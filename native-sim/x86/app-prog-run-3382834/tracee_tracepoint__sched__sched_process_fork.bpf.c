extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char logs;
extern char logs_count;
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

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_0(
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
	case 25ULL: goto x86_l_19;
	case 27ULL: goto x86_l_1b;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 44ULL: goto x86_l_2c;
	case 47ULL: goto x86_l_2f;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 62ULL: goto x86_l_3e;
	case 64ULL: goto x86_l_40;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 78ULL: goto x86_l_4e;
	case 83ULL: goto x86_l_53;
	case 85ULL: goto x86_l_55;
	case 88ULL: goto x86_l_58;
	case 93ULL: goto x86_l_5d;
	case 95ULL: goto x86_l_5f;
	case 98ULL: goto x86_l_62;
	case 100ULL: goto x86_l_64;
	case 103ULL: goto x86_l_67;
	case 105ULL: goto x86_l_69;
	case 109ULL: goto x86_l_6d;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 130ULL: goto x86_l_82;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 161ULL: goto x86_l_a1;
	case 163ULL: goto x86_l_a3;
	case 166ULL: goto x86_l_a6;
	case 168ULL: goto x86_l_a8;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 188ULL: goto x86_l_bc;
	case 195ULL: goto x86_l_c3;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 229ULL: goto x86_l_e5;
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
	case 544ULL: goto x86_l_220;
	case 552ULL: goto x86_l_228;
	case 557ULL: goto x86_l_22d;
	case 559ULL: goto x86_l_22f;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 572ULL: goto x86_l_23c;
	case 576ULL: goto x86_l_240;
	case 583ULL: goto x86_l_247;
	case 590ULL: goto x86_l_24e;
	case 598ULL: goto x86_l_256;
	case 603ULL: goto x86_l_25b;
	case 605ULL: goto x86_l_25d;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 619ULL: goto x86_l_26b;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 663ULL: goto x86_l_297;
	case 667ULL: goto x86_l_29b;
	case 675ULL: goto x86_l_2a3;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 694ULL: goto x86_l_2b6;
	case 697ULL: goto x86_l_2b9;
	case 703ULL: goto x86_l_2bf;
	case 706ULL: goto x86_l_2c2;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 724ULL: goto x86_l_2d4;
	case 735ULL: goto x86_l_2df;
	case 746ULL: goto x86_l_2ea;
	case 757ULL: goto x86_l_2f5;
	case 768ULL: goto x86_l_300;
	case 779ULL: goto x86_l_30b;
	case 790ULL: goto x86_l_316;
	case 801ULL: goto x86_l_321;
	case 812ULL: goto x86_l_32c;
	case 823ULL: goto x86_l_337;
	case 834ULL: goto x86_l_342;
	case 845ULL: goto x86_l_34d;
	case 856ULL: goto x86_l_358;
	case 867ULL: goto x86_l_363;
	case 878ULL: goto x86_l_36e;
	case 889ULL: goto x86_l_379;
	case 900ULL: goto x86_l_384;
	case 911ULL: goto x86_l_38f;
	case 922ULL: goto x86_l_39a;
	case 933ULL: goto x86_l_3a5;
	case 944ULL: goto x86_l_3b0;
	case 955ULL: goto x86_l_3bb;
	case 966ULL: goto x86_l_3c6;
	case 977ULL: goto x86_l_3d1;
	case 988ULL: goto x86_l_3dc;
	case 999ULL: goto x86_l_3e7;
	case 1010ULL: goto x86_l_3f2;
	case 1021ULL: goto x86_l_3fd;
	case 1032ULL: goto x86_l_408;
	case 1043ULL: goto x86_l_413;
	case 1051ULL: goto x86_l_41b;
	case 1059ULL: goto x86_l_423;
	case 1067ULL: goto x86_l_42b;
	case 1075ULL: goto x86_l_433;
	case 1083ULL: goto x86_l_43b;
	case 1091ULL: goto x86_l_443;
	case 1099ULL: goto x86_l_44b;
	case 1107ULL: goto x86_l_453;
	case 1115ULL: goto x86_l_45b;
	case 1123ULL: goto x86_l_463;
	case 1131ULL: goto x86_l_46b;
	case 1139ULL: goto x86_l_473;
	case 1147ULL: goto x86_l_47b;
	case 1155ULL: goto x86_l_483;
	case 1163ULL: goto x86_l_48b;
	case 1170ULL: goto x86_l_492;
	case 1177ULL: goto x86_l_499;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1193ULL: goto x86_l_4a9;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1205ULL: goto x86_l_4b5;
	case 1208ULL: goto x86_l_4b8;
	case 1210ULL: goto x86_l_4ba;
	case 1218ULL: goto x86_l_4c2;
	case 1221ULL: goto x86_l_4c5;
	case 1227ULL: goto x86_l_4cb;
	case 1232ULL: goto x86_l_4d0;
	case 1237ULL: goto x86_l_4d5;
	case 1244ULL: goto x86_l_4dc;
	case 1248ULL: goto x86_l_4e0;
	case 1256ULL: goto x86_l_4e8;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1273ULL: goto x86_l_4f9;
	case 1279ULL: goto x86_l_4ff;
	case 1281ULL: goto x86_l_501;
	case 1284ULL: goto x86_l_504;
	case 1290ULL: goto x86_l_50a;
	case 1293ULL: goto x86_l_50d;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1311ULL: goto x86_l_51f;
	case 1322ULL: goto x86_l_52a;
	case 1333ULL: goto x86_l_535;
	case 1344ULL: goto x86_l_540;
	case 1355ULL: goto x86_l_54b;
	case 1366ULL: goto x86_l_556;
	case 1377ULL: goto x86_l_561;
	case 1388ULL: goto x86_l_56c;
	case 1399ULL: goto x86_l_577;
	case 1407ULL: goto x86_l_57f;
	case 1415ULL: goto x86_l_587;
	case 1423ULL: goto x86_l_58f;
	case 1431ULL: goto x86_l_597;
	case 1439ULL: goto x86_l_59f;
	case 1447ULL: goto x86_l_5a7;
	case 1455ULL: goto x86_l_5af;
	case 1463ULL: goto x86_l_5b7;
	case 1471ULL: goto x86_l_5bf;
	case 1479ULL: goto x86_l_5c7;
	case 1487ULL: goto x86_l_5cf;
	case 1495ULL: goto x86_l_5d7;
	case 1503ULL: goto x86_l_5df;
	case 1511ULL: goto x86_l_5e7;
	case 1519ULL: goto x86_l_5ef;
	case 1526ULL: goto x86_l_5f6;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1564ULL: goto x86_l_61c;
	case 1566ULL: goto x86_l_61e;
	case 1569ULL: goto x86_l_621;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1590ULL: goto x86_l_636;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1650ULL: goto x86_l_672;
	case 1654ULL: goto x86_l_676;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1678ULL: goto x86_l_68e;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1762ULL: goto x86_l_6e2;
	case 1765ULL: goto x86_l_6e5;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1774ULL: goto x86_l_6ee;
	case 1778ULL: goto x86_l_6f2;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1829ULL: goto x86_l_725;
	case 1831ULL: goto x86_l_727;
	case 1835ULL: goto x86_l_72b;
	case 1839ULL: goto x86_l_72f;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1859ULL: goto x86_l_743;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1884ULL: goto x86_l_75c;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1897ULL: goto x86_l_769;
	case 1901ULL: goto x86_l_76d;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1921ULL: goto x86_l_781;
	case 1924ULL: goto x86_l_784;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1984ULL: goto x86_l_7c0;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2016ULL: goto x86_l_7e0;
	case 2020ULL: goto x86_l_7e4;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2069ULL: goto x86_l_815;
	case 2071ULL: goto x86_l_817;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
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
	/* 0xa: sub    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 280ULL);
x86_l_11:
	/* 0x11: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_19:
	/* 0x19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b:
	/* 0x1b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c:
	/* 0x2c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_34:
	/* 0x34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39:
	/* 0x39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: test   DWORD PTR [rsp],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2097152ULL);
x86_l_47:
	/* 0x47: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_4c:
	/* 0x4c: jne    b1 <tracepoint__sched__sched_process_fork+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b1;
	}
x86_l_4e:
	/* 0x4e: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_53:
	/* 0x53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55:
	/* 0x55: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_58:
	/* 0x58: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_5d:
	/* 0x5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f:
	/* 0x5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62:
	/* 0x62: je     69 <tracepoint__sched__sched_process_fork+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69;
	}
x86_l_64:
	/* 0x64: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_67:
	/* 0x67: jmp    69 <tracepoint__sched__sched_process_fork+0x69> */
	goto x86_l_69;
x86_l_69:
	/* 0x69: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6d:
	/* 0x6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_70:
	/* 0x70: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_75:
	/* 0x75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a:
	/* 0x7a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f:
	/* 0x7f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_82:
	/* 0x82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84:
	/* 0x84: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_88:
	/* 0x88: jne    90 <tracepoint__sched__sched_process_fork+0x90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_90;
	}
x86_l_8a:
	/* 0x8a: mov    ebp,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8e:
	/* 0x8e: jmp    b1 <tracepoint__sched__sched_process_fork+0xb1> */
	goto x86_l_b1;
x86_l_90:
	/* 0x90: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_97:
	/* 0x97: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9c:
	/* 0x9c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a1:
	/* 0xa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3:
	/* 0xa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: je     ac <tracepoint__sched__sched_process_fork+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac;
	}
x86_l_a8:
	/* 0xa8: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa:
	/* 0xaa: jmp    b1 <tracepoint__sched__sched_process_fork+0xb1> */
	goto x86_l_b1;
x86_l_ac:
	/* 0xac: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b1:
	/* 0xb1: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_bc:
	/* 0xbc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c3:
	/* 0xc3: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_cb:
	/* 0xcb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0:
	/* 0xd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_db:
	/* 0xdb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e5:
	/* 0xe5: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ed:
	/* 0xed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2:
	/* 0xf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4:
	/* 0xf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
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
	/* 0x1ec: mov    DWORD PTR [r14+0x70],0x2ca */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337866ULL);
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
	/* 0x212: mov    DWORD PTR [rsp+0xc8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_228:
	/* 0x228: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22d:
	/* 0x22d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f:
	/* 0x22f: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_237:
	/* 0x237: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a:
	/* 0x23a: je     290 <tracepoint__sched__sched_process_fork+0x290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_290;
	}
x86_l_23c:
	/* 0x23c: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_240:
	/* 0x240: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_247:
	/* 0x247: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_24e:
	/* 0x24e: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_256:
	/* 0x256: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25b:
	/* 0x25b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d:
	/* 0x25d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_260:
	/* 0x260: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_263:
	/* 0x263: mov    QWORD PTR [rsp+0xb8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_26b:
	/* 0x26b: mov    QWORD PTR [rsp+0xa8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_273:
	/* 0x273: je     4d0 <tracepoint__sched__sched_process_fork+0x4d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d0;
	}
x86_l_279:
	/* 0x279: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_27e:
	/* 0x27e: jne    a75 <tracepoint__sched__sched_process_fork+0xa75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2677ULL;
	}
x86_l_284:
	/* 0x284: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: jmp    b16 <tracepoint__sched__sched_process_fork+0xb16> */
	return 2838ULL;
x86_l_290:
	/* 0x290: mov    eax,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_297:
	/* 0x297: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29b:
	/* 0x29b: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2a3:
	/* 0x2a3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2aa:
	/* 0x2aa: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2af:
	/* 0x2af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4:
	/* 0x2b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6:
	/* 0x2b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_2bf:
	/* 0x2bf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2c6:
	/* 0x2c6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c9:
	/* 0x2c9: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2d4:
	/* 0x2d4: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2df:
	/* 0x2df: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2ea:
	/* 0x2ea: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2f5:
	/* 0x2f5: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_300:
	/* 0x300: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_30b:
	/* 0x30b: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_316:
	/* 0x316: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_321:
	/* 0x321: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_32c:
	/* 0x32c: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_337:
	/* 0x337: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_342:
	/* 0x342: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_34d:
	/* 0x34d: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_358:
	/* 0x358: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_363:
	/* 0x363: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_36e:
	/* 0x36e: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_379:
	/* 0x379: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_384:
	/* 0x384: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_39a:
	/* 0x39a: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3a5:
	/* 0x3a5: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3b0:
	/* 0x3b0: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3bb:
	/* 0x3bb: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3c6:
	/* 0x3c6: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3d1:
	/* 0x3d1: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3dc:
	/* 0x3dc: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3e7:
	/* 0x3e7: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3f2:
	/* 0x3f2: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3fd:
	/* 0x3fd: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_408:
	/* 0x408: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_413:
	/* 0x413: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_43b:
	/* 0x43b: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_44b:
	/* 0x44b: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_453:
	/* 0x453: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_473:
	/* 0x473: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_492:
	/* 0x492: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_499:
	/* 0x499: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_49c:
	/* 0x49c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a1:
	/* 0x4a1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a6:
	/* 0x4a6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a9:
	/* 0x4a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab:
	/* 0x4ab: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4b0:
	/* 0x4b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b5:
	/* 0x4b5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b8:
	/* 0x4b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba:
	/* 0x4ba: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4c2:
	/* 0x4c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: jne    23c <tracepoint__sched__sched_process_fork+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23c;
	}
x86_l_4cb:
	/* 0x4cb: jmp    3441 <tracepoint__sched__sched_process_fork+0x3441> */
	return 13377ULL;
x86_l_4d0:
	/* 0x4d0: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4d5:
	/* 0x4d5: mov    eax,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4dc:
	/* 0x4dc: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4e0:
	/* 0x4e0: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4e8:
	/* 0x4e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4ef:
	/* 0x4ef: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f4:
	/* 0x4f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f9:
	/* 0x4f9: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4ff:
	/* 0x4ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_501:
	/* 0x501: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_504:
	/* 0x504: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_50a:
	/* 0x50a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_50d:
	/* 0x50d: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_511:
	/* 0x511: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_514:
	/* 0x514: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_51f:
	/* 0x51f: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_535:
	/* 0x535: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_540:
	/* 0x540: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_54b:
	/* 0x54b: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_556:
	/* 0x556: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_561:
	/* 0x561: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_577:
	/* 0x577: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_57f:
	/* 0x57f: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_587:
	/* 0x587: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_58f:
	/* 0x58f: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_597:
	/* 0x597: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_59f:
	/* 0x59f: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5af:
	/* 0x5af: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5b7:
	/* 0x5b7: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5bf:
	/* 0x5bf: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5c7:
	/* 0x5c7: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5d7:
	/* 0x5d7: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5ef:
	/* 0x5ef: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f6:
	/* 0x5f6: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5fd:
	/* 0x5fd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_600:
	/* 0x600: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_605:
	/* 0x605: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_60a:
	/* 0x60a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60f:
	/* 0x60f: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_614:
	/* 0x614: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_619:
	/* 0x619: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_61c:
	/* 0x61c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61e:
	/* 0x61e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_621:
	/* 0x621: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_627:
	/* 0x627: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_62a:
	/* 0x62a: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_62f:
	/* 0x62f: mov    r14,QWORD PTR [rax+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_636:
	/* 0x636: lea    r13,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_63a:
	/* 0x63a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_642:
	/* 0x642: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_647:
	/* 0x647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c:
	/* 0x64c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_64f:
	/* 0x64f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651:
	/* 0x651: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_65a:
	/* 0x65a: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65e:
	/* 0x65e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_661:
	/* 0x661: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_666:
	/* 0x666: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66b:
	/* 0x66b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_670:
	/* 0x670: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_672:
	/* 0x672: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_676:
	/* 0x676: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_67a:
	/* 0x67a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_687:
	/* 0x687: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68c:
	/* 0x68c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68e:
	/* 0x68e: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_697:
	/* 0x697: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_69a:
	/* 0x69a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_69f:
	/* 0x69f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a4:
	/* 0x6a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6a9:
	/* 0x6a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ab:
	/* 0x6ab: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ae:
	/* 0x6ae: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6b1:
	/* 0x6b1: lea    rbp,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b5:
	/* 0x6b5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6b8:
	/* 0x6b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6bd:
	/* 0x6bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c2:
	/* 0x6c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c7:
	/* 0x6c7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ca:
	/* 0x6ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cc:
	/* 0x6cc: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d0:
	/* 0x6d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6d3:
	/* 0x6d3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6d8:
	/* 0x6d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6dd:
	/* 0x6dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e2:
	/* 0x6e2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6e5:
	/* 0x6e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e7:
	/* 0x6e7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ea:
	/* 0x6ea: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6ee:
	/* 0x6ee: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6f2:
	/* 0x6f2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6f6:
	/* 0x6f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6f9:
	/* 0x6f9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6fe:
	/* 0x6fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_703:
	/* 0x703: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_708:
	/* 0x708: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70a:
	/* 0x70a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70d:
	/* 0x70d: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_710:
	/* 0x710: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_713:
	/* 0x713: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_718:
	/* 0x718: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_71d:
	/* 0x71d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_722:
	/* 0x722: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_725:
	/* 0x725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_727:
	/* 0x727: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72b:
	/* 0x72b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_72f:
	/* 0x72f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_732:
	/* 0x732: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_737:
	/* 0x737: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73c:
	/* 0x73c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_741:
	/* 0x741: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_743:
	/* 0x743: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_747:
	/* 0x747: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_74a:
	/* 0x74a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_74f:
	/* 0x74f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_754:
	/* 0x754: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_759:
	/* 0x759: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_75c:
	/* 0x75c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75e:
	/* 0x75e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_761:
	/* 0x761: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_765:
	/* 0x765: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_769:
	/* 0x769: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_76d:
	/* 0x76d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_770:
	/* 0x770: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_775:
	/* 0x775: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_77a:
	/* 0x77a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77f:
	/* 0x77f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_781:
	/* 0x781: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_784:
	/* 0x784: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_787:
	/* 0x787: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_78a:
	/* 0x78a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_78f:
	/* 0x78f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_794:
	/* 0x794: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_799:
	/* 0x799: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_79c:
	/* 0x79c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79e:
	/* 0x79e: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a2:
	/* 0x7a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7aa:
	/* 0x7aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7af:
	/* 0x7af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7b4:
	/* 0x7b4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7b7:
	/* 0x7b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b9:
	/* 0x7b9: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bc:
	/* 0x7bc: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7c0:
	/* 0x7c0: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7c4:
	/* 0x7c4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7c8:
	/* 0x7c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7cb:
	/* 0x7cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7d0:
	/* 0x7d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d5:
	/* 0x7d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e0:
	/* 0x7e0: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7e4:
	/* 0x7e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7e7:
	/* 0x7e7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ec:
	/* 0x7ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f1:
	/* 0x7f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f6:
	/* 0x7f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f8:
	/* 0x7f8: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7fb:
	/* 0x7fb: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_800:
	/* 0x800: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_803:
	/* 0x803: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_808:
	/* 0x808: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80d:
	/* 0x80d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_812:
	/* 0x812: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_815:
	/* 0x815: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_817:
	/* 0x817: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81b:
	/* 0x81b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_81e:
	/* 0x81e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_823:
	/* 0x823: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_828:
	/* 0x828: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 2093ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2161ULL: goto x86_l_871;
	case 2164ULL: goto x86_l_874;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2189ULL: goto x86_l_88d;
	case 2193ULL: goto x86_l_891;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2231ULL: goto x86_l_8b7;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2288ULL: goto x86_l_8f0;
	case 2290ULL: goto x86_l_8f2;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2348ULL: goto x86_l_92c;
	case 2352ULL: goto x86_l_930;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2362ULL: goto x86_l_93a;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2405ULL: goto x86_l_965;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2425ULL: goto x86_l_979;
	case 2429ULL: goto x86_l_97d;
	case 2433ULL: goto x86_l_981;
	case 2437ULL: goto x86_l_985;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2464ULL: goto x86_l_9a0;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2489ULL: goto x86_l_9b9;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2501ULL: goto x86_l_9c5;
	case 2509ULL: goto x86_l_9cd;
	case 2513ULL: goto x86_l_9d1;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2559ULL: goto x86_l_9ff;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2568ULL: goto x86_l_a08;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2585ULL: goto x86_l_a19;
	case 2589ULL: goto x86_l_a1d;
	case 2592ULL: goto x86_l_a20;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2615ULL: goto x86_l_a37;
	case 2618ULL: goto x86_l_a3a;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2640ULL: goto x86_l_a50;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2743ULL: goto x86_l_ab7;
	case 2748ULL: goto x86_l_abc;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2773ULL: goto x86_l_ad5;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2801ULL: goto x86_l_af1;
	case 2804ULL: goto x86_l_af4;
	case 2806ULL: goto x86_l_af6;
	case 2810ULL: goto x86_l_afa;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2830ULL: goto x86_l_b0e;
	case 2834ULL: goto x86_l_b12;
	case 2836ULL: goto x86_l_b14;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2846ULL: goto x86_l_b1e;
	case 2850ULL: goto x86_l_b22;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2867ULL: goto x86_l_b33;
	case 2869ULL: goto x86_l_b35;
	case 2872ULL: goto x86_l_b38;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2889ULL: goto x86_l_b49;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2923ULL: goto x86_l_b6b;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2954ULL: goto x86_l_b8a;
	case 2957ULL: goto x86_l_b8d;
	case 2959ULL: goto x86_l_b8f;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2972ULL: goto x86_l_b9c;
	case 2975ULL: goto x86_l_b9f;
	case 2977ULL: goto x86_l_ba1;
	case 2981ULL: goto x86_l_ba5;
	case 2988ULL: goto x86_l_bac;
	case 2991ULL: goto x86_l_baf;
	case 2998ULL: goto x86_l_bb6;
	case 3002ULL: goto x86_l_bba;
	case 3006ULL: goto x86_l_bbe;
	case 3013ULL: goto x86_l_bc5;
	case 3020ULL: goto x86_l_bcc;
	case 3024ULL: goto x86_l_bd0;
	case 3031ULL: goto x86_l_bd7;
	case 3035ULL: goto x86_l_bdb;
	case 3042ULL: goto x86_l_be2;
	case 3046ULL: goto x86_l_be6;
	case 3053ULL: goto x86_l_bed;
	case 3057ULL: goto x86_l_bf1;
	case 3064ULL: goto x86_l_bf8;
	case 3071ULL: goto x86_l_bff;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3094ULL: goto x86_l_c16;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3116ULL: goto x86_l_c2c;
	case 3118ULL: goto x86_l_c2e;
	case 3121ULL: goto x86_l_c31;
	case 3128ULL: goto x86_l_c38;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3193ULL: goto x86_l_c79;
	case 3200ULL: goto x86_l_c80;
	case 3204ULL: goto x86_l_c84;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3237ULL: goto x86_l_ca5;
	case 3241ULL: goto x86_l_ca9;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3267ULL: goto x86_l_cc3;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3285ULL: goto x86_l_cd5;
	case 3290ULL: goto x86_l_cda;
	case 3295ULL: goto x86_l_cdf;
	case 3297ULL: goto x86_l_ce1;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3322ULL: goto x86_l_cfa;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3398ULL: goto x86_l_d46;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3423ULL: goto x86_l_d5f;
	case 3425ULL: goto x86_l_d61;
	case 3428ULL: goto x86_l_d64;
	case 3432ULL: goto x86_l_d68;
	case 3436ULL: goto x86_l_d6c;
	case 3440ULL: goto x86_l_d70;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3460ULL: goto x86_l_d84;
	case 3463ULL: goto x86_l_d87;
	case 3470ULL: goto x86_l_d8e;
	case 3477ULL: goto x86_l_d95;
	case 3479ULL: goto x86_l_d97;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3502ULL: goto x86_l_dae;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3530ULL: goto x86_l_dca;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3552ULL: goto x86_l_de0;
	case 3558ULL: goto x86_l_de6;
	case 3561ULL: goto x86_l_de9;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3608ULL: goto x86_l_e18;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3674ULL: goto x86_l_e5a;
	case 3682ULL: goto x86_l_e62;
	case 3691ULL: goto x86_l_e6b;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3736ULL: goto x86_l_e98;
	case 3740ULL: goto x86_l_e9c;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_82d:
	/* 0x82d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_830:
	/* 0x830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_832:
	/* 0x832: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_835:
	/* 0x835: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_839:
	/* 0x839: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_83d:
	/* 0x83d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_841:
	/* 0x841: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_844:
	/* 0x844: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_849:
	/* 0x849: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_84e:
	/* 0x84e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_853:
	/* 0x853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_855:
	/* 0x855: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_859:
	/* 0x859: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_85d:
	/* 0x85d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_860:
	/* 0x860: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_865:
	/* 0x865: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_86a:
	/* 0x86a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_86f:
	/* 0x86f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_871:
	/* 0x871: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_874:
	/* 0x874: jne    8d1 <tracepoint__sched__sched_process_fork+0x8d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d1;
	}
x86_l_876:
	/* 0x876: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_879:
	/* 0x879: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_87e:
	/* 0x87e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_883:
	/* 0x883: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_888:
	/* 0x888: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_88b:
	/* 0x88b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88d:
	/* 0x88d: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_891:
	/* 0x891: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_894:
	/* 0x894: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_899:
	/* 0x899: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89e:
	/* 0x89e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8a3:
	/* 0x8a3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8a6:
	/* 0x8a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a8:
	/* 0x8a8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ab:
	/* 0x8ab: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8af:
	/* 0x8af: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8b3:
	/* 0x8b3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8b7:
	/* 0x8b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8ba:
	/* 0x8ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8bf:
	/* 0x8bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8c4:
	/* 0x8c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8c9:
	/* 0x8c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cb:
	/* 0x8cb: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ce:
	/* 0x8ce: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8d1:
	/* 0x8d1: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d4:
	/* 0x8d4: lea    r13,[r14+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8db:
	/* 0x8db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8de:
	/* 0x8de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8e3:
	/* 0x8e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e8:
	/* 0x8e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ed:
	/* 0x8ed: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8f0:
	/* 0x8f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f2:
	/* 0x8f2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f6:
	/* 0x8f6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8fa:
	/* 0x8fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8fd:
	/* 0x8fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_902:
	/* 0x902: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_907:
	/* 0x907: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_90c:
	/* 0x90c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90e:
	/* 0x90e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_912:
	/* 0x912: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_917:
	/* 0x917: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_91c:
	/* 0x91c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_921:
	/* 0x921: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_925:
	/* 0x925: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_92a:
	/* 0x92a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92c:
	/* 0x92c: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_930:
	/* 0x930: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_933:
	/* 0x933: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_938:
	/* 0x938: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93a:
	/* 0x93a: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_93d:
	/* 0x93d: lea    rdx,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_941:
	/* 0x941: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_944:
	/* 0x944: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_949:
	/* 0x949: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94e:
	/* 0x94e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_953:
	/* 0x953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_955:
	/* 0x955: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_959:
	/* 0x959: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_961:
	/* 0x961: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_965:
	/* 0x965: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_968:
	/* 0x968: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_96d:
	/* 0x96d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_972:
	/* 0x972: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_977:
	/* 0x977: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_979:
	/* 0x979: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_97d:
	/* 0x97d: mov    QWORD PTR [rbx+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_981:
	/* 0x981: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_985:
	/* 0x985: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_988:
	/* 0x988: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_98d:
	/* 0x98d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_992:
	/* 0x992: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_997:
	/* 0x997: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_99a:
	/* 0x99a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99c:
	/* 0x99c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a0:
	/* 0x9a0: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9a4:
	/* 0x9a4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9a7:
	/* 0x9a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9ac:
	/* 0x9ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b1:
	/* 0x9b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9b6:
	/* 0x9b6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9b9:
	/* 0x9b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bb:
	/* 0x9bb: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_9bf:
	/* 0x9bf: je     9c5 <tracepoint__sched__sched_process_fork+0x9c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c5;
	}
x86_l_9c1:
	/* 0x9c1: or     BYTE PTR [rbx+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_9c5:
	/* 0x9c5: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_9cd:
	/* 0x9cd: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9d1:
	/* 0x9d1: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_9d9:
	/* 0x9d9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_9de:
	/* 0x9de: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_9e3:
	/* 0x9e3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9e8:
	/* 0x9e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ea:
	/* 0x9ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f2:
	/* 0x9f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f7:
	/* 0x9f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9fc:
	/* 0x9fc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9ff:
	/* 0x9ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a01:
	/* 0xa01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a05:
	/* 0xa05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a0d:
	/* 0xa0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a12:
	/* 0xa12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a17:
	/* 0xa17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a19:
	/* 0xa19: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1d:
	/* 0xa1d: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_a20:
	/* 0xa20: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_a23:
	/* 0xa23: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_a28:
	/* 0xa28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a2d:
	/* 0xa2d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a30:
	/* 0xa30: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a35:
	/* 0xa35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a37:
	/* 0xa37: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a3a:
	/* 0xa3a: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_a3e:
	/* 0xa3e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a43:
	/* 0xa43: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_a48:
	/* 0xa48: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a4d:
	/* 0xa4d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a50:
	/* 0xa50: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_a53:
	/* 0xa53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a55:
	/* 0xa55: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a5d:
	/* 0xa5d: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a62:
	/* 0xa62: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a6a:
	/* 0xa6a: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a6f:
	/* 0xa6f: je     284 <tracepoint__sched__sched_process_fork+0x284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 644ULL;
	}
x86_l_a75:
	/* 0xa75: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a7a:
	/* 0xa7a: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a81:
	/* 0xa81: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a86:
	/* 0xa86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a8b:
	/* 0xa8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a90:
	/* 0xa90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a95:
	/* 0xa95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a97:
	/* 0xa97: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a9c:
	/* 0xa9c: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aa1:
	/* 0xaa1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_aa6:
	/* 0xaa6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aab:
	/* 0xaab: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ab0:
	/* 0xab0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab5:
	/* 0xab5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab7:
	/* 0xab7: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_abc:
	/* 0xabc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_abf:
	/* 0xabf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ac4:
	/* 0xac4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ac9:
	/* 0xac9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ace:
	/* 0xace: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ad3:
	/* 0xad3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad5:
	/* 0xad5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad9:
	/* 0xad9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae1:
	/* 0xae1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ae6:
	/* 0xae6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aeb:
	/* 0xaeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aed:
	/* 0xaed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af1:
	/* 0xaf1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_af4:
	/* 0xaf4: je     b14 <tracepoint__sched__sched_process_fork+0xb14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b14;
	}
x86_l_af6:
	/* 0xaf6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_afa:
	/* 0xafa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_afd:
	/* 0xafd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b02:
	/* 0xb02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b07:
	/* 0xb07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b0c:
	/* 0xb0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0e:
	/* 0xb0e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b12:
	/* 0xb12: jmp    b16 <tracepoint__sched__sched_process_fork+0xb16> */
	goto x86_l_b16;
x86_l_b14:
	/* 0xb14: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b16:
	/* 0xb16: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1a:
	/* 0xb1a: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1e:
	/* 0xb1e: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b22:
	/* 0xb22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b29:
	/* 0xb29: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b2e:
	/* 0xb2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b33:
	/* 0xb33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b35:
	/* 0xb35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b38:
	/* 0xb38: je     b50 <tracepoint__sched__sched_process_fork+0xb50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b50;
	}
x86_l_b3a:
	/* 0xb3a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b3d:
	/* 0xb3d: mov    BYTE PTR [rbx+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_b43:
	/* 0xb43: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_b46:
	/* 0xb46: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b49:
	/* 0xb49: jne    b50 <tracepoint__sched__sched_process_fork+0xb50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b50;
	}
x86_l_b4b:
	/* 0xb4b: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_b50:
	/* 0xb50: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_b55:
	/* 0xb55: cmp    ax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_b5a:
	/* 0xb5a: jne    3459 <tracepoint__sched__sched_process_fork+0x3459> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13401ULL;
	}
x86_l_b60:
	/* 0xb60: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_b6b:
	/* 0xb6b: mov    DWORD PTR [rsp],0x2ca */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 714ULL);
x86_l_b72:
	/* 0xb72: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b77:
	/* 0xb77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b7e:
	/* 0xb7e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b83:
	/* 0xb83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b88:
	/* 0xb88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8a:
	/* 0xb8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b8d:
	/* 0xb8d: je     bf8 <tracepoint__sched__sched_process_fork+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_b8f:
	/* 0xb8f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b92:
	/* 0xb92: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b95:
	/* 0xb95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b9a:
	/* 0xb9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9c:
	/* 0xb9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9f:
	/* 0xb9f: je     bf8 <tracepoint__sched__sched_process_fork+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_ba1:
	/* 0xba1: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba5:
	/* 0xba5: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_bac:
	/* 0xbac: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_baf:
	/* 0xbaf: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_bb6:
	/* 0xbb6: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bba:
	/* 0xbba: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bbe:
	/* 0xbbe: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_bc5:
	/* 0xbc5: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_bcc:
	/* 0xbcc: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd0:
	/* 0xbd0: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_bd7:
	/* 0xbd7: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_be2:
	/* 0xbe2: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_be6:
	/* 0xbe6: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_bed:
	/* 0xbed: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bf1:
	/* 0xbf1: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_bf8:
	/* 0xbf8: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_bff:
	/* 0xbff: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c06:
	/* 0xc06: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0a:
	/* 0xc0a: mov    r13,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0e:
	/* 0xc0e: mov    QWORD PTR [rsp+0x110],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_c16:
	/* 0xc16: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c1a:
	/* 0xc1a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c1d:
	/* 0xc1d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c22:
	/* 0xc22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c27:
	/* 0xc27: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c2c:
	/* 0xc2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2e:
	/* 0xc2e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c31:
	/* 0xc31: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_c38:
	/* 0xc38: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c3c:
	/* 0xc3c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c3f:
	/* 0xc3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c44:
	/* 0xc44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c49:
	/* 0xc49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4e:
	/* 0xc4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c50:
	/* 0xc50: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c54:
	/* 0xc54: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c59:
	/* 0xc59: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c5d:
	/* 0xc5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c60:
	/* 0xc60: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c65:
	/* 0xc65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c6a:
	/* 0xc6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c6f:
	/* 0xc6f: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c74:
	/* 0xc74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c76:
	/* 0xc76: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c79:
	/* 0xc79: mov    DWORD PTR [rsp+0x94],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_c80:
	/* 0xc80: lea    rbp,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c84:
	/* 0xc84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c87:
	/* 0xc87: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c8c:
	/* 0xc8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c91:
	/* 0xc91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c96:
	/* 0xc96: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c99:
	/* 0xc99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9b:
	/* 0xc9b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9e:
	/* 0xc9e: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ca5:
	/* 0xca5: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca9:
	/* 0xca9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cac:
	/* 0xcac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cb1:
	/* 0xcb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb6:
	/* 0xcb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cbb:
	/* 0xcbb: mov    QWORD PTR [rsp+0x108],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_cc3:
	/* 0xcc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc5:
	/* 0xcc5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc9:
	/* 0xcc9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ccd:
	/* 0xccd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cd0:
	/* 0xcd0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cd5:
	/* 0xcd5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cda:
	/* 0xcda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cdf:
	/* 0xcdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce1:
	/* 0xce1: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce5:
	/* 0xce5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ce8:
	/* 0xce8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ced:
	/* 0xced: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cf2:
	/* 0xcf2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cf7:
	/* 0xcf7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cfa:
	/* 0xcfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfc:
	/* 0xcfc: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cff:
	/* 0xcff: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d03:
	/* 0xd03: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d07:
	/* 0xd07: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d0b:
	/* 0xd0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d0e:
	/* 0xd0e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d13:
	/* 0xd13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d18:
	/* 0xd18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d1d:
	/* 0xd1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1f:
	/* 0xd1f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d22:
	/* 0xd22: mov    DWORD PTR [rsp+0xfc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 252ULL);
x86_l_d29:
	/* 0xd29: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d2e:
	/* 0xd2e: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d32:
	/* 0xd32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d35:
	/* 0xd35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3a:
	/* 0xd3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d3f:
	/* 0xd3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d44:
	/* 0xd44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d46:
	/* 0xd46: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4a:
	/* 0xd4a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d52:
	/* 0xd52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d57:
	/* 0xd57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d5c:
	/* 0xd5c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d5f:
	/* 0xd5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d61:
	/* 0xd61: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d64:
	/* 0xd64: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d68:
	/* 0xd68: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d6c:
	/* 0xd6c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d78:
	/* 0xd78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d7d:
	/* 0xd7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d82:
	/* 0xd82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d84:
	/* 0xd84: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d87:
	/* 0xd87: mov    DWORD PTR [rsp+0xc4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_d8e:
	/* 0xd8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_d95:
	/* 0xd95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d97:
	/* 0xd97: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d9f:
	/* 0xd9f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_da4:
	/* 0xda4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_da7:
	/* 0xda7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da9:
	/* 0xda9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dab:
	/* 0xdab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dae:
	/* 0xdae: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_db6:
	/* 0xdb6: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: jns    f01 <tracepoint__sched__sched_process_fork+0xf01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3841ULL;
	}
x86_l_dbf:
	/* 0xdbf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_dca:
	/* 0xdca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_dd1:
	/* 0xdd1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dd6:
	/* 0xdd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ddb:
	/* 0xddb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddd:
	/* 0xddd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: je     ef9 <tracepoint__sched__sched_process_fork+0xef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3833ULL;
	}
x86_l_de6:
	/* 0xde6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_de9:
	/* 0xde9: movabs rax,0xffffffff00000003 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744069414584323ULL);
x86_l_df3:
	/* 0xdf3: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df7:
	/* 0xdf7: mov    QWORD PTR [r12+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfc:
	/* 0xdfc: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_e01:
	/* 0xe01: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_e04:
	/* 0xe04: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0f:
	/* 0xe0f: mov    DWORD PTR [r12+0x1c],0x27d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084925ULL);
x86_l_e18:
	/* 0xe18: movabs rax,0x702f656563617274 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8083791342286762612ULL);
x86_l_e22:
	/* 0xe22: mov    QWORD PTR [r12+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e27:
	/* 0xe27: movabs rax,0x2f667062652f676b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3415540935313811307ULL);
x86_l_e31:
	/* 0xe31: mov    QWORD PTR [r12+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e36:
	/* 0xe36: movabs rax,0x6565636172742f63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306355240661692259ULL);
x86_l_e40:
	/* 0xe40: mov    QWORD PTR [r12+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e45:
	/* 0xe45: movabs rax,0x632e6670622e6565 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7146762291553133925ULL);
x86_l_e4f:
	/* 0xe4f: mov    QWORD PTR [r12+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_e54:
	/* 0xe54: mov    BYTE PTR [r12+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_e5a:
	/* 0xe5a: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e62:
	/* 0xe62: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e6b:
	/* 0xe6b: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_e72:
	/* 0xe72: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_e77:
	/* 0xe77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e79:
	/* 0xe79: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7e:
	/* 0xe7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_e85:
	/* 0xe85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8a:
	/* 0xe8a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e8d:
	/* 0xe8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8f:
	/* 0xe8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e92:
	/* 0xe92: je     3595 <tracepoint__sched__sched_process_fork+0x3595> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13717ULL;
	}
x86_l_e98:
	/* 0xe98: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9c:
	/* 0xe9c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e9e:
	/* 0xe9e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea3:
	/* 0xea3: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 3751ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3761ULL: goto x86_l_eb1;
	case 3769ULL: goto x86_l_eb9;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3822ULL: goto x86_l_eee;
	case 3825ULL: goto x86_l_ef1;
	case 3827ULL: goto x86_l_ef3;
	case 3833ULL: goto x86_l_ef9;
	case 3841ULL: goto x86_l_f01;
	case 3848ULL: goto x86_l_f08;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3863ULL: goto x86_l_f17;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3882ULL: goto x86_l_f2a;
	case 3886ULL: goto x86_l_f2e;
	case 3893ULL: goto x86_l_f35;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3941ULL: goto x86_l_f65;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3949ULL: goto x86_l_f6d;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3964ULL: goto x86_l_f7c;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4041ULL: goto x86_l_fc9;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4056ULL: goto x86_l_fd8;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4074ULL: goto x86_l_fea;
	case 4076ULL: goto x86_l_fec;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4108ULL: goto x86_l_100c;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4124ULL: goto x86_l_101c;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4147ULL: goto x86_l_1033;
	case 4149ULL: goto x86_l_1035;
	case 4160ULL: goto x86_l_1040;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4227ULL: goto x86_l_1083;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4247ULL: goto x86_l_1097;
	case 4251ULL: goto x86_l_109b;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4268ULL: goto x86_l_10ac;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4289ULL: goto x86_l_10c1;
	case 4291ULL: goto x86_l_10c3;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4322ULL: goto x86_l_10e2;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4357ULL: goto x86_l_1105;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4411ULL: goto x86_l_113b;
	case 4416ULL: goto x86_l_1140;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4470ULL: goto x86_l_1176;
	case 4474ULL: goto x86_l_117a;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4503ULL: goto x86_l_1197;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4526ULL: goto x86_l_11ae;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4536ULL: goto x86_l_11b8;
	case 4540ULL: goto x86_l_11bc;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4557ULL: goto x86_l_11cd;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4568ULL: goto x86_l_11d8;
	case 4570ULL: goto x86_l_11da;
	case 4573ULL: goto x86_l_11dd;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4594ULL: goto x86_l_11f2;
	case 4599ULL: goto x86_l_11f7;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4615ULL: goto x86_l_1207;
	case 4618ULL: goto x86_l_120a;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4636ULL: goto x86_l_121c;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4672ULL: goto x86_l_1240;
	case 4676ULL: goto x86_l_1244;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4719ULL: goto x86_l_126f;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4739ULL: goto x86_l_1283;
	case 4747ULL: goto x86_l_128b;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4763ULL: goto x86_l_129b;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4809ULL: goto x86_l_12c9;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4843ULL: goto x86_l_12eb;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4867ULL: goto x86_l_1303;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4882ULL: goto x86_l_1312;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4907ULL: goto x86_l_132b;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4937ULL: goto x86_l_1349;
	case 4944ULL: goto x86_l_1350;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4956ULL: goto x86_l_135c;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4979ULL: goto x86_l_1373;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4986ULL: goto x86_l_137a;
	case 4993ULL: goto x86_l_1381;
	case 4996ULL: goto x86_l_1384;
	case 4999ULL: goto x86_l_1387;
	case 5002ULL: goto x86_l_138a;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5022ULL: goto x86_l_139e;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5060ULL: goto x86_l_13c4;
	case 5063ULL: goto x86_l_13c7;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5076ULL: goto x86_l_13d4;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5129ULL: goto x86_l_1409;
	case 5137ULL: goto x86_l_1411;
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5156ULL: goto x86_l_1424;
	case 5164ULL: goto x86_l_142c;
	case 5168ULL: goto x86_l_1430;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5192ULL: goto x86_l_1448;
	case 5196ULL: goto x86_l_144c;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5208ULL: goto x86_l_1458;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5221ULL: goto x86_l_1465;
	case 5224ULL: goto x86_l_1468;
	case 5226ULL: goto x86_l_146a;
	case 5229ULL: goto x86_l_146d;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5264ULL: goto x86_l_1490;
	case 5266ULL: goto x86_l_1492;
	case 5270ULL: goto x86_l_1496;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5277ULL: goto x86_l_149d;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5326ULL: goto x86_l_14ce;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5338ULL: goto x86_l_14da;
	case 5341ULL: goto x86_l_14dd;
	case 5343ULL: goto x86_l_14df;
	case 5350ULL: goto x86_l_14e6;
	case 5357ULL: goto x86_l_14ed;
	case 5360ULL: goto x86_l_14f0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ea7:
	/* 0xea7: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_eaa:
	/* 0xeaa: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_eb1:
	/* 0xeb1: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_eb9:
	/* 0xeb9: jb     ef9 <tracepoint__sched__sched_process_fork+0xef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ef9;
	}
x86_l_ebb:
	/* 0xebb: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebd:
	/* 0xebd: mov    DWORD PTR [r12+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec2:
	/* 0xec2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_ec9:
	/* 0xec9: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_ece:
	/* 0xece: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_ed3:
	/* 0xed3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ed6:
	/* 0xed6: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_edb:
	/* 0xedb: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ee3:
	/* 0xee3: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_ee8:
	/* 0xee8: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_eee:
	/* 0xeee: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_ef1:
	/* 0xef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef3:
	/* 0xef3: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef9:
	/* 0xef9: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f01:
	/* 0xf01: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_f08:
	/* 0xf08: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f10:
	/* 0xf10: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f15:
	/* 0xf15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f17:
	/* 0xf17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1a:
	/* 0xf1a: je     348c <tracepoint__sched__sched_process_fork+0x348c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13452ULL;
	}
x86_l_f20:
	/* 0xf20: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f23:
	/* 0xf23: mov    eax,DWORD PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_f2a:
	/* 0xf2a: mov    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_f2e:
	/* 0xf2e: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f35:
	/* 0xf35: mov    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f39:
	/* 0xf39: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f41:
	/* 0xf41: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_f46:
	/* 0xf46: mov    DWORD PTR [rsp],0x30e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 782ULL);
x86_l_f4d:
	/* 0xf4d: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f52:
	/* 0xf52: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_f59:
	/* 0xf59: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f5e:
	/* 0xf5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f63:
	/* 0xf63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f65:
	/* 0xf65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f68:
	/* 0xf68: je     f82 <tracepoint__sched__sched_process_fork+0xf82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f82;
	}
x86_l_f6a:
	/* 0xf6a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f6d:
	/* 0xf6d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f70:
	/* 0xf70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f75:
	/* 0xf75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f77:
	/* 0xf77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7a:
	/* 0xf7a: je     f82 <tracepoint__sched__sched_process_fork+0xf82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f82;
	}
x86_l_f7c:
	/* 0xf7c: cmp    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f80:
	/* 0xf80: jne    fcf <tracepoint__sched__sched_process_fork+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fcf;
	}
x86_l_f82:
	/* 0xf82: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_f87:
	/* 0xf87: mov    DWORD PTR [rsp],0x30f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 783ULL);
x86_l_f8e:
	/* 0xf8e: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f93:
	/* 0xf93: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_f9a:
	/* 0xf9a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f9f:
	/* 0xf9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa4:
	/* 0xfa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa6:
	/* 0xfa6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: je     128b <tracepoint__sched__sched_process_fork+0x128b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128b;
	}
x86_l_faf:
	/* 0xfaf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fb2:
	/* 0xfb2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fb5:
	/* 0xfb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fba:
	/* 0xfba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbc:
	/* 0xfbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: je     128b <tracepoint__sched__sched_process_fork+0x128b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128b;
	}
x86_l_fc5:
	/* 0xfc5: cmp    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc9:
	/* 0xfc9: je     128b <tracepoint__sched__sched_process_fork+0x128b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128b;
	}
x86_l_fcf:
	/* 0xfcf: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fd4:
	/* 0xfd4: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fd8:
	/* 0xfd8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fdb:
	/* 0xfdb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fe0:
	/* 0xfe0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fe5:
	/* 0xfe5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fea:
	/* 0xfea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fec:
	/* 0xfec: test   DWORD PTR [rsp],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2097152ULL);
x86_l_ff3:
	/* 0xff3: jne    1035 <tracepoint__sched__sched_process_fork+0x1035> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1035;
	}
x86_l_ff5:
	/* 0xff5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ff8:
	/* 0xff8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ffd:
	/* 0xffd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1002:
	/* 0x1002: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1007:
	/* 0x1007: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_100a:
	/* 0x100a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100c:
	/* 0x100c: mov    ebx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100f:
	/* 0x100f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1012:
	/* 0x1012: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1017:
	/* 0x1017: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_101c:
	/* 0x101c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1021:
	/* 0x1021: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1026:
	/* 0x1026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1028:
	/* 0x1028: cmp    ebx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_102b:
	/* 0x102b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1033:
	/* 0x1033: jne    1050 <tracepoint__sched__sched_process_fork+0x1050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1050;
	}
x86_l_1035:
	/* 0x1035: mov    QWORD PTR [r15+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1040:
	/* 0x1040: mov    QWORD PTR [r15+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_104b:
	/* 0x104b: jmp    128b <tracepoint__sched__sched_process_fork+0x128b> */
	goto x86_l_128b;
x86_l_1050:
	/* 0x1050: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1055:
	/* 0x1055: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_105a:
	/* 0x105a: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_105f:
	/* 0x105f: lea    rdx,[rbx+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1066:
	/* 0x1066: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1069:
	/* 0x1069: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_106e:
	/* 0x106e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1073:
	/* 0x1073: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1078:
	/* 0x1078: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107a:
	/* 0x107a: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_107f:
	/* 0x107f: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1083:
	/* 0x1083: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1086:
	/* 0x1086: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_108b:
	/* 0x108b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1090:
	/* 0x1090: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1095:
	/* 0x1095: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1097:
	/* 0x1097: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109b:
	/* 0x109b: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_109f:
	/* 0x109f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10a2:
	/* 0x10a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a7:
	/* 0x10a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ac:
	/* 0x10ac: dec    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_10af:
	/* 0x10af: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10b4:
	/* 0x10b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b9:
	/* 0x10b9: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10be:
	/* 0x10be: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10c1:
	/* 0x10c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c3:
	/* 0x10c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c7:
	/* 0x10c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10ca:
	/* 0x10ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10cf:
	/* 0x10cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d4:
	/* 0x10d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d9:
	/* 0x10d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10db:
	/* 0x10db: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10df:
	/* 0x10df: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_10e2:
	/* 0x10e2: je     115d <tracepoint__sched__sched_process_fork+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115d;
	}
x86_l_10e4:
	/* 0x10e4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e6:
	/* 0x10e6: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_10e9:
	/* 0x10e9: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_10ef:
	/* 0x10ef: lea    r15,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_10f3:
	/* 0x10f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f8:
	/* 0x10f8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10fb:
	/* 0x10fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1100:
	/* 0x1100: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1105:
	/* 0x1105: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1109:
	/* 0x1109: lea    rdx,[rbp-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_110d:
	/* 0x110d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1112:
	/* 0x1112: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_111a:
	/* 0x111a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111c:
	/* 0x111c: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1121:
	/* 0x1121: cmp    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1125:
	/* 0x1125: jbe    113b <tracepoint__sched__sched_process_fork+0x113b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_113b;
	}
x86_l_1127:
	/* 0x1127: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: jbe    1229 <tracepoint__sched__sched_process_fork+0x1229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1229;
	}
x86_l_1130:
	/* 0x1130: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1134:
	/* 0x1134: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1139:
	/* 0x1139: jmp    1140 <tracepoint__sched__sched_process_fork+0x1140> */
	goto x86_l_1140;
x86_l_113b:
	/* 0x113b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1140:
	/* 0x1140: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1143:
	/* 0x1143: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1148:
	/* 0x1148: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_114b:
	/* 0x114b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114d:
	/* 0x114d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1151:
	/* 0x1151: cmp    ebx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 33ULL);
x86_l_1154:
	/* 0x1154: ja     115d <tracepoint__sched__sched_process_fork+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_115d;
	}
x86_l_1156:
	/* 0x1156: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1158:
	/* 0x1158: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_115b:
	/* 0x115b: jne    10ef <tracepoint__sched__sched_process_fork+0x10ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10ef;
	}
x86_l_115d:
	/* 0x115d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1160:
	/* 0x1160: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1165:
	/* 0x1165: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_116a:
	/* 0x116a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_116f:
	/* 0x116f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1174:
	/* 0x1174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1176:
	/* 0x1176: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117a:
	/* 0x117a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_117d:
	/* 0x117d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1182:
	/* 0x1182: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1187:
	/* 0x1187: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118c:
	/* 0x118c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118e:
	/* 0x118e: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1192:
	/* 0x1192: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1195:
	/* 0x1195: je     120c <tracepoint__sched__sched_process_fork+0x120c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120c;
	}
x86_l_1197:
	/* 0x1197: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1199:
	/* 0x1199: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_11a2:
	/* 0x11a2: lea    r15,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_11a6:
	/* 0x11a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ab:
	/* 0x11ab: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_11ae:
	/* 0x11ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b3:
	/* 0x11b3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11b6:
	/* 0x11b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b8:
	/* 0x11b8: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bc:
	/* 0x11bc: lea    rdx,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_11c0:
	/* 0x11c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11c5:
	/* 0x11c5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_11c8:
	/* 0x11c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11cd:
	/* 0x11cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cf:
	/* 0x11cf: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11d4:
	/* 0x11d4: cmp    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d8:
	/* 0x11d8: jbe    11ea <tracepoint__sched__sched_process_fork+0x11ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_11ea;
	}
x86_l_11da:
	/* 0x11da: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_11dd:
	/* 0x11dd: jbe    1229 <tracepoint__sched__sched_process_fork+0x1229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1229;
	}
x86_l_11df:
	/* 0x11df: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_11e3:
	/* 0x11e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11e8:
	/* 0x11e8: jmp    11ef <tracepoint__sched__sched_process_fork+0x11ef> */
	goto x86_l_11ef;
x86_l_11ea:
	/* 0x11ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ef:
	/* 0x11ef: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_11f2:
	/* 0x11f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f7:
	/* 0x11f7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11fa:
	/* 0x11fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fc:
	/* 0x11fc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1200:
	/* 0x1200: cmp    ebp,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 33ULL);
x86_l_1203:
	/* 0x1203: ja     120c <tracepoint__sched__sched_process_fork+0x120c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_120c;
	}
x86_l_1205:
	/* 0x1205: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1207:
	/* 0x1207: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_120a:
	/* 0x120a: jne    11a2 <tracepoint__sched__sched_process_fork+0x11a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11a2;
	}
x86_l_120c:
	/* 0x120c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1211:
	/* 0x1211: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_121c:
	/* 0x121c: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_1227:
	/* 0x1227: jmp    1276 <tracepoint__sched__sched_process_fork+0x1276> */
	goto x86_l_1276;
x86_l_1229:
	/* 0x1229: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_122c:
	/* 0x122c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1231:
	/* 0x1231: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1236:
	/* 0x1236: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_123b:
	/* 0x123b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_123e:
	/* 0x123e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1240:
	/* 0x1240: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1244:
	/* 0x1244: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1248:
	/* 0x1248: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_124b:
	/* 0x124b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1250:
	/* 0x1250: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1255:
	/* 0x1255: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_125a:
	/* 0x125a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_125d:
	/* 0x125d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125f:
	/* 0x125f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1263:
	/* 0x1263: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [rcx+0xb8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_126f:
	/* 0x126f: mov    QWORD PTR [rcx+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1276:
	/* 0x1276: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_127b:
	/* 0x127b: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1283:
	/* 0x1283: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_128b:
	/* 0x128b: lea    rax,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_128f:
	/* 0x128f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1294:
	/* 0x1294: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_129b:
	/* 0x129b: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_12a3:
	/* 0x12a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a8:
	/* 0x12a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12aa:
	/* 0x12aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ad:
	/* 0x12ad: je     12c2 <tracepoint__sched__sched_process_fork+0x12c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c2;
	}
x86_l_12af:
	/* 0x12af: cmp    QWORD PTR [r14+0x7e70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139019501436928ULL);
x86_l_12b7:
	/* 0x12b7: jne    1af1 <tracepoint__sched__sched_process_fork+0x1af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6897ULL;
	}
x86_l_12bd:
	/* 0x12bd: jmp    1b51 <tracepoint__sched__sched_process_fork+0x1b51> */
	return 6993ULL;
x86_l_12c2:
	/* 0x12c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_12c9:
	/* 0x12c9: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_12d1:
	/* 0x12d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d6:
	/* 0x12d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d8:
	/* 0x12d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12db:
	/* 0x12db: je     35d5 <tracepoint__sched__sched_process_fork+0x35d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13781ULL;
	}
x86_l_12e1:
	/* 0x12e1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_12e4:
	/* 0x12e4: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_12eb:
	/* 0x12eb: lea    r12,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_12f3:
	/* 0x12f3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12f8:
	/* 0x12f8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1303:
	/* 0x1303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1305:
	/* 0x1305: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130a:
	/* 0x130a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_130d:
	/* 0x130d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1310:
	/* 0x1310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1312:
	/* 0x1312: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1315:
	/* 0x1315: je     36e2 <tracepoint__sched__sched_process_fork+0x36e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14050ULL;
	}
x86_l_131b:
	/* 0x131b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1320:
	/* 0x1320: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1324:
	/* 0x1324: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1329:
	/* 0x1329: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_132b:
	/* 0x132b: jne    1339 <tracepoint__sched__sched_process_fork+0x1339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1339;
	}
x86_l_132d:
	/* 0x132d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132f:
	/* 0x132f: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1334:
	/* 0x1334: jmp    1ae0 <tracepoint__sched__sched_process_fork+0x1ae0> */
	return 6880ULL;
x86_l_1339:
	/* 0x1339: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_1340:
	/* 0x1340: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1343:
	/* 0x1343: je     14df <tracepoint__sched__sched_process_fork+0x14df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14df;
	}
x86_l_1349:
	/* 0x1349: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_1350:
	/* 0x1350: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1353:
	/* 0x1353: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1355:
	/* 0x1355: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1358:
	/* 0x1358: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_135c:
	/* 0x135c: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_135f:
	/* 0x135f: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1362:
	/* 0x1362: xor    rbp,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_1369:
	/* 0x1369: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_136c:
	/* 0x136c: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1373:
	/* 0x1373: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1376:
	/* 0x1376: je     1397 <tracepoint__sched__sched_process_fork+0x1397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1397;
	}
x86_l_1378:
	/* 0x1378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137a:
	/* 0x137a: cmp    BYTE PTR [rbx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1381:
	/* 0x1381: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1384:
	/* 0x1384: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1387:
	/* 0x1387: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_138a:
	/* 0x138a: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1391:
	/* 0x1391: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1394:
	/* 0x1394: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1397:
	/* 0x1397: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_139e:
	/* 0x139e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13a1:
	/* 0x13a1: je     13bd <tracepoint__sched__sched_process_fork+0x13bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bd;
	}
x86_l_13a3:
	/* 0x13a3: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_13a7:
	/* 0x13a7: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13aa:
	/* 0x13aa: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_13ad:
	/* 0x13ad: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_13b0:
	/* 0x13b0: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_13b7:
	/* 0x13b7: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ba:
	/* 0x13ba: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_13bd:
	/* 0x13bd: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_13c4:
	/* 0x13c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c7:
	/* 0x13c7: je     13e8 <tracepoint__sched__sched_process_fork+0x13e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e8;
	}
x86_l_13c9:
	/* 0x13c9: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13cc:
	/* 0x13cc: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13d4:
	/* 0x13d4: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_13d8:
	/* 0x13d8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_13db:
	/* 0x13db: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_13e2:
	/* 0x13e2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13e5:
	/* 0x13e5: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_13e8:
	/* 0x13e8: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_13ed:
	/* 0x13ed: mov    r13,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_13f4:
	/* 0x13f4: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_13f7:
	/* 0x13f7: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13fc:
	/* 0x13fc: je     1545 <tracepoint__sched__sched_process_fork+0x1545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5445ULL;
	}
x86_l_1402:
	/* 0x1402: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1409:
	/* 0x1409: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1411:
	/* 0x1411: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_1418:
	/* 0x1418: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_141d:
	/* 0x141d: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_1424:
	/* 0x1424: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_142c:
	/* 0x142c: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1430:
	/* 0x1430: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_1437:
	/* 0x1437: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_143a:
	/* 0x143a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143f:
	/* 0x143f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1441:
	/* 0x1441: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1444:
	/* 0x1444: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1448:
	/* 0x1448: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144c:
	/* 0x144c: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1453:
	/* 0x1453: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1456:
	/* 0x1456: je     1476 <tracepoint__sched__sched_process_fork+0x1476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1476;
	}
x86_l_1458:
	/* 0x1458: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_145b:
	/* 0x145b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1460:
	/* 0x1460: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1463:
	/* 0x1463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1465:
	/* 0x1465: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1468:
	/* 0x1468: je     1476 <tracepoint__sched__sched_process_fork+0x1476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1476;
	}
x86_l_146a:
	/* 0x146a: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146d:
	/* 0x146d: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1471:
	/* 0x1471: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1474:
	/* 0x1474: jmp    1479 <tracepoint__sched__sched_process_fork+0x1479> */
	goto x86_l_1479;
x86_l_1476:
	/* 0x1476: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1479:
	/* 0x1479: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1481:
	/* 0x1481: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1486:
	/* 0x1486: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_148a:
	/* 0x148a: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_148d:
	/* 0x148d: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1490:
	/* 0x1490: jb     14a8 <tracepoint__sched__sched_process_fork+0x14a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_14a8;
	}
x86_l_1492:
	/* 0x1492: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1496:
	/* 0x1496: je     149d <tracepoint__sched__sched_process_fork+0x149d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_149d;
	}
x86_l_1498:
	/* 0x1498: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_149b:
	/* 0x149b: jbe    14a8 <tracepoint__sched__sched_process_fork+0x14a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14a8;
	}
x86_l_149d:
	/* 0x149d: and    rbx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 256ULL);
x86_l_14a5:
	/* 0x14a5: or     r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14a8:
	/* 0x14a8: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ac:
	/* 0x14ac: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b0:
	/* 0x14b0: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14b7:
	/* 0x14b7: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_14ba:
	/* 0x14ba: je     14fb <tracepoint__sched__sched_process_fork+0x14fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5371ULL;
	}
x86_l_14bc:
	/* 0x14bc: mov    QWORD PTR [rsp+0x70],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14c1:
	/* 0x14c1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_14c4:
	/* 0x14c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c9:
	/* 0x14c9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_14cc:
	/* 0x14cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ce:
	/* 0x14ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d1:
	/* 0x14d1: je     150b <tracepoint__sched__sched_process_fork+0x150b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5387ULL;
	}
x86_l_14d3:
	/* 0x14d3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d6:
	/* 0x14d6: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14da:
	/* 0x14da: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14dd:
	/* 0x14dd: jmp    150d <tracepoint__sched__sched_process_fork+0x150d> */
	return 5389ULL;
x86_l_14df:
	/* 0x14df: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14e6:
	/* 0x14e6: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_14ed:
	/* 0x14ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f0:
	/* 0x14f0: jne    1378 <tracepoint__sched__sched_process_fork+0x1378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1378;
	}
	return 5366ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5366ULL: goto x86_l_14f6;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5376ULL: goto x86_l_1500;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5387ULL: goto x86_l_150b;
	case 5389ULL: goto x86_l_150d;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5405ULL: goto x86_l_151d;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5414ULL: goto x86_l_1526;
	case 5418ULL: goto x86_l_152a;
	case 5420ULL: goto x86_l_152c;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5433ULL: goto x86_l_1539;
	case 5436ULL: goto x86_l_153c;
	case 5439ULL: goto x86_l_153f;
	case 5442ULL: goto x86_l_1542;
	case 5445ULL: goto x86_l_1545;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5466ULL: goto x86_l_155a;
	case 5470ULL: goto x86_l_155e;
	case 5477ULL: goto x86_l_1565;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5496ULL: goto x86_l_1578;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5512ULL: goto x86_l_1588;
	case 5519ULL: goto x86_l_158f;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5536ULL: goto x86_l_15a0;
	case 5540ULL: goto x86_l_15a4;
	case 5547ULL: goto x86_l_15ab;
	case 5550ULL: goto x86_l_15ae;
	case 5552ULL: goto x86_l_15b0;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5567ULL: goto x86_l_15bf;
	case 5570ULL: goto x86_l_15c2;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5610ULL: goto x86_l_15ea;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5656ULL: goto x86_l_1618;
	case 5664ULL: goto x86_l_1620;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5695ULL: goto x86_l_163f;
	case 5700ULL: goto x86_l_1644;
	case 5702ULL: goto x86_l_1646;
	case 5706ULL: goto x86_l_164a;
	case 5710ULL: goto x86_l_164e;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5730ULL: goto x86_l_1662;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5775ULL: goto x86_l_168f;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5794ULL: goto x86_l_16a2;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	case 5814ULL: goto x86_l_16b6;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5822ULL: goto x86_l_16be;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5836ULL: goto x86_l_16cc;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5850ULL: goto x86_l_16da;
	case 5852ULL: goto x86_l_16dc;
	case 5855ULL: goto x86_l_16df;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5864ULL: goto x86_l_16e8;
	case 5872ULL: goto x86_l_16f0;
	case 5878ULL: goto x86_l_16f6;
	case 5885ULL: goto x86_l_16fd;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5913ULL: goto x86_l_1719;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5934ULL: goto x86_l_172e;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5943ULL: goto x86_l_1737;
	case 5947ULL: goto x86_l_173b;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5959ULL: goto x86_l_1747;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5979ULL: goto x86_l_175b;
	case 5982ULL: goto x86_l_175e;
	case 5987ULL: goto x86_l_1763;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6006ULL: goto x86_l_1776;
	case 6013ULL: goto x86_l_177d;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6043ULL: goto x86_l_179b;
	case 6045ULL: goto x86_l_179d;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6057ULL: goto x86_l_17a9;
	case 6060ULL: goto x86_l_17ac;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6071ULL: goto x86_l_17b7;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6083ULL: goto x86_l_17c3;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6093ULL: goto x86_l_17cd;
	case 6096ULL: goto x86_l_17d0;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6128ULL: goto x86_l_17f0;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6148ULL: goto x86_l_1804;
	case 6152ULL: goto x86_l_1808;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6172ULL: goto x86_l_181c;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6192ULL: goto x86_l_1830;
	case 6197ULL: goto x86_l_1835;
	case 6199ULL: goto x86_l_1837;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6233ULL: goto x86_l_1859;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6249ULL: goto x86_l_1869;
	case 6256ULL: goto x86_l_1870;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6276ULL: goto x86_l_1884;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6292ULL: goto x86_l_1894;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6306ULL: goto x86_l_18a2;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6319ULL: goto x86_l_18af;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6333ULL: goto x86_l_18bd;
	case 6339ULL: goto x86_l_18c3;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6376ULL: goto x86_l_18e8;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6415ULL: goto x86_l_190f;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6436ULL: goto x86_l_1924;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6445ULL: goto x86_l_192d;
	case 6448ULL: goto x86_l_1930;
	case 6450ULL: goto x86_l_1932;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6464ULL: goto x86_l_1940;
	case 6470ULL: goto x86_l_1946;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6482ULL: goto x86_l_1952;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6502ULL: goto x86_l_1966;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6536ULL: goto x86_l_1988;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6549ULL: goto x86_l_1995;
	case 6552ULL: goto x86_l_1998;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6566ULL: goto x86_l_19a6;
	case 6568ULL: goto x86_l_19a8;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6587ULL: goto x86_l_19bb;
	case 6590ULL: goto x86_l_19be;
	case 6592ULL: goto x86_l_19c0;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6611ULL: goto x86_l_19d3;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6631ULL: goto x86_l_19e7;
	case 6634ULL: goto x86_l_19ea;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6651ULL: goto x86_l_19fb;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6673ULL: goto x86_l_1a11;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6689ULL: goto x86_l_1a21;
	case 6692ULL: goto x86_l_1a24;
	case 6698ULL: goto x86_l_1a2a;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6742ULL: goto x86_l_1a56;
	case 6745ULL: goto x86_l_1a59;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6765ULL: goto x86_l_1a6d;
	case 6767ULL: goto x86_l_1a6f;
	case 6770ULL: goto x86_l_1a72;
	case 6772ULL: goto x86_l_1a74;
	case 6780ULL: goto x86_l_1a7c;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6792ULL: goto x86_l_1a88;
	case 6794ULL: goto x86_l_1a8a;
	case 6797ULL: goto x86_l_1a8d;
	case 6799ULL: goto x86_l_1a8f;
	case 6802ULL: goto x86_l_1a92;
	case 6806ULL: goto x86_l_1a96;
	case 6809ULL: goto x86_l_1a99;
	case 6811ULL: goto x86_l_1a9b;
	case 6813ULL: goto x86_l_1a9d;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6825ULL: goto x86_l_1aa9;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6843ULL: goto x86_l_1abb;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6861ULL: goto x86_l_1acd;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6880ULL: goto x86_l_1ae0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14f6:
	/* 0x14f6: jmp    1397 <tracepoint__sched__sched_process_fork+0x1397> */
	return 5015ULL;
x86_l_14fb:
	/* 0x14fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fd:
	/* 0x14fd: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1500:
	/* 0x1500: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1504:
	/* 0x1504: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1507:
	/* 0x1507: jae    1526 <tracepoint__sched__sched_process_fork+0x1526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1526;
	}
x86_l_1509:
	/* 0x1509: jmp    153c <tracepoint__sched__sched_process_fork+0x153c> */
	goto x86_l_153c;
x86_l_150b:
	/* 0x150b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150d:
	/* 0x150d: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1515:
	/* 0x1515: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_151a:
	/* 0x151a: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_151d:
	/* 0x151d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1521:
	/* 0x1521: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: jb     153c <tracepoint__sched__sched_process_fork+0x153c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_153c;
	}
x86_l_1526:
	/* 0x1526: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_152a:
	/* 0x152a: je     1531 <tracepoint__sched__sched_process_fork+0x1531> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1531;
	}
x86_l_152c:
	/* 0x152c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_152f:
	/* 0x152f: jbe    153c <tracepoint__sched__sched_process_fork+0x153c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_153c;
	}
x86_l_1531:
	/* 0x1531: and    rbx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 256ULL);
x86_l_1539:
	/* 0x1539: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_153c:
	/* 0x153c: or     r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_153f:
	/* 0x153f: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1542:
	/* 0x1542: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1545:
	/* 0x1545: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_154d:
	/* 0x154d: je     15e4 <tracepoint__sched__sched_process_fork+0x15e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e4;
	}
x86_l_1553:
	/* 0x1553: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1558:
	/* 0x1558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155a:
	/* 0x155a: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_155e:
	/* 0x155e: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1565:
	/* 0x1565: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_156c:
	/* 0x156c: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1571:
	/* 0x1571: mov    r13,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_1578:
	/* 0x1578: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_157f:
	/* 0x157f: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1584:
	/* 0x1584: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1588:
	/* 0x1588: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_158f:
	/* 0x158f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1592:
	/* 0x1592: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1597:
	/* 0x1597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1599:
	/* 0x1599: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_159c:
	/* 0x159c: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15a0:
	/* 0x15a0: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a4:
	/* 0x15a4: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15ab:
	/* 0x15ab: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_15ae:
	/* 0x15ae: je     15cb <tracepoint__sched__sched_process_fork+0x15cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15cb;
	}
x86_l_15b0:
	/* 0x15b0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_15b3:
	/* 0x15b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b8:
	/* 0x15b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ba:
	/* 0x15ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15bd:
	/* 0x15bd: je     15cb <tracepoint__sched__sched_process_fork+0x15cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15cb;
	}
x86_l_15bf:
	/* 0x15bf: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c2:
	/* 0x15c2: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c6:
	/* 0x15c6: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15c9:
	/* 0x15c9: jmp    15cd <tracepoint__sched__sched_process_fork+0x15cd> */
	goto x86_l_15cd;
x86_l_15cb:
	/* 0x15cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15cd:
	/* 0x15cd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15d0:
	/* 0x15d0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d4:
	/* 0x15d4: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_15d7:
	/* 0x15d7: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_15da:
	/* 0x15da: jae    15f9 <tracepoint__sched__sched_process_fork+0x15f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15f9;
	}
x86_l_15dc:
	/* 0x15dc: movzx  r13d,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_15e2:
	/* 0x15e2: jmp    1612 <tracepoint__sched__sched_process_fork+0x1612> */
	goto x86_l_1612;
x86_l_15e4:
	/* 0x15e4: movzx  r13d,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_15ea:
	/* 0x15ea: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_15f2:
	/* 0x15f2: jne    1626 <tracepoint__sched__sched_process_fork+0x1626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1626;
	}
x86_l_15f4:
	/* 0x15f4: jmp    16e8 <tracepoint__sched__sched_process_fork+0x16e8> */
	goto x86_l_16e8;
x86_l_15f9:
	/* 0x15f9: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15fd:
	/* 0x15fd: movzx  r13d,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1603:
	/* 0x1603: je     160a <tracepoint__sched__sched_process_fork+0x160a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160a;
	}
x86_l_1605:
	/* 0x1605: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1608:
	/* 0x1608: jbe    1612 <tracepoint__sched__sched_process_fork+0x1612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1612;
	}
x86_l_160a:
	/* 0x160a: and    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_160f:
	/* 0x160f: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1612:
	/* 0x1612: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1615:
	/* 0x1615: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1618:
	/* 0x1618: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1620:
	/* 0x1620: je     16e8 <tracepoint__sched__sched_process_fork+0x16e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16e8;
	}
x86_l_1626:
	/* 0x1626: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_162b:
	/* 0x162b: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1632:
	/* 0x1632: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1635:
	/* 0x1635: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_163a:
	/* 0x163a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_163f:
	/* 0x163f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1644:
	/* 0x1644: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1646:
	/* 0x1646: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164a:
	/* 0x164a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_164e:
	/* 0x164e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1651:
	/* 0x1651: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1656:
	/* 0x1656: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_165b:
	/* 0x165b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1660:
	/* 0x1660: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1662:
	/* 0x1662: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1666:
	/* 0x1666: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_166b:
	/* 0x166b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1670:
	/* 0x1670: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1675:
	/* 0x1675: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1679:
	/* 0x1679: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_167e:
	/* 0x167e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1680:
	/* 0x1680: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1684:
	/* 0x1684: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1688:
	/* 0x1688: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_168f:
	/* 0x168f: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1696:
	/* 0x1696: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169b:
	/* 0x169b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_16a2:
	/* 0x16a2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16a5:
	/* 0x16a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16aa:
	/* 0x16aa: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16ad:
	/* 0x16ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16af:
	/* 0x16af: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_16b6:
	/* 0x16b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b9:
	/* 0x16b9: je     16da <tracepoint__sched__sched_process_fork+0x16da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16da;
	}
x86_l_16bb:
	/* 0x16bb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16be:
	/* 0x16be: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_16c2:
	/* 0x16c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c7:
	/* 0x16c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c9:
	/* 0x16c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16cc:
	/* 0x16cc: je     16da <tracepoint__sched__sched_process_fork+0x16da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16da;
	}
x86_l_16ce:
	/* 0x16ce: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d1:
	/* 0x16d1: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d5:
	/* 0x16d5: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16d8:
	/* 0x16d8: jmp    16dc <tracepoint__sched__sched_process_fork+0x16dc> */
	goto x86_l_16dc;
x86_l_16da:
	/* 0x16da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16dc:
	/* 0x16dc: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16df:
	/* 0x16df: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_16e2:
	/* 0x16e2: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16e5:
	/* 0x16e5: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_16e8:
	/* 0x16e8: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_16f0:
	/* 0x16f0: je     17d6 <tracepoint__sched__sched_process_fork+0x17d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d6;
	}
x86_l_16f6:
	/* 0x16f6: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_16fd:
	/* 0x16fd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1701:
	/* 0x1701: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1704:
	/* 0x1704: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1709:
	/* 0x1709: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_170e:
	/* 0x170e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1713:
	/* 0x1713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1715:
	/* 0x1715: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1719:
	/* 0x1719: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_171c:
	/* 0x171c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1721:
	/* 0x1721: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1726:
	/* 0x1726: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_172b:
	/* 0x172b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_172e:
	/* 0x172e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1730:
	/* 0x1730: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1733:
	/* 0x1733: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1737:
	/* 0x1737: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_173b:
	/* 0x173b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_173f:
	/* 0x173f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1742:
	/* 0x1742: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1747:
	/* 0x1747: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_174c:
	/* 0x174c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1751:
	/* 0x1751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1753:
	/* 0x1753: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1757:
	/* 0x1757: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_175b:
	/* 0x175b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_175e:
	/* 0x175e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1763:
	/* 0x1763: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1768:
	/* 0x1768: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_176d:
	/* 0x176d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176f:
	/* 0x176f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1772:
	/* 0x1772: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1776:
	/* 0x1776: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_177d:
	/* 0x177d: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1784:
	/* 0x1784: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1789:
	/* 0x1789: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1790:
	/* 0x1790: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1793:
	/* 0x1793: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1798:
	/* 0x1798: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_179b:
	/* 0x179b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179d:
	/* 0x179d: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17a4:
	/* 0x17a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17a7:
	/* 0x17a7: je     17c8 <tracepoint__sched__sched_process_fork+0x17c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c8;
	}
x86_l_17a9:
	/* 0x17a9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17ac:
	/* 0x17ac: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17b0:
	/* 0x17b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17b5:
	/* 0x17b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b7:
	/* 0x17b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ba:
	/* 0x17ba: je     17c8 <tracepoint__sched__sched_process_fork+0x17c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c8;
	}
x86_l_17bc:
	/* 0x17bc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17bf:
	/* 0x17bf: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c3:
	/* 0x17c3: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17c6:
	/* 0x17c6: jmp    17ca <tracepoint__sched__sched_process_fork+0x17ca> */
	goto x86_l_17ca;
x86_l_17c8:
	/* 0x17c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ca:
	/* 0x17ca: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_17cd:
	/* 0x17cd: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_17d0:
	/* 0x17d0: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_17d3:
	/* 0x17d3: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_17d6:
	/* 0x17d6: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_17de:
	/* 0x17de: je     18b5 <tracepoint__sched__sched_process_fork+0x18b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b5;
	}
x86_l_17e4:
	/* 0x17e4: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_17e9:
	/* 0x17e9: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_17f0:
	/* 0x17f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17f3:
	/* 0x17f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17f8:
	/* 0x17f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17fd:
	/* 0x17fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1802:
	/* 0x1802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1804:
	/* 0x1804: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1808:
	/* 0x1808: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_180b:
	/* 0x180b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1810:
	/* 0x1810: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1815:
	/* 0x1815: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_181a:
	/* 0x181a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181c:
	/* 0x181c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1820:
	/* 0x1820: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1823:
	/* 0x1823: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1828:
	/* 0x1828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_182d:
	/* 0x182d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1830:
	/* 0x1830: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1835:
	/* 0x1835: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1837:
	/* 0x1837: lea    r12,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_183b:
	/* 0x183b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1840:
	/* 0x1840: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1845:
	/* 0x1845: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1848:
	/* 0x1848: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_184d:
	/* 0x184d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1850:
	/* 0x1850: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1852:
	/* 0x1852: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1859:
	/* 0x1859: mov    r15,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1860:
	/* 0x1860: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1865:
	/* 0x1865: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1869:
	/* 0x1869: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1870:
	/* 0x1870: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1873:
	/* 0x1873: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1878:
	/* 0x1878: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_187b:
	/* 0x187b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187d:
	/* 0x187d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1884:
	/* 0x1884: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1887:
	/* 0x1887: je     18a7 <tracepoint__sched__sched_process_fork+0x18a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a7;
	}
x86_l_1889:
	/* 0x1889: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_188c:
	/* 0x188c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1891:
	/* 0x1891: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1894:
	/* 0x1894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1896:
	/* 0x1896: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1899:
	/* 0x1899: je     18a7 <tracepoint__sched__sched_process_fork+0x18a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a7;
	}
x86_l_189b:
	/* 0x189b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189e:
	/* 0x189e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a2:
	/* 0x18a2: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18a5:
	/* 0x18a5: jmp    18a9 <tracepoint__sched__sched_process_fork+0x18a9> */
	goto x86_l_18a9;
x86_l_18a7:
	/* 0x18a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a9:
	/* 0x18a9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_18ac:
	/* 0x18ac: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_18af:
	/* 0x18af: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_18b2:
	/* 0x18b2: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_18b5:
	/* 0x18b5: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_18bd:
	/* 0x18bd: movzx  r13d,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_18c3:
	/* 0x18c3: je     1946 <tracepoint__sched__sched_process_fork+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1946;
	}
x86_l_18c9:
	/* 0x18c9: lea    r12,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_18cd:
	/* 0x18cd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_18d2:
	/* 0x18d2: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_18d7:
	/* 0x18d7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_18da:
	/* 0x18da: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_18df:
	/* 0x18df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e1:
	/* 0x18e1: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_18e8:
	/* 0x18e8: mov    r15,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_18ef:
	/* 0x18ef: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f4:
	/* 0x18f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_18fb:
	/* 0x18fb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18fe:
	/* 0x18fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1903:
	/* 0x1903: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1906:
	/* 0x1906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1908:
	/* 0x1908: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_190f:
	/* 0x190f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1912:
	/* 0x1912: je     1932 <tracepoint__sched__sched_process_fork+0x1932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1932;
	}
x86_l_1914:
	/* 0x1914: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1917:
	/* 0x1917: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_191c:
	/* 0x191c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_191f:
	/* 0x191f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1921:
	/* 0x1921: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1924:
	/* 0x1924: je     1932 <tracepoint__sched__sched_process_fork+0x1932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1932;
	}
x86_l_1926:
	/* 0x1926: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1929:
	/* 0x1929: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192d:
	/* 0x192d: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1930:
	/* 0x1930: jmp    1934 <tracepoint__sched__sched_process_fork+0x1934> */
	goto x86_l_1934;
x86_l_1932:
	/* 0x1932: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1934:
	/* 0x1934: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1937:
	/* 0x1937: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_193a:
	/* 0x193a: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_193d:
	/* 0x193d: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1940:
	/* 0x1940: movzx  r13d,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1946:
	/* 0x1946: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_194d:
	/* 0x194d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1950:
	/* 0x1950: je     19b4 <tracepoint__sched__sched_process_fork+0x19b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b4;
	}
x86_l_1952:
	/* 0x1952: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1956:
	/* 0x1956: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1959:
	/* 0x1959: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1960:
	/* 0x1960: mov    WORD PTR [rsp+0x50],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1966:
	/* 0x1966: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_196d:
	/* 0x196d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1972:
	/* 0x1972: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1977:
	/* 0x1977: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_197a:
	/* 0x197a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197c:
	/* 0x197c: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1983:
	/* 0x1983: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1986:
	/* 0x1986: je     19a6 <tracepoint__sched__sched_process_fork+0x19a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a6;
	}
x86_l_1988:
	/* 0x1988: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_198b:
	/* 0x198b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_198e:
	/* 0x198e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1993:
	/* 0x1993: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1995:
	/* 0x1995: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1998:
	/* 0x1998: je     19a6 <tracepoint__sched__sched_process_fork+0x19a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a6;
	}
x86_l_199a:
	/* 0x199a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_199d:
	/* 0x199d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a1:
	/* 0x19a1: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19a4:
	/* 0x19a4: jmp    19a8 <tracepoint__sched__sched_process_fork+0x19a8> */
	goto x86_l_19a8;
x86_l_19a6:
	/* 0x19a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a8:
	/* 0x19a8: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19ab:
	/* 0x19ab: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_19ae:
	/* 0x19ae: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19b1:
	/* 0x19b1: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_19b4:
	/* 0x19b4: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_19bb:
	/* 0x19bb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_19be:
	/* 0x19be: je     1a1a <tracepoint__sched__sched_process_fork+0x1a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a1a;
	}
x86_l_19c0:
	/* 0x19c0: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_19c7:
	/* 0x19c7: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19cc:
	/* 0x19cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_19d3:
	/* 0x19d3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_19d6:
	/* 0x19d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19db:
	/* 0x19db: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19de:
	/* 0x19de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e0:
	/* 0x19e0: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_19e7:
	/* 0x19e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19ea:
	/* 0x19ea: je     1a0c <tracepoint__sched__sched_process_fork+0x1a0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a0c;
	}
x86_l_19ec:
	/* 0x19ec: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19ef:
	/* 0x19ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f4:
	/* 0x19f4: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19f9:
	/* 0x19f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fb:
	/* 0x19fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19fe:
	/* 0x19fe: je     1a0c <tracepoint__sched__sched_process_fork+0x1a0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a0c;
	}
x86_l_1a00:
	/* 0x1a00: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a03:
	/* 0x1a03: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a07:
	/* 0x1a07: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a0a:
	/* 0x1a0a: jmp    1a0e <tracepoint__sched__sched_process_fork+0x1a0e> */
	goto x86_l_1a0e;
x86_l_1a0c:
	/* 0x1a0c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0e:
	/* 0x1a0e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a11:
	/* 0x1a11: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a14:
	/* 0x1a14: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a17:
	/* 0x1a17: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a1a:
	/* 0x1a1a: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1a21:
	/* 0x1a21: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1a24:
	/* 0x1a24: je     1aa9 <tracepoint__sched__sched_process_fork+0x1aa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aa9;
	}
x86_l_1a2a:
	/* 0x1a2a: mov    r15,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1a31:
	/* 0x1a31: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a36:
	/* 0x1a36: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1a3d:
	/* 0x1a3d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a45:
	/* 0x1a45: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a48:
	/* 0x1a48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4a:
	/* 0x1a4a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1a51:
	/* 0x1a51: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a54:
	/* 0x1a54: je     1a9b <tracepoint__sched__sched_process_fork+0x1a9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9b;
	}
x86_l_1a56:
	/* 0x1a56: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1a59:
	/* 0x1a59: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a61:
	/* 0x1a61: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a65:
	/* 0x1a65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a6d:
	/* 0x1a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6f:
	/* 0x1a6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a72:
	/* 0x1a72: jne    1a8f <tracepoint__sched__sched_process_fork+0x1a8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a8f;
	}
x86_l_1a74:
	/* 0x1a74: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a7c:
	/* 0x1a7c: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a80:
	/* 0x1a80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a85:
	/* 0x1a85: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a88:
	/* 0x1a88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8a:
	/* 0x1a8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8d:
	/* 0x1a8d: je     1a9b <tracepoint__sched__sched_process_fork+0x1a9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9b;
	}
x86_l_1a8f:
	/* 0x1a8f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a92:
	/* 0x1a92: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a96:
	/* 0x1a96: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a99:
	/* 0x1a99: jmp    1a9d <tracepoint__sched__sched_process_fork+0x1a9d> */
	goto x86_l_1a9d;
x86_l_1a9b:
	/* 0x1a9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9d:
	/* 0x1a9d: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1aa0:
	/* 0x1aa0: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1aa3:
	/* 0x1aa3: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1aa6:
	/* 0x1aa6: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1aa9:
	/* 0x1aa9: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1ab0:
	/* 0x1ab0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ab3:
	/* 0x1ab3: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1abb:
	/* 0x1abb: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ac3:
	/* 0x1ac3: je     1ad4 <tracepoint__sched__sched_process_fork+0x1ad4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad4;
	}
x86_l_1ac5:
	/* 0x1ac5: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1acd:
	/* 0x1acd: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1ad1:
	/* 0x1ad1: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ad4:
	/* 0x1ad4: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ad9:
	/* 0x1ad9: and    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 6884ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6910ULL: goto x86_l_1afe;
	case 6917ULL: goto x86_l_1b05;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6932ULL: goto x86_l_1b14;
	case 6935ULL: goto x86_l_1b17;
	case 6937ULL: goto x86_l_1b19;
	case 6940ULL: goto x86_l_1b1c;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6963ULL: goto x86_l_1b33;
	case 6966ULL: goto x86_l_1b36;
	case 6968ULL: goto x86_l_1b38;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7010ULL: goto x86_l_1b62;
	case 7013ULL: goto x86_l_1b65;
	case 7020ULL: goto x86_l_1b6c;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7042ULL: goto x86_l_1b82;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7070ULL: goto x86_l_1b9e;
	case 7073ULL: goto x86_l_1ba1;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7108ULL: goto x86_l_1bc4;
	case 7116ULL: goto x86_l_1bcc;
	case 7126ULL: goto x86_l_1bd6;
	case 7130ULL: goto x86_l_1bda;
	case 7140ULL: goto x86_l_1be4;
	case 7144ULL: goto x86_l_1be8;
	case 7154ULL: goto x86_l_1bf2;
	case 7158ULL: goto x86_l_1bf6;
	case 7168ULL: goto x86_l_1c00;
	case 7172ULL: goto x86_l_1c04;
	case 7177ULL: goto x86_l_1c09;
	case 7185ULL: goto x86_l_1c11;
	case 7194ULL: goto x86_l_1c1a;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7230ULL: goto x86_l_1c3e;
	case 7233ULL: goto x86_l_1c41;
	case 7239ULL: goto x86_l_1c47;
	case 7243ULL: goto x86_l_1c4b;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7254ULL: goto x86_l_1c56;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7267ULL: goto x86_l_1c63;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7276ULL: goto x86_l_1c6c;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7329ULL: goto x86_l_1ca1;
	case 7337ULL: goto x86_l_1ca9;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7354ULL: goto x86_l_1cba;
	case 7361ULL: goto x86_l_1cc1;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7377ULL: goto x86_l_1cd1;
	case 7380ULL: goto x86_l_1cd4;
	case 7383ULL: goto x86_l_1cd7;
	case 7386ULL: goto x86_l_1cda;
	case 7390ULL: goto x86_l_1cde;
	case 7393ULL: goto x86_l_1ce1;
	case 7396ULL: goto x86_l_1ce4;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7413ULL: goto x86_l_1cf5;
	case 7416ULL: goto x86_l_1cf8;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7465ULL: goto x86_l_1d29;
	case 7468ULL: goto x86_l_1d2c;
	case 7471ULL: goto x86_l_1d2f;
	case 7474ULL: goto x86_l_1d32;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7494ULL: goto x86_l_1d46;
	case 7497ULL: goto x86_l_1d49;
	case 7499ULL: goto x86_l_1d4b;
	case 7502ULL: goto x86_l_1d4e;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7517ULL: goto x86_l_1d5d;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7542ULL: goto x86_l_1d76;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7556ULL: goto x86_l_1d84;
	case 7563ULL: goto x86_l_1d8b;
	case 7571ULL: goto x86_l_1d93;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7623ULL: goto x86_l_1dc7;
	case 7627ULL: goto x86_l_1dcb;
	case 7634ULL: goto x86_l_1dd2;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7655ULL: goto x86_l_1de7;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7664ULL: goto x86_l_1df0;
	case 7667ULL: goto x86_l_1df3;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7693ULL: goto x86_l_1e0d;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7704ULL: goto x86_l_1e18;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7719ULL: goto x86_l_1e27;
	case 7723ULL: goto x86_l_1e2b;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7765ULL: goto x86_l_1e55;
	case 7768ULL: goto x86_l_1e58;
	case 7770ULL: goto x86_l_1e5a;
	case 7777ULL: goto x86_l_1e61;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7793ULL: goto x86_l_1e71;
	case 7798ULL: goto x86_l_1e76;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7829ULL: goto x86_l_1e95;
	case 7833ULL: goto x86_l_1e99;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7849ULL: goto x86_l_1ea9;
	case 7857ULL: goto x86_l_1eb1;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7882ULL: goto x86_l_1eca;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7899ULL: goto x86_l_1edb;
	case 7906ULL: goto x86_l_1ee2;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7920ULL: goto x86_l_1ef0;
	case 7927ULL: goto x86_l_1ef7;
	case 7934ULL: goto x86_l_1efe;
	case 7938ULL: goto x86_l_1f02;
	case 7945ULL: goto x86_l_1f09;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7973ULL: goto x86_l_1f25;
	case 7976ULL: goto x86_l_1f28;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7996ULL: goto x86_l_1f3c;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8005ULL: goto x86_l_1f45;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8053ULL: goto x86_l_1f75;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8067ULL: goto x86_l_1f83;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8085ULL: goto x86_l_1f95;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8109ULL: goto x86_l_1fad;
	case 8113ULL: goto x86_l_1fb1;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8163ULL: goto x86_l_1fe3;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8178ULL: goto x86_l_1ff2;
	case 8185ULL: goto x86_l_1ff9;
	case 8189ULL: goto x86_l_1ffd;
	case 8196ULL: goto x86_l_2004;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8221ULL: goto x86_l_201d;
	case 8224ULL: goto x86_l_2020;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8235ULL: goto x86_l_202b;
	case 8238ULL: goto x86_l_202e;
	case 8240ULL: goto x86_l_2030;
	case 8243ULL: goto x86_l_2033;
	case 8247ULL: goto x86_l_2037;
	case 8250ULL: goto x86_l_203a;
	case 8252ULL: goto x86_l_203c;
	case 8254ULL: goto x86_l_203e;
	case 8257ULL: goto x86_l_2041;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8274ULL: goto x86_l_2052;
	case 8280ULL: goto x86_l_2058;
	case 8287ULL: goto x86_l_205f;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8311ULL: goto x86_l_2077;
	case 8315ULL: goto x86_l_207b;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8333ULL: goto x86_l_208d;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8345ULL: goto x86_l_2099;
	case 8349ULL: goto x86_l_209d;
	case 8353ULL: goto x86_l_20a1;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8381ULL: goto x86_l_20bd;
	case 8384ULL: goto x86_l_20c0;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8401ULL: goto x86_l_20d1;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8415ULL: goto x86_l_20df;
	case 8422ULL: goto x86_l_20e6;
	case 8426ULL: goto x86_l_20ea;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8446ULL: goto x86_l_20fe;
	case 8453ULL: goto x86_l_2105;
	case 8456ULL: goto x86_l_2108;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8465ULL: goto x86_l_2111;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8477ULL: goto x86_l_211d;
	case 8480ULL: goto x86_l_2120;
	case 8484ULL: goto x86_l_2124;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ae4:
	/* 0x1ae4: mov    BYTE PTR [rax],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ae7:
	/* 0x1ae7: cmp    QWORD PTR [r14+0x7e70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139019501436928ULL);
x86_l_1aef:
	/* 0x1aef: je     1b51 <tracepoint__sched__sched_process_fork+0x1b51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b51;
	}
x86_l_1af1:
	/* 0x1af1: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1af6:
	/* 0x1af6: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1afe:
	/* 0x1afe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1b05:
	/* 0x1b05: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b12:
	/* 0x1b12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b14:
	/* 0x1b14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b17:
	/* 0x1b17: je     1b51 <tracepoint__sched__sched_process_fork+0x1b51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b51;
	}
x86_l_1b19:
	/* 0x1b19: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1b1c:
	/* 0x1b1c: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b29:
	/* 0x1b29: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b2c:
	/* 0x1b2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2e:
	/* 0x1b2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b31:
	/* 0x1b31: je     1b51 <tracepoint__sched__sched_process_fork+0x1b51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b51;
	}
x86_l_1b33:
	/* 0x1b33: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b36:
	/* 0x1b36: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b38:
	/* 0x1b38: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1b40:
	/* 0x1b40: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b45:
	/* 0x1b45: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b4a:
	/* 0x1b4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4c:
	/* 0x1b4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b4f:
	/* 0x1b4f: js     1b77 <tracepoint__sched__sched_process_fork+0x1b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b77;
	}
x86_l_1b51:
	/* 0x1b51: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b55:
	/* 0x1b55: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b5a:
	/* 0x1b5a: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1b5c:
	/* 0x1b5c: jne    1cba <tracepoint__sched__sched_process_fork+0x1cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cba;
	}
x86_l_1b62:
	/* 0x1b62: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b65:
	/* 0x1b65: and    QWORD PTR [r14+0x80],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1b6c:
	/* 0x1b6c: jne    242a <tracepoint__sched__sched_process_fork+0x242a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9258ULL;
	}
x86_l_1b72:
	/* 0x1b72: jmp    3441 <tracepoint__sched__sched_process_fork+0x3441> */
	return 13377ULL;
x86_l_1b77:
	/* 0x1b77: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b7a:
	/* 0x1b7a: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b82:
	/* 0x1b82: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_1b89:
	/* 0x1b89: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b93:
	/* 0x1b93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b95:
	/* 0x1b95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b98:
	/* 0x1b98: je     1ca1 <tracepoint__sched__sched_process_fork+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca1;
	}
x86_l_1b9e:
	/* 0x1b9e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1ba1:
	/* 0x1ba1: movabs rax,0xffffffff00000003 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744069414584323ULL);
x86_l_1bab:
	/* 0x1bab: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bae:
	/* 0x1bae: mov    QWORD PTR [r15+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_1bba:
	/* 0x1bba: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1bbe:
	/* 0x1bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc0:
	/* 0x1bc0: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    DWORD PTR [r15+0x1c],0x2b6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084982ULL);
x86_l_1bcc:
	/* 0x1bcc: movabs rax,0x702f656563617274 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8083791342286762612ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    QWORD PTR [r15+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bda:
	/* 0x1bda: movabs rax,0x2f667062652f676b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3415540935313811307ULL);
x86_l_1be4:
	/* 0x1be4: mov    QWORD PTR [r15+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1be8:
	/* 0x1be8: movabs rax,0x6565636172742f63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306355240661692259ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    QWORD PTR [r15+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bf6:
	/* 0x1bf6: movabs rax,0x632e6670622e6565 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7146762291553133925ULL);
x86_l_1c00:
	/* 0x1c00: mov    QWORD PTR [r15+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1c04:
	/* 0x1c04: mov    BYTE PTR [r15+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_1c09:
	/* 0x1c09: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c11:
	/* 0x1c11: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c21:
	/* 0x1c21: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1c26:
	/* 0x1c26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c28:
	/* 0x1c28: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c2d:
	/* 0x1c2d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_1c34:
	/* 0x1c34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c39:
	/* 0x1c39: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c3c:
	/* 0x1c3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3e:
	/* 0x1c3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c41:
	/* 0x1c41: je     3806 <tracepoint__sched__sched_process_fork+0x3806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14342ULL;
	}
x86_l_1c47:
	/* 0x1c47: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c4b:
	/* 0x1c4b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c52:
	/* 0x1c52: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c56:
	/* 0x1c56: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1c59:
	/* 0x1c59: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1c5c:
	/* 0x1c5c: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_1c63:
	/* 0x1c63: jb     1ca1 <tracepoint__sched__sched_process_fork+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ca1;
	}
x86_l_1c65:
	/* 0x1c65: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c68:
	/* 0x1c68: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_1c73:
	/* 0x1c73: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c78:
	/* 0x1c78: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1c82:
	/* 0x1c82: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_1c95:
	/* 0x1c95: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cad:
	/* 0x1cad: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1cb2:
	/* 0x1cb2: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: je     1b62 <tracepoint__sched__sched_process_fork+0x1b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b62;
	}
x86_l_1cba:
	/* 0x1cba: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_1cc1:
	/* 0x1cc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc4:
	/* 0x1cc4: je     1e5a <tracepoint__sched__sched_process_fork+0x1e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5a;
	}
x86_l_1cca:
	/* 0x1cca: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_1cd1:
	/* 0x1cd1: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1cd4:
	/* 0x1cd4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cd7:
	/* 0x1cd7: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1cda:
	/* 0x1cda: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_1cde:
	/* 0x1cde: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ce1:
	/* 0x1ce1: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1ce4:
	/* 0x1ce4: xor    r13,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_1ceb:
	/* 0x1ceb: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cee:
	/* 0x1cee: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1cf5:
	/* 0x1cf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cf8:
	/* 0x1cf8: je     1d19 <tracepoint__sched__sched_process_fork+0x1d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d19;
	}
x86_l_1cfa:
	/* 0x1cfa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfc:
	/* 0x1cfc: cmp    BYTE PTR [rbx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1d03:
	/* 0x1d03: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1d06:
	/* 0x1d06: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d09:
	/* 0x1d09: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1d0c:
	/* 0x1d0c: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1d13:
	/* 0x1d13: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d16:
	/* 0x1d16: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d19:
	/* 0x1d19: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_1d20:
	/* 0x1d20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: je     1d3f <tracepoint__sched__sched_process_fork+0x1d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3f;
	}
x86_l_1d25:
	/* 0x1d25: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1d29:
	/* 0x1d29: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d2c:
	/* 0x1d2c: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1d2f:
	/* 0x1d2f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1d32:
	/* 0x1d32: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_1d39:
	/* 0x1d39: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d3c:
	/* 0x1d3c: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d3f:
	/* 0x1d3f: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_1d46:
	/* 0x1d46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d49:
	/* 0x1d49: je     1d6a <tracepoint__sched__sched_process_fork+0x1d6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6a;
	}
x86_l_1d4b:
	/* 0x1d4b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d4e:
	/* 0x1d4e: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1d56:
	/* 0x1d56: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d5a:
	/* 0x1d5a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1d5d:
	/* 0x1d5d: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1d64:
	/* 0x1d64: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d67:
	/* 0x1d67: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d6a:
	/* 0x1d6a: movzx  ebp,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_1d76:
	/* 0x1d76: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1d79:
	/* 0x1d79: mov    WORD PTR [rsp+0x60],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d7e:
	/* 0x1d7e: je     1ec2 <tracepoint__sched__sched_process_fork+0x1ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec2;
	}
x86_l_1d84:
	/* 0x1d84: mov    rax,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d93:
	/* 0x1d93: mov    rax,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_1da6:
	/* 0x1da6: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1dab:
	/* 0x1dab: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1daf:
	/* 0x1daf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_1db6:
	/* 0x1db6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1db9:
	/* 0x1db9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dbe:
	/* 0x1dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc0:
	/* 0x1dc0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1dc3:
	/* 0x1dc3: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcb:
	/* 0x1dcb: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1dd2:
	/* 0x1dd2: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1dd5:
	/* 0x1dd5: je     1df5 <tracepoint__sched__sched_process_fork+0x1df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df5;
	}
x86_l_1dd7:
	/* 0x1dd7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1dda:
	/* 0x1dda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1de2:
	/* 0x1de2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de4:
	/* 0x1de4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1de7:
	/* 0x1de7: je     1df5 <tracepoint__sched__sched_process_fork+0x1df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df5;
	}
x86_l_1de9:
	/* 0x1de9: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dec:
	/* 0x1dec: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df0:
	/* 0x1df0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1df3:
	/* 0x1df3: jmp    1df7 <tracepoint__sched__sched_process_fork+0x1df7> */
	goto x86_l_1df7;
x86_l_1df5:
	/* 0x1df5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df7:
	/* 0x1df7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1dfc:
	/* 0x1dfc: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e01:
	/* 0x1e01: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e05:
	/* 0x1e05: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1e08:
	/* 0x1e08: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1e0b:
	/* 0x1e0b: jb     1e23 <tracepoint__sched__sched_process_fork+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1e23;
	}
x86_l_1e0d:
	/* 0x1e0d: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1e11:
	/* 0x1e11: je     1e18 <tracepoint__sched__sched_process_fork+0x1e18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e18;
	}
x86_l_1e13:
	/* 0x1e13: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1e16:
	/* 0x1e16: jbe    1e23 <tracepoint__sched__sched_process_fork+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e23;
	}
x86_l_1e18:
	/* 0x1e18: and    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_1e20:
	/* 0x1e20: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e23:
	/* 0x1e23: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e27:
	/* 0x1e27: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e2b:
	/* 0x1e2b: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1e32:
	/* 0x1e32: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1e35:
	/* 0x1e35: je     1e76 <tracepoint__sched__sched_process_fork+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e76;
	}
x86_l_1e37:
	/* 0x1e37: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1e3f:
	/* 0x1e3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e44:
	/* 0x1e44: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e47:
	/* 0x1e47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e49:
	/* 0x1e49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e4c:
	/* 0x1e4c: je     1e86 <tracepoint__sched__sched_process_fork+0x1e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e86;
	}
x86_l_1e4e:
	/* 0x1e4e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e51:
	/* 0x1e51: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e55:
	/* 0x1e55: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e58:
	/* 0x1e58: jmp    1e88 <tracepoint__sched__sched_process_fork+0x1e88> */
	goto x86_l_1e88;
x86_l_1e5a:
	/* 0x1e5a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1e61:
	/* 0x1e61: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1e68:
	/* 0x1e68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e6b:
	/* 0x1e6b: jne    1cfa <tracepoint__sched__sched_process_fork+0x1cfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cfa;
	}
x86_l_1e71:
	/* 0x1e71: jmp    1d19 <tracepoint__sched__sched_process_fork+0x1d19> */
	goto x86_l_1d19;
x86_l_1e76:
	/* 0x1e76: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e78:
	/* 0x1e78: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e7b:
	/* 0x1e7b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e7f:
	/* 0x1e7f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1e82:
	/* 0x1e82: jae    1e9e <tracepoint__sched__sched_process_fork+0x1e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e9e;
	}
x86_l_1e84:
	/* 0x1e84: jmp    1eb4 <tracepoint__sched__sched_process_fork+0x1eb4> */
	goto x86_l_1eb4;
x86_l_1e86:
	/* 0x1e86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e88:
	/* 0x1e88: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e8d:
	/* 0x1e8d: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e92:
	/* 0x1e92: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e95:
	/* 0x1e95: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e99:
	/* 0x1e99: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1e9c:
	/* 0x1e9c: jb     1eb4 <tracepoint__sched__sched_process_fork+0x1eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1eb4;
	}
x86_l_1e9e:
	/* 0x1e9e: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ea2:
	/* 0x1ea2: je     1ea9 <tracepoint__sched__sched_process_fork+0x1ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ea9;
	}
x86_l_1ea4:
	/* 0x1ea4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1ea7:
	/* 0x1ea7: jbe    1eb4 <tracepoint__sched__sched_process_fork+0x1eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1eb4;
	}
x86_l_1ea9:
	/* 0x1ea9: and    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_1eb1:
	/* 0x1eb1: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1eb4:
	/* 0x1eb4: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_1eb7:
	/* 0x1eb7: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1eba:
	/* 0x1eba: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1ebd:
	/* 0x1ebd: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1ec2:
	/* 0x1ec2: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1eca:
	/* 0x1eca: je     1f7b <tracepoint__sched__sched_process_fork+0x1f7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f7b;
	}
x86_l_1ed0:
	/* 0x1ed0: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1ed5:
	/* 0x1ed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed7:
	/* 0x1ed7: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1edb:
	/* 0x1edb: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1eee:
	/* 0x1eee: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1ef0:
	/* 0x1ef0: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_1ef7:
	/* 0x1ef7: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_1efe:
	/* 0x1efe: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f02:
	/* 0x1f02: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_1f09:
	/* 0x1f09: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1f0c:
	/* 0x1f0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f11:
	/* 0x1f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f13:
	/* 0x1f13: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f16:
	/* 0x1f16: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f25:
	/* 0x1f25: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_1f28:
	/* 0x1f28: je     1f45 <tracepoint__sched__sched_process_fork+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f45;
	}
x86_l_1f2a:
	/* 0x1f2a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1f2d:
	/* 0x1f2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f32:
	/* 0x1f32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f34:
	/* 0x1f34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f37:
	/* 0x1f37: je     1f45 <tracepoint__sched__sched_process_fork+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f45;
	}
x86_l_1f39:
	/* 0x1f39: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f40:
	/* 0x1f40: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f43:
	/* 0x1f43: jmp    1f47 <tracepoint__sched__sched_process_fork+0x1f47> */
	goto x86_l_1f47;
x86_l_1f45:
	/* 0x1f45: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f47:
	/* 0x1f47: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f4a:
	/* 0x1f4a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4e:
	/* 0x1f4e: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1f51:
	/* 0x1f51: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1f54:
	/* 0x1f54: jae    1f5d <tracepoint__sched__sched_process_fork+0x1f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f5d;
	}
x86_l_1f56:
	/* 0x1f56: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1f5b:
	/* 0x1f5b: jmp    1f75 <tracepoint__sched__sched_process_fork+0x1f75> */
	goto x86_l_1f75;
x86_l_1f5d:
	/* 0x1f5d: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f61:
	/* 0x1f61: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1f66:
	/* 0x1f66: je     1f6d <tracepoint__sched__sched_process_fork+0x1f6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6d;
	}
x86_l_1f68:
	/* 0x1f68: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1f6b:
	/* 0x1f6b: jbe    1f75 <tracepoint__sched__sched_process_fork+0x1f75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f75;
	}
x86_l_1f6d:
	/* 0x1f6d: and    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 88ULL);
x86_l_1f72:
	/* 0x1f72: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f75:
	/* 0x1f75: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f78:
	/* 0x1f78: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f7b:
	/* 0x1f7b: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1f83:
	/* 0x1f83: je     204a <tracepoint__sched__sched_process_fork+0x204a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204a;
	}
x86_l_1f89:
	/* 0x1f89: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1f8e:
	/* 0x1f8e: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1f95:
	/* 0x1f95: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f98:
	/* 0x1f98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa2:
	/* 0x1fa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa7:
	/* 0x1fa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa9:
	/* 0x1fa9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fad:
	/* 0x1fad: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fb4:
	/* 0x1fb4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fc3:
	/* 0x1fc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc5:
	/* 0x1fc5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc9:
	/* 0x1fc9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fce:
	/* 0x1fce: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fe1:
	/* 0x1fe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe3:
	/* 0x1fe3: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1feb:
	/* 0x1feb: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_2004:
	/* 0x2004: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2007:
	/* 0x2007: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_200c:
	/* 0x200c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_200f:
	/* 0x200f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2011:
	/* 0x2011: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2018:
	/* 0x2018: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_201b:
	/* 0x201b: je     203c <tracepoint__sched__sched_process_fork+0x203c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203c;
	}
x86_l_201d:
	/* 0x201d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2020:
	/* 0x2020: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2024:
	/* 0x2024: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2029:
	/* 0x2029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202b:
	/* 0x202b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_202e:
	/* 0x202e: je     203c <tracepoint__sched__sched_process_fork+0x203c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203c;
	}
x86_l_2030:
	/* 0x2030: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2033:
	/* 0x2033: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2037:
	/* 0x2037: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_203a:
	/* 0x203a: jmp    203e <tracepoint__sched__sched_process_fork+0x203e> */
	goto x86_l_203e;
x86_l_203c:
	/* 0x203c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203e:
	/* 0x203e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2041:
	/* 0x2041: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2044:
	/* 0x2044: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2047:
	/* 0x2047: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_204a:
	/* 0x204a: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_2052:
	/* 0x2052: je     2137 <tracepoint__sched__sched_process_fork+0x2137> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8503ULL;
	}
x86_l_2058:
	/* 0x2058: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_205f:
	/* 0x205f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2063:
	/* 0x2063: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_206b:
	/* 0x206b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2070:
	/* 0x2070: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2075:
	/* 0x2075: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2077:
	/* 0x2077: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207b:
	/* 0x207b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_207e:
	/* 0x207e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2083:
	/* 0x2083: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2088:
	/* 0x2088: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_208d:
	/* 0x208d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2090:
	/* 0x2090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2092:
	/* 0x2092: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2095:
	/* 0x2095: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2099:
	/* 0x2099: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_209d:
	/* 0x209d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20a1:
	/* 0x20a1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a4:
	/* 0x20a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20a9:
	/* 0x20a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ae:
	/* 0x20ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b3:
	/* 0x20b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b5:
	/* 0x20b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b9:
	/* 0x20b9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_20bd:
	/* 0x20bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20c0:
	/* 0x20c0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20c5:
	/* 0x20c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ca:
	/* 0x20ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20cf:
	/* 0x20cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d1:
	/* 0x20d1: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d4:
	/* 0x20d4: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20d8:
	/* 0x20d8: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_20df:
	/* 0x20df: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_20e6:
	/* 0x20e6: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ea:
	/* 0x20ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_20f1:
	/* 0x20f1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_20f4:
	/* 0x20f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20f9:
	/* 0x20f9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_20fc:
	/* 0x20fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fe:
	/* 0x20fe: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2105:
	/* 0x2105: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2108:
	/* 0x2108: je     2129 <tracepoint__sched__sched_process_fork+0x2129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8489ULL;
	}
x86_l_210a:
	/* 0x210a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_210d:
	/* 0x210d: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2111:
	/* 0x2111: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2116:
	/* 0x2116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2118:
	/* 0x2118: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211b:
	/* 0x211b: je     2129 <tracepoint__sched__sched_process_fork+0x2129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8489ULL;
	}
x86_l_211d:
	/* 0x211d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2120:
	/* 0x2120: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2124:
	/* 0x2124: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
	return 8487ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8511ULL: goto x86_l_213f;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8529ULL: goto x86_l_2151;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8547ULL: goto x86_l_2163;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8577ULL: goto x86_l_2181;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8590ULL: goto x86_l_218e;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8625ULL: goto x86_l_21b1;
	case 8627ULL: goto x86_l_21b3;
	case 8634ULL: goto x86_l_21ba;
	case 8641ULL: goto x86_l_21c1;
	case 8645ULL: goto x86_l_21c5;
	case 8652ULL: goto x86_l_21cc;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8702ULL: goto x86_l_21fe;
	case 8705ULL: goto x86_l_2201;
	case 8707ULL: goto x86_l_2203;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8760ULL: goto x86_l_2238;
	case 8767ULL: goto x86_l_223f;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8821ULL: goto x86_l_2275;
	case 8823ULL: goto x86_l_2277;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8851ULL: goto x86_l_2293;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8875ULL: goto x86_l_22ab;
	case 8878ULL: goto x86_l_22ae;
	case 8885ULL: goto x86_l_22b5;
	case 8890ULL: goto x86_l_22ba;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8910ULL: goto x86_l_22ce;
	case 8912ULL: goto x86_l_22d0;
	case 8919ULL: goto x86_l_22d7;
	case 8922ULL: goto x86_l_22da;
	case 8924ULL: goto x86_l_22dc;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8949ULL: goto x86_l_22f5;
	case 8952ULL: goto x86_l_22f8;
	case 8954ULL: goto x86_l_22fa;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8968ULL: goto x86_l_2308;
	case 8975ULL: goto x86_l_230f;
	case 8978ULL: goto x86_l_2312;
	case 8980ULL: goto x86_l_2314;
	case 8987ULL: goto x86_l_231b;
	case 8991ULL: goto x86_l_231f;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9018ULL: goto x86_l_233a;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9043ULL: goto x86_l_2353;
	case 9046ULL: goto x86_l_2356;
	case 9050ULL: goto x86_l_235a;
	case 9053ULL: goto x86_l_235d;
	case 9055ULL: goto x86_l_235f;
	case 9057ULL: goto x86_l_2361;
	case 9060ULL: goto x86_l_2364;
	case 9063ULL: goto x86_l_2367;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9085ULL: goto x86_l_237d;
	case 9092ULL: goto x86_l_2384;
	case 9096ULL: goto x86_l_2388;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9114ULL: goto x86_l_239a;
	case 9116ULL: goto x86_l_239c;
	case 9123ULL: goto x86_l_23a3;
	case 9126ULL: goto x86_l_23a6;
	case 9128ULL: goto x86_l_23a8;
	case 9131ULL: goto x86_l_23ab;
	case 9139ULL: goto x86_l_23b3;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9153ULL: goto x86_l_23c1;
	case 9156ULL: goto x86_l_23c4;
	case 9158ULL: goto x86_l_23c6;
	case 9166ULL: goto x86_l_23ce;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9178ULL: goto x86_l_23da;
	case 9180ULL: goto x86_l_23dc;
	case 9183ULL: goto x86_l_23df;
	case 9185ULL: goto x86_l_23e1;
	case 9188ULL: goto x86_l_23e4;
	case 9192ULL: goto x86_l_23e8;
	case 9195ULL: goto x86_l_23eb;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9202ULL: goto x86_l_23f2;
	case 9205ULL: goto x86_l_23f5;
	case 9208ULL: goto x86_l_23f8;
	case 9211ULL: goto x86_l_23fb;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9238ULL: goto x86_l_2416;
	case 9245ULL: goto x86_l_241d;
	case 9252ULL: goto x86_l_2424;
	case 9258ULL: goto x86_l_242a;
	case 9266ULL: goto x86_l_2432;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9326ULL: goto x86_l_246e;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9357ULL: goto x86_l_248d;
	case 9361ULL: goto x86_l_2491;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9385ULL: goto x86_l_24a9;
	case 9389ULL: goto x86_l_24ad;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9427ULL: goto x86_l_24d3;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9450ULL: goto x86_l_24ea;
	case 9457ULL: goto x86_l_24f1;
	case 9461ULL: goto x86_l_24f5;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9488ULL: goto x86_l_2510;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9511ULL: goto x86_l_2527;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9549ULL: goto x86_l_254d;
	case 9556ULL: goto x86_l_2554;
	case 9564ULL: goto x86_l_255c;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9582ULL: goto x86_l_256e;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9594ULL: goto x86_l_257a;
	case 9601ULL: goto x86_l_2581;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9626ULL: goto x86_l_259a;
	case 9629ULL: goto x86_l_259d;
	case 9631ULL: goto x86_l_259f;
	case 9634ULL: goto x86_l_25a2;
	case 9642ULL: goto x86_l_25aa;
	case 9649ULL: goto x86_l_25b1;
	case 9657ULL: goto x86_l_25b9;
	case 9664ULL: goto x86_l_25c0;
	case 9672ULL: goto x86_l_25c8;
	case 9674ULL: goto x86_l_25ca;
	case 9683ULL: goto x86_l_25d3;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9702ULL: goto x86_l_25e6;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9727ULL: goto x86_l_25ff;
	case 9730ULL: goto x86_l_2602;
	case 9732ULL: goto x86_l_2604;
	case 9735ULL: goto x86_l_2607;
	case 9743ULL: goto x86_l_260f;
	case 9750ULL: goto x86_l_2616;
	case 9758ULL: goto x86_l_261e;
	case 9765ULL: goto x86_l_2625;
	case 9767ULL: goto x86_l_2627;
	case 9776ULL: goto x86_l_2630;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9788ULL: goto x86_l_263c;
	case 9795ULL: goto x86_l_2643;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9820ULL: goto x86_l_265c;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9836ULL: goto x86_l_266c;
	case 9843ULL: goto x86_l_2673;
	case 9851ULL: goto x86_l_267b;
	case 9858ULL: goto x86_l_2682;
	case 9860ULL: goto x86_l_2684;
	case 9869ULL: goto x86_l_268d;
	case 9875ULL: goto x86_l_2693;
	case 9877ULL: goto x86_l_2695;
	case 9881ULL: goto x86_l_2699;
	case 9888ULL: goto x86_l_26a0;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9913ULL: goto x86_l_26b9;
	case 9916ULL: goto x86_l_26bc;
	case 9918ULL: goto x86_l_26be;
	case 9921ULL: goto x86_l_26c1;
	case 9929ULL: goto x86_l_26c9;
	case 9936ULL: goto x86_l_26d0;
	case 9944ULL: goto x86_l_26d8;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9962ULL: goto x86_l_26ea;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9974ULL: goto x86_l_26f6;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10011ULL: goto x86_l_271b;
	case 10019ULL: goto x86_l_2723;
	case 10026ULL: goto x86_l_272a;
	case 10034ULL: goto x86_l_2732;
	case 10041ULL: goto x86_l_2739;
	case 10043ULL: goto x86_l_273b;
	case 10052ULL: goto x86_l_2744;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10064ULL: goto x86_l_2750;
	case 10071ULL: goto x86_l_2757;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10096ULL: goto x86_l_2770;
	case 10099ULL: goto x86_l_2773;
	case 10101ULL: goto x86_l_2775;
	case 10104ULL: goto x86_l_2778;
	case 10112ULL: goto x86_l_2780;
	case 10119ULL: goto x86_l_2787;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2127:
	/* 0x2127: jmp    212b <tracepoint__sched__sched_process_fork+0x212b> */
	goto x86_l_212b;
x86_l_2129:
	/* 0x2129: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_212b:
	/* 0x212b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_212e:
	/* 0x212e: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2131:
	/* 0x2131: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2134:
	/* 0x2134: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2137:
	/* 0x2137: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_213f:
	/* 0x213f: je     2216 <tracepoint__sched__sched_process_fork+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2216;
	}
x86_l_2145:
	/* 0x2145: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_214a:
	/* 0x214a: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2151:
	/* 0x2151: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2154:
	/* 0x2154: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2159:
	/* 0x2159: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215e:
	/* 0x215e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2163:
	/* 0x2163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2165:
	/* 0x2165: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2169:
	/* 0x2169: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_216c:
	/* 0x216c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2171:
	/* 0x2171: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2176:
	/* 0x2176: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_217b:
	/* 0x217b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217d:
	/* 0x217d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2181:
	/* 0x2181: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_2184:
	/* 0x2184: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2189:
	/* 0x2189: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_218e:
	/* 0x218e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2191:
	/* 0x2191: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2196:
	/* 0x2196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2198:
	/* 0x2198: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_219c:
	/* 0x219c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21a1:
	/* 0x21a1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_21a6:
	/* 0x21a6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_21a9:
	/* 0x21a9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21ae:
	/* 0x21ae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21b1:
	/* 0x21b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b3:
	/* 0x21b3: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_21ba:
	/* 0x21ba: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_21c1:
	/* 0x21c1: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c5:
	/* 0x21c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_21cc:
	/* 0x21cc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_21cf:
	/* 0x21cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d4:
	/* 0x21d4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_21d7:
	/* 0x21d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d9:
	/* 0x21d9: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_21e0:
	/* 0x21e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21e3:
	/* 0x21e3: je     2203 <tracepoint__sched__sched_process_fork+0x2203> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2203;
	}
x86_l_21e5:
	/* 0x21e5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_21e8:
	/* 0x21e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21ed:
	/* 0x21ed: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_21f0:
	/* 0x21f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f2:
	/* 0x21f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21f5:
	/* 0x21f5: je     2203 <tracepoint__sched__sched_process_fork+0x2203> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2203;
	}
x86_l_21f7:
	/* 0x21f7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21fa:
	/* 0x21fa: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fe:
	/* 0x21fe: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2201:
	/* 0x2201: jmp    2205 <tracepoint__sched__sched_process_fork+0x2205> */
	goto x86_l_2205;
x86_l_2203:
	/* 0x2203: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2205:
	/* 0x2205: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2208:
	/* 0x2208: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_220b:
	/* 0x220b: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_220e:
	/* 0x220e: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2211:
	/* 0x2211: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_2216:
	/* 0x2216: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_221e:
	/* 0x221e: je     229b <tracepoint__sched__sched_process_fork+0x229b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229b;
	}
x86_l_2220:
	/* 0x2220: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2224:
	/* 0x2224: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2229:
	/* 0x2229: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_222e:
	/* 0x222e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2231:
	/* 0x2231: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2236:
	/* 0x2236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2238:
	/* 0x2238: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_223f:
	/* 0x223f: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_2246:
	/* 0x2246: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_224a:
	/* 0x224a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_2251:
	/* 0x2251: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2254:
	/* 0x2254: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2259:
	/* 0x2259: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_225c:
	/* 0x225c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225e:
	/* 0x225e: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2265:
	/* 0x2265: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2268:
	/* 0x2268: je     2288 <tracepoint__sched__sched_process_fork+0x2288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2288;
	}
x86_l_226a:
	/* 0x226a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_226d:
	/* 0x226d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2272:
	/* 0x2272: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2275:
	/* 0x2275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2277:
	/* 0x2277: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_227a:
	/* 0x227a: je     2288 <tracepoint__sched__sched_process_fork+0x2288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2288;
	}
x86_l_227c:
	/* 0x227c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227f:
	/* 0x227f: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2283:
	/* 0x2283: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2286:
	/* 0x2286: jmp    228a <tracepoint__sched__sched_process_fork+0x228a> */
	goto x86_l_228a;
x86_l_2288:
	/* 0x2288: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228a:
	/* 0x228a: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_228d:
	/* 0x228d: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2290:
	/* 0x2290: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2293:
	/* 0x2293: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2296:
	/* 0x2296: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_229b:
	/* 0x229b: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_22a2:
	/* 0x22a2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_22a5:
	/* 0x22a5: je     2308 <tracepoint__sched__sched_process_fork+0x2308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2308;
	}
x86_l_22a7:
	/* 0x22a7: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ab:
	/* 0x22ab: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ae:
	/* 0x22ae: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_22b5:
	/* 0x22b5: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22ba:
	/* 0x22ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_22c1:
	/* 0x22c1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22c6:
	/* 0x22c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22cb:
	/* 0x22cb: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22ce:
	/* 0x22ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d0:
	/* 0x22d0: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_22d7:
	/* 0x22d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22da:
	/* 0x22da: je     22fa <tracepoint__sched__sched_process_fork+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fa;
	}
x86_l_22dc:
	/* 0x22dc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22df:
	/* 0x22df: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_22e2:
	/* 0x22e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22e7:
	/* 0x22e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e9:
	/* 0x22e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ec:
	/* 0x22ec: je     22fa <tracepoint__sched__sched_process_fork+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fa;
	}
x86_l_22ee:
	/* 0x22ee: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f1:
	/* 0x22f1: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f5:
	/* 0x22f5: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22f8:
	/* 0x22f8: jmp    22fc <tracepoint__sched__sched_process_fork+0x22fc> */
	goto x86_l_22fc;
x86_l_22fa:
	/* 0x22fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22fc:
	/* 0x22fc: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22ff:
	/* 0x22ff: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2302:
	/* 0x2302: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2305:
	/* 0x2305: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2308:
	/* 0x2308: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_230f:
	/* 0x230f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2312:
	/* 0x2312: je     236d <tracepoint__sched__sched_process_fork+0x236d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_236d;
	}
x86_l_2314:
	/* 0x2314: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_231b:
	/* 0x231b: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231f:
	/* 0x231f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_2326:
	/* 0x2326: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2329:
	/* 0x2329: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_232e:
	/* 0x232e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2331:
	/* 0x2331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2333:
	/* 0x2333: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_233a:
	/* 0x233a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_233d:
	/* 0x233d: je     235f <tracepoint__sched__sched_process_fork+0x235f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235f;
	}
x86_l_233f:
	/* 0x233f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2342:
	/* 0x2342: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2347:
	/* 0x2347: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_234c:
	/* 0x234c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234e:
	/* 0x234e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2351:
	/* 0x2351: je     235f <tracepoint__sched__sched_process_fork+0x235f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235f;
	}
x86_l_2353:
	/* 0x2353: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2356:
	/* 0x2356: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235a:
	/* 0x235a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_235d:
	/* 0x235d: jmp    2361 <tracepoint__sched__sched_process_fork+0x2361> */
	goto x86_l_2361;
x86_l_235f:
	/* 0x235f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2361:
	/* 0x2361: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2364:
	/* 0x2364: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2367:
	/* 0x2367: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_236a:
	/* 0x236a: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_236d:
	/* 0x236d: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_2374:
	/* 0x2374: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2377:
	/* 0x2377: je     23fb <tracepoint__sched__sched_process_fork+0x23fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fb;
	}
x86_l_237d:
	/* 0x237d: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_2384:
	/* 0x2384: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2388:
	/* 0x2388: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_238f:
	/* 0x238f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2392:
	/* 0x2392: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2397:
	/* 0x2397: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_239a:
	/* 0x239a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_239c:
	/* 0x239c: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23a3:
	/* 0x23a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a6:
	/* 0x23a6: je     23ed <tracepoint__sched__sched_process_fork+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ed;
	}
x86_l_23a8:
	/* 0x23a8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_23ab:
	/* 0x23ab: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23b3:
	/* 0x23b3: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_23b7:
	/* 0x23b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23bc:
	/* 0x23bc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23bf:
	/* 0x23bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c1:
	/* 0x23c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23c4:
	/* 0x23c4: jne    23e1 <tracepoint__sched__sched_process_fork+0x23e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23e1;
	}
x86_l_23c6:
	/* 0x23c6: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23ce:
	/* 0x23ce: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d2:
	/* 0x23d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23d7:
	/* 0x23d7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23da:
	/* 0x23da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23dc:
	/* 0x23dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23df:
	/* 0x23df: je     23ed <tracepoint__sched__sched_process_fork+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ed;
	}
x86_l_23e1:
	/* 0x23e1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e4:
	/* 0x23e4: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e8:
	/* 0x23e8: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23eb:
	/* 0x23eb: jmp    23ef <tracepoint__sched__sched_process_fork+0x23ef> */
	goto x86_l_23ef;
x86_l_23ed:
	/* 0x23ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23ef:
	/* 0x23ef: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_23f2:
	/* 0x23f2: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_23f5:
	/* 0x23f5: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_23f8:
	/* 0x23f8: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_23fb:
	/* 0x23fb: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2402:
	/* 0x2402: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2405:
	/* 0x2405: je     2416 <tracepoint__sched__sched_process_fork+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2416;
	}
x86_l_2407:
	/* 0x2407: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_240f:
	/* 0x240f: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_2413:
	/* 0x2413: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2416:
	/* 0x2416: and    r13,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_241d:
	/* 0x241d: and    QWORD PTR [r14+0x80],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_2424:
	/* 0x2424: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_242a:
	/* 0x242a: mov    r15,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2432:
	/* 0x2432: lea    rdx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2436:
	/* 0x2436: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2439:
	/* 0x2439: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_243e:
	/* 0x243e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2443:
	/* 0x2443: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2448:
	/* 0x2448: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244a:
	/* 0x244a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244e:
	/* 0x244e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2453:
	/* 0x2453: lea    rdx,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2457:
	/* 0x2457: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_245a:
	/* 0x245a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_245f:
	/* 0x245f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2464:
	/* 0x2464: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2469:
	/* 0x2469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246b:
	/* 0x246b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246e:
	/* 0x246e: mov    DWORD PTR [rsp+0xf8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2475:
	/* 0x2475: lea    rdx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2479:
	/* 0x2479: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_247c:
	/* 0x247c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2481:
	/* 0x2481: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2486:
	/* 0x2486: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_248b:
	/* 0x248b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248d:
	/* 0x248d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2491:
	/* 0x2491: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2495:
	/* 0x2495: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2498:
	/* 0x2498: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_249d:
	/* 0x249d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24a2:
	/* 0x24a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a7:
	/* 0x24a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a9:
	/* 0x24a9: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ad:
	/* 0x24ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24b0:
	/* 0x24b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_24b5:
	/* 0x24b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24ba:
	/* 0x24ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24bf:
	/* 0x24bf: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_24c2:
	/* 0x24c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c4:
	/* 0x24c4: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24c7:
	/* 0x24c7: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_24cb:
	/* 0x24cb: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_24cf:
	/* 0x24cf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24d3:
	/* 0x24d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24d6:
	/* 0x24d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_24db:
	/* 0x24db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24e0:
	/* 0x24e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24e5:
	/* 0x24e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e7:
	/* 0x24e7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ea:
	/* 0x24ea: mov    DWORD PTR [rsp+0xf4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_24f1:
	/* 0x24f1: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24f5:
	/* 0x24f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24f8:
	/* 0x24f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24fd:
	/* 0x24fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2502:
	/* 0x2502: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2507:
	/* 0x2507: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_250a:
	/* 0x250a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250c:
	/* 0x250c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2510:
	/* 0x2510: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2513:
	/* 0x2513: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2518:
	/* 0x2518: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_251d:
	/* 0x251d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2522:
	/* 0x2522: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2525:
	/* 0x2525: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2527:
	/* 0x2527: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252a:
	/* 0x252a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_252e:
	/* 0x252e: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2532:
	/* 0x2532: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2536:
	/* 0x2536: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2539:
	/* 0x2539: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_253e:
	/* 0x253e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2543:
	/* 0x2543: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2548:
	/* 0x2548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254a:
	/* 0x254a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_254d:
	/* 0x254d: mov    DWORD PTR [rsp+0xf0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2554:
	/* 0x2554: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_255c:
	/* 0x255c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2563:
	/* 0x2563: ja     25b1 <tracepoint__sched__sched_process_fork+0x25b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25b1;
	}
x86_l_2565:
	/* 0x2565: mov    BYTE PTR [r14+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_256e:
	/* 0x256e: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2574:
	/* 0x2574: ja     25b1 <tracepoint__sched__sched_process_fork+0x25b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25b1;
	}
x86_l_2576:
	/* 0x2576: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_257a:
	/* 0x257a: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2581:
	/* 0x2581: lea    rdx,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2589:
	/* 0x2589: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_258e:
	/* 0x258e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2593:
	/* 0x2593: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2598:
	/* 0x2598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259a:
	/* 0x259a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_259d:
	/* 0x259d: js     25b1 <tracepoint__sched__sched_process_fork+0x25b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25b1;
	}
x86_l_259f:
	/* 0x259f: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_25a2:
	/* 0x25a2: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25aa:
	/* 0x25aa: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_25b1:
	/* 0x25b1: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25b9:
	/* 0x25b9: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_25c0:
	/* 0x25c0: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_25c8:
	/* 0x25c8: ja     2616 <tracepoint__sched__sched_process_fork+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2616;
	}
x86_l_25ca:
	/* 0x25ca: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_25d3:
	/* 0x25d3: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_25d9:
	/* 0x25d9: ja     2616 <tracepoint__sched__sched_process_fork+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2616;
	}
x86_l_25db:
	/* 0x25db: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_25df:
	/* 0x25df: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_25e6:
	/* 0x25e6: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25ee:
	/* 0x25ee: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25f3:
	/* 0x25f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25f8:
	/* 0x25f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25fd:
	/* 0x25fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ff:
	/* 0x25ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2602:
	/* 0x2602: js     2616 <tracepoint__sched__sched_process_fork+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2616;
	}
x86_l_2604:
	/* 0x2604: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2607:
	/* 0x2607: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_260f:
	/* 0x260f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2616:
	/* 0x2616: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_261e:
	/* 0x261e: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2625:
	/* 0x2625: ja     2673 <tracepoint__sched__sched_process_fork+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2673;
	}
x86_l_2627:
	/* 0x2627: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_2630:
	/* 0x2630: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2636:
	/* 0x2636: ja     2673 <tracepoint__sched__sched_process_fork+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2673;
	}
x86_l_2638:
	/* 0x2638: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_263c:
	/* 0x263c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2643:
	/* 0x2643: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_264b:
	/* 0x264b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2650:
	/* 0x2650: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2655:
	/* 0x2655: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_265a:
	/* 0x265a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265c:
	/* 0x265c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_265f:
	/* 0x265f: js     2673 <tracepoint__sched__sched_process_fork+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2673;
	}
x86_l_2661:
	/* 0x2661: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2664:
	/* 0x2664: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_266c:
	/* 0x266c: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2673:
	/* 0x2673: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_267b:
	/* 0x267b: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2682:
	/* 0x2682: ja     26d0 <tracepoint__sched__sched_process_fork+0x26d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_26d0;
	}
x86_l_2684:
	/* 0x2684: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_268d:
	/* 0x268d: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2693:
	/* 0x2693: ja     26d0 <tracepoint__sched__sched_process_fork+0x26d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_26d0;
	}
x86_l_2695:
	/* 0x2695: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2699:
	/* 0x2699: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_26a0:
	/* 0x26a0: lea    rdx,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_26a8:
	/* 0x26a8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_26ad:
	/* 0x26ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b2:
	/* 0x26b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b7:
	/* 0x26b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b9:
	/* 0x26b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26bc:
	/* 0x26bc: js     26d0 <tracepoint__sched__sched_process_fork+0x26d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26d0;
	}
x86_l_26be:
	/* 0x26be: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_26c1:
	/* 0x26c1: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26c9:
	/* 0x26c9: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_26d0:
	/* 0x26d0: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26d8:
	/* 0x26d8: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_26df:
	/* 0x26df: ja     272a <tracepoint__sched__sched_process_fork+0x272a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_272a;
	}
x86_l_26e1:
	/* 0x26e1: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_26ea:
	/* 0x26ea: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_26f0:
	/* 0x26f0: ja     272a <tracepoint__sched__sched_process_fork+0x272a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_272a;
	}
x86_l_26f2:
	/* 0x26f2: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_26f6:
	/* 0x26f6: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_26fd:
	/* 0x26fd: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2702:
	/* 0x2702: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2707:
	/* 0x2707: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_270c:
	/* 0x270c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2711:
	/* 0x2711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2713:
	/* 0x2713: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2716:
	/* 0x2716: js     272a <tracepoint__sched__sched_process_fork+0x272a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272a;
	}
x86_l_2718:
	/* 0x2718: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_271b:
	/* 0x271b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2723:
	/* 0x2723: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_272a:
	/* 0x272a: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2732:
	/* 0x2732: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2739:
	/* 0x2739: ja     2787 <tracepoint__sched__sched_process_fork+0x2787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2787;
	}
x86_l_273b:
	/* 0x273b: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_2744:
	/* 0x2744: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_274a:
	/* 0x274a: ja     2787 <tracepoint__sched__sched_process_fork+0x2787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2787;
	}
x86_l_274c:
	/* 0x274c: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2750:
	/* 0x2750: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2757:
	/* 0x2757: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_275f:
	/* 0x275f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2764:
	/* 0x2764: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2769:
	/* 0x2769: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_276e:
	/* 0x276e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2770:
	/* 0x2770: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2773:
	/* 0x2773: js     2787 <tracepoint__sched__sched_process_fork+0x2787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2787;
	}
x86_l_2775:
	/* 0x2775: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2778:
	/* 0x2778: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2780:
	/* 0x2780: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2787:
	/* 0x2787: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
	return 10127ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10127ULL: goto x86_l_278f;
	case 10134ULL: goto x86_l_2796;
	case 10136ULL: goto x86_l_2798;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10153ULL: goto x86_l_27a9;
	case 10157ULL: goto x86_l_27ad;
	case 10164ULL: goto x86_l_27b4;
	case 10172ULL: goto x86_l_27bc;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10192ULL: goto x86_l_27d0;
	case 10194ULL: goto x86_l_27d2;
	case 10197ULL: goto x86_l_27d5;
	case 10205ULL: goto x86_l_27dd;
	case 10212ULL: goto x86_l_27e4;
	case 10220ULL: goto x86_l_27ec;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10238ULL: goto x86_l_27fe;
	case 10244ULL: goto x86_l_2804;
	case 10246ULL: goto x86_l_2806;
	case 10250ULL: goto x86_l_280a;
	case 10257ULL: goto x86_l_2811;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10290ULL: goto x86_l_2832;
	case 10298ULL: goto x86_l_283a;
	case 10305ULL: goto x86_l_2841;
	case 10313ULL: goto x86_l_2849;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10331ULL: goto x86_l_285b;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10343ULL: goto x86_l_2867;
	case 10350ULL: goto x86_l_286e;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10391ULL: goto x86_l_2897;
	case 10398ULL: goto x86_l_289e;
	case 10406ULL: goto x86_l_28a6;
	case 10413ULL: goto x86_l_28ad;
	case 10415ULL: goto x86_l_28af;
	case 10424ULL: goto x86_l_28b8;
	case 10430ULL: goto x86_l_28be;
	case 10432ULL: goto x86_l_28c0;
	case 10436ULL: goto x86_l_28c4;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10453ULL: goto x86_l_28d5;
	case 10458ULL: goto x86_l_28da;
	case 10463ULL: goto x86_l_28df;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10481ULL: goto x86_l_28f1;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10499ULL: goto x86_l_2903;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10531ULL: goto x86_l_2923;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10559ULL: goto x86_l_293f;
	case 10563ULL: goto x86_l_2943;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10587ULL: goto x86_l_295b;
	case 10591ULL: goto x86_l_295f;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10611ULL: goto x86_l_2973;
	case 10615ULL: goto x86_l_2977;
	case 10623ULL: goto x86_l_297f;
	case 10627ULL: goto x86_l_2983;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10650ULL: goto x86_l_299a;
	case 10657ULL: goto x86_l_29a1;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10681ULL: goto x86_l_29b9;
	case 10684ULL: goto x86_l_29bc;
	case 10691ULL: goto x86_l_29c3;
	case 10695ULL: goto x86_l_29c7;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10719ULL: goto x86_l_29df;
	case 10723ULL: goto x86_l_29e3;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10741ULL: goto x86_l_29f5;
	case 10743ULL: goto x86_l_29f7;
	case 10747ULL: goto x86_l_29fb;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10773ULL: goto x86_l_2a15;
	case 10777ULL: goto x86_l_2a19;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10808ULL: goto x86_l_2a38;
	case 10815ULL: goto x86_l_2a3f;
	case 10819ULL: goto x86_l_2a43;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10846ULL: goto x86_l_2a5e;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10869ULL: goto x86_l_2a75;
	case 10872ULL: goto x86_l_2a78;
	case 10876ULL: goto x86_l_2a7c;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10907ULL: goto x86_l_2a9b;
	case 10914ULL: goto x86_l_2aa2;
	case 10918ULL: goto x86_l_2aa6;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10938ULL: goto x86_l_2aba;
	case 10942ULL: goto x86_l_2abe;
	case 10950ULL: goto x86_l_2ac6;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10974ULL: goto x86_l_2ade;
	case 10977ULL: goto x86_l_2ae1;
	case 10984ULL: goto x86_l_2ae8;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10996ULL: goto x86_l_2af4;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11008ULL: goto x86_l_2b00;
	case 11011ULL: goto x86_l_2b03;
	case 11018ULL: goto x86_l_2b0a;
	case 11022ULL: goto x86_l_2b0e;
	case 11025ULL: goto x86_l_2b11;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11040ULL: goto x86_l_2b20;
	case 11042ULL: goto x86_l_2b22;
	case 11046ULL: goto x86_l_2b26;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11074ULL: goto x86_l_2b42;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11100ULL: goto x86_l_2b5c;
	case 11104ULL: goto x86_l_2b60;
	case 11108ULL: goto x86_l_2b64;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11135ULL: goto x86_l_2b7f;
	case 11142ULL: goto x86_l_2b86;
	case 11146ULL: goto x86_l_2b8a;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11164ULL: goto x86_l_2b9c;
	case 11167ULL: goto x86_l_2b9f;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11176ULL: goto x86_l_2ba8;
	case 11181ULL: goto x86_l_2bad;
	case 11186ULL: goto x86_l_2bb2;
	case 11191ULL: goto x86_l_2bb7;
	case 11194ULL: goto x86_l_2bba;
	case 11196ULL: goto x86_l_2bbc;
	case 11199ULL: goto x86_l_2bbf;
	case 11203ULL: goto x86_l_2bc3;
	case 11207ULL: goto x86_l_2bc7;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11229ULL: goto x86_l_2bdd;
	case 11231ULL: goto x86_l_2bdf;
	case 11239ULL: goto x86_l_2be7;
	case 11246ULL: goto x86_l_2bee;
	case 11248ULL: goto x86_l_2bf0;
	case 11257ULL: goto x86_l_2bf9;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11276ULL: goto x86_l_2c0c;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11299ULL: goto x86_l_2c23;
	case 11301ULL: goto x86_l_2c25;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11309ULL: goto x86_l_2c2d;
	case 11317ULL: goto x86_l_2c35;
	case 11324ULL: goto x86_l_2c3c;
	case 11332ULL: goto x86_l_2c44;
	case 11339ULL: goto x86_l_2c4b;
	case 11341ULL: goto x86_l_2c4d;
	case 11350ULL: goto x86_l_2c56;
	case 11356ULL: goto x86_l_2c5c;
	case 11358ULL: goto x86_l_2c5e;
	case 11362ULL: goto x86_l_2c62;
	case 11369ULL: goto x86_l_2c69;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11394ULL: goto x86_l_2c82;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11410ULL: goto x86_l_2c92;
	case 11417ULL: goto x86_l_2c99;
	case 11425ULL: goto x86_l_2ca1;
	case 11432ULL: goto x86_l_2ca8;
	case 11434ULL: goto x86_l_2caa;
	case 11443ULL: goto x86_l_2cb3;
	case 11449ULL: goto x86_l_2cb9;
	case 11451ULL: goto x86_l_2cbb;
	case 11455ULL: goto x86_l_2cbf;
	case 11462ULL: goto x86_l_2cc6;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11495ULL: goto x86_l_2ce7;
	case 11503ULL: goto x86_l_2cef;
	case 11510ULL: goto x86_l_2cf6;
	case 11518ULL: goto x86_l_2cfe;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11536ULL: goto x86_l_2d10;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11548ULL: goto x86_l_2d1c;
	case 11555ULL: goto x86_l_2d23;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11583ULL: goto x86_l_2d3f;
	case 11585ULL: goto x86_l_2d41;
	case 11588ULL: goto x86_l_2d44;
	case 11596ULL: goto x86_l_2d4c;
	case 11603ULL: goto x86_l_2d53;
	case 11611ULL: goto x86_l_2d5b;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11629ULL: goto x86_l_2d6d;
	case 11635ULL: goto x86_l_2d73;
	case 11637ULL: goto x86_l_2d75;
	case 11641ULL: goto x86_l_2d79;
	case 11648ULL: goto x86_l_2d80;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11681ULL: goto x86_l_2da1;
	case 11689ULL: goto x86_l_2da9;
	case 11696ULL: goto x86_l_2db0;
	case 11704ULL: goto x86_l_2db8;
	case 11711ULL: goto x86_l_2dbf;
	case 11713ULL: goto x86_l_2dc1;
	case 11722ULL: goto x86_l_2dca;
	case 11728ULL: goto x86_l_2dd0;
	case 11730ULL: goto x86_l_2dd2;
	case 11734ULL: goto x86_l_2dd6;
	case 11741ULL: goto x86_l_2ddd;
	case 11749ULL: goto x86_l_2de5;
	case 11754ULL: goto x86_l_2dea;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11774ULL: goto x86_l_2dfe;
	case 11782ULL: goto x86_l_2e06;
	case 11789ULL: goto x86_l_2e0d;
	case 11797ULL: goto x86_l_2e15;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11823ULL: goto x86_l_2e2f;
	case 11827ULL: goto x86_l_2e33;
	case 11834ULL: goto x86_l_2e3a;
	case 11837ULL: goto x86_l_2e3d;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11859ULL: goto x86_l_2e53;
	case 11862ULL: goto x86_l_2e56;
	case 11870ULL: goto x86_l_2e5e;
	case 11877ULL: goto x86_l_2e65;
	case 11885ULL: goto x86_l_2e6d;
	case 11892ULL: goto x86_l_2e74;
	case 11894ULL: goto x86_l_2e76;
	case 11903ULL: goto x86_l_2e7f;
	case 11909ULL: goto x86_l_2e85;
	default: return 0xffffffffffffffffULL;
	}
x86_l_278f:
	/* 0x278f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2796:
	/* 0x2796: ja     27e4 <tracepoint__sched__sched_process_fork+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27e4;
	}
x86_l_2798:
	/* 0x2798: mov    BYTE PTR [r14+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_27a1:
	/* 0x27a1: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_27a7:
	/* 0x27a7: ja     27e4 <tracepoint__sched__sched_process_fork+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27e4;
	}
x86_l_27a9:
	/* 0x27a9: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_27ad:
	/* 0x27ad: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_27b4:
	/* 0x27b4: lea    rdx,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_27bc:
	/* 0x27bc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_27c1:
	/* 0x27c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c6:
	/* 0x27c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27cb:
	/* 0x27cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cd:
	/* 0x27cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27d0:
	/* 0x27d0: js     27e4 <tracepoint__sched__sched_process_fork+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27e4;
	}
x86_l_27d2:
	/* 0x27d2: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_27d5:
	/* 0x27d5: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27dd:
	/* 0x27dd: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_27e4:
	/* 0x27e4: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27ec:
	/* 0x27ec: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_27f3:
	/* 0x27f3: ja     2841 <tracepoint__sched__sched_process_fork+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2841;
	}
x86_l_27f5:
	/* 0x27f5: mov    BYTE PTR [r14+rbx*1+0x89],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519559ULL);
x86_l_27fe:
	/* 0x27fe: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2804:
	/* 0x2804: ja     2841 <tracepoint__sched__sched_process_fork+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2841;
	}
x86_l_2806:
	/* 0x2806: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_280a:
	/* 0x280a: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2811:
	/* 0x2811: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2819:
	/* 0x2819: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_281e:
	/* 0x281e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2823:
	/* 0x2823: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2828:
	/* 0x2828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282a:
	/* 0x282a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_282d:
	/* 0x282d: js     2841 <tracepoint__sched__sched_process_fork+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2841;
	}
x86_l_282f:
	/* 0x282f: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2832:
	/* 0x2832: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_283a:
	/* 0x283a: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2841:
	/* 0x2841: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2849:
	/* 0x2849: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2850:
	/* 0x2850: ja     289e <tracepoint__sched__sched_process_fork+0x289e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_289e;
	}
x86_l_2852:
	/* 0x2852: mov    BYTE PTR [r14+rbx*1+0x89],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519560ULL);
x86_l_285b:
	/* 0x285b: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2861:
	/* 0x2861: ja     289e <tracepoint__sched__sched_process_fork+0x289e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_289e;
	}
x86_l_2863:
	/* 0x2863: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2867:
	/* 0x2867: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_286e:
	/* 0x286e: lea    rdx,[rsp+0xfc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 252ULL);
x86_l_2876:
	/* 0x2876: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_287b:
	/* 0x287b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2880:
	/* 0x2880: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2885:
	/* 0x2885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2887:
	/* 0x2887: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_288a:
	/* 0x288a: js     289e <tracepoint__sched__sched_process_fork+0x289e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_289e;
	}
x86_l_288c:
	/* 0x288c: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_288f:
	/* 0x288f: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2897:
	/* 0x2897: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_289e:
	/* 0x289e: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28a6:
	/* 0x28a6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_28ad:
	/* 0x28ad: ja     28f8 <tracepoint__sched__sched_process_fork+0x28f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28f8;
	}
x86_l_28af:
	/* 0x28af: mov    BYTE PTR [r14+rbx*1+0x89],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519561ULL);
x86_l_28b8:
	/* 0x28b8: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_28be:
	/* 0x28be: ja     28f8 <tracepoint__sched__sched_process_fork+0x28f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28f8;
	}
x86_l_28c0:
	/* 0x28c0: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_28c4:
	/* 0x28c4: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_28cb:
	/* 0x28cb: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28d0:
	/* 0x28d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28d5:
	/* 0x28d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28da:
	/* 0x28da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28df:
	/* 0x28df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e1:
	/* 0x28e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e4:
	/* 0x28e4: js     28f8 <tracepoint__sched__sched_process_fork+0x28f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28f8;
	}
x86_l_28e6:
	/* 0x28e6: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_28e9:
	/* 0x28e9: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28f1:
	/* 0x28f1: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_28f8:
	/* 0x28f8: test   BYTE PTR [r15+0x5],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836482ULL);
x86_l_28fd:
	/* 0x28fd: je     2f7c <tracepoint__sched__sched_process_fork+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12156ULL;
	}
x86_l_2903:
	/* 0x2903: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2906:
	/* 0x2906: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_290b:
	/* 0x290b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2910:
	/* 0x2910: mov    rdx,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2918:
	/* 0x2918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291d:
	/* 0x291d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291f:
	/* 0x291f: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2923:
	/* 0x2923: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2927:
	/* 0x2927: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_292a:
	/* 0x292a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_292f:
	/* 0x292f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2934:
	/* 0x2934: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2939:
	/* 0x2939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293b:
	/* 0x293b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293f:
	/* 0x293f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2943:
	/* 0x2943: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2946:
	/* 0x2946: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_294b:
	/* 0x294b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2950:
	/* 0x2950: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2955:
	/* 0x2955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2957:
	/* 0x2957: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295b:
	/* 0x295b: lea    rdx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_295f:
	/* 0x295f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2962:
	/* 0x2962: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2967:
	/* 0x2967: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_296c:
	/* 0x296c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2971:
	/* 0x2971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2973:
	/* 0x2973: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2977:
	/* 0x2977: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_297f:
	/* 0x297f: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2983:
	/* 0x2983: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2986:
	/* 0x2986: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_298b:
	/* 0x298b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2990:
	/* 0x2990: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2995:
	/* 0x2995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2997:
	/* 0x2997: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299a:
	/* 0x299a: mov    DWORD PTR [rsp+0xec],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_29a1:
	/* 0x29a1: lea    rdx,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29a5:
	/* 0x29a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29a8:
	/* 0x29a8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29ad:
	/* 0x29ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b2:
	/* 0x29b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29b7:
	/* 0x29b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b9:
	/* 0x29b9: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bc:
	/* 0x29bc: mov    DWORD PTR [rsp+0xe8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_29c3:
	/* 0x29c3: lea    rdx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29c7:
	/* 0x29c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29ca:
	/* 0x29ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29cf:
	/* 0x29cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29d4:
	/* 0x29d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29d9:
	/* 0x29d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29db:
	/* 0x29db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29df:
	/* 0x29df: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29e3:
	/* 0x29e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29e6:
	/* 0x29e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29eb:
	/* 0x29eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29f0:
	/* 0x29f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f5:
	/* 0x29f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f7:
	/* 0x29f7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29fb:
	/* 0x29fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29fe:
	/* 0x29fe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a03:
	/* 0x2a03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a08:
	/* 0x2a08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a0d:
	/* 0x2a0d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a10:
	/* 0x2a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a12:
	/* 0x2a12: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a15:
	/* 0x2a15: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a19:
	/* 0x2a19: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a1d:
	/* 0x2a1d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a21:
	/* 0x2a21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a24:
	/* 0x2a24: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a29:
	/* 0x2a29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a33:
	/* 0x2a33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a35:
	/* 0x2a35: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a38:
	/* 0x2a38: mov    DWORD PTR [rsp+0xe4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_2a3f:
	/* 0x2a3f: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a43:
	/* 0x2a43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a46:
	/* 0x2a46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a50:
	/* 0x2a50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a58:
	/* 0x2a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5a:
	/* 0x2a5a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5e:
	/* 0x2a5e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a61:
	/* 0x2a61: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a66:
	/* 0x2a66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a70:
	/* 0x2a70: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a73:
	/* 0x2a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a75:
	/* 0x2a75: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a78:
	/* 0x2a78: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a7c:
	/* 0x2a7c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a80:
	/* 0x2a80: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a84:
	/* 0x2a84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a87:
	/* 0x2a87: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a91:
	/* 0x2a91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a96:
	/* 0x2a96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a98:
	/* 0x2a98: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    DWORD PTR [rsp+0xe0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2aa2:
	/* 0x2aa2: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2aa6:
	/* 0x2aa6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aa9:
	/* 0x2aa9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2aae:
	/* 0x2aae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ab8:
	/* 0x2ab8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aba:
	/* 0x2aba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abe:
	/* 0x2abe: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2ac6:
	/* 0x2ac6: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aca:
	/* 0x2aca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2acd:
	/* 0x2acd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2ad2:
	/* 0x2ad2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2adc:
	/* 0x2adc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ade:
	/* 0x2ade: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    DWORD PTR [rsp+0xdc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_2ae8:
	/* 0x2ae8: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2aec:
	/* 0x2aec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aef:
	/* 0x2aef: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2af4:
	/* 0x2af4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af9:
	/* 0x2af9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2afe:
	/* 0x2afe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b00:
	/* 0x2b00: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b03:
	/* 0x2b03: mov    DWORD PTR [rsp+0xd8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b0e:
	/* 0x2b0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b11:
	/* 0x2b11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b16:
	/* 0x2b16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b1b:
	/* 0x2b1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b20:
	/* 0x2b20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b22:
	/* 0x2b22: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b26:
	/* 0x2b26: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b2a:
	/* 0x2b2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b2d:
	/* 0x2b2d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b32:
	/* 0x2b32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b37:
	/* 0x2b37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b3c:
	/* 0x2b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3e:
	/* 0x2b3e: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b42:
	/* 0x2b42: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b45:
	/* 0x2b45: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b54:
	/* 0x2b54: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b57:
	/* 0x2b57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b59:
	/* 0x2b59: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b5c:
	/* 0x2b5c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2b60:
	/* 0x2b60: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b64:
	/* 0x2b64: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b68:
	/* 0x2b68: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b6b:
	/* 0x2b6b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b70:
	/* 0x2b70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b75:
	/* 0x2b75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b7a:
	/* 0x2b7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7c:
	/* 0x2b7c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    DWORD PTR [rsp+0xd4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2b86:
	/* 0x2b86: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b8d:
	/* 0x2b8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b92:
	/* 0x2b92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b97:
	/* 0x2b97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b9c:
	/* 0x2b9c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b9f:
	/* 0x2b9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba1:
	/* 0x2ba1: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ba5:
	/* 0x2ba5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ba8:
	/* 0x2ba8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2bad:
	/* 0x2bad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bb7:
	/* 0x2bb7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2bba:
	/* 0x2bba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bbc:
	/* 0x2bbc: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbf:
	/* 0x2bbf: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2bc3:
	/* 0x2bc3: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2bc7:
	/* 0x2bc7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bce:
	/* 0x2bce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bdd:
	/* 0x2bdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdf:
	/* 0x2bdf: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2be7:
	/* 0x2be7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2bee:
	/* 0x2bee: ja     2c3c <tracepoint__sched__sched_process_fork+0x2c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c3c;
	}
x86_l_2bf0:
	/* 0x2bf0: mov    BYTE PTR [r14+rbx*1+0x89],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519562ULL);
x86_l_2bf9:
	/* 0x2bf9: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2bff:
	/* 0x2bff: ja     2c3c <tracepoint__sched__sched_process_fork+0x2c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c3c;
	}
x86_l_2c01:
	/* 0x2c01: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c05:
	/* 0x2c05: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2c0c:
	/* 0x2c0c: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2c14:
	/* 0x2c14: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2c19:
	/* 0x2c19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c23:
	/* 0x2c23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c25:
	/* 0x2c25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c28:
	/* 0x2c28: js     2c3c <tracepoint__sched__sched_process_fork+0x2c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c3c;
	}
x86_l_2c2a:
	/* 0x2c2a: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c35:
	/* 0x2c35: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2c3c:
	/* 0x2c3c: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c44:
	/* 0x2c44: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2c4b:
	/* 0x2c4b: ja     2c99 <tracepoint__sched__sched_process_fork+0x2c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c99;
	}
x86_l_2c4d:
	/* 0x2c4d: mov    BYTE PTR [r14+rbx*1+0x89],0xb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519563ULL);
x86_l_2c56:
	/* 0x2c56: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2c5c:
	/* 0x2c5c: ja     2c99 <tracepoint__sched__sched_process_fork+0x2c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c99;
	}
x86_l_2c5e:
	/* 0x2c5e: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c62:
	/* 0x2c62: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2c69:
	/* 0x2c69: lea    rdx,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c71:
	/* 0x2c71: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2c76:
	/* 0x2c76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c80:
	/* 0x2c80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c82:
	/* 0x2c82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c85:
	/* 0x2c85: js     2c99 <tracepoint__sched__sched_process_fork+0x2c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c99;
	}
x86_l_2c87:
	/* 0x2c87: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c92:
	/* 0x2c92: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2c99:
	/* 0x2c99: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ca1:
	/* 0x2ca1: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2ca8:
	/* 0x2ca8: ja     2cf6 <tracepoint__sched__sched_process_fork+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cf6;
	}
x86_l_2caa:
	/* 0x2caa: mov    BYTE PTR [r14+rbx*1+0x89],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519564ULL);
x86_l_2cb3:
	/* 0x2cb3: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2cb9:
	/* 0x2cb9: ja     2cf6 <tracepoint__sched__sched_process_fork+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cf6;
	}
x86_l_2cbb:
	/* 0x2cbb: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2cbf:
	/* 0x2cbf: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2cc6:
	/* 0x2cc6: lea    rdx,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_2cce:
	/* 0x2cce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cdd:
	/* 0x2cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdf:
	/* 0x2cdf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce2:
	/* 0x2ce2: js     2cf6 <tracepoint__sched__sched_process_fork+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cf6;
	}
x86_l_2ce4:
	/* 0x2ce4: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2ce7:
	/* 0x2ce7: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cef:
	/* 0x2cef: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2cf6:
	/* 0x2cf6: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cfe:
	/* 0x2cfe: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2d05:
	/* 0x2d05: ja     2d53 <tracepoint__sched__sched_process_fork+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d53;
	}
x86_l_2d07:
	/* 0x2d07: mov    BYTE PTR [r14+rbx*1+0x89],0xd */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519565ULL);
x86_l_2d10:
	/* 0x2d10: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2d16:
	/* 0x2d16: ja     2d53 <tracepoint__sched__sched_process_fork+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d53;
	}
x86_l_2d18:
	/* 0x2d18: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d1c:
	/* 0x2d1c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2d23:
	/* 0x2d23: lea    rdx,[rsp+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_2d2b:
	/* 0x2d2b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2d30:
	/* 0x2d30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d35:
	/* 0x2d35: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d3a:
	/* 0x2d3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3c:
	/* 0x2d3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d3f:
	/* 0x2d3f: js     2d53 <tracepoint__sched__sched_process_fork+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2d53;
	}
x86_l_2d41:
	/* 0x2d41: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2d44:
	/* 0x2d44: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d4c:
	/* 0x2d4c: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2d53:
	/* 0x2d53: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d5b:
	/* 0x2d5b: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2d62:
	/* 0x2d62: ja     2db0 <tracepoint__sched__sched_process_fork+0x2db0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2db0;
	}
x86_l_2d64:
	/* 0x2d64: mov    BYTE PTR [r14+rbx*1+0x89],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519566ULL);
x86_l_2d6d:
	/* 0x2d6d: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2d73:
	/* 0x2d73: ja     2db0 <tracepoint__sched__sched_process_fork+0x2db0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2db0;
	}
x86_l_2d75:
	/* 0x2d75: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d79:
	/* 0x2d79: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2d80:
	/* 0x2d80: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d88:
	/* 0x2d88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d92:
	/* 0x2d92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d97:
	/* 0x2d97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d99:
	/* 0x2d99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d9c:
	/* 0x2d9c: js     2db0 <tracepoint__sched__sched_process_fork+0x2db0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2db0;
	}
x86_l_2d9e:
	/* 0x2d9e: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2da1:
	/* 0x2da1: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2da9:
	/* 0x2da9: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2db0:
	/* 0x2db0: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2db8:
	/* 0x2db8: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2dbf:
	/* 0x2dbf: ja     2e0d <tracepoint__sched__sched_process_fork+0x2e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e0d;
	}
x86_l_2dc1:
	/* 0x2dc1: mov    BYTE PTR [r14+rbx*1+0x89],0xf */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519567ULL);
x86_l_2dca:
	/* 0x2dca: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2dd0:
	/* 0x2dd0: ja     2e0d <tracepoint__sched__sched_process_fork+0x2e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e0d;
	}
x86_l_2dd2:
	/* 0x2dd2: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2dd6:
	/* 0x2dd6: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2ddd:
	/* 0x2ddd: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2de5:
	/* 0x2de5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2dea:
	/* 0x2dea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2def:
	/* 0x2def: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2df4:
	/* 0x2df4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df6:
	/* 0x2df6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2df9:
	/* 0x2df9: js     2e0d <tracepoint__sched__sched_process_fork+0x2e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e0d;
	}
x86_l_2dfb:
	/* 0x2dfb: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e06:
	/* 0x2e06: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2e0d:
	/* 0x2e0d: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e15:
	/* 0x2e15: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2e1c:
	/* 0x2e1c: ja     2e65 <tracepoint__sched__sched_process_fork+0x2e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e65;
	}
x86_l_2e1e:
	/* 0x2e1e: mov    BYTE PTR [r14+rbx*1+0x89],0x10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519568ULL);
x86_l_2e27:
	/* 0x2e27: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2e2d:
	/* 0x2e2d: ja     2e65 <tracepoint__sched__sched_process_fork+0x2e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e65;
	}
x86_l_2e2f:
	/* 0x2e2f: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2e33:
	/* 0x2e33: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2e3d:
	/* 0x2e3d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2e42:
	/* 0x2e42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e47:
	/* 0x2e47: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e4c:
	/* 0x2e4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4e:
	/* 0x2e4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e51:
	/* 0x2e51: js     2e65 <tracepoint__sched__sched_process_fork+0x2e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e65;
	}
x86_l_2e53:
	/* 0x2e53: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2e56:
	/* 0x2e56: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e5e:
	/* 0x2e5e: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2e65:
	/* 0x2e65: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e6d:
	/* 0x2e6d: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2e74:
	/* 0x2e74: ja     2ec2 <tracepoint__sched__sched_process_fork+0x2ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11970ULL;
	}
x86_l_2e76:
	/* 0x2e76: mov    BYTE PTR [r14+rbx*1+0x89],0x11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519569ULL);
x86_l_2e7f:
	/* 0x2e7f: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2e85:
	/* 0x2e85: ja     2ec2 <tracepoint__sched__sched_process_fork+0x2ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11970ULL;
	}
	return 11911ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11911ULL: goto x86_l_2e87;
	case 11915ULL: goto x86_l_2e8b;
	case 11922ULL: goto x86_l_2e92;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11963ULL: goto x86_l_2ebb;
	case 11970ULL: goto x86_l_2ec2;
	case 11978ULL: goto x86_l_2eca;
	case 11985ULL: goto x86_l_2ed1;
	case 11987ULL: goto x86_l_2ed3;
	case 11996ULL: goto x86_l_2edc;
	case 12002ULL: goto x86_l_2ee2;
	case 12004ULL: goto x86_l_2ee4;
	case 12008ULL: goto x86_l_2ee8;
	case 12015ULL: goto x86_l_2eef;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12040ULL: goto x86_l_2f08;
	case 12043ULL: goto x86_l_2f0b;
	case 12045ULL: goto x86_l_2f0d;
	case 12048ULL: goto x86_l_2f10;
	case 12056ULL: goto x86_l_2f18;
	case 12063ULL: goto x86_l_2f1f;
	case 12071ULL: goto x86_l_2f27;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12089ULL: goto x86_l_2f39;
	case 12095ULL: goto x86_l_2f3f;
	case 12097ULL: goto x86_l_2f41;
	case 12101ULL: goto x86_l_2f45;
	case 12108ULL: goto x86_l_2f4c;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12131ULL: goto x86_l_2f63;
	case 12133ULL: goto x86_l_2f65;
	case 12136ULL: goto x86_l_2f68;
	case 12138ULL: goto x86_l_2f6a;
	case 12141ULL: goto x86_l_2f6d;
	case 12149ULL: goto x86_l_2f75;
	case 12156ULL: goto x86_l_2f7c;
	case 12163ULL: goto x86_l_2f83;
	case 12167ULL: goto x86_l_2f87;
	case 12170ULL: goto x86_l_2f8a;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12188ULL: goto x86_l_2f9c;
	case 12190ULL: goto x86_l_2f9e;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12203ULL: goto x86_l_2fab;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12221ULL: goto x86_l_2fbd;
	case 12223ULL: goto x86_l_2fbf;
	case 12227ULL: goto x86_l_2fc3;
	case 12231ULL: goto x86_l_2fc7;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12251ULL: goto x86_l_2fdb;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12278ULL: goto x86_l_2ff6;
	case 12280ULL: goto x86_l_2ff8;
	case 12283ULL: goto x86_l_2ffb;
	case 12287ULL: goto x86_l_2fff;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12312ULL: goto x86_l_3018;
	case 12314ULL: goto x86_l_301a;
	case 12318ULL: goto x86_l_301e;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12344ULL: goto x86_l_3038;
	case 12348ULL: goto x86_l_303c;
	case 12352ULL: goto x86_l_3040;
	case 12356ULL: goto x86_l_3044;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12379ULL: goto x86_l_305b;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12404ULL: goto x86_l_3074;
	case 12406ULL: goto x86_l_3076;
	case 12410ULL: goto x86_l_307a;
	case 12414ULL: goto x86_l_307e;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12434ULL: goto x86_l_3092;
	case 12438ULL: goto x86_l_3096;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12456ULL: goto x86_l_30a8;
	case 12459ULL: goto x86_l_30ab;
	case 12461ULL: goto x86_l_30ad;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12496ULL: goto x86_l_30d0;
	case 12499ULL: goto x86_l_30d3;
	case 12503ULL: goto x86_l_30d7;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12524ULL: goto x86_l_30ec;
	case 12526ULL: goto x86_l_30ee;
	case 12530ULL: goto x86_l_30f2;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12551ULL: goto x86_l_3107;
	case 12553ULL: goto x86_l_3109;
	case 12556ULL: goto x86_l_310c;
	case 12560ULL: goto x86_l_3110;
	case 12564ULL: goto x86_l_3114;
	case 12568ULL: goto x86_l_3118;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12586ULL: goto x86_l_312a;
	case 12588ULL: goto x86_l_312c;
	case 12592ULL: goto x86_l_3130;
	case 12596ULL: goto x86_l_3134;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12616ULL: goto x86_l_3148;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12645ULL: goto x86_l_3165;
	case 12647ULL: goto x86_l_3167;
	case 12651ULL: goto x86_l_316b;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12669ULL: goto x86_l_317d;
	case 12672ULL: goto x86_l_3180;
	case 12674ULL: goto x86_l_3182;
	case 12677ULL: goto x86_l_3185;
	case 12681ULL: goto x86_l_3189;
	case 12685ULL: goto x86_l_318d;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12717ULL: goto x86_l_31ad;
	case 12720ULL: goto x86_l_31b0;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12737ULL: goto x86_l_31c1;
	case 12740ULL: goto x86_l_31c4;
	case 12742ULL: goto x86_l_31c6;
	case 12745ULL: goto x86_l_31c9;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12769ULL: goto x86_l_31e1;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12790ULL: goto x86_l_31f6;
	case 12792ULL: goto x86_l_31f8;
	case 12795ULL: goto x86_l_31fb;
	case 12799ULL: goto x86_l_31ff;
	case 12803ULL: goto x86_l_3203;
	case 12807ULL: goto x86_l_3207;
	case 12810ULL: goto x86_l_320a;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12834ULL: goto x86_l_3222;
	case 12838ULL: goto x86_l_3226;
	case 12845ULL: goto x86_l_322d;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12870ULL: goto x86_l_3246;
	case 12872ULL: goto x86_l_3248;
	case 12876ULL: goto x86_l_324c;
	case 12880ULL: goto x86_l_3250;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12900ULL: goto x86_l_3264;
	case 12904ULL: goto x86_l_3268;
	case 12912ULL: goto x86_l_3270;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12931ULL: goto x86_l_3283;
	case 12933ULL: goto x86_l_3285;
	case 12940ULL: goto x86_l_328c;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12951ULL: goto x86_l_3297;
	case 12955ULL: goto x86_l_329b;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12979ULL: goto x86_l_32b3;
	case 12983ULL: goto x86_l_32b7;
	case 12987ULL: goto x86_l_32bb;
	case 12992ULL: goto x86_l_32c0;
	case 12996ULL: goto x86_l_32c4;
	case 12999ULL: goto x86_l_32c7;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13020ULL: goto x86_l_32dc;
	case 13024ULL: goto x86_l_32e0;
	case 13028ULL: goto x86_l_32e4;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13051ULL: goto x86_l_32fb;
	case 13055ULL: goto x86_l_32ff;
	case 13059ULL: goto x86_l_3303;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13080ULL: goto x86_l_3318;
	case 13082ULL: goto x86_l_331a;
	case 13086ULL: goto x86_l_331e;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13101ULL: goto x86_l_332d;
	case 13105ULL: goto x86_l_3331;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13123ULL: goto x86_l_3343;
	case 13128ULL: goto x86_l_3348;
	case 13130ULL: goto x86_l_334a;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13151ULL: goto x86_l_335f;
	case 13153ULL: goto x86_l_3361;
	case 13157ULL: goto x86_l_3365;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13181ULL: goto x86_l_337d;
	case 13184ULL: goto x86_l_3380;
	case 13189ULL: goto x86_l_3385;
	case 13194ULL: goto x86_l_338a;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13204ULL: goto x86_l_3394;
	case 13207ULL: goto x86_l_3397;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13229ULL: goto x86_l_33ad;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13241ULL: goto x86_l_33b9;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13257ULL: goto x86_l_33c9;
	case 13259ULL: goto x86_l_33cb;
	case 13267ULL: goto x86_l_33d3;
	case 13271ULL: goto x86_l_33d7;
	case 13279ULL: goto x86_l_33df;
	case 13281ULL: goto x86_l_33e1;
	case 13288ULL: goto x86_l_33e8;
	case 13293ULL: goto x86_l_33ed;
	case 13298ULL: goto x86_l_33f2;
	case 13303ULL: goto x86_l_33f7;
	case 13306ULL: goto x86_l_33fa;
	case 13308ULL: goto x86_l_33fc;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13316ULL: goto x86_l_3404;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13334ULL: goto x86_l_3416;
	case 13337ULL: goto x86_l_3419;
	case 13343ULL: goto x86_l_341f;
	case 13347ULL: goto x86_l_3423;
	case 13354ULL: goto x86_l_342a;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13375ULL: goto x86_l_343f;
	case 13377ULL: goto x86_l_3441;
	case 13379ULL: goto x86_l_3443;
	case 13386ULL: goto x86_l_344a;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13391ULL: goto x86_l_344f;
	case 13393ULL: goto x86_l_3451;
	case 13395ULL: goto x86_l_3453;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13408ULL: goto x86_l_3460;
	case 13411ULL: goto x86_l_3463;
	case 13415ULL: goto x86_l_3467;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13460ULL: goto x86_l_3494;
	case 13467ULL: goto x86_l_349b;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13479ULL: goto x86_l_34a7;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13487ULL: goto x86_l_34af;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e87:
	/* 0x2e87: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2e8b:
	/* 0x2e8b: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2e92:
	/* 0x2e92: lea    rdx,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ea9:
	/* 0x2ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eab:
	/* 0x2eab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eae:
	/* 0x2eae: js     2ec2 <tracepoint__sched__sched_process_fork+0x2ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ec2;
	}
x86_l_2eb0:
	/* 0x2eb0: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2eb3:
	/* 0x2eb3: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ebb:
	/* 0x2ebb: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2ec2:
	/* 0x2ec2: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eca:
	/* 0x2eca: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2ed1:
	/* 0x2ed1: ja     2f1f <tracepoint__sched__sched_process_fork+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f1f;
	}
x86_l_2ed3:
	/* 0x2ed3: mov    BYTE PTR [r14+rbx*1+0x89],0x12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519570ULL);
x86_l_2edc:
	/* 0x2edc: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2ee2:
	/* 0x2ee2: ja     2f1f <tracepoint__sched__sched_process_fork+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f1f;
	}
x86_l_2ee4:
	/* 0x2ee4: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2ee8:
	/* 0x2ee8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2eef:
	/* 0x2eef: lea    rdx,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2ef7:
	/* 0x2ef7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2efc:
	/* 0x2efc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f01:
	/* 0x2f01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f06:
	/* 0x2f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f08:
	/* 0x2f08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f0b:
	/* 0x2f0b: js     2f1f <tracepoint__sched__sched_process_fork+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f1f;
	}
x86_l_2f0d:
	/* 0x2f0d: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2f10:
	/* 0x2f10: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f18:
	/* 0x2f18: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2f1f:
	/* 0x2f1f: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f27:
	/* 0x2f27: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2f2e:
	/* 0x2f2e: ja     2f7c <tracepoint__sched__sched_process_fork+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f7c;
	}
x86_l_2f30:
	/* 0x2f30: mov    BYTE PTR [r14+rbx*1+0x89],0x13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519571ULL);
x86_l_2f39:
	/* 0x2f39: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2f3f:
	/* 0x2f3f: ja     2f7c <tracepoint__sched__sched_process_fork+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f7c;
	}
x86_l_2f41:
	/* 0x2f41: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2f45:
	/* 0x2f45: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2f4c:
	/* 0x2f4c: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2f54:
	/* 0x2f54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f59:
	/* 0x2f59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f63:
	/* 0x2f63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f65:
	/* 0x2f65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f68:
	/* 0x2f68: js     2f7c <tracepoint__sched__sched_process_fork+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f7c;
	}
x86_l_2f6a:
	/* 0x2f6a: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2f6d:
	/* 0x2f6d: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f75:
	/* 0x2f75: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2f7c:
	/* 0x2f7c: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2f83:
	/* 0x2f83: lea    r13,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f87:
	/* 0x2f87: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f8a:
	/* 0x2f8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f8f:
	/* 0x2f8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f94:
	/* 0x2f94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f99:
	/* 0x2f99: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f9c:
	/* 0x2f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9e:
	/* 0x2f9e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2fa7:
	/* 0x2fa7: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fab:
	/* 0x2fab: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fae:
	/* 0x2fae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fbd:
	/* 0x2fbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbf:
	/* 0x2fbf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc3:
	/* 0x2fc3: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2fc7:
	/* 0x2fc7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fca:
	/* 0x2fca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd9:
	/* 0x2fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdb:
	/* 0x2fdb: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fdf:
	/* 0x2fdf: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fe7:
	/* 0x2fe7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2fec:
	/* 0x2fec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ff1:
	/* 0x2ff1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ff6:
	/* 0x2ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff8:
	/* 0x2ff8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2fff:
	/* 0x2fff: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3003:
	/* 0x3003: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3006:
	/* 0x3006: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_300b:
	/* 0x300b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3010:
	/* 0x3010: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3015:
	/* 0x3015: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3018:
	/* 0x3018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301a:
	/* 0x301a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_301e:
	/* 0x301e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3021:
	/* 0x3021: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3026:
	/* 0x3026: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_302b:
	/* 0x302b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3030:
	/* 0x3030: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3033:
	/* 0x3033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3035:
	/* 0x3035: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3038:
	/* 0x3038: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_303c:
	/* 0x303c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3040:
	/* 0x3040: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3044:
	/* 0x3044: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3047:
	/* 0x3047: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_304c:
	/* 0x304c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3051:
	/* 0x3051: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3056:
	/* 0x3056: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3058:
	/* 0x3058: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_305b:
	/* 0x305b: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_305f:
	/* 0x305f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3062:
	/* 0x3062: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3067:
	/* 0x3067: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_306c:
	/* 0x306c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3071:
	/* 0x3071: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3074:
	/* 0x3074: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3076:
	/* 0x3076: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_307a:
	/* 0x307a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_307e:
	/* 0x307e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3081:
	/* 0x3081: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3086:
	/* 0x3086: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_308b:
	/* 0x308b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3090:
	/* 0x3090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3092:
	/* 0x3092: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3096:
	/* 0x3096: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3099:
	/* 0x3099: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_309e:
	/* 0x309e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30a3:
	/* 0x30a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30a8:
	/* 0x30a8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30ab:
	/* 0x30ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ad:
	/* 0x30ad: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b0:
	/* 0x30b0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_30b4:
	/* 0x30b4: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_30b8:
	/* 0x30b8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30bc:
	/* 0x30bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30bf:
	/* 0x30bf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30c4:
	/* 0x30c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c9:
	/* 0x30c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30ce:
	/* 0x30ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d0:
	/* 0x30d0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d3:
	/* 0x30d3: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30d7:
	/* 0x30d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30da:
	/* 0x30da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30df:
	/* 0x30df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30e4:
	/* 0x30e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30e9:
	/* 0x30e9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_30ec:
	/* 0x30ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ee:
	/* 0x30ee: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f2:
	/* 0x30f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30f5:
	/* 0x30f5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30fa:
	/* 0x30fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ff:
	/* 0x30ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3104:
	/* 0x3104: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3107:
	/* 0x3107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3109:
	/* 0x3109: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310c:
	/* 0x310c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3110:
	/* 0x3110: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3114:
	/* 0x3114: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3118:
	/* 0x3118: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_311b:
	/* 0x311b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3120:
	/* 0x3120: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3125:
	/* 0x3125: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_312a:
	/* 0x312a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312c:
	/* 0x312c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3130:
	/* 0x3130: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3134:
	/* 0x3134: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3137:
	/* 0x3137: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_313c:
	/* 0x313c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3141:
	/* 0x3141: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3146:
	/* 0x3146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3148:
	/* 0x3148: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_314b:
	/* 0x314b: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3150:
	/* 0x3150: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3153:
	/* 0x3153: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3158:
	/* 0x3158: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_315d:
	/* 0x315d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3162:
	/* 0x3162: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3165:
	/* 0x3165: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3167:
	/* 0x3167: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_316b:
	/* 0x316b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_316e:
	/* 0x316e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3173:
	/* 0x3173: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3178:
	/* 0x3178: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_317d:
	/* 0x317d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3180:
	/* 0x3180: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3182:
	/* 0x3182: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3185:
	/* 0x3185: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3189:
	/* 0x3189: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_318d:
	/* 0x318d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3191:
	/* 0x3191: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3194:
	/* 0x3194: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3199:
	/* 0x3199: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_319e:
	/* 0x319e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31a3:
	/* 0x31a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a5:
	/* 0x31a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31a9:
	/* 0x31a9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_31ad:
	/* 0x31ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31b0:
	/* 0x31b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_31b5:
	/* 0x31b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31ba:
	/* 0x31ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31bf:
	/* 0x31bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c1:
	/* 0x31c1: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_31c4:
	/* 0x31c4: jne    3222 <tracepoint__sched__sched_process_fork+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3222;
	}
x86_l_31c6:
	/* 0x31c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31c9:
	/* 0x31c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31ce:
	/* 0x31ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31d3:
	/* 0x31d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d8:
	/* 0x31d8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31db:
	/* 0x31db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dd:
	/* 0x31dd: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31e1:
	/* 0x31e1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31e4:
	/* 0x31e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_31e9:
	/* 0x31e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31ee:
	/* 0x31ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31f3:
	/* 0x31f3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31f6:
	/* 0x31f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f8:
	/* 0x31f8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fb:
	/* 0x31fb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_31ff:
	/* 0x31ff: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3203:
	/* 0x3203: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3207:
	/* 0x3207: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_320a:
	/* 0x320a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_320f:
	/* 0x320f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3214:
	/* 0x3214: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3219:
	/* 0x3219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321b:
	/* 0x321b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_321e:
	/* 0x321e: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3222:
	/* 0x3222: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3226:
	/* 0x3226: lea    rbp,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_322d:
	/* 0x322d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3230:
	/* 0x3230: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3235:
	/* 0x3235: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_323a:
	/* 0x323a: lea    r13,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_323e:
	/* 0x323e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3243:
	/* 0x3243: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3246:
	/* 0x3246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3248:
	/* 0x3248: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324c:
	/* 0x324c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3250:
	/* 0x3250: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3253:
	/* 0x3253: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3258:
	/* 0x3258: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_325d:
	/* 0x325d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3262:
	/* 0x3262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3264:
	/* 0x3264: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3268:
	/* 0x3268: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3270:
	/* 0x3270: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3275:
	/* 0x3275: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_327a:
	/* 0x327a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_327e:
	/* 0x327e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3283:
	/* 0x3283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3285:
	/* 0x3285: mov    eax,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_328c:
	/* 0x328c: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3290:
	/* 0x3290: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3295:
	/* 0x3295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3297:
	/* 0x3297: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_329b:
	/* 0x329b: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_329f:
	/* 0x329f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32a2:
	/* 0x32a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32a7:
	/* 0x32a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32ac:
	/* 0x32ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b1:
	/* 0x32b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b3:
	/* 0x32b3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b7:
	/* 0x32b7: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32bb:
	/* 0x32bb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_32c0:
	/* 0x32c0: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_32c4:
	/* 0x32c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32c7:
	/* 0x32c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32cc:
	/* 0x32cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d1:
	/* 0x32d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32d6:
	/* 0x32d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d8:
	/* 0x32d8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32dc:
	/* 0x32dc: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_32e0:
	/* 0x32e0: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_32e4:
	/* 0x32e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32e7:
	/* 0x32e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32ec:
	/* 0x32ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32f1:
	/* 0x32f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f6:
	/* 0x32f6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32f9:
	/* 0x32f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fb:
	/* 0x32fb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ff:
	/* 0x32ff: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3303:
	/* 0x3303: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3306:
	/* 0x3306: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_330b:
	/* 0x330b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3310:
	/* 0x3310: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3315:
	/* 0x3315: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3318:
	/* 0x3318: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331a:
	/* 0x331a: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_331e:
	/* 0x331e: je     3325 <tracepoint__sched__sched_process_fork+0x3325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3325;
	}
x86_l_3320:
	/* 0x3320: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_3325:
	/* 0x3325: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_332d:
	/* 0x332d: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3331:
	/* 0x3331: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_3339:
	/* 0x3339: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_333e:
	/* 0x333e: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_3343:
	/* 0x3343: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3348:
	/* 0x3348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334a:
	/* 0x334a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_334d:
	/* 0x334d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3352:
	/* 0x3352: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3357:
	/* 0x3357: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_335c:
	/* 0x335c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_335f:
	/* 0x335f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3361:
	/* 0x3361: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3365:
	/* 0x3365: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3368:
	/* 0x3368: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_336d:
	/* 0x336d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3372:
	/* 0x3372: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3377:
	/* 0x3377: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3379:
	/* 0x3379: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337d:
	/* 0x337d: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_3380:
	/* 0x3380: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_3385:
	/* 0x3385: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_338a:
	/* 0x338a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_338d:
	/* 0x338d: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_3392:
	/* 0x3392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3394:
	/* 0x3394: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3397:
	/* 0x3397: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_339b:
	/* 0x339b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_33a0:
	/* 0x33a0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_33a5:
	/* 0x33a5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_33aa:
	/* 0x33aa: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_33ad:
	/* 0x33ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33af:
	/* 0x33af: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_33b4:
	/* 0x33b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33b9:
	/* 0x33b9: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_33c1:
	/* 0x33c1: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_33c6:
	/* 0x33c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_33c9:
	/* 0x33c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cb:
	/* 0x33cb: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_33d3:
	/* 0x33d3: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_33d7:
	/* 0x33d7: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33df:
	/* 0x33df: je     3404 <tracepoint__sched__sched_process_fork+0x3404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3404;
	}
x86_l_33e1:
	/* 0x33e1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_33e8:
	/* 0x33e8: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_33ed:
	/* 0x33ed: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_33f2:
	/* 0x33f2: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_33f7:
	/* 0x33f7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_33fa:
	/* 0x33fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fc:
	/* 0x33fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33fe:
	/* 0x33fe: js     3404 <tracepoint__sched__sched_process_fork+0x3404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3404;
	}
x86_l_3400:
	/* 0x3400: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3404:
	/* 0x3404: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_340c:
	/* 0x340c: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_3411:
	/* 0x3411: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_3416:
	/* 0x3416: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_3419:
	/* 0x3419: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_341f:
	/* 0x341f: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3423:
	/* 0x3423: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_342a:
	/* 0x342a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_342f:
	/* 0x342f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3434:
	/* 0x3434: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3439:
	/* 0x3439: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_343c:
	/* 0x343c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_343f:
	/* 0x343f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3441:
	/* 0x3441: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3443:
	/* 0x3443: add    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_344a:
	/* 0x344a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_344b:
	/* 0x344b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_344d:
	/* 0x344d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_344f:
	/* 0x344f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3451:
	/* 0x3451: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3453:
	/* 0x3453: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3454:
	/* 0x3454: jmp    38e6 <tracepoint__sched__sched_process_fork+0x38e6> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3459:
	/* 0x3459: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_3460:
	/* 0x3460: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3463:
	/* 0x3463: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3467:
	/* 0x3467: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_346c:
	/* 0x346c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3471:
	/* 0x3471: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_3476:
	/* 0x3476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3478:
	/* 0x3478: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_347b:
	/* 0x347b: jne    3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3441;
	}
x86_l_347d:
	/* 0x347d: movzx  eax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3482:
	/* 0x3482: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_3487:
	/* 0x3487: jmp    b60 <tracepoint__sched__sched_process_fork+0xb60> */
	return 2912ULL;
x86_l_348c:
	/* 0x348c: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3494:
	/* 0x3494: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_349b:
	/* 0x349b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34a0:
	/* 0x34a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34a5:
	/* 0x34a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a7:
	/* 0x34a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34aa:
	/* 0x34aa: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3441;
	}
x86_l_34ac:
	/* 0x34ac: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_34af:
	/* 0x34af: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_34b9:
	/* 0x34b9: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34bc:
	/* 0x34bc: mov    QWORD PTR [rbx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34c4:
	/* 0x34c4: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_34c9:
	/* 0x34c9: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
	return 13516ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_fork_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13516ULL: goto x86_l_34cc;
	case 13520ULL: goto x86_l_34d0;
	case 13522ULL: goto x86_l_34d2;
	case 13525ULL: goto x86_l_34d5;
	case 13532ULL: goto x86_l_34dc;
	case 13542ULL: goto x86_l_34e6;
	case 13546ULL: goto x86_l_34ea;
	case 13556ULL: goto x86_l_34f4;
	case 13560ULL: goto x86_l_34f8;
	case 13570ULL: goto x86_l_3502;
	case 13574ULL: goto x86_l_3506;
	case 13584ULL: goto x86_l_3510;
	case 13588ULL: goto x86_l_3514;
	case 13592ULL: goto x86_l_3518;
	case 13600ULL: goto x86_l_3520;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13614ULL: goto x86_l_352e;
	case 13617ULL: goto x86_l_3531;
	case 13622ULL: goto x86_l_3536;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13637ULL: goto x86_l_3545;
	case 13639ULL: goto x86_l_3547;
	case 13642ULL: goto x86_l_354a;
	case 13648ULL: goto x86_l_3550;
	case 13652ULL: goto x86_l_3554;
	case 13654ULL: goto x86_l_3556;
	case 13658ULL: goto x86_l_355a;
	case 13661ULL: goto x86_l_355d;
	case 13668ULL: goto x86_l_3564;
	case 13674ULL: goto x86_l_356a;
	case 13676ULL: goto x86_l_356c;
	case 13679ULL: goto x86_l_356f;
	case 13686ULL: goto x86_l_3576;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13699ULL: goto x86_l_3583;
	case 13704ULL: goto x86_l_3588;
	case 13712ULL: goto x86_l_3590;
	case 13717ULL: goto x86_l_3595;
	case 13724ULL: goto x86_l_359c;
	case 13726ULL: goto x86_l_359e;
	case 13729ULL: goto x86_l_35a1;
	case 13734ULL: goto x86_l_35a6;
	case 13737ULL: goto x86_l_35a9;
	case 13740ULL: goto x86_l_35ac;
	case 13742ULL: goto x86_l_35ae;
	case 13744ULL: goto x86_l_35b0;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13755ULL: goto x86_l_35bb;
	case 13762ULL: goto x86_l_35c2;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13789ULL: goto x86_l_35dd;
	case 13796ULL: goto x86_l_35e4;
	case 13801ULL: goto x86_l_35e9;
	case 13806ULL: goto x86_l_35ee;
	case 13808ULL: goto x86_l_35f0;
	case 13811ULL: goto x86_l_35f3;
	case 13817ULL: goto x86_l_35f9;
	case 13820ULL: goto x86_l_35fc;
	case 13830ULL: goto x86_l_3606;
	case 13833ULL: goto x86_l_3609;
	case 13841ULL: goto x86_l_3611;
	case 13846ULL: goto x86_l_3616;
	case 13849ULL: goto x86_l_3619;
	case 13853ULL: goto x86_l_361d;
	case 13855ULL: goto x86_l_361f;
	case 13858ULL: goto x86_l_3622;
	case 13865ULL: goto x86_l_3629;
	case 13875ULL: goto x86_l_3633;
	case 13879ULL: goto x86_l_3637;
	case 13889ULL: goto x86_l_3641;
	case 13893ULL: goto x86_l_3645;
	case 13903ULL: goto x86_l_364f;
	case 13907ULL: goto x86_l_3653;
	case 13917ULL: goto x86_l_365d;
	case 13921ULL: goto x86_l_3661;
	case 13925ULL: goto x86_l_3665;
	case 13933ULL: goto x86_l_366d;
	case 13940ULL: goto x86_l_3674;
	case 13945ULL: goto x86_l_3679;
	case 13947ULL: goto x86_l_367b;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13962ULL: goto x86_l_368a;
	case 13967ULL: goto x86_l_368f;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13975ULL: goto x86_l_3697;
	case 13981ULL: goto x86_l_369d;
	case 13985ULL: goto x86_l_36a1;
	case 13987ULL: goto x86_l_36a3;
	case 13991ULL: goto x86_l_36a7;
	case 13994ULL: goto x86_l_36aa;
	case 14001ULL: goto x86_l_36b1;
	case 14007ULL: goto x86_l_36b7;
	case 14009ULL: goto x86_l_36b9;
	case 14012ULL: goto x86_l_36bc;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14029ULL: goto x86_l_36cd;
	case 14032ULL: goto x86_l_36d0;
	case 14037ULL: goto x86_l_36d5;
	case 14045ULL: goto x86_l_36dd;
	case 14050ULL: goto x86_l_36e2;
	case 14058ULL: goto x86_l_36ea;
	case 14065ULL: goto x86_l_36f1;
	case 14070ULL: goto x86_l_36f6;
	case 14075ULL: goto x86_l_36fb;
	case 14077ULL: goto x86_l_36fd;
	case 14080ULL: goto x86_l_3700;
	case 14086ULL: goto x86_l_3706;
	case 14089ULL: goto x86_l_3709;
	case 14099ULL: goto x86_l_3713;
	case 14102ULL: goto x86_l_3716;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14118ULL: goto x86_l_3726;
	case 14122ULL: goto x86_l_372a;
	case 14124ULL: goto x86_l_372c;
	case 14127ULL: goto x86_l_372f;
	case 14134ULL: goto x86_l_3736;
	case 14144ULL: goto x86_l_3740;
	case 14148ULL: goto x86_l_3744;
	case 14158ULL: goto x86_l_374e;
	case 14162ULL: goto x86_l_3752;
	case 14172ULL: goto x86_l_375c;
	case 14176ULL: goto x86_l_3760;
	case 14186ULL: goto x86_l_376a;
	case 14190ULL: goto x86_l_376e;
	case 14194ULL: goto x86_l_3772;
	case 14202ULL: goto x86_l_377a;
	case 14209ULL: goto x86_l_3781;
	case 14214ULL: goto x86_l_3786;
	case 14216ULL: goto x86_l_3788;
	case 14219ULL: goto x86_l_378b;
	case 14224ULL: goto x86_l_3790;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14239ULL: goto x86_l_379f;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14254ULL: goto x86_l_37ae;
	case 14256ULL: goto x86_l_37b0;
	case 14260ULL: goto x86_l_37b4;
	case 14263ULL: goto x86_l_37b7;
	case 14270ULL: goto x86_l_37be;
	case 14276ULL: goto x86_l_37c4;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14288ULL: goto x86_l_37d0;
	case 14293ULL: goto x86_l_37d5;
	case 14298ULL: goto x86_l_37da;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14325ULL: goto x86_l_37f5;
	case 14328ULL: goto x86_l_37f8;
	case 14330ULL: goto x86_l_37fa;
	case 14337ULL: goto x86_l_3801;
	case 14342ULL: goto x86_l_3806;
	case 14349ULL: goto x86_l_380d;
	case 14351ULL: goto x86_l_380f;
	case 14356ULL: goto x86_l_3814;
	case 14359ULL: goto x86_l_3817;
	case 14362ULL: goto x86_l_381a;
	case 14365ULL: goto x86_l_381d;
	case 14367ULL: goto x86_l_381f;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14377ULL: goto x86_l_3829;
	case 14384ULL: goto x86_l_3830;
	case 14390ULL: goto x86_l_3836;
	case 14395ULL: goto x86_l_383b;
	case 14402ULL: goto x86_l_3842;
	case 14405ULL: goto x86_l_3845;
	case 14408ULL: goto x86_l_3848;
	case 14413ULL: goto x86_l_384d;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14421ULL: goto x86_l_3855;
	case 14423ULL: goto x86_l_3857;
	case 14426ULL: goto x86_l_385a;
	case 14431ULL: goto x86_l_385f;
	case 14434ULL: goto x86_l_3862;
	case 14441ULL: goto x86_l_3869;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14459ULL: goto x86_l_387b;
	case 14462ULL: goto x86_l_387e;
	case 14465ULL: goto x86_l_3881;
	case 14470ULL: goto x86_l_3886;
	case 14473ULL: goto x86_l_3889;
	case 14476ULL: goto x86_l_388c;
	case 14478ULL: goto x86_l_388e;
	case 14480ULL: goto x86_l_3890;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14491ULL: goto x86_l_389b;
	case 14498ULL: goto x86_l_38a2;
	case 14504ULL: goto x86_l_38a8;
	case 14509ULL: goto x86_l_38ad;
	case 14516ULL: goto x86_l_38b4;
	case 14519ULL: goto x86_l_38b7;
	case 14522ULL: goto x86_l_38ba;
	case 14527ULL: goto x86_l_38bf;
	case 14530ULL: goto x86_l_38c2;
	case 14533ULL: goto x86_l_38c5;
	case 14535ULL: goto x86_l_38c7;
	case 14537ULL: goto x86_l_38c9;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14548ULL: goto x86_l_38d4;
	case 14555ULL: goto x86_l_38db;
	case 14561ULL: goto x86_l_38e1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_34cc:
	/* 0x34cc: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34d0:
	/* 0x34d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d2:
	/* 0x34d2: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34d5:
	/* 0x34d5: mov    DWORD PTR [rbx+0x1c],0x281 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084929ULL);
x86_l_34dc:
	/* 0x34dc: movabs rax,0x702f656563617274 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8083791342286762612ULL);
x86_l_34e6:
	/* 0x34e6: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ea:
	/* 0x34ea: movabs rax,0x2f667062652f676b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3415540935313811307ULL);
x86_l_34f4:
	/* 0x34f4: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34f8:
	/* 0x34f8: movabs rax,0x6565636172742f63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306355240661692259ULL);
x86_l_3502:
	/* 0x3502: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3506:
	/* 0x3506: movabs rax,0x632e6670622e6565 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7146762291553133925ULL);
x86_l_3510:
	/* 0x3510: mov    QWORD PTR [rbx+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3514:
	/* 0x3514: mov    BYTE PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_3518:
	/* 0x3518: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3520:
	/* 0x3520: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3527:
	/* 0x3527: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_352c:
	/* 0x352c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_352e:
	/* 0x352e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3531:
	/* 0x3531: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3536:
	/* 0x3536: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_353d:
	/* 0x353d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3542:
	/* 0x3542: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3545:
	/* 0x3545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3547:
	/* 0x3547: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_354a:
	/* 0x354a: je     383b <tracepoint__sched__sched_process_fork+0x383b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_383b;
	}
x86_l_3550:
	/* 0x3550: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3554:
	/* 0x3554: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3556:
	/* 0x3556: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355a:
	/* 0x355a: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_355d:
	/* 0x355d: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_3564:
	/* 0x3564: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_356a:
	/* 0x356a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_356c:
	/* 0x356c: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_356f:
	/* 0x356f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_3576:
	/* 0x3576: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_357b:
	/* 0x357b: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_3580:
	/* 0x3580: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3583:
	/* 0x3583: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3588:
	/* 0x3588: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3590:
	/* 0x3590: jmp    37ea <tracepoint__sched__sched_process_fork+0x37ea> */
	goto x86_l_37ea;
x86_l_3595:
	/* 0x3595: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_359c:
	/* 0x359c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_359e:
	/* 0x359e: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_35a1:
	/* 0x35a1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35a6:
	/* 0x35a6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35a9:
	/* 0x35a9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35ac:
	/* 0x35ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35ae:
	/* 0x35ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b0:
	/* 0x35b0: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_35b3:
	/* 0x35b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b8:
	/* 0x35b8: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_35bb:
	/* 0x35bb: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_35c2:
	/* 0x35c2: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_35ca:
	/* 0x35ca: jae    ebb <tracepoint__sched__sched_process_fork+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3771ULL;
	}
x86_l_35d0:
	/* 0x35d0: jmp    ef9 <tracepoint__sched__sched_process_fork+0xef9> */
	return 3833ULL;
x86_l_35d5:
	/* 0x35d5: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_35dd:
	/* 0x35dd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_35e4:
	/* 0x35e4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35e9:
	/* 0x35e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35ee:
	/* 0x35ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f0:
	/* 0x35f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35f3:
	/* 0x35f3: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_35f9:
	/* 0x35f9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_35fc:
	/* 0x35fc: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_3606:
	/* 0x3606: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3609:
	/* 0x3609: mov    QWORD PTR [rbx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3611:
	/* 0x3611: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3616:
	/* 0x3616: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_3619:
	/* 0x3619: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_361d:
	/* 0x361d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361f:
	/* 0x361f: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3622:
	/* 0x3622: mov    DWORD PTR [rbx+0x1c],0x296 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084950ULL);
x86_l_3629:
	/* 0x3629: movabs rax,0x702f656563617274 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8083791342286762612ULL);
x86_l_3633:
	/* 0x3633: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3637:
	/* 0x3637: movabs rax,0x2f667062652f676b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3415540935313811307ULL);
x86_l_3641:
	/* 0x3641: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3645:
	/* 0x3645: movabs rax,0x6565636172742f63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306355240661692259ULL);
x86_l_364f:
	/* 0x364f: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3653:
	/* 0x3653: movabs rax,0x632e6670622e6565 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7146762291553133925ULL);
x86_l_365d:
	/* 0x365d: mov    QWORD PTR [rbx+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3661:
	/* 0x3661: mov    BYTE PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_3665:
	/* 0x3665: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_366d:
	/* 0x366d: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3674:
	/* 0x3674: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3679:
	/* 0x3679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367b:
	/* 0x367b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_367e:
	/* 0x367e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3683:
	/* 0x3683: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_368a:
	/* 0x368a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368f:
	/* 0x368f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3692:
	/* 0x3692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3694:
	/* 0x3694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3697:
	/* 0x3697: je     3874 <tracepoint__sched__sched_process_fork+0x3874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3874;
	}
x86_l_369d:
	/* 0x369d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a1:
	/* 0x36a1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_36a3:
	/* 0x36a3: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a7:
	/* 0x36a7: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36aa:
	/* 0x36aa: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_36b1:
	/* 0x36b1: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_36b7:
	/* 0x36b7: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b9:
	/* 0x36b9: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36bc:
	/* 0x36bc: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_36c3:
	/* 0x36c3: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_36c8:
	/* 0x36c8: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_36cd:
	/* 0x36cd: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_36d0:
	/* 0x36d0: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_36d5:
	/* 0x36d5: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_36dd:
	/* 0x36dd: jmp    37ea <tracepoint__sched__sched_process_fork+0x37ea> */
	goto x86_l_37ea;
x86_l_36e2:
	/* 0x36e2: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_36ea:
	/* 0x36ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_36f1:
	/* 0x36f1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36f6:
	/* 0x36f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36fb:
	/* 0x36fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36fd:
	/* 0x36fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3700:
	/* 0x3700: je     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13377ULL;
	}
x86_l_3706:
	/* 0x3706: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3709:
	/* 0x3709: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_3713:
	/* 0x3713: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3716:
	/* 0x3716: mov    QWORD PTR [rbx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_371e:
	/* 0x371e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3723:
	/* 0x3723: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_3726:
	/* 0x3726: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_372a:
	/* 0x372a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372c:
	/* 0x372c: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_372f:
	/* 0x372f: mov    DWORD PTR [rbx+0x1c],0x29e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084958ULL);
x86_l_3736:
	/* 0x3736: movabs rax,0x702f656563617274 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8083791342286762612ULL);
x86_l_3740:
	/* 0x3740: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3744:
	/* 0x3744: movabs rax,0x2f667062652f676b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3415540935313811307ULL);
x86_l_374e:
	/* 0x374e: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3752:
	/* 0x3752: movabs rax,0x6565636172742f63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306355240661692259ULL);
x86_l_375c:
	/* 0x375c: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3760:
	/* 0x3760: movabs rax,0x632e6670622e6565 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7146762291553133925ULL);
x86_l_376a:
	/* 0x376a: mov    QWORD PTR [rbx+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_376e:
	/* 0x376e: mov    BYTE PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_3772:
	/* 0x3772: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_377a:
	/* 0x377a: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3781:
	/* 0x3781: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3786:
	/* 0x3786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3788:
	/* 0x3788: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_378b:
	/* 0x378b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3790:
	/* 0x3790: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3797:
	/* 0x3797: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_379c:
	/* 0x379c: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_379f:
	/* 0x379f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37a1:
	/* 0x37a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37a4:
	/* 0x37a4: je     38ad <tracepoint__sched__sched_process_fork+0x38ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ad;
	}
x86_l_37aa:
	/* 0x37aa: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37ae:
	/* 0x37ae: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_37b0:
	/* 0x37b0: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37b4:
	/* 0x37b4: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37b7:
	/* 0x37b7: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_37be:
	/* 0x37be: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_37c4:
	/* 0x37c4: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c6:
	/* 0x37c6: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c9:
	/* 0x37c9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_37d0:
	/* 0x37d0: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_37d5:
	/* 0x37d5: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_37da:
	/* 0x37da: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_37dd:
	/* 0x37dd: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_37e2:
	/* 0x37e2: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_37ea:
	/* 0x37ea: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_37ef:
	/* 0x37ef: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_37f5:
	/* 0x37f5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37f8:
	/* 0x37f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37fa:
	/* 0x37fa: mov    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3801:
	/* 0x3801: jmp    3441 <tracepoint__sched__sched_process_fork+0x3441> */
	return 13377ULL;
x86_l_3806:
	/* 0x3806: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_380d:
	/* 0x380d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_380f:
	/* 0x380f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3814:
	/* 0x3814: mov    rbp,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSP, X86_WIDTH_64);
x86_l_3817:
	/* 0x3817: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_381a:
	/* 0x381a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_381d:
	/* 0x381d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_381f:
	/* 0x381f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3821:
	/* 0x3821: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3826:
	/* 0x3826: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3829:
	/* 0x3829: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_3830:
	/* 0x3830: jae    1c65 <tracepoint__sched__sched_process_fork+0x1c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7269ULL;
	}
x86_l_3836:
	/* 0x3836: jmp    1ca1 <tracepoint__sched__sched_process_fork+0x1ca1> */
	return 7329ULL;
x86_l_383b:
	/* 0x383b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3842:
	/* 0x3842: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3845:
	/* 0x3845: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_3848:
	/* 0x3848: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_384d:
	/* 0x384d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3850:
	/* 0x3850: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3853:
	/* 0x3853: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3855:
	/* 0x3855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3857:
	/* 0x3857: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_385a:
	/* 0x385a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_385f:
	/* 0x385f: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3862:
	/* 0x3862: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_3869:
	/* 0x3869: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_386f:
	/* 0x386f: jmp    356a <tracepoint__sched__sched_process_fork+0x356a> */
	goto x86_l_356a;
x86_l_3874:
	/* 0x3874: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_387b:
	/* 0x387b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_387e:
	/* 0x387e: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_3881:
	/* 0x3881: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3886:
	/* 0x3886: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3889:
	/* 0x3889: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_388c:
	/* 0x388c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_388e:
	/* 0x388e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3890:
	/* 0x3890: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_3893:
	/* 0x3893: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3898:
	/* 0x3898: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_389b:
	/* 0x389b: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_38a2:
	/* 0x38a2: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_38a8:
	/* 0x38a8: jmp    36b7 <tracepoint__sched__sched_process_fork+0x36b7> */
	goto x86_l_36b7;
x86_l_38ad:
	/* 0x38ad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_38b4:
	/* 0x38b4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38b7:
	/* 0x38b7: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_38ba:
	/* 0x38ba: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38bf:
	/* 0x38bf: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_38c2:
	/* 0x38c2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_38c5:
	/* 0x38c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38c7:
	/* 0x38c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38c9:
	/* 0x38c9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_38cc:
	/* 0x38cc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38d1:
	/* 0x38d1: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38d4:
	/* 0x38d4: cmp    r15,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 2000000001ULL);
x86_l_38db:
	/* 0x38db: jb     3441 <tracepoint__sched__sched_process_fork+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13377ULL;
	}
x86_l_38e1:
	/* 0x38e1: jmp    37c4 <tracepoint__sched__sched_process_fork+0x37c4> */
	goto x86_l_37c4;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_tracepoint__sched__sched_process_fork_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13172U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2088ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2093ULL && __x86_pc <= 3747ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3751ULL && __x86_pc <= 5360ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5366ULL && __x86_pc <= 6880ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6884ULL && __x86_pc <= 8484ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8487ULL && __x86_pc <= 10119ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10127ULL && __x86_pc <= 11909ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11911ULL && __x86_pc <= 13513ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13516ULL && __x86_pc <= 14561ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_fork_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

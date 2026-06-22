extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char prog_array_tp;
extern char scratch_map;
extern char sys_32_to_64_map;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_0(
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
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 234ULL: goto x86_l_ea;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 248ULL: goto x86_l_f8;
	case 251ULL: goto x86_l_fb;
	case 261ULL: goto x86_l_105;
	case 269ULL: goto x86_l_10d;
	case 280ULL: goto x86_l_118;
	case 291ULL: goto x86_l_123;
	case 302ULL: goto x86_l_12e;
	case 313ULL: goto x86_l_139;
	case 324ULL: goto x86_l_144;
	case 335ULL: goto x86_l_14f;
	case 346ULL: goto x86_l_15a;
	case 357ULL: goto x86_l_165;
	case 364ULL: goto x86_l_16c;
	case 372ULL: goto x86_l_174;
	case 380ULL: goto x86_l_17c;
	case 388ULL: goto x86_l_184;
	case 396ULL: goto x86_l_18c;
	case 404ULL: goto x86_l_194;
	case 412ULL: goto x86_l_19c;
	case 420ULL: goto x86_l_1a4;
	case 428ULL: goto x86_l_1ac;
	case 436ULL: goto x86_l_1b4;
	case 444ULL: goto x86_l_1bc;
	case 452ULL: goto x86_l_1c4;
	case 460ULL: goto x86_l_1cc;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 475ULL: goto x86_l_1db;
	case 479ULL: goto x86_l_1df;
	case 483ULL: goto x86_l_1e3;
	case 487ULL: goto x86_l_1e7;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 521ULL: goto x86_l_209;
	case 525ULL: goto x86_l_20d;
	case 532ULL: goto x86_l_214;
	case 537ULL: goto x86_l_219;
	case 544ULL: goto x86_l_220;
	case 552ULL: goto x86_l_228;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 566ULL: goto x86_l_236;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 585ULL: goto x86_l_249;
	case 593ULL: goto x86_l_251;
	case 595ULL: goto x86_l_253;
	case 598ULL: goto x86_l_256;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 614ULL: goto x86_l_266;
	case 620ULL: goto x86_l_26c;
	case 624ULL: goto x86_l_270;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 649ULL: goto x86_l_289;
	case 653ULL: goto x86_l_28d;
	case 661ULL: goto x86_l_295;
	case 666ULL: goto x86_l_29a;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
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
	case 1035ULL: goto x86_l_40b;
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
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1177ULL: goto x86_l_499;
	case 1180ULL: goto x86_l_49c;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1213ULL: goto x86_l_4bd;
	case 1218ULL: goto x86_l_4c2;
	case 1225ULL: goto x86_l_4c9;
	case 1229ULL: goto x86_l_4cd;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1265ULL: goto x86_l_4f1;
	case 1269ULL: goto x86_l_4f5;
	case 1273ULL: goto x86_l_4f9;
	case 1284ULL: goto x86_l_504;
	case 1295ULL: goto x86_l_50f;
	case 1306ULL: goto x86_l_51a;
	case 1317ULL: goto x86_l_525;
	case 1328ULL: goto x86_l_530;
	case 1339ULL: goto x86_l_53b;
	case 1350ULL: goto x86_l_546;
	case 1361ULL: goto x86_l_551;
	case 1372ULL: goto x86_l_55c;
	case 1380ULL: goto x86_l_564;
	case 1388ULL: goto x86_l_56c;
	case 1396ULL: goto x86_l_574;
	case 1404ULL: goto x86_l_57c;
	case 1412ULL: goto x86_l_584;
	case 1420ULL: goto x86_l_58c;
	case 1428ULL: goto x86_l_594;
	case 1436ULL: goto x86_l_59c;
	case 1444ULL: goto x86_l_5a4;
	case 1452ULL: goto x86_l_5ac;
	case 1460ULL: goto x86_l_5b4;
	case 1468ULL: goto x86_l_5bc;
	case 1476ULL: goto x86_l_5c4;
	case 1484ULL: goto x86_l_5cc;
	case 1492ULL: goto x86_l_5d4;
	case 1499ULL: goto x86_l_5db;
	case 1505ULL: goto x86_l_5e1;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1522ULL: goto x86_l_5f2;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1544ULL: goto x86_l_608;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1565ULL: goto x86_l_61d;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1587ULL: goto x86_l_633;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1673ULL: goto x86_l_689;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1708ULL: goto x86_l_6ac;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1735ULL: goto x86_l_6c7;
	case 1739ULL: goto x86_l_6cb;
	case 1743ULL: goto x86_l_6cf;
	case 1747ULL: goto x86_l_6d3;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1768ULL: goto x86_l_6e8;
	case 1772ULL: goto x86_l_6ec;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1855ULL: goto x86_l_73f;
	case 1859ULL: goto x86_l_743;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1880ULL: goto x86_l_758;
	case 1884ULL: goto x86_l_75c;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2052ULL: goto x86_l_804;
	case 2054ULL: goto x86_l_806;
	case 2058ULL: goto x86_l_80a;
	case 2062ULL: goto x86_l_80e;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2111ULL: goto x86_l_83f;
	case 2113ULL: goto x86_l_841;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 216ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0xc8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_12:
	/* 0x12: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_17:
	/* 0x17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19:
	/* 0x19: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1c:
	/* 0x1c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_21:
	/* 0x21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23:
	/* 0x23: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
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
	/* 0x48: jne    ba <tracepoint__sched__sched_process_exec+0xba> */
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
	/* 0x74: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x87: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_91:
	/* 0x91: jne    99 <tracepoint__sched__sched_process_exec+0x99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_99;
	}
x86_l_93:
	/* 0x93: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97:
	/* 0x97: jmp    ba <tracepoint__sched__sched_process_exec+0xba> */
	goto x86_l_ba;
x86_l_99:
	/* 0x99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e:
	/* 0x9e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_a5:
	/* 0xa5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa:
	/* 0xaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac:
	/* 0xac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af:
	/* 0xaf: je     b5 <tracepoint__sched__sched_process_exec+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5;
	}
x86_l_b1:
	/* 0xb1: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3:
	/* 0xb3: jmp    ba <tracepoint__sched__sched_process_exec+0xba> */
	goto x86_l_ba;
x86_l_b5:
	/* 0xb5: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_ba:
	/* 0xba: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1:
	/* 0xc1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c6:
	/* 0xc6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_cd:
	/* 0xcd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d0:
	/* 0xd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11147ULL;
	}
x86_l_db:
	/* 0xdb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3:
	/* 0xe3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_ea:
	/* 0xea: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11147ULL;
	}
x86_l_f8:
	/* 0xf8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_105:
	/* 0x105: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_118:
	/* 0x118: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_123:
	/* 0x123: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_14f:
	/* 0x14f: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_15a:
	/* 0x15a: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_165:
	/* 0x165: mov    QWORD PTR [r14+0x7dd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_16c:
	/* 0x16c: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_174:
	/* 0x174: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17c:
	/* 0x17c: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_194:
	/* 0x194: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a4:
	/* 0x1a4: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1bc:
	/* 0x1bc: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c4:
	/* 0x1c4: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d9:
	/* 0x1d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db:
	/* 0x1db: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1df:
	/* 0x1df: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e3:
	/* 0x1e3: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e7:
	/* 0x1e7: mov    DWORD PTR [r14+0x70],0x2cb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337867ULL);
x86_l_1ef:
	/* 0x1ef: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f4:
	/* 0x1f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9:
	/* 0x1f9: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_205:
	/* 0x205: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_209:
	/* 0x209: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20d:
	/* 0x20d: mov    DWORD PTR [rsp+0x9c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_214:
	/* 0x214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_228:
	/* 0x228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a:
	/* 0x22a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_230:
	/* 0x230: je     282 <tracepoint__sched__sched_process_exec+0x282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_282;
	}
x86_l_232:
	/* 0x232: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_236:
	/* 0x236: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_23d:
	/* 0x23d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242:
	/* 0x242: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_249:
	/* 0x249: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_251:
	/* 0x251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253:
	/* 0x253: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_256:
	/* 0x256: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_259:
	/* 0x259: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_266:
	/* 0x266: je     4c2 <tracepoint__sched__sched_process_exec+0x4c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c2;
	}
x86_l_26c:
	/* 0x26c: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_270:
	/* 0x270: jne    a1a <tracepoint__sched__sched_process_exec+0xa1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2586ULL;
	}
x86_l_276:
	/* 0x276: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_27b:
	/* 0x27b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d:
	/* 0x27d: jmp    aa1 <tracepoint__sched__sched_process_exec+0xaa1> */
	return 2721ULL;
x86_l_282:
	/* 0x282: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_289:
	/* 0x289: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d:
	/* 0x28d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_295:
	/* 0x295: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29a:
	/* 0x29a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2a1:
	/* 0x2a1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6:
	/* 0x2a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8:
	/* 0x2a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: je     2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11147ULL;
	}
x86_l_2b1:
	/* 0x2b1: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5:
	/* 0x2b5: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b9:
	/* 0x2b9: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2c4:
	/* 0x2c4: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2cf:
	/* 0x2cf: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2da:
	/* 0x2da: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_306:
	/* 0x306: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_311:
	/* 0x311: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_31c:
	/* 0x31c: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_327:
	/* 0x327: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_332:
	/* 0x332: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_33d:
	/* 0x33d: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_348:
	/* 0x348: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_353:
	/* 0x353: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_35e:
	/* 0x35e: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_369:
	/* 0x369: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_374:
	/* 0x374: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_37f:
	/* 0x37f: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_38a:
	/* 0x38a: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_395:
	/* 0x395: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3c1:
	/* 0x3c1: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3cc:
	/* 0x3cc: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3e2:
	/* 0x3e2: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3ed:
	/* 0x3ed: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3f8:
	/* 0x3f8: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_403:
	/* 0x403: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_413:
	/* 0x413: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_43b:
	/* 0x43b: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_44b:
	/* 0x44b: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_453:
	/* 0x453: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_473:
	/* 0x473: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482:
	/* 0x482: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_488:
	/* 0x488: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_48f:
	/* 0x48f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_494:
	/* 0x494: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_499:
	/* 0x499: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_49c:
	/* 0x49c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_49f:
	/* 0x49f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4a2:
	/* 0x4a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a7:
	/* 0x4a7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac:
	/* 0x4ac: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4af:
	/* 0x4af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1:
	/* 0x4b1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: jne    232 <tracepoint__sched__sched_process_exec+0x232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_232;
	}
x86_l_4bd:
	/* 0x4bd: jmp    2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	return 11147ULL;
x86_l_4c2:
	/* 0x4c2: mov    eax,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_4c9:
	/* 0x4c9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd:
	/* 0x4cd: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d5:
	/* 0x4d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4da:
	/* 0x4da: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4e1:
	/* 0x4e1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e6:
	/* 0x4e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8:
	/* 0x4e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: je     2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11147ULL;
	}
x86_l_4f1:
	/* 0x4f1: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f5:
	/* 0x4f5: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f9:
	/* 0x4f9: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_504:
	/* 0x504: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_50f:
	/* 0x50f: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_51a:
	/* 0x51a: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_546:
	/* 0x546: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_551:
	/* 0x551: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_564:
	/* 0x564: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_574:
	/* 0x574: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_57c:
	/* 0x57c: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_584:
	/* 0x584: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_58c:
	/* 0x58c: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b4:
	/* 0x5b4: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5bc:
	/* 0x5bc: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5c4:
	/* 0x5c4: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5cc:
	/* 0x5cc: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d4:
	/* 0x5d4: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db:
	/* 0x5db: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5e1:
	/* 0x5e1: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5e8:
	/* 0x5e8: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ed:
	/* 0x5ed: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5f2:
	/* 0x5f2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_5f5:
	/* 0x5f5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5f8:
	/* 0x5f8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5fb:
	/* 0x5fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_600:
	/* 0x600: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_605:
	/* 0x605: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_608:
	/* 0x608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a:
	/* 0x60a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: je     2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11147ULL;
	}
x86_l_613:
	/* 0x613: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_616:
	/* 0x616: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_61d:
	/* 0x61d: lea    rbp,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_621:
	/* 0x621: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_626:
	/* 0x626: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62b:
	/* 0x62b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_630:
	/* 0x630: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_633:
	/* 0x633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_635:
	/* 0x635: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_63a:
	/* 0x63a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63f:
	/* 0x63f: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_643:
	/* 0x643: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_648:
	/* 0x648: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64d:
	/* 0x64d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_652:
	/* 0x652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_654:
	/* 0x654: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_659:
	/* 0x659: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_65d:
	/* 0x65d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_662:
	/* 0x662: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_667:
	/* 0x667: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66c:
	/* 0x66c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66e:
	/* 0x66e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_673:
	/* 0x673: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_678:
	/* 0x678: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67d:
	/* 0x67d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_682:
	/* 0x682: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_687:
	/* 0x687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_689:
	/* 0x689: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68d:
	/* 0x68d: mov    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_691:
	/* 0x691: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_696:
	/* 0x696: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_69a:
	/* 0x69a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69f:
	/* 0x69f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a4:
	/* 0x6a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a9:
	/* 0x6a9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6ac:
	/* 0x6ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ae:
	/* 0x6ae: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b3:
	/* 0x6b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b8:
	/* 0x6b8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6bd:
	/* 0x6bd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c2:
	/* 0x6c2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c7:
	/* 0x6c7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6cb:
	/* 0x6cb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6cf:
	/* 0x6cf: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_6d3:
	/* 0x6d3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6d7:
	/* 0x6d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6dc:
	/* 0x6dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e1:
	/* 0x6e1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e6:
	/* 0x6e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e8:
	/* 0x6e8: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ec:
	/* 0x6ec: mov    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6f0:
	/* 0x6f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f5:
	/* 0x6f5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6fa:
	/* 0x6fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ff:
	/* 0x6ff: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_702:
	/* 0x702: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_704:
	/* 0x704: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_709:
	/* 0x709: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_712:
	/* 0x712: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_717:
	/* 0x717: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71c:
	/* 0x71c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71e:
	/* 0x71e: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_723:
	/* 0x723: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_728:
	/* 0x728: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_72d:
	/* 0x72d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_732:
	/* 0x732: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_73b:
	/* 0x73b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_73f:
	/* 0x73f: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_743:
	/* 0x743: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_747:
	/* 0x747: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74c:
	/* 0x74c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_751:
	/* 0x751: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_756:
	/* 0x756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_758:
	/* 0x758: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75c:
	/* 0x75c: mov    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_760:
	/* 0x760: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_765:
	/* 0x765: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_76a:
	/* 0x76a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76f:
	/* 0x76f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_772:
	/* 0x772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_774:
	/* 0x774: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_779:
	/* 0x779: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_77e:
	/* 0x77e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_783:
	/* 0x783: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_788:
	/* 0x788: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_78b:
	/* 0x78b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78d:
	/* 0x78d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_791:
	/* 0x791: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_795:
	/* 0x795: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_799:
	/* 0x799: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_79d:
	/* 0x79d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a2:
	/* 0x7a2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a7:
	/* 0x7a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7b3:
	/* 0x7b3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7b7:
	/* 0x7b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7bc:
	/* 0x7bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c1:
	/* 0x7c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c6:
	/* 0x7c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c8:
	/* 0x7c8: mov    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7cc:
	/* 0x7cc: mov    QWORD PTR [rsp+0xa8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7d4:
	/* 0x7d4: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d9:
	/* 0x7d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7de:
	/* 0x7de: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7e3:
	/* 0x7e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e8:
	/* 0x7e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7eb:
	/* 0x7eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ed:
	/* 0x7ed: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f2:
	/* 0x7f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f7:
	/* 0x7f7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7fc:
	/* 0x7fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_801:
	/* 0x801: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_804:
	/* 0x804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_806:
	/* 0x806: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_80a:
	/* 0x80a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_80e:
	/* 0x80e: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_812:
	/* 0x812: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_816:
	/* 0x816: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_81b:
	/* 0x81b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_820:
	/* 0x820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_825:
	/* 0x825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_827:
	/* 0x827: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82c:
	/* 0x82c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_830:
	/* 0x830: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_835:
	/* 0x835: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83a:
	/* 0x83a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_83f:
	/* 0x83f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_841:
	/* 0x841: cmp    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_845:
	/* 0x845: jne    89d <tracepoint__sched__sched_process_exec+0x89d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2205ULL;
	}
x86_l_847:
	/* 0x847: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_84c:
	/* 0x84c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_851:
	/* 0x851: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_856:
	/* 0x856: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
	return 2137ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2137ULL: goto x86_l_859;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2164ULL: goto x86_l_874;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2176ULL: goto x86_l_880;
	case 2180ULL: goto x86_l_884;
	case 2185ULL: goto x86_l_889;
	case 2190ULL: goto x86_l_88e;
	case 2195ULL: goto x86_l_893;
	case 2197ULL: goto x86_l_895;
	case 2201ULL: goto x86_l_899;
	case 2205ULL: goto x86_l_89d;
	case 2209ULL: goto x86_l_8a1;
	case 2214ULL: goto x86_l_8a6;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2236ULL: goto x86_l_8bc;
	case 2239ULL: goto x86_l_8bf;
	case 2241ULL: goto x86_l_8c1;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2304ULL: goto x86_l_900;
	case 2308ULL: goto x86_l_904;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2372ULL: goto x86_l_944;
	case 2380ULL: goto x86_l_94c;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2451ULL: goto x86_l_993;
	case 2459ULL: goto x86_l_99b;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2497ULL: goto x86_l_9c1;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2566ULL: goto x86_l_a06;
	case 2568ULL: goto x86_l_a08;
	case 2576ULL: goto x86_l_a10;
	case 2580ULL: goto x86_l_a14;
	case 2586ULL: goto x86_l_a1a;
	case 2591ULL: goto x86_l_a1f;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2719ULL: goto x86_l_a9f;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2729ULL: goto x86_l_aa9;
	case 2733ULL: goto x86_l_aad;
	case 2738ULL: goto x86_l_ab2;
	case 2745ULL: goto x86_l_ab9;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2757ULL: goto x86_l_ac5;
	case 2760ULL: goto x86_l_ac8;
	case 2767ULL: goto x86_l_acf;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2789ULL: goto x86_l_ae5;
	case 2795ULL: goto x86_l_aeb;
	case 2806ULL: goto x86_l_af6;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2824ULL: goto x86_l_b08;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2838ULL: goto x86_l_b16;
	case 2841ULL: goto x86_l_b19;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2858ULL: goto x86_l_b2a;
	case 2861ULL: goto x86_l_b2d;
	case 2863ULL: goto x86_l_b2f;
	case 2867ULL: goto x86_l_b33;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2884ULL: goto x86_l_b44;
	case 2888ULL: goto x86_l_b48;
	case 2892ULL: goto x86_l_b4c;
	case 2899ULL: goto x86_l_b53;
	case 2906ULL: goto x86_l_b5a;
	case 2910ULL: goto x86_l_b5e;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2928ULL: goto x86_l_b70;
	case 2932ULL: goto x86_l_b74;
	case 2939ULL: goto x86_l_b7b;
	case 2943ULL: goto x86_l_b7f;
	case 2950ULL: goto x86_l_b86;
	case 2957ULL: goto x86_l_b8d;
	case 2964ULL: goto x86_l_b94;
	case 2975ULL: goto x86_l_b9f;
	case 2986ULL: goto x86_l_baa;
	case 2994ULL: goto x86_l_bb2;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3092ULL: goto x86_l_c14;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3190ULL: goto x86_l_c76;
	case 3198ULL: goto x86_l_c7e;
	case 3200ULL: goto x86_l_c80;
	case 3204ULL: goto x86_l_c84;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3261ULL: goto x86_l_cbd;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3276ULL: goto x86_l_ccc;
	case 3282ULL: goto x86_l_cd2;
	case 3290ULL: goto x86_l_cda;
	case 3294ULL: goto x86_l_cde;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3325ULL: goto x86_l_cfd;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3563ULL: goto x86_l_deb;
	case 3569ULL: goto x86_l_df1;
	case 3574ULL: goto x86_l_df6;
	case 3577ULL: goto x86_l_df9;
	case 3583ULL: goto x86_l_dff;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3615ULL: goto x86_l_e1f;
	case 3621ULL: goto x86_l_e25;
	case 3623ULL: goto x86_l_e27;
	case 3625ULL: goto x86_l_e29;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3646ULL: goto x86_l_e3e;
	case 3649ULL: goto x86_l_e41;
	case 3655ULL: goto x86_l_e47;
	case 3663ULL: goto x86_l_e4f;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3745ULL: goto x86_l_ea1;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3783ULL: goto x86_l_ec7;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3857ULL: goto x86_l_f11;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_859:
	/* 0x859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85b:
	/* 0x85b: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_860:
	/* 0x860: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_865:
	/* 0x865: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86a:
	/* 0x86a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_86f:
	/* 0x86f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_872:
	/* 0x872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_874:
	/* 0x874: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_878:
	/* 0x878: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_87c:
	/* 0x87c: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_880:
	/* 0x880: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_884:
	/* 0x884: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_889:
	/* 0x889: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88e:
	/* 0x88e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_893:
	/* 0x893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_895:
	/* 0x895: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_899:
	/* 0x899: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_89d:
	/* 0x89d: mov    DWORD PTR [r15+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a1:
	/* 0x8a1: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8a6:
	/* 0x8a6: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8ad:
	/* 0x8ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b2:
	/* 0x8b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b7:
	/* 0x8b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8bc:
	/* 0x8bc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8bf:
	/* 0x8bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c1:
	/* 0x8c1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c6:
	/* 0x8c6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8ca:
	/* 0x8ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d4:
	/* 0x8d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d9:
	/* 0x8d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8db:
	/* 0x8db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e5:
	/* 0x8e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ea:
	/* 0x8ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8ef:
	/* 0x8ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f1:
	/* 0x8f1: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f5:
	/* 0x8f5: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8f9:
	/* 0x8f9: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_8fe:
	/* 0x8fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_900:
	/* 0x900: mov    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_904:
	/* 0x904: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_908:
	/* 0x908: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_90d:
	/* 0x90d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_912:
	/* 0x912: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_917:
	/* 0x917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_919:
	/* 0x919: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_91e:
	/* 0x91e: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_921:
	/* 0x921: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_926:
	/* 0x926: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_92a:
	/* 0x92a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92f:
	/* 0x92f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_934:
	/* 0x934: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_939:
	/* 0x939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93b:
	/* 0x93b: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_940:
	/* 0x940: mov    QWORD PTR [r15+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_944:
	/* 0x944: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_94c:
	/* 0x94c: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_950:
	/* 0x950: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_955:
	/* 0x955: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95a:
	/* 0x95a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95f:
	/* 0x95f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_961:
	/* 0x961: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_966:
	/* 0x966: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_96a:
	/* 0x96a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96f:
	/* 0x96f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_974:
	/* 0x974: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_979:
	/* 0x979: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97e:
	/* 0x97e: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_983:
	/* 0x983: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_988:
	/* 0x988: je     98f <tracepoint__sched__sched_process_exec+0x98f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98f;
	}
x86_l_98a:
	/* 0x98a: or     BYTE PTR [r15+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_98f:
	/* 0x98f: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_993:
	/* 0x993: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_99b:
	/* 0x99b: mov    QWORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_9a3:
	/* 0x9a3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_9a8:
	/* 0x9a8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9ad:
	/* 0x9ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9af:
	/* 0x9af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b4:
	/* 0x9b4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b9:
	/* 0x9b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9be:
	/* 0x9be: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9c1:
	/* 0x9c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c3:
	/* 0x9c3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9cd:
	/* 0x9cd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d2:
	/* 0x9d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d7:
	/* 0x9d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d9:
	/* 0x9d9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9de:
	/* 0x9de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9e3:
	/* 0x9e3: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e8:
	/* 0x9e8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_9eb:
	/* 0x9eb: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9f0:
	/* 0x9f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f2:
	/* 0x9f2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_9f5:
	/* 0x9f5: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9f9:
	/* 0x9f9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9fe:
	/* 0x9fe: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a03:
	/* 0xa03: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a06:
	/* 0xa06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a08:
	/* 0xa08: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a10:
	/* 0xa10: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a14:
	/* 0xa14: je     276 <tracepoint__sched__sched_process_exec+0x276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 630ULL;
	}
x86_l_a1a:
	/* 0xa1a: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a1f:
	/* 0xa1f: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a26:
	/* 0xa26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a2b:
	/* 0xa2b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a30:
	/* 0xa30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a35:
	/* 0xa35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a37:
	/* 0xa37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3c:
	/* 0xa3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a41:
	/* 0xa41: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a46:
	/* 0xa46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4b:
	/* 0xa4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4d:
	/* 0xa4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a52:
	/* 0xa52: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a57:
	/* 0xa57: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a5c:
	/* 0xa5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a61:
	/* 0xa61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a63:
	/* 0xa63: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a68:
	/* 0xa68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a6d:
	/* 0xa6d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a72:
	/* 0xa72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a77:
	/* 0xa77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a79:
	/* 0xa79: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7e:
	/* 0xa7e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a81:
	/* 0xa81: je     a9f <tracepoint__sched__sched_process_exec+0xa9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a9f;
	}
x86_l_a83:
	/* 0xa83: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a87:
	/* 0xa87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a8c:
	/* 0xa8c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a91:
	/* 0xa91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a96:
	/* 0xa96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a98:
	/* 0xa98: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a9d:
	/* 0xa9d: jmp    aa1 <tracepoint__sched__sched_process_exec+0xaa1> */
	goto x86_l_aa1;
x86_l_a9f:
	/* 0xa9f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa1:
	/* 0xaa1: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa9:
	/* 0xaa9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aad:
	/* 0xaad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab2:
	/* 0xab2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_ab9:
	/* 0xab9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_abe:
	/* 0xabe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac0:
	/* 0xac0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: je     adc <tracepoint__sched__sched_process_exec+0xadc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_adc;
	}
x86_l_ac5:
	/* 0xac5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ac8:
	/* 0xac8: mov    BYTE PTR [r15+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_acf:
	/* 0xacf: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_ad2:
	/* 0xad2: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ad5:
	/* 0xad5: jne    adc <tracepoint__sched__sched_process_exec+0xadc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_adc;
	}
x86_l_ad7:
	/* 0xad7: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_adc:
	/* 0xadc: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ae1:
	/* 0xae1: cmp    ax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ae5:
	/* 0xae5: jne    1448 <tracepoint__sched__sched_process_exec+0x1448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5192ULL;
	}
x86_l_aeb:
	/* 0xaeb: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_af6:
	/* 0xaf6: mov    DWORD PTR [rsp+0x30],0x2cb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430923ULL);
x86_l_afe:
	/* 0xafe: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b03:
	/* 0xb03: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b08:
	/* 0xb08: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b0f:
	/* 0xb0f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b14:
	/* 0xb14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b16:
	/* 0xb16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b19:
	/* 0xb19: je     b86 <tracepoint__sched__sched_process_exec+0xb86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b86;
	}
x86_l_b1b:
	/* 0xb1b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b20:
	/* 0xb20: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b25:
	/* 0xb25: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b28:
	/* 0xb28: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b2a:
	/* 0xb2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2d:
	/* 0xb2d: je     b86 <tracepoint__sched__sched_process_exec+0xb86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b86;
	}
x86_l_b2f:
	/* 0xb2f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b33:
	/* 0xb33: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b3a:
	/* 0xb3a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3d:
	/* 0xb3d: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b44:
	/* 0xb44: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b48:
	/* 0xb48: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b4c:
	/* 0xb4c: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b53:
	/* 0xb53: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b5a:
	/* 0xb5a: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5e:
	/* 0xb5e: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b65:
	/* 0xb65: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b69:
	/* 0xb69: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b70:
	/* 0xb70: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b74:
	/* 0xb74: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b7b:
	/* 0xb7b: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b7f:
	/* 0xb7f: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b86:
	/* 0xb86: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b8d:
	/* 0xb8d: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b94:
	/* 0xb94: mov    QWORD PTR [r15+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_b9f:
	/* 0xb9f: mov    QWORD PTR [r15+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_baa:
	/* 0xbaa: cmp    BYTE PTR [r15+0xb1],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211394ULL);
x86_l_bb2:
	/* 0xbb2: jne    cbd <tracepoint__sched__sched_process_exec+0xcbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cbd;
	}
x86_l_bb8:
	/* 0xbb8: mov    r13d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 144ULL);
x86_l_bbe:
	/* 0xbbe: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_bc5:
	/* 0xbc5: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bc8:
	/* 0xbc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bcd:
	/* 0xbcd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd2:
	/* 0xbd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bd7:
	/* 0xbd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd9:
	/* 0xbd9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bde:
	/* 0xbde: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_be2:
	/* 0xbe2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_be7:
	/* 0xbe7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bec:
	/* 0xbec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf1:
	/* 0xbf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf3:
	/* 0xbf3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bf8:
	/* 0xbf8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bfd:
	/* 0xbfd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c02:
	/* 0xc02: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c07:
	/* 0xc07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c09:
	/* 0xc09: mov    ebx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0d:
	/* 0xc0d: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_c14:
	/* 0xc14: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c18:
	/* 0xc18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c1d:
	/* 0xc1d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c22:
	/* 0xc22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c27:
	/* 0xc27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c29:
	/* 0xc29: add    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_c2e:
	/* 0xc2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c33:
	/* 0xc33: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c38:
	/* 0xc38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c3d:
	/* 0xc3d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c40:
	/* 0xc40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c42:
	/* 0xc42: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c47:
	/* 0xc47: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c4b:
	/* 0xc4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c50:
	/* 0xc50: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c55:
	/* 0xc55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c5a:
	/* 0xc5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5c:
	/* 0xc5c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c61:
	/* 0xc61: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c66:
	/* 0xc66: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6b:
	/* 0xc6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c70:
	/* 0xc70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c72:
	/* 0xc72: cmp    ebx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_c76:
	/* 0xc76: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c7e:
	/* 0xc7e: je     cbd <tracepoint__sched__sched_process_exec+0xcbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cbd;
	}
x86_l_c80:
	/* 0xc80: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c84:
	/* 0xc84: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c88:
	/* 0xc88: mov    BYTE PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_c8d:
	/* 0xc8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c92:
	/* 0xc92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c99:
	/* 0xc99: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c9e:
	/* 0xc9e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca3:
	/* 0xca3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca5:
	/* 0xca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca7:
	/* 0xca7: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_cac:
	/* 0xcac: mov    BYTE PTR [r15+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_cb3:
	/* 0xcb3: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_cb8:
	/* 0xcb8: or     BYTE PTR [r15+0x54],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252865ULL);
x86_l_cbd:
	/* 0xcbd: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_cc5:
	/* 0xcc5: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc9:
	/* 0xcc9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_ccc:
	/* 0xccc: je     e62 <tracepoint__sched__sched_process_exec+0xe62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e62;
	}
x86_l_cd2:
	/* 0xcd2: mov    QWORD PTR [rsp+0x90],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cda:
	/* 0xcda: lea    rax,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cde:
	/* 0xcde: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ce6:
	/* 0xce6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ceb:
	/* 0xceb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf0:
	/* 0xcf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf5:
	/* 0xcf5: mov    QWORD PTR [rsp+0xd0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_cfd:
	/* 0xcfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cff:
	/* 0xcff: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d04:
	/* 0xd04: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_d0c:
	/* 0xd0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d11:
	/* 0xd11: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_d18:
	/* 0xd18: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d1d:
	/* 0xd1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1f:
	/* 0xd1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d22:
	/* 0xd22: mov    QWORD PTR [rsp+0xa8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d2a:
	/* 0xd2a: je     e6d <tracepoint__sched__sched_process_exec+0xe6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e6d;
	}
x86_l_d30:
	/* 0xd30: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d33:
	/* 0xd33: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d37:
	/* 0xd37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d3c:
	/* 0xd3c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d41:
	/* 0xd41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d4d:
	/* 0xd4d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d52:
	/* 0xd52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d57:
	/* 0xd57: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5c:
	/* 0xd5c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d61:
	/* 0xd61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d66:
	/* 0xd66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d68:
	/* 0xd68: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_d6d:
	/* 0xd6d: jne    e75 <tracepoint__sched__sched_process_exec+0xe75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e75;
	}
x86_l_d73:
	/* 0xd73: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d78:
	/* 0xd78: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7c:
	/* 0xd7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d81:
	/* 0xd81: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d86:
	/* 0xd86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d8b:
	/* 0xd8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8d:
	/* 0xd8d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d92:
	/* 0xd92: lea    rax,[r12-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_d97:
	/* 0xd97: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9b:
	/* 0xd9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_da0:
	/* 0xda0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da4:
	/* 0xda4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da9:
	/* 0xda9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dae:
	/* 0xdae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db0:
	/* 0xdb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db5:
	/* 0xdb5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dba:
	/* 0xdba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dbf:
	/* 0xdbf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc4:
	/* 0xdc4: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dc9:
	/* 0xdc9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dce:
	/* 0xdce: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dd2:
	/* 0xdd2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd7:
	/* 0xdd7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ddc:
	/* 0xddc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de1:
	/* 0xde1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de3:
	/* 0xde3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de8:
	/* 0xde8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_deb:
	/* 0xdeb: je     e93 <tracepoint__sched__sched_process_exec+0xe93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e93;
	}
x86_l_df1:
	/* 0xdf1: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_df6:
	/* 0xdf6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_df9:
	/* 0xdf9: je     e93 <tracepoint__sched__sched_process_exec+0xe93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e93;
	}
x86_l_dff:
	/* 0xdff: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e03:
	/* 0xe03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e08:
	/* 0xe08: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0d:
	/* 0xe0d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_e12:
	/* 0xe12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e14:
	/* 0xe14: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e18:
	/* 0xe18: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e1d:
	/* 0xe1d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e1f:
	/* 0xe1f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e25:
	/* 0xe25: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_e27:
	/* 0xe27: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_e29:
	/* 0xe29: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_e2f:
	/* 0xe2f: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e34:
	/* 0xe34: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e37:
	/* 0xe37: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_e3c:
	/* 0xe3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3e:
	/* 0xe3e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e41:
	/* 0xe41: jl     1578 <tracepoint__sched__sched_process_exec+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5496ULL;
	}
x86_l_e47:
	/* 0xe47: mov    BYTE PTR [r15+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_e4f:
	/* 0xe4f: mov    r13d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16384ULL);
x86_l_e55:
	/* 0xe55: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e58:
	/* 0xe58: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e5d:
	/* 0xe5d: jmp    eff <tracepoint__sched__sched_process_exec+0xeff> */
	goto x86_l_eff;
x86_l_e62:
	/* 0xe62: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_e68:
	/* 0xe68: jmp    2b8e <tracepoint__sched__sched_process_exec+0x2b8e> */
	return 11150ULL;
x86_l_e6d:
	/* 0xe6d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e70:
	/* 0xe70: jmp    15c3 <tracepoint__sched__sched_process_exec+0x15c3> */
	return 5571ULL;
x86_l_e75:
	/* 0xe75: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_e7a:
	/* 0xe7a: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_e81:
	/* 0xe81: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e89:
	/* 0xe89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8b:
	/* 0xe8b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8e:
	/* 0xe8e: jmp    15b1 <tracepoint__sched__sched_process_exec+0x15b1> */
	return 5553ULL;
x86_l_e93:
	/* 0xe93: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e96:
	/* 0xe96: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9b:
	/* 0xe9b: jne    1578 <tracepoint__sched__sched_process_exec+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5496ULL;
	}
x86_l_ea1:
	/* 0xea1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea5:
	/* 0xea5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_eaa:
	/* 0xeaa: je     1578 <tracepoint__sched__sched_process_exec+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5496ULL;
	}
x86_l_eb0:
	/* 0xeb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eb5:
	/* 0xeb5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb9:
	/* 0xeb9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ebd:
	/* 0xebd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec2:
	/* 0xec2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec7:
	/* 0xec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec9:
	/* 0xec9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ece:
	/* 0xece: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed2:
	/* 0xed2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ed5:
	/* 0xed5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eda:
	/* 0xeda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edc:
	/* 0xedc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ee1:
	/* 0xee1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee5:
	/* 0xee5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eea:
	/* 0xeea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eef:
	/* 0xeef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef1:
	/* 0xef1: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef5:
	/* 0xef5: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ef9:
	/* 0xef9: mov    r13d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16384ULL);
x86_l_eff:
	/* 0xeff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f04:
	/* 0xf04: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f09:
	/* 0xf09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f0e:
	/* 0xf0e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f11:
	/* 0xf11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f13:
	/* 0xf13: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f18:
	/* 0xf18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1d:
	/* 0xf1d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	return 3873ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3943ULL: goto x86_l_f67;
	case 3946ULL: goto x86_l_f6a;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3957ULL: goto x86_l_f75;
	case 3960ULL: goto x86_l_f78;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3974ULL: goto x86_l_f86;
	case 3980ULL: goto x86_l_f8c;
	case 3983ULL: goto x86_l_f8f;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4048ULL: goto x86_l_fd0;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4072ULL: goto x86_l_fe8;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4101ULL: goto x86_l_1005;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4117ULL: goto x86_l_1015;
	case 4122ULL: goto x86_l_101a;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4157ULL: goto x86_l_103d;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4183ULL: goto x86_l_1057;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4257ULL: goto x86_l_10a1;
	case 4261ULL: goto x86_l_10a5;
	case 4263ULL: goto x86_l_10a7;
	case 4269ULL: goto x86_l_10ad;
	case 4272ULL: goto x86_l_10b0;
	case 4274ULL: goto x86_l_10b2;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4343ULL: goto x86_l_10f7;
	case 4346ULL: goto x86_l_10fa;
	case 4352ULL: goto x86_l_1100;
	case 4356ULL: goto x86_l_1104;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4381ULL: goto x86_l_111d;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4402ULL: goto x86_l_1132;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4414ULL: goto x86_l_113e;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4435ULL: goto x86_l_1153;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4504ULL: goto x86_l_1198;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4541ULL: goto x86_l_11bd;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4554ULL: goto x86_l_11ca;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4652ULL: goto x86_l_122c;
	case 4657ULL: goto x86_l_1231;
	case 4661ULL: goto x86_l_1235;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4715ULL: goto x86_l_126b;
	case 4717ULL: goto x86_l_126d;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4752ULL: goto x86_l_1290;
	case 4757ULL: goto x86_l_1295;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4871ULL: goto x86_l_1307;
	case 4877ULL: goto x86_l_130d;
	case 4881ULL: goto x86_l_1311;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4900ULL: goto x86_l_1324;
	case 4902ULL: goto x86_l_1326;
	case 4905ULL: goto x86_l_1329;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4939ULL: goto x86_l_134b;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4979ULL: goto x86_l_1373;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5118ULL: goto x86_l_13fe;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5164ULL: goto x86_l_142c;
	case 5168ULL: goto x86_l_1430;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5192ULL: goto x86_l_1448;
	case 5199ULL: goto x86_l_144f;
	case 5202ULL: goto x86_l_1452;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5227ULL: goto x86_l_146b;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5250ULL: goto x86_l_1482;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5274ULL: goto x86_l_149a;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5290ULL: goto x86_l_14aa;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5318ULL: goto x86_l_14c6;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5334ULL: goto x86_l_14d6;
	case 5338ULL: goto x86_l_14da;
	case 5343ULL: goto x86_l_14df;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5424ULL: goto x86_l_1530;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5438ULL: goto x86_l_153e;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5449ULL: goto x86_l_1549;
	case 5451ULL: goto x86_l_154b;
	case 5457ULL: goto x86_l_1551;
	case 5460ULL: goto x86_l_1554;
	case 5462ULL: goto x86_l_1556;
	case 5468ULL: goto x86_l_155c;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f21:
	/* 0xf21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f26:
	/* 0xf26: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f2b:
	/* 0xf2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f30:
	/* 0xf30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f32:
	/* 0xf32: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f37:
	/* 0xf37: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f3a:
	/* 0xf3a: je     f75 <tracepoint__sched__sched_process_exec+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f75;
	}
x86_l_f3c:
	/* 0xf3c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f41:
	/* 0xf41: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f44:
	/* 0xf44: je     f75 <tracepoint__sched__sched_process_exec+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f75;
	}
x86_l_f46:
	/* 0xf46: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f4a:
	/* 0xf4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f4f:
	/* 0xf4f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f54:
	/* 0xf54: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_f59:
	/* 0xf59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5b:
	/* 0xf5b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f5f:
	/* 0xf5f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f61:
	/* 0xf61: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f67:
	/* 0xf67: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_f6a:
	/* 0xf6a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f6c:
	/* 0xf6c: jae    fa9 <tracepoint__sched__sched_process_exec+0xfa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_fa9;
	}
x86_l_f6e:
	/* 0xf6e: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f73:
	/* 0xf73: jmp    f8c <tracepoint__sched__sched_process_exec+0xf8c> */
	goto x86_l_f8c;
x86_l_f75:
	/* 0xf75: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f78:
	/* 0xf78: je     fe8 <tracepoint__sched__sched_process_exec+0xfe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe8;
	}
x86_l_f7a:
	/* 0xf7a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7f:
	/* 0xf7f: cmp    r13d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16384ULL);
x86_l_f86:
	/* 0xf86: je     1578 <tracepoint__sched__sched_process_exec+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5496ULL;
	}
x86_l_f8c:
	/* 0xf8c: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_f8f:
	/* 0xf8f: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_f92:
	/* 0xf92: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_f97:
	/* 0xf97: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_f9c:
	/* 0xf9c: mov    BYTE PTR [r15+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_fa4:
	/* 0xfa4: jmp    15a9 <tracepoint__sched__sched_process_exec+0x15a9> */
	return 5545ULL;
x86_l_fa9:
	/* 0xfa9: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fae:
	/* 0xfae: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_fb4:
	/* 0xfb4: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb9:
	/* 0xfb9: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_fbc:
	/* 0xfbc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_fc1:
	/* 0xfc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc3:
	/* 0xfc3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fc6:
	/* 0xfc6: jl     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5483ULL;
	}
x86_l_fcc:
	/* 0xfcc: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_fd0:
	/* 0xfd0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_fd6:
	/* 0xfd6: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_fdb:
	/* 0xfdb: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fde:
	/* 0xfde: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe3:
	/* 0xfe3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: jmp    1045 <tracepoint__sched__sched_process_exec+0x1045> */
	goto x86_l_1045;
x86_l_fe8:
	/* 0xfe8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fec:
	/* 0xfec: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_ff1:
	/* 0xff1: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff6:
	/* 0xff6: je     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5483ULL;
	}
x86_l_ffc:
	/* 0xffc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1001:
	/* 0x1001: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1005:
	/* 0x1005: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1009:
	/* 0x1009: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100e:
	/* 0x100e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1013:
	/* 0x1013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1015:
	/* 0x1015: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_101a:
	/* 0x101a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_101e:
	/* 0x101e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1021:
	/* 0x1021: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1026:
	/* 0x1026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1028:
	/* 0x1028: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_102d:
	/* 0x102d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1031:
	/* 0x1031: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1036:
	/* 0x1036: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_103b:
	/* 0x103b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103d:
	/* 0x103d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1041:
	/* 0x1041: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1045:
	/* 0x1045: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_104a:
	/* 0x104a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_104f:
	/* 0x104f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1054:
	/* 0x1054: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_1057:
	/* 0x1057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1059:
	/* 0x1059: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_105e:
	/* 0x105e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1063:
	/* 0x1063: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1067:
	/* 0x1067: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_106c:
	/* 0x106c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1071:
	/* 0x1071: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1076:
	/* 0x1076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1078:
	/* 0x1078: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107d:
	/* 0x107d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1080:
	/* 0x1080: je     10f7 <tracepoint__sched__sched_process_exec+0x10f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10f7;
	}
x86_l_1082:
	/* 0x1082: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1087:
	/* 0x1087: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_108a:
	/* 0x108a: je     10f7 <tracepoint__sched__sched_process_exec+0x10f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10f7;
	}
x86_l_108c:
	/* 0x108c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1090:
	/* 0x1090: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1095:
	/* 0x1095: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109a:
	/* 0x109a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_109f:
	/* 0x109f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a1:
	/* 0x10a1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10a5:
	/* 0x10a5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10a7:
	/* 0x10a7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ad:
	/* 0x10ad: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_10b0:
	/* 0x10b0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10b2:
	/* 0x10b2: jb     f6e <tracepoint__sched__sched_process_exec+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f6e;
	}
x86_l_10b8:
	/* 0x10b8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10bd:
	/* 0x10bd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_10c3:
	/* 0x10c3: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c8:
	/* 0x10c8: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10cb:
	/* 0x10cb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_10d0:
	/* 0x10d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d2:
	/* 0x10d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10d5:
	/* 0x10d5: jl     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5483ULL;
	}
x86_l_10db:
	/* 0x10db: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_10df:
	/* 0x10df: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_10e5:
	/* 0x10e5: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_10ea:
	/* 0x10ea: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10ed:
	/* 0x10ed: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f2:
	/* 0x10f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10f5:
	/* 0x10f5: jmp    115d <tracepoint__sched__sched_process_exec+0x115d> */
	goto x86_l_115d;
x86_l_10f7:
	/* 0x10f7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: jne    f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f7a;
	}
x86_l_1100:
	/* 0x1100: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1104:
	/* 0x1104: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1109:
	/* 0x1109: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110e:
	/* 0x110e: je     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5483ULL;
	}
x86_l_1114:
	/* 0x1114: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1119:
	/* 0x1119: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111d:
	/* 0x111d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1121:
	/* 0x1121: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1126:
	/* 0x1126: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_112b:
	/* 0x112b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112d:
	/* 0x112d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1132:
	/* 0x1132: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1136:
	/* 0x1136: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1139:
	/* 0x1139: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_113e:
	/* 0x113e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1140:
	/* 0x1140: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1145:
	/* 0x1145: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1149:
	/* 0x1149: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_114e:
	/* 0x114e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1153:
	/* 0x1153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1155:
	/* 0x1155: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1159:
	/* 0x1159: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_115d:
	/* 0x115d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1162:
	/* 0x1162: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1167:
	/* 0x1167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116c:
	/* 0x116c: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1171:
	/* 0x1171: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1176:
	/* 0x1176: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_117b:
	/* 0x117b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_117f:
	/* 0x117f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1184:
	/* 0x1184: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1189:
	/* 0x1189: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118e:
	/* 0x118e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1190:
	/* 0x1190: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1195:
	/* 0x1195: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1198:
	/* 0x1198: je     120f <tracepoint__sched__sched_process_exec+0x120f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120f;
	}
x86_l_119a:
	/* 0x119a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_119f:
	/* 0x119f: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11a2:
	/* 0x11a2: je     120f <tracepoint__sched__sched_process_exec+0x120f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120f;
	}
x86_l_11a4:
	/* 0x11a4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11a8:
	/* 0x11a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ad:
	/* 0x11ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11b2:
	/* 0x11b2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11b7:
	/* 0x11b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b9:
	/* 0x11b9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11bd:
	/* 0x11bd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11bf:
	/* 0x11bf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c5:
	/* 0x11c5: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_11c8:
	/* 0x11c8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_11ca:
	/* 0x11ca: jb     f6e <tracepoint__sched__sched_process_exec+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f6e;
	}
x86_l_11d0:
	/* 0x11d0: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d5:
	/* 0x11d5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_11db:
	/* 0x11db: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11e0:
	/* 0x11e0: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11e3:
	/* 0x11e3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_11e8:
	/* 0x11e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ea:
	/* 0x11ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11ed:
	/* 0x11ed: jl     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5483ULL;
	}
x86_l_11f3:
	/* 0x11f3: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_11f7:
	/* 0x11f7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_11fd:
	/* 0x11fd: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1202:
	/* 0x1202: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1205:
	/* 0x1205: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120a:
	/* 0x120a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_120d:
	/* 0x120d: jmp    1275 <tracepoint__sched__sched_process_exec+0x1275> */
	goto x86_l_1275;
x86_l_120f:
	/* 0x120f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1212:
	/* 0x1212: jne    f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f7a;
	}
x86_l_1218:
	/* 0x1218: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121c:
	/* 0x121c: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1221:
	/* 0x1221: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1226:
	/* 0x1226: je     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5483ULL;
	}
x86_l_122c:
	/* 0x122c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1231:
	/* 0x1231: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1235:
	/* 0x1235: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1239:
	/* 0x1239: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123e:
	/* 0x123e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1243:
	/* 0x1243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1245:
	/* 0x1245: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_124a:
	/* 0x124a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124e:
	/* 0x124e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1251:
	/* 0x1251: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1256:
	/* 0x1256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1258:
	/* 0x1258: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_125d:
	/* 0x125d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1261:
	/* 0x1261: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1266:
	/* 0x1266: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_126b:
	/* 0x126b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126d:
	/* 0x126d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1271:
	/* 0x1271: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1275:
	/* 0x1275: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_127a:
	/* 0x127a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127f:
	/* 0x127f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1284:
	/* 0x1284: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1290:
	/* 0x1290: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1295:
	/* 0x1295: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1299:
	/* 0x1299: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_129e:
	/* 0x129e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a3:
	/* 0x12a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a8:
	/* 0x12a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12aa:
	/* 0x12aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12af:
	/* 0x12af: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12b2:
	/* 0x12b2: je     1326 <tracepoint__sched__sched_process_exec+0x1326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1326;
	}
x86_l_12b4:
	/* 0x12b4: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b9:
	/* 0x12b9: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_12bc:
	/* 0x12bc: je     1326 <tracepoint__sched__sched_process_exec+0x1326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1326;
	}
x86_l_12be:
	/* 0x12be: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12c2:
	/* 0x12c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12c7:
	/* 0x12c7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12cc:
	/* 0x12cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12d7:
	/* 0x12d7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12d9:
	/* 0x12d9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12df:
	/* 0x12df: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_12e2:
	/* 0x12e2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12e4:
	/* 0x12e4: jb     f6e <tracepoint__sched__sched_process_exec+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f6e;
	}
x86_l_12ea:
	/* 0x12ea: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12ef:
	/* 0x12ef: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_12f5:
	/* 0x12f5: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12fa:
	/* 0x12fa: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12fd:
	/* 0x12fd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1302:
	/* 0x1302: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1304:
	/* 0x1304: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1307:
	/* 0x1307: jl     156b <tracepoint__sched__sched_process_exec+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5483ULL;
	}
x86_l_130d:
	/* 0x130d: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1311:
	/* 0x1311: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1317:
	/* 0x1317: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_131c:
	/* 0x131c: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_131f:
	/* 0x131f: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1324:
	/* 0x1324: jmp    138c <tracepoint__sched__sched_process_exec+0x138c> */
	goto x86_l_138c;
x86_l_1326:
	/* 0x1326: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1329:
	/* 0x1329: jne    f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f7a;
	}
x86_l_132f:
	/* 0x132f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1333:
	/* 0x1333: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1338:
	/* 0x1338: je     f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7a;
	}
x86_l_133e:
	/* 0x133e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1343:
	/* 0x1343: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1347:
	/* 0x1347: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_134b:
	/* 0x134b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1350:
	/* 0x1350: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1355:
	/* 0x1355: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1357:
	/* 0x1357: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_135c:
	/* 0x135c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1360:
	/* 0x1360: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1363:
	/* 0x1363: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1368:
	/* 0x1368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136a:
	/* 0x136a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_136f:
	/* 0x136f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1373:
	/* 0x1373: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1378:
	/* 0x1378: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_137d:
	/* 0x137d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137f:
	/* 0x137f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1383:
	/* 0x1383: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1387:
	/* 0x1387: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_138c:
	/* 0x138c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1391:
	/* 0x1391: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1396:
	/* 0x1396: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_139b:
	/* 0x139b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a0:
	/* 0x13a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a2:
	/* 0x13a2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ac:
	/* 0x13ac: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13b0:
	/* 0x13b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13b5:
	/* 0x13b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ba:
	/* 0x13ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13bf:
	/* 0x13bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c1:
	/* 0x13c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c6:
	/* 0x13c6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13c9:
	/* 0x13c9: je     1479 <tracepoint__sched__sched_process_exec+0x1479> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1479;
	}
x86_l_13cf:
	/* 0x13cf: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d4:
	/* 0x13d4: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: je     1479 <tracepoint__sched__sched_process_exec+0x1479> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1479;
	}
x86_l_13dd:
	/* 0x13dd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13e1:
	/* 0x13e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e6:
	/* 0x13e6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13eb:
	/* 0x13eb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13f0:
	/* 0x13f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f2:
	/* 0x13f2: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13f6:
	/* 0x13f6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13f8:
	/* 0x13f8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13fe:
	/* 0x13fe: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1401:
	/* 0x1401: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1403:
	/* 0x1403: jb     f6e <tracepoint__sched__sched_process_exec+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f6e;
	}
x86_l_1409:
	/* 0x1409: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_140e:
	/* 0x140e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1414:
	/* 0x1414: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1419:
	/* 0x1419: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_141c:
	/* 0x141c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1421:
	/* 0x1421: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1423:
	/* 0x1423: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1426:
	/* 0x1426: jl     1566 <tracepoint__sched__sched_process_exec+0x1566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1566;
	}
x86_l_142c:
	/* 0x142c: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1430:
	/* 0x1430: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1436:
	/* 0x1436: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_143b:
	/* 0x143b: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_143e:
	/* 0x143e: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1443:
	/* 0x1443: jmp    14df <tracepoint__sched__sched_process_exec+0x14df> */
	goto x86_l_14df;
x86_l_1448:
	/* 0x1448: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_144f:
	/* 0x144f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1452:
	/* 0x1452: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1456:
	/* 0x1456: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_145b:
	/* 0x145b: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1460:
	/* 0x1460: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1462:
	/* 0x1462: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1465:
	/* 0x1465: jne    2b8b <tracepoint__sched__sched_process_exec+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11147ULL;
	}
x86_l_146b:
	/* 0x146b: movzx  eax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_146f:
	/* 0x146f: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_1474:
	/* 0x1474: jmp    aeb <tracepoint__sched__sched_process_exec+0xaeb> */
	return 2795ULL;
x86_l_1479:
	/* 0x1479: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_147c:
	/* 0x147c: jne    f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f7a;
	}
x86_l_1482:
	/* 0x1482: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1486:
	/* 0x1486: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_148b:
	/* 0x148b: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_1491:
	/* 0x1491: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1496:
	/* 0x1496: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149a:
	/* 0x149a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_149e:
	/* 0x149e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a3:
	/* 0x14a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14a8:
	/* 0x14a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14aa:
	/* 0x14aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14af:
	/* 0x14af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b3:
	/* 0x14b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14bb:
	/* 0x14bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14c2:
	/* 0x14c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c6:
	/* 0x14c6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14cb:
	/* 0x14cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d0:
	/* 0x14d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d2:
	/* 0x14d2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d6:
	/* 0x14d6: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14da:
	/* 0x14da: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14df:
	/* 0x14df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14e4:
	/* 0x14e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14e9:
	/* 0x14e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ee:
	/* 0x14ee: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14f3:
	/* 0x14f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f5:
	/* 0x14f5: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14fa:
	/* 0x14fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ff:
	/* 0x14ff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1503:
	/* 0x1503: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1508:
	/* 0x1508: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_150d:
	/* 0x150d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1512:
	/* 0x1512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1514:
	/* 0x1514: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1519:
	/* 0x1519: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_151c:
	/* 0x151c: je     2ba0 <tracepoint__sched__sched_process_exec+0x2ba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11168ULL;
	}
x86_l_1522:
	/* 0x1522: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1527:
	/* 0x1527: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_152a:
	/* 0x152a: je     2ba0 <tracepoint__sched__sched_process_exec+0x2ba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11168ULL;
	}
x86_l_1530:
	/* 0x1530: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1534:
	/* 0x1534: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1539:
	/* 0x1539: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_153e:
	/* 0x153e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1543:
	/* 0x1543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1545:
	/* 0x1545: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1549:
	/* 0x1549: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_154b:
	/* 0x154b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1551:
	/* 0x1551: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1554:
	/* 0x1554: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1556:
	/* 0x1556: jae    2c08 <tracepoint__sched__sched_process_exec+0x2c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11272ULL;
	}
x86_l_155c:
	/* 0x155c: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1561:
	/* 0x1561: jmp    f6e <tracepoint__sched__sched_process_exec+0xf6e> */
	goto x86_l_f6e;
x86_l_1566:
	/* 0x1566: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 5483ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5483ULL: goto x86_l_156b;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5586ULL: goto x86_l_15d2;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5614ULL: goto x86_l_15ee;
	case 5622ULL: goto x86_l_15f6;
	case 5629ULL: goto x86_l_15fd;
	case 5632ULL: goto x86_l_1600;
	case 5635ULL: goto x86_l_1603;
	case 5638ULL: goto x86_l_1606;
	case 5642ULL: goto x86_l_160a;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5665ULL: goto x86_l_1621;
	case 5668ULL: goto x86_l_1624;
	case 5670ULL: goto x86_l_1626;
	case 5672ULL: goto x86_l_1628;
	case 5680ULL: goto x86_l_1630;
	case 5687ULL: goto x86_l_1637;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5696ULL: goto x86_l_1640;
	case 5703ULL: goto x86_l_1647;
	case 5706ULL: goto x86_l_164a;
	case 5709ULL: goto x86_l_164d;
	case 5716ULL: goto x86_l_1654;
	case 5719ULL: goto x86_l_1657;
	case 5721ULL: goto x86_l_1659;
	case 5725ULL: goto x86_l_165d;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5734ULL: goto x86_l_1666;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5747ULL: goto x86_l_1673;
	case 5754ULL: goto x86_l_167a;
	case 5757ULL: goto x86_l_167d;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5770ULL: goto x86_l_168a;
	case 5777ULL: goto x86_l_1691;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5809ULL: goto x86_l_16b1;
	case 5816ULL: goto x86_l_16b8;
	case 5824ULL: goto x86_l_16c0;
	case 5831ULL: goto x86_l_16c7;
	case 5839ULL: goto x86_l_16cf;
	case 5846ULL: goto x86_l_16d6;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5897ULL: goto x86_l_1709;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5920ULL: goto x86_l_1720;
	case 5922ULL: goto x86_l_1722;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5932ULL: goto x86_l_172c;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5945ULL: goto x86_l_1739;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5970ULL: goto x86_l_1752;
	case 5972ULL: goto x86_l_1754;
	case 5975ULL: goto x86_l_1757;
	case 5977ULL: goto x86_l_1759;
	case 5985ULL: goto x86_l_1761;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6004ULL: goto x86_l_1774;
	case 6007ULL: goto x86_l_1777;
	case 6009ULL: goto x86_l_1779;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6030ULL: goto x86_l_178e;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6044ULL: goto x86_l_179c;
	case 6047ULL: goto x86_l_179f;
	case 6049ULL: goto x86_l_17a1;
	case 6056ULL: goto x86_l_17a8;
	case 6063ULL: goto x86_l_17af;
	case 6066ULL: goto x86_l_17b2;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6079ULL: goto x86_l_17bf;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6104ULL: goto x86_l_17d8;
	case 6112ULL: goto x86_l_17e0;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6123ULL: goto x86_l_17eb;
	case 6125ULL: goto x86_l_17ed;
	case 6129ULL: goto x86_l_17f1;
	case 6131ULL: goto x86_l_17f3;
	case 6134ULL: goto x86_l_17f6;
	case 6136ULL: goto x86_l_17f8;
	case 6144ULL: goto x86_l_1800;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6153ULL: goto x86_l_1809;
	case 6156ULL: goto x86_l_180c;
	case 6164ULL: goto x86_l_1814;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6177ULL: goto x86_l_1821;
	case 6181ULL: goto x86_l_1825;
	case 6188ULL: goto x86_l_182c;
	case 6195ULL: goto x86_l_1833;
	case 6203ULL: goto x86_l_183b;
	case 6210ULL: goto x86_l_1842;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6255ULL: goto x86_l_186f;
	case 6262ULL: goto x86_l_1876;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6287ULL: goto x86_l_188f;
	case 6290ULL: goto x86_l_1892;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6301ULL: goto x86_l_189d;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6344ULL: goto x86_l_18c8;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6360ULL: goto x86_l_18d8;
	case 6368ULL: goto x86_l_18e0;
	case 6371ULL: goto x86_l_18e3;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6483ULL: goto x86_l_1953;
	case 6490ULL: goto x86_l_195a;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6503ULL: goto x86_l_1967;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6546ULL: goto x86_l_1992;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6555ULL: goto x86_l_199b;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6562ULL: goto x86_l_19a2;
	case 6565ULL: goto x86_l_19a5;
	case 6568ULL: goto x86_l_19a8;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6582ULL: goto x86_l_19b6;
	case 6588ULL: goto x86_l_19bc;
	case 6595ULL: goto x86_l_19c3;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6649ULL: goto x86_l_19f9;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6679ULL: goto x86_l_1a17;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6700ULL: goto x86_l_1a2c;
	case 6704ULL: goto x86_l_1a30;
	case 6708ULL: goto x86_l_1a34;
	case 6715ULL: goto x86_l_1a3b;
	case 6722ULL: goto x86_l_1a42;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6761ULL: goto x86_l_1a69;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6778ULL: goto x86_l_1a7a;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6794ULL: goto x86_l_1a8a;
	case 6797ULL: goto x86_l_1a8d;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6806ULL: goto x86_l_1a96;
	case 6814ULL: goto x86_l_1a9e;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6925ULL: goto x86_l_1b0d;
	case 6932ULL: goto x86_l_1b14;
	case 6935ULL: goto x86_l_1b17;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6971ULL: goto x86_l_1b3b;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6987ULL: goto x86_l_1b4b;
	case 6989ULL: goto x86_l_1b4d;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7035ULL: goto x86_l_1b7b;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7054ULL: goto x86_l_1b8e;
	case 7061ULL: goto x86_l_1b95;
	case 7068ULL: goto x86_l_1b9c;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7107ULL: goto x86_l_1bc3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_156b:
	/* 0x156b: cmp    r13d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16384ULL);
x86_l_1572:
	/* 0x1572: jne    f8c <tracepoint__sched__sched_process_exec+0xf8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3980ULL;
	}
x86_l_1578:
	/* 0x1578: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157d:
	/* 0x157d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1581:
	/* 0x1581: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1586:
	/* 0x1586: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_158b:
	/* 0x158b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1590:
	/* 0x1590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1592:
	/* 0x1592: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1597:
	/* 0x1597: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_159c:
	/* 0x159c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_159f:
	/* 0x159f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15a4:
	/* 0x15a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a6:
	/* 0x15a6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a9:
	/* 0x15a9: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15b1:
	/* 0x15b1: and    r13d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_15b8:
	/* 0x15b8: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15bb:
	/* 0x15bb: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15c3:
	/* 0x15c3: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c8:
	/* 0x15c8: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ca:
	/* 0x15ca: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15d2:
	/* 0x15d2: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_15d4:
	/* 0x15d4: jne    15de <tracepoint__sched__sched_process_exec+0x15de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15de;
	}
x86_l_15d6:
	/* 0x15d6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d9:
	/* 0x15d9: jmp    1d85 <tracepoint__sched__sched_process_exec+0x1d85> */
	return 7557ULL;
x86_l_15de:
	/* 0x15de: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_15e5:
	/* 0x15e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e8:
	/* 0x15e8: je     17a1 <tracepoint__sched__sched_process_exec+0x17a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a1;
	}
x86_l_15ee:
	/* 0x15ee: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15f6:
	/* 0x15f6: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_15fd:
	/* 0x15fd: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1600:
	/* 0x1600: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1603:
	/* 0x1603: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1606:
	/* 0x1606: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_160a:
	/* 0x160a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_160d:
	/* 0x160d: neg    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1610:
	/* 0x1610: xor    r15,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_1617:
	/* 0x1617: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_161a:
	/* 0x161a: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1621:
	/* 0x1621: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1624:
	/* 0x1624: je     164d <tracepoint__sched__sched_process_exec+0x164d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_164d;
	}
x86_l_1626:
	/* 0x1626: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1628:
	/* 0x1628: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1630:
	/* 0x1630: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1637:
	/* 0x1637: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_163a:
	/* 0x163a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_163d:
	/* 0x163d: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1640:
	/* 0x1640: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1647:
	/* 0x1647: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_164a:
	/* 0x164a: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_164d:
	/* 0x164d: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_1654:
	/* 0x1654: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1657:
	/* 0x1657: je     1673 <tracepoint__sched__sched_process_exec+0x1673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1673;
	}
x86_l_1659:
	/* 0x1659: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_165d:
	/* 0x165d: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1660:
	/* 0x1660: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1663:
	/* 0x1663: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1666:
	/* 0x1666: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_166d:
	/* 0x166d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1670:
	/* 0x1670: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1673:
	/* 0x1673: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_167a:
	/* 0x167a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_167d:
	/* 0x167d: je     1697 <tracepoint__sched__sched_process_exec+0x1697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1697;
	}
x86_l_167f:
	/* 0x167f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1682:
	/* 0x1682: movsx  rcx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1687:
	/* 0x1687: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_168a:
	/* 0x168a: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1691:
	/* 0x1691: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1694:
	/* 0x1694: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1697:
	/* 0x1697: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_169c:
	/* 0x169c: mov    rbp,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_16a3:
	/* 0x16a3: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_16a6:
	/* 0x16a6: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16ab:
	/* 0x16ab: je     180c <tracepoint__sched__sched_process_exec+0x180c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_180c;
	}
x86_l_16b1:
	/* 0x16b1: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_16b8:
	/* 0x16b8: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_16c0:
	/* 0x16c0: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_16c7:
	/* 0x16c7: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16cf:
	/* 0x16cf: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_16d6:
	/* 0x16d6: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16de:
	/* 0x16de: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e3:
	/* 0x16e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e8:
	/* 0x16e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_16ef:
	/* 0x16ef: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f4:
	/* 0x16f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f6:
	/* 0x16f6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_16f9:
	/* 0x16f9: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16fd:
	/* 0x16fd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1702:
	/* 0x1702: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1709:
	/* 0x1709: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_170c:
	/* 0x170c: je     172e <tracepoint__sched__sched_process_exec+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_170e:
	/* 0x170e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1713:
	/* 0x1713: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1718:
	/* 0x1718: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171d:
	/* 0x171d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1720:
	/* 0x1720: je     172e <tracepoint__sched__sched_process_exec+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1722:
	/* 0x1722: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1725:
	/* 0x1725: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1729:
	/* 0x1729: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_172c:
	/* 0x172c: jmp    1731 <tracepoint__sched__sched_process_exec+0x1731> */
	goto x86_l_1731;
x86_l_172e:
	/* 0x172e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1731:
	/* 0x1731: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1739:
	/* 0x1739: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1741:
	/* 0x1741: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1746:
	/* 0x1746: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1749:
	/* 0x1749: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_174c:
	/* 0x174c: jb     1764 <tracepoint__sched__sched_process_exec+0x1764> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1764;
	}
x86_l_174e:
	/* 0x174e: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1752:
	/* 0x1752: je     1759 <tracepoint__sched__sched_process_exec+0x1759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1759;
	}
x86_l_1754:
	/* 0x1754: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1757:
	/* 0x1757: jbe    1764 <tracepoint__sched__sched_process_exec+0x1764> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1764;
	}
x86_l_1759:
	/* 0x1759: and    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_1761:
	/* 0x1761: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1764:
	/* 0x1764: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1768:
	/* 0x1768: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_176d:
	/* 0x176d: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1774:
	/* 0x1774: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1777:
	/* 0x1777: je     17bd <tracepoint__sched__sched_process_exec+0x17bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17bd;
	}
x86_l_1779:
	/* 0x1779: mov    QWORD PTR [rsp+0x88],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1781:
	/* 0x1781: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1786:
	/* 0x1786: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_178b:
	/* 0x178b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_178e:
	/* 0x178e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1790:
	/* 0x1790: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1793:
	/* 0x1793: je     17ce <tracepoint__sched__sched_process_exec+0x17ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ce;
	}
x86_l_1795:
	/* 0x1795: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1798:
	/* 0x1798: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_179c:
	/* 0x179c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_179f:
	/* 0x179f: jmp    17d0 <tracepoint__sched__sched_process_exec+0x17d0> */
	goto x86_l_17d0;
x86_l_17a1:
	/* 0x17a1: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17a8:
	/* 0x17a8: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_17af:
	/* 0x17af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17b2:
	/* 0x17b2: jne    1626 <tracepoint__sched__sched_process_exec+0x1626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1626;
	}
x86_l_17b8:
	/* 0x17b8: jmp    164d <tracepoint__sched__sched_process_exec+0x164d> */
	goto x86_l_164d;
x86_l_17bd:
	/* 0x17bd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17bf:
	/* 0x17bf: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17c2:
	/* 0x17c2: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17c7:
	/* 0x17c7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_17ca:
	/* 0x17ca: jae    17ed <tracepoint__sched__sched_process_exec+0x17ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_17ed;
	}
x86_l_17cc:
	/* 0x17cc: jmp    1803 <tracepoint__sched__sched_process_exec+0x1803> */
	goto x86_l_1803;
x86_l_17ce:
	/* 0x17ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d0:
	/* 0x17d0: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17d8:
	/* 0x17d8: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17e0:
	/* 0x17e0: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17e3:
	/* 0x17e3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17e8:
	/* 0x17e8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_17eb:
	/* 0x17eb: jb     1803 <tracepoint__sched__sched_process_exec+0x1803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1803;
	}
x86_l_17ed:
	/* 0x17ed: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17f1:
	/* 0x17f1: je     17f8 <tracepoint__sched__sched_process_exec+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17f8;
	}
x86_l_17f3:
	/* 0x17f3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_17f6:
	/* 0x17f6: jbe    1803 <tracepoint__sched__sched_process_exec+0x1803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1803;
	}
x86_l_17f8:
	/* 0x17f8: and    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_1800:
	/* 0x1800: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1803:
	/* 0x1803: or     r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_1806:
	/* 0x1806: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1809:
	/* 0x1809: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_180c:
	/* 0x180c: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1814:
	/* 0x1814: je     18b4 <tracepoint__sched__sched_process_exec+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b4;
	}
x86_l_181a:
	/* 0x181a: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_181f:
	/* 0x181f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1821:
	/* 0x1821: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1825:
	/* 0x1825: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_182c:
	/* 0x182c: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1833:
	/* 0x1833: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_183b:
	/* 0x183b: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_1842:
	/* 0x1842: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_1849:
	/* 0x1849: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_184e:
	/* 0x184e: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1853:
	/* 0x1853: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1858:
	/* 0x1858: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_185f:
	/* 0x185f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1864:
	/* 0x1864: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1866:
	/* 0x1866: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_186a:
	/* 0x186a: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_186f:
	/* 0x186f: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1876:
	/* 0x1876: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1879:
	/* 0x1879: je     189b <tracepoint__sched__sched_process_exec+0x189b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189b;
	}
x86_l_187b:
	/* 0x187b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1880:
	/* 0x1880: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1885:
	/* 0x1885: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1888:
	/* 0x1888: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_188a:
	/* 0x188a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_188d:
	/* 0x188d: je     189b <tracepoint__sched__sched_process_exec+0x189b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189b;
	}
x86_l_188f:
	/* 0x188f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1892:
	/* 0x1892: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1896:
	/* 0x1896: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1899:
	/* 0x1899: jmp    189d <tracepoint__sched__sched_process_exec+0x189d> */
	goto x86_l_189d;
x86_l_189b:
	/* 0x189b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_189d:
	/* 0x189d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18a0:
	/* 0x18a0: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18a5:
	/* 0x18a5: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_18a8:
	/* 0x18a8: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_18ab:
	/* 0x18ab: jae    18c8 <tracepoint__sched__sched_process_exec+0x18c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18c8;
	}
x86_l_18ad:
	/* 0x18ad: movzx  ebp,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_18b2:
	/* 0x18b2: jmp    18e3 <tracepoint__sched__sched_process_exec+0x18e3> */
	goto x86_l_18e3;
x86_l_18b4:
	/* 0x18b4: movzx  ebp,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_18b9:
	/* 0x18b9: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_18c1:
	/* 0x18c1: jne    18f7 <tracepoint__sched__sched_process_exec+0x18f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f7;
	}
x86_l_18c3:
	/* 0x18c3: jmp    19ae <tracepoint__sched__sched_process_exec+0x19ae> */
	goto x86_l_19ae;
x86_l_18c8:
	/* 0x18c8: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_18cc:
	/* 0x18cc: movzx  ebp,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_18d1:
	/* 0x18d1: je     18d8 <tracepoint__sched__sched_process_exec+0x18d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d8;
	}
x86_l_18d3:
	/* 0x18d3: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_18d6:
	/* 0x18d6: jbe    18e3 <tracepoint__sched__sched_process_exec+0x18e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_18e3;
	}
x86_l_18d8:
	/* 0x18d8: and    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 136ULL);
x86_l_18e0:
	/* 0x18e0: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_18e3:
	/* 0x18e3: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_18e6:
	/* 0x18e6: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_18e9:
	/* 0x18e9: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_18f1:
	/* 0x18f1: je     19ae <tracepoint__sched__sched_process_exec+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ae;
	}
x86_l_18f7:
	/* 0x18f7: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_18fc:
	/* 0x18fc: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1903:
	/* 0x1903: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1908:
	/* 0x1908: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_190d:
	/* 0x190d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1912:
	/* 0x1912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1914:
	/* 0x1914: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1919:
	/* 0x1919: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_191d:
	/* 0x191d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1922:
	/* 0x1922: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1927:
	/* 0x1927: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_192c:
	/* 0x192c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192e:
	/* 0x192e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1933:
	/* 0x1933: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1938:
	/* 0x1938: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193d:
	/* 0x193d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1942:
	/* 0x1942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1944:
	/* 0x1944: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1948:
	/* 0x1948: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_194c:
	/* 0x194c: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1953:
	/* 0x1953: mov    r12,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_195a:
	/* 0x195a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_195d:
	/* 0x195d: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1962:
	/* 0x1962: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1967:
	/* 0x1967: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_196e:
	/* 0x196e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1973:
	/* 0x1973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1975:
	/* 0x1975: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_197c:
	/* 0x197c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_197f:
	/* 0x197f: je     19a0 <tracepoint__sched__sched_process_exec+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a0;
	}
x86_l_1981:
	/* 0x1981: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1985:
	/* 0x1985: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_198a:
	/* 0x198a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_198d:
	/* 0x198d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_198f:
	/* 0x198f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1992:
	/* 0x1992: je     19a0 <tracepoint__sched__sched_process_exec+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a0;
	}
x86_l_1994:
	/* 0x1994: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1997:
	/* 0x1997: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199b:
	/* 0x199b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_199e:
	/* 0x199e: jmp    19a2 <tracepoint__sched__sched_process_exec+0x19a2> */
	goto x86_l_19a2;
x86_l_19a0:
	/* 0x19a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a2:
	/* 0x19a2: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19a5:
	/* 0x19a5: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_19a8:
	/* 0x19a8: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19ab:
	/* 0x19ab: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_19ae:
	/* 0x19ae: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_19b6:
	/* 0x19b6: je     1a96 <tracepoint__sched__sched_process_exec+0x1a96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a96;
	}
x86_l_19bc:
	/* 0x19bc: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_19c3:
	/* 0x19c3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19c7:
	/* 0x19c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19cc:
	/* 0x19cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19d1:
	/* 0x19d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19d6:
	/* 0x19d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d8:
	/* 0x19d8: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19dd:
	/* 0x19dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19e2:
	/* 0x19e2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19e7:
	/* 0x19e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ec:
	/* 0x19ec: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19ef:
	/* 0x19ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f1:
	/* 0x19f1: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19f5:
	/* 0x19f5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_19f9:
	/* 0x19f9: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_19fd:
	/* 0x19fd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a01:
	/* 0x1a01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a06:
	/* 0x1a06: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a10:
	/* 0x1a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a12:
	/* 0x1a12: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a17:
	/* 0x1a17: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a20:
	/* 0x1a20: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a25:
	/* 0x1a25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a2a:
	/* 0x1a2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2c:
	/* 0x1a2c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a30:
	/* 0x1a30: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a34:
	/* 0x1a34: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    r12,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1a42:
	/* 0x1a42: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a45:
	/* 0x1a45: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1a56:
	/* 0x1a56: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a5b:
	/* 0x1a5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5d:
	/* 0x1a5d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1a64:
	/* 0x1a64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a67:
	/* 0x1a67: je     1a88 <tracepoint__sched__sched_process_exec+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a88;
	}
x86_l_1a69:
	/* 0x1a69: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1a72:
	/* 0x1a72: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a75:
	/* 0x1a75: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a77:
	/* 0x1a77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a7a:
	/* 0x1a7a: je     1a88 <tracepoint__sched__sched_process_exec+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a88;
	}
x86_l_1a7c:
	/* 0x1a7c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a83:
	/* 0x1a83: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a86:
	/* 0x1a86: jmp    1a8a <tracepoint__sched__sched_process_exec+0x1a8a> */
	goto x86_l_1a8a;
x86_l_1a88:
	/* 0x1a88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8a:
	/* 0x1a8a: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a8d:
	/* 0x1a8d: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a90:
	/* 0x1a90: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a93:
	/* 0x1a93: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a96:
	/* 0x1a96: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1a9e:
	/* 0x1a9e: je     1b6c <tracepoint__sched__sched_process_exec+0x1b6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6c;
	}
x86_l_1aa4:
	/* 0x1aa4: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1aa9:
	/* 0x1aa9: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab5:
	/* 0x1ab5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aba:
	/* 0x1aba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1abf:
	/* 0x1abf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac1:
	/* 0x1ac1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1acb:
	/* 0x1acb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad5:
	/* 0x1ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad7:
	/* 0x1ad7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1adc:
	/* 0x1adc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae1:
	/* 0x1ae1: lea    rbp,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1ae9:
	/* 0x1ae9: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1aee:
	/* 0x1aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af0:
	/* 0x1af0: lea    r13,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1af4:
	/* 0x1af4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1af9:
	/* 0x1af9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1afc:
	/* 0x1afc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b01:
	/* 0x1b01: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b04:
	/* 0x1b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b06:
	/* 0x1b06: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1b14:
	/* 0x1b14: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b17:
	/* 0x1b17: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1b1c:
	/* 0x1b1c: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b21:
	/* 0x1b21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b26:
	/* 0x1b26: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1b2d:
	/* 0x1b2d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b32:
	/* 0x1b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b34:
	/* 0x1b34: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b3b:
	/* 0x1b3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b3e:
	/* 0x1b3e: je     1b5e <tracepoint__sched__sched_process_exec+0x1b5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5e;
	}
x86_l_1b40:
	/* 0x1b40: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b45:
	/* 0x1b45: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1b4b:
	/* 0x1b4b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b4d:
	/* 0x1b4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b50:
	/* 0x1b50: je     1b5e <tracepoint__sched__sched_process_exec+0x1b5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5e;
	}
x86_l_1b52:
	/* 0x1b52: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b55:
	/* 0x1b55: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b59:
	/* 0x1b59: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b5c:
	/* 0x1b5c: jmp    1b60 <tracepoint__sched__sched_process_exec+0x1b60> */
	goto x86_l_1b60;
x86_l_1b5e:
	/* 0x1b5e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b60:
	/* 0x1b60: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b63:
	/* 0x1b63: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1b66:
	/* 0x1b66: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b69:
	/* 0x1b69: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1b6c:
	/* 0x1b6c: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1b74:
	/* 0x1b74: movzx  ebp,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1b79:
	/* 0x1b79: je     1bf4 <tracepoint__sched__sched_process_exec+0x1bf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7156ULL;
	}
x86_l_1b7b:
	/* 0x1b7b: lea    r13,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1b84:
	/* 0x1b84: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b87:
	/* 0x1b87: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b8c:
	/* 0x1b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8e:
	/* 0x1b8e: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1b95:
	/* 0x1b95: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1b9c:
	/* 0x1b9c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b9f:
	/* 0x1b9f: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1bb0:
	/* 0x1bb0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bb5:
	/* 0x1bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb7:
	/* 0x1bb7: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1bbe:
	/* 0x1bbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bc1:
	/* 0x1bc1: je     1be1 <tracepoint__sched__sched_process_exec+0x1be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7137ULL;
	}
x86_l_1bc3:
	/* 0x1bc3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
	return 7112ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7118ULL: goto x86_l_1bce;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7125ULL: goto x86_l_1bd5;
	case 7128ULL: goto x86_l_1bd8;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7145ULL: goto x86_l_1be9;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7172ULL: goto x86_l_1c04;
	case 7176ULL: goto x86_l_1c08;
	case 7183ULL: goto x86_l_1c0f;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7217ULL: goto x86_l_1c31;
	case 7220ULL: goto x86_l_1c34;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7235ULL: goto x86_l_1c43;
	case 7237ULL: goto x86_l_1c45;
	case 7240ULL: goto x86_l_1c48;
	case 7242ULL: goto x86_l_1c4a;
	case 7245ULL: goto x86_l_1c4d;
	case 7249ULL: goto x86_l_1c51;
	case 7252ULL: goto x86_l_1c54;
	case 7254ULL: goto x86_l_1c56;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7265ULL: goto x86_l_1c61;
	case 7268ULL: goto x86_l_1c64;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7287ULL: goto x86_l_1c77;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7321ULL: goto x86_l_1c99;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7334ULL: goto x86_l_1ca6;
	case 7342ULL: goto x86_l_1cae;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7356ULL: goto x86_l_1cbc;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7394ULL: goto x86_l_1ce2;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7428ULL: goto x86_l_1d04;
	case 7431ULL: goto x86_l_1d07;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7482ULL: goto x86_l_1d3a;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7498ULL: goto x86_l_1d4a;
	case 7501ULL: goto x86_l_1d4d;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7510ULL: goto x86_l_1d56;
	case 7518ULL: goto x86_l_1d5e;
	case 7525ULL: goto x86_l_1d65;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7547ULL: goto x86_l_1d7b;
	case 7550ULL: goto x86_l_1d7e;
	case 7557ULL: goto x86_l_1d85;
	case 7561ULL: goto x86_l_1d89;
	case 7565ULL: goto x86_l_1d8d;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7632ULL: goto x86_l_1dd0;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7651ULL: goto x86_l_1de3;
	case 7658ULL: goto x86_l_1dea;
	case 7661ULL: goto x86_l_1ded;
	case 7667ULL: goto x86_l_1df3;
	case 7675ULL: goto x86_l_1dfb;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7725ULL: goto x86_l_1e2d;
	case 7733ULL: goto x86_l_1e35;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7749ULL: goto x86_l_1e45;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7762ULL: goto x86_l_1e52;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7774ULL: goto x86_l_1e5e;
	case 7778ULL: goto x86_l_1e62;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7794ULL: goto x86_l_1e72;
	case 7797ULL: goto x86_l_1e75;
	case 7800ULL: goto x86_l_1e78;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7848ULL: goto x86_l_1ea8;
	case 7851ULL: goto x86_l_1eab;
	case 7859ULL: goto x86_l_1eb3;
	case 7865ULL: goto x86_l_1eb9;
	case 7872ULL: goto x86_l_1ec0;
	case 7880ULL: goto x86_l_1ec8;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7899ULL: goto x86_l_1edb;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7968ULL: goto x86_l_1f20;
	case 7970ULL: goto x86_l_1f22;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7978ULL: goto x86_l_1f2a;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7987ULL: goto x86_l_1f33;
	case 7990ULL: goto x86_l_1f36;
	case 7998ULL: goto x86_l_1f3e;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8014ULL: goto x86_l_1f4e;
	case 8016ULL: goto x86_l_1f50;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8025ULL: goto x86_l_1f59;
	case 8027ULL: goto x86_l_1f5b;
	case 8035ULL: goto x86_l_1f63;
	case 8038ULL: goto x86_l_1f66;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8084ULL: goto x86_l_1f94;
	case 8087ULL: goto x86_l_1f97;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8103ULL: goto x86_l_1fa7;
	case 8110ULL: goto x86_l_1fae;
	case 8113ULL: goto x86_l_1fb1;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8143ULL: goto x86_l_1fcf;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8178ULL: goto x86_l_1ff2;
	case 8180ULL: goto x86_l_1ff4;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8213ULL: goto x86_l_2015;
	case 8222ULL: goto x86_l_201e;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8235ULL: goto x86_l_202b;
	case 8239ULL: goto x86_l_202f;
	case 8246ULL: goto x86_l_2036;
	case 8253ULL: goto x86_l_203d;
	case 8258ULL: goto x86_l_2042;
	case 8265ULL: goto x86_l_2049;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8297ULL: goto x86_l_2069;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8313ULL: goto x86_l_2079;
	case 8316ULL: goto x86_l_207c;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8331ULL: goto x86_l_208b;
	case 8333ULL: goto x86_l_208d;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8375ULL: goto x86_l_20b7;
	case 8379ULL: goto x86_l_20bb;
	case 8384ULL: goto x86_l_20c0;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8413ULL: goto x86_l_20dd;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8500ULL: goto x86_l_2134;
	case 8504ULL: goto x86_l_2138;
	case 8511ULL: goto x86_l_213f;
	case 8518ULL: goto x86_l_2146;
	case 8521ULL: goto x86_l_2149;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8553ULL: goto x86_l_2169;
	case 8560ULL: goto x86_l_2170;
	case 8563ULL: goto x86_l_2173;
	case 8565ULL: goto x86_l_2175;
	case 8569ULL: goto x86_l_2179;
	case 8574ULL: goto x86_l_217e;
	case 8577ULL: goto x86_l_2181;
	case 8579ULL: goto x86_l_2183;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8596ULL: goto x86_l_2194;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8631ULL: goto x86_l_21b7;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bc8:
	/* 0x1bc8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1bcb:
	/* 0x1bcb: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1bce:
	/* 0x1bce: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bd0:
	/* 0x1bd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bd3:
	/* 0x1bd3: je     1be1 <tracepoint__sched__sched_process_exec+0x1be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be1;
	}
x86_l_1bd5:
	/* 0x1bd5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdc:
	/* 0x1bdc: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1bdf:
	/* 0x1bdf: jmp    1be3 <tracepoint__sched__sched_process_exec+0x1be3> */
	goto x86_l_1be3;
x86_l_1be1:
	/* 0x1be1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be3:
	/* 0x1be3: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1be6:
	/* 0x1be6: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1be9:
	/* 0x1be9: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bec:
	/* 0x1bec: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1bef:
	/* 0x1bef: movzx  ebp,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1bfb:
	/* 0x1bfb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1bfe:
	/* 0x1bfe: je     1c64 <tracepoint__sched__sched_process_exec+0x1c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c64;
	}
x86_l_1c00:
	/* 0x1c00: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c04:
	/* 0x1c04: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c08:
	/* 0x1c08: mov    r12,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1c0f:
	/* 0x1c0f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c12:
	/* 0x1c12: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c17:
	/* 0x1c17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1c23:
	/* 0x1c23: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c28:
	/* 0x1c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2a:
	/* 0x1c2a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c31:
	/* 0x1c31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c34:
	/* 0x1c34: je     1c56 <tracepoint__sched__sched_process_exec+0x1c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c56;
	}
x86_l_1c36:
	/* 0x1c36: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c3b:
	/* 0x1c3b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c40:
	/* 0x1c40: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c43:
	/* 0x1c43: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c45:
	/* 0x1c45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c48:
	/* 0x1c48: je     1c56 <tracepoint__sched__sched_process_exec+0x1c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c56;
	}
x86_l_1c4a:
	/* 0x1c4a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c51:
	/* 0x1c51: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c54:
	/* 0x1c54: jmp    1c58 <tracepoint__sched__sched_process_exec+0x1c58> */
	goto x86_l_1c58;
x86_l_1c56:
	/* 0x1c56: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c58:
	/* 0x1c58: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c5b:
	/* 0x1c5b: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c5e:
	/* 0x1c5e: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c61:
	/* 0x1c61: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c64:
	/* 0x1c64: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1c6b:
	/* 0x1c6b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1c6e:
	/* 0x1c6e: je     1ccf <tracepoint__sched__sched_process_exec+0x1ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ccf;
	}
x86_l_1c70:
	/* 0x1c70: mov    r12,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1c77:
	/* 0x1c77: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c7a:
	/* 0x1c7a: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1c8b:
	/* 0x1c8b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c99:
	/* 0x1c99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c9c:
	/* 0x1c9c: je     1cc1 <tracepoint__sched__sched_process_exec+0x1cc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc1;
	}
x86_l_1c9e:
	/* 0x1c9e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ca3:
	/* 0x1ca3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ca6:
	/* 0x1ca6: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1cae:
	/* 0x1cae: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cb0:
	/* 0x1cb0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cb3:
	/* 0x1cb3: je     1cc1 <tracepoint__sched__sched_process_exec+0x1cc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc1;
	}
x86_l_1cb5:
	/* 0x1cb5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbc:
	/* 0x1cbc: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1cbf:
	/* 0x1cbf: jmp    1cc3 <tracepoint__sched__sched_process_exec+0x1cc3> */
	goto x86_l_1cc3;
x86_l_1cc1:
	/* 0x1cc1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc3:
	/* 0x1cc3: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cc6:
	/* 0x1cc6: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cc9:
	/* 0x1cc9: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ccc:
	/* 0x1ccc: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1ccf:
	/* 0x1ccf: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1cd6:
	/* 0x1cd6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1cd9:
	/* 0x1cd9: je     1d56 <tracepoint__sched__sched_process_exec+0x1d56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d56;
	}
x86_l_1cdb:
	/* 0x1cdb: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1ce2:
	/* 0x1ce2: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ce5:
	/* 0x1ce5: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cea:
	/* 0x1cea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cef:
	/* 0x1cef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1cf6:
	/* 0x1cf6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cfb:
	/* 0x1cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfd:
	/* 0x1cfd: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d04:
	/* 0x1d04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d07:
	/* 0x1d07: je     1d48 <tracepoint__sched__sched_process_exec+0x1d48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d48;
	}
x86_l_1d09:
	/* 0x1d09: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1d0c:
	/* 0x1d0c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d11:
	/* 0x1d11: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d15:
	/* 0x1d15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1d1d:
	/* 0x1d1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1f:
	/* 0x1d1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d22:
	/* 0x1d22: jne    1d3c <tracepoint__sched__sched_process_exec+0x1d3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d3c;
	}
x86_l_1d24:
	/* 0x1d24: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d29:
	/* 0x1d29: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d32:
	/* 0x1d32: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1d35:
	/* 0x1d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d37:
	/* 0x1d37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d3a:
	/* 0x1d3a: je     1d48 <tracepoint__sched__sched_process_exec+0x1d48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d48;
	}
x86_l_1d3c:
	/* 0x1d3c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d43:
	/* 0x1d43: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d46:
	/* 0x1d46: jmp    1d4a <tracepoint__sched__sched_process_exec+0x1d4a> */
	goto x86_l_1d4a;
x86_l_1d48:
	/* 0x1d48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4a:
	/* 0x1d4a: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d4d:
	/* 0x1d4d: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d50:
	/* 0x1d50: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d53:
	/* 0x1d53: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d56:
	/* 0x1d56: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1d65:
	/* 0x1d65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d68:
	/* 0x1d68: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d75:
	/* 0x1d75: je     1d7e <tracepoint__sched__sched_process_exec+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7e;
	}
x86_l_1d77:
	/* 0x1d77: and    rax,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1d7b:
	/* 0x1d7b: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d7e:
	/* 0x1d7e: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1d85:
	/* 0x1d85: mov    QWORD PTR [rbp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d89:
	/* 0x1d89: mov    BYTE PTR [rbp+0x0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1d8d:
	/* 0x1d8d: lea    r15,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d91:
	/* 0x1d91: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d94:
	/* 0x1d94: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1d99:
	/* 0x1d99: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d9c:
	/* 0x1d9c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9e:
	/* 0x1d9e: call   1da3 <tracepoint__sched__sched_process_exec+0x1da3> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_1da3:
	/* 0x1da3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1da8:
	/* 0x1da8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1db0:
	/* 0x1db0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1db5:
	/* 0x1db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db7:
	/* 0x1db7: mov    eax,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc0:
	/* 0x1dc0: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1dc4:
	/* 0x1dc4: jne    1ddb <tracepoint__sched__sched_process_exec+0x1ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ddb;
	}
x86_l_1dc6:
	/* 0x1dc6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc9:
	/* 0x1dc9: and    QWORD PTR [r14+0x80],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1dd0:
	/* 0x1dd0: jne    25b6 <tracepoint__sched__sched_process_exec+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9654ULL;
	}
x86_l_1dd6:
	/* 0x1dd6: jmp    2b8e <tracepoint__sched__sched_process_exec+0x2b8e> */
	return 11150ULL;
x86_l_1ddb:
	/* 0x1ddb: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1de3:
	/* 0x1de3: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_1dea:
	/* 0x1dea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ded:
	/* 0x1ded: je     1fa0 <tracepoint__sched__sched_process_exec+0x1fa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fa0;
	}
x86_l_1df3:
	/* 0x1df3: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1dfb:
	/* 0x1dfb: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_1e02:
	/* 0x1e02: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1e05:
	/* 0x1e05: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e08:
	/* 0x1e08: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1e0b:
	/* 0x1e0b: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_1e0f:
	/* 0x1e0f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e12:
	/* 0x1e12: neg    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1e15:
	/* 0x1e15: xor    r15,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_1e1c:
	/* 0x1e1c: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e1f:
	/* 0x1e1f: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1e26:
	/* 0x1e26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e29:
	/* 0x1e29: je     1e52 <tracepoint__sched__sched_process_exec+0x1e52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e52;
	}
x86_l_1e2b:
	/* 0x1e2b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e2d:
	/* 0x1e2d: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e35:
	/* 0x1e35: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1e3c:
	/* 0x1e3c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1e3f:
	/* 0x1e3f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e42:
	/* 0x1e42: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1e45:
	/* 0x1e45: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1e4c:
	/* 0x1e4c: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e4f:
	/* 0x1e4f: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e52:
	/* 0x1e52: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_1e59:
	/* 0x1e59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e5c:
	/* 0x1e5c: je     1e78 <tracepoint__sched__sched_process_exec+0x1e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e78;
	}
x86_l_1e5e:
	/* 0x1e5e: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1e62:
	/* 0x1e62: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e65:
	/* 0x1e65: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1e68:
	/* 0x1e68: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1e6b:
	/* 0x1e6b: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_1e72:
	/* 0x1e72: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e75:
	/* 0x1e75: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e78:
	/* 0x1e78: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_1e7f:
	/* 0x1e7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e82:
	/* 0x1e82: je     1e9c <tracepoint__sched__sched_process_exec+0x1e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9c;
	}
x86_l_1e84:
	/* 0x1e84: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e87:
	/* 0x1e87: movsx  rcx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e8c:
	/* 0x1e8c: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1e8f:
	/* 0x1e8f: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1e96:
	/* 0x1e96: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e99:
	/* 0x1e99: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e9c:
	/* 0x1e9c: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_1ea8:
	/* 0x1ea8: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1eab:
	/* 0x1eab: mov    WORD PTR [rsp+0x80],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1eb3:
	/* 0x1eb3: je     200d <tracepoint__sched__sched_process_exec+0x200d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200d;
	}
x86_l_1eb9:
	/* 0x1eb9: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_1edb:
	/* 0x1edb: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee8:
	/* 0x1ee8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1eed:
	/* 0x1eed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_1ef4:
	/* 0x1ef4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ef9:
	/* 0x1ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efb:
	/* 0x1efb: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1efe:
	/* 0x1efe: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f02:
	/* 0x1f02: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f07:
	/* 0x1f07: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f0e:
	/* 0x1f0e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f11:
	/* 0x1f11: je     1f33 <tracepoint__sched__sched_process_exec+0x1f33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f33;
	}
x86_l_1f13:
	/* 0x1f13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f18:
	/* 0x1f18: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f1d:
	/* 0x1f1d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f20:
	/* 0x1f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f22:
	/* 0x1f22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f25:
	/* 0x1f25: je     1f33 <tracepoint__sched__sched_process_exec+0x1f33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f33;
	}
x86_l_1f27:
	/* 0x1f27: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2a:
	/* 0x1f2a: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2e:
	/* 0x1f2e: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f31:
	/* 0x1f31: jmp    1f36 <tracepoint__sched__sched_process_exec+0x1f36> */
	goto x86_l_1f36;
x86_l_1f33:
	/* 0x1f33: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f36:
	/* 0x1f36: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f3e:
	/* 0x1f3e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f43:
	/* 0x1f43: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f48:
	/* 0x1f48: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1f4b:
	/* 0x1f4b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1f4e:
	/* 0x1f4e: jb     1f66 <tracepoint__sched__sched_process_exec+0x1f66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f66;
	}
x86_l_1f50:
	/* 0x1f50: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f54:
	/* 0x1f54: je     1f5b <tracepoint__sched__sched_process_exec+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5b;
	}
x86_l_1f56:
	/* 0x1f56: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1f59:
	/* 0x1f59: jbe    1f66 <tracepoint__sched__sched_process_exec+0x1f66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f66;
	}
x86_l_1f5b:
	/* 0x1f5b: and    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 160ULL);
x86_l_1f63:
	/* 0x1f63: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f66:
	/* 0x1f66: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f76:
	/* 0x1f76: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f79:
	/* 0x1f79: je     1fbc <tracepoint__sched__sched_process_exec+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1f7b:
	/* 0x1f7b: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f80:
	/* 0x1f80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f85:
	/* 0x1f85: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f8d:
	/* 0x1f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8f:
	/* 0x1f8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f92:
	/* 0x1f92: je     1fcd <tracepoint__sched__sched_process_exec+0x1fcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fcd;
	}
x86_l_1f94:
	/* 0x1f94: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f97:
	/* 0x1f97: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f9b:
	/* 0x1f9b: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f9e:
	/* 0x1f9e: jmp    1fcf <tracepoint__sched__sched_process_exec+0x1fcf> */
	goto x86_l_1fcf;
x86_l_1fa0:
	/* 0x1fa0: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1fae:
	/* 0x1fae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb1:
	/* 0x1fb1: jne    1e2b <tracepoint__sched__sched_process_exec+0x1e2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e2b;
	}
x86_l_1fb7:
	/* 0x1fb7: jmp    1e52 <tracepoint__sched__sched_process_exec+0x1e52> */
	goto x86_l_1e52;
x86_l_1fbc:
	/* 0x1fbc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fbe:
	/* 0x1fbe: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1fc1:
	/* 0x1fc1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc6:
	/* 0x1fc6: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1fc9:
	/* 0x1fc9: jae    1fe9 <tracepoint__sched__sched_process_exec+0x1fe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fe9;
	}
x86_l_1fcb:
	/* 0x1fcb: jmp    1fff <tracepoint__sched__sched_process_exec+0x1fff> */
	goto x86_l_1fff;
x86_l_1fcd:
	/* 0x1fcd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcf:
	/* 0x1fcf: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1fd7:
	/* 0x1fd7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fdc:
	/* 0x1fdc: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1fdf:
	/* 0x1fdf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fe4:
	/* 0x1fe4: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1fe7:
	/* 0x1fe7: jb     1fff <tracepoint__sched__sched_process_exec+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1fff;
	}
x86_l_1fe9:
	/* 0x1fe9: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1fed:
	/* 0x1fed: je     1ff4 <tracepoint__sched__sched_process_exec+0x1ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff4;
	}
x86_l_1fef:
	/* 0x1fef: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1ff2:
	/* 0x1ff2: jbe    1fff <tracepoint__sched__sched_process_exec+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1fff;
	}
x86_l_1ff4:
	/* 0x1ff4: and    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 160ULL);
x86_l_1ffc:
	/* 0x1ffc: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_1fff:
	/* 0x1fff: or     r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_2002:
	/* 0x2002: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2005:
	/* 0x2005: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2008:
	/* 0x2008: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_200d:
	/* 0x200d: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_2015:
	/* 0x2015: movzx  r12d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_201e:
	/* 0x201e: je     20d5 <tracepoint__sched__sched_process_exec+0x20d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d5;
	}
x86_l_2024:
	/* 0x2024: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2029:
	/* 0x2029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202b:
	/* 0x202b: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_202f:
	/* 0x202f: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2036:
	/* 0x2036: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_203d:
	/* 0x203d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2042:
	/* 0x2042: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_2049:
	/* 0x2049: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_2050:
	/* 0x2050: mov    WORD PTR [rsp+0x30],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2056:
	/* 0x2056: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_205b:
	/* 0x205b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_2062:
	/* 0x2062: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2067:
	/* 0x2067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2069:
	/* 0x2069: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_206d:
	/* 0x206d: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2072:
	/* 0x2072: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2079:
	/* 0x2079: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_207c:
	/* 0x207c: je     209e <tracepoint__sched__sched_process_exec+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209e;
	}
x86_l_207e:
	/* 0x207e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2083:
	/* 0x2083: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2088:
	/* 0x2088: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_208b:
	/* 0x208b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_208d:
	/* 0x208d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2090:
	/* 0x2090: je     209e <tracepoint__sched__sched_process_exec+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209e;
	}
x86_l_2092:
	/* 0x2092: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2095:
	/* 0x2095: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2099:
	/* 0x2099: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_209c:
	/* 0x209c: jmp    20a0 <tracepoint__sched__sched_process_exec+0x20a0> */
	goto x86_l_20a0;
x86_l_209e:
	/* 0x209e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a0:
	/* 0x20a0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_20a3:
	/* 0x20a3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20a8:
	/* 0x20a8: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_20ab:
	/* 0x20ab: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_20ae:
	/* 0x20ae: jae    20b7 <tracepoint__sched__sched_process_exec+0x20b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_20b7;
	}
x86_l_20b0:
	/* 0x20b0: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b5:
	/* 0x20b5: jmp    20cf <tracepoint__sched__sched_process_exec+0x20cf> */
	goto x86_l_20cf;
x86_l_20b7:
	/* 0x20b7: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_20bb:
	/* 0x20bb: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c0:
	/* 0x20c0: je     20c7 <tracepoint__sched__sched_process_exec+0x20c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c7;
	}
x86_l_20c2:
	/* 0x20c2: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_20c5:
	/* 0x20c5: jbe    20cf <tracepoint__sched__sched_process_exec+0x20cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20cf;
	}
x86_l_20c7:
	/* 0x20c7: and    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 40ULL);
x86_l_20cc:
	/* 0x20cc: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_20cf:
	/* 0x20cf: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_20d2:
	/* 0x20d2: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_20d5:
	/* 0x20d5: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_20dd:
	/* 0x20dd: je     21a2 <tracepoint__sched__sched_process_exec+0x21a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a2;
	}
x86_l_20e3:
	/* 0x20e3: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_20e8:
	/* 0x20e8: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_20ef:
	/* 0x20ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f4:
	/* 0x20f4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20f9:
	/* 0x20f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20fe:
	/* 0x20fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2100:
	/* 0x2100: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2105:
	/* 0x2105: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2109:
	/* 0x2109: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_210e:
	/* 0x210e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2113:
	/* 0x2113: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2118:
	/* 0x2118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211a:
	/* 0x211a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_211f:
	/* 0x211f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2124:
	/* 0x2124: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2129:
	/* 0x2129: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_212e:
	/* 0x212e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2130:
	/* 0x2130: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2134:
	/* 0x2134: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2138:
	/* 0x2138: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_213f:
	/* 0x213f: mov    r12,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_2146:
	/* 0x2146: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2149:
	/* 0x2149: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_2151:
	/* 0x2151: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2156:
	/* 0x2156: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_215b:
	/* 0x215b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_2162:
	/* 0x2162: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2167:
	/* 0x2167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2169:
	/* 0x2169: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2170:
	/* 0x2170: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2173:
	/* 0x2173: je     2194 <tracepoint__sched__sched_process_exec+0x2194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2194;
	}
x86_l_2175:
	/* 0x2175: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2179:
	/* 0x2179: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_217e:
	/* 0x217e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2181:
	/* 0x2181: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2183:
	/* 0x2183: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2186:
	/* 0x2186: je     2194 <tracepoint__sched__sched_process_exec+0x2194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2194;
	}
x86_l_2188:
	/* 0x2188: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218b:
	/* 0x218b: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_218f:
	/* 0x218f: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2192:
	/* 0x2192: jmp    2196 <tracepoint__sched__sched_process_exec+0x2196> */
	goto x86_l_2196;
x86_l_2194:
	/* 0x2194: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2196:
	/* 0x2196: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2199:
	/* 0x2199: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_219c:
	/* 0x219c: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_219f:
	/* 0x219f: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_21a2:
	/* 0x21a2: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_21aa:
	/* 0x21aa: je     2292 <tracepoint__sched__sched_process_exec+0x2292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8850ULL;
	}
x86_l_21b0:
	/* 0x21b0: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_21b7:
	/* 0x21b7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_21bb:
	/* 0x21bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21c0:
	/* 0x21c0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21c5:
	/* 0x21c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21ca:
	/* 0x21ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cc:
	/* 0x21cc: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21d1:
	/* 0x21d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21d6:
	/* 0x21d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21db:
	/* 0x21db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21e0:
	/* 0x21e0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
	return 8675ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8681ULL: goto x86_l_21e9;
	case 8685ULL: goto x86_l_21ed;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8740ULL: goto x86_l_2224;
	case 8744ULL: goto x86_l_2228;
	case 8751ULL: goto x86_l_222f;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8779ULL: goto x86_l_224b;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8793ULL: goto x86_l_2259;
	case 8800ULL: goto x86_l_2260;
	case 8803ULL: goto x86_l_2263;
	case 8805ULL: goto x86_l_2265;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8819ULL: goto x86_l_2273;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8831ULL: goto x86_l_227f;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8838ULL: goto x86_l_2286;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8847ULL: goto x86_l_228f;
	case 8850ULL: goto x86_l_2292;
	case 8858ULL: goto x86_l_229a;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8940ULL: goto x86_l_22ec;
	case 8944ULL: goto x86_l_22f0;
	case 8949ULL: goto x86_l_22f5;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8969ULL: goto x86_l_2309;
	case 8976ULL: goto x86_l_2310;
	case 8979ULL: goto x86_l_2313;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9018ULL: goto x86_l_233a;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9055ULL: goto x86_l_235f;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9080ULL: goto x86_l_2378;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9112ULL: goto x86_l_2398;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9154ULL: goto x86_l_23c2;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9184ULL: goto x86_l_23e0;
	case 9187ULL: goto x86_l_23e3;
	case 9191ULL: goto x86_l_23e7;
	case 9194ULL: goto x86_l_23ea;
	case 9196ULL: goto x86_l_23ec;
	case 9198ULL: goto x86_l_23ee;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9222ULL: goto x86_l_2406;
	case 9225ULL: goto x86_l_2409;
	case 9227ULL: goto x86_l_240b;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9242ULL: goto x86_l_241a;
	case 9245ULL: goto x86_l_241d;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9263ULL: goto x86_l_242f;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9284ULL: goto x86_l_2444;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9302ULL: goto x86_l_2456;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9326ULL: goto x86_l_246e;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9342ULL: goto x86_l_247e;
	case 9345ULL: goto x86_l_2481;
	case 9347ULL: goto x86_l_2483;
	case 9354ULL: goto x86_l_248a;
	case 9357ULL: goto x86_l_248d;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9396ULL: goto x86_l_24b4;
	case 9399ULL: goto x86_l_24b7;
	case 9401ULL: goto x86_l_24b9;
	case 9406ULL: goto x86_l_24be;
	case 9409ULL: goto x86_l_24c1;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9422ULL: goto x86_l_24ce;
	case 9424ULL: goto x86_l_24d0;
	case 9427ULL: goto x86_l_24d3;
	case 9431ULL: goto x86_l_24d7;
	case 9434ULL: goto x86_l_24da;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9450ULL: goto x86_l_24ea;
	case 9457ULL: goto x86_l_24f1;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9473ULL: goto x86_l_2501;
	case 9476ULL: goto x86_l_2504;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9508ULL: goto x86_l_2524;
	case 9515ULL: goto x86_l_252b;
	case 9518ULL: goto x86_l_252e;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9531ULL: goto x86_l_253b;
	case 9539ULL: goto x86_l_2543;
	case 9541ULL: goto x86_l_2545;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9573ULL: goto x86_l_2565;
	case 9577ULL: goto x86_l_2569;
	case 9580ULL: goto x86_l_256c;
	case 9582ULL: goto x86_l_256e;
	case 9584ULL: goto x86_l_2570;
	case 9587ULL: goto x86_l_2573;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9608ULL: goto x86_l_2588;
	case 9611ULL: goto x86_l_258b;
	case 9619ULL: goto x86_l_2593;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9631ULL: goto x86_l_259f;
	case 9634ULL: goto x86_l_25a2;
	case 9641ULL: goto x86_l_25a9;
	case 9648ULL: goto x86_l_25b0;
	case 9654ULL: goto x86_l_25b6;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9707ULL: goto x86_l_25eb;
	case 9710ULL: goto x86_l_25ee;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9785ULL: goto x86_l_2639;
	case 9787ULL: goto x86_l_263b;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9871ULL: goto x86_l_268f;
	case 9876ULL: goto x86_l_2694;
	case 9878ULL: goto x86_l_2696;
	case 9883ULL: goto x86_l_269b;
	case 9888ULL: goto x86_l_26a0;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9910ULL: goto x86_l_26b6;
	case 9912ULL: goto x86_l_26b8;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9975ULL: goto x86_l_26f7;
	case 9982ULL: goto x86_l_26fe;
	case 9987ULL: goto x86_l_2703;
	case 9989ULL: goto x86_l_2705;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10066ULL: goto x86_l_2752;
	case 10075ULL: goto x86_l_275b;
	case 10083ULL: goto x86_l_2763;
	case 10091ULL: goto x86_l_276b;
	case 10097ULL: goto x86_l_2771;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10112ULL: goto x86_l_2780;
	case 10116ULL: goto x86_l_2784;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10145ULL: goto x86_l_27a1;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10162ULL: goto x86_l_27b2;
	case 10170ULL: goto x86_l_27ba;
	case 10173ULL: goto x86_l_27bd;
	case 10181ULL: goto x86_l_27c5;
	case 10188ULL: goto x86_l_27cc;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10210ULL: goto x86_l_27e2;
	case 10219ULL: goto x86_l_27eb;
	case 10227ULL: goto x86_l_27f3;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10242ULL: goto x86_l_2802;
	case 10247ULL: goto x86_l_2807;
	case 10255ULL: goto x86_l_280f;
	case 10259ULL: goto x86_l_2813;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10274ULL: goto x86_l_2822;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10288ULL: goto x86_l_2830;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10305ULL: goto x86_l_2841;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10324ULL: goto x86_l_2854;
	case 10331ULL: goto x86_l_285b;
	case 10339ULL: goto x86_l_2863;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21e3:
	/* 0x21e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e5:
	/* 0x21e5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e9:
	/* 0x21e9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_21ed:
	/* 0x21ed: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21f1:
	/* 0x21f1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_21f5:
	/* 0x21f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21fa:
	/* 0x21fa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ff:
	/* 0x21ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2204:
	/* 0x2204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2206:
	/* 0x2206: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_220b:
	/* 0x220b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_220f:
	/* 0x220f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2214:
	/* 0x2214: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2219:
	/* 0x2219: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_221e:
	/* 0x221e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2220:
	/* 0x2220: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2224:
	/* 0x2224: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2228:
	/* 0x2228: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_222f:
	/* 0x222f: mov    r12,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_2236:
	/* 0x2236: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2239:
	/* 0x2239: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_2241:
	/* 0x2241: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2246:
	/* 0x2246: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_224b:
	/* 0x224b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_2252:
	/* 0x2252: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2257:
	/* 0x2257: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2259:
	/* 0x2259: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2260:
	/* 0x2260: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2263:
	/* 0x2263: je     2284 <tracepoint__sched__sched_process_exec+0x2284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2284;
	}
x86_l_2265:
	/* 0x2265: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2269:
	/* 0x2269: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_226e:
	/* 0x226e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2271:
	/* 0x2271: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2273:
	/* 0x2273: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2276:
	/* 0x2276: je     2284 <tracepoint__sched__sched_process_exec+0x2284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2284;
	}
x86_l_2278:
	/* 0x2278: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227b:
	/* 0x227b: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227f:
	/* 0x227f: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2282:
	/* 0x2282: jmp    2286 <tracepoint__sched__sched_process_exec+0x2286> */
	goto x86_l_2286;
x86_l_2284:
	/* 0x2284: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2286:
	/* 0x2286: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2289:
	/* 0x2289: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_228c:
	/* 0x228c: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_228f:
	/* 0x228f: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2292:
	/* 0x2292: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_229a:
	/* 0x229a: je     2370 <tracepoint__sched__sched_process_exec+0x2370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2370;
	}
x86_l_22a0:
	/* 0x22a0: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_22a5:
	/* 0x22a5: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_22ac:
	/* 0x22ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22b1:
	/* 0x22b1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b6:
	/* 0x22b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22bb:
	/* 0x22bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bd:
	/* 0x22bd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22c2:
	/* 0x22c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c7:
	/* 0x22c7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22cc:
	/* 0x22cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d1:
	/* 0x22d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d3:
	/* 0x22d3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22d8:
	/* 0x22d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22dd:
	/* 0x22dd: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e2:
	/* 0x22e2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_22e5:
	/* 0x22e5: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_22ea:
	/* 0x22ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ec:
	/* 0x22ec: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_22f0:
	/* 0x22f0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_22f5:
	/* 0x22f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22f8:
	/* 0x22f8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22fd:
	/* 0x22fd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2300:
	/* 0x2300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2302:
	/* 0x2302: mov    r12,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_2309:
	/* 0x2309: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_2310:
	/* 0x2310: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2313:
	/* 0x2313: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_231b:
	/* 0x231b: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2320:
	/* 0x2320: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2325:
	/* 0x2325: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_232c:
	/* 0x232c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2331:
	/* 0x2331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2333:
	/* 0x2333: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_233a:
	/* 0x233a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_233d:
	/* 0x233d: je     235d <tracepoint__sched__sched_process_exec+0x235d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235d;
	}
x86_l_233f:
	/* 0x233f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2344:
	/* 0x2344: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2347:
	/* 0x2347: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_234a:
	/* 0x234a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_234c:
	/* 0x234c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_234f:
	/* 0x234f: je     235d <tracepoint__sched__sched_process_exec+0x235d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235d;
	}
x86_l_2351:
	/* 0x2351: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2354:
	/* 0x2354: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2358:
	/* 0x2358: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_235b:
	/* 0x235b: jmp    235f <tracepoint__sched__sched_process_exec+0x235f> */
	goto x86_l_235f;
x86_l_235d:
	/* 0x235d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_235f:
	/* 0x235f: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2362:
	/* 0x2362: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2365:
	/* 0x2365: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_2368:
	/* 0x2368: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_236b:
	/* 0x236b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2370:
	/* 0x2370: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_2378:
	/* 0x2378: je     23ff <tracepoint__sched__sched_process_exec+0x23ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ff;
	}
x86_l_237e:
	/* 0x237e: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2382:
	/* 0x2382: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2387:
	/* 0x2387: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_238a:
	/* 0x238a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_238f:
	/* 0x238f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2391:
	/* 0x2391: mov    r12,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_2398:
	/* 0x2398: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_239f:
	/* 0x239f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23a2:
	/* 0x23a2: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_23aa:
	/* 0x23aa: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23af:
	/* 0x23af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23b4:
	/* 0x23b4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_23bb:
	/* 0x23bb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23c0:
	/* 0x23c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c2:
	/* 0x23c2: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23c9:
	/* 0x23c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: je     23ec <tracepoint__sched__sched_process_exec+0x23ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ec;
	}
x86_l_23ce:
	/* 0x23ce: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23d3:
	/* 0x23d3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_23d6:
	/* 0x23d6: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_23db:
	/* 0x23db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23de:
	/* 0x23de: je     23ec <tracepoint__sched__sched_process_exec+0x23ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ec;
	}
x86_l_23e0:
	/* 0x23e0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e3:
	/* 0x23e3: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e7:
	/* 0x23e7: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23ea:
	/* 0x23ea: jmp    23ee <tracepoint__sched__sched_process_exec+0x23ee> */
	goto x86_l_23ee;
x86_l_23ec:
	/* 0x23ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23ee:
	/* 0x23ee: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_23f1:
	/* 0x23f1: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_23f4:
	/* 0x23f4: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_23f7:
	/* 0x23f7: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_23fa:
	/* 0x23fa: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23ff:
	/* 0x23ff: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_2406:
	/* 0x2406: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2409:
	/* 0x2409: je     2477 <tracepoint__sched__sched_process_exec+0x2477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2477;
	}
x86_l_240b:
	/* 0x240b: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240f:
	/* 0x240f: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2413:
	/* 0x2413: mov    r12,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_241a:
	/* 0x241a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_241d:
	/* 0x241d: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_2425:
	/* 0x2425: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_242a:
	/* 0x242a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242f:
	/* 0x242f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_2436:
	/* 0x2436: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243b:
	/* 0x243b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243d:
	/* 0x243d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2444:
	/* 0x2444: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2447:
	/* 0x2447: je     2469 <tracepoint__sched__sched_process_exec+0x2469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2469;
	}
x86_l_2449:
	/* 0x2449: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_244e:
	/* 0x244e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2453:
	/* 0x2453: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2456:
	/* 0x2456: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2458:
	/* 0x2458: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_245b:
	/* 0x245b: je     2469 <tracepoint__sched__sched_process_exec+0x2469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2469;
	}
x86_l_245d:
	/* 0x245d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2460:
	/* 0x2460: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2464:
	/* 0x2464: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2467:
	/* 0x2467: jmp    246b <tracepoint__sched__sched_process_exec+0x246b> */
	goto x86_l_246b;
x86_l_2469:
	/* 0x2469: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_246b:
	/* 0x246b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_246e:
	/* 0x246e: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2471:
	/* 0x2471: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2474:
	/* 0x2474: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2477:
	/* 0x2477: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_247e:
	/* 0x247e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2481:
	/* 0x2481: je     24ea <tracepoint__sched__sched_process_exec+0x24ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ea;
	}
x86_l_2483:
	/* 0x2483: mov    r12,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_248a:
	/* 0x248a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_248d:
	/* 0x248d: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_2495:
	/* 0x2495: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_249a:
	/* 0x249a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249f:
	/* 0x249f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_24a6:
	/* 0x24a6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ab:
	/* 0x24ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ad:
	/* 0x24ad: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_24b4:
	/* 0x24b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24b7:
	/* 0x24b7: je     24dc <tracepoint__sched__sched_process_exec+0x24dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24dc;
	}
x86_l_24b9:
	/* 0x24b9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24be:
	/* 0x24be: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_24c1:
	/* 0x24c1: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24c9:
	/* 0x24c9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_24cb:
	/* 0x24cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24ce:
	/* 0x24ce: je     24dc <tracepoint__sched__sched_process_exec+0x24dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24dc;
	}
x86_l_24d0:
	/* 0x24d0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d3:
	/* 0x24d3: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d7:
	/* 0x24d7: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24da:
	/* 0x24da: jmp    24de <tracepoint__sched__sched_process_exec+0x24de> */
	goto x86_l_24de;
x86_l_24dc:
	/* 0x24dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24de:
	/* 0x24de: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24e1:
	/* 0x24e1: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_24e4:
	/* 0x24e4: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24e7:
	/* 0x24e7: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_24ea:
	/* 0x24ea: mov    r12,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_24f1:
	/* 0x24f1: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_24f4:
	/* 0x24f4: je     2581 <tracepoint__sched__sched_process_exec+0x2581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2581;
	}
x86_l_24fa:
	/* 0x24fa: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_2501:
	/* 0x2501: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2504:
	/* 0x2504: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_250c:
	/* 0x250c: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2511:
	/* 0x2511: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2516:
	/* 0x2516: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_251d:
	/* 0x251d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2522:
	/* 0x2522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2524:
	/* 0x2524: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_252b:
	/* 0x252b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_252e:
	/* 0x252e: je     256e <tracepoint__sched__sched_process_exec+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256e;
	}
x86_l_2530:
	/* 0x2530: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2533:
	/* 0x2533: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2538:
	/* 0x2538: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_253b:
	/* 0x253b: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2543:
	/* 0x2543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2545:
	/* 0x2545: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2548:
	/* 0x2548: jne    2562 <tracepoint__sched__sched_process_exec+0x2562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2562;
	}
x86_l_254a:
	/* 0x254a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_254f:
	/* 0x254f: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2553:
	/* 0x2553: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2558:
	/* 0x2558: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_255b:
	/* 0x255b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255d:
	/* 0x255d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2560:
	/* 0x2560: je     256e <tracepoint__sched__sched_process_exec+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256e;
	}
x86_l_2562:
	/* 0x2562: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2565:
	/* 0x2565: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2569:
	/* 0x2569: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_256c:
	/* 0x256c: jmp    2570 <tracepoint__sched__sched_process_exec+0x2570> */
	goto x86_l_2570;
x86_l_256e:
	/* 0x256e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2570:
	/* 0x2570: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_2573:
	/* 0x2573: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2576:
	/* 0x2576: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2579:
	/* 0x2579: and    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_257c:
	/* 0x257c: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2581:
	/* 0x2581: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2588:
	/* 0x2588: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_258b:
	/* 0x258b: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2593:
	/* 0x2593: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2599:
	/* 0x2599: je     25a2 <tracepoint__sched__sched_process_exec+0x25a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25a2;
	}
x86_l_259b:
	/* 0x259b: and    rax,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_259f:
	/* 0x259f: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25a2:
	/* 0x25a2: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_25a9:
	/* 0x25a9: and    QWORD PTR [r14+0x80],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_25b0:
	/* 0x25b0: je     2b8e <tracepoint__sched__sched_process_exec+0x2b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11150ULL;
	}
x86_l_25b6:
	/* 0x25b6: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_25be:
	/* 0x25be: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25c2:
	/* 0x25c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25c7:
	/* 0x25c7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25cc:
	/* 0x25cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d1:
	/* 0x25d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d3:
	/* 0x25d3: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d8:
	/* 0x25d8: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_25dc:
	/* 0x25dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25e1:
	/* 0x25e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25e6:
	/* 0x25e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25eb:
	/* 0x25eb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25ee:
	/* 0x25ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f0:
	/* 0x25f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25f5:
	/* 0x25f5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25fa:
	/* 0x25fa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25fe:
	/* 0x25fe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2603:
	/* 0x2603: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2608:
	/* 0x2608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260a:
	/* 0x260a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_260f:
	/* 0x260f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2614:
	/* 0x2614: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2619:
	/* 0x2619: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_261e:
	/* 0x261e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2620:
	/* 0x2620: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2624:
	/* 0x2624: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2627:
	/* 0x2627: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_262c:
	/* 0x262c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2631:
	/* 0x2631: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2636:
	/* 0x2636: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2639:
	/* 0x2639: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263b:
	/* 0x263b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2640:
	/* 0x2640: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2645:
	/* 0x2645: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2649:
	/* 0x2649: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_264e:
	/* 0x264e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2653:
	/* 0x2653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2655:
	/* 0x2655: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_265a:
	/* 0x265a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_265f:
	/* 0x265f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2664:
	/* 0x2664: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2667:
	/* 0x2667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2669:
	/* 0x2669: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2672:
	/* 0x2672: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2677:
	/* 0x2677: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2680:
	/* 0x2680: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2685:
	/* 0x2685: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_268a:
	/* 0x268a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268f:
	/* 0x268f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2694:
	/* 0x2694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2696:
	/* 0x2696: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269b:
	/* 0x269b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26a0:
	/* 0x26a0: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_26a4:
	/* 0x26a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a9:
	/* 0x26a9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ae:
	/* 0x26ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b3:
	/* 0x26b3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26b6:
	/* 0x26b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b8:
	/* 0x26b8: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26bc:
	/* 0x26bc: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26c1:
	/* 0x26c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26c6:
	/* 0x26c6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26cb:
	/* 0x26cb: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d0:
	/* 0x26d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d5:
	/* 0x26d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d7:
	/* 0x26d7: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26dc:
	/* 0x26dc: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_26df:
	/* 0x26df: js     2705 <tracepoint__sched__sched_process_exec+0x2705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2705;
	}
x86_l_26e1:
	/* 0x26e1: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26e6:
	/* 0x26e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26eb:
	/* 0x26eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f0:
	/* 0x26f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f5:
	/* 0x26f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f7:
	/* 0x26f7: imul   rax,r15,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_R15, X86_WIDTH_64, 1000000000ULL);
x86_l_26fe:
	/* 0x26fe: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2703:
	/* 0x2703: jmp    2707 <tracepoint__sched__sched_process_exec+0x2707> */
	goto x86_l_2707;
x86_l_2705:
	/* 0x2705: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2707:
	/* 0x2707: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_270c:
	/* 0x270c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2711:
	/* 0x2711: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2716:
	/* 0x2716: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_271b:
	/* 0x271b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2720:
	/* 0x2720: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2723:
	/* 0x2723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2725:
	/* 0x2725: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_272a:
	/* 0x272a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_272f:
	/* 0x272f: lea    rdi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2737:
	/* 0x2737: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_273c:
	/* 0x273c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273e:
	/* 0x273e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2746:
	/* 0x2746: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_274c:
	/* 0x274c: ja     285b <tracepoint__sched__sched_process_exec+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_285b;
	}
x86_l_2752:
	/* 0x2752: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_275b:
	/* 0x275b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2763:
	/* 0x2763: mov    WORD PTR [r14+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_276b:
	/* 0x276b: cmp    ecx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27899ULL);
x86_l_2771:
	/* 0x2771: ja     27d8 <tracepoint__sched__sched_process_exec+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27d8;
	}
x86_l_2773:
	/* 0x2773: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2778:
	/* 0x2778: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2780:
	/* 0x2780: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2784:
	/* 0x2784: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_278b:
	/* 0x278b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2790:
	/* 0x2790: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2793:
	/* 0x2793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2795:
	/* 0x2795: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2797:
	/* 0x2797: jle    27d0 <tracepoint__sched__sched_process_exec+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27d0;
	}
x86_l_2799:
	/* 0x2799: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27a1:
	/* 0x27a1: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_27a8:
	/* 0x27a8: ja     27d8 <tracepoint__sched__sched_process_exec+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27d8;
	}
x86_l_27aa:
	/* 0x27aa: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_27b2:
	/* 0x27b2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_27ba:
	/* 0x27ba: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_27bd:
	/* 0x27bd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27c5:
	/* 0x27c5: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_27cc:
	/* 0x27cc: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_27ce:
	/* 0x27ce: jmp    27d8 <tracepoint__sched__sched_process_exec+0x27d8> */
	goto x86_l_27d8;
x86_l_27d0:
	/* 0x27d0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27d8:
	/* 0x27d8: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_27db:
	/* 0x27db: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_27e0:
	/* 0x27e0: ja     285b <tracepoint__sched__sched_process_exec+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_285b;
	}
x86_l_27e2:
	/* 0x27e2: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_27eb:
	/* 0x27eb: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27f3:
	/* 0x27f3: mov    WORD PTR [r14+0x7d8e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_27fb:
	/* 0x27fb: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_2800:
	/* 0x2800: ja     285b <tracepoint__sched__sched_process_exec+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_285b;
	}
x86_l_2802:
	/* 0x2802: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2807:
	/* 0x2807: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_280f:
	/* 0x280f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2813:
	/* 0x2813: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_281a:
	/* 0x281a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_281f:
	/* 0x281f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2822:
	/* 0x2822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2824:
	/* 0x2824: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2826:
	/* 0x2826: jle    285b <tracepoint__sched__sched_process_exec+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_285b;
	}
x86_l_2828:
	/* 0x2828: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2830:
	/* 0x2830: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_2837:
	/* 0x2837: ja     285b <tracepoint__sched__sched_process_exec+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_285b;
	}
x86_l_2839:
	/* 0x2839: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2841:
	/* 0x2841: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2849:
	/* 0x2849: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_284c:
	/* 0x284c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2854:
	/* 0x2854: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_285b:
	/* 0x285b: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2863:
	/* 0x2863: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
	return 10346ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10346ULL: goto x86_l_286a;
	case 10348ULL: goto x86_l_286c;
	case 10357ULL: goto x86_l_2875;
	case 10363ULL: goto x86_l_287b;
	case 10365ULL: goto x86_l_287d;
	case 10369ULL: goto x86_l_2881;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10394ULL: goto x86_l_289a;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10407ULL: goto x86_l_28a7;
	case 10414ULL: goto x86_l_28ae;
	case 10422ULL: goto x86_l_28b6;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10440ULL: goto x86_l_28c8;
	case 10446ULL: goto x86_l_28ce;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10476ULL: goto x86_l_28ec;
	case 10479ULL: goto x86_l_28ef;
	case 10481ULL: goto x86_l_28f1;
	case 10484ULL: goto x86_l_28f4;
	case 10492ULL: goto x86_l_28fc;
	case 10499ULL: goto x86_l_2903;
	case 10507ULL: goto x86_l_290b;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10525ULL: goto x86_l_291d;
	case 10531ULL: goto x86_l_2923;
	case 10533ULL: goto x86_l_2925;
	case 10537ULL: goto x86_l_2929;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10577ULL: goto x86_l_2951;
	case 10584ULL: goto x86_l_2958;
	case 10592ULL: goto x86_l_2960;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10618ULL: goto x86_l_297a;
	case 10622ULL: goto x86_l_297e;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10649ULL: goto x86_l_2999;
	case 10652ULL: goto x86_l_299c;
	case 10654ULL: goto x86_l_299e;
	case 10657ULL: goto x86_l_29a1;
	case 10665ULL: goto x86_l_29a9;
	case 10672ULL: goto x86_l_29b0;
	case 10679ULL: goto x86_l_29b7;
	case 10682ULL: goto x86_l_29ba;
	case 10688ULL: goto x86_l_29c0;
	case 10695ULL: goto x86_l_29c7;
	case 10697ULL: goto x86_l_29c9;
	case 10700ULL: goto x86_l_29cc;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10713ULL: goto x86_l_29d9;
	case 10721ULL: goto x86_l_29e1;
	case 10727ULL: goto x86_l_29e7;
	case 10733ULL: goto x86_l_29ed;
	case 10742ULL: goto x86_l_29f6;
	case 10750ULL: goto x86_l_29fe;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10765ULL: goto x86_l_2a0d;
	case 10772ULL: goto x86_l_2a14;
	case 10777ULL: goto x86_l_2a19;
	case 10785ULL: goto x86_l_2a21;
	case 10789ULL: goto x86_l_2a25;
	case 10796ULL: goto x86_l_2a2c;
	case 10801ULL: goto x86_l_2a31;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10815ULL: goto x86_l_2a3f;
	case 10822ULL: goto x86_l_2a46;
	case 10824ULL: goto x86_l_2a48;
	case 10832ULL: goto x86_l_2a50;
	case 10840ULL: goto x86_l_2a58;
	case 10843ULL: goto x86_l_2a5b;
	case 10851ULL: goto x86_l_2a63;
	case 10858ULL: goto x86_l_2a6a;
	case 10866ULL: goto x86_l_2a72;
	case 10873ULL: goto x86_l_2a79;
	case 10875ULL: goto x86_l_2a7b;
	case 10884ULL: goto x86_l_2a84;
	case 10891ULL: goto x86_l_2a8b;
	case 10893ULL: goto x86_l_2a8d;
	case 10897ULL: goto x86_l_2a91;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10919ULL: goto x86_l_2aa7;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10928ULL: goto x86_l_2ab0;
	case 10936ULL: goto x86_l_2ab8;
	case 10943ULL: goto x86_l_2abf;
	case 10951ULL: goto x86_l_2ac7;
	case 10958ULL: goto x86_l_2ace;
	case 10960ULL: goto x86_l_2ad0;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10977ULL: goto x86_l_2ae1;
	case 10984ULL: goto x86_l_2ae8;
	case 10988ULL: goto x86_l_2aec;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11007ULL: goto x86_l_2aff;
	case 11010ULL: goto x86_l_2b02;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11023ULL: goto x86_l_2b0f;
	case 11030ULL: goto x86_l_2b16;
	case 11038ULL: goto x86_l_2b1e;
	case 11045ULL: goto x86_l_2b25;
	case 11047ULL: goto x86_l_2b27;
	case 11056ULL: goto x86_l_2b30;
	case 11062ULL: goto x86_l_2b36;
	case 11064ULL: goto x86_l_2b38;
	case 11071ULL: goto x86_l_2b3f;
	case 11075ULL: goto x86_l_2b43;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11100ULL: goto x86_l_2b5c;
	case 11102ULL: goto x86_l_2b5e;
	case 11105ULL: goto x86_l_2b61;
	case 11113ULL: goto x86_l_2b69;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11132ULL: goto x86_l_2b7c;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11147ULL: goto x86_l_2b8b;
	case 11150ULL: goto x86_l_2b8e;
	case 11153ULL: goto x86_l_2b91;
	case 11160ULL: goto x86_l_2b98;
	case 11162ULL: goto x86_l_2b9a;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11171ULL: goto x86_l_2ba3;
	case 11177ULL: goto x86_l_2ba9;
	case 11181ULL: goto x86_l_2bad;
	case 11186ULL: goto x86_l_2bb2;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11226ULL: goto x86_l_2bda;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11257ULL: goto x86_l_2bf9;
	case 11261ULL: goto x86_l_2bfd;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11304ULL: goto x86_l_2c28;
	case 11308ULL: goto x86_l_2c2c;
	case 11314ULL: goto x86_l_2c32;
	case 11319ULL: goto x86_l_2c37;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11392ULL: goto x86_l_2c80;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11404ULL: goto x86_l_2c8c;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11425ULL: goto x86_l_2ca1;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11437ULL: goto x86_l_2cad;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11480ULL: goto x86_l_2cd8;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11495ULL: goto x86_l_2ce7;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11544ULL: goto x86_l_2d18;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11561ULL: goto x86_l_2d29;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11575ULL: goto x86_l_2d37;
	case 11580ULL: goto x86_l_2d3c;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11600ULL: goto x86_l_2d50;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11645ULL: goto x86_l_2d7d;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11670ULL: goto x86_l_2d96;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11686ULL: goto x86_l_2da6;
	case 11691ULL: goto x86_l_2dab;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11718ULL: goto x86_l_2dc6;
	case 11720ULL: goto x86_l_2dc8;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11749ULL: goto x86_l_2de5;
	case 11752ULL: goto x86_l_2de8;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11777ULL: goto x86_l_2e01;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11787ULL: goto x86_l_2e0b;
	case 11790ULL: goto x86_l_2e0e;
	case 11796ULL: goto x86_l_2e14;
	case 11800ULL: goto x86_l_2e18;
	case 11805ULL: goto x86_l_2e1d;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11820ULL: goto x86_l_2e2c;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11983ULL: goto x86_l_2ecf;
	case 11987ULL: goto x86_l_2ed3;
	case 11989ULL: goto x86_l_2ed5;
	case 11995ULL: goto x86_l_2edb;
	case 11998ULL: goto x86_l_2ede;
	case 12000ULL: goto x86_l_2ee0;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12029ULL: goto x86_l_2efd;
	case 12032ULL: goto x86_l_2f00;
	case 12038ULL: goto x86_l_2f06;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12057ULL: goto x86_l_2f19;
	case 12060ULL: goto x86_l_2f1c;
	case 12065ULL: goto x86_l_2f21;
	case 12067ULL: goto x86_l_2f23;
	case 12070ULL: goto x86_l_2f26;
	case 12076ULL: goto x86_l_2f2c;
	case 12080ULL: goto x86_l_2f30;
	default: return 0xffffffffffffffffULL;
	}
x86_l_286a:
	/* 0x286a: ja     28ae <tracepoint__sched__sched_process_exec+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_286c:
	/* 0x286c: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_2875:
	/* 0x2875: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_287b:
	/* 0x287b: ja     28ae <tracepoint__sched__sched_process_exec+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_287d:
	/* 0x287d: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2881:
	/* 0x2881: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2888:
	/* 0x2888: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_288d:
	/* 0x288d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2890:
	/* 0x2890: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2895:
	/* 0x2895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2897:
	/* 0x2897: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_289a:
	/* 0x289a: js     28ae <tracepoint__sched__sched_process_exec+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_289c:
	/* 0x289c: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_289f:
	/* 0x289f: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28a7:
	/* 0x28a7: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_28ae:
	/* 0x28ae: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28b6:
	/* 0x28b6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_28bd:
	/* 0x28bd: ja     2903 <tracepoint__sched__sched_process_exec+0x2903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2903;
	}
x86_l_28bf:
	/* 0x28bf: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_28c8:
	/* 0x28c8: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_28ce:
	/* 0x28ce: ja     2903 <tracepoint__sched__sched_process_exec+0x2903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2903;
	}
x86_l_28d0:
	/* 0x28d0: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_28d4:
	/* 0x28d4: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_28db:
	/* 0x28db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28e0:
	/* 0x28e0: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28e5:
	/* 0x28e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ea:
	/* 0x28ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ec:
	/* 0x28ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28ef:
	/* 0x28ef: js     2903 <tracepoint__sched__sched_process_exec+0x2903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2903;
	}
x86_l_28f1:
	/* 0x28f1: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_28f4:
	/* 0x28f4: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28fc:
	/* 0x28fc: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2903:
	/* 0x2903: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_290b:
	/* 0x290b: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2912:
	/* 0x2912: ja     2958 <tracepoint__sched__sched_process_exec+0x2958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2958;
	}
x86_l_2914:
	/* 0x2914: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_291d:
	/* 0x291d: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2923:
	/* 0x2923: ja     2958 <tracepoint__sched__sched_process_exec+0x2958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2958;
	}
x86_l_2925:
	/* 0x2925: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2929:
	/* 0x2929: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2930:
	/* 0x2930: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2935:
	/* 0x2935: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293a:
	/* 0x293a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_293f:
	/* 0x293f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2941:
	/* 0x2941: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2944:
	/* 0x2944: js     2958 <tracepoint__sched__sched_process_exec+0x2958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2958;
	}
x86_l_2946:
	/* 0x2946: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2949:
	/* 0x2949: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2951:
	/* 0x2951: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2958:
	/* 0x2958: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2960:
	/* 0x2960: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2967:
	/* 0x2967: ja     29b0 <tracepoint__sched__sched_process_exec+0x29b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b0;
	}
x86_l_2969:
	/* 0x2969: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_2972:
	/* 0x2972: cmp    ebx,0x7cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31997ULL);
x86_l_2978:
	/* 0x2978: ja     29b0 <tracepoint__sched__sched_process_exec+0x29b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b0;
	}
x86_l_297a:
	/* 0x297a: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_297e:
	/* 0x297e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2985:
	/* 0x2985: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_298a:
	/* 0x298a: lea    rdx,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2992:
	/* 0x2992: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2997:
	/* 0x2997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2999:
	/* 0x2999: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299c:
	/* 0x299c: js     29b0 <tracepoint__sched__sched_process_exec+0x29b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29b0;
	}
x86_l_299e:
	/* 0x299e: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_29a1:
	/* 0x29a1: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_29a9:
	/* 0x29a9: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_29b0:
	/* 0x29b0: mov    rax,QWORD PTR [rbp+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_29b7:
	/* 0x29b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29ba:
	/* 0x29ba: je     2b70 <tracepoint__sched__sched_process_exec+0x2b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b70;
	}
x86_l_29c0:
	/* 0x29c0: lea    rbx,[rbp+0x158] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_29c7:
	/* 0x29c7: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c9:
	/* 0x29c9: cmp    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_29cc:
	/* 0x29cc: jne    29d9 <tracepoint__sched__sched_process_exec+0x29d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29d9;
	}
x86_l_29ce:
	/* 0x29ce: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_29d3:
	/* 0x29d3: je     2b70 <tracepoint__sched__sched_process_exec+0x2b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b70;
	}
x86_l_29d9:
	/* 0x29d9: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29e1:
	/* 0x29e1: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_29e7:
	/* 0x29e7: ja     2a6a <tracepoint__sched__sched_process_exec+0x2a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a6a;
	}
x86_l_29ed:
	/* 0x29ed: mov    BYTE PTR [r14+rax*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519558ULL);
x86_l_29f6:
	/* 0x29f6: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29fe:
	/* 0x29fe: mov    WORD PTR [r14+0x7d98],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32152ULL);
x86_l_2a06:
	/* 0x2a06: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_2a0b:
	/* 0x2a0b: ja     2a6a <tracepoint__sched__sched_process_exec+0x2a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a6a;
	}
x86_l_2a0d:
	/* 0x2a0d: lea    rdx,[rbp+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2a14:
	/* 0x2a14: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a19:
	/* 0x2a19: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a21:
	/* 0x2a21: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2a25:
	/* 0x2a25: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_2a2c:
	/* 0x2a2c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a31:
	/* 0x2a31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a33:
	/* 0x2a33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a35:
	/* 0x2a35: jle    2a6a <tracepoint__sched__sched_process_exec+0x2a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2a6a;
	}
x86_l_2a37:
	/* 0x2a37: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a3f:
	/* 0x2a3f: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_2a46:
	/* 0x2a46: ja     2a6a <tracepoint__sched__sched_process_exec+0x2a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a6a;
	}
x86_l_2a48:
	/* 0x2a48: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2a50:
	/* 0x2a50: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a58:
	/* 0x2a58: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2a5b:
	/* 0x2a5b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a63:
	/* 0x2a63: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2a6a:
	/* 0x2a6a: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a72:
	/* 0x2a72: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_2a79:
	/* 0x2a79: ja     2abf <tracepoint__sched__sched_process_exec+0x2abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2abf;
	}
x86_l_2a7b:
	/* 0x2a7b: mov    BYTE PTR [r14+r15*1+0x89],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519559ULL);
x86_l_2a84:
	/* 0x2a84: cmp    r15d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31995ULL);
x86_l_2a8b:
	/* 0x2a8b: ja     2abf <tracepoint__sched__sched_process_exec+0x2abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2abf;
	}
x86_l_2a8d:
	/* 0x2a8d: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2a91:
	/* 0x2a91: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2a98:
	/* 0x2a98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aa2:
	/* 0x2aa2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2aa5:
	/* 0x2aa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa7:
	/* 0x2aa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aaa:
	/* 0x2aaa: js     2abf <tracepoint__sched__sched_process_exec+0x2abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2abf;
	}
x86_l_2aac:
	/* 0x2aac: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ab8:
	/* 0x2ab8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2abf:
	/* 0x2abf: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ac7:
	/* 0x2ac7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2ace:
	/* 0x2ace: ja     2b16 <tracepoint__sched__sched_process_exec+0x2b16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b16;
	}
x86_l_2ad0:
	/* 0x2ad0: mov    BYTE PTR [r14+rbx*1+0x89],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519560ULL);
x86_l_2ad9:
	/* 0x2ad9: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2adf:
	/* 0x2adf: ja     2b16 <tracepoint__sched__sched_process_exec+0x2b16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b16;
	}
x86_l_2ae1:
	/* 0x2ae1: lea    rdx,[rbp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_2ae8:
	/* 0x2ae8: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2aec:
	/* 0x2aec: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2af3:
	/* 0x2af3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af8:
	/* 0x2af8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afd:
	/* 0x2afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aff:
	/* 0x2aff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b02:
	/* 0x2b02: js     2b16 <tracepoint__sched__sched_process_exec+0x2b16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b16;
	}
x86_l_2b04:
	/* 0x2b04: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2b07:
	/* 0x2b07: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b0f:
	/* 0x2b0f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2b16:
	/* 0x2b16: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b1e:
	/* 0x2b1e: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2b25:
	/* 0x2b25: ja     2b70 <tracepoint__sched__sched_process_exec+0x2b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b70;
	}
x86_l_2b27:
	/* 0x2b27: mov    BYTE PTR [r14+rbx*1+0x89],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519561ULL);
x86_l_2b30:
	/* 0x2b30: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2b36:
	/* 0x2b36: ja     2b70 <tracepoint__sched__sched_process_exec+0x2b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b70;
	}
x86_l_2b38:
	/* 0x2b38: add    rbp,0x168 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 360ULL);
x86_l_2b3f:
	/* 0x2b3f: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b43:
	/* 0x2b43: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b54:
	/* 0x2b54: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2b57:
	/* 0x2b57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b59:
	/* 0x2b59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b5c:
	/* 0x2b5c: js     2b70 <tracepoint__sched__sched_process_exec+0x2b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b70;
	}
x86_l_2b5e:
	/* 0x2b5e: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2b61:
	/* 0x2b61: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b69:
	/* 0x2b69: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2b70:
	/* 0x2b70: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b75:
	/* 0x2b75: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array_tp)));
x86_l_2b7c:
	/* 0x2b7c: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2b84:
	/* 0x2b84: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2b89:
	/* 0x2b89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8b:
	/* 0x2b8b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b8e:
	/* 0x2b8e: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2b91:
	/* 0x2b91: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2b98:
	/* 0x2b98: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2b9a:
	/* 0x2b9a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2b9b:
	/* 0x2b9b: jmp    3a8f <tracepoint__sched__sched_process_exec+0x3a8f> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2ba0:
	/* 0x2ba0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ba3:
	/* 0x2ba3: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf6;
	}
x86_l_2ba9:
	/* 0x2ba9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bad:
	/* 0x2bad: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2bb2:
	/* 0x2bb2: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2bb8:
	/* 0x2bb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc1:
	/* 0x2bc1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bc5:
	/* 0x2bc5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bca:
	/* 0x2bca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bcf:
	/* 0x2bcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd1:
	/* 0x2bd1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bda:
	/* 0x2bda: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bdd:
	/* 0x2bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be2:
	/* 0x2be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be4:
	/* 0x2be4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2be9:
	/* 0x2be9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bed:
	/* 0x2bed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf7:
	/* 0x2bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf9:
	/* 0x2bf9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bfd:
	/* 0x2bfd: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c01:
	/* 0x2c01: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c06:
	/* 0x2c06: jmp    2c43 <tracepoint__sched__sched_process_exec+0x2c43> */
	goto x86_l_2c43;
x86_l_2c08:
	/* 0x2c08: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c0d:
	/* 0x2c0d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c13:
	/* 0x2c13: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c18:
	/* 0x2c18: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c1d:
	/* 0x2c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1f:
	/* 0x2c1f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c22:
	/* 0x2c22: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2cf6;
	}
x86_l_2c28:
	/* 0x2c28: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c2c:
	/* 0x2c2c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c32:
	/* 0x2c32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c37:
	/* 0x2c37: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c3b:
	/* 0x2c3b: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c3e:
	/* 0x2c3e: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c43:
	/* 0x2c43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c48:
	/* 0x2c48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c52:
	/* 0x2c52: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c57:
	/* 0x2c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c59:
	/* 0x2c59: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c63:
	/* 0x2c63: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c67:
	/* 0x2c67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c6c:
	/* 0x2c6c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c71:
	/* 0x2c71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c76:
	/* 0x2c76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c78:
	/* 0x2c78: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7d:
	/* 0x2c7d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c80:
	/* 0x2c80: je     2cf1 <tracepoint__sched__sched_process_exec+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf1;
	}
x86_l_2c82:
	/* 0x2c82: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c87:
	/* 0x2c87: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2c8a:
	/* 0x2c8a: je     2cf1 <tracepoint__sched__sched_process_exec+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf1;
	}
x86_l_2c8c:
	/* 0x2c8c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c90:
	/* 0x2c90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c95:
	/* 0x2c95: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c9f:
	/* 0x2c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca1:
	/* 0x2ca1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ca5:
	/* 0x2ca5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ca7:
	/* 0x2ca7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2cad:
	/* 0x2cad: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2cb0:
	/* 0x2cb0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cb2:
	/* 0x2cb2: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_2cb8:
	/* 0x2cb8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cbd:
	/* 0x2cbd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2cc3:
	/* 0x2cc3: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ccd:
	/* 0x2ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ccf:
	/* 0x2ccf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd2:
	/* 0x2cd2: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2cf6;
	}
x86_l_2cd4:
	/* 0x2cd4: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2cd8:
	/* 0x2cd8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2cde:
	/* 0x2cde: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce3:
	/* 0x2ce3: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ce7:
	/* 0x2ce7: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cea:
	/* 0x2cea: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cef:
	/* 0x2cef: jmp    2d59 <tracepoint__sched__sched_process_exec+0x2d59> */
	goto x86_l_2d59;
x86_l_2cf1:
	/* 0x2cf1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cf4:
	/* 0x2cf4: je     2d00 <tracepoint__sched__sched_process_exec+0x2d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d00;
	}
x86_l_2cf6:
	/* 0x2cf6: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cfb:
	/* 0x2cfb: jmp    f7a <tracepoint__sched__sched_process_exec+0xf7a> */
	return 3962ULL;
x86_l_2d00:
	/* 0x2d00: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d04:
	/* 0x2d04: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2d09:
	/* 0x2d09: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2d0b:
	/* 0x2d0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d10:
	/* 0x2d10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d14:
	/* 0x2d14: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d18:
	/* 0x2d18: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d22:
	/* 0x2d22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d24:
	/* 0x2d24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d29:
	/* 0x2d29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d30:
	/* 0x2d30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d35:
	/* 0x2d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d37:
	/* 0x2d37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d3c:
	/* 0x2d3c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d40:
	/* 0x2d40: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d45:
	/* 0x2d45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d4a:
	/* 0x2d4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4c:
	/* 0x2d4c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d50:
	/* 0x2d50: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d54:
	/* 0x2d54: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d59:
	/* 0x2d59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d5e:
	/* 0x2d5e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d63:
	/* 0x2d63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d68:
	/* 0x2d68: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d6d:
	/* 0x2d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6f:
	/* 0x2d6f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d74:
	/* 0x2d74: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d79:
	/* 0x2d79: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d7d:
	/* 0x2d7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d82:
	/* 0x2d82: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d87:
	/* 0x2d87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8c:
	/* 0x2d8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8e:
	/* 0x2d8e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d93:
	/* 0x2d93: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d96:
	/* 0x2d96: je     2e0b <tracepoint__sched__sched_process_exec+0x2e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e0b;
	}
x86_l_2d98:
	/* 0x2d98: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d9d:
	/* 0x2d9d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2da0:
	/* 0x2da0: je     2e0b <tracepoint__sched__sched_process_exec+0x2e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e0b;
	}
x86_l_2da2:
	/* 0x2da2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2da6:
	/* 0x2da6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dab:
	/* 0x2dab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2db0:
	/* 0x2db0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2db5:
	/* 0x2db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db7:
	/* 0x2db7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2dbb:
	/* 0x2dbb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dbd:
	/* 0x2dbd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2dc3:
	/* 0x2dc3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2dc6:
	/* 0x2dc6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dc8:
	/* 0x2dc8: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_2dce:
	/* 0x2dce: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dd3:
	/* 0x2dd3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2dd9:
	/* 0x2dd9: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2dde:
	/* 0x2dde: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2de3:
	/* 0x2de3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de5:
	/* 0x2de5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2de8:
	/* 0x2de8: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2cf6;
	}
x86_l_2dee:
	/* 0x2dee: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2df2:
	/* 0x2df2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2df8:
	/* 0x2df8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfd:
	/* 0x2dfd: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e01:
	/* 0x2e01: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e04:
	/* 0x2e04: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e09:
	/* 0x2e09: jmp    2e71 <tracepoint__sched__sched_process_exec+0x2e71> */
	goto x86_l_2e71;
x86_l_2e0b:
	/* 0x2e0b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e0e:
	/* 0x2e0e: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf6;
	}
x86_l_2e14:
	/* 0x2e14: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e18:
	/* 0x2e18: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2e1d:
	/* 0x2e1d: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf6;
	}
x86_l_2e23:
	/* 0x2e23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e28:
	/* 0x2e28: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2c:
	/* 0x2e2c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e30:
	/* 0x2e30: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e35:
	/* 0x2e35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e3a:
	/* 0x2e3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e3c:
	/* 0x2e3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e41:
	/* 0x2e41: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e45:
	/* 0x2e45: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e48:
	/* 0x2e48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e4d:
	/* 0x2e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4f:
	/* 0x2e4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e54:
	/* 0x2e54: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e58:
	/* 0x2e58: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e62:
	/* 0x2e62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e64:
	/* 0x2e64: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e68:
	/* 0x2e68: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e71:
	/* 0x2e71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e76:
	/* 0x2e76: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e7b:
	/* 0x2e7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e80:
	/* 0x2e80: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e85:
	/* 0x2e85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e87:
	/* 0x2e87: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e91:
	/* 0x2e91: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e95:
	/* 0x2e95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e9a:
	/* 0x2e9a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea4:
	/* 0x2ea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea6:
	/* 0x2ea6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eab:
	/* 0x2eab: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2eae:
	/* 0x2eae: je     2f23 <tracepoint__sched__sched_process_exec+0x2f23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f23;
	}
x86_l_2eb0:
	/* 0x2eb0: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eb5:
	/* 0x2eb5: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2eb8:
	/* 0x2eb8: je     2f23 <tracepoint__sched__sched_process_exec+0x2f23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f23;
	}
x86_l_2eba:
	/* 0x2eba: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ebe:
	/* 0x2ebe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ec3:
	/* 0x2ec3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ecd:
	/* 0x2ecd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ecf:
	/* 0x2ecf: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ed3:
	/* 0x2ed3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ed5:
	/* 0x2ed5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2edb:
	/* 0x2edb: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2ede:
	/* 0x2ede: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ee0:
	/* 0x2ee0: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_2ee6:
	/* 0x2ee6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2eeb:
	/* 0x2eeb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2ef1:
	/* 0x2ef1: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2efb:
	/* 0x2efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efd:
	/* 0x2efd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f00:
	/* 0x2f00: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2cf6;
	}
x86_l_2f06:
	/* 0x2f06: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f0a:
	/* 0x2f0a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f10:
	/* 0x2f10: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f15:
	/* 0x2f15: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f19:
	/* 0x2f19: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f1c:
	/* 0x2f1c: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f21:
	/* 0x2f21: jmp    2f89 <tracepoint__sched__sched_process_exec+0x2f89> */
	return 12169ULL;
x86_l_2f23:
	/* 0x2f23: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f26:
	/* 0x2f26: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf6;
	}
x86_l_2f2c:
	/* 0x2f2c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f30:
	/* 0x2f30: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
	return 12085ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12085ULL: goto x86_l_2f35;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12125ULL: goto x86_l_2f5d;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12156ULL: goto x86_l_2f7c;
	case 12160ULL: goto x86_l_2f80;
	case 12164ULL: goto x86_l_2f84;
	case 12169ULL: goto x86_l_2f89;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12230ULL: goto x86_l_2fc6;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12246ULL: goto x86_l_2fd6;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12263ULL: goto x86_l_2fe7;
	case 12267ULL: goto x86_l_2feb;
	case 12269ULL: goto x86_l_2fed;
	case 12275ULL: goto x86_l_2ff3;
	case 12278ULL: goto x86_l_2ff6;
	case 12280ULL: goto x86_l_2ff8;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12297ULL: goto x86_l_3009;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12309ULL: goto x86_l_3015;
	case 12312ULL: goto x86_l_3018;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12337ULL: goto x86_l_3031;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12347ULL: goto x86_l_303b;
	case 12350ULL: goto x86_l_303e;
	case 12356ULL: goto x86_l_3044;
	case 12360ULL: goto x86_l_3048;
	case 12365ULL: goto x86_l_304d;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12380ULL: goto x86_l_305c;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12405ULL: goto x86_l_3075;
	case 12408ULL: goto x86_l_3078;
	case 12413ULL: goto x86_l_307d;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12436ULL: goto x86_l_3094;
	case 12440ULL: goto x86_l_3098;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12485ULL: goto x86_l_30c5;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12502ULL: goto x86_l_30d6;
	case 12507ULL: goto x86_l_30db;
	case 12510ULL: goto x86_l_30de;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12520ULL: goto x86_l_30e8;
	case 12522ULL: goto x86_l_30ea;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12543ULL: goto x86_l_30ff;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12555ULL: goto x86_l_310b;
	case 12558ULL: goto x86_l_310e;
	case 12560ULL: goto x86_l_3110;
	case 12566ULL: goto x86_l_3116;
	case 12571ULL: goto x86_l_311b;
	case 12577ULL: goto x86_l_3121;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12589ULL: goto x86_l_312d;
	case 12592ULL: goto x86_l_3130;
	case 12598ULL: goto x86_l_3136;
	case 12602ULL: goto x86_l_313a;
	case 12608ULL: goto x86_l_3140;
	case 12613ULL: goto x86_l_3145;
	case 12617ULL: goto x86_l_3149;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12627ULL: goto x86_l_3153;
	case 12630ULL: goto x86_l_3156;
	case 12636ULL: goto x86_l_315c;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12664ULL: goto x86_l_3178;
	case 12669ULL: goto x86_l_317d;
	case 12674ULL: goto x86_l_3182;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12685ULL: goto x86_l_318d;
	case 12688ULL: goto x86_l_3190;
	case 12693ULL: goto x86_l_3195;
	case 12695ULL: goto x86_l_3197;
	case 12700ULL: goto x86_l_319c;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12716ULL: goto x86_l_31ac;
	case 12720ULL: goto x86_l_31b0;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12761ULL: goto x86_l_31d9;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12790ULL: goto x86_l_31f6;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12802ULL: goto x86_l_3202;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12816ULL: goto x86_l_3210;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12827ULL: goto x86_l_321b;
	case 12829ULL: goto x86_l_321d;
	case 12835ULL: goto x86_l_3223;
	case 12838ULL: goto x86_l_3226;
	case 12840ULL: goto x86_l_3228;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12857ULL: goto x86_l_3239;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12869ULL: goto x86_l_3245;
	case 12872ULL: goto x86_l_3248;
	case 12878ULL: goto x86_l_324e;
	case 12882ULL: goto x86_l_3252;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12897ULL: goto x86_l_3261;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12907ULL: goto x86_l_326b;
	case 12910ULL: goto x86_l_326e;
	case 12916ULL: goto x86_l_3274;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12940ULL: goto x86_l_328c;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12954ULL: goto x86_l_329a;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12965ULL: goto x86_l_32a5;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12994ULL: goto x86_l_32c2;
	case 12996ULL: goto x86_l_32c4;
	case 13000ULL: goto x86_l_32c8;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13029ULL: goto x86_l_32e5;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13070ULL: goto x86_l_330e;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13080ULL: goto x86_l_3318;
	case 13082ULL: goto x86_l_331a;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13101ULL: goto x86_l_332d;
	case 13103ULL: goto x86_l_332f;
	case 13107ULL: goto x86_l_3333;
	case 13109ULL: goto x86_l_3335;
	case 13115ULL: goto x86_l_333b;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13126ULL: goto x86_l_3346;
	case 13131ULL: goto x86_l_334b;
	case 13137ULL: goto x86_l_3351;
	case 13142ULL: goto x86_l_3356;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13152ULL: goto x86_l_3360;
	case 13158ULL: goto x86_l_3366;
	case 13162ULL: goto x86_l_336a;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13177ULL: goto x86_l_3379;
	case 13180ULL: goto x86_l_337c;
	case 13185ULL: goto x86_l_3381;
	case 13187ULL: goto x86_l_3383;
	case 13190ULL: goto x86_l_3386;
	case 13196ULL: goto x86_l_338c;
	case 13200ULL: goto x86_l_3390;
	case 13205ULL: goto x86_l_3395;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13220ULL: goto x86_l_33a4;
	case 13224ULL: goto x86_l_33a8;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13236ULL: goto x86_l_33b4;
	case 13241ULL: goto x86_l_33b9;
	case 13245ULL: goto x86_l_33bd;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13255ULL: goto x86_l_33c7;
	case 13260ULL: goto x86_l_33cc;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13276ULL: goto x86_l_33dc;
	case 13280ULL: goto x86_l_33e0;
	case 13284ULL: goto x86_l_33e4;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13311ULL: goto x86_l_33ff;
	case 13316ULL: goto x86_l_3404;
	case 13321ULL: goto x86_l_3409;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13350ULL: goto x86_l_3426;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13366ULL: goto x86_l_3436;
	case 13371ULL: goto x86_l_343b;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13383ULL: goto x86_l_3447;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13395ULL: goto x86_l_3453;
	case 13398ULL: goto x86_l_3456;
	case 13400ULL: goto x86_l_3458;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13429ULL: goto x86_l_3475;
	case 13432ULL: goto x86_l_3478;
	case 13438ULL: goto x86_l_347e;
	case 13442ULL: goto x86_l_3482;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13457ULL: goto x86_l_3491;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13467ULL: goto x86_l_349b;
	case 13470ULL: goto x86_l_349e;
	case 13476ULL: goto x86_l_34a4;
	case 13480ULL: goto x86_l_34a8;
	case 13485ULL: goto x86_l_34ad;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13525ULL: goto x86_l_34d5;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13554ULL: goto x86_l_34f2;
	case 13556ULL: goto x86_l_34f4;
	case 13560ULL: goto x86_l_34f8;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13589ULL: goto x86_l_3515;
	case 13591ULL: goto x86_l_3517;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13630ULL: goto x86_l_353e;
	case 13632ULL: goto x86_l_3540;
	case 13637ULL: goto x86_l_3545;
	case 13640ULL: goto x86_l_3548;
	case 13642ULL: goto x86_l_354a;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13667ULL: goto x86_l_3563;
	case 13669ULL: goto x86_l_3565;
	case 13675ULL: goto x86_l_356b;
	case 13678ULL: goto x86_l_356e;
	case 13680ULL: goto x86_l_3570;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f35:
	/* 0x2f35: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_2f3b:
	/* 0x2f3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f40:
	/* 0x2f40: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f44:
	/* 0x2f44: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f48:
	/* 0x2f48: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4d:
	/* 0x2f4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f52:
	/* 0x2f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f54:
	/* 0x2f54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f59:
	/* 0x2f59: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5d:
	/* 0x2f5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f60:
	/* 0x2f60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f65:
	/* 0x2f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f67:
	/* 0x2f67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f70:
	/* 0x2f70: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f75:
	/* 0x2f75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f7a:
	/* 0x2f7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7c:
	/* 0x2f7c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f80:
	/* 0x2f80: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f84:
	/* 0x2f84: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f89:
	/* 0x2f89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f8e:
	/* 0x2f8e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f93:
	/* 0x2f93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f98:
	/* 0x2f98: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f9d:
	/* 0x2f9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9f:
	/* 0x2f9f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fa9:
	/* 0x2fa9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fad:
	/* 0x2fad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fb2:
	/* 0x2fb2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fbc:
	/* 0x2fbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbe:
	/* 0x2fbe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc3:
	/* 0x2fc3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2fc6:
	/* 0x2fc6: je     303b <tracepoint__sched__sched_process_exec+0x303b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303b;
	}
x86_l_2fc8:
	/* 0x2fc8: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fcd:
	/* 0x2fcd: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2fd0:
	/* 0x2fd0: je     303b <tracepoint__sched__sched_process_exec+0x303b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303b;
	}
x86_l_2fd2:
	/* 0x2fd2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fd6:
	/* 0x2fd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fdb:
	/* 0x2fdb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fe0:
	/* 0x2fe0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2fe5:
	/* 0x2fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe7:
	/* 0x2fe7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2feb:
	/* 0x2feb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fed:
	/* 0x2fed: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ff3:
	/* 0x2ff3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_2ff6:
	/* 0x2ff6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ff8:
	/* 0x2ff8: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_2ffe:
	/* 0x2ffe: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3003:
	/* 0x3003: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3009:
	/* 0x3009: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_300e:
	/* 0x300e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3013:
	/* 0x3013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3015:
	/* 0x3015: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3018:
	/* 0x3018: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_301e:
	/* 0x301e: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3022:
	/* 0x3022: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3028:
	/* 0x3028: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302d:
	/* 0x302d: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3031:
	/* 0x3031: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3034:
	/* 0x3034: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3039:
	/* 0x3039: jmp    30a1 <tracepoint__sched__sched_process_exec+0x30a1> */
	goto x86_l_30a1;
x86_l_303b:
	/* 0x303b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_303e:
	/* 0x303e: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_3044:
	/* 0x3044: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3048:
	/* 0x3048: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_304d:
	/* 0x304d: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_3053:
	/* 0x3053: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3058:
	/* 0x3058: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_305c:
	/* 0x305c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3060:
	/* 0x3060: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3065:
	/* 0x3065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_306a:
	/* 0x306a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306c:
	/* 0x306c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3071:
	/* 0x3071: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3075:
	/* 0x3075: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3078:
	/* 0x3078: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_307d:
	/* 0x307d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_307f:
	/* 0x307f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3084:
	/* 0x3084: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3088:
	/* 0x3088: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_308d:
	/* 0x308d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3092:
	/* 0x3092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3094:
	/* 0x3094: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3098:
	/* 0x3098: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_309c:
	/* 0x309c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30a1:
	/* 0x30a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30a6:
	/* 0x30a6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30ab:
	/* 0x30ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b0:
	/* 0x30b0: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30b5:
	/* 0x30b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b7:
	/* 0x30b7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30bc:
	/* 0x30bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c1:
	/* 0x30c1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30c5:
	/* 0x30c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ca:
	/* 0x30ca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30cf:
	/* 0x30cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d4:
	/* 0x30d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d6:
	/* 0x30d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30db:
	/* 0x30db: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30de:
	/* 0x30de: je     3153 <tracepoint__sched__sched_process_exec+0x3153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3153;
	}
x86_l_30e0:
	/* 0x30e0: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30e5:
	/* 0x30e5: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_30e8:
	/* 0x30e8: je     3153 <tracepoint__sched__sched_process_exec+0x3153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3153;
	}
x86_l_30ea:
	/* 0x30ea: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30ee:
	/* 0x30ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30f3:
	/* 0x30f3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30f8:
	/* 0x30f8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30fd:
	/* 0x30fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ff:
	/* 0x30ff: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3103:
	/* 0x3103: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3105:
	/* 0x3105: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_310b:
	/* 0x310b: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_310e:
	/* 0x310e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3110:
	/* 0x3110: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_3116:
	/* 0x3116: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_311b:
	/* 0x311b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3121:
	/* 0x3121: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3126:
	/* 0x3126: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_312b:
	/* 0x312b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312d:
	/* 0x312d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3130:
	/* 0x3130: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_3136:
	/* 0x3136: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_313a:
	/* 0x313a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3140:
	/* 0x3140: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3145:
	/* 0x3145: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3149:
	/* 0x3149: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_314c:
	/* 0x314c: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3151:
	/* 0x3151: jmp    31b9 <tracepoint__sched__sched_process_exec+0x31b9> */
	goto x86_l_31b9;
x86_l_3153:
	/* 0x3153: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3156:
	/* 0x3156: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_315c:
	/* 0x315c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3160:
	/* 0x3160: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3165:
	/* 0x3165: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_316b:
	/* 0x316b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3170:
	/* 0x3170: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3174:
	/* 0x3174: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3178:
	/* 0x3178: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_317d:
	/* 0x317d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3182:
	/* 0x3182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3184:
	/* 0x3184: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3189:
	/* 0x3189: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318d:
	/* 0x318d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3190:
	/* 0x3190: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3195:
	/* 0x3195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3197:
	/* 0x3197: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_319c:
	/* 0x319c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31a0:
	/* 0x31a0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31a5:
	/* 0x31a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31aa:
	/* 0x31aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ac:
	/* 0x31ac: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b0:
	/* 0x31b0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31b4:
	/* 0x31b4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31b9:
	/* 0x31b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31be:
	/* 0x31be: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31c3:
	/* 0x31c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c8:
	/* 0x31c8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31cd:
	/* 0x31cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cf:
	/* 0x31cf: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31d4:
	/* 0x31d4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31d9:
	/* 0x31d9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31dd:
	/* 0x31dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31e2:
	/* 0x31e2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31e7:
	/* 0x31e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ec:
	/* 0x31ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ee:
	/* 0x31ee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f3:
	/* 0x31f3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31f6:
	/* 0x31f6: je     326b <tracepoint__sched__sched_process_exec+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326b;
	}
x86_l_31f8:
	/* 0x31f8: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31fd:
	/* 0x31fd: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3200:
	/* 0x3200: je     326b <tracepoint__sched__sched_process_exec+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326b;
	}
x86_l_3202:
	/* 0x3202: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3206:
	/* 0x3206: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_320b:
	/* 0x320b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3210:
	/* 0x3210: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3215:
	/* 0x3215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3217:
	/* 0x3217: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_321b:
	/* 0x321b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_321d:
	/* 0x321d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3223:
	/* 0x3223: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_3226:
	/* 0x3226: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3228:
	/* 0x3228: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_322e:
	/* 0x322e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3233:
	/* 0x3233: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3239:
	/* 0x3239: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_323e:
	/* 0x323e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3243:
	/* 0x3243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3245:
	/* 0x3245: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3248:
	/* 0x3248: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_324e:
	/* 0x324e: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3252:
	/* 0x3252: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3258:
	/* 0x3258: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325d:
	/* 0x325d: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3261:
	/* 0x3261: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3264:
	/* 0x3264: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3269:
	/* 0x3269: jmp    32d1 <tracepoint__sched__sched_process_exec+0x32d1> */
	goto x86_l_32d1;
x86_l_326b:
	/* 0x326b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_326e:
	/* 0x326e: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_3274:
	/* 0x3274: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3278:
	/* 0x3278: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_327d:
	/* 0x327d: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_3283:
	/* 0x3283: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3288:
	/* 0x3288: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328c:
	/* 0x328c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3290:
	/* 0x3290: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3295:
	/* 0x3295: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_329a:
	/* 0x329a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329c:
	/* 0x329c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32a1:
	/* 0x32a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a5:
	/* 0x32a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32a8:
	/* 0x32a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ad:
	/* 0x32ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32af:
	/* 0x32af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32b4:
	/* 0x32b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b8:
	/* 0x32b8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32bd:
	/* 0x32bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c2:
	/* 0x32c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c4:
	/* 0x32c4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c8:
	/* 0x32c8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32cc:
	/* 0x32cc: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32d1:
	/* 0x32d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d6:
	/* 0x32d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32db:
	/* 0x32db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e0:
	/* 0x32e0: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32e5:
	/* 0x32e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e7:
	/* 0x32e7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ec:
	/* 0x32ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f1:
	/* 0x32f1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32f5:
	/* 0x32f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32fa:
	/* 0x32fa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ff:
	/* 0x32ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3304:
	/* 0x3304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3306:
	/* 0x3306: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_330b:
	/* 0x330b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_330e:
	/* 0x330e: je     3383 <tracepoint__sched__sched_process_exec+0x3383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3383;
	}
x86_l_3310:
	/* 0x3310: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3315:
	/* 0x3315: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3318:
	/* 0x3318: je     3383 <tracepoint__sched__sched_process_exec+0x3383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3383;
	}
x86_l_331a:
	/* 0x331a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_331e:
	/* 0x331e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3323:
	/* 0x3323: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3328:
	/* 0x3328: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_332d:
	/* 0x332d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332f:
	/* 0x332f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3333:
	/* 0x3333: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3335:
	/* 0x3335: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_333b:
	/* 0x333b: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_333e:
	/* 0x333e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3340:
	/* 0x3340: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_3346:
	/* 0x3346: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_334b:
	/* 0x334b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3351:
	/* 0x3351: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3356:
	/* 0x3356: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_335b:
	/* 0x335b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335d:
	/* 0x335d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3360:
	/* 0x3360: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_3366:
	/* 0x3366: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_336a:
	/* 0x336a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3370:
	/* 0x3370: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3375:
	/* 0x3375: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3379:
	/* 0x3379: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_337c:
	/* 0x337c: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3381:
	/* 0x3381: jmp    33e9 <tracepoint__sched__sched_process_exec+0x33e9> */
	goto x86_l_33e9;
x86_l_3383:
	/* 0x3383: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3386:
	/* 0x3386: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_338c:
	/* 0x338c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3390:
	/* 0x3390: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3395:
	/* 0x3395: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_339b:
	/* 0x339b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33a0:
	/* 0x33a0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a4:
	/* 0x33a4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33a8:
	/* 0x33a8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33ad:
	/* 0x33ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b2:
	/* 0x33b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b4:
	/* 0x33b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33b9:
	/* 0x33b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33bd:
	/* 0x33bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33c0:
	/* 0x33c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c5:
	/* 0x33c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c7:
	/* 0x33c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33cc:
	/* 0x33cc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d0:
	/* 0x33d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33d5:
	/* 0x33d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33da:
	/* 0x33da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dc:
	/* 0x33dc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33e0:
	/* 0x33e0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33e4:
	/* 0x33e4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33e9:
	/* 0x33e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33ee:
	/* 0x33ee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33f3:
	/* 0x33f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f8:
	/* 0x33f8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33fd:
	/* 0x33fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ff:
	/* 0x33ff: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3404:
	/* 0x3404: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3409:
	/* 0x3409: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_340d:
	/* 0x340d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3412:
	/* 0x3412: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3417:
	/* 0x3417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_341c:
	/* 0x341c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341e:
	/* 0x341e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3423:
	/* 0x3423: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3426:
	/* 0x3426: je     349b <tracepoint__sched__sched_process_exec+0x349b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_349b;
	}
x86_l_3428:
	/* 0x3428: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_342d:
	/* 0x342d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3430:
	/* 0x3430: je     349b <tracepoint__sched__sched_process_exec+0x349b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_349b;
	}
x86_l_3432:
	/* 0x3432: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3436:
	/* 0x3436: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_343b:
	/* 0x343b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3440:
	/* 0x3440: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3445:
	/* 0x3445: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3447:
	/* 0x3447: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_344b:
	/* 0x344b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_344d:
	/* 0x344d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3453:
	/* 0x3453: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_3456:
	/* 0x3456: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3458:
	/* 0x3458: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_345e:
	/* 0x345e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3463:
	/* 0x3463: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3469:
	/* 0x3469: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_346e:
	/* 0x346e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3473:
	/* 0x3473: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3475:
	/* 0x3475: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3478:
	/* 0x3478: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_347e:
	/* 0x347e: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3482:
	/* 0x3482: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3488:
	/* 0x3488: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348d:
	/* 0x348d: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3491:
	/* 0x3491: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3494:
	/* 0x3494: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3499:
	/* 0x3499: jmp    3501 <tracepoint__sched__sched_process_exec+0x3501> */
	goto x86_l_3501;
x86_l_349b:
	/* 0x349b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_349e:
	/* 0x349e: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_34a4:
	/* 0x34a4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a8:
	/* 0x34a8: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_34ad:
	/* 0x34ad: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_34b3:
	/* 0x34b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34b8:
	/* 0x34b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34bc:
	/* 0x34bc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34c0:
	/* 0x34c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34c5:
	/* 0x34c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ca:
	/* 0x34ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34cc:
	/* 0x34cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34d1:
	/* 0x34d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d5:
	/* 0x34d5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34d8:
	/* 0x34d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34dd:
	/* 0x34dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34df:
	/* 0x34df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34e4:
	/* 0x34e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34e8:
	/* 0x34e8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ed:
	/* 0x34ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f2:
	/* 0x34f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f4:
	/* 0x34f4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34f8:
	/* 0x34f8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34fc:
	/* 0x34fc: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3501:
	/* 0x3501: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3506:
	/* 0x3506: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_350b:
	/* 0x350b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3510:
	/* 0x3510: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3515:
	/* 0x3515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3517:
	/* 0x3517: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_351c:
	/* 0x351c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3521:
	/* 0x3521: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3525:
	/* 0x3525: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_352a:
	/* 0x352a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_352f:
	/* 0x352f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3534:
	/* 0x3534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3536:
	/* 0x3536: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_353b:
	/* 0x353b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_353e:
	/* 0x353e: je     35b3 <tracepoint__sched__sched_process_exec+0x35b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13747ULL;
	}
x86_l_3540:
	/* 0x3540: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3545:
	/* 0x3545: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3548:
	/* 0x3548: je     35b3 <tracepoint__sched__sched_process_exec+0x35b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13747ULL;
	}
x86_l_354a:
	/* 0x354a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_354e:
	/* 0x354e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3553:
	/* 0x3553: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3558:
	/* 0x3558: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_355d:
	/* 0x355d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355f:
	/* 0x355f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3563:
	/* 0x3563: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3565:
	/* 0x3565: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_356b:
	/* 0x356b: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_356e:
	/* 0x356e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3570:
	/* 0x3570: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
	return 13686ULL;
}

static __noinline __u64 tracee_tracepoint__sched__sched_process_exec_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13686ULL: goto x86_l_3576;
	case 13691ULL: goto x86_l_357b;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13709ULL: goto x86_l_358d;
	case 13712ULL: goto x86_l_3590;
	case 13718ULL: goto x86_l_3596;
	case 13722ULL: goto x86_l_359a;
	case 13728ULL: goto x86_l_35a0;
	case 13733ULL: goto x86_l_35a5;
	case 13737ULL: goto x86_l_35a9;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13747ULL: goto x86_l_35b3;
	case 13750ULL: goto x86_l_35b6;
	case 13756ULL: goto x86_l_35bc;
	case 13760ULL: goto x86_l_35c0;
	case 13765ULL: goto x86_l_35c5;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13780ULL: goto x86_l_35d4;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13796ULL: goto x86_l_35e4;
	case 13801ULL: goto x86_l_35e9;
	case 13805ULL: goto x86_l_35ed;
	case 13808ULL: goto x86_l_35f0;
	case 13813ULL: goto x86_l_35f5;
	case 13815ULL: goto x86_l_35f7;
	case 13820ULL: goto x86_l_35fc;
	case 13824ULL: goto x86_l_3600;
	case 13829ULL: goto x86_l_3605;
	case 13834ULL: goto x86_l_360a;
	case 13836ULL: goto x86_l_360c;
	case 13840ULL: goto x86_l_3610;
	case 13844ULL: goto x86_l_3614;
	case 13849ULL: goto x86_l_3619;
	case 13854ULL: goto x86_l_361e;
	case 13859ULL: goto x86_l_3623;
	case 13864ULL: goto x86_l_3628;
	case 13869ULL: goto x86_l_362d;
	case 13871ULL: goto x86_l_362f;
	case 13876ULL: goto x86_l_3634;
	case 13881ULL: goto x86_l_3639;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13907ULL: goto x86_l_3653;
	case 13910ULL: goto x86_l_3656;
	case 13912ULL: goto x86_l_3658;
	case 13917ULL: goto x86_l_365d;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13926ULL: goto x86_l_3666;
	case 13931ULL: goto x86_l_366b;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13943ULL: goto x86_l_3677;
	case 13947ULL: goto x86_l_367b;
	case 13949ULL: goto x86_l_367d;
	case 13955ULL: goto x86_l_3683;
	case 13958ULL: goto x86_l_3686;
	case 13960ULL: goto x86_l_3688;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13977ULL: goto x86_l_3699;
	case 13982ULL: goto x86_l_369e;
	case 13987ULL: goto x86_l_36a3;
	case 13989ULL: goto x86_l_36a5;
	case 13992ULL: goto x86_l_36a8;
	case 13998ULL: goto x86_l_36ae;
	case 14002ULL: goto x86_l_36b2;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14017ULL: goto x86_l_36c1;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14030ULL: goto x86_l_36ce;
	case 14036ULL: goto x86_l_36d4;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14051ULL: goto x86_l_36e3;
	case 14056ULL: goto x86_l_36e8;
	case 14060ULL: goto x86_l_36ec;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14074ULL: goto x86_l_36fa;
	case 14076ULL: goto x86_l_36fc;
	case 14081ULL: goto x86_l_3701;
	case 14085ULL: goto x86_l_3705;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14095ULL: goto x86_l_370f;
	case 14100ULL: goto x86_l_3714;
	case 14104ULL: goto x86_l_3718;
	case 14109ULL: goto x86_l_371d;
	case 14114ULL: goto x86_l_3722;
	case 14116ULL: goto x86_l_3724;
	case 14120ULL: goto x86_l_3728;
	case 14124ULL: goto x86_l_372c;
	case 14129ULL: goto x86_l_3731;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14151ULL: goto x86_l_3747;
	case 14156ULL: goto x86_l_374c;
	case 14161ULL: goto x86_l_3751;
	case 14165ULL: goto x86_l_3755;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14180ULL: goto x86_l_3764;
	case 14182ULL: goto x86_l_3766;
	case 14187ULL: goto x86_l_376b;
	case 14190ULL: goto x86_l_376e;
	case 14192ULL: goto x86_l_3770;
	case 14197ULL: goto x86_l_3775;
	case 14200ULL: goto x86_l_3778;
	case 14202ULL: goto x86_l_377a;
	case 14206ULL: goto x86_l_377e;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14223ULL: goto x86_l_378f;
	case 14227ULL: goto x86_l_3793;
	case 14229ULL: goto x86_l_3795;
	case 14235ULL: goto x86_l_379b;
	case 14238ULL: goto x86_l_379e;
	case 14240ULL: goto x86_l_37a0;
	case 14246ULL: goto x86_l_37a6;
	case 14251ULL: goto x86_l_37ab;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14269ULL: goto x86_l_37bd;
	case 14272ULL: goto x86_l_37c0;
	case 14278ULL: goto x86_l_37c6;
	case 14282ULL: goto x86_l_37ca;
	case 14288ULL: goto x86_l_37d0;
	case 14293ULL: goto x86_l_37d5;
	case 14297ULL: goto x86_l_37d9;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14307ULL: goto x86_l_37e3;
	case 14310ULL: goto x86_l_37e6;
	case 14316ULL: goto x86_l_37ec;
	case 14320ULL: goto x86_l_37f0;
	case 14325ULL: goto x86_l_37f5;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14340ULL: goto x86_l_3804;
	case 14344ULL: goto x86_l_3808;
	case 14349ULL: goto x86_l_380d;
	case 14354ULL: goto x86_l_3812;
	case 14356ULL: goto x86_l_3814;
	case 14361ULL: goto x86_l_3819;
	case 14365ULL: goto x86_l_381d;
	case 14368ULL: goto x86_l_3820;
	case 14373ULL: goto x86_l_3825;
	case 14375ULL: goto x86_l_3827;
	case 14380ULL: goto x86_l_382c;
	case 14384ULL: goto x86_l_3830;
	case 14389ULL: goto x86_l_3835;
	case 14394ULL: goto x86_l_383a;
	case 14396ULL: goto x86_l_383c;
	case 14400ULL: goto x86_l_3840;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14419ULL: goto x86_l_3853;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14431ULL: goto x86_l_385f;
	case 14436ULL: goto x86_l_3864;
	case 14441ULL: goto x86_l_3869;
	case 14445ULL: goto x86_l_386d;
	case 14450ULL: goto x86_l_3872;
	case 14455ULL: goto x86_l_3877;
	case 14460ULL: goto x86_l_387c;
	case 14462ULL: goto x86_l_387e;
	case 14467ULL: goto x86_l_3883;
	case 14470ULL: goto x86_l_3886;
	case 14472ULL: goto x86_l_3888;
	case 14477ULL: goto x86_l_388d;
	case 14480ULL: goto x86_l_3890;
	case 14482ULL: goto x86_l_3892;
	case 14486ULL: goto x86_l_3896;
	case 14491ULL: goto x86_l_389b;
	case 14496ULL: goto x86_l_38a0;
	case 14501ULL: goto x86_l_38a5;
	case 14503ULL: goto x86_l_38a7;
	case 14507ULL: goto x86_l_38ab;
	case 14509ULL: goto x86_l_38ad;
	case 14515ULL: goto x86_l_38b3;
	case 14518ULL: goto x86_l_38b6;
	case 14520ULL: goto x86_l_38b8;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14537ULL: goto x86_l_38c9;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14549ULL: goto x86_l_38d5;
	case 14552ULL: goto x86_l_38d8;
	case 14558ULL: goto x86_l_38de;
	case 14562ULL: goto x86_l_38e2;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14577ULL: goto x86_l_38f1;
	case 14580ULL: goto x86_l_38f4;
	case 14585ULL: goto x86_l_38f9;
	case 14587ULL: goto x86_l_38fb;
	case 14590ULL: goto x86_l_38fe;
	case 14596ULL: goto x86_l_3904;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14611ULL: goto x86_l_3913;
	case 14616ULL: goto x86_l_3918;
	case 14620ULL: goto x86_l_391c;
	case 14624ULL: goto x86_l_3920;
	case 14629ULL: goto x86_l_3925;
	case 14634ULL: goto x86_l_392a;
	case 14636ULL: goto x86_l_392c;
	case 14641ULL: goto x86_l_3931;
	case 14645ULL: goto x86_l_3935;
	case 14648ULL: goto x86_l_3938;
	case 14653ULL: goto x86_l_393d;
	case 14655ULL: goto x86_l_393f;
	case 14660ULL: goto x86_l_3944;
	case 14664ULL: goto x86_l_3948;
	case 14669ULL: goto x86_l_394d;
	case 14674ULL: goto x86_l_3952;
	case 14676ULL: goto x86_l_3954;
	case 14680ULL: goto x86_l_3958;
	case 14684ULL: goto x86_l_395c;
	case 14689ULL: goto x86_l_3961;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14704ULL: goto x86_l_3970;
	case 14709ULL: goto x86_l_3975;
	case 14711ULL: goto x86_l_3977;
	case 14716ULL: goto x86_l_397c;
	case 14721ULL: goto x86_l_3981;
	case 14725ULL: goto x86_l_3985;
	case 14730ULL: goto x86_l_398a;
	case 14735ULL: goto x86_l_398f;
	case 14740ULL: goto x86_l_3994;
	case 14742ULL: goto x86_l_3996;
	case 14747ULL: goto x86_l_399b;
	case 14750ULL: goto x86_l_399e;
	case 14756ULL: goto x86_l_39a4;
	case 14761ULL: goto x86_l_39a9;
	case 14764ULL: goto x86_l_39ac;
	case 14770ULL: goto x86_l_39b2;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14789ULL: goto x86_l_39c5;
	case 14791ULL: goto x86_l_39c7;
	case 14795ULL: goto x86_l_39cb;
	case 14797ULL: goto x86_l_39cd;
	case 14803ULL: goto x86_l_39d3;
	case 14806ULL: goto x86_l_39d6;
	case 14808ULL: goto x86_l_39d8;
	case 14814ULL: goto x86_l_39de;
	case 14819ULL: goto x86_l_39e3;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14837ULL: goto x86_l_39f5;
	case 14840ULL: goto x86_l_39f8;
	case 14846ULL: goto x86_l_39fe;
	case 14850ULL: goto x86_l_3a02;
	case 14856ULL: goto x86_l_3a08;
	case 14861ULL: goto x86_l_3a0d;
	case 14866ULL: goto x86_l_3a12;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14879ULL: goto x86_l_3a1f;
	case 14886ULL: goto x86_l_3a26;
	case 14892ULL: goto x86_l_3a2c;
	case 14897ULL: goto x86_l_3a31;
	case 14900ULL: goto x86_l_3a34;
	case 14906ULL: goto x86_l_3a3a;
	case 14910ULL: goto x86_l_3a3e;
	case 14915ULL: goto x86_l_3a43;
	case 14921ULL: goto x86_l_3a49;
	case 14926ULL: goto x86_l_3a4e;
	case 14930ULL: goto x86_l_3a52;
	case 14934ULL: goto x86_l_3a56;
	case 14939ULL: goto x86_l_3a5b;
	case 14944ULL: goto x86_l_3a60;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14955ULL: goto x86_l_3a6b;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14965ULL: goto x86_l_3a75;
	case 14970ULL: goto x86_l_3a7a;
	case 14974ULL: goto x86_l_3a7e;
	case 14979ULL: goto x86_l_3a83;
	case 14984ULL: goto x86_l_3a88;
	case 14986ULL: goto x86_l_3a8a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3576:
	/* 0x3576: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_357b:
	/* 0x357b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3581:
	/* 0x3581: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3586:
	/* 0x3586: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_358b:
	/* 0x358b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358d:
	/* 0x358d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3590:
	/* 0x3590: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_3596:
	/* 0x3596: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_359a:
	/* 0x359a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_35a0:
	/* 0x35a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35a5:
	/* 0x35a5: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_35a9:
	/* 0x35a9: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35ac:
	/* 0x35ac: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b1:
	/* 0x35b1: jmp    3619 <tracepoint__sched__sched_process_exec+0x3619> */
	goto x86_l_3619;
x86_l_35b3:
	/* 0x35b3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35b6:
	/* 0x35b6: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_35bc:
	/* 0x35bc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c0:
	/* 0x35c0: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_35c5:
	/* 0x35c5: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_35cb:
	/* 0x35cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35d0:
	/* 0x35d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d4:
	/* 0x35d4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35d8:
	/* 0x35d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35dd:
	/* 0x35dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35e2:
	/* 0x35e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e4:
	/* 0x35e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35e9:
	/* 0x35e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ed:
	/* 0x35ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35f0:
	/* 0x35f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35f5:
	/* 0x35f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f7:
	/* 0x35f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35fc:
	/* 0x35fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3600:
	/* 0x3600: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3605:
	/* 0x3605: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_360a:
	/* 0x360a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360c:
	/* 0x360c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3610:
	/* 0x3610: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3614:
	/* 0x3614: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3619:
	/* 0x3619: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_361e:
	/* 0x361e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3623:
	/* 0x3623: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3628:
	/* 0x3628: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_362d:
	/* 0x362d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362f:
	/* 0x362f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3634:
	/* 0x3634: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3639:
	/* 0x3639: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_363d:
	/* 0x363d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3642:
	/* 0x3642: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3647:
	/* 0x3647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_364c:
	/* 0x364c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364e:
	/* 0x364e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3653:
	/* 0x3653: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3656:
	/* 0x3656: je     36cb <tracepoint__sched__sched_process_exec+0x36cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36cb;
	}
x86_l_3658:
	/* 0x3658: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_365d:
	/* 0x365d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3660:
	/* 0x3660: je     36cb <tracepoint__sched__sched_process_exec+0x36cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36cb;
	}
x86_l_3662:
	/* 0x3662: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3666:
	/* 0x3666: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_366b:
	/* 0x366b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3670:
	/* 0x3670: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3675:
	/* 0x3675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3677:
	/* 0x3677: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_367b:
	/* 0x367b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_367d:
	/* 0x367d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3683:
	/* 0x3683: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_3686:
	/* 0x3686: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3688:
	/* 0x3688: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_368e:
	/* 0x368e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3693:
	/* 0x3693: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3699:
	/* 0x3699: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_369e:
	/* 0x369e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_36a3:
	/* 0x36a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a5:
	/* 0x36a5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_36a8:
	/* 0x36a8: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_36ae:
	/* 0x36ae: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_36b2:
	/* 0x36b2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_36b8:
	/* 0x36b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36bd:
	/* 0x36bd: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_36c1:
	/* 0x36c1: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36c4:
	/* 0x36c4: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36c9:
	/* 0x36c9: jmp    3731 <tracepoint__sched__sched_process_exec+0x3731> */
	goto x86_l_3731;
x86_l_36cb:
	/* 0x36cb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_36ce:
	/* 0x36ce: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_36d4:
	/* 0x36d4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d8:
	/* 0x36d8: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_36dd:
	/* 0x36dd: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_36e3:
	/* 0x36e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36e8:
	/* 0x36e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36ec:
	/* 0x36ec: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_36f0:
	/* 0x36f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36f5:
	/* 0x36f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36fa:
	/* 0x36fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36fc:
	/* 0x36fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3701:
	/* 0x3701: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3705:
	/* 0x3705: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3708:
	/* 0x3708: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_370d:
	/* 0x370d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370f:
	/* 0x370f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3714:
	/* 0x3714: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3718:
	/* 0x3718: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_371d:
	/* 0x371d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3722:
	/* 0x3722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3724:
	/* 0x3724: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3728:
	/* 0x3728: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_372c:
	/* 0x372c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3731:
	/* 0x3731: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3736:
	/* 0x3736: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_373b:
	/* 0x373b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3740:
	/* 0x3740: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3745:
	/* 0x3745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3747:
	/* 0x3747: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_374c:
	/* 0x374c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3751:
	/* 0x3751: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3755:
	/* 0x3755: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_375a:
	/* 0x375a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_375f:
	/* 0x375f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3764:
	/* 0x3764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3766:
	/* 0x3766: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_376b:
	/* 0x376b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_376e:
	/* 0x376e: je     37e3 <tracepoint__sched__sched_process_exec+0x37e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e3;
	}
x86_l_3770:
	/* 0x3770: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3775:
	/* 0x3775: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3778:
	/* 0x3778: je     37e3 <tracepoint__sched__sched_process_exec+0x37e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e3;
	}
x86_l_377a:
	/* 0x377a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_377e:
	/* 0x377e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3783:
	/* 0x3783: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3788:
	/* 0x3788: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_378d:
	/* 0x378d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378f:
	/* 0x378f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3793:
	/* 0x3793: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3795:
	/* 0x3795: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_379b:
	/* 0x379b: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_379e:
	/* 0x379e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_37a0:
	/* 0x37a0: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_37a6:
	/* 0x37a6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_37ab:
	/* 0x37ab: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_37b1:
	/* 0x37b1: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_37b6:
	/* 0x37b6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_37bb:
	/* 0x37bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37bd:
	/* 0x37bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37c0:
	/* 0x37c0: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_37c6:
	/* 0x37c6: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_37ca:
	/* 0x37ca: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_37d0:
	/* 0x37d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37d5:
	/* 0x37d5: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_37d9:
	/* 0x37d9: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_37dc:
	/* 0x37dc: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37e1:
	/* 0x37e1: jmp    3849 <tracepoint__sched__sched_process_exec+0x3849> */
	goto x86_l_3849;
x86_l_37e3:
	/* 0x37e3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_37e6:
	/* 0x37e6: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_37ec:
	/* 0x37ec: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37f0:
	/* 0x37f0: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_37f5:
	/* 0x37f5: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_37fb:
	/* 0x37fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3800:
	/* 0x3800: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3804:
	/* 0x3804: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3808:
	/* 0x3808: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_380d:
	/* 0x380d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3812:
	/* 0x3812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3814:
	/* 0x3814: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3819:
	/* 0x3819: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381d:
	/* 0x381d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3820:
	/* 0x3820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3825:
	/* 0x3825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3827:
	/* 0x3827: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_382c:
	/* 0x382c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3830:
	/* 0x3830: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3835:
	/* 0x3835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_383a:
	/* 0x383a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383c:
	/* 0x383c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3840:
	/* 0x3840: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3844:
	/* 0x3844: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3849:
	/* 0x3849: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_384e:
	/* 0x384e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3853:
	/* 0x3853: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3858:
	/* 0x3858: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_385d:
	/* 0x385d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_385f:
	/* 0x385f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3864:
	/* 0x3864: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3869:
	/* 0x3869: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_386d:
	/* 0x386d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3872:
	/* 0x3872: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3877:
	/* 0x3877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_387c:
	/* 0x387c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387e:
	/* 0x387e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3883:
	/* 0x3883: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3886:
	/* 0x3886: je     38fb <tracepoint__sched__sched_process_exec+0x38fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38fb;
	}
x86_l_3888:
	/* 0x3888: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_388d:
	/* 0x388d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3890:
	/* 0x3890: je     38fb <tracepoint__sched__sched_process_exec+0x38fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38fb;
	}
x86_l_3892:
	/* 0x3892: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3896:
	/* 0x3896: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_389b:
	/* 0x389b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38a0:
	/* 0x38a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_38a5:
	/* 0x38a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a7:
	/* 0x38a7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_38ab:
	/* 0x38ab: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_38ad:
	/* 0x38ad: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_38b3:
	/* 0x38b3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_38b6:
	/* 0x38b6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38b8:
	/* 0x38b8: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_38be:
	/* 0x38be: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_38c3:
	/* 0x38c3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_38c9:
	/* 0x38c9: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38ce:
	/* 0x38ce: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_38d3:
	/* 0x38d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d5:
	/* 0x38d5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38d8:
	/* 0x38d8: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_38de:
	/* 0x38de: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_38e2:
	/* 0x38e2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_38e8:
	/* 0x38e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ed:
	/* 0x38ed: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_38f1:
	/* 0x38f1: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38f4:
	/* 0x38f4: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38f9:
	/* 0x38f9: jmp    3961 <tracepoint__sched__sched_process_exec+0x3961> */
	goto x86_l_3961;
x86_l_38fb:
	/* 0x38fb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_38fe:
	/* 0x38fe: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_3904:
	/* 0x3904: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3908:
	/* 0x3908: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_390d:
	/* 0x390d: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_3913:
	/* 0x3913: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3918:
	/* 0x3918: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_391c:
	/* 0x391c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3920:
	/* 0x3920: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3925:
	/* 0x3925: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392a:
	/* 0x392a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392c:
	/* 0x392c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3931:
	/* 0x3931: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3935:
	/* 0x3935: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3938:
	/* 0x3938: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_393d:
	/* 0x393d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393f:
	/* 0x393f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3944:
	/* 0x3944: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3948:
	/* 0x3948: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_394d:
	/* 0x394d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3952:
	/* 0x3952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3954:
	/* 0x3954: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3958:
	/* 0x3958: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_395c:
	/* 0x395c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3961:
	/* 0x3961: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3966:
	/* 0x3966: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_396b:
	/* 0x396b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3970:
	/* 0x3970: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3975:
	/* 0x3975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3977:
	/* 0x3977: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_397c:
	/* 0x397c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3981:
	/* 0x3981: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3985:
	/* 0x3985: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_398a:
	/* 0x398a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_398f:
	/* 0x398f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3994:
	/* 0x3994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3996:
	/* 0x3996: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_399b:
	/* 0x399b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_399e:
	/* 0x399e: je     3a31 <tracepoint__sched__sched_process_exec+0x3a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a31;
	}
x86_l_39a4:
	/* 0x39a4: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39a9:
	/* 0x39a9: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_39ac:
	/* 0x39ac: je     3a31 <tracepoint__sched__sched_process_exec+0x3a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a31;
	}
x86_l_39b2:
	/* 0x39b2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_39b6:
	/* 0x39b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39bb:
	/* 0x39bb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39c0:
	/* 0x39c0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39c5:
	/* 0x39c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c7:
	/* 0x39c7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_39cb:
	/* 0x39cb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_39cd:
	/* 0x39cd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_39d3:
	/* 0x39d3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_39d6:
	/* 0x39d6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39d8:
	/* 0x39d8: jb     155c <tracepoint__sched__sched_process_exec+0x155c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5468ULL;
	}
x86_l_39de:
	/* 0x39de: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_39e3:
	/* 0x39e3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_39e9:
	/* 0x39e9: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39ee:
	/* 0x39ee: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_39f3:
	/* 0x39f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f5:
	/* 0x39f5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_39f8:
	/* 0x39f8: jl     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11510ULL;
	}
x86_l_39fe:
	/* 0x39fe: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3a02:
	/* 0x3a02: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3a08:
	/* 0x3a08: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0d:
	/* 0x3a0d: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3a12:
	/* 0x3a12: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a15:
	/* 0x3a15: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a1a:
	/* 0x3a1a: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a1f:
	/* 0x3a1f: cmp    r13d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16384ULL);
x86_l_3a26:
	/* 0x3a26: je     1578 <tracepoint__sched__sched_process_exec+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5496ULL;
	}
x86_l_3a2c:
	/* 0x3a2c: jmp    f8c <tracepoint__sched__sched_process_exec+0xf8c> */
	return 3980ULL;
x86_l_3a31:
	/* 0x3a31: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3a34:
	/* 0x3a34: jne    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11510ULL;
	}
x86_l_3a3a:
	/* 0x3a3a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3e:
	/* 0x3a3e: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3a43:
	/* 0x3a43: je     2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11510ULL;
	}
x86_l_3a49:
	/* 0x3a49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a4e:
	/* 0x3a4e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a52:
	/* 0x3a52: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a56:
	/* 0x3a56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a5b:
	/* 0x3a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a60:
	/* 0x3a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a62:
	/* 0x3a62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a67:
	/* 0x3a67: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a6b:
	/* 0x3a6b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a6e:
	/* 0x3a6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a73:
	/* 0x3a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a75:
	/* 0x3a75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a7a:
	/* 0x3a7a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a7e:
	/* 0x3a7e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a83:
	/* 0x3a83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a88:
	/* 0x3a88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a8a:
	/* 0x3a8a: jmp    2cf6 <tracepoint__sched__sched_process_exec+0x2cf6> */
	return 11510ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_tracepoint__sched__sched_process_exec_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13516U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2134ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2137ULL && __x86_pc <= 3869ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3873ULL && __x86_pc <= 5478ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5483ULL && __x86_pc <= 7107ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7112ULL && __x86_pc <= 8672ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8675ULL && __x86_pc <= 10339ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10346ULL && __x86_pc <= 12080ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12085ULL && __x86_pc <= 13680ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13686ULL && __x86_pc <= 14986ULL)
			__x86_pc = tracee_tracepoint__sched__sched_process_exec_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char binary_filter_version;
extern char bufs;
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

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_0(
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
	case 47ULL: goto x86_l_2f;
	case 52ULL: goto x86_l_34;
	case 54ULL: goto x86_l_36;
	case 62ULL: goto x86_l_3e;
	case 67ULL: goto x86_l_43;
	case 69ULL: goto x86_l_45;
	case 74ULL: goto x86_l_4a;
	case 76ULL: goto x86_l_4c;
	case 81ULL: goto x86_l_51;
	case 84ULL: goto x86_l_54;
	case 86ULL: goto x86_l_56;
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 107ULL: goto x86_l_6b;
	case 111ULL: goto x86_l_6f;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 140ULL: goto x86_l_8c;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 153ULL: goto x86_l_99;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 232ULL: goto x86_l_e8;
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
	case 559ULL: goto x86_l_22f;
	case 562ULL: goto x86_l_232;
	case 564ULL: goto x86_l_234;
	case 568ULL: goto x86_l_238;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 587ULL: goto x86_l_24b;
	case 595ULL: goto x86_l_253;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 626ULL: goto x86_l_272;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 671ULL: goto x86_l_29f;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 688ULL: goto x86_l_2b0;
	case 699ULL: goto x86_l_2bb;
	case 710ULL: goto x86_l_2c6;
	case 721ULL: goto x86_l_2d1;
	case 732ULL: goto x86_l_2dc;
	case 743ULL: goto x86_l_2e7;
	case 754ULL: goto x86_l_2f2;
	case 765ULL: goto x86_l_2fd;
	case 776ULL: goto x86_l_308;
	case 787ULL: goto x86_l_313;
	case 798ULL: goto x86_l_31e;
	case 809ULL: goto x86_l_329;
	case 820ULL: goto x86_l_334;
	case 831ULL: goto x86_l_33f;
	case 842ULL: goto x86_l_34a;
	case 853ULL: goto x86_l_355;
	case 864ULL: goto x86_l_360;
	case 875ULL: goto x86_l_36b;
	case 886ULL: goto x86_l_376;
	case 897ULL: goto x86_l_381;
	case 908ULL: goto x86_l_38c;
	case 919ULL: goto x86_l_397;
	case 930ULL: goto x86_l_3a2;
	case 941ULL: goto x86_l_3ad;
	case 952ULL: goto x86_l_3b8;
	case 963ULL: goto x86_l_3c3;
	case 974ULL: goto x86_l_3ce;
	case 985ULL: goto x86_l_3d9;
	case 996ULL: goto x86_l_3e4;
	case 1007ULL: goto x86_l_3ef;
	case 1018ULL: goto x86_l_3fa;
	case 1026ULL: goto x86_l_402;
	case 1034ULL: goto x86_l_40a;
	case 1042ULL: goto x86_l_412;
	case 1050ULL: goto x86_l_41a;
	case 1058ULL: goto x86_l_422;
	case 1066ULL: goto x86_l_42a;
	case 1074ULL: goto x86_l_432;
	case 1082ULL: goto x86_l_43a;
	case 1090ULL: goto x86_l_442;
	case 1098ULL: goto x86_l_44a;
	case 1106ULL: goto x86_l_452;
	case 1114ULL: goto x86_l_45a;
	case 1122ULL: goto x86_l_462;
	case 1130ULL: goto x86_l_46a;
	case 1138ULL: goto x86_l_472;
	case 1145ULL: goto x86_l_479;
	case 1151ULL: goto x86_l_47f;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1192ULL: goto x86_l_4a8;
	case 1197ULL: goto x86_l_4ad;
	case 1200ULL: goto x86_l_4b0;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1218ULL: goto x86_l_4c2;
	case 1222ULL: goto x86_l_4c6;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1242ULL: goto x86_l_4da;
	case 1247ULL: goto x86_l_4df;
	case 1249ULL: goto x86_l_4e1;
	case 1252ULL: goto x86_l_4e4;
	case 1258ULL: goto x86_l_4ea;
	case 1266ULL: goto x86_l_4f2;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1285ULL: goto x86_l_505;
	case 1296ULL: goto x86_l_510;
	case 1307ULL: goto x86_l_51b;
	case 1318ULL: goto x86_l_526;
	case 1329ULL: goto x86_l_531;
	case 1340ULL: goto x86_l_53c;
	case 1351ULL: goto x86_l_547;
	case 1362ULL: goto x86_l_552;
	case 1373ULL: goto x86_l_55d;
	case 1381ULL: goto x86_l_565;
	case 1389ULL: goto x86_l_56d;
	case 1397ULL: goto x86_l_575;
	case 1405ULL: goto x86_l_57d;
	case 1413ULL: goto x86_l_585;
	case 1421ULL: goto x86_l_58d;
	case 1429ULL: goto x86_l_595;
	case 1437ULL: goto x86_l_59d;
	case 1445ULL: goto x86_l_5a5;
	case 1453ULL: goto x86_l_5ad;
	case 1461ULL: goto x86_l_5b5;
	case 1469ULL: goto x86_l_5bd;
	case 1477ULL: goto x86_l_5c5;
	case 1485ULL: goto x86_l_5cd;
	case 1493ULL: goto x86_l_5d5;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1526ULL: goto x86_l_5f6;
	case 1529ULL: goto x86_l_5f9;
	case 1532ULL: goto x86_l_5fc;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1550ULL: goto x86_l_60e;
	case 1556ULL: goto x86_l_614;
	case 1559ULL: goto x86_l_617;
	case 1566ULL: goto x86_l_61e;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1588ULL: goto x86_l_634;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1630ULL: goto x86_l_65e;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1678ULL: goto x86_l_68e;
	case 1682ULL: goto x86_l_692;
	case 1685ULL: goto x86_l_695;
	case 1693ULL: goto x86_l_69d;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1712ULL: goto x86_l_6b0;
	case 1715ULL: goto x86_l_6b3;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1746ULL: goto x86_l_6d2;
	case 1750ULL: goto x86_l_6d6;
	case 1754ULL: goto x86_l_6da;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1775ULL: goto x86_l_6ef;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1851ULL: goto x86_l_73b;
	case 1853ULL: goto x86_l_73d;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1886ULL: goto x86_l_75e;
	case 1890ULL: goto x86_l_762;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1911ULL: goto x86_l_777;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1946ULL: goto x86_l_79a;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2029ULL: goto x86_l_7ed;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2054ULL: goto x86_l_806;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2068ULL: goto x86_l_814;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2082ULL: goto x86_l_822;
	case 2087ULL: goto x86_l_827;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
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
	/* 0x2a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f:
	/* 0x2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34:
	/* 0x34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36:
	/* 0x36: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_3e:
	/* 0x3e: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_43:
	/* 0x43: jne    b5 <trace_set_fs_pwd+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5;
	}
x86_l_45:
	/* 0x45: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_4a:
	/* 0x4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c:
	/* 0x4c: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_51:
	/* 0x51: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_54:
	/* 0x54: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_56:
	/* 0x56: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f:
	/* 0x5f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64:
	/* 0x64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f:
	/* 0x6f: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_73:
	/* 0x73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78:
	/* 0x78: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d:
	/* 0x7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82:
	/* 0x82: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_85:
	/* 0x85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87:
	/* 0x87: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_8c:
	/* 0x8c: jne    94 <trace_set_fs_pwd+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94;
	}
x86_l_8e:
	/* 0x8e: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_92:
	/* 0x92: jmp    b5 <trace_set_fs_pwd+0xb5> */
	goto x86_l_b5;
x86_l_94:
	/* 0x94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_99:
	/* 0x99: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_a0:
	/* 0xa0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a5:
	/* 0xa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7:
	/* 0xa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: je     b0 <trace_set_fs_pwd+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_ac:
	/* 0xac: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: jmp    b5 <trace_set_fs_pwd+0xb5> */
	goto x86_l_b5;
x86_l_b0:
	/* 0xb0: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bd:
	/* 0xbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c2:
	/* 0xc2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c9:
	/* 0xc9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce:
	/* 0xce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0:
	/* 0xd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: je     1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_d9:
	/* 0xd9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e1:
	/* 0xe1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e8:
	/* 0xe8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_f8:
	/* 0xf8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
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
	/* 0x165: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
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
	/* 0x1e7: mov    DWORD PTR [r14+0x70],0x30d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337933ULL);
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
	/* 0x20d: mov    DWORD PTR [rsp+0xa4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_214:
	/* 0x214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_228:
	/* 0x228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a:
	/* 0x22a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f:
	/* 0x22f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_232:
	/* 0x232: je     279 <trace_set_fs_pwd+0x279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279;
	}
x86_l_234:
	/* 0x234: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_238:
	/* 0x238: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23f:
	/* 0x23f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_244:
	/* 0x244: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_24b:
	/* 0x24b: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_253:
	/* 0x253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255:
	/* 0x255: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_258:
	/* 0x258: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: je     4bb <trace_set_fs_pwd+0x4bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bb;
	}
x86_l_261:
	/* 0x261: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_267:
	/* 0x267: jne    a1a <trace_set_fs_pwd+0xa1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2586ULL;
	}
x86_l_26d:
	/* 0x26d: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_272:
	/* 0x272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274:
	/* 0x274: jmp    aa1 <trace_set_fs_pwd+0xaa1> */
	return 2721ULL;
x86_l_279:
	/* 0x279: mov    eax,DWORD PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_280:
	/* 0x280: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_284:
	/* 0x284: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_28c:
	/* 0x28c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_291:
	/* 0x291: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_298:
	/* 0x298: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29d:
	/* 0x29d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f:
	/* 0x29f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: je     1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_2a8:
	/* 0x2a8: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ac:
	/* 0x2ac: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b0:
	/* 0x2b0: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2bb:
	/* 0x2bb: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2c6:
	/* 0x2c6: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2d1:
	/* 0x2d1: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2dc:
	/* 0x2dc: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2e7:
	/* 0x2e7: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2f2:
	/* 0x2f2: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2fd:
	/* 0x2fd: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_308:
	/* 0x308: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_313:
	/* 0x313: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_31e:
	/* 0x31e: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_329:
	/* 0x329: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_334:
	/* 0x334: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_33f:
	/* 0x33f: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_34a:
	/* 0x34a: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_355:
	/* 0x355: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_360:
	/* 0x360: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_376:
	/* 0x376: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_381:
	/* 0x381: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_397:
	/* 0x397: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3a2:
	/* 0x3a2: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3ad:
	/* 0x3ad: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3b8:
	/* 0x3b8: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3c3:
	/* 0x3c3: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3ce:
	/* 0x3ce: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3d9:
	/* 0x3d9: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3e4:
	/* 0x3e4: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3fa:
	/* 0x3fa: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_402:
	/* 0x402: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_40a:
	/* 0x40a: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_41a:
	/* 0x41a: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_422:
	/* 0x422: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_42a:
	/* 0x42a: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_432:
	/* 0x432: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_43a:
	/* 0x43a: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_44a:
	/* 0x44a: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_452:
	/* 0x452: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_45a:
	/* 0x45a: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_462:
	/* 0x462: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_472:
	/* 0x472: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_479:
	/* 0x479: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_47f:
	/* 0x47f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_486:
	/* 0x486: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48b:
	/* 0x48b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_490:
	/* 0x490: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_493:
	/* 0x493: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_496:
	/* 0x496: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_499:
	/* 0x499: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49e:
	/* 0x49e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a3:
	/* 0x4a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a6:
	/* 0x4a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a8:
	/* 0x4a8: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad:
	/* 0x4ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b0:
	/* 0x4b0: jne    234 <trace_set_fs_pwd+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_234;
	}
x86_l_4b6:
	/* 0x4b6: jmp    1b71 <trace_set_fs_pwd+0x1b71> */
	return 7025ULL;
x86_l_4bb:
	/* 0x4bb: mov    eax,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4c2:
	/* 0x4c2: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c6:
	/* 0x4c6: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4ce:
	/* 0x4ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d3:
	/* 0x4d3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4da:
	/* 0x4da: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4df:
	/* 0x4df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1:
	/* 0x4e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e4:
	/* 0x4e4: je     1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_4ea:
	/* 0x4ea: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f2:
	/* 0x4f2: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f6:
	/* 0x4f6: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4fa:
	/* 0x4fa: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_505:
	/* 0x505: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_510:
	/* 0x510: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_51b:
	/* 0x51b: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_526:
	/* 0x526: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_531:
	/* 0x531: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_547:
	/* 0x547: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_55d:
	/* 0x55d: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_565:
	/* 0x565: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_56d:
	/* 0x56d: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_575:
	/* 0x575: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_585:
	/* 0x585: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_595:
	/* 0x595: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5a5:
	/* 0x5a5: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5ad:
	/* 0x5ad: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b5:
	/* 0x5b5: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5c5:
	/* 0x5c5: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5cd:
	/* 0x5cd: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dc:
	/* 0x5dc: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5e2:
	/* 0x5e2: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5e9:
	/* 0x5e9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ee:
	/* 0x5ee: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5f3:
	/* 0x5f3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f6:
	/* 0x5f6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5f9:
	/* 0x5f9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5fc:
	/* 0x5fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_601:
	/* 0x601: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_606:
	/* 0x606: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_609:
	/* 0x609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b:
	/* 0x60b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: je     1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_614:
	/* 0x614: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_617:
	/* 0x617: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_61e:
	/* 0x61e: lea    r12,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_622:
	/* 0x622: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_627:
	/* 0x627: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62c:
	/* 0x62c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_631:
	/* 0x631: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_634:
	/* 0x634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_636:
	/* 0x636: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_63b:
	/* 0x63b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_640:
	/* 0x640: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_644:
	/* 0x644: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_649:
	/* 0x649: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64e:
	/* 0x64e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_653:
	/* 0x653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655:
	/* 0x655: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65a:
	/* 0x65a: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_65e:
	/* 0x65e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_663:
	/* 0x663: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_668:
	/* 0x668: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66d:
	/* 0x66d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66f:
	/* 0x66f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_674:
	/* 0x674: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_679:
	/* 0x679: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_67d:
	/* 0x67d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_682:
	/* 0x682: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_687:
	/* 0x687: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_68c:
	/* 0x68c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68e:
	/* 0x68e: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_692:
	/* 0x692: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_695:
	/* 0x695: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_69d:
	/* 0x69d: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a6:
	/* 0x6a6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ab:
	/* 0x6ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b0:
	/* 0x6b0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6b3:
	/* 0x6b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b5:
	/* 0x6b5: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ba:
	/* 0x6ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6bf:
	/* 0x6bf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c4:
	/* 0x6c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c9:
	/* 0x6c9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6cc:
	/* 0x6cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ce:
	/* 0x6ce: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d2:
	/* 0x6d2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6d6:
	/* 0x6d6: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6da:
	/* 0x6da: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6de:
	/* 0x6de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e3:
	/* 0x6e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e8:
	/* 0x6e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6ed:
	/* 0x6ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ef:
	/* 0x6ef: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f3:
	/* 0x6f3: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6f6:
	/* 0x6f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6fb:
	/* 0x6fb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_700:
	/* 0x700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_705:
	/* 0x705: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_708:
	/* 0x708: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70a:
	/* 0x70a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_70f:
	/* 0x70f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_713:
	/* 0x713: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_718:
	/* 0x718: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71d:
	/* 0x71d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_722:
	/* 0x722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_724:
	/* 0x724: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_729:
	/* 0x729: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72e:
	/* 0x72e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_733:
	/* 0x733: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_738:
	/* 0x738: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_73b:
	/* 0x73b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73d:
	/* 0x73d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_741:
	/* 0x741: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_745:
	/* 0x745: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_749:
	/* 0x749: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_74d:
	/* 0x74d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_752:
	/* 0x752: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_757:
	/* 0x757: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_75c:
	/* 0x75c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75e:
	/* 0x75e: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_762:
	/* 0x762: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_765:
	/* 0x765: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_76a:
	/* 0x76a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_76f:
	/* 0x76f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_774:
	/* 0x774: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_777:
	/* 0x777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_779:
	/* 0x779: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77e:
	/* 0x77e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_783:
	/* 0x783: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_788:
	/* 0x788: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_78d:
	/* 0x78d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_790:
	/* 0x790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_792:
	/* 0x792: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_796:
	/* 0x796: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_79a:
	/* 0x79a: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_79e:
	/* 0x79e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7a2:
	/* 0x7a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a7:
	/* 0x7a7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ac:
	/* 0x7ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b1:
	/* 0x7b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b3:
	/* 0x7b3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7b8:
	/* 0x7b8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7bc:
	/* 0x7bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c1:
	/* 0x7c1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c6:
	/* 0x7c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7cb:
	/* 0x7cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cd:
	/* 0x7cd: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d2:
	/* 0x7d2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7d7:
	/* 0x7d7: lea    r15,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7db:
	/* 0x7db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e0:
	/* 0x7e0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7e5:
	/* 0x7e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ea:
	/* 0x7ea: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7ed:
	/* 0x7ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ef:
	/* 0x7ef: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f4:
	/* 0x7f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f9:
	/* 0x7f9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7fe:
	/* 0x7fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_803:
	/* 0x803: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_806:
	/* 0x806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_808:
	/* 0x808: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_80c:
	/* 0x80c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_810:
	/* 0x810: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_814:
	/* 0x814: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_818:
	/* 0x818: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_81d:
	/* 0x81d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_822:
	/* 0x822: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_827:
	/* 0x827: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_829:
	/* 0x829: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82e:
	/* 0x82e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_832:
	/* 0x832: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_837:
	/* 0x837: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83c:
	/* 0x83c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_841:
	/* 0x841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_843:
	/* 0x843: cmp    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_848:
	/* 0x848: jne    89f <trace_set_fs_pwd+0x89f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2207ULL;
	}
x86_l_84a:
	/* 0x84a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_84f:
	/* 0x84f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_854:
	/* 0x854: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_859:
	/* 0x859: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
	return 2140ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2140ULL: goto x86_l_85c;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2179ULL: goto x86_l_883;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2211ULL: goto x86_l_8a3;
	case 2219ULL: goto x86_l_8ab;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2308ULL: goto x86_l_904;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2350ULL: goto x86_l_92e;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2446ULL: goto x86_l_98e;
	case 2454ULL: goto x86_l_996;
	case 2462ULL: goto x86_l_99e;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2492ULL: goto x86_l_9bc;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2541ULL: goto x86_l_9ed;
	case 2544ULL: goto x86_l_9f0;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2574ULL: goto x86_l_a0e;
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
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2772ULL: goto x86_l_ad4;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2790ULL: goto x86_l_ae6;
	case 2796ULL: goto x86_l_aec;
	case 2807ULL: goto x86_l_af7;
	case 2815ULL: goto x86_l_aff;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2839ULL: goto x86_l_b17;
	case 2842ULL: goto x86_l_b1a;
	case 2844ULL: goto x86_l_b1c;
	case 2849ULL: goto x86_l_b21;
	case 2854ULL: goto x86_l_b26;
	case 2857ULL: goto x86_l_b29;
	case 2859ULL: goto x86_l_b2b;
	case 2862ULL: goto x86_l_b2e;
	case 2864ULL: goto x86_l_b30;
	case 2868ULL: goto x86_l_b34;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2885ULL: goto x86_l_b45;
	case 2889ULL: goto x86_l_b49;
	case 2893ULL: goto x86_l_b4d;
	case 2900ULL: goto x86_l_b54;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2918ULL: goto x86_l_b66;
	case 2922ULL: goto x86_l_b6a;
	case 2929ULL: goto x86_l_b71;
	case 2933ULL: goto x86_l_b75;
	case 2940ULL: goto x86_l_b7c;
	case 2944ULL: goto x86_l_b80;
	case 2951ULL: goto x86_l_b87;
	case 2958ULL: goto x86_l_b8e;
	case 2965ULL: goto x86_l_b95;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2991ULL: goto x86_l_baf;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3008ULL: goto x86_l_bc0;
	case 3010ULL: goto x86_l_bc2;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3023ULL: goto x86_l_bcf;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3041ULL: goto x86_l_be1;
	case 3044ULL: goto x86_l_be4;
	case 3050ULL: goto x86_l_bea;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3063ULL: goto x86_l_bf7;
	case 3066ULL: goto x86_l_bfa;
	case 3070ULL: goto x86_l_bfe;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3141ULL: goto x86_l_c45;
	case 3145ULL: goto x86_l_c49;
	case 3148ULL: goto x86_l_c4c;
	case 3151ULL: goto x86_l_c4f;
	case 3154ULL: goto x86_l_c52;
	case 3161ULL: goto x86_l_c59;
	case 3164ULL: goto x86_l_c5c;
	case 3167ULL: goto x86_l_c5f;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	case 3185ULL: goto x86_l_c71;
	case 3187ULL: goto x86_l_c73;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3238ULL: goto x86_l_ca6;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3256ULL: goto x86_l_cb8;
	case 3264ULL: goto x86_l_cc0;
	case 3271ULL: goto x86_l_cc7;
	case 3279ULL: goto x86_l_ccf;
	case 3286ULL: goto x86_l_cd6;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3369ULL: goto x86_l_d29;
	case 3372ULL: goto x86_l_d2c;
	case 3374ULL: goto x86_l_d2e;
	case 3376ULL: goto x86_l_d30;
	case 3384ULL: goto x86_l_d38;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3400ULL: goto x86_l_d48;
	case 3403ULL: goto x86_l_d4b;
	case 3405ULL: goto x86_l_d4d;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3416ULL: goto x86_l_d58;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3448ULL: goto x86_l_d78;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3471ULL: goto x86_l_d8f;
	case 3474ULL: goto x86_l_d92;
	case 3476ULL: goto x86_l_d94;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3488ULL: goto x86_l_da0;
	case 3495ULL: goto x86_l_da7;
	case 3502ULL: goto x86_l_dae;
	case 3505ULL: goto x86_l_db1;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3518ULL: goto x86_l_dbe;
	case 3521ULL: goto x86_l_dc1;
	case 3526ULL: goto x86_l_dc6;
	case 3529ULL: goto x86_l_dc9;
	case 3531ULL: goto x86_l_dcb;
	case 3533ULL: goto x86_l_dcd;
	case 3535ULL: goto x86_l_dcf;
	case 3543ULL: goto x86_l_dd7;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3564ULL: goto x86_l_dec;
	case 3568ULL: goto x86_l_df0;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3575ULL: goto x86_l_df7;
	case 3583ULL: goto x86_l_dff;
	case 3586ULL: goto x86_l_e02;
	case 3589ULL: goto x86_l_e05;
	case 3592ULL: goto x86_l_e08;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3605ULL: goto x86_l_e15;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3618ULL: goto x86_l_e22;
	case 3622ULL: goto x86_l_e26;
	case 3629ULL: goto x86_l_e2d;
	case 3636ULL: goto x86_l_e34;
	case 3644ULL: goto x86_l_e3c;
	case 3651ULL: goto x86_l_e43;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3742ULL: goto x86_l_e9e;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3778ULL: goto x86_l_ec2;
	case 3786ULL: goto x86_l_eca;
	default: return 0xffffffffffffffffULL;
	}
x86_l_85c:
	/* 0x85c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85e:
	/* 0x85e: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_863:
	/* 0x863: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_868:
	/* 0x868: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86d:
	/* 0x86d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_872:
	/* 0x872: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_875:
	/* 0x875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_877:
	/* 0x877: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_87b:
	/* 0x87b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_87f:
	/* 0x87f: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_883:
	/* 0x883: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_887:
	/* 0x887: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_88c:
	/* 0x88c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_891:
	/* 0x891: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_896:
	/* 0x896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_898:
	/* 0x898: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_89c:
	/* 0x89c: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_89f:
	/* 0x89f: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a3:
	/* 0x8a3: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8ab:
	/* 0x8ab: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b2:
	/* 0x8b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b7:
	/* 0x8b7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8bc:
	/* 0x8bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c1:
	/* 0x8c1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c6:
	/* 0x8c6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8cb:
	/* 0x8cb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8cf:
	/* 0x8cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d4:
	/* 0x8d4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d9:
	/* 0x8d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8de:
	/* 0x8de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e0:
	/* 0x8e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e5:
	/* 0x8e5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ea:
	/* 0x8ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8ef:
	/* 0x8ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8fa:
	/* 0x8fa: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8fd:
	/* 0x8fd: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_902:
	/* 0x902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_904:
	/* 0x904: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_907:
	/* 0x907: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_90b:
	/* 0x90b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_910:
	/* 0x910: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_915:
	/* 0x915: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_91a:
	/* 0x91a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91c:
	/* 0x91c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_921:
	/* 0x921: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_925:
	/* 0x925: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_92a:
	/* 0x92a: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_92e:
	/* 0x92e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_933:
	/* 0x933: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_938:
	/* 0x938: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_93d:
	/* 0x93d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93f:
	/* 0x93f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_944:
	/* 0x944: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_948:
	/* 0x948: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94d:
	/* 0x94d: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_951:
	/* 0x951: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_956:
	/* 0x956: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95b:
	/* 0x95b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_960:
	/* 0x960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_962:
	/* 0x962: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_967:
	/* 0x967: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_96b:
	/* 0x96b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_970:
	/* 0x970: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_975:
	/* 0x975: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_97a:
	/* 0x97a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_97d:
	/* 0x97d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97f:
	/* 0x97f: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_984:
	/* 0x984: je     98a <trace_set_fs_pwd+0x98a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98a;
	}
x86_l_986:
	/* 0x986: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_98a:
	/* 0x98a: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_98e:
	/* 0x98e: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_996:
	/* 0x996: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_99e:
	/* 0x99e: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_9a3:
	/* 0x9a3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9a8:
	/* 0x9a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9aa:
	/* 0x9aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9af:
	/* 0x9af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b4:
	/* 0x9b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9b9:
	/* 0x9b9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9be:
	/* 0x9be: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c3:
	/* 0x9c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c8:
	/* 0x9c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9cd:
	/* 0x9cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d2:
	/* 0x9d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d4:
	/* 0x9d4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d9:
	/* 0x9d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9de:
	/* 0x9de: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e3:
	/* 0x9e3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9e6:
	/* 0x9e6: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9eb:
	/* 0x9eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ed:
	/* 0x9ed: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9f0:
	/* 0x9f0: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9f4:
	/* 0x9f4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9f9:
	/* 0x9f9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a06:
	/* 0xa06: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a0e:
	/* 0xa0e: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a14:
	/* 0xa14: je     26d <trace_set_fs_pwd+0x26d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 621ULL;
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
	/* 0xa2b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0xa3c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a41:
	/* 0xa41: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
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
	/* 0xa52: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
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
	/* 0xa81: je     a9f <trace_set_fs_pwd+0xa9f> */
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
	/* 0xa9d: jmp    aa1 <trace_set_fs_pwd+0xaa1> */
	goto x86_l_aa1;
x86_l_a9f:
	/* 0xa9f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa1:
	/* 0xaa1: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa9:
	/* 0xaa9: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aad:
	/* 0xaad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab2:
	/* 0xab2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_ab9:
	/* 0xab9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_abe:
	/* 0xabe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac0:
	/* 0xac0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: je     adb <trace_set_fs_pwd+0xadb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_adb;
	}
x86_l_ac5:
	/* 0xac5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ac8:
	/* 0xac8: mov    BYTE PTR [rbx+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ace:
	/* 0xace: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_ad1:
	/* 0xad1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ad4:
	/* 0xad4: jne    adb <trace_set_fs_pwd+0xadb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_adb;
	}
x86_l_ad6:
	/* 0xad6: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_adb:
	/* 0xadb: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ae0:
	/* 0xae0: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ae6:
	/* 0xae6: jne    1b42 <trace_set_fs_pwd+0x1b42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6978ULL;
	}
x86_l_aec:
	/* 0xaec: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_af7:
	/* 0xaf7: mov    DWORD PTR [rsp+0x30],0x30d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430989ULL);
x86_l_aff:
	/* 0xaff: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b04:
	/* 0xb04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b09:
	/* 0xb09: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b10:
	/* 0xb10: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b15:
	/* 0xb15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b17:
	/* 0xb17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1a:
	/* 0xb1a: je     b87 <trace_set_fs_pwd+0xb87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b87;
	}
x86_l_b1c:
	/* 0xb1c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b21:
	/* 0xb21: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b26:
	/* 0xb26: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b29:
	/* 0xb29: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b2b:
	/* 0xb2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2e:
	/* 0xb2e: je     b87 <trace_set_fs_pwd+0xb87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b87;
	}
x86_l_b30:
	/* 0xb30: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b34:
	/* 0xb34: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b3b:
	/* 0xb3b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3e:
	/* 0xb3e: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b45:
	/* 0xb45: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b49:
	/* 0xb49: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b4d:
	/* 0xb4d: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b54:
	/* 0xb54: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b5b:
	/* 0xb5b: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5f:
	/* 0xb5f: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b66:
	/* 0xb66: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6a:
	/* 0xb6a: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b71:
	/* 0xb71: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b75:
	/* 0xb75: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b7c:
	/* 0xb7c: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b80:
	/* 0xb80: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b87:
	/* 0xb87: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b8e:
	/* 0xb8e: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b95:
	/* 0xb95: mov    ecx,DWORD PTR [r14+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_b99:
	/* 0xb99: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_b9c:
	/* 0xb9c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9e:
	/* 0xb9e: cmp    ecx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 80ULL);
x86_l_ba1:
	/* 0xba1: jne    20fb <trace_set_fs_pwd+0x20fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8443ULL;
	}
x86_l_ba7:
	/* 0xba7: lea    rdx,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bab:
	/* 0xbab: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_baf:
	/* 0xbaf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb1:
	/* 0xbb1: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bb6:
	/* 0xbb6: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_bb8:
	/* 0xbb8: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bc0:
	/* 0xbc0: jne    bda <trace_set_fs_pwd+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bda;
	}
x86_l_bc2:
	/* 0xbc2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc5:
	/* 0xbc5: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_bc8:
	/* 0xbc8: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bcf:
	/* 0xbcf: jne    13bb <trace_set_fs_pwd+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5051ULL;
	}
x86_l_bd5:
	/* 0xbd5: jmp    20fb <trace_set_fs_pwd+0x20fb> */
	return 8443ULL;
x86_l_bda:
	/* 0xbda: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_be1:
	/* 0xbe1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be4:
	/* 0xbe4: je     da0 <trace_set_fs_pwd+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da0;
	}
x86_l_bea:
	/* 0xbea: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_bf1:
	/* 0xbf1: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_bf4:
	/* 0xbf4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf7:
	/* 0xbf7: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_bfa:
	/* 0xbfa: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_bfe:
	/* 0xbfe: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c01:
	/* 0xc01: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c04:
	/* 0xc04: xor    r13,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_c0b:
	/* 0xc0b: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c0e:
	/* 0xc0e: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_c15:
	/* 0xc15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c18:
	/* 0xc18: je     c39 <trace_set_fs_pwd+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c39;
	}
x86_l_c1a:
	/* 0xc1a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1c:
	/* 0xc1c: cmp    BYTE PTR [rbx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_c23:
	/* 0xc23: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_c26:
	/* 0xc26: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c29:
	/* 0xc29: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c2c:
	/* 0xc2c: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_c33:
	/* 0xc33: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c36:
	/* 0xc36: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c39:
	/* 0xc39: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_c40:
	/* 0xc40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: je     c5f <trace_set_fs_pwd+0xc5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5f;
	}
x86_l_c45:
	/* 0xc45: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c49:
	/* 0xc49: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c4c:
	/* 0xc4c: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_c4f:
	/* 0xc4f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c52:
	/* 0xc52: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_c59:
	/* 0xc59: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c5c:
	/* 0xc5c: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c5f:
	/* 0xc5f: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_c66:
	/* 0xc66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c69:
	/* 0xc69: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c71:
	/* 0xc71: je     c8f <trace_set_fs_pwd+0xc8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8f;
	}
x86_l_c73:
	/* 0xc73: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c76:
	/* 0xc76: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7b:
	/* 0xc7b: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c7f:
	/* 0xc7f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c82:
	/* 0xc82: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_c89:
	/* 0xc89: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c8c:
	/* 0xc8c: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c8f:
	/* 0xc8f: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c94:
	/* 0xc94: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_c9b:
	/* 0xc9b: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_c9e:
	/* 0xc9e: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ca6:
	/* 0xca6: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cab:
	/* 0xcab: je     e0d <trace_set_fs_pwd+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0d;
	}
x86_l_cb1:
	/* 0xcb1: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_cb8:
	/* 0xcb8: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cc0:
	/* 0xcc0: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_cc7:
	/* 0xcc7: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ccf:
	/* 0xccf: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_cd6:
	/* 0xcd6: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cde:
	/* 0xcde: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce3:
	/* 0xce3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce8:
	/* 0xce8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_cef:
	/* 0xcef: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf4:
	/* 0xcf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf6:
	/* 0xcf6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_cf9:
	/* 0xcf9: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cfd:
	/* 0xcfd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d02:
	/* 0xd02: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d09:
	/* 0xd09: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d0c:
	/* 0xd0c: je     d2e <trace_set_fs_pwd+0xd2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2e;
	}
x86_l_d0e:
	/* 0xd0e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d13:
	/* 0xd13: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d18:
	/* 0xd18: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d1b:
	/* 0xd1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1d:
	/* 0xd1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d20:
	/* 0xd20: je     d2e <trace_set_fs_pwd+0xd2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2e;
	}
x86_l_d22:
	/* 0xd22: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d25:
	/* 0xd25: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d29:
	/* 0xd29: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d2c:
	/* 0xd2c: jmp    d30 <trace_set_fs_pwd+0xd30> */
	goto x86_l_d30;
x86_l_d2e:
	/* 0xd2e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d30:
	/* 0xd30: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d38:
	/* 0xd38: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d40:
	/* 0xd40: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d45:
	/* 0xd45: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_d48:
	/* 0xd48: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d4b:
	/* 0xd4b: jb     d63 <trace_set_fs_pwd+0xd63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d63;
	}
x86_l_d4d:
	/* 0xd4d: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d51:
	/* 0xd51: je     d58 <trace_set_fs_pwd+0xd58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d58;
	}
x86_l_d53:
	/* 0xd53: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: jbe    d63 <trace_set_fs_pwd+0xd63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d63;
	}
x86_l_d58:
	/* 0xd58: and    rbp,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_d60:
	/* 0xd60: or     rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_d63:
	/* 0xd63: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d67:
	/* 0xd67: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d6c:
	/* 0xd6c: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d73:
	/* 0xd73: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d76:
	/* 0xd76: je     dbc <trace_set_fs_pwd+0xdbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dbc;
	}
x86_l_d78:
	/* 0xd78: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d80:
	/* 0xd80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d85:
	/* 0xd85: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d8a:
	/* 0xd8a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8f:
	/* 0xd8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d92:
	/* 0xd92: je     dcd <trace_set_fs_pwd+0xdcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcd;
	}
x86_l_d94:
	/* 0xd94: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d97:
	/* 0xd97: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9b:
	/* 0xd9b: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d9e:
	/* 0xd9e: jmp    dcf <trace_set_fs_pwd+0xdcf> */
	goto x86_l_dcf;
x86_l_da0:
	/* 0xda0: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_da7:
	/* 0xda7: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_dae:
	/* 0xdae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db1:
	/* 0xdb1: jne    c1a <trace_set_fs_pwd+0xc1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c1a;
	}
x86_l_db7:
	/* 0xdb7: jmp    c39 <trace_set_fs_pwd+0xc39> */
	goto x86_l_c39;
x86_l_dbc:
	/* 0xdbc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dbe:
	/* 0xdbe: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dc1:
	/* 0xdc1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dc6:
	/* 0xdc6: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_dc9:
	/* 0xdc9: jae    dec <trace_set_fs_pwd+0xdec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_dec;
	}
x86_l_dcb:
	/* 0xdcb: jmp    e02 <trace_set_fs_pwd+0xe02> */
	goto x86_l_e02;
x86_l_dcd:
	/* 0xdcd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dcf:
	/* 0xdcf: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_dd7:
	/* 0xdd7: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ddf:
	/* 0xddf: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_de2:
	/* 0xde2: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de7:
	/* 0xde7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_dea:
	/* 0xdea: jb     e02 <trace_set_fs_pwd+0xe02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e02;
	}
x86_l_dec:
	/* 0xdec: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_df0:
	/* 0xdf0: je     df7 <trace_set_fs_pwd+0xdf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df7;
	}
x86_l_df2:
	/* 0xdf2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_df5:
	/* 0xdf5: jbe    e02 <trace_set_fs_pwd+0xe02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e02;
	}
x86_l_df7:
	/* 0xdf7: and    rbp,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_dff:
	/* 0xdff: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e02:
	/* 0xe02: or     rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_e05:
	/* 0xe05: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e08:
	/* 0xe08: and    r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e0b:
	/* 0xe0b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0d:
	/* 0xe0d: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_e15:
	/* 0xe15: je     ed3 <trace_set_fs_pwd+0xed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3795ULL;
	}
x86_l_e1b:
	/* 0xe1b: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_e20:
	/* 0xe20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e22:
	/* 0xe22: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e26:
	/* 0xe26: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_e2d:
	/* 0xe2d: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_e34:
	/* 0xe34: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e3c:
	/* 0xe3c: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_e43:
	/* 0xe43: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_e4a:
	/* 0xe4a: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_e4f:
	/* 0xe4f: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e54:
	/* 0xe54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e59:
	/* 0xe59: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_e60:
	/* 0xe60: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e65:
	/* 0xe65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e67:
	/* 0xe67: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e6b:
	/* 0xe6b: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e70:
	/* 0xe70: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e77:
	/* 0xe77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7a:
	/* 0xe7a: je     e9c <trace_set_fs_pwd+0xe9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9c;
	}
x86_l_e7c:
	/* 0xe7c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e81:
	/* 0xe81: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e86:
	/* 0xe86: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e8b:
	/* 0xe8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: je     e9c <trace_set_fs_pwd+0xe9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9c;
	}
x86_l_e90:
	/* 0xe90: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e93:
	/* 0xe93: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e97:
	/* 0xe97: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e9a:
	/* 0xe9a: jmp    e9e <trace_set_fs_pwd+0xe9e> */
	goto x86_l_e9e;
x86_l_e9c:
	/* 0xe9c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9e:
	/* 0xe9e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ea1:
	/* 0xea1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea6:
	/* 0xea6: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_ea9:
	/* 0xea9: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_eac:
	/* 0xeac: jae    eb2 <trace_set_fs_pwd+0xeb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_eb2;
	}
x86_l_eae:
	/* 0xeae: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb0:
	/* 0xeb0: jmp    ecd <trace_set_fs_pwd+0xecd> */
	return 3789ULL;
x86_l_eb2:
	/* 0xeb2: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eb6:
	/* 0xeb6: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_ebb:
	/* 0xebb: je     ec2 <trace_set_fs_pwd+0xec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec2;
	}
x86_l_ebd:
	/* 0xebd: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_ec0:
	/* 0xec0: jbe    ecd <trace_set_fs_pwd+0xecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3789ULL;
	}
x86_l_ec2:
	/* 0xec2: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_eca:
	/* 0xeca: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
	return 3789ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3803ULL: goto x86_l_edb;
	case 3809ULL: goto x86_l_ee1;
	case 3814ULL: goto x86_l_ee6;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3886ULL: goto x86_l_f2e;
	case 3890ULL: goto x86_l_f32;
	case 3894ULL: goto x86_l_f36;
	case 3901ULL: goto x86_l_f3d;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3926ULL: goto x86_l_f56;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3964ULL: goto x86_l_f7c;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3971ULL: goto x86_l_f83;
	case 3974ULL: goto x86_l_f86;
	case 3978ULL: goto x86_l_f8a;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 4005ULL: goto x86_l_fa5;
	case 4011ULL: goto x86_l_fab;
	case 4018ULL: goto x86_l_fb2;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4032ULL: goto x86_l_fc0;
	case 4037ULL: goto x86_l_fc5;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4068ULL: goto x86_l_fe4;
	case 4072ULL: goto x86_l_fe8;
	case 4076ULL: goto x86_l_fec;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4131ULL: goto x86_l_1023;
	case 4138ULL: goto x86_l_102a;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4184ULL: goto x86_l_1058;
	case 4187ULL: goto x86_l_105b;
	case 4189ULL: goto x86_l_105d;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4203ULL: goto x86_l_106b;
	case 4206ULL: goto x86_l_106e;
	case 4208ULL: goto x86_l_1070;
	case 4211ULL: goto x86_l_1073;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4242ULL: goto x86_l_1092;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4324ULL: goto x86_l_10e4;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4336ULL: goto x86_l_10f0;
	case 4341ULL: goto x86_l_10f5;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4353ULL: goto x86_l_1101;
	case 4360ULL: goto x86_l_1108;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4399ULL: goto x86_l_112f;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4417ULL: goto x86_l_1141;
	case 4420ULL: goto x86_l_1144;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4439ULL: goto x86_l_1157;
	case 4442ULL: goto x86_l_115a;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4450ULL: goto x86_l_1162;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4464ULL: goto x86_l_1170;
	case 4469ULL: goto x86_l_1175;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4479ULL: goto x86_l_117f;
	case 4486ULL: goto x86_l_1186;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4542ULL: goto x86_l_11be;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4553ULL: goto x86_l_11c9;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4565ULL: goto x86_l_11d5;
	case 4567ULL: goto x86_l_11d7;
	case 4569ULL: goto x86_l_11d9;
	case 4572ULL: goto x86_l_11dc;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4603ULL: goto x86_l_11fb;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4667ULL: goto x86_l_123b;
	case 4669ULL: goto x86_l_123d;
	case 4672ULL: goto x86_l_1240;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4681ULL: goto x86_l_1249;
	case 4684ULL: goto x86_l_124c;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4719ULL: goto x86_l_126f;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4744ULL: goto x86_l_1288;
	case 4749ULL: goto x86_l_128d;
	case 4751ULL: goto x86_l_128f;
	case 4758ULL: goto x86_l_1296;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4795ULL: goto x86_l_12bb;
	case 4797ULL: goto x86_l_12bd;
	case 4800ULL: goto x86_l_12c0;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4826ULL: goto x86_l_12da;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4860ULL: goto x86_l_12fc;
	case 4867ULL: goto x86_l_1303;
	case 4870ULL: goto x86_l_1306;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4916ULL: goto x86_l_1334;
	case 4918ULL: goto x86_l_1336;
	case 4921ULL: goto x86_l_1339;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4943ULL: goto x86_l_134f;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4965ULL: goto x86_l_1365;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4979ULL: goto x86_l_1373;
	case 4987ULL: goto x86_l_137b;
	case 4989ULL: goto x86_l_137d;
	case 4996ULL: goto x86_l_1384;
	case 4999ULL: goto x86_l_1387;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5018ULL: goto x86_l_139a;
	case 5021ULL: goto x86_l_139d;
	case 5028ULL: goto x86_l_13a4;
	case 5035ULL: goto x86_l_13ab;
	case 5038ULL: goto x86_l_13ae;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5058ULL: goto x86_l_13c2;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5113ULL: goto x86_l_13f9;
	case 5121ULL: goto x86_l_1401;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5140ULL: goto x86_l_1414;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5197ULL: goto x86_l_144d;
	case 5199ULL: goto x86_l_144f;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5225ULL: goto x86_l_1469;
	case 5227ULL: goto x86_l_146b;
	case 5232ULL: goto x86_l_1470;
	case 5236ULL: goto x86_l_1474;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5274ULL: goto x86_l_149a;
	case 5280ULL: goto x86_l_14a0;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5292ULL: goto x86_l_14ac;
	case 5296ULL: goto x86_l_14b0;
	case 5301ULL: goto x86_l_14b5;
	case 5306ULL: goto x86_l_14ba;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ecd:
	/* 0xecd: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed0:
	/* 0xed0: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ed3:
	/* 0xed3: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_edb:
	/* 0xedb: je     f9d <trace_set_fs_pwd+0xf9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9d;
	}
x86_l_ee1:
	/* 0xee1: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_ee6:
	/* 0xee6: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_eed:
	/* 0xeed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ef2:
	/* 0xef2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef7:
	/* 0xef7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_efc:
	/* 0xefc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efe:
	/* 0xefe: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f03:
	/* 0xf03: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f07:
	/* 0xf07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f0c:
	/* 0xf0c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f11:
	/* 0xf11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f1d:
	/* 0xf1d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f22:
	/* 0xf22: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f27:
	/* 0xf27: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2c:
	/* 0xf2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2e:
	/* 0xf2e: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f32:
	/* 0xf32: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f36:
	/* 0xf36: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_f3d:
	/* 0xf3d: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_f44:
	/* 0xf44: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f47:
	/* 0xf47: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_f4c:
	/* 0xf4c: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f51:
	/* 0xf51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f56:
	/* 0xf56: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_f5d:
	/* 0xf5d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f62:
	/* 0xf62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f64:
	/* 0xf64: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f6b:
	/* 0xf6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6e:
	/* 0xf6e: je     f8f <trace_set_fs_pwd+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f70:
	/* 0xf70: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f74:
	/* 0xf74: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f79:
	/* 0xf79: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f7c:
	/* 0xf7c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f7e:
	/* 0xf7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f81:
	/* 0xf81: je     f8f <trace_set_fs_pwd+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f83:
	/* 0xf83: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f86:
	/* 0xf86: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8a:
	/* 0xf8a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f8d:
	/* 0xf8d: jmp    f91 <trace_set_fs_pwd+0xf91> */
	goto x86_l_f91;
x86_l_f8f:
	/* 0xf8f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f91:
	/* 0xf91: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f94:
	/* 0xf94: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f97:
	/* 0xf97: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f9a:
	/* 0xf9a: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_f9d:
	/* 0xf9d: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_fa5:
	/* 0xfa5: je     108a <trace_set_fs_pwd+0x108a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108a;
	}
x86_l_fab:
	/* 0xfab: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_fb2:
	/* 0xfb2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fb6:
	/* 0xfb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fbb:
	/* 0xfbb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc0:
	/* 0xfc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc5:
	/* 0xfc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc7:
	/* 0xfc7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fcc:
	/* 0xfcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd1:
	/* 0xfd1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd6:
	/* 0xfd6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fdb:
	/* 0xfdb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fe4:
	/* 0xfe4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_fe8:
	/* 0xfe8: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_fec:
	/* 0xfec: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ff0:
	/* 0xff0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff5:
	/* 0xff5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ffa:
	/* 0xffa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fff:
	/* 0xfff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1001:
	/* 0x1001: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1006:
	/* 0x1006: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_100a:
	/* 0x100a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_100f:
	/* 0x100f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1014:
	/* 0x1014: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1019:
	/* 0x1019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101b:
	/* 0x101b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_101f:
	/* 0x101f: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1023:
	/* 0x1023: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_102a:
	/* 0x102a: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1031:
	/* 0x1031: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1034:
	/* 0x1034: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1039:
	/* 0x1039: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_103e:
	/* 0x103e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1043:
	/* 0x1043: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_104a:
	/* 0x104a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_104f:
	/* 0x104f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1051:
	/* 0x1051: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1058:
	/* 0x1058: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105b:
	/* 0x105b: je     107c <trace_set_fs_pwd+0x107c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_105d:
	/* 0x105d: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1061:
	/* 0x1061: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1066:
	/* 0x1066: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1069:
	/* 0x1069: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_106b:
	/* 0x106b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: je     107c <trace_set_fs_pwd+0x107c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1070:
	/* 0x1070: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1073:
	/* 0x1073: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1077:
	/* 0x1077: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_107a:
	/* 0x107a: jmp    107e <trace_set_fs_pwd+0x107e> */
	goto x86_l_107e;
x86_l_107c:
	/* 0x107c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107e:
	/* 0x107e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1081:
	/* 0x1081: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1084:
	/* 0x1084: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1087:
	/* 0x1087: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_108a:
	/* 0x108a: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1092:
	/* 0x1092: je     1162 <trace_set_fs_pwd+0x1162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1162;
	}
x86_l_1098:
	/* 0x1098: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_109d:
	/* 0x109d: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a9:
	/* 0x10a9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ae:
	/* 0x10ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b3:
	/* 0x10b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b5:
	/* 0x10b5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ba:
	/* 0x10ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10bf:
	/* 0x10bf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10c4:
	/* 0x10c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c9:
	/* 0x10c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cb:
	/* 0x10cb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d0:
	/* 0x10d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d5:
	/* 0x10d5: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10da:
	/* 0x10da: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_10dd:
	/* 0x10dd: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_10e2:
	/* 0x10e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e4:
	/* 0x10e4: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_10e8:
	/* 0x10e8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_10ed:
	/* 0x10ed: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10f0:
	/* 0x10f0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10f5:
	/* 0x10f5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10f8:
	/* 0x10f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fa:
	/* 0x10fa: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1101:
	/* 0x1101: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1108:
	/* 0x1108: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_110b:
	/* 0x110b: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1110:
	/* 0x1110: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1115:
	/* 0x1115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111a:
	/* 0x111a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1121:
	/* 0x1121: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1126:
	/* 0x1126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1128:
	/* 0x1128: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_112f:
	/* 0x112f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1132:
	/* 0x1132: je     1152 <trace_set_fs_pwd+0x1152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1152;
	}
x86_l_1134:
	/* 0x1134: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1139:
	/* 0x1139: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_113c:
	/* 0x113c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_113f:
	/* 0x113f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1141:
	/* 0x1141: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1144:
	/* 0x1144: je     1152 <trace_set_fs_pwd+0x1152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1152;
	}
x86_l_1146:
	/* 0x1146: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1149:
	/* 0x1149: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114d:
	/* 0x114d: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1150:
	/* 0x1150: jmp    1154 <trace_set_fs_pwd+0x1154> */
	goto x86_l_1154;
x86_l_1152:
	/* 0x1152: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1154:
	/* 0x1154: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1157:
	/* 0x1157: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_115a:
	/* 0x115a: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_115d:
	/* 0x115d: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1160:
	/* 0x1160: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1162:
	/* 0x1162: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_116a:
	/* 0x116a: je     11e7 <trace_set_fs_pwd+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e7;
	}
x86_l_116c:
	/* 0x116c: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1170:
	/* 0x1170: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1175:
	/* 0x1175: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1178:
	/* 0x1178: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_117d:
	/* 0x117d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117f:
	/* 0x117f: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1186:
	/* 0x1186: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_118d:
	/* 0x118d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1190:
	/* 0x1190: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1195:
	/* 0x1195: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_119a:
	/* 0x119a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_119f:
	/* 0x119f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_11a6:
	/* 0x11a6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11ab:
	/* 0x11ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ad:
	/* 0x11ad: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11b4:
	/* 0x11b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b7:
	/* 0x11b7: je     11d7 <trace_set_fs_pwd+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d7;
	}
x86_l_11b9:
	/* 0x11b9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11be:
	/* 0x11be: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11c1:
	/* 0x11c1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_11c4:
	/* 0x11c4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11c6:
	/* 0x11c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c9:
	/* 0x11c9: je     11d7 <trace_set_fs_pwd+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d7;
	}
x86_l_11cb:
	/* 0x11cb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ce:
	/* 0x11ce: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d2:
	/* 0x11d2: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11d5:
	/* 0x11d5: jmp    11d9 <trace_set_fs_pwd+0x11d9> */
	goto x86_l_11d9;
x86_l_11d7:
	/* 0x11d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d9:
	/* 0x11d9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11dc:
	/* 0x11dc: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_11df:
	/* 0x11df: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11e2:
	/* 0x11e2: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_11e5:
	/* 0x11e5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e7:
	/* 0x11e7: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_11ee:
	/* 0x11ee: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: je     125c <trace_set_fs_pwd+0x125c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125c;
	}
x86_l_11f3:
	/* 0x11f3: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f7:
	/* 0x11f7: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11fb:
	/* 0x11fb: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1202:
	/* 0x1202: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1205:
	/* 0x1205: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_120a:
	/* 0x120a: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_120f:
	/* 0x120f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1214:
	/* 0x1214: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_121b:
	/* 0x121b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1220:
	/* 0x1220: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1222:
	/* 0x1222: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1229:
	/* 0x1229: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122c:
	/* 0x122c: je     124e <trace_set_fs_pwd+0x124e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_124e;
	}
x86_l_122e:
	/* 0x122e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1233:
	/* 0x1233: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1238:
	/* 0x1238: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_123b:
	/* 0x123b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_123d:
	/* 0x123d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1240:
	/* 0x1240: je     124e <trace_set_fs_pwd+0x124e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_124e;
	}
x86_l_1242:
	/* 0x1242: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1245:
	/* 0x1245: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1249:
	/* 0x1249: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_124c:
	/* 0x124c: jmp    1250 <trace_set_fs_pwd+0x1250> */
	goto x86_l_1250;
x86_l_124e:
	/* 0x124e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1250:
	/* 0x1250: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1253:
	/* 0x1253: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1256:
	/* 0x1256: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1259:
	/* 0x1259: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_125c:
	/* 0x125c: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1263:
	/* 0x1263: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1266:
	/* 0x1266: je     12c9 <trace_set_fs_pwd+0x12c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c9;
	}
x86_l_1268:
	/* 0x1268: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_126f:
	/* 0x126f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1272:
	/* 0x1272: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1277:
	/* 0x1277: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127c:
	/* 0x127c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1281:
	/* 0x1281: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1288:
	/* 0x1288: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_128d:
	/* 0x128d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128f:
	/* 0x128f: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1296:
	/* 0x1296: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1299:
	/* 0x1299: je     12bb <trace_set_fs_pwd+0x12bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bb;
	}
x86_l_129b:
	/* 0x129b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12a0:
	/* 0x12a0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12a3:
	/* 0x12a3: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_12a8:
	/* 0x12a8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12aa:
	/* 0x12aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ad:
	/* 0x12ad: je     12bb <trace_set_fs_pwd+0x12bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bb;
	}
x86_l_12af:
	/* 0x12af: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b2:
	/* 0x12b2: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b6:
	/* 0x12b6: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12b9:
	/* 0x12b9: jmp    12bd <trace_set_fs_pwd+0x12bd> */
	goto x86_l_12bd;
x86_l_12bb:
	/* 0x12bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12bd:
	/* 0x12bd: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12c0:
	/* 0x12c0: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_12c3:
	/* 0x12c3: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12c6:
	/* 0x12c6: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_12c9:
	/* 0x12c9: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_12d0:
	/* 0x12d0: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_12d3:
	/* 0x12d3: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_12d8:
	/* 0x12d8: je     1347 <trace_set_fs_pwd+0x1347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1347;
	}
x86_l_12da:
	/* 0x12da: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_12e1:
	/* 0x12e1: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12e4:
	/* 0x12e4: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12e9:
	/* 0x12e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ee:
	/* 0x12ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_12f5:
	/* 0x12f5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12fa:
	/* 0x12fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fc:
	/* 0x12fc: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1303:
	/* 0x1303: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1306:
	/* 0x1306: je     1365 <trace_set_fs_pwd+0x1365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1365;
	}
x86_l_1308:
	/* 0x1308: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_130b:
	/* 0x130b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1310:
	/* 0x1310: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1314:
	/* 0x1314: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1319:
	/* 0x1319: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_131c:
	/* 0x131c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131e:
	/* 0x131e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1321:
	/* 0x1321: jne    133b <trace_set_fs_pwd+0x133b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_133b;
	}
x86_l_1323:
	/* 0x1323: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1328:
	/* 0x1328: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132c:
	/* 0x132c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1331:
	/* 0x1331: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1334:
	/* 0x1334: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1336:
	/* 0x1336: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1339:
	/* 0x1339: je     1365 <trace_set_fs_pwd+0x1365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1365;
	}
x86_l_133b:
	/* 0x133b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133e:
	/* 0x133e: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1342:
	/* 0x1342: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1345:
	/* 0x1345: jmp    1367 <trace_set_fs_pwd+0x1367> */
	goto x86_l_1367;
x86_l_1347:
	/* 0x1347: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_134f:
	/* 0x134f: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1356:
	/* 0x1356: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1359:
	/* 0x1359: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1361:
	/* 0x1361: jne    1391 <trace_set_fs_pwd+0x1391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1391;
	}
x86_l_1363:
	/* 0x1363: jmp    139d <trace_set_fs_pwd+0x139d> */
	goto x86_l_139d;
x86_l_1365:
	/* 0x1365: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1367:
	/* 0x1367: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_136a:
	/* 0x136a: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_136d:
	/* 0x136d: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1370:
	/* 0x1370: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1373:
	/* 0x1373: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_137b:
	/* 0x137b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137d:
	/* 0x137d: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1384:
	/* 0x1384: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1387:
	/* 0x1387: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_138f:
	/* 0x138f: je     139d <trace_set_fs_pwd+0x139d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139d;
	}
x86_l_1391:
	/* 0x1391: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1396:
	/* 0x1396: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_139a:
	/* 0x139a: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_139d:
	/* 0x139d: and    r13,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_13a4:
	/* 0x13a4: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13ab:
	/* 0x13ab: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13ae:
	/* 0x13ae: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13b5:
	/* 0x13b5: je     20fb <trace_set_fs_pwd+0x20fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8443ULL;
	}
x86_l_13bb:
	/* 0x13bb: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_13c2:
	/* 0x13c2: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_13c6:
	/* 0x13c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13cb:
	/* 0x13cb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d0:
	/* 0x13d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13d5:
	/* 0x13d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d7:
	/* 0x13d7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13dc:
	/* 0x13dc: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13e0:
	/* 0x13e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x13f1: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_13f9:
	/* 0x13f9: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1401:
	/* 0x1401: jne    20fb <trace_set_fs_pwd+0x20fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8443ULL;
	}
x86_l_1407:
	/* 0x1407: cmp    DWORD PTR [r14+0x74],0x50 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206416ULL);
x86_l_140c:
	/* 0x140c: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1414:
	/* 0x1414: jne    144f <trace_set_fs_pwd+0x144f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_144f;
	}
x86_l_1416:
	/* 0x1416: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_141b:
	/* 0x141b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141d:
	/* 0x141d: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_1422:
	/* 0x1422: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1425:
	/* 0x1425: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1427:
	/* 0x1427: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1431:
	/* 0x1431: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1436:
	/* 0x1436: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_143b:
	/* 0x143b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1447:
	/* 0x1447: jne    1453 <trace_set_fs_pwd+0x1453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1453;
	}
x86_l_1449:
	/* 0x1449: mov    rbp,QWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_144d:
	/* 0x144d: jmp    1470 <trace_set_fs_pwd+0x1470> */
	goto x86_l_1470;
x86_l_144f:
	/* 0x144f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1451:
	/* 0x1451: jmp    1470 <trace_set_fs_pwd+0x1470> */
	goto x86_l_1470;
x86_l_1453:
	/* 0x1453: add    rbx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
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
	/* 0x1466: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1469:
	/* 0x1469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146b:
	/* 0x146b: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1470:
	/* 0x1470: mov    rbx,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1474:
	/* 0x1474: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_147c:
	/* 0x147c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1481:
	/* 0x1481: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_1488:
	/* 0x1488: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_148d:
	/* 0x148d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148f:
	/* 0x148f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1492:
	/* 0x1492: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_149a:
	/* 0x149a: je     15ea <trace_set_fs_pwd+0x15ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5610ULL;
	}
x86_l_14a0:
	/* 0x14a0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_14a3:
	/* 0x14a3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_14a6:
	/* 0x14a6: je     18e7 <trace_set_fs_pwd+0x18e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6375ULL;
	}
x86_l_14ac:
	/* 0x14ac: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b0:
	/* 0x14b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14b5:
	/* 0x14b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14ba:
	/* 0x14ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14bf:
	/* 0x14bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c1:
	/* 0x14c1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14c6:
	/* 0x14c6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14cb:
	/* 0x14cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14d0:
	/* 0x14d0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14d5:
	/* 0x14d5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14da:
	/* 0x14da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14df:
	/* 0x14df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e1:
	/* 0x14e1: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_14e6:
	/* 0x14e6: jne    1606 <trace_set_fs_pwd+0x1606> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5638ULL;
	}
x86_l_14ec:
	/* 0x14ec: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f1:
	/* 0x14f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14f6:
	/* 0x14f6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 5371ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5371ULL: goto x86_l_14fb;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5454ULL: goto x86_l_154e;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5479ULL: goto x86_l_1567;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5520ULL: goto x86_l_1590;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5531ULL: goto x86_l_159b;
	case 5537ULL: goto x86_l_15a1;
	case 5539ULL: goto x86_l_15a3;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5557ULL: goto x86_l_15b5;
	case 5559ULL: goto x86_l_15b7;
	case 5562ULL: goto x86_l_15ba;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5585ULL: goto x86_l_15d1;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5621ULL: goto x86_l_15f5;
	case 5627ULL: goto x86_l_15fb;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5792ULL: goto x86_l_16a0;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5833ULL: goto x86_l_16c9;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5866ULL: goto x86_l_16ea;
	case 5870ULL: goto x86_l_16ee;
	case 5872ULL: goto x86_l_16f0;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5902ULL: goto x86_l_170e;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5920ULL: goto x86_l_1720;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5957ULL: goto x86_l_1745;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6006ULL: goto x86_l_1776;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6127ULL: goto x86_l_17ef;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6143ULL: goto x86_l_17ff;
	case 6148ULL: goto x86_l_1804;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6209ULL: goto x86_l_1841;
	case 6211ULL: goto x86_l_1843;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6232ULL: goto x86_l_1858;
	case 6237ULL: goto x86_l_185d;
	case 6243ULL: goto x86_l_1863;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6253ULL: goto x86_l_186d;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6318ULL: goto x86_l_18ae;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6377ULL: goto x86_l_18e9;
	case 6380ULL: goto x86_l_18ec;
	case 6388ULL: goto x86_l_18f4;
	case 6394ULL: goto x86_l_18fa;
	case 6400ULL: goto x86_l_1900;
	case 6409ULL: goto x86_l_1909;
	case 6417ULL: goto x86_l_1911;
	case 6425ULL: goto x86_l_1919;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6446ULL: goto x86_l_192e;
	case 6450ULL: goto x86_l_1932;
	case 6457ULL: goto x86_l_1939;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6467ULL: goto x86_l_1943;
	case 6469ULL: goto x86_l_1945;
	case 6471ULL: goto x86_l_1947;
	case 6479ULL: goto x86_l_194f;
	case 6486ULL: goto x86_l_1956;
	case 6488ULL: goto x86_l_1958;
	case 6496ULL: goto x86_l_1960;
	case 6504ULL: goto x86_l_1968;
	case 6507ULL: goto x86_l_196b;
	case 6515ULL: goto x86_l_1973;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6526ULL: goto x86_l_197e;
	case 6534ULL: goto x86_l_1986;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6548ULL: goto x86_l_1994;
	case 6557ULL: goto x86_l_199d;
	case 6565ULL: goto x86_l_19a5;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6597ULL: goto x86_l_19c5;
	case 6601ULL: goto x86_l_19c9;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6626ULL: goto x86_l_19e2;
	case 6634ULL: goto x86_l_19ea;
	case 6641ULL: goto x86_l_19f1;
	case 6647ULL: goto x86_l_19f7;
	case 6655ULL: goto x86_l_19ff;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6674ULL: goto x86_l_1a12;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6716ULL: goto x86_l_1a3c;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6738ULL: goto x86_l_1a52;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6854ULL: goto x86_l_1ac6;
	case 6860ULL: goto x86_l_1acc;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6885ULL: goto x86_l_1ae5;
	case 6887ULL: goto x86_l_1ae7;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6902ULL: goto x86_l_1af6;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6929ULL: goto x86_l_1b11;
	case 6932ULL: goto x86_l_1b14;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6946ULL: goto x86_l_1b22;
	case 6952ULL: goto x86_l_1b28;
	case 6958ULL: goto x86_l_1b2e;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6985ULL: goto x86_l_1b49;
	case 6988ULL: goto x86_l_1b4c;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7009ULL: goto x86_l_1b61;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7035ULL: goto x86_l_1b7b;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14fb:
	/* 0x14fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1500:
	/* 0x1500: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1503:
	/* 0x1503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1505:
	/* 0x1505: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_150a:
	/* 0x150a: lea    rax,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_150e:
	/* 0x150e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1513:
	/* 0x1513: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1518:
	/* 0x1518: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_151d:
	/* 0x151d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1522:
	/* 0x1522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1527:
	/* 0x1527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1529:
	/* 0x1529: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_152e:
	/* 0x152e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1533:
	/* 0x1533: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1538:
	/* 0x1538: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_153b:
	/* 0x153b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_153e:
	/* 0x153e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1540:
	/* 0x1540: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1545:
	/* 0x1545: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_154a:
	/* 0x154a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_154e:
	/* 0x154e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1553:
	/* 0x1553: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1558:
	/* 0x1558: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_155d:
	/* 0x155d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155f:
	/* 0x155f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1564:
	/* 0x1564: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1567:
	/* 0x1567: je     1617 <trace_set_fs_pwd+0x1617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1617;
	}
x86_l_156d:
	/* 0x156d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1572:
	/* 0x1572: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1575:
	/* 0x1575: je     1617 <trace_set_fs_pwd+0x1617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1617;
	}
x86_l_157b:
	/* 0x157b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_157f:
	/* 0x157f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1584:
	/* 0x1584: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1589:
	/* 0x1589: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_158e:
	/* 0x158e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1590:
	/* 0x1590: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1594:
	/* 0x1594: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1599:
	/* 0x1599: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_159b:
	/* 0x159b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15a1:
	/* 0x15a1: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_15a3:
	/* 0x15a3: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15a5:
	/* 0x15a5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_15ab:
	/* 0x15ab: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_15b0:
	/* 0x15b0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_15b5:
	/* 0x15b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b7:
	/* 0x15b7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15ba:
	/* 0x15ba: jl     18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18b4;
	}
x86_l_15c0:
	/* 0x15c0: mov    QWORD PTR [rsp+0x78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15c5:
	/* 0x15c5: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15ca:
	/* 0x15ca: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_15d1:
	/* 0x15d1: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_15d6:
	/* 0x15d6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15d8:
	/* 0x15d8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15dd:
	/* 0x15dd: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15e2:
	/* 0x15e2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15e5:
	/* 0x15e5: jmp    168e <trace_set_fs_pwd+0x168e> */
	goto x86_l_168e;
x86_l_15ea:
	/* 0x15ea: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ed:
	/* 0x15ed: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15f5:
	/* 0x15f5: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_15fb:
	/* 0x15fb: jbe    1900 <trace_set_fs_pwd+0x1900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1900;
	}
x86_l_1601:
	/* 0x1601: jmp    1c9a <trace_set_fs_pwd+0x1c9a> */
	return 7322ULL;
x86_l_1606:
	/* 0x1606: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_160b:
	/* 0x160b: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1612:
	/* 0x1612: jmp    18dd <trace_set_fs_pwd+0x18dd> */
	goto x86_l_18dd;
x86_l_1617:
	/* 0x1617: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_161a:
	/* 0x161a: jne    18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18b4;
	}
x86_l_1620:
	/* 0x1620: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1625:
	/* 0x1625: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_162a:
	/* 0x162a: je     18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b4;
	}
x86_l_1630:
	/* 0x1630: mov    QWORD PTR [rsp+0x78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1635:
	/* 0x1635: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_163a:
	/* 0x163a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_163f:
	/* 0x163f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1643:
	/* 0x1643: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1648:
	/* 0x1648: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_164d:
	/* 0x164d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164f:
	/* 0x164f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1654:
	/* 0x1654: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1659:
	/* 0x1659: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165e:
	/* 0x165e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1663:
	/* 0x1663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1665:
	/* 0x1665: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_166a:
	/* 0x166a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_166f:
	/* 0x166f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1674:
	/* 0x1674: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1679:
	/* 0x1679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167b:
	/* 0x167b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1680:
	/* 0x1680: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1684:
	/* 0x1684: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1689:
	/* 0x1689: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_168e:
	/* 0x168e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1693:
	/* 0x1693: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1698:
	/* 0x1698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_169d:
	/* 0x169d: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_16a0:
	/* 0x16a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a2:
	/* 0x16a2: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a7:
	/* 0x16a7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16ac:
	/* 0x16ac: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16b0:
	/* 0x16b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16b5:
	/* 0x16b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16ba:
	/* 0x16ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16bf:
	/* 0x16bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c1:
	/* 0x16c1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16c6:
	/* 0x16c6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16c9:
	/* 0x16c9: je     170b <trace_set_fs_pwd+0x170b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170b;
	}
x86_l_16cb:
	/* 0x16cb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16d0:
	/* 0x16d0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16d3:
	/* 0x16d3: je     170b <trace_set_fs_pwd+0x170b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170b;
	}
x86_l_16d5:
	/* 0x16d5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16d9:
	/* 0x16d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16de:
	/* 0x16de: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e3:
	/* 0x16e3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_16e8:
	/* 0x16e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ea:
	/* 0x16ea: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_16ee:
	/* 0x16ee: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_16f0:
	/* 0x16f0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16f6:
	/* 0x16f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fb:
	/* 0x16fb: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_16fd:
	/* 0x16fd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16ff:
	/* 0x16ff: jae    172b <trace_set_fs_pwd+0x172b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_172b;
	}
x86_l_1701:
	/* 0x1701: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1706:
	/* 0x1706: jmp    1c62 <trace_set_fs_pwd+0x1c62> */
	return 7266ULL;
x86_l_170b:
	/* 0x170b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_170e:
	/* 0x170e: je     1778 <trace_set_fs_pwd+0x1778> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1778;
	}
x86_l_1710:
	/* 0x1710: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1715:
	/* 0x1715: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171a:
	/* 0x171a: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_1720:
	/* 0x1720: je     18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b4;
	}
x86_l_1726:
	/* 0x1726: jmp    1c62 <trace_set_fs_pwd+0x1c62> */
	return 7266ULL;
x86_l_172b:
	/* 0x172b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1730:
	/* 0x1730: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1736:
	/* 0x1736: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173b:
	/* 0x173b: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_173e:
	/* 0x173e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1743:
	/* 0x1743: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1745:
	/* 0x1745: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1748:
	/* 0x1748: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_174d:
	/* 0x174d: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18a3;
	}
x86_l_1753:
	/* 0x1753: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1758:
	/* 0x1758: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_175b:
	/* 0x175b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1761:
	/* 0x1761: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1767:
	/* 0x1767: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1769:
	/* 0x1769: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176e:
	/* 0x176e: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1773:
	/* 0x1773: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1776:
	/* 0x1776: jmp    17dd <trace_set_fs_pwd+0x17dd> */
	goto x86_l_17dd;
x86_l_1778:
	/* 0x1778: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_177d:
	/* 0x177d: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1782:
	/* 0x1782: je     1710 <trace_set_fs_pwd+0x1710> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1710;
	}
x86_l_1784:
	/* 0x1784: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178e:
	/* 0x178e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1792:
	/* 0x1792: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1797:
	/* 0x1797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179c:
	/* 0x179c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179e:
	/* 0x179e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17a3:
	/* 0x17a3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a8:
	/* 0x17a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ad:
	/* 0x17ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b2:
	/* 0x17b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b4:
	/* 0x17b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17b9:
	/* 0x17b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17be:
	/* 0x17be: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17c3:
	/* 0x17c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c8:
	/* 0x17c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ca:
	/* 0x17ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cf:
	/* 0x17cf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17d3:
	/* 0x17d3: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17d8:
	/* 0x17d8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17dd:
	/* 0x17dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17e2:
	/* 0x17e2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17e7:
	/* 0x17e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ec:
	/* 0x17ec: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_17ef:
	/* 0x17ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f1:
	/* 0x17f1: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17f6:
	/* 0x17f6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17fb:
	/* 0x17fb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17ff:
	/* 0x17ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1804:
	/* 0x1804: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1809:
	/* 0x1809: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_180e:
	/* 0x180e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1810:
	/* 0x1810: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1815:
	/* 0x1815: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1818:
	/* 0x1818: je     189a <trace_set_fs_pwd+0x189a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189a;
	}
x86_l_181e:
	/* 0x181e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1823:
	/* 0x1823: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1826:
	/* 0x1826: je     189a <trace_set_fs_pwd+0x189a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189a;
	}
x86_l_1828:
	/* 0x1828: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_182c:
	/* 0x182c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1831:
	/* 0x1831: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1836:
	/* 0x1836: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_183b:
	/* 0x183b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183d:
	/* 0x183d: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1841:
	/* 0x1841: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1843:
	/* 0x1843: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1849:
	/* 0x1849: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184e:
	/* 0x184e: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1850:
	/* 0x1850: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1852:
	/* 0x1852: jb     1c62 <trace_set_fs_pwd+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7266ULL;
	}
x86_l_1858:
	/* 0x1858: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_185d:
	/* 0x185d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1863:
	/* 0x1863: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1866:
	/* 0x1866: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_186b:
	/* 0x186b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186d:
	/* 0x186d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1870:
	/* 0x1870: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18a3;
	}
x86_l_1872:
	/* 0x1872: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1877:
	/* 0x1877: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_187a:
	/* 0x187a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1880:
	/* 0x1880: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1886:
	/* 0x1886: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1888:
	/* 0x1888: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_188d:
	/* 0x188d: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1892:
	/* 0x1892: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1895:
	/* 0x1895: jmp    1a7d <trace_set_fs_pwd+0x1a7d> */
	goto x86_l_1a7d;
x86_l_189a:
	/* 0x189a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_189d:
	/* 0x189d: je     1a1e <trace_set_fs_pwd+0x1a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a1e;
	}
x86_l_18a3:
	/* 0x18a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a8:
	/* 0x18a8: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_18ae:
	/* 0x18ae: jne    1c62 <trace_set_fs_pwd+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7266ULL;
	}
x86_l_18b4:
	/* 0x18b4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b9:
	/* 0x18b9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18bd:
	/* 0x18bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18c2:
	/* 0x18c2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18c7:
	/* 0x18c7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_18cc:
	/* 0x18cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ce:
	/* 0x18ce: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18d3:
	/* 0x18d3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_18d8:
	/* 0x18d8: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18dd:
	/* 0x18dd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_18e0:
	/* 0x18e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18e5:
	/* 0x18e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e7:
	/* 0x18e7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e9:
	/* 0x18e9: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18ec:
	/* 0x18ec: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18f4:
	/* 0x18f4: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_18fa:
	/* 0x18fa: ja     1c9a <trace_set_fs_pwd+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7322ULL;
	}
x86_l_1900:
	/* 0x1900: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1909:
	/* 0x1909: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1911:
	/* 0x1911: mov    WORD PTR [r14+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1919:
	/* 0x1919: cmp    ecx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27899ULL);
x86_l_191f:
	/* 0x191f: ja     1986 <trace_set_fs_pwd+0x1986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1986;
	}
x86_l_1921:
	/* 0x1921: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1926:
	/* 0x1926: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_192e:
	/* 0x192e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1932:
	/* 0x1932: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1939:
	/* 0x1939: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_193e:
	/* 0x193e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1941:
	/* 0x1941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1943:
	/* 0x1943: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1945:
	/* 0x1945: jle    197e <trace_set_fs_pwd+0x197e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_197e;
	}
x86_l_1947:
	/* 0x1947: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_194f:
	/* 0x194f: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1956:
	/* 0x1956: ja     1986 <trace_set_fs_pwd+0x1986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1986;
	}
x86_l_1958:
	/* 0x1958: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1960:
	/* 0x1960: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1968:
	/* 0x1968: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_196b:
	/* 0x196b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1973:
	/* 0x1973: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_197a:
	/* 0x197a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_197c:
	/* 0x197c: jmp    1986 <trace_set_fs_pwd+0x1986> */
	goto x86_l_1986;
x86_l_197e:
	/* 0x197e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1986:
	/* 0x1986: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1989:
	/* 0x1989: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_198e:
	/* 0x198e: ja     1c9a <trace_set_fs_pwd+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7322ULL;
	}
x86_l_1994:
	/* 0x1994: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_199d:
	/* 0x199d: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19a5:
	/* 0x19a5: mov    WORD PTR [r14+0x7d8e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_19ad:
	/* 0x19ad: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_19b2:
	/* 0x19b2: ja     1c9a <trace_set_fs_pwd+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7322ULL;
	}
x86_l_19b8:
	/* 0x19b8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19bd:
	/* 0x19bd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19c5:
	/* 0x19c5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19c9:
	/* 0x19c9: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_19d0:
	/* 0x19d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19d5:
	/* 0x19d5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19d8:
	/* 0x19d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19da:
	/* 0x19da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19dc:
	/* 0x19dc: jle    1c9a <trace_set_fs_pwd+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7322ULL;
	}
x86_l_19e2:
	/* 0x19e2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19ea:
	/* 0x19ea: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_19f1:
	/* 0x19f1: ja     1c9a <trace_set_fs_pwd+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7322ULL;
	}
x86_l_19f7:
	/* 0x19f7: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_19ff:
	/* 0x19ff: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a07:
	/* 0x1a07: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1a0a:
	/* 0x1a0a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a12:
	/* 0x1a12: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a19:
	/* 0x1a19: jmp    1c9a <trace_set_fs_pwd+0x1c9a> */
	return 7322ULL;
x86_l_1a1e:
	/* 0x1a1e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a23:
	/* 0x1a23: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1a28:
	/* 0x1a28: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a3;
	}
x86_l_1a2e:
	/* 0x1a2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a33:
	/* 0x1a33: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a38:
	/* 0x1a38: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a3c:
	/* 0x1a3c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a41:
	/* 0x1a41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a46:
	/* 0x1a46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a48:
	/* 0x1a48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a52:
	/* 0x1a52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a57:
	/* 0x1a57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a5c:
	/* 0x1a5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a63:
	/* 0x1a63: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a68:
	/* 0x1a68: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a72:
	/* 0x1a72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a74:
	/* 0x1a74: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a79:
	/* 0x1a79: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a82:
	/* 0x1a82: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a87:
	/* 0x1a87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1a8f:
	/* 0x1a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a91:
	/* 0x1a91: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a96:
	/* 0x1a96: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9b:
	/* 0x1a9b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa4:
	/* 0x1aa4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aae:
	/* 0x1aae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab0:
	/* 0x1ab0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ab5:
	/* 0x1ab5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ab8:
	/* 0x1ab8: je     1b78 <trace_set_fs_pwd+0x1b78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b78;
	}
x86_l_1abe:
	/* 0x1abe: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac3:
	/* 0x1ac3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ac6:
	/* 0x1ac6: je     1b78 <trace_set_fs_pwd+0x1b78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b78;
	}
x86_l_1acc:
	/* 0x1acc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad5:
	/* 0x1ad5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ada:
	/* 0x1ada: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1adf:
	/* 0x1adf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ae5:
	/* 0x1ae5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ae7:
	/* 0x1ae7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aed:
	/* 0x1aed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af2:
	/* 0x1af2: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1af4:
	/* 0x1af4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1af6:
	/* 0x1af6: jb     1c62 <trace_set_fs_pwd+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7266ULL;
	}
x86_l_1afc:
	/* 0x1afc: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b01:
	/* 0x1b01: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1b07:
	/* 0x1b07: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b0a:
	/* 0x1b0a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b0f:
	/* 0x1b0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b11:
	/* 0x1b11: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b14:
	/* 0x1b14: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18a3;
	}
x86_l_1b1a:
	/* 0x1b1a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1f:
	/* 0x1b1f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1b22:
	/* 0x1b22: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1b28:
	/* 0x1b28: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1b2e:
	/* 0x1b2e: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b30:
	/* 0x1b30: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b35:
	/* 0x1b35: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b3d:
	/* 0x1b3d: jmp    1be0 <trace_set_fs_pwd+0x1be0> */
	return 7136ULL;
x86_l_1b42:
	/* 0x1b42: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1b49:
	/* 0x1b49: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b4c:
	/* 0x1b4c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b50:
	/* 0x1b50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b55:
	/* 0x1b55: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1b5a:
	/* 0x1b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5c:
	/* 0x1b5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5f:
	/* 0x1b5f: jne    1b71 <trace_set_fs_pwd+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b71;
	}
x86_l_1b61:
	/* 0x1b61: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_1b67:
	/* 0x1b67: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_1b6c:
	/* 0x1b6c: jmp    aec <trace_set_fs_pwd+0xaec> */
	return 2796ULL;
x86_l_1b71:
	/* 0x1b71: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b73:
	/* 0x1b73: jmp    20fb <trace_set_fs_pwd+0x20fb> */
	return 8443ULL;
x86_l_1b78:
	/* 0x1b78: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b7b:
	/* 0x1b7b: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18a3;
	}
x86_l_1b81:
	/* 0x1b81: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b86:
	/* 0x1b86: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1b8b:
	/* 0x1b8b: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a3;
	}
x86_l_1b91:
	/* 0x1b91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b96:
	/* 0x1b96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b9b:
	/* 0x1b9b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b9f:
	/* 0x1b9f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba9:
	/* 0x1ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bab:
	/* 0x1bab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb5:
	/* 0x1bb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bba:
	/* 0x1bba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 7103ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7103ULL: goto x86_l_1bbf;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7154ULL: goto x86_l_1bf2;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7195ULL: goto x86_l_1c1b;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7219ULL: goto x86_l_1c33;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7234ULL: goto x86_l_1c42;
	case 7236ULL: goto x86_l_1c44;
	case 7240ULL: goto x86_l_1c48;
	case 7242ULL: goto x86_l_1c4a;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7268ULL: goto x86_l_1c64;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7293ULL: goto x86_l_1c7d;
	case 7299ULL: goto x86_l_1c83;
	case 7302ULL: goto x86_l_1c86;
	case 7310ULL: goto x86_l_1c8e;
	case 7316ULL: goto x86_l_1c94;
	case 7322ULL: goto x86_l_1c9a;
	case 7329ULL: goto x86_l_1ca1;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7466ULL: goto x86_l_1d2a;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7491ULL: goto x86_l_1d43;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7501ULL: goto x86_l_1d4d;
	case 7505ULL: goto x86_l_1d51;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7549ULL: goto x86_l_1d7d;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7617ULL: goto x86_l_1dc1;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7642ULL: goto x86_l_1dda;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7703ULL: goto x86_l_1e17;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7804ULL: goto x86_l_1e7c;
	case 7808ULL: goto x86_l_1e80;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7927ULL: goto x86_l_1ef7;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7956ULL: goto x86_l_1f14;
	case 7960ULL: goto x86_l_1f18;
	case 7964ULL: goto x86_l_1f1c;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7989ULL: goto x86_l_1f35;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8054ULL: goto x86_l_1f76;
	case 8058ULL: goto x86_l_1f7a;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8174ULL: goto x86_l_1fee;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8192ULL: goto x86_l_2000;
	case 8200ULL: goto x86_l_2008;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8238ULL: goto x86_l_202e;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8290ULL: goto x86_l_2062;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8307ULL: goto x86_l_2073;
	case 8309ULL: goto x86_l_2075;
	case 8314ULL: goto x86_l_207a;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8340ULL: goto x86_l_2094;
	case 8344ULL: goto x86_l_2098;
	case 8352ULL: goto x86_l_20a0;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8380ULL: goto x86_l_20bc;
	case 8384ULL: goto x86_l_20c0;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8438ULL: goto x86_l_20f6;
	case 8440ULL: goto x86_l_20f8;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8533ULL: goto x86_l_2155;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8564ULL: goto x86_l_2174;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8589ULL: goto x86_l_218d;
	case 8592ULL: goto x86_l_2190;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8621ULL: goto x86_l_21ad;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8684ULL: goto x86_l_21ec;
	case 8689ULL: goto x86_l_21f1;
	case 8692ULL: goto x86_l_21f4;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8706ULL: goto x86_l_2202;
	case 8708ULL: goto x86_l_2204;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8729ULL: goto x86_l_2219;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bbf:
	/* 0x1bbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc1:
	/* 0x1bc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bcb:
	/* 0x1bcb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd5:
	/* 0x1bd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd7:
	/* 0x1bd7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdc:
	/* 0x1bdc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1be0:
	/* 0x1be0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be5:
	/* 0x1be5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bea:
	/* 0x1bea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bef:
	/* 0x1bef: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1bf2:
	/* 0x1bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf4:
	/* 0x1bf4: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bf9:
	/* 0x1bf9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bfe:
	/* 0x1bfe: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c02:
	/* 0x1c02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c07:
	/* 0x1c07: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0c:
	/* 0x1c0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c11:
	/* 0x1c11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c13:
	/* 0x1c13: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c18:
	/* 0x1c18: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c1b:
	/* 0x1c1b: je     210c <trace_set_fs_pwd+0x210c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210c;
	}
x86_l_1c21:
	/* 0x1c21: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c26:
	/* 0x1c26: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c29:
	/* 0x1c29: je     210c <trace_set_fs_pwd+0x210c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210c;
	}
x86_l_1c2f:
	/* 0x1c2f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c33:
	/* 0x1c33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c38:
	/* 0x1c38: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c42:
	/* 0x1c42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c44:
	/* 0x1c44: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c48:
	/* 0x1c48: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c4a:
	/* 0x1c4a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c50:
	/* 0x1c50: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c55:
	/* 0x1c55: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c57:
	/* 0x1c57: jae    2176 <trace_set_fs_pwd+0x2176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2176;
	}
x86_l_1c5d:
	/* 0x1c5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c62:
	/* 0x1c62: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1c64:
	/* 0x1c64: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1c66:
	/* 0x1c66: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c70:
	/* 0x1c70: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1c75:
	/* 0x1c75: mov    BYTE PTR [r15+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1c7d:
	/* 0x1c7d: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1c83:
	/* 0x1c83: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c86:
	/* 0x1c86: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c8e:
	/* 0x1c8e: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1c94:
	/* 0x1c94: jbe    1900 <trace_set_fs_pwd+0x1900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6400ULL;
	}
x86_l_1c9a:
	/* 0x1c9a: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1ca1:
	/* 0x1ca1: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca5:
	/* 0x1ca5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1caa:
	/* 0x1caa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1caf:
	/* 0x1caf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1cb7:
	/* 0x1cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb9:
	/* 0x1cb9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cc3:
	/* 0x1cc3: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ccc:
	/* 0x1ccc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd6:
	/* 0x1cd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd8:
	/* 0x1cd8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cdd:
	/* 0x1cdd: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ce6:
	/* 0x1ce6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf0:
	/* 0x1cf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf2:
	/* 0x1cf2: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cf7:
	/* 0x1cf7: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1cfb:
	/* 0x1cfb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d00:
	/* 0x1d00: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d05:
	/* 0x1d05: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d0a:
	/* 0x1d0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0c:
	/* 0x1d0c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d10:
	/* 0x1d10: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d14:
	/* 0x1d14: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d18:
	/* 0x1d18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d1d:
	/* 0x1d1d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d22:
	/* 0x1d22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d27:
	/* 0x1d27: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d2a:
	/* 0x1d2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2c:
	/* 0x1d2c: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d36:
	/* 0x1d36: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d40:
	/* 0x1d40: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d43:
	/* 0x1d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d45:
	/* 0x1d45: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d49:
	/* 0x1d49: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1d4d:
	/* 0x1d4d: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1d51:
	/* 0x1d51: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d55:
	/* 0x1d55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d5a:
	/* 0x1d5a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d64:
	/* 0x1d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d66:
	/* 0x1d66: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d73:
	/* 0x1d73: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d78:
	/* 0x1d78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d7d:
	/* 0x1d7d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d80:
	/* 0x1d80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d82:
	/* 0x1d82: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d87:
	/* 0x1d87: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d90:
	/* 0x1d90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d95:
	/* 0x1d95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d9a:
	/* 0x1d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9c:
	/* 0x1d9c: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1da1:
	/* 0x1da1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1da6:
	/* 0x1da6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dab:
	/* 0x1dab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1db0:
	/* 0x1db0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1db3:
	/* 0x1db3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db5:
	/* 0x1db5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1db9:
	/* 0x1db9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1dbd:
	/* 0x1dbd: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1dc1:
	/* 0x1dc1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dca:
	/* 0x1dca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dd4:
	/* 0x1dd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd6:
	/* 0x1dd6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dda:
	/* 0x1dda: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dde:
	/* 0x1dde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1de3:
	/* 0x1de3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1de8:
	/* 0x1de8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ded:
	/* 0x1ded: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1df0:
	/* 0x1df0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df2:
	/* 0x1df2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df7:
	/* 0x1df7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dfc:
	/* 0x1dfc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e01:
	/* 0x1e01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e06:
	/* 0x1e06: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e09:
	/* 0x1e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0b:
	/* 0x1e0b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e0f:
	/* 0x1e0f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e13:
	/* 0x1e13: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e17:
	/* 0x1e17: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e1b:
	/* 0x1e1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e20:
	/* 0x1e20: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e25:
	/* 0x1e25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e2a:
	/* 0x1e2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2c:
	/* 0x1e2c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e31:
	/* 0x1e31: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1e35:
	/* 0x1e35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e3a:
	/* 0x1e3a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e44:
	/* 0x1e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e46:
	/* 0x1e46: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e4b:
	/* 0x1e4b: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e54:
	/* 0x1e54: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e59:
	/* 0x1e59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e5e:
	/* 0x1e5e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e61:
	/* 0x1e61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e63:
	/* 0x1e63: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e68:
	/* 0x1e68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e6d:
	/* 0x1e6d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e72:
	/* 0x1e72: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e77:
	/* 0x1e77: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e7a:
	/* 0x1e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7c:
	/* 0x1e7c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e80:
	/* 0x1e80: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e84:
	/* 0x1e84: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e88:
	/* 0x1e88: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e91:
	/* 0x1e91: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e96:
	/* 0x1e96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e9b:
	/* 0x1e9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9d:
	/* 0x1e9d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ea2:
	/* 0x1ea2: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eab:
	/* 0x1eab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eb5:
	/* 0x1eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb7:
	/* 0x1eb7: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_1ebc:
	/* 0x1ebc: jne    1f14 <trace_set_fs_pwd+0x1f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f14;
	}
x86_l_1ebe:
	/* 0x1ebe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ec3:
	/* 0x1ec3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ed0:
	/* 0x1ed0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed2:
	/* 0x1ed2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ed7:
	/* 0x1ed7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1edc:
	/* 0x1edc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ee6:
	/* 0x1ee6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ee9:
	/* 0x1ee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eeb:
	/* 0x1eeb: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eef:
	/* 0x1eef: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1ef3:
	/* 0x1ef3: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ef7:
	/* 0x1ef7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1efb:
	/* 0x1efb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f00:
	/* 0x1f00: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f05:
	/* 0x1f05: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f0a:
	/* 0x1f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0c:
	/* 0x1f0c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f10:
	/* 0x1f10: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f14:
	/* 0x1f14: lea    r12,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f18:
	/* 0x1f18: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f1c:
	/* 0x1f1c: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f23:
	/* 0x1f23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f28:
	/* 0x1f28: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f32:
	/* 0x1f32: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f35:
	/* 0x1f35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f37:
	/* 0x1f37: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f3c:
	/* 0x1f3c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f40:
	/* 0x1f40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f45:
	/* 0x1f45: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f4f:
	/* 0x1f4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f51:
	/* 0x1f51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f56:
	/* 0x1f56: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f5b:
	/* 0x1f5b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f60:
	/* 0x1f60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f65:
	/* 0x1f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f67:
	/* 0x1f67: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f6b:
	/* 0x1f6b: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1f74:
	/* 0x1f74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f76:
	/* 0x1f76: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f7a:
	/* 0x1f7a: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f83:
	/* 0x1f83: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f88:
	/* 0x1f88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f8d:
	/* 0x1f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8f:
	/* 0x1f8f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f94:
	/* 0x1f94: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f98:
	/* 0x1f98: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f9d:
	/* 0x1f9d: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa6:
	/* 0x1fa6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fab:
	/* 0x1fab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb0:
	/* 0x1fb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb2:
	/* 0x1fb2: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb7:
	/* 0x1fb7: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fbb:
	/* 0x1fbb: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fc4:
	/* 0x1fc4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fce:
	/* 0x1fce: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1fd1:
	/* 0x1fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd3:
	/* 0x1fd3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fe1:
	/* 0x1fe1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1feb:
	/* 0x1feb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1fee:
	/* 0x1fee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff0:
	/* 0x1ff0: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1ff5:
	/* 0x1ff5: je     1ffc <trace_set_fs_pwd+0x1ffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ffc;
	}
x86_l_1ff7:
	/* 0x1ff7: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1ffc:
	/* 0x1ffc: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2000:
	/* 0x2000: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2008:
	/* 0x2008: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2010:
	/* 0x2010: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2015:
	/* 0x2015: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_201a:
	/* 0x201a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201c:
	/* 0x201c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2021:
	/* 0x2021: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2026:
	/* 0x2026: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_202b:
	/* 0x202b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_202e:
	/* 0x202e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2030:
	/* 0x2030: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2035:
	/* 0x2035: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_203a:
	/* 0x203a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_203f:
	/* 0x203f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2044:
	/* 0x2044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2046:
	/* 0x2046: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_204b:
	/* 0x204b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2050:
	/* 0x2050: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2055:
	/* 0x2055: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2058:
	/* 0x2058: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_205d:
	/* 0x205d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205f:
	/* 0x205f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2062:
	/* 0x2062: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2066:
	/* 0x2066: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_206b:
	/* 0x206b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2070:
	/* 0x2070: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2073:
	/* 0x2073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2075:
	/* 0x2075: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_207a:
	/* 0x207a: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2082:
	/* 0x2082: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2087:
	/* 0x2087: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_208a:
	/* 0x208a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208c:
	/* 0x208c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2094:
	/* 0x2094: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2098:
	/* 0x2098: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_20a0:
	/* 0x20a0: je     20c0 <trace_set_fs_pwd+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c0;
	}
x86_l_20a2:
	/* 0x20a2: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_20a7:
	/* 0x20a7: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_20ae:
	/* 0x20ae: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_20b3:
	/* 0x20b3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20b6:
	/* 0x20b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b8:
	/* 0x20b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ba:
	/* 0x20ba: js     20c0 <trace_set_fs_pwd+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20c0;
	}
x86_l_20bc:
	/* 0x20bc: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_20c0:
	/* 0x20c0: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20c8:
	/* 0x20c8: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_20cd:
	/* 0x20cd: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_20d2:
	/* 0x20d2: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_20d5:
	/* 0x20d5: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_20db:
	/* 0x20db: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20df:
	/* 0x20df: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_20e4:
	/* 0x20e4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_20eb:
	/* 0x20eb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_20f0:
	/* 0x20f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20f3:
	/* 0x20f3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_20f6:
	/* 0x20f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f8:
	/* 0x20f8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_20fb:
	/* 0x20fb: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_20fd:
	/* 0x20fd: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_2104:
	/* 0x2104: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2106:
	/* 0x2106: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2107:
	/* 0x2107: jmp    330e <trace_set_fs_pwd+0x330e> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_210c:
	/* 0x210c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_210f:
	/* 0x210f: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2115:
	/* 0x2115: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_211a:
	/* 0x211a: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_211f:
	/* 0x211f: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2125:
	/* 0x2125: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_212a:
	/* 0x212a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_212f:
	/* 0x212f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2133:
	/* 0x2133: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2138:
	/* 0x2138: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_213d:
	/* 0x213d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213f:
	/* 0x213f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2144:
	/* 0x2144: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2149:
	/* 0x2149: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_214e:
	/* 0x214e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2153:
	/* 0x2153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2155:
	/* 0x2155: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215a:
	/* 0x215a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_215f:
	/* 0x215f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2164:
	/* 0x2164: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2169:
	/* 0x2169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216b:
	/* 0x216b: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2170:
	/* 0x2170: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2174:
	/* 0x2174: jmp    21b9 <trace_set_fs_pwd+0x21b9> */
	goto x86_l_21b9;
x86_l_2176:
	/* 0x2176: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_217b:
	/* 0x217b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2181:
	/* 0x2181: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2186:
	/* 0x2186: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_218b:
	/* 0x218b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218d:
	/* 0x218d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2190:
	/* 0x2190: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2196:
	/* 0x2196: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_219b:
	/* 0x219b: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_219e:
	/* 0x219e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_21a4:
	/* 0x21a4: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a9:
	/* 0x21a9: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_21ad:
	/* 0x21ad: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21af:
	/* 0x21af: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b4:
	/* 0x21b4: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21b9:
	/* 0x21b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21be:
	/* 0x21be: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21c3:
	/* 0x21c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21c8:
	/* 0x21c8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_21cb:
	/* 0x21cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cd:
	/* 0x21cd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21d2:
	/* 0x21d2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d7:
	/* 0x21d7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21db:
	/* 0x21db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21e0:
	/* 0x21e0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e5:
	/* 0x21e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21ea:
	/* 0x21ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ec:
	/* 0x21ec: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21f1:
	/* 0x21f1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21f4:
	/* 0x21f4: je     2277 <trace_set_fs_pwd+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8823ULL;
	}
x86_l_21fa:
	/* 0x21fa: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ff:
	/* 0x21ff: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2202:
	/* 0x2202: je     2277 <trace_set_fs_pwd+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8823ULL;
	}
x86_l_2204:
	/* 0x2204: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2208:
	/* 0x2208: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_220d:
	/* 0x220d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2212:
	/* 0x2212: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2217:
	/* 0x2217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2219:
	/* 0x2219: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_221d:
	/* 0x221d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_221f:
	/* 0x221f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 8741ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8741ULL: goto x86_l_2225;
	case 8746ULL: goto x86_l_222a;
	case 8748ULL: goto x86_l_222c;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8777ULL: goto x86_l_2249;
	case 8780ULL: goto x86_l_224c;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8809ULL: goto x86_l_2269;
	case 8811ULL: goto x86_l_226b;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8823ULL: goto x86_l_2277;
	case 8826ULL: goto x86_l_227a;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8896ULL: goto x86_l_22c0;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8983ULL: goto x86_l_2317;
	case 8986ULL: goto x86_l_231a;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9027ULL: goto x86_l_2343;
	case 9029ULL: goto x86_l_2345;
	case 9035ULL: goto x86_l_234b;
	case 9040ULL: goto x86_l_2350;
	case 9042ULL: goto x86_l_2352;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9059ULL: goto x86_l_2363;
	case 9064ULL: goto x86_l_2368;
	case 9069ULL: goto x86_l_236d;
	case 9071ULL: goto x86_l_236f;
	case 9074ULL: goto x86_l_2372;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9088ULL: goto x86_l_2380;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9210ULL: goto x86_l_23fa;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9241ULL: goto x86_l_2419;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9280ULL: goto x86_l_2440;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9329ULL: goto x86_l_2471;
	case 9334ULL: goto x86_l_2476;
	case 9336ULL: goto x86_l_2478;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9430ULL: goto x86_l_24d6;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9530ULL: goto x86_l_253a;
	case 9533ULL: goto x86_l_253d;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9549ULL: goto x86_l_254d;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9611ULL: goto x86_l_258b;
	case 9615ULL: goto x86_l_258f;
	case 9617ULL: goto x86_l_2591;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9630ULL: goto x86_l_259e;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9659ULL: goto x86_l_25bb;
	case 9662ULL: goto x86_l_25be;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9676ULL: goto x86_l_25cc;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9708ULL: goto x86_l_25ec;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9798ULL: goto x86_l_2646;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9809ULL: goto x86_l_2651;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9868ULL: goto x86_l_268c;
	case 9874ULL: goto x86_l_2692;
	case 9879ULL: goto x86_l_2697;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9905ULL: goto x86_l_26b1;
	case 9909ULL: goto x86_l_26b5;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9924ULL: goto x86_l_26c4;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9956ULL: goto x86_l_26e4;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9985ULL: goto x86_l_2701;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 9999ULL: goto x86_l_270f;
	case 10002ULL: goto x86_l_2712;
	case 10008ULL: goto x86_l_2718;
	case 10013ULL: goto x86_l_271d;
	case 10018ULL: goto x86_l_2722;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10065ULL: goto x86_l_2751;
	case 10070ULL: goto x86_l_2756;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10159ULL: goto x86_l_27af;
	case 10162ULL: goto x86_l_27b2;
	case 10168ULL: goto x86_l_27b8;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10199ULL: goto x86_l_27d7;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10247ULL: goto x86_l_2807;
	case 10250ULL: goto x86_l_280a;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10264ULL: goto x86_l_2818;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10279ULL: goto x86_l_2827;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10293ULL: goto x86_l_2835;
	case 10296ULL: goto x86_l_2838;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10388ULL: goto x86_l_2894;
	case 10393ULL: goto x86_l_2899;
	case 10397ULL: goto x86_l_289d;
	case 10402ULL: goto x86_l_28a2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2225:
	/* 0x2225: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222a:
	/* 0x222a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_222c:
	/* 0x222c: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2232:
	/* 0x2232: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2237:
	/* 0x2237: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_223d:
	/* 0x223d: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2242:
	/* 0x2242: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2247:
	/* 0x2247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2249:
	/* 0x2249: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_224c:
	/* 0x224c: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2252:
	/* 0x2252: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2257:
	/* 0x2257: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_225a:
	/* 0x225a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2260:
	/* 0x2260: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2265:
	/* 0x2265: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2269:
	/* 0x2269: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_226b:
	/* 0x226b: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2270:
	/* 0x2270: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2275:
	/* 0x2275: jmp    22df <trace_set_fs_pwd+0x22df> */
	goto x86_l_22df;
x86_l_2277:
	/* 0x2277: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_227a:
	/* 0x227a: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2280:
	/* 0x2280: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2285:
	/* 0x2285: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_228a:
	/* 0x228a: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2290:
	/* 0x2290: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2295:
	/* 0x2295: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229a:
	/* 0x229a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_229e:
	/* 0x229e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22a3:
	/* 0x22a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a8:
	/* 0x22a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22aa:
	/* 0x22aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22af:
	/* 0x22af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b4:
	/* 0x22b4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b9:
	/* 0x22b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22be:
	/* 0x22be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c0:
	/* 0x22c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c5:
	/* 0x22c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ca:
	/* 0x22ca: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22cf:
	/* 0x22cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d4:
	/* 0x22d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d6:
	/* 0x22d6: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22db:
	/* 0x22db: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22df:
	/* 0x22df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22e4:
	/* 0x22e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e9:
	/* 0x22e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ee:
	/* 0x22ee: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_22f1:
	/* 0x22f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f3:
	/* 0x22f3: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22f8:
	/* 0x22f8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22fd:
	/* 0x22fd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2301:
	/* 0x2301: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2306:
	/* 0x2306: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_230b:
	/* 0x230b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2310:
	/* 0x2310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2312:
	/* 0x2312: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2317:
	/* 0x2317: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_231a:
	/* 0x231a: je     239d <trace_set_fs_pwd+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239d;
	}
x86_l_2320:
	/* 0x2320: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2325:
	/* 0x2325: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2328:
	/* 0x2328: je     239d <trace_set_fs_pwd+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239d;
	}
x86_l_232a:
	/* 0x232a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_232e:
	/* 0x232e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2333:
	/* 0x2333: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2338:
	/* 0x2338: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_233d:
	/* 0x233d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233f:
	/* 0x233f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2343:
	/* 0x2343: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2345:
	/* 0x2345: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_234b:
	/* 0x234b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2350:
	/* 0x2350: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2352:
	/* 0x2352: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2358:
	/* 0x2358: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_235d:
	/* 0x235d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2363:
	/* 0x2363: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2368:
	/* 0x2368: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_236d:
	/* 0x236d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236f:
	/* 0x236f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2372:
	/* 0x2372: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2378:
	/* 0x2378: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237d:
	/* 0x237d: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2380:
	/* 0x2380: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2386:
	/* 0x2386: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_238b:
	/* 0x238b: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_238f:
	/* 0x238f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2391:
	/* 0x2391: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2396:
	/* 0x2396: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_239b:
	/* 0x239b: jmp    2405 <trace_set_fs_pwd+0x2405> */
	goto x86_l_2405;
x86_l_239d:
	/* 0x239d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23a0:
	/* 0x23a0: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_23a6:
	/* 0x23a6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ab:
	/* 0x23ab: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_23b0:
	/* 0x23b0: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_23b6:
	/* 0x23b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23bb:
	/* 0x23bb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23c0:
	/* 0x23c0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23c4:
	/* 0x23c4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c9:
	/* 0x23c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ce:
	/* 0x23ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d0:
	/* 0x23d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d5:
	/* 0x23d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23da:
	/* 0x23da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23df:
	/* 0x23df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23e4:
	/* 0x23e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e6:
	/* 0x23e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23eb:
	/* 0x23eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f0:
	/* 0x23f0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23f5:
	/* 0x23f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23fa:
	/* 0x23fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fc:
	/* 0x23fc: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2401:
	/* 0x2401: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2405:
	/* 0x2405: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_240a:
	/* 0x240a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_240f:
	/* 0x240f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2414:
	/* 0x2414: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2417:
	/* 0x2417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2419:
	/* 0x2419: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_241e:
	/* 0x241e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2423:
	/* 0x2423: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2427:
	/* 0x2427: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242c:
	/* 0x242c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2431:
	/* 0x2431: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2436:
	/* 0x2436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2438:
	/* 0x2438: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_243d:
	/* 0x243d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2440:
	/* 0x2440: je     24c3 <trace_set_fs_pwd+0x24c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c3;
	}
x86_l_2446:
	/* 0x2446: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_244b:
	/* 0x244b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_244e:
	/* 0x244e: je     24c3 <trace_set_fs_pwd+0x24c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c3;
	}
x86_l_2450:
	/* 0x2450: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2454:
	/* 0x2454: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2459:
	/* 0x2459: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_245e:
	/* 0x245e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2463:
	/* 0x2463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2465:
	/* 0x2465: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2469:
	/* 0x2469: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_246b:
	/* 0x246b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2471:
	/* 0x2471: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2476:
	/* 0x2476: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2478:
	/* 0x2478: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_247e:
	/* 0x247e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2483:
	/* 0x2483: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2489:
	/* 0x2489: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_248e:
	/* 0x248e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2493:
	/* 0x2493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2495:
	/* 0x2495: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2498:
	/* 0x2498: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_249e:
	/* 0x249e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a3:
	/* 0x24a3: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_24a6:
	/* 0x24a6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_24ac:
	/* 0x24ac: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24b1:
	/* 0x24b1: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_24b5:
	/* 0x24b5: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24b7:
	/* 0x24b7: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bc:
	/* 0x24bc: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24c1:
	/* 0x24c1: jmp    252b <trace_set_fs_pwd+0x252b> */
	goto x86_l_252b;
x86_l_24c3:
	/* 0x24c3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24c6:
	/* 0x24c6: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_24cc:
	/* 0x24cc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d1:
	/* 0x24d1: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_24d6:
	/* 0x24d6: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_24dc:
	/* 0x24dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24e1:
	/* 0x24e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e6:
	/* 0x24e6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24ea:
	/* 0x24ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24ef:
	/* 0x24ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f4:
	/* 0x24f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f6:
	/* 0x24f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24fb:
	/* 0x24fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2500:
	/* 0x2500: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2505:
	/* 0x2505: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_250a:
	/* 0x250a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250c:
	/* 0x250c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2511:
	/* 0x2511: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2516:
	/* 0x2516: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_251b:
	/* 0x251b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2520:
	/* 0x2520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2522:
	/* 0x2522: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2527:
	/* 0x2527: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_252b:
	/* 0x252b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2530:
	/* 0x2530: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2535:
	/* 0x2535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_253a:
	/* 0x253a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_253d:
	/* 0x253d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253f:
	/* 0x253f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2544:
	/* 0x2544: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2549:
	/* 0x2549: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_254d:
	/* 0x254d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2552:
	/* 0x2552: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2557:
	/* 0x2557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255c:
	/* 0x255c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255e:
	/* 0x255e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2563:
	/* 0x2563: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2566:
	/* 0x2566: je     25e9 <trace_set_fs_pwd+0x25e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e9;
	}
x86_l_256c:
	/* 0x256c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2571:
	/* 0x2571: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: je     25e9 <trace_set_fs_pwd+0x25e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e9;
	}
x86_l_2576:
	/* 0x2576: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_257a:
	/* 0x257a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_257f:
	/* 0x257f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2584:
	/* 0x2584: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2589:
	/* 0x2589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258b:
	/* 0x258b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_258f:
	/* 0x258f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2591:
	/* 0x2591: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2597:
	/* 0x2597: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259c:
	/* 0x259c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_259e:
	/* 0x259e: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_25a4:
	/* 0x25a4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25a9:
	/* 0x25a9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25af:
	/* 0x25af: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_25b4:
	/* 0x25b4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_25b9:
	/* 0x25b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bb:
	/* 0x25bb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25be:
	/* 0x25be: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_25c4:
	/* 0x25c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c9:
	/* 0x25c9: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_25cc:
	/* 0x25cc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_25d2:
	/* 0x25d2: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25d7:
	/* 0x25d7: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_25db:
	/* 0x25db: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25dd:
	/* 0x25dd: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e2:
	/* 0x25e2: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25e7:
	/* 0x25e7: jmp    2651 <trace_set_fs_pwd+0x2651> */
	goto x86_l_2651;
x86_l_25e9:
	/* 0x25e9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25ec:
	/* 0x25ec: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_25f2:
	/* 0x25f2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f7:
	/* 0x25f7: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_25fc:
	/* 0x25fc: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2602:
	/* 0x2602: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2607:
	/* 0x2607: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260c:
	/* 0x260c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2610:
	/* 0x2610: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2615:
	/* 0x2615: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_261a:
	/* 0x261a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_261c:
	/* 0x261c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2621:
	/* 0x2621: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2626:
	/* 0x2626: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262b:
	/* 0x262b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2630:
	/* 0x2630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2632:
	/* 0x2632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2637:
	/* 0x2637: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263c:
	/* 0x263c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2641:
	/* 0x2641: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2646:
	/* 0x2646: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2648:
	/* 0x2648: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264d:
	/* 0x264d: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2651:
	/* 0x2651: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2656:
	/* 0x2656: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_265b:
	/* 0x265b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2660:
	/* 0x2660: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2663:
	/* 0x2663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2665:
	/* 0x2665: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_266a:
	/* 0x266a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_266f:
	/* 0x266f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2673:
	/* 0x2673: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2678:
	/* 0x2678: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_267d:
	/* 0x267d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2682:
	/* 0x2682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2684:
	/* 0x2684: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2689:
	/* 0x2689: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_268c:
	/* 0x268c: je     270f <trace_set_fs_pwd+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_270f;
	}
x86_l_2692:
	/* 0x2692: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2697:
	/* 0x2697: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_269a:
	/* 0x269a: je     270f <trace_set_fs_pwd+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_270f;
	}
x86_l_269c:
	/* 0x269c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26a0:
	/* 0x26a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a5:
	/* 0x26a5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26aa:
	/* 0x26aa: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26af:
	/* 0x26af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b1:
	/* 0x26b1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_26b5:
	/* 0x26b5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_26b7:
	/* 0x26b7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26bd:
	/* 0x26bd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26c2:
	/* 0x26c2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26c4:
	/* 0x26c4: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_26ca:
	/* 0x26ca: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26cf:
	/* 0x26cf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_26d5:
	/* 0x26d5: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_26da:
	/* 0x26da: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_26df:
	/* 0x26df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e1:
	/* 0x26e1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26e4:
	/* 0x26e4: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_26ea:
	/* 0x26ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ef:
	/* 0x26ef: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_26f2:
	/* 0x26f2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_26f8:
	/* 0x26f8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26fd:
	/* 0x26fd: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2701:
	/* 0x2701: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2703:
	/* 0x2703: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2708:
	/* 0x2708: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_270d:
	/* 0x270d: jmp    2777 <trace_set_fs_pwd+0x2777> */
	goto x86_l_2777;
x86_l_270f:
	/* 0x270f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2712:
	/* 0x2712: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2718:
	/* 0x2718: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271d:
	/* 0x271d: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2722:
	/* 0x2722: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2728:
	/* 0x2728: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_272d:
	/* 0x272d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2732:
	/* 0x2732: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2736:
	/* 0x2736: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_273b:
	/* 0x273b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2740:
	/* 0x2740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2742:
	/* 0x2742: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2747:
	/* 0x2747: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274c:
	/* 0x274c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2751:
	/* 0x2751: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2756:
	/* 0x2756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2758:
	/* 0x2758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_275d:
	/* 0x275d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2762:
	/* 0x2762: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2767:
	/* 0x2767: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_276c:
	/* 0x276c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276e:
	/* 0x276e: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2773:
	/* 0x2773: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2777:
	/* 0x2777: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_277c:
	/* 0x277c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2781:
	/* 0x2781: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2786:
	/* 0x2786: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2789:
	/* 0x2789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278b:
	/* 0x278b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2790:
	/* 0x2790: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2795:
	/* 0x2795: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2799:
	/* 0x2799: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_279e:
	/* 0x279e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27a3:
	/* 0x27a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27a8:
	/* 0x27a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27aa:
	/* 0x27aa: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27af:
	/* 0x27af: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_27b2:
	/* 0x27b2: je     2835 <trace_set_fs_pwd+0x2835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2835;
	}
x86_l_27b8:
	/* 0x27b8: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27bd:
	/* 0x27bd: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27c0:
	/* 0x27c0: je     2835 <trace_set_fs_pwd+0x2835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2835;
	}
x86_l_27c2:
	/* 0x27c2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27c6:
	/* 0x27c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27cb:
	/* 0x27cb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d0:
	/* 0x27d0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27d5:
	/* 0x27d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d7:
	/* 0x27d7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_27db:
	/* 0x27db: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_27dd:
	/* 0x27dd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27e3:
	/* 0x27e3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e8:
	/* 0x27e8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27ea:
	/* 0x27ea: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_27f0:
	/* 0x27f0: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27f5:
	/* 0x27f5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27fb:
	/* 0x27fb: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2800:
	/* 0x2800: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2805:
	/* 0x2805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2807:
	/* 0x2807: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_280a:
	/* 0x280a: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2810:
	/* 0x2810: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2815:
	/* 0x2815: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2818:
	/* 0x2818: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_281e:
	/* 0x281e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2823:
	/* 0x2823: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2827:
	/* 0x2827: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2829:
	/* 0x2829: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282e:
	/* 0x282e: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2833:
	/* 0x2833: jmp    289d <trace_set_fs_pwd+0x289d> */
	goto x86_l_289d;
x86_l_2835:
	/* 0x2835: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2838:
	/* 0x2838: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_283e:
	/* 0x283e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2843:
	/* 0x2843: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2848:
	/* 0x2848: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_284e:
	/* 0x284e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2853:
	/* 0x2853: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2858:
	/* 0x2858: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_285c:
	/* 0x285c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2861:
	/* 0x2861: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2866:
	/* 0x2866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2868:
	/* 0x2868: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_286d:
	/* 0x286d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2872:
	/* 0x2872: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2883:
	/* 0x2883: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2888:
	/* 0x2888: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_288d:
	/* 0x288d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2892:
	/* 0x2892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2894:
	/* 0x2894: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2899:
	/* 0x2899: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_289d:
	/* 0x289d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28a2:
	/* 0x28a2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 10407ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10407ULL: goto x86_l_28a7;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10446ULL: goto x86_l_28ce;
	case 10448ULL: goto x86_l_28d0;
	case 10453ULL: goto x86_l_28d5;
	case 10456ULL: goto x86_l_28d8;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10470ULL: goto x86_l_28e6;
	case 10472ULL: goto x86_l_28e8;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10512ULL: goto x86_l_2910;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10541ULL: goto x86_l_292d;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10573ULL: goto x86_l_294d;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10636ULL: goto x86_l_298c;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10682ULL: goto x86_l_29ba;
	case 10687ULL: goto x86_l_29bf;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10711ULL: goto x86_l_29d7;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10750ULL: goto x86_l_29fe;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10764ULL: goto x86_l_2a0c;
	case 10766ULL: goto x86_l_2a0e;
	case 10770ULL: goto x86_l_2a12;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10785ULL: goto x86_l_2a21;
	case 10787ULL: goto x86_l_2a23;
	case 10791ULL: goto x86_l_2a27;
	case 10793ULL: goto x86_l_2a29;
	case 10799ULL: goto x86_l_2a2f;
	case 10804ULL: goto x86_l_2a34;
	case 10806ULL: goto x86_l_2a36;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10835ULL: goto x86_l_2a53;
	case 10838ULL: goto x86_l_2a56;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10852ULL: goto x86_l_2a64;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10867ULL: goto x86_l_2a73;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10879ULL: goto x86_l_2a7f;
	case 10881ULL: goto x86_l_2a81;
	case 10884ULL: goto x86_l_2a84;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10900ULL: goto x86_l_2a94;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11085ULL: goto x86_l_2b4d;
	case 11087ULL: goto x86_l_2b4f;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11129ULL: goto x86_l_2b79;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11178ULL: goto x86_l_2baa;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11313ULL: goto x86_l_2c31;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11352ULL: goto x86_l_2c58;
	case 11354ULL: goto x86_l_2c5a;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11375ULL: goto x86_l_2c6f;
	case 11379ULL: goto x86_l_2c73;
	case 11381ULL: goto x86_l_2c75;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11394ULL: goto x86_l_2c82;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11426ULL: goto x86_l_2ca2;
	case 11432ULL: goto x86_l_2ca8;
	case 11437ULL: goto x86_l_2cad;
	case 11440ULL: goto x86_l_2cb0;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11455ULL: goto x86_l_2cbf;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11472ULL: goto x86_l_2cd0;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11488ULL: goto x86_l_2ce0;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11591ULL: goto x86_l_2d47;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11622ULL: goto x86_l_2d66;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11632ULL: goto x86_l_2d70;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11669ULL: goto x86_l_2d95;
	case 11673ULL: goto x86_l_2d99;
	case 11675ULL: goto x86_l_2d9b;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11705ULL: goto x86_l_2db9;
	case 11710ULL: goto x86_l_2dbe;
	case 11715ULL: goto x86_l_2dc3;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11782ULL: goto x86_l_2e06;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11858ULL: goto x86_l_2e52;
	case 11863ULL: goto x86_l_2e57;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11918ULL: goto x86_l_2e8e;
	case 11923ULL: goto x86_l_2e93;
	case 11926ULL: goto x86_l_2e96;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11963ULL: goto x86_l_2ebb;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11982ULL: goto x86_l_2ece;
	case 11988ULL: goto x86_l_2ed4;
	case 11993ULL: goto x86_l_2ed9;
	case 11999ULL: goto x86_l_2edf;
	case 12004ULL: goto x86_l_2ee4;
	case 12009ULL: goto x86_l_2ee9;
	case 12011ULL: goto x86_l_2eeb;
	case 12014ULL: goto x86_l_2eee;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12043ULL: goto x86_l_2f0b;
	case 12045ULL: goto x86_l_2f0d;
	case 12050ULL: goto x86_l_2f12;
	case 12055ULL: goto x86_l_2f17;
	case 12057ULL: goto x86_l_2f19;
	default: return 0xffffffffffffffffULL;
	}
x86_l_28a7:
	/* 0x28a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ac:
	/* 0x28ac: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_28af:
	/* 0x28af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b1:
	/* 0x28b1: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28b6:
	/* 0x28b6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28bb:
	/* 0x28bb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28c4:
	/* 0x28c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28c9:
	/* 0x28c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ce:
	/* 0x28ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d0:
	/* 0x28d0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28d5:
	/* 0x28d5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28d8:
	/* 0x28d8: je     295b <trace_set_fs_pwd+0x295b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295b;
	}
x86_l_28de:
	/* 0x28de: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28e3:
	/* 0x28e3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28e6:
	/* 0x28e6: je     295b <trace_set_fs_pwd+0x295b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295b;
	}
x86_l_28e8:
	/* 0x28e8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28ec:
	/* 0x28ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28f1:
	/* 0x28f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28f6:
	/* 0x28f6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28fb:
	/* 0x28fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28fd:
	/* 0x28fd: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2901:
	/* 0x2901: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2903:
	/* 0x2903: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2909:
	/* 0x2909: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290e:
	/* 0x290e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2910:
	/* 0x2910: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2916:
	/* 0x2916: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_291b:
	/* 0x291b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2921:
	/* 0x2921: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2926:
	/* 0x2926: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_292b:
	/* 0x292b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292d:
	/* 0x292d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2930:
	/* 0x2930: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2936:
	/* 0x2936: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293b:
	/* 0x293b: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_293e:
	/* 0x293e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2944:
	/* 0x2944: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2949:
	/* 0x2949: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_294d:
	/* 0x294d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_294f:
	/* 0x294f: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2954:
	/* 0x2954: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2959:
	/* 0x2959: jmp    29c3 <trace_set_fs_pwd+0x29c3> */
	goto x86_l_29c3;
x86_l_295b:
	/* 0x295b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_295e:
	/* 0x295e: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2964:
	/* 0x2964: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2969:
	/* 0x2969: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_296e:
	/* 0x296e: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2974:
	/* 0x2974: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2979:
	/* 0x2979: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_297e:
	/* 0x297e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2982:
	/* 0x2982: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2987:
	/* 0x2987: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_298c:
	/* 0x298c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298e:
	/* 0x298e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2993:
	/* 0x2993: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2998:
	/* 0x2998: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_299d:
	/* 0x299d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29a2:
	/* 0x29a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a4:
	/* 0x29a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29a9:
	/* 0x29a9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ae:
	/* 0x29ae: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29b3:
	/* 0x29b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b8:
	/* 0x29b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ba:
	/* 0x29ba: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29bf:
	/* 0x29bf: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29c3:
	/* 0x29c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29c8:
	/* 0x29c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29cd:
	/* 0x29cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29d2:
	/* 0x29d2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_29d5:
	/* 0x29d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d7:
	/* 0x29d7: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29dc:
	/* 0x29dc: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e1:
	/* 0x29e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29e5:
	/* 0x29e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ea:
	/* 0x29ea: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29ef:
	/* 0x29ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f4:
	/* 0x29f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f6:
	/* 0x29f6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29fb:
	/* 0x29fb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29fe:
	/* 0x29fe: je     2a81 <trace_set_fs_pwd+0x2a81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a81;
	}
x86_l_2a04:
	/* 0x2a04: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a09:
	/* 0x2a09: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a0c:
	/* 0x2a0c: je     2a81 <trace_set_fs_pwd+0x2a81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a81;
	}
x86_l_2a0e:
	/* 0x2a0e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a12:
	/* 0x2a12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a17:
	/* 0x2a17: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a1c:
	/* 0x2a1c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a21:
	/* 0x2a21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a23:
	/* 0x2a23: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2a27:
	/* 0x2a27: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a29:
	/* 0x2a29: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a2f:
	/* 0x2a2f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a34:
	/* 0x2a34: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a36:
	/* 0x2a36: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2a3c:
	/* 0x2a3c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a41:
	/* 0x2a41: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a47:
	/* 0x2a47: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2a4c:
	/* 0x2a4c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a51:
	/* 0x2a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a53:
	/* 0x2a53: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a56:
	/* 0x2a56: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2a5c:
	/* 0x2a5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a61:
	/* 0x2a61: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a64:
	/* 0x2a64: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6f:
	/* 0x2a6f: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a73:
	/* 0x2a73: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a75:
	/* 0x2a75: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7a:
	/* 0x2a7a: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a7f:
	/* 0x2a7f: jmp    2ae9 <trace_set_fs_pwd+0x2ae9> */
	goto x86_l_2ae9;
x86_l_2a81:
	/* 0x2a81: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a84:
	/* 0x2a84: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2a8a:
	/* 0x2a8a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a8f:
	/* 0x2a8f: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2a94:
	/* 0x2a94: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2a9a:
	/* 0x2a9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa4:
	/* 0x2aa4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2aa8:
	/* 0x2aa8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aad:
	/* 0x2aad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ab2:
	/* 0x2ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab4:
	/* 0x2ab4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abe:
	/* 0x2abe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac8:
	/* 0x2ac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aca:
	/* 0x2aca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2acf:
	/* 0x2acf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad4:
	/* 0x2ad4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ade:
	/* 0x2ade: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae0:
	/* 0x2ae0: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae5:
	/* 0x2ae5: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ae9:
	/* 0x2ae9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aee:
	/* 0x2aee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2af3:
	/* 0x2af3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2af8:
	/* 0x2af8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2afb:
	/* 0x2afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afd:
	/* 0x2afd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b02:
	/* 0x2b02: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b07:
	/* 0x2b07: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b10:
	/* 0x2b10: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b15:
	/* 0x2b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b1a:
	/* 0x2b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1c:
	/* 0x2b1c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b21:
	/* 0x2b21: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b24:
	/* 0x2b24: je     2ba7 <trace_set_fs_pwd+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba7;
	}
x86_l_2b2a:
	/* 0x2b2a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b2f:
	/* 0x2b2f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b32:
	/* 0x2b32: je     2ba7 <trace_set_fs_pwd+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba7;
	}
x86_l_2b34:
	/* 0x2b34: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b38:
	/* 0x2b38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3d:
	/* 0x2b3d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b42:
	/* 0x2b42: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b47:
	/* 0x2b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b49:
	/* 0x2b49: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2b4d:
	/* 0x2b4d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b4f:
	/* 0x2b4f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b55:
	/* 0x2b55: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5a:
	/* 0x2b5a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b5c:
	/* 0x2b5c: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2b62:
	/* 0x2b62: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b67:
	/* 0x2b67: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b6d:
	/* 0x2b6d: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2b72:
	/* 0x2b72: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b77:
	/* 0x2b77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b79:
	/* 0x2b79: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b7c:
	/* 0x2b7c: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2b82:
	/* 0x2b82: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b87:
	/* 0x2b87: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2b8a:
	/* 0x2b8a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2b90:
	/* 0x2b90: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b95:
	/* 0x2b95: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2b99:
	/* 0x2b99: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b9b:
	/* 0x2b9b: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ba5:
	/* 0x2ba5: jmp    2c0f <trace_set_fs_pwd+0x2c0f> */
	goto x86_l_2c0f;
x86_l_2ba7:
	/* 0x2ba7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2baa:
	/* 0x2baa: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2bb0:
	/* 0x2bb0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb5:
	/* 0x2bb5: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2bba:
	/* 0x2bba: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2bc0:
	/* 0x2bc0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bca:
	/* 0x2bca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bce:
	/* 0x2bce: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd8:
	/* 0x2bd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bda:
	/* 0x2bda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be4:
	/* 0x2be4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be9:
	/* 0x2be9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bee:
	/* 0x2bee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf0:
	/* 0x2bf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf5:
	/* 0x2bf5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bfa:
	/* 0x2bfa: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bff:
	/* 0x2bff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c04:
	/* 0x2c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c06:
	/* 0x2c06: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c0b:
	/* 0x2c0b: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c0f:
	/* 0x2c0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c14:
	/* 0x2c14: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c19:
	/* 0x2c19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2c21:
	/* 0x2c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c23:
	/* 0x2c23: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c28:
	/* 0x2c28: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c2d:
	/* 0x2c2d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c31:
	/* 0x2c31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c36:
	/* 0x2c36: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c3b:
	/* 0x2c3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c40:
	/* 0x2c40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c42:
	/* 0x2c42: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c47:
	/* 0x2c47: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c4a:
	/* 0x2c4a: je     2ccd <trace_set_fs_pwd+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccd;
	}
x86_l_2c50:
	/* 0x2c50: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c55:
	/* 0x2c55: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c58:
	/* 0x2c58: je     2ccd <trace_set_fs_pwd+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccd;
	}
x86_l_2c5a:
	/* 0x2c5a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c63:
	/* 0x2c63: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c68:
	/* 0x2c68: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c6d:
	/* 0x2c6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6f:
	/* 0x2c6f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2c73:
	/* 0x2c73: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c75:
	/* 0x2c75: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c80:
	/* 0x2c80: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c82:
	/* 0x2c82: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2c88:
	/* 0x2c88: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c8d:
	/* 0x2c8d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c93:
	/* 0x2c93: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2c98:
	/* 0x2c98: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c9d:
	/* 0x2c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9f:
	/* 0x2c9f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ca2:
	/* 0x2ca2: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2ca8:
	/* 0x2ca8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cad:
	/* 0x2cad: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2cb0:
	/* 0x2cb0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2cbf:
	/* 0x2cbf: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cc1:
	/* 0x2cc1: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ccb:
	/* 0x2ccb: jmp    2d35 <trace_set_fs_pwd+0x2d35> */
	goto x86_l_2d35;
x86_l_2ccd:
	/* 0x2ccd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cd0:
	/* 0x2cd0: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2cd6:
	/* 0x2cd6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cdb:
	/* 0x2cdb: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2ce0:
	/* 0x2ce0: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2ce6:
	/* 0x2ce6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf0:
	/* 0x2cf0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cf4:
	/* 0x2cf4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cfe:
	/* 0x2cfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d00:
	/* 0x2d00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d05:
	/* 0x2d05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0a:
	/* 0x2d0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d14:
	/* 0x2d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d16:
	/* 0x2d16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d1b:
	/* 0x2d1b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d20:
	/* 0x2d20: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d25:
	/* 0x2d25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2a:
	/* 0x2d2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2c:
	/* 0x2d2c: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d31:
	/* 0x2d31: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d35:
	/* 0x2d35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d3a:
	/* 0x2d3a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d3f:
	/* 0x2d3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d44:
	/* 0x2d44: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2d47:
	/* 0x2d47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d49:
	/* 0x2d49: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d53:
	/* 0x2d53: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d57:
	/* 0x2d57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d5c:
	/* 0x2d5c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d61:
	/* 0x2d61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d66:
	/* 0x2d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d68:
	/* 0x2d68: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d6d:
	/* 0x2d6d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d70:
	/* 0x2d70: je     2df3 <trace_set_fs_pwd+0x2df3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df3;
	}
x86_l_2d76:
	/* 0x2d76: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d7b:
	/* 0x2d7b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d7e:
	/* 0x2d7e: je     2df3 <trace_set_fs_pwd+0x2df3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df3;
	}
x86_l_2d80:
	/* 0x2d80: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d84:
	/* 0x2d84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d89:
	/* 0x2d89: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d8e:
	/* 0x2d8e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d93:
	/* 0x2d93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d95:
	/* 0x2d95: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2d99:
	/* 0x2d99: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d9b:
	/* 0x2d9b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2da1:
	/* 0x2da1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da6:
	/* 0x2da6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2da8:
	/* 0x2da8: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2dae:
	/* 0x2dae: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2db3:
	/* 0x2db3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2db9:
	/* 0x2db9: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2dbe:
	/* 0x2dbe: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2dc3:
	/* 0x2dc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc5:
	/* 0x2dc5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dc8:
	/* 0x2dc8: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2dce:
	/* 0x2dce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dd3:
	/* 0x2dd3: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2dd6:
	/* 0x2dd6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ddc:
	/* 0x2ddc: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2de1:
	/* 0x2de1: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2de5:
	/* 0x2de5: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2de7:
	/* 0x2de7: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dec:
	/* 0x2dec: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2df1:
	/* 0x2df1: jmp    2e5b <trace_set_fs_pwd+0x2e5b> */
	goto x86_l_2e5b;
x86_l_2df3:
	/* 0x2df3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2df6:
	/* 0x2df6: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2dfc:
	/* 0x2dfc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e01:
	/* 0x2e01: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2e06:
	/* 0x2e06: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2e0c:
	/* 0x2e0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e11:
	/* 0x2e11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e16:
	/* 0x2e16: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e1a:
	/* 0x2e1a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e1f:
	/* 0x2e1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e24:
	/* 0x2e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e26:
	/* 0x2e26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e30:
	/* 0x2e30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x2e41: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e46:
	/* 0x2e46: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e50:
	/* 0x2e50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e52:
	/* 0x2e52: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e57:
	/* 0x2e57: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e60:
	/* 0x2e60: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e65:
	/* 0x2e65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6a:
	/* 0x2e6a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e74:
	/* 0x2e74: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e79:
	/* 0x2e79: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e82:
	/* 0x2e82: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e87:
	/* 0x2e87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8c:
	/* 0x2e8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8e:
	/* 0x2e8e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e93:
	/* 0x2e93: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e96:
	/* 0x2e96: je     2f19 <trace_set_fs_pwd+0x2f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f19;
	}
x86_l_2e9c:
	/* 0x2e9c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ea1:
	/* 0x2ea1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ea4:
	/* 0x2ea4: je     2f19 <trace_set_fs_pwd+0x2f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f19;
	}
x86_l_2ea6:
	/* 0x2ea6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2eaa:
	/* 0x2eaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eaf:
	/* 0x2eaf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2eb9:
	/* 0x2eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebb:
	/* 0x2ebb: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ebf:
	/* 0x2ebf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ec1:
	/* 0x2ec1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ec7:
	/* 0x2ec7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ecc:
	/* 0x2ecc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ece:
	/* 0x2ece: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2ed4:
	/* 0x2ed4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ed9:
	/* 0x2ed9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2edf:
	/* 0x2edf: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2ee4:
	/* 0x2ee4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ee9:
	/* 0x2ee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eeb:
	/* 0x2eeb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eee:
	/* 0x2eee: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_2ef4:
	/* 0x2ef4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef9:
	/* 0x2ef9: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2efc:
	/* 0x2efc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f02:
	/* 0x2f02: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f07:
	/* 0x2f07: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f0b:
	/* 0x2f0b: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f0d:
	/* 0x2f0d: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f12:
	/* 0x2f12: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f17:
	/* 0x2f17: jmp    2f81 <trace_set_fs_pwd+0x2f81> */
	return 12161ULL;
x86_l_2f19:
	/* 0x2f19: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
	return 12060ULL;
}

static __noinline __u64 tracee_trace_set_fs_pwd_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12060ULL: goto x86_l_2f1c;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12130ULL: goto x86_l_2f62;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12176ULL: goto x86_l_2f90;
	case 12179ULL: goto x86_l_2f93;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12191ULL: goto x86_l_2f9f;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12212ULL: goto x86_l_2fb4;
	case 12217ULL: goto x86_l_2fb9;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12234ULL: goto x86_l_2fca;
	case 12236ULL: goto x86_l_2fcc;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12257ULL: goto x86_l_2fe1;
	case 12261ULL: goto x86_l_2fe5;
	case 12263ULL: goto x86_l_2fe7;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12276ULL: goto x86_l_2ff4;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12305ULL: goto x86_l_3011;
	case 12308ULL: goto x86_l_3014;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12322ULL: goto x86_l_3022;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12354ULL: goto x86_l_3042;
	case 12360ULL: goto x86_l_3048;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12390ULL: goto x86_l_3066;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12470ULL: goto x86_l_30b6;
	case 12473ULL: goto x86_l_30b9;
	case 12475ULL: goto x86_l_30bb;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12499ULL: goto x86_l_30d3;
	case 12504ULL: goto x86_l_30d8;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12514ULL: goto x86_l_30e2;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12555ULL: goto x86_l_310b;
	case 12557ULL: goto x86_l_310d;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12570ULL: goto x86_l_311a;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12599ULL: goto x86_l_3137;
	case 12602ULL: goto x86_l_313a;
	case 12608ULL: goto x86_l_3140;
	case 12613ULL: goto x86_l_3145;
	case 12616ULL: goto x86_l_3148;
	case 12622ULL: goto x86_l_314e;
	case 12627ULL: goto x86_l_3153;
	case 12631ULL: goto x86_l_3157;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12643ULL: goto x86_l_3163;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12680ULL: goto x86_l_3188;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12767ULL: goto x86_l_31df;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12808ULL: goto x86_l_3208;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12822ULL: goto x86_l_3216;
	case 12828ULL: goto x86_l_321c;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12855ULL: goto x86_l_3237;
	case 12861ULL: goto x86_l_323d;
	case 12866ULL: goto x86_l_3242;
	case 12868ULL: goto x86_l_3244;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12885ULL: goto x86_l_3255;
	case 12890ULL: goto x86_l_325a;
	case 12895ULL: goto x86_l_325f;
	case 12897ULL: goto x86_l_3261;
	case 12900ULL: goto x86_l_3264;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12914ULL: goto x86_l_3272;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12942ULL: goto x86_l_328e;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 13002ULL: goto x86_l_32ca;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13065ULL: goto x86_l_3309;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f1c:
	/* 0x2f1c: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_2f22:
	/* 0x2f22: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f27:
	/* 0x2f27: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2f2c:
	/* 0x2f2c: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_2f32:
	/* 0x2f32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f37:
	/* 0x2f37: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3c:
	/* 0x2f3c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f40:
	/* 0x2f40: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f45:
	/* 0x2f45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4a:
	/* 0x2f4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4c:
	/* 0x2f4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f51:
	/* 0x2f51: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f56:
	/* 0x2f56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f5b:
	/* 0x2f5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f60:
	/* 0x2f60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f62:
	/* 0x2f62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f67:
	/* 0x2f67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6c:
	/* 0x2f6c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f71:
	/* 0x2f71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f76:
	/* 0x2f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f78:
	/* 0x2f78: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7d:
	/* 0x2f7d: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f81:
	/* 0x2f81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f86:
	/* 0x2f86: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f90:
	/* 0x2f90: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2f93:
	/* 0x2f93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f95:
	/* 0x2f95: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f9a:
	/* 0x2f9a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f9f:
	/* 0x2f9f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fa3:
	/* 0x2fa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fa8:
	/* 0x2fa8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fad:
	/* 0x2fad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb2:
	/* 0x2fb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb4:
	/* 0x2fb4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fb9:
	/* 0x2fb9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2fbc:
	/* 0x2fbc: je     303f <trace_set_fs_pwd+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303f;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fc7:
	/* 0x2fc7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2fca:
	/* 0x2fca: je     303f <trace_set_fs_pwd+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303f;
	}
x86_l_2fcc:
	/* 0x2fcc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fd0:
	/* 0x2fd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fd5:
	/* 0x2fd5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fda:
	/* 0x2fda: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2fdf:
	/* 0x2fdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe1:
	/* 0x2fe1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2fe5:
	/* 0x2fe5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fe7:
	/* 0x2fe7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fed:
	/* 0x2fed: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff2:
	/* 0x2ff2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ff4:
	/* 0x2ff4: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_2ffa:
	/* 0x2ffa: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fff:
	/* 0x2fff: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3005:
	/* 0x3005: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_300a:
	/* 0x300a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_300f:
	/* 0x300f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3011:
	/* 0x3011: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3014:
	/* 0x3014: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_301a:
	/* 0x301a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301f:
	/* 0x301f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3022:
	/* 0x3022: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3028:
	/* 0x3028: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_302d:
	/* 0x302d: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3031:
	/* 0x3031: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3033:
	/* 0x3033: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3038:
	/* 0x3038: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_303d:
	/* 0x303d: jmp    30a7 <trace_set_fs_pwd+0x30a7> */
	goto x86_l_30a7;
x86_l_303f:
	/* 0x303f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3042:
	/* 0x3042: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_3048:
	/* 0x3048: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_304d:
	/* 0x304d: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3052:
	/* 0x3052: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_3058:
	/* 0x3058: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_305d:
	/* 0x305d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3062:
	/* 0x3062: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3066:
	/* 0x3066: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_306b:
	/* 0x306b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3070:
	/* 0x3070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3072:
	/* 0x3072: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3077:
	/* 0x3077: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_307c:
	/* 0x307c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3081:
	/* 0x3081: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3086:
	/* 0x3086: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3088:
	/* 0x3088: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_308d:
	/* 0x308d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3092:
	/* 0x3092: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3097:
	/* 0x3097: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_309c:
	/* 0x309c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309e:
	/* 0x309e: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a3:
	/* 0x30a3: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30a7:
	/* 0x30a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ac:
	/* 0x30ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30b1:
	/* 0x30b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b6:
	/* 0x30b6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_30b9:
	/* 0x30b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30bb:
	/* 0x30bb: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30c0:
	/* 0x30c0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30c5:
	/* 0x30c5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30c9:
	/* 0x30c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ce:
	/* 0x30ce: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30d3:
	/* 0x30d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d8:
	/* 0x30d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30da:
	/* 0x30da: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30df:
	/* 0x30df: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_30e2:
	/* 0x30e2: je     3165 <trace_set_fs_pwd+0x3165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3165;
	}
x86_l_30e8:
	/* 0x30e8: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30ed:
	/* 0x30ed: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30f0:
	/* 0x30f0: je     3165 <trace_set_fs_pwd+0x3165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3165;
	}
x86_l_30f2:
	/* 0x30f2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30f6:
	/* 0x30f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30fb:
	/* 0x30fb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3100:
	/* 0x3100: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3105:
	/* 0x3105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3107:
	/* 0x3107: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_310b:
	/* 0x310b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_310d:
	/* 0x310d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3113:
	/* 0x3113: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3118:
	/* 0x3118: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_311a:
	/* 0x311a: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_3120:
	/* 0x3120: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3125:
	/* 0x3125: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_312b:
	/* 0x312b: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3130:
	/* 0x3130: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3135:
	/* 0x3135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3137:
	/* 0x3137: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_313a:
	/* 0x313a: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_3140:
	/* 0x3140: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3145:
	/* 0x3145: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3148:
	/* 0x3148: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_314e:
	/* 0x314e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3153:
	/* 0x3153: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3157:
	/* 0x3157: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3159:
	/* 0x3159: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_315e:
	/* 0x315e: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3163:
	/* 0x3163: jmp    31cd <trace_set_fs_pwd+0x31cd> */
	goto x86_l_31cd;
x86_l_3165:
	/* 0x3165: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3168:
	/* 0x3168: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_316e:
	/* 0x316e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3173:
	/* 0x3173: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3178:
	/* 0x3178: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_317e:
	/* 0x317e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3183:
	/* 0x3183: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3188:
	/* 0x3188: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_318c:
	/* 0x318c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3191:
	/* 0x3191: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3196:
	/* 0x3196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3198:
	/* 0x3198: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_319d:
	/* 0x319d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a2:
	/* 0x31a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a7:
	/* 0x31a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ac:
	/* 0x31ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ae:
	/* 0x31ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31b3:
	/* 0x31b3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b8:
	/* 0x31b8: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31bd:
	/* 0x31bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c2:
	/* 0x31c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c4:
	/* 0x31c4: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c9:
	/* 0x31c9: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31cd:
	/* 0x31cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31d2:
	/* 0x31d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31d7:
	/* 0x31d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31dc:
	/* 0x31dc: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_31df:
	/* 0x31df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e1:
	/* 0x31e1: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31e6:
	/* 0x31e6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31eb:
	/* 0x31eb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31ef:
	/* 0x31ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31f4:
	/* 0x31f4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31f9:
	/* 0x31f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31fe:
	/* 0x31fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3200:
	/* 0x3200: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3205:
	/* 0x3205: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3208:
	/* 0x3208: je     3299 <trace_set_fs_pwd+0x3299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3299;
	}
x86_l_320e:
	/* 0x320e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3213:
	/* 0x3213: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3216:
	/* 0x3216: je     3299 <trace_set_fs_pwd+0x3299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3299;
	}
x86_l_321c:
	/* 0x321c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3220:
	/* 0x3220: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3225:
	/* 0x3225: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_322a:
	/* 0x322a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_322f:
	/* 0x322f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3231:
	/* 0x3231: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3235:
	/* 0x3235: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3237:
	/* 0x3237: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_323d:
	/* 0x323d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3242:
	/* 0x3242: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3244:
	/* 0x3244: jb     1c5d <trace_set_fs_pwd+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7261ULL;
	}
x86_l_324a:
	/* 0x324a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_324f:
	/* 0x324f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3255:
	/* 0x3255: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_325a:
	/* 0x325a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_325f:
	/* 0x325f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3261:
	/* 0x3261: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3264:
	/* 0x3264: jl     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6307ULL;
	}
x86_l_326a:
	/* 0x326a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_326f:
	/* 0x326f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3272:
	/* 0x3272: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3278:
	/* 0x3278: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_327d:
	/* 0x327d: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3281:
	/* 0x3281: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3283:
	/* 0x3283: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3288:
	/* 0x3288: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_328e:
	/* 0x328e: je     18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6324ULL;
	}
x86_l_3294:
	/* 0x3294: jmp    1c62 <trace_set_fs_pwd+0x1c62> */
	return 7266ULL;
x86_l_3299:
	/* 0x3299: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_329c:
	/* 0x329c: jne    18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6307ULL;
	}
x86_l_32a2:
	/* 0x32a2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32a7:
	/* 0x32a7: cmp    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_32ac:
	/* 0x32ac: je     18a3 <trace_set_fs_pwd+0x18a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6307ULL;
	}
x86_l_32b2:
	/* 0x32b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32b7:
	/* 0x32b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32bc:
	/* 0x32bc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32c0:
	/* 0x32c0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32c5:
	/* 0x32c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ca:
	/* 0x32ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cc:
	/* 0x32cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d1:
	/* 0x32d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d6:
	/* 0x32d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32db:
	/* 0x32db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e0:
	/* 0x32e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32e7:
	/* 0x32e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ec:
	/* 0x32ec: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32f1:
	/* 0x32f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f6:
	/* 0x32f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f8:
	/* 0x32f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32fd:
	/* 0x32fd: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_3303:
	/* 0x3303: je     18b4 <trace_set_fs_pwd+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6324ULL;
	}
x86_l_3309:
	/* 0x3309: jmp    1c62 <trace_set_fs_pwd+0x1c62> */
	return 7266ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_set_fs_pwd_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11668U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2137ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2140ULL && __x86_pc <= 3786ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3789ULL && __x86_pc <= 5366ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5371ULL && __x86_pc <= 7098ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7103ULL && __x86_pc <= 8735ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8741ULL && __x86_pc <= 10402ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10407ULL && __x86_pc <= 12057ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12060ULL && __x86_pc <= 13065ULL)
			__x86_pc = tracee_trace_set_fs_pwd_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

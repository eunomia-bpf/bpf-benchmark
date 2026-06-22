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

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_0(
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
	case 62ULL: goto x86_l_3e;
	case 64ULL: goto x86_l_40;
	case 72ULL: goto x86_l_48;
	case 77ULL: goto x86_l_4d;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 94ULL: goto x86_l_5e;
	case 96ULL: goto x86_l_60;
	case 99ULL: goto x86_l_63;
	case 101ULL: goto x86_l_65;
	case 104ULL: goto x86_l_68;
	case 106ULL: goto x86_l_6a;
	case 110ULL: goto x86_l_6e;
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
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 248ULL: goto x86_l_f8;
	case 251ULL: goto x86_l_fb;
	case 262ULL: goto x86_l_106;
	case 271ULL: goto x86_l_10f;
	case 283ULL: goto x86_l_11b;
	case 295ULL: goto x86_l_127;
	case 307ULL: goto x86_l_133;
	case 319ULL: goto x86_l_13f;
	case 331ULL: goto x86_l_14b;
	case 343ULL: goto x86_l_157;
	case 355ULL: goto x86_l_163;
	case 367ULL: goto x86_l_16f;
	case 375ULL: goto x86_l_177;
	case 384ULL: goto x86_l_180;
	case 393ULL: goto x86_l_189;
	case 402ULL: goto x86_l_192;
	case 411ULL: goto x86_l_19b;
	case 420ULL: goto x86_l_1a4;
	case 429ULL: goto x86_l_1ad;
	case 438ULL: goto x86_l_1b6;
	case 447ULL: goto x86_l_1bf;
	case 456ULL: goto x86_l_1c8;
	case 465ULL: goto x86_l_1d1;
	case 474ULL: goto x86_l_1da;
	case 483ULL: goto x86_l_1e3;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 529ULL: goto x86_l_211;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 540ULL: goto x86_l_21c;
	case 546ULL: goto x86_l_222;
	case 551ULL: goto x86_l_227;
	case 556ULL: goto x86_l_22c;
	case 563ULL: goto x86_l_233;
	case 570ULL: goto x86_l_23a;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 588ULL: goto x86_l_24c;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 598ULL: goto x86_l_256;
	case 605ULL: goto x86_l_25d;
	case 612ULL: goto x86_l_264;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 627ULL: goto x86_l_273;
	case 630ULL: goto x86_l_276;
	case 633ULL: goto x86_l_279;
	case 637ULL: goto x86_l_27d;
	case 645ULL: goto x86_l_285;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 662ULL: goto x86_l_296;
	case 667ULL: goto x86_l_29b;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
	case 693ULL: goto x86_l_2b5;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 712ULL: goto x86_l_2c8;
	case 715ULL: goto x86_l_2cb;
	case 721ULL: goto x86_l_2d1;
	case 724ULL: goto x86_l_2d4;
	case 728ULL: goto x86_l_2d8;
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
	case 1029ULL: goto x86_l_405;
	case 1040ULL: goto x86_l_410;
	case 1051ULL: goto x86_l_41b;
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
	case 1166ULL: goto x86_l_48e;
	case 1174ULL: goto x86_l_496;
	case 1182ULL: goto x86_l_49e;
	case 1189ULL: goto x86_l_4a5;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1214ULL: goto x86_l_4be;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1229ULL: goto x86_l_4cd;
	case 1231ULL: goto x86_l_4cf;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1255ULL: goto x86_l_4e7;
	case 1259ULL: goto x86_l_4eb;
	case 1267ULL: goto x86_l_4f3;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1295ULL: goto x86_l_50f;
	case 1301ULL: goto x86_l_515;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1313ULL: goto x86_l_521;
	case 1317ULL: goto x86_l_525;
	case 1328ULL: goto x86_l_530;
	case 1339ULL: goto x86_l_53b;
	case 1350ULL: goto x86_l_546;
	case 1361ULL: goto x86_l_551;
	case 1372ULL: goto x86_l_55c;
	case 1383ULL: goto x86_l_567;
	case 1394ULL: goto x86_l_572;
	case 1405ULL: goto x86_l_57d;
	case 1416ULL: goto x86_l_588;
	case 1424ULL: goto x86_l_590;
	case 1432ULL: goto x86_l_598;
	case 1440ULL: goto x86_l_5a0;
	case 1448ULL: goto x86_l_5a8;
	case 1456ULL: goto x86_l_5b0;
	case 1464ULL: goto x86_l_5b8;
	case 1472ULL: goto x86_l_5c0;
	case 1480ULL: goto x86_l_5c8;
	case 1488ULL: goto x86_l_5d0;
	case 1496ULL: goto x86_l_5d8;
	case 1504ULL: goto x86_l_5e0;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1528ULL: goto x86_l_5f8;
	case 1536ULL: goto x86_l_600;
	case 1543ULL: goto x86_l_607;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1560ULL: goto x86_l_618;
	case 1565ULL: goto x86_l_61d;
	case 1568ULL: goto x86_l_620;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1583ULL: goto x86_l_62f;
	case 1585ULL: goto x86_l_631;
	case 1588ULL: goto x86_l_634;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1648ULL: goto x86_l_670;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1736ULL: goto x86_l_6c8;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1806ULL: goto x86_l_70e;
	case 1808ULL: goto x86_l_710;
	case 1812ULL: goto x86_l_714;
	case 1816ULL: goto x86_l_718;
	case 1820ULL: goto x86_l_71c;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1846ULL: goto x86_l_736;
	case 1850ULL: goto x86_l_73a;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1877ULL: goto x86_l_755;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1940ULL: goto x86_l_794;
	case 1944ULL: goto x86_l_798;
	case 1948ULL: goto x86_l_79c;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1982ULL: goto x86_l_7be;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2041ULL: goto x86_l_7f9;
	case 2045ULL: goto x86_l_7fd;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2163ULL: goto x86_l_873;
	case 2168ULL: goto x86_l_878;
	case 2171ULL: goto x86_l_87b;
	case 2173ULL: goto x86_l_87d;
	case 2177ULL: goto x86_l_881;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
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
	/* 0x2a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x40: test   DWORD PTR [rsp+0x10],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68721573888ULL);
x86_l_48:
	/* 0x48: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_4d:
	/* 0x4d: jne    b5 <trace_execute_finished+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5;
	}
x86_l_4f:
	/* 0x4f: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63:
	/* 0x63: je     6a <trace_execute_finished+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a;
	}
x86_l_65:
	/* 0x65: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_68:
	/* 0x68: jmp    6a <trace_execute_finished+0x6a> */
	goto x86_l_6a;
x86_l_6a:
	/* 0x6a: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e:
	/* 0x6e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73:
	/* 0x73: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_78:
	/* 0x78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x87: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_8c:
	/* 0x8c: jne    94 <trace_execute_finished+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94;
	}
x86_l_8e:
	/* 0x8e: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_92:
	/* 0x92: jmp    b5 <trace_execute_finished+0xb5> */
	goto x86_l_b5;
x86_l_94:
	/* 0x94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_9b:
	/* 0x9b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0:
	/* 0xa0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a5:
	/* 0xa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7:
	/* 0xa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: je     b0 <trace_execute_finished+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_ac:
	/* 0xac: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: jmp    b5 <trace_execute_finished+0xb5> */
	goto x86_l_b5;
x86_l_b0:
	/* 0xb0: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_bd:
	/* 0xbd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c4:
	/* 0xc4: lea    rsi,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_c9:
	/* 0xc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce:
	/* 0xce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0:
	/* 0xd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: je     688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26763ULL;
	}
x86_l_d9:
	/* 0xd9: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e3:
	/* 0xe3: lea    rsi,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_e8:
	/* 0xe8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26763ULL;
	}
x86_l_f8:
	/* 0xf8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_106:
	/* 0x106: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10f:
	/* 0x10f: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_127:
	/* 0x127: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_133:
	/* 0x133: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_13f:
	/* 0x13f: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_14b:
	/* 0x14b: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_157:
	/* 0x157: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_163:
	/* 0x163: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_16f:
	/* 0x16f: mov    QWORD PTR [r12+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_177:
	/* 0x177: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_189:
	/* 0x189: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_192:
	/* 0x192: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_19b:
	/* 0x19b: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1a4:
	/* 0x1a4: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ad:
	/* 0x1ad: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b6:
	/* 0x1b6: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1da:
	/* 0x1da: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1e3:
	/* 0x1e3: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1ec:
	/* 0x1ec: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f8:
	/* 0x1f8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1fc:
	/* 0x1fc: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_201:
	/* 0x201: mov    DWORD PTR [r12+0x70],0x313 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337939ULL);
x86_l_20a:
	/* 0x20a: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_20f:
	/* 0x20f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211:
	/* 0x211: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215:
	/* 0x215: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_21a:
	/* 0x21a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c:
	/* 0x21c: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_222:
	/* 0x222: mov    DWORD PTR [r12+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_227:
	/* 0x227: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_233:
	/* 0x233: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_23a:
	/* 0x23a: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_242:
	/* 0x242: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_24c:
	/* 0x24c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24f:
	/* 0x24f: je     2a2 <trace_execute_finished+0x2a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2;
	}
x86_l_251:
	/* 0x251: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_256:
	/* 0x256: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_25d:
	/* 0x25d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_264:
	/* 0x264: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_26c:
	/* 0x26c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_271:
	/* 0x271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273:
	/* 0x273: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_276:
	/* 0x276: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_279:
	/* 0x279: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d:
	/* 0x27d: mov    QWORD PTR [rsp+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_285:
	/* 0x285: je     4e0 <trace_execute_finished+0x4e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e0;
	}
x86_l_28b:
	/* 0x28b: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_290:
	/* 0x290: jne    af3 <trace_execute_finished+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2803ULL;
	}
x86_l_296:
	/* 0x296: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_29b:
	/* 0x29b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d:
	/* 0x29d: jmp    b9e <trace_execute_finished+0xb9e> */
	return 2974ULL;
x86_l_2a2:
	/* 0x2a2: mov    eax,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_2a9:
	/* 0x2a9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2b5:
	/* 0x2b5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2bc:
	/* 0x2bc: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c1:
	/* 0x2c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c6:
	/* 0x2c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8:
	/* 0x2c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cb:
	/* 0x2cb: je     688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26763ULL;
	}
x86_l_2d1:
	/* 0x2d1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d4:
	/* 0x2d4: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d8:
	/* 0x2d8: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc:
	/* 0x2dc: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2e7:
	/* 0x2e7: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2f2:
	/* 0x2f2: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2fd:
	/* 0x2fd: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_308:
	/* 0x308: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_313:
	/* 0x313: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_31e:
	/* 0x31e: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_329:
	/* 0x329: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_334:
	/* 0x334: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_33f:
	/* 0x33f: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_34a:
	/* 0x34a: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_355:
	/* 0x355: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_360:
	/* 0x360: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_376:
	/* 0x376: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_381:
	/* 0x381: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_397:
	/* 0x397: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3a2:
	/* 0x3a2: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3ad:
	/* 0x3ad: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3b8:
	/* 0x3b8: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3c3:
	/* 0x3c3: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3ce:
	/* 0x3ce: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3d9:
	/* 0x3d9: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3e4:
	/* 0x3e4: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3fa:
	/* 0x3fa: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_405:
	/* 0x405: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_410:
	/* 0x410: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_42e:
	/* 0x42e: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_446:
	/* 0x446: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_456:
	/* 0x456: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_45e:
	/* 0x45e: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_486:
	/* 0x486: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_48e:
	/* 0x48e: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_49e:
	/* 0x49e: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a5:
	/* 0x4a5: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4ac:
	/* 0x4ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b1:
	/* 0x4b1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4b6:
	/* 0x4b6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bb:
	/* 0x4bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4be:
	/* 0x4be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c0:
	/* 0x4c0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5:
	/* 0x4c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ca:
	/* 0x4ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cf:
	/* 0x4cf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d5:
	/* 0x4d5: jne    251 <trace_execute_finished+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251;
	}
x86_l_4db:
	/* 0x4db: jmp    688b <trace_execute_finished+0x688b> */
	return 26763ULL;
x86_l_4e0:
	/* 0x4e0: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4e7:
	/* 0x4e7: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eb:
	/* 0x4eb: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4f3:
	/* 0x4f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4fa:
	/* 0x4fa: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4ff:
	/* 0x4ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_504:
	/* 0x504: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_50a:
	/* 0x50a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c:
	/* 0x50c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50f:
	/* 0x50f: je     688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26763ULL;
	}
x86_l_515:
	/* 0x515: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rsp+0x78],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_51d:
	/* 0x51d: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_521:
	/* 0x521: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_546:
	/* 0x546: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_551:
	/* 0x551: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_588:
	/* 0x588: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5a0:
	/* 0x5a0: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5c0:
	/* 0x5c0: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5d8:
	/* 0x5d8: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5e0:
	/* 0x5e0: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5f8:
	/* 0x5f8: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_607:
	/* 0x607: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_60e:
	/* 0x60e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_613:
	/* 0x613: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_618:
	/* 0x618: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_61d:
	/* 0x61d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_620:
	/* 0x620: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_622:
	/* 0x622: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_627:
	/* 0x627: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62c:
	/* 0x62c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_62f:
	/* 0x62f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_631:
	/* 0x631: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_634:
	/* 0x634: je     688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26763ULL;
	}
x86_l_63a:
	/* 0x63a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: mov    r12,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_645:
	/* 0x645: lea    r15,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64a:
	/* 0x64a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64f:
	/* 0x64f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_654:
	/* 0x654: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_659:
	/* 0x659: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65e:
	/* 0x65e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_661:
	/* 0x661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_663:
	/* 0x663: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_668:
	/* 0x668: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_670:
	/* 0x670: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_674:
	/* 0x674: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_679:
	/* 0x679: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_67e:
	/* 0x67e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_683:
	/* 0x683: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68f:
	/* 0x68f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_693:
	/* 0x693: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_698:
	/* 0x698: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_69d:
	/* 0x69d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a2:
	/* 0x6a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a7:
	/* 0x6a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a9:
	/* 0x6a9: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ae:
	/* 0x6ae: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6b2:
	/* 0x6b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b7:
	/* 0x6b7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6bc:
	/* 0x6bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c1:
	/* 0x6c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c6:
	/* 0x6c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c8:
	/* 0x6c8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cc:
	/* 0x6cc: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6d0:
	/* 0x6d0: mov    QWORD PTR [rsp+0x58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6d5:
	/* 0x6d5: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6d9:
	/* 0x6d9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6de:
	/* 0x6de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e3:
	/* 0x6e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e8:
	/* 0x6e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ed:
	/* 0x6ed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6f0:
	/* 0x6f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f2:
	/* 0x6f2: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f7:
	/* 0x6f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fc:
	/* 0x6fc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_701:
	/* 0x701: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_706:
	/* 0x706: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_70b:
	/* 0x70b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_70e:
	/* 0x70e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_710:
	/* 0x710: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_714:
	/* 0x714: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_718:
	/* 0x718: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_71c:
	/* 0x71c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_720:
	/* 0x720: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_725:
	/* 0x725: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_72a:
	/* 0x72a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72f:
	/* 0x72f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_734:
	/* 0x734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_736:
	/* 0x736: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73a:
	/* 0x73a: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_73e:
	/* 0x73e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_743:
	/* 0x743: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_748:
	/* 0x748: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74d:
	/* 0x74d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_752:
	/* 0x752: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_755:
	/* 0x755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_757:
	/* 0x757: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75c:
	/* 0x75c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_760:
	/* 0x760: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_765:
	/* 0x765: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_76a:
	/* 0x76a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_76f:
	/* 0x76f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_774:
	/* 0x774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_776:
	/* 0x776: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77b:
	/* 0x77b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_780:
	/* 0x780: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_785:
	/* 0x785: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78a:
	/* 0x78a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_78f:
	/* 0x78f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_792:
	/* 0x792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_794:
	/* 0x794: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_798:
	/* 0x798: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_79c:
	/* 0x79c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7a0:
	/* 0x7a0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7a4:
	/* 0x7a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a9:
	/* 0x7a9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ae:
	/* 0x7ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b3:
	/* 0x7b3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7be:
	/* 0x7be: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c2:
	/* 0x7c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c7:
	/* 0x7c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7cc:
	/* 0x7cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d1:
	/* 0x7d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d6:
	/* 0x7d6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7d9:
	/* 0x7d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7db:
	/* 0x7db: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e0:
	/* 0x7e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e5:
	/* 0x7e5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ea:
	/* 0x7ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ef:
	/* 0x7ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f4:
	/* 0x7f4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f9:
	/* 0x7f9: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fd:
	/* 0x7fd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_801:
	/* 0x801: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_805:
	/* 0x805: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_809:
	/* 0x809: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80e:
	/* 0x80e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_813:
	/* 0x813: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_818:
	/* 0x818: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81d:
	/* 0x81d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81f:
	/* 0x81f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_824:
	/* 0x824: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_828:
	/* 0x828: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_82d:
	/* 0x82d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_832:
	/* 0x832: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_837:
	/* 0x837: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_83c:
	/* 0x83c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83e:
	/* 0x83e: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_842:
	/* 0x842: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_846:
	/* 0x846: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_84b:
	/* 0x84b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_850:
	/* 0x850: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_855:
	/* 0x855: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_85a:
	/* 0x85a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85f:
	/* 0x85f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_864:
	/* 0x864: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_869:
	/* 0x869: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_86e:
	/* 0x86e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_873:
	/* 0x873: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_878:
	/* 0x878: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_87b:
	/* 0x87b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87d:
	/* 0x87d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_881:
	/* 0x881: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
	return 2181ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2181ULL: goto x86_l_885;
	case 2185ULL: goto x86_l_889;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2254ULL: goto x86_l_8ce;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2397ULL: goto x86_l_95d;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2462ULL: goto x86_l_99e;
	case 2466ULL: goto x86_l_9a2;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2517ULL: goto x86_l_9d5;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2587ULL: goto x86_l_a1b;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2621ULL: goto x86_l_a3d;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2631ULL: goto x86_l_a47;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2645ULL: goto x86_l_a55;
	case 2649ULL: goto x86_l_a59;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2759ULL: goto x86_l_ac7;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2783ULL: goto x86_l_adf;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3028ULL: goto x86_l_bd4;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3045ULL: goto x86_l_be5;
	case 3051ULL: goto x86_l_beb;
	case 3063ULL: goto x86_l_bf7;
	case 3071ULL: goto x86_l_bff;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3095ULL: goto x86_l_c17;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3120ULL: goto x86_l_c30;
	case 3124ULL: goto x86_l_c34;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3151ULL: goto x86_l_c4f;
	case 3159ULL: goto x86_l_c57;
	case 3167ULL: goto x86_l_c5f;
	case 3171ULL: goto x86_l_c63;
	case 3179ULL: goto x86_l_c6b;
	case 3183ULL: goto x86_l_c6f;
	case 3191ULL: goto x86_l_c77;
	case 3195ULL: goto x86_l_c7b;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3215ULL: goto x86_l_c8f;
	case 3223ULL: goto x86_l_c97;
	case 3231ULL: goto x86_l_c9f;
	case 3234ULL: goto x86_l_ca2;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3265ULL: goto x86_l_cc1;
	case 3271ULL: goto x86_l_cc7;
	case 3276ULL: goto x86_l_ccc;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3309ULL: goto x86_l_ced;
	case 3313ULL: goto x86_l_cf1;
	case 3316ULL: goto x86_l_cf4;
	case 3319ULL: goto x86_l_cf7;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3343ULL: goto x86_l_d0f;
	case 3345ULL: goto x86_l_d11;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3361ULL: goto x86_l_d21;
	case 3369ULL: goto x86_l_d29;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3396ULL: goto x86_l_d44;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3416ULL: goto x86_l_d58;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3452ULL: goto x86_l_d7c;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3464ULL: goto x86_l_d88;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3486ULL: goto x86_l_d9e;
	case 3494ULL: goto x86_l_da6;
	case 3502ULL: goto x86_l_dae;
	case 3510ULL: goto x86_l_db6;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3545ULL: goto x86_l_dd9;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3595ULL: goto x86_l_e0b;
	case 3599ULL: goto x86_l_e0f;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3607ULL: goto x86_l_e17;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3625ULL: goto x86_l_e29;
	case 3629ULL: goto x86_l_e2d;
	case 3631ULL: goto x86_l_e2f;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3666ULL: goto x86_l_e52;
	case 3669ULL: goto x86_l_e55;
	case 3671ULL: goto x86_l_e57;
	case 3676ULL: goto x86_l_e5c;
	case 3681ULL: goto x86_l_e61;
	case 3684ULL: goto x86_l_e64;
	case 3686ULL: goto x86_l_e66;
	case 3689ULL: goto x86_l_e69;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3703ULL: goto x86_l_e77;
	case 3710ULL: goto x86_l_e7e;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3734ULL: goto x86_l_e96;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3745ULL: goto x86_l_ea1;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3775ULL: goto x86_l_ebf;
	case 3778ULL: goto x86_l_ec2;
	case 3780ULL: goto x86_l_ec4;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3804ULL: goto x86_l_edc;
	case 3813ULL: goto x86_l_ee5;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3839ULL: goto x86_l_eff;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3860ULL: goto x86_l_f14;
	case 3863ULL: goto x86_l_f17;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	default: return 0xffffffffffffffffULL;
	}
x86_l_885:
	/* 0x885: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_889:
	/* 0x889: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_88d:
	/* 0x88d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_892:
	/* 0x892: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_897:
	/* 0x897: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89c:
	/* 0x89c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a1:
	/* 0x8a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a3:
	/* 0x8a3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a8:
	/* 0x8a8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8ac:
	/* 0x8ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b1:
	/* 0x8b1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8bb:
	/* 0x8bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8c0:
	/* 0x8c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c2:
	/* 0x8c2: cmp    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_8c6:
	/* 0x8c6: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8ce:
	/* 0x8ce: jne    935 <trace_execute_finished+0x935> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_935;
	}
x86_l_8d0:
	/* 0x8d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8d5:
	/* 0x8d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8da:
	/* 0x8da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8df:
	/* 0x8df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e4:
	/* 0x8e4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8e7:
	/* 0x8e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e9:
	/* 0x8e9: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ee:
	/* 0x8ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f3:
	/* 0x8f3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f8:
	/* 0x8f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fd:
	/* 0x8fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_902:
	/* 0x902: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_905:
	/* 0x905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_907:
	/* 0x907: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90b:
	/* 0x90b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_90f:
	/* 0x90f: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_913:
	/* 0x913: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_917:
	/* 0x917: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91c:
	/* 0x91c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_921:
	/* 0x921: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_926:
	/* 0x926: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_92b:
	/* 0x92b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92d:
	/* 0x92d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_931:
	/* 0x931: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_935:
	/* 0x935: mov    DWORD PTR [r13+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_939:
	/* 0x939: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_93e:
	/* 0x93e: lea    r15,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_946:
	/* 0x946: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_94b:
	/* 0x94b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_950:
	/* 0x950: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_955:
	/* 0x955: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95a:
	/* 0x95a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_95d:
	/* 0x95d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95f:
	/* 0x95f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_964:
	/* 0x964: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_968:
	/* 0x968: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96d:
	/* 0x96d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_972:
	/* 0x972: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_977:
	/* 0x977: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_97c:
	/* 0x97c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97e:
	/* 0x97e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_983:
	/* 0x983: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_988:
	/* 0x988: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_98d:
	/* 0x98d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_992:
	/* 0x992: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_997:
	/* 0x997: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_99c:
	/* 0x99c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99e:
	/* 0x99e: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a2:
	/* 0x9a2: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_9a6:
	/* 0x9a6: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_9ab:
	/* 0x9ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ad:
	/* 0x9ad: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9b1:
	/* 0x9b1: lea    rdx,[r12+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9b6:
	/* 0x9b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9bb:
	/* 0x9bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c0:
	/* 0x9c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c5:
	/* 0x9c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ca:
	/* 0x9ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cc:
	/* 0x9cc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d1:
	/* 0x9d1: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d5:
	/* 0x9d5: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9dd:
	/* 0x9dd: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9e1:
	/* 0x9e1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e6:
	/* 0x9e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9eb:
	/* 0x9eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f0:
	/* 0x9f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f5:
	/* 0x9f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f7:
	/* 0x9f7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9fc:
	/* 0x9fc: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a00:
	/* 0xa00: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a04:
	/* 0xa04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a09:
	/* 0xa09: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a0e:
	/* 0xa0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a13:
	/* 0xa13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a18:
	/* 0xa18: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a1b:
	/* 0xa1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1d:
	/* 0xa1d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a22:
	/* 0xa22: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a26:
	/* 0xa26: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a2b:
	/* 0xa2b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a35:
	/* 0xa35: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a3a:
	/* 0xa3a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a3d:
	/* 0xa3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3f:
	/* 0xa3f: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_a44:
	/* 0xa44: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_a47:
	/* 0xa47: je     a4d <trace_execute_finished+0xa4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4d;
	}
x86_l_a49:
	/* 0xa49: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a55:
	/* 0xa55: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a59:
	/* 0xa59: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a61:
	/* 0xa61: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a66:
	/* 0xa66: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a6b:
	/* 0xa6b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a70:
	/* 0xa70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a72:
	/* 0xa72: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a77:
	/* 0xa77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a7c:
	/* 0xa7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a81:
	/* 0xa81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a86:
	/* 0xa86: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a89:
	/* 0xa89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8b:
	/* 0xa8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a90:
	/* 0xa90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a95:
	/* 0xa95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a9a:
	/* 0xa9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a9f:
	/* 0xa9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa4:
	/* 0xaa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa6:
	/* 0xaa6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aab:
	/* 0xaab: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab0:
	/* 0xab0: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_ab5:
	/* 0xab5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aba:
	/* 0xaba: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_abd:
	/* 0xabd: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_ac2:
	/* 0xac2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac4:
	/* 0xac4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_acb:
	/* 0xacb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ad0:
	/* 0xad0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_ad5:
	/* 0xad5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ada:
	/* 0xada: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adf:
	/* 0xadf: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae3:
	/* 0xae3: mov    rbx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ae8:
	/* 0xae8: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_aed:
	/* 0xaed: je     296 <trace_execute_finished+0x296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 662ULL;
	}
x86_l_af3:
	/* 0xaf3: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_af8:
	/* 0xaf8: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b00:
	/* 0xb00: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b05:
	/* 0xb05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b0a:
	/* 0xb0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b0f:
	/* 0xb0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b14:
	/* 0xb14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b16:
	/* 0xb16: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1b:
	/* 0xb1b: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b20:
	/* 0xb20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2f:
	/* 0xb2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b34:
	/* 0xb34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b36:
	/* 0xb36: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b3b:
	/* 0xb3b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b40:
	/* 0xb40: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b45:
	/* 0xb45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b4a:
	/* 0xb4a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b4f:
	/* 0xb4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b54:
	/* 0xb54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b56:
	/* 0xb56: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5b:
	/* 0xb5b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b60:
	/* 0xb60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6a:
	/* 0xb6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6f:
	/* 0xb6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b71:
	/* 0xb71: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b76:
	/* 0xb76: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b79:
	/* 0xb79: je     b9c <trace_execute_finished+0xb9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b9c;
	}
x86_l_b7b:
	/* 0xb7b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b7f:
	/* 0xb7f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b84:
	/* 0xb84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b89:
	/* 0xb89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b8e:
	/* 0xb8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b93:
	/* 0xb93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b95:
	/* 0xb95: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9a:
	/* 0xb9a: jmp    b9e <trace_execute_finished+0xb9e> */
	goto x86_l_b9e;
x86_l_b9c:
	/* 0xb9c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9e:
	/* 0xb9e: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba3:
	/* 0xba3: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba7:
	/* 0xba7: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bab:
	/* 0xbab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_bb2:
	/* 0xbb2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb7:
	/* 0xbb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bbc:
	/* 0xbbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbe:
	/* 0xbbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc1:
	/* 0xbc1: je     bda <trace_execute_finished+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bda;
	}
x86_l_bc3:
	/* 0xbc3: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_bc6:
	/* 0xbc6: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_bcc:
	/* 0xbcc: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_bcf:
	/* 0xbcf: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_bd2:
	/* 0xbd2: jne    bda <trace_execute_finished+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bda;
	}
x86_l_bd4:
	/* 0xbd4: or     BYTE PTR [r12+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_bda:
	/* 0xbda: movzx  eax,WORD PTR [r12+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_be0:
	/* 0xbe0: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_be5:
	/* 0xbe5: jne    6856 <trace_execute_finished+0x6856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26710ULL;
	}
x86_l_beb:
	/* 0xbeb: mov    QWORD PTR [r12+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_bf7:
	/* 0xbf7: mov    DWORD PTR [rsp+0x10],0x313 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719477523ULL);
x86_l_bff:
	/* 0xbff: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c04:
	/* 0xc04: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c0b:
	/* 0xc0b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c10:
	/* 0xc10: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c15:
	/* 0xc15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c17:
	/* 0xc17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1a:
	/* 0xc1a: je     c8f <trace_execute_finished+0xc8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8f;
	}
x86_l_c1c:
	/* 0xc1c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c1f:
	/* 0xc1f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c24:
	/* 0xc24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c29:
	/* 0xc29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2b:
	/* 0xc2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c2e:
	/* 0xc2e: je     c8f <trace_execute_finished+0xc8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8f;
	}
x86_l_c30:
	/* 0xc30: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c34:
	/* 0xc34: mov    QWORD PTR [r12+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c3c:
	/* 0xc3c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3f:
	/* 0xc3f: mov    QWORD PTR [r12+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c47:
	/* 0xc47: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c4b:
	/* 0xc4b: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c4f:
	/* 0xc4f: mov    QWORD PTR [r12+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_c57:
	/* 0xc57: mov    QWORD PTR [r12+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_c5f:
	/* 0xc5f: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c63:
	/* 0xc63: mov    QWORD PTR [r12+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_c6b:
	/* 0xc6b: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6f:
	/* 0xc6f: mov    QWORD PTR [r12+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_c77:
	/* 0xc77: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c7b:
	/* 0xc7b: mov    QWORD PTR [r12+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_c83:
	/* 0xc83: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c87:
	/* 0xc87: mov    QWORD PTR [r12+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_c8f:
	/* 0xc8f: mov    rdx,QWORD PTR [r12+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c97:
	/* 0xc97: mov    QWORD PTR [r12+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c9f:
	/* 0xc9f: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca2:
	/* 0xca2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca4:
	/* 0xca4: cmp    ecx,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_ca9:
	/* 0xca9: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cb1:
	/* 0xcb1: jne    ccc <trace_execute_finished+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ccc;
	}
x86_l_cb3:
	/* 0xcb3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb6:
	/* 0xcb6: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_cb9:
	/* 0xcb9: mov    QWORD PTR [r12+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cc1:
	/* 0xcc1: jne    14f7 <trace_execute_finished+0x14f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5367ULL;
	}
x86_l_cc7:
	/* 0xcc7: jmp    1f9e <trace_execute_finished+0x1f9e> */
	return 8094ULL;
x86_l_ccc:
	/* 0xccc: mov    rax,QWORD PTR [r12+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_cd4:
	/* 0xcd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd7:
	/* 0xcd7: je     e77 <trace_execute_finished+0xe77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e77;
	}
x86_l_cdd:
	/* 0xcdd: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_ce4:
	/* 0xce4: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_ce7:
	/* 0xce7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cea:
	/* 0xcea: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_ced:
	/* 0xced: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_cf1:
	/* 0xcf1: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cf4:
	/* 0xcf4: neg    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cf7:
	/* 0xcf7: xor    r14,QWORD PTR [r12+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_cff:
	/* 0xcff: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d02:
	/* 0xd02: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d0a:
	/* 0xd0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: je     d2f <trace_execute_finished+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2f;
	}
x86_l_d0f:
	/* 0xd0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d11:
	/* 0xd11: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d18:
	/* 0xd18: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d1b:
	/* 0xd1b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d1e:
	/* 0xd1e: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d21:
	/* 0xd21: xor    rcx,QWORD PTR [r12+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d29:
	/* 0xd29: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d2c:
	/* 0xd2c: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d2f:
	/* 0xd2f: mov    rax,QWORD PTR [r12+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d37:
	/* 0xd37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3a:
	/* 0xd3a: je     d58 <trace_execute_finished+0xd58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d58;
	}
x86_l_d3c:
	/* 0xd3c: mov    ecx,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d41:
	/* 0xd41: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d44:
	/* 0xd44: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d47:
	/* 0xd47: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d4a:
	/* 0xd4a: xor    rcx,QWORD PTR [r12+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d52:
	/* 0xd52: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d55:
	/* 0xd55: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d58:
	/* 0xd58: mov    rax,QWORD PTR [r12+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d60:
	/* 0xd60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d63:
	/* 0xd63: mov    QWORD PTR [rsp+0x78],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d68:
	/* 0xd68: je     d82 <trace_execute_finished+0xd82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d82;
	}
x86_l_d6a:
	/* 0xd6a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d6d:
	/* 0xd6d: movsx  rcx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d71:
	/* 0xd71: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d74:
	/* 0xd74: xor    rcx,QWORD PTR [r12+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_d7c:
	/* 0xd7c: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d7f:
	/* 0xd7f: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d82:
	/* 0xd82: movzx  eax,WORD PTR [r12+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_d88:
	/* 0xd88: mov    r15,QWORD PTR [r12+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_d90:
	/* 0xd90: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d93:
	/* 0xd93: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d98:
	/* 0xd98: je     edc <trace_execute_finished+0xedc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edc;
	}
x86_l_d9e:
	/* 0xd9e: mov    rcx,QWORD PTR [r12+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_da6:
	/* 0xda6: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_dae:
	/* 0xdae: mov    r13,QWORD PTR [r12+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_db6:
	/* 0xdb6: mov    rcx,QWORD PTR [r12+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_dbe:
	/* 0xdbe: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dc3:
	/* 0xdc3: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc8:
	/* 0xdc8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_dcf:
	/* 0xdcf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd4:
	/* 0xdd4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd9:
	/* 0xdd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddb:
	/* 0xddb: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_de3:
	/* 0xde3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de8:
	/* 0xde8: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_def:
	/* 0xdef: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: je     e14 <trace_execute_finished+0xe14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e14;
	}
x86_l_df4:
	/* 0xdf4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df9:
	/* 0xdf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dfe:
	/* 0xdfe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e01:
	/* 0xe01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e03:
	/* 0xe03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e06:
	/* 0xe06: je     e14 <trace_execute_finished+0xe14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e14;
	}
x86_l_e08:
	/* 0xe08: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e0b:
	/* 0xe0b: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0f:
	/* 0xe0f: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e12:
	/* 0xe12: jmp    e17 <trace_execute_finished+0xe17> */
	goto x86_l_e17;
x86_l_e14:
	/* 0xe14: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e17:
	/* 0xe17: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e1c:
	/* 0xe1c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e21:
	/* 0xe21: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e24:
	/* 0xe24: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e27:
	/* 0xe27: jb     e3f <trace_execute_finished+0xe3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e3f;
	}
x86_l_e29:
	/* 0xe29: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e2d:
	/* 0xe2d: je     e34 <trace_execute_finished+0xe34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e34;
	}
x86_l_e2f:
	/* 0xe2f: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e32:
	/* 0xe32: jbe    e3f <trace_execute_finished+0xe3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e3f;
	}
x86_l_e34:
	/* 0xe34: and    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 160ULL);
x86_l_e3c:
	/* 0xe3c: or     r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e3f:
	/* 0xe3f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e43:
	/* 0xe43: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e46:
	/* 0xe46: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4b:
	/* 0xe4b: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e52:
	/* 0xe52: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e55:
	/* 0xe55: je     e94 <trace_execute_finished+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e94;
	}
x86_l_e57:
	/* 0xe57: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5c:
	/* 0xe5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e61:
	/* 0xe61: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e64:
	/* 0xe64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e66:
	/* 0xe66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e69:
	/* 0xe69: je     ea5 <trace_execute_finished+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea5;
	}
x86_l_e6b:
	/* 0xe6b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6e:
	/* 0xe6e: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e72:
	/* 0xe72: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e75:
	/* 0xe75: jmp    ea7 <trace_execute_finished+0xea7> */
	goto x86_l_ea7;
x86_l_e77:
	/* 0xe77: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e7e:
	/* 0xe7e: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e86:
	/* 0xe86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: jne    d0f <trace_execute_finished+0xd0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d0f;
	}
x86_l_e8f:
	/* 0xe8f: jmp    d2f <trace_execute_finished+0xd2f> */
	goto x86_l_d2f;
x86_l_e94:
	/* 0xe94: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e96:
	/* 0xe96: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e99:
	/* 0xe99: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9e:
	/* 0xe9e: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_ea1:
	/* 0xea1: jae    eb9 <trace_execute_finished+0xeb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_eb9;
	}
x86_l_ea3:
	/* 0xea3: jmp    ecf <trace_execute_finished+0xecf> */
	goto x86_l_ecf;
x86_l_ea5:
	/* 0xea5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea7:
	/* 0xea7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_eac:
	/* 0xeac: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eaf:
	/* 0xeaf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb4:
	/* 0xeb4: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: jb     ecf <trace_execute_finished+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ecf;
	}
x86_l_eb9:
	/* 0xeb9: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ebd:
	/* 0xebd: je     ec4 <trace_execute_finished+0xec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec4;
	}
x86_l_ebf:
	/* 0xebf: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ec2:
	/* 0xec2: jbe    ecf <trace_execute_finished+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ecf;
	}
x86_l_ec4:
	/* 0xec4: and    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 160ULL);
x86_l_ecc:
	/* 0xecc: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_ecf:
	/* 0xecf: or     r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed2:
	/* 0xed2: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed5:
	/* 0xed5: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_ed8:
	/* 0xed8: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_edc:
	/* 0xedc: cmp    QWORD PTR [r12+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_ee5:
	/* 0xee5: je     f8a <trace_execute_finished+0xf8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3978ULL;
	}
x86_l_eeb:
	/* 0xeeb: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_ef0:
	/* 0xef0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef2:
	/* 0xef2: mov    DWORD PTR [r12+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef7:
	/* 0xef7: mov    rbx,QWORD PTR [r12+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_eff:
	/* 0xeff: mov    rax,QWORD PTR [r12+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f07:
	/* 0xf07: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f0c:
	/* 0xf0c: mov    r13,QWORD PTR [r12+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f14:
	/* 0xf14: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_f17:
	/* 0xf17: mov    r12,QWORD PTR [r12+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f1f:
	/* 0xf1f: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_f24:
	/* 0xf24: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 3881ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3906ULL: goto x86_l_f42;
	case 3911ULL: goto x86_l_f47;
	case 3918ULL: goto x86_l_f4e;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3954ULL: goto x86_l_f72;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3976ULL: goto x86_l_f88;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4004ULL: goto x86_l_fa4;
	case 4010ULL: goto x86_l_faa;
	case 4012ULL: goto x86_l_fac;
	case 4015ULL: goto x86_l_faf;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4035ULL: goto x86_l_fc3;
	case 4044ULL: goto x86_l_fcc;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4165ULL: goto x86_l_1045;
	case 4173ULL: goto x86_l_104d;
	case 4179ULL: goto x86_l_1053;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4199ULL: goto x86_l_1067;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4207ULL: goto x86_l_106f;
	case 4214ULL: goto x86_l_1076;
	case 4217ULL: goto x86_l_1079;
	case 4219ULL: goto x86_l_107b;
	case 4223ULL: goto x86_l_107f;
	case 4228ULL: goto x86_l_1084;
	case 4230ULL: goto x86_l_1086;
	case 4233ULL: goto x86_l_1089;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	case 4242ULL: goto x86_l_1092;
	case 4245ULL: goto x86_l_1095;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4261ULL: goto x86_l_10a5;
	case 4265ULL: goto x86_l_10a9;
	case 4274ULL: goto x86_l_10b2;
	case 4280ULL: goto x86_l_10b8;
	case 4288ULL: goto x86_l_10c0;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4334ULL: goto x86_l_10ee;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4348ULL: goto x86_l_10fc;
	case 4352ULL: goto x86_l_1100;
	case 4356ULL: goto x86_l_1104;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4430ULL: goto x86_l_114e;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4464ULL: goto x86_l_1170;
	case 4466ULL: goto x86_l_1172;
	case 4469ULL: goto x86_l_1175;
	case 4472ULL: goto x86_l_1178;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4503ULL: goto x86_l_1197;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4517ULL: goto x86_l_11a5;
	case 4520ULL: goto x86_l_11a8;
	case 4523ULL: goto x86_l_11ab;
	case 4526ULL: goto x86_l_11ae;
	case 4530ULL: goto x86_l_11b2;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4663ULL: goto x86_l_1237;
	case 4665ULL: goto x86_l_1239;
	case 4673ULL: goto x86_l_1241;
	case 4681ULL: goto x86_l_1249;
	case 4687ULL: goto x86_l_124f;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4742ULL: goto x86_l_1286;
	case 4746ULL: goto x86_l_128a;
	case 4749ULL: goto x86_l_128d;
	case 4751ULL: goto x86_l_128f;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4823ULL: goto x86_l_12d7;
	case 4831ULL: goto x86_l_12df;
	case 4837ULL: goto x86_l_12e5;
	case 4844ULL: goto x86_l_12ec;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4882ULL: goto x86_l_1312;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4912ULL: goto x86_l_1330;
	case 4915ULL: goto x86_l_1333;
	case 4919ULL: goto x86_l_1337;
	case 4925ULL: goto x86_l_133d;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4947ULL: goto x86_l_1353;
	case 4955ULL: goto x86_l_135b;
	case 4961ULL: goto x86_l_1361;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4981ULL: goto x86_l_1375;
	case 4983ULL: goto x86_l_1377;
	case 4990ULL: goto x86_l_137e;
	case 4993ULL: goto x86_l_1381;
	case 4995ULL: goto x86_l_1383;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5022ULL: goto x86_l_139e;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5032ULL: goto x86_l_13a8;
	case 5035ULL: goto x86_l_13ab;
	case 5038ULL: goto x86_l_13ae;
	case 5041ULL: goto x86_l_13b1;
	case 5045ULL: goto x86_l_13b5;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5058ULL: goto x86_l_13c2;
	case 5066ULL: goto x86_l_13ca;
	case 5072ULL: goto x86_l_13d0;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5092ULL: goto x86_l_13e4;
	case 5094ULL: goto x86_l_13e6;
	case 5097ULL: goto x86_l_13e9;
	case 5100ULL: goto x86_l_13ec;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5142ULL: goto x86_l_1416;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5151ULL: goto x86_l_141f;
	case 5154ULL: goto x86_l_1422;
	case 5158ULL: goto x86_l_1426;
	case 5166ULL: goto x86_l_142e;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5183ULL: goto x86_l_143f;
	case 5189ULL: goto x86_l_1445;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5211ULL: goto x86_l_145b;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5223ULL: goto x86_l_1467;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5248ULL: goto x86_l_1480;
	case 5250ULL: goto x86_l_1482;
	case 5255ULL: goto x86_l_1487;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5267ULL: goto x86_l_1493;
	case 5269ULL: goto x86_l_1495;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5288ULL: goto x86_l_14a8;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5297ULL: goto x86_l_14b1;
	case 5300ULL: goto x86_l_14b4;
	case 5304ULL: goto x86_l_14b8;
	case 5312ULL: goto x86_l_14c0;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5342ULL: goto x86_l_14de;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5361ULL: goto x86_l_14f1;
	case 5367ULL: goto x86_l_14f7;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5434ULL: goto x86_l_153a;
	case 5436ULL: goto x86_l_153c;
	case 5441ULL: goto x86_l_1541;
	case 5443ULL: goto x86_l_1543;
	case 5447ULL: goto x86_l_1547;
	case 5449ULL: goto x86_l_1549;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f29:
	/* 0xf29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f30:
	/* 0xf30: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f35:
	/* 0xf35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3a:
	/* 0xf3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3c:
	/* 0xf3c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f42:
	/* 0xf42: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f47:
	/* 0xf47: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f4e:
	/* 0xf4e: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_f51:
	/* 0xf51: je     f70 <trace_execute_finished+0xf70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f70;
	}
x86_l_f53:
	/* 0xf53: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f58:
	/* 0xf58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5d:
	/* 0xf5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5f:
	/* 0xf5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: je     f70 <trace_execute_finished+0xf70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f70;
	}
x86_l_f64:
	/* 0xf64: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f67:
	/* 0xf67: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6b:
	/* 0xf6b: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f6e:
	/* 0xf6e: jmp    f72 <trace_execute_finished+0xf72> */
	goto x86_l_f72;
x86_l_f70:
	/* 0xf70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f72:
	/* 0xf72: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f75:
	/* 0xf75: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7a:
	/* 0xf7a: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f7d:
	/* 0xf7d: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: jae    fa0 <trace_execute_finished+0xfa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_fa0;
	}
x86_l_f82:
	/* 0xf82: movzx  r13d,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_f88:
	/* 0xf88: jmp    fb9 <trace_execute_finished+0xfb9> */
	goto x86_l_fb9;
x86_l_f8a:
	/* 0xf8a: movzx  r13d,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_f90:
	/* 0xf90: cmp    QWORD PTR [r12+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_f99:
	/* 0xf99: jne    fd2 <trace_execute_finished+0xfd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fd2;
	}
x86_l_f9b:
	/* 0xf9b: jmp    10a9 <trace_execute_finished+0x10a9> */
	goto x86_l_10a9;
x86_l_fa0:
	/* 0xfa0: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fa4:
	/* 0xfa4: movzx  r13d,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_faa:
	/* 0xfaa: je     fb1 <trace_execute_finished+0xfb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb1;
	}
x86_l_fac:
	/* 0xfac: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_faf:
	/* 0xfaf: jbe    fb9 <trace_execute_finished+0xfb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fb9;
	}
x86_l_fb1:
	/* 0xfb1: and    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_fb6:
	/* 0xfb6: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_fb9:
	/* 0xfb9: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_fbc:
	/* 0xfbc: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_fbf:
	/* 0xfbf: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc3:
	/* 0xfc3: cmp    QWORD PTR [r12+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_fcc:
	/* 0xfcc: je     10a9 <trace_execute_finished+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_fd2:
	/* 0xfd2: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_fd7:
	/* 0xfd7: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_fdf:
	/* 0xfdf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe4:
	/* 0xfe4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fe9:
	/* 0xfe9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fee:
	/* 0xfee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ffa:
	/* 0xffa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ffe:
	/* 0xffe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1003:
	/* 0x1003: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1008:
	/* 0x1008: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_100d:
	/* 0x100d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1012:
	/* 0x1012: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1014:
	/* 0x1014: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1019:
	/* 0x1019: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101e:
	/* 0x101e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1023:
	/* 0x1023: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1028:
	/* 0x1028: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_102d:
	/* 0x102d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1032:
	/* 0x1032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1034:
	/* 0x1034: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1038:
	/* 0x1038: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_103d:
	/* 0x103d: mov    rbx,QWORD PTR [r12+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1045:
	/* 0x1045: mov    r15,QWORD PTR [r12+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_104d:
	/* 0x104d: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1053:
	/* 0x1053: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_105a:
	/* 0x105a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105f:
	/* 0x105f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1064:
	/* 0x1064: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1067:
	/* 0x1067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1069:
	/* 0x1069: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_106c:
	/* 0x106c: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_106f:
	/* 0x106f: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1076:
	/* 0x1076: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_1079:
	/* 0x1079: je     1097 <trace_execute_finished+0x1097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1097;
	}
x86_l_107b:
	/* 0x107b: lea    rsi,[rax+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_107f:
	/* 0x107f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1084:
	/* 0x1084: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1086:
	/* 0x1086: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1089:
	/* 0x1089: je     1097 <trace_execute_finished+0x1097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1097;
	}
x86_l_108b:
	/* 0x108b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108e:
	/* 0x108e: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1092:
	/* 0x1092: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1095:
	/* 0x1095: jmp    1099 <trace_execute_finished+0x1099> */
	goto x86_l_1099;
x86_l_1097:
	/* 0x1097: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1099:
	/* 0x1099: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_109c:
	/* 0x109c: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_109f:
	/* 0x109f: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10a2:
	/* 0x10a2: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_10a5:
	/* 0x10a5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a9:
	/* 0x10a9: cmp    QWORD PTR [r12+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_10b2:
	/* 0x10b2: je     11b2 <trace_execute_finished+0x11b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b2;
	}
x86_l_10b8:
	/* 0x10b8: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_10c0:
	/* 0x10c0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10c4:
	/* 0x10c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c9:
	/* 0x10c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10ce:
	/* 0x10ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d3:
	/* 0x10d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d8:
	/* 0x10d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10da:
	/* 0x10da: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10df:
	/* 0x10df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e4:
	/* 0x10e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10e9:
	/* 0x10e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ee:
	/* 0x10ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10f3:
	/* 0x10f3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f8:
	/* 0x10f8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10fc:
	/* 0x10fc: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1100:
	/* 0x1100: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1104:
	/* 0x1104: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1108:
	/* 0x1108: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110d:
	/* 0x110d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1112:
	/* 0x1112: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1117:
	/* 0x1117: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_111c:
	/* 0x111c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111e:
	/* 0x111e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1123:
	/* 0x1123: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1127:
	/* 0x1127: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112c:
	/* 0x112c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1131:
	/* 0x1131: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1136:
	/* 0x1136: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_113b:
	/* 0x113b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113d:
	/* 0x113d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1141:
	/* 0x1141: mov    DWORD PTR [r12+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1146:
	/* 0x1146: mov    rbx,QWORD PTR [r12+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_114e:
	/* 0x114e: mov    r15,QWORD PTR [r12+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1156:
	/* 0x1156: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115c:
	/* 0x115c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1163:
	/* 0x1163: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1168:
	/* 0x1168: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116d:
	/* 0x116d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1170:
	/* 0x1170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1172:
	/* 0x1172: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1175:
	/* 0x1175: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1178:
	/* 0x1178: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_117f:
	/* 0x117f: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_1182:
	/* 0x1182: je     11a0 <trace_execute_finished+0x11a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a0;
	}
x86_l_1184:
	/* 0x1184: lea    rsi,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1188:
	/* 0x1188: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_118d:
	/* 0x118d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118f:
	/* 0x118f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: je     11a0 <trace_execute_finished+0x11a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a0;
	}
x86_l_1194:
	/* 0x1194: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1197:
	/* 0x1197: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119b:
	/* 0x119b: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_119e:
	/* 0x119e: jmp    11a2 <trace_execute_finished+0x11a2> */
	goto x86_l_11a2;
x86_l_11a0:
	/* 0x11a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a2:
	/* 0x11a2: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11a5:
	/* 0x11a5: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_11a8:
	/* 0x11a8: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ab:
	/* 0x11ab: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_11ae:
	/* 0x11ae: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b2:
	/* 0x11b2: cmp    QWORD PTR [r12+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11bb:
	/* 0x11bb: je     12a7 <trace_execute_finished+0x12a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a7;
	}
x86_l_11c1:
	/* 0x11c1: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11c6:
	/* 0x11c6: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_11ce:
	/* 0x11ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d3:
	/* 0x11d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11d8:
	/* 0x11d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11dd:
	/* 0x11dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11e2:
	/* 0x11e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e4:
	/* 0x11e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11e9:
	/* 0x11e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ee:
	/* 0x11ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11f3:
	/* 0x11f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11f8:
	/* 0x11f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11fd:
	/* 0x11fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ff:
	/* 0x11ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1204:
	/* 0x1204: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1209:
	/* 0x1209: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_120e:
	/* 0x120e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1213:
	/* 0x1213: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1216:
	/* 0x1216: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_121b:
	/* 0x121b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121d:
	/* 0x121d: lea    rbx,[r12+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1222:
	/* 0x1222: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1227:
	/* 0x1227: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_122c:
	/* 0x122c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_122f:
	/* 0x122f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1234:
	/* 0x1234: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1237:
	/* 0x1237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1239:
	/* 0x1239: mov    r15,QWORD PTR [r12+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1241:
	/* 0x1241: mov    r12,QWORD PTR [r12+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1249:
	/* 0x1249: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_124f:
	/* 0x124f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1256:
	/* 0x1256: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_125b:
	/* 0x125b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1260:
	/* 0x1260: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1263:
	/* 0x1263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1265:
	/* 0x1265: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_126c:
	/* 0x126c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_126f:
	/* 0x126f: je     128f <trace_execute_finished+0x128f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128f;
	}
x86_l_1271:
	/* 0x1271: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1274:
	/* 0x1274: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1279:
	/* 0x1279: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_127c:
	/* 0x127c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127e:
	/* 0x127e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1281:
	/* 0x1281: je     128f <trace_execute_finished+0x128f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128f;
	}
x86_l_1283:
	/* 0x1283: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1286:
	/* 0x1286: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128a:
	/* 0x128a: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_128d:
	/* 0x128d: jmp    1291 <trace_execute_finished+0x1291> */
	goto x86_l_1291;
x86_l_128f:
	/* 0x128f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1291:
	/* 0x1291: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1294:
	/* 0x1294: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1297:
	/* 0x1297: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_129a:
	/* 0x129a: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_129d:
	/* 0x129d: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a1:
	/* 0x12a1: movzx  r13d,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_12a7:
	/* 0x12a7: cmp    QWORD PTR [r12+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12b0:
	/* 0x12b0: je     133d <trace_execute_finished+0x133d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133d;
	}
x86_l_12b6:
	/* 0x12b6: lea    rbx,[r12+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12bb:
	/* 0x12bb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12c0:
	/* 0x12c0: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12c5:
	/* 0x12c5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c8:
	/* 0x12c8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: mov    r15,QWORD PTR [r12+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12d7:
	/* 0x12d7: mov    r12,QWORD PTR [r12+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12df:
	/* 0x12df: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e5:
	/* 0x12e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12ec:
	/* 0x12ec: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12f1:
	/* 0x12f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f6:
	/* 0x12f6: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12f9:
	/* 0x12f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fb:
	/* 0x12fb: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1302:
	/* 0x1302: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1305:
	/* 0x1305: je     1325 <trace_execute_finished+0x1325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1325;
	}
x86_l_1307:
	/* 0x1307: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130f:
	/* 0x130f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1312:
	/* 0x1312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1314:
	/* 0x1314: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1317:
	/* 0x1317: je     1325 <trace_execute_finished+0x1325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1325;
	}
x86_l_1319:
	/* 0x1319: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131c:
	/* 0x131c: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1320:
	/* 0x1320: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1323:
	/* 0x1323: jmp    1327 <trace_execute_finished+0x1327> */
	goto x86_l_1327;
x86_l_1325:
	/* 0x1325: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1327:
	/* 0x1327: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_132a:
	/* 0x132a: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_132d:
	/* 0x132d: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1330:
	/* 0x1330: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1333:
	/* 0x1333: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1337:
	/* 0x1337: movzx  r13d,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_133d:
	/* 0x133d: mov    rbx,QWORD PTR [r12+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1345:
	/* 0x1345: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1348:
	/* 0x1348: je     13b5 <trace_execute_finished+0x13b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b5;
	}
x86_l_134a:
	/* 0x134a: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134f:
	/* 0x134f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1353:
	/* 0x1353: mov    r15,QWORD PTR [r12+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_135b:
	/* 0x135b: mov    WORD PTR [rsp+0x8],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1361:
	/* 0x1361: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1368:
	/* 0x1368: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136d:
	/* 0x136d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1372:
	/* 0x1372: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1375:
	/* 0x1375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1377:
	/* 0x1377: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_137e:
	/* 0x137e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1381:
	/* 0x1381: je     13a3 <trace_execute_finished+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a3;
	}
x86_l_1383:
	/* 0x1383: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1386:
	/* 0x1386: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138b:
	/* 0x138b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1390:
	/* 0x1390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1392:
	/* 0x1392: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: je     13a3 <trace_execute_finished+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a3;
	}
x86_l_1397:
	/* 0x1397: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139a:
	/* 0x139a: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139e:
	/* 0x139e: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13a1:
	/* 0x13a1: jmp    13a5 <trace_execute_finished+0x13a5> */
	goto x86_l_13a5;
x86_l_13a3:
	/* 0x13a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a5:
	/* 0x13a5: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13a8:
	/* 0x13a8: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_13ab:
	/* 0x13ab: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ae:
	/* 0x13ae: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13b1:
	/* 0x13b1: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b5:
	/* 0x13b5: mov    rbx,QWORD PTR [r12+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13bd:
	/* 0x13bd: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13c0:
	/* 0x13c0: je     1426 <trace_execute_finished+0x1426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1426;
	}
x86_l_13c2:
	/* 0x13c2: mov    r15,QWORD PTR [r12+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13ca:
	/* 0x13ca: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13d0:
	/* 0x13d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13d7:
	/* 0x13d7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13dc:
	/* 0x13dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e1:
	/* 0x13e1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13e4:
	/* 0x13e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e6:
	/* 0x13e6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13e9:
	/* 0x13e9: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_13ec:
	/* 0x13ec: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13f3:
	/* 0x13f3: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_13f6:
	/* 0x13f6: je     1414 <trace_execute_finished+0x1414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1414;
	}
x86_l_13f8:
	/* 0x13f8: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13fc:
	/* 0x13fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1401:
	/* 0x1401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1403:
	/* 0x1403: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1406:
	/* 0x1406: je     1414 <trace_execute_finished+0x1414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1414;
	}
x86_l_1408:
	/* 0x1408: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_140b:
	/* 0x140b: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140f:
	/* 0x140f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1412:
	/* 0x1412: jmp    1416 <trace_execute_finished+0x1416> */
	goto x86_l_1416;
x86_l_1414:
	/* 0x1414: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1416:
	/* 0x1416: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1419:
	/* 0x1419: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_141c:
	/* 0x141c: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_141f:
	/* 0x141f: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1422:
	/* 0x1422: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1426:
	/* 0x1426: mov    r15,QWORD PTR [r12+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_142e:
	/* 0x142e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1431:
	/* 0x1431: je     14b8 <trace_execute_finished+0x14b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b8;
	}
x86_l_1437:
	/* 0x1437: mov    r12,QWORD PTR [r12+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_143f:
	/* 0x143f: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1445:
	/* 0x1445: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_144c:
	/* 0x144c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1451:
	/* 0x1451: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1456:
	/* 0x1456: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1462:
	/* 0x1462: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1465:
	/* 0x1465: je     14a6 <trace_execute_finished+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a6;
	}
x86_l_1467:
	/* 0x1467: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_146a:
	/* 0x146a: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_146f:
	/* 0x146f: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1473:
	/* 0x1473: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1478:
	/* 0x1478: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_147b:
	/* 0x147b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147d:
	/* 0x147d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1480:
	/* 0x1480: jne    149a <trace_execute_finished+0x149a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_149a;
	}
x86_l_1482:
	/* 0x1482: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1487:
	/* 0x1487: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_148b:
	/* 0x148b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1490:
	/* 0x1490: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1493:
	/* 0x1493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1495:
	/* 0x1495: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1498:
	/* 0x1498: je     14a6 <trace_execute_finished+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a6;
	}
x86_l_149a:
	/* 0x149a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149d:
	/* 0x149d: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a1:
	/* 0x14a1: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14a4:
	/* 0x14a4: jmp    14a8 <trace_execute_finished+0x14a8> */
	goto x86_l_14a8;
x86_l_14a6:
	/* 0x14a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a8:
	/* 0x14a8: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_14ab:
	/* 0x14ab: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_14ae:
	/* 0x14ae: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14b1:
	/* 0x14b1: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_14b4:
	/* 0x14b4: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b8:
	/* 0x14b8: mov    rdx,QWORD PTR [r12+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14c0:
	/* 0x14c0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_14c3:
	/* 0x14c3: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14c8:
	/* 0x14c8: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_14cd:
	/* 0x14cd: je     14d6 <trace_execute_finished+0x14d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d6;
	}
x86_l_14cf:
	/* 0x14cf: and    rdx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14d3:
	/* 0x14d3: or     r14,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d6:
	/* 0x14d6: and    r14,QWORD PTR [r12+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14de:
	/* 0x14de: mov    rdx,QWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14e6:
	/* 0x14e6: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_14e9:
	/* 0x14e9: mov    QWORD PTR [r12+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14f1:
	/* 0x14f1: je     1f9e <trace_execute_finished+0x1f9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8094ULL;
	}
x86_l_14f7:
	/* 0x14f7: lea    r14,[r12+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_14ff:
	/* 0x14ff: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_1504:
	/* 0x1504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1506:
	/* 0x1506: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1509:
	/* 0x1509: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_150e:
	/* 0x150e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1510:
	/* 0x1510: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: cmp    DWORD PTR [r12+0x74],0x142 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206658ULL);
x86_l_151c:
	/* 0x151c: jne    1549 <trace_execute_finished+0x1549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1549;
	}
x86_l_151e:
	/* 0x151e: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1526:
	/* 0x1526: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152b:
	/* 0x152b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1530:
	/* 0x1530: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1535:
	/* 0x1535: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_153a:
	/* 0x153a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153c:
	/* 0x153c: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1541:
	/* 0x1541: jne    1574 <trace_execute_finished+0x1574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5492ULL;
	}
x86_l_1543:
	/* 0x1543: lea    rax,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1547:
	/* 0x1547: jmp    1581 <trace_execute_finished+0x1581> */
	return 5505ULL;
x86_l_1549:
	/* 0x1549: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1551:
	/* 0x1551: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1556:
	/* 0x1556: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_155b:
	/* 0x155b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1560:
	/* 0x1560: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 5477ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5477ULL: goto x86_l_1565;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5492ULL: goto x86_l_1574;
	case 5495ULL: goto x86_l_1577;
	case 5501ULL: goto x86_l_157d;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5512ULL: goto x86_l_1588;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5549ULL: goto x86_l_15ad;
	case 5553ULL: goto x86_l_15b1;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5564ULL: goto x86_l_15bc;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5608ULL: goto x86_l_15e8;
	case 5612ULL: goto x86_l_15ec;
	case 5614ULL: goto x86_l_15ee;
	case 5617ULL: goto x86_l_15f1;
	case 5623ULL: goto x86_l_15f7;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5670ULL: goto x86_l_1626;
	case 5672ULL: goto x86_l_1628;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5689ULL: goto x86_l_1639;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5722ULL: goto x86_l_165a;
	case 5724ULL: goto x86_l_165c;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5791ULL: goto x86_l_169f;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5803ULL: goto x86_l_16ab;
	case 5809ULL: goto x86_l_16b1;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5853ULL: goto x86_l_16dd;
	case 5857ULL: goto x86_l_16e1;
	case 5859ULL: goto x86_l_16e3;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5876ULL: goto x86_l_16f4;
	case 5880ULL: goto x86_l_16f8;
	case 5884ULL: goto x86_l_16fc;
	case 5891ULL: goto x86_l_1703;
	case 5893ULL: goto x86_l_1705;
	case 5902ULL: goto x86_l_170e;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5915ULL: goto x86_l_171b;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5944ULL: goto x86_l_1738;
	case 5947ULL: goto x86_l_173b;
	case 5949ULL: goto x86_l_173d;
	case 5953ULL: goto x86_l_1741;
	case 5962ULL: goto x86_l_174a;
	case 5970ULL: goto x86_l_1752;
	case 5974ULL: goto x86_l_1756;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5992ULL: goto x86_l_1768;
	case 5999ULL: goto x86_l_176f;
	case 6001ULL: goto x86_l_1771;
	case 6005ULL: goto x86_l_1775;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6039ULL: goto x86_l_1797;
	case 6043ULL: goto x86_l_179b;
	case 6052ULL: goto x86_l_17a4;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6086ULL: goto x86_l_17c6;
	case 6092ULL: goto x86_l_17cc;
	case 6098ULL: goto x86_l_17d2;
	case 6107ULL: goto x86_l_17db;
	case 6116ULL: goto x86_l_17e4;
	case 6125ULL: goto x86_l_17ed;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6137ULL: goto x86_l_17f9;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6163ULL: goto x86_l_1813;
	case 6167ULL: goto x86_l_1817;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6186ULL: goto x86_l_182a;
	case 6188ULL: goto x86_l_182c;
	case 6192ULL: goto x86_l_1830;
	case 6199ULL: goto x86_l_1837;
	case 6201ULL: goto x86_l_1839;
	case 6209ULL: goto x86_l_1841;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6230ULL: goto x86_l_1856;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6256ULL: goto x86_l_1870;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6270ULL: goto x86_l_187e;
	case 6279ULL: goto x86_l_1887;
	case 6288ULL: goto x86_l_1890;
	case 6291ULL: goto x86_l_1893;
	case 6300ULL: goto x86_l_189c;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6350ULL: goto x86_l_18ce;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6362ULL: goto x86_l_18da;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6411ULL: goto x86_l_190b;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6423ULL: goto x86_l_1917;
	case 6429ULL: goto x86_l_191d;
	case 6435ULL: goto x86_l_1923;
	case 6437ULL: goto x86_l_1925;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6453ULL: goto x86_l_1935;
	case 6461ULL: goto x86_l_193d;
	case 6469ULL: goto x86_l_1945;
	case 6473ULL: goto x86_l_1949;
	case 6479ULL: goto x86_l_194f;
	case 6483ULL: goto x86_l_1953;
	case 6489ULL: goto x86_l_1959;
	case 6495ULL: goto x86_l_195f;
	case 6504ULL: goto x86_l_1968;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6525ULL: goto x86_l_197d;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6581ULL: goto x86_l_19b5;
	case 6585ULL: goto x86_l_19b9;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6611ULL: goto x86_l_19d3;
	case 6615ULL: goto x86_l_19d7;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6634ULL: goto x86_l_19ea;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6642ULL: goto x86_l_19f2;
	case 6646ULL: goto x86_l_19f6;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6660ULL: goto x86_l_1a04;
	case 6666ULL: goto x86_l_1a0a;
	case 6668ULL: goto x86_l_1a0c;
	case 6676ULL: goto x86_l_1a14;
	case 6684ULL: goto x86_l_1a1c;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6701ULL: goto x86_l_1a2d;
	case 6705ULL: goto x86_l_1a31;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6723ULL: goto x86_l_1a43;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6735ULL: goto x86_l_1a4f;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6764ULL: goto x86_l_1a6c;
	case 6767ULL: goto x86_l_1a6f;
	case 6769ULL: goto x86_l_1a71;
	case 6772ULL: goto x86_l_1a74;
	case 6781ULL: goto x86_l_1a7d;
	case 6789ULL: goto x86_l_1a85;
	case 6797ULL: goto x86_l_1a8d;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6885ULL: goto x86_l_1ae5;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6923ULL: goto x86_l_1b0b;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6998ULL: goto x86_l_1b56;
	case 7002ULL: goto x86_l_1b5a;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7032ULL: goto x86_l_1b78;
	case 7036ULL: goto x86_l_1b7c;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7125ULL: goto x86_l_1bd5;
	case 7129ULL: goto x86_l_1bd9;
	case 7133ULL: goto x86_l_1bdd;
	case 7137ULL: goto x86_l_1be1;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7167ULL: goto x86_l_1bff;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7237ULL: goto x86_l_1c45;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1565:
	/* 0x1565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1567:
	/* 0x1567: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_156c:
	/* 0x156c: jne    15b3 <trace_execute_finished+0x15b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15b3;
	}
x86_l_156e:
	/* 0x156e: lea    rax,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1572:
	/* 0x1572: jmp    15c0 <trace_execute_finished+0x15c0> */
	goto x86_l_15c0;
x86_l_1574:
	/* 0x1574: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1577:
	/* 0x1577: je     17ae <trace_execute_finished+0x17ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ae;
	}
x86_l_157d:
	/* 0x157d: lea    rax,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1581:
	/* 0x1581: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1584:
	/* 0x1584: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1588:
	/* 0x1588: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1590:
	/* 0x1590: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1595:
	/* 0x1595: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_159a:
	/* 0x159a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_159f:
	/* 0x159f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15a4:
	/* 0x15a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a6:
	/* 0x15a6: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_15ab:
	/* 0x15ab: jne    15ee <trace_execute_finished+0x15ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15ee;
	}
x86_l_15ad:
	/* 0x15ad: lea    rax,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15b1:
	/* 0x15b1: jmp    15fb <trace_execute_finished+0x15fb> */
	goto x86_l_15fb;
x86_l_15b3:
	/* 0x15b3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_15b6:
	/* 0x15b6: je     17b3 <trace_execute_finished+0x17b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b3;
	}
x86_l_15bc:
	/* 0x15bc: lea    rax,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15c0:
	/* 0x15c0: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c3:
	/* 0x15c3: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_15cb:
	/* 0x15cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d0:
	/* 0x15d0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15d5:
	/* 0x15d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15da:
	/* 0x15da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15df:
	/* 0x15df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e1:
	/* 0x15e1: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_15e6:
	/* 0x15e6: jne    165c <trace_execute_finished+0x165c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_165c;
	}
x86_l_15e8:
	/* 0x15e8: lea    rax,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15ec:
	/* 0x15ec: jmp    1669 <trace_execute_finished+0x1669> */
	goto x86_l_1669;
x86_l_15ee:
	/* 0x15ee: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_15f1:
	/* 0x15f1: je     17b8 <trace_execute_finished+0x17b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b8;
	}
x86_l_15f7:
	/* 0x15f7: lea    rax,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15fb:
	/* 0x15fb: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15fe:
	/* 0x15fe: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1606:
	/* 0x1606: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160b:
	/* 0x160b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1610:
	/* 0x1610: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1615:
	/* 0x1615: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_161a:
	/* 0x161a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161c:
	/* 0x161c: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1621:
	/* 0x1621: je     1628 <trace_execute_finished+0x1628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1628;
	}
x86_l_1623:
	/* 0x1623: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: je     1631 <trace_execute_finished+0x1631> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1631;
	}
x86_l_1628:
	/* 0x1628: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_162c:
	/* 0x162c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1631:
	/* 0x1631: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1639:
	/* 0x1639: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_163e:
	/* 0x163e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1643:
	/* 0x1643: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1648:
	/* 0x1648: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_164d:
	/* 0x164d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164f:
	/* 0x164f: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1654:
	/* 0x1654: jne    16a8 <trace_execute_finished+0x16a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a8;
	}
x86_l_1656:
	/* 0x1656: lea    rax,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_165a:
	/* 0x165a: jmp    16b5 <trace_execute_finished+0x16b5> */
	goto x86_l_16b5;
x86_l_165c:
	/* 0x165c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_165f:
	/* 0x165f: je     17bd <trace_execute_finished+0x17bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17bd;
	}
x86_l_1665:
	/* 0x1665: lea    rax,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1669:
	/* 0x1669: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166c:
	/* 0x166c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1671:
	/* 0x1671: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1679:
	/* 0x1679: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_167e:
	/* 0x167e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1683:
	/* 0x1683: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1688:
	/* 0x1688: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168d:
	/* 0x168d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168f:
	/* 0x168f: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1694:
	/* 0x1694: je     169f <trace_execute_finished+0x169f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169f;
	}
x86_l_1696:
	/* 0x1696: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1699:
	/* 0x1699: je     17c2 <trace_execute_finished+0x17c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c2;
	}
x86_l_169f:
	/* 0x169f: mov    rbp,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_16a3:
	/* 0x16a3: jmp    17c2 <trace_execute_finished+0x17c2> */
	goto x86_l_17c2;
x86_l_16a8:
	/* 0x16a8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_16ab:
	/* 0x16ab: je     1862 <trace_execute_finished+0x1862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1862;
	}
x86_l_16b1:
	/* 0x16b1: lea    rax,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16b5:
	/* 0x16b5: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b8:
	/* 0x16b8: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_16c0:
	/* 0x16c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16c5:
	/* 0x16c5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16ca:
	/* 0x16ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16cf:
	/* 0x16cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16d4:
	/* 0x16d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d6:
	/* 0x16d6: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_16db:
	/* 0x16db: jne    16e3 <trace_execute_finished+0x16e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e3;
	}
x86_l_16dd:
	/* 0x16dd: add    r13,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_16e1:
	/* 0x16e1: jmp    16f0 <trace_execute_finished+0x16f0> */
	goto x86_l_16f0;
x86_l_16e3:
	/* 0x16e3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_16e6:
	/* 0x16e6: je     1867 <trace_execute_finished+0x1867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1867;
	}
x86_l_16ec:
	/* 0x16ec: add    r13,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_16f0:
	/* 0x16f0: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f4:
	/* 0x16f4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f8:
	/* 0x16f8: movzx  r15d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16fc:
	/* 0x16fc: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_1703:
	/* 0x1703: ja     1752 <trace_execute_finished+0x1752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1752;
	}
x86_l_1705:
	/* 0x1705: mov    BYTE PTR [r12+r15*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519552ULL);
x86_l_170e:
	/* 0x170e: cmp    r15d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31995ULL);
x86_l_1715:
	/* 0x1715: ja     1752 <trace_execute_finished+0x1752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1752;
	}
x86_l_1717:
	/* 0x1717: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_171b:
	/* 0x171b: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1722:
	/* 0x1722: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1727:
	/* 0x1727: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_172c:
	/* 0x172c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1731:
	/* 0x1731: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1736:
	/* 0x1736: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1738:
	/* 0x1738: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173b:
	/* 0x173b: js     1752 <trace_execute_finished+0x1752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1752;
	}
x86_l_173d:
	/* 0x173d: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1741:
	/* 0x1741: mov    WORD PTR [r12+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_174a:
	/* 0x174a: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1752:
	/* 0x1752: movzx  r15d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1756:
	/* 0x1756: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_175d:
	/* 0x175d: ja     17c2 <trace_execute_finished+0x17c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17c2;
	}
x86_l_175f:
	/* 0x175f: mov    BYTE PTR [r12+r15*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519553ULL);
x86_l_1768:
	/* 0x1768: cmp    r15d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31995ULL);
x86_l_176f:
	/* 0x176f: ja     17c2 <trace_execute_finished+0x17c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17c2;
	}
x86_l_1771:
	/* 0x1771: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1775:
	/* 0x1775: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_177c:
	/* 0x177c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1781:
	/* 0x1781: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1786:
	/* 0x1786: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_178b:
	/* 0x178b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1790:
	/* 0x1790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1792:
	/* 0x1792: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1795:
	/* 0x1795: js     17c2 <trace_execute_finished+0x17c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_17c2;
	}
x86_l_1797:
	/* 0x1797: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_179b:
	/* 0x179b: mov    WORD PTR [r12+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_17a4:
	/* 0x17a4: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_17ac:
	/* 0x17ac: jmp    17c2 <trace_execute_finished+0x17c2> */
	goto x86_l_17c2;
x86_l_17ae:
	/* 0x17ae: jmp    1584 <trace_execute_finished+0x1584> */
	goto x86_l_1584;
x86_l_17b3:
	/* 0x17b3: jmp    15c3 <trace_execute_finished+0x15c3> */
	goto x86_l_15c3;
x86_l_17b8:
	/* 0x17b8: jmp    15fe <trace_execute_finished+0x15fe> */
	goto x86_l_15fe;
x86_l_17bd:
	/* 0x17bd: jmp    1671 <trace_execute_finished+0x1671> */
	goto x86_l_1671;
x86_l_17c2:
	/* 0x17c2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17c6:
	/* 0x17c6: cmp    rax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32000ULL);
x86_l_17cc:
	/* 0x17cc: jae    193d <trace_execute_finished+0x193d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_193d;
	}
x86_l_17d2:
	/* 0x17d2: mov    BYTE PTR [r12+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_17db:
	/* 0x17db: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17e4:
	/* 0x17e4: mov    WORD PTR [r12+0x7d90],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32144ULL);
x86_l_17ed:
	/* 0x17ed: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_17f4:
	/* 0x17f4: ja     1870 <trace_execute_finished+0x1870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1870;
	}
x86_l_17f6:
	/* 0x17f6: add    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17f9:
	/* 0x17f9: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1800:
	/* 0x1800: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1805:
	/* 0x1805: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_180a:
	/* 0x180a: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1813:
	/* 0x1813: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1817:
	/* 0x1817: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_181e:
	/* 0x181e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1823:
	/* 0x1823: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1826:
	/* 0x1826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1828:
	/* 0x1828: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182a:
	/* 0x182a: jle    186c <trace_execute_finished+0x186c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_186c;
	}
x86_l_182c:
	/* 0x182c: movzx  ecx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1830:
	/* 0x1830: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1837:
	/* 0x1837: ja     1870 <trace_execute_finished+0x1870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1870;
	}
x86_l_1839:
	/* 0x1839: mov    DWORD PTR [rcx+r12*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 138ULL);
x86_l_1841:
	/* 0x1841: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_184a:
	/* 0x184a: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_184d:
	/* 0x184d: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1856:
	/* 0x1856: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_185e:
	/* 0x185e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1860:
	/* 0x1860: jmp    1870 <trace_execute_finished+0x1870> */
	goto x86_l_1870;
x86_l_1862:
	/* 0x1862: jmp    16b8 <trace_execute_finished+0x16b8> */
	goto x86_l_16b8;
x86_l_1867:
	/* 0x1867: jmp    16f4 <trace_execute_finished+0x16f4> */
	goto x86_l_16f4;
x86_l_186c:
	/* 0x186c: movzx  ecx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1870:
	/* 0x1870: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1873:
	/* 0x1873: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1878:
	/* 0x1878: ja     193d <trace_execute_finished+0x193d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_193d;
	}
x86_l_187e:
	/* 0x187e: mov    BYTE PTR [r12+rax*1+0x89],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519564ULL);
x86_l_1887:
	/* 0x1887: movzx  ebx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1890:
	/* 0x1890: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1893:
	/* 0x1893: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_189c:
	/* 0x189c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18a5:
	/* 0x18a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18aa:
	/* 0x18aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18af:
	/* 0x18af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b4:
	/* 0x18b4: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18b9:
	/* 0x18b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18be:
	/* 0x18be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c0:
	/* 0x18c0: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c5:
	/* 0x18c5: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_18c8:
	/* 0x18c8: je     1923 <trace_execute_finished+0x1923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1923;
	}
x86_l_18ca:
	/* 0x18ca: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18ce:
	/* 0x18ce: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_18d4:
	/* 0x18d4: ja     1923 <trace_execute_finished+0x1923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1923;
	}
x86_l_18d6:
	/* 0x18d6: lea    rdx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_18da:
	/* 0x18da: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18e1:
	/* 0x18e1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18e6:
	/* 0x18e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18eb:
	/* 0x18eb: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18f4:
	/* 0x18f4: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_18f8:
	/* 0x18f8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18ff:
	/* 0x18ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1904:
	/* 0x1904: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1909:
	/* 0x1909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190b:
	/* 0x190b: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190f:
	/* 0x190f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1911:
	/* 0x1911: jle    1923 <trace_execute_finished+0x1923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1923;
	}
x86_l_1913:
	/* 0x1913: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1917:
	/* 0x1917: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_191d:
	/* 0x191d: jbe    1fad <trace_execute_finished+0x1fad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8109ULL;
	}
x86_l_1923:
	/* 0x1923: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1925:
	/* 0x1925: cmp    ebx,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31998ULL);
x86_l_192b:
	/* 0x192b: ja     193d <trace_execute_finished+0x193d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_193d;
	}
x86_l_192d:
	/* 0x192d: mov    BYTE PTR [r12+rbx*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 138ULL);
x86_l_1935:
	/* 0x1935: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_193d:
	/* 0x193d: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1945:
	/* 0x1945: test   BYTE PTR [rax+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_1949:
	/* 0x1949: je     1a1c <trace_execute_finished+0x1a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a1c;
	}
x86_l_194f:
	/* 0x194f: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1953:
	/* 0x1953: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1959:
	/* 0x1959: ja     1a1c <trace_execute_finished+0x1a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a1c;
	}
x86_l_195f:
	/* 0x195f: mov    BYTE PTR [r12+rax*1+0x89],0xd */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519565ULL);
x86_l_1968:
	/* 0x1968: movzx  ebx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1971:
	/* 0x1971: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1974:
	/* 0x1974: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_197d:
	/* 0x197d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1986:
	/* 0x1986: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198b:
	/* 0x198b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1990:
	/* 0x1990: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1995:
	/* 0x1995: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_199a:
	/* 0x199a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_199d:
	/* 0x199d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199f:
	/* 0x199f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19a4:
	/* 0x19a4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_19a7:
	/* 0x19a7: je     1a02 <trace_execute_finished+0x1a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a02;
	}
x86_l_19a9:
	/* 0x19a9: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19ad:
	/* 0x19ad: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_19b3:
	/* 0x19b3: ja     1a02 <trace_execute_finished+0x1a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a02;
	}
x86_l_19b5:
	/* 0x19b5: lea    rdx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_19b9:
	/* 0x19b9: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_19c0:
	/* 0x19c0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19ca:
	/* 0x19ca: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19d3:
	/* 0x19d3: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_19d7:
	/* 0x19d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_19de:
	/* 0x19de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e3:
	/* 0x19e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19e8:
	/* 0x19e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ea:
	/* 0x19ea: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ee:
	/* 0x19ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f0:
	/* 0x19f0: jle    1a02 <trace_execute_finished+0x1a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a02;
	}
x86_l_19f2:
	/* 0x19f2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19f6:
	/* 0x19f6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_19fc:
	/* 0x19fc: jbe    44c7 <trace_execute_finished+0x44c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 17607ULL;
	}
x86_l_1a02:
	/* 0x1a02: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a04:
	/* 0x1a04: cmp    ebx,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31998ULL);
x86_l_1a0a:
	/* 0x1a0a: ja     1a1c <trace_execute_finished+0x1a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a1c;
	}
x86_l_1a0c:
	/* 0x1a0c: mov    BYTE PTR [r12+rbx*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 138ULL);
x86_l_1a14:
	/* 0x1a14: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a24:
	/* 0x1a24: mov    rax,QWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a28:
	/* 0x1a28: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2d:
	/* 0x1a2d: movzx  ebx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a31:
	/* 0x1a31: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1a38:
	/* 0x1a38: ja     1a85 <trace_execute_finished+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a85;
	}
x86_l_1a3a:
	/* 0x1a3a: mov    BYTE PTR [r12+rbx*1+0x89],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519566ULL);
x86_l_1a43:
	/* 0x1a43: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1a49:
	/* 0x1a49: ja     1a85 <trace_execute_finished+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a85;
	}
x86_l_1a4b:
	/* 0x1a4b: lea    rdi,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1a4f:
	/* 0x1a4f: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1a56:
	/* 0x1a56: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a60:
	/* 0x1a60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a65:
	/* 0x1a65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a6a:
	/* 0x1a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6c:
	/* 0x1a6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a6f:
	/* 0x1a6f: js     1a85 <trace_execute_finished+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a85;
	}
x86_l_1a71:
	/* 0x1a71: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1a74:
	/* 0x1a74: mov    WORD PTR [r12+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a7d:
	/* 0x1a7d: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a85:
	/* 0x1a85: mov    r13,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1a8d:
	/* 0x1a8d: lea    r15,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a91:
	/* 0x1a91: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a96:
	/* 0x1a96: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa0:
	/* 0x1aa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1aa8:
	/* 0x1aa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aaa:
	/* 0x1aaa: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab3:
	/* 0x1ab3: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab7:
	/* 0x1ab7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1abc:
	/* 0x1abc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1acb:
	/* 0x1acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acd:
	/* 0x1acd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad2:
	/* 0x1ad2: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1ad6:
	/* 0x1ad6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1adb:
	/* 0x1adb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aea:
	/* 0x1aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aec:
	/* 0x1aec: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af1:
	/* 0x1af1: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1af5:
	/* 0x1af5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1afa:
	/* 0x1afa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1aff:
	/* 0x1aff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b04:
	/* 0x1b04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b09:
	/* 0x1b09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0b:
	/* 0x1b0b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1b14:
	/* 0x1b14: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1b17:
	/* 0x1b17: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1b:
	/* 0x1b1b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b20:
	/* 0x1b20: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b25:
	/* 0x1b25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b32:
	/* 0x1b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b34:
	/* 0x1b34: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b39:
	/* 0x1b39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b43:
	/* 0x1b43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b48:
	/* 0x1b48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1b50:
	/* 0x1b50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b52:
	/* 0x1b52: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b56:
	/* 0x1b56: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b5a:
	/* 0x1b5a: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b5e:
	/* 0x1b5e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b62:
	/* 0x1b62: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b67:
	/* 0x1b67: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b71:
	/* 0x1b71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b76:
	/* 0x1b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b78:
	/* 0x1b78: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    DWORD PTR [rbp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b7f:
	/* 0x1b7f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b84:
	/* 0x1b84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b89:
	/* 0x1b89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b93:
	/* 0x1b93: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b96:
	/* 0x1b96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b98:
	/* 0x1b98: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b9d:
	/* 0x1b9d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ba1:
	/* 0x1ba1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bab:
	/* 0x1bab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb5:
	/* 0x1bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb7:
	/* 0x1bb7: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bbc:
	/* 0x1bbc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1bd3:
	/* 0x1bd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd5:
	/* 0x1bd5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd9:
	/* 0x1bd9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1bdd:
	/* 0x1bdd: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1be1:
	/* 0x1be1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1be5:
	/* 0x1be5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bea:
	/* 0x1bea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bef:
	/* 0x1bef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf9:
	/* 0x1bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfb:
	/* 0x1bfb: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bff:
	/* 0x1bff: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c02:
	/* 0x1c02: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c07:
	/* 0x1c07: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c0c:
	/* 0x1c0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c11:
	/* 0x1c11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c16:
	/* 0x1c16: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c19:
	/* 0x1c19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1b:
	/* 0x1c1b: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c20:
	/* 0x1c20: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c25:
	/* 0x1c25: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c2a:
	/* 0x1c2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c34:
	/* 0x1c34: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1c37:
	/* 0x1c37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c39:
	/* 0x1c39: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3d:
	/* 0x1c3d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1c41:
	/* 0x1c41: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c45:
	/* 0x1c45: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c49:
	/* 0x1c49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 7251ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7358ULL: goto x86_l_1cbe;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7370ULL: goto x86_l_1cca;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7405ULL: goto x86_l_1ced;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7489ULL: goto x86_l_1d41;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7501ULL: goto x86_l_1d4d;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7538ULL: goto x86_l_1d72;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7637ULL: goto x86_l_1dd5;
	case 7641ULL: goto x86_l_1dd9;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7689ULL: goto x86_l_1e09;
	case 7693ULL: goto x86_l_1e0d;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7728ULL: goto x86_l_1e30;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7798ULL: goto x86_l_1e76;
	case 7802ULL: goto x86_l_1e7a;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7859ULL: goto x86_l_1eb3;
	case 7862ULL: goto x86_l_1eb6;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7976ULL: goto x86_l_1f28;
	case 7984ULL: goto x86_l_1f30;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8113ULL: goto x86_l_1fb1;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8144ULL: goto x86_l_1fd0;
	case 8148ULL: goto x86_l_1fd4;
	case 8155ULL: goto x86_l_1fdb;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8188ULL: goto x86_l_1ffc;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8235ULL: goto x86_l_202b;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8260ULL: goto x86_l_2044;
	case 8264ULL: goto x86_l_2048;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8290ULL: goto x86_l_2062;
	case 8294ULL: goto x86_l_2066;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8313ULL: goto x86_l_2079;
	case 8317ULL: goto x86_l_207d;
	case 8319ULL: goto x86_l_207f;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8331ULL: goto x86_l_208b;
	case 8337ULL: goto x86_l_2091;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8364ULL: goto x86_l_20ac;
	case 8369ULL: goto x86_l_20b1;
	case 8378ULL: goto x86_l_20ba;
	case 8382ULL: goto x86_l_20be;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8422ULL: goto x86_l_20e6;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8469ULL: goto x86_l_2115;
	case 8472ULL: goto x86_l_2118;
	case 8478ULL: goto x86_l_211e;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8498ULL: goto x86_l_2132;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8515ULL: goto x86_l_2143;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8547ULL: goto x86_l_2163;
	case 8551ULL: goto x86_l_2167;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8561ULL: goto x86_l_2171;
	case 8565ULL: goto x86_l_2175;
	case 8571ULL: goto x86_l_217b;
	case 8577ULL: goto x86_l_2181;
	case 8581ULL: goto x86_l_2185;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8612ULL: goto x86_l_21a4;
	case 8616ULL: goto x86_l_21a8;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8656ULL: goto x86_l_21d0;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8674ULL: goto x86_l_21e2;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8696ULL: goto x86_l_21f8;
	case 8701ULL: goto x86_l_21fd;
	case 8703ULL: goto x86_l_21ff;
	case 8706ULL: goto x86_l_2202;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8728ULL: goto x86_l_2218;
	case 8731ULL: goto x86_l_221b;
	case 8735ULL: goto x86_l_221f;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8761ULL: goto x86_l_2239;
	case 8765ULL: goto x86_l_223d;
	case 8772ULL: goto x86_l_2244;
	case 8777ULL: goto x86_l_2249;
	case 8782ULL: goto x86_l_224e;
	case 8784ULL: goto x86_l_2250;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8798ULL: goto x86_l_225e;
	case 8802ULL: goto x86_l_2262;
	case 8808ULL: goto x86_l_2268;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8825ULL: goto x86_l_2279;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8856ULL: goto x86_l_2298;
	case 8860ULL: goto x86_l_229c;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8900ULL: goto x86_l_22c4;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8950ULL: goto x86_l_22f6;
	case 8956ULL: goto x86_l_22fc;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8970ULL: goto x86_l_230a;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8983ULL: goto x86_l_2317;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c53:
	/* 0x1c53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c58:
	/* 0x1c58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c5d:
	/* 0x1c5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5f:
	/* 0x1c5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c64:
	/* 0x1c64: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1c68:
	/* 0x1c68: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c72:
	/* 0x1c72: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c77:
	/* 0x1c77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c7c:
	/* 0x1c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7e:
	/* 0x1c7e: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c83:
	/* 0x1c83: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c87:
	/* 0x1c87: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c91:
	/* 0x1c91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c96:
	/* 0x1c96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c9e:
	/* 0x1c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca0:
	/* 0x1ca0: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca5:
	/* 0x1ca5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1caa:
	/* 0x1caa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1caf:
	/* 0x1caf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1cbc:
	/* 0x1cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbe:
	/* 0x1cbe: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc2:
	/* 0x1cc2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1cc6:
	/* 0x1cc6: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1cca:
	/* 0x1cca: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cce:
	/* 0x1cce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cdd:
	/* 0x1cdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce2:
	/* 0x1ce2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce4:
	/* 0x1ce4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce9:
	/* 0x1ce9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1ced:
	/* 0x1ced: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d01:
	/* 0x1d01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d03:
	/* 0x1d03: cmp    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d08:
	/* 0x1d08: jne    1d6e <trace_execute_finished+0x1d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d6e;
	}
x86_l_1d0a:
	/* 0x1d0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d14:
	/* 0x1d14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d19:
	/* 0x1d19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d1e:
	/* 0x1d1e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d21:
	/* 0x1d21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d23:
	/* 0x1d23: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d28:
	/* 0x1d28: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d32:
	/* 0x1d32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d37:
	/* 0x1d37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1d3f:
	/* 0x1d3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d41:
	/* 0x1d41: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d45:
	/* 0x1d45: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1d49:
	/* 0x1d49: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d4d:
	/* 0x1d4d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d51:
	/* 0x1d51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d56:
	/* 0x1d56: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d60:
	/* 0x1d60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d65:
	/* 0x1d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d67:
	/* 0x1d67: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    DWORD PTR [rbp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    DWORD PTR [rbp+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d72:
	/* 0x1d72: lea    r15,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d79:
	/* 0x1d79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d83:
	/* 0x1d83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d88:
	/* 0x1d88: lea    r12,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d91:
	/* 0x1d91: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d94:
	/* 0x1d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d96:
	/* 0x1d96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9b:
	/* 0x1d9b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d9f:
	/* 0x1d9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da4:
	/* 0x1da4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1da9:
	/* 0x1da9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dae:
	/* 0x1dae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db3:
	/* 0x1db3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db5:
	/* 0x1db5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dba:
	/* 0x1dba: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dce:
	/* 0x1dce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dd3:
	/* 0x1dd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd5:
	/* 0x1dd5: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1dd9:
	/* 0x1dd9: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ddc:
	/* 0x1ddc: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1de1:
	/* 0x1de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de3:
	/* 0x1de3: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1de6:
	/* 0x1de6: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1dea:
	/* 0x1dea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1def:
	/* 0x1def: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1df4:
	/* 0x1df4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1df9:
	/* 0x1df9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dfe:
	/* 0x1dfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e00:
	/* 0x1e00: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e05:
	/* 0x1e05: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e09:
	/* 0x1e09: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0d:
	/* 0x1e0d: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1e11:
	/* 0x1e11: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e16:
	/* 0x1e16: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e1b:
	/* 0x1e1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e20:
	/* 0x1e20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e25:
	/* 0x1e25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e27:
	/* 0x1e27: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e30:
	/* 0x1e30: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1e34:
	/* 0x1e34: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e39:
	/* 0x1e39: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e43:
	/* 0x1e43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e48:
	/* 0x1e48: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e4b:
	/* 0x1e4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4d:
	/* 0x1e4d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e52:
	/* 0x1e52: mov    QWORD PTR [rbp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e56:
	/* 0x1e56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e60:
	/* 0x1e60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e65:
	/* 0x1e65: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e6d:
	/* 0x1e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6f:
	/* 0x1e6f: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1e74:
	/* 0x1e74: je     1e7a <trace_execute_finished+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e7a;
	}
x86_l_1e76:
	/* 0x1e76: or     BYTE PTR [rbp+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    QWORD PTR [rbp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1e82:
	/* 0x1e82: lea    rdi,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1e86:
	/* 0x1e86: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1e8e:
	/* 0x1e8e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e93:
	/* 0x1e93: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1e98:
	/* 0x1e98: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e9d:
	/* 0x1e9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9f:
	/* 0x1e9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eae:
	/* 0x1eae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb3:
	/* 0x1eb3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1eb6:
	/* 0x1eb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb8:
	/* 0x1eb8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ebd:
	/* 0x1ebd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ed1:
	/* 0x1ed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed3:
	/* 0x1ed3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed8:
	/* 0x1ed8: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1edd:
	/* 0x1edd: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1eea:
	/* 0x1eea: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1eef:
	/* 0x1eef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef1:
	/* 0x1ef1: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1ef4:
	/* 0x1ef4: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1efd:
	/* 0x1efd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1f02:
	/* 0x1f02: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f07:
	/* 0x1f07: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1f0a:
	/* 0x1f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0c:
	/* 0x1f0c: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_1f11:
	/* 0x1f11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f16:
	/* 0x1f16: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1f23:
	/* 0x1f23: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f26:
	/* 0x1f26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f28:
	/* 0x1f28: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f30:
	/* 0x1f30: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1f34:
	/* 0x1f34: je     1f5d <trace_execute_finished+0x1f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5d;
	}
x86_l_1f36:
	/* 0x1f36: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1f3d:
	/* 0x1f3d: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1f42:
	/* 0x1f42: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1f47:
	/* 0x1f47: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1f54:
	/* 0x1f54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f56:
	/* 0x1f56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f58:
	/* 0x1f58: js     1f5d <trace_execute_finished+0x1f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f5d;
	}
x86_l_1f5a:
	/* 0x1f5a: mov    DWORD PTR [rbp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f5d:
	/* 0x1f5d: movzx  eax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f64:
	/* 0x1f64: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1f69:
	/* 0x1f69: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1f6e:
	/* 0x1f6e: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1f71:
	/* 0x1f71: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1f77:
	/* 0x1f77: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f7b:
	/* 0x1f7b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1f82:
	/* 0x1f82: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1f87:
	/* 0x1f87: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f94:
	/* 0x1f94: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1f99:
	/* 0x1f99: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1f9c:
	/* 0x1f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9e:
	/* 0x1f9e: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1fa5:
	/* 0x1fa5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1fa7:
	/* 0x1fa7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1fa8:
	/* 0x1fa8: jmp    68aa <trace_execute_finished+0x68aa> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fad:
	/* 0x1fad: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fb1:
	/* 0x1fb1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fb8:
	/* 0x1fb8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fc7:
	/* 0x1fc7: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fd0:
	/* 0x1fd0: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1fd4:
	/* 0x1fd4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fdb:
	/* 0x1fdb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fe0:
	/* 0x1fe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe2:
	/* 0x1fe2: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1fe7:
	/* 0x1fe7: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ff0:
	/* 0x1ff0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ff3:
	/* 0x1ff3: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2005:
	/* 0x2005: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_200a:
	/* 0x200a: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_200e:
	/* 0x200e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2013:
	/* 0x2013: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2018:
	/* 0x2018: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201d:
	/* 0x201d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2022:
	/* 0x2022: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2024:
	/* 0x2024: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2029:
	/* 0x2029: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_202b:
	/* 0x202b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_202e:
	/* 0x202e: je     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_2034:
	/* 0x2034: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2038:
	/* 0x2038: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_203e:
	/* 0x203e: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2044:
	/* 0x2044: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2048:
	/* 0x2048: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_204f:
	/* 0x204f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2054:
	/* 0x2054: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2059:
	/* 0x2059: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2062:
	/* 0x2062: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2066:
	/* 0x2066: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_206d:
	/* 0x206d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2072:
	/* 0x2072: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2077:
	/* 0x2077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2079:
	/* 0x2079: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_207d:
	/* 0x207d: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_207f:
	/* 0x207f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2081:
	/* 0x2081: jle    1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6437ULL;
	}
x86_l_2087:
	/* 0x2087: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_208b:
	/* 0x208b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2091:
	/* 0x2091: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2097:
	/* 0x2097: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_209b:
	/* 0x209b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20a2:
	/* 0x20a2: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a7:
	/* 0x20a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ac:
	/* 0x20ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20b1:
	/* 0x20b1: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20ba:
	/* 0x20ba: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20be:
	/* 0x20be: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20c5:
	/* 0x20c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ca:
	/* 0x20ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20cc:
	/* 0x20cc: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_20d1:
	/* 0x20d1: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_20da:
	/* 0x20da: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_20dd:
	/* 0x20dd: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20e6:
	/* 0x20e6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20ef:
	/* 0x20ef: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_20f4:
	/* 0x20f4: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f8:
	/* 0x20f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20fd:
	/* 0x20fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2102:
	/* 0x2102: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2107:
	/* 0x2107: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210c:
	/* 0x210c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210e:
	/* 0x210e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2113:
	/* 0x2113: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2115:
	/* 0x2115: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2118:
	/* 0x2118: je     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_211e:
	/* 0x211e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2122:
	/* 0x2122: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2128:
	/* 0x2128: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_212e:
	/* 0x212e: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2132:
	/* 0x2132: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2139:
	/* 0x2139: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_213e:
	/* 0x213e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2143:
	/* 0x2143: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_214c:
	/* 0x214c: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2150:
	/* 0x2150: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2157:
	/* 0x2157: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_215c:
	/* 0x215c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2161:
	/* 0x2161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2163:
	/* 0x2163: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2167:
	/* 0x2167: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2169:
	/* 0x2169: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_216b:
	/* 0x216b: jle    1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6437ULL;
	}
x86_l_2171:
	/* 0x2171: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2175:
	/* 0x2175: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_217b:
	/* 0x217b: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2181:
	/* 0x2181: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2185:
	/* 0x2185: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_218c:
	/* 0x218c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2191:
	/* 0x2191: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2196:
	/* 0x2196: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_219b:
	/* 0x219b: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21a4:
	/* 0x21a4: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21a8:
	/* 0x21a8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21af:
	/* 0x21af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21b4:
	/* 0x21b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b6:
	/* 0x21b6: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_21bb:
	/* 0x21bb: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_21c4:
	/* 0x21c4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_21c7:
	/* 0x21c7: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21d0:
	/* 0x21d0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21d9:
	/* 0x21d9: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21de:
	/* 0x21de: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21e2:
	/* 0x21e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21e7:
	/* 0x21e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21ec:
	/* 0x21ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21f1:
	/* 0x21f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f6:
	/* 0x21f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f8:
	/* 0x21f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21fd:
	/* 0x21fd: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_21ff:
	/* 0x21ff: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2202:
	/* 0x2202: je     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_2208:
	/* 0x2208: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_220c:
	/* 0x220c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2212:
	/* 0x2212: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2218:
	/* 0x2218: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_221b:
	/* 0x221b: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_221f:
	/* 0x221f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2226:
	/* 0x2226: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_222b:
	/* 0x222b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2230:
	/* 0x2230: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2239:
	/* 0x2239: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_223d:
	/* 0x223d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2244:
	/* 0x2244: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2249:
	/* 0x2249: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_224e:
	/* 0x224e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2250:
	/* 0x2250: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2254:
	/* 0x2254: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2256:
	/* 0x2256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2258:
	/* 0x2258: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_225e:
	/* 0x225e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2262:
	/* 0x2262: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2268:
	/* 0x2268: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226c:
	/* 0x226c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2275:
	/* 0x2275: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2279:
	/* 0x2279: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2280:
	/* 0x2280: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2285:
	/* 0x2285: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_228a:
	/* 0x228a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_228f:
	/* 0x228f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2298:
	/* 0x2298: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_229c:
	/* 0x229c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22a3:
	/* 0x22a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22a8:
	/* 0x22a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22aa:
	/* 0x22aa: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_22af:
	/* 0x22af: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22b8:
	/* 0x22b8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22bb:
	/* 0x22bb: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_22c4:
	/* 0x22c4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22cd:
	/* 0x22cd: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22d2:
	/* 0x22d2: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22d6:
	/* 0x22d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22db:
	/* 0x22db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22e0:
	/* 0x22e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22e5:
	/* 0x22e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ea:
	/* 0x22ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ec:
	/* 0x22ec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f1:
	/* 0x22f1: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_22f3:
	/* 0x22f3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_22f6:
	/* 0x22f6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_22fc:
	/* 0x22fc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2300:
	/* 0x2300: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2306:
	/* 0x2306: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230a:
	/* 0x230a: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_230d:
	/* 0x230d: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2313:
	/* 0x2313: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2317:
	/* 0x2317: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_231e:
	/* 0x231e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2323:
	/* 0x2323: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2328:
	/* 0x2328: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2331:
	/* 0x2331: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2335:
	/* 0x2335: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_233c:
	/* 0x233c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2341:
	/* 0x2341: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2346:
	/* 0x2346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2348:
	/* 0x2348: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_234c:
	/* 0x234c: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_234e:
	/* 0x234e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2350:
	/* 0x2350: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
	return 9046ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9046ULL: goto x86_l_2356;
	case 9050ULL: goto x86_l_235a;
	case 9056ULL: goto x86_l_2360;
	case 9060ULL: goto x86_l_2364;
	case 9063ULL: goto x86_l_2367;
	case 9069ULL: goto x86_l_236d;
	case 9073ULL: goto x86_l_2371;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9148ULL: goto x86_l_23bc;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9166ULL: goto x86_l_23ce;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9186ULL: goto x86_l_23e2;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9195ULL: goto x86_l_23eb;
	case 9198ULL: goto x86_l_23ee;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9227ULL: goto x86_l_240b;
	case 9231ULL: goto x86_l_240f;
	case 9238ULL: goto x86_l_2416;
	case 9243ULL: goto x86_l_241b;
	case 9248ULL: goto x86_l_2420;
	case 9257ULL: goto x86_l_2429;
	case 9261ULL: goto x86_l_242d;
	case 9268ULL: goto x86_l_2434;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9288ULL: goto x86_l_2448;
	case 9294ULL: goto x86_l_244e;
	case 9298ULL: goto x86_l_2452;
	case 9304ULL: goto x86_l_2458;
	case 9308ULL: goto x86_l_245c;
	case 9311ULL: goto x86_l_245f;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9384ULL: goto x86_l_24a8;
	case 9387ULL: goto x86_l_24ab;
	case 9396ULL: goto x86_l_24b4;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9446ULL: goto x86_l_24e6;
	case 9452ULL: goto x86_l_24ec;
	case 9456ULL: goto x86_l_24f0;
	case 9462ULL: goto x86_l_24f6;
	case 9466ULL: goto x86_l_24fa;
	case 9469ULL: goto x86_l_24fd;
	case 9475ULL: goto x86_l_2503;
	case 9479ULL: goto x86_l_2507;
	case 9486ULL: goto x86_l_250e;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9505ULL: goto x86_l_2521;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9528ULL: goto x86_l_2538;
	case 9532ULL: goto x86_l_253c;
	case 9534ULL: goto x86_l_253e;
	case 9536ULL: goto x86_l_2540;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9565ULL: goto x86_l_255d;
	case 9569ULL: goto x86_l_2561;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9600ULL: goto x86_l_2580;
	case 9604ULL: goto x86_l_2584;
	case 9611ULL: goto x86_l_258b;
	case 9616ULL: goto x86_l_2590;
	case 9618ULL: goto x86_l_2592;
	case 9623ULL: goto x86_l_2597;
	case 9632ULL: goto x86_l_25a0;
	case 9635ULL: goto x86_l_25a3;
	case 9644ULL: goto x86_l_25ac;
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9694ULL: goto x86_l_25de;
	case 9700ULL: goto x86_l_25e4;
	case 9704ULL: goto x86_l_25e8;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9723ULL: goto x86_l_25fb;
	case 9727ULL: goto x86_l_25ff;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9776ULL: goto x86_l_2630;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9790ULL: goto x86_l_263e;
	case 9794ULL: goto x86_l_2642;
	case 9800ULL: goto x86_l_2648;
	case 9804ULL: goto x86_l_264c;
	case 9807ULL: goto x86_l_264f;
	case 9813ULL: goto x86_l_2655;
	case 9817ULL: goto x86_l_2659;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9866ULL: goto x86_l_268a;
	case 9871ULL: goto x86_l_268f;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9892ULL: goto x86_l_26a4;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9939ULL: goto x86_l_26d3;
	case 9942ULL: goto x86_l_26d6;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9982ULL: goto x86_l_26fe;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 10001ULL: goto x86_l_2711;
	case 10005ULL: goto x86_l_2715;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10024ULL: goto x86_l_2728;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10042ULL: goto x86_l_273a;
	case 10048ULL: goto x86_l_2740;
	case 10052ULL: goto x86_l_2744;
	case 10055ULL: goto x86_l_2747;
	case 10061ULL: goto x86_l_274d;
	case 10065ULL: goto x86_l_2751;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10096ULL: goto x86_l_2770;
	case 10100ULL: goto x86_l_2774;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10128ULL: goto x86_l_2790;
	case 10131ULL: goto x86_l_2793;
	case 10140ULL: goto x86_l_279c;
	case 10149ULL: goto x86_l_27a5;
	case 10154ULL: goto x86_l_27aa;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10168ULL: goto x86_l_27b8;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10200ULL: goto x86_l_27d8;
	case 10206ULL: goto x86_l_27de;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10223ULL: goto x86_l_27ef;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10249ULL: goto x86_l_2809;
	case 10253ULL: goto x86_l_280d;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10286ULL: goto x86_l_282e;
	case 10290ULL: goto x86_l_2832;
	case 10296ULL: goto x86_l_2838;
	case 10300ULL: goto x86_l_283c;
	case 10303ULL: goto x86_l_283f;
	case 10309ULL: goto x86_l_2845;
	case 10313ULL: goto x86_l_2849;
	case 10320ULL: goto x86_l_2850;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10344ULL: goto x86_l_2868;
	case 10348ULL: goto x86_l_286c;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10376ULL: goto x86_l_2888;
	case 10379ULL: goto x86_l_288b;
	case 10388ULL: goto x86_l_2894;
	case 10397ULL: goto x86_l_289d;
	case 10402ULL: goto x86_l_28a2;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10435ULL: goto x86_l_28c3;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10467ULL: goto x86_l_28e3;
	case 10471ULL: goto x86_l_28e7;
	case 10478ULL: goto x86_l_28ee;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10497ULL: goto x86_l_2901;
	case 10501ULL: goto x86_l_2905;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10520ULL: goto x86_l_2918;
	case 10524ULL: goto x86_l_291c;
	case 10526ULL: goto x86_l_291e;
	case 10528ULL: goto x86_l_2920;
	case 10534ULL: goto x86_l_2926;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10561ULL: goto x86_l_2941;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10578ULL: goto x86_l_2952;
	case 10583ULL: goto x86_l_2957;
	case 10592ULL: goto x86_l_2960;
	case 10596ULL: goto x86_l_2964;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10624ULL: goto x86_l_2980;
	case 10627ULL: goto x86_l_2983;
	case 10636ULL: goto x86_l_298c;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10654ULL: goto x86_l_299e;
	case 10659ULL: goto x86_l_29a3;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10696ULL: goto x86_l_29c8;
	case 10702ULL: goto x86_l_29ce;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10715ULL: goto x86_l_29db;
	case 10719ULL: goto x86_l_29df;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10745ULL: goto x86_l_29f9;
	case 10749ULL: goto x86_l_29fd;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10772ULL: goto x86_l_2a14;
	case 10774ULL: goto x86_l_2a16;
	case 10776ULL: goto x86_l_2a18;
	case 10782ULL: goto x86_l_2a1e;
	case 10786ULL: goto x86_l_2a22;
	case 10792ULL: goto x86_l_2a28;
	case 10796ULL: goto x86_l_2a2c;
	case 10799ULL: goto x86_l_2a2f;
	case 10805ULL: goto x86_l_2a35;
	case 10809ULL: goto x86_l_2a39;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10872ULL: goto x86_l_2a78;
	case 10875ULL: goto x86_l_2a7b;
	case 10884ULL: goto x86_l_2a84;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10931ULL: goto x86_l_2ab3;
	case 10934ULL: goto x86_l_2ab6;
	case 10940ULL: goto x86_l_2abc;
	case 10944ULL: goto x86_l_2ac0;
	case 10950ULL: goto x86_l_2ac6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2356:
	/* 0x2356: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_235a:
	/* 0x235a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2360:
	/* 0x2360: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2364:
	/* 0x2364: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2367:
	/* 0x2367: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_236d:
	/* 0x236d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2371:
	/* 0x2371: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2378:
	/* 0x2378: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237d:
	/* 0x237d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2382:
	/* 0x2382: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2387:
	/* 0x2387: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2390:
	/* 0x2390: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2394:
	/* 0x2394: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_239b:
	/* 0x239b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23a0:
	/* 0x23a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a2:
	/* 0x23a2: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_23a7:
	/* 0x23a7: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_23b0:
	/* 0x23b0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_23b3:
	/* 0x23b3: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_23bc:
	/* 0x23bc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_23c5:
	/* 0x23c5: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23ca:
	/* 0x23ca: lea    rdx,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23ce:
	/* 0x23ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d3:
	/* 0x23d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23d8:
	/* 0x23d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23dd:
	/* 0x23dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23e2:
	/* 0x23e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e4:
	/* 0x23e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e9:
	/* 0x23e9: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_23eb:
	/* 0x23eb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_23ee:
	/* 0x23ee: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_23f4:
	/* 0x23f4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23f8:
	/* 0x23f8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_23fe:
	/* 0x23fe: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2402:
	/* 0x2402: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2405:
	/* 0x2405: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_240b:
	/* 0x240b: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_240f:
	/* 0x240f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2416:
	/* 0x2416: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_241b:
	/* 0x241b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2420:
	/* 0x2420: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2429:
	/* 0x2429: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_242d:
	/* 0x242d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2434:
	/* 0x2434: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2439:
	/* 0x2439: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_243e:
	/* 0x243e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2440:
	/* 0x2440: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2444:
	/* 0x2444: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2446:
	/* 0x2446: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2448:
	/* 0x2448: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_244e:
	/* 0x244e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2452:
	/* 0x2452: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2458:
	/* 0x2458: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245c:
	/* 0x245c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_245f:
	/* 0x245f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2465:
	/* 0x2465: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2469:
	/* 0x2469: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2470:
	/* 0x2470: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2475:
	/* 0x2475: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_247a:
	/* 0x247a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_247f:
	/* 0x247f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2488:
	/* 0x2488: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_248c:
	/* 0x248c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2493:
	/* 0x2493: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2498:
	/* 0x2498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249a:
	/* 0x249a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_249f:
	/* 0x249f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_24a8:
	/* 0x24a8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_24ab:
	/* 0x24ab: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24b4:
	/* 0x24b4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24bd:
	/* 0x24bd: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24c2:
	/* 0x24c2: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24c6:
	/* 0x24c6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cb:
	/* 0x24cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24d0:
	/* 0x24d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d5:
	/* 0x24d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24da:
	/* 0x24da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24dc:
	/* 0x24dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e1:
	/* 0x24e1: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_24e3:
	/* 0x24e3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_24e6:
	/* 0x24e6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_24ec:
	/* 0x24ec: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24f0:
	/* 0x24f0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_24f6:
	/* 0x24f6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24fa:
	/* 0x24fa: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_24fd:
	/* 0x24fd: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2503:
	/* 0x2503: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2507:
	/* 0x2507: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_250e:
	/* 0x250e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2513:
	/* 0x2513: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2518:
	/* 0x2518: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2521:
	/* 0x2521: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2525:
	/* 0x2525: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_252c:
	/* 0x252c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2531:
	/* 0x2531: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2536:
	/* 0x2536: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2538:
	/* 0x2538: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253c:
	/* 0x253c: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_253e:
	/* 0x253e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2540:
	/* 0x2540: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2546:
	/* 0x2546: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_254a:
	/* 0x254a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2550:
	/* 0x2550: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2554:
	/* 0x2554: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2557:
	/* 0x2557: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_255d:
	/* 0x255d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2561:
	/* 0x2561: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2568:
	/* 0x2568: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256d:
	/* 0x256d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2572:
	/* 0x2572: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2577:
	/* 0x2577: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2580:
	/* 0x2580: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2584:
	/* 0x2584: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_258b:
	/* 0x258b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2590:
	/* 0x2590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2592:
	/* 0x2592: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2597:
	/* 0x2597: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25a0:
	/* 0x25a0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_25a3:
	/* 0x25a3: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25ac:
	/* 0x25ac: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25b5:
	/* 0x25b5: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25ba:
	/* 0x25ba: lea    rdx,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25be:
	/* 0x25be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c3:
	/* 0x25c3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25c8:
	/* 0x25c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25cd:
	/* 0x25cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d2:
	/* 0x25d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d4:
	/* 0x25d4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d9:
	/* 0x25d9: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_25db:
	/* 0x25db: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_25de:
	/* 0x25de: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_25e4:
	/* 0x25e4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25e8:
	/* 0x25e8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_25ee:
	/* 0x25ee: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f2:
	/* 0x25f2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_25f5:
	/* 0x25f5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_25fb:
	/* 0x25fb: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_25ff:
	/* 0x25ff: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2606:
	/* 0x2606: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_260b:
	/* 0x260b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2610:
	/* 0x2610: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2619:
	/* 0x2619: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_261d:
	/* 0x261d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2624:
	/* 0x2624: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2629:
	/* 0x2629: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_262e:
	/* 0x262e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2630:
	/* 0x2630: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2634:
	/* 0x2634: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_2636:
	/* 0x2636: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2638:
	/* 0x2638: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_263e:
	/* 0x263e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2642:
	/* 0x2642: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2648:
	/* 0x2648: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264c:
	/* 0x264c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_264f:
	/* 0x264f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2655:
	/* 0x2655: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2659:
	/* 0x2659: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2660:
	/* 0x2660: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2665:
	/* 0x2665: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_266a:
	/* 0x266a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_266f:
	/* 0x266f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2678:
	/* 0x2678: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_267c:
	/* 0x267c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2683:
	/* 0x2683: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2688:
	/* 0x2688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268a:
	/* 0x268a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_268f:
	/* 0x268f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2698:
	/* 0x2698: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_269b:
	/* 0x269b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26a4:
	/* 0x26a4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26ad:
	/* 0x26ad: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26b2:
	/* 0x26b2: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26b6:
	/* 0x26b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26bb:
	/* 0x26bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26c0:
	/* 0x26c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26c5:
	/* 0x26c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ca:
	/* 0x26ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cc:
	/* 0x26cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d1:
	/* 0x26d1: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_26d3:
	/* 0x26d3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_26d6:
	/* 0x26d6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_26dc:
	/* 0x26dc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26e0:
	/* 0x26e0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_26e6:
	/* 0x26e6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ea:
	/* 0x26ea: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_26ed:
	/* 0x26ed: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_26f3:
	/* 0x26f3: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_26f7:
	/* 0x26f7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_26fe:
	/* 0x26fe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2703:
	/* 0x2703: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2708:
	/* 0x2708: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2711:
	/* 0x2711: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2715:
	/* 0x2715: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_271c:
	/* 0x271c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2721:
	/* 0x2721: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2726:
	/* 0x2726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2728:
	/* 0x2728: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272c:
	/* 0x272c: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_272e:
	/* 0x272e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2730:
	/* 0x2730: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2736:
	/* 0x2736: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_273a:
	/* 0x273a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2740:
	/* 0x2740: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2744:
	/* 0x2744: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2747:
	/* 0x2747: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_274d:
	/* 0x274d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2751:
	/* 0x2751: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2758:
	/* 0x2758: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_275d:
	/* 0x275d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2762:
	/* 0x2762: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2767:
	/* 0x2767: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2770:
	/* 0x2770: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2774:
	/* 0x2774: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_277b:
	/* 0x277b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2780:
	/* 0x2780: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2782:
	/* 0x2782: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2787:
	/* 0x2787: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2790:
	/* 0x2790: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2793:
	/* 0x2793: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_279c:
	/* 0x279c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27a5:
	/* 0x27a5: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27aa:
	/* 0x27aa: lea    rdx,[rax+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_27ae:
	/* 0x27ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b3:
	/* 0x27b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27b8:
	/* 0x27b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27bd:
	/* 0x27bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27c2:
	/* 0x27c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c4:
	/* 0x27c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c9:
	/* 0x27c9: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_27cb:
	/* 0x27cb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27ce:
	/* 0x27ce: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_27d4:
	/* 0x27d4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27d8:
	/* 0x27d8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_27de:
	/* 0x27de: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e2:
	/* 0x27e2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_27e5:
	/* 0x27e5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_27eb:
	/* 0x27eb: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_27ef:
	/* 0x27ef: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27f6:
	/* 0x27f6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27fb:
	/* 0x27fb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2800:
	/* 0x2800: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2809:
	/* 0x2809: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_280d:
	/* 0x280d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2814:
	/* 0x2814: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2819:
	/* 0x2819: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_281e:
	/* 0x281e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2820:
	/* 0x2820: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2824:
	/* 0x2824: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_2826:
	/* 0x2826: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2828:
	/* 0x2828: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_282e:
	/* 0x282e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2832:
	/* 0x2832: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2838:
	/* 0x2838: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283c:
	/* 0x283c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_283f:
	/* 0x283f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2845:
	/* 0x2845: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2849:
	/* 0x2849: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2850:
	/* 0x2850: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2855:
	/* 0x2855: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_285a:
	/* 0x285a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_285f:
	/* 0x285f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2868:
	/* 0x2868: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_286c:
	/* 0x286c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2873:
	/* 0x2873: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2878:
	/* 0x2878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287a:
	/* 0x287a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_287f:
	/* 0x287f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2888:
	/* 0x2888: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_288b:
	/* 0x288b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2894:
	/* 0x2894: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_289d:
	/* 0x289d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28a2:
	/* 0x28a2: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28a6:
	/* 0x28a6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ab:
	/* 0x28ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28b0:
	/* 0x28b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b5:
	/* 0x28b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ba:
	/* 0x28ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bc:
	/* 0x28bc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c1:
	/* 0x28c1: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_28c3:
	/* 0x28c3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_28c6:
	/* 0x28c6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_28cc:
	/* 0x28cc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28d0:
	/* 0x28d0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_28d6:
	/* 0x28d6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28da:
	/* 0x28da: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_28dd:
	/* 0x28dd: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_28e3:
	/* 0x28e3: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_28e7:
	/* 0x28e7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28ee:
	/* 0x28ee: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28f3:
	/* 0x28f3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_28f8:
	/* 0x28f8: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2901:
	/* 0x2901: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2905:
	/* 0x2905: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_290c:
	/* 0x290c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2911:
	/* 0x2911: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2916:
	/* 0x2916: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2918:
	/* 0x2918: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291c:
	/* 0x291c: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_291e:
	/* 0x291e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2920:
	/* 0x2920: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2926:
	/* 0x2926: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_292a:
	/* 0x292a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2930:
	/* 0x2930: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2934:
	/* 0x2934: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2937:
	/* 0x2937: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_293d:
	/* 0x293d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2941:
	/* 0x2941: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2948:
	/* 0x2948: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_294d:
	/* 0x294d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2952:
	/* 0x2952: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2957:
	/* 0x2957: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2960:
	/* 0x2960: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2964:
	/* 0x2964: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_296b:
	/* 0x296b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2970:
	/* 0x2970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2972:
	/* 0x2972: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2977:
	/* 0x2977: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2980:
	/* 0x2980: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2983:
	/* 0x2983: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_298c:
	/* 0x298c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2995:
	/* 0x2995: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_299a:
	/* 0x299a: lea    rdx,[rax+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_299e:
	/* 0x299e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29a3:
	/* 0x29a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29a8:
	/* 0x29a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29ad:
	/* 0x29ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b2:
	/* 0x29b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b4:
	/* 0x29b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b9:
	/* 0x29b9: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_29bb:
	/* 0x29bb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_29be:
	/* 0x29be: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_29c4:
	/* 0x29c4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29c8:
	/* 0x29c8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_29ce:
	/* 0x29ce: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d2:
	/* 0x29d2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_29d5:
	/* 0x29d5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_29db:
	/* 0x29db: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29df:
	/* 0x29df: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29e6:
	/* 0x29e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29eb:
	/* 0x29eb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_29f0:
	/* 0x29f0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29f9:
	/* 0x29f9: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29fd:
	/* 0x29fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a04:
	/* 0x2a04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a09:
	/* 0x2a09: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a0e:
	/* 0x2a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a10:
	/* 0x2a10: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a14:
	/* 0x2a14: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_2a16:
	/* 0x2a16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a18:
	/* 0x2a18: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2a1e:
	/* 0x2a1e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a22:
	/* 0x2a22: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2a28:
	/* 0x2a28: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a2c:
	/* 0x2a2c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2a2f:
	/* 0x2a2f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2a35:
	/* 0x2a35: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a39:
	/* 0x2a39: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a40:
	/* 0x2a40: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a45:
	/* 0x2a45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a4f:
	/* 0x2a4f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a58:
	/* 0x2a58: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a5c:
	/* 0x2a5c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a63:
	/* 0x2a63: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a68:
	/* 0x2a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6a:
	/* 0x2a6a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2a6f:
	/* 0x2a6f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a78:
	/* 0x2a78: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a84:
	/* 0x2a84: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a92:
	/* 0x2a92: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2a96:
	/* 0x2a96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2aa0:
	/* 0x2aa0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aaa:
	/* 0x2aaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aac:
	/* 0x2aac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab1:
	/* 0x2ab1: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_2ab3:
	/* 0x2ab3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2ab6:
	/* 0x2ab6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2abc:
	/* 0x2abc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ac0:
	/* 0x2ac0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ac6:
	/* 0x2ac6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 10954ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10993ULL: goto x86_l_2af1;
	case 10997ULL: goto x86_l_2af5;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11016ULL: goto x86_l_2b08;
	case 11020ULL: goto x86_l_2b0c;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11030ULL: goto x86_l_2b16;
	case 11034ULL: goto x86_l_2b1a;
	case 11040ULL: goto x86_l_2b20;
	case 11044ULL: goto x86_l_2b24;
	case 11047ULL: goto x86_l_2b27;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11088ULL: goto x86_l_2b50;
	case 11092ULL: goto x86_l_2b54;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11120ULL: goto x86_l_2b70;
	case 11123ULL: goto x86_l_2b73;
	case 11132ULL: goto x86_l_2b7c;
	case 11141ULL: goto x86_l_2b85;
	case 11146ULL: goto x86_l_2b8a;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11160ULL: goto x86_l_2b98;
	case 11165ULL: goto x86_l_2b9d;
	case 11170ULL: goto x86_l_2ba2;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11188ULL: goto x86_l_2bb4;
	case 11192ULL: goto x86_l_2bb8;
	case 11198ULL: goto x86_l_2bbe;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11211ULL: goto x86_l_2bcb;
	case 11215ULL: goto x86_l_2bcf;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11232ULL: goto x86_l_2be0;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11264ULL: goto x86_l_2c00;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11278ULL: goto x86_l_2c0e;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11292ULL: goto x86_l_2c1c;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11305ULL: goto x86_l_2c29;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11368ULL: goto x86_l_2c68;
	case 11371ULL: goto x86_l_2c6b;
	case 11380ULL: goto x86_l_2c74;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11398ULL: goto x86_l_2c86;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11427ULL: goto x86_l_2ca3;
	case 11430ULL: goto x86_l_2ca6;
	case 11436ULL: goto x86_l_2cac;
	case 11440ULL: goto x86_l_2cb0;
	case 11446ULL: goto x86_l_2cb6;
	case 11450ULL: goto x86_l_2cba;
	case 11453ULL: goto x86_l_2cbd;
	case 11459ULL: goto x86_l_2cc3;
	case 11463ULL: goto x86_l_2cc7;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11489ULL: goto x86_l_2ce1;
	case 11493ULL: goto x86_l_2ce5;
	case 11500ULL: goto x86_l_2cec;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11518ULL: goto x86_l_2cfe;
	case 11520ULL: goto x86_l_2d00;
	case 11526ULL: goto x86_l_2d06;
	case 11530ULL: goto x86_l_2d0a;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11543ULL: goto x86_l_2d17;
	case 11549ULL: goto x86_l_2d1d;
	case 11553ULL: goto x86_l_2d21;
	case 11560ULL: goto x86_l_2d28;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11584ULL: goto x86_l_2d40;
	case 11588ULL: goto x86_l_2d44;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11616ULL: goto x86_l_2d60;
	case 11619ULL: goto x86_l_2d63;
	case 11628ULL: goto x86_l_2d6c;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11675ULL: goto x86_l_2d9b;
	case 11678ULL: goto x86_l_2d9e;
	case 11684ULL: goto x86_l_2da4;
	case 11688ULL: goto x86_l_2da8;
	case 11694ULL: goto x86_l_2dae;
	case 11698ULL: goto x86_l_2db2;
	case 11701ULL: goto x86_l_2db5;
	case 11707ULL: goto x86_l_2dbb;
	case 11711ULL: goto x86_l_2dbf;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11737ULL: goto x86_l_2dd9;
	case 11741ULL: goto x86_l_2ddd;
	case 11748ULL: goto x86_l_2de4;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11760ULL: goto x86_l_2df0;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11774ULL: goto x86_l_2dfe;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11788ULL: goto x86_l_2e0c;
	case 11791ULL: goto x86_l_2e0f;
	case 11797ULL: goto x86_l_2e15;
	case 11801ULL: goto x86_l_2e19;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11832ULL: goto x86_l_2e38;
	case 11836ULL: goto x86_l_2e3c;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11855ULL: goto x86_l_2e4f;
	case 11864ULL: goto x86_l_2e58;
	case 11867ULL: goto x86_l_2e5b;
	case 11876ULL: goto x86_l_2e64;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11897ULL: goto x86_l_2e79;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11926ULL: goto x86_l_2e96;
	case 11929ULL: goto x86_l_2e99;
	case 11935ULL: goto x86_l_2e9f;
	case 11939ULL: goto x86_l_2ea3;
	case 11945ULL: goto x86_l_2ea9;
	case 11949ULL: goto x86_l_2ead;
	case 11952ULL: goto x86_l_2eb0;
	case 11958ULL: goto x86_l_2eb6;
	case 11962ULL: goto x86_l_2eba;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11988ULL: goto x86_l_2ed4;
	case 11992ULL: goto x86_l_2ed8;
	case 11999ULL: goto x86_l_2edf;
	case 12004ULL: goto x86_l_2ee4;
	case 12009ULL: goto x86_l_2ee9;
	case 12011ULL: goto x86_l_2eeb;
	case 12015ULL: goto x86_l_2eef;
	case 12017ULL: goto x86_l_2ef1;
	case 12019ULL: goto x86_l_2ef3;
	case 12025ULL: goto x86_l_2ef9;
	case 12029ULL: goto x86_l_2efd;
	case 12035ULL: goto x86_l_2f03;
	case 12039ULL: goto x86_l_2f07;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12052ULL: goto x86_l_2f14;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12083ULL: goto x86_l_2f33;
	case 12087ULL: goto x86_l_2f37;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12115ULL: goto x86_l_2f53;
	case 12118ULL: goto x86_l_2f56;
	case 12127ULL: goto x86_l_2f5f;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12170ULL: goto x86_l_2f8a;
	case 12175ULL: goto x86_l_2f8f;
	case 12177ULL: goto x86_l_2f91;
	case 12180ULL: goto x86_l_2f94;
	case 12186ULL: goto x86_l_2f9a;
	case 12190ULL: goto x86_l_2f9e;
	case 12196ULL: goto x86_l_2fa4;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12209ULL: goto x86_l_2fb1;
	case 12213ULL: goto x86_l_2fb5;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12239ULL: goto x86_l_2fcf;
	case 12243ULL: goto x86_l_2fd3;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	case 12266ULL: goto x86_l_2fea;
	case 12268ULL: goto x86_l_2fec;
	case 12270ULL: goto x86_l_2fee;
	case 12276ULL: goto x86_l_2ff4;
	case 12280ULL: goto x86_l_2ff8;
	case 12286ULL: goto x86_l_2ffe;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12299ULL: goto x86_l_300b;
	case 12303ULL: goto x86_l_300f;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12334ULL: goto x86_l_302e;
	case 12338ULL: goto x86_l_3032;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12366ULL: goto x86_l_304e;
	case 12369ULL: goto x86_l_3051;
	case 12378ULL: goto x86_l_305a;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12399ULL: goto x86_l_306f;
	case 12404ULL: goto x86_l_3074;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12419ULL: goto x86_l_3083;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12428ULL: goto x86_l_308c;
	case 12431ULL: goto x86_l_308f;
	case 12437ULL: goto x86_l_3095;
	case 12441ULL: goto x86_l_3099;
	case 12447ULL: goto x86_l_309f;
	case 12451ULL: goto x86_l_30a3;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	case 12464ULL: goto x86_l_30b0;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12490ULL: goto x86_l_30ca;
	case 12494ULL: goto x86_l_30ce;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12513ULL: goto x86_l_30e1;
	case 12517ULL: goto x86_l_30e5;
	case 12519ULL: goto x86_l_30e7;
	case 12521ULL: goto x86_l_30e9;
	case 12527ULL: goto x86_l_30ef;
	case 12531ULL: goto x86_l_30f3;
	case 12537ULL: goto x86_l_30f9;
	case 12541ULL: goto x86_l_30fd;
	case 12544ULL: goto x86_l_3100;
	case 12550ULL: goto x86_l_3106;
	case 12554ULL: goto x86_l_310a;
	case 12561ULL: goto x86_l_3111;
	case 12566ULL: goto x86_l_3116;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12585ULL: goto x86_l_3129;
	case 12589ULL: goto x86_l_312d;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12603ULL: goto x86_l_313b;
	case 12608ULL: goto x86_l_3140;
	case 12617ULL: goto x86_l_3149;
	case 12620ULL: goto x86_l_314c;
	case 12629ULL: goto x86_l_3155;
	case 12638ULL: goto x86_l_315e;
	case 12643ULL: goto x86_l_3163;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12679ULL: goto x86_l_3187;
	case 12682ULL: goto x86_l_318a;
	case 12688ULL: goto x86_l_3190;
	case 12692ULL: goto x86_l_3194;
	case 12698ULL: goto x86_l_319a;
	case 12702ULL: goto x86_l_319e;
	case 12705ULL: goto x86_l_31a1;
	case 12711ULL: goto x86_l_31a7;
	case 12715ULL: goto x86_l_31ab;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12741ULL: goto x86_l_31c5;
	case 12745ULL: goto x86_l_31c9;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12764ULL: goto x86_l_31dc;
	case 12768ULL: goto x86_l_31e0;
	case 12770ULL: goto x86_l_31e2;
	case 12772ULL: goto x86_l_31e4;
	case 12778ULL: goto x86_l_31ea;
	case 12782ULL: goto x86_l_31ee;
	case 12788ULL: goto x86_l_31f4;
	case 12792ULL: goto x86_l_31f8;
	case 12795ULL: goto x86_l_31fb;
	case 12801ULL: goto x86_l_3201;
	case 12805ULL: goto x86_l_3205;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12822ULL: goto x86_l_3216;
	case 12827ULL: goto x86_l_321b;
	case 12836ULL: goto x86_l_3224;
	case 12840ULL: goto x86_l_3228;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12854ULL: goto x86_l_3236;
	case 12859ULL: goto x86_l_323b;
	case 12868ULL: goto x86_l_3244;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2aca:
	/* 0x2aca: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2acd:
	/* 0x2acd: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2ad3:
	/* 0x2ad3: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ad7:
	/* 0x2ad7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ade:
	/* 0x2ade: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ae8:
	/* 0x2ae8: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2af1:
	/* 0x2af1: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2af5:
	/* 0x2af5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2afc:
	/* 0x2afc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b01:
	/* 0x2b01: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b06:
	/* 0x2b06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b08:
	/* 0x2b08: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0c:
	/* 0x2b0c: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_2b0e:
	/* 0x2b0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b10:
	/* 0x2b10: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2b16:
	/* 0x2b16: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b1a:
	/* 0x2b1a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2b20:
	/* 0x2b20: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b24:
	/* 0x2b24: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2b27:
	/* 0x2b27: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2b2d:
	/* 0x2b2d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b31:
	/* 0x2b31: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b38:
	/* 0x2b38: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b42:
	/* 0x2b42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b47:
	/* 0x2b47: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b50:
	/* 0x2b50: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b54:
	/* 0x2b54: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b5b:
	/* 0x2b5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b60:
	/* 0x2b60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b62:
	/* 0x2b62: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2b67:
	/* 0x2b67: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b70:
	/* 0x2b70: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b73:
	/* 0x2b73: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b7c:
	/* 0x2b7c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b85:
	/* 0x2b85: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b8a:
	/* 0x2b8a: lea    rdx,[rax+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b8e:
	/* 0x2b8e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b93:
	/* 0x2b93: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b98:
	/* 0x2b98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b9d:
	/* 0x2b9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba2:
	/* 0x2ba2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba4:
	/* 0x2ba4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba9:
	/* 0x2ba9: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_2bab:
	/* 0x2bab: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2bae:
	/* 0x2bae: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2bb4:
	/* 0x2bb4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bb8:
	/* 0x2bb8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2bc5:
	/* 0x2bc5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2bcb:
	/* 0x2bcb: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2bcf:
	/* 0x2bcf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2be0:
	/* 0x2be0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2be9:
	/* 0x2be9: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2bed:
	/* 0x2bed: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bfe:
	/* 0x2bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c00:
	/* 0x2c00: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c04:
	/* 0x2c04: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_2c06:
	/* 0x2c06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c08:
	/* 0x2c08: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2c0e:
	/* 0x2c0e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c12:
	/* 0x2c12: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2c18:
	/* 0x2c18: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c1c:
	/* 0x2c1c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2c1f:
	/* 0x2c1f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2c25:
	/* 0x2c25: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c29:
	/* 0x2c29: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c30:
	/* 0x2c30: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c35:
	/* 0x2c35: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c3f:
	/* 0x2c3f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c48:
	/* 0x2c48: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c4c:
	/* 0x2c4c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c53:
	/* 0x2c53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c58:
	/* 0x2c58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5a:
	/* 0x2c5a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2c5f:
	/* 0x2c5f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c68:
	/* 0x2c68: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c74:
	/* 0x2c74: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c82:
	/* 0x2c82: lea    rdx,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c86:
	/* 0x2c86: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c90:
	/* 0x2c90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c95:
	/* 0x2c95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c9a:
	/* 0x2c9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9c:
	/* 0x2c9c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_2ca3:
	/* 0x2ca3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2ca6:
	/* 0x2ca6: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2cac:
	/* 0x2cac: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cb0:
	/* 0x2cb0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cba:
	/* 0x2cba: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2cbd:
	/* 0x2cbd: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2cc3:
	/* 0x2cc3: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2cc7:
	/* 0x2cc7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2cce:
	/* 0x2cce: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2cd8:
	/* 0x2cd8: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ce1:
	/* 0x2ce1: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ce5:
	/* 0x2ce5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2cec:
	/* 0x2cec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cf6:
	/* 0x2cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf8:
	/* 0x2cf8: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_2cfe:
	/* 0x2cfe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d00:
	/* 0x2d00: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2d06:
	/* 0x2d06: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d0a:
	/* 0x2d0a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2d10:
	/* 0x2d10: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d14:
	/* 0x2d14: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2d17:
	/* 0x2d17: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2d1d:
	/* 0x2d1d: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d21:
	/* 0x2d21: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d28:
	/* 0x2d28: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d32:
	/* 0x2d32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d37:
	/* 0x2d37: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d40:
	/* 0x2d40: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d44:
	/* 0x2d44: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d50:
	/* 0x2d50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d52:
	/* 0x2d52: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2d57:
	/* 0x2d57: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d60:
	/* 0x2d60: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d63:
	/* 0x2d63: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d6c:
	/* 0x2d6c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d75:
	/* 0x2d75: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d7a:
	/* 0x2d7a: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2d7e:
	/* 0x2d7e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d83:
	/* 0x2d83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d88:
	/* 0x2d88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d92:
	/* 0x2d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d94:
	/* 0x2d94: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d99:
	/* 0x2d99: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_2d9b:
	/* 0x2d9b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2d9e:
	/* 0x2d9e: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2da4:
	/* 0x2da4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2da8:
	/* 0x2da8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2dae:
	/* 0x2dae: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db2:
	/* 0x2db2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2db5:
	/* 0x2db5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2dbb:
	/* 0x2dbb: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2dbf:
	/* 0x2dbf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dcb:
	/* 0x2dcb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dd0:
	/* 0x2dd0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dd9:
	/* 0x2dd9: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ddd:
	/* 0x2ddd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2de4:
	/* 0x2de4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de9:
	/* 0x2de9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dee:
	/* 0x2dee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df0:
	/* 0x2df0: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df4:
	/* 0x2df4: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_2df6:
	/* 0x2df6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2df8:
	/* 0x2df8: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2dfe:
	/* 0x2dfe: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e02:
	/* 0x2e02: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2e08:
	/* 0x2e08: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e0c:
	/* 0x2e0c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2e0f:
	/* 0x2e0f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2e15:
	/* 0x2e15: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2e19:
	/* 0x2e19: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e20:
	/* 0x2e20: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e25:
	/* 0x2e25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e2a:
	/* 0x2e2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e2f:
	/* 0x2e2f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e38:
	/* 0x2e38: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e3c:
	/* 0x2e3c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e43:
	/* 0x2e43: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e48:
	/* 0x2e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4a:
	/* 0x2e4a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2e4f:
	/* 0x2e4f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e58:
	/* 0x2e58: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e64:
	/* 0x2e64: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e6d:
	/* 0x2e6d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e72:
	/* 0x2e72: lea    rdx,[rax+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e79:
	/* 0x2e79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e83:
	/* 0x2e83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e88:
	/* 0x2e88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8d:
	/* 0x2e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8f:
	/* 0x2e8f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e94:
	/* 0x2e94: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2e96:
	/* 0x2e96: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e99:
	/* 0x2e99: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2e9f:
	/* 0x2e9f: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ea3:
	/* 0x2ea3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ead:
	/* 0x2ead: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2eb0:
	/* 0x2eb0: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2eb6:
	/* 0x2eb6: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2eba:
	/* 0x2eba: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ecb:
	/* 0x2ecb: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ed4:
	/* 0x2ed4: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ed8:
	/* 0x2ed8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2edf:
	/* 0x2edf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee4:
	/* 0x2ee4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ee9:
	/* 0x2ee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eeb:
	/* 0x2eeb: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eef:
	/* 0x2eef: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2ef1:
	/* 0x2ef1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ef3:
	/* 0x2ef3: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2ef9:
	/* 0x2ef9: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2efd:
	/* 0x2efd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2f03:
	/* 0x2f03: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f07:
	/* 0x2f07: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2f0a:
	/* 0x2f0a: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2f10:
	/* 0x2f10: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f14:
	/* 0x2f14: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f1b:
	/* 0x2f1b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f20:
	/* 0x2f20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f25:
	/* 0x2f25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f2a:
	/* 0x2f2a: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f33:
	/* 0x2f33: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f37:
	/* 0x2f37: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f43:
	/* 0x2f43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f45:
	/* 0x2f45: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2f4a:
	/* 0x2f4a: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f53:
	/* 0x2f53: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f56:
	/* 0x2f56: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f68:
	/* 0x2f68: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f6d:
	/* 0x2f6d: lea    rdx,[rax+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f74:
	/* 0x2f74: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f79:
	/* 0x2f79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f83:
	/* 0x2f83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f88:
	/* 0x2f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8a:
	/* 0x2f8a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f8f:
	/* 0x2f8f: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2f91:
	/* 0x2f91: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f94:
	/* 0x2f94: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_2f9a:
	/* 0x2f9a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f9e:
	/* 0x2f9e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2fab:
	/* 0x2fab: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_2fb1:
	/* 0x2fb1: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2fb5:
	/* 0x2fb5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fbc:
	/* 0x2fbc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2fc6:
	/* 0x2fc6: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fcf:
	/* 0x2fcf: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2fd3:
	/* 0x2fd3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fda:
	/* 0x2fda: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fe4:
	/* 0x2fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe6:
	/* 0x2fe6: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fea:
	/* 0x2fea: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2fec:
	/* 0x2fec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fee:
	/* 0x2fee: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_2ff4:
	/* 0x2ff4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ff8:
	/* 0x2ff8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ffe:
	/* 0x2ffe: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3002:
	/* 0x3002: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3005:
	/* 0x3005: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_300b:
	/* 0x300b: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_300f:
	/* 0x300f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3016:
	/* 0x3016: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301b:
	/* 0x301b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3020:
	/* 0x3020: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3025:
	/* 0x3025: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_302e:
	/* 0x302e: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3032:
	/* 0x3032: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3039:
	/* 0x3039: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_303e:
	/* 0x303e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3040:
	/* 0x3040: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3045:
	/* 0x3045: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_304e:
	/* 0x304e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3051:
	/* 0x3051: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_305a:
	/* 0x305a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3063:
	/* 0x3063: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3068:
	/* 0x3068: lea    rdx,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_306f:
	/* 0x306f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3074:
	/* 0x3074: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3079:
	/* 0x3079: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_307e:
	/* 0x307e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3083:
	/* 0x3083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3085:
	/* 0x3085: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_308a:
	/* 0x308a: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_308c:
	/* 0x308c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_308f:
	/* 0x308f: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3095:
	/* 0x3095: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3099:
	/* 0x3099: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_309f:
	/* 0x309f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a3:
	/* 0x30a3: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_30a6:
	/* 0x30a6: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_30ac:
	/* 0x30ac: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_30b0:
	/* 0x30b0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30b7:
	/* 0x30b7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30bc:
	/* 0x30bc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_30c1:
	/* 0x30c1: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30ca:
	/* 0x30ca: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_30ce:
	/* 0x30ce: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30d5:
	/* 0x30d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30da:
	/* 0x30da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30df:
	/* 0x30df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e1:
	/* 0x30e1: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e5:
	/* 0x30e5: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_30e7:
	/* 0x30e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30e9:
	/* 0x30e9: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_30ef:
	/* 0x30ef: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30f3:
	/* 0x30f3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_30f9:
	/* 0x30f9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30fd:
	/* 0x30fd: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3100:
	/* 0x3100: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3106:
	/* 0x3106: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_310a:
	/* 0x310a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3111:
	/* 0x3111: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3116:
	/* 0x3116: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_311b:
	/* 0x311b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3120:
	/* 0x3120: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3129:
	/* 0x3129: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_312d:
	/* 0x312d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3134:
	/* 0x3134: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3139:
	/* 0x3139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313b:
	/* 0x313b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3140:
	/* 0x3140: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3149:
	/* 0x3149: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_314c:
	/* 0x314c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3155:
	/* 0x3155: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_315e:
	/* 0x315e: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3163:
	/* 0x3163: lea    rdx,[rax+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_316a:
	/* 0x316a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316f:
	/* 0x316f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3174:
	/* 0x3174: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3179:
	/* 0x3179: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_317e:
	/* 0x317e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3180:
	/* 0x3180: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3185:
	/* 0x3185: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_3187:
	/* 0x3187: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_318a:
	/* 0x318a: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3190:
	/* 0x3190: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3194:
	/* 0x3194: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_319a:
	/* 0x319a: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319e:
	/* 0x319e: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_31a1:
	/* 0x31a1: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_31a7:
	/* 0x31a7: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_31ab:
	/* 0x31ab: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31b2:
	/* 0x31b2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31b7:
	/* 0x31b7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31bc:
	/* 0x31bc: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31c5:
	/* 0x31c5: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_31c9:
	/* 0x31c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31d0:
	/* 0x31d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31d5:
	/* 0x31d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31da:
	/* 0x31da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dc:
	/* 0x31dc: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e0:
	/* 0x31e0: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_31e2:
	/* 0x31e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31e4:
	/* 0x31e4: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_31ea:
	/* 0x31ea: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31ee:
	/* 0x31ee: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_31f4:
	/* 0x31f4: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31f8:
	/* 0x31f8: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_31fb:
	/* 0x31fb: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3201:
	/* 0x3201: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3205:
	/* 0x3205: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_320c:
	/* 0x320c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3211:
	/* 0x3211: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3216:
	/* 0x3216: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_321b:
	/* 0x321b: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3224:
	/* 0x3224: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3228:
	/* 0x3228: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_322f:
	/* 0x322f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3234:
	/* 0x3234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3236:
	/* 0x3236: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_323b:
	/* 0x323b: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3244:
	/* 0x3244: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
	return 12871ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12871ULL: goto x86_l_3247;
	case 12880ULL: goto x86_l_3250;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12901ULL: goto x86_l_3265;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12916ULL: goto x86_l_3274;
	case 12921ULL: goto x86_l_3279;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12930ULL: goto x86_l_3282;
	case 12933ULL: goto x86_l_3285;
	case 12939ULL: goto x86_l_328b;
	case 12943ULL: goto x86_l_328f;
	case 12949ULL: goto x86_l_3295;
	case 12953ULL: goto x86_l_3299;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12966ULL: goto x86_l_32a6;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12992ULL: goto x86_l_32c0;
	case 12996ULL: goto x86_l_32c4;
	case 13003ULL: goto x86_l_32cb;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13015ULL: goto x86_l_32d7;
	case 13019ULL: goto x86_l_32db;
	case 13021ULL: goto x86_l_32dd;
	case 13023ULL: goto x86_l_32df;
	case 13029ULL: goto x86_l_32e5;
	case 13033ULL: goto x86_l_32e9;
	case 13039ULL: goto x86_l_32ef;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13052ULL: goto x86_l_32fc;
	case 13056ULL: goto x86_l_3300;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13078ULL: goto x86_l_3316;
	case 13087ULL: goto x86_l_331f;
	case 13091ULL: goto x86_l_3323;
	case 13098ULL: goto x86_l_332a;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13119ULL: goto x86_l_333f;
	case 13122ULL: goto x86_l_3342;
	case 13131ULL: goto x86_l_334b;
	case 13140ULL: goto x86_l_3354;
	case 13145ULL: goto x86_l_3359;
	case 13152ULL: goto x86_l_3360;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13174ULL: goto x86_l_3376;
	case 13179ULL: goto x86_l_337b;
	case 13181ULL: goto x86_l_337d;
	case 13184ULL: goto x86_l_3380;
	case 13190ULL: goto x86_l_3386;
	case 13194ULL: goto x86_l_338a;
	case 13200ULL: goto x86_l_3390;
	case 13204ULL: goto x86_l_3394;
	case 13207ULL: goto x86_l_3397;
	case 13213ULL: goto x86_l_339d;
	case 13217ULL: goto x86_l_33a1;
	case 13224ULL: goto x86_l_33a8;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13243ULL: goto x86_l_33bb;
	case 13247ULL: goto x86_l_33bf;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13264ULL: goto x86_l_33d0;
	case 13266ULL: goto x86_l_33d2;
	case 13270ULL: goto x86_l_33d6;
	case 13272ULL: goto x86_l_33d8;
	case 13274ULL: goto x86_l_33da;
	case 13280ULL: goto x86_l_33e0;
	case 13284ULL: goto x86_l_33e4;
	case 13290ULL: goto x86_l_33ea;
	case 13294ULL: goto x86_l_33ee;
	case 13297ULL: goto x86_l_33f1;
	case 13303ULL: goto x86_l_33f7;
	case 13307ULL: goto x86_l_33fb;
	case 13314ULL: goto x86_l_3402;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13338ULL: goto x86_l_341a;
	case 13342ULL: goto x86_l_341e;
	case 13349ULL: goto x86_l_3425;
	case 13354ULL: goto x86_l_342a;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13370ULL: goto x86_l_343a;
	case 13373ULL: goto x86_l_343d;
	case 13382ULL: goto x86_l_3446;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13441ULL: goto x86_l_3481;
	case 13445ULL: goto x86_l_3485;
	case 13451ULL: goto x86_l_348b;
	case 13455ULL: goto x86_l_348f;
	case 13458ULL: goto x86_l_3492;
	case 13464ULL: goto x86_l_3498;
	case 13468ULL: goto x86_l_349c;
	case 13475ULL: goto x86_l_34a3;
	case 13480ULL: goto x86_l_34a8;
	case 13485ULL: goto x86_l_34ad;
	case 13494ULL: goto x86_l_34b6;
	case 13498ULL: goto x86_l_34ba;
	case 13505ULL: goto x86_l_34c1;
	case 13510ULL: goto x86_l_34c6;
	case 13515ULL: goto x86_l_34cb;
	case 13517ULL: goto x86_l_34cd;
	case 13521ULL: goto x86_l_34d1;
	case 13523ULL: goto x86_l_34d3;
	case 13525ULL: goto x86_l_34d5;
	case 13531ULL: goto x86_l_34db;
	case 13535ULL: goto x86_l_34df;
	case 13541ULL: goto x86_l_34e5;
	case 13545ULL: goto x86_l_34e9;
	case 13548ULL: goto x86_l_34ec;
	case 13554ULL: goto x86_l_34f2;
	case 13558ULL: goto x86_l_34f6;
	case 13565ULL: goto x86_l_34fd;
	case 13570ULL: goto x86_l_3502;
	case 13575ULL: goto x86_l_3507;
	case 13580ULL: goto x86_l_350c;
	case 13589ULL: goto x86_l_3515;
	case 13593ULL: goto x86_l_3519;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13621ULL: goto x86_l_3535;
	case 13624ULL: goto x86_l_3538;
	case 13633ULL: goto x86_l_3541;
	case 13642ULL: goto x86_l_354a;
	case 13647ULL: goto x86_l_354f;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13676ULL: goto x86_l_356c;
	case 13681ULL: goto x86_l_3571;
	case 13683ULL: goto x86_l_3573;
	case 13686ULL: goto x86_l_3576;
	case 13692ULL: goto x86_l_357c;
	case 13696ULL: goto x86_l_3580;
	case 13702ULL: goto x86_l_3586;
	case 13706ULL: goto x86_l_358a;
	case 13709ULL: goto x86_l_358d;
	case 13715ULL: goto x86_l_3593;
	case 13719ULL: goto x86_l_3597;
	case 13726ULL: goto x86_l_359e;
	case 13731ULL: goto x86_l_35a3;
	case 13736ULL: goto x86_l_35a8;
	case 13745ULL: goto x86_l_35b1;
	case 13749ULL: goto x86_l_35b5;
	case 13756ULL: goto x86_l_35bc;
	case 13761ULL: goto x86_l_35c1;
	case 13766ULL: goto x86_l_35c6;
	case 13768ULL: goto x86_l_35c8;
	case 13772ULL: goto x86_l_35cc;
	case 13774ULL: goto x86_l_35ce;
	case 13776ULL: goto x86_l_35d0;
	case 13782ULL: goto x86_l_35d6;
	case 13786ULL: goto x86_l_35da;
	case 13792ULL: goto x86_l_35e0;
	case 13796ULL: goto x86_l_35e4;
	case 13799ULL: goto x86_l_35e7;
	case 13805ULL: goto x86_l_35ed;
	case 13809ULL: goto x86_l_35f1;
	case 13816ULL: goto x86_l_35f8;
	case 13821ULL: goto x86_l_35fd;
	case 13826ULL: goto x86_l_3602;
	case 13831ULL: goto x86_l_3607;
	case 13840ULL: goto x86_l_3610;
	case 13844ULL: goto x86_l_3614;
	case 13851ULL: goto x86_l_361b;
	case 13856ULL: goto x86_l_3620;
	case 13858ULL: goto x86_l_3622;
	case 13863ULL: goto x86_l_3627;
	case 13872ULL: goto x86_l_3630;
	case 13875ULL: goto x86_l_3633;
	case 13884ULL: goto x86_l_363c;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13905ULL: goto x86_l_3651;
	case 13910ULL: goto x86_l_3656;
	case 13915ULL: goto x86_l_365b;
	case 13920ULL: goto x86_l_3660;
	case 13925ULL: goto x86_l_3665;
	case 13927ULL: goto x86_l_3667;
	case 13932ULL: goto x86_l_366c;
	case 13934ULL: goto x86_l_366e;
	case 13937ULL: goto x86_l_3671;
	case 13943ULL: goto x86_l_3677;
	case 13947ULL: goto x86_l_367b;
	case 13953ULL: goto x86_l_3681;
	case 13957ULL: goto x86_l_3685;
	case 13960ULL: goto x86_l_3688;
	case 13966ULL: goto x86_l_368e;
	case 13970ULL: goto x86_l_3692;
	case 13977ULL: goto x86_l_3699;
	case 13982ULL: goto x86_l_369e;
	case 13987ULL: goto x86_l_36a3;
	case 13996ULL: goto x86_l_36ac;
	case 14000ULL: goto x86_l_36b0;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14017ULL: goto x86_l_36c1;
	case 14019ULL: goto x86_l_36c3;
	case 14023ULL: goto x86_l_36c7;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14033ULL: goto x86_l_36d1;
	case 14037ULL: goto x86_l_36d5;
	case 14043ULL: goto x86_l_36db;
	case 14047ULL: goto x86_l_36df;
	case 14050ULL: goto x86_l_36e2;
	case 14056ULL: goto x86_l_36e8;
	case 14060ULL: goto x86_l_36ec;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14077ULL: goto x86_l_36fd;
	case 14082ULL: goto x86_l_3702;
	case 14091ULL: goto x86_l_370b;
	case 14095ULL: goto x86_l_370f;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14109ULL: goto x86_l_371d;
	case 14114ULL: goto x86_l_3722;
	case 14123ULL: goto x86_l_372b;
	case 14126ULL: goto x86_l_372e;
	case 14135ULL: goto x86_l_3737;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
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
	case 14198ULL: goto x86_l_3776;
	case 14204ULL: goto x86_l_377c;
	case 14208ULL: goto x86_l_3780;
	case 14211ULL: goto x86_l_3783;
	case 14217ULL: goto x86_l_3789;
	case 14221ULL: goto x86_l_378d;
	case 14228ULL: goto x86_l_3794;
	case 14233ULL: goto x86_l_3799;
	case 14238ULL: goto x86_l_379e;
	case 14247ULL: goto x86_l_37a7;
	case 14251ULL: goto x86_l_37ab;
	case 14258ULL: goto x86_l_37b2;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14274ULL: goto x86_l_37c2;
	case 14276ULL: goto x86_l_37c4;
	case 14278ULL: goto x86_l_37c6;
	case 14284ULL: goto x86_l_37cc;
	case 14288ULL: goto x86_l_37d0;
	case 14294ULL: goto x86_l_37d6;
	case 14298ULL: goto x86_l_37da;
	case 14301ULL: goto x86_l_37dd;
	case 14307ULL: goto x86_l_37e3;
	case 14311ULL: goto x86_l_37e7;
	case 14318ULL: goto x86_l_37ee;
	case 14323ULL: goto x86_l_37f3;
	case 14328ULL: goto x86_l_37f8;
	case 14333ULL: goto x86_l_37fd;
	case 14342ULL: goto x86_l_3806;
	case 14346ULL: goto x86_l_380a;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14374ULL: goto x86_l_3826;
	case 14377ULL: goto x86_l_3829;
	case 14386ULL: goto x86_l_3832;
	case 14395ULL: goto x86_l_383b;
	case 14400ULL: goto x86_l_3840;
	case 14407ULL: goto x86_l_3847;
	case 14412ULL: goto x86_l_384c;
	case 14417ULL: goto x86_l_3851;
	case 14422ULL: goto x86_l_3856;
	case 14427ULL: goto x86_l_385b;
	case 14429ULL: goto x86_l_385d;
	case 14434ULL: goto x86_l_3862;
	case 14436ULL: goto x86_l_3864;
	case 14439ULL: goto x86_l_3867;
	case 14445ULL: goto x86_l_386d;
	case 14449ULL: goto x86_l_3871;
	case 14455ULL: goto x86_l_3877;
	case 14459ULL: goto x86_l_387b;
	case 14462ULL: goto x86_l_387e;
	case 14468ULL: goto x86_l_3884;
	case 14472ULL: goto x86_l_3888;
	case 14479ULL: goto x86_l_388f;
	case 14484ULL: goto x86_l_3894;
	case 14489ULL: goto x86_l_3899;
	case 14498ULL: goto x86_l_38a2;
	case 14502ULL: goto x86_l_38a6;
	case 14509ULL: goto x86_l_38ad;
	case 14514ULL: goto x86_l_38b2;
	case 14519ULL: goto x86_l_38b7;
	case 14521ULL: goto x86_l_38b9;
	case 14525ULL: goto x86_l_38bd;
	case 14527ULL: goto x86_l_38bf;
	case 14529ULL: goto x86_l_38c1;
	case 14535ULL: goto x86_l_38c7;
	case 14539ULL: goto x86_l_38cb;
	case 14545ULL: goto x86_l_38d1;
	case 14549ULL: goto x86_l_38d5;
	case 14552ULL: goto x86_l_38d8;
	case 14558ULL: goto x86_l_38de;
	case 14562ULL: goto x86_l_38e2;
	case 14569ULL: goto x86_l_38e9;
	case 14574ULL: goto x86_l_38ee;
	case 14579ULL: goto x86_l_38f3;
	case 14584ULL: goto x86_l_38f8;
	case 14593ULL: goto x86_l_3901;
	case 14597ULL: goto x86_l_3905;
	case 14604ULL: goto x86_l_390c;
	case 14609ULL: goto x86_l_3911;
	case 14611ULL: goto x86_l_3913;
	case 14616ULL: goto x86_l_3918;
	case 14625ULL: goto x86_l_3921;
	case 14628ULL: goto x86_l_3924;
	case 14637ULL: goto x86_l_392d;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14668ULL: goto x86_l_394c;
	case 14673ULL: goto x86_l_3951;
	case 14678ULL: goto x86_l_3956;
	case 14680ULL: goto x86_l_3958;
	case 14685ULL: goto x86_l_395d;
	case 14687ULL: goto x86_l_395f;
	case 14690ULL: goto x86_l_3962;
	case 14696ULL: goto x86_l_3968;
	case 14700ULL: goto x86_l_396c;
	case 14706ULL: goto x86_l_3972;
	case 14710ULL: goto x86_l_3976;
	case 14713ULL: goto x86_l_3979;
	case 14719ULL: goto x86_l_397f;
	case 14723ULL: goto x86_l_3983;
	case 14730ULL: goto x86_l_398a;
	case 14735ULL: goto x86_l_398f;
	case 14740ULL: goto x86_l_3994;
	case 14749ULL: goto x86_l_399d;
	case 14753ULL: goto x86_l_39a1;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14770ULL: goto x86_l_39b2;
	case 14772ULL: goto x86_l_39b4;
	case 14776ULL: goto x86_l_39b8;
	case 14778ULL: goto x86_l_39ba;
	case 14780ULL: goto x86_l_39bc;
	case 14786ULL: goto x86_l_39c2;
	case 14790ULL: goto x86_l_39c6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3247:
	/* 0x3247: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3250:
	/* 0x3250: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3259:
	/* 0x3259: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_325e:
	/* 0x325e: lea    rdx,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3265:
	/* 0x3265: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_326a:
	/* 0x326a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_326f:
	/* 0x326f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3274:
	/* 0x3274: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3279:
	/* 0x3279: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_327b:
	/* 0x327b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3280:
	/* 0x3280: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_3282:
	/* 0x3282: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3285:
	/* 0x3285: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_328b:
	/* 0x328b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_328f:
	/* 0x328f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3295:
	/* 0x3295: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3299:
	/* 0x3299: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_329c:
	/* 0x329c: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_32a2:
	/* 0x32a2: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_32a6:
	/* 0x32a6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32ad:
	/* 0x32ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32b2:
	/* 0x32b2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32b7:
	/* 0x32b7: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32c0:
	/* 0x32c0: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_32c4:
	/* 0x32c4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32cb:
	/* 0x32cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d0:
	/* 0x32d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32d5:
	/* 0x32d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d7:
	/* 0x32d7: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32db:
	/* 0x32db: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_32dd:
	/* 0x32dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32df:
	/* 0x32df: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_32e5:
	/* 0x32e5: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32e9:
	/* 0x32e9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_32ef:
	/* 0x32ef: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32f3:
	/* 0x32f3: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_32f6:
	/* 0x32f6: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_32fc:
	/* 0x32fc: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3300:
	/* 0x3300: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3307:
	/* 0x3307: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_330c:
	/* 0x330c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3311:
	/* 0x3311: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3316:
	/* 0x3316: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_331f:
	/* 0x331f: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3323:
	/* 0x3323: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_332a:
	/* 0x332a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_332f:
	/* 0x332f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3331:
	/* 0x3331: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3336:
	/* 0x3336: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_333f:
	/* 0x333f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3342:
	/* 0x3342: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_334b:
	/* 0x334b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3354:
	/* 0x3354: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3359:
	/* 0x3359: lea    rdx,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3360:
	/* 0x3360: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3365:
	/* 0x3365: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_336a:
	/* 0x336a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_336f:
	/* 0x336f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3374:
	/* 0x3374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3376:
	/* 0x3376: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337b:
	/* 0x337b: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_337d:
	/* 0x337d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3380:
	/* 0x3380: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3386:
	/* 0x3386: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_338a:
	/* 0x338a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3390:
	/* 0x3390: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3394:
	/* 0x3394: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3397:
	/* 0x3397: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_339d:
	/* 0x339d: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_33a1:
	/* 0x33a1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33a8:
	/* 0x33a8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33ad:
	/* 0x33ad: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_33b2:
	/* 0x33b2: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33bb:
	/* 0x33bb: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_33bf:
	/* 0x33bf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33c6:
	/* 0x33c6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33cb:
	/* 0x33cb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33d0:
	/* 0x33d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d2:
	/* 0x33d2: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d6:
	/* 0x33d6: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_33d8:
	/* 0x33d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33da:
	/* 0x33da: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_33e0:
	/* 0x33e0: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33e4:
	/* 0x33e4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_33ea:
	/* 0x33ea: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ee:
	/* 0x33ee: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_33f1:
	/* 0x33f1: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_33f7:
	/* 0x33f7: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_33fb:
	/* 0x33fb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3402:
	/* 0x3402: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3407:
	/* 0x3407: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_340c:
	/* 0x340c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3411:
	/* 0x3411: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_341a:
	/* 0x341a: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_341e:
	/* 0x341e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3425:
	/* 0x3425: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_342a:
	/* 0x342a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342c:
	/* 0x342c: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3431:
	/* 0x3431: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_343a:
	/* 0x343a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_343d:
	/* 0x343d: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3446:
	/* 0x3446: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_344f:
	/* 0x344f: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3454:
	/* 0x3454: lea    rdx,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_345b:
	/* 0x345b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3460:
	/* 0x3460: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3465:
	/* 0x3465: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_346a:
	/* 0x346a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_346f:
	/* 0x346f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3471:
	/* 0x3471: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3476:
	/* 0x3476: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3478:
	/* 0x3478: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_347b:
	/* 0x347b: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3481:
	/* 0x3481: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3485:
	/* 0x3485: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_348b:
	/* 0x348b: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_348f:
	/* 0x348f: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3492:
	/* 0x3492: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3498:
	/* 0x3498: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_349c:
	/* 0x349c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34a3:
	/* 0x34a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34a8:
	/* 0x34a8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34ad:
	/* 0x34ad: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34b6:
	/* 0x34b6: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_34ba:
	/* 0x34ba: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34c1:
	/* 0x34c1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34c6:
	/* 0x34c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34cb:
	/* 0x34cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34cd:
	/* 0x34cd: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d1:
	/* 0x34d1: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_34d3:
	/* 0x34d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34d5:
	/* 0x34d5: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_34db:
	/* 0x34db: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34df:
	/* 0x34df: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_34e5:
	/* 0x34e5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34e9:
	/* 0x34e9: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_34ec:
	/* 0x34ec: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_34f2:
	/* 0x34f2: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_34f6:
	/* 0x34f6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34fd:
	/* 0x34fd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3502:
	/* 0x3502: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3507:
	/* 0x3507: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_350c:
	/* 0x350c: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3515:
	/* 0x3515: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3519:
	/* 0x3519: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3520:
	/* 0x3520: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3525:
	/* 0x3525: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3527:
	/* 0x3527: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_352c:
	/* 0x352c: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3535:
	/* 0x3535: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3538:
	/* 0x3538: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3541:
	/* 0x3541: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_354a:
	/* 0x354a: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_354f:
	/* 0x354f: lea    rdx,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3556:
	/* 0x3556: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_355b:
	/* 0x355b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3560:
	/* 0x3560: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3565:
	/* 0x3565: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_356a:
	/* 0x356a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_356c:
	/* 0x356c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3571:
	/* 0x3571: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3573:
	/* 0x3573: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3576:
	/* 0x3576: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_357c:
	/* 0x357c: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3580:
	/* 0x3580: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3586:
	/* 0x3586: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_358a:
	/* 0x358a: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_358d:
	/* 0x358d: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3593:
	/* 0x3593: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3597:
	/* 0x3597: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_359e:
	/* 0x359e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35a3:
	/* 0x35a3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35a8:
	/* 0x35a8: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35b1:
	/* 0x35b1: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_35b5:
	/* 0x35b5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35bc:
	/* 0x35bc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c1:
	/* 0x35c1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35c6:
	/* 0x35c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c8:
	/* 0x35c8: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35cc:
	/* 0x35cc: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_35ce:
	/* 0x35ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35d0:
	/* 0x35d0: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_35d6:
	/* 0x35d6: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35da:
	/* 0x35da: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_35e0:
	/* 0x35e0: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e4:
	/* 0x35e4: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_35e7:
	/* 0x35e7: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_35ed:
	/* 0x35ed: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_35f1:
	/* 0x35f1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_35f8:
	/* 0x35f8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35fd:
	/* 0x35fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3602:
	/* 0x3602: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3607:
	/* 0x3607: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3610:
	/* 0x3610: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3614:
	/* 0x3614: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_361b:
	/* 0x361b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3620:
	/* 0x3620: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3622:
	/* 0x3622: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3627:
	/* 0x3627: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3630:
	/* 0x3630: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3633:
	/* 0x3633: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_363c:
	/* 0x363c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3645:
	/* 0x3645: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_364a:
	/* 0x364a: lea    rdx,[rax+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3651:
	/* 0x3651: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3656:
	/* 0x3656: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_365b:
	/* 0x365b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3660:
	/* 0x3660: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3665:
	/* 0x3665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3667:
	/* 0x3667: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366c:
	/* 0x366c: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_366e:
	/* 0x366e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3671:
	/* 0x3671: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3677:
	/* 0x3677: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_367b:
	/* 0x367b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3681:
	/* 0x3681: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3685:
	/* 0x3685: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3688:
	/* 0x3688: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_368e:
	/* 0x368e: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3692:
	/* 0x3692: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3699:
	/* 0x3699: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_369e:
	/* 0x369e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36a3:
	/* 0x36a3: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36ac:
	/* 0x36ac: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_36b0:
	/* 0x36b0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36b7:
	/* 0x36b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36bc:
	/* 0x36bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36c1:
	/* 0x36c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c3:
	/* 0x36c3: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36c7:
	/* 0x36c7: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_36c9:
	/* 0x36c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36cb:
	/* 0x36cb: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_36d1:
	/* 0x36d1: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36d5:
	/* 0x36d5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_36db:
	/* 0x36db: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36df:
	/* 0x36df: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_36e2:
	/* 0x36e2: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_36e8:
	/* 0x36e8: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36ec:
	/* 0x36ec: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36f3:
	/* 0x36f3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36f8:
	/* 0x36f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36fd:
	/* 0x36fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3702:
	/* 0x3702: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_370b:
	/* 0x370b: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_370f:
	/* 0x370f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3716:
	/* 0x3716: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_371b:
	/* 0x371b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371d:
	/* 0x371d: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3722:
	/* 0x3722: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_372b:
	/* 0x372b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_372e:
	/* 0x372e: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3737:
	/* 0x3737: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3740:
	/* 0x3740: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3745:
	/* 0x3745: lea    rdx,[rax+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
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
	/* 0x3767: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3769:
	/* 0x3769: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_376c:
	/* 0x376c: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3772:
	/* 0x3772: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3776:
	/* 0x3776: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_377c:
	/* 0x377c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3780:
	/* 0x3780: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3783:
	/* 0x3783: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3789:
	/* 0x3789: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_378d:
	/* 0x378d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3794:
	/* 0x3794: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3799:
	/* 0x3799: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_379e:
	/* 0x379e: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37a7:
	/* 0x37a7: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_37ab:
	/* 0x37ab: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37b2:
	/* 0x37b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b7:
	/* 0x37b7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37bc:
	/* 0x37bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37be:
	/* 0x37be: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c2:
	/* 0x37c2: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_37c4:
	/* 0x37c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37c6:
	/* 0x37c6: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_37cc:
	/* 0x37cc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37d0:
	/* 0x37d0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_37d6:
	/* 0x37d6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37da:
	/* 0x37da: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_37dd:
	/* 0x37dd: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_37e3:
	/* 0x37e3: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_37e7:
	/* 0x37e7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37ee:
	/* 0x37ee: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37f3:
	/* 0x37f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37f8:
	/* 0x37f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37fd:
	/* 0x37fd: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3806:
	/* 0x3806: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_380a:
	/* 0x380a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3811:
	/* 0x3811: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3816:
	/* 0x3816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3818:
	/* 0x3818: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_381d:
	/* 0x381d: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3826:
	/* 0x3826: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3829:
	/* 0x3829: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3832:
	/* 0x3832: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_383b:
	/* 0x383b: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3840:
	/* 0x3840: lea    rdx,[rax+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3847:
	/* 0x3847: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_384c:
	/* 0x384c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3851:
	/* 0x3851: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3856:
	/* 0x3856: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_385b:
	/* 0x385b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_385d:
	/* 0x385d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3862:
	/* 0x3862: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3864:
	/* 0x3864: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3867:
	/* 0x3867: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_386d:
	/* 0x386d: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3871:
	/* 0x3871: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3877:
	/* 0x3877: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_387b:
	/* 0x387b: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_387e:
	/* 0x387e: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3884:
	/* 0x3884: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3888:
	/* 0x3888: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_388f:
	/* 0x388f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3894:
	/* 0x3894: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3899:
	/* 0x3899: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38a2:
	/* 0x38a2: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_38a6:
	/* 0x38a6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_38ad:
	/* 0x38ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38b2:
	/* 0x38b2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_38b7:
	/* 0x38b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b9:
	/* 0x38b9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38bd:
	/* 0x38bd: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_38bf:
	/* 0x38bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38c1:
	/* 0x38c1: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_38c7:
	/* 0x38c7: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38cb:
	/* 0x38cb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_38d1:
	/* 0x38d1: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38d5:
	/* 0x38d5: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_38d8:
	/* 0x38d8: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_38de:
	/* 0x38de: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38e2:
	/* 0x38e2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38e9:
	/* 0x38e9: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38ee:
	/* 0x38ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38f3:
	/* 0x38f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f8:
	/* 0x38f8: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3901:
	/* 0x3901: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3905:
	/* 0x3905: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_390c:
	/* 0x390c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3911:
	/* 0x3911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3913:
	/* 0x3913: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3918:
	/* 0x3918: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3921:
	/* 0x3921: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3924:
	/* 0x3924: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_392d:
	/* 0x392d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3936:
	/* 0x3936: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_393b:
	/* 0x393b: lea    rdx,[rax+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3942:
	/* 0x3942: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3947:
	/* 0x3947: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_394c:
	/* 0x394c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3951:
	/* 0x3951: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3956:
	/* 0x3956: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3958:
	/* 0x3958: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_395d:
	/* 0x395d: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_395f:
	/* 0x395f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3962:
	/* 0x3962: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3968:
	/* 0x3968: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_396c:
	/* 0x396c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3972:
	/* 0x3972: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3976:
	/* 0x3976: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3979:
	/* 0x3979: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_397f:
	/* 0x397f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3983:
	/* 0x3983: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_398a:
	/* 0x398a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_398f:
	/* 0x398f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3994:
	/* 0x3994: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_399d:
	/* 0x399d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_39a1:
	/* 0x39a1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39a8:
	/* 0x39a8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ad:
	/* 0x39ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39b2:
	/* 0x39b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b4:
	/* 0x39b4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39b8:
	/* 0x39b8: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_39ba:
	/* 0x39ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39bc:
	/* 0x39bc: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_39c2:
	/* 0x39c2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39c6:
	/* 0x39c6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
	return 14796ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14796ULL: goto x86_l_39cc;
	case 14800ULL: goto x86_l_39d0;
	case 14803ULL: goto x86_l_39d3;
	case 14809ULL: goto x86_l_39d9;
	case 14813ULL: goto x86_l_39dd;
	case 14820ULL: goto x86_l_39e4;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14844ULL: goto x86_l_39fc;
	case 14848ULL: goto x86_l_3a00;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14862ULL: goto x86_l_3a0e;
	case 14867ULL: goto x86_l_3a13;
	case 14876ULL: goto x86_l_3a1c;
	case 14879ULL: goto x86_l_3a1f;
	case 14888ULL: goto x86_l_3a28;
	case 14897ULL: goto x86_l_3a31;
	case 14902ULL: goto x86_l_3a36;
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
	case 14951ULL: goto x86_l_3a67;
	case 14957ULL: goto x86_l_3a6d;
	case 14961ULL: goto x86_l_3a71;
	case 14964ULL: goto x86_l_3a74;
	case 14970ULL: goto x86_l_3a7a;
	case 14974ULL: goto x86_l_3a7e;
	case 14981ULL: goto x86_l_3a85;
	case 14986ULL: goto x86_l_3a8a;
	case 14991ULL: goto x86_l_3a8f;
	case 15000ULL: goto x86_l_3a98;
	case 15004ULL: goto x86_l_3a9c;
	case 15011ULL: goto x86_l_3aa3;
	case 15016ULL: goto x86_l_3aa8;
	case 15021ULL: goto x86_l_3aad;
	case 15023ULL: goto x86_l_3aaf;
	case 15027ULL: goto x86_l_3ab3;
	case 15029ULL: goto x86_l_3ab5;
	case 15031ULL: goto x86_l_3ab7;
	case 15037ULL: goto x86_l_3abd;
	case 15041ULL: goto x86_l_3ac1;
	case 15047ULL: goto x86_l_3ac7;
	case 15051ULL: goto x86_l_3acb;
	case 15054ULL: goto x86_l_3ace;
	case 15060ULL: goto x86_l_3ad4;
	case 15064ULL: goto x86_l_3ad8;
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15081ULL: goto x86_l_3ae9;
	case 15086ULL: goto x86_l_3aee;
	case 15095ULL: goto x86_l_3af7;
	case 15099ULL: goto x86_l_3afb;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15113ULL: goto x86_l_3b09;
	case 15118ULL: goto x86_l_3b0e;
	case 15127ULL: goto x86_l_3b17;
	case 15130ULL: goto x86_l_3b1a;
	case 15139ULL: goto x86_l_3b23;
	case 15148ULL: goto x86_l_3b2c;
	case 15153ULL: goto x86_l_3b31;
	case 15160ULL: goto x86_l_3b38;
	case 15165ULL: goto x86_l_3b3d;
	case 15170ULL: goto x86_l_3b42;
	case 15175ULL: goto x86_l_3b47;
	case 15180ULL: goto x86_l_3b4c;
	case 15182ULL: goto x86_l_3b4e;
	case 15187ULL: goto x86_l_3b53;
	case 15189ULL: goto x86_l_3b55;
	case 15192ULL: goto x86_l_3b58;
	case 15198ULL: goto x86_l_3b5e;
	case 15202ULL: goto x86_l_3b62;
	case 15208ULL: goto x86_l_3b68;
	case 15212ULL: goto x86_l_3b6c;
	case 15215ULL: goto x86_l_3b6f;
	case 15221ULL: goto x86_l_3b75;
	case 15225ULL: goto x86_l_3b79;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15242ULL: goto x86_l_3b8a;
	case 15251ULL: goto x86_l_3b93;
	case 15255ULL: goto x86_l_3b97;
	case 15262ULL: goto x86_l_3b9e;
	case 15267ULL: goto x86_l_3ba3;
	case 15272ULL: goto x86_l_3ba8;
	case 15274ULL: goto x86_l_3baa;
	case 15278ULL: goto x86_l_3bae;
	case 15280ULL: goto x86_l_3bb0;
	case 15282ULL: goto x86_l_3bb2;
	case 15288ULL: goto x86_l_3bb8;
	case 15292ULL: goto x86_l_3bbc;
	case 15298ULL: goto x86_l_3bc2;
	case 15302ULL: goto x86_l_3bc6;
	case 15305ULL: goto x86_l_3bc9;
	case 15311ULL: goto x86_l_3bcf;
	case 15315ULL: goto x86_l_3bd3;
	case 15322ULL: goto x86_l_3bda;
	case 15327ULL: goto x86_l_3bdf;
	case 15332ULL: goto x86_l_3be4;
	case 15337ULL: goto x86_l_3be9;
	case 15346ULL: goto x86_l_3bf2;
	case 15350ULL: goto x86_l_3bf6;
	case 15357ULL: goto x86_l_3bfd;
	case 15362ULL: goto x86_l_3c02;
	case 15364ULL: goto x86_l_3c04;
	case 15369ULL: goto x86_l_3c09;
	case 15378ULL: goto x86_l_3c12;
	case 15381ULL: goto x86_l_3c15;
	case 15390ULL: goto x86_l_3c1e;
	case 15399ULL: goto x86_l_3c27;
	case 15404ULL: goto x86_l_3c2c;
	case 15411ULL: goto x86_l_3c33;
	case 15416ULL: goto x86_l_3c38;
	case 15421ULL: goto x86_l_3c3d;
	case 15426ULL: goto x86_l_3c42;
	case 15431ULL: goto x86_l_3c47;
	case 15433ULL: goto x86_l_3c49;
	case 15438ULL: goto x86_l_3c4e;
	case 15440ULL: goto x86_l_3c50;
	case 15443ULL: goto x86_l_3c53;
	case 15449ULL: goto x86_l_3c59;
	case 15453ULL: goto x86_l_3c5d;
	case 15459ULL: goto x86_l_3c63;
	case 15463ULL: goto x86_l_3c67;
	case 15466ULL: goto x86_l_3c6a;
	case 15472ULL: goto x86_l_3c70;
	case 15476ULL: goto x86_l_3c74;
	case 15483ULL: goto x86_l_3c7b;
	case 15488ULL: goto x86_l_3c80;
	case 15493ULL: goto x86_l_3c85;
	case 15502ULL: goto x86_l_3c8e;
	case 15506ULL: goto x86_l_3c92;
	case 15513ULL: goto x86_l_3c99;
	case 15518ULL: goto x86_l_3c9e;
	case 15523ULL: goto x86_l_3ca3;
	case 15525ULL: goto x86_l_3ca5;
	case 15529ULL: goto x86_l_3ca9;
	case 15531ULL: goto x86_l_3cab;
	case 15533ULL: goto x86_l_3cad;
	case 15539ULL: goto x86_l_3cb3;
	case 15543ULL: goto x86_l_3cb7;
	case 15549ULL: goto x86_l_3cbd;
	case 15553ULL: goto x86_l_3cc1;
	case 15556ULL: goto x86_l_3cc4;
	case 15562ULL: goto x86_l_3cca;
	case 15566ULL: goto x86_l_3cce;
	case 15573ULL: goto x86_l_3cd5;
	case 15578ULL: goto x86_l_3cda;
	case 15583ULL: goto x86_l_3cdf;
	case 15588ULL: goto x86_l_3ce4;
	case 15597ULL: goto x86_l_3ced;
	case 15601ULL: goto x86_l_3cf1;
	case 15608ULL: goto x86_l_3cf8;
	case 15613ULL: goto x86_l_3cfd;
	case 15615ULL: goto x86_l_3cff;
	case 15620ULL: goto x86_l_3d04;
	case 15629ULL: goto x86_l_3d0d;
	case 15632ULL: goto x86_l_3d10;
	case 15641ULL: goto x86_l_3d19;
	case 15650ULL: goto x86_l_3d22;
	case 15655ULL: goto x86_l_3d27;
	case 15662ULL: goto x86_l_3d2e;
	case 15667ULL: goto x86_l_3d33;
	case 15672ULL: goto x86_l_3d38;
	case 15677ULL: goto x86_l_3d3d;
	case 15682ULL: goto x86_l_3d42;
	case 15684ULL: goto x86_l_3d44;
	case 15689ULL: goto x86_l_3d49;
	case 15691ULL: goto x86_l_3d4b;
	case 15694ULL: goto x86_l_3d4e;
	case 15700ULL: goto x86_l_3d54;
	case 15704ULL: goto x86_l_3d58;
	case 15710ULL: goto x86_l_3d5e;
	case 15714ULL: goto x86_l_3d62;
	case 15717ULL: goto x86_l_3d65;
	case 15723ULL: goto x86_l_3d6b;
	case 15727ULL: goto x86_l_3d6f;
	case 15734ULL: goto x86_l_3d76;
	case 15739ULL: goto x86_l_3d7b;
	case 15744ULL: goto x86_l_3d80;
	case 15753ULL: goto x86_l_3d89;
	case 15757ULL: goto x86_l_3d8d;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15776ULL: goto x86_l_3da0;
	case 15780ULL: goto x86_l_3da4;
	case 15782ULL: goto x86_l_3da6;
	case 15784ULL: goto x86_l_3da8;
	case 15790ULL: goto x86_l_3dae;
	case 15794ULL: goto x86_l_3db2;
	case 15800ULL: goto x86_l_3db8;
	case 15804ULL: goto x86_l_3dbc;
	case 15807ULL: goto x86_l_3dbf;
	case 15813ULL: goto x86_l_3dc5;
	case 15817ULL: goto x86_l_3dc9;
	case 15824ULL: goto x86_l_3dd0;
	case 15829ULL: goto x86_l_3dd5;
	case 15834ULL: goto x86_l_3dda;
	case 15839ULL: goto x86_l_3ddf;
	case 15848ULL: goto x86_l_3de8;
	case 15852ULL: goto x86_l_3dec;
	case 15859ULL: goto x86_l_3df3;
	case 15864ULL: goto x86_l_3df8;
	case 15866ULL: goto x86_l_3dfa;
	case 15871ULL: goto x86_l_3dff;
	case 15880ULL: goto x86_l_3e08;
	case 15883ULL: goto x86_l_3e0b;
	case 15892ULL: goto x86_l_3e14;
	case 15901ULL: goto x86_l_3e1d;
	case 15906ULL: goto x86_l_3e22;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15923ULL: goto x86_l_3e33;
	case 15928ULL: goto x86_l_3e38;
	case 15933ULL: goto x86_l_3e3d;
	case 15935ULL: goto x86_l_3e3f;
	case 15940ULL: goto x86_l_3e44;
	case 15942ULL: goto x86_l_3e46;
	case 15945ULL: goto x86_l_3e49;
	case 15951ULL: goto x86_l_3e4f;
	case 15955ULL: goto x86_l_3e53;
	case 15961ULL: goto x86_l_3e59;
	case 15965ULL: goto x86_l_3e5d;
	case 15968ULL: goto x86_l_3e60;
	case 15974ULL: goto x86_l_3e66;
	case 15978ULL: goto x86_l_3e6a;
	case 15985ULL: goto x86_l_3e71;
	case 15990ULL: goto x86_l_3e76;
	case 15995ULL: goto x86_l_3e7b;
	case 16004ULL: goto x86_l_3e84;
	case 16008ULL: goto x86_l_3e88;
	case 16015ULL: goto x86_l_3e8f;
	case 16020ULL: goto x86_l_3e94;
	case 16025ULL: goto x86_l_3e99;
	case 16027ULL: goto x86_l_3e9b;
	case 16031ULL: goto x86_l_3e9f;
	case 16033ULL: goto x86_l_3ea1;
	case 16035ULL: goto x86_l_3ea3;
	case 16041ULL: goto x86_l_3ea9;
	case 16045ULL: goto x86_l_3ead;
	case 16051ULL: goto x86_l_3eb3;
	case 16055ULL: goto x86_l_3eb7;
	case 16058ULL: goto x86_l_3eba;
	case 16064ULL: goto x86_l_3ec0;
	case 16068ULL: goto x86_l_3ec4;
	case 16075ULL: goto x86_l_3ecb;
	case 16080ULL: goto x86_l_3ed0;
	case 16085ULL: goto x86_l_3ed5;
	case 16090ULL: goto x86_l_3eda;
	case 16099ULL: goto x86_l_3ee3;
	case 16103ULL: goto x86_l_3ee7;
	case 16110ULL: goto x86_l_3eee;
	case 16115ULL: goto x86_l_3ef3;
	case 16117ULL: goto x86_l_3ef5;
	case 16122ULL: goto x86_l_3efa;
	case 16131ULL: goto x86_l_3f03;
	case 16134ULL: goto x86_l_3f06;
	case 16143ULL: goto x86_l_3f0f;
	case 16152ULL: goto x86_l_3f18;
	case 16157ULL: goto x86_l_3f1d;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16174ULL: goto x86_l_3f2e;
	case 16179ULL: goto x86_l_3f33;
	case 16184ULL: goto x86_l_3f38;
	case 16186ULL: goto x86_l_3f3a;
	case 16191ULL: goto x86_l_3f3f;
	case 16193ULL: goto x86_l_3f41;
	case 16196ULL: goto x86_l_3f44;
	case 16202ULL: goto x86_l_3f4a;
	case 16206ULL: goto x86_l_3f4e;
	case 16212ULL: goto x86_l_3f54;
	case 16216ULL: goto x86_l_3f58;
	case 16219ULL: goto x86_l_3f5b;
	case 16225ULL: goto x86_l_3f61;
	case 16229ULL: goto x86_l_3f65;
	case 16236ULL: goto x86_l_3f6c;
	case 16241ULL: goto x86_l_3f71;
	case 16246ULL: goto x86_l_3f76;
	case 16255ULL: goto x86_l_3f7f;
	case 16259ULL: goto x86_l_3f83;
	case 16266ULL: goto x86_l_3f8a;
	case 16271ULL: goto x86_l_3f8f;
	case 16276ULL: goto x86_l_3f94;
	case 16278ULL: goto x86_l_3f96;
	case 16282ULL: goto x86_l_3f9a;
	case 16284ULL: goto x86_l_3f9c;
	case 16286ULL: goto x86_l_3f9e;
	case 16292ULL: goto x86_l_3fa4;
	case 16296ULL: goto x86_l_3fa8;
	case 16302ULL: goto x86_l_3fae;
	case 16306ULL: goto x86_l_3fb2;
	case 16309ULL: goto x86_l_3fb5;
	case 16315ULL: goto x86_l_3fbb;
	case 16319ULL: goto x86_l_3fbf;
	case 16326ULL: goto x86_l_3fc6;
	case 16331ULL: goto x86_l_3fcb;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16350ULL: goto x86_l_3fde;
	case 16354ULL: goto x86_l_3fe2;
	case 16361ULL: goto x86_l_3fe9;
	case 16366ULL: goto x86_l_3fee;
	case 16368ULL: goto x86_l_3ff0;
	case 16373ULL: goto x86_l_3ff5;
	case 16382ULL: goto x86_l_3ffe;
	case 16385ULL: goto x86_l_4001;
	case 16394ULL: goto x86_l_400a;
	case 16403ULL: goto x86_l_4013;
	case 16408ULL: goto x86_l_4018;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16425ULL: goto x86_l_4029;
	case 16430ULL: goto x86_l_402e;
	case 16435ULL: goto x86_l_4033;
	case 16437ULL: goto x86_l_4035;
	case 16442ULL: goto x86_l_403a;
	case 16444ULL: goto x86_l_403c;
	case 16447ULL: goto x86_l_403f;
	case 16453ULL: goto x86_l_4045;
	case 16457ULL: goto x86_l_4049;
	case 16463ULL: goto x86_l_404f;
	case 16467ULL: goto x86_l_4053;
	case 16470ULL: goto x86_l_4056;
	case 16476ULL: goto x86_l_405c;
	case 16480ULL: goto x86_l_4060;
	case 16487ULL: goto x86_l_4067;
	case 16492ULL: goto x86_l_406c;
	case 16497ULL: goto x86_l_4071;
	case 16506ULL: goto x86_l_407a;
	case 16510ULL: goto x86_l_407e;
	case 16517ULL: goto x86_l_4085;
	case 16522ULL: goto x86_l_408a;
	case 16527ULL: goto x86_l_408f;
	case 16529ULL: goto x86_l_4091;
	case 16533ULL: goto x86_l_4095;
	case 16535ULL: goto x86_l_4097;
	case 16537ULL: goto x86_l_4099;
	case 16543ULL: goto x86_l_409f;
	case 16547ULL: goto x86_l_40a3;
	case 16553ULL: goto x86_l_40a9;
	case 16557ULL: goto x86_l_40ad;
	case 16560ULL: goto x86_l_40b0;
	case 16566ULL: goto x86_l_40b6;
	case 16570ULL: goto x86_l_40ba;
	case 16577ULL: goto x86_l_40c1;
	case 16582ULL: goto x86_l_40c6;
	case 16587ULL: goto x86_l_40cb;
	case 16592ULL: goto x86_l_40d0;
	case 16601ULL: goto x86_l_40d9;
	case 16605ULL: goto x86_l_40dd;
	case 16612ULL: goto x86_l_40e4;
	case 16617ULL: goto x86_l_40e9;
	case 16619ULL: goto x86_l_40eb;
	case 16624ULL: goto x86_l_40f0;
	case 16633ULL: goto x86_l_40f9;
	case 16636ULL: goto x86_l_40fc;
	case 16645ULL: goto x86_l_4105;
	case 16654ULL: goto x86_l_410e;
	case 16659ULL: goto x86_l_4113;
	case 16666ULL: goto x86_l_411a;
	case 16671ULL: goto x86_l_411f;
	case 16676ULL: goto x86_l_4124;
	case 16681ULL: goto x86_l_4129;
	case 16686ULL: goto x86_l_412e;
	case 16688ULL: goto x86_l_4130;
	case 16693ULL: goto x86_l_4135;
	case 16695ULL: goto x86_l_4137;
	case 16698ULL: goto x86_l_413a;
	case 16704ULL: goto x86_l_4140;
	case 16708ULL: goto x86_l_4144;
	case 16714ULL: goto x86_l_414a;
	case 16718ULL: goto x86_l_414e;
	case 16721ULL: goto x86_l_4151;
	default: return 0xffffffffffffffffULL;
	}
x86_l_39cc:
	/* 0x39cc: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39d0:
	/* 0x39d0: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_39d3:
	/* 0x39d3: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_39d9:
	/* 0x39d9: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_39dd:
	/* 0x39dd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39e4:
	/* 0x39e4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39e9:
	/* 0x39e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39ee:
	/* 0x39ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39f3:
	/* 0x39f3: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39fc:
	/* 0x39fc: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a00:
	/* 0x3a00: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a07:
	/* 0x3a07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a0c:
	/* 0x3a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a0e:
	/* 0x3a0e: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3a13:
	/* 0x3a13: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a1c:
	/* 0x3a1c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a1f:
	/* 0x3a1f: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a28:
	/* 0x3a28: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a31:
	/* 0x3a31: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3a36:
	/* 0x3a36: lea    rdx,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
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
	/* 0x3a58: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_3a5a:
	/* 0x3a5a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3a5d:
	/* 0x3a5d: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3a63:
	/* 0x3a63: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a67:
	/* 0x3a67: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3a6d:
	/* 0x3a6d: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a71:
	/* 0x3a71: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3a74:
	/* 0x3a74: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3a7a:
	/* 0x3a7a: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3a7e:
	/* 0x3a7e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a85:
	/* 0x3a85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a8a:
	/* 0x3a8a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a8f:
	/* 0x3a8f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a98:
	/* 0x3a98: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3a9c:
	/* 0x3a9c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aa8:
	/* 0x3aa8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3aad:
	/* 0x3aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aaf:
	/* 0x3aaf: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ab3:
	/* 0x3ab3: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_3ab5:
	/* 0x3ab5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab7:
	/* 0x3ab7: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3abd:
	/* 0x3abd: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ac1:
	/* 0x3ac1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3ac7:
	/* 0x3ac7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3acb:
	/* 0x3acb: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3ace:
	/* 0x3ace: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3ad4:
	/* 0x3ad4: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ad8:
	/* 0x3ad8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3adf:
	/* 0x3adf: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ae4:
	/* 0x3ae4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3aee:
	/* 0x3aee: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3af7:
	/* 0x3af7: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3afb:
	/* 0x3afb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b02:
	/* 0x3b02: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b07:
	/* 0x3b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b09:
	/* 0x3b09: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3b0e:
	/* 0x3b0e: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3b17:
	/* 0x3b17: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b1a:
	/* 0x3b1a: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b23:
	/* 0x3b23: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b2c:
	/* 0x3b2c: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b31:
	/* 0x3b31: lea    rdx,[rax+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3b38:
	/* 0x3b38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3d:
	/* 0x3b3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b42:
	/* 0x3b42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b47:
	/* 0x3b47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b4c:
	/* 0x3b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4e:
	/* 0x3b4e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b53:
	/* 0x3b53: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_3b55:
	/* 0x3b55: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3b58:
	/* 0x3b58: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3b5e:
	/* 0x3b5e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b62:
	/* 0x3b62: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3b68:
	/* 0x3b68: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b6c:
	/* 0x3b6c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3b6f:
	/* 0x3b6f: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3b75:
	/* 0x3b75: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3b79:
	/* 0x3b79: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b80:
	/* 0x3b80: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b85:
	/* 0x3b85: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b8a:
	/* 0x3b8a: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b93:
	/* 0x3b93: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3b97:
	/* 0x3b97: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b9e:
	/* 0x3b9e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ba3:
	/* 0x3ba3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ba8:
	/* 0x3ba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3baa:
	/* 0x3baa: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bae:
	/* 0x3bae: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_3bb0:
	/* 0x3bb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bb2:
	/* 0x3bb2: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3bb8:
	/* 0x3bb8: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bbc:
	/* 0x3bbc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bc6:
	/* 0x3bc6: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3bc9:
	/* 0x3bc9: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3bcf:
	/* 0x3bcf: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3bd3:
	/* 0x3bd3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bda:
	/* 0x3bda: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bdf:
	/* 0x3bdf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3be4:
	/* 0x3be4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3be9:
	/* 0x3be9: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bf2:
	/* 0x3bf2: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bf6:
	/* 0x3bf6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bfd:
	/* 0x3bfd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c02:
	/* 0x3c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c04:
	/* 0x3c04: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3c09:
	/* 0x3c09: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c12:
	/* 0x3c12: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c15:
	/* 0x3c15: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c1e:
	/* 0x3c1e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c27:
	/* 0x3c27: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3c2c:
	/* 0x3c2c: lea    rdx,[rax+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3c33:
	/* 0x3c33: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c38:
	/* 0x3c38: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c3d:
	/* 0x3c3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c42:
	/* 0x3c42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c47:
	/* 0x3c47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c49:
	/* 0x3c49: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c4e:
	/* 0x3c4e: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_3c50:
	/* 0x3c50: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3c53:
	/* 0x3c53: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3c59:
	/* 0x3c59: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c5d:
	/* 0x3c5d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3c63:
	/* 0x3c63: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c67:
	/* 0x3c67: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3c6a:
	/* 0x3c6a: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3c70:
	/* 0x3c70: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3c74:
	/* 0x3c74: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c7b:
	/* 0x3c7b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c80:
	/* 0x3c80: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c85:
	/* 0x3c85: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c8e:
	/* 0x3c8e: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3c92:
	/* 0x3c92: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c99:
	/* 0x3c99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c9e:
	/* 0x3c9e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ca3:
	/* 0x3ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca5:
	/* 0x3ca5: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_3cab:
	/* 0x3cab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cad:
	/* 0x3cad: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3cb3:
	/* 0x3cb3: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cb7:
	/* 0x3cb7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3cbd:
	/* 0x3cbd: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cc1:
	/* 0x3cc1: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3cc4:
	/* 0x3cc4: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3cca:
	/* 0x3cca: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3cce:
	/* 0x3cce: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3cd5:
	/* 0x3cd5: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cda:
	/* 0x3cda: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cdf:
	/* 0x3cdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ce4:
	/* 0x3ce4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ced:
	/* 0x3ced: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cf1:
	/* 0x3cf1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3cf8:
	/* 0x3cf8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cfd:
	/* 0x3cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cff:
	/* 0x3cff: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3d04:
	/* 0x3d04: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d0d:
	/* 0x3d0d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d10:
	/* 0x3d10: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d19:
	/* 0x3d19: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d22:
	/* 0x3d22: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d27:
	/* 0x3d27: lea    rdx,[rax+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3d2e:
	/* 0x3d2e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d33:
	/* 0x3d33: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d38:
	/* 0x3d38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d3d:
	/* 0x3d3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d42:
	/* 0x3d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d44:
	/* 0x3d44: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d49:
	/* 0x3d49: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_3d4b:
	/* 0x3d4b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3d4e:
	/* 0x3d4e: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3d54:
	/* 0x3d54: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d58:
	/* 0x3d58: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3d5e:
	/* 0x3d5e: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d62:
	/* 0x3d62: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3d65:
	/* 0x3d65: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3d6b:
	/* 0x3d6b: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3d6f:
	/* 0x3d6f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d76:
	/* 0x3d76: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d7b:
	/* 0x3d7b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d80:
	/* 0x3d80: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d89:
	/* 0x3d89: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3d8d:
	/* 0x3d8d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d94:
	/* 0x3d94: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d99:
	/* 0x3d99: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d9e:
	/* 0x3d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da0:
	/* 0x3da0: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3da4:
	/* 0x3da4: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_3da6:
	/* 0x3da6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3da8:
	/* 0x3da8: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3dae:
	/* 0x3dae: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3db2:
	/* 0x3db2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3db8:
	/* 0x3db8: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dbc:
	/* 0x3dbc: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3dbf:
	/* 0x3dbf: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3dc5:
	/* 0x3dc5: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3dc9:
	/* 0x3dc9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dd0:
	/* 0x3dd0: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd5:
	/* 0x3dd5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3dda:
	/* 0x3dda: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ddf:
	/* 0x3ddf: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3de8:
	/* 0x3de8: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3dec:
	/* 0x3dec: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3df3:
	/* 0x3df3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3df8:
	/* 0x3df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dfa:
	/* 0x3dfa: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3dff:
	/* 0x3dff: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e08:
	/* 0x3e08: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e0b:
	/* 0x3e0b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e14:
	/* 0x3e14: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e1d:
	/* 0x3e1d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e22:
	/* 0x3e22: lea    rdx,[rax+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_3e29:
	/* 0x3e29: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e2e:
	/* 0x3e2e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e33:
	/* 0x3e33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e38:
	/* 0x3e38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e3d:
	/* 0x3e3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3f:
	/* 0x3e3f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e44:
	/* 0x3e44: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_3e46:
	/* 0x3e46: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3e49:
	/* 0x3e49: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3e4f:
	/* 0x3e4f: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e53:
	/* 0x3e53: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3e59:
	/* 0x3e59: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e5d:
	/* 0x3e5d: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3e60:
	/* 0x3e60: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3e66:
	/* 0x3e66: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3e6a:
	/* 0x3e6a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e71:
	/* 0x3e71: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e76:
	/* 0x3e76: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e7b:
	/* 0x3e7b: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e84:
	/* 0x3e84: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3e88:
	/* 0x3e88: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e8f:
	/* 0x3e8f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e94:
	/* 0x3e94: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e99:
	/* 0x3e99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e9b:
	/* 0x3e9b: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_3ea1:
	/* 0x3ea1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ea3:
	/* 0x3ea3: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3ea9:
	/* 0x3ea9: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ead:
	/* 0x3ead: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3eb3:
	/* 0x3eb3: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eb7:
	/* 0x3eb7: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3eba:
	/* 0x3eba: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3ec0:
	/* 0x3ec0: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ec4:
	/* 0x3ec4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ecb:
	/* 0x3ecb: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed0:
	/* 0x3ed0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ed5:
	/* 0x3ed5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3eda:
	/* 0x3eda: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ee3:
	/* 0x3ee3: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ee7:
	/* 0x3ee7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3eee:
	/* 0x3eee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ef3:
	/* 0x3ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef5:
	/* 0x3ef5: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3efa:
	/* 0x3efa: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f03:
	/* 0x3f03: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f06:
	/* 0x3f06: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f0f:
	/* 0x3f0f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f18:
	/* 0x3f18: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f1d:
	/* 0x3f1d: lea    rdx,[rax+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_3f24:
	/* 0x3f24: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f29:
	/* 0x3f29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f2e:
	/* 0x3f2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f33:
	/* 0x3f33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f38:
	/* 0x3f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3a:
	/* 0x3f3a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f3f:
	/* 0x3f3f: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3f41:
	/* 0x3f41: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3f44:
	/* 0x3f44: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_3f4a:
	/* 0x3f4a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f4e:
	/* 0x3f4e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3f54:
	/* 0x3f54: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f58:
	/* 0x3f58: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3f5b:
	/* 0x3f5b: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3f61:
	/* 0x3f61: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3f65:
	/* 0x3f65: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f6c:
	/* 0x3f6c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f71:
	/* 0x3f71: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f76:
	/* 0x3f76: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f7f:
	/* 0x3f7f: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3f83:
	/* 0x3f83: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f8a:
	/* 0x3f8a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f8f:
	/* 0x3f8f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f94:
	/* 0x3f94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f96:
	/* 0x3f96: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f9a:
	/* 0x3f9a: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3f9c:
	/* 0x3f9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f9e:
	/* 0x3f9e: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_3fa4:
	/* 0x3fa4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fa8:
	/* 0x3fa8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3fae:
	/* 0x3fae: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb2:
	/* 0x3fb2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3fb5:
	/* 0x3fb5: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_3fbb:
	/* 0x3fbb: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3fbf:
	/* 0x3fbf: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3fc6:
	/* 0x3fc6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fcb:
	/* 0x3fcb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fd5:
	/* 0x3fd5: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fde:
	/* 0x3fde: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fe2:
	/* 0x3fe2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3fe9:
	/* 0x3fe9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fee:
	/* 0x3fee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff0:
	/* 0x3ff0: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_3ff5:
	/* 0x3ff5: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ffe:
	/* 0x3ffe: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4001:
	/* 0x4001: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_400a:
	/* 0x400a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4013:
	/* 0x4013: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4018:
	/* 0x4018: lea    rdx,[rax+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_401f:
	/* 0x401f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4024:
	/* 0x4024: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4029:
	/* 0x4029: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_402e:
	/* 0x402e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4033:
	/* 0x4033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4035:
	/* 0x4035: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_403a:
	/* 0x403a: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_403c:
	/* 0x403c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_403f:
	/* 0x403f: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_4045:
	/* 0x4045: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4049:
	/* 0x4049: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_404f:
	/* 0x404f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4053:
	/* 0x4053: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_4056:
	/* 0x4056: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_405c:
	/* 0x405c: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4060:
	/* 0x4060: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4067:
	/* 0x4067: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_406c:
	/* 0x406c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4071:
	/* 0x4071: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_407a:
	/* 0x407a: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_407e:
	/* 0x407e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4085:
	/* 0x4085: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_408a:
	/* 0x408a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_408f:
	/* 0x408f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4091:
	/* 0x4091: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4095:
	/* 0x4095: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_4097:
	/* 0x4097: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4099:
	/* 0x4099: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_409f:
	/* 0x409f: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40a3:
	/* 0x40a3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_40a9:
	/* 0x40a9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ad:
	/* 0x40ad: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_40b0:
	/* 0x40b0: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_40b6:
	/* 0x40b6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_40ba:
	/* 0x40ba: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40c1:
	/* 0x40c1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40c6:
	/* 0x40c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40cb:
	/* 0x40cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40d0:
	/* 0x40d0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40d9:
	/* 0x40d9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40dd:
	/* 0x40dd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40e4:
	/* 0x40e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40e9:
	/* 0x40e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40eb:
	/* 0x40eb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_40f0:
	/* 0x40f0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_40f9:
	/* 0x40f9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_40fc:
	/* 0x40fc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4105:
	/* 0x4105: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_410e:
	/* 0x410e: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4113:
	/* 0x4113: lea    rdx,[rax+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_411a:
	/* 0x411a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_411f:
	/* 0x411f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4124:
	/* 0x4124: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4129:
	/* 0x4129: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_412e:
	/* 0x412e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4130:
	/* 0x4130: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4135:
	/* 0x4135: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4137:
	/* 0x4137: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_413a:
	/* 0x413a: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_4140:
	/* 0x4140: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4144:
	/* 0x4144: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_414a:
	/* 0x414a: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414e:
	/* 0x414e: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_4151:
	/* 0x4151: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
	return 16727ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16727ULL: goto x86_l_4157;
	case 16731ULL: goto x86_l_415b;
	case 16738ULL: goto x86_l_4162;
	case 16743ULL: goto x86_l_4167;
	case 16748ULL: goto x86_l_416c;
	case 16757ULL: goto x86_l_4175;
	case 16761ULL: goto x86_l_4179;
	case 16768ULL: goto x86_l_4180;
	case 16773ULL: goto x86_l_4185;
	case 16778ULL: goto x86_l_418a;
	case 16780ULL: goto x86_l_418c;
	case 16784ULL: goto x86_l_4190;
	case 16786ULL: goto x86_l_4192;
	case 16788ULL: goto x86_l_4194;
	case 16794ULL: goto x86_l_419a;
	case 16798ULL: goto x86_l_419e;
	case 16804ULL: goto x86_l_41a4;
	case 16808ULL: goto x86_l_41a8;
	case 16811ULL: goto x86_l_41ab;
	case 16817ULL: goto x86_l_41b1;
	case 16821ULL: goto x86_l_41b5;
	case 16828ULL: goto x86_l_41bc;
	case 16833ULL: goto x86_l_41c1;
	case 16838ULL: goto x86_l_41c6;
	case 16843ULL: goto x86_l_41cb;
	case 16852ULL: goto x86_l_41d4;
	case 16856ULL: goto x86_l_41d8;
	case 16863ULL: goto x86_l_41df;
	case 16868ULL: goto x86_l_41e4;
	case 16870ULL: goto x86_l_41e6;
	case 16875ULL: goto x86_l_41eb;
	case 16884ULL: goto x86_l_41f4;
	case 16887ULL: goto x86_l_41f7;
	case 16896ULL: goto x86_l_4200;
	case 16905ULL: goto x86_l_4209;
	case 16910ULL: goto x86_l_420e;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16927ULL: goto x86_l_421f;
	case 16932ULL: goto x86_l_4224;
	case 16937ULL: goto x86_l_4229;
	case 16939ULL: goto x86_l_422b;
	case 16944ULL: goto x86_l_4230;
	case 16946ULL: goto x86_l_4232;
	case 16949ULL: goto x86_l_4235;
	case 16955ULL: goto x86_l_423b;
	case 16959ULL: goto x86_l_423f;
	case 16965ULL: goto x86_l_4245;
	case 16969ULL: goto x86_l_4249;
	case 16972ULL: goto x86_l_424c;
	case 16978ULL: goto x86_l_4252;
	case 16982ULL: goto x86_l_4256;
	case 16989ULL: goto x86_l_425d;
	case 16994ULL: goto x86_l_4262;
	case 16999ULL: goto x86_l_4267;
	case 17008ULL: goto x86_l_4270;
	case 17012ULL: goto x86_l_4274;
	case 17019ULL: goto x86_l_427b;
	case 17024ULL: goto x86_l_4280;
	case 17029ULL: goto x86_l_4285;
	case 17031ULL: goto x86_l_4287;
	case 17035ULL: goto x86_l_428b;
	case 17037ULL: goto x86_l_428d;
	case 17039ULL: goto x86_l_428f;
	case 17045ULL: goto x86_l_4295;
	case 17049ULL: goto x86_l_4299;
	case 17055ULL: goto x86_l_429f;
	case 17059ULL: goto x86_l_42a3;
	case 17062ULL: goto x86_l_42a6;
	case 17068ULL: goto x86_l_42ac;
	case 17072ULL: goto x86_l_42b0;
	case 17079ULL: goto x86_l_42b7;
	case 17084ULL: goto x86_l_42bc;
	case 17089ULL: goto x86_l_42c1;
	case 17094ULL: goto x86_l_42c6;
	case 17103ULL: goto x86_l_42cf;
	case 17107ULL: goto x86_l_42d3;
	case 17114ULL: goto x86_l_42da;
	case 17119ULL: goto x86_l_42df;
	case 17121ULL: goto x86_l_42e1;
	case 17126ULL: goto x86_l_42e6;
	case 17135ULL: goto x86_l_42ef;
	case 17138ULL: goto x86_l_42f2;
	case 17147ULL: goto x86_l_42fb;
	case 17156ULL: goto x86_l_4304;
	case 17161ULL: goto x86_l_4309;
	case 17168ULL: goto x86_l_4310;
	case 17173ULL: goto x86_l_4315;
	case 17178ULL: goto x86_l_431a;
	case 17183ULL: goto x86_l_431f;
	case 17188ULL: goto x86_l_4324;
	case 17190ULL: goto x86_l_4326;
	case 17195ULL: goto x86_l_432b;
	case 17197ULL: goto x86_l_432d;
	case 17200ULL: goto x86_l_4330;
	case 17206ULL: goto x86_l_4336;
	case 17210ULL: goto x86_l_433a;
	case 17216ULL: goto x86_l_4340;
	case 17220ULL: goto x86_l_4344;
	case 17223ULL: goto x86_l_4347;
	case 17229ULL: goto x86_l_434d;
	case 17233ULL: goto x86_l_4351;
	case 17240ULL: goto x86_l_4358;
	case 17245ULL: goto x86_l_435d;
	case 17250ULL: goto x86_l_4362;
	case 17259ULL: goto x86_l_436b;
	case 17263ULL: goto x86_l_436f;
	case 17270ULL: goto x86_l_4376;
	case 17275ULL: goto x86_l_437b;
	case 17280ULL: goto x86_l_4380;
	case 17282ULL: goto x86_l_4382;
	case 17286ULL: goto x86_l_4386;
	case 17288ULL: goto x86_l_4388;
	case 17290ULL: goto x86_l_438a;
	case 17296ULL: goto x86_l_4390;
	case 17300ULL: goto x86_l_4394;
	case 17306ULL: goto x86_l_439a;
	case 17310ULL: goto x86_l_439e;
	case 17313ULL: goto x86_l_43a1;
	case 17319ULL: goto x86_l_43a7;
	case 17323ULL: goto x86_l_43ab;
	case 17330ULL: goto x86_l_43b2;
	case 17335ULL: goto x86_l_43b7;
	case 17340ULL: goto x86_l_43bc;
	case 17345ULL: goto x86_l_43c1;
	case 17354ULL: goto x86_l_43ca;
	case 17358ULL: goto x86_l_43ce;
	case 17365ULL: goto x86_l_43d5;
	case 17370ULL: goto x86_l_43da;
	case 17372ULL: goto x86_l_43dc;
	case 17377ULL: goto x86_l_43e1;
	case 17386ULL: goto x86_l_43ea;
	case 17389ULL: goto x86_l_43ed;
	case 17398ULL: goto x86_l_43f6;
	case 17406ULL: goto x86_l_43fe;
	case 17409ULL: goto x86_l_4401;
	case 17415ULL: goto x86_l_4407;
	case 17417ULL: goto x86_l_4409;
	case 17423ULL: goto x86_l_440f;
	case 17427ULL: goto x86_l_4413;
	case 17430ULL: goto x86_l_4416;
	case 17434ULL: goto x86_l_441a;
	case 17438ULL: goto x86_l_441e;
	case 17445ULL: goto x86_l_4425;
	case 17450ULL: goto x86_l_442a;
	case 17455ULL: goto x86_l_442f;
	case 17460ULL: goto x86_l_4434;
	case 17467ULL: goto x86_l_443b;
	case 17470ULL: goto x86_l_443e;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17484ULL: goto x86_l_444c;
	case 17488ULL: goto x86_l_4450;
	case 17490ULL: goto x86_l_4452;
	case 17492ULL: goto x86_l_4454;
	case 17498ULL: goto x86_l_445a;
	case 17502ULL: goto x86_l_445e;
	case 17508ULL: goto x86_l_4464;
	case 17512ULL: goto x86_l_4468;
	case 17515ULL: goto x86_l_446b;
	case 17521ULL: goto x86_l_4471;
	case 17525ULL: goto x86_l_4475;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17542ULL: goto x86_l_4486;
	case 17547ULL: goto x86_l_448b;
	case 17556ULL: goto x86_l_4494;
	case 17560ULL: goto x86_l_4498;
	case 17567ULL: goto x86_l_449f;
	case 17572ULL: goto x86_l_44a4;
	case 17574ULL: goto x86_l_44a6;
	case 17579ULL: goto x86_l_44ab;
	case 17588ULL: goto x86_l_44b4;
	case 17591ULL: goto x86_l_44b7;
	case 17600ULL: goto x86_l_44c0;
	case 17602ULL: goto x86_l_44c2;
	case 17607ULL: goto x86_l_44c7;
	case 17611ULL: goto x86_l_44cb;
	case 17618ULL: goto x86_l_44d2;
	case 17623ULL: goto x86_l_44d7;
	case 17628ULL: goto x86_l_44dc;
	case 17633ULL: goto x86_l_44e1;
	case 17642ULL: goto x86_l_44ea;
	case 17646ULL: goto x86_l_44ee;
	case 17653ULL: goto x86_l_44f5;
	case 17658ULL: goto x86_l_44fa;
	case 17660ULL: goto x86_l_44fc;
	case 17665ULL: goto x86_l_4501;
	case 17674ULL: goto x86_l_450a;
	case 17677ULL: goto x86_l_450d;
	case 17686ULL: goto x86_l_4516;
	case 17695ULL: goto x86_l_451f;
	case 17699ULL: goto x86_l_4523;
	case 17704ULL: goto x86_l_4528;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17719ULL: goto x86_l_4537;
	case 17721ULL: goto x86_l_4539;
	case 17726ULL: goto x86_l_453e;
	case 17728ULL: goto x86_l_4540;
	case 17731ULL: goto x86_l_4543;
	case 17737ULL: goto x86_l_4549;
	case 17741ULL: goto x86_l_454d;
	case 17747ULL: goto x86_l_4553;
	case 17753ULL: goto x86_l_4559;
	case 17757ULL: goto x86_l_455d;
	case 17764ULL: goto x86_l_4564;
	case 17769ULL: goto x86_l_4569;
	case 17774ULL: goto x86_l_456e;
	case 17783ULL: goto x86_l_4577;
	case 17787ULL: goto x86_l_457b;
	case 17794ULL: goto x86_l_4582;
	case 17799ULL: goto x86_l_4587;
	case 17804ULL: goto x86_l_458c;
	case 17806ULL: goto x86_l_458e;
	case 17810ULL: goto x86_l_4592;
	case 17812ULL: goto x86_l_4594;
	case 17814ULL: goto x86_l_4596;
	case 17820ULL: goto x86_l_459c;
	case 17824ULL: goto x86_l_45a0;
	case 17830ULL: goto x86_l_45a6;
	case 17836ULL: goto x86_l_45ac;
	case 17840ULL: goto x86_l_45b0;
	case 17847ULL: goto x86_l_45b7;
	case 17852ULL: goto x86_l_45bc;
	case 17857ULL: goto x86_l_45c1;
	case 17862ULL: goto x86_l_45c6;
	case 17871ULL: goto x86_l_45cf;
	case 17875ULL: goto x86_l_45d3;
	case 17882ULL: goto x86_l_45da;
	case 17887ULL: goto x86_l_45df;
	case 17889ULL: goto x86_l_45e1;
	case 17894ULL: goto x86_l_45e6;
	case 17903ULL: goto x86_l_45ef;
	case 17906ULL: goto x86_l_45f2;
	case 17915ULL: goto x86_l_45fb;
	case 17924ULL: goto x86_l_4604;
	case 17928ULL: goto x86_l_4608;
	case 17933ULL: goto x86_l_460d;
	case 17938ULL: goto x86_l_4612;
	case 17943ULL: goto x86_l_4617;
	case 17948ULL: goto x86_l_461c;
	case 17950ULL: goto x86_l_461e;
	case 17955ULL: goto x86_l_4623;
	case 17957ULL: goto x86_l_4625;
	case 17960ULL: goto x86_l_4628;
	case 17966ULL: goto x86_l_462e;
	case 17970ULL: goto x86_l_4632;
	case 17976ULL: goto x86_l_4638;
	case 17982ULL: goto x86_l_463e;
	case 17986ULL: goto x86_l_4642;
	case 17993ULL: goto x86_l_4649;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18012ULL: goto x86_l_465c;
	case 18016ULL: goto x86_l_4660;
	case 18023ULL: goto x86_l_4667;
	case 18028ULL: goto x86_l_466c;
	case 18033ULL: goto x86_l_4671;
	case 18035ULL: goto x86_l_4673;
	case 18039ULL: goto x86_l_4677;
	case 18041ULL: goto x86_l_4679;
	case 18043ULL: goto x86_l_467b;
	case 18049ULL: goto x86_l_4681;
	case 18053ULL: goto x86_l_4685;
	case 18059ULL: goto x86_l_468b;
	case 18065ULL: goto x86_l_4691;
	case 18069ULL: goto x86_l_4695;
	case 18076ULL: goto x86_l_469c;
	case 18081ULL: goto x86_l_46a1;
	case 18086ULL: goto x86_l_46a6;
	case 18091ULL: goto x86_l_46ab;
	case 18100ULL: goto x86_l_46b4;
	case 18104ULL: goto x86_l_46b8;
	case 18111ULL: goto x86_l_46bf;
	case 18116ULL: goto x86_l_46c4;
	case 18118ULL: goto x86_l_46c6;
	case 18123ULL: goto x86_l_46cb;
	case 18132ULL: goto x86_l_46d4;
	case 18135ULL: goto x86_l_46d7;
	case 18144ULL: goto x86_l_46e0;
	case 18153ULL: goto x86_l_46e9;
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18167ULL: goto x86_l_46f7;
	case 18172ULL: goto x86_l_46fc;
	case 18177ULL: goto x86_l_4701;
	case 18179ULL: goto x86_l_4703;
	case 18184ULL: goto x86_l_4708;
	case 18186ULL: goto x86_l_470a;
	case 18189ULL: goto x86_l_470d;
	case 18195ULL: goto x86_l_4713;
	case 18199ULL: goto x86_l_4717;
	case 18205ULL: goto x86_l_471d;
	case 18211ULL: goto x86_l_4723;
	case 18215ULL: goto x86_l_4727;
	case 18222ULL: goto x86_l_472e;
	case 18227ULL: goto x86_l_4733;
	case 18232ULL: goto x86_l_4738;
	case 18241ULL: goto x86_l_4741;
	case 18245ULL: goto x86_l_4745;
	case 18252ULL: goto x86_l_474c;
	case 18257ULL: goto x86_l_4751;
	case 18262ULL: goto x86_l_4756;
	case 18264ULL: goto x86_l_4758;
	case 18268ULL: goto x86_l_475c;
	case 18270ULL: goto x86_l_475e;
	case 18272ULL: goto x86_l_4760;
	case 18278ULL: goto x86_l_4766;
	case 18282ULL: goto x86_l_476a;
	case 18288ULL: goto x86_l_4770;
	case 18292ULL: goto x86_l_4774;
	case 18298ULL: goto x86_l_477a;
	case 18302ULL: goto x86_l_477e;
	case 18309ULL: goto x86_l_4785;
	case 18314ULL: goto x86_l_478a;
	case 18319ULL: goto x86_l_478f;
	case 18324ULL: goto x86_l_4794;
	case 18333ULL: goto x86_l_479d;
	case 18337ULL: goto x86_l_47a1;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18351ULL: goto x86_l_47af;
	case 18356ULL: goto x86_l_47b4;
	case 18365ULL: goto x86_l_47bd;
	case 18368ULL: goto x86_l_47c0;
	case 18377ULL: goto x86_l_47c9;
	case 18386ULL: goto x86_l_47d2;
	case 18390ULL: goto x86_l_47d6;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18405ULL: goto x86_l_47e5;
	case 18410ULL: goto x86_l_47ea;
	case 18412ULL: goto x86_l_47ec;
	case 18417ULL: goto x86_l_47f1;
	case 18419ULL: goto x86_l_47f3;
	case 18422ULL: goto x86_l_47f6;
	case 18428ULL: goto x86_l_47fc;
	case 18432ULL: goto x86_l_4800;
	case 18438ULL: goto x86_l_4806;
	case 18442ULL: goto x86_l_480a;
	case 18448ULL: goto x86_l_4810;
	case 18452ULL: goto x86_l_4814;
	case 18459ULL: goto x86_l_481b;
	case 18464ULL: goto x86_l_4820;
	case 18469ULL: goto x86_l_4825;
	case 18478ULL: goto x86_l_482e;
	case 18482ULL: goto x86_l_4832;
	case 18489ULL: goto x86_l_4839;
	case 18494ULL: goto x86_l_483e;
	case 18499ULL: goto x86_l_4843;
	case 18501ULL: goto x86_l_4845;
	case 18505ULL: goto x86_l_4849;
	case 18507ULL: goto x86_l_484b;
	case 18509ULL: goto x86_l_484d;
	case 18515ULL: goto x86_l_4853;
	case 18519ULL: goto x86_l_4857;
	case 18525ULL: goto x86_l_485d;
	case 18529ULL: goto x86_l_4861;
	case 18535ULL: goto x86_l_4867;
	case 18539ULL: goto x86_l_486b;
	case 18546ULL: goto x86_l_4872;
	case 18551ULL: goto x86_l_4877;
	case 18556ULL: goto x86_l_487c;
	case 18561ULL: goto x86_l_4881;
	case 18570ULL: goto x86_l_488a;
	case 18574ULL: goto x86_l_488e;
	case 18581ULL: goto x86_l_4895;
	case 18586ULL: goto x86_l_489a;
	case 18588ULL: goto x86_l_489c;
	case 18593ULL: goto x86_l_48a1;
	case 18602ULL: goto x86_l_48aa;
	case 18605ULL: goto x86_l_48ad;
	case 18614ULL: goto x86_l_48b6;
	case 18623ULL: goto x86_l_48bf;
	case 18627ULL: goto x86_l_48c3;
	case 18632ULL: goto x86_l_48c8;
	case 18637ULL: goto x86_l_48cd;
	case 18642ULL: goto x86_l_48d2;
	case 18647ULL: goto x86_l_48d7;
	case 18649ULL: goto x86_l_48d9;
	case 18654ULL: goto x86_l_48de;
	case 18656ULL: goto x86_l_48e0;
	case 18659ULL: goto x86_l_48e3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4157:
	/* 0x4157: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_415b:
	/* 0x415b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4162:
	/* 0x4162: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4167:
	/* 0x4167: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_416c:
	/* 0x416c: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4175:
	/* 0x4175: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4179:
	/* 0x4179: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4180:
	/* 0x4180: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4185:
	/* 0x4185: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_418a:
	/* 0x418a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418c:
	/* 0x418c: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4190:
	/* 0x4190: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4192:
	/* 0x4192: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4194:
	/* 0x4194: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_419a:
	/* 0x419a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_419e:
	/* 0x419e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_41a4:
	/* 0x41a4: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a8:
	/* 0x41a8: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_41ab:
	/* 0x41ab: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_41b1:
	/* 0x41b1: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_41b5:
	/* 0x41b5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41bc:
	/* 0x41bc: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41c1:
	/* 0x41c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41c6:
	/* 0x41c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41cb:
	/* 0x41cb: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41d4:
	/* 0x41d4: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41d8:
	/* 0x41d8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41df:
	/* 0x41df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41e4:
	/* 0x41e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e6:
	/* 0x41e6: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_41eb:
	/* 0x41eb: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41f4:
	/* 0x41f4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41f7:
	/* 0x41f7: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4200:
	/* 0x4200: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4209:
	/* 0x4209: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_420e:
	/* 0x420e: lea    rdx,[rax+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4215:
	/* 0x4215: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_421a:
	/* 0x421a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_421f:
	/* 0x421f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4224:
	/* 0x4224: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4229:
	/* 0x4229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_422b:
	/* 0x422b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4230:
	/* 0x4230: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_4232:
	/* 0x4232: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4235:
	/* 0x4235: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_423b:
	/* 0x423b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_423f:
	/* 0x423f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4245:
	/* 0x4245: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4249:
	/* 0x4249: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_424c:
	/* 0x424c: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_4252:
	/* 0x4252: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4256:
	/* 0x4256: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_425d:
	/* 0x425d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4262:
	/* 0x4262: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4267:
	/* 0x4267: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4270:
	/* 0x4270: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4274:
	/* 0x4274: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_427b:
	/* 0x427b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4280:
	/* 0x4280: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4285:
	/* 0x4285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4287:
	/* 0x4287: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_428b:
	/* 0x428b: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_428d:
	/* 0x428d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_428f:
	/* 0x428f: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_4295:
	/* 0x4295: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4299:
	/* 0x4299: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_429f:
	/* 0x429f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42a3:
	/* 0x42a3: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_42a6:
	/* 0x42a6: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_42ac:
	/* 0x42ac: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_42b0:
	/* 0x42b0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42b7:
	/* 0x42b7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42bc:
	/* 0x42bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42c1:
	/* 0x42c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42c6:
	/* 0x42c6: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42cf:
	/* 0x42cf: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_42d3:
	/* 0x42d3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42da:
	/* 0x42da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42df:
	/* 0x42df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e1:
	/* 0x42e1: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_42e6:
	/* 0x42e6: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42ef:
	/* 0x42ef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42f2:
	/* 0x42f2: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42fb:
	/* 0x42fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4304:
	/* 0x4304: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4309:
	/* 0x4309: add    rdx,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_4310:
	/* 0x4310: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4315:
	/* 0x4315: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_431a:
	/* 0x431a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_431f:
	/* 0x431f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4324:
	/* 0x4324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4326:
	/* 0x4326: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_432b:
	/* 0x432b: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_432d:
	/* 0x432d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4330:
	/* 0x4330: je     689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26782ULL;
	}
x86_l_4336:
	/* 0x4336: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_433a:
	/* 0x433a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4340:
	/* 0x4340: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4344:
	/* 0x4344: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_4347:
	/* 0x4347: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_434d:
	/* 0x434d: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4351:
	/* 0x4351: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4358:
	/* 0x4358: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_435d:
	/* 0x435d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4362:
	/* 0x4362: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_436b:
	/* 0x436b: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_436f:
	/* 0x436f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4376:
	/* 0x4376: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_437b:
	/* 0x437b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4380:
	/* 0x4380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4382:
	/* 0x4382: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4386:
	/* 0x4386: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_4388:
	/* 0x4388: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_438a:
	/* 0x438a: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_4390:
	/* 0x4390: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4394:
	/* 0x4394: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_439a:
	/* 0x439a: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_439e:
	/* 0x439e: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_43a1:
	/* 0x43a1: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_43a7:
	/* 0x43a7: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_43ab:
	/* 0x43ab: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43b2:
	/* 0x43b2: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43b7:
	/* 0x43b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43bc:
	/* 0x43bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43c1:
	/* 0x43c1: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43ca:
	/* 0x43ca: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43ce:
	/* 0x43ce: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43d5:
	/* 0x43d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43da:
	/* 0x43da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43dc:
	/* 0x43dc: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_43e1:
	/* 0x43e1: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43ea:
	/* 0x43ea: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43ed:
	/* 0x43ed: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43f6:
	/* 0x43f6: mov    DWORD PTR [rsp+0x60],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412319886894ULL);
x86_l_43fe:
	/* 0x43fe: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4401:
	/* 0x4401: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_4407:
	/* 0x4407: jb     4413 <trace_execute_finished+0x4413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4413;
	}
x86_l_4409:
	/* 0x4409: mov    WORD PTR [r14],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_440f:
	/* 0x440f: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_4413:
	/* 0x4413: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4416:
	/* 0x4416: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_441a:
	/* 0x441a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_441e:
	/* 0x441e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4425:
	/* 0x4425: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_442a:
	/* 0x442a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_442f:
	/* 0x442f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4434:
	/* 0x4434: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_443b:
	/* 0x443b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_443e:
	/* 0x443e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4445:
	/* 0x4445: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_444a:
	/* 0x444a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444c:
	/* 0x444c: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_4450:
	/* 0x4450: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_4452:
	/* 0x4452: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4454:
	/* 0x4454: jle    689e <trace_execute_finished+0x689e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26782ULL;
	}
x86_l_445a:
	/* 0x445a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_445e:
	/* 0x445e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4464:
	/* 0x4464: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4468:
	/* 0x4468: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_446b:
	/* 0x446b: ja     1925 <trace_execute_finished+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6437ULL;
	}
x86_l_4471:
	/* 0x4471: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4475:
	/* 0x4475: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_447c:
	/* 0x447c: lea    rdx,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_4481:
	/* 0x4481: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4486:
	/* 0x4486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_448b:
	/* 0x448b: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4494:
	/* 0x4494: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4498:
	/* 0x4498: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_449f:
	/* 0x449f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44a4:
	/* 0x44a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a6:
	/* 0x44a6: movzx  eax,WORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 108ULL);
x86_l_44ab:
	/* 0x44ab: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_44b4:
	/* 0x44b4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44b7:
	/* 0x44b7: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44c0:
	/* 0x44c0: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_44c2:
	/* 0x44c2: jmp    1925 <trace_execute_finished+0x1925> */
	return 6437ULL;
x86_l_44c7:
	/* 0x44c7: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_44cb:
	/* 0x44cb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44d2:
	/* 0x44d2: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d7:
	/* 0x44d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44dc:
	/* 0x44dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44e1:
	/* 0x44e1: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44ea:
	/* 0x44ea: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44ee:
	/* 0x44ee: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44f5:
	/* 0x44f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44fa:
	/* 0x44fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44fc:
	/* 0x44fc: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4501:
	/* 0x4501: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_450a:
	/* 0x450a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_450d:
	/* 0x450d: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4516:
	/* 0x4516: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_451f:
	/* 0x451f: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4523:
	/* 0x4523: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4528:
	/* 0x4528: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_452d:
	/* 0x452d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4532:
	/* 0x4532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4537:
	/* 0x4537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4539:
	/* 0x4539: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_453e:
	/* 0x453e: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_4540:
	/* 0x4540: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4543:
	/* 0x4543: je     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6660ULL;
	}
x86_l_4549:
	/* 0x4549: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_454d:
	/* 0x454d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4553:
	/* 0x4553: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4559:
	/* 0x4559: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_455d:
	/* 0x455d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4564:
	/* 0x4564: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4569:
	/* 0x4569: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_456e:
	/* 0x456e: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4577:
	/* 0x4577: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_457b:
	/* 0x457b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4582:
	/* 0x4582: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4587:
	/* 0x4587: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_458c:
	/* 0x458c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_458e:
	/* 0x458e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4592:
	/* 0x4592: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_4594:
	/* 0x4594: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4596:
	/* 0x4596: jle    1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6660ULL;
	}
x86_l_459c:
	/* 0x459c: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45a0:
	/* 0x45a0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_45a6:
	/* 0x45a6: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_45ac:
	/* 0x45ac: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45b0:
	/* 0x45b0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45b7:
	/* 0x45b7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45bc:
	/* 0x45bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45c1:
	/* 0x45c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45c6:
	/* 0x45c6: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45cf:
	/* 0x45cf: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45d3:
	/* 0x45d3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45da:
	/* 0x45da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45df:
	/* 0x45df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45e1:
	/* 0x45e1: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_45e6:
	/* 0x45e6: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_45ef:
	/* 0x45ef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45f2:
	/* 0x45f2: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45fb:
	/* 0x45fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4604:
	/* 0x4604: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4608:
	/* 0x4608: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_460d:
	/* 0x460d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4612:
	/* 0x4612: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4617:
	/* 0x4617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_461c:
	/* 0x461c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461e:
	/* 0x461e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4623:
	/* 0x4623: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_4625:
	/* 0x4625: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4628:
	/* 0x4628: je     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6660ULL;
	}
x86_l_462e:
	/* 0x462e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4632:
	/* 0x4632: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4638:
	/* 0x4638: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_463e:
	/* 0x463e: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4642:
	/* 0x4642: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4649:
	/* 0x4649: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_464e:
	/* 0x464e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4653:
	/* 0x4653: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_465c:
	/* 0x465c: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
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
	/* 0x4673: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4677:
	/* 0x4677: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_4679:
	/* 0x4679: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_467b:
	/* 0x467b: jle    1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6660ULL;
	}
x86_l_4681:
	/* 0x4681: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4685:
	/* 0x4685: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_468b:
	/* 0x468b: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4691:
	/* 0x4691: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4695:
	/* 0x4695: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_469c:
	/* 0x469c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a1:
	/* 0x46a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46a6:
	/* 0x46a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46ab:
	/* 0x46ab: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46b4:
	/* 0x46b4: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_46b8:
	/* 0x46b8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_46bf:
	/* 0x46bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46c4:
	/* 0x46c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c6:
	/* 0x46c6: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_46cb:
	/* 0x46cb: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_46d4:
	/* 0x46d4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_46d7:
	/* 0x46d7: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_46e0:
	/* 0x46e0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46e9:
	/* 0x46e9: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46ed:
	/* 0x46ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46f2:
	/* 0x46f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_46f7:
	/* 0x46f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46fc:
	/* 0x46fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4701:
	/* 0x4701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4703:
	/* 0x4703: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4708:
	/* 0x4708: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_470a:
	/* 0x470a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_470d:
	/* 0x470d: je     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6660ULL;
	}
x86_l_4713:
	/* 0x4713: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4717:
	/* 0x4717: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_471d:
	/* 0x471d: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4723:
	/* 0x4723: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4727:
	/* 0x4727: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_472e:
	/* 0x472e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4733:
	/* 0x4733: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4738:
	/* 0x4738: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4741:
	/* 0x4741: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4745:
	/* 0x4745: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_474c:
	/* 0x474c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4751:
	/* 0x4751: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4756:
	/* 0x4756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4758:
	/* 0x4758: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_475c:
	/* 0x475c: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_475e:
	/* 0x475e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4760:
	/* 0x4760: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4766:
	/* 0x4766: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_476a:
	/* 0x476a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4770:
	/* 0x4770: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4774:
	/* 0x4774: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_477a:
	/* 0x477a: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_477e:
	/* 0x477e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4785:
	/* 0x4785: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_478a:
	/* 0x478a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_478f:
	/* 0x478f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4794:
	/* 0x4794: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_479d:
	/* 0x479d: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47a1:
	/* 0x47a1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47a8:
	/* 0x47a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47ad:
	/* 0x47ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47af:
	/* 0x47af: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_47b4:
	/* 0x47b4: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_47bd:
	/* 0x47bd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_47c0:
	/* 0x47c0: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_47c9:
	/* 0x47c9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47d2:
	/* 0x47d2: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47d6:
	/* 0x47d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47db:
	/* 0x47db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47e0:
	/* 0x47e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47e5:
	/* 0x47e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ea:
	/* 0x47ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ec:
	/* 0x47ec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47f1:
	/* 0x47f1: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_47f3:
	/* 0x47f3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_47f6:
	/* 0x47f6: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_47fc:
	/* 0x47fc: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4800:
	/* 0x4800: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4806:
	/* 0x4806: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_480a:
	/* 0x480a: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4810:
	/* 0x4810: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4814:
	/* 0x4814: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_481b:
	/* 0x481b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4820:
	/* 0x4820: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4825:
	/* 0x4825: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_482e:
	/* 0x482e: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4832:
	/* 0x4832: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4839:
	/* 0x4839: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_483e:
	/* 0x483e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4843:
	/* 0x4843: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4845:
	/* 0x4845: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4849:
	/* 0x4849: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_484b:
	/* 0x484b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_484d:
	/* 0x484d: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4853:
	/* 0x4853: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4857:
	/* 0x4857: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_485d:
	/* 0x485d: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4861:
	/* 0x4861: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4867:
	/* 0x4867: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_486b:
	/* 0x486b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4872:
	/* 0x4872: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4877:
	/* 0x4877: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_487c:
	/* 0x487c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4881:
	/* 0x4881: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_488a:
	/* 0x488a: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_488e:
	/* 0x488e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4895:
	/* 0x4895: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_489a:
	/* 0x489a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489c:
	/* 0x489c: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_48a1:
	/* 0x48a1: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_48aa:
	/* 0x48aa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_48ad:
	/* 0x48ad: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_48b6:
	/* 0x48b6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_48bf:
	/* 0x48bf: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_48c3:
	/* 0x48c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48c8:
	/* 0x48c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48cd:
	/* 0x48cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48d2:
	/* 0x48d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d7:
	/* 0x48d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d9:
	/* 0x48d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48de:
	/* 0x48de: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_48e0:
	/* 0x48e0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_48e3:
	/* 0x48e3: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
	return 18665ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18665ULL: goto x86_l_48e9;
	case 18669ULL: goto x86_l_48ed;
	case 18675ULL: goto x86_l_48f3;
	case 18679ULL: goto x86_l_48f7;
	case 18685ULL: goto x86_l_48fd;
	case 18689ULL: goto x86_l_4901;
	case 18696ULL: goto x86_l_4908;
	case 18701ULL: goto x86_l_490d;
	case 18706ULL: goto x86_l_4912;
	case 18715ULL: goto x86_l_491b;
	case 18719ULL: goto x86_l_491f;
	case 18726ULL: goto x86_l_4926;
	case 18731ULL: goto x86_l_492b;
	case 18736ULL: goto x86_l_4930;
	case 18738ULL: goto x86_l_4932;
	case 18742ULL: goto x86_l_4936;
	case 18744ULL: goto x86_l_4938;
	case 18746ULL: goto x86_l_493a;
	case 18752ULL: goto x86_l_4940;
	case 18756ULL: goto x86_l_4944;
	case 18762ULL: goto x86_l_494a;
	case 18766ULL: goto x86_l_494e;
	case 18772ULL: goto x86_l_4954;
	case 18776ULL: goto x86_l_4958;
	case 18783ULL: goto x86_l_495f;
	case 18788ULL: goto x86_l_4964;
	case 18793ULL: goto x86_l_4969;
	case 18798ULL: goto x86_l_496e;
	case 18807ULL: goto x86_l_4977;
	case 18811ULL: goto x86_l_497b;
	case 18818ULL: goto x86_l_4982;
	case 18823ULL: goto x86_l_4987;
	case 18825ULL: goto x86_l_4989;
	case 18830ULL: goto x86_l_498e;
	case 18839ULL: goto x86_l_4997;
	case 18842ULL: goto x86_l_499a;
	case 18851ULL: goto x86_l_49a3;
	case 18860ULL: goto x86_l_49ac;
	case 18864ULL: goto x86_l_49b0;
	case 18869ULL: goto x86_l_49b5;
	case 18874ULL: goto x86_l_49ba;
	case 18879ULL: goto x86_l_49bf;
	case 18884ULL: goto x86_l_49c4;
	case 18886ULL: goto x86_l_49c6;
	case 18891ULL: goto x86_l_49cb;
	case 18893ULL: goto x86_l_49cd;
	case 18896ULL: goto x86_l_49d0;
	case 18902ULL: goto x86_l_49d6;
	case 18906ULL: goto x86_l_49da;
	case 18912ULL: goto x86_l_49e0;
	case 18916ULL: goto x86_l_49e4;
	case 18922ULL: goto x86_l_49ea;
	case 18926ULL: goto x86_l_49ee;
	case 18933ULL: goto x86_l_49f5;
	case 18938ULL: goto x86_l_49fa;
	case 18943ULL: goto x86_l_49ff;
	case 18952ULL: goto x86_l_4a08;
	case 18956ULL: goto x86_l_4a0c;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18973ULL: goto x86_l_4a1d;
	case 18975ULL: goto x86_l_4a1f;
	case 18979ULL: goto x86_l_4a23;
	case 18981ULL: goto x86_l_4a25;
	case 18983ULL: goto x86_l_4a27;
	case 18989ULL: goto x86_l_4a2d;
	case 18993ULL: goto x86_l_4a31;
	case 18999ULL: goto x86_l_4a37;
	case 19003ULL: goto x86_l_4a3b;
	case 19009ULL: goto x86_l_4a41;
	case 19013ULL: goto x86_l_4a45;
	case 19020ULL: goto x86_l_4a4c;
	case 19025ULL: goto x86_l_4a51;
	case 19030ULL: goto x86_l_4a56;
	case 19035ULL: goto x86_l_4a5b;
	case 19044ULL: goto x86_l_4a64;
	case 19048ULL: goto x86_l_4a68;
	case 19055ULL: goto x86_l_4a6f;
	case 19060ULL: goto x86_l_4a74;
	case 19062ULL: goto x86_l_4a76;
	case 19067ULL: goto x86_l_4a7b;
	case 19076ULL: goto x86_l_4a84;
	case 19079ULL: goto x86_l_4a87;
	case 19088ULL: goto x86_l_4a90;
	case 19097ULL: goto x86_l_4a99;
	case 19101ULL: goto x86_l_4a9d;
	case 19106ULL: goto x86_l_4aa2;
	case 19111ULL: goto x86_l_4aa7;
	case 19116ULL: goto x86_l_4aac;
	case 19121ULL: goto x86_l_4ab1;
	case 19123ULL: goto x86_l_4ab3;
	case 19128ULL: goto x86_l_4ab8;
	case 19130ULL: goto x86_l_4aba;
	case 19133ULL: goto x86_l_4abd;
	case 19139ULL: goto x86_l_4ac3;
	case 19143ULL: goto x86_l_4ac7;
	case 19149ULL: goto x86_l_4acd;
	case 19153ULL: goto x86_l_4ad1;
	case 19159ULL: goto x86_l_4ad7;
	case 19163ULL: goto x86_l_4adb;
	case 19170ULL: goto x86_l_4ae2;
	case 19175ULL: goto x86_l_4ae7;
	case 19180ULL: goto x86_l_4aec;
	case 19189ULL: goto x86_l_4af5;
	case 19193ULL: goto x86_l_4af9;
	case 19200ULL: goto x86_l_4b00;
	case 19205ULL: goto x86_l_4b05;
	case 19210ULL: goto x86_l_4b0a;
	case 19212ULL: goto x86_l_4b0c;
	case 19216ULL: goto x86_l_4b10;
	case 19218ULL: goto x86_l_4b12;
	case 19220ULL: goto x86_l_4b14;
	case 19226ULL: goto x86_l_4b1a;
	case 19230ULL: goto x86_l_4b1e;
	case 19236ULL: goto x86_l_4b24;
	case 19240ULL: goto x86_l_4b28;
	case 19246ULL: goto x86_l_4b2e;
	case 19250ULL: goto x86_l_4b32;
	case 19257ULL: goto x86_l_4b39;
	case 19262ULL: goto x86_l_4b3e;
	case 19267ULL: goto x86_l_4b43;
	case 19272ULL: goto x86_l_4b48;
	case 19281ULL: goto x86_l_4b51;
	case 19285ULL: goto x86_l_4b55;
	case 19292ULL: goto x86_l_4b5c;
	case 19297ULL: goto x86_l_4b61;
	case 19299ULL: goto x86_l_4b63;
	case 19304ULL: goto x86_l_4b68;
	case 19313ULL: goto x86_l_4b71;
	case 19316ULL: goto x86_l_4b74;
	case 19325ULL: goto x86_l_4b7d;
	case 19334ULL: goto x86_l_4b86;
	case 19338ULL: goto x86_l_4b8a;
	case 19343ULL: goto x86_l_4b8f;
	case 19348ULL: goto x86_l_4b94;
	case 19353ULL: goto x86_l_4b99;
	case 19358ULL: goto x86_l_4b9e;
	case 19360ULL: goto x86_l_4ba0;
	case 19365ULL: goto x86_l_4ba5;
	case 19367ULL: goto x86_l_4ba7;
	case 19370ULL: goto x86_l_4baa;
	case 19376ULL: goto x86_l_4bb0;
	case 19380ULL: goto x86_l_4bb4;
	case 19386ULL: goto x86_l_4bba;
	case 19390ULL: goto x86_l_4bbe;
	case 19396ULL: goto x86_l_4bc4;
	case 19400ULL: goto x86_l_4bc8;
	case 19407ULL: goto x86_l_4bcf;
	case 19412ULL: goto x86_l_4bd4;
	case 19417ULL: goto x86_l_4bd9;
	case 19426ULL: goto x86_l_4be2;
	case 19430ULL: goto x86_l_4be6;
	case 19437ULL: goto x86_l_4bed;
	case 19442ULL: goto x86_l_4bf2;
	case 19447ULL: goto x86_l_4bf7;
	case 19449ULL: goto x86_l_4bf9;
	case 19453ULL: goto x86_l_4bfd;
	case 19455ULL: goto x86_l_4bff;
	case 19457ULL: goto x86_l_4c01;
	case 19463ULL: goto x86_l_4c07;
	case 19467ULL: goto x86_l_4c0b;
	case 19473ULL: goto x86_l_4c11;
	case 19477ULL: goto x86_l_4c15;
	case 19483ULL: goto x86_l_4c1b;
	case 19487ULL: goto x86_l_4c1f;
	case 19494ULL: goto x86_l_4c26;
	case 19499ULL: goto x86_l_4c2b;
	case 19504ULL: goto x86_l_4c30;
	case 19509ULL: goto x86_l_4c35;
	case 19518ULL: goto x86_l_4c3e;
	case 19522ULL: goto x86_l_4c42;
	case 19529ULL: goto x86_l_4c49;
	case 19534ULL: goto x86_l_4c4e;
	case 19536ULL: goto x86_l_4c50;
	case 19541ULL: goto x86_l_4c55;
	case 19550ULL: goto x86_l_4c5e;
	case 19553ULL: goto x86_l_4c61;
	case 19562ULL: goto x86_l_4c6a;
	case 19571ULL: goto x86_l_4c73;
	case 19575ULL: goto x86_l_4c77;
	case 19580ULL: goto x86_l_4c7c;
	case 19585ULL: goto x86_l_4c81;
	case 19590ULL: goto x86_l_4c86;
	case 19595ULL: goto x86_l_4c8b;
	case 19597ULL: goto x86_l_4c8d;
	case 19602ULL: goto x86_l_4c92;
	case 19604ULL: goto x86_l_4c94;
	case 19607ULL: goto x86_l_4c97;
	case 19613ULL: goto x86_l_4c9d;
	case 19617ULL: goto x86_l_4ca1;
	case 19623ULL: goto x86_l_4ca7;
	case 19627ULL: goto x86_l_4cab;
	case 19633ULL: goto x86_l_4cb1;
	case 19637ULL: goto x86_l_4cb5;
	case 19644ULL: goto x86_l_4cbc;
	case 19649ULL: goto x86_l_4cc1;
	case 19654ULL: goto x86_l_4cc6;
	case 19663ULL: goto x86_l_4ccf;
	case 19667ULL: goto x86_l_4cd3;
	case 19674ULL: goto x86_l_4cda;
	case 19679ULL: goto x86_l_4cdf;
	case 19684ULL: goto x86_l_4ce4;
	case 19686ULL: goto x86_l_4ce6;
	case 19690ULL: goto x86_l_4cea;
	case 19692ULL: goto x86_l_4cec;
	case 19694ULL: goto x86_l_4cee;
	case 19700ULL: goto x86_l_4cf4;
	case 19704ULL: goto x86_l_4cf8;
	case 19710ULL: goto x86_l_4cfe;
	case 19714ULL: goto x86_l_4d02;
	case 19720ULL: goto x86_l_4d08;
	case 19724ULL: goto x86_l_4d0c;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19741ULL: goto x86_l_4d1d;
	case 19746ULL: goto x86_l_4d22;
	case 19755ULL: goto x86_l_4d2b;
	case 19759ULL: goto x86_l_4d2f;
	case 19766ULL: goto x86_l_4d36;
	case 19771ULL: goto x86_l_4d3b;
	case 19773ULL: goto x86_l_4d3d;
	case 19778ULL: goto x86_l_4d42;
	case 19787ULL: goto x86_l_4d4b;
	case 19790ULL: goto x86_l_4d4e;
	case 19799ULL: goto x86_l_4d57;
	case 19808ULL: goto x86_l_4d60;
	case 19812ULL: goto x86_l_4d64;
	case 19817ULL: goto x86_l_4d69;
	case 19822ULL: goto x86_l_4d6e;
	case 19827ULL: goto x86_l_4d73;
	case 19832ULL: goto x86_l_4d78;
	case 19834ULL: goto x86_l_4d7a;
	case 19839ULL: goto x86_l_4d7f;
	case 19841ULL: goto x86_l_4d81;
	case 19844ULL: goto x86_l_4d84;
	case 19850ULL: goto x86_l_4d8a;
	case 19854ULL: goto x86_l_4d8e;
	case 19860ULL: goto x86_l_4d94;
	case 19864ULL: goto x86_l_4d98;
	case 19870ULL: goto x86_l_4d9e;
	case 19874ULL: goto x86_l_4da2;
	case 19881ULL: goto x86_l_4da9;
	case 19886ULL: goto x86_l_4dae;
	case 19891ULL: goto x86_l_4db3;
	case 19900ULL: goto x86_l_4dbc;
	case 19904ULL: goto x86_l_4dc0;
	case 19911ULL: goto x86_l_4dc7;
	case 19916ULL: goto x86_l_4dcc;
	case 19921ULL: goto x86_l_4dd1;
	case 19923ULL: goto x86_l_4dd3;
	case 19927ULL: goto x86_l_4dd7;
	case 19929ULL: goto x86_l_4dd9;
	case 19931ULL: goto x86_l_4ddb;
	case 19937ULL: goto x86_l_4de1;
	case 19941ULL: goto x86_l_4de5;
	case 19947ULL: goto x86_l_4deb;
	case 19951ULL: goto x86_l_4def;
	case 19957ULL: goto x86_l_4df5;
	case 19961ULL: goto x86_l_4df9;
	case 19968ULL: goto x86_l_4e00;
	case 19973ULL: goto x86_l_4e05;
	case 19978ULL: goto x86_l_4e0a;
	case 19983ULL: goto x86_l_4e0f;
	case 19992ULL: goto x86_l_4e18;
	case 19996ULL: goto x86_l_4e1c;
	case 20003ULL: goto x86_l_4e23;
	case 20008ULL: goto x86_l_4e28;
	case 20010ULL: goto x86_l_4e2a;
	case 20015ULL: goto x86_l_4e2f;
	case 20024ULL: goto x86_l_4e38;
	case 20027ULL: goto x86_l_4e3b;
	case 20036ULL: goto x86_l_4e44;
	case 20045ULL: goto x86_l_4e4d;
	case 20049ULL: goto x86_l_4e51;
	case 20054ULL: goto x86_l_4e56;
	case 20059ULL: goto x86_l_4e5b;
	case 20064ULL: goto x86_l_4e60;
	case 20069ULL: goto x86_l_4e65;
	case 20071ULL: goto x86_l_4e67;
	case 20076ULL: goto x86_l_4e6c;
	case 20078ULL: goto x86_l_4e6e;
	case 20081ULL: goto x86_l_4e71;
	case 20087ULL: goto x86_l_4e77;
	case 20091ULL: goto x86_l_4e7b;
	case 20097ULL: goto x86_l_4e81;
	case 20101ULL: goto x86_l_4e85;
	case 20107ULL: goto x86_l_4e8b;
	case 20111ULL: goto x86_l_4e8f;
	case 20118ULL: goto x86_l_4e96;
	case 20123ULL: goto x86_l_4e9b;
	case 20128ULL: goto x86_l_4ea0;
	case 20137ULL: goto x86_l_4ea9;
	case 20141ULL: goto x86_l_4ead;
	case 20148ULL: goto x86_l_4eb4;
	case 20153ULL: goto x86_l_4eb9;
	case 20158ULL: goto x86_l_4ebe;
	case 20160ULL: goto x86_l_4ec0;
	case 20164ULL: goto x86_l_4ec4;
	case 20166ULL: goto x86_l_4ec6;
	case 20168ULL: goto x86_l_4ec8;
	case 20174ULL: goto x86_l_4ece;
	case 20178ULL: goto x86_l_4ed2;
	case 20184ULL: goto x86_l_4ed8;
	case 20188ULL: goto x86_l_4edc;
	case 20194ULL: goto x86_l_4ee2;
	case 20198ULL: goto x86_l_4ee6;
	case 20205ULL: goto x86_l_4eed;
	case 20210ULL: goto x86_l_4ef2;
	case 20215ULL: goto x86_l_4ef7;
	case 20220ULL: goto x86_l_4efc;
	case 20229ULL: goto x86_l_4f05;
	case 20233ULL: goto x86_l_4f09;
	case 20240ULL: goto x86_l_4f10;
	case 20245ULL: goto x86_l_4f15;
	case 20247ULL: goto x86_l_4f17;
	case 20252ULL: goto x86_l_4f1c;
	case 20261ULL: goto x86_l_4f25;
	case 20264ULL: goto x86_l_4f28;
	case 20273ULL: goto x86_l_4f31;
	case 20282ULL: goto x86_l_4f3a;
	case 20286ULL: goto x86_l_4f3e;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20301ULL: goto x86_l_4f4d;
	case 20306ULL: goto x86_l_4f52;
	case 20308ULL: goto x86_l_4f54;
	case 20313ULL: goto x86_l_4f59;
	case 20315ULL: goto x86_l_4f5b;
	case 20318ULL: goto x86_l_4f5e;
	case 20324ULL: goto x86_l_4f64;
	case 20328ULL: goto x86_l_4f68;
	case 20334ULL: goto x86_l_4f6e;
	case 20338ULL: goto x86_l_4f72;
	case 20344ULL: goto x86_l_4f78;
	case 20348ULL: goto x86_l_4f7c;
	case 20355ULL: goto x86_l_4f83;
	case 20360ULL: goto x86_l_4f88;
	case 20365ULL: goto x86_l_4f8d;
	case 20374ULL: goto x86_l_4f96;
	case 20378ULL: goto x86_l_4f9a;
	case 20385ULL: goto x86_l_4fa1;
	case 20390ULL: goto x86_l_4fa6;
	case 20395ULL: goto x86_l_4fab;
	case 20397ULL: goto x86_l_4fad;
	case 20401ULL: goto x86_l_4fb1;
	case 20403ULL: goto x86_l_4fb3;
	case 20405ULL: goto x86_l_4fb5;
	case 20411ULL: goto x86_l_4fbb;
	case 20415ULL: goto x86_l_4fbf;
	case 20421ULL: goto x86_l_4fc5;
	case 20425ULL: goto x86_l_4fc9;
	case 20431ULL: goto x86_l_4fcf;
	case 20435ULL: goto x86_l_4fd3;
	case 20442ULL: goto x86_l_4fda;
	case 20447ULL: goto x86_l_4fdf;
	case 20452ULL: goto x86_l_4fe4;
	case 20457ULL: goto x86_l_4fe9;
	case 20466ULL: goto x86_l_4ff2;
	case 20470ULL: goto x86_l_4ff6;
	case 20477ULL: goto x86_l_4ffd;
	case 20482ULL: goto x86_l_5002;
	case 20484ULL: goto x86_l_5004;
	case 20489ULL: goto x86_l_5009;
	case 20498ULL: goto x86_l_5012;
	case 20501ULL: goto x86_l_5015;
	case 20510ULL: goto x86_l_501e;
	case 20519ULL: goto x86_l_5027;
	case 20523ULL: goto x86_l_502b;
	case 20528ULL: goto x86_l_5030;
	case 20533ULL: goto x86_l_5035;
	case 20538ULL: goto x86_l_503a;
	case 20543ULL: goto x86_l_503f;
	case 20545ULL: goto x86_l_5041;
	case 20550ULL: goto x86_l_5046;
	case 20552ULL: goto x86_l_5048;
	case 20555ULL: goto x86_l_504b;
	case 20561ULL: goto x86_l_5051;
	case 20565ULL: goto x86_l_5055;
	case 20571ULL: goto x86_l_505b;
	case 20575ULL: goto x86_l_505f;
	case 20581ULL: goto x86_l_5065;
	case 20585ULL: goto x86_l_5069;
	case 20592ULL: goto x86_l_5070;
	case 20597ULL: goto x86_l_5075;
	default: return 0xffffffffffffffffULL;
	}
x86_l_48e9:
	/* 0x48e9: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48ed:
	/* 0x48ed: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_48f3:
	/* 0x48f3: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48f7:
	/* 0x48f7: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_48fd:
	/* 0x48fd: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4901:
	/* 0x4901: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4908:
	/* 0x4908: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_490d:
	/* 0x490d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4912:
	/* 0x4912: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_491b:
	/* 0x491b: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_491f:
	/* 0x491f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4926:
	/* 0x4926: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_492b:
	/* 0x492b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4930:
	/* 0x4930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4932:
	/* 0x4932: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4936:
	/* 0x4936: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_4938:
	/* 0x4938: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_493a:
	/* 0x493a: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4940:
	/* 0x4940: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4944:
	/* 0x4944: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_494a:
	/* 0x494a: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_494e:
	/* 0x494e: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4954:
	/* 0x4954: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4958:
	/* 0x4958: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_495f:
	/* 0x495f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4964:
	/* 0x4964: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4969:
	/* 0x4969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_496e:
	/* 0x496e: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4977:
	/* 0x4977: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_497b:
	/* 0x497b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4982:
	/* 0x4982: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4987:
	/* 0x4987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4989:
	/* 0x4989: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_498e:
	/* 0x498e: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4997:
	/* 0x4997: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_499a:
	/* 0x499a: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_49a3:
	/* 0x49a3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_49ac:
	/* 0x49ac: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49b0:
	/* 0x49b0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49b5:
	/* 0x49b5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49ba:
	/* 0x49ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49bf:
	/* 0x49bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c4:
	/* 0x49c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c6:
	/* 0x49c6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49cb:
	/* 0x49cb: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_49cd:
	/* 0x49cd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_49d0:
	/* 0x49d0: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_49d6:
	/* 0x49d6: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49da:
	/* 0x49da: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_49e0:
	/* 0x49e0: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e4:
	/* 0x49e4: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_49ea:
	/* 0x49ea: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_49ee:
	/* 0x49ee: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49f5:
	/* 0x49f5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49fa:
	/* 0x49fa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_49ff:
	/* 0x49ff: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a08:
	/* 0x4a08: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4a0c:
	/* 0x4a0c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a13:
	/* 0x4a13: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a18:
	/* 0x4a18: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a1d:
	/* 0x4a1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1f:
	/* 0x4a1f: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a23:
	/* 0x4a23: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_4a25:
	/* 0x4a25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a27:
	/* 0x4a27: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4a2d:
	/* 0x4a2d: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a31:
	/* 0x4a31: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4a37:
	/* 0x4a37: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a3b:
	/* 0x4a3b: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4a41:
	/* 0x4a41: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a45:
	/* 0x4a45: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a4c:
	/* 0x4a4c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a51:
	/* 0x4a51: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a56:
	/* 0x4a56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a5b:
	/* 0x4a5b: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a64:
	/* 0x4a64: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a68:
	/* 0x4a68: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a6f:
	/* 0x4a6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a74:
	/* 0x4a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a76:
	/* 0x4a76: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4a7b:
	/* 0x4a7b: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4a84:
	/* 0x4a84: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4a87:
	/* 0x4a87: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4a90:
	/* 0x4a90: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4a99:
	/* 0x4a99: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a9d:
	/* 0x4a9d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4aa2:
	/* 0x4aa2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4aa7:
	/* 0x4aa7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aac:
	/* 0x4aac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ab1:
	/* 0x4ab1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab3:
	/* 0x4ab3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ab8:
	/* 0x4ab8: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_4aba:
	/* 0x4aba: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4abd:
	/* 0x4abd: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4ac3:
	/* 0x4ac3: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ac7:
	/* 0x4ac7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4acd:
	/* 0x4acd: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad1:
	/* 0x4ad1: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4ad7:
	/* 0x4ad7: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4adb:
	/* 0x4adb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ae2:
	/* 0x4ae2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ae7:
	/* 0x4ae7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4aec:
	/* 0x4aec: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4af5:
	/* 0x4af5: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4af9:
	/* 0x4af9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b00:
	/* 0x4b00: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b05:
	/* 0x4b05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b0a:
	/* 0x4b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b0c:
	/* 0x4b0c: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b10:
	/* 0x4b10: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_4b12:
	/* 0x4b12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b14:
	/* 0x4b14: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4b1a:
	/* 0x4b1a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b1e:
	/* 0x4b1e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4b24:
	/* 0x4b24: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b28:
	/* 0x4b28: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4b2e:
	/* 0x4b2e: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4b32:
	/* 0x4b32: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b39:
	/* 0x4b39: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b3e:
	/* 0x4b3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b43:
	/* 0x4b43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b48:
	/* 0x4b48: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b51:
	/* 0x4b51: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b55:
	/* 0x4b55: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b5c:
	/* 0x4b5c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b61:
	/* 0x4b61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b63:
	/* 0x4b63: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4b68:
	/* 0x4b68: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4b71:
	/* 0x4b71: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4b74:
	/* 0x4b74: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4b7d:
	/* 0x4b7d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4b86:
	/* 0x4b86: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b8a:
	/* 0x4b8a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b8f:
	/* 0x4b8f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b94:
	/* 0x4b94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b99:
	/* 0x4b99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b9e:
	/* 0x4b9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba0:
	/* 0x4ba0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba5:
	/* 0x4ba5: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_4ba7:
	/* 0x4ba7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4baa:
	/* 0x4baa: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4bb0:
	/* 0x4bb0: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bb4:
	/* 0x4bb4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4bba:
	/* 0x4bba: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bbe:
	/* 0x4bbe: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4bc4:
	/* 0x4bc4: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4bc8:
	/* 0x4bc8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4bcf:
	/* 0x4bcf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4bd4:
	/* 0x4bd4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4bd9:
	/* 0x4bd9: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4be2:
	/* 0x4be2: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4be6:
	/* 0x4be6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4bed:
	/* 0x4bed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bf2:
	/* 0x4bf2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4bf7:
	/* 0x4bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf9:
	/* 0x4bf9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bfd:
	/* 0x4bfd: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_4bff:
	/* 0x4bff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c01:
	/* 0x4c01: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4c07:
	/* 0x4c07: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c0b:
	/* 0x4c0b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4c11:
	/* 0x4c11: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c15:
	/* 0x4c15: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4c1b:
	/* 0x4c1b: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4c1f:
	/* 0x4c1f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c26:
	/* 0x4c26: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c2b:
	/* 0x4c2b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c30:
	/* 0x4c30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c35:
	/* 0x4c35: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c3e:
	/* 0x4c3e: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4c42:
	/* 0x4c42: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c49:
	/* 0x4c49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c4e:
	/* 0x4c4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c50:
	/* 0x4c50: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4c55:
	/* 0x4c55: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c5e:
	/* 0x4c5e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c61:
	/* 0x4c61: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c6a:
	/* 0x4c6a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c73:
	/* 0x4c73: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c77:
	/* 0x4c77: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c7c:
	/* 0x4c7c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c81:
	/* 0x4c81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c86:
	/* 0x4c86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c8b:
	/* 0x4c8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c8d:
	/* 0x4c8d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c92:
	/* 0x4c92: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_4c94:
	/* 0x4c94: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4c97:
	/* 0x4c97: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4c9d:
	/* 0x4c9d: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ca1:
	/* 0x4ca1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4ca7:
	/* 0x4ca7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cab:
	/* 0x4cab: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4cb1:
	/* 0x4cb1: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4cb5:
	/* 0x4cb5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4cbc:
	/* 0x4cbc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4cc1:
	/* 0x4cc1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cc6:
	/* 0x4cc6: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ccf:
	/* 0x4ccf: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4cd3:
	/* 0x4cd3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4cda:
	/* 0x4cda: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cdf:
	/* 0x4cdf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ce4:
	/* 0x4ce4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ce6:
	/* 0x4ce6: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cea:
	/* 0x4cea: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_4cec:
	/* 0x4cec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cee:
	/* 0x4cee: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4cf4:
	/* 0x4cf4: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4cf8:
	/* 0x4cf8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4cfe:
	/* 0x4cfe: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d02:
	/* 0x4d02: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4d08:
	/* 0x4d08: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4d0c:
	/* 0x4d0c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d13:
	/* 0x4d13: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d18:
	/* 0x4d18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d1d:
	/* 0x4d1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d22:
	/* 0x4d22: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d2b:
	/* 0x4d2b: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4d2f:
	/* 0x4d2f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d36:
	/* 0x4d36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d3b:
	/* 0x4d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d3d:
	/* 0x4d3d: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4d42:
	/* 0x4d42: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4d4b:
	/* 0x4d4b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d4e:
	/* 0x4d4e: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d57:
	/* 0x4d57: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d60:
	/* 0x4d60: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d64:
	/* 0x4d64: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d69:
	/* 0x4d69: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d6e:
	/* 0x4d6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d73:
	/* 0x4d73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d78:
	/* 0x4d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d7a:
	/* 0x4d7a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d7f:
	/* 0x4d7f: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_4d81:
	/* 0x4d81: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4d84:
	/* 0x4d84: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4d8a:
	/* 0x4d8a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d8e:
	/* 0x4d8e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4d94:
	/* 0x4d94: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d98:
	/* 0x4d98: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4d9e:
	/* 0x4d9e: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4da2:
	/* 0x4da2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4da9:
	/* 0x4da9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4dae:
	/* 0x4dae: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4db3:
	/* 0x4db3: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dbc:
	/* 0x4dbc: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4dc0:
	/* 0x4dc0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4dc7:
	/* 0x4dc7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4dd1:
	/* 0x4dd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dd3:
	/* 0x4dd3: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd7:
	/* 0x4dd7: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_4dd9:
	/* 0x4dd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ddb:
	/* 0x4ddb: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4de1:
	/* 0x4de1: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4de5:
	/* 0x4de5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4deb:
	/* 0x4deb: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4def:
	/* 0x4def: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4df5:
	/* 0x4df5: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4df9:
	/* 0x4df9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e00:
	/* 0x4e00: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e05:
	/* 0x4e05: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e0a:
	/* 0x4e0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e0f:
	/* 0x4e0f: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e18:
	/* 0x4e18: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4e1c:
	/* 0x4e1c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e23:
	/* 0x4e23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e28:
	/* 0x4e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2a:
	/* 0x4e2a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4e2f:
	/* 0x4e2f: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4e38:
	/* 0x4e38: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4e3b:
	/* 0x4e3b: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4e44:
	/* 0x4e44: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e4d:
	/* 0x4e4d: lea    rdx,[rbp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4e51:
	/* 0x4e51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e56:
	/* 0x4e56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e5b:
	/* 0x4e5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e60:
	/* 0x4e60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e65:
	/* 0x4e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e67:
	/* 0x4e67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e6c:
	/* 0x4e6c: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_4e6e:
	/* 0x4e6e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4e71:
	/* 0x4e71: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4e77:
	/* 0x4e77: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e7b:
	/* 0x4e7b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4e81:
	/* 0x4e81: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e85:
	/* 0x4e85: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4e8b:
	/* 0x4e8b: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4e8f:
	/* 0x4e8f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e96:
	/* 0x4e96: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e9b:
	/* 0x4e9b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ea0:
	/* 0x4ea0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ea9:
	/* 0x4ea9: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4ead:
	/* 0x4ead: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4eb4:
	/* 0x4eb4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4eb9:
	/* 0x4eb9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ebe:
	/* 0x4ebe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec0:
	/* 0x4ec0: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ec4:
	/* 0x4ec4: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_4ec6:
	/* 0x4ec6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ec8:
	/* 0x4ec8: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4ece:
	/* 0x4ece: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ed2:
	/* 0x4ed2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4ed8:
	/* 0x4ed8: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4edc:
	/* 0x4edc: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4ee2:
	/* 0x4ee2: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4ee6:
	/* 0x4ee6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4eed:
	/* 0x4eed: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef2:
	/* 0x4ef2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ef7:
	/* 0x4ef7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4efc:
	/* 0x4efc: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f05:
	/* 0x4f05: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f09:
	/* 0x4f09: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f10:
	/* 0x4f10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f15:
	/* 0x4f15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f17:
	/* 0x4f17: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4f1c:
	/* 0x4f1c: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4f25:
	/* 0x4f25: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4f28:
	/* 0x4f28: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4f31:
	/* 0x4f31: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f3a:
	/* 0x4f3a: lea    rdx,[rbp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4f3e:
	/* 0x4f3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f43:
	/* 0x4f43: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f48:
	/* 0x4f48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f4d:
	/* 0x4f4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f52:
	/* 0x4f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f54:
	/* 0x4f54: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f59:
	/* 0x4f59: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_4f5b:
	/* 0x4f5b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4f5e:
	/* 0x4f5e: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_4f64:
	/* 0x4f64: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f68:
	/* 0x4f68: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4f6e:
	/* 0x4f6e: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f72:
	/* 0x4f72: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4f78:
	/* 0x4f78: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4f7c:
	/* 0x4f7c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f83:
	/* 0x4f83: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f88:
	/* 0x4f88: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4f8d:
	/* 0x4f8d: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f96:
	/* 0x4f96: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_4f9a:
	/* 0x4f9a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4fa1:
	/* 0x4fa1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fa6:
	/* 0x4fa6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4fab:
	/* 0x4fab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fad:
	/* 0x4fad: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb1:
	/* 0x4fb1: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_4fb3:
	/* 0x4fb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fb5:
	/* 0x4fb5: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_4fbb:
	/* 0x4fbb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fbf:
	/* 0x4fbf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4fc5:
	/* 0x4fc5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fc9:
	/* 0x4fc9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_4fcf:
	/* 0x4fcf: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4fd3:
	/* 0x4fd3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4fda:
	/* 0x4fda: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fdf:
	/* 0x4fdf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4fe4:
	/* 0x4fe4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fe9:
	/* 0x4fe9: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ff2:
	/* 0x4ff2: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ff6:
	/* 0x4ff6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ffd:
	/* 0x4ffd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5002:
	/* 0x5002: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5004:
	/* 0x5004: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5009:
	/* 0x5009: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5012:
	/* 0x5012: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5015:
	/* 0x5015: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_501e:
	/* 0x501e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5027:
	/* 0x5027: lea    rdx,[rbp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_502b:
	/* 0x502b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5030:
	/* 0x5030: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5035:
	/* 0x5035: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_503a:
	/* 0x503a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_503f:
	/* 0x503f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5041:
	/* 0x5041: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5046:
	/* 0x5046: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_5048:
	/* 0x5048: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_504b:
	/* 0x504b: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5051:
	/* 0x5051: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5055:
	/* 0x5055: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_505b:
	/* 0x505b: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_505f:
	/* 0x505f: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5065:
	/* 0x5065: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5069:
	/* 0x5069: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5070:
	/* 0x5070: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5075:
	/* 0x5075: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
	return 20602ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20602ULL: goto x86_l_507a;
	case 20611ULL: goto x86_l_5083;
	case 20615ULL: goto x86_l_5087;
	case 20622ULL: goto x86_l_508e;
	case 20627ULL: goto x86_l_5093;
	case 20632ULL: goto x86_l_5098;
	case 20634ULL: goto x86_l_509a;
	case 20638ULL: goto x86_l_509e;
	case 20640ULL: goto x86_l_50a0;
	case 20642ULL: goto x86_l_50a2;
	case 20648ULL: goto x86_l_50a8;
	case 20652ULL: goto x86_l_50ac;
	case 20658ULL: goto x86_l_50b2;
	case 20662ULL: goto x86_l_50b6;
	case 20668ULL: goto x86_l_50bc;
	case 20672ULL: goto x86_l_50c0;
	case 20679ULL: goto x86_l_50c7;
	case 20684ULL: goto x86_l_50cc;
	case 20689ULL: goto x86_l_50d1;
	case 20694ULL: goto x86_l_50d6;
	case 20703ULL: goto x86_l_50df;
	case 20707ULL: goto x86_l_50e3;
	case 20714ULL: goto x86_l_50ea;
	case 20719ULL: goto x86_l_50ef;
	case 20721ULL: goto x86_l_50f1;
	case 20726ULL: goto x86_l_50f6;
	case 20735ULL: goto x86_l_50ff;
	case 20738ULL: goto x86_l_5102;
	case 20747ULL: goto x86_l_510b;
	case 20756ULL: goto x86_l_5114;
	case 20760ULL: goto x86_l_5118;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20775ULL: goto x86_l_5127;
	case 20780ULL: goto x86_l_512c;
	case 20782ULL: goto x86_l_512e;
	case 20787ULL: goto x86_l_5133;
	case 20789ULL: goto x86_l_5135;
	case 20792ULL: goto x86_l_5138;
	case 20798ULL: goto x86_l_513e;
	case 20802ULL: goto x86_l_5142;
	case 20808ULL: goto x86_l_5148;
	case 20812ULL: goto x86_l_514c;
	case 20818ULL: goto x86_l_5152;
	case 20822ULL: goto x86_l_5156;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20839ULL: goto x86_l_5167;
	case 20848ULL: goto x86_l_5170;
	case 20852ULL: goto x86_l_5174;
	case 20859ULL: goto x86_l_517b;
	case 20864ULL: goto x86_l_5180;
	case 20869ULL: goto x86_l_5185;
	case 20871ULL: goto x86_l_5187;
	case 20875ULL: goto x86_l_518b;
	case 20877ULL: goto x86_l_518d;
	case 20879ULL: goto x86_l_518f;
	case 20885ULL: goto x86_l_5195;
	case 20889ULL: goto x86_l_5199;
	case 20895ULL: goto x86_l_519f;
	case 20899ULL: goto x86_l_51a3;
	case 20905ULL: goto x86_l_51a9;
	case 20909ULL: goto x86_l_51ad;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	case 20926ULL: goto x86_l_51be;
	case 20931ULL: goto x86_l_51c3;
	case 20940ULL: goto x86_l_51cc;
	case 20944ULL: goto x86_l_51d0;
	case 20951ULL: goto x86_l_51d7;
	case 20956ULL: goto x86_l_51dc;
	case 20958ULL: goto x86_l_51de;
	case 20963ULL: goto x86_l_51e3;
	case 20972ULL: goto x86_l_51ec;
	case 20975ULL: goto x86_l_51ef;
	case 20984ULL: goto x86_l_51f8;
	case 20993ULL: goto x86_l_5201;
	case 20997ULL: goto x86_l_5205;
	case 21002ULL: goto x86_l_520a;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21017ULL: goto x86_l_5219;
	case 21019ULL: goto x86_l_521b;
	case 21024ULL: goto x86_l_5220;
	case 21026ULL: goto x86_l_5222;
	case 21029ULL: goto x86_l_5225;
	case 21035ULL: goto x86_l_522b;
	case 21039ULL: goto x86_l_522f;
	case 21045ULL: goto x86_l_5235;
	case 21049ULL: goto x86_l_5239;
	case 21055ULL: goto x86_l_523f;
	case 21059ULL: goto x86_l_5243;
	case 21066ULL: goto x86_l_524a;
	case 21071ULL: goto x86_l_524f;
	case 21076ULL: goto x86_l_5254;
	case 21085ULL: goto x86_l_525d;
	case 21089ULL: goto x86_l_5261;
	case 21096ULL: goto x86_l_5268;
	case 21101ULL: goto x86_l_526d;
	case 21106ULL: goto x86_l_5272;
	case 21108ULL: goto x86_l_5274;
	case 21112ULL: goto x86_l_5278;
	case 21114ULL: goto x86_l_527a;
	case 21116ULL: goto x86_l_527c;
	case 21122ULL: goto x86_l_5282;
	case 21126ULL: goto x86_l_5286;
	case 21132ULL: goto x86_l_528c;
	case 21136ULL: goto x86_l_5290;
	case 21142ULL: goto x86_l_5296;
	case 21146ULL: goto x86_l_529a;
	case 21153ULL: goto x86_l_52a1;
	case 21158ULL: goto x86_l_52a6;
	case 21163ULL: goto x86_l_52ab;
	case 21168ULL: goto x86_l_52b0;
	case 21177ULL: goto x86_l_52b9;
	case 21181ULL: goto x86_l_52bd;
	case 21188ULL: goto x86_l_52c4;
	case 21193ULL: goto x86_l_52c9;
	case 21195ULL: goto x86_l_52cb;
	case 21200ULL: goto x86_l_52d0;
	case 21209ULL: goto x86_l_52d9;
	case 21212ULL: goto x86_l_52dc;
	case 21221ULL: goto x86_l_52e5;
	case 21230ULL: goto x86_l_52ee;
	case 21237ULL: goto x86_l_52f5;
	case 21242ULL: goto x86_l_52fa;
	case 21247ULL: goto x86_l_52ff;
	case 21252ULL: goto x86_l_5304;
	case 21257ULL: goto x86_l_5309;
	case 21259ULL: goto x86_l_530b;
	case 21264ULL: goto x86_l_5310;
	case 21266ULL: goto x86_l_5312;
	case 21269ULL: goto x86_l_5315;
	case 21275ULL: goto x86_l_531b;
	case 21279ULL: goto x86_l_531f;
	case 21285ULL: goto x86_l_5325;
	case 21289ULL: goto x86_l_5329;
	case 21295ULL: goto x86_l_532f;
	case 21299ULL: goto x86_l_5333;
	case 21306ULL: goto x86_l_533a;
	case 21311ULL: goto x86_l_533f;
	case 21316ULL: goto x86_l_5344;
	case 21325ULL: goto x86_l_534d;
	case 21329ULL: goto x86_l_5351;
	case 21336ULL: goto x86_l_5358;
	case 21341ULL: goto x86_l_535d;
	case 21346ULL: goto x86_l_5362;
	case 21348ULL: goto x86_l_5364;
	case 21352ULL: goto x86_l_5368;
	case 21354ULL: goto x86_l_536a;
	case 21356ULL: goto x86_l_536c;
	case 21362ULL: goto x86_l_5372;
	case 21366ULL: goto x86_l_5376;
	case 21372ULL: goto x86_l_537c;
	case 21376ULL: goto x86_l_5380;
	case 21382ULL: goto x86_l_5386;
	case 21386ULL: goto x86_l_538a;
	case 21393ULL: goto x86_l_5391;
	case 21398ULL: goto x86_l_5396;
	case 21403ULL: goto x86_l_539b;
	case 21408ULL: goto x86_l_53a0;
	case 21417ULL: goto x86_l_53a9;
	case 21421ULL: goto x86_l_53ad;
	case 21428ULL: goto x86_l_53b4;
	case 21433ULL: goto x86_l_53b9;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21449ULL: goto x86_l_53c9;
	case 21452ULL: goto x86_l_53cc;
	case 21461ULL: goto x86_l_53d5;
	case 21470ULL: goto x86_l_53de;
	case 21477ULL: goto x86_l_53e5;
	case 21482ULL: goto x86_l_53ea;
	case 21487ULL: goto x86_l_53ef;
	case 21492ULL: goto x86_l_53f4;
	case 21497ULL: goto x86_l_53f9;
	case 21499ULL: goto x86_l_53fb;
	case 21504ULL: goto x86_l_5400;
	case 21506ULL: goto x86_l_5402;
	case 21509ULL: goto x86_l_5405;
	case 21515ULL: goto x86_l_540b;
	case 21519ULL: goto x86_l_540f;
	case 21525ULL: goto x86_l_5415;
	case 21529ULL: goto x86_l_5419;
	case 21535ULL: goto x86_l_541f;
	case 21539ULL: goto x86_l_5423;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21556ULL: goto x86_l_5434;
	case 21565ULL: goto x86_l_543d;
	case 21569ULL: goto x86_l_5441;
	case 21576ULL: goto x86_l_5448;
	case 21581ULL: goto x86_l_544d;
	case 21586ULL: goto x86_l_5452;
	case 21588ULL: goto x86_l_5454;
	case 21592ULL: goto x86_l_5458;
	case 21594ULL: goto x86_l_545a;
	case 21596ULL: goto x86_l_545c;
	case 21602ULL: goto x86_l_5462;
	case 21606ULL: goto x86_l_5466;
	case 21612ULL: goto x86_l_546c;
	case 21616ULL: goto x86_l_5470;
	case 21622ULL: goto x86_l_5476;
	case 21626ULL: goto x86_l_547a;
	case 21633ULL: goto x86_l_5481;
	case 21638ULL: goto x86_l_5486;
	case 21643ULL: goto x86_l_548b;
	case 21648ULL: goto x86_l_5490;
	case 21657ULL: goto x86_l_5499;
	case 21661ULL: goto x86_l_549d;
	case 21668ULL: goto x86_l_54a4;
	case 21673ULL: goto x86_l_54a9;
	case 21675ULL: goto x86_l_54ab;
	case 21680ULL: goto x86_l_54b0;
	case 21689ULL: goto x86_l_54b9;
	case 21692ULL: goto x86_l_54bc;
	case 21701ULL: goto x86_l_54c5;
	case 21710ULL: goto x86_l_54ce;
	case 21717ULL: goto x86_l_54d5;
	case 21722ULL: goto x86_l_54da;
	case 21727ULL: goto x86_l_54df;
	case 21732ULL: goto x86_l_54e4;
	case 21737ULL: goto x86_l_54e9;
	case 21739ULL: goto x86_l_54eb;
	case 21744ULL: goto x86_l_54f0;
	case 21746ULL: goto x86_l_54f2;
	case 21749ULL: goto x86_l_54f5;
	case 21755ULL: goto x86_l_54fb;
	case 21759ULL: goto x86_l_54ff;
	case 21765ULL: goto x86_l_5505;
	case 21769ULL: goto x86_l_5509;
	case 21775ULL: goto x86_l_550f;
	case 21779ULL: goto x86_l_5513;
	case 21786ULL: goto x86_l_551a;
	case 21791ULL: goto x86_l_551f;
	case 21796ULL: goto x86_l_5524;
	case 21805ULL: goto x86_l_552d;
	case 21809ULL: goto x86_l_5531;
	case 21816ULL: goto x86_l_5538;
	case 21821ULL: goto x86_l_553d;
	case 21826ULL: goto x86_l_5542;
	case 21828ULL: goto x86_l_5544;
	case 21832ULL: goto x86_l_5548;
	case 21834ULL: goto x86_l_554a;
	case 21836ULL: goto x86_l_554c;
	case 21842ULL: goto x86_l_5552;
	case 21846ULL: goto x86_l_5556;
	case 21852ULL: goto x86_l_555c;
	case 21856ULL: goto x86_l_5560;
	case 21862ULL: goto x86_l_5566;
	case 21866ULL: goto x86_l_556a;
	case 21873ULL: goto x86_l_5571;
	case 21878ULL: goto x86_l_5576;
	case 21883ULL: goto x86_l_557b;
	case 21888ULL: goto x86_l_5580;
	case 21897ULL: goto x86_l_5589;
	case 21901ULL: goto x86_l_558d;
	case 21908ULL: goto x86_l_5594;
	case 21913ULL: goto x86_l_5599;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21929ULL: goto x86_l_55a9;
	case 21932ULL: goto x86_l_55ac;
	case 21941ULL: goto x86_l_55b5;
	case 21950ULL: goto x86_l_55be;
	case 21957ULL: goto x86_l_55c5;
	case 21962ULL: goto x86_l_55ca;
	case 21967ULL: goto x86_l_55cf;
	case 21972ULL: goto x86_l_55d4;
	case 21977ULL: goto x86_l_55d9;
	case 21979ULL: goto x86_l_55db;
	case 21984ULL: goto x86_l_55e0;
	case 21986ULL: goto x86_l_55e2;
	case 21989ULL: goto x86_l_55e5;
	case 21995ULL: goto x86_l_55eb;
	case 21999ULL: goto x86_l_55ef;
	case 22005ULL: goto x86_l_55f5;
	case 22009ULL: goto x86_l_55f9;
	case 22015ULL: goto x86_l_55ff;
	case 22019ULL: goto x86_l_5603;
	case 22026ULL: goto x86_l_560a;
	case 22031ULL: goto x86_l_560f;
	case 22036ULL: goto x86_l_5614;
	case 22045ULL: goto x86_l_561d;
	case 22049ULL: goto x86_l_5621;
	case 22056ULL: goto x86_l_5628;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22068ULL: goto x86_l_5634;
	case 22072ULL: goto x86_l_5638;
	case 22074ULL: goto x86_l_563a;
	case 22076ULL: goto x86_l_563c;
	case 22082ULL: goto x86_l_5642;
	case 22086ULL: goto x86_l_5646;
	case 22092ULL: goto x86_l_564c;
	case 22096ULL: goto x86_l_5650;
	case 22102ULL: goto x86_l_5656;
	case 22106ULL: goto x86_l_565a;
	case 22113ULL: goto x86_l_5661;
	case 22118ULL: goto x86_l_5666;
	case 22123ULL: goto x86_l_566b;
	case 22128ULL: goto x86_l_5670;
	case 22137ULL: goto x86_l_5679;
	case 22141ULL: goto x86_l_567d;
	case 22148ULL: goto x86_l_5684;
	case 22153ULL: goto x86_l_5689;
	case 22155ULL: goto x86_l_568b;
	case 22160ULL: goto x86_l_5690;
	case 22169ULL: goto x86_l_5699;
	case 22172ULL: goto x86_l_569c;
	case 22181ULL: goto x86_l_56a5;
	case 22190ULL: goto x86_l_56ae;
	case 22197ULL: goto x86_l_56b5;
	case 22202ULL: goto x86_l_56ba;
	case 22207ULL: goto x86_l_56bf;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22219ULL: goto x86_l_56cb;
	case 22224ULL: goto x86_l_56d0;
	case 22226ULL: goto x86_l_56d2;
	case 22229ULL: goto x86_l_56d5;
	case 22235ULL: goto x86_l_56db;
	case 22239ULL: goto x86_l_56df;
	case 22245ULL: goto x86_l_56e5;
	case 22249ULL: goto x86_l_56e9;
	case 22255ULL: goto x86_l_56ef;
	case 22259ULL: goto x86_l_56f3;
	case 22266ULL: goto x86_l_56fa;
	case 22271ULL: goto x86_l_56ff;
	case 22276ULL: goto x86_l_5704;
	case 22285ULL: goto x86_l_570d;
	case 22289ULL: goto x86_l_5711;
	case 22296ULL: goto x86_l_5718;
	case 22301ULL: goto x86_l_571d;
	case 22306ULL: goto x86_l_5722;
	case 22308ULL: goto x86_l_5724;
	case 22312ULL: goto x86_l_5728;
	case 22314ULL: goto x86_l_572a;
	case 22316ULL: goto x86_l_572c;
	case 22322ULL: goto x86_l_5732;
	case 22326ULL: goto x86_l_5736;
	case 22332ULL: goto x86_l_573c;
	case 22336ULL: goto x86_l_5740;
	case 22342ULL: goto x86_l_5746;
	case 22346ULL: goto x86_l_574a;
	case 22353ULL: goto x86_l_5751;
	case 22358ULL: goto x86_l_5756;
	case 22363ULL: goto x86_l_575b;
	case 22368ULL: goto x86_l_5760;
	case 22377ULL: goto x86_l_5769;
	case 22381ULL: goto x86_l_576d;
	case 22388ULL: goto x86_l_5774;
	case 22393ULL: goto x86_l_5779;
	case 22395ULL: goto x86_l_577b;
	case 22400ULL: goto x86_l_5780;
	case 22409ULL: goto x86_l_5789;
	case 22412ULL: goto x86_l_578c;
	case 22421ULL: goto x86_l_5795;
	case 22430ULL: goto x86_l_579e;
	case 22437ULL: goto x86_l_57a5;
	case 22442ULL: goto x86_l_57aa;
	case 22447ULL: goto x86_l_57af;
	case 22452ULL: goto x86_l_57b4;
	case 22457ULL: goto x86_l_57b9;
	case 22459ULL: goto x86_l_57bb;
	case 22464ULL: goto x86_l_57c0;
	case 22466ULL: goto x86_l_57c2;
	case 22469ULL: goto x86_l_57c5;
	case 22475ULL: goto x86_l_57cb;
	case 22479ULL: goto x86_l_57cf;
	case 22485ULL: goto x86_l_57d5;
	case 22489ULL: goto x86_l_57d9;
	case 22495ULL: goto x86_l_57df;
	case 22499ULL: goto x86_l_57e3;
	case 22506ULL: goto x86_l_57ea;
	case 22511ULL: goto x86_l_57ef;
	case 22516ULL: goto x86_l_57f4;
	case 22525ULL: goto x86_l_57fd;
	case 22529ULL: goto x86_l_5801;
	case 22536ULL: goto x86_l_5808;
	case 22541ULL: goto x86_l_580d;
	case 22546ULL: goto x86_l_5812;
	case 22548ULL: goto x86_l_5814;
	case 22552ULL: goto x86_l_5818;
	default: return 0xffffffffffffffffULL;
	}
x86_l_507a:
	/* 0x507a: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5083:
	/* 0x5083: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5087:
	/* 0x5087: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_508e:
	/* 0x508e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5093:
	/* 0x5093: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5098:
	/* 0x5098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_509a:
	/* 0x509a: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_509e:
	/* 0x509e: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_50a0:
	/* 0x50a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50a2:
	/* 0x50a2: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_50a8:
	/* 0x50a8: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50ac:
	/* 0x50ac: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_50b2:
	/* 0x50b2: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50b6:
	/* 0x50b6: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_50bc:
	/* 0x50bc: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_50c0:
	/* 0x50c0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50c7:
	/* 0x50c7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50cc:
	/* 0x50cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50d1:
	/* 0x50d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50d6:
	/* 0x50d6: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50df:
	/* 0x50df: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_50e3:
	/* 0x50e3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50ea:
	/* 0x50ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50ef:
	/* 0x50ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f1:
	/* 0x50f1: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_50f6:
	/* 0x50f6: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_50ff:
	/* 0x50ff: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5102:
	/* 0x5102: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_510b:
	/* 0x510b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5114:
	/* 0x5114: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5118:
	/* 0x5118: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_511d:
	/* 0x511d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5122:
	/* 0x5122: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5127:
	/* 0x5127: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_512c:
	/* 0x512c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512e:
	/* 0x512e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5133:
	/* 0x5133: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_5135:
	/* 0x5135: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5138:
	/* 0x5138: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_513e:
	/* 0x513e: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5142:
	/* 0x5142: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5148:
	/* 0x5148: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_514c:
	/* 0x514c: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5152:
	/* 0x5152: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5156:
	/* 0x5156: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_515d:
	/* 0x515d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5162:
	/* 0x5162: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5167:
	/* 0x5167: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5170:
	/* 0x5170: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5174:
	/* 0x5174: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_517b:
	/* 0x517b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5180:
	/* 0x5180: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5185:
	/* 0x5185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5187:
	/* 0x5187: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_518b:
	/* 0x518b: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_518d:
	/* 0x518d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_518f:
	/* 0x518f: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5195:
	/* 0x5195: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5199:
	/* 0x5199: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_519f:
	/* 0x519f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a3:
	/* 0x51a3: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_51a9:
	/* 0x51a9: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_51ad:
	/* 0x51ad: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51b4:
	/* 0x51b4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51b9:
	/* 0x51b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51be:
	/* 0x51be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51c3:
	/* 0x51c3: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51cc:
	/* 0x51cc: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_51d0:
	/* 0x51d0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51d7:
	/* 0x51d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51dc:
	/* 0x51dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51de:
	/* 0x51de: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_51e3:
	/* 0x51e3: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_51ec:
	/* 0x51ec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_51ef:
	/* 0x51ef: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_51f8:
	/* 0x51f8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5201:
	/* 0x5201: lea    rdx,[rbp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5205:
	/* 0x5205: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_520a:
	/* 0x520a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_520f:
	/* 0x520f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5214:
	/* 0x5214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5219:
	/* 0x5219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521b:
	/* 0x521b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5220:
	/* 0x5220: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_5222:
	/* 0x5222: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5225:
	/* 0x5225: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_522b:
	/* 0x522b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_522f:
	/* 0x522f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5235:
	/* 0x5235: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5239:
	/* 0x5239: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_523f:
	/* 0x523f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5243:
	/* 0x5243: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_524a:
	/* 0x524a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_524f:
	/* 0x524f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5254:
	/* 0x5254: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_525d:
	/* 0x525d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5261:
	/* 0x5261: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5268:
	/* 0x5268: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_526d:
	/* 0x526d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5272:
	/* 0x5272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5274:
	/* 0x5274: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5278:
	/* 0x5278: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_527a:
	/* 0x527a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_527c:
	/* 0x527c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5282:
	/* 0x5282: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5286:
	/* 0x5286: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_528c:
	/* 0x528c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5290:
	/* 0x5290: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5296:
	/* 0x5296: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_529a:
	/* 0x529a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52a1:
	/* 0x52a1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a6:
	/* 0x52a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52ab:
	/* 0x52ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52b0:
	/* 0x52b0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52b9:
	/* 0x52b9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_52bd:
	/* 0x52bd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52c4:
	/* 0x52c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52c9:
	/* 0x52c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52cb:
	/* 0x52cb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_52d0:
	/* 0x52d0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_52d9:
	/* 0x52d9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_52dc:
	/* 0x52dc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_52e5:
	/* 0x52e5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_52ee:
	/* 0x52ee: lea    rdx,[rbp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_52f5:
	/* 0x52f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52fa:
	/* 0x52fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52ff:
	/* 0x52ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5304:
	/* 0x5304: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5309:
	/* 0x5309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_530b:
	/* 0x530b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5310:
	/* 0x5310: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_5312:
	/* 0x5312: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5315:
	/* 0x5315: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_531b:
	/* 0x531b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_531f:
	/* 0x531f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5325:
	/* 0x5325: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5329:
	/* 0x5329: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_532f:
	/* 0x532f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5333:
	/* 0x5333: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_533a:
	/* 0x533a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_533f:
	/* 0x533f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5344:
	/* 0x5344: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_534d:
	/* 0x534d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5351:
	/* 0x5351: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5358:
	/* 0x5358: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_535d:
	/* 0x535d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5362:
	/* 0x5362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5364:
	/* 0x5364: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5368:
	/* 0x5368: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_536a:
	/* 0x536a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_536c:
	/* 0x536c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5372:
	/* 0x5372: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5376:
	/* 0x5376: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_537c:
	/* 0x537c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5380:
	/* 0x5380: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5386:
	/* 0x5386: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_538a:
	/* 0x538a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5391:
	/* 0x5391: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5396:
	/* 0x5396: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_539b:
	/* 0x539b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53a0:
	/* 0x53a0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_53a9:
	/* 0x53a9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_53ad:
	/* 0x53ad: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_53b4:
	/* 0x53b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_53b9:
	/* 0x53b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53bb:
	/* 0x53bb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_53c0:
	/* 0x53c0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_53c9:
	/* 0x53c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_53cc:
	/* 0x53cc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_53d5:
	/* 0x53d5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_53de:
	/* 0x53de: lea    rdx,[rbp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_53e5:
	/* 0x53e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53ea:
	/* 0x53ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53ef:
	/* 0x53ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53f4:
	/* 0x53f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53f9:
	/* 0x53f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53fb:
	/* 0x53fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5400:
	/* 0x5400: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_5402:
	/* 0x5402: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5405:
	/* 0x5405: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_540b:
	/* 0x540b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_540f:
	/* 0x540f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5415:
	/* 0x5415: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5419:
	/* 0x5419: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_541f:
	/* 0x541f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5423:
	/* 0x5423: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_542a:
	/* 0x542a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_542f:
	/* 0x542f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5434:
	/* 0x5434: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_543d:
	/* 0x543d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5441:
	/* 0x5441: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5448:
	/* 0x5448: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_544d:
	/* 0x544d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5452:
	/* 0x5452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5454:
	/* 0x5454: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5458:
	/* 0x5458: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_545a:
	/* 0x545a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_545c:
	/* 0x545c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5462:
	/* 0x5462: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5466:
	/* 0x5466: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_546c:
	/* 0x546c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5470:
	/* 0x5470: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5476:
	/* 0x5476: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_547a:
	/* 0x547a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5481:
	/* 0x5481: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5486:
	/* 0x5486: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_548b:
	/* 0x548b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5490:
	/* 0x5490: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5499:
	/* 0x5499: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_549d:
	/* 0x549d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_54a4:
	/* 0x54a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54a9:
	/* 0x54a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54ab:
	/* 0x54ab: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_54b0:
	/* 0x54b0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_54b9:
	/* 0x54b9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_54bc:
	/* 0x54bc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_54c5:
	/* 0x54c5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_54ce:
	/* 0x54ce: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_54d5:
	/* 0x54d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54da:
	/* 0x54da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54df:
	/* 0x54df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54e4:
	/* 0x54e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54e9:
	/* 0x54e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54eb:
	/* 0x54eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54f0:
	/* 0x54f0: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_54f2:
	/* 0x54f2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_54f5:
	/* 0x54f5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_54fb:
	/* 0x54fb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54ff:
	/* 0x54ff: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5505:
	/* 0x5505: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5509:
	/* 0x5509: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_550f:
	/* 0x550f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5513:
	/* 0x5513: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_551a:
	/* 0x551a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_551f:
	/* 0x551f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5524:
	/* 0x5524: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_552d:
	/* 0x552d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5531:
	/* 0x5531: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5538:
	/* 0x5538: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_553d:
	/* 0x553d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5542:
	/* 0x5542: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5544:
	/* 0x5544: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5548:
	/* 0x5548: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_554a:
	/* 0x554a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_554c:
	/* 0x554c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5552:
	/* 0x5552: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5556:
	/* 0x5556: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_555c:
	/* 0x555c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5560:
	/* 0x5560: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5566:
	/* 0x5566: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_556a:
	/* 0x556a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5571:
	/* 0x5571: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5576:
	/* 0x5576: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_557b:
	/* 0x557b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5580:
	/* 0x5580: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5589:
	/* 0x5589: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_558d:
	/* 0x558d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5594:
	/* 0x5594: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5599:
	/* 0x5599: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559b:
	/* 0x559b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_55a0:
	/* 0x55a0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_55a9:
	/* 0x55a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_55ac:
	/* 0x55ac: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_55b5:
	/* 0x55b5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_55be:
	/* 0x55be: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_55c5:
	/* 0x55c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55ca:
	/* 0x55ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55cf:
	/* 0x55cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55d4:
	/* 0x55d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55d9:
	/* 0x55d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55db:
	/* 0x55db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55e0:
	/* 0x55e0: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_55e2:
	/* 0x55e2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_55e5:
	/* 0x55e5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_55eb:
	/* 0x55eb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55ef:
	/* 0x55ef: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_55f5:
	/* 0x55f5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f9:
	/* 0x55f9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_55ff:
	/* 0x55ff: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5603:
	/* 0x5603: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_560a:
	/* 0x560a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_560f:
	/* 0x560f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5614:
	/* 0x5614: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_561d:
	/* 0x561d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5621:
	/* 0x5621: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5628:
	/* 0x5628: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_562d:
	/* 0x562d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5632:
	/* 0x5632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5634:
	/* 0x5634: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5638:
	/* 0x5638: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_563a:
	/* 0x563a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_563c:
	/* 0x563c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5642:
	/* 0x5642: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5646:
	/* 0x5646: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_564c:
	/* 0x564c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5650:
	/* 0x5650: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5656:
	/* 0x5656: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_565a:
	/* 0x565a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5661:
	/* 0x5661: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5666:
	/* 0x5666: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_566b:
	/* 0x566b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5670:
	/* 0x5670: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5679:
	/* 0x5679: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_567d:
	/* 0x567d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5684:
	/* 0x5684: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5689:
	/* 0x5689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_568b:
	/* 0x568b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5690:
	/* 0x5690: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5699:
	/* 0x5699: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_569c:
	/* 0x569c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_56a5:
	/* 0x56a5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_56ae:
	/* 0x56ae: lea    rdx,[rbp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_56b5:
	/* 0x56b5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56ba:
	/* 0x56ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_56bf:
	/* 0x56bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56c4:
	/* 0x56c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56c9:
	/* 0x56c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56cb:
	/* 0x56cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56d0:
	/* 0x56d0: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_56d2:
	/* 0x56d2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_56d5:
	/* 0x56d5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_56db:
	/* 0x56db: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56df:
	/* 0x56df: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_56e5:
	/* 0x56e5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e9:
	/* 0x56e9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_56ef:
	/* 0x56ef: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_56f3:
	/* 0x56f3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56fa:
	/* 0x56fa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56ff:
	/* 0x56ff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5704:
	/* 0x5704: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_570d:
	/* 0x570d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5711:
	/* 0x5711: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5718:
	/* 0x5718: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_571d:
	/* 0x571d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5722:
	/* 0x5722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5724:
	/* 0x5724: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5728:
	/* 0x5728: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_572a:
	/* 0x572a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_572c:
	/* 0x572c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5732:
	/* 0x5732: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5736:
	/* 0x5736: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_573c:
	/* 0x573c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5740:
	/* 0x5740: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5746:
	/* 0x5746: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_574a:
	/* 0x574a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5751:
	/* 0x5751: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5756:
	/* 0x5756: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_575b:
	/* 0x575b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5760:
	/* 0x5760: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5769:
	/* 0x5769: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_576d:
	/* 0x576d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5774:
	/* 0x5774: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5779:
	/* 0x5779: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_577b:
	/* 0x577b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5780:
	/* 0x5780: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5789:
	/* 0x5789: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_578c:
	/* 0x578c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5795:
	/* 0x5795: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_579e:
	/* 0x579e: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_57a5:
	/* 0x57a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57aa:
	/* 0x57aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57af:
	/* 0x57af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57b4:
	/* 0x57b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57b9:
	/* 0x57b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57bb:
	/* 0x57bb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57c0:
	/* 0x57c0: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_57c2:
	/* 0x57c2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_57c5:
	/* 0x57c5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_57cb:
	/* 0x57cb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_57cf:
	/* 0x57cf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_57d5:
	/* 0x57d5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57d9:
	/* 0x57d9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_57df:
	/* 0x57df: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_57e3:
	/* 0x57e3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_57ea:
	/* 0x57ea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_57ef:
	/* 0x57ef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_57f4:
	/* 0x57f4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_57fd:
	/* 0x57fd: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5801:
	/* 0x5801: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5808:
	/* 0x5808: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_580d:
	/* 0x580d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5812:
	/* 0x5812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5814:
	/* 0x5814: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5818:
	/* 0x5818: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
	return 22554ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22554ULL: goto x86_l_581a;
	case 22556ULL: goto x86_l_581c;
	case 22562ULL: goto x86_l_5822;
	case 22566ULL: goto x86_l_5826;
	case 22572ULL: goto x86_l_582c;
	case 22576ULL: goto x86_l_5830;
	case 22582ULL: goto x86_l_5836;
	case 22586ULL: goto x86_l_583a;
	case 22593ULL: goto x86_l_5841;
	case 22598ULL: goto x86_l_5846;
	case 22603ULL: goto x86_l_584b;
	case 22608ULL: goto x86_l_5850;
	case 22617ULL: goto x86_l_5859;
	case 22621ULL: goto x86_l_585d;
	case 22628ULL: goto x86_l_5864;
	case 22633ULL: goto x86_l_5869;
	case 22635ULL: goto x86_l_586b;
	case 22640ULL: goto x86_l_5870;
	case 22649ULL: goto x86_l_5879;
	case 22652ULL: goto x86_l_587c;
	case 22661ULL: goto x86_l_5885;
	case 22670ULL: goto x86_l_588e;
	case 22677ULL: goto x86_l_5895;
	case 22682ULL: goto x86_l_589a;
	case 22687ULL: goto x86_l_589f;
	case 22692ULL: goto x86_l_58a4;
	case 22697ULL: goto x86_l_58a9;
	case 22699ULL: goto x86_l_58ab;
	case 22704ULL: goto x86_l_58b0;
	case 22706ULL: goto x86_l_58b2;
	case 22709ULL: goto x86_l_58b5;
	case 22715ULL: goto x86_l_58bb;
	case 22719ULL: goto x86_l_58bf;
	case 22725ULL: goto x86_l_58c5;
	case 22729ULL: goto x86_l_58c9;
	case 22735ULL: goto x86_l_58cf;
	case 22739ULL: goto x86_l_58d3;
	case 22746ULL: goto x86_l_58da;
	case 22751ULL: goto x86_l_58df;
	case 22756ULL: goto x86_l_58e4;
	case 22765ULL: goto x86_l_58ed;
	case 22769ULL: goto x86_l_58f1;
	case 22776ULL: goto x86_l_58f8;
	case 22781ULL: goto x86_l_58fd;
	case 22786ULL: goto x86_l_5902;
	case 22788ULL: goto x86_l_5904;
	case 22792ULL: goto x86_l_5908;
	case 22794ULL: goto x86_l_590a;
	case 22796ULL: goto x86_l_590c;
	case 22802ULL: goto x86_l_5912;
	case 22806ULL: goto x86_l_5916;
	case 22812ULL: goto x86_l_591c;
	case 22816ULL: goto x86_l_5920;
	case 22822ULL: goto x86_l_5926;
	case 22826ULL: goto x86_l_592a;
	case 22833ULL: goto x86_l_5931;
	case 22838ULL: goto x86_l_5936;
	case 22843ULL: goto x86_l_593b;
	case 22848ULL: goto x86_l_5940;
	case 22857ULL: goto x86_l_5949;
	case 22861ULL: goto x86_l_594d;
	case 22868ULL: goto x86_l_5954;
	case 22873ULL: goto x86_l_5959;
	case 22875ULL: goto x86_l_595b;
	case 22880ULL: goto x86_l_5960;
	case 22889ULL: goto x86_l_5969;
	case 22892ULL: goto x86_l_596c;
	case 22901ULL: goto x86_l_5975;
	case 22910ULL: goto x86_l_597e;
	case 22917ULL: goto x86_l_5985;
	case 22922ULL: goto x86_l_598a;
	case 22927ULL: goto x86_l_598f;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22939ULL: goto x86_l_599b;
	case 22944ULL: goto x86_l_59a0;
	case 22946ULL: goto x86_l_59a2;
	case 22949ULL: goto x86_l_59a5;
	case 22955ULL: goto x86_l_59ab;
	case 22959ULL: goto x86_l_59af;
	case 22965ULL: goto x86_l_59b5;
	case 22969ULL: goto x86_l_59b9;
	case 22975ULL: goto x86_l_59bf;
	case 22979ULL: goto x86_l_59c3;
	case 22986ULL: goto x86_l_59ca;
	case 22991ULL: goto x86_l_59cf;
	case 22996ULL: goto x86_l_59d4;
	case 23005ULL: goto x86_l_59dd;
	case 23009ULL: goto x86_l_59e1;
	case 23016ULL: goto x86_l_59e8;
	case 23021ULL: goto x86_l_59ed;
	case 23026ULL: goto x86_l_59f2;
	case 23028ULL: goto x86_l_59f4;
	case 23032ULL: goto x86_l_59f8;
	case 23034ULL: goto x86_l_59fa;
	case 23036ULL: goto x86_l_59fc;
	case 23042ULL: goto x86_l_5a02;
	case 23046ULL: goto x86_l_5a06;
	case 23052ULL: goto x86_l_5a0c;
	case 23056ULL: goto x86_l_5a10;
	case 23062ULL: goto x86_l_5a16;
	case 23066ULL: goto x86_l_5a1a;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23083ULL: goto x86_l_5a2b;
	case 23088ULL: goto x86_l_5a30;
	case 23097ULL: goto x86_l_5a39;
	case 23101ULL: goto x86_l_5a3d;
	case 23108ULL: goto x86_l_5a44;
	case 23113ULL: goto x86_l_5a49;
	case 23115ULL: goto x86_l_5a4b;
	case 23120ULL: goto x86_l_5a50;
	case 23129ULL: goto x86_l_5a59;
	case 23132ULL: goto x86_l_5a5c;
	case 23141ULL: goto x86_l_5a65;
	case 23150ULL: goto x86_l_5a6e;
	case 23157ULL: goto x86_l_5a75;
	case 23162ULL: goto x86_l_5a7a;
	case 23167ULL: goto x86_l_5a7f;
	case 23172ULL: goto x86_l_5a84;
	case 23177ULL: goto x86_l_5a89;
	case 23179ULL: goto x86_l_5a8b;
	case 23184ULL: goto x86_l_5a90;
	case 23186ULL: goto x86_l_5a92;
	case 23189ULL: goto x86_l_5a95;
	case 23195ULL: goto x86_l_5a9b;
	case 23199ULL: goto x86_l_5a9f;
	case 23205ULL: goto x86_l_5aa5;
	case 23209ULL: goto x86_l_5aa9;
	case 23215ULL: goto x86_l_5aaf;
	case 23219ULL: goto x86_l_5ab3;
	case 23226ULL: goto x86_l_5aba;
	case 23231ULL: goto x86_l_5abf;
	case 23236ULL: goto x86_l_5ac4;
	case 23245ULL: goto x86_l_5acd;
	case 23249ULL: goto x86_l_5ad1;
	case 23256ULL: goto x86_l_5ad8;
	case 23261ULL: goto x86_l_5add;
	case 23266ULL: goto x86_l_5ae2;
	case 23268ULL: goto x86_l_5ae4;
	case 23272ULL: goto x86_l_5ae8;
	case 23274ULL: goto x86_l_5aea;
	case 23276ULL: goto x86_l_5aec;
	case 23282ULL: goto x86_l_5af2;
	case 23286ULL: goto x86_l_5af6;
	case 23292ULL: goto x86_l_5afc;
	case 23296ULL: goto x86_l_5b00;
	case 23302ULL: goto x86_l_5b06;
	case 23306ULL: goto x86_l_5b0a;
	case 23313ULL: goto x86_l_5b11;
	case 23318ULL: goto x86_l_5b16;
	case 23323ULL: goto x86_l_5b1b;
	case 23328ULL: goto x86_l_5b20;
	case 23337ULL: goto x86_l_5b29;
	case 23341ULL: goto x86_l_5b2d;
	case 23348ULL: goto x86_l_5b34;
	case 23353ULL: goto x86_l_5b39;
	case 23355ULL: goto x86_l_5b3b;
	case 23360ULL: goto x86_l_5b40;
	case 23369ULL: goto x86_l_5b49;
	case 23372ULL: goto x86_l_5b4c;
	case 23381ULL: goto x86_l_5b55;
	case 23390ULL: goto x86_l_5b5e;
	case 23397ULL: goto x86_l_5b65;
	case 23402ULL: goto x86_l_5b6a;
	case 23407ULL: goto x86_l_5b6f;
	case 23412ULL: goto x86_l_5b74;
	case 23417ULL: goto x86_l_5b79;
	case 23419ULL: goto x86_l_5b7b;
	case 23424ULL: goto x86_l_5b80;
	case 23426ULL: goto x86_l_5b82;
	case 23429ULL: goto x86_l_5b85;
	case 23435ULL: goto x86_l_5b8b;
	case 23439ULL: goto x86_l_5b8f;
	case 23445ULL: goto x86_l_5b95;
	case 23449ULL: goto x86_l_5b99;
	case 23455ULL: goto x86_l_5b9f;
	case 23459ULL: goto x86_l_5ba3;
	case 23466ULL: goto x86_l_5baa;
	case 23471ULL: goto x86_l_5baf;
	case 23476ULL: goto x86_l_5bb4;
	case 23485ULL: goto x86_l_5bbd;
	case 23489ULL: goto x86_l_5bc1;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23506ULL: goto x86_l_5bd2;
	case 23508ULL: goto x86_l_5bd4;
	case 23512ULL: goto x86_l_5bd8;
	case 23514ULL: goto x86_l_5bda;
	case 23516ULL: goto x86_l_5bdc;
	case 23522ULL: goto x86_l_5be2;
	case 23526ULL: goto x86_l_5be6;
	case 23532ULL: goto x86_l_5bec;
	case 23536ULL: goto x86_l_5bf0;
	case 23542ULL: goto x86_l_5bf6;
	case 23546ULL: goto x86_l_5bfa;
	case 23553ULL: goto x86_l_5c01;
	case 23558ULL: goto x86_l_5c06;
	case 23563ULL: goto x86_l_5c0b;
	case 23568ULL: goto x86_l_5c10;
	case 23577ULL: goto x86_l_5c19;
	case 23581ULL: goto x86_l_5c1d;
	case 23588ULL: goto x86_l_5c24;
	case 23593ULL: goto x86_l_5c29;
	case 23595ULL: goto x86_l_5c2b;
	case 23600ULL: goto x86_l_5c30;
	case 23609ULL: goto x86_l_5c39;
	case 23612ULL: goto x86_l_5c3c;
	case 23621ULL: goto x86_l_5c45;
	case 23630ULL: goto x86_l_5c4e;
	case 23637ULL: goto x86_l_5c55;
	case 23642ULL: goto x86_l_5c5a;
	case 23647ULL: goto x86_l_5c5f;
	case 23652ULL: goto x86_l_5c64;
	case 23657ULL: goto x86_l_5c69;
	case 23659ULL: goto x86_l_5c6b;
	case 23664ULL: goto x86_l_5c70;
	case 23666ULL: goto x86_l_5c72;
	case 23669ULL: goto x86_l_5c75;
	case 23675ULL: goto x86_l_5c7b;
	case 23679ULL: goto x86_l_5c7f;
	case 23685ULL: goto x86_l_5c85;
	case 23689ULL: goto x86_l_5c89;
	case 23695ULL: goto x86_l_5c8f;
	case 23699ULL: goto x86_l_5c93;
	case 23706ULL: goto x86_l_5c9a;
	case 23711ULL: goto x86_l_5c9f;
	case 23716ULL: goto x86_l_5ca4;
	case 23725ULL: goto x86_l_5cad;
	case 23729ULL: goto x86_l_5cb1;
	case 23736ULL: goto x86_l_5cb8;
	case 23741ULL: goto x86_l_5cbd;
	case 23746ULL: goto x86_l_5cc2;
	case 23748ULL: goto x86_l_5cc4;
	case 23752ULL: goto x86_l_5cc8;
	case 23754ULL: goto x86_l_5cca;
	case 23756ULL: goto x86_l_5ccc;
	case 23762ULL: goto x86_l_5cd2;
	case 23766ULL: goto x86_l_5cd6;
	case 23772ULL: goto x86_l_5cdc;
	case 23776ULL: goto x86_l_5ce0;
	case 23782ULL: goto x86_l_5ce6;
	case 23786ULL: goto x86_l_5cea;
	case 23793ULL: goto x86_l_5cf1;
	case 23798ULL: goto x86_l_5cf6;
	case 23803ULL: goto x86_l_5cfb;
	case 23808ULL: goto x86_l_5d00;
	case 23817ULL: goto x86_l_5d09;
	case 23821ULL: goto x86_l_5d0d;
	case 23828ULL: goto x86_l_5d14;
	case 23833ULL: goto x86_l_5d19;
	case 23835ULL: goto x86_l_5d1b;
	case 23840ULL: goto x86_l_5d20;
	case 23849ULL: goto x86_l_5d29;
	case 23852ULL: goto x86_l_5d2c;
	case 23861ULL: goto x86_l_5d35;
	case 23870ULL: goto x86_l_5d3e;
	case 23877ULL: goto x86_l_5d45;
	case 23882ULL: goto x86_l_5d4a;
	case 23887ULL: goto x86_l_5d4f;
	case 23892ULL: goto x86_l_5d54;
	case 23897ULL: goto x86_l_5d59;
	case 23899ULL: goto x86_l_5d5b;
	case 23904ULL: goto x86_l_5d60;
	case 23906ULL: goto x86_l_5d62;
	case 23909ULL: goto x86_l_5d65;
	case 23915ULL: goto x86_l_5d6b;
	case 23919ULL: goto x86_l_5d6f;
	case 23925ULL: goto x86_l_5d75;
	case 23929ULL: goto x86_l_5d79;
	case 23935ULL: goto x86_l_5d7f;
	case 23939ULL: goto x86_l_5d83;
	case 23946ULL: goto x86_l_5d8a;
	case 23951ULL: goto x86_l_5d8f;
	case 23956ULL: goto x86_l_5d94;
	case 23965ULL: goto x86_l_5d9d;
	case 23969ULL: goto x86_l_5da1;
	case 23976ULL: goto x86_l_5da8;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23988ULL: goto x86_l_5db4;
	case 23992ULL: goto x86_l_5db8;
	case 23994ULL: goto x86_l_5dba;
	case 23996ULL: goto x86_l_5dbc;
	case 24002ULL: goto x86_l_5dc2;
	case 24006ULL: goto x86_l_5dc6;
	case 24012ULL: goto x86_l_5dcc;
	case 24016ULL: goto x86_l_5dd0;
	case 24022ULL: goto x86_l_5dd6;
	case 24026ULL: goto x86_l_5dda;
	case 24033ULL: goto x86_l_5de1;
	case 24038ULL: goto x86_l_5de6;
	case 24043ULL: goto x86_l_5deb;
	case 24048ULL: goto x86_l_5df0;
	case 24057ULL: goto x86_l_5df9;
	case 24061ULL: goto x86_l_5dfd;
	case 24068ULL: goto x86_l_5e04;
	case 24073ULL: goto x86_l_5e09;
	case 24075ULL: goto x86_l_5e0b;
	case 24080ULL: goto x86_l_5e10;
	case 24089ULL: goto x86_l_5e19;
	case 24092ULL: goto x86_l_5e1c;
	case 24101ULL: goto x86_l_5e25;
	case 24110ULL: goto x86_l_5e2e;
	case 24117ULL: goto x86_l_5e35;
	case 24122ULL: goto x86_l_5e3a;
	case 24127ULL: goto x86_l_5e3f;
	case 24132ULL: goto x86_l_5e44;
	case 24137ULL: goto x86_l_5e49;
	case 24139ULL: goto x86_l_5e4b;
	case 24144ULL: goto x86_l_5e50;
	case 24146ULL: goto x86_l_5e52;
	case 24149ULL: goto x86_l_5e55;
	case 24155ULL: goto x86_l_5e5b;
	case 24159ULL: goto x86_l_5e5f;
	case 24165ULL: goto x86_l_5e65;
	case 24169ULL: goto x86_l_5e69;
	case 24175ULL: goto x86_l_5e6f;
	case 24179ULL: goto x86_l_5e73;
	case 24186ULL: goto x86_l_5e7a;
	case 24191ULL: goto x86_l_5e7f;
	case 24196ULL: goto x86_l_5e84;
	case 24205ULL: goto x86_l_5e8d;
	case 24209ULL: goto x86_l_5e91;
	case 24216ULL: goto x86_l_5e98;
	case 24221ULL: goto x86_l_5e9d;
	case 24226ULL: goto x86_l_5ea2;
	case 24228ULL: goto x86_l_5ea4;
	case 24232ULL: goto x86_l_5ea8;
	case 24234ULL: goto x86_l_5eaa;
	case 24236ULL: goto x86_l_5eac;
	case 24242ULL: goto x86_l_5eb2;
	case 24246ULL: goto x86_l_5eb6;
	case 24252ULL: goto x86_l_5ebc;
	case 24256ULL: goto x86_l_5ec0;
	case 24262ULL: goto x86_l_5ec6;
	case 24266ULL: goto x86_l_5eca;
	case 24273ULL: goto x86_l_5ed1;
	case 24278ULL: goto x86_l_5ed6;
	case 24283ULL: goto x86_l_5edb;
	case 24288ULL: goto x86_l_5ee0;
	case 24297ULL: goto x86_l_5ee9;
	case 24301ULL: goto x86_l_5eed;
	case 24308ULL: goto x86_l_5ef4;
	case 24313ULL: goto x86_l_5ef9;
	case 24315ULL: goto x86_l_5efb;
	case 24320ULL: goto x86_l_5f00;
	case 24329ULL: goto x86_l_5f09;
	case 24332ULL: goto x86_l_5f0c;
	case 24341ULL: goto x86_l_5f15;
	case 24350ULL: goto x86_l_5f1e;
	case 24357ULL: goto x86_l_5f25;
	case 24362ULL: goto x86_l_5f2a;
	case 24367ULL: goto x86_l_5f2f;
	case 24372ULL: goto x86_l_5f34;
	case 24377ULL: goto x86_l_5f39;
	case 24379ULL: goto x86_l_5f3b;
	case 24384ULL: goto x86_l_5f40;
	case 24386ULL: goto x86_l_5f42;
	case 24389ULL: goto x86_l_5f45;
	case 24395ULL: goto x86_l_5f4b;
	case 24399ULL: goto x86_l_5f4f;
	case 24405ULL: goto x86_l_5f55;
	case 24409ULL: goto x86_l_5f59;
	case 24415ULL: goto x86_l_5f5f;
	case 24419ULL: goto x86_l_5f63;
	case 24426ULL: goto x86_l_5f6a;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24445ULL: goto x86_l_5f7d;
	case 24449ULL: goto x86_l_5f81;
	case 24456ULL: goto x86_l_5f88;
	case 24461ULL: goto x86_l_5f8d;
	case 24466ULL: goto x86_l_5f92;
	case 24468ULL: goto x86_l_5f94;
	case 24472ULL: goto x86_l_5f98;
	case 24474ULL: goto x86_l_5f9a;
	case 24476ULL: goto x86_l_5f9c;
	case 24482ULL: goto x86_l_5fa2;
	case 24486ULL: goto x86_l_5fa6;
	case 24492ULL: goto x86_l_5fac;
	case 24496ULL: goto x86_l_5fb0;
	case 24502ULL: goto x86_l_5fb6;
	case 24506ULL: goto x86_l_5fba;
	default: return 0xffffffffffffffffULL;
	}
x86_l_581a:
	/* 0x581a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_581c:
	/* 0x581c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5822:
	/* 0x5822: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5826:
	/* 0x5826: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_582c:
	/* 0x582c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5830:
	/* 0x5830: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5836:
	/* 0x5836: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_583a:
	/* 0x583a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5841:
	/* 0x5841: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5846:
	/* 0x5846: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_584b:
	/* 0x584b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5850:
	/* 0x5850: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5859:
	/* 0x5859: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_585d:
	/* 0x585d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5864:
	/* 0x5864: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5869:
	/* 0x5869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586b:
	/* 0x586b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5870:
	/* 0x5870: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5879:
	/* 0x5879: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_587c:
	/* 0x587c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5885:
	/* 0x5885: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_588e:
	/* 0x588e: lea    rdx,[rbp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5895:
	/* 0x5895: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_589a:
	/* 0x589a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_589f:
	/* 0x589f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_58a4:
	/* 0x58a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a9:
	/* 0x58a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58ab:
	/* 0x58ab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58b0:
	/* 0x58b0: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_58b2:
	/* 0x58b2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_58b5:
	/* 0x58b5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_58bb:
	/* 0x58bb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58bf:
	/* 0x58bf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_58c5:
	/* 0x58c5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c9:
	/* 0x58c9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_58cf:
	/* 0x58cf: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_58d3:
	/* 0x58d3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_58da:
	/* 0x58da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_58df:
	/* 0x58df: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_58e4:
	/* 0x58e4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_58ed:
	/* 0x58ed: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_58f1:
	/* 0x58f1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_58f8:
	/* 0x58f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58fd:
	/* 0x58fd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5902:
	/* 0x5902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5904:
	/* 0x5904: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5908:
	/* 0x5908: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_590a:
	/* 0x590a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_590c:
	/* 0x590c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5912:
	/* 0x5912: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5916:
	/* 0x5916: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_591c:
	/* 0x591c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5920:
	/* 0x5920: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5926:
	/* 0x5926: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_592a:
	/* 0x592a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5931:
	/* 0x5931: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5936:
	/* 0x5936: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_593b:
	/* 0x593b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5940:
	/* 0x5940: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5949:
	/* 0x5949: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_594d:
	/* 0x594d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5954:
	/* 0x5954: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5959:
	/* 0x5959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595b:
	/* 0x595b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5960:
	/* 0x5960: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5969:
	/* 0x5969: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_596c:
	/* 0x596c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5975:
	/* 0x5975: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_597e:
	/* 0x597e: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_5985:
	/* 0x5985: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_598a:
	/* 0x598a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_598f:
	/* 0x598f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5994:
	/* 0x5994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5999:
	/* 0x5999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599b:
	/* 0x599b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59a0:
	/* 0x59a0: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_59a2:
	/* 0x59a2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_59a5:
	/* 0x59a5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_59ab:
	/* 0x59ab: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_59af:
	/* 0x59af: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_59b5:
	/* 0x59b5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59b9:
	/* 0x59b9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_59bf:
	/* 0x59bf: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_59c3:
	/* 0x59c3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_59ca:
	/* 0x59ca: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_59cf:
	/* 0x59cf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_59d4:
	/* 0x59d4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_59dd:
	/* 0x59dd: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_59e1:
	/* 0x59e1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_59e8:
	/* 0x59e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59ed:
	/* 0x59ed: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_59f2:
	/* 0x59f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f4:
	/* 0x59f4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59f8:
	/* 0x59f8: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_59fa:
	/* 0x59fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59fc:
	/* 0x59fc: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5a02:
	/* 0x5a02: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5a06:
	/* 0x5a06: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5a0c:
	/* 0x5a0c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a10:
	/* 0x5a10: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5a16:
	/* 0x5a16: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5a1a:
	/* 0x5a1a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5a21:
	/* 0x5a21: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a26:
	/* 0x5a26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5a2b:
	/* 0x5a2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a30:
	/* 0x5a30: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5a39:
	/* 0x5a39: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5a3d:
	/* 0x5a3d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5a44:
	/* 0x5a44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5a49:
	/* 0x5a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4b:
	/* 0x5a4b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5a50:
	/* 0x5a50: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5a59:
	/* 0x5a59: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5a5c:
	/* 0x5a5c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5a65:
	/* 0x5a65: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5a6e:
	/* 0x5a6e: lea    rdx,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5a75:
	/* 0x5a75: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a7a:
	/* 0x5a7a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a7f:
	/* 0x5a7f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a84:
	/* 0x5a84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a89:
	/* 0x5a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a8b:
	/* 0x5a8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a90:
	/* 0x5a90: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_5a92:
	/* 0x5a92: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5a95:
	/* 0x5a95: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5a9b:
	/* 0x5a9b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5a9f:
	/* 0x5a9f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5aa5:
	/* 0x5aa5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aa9:
	/* 0x5aa9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5aaf:
	/* 0x5aaf: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5ab3:
	/* 0x5ab3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5aba:
	/* 0x5aba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5abf:
	/* 0x5abf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5ac4:
	/* 0x5ac4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5acd:
	/* 0x5acd: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5ad1:
	/* 0x5ad1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5ad8:
	/* 0x5ad8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5add:
	/* 0x5add: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5ae2:
	/* 0x5ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ae4:
	/* 0x5ae4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae8:
	/* 0x5ae8: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_5aea:
	/* 0x5aea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5aec:
	/* 0x5aec: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5af2:
	/* 0x5af2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5af6:
	/* 0x5af6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5afc:
	/* 0x5afc: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b00:
	/* 0x5b00: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5b06:
	/* 0x5b06: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5b0a:
	/* 0x5b0a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5b11:
	/* 0x5b11: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b16:
	/* 0x5b16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5b1b:
	/* 0x5b1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b20:
	/* 0x5b20: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5b29:
	/* 0x5b29: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5b2d:
	/* 0x5b2d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5b34:
	/* 0x5b34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5b39:
	/* 0x5b39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b3b:
	/* 0x5b3b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5b40:
	/* 0x5b40: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5b49:
	/* 0x5b49: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5b4c:
	/* 0x5b4c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5b55:
	/* 0x5b55: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5b5e:
	/* 0x5b5e: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5b65:
	/* 0x5b65: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b6a:
	/* 0x5b6a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b6f:
	/* 0x5b6f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b74:
	/* 0x5b74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b79:
	/* 0x5b79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b7b:
	/* 0x5b7b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b80:
	/* 0x5b80: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_5b82:
	/* 0x5b82: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5b85:
	/* 0x5b85: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5b8b:
	/* 0x5b8b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5b8f:
	/* 0x5b8f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5b95:
	/* 0x5b95: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b99:
	/* 0x5b99: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5b9f:
	/* 0x5b9f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5ba3:
	/* 0x5ba3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5baa:
	/* 0x5baa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5baf:
	/* 0x5baf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5bb4:
	/* 0x5bb4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5bbd:
	/* 0x5bbd: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5bc1:
	/* 0x5bc1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5bc8:
	/* 0x5bc8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bcd:
	/* 0x5bcd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5bd2:
	/* 0x5bd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bd4:
	/* 0x5bd4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bd8:
	/* 0x5bd8: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_5bda:
	/* 0x5bda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bdc:
	/* 0x5bdc: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5be2:
	/* 0x5be2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5be6:
	/* 0x5be6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5bec:
	/* 0x5bec: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bf0:
	/* 0x5bf0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5bf6:
	/* 0x5bf6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5bfa:
	/* 0x5bfa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5c01:
	/* 0x5c01: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c06:
	/* 0x5c06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5c0b:
	/* 0x5c0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c10:
	/* 0x5c10: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5c19:
	/* 0x5c19: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5c1d:
	/* 0x5c1d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5c24:
	/* 0x5c24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5c29:
	/* 0x5c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2b:
	/* 0x5c2b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5c30:
	/* 0x5c30: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5c39:
	/* 0x5c39: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5c3c:
	/* 0x5c3c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5c45:
	/* 0x5c45: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5c4e:
	/* 0x5c4e: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5c55:
	/* 0x5c55: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c5a:
	/* 0x5c5a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c5f:
	/* 0x5c5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c64:
	/* 0x5c64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c69:
	/* 0x5c69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c6b:
	/* 0x5c6b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c70:
	/* 0x5c70: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_5c72:
	/* 0x5c72: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5c75:
	/* 0x5c75: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5c7b:
	/* 0x5c7b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5c7f:
	/* 0x5c7f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5c85:
	/* 0x5c85: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c89:
	/* 0x5c89: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5c8f:
	/* 0x5c8f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5c93:
	/* 0x5c93: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5c9a:
	/* 0x5c9a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5c9f:
	/* 0x5c9f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5ca4:
	/* 0x5ca4: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5cad:
	/* 0x5cad: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5cb1:
	/* 0x5cb1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5cb8:
	/* 0x5cb8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cbd:
	/* 0x5cbd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5cc2:
	/* 0x5cc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc4:
	/* 0x5cc4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc8:
	/* 0x5cc8: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_5cca:
	/* 0x5cca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ccc:
	/* 0x5ccc: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5cd2:
	/* 0x5cd2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5cd6:
	/* 0x5cd6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5cdc:
	/* 0x5cdc: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ce0:
	/* 0x5ce0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5ce6:
	/* 0x5ce6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5cea:
	/* 0x5cea: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5cf1:
	/* 0x5cf1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cf6:
	/* 0x5cf6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5cfb:
	/* 0x5cfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d00:
	/* 0x5d00: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5d09:
	/* 0x5d09: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5d0d:
	/* 0x5d0d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5d14:
	/* 0x5d14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5d19:
	/* 0x5d19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1b:
	/* 0x5d1b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5d20:
	/* 0x5d20: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5d29:
	/* 0x5d29: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5d2c:
	/* 0x5d2c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5d35:
	/* 0x5d35: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5d3e:
	/* 0x5d3e: lea    rdx,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5d45:
	/* 0x5d45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d4a:
	/* 0x5d4a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d4f:
	/* 0x5d4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d54:
	/* 0x5d54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d59:
	/* 0x5d59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d5b:
	/* 0x5d5b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d60:
	/* 0x5d60: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_5d62:
	/* 0x5d62: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5d65:
	/* 0x5d65: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5d6b:
	/* 0x5d6b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5d6f:
	/* 0x5d6f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5d75:
	/* 0x5d75: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d79:
	/* 0x5d79: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5d7f:
	/* 0x5d7f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5d83:
	/* 0x5d83: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5d8a:
	/* 0x5d8a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5d8f:
	/* 0x5d8f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5d94:
	/* 0x5d94: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5d9d:
	/* 0x5d9d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5da1:
	/* 0x5da1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5da8:
	/* 0x5da8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dad:
	/* 0x5dad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5db2:
	/* 0x5db2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5db4:
	/* 0x5db4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db8:
	/* 0x5db8: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_5dba:
	/* 0x5dba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dbc:
	/* 0x5dbc: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5dc2:
	/* 0x5dc2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5dc6:
	/* 0x5dc6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5dcc:
	/* 0x5dcc: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dd0:
	/* 0x5dd0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5dd6:
	/* 0x5dd6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5dda:
	/* 0x5dda: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5de1:
	/* 0x5de1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de6:
	/* 0x5de6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5deb:
	/* 0x5deb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5df0:
	/* 0x5df0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5df9:
	/* 0x5df9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5dfd:
	/* 0x5dfd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5e04:
	/* 0x5e04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5e09:
	/* 0x5e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e0b:
	/* 0x5e0b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5e10:
	/* 0x5e10: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5e19:
	/* 0x5e19: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5e1c:
	/* 0x5e1c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5e25:
	/* 0x5e25: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e2e:
	/* 0x5e2e: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_5e35:
	/* 0x5e35: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e3a:
	/* 0x5e3a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e3f:
	/* 0x5e3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e44:
	/* 0x5e44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e49:
	/* 0x5e49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e4b:
	/* 0x5e4b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e50:
	/* 0x5e50: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_5e52:
	/* 0x5e52: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5e55:
	/* 0x5e55: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5e5b:
	/* 0x5e5b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5e5f:
	/* 0x5e5f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5e65:
	/* 0x5e65: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e69:
	/* 0x5e69: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5e6f:
	/* 0x5e6f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5e73:
	/* 0x5e73: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5e7a:
	/* 0x5e7a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5e7f:
	/* 0x5e7f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5e84:
	/* 0x5e84: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5e8d:
	/* 0x5e8d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5e91:
	/* 0x5e91: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5e98:
	/* 0x5e98: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e9d:
	/* 0x5e9d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5ea2:
	/* 0x5ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ea4:
	/* 0x5ea4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ea8:
	/* 0x5ea8: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_5eaa:
	/* 0x5eaa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5eac:
	/* 0x5eac: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5eb2:
	/* 0x5eb2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5eb6:
	/* 0x5eb6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5ebc:
	/* 0x5ebc: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ec0:
	/* 0x5ec0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5ec6:
	/* 0x5ec6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5eca:
	/* 0x5eca: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5ed1:
	/* 0x5ed1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ed6:
	/* 0x5ed6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5edb:
	/* 0x5edb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5ee0:
	/* 0x5ee0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5ee9:
	/* 0x5ee9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5eed:
	/* 0x5eed: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5ef4:
	/* 0x5ef4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5ef9:
	/* 0x5ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5efb:
	/* 0x5efb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5f00:
	/* 0x5f00: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5f09:
	/* 0x5f09: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5f0c:
	/* 0x5f0c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5f15:
	/* 0x5f15: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5f1e:
	/* 0x5f1e: lea    rdx,[rbp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5f25:
	/* 0x5f25: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f2a:
	/* 0x5f2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f2f:
	/* 0x5f2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f34:
	/* 0x5f34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f39:
	/* 0x5f39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f3b:
	/* 0x5f3b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f40:
	/* 0x5f40: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5f42:
	/* 0x5f42: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5f45:
	/* 0x5f45: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_5f4b:
	/* 0x5f4b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5f4f:
	/* 0x5f4f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5f55:
	/* 0x5f55: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f59:
	/* 0x5f59: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5f5f:
	/* 0x5f5f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5f63:
	/* 0x5f63: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5f6a:
	/* 0x5f6a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5f6f:
	/* 0x5f6f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5f74:
	/* 0x5f74: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5f7d:
	/* 0x5f7d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_5f81:
	/* 0x5f81: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5f88:
	/* 0x5f88: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f8d:
	/* 0x5f8d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5f92:
	/* 0x5f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f94:
	/* 0x5f94: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f98:
	/* 0x5f98: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5f9a:
	/* 0x5f9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f9c:
	/* 0x5f9c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_5fa2:
	/* 0x5fa2: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5fa6:
	/* 0x5fa6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5fac:
	/* 0x5fac: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fb0:
	/* 0x5fb0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_5fb6:
	/* 0x5fb6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5fba:
	/* 0x5fba: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
	return 24513ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24513ULL: goto x86_l_5fc1;
	case 24518ULL: goto x86_l_5fc6;
	case 24523ULL: goto x86_l_5fcb;
	case 24528ULL: goto x86_l_5fd0;
	case 24537ULL: goto x86_l_5fd9;
	case 24541ULL: goto x86_l_5fdd;
	case 24548ULL: goto x86_l_5fe4;
	case 24553ULL: goto x86_l_5fe9;
	case 24555ULL: goto x86_l_5feb;
	case 24560ULL: goto x86_l_5ff0;
	case 24569ULL: goto x86_l_5ff9;
	case 24572ULL: goto x86_l_5ffc;
	case 24581ULL: goto x86_l_6005;
	case 24590ULL: goto x86_l_600e;
	case 24597ULL: goto x86_l_6015;
	case 24602ULL: goto x86_l_601a;
	case 24607ULL: goto x86_l_601f;
	case 24612ULL: goto x86_l_6024;
	case 24617ULL: goto x86_l_6029;
	case 24619ULL: goto x86_l_602b;
	case 24624ULL: goto x86_l_6030;
	case 24626ULL: goto x86_l_6032;
	case 24629ULL: goto x86_l_6035;
	case 24635ULL: goto x86_l_603b;
	case 24639ULL: goto x86_l_603f;
	case 24645ULL: goto x86_l_6045;
	case 24649ULL: goto x86_l_6049;
	case 24655ULL: goto x86_l_604f;
	case 24659ULL: goto x86_l_6053;
	case 24666ULL: goto x86_l_605a;
	case 24671ULL: goto x86_l_605f;
	case 24676ULL: goto x86_l_6064;
	case 24685ULL: goto x86_l_606d;
	case 24689ULL: goto x86_l_6071;
	case 24696ULL: goto x86_l_6078;
	case 24701ULL: goto x86_l_607d;
	case 24706ULL: goto x86_l_6082;
	case 24708ULL: goto x86_l_6084;
	case 24712ULL: goto x86_l_6088;
	case 24714ULL: goto x86_l_608a;
	case 24716ULL: goto x86_l_608c;
	case 24722ULL: goto x86_l_6092;
	case 24726ULL: goto x86_l_6096;
	case 24732ULL: goto x86_l_609c;
	case 24736ULL: goto x86_l_60a0;
	case 24742ULL: goto x86_l_60a6;
	case 24746ULL: goto x86_l_60aa;
	case 24753ULL: goto x86_l_60b1;
	case 24758ULL: goto x86_l_60b6;
	case 24763ULL: goto x86_l_60bb;
	case 24768ULL: goto x86_l_60c0;
	case 24777ULL: goto x86_l_60c9;
	case 24781ULL: goto x86_l_60cd;
	case 24788ULL: goto x86_l_60d4;
	case 24793ULL: goto x86_l_60d9;
	case 24795ULL: goto x86_l_60db;
	case 24800ULL: goto x86_l_60e0;
	case 24809ULL: goto x86_l_60e9;
	case 24812ULL: goto x86_l_60ec;
	case 24821ULL: goto x86_l_60f5;
	case 24830ULL: goto x86_l_60fe;
	case 24837ULL: goto x86_l_6105;
	case 24842ULL: goto x86_l_610a;
	case 24847ULL: goto x86_l_610f;
	case 24852ULL: goto x86_l_6114;
	case 24857ULL: goto x86_l_6119;
	case 24859ULL: goto x86_l_611b;
	case 24864ULL: goto x86_l_6120;
	case 24866ULL: goto x86_l_6122;
	case 24869ULL: goto x86_l_6125;
	case 24875ULL: goto x86_l_612b;
	case 24879ULL: goto x86_l_612f;
	case 24885ULL: goto x86_l_6135;
	case 24889ULL: goto x86_l_6139;
	case 24895ULL: goto x86_l_613f;
	case 24899ULL: goto x86_l_6143;
	case 24906ULL: goto x86_l_614a;
	case 24911ULL: goto x86_l_614f;
	case 24916ULL: goto x86_l_6154;
	case 24925ULL: goto x86_l_615d;
	case 24929ULL: goto x86_l_6161;
	case 24936ULL: goto x86_l_6168;
	case 24941ULL: goto x86_l_616d;
	case 24946ULL: goto x86_l_6172;
	case 24948ULL: goto x86_l_6174;
	case 24952ULL: goto x86_l_6178;
	case 24954ULL: goto x86_l_617a;
	case 24956ULL: goto x86_l_617c;
	case 24962ULL: goto x86_l_6182;
	case 24966ULL: goto x86_l_6186;
	case 24972ULL: goto x86_l_618c;
	case 24976ULL: goto x86_l_6190;
	case 24982ULL: goto x86_l_6196;
	case 24986ULL: goto x86_l_619a;
	case 24993ULL: goto x86_l_61a1;
	case 24998ULL: goto x86_l_61a6;
	case 25003ULL: goto x86_l_61ab;
	case 25008ULL: goto x86_l_61b0;
	case 25017ULL: goto x86_l_61b9;
	case 25021ULL: goto x86_l_61bd;
	case 25028ULL: goto x86_l_61c4;
	case 25033ULL: goto x86_l_61c9;
	case 25035ULL: goto x86_l_61cb;
	case 25040ULL: goto x86_l_61d0;
	case 25049ULL: goto x86_l_61d9;
	case 25052ULL: goto x86_l_61dc;
	case 25061ULL: goto x86_l_61e5;
	case 25070ULL: goto x86_l_61ee;
	case 25077ULL: goto x86_l_61f5;
	case 25082ULL: goto x86_l_61fa;
	case 25087ULL: goto x86_l_61ff;
	case 25092ULL: goto x86_l_6204;
	case 25097ULL: goto x86_l_6209;
	case 25099ULL: goto x86_l_620b;
	case 25104ULL: goto x86_l_6210;
	case 25106ULL: goto x86_l_6212;
	case 25109ULL: goto x86_l_6215;
	case 25115ULL: goto x86_l_621b;
	case 25119ULL: goto x86_l_621f;
	case 25125ULL: goto x86_l_6225;
	case 25129ULL: goto x86_l_6229;
	case 25135ULL: goto x86_l_622f;
	case 25139ULL: goto x86_l_6233;
	case 25146ULL: goto x86_l_623a;
	case 25151ULL: goto x86_l_623f;
	case 25156ULL: goto x86_l_6244;
	case 25165ULL: goto x86_l_624d;
	case 25169ULL: goto x86_l_6251;
	case 25176ULL: goto x86_l_6258;
	case 25181ULL: goto x86_l_625d;
	case 25186ULL: goto x86_l_6262;
	case 25188ULL: goto x86_l_6264;
	case 25192ULL: goto x86_l_6268;
	case 25194ULL: goto x86_l_626a;
	case 25196ULL: goto x86_l_626c;
	case 25202ULL: goto x86_l_6272;
	case 25206ULL: goto x86_l_6276;
	case 25212ULL: goto x86_l_627c;
	case 25216ULL: goto x86_l_6280;
	case 25222ULL: goto x86_l_6286;
	case 25226ULL: goto x86_l_628a;
	case 25233ULL: goto x86_l_6291;
	case 25238ULL: goto x86_l_6296;
	case 25243ULL: goto x86_l_629b;
	case 25248ULL: goto x86_l_62a0;
	case 25257ULL: goto x86_l_62a9;
	case 25261ULL: goto x86_l_62ad;
	case 25268ULL: goto x86_l_62b4;
	case 25273ULL: goto x86_l_62b9;
	case 25275ULL: goto x86_l_62bb;
	case 25280ULL: goto x86_l_62c0;
	case 25289ULL: goto x86_l_62c9;
	case 25292ULL: goto x86_l_62cc;
	case 25301ULL: goto x86_l_62d5;
	case 25310ULL: goto x86_l_62de;
	case 25317ULL: goto x86_l_62e5;
	case 25322ULL: goto x86_l_62ea;
	case 25327ULL: goto x86_l_62ef;
	case 25332ULL: goto x86_l_62f4;
	case 25337ULL: goto x86_l_62f9;
	case 25339ULL: goto x86_l_62fb;
	case 25344ULL: goto x86_l_6300;
	case 25346ULL: goto x86_l_6302;
	case 25349ULL: goto x86_l_6305;
	case 25355ULL: goto x86_l_630b;
	case 25359ULL: goto x86_l_630f;
	case 25365ULL: goto x86_l_6315;
	case 25369ULL: goto x86_l_6319;
	case 25375ULL: goto x86_l_631f;
	case 25379ULL: goto x86_l_6323;
	case 25386ULL: goto x86_l_632a;
	case 25391ULL: goto x86_l_632f;
	case 25396ULL: goto x86_l_6334;
	case 25405ULL: goto x86_l_633d;
	case 25409ULL: goto x86_l_6341;
	case 25416ULL: goto x86_l_6348;
	case 25421ULL: goto x86_l_634d;
	case 25426ULL: goto x86_l_6352;
	case 25428ULL: goto x86_l_6354;
	case 25432ULL: goto x86_l_6358;
	case 25434ULL: goto x86_l_635a;
	case 25436ULL: goto x86_l_635c;
	case 25442ULL: goto x86_l_6362;
	case 25446ULL: goto x86_l_6366;
	case 25452ULL: goto x86_l_636c;
	case 25456ULL: goto x86_l_6370;
	case 25462ULL: goto x86_l_6376;
	case 25466ULL: goto x86_l_637a;
	case 25473ULL: goto x86_l_6381;
	case 25478ULL: goto x86_l_6386;
	case 25483ULL: goto x86_l_638b;
	case 25488ULL: goto x86_l_6390;
	case 25497ULL: goto x86_l_6399;
	case 25501ULL: goto x86_l_639d;
	case 25508ULL: goto x86_l_63a4;
	case 25513ULL: goto x86_l_63a9;
	case 25515ULL: goto x86_l_63ab;
	case 25520ULL: goto x86_l_63b0;
	case 25529ULL: goto x86_l_63b9;
	case 25532ULL: goto x86_l_63bc;
	case 25541ULL: goto x86_l_63c5;
	case 25550ULL: goto x86_l_63ce;
	case 25557ULL: goto x86_l_63d5;
	case 25562ULL: goto x86_l_63da;
	case 25567ULL: goto x86_l_63df;
	case 25572ULL: goto x86_l_63e4;
	case 25577ULL: goto x86_l_63e9;
	case 25579ULL: goto x86_l_63eb;
	case 25584ULL: goto x86_l_63f0;
	case 25586ULL: goto x86_l_63f2;
	case 25589ULL: goto x86_l_63f5;
	case 25595ULL: goto x86_l_63fb;
	case 25599ULL: goto x86_l_63ff;
	case 25605ULL: goto x86_l_6405;
	case 25609ULL: goto x86_l_6409;
	case 25615ULL: goto x86_l_640f;
	case 25619ULL: goto x86_l_6413;
	case 25626ULL: goto x86_l_641a;
	case 25631ULL: goto x86_l_641f;
	case 25636ULL: goto x86_l_6424;
	case 25645ULL: goto x86_l_642d;
	case 25649ULL: goto x86_l_6431;
	case 25656ULL: goto x86_l_6438;
	case 25661ULL: goto x86_l_643d;
	case 25666ULL: goto x86_l_6442;
	case 25668ULL: goto x86_l_6444;
	case 25672ULL: goto x86_l_6448;
	case 25674ULL: goto x86_l_644a;
	case 25676ULL: goto x86_l_644c;
	case 25682ULL: goto x86_l_6452;
	case 25686ULL: goto x86_l_6456;
	case 25692ULL: goto x86_l_645c;
	case 25696ULL: goto x86_l_6460;
	case 25702ULL: goto x86_l_6466;
	case 25706ULL: goto x86_l_646a;
	case 25713ULL: goto x86_l_6471;
	case 25718ULL: goto x86_l_6476;
	case 25723ULL: goto x86_l_647b;
	case 25728ULL: goto x86_l_6480;
	case 25737ULL: goto x86_l_6489;
	case 25741ULL: goto x86_l_648d;
	case 25748ULL: goto x86_l_6494;
	case 25753ULL: goto x86_l_6499;
	case 25755ULL: goto x86_l_649b;
	case 25760ULL: goto x86_l_64a0;
	case 25769ULL: goto x86_l_64a9;
	case 25772ULL: goto x86_l_64ac;
	case 25781ULL: goto x86_l_64b5;
	case 25790ULL: goto x86_l_64be;
	case 25797ULL: goto x86_l_64c5;
	case 25802ULL: goto x86_l_64ca;
	case 25807ULL: goto x86_l_64cf;
	case 25812ULL: goto x86_l_64d4;
	case 25817ULL: goto x86_l_64d9;
	case 25819ULL: goto x86_l_64db;
	case 25824ULL: goto x86_l_64e0;
	case 25826ULL: goto x86_l_64e2;
	case 25829ULL: goto x86_l_64e5;
	case 25835ULL: goto x86_l_64eb;
	case 25839ULL: goto x86_l_64ef;
	case 25845ULL: goto x86_l_64f5;
	case 25849ULL: goto x86_l_64f9;
	case 25855ULL: goto x86_l_64ff;
	case 25859ULL: goto x86_l_6503;
	case 25866ULL: goto x86_l_650a;
	case 25871ULL: goto x86_l_650f;
	case 25876ULL: goto x86_l_6514;
	case 25885ULL: goto x86_l_651d;
	case 25889ULL: goto x86_l_6521;
	case 25896ULL: goto x86_l_6528;
	case 25901ULL: goto x86_l_652d;
	case 25906ULL: goto x86_l_6532;
	case 25908ULL: goto x86_l_6534;
	case 25912ULL: goto x86_l_6538;
	case 25914ULL: goto x86_l_653a;
	case 25916ULL: goto x86_l_653c;
	case 25922ULL: goto x86_l_6542;
	case 25926ULL: goto x86_l_6546;
	case 25932ULL: goto x86_l_654c;
	case 25936ULL: goto x86_l_6550;
	case 25942ULL: goto x86_l_6556;
	case 25946ULL: goto x86_l_655a;
	case 25953ULL: goto x86_l_6561;
	case 25958ULL: goto x86_l_6566;
	case 25963ULL: goto x86_l_656b;
	case 25968ULL: goto x86_l_6570;
	case 25977ULL: goto x86_l_6579;
	case 25981ULL: goto x86_l_657d;
	case 25988ULL: goto x86_l_6584;
	case 25993ULL: goto x86_l_6589;
	case 25995ULL: goto x86_l_658b;
	case 26000ULL: goto x86_l_6590;
	case 26009ULL: goto x86_l_6599;
	case 26012ULL: goto x86_l_659c;
	case 26021ULL: goto x86_l_65a5;
	case 26030ULL: goto x86_l_65ae;
	case 26037ULL: goto x86_l_65b5;
	case 26042ULL: goto x86_l_65ba;
	case 26047ULL: goto x86_l_65bf;
	case 26052ULL: goto x86_l_65c4;
	case 26057ULL: goto x86_l_65c9;
	case 26059ULL: goto x86_l_65cb;
	case 26064ULL: goto x86_l_65d0;
	case 26066ULL: goto x86_l_65d2;
	case 26069ULL: goto x86_l_65d5;
	case 26075ULL: goto x86_l_65db;
	case 26079ULL: goto x86_l_65df;
	case 26085ULL: goto x86_l_65e5;
	case 26089ULL: goto x86_l_65e9;
	case 26095ULL: goto x86_l_65ef;
	case 26099ULL: goto x86_l_65f3;
	case 26106ULL: goto x86_l_65fa;
	case 26111ULL: goto x86_l_65ff;
	case 26116ULL: goto x86_l_6604;
	case 26125ULL: goto x86_l_660d;
	case 26129ULL: goto x86_l_6611;
	case 26136ULL: goto x86_l_6618;
	case 26141ULL: goto x86_l_661d;
	case 26146ULL: goto x86_l_6622;
	case 26148ULL: goto x86_l_6624;
	case 26152ULL: goto x86_l_6628;
	case 26154ULL: goto x86_l_662a;
	case 26156ULL: goto x86_l_662c;
	case 26162ULL: goto x86_l_6632;
	case 26166ULL: goto x86_l_6636;
	case 26172ULL: goto x86_l_663c;
	case 26176ULL: goto x86_l_6640;
	case 26182ULL: goto x86_l_6646;
	case 26186ULL: goto x86_l_664a;
	case 26193ULL: goto x86_l_6651;
	case 26198ULL: goto x86_l_6656;
	case 26203ULL: goto x86_l_665b;
	case 26208ULL: goto x86_l_6660;
	case 26217ULL: goto x86_l_6669;
	case 26221ULL: goto x86_l_666d;
	case 26228ULL: goto x86_l_6674;
	case 26233ULL: goto x86_l_6679;
	case 26235ULL: goto x86_l_667b;
	case 26240ULL: goto x86_l_6680;
	case 26249ULL: goto x86_l_6689;
	case 26252ULL: goto x86_l_668c;
	case 26261ULL: goto x86_l_6695;
	case 26270ULL: goto x86_l_669e;
	case 26277ULL: goto x86_l_66a5;
	case 26282ULL: goto x86_l_66aa;
	case 26287ULL: goto x86_l_66af;
	case 26292ULL: goto x86_l_66b4;
	case 26297ULL: goto x86_l_66b9;
	case 26300ULL: goto x86_l_66bc;
	case 26302ULL: goto x86_l_66be;
	case 26307ULL: goto x86_l_66c3;
	case 26309ULL: goto x86_l_66c5;
	case 26312ULL: goto x86_l_66c8;
	case 26318ULL: goto x86_l_66ce;
	case 26322ULL: goto x86_l_66d2;
	case 26328ULL: goto x86_l_66d8;
	case 26332ULL: goto x86_l_66dc;
	case 26338ULL: goto x86_l_66e2;
	case 26342ULL: goto x86_l_66e6;
	case 26349ULL: goto x86_l_66ed;
	case 26354ULL: goto x86_l_66f2;
	case 26359ULL: goto x86_l_66f7;
	case 26368ULL: goto x86_l_6700;
	case 26372ULL: goto x86_l_6704;
	case 26379ULL: goto x86_l_670b;
	case 26384ULL: goto x86_l_6710;
	case 26389ULL: goto x86_l_6715;
	case 26391ULL: goto x86_l_6717;
	case 26395ULL: goto x86_l_671b;
	case 26397ULL: goto x86_l_671d;
	case 26399ULL: goto x86_l_671f;
	case 26405ULL: goto x86_l_6725;
	case 26409ULL: goto x86_l_6729;
	case 26415ULL: goto x86_l_672f;
	case 26419ULL: goto x86_l_6733;
	case 26425ULL: goto x86_l_6739;
	case 26429ULL: goto x86_l_673d;
	case 26436ULL: goto x86_l_6744;
	case 26441ULL: goto x86_l_6749;
	case 26446ULL: goto x86_l_674e;
	case 26451ULL: goto x86_l_6753;
	case 26460ULL: goto x86_l_675c;
	case 26464ULL: goto x86_l_6760;
	case 26471ULL: goto x86_l_6767;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5fc1:
	/* 0x5fc1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fc6:
	/* 0x5fc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5fcb:
	/* 0x5fcb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5fd0:
	/* 0x5fd0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5fd9:
	/* 0x5fd9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5fdd:
	/* 0x5fdd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5fe4:
	/* 0x5fe4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5fe9:
	/* 0x5fe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5feb:
	/* 0x5feb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5ff0:
	/* 0x5ff0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5ff9:
	/* 0x5ff9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5ffc:
	/* 0x5ffc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_6005:
	/* 0x6005: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_600e:
	/* 0x600e: lea    rdx,[rbp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6015:
	/* 0x6015: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_601a:
	/* 0x601a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_601f:
	/* 0x601f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6024:
	/* 0x6024: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6029:
	/* 0x6029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602b:
	/* 0x602b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6030:
	/* 0x6030: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_6032:
	/* 0x6032: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6035:
	/* 0x6035: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_603b:
	/* 0x603b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_603f:
	/* 0x603f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_6045:
	/* 0x6045: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6049:
	/* 0x6049: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_604f:
	/* 0x604f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6053:
	/* 0x6053: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_605a:
	/* 0x605a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_605f:
	/* 0x605f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6064:
	/* 0x6064: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_606d:
	/* 0x606d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6071:
	/* 0x6071: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6078:
	/* 0x6078: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_607d:
	/* 0x607d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6082:
	/* 0x6082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6084:
	/* 0x6084: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6088:
	/* 0x6088: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_608a:
	/* 0x608a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_608c:
	/* 0x608c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6092:
	/* 0x6092: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6096:
	/* 0x6096: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_609c:
	/* 0x609c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60a0:
	/* 0x60a0: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_60a6:
	/* 0x60a6: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_60aa:
	/* 0x60aa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_60b1:
	/* 0x60b1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60b6:
	/* 0x60b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_60bb:
	/* 0x60bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_60c0:
	/* 0x60c0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_60c9:
	/* 0x60c9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_60cd:
	/* 0x60cd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_60d4:
	/* 0x60d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_60d9:
	/* 0x60d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60db:
	/* 0x60db: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_60e0:
	/* 0x60e0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_60e9:
	/* 0x60e9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_60ec:
	/* 0x60ec: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_60f5:
	/* 0x60f5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_60fe:
	/* 0x60fe: lea    rdx,[rbp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_6105:
	/* 0x6105: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610a:
	/* 0x610a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_610f:
	/* 0x610f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6114:
	/* 0x6114: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6119:
	/* 0x6119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611b:
	/* 0x611b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6120:
	/* 0x6120: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_6122:
	/* 0x6122: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6125:
	/* 0x6125: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_612b:
	/* 0x612b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_612f:
	/* 0x612f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_6135:
	/* 0x6135: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6139:
	/* 0x6139: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_613f:
	/* 0x613f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6143:
	/* 0x6143: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_614a:
	/* 0x614a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_614f:
	/* 0x614f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6154:
	/* 0x6154: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_615d:
	/* 0x615d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6161:
	/* 0x6161: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6168:
	/* 0x6168: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_616d:
	/* 0x616d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6172:
	/* 0x6172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6174:
	/* 0x6174: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6178:
	/* 0x6178: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_617a:
	/* 0x617a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_617c:
	/* 0x617c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6182:
	/* 0x6182: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6186:
	/* 0x6186: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_618c:
	/* 0x618c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6190:
	/* 0x6190: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6196:
	/* 0x6196: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_619a:
	/* 0x619a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_61a1:
	/* 0x61a1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61a6:
	/* 0x61a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_61ab:
	/* 0x61ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_61b0:
	/* 0x61b0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_61b9:
	/* 0x61b9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_61bd:
	/* 0x61bd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_61c4:
	/* 0x61c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_61c9:
	/* 0x61c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61cb:
	/* 0x61cb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_61d0:
	/* 0x61d0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_61d9:
	/* 0x61d9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_61dc:
	/* 0x61dc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_61e5:
	/* 0x61e5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_61ee:
	/* 0x61ee: lea    rdx,[rbp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_61f5:
	/* 0x61f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61fa:
	/* 0x61fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61ff:
	/* 0x61ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6204:
	/* 0x6204: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6209:
	/* 0x6209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_620b:
	/* 0x620b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6210:
	/* 0x6210: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_6212:
	/* 0x6212: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6215:
	/* 0x6215: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_621b:
	/* 0x621b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_621f:
	/* 0x621f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_6225:
	/* 0x6225: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6229:
	/* 0x6229: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_622f:
	/* 0x622f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6233:
	/* 0x6233: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_623a:
	/* 0x623a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_623f:
	/* 0x623f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6244:
	/* 0x6244: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_624d:
	/* 0x624d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6251:
	/* 0x6251: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6258:
	/* 0x6258: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_625d:
	/* 0x625d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6262:
	/* 0x6262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6264:
	/* 0x6264: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6268:
	/* 0x6268: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_626a:
	/* 0x626a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_626c:
	/* 0x626c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6272:
	/* 0x6272: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6276:
	/* 0x6276: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_627c:
	/* 0x627c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6280:
	/* 0x6280: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6286:
	/* 0x6286: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_628a:
	/* 0x628a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6291:
	/* 0x6291: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6296:
	/* 0x6296: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_629b:
	/* 0x629b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62a0:
	/* 0x62a0: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_62a9:
	/* 0x62a9: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_62ad:
	/* 0x62ad: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_62b4:
	/* 0x62b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_62b9:
	/* 0x62b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62bb:
	/* 0x62bb: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_62c0:
	/* 0x62c0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_62c9:
	/* 0x62c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_62cc:
	/* 0x62cc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_62d5:
	/* 0x62d5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_62de:
	/* 0x62de: lea    rdx,[rbp+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_62e5:
	/* 0x62e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62ea:
	/* 0x62ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_62ef:
	/* 0x62ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62f4:
	/* 0x62f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62f9:
	/* 0x62f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62fb:
	/* 0x62fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6300:
	/* 0x6300: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_6302:
	/* 0x6302: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6305:
	/* 0x6305: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_630b:
	/* 0x630b: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_630f:
	/* 0x630f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_6315:
	/* 0x6315: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6319:
	/* 0x6319: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_631f:
	/* 0x631f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6323:
	/* 0x6323: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_632a:
	/* 0x632a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_632f:
	/* 0x632f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6334:
	/* 0x6334: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_633d:
	/* 0x633d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6341:
	/* 0x6341: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6348:
	/* 0x6348: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_634d:
	/* 0x634d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6352:
	/* 0x6352: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6354:
	/* 0x6354: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6358:
	/* 0x6358: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_635a:
	/* 0x635a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_635c:
	/* 0x635c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6362:
	/* 0x6362: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6366:
	/* 0x6366: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_636c:
	/* 0x636c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6370:
	/* 0x6370: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6376:
	/* 0x6376: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_637a:
	/* 0x637a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6381:
	/* 0x6381: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6386:
	/* 0x6386: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_638b:
	/* 0x638b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6390:
	/* 0x6390: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6399:
	/* 0x6399: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_639d:
	/* 0x639d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_63a4:
	/* 0x63a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_63a9:
	/* 0x63a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63ab:
	/* 0x63ab: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_63b0:
	/* 0x63b0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_63b9:
	/* 0x63b9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_63bc:
	/* 0x63bc: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_63c5:
	/* 0x63c5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_63ce:
	/* 0x63ce: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_63d5:
	/* 0x63d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63da:
	/* 0x63da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63df:
	/* 0x63df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63e4:
	/* 0x63e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63e9:
	/* 0x63e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63eb:
	/* 0x63eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63f0:
	/* 0x63f0: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_63f2:
	/* 0x63f2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_63f5:
	/* 0x63f5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_63fb:
	/* 0x63fb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_63ff:
	/* 0x63ff: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_6405:
	/* 0x6405: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6409:
	/* 0x6409: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_640f:
	/* 0x640f: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6413:
	/* 0x6413: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_641a:
	/* 0x641a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_641f:
	/* 0x641f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6424:
	/* 0x6424: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_642d:
	/* 0x642d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6431:
	/* 0x6431: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6438:
	/* 0x6438: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_643d:
	/* 0x643d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6442:
	/* 0x6442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6444:
	/* 0x6444: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6448:
	/* 0x6448: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_644a:
	/* 0x644a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_644c:
	/* 0x644c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6452:
	/* 0x6452: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6456:
	/* 0x6456: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_645c:
	/* 0x645c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6460:
	/* 0x6460: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6466:
	/* 0x6466: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_646a:
	/* 0x646a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6471:
	/* 0x6471: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6476:
	/* 0x6476: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_647b:
	/* 0x647b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6480:
	/* 0x6480: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6489:
	/* 0x6489: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_648d:
	/* 0x648d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6494:
	/* 0x6494: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6499:
	/* 0x6499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_649b:
	/* 0x649b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_64a0:
	/* 0x64a0: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_64a9:
	/* 0x64a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_64ac:
	/* 0x64ac: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_64b5:
	/* 0x64b5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_64be:
	/* 0x64be: lea    rdx,[rbp+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_64c5:
	/* 0x64c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64ca:
	/* 0x64ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64cf:
	/* 0x64cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64d4:
	/* 0x64d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64d9:
	/* 0x64d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64db:
	/* 0x64db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64e0:
	/* 0x64e0: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_64e2:
	/* 0x64e2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_64e5:
	/* 0x64e5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_64eb:
	/* 0x64eb: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_64ef:
	/* 0x64ef: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_64f5:
	/* 0x64f5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64f9:
	/* 0x64f9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_64ff:
	/* 0x64ff: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6503:
	/* 0x6503: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_650a:
	/* 0x650a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_650f:
	/* 0x650f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6514:
	/* 0x6514: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_651d:
	/* 0x651d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6521:
	/* 0x6521: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6528:
	/* 0x6528: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_652d:
	/* 0x652d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6532:
	/* 0x6532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6534:
	/* 0x6534: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6538:
	/* 0x6538: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_653a:
	/* 0x653a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_653c:
	/* 0x653c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6542:
	/* 0x6542: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6546:
	/* 0x6546: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_654c:
	/* 0x654c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6550:
	/* 0x6550: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6556:
	/* 0x6556: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_655a:
	/* 0x655a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6561:
	/* 0x6561: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6566:
	/* 0x6566: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_656b:
	/* 0x656b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6570:
	/* 0x6570: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6579:
	/* 0x6579: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_657d:
	/* 0x657d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6584:
	/* 0x6584: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6589:
	/* 0x6589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_658b:
	/* 0x658b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_6590:
	/* 0x6590: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_6599:
	/* 0x6599: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_659c:
	/* 0x659c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_65a5:
	/* 0x65a5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_65ae:
	/* 0x65ae: lea    rdx,[rbp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_65b5:
	/* 0x65b5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65ba:
	/* 0x65ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_65bf:
	/* 0x65bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_65c4:
	/* 0x65c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65c9:
	/* 0x65c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65cb:
	/* 0x65cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65d0:
	/* 0x65d0: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_65d2:
	/* 0x65d2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_65d5:
	/* 0x65d5: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_65db:
	/* 0x65db: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_65df:
	/* 0x65df: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_65e5:
	/* 0x65e5: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65e9:
	/* 0x65e9: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_65ef:
	/* 0x65ef: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_65f3:
	/* 0x65f3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_65fa:
	/* 0x65fa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_65ff:
	/* 0x65ff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6604:
	/* 0x6604: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_660d:
	/* 0x660d: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6611:
	/* 0x6611: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_6618:
	/* 0x6618: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_661d:
	/* 0x661d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6622:
	/* 0x6622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6624:
	/* 0x6624: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6628:
	/* 0x6628: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_662a:
	/* 0x662a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_662c:
	/* 0x662c: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6632:
	/* 0x6632: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6636:
	/* 0x6636: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_663c:
	/* 0x663c: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6640:
	/* 0x6640: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6646:
	/* 0x6646: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_664a:
	/* 0x664a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6651:
	/* 0x6651: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6656:
	/* 0x6656: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_665b:
	/* 0x665b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6660:
	/* 0x6660: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6669:
	/* 0x6669: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_666d:
	/* 0x666d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6674:
	/* 0x6674: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6679:
	/* 0x6679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_667b:
	/* 0x667b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_6680:
	/* 0x6680: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_6689:
	/* 0x6689: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_668c:
	/* 0x668c: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_6695:
	/* 0x6695: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_669e:
	/* 0x669e: add    rbp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_66a5:
	/* 0x66a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66aa:
	/* 0x66aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66af:
	/* 0x66af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_66b4:
	/* 0x66b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66b9:
	/* 0x66b9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_66bc:
	/* 0x66bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66be:
	/* 0x66be: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66c3:
	/* 0x66c3: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_66c5:
	/* 0x66c5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_66c8:
	/* 0x66c8: je     6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26773ULL;
	}
x86_l_66ce:
	/* 0x66ce: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_66d2:
	/* 0x66d2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_66d8:
	/* 0x66d8: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66dc:
	/* 0x66dc: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_66e2:
	/* 0x66e2: lea    rcx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_66e6:
	/* 0x66e6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_66ed:
	/* 0x66ed: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_66f2:
	/* 0x66f2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_66f7:
	/* 0x66f7: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6700:
	/* 0x6700: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6704:
	/* 0x6704: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_670b:
	/* 0x670b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6710:
	/* 0x6710: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6715:
	/* 0x6715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6717:
	/* 0x6717: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_671b:
	/* 0x671b: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_671d:
	/* 0x671d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_671f:
	/* 0x671f: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 26773ULL;
	}
x86_l_6725:
	/* 0x6725: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6729:
	/* 0x6729: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_672f:
	/* 0x672f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6733:
	/* 0x6733: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6739:
	/* 0x6739: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_673d:
	/* 0x673d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6744:
	/* 0x6744: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6749:
	/* 0x6749: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_674e:
	/* 0x674e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6753:
	/* 0x6753: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_675c:
	/* 0x675c: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_6760:
	/* 0x6760: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_6767:
	/* 0x6767: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 26476ULL;
}

static __noinline __u64 tracee_trace_execute_finished_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26476ULL: goto x86_l_676c;
	case 26478ULL: goto x86_l_676e;
	case 26483ULL: goto x86_l_6773;
	case 26492ULL: goto x86_l_677c;
	case 26495ULL: goto x86_l_677f;
	case 26504ULL: goto x86_l_6788;
	case 26512ULL: goto x86_l_6790;
	case 26515ULL: goto x86_l_6793;
	case 26521ULL: goto x86_l_6799;
	case 26523ULL: goto x86_l_679b;
	case 26529ULL: goto x86_l_67a1;
	case 26533ULL: goto x86_l_67a5;
	case 26536ULL: goto x86_l_67a8;
	case 26540ULL: goto x86_l_67ac;
	case 26544ULL: goto x86_l_67b0;
	case 26551ULL: goto x86_l_67b7;
	case 26556ULL: goto x86_l_67bc;
	case 26561ULL: goto x86_l_67c1;
	case 26566ULL: goto x86_l_67c6;
	case 26573ULL: goto x86_l_67cd;
	case 26576ULL: goto x86_l_67d0;
	case 26583ULL: goto x86_l_67d7;
	case 26588ULL: goto x86_l_67dc;
	case 26590ULL: goto x86_l_67de;
	case 26594ULL: goto x86_l_67e2;
	case 26596ULL: goto x86_l_67e4;
	case 26598ULL: goto x86_l_67e6;
	case 26604ULL: goto x86_l_67ec;
	case 26608ULL: goto x86_l_67f0;
	case 26614ULL: goto x86_l_67f6;
	case 26618ULL: goto x86_l_67fa;
	case 26624ULL: goto x86_l_6800;
	case 26628ULL: goto x86_l_6804;
	case 26635ULL: goto x86_l_680b;
	case 26640ULL: goto x86_l_6810;
	case 26645ULL: goto x86_l_6815;
	case 26650ULL: goto x86_l_681a;
	case 26659ULL: goto x86_l_6823;
	case 26663ULL: goto x86_l_6827;
	case 26670ULL: goto x86_l_682e;
	case 26675ULL: goto x86_l_6833;
	case 26677ULL: goto x86_l_6835;
	case 26682ULL: goto x86_l_683a;
	case 26691ULL: goto x86_l_6843;
	case 26694ULL: goto x86_l_6846;
	case 26703ULL: goto x86_l_684f;
	case 26705ULL: goto x86_l_6851;
	case 26710ULL: goto x86_l_6856;
	case 26718ULL: goto x86_l_685e;
	case 26721ULL: goto x86_l_6861;
	case 26725ULL: goto x86_l_6865;
	case 26730ULL: goto x86_l_686a;
	case 26735ULL: goto x86_l_686f;
	case 26740ULL: goto x86_l_6874;
	case 26742ULL: goto x86_l_6876;
	case 26745ULL: goto x86_l_6879;
	case 26747ULL: goto x86_l_687b;
	case 26752ULL: goto x86_l_6880;
	case 26758ULL: goto x86_l_6886;
	case 26763ULL: goto x86_l_688b;
	case 26768ULL: goto x86_l_6890;
	case 26773ULL: goto x86_l_6895;
	case 26777ULL: goto x86_l_6899;
	case 26782ULL: goto x86_l_689e;
	case 26786ULL: goto x86_l_68a2;
	case 26789ULL: goto x86_l_68a5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_676c:
	/* 0x676c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676e:
	/* 0x676e: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_6773:
	/* 0x6773: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_677c:
	/* 0x677c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_677f:
	/* 0x677f: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_6788:
	/* 0x6788: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_6790:
	/* 0x6790: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_6793:
	/* 0x6793: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_6799:
	/* 0x6799: jb     67a5 <trace_execute_finished+0x67a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_67a5;
	}
x86_l_679b:
	/* 0x679b: mov    WORD PTR [r14],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_67a1:
	/* 0x67a1: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_67a5:
	/* 0x67a5: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_67a8:
	/* 0x67a8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67ac:
	/* 0x67ac: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_67b0:
	/* 0x67b0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_67b7:
	/* 0x67b7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_67bc:
	/* 0x67bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67c1:
	/* 0x67c1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_67c6:
	/* 0x67c6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_67cd:
	/* 0x67cd: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67d0:
	/* 0x67d0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_67d7:
	/* 0x67d7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67dc:
	/* 0x67dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67de:
	/* 0x67de: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67e2:
	/* 0x67e2: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_67e4:
	/* 0x67e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_67e6:
	/* 0x67e6: jle    6895 <trace_execute_finished+0x6895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6895;
	}
x86_l_67ec:
	/* 0x67ec: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_67f0:
	/* 0x67f0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_67f6:
	/* 0x67f6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67fa:
	/* 0x67fa: ja     1a04 <trace_execute_finished+0x1a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6660ULL;
	}
x86_l_6800:
	/* 0x6800: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6804:
	/* 0x6804: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_680b:
	/* 0x680b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6810:
	/* 0x6810: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6815:
	/* 0x6815: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_681a:
	/* 0x681a: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_6823:
	/* 0x6823: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_6827:
	/* 0x6827: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_682e:
	/* 0x682e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6833:
	/* 0x6833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6835:
	/* 0x6835: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_683a:
	/* 0x683a: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_6843:
	/* 0x6843: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_6846:
	/* 0x6846: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_684f:
	/* 0x684f: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_6851:
	/* 0x6851: jmp    1a04 <trace_execute_finished+0x1a04> */
	return 6660ULL;
x86_l_6856:
	/* 0x6856: lea    rdi,[r12+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_685e:
	/* 0x685e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6861:
	/* 0x6861: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6865:
	/* 0x6865: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_686a:
	/* 0x686a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_686f:
	/* 0x686f: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_6874:
	/* 0x6874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6876:
	/* 0x6876: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6879:
	/* 0x6879: jne    688b <trace_execute_finished+0x688b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_688b;
	}
x86_l_687b:
	/* 0x687b: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_6880:
	/* 0x6880: mov    WORD PTR [r12+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_6886:
	/* 0x6886: jmp    beb <trace_execute_finished+0xbeb> */
	return 3051ULL;
x86_l_688b:
	/* 0x688b: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_6890:
	/* 0x6890: jmp    1f9e <trace_execute_finished+0x1f9e> */
	return 8094ULL;
x86_l_6895:
	/* 0x6895: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6899:
	/* 0x6899: jmp    1a04 <trace_execute_finished+0x1a04> */
	return 6660ULL;
x86_l_689e:
	/* 0x689e: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68a2:
	/* 0x68a2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_68a5:
	/* 0x68a5: jmp    1925 <trace_execute_finished+0x1925> */
	return 6437ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_execute_finished_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 21768U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2177ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2181ULL && __x86_pc <= 3876ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3881ULL && __x86_pc <= 5472ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5477ULL && __x86_pc <= 7246ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7251ULL && __x86_pc <= 9040ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9046ULL && __x86_pc <= 10950ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10954ULL && __x86_pc <= 12868ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12871ULL && __x86_pc <= 14790ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14796ULL && __x86_pc <= 16721ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16727ULL && __x86_pc <= 18659ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18665ULL && __x86_pc <= 20597ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20602ULL && __x86_pc <= 22552ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22554ULL && __x86_pc <= 24506ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 24513ULL && __x86_pc <= 26471ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 26476ULL && __x86_pc <= 26789ULL)
			__x86_pc = tracee_trace_execute_finished_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

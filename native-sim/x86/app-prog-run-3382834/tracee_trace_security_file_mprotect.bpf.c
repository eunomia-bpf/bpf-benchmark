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

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_0(
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
	case 32ULL: goto x86_l_20;
	case 44ULL: goto x86_l_2c;
	case 56ULL: goto x86_l_38;
	case 68ULL: goto x86_l_44;
	case 80ULL: goto x86_l_50;
	case 92ULL: goto x86_l_5c;
	case 104ULL: goto x86_l_68;
	case 116ULL: goto x86_l_74;
	case 128ULL: goto x86_l_80;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 143ULL: goto x86_l_8f;
	case 145ULL: goto x86_l_91;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 167ULL: goto x86_l_a7;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 196ULL: goto x86_l_c4;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 209ULL: goto x86_l_d1;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 243ULL: goto x86_l_f3;
	case 245ULL: goto x86_l_f5;
	case 250ULL: goto x86_l_fa;
	case 252ULL: goto x86_l_fc;
	case 256ULL: goto x86_l_100;
	case 258ULL: goto x86_l_102;
	case 265ULL: goto x86_l_109;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 299ULL: goto x86_l_12b;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 316ULL: goto x86_l_13c;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 349ULL: goto x86_l_15d;
	case 352ULL: goto x86_l_160;
	case 358ULL: goto x86_l_166;
	case 361ULL: goto x86_l_169;
	case 371ULL: goto x86_l_173;
	case 379ULL: goto x86_l_17b;
	case 390ULL: goto x86_l_186;
	case 401ULL: goto x86_l_191;
	case 412ULL: goto x86_l_19c;
	case 423ULL: goto x86_l_1a7;
	case 434ULL: goto x86_l_1b2;
	case 445ULL: goto x86_l_1bd;
	case 456ULL: goto x86_l_1c8;
	case 467ULL: goto x86_l_1d3;
	case 474ULL: goto x86_l_1da;
	case 482ULL: goto x86_l_1e2;
	case 490ULL: goto x86_l_1ea;
	case 498ULL: goto x86_l_1f2;
	case 506ULL: goto x86_l_1fa;
	case 514ULL: goto x86_l_202;
	case 522ULL: goto x86_l_20a;
	case 530ULL: goto x86_l_212;
	case 538ULL: goto x86_l_21a;
	case 546ULL: goto x86_l_222;
	case 554ULL: goto x86_l_22a;
	case 562ULL: goto x86_l_232;
	case 570ULL: goto x86_l_23a;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 589ULL: goto x86_l_24d;
	case 593ULL: goto x86_l_251;
	case 597ULL: goto x86_l_255;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 628ULL: goto x86_l_274;
	case 632ULL: goto x86_l_278;
	case 636ULL: goto x86_l_27c;
	case 639ULL: goto x86_l_27f;
	case 646ULL: goto x86_l_286;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 656ULL: goto x86_l_290;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 669ULL: goto x86_l_29d;
	case 673ULL: goto x86_l_2a1;
	case 680ULL: goto x86_l_2a8;
	case 687ULL: goto x86_l_2af;
	case 695ULL: goto x86_l_2b7;
	case 700ULL: goto x86_l_2bc;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 713ULL: goto x86_l_2c9;
	case 721ULL: goto x86_l_2d1;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 738ULL: goto x86_l_2e2;
	case 743ULL: goto x86_l_2e7;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 765ULL: goto x86_l_2fd;
	case 772ULL: goto x86_l_304;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 804ULL: goto x86_l_324;
	case 815ULL: goto x86_l_32f;
	case 826ULL: goto x86_l_33a;
	case 837ULL: goto x86_l_345;
	case 848ULL: goto x86_l_350;
	case 859ULL: goto x86_l_35b;
	case 870ULL: goto x86_l_366;
	case 881ULL: goto x86_l_371;
	case 892ULL: goto x86_l_37c;
	case 903ULL: goto x86_l_387;
	case 914ULL: goto x86_l_392;
	case 925ULL: goto x86_l_39d;
	case 936ULL: goto x86_l_3a8;
	case 947ULL: goto x86_l_3b3;
	case 958ULL: goto x86_l_3be;
	case 969ULL: goto x86_l_3c9;
	case 980ULL: goto x86_l_3d4;
	case 991ULL: goto x86_l_3df;
	case 1002ULL: goto x86_l_3ea;
	case 1013ULL: goto x86_l_3f5;
	case 1024ULL: goto x86_l_400;
	case 1035ULL: goto x86_l_40b;
	case 1046ULL: goto x86_l_416;
	case 1057ULL: goto x86_l_421;
	case 1068ULL: goto x86_l_42c;
	case 1079ULL: goto x86_l_437;
	case 1090ULL: goto x86_l_442;
	case 1101ULL: goto x86_l_44d;
	case 1112ULL: goto x86_l_458;
	case 1123ULL: goto x86_l_463;
	case 1134ULL: goto x86_l_46e;
	case 1142ULL: goto x86_l_476;
	case 1150ULL: goto x86_l_47e;
	case 1158ULL: goto x86_l_486;
	case 1166ULL: goto x86_l_48e;
	case 1174ULL: goto x86_l_496;
	case 1182ULL: goto x86_l_49e;
	case 1190ULL: goto x86_l_4a6;
	case 1198ULL: goto x86_l_4ae;
	case 1206ULL: goto x86_l_4b6;
	case 1214ULL: goto x86_l_4be;
	case 1222ULL: goto x86_l_4c6;
	case 1230ULL: goto x86_l_4ce;
	case 1238ULL: goto x86_l_4d6;
	case 1246ULL: goto x86_l_4de;
	case 1254ULL: goto x86_l_4e6;
	case 1261ULL: goto x86_l_4ed;
	case 1268ULL: goto x86_l_4f4;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1286ULL: goto x86_l_506;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1301ULL: goto x86_l_515;
	case 1303ULL: goto x86_l_517;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1320ULL: goto x86_l_528;
	case 1325ULL: goto x86_l_52d;
	case 1332ULL: goto x86_l_534;
	case 1336ULL: goto x86_l_538;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1367ULL: goto x86_l_557;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1389ULL: goto x86_l_56d;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1408ULL: goto x86_l_580;
	case 1419ULL: goto x86_l_58b;
	case 1430ULL: goto x86_l_596;
	case 1441ULL: goto x86_l_5a1;
	case 1452ULL: goto x86_l_5ac;
	case 1463ULL: goto x86_l_5b7;
	case 1474ULL: goto x86_l_5c2;
	case 1485ULL: goto x86_l_5cd;
	case 1496ULL: goto x86_l_5d8;
	case 1504ULL: goto x86_l_5e0;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1528ULL: goto x86_l_5f8;
	case 1536ULL: goto x86_l_600;
	case 1544ULL: goto x86_l_608;
	case 1552ULL: goto x86_l_610;
	case 1560ULL: goto x86_l_618;
	case 1568ULL: goto x86_l_620;
	case 1576ULL: goto x86_l_628;
	case 1584ULL: goto x86_l_630;
	case 1592ULL: goto x86_l_638;
	case 1600ULL: goto x86_l_640;
	case 1608ULL: goto x86_l_648;
	case 1616ULL: goto x86_l_650;
	case 1623ULL: goto x86_l_657;
	case 1630ULL: goto x86_l_65e;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1648ULL: goto x86_l_670;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1674ULL: goto x86_l_68a;
	case 1677ULL: goto x86_l_68d;
	case 1684ULL: goto x86_l_694;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1711ULL: goto x86_l_6af;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1726ULL: goto x86_l_6be;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1788ULL: goto x86_l_6fc;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1849ULL: goto x86_l_739;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1881ULL: goto x86_l_759;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1919ULL: goto x86_l_77f;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2011ULL: goto x86_l_7db;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2025ULL: goto x86_l_7e9;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2059ULL: goto x86_l_80b;
	case 2064ULL: goto x86_l_810;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2118ULL: goto x86_l_846;
	case 2122ULL: goto x86_l_84a;
	case 2126ULL: goto x86_l_84e;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
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
	/* 0xa: sub    rsp,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 392ULL);
x86_l_11:
	/* 0x11: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    QWORD PTR [rsp+0x180],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1649267441664ULL);
x86_l_20:
	/* 0x20: mov    QWORD PTR [rsp+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_2c:
	/* 0x2c: mov    QWORD PTR [rsp+0x170],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1580547964928ULL);
x86_l_38:
	/* 0x38: mov    QWORD PTR [rsp+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_44:
	/* 0x44: mov    QWORD PTR [rsp+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_5c:
	/* 0x5c: mov    QWORD PTR [rsp+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rsp+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_74:
	/* 0x74: mov    QWORD PTR [rsp+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_80:
	/* 0x80: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_85:
	/* 0x85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87:
	/* 0x87: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_8f:
	/* 0x8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91:
	/* 0x91: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_98:
	/* 0x98: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d:
	/* 0x9d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a2:
	/* 0xa2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a7:
	/* 0xa7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ac:
	/* 0xac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae:
	/* 0xae: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_b6:
	/* 0xb6: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_bb:
	/* 0xbb: jne    123 <trace_security_file_mprotect+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_123;
	}
x86_l_bd:
	/* 0xbd: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_c2:
	/* 0xc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4:
	/* 0xc4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c7:
	/* 0xc7: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_cc:
	/* 0xcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce:
	/* 0xce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1:
	/* 0xd1: je     d8 <trace_security_file_mprotect+0xd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d8;
	}
x86_l_d3:
	/* 0xd3: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d6:
	/* 0xd6: jmp    d8 <trace_security_file_mprotect+0xd8> */
	goto x86_l_d8;
x86_l_d8:
	/* 0xd8: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc:
	/* 0xdc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e1:
	/* 0xe1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e6:
	/* 0xe6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eb:
	/* 0xeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f0:
	/* 0xf0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5:
	/* 0xf5: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_fa:
	/* 0xfa: jne    102 <trace_security_file_mprotect+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_102;
	}
x86_l_fc:
	/* 0xfc: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100:
	/* 0x100: jmp    123 <trace_security_file_mprotect+0x123> */
	goto x86_l_123;
x86_l_102:
	/* 0x102: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_109:
	/* 0x109: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e:
	/* 0x10e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_113:
	/* 0x113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115:
	/* 0x115: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118:
	/* 0x118: je     11e <trace_security_file_mprotect+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e;
	}
x86_l_11a:
	/* 0x11a: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c:
	/* 0x11c: jmp    123 <trace_security_file_mprotect+0x123> */
	goto x86_l_123;
x86_l_11e:
	/* 0x11e: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_123:
	/* 0x123: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_12b:
	/* 0x12b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_132:
	/* 0x132: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137:
	/* 0x137: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c:
	/* 0x13c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e:
	/* 0x13e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_141:
	/* 0x141: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_147:
	/* 0x147: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_14a:
	/* 0x14a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_151:
	/* 0x151: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_156:
	/* 0x156: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b:
	/* 0x15b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d:
	/* 0x15d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160:
	/* 0x160: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_166:
	/* 0x166: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: mov    WORD PTR [r13+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_173:
	/* 0x173: mov    BYTE PTR [r13+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_17b:
	/* 0x17b: mov    QWORD PTR [r13+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_186:
	/* 0x186: mov    QWORD PTR [r13+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [r13+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [r13+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [r13+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [r13+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1bd:
	/* 0x1bd: mov    QWORD PTR [r13+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [r13+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1d3:
	/* 0x1d3: mov    QWORD PTR [r13+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1da:
	/* 0x1da: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ea:
	/* 0x1ea: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f2:
	/* 0x1f2: mov    QWORD PTR [r13+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1fa:
	/* 0x1fa: mov    QWORD PTR [r13+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_202:
	/* 0x202: mov    QWORD PTR [r13+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20a:
	/* 0x20a: mov    QWORD PTR [r13+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_212:
	/* 0x212: mov    QWORD PTR [r13+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [r13+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_222:
	/* 0x222: mov    QWORD PTR [r13+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_22a:
	/* 0x22a: mov    QWORD PTR [r13+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_232:
	/* 0x232: mov    QWORD PTR [r13+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_23a:
	/* 0x23a: mov    QWORD PTR [r13+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_242:
	/* 0x242: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24d:
	/* 0x24d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_251:
	/* 0x251: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_255:
	/* 0x255: mov    DWORD PTR [r13+0x70],0x2ec */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337900ULL);
x86_l_25d:
	/* 0x25d: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_262:
	/* 0x262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264:
	/* 0x264: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_268:
	/* 0x268: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: mov    WORD PTR [r13+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_274:
	/* 0x274: mov    DWORD PTR [r13+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_278:
	/* 0x278: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_27c:
	/* 0x27c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f:
	/* 0x27f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_286:
	/* 0x286: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_289:
	/* 0x289: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e:
	/* 0x28e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290:
	/* 0x290: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_298:
	/* 0x298: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: je     2ee <trace_security_file_mprotect+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee;
	}
x86_l_29d:
	/* 0x29d: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a1:
	/* 0x2a1: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a8:
	/* 0x2a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2af:
	/* 0x2af: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2b7:
	/* 0x2b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bc:
	/* 0x2bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be:
	/* 0x2be: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c4:
	/* 0x2c4: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c9:
	/* 0x2c9: mov    QWORD PTR [rsp+0xb8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2d1:
	/* 0x2d1: je     52d <trace_security_file_mprotect+0x52d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52d;
	}
x86_l_2d7:
	/* 0x2d7: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2dc:
	/* 0x2dc: jne    b44 <trace_security_file_mprotect+0xb44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2884ULL;
	}
x86_l_2e2:
	/* 0x2e2: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2e7:
	/* 0x2e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9:
	/* 0x2e9: jmp    bee <trace_security_file_mprotect+0xbee> */
	return 3054ULL;
x86_l_2ee:
	/* 0x2ee: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f1:
	/* 0x2f1: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2fd:
	/* 0x2fd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_304:
	/* 0x304: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309:
	/* 0x309: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_319:
	/* 0x319: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_320:
	/* 0x320: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_324:
	/* 0x324: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_32f:
	/* 0x32f: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_33a:
	/* 0x33a: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_345:
	/* 0x345: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_35b:
	/* 0x35b: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_366:
	/* 0x366: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_371:
	/* 0x371: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_37c:
	/* 0x37c: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_392:
	/* 0x392: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3a8:
	/* 0x3a8: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3be:
	/* 0x3be: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3ea:
	/* 0x3ea: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_400:
	/* 0x400: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_416:
	/* 0x416: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_421:
	/* 0x421: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_42c:
	/* 0x42c: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_437:
	/* 0x437: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_458:
	/* 0x458: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_486:
	/* 0x486: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_48e:
	/* 0x48e: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_49e:
	/* 0x49e: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4a6:
	/* 0x4a6: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4be:
	/* 0x4be: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4d6:
	/* 0x4d6: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4de:
	/* 0x4de: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ed:
	/* 0x4ed: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4f4:
	/* 0x4f4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f9:
	/* 0x4f9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4fe:
	/* 0x4fe: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_503:
	/* 0x503: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_506:
	/* 0x506: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508:
	/* 0x508: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50d:
	/* 0x50d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_512:
	/* 0x512: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_515:
	/* 0x515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_517:
	/* 0x517: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_51f:
	/* 0x51f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_522:
	/* 0x522: jne    29d <trace_security_file_mprotect+0x29d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29d;
	}
x86_l_528:
	/* 0x528: jmp    4152 <trace_security_file_mprotect+0x4152> */
	return 16722ULL;
x86_l_52d:
	/* 0x52d: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_534:
	/* 0x534: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_538:
	/* 0x538: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_540:
	/* 0x540: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_547:
	/* 0x547: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c:
	/* 0x54c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_551:
	/* 0x551: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55c:
	/* 0x55c: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_562:
	/* 0x562: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: mov    QWORD PTR [rsp+0xb0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_56d:
	/* 0x56d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_571:
	/* 0x571: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_575:
	/* 0x575: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_580:
	/* 0x580: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_58b:
	/* 0x58b: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_596:
	/* 0x596: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5a1:
	/* 0x5a1: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5b7:
	/* 0x5b7: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5c2:
	/* 0x5c2: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5cd:
	/* 0x5cd: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5d8:
	/* 0x5d8: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5e0:
	/* 0x5e0: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5f8:
	/* 0x5f8: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_608:
	/* 0x608: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_610:
	/* 0x610: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_618:
	/* 0x618: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_620:
	/* 0x620: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_628:
	/* 0x628: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_630:
	/* 0x630: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_638:
	/* 0x638: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_640:
	/* 0x640: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_648:
	/* 0x648: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_650:
	/* 0x650: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_657:
	/* 0x657: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_65e:
	/* 0x65e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_663:
	/* 0x663: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_668:
	/* 0x668: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_66d:
	/* 0x66d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_670:
	/* 0x670: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_672:
	/* 0x672: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_677:
	/* 0x677: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67c:
	/* 0x67c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681:
	/* 0x681: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_684:
	/* 0x684: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_68a:
	/* 0x68a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_68d:
	/* 0x68d: mov    rbx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_694:
	/* 0x694: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_698:
	/* 0x698: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d:
	/* 0x69d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6a2:
	/* 0x6a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a7:
	/* 0x6a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ac:
	/* 0x6ac: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6af:
	/* 0x6af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b1:
	/* 0x6b1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b6:
	/* 0x6b6: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6be:
	/* 0x6be: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c2:
	/* 0x6c2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c7:
	/* 0x6c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6cc:
	/* 0x6cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d1:
	/* 0x6d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d6:
	/* 0x6d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d8:
	/* 0x6d8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6dd:
	/* 0x6dd: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6e1:
	/* 0x6e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e6:
	/* 0x6e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6eb:
	/* 0x6eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f0:
	/* 0x6f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6fc:
	/* 0x6fc: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_700:
	/* 0x700: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_705:
	/* 0x705: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_70a:
	/* 0x70a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70f:
	/* 0x70f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_714:
	/* 0x714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_716:
	/* 0x716: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71a:
	/* 0x71a: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_71e:
	/* 0x71e: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_722:
	/* 0x722: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_727:
	/* 0x727: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_72c:
	/* 0x72c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_731:
	/* 0x731: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_736:
	/* 0x736: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_739:
	/* 0x739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73b:
	/* 0x73b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_740:
	/* 0x740: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_745:
	/* 0x745: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_74a:
	/* 0x74a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74f:
	/* 0x74f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_754:
	/* 0x754: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_757:
	/* 0x757: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_759:
	/* 0x759: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75d:
	/* 0x75d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_761:
	/* 0x761: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_765:
	/* 0x765: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_769:
	/* 0x769: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_76e:
	/* 0x76e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_773:
	/* 0x773: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_778:
	/* 0x778: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77d:
	/* 0x77d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77f:
	/* 0x77f: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_783:
	/* 0x783: mov    DWORD PTR [r14+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_787:
	/* 0x787: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_78c:
	/* 0x78c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_791:
	/* 0x791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_796:
	/* 0x796: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_79b:
	/* 0x79b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_79e:
	/* 0x79e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a0:
	/* 0x7a0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a5:
	/* 0x7a5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7a9:
	/* 0x7a9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ae:
	/* 0x7ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b8:
	/* 0x7b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7bd:
	/* 0x7bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bf:
	/* 0x7bf: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c4:
	/* 0x7c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c9:
	/* 0x7c9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ce:
	/* 0x7ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d3:
	/* 0x7d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7d8:
	/* 0x7d8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7db:
	/* 0x7db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dd:
	/* 0x7dd: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7e1:
	/* 0x7e1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7e5:
	/* 0x7e5: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7e9:
	/* 0x7e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7ed:
	/* 0x7ed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f2:
	/* 0x7f2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7f7:
	/* 0x7f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7fc:
	/* 0x7fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_801:
	/* 0x801: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_803:
	/* 0x803: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_807:
	/* 0x807: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80b:
	/* 0x80b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_810:
	/* 0x810: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_815:
	/* 0x815: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_81a:
	/* 0x81a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81f:
	/* 0x81f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_822:
	/* 0x822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_824:
	/* 0x824: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_829:
	/* 0x829: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82e:
	/* 0x82e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_833:
	/* 0x833: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_838:
	/* 0x838: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_83d:
	/* 0x83d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_840:
	/* 0x840: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_842:
	/* 0x842: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_846:
	/* 0x846: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_84a:
	/* 0x84a: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_84e:
	/* 0x84e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_852:
	/* 0x852: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_857:
	/* 0x857: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_85c:
	/* 0x85c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_861:
	/* 0x861: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_866:
	/* 0x866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_868:
	/* 0x868: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86d:
	/* 0x86d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_871:
	/* 0x871: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_876:
	/* 0x876: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_87b:
	/* 0x87b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_880:
	/* 0x880: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_885:
	/* 0x885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_887:
	/* 0x887: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88b:
	/* 0x88b: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88f:
	/* 0x88f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_894:
	/* 0x894: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_899:
	/* 0x899: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2206ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2254ULL: goto x86_l_8ce;
	case 2258ULL: goto x86_l_8d2;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2322ULL: goto x86_l_912;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2377ULL: goto x86_l_949;
	case 2379ULL: goto x86_l_94b;
	case 2383ULL: goto x86_l_94f;
	case 2387ULL: goto x86_l_953;
	case 2391ULL: goto x86_l_957;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2417ULL: goto x86_l_971;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2526ULL: goto x86_l_9de;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2582ULL: goto x86_l_a16;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2688ULL: goto x86_l_a80;
	case 2690ULL: goto x86_l_a82;
	case 2695ULL: goto x86_l_a87;
	case 2703ULL: goto x86_l_a8f;
	case 2705ULL: goto x86_l_a91;
	case 2711ULL: goto x86_l_a97;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2774ULL: goto x86_l_ad6;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2836ULL: goto x86_l_b14;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2906ULL: goto x86_l_b5a;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2918ULL: goto x86_l_b66;
	case 2923ULL: goto x86_l_b6b;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3019ULL: goto x86_l_bcb;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3045ULL: goto x86_l_be5;
	case 3050ULL: goto x86_l_bea;
	case 3052ULL: goto x86_l_bec;
	case 3054ULL: goto x86_l_bee;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3067ULL: goto x86_l_bfb;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3084ULL: goto x86_l_c0c;
	case 3086ULL: goto x86_l_c0e;
	case 3089ULL: goto x86_l_c11;
	case 3091ULL: goto x86_l_c13;
	case 3094ULL: goto x86_l_c16;
	case 3102ULL: goto x86_l_c1e;
	case 3105ULL: goto x86_l_c21;
	case 3108ULL: goto x86_l_c24;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3131ULL: goto x86_l_c3b;
	case 3142ULL: goto x86_l_c46;
	case 3150ULL: goto x86_l_c4e;
	case 3155ULL: goto x86_l_c53;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	case 3179ULL: goto x86_l_c6b;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3203ULL: goto x86_l_c83;
	case 3210ULL: goto x86_l_c8a;
	case 3213ULL: goto x86_l_c8d;
	case 3220ULL: goto x86_l_c94;
	case 3224ULL: goto x86_l_c98;
	case 3228ULL: goto x86_l_c9c;
	case 3235ULL: goto x86_l_ca3;
	case 3242ULL: goto x86_l_caa;
	case 3246ULL: goto x86_l_cae;
	case 3253ULL: goto x86_l_cb5;
	case 3257ULL: goto x86_l_cb9;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3286ULL: goto x86_l_cd6;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3328ULL: goto x86_l_d00;
	case 3336ULL: goto x86_l_d08;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3375ULL: goto x86_l_d2f;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3477ULL: goto x86_l_d95;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3503ULL: goto x86_l_daf;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3529ULL: goto x86_l_dc9;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3555ULL: goto x86_l_de3;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3566ULL: goto x86_l_dee;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3581ULL: goto x86_l_dfd;
	case 3584ULL: goto x86_l_e00;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3602ULL: goto x86_l_e12;
	case 3610ULL: goto x86_l_e1a;
	case 3618ULL: goto x86_l_e22;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3628ULL: goto x86_l_e2c;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3644ULL: goto x86_l_e3c;
	case 3653ULL: goto x86_l_e45;
	case 3656ULL: goto x86_l_e48;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3666ULL: goto x86_l_e52;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3679ULL: goto x86_l_e5f;
	case 3682ULL: goto x86_l_e62;
	case 3689ULL: goto x86_l_e69;
	case 3692ULL: goto x86_l_e6c;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3704ULL: goto x86_l_e78;
	case 3711ULL: goto x86_l_e7f;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3740ULL: goto x86_l_e9c;
	case 3743ULL: goto x86_l_e9f;
	case 3745ULL: goto x86_l_ea1;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3755ULL: goto x86_l_eab;
	case 3758ULL: goto x86_l_eae;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3778ULL: goto x86_l_ec2;
	case 3781ULL: goto x86_l_ec5;
	case 3783ULL: goto x86_l_ec7;
	case 3786ULL: goto x86_l_eca;
	case 3794ULL: goto x86_l_ed2;
	case 3798ULL: goto x86_l_ed6;
	case 3801ULL: goto x86_l_ed9;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3826ULL: goto x86_l_ef2;
	case 3829ULL: goto x86_l_ef5;
	case 3837ULL: goto x86_l_efd;
	case 3843ULL: goto x86_l_f03;
	case 3850ULL: goto x86_l_f0a;
	case 3858ULL: goto x86_l_f12;
	case 3865ULL: goto x86_l_f19;
	case 3872ULL: goto x86_l_f20;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	default: return 0xffffffffffffffffULL;
	}
x86_l_89e:
	/* 0x89e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a3:
	/* 0x8a3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8a6:
	/* 0x8a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a8:
	/* 0x8a8: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ad:
	/* 0x8ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b2:
	/* 0x8b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8b7:
	/* 0x8b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8bc:
	/* 0x8bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8c1:
	/* 0x8c1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c6:
	/* 0x8c6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ca:
	/* 0x8ca: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8ce:
	/* 0x8ce: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8d2:
	/* 0x8d2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8d6:
	/* 0x8d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8db:
	/* 0x8db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8e0:
	/* 0x8e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e5:
	/* 0x8e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ea:
	/* 0x8ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ec:
	/* 0x8ec: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8f1:
	/* 0x8f1: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8f5:
	/* 0x8f5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8fa:
	/* 0x8fa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8ff:
	/* 0x8ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_904:
	/* 0x904: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_909:
	/* 0x909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90b:
	/* 0x90b: cmp    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_90f:
	/* 0x90f: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_912:
	/* 0x912: jne    97a <trace_security_file_mprotect+0x97a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_97a;
	}
x86_l_914:
	/* 0x914: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_919:
	/* 0x919: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_91e:
	/* 0x91e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_923:
	/* 0x923: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_928:
	/* 0x928: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_92b:
	/* 0x92b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92d:
	/* 0x92d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_932:
	/* 0x932: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_937:
	/* 0x937: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_941:
	/* 0x941: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_946:
	/* 0x946: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_949:
	/* 0x949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94b:
	/* 0x94b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_94f:
	/* 0x94f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_953:
	/* 0x953: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_957:
	/* 0x957: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_95b:
	/* 0x95b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_960:
	/* 0x960: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_965:
	/* 0x965: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96a:
	/* 0x96a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_96f:
	/* 0x96f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_971:
	/* 0x971: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_975:
	/* 0x975: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_97a:
	/* 0x97a: mov    DWORD PTR [r12+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97f:
	/* 0x97f: lea    rbp,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_986:
	/* 0x986: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98b:
	/* 0x98b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_990:
	/* 0x990: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_995:
	/* 0x995: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_99a:
	/* 0x99a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_99d:
	/* 0x99d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99f:
	/* 0x99f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a4:
	/* 0x9a4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9a8:
	/* 0x9a8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ad:
	/* 0x9ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9b2:
	/* 0x9b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b7:
	/* 0x9b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bc:
	/* 0x9bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9be:
	/* 0x9be: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c3:
	/* 0x9c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c8:
	/* 0x9c8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9cd:
	/* 0x9cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d2:
	/* 0x9d2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d7:
	/* 0x9d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9dc:
	/* 0x9dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9de:
	/* 0x9de: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e2:
	/* 0x9e2: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_9e7:
	/* 0x9e7: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_9ec:
	/* 0x9ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ee:
	/* 0x9ee: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f3:
	/* 0x9f3: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9f7:
	/* 0x9f7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9fc:
	/* 0x9fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a01:
	/* 0xa01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a06:
	/* 0xa06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0b:
	/* 0xa0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0d:
	/* 0xa0d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a12:
	/* 0xa12: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a16:
	/* 0xa16: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a1e:
	/* 0xa1e: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a22:
	/* 0xa22: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a27:
	/* 0xa27: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a2c:
	/* 0xa2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a31:
	/* 0xa31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a36:
	/* 0xa36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a38:
	/* 0xa38: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a3d:
	/* 0xa3d: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a42:
	/* 0xa42: add    r13,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a46:
	/* 0xa46: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a4b:
	/* 0xa4b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a50:
	/* 0xa50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a55:
	/* 0xa55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a5a:
	/* 0xa5a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5f:
	/* 0xa5f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a69:
	/* 0xa69: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a6e:
	/* 0xa6e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a73:
	/* 0xa73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a78:
	/* 0xa78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a7d:
	/* 0xa7d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a80:
	/* 0xa80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a82:
	/* 0xa82: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_a87:
	/* 0xa87: mov    r14,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a8f:
	/* 0xa8f: je     a97 <trace_security_file_mprotect+0xa97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a97;
	}
x86_l_a91:
	/* 0xa91: or     BYTE PTR [r12+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a97:
	/* 0xa97: mov    QWORD PTR [r12+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_aa0:
	/* 0xaa0: lea    rdi,[r12+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [r12+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_aae:
	/* 0xaae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ab3:
	/* 0xab3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_ab8:
	/* 0xab8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_abd:
	/* 0xabd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abf:
	/* 0xabf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ac4:
	/* 0xac4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ac9:
	/* 0xac9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ace:
	/* 0xace: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ad3:
	/* 0xad3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ad6:
	/* 0xad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad8:
	/* 0xad8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_add:
	/* 0xadd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ae2:
	/* 0xae2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae7:
	/* 0xae7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aec:
	/* 0xaec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af1:
	/* 0xaf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af3:
	/* 0xaf3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_af8:
	/* 0xaf8: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_afd:
	/* 0xafd: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_b02:
	/* 0xb02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b07:
	/* 0xb07: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b0f:
	/* 0xb0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b11:
	/* 0xb11: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b14:
	/* 0xb14: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b18:
	/* 0xb18: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b1d:
	/* 0xb1d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b22:
	/* 0xb22: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b27:
	/* 0xb27: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2c:
	/* 0xb2c: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b34:
	/* 0xb34: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b39:
	/* 0xb39: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b3e:
	/* 0xb3e: je     2e2 <trace_security_file_mprotect+0x2e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 738ULL;
	}
x86_l_b44:
	/* 0xb44: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b49:
	/* 0xb49: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b50:
	/* 0xb50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b55:
	/* 0xb55: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b5a:
	/* 0xb5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b5f:
	/* 0xb5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b64:
	/* 0xb64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b66:
	/* 0xb66: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6b:
	/* 0xb6b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b70:
	/* 0xb70: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b75:
	/* 0xb75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b7a:
	/* 0xb7a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7f:
	/* 0xb7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b84:
	/* 0xb84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b86:
	/* 0xb86: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8b:
	/* 0xb8b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b90:
	/* 0xb90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b95:
	/* 0xb95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b9a:
	/* 0xb9a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9f:
	/* 0xb9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba4:
	/* 0xba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba6:
	/* 0xba6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bab:
	/* 0xbab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb0:
	/* 0xbb0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bb5:
	/* 0xbb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bba:
	/* 0xbba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bbf:
	/* 0xbbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc1:
	/* 0xbc1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bc6:
	/* 0xbc6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bc9:
	/* 0xbc9: je     bec <trace_security_file_mprotect+0xbec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bec;
	}
x86_l_bcb:
	/* 0xbcb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bcf:
	/* 0xbcf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd4:
	/* 0xbd4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bd9:
	/* 0xbd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bde:
	/* 0xbde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be3:
	/* 0xbe3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be5:
	/* 0xbe5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bea:
	/* 0xbea: jmp    bee <trace_security_file_mprotect+0xbee> */
	goto x86_l_bee;
x86_l_bec:
	/* 0xbec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bee:
	/* 0xbee: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf2:
	/* 0xbf2: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf7:
	/* 0xbf7: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bfb:
	/* 0xbfb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c02:
	/* 0xc02: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c07:
	/* 0xc07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c0c:
	/* 0xc0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0e:
	/* 0xc0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c11:
	/* 0xc11: je     c2b <trace_security_file_mprotect+0xc2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2b;
	}
x86_l_c13:
	/* 0xc13: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c16:
	/* 0xc16: mov    BYTE PTR [r12+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c1e:
	/* 0xc1e: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c21:
	/* 0xc21: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c24:
	/* 0xc24: jne    c2b <trace_security_file_mprotect+0xc2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c2b;
	}
x86_l_c26:
	/* 0xc26: or     BYTE PTR [r13+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c2b:
	/* 0xc2b: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c30:
	/* 0xc30: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c35:
	/* 0xc35: jne    4329 <trace_security_file_mprotect+0x4329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17193ULL;
	}
x86_l_c3b:
	/* 0xc3b: mov    QWORD PTR [r13+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c46:
	/* 0xc46: mov    DWORD PTR [rsp+0x30],0x2ec */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430956ULL);
x86_l_c4e:
	/* 0xc4e: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c53:
	/* 0xc53: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c5a:
	/* 0xc5a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c5f:
	/* 0xc5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c64:
	/* 0xc64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c66:
	/* 0xc66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c69:
	/* 0xc69: je     cd6 <trace_security_file_mprotect+0xcd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd6;
	}
x86_l_c6b:
	/* 0xc6b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c73:
	/* 0xc73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c78:
	/* 0xc78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7a:
	/* 0xc7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c7d:
	/* 0xc7d: je     cd6 <trace_security_file_mprotect+0xcd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd6;
	}
x86_l_c7f:
	/* 0xc7f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c83:
	/* 0xc83: mov    QWORD PTR [r13+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c8a:
	/* 0xc8a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8d:
	/* 0xc8d: mov    QWORD PTR [r13+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c94:
	/* 0xc94: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c98:
	/* 0xc98: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c9c:
	/* 0xc9c: mov    QWORD PTR [r13+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_ca3:
	/* 0xca3: mov    QWORD PTR [r13+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_caa:
	/* 0xcaa: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cae:
	/* 0xcae: mov    QWORD PTR [r13+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_cb5:
	/* 0xcb5: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb9:
	/* 0xcb9: mov    QWORD PTR [r13+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_cc0:
	/* 0xcc0: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cc4:
	/* 0xcc4: mov    QWORD PTR [r13+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_ccb:
	/* 0xccb: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ccf:
	/* 0xccf: mov    QWORD PTR [r13+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_cd6:
	/* 0xcd6: mov    rax,QWORD PTR [r13+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_cdd:
	/* 0xcdd: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ce4:
	/* 0xce4: mov    eax,DWORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_ce8:
	/* 0xce8: cmp    eax,0x149 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 329ULL);
x86_l_ced:
	/* 0xced: je     cf8 <trace_security_file_mprotect+0xcf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf8;
	}
x86_l_cef:
	/* 0xcef: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_cf2:
	/* 0xcf2: jne    4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16722ULL;
	}
x86_l_cf8:
	/* 0xcf8: mov    rbx,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cfc:
	/* 0xcfc: mov    rax,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d00:
	/* 0xd00: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d08:
	/* 0xd08: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d0c:
	/* 0xd0c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d11:
	/* 0xd11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d16:
	/* 0xd16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d1b:
	/* 0xd1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d20:
	/* 0xd20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d22:
	/* 0xd22: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d27:
	/* 0xd27: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_d2f:
	/* 0xd2f: add    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_d33:
	/* 0xd33: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d38:
	/* 0xd38: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3d:
	/* 0xd3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d42:
	/* 0xd42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d47:
	/* 0xd47: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_d4a:
	/* 0xd4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4c:
	/* 0xd4c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d59:
	/* 0xd59: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_d5e:
	/* 0xd5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d60:
	/* 0xd60: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d63:
	/* 0xd63: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_d68:
	/* 0xd68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6a:
	/* 0xd6a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d6d:
	/* 0xd6d: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_d74:
	/* 0xd74: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d79:
	/* 0xd79: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d7e:
	/* 0xd7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d83:
	/* 0xd83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d88:
	/* 0xd88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8a:
	/* 0xd8a: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_d8f:
	/* 0xd8f: jne    d97 <trace_security_file_mprotect+0xd97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d97;
	}
x86_l_d91:
	/* 0xd91: lea    rax,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d95:
	/* 0xd95: jmp    da4 <trace_security_file_mprotect+0xda4> */
	goto x86_l_da4;
x86_l_d97:
	/* 0xd97: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_d9a:
	/* 0xd9a: je     fdf <trace_security_file_mprotect+0xfdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4063ULL;
	}
x86_l_da0:
	/* 0xda0: lea    rax,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_da4:
	/* 0xda4: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da7:
	/* 0xda7: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_daf:
	/* 0xdaf: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_db6:
	/* 0xdb6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dbb:
	/* 0xdbb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dc0:
	/* 0xdc0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dc5:
	/* 0xdc5: lea    rcx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dc9:
	/* 0xdc9: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_dd1:
	/* 0xdd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dd6:
	/* 0xdd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd8:
	/* 0xdd8: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_ddd:
	/* 0xddd: jne    de5 <trace_security_file_mprotect+0xde5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_de5;
	}
x86_l_ddf:
	/* 0xddf: lea    rax,[rbp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_de3:
	/* 0xde3: jmp    df2 <trace_security_file_mprotect+0xdf2> */
	goto x86_l_df2;
x86_l_de5:
	/* 0xde5: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_de8:
	/* 0xde8: je     fe4 <trace_security_file_mprotect+0xfe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4068ULL;
	}
x86_l_dee:
	/* 0xdee: lea    rax,[rbp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_df2:
	/* 0xdf2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df5:
	/* 0xdf5: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_dfd:
	/* 0xdfd: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e00:
	/* 0xe00: mov    rcx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e08:
	/* 0xe08: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_e0a:
	/* 0xe0a: mov    QWORD PTR [rsp+0xc8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e12:
	/* 0xe12: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e1a:
	/* 0xe1a: mov    QWORD PTR [rsp+0xb0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e22:
	/* 0xe22: jne    e2c <trace_security_file_mprotect+0xe2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e2c;
	}
x86_l_e24:
	/* 0xe24: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e27:
	/* 0xe27: jmp    1630 <trace_security_file_mprotect+0x1630> */
	return 5680ULL;
x86_l_e2c:
	/* 0xe2c: mov    rax,QWORD PTR [r13+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_e33:
	/* 0xe33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e36:
	/* 0xe36: je     fe9 <trace_security_file_mprotect+0xfe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4073ULL;
	}
x86_l_e3c:
	/* 0xe3c: movzx  ecx,BYTE PTR [r12+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_e45:
	/* 0xe45: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_e48:
	/* 0xe48: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4b:
	/* 0xe4b: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_e4e:
	/* 0xe4e: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e52:
	/* 0xe52: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e55:
	/* 0xe55: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e58:
	/* 0xe58: xor    r12,QWORD PTR [r13+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_e5f:
	/* 0xe5f: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e62:
	/* 0xe62: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e69:
	/* 0xe69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6c:
	/* 0xe6c: je     e95 <trace_security_file_mprotect+0xe95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e95;
	}
x86_l_e6e:
	/* 0xe6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e70:
	/* 0xe70: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e78:
	/* 0xe78: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_e7f:
	/* 0xe7f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_e82:
	/* 0xe82: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e85:
	/* 0xe85: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e88:
	/* 0xe88: xor    rcx,QWORD PTR [r13+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_e8f:
	/* 0xe8f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e92:
	/* 0xe92: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e95:
	/* 0xe95: mov    rax,QWORD PTR [r13+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_e9c:
	/* 0xe9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e9f:
	/* 0xe9f: je     ebb <trace_security_file_mprotect+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebb;
	}
x86_l_ea1:
	/* 0xea1: mov    ecx,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ea5:
	/* 0xea5: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ea8:
	/* 0xea8: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_eab:
	/* 0xeab: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_eae:
	/* 0xeae: xor    rcx,QWORD PTR [r13+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_eb5:
	/* 0xeb5: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_eb8:
	/* 0xeb8: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ebb:
	/* 0xebb: mov    rax,QWORD PTR [r13+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_ec2:
	/* 0xec2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec5:
	/* 0xec5: je     ee6 <trace_security_file_mprotect+0xee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee6;
	}
x86_l_ec7:
	/* 0xec7: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eca:
	/* 0xeca: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ed2:
	/* 0xed2: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ed6:
	/* 0xed6: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ed9:
	/* 0xed9: xor    rcx,QWORD PTR [r13+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_ee0:
	/* 0xee0: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ee3:
	/* 0xee3: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ee6:
	/* 0xee6: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_eeb:
	/* 0xeeb: mov    r15,QWORD PTR [r13+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_ef2:
	/* 0xef2: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_ef5:
	/* 0xef5: mov    WORD PTR [rsp+0x98],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_efd:
	/* 0xefd: je     1051 <trace_security_file_mprotect+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4177ULL;
	}
x86_l_f03:
	/* 0xf03: mov    rcx,QWORD PTR [r13+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_f0a:
	/* 0xf0a: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f12:
	/* 0xf12: mov    rbp,QWORD PTR [r13+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_f19:
	/* 0xf19: mov    rcx,QWORD PTR [r13+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_f20:
	/* 0xf20: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f28:
	/* 0xf28: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f2d:
	/* 0xf2d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_f34:
	/* 0xf34: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f39:
	/* 0xf39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3e:
	/* 0xf3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f40:
	/* 0xf40: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f43:
	/* 0xf43: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f47:
	/* 0xf47: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f4c:
	/* 0xf4c: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f53:
	/* 0xf53: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: je     f78 <trace_security_file_mprotect+0xf78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3960ULL;
	}
x86_l_f58:
	/* 0xf58: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5d:
	/* 0xf5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f62:
	/* 0xf62: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f65:
	/* 0xf65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3943ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3943ULL: goto x86_l_f67;
	case 3946ULL: goto x86_l_f6a;
	case 3948ULL: goto x86_l_f6c;
	case 3951ULL: goto x86_l_f6f;
	case 3955ULL: goto x86_l_f73;
	case 3958ULL: goto x86_l_f76;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3979ULL: goto x86_l_f8b;
	case 3982ULL: goto x86_l_f8e;
	case 3984ULL: goto x86_l_f90;
	case 3988ULL: goto x86_l_f94;
	case 3990ULL: goto x86_l_f96;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4080ULL: goto x86_l_ff0;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4116ULL: goto x86_l_1014;
	case 4118ULL: goto x86_l_1016;
	case 4120ULL: goto x86_l_1018;
	case 4128ULL: goto x86_l_1020;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4147ULL: goto x86_l_1033;
	case 4150ULL: goto x86_l_1036;
	case 4152ULL: goto x86_l_1038;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4198ULL: goto x86_l_1066;
	case 4202ULL: goto x86_l_106a;
	case 4209ULL: goto x86_l_1071;
	case 4216ULL: goto x86_l_1078;
	case 4224ULL: goto x86_l_1080;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4241ULL: goto x86_l_1091;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4317ULL: goto x86_l_10dd;
	case 4321ULL: goto x86_l_10e1;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4352ULL: goto x86_l_1100;
	case 4354ULL: goto x86_l_1102;
	case 4362ULL: goto x86_l_110a;
	case 4370ULL: goto x86_l_1112;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4381ULL: goto x86_l_111d;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4426ULL: goto x86_l_114a;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4527ULL: goto x86_l_11af;
	case 4529ULL: goto x86_l_11b1;
	case 4533ULL: goto x86_l_11b5;
	case 4537ULL: goto x86_l_11b9;
	case 4544ULL: goto x86_l_11c0;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4585ULL: goto x86_l_11e9;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4612ULL: goto x86_l_1204;
	case 4616ULL: goto x86_l_1208;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4626ULL: goto x86_l_1212;
	case 4629ULL: goto x86_l_1215;
	case 4632ULL: goto x86_l_1218;
	case 4635ULL: goto x86_l_121b;
	case 4643ULL: goto x86_l_1223;
	case 4649ULL: goto x86_l_1229;
	case 4656ULL: goto x86_l_1230;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4716ULL: goto x86_l_126c;
	case 4720ULL: goto x86_l_1270;
	case 4724ULL: goto x86_l_1274;
	case 4728ULL: goto x86_l_1278;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4781ULL: goto x86_l_12ad;
	case 4785ULL: goto x86_l_12b1;
	case 4789ULL: goto x86_l_12b5;
	case 4796ULL: goto x86_l_12bc;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4837ULL: goto x86_l_12e5;
	case 4840ULL: goto x86_l_12e8;
	case 4842ULL: goto x86_l_12ea;
	case 4845ULL: goto x86_l_12ed;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4868ULL: goto x86_l_1304;
	case 4871ULL: goto x86_l_1307;
	case 4873ULL: goto x86_l_1309;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4913ULL: goto x86_l_1331;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5017ULL: goto x86_l_1399;
	case 5019ULL: goto x86_l_139b;
	case 5026ULL: goto x86_l_13a2;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5045ULL: goto x86_l_13b5;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5058ULL: goto x86_l_13c2;
	case 5060ULL: goto x86_l_13c4;
	case 5067ULL: goto x86_l_13cb;
	case 5070ULL: goto x86_l_13ce;
	case 5072ULL: goto x86_l_13d0;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5100ULL: goto x86_l_13ec;
	case 5102ULL: goto x86_l_13ee;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5139ULL: goto x86_l_1413;
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5166ULL: goto x86_l_142e;
	case 5173ULL: goto x86_l_1435;
	case 5178ULL: goto x86_l_143a;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5195ULL: goto x86_l_144b;
	case 5198ULL: goto x86_l_144e;
	case 5200ULL: goto x86_l_1450;
	case 5207ULL: goto x86_l_1457;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5223ULL: goto x86_l_1467;
	case 5225ULL: goto x86_l_1469;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5237ULL: goto x86_l_1475;
	case 5240ULL: goto x86_l_1478;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5250ULL: goto x86_l_1482;
	case 5253ULL: goto x86_l_1485;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5273ULL: goto x86_l_1499;
	case 5277ULL: goto x86_l_149d;
	case 5281ULL: goto x86_l_14a1;
	case 5288ULL: goto x86_l_14a8;
	case 5293ULL: goto x86_l_14ad;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5313ULL: goto x86_l_14c1;
	case 5315ULL: goto x86_l_14c3;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5342ULL: goto x86_l_14de;
	case 5345ULL: goto x86_l_14e1;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5364ULL: goto x86_l_14f4;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5426ULL: goto x86_l_1532;
	case 5429ULL: goto x86_l_1535;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5447ULL: goto x86_l_1547;
	case 5449ULL: goto x86_l_1549;
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5466ULL: goto x86_l_155a;
	case 5468ULL: goto x86_l_155c;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5480ULL: goto x86_l_1568;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5515ULL: goto x86_l_158b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f67:
	/* 0xf67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6a:
	/* 0xf6a: je     f78 <trace_security_file_mprotect+0xf78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f78;
	}
x86_l_f6c:
	/* 0xf6c: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6f:
	/* 0xf6f: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f73:
	/* 0xf73: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f76:
	/* 0xf76: jmp    f7b <trace_security_file_mprotect+0xf7b> */
	goto x86_l_f7b;
x86_l_f78:
	/* 0xf78: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7b:
	/* 0xf7b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f83:
	/* 0xf83: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f88:
	/* 0xf88: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f8b:
	/* 0xf8b: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f8e:
	/* 0xf8e: jb     fa6 <trace_security_file_mprotect+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_fa6;
	}
x86_l_f90:
	/* 0xf90: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f94:
	/* 0xf94: je     f9b <trace_security_file_mprotect+0xf9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9b;
	}
x86_l_f96:
	/* 0xf96: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f99:
	/* 0xf99: jbe    fa6 <trace_security_file_mprotect+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fa6;
	}
x86_l_f9b:
	/* 0xf9b: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_fa3:
	/* 0xfa3: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_fa6:
	/* 0xfa6: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fab:
	/* 0xfab: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fae:
	/* 0xfae: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb3:
	/* 0xfb3: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fba:
	/* 0xfba: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_fbd:
	/* 0xfbd: je     1005 <trace_security_file_mprotect+0x1005> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1005;
	}
x86_l_fbf:
	/* 0xfbf: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc4:
	/* 0xfc4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc9:
	/* 0xfc9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fce:
	/* 0xfce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: je     1016 <trace_security_file_mprotect+0x1016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1016;
	}
x86_l_fd3:
	/* 0xfd3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd6:
	/* 0xfd6: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fda:
	/* 0xfda: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fdd:
	/* 0xfdd: jmp    1018 <trace_security_file_mprotect+0x1018> */
	goto x86_l_1018;
x86_l_fdf:
	/* 0xfdf: jmp    da7 <trace_security_file_mprotect+0xda7> */
	return 3495ULL;
x86_l_fe4:
	/* 0xfe4: jmp    df5 <trace_security_file_mprotect+0xdf5> */
	return 3573ULL;
x86_l_fe9:
	/* 0xfe9: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ff0:
	/* 0xff0: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ff7:
	/* 0xff7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffa:
	/* 0xffa: jne    e6e <trace_security_file_mprotect+0xe6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3694ULL;
	}
x86_l_1000:
	/* 0x1000: jmp    e95 <trace_security_file_mprotect+0xe95> */
	return 3733ULL;
x86_l_1005:
	/* 0x1005: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1007:
	/* 0x1007: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_100a:
	/* 0x100a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_100f:
	/* 0x100f: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1012:
	/* 0x1012: jae    102d <trace_security_file_mprotect+0x102d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_102d;
	}
x86_l_1014:
	/* 0x1014: jmp    1043 <trace_security_file_mprotect+0x1043> */
	goto x86_l_1043;
x86_l_1016:
	/* 0x1016: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1018:
	/* 0x1018: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1020:
	/* 0x1020: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1023:
	/* 0x1023: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1028:
	/* 0x1028: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_102b:
	/* 0x102b: jb     1043 <trace_security_file_mprotect+0x1043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1043;
	}
x86_l_102d:
	/* 0x102d: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1031:
	/* 0x1031: je     1038 <trace_security_file_mprotect+0x1038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1038;
	}
x86_l_1033:
	/* 0x1033: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1036:
	/* 0x1036: jbe    1043 <trace_security_file_mprotect+0x1043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1043;
	}
x86_l_1038:
	/* 0x1038: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_1040:
	/* 0x1040: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1043:
	/* 0x1043: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1046:
	/* 0x1046: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1049:
	/* 0x1049: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_104c:
	/* 0x104c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1051:
	/* 0x1051: cmp    QWORD PTR [r13+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1059:
	/* 0x1059: je     1102 <trace_security_file_mprotect+0x1102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1102;
	}
x86_l_105f:
	/* 0x105f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1064:
	/* 0x1064: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1066:
	/* 0x1066: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_106a:
	/* 0x106a: mov    rbx,QWORD PTR [r13+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1071:
	/* 0x1071: mov    rax,QWORD PTR [r13+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1078:
	/* 0x1078: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1080:
	/* 0x1080: mov    rbp,QWORD PTR [r13+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_1087:
	/* 0x1087: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_108a:
	/* 0x108a: mov    r13,QWORD PTR [r13+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_1091:
	/* 0x1091: movzx  eax,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1099:
	/* 0x1099: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109e:
	/* 0x109e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_10a5:
	/* 0x10a5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10aa:
	/* 0x10aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10af:
	/* 0x10af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b1:
	/* 0x10b1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10b4:
	/* 0x10b4: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10b8:
	/* 0x10b8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10bd:
	/* 0x10bd: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10c4:
	/* 0x10c4: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_10c7:
	/* 0x10c7: je     10e6 <trace_security_file_mprotect+0x10e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e6;
	}
x86_l_10c9:
	/* 0x10c9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ce:
	/* 0x10ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d3:
	/* 0x10d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d5:
	/* 0x10d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d8:
	/* 0x10d8: je     10e6 <trace_security_file_mprotect+0x10e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e6;
	}
x86_l_10da:
	/* 0x10da: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10dd:
	/* 0x10dd: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e1:
	/* 0x10e1: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10e4:
	/* 0x10e4: jmp    10e8 <trace_security_file_mprotect+0x10e8> */
	goto x86_l_10e8;
x86_l_10e6:
	/* 0x10e6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e8:
	/* 0x10e8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10eb:
	/* 0x10eb: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10f0:
	/* 0x10f0: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_10f3:
	/* 0x10f3: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: jae    1119 <trace_security_file_mprotect+0x1119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1119;
	}
x86_l_10f8:
	/* 0x10f8: movzx  ebp,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1100:
	/* 0x1100: jmp    1137 <trace_security_file_mprotect+0x1137> */
	goto x86_l_1137;
x86_l_1102:
	/* 0x1102: movzx  ebp,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_110a:
	/* 0x110a: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1112:
	/* 0x1112: jne    1150 <trace_security_file_mprotect+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1150;
	}
x86_l_1114:
	/* 0x1114: jmp    121b <trace_security_file_mprotect+0x121b> */
	goto x86_l_121b;
x86_l_1119:
	/* 0x1119: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_111d:
	/* 0x111d: movzx  ebp,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1125:
	/* 0x1125: je     112c <trace_security_file_mprotect+0x112c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112c;
	}
x86_l_1127:
	/* 0x1127: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: jbe    1137 <trace_security_file_mprotect+0x1137> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1137;
	}
x86_l_112c:
	/* 0x112c: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1134:
	/* 0x1134: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1137:
	/* 0x1137: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_113a:
	/* 0x113a: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_113d:
	/* 0x113d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1142:
	/* 0x1142: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_114a:
	/* 0x114a: je     121b <trace_security_file_mprotect+0x121b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121b;
	}
x86_l_1150:
	/* 0x1150: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1155:
	/* 0x1155: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_115c:
	/* 0x115c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1161:
	/* 0x1161: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1166:
	/* 0x1166: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_116b:
	/* 0x116b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1170:
	/* 0x1170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1172:
	/* 0x1172: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1177:
	/* 0x1177: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_117b:
	/* 0x117b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1180:
	/* 0x1180: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1185:
	/* 0x1185: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_118a:
	/* 0x118a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118f:
	/* 0x118f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1191:
	/* 0x1191: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1196:
	/* 0x1196: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119b:
	/* 0x119b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_11a0:
	/* 0x11a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11a5:
	/* 0x11a5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11aa:
	/* 0x11aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11af:
	/* 0x11af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b1:
	/* 0x11b1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b5:
	/* 0x11b5: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11b9:
	/* 0x11b9: mov    rbx,QWORD PTR [r13+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_11c0:
	/* 0x11c0: mov    r15,QWORD PTR [r13+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_11c7:
	/* 0x11c7: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11cc:
	/* 0x11cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_11d3:
	/* 0x11d3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11d8:
	/* 0x11d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11dd:
	/* 0x11dd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e0:
	/* 0x11e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e2:
	/* 0x11e2: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11e9:
	/* 0x11e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11ec:
	/* 0x11ec: je     120d <trace_security_file_mprotect+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120d;
	}
x86_l_11ee:
	/* 0x11ee: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: lea    rsi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11f5:
	/* 0x11f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11fa:
	/* 0x11fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fc:
	/* 0x11fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: je     120d <trace_security_file_mprotect+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120d;
	}
x86_l_1201:
	/* 0x1201: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1204:
	/* 0x1204: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1208:
	/* 0x1208: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_120b:
	/* 0x120b: jmp    120f <trace_security_file_mprotect+0x120f> */
	goto x86_l_120f;
x86_l_120d:
	/* 0x120d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120f:
	/* 0x120f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1212:
	/* 0x1212: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1215:
	/* 0x1215: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1218:
	/* 0x1218: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_121b:
	/* 0x121b: cmp    QWORD PTR [r13+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1223:
	/* 0x1223: je     1317 <trace_security_file_mprotect+0x1317> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1317;
	}
x86_l_1229:
	/* 0x1229: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1230:
	/* 0x1230: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1234:
	/* 0x1234: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1239:
	/* 0x1239: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_123e:
	/* 0x123e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1243:
	/* 0x1243: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1248:
	/* 0x1248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124a:
	/* 0x124a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_124f:
	/* 0x124f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1254:
	/* 0x1254: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1259:
	/* 0x1259: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_125e:
	/* 0x125e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1263:
	/* 0x1263: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1266:
	/* 0x1266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1268:
	/* 0x1268: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_126c:
	/* 0x126c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1270:
	/* 0x1270: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1274:
	/* 0x1274: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1278:
	/* 0x1278: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127d:
	/* 0x127d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1282:
	/* 0x1282: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1287:
	/* 0x1287: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_128c:
	/* 0x128c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128e:
	/* 0x128e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1293:
	/* 0x1293: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1297:
	/* 0x1297: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_129c:
	/* 0x129c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12a1:
	/* 0x12a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12a6:
	/* 0x12a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12ab:
	/* 0x12ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ad:
	/* 0x12ad: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b1:
	/* 0x12b1: mov    DWORD PTR [r13+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12b5:
	/* 0x12b5: mov    rbx,QWORD PTR [r13+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_12bc:
	/* 0x12bc: mov    r15,QWORD PTR [r13+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_12c3:
	/* 0x12c3: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12c8:
	/* 0x12c8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_12cf:
	/* 0x12cf: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12d4:
	/* 0x12d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d9:
	/* 0x12d9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12dc:
	/* 0x12dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12de:
	/* 0x12de: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12e5:
	/* 0x12e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e8:
	/* 0x12e8: je     1309 <trace_security_file_mprotect+0x1309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1309;
	}
x86_l_12ea:
	/* 0x12ea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12ed:
	/* 0x12ed: lea    rsi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12f1:
	/* 0x12f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f6:
	/* 0x12f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f8:
	/* 0x12f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: je     1309 <trace_security_file_mprotect+0x1309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1309;
	}
x86_l_12fd:
	/* 0x12fd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1300:
	/* 0x1300: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1304:
	/* 0x1304: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1307:
	/* 0x1307: jmp    130b <trace_security_file_mprotect+0x130b> */
	goto x86_l_130b;
x86_l_1309:
	/* 0x1309: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130b:
	/* 0x130b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_130e:
	/* 0x130e: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1311:
	/* 0x1311: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1314:
	/* 0x1314: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1317:
	/* 0x1317: cmp    QWORD PTR [r13+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_131f:
	/* 0x131f: je     1401 <trace_security_file_mprotect+0x1401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1401;
	}
x86_l_1325:
	/* 0x1325: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_132a:
	/* 0x132a: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1331:
	/* 0x1331: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1336:
	/* 0x1336: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_133b:
	/* 0x133b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1340:
	/* 0x1340: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1345:
	/* 0x1345: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1347:
	/* 0x1347: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_134c:
	/* 0x134c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1351:
	/* 0x1351: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1356:
	/* 0x1356: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_135b:
	/* 0x135b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1360:
	/* 0x1360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1362:
	/* 0x1362: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1367:
	/* 0x1367: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_136c:
	/* 0x136c: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1371:
	/* 0x1371: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1376:
	/* 0x1376: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1379:
	/* 0x1379: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_137e:
	/* 0x137e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1380:
	/* 0x1380: lea    rbx,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1384:
	/* 0x1384: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1389:
	/* 0x1389: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_138e:
	/* 0x138e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1391:
	/* 0x1391: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1396:
	/* 0x1396: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1399:
	/* 0x1399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139b:
	/* 0x139b: mov    r15,QWORD PTR [r13+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_13a2:
	/* 0x13a2: mov    r13,QWORD PTR [r13+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_13a9:
	/* 0x13a9: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ae:
	/* 0x13ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_13b5:
	/* 0x13b5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ba:
	/* 0x13ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13bf:
	/* 0x13bf: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13c2:
	/* 0x13c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c4:
	/* 0x13c4: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13cb:
	/* 0x13cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ce:
	/* 0x13ce: je     13ee <trace_security_file_mprotect+0x13ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ee;
	}
x86_l_13d0:
	/* 0x13d0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13d3:
	/* 0x13d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d8:
	/* 0x13d8: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e0:
	/* 0x13e0: je     13ee <trace_security_file_mprotect+0x13ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ee;
	}
x86_l_13e2:
	/* 0x13e2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e5:
	/* 0x13e5: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e9:
	/* 0x13e9: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13ec:
	/* 0x13ec: jmp    13f0 <trace_security_file_mprotect+0x13f0> */
	goto x86_l_13f0;
x86_l_13ee:
	/* 0x13ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f0:
	/* 0x13f0: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13f3:
	/* 0x13f3: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13f6:
	/* 0x13f6: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_13f9:
	/* 0x13f9: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_13fc:
	/* 0x13fc: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1401:
	/* 0x1401: cmp    QWORD PTR [r13+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1409:
	/* 0x1409: je     148d <trace_security_file_mprotect+0x148d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148d;
	}
x86_l_140f:
	/* 0x140f: lea    rbx,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1413:
	/* 0x1413: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1418:
	/* 0x1418: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_141d:
	/* 0x141d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1420:
	/* 0x1420: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1425:
	/* 0x1425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1427:
	/* 0x1427: mov    r15,QWORD PTR [r13+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_142e:
	/* 0x142e: mov    r13,QWORD PTR [r13+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1435:
	/* 0x1435: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_143a:
	/* 0x143a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1441:
	/* 0x1441: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1446:
	/* 0x1446: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144b:
	/* 0x144b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_144e:
	/* 0x144e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1450:
	/* 0x1450: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1457:
	/* 0x1457: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145a:
	/* 0x145a: je     147a <trace_security_file_mprotect+0x147a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147a;
	}
x86_l_145c:
	/* 0x145c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_145f:
	/* 0x145f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1464:
	/* 0x1464: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1467:
	/* 0x1467: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1469:
	/* 0x1469: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146c:
	/* 0x146c: je     147a <trace_security_file_mprotect+0x147a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147a;
	}
x86_l_146e:
	/* 0x146e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1471:
	/* 0x1471: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1475:
	/* 0x1475: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1478:
	/* 0x1478: jmp    147c <trace_security_file_mprotect+0x147c> */
	goto x86_l_147c;
x86_l_147a:
	/* 0x147a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147c:
	/* 0x147c: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_147f:
	/* 0x147f: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1482:
	/* 0x1482: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1485:
	/* 0x1485: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1488:
	/* 0x1488: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_148d:
	/* 0x148d: mov    rbx,QWORD PTR [r13+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1494:
	/* 0x1494: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1497:
	/* 0x1497: je     14fd <trace_security_file_mprotect+0x14fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14fd;
	}
x86_l_1499:
	/* 0x1499: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_149d:
	/* 0x149d: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14a1:
	/* 0x14a1: mov    r15,QWORD PTR [r13+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_14a8:
	/* 0x14a8: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ad:
	/* 0x14ad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_14b4:
	/* 0x14b4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b9:
	/* 0x14b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14be:
	/* 0x14be: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14c1:
	/* 0x14c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c3:
	/* 0x14c3: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14ca:
	/* 0x14ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14cd:
	/* 0x14cd: je     14ef <trace_security_file_mprotect+0x14ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ef;
	}
x86_l_14cf:
	/* 0x14cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14d7:
	/* 0x14d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14dc:
	/* 0x14dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14de:
	/* 0x14de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e1:
	/* 0x14e1: je     14ef <trace_security_file_mprotect+0x14ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ef;
	}
x86_l_14e3:
	/* 0x14e3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e6:
	/* 0x14e6: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ea:
	/* 0x14ea: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14ed:
	/* 0x14ed: jmp    14f1 <trace_security_file_mprotect+0x14f1> */
	goto x86_l_14f1;
x86_l_14ef:
	/* 0x14ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f1:
	/* 0x14f1: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14f4:
	/* 0x14f4: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_14f7:
	/* 0x14f7: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14fa:
	/* 0x14fa: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_14fd:
	/* 0x14fd: mov    rbx,QWORD PTR [r13+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1504:
	/* 0x1504: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1507:
	/* 0x1507: je     1568 <trace_security_file_mprotect+0x1568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1568;
	}
x86_l_1509:
	/* 0x1509: mov    r15,QWORD PTR [r13+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1510:
	/* 0x1510: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1515:
	/* 0x1515: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_151c:
	/* 0x151c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1521:
	/* 0x1521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1526:
	/* 0x1526: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1529:
	/* 0x1529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152b:
	/* 0x152b: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1532:
	/* 0x1532: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1535:
	/* 0x1535: je     155a <trace_security_file_mprotect+0x155a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155a;
	}
x86_l_1537:
	/* 0x1537: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_153a:
	/* 0x153a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153f:
	/* 0x153f: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1547:
	/* 0x1547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1549:
	/* 0x1549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154c:
	/* 0x154c: je     155a <trace_security_file_mprotect+0x155a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155a;
	}
x86_l_154e:
	/* 0x154e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1551:
	/* 0x1551: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1555:
	/* 0x1555: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1558:
	/* 0x1558: jmp    155c <trace_security_file_mprotect+0x155c> */
	goto x86_l_155c;
x86_l_155a:
	/* 0x155a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155c:
	/* 0x155c: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_155f:
	/* 0x155f: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1562:
	/* 0x1562: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1565:
	/* 0x1565: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1568:
	/* 0x1568: mov    r15,QWORD PTR [r13+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_156f:
	/* 0x156f: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1572:
	/* 0x1572: je     15fe <trace_security_file_mprotect+0x15fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5630ULL;
	}
x86_l_1578:
	/* 0x1578: mov    r13,QWORD PTR [r13+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_157f:
	/* 0x157f: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1584:
	/* 0x1584: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_158b:
	/* 0x158b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 5520ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5530ULL: goto x86_l_159a;
	case 5537ULL: goto x86_l_15a1;
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5557ULL: goto x86_l_15b5;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5567ULL: goto x86_l_15bf;
	case 5570ULL: goto x86_l_15c2;
	case 5572ULL: goto x86_l_15c4;
	case 5580ULL: goto x86_l_15cc;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5592ULL: goto x86_l_15d8;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5599ULL: goto x86_l_15df;
	case 5602ULL: goto x86_l_15e2;
	case 5606ULL: goto x86_l_15e6;
	case 5609ULL: goto x86_l_15e9;
	case 5611ULL: goto x86_l_15eb;
	case 5613ULL: goto x86_l_15ed;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5637ULL: goto x86_l_1605;
	case 5640ULL: goto x86_l_1608;
	case 5648ULL: goto x86_l_1610;
	case 5656ULL: goto x86_l_1618;
	case 5658ULL: goto x86_l_161a;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5673ULL: goto x86_l_1629;
	case 5680ULL: goto x86_l_1630;
	case 5687ULL: goto x86_l_1637;
	case 5691ULL: goto x86_l_163b;
	case 5699ULL: goto x86_l_1643;
	case 5706ULL: goto x86_l_164a;
	case 5714ULL: goto x86_l_1652;
	case 5720ULL: goto x86_l_1658;
	case 5728ULL: goto x86_l_1660;
	case 5737ULL: goto x86_l_1669;
	case 5746ULL: goto x86_l_1672;
	case 5755ULL: goto x86_l_167b;
	case 5764ULL: goto x86_l_1684;
	case 5773ULL: goto x86_l_168d;
	case 5782ULL: goto x86_l_1696;
	case 5791ULL: goto x86_l_169f;
	case 5800ULL: goto x86_l_16a8;
	case 5806ULL: goto x86_l_16ae;
	case 5814ULL: goto x86_l_16b6;
	case 5821ULL: goto x86_l_16bd;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5836ULL: goto x86_l_16cc;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5853ULL: goto x86_l_16dd;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5872ULL: goto x86_l_16f0;
	case 5877ULL: goto x86_l_16f5;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5927ULL: goto x86_l_1727;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5962ULL: goto x86_l_174a;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6075ULL: goto x86_l_17bb;
	case 6081ULL: goto x86_l_17c1;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6124ULL: goto x86_l_17ec;
	case 6126ULL: goto x86_l_17ee;
	case 6128ULL: goto x86_l_17f0;
	case 6134ULL: goto x86_l_17f6;
	case 6137ULL: goto x86_l_17f9;
	case 6142ULL: goto x86_l_17fe;
	case 6144ULL: goto x86_l_1800;
	case 6147ULL: goto x86_l_1803;
	case 6153ULL: goto x86_l_1809;
	case 6160ULL: goto x86_l_1810;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6223ULL: goto x86_l_184f;
	case 6226ULL: goto x86_l_1852;
	case 6232ULL: goto x86_l_1858;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6247ULL: goto x86_l_1867;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6270ULL: goto x86_l_187e;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6285ULL: goto x86_l_188d;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6460ULL: goto x86_l_193c;
	case 6464ULL: goto x86_l_1940;
	case 6466ULL: goto x86_l_1942;
	case 6472ULL: goto x86_l_1948;
	case 6475ULL: goto x86_l_194b;
	case 6477ULL: goto x86_l_194d;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6547ULL: goto x86_l_1993;
	case 6554ULL: goto x86_l_199a;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6637ULL: goto x86_l_19ed;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6680ULL: goto x86_l_1a18;
	case 6689ULL: goto x86_l_1a21;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6827ULL: goto x86_l_1aab;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6878ULL: goto x86_l_1ade;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6956ULL: goto x86_l_1b2c;
	case 6961ULL: goto x86_l_1b31;
	case 6966ULL: goto x86_l_1b36;
	case 6969ULL: goto x86_l_1b39;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7024ULL: goto x86_l_1b70;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7050ULL: goto x86_l_1b8a;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7084ULL: goto x86_l_1bac;
	case 7089ULL: goto x86_l_1bb1;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7123ULL: goto x86_l_1bd3;
	case 7131ULL: goto x86_l_1bdb;
	case 7142ULL: goto x86_l_1be6;
	case 7150ULL: goto x86_l_1bee;
	case 7158ULL: goto x86_l_1bf6;
	case 7166ULL: goto x86_l_1bfe;
	case 7172ULL: goto x86_l_1c04;
	case 7178ULL: goto x86_l_1c0a;
	case 7187ULL: goto x86_l_1c13;
	case 7195ULL: goto x86_l_1c1b;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7211ULL: goto x86_l_1c2b;
	case 7215ULL: goto x86_l_1c2f;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7261ULL: goto x86_l_1c5d;
	case 7263ULL: goto x86_l_1c5f;
	case 7265ULL: goto x86_l_1c61;
	case 7273ULL: goto x86_l_1c69;
	case 7280ULL: goto x86_l_1c70;
	case 7282ULL: goto x86_l_1c72;
	case 7290ULL: goto x86_l_1c7a;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7309ULL: goto x86_l_1c8d;
	case 7316ULL: goto x86_l_1c94;
	case 7324ULL: goto x86_l_1c9c;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1590:
	/* 0x1590: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1595:
	/* 0x1595: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1598:
	/* 0x1598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159a:
	/* 0x159a: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15a1:
	/* 0x15a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a4:
	/* 0x15a4: je     15eb <trace_security_file_mprotect+0x15eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15eb;
	}
x86_l_15a6:
	/* 0x15a6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15a9:
	/* 0x15a9: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15b1:
	/* 0x15b1: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15b5:
	/* 0x15b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ba:
	/* 0x15ba: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15bd:
	/* 0x15bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bf:
	/* 0x15bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15c2:
	/* 0x15c2: jne    15df <trace_security_file_mprotect+0x15df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15df;
	}
x86_l_15c4:
	/* 0x15c4: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15cc:
	/* 0x15cc: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d0:
	/* 0x15d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d5:
	/* 0x15d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15d8:
	/* 0x15d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15da:
	/* 0x15da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15dd:
	/* 0x15dd: je     15eb <trace_security_file_mprotect+0x15eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15eb;
	}
x86_l_15df:
	/* 0x15df: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e2:
	/* 0x15e2: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e6:
	/* 0x15e6: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15e9:
	/* 0x15e9: jmp    15ed <trace_security_file_mprotect+0x15ed> */
	goto x86_l_15ed;
x86_l_15eb:
	/* 0x15eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ed:
	/* 0x15ed: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_15f0:
	/* 0x15f0: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_15f3:
	/* 0x15f3: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15f6:
	/* 0x15f6: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_15f9:
	/* 0x15f9: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15fe:
	/* 0x15fe: mov    rax,QWORD PTR [r13+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1605:
	/* 0x1605: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1608:
	/* 0x1608: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1610:
	/* 0x1610: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1618:
	/* 0x1618: je     1629 <trace_security_file_mprotect+0x1629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1629;
	}
x86_l_161a:
	/* 0x161a: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1622:
	/* 0x1622: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1626:
	/* 0x1626: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1629:
	/* 0x1629: and    r12,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1630:
	/* 0x1630: lea    rcx,[r13+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1637:
	/* 0x1637: lea    rax,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_163b:
	/* 0x163b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1643:
	/* 0x1643: and    QWORD PTR [r13+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_164a:
	/* 0x164a: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1652:
	/* 0x1652: je     243a <trace_security_file_mprotect+0x243a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9274ULL;
	}
x86_l_1658:
	/* 0x1658: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1660:
	/* 0x1660: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1669:
	/* 0x1669: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1672:
	/* 0x1672: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_167b:
	/* 0x167b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1684:
	/* 0x1684: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_168d:
	/* 0x168d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1696:
	/* 0x1696: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_169f:
	/* 0x169f: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_16a8:
	/* 0x16a8: je     1823 <trace_security_file_mprotect+0x1823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1823;
	}
x86_l_16ae:
	/* 0x16ae: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16b6:
	/* 0x16b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_16bd:
	/* 0x16bd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x16cc: je     1832 <trace_security_file_mprotect+0x1832> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1832;
	}
x86_l_16d2:
	/* 0x16d2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16dd:
	/* 0x16dd: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e1:
	/* 0x16e1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e6:
	/* 0x16e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16eb:
	/* 0x16eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16f0:
	/* 0x16f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f5:
	/* 0x16f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f7:
	/* 0x16f7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16fc:
	/* 0x16fc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1701:
	/* 0x1701: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1706:
	/* 0x1706: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_170b:
	/* 0x170b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1710:
	/* 0x1710: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1715:
	/* 0x1715: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_171a:
	/* 0x171a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171c:
	/* 0x171c: test   BYTE PTR [rsp+0x10],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476768ULL);
x86_l_1721:
	/* 0x1721: jne    1839 <trace_security_file_mprotect+0x1839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1839;
	}
x86_l_1727:
	/* 0x1727: lea    rdx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172b:
	/* 0x172b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1730:
	/* 0x1730: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1735:
	/* 0x1735: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173f:
	/* 0x173f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1741:
	/* 0x1741: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1746:
	/* 0x1746: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_174a:
	/* 0x174a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174e:
	/* 0x174e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1753:
	/* 0x1753: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1758:
	/* 0x1758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_175d:
	/* 0x175d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1761:
	/* 0x1761: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1766:
	/* 0x1766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1768:
	/* 0x1768: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176d:
	/* 0x176d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1772:
	/* 0x1772: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1777:
	/* 0x1777: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177c:
	/* 0x177c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1781:
	/* 0x1781: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1786:
	/* 0x1786: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178b:
	/* 0x178b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_178f:
	/* 0x178f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1794:
	/* 0x1794: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1799:
	/* 0x1799: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_179e:
	/* 0x179e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17a3:
	/* 0x17a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a5:
	/* 0x17a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17aa:
	/* 0x17aa: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_17ad:
	/* 0x17ad: je     184f <trace_security_file_mprotect+0x184f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_184f;
	}
x86_l_17b3:
	/* 0x17b3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b8:
	/* 0x17b8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_17bb:
	/* 0x17bb: je     184f <trace_security_file_mprotect+0x184f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_184f;
	}
x86_l_17c1:
	/* 0x17c1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17c5:
	/* 0x17c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ca:
	/* 0x17ca: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_17cf:
	/* 0x17cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17d4:
	/* 0x17d4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17d9:
	/* 0x17d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17db:
	/* 0x17db: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17df:
	/* 0x17df: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17e4:
	/* 0x17e4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_17e6:
	/* 0x17e6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ec:
	/* 0x17ec: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_17ee:
	/* 0x17ee: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_17f0:
	/* 0x17f0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_17f6:
	/* 0x17f6: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17f9:
	/* 0x17f9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_17fe:
	/* 0x17fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1800:
	/* 0x1800: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1803:
	/* 0x1803: jl     19a0 <trace_security_file_mprotect+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_19a0;
	}
x86_l_1809:
	/* 0x1809: mov    BYTE PTR [rbx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_1810:
	/* 0x1810: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_1816:
	/* 0x1816: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1819:
	/* 0x1819: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_181e:
	/* 0x181e: jmp    18d1 <trace_security_file_mprotect+0x18d1> */
	goto x86_l_18d1;
x86_l_1823:
	/* 0x1823: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1826:
	/* 0x1826: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1828:
	/* 0x1828: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182b:
	/* 0x182b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182d:
	/* 0x182d: jmp    1b70 <trace_security_file_mprotect+0x1b70> */
	goto x86_l_1b70;
x86_l_1832:
	/* 0x1832: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1834:
	/* 0x1834: jmp    19e5 <trace_security_file_mprotect+0x19e5> */
	goto x86_l_19e5;
x86_l_1839:
	/* 0x1839: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1840:
	/* 0x1840: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1845:
	/* 0x1845: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_184a:
	/* 0x184a: jmp    19ce <trace_security_file_mprotect+0x19ce> */
	goto x86_l_19ce;
x86_l_184f:
	/* 0x184f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1852:
	/* 0x1852: jne    19a0 <trace_security_file_mprotect+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a0;
	}
x86_l_1858:
	/* 0x1858: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_185c:
	/* 0x185c: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1861:
	/* 0x1861: je     19a0 <trace_security_file_mprotect+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a0;
	}
x86_l_1867:
	/* 0x1867: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_186b:
	/* 0x186b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1870:
	/* 0x1870: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1875:
	/* 0x1875: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_187a:
	/* 0x187a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187e:
	/* 0x187e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1882:
	/* 0x1882: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1887:
	/* 0x1887: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1889:
	/* 0x1889: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188d:
	/* 0x188d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1890:
	/* 0x1890: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1895:
	/* 0x1895: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_189a:
	/* 0x189a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189e:
	/* 0x189e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18a3:
	/* 0x18a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a5:
	/* 0x18a5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18ae:
	/* 0x18ae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b3:
	/* 0x18b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18b8:
	/* 0x18b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18bc:
	/* 0x18bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c1:
	/* 0x18c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c3:
	/* 0x18c3: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18c7:
	/* 0x18c7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18cb:
	/* 0x18cb: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_18d1:
	/* 0x18d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18d6:
	/* 0x18d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18db:
	/* 0x18db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18e0:
	/* 0x18e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18e5:
	/* 0x18e5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18e8:
	/* 0x18e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ea:
	/* 0x18ea: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ef:
	/* 0x18ef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f4:
	/* 0x18f4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18f8:
	/* 0x18f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18fd:
	/* 0x18fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1902:
	/* 0x1902: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1907:
	/* 0x1907: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190c:
	/* 0x190c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190e:
	/* 0x190e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1913:
	/* 0x1913: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1916:
	/* 0x1916: je     198a <trace_security_file_mprotect+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198a;
	}
x86_l_1918:
	/* 0x1918: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_191d:
	/* 0x191d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1920:
	/* 0x1920: je     198a <trace_security_file_mprotect+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198a;
	}
x86_l_1922:
	/* 0x1922: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1926:
	/* 0x1926: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192b:
	/* 0x192b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1930:
	/* 0x1930: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1935:
	/* 0x1935: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_193a:
	/* 0x193a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193c:
	/* 0x193c: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1940:
	/* 0x1940: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1942:
	/* 0x1942: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1948:
	/* 0x1948: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_194b:
	/* 0x194b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_194d:
	/* 0x194d: jb     31c0 <trace_security_file_mprotect+0x31c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12736ULL;
	}
x86_l_1953:
	/* 0x1953: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1958:
	/* 0x1958: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_195e:
	/* 0x195e: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1961:
	/* 0x1961: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1963:
	/* 0x1963: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1968:
	/* 0x1968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196a:
	/* 0x196a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_196d:
	/* 0x196d: jl     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1993;
	}
x86_l_196f:
	/* 0x196f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1973:
	/* 0x1973: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1979:
	/* 0x1979: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_197d:
	/* 0x197d: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1980:
	/* 0x1980: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1985:
	/* 0x1985: jmp    313e <trace_security_file_mprotect+0x313e> */
	return 12606ULL;
x86_l_198a:
	/* 0x198a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_198d:
	/* 0x198d: je     30cb <trace_security_file_mprotect+0x30cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12491ULL;
	}
x86_l_1993:
	/* 0x1993: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_199a:
	/* 0x199a: jne    31c0 <trace_security_file_mprotect+0x31c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12736ULL;
	}
x86_l_19a0:
	/* 0x19a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a5:
	/* 0x19a5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19a9:
	/* 0x19a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ae:
	/* 0x19ae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_19b3:
	/* 0x19b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19b8:
	/* 0x19b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_19bd:
	/* 0x19bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bf:
	/* 0x19bf: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c4:
	/* 0x19c4: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_19c9:
	/* 0x19c9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19ce:
	/* 0x19ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19d1:
	/* 0x19d1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19d6:
	/* 0x19d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d8:
	/* 0x19d8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19db:
	/* 0x19db: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19e2:
	/* 0x19e2: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19e5:
	/* 0x19e5: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19ed:
	/* 0x19ed: lea    rbp,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f1:
	/* 0x19f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f6:
	/* 0x19f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19fb:
	/* 0x19fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a00:
	/* 0x1a00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a05:
	/* 0x1a05: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a08:
	/* 0x1a08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0a:
	/* 0x1a0a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a18:
	/* 0x1a18: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a21:
	/* 0x1a21: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a25:
	/* 0x1a25: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a34:
	/* 0x1a34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a39:
	/* 0x1a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3b:
	/* 0x1a3b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a40:
	/* 0x1a40: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a45:
	/* 0x1a45: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1a49:
	/* 0x1a49: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a4e:
	/* 0x1a4e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a53:
	/* 0x1a53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a58:
	/* 0x1a58: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a5d:
	/* 0x1a5d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a62:
	/* 0x1a62: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a66:
	/* 0x1a66: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a6b:
	/* 0x1a6b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a70:
	/* 0x1a70: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a75:
	/* 0x1a75: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a84:
	/* 0x1a84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a86:
	/* 0x1a86: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8b:
	/* 0x1a8b: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1a8e:
	/* 0x1a8e: js     1ab9 <trace_security_file_mprotect+0x1ab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ab9;
	}
x86_l_1a90:
	/* 0x1a90: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a95:
	/* 0x1a95: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa9:
	/* 0x1aa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aab:
	/* 0x1aab: imul   r15,r14,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R15, X86_R14, X86_WIDTH_64, 1000000000ULL);
x86_l_1ab2:
	/* 0x1ab2: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ab7:
	/* 0x1ab7: jmp    1abc <trace_security_file_mprotect+0x1abc> */
	goto x86_l_1abc;
x86_l_1ab9:
	/* 0x1ab9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1abc:
	/* 0x1abc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1acb:
	/* 0x1acb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ad3:
	/* 0x1ad3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad5:
	/* 0x1ad5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ada:
	/* 0x1ada: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ade:
	/* 0x1ade: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aed:
	/* 0x1aed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af2:
	/* 0x1af2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1af6:
	/* 0x1af6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1afb:
	/* 0x1afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1afd:
	/* 0x1afd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b02:
	/* 0x1b02: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b07:
	/* 0x1b07: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b11:
	/* 0x1b11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b16:
	/* 0x1b16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b1b:
	/* 0x1b1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1d:
	/* 0x1b1d: mov    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b22:
	/* 0x1b22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b27:
	/* 0x1b27: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b31:
	/* 0x1b31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b36:
	/* 0x1b36: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b39:
	/* 0x1b39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3b:
	/* 0x1b3b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b40:
	/* 0x1b40: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b44:
	/* 0x1b44: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b49:
	/* 0x1b49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b53:
	/* 0x1b53: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b58:
	/* 0x1b58: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b61:
	/* 0x1b61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b63:
	/* 0x1b63: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b68:
	/* 0x1b68: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1b70:
	/* 0x1b70: mov    QWORD PTR [rsp+0xf0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1b78:
	/* 0x1b78: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b82:
	/* 0x1b82: mov    QWORD PTR [rsp+0xf8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1b92:
	/* 0x1b92: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b97:
	/* 0x1b97: mov    QWORD PTR [rsp+0x108],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1bac:
	/* 0x1bac: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    QWORD PTR [rsp+0x120],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    QWORD PTR [rsp+0x128],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    DWORD PTR [rsp+0x130],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    DWORD PTR [rsp+0x134],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_1be6:
	/* 0x1be6: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_1bee:
	/* 0x1bee: mov    QWORD PTR [rsp+0x140],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1bf6:
	/* 0x1bf6: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bfe:
	/* 0x1bfe: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1c04:
	/* 0x1c04: ja     1c94 <trace_security_file_mprotect+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c94;
	}
x86_l_1c0a:
	/* 0x1c0a: mov    BYTE PTR [r13+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1c13:
	/* 0x1c13: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    WORD PTR [r13+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1c23:
	/* 0x1c23: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1c29:
	/* 0x1c29: ja     1c94 <trace_security_file_mprotect+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c94;
	}
x86_l_1c2b:
	/* 0x1c2b: lea    rcx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1c2f:
	/* 0x1c2f: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1c36:
	/* 0x1c36: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1c3b:
	/* 0x1c3b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c40:
	/* 0x1c40: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c48:
	/* 0x1c48: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1c4c:
	/* 0x1c4c: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1c53:
	/* 0x1c53: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c58:
	/* 0x1c58: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5d:
	/* 0x1c5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c5f:
	/* 0x1c5f: jle    1c94 <trace_security_file_mprotect+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c94;
	}
x86_l_1c61:
	/* 0x1c61: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c69:
	/* 0x1c69: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1c70:
	/* 0x1c70: ja     1c94 <trace_security_file_mprotect+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c94;
	}
x86_l_1c72:
	/* 0x1c72: mov    DWORD PTR [rcx+r13*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_1c7a:
	/* 0x1c7a: add    ax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c82:
	/* 0x1c82: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1c85:
	/* 0x1c85: mov    WORD PTR [r13+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c8d:
	/* 0x1c8d: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1c94:
	/* 0x1c94: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c9c:
	/* 0x1c9c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1ca3:
	/* 0x1ca3: ja     1cf1 <trace_security_file_mprotect+0x1cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7409ULL;
	}
x86_l_1ca5:
	/* 0x1ca5: mov    BYTE PTR [r13+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
	return 7342ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7342ULL: goto x86_l_1cae;
	case 7348ULL: goto x86_l_1cb4;
	case 7350ULL: goto x86_l_1cb6;
	case 7354ULL: goto x86_l_1cba;
	case 7361ULL: goto x86_l_1cc1;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7391ULL: goto x86_l_1cdf;
	case 7394ULL: goto x86_l_1ce2;
	case 7402ULL: goto x86_l_1cea;
	case 7409ULL: goto x86_l_1cf1;
	case 7417ULL: goto x86_l_1cf9;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7435ULL: goto x86_l_1d0b;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7451ULL: goto x86_l_1d1b;
	case 7455ULL: goto x86_l_1d1f;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7482ULL: goto x86_l_1d3a;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7495ULL: goto x86_l_1d47;
	case 7502ULL: goto x86_l_1d4e;
	case 7510ULL: goto x86_l_1d56;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7528ULL: goto x86_l_1d68;
	case 7534ULL: goto x86_l_1d6e;
	case 7536ULL: goto x86_l_1d70;
	case 7540ULL: goto x86_l_1d74;
	case 7547ULL: goto x86_l_1d7b;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7588ULL: goto x86_l_1da4;
	case 7595ULL: goto x86_l_1dab;
	case 7603ULL: goto x86_l_1db3;
	case 7610ULL: goto x86_l_1dba;
	case 7612ULL: goto x86_l_1dbc;
	case 7621ULL: goto x86_l_1dc5;
	case 7627ULL: goto x86_l_1dcb;
	case 7629ULL: goto x86_l_1dcd;
	case 7633ULL: goto x86_l_1dd1;
	case 7640ULL: goto x86_l_1dd8;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7668ULL: goto x86_l_1df4;
	case 7670ULL: goto x86_l_1df6;
	case 7673ULL: goto x86_l_1df9;
	case 7681ULL: goto x86_l_1e01;
	case 7688ULL: goto x86_l_1e08;
	case 7696ULL: goto x86_l_1e10;
	case 7703ULL: goto x86_l_1e17;
	case 7705ULL: goto x86_l_1e19;
	case 7714ULL: goto x86_l_1e22;
	case 7720ULL: goto x86_l_1e28;
	case 7722ULL: goto x86_l_1e2a;
	case 7726ULL: goto x86_l_1e2e;
	case 7733ULL: goto x86_l_1e35;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7763ULL: goto x86_l_1e53;
	case 7766ULL: goto x86_l_1e56;
	case 7774ULL: goto x86_l_1e5e;
	case 7781ULL: goto x86_l_1e65;
	case 7789ULL: goto x86_l_1e6d;
	case 7795ULL: goto x86_l_1e73;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7822ULL: goto x86_l_1e8e;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7831ULL: goto x86_l_1e97;
	case 7835ULL: goto x86_l_1e9b;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7854ULL: goto x86_l_1eae;
	case 7858ULL: goto x86_l_1eb2;
	case 7866ULL: goto x86_l_1eba;
	case 7873ULL: goto x86_l_1ec1;
	case 7875ULL: goto x86_l_1ec3;
	case 7884ULL: goto x86_l_1ecc;
	case 7890ULL: goto x86_l_1ed2;
	case 7892ULL: goto x86_l_1ed4;
	case 7896ULL: goto x86_l_1ed8;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7925ULL: goto x86_l_1ef5;
	case 7928ULL: goto x86_l_1ef8;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7941ULL: goto x86_l_1f05;
	case 7948ULL: goto x86_l_1f0c;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7997ULL: goto x86_l_1f3d;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8054ULL: goto x86_l_1f76;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8085ULL: goto x86_l_1f95;
	case 8089ULL: goto x86_l_1f99;
	case 8093ULL: goto x86_l_1f9d;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8122ULL: goto x86_l_1fba;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8155ULL: goto x86_l_1fdb;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8197ULL: goto x86_l_2005;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8224ULL: goto x86_l_2020;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8235ULL: goto x86_l_202b;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8291ULL: goto x86_l_2063;
	case 8295ULL: goto x86_l_2067;
	case 8299ULL: goto x86_l_206b;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8356ULL: goto x86_l_20a4;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8388ULL: goto x86_l_20c4;
	case 8392ULL: goto x86_l_20c8;
	case 8396ULL: goto x86_l_20cc;
	case 8400ULL: goto x86_l_20d0;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8476ULL: goto x86_l_211c;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8491ULL: goto x86_l_212b;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8525ULL: goto x86_l_214d;
	case 8529ULL: goto x86_l_2151;
	case 8533ULL: goto x86_l_2155;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8547ULL: goto x86_l_2163;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8650ULL: goto x86_l_21ca;
	case 8652ULL: goto x86_l_21cc;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8664ULL: goto x86_l_21d8;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8694ULL: goto x86_l_21f6;
	case 8698ULL: goto x86_l_21fa;
	case 8702ULL: goto x86_l_21fe;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8801ULL: goto x86_l_2261;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8816ULL: goto x86_l_2270;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8851ULL: goto x86_l_2293;
	case 8859ULL: goto x86_l_229b;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8885ULL: goto x86_l_22b5;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8980ULL: goto x86_l_2314;
	case 8984ULL: goto x86_l_2318;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9032ULL: goto x86_l_2348;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cae:
	/* 0x1cae: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1cb4:
	/* 0x1cb4: ja     1cf1 <trace_security_file_mprotect+0x1cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cf1;
	}
x86_l_1cb6:
	/* 0x1cb6: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1cba:
	/* 0x1cba: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1cc1:
	/* 0x1cc1: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cce:
	/* 0x1cce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd8:
	/* 0x1cd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cda:
	/* 0x1cda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cdd:
	/* 0x1cdd: js     1cf1 <trace_security_file_mprotect+0x1cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cf1;
	}
x86_l_1cdf:
	/* 0x1cdf: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cea:
	/* 0x1cea: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1cf1:
	/* 0x1cf1: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cf9:
	/* 0x1cf9: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1d00:
	/* 0x1d00: ja     1d4e <trace_security_file_mprotect+0x1d4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4e;
	}
x86_l_1d02:
	/* 0x1d02: mov    BYTE PTR [r13+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1d0b:
	/* 0x1d0b: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1d11:
	/* 0x1d11: ja     1d4e <trace_security_file_mprotect+0x1d4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4e;
	}
x86_l_1d13:
	/* 0x1d13: lea    rdx,[rsp+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1d1b:
	/* 0x1d1b: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1d1f:
	/* 0x1d1f: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1d26:
	/* 0x1d26: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d30:
	/* 0x1d30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d35:
	/* 0x1d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d37:
	/* 0x1d37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d3a:
	/* 0x1d3a: js     1d4e <trace_security_file_mprotect+0x1d4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d4e;
	}
x86_l_1d3c:
	/* 0x1d3c: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d47:
	/* 0x1d47: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d4e:
	/* 0x1d4e: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d56:
	/* 0x1d56: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1d5d:
	/* 0x1d5d: ja     1dab <trace_security_file_mprotect+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dab;
	}
x86_l_1d5f:
	/* 0x1d5f: mov    BYTE PTR [r13+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1d68:
	/* 0x1d68: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1d6e:
	/* 0x1d6e: ja     1dab <trace_security_file_mprotect+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dab;
	}
x86_l_1d70:
	/* 0x1d70: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1d74:
	/* 0x1d74: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1d7b:
	/* 0x1d7b: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1d83:
	/* 0x1d83: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d88:
	/* 0x1d88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d92:
	/* 0x1d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d94:
	/* 0x1d94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d97:
	/* 0x1d97: js     1dab <trace_security_file_mprotect+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dab;
	}
x86_l_1d99:
	/* 0x1d99: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1da4:
	/* 0x1da4: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1dab:
	/* 0x1dab: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1db3:
	/* 0x1db3: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1dba:
	/* 0x1dba: ja     1e08 <trace_security_file_mprotect+0x1e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e08;
	}
x86_l_1dbc:
	/* 0x1dbc: mov    BYTE PTR [r13+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1dc5:
	/* 0x1dc5: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1dcb:
	/* 0x1dcb: ja     1e08 <trace_security_file_mprotect+0x1e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e08;
	}
x86_l_1dcd:
	/* 0x1dcd: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1dd1:
	/* 0x1dd1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1dd8:
	/* 0x1dd8: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1de0:
	/* 0x1de0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1de5:
	/* 0x1de5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dea:
	/* 0x1dea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1def:
	/* 0x1def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df1:
	/* 0x1df1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df4:
	/* 0x1df4: js     1e08 <trace_security_file_mprotect+0x1e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e08;
	}
x86_l_1df6:
	/* 0x1df6: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1df9:
	/* 0x1df9: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e01:
	/* 0x1e01: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e08:
	/* 0x1e08: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e10:
	/* 0x1e10: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1e17:
	/* 0x1e17: ja     1e65 <trace_security_file_mprotect+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e65;
	}
x86_l_1e19:
	/* 0x1e19: mov    BYTE PTR [r13+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_1e22:
	/* 0x1e22: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1e28:
	/* 0x1e28: ja     1e65 <trace_security_file_mprotect+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e65;
	}
x86_l_1e2a:
	/* 0x1e2a: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1e2e:
	/* 0x1e2e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e35:
	/* 0x1e35: lea    rdx,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e42:
	/* 0x1e42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e47:
	/* 0x1e47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e4c:
	/* 0x1e4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4e:
	/* 0x1e4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e51:
	/* 0x1e51: js     1e65 <trace_security_file_mprotect+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e65;
	}
x86_l_1e53:
	/* 0x1e53: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1e56:
	/* 0x1e56: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e5e:
	/* 0x1e5e: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e65:
	/* 0x1e65: cmp    DWORD PTR [r13+0x74],0x149 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206665ULL);
x86_l_1e6d:
	/* 0x1e6d: jne    1f0c <trace_security_file_mprotect+0x1f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f0c;
	}
x86_l_1e73:
	/* 0x1e73: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1e7a:
	/* 0x1e7a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e84:
	/* 0x1e84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e89:
	/* 0x1e89: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e8e:
	/* 0x1e8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e90:
	/* 0x1e90: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1e95:
	/* 0x1e95: jne    1e9d <trace_security_file_mprotect+0x1e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e9d;
	}
x86_l_1e97:
	/* 0x1e97: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e9b:
	/* 0x1e9b: jmp    1eaa <trace_security_file_mprotect+0x1eaa> */
	goto x86_l_1eaa;
x86_l_1e9d:
	/* 0x1e9d: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1ea0:
	/* 0x1ea0: je     273f <trace_security_file_mprotect+0x273f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10047ULL;
	}
x86_l_1ea6:
	/* 0x1ea6: add    rbp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eae:
	/* 0x1eae: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb2:
	/* 0x1eb2: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1eba:
	/* 0x1eba: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1ec1:
	/* 0x1ec1: ja     1f0c <trace_security_file_mprotect+0x1f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f0c;
	}
x86_l_1ec3:
	/* 0x1ec3: mov    BYTE PTR [r13+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_1ecc:
	/* 0x1ecc: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1ed2:
	/* 0x1ed2: ja     1f0c <trace_security_file_mprotect+0x1f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f0c;
	}
x86_l_1ed4:
	/* 0x1ed4: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1ed8:
	/* 0x1ed8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1edf:
	/* 0x1edf: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eee:
	/* 0x1eee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ef3:
	/* 0x1ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef5:
	/* 0x1ef5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ef8:
	/* 0x1ef8: js     1f0c <trace_security_file_mprotect+0x1f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f0c;
	}
x86_l_1efa:
	/* 0x1efa: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1efd:
	/* 0x1efd: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f05:
	/* 0x1f05: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1f0c:
	/* 0x1f0c: mov    rbx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1f13:
	/* 0x1f13: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f17:
	/* 0x1f17: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f1c:
	/* 0x1f1c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f21:
	/* 0x1f21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f26:
	/* 0x1f26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f2e:
	/* 0x1f2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f30:
	/* 0x1f30: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f35:
	/* 0x1f35: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f3d:
	/* 0x1f3d: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f41:
	/* 0x1f41: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f46:
	/* 0x1f46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f50:
	/* 0x1f50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f55:
	/* 0x1f55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f57:
	/* 0x1f57: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f5c:
	/* 0x1f5c: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1f60:
	/* 0x1f60: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f65:
	/* 0x1f65: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f74:
	/* 0x1f74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f76:
	/* 0x1f76: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f7b:
	/* 0x1f7b: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1f7f:
	/* 0x1f7f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f84:
	/* 0x1f84: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f89:
	/* 0x1f89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f93:
	/* 0x1f93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f95:
	/* 0x1f95: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f99:
	/* 0x1f99: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f9d:
	/* 0x1f9d: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fa1:
	/* 0x1fa1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fab:
	/* 0x1fab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fb8:
	/* 0x1fb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fba:
	/* 0x1fba: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_1fbd:
	/* 0x1fbd: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc2:
	/* 0x1fc2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc7:
	/* 0x1fc7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fd1:
	/* 0x1fd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fd6:
	/* 0x1fd6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fd9:
	/* 0x1fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fdb:
	/* 0x1fdb: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fdf:
	/* 0x1fdf: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1fe3:
	/* 0x1fe3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1fe7:
	/* 0x1fe7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1feb:
	/* 0x1feb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ff5:
	/* 0x1ff5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fff:
	/* 0x1fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2001:
	/* 0x2001: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2005:
	/* 0x2005: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2009:
	/* 0x2009: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_200e:
	/* 0x200e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2013:
	/* 0x2013: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2018:
	/* 0x2018: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_201d:
	/* 0x201d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2020:
	/* 0x2020: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2022:
	/* 0x2022: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2027:
	/* 0x2027: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_202b:
	/* 0x202b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2030:
	/* 0x2030: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2035:
	/* 0x2035: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_203a:
	/* 0x203a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_203f:
	/* 0x203f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2041:
	/* 0x2041: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2046:
	/* 0x2046: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_204b:
	/* 0x204b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2050:
	/* 0x2050: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2055:
	/* 0x2055: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_205a:
	/* 0x205a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_205d:
	/* 0x205d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205f:
	/* 0x205f: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2063:
	/* 0x2063: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2067:
	/* 0x2067: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_206b:
	/* 0x206b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_206f:
	/* 0x206f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2074:
	/* 0x2074: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2079:
	/* 0x2079: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_207e:
	/* 0x207e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2083:
	/* 0x2083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2085:
	/* 0x2085: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2089:
	/* 0x2089: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_208d:
	/* 0x208d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2092:
	/* 0x2092: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2097:
	/* 0x2097: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_209c:
	/* 0x209c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a1:
	/* 0x20a1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20a4:
	/* 0x20a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a6:
	/* 0x20a6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20ab:
	/* 0x20ab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20b0:
	/* 0x20b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20b5:
	/* 0x20b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ba:
	/* 0x20ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20bf:
	/* 0x20bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20c2:
	/* 0x20c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c4:
	/* 0x20c4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20c8:
	/* 0x20c8: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_20cc:
	/* 0x20cc: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20d0:
	/* 0x20d0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20d4:
	/* 0x20d4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20d9:
	/* 0x20d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20de:
	/* 0x20de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20e3:
	/* 0x20e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20e8:
	/* 0x20e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ea:
	/* 0x20ea: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20ef:
	/* 0x20ef: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_20f3:
	/* 0x20f3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20f8:
	/* 0x20f8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20fd:
	/* 0x20fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2102:
	/* 0x2102: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2107:
	/* 0x2107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2109:
	/* 0x2109: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_210e:
	/* 0x210e: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2112:
	/* 0x2112: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2117:
	/* 0x2117: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_211c:
	/* 0x211c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2121:
	/* 0x2121: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2126:
	/* 0x2126: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2129:
	/* 0x2129: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212b:
	/* 0x212b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2130:
	/* 0x2130: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2135:
	/* 0x2135: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_213a:
	/* 0x213a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_213f:
	/* 0x213f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2144:
	/* 0x2144: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_214d:
	/* 0x214d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2151:
	/* 0x2151: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2155:
	/* 0x2155: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2159:
	/* 0x2159: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_215e:
	/* 0x215e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2163:
	/* 0x2163: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2168:
	/* 0x2168: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_216d:
	/* 0x216d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216f:
	/* 0x216f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2174:
	/* 0x2174: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2178:
	/* 0x2178: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_217d:
	/* 0x217d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2182:
	/* 0x2182: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2187:
	/* 0x2187: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_218c:
	/* 0x218c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218e:
	/* 0x218e: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_2193:
	/* 0x2193: jne    21fa <trace_security_file_mprotect+0x21fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21fa;
	}
x86_l_2195:
	/* 0x2195: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_219a:
	/* 0x219a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_219f:
	/* 0x219f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21a4:
	/* 0x21a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a9:
	/* 0x21a9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21ac:
	/* 0x21ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ae:
	/* 0x21ae: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b3:
	/* 0x21b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b8:
	/* 0x21b8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21bd:
	/* 0x21bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21c2:
	/* 0x21c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21c7:
	/* 0x21c7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21ca:
	/* 0x21ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cc:
	/* 0x21cc: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21d0:
	/* 0x21d0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_21d4:
	/* 0x21d4: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21d8:
	/* 0x21d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21dc:
	/* 0x21dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e1:
	/* 0x21e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21e6:
	/* 0x21e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21eb:
	/* 0x21eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21f0:
	/* 0x21f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f2:
	/* 0x21f2: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21f6:
	/* 0x21f6: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21fa:
	/* 0x21fa: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21fe:
	/* 0x21fe: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2205:
	/* 0x2205: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_220a:
	/* 0x220a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_220f:
	/* 0x220f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2214:
	/* 0x2214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2219:
	/* 0x2219: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_221c:
	/* 0x221c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221e:
	/* 0x221e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2223:
	/* 0x2223: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2227:
	/* 0x2227: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_222c:
	/* 0x222c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2231:
	/* 0x2231: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2236:
	/* 0x2236: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_223b:
	/* 0x223b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223d:
	/* 0x223d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2242:
	/* 0x2242: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2247:
	/* 0x2247: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_224c:
	/* 0x224c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2251:
	/* 0x2251: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2256:
	/* 0x2256: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_225b:
	/* 0x225b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225d:
	/* 0x225d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2261:
	/* 0x2261: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2265:
	/* 0x2265: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_226a:
	/* 0x226a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226c:
	/* 0x226c: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2270:
	/* 0x2270: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2274:
	/* 0x2274: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2279:
	/* 0x2279: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_227e:
	/* 0x227e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2283:
	/* 0x2283: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2288:
	/* 0x2288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228a:
	/* 0x228a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_228f:
	/* 0x228f: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2293:
	/* 0x2293: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_229b:
	/* 0x229b: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_229f:
	/* 0x229f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a4:
	/* 0x22a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a9:
	/* 0x22a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22ae:
	/* 0x22ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b3:
	/* 0x22b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b5:
	/* 0x22b5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22ba:
	/* 0x22ba: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22be:
	/* 0x22be: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_22c2:
	/* 0x22c2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22c7:
	/* 0x22c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22cc:
	/* 0x22cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22d1:
	/* 0x22d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d6:
	/* 0x22d6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22d9:
	/* 0x22d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22db:
	/* 0x22db: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e0:
	/* 0x22e0: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22e4:
	/* 0x22e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e9:
	/* 0x22e9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22ee:
	/* 0x22ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22f3:
	/* 0x22f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22f8:
	/* 0x22f8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_22fb:
	/* 0x22fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22fd:
	/* 0x22fd: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_2302:
	/* 0x2302: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_2305:
	/* 0x2305: je     230c <trace_security_file_mprotect+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_230c;
	}
x86_l_2307:
	/* 0x2307: or     BYTE PTR [r13+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_230c:
	/* 0x230c: mov    QWORD PTR [r13+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2314:
	/* 0x2314: lea    rdi,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2318:
	/* 0x2318: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2320:
	/* 0x2320: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2325:
	/* 0x2325: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_232a:
	/* 0x232a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_232f:
	/* 0x232f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2331:
	/* 0x2331: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2336:
	/* 0x2336: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_233b:
	/* 0x233b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2340:
	/* 0x2340: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2345:
	/* 0x2345: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2348:
	/* 0x2348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234a:
	/* 0x234a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_234f:
	/* 0x234f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2354:
	/* 0x2354: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2359:
	/* 0x2359: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_235e:
	/* 0x235e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2363:
	/* 0x2363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2365:
	/* 0x2365: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236a:
	/* 0x236a: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236f:
	/* 0x236f: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2374:
	/* 0x2374: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2379:
	/* 0x2379: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_237c:
	/* 0x237c: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
	return 9089ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9089ULL: goto x86_l_2381;
	case 9091ULL: goto x86_l_2383;
	case 9095ULL: goto x86_l_2387;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9133ULL: goto x86_l_23ad;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9148ULL: goto x86_l_23bc;
	case 9156ULL: goto x86_l_23c4;
	case 9160ULL: goto x86_l_23c8;
	case 9168ULL: goto x86_l_23d0;
	case 9170ULL: goto x86_l_23d2;
	case 9177ULL: goto x86_l_23d9;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9195ULL: goto x86_l_23eb;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9201ULL: goto x86_l_23f1;
	case 9205ULL: goto x86_l_23f5;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9236ULL: goto x86_l_2414;
	case 9243ULL: goto x86_l_241b;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9261ULL: goto x86_l_242d;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9274ULL: goto x86_l_243a;
	case 9282ULL: goto x86_l_2442;
	case 9292ULL: goto x86_l_244c;
	case 9300ULL: goto x86_l_2454;
	case 9308ULL: goto x86_l_245c;
	case 9316ULL: goto x86_l_2464;
	case 9324ULL: goto x86_l_246c;
	case 9332ULL: goto x86_l_2474;
	case 9340ULL: goto x86_l_247c;
	case 9348ULL: goto x86_l_2484;
	case 9356ULL: goto x86_l_248c;
	case 9363ULL: goto x86_l_2493;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9420ULL: goto x86_l_24cc;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9435ULL: goto x86_l_24db;
	case 9438ULL: goto x86_l_24de;
	case 9444ULL: goto x86_l_24e4;
	case 9448ULL: goto x86_l_24e8;
	case 9455ULL: goto x86_l_24ef;
	case 9458ULL: goto x86_l_24f2;
	case 9465ULL: goto x86_l_24f9;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9483ULL: goto x86_l_250b;
	case 9487ULL: goto x86_l_250f;
	case 9494ULL: goto x86_l_2516;
	case 9498ULL: goto x86_l_251a;
	case 9505ULL: goto x86_l_2521;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9520ULL: goto x86_l_2530;
	case 9524ULL: goto x86_l_2534;
	case 9531ULL: goto x86_l_253b;
	case 9538ULL: goto x86_l_2542;
	case 9540ULL: goto x86_l_2544;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9549ULL: goto x86_l_254d;
	case 9552ULL: goto x86_l_2550;
	case 9559ULL: goto x86_l_2557;
	case 9567ULL: goto x86_l_255f;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9602ULL: goto x86_l_2582;
	case 9609ULL: goto x86_l_2589;
	case 9612ULL: goto x86_l_258c;
	case 9615ULL: goto x86_l_258f;
	case 9618ULL: goto x86_l_2592;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9628ULL: goto x86_l_259c;
	case 9635ULL: goto x86_l_25a3;
	case 9638ULL: goto x86_l_25a6;
	case 9645ULL: goto x86_l_25ad;
	case 9648ULL: goto x86_l_25b0;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9660ULL: goto x86_l_25bc;
	case 9667ULL: goto x86_l_25c3;
	case 9670ULL: goto x86_l_25c6;
	case 9673ULL: goto x86_l_25c9;
	case 9676ULL: goto x86_l_25cc;
	case 9683ULL: goto x86_l_25d3;
	case 9686ULL: goto x86_l_25d6;
	case 9689ULL: goto x86_l_25d9;
	case 9696ULL: goto x86_l_25e0;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9705ULL: goto x86_l_25e9;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9727ULL: goto x86_l_25ff;
	case 9734ULL: goto x86_l_2606;
	case 9737ULL: goto x86_l_2609;
	case 9739ULL: goto x86_l_260b;
	case 9742ULL: goto x86_l_260e;
	case 9750ULL: goto x86_l_2616;
	case 9754ULL: goto x86_l_261a;
	case 9757ULL: goto x86_l_261d;
	case 9764ULL: goto x86_l_2624;
	case 9767ULL: goto x86_l_2627;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9782ULL: goto x86_l_2636;
	case 9785ULL: goto x86_l_2639;
	case 9793ULL: goto x86_l_2641;
	case 9799ULL: goto x86_l_2647;
	case 9806ULL: goto x86_l_264e;
	case 9814ULL: goto x86_l_2656;
	case 9821ULL: goto x86_l_265d;
	case 9828ULL: goto x86_l_2664;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9860ULL: goto x86_l_2684;
	case 9863ULL: goto x86_l_2687;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9879ULL: goto x86_l_2697;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9897ULL: goto x86_l_26a9;
	case 9899ULL: goto x86_l_26ab;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9914ULL: goto x86_l_26ba;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9938ULL: goto x86_l_26d2;
	case 9940ULL: goto x86_l_26d4;
	case 9944ULL: goto x86_l_26d8;
	case 9946ULL: goto x86_l_26da;
	case 9949ULL: goto x86_l_26dd;
	case 9951ULL: goto x86_l_26df;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10005ULL: goto x86_l_2715;
	case 10007ULL: goto x86_l_2717;
	case 10010ULL: goto x86_l_271a;
	case 10014ULL: goto x86_l_271e;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10026ULL: goto x86_l_272a;
	case 10033ULL: goto x86_l_2731;
	case 10036ULL: goto x86_l_2734;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10058ULL: goto x86_l_274a;
	case 10066ULL: goto x86_l_2752;
	case 10069ULL: goto x86_l_2755;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10085ULL: goto x86_l_2765;
	case 10088ULL: goto x86_l_2768;
	case 10090ULL: goto x86_l_276a;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10123ULL: goto x86_l_278b;
	case 10129ULL: goto x86_l_2791;
	case 10134ULL: goto x86_l_2796;
	case 10136ULL: goto x86_l_2798;
	case 10140ULL: goto x86_l_279c;
	case 10147ULL: goto x86_l_27a3;
	case 10154ULL: goto x86_l_27aa;
	case 10162ULL: goto x86_l_27b2;
	case 10169ULL: goto x86_l_27b9;
	case 10172ULL: goto x86_l_27bc;
	case 10179ULL: goto x86_l_27c3;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10230ULL: goto x86_l_27f6;
	case 10233ULL: goto x86_l_27f9;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10247ULL: goto x86_l_2807;
	case 10250ULL: goto x86_l_280a;
	case 10252ULL: goto x86_l_280c;
	case 10255ULL: goto x86_l_280f;
	case 10259ULL: goto x86_l_2813;
	case 10262ULL: goto x86_l_2816;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10277ULL: goto x86_l_2825;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10290ULL: goto x86_l_2832;
	case 10292ULL: goto x86_l_2834;
	case 10300ULL: goto x86_l_283c;
	case 10302ULL: goto x86_l_283e;
	case 10306ULL: goto x86_l_2842;
	case 10314ULL: goto x86_l_284a;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10329ULL: goto x86_l_2859;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10351ULL: goto x86_l_286f;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10452ULL: goto x86_l_28d4;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10462ULL: goto x86_l_28de;
	case 10469ULL: goto x86_l_28e5;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10510ULL: goto x86_l_290e;
	case 10513ULL: goto x86_l_2911;
	case 10515ULL: goto x86_l_2913;
	case 10518ULL: goto x86_l_2916;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	case 10534ULL: goto x86_l_2926;
	case 10537ULL: goto x86_l_2929;
	case 10541ULL: goto x86_l_292d;
	case 10544ULL: goto x86_l_2930;
	case 10546ULL: goto x86_l_2932;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10554ULL: goto x86_l_293a;
	case 10557ULL: goto x86_l_293d;
	case 10560ULL: goto x86_l_2940;
	case 10568ULL: goto x86_l_2948;
	case 10574ULL: goto x86_l_294e;
	case 10581ULL: goto x86_l_2955;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10637ULL: goto x86_l_298d;
	case 10641ULL: goto x86_l_2991;
	case 10645ULL: goto x86_l_2995;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10684ULL: goto x86_l_29bc;
	case 10689ULL: goto x86_l_29c1;
	case 10694ULL: goto x86_l_29c6;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10710ULL: goto x86_l_29d6;
	case 10714ULL: goto x86_l_29da;
	case 10721ULL: goto x86_l_29e1;
	case 10728ULL: goto x86_l_29e8;
	case 10733ULL: goto x86_l_29ed;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10753ULL: goto x86_l_2a01;
	case 10755ULL: goto x86_l_2a03;
	case 10762ULL: goto x86_l_2a0a;
	case 10765ULL: goto x86_l_2a0d;
	case 10767ULL: goto x86_l_2a0f;
	case 10770ULL: goto x86_l_2a12;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10781ULL: goto x86_l_2a1d;
	case 10784ULL: goto x86_l_2a20;
	case 10786ULL: goto x86_l_2a22;
	case 10789ULL: goto x86_l_2a25;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10798ULL: goto x86_l_2a2e;
	case 10800ULL: goto x86_l_2a30;
	case 10803ULL: goto x86_l_2a33;
	case 10806ULL: goto x86_l_2a36;
	case 10809ULL: goto x86_l_2a39;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2381:
	/* 0x2381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2383:
	/* 0x2383: lea    rdi,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2387:
	/* 0x2387: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_238c:
	/* 0x238c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2391:
	/* 0x2391: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2396:
	/* 0x2396: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2399:
	/* 0x2399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_239b:
	/* 0x239b: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_23a0:
	/* 0x23a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23a5:
	/* 0x23a5: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_23ad:
	/* 0x23ad: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23b5:
	/* 0x23b5: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_23ba:
	/* 0x23ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bc:
	/* 0x23bc: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_23c4:
	/* 0x23c4: test   BYTE PTR [rbx+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_23c8:
	/* 0x23c8: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_23d0:
	/* 0x23d0: je     23f5 <trace_security_file_mprotect+0x23f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f5;
	}
x86_l_23d2:
	/* 0x23d2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_23d9:
	/* 0x23d9: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_23de:
	/* 0x23de: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_23e3:
	/* 0x23e3: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_23e8:
	/* 0x23e8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_23eb:
	/* 0x23eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ed:
	/* 0x23ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23ef:
	/* 0x23ef: js     23f5 <trace_security_file_mprotect+0x23f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_23f5;
	}
x86_l_23f1:
	/* 0x23f1: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_23f5:
	/* 0x23f5: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23fd:
	/* 0x23fd: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2402:
	/* 0x2402: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2407:
	/* 0x2407: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_240a:
	/* 0x240a: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2410:
	/* 0x2410: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2414:
	/* 0x2414: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_241b:
	/* 0x241b: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2420:
	/* 0x2420: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2425:
	/* 0x2425: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_242a:
	/* 0x242a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_242d:
	/* 0x242d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2430:
	/* 0x2430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2432:
	/* 0x2432: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_243a:
	/* 0x243a: mov    DWORD PTR [r13+0x70],0x2d4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337876ULL);
x86_l_2442:
	/* 0x2442: mov    WORD PTR [r13+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_244c:
	/* 0x244c: mov    BYTE PTR [r13+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2454:
	/* 0x2454: mov    QWORD PTR [rcx+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_245c:
	/* 0x245c: mov    QWORD PTR [rcx+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_2464:
	/* 0x2464: mov    QWORD PTR [rcx+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_246c:
	/* 0x246c: mov    QWORD PTR [rcx+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_2474:
	/* 0x2474: mov    QWORD PTR [rcx+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_247c:
	/* 0x247c: mov    QWORD PTR [rcx+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_2484:
	/* 0x2484: mov    QWORD PTR [rcx+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_248c:
	/* 0x248c: mov    QWORD PTR [rcx],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_2493:
	/* 0x2493: mov    QWORD PTR [r13+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_249e:
	/* 0x249e: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_24a3:
	/* 0x24a3: mov    DWORD PTR [rsp+0x30],0x2d4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430932ULL);
x86_l_24ab:
	/* 0x24ab: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b0:
	/* 0x24b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_24b7:
	/* 0x24b7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24bc:
	/* 0x24bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24c1:
	/* 0x24c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c3:
	/* 0x24c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24c6:
	/* 0x24c6: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_24cc:
	/* 0x24cc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_24cf:
	/* 0x24cf: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24d4:
	/* 0x24d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24d9:
	/* 0x24d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24db:
	/* 0x24db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24de:
	/* 0x24de: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_24e4:
	/* 0x24e4: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e8:
	/* 0x24e8: mov    QWORD PTR [r13+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_24ef:
	/* 0x24ef: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f2:
	/* 0x24f2: mov    QWORD PTR [r13+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_24f9:
	/* 0x24f9: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2500:
	/* 0x2500: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2504:
	/* 0x2504: mov    QWORD PTR [r13+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_250b:
	/* 0x250b: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_250f:
	/* 0x250f: mov    QWORD PTR [r13+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_2516:
	/* 0x2516: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_251a:
	/* 0x251a: mov    QWORD PTR [r13+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_2521:
	/* 0x2521: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2525:
	/* 0x2525: mov    QWORD PTR [r13+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_252c:
	/* 0x252c: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2530:
	/* 0x2530: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2534:
	/* 0x2534: mov    QWORD PTR [r13+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_253b:
	/* 0x253b: mov    QWORD PTR [r13+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2542:
	/* 0x2542: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2544:
	/* 0x2544: cmp    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2548:
	/* 0x2548: jne    256a <trace_security_file_mprotect+0x256a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_256a;
	}
x86_l_254a:
	/* 0x254a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_254d:
	/* 0x254d: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2550:
	/* 0x2550: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2557:
	/* 0x2557: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_255f:
	/* 0x255f: jne    2d74 <trace_security_file_mprotect+0x2d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11636ULL;
	}
x86_l_2565:
	/* 0x2565: jmp    2d68 <trace_security_file_mprotect+0x2d68> */
	return 11624ULL;
x86_l_256a:
	/* 0x256a: mov    rax,QWORD PTR [r13+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_2571:
	/* 0x2571: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: je     2723 <trace_security_file_mprotect+0x2723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2723;
	}
x86_l_257a:
	/* 0x257a: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2582:
	/* 0x2582: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_2589:
	/* 0x2589: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_258c:
	/* 0x258c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258f:
	/* 0x258f: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2592:
	/* 0x2592: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_2596:
	/* 0x2596: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2599:
	/* 0x2599: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_259c:
	/* 0x259c: xor    r12,QWORD PTR [r13+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_25a3:
	/* 0x25a3: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25a6:
	/* 0x25a6: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_25ad:
	/* 0x25ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25b0:
	/* 0x25b0: je     25d9 <trace_security_file_mprotect+0x25d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d9;
	}
x86_l_25b2:
	/* 0x25b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25b4:
	/* 0x25b4: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_25bc:
	/* 0x25bc: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_25c3:
	/* 0x25c3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_25c6:
	/* 0x25c6: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25c9:
	/* 0x25c9: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_25cc:
	/* 0x25cc: xor    rcx,QWORD PTR [r13+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_25d3:
	/* 0x25d3: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25d6:
	/* 0x25d6: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_25d9:
	/* 0x25d9: mov    rax,QWORD PTR [r13+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_25e0:
	/* 0x25e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25e3:
	/* 0x25e3: je     25ff <trace_security_file_mprotect+0x25ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ff;
	}
x86_l_25e5:
	/* 0x25e5: mov    ecx,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_25e9:
	/* 0x25e9: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25ec:
	/* 0x25ec: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_25ef:
	/* 0x25ef: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_25f2:
	/* 0x25f2: xor    rcx,QWORD PTR [r13+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_25f9:
	/* 0x25f9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25fc:
	/* 0x25fc: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_25ff:
	/* 0x25ff: mov    rax,QWORD PTR [r13+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2606:
	/* 0x2606: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2609:
	/* 0x2609: je     262a <trace_security_file_mprotect+0x262a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262a;
	}
x86_l_260b:
	/* 0x260b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_260e:
	/* 0x260e: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2616:
	/* 0x2616: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_261a:
	/* 0x261a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_261d:
	/* 0x261d: xor    rcx,QWORD PTR [r13+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_2624:
	/* 0x2624: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2627:
	/* 0x2627: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_262a:
	/* 0x262a: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_262f:
	/* 0x262f: mov    r15,QWORD PTR [r13+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_2636:
	/* 0x2636: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2639:
	/* 0x2639: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2641:
	/* 0x2641: je     2783 <trace_security_file_mprotect+0x2783> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2783;
	}
x86_l_2647:
	/* 0x2647: mov    rcx,QWORD PTR [r13+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_264e:
	/* 0x264e: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2656:
	/* 0x2656: mov    rbp,QWORD PTR [r13+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_265d:
	/* 0x265d: mov    rcx,QWORD PTR [r13+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_2664:
	/* 0x2664: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_266c:
	/* 0x266c: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2671:
	/* 0x2671: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_2678:
	/* 0x2678: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_267d:
	/* 0x267d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2682:
	/* 0x2682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2684:
	/* 0x2684: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2687:
	/* 0x2687: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_268b:
	/* 0x268b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2690:
	/* 0x2690: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2697:
	/* 0x2697: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_269a:
	/* 0x269a: je     26bc <trace_security_file_mprotect+0x26bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bc;
	}
x86_l_269c:
	/* 0x269c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26a1:
	/* 0x26a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26a6:
	/* 0x26a6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26a9:
	/* 0x26a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ab:
	/* 0x26ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26ae:
	/* 0x26ae: je     26bc <trace_security_file_mprotect+0x26bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bc;
	}
x86_l_26b0:
	/* 0x26b0: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b3:
	/* 0x26b3: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b7:
	/* 0x26b7: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_26ba:
	/* 0x26ba: jmp    26bf <trace_security_file_mprotect+0x26bf> */
	goto x86_l_26bf;
x86_l_26bc:
	/* 0x26bc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26bf:
	/* 0x26bf: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_26c7:
	/* 0x26c7: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26cc:
	/* 0x26cc: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_26cf:
	/* 0x26cf: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_26d2:
	/* 0x26d2: jb     26ea <trace_security_file_mprotect+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26ea;
	}
x86_l_26d4:
	/* 0x26d4: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_26d8:
	/* 0x26d8: je     26df <trace_security_file_mprotect+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_26da:
	/* 0x26da: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_26dd:
	/* 0x26dd: jbe    26ea <trace_security_file_mprotect+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26ea;
	}
x86_l_26df:
	/* 0x26df: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_26e7:
	/* 0x26e7: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_26ea:
	/* 0x26ea: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26ef:
	/* 0x26ef: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26f2:
	/* 0x26f2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26f7:
	/* 0x26f7: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_26fe:
	/* 0x26fe: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2701:
	/* 0x2701: je     2744 <trace_security_file_mprotect+0x2744> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2744;
	}
x86_l_2703:
	/* 0x2703: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2708:
	/* 0x2708: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_270d:
	/* 0x270d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2710:
	/* 0x2710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2712:
	/* 0x2712: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2715:
	/* 0x2715: je     2748 <trace_security_file_mprotect+0x2748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2748;
	}
x86_l_2717:
	/* 0x2717: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271a:
	/* 0x271a: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_271e:
	/* 0x271e: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2721:
	/* 0x2721: jmp    274a <trace_security_file_mprotect+0x274a> */
	goto x86_l_274a;
x86_l_2723:
	/* 0x2723: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_272a:
	/* 0x272a: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_2731:
	/* 0x2731: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2734:
	/* 0x2734: jne    25b2 <trace_security_file_mprotect+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25b2;
	}
x86_l_273a:
	/* 0x273a: jmp    25d9 <trace_security_file_mprotect+0x25d9> */
	goto x86_l_25d9;
x86_l_273f:
	/* 0x273f: jmp    1eae <trace_security_file_mprotect+0x1eae> */
	return 7854ULL;
x86_l_2744:
	/* 0x2744: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2746:
	/* 0x2746: jmp    2752 <trace_security_file_mprotect+0x2752> */
	goto x86_l_2752;
x86_l_2748:
	/* 0x2748: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274a:
	/* 0x274a: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2752:
	/* 0x2752: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2755:
	/* 0x2755: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_275a:
	/* 0x275a: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_275d:
	/* 0x275d: jb     2775 <trace_security_file_mprotect+0x2775> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2775;
	}
x86_l_275f:
	/* 0x275f: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2763:
	/* 0x2763: je     276a <trace_security_file_mprotect+0x276a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_276a;
	}
x86_l_2765:
	/* 0x2765: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2768:
	/* 0x2768: jbe    2775 <trace_security_file_mprotect+0x2775> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2775;
	}
x86_l_276a:
	/* 0x276a: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_2772:
	/* 0x2772: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_2775:
	/* 0x2775: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2778:
	/* 0x2778: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_277b:
	/* 0x277b: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_277e:
	/* 0x277e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2783:
	/* 0x2783: cmp    QWORD PTR [r13+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_278b:
	/* 0x278b: je     2834 <trace_security_file_mprotect+0x2834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2834;
	}
x86_l_2791:
	/* 0x2791: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2796:
	/* 0x2796: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2798:
	/* 0x2798: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_279c:
	/* 0x279c: mov    rbx,QWORD PTR [r13+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_27a3:
	/* 0x27a3: mov    rax,QWORD PTR [r13+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_27aa:
	/* 0x27aa: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_27b2:
	/* 0x27b2: mov    rbp,QWORD PTR [r13+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_27b9:
	/* 0x27b9: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_27bc:
	/* 0x27bc: mov    r13,QWORD PTR [r13+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_27c3:
	/* 0x27c3: movzx  eax,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_27cb:
	/* 0x27cb: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d0:
	/* 0x27d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_27d7:
	/* 0x27d7: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27dc:
	/* 0x27dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27e1:
	/* 0x27e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e3:
	/* 0x27e3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_27e6:
	/* 0x27e6: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ea:
	/* 0x27ea: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ef:
	/* 0x27ef: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_27f6:
	/* 0x27f6: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_27f9:
	/* 0x27f9: je     2818 <trace_security_file_mprotect+0x2818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2818;
	}
x86_l_27fb:
	/* 0x27fb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2800:
	/* 0x2800: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2805:
	/* 0x2805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2807:
	/* 0x2807: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_280a:
	/* 0x280a: je     2818 <trace_security_file_mprotect+0x2818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2818;
	}
x86_l_280c:
	/* 0x280c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280f:
	/* 0x280f: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2813:
	/* 0x2813: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2816:
	/* 0x2816: jmp    281a <trace_security_file_mprotect+0x281a> */
	goto x86_l_281a;
x86_l_2818:
	/* 0x2818: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_281a:
	/* 0x281a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_281d:
	/* 0x281d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2822:
	/* 0x2822: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2825:
	/* 0x2825: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2828:
	/* 0x2828: jae    283e <trace_security_file_mprotect+0x283e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_283e;
	}
x86_l_282a:
	/* 0x282a: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_2832:
	/* 0x2832: jmp    285c <trace_security_file_mprotect+0x285c> */
	goto x86_l_285c;
x86_l_2834:
	/* 0x2834: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_283c:
	/* 0x283c: jmp    2867 <trace_security_file_mprotect+0x2867> */
	goto x86_l_2867;
x86_l_283e:
	/* 0x283e: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2842:
	/* 0x2842: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_284a:
	/* 0x284a: je     2851 <trace_security_file_mprotect+0x2851> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2851;
	}
x86_l_284c:
	/* 0x284c: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_284f:
	/* 0x284f: jbe    285c <trace_security_file_mprotect+0x285c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_285c;
	}
x86_l_2851:
	/* 0x2851: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_2859:
	/* 0x2859: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_285c:
	/* 0x285c: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_285f:
	/* 0x285f: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2862:
	/* 0x2862: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2867:
	/* 0x2867: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_286f:
	/* 0x286f: je     2940 <trace_security_file_mprotect+0x2940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2940;
	}
x86_l_2875:
	/* 0x2875: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_287a:
	/* 0x287a: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2881:
	/* 0x2881: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2886:
	/* 0x2886: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_288b:
	/* 0x288b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2890:
	/* 0x2890: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2895:
	/* 0x2895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2897:
	/* 0x2897: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_289c:
	/* 0x289c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28a0:
	/* 0x28a0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28a5:
	/* 0x28a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28aa:
	/* 0x28aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28af:
	/* 0x28af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b4:
	/* 0x28b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b6:
	/* 0x28b6: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28bb:
	/* 0x28bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c0:
	/* 0x28c0: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_28c5:
	/* 0x28c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28ca:
	/* 0x28ca: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28cf:
	/* 0x28cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28d4:
	/* 0x28d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d6:
	/* 0x28d6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28da:
	/* 0x28da: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_28de:
	/* 0x28de: mov    rbx,QWORD PTR [r13+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_28e5:
	/* 0x28e5: mov    r15,QWORD PTR [r13+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_28ec:
	/* 0x28ec: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28f1:
	/* 0x28f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_28f8:
	/* 0x28f8: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28fd:
	/* 0x28fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2902:
	/* 0x2902: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2905:
	/* 0x2905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2907:
	/* 0x2907: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_290e:
	/* 0x290e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2911:
	/* 0x2911: je     2932 <trace_security_file_mprotect+0x2932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2932;
	}
x86_l_2913:
	/* 0x2913: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2916:
	/* 0x2916: lea    rsi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_291a:
	/* 0x291a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_291f:
	/* 0x291f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2921:
	/* 0x2921: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2924:
	/* 0x2924: je     2932 <trace_security_file_mprotect+0x2932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2932;
	}
x86_l_2926:
	/* 0x2926: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2929:
	/* 0x2929: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292d:
	/* 0x292d: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2930:
	/* 0x2930: jmp    2934 <trace_security_file_mprotect+0x2934> */
	goto x86_l_2934;
x86_l_2932:
	/* 0x2932: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2934:
	/* 0x2934: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2937:
	/* 0x2937: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_293a:
	/* 0x293a: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_293d:
	/* 0x293d: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2940:
	/* 0x2940: cmp    QWORD PTR [r13+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_2948:
	/* 0x2948: je     2a3c <trace_security_file_mprotect+0x2a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10812ULL;
	}
x86_l_294e:
	/* 0x294e: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2955:
	/* 0x2955: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2959:
	/* 0x2959: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_295e:
	/* 0x295e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2963:
	/* 0x2963: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2968:
	/* 0x2968: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_296d:
	/* 0x296d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296f:
	/* 0x296f: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2974:
	/* 0x2974: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2979:
	/* 0x2979: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_297e:
	/* 0x297e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2983:
	/* 0x2983: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2988:
	/* 0x2988: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_298b:
	/* 0x298b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298d:
	/* 0x298d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2991:
	/* 0x2991: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2995:
	/* 0x2995: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2999:
	/* 0x2999: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_299d:
	/* 0x299d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29a2:
	/* 0x29a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29a7:
	/* 0x29a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ac:
	/* 0x29ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b1:
	/* 0x29b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b3:
	/* 0x29b3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29b8:
	/* 0x29b8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_29bc:
	/* 0x29bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29c1:
	/* 0x29c1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29c6:
	/* 0x29c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29cb:
	/* 0x29cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29d0:
	/* 0x29d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d2:
	/* 0x29d2: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29d6:
	/* 0x29d6: mov    DWORD PTR [r13+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29da:
	/* 0x29da: mov    rbx,QWORD PTR [r13+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_29e1:
	/* 0x29e1: mov    r15,QWORD PTR [r13+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_29e8:
	/* 0x29e8: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29ed:
	/* 0x29ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_29f4:
	/* 0x29f4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29f9:
	/* 0x29f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29fe:
	/* 0x29fe: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2a01:
	/* 0x2a01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a03:
	/* 0x2a03: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2a0a:
	/* 0x2a0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a0d:
	/* 0x2a0d: je     2a2e <trace_security_file_mprotect+0x2a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2e;
	}
x86_l_2a0f:
	/* 0x2a0f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a12:
	/* 0x2a12: lea    rsi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a16:
	/* 0x2a16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a1b:
	/* 0x2a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1d:
	/* 0x2a1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a20:
	/* 0x2a20: je     2a2e <trace_security_file_mprotect+0x2a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2e;
	}
x86_l_2a22:
	/* 0x2a22: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a25:
	/* 0x2a25: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a29:
	/* 0x2a29: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2a2c:
	/* 0x2a2c: jmp    2a30 <trace_security_file_mprotect+0x2a30> */
	goto x86_l_2a30;
x86_l_2a2e:
	/* 0x2a2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a30:
	/* 0x2a30: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a33:
	/* 0x2a33: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a36:
	/* 0x2a36: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a39:
	/* 0x2a39: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
	return 10812ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10812ULL: goto x86_l_2a3c;
	case 10820ULL: goto x86_l_2a44;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10838ULL: goto x86_l_2a56;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	case 10858ULL: goto x86_l_2a6a;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10917ULL: goto x86_l_2aa5;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10942ULL: goto x86_l_2abe;
	case 10944ULL: goto x86_l_2ac0;
	case 10951ULL: goto x86_l_2ac7;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10970ULL: goto x86_l_2ada;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11015ULL: goto x86_l_2b07;
	case 11018ULL: goto x86_l_2b0a;
	case 11022ULL: goto x86_l_2b0e;
	case 11025ULL: goto x86_l_2b11;
	case 11027ULL: goto x86_l_2b13;
	case 11029ULL: goto x86_l_2b15;
	case 11032ULL: goto x86_l_2b18;
	case 11035ULL: goto x86_l_2b1b;
	case 11038ULL: goto x86_l_2b1e;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11054ULL: goto x86_l_2b2e;
	case 11060ULL: goto x86_l_2b34;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11084ULL: goto x86_l_2b4c;
	case 11091ULL: goto x86_l_2b53;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11123ULL: goto x86_l_2b73;
	case 11125ULL: goto x86_l_2b75;
	case 11132ULL: goto x86_l_2b7c;
	case 11135ULL: goto x86_l_2b7f;
	case 11137ULL: goto x86_l_2b81;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11148ULL: goto x86_l_2b8c;
	case 11150ULL: goto x86_l_2b8e;
	case 11153ULL: goto x86_l_2b91;
	case 11155ULL: goto x86_l_2b93;
	case 11158ULL: goto x86_l_2b96;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11169ULL: goto x86_l_2ba1;
	case 11172ULL: goto x86_l_2ba4;
	case 11175ULL: goto x86_l_2ba7;
	case 11178ULL: goto x86_l_2baa;
	case 11181ULL: goto x86_l_2bad;
	case 11186ULL: goto x86_l_2bb2;
	case 11193ULL: goto x86_l_2bb9;
	case 11196ULL: goto x86_l_2bbc;
	case 11198ULL: goto x86_l_2bbe;
	case 11202ULL: goto x86_l_2bc2;
	case 11206ULL: goto x86_l_2bc6;
	case 11213ULL: goto x86_l_2bcd;
	case 11218ULL: goto x86_l_2bd2;
	case 11225ULL: goto x86_l_2bd9;
	case 11230ULL: goto x86_l_2bde;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11247ULL: goto x86_l_2bef;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11292ULL: goto x86_l_2c1c;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11305ULL: goto x86_l_2c29;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11342ULL: goto x86_l_2c4e;
	case 11344ULL: goto x86_l_2c50;
	case 11351ULL: goto x86_l_2c57;
	case 11354ULL: goto x86_l_2c5a;
	case 11356ULL: goto x86_l_2c5c;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11372ULL: goto x86_l_2c6c;
	case 11374ULL: goto x86_l_2c6e;
	case 11377ULL: goto x86_l_2c71;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11386ULL: goto x86_l_2c7a;
	case 11389ULL: goto x86_l_2c7d;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11412ULL: goto x86_l_2c94;
	case 11415ULL: goto x86_l_2c97;
	case 11421ULL: goto x86_l_2c9d;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11453ULL: goto x86_l_2cbd;
	case 11455ULL: goto x86_l_2cbf;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11478ULL: goto x86_l_2cd6;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11505ULL: goto x86_l_2cf1;
	case 11509ULL: goto x86_l_2cf5;
	case 11514ULL: goto x86_l_2cfa;
	case 11517ULL: goto x86_l_2cfd;
	case 11519ULL: goto x86_l_2cff;
	case 11522ULL: goto x86_l_2d02;
	case 11524ULL: goto x86_l_2d04;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11544ULL: goto x86_l_2d18;
	case 11547ULL: goto x86_l_2d1b;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11573ULL: goto x86_l_2d35;
	case 11575ULL: goto x86_l_2d37;
	case 11583ULL: goto x86_l_2d3f;
	case 11587ULL: goto x86_l_2d43;
	case 11590ULL: goto x86_l_2d46;
	case 11597ULL: goto x86_l_2d4d;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11614ULL: goto x86_l_2d5e;
	case 11622ULL: goto x86_l_2d66;
	case 11624ULL: goto x86_l_2d68;
	case 11630ULL: goto x86_l_2d6e;
	case 11636ULL: goto x86_l_2d74;
	case 11645ULL: goto x86_l_2d7d;
	case 11651ULL: goto x86_l_2d83;
	case 11660ULL: goto x86_l_2d8c;
	case 11669ULL: goto x86_l_2d95;
	case 11678ULL: goto x86_l_2d9e;
	case 11687ULL: goto x86_l_2da7;
	case 11696ULL: goto x86_l_2db0;
	case 11705ULL: goto x86_l_2db9;
	case 11714ULL: goto x86_l_2dc2;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11731ULL: goto x86_l_2dd3;
	case 11739ULL: goto x86_l_2ddb;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11767ULL: goto x86_l_2df7;
	case 11770ULL: goto x86_l_2dfa;
	case 11774ULL: goto x86_l_2dfe;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11821ULL: goto x86_l_2e2d;
	case 11826ULL: goto x86_l_2e32;
	case 11831ULL: goto x86_l_2e37;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11844ULL: goto x86_l_2e44;
	case 11847ULL: goto x86_l_2e47;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11882ULL: goto x86_l_2e6a;
	case 11886ULL: goto x86_l_2e6e;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11981ULL: goto x86_l_2ecd;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11995ULL: goto x86_l_2edb;
	case 12001ULL: goto x86_l_2ee1;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12027ULL: goto x86_l_2efb;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12044ULL: goto x86_l_2f0c;
	case 12046ULL: goto x86_l_2f0e;
	case 12048ULL: goto x86_l_2f10;
	case 12054ULL: goto x86_l_2f16;
	case 12057ULL: goto x86_l_2f19;
	case 12062ULL: goto x86_l_2f1e;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12073ULL: goto x86_l_2f29;
	case 12080ULL: goto x86_l_2f30;
	case 12086ULL: goto x86_l_2f36;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12102ULL: goto x86_l_2f46;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12109ULL: goto x86_l_2f4d;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12119ULL: goto x86_l_2f57;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12129ULL: goto x86_l_2f61;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12156ULL: goto x86_l_2f7c;
	case 12159ULL: goto x86_l_2f7f;
	case 12164ULL: goto x86_l_2f84;
	case 12167ULL: goto x86_l_2f87;
	case 12173ULL: goto x86_l_2f8d;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12188ULL: goto x86_l_2f9c;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12211ULL: goto x86_l_2fb3;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12222ULL: goto x86_l_2fbe;
	case 12226ULL: goto x86_l_2fc2;
	case 12229ULL: goto x86_l_2fc5;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12250ULL: goto x86_l_2fda;
	case 12254ULL: goto x86_l_2fde;
	case 12259ULL: goto x86_l_2fe3;
	case 12264ULL: goto x86_l_2fe8;
	case 12269ULL: goto x86_l_2fed;
	case 12273ULL: goto x86_l_2ff1;
	case 12278ULL: goto x86_l_2ff6;
	case 12280ULL: goto x86_l_2ff8;
	case 12284ULL: goto x86_l_2ffc;
	case 12288ULL: goto x86_l_3000;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12317ULL: goto x86_l_301d;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12329ULL: goto x86_l_3029;
	case 12333ULL: goto x86_l_302d;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12348ULL: goto x86_l_303c;
	case 12353ULL: goto x86_l_3041;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12363ULL: goto x86_l_304b;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12377ULL: goto x86_l_3059;
	case 12383ULL: goto x86_l_305f;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12407ULL: goto x86_l_3077;
	case 12409ULL: goto x86_l_3079;
	case 12413ULL: goto x86_l_307d;
	case 12415ULL: goto x86_l_307f;
	case 12421ULL: goto x86_l_3085;
	case 12424ULL: goto x86_l_3088;
	case 12426ULL: goto x86_l_308a;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12443ULL: goto x86_l_309b;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12455ULL: goto x86_l_30a7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a3c:
	/* 0x2a3c: cmp    QWORD PTR [r13+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_2a44:
	/* 0x2a44: je     2b26 <trace_security_file_mprotect+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a4a:
	/* 0x2a4a: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2a4f:
	/* 0x2a4f: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2a56:
	/* 0x2a56: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a5b:
	/* 0x2a5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a60:
	/* 0x2a60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a65:
	/* 0x2a65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a6a:
	/* 0x2a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6c:
	/* 0x2a6c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a71:
	/* 0x2a71: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a76:
	/* 0x2a76: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a80:
	/* 0x2a80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a85:
	/* 0x2a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a87:
	/* 0x2a87: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8c:
	/* 0x2a8c: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a91:
	/* 0x2a91: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2a96:
	/* 0x2a96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2a9e:
	/* 0x2a9e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2aa3:
	/* 0x2aa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa5:
	/* 0x2aa5: lea    rbx,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2aa9:
	/* 0x2aa9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2aae:
	/* 0x2aae: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ab6:
	/* 0x2ab6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2abb:
	/* 0x2abb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2abe:
	/* 0x2abe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac0:
	/* 0x2ac0: mov    r15,QWORD PTR [r13+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    r13,QWORD PTR [r13+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_2ace:
	/* 0x2ace: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_2ada:
	/* 0x2ada: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2adf:
	/* 0x2adf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ae4:
	/* 0x2ae4: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2ae7:
	/* 0x2ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae9:
	/* 0x2ae9: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2af0:
	/* 0x2af0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2af3:
	/* 0x2af3: je     2b13 <trace_security_file_mprotect+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b13;
	}
x86_l_2af5:
	/* 0x2af5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2af8:
	/* 0x2af8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2afd:
	/* 0x2afd: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2b00:
	/* 0x2b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b02:
	/* 0x2b02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: je     2b13 <trace_security_file_mprotect+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b13;
	}
x86_l_2b07:
	/* 0x2b07: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0e:
	/* 0x2b0e: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2b11:
	/* 0x2b11: jmp    2b15 <trace_security_file_mprotect+0x2b15> */
	goto x86_l_2b15;
x86_l_2b13:
	/* 0x2b13: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b15:
	/* 0x2b15: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2b18:
	/* 0x2b18: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2b1b:
	/* 0x2b1b: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2b1e:
	/* 0x2b1e: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2b21:
	/* 0x2b21: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b26:
	/* 0x2b26: cmp    QWORD PTR [r13+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_2b2e:
	/* 0x2b2e: je     2bb2 <trace_security_file_mprotect+0x2bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bb2;
	}
x86_l_2b34:
	/* 0x2b34: lea    rbx,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2b38:
	/* 0x2b38: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2b42:
	/* 0x2b42: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b45:
	/* 0x2b45: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b4a:
	/* 0x2b4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4c:
	/* 0x2b4c: mov    r15,QWORD PTR [r13+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_2b53:
	/* 0x2b53: mov    r13,QWORD PTR [r13+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_2b66:
	/* 0x2b66: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b70:
	/* 0x2b70: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2b73:
	/* 0x2b73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b75:
	/* 0x2b75: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2b7c:
	/* 0x2b7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7f:
	/* 0x2b7f: je     2b9f <trace_security_file_mprotect+0x2b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9f;
	}
x86_l_2b81:
	/* 0x2b81: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2b84:
	/* 0x2b84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b89:
	/* 0x2b89: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2b8c:
	/* 0x2b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8e:
	/* 0x2b8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b91:
	/* 0x2b91: je     2b9f <trace_security_file_mprotect+0x2b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9f;
	}
x86_l_2b93:
	/* 0x2b93: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b96:
	/* 0x2b96: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9a:
	/* 0x2b9a: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2b9d:
	/* 0x2b9d: jmp    2ba1 <trace_security_file_mprotect+0x2ba1> */
	goto x86_l_2ba1;
x86_l_2b9f:
	/* 0x2b9f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba1:
	/* 0x2ba1: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ba4:
	/* 0x2ba4: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2ba7:
	/* 0x2ba7: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2baa:
	/* 0x2baa: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2bad:
	/* 0x2bad: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    rbx,QWORD PTR [r13+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_2bb9:
	/* 0x2bb9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2bbc:
	/* 0x2bbc: je     2c22 <trace_security_file_mprotect+0x2c22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c22;
	}
x86_l_2bbe:
	/* 0x2bbe: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    r15,QWORD PTR [r13+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_2bcd:
	/* 0x2bcd: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_2bd9:
	/* 0x2bd9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bde:
	/* 0x2bde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2be3:
	/* 0x2be3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2be6:
	/* 0x2be6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be8:
	/* 0x2be8: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2bef:
	/* 0x2bef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf2:
	/* 0x2bf2: je     2c14 <trace_security_file_mprotect+0x2c14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c14;
	}
x86_l_2bf4:
	/* 0x2bf4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2bf7:
	/* 0x2bf7: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c01:
	/* 0x2c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c03:
	/* 0x2c03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c06:
	/* 0x2c06: je     2c14 <trace_security_file_mprotect+0x2c14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c14;
	}
x86_l_2c08:
	/* 0x2c08: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c0f:
	/* 0x2c0f: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2c12:
	/* 0x2c12: jmp    2c16 <trace_security_file_mprotect+0x2c16> */
	goto x86_l_2c16;
x86_l_2c14:
	/* 0x2c14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c16:
	/* 0x2c16: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c19:
	/* 0x2c19: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c1c:
	/* 0x2c1c: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c1f:
	/* 0x2c1f: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c22:
	/* 0x2c22: mov    rbx,QWORD PTR [r13+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_2c29:
	/* 0x2c29: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2c2c:
	/* 0x2c2c: je     2c8d <trace_security_file_mprotect+0x2c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c8d;
	}
x86_l_2c2e:
	/* 0x2c2e: mov    r15,QWORD PTR [r13+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_2c35:
	/* 0x2c35: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_2c41:
	/* 0x2c41: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c46:
	/* 0x2c46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c4b:
	/* 0x2c4b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2c4e:
	/* 0x2c4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c50:
	/* 0x2c50: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2c57:
	/* 0x2c57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c5a:
	/* 0x2c5a: je     2c7f <trace_security_file_mprotect+0x2c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c7f;
	}
x86_l_2c5c:
	/* 0x2c5c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c5f:
	/* 0x2c5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c64:
	/* 0x2c64: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c6c:
	/* 0x2c6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6e:
	/* 0x2c6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c71:
	/* 0x2c71: je     2c7f <trace_security_file_mprotect+0x2c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c7f;
	}
x86_l_2c73:
	/* 0x2c73: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c76:
	/* 0x2c76: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7a:
	/* 0x2c7a: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2c7d:
	/* 0x2c7d: jmp    2c81 <trace_security_file_mprotect+0x2c81> */
	goto x86_l_2c81;
x86_l_2c7f:
	/* 0x2c7f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c81:
	/* 0x2c81: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c84:
	/* 0x2c84: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c87:
	/* 0x2c87: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c8a:
	/* 0x2c8a: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c8d:
	/* 0x2c8d: mov    r15,QWORD PTR [r13+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_2c94:
	/* 0x2c94: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2c97:
	/* 0x2c97: je     2d23 <trace_security_file_mprotect+0x2d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d23;
	}
x86_l_2c9d:
	/* 0x2c9d: mov    r13,QWORD PTR [r13+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_2cb0:
	/* 0x2cb0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cba:
	/* 0x2cba: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2cbd:
	/* 0x2cbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbf:
	/* 0x2cbf: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2cc6:
	/* 0x2cc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc9:
	/* 0x2cc9: je     2d10 <trace_security_file_mprotect+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d10;
	}
x86_l_2ccb:
	/* 0x2ccb: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2cce:
	/* 0x2cce: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2cd6:
	/* 0x2cd6: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2cda:
	/* 0x2cda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cdf:
	/* 0x2cdf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ce2:
	/* 0x2ce2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce4:
	/* 0x2ce4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce7:
	/* 0x2ce7: jne    2d04 <trace_security_file_mprotect+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d04;
	}
x86_l_2ce9:
	/* 0x2ce9: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2cf1:
	/* 0x2cf1: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf5:
	/* 0x2cf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cfa:
	/* 0x2cfa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2cfd:
	/* 0x2cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cff:
	/* 0x2cff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d02:
	/* 0x2d02: je     2d10 <trace_security_file_mprotect+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d10;
	}
x86_l_2d04:
	/* 0x2d04: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d07:
	/* 0x2d07: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d0b:
	/* 0x2d0b: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2d0e:
	/* 0x2d0e: jmp    2d12 <trace_security_file_mprotect+0x2d12> */
	goto x86_l_2d12;
x86_l_2d10:
	/* 0x2d10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d12:
	/* 0x2d12: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d15:
	/* 0x2d15: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d18:
	/* 0x2d18: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d1b:
	/* 0x2d1b: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d1e:
	/* 0x2d1e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d23:
	/* 0x2d23: mov    rax,QWORD PTR [r13+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2d2a:
	/* 0x2d2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d2d:
	/* 0x2d2d: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2d35:
	/* 0x2d35: je     2d46 <trace_security_file_mprotect+0x2d46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d46;
	}
x86_l_2d37:
	/* 0x2d37: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d3f:
	/* 0x2d3f: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_2d43:
	/* 0x2d43: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d46:
	/* 0x2d46: and    r12,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    rcx,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d54:
	/* 0x2d54: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d57:
	/* 0x2d57: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2d66:
	/* 0x2d66: jne    2d74 <trace_security_file_mprotect+0x2d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d74;
	}
x86_l_2d68:
	/* 0x2d68: test   BYTE PTR [r12+0x4],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869188ULL);
x86_l_2d6e:
	/* 0x2d6e: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_2d74:
	/* 0x2d74: cmp    QWORD PTR [rsp+0x138],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2d7d:
	/* 0x2d7d: jne    36e4 <trace_security_file_mprotect+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14052ULL;
	}
x86_l_2d83:
	/* 0x2d83: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2d95:
	/* 0x2d95: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2da7:
	/* 0x2da7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2db0:
	/* 0x2db0: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2db9:
	/* 0x2db9: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2dca:
	/* 0x2dca: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_2dcd:
	/* 0x2dcd: je     2f43 <trace_security_file_mprotect+0x2f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f43;
	}
x86_l_2dd3:
	/* 0x2dd3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ddb:
	/* 0x2ddb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_2de2:
	/* 0x2de2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de7:
	/* 0x2de7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dec:
	/* 0x2dec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dee:
	/* 0x2dee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2df1:
	/* 0x2df1: je     2f54 <trace_security_file_mprotect+0x2f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f54;
	}
x86_l_2df7:
	/* 0x2df7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2dfa:
	/* 0x2dfa: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfe:
	/* 0x2dfe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e03:
	/* 0x2e03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e08:
	/* 0x2e08: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e0d:
	/* 0x2e0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e12:
	/* 0x2e12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e14:
	/* 0x2e14: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e19:
	/* 0x2e19: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e1e:
	/* 0x2e1e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e23:
	/* 0x2e23: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e28:
	/* 0x2e28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e2d:
	/* 0x2e2d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e32:
	/* 0x2e32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e37:
	/* 0x2e37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e39:
	/* 0x2e39: test   BYTE PTR [rsp+0x10],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476768ULL);
x86_l_2e3e:
	/* 0x2e3e: jne    2f5e <trace_security_file_mprotect+0x2f5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f5e;
	}
x86_l_2e44:
	/* 0x2e44: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2e47:
	/* 0x2e47: lea    rdx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4b:
	/* 0x2e4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e50:
	/* 0x2e50: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e55:
	/* 0x2e55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e5a:
	/* 0x2e5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e5f:
	/* 0x2e5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e61:
	/* 0x2e61: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e66:
	/* 0x2e66: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_2e6a:
	/* 0x2e6a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e6e:
	/* 0x2e6e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e73:
	/* 0x2e73: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e78:
	/* 0x2e78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e81:
	/* 0x2e81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e86:
	/* 0x2e86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e88:
	/* 0x2e88: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e8d:
	/* 0x2e8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e92:
	/* 0x2e92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e97:
	/* 0x2e97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2e9f:
	/* 0x2e9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea1:
	/* 0x2ea1: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eab:
	/* 0x2eab: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2eaf:
	/* 0x2eaf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ebe:
	/* 0x2ebe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec3:
	/* 0x2ec3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec5:
	/* 0x2ec5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eca:
	/* 0x2eca: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2ecd:
	/* 0x2ecd: je     2f84 <trace_security_file_mprotect+0x2f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f84;
	}
x86_l_2ed3:
	/* 0x2ed3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2edb:
	/* 0x2edb: je     2f84 <trace_security_file_mprotect+0x2f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f84;
	}
x86_l_2ee1:
	/* 0x2ee1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ee5:
	/* 0x2ee5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eea:
	/* 0x2eea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2eef:
	/* 0x2eef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ef9:
	/* 0x2ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efb:
	/* 0x2efb: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2eff:
	/* 0x2eff: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f04:
	/* 0x2f04: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f06:
	/* 0x2f06: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2f0e:
	/* 0x2f0e: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2f10:
	/* 0x2f10: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f16:
	/* 0x2f16: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f19:
	/* 0x2f19: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f1e:
	/* 0x2f1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f20:
	/* 0x2f20: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f23:
	/* 0x2f23: jl     3272 <trace_security_file_mprotect+0x3272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12914ULL;
	}
x86_l_2f29:
	/* 0x2f29: mov    BYTE PTR [rbx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_2f30:
	/* 0x2f30: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_2f36:
	/* 0x2f36: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f39:
	/* 0x2f39: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3e:
	/* 0x2f3e: jmp    3006 <trace_security_file_mprotect+0x3006> */
	goto x86_l_3006;
x86_l_2f43:
	/* 0x2f43: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2f46:
	/* 0x2f46: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f49:
	/* 0x2f49: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4b:
	/* 0x2f4b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4d:
	/* 0x2f4d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4f:
	/* 0x2f4f: jmp    3657 <trace_security_file_mprotect+0x3657> */
	return 13911ULL;
x86_l_2f54:
	/* 0x2f54: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2f57:
	/* 0x2f57: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f59:
	/* 0x2f59: jmp    34d2 <trace_security_file_mprotect+0x34d2> */
	return 13522ULL;
x86_l_2f5e:
	/* 0x2f5e: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2f61:
	/* 0x2f61: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2f68:
	/* 0x2f68: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2f6d:
	/* 0x2f6d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f72:
	/* 0x2f72: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f7a:
	/* 0x2f7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7c:
	/* 0x2f7c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f7f:
	/* 0x2f7f: jmp    34c8 <trace_security_file_mprotect+0x34c8> */
	return 13512ULL;
x86_l_2f84:
	/* 0x2f84: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2f87:
	/* 0x2f87: jne    3272 <trace_security_file_mprotect+0x3272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12914ULL;
	}
x86_l_2f8d:
	/* 0x2f8d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f91:
	/* 0x2f91: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2f96:
	/* 0x2f96: je     3272 <trace_security_file_mprotect+0x3272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12914ULL;
	}
x86_l_2f9c:
	/* 0x2f9c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fa0:
	/* 0x2fa0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fa5:
	/* 0x2fa5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2faa:
	/* 0x2faa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2faf:
	/* 0x2faf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb3:
	/* 0x2fb3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fbc:
	/* 0x2fbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbe:
	/* 0x2fbe: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fc5:
	/* 0x2fc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fca:
	/* 0x2fca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd8:
	/* 0x2fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fda:
	/* 0x2fda: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fde:
	/* 0x2fde: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fe3:
	/* 0x2fe3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fe8:
	/* 0x2fe8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fed:
	/* 0x2fed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff1:
	/* 0x2ff1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ff6:
	/* 0x2ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff8:
	/* 0x2ff8: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffc:
	/* 0x2ffc: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3000:
	/* 0x3000: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_3006:
	/* 0x3006: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_300b:
	/* 0x300b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3010:
	/* 0x3010: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3015:
	/* 0x3015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_301a:
	/* 0x301a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_301d:
	/* 0x301d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301f:
	/* 0x301f: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3024:
	/* 0x3024: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3029:
	/* 0x3029: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_302d:
	/* 0x302d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3032:
	/* 0x3032: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3037:
	/* 0x3037: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_303c:
	/* 0x303c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3041:
	/* 0x3041: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3043:
	/* 0x3043: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3048:
	/* 0x3048: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_304b:
	/* 0x304b: je     325c <trace_security_file_mprotect+0x325c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12892ULL;
	}
x86_l_3051:
	/* 0x3051: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3056:
	/* 0x3056: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3059:
	/* 0x3059: je     325c <trace_security_file_mprotect+0x325c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12892ULL;
	}
x86_l_305f:
	/* 0x305f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3063:
	/* 0x3063: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3068:
	/* 0x3068: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_306d:
	/* 0x306d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3072:
	/* 0x3072: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3077:
	/* 0x3077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3079:
	/* 0x3079: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_307d:
	/* 0x307d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_307f:
	/* 0x307f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3085:
	/* 0x3085: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3088:
	/* 0x3088: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_308a:
	/* 0x308a: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_3090:
	/* 0x3090: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3095:
	/* 0x3095: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_309b:
	/* 0x309b: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_309e:
	/* 0x309e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_30a0:
	/* 0x30a0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_30a5:
	/* 0x30a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a7:
	/* 0x30a7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
	return 12458ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12458ULL: goto x86_l_30aa;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12478ULL: goto x86_l_30be;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12491ULL: goto x86_l_30cb;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12506ULL: goto x86_l_30da;
	case 12510ULL: goto x86_l_30de;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12529ULL: goto x86_l_30f1;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12540ULL: goto x86_l_30fc;
	case 12544ULL: goto x86_l_3100;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12561ULL: goto x86_l_3111;
	case 12566ULL: goto x86_l_3116;
	case 12568ULL: goto x86_l_3118;
	case 12572ULL: goto x86_l_311c;
	case 12577ULL: goto x86_l_3121;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12591ULL: goto x86_l_312f;
	case 12596ULL: goto x86_l_3134;
	case 12598ULL: goto x86_l_3136;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12672ULL: goto x86_l_3180;
	case 12675ULL: goto x86_l_3183;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12713ULL: goto x86_l_31a9;
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12725ULL: goto x86_l_31b5;
	case 12728ULL: goto x86_l_31b8;
	case 12730ULL: goto x86_l_31ba;
	case 12736ULL: goto x86_l_31c0;
	case 12739ULL: goto x86_l_31c3;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12751ULL: goto x86_l_31cf;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12766ULL: goto x86_l_31de;
	case 12772ULL: goto x86_l_31e4;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12787ULL: goto x86_l_31f3;
	case 12791ULL: goto x86_l_31f7;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12810ULL: goto x86_l_320a;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12825ULL: goto x86_l_3219;
	case 12828ULL: goto x86_l_321c;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12879ULL: goto x86_l_324f;
	case 12883ULL: goto x86_l_3253;
	case 12887ULL: goto x86_l_3257;
	case 12892ULL: goto x86_l_325c;
	case 12895ULL: goto x86_l_325f;
	case 12901ULL: goto x86_l_3265;
	case 12908ULL: goto x86_l_326c;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12970ULL: goto x86_l_32aa;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12989ULL: goto x86_l_32bd;
	case 12992ULL: goto x86_l_32c0;
	case 12994ULL: goto x86_l_32c2;
	case 12999ULL: goto x86_l_32c7;
	case 13001ULL: goto x86_l_32c9;
	case 13004ULL: goto x86_l_32cc;
	case 13010ULL: goto x86_l_32d2;
	case 13014ULL: goto x86_l_32d6;
	case 13020ULL: goto x86_l_32dc;
	case 13024ULL: goto x86_l_32e0;
	case 13027ULL: goto x86_l_32e3;
	case 13032ULL: goto x86_l_32e8;
	case 13037ULL: goto x86_l_32ed;
	case 13042ULL: goto x86_l_32f2;
	case 13047ULL: goto x86_l_32f7;
	case 13052ULL: goto x86_l_32fc;
	case 13055ULL: goto x86_l_32ff;
	case 13057ULL: goto x86_l_3301;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13093ULL: goto x86_l_3325;
	case 13098ULL: goto x86_l_332a;
	case 13101ULL: goto x86_l_332d;
	case 13107ULL: goto x86_l_3333;
	case 13112ULL: goto x86_l_3338;
	case 13115ULL: goto x86_l_333b;
	case 13121ULL: goto x86_l_3341;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13140ULL: goto x86_l_3354;
	case 13145ULL: goto x86_l_3359;
	case 13147ULL: goto x86_l_335b;
	case 13151ULL: goto x86_l_335f;
	case 13153ULL: goto x86_l_3361;
	case 13159ULL: goto x86_l_3367;
	case 13162ULL: goto x86_l_336a;
	case 13164ULL: goto x86_l_336c;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13181ULL: goto x86_l_337d;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13193ULL: goto x86_l_3389;
	case 13196ULL: goto x86_l_338c;
	case 13202ULL: goto x86_l_3392;
	case 13206ULL: goto x86_l_3396;
	case 13212ULL: goto x86_l_339c;
	case 13216ULL: goto x86_l_33a0;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13229ULL: goto x86_l_33ad;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13244ULL: goto x86_l_33bc;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13258ULL: goto x86_l_33ca;
	case 13263ULL: goto x86_l_33cf;
	case 13267ULL: goto x86_l_33d3;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13278ULL: goto x86_l_33de;
	case 13282ULL: goto x86_l_33e2;
	case 13285ULL: goto x86_l_33e5;
	case 13290ULL: goto x86_l_33ea;
	case 13295ULL: goto x86_l_33ef;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13315ULL: goto x86_l_3403;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13329ULL: goto x86_l_3411;
	case 13334ULL: goto x86_l_3416;
	case 13336ULL: goto x86_l_3418;
	case 13340ULL: goto x86_l_341c;
	case 13344ULL: goto x86_l_3420;
	case 13349ULL: goto x86_l_3425;
	case 13354ULL: goto x86_l_342a;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13379ULL: goto x86_l_3443;
	case 13383ULL: goto x86_l_3447;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13413ULL: goto x86_l_3465;
	case 13419ULL: goto x86_l_346b;
	case 13424ULL: goto x86_l_3470;
	case 13427ULL: goto x86_l_3473;
	case 13433ULL: goto x86_l_3479;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13457ULL: goto x86_l_3491;
	case 13459ULL: goto x86_l_3493;
	case 13463ULL: goto x86_l_3497;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13474ULL: goto x86_l_34a2;
	case 13476ULL: goto x86_l_34a4;
	case 13482ULL: goto x86_l_34aa;
	case 13485ULL: goto x86_l_34ad;
	case 13488ULL: goto x86_l_34b0;
	case 13493ULL: goto x86_l_34b5;
	case 13497ULL: goto x86_l_34b9;
	case 13504ULL: goto x86_l_34c0;
	case 13512ULL: goto x86_l_34c8;
	case 13519ULL: goto x86_l_34cf;
	case 13522ULL: goto x86_l_34d2;
	case 13530ULL: goto x86_l_34da;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13554ULL: goto x86_l_34f2;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13573ULL: goto x86_l_3505;
	case 13582ULL: goto x86_l_350e;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13608ULL: goto x86_l_3528;
	case 13613ULL: goto x86_l_352d;
	case 13618ULL: goto x86_l_3532;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13632ULL: goto x86_l_3540;
	case 13637ULL: goto x86_l_3545;
	case 13642ULL: goto x86_l_354a;
	case 13645ULL: goto x86_l_354d;
	case 13647ULL: goto x86_l_354f;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13661ULL: goto x86_l_355d;
	case 13666ULL: goto x86_l_3562;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13681ULL: goto x86_l_3571;
	case 13683ULL: goto x86_l_3573;
	case 13688ULL: goto x86_l_3578;
	case 13691ULL: goto x86_l_357b;
	case 13693ULL: goto x86_l_357d;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13713ULL: goto x86_l_3591;
	case 13718ULL: goto x86_l_3596;
	case 13720ULL: goto x86_l_3598;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13734ULL: goto x86_l_35a6;
	case 13737ULL: goto x86_l_35a9;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13763ULL: goto x86_l_35c3;
	case 13765ULL: goto x86_l_35c5;
	case 13770ULL: goto x86_l_35ca;
	case 13774ULL: goto x86_l_35ce;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13798ULL: goto x86_l_35e6;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13815ULL: goto x86_l_35f7;
	case 13820ULL: goto x86_l_35fc;
	case 13825ULL: goto x86_l_3601;
	case 13830ULL: goto x86_l_3606;
	case 13835ULL: goto x86_l_360b;
	case 13837ULL: goto x86_l_360d;
	case 13841ULL: goto x86_l_3611;
	case 13846ULL: goto x86_l_3616;
	case 13851ULL: goto x86_l_361b;
	case 13856ULL: goto x86_l_3620;
	case 13861ULL: goto x86_l_3625;
	case 13864ULL: goto x86_l_3628;
	case 13866ULL: goto x86_l_362a;
	case 13871ULL: goto x86_l_362f;
	case 13875ULL: goto x86_l_3633;
	case 13880ULL: goto x86_l_3638;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13899ULL: goto x86_l_364b;
	case 13904ULL: goto x86_l_3650;
	case 13906ULL: goto x86_l_3652;
	case 13911ULL: goto x86_l_3657;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13929ULL: goto x86_l_3669;
	case 13937ULL: goto x86_l_3671;
	case 13945ULL: goto x86_l_3679;
	case 13950ULL: goto x86_l_367e;
	case 13958ULL: goto x86_l_3686;
	case 13963ULL: goto x86_l_368b;
	case 13971ULL: goto x86_l_3693;
	case 13976ULL: goto x86_l_3698;
	case 13984ULL: goto x86_l_36a0;
	case 13989ULL: goto x86_l_36a5;
	case 13997ULL: goto x86_l_36ad;
	case 14002ULL: goto x86_l_36b2;
	case 14010ULL: goto x86_l_36ba;
	case 14017ULL: goto x86_l_36c1;
	case 14028ULL: goto x86_l_36cc;
	case 14036ULL: goto x86_l_36d4;
	case 14044ULL: goto x86_l_36dc;
	case 14047ULL: goto x86_l_36df;
	case 14052ULL: goto x86_l_36e4;
	case 14061ULL: goto x86_l_36ed;
	case 14067ULL: goto x86_l_36f3;
	case 14076ULL: goto x86_l_36fc;
	case 14078ULL: goto x86_l_36fe;
	case 14086ULL: goto x86_l_3706;
	case 14089ULL: goto x86_l_3709;
	case 14091ULL: goto x86_l_370b;
	case 14099ULL: goto x86_l_3713;
	case 14101ULL: goto x86_l_3715;
	case 14103ULL: goto x86_l_3717;
	case 14105ULL: goto x86_l_3719;
	case 14108ULL: goto x86_l_371c;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14127ULL: goto x86_l_372f;
	case 14135ULL: goto x86_l_3737;
	case 14138ULL: goto x86_l_373a;
	case 14140ULL: goto x86_l_373c;
	case 14148ULL: goto x86_l_3744;
	case 14151ULL: goto x86_l_3747;
	case 14153ULL: goto x86_l_3749;
	case 14155ULL: goto x86_l_374b;
	case 14157ULL: goto x86_l_374d;
	case 14163ULL: goto x86_l_3753;
	case 14171ULL: goto x86_l_375b;
	case 14173ULL: goto x86_l_375d;
	case 14181ULL: goto x86_l_3765;
	case 14183ULL: goto x86_l_3767;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30aa:
	/* 0x30aa: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3265;
	}
x86_l_30b0:
	/* 0x30b0: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_30b4:
	/* 0x30b4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_30ba:
	/* 0x30ba: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_30be:
	/* 0x30be: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30c1:
	/* 0x30c1: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c6:
	/* 0x30c6: jmp    3420 <trace_security_file_mprotect+0x3420> */
	goto x86_l_3420;
x86_l_30cb:
	/* 0x30cb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30cf:
	/* 0x30cf: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_30d4:
	/* 0x30d4: je     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6547ULL;
	}
x86_l_30da:
	/* 0x30da: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30de:
	/* 0x30de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e3:
	/* 0x30e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30e8:
	/* 0x30e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ed:
	/* 0x30ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f1:
	/* 0x30f1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30f5:
	/* 0x30f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30fa:
	/* 0x30fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30fc:
	/* 0x30fc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3100:
	/* 0x3100: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3103:
	/* 0x3103: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3108:
	/* 0x3108: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_310d:
	/* 0x310d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3111:
	/* 0x3111: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3116:
	/* 0x3116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3118:
	/* 0x3118: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311c:
	/* 0x311c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3121:
	/* 0x3121: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3126:
	/* 0x3126: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_312b:
	/* 0x312b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312f:
	/* 0x312f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3134:
	/* 0x3134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3136:
	/* 0x3136: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_313a:
	/* 0x313a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_313e:
	/* 0x313e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3143:
	/* 0x3143: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3148:
	/* 0x3148: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_314d:
	/* 0x314d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3152:
	/* 0x3152: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3155:
	/* 0x3155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3157:
	/* 0x3157: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_315c:
	/* 0x315c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3161:
	/* 0x3161: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3165:
	/* 0x3165: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316a:
	/* 0x316a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_316f:
	/* 0x316f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3174:
	/* 0x3174: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3179:
	/* 0x3179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317b:
	/* 0x317b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3180:
	/* 0x3180: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3183:
	/* 0x3183: je     31db <trace_security_file_mprotect+0x31db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31db;
	}
x86_l_3185:
	/* 0x3185: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_318a:
	/* 0x318a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_318d:
	/* 0x318d: je     31db <trace_security_file_mprotect+0x31db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31db;
	}
x86_l_318f:
	/* 0x318f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3193:
	/* 0x3193: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3198:
	/* 0x3198: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_319d:
	/* 0x319d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a2:
	/* 0x31a2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31a7:
	/* 0x31a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a9:
	/* 0x31a9: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_31ad:
	/* 0x31ad: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31af:
	/* 0x31af: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31b5:
	/* 0x31b5: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_31b8:
	/* 0x31b8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31ba:
	/* 0x31ba: jae    32b2 <trace_security_file_mprotect+0x32b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32b2;
	}
x86_l_31c0:
	/* 0x31c0: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_31c3:
	/* 0x31c3: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_31c6:
	/* 0x31c6: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_31cb:
	/* 0x31cb: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_31cf:
	/* 0x31cf: mov    BYTE PTR [rbx+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_31d6:
	/* 0x31d6: jmp    19db <trace_security_file_mprotect+0x19db> */
	return 6619ULL;
x86_l_31db:
	/* 0x31db: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_31de:
	/* 0x31de: jne    1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6547ULL;
	}
x86_l_31e4:
	/* 0x31e4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31e8:
	/* 0x31e8: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_31ed:
	/* 0x31ed: je     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6547ULL;
	}
x86_l_31f3:
	/* 0x31f3: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31f7:
	/* 0x31f7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fc:
	/* 0x31fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3201:
	/* 0x3201: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3206:
	/* 0x3206: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_320a:
	/* 0x320a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_320e:
	/* 0x320e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3213:
	/* 0x3213: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3215:
	/* 0x3215: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3219:
	/* 0x3219: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_321c:
	/* 0x321c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3221:
	/* 0x3221: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3226:
	/* 0x3226: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322a:
	/* 0x322a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_322f:
	/* 0x322f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3231:
	/* 0x3231: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3235:
	/* 0x3235: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_323a:
	/* 0x323a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_323f:
	/* 0x323f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3244:
	/* 0x3244: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3248:
	/* 0x3248: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_324d:
	/* 0x324d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324f:
	/* 0x324f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3253:
	/* 0x3253: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3257:
	/* 0x3257: jmp    32e8 <trace_security_file_mprotect+0x32e8> */
	goto x86_l_32e8;
x86_l_325c:
	/* 0x325c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_325f:
	/* 0x325f: je     33ad <trace_security_file_mprotect+0x33ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33ad;
	}
x86_l_3265:
	/* 0x3265: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_326c:
	/* 0x326c: jne    34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34aa;
	}
x86_l_3272:
	/* 0x3272: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3277:
	/* 0x3277: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_327b:
	/* 0x327b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3280:
	/* 0x3280: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3285:
	/* 0x3285: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_328a:
	/* 0x328a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_328f:
	/* 0x328f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3291:
	/* 0x3291: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3296:
	/* 0x3296: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_329b:
	/* 0x329b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_32a0:
	/* 0x32a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32a3:
	/* 0x32a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32a8:
	/* 0x32a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32aa:
	/* 0x32aa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32ad:
	/* 0x32ad: jmp    34c0 <trace_security_file_mprotect+0x34c0> */
	goto x86_l_34c0;
x86_l_32b2:
	/* 0x32b2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32b7:
	/* 0x32b7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_32bd:
	/* 0x32bd: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32c0:
	/* 0x32c0: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_32c2:
	/* 0x32c2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_32c7:
	/* 0x32c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c9:
	/* 0x32c9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32cc:
	/* 0x32cc: jl     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6547ULL;
	}
x86_l_32d2:
	/* 0x32d2: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_32d6:
	/* 0x32d6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_32dc:
	/* 0x32dc: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_32e0:
	/* 0x32e0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32e3:
	/* 0x32e3: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e8:
	/* 0x32e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ed:
	/* 0x32ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32f2:
	/* 0x32f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32f7:
	/* 0x32f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fc:
	/* 0x32fc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_32ff:
	/* 0x32ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3301:
	/* 0x3301: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3306:
	/* 0x3306: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_330b:
	/* 0x330b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_330f:
	/* 0x330f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3314:
	/* 0x3314: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3319:
	/* 0x3319: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_331e:
	/* 0x331e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3323:
	/* 0x3323: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3325:
	/* 0x3325: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_332a:
	/* 0x332a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_332d:
	/* 0x332d: je     416a <trace_security_file_mprotect+0x416a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16746ULL;
	}
x86_l_3333:
	/* 0x3333: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3338:
	/* 0x3338: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_333b:
	/* 0x333b: je     416a <trace_security_file_mprotect+0x416a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16746ULL;
	}
x86_l_3341:
	/* 0x3341: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3345:
	/* 0x3345: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_334a:
	/* 0x334a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_334f:
	/* 0x334f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3354:
	/* 0x3354: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3359:
	/* 0x3359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335b:
	/* 0x335b: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_335f:
	/* 0x335f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3361:
	/* 0x3361: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3367:
	/* 0x3367: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_336a:
	/* 0x336a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_336c:
	/* 0x336c: jb     31c0 <trace_security_file_mprotect+0x31c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31c0;
	}
x86_l_3372:
	/* 0x3372: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3377:
	/* 0x3377: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_337d:
	/* 0x337d: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3380:
	/* 0x3380: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3382:
	/* 0x3382: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3387:
	/* 0x3387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3389:
	/* 0x3389: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_338c:
	/* 0x338c: jl     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6547ULL;
	}
x86_l_3392:
	/* 0x3392: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3396:
	/* 0x3396: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_339c:
	/* 0x339c: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_33a0:
	/* 0x33a0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33a3:
	/* 0x33a3: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a8:
	/* 0x33a8: jmp    41e6 <trace_security_file_mprotect+0x41e6> */
	return 16870ULL;
x86_l_33ad:
	/* 0x33ad: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b1:
	/* 0x33b1: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_33b6:
	/* 0x33b6: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3265;
	}
x86_l_33bc:
	/* 0x33bc: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33c0:
	/* 0x33c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c5:
	/* 0x33c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33ca:
	/* 0x33ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33cf:
	/* 0x33cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d3:
	/* 0x33d3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33d7:
	/* 0x33d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33dc:
	/* 0x33dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33de:
	/* 0x33de: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33e2:
	/* 0x33e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33e5:
	/* 0x33e5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33ea:
	/* 0x33ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33ef:
	/* 0x33ef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f3:
	/* 0x33f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f8:
	/* 0x33f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fa:
	/* 0x33fa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33fe:
	/* 0x33fe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3403:
	/* 0x3403: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3408:
	/* 0x3408: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_340d:
	/* 0x340d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3411:
	/* 0x3411: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3416:
	/* 0x3416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3418:
	/* 0x3418: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_341c:
	/* 0x341c: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3420:
	/* 0x3420: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3425:
	/* 0x3425: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_342a:
	/* 0x342a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_342f:
	/* 0x342f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3434:
	/* 0x3434: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3437:
	/* 0x3437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3439:
	/* 0x3439: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_343e:
	/* 0x343e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3443:
	/* 0x3443: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3447:
	/* 0x3447: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_344c:
	/* 0x344c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3451:
	/* 0x3451: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3456:
	/* 0x3456: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_345b:
	/* 0x345b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_345d:
	/* 0x345d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3462:
	/* 0x3462: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3465:
	/* 0x3465: je     42ab <trace_security_file_mprotect+0x42ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17067ULL;
	}
x86_l_346b:
	/* 0x346b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3470:
	/* 0x3470: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3473:
	/* 0x3473: je     42ab <trace_security_file_mprotect+0x42ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17067ULL;
	}
x86_l_3479:
	/* 0x3479: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_347d:
	/* 0x347d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3482:
	/* 0x3482: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3487:
	/* 0x3487: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_348c:
	/* 0x348c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3491:
	/* 0x3491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3493:
	/* 0x3493: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3497:
	/* 0x3497: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3499:
	/* 0x3499: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_349f:
	/* 0x349f: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_34a2:
	/* 0x34a2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34a4:
	/* 0x34a4: jae    4360 <trace_security_file_mprotect+0x4360> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 17248ULL;
	}
x86_l_34aa:
	/* 0x34aa: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_34ad:
	/* 0x34ad: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_34b0:
	/* 0x34b0: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34b5:
	/* 0x34b5: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_34b9:
	/* 0x34b9: mov    BYTE PTR [rbx+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_34c0:
	/* 0x34c0: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_34c8:
	/* 0x34c8: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_34cf:
	/* 0x34cf: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34d2:
	/* 0x34d2: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_34da:
	/* 0x34da: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_34de:
	/* 0x34de: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e3:
	/* 0x34e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34e8:
	/* 0x34e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34ed:
	/* 0x34ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f2:
	/* 0x34f2: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_34f5:
	/* 0x34f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f7:
	/* 0x34f7: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34fc:
	/* 0x34fc: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3505:
	/* 0x3505: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_350e:
	/* 0x350e: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3512:
	/* 0x3512: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3517:
	/* 0x3517: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_351c:
	/* 0x351c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3521:
	/* 0x3521: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3526:
	/* 0x3526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3528:
	/* 0x3528: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_352d:
	/* 0x352d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3532:
	/* 0x3532: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3536:
	/* 0x3536: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_353b:
	/* 0x353b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3540:
	/* 0x3540: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3545:
	/* 0x3545: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_354a:
	/* 0x354a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_354d:
	/* 0x354d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354f:
	/* 0x354f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3553:
	/* 0x3553: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3558:
	/* 0x3558: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355d:
	/* 0x355d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3562:
	/* 0x3562: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3567:
	/* 0x3567: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_356c:
	/* 0x356c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3571:
	/* 0x3571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3573:
	/* 0x3573: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3578:
	/* 0x3578: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_357b:
	/* 0x357b: js     35a6 <trace_security_file_mprotect+0x35a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_35a6;
	}
x86_l_357d:
	/* 0x357d: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3582:
	/* 0x3582: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3587:
	/* 0x3587: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_358c:
	/* 0x358c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3591:
	/* 0x3591: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3596:
	/* 0x3596: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3598:
	/* 0x3598: imul   r15,r14,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R15, X86_R14, X86_WIDTH_64, 1000000000ULL);
x86_l_359f:
	/* 0x359f: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_35a4:
	/* 0x35a4: jmp    35a9 <trace_security_file_mprotect+0x35a9> */
	goto x86_l_35a9;
x86_l_35a6:
	/* 0x35a6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a9:
	/* 0x35a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ae:
	/* 0x35ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35b3:
	/* 0x35b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35b8:
	/* 0x35b8: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_35bb:
	/* 0x35bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35c0:
	/* 0x35c0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_35c3:
	/* 0x35c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c5:
	/* 0x35c5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ca:
	/* 0x35ca: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35ce:
	/* 0x35ce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d3:
	/* 0x35d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35d8:
	/* 0x35d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35dd:
	/* 0x35dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e2:
	/* 0x35e2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35e6:
	/* 0x35e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35eb:
	/* 0x35eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ed:
	/* 0x35ed: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35f2:
	/* 0x35f2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35f7:
	/* 0x35f7: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_35fc:
	/* 0x35fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3601:
	/* 0x3601: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3606:
	/* 0x3606: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_360b:
	/* 0x360b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360d:
	/* 0x360d: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3611:
	/* 0x3611: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3616:
	/* 0x3616: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_361b:
	/* 0x361b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3620:
	/* 0x3620: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3625:
	/* 0x3625: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3628:
	/* 0x3628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362a:
	/* 0x362a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_362f:
	/* 0x362f: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3633:
	/* 0x3633: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3638:
	/* 0x3638: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_363d:
	/* 0x363d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3642:
	/* 0x3642: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3647:
	/* 0x3647: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_364b:
	/* 0x364b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3650:
	/* 0x3650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3652:
	/* 0x3652: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3657:
	/* 0x3657: mov    QWORD PTR [rsp+0xf0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_365f:
	/* 0x365f: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3664:
	/* 0x3664: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3669:
	/* 0x3669: mov    QWORD PTR [rsp+0xf8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3671:
	/* 0x3671: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_3679:
	/* 0x3679: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_367e:
	/* 0x367e: mov    QWORD PTR [rsp+0x108],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_3686:
	/* 0x3686: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_368b:
	/* 0x368b: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3693:
	/* 0x3693: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3698:
	/* 0x3698: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_36a0:
	/* 0x36a0: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_36a5:
	/* 0x36a5: mov    QWORD PTR [rsp+0x120],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_36ad:
	/* 0x36ad: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_36b2:
	/* 0x36b2: mov    QWORD PTR [rsp+0x128],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_36ba:
	/* 0x36ba: mov    DWORD PTR [rsp+0x130],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_36c1:
	/* 0x36c1: mov    DWORD PTR [rsp+0x134],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_36cc:
	/* 0x36cc: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_36d4:
	/* 0x36d4: mov    QWORD PTR [rsp+0x140],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_36dc:
	/* 0x36dc: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_36df:
	/* 0x36df: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36e4:
	/* 0x36e4: cmp    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_36ed:
	/* 0x36ed: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_36f3:
	/* 0x36f3: cmp    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_36fc:
	/* 0x36fc: je     3723 <trace_security_file_mprotect+0x3723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3723;
	}
x86_l_36fe:
	/* 0x36fe: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3706:
	/* 0x3706: test   dl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_3709:
	/* 0x3709: jne    373c <trace_security_file_mprotect+0x373c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_373c;
	}
x86_l_370b:
	/* 0x370b: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3713:
	/* 0x3713: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_3715:
	/* 0x3715: jne    375d <trace_security_file_mprotect+0x375d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_375d;
	}
x86_l_3717:
	/* 0x3717: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3719:
	/* 0x3719: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_371c:
	/* 0x371c: jne    3770 <trace_security_file_mprotect+0x3770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14192ULL;
	}
x86_l_371e:
	/* 0x371e: jmp    37a2 <trace_security_file_mprotect+0x37a2> */
	return 14242ULL;
x86_l_3723:
	/* 0x3723: mov    QWORD PTR [rsp+0xd0],0x1000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353201664ULL);
x86_l_372f:
	/* 0x372f: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3737:
	/* 0x3737: test   dl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_373a:
	/* 0x373a: je     370b <trace_security_file_mprotect+0x370b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_370b;
	}
x86_l_373c:
	/* 0x373c: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3744:
	/* 0x3744: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_3747:
	/* 0x3747: jne    376e <trace_security_file_mprotect+0x376e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14190ULL;
	}
x86_l_3749:
	/* 0x3749: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_374b:
	/* 0x374b: test   al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_374d:
	/* 0x374d: jne    4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16722ULL;
	}
x86_l_3753:
	/* 0x3753: mov    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_375b:
	/* 0x375b: jmp    37aa <trace_security_file_mprotect+0x37aa> */
	return 14250ULL;
x86_l_375d:
	/* 0x375d: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_3765:
	/* 0x3765: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3767:
	/* 0x3767: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
	return 14186ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14186ULL: goto x86_l_376a;
	case 14188ULL: goto x86_l_376c;
	case 14190ULL: goto x86_l_376e;
	case 14192ULL: goto x86_l_3770;
	case 14195ULL: goto x86_l_3773;
	case 14198ULL: goto x86_l_3776;
	case 14200ULL: goto x86_l_3778;
	case 14208ULL: goto x86_l_3780;
	case 14214ULL: goto x86_l_3786;
	case 14216ULL: goto x86_l_3788;
	case 14219ULL: goto x86_l_378b;
	case 14227ULL: goto x86_l_3793;
	case 14229ULL: goto x86_l_3795;
	case 14231ULL: goto x86_l_3797;
	case 14237ULL: goto x86_l_379d;
	case 14242ULL: goto x86_l_37a2;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14252ULL: goto x86_l_37ac;
	case 14260ULL: goto x86_l_37b4;
	case 14262ULL: goto x86_l_37b6;
	case 14266ULL: goto x86_l_37ba;
	case 14274ULL: goto x86_l_37c2;
	case 14281ULL: goto x86_l_37c9;
	case 14283ULL: goto x86_l_37cb;
	case 14292ULL: goto x86_l_37d4;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14304ULL: goto x86_l_37e0;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14333ULL: goto x86_l_37fd;
	case 14336ULL: goto x86_l_3800;
	case 14338ULL: goto x86_l_3802;
	case 14341ULL: goto x86_l_3805;
	case 14349ULL: goto x86_l_380d;
	case 14356ULL: goto x86_l_3814;
	case 14364ULL: goto x86_l_381c;
	case 14371ULL: goto x86_l_3823;
	case 14373ULL: goto x86_l_3825;
	case 14382ULL: goto x86_l_382e;
	case 14388ULL: goto x86_l_3834;
	case 14390ULL: goto x86_l_3836;
	case 14394ULL: goto x86_l_383a;
	case 14401ULL: goto x86_l_3841;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14419ULL: goto x86_l_3853;
	case 14424ULL: goto x86_l_3858;
	case 14426ULL: goto x86_l_385a;
	case 14429ULL: goto x86_l_385d;
	case 14431ULL: goto x86_l_385f;
	case 14434ULL: goto x86_l_3862;
	case 14442ULL: goto x86_l_386a;
	case 14449ULL: goto x86_l_3871;
	case 14457ULL: goto x86_l_3879;
	case 14464ULL: goto x86_l_3880;
	case 14466ULL: goto x86_l_3882;
	case 14475ULL: goto x86_l_388b;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14487ULL: goto x86_l_3897;
	case 14494ULL: goto x86_l_389e;
	case 14502ULL: goto x86_l_38a6;
	case 14507ULL: goto x86_l_38ab;
	case 14512ULL: goto x86_l_38b0;
	case 14517ULL: goto x86_l_38b5;
	case 14519ULL: goto x86_l_38b7;
	case 14522ULL: goto x86_l_38ba;
	case 14524ULL: goto x86_l_38bc;
	case 14527ULL: goto x86_l_38bf;
	case 14535ULL: goto x86_l_38c7;
	case 14542ULL: goto x86_l_38ce;
	case 14550ULL: goto x86_l_38d6;
	case 14557ULL: goto x86_l_38dd;
	case 14559ULL: goto x86_l_38df;
	case 14568ULL: goto x86_l_38e8;
	case 14574ULL: goto x86_l_38ee;
	case 14576ULL: goto x86_l_38f0;
	case 14580ULL: goto x86_l_38f4;
	case 14587ULL: goto x86_l_38fb;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14610ULL: goto x86_l_3912;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14617ULL: goto x86_l_3919;
	case 14620ULL: goto x86_l_391c;
	case 14628ULL: goto x86_l_3924;
	case 14635ULL: goto x86_l_392b;
	case 14643ULL: goto x86_l_3933;
	case 14650ULL: goto x86_l_393a;
	case 14652ULL: goto x86_l_393c;
	case 14661ULL: goto x86_l_3945;
	case 14667ULL: goto x86_l_394b;
	case 14669ULL: goto x86_l_394d;
	case 14673ULL: goto x86_l_3951;
	case 14680ULL: goto x86_l_3958;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14703ULL: goto x86_l_396f;
	case 14705ULL: goto x86_l_3971;
	case 14708ULL: goto x86_l_3974;
	case 14710ULL: goto x86_l_3976;
	case 14713ULL: goto x86_l_3979;
	case 14721ULL: goto x86_l_3981;
	case 14728ULL: goto x86_l_3988;
	case 14736ULL: goto x86_l_3990;
	case 14739ULL: goto x86_l_3993;
	case 14745ULL: goto x86_l_3999;
	case 14753ULL: goto x86_l_39a1;
	case 14759ULL: goto x86_l_39a7;
	case 14765ULL: goto x86_l_39ad;
	case 14774ULL: goto x86_l_39b6;
	case 14782ULL: goto x86_l_39be;
	case 14790ULL: goto x86_l_39c6;
	case 14796ULL: goto x86_l_39cc;
	case 14798ULL: goto x86_l_39ce;
	case 14802ULL: goto x86_l_39d2;
	case 14809ULL: goto x86_l_39d9;
	case 14814ULL: goto x86_l_39de;
	case 14819ULL: goto x86_l_39e3;
	case 14827ULL: goto x86_l_39eb;
	case 14831ULL: goto x86_l_39ef;
	case 14838ULL: goto x86_l_39f6;
	case 14843ULL: goto x86_l_39fb;
	case 14845ULL: goto x86_l_39fd;
	case 14847ULL: goto x86_l_39ff;
	case 14849ULL: goto x86_l_3a01;
	case 14857ULL: goto x86_l_3a09;
	case 14864ULL: goto x86_l_3a10;
	case 14866ULL: goto x86_l_3a12;
	case 14874ULL: goto x86_l_3a1a;
	case 14882ULL: goto x86_l_3a22;
	case 14885ULL: goto x86_l_3a25;
	case 14893ULL: goto x86_l_3a2d;
	case 14900ULL: goto x86_l_3a34;
	case 14908ULL: goto x86_l_3a3c;
	case 14915ULL: goto x86_l_3a43;
	case 14917ULL: goto x86_l_3a45;
	case 14926ULL: goto x86_l_3a4e;
	case 14932ULL: goto x86_l_3a54;
	case 14934ULL: goto x86_l_3a56;
	case 14942ULL: goto x86_l_3a5e;
	case 14946ULL: goto x86_l_3a62;
	case 14953ULL: goto x86_l_3a69;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14968ULL: goto x86_l_3a78;
	case 14970ULL: goto x86_l_3a7a;
	case 14973ULL: goto x86_l_3a7d;
	case 14975ULL: goto x86_l_3a7f;
	case 14978ULL: goto x86_l_3a82;
	case 14986ULL: goto x86_l_3a8a;
	case 14993ULL: goto x86_l_3a91;
	case 15001ULL: goto x86_l_3a99;
	case 15008ULL: goto x86_l_3aa0;
	case 15010ULL: goto x86_l_3aa2;
	case 15019ULL: goto x86_l_3aab;
	case 15025ULL: goto x86_l_3ab1;
	case 15027ULL: goto x86_l_3ab3;
	case 15035ULL: goto x86_l_3abb;
	case 15039ULL: goto x86_l_3abf;
	case 15046ULL: goto x86_l_3ac6;
	case 15051ULL: goto x86_l_3acb;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15063ULL: goto x86_l_3ad7;
	case 15066ULL: goto x86_l_3ada;
	case 15068ULL: goto x86_l_3adc;
	case 15071ULL: goto x86_l_3adf;
	case 15079ULL: goto x86_l_3ae7;
	case 15086ULL: goto x86_l_3aee;
	case 15094ULL: goto x86_l_3af6;
	case 15101ULL: goto x86_l_3afd;
	case 15103ULL: goto x86_l_3aff;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15120ULL: goto x86_l_3b10;
	case 15128ULL: goto x86_l_3b18;
	case 15132ULL: goto x86_l_3b1c;
	case 15139ULL: goto x86_l_3b23;
	case 15144ULL: goto x86_l_3b28;
	case 15149ULL: goto x86_l_3b2d;
	case 15154ULL: goto x86_l_3b32;
	case 15156ULL: goto x86_l_3b34;
	case 15159ULL: goto x86_l_3b37;
	case 15161ULL: goto x86_l_3b39;
	case 15164ULL: goto x86_l_3b3c;
	case 15172ULL: goto x86_l_3b44;
	case 15179ULL: goto x86_l_3b4b;
	case 15186ULL: goto x86_l_3b52;
	case 15190ULL: goto x86_l_3b56;
	case 15195ULL: goto x86_l_3b5b;
	case 15200ULL: goto x86_l_3b60;
	case 15205ULL: goto x86_l_3b65;
	case 15210ULL: goto x86_l_3b6a;
	case 15213ULL: goto x86_l_3b6d;
	case 15215ULL: goto x86_l_3b6f;
	case 15220ULL: goto x86_l_3b74;
	case 15228ULL: goto x86_l_3b7c;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15242ULL: goto x86_l_3b8a;
	case 15247ULL: goto x86_l_3b8f;
	case 15252ULL: goto x86_l_3b94;
	case 15254ULL: goto x86_l_3b96;
	case 15259ULL: goto x86_l_3b9b;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15273ULL: goto x86_l_3ba9;
	case 15278ULL: goto x86_l_3bae;
	case 15283ULL: goto x86_l_3bb3;
	case 15285ULL: goto x86_l_3bb5;
	case 15290ULL: goto x86_l_3bba;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15304ULL: goto x86_l_3bc8;
	case 15309ULL: goto x86_l_3bcd;
	case 15314ULL: goto x86_l_3bd2;
	case 15316ULL: goto x86_l_3bd4;
	case 15320ULL: goto x86_l_3bd8;
	case 15324ULL: goto x86_l_3bdc;
	case 15328ULL: goto x86_l_3be0;
	case 15333ULL: goto x86_l_3be5;
	case 15338ULL: goto x86_l_3bea;
	case 15343ULL: goto x86_l_3bef;
	case 15348ULL: goto x86_l_3bf4;
	case 15351ULL: goto x86_l_3bf7;
	case 15353ULL: goto x86_l_3bf9;
	case 15356ULL: goto x86_l_3bfc;
	case 15361ULL: goto x86_l_3c01;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15384ULL: goto x86_l_3c18;
	case 15386ULL: goto x86_l_3c1a;
	case 15390ULL: goto x86_l_3c1e;
	case 15394ULL: goto x86_l_3c22;
	case 15398ULL: goto x86_l_3c26;
	case 15402ULL: goto x86_l_3c2a;
	case 15407ULL: goto x86_l_3c2f;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15422ULL: goto x86_l_3c3e;
	case 15424ULL: goto x86_l_3c40;
	case 15428ULL: goto x86_l_3c44;
	case 15432ULL: goto x86_l_3c48;
	case 15437ULL: goto x86_l_3c4d;
	case 15442ULL: goto x86_l_3c52;
	case 15447ULL: goto x86_l_3c57;
	case 15452ULL: goto x86_l_3c5c;
	case 15455ULL: goto x86_l_3c5f;
	case 15457ULL: goto x86_l_3c61;
	case 15462ULL: goto x86_l_3c66;
	case 15466ULL: goto x86_l_3c6a;
	case 15471ULL: goto x86_l_3c6f;
	case 15476ULL: goto x86_l_3c74;
	case 15481ULL: goto x86_l_3c79;
	case 15486ULL: goto x86_l_3c7e;
	case 15488ULL: goto x86_l_3c80;
	case 15493ULL: goto x86_l_3c85;
	case 15498ULL: goto x86_l_3c8a;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15516ULL: goto x86_l_3c9c;
	case 15518ULL: goto x86_l_3c9e;
	case 15522ULL: goto x86_l_3ca2;
	case 15526ULL: goto x86_l_3ca6;
	case 15530ULL: goto x86_l_3caa;
	case 15534ULL: goto x86_l_3cae;
	case 15539ULL: goto x86_l_3cb3;
	case 15544ULL: goto x86_l_3cb8;
	case 15549ULL: goto x86_l_3cbd;
	case 15554ULL: goto x86_l_3cc2;
	case 15556ULL: goto x86_l_3cc4;
	case 15560ULL: goto x86_l_3cc8;
	case 15564ULL: goto x86_l_3ccc;
	case 15569ULL: goto x86_l_3cd1;
	case 15574ULL: goto x86_l_3cd6;
	case 15579ULL: goto x86_l_3cdb;
	case 15584ULL: goto x86_l_3ce0;
	case 15587ULL: goto x86_l_3ce3;
	case 15589ULL: goto x86_l_3ce5;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15604ULL: goto x86_l_3cf4;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15617ULL: goto x86_l_3d01;
	case 15619ULL: goto x86_l_3d03;
	case 15623ULL: goto x86_l_3d07;
	case 15627ULL: goto x86_l_3d0b;
	case 15631ULL: goto x86_l_3d0f;
	case 15635ULL: goto x86_l_3d13;
	case 15640ULL: goto x86_l_3d18;
	case 15645ULL: goto x86_l_3d1d;
	case 15650ULL: goto x86_l_3d22;
	case 15655ULL: goto x86_l_3d27;
	case 15657ULL: goto x86_l_3d29;
	case 15662ULL: goto x86_l_3d2e;
	case 15666ULL: goto x86_l_3d32;
	case 15671ULL: goto x86_l_3d37;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15686ULL: goto x86_l_3d46;
	case 15688ULL: goto x86_l_3d48;
	case 15693ULL: goto x86_l_3d4d;
	case 15697ULL: goto x86_l_3d51;
	case 15702ULL: goto x86_l_3d56;
	case 15707ULL: goto x86_l_3d5b;
	case 15712ULL: goto x86_l_3d60;
	case 15717ULL: goto x86_l_3d65;
	case 15720ULL: goto x86_l_3d68;
	case 15722ULL: goto x86_l_3d6a;
	case 15727ULL: goto x86_l_3d6f;
	case 15732ULL: goto x86_l_3d74;
	case 15737ULL: goto x86_l_3d79;
	case 15742ULL: goto x86_l_3d7e;
	case 15747ULL: goto x86_l_3d83;
	case 15750ULL: goto x86_l_3d86;
	case 15752ULL: goto x86_l_3d88;
	case 15756ULL: goto x86_l_3d8c;
	case 15760ULL: goto x86_l_3d90;
	case 15764ULL: goto x86_l_3d94;
	case 15768ULL: goto x86_l_3d98;
	case 15773ULL: goto x86_l_3d9d;
	case 15778ULL: goto x86_l_3da2;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15790ULL: goto x86_l_3dae;
	case 15795ULL: goto x86_l_3db3;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15819ULL: goto x86_l_3dcb;
	case 15821ULL: goto x86_l_3dcd;
	case 15826ULL: goto x86_l_3dd2;
	case 15828ULL: goto x86_l_3dd4;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15843ULL: goto x86_l_3de3;
	case 15848ULL: goto x86_l_3de8;
	case 15851ULL: goto x86_l_3deb;
	case 15853ULL: goto x86_l_3ded;
	case 15858ULL: goto x86_l_3df2;
	case 15863ULL: goto x86_l_3df7;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15878ULL: goto x86_l_3e06;
	case 15881ULL: goto x86_l_3e09;
	case 15883ULL: goto x86_l_3e0b;
	case 15887ULL: goto x86_l_3e0f;
	case 15891ULL: goto x86_l_3e13;
	case 15895ULL: goto x86_l_3e17;
	case 15899ULL: goto x86_l_3e1b;
	case 15904ULL: goto x86_l_3e20;
	case 15909ULL: goto x86_l_3e25;
	case 15914ULL: goto x86_l_3e2a;
	case 15919ULL: goto x86_l_3e2f;
	case 15921ULL: goto x86_l_3e31;
	case 15925ULL: goto x86_l_3e35;
	case 15929ULL: goto x86_l_3e39;
	case 15933ULL: goto x86_l_3e3d;
	case 15940ULL: goto x86_l_3e44;
	case 15945ULL: goto x86_l_3e49;
	case 15950ULL: goto x86_l_3e4e;
	case 15955ULL: goto x86_l_3e53;
	case 15960ULL: goto x86_l_3e58;
	case 15963ULL: goto x86_l_3e5b;
	case 15965ULL: goto x86_l_3e5d;
	case 15970ULL: goto x86_l_3e62;
	case 15974ULL: goto x86_l_3e66;
	case 15979ULL: goto x86_l_3e6b;
	case 15984ULL: goto x86_l_3e70;
	case 15989ULL: goto x86_l_3e75;
	default: return 0xffffffffffffffffULL;
	}
x86_l_376a:
	/* 0x376a: jne    3770 <trace_security_file_mprotect+0x3770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3770;
	}
x86_l_376c:
	/* 0x376c: jmp    37a2 <trace_security_file_mprotect+0x37a2> */
	goto x86_l_37a2;
x86_l_376e:
	/* 0x376e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3770:
	/* 0x3770: and    eax,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 6ULL);
x86_l_3773:
	/* 0x3773: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3776:
	/* 0x3776: jne    37a2 <trace_security_file_mprotect+0x37a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37a2;
	}
x86_l_3778:
	/* 0x3778: mov    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_3780:
	/* 0x3780: movzx  eax,BYTE PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_3786:
	/* 0x3786: and    al,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 4ULL);
x86_l_3788:
	/* 0x3788: shr    al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 2ULL);
x86_l_378b:
	/* 0x378b: cmp    QWORD PTR [r13+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3793:
	/* 0x3793: jne    37b6 <trace_security_file_mprotect+0x37b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37b6;
	}
x86_l_3795:
	/* 0x3795: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3797:
	/* 0x3797: jne    407c <trace_security_file_mprotect+0x407c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16508ULL;
	}
x86_l_379d:
	/* 0x379d: jmp    4152 <trace_security_file_mprotect+0x4152> */
	return 16722ULL;
x86_l_37a2:
	/* 0x37a2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_37a4:
	/* 0x37a4: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16722ULL;
	}
x86_l_37aa:
	/* 0x37aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37ac:
	/* 0x37ac: cmp    QWORD PTR [r13+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_37b4:
	/* 0x37b4: je     3795 <trace_security_file_mprotect+0x3795> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3795;
	}
x86_l_37b6:
	/* 0x37b6: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37ba:
	/* 0x37ba: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37c2:
	/* 0x37c2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_37c9:
	/* 0x37c9: ja     3814 <trace_security_file_mprotect+0x3814> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3814;
	}
x86_l_37cb:
	/* 0x37cb: mov    BYTE PTR [r13+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_37d4:
	/* 0x37d4: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_37da:
	/* 0x37da: ja     3814 <trace_security_file_mprotect+0x3814> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3814;
	}
x86_l_37dc:
	/* 0x37dc: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37e0:
	/* 0x37e0: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_37e7:
	/* 0x37e7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37ec:
	/* 0x37ec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_37f1:
	/* 0x37f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37f6:
	/* 0x37f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37fb:
	/* 0x37fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37fd:
	/* 0x37fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3800:
	/* 0x3800: js     3814 <trace_security_file_mprotect+0x3814> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3814;
	}
x86_l_3802:
	/* 0x3802: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3805:
	/* 0x3805: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_380d:
	/* 0x380d: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3814:
	/* 0x3814: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_381c:
	/* 0x381c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3823:
	/* 0x3823: ja     3871 <trace_security_file_mprotect+0x3871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3871;
	}
x86_l_3825:
	/* 0x3825: mov    BYTE PTR [r13+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_382e:
	/* 0x382e: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3834:
	/* 0x3834: ja     3871 <trace_security_file_mprotect+0x3871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3871;
	}
x86_l_3836:
	/* 0x3836: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_383a:
	/* 0x383a: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3841:
	/* 0x3841: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3849:
	/* 0x3849: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_384e:
	/* 0x384e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3853:
	/* 0x3853: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3858:
	/* 0x3858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_385a:
	/* 0x385a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_385d:
	/* 0x385d: js     3871 <trace_security_file_mprotect+0x3871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3871;
	}
x86_l_385f:
	/* 0x385f: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3862:
	/* 0x3862: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_386a:
	/* 0x386a: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3871:
	/* 0x3871: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3879:
	/* 0x3879: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3880:
	/* 0x3880: ja     38ce <trace_security_file_mprotect+0x38ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_38ce;
	}
x86_l_3882:
	/* 0x3882: mov    BYTE PTR [r13+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_388b:
	/* 0x388b: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3891:
	/* 0x3891: ja     38ce <trace_security_file_mprotect+0x38ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_38ce;
	}
x86_l_3893:
	/* 0x3893: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3897:
	/* 0x3897: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_389e:
	/* 0x389e: lea    rdx,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_38a6:
	/* 0x38a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38ab:
	/* 0x38ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38b0:
	/* 0x38b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38b5:
	/* 0x38b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b7:
	/* 0x38b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38ba:
	/* 0x38ba: js     38ce <trace_security_file_mprotect+0x38ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_38ce;
	}
x86_l_38bc:
	/* 0x38bc: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_38bf:
	/* 0x38bf: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38c7:
	/* 0x38c7: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_38ce:
	/* 0x38ce: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38d6:
	/* 0x38d6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_38dd:
	/* 0x38dd: ja     392b <trace_security_file_mprotect+0x392b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_392b;
	}
x86_l_38df:
	/* 0x38df: mov    BYTE PTR [r13+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_38e8:
	/* 0x38e8: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_38ee:
	/* 0x38ee: ja     392b <trace_security_file_mprotect+0x392b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_392b;
	}
x86_l_38f0:
	/* 0x38f0: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_38f4:
	/* 0x38f4: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_38fb:
	/* 0x38fb: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3903:
	/* 0x3903: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3908:
	/* 0x3908: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_390d:
	/* 0x390d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3912:
	/* 0x3912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3914:
	/* 0x3914: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3917:
	/* 0x3917: js     392b <trace_security_file_mprotect+0x392b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_392b;
	}
x86_l_3919:
	/* 0x3919: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_391c:
	/* 0x391c: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3924:
	/* 0x3924: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_392b:
	/* 0x392b: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3933:
	/* 0x3933: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_393a:
	/* 0x393a: ja     3988 <trace_security_file_mprotect+0x3988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3988;
	}
x86_l_393c:
	/* 0x393c: mov    BYTE PTR [r13+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_3945:
	/* 0x3945: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_394b:
	/* 0x394b: ja     3988 <trace_security_file_mprotect+0x3988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3988;
	}
x86_l_394d:
	/* 0x394d: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3951:
	/* 0x3951: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3958:
	/* 0x3958: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3960:
	/* 0x3960: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3965:
	/* 0x3965: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_396a:
	/* 0x396a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_396f:
	/* 0x396f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3971:
	/* 0x3971: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3974:
	/* 0x3974: js     3988 <trace_security_file_mprotect+0x3988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3988;
	}
x86_l_3976:
	/* 0x3976: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3979:
	/* 0x3979: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3981:
	/* 0x3981: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3988:
	/* 0x3988: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3990:
	/* 0x3990: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3993:
	/* 0x3993: je     3b4b <trace_security_file_mprotect+0x3b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b4b;
	}
x86_l_3999:
	/* 0x3999: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39a1:
	/* 0x39a1: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_39a7:
	/* 0x39a7: ja     3a34 <trace_security_file_mprotect+0x3a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a34;
	}
x86_l_39ad:
	/* 0x39ad: mov    BYTE PTR [r13+rax*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519557ULL);
x86_l_39b6:
	/* 0x39b6: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39be:
	/* 0x39be: mov    WORD PTR [r13+0x7d96],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32150ULL);
x86_l_39c6:
	/* 0x39c6: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_39cc:
	/* 0x39cc: ja     3a34 <trace_security_file_mprotect+0x3a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a34;
	}
x86_l_39ce:
	/* 0x39ce: lea    rcx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_39d2:
	/* 0x39d2: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_39d9:
	/* 0x39d9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39de:
	/* 0x39de: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39e3:
	/* 0x39e3: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39eb:
	/* 0x39eb: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_39ef:
	/* 0x39ef: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_39f6:
	/* 0x39f6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39fb:
	/* 0x39fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39fd:
	/* 0x39fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39ff:
	/* 0x39ff: jle    3a34 <trace_security_file_mprotect+0x3a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3a34;
	}
x86_l_3a01:
	/* 0x3a01: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a09:
	/* 0x3a09: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_3a10:
	/* 0x3a10: ja     3a34 <trace_security_file_mprotect+0x3a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a34;
	}
x86_l_3a12:
	/* 0x3a12: mov    DWORD PTR [rcx+r13*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_3a1a:
	/* 0x3a1a: add    ax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a22:
	/* 0x3a22: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3a25:
	/* 0x3a25: mov    WORD PTR [r13+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a2d:
	/* 0x3a2d: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3a34:
	/* 0x3a34: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a3c:
	/* 0x3a3c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3a43:
	/* 0x3a43: ja     3a91 <trace_security_file_mprotect+0x3a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a91;
	}
x86_l_3a45:
	/* 0x3a45: mov    BYTE PTR [r13+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_3a4e:
	/* 0x3a4e: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_3a54:
	/* 0x3a54: ja     3a91 <trace_security_file_mprotect+0x3a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a91;
	}
x86_l_3a56:
	/* 0x3a56: lea    rdx,[rsp+0x130] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3a5e:
	/* 0x3a5e: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3a62:
	/* 0x3a62: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3a69:
	/* 0x3a69: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3a6e:
	/* 0x3a6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a73:
	/* 0x3a73: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a78:
	/* 0x3a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7a:
	/* 0x3a7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a7d:
	/* 0x3a7d: js     3a91 <trace_security_file_mprotect+0x3a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a91;
	}
x86_l_3a7f:
	/* 0x3a7f: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3a82:
	/* 0x3a82: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a8a:
	/* 0x3a8a: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3a91:
	/* 0x3a91: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a99:
	/* 0x3a99: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3aa0:
	/* 0x3aa0: ja     3aee <trace_security_file_mprotect+0x3aee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3aee;
	}
x86_l_3aa2:
	/* 0x3aa2: mov    BYTE PTR [r13+rbx*1+0x89],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519559ULL);
x86_l_3aab:
	/* 0x3aab: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3ab1:
	/* 0x3ab1: ja     3aee <trace_security_file_mprotect+0x3aee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3aee;
	}
x86_l_3ab3:
	/* 0x3ab3: lea    rdx,[rsp+0x138] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3abb:
	/* 0x3abb: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3abf:
	/* 0x3abf: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3ac6:
	/* 0x3ac6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3acb:
	/* 0x3acb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ad0:
	/* 0x3ad0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ad5:
	/* 0x3ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ad7:
	/* 0x3ad7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ada:
	/* 0x3ada: js     3aee <trace_security_file_mprotect+0x3aee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3aee;
	}
x86_l_3adc:
	/* 0x3adc: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3adf:
	/* 0x3adf: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ae7:
	/* 0x3ae7: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3aee:
	/* 0x3aee: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3af6:
	/* 0x3af6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3afd:
	/* 0x3afd: ja     3b4b <trace_security_file_mprotect+0x3b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3b4b;
	}
x86_l_3aff:
	/* 0x3aff: mov    BYTE PTR [r13+rbx*1+0x89],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519560ULL);
x86_l_3b08:
	/* 0x3b08: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3b0e:
	/* 0x3b0e: ja     3b4b <trace_security_file_mprotect+0x3b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3b4b;
	}
x86_l_3b10:
	/* 0x3b10: lea    rdx,[rsp+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3b18:
	/* 0x3b18: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3b1c:
	/* 0x3b1c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3b23:
	/* 0x3b23: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b28:
	/* 0x3b28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b2d:
	/* 0x3b2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b32:
	/* 0x3b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b34:
	/* 0x3b34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b37:
	/* 0x3b37: js     3b4b <trace_security_file_mprotect+0x3b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b4b;
	}
x86_l_3b39:
	/* 0x3b39: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3b3c:
	/* 0x3b3c: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b44:
	/* 0x3b44: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3b4b:
	/* 0x3b4b: mov    rbx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_3b52:
	/* 0x3b52: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b56:
	/* 0x3b56: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b5b:
	/* 0x3b5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b60:
	/* 0x3b60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b65:
	/* 0x3b65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b6a:
	/* 0x3b6a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3b6d:
	/* 0x3b6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6f:
	/* 0x3b6f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b74:
	/* 0x3b74: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b7c:
	/* 0x3b7c: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b80:
	/* 0x3b80: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b85:
	/* 0x3b85: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b8a:
	/* 0x3b8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b8f:
	/* 0x3b8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b94:
	/* 0x3b94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b96:
	/* 0x3b96: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b9b:
	/* 0x3b9b: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3b9f:
	/* 0x3b9f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ba4:
	/* 0x3ba4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ba9:
	/* 0x3ba9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bae:
	/* 0x3bae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bb3:
	/* 0x3bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bb5:
	/* 0x3bb5: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bba:
	/* 0x3bba: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3bbe:
	/* 0x3bbe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bc3:
	/* 0x3bc3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3bc8:
	/* 0x3bc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bcd:
	/* 0x3bcd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3bd2:
	/* 0x3bd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd4:
	/* 0x3bd4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bd8:
	/* 0x3bd8: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3bdc:
	/* 0x3bdc: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3be0:
	/* 0x3be0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3be5:
	/* 0x3be5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bea:
	/* 0x3bea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bef:
	/* 0x3bef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bf4:
	/* 0x3bf4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3bf7:
	/* 0x3bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bf9:
	/* 0x3bf9: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_3bfc:
	/* 0x3bfc: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c01:
	/* 0x3c01: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c06:
	/* 0x3c06: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c10:
	/* 0x3c10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c15:
	/* 0x3c15: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3c18:
	/* 0x3c18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1a:
	/* 0x3c1a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c1e:
	/* 0x3c1e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3c22:
	/* 0x3c22: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3c26:
	/* 0x3c26: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c2a:
	/* 0x3c2a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c2f:
	/* 0x3c2f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3c34:
	/* 0x3c34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c39:
	/* 0x3c39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c3e:
	/* 0x3c3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c40:
	/* 0x3c40: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c44:
	/* 0x3c44: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3c48:
	/* 0x3c48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c4d:
	/* 0x3c4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c52:
	/* 0x3c52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c57:
	/* 0x3c57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5c:
	/* 0x3c5c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3c5f:
	/* 0x3c5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c61:
	/* 0x3c61: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c66:
	/* 0x3c66: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c6a:
	/* 0x3c6a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c6f:
	/* 0x3c6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c74:
	/* 0x3c74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c79:
	/* 0x3c79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c7e:
	/* 0x3c7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c80:
	/* 0x3c80: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c85:
	/* 0x3c85: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c8a:
	/* 0x3c8a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3c8f:
	/* 0x3c8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c94:
	/* 0x3c94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c99:
	/* 0x3c99: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3c9c:
	/* 0x3c9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9e:
	/* 0x3c9e: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ca2:
	/* 0x3ca2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3ca6:
	/* 0x3ca6: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3caa:
	/* 0x3caa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3cae:
	/* 0x3cae: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cb3:
	/* 0x3cb3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3cb8:
	/* 0x3cb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cbd:
	/* 0x3cbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cc2:
	/* 0x3cc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc4:
	/* 0x3cc4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cc8:
	/* 0x3cc8: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ccc:
	/* 0x3ccc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cd1:
	/* 0x3cd1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cdb:
	/* 0x3cdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ce0:
	/* 0x3ce0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3ce3:
	/* 0x3ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ce5:
	/* 0x3ce5: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cea:
	/* 0x3cea: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cef:
	/* 0x3cef: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3cf4:
	/* 0x3cf4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cf9:
	/* 0x3cf9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cfe:
	/* 0x3cfe: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3d01:
	/* 0x3d01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d03:
	/* 0x3d03: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d07:
	/* 0x3d07: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3d0b:
	/* 0x3d0b: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d0f:
	/* 0x3d0f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d13:
	/* 0x3d13: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d18:
	/* 0x3d18: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d1d:
	/* 0x3d1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d22:
	/* 0x3d22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d27:
	/* 0x3d27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d29:
	/* 0x3d29: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d2e:
	/* 0x3d2e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3d32:
	/* 0x3d32: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d37:
	/* 0x3d37: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3d3c:
	/* 0x3d3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d41:
	/* 0x3d41: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d46:
	/* 0x3d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d48:
	/* 0x3d48: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d4d:
	/* 0x3d4d: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d51:
	/* 0x3d51: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d56:
	/* 0x3d56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d5b:
	/* 0x3d5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d60:
	/* 0x3d60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d65:
	/* 0x3d65: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3d68:
	/* 0x3d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d6a:
	/* 0x3d6a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d6f:
	/* 0x3d6f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d74:
	/* 0x3d74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3d79:
	/* 0x3d79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d7e:
	/* 0x3d7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d83:
	/* 0x3d83: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3d86:
	/* 0x3d86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d88:
	/* 0x3d88: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d8c:
	/* 0x3d8c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3d90:
	/* 0x3d90: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d94:
	/* 0x3d94: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d98:
	/* 0x3d98: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d9d:
	/* 0x3d9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3da2:
	/* 0x3da2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3da7:
	/* 0x3da7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dac:
	/* 0x3dac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dae:
	/* 0x3dae: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3db3:
	/* 0x3db3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3db7:
	/* 0x3db7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dbc:
	/* 0x3dbc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3dc1:
	/* 0x3dc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dc6:
	/* 0x3dc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3dcb:
	/* 0x3dcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dcd:
	/* 0x3dcd: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_3dd2:
	/* 0x3dd2: jne    3e39 <trace_security_file_mprotect+0x3e39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e39;
	}
x86_l_3dd4:
	/* 0x3dd4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dd9:
	/* 0x3dd9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3dde:
	/* 0x3dde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3de3:
	/* 0x3de3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de8:
	/* 0x3de8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3deb:
	/* 0x3deb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ded:
	/* 0x3ded: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3df2:
	/* 0x3df2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3df7:
	/* 0x3df7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3dfc:
	/* 0x3dfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e01:
	/* 0x3e01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e06:
	/* 0x3e06: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3e09:
	/* 0x3e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e0b:
	/* 0x3e0b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e0f:
	/* 0x3e0f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3e13:
	/* 0x3e13: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3e17:
	/* 0x3e17: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3e1b:
	/* 0x3e1b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e20:
	/* 0x3e20: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3e25:
	/* 0x3e25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e2a:
	/* 0x3e2a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e2f:
	/* 0x3e2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e31:
	/* 0x3e31: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e35:
	/* 0x3e35: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e39:
	/* 0x3e39: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e3d:
	/* 0x3e3d: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3e44:
	/* 0x3e44: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e49:
	/* 0x3e49: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e4e:
	/* 0x3e4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e53:
	/* 0x3e53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e58:
	/* 0x3e58: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e5b:
	/* 0x3e5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e5d:
	/* 0x3e5d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e62:
	/* 0x3e62: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e66:
	/* 0x3e66: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e6b:
	/* 0x3e6b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e70:
	/* 0x3e70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e75:
	/* 0x3e75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 15994ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15994ULL: goto x86_l_3e7a;
	case 15996ULL: goto x86_l_3e7c;
	case 16001ULL: goto x86_l_3e81;
	case 16006ULL: goto x86_l_3e86;
	case 16011ULL: goto x86_l_3e8b;
	case 16016ULL: goto x86_l_3e90;
	case 16021ULL: goto x86_l_3e95;
	case 16026ULL: goto x86_l_3e9a;
	case 16028ULL: goto x86_l_3e9c;
	case 16032ULL: goto x86_l_3ea0;
	case 16036ULL: goto x86_l_3ea4;
	case 16041ULL: goto x86_l_3ea9;
	case 16043ULL: goto x86_l_3eab;
	case 16047ULL: goto x86_l_3eaf;
	case 16051ULL: goto x86_l_3eb3;
	case 16056ULL: goto x86_l_3eb8;
	case 16061ULL: goto x86_l_3ebd;
	case 16066ULL: goto x86_l_3ec2;
	case 16071ULL: goto x86_l_3ec7;
	case 16073ULL: goto x86_l_3ec9;
	case 16078ULL: goto x86_l_3ece;
	case 16082ULL: goto x86_l_3ed2;
	case 16090ULL: goto x86_l_3eda;
	case 16094ULL: goto x86_l_3ede;
	case 16099ULL: goto x86_l_3ee3;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16114ULL: goto x86_l_3ef2;
	case 16116ULL: goto x86_l_3ef4;
	case 16121ULL: goto x86_l_3ef9;
	case 16125ULL: goto x86_l_3efd;
	case 16129ULL: goto x86_l_3f01;
	case 16134ULL: goto x86_l_3f06;
	case 16139ULL: goto x86_l_3f0b;
	case 16144ULL: goto x86_l_3f10;
	case 16149ULL: goto x86_l_3f15;
	case 16152ULL: goto x86_l_3f18;
	case 16154ULL: goto x86_l_3f1a;
	case 16159ULL: goto x86_l_3f1f;
	case 16163ULL: goto x86_l_3f23;
	case 16168ULL: goto x86_l_3f28;
	case 16173ULL: goto x86_l_3f2d;
	case 16178ULL: goto x86_l_3f32;
	case 16183ULL: goto x86_l_3f37;
	case 16186ULL: goto x86_l_3f3a;
	case 16188ULL: goto x86_l_3f3c;
	case 16193ULL: goto x86_l_3f41;
	case 16196ULL: goto x86_l_3f44;
	case 16198ULL: goto x86_l_3f46;
	case 16203ULL: goto x86_l_3f4b;
	case 16211ULL: goto x86_l_3f53;
	case 16215ULL: goto x86_l_3f57;
	case 16223ULL: goto x86_l_3f5f;
	case 16228ULL: goto x86_l_3f64;
	case 16233ULL: goto x86_l_3f69;
	case 16238ULL: goto x86_l_3f6e;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16250ULL: goto x86_l_3f7a;
	case 16255ULL: goto x86_l_3f7f;
	case 16260ULL: goto x86_l_3f84;
	case 16263ULL: goto x86_l_3f87;
	case 16265ULL: goto x86_l_3f89;
	case 16270ULL: goto x86_l_3f8e;
	case 16275ULL: goto x86_l_3f93;
	case 16280ULL: goto x86_l_3f98;
	case 16285ULL: goto x86_l_3f9d;
	case 16290ULL: goto x86_l_3fa2;
	case 16292ULL: goto x86_l_3fa4;
	case 16297ULL: goto x86_l_3fa9;
	case 16302ULL: goto x86_l_3fae;
	case 16307ULL: goto x86_l_3fb3;
	case 16312ULL: goto x86_l_3fb8;
	case 16315ULL: goto x86_l_3fbb;
	case 16320ULL: goto x86_l_3fc0;
	case 16322ULL: goto x86_l_3fc2;
	case 16326ULL: goto x86_l_3fc6;
	case 16331ULL: goto x86_l_3fcb;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16344ULL: goto x86_l_3fd8;
	case 16346ULL: goto x86_l_3fda;
	case 16351ULL: goto x86_l_3fdf;
	case 16356ULL: goto x86_l_3fe4;
	case 16364ULL: goto x86_l_3fec;
	case 16372ULL: goto x86_l_3ff4;
	case 16377ULL: goto x86_l_3ff9;
	case 16379ULL: goto x86_l_3ffb;
	case 16387ULL: goto x86_l_4003;
	case 16391ULL: goto x86_l_4007;
	case 16399ULL: goto x86_l_400f;
	case 16401ULL: goto x86_l_4011;
	case 16408ULL: goto x86_l_4018;
	case 16413ULL: goto x86_l_401d;
	case 16418ULL: goto x86_l_4022;
	case 16423ULL: goto x86_l_4027;
	case 16426ULL: goto x86_l_402a;
	case 16428ULL: goto x86_l_402c;
	case 16430ULL: goto x86_l_402e;
	case 16432ULL: goto x86_l_4030;
	case 16436ULL: goto x86_l_4034;
	case 16444ULL: goto x86_l_403c;
	case 16449ULL: goto x86_l_4041;
	case 16454ULL: goto x86_l_4046;
	case 16457ULL: goto x86_l_4049;
	case 16463ULL: goto x86_l_404f;
	case 16467ULL: goto x86_l_4053;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16484ULL: goto x86_l_4064;
	case 16489ULL: goto x86_l_4069;
	case 16492ULL: goto x86_l_406c;
	case 16495ULL: goto x86_l_406f;
	case 16497ULL: goto x86_l_4071;
	case 16502ULL: goto x86_l_4076;
	case 16508ULL: goto x86_l_407c;
	case 16512ULL: goto x86_l_4080;
	case 16516ULL: goto x86_l_4084;
	case 16524ULL: goto x86_l_408c;
	case 16532ULL: goto x86_l_4094;
	case 16537ULL: goto x86_l_4099;
	case 16542ULL: goto x86_l_409e;
	case 16547ULL: goto x86_l_40a3;
	case 16550ULL: goto x86_l_40a6;
	case 16552ULL: goto x86_l_40a8;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16570ULL: goto x86_l_40ba;
	case 16575ULL: goto x86_l_40bf;
	case 16580ULL: goto x86_l_40c4;
	case 16582ULL: goto x86_l_40c6;
	case 16590ULL: goto x86_l_40ce;
	case 16598ULL: goto x86_l_40d6;
	case 16610ULL: goto x86_l_40e2;
	case 16617ULL: goto x86_l_40e9;
	case 16624ULL: goto x86_l_40f0;
	case 16632ULL: goto x86_l_40f8;
	case 16638ULL: goto x86_l_40fe;
	case 16640ULL: goto x86_l_4100;
	case 16644ULL: goto x86_l_4104;
	case 16651ULL: goto x86_l_410b;
	case 16659ULL: goto x86_l_4113;
	case 16664ULL: goto x86_l_4118;
	case 16669ULL: goto x86_l_411d;
	case 16677ULL: goto x86_l_4125;
	case 16681ULL: goto x86_l_4129;
	case 16688ULL: goto x86_l_4130;
	case 16693ULL: goto x86_l_4135;
	case 16695ULL: goto x86_l_4137;
	case 16702ULL: goto x86_l_413e;
	case 16707ULL: goto x86_l_4143;
	case 16712ULL: goto x86_l_4148;
	case 16715ULL: goto x86_l_414b;
	case 16720ULL: goto x86_l_4150;
	case 16722ULL: goto x86_l_4152;
	case 16724ULL: goto x86_l_4154;
	case 16731ULL: goto x86_l_415b;
	case 16732ULL: goto x86_l_415c;
	case 16734ULL: goto x86_l_415e;
	case 16736ULL: goto x86_l_4160;
	case 16738ULL: goto x86_l_4162;
	case 16740ULL: goto x86_l_4164;
	case 16741ULL: goto x86_l_4165;
	case 16746ULL: goto x86_l_416a;
	case 16749ULL: goto x86_l_416d;
	case 16755ULL: goto x86_l_4173;
	case 16759ULL: goto x86_l_4177;
	case 16764ULL: goto x86_l_417c;
	case 16770ULL: goto x86_l_4182;
	case 16774ULL: goto x86_l_4186;
	case 16779ULL: goto x86_l_418b;
	case 16784ULL: goto x86_l_4190;
	case 16789ULL: goto x86_l_4195;
	case 16793ULL: goto x86_l_4199;
	case 16797ULL: goto x86_l_419d;
	case 16802ULL: goto x86_l_41a2;
	case 16804ULL: goto x86_l_41a4;
	case 16808ULL: goto x86_l_41a8;
	case 16811ULL: goto x86_l_41ab;
	case 16816ULL: goto x86_l_41b0;
	case 16821ULL: goto x86_l_41b5;
	case 16825ULL: goto x86_l_41b9;
	case 16830ULL: goto x86_l_41be;
	case 16832ULL: goto x86_l_41c0;
	case 16836ULL: goto x86_l_41c4;
	case 16841ULL: goto x86_l_41c9;
	case 16846ULL: goto x86_l_41ce;
	case 16851ULL: goto x86_l_41d3;
	case 16855ULL: goto x86_l_41d7;
	case 16860ULL: goto x86_l_41dc;
	case 16862ULL: goto x86_l_41de;
	case 16866ULL: goto x86_l_41e2;
	case 16870ULL: goto x86_l_41e6;
	case 16875ULL: goto x86_l_41eb;
	case 16880ULL: goto x86_l_41f0;
	case 16885ULL: goto x86_l_41f5;
	case 16890ULL: goto x86_l_41fa;
	case 16893ULL: goto x86_l_41fd;
	case 16895ULL: goto x86_l_41ff;
	case 16900ULL: goto x86_l_4204;
	case 16905ULL: goto x86_l_4209;
	case 16909ULL: goto x86_l_420d;
	case 16914ULL: goto x86_l_4212;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16931ULL: goto x86_l_4223;
	case 16936ULL: goto x86_l_4228;
	case 16939ULL: goto x86_l_422b;
	case 16945ULL: goto x86_l_4231;
	case 16950ULL: goto x86_l_4236;
	case 16953ULL: goto x86_l_4239;
	case 16959ULL: goto x86_l_423f;
	case 16963ULL: goto x86_l_4243;
	case 16968ULL: goto x86_l_4248;
	case 16973ULL: goto x86_l_424d;
	case 16978ULL: goto x86_l_4252;
	case 16983ULL: goto x86_l_4257;
	case 16985ULL: goto x86_l_4259;
	case 16989ULL: goto x86_l_425d;
	case 16991ULL: goto x86_l_425f;
	case 16997ULL: goto x86_l_4265;
	case 17000ULL: goto x86_l_4268;
	case 17002ULL: goto x86_l_426a;
	case 17008ULL: goto x86_l_4270;
	case 17013ULL: goto x86_l_4275;
	case 17019ULL: goto x86_l_427b;
	case 17022ULL: goto x86_l_427e;
	case 17024ULL: goto x86_l_4280;
	case 17029ULL: goto x86_l_4285;
	case 17031ULL: goto x86_l_4287;
	case 17034ULL: goto x86_l_428a;
	case 17040ULL: goto x86_l_4290;
	case 17044ULL: goto x86_l_4294;
	case 17050ULL: goto x86_l_429a;
	case 17054ULL: goto x86_l_429e;
	case 17057ULL: goto x86_l_42a1;
	case 17062ULL: goto x86_l_42a6;
	case 17067ULL: goto x86_l_42ab;
	case 17070ULL: goto x86_l_42ae;
	case 17076ULL: goto x86_l_42b4;
	case 17080ULL: goto x86_l_42b8;
	case 17085ULL: goto x86_l_42bd;
	case 17091ULL: goto x86_l_42c3;
	case 17095ULL: goto x86_l_42c7;
	case 17100ULL: goto x86_l_42cc;
	case 17105ULL: goto x86_l_42d1;
	case 17110ULL: goto x86_l_42d6;
	case 17114ULL: goto x86_l_42da;
	case 17118ULL: goto x86_l_42de;
	case 17123ULL: goto x86_l_42e3;
	case 17125ULL: goto x86_l_42e5;
	case 17129ULL: goto x86_l_42e9;
	case 17132ULL: goto x86_l_42ec;
	case 17137ULL: goto x86_l_42f1;
	case 17142ULL: goto x86_l_42f6;
	case 17146ULL: goto x86_l_42fa;
	case 17151ULL: goto x86_l_42ff;
	case 17153ULL: goto x86_l_4301;
	case 17157ULL: goto x86_l_4305;
	case 17162ULL: goto x86_l_430a;
	case 17167ULL: goto x86_l_430f;
	case 17172ULL: goto x86_l_4314;
	case 17176ULL: goto x86_l_4318;
	case 17181ULL: goto x86_l_431d;
	case 17183ULL: goto x86_l_431f;
	case 17187ULL: goto x86_l_4323;
	case 17191ULL: goto x86_l_4327;
	case 17193ULL: goto x86_l_4329;
	case 17200ULL: goto x86_l_4330;
	case 17203ULL: goto x86_l_4333;
	case 17207ULL: goto x86_l_4337;
	case 17212ULL: goto x86_l_433c;
	case 17217ULL: goto x86_l_4341;
	case 17222ULL: goto x86_l_4346;
	case 17224ULL: goto x86_l_4348;
	case 17227ULL: goto x86_l_434b;
	case 17233ULL: goto x86_l_4351;
	case 17238ULL: goto x86_l_4356;
	case 17243ULL: goto x86_l_435b;
	case 17248ULL: goto x86_l_4360;
	case 17253ULL: goto x86_l_4365;
	case 17259ULL: goto x86_l_436b;
	case 17262ULL: goto x86_l_436e;
	case 17264ULL: goto x86_l_4370;
	case 17269ULL: goto x86_l_4375;
	case 17271ULL: goto x86_l_4377;
	case 17274ULL: goto x86_l_437a;
	case 17280ULL: goto x86_l_4380;
	case 17284ULL: goto x86_l_4384;
	case 17290ULL: goto x86_l_438a;
	case 17294ULL: goto x86_l_438e;
	case 17297ULL: goto x86_l_4391;
	case 17302ULL: goto x86_l_4396;
	case 17307ULL: goto x86_l_439b;
	case 17312ULL: goto x86_l_43a0;
	case 17317ULL: goto x86_l_43a5;
	case 17322ULL: goto x86_l_43aa;
	case 17325ULL: goto x86_l_43ad;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17337ULL: goto x86_l_43b9;
	case 17341ULL: goto x86_l_43bd;
	case 17346ULL: goto x86_l_43c2;
	case 17351ULL: goto x86_l_43c7;
	case 17356ULL: goto x86_l_43cc;
	case 17361ULL: goto x86_l_43d1;
	case 17363ULL: goto x86_l_43d3;
	case 17368ULL: goto x86_l_43d8;
	case 17371ULL: goto x86_l_43db;
	case 17377ULL: goto x86_l_43e1;
	case 17382ULL: goto x86_l_43e6;
	case 17385ULL: goto x86_l_43e9;
	case 17391ULL: goto x86_l_43ef;
	case 17395ULL: goto x86_l_43f3;
	case 17400ULL: goto x86_l_43f8;
	case 17405ULL: goto x86_l_43fd;
	case 17410ULL: goto x86_l_4402;
	case 17415ULL: goto x86_l_4407;
	case 17417ULL: goto x86_l_4409;
	case 17421ULL: goto x86_l_440d;
	case 17423ULL: goto x86_l_440f;
	case 17429ULL: goto x86_l_4415;
	case 17432ULL: goto x86_l_4418;
	case 17434ULL: goto x86_l_441a;
	case 17440ULL: goto x86_l_4420;
	case 17445ULL: goto x86_l_4425;
	case 17451ULL: goto x86_l_442b;
	case 17454ULL: goto x86_l_442e;
	case 17456ULL: goto x86_l_4430;
	case 17461ULL: goto x86_l_4435;
	case 17463ULL: goto x86_l_4437;
	case 17466ULL: goto x86_l_443a;
	case 17472ULL: goto x86_l_4440;
	case 17476ULL: goto x86_l_4444;
	case 17482ULL: goto x86_l_444a;
	case 17486ULL: goto x86_l_444e;
	case 17489ULL: goto x86_l_4451;
	case 17494ULL: goto x86_l_4456;
	case 17499ULL: goto x86_l_445b;
	case 17502ULL: goto x86_l_445e;
	case 17508ULL: goto x86_l_4464;
	case 17512ULL: goto x86_l_4468;
	case 17517ULL: goto x86_l_446d;
	case 17523ULL: goto x86_l_4473;
	case 17527ULL: goto x86_l_4477;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17542ULL: goto x86_l_4486;
	case 17546ULL: goto x86_l_448a;
	case 17550ULL: goto x86_l_448e;
	case 17555ULL: goto x86_l_4493;
	case 17557ULL: goto x86_l_4495;
	case 17561ULL: goto x86_l_4499;
	case 17564ULL: goto x86_l_449c;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17578ULL: goto x86_l_44aa;
	case 17583ULL: goto x86_l_44af;
	case 17585ULL: goto x86_l_44b1;
	case 17589ULL: goto x86_l_44b5;
	case 17594ULL: goto x86_l_44ba;
	case 17599ULL: goto x86_l_44bf;
	case 17604ULL: goto x86_l_44c4;
	case 17608ULL: goto x86_l_44c8;
	case 17613ULL: goto x86_l_44cd;
	case 17615ULL: goto x86_l_44cf;
	case 17619ULL: goto x86_l_44d3;
	case 17623ULL: goto x86_l_44d7;
	case 17628ULL: goto x86_l_44dc;
	case 17633ULL: goto x86_l_44e1;
	case 17638ULL: goto x86_l_44e6;
	case 17643ULL: goto x86_l_44eb;
	case 17646ULL: goto x86_l_44ee;
	case 17648ULL: goto x86_l_44f0;
	case 17653ULL: goto x86_l_44f5;
	case 17658ULL: goto x86_l_44fa;
	case 17662ULL: goto x86_l_44fe;
	case 17667ULL: goto x86_l_4503;
	case 17672ULL: goto x86_l_4508;
	case 17677ULL: goto x86_l_450d;
	case 17682ULL: goto x86_l_4512;
	case 17684ULL: goto x86_l_4514;
	case 17689ULL: goto x86_l_4519;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3e7a:
	/* 0x3e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e7c:
	/* 0x3e7c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e81:
	/* 0x3e81: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e86:
	/* 0x3e86: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e8b:
	/* 0x3e8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e90:
	/* 0x3e90: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e95:
	/* 0x3e95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e9a:
	/* 0x3e9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e9c:
	/* 0x3e9c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ea0:
	/* 0x3ea0: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3ea4:
	/* 0x3ea4: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3ea9:
	/* 0x3ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eab:
	/* 0x3eab: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3eaf:
	/* 0x3eaf: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3eb3:
	/* 0x3eb3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3eb8:
	/* 0x3eb8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ebd:
	/* 0x3ebd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ec2:
	/* 0x3ec2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ec7:
	/* 0x3ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec9:
	/* 0x3ec9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ece:
	/* 0x3ece: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed2:
	/* 0x3ed2: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3eda:
	/* 0x3eda: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3ede:
	/* 0x3ede: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ee3:
	/* 0x3ee3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3eed:
	/* 0x3eed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef2:
	/* 0x3ef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef4:
	/* 0x3ef4: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ef9:
	/* 0x3ef9: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3efd:
	/* 0x3efd: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3f01:
	/* 0x3f01: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f06:
	/* 0x3f06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f0b:
	/* 0x3f0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f10:
	/* 0x3f10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f15:
	/* 0x3f15: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3f18:
	/* 0x3f18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f1a:
	/* 0x3f1a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f1f:
	/* 0x3f1f: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f23:
	/* 0x3f23: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f28:
	/* 0x3f28: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3f2d:
	/* 0x3f2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f32:
	/* 0x3f32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f37:
	/* 0x3f37: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3f3a:
	/* 0x3f3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3c:
	/* 0x3f3c: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_3f41:
	/* 0x3f41: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_3f44:
	/* 0x3f44: je     3f4b <trace_security_file_mprotect+0x3f4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4b;
	}
x86_l_3f46:
	/* 0x3f46: or     BYTE PTR [r13+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_3f4b:
	/* 0x3f4b: mov    QWORD PTR [r13+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_3f53:
	/* 0x3f53: lea    rdi,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3f57:
	/* 0x3f57: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_3f5f:
	/* 0x3f5f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3f64:
	/* 0x3f64: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_3f69:
	/* 0x3f69: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f6e:
	/* 0x3f6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f70:
	/* 0x3f70: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f75:
	/* 0x3f75: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f7a:
	/* 0x3f7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f7f:
	/* 0x3f7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f84:
	/* 0x3f84: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3f87:
	/* 0x3f87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f89:
	/* 0x3f89: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f8e:
	/* 0x3f8e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f93:
	/* 0x3f93: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f98:
	/* 0x3f98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f9d:
	/* 0x3f9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fa2:
	/* 0x3fa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fa4:
	/* 0x3fa4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3fa9:
	/* 0x3fa9: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3fae:
	/* 0x3fae: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_3fb3:
	/* 0x3fb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fb8:
	/* 0x3fb8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3fbb:
	/* 0x3fbb: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_3fc0:
	/* 0x3fc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc2:
	/* 0x3fc2: lea    rdi,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3fc6:
	/* 0x3fc6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3fcb:
	/* 0x3fcb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3fd5:
	/* 0x3fd5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3fd8:
	/* 0x3fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fda:
	/* 0x3fda: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_3fdf:
	/* 0x3fdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fe4:
	/* 0x3fe4: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3fec:
	/* 0x3fec: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3ff4:
	/* 0x3ff4: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_3ff9:
	/* 0x3ff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ffb:
	/* 0x3ffb: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4003:
	/* 0x4003: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_4007:
	/* 0x4007: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_400f:
	/* 0x400f: je     4034 <trace_security_file_mprotect+0x4034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4034;
	}
x86_l_4011:
	/* 0x4011: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_4018:
	/* 0x4018: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_401d:
	/* 0x401d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_4022:
	/* 0x4022: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_4027:
	/* 0x4027: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_402a:
	/* 0x402a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402c:
	/* 0x402c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_402e:
	/* 0x402e: js     4034 <trace_security_file_mprotect+0x4034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4034;
	}
x86_l_4030:
	/* 0x4030: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4034:
	/* 0x4034: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_403c:
	/* 0x403c: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_4041:
	/* 0x4041: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_4046:
	/* 0x4046: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4049:
	/* 0x4049: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_404f:
	/* 0x404f: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4053:
	/* 0x4053: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_405a:
	/* 0x405a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_405f:
	/* 0x405f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4064:
	/* 0x4064: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_4069:
	/* 0x4069: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_406c:
	/* 0x406c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_406f:
	/* 0x406f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4071:
	/* 0x4071: cmp    BYTE PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4076:
	/* 0x4076: je     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4152;
	}
x86_l_407c:
	/* 0x407c: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4080:
	/* 0x4080: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4084:
	/* 0x4084: mov    BYTE PTR [rsp+0x148],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273090ULL);
x86_l_408c:
	/* 0x408c: lea    rdi,[rsp+0x149] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 329ULL);
x86_l_4094:
	/* 0x4094: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4099:
	/* 0x4099: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_409e:
	/* 0x409e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40a3:
	/* 0x40a3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_40a6:
	/* 0x40a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40a8:
	/* 0x40a8: lea    rdi,[rsp+0x151] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 337ULL);
x86_l_40b0:
	/* 0x40b0: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40b5:
	/* 0x40b5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_40ba:
	/* 0x40ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40bf:
	/* 0x40bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40c4:
	/* 0x40c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c6:
	/* 0x40c6: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_40ce:
	/* 0x40ce: mov    QWORD PTR [rsp+0x168],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_40d6:
	/* 0x40d6: mov    QWORD PTR [rsp+0x170],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1580547964928ULL);
x86_l_40e2:
	/* 0x40e2: mov    eax,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_40e9:
	/* 0x40e9: mov    DWORD PTR [rsp+0x178],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_40f0:
	/* 0x40f0: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40f8:
	/* 0x40f8: cmp    rax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31935ULL);
x86_l_40fe:
	/* 0x40fe: ja     4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4152;
	}
x86_l_4100:
	/* 0x4100: lea    rcx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_4104:
	/* 0x4104: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_410b:
	/* 0x410b: lea    rdx,[rsp+0x148] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4113:
	/* 0x4113: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_4118:
	/* 0x4118: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_411d:
	/* 0x411d: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4125:
	/* 0x4125: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_4129:
	/* 0x4129: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4130:
	/* 0x4130: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_4135:
	/* 0x4135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4137:
	/* 0x4137: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_413e:
	/* 0x413e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4143:
	/* 0x4143: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4148:
	/* 0x4148: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_414b:
	/* 0x414b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4150:
	/* 0x4150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4152:
	/* 0x4152: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4154:
	/* 0x4154: add    rsp,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_415b:
	/* 0x415b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_415c:
	/* 0x415c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_415e:
	/* 0x415e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_4160:
	/* 0x4160: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4162:
	/* 0x4162: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4164:
	/* 0x4164: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4165:
	/* 0x4165: jmp    6c21 <trace_security_file_mprotect+0x6c21> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_416a:
	/* 0x416a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_416d:
	/* 0x416d: jne    1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6547ULL;
	}
x86_l_4173:
	/* 0x4173: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4177:
	/* 0x4177: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_417c:
	/* 0x417c: je     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6547ULL;
	}
x86_l_4182:
	/* 0x4182: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4186:
	/* 0x4186: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_418b:
	/* 0x418b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4190:
	/* 0x4190: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4195:
	/* 0x4195: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4199:
	/* 0x4199: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_419d:
	/* 0x419d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41a2:
	/* 0x41a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a4:
	/* 0x41a4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a8:
	/* 0x41a8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41ab:
	/* 0x41ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41b0:
	/* 0x41b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41b5:
	/* 0x41b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b9:
	/* 0x41b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41be:
	/* 0x41be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c0:
	/* 0x41c0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41c4:
	/* 0x41c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_41c9:
	/* 0x41c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41ce:
	/* 0x41ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41d3:
	/* 0x41d3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d7:
	/* 0x41d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41dc:
	/* 0x41dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41de:
	/* 0x41de: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e2:
	/* 0x41e2: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_41e6:
	/* 0x41e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41eb:
	/* 0x41eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41f0:
	/* 0x41f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41f5:
	/* 0x41f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41fa:
	/* 0x41fa: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_41fd:
	/* 0x41fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ff:
	/* 0x41ff: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4204:
	/* 0x4204: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4209:
	/* 0x4209: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_420d:
	/* 0x420d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4212:
	/* 0x4212: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4217:
	/* 0x4217: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_421c:
	/* 0x421c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4221:
	/* 0x4221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4223:
	/* 0x4223: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4228:
	/* 0x4228: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_422b:
	/* 0x422b: je     445b <trace_security_file_mprotect+0x445b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445b;
	}
x86_l_4231:
	/* 0x4231: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4236:
	/* 0x4236: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4239:
	/* 0x4239: je     445b <trace_security_file_mprotect+0x445b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445b;
	}
x86_l_423f:
	/* 0x423f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4243:
	/* 0x4243: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4248:
	/* 0x4248: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_424d:
	/* 0x424d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4252:
	/* 0x4252: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4257:
	/* 0x4257: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4259:
	/* 0x4259: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_425d:
	/* 0x425d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_425f:
	/* 0x425f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4265:
	/* 0x4265: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4268:
	/* 0x4268: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_426a:
	/* 0x426a: jb     31c0 <trace_security_file_mprotect+0x31c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12736ULL;
	}
x86_l_4270:
	/* 0x4270: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4275:
	/* 0x4275: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_427b:
	/* 0x427b: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_427e:
	/* 0x427e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4280:
	/* 0x4280: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4285:
	/* 0x4285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4287:
	/* 0x4287: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_428a:
	/* 0x428a: jl     1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6547ULL;
	}
x86_l_4290:
	/* 0x4290: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4294:
	/* 0x4294: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_429a:
	/* 0x429a: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_429e:
	/* 0x429e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_42a1:
	/* 0x42a1: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a6:
	/* 0x42a6: jmp    44d7 <trace_security_file_mprotect+0x44d7> */
	goto x86_l_44d7;
x86_l_42ab:
	/* 0x42ab: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_42ae:
	/* 0x42ae: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_42b4:
	/* 0x42b4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42b8:
	/* 0x42b8: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_42bd:
	/* 0x42bd: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_42c3:
	/* 0x42c3: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42c7:
	/* 0x42c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42cc:
	/* 0x42cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42d1:
	/* 0x42d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42d6:
	/* 0x42d6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42da:
	/* 0x42da: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42de:
	/* 0x42de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42e3:
	/* 0x42e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e5:
	/* 0x42e5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e9:
	/* 0x42e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42ec:
	/* 0x42ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42f1:
	/* 0x42f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42f6:
	/* 0x42f6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42fa:
	/* 0x42fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ff:
	/* 0x42ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4301:
	/* 0x4301: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4305:
	/* 0x4305: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_430a:
	/* 0x430a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_430f:
	/* 0x430f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4314:
	/* 0x4314: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4318:
	/* 0x4318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_431d:
	/* 0x431d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_431f:
	/* 0x431f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4323:
	/* 0x4323: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4327:
	/* 0x4327: jmp    4396 <trace_security_file_mprotect+0x4396> */
	goto x86_l_4396;
x86_l_4329:
	/* 0x4329: lea    rdi,[r13+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_4330:
	/* 0x4330: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4333:
	/* 0x4333: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4337:
	/* 0x4337: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_433c:
	/* 0x433c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4341:
	/* 0x4341: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_4346:
	/* 0x4346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4348:
	/* 0x4348: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_434b:
	/* 0x434b: jne    4152 <trace_security_file_mprotect+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4152;
	}
x86_l_4351:
	/* 0x4351: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_4356:
	/* 0x4356: mov    WORD PTR [r13+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_435b:
	/* 0x435b: jmp    c3b <trace_security_file_mprotect+0xc3b> */
	return 3131ULL;
x86_l_4360:
	/* 0x4360: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4365:
	/* 0x4365: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_436b:
	/* 0x436b: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_436e:
	/* 0x436e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4370:
	/* 0x4370: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4375:
	/* 0x4375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4377:
	/* 0x4377: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_437a:
	/* 0x437a: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4380:
	/* 0x4380: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4384:
	/* 0x4384: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_438a:
	/* 0x438a: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_438e:
	/* 0x438e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4391:
	/* 0x4391: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4396:
	/* 0x4396: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_439b:
	/* 0x439b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43a0:
	/* 0x43a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43a5:
	/* 0x43a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43aa:
	/* 0x43aa: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_43ad:
	/* 0x43ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43af:
	/* 0x43af: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b4:
	/* 0x43b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43b9:
	/* 0x43b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_43bd:
	/* 0x43bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43c2:
	/* 0x43c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43c7:
	/* 0x43c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43cc:
	/* 0x43cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43d1:
	/* 0x43d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43d3:
	/* 0x43d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d8:
	/* 0x43d8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_43db:
	/* 0x43db: je     456b <trace_security_file_mprotect+0x456b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17771ULL;
	}
x86_l_43e1:
	/* 0x43e1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43e6:
	/* 0x43e6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_43e9:
	/* 0x43e9: je     456b <trace_security_file_mprotect+0x456b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17771ULL;
	}
x86_l_43ef:
	/* 0x43ef: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_43f3:
	/* 0x43f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43f8:
	/* 0x43f8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_43fd:
	/* 0x43fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4402:
	/* 0x4402: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4407:
	/* 0x4407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4409:
	/* 0x4409: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_440d:
	/* 0x440d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_440f:
	/* 0x440f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4415:
	/* 0x4415: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4418:
	/* 0x4418: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_441a:
	/* 0x441a: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_4420:
	/* 0x4420: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4425:
	/* 0x4425: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_442b:
	/* 0x442b: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_442e:
	/* 0x442e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4430:
	/* 0x4430: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4435:
	/* 0x4435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4437:
	/* 0x4437: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_443a:
	/* 0x443a: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4440:
	/* 0x4440: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4444:
	/* 0x4444: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_444a:
	/* 0x444a: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_444e:
	/* 0x444e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4451:
	/* 0x4451: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4456:
	/* 0x4456: jmp    45e7 <trace_security_file_mprotect+0x45e7> */
	return 17895ULL;
x86_l_445b:
	/* 0x445b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_445e:
	/* 0x445e: jne    1993 <trace_security_file_mprotect+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6547ULL;
	}
x86_l_4464:
	/* 0x4464: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4468:
	/* 0x4468: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_446d:
	/* 0x446d: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_4473:
	/* 0x4473: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4477:
	/* 0x4477: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_447c:
	/* 0x447c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4481:
	/* 0x4481: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4486:
	/* 0x4486: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448a:
	/* 0x448a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_448e:
	/* 0x448e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4493:
	/* 0x4493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4495:
	/* 0x4495: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4499:
	/* 0x4499: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_449c:
	/* 0x449c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44a1:
	/* 0x44a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44a6:
	/* 0x44a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44aa:
	/* 0x44aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44af:
	/* 0x44af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44b1:
	/* 0x44b1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44b5:
	/* 0x44b5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44ba:
	/* 0x44ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44bf:
	/* 0x44bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44c4:
	/* 0x44c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c8:
	/* 0x44c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44cd:
	/* 0x44cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44cf:
	/* 0x44cf: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d3:
	/* 0x44d3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_44d7:
	/* 0x44d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44dc:
	/* 0x44dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44e1:
	/* 0x44e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44e6:
	/* 0x44e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44eb:
	/* 0x44eb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_44ee:
	/* 0x44ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f0:
	/* 0x44f0: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44f5:
	/* 0x44f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44fa:
	/* 0x44fa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44fe:
	/* 0x44fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4503:
	/* 0x4503: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4508:
	/* 0x4508: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_450d:
	/* 0x450d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4512:
	/* 0x4512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4514:
	/* 0x4514: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4519:
	/* 0x4519: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
	return 17692ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17692ULL: goto x86_l_451c;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17706ULL: goto x86_l_452a;
	case 17712ULL: goto x86_l_4530;
	case 17716ULL: goto x86_l_4534;
	case 17721ULL: goto x86_l_4539;
	case 17726ULL: goto x86_l_453e;
	case 17731ULL: goto x86_l_4543;
	case 17736ULL: goto x86_l_4548;
	case 17738ULL: goto x86_l_454a;
	case 17742ULL: goto x86_l_454e;
	case 17744ULL: goto x86_l_4550;
	case 17750ULL: goto x86_l_4556;
	case 17753ULL: goto x86_l_4559;
	case 17755ULL: goto x86_l_455b;
	case 17761ULL: goto x86_l_4561;
	case 17766ULL: goto x86_l_4566;
	case 17771ULL: goto x86_l_456b;
	case 17774ULL: goto x86_l_456e;
	case 17780ULL: goto x86_l_4574;
	case 17784ULL: goto x86_l_4578;
	case 17789ULL: goto x86_l_457d;
	case 17795ULL: goto x86_l_4583;
	case 17799ULL: goto x86_l_4587;
	case 17804ULL: goto x86_l_458c;
	case 17809ULL: goto x86_l_4591;
	case 17814ULL: goto x86_l_4596;
	case 17818ULL: goto x86_l_459a;
	case 17822ULL: goto x86_l_459e;
	case 17827ULL: goto x86_l_45a3;
	case 17829ULL: goto x86_l_45a5;
	case 17833ULL: goto x86_l_45a9;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17846ULL: goto x86_l_45b6;
	case 17850ULL: goto x86_l_45ba;
	case 17855ULL: goto x86_l_45bf;
	case 17857ULL: goto x86_l_45c1;
	case 17861ULL: goto x86_l_45c5;
	case 17866ULL: goto x86_l_45ca;
	case 17871ULL: goto x86_l_45cf;
	case 17876ULL: goto x86_l_45d4;
	case 17880ULL: goto x86_l_45d8;
	case 17885ULL: goto x86_l_45dd;
	case 17887ULL: goto x86_l_45df;
	case 17891ULL: goto x86_l_45e3;
	case 17895ULL: goto x86_l_45e7;
	case 17900ULL: goto x86_l_45ec;
	case 17905ULL: goto x86_l_45f1;
	case 17910ULL: goto x86_l_45f6;
	case 17915ULL: goto x86_l_45fb;
	case 17918ULL: goto x86_l_45fe;
	case 17920ULL: goto x86_l_4600;
	case 17925ULL: goto x86_l_4605;
	case 17930ULL: goto x86_l_460a;
	case 17934ULL: goto x86_l_460e;
	case 17939ULL: goto x86_l_4613;
	case 17944ULL: goto x86_l_4618;
	case 17949ULL: goto x86_l_461d;
	case 17954ULL: goto x86_l_4622;
	case 17956ULL: goto x86_l_4624;
	case 17961ULL: goto x86_l_4629;
	case 17964ULL: goto x86_l_462c;
	case 17970ULL: goto x86_l_4632;
	case 17975ULL: goto x86_l_4637;
	case 17978ULL: goto x86_l_463a;
	case 17984ULL: goto x86_l_4640;
	case 17988ULL: goto x86_l_4644;
	case 17993ULL: goto x86_l_4649;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18008ULL: goto x86_l_4658;
	case 18010ULL: goto x86_l_465a;
	case 18014ULL: goto x86_l_465e;
	case 18016ULL: goto x86_l_4660;
	case 18022ULL: goto x86_l_4666;
	case 18025ULL: goto x86_l_4669;
	case 18027ULL: goto x86_l_466b;
	case 18033ULL: goto x86_l_4671;
	case 18038ULL: goto x86_l_4676;
	case 18044ULL: goto x86_l_467c;
	case 18047ULL: goto x86_l_467f;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18056ULL: goto x86_l_4688;
	case 18059ULL: goto x86_l_468b;
	case 18065ULL: goto x86_l_4691;
	case 18069ULL: goto x86_l_4695;
	case 18075ULL: goto x86_l_469b;
	case 18079ULL: goto x86_l_469f;
	case 18082ULL: goto x86_l_46a2;
	case 18087ULL: goto x86_l_46a7;
	case 18092ULL: goto x86_l_46ac;
	case 18095ULL: goto x86_l_46af;
	case 18101ULL: goto x86_l_46b5;
	case 18105ULL: goto x86_l_46b9;
	case 18110ULL: goto x86_l_46be;
	case 18116ULL: goto x86_l_46c4;
	case 18120ULL: goto x86_l_46c8;
	case 18125ULL: goto x86_l_46cd;
	case 18130ULL: goto x86_l_46d2;
	case 18135ULL: goto x86_l_46d7;
	case 18139ULL: goto x86_l_46db;
	case 18143ULL: goto x86_l_46df;
	case 18148ULL: goto x86_l_46e4;
	case 18150ULL: goto x86_l_46e6;
	case 18154ULL: goto x86_l_46ea;
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18167ULL: goto x86_l_46f7;
	case 18171ULL: goto x86_l_46fb;
	case 18176ULL: goto x86_l_4700;
	case 18178ULL: goto x86_l_4702;
	case 18182ULL: goto x86_l_4706;
	case 18187ULL: goto x86_l_470b;
	case 18192ULL: goto x86_l_4710;
	case 18197ULL: goto x86_l_4715;
	case 18201ULL: goto x86_l_4719;
	case 18206ULL: goto x86_l_471e;
	case 18208ULL: goto x86_l_4720;
	case 18212ULL: goto x86_l_4724;
	case 18216ULL: goto x86_l_4728;
	case 18221ULL: goto x86_l_472d;
	case 18224ULL: goto x86_l_4730;
	case 18230ULL: goto x86_l_4736;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18245ULL: goto x86_l_4745;
	case 18249ULL: goto x86_l_4749;
	case 18254ULL: goto x86_l_474e;
	case 18259ULL: goto x86_l_4753;
	case 18264ULL: goto x86_l_4758;
	case 18268ULL: goto x86_l_475c;
	case 18272ULL: goto x86_l_4760;
	case 18277ULL: goto x86_l_4765;
	case 18279ULL: goto x86_l_4767;
	case 18283ULL: goto x86_l_476b;
	case 18286ULL: goto x86_l_476e;
	case 18291ULL: goto x86_l_4773;
	case 18296ULL: goto x86_l_4778;
	case 18300ULL: goto x86_l_477c;
	case 18305ULL: goto x86_l_4781;
	case 18307ULL: goto x86_l_4783;
	case 18311ULL: goto x86_l_4787;
	case 18316ULL: goto x86_l_478c;
	case 18321ULL: goto x86_l_4791;
	case 18326ULL: goto x86_l_4796;
	case 18330ULL: goto x86_l_479a;
	case 18335ULL: goto x86_l_479f;
	case 18337ULL: goto x86_l_47a1;
	case 18341ULL: goto x86_l_47a5;
	case 18345ULL: goto x86_l_47a9;
	case 18350ULL: goto x86_l_47ae;
	case 18355ULL: goto x86_l_47b3;
	case 18360ULL: goto x86_l_47b8;
	case 18365ULL: goto x86_l_47bd;
	case 18368ULL: goto x86_l_47c0;
	case 18370ULL: goto x86_l_47c2;
	case 18375ULL: goto x86_l_47c7;
	case 18380ULL: goto x86_l_47cc;
	case 18384ULL: goto x86_l_47d0;
	case 18389ULL: goto x86_l_47d5;
	case 18394ULL: goto x86_l_47da;
	case 18399ULL: goto x86_l_47df;
	case 18404ULL: goto x86_l_47e4;
	case 18406ULL: goto x86_l_47e6;
	case 18411ULL: goto x86_l_47eb;
	case 18414ULL: goto x86_l_47ee;
	case 18420ULL: goto x86_l_47f4;
	case 18425ULL: goto x86_l_47f9;
	case 18428ULL: goto x86_l_47fc;
	case 18434ULL: goto x86_l_4802;
	case 18438ULL: goto x86_l_4806;
	case 18443ULL: goto x86_l_480b;
	case 18448ULL: goto x86_l_4810;
	case 18453ULL: goto x86_l_4815;
	case 18458ULL: goto x86_l_481a;
	case 18460ULL: goto x86_l_481c;
	case 18464ULL: goto x86_l_4820;
	case 18466ULL: goto x86_l_4822;
	case 18472ULL: goto x86_l_4828;
	case 18475ULL: goto x86_l_482b;
	case 18477ULL: goto x86_l_482d;
	case 18483ULL: goto x86_l_4833;
	case 18488ULL: goto x86_l_4838;
	case 18494ULL: goto x86_l_483e;
	case 18497ULL: goto x86_l_4841;
	case 18499ULL: goto x86_l_4843;
	case 18504ULL: goto x86_l_4848;
	case 18506ULL: goto x86_l_484a;
	case 18509ULL: goto x86_l_484d;
	case 18515ULL: goto x86_l_4853;
	case 18519ULL: goto x86_l_4857;
	case 18525ULL: goto x86_l_485d;
	case 18529ULL: goto x86_l_4861;
	case 18532ULL: goto x86_l_4864;
	case 18537ULL: goto x86_l_4869;
	case 18542ULL: goto x86_l_486e;
	case 18547ULL: goto x86_l_4873;
	case 18553ULL: goto x86_l_4879;
	case 18556ULL: goto x86_l_487c;
	case 18558ULL: goto x86_l_487e;
	case 18563ULL: goto x86_l_4883;
	case 18565ULL: goto x86_l_4885;
	case 18568ULL: goto x86_l_4888;
	case 18574ULL: goto x86_l_488e;
	case 18578ULL: goto x86_l_4892;
	case 18584ULL: goto x86_l_4898;
	case 18588ULL: goto x86_l_489c;
	case 18591ULL: goto x86_l_489f;
	case 18596ULL: goto x86_l_48a4;
	case 18601ULL: goto x86_l_48a9;
	case 18606ULL: goto x86_l_48ae;
	case 18611ULL: goto x86_l_48b3;
	case 18616ULL: goto x86_l_48b8;
	case 18619ULL: goto x86_l_48bb;
	case 18621ULL: goto x86_l_48bd;
	case 18626ULL: goto x86_l_48c2;
	case 18631ULL: goto x86_l_48c7;
	case 18635ULL: goto x86_l_48cb;
	case 18640ULL: goto x86_l_48d0;
	case 18645ULL: goto x86_l_48d5;
	case 18650ULL: goto x86_l_48da;
	case 18655ULL: goto x86_l_48df;
	case 18657ULL: goto x86_l_48e1;
	case 18662ULL: goto x86_l_48e6;
	case 18665ULL: goto x86_l_48e9;
	case 18667ULL: goto x86_l_48eb;
	case 18672ULL: goto x86_l_48f0;
	case 18675ULL: goto x86_l_48f3;
	case 18677ULL: goto x86_l_48f5;
	case 18681ULL: goto x86_l_48f9;
	case 18686ULL: goto x86_l_48fe;
	case 18691ULL: goto x86_l_4903;
	case 18696ULL: goto x86_l_4908;
	case 18701ULL: goto x86_l_490d;
	case 18703ULL: goto x86_l_490f;
	case 18707ULL: goto x86_l_4913;
	case 18709ULL: goto x86_l_4915;
	case 18715ULL: goto x86_l_491b;
	case 18718ULL: goto x86_l_491e;
	case 18720ULL: goto x86_l_4920;
	case 18726ULL: goto x86_l_4926;
	case 18731ULL: goto x86_l_492b;
	case 18737ULL: goto x86_l_4931;
	case 18740ULL: goto x86_l_4934;
	case 18742ULL: goto x86_l_4936;
	case 18747ULL: goto x86_l_493b;
	case 18749ULL: goto x86_l_493d;
	case 18752ULL: goto x86_l_4940;
	case 18754ULL: goto x86_l_4942;
	case 18758ULL: goto x86_l_4946;
	case 18764ULL: goto x86_l_494c;
	case 18768ULL: goto x86_l_4950;
	case 18771ULL: goto x86_l_4953;
	case 18776ULL: goto x86_l_4958;
	case 18781ULL: goto x86_l_495d;
	case 18784ULL: goto x86_l_4960;
	case 18790ULL: goto x86_l_4966;
	case 18795ULL: goto x86_l_496b;
	case 18800ULL: goto x86_l_4970;
	case 18803ULL: goto x86_l_4973;
	case 18809ULL: goto x86_l_4979;
	case 18813ULL: goto x86_l_497d;
	case 18818ULL: goto x86_l_4982;
	case 18824ULL: goto x86_l_4988;
	case 18828ULL: goto x86_l_498c;
	case 18833ULL: goto x86_l_4991;
	case 18838ULL: goto x86_l_4996;
	case 18843ULL: goto x86_l_499b;
	case 18847ULL: goto x86_l_499f;
	case 18851ULL: goto x86_l_49a3;
	case 18856ULL: goto x86_l_49a8;
	case 18858ULL: goto x86_l_49aa;
	case 18862ULL: goto x86_l_49ae;
	case 18865ULL: goto x86_l_49b1;
	case 18870ULL: goto x86_l_49b6;
	case 18875ULL: goto x86_l_49bb;
	case 18879ULL: goto x86_l_49bf;
	case 18884ULL: goto x86_l_49c4;
	case 18886ULL: goto x86_l_49c6;
	case 18890ULL: goto x86_l_49ca;
	case 18895ULL: goto x86_l_49cf;
	case 18900ULL: goto x86_l_49d4;
	case 18905ULL: goto x86_l_49d9;
	case 18909ULL: goto x86_l_49dd;
	case 18914ULL: goto x86_l_49e2;
	case 18916ULL: goto x86_l_49e4;
	case 18920ULL: goto x86_l_49e8;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18934ULL: goto x86_l_49f6;
	case 18939ULL: goto x86_l_49fb;
	case 18944ULL: goto x86_l_4a00;
	case 18947ULL: goto x86_l_4a03;
	case 18949ULL: goto x86_l_4a05;
	case 18954ULL: goto x86_l_4a0a;
	case 18959ULL: goto x86_l_4a0f;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18973ULL: goto x86_l_4a1d;
	case 18978ULL: goto x86_l_4a22;
	case 18983ULL: goto x86_l_4a27;
	case 18985ULL: goto x86_l_4a29;
	case 18990ULL: goto x86_l_4a2e;
	case 18993ULL: goto x86_l_4a31;
	case 18999ULL: goto x86_l_4a37;
	case 19004ULL: goto x86_l_4a3c;
	case 19007ULL: goto x86_l_4a3f;
	case 19013ULL: goto x86_l_4a45;
	case 19017ULL: goto x86_l_4a49;
	case 19022ULL: goto x86_l_4a4e;
	case 19027ULL: goto x86_l_4a53;
	case 19032ULL: goto x86_l_4a58;
	case 19037ULL: goto x86_l_4a5d;
	case 19039ULL: goto x86_l_4a5f;
	case 19043ULL: goto x86_l_4a63;
	case 19045ULL: goto x86_l_4a65;
	case 19051ULL: goto x86_l_4a6b;
	case 19054ULL: goto x86_l_4a6e;
	case 19056ULL: goto x86_l_4a70;
	case 19062ULL: goto x86_l_4a76;
	case 19067ULL: goto x86_l_4a7b;
	case 19073ULL: goto x86_l_4a81;
	case 19076ULL: goto x86_l_4a84;
	case 19078ULL: goto x86_l_4a86;
	case 19083ULL: goto x86_l_4a8b;
	case 19085ULL: goto x86_l_4a8d;
	case 19088ULL: goto x86_l_4a90;
	case 19094ULL: goto x86_l_4a96;
	case 19098ULL: goto x86_l_4a9a;
	case 19104ULL: goto x86_l_4aa0;
	case 19108ULL: goto x86_l_4aa4;
	case 19111ULL: goto x86_l_4aa7;
	case 19116ULL: goto x86_l_4aac;
	case 19121ULL: goto x86_l_4ab1;
	case 19125ULL: goto x86_l_4ab5;
	case 19130ULL: goto x86_l_4aba;
	case 19136ULL: goto x86_l_4ac0;
	case 19140ULL: goto x86_l_4ac4;
	case 19145ULL: goto x86_l_4ac9;
	case 19150ULL: goto x86_l_4ace;
	case 19155ULL: goto x86_l_4ad3;
	case 19159ULL: goto x86_l_4ad7;
	case 19163ULL: goto x86_l_4adb;
	case 19168ULL: goto x86_l_4ae0;
	case 19170ULL: goto x86_l_4ae2;
	case 19174ULL: goto x86_l_4ae6;
	case 19177ULL: goto x86_l_4ae9;
	case 19182ULL: goto x86_l_4aee;
	case 19187ULL: goto x86_l_4af3;
	case 19191ULL: goto x86_l_4af7;
	case 19196ULL: goto x86_l_4afc;
	case 19198ULL: goto x86_l_4afe;
	case 19202ULL: goto x86_l_4b02;
	case 19207ULL: goto x86_l_4b07;
	case 19212ULL: goto x86_l_4b0c;
	case 19217ULL: goto x86_l_4b11;
	case 19221ULL: goto x86_l_4b15;
	case 19226ULL: goto x86_l_4b1a;
	case 19228ULL: goto x86_l_4b1c;
	case 19232ULL: goto x86_l_4b20;
	case 19236ULL: goto x86_l_4b24;
	case 19241ULL: goto x86_l_4b29;
	case 19246ULL: goto x86_l_4b2e;
	case 19251ULL: goto x86_l_4b33;
	case 19256ULL: goto x86_l_4b38;
	case 19259ULL: goto x86_l_4b3b;
	case 19261ULL: goto x86_l_4b3d;
	case 19266ULL: goto x86_l_4b42;
	case 19271ULL: goto x86_l_4b47;
	case 19275ULL: goto x86_l_4b4b;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19290ULL: goto x86_l_4b5a;
	case 19295ULL: goto x86_l_4b5f;
	case 19297ULL: goto x86_l_4b61;
	case 19302ULL: goto x86_l_4b66;
	case 19305ULL: goto x86_l_4b69;
	case 19307ULL: goto x86_l_4b6b;
	case 19312ULL: goto x86_l_4b70;
	case 19315ULL: goto x86_l_4b73;
	case 19317ULL: goto x86_l_4b75;
	default: return 0xffffffffffffffffULL;
	}
x86_l_451c:
	/* 0x451c: je     46ac <trace_security_file_mprotect+0x46ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46ac;
	}
x86_l_4522:
	/* 0x4522: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4527:
	/* 0x4527: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_452a:
	/* 0x452a: je     46ac <trace_security_file_mprotect+0x46ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46ac;
	}
x86_l_4530:
	/* 0x4530: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4534:
	/* 0x4534: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4539:
	/* 0x4539: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_453e:
	/* 0x453e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4543:
	/* 0x4543: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4548:
	/* 0x4548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454a:
	/* 0x454a: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_454e:
	/* 0x454e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4550:
	/* 0x4550: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4556:
	/* 0x4556: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4559:
	/* 0x4559: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_455b:
	/* 0x455b: jae    486e <trace_security_file_mprotect+0x486e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_486e;
	}
x86_l_4561:
	/* 0x4561: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4566:
	/* 0x4566: jmp    31c0 <trace_security_file_mprotect+0x31c0> */
	return 12736ULL;
x86_l_456b:
	/* 0x456b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_456e:
	/* 0x456e: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_4574:
	/* 0x4574: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4578:
	/* 0x4578: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_457d:
	/* 0x457d: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_4583:
	/* 0x4583: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4587:
	/* 0x4587: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_458c:
	/* 0x458c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4591:
	/* 0x4591: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4596:
	/* 0x4596: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_459a:
	/* 0x459a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_459e:
	/* 0x459e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45a3:
	/* 0x45a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a5:
	/* 0x45a5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a9:
	/* 0x45a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45ac:
	/* 0x45ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45b1:
	/* 0x45b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45b6:
	/* 0x45b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ba:
	/* 0x45ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45bf:
	/* 0x45bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45c1:
	/* 0x45c1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c5:
	/* 0x45c5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45ca:
	/* 0x45ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45cf:
	/* 0x45cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45d4:
	/* 0x45d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45d8:
	/* 0x45d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45dd:
	/* 0x45dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45df:
	/* 0x45df: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45e3:
	/* 0x45e3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45e7:
	/* 0x45e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45ec:
	/* 0x45ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45f1:
	/* 0x45f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45f6:
	/* 0x45f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45fb:
	/* 0x45fb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_45fe:
	/* 0x45fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4600:
	/* 0x4600: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4605:
	/* 0x4605: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_460a:
	/* 0x460a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_460e:
	/* 0x460e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4613:
	/* 0x4613: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4618:
	/* 0x4618: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_461d:
	/* 0x461d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4622:
	/* 0x4622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4624:
	/* 0x4624: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4629:
	/* 0x4629: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_462c:
	/* 0x462c: je     472d <trace_security_file_mprotect+0x472d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_472d;
	}
x86_l_4632:
	/* 0x4632: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4637:
	/* 0x4637: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_463a:
	/* 0x463a: je     472d <trace_security_file_mprotect+0x472d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_472d;
	}
x86_l_4640:
	/* 0x4640: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4644:
	/* 0x4644: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4649:
	/* 0x4649: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_464e:
	/* 0x464e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4653:
	/* 0x4653: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4658:
	/* 0x4658: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465a:
	/* 0x465a: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_465e:
	/* 0x465e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4660:
	/* 0x4660: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4666:
	/* 0x4666: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4669:
	/* 0x4669: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_466b:
	/* 0x466b: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_4671:
	/* 0x4671: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4676:
	/* 0x4676: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_467c:
	/* 0x467c: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_467f:
	/* 0x467f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4681:
	/* 0x4681: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4686:
	/* 0x4686: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4688:
	/* 0x4688: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_468b:
	/* 0x468b: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4691:
	/* 0x4691: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4695:
	/* 0x4695: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_469b:
	/* 0x469b: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_469f:
	/* 0x469f: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_46a2:
	/* 0x46a2: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a7:
	/* 0x46a7: jmp    47a9 <trace_security_file_mprotect+0x47a9> */
	goto x86_l_47a9;
x86_l_46ac:
	/* 0x46ac: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_46af:
	/* 0x46af: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4966;
	}
x86_l_46b5:
	/* 0x46b5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b9:
	/* 0x46b9: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_46be:
	/* 0x46be: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4966;
	}
x86_l_46c4:
	/* 0x46c4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46c8:
	/* 0x46c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46cd:
	/* 0x46cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46d2:
	/* 0x46d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46d7:
	/* 0x46d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46db:
	/* 0x46db: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46df:
	/* 0x46df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46e4:
	/* 0x46e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e6:
	/* 0x46e6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46ea:
	/* 0x46ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46ed:
	/* 0x46ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46f2:
	/* 0x46f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46f7:
	/* 0x46f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46fb:
	/* 0x46fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4700:
	/* 0x4700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4702:
	/* 0x4702: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4706:
	/* 0x4706: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_470b:
	/* 0x470b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4710:
	/* 0x4710: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4715:
	/* 0x4715: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4719:
	/* 0x4719: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_471e:
	/* 0x471e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4720:
	/* 0x4720: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4724:
	/* 0x4724: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4728:
	/* 0x4728: jmp    48a4 <trace_security_file_mprotect+0x48a4> */
	goto x86_l_48a4;
x86_l_472d:
	/* 0x472d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4730:
	/* 0x4730: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_4736:
	/* 0x4736: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_473a:
	/* 0x473a: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_473f:
	/* 0x473f: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_4745:
	/* 0x4745: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4749:
	/* 0x4749: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_474e:
	/* 0x474e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4753:
	/* 0x4753: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4758:
	/* 0x4758: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_475c:
	/* 0x475c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4760:
	/* 0x4760: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4765:
	/* 0x4765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4767:
	/* 0x4767: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_476b:
	/* 0x476b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_476e:
	/* 0x476e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4773:
	/* 0x4773: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4778:
	/* 0x4778: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_477c:
	/* 0x477c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4781:
	/* 0x4781: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4783:
	/* 0x4783: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4787:
	/* 0x4787: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_478c:
	/* 0x478c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4791:
	/* 0x4791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4796:
	/* 0x4796: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_479a:
	/* 0x479a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_479f:
	/* 0x479f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47a1:
	/* 0x47a1: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a5:
	/* 0x47a5: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_47a9:
	/* 0x47a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47ae:
	/* 0x47ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47b3:
	/* 0x47b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47b8:
	/* 0x47b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47bd:
	/* 0x47bd: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_47c0:
	/* 0x47c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c2:
	/* 0x47c2: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47c7:
	/* 0x47c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47cc:
	/* 0x47cc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_47d0:
	/* 0x47d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47d5:
	/* 0x47d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47da:
	/* 0x47da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47df:
	/* 0x47df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47e4:
	/* 0x47e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47e6:
	/* 0x47e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47eb:
	/* 0x47eb: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_47ee:
	/* 0x47ee: je     4970 <trace_security_file_mprotect+0x4970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4970;
	}
x86_l_47f4:
	/* 0x47f4: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47f9:
	/* 0x47f9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_47fc:
	/* 0x47fc: je     4970 <trace_security_file_mprotect+0x4970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4970;
	}
x86_l_4802:
	/* 0x4802: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4806:
	/* 0x4806: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_480b:
	/* 0x480b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4810:
	/* 0x4810: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4815:
	/* 0x4815: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_481a:
	/* 0x481a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_481c:
	/* 0x481c: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4820:
	/* 0x4820: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4822:
	/* 0x4822: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4828:
	/* 0x4828: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_482b:
	/* 0x482b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_482d:
	/* 0x482d: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_4833:
	/* 0x4833: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4838:
	/* 0x4838: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_483e:
	/* 0x483e: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4841:
	/* 0x4841: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4843:
	/* 0x4843: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4848:
	/* 0x4848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_484a:
	/* 0x484a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_484d:
	/* 0x484d: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4853:
	/* 0x4853: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4857:
	/* 0x4857: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_485d:
	/* 0x485d: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4861:
	/* 0x4861: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4864:
	/* 0x4864: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4869:
	/* 0x4869: jmp    49ec <trace_security_file_mprotect+0x49ec> */
	goto x86_l_49ec;
x86_l_486e:
	/* 0x486e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4873:
	/* 0x4873: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4879:
	/* 0x4879: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_487c:
	/* 0x487c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_487e:
	/* 0x487e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4883:
	/* 0x4883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4885:
	/* 0x4885: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4888:
	/* 0x4888: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_4966;
	}
x86_l_488e:
	/* 0x488e: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4892:
	/* 0x4892: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4898:
	/* 0x4898: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_489c:
	/* 0x489c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_489f:
	/* 0x489f: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48a4:
	/* 0x48a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48a9:
	/* 0x48a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48ae:
	/* 0x48ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48b3:
	/* 0x48b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48b8:
	/* 0x48b8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_48bb:
	/* 0x48bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48bd:
	/* 0x48bd: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48c2:
	/* 0x48c2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c7:
	/* 0x48c7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_48cb:
	/* 0x48cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48d0:
	/* 0x48d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48d5:
	/* 0x48d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48da:
	/* 0x48da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48df:
	/* 0x48df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e1:
	/* 0x48e1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48e6:
	/* 0x48e6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_48e9:
	/* 0x48e9: je     495d <trace_security_file_mprotect+0x495d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_495d;
	}
x86_l_48eb:
	/* 0x48eb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f0:
	/* 0x48f0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_48f3:
	/* 0x48f3: je     495d <trace_security_file_mprotect+0x495d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_495d;
	}
x86_l_48f5:
	/* 0x48f5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48f9:
	/* 0x48f9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48fe:
	/* 0x48fe: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4903:
	/* 0x4903: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4908:
	/* 0x4908: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_490d:
	/* 0x490d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_490f:
	/* 0x490f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4913:
	/* 0x4913: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4915:
	/* 0x4915: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_491b:
	/* 0x491b: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_491e:
	/* 0x491e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4920:
	/* 0x4920: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4561;
	}
x86_l_4926:
	/* 0x4926: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_492b:
	/* 0x492b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4931:
	/* 0x4931: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4934:
	/* 0x4934: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4936:
	/* 0x4936: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_493b:
	/* 0x493b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493d:
	/* 0x493d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4940:
	/* 0x4940: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_4966;
	}
x86_l_4942:
	/* 0x4942: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4946:
	/* 0x4946: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_494c:
	/* 0x494c: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4950:
	/* 0x4950: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4953:
	/* 0x4953: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4958:
	/* 0x4958: jmp    4b24 <trace_security_file_mprotect+0x4b24> */
	goto x86_l_4b24;
x86_l_495d:
	/* 0x495d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4960:
	/* 0x4960: je     4ab1 <trace_security_file_mprotect+0x4ab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ab1;
	}
x86_l_4966:
	/* 0x4966: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_496b:
	/* 0x496b: jmp    1993 <trace_security_file_mprotect+0x1993> */
	return 6547ULL;
x86_l_4970:
	/* 0x4970: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4973:
	/* 0x4973: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_4979:
	/* 0x4979: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497d:
	/* 0x497d: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4982:
	/* 0x4982: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_4988:
	/* 0x4988: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_498c:
	/* 0x498c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4991:
	/* 0x4991: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4996:
	/* 0x4996: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_499b:
	/* 0x499b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_499f:
	/* 0x499f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49a3:
	/* 0x49a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49a8:
	/* 0x49a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49aa:
	/* 0x49aa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ae:
	/* 0x49ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49b1:
	/* 0x49b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49b6:
	/* 0x49b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49bb:
	/* 0x49bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49bf:
	/* 0x49bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c4:
	/* 0x49c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c6:
	/* 0x49c6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ca:
	/* 0x49ca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49cf:
	/* 0x49cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49d4:
	/* 0x49d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49d9:
	/* 0x49d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49dd:
	/* 0x49dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49e2:
	/* 0x49e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49e4:
	/* 0x49e4: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e8:
	/* 0x49e8: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_49ec:
	/* 0x49ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49f1:
	/* 0x49f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49f6:
	/* 0x49f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49fb:
	/* 0x49fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a00:
	/* 0x4a00: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4a03:
	/* 0x4a03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a05:
	/* 0x4a05: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a0a:
	/* 0x4a0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a0f:
	/* 0x4a0f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a13:
	/* 0x4a13: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a18:
	/* 0x4a18: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a1d:
	/* 0x4a1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a22:
	/* 0x4a22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a27:
	/* 0x4a27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a29:
	/* 0x4a29: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2e:
	/* 0x4a2e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4a31:
	/* 0x4a31: je     4d1f <trace_security_file_mprotect+0x4d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19743ULL;
	}
x86_l_4a37:
	/* 0x4a37: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a3c:
	/* 0x4a3c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4a3f:
	/* 0x4a3f: je     4d1f <trace_security_file_mprotect+0x4d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19743ULL;
	}
x86_l_4a45:
	/* 0x4a45: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a49:
	/* 0x4a49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a4e:
	/* 0x4a4e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4a53:
	/* 0x4a53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a58:
	/* 0x4a58: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4a5d:
	/* 0x4a5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5f:
	/* 0x4a5f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4a63:
	/* 0x4a63: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a65:
	/* 0x4a65: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a6b:
	/* 0x4a6b: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4a6e:
	/* 0x4a6e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4a70:
	/* 0x4a70: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_4a76:
	/* 0x4a76: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a7b:
	/* 0x4a7b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4a81:
	/* 0x4a81: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4a84:
	/* 0x4a84: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4a86:
	/* 0x4a86: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4a8b:
	/* 0x4a8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a8d:
	/* 0x4a8d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a90:
	/* 0x4a90: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4a96:
	/* 0x4a96: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4a9a:
	/* 0x4a9a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4aa0:
	/* 0x4aa0: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4aa4:
	/* 0x4aa4: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4aa7:
	/* 0x4aa7: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aac:
	/* 0x4aac: jmp    4d9b <trace_security_file_mprotect+0x4d9b> */
	return 19867ULL;
x86_l_4ab1:
	/* 0x4ab1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ab5:
	/* 0x4ab5: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4aba:
	/* 0x4aba: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4966;
	}
x86_l_4ac0:
	/* 0x4ac0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ac4:
	/* 0x4ac4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac9:
	/* 0x4ac9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ace:
	/* 0x4ace: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ad3:
	/* 0x4ad3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad7:
	/* 0x4ad7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4adb:
	/* 0x4adb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ae0:
	/* 0x4ae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae2:
	/* 0x4ae2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae6:
	/* 0x4ae6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ae9:
	/* 0x4ae9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4aee:
	/* 0x4aee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4af3:
	/* 0x4af3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4af7:
	/* 0x4af7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4afc:
	/* 0x4afc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4afe:
	/* 0x4afe: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b02:
	/* 0x4b02: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b07:
	/* 0x4b07: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b0c:
	/* 0x4b0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b11:
	/* 0x4b11: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b15:
	/* 0x4b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1a:
	/* 0x4b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1c:
	/* 0x4b1c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b20:
	/* 0x4b20: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b24:
	/* 0x4b24: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b29:
	/* 0x4b29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b2e:
	/* 0x4b2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b33:
	/* 0x4b33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b38:
	/* 0x4b38: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4b3b:
	/* 0x4b3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b3d:
	/* 0x4b3d: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b42:
	/* 0x4b42: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b47:
	/* 0x4b47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b4b:
	/* 0x4b4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b50:
	/* 0x4b50: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b55:
	/* 0x4b55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b5a:
	/* 0x4b5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b5f:
	/* 0x4b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b61:
	/* 0x4b61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b66:
	/* 0x4b66: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4b69:
	/* 0x4b69: je     4bde <trace_security_file_mprotect+0x4bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19422ULL;
	}
x86_l_4b6b:
	/* 0x4b6b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b70:
	/* 0x4b70: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4b73:
	/* 0x4b73: je     4bde <trace_security_file_mprotect+0x4bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19422ULL;
	}
x86_l_4b75:
	/* 0x4b75: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
	return 19321ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19321ULL: goto x86_l_4b79;
	case 19326ULL: goto x86_l_4b7e;
	case 19331ULL: goto x86_l_4b83;
	case 19336ULL: goto x86_l_4b88;
	case 19341ULL: goto x86_l_4b8d;
	case 19343ULL: goto x86_l_4b8f;
	case 19347ULL: goto x86_l_4b93;
	case 19349ULL: goto x86_l_4b95;
	case 19355ULL: goto x86_l_4b9b;
	case 19358ULL: goto x86_l_4b9e;
	case 19360ULL: goto x86_l_4ba0;
	case 19366ULL: goto x86_l_4ba6;
	case 19371ULL: goto x86_l_4bab;
	case 19377ULL: goto x86_l_4bb1;
	case 19380ULL: goto x86_l_4bb4;
	case 19382ULL: goto x86_l_4bb6;
	case 19387ULL: goto x86_l_4bbb;
	case 19389ULL: goto x86_l_4bbd;
	case 19392ULL: goto x86_l_4bc0;
	case 19398ULL: goto x86_l_4bc6;
	case 19402ULL: goto x86_l_4bca;
	case 19408ULL: goto x86_l_4bd0;
	case 19412ULL: goto x86_l_4bd4;
	case 19415ULL: goto x86_l_4bd7;
	case 19420ULL: goto x86_l_4bdc;
	case 19422ULL: goto x86_l_4bde;
	case 19425ULL: goto x86_l_4be1;
	case 19431ULL: goto x86_l_4be7;
	case 19435ULL: goto x86_l_4beb;
	case 19440ULL: goto x86_l_4bf0;
	case 19446ULL: goto x86_l_4bf6;
	case 19450ULL: goto x86_l_4bfa;
	case 19455ULL: goto x86_l_4bff;
	case 19460ULL: goto x86_l_4c04;
	case 19465ULL: goto x86_l_4c09;
	case 19469ULL: goto x86_l_4c0d;
	case 19473ULL: goto x86_l_4c11;
	case 19478ULL: goto x86_l_4c16;
	case 19480ULL: goto x86_l_4c18;
	case 19484ULL: goto x86_l_4c1c;
	case 19487ULL: goto x86_l_4c1f;
	case 19492ULL: goto x86_l_4c24;
	case 19497ULL: goto x86_l_4c29;
	case 19501ULL: goto x86_l_4c2d;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19512ULL: goto x86_l_4c38;
	case 19517ULL: goto x86_l_4c3d;
	case 19522ULL: goto x86_l_4c42;
	case 19527ULL: goto x86_l_4c47;
	case 19531ULL: goto x86_l_4c4b;
	case 19536ULL: goto x86_l_4c50;
	case 19538ULL: goto x86_l_4c52;
	case 19542ULL: goto x86_l_4c56;
	case 19546ULL: goto x86_l_4c5a;
	case 19551ULL: goto x86_l_4c5f;
	case 19556ULL: goto x86_l_4c64;
	case 19561ULL: goto x86_l_4c69;
	case 19566ULL: goto x86_l_4c6e;
	case 19569ULL: goto x86_l_4c71;
	case 19571ULL: goto x86_l_4c73;
	case 19576ULL: goto x86_l_4c78;
	case 19581ULL: goto x86_l_4c7d;
	case 19585ULL: goto x86_l_4c81;
	case 19590ULL: goto x86_l_4c86;
	case 19595ULL: goto x86_l_4c8b;
	case 19600ULL: goto x86_l_4c90;
	case 19605ULL: goto x86_l_4c95;
	case 19607ULL: goto x86_l_4c97;
	case 19612ULL: goto x86_l_4c9c;
	case 19615ULL: goto x86_l_4c9f;
	case 19621ULL: goto x86_l_4ca5;
	case 19626ULL: goto x86_l_4caa;
	case 19629ULL: goto x86_l_4cad;
	case 19635ULL: goto x86_l_4cb3;
	case 19639ULL: goto x86_l_4cb7;
	case 19644ULL: goto x86_l_4cbc;
	case 19649ULL: goto x86_l_4cc1;
	case 19654ULL: goto x86_l_4cc6;
	case 19659ULL: goto x86_l_4ccb;
	case 19661ULL: goto x86_l_4ccd;
	case 19665ULL: goto x86_l_4cd1;
	case 19667ULL: goto x86_l_4cd3;
	case 19673ULL: goto x86_l_4cd9;
	case 19676ULL: goto x86_l_4cdc;
	case 19678ULL: goto x86_l_4cde;
	case 19684ULL: goto x86_l_4ce4;
	case 19689ULL: goto x86_l_4ce9;
	case 19695ULL: goto x86_l_4cef;
	case 19698ULL: goto x86_l_4cf2;
	case 19700ULL: goto x86_l_4cf4;
	case 19705ULL: goto x86_l_4cf9;
	case 19707ULL: goto x86_l_4cfb;
	case 19710ULL: goto x86_l_4cfe;
	case 19716ULL: goto x86_l_4d04;
	case 19720ULL: goto x86_l_4d08;
	case 19726ULL: goto x86_l_4d0e;
	case 19730ULL: goto x86_l_4d12;
	case 19733ULL: goto x86_l_4d15;
	case 19738ULL: goto x86_l_4d1a;
	case 19743ULL: goto x86_l_4d1f;
	case 19746ULL: goto x86_l_4d22;
	case 19752ULL: goto x86_l_4d28;
	case 19756ULL: goto x86_l_4d2c;
	case 19761ULL: goto x86_l_4d31;
	case 19767ULL: goto x86_l_4d37;
	case 19771ULL: goto x86_l_4d3b;
	case 19776ULL: goto x86_l_4d40;
	case 19781ULL: goto x86_l_4d45;
	case 19786ULL: goto x86_l_4d4a;
	case 19790ULL: goto x86_l_4d4e;
	case 19794ULL: goto x86_l_4d52;
	case 19799ULL: goto x86_l_4d57;
	case 19801ULL: goto x86_l_4d59;
	case 19805ULL: goto x86_l_4d5d;
	case 19808ULL: goto x86_l_4d60;
	case 19813ULL: goto x86_l_4d65;
	case 19818ULL: goto x86_l_4d6a;
	case 19822ULL: goto x86_l_4d6e;
	case 19827ULL: goto x86_l_4d73;
	case 19829ULL: goto x86_l_4d75;
	case 19833ULL: goto x86_l_4d79;
	case 19838ULL: goto x86_l_4d7e;
	case 19843ULL: goto x86_l_4d83;
	case 19848ULL: goto x86_l_4d88;
	case 19852ULL: goto x86_l_4d8c;
	case 19857ULL: goto x86_l_4d91;
	case 19859ULL: goto x86_l_4d93;
	case 19863ULL: goto x86_l_4d97;
	case 19867ULL: goto x86_l_4d9b;
	case 19872ULL: goto x86_l_4da0;
	case 19877ULL: goto x86_l_4da5;
	case 19882ULL: goto x86_l_4daa;
	case 19887ULL: goto x86_l_4daf;
	case 19890ULL: goto x86_l_4db2;
	case 19892ULL: goto x86_l_4db4;
	case 19897ULL: goto x86_l_4db9;
	case 19902ULL: goto x86_l_4dbe;
	case 19906ULL: goto x86_l_4dc2;
	case 19911ULL: goto x86_l_4dc7;
	case 19916ULL: goto x86_l_4dcc;
	case 19921ULL: goto x86_l_4dd1;
	case 19926ULL: goto x86_l_4dd6;
	case 19928ULL: goto x86_l_4dd8;
	case 19933ULL: goto x86_l_4ddd;
	case 19936ULL: goto x86_l_4de0;
	case 19942ULL: goto x86_l_4de6;
	case 19947ULL: goto x86_l_4deb;
	case 19950ULL: goto x86_l_4dee;
	case 19956ULL: goto x86_l_4df4;
	case 19960ULL: goto x86_l_4df8;
	case 19965ULL: goto x86_l_4dfd;
	case 19970ULL: goto x86_l_4e02;
	case 19975ULL: goto x86_l_4e07;
	case 19980ULL: goto x86_l_4e0c;
	case 19982ULL: goto x86_l_4e0e;
	case 19986ULL: goto x86_l_4e12;
	case 19988ULL: goto x86_l_4e14;
	case 19994ULL: goto x86_l_4e1a;
	case 19997ULL: goto x86_l_4e1d;
	case 19999ULL: goto x86_l_4e1f;
	case 20005ULL: goto x86_l_4e25;
	case 20010ULL: goto x86_l_4e2a;
	case 20016ULL: goto x86_l_4e30;
	case 20019ULL: goto x86_l_4e33;
	case 20021ULL: goto x86_l_4e35;
	case 20026ULL: goto x86_l_4e3a;
	case 20028ULL: goto x86_l_4e3c;
	case 20031ULL: goto x86_l_4e3f;
	case 20037ULL: goto x86_l_4e45;
	case 20041ULL: goto x86_l_4e49;
	case 20047ULL: goto x86_l_4e4f;
	case 20051ULL: goto x86_l_4e53;
	case 20054ULL: goto x86_l_4e56;
	case 20059ULL: goto x86_l_4e5b;
	case 20064ULL: goto x86_l_4e60;
	case 20067ULL: goto x86_l_4e63;
	case 20073ULL: goto x86_l_4e69;
	case 20077ULL: goto x86_l_4e6d;
	case 20082ULL: goto x86_l_4e72;
	case 20088ULL: goto x86_l_4e78;
	case 20092ULL: goto x86_l_4e7c;
	case 20097ULL: goto x86_l_4e81;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20111ULL: goto x86_l_4e8f;
	case 20115ULL: goto x86_l_4e93;
	case 20120ULL: goto x86_l_4e98;
	case 20122ULL: goto x86_l_4e9a;
	case 20126ULL: goto x86_l_4e9e;
	case 20129ULL: goto x86_l_4ea1;
	case 20134ULL: goto x86_l_4ea6;
	case 20139ULL: goto x86_l_4eab;
	case 20143ULL: goto x86_l_4eaf;
	case 20148ULL: goto x86_l_4eb4;
	case 20150ULL: goto x86_l_4eb6;
	case 20154ULL: goto x86_l_4eba;
	case 20159ULL: goto x86_l_4ebf;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20173ULL: goto x86_l_4ecd;
	case 20178ULL: goto x86_l_4ed2;
	case 20180ULL: goto x86_l_4ed4;
	case 20184ULL: goto x86_l_4ed8;
	case 20188ULL: goto x86_l_4edc;
	case 20193ULL: goto x86_l_4ee1;
	case 20198ULL: goto x86_l_4ee6;
	case 20203ULL: goto x86_l_4eeb;
	case 20208ULL: goto x86_l_4ef0;
	case 20211ULL: goto x86_l_4ef3;
	case 20213ULL: goto x86_l_4ef5;
	case 20218ULL: goto x86_l_4efa;
	case 20223ULL: goto x86_l_4eff;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20237ULL: goto x86_l_4f0d;
	case 20242ULL: goto x86_l_4f12;
	case 20247ULL: goto x86_l_4f17;
	case 20249ULL: goto x86_l_4f19;
	case 20254ULL: goto x86_l_4f1e;
	case 20257ULL: goto x86_l_4f21;
	case 20263ULL: goto x86_l_4f27;
	case 20268ULL: goto x86_l_4f2c;
	case 20271ULL: goto x86_l_4f2f;
	case 20277ULL: goto x86_l_4f35;
	case 20281ULL: goto x86_l_4f39;
	case 20286ULL: goto x86_l_4f3e;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20301ULL: goto x86_l_4f4d;
	case 20303ULL: goto x86_l_4f4f;
	case 20307ULL: goto x86_l_4f53;
	case 20309ULL: goto x86_l_4f55;
	case 20315ULL: goto x86_l_4f5b;
	case 20318ULL: goto x86_l_4f5e;
	case 20320ULL: goto x86_l_4f60;
	case 20326ULL: goto x86_l_4f66;
	case 20331ULL: goto x86_l_4f6b;
	case 20337ULL: goto x86_l_4f71;
	case 20340ULL: goto x86_l_4f74;
	case 20342ULL: goto x86_l_4f76;
	case 20347ULL: goto x86_l_4f7b;
	case 20349ULL: goto x86_l_4f7d;
	case 20352ULL: goto x86_l_4f80;
	case 20358ULL: goto x86_l_4f86;
	case 20362ULL: goto x86_l_4f8a;
	case 20368ULL: goto x86_l_4f90;
	case 20372ULL: goto x86_l_4f94;
	case 20375ULL: goto x86_l_4f97;
	case 20380ULL: goto x86_l_4f9c;
	case 20385ULL: goto x86_l_4fa1;
	case 20388ULL: goto x86_l_4fa4;
	case 20394ULL: goto x86_l_4faa;
	case 20398ULL: goto x86_l_4fae;
	case 20403ULL: goto x86_l_4fb3;
	case 20409ULL: goto x86_l_4fb9;
	case 20413ULL: goto x86_l_4fbd;
	case 20418ULL: goto x86_l_4fc2;
	case 20423ULL: goto x86_l_4fc7;
	case 20428ULL: goto x86_l_4fcc;
	case 20432ULL: goto x86_l_4fd0;
	case 20436ULL: goto x86_l_4fd4;
	case 20441ULL: goto x86_l_4fd9;
	case 20443ULL: goto x86_l_4fdb;
	case 20447ULL: goto x86_l_4fdf;
	case 20450ULL: goto x86_l_4fe2;
	case 20455ULL: goto x86_l_4fe7;
	case 20460ULL: goto x86_l_4fec;
	case 20464ULL: goto x86_l_4ff0;
	case 20469ULL: goto x86_l_4ff5;
	case 20471ULL: goto x86_l_4ff7;
	case 20475ULL: goto x86_l_4ffb;
	case 20480ULL: goto x86_l_5000;
	case 20485ULL: goto x86_l_5005;
	case 20490ULL: goto x86_l_500a;
	case 20494ULL: goto x86_l_500e;
	case 20499ULL: goto x86_l_5013;
	case 20501ULL: goto x86_l_5015;
	case 20505ULL: goto x86_l_5019;
	case 20509ULL: goto x86_l_501d;
	case 20514ULL: goto x86_l_5022;
	case 20519ULL: goto x86_l_5027;
	case 20524ULL: goto x86_l_502c;
	case 20529ULL: goto x86_l_5031;
	case 20532ULL: goto x86_l_5034;
	case 20534ULL: goto x86_l_5036;
	case 20539ULL: goto x86_l_503b;
	case 20544ULL: goto x86_l_5040;
	case 20548ULL: goto x86_l_5044;
	case 20553ULL: goto x86_l_5049;
	case 20558ULL: goto x86_l_504e;
	case 20563ULL: goto x86_l_5053;
	case 20568ULL: goto x86_l_5058;
	case 20570ULL: goto x86_l_505a;
	case 20575ULL: goto x86_l_505f;
	case 20578ULL: goto x86_l_5062;
	case 20584ULL: goto x86_l_5068;
	case 20589ULL: goto x86_l_506d;
	case 20592ULL: goto x86_l_5070;
	case 20598ULL: goto x86_l_5076;
	case 20602ULL: goto x86_l_507a;
	case 20607ULL: goto x86_l_507f;
	case 20612ULL: goto x86_l_5084;
	case 20617ULL: goto x86_l_5089;
	case 20622ULL: goto x86_l_508e;
	case 20624ULL: goto x86_l_5090;
	case 20628ULL: goto x86_l_5094;
	case 20630ULL: goto x86_l_5096;
	case 20636ULL: goto x86_l_509c;
	case 20639ULL: goto x86_l_509f;
	case 20641ULL: goto x86_l_50a1;
	case 20647ULL: goto x86_l_50a7;
	case 20652ULL: goto x86_l_50ac;
	case 20658ULL: goto x86_l_50b2;
	case 20661ULL: goto x86_l_50b5;
	case 20663ULL: goto x86_l_50b7;
	case 20668ULL: goto x86_l_50bc;
	case 20670ULL: goto x86_l_50be;
	case 20673ULL: goto x86_l_50c1;
	case 20679ULL: goto x86_l_50c7;
	case 20683ULL: goto x86_l_50cb;
	case 20689ULL: goto x86_l_50d1;
	case 20693ULL: goto x86_l_50d5;
	case 20696ULL: goto x86_l_50d8;
	case 20701ULL: goto x86_l_50dd;
	case 20706ULL: goto x86_l_50e2;
	case 20709ULL: goto x86_l_50e5;
	case 20715ULL: goto x86_l_50eb;
	case 20719ULL: goto x86_l_50ef;
	case 20724ULL: goto x86_l_50f4;
	case 20730ULL: goto x86_l_50fa;
	case 20734ULL: goto x86_l_50fe;
	case 20739ULL: goto x86_l_5103;
	case 20744ULL: goto x86_l_5108;
	case 20749ULL: goto x86_l_510d;
	case 20753ULL: goto x86_l_5111;
	case 20757ULL: goto x86_l_5115;
	case 20762ULL: goto x86_l_511a;
	case 20764ULL: goto x86_l_511c;
	case 20768ULL: goto x86_l_5120;
	case 20771ULL: goto x86_l_5123;
	case 20776ULL: goto x86_l_5128;
	case 20781ULL: goto x86_l_512d;
	case 20785ULL: goto x86_l_5131;
	case 20790ULL: goto x86_l_5136;
	case 20792ULL: goto x86_l_5138;
	case 20796ULL: goto x86_l_513c;
	case 20801ULL: goto x86_l_5141;
	case 20806ULL: goto x86_l_5146;
	case 20811ULL: goto x86_l_514b;
	case 20815ULL: goto x86_l_514f;
	case 20820ULL: goto x86_l_5154;
	case 20822ULL: goto x86_l_5156;
	case 20826ULL: goto x86_l_515a;
	case 20830ULL: goto x86_l_515e;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20845ULL: goto x86_l_516d;
	case 20850ULL: goto x86_l_5172;
	case 20853ULL: goto x86_l_5175;
	case 20855ULL: goto x86_l_5177;
	case 20860ULL: goto x86_l_517c;
	case 20865ULL: goto x86_l_5181;
	case 20869ULL: goto x86_l_5185;
	case 20874ULL: goto x86_l_518a;
	case 20879ULL: goto x86_l_518f;
	case 20884ULL: goto x86_l_5194;
	case 20889ULL: goto x86_l_5199;
	case 20891ULL: goto x86_l_519b;
	case 20896ULL: goto x86_l_51a0;
	case 20899ULL: goto x86_l_51a3;
	case 20905ULL: goto x86_l_51a9;
	case 20910ULL: goto x86_l_51ae;
	case 20913ULL: goto x86_l_51b1;
	case 20919ULL: goto x86_l_51b7;
	case 20923ULL: goto x86_l_51bb;
	case 20928ULL: goto x86_l_51c0;
	case 20933ULL: goto x86_l_51c5;
	case 20938ULL: goto x86_l_51ca;
	case 20943ULL: goto x86_l_51cf;
	case 20945ULL: goto x86_l_51d1;
	case 20949ULL: goto x86_l_51d5;
	case 20951ULL: goto x86_l_51d7;
	case 20957ULL: goto x86_l_51dd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4b79:
	/* 0x4b79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b7e:
	/* 0x4b7e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4b83:
	/* 0x4b83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b88:
	/* 0x4b88: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4b8d:
	/* 0x4b8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b8f:
	/* 0x4b8f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b93:
	/* 0x4b93: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4b95:
	/* 0x4b95: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4b9e:
	/* 0x4b9e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ba0:
	/* 0x4ba0: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_4ba6:
	/* 0x4ba6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bab:
	/* 0x4bab: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4bb1:
	/* 0x4bb1: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4bb4:
	/* 0x4bb4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4bb6:
	/* 0x4bb6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4bbb:
	/* 0x4bbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bbd:
	/* 0x4bbd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bc0:
	/* 0x4bc0: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_4bc6:
	/* 0x4bc6: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4bca:
	/* 0x4bca: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4bd0:
	/* 0x4bd0: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4bd4:
	/* 0x4bd4: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4bd7:
	/* 0x4bd7: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bdc:
	/* 0x4bdc: jmp    4c5a <trace_security_file_mprotect+0x4c5a> */
	goto x86_l_4c5a;
x86_l_4bde:
	/* 0x4bde: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4be1:
	/* 0x4be1: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_4be7:
	/* 0x4be7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4beb:
	/* 0x4beb: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4bf0:
	/* 0x4bf0: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_4bf6:
	/* 0x4bf6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4bfa:
	/* 0x4bfa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bff:
	/* 0x4bff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c04:
	/* 0x4c04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c09:
	/* 0x4c09: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c0d:
	/* 0x4c0d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c11:
	/* 0x4c11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c16:
	/* 0x4c16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c18:
	/* 0x4c18: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c1c:
	/* 0x4c1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c1f:
	/* 0x4c1f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c24:
	/* 0x4c24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c29:
	/* 0x4c29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c2d:
	/* 0x4c2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c32:
	/* 0x4c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c34:
	/* 0x4c34: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c38:
	/* 0x4c38: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c3d:
	/* 0x4c3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c42:
	/* 0x4c42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c47:
	/* 0x4c47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c4b:
	/* 0x4c4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c50:
	/* 0x4c50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c52:
	/* 0x4c52: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c56:
	/* 0x4c56: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c5a:
	/* 0x4c5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c5f:
	/* 0x4c5f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c64:
	/* 0x4c64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c69:
	/* 0x4c69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c6e:
	/* 0x4c6e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4c71:
	/* 0x4c71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c73:
	/* 0x4c73: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c78:
	/* 0x4c78: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c7d:
	/* 0x4c7d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c81:
	/* 0x4c81: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c86:
	/* 0x4c86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c8b:
	/* 0x4c8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c90:
	/* 0x4c90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c95:
	/* 0x4c95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c97:
	/* 0x4c97: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9c:
	/* 0x4c9c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c9f:
	/* 0x4c9f: je     4e60 <trace_security_file_mprotect+0x4e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e60;
	}
x86_l_4ca5:
	/* 0x4ca5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4caa:
	/* 0x4caa: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4cad:
	/* 0x4cad: je     4e60 <trace_security_file_mprotect+0x4e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e60;
	}
x86_l_4cb3:
	/* 0x4cb3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4cb7:
	/* 0x4cb7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cbc:
	/* 0x4cbc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4cc1:
	/* 0x4cc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cc6:
	/* 0x4cc6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ccb:
	/* 0x4ccb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ccd:
	/* 0x4ccd: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4cd1:
	/* 0x4cd1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4cd3:
	/* 0x4cd3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4cd9:
	/* 0x4cd9: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4cdc:
	/* 0x4cdc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4cde:
	/* 0x4cde: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_4ce4:
	/* 0x4ce4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce9:
	/* 0x4ce9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4cef:
	/* 0x4cef: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4cf2:
	/* 0x4cf2: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4cf4:
	/* 0x4cf4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4cf9:
	/* 0x4cf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cfb:
	/* 0x4cfb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4cfe:
	/* 0x4cfe: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_4d04:
	/* 0x4d04: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4d08:
	/* 0x4d08: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4d0e:
	/* 0x4d0e: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4d12:
	/* 0x4d12: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d15:
	/* 0x4d15: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d1a:
	/* 0x4d1a: jmp    4edc <trace_security_file_mprotect+0x4edc> */
	goto x86_l_4edc;
x86_l_4d1f:
	/* 0x4d1f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4d22:
	/* 0x4d22: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_4d28:
	/* 0x4d28: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d2c:
	/* 0x4d2c: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4d31:
	/* 0x4d31: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_4d37:
	/* 0x4d37: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d3b:
	/* 0x4d3b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d40:
	/* 0x4d40: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d45:
	/* 0x4d45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d4a:
	/* 0x4d4a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d4e:
	/* 0x4d4e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d52:
	/* 0x4d52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d57:
	/* 0x4d57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d59:
	/* 0x4d59: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d5d:
	/* 0x4d5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d60:
	/* 0x4d60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d65:
	/* 0x4d65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d6a:
	/* 0x4d6a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d6e:
	/* 0x4d6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d73:
	/* 0x4d73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d75:
	/* 0x4d75: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d79:
	/* 0x4d79: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d7e:
	/* 0x4d7e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d83:
	/* 0x4d83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d88:
	/* 0x4d88: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8c:
	/* 0x4d8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d91:
	/* 0x4d91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d93:
	/* 0x4d93: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d97:
	/* 0x4d97: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d9b:
	/* 0x4d9b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4da0:
	/* 0x4da0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4da5:
	/* 0x4da5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4daa:
	/* 0x4daa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4daf:
	/* 0x4daf: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4db2:
	/* 0x4db2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db4:
	/* 0x4db4: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db9:
	/* 0x4db9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dbe:
	/* 0x4dbe: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4dc2:
	/* 0x4dc2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dc7:
	/* 0x4dc7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4dd1:
	/* 0x4dd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dd6:
	/* 0x4dd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dd8:
	/* 0x4dd8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ddd:
	/* 0x4ddd: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4de0:
	/* 0x4de0: je     4fa1 <trace_security_file_mprotect+0x4fa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa1;
	}
x86_l_4de6:
	/* 0x4de6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4deb:
	/* 0x4deb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4dee:
	/* 0x4dee: je     4fa1 <trace_security_file_mprotect+0x4fa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa1;
	}
x86_l_4df4:
	/* 0x4df4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4df8:
	/* 0x4df8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dfd:
	/* 0x4dfd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4e02:
	/* 0x4e02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e07:
	/* 0x4e07: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4e0c:
	/* 0x4e0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e0e:
	/* 0x4e0e: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4e12:
	/* 0x4e12: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4e14:
	/* 0x4e14: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e1a:
	/* 0x4e1a: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4e1d:
	/* 0x4e1d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e1f:
	/* 0x4e1f: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_4e25:
	/* 0x4e25: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e2a:
	/* 0x4e2a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4e30:
	/* 0x4e30: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4e33:
	/* 0x4e33: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4e35:
	/* 0x4e35: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4e3a:
	/* 0x4e3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e3c:
	/* 0x4e3c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4e3f:
	/* 0x4e3f: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_4e45:
	/* 0x4e45: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4e49:
	/* 0x4e49: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4e4f:
	/* 0x4e4f: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4e53:
	/* 0x4e53: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e56:
	/* 0x4e56: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e5b:
	/* 0x4e5b: jmp    501d <trace_security_file_mprotect+0x501d> */
	goto x86_l_501d;
x86_l_4e60:
	/* 0x4e60: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4e63:
	/* 0x4e63: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_4e69:
	/* 0x4e69: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e6d:
	/* 0x4e6d: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4e72:
	/* 0x4e72: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_4e78:
	/* 0x4e78: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e7c:
	/* 0x4e7c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e81:
	/* 0x4e81: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e86:
	/* 0x4e86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e8b:
	/* 0x4e8b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e8f:
	/* 0x4e8f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e93:
	/* 0x4e93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e98:
	/* 0x4e98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e9a:
	/* 0x4e9a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e9e:
	/* 0x4e9e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ea1:
	/* 0x4ea1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ea6:
	/* 0x4ea6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4eab:
	/* 0x4eab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eaf:
	/* 0x4eaf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eb4:
	/* 0x4eb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb6:
	/* 0x4eb6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eba:
	/* 0x4eba: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ebf:
	/* 0x4ebf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ec4:
	/* 0x4ec4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ec9:
	/* 0x4ec9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ecd:
	/* 0x4ecd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ed2:
	/* 0x4ed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ed4:
	/* 0x4ed4: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ed8:
	/* 0x4ed8: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4edc:
	/* 0x4edc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ee1:
	/* 0x4ee1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ee6:
	/* 0x4ee6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4eeb:
	/* 0x4eeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ef0:
	/* 0x4ef0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4ef3:
	/* 0x4ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ef5:
	/* 0x4ef5: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4efa:
	/* 0x4efa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eff:
	/* 0x4eff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f03:
	/* 0x4f03: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f08:
	/* 0x4f08: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f0d:
	/* 0x4f0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f12:
	/* 0x4f12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f17:
	/* 0x4f17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f19:
	/* 0x4f19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f1e:
	/* 0x4f1e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4f21:
	/* 0x4f21: je     50e2 <trace_security_file_mprotect+0x50e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e2;
	}
x86_l_4f27:
	/* 0x4f27: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f2c:
	/* 0x4f2c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4f2f:
	/* 0x4f2f: je     50e2 <trace_security_file_mprotect+0x50e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e2;
	}
x86_l_4f35:
	/* 0x4f35: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f39:
	/* 0x4f39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f3e:
	/* 0x4f3e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4f43:
	/* 0x4f43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f48:
	/* 0x4f48: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4f4d:
	/* 0x4f4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4f:
	/* 0x4f4f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4f53:
	/* 0x4f53: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4f55:
	/* 0x4f55: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f5b:
	/* 0x4f5b: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4f5e:
	/* 0x4f5e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4f60:
	/* 0x4f60: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_4f66:
	/* 0x4f66: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f6b:
	/* 0x4f6b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4f71:
	/* 0x4f71: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f74:
	/* 0x4f74: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4f76:
	/* 0x4f76: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4f7b:
	/* 0x4f7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f7d:
	/* 0x4f7d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4f80:
	/* 0x4f80: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_4f86:
	/* 0x4f86: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4f8a:
	/* 0x4f8a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4f90:
	/* 0x4f90: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4f94:
	/* 0x4f94: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4f97:
	/* 0x4f97: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f9c:
	/* 0x4f9c: jmp    515e <trace_security_file_mprotect+0x515e> */
	goto x86_l_515e;
x86_l_4fa1:
	/* 0x4fa1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4fa4:
	/* 0x4fa4: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_4faa:
	/* 0x4faa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fae:
	/* 0x4fae: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4fb3:
	/* 0x4fb3: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_4fb9:
	/* 0x4fb9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4fbd:
	/* 0x4fbd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fc2:
	/* 0x4fc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fc7:
	/* 0x4fc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fcc:
	/* 0x4fcc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd0:
	/* 0x4fd0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4fd4:
	/* 0x4fd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fd9:
	/* 0x4fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fdb:
	/* 0x4fdb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fdf:
	/* 0x4fdf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fe2:
	/* 0x4fe2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fe7:
	/* 0x4fe7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fec:
	/* 0x4fec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ff0:
	/* 0x4ff0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ff5:
	/* 0x4ff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff7:
	/* 0x4ff7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ffb:
	/* 0x4ffb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5000:
	/* 0x5000: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5005:
	/* 0x5005: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_500a:
	/* 0x500a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_500e:
	/* 0x500e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5013:
	/* 0x5013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5015:
	/* 0x5015: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5019:
	/* 0x5019: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_501d:
	/* 0x501d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5022:
	/* 0x5022: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5027:
	/* 0x5027: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_502c:
	/* 0x502c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5031:
	/* 0x5031: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5034:
	/* 0x5034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5036:
	/* 0x5036: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_503b:
	/* 0x503b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5040:
	/* 0x5040: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5044:
	/* 0x5044: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5049:
	/* 0x5049: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_504e:
	/* 0x504e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5053:
	/* 0x5053: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5058:
	/* 0x5058: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_505a:
	/* 0x505a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_505f:
	/* 0x505f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5062:
	/* 0x5062: je     5223 <trace_security_file_mprotect+0x5223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21027ULL;
	}
x86_l_5068:
	/* 0x5068: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_506d:
	/* 0x506d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5070:
	/* 0x5070: je     5223 <trace_security_file_mprotect+0x5223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21027ULL;
	}
x86_l_5076:
	/* 0x5076: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_507a:
	/* 0x507a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_507f:
	/* 0x507f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5084:
	/* 0x5084: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5089:
	/* 0x5089: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_508e:
	/* 0x508e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5090:
	/* 0x5090: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5094:
	/* 0x5094: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5096:
	/* 0x5096: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_509c:
	/* 0x509c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_509f:
	/* 0x509f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_50a1:
	/* 0x50a1: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_50a7:
	/* 0x50a7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50ac:
	/* 0x50ac: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_50b2:
	/* 0x50b2: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50b5:
	/* 0x50b5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_50b7:
	/* 0x50b7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_50bc:
	/* 0x50bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50be:
	/* 0x50be: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50c1:
	/* 0x50c1: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_50c7:
	/* 0x50c7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_50cb:
	/* 0x50cb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_50d1:
	/* 0x50d1: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_50d5:
	/* 0x50d5: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_50d8:
	/* 0x50d8: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50dd:
	/* 0x50dd: jmp    529f <trace_security_file_mprotect+0x529f> */
	return 21151ULL;
x86_l_50e2:
	/* 0x50e2: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_50e5:
	/* 0x50e5: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_50eb:
	/* 0x50eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50ef:
	/* 0x50ef: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_50f4:
	/* 0x50f4: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_50fa:
	/* 0x50fa: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_50fe:
	/* 0x50fe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5103:
	/* 0x5103: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5108:
	/* 0x5108: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_510d:
	/* 0x510d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5111:
	/* 0x5111: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5115:
	/* 0x5115: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_511a:
	/* 0x511a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_511c:
	/* 0x511c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5120:
	/* 0x5120: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5123:
	/* 0x5123: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5128:
	/* 0x5128: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_512d:
	/* 0x512d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5131:
	/* 0x5131: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5136:
	/* 0x5136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5138:
	/* 0x5138: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_513c:
	/* 0x513c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5141:
	/* 0x5141: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5146:
	/* 0x5146: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_514b:
	/* 0x514b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_514f:
	/* 0x514f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5154:
	/* 0x5154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5156:
	/* 0x5156: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_515a:
	/* 0x515a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_515e:
	/* 0x515e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5163:
	/* 0x5163: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5168:
	/* 0x5168: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_516d:
	/* 0x516d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5172:
	/* 0x5172: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5175:
	/* 0x5175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5177:
	/* 0x5177: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_517c:
	/* 0x517c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5181:
	/* 0x5181: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5185:
	/* 0x5185: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518a:
	/* 0x518a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_518f:
	/* 0x518f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5194:
	/* 0x5194: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5199:
	/* 0x5199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519b:
	/* 0x519b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a0:
	/* 0x51a0: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_51a3:
	/* 0x51a3: je     5364 <trace_security_file_mprotect+0x5364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21348ULL;
	}
x86_l_51a9:
	/* 0x51a9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51ae:
	/* 0x51ae: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_51b1:
	/* 0x51b1: je     5364 <trace_security_file_mprotect+0x5364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21348ULL;
	}
x86_l_51b7:
	/* 0x51b7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51bb:
	/* 0x51bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51c0:
	/* 0x51c0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_51c5:
	/* 0x51c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51ca:
	/* 0x51ca: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_51cf:
	/* 0x51cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d1:
	/* 0x51d1: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_51d5:
	/* 0x51d5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_51d7:
	/* 0x51d7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51dd:
	/* 0x51dd: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
	return 20960ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20960ULL: goto x86_l_51e0;
	case 20962ULL: goto x86_l_51e2;
	case 20968ULL: goto x86_l_51e8;
	case 20973ULL: goto x86_l_51ed;
	case 20979ULL: goto x86_l_51f3;
	case 20982ULL: goto x86_l_51f6;
	case 20984ULL: goto x86_l_51f8;
	case 20989ULL: goto x86_l_51fd;
	case 20991ULL: goto x86_l_51ff;
	case 20994ULL: goto x86_l_5202;
	case 21000ULL: goto x86_l_5208;
	case 21004ULL: goto x86_l_520c;
	case 21010ULL: goto x86_l_5212;
	case 21014ULL: goto x86_l_5216;
	case 21017ULL: goto x86_l_5219;
	case 21022ULL: goto x86_l_521e;
	case 21027ULL: goto x86_l_5223;
	case 21030ULL: goto x86_l_5226;
	case 21036ULL: goto x86_l_522c;
	case 21040ULL: goto x86_l_5230;
	case 21045ULL: goto x86_l_5235;
	case 21051ULL: goto x86_l_523b;
	case 21055ULL: goto x86_l_523f;
	case 21060ULL: goto x86_l_5244;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21074ULL: goto x86_l_5252;
	case 21078ULL: goto x86_l_5256;
	case 21083ULL: goto x86_l_525b;
	case 21085ULL: goto x86_l_525d;
	case 21089ULL: goto x86_l_5261;
	case 21092ULL: goto x86_l_5264;
	case 21097ULL: goto x86_l_5269;
	case 21102ULL: goto x86_l_526e;
	case 21106ULL: goto x86_l_5272;
	case 21111ULL: goto x86_l_5277;
	case 21113ULL: goto x86_l_5279;
	case 21117ULL: goto x86_l_527d;
	case 21122ULL: goto x86_l_5282;
	case 21127ULL: goto x86_l_5287;
	case 21132ULL: goto x86_l_528c;
	case 21136ULL: goto x86_l_5290;
	case 21141ULL: goto x86_l_5295;
	case 21143ULL: goto x86_l_5297;
	case 21147ULL: goto x86_l_529b;
	case 21151ULL: goto x86_l_529f;
	case 21156ULL: goto x86_l_52a4;
	case 21161ULL: goto x86_l_52a9;
	case 21166ULL: goto x86_l_52ae;
	case 21171ULL: goto x86_l_52b3;
	case 21174ULL: goto x86_l_52b6;
	case 21176ULL: goto x86_l_52b8;
	case 21181ULL: goto x86_l_52bd;
	case 21186ULL: goto x86_l_52c2;
	case 21190ULL: goto x86_l_52c6;
	case 21195ULL: goto x86_l_52cb;
	case 21200ULL: goto x86_l_52d0;
	case 21205ULL: goto x86_l_52d5;
	case 21210ULL: goto x86_l_52da;
	case 21212ULL: goto x86_l_52dc;
	case 21217ULL: goto x86_l_52e1;
	case 21220ULL: goto x86_l_52e4;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21234ULL: goto x86_l_52f2;
	case 21240ULL: goto x86_l_52f8;
	case 21244ULL: goto x86_l_52fc;
	case 21249ULL: goto x86_l_5301;
	case 21254ULL: goto x86_l_5306;
	case 21259ULL: goto x86_l_530b;
	case 21264ULL: goto x86_l_5310;
	case 21266ULL: goto x86_l_5312;
	case 21270ULL: goto x86_l_5316;
	case 21272ULL: goto x86_l_5318;
	case 21278ULL: goto x86_l_531e;
	case 21281ULL: goto x86_l_5321;
	case 21283ULL: goto x86_l_5323;
	case 21289ULL: goto x86_l_5329;
	case 21294ULL: goto x86_l_532e;
	case 21300ULL: goto x86_l_5334;
	case 21303ULL: goto x86_l_5337;
	case 21305ULL: goto x86_l_5339;
	case 21310ULL: goto x86_l_533e;
	case 21312ULL: goto x86_l_5340;
	case 21315ULL: goto x86_l_5343;
	case 21321ULL: goto x86_l_5349;
	case 21325ULL: goto x86_l_534d;
	case 21331ULL: goto x86_l_5353;
	case 21335ULL: goto x86_l_5357;
	case 21338ULL: goto x86_l_535a;
	case 21343ULL: goto x86_l_535f;
	case 21348ULL: goto x86_l_5364;
	case 21351ULL: goto x86_l_5367;
	case 21357ULL: goto x86_l_536d;
	case 21361ULL: goto x86_l_5371;
	case 21366ULL: goto x86_l_5376;
	case 21372ULL: goto x86_l_537c;
	case 21376ULL: goto x86_l_5380;
	case 21381ULL: goto x86_l_5385;
	case 21386ULL: goto x86_l_538a;
	case 21391ULL: goto x86_l_538f;
	case 21395ULL: goto x86_l_5393;
	case 21399ULL: goto x86_l_5397;
	case 21404ULL: goto x86_l_539c;
	case 21406ULL: goto x86_l_539e;
	case 21410ULL: goto x86_l_53a2;
	case 21413ULL: goto x86_l_53a5;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21427ULL: goto x86_l_53b3;
	case 21432ULL: goto x86_l_53b8;
	case 21434ULL: goto x86_l_53ba;
	case 21438ULL: goto x86_l_53be;
	case 21443ULL: goto x86_l_53c3;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21464ULL: goto x86_l_53d8;
	case 21468ULL: goto x86_l_53dc;
	case 21472ULL: goto x86_l_53e0;
	case 21477ULL: goto x86_l_53e5;
	case 21482ULL: goto x86_l_53ea;
	case 21487ULL: goto x86_l_53ef;
	case 21492ULL: goto x86_l_53f4;
	case 21495ULL: goto x86_l_53f7;
	case 21497ULL: goto x86_l_53f9;
	case 21502ULL: goto x86_l_53fe;
	case 21507ULL: goto x86_l_5403;
	case 21511ULL: goto x86_l_5407;
	case 21516ULL: goto x86_l_540c;
	case 21521ULL: goto x86_l_5411;
	case 21526ULL: goto x86_l_5416;
	case 21531ULL: goto x86_l_541b;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21541ULL: goto x86_l_5425;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21555ULL: goto x86_l_5433;
	case 21561ULL: goto x86_l_5439;
	case 21565ULL: goto x86_l_543d;
	case 21570ULL: goto x86_l_5442;
	case 21575ULL: goto x86_l_5447;
	case 21580ULL: goto x86_l_544c;
	case 21585ULL: goto x86_l_5451;
	case 21587ULL: goto x86_l_5453;
	case 21591ULL: goto x86_l_5457;
	case 21593ULL: goto x86_l_5459;
	case 21599ULL: goto x86_l_545f;
	case 21602ULL: goto x86_l_5462;
	case 21604ULL: goto x86_l_5464;
	case 21610ULL: goto x86_l_546a;
	case 21615ULL: goto x86_l_546f;
	case 21621ULL: goto x86_l_5475;
	case 21624ULL: goto x86_l_5478;
	case 21626ULL: goto x86_l_547a;
	case 21631ULL: goto x86_l_547f;
	case 21633ULL: goto x86_l_5481;
	case 21636ULL: goto x86_l_5484;
	case 21642ULL: goto x86_l_548a;
	case 21646ULL: goto x86_l_548e;
	case 21652ULL: goto x86_l_5494;
	case 21656ULL: goto x86_l_5498;
	case 21659ULL: goto x86_l_549b;
	case 21664ULL: goto x86_l_54a0;
	case 21669ULL: goto x86_l_54a5;
	case 21672ULL: goto x86_l_54a8;
	case 21678ULL: goto x86_l_54ae;
	case 21682ULL: goto x86_l_54b2;
	case 21687ULL: goto x86_l_54b7;
	case 21693ULL: goto x86_l_54bd;
	case 21697ULL: goto x86_l_54c1;
	case 21702ULL: goto x86_l_54c6;
	case 21707ULL: goto x86_l_54cb;
	case 21712ULL: goto x86_l_54d0;
	case 21716ULL: goto x86_l_54d4;
	case 21720ULL: goto x86_l_54d8;
	case 21725ULL: goto x86_l_54dd;
	case 21727ULL: goto x86_l_54df;
	case 21731ULL: goto x86_l_54e3;
	case 21734ULL: goto x86_l_54e6;
	case 21739ULL: goto x86_l_54eb;
	case 21744ULL: goto x86_l_54f0;
	case 21748ULL: goto x86_l_54f4;
	case 21753ULL: goto x86_l_54f9;
	case 21755ULL: goto x86_l_54fb;
	case 21759ULL: goto x86_l_54ff;
	case 21764ULL: goto x86_l_5504;
	case 21769ULL: goto x86_l_5509;
	case 21774ULL: goto x86_l_550e;
	case 21778ULL: goto x86_l_5512;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21789ULL: goto x86_l_551d;
	case 21793ULL: goto x86_l_5521;
	case 21798ULL: goto x86_l_5526;
	case 21803ULL: goto x86_l_552b;
	case 21808ULL: goto x86_l_5530;
	case 21813ULL: goto x86_l_5535;
	case 21816ULL: goto x86_l_5538;
	case 21818ULL: goto x86_l_553a;
	case 21823ULL: goto x86_l_553f;
	case 21828ULL: goto x86_l_5544;
	case 21832ULL: goto x86_l_5548;
	case 21837ULL: goto x86_l_554d;
	case 21842ULL: goto x86_l_5552;
	case 21847ULL: goto x86_l_5557;
	case 21852ULL: goto x86_l_555c;
	case 21854ULL: goto x86_l_555e;
	case 21859ULL: goto x86_l_5563;
	case 21862ULL: goto x86_l_5566;
	case 21868ULL: goto x86_l_556c;
	case 21873ULL: goto x86_l_5571;
	case 21876ULL: goto x86_l_5574;
	case 21882ULL: goto x86_l_557a;
	case 21886ULL: goto x86_l_557e;
	case 21891ULL: goto x86_l_5583;
	case 21896ULL: goto x86_l_5588;
	case 21901ULL: goto x86_l_558d;
	case 21906ULL: goto x86_l_5592;
	case 21908ULL: goto x86_l_5594;
	case 21912ULL: goto x86_l_5598;
	case 21914ULL: goto x86_l_559a;
	case 21920ULL: goto x86_l_55a0;
	case 21923ULL: goto x86_l_55a3;
	case 21925ULL: goto x86_l_55a5;
	case 21931ULL: goto x86_l_55ab;
	case 21936ULL: goto x86_l_55b0;
	case 21942ULL: goto x86_l_55b6;
	case 21945ULL: goto x86_l_55b9;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21954ULL: goto x86_l_55c2;
	case 21957ULL: goto x86_l_55c5;
	case 21963ULL: goto x86_l_55cb;
	case 21967ULL: goto x86_l_55cf;
	case 21973ULL: goto x86_l_55d5;
	case 21977ULL: goto x86_l_55d9;
	case 21980ULL: goto x86_l_55dc;
	case 21985ULL: goto x86_l_55e1;
	case 21990ULL: goto x86_l_55e6;
	case 21993ULL: goto x86_l_55e9;
	case 21999ULL: goto x86_l_55ef;
	case 22003ULL: goto x86_l_55f3;
	case 22008ULL: goto x86_l_55f8;
	case 22014ULL: goto x86_l_55fe;
	case 22018ULL: goto x86_l_5602;
	case 22023ULL: goto x86_l_5607;
	case 22028ULL: goto x86_l_560c;
	case 22033ULL: goto x86_l_5611;
	case 22037ULL: goto x86_l_5615;
	case 22041ULL: goto x86_l_5619;
	case 22046ULL: goto x86_l_561e;
	case 22048ULL: goto x86_l_5620;
	case 22052ULL: goto x86_l_5624;
	case 22055ULL: goto x86_l_5627;
	case 22060ULL: goto x86_l_562c;
	case 22065ULL: goto x86_l_5631;
	case 22069ULL: goto x86_l_5635;
	case 22074ULL: goto x86_l_563a;
	case 22076ULL: goto x86_l_563c;
	case 22080ULL: goto x86_l_5640;
	case 22085ULL: goto x86_l_5645;
	case 22090ULL: goto x86_l_564a;
	case 22095ULL: goto x86_l_564f;
	case 22099ULL: goto x86_l_5653;
	case 22104ULL: goto x86_l_5658;
	case 22106ULL: goto x86_l_565a;
	case 22110ULL: goto x86_l_565e;
	case 22114ULL: goto x86_l_5662;
	case 22119ULL: goto x86_l_5667;
	case 22124ULL: goto x86_l_566c;
	case 22129ULL: goto x86_l_5671;
	case 22134ULL: goto x86_l_5676;
	case 22137ULL: goto x86_l_5679;
	case 22139ULL: goto x86_l_567b;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22153ULL: goto x86_l_5689;
	case 22158ULL: goto x86_l_568e;
	case 22163ULL: goto x86_l_5693;
	case 22168ULL: goto x86_l_5698;
	case 22173ULL: goto x86_l_569d;
	case 22175ULL: goto x86_l_569f;
	case 22180ULL: goto x86_l_56a4;
	case 22183ULL: goto x86_l_56a7;
	case 22189ULL: goto x86_l_56ad;
	case 22194ULL: goto x86_l_56b2;
	case 22197ULL: goto x86_l_56b5;
	case 22203ULL: goto x86_l_56bb;
	case 22207ULL: goto x86_l_56bf;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22222ULL: goto x86_l_56ce;
	case 22227ULL: goto x86_l_56d3;
	case 22229ULL: goto x86_l_56d5;
	case 22233ULL: goto x86_l_56d9;
	case 22235ULL: goto x86_l_56db;
	case 22241ULL: goto x86_l_56e1;
	case 22244ULL: goto x86_l_56e4;
	case 22246ULL: goto x86_l_56e6;
	case 22252ULL: goto x86_l_56ec;
	case 22257ULL: goto x86_l_56f1;
	case 22263ULL: goto x86_l_56f7;
	case 22266ULL: goto x86_l_56fa;
	case 22268ULL: goto x86_l_56fc;
	case 22273ULL: goto x86_l_5701;
	case 22275ULL: goto x86_l_5703;
	case 22278ULL: goto x86_l_5706;
	case 22284ULL: goto x86_l_570c;
	case 22288ULL: goto x86_l_5710;
	case 22294ULL: goto x86_l_5716;
	case 22298ULL: goto x86_l_571a;
	case 22301ULL: goto x86_l_571d;
	case 22306ULL: goto x86_l_5722;
	case 22311ULL: goto x86_l_5727;
	case 22314ULL: goto x86_l_572a;
	case 22320ULL: goto x86_l_5730;
	case 22324ULL: goto x86_l_5734;
	case 22329ULL: goto x86_l_5739;
	case 22335ULL: goto x86_l_573f;
	case 22339ULL: goto x86_l_5743;
	case 22344ULL: goto x86_l_5748;
	case 22349ULL: goto x86_l_574d;
	case 22354ULL: goto x86_l_5752;
	case 22358ULL: goto x86_l_5756;
	case 22362ULL: goto x86_l_575a;
	case 22367ULL: goto x86_l_575f;
	case 22369ULL: goto x86_l_5761;
	case 22373ULL: goto x86_l_5765;
	case 22376ULL: goto x86_l_5768;
	case 22381ULL: goto x86_l_576d;
	case 22386ULL: goto x86_l_5772;
	case 22390ULL: goto x86_l_5776;
	case 22395ULL: goto x86_l_577b;
	case 22397ULL: goto x86_l_577d;
	case 22401ULL: goto x86_l_5781;
	case 22406ULL: goto x86_l_5786;
	case 22411ULL: goto x86_l_578b;
	case 22416ULL: goto x86_l_5790;
	case 22420ULL: goto x86_l_5794;
	case 22425ULL: goto x86_l_5799;
	case 22427ULL: goto x86_l_579b;
	case 22431ULL: goto x86_l_579f;
	case 22435ULL: goto x86_l_57a3;
	case 22440ULL: goto x86_l_57a8;
	case 22445ULL: goto x86_l_57ad;
	case 22450ULL: goto x86_l_57b2;
	case 22455ULL: goto x86_l_57b7;
	case 22458ULL: goto x86_l_57ba;
	case 22460ULL: goto x86_l_57bc;
	case 22465ULL: goto x86_l_57c1;
	case 22470ULL: goto x86_l_57c6;
	case 22474ULL: goto x86_l_57ca;
	case 22479ULL: goto x86_l_57cf;
	case 22484ULL: goto x86_l_57d4;
	case 22489ULL: goto x86_l_57d9;
	case 22494ULL: goto x86_l_57de;
	case 22496ULL: goto x86_l_57e0;
	case 22501ULL: goto x86_l_57e5;
	case 22504ULL: goto x86_l_57e8;
	case 22510ULL: goto x86_l_57ee;
	case 22515ULL: goto x86_l_57f3;
	case 22518ULL: goto x86_l_57f6;
	case 22524ULL: goto x86_l_57fc;
	case 22528ULL: goto x86_l_5800;
	case 22533ULL: goto x86_l_5805;
	case 22538ULL: goto x86_l_580a;
	case 22543ULL: goto x86_l_580f;
	case 22548ULL: goto x86_l_5814;
	case 22550ULL: goto x86_l_5816;
	case 22554ULL: goto x86_l_581a;
	case 22556ULL: goto x86_l_581c;
	case 22562ULL: goto x86_l_5822;
	case 22565ULL: goto x86_l_5825;
	case 22567ULL: goto x86_l_5827;
	case 22573ULL: goto x86_l_582d;
	case 22578ULL: goto x86_l_5832;
	case 22584ULL: goto x86_l_5838;
	case 22587ULL: goto x86_l_583b;
	case 22589ULL: goto x86_l_583d;
	case 22594ULL: goto x86_l_5842;
	case 22596ULL: goto x86_l_5844;
	default: return 0xffffffffffffffffULL;
	}
x86_l_51e0:
	/* 0x51e0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_51e2:
	/* 0x51e2: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_51e8:
	/* 0x51e8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51ed:
	/* 0x51ed: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_51f3:
	/* 0x51f3: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_51f6:
	/* 0x51f6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_51f8:
	/* 0x51f8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_51fd:
	/* 0x51fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ff:
	/* 0x51ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5202:
	/* 0x5202: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_5208:
	/* 0x5208: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_520c:
	/* 0x520c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5212:
	/* 0x5212: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5216:
	/* 0x5216: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5219:
	/* 0x5219: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_521e:
	/* 0x521e: jmp    53e0 <trace_security_file_mprotect+0x53e0> */
	goto x86_l_53e0;
x86_l_5223:
	/* 0x5223: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5226:
	/* 0x5226: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_522c:
	/* 0x522c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5230:
	/* 0x5230: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5235:
	/* 0x5235: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_523b:
	/* 0x523b: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_523f:
	/* 0x523f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5244:
	/* 0x5244: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5249:
	/* 0x5249: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_524e:
	/* 0x524e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5252:
	/* 0x5252: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5256:
	/* 0x5256: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525b:
	/* 0x525b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_525d:
	/* 0x525d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5261:
	/* 0x5261: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5264:
	/* 0x5264: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5269:
	/* 0x5269: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_526e:
	/* 0x526e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5272:
	/* 0x5272: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5277:
	/* 0x5277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5279:
	/* 0x5279: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_527d:
	/* 0x527d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5282:
	/* 0x5282: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5287:
	/* 0x5287: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_528c:
	/* 0x528c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5290:
	/* 0x5290: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5295:
	/* 0x5295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5297:
	/* 0x5297: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_529b:
	/* 0x529b: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_529f:
	/* 0x529f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52a4:
	/* 0x52a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52a9:
	/* 0x52a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52ae:
	/* 0x52ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52b3:
	/* 0x52b3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_52b6:
	/* 0x52b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b8:
	/* 0x52b8: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52bd:
	/* 0x52bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c2:
	/* 0x52c2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52c6:
	/* 0x52c6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52cb:
	/* 0x52cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52d0:
	/* 0x52d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52d5:
	/* 0x52d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52da:
	/* 0x52da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52dc:
	/* 0x52dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52e1:
	/* 0x52e1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_52e4:
	/* 0x52e4: je     54a5 <trace_security_file_mprotect+0x54a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54a5;
	}
x86_l_52ea:
	/* 0x52ea: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52ef:
	/* 0x52ef: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_52f2:
	/* 0x52f2: je     54a5 <trace_security_file_mprotect+0x54a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54a5;
	}
x86_l_52f8:
	/* 0x52f8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52fc:
	/* 0x52fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5301:
	/* 0x5301: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5306:
	/* 0x5306: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_530b:
	/* 0x530b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5310:
	/* 0x5310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5312:
	/* 0x5312: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5316:
	/* 0x5316: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5318:
	/* 0x5318: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_531e:
	/* 0x531e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5321:
	/* 0x5321: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5323:
	/* 0x5323: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_5329:
	/* 0x5329: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_532e:
	/* 0x532e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5334:
	/* 0x5334: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5337:
	/* 0x5337: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5339:
	/* 0x5339: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_533e:
	/* 0x533e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5340:
	/* 0x5340: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5343:
	/* 0x5343: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_5349:
	/* 0x5349: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_534d:
	/* 0x534d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5353:
	/* 0x5353: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5357:
	/* 0x5357: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_535a:
	/* 0x535a: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535f:
	/* 0x535f: jmp    5521 <trace_security_file_mprotect+0x5521> */
	goto x86_l_5521;
x86_l_5364:
	/* 0x5364: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5367:
	/* 0x5367: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_536d:
	/* 0x536d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5371:
	/* 0x5371: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5376:
	/* 0x5376: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_537c:
	/* 0x537c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5380:
	/* 0x5380: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5385:
	/* 0x5385: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_538a:
	/* 0x538a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_538f:
	/* 0x538f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5393:
	/* 0x5393: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5397:
	/* 0x5397: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_539c:
	/* 0x539c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_539e:
	/* 0x539e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53a2:
	/* 0x53a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_53a5:
	/* 0x53a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53aa:
	/* 0x53aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53af:
	/* 0x53af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53b3:
	/* 0x53b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53b8:
	/* 0x53b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53ba:
	/* 0x53ba: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53be:
	/* 0x53be: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53c3:
	/* 0x53c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53c8:
	/* 0x53c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53cd:
	/* 0x53cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53d1:
	/* 0x53d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53d6:
	/* 0x53d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d8:
	/* 0x53d8: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53dc:
	/* 0x53dc: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_53e0:
	/* 0x53e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53e5:
	/* 0x53e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53ea:
	/* 0x53ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53ef:
	/* 0x53ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53f4:
	/* 0x53f4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_53f7:
	/* 0x53f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53f9:
	/* 0x53f9: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53fe:
	/* 0x53fe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5403:
	/* 0x5403: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5407:
	/* 0x5407: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_540c:
	/* 0x540c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5411:
	/* 0x5411: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5416:
	/* 0x5416: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_541b:
	/* 0x541b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_541d:
	/* 0x541d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5422:
	/* 0x5422: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5425:
	/* 0x5425: je     55e6 <trace_security_file_mprotect+0x55e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55e6;
	}
x86_l_542b:
	/* 0x542b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5430:
	/* 0x5430: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5433:
	/* 0x5433: je     55e6 <trace_security_file_mprotect+0x55e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55e6;
	}
x86_l_5439:
	/* 0x5439: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_543d:
	/* 0x543d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5442:
	/* 0x5442: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5447:
	/* 0x5447: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_544c:
	/* 0x544c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5451:
	/* 0x5451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5453:
	/* 0x5453: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5457:
	/* 0x5457: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5459:
	/* 0x5459: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_545f:
	/* 0x545f: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5462:
	/* 0x5462: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5464:
	/* 0x5464: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_546a:
	/* 0x546a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_546f:
	/* 0x546f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5475:
	/* 0x5475: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5478:
	/* 0x5478: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_547a:
	/* 0x547a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_547f:
	/* 0x547f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5481:
	/* 0x5481: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5484:
	/* 0x5484: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_548a:
	/* 0x548a: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_548e:
	/* 0x548e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5494:
	/* 0x5494: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5498:
	/* 0x5498: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_549b:
	/* 0x549b: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a0:
	/* 0x54a0: jmp    5662 <trace_security_file_mprotect+0x5662> */
	goto x86_l_5662;
x86_l_54a5:
	/* 0x54a5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_54a8:
	/* 0x54a8: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_54ae:
	/* 0x54ae: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54b2:
	/* 0x54b2: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_54b7:
	/* 0x54b7: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_54bd:
	/* 0x54bd: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54c1:
	/* 0x54c1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c6:
	/* 0x54c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54cb:
	/* 0x54cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54d0:
	/* 0x54d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54d4:
	/* 0x54d4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54d8:
	/* 0x54d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54dd:
	/* 0x54dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54df:
	/* 0x54df: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54e3:
	/* 0x54e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54e6:
	/* 0x54e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54eb:
	/* 0x54eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54f0:
	/* 0x54f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f4:
	/* 0x54f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54f9:
	/* 0x54f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54fb:
	/* 0x54fb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54ff:
	/* 0x54ff: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5504:
	/* 0x5504: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5509:
	/* 0x5509: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_550e:
	/* 0x550e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5512:
	/* 0x5512: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5517:
	/* 0x5517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5519:
	/* 0x5519: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_551d:
	/* 0x551d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5521:
	/* 0x5521: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5526:
	/* 0x5526: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_552b:
	/* 0x552b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5530:
	/* 0x5530: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5535:
	/* 0x5535: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5538:
	/* 0x5538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_553a:
	/* 0x553a: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_553f:
	/* 0x553f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5544:
	/* 0x5544: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5548:
	/* 0x5548: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_554d:
	/* 0x554d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5552:
	/* 0x5552: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5557:
	/* 0x5557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_555c:
	/* 0x555c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555e:
	/* 0x555e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5563:
	/* 0x5563: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5566:
	/* 0x5566: je     5727 <trace_security_file_mprotect+0x5727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5727;
	}
x86_l_556c:
	/* 0x556c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5571:
	/* 0x5571: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5574:
	/* 0x5574: je     5727 <trace_security_file_mprotect+0x5727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5727;
	}
x86_l_557a:
	/* 0x557a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_557e:
	/* 0x557e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5583:
	/* 0x5583: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5588:
	/* 0x5588: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_558d:
	/* 0x558d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5592:
	/* 0x5592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5594:
	/* 0x5594: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5598:
	/* 0x5598: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_559a:
	/* 0x559a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55a0:
	/* 0x55a0: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_55a3:
	/* 0x55a3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_55a5:
	/* 0x55a5: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_55ab:
	/* 0x55ab: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55b0:
	/* 0x55b0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_55b6:
	/* 0x55b6: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55b9:
	/* 0x55b9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_55bb:
	/* 0x55bb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_55c0:
	/* 0x55c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c2:
	/* 0x55c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_55c5:
	/* 0x55c5: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_55cb:
	/* 0x55cb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_55cf:
	/* 0x55cf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_55d5:
	/* 0x55d5: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_55d9:
	/* 0x55d9: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_55dc:
	/* 0x55dc: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55e1:
	/* 0x55e1: jmp    57a3 <trace_security_file_mprotect+0x57a3> */
	goto x86_l_57a3;
x86_l_55e6:
	/* 0x55e6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_55e9:
	/* 0x55e9: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_55ef:
	/* 0x55ef: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f3:
	/* 0x55f3: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_55f8:
	/* 0x55f8: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_55fe:
	/* 0x55fe: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5602:
	/* 0x5602: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5607:
	/* 0x5607: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_560c:
	/* 0x560c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5611:
	/* 0x5611: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5615:
	/* 0x5615: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5619:
	/* 0x5619: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_561e:
	/* 0x561e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5620:
	/* 0x5620: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5624:
	/* 0x5624: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5627:
	/* 0x5627: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_562c:
	/* 0x562c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5631:
	/* 0x5631: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5635:
	/* 0x5635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_563a:
	/* 0x563a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_563c:
	/* 0x563c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5640:
	/* 0x5640: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5645:
	/* 0x5645: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_564a:
	/* 0x564a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_564f:
	/* 0x564f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5653:
	/* 0x5653: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5658:
	/* 0x5658: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_565a:
	/* 0x565a: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_565e:
	/* 0x565e: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5662:
	/* 0x5662: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5667:
	/* 0x5667: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_566c:
	/* 0x566c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5671:
	/* 0x5671: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5676:
	/* 0x5676: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5679:
	/* 0x5679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_567b:
	/* 0x567b: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5680:
	/* 0x5680: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5685:
	/* 0x5685: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5689:
	/* 0x5689: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_568e:
	/* 0x568e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5693:
	/* 0x5693: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5698:
	/* 0x5698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_569d:
	/* 0x569d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569f:
	/* 0x569f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56a4:
	/* 0x56a4: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_56a7:
	/* 0x56a7: je     5868 <trace_security_file_mprotect+0x5868> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22632ULL;
	}
x86_l_56ad:
	/* 0x56ad: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56b2:
	/* 0x56b2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_56b5:
	/* 0x56b5: je     5868 <trace_security_file_mprotect+0x5868> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22632ULL;
	}
x86_l_56bb:
	/* 0x56bb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_56bf:
	/* 0x56bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56c4:
	/* 0x56c4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_56c9:
	/* 0x56c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56ce:
	/* 0x56ce: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_56d3:
	/* 0x56d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56d5:
	/* 0x56d5: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_56d9:
	/* 0x56d9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_56db:
	/* 0x56db: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_56e1:
	/* 0x56e1: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_56e4:
	/* 0x56e4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56e6:
	/* 0x56e6: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_56ec:
	/* 0x56ec: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_56f1:
	/* 0x56f1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_56f7:
	/* 0x56f7: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_56fa:
	/* 0x56fa: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_56fc:
	/* 0x56fc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5701:
	/* 0x5701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5703:
	/* 0x5703: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5706:
	/* 0x5706: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_570c:
	/* 0x570c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5710:
	/* 0x5710: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5716:
	/* 0x5716: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_571a:
	/* 0x571a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_571d:
	/* 0x571d: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5722:
	/* 0x5722: jmp    58e4 <trace_security_file_mprotect+0x58e4> */
	return 22756ULL;
x86_l_5727:
	/* 0x5727: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_572a:
	/* 0x572a: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_5730:
	/* 0x5730: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5734:
	/* 0x5734: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5739:
	/* 0x5739: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_573f:
	/* 0x573f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5743:
	/* 0x5743: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5748:
	/* 0x5748: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_574d:
	/* 0x574d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5752:
	/* 0x5752: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5756:
	/* 0x5756: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_575a:
	/* 0x575a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_575f:
	/* 0x575f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5761:
	/* 0x5761: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5765:
	/* 0x5765: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5768:
	/* 0x5768: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_576d:
	/* 0x576d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5772:
	/* 0x5772: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5776:
	/* 0x5776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_577b:
	/* 0x577b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_577d:
	/* 0x577d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5781:
	/* 0x5781: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5786:
	/* 0x5786: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_578b:
	/* 0x578b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5790:
	/* 0x5790: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5794:
	/* 0x5794: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5799:
	/* 0x5799: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_579b:
	/* 0x579b: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_579f:
	/* 0x579f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57a3:
	/* 0x57a3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57a8:
	/* 0x57a8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57ad:
	/* 0x57ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57b2:
	/* 0x57b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57b7:
	/* 0x57b7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_57ba:
	/* 0x57ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57bc:
	/* 0x57bc: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57c1:
	/* 0x57c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57c6:
	/* 0x57c6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57ca:
	/* 0x57ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57cf:
	/* 0x57cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57d4:
	/* 0x57d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57d9:
	/* 0x57d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57de:
	/* 0x57de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e0:
	/* 0x57e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e5:
	/* 0x57e5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_57e8:
	/* 0x57e8: je     59a9 <trace_security_file_mprotect+0x59a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22953ULL;
	}
x86_l_57ee:
	/* 0x57ee: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57f3:
	/* 0x57f3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_57f6:
	/* 0x57f6: je     59a9 <trace_security_file_mprotect+0x59a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22953ULL;
	}
x86_l_57fc:
	/* 0x57fc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5800:
	/* 0x5800: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5805:
	/* 0x5805: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_580a:
	/* 0x580a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_580f:
	/* 0x580f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5814:
	/* 0x5814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5816:
	/* 0x5816: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_581a:
	/* 0x581a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_581c:
	/* 0x581c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5822:
	/* 0x5822: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5825:
	/* 0x5825: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5827:
	/* 0x5827: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_582d:
	/* 0x582d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5832:
	/* 0x5832: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5838:
	/* 0x5838: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_583b:
	/* 0x583b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_583d:
	/* 0x583d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5842:
	/* 0x5842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5844:
	/* 0x5844: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
	return 22599ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22599ULL: goto x86_l_5847;
	case 22605ULL: goto x86_l_584d;
	case 22609ULL: goto x86_l_5851;
	case 22615ULL: goto x86_l_5857;
	case 22619ULL: goto x86_l_585b;
	case 22622ULL: goto x86_l_585e;
	case 22627ULL: goto x86_l_5863;
	case 22632ULL: goto x86_l_5868;
	case 22635ULL: goto x86_l_586b;
	case 22641ULL: goto x86_l_5871;
	case 22645ULL: goto x86_l_5875;
	case 22650ULL: goto x86_l_587a;
	case 22656ULL: goto x86_l_5880;
	case 22660ULL: goto x86_l_5884;
	case 22665ULL: goto x86_l_5889;
	case 22670ULL: goto x86_l_588e;
	case 22675ULL: goto x86_l_5893;
	case 22679ULL: goto x86_l_5897;
	case 22683ULL: goto x86_l_589b;
	case 22688ULL: goto x86_l_58a0;
	case 22690ULL: goto x86_l_58a2;
	case 22694ULL: goto x86_l_58a6;
	case 22697ULL: goto x86_l_58a9;
	case 22702ULL: goto x86_l_58ae;
	case 22707ULL: goto x86_l_58b3;
	case 22711ULL: goto x86_l_58b7;
	case 22716ULL: goto x86_l_58bc;
	case 22718ULL: goto x86_l_58be;
	case 22722ULL: goto x86_l_58c2;
	case 22727ULL: goto x86_l_58c7;
	case 22732ULL: goto x86_l_58cc;
	case 22737ULL: goto x86_l_58d1;
	case 22741ULL: goto x86_l_58d5;
	case 22746ULL: goto x86_l_58da;
	case 22748ULL: goto x86_l_58dc;
	case 22752ULL: goto x86_l_58e0;
	case 22756ULL: goto x86_l_58e4;
	case 22761ULL: goto x86_l_58e9;
	case 22766ULL: goto x86_l_58ee;
	case 22771ULL: goto x86_l_58f3;
	case 22776ULL: goto x86_l_58f8;
	case 22779ULL: goto x86_l_58fb;
	case 22781ULL: goto x86_l_58fd;
	case 22786ULL: goto x86_l_5902;
	case 22791ULL: goto x86_l_5907;
	case 22795ULL: goto x86_l_590b;
	case 22800ULL: goto x86_l_5910;
	case 22805ULL: goto x86_l_5915;
	case 22810ULL: goto x86_l_591a;
	case 22815ULL: goto x86_l_591f;
	case 22817ULL: goto x86_l_5921;
	case 22822ULL: goto x86_l_5926;
	case 22825ULL: goto x86_l_5929;
	case 22831ULL: goto x86_l_592f;
	case 22836ULL: goto x86_l_5934;
	case 22839ULL: goto x86_l_5937;
	case 22845ULL: goto x86_l_593d;
	case 22849ULL: goto x86_l_5941;
	case 22854ULL: goto x86_l_5946;
	case 22859ULL: goto x86_l_594b;
	case 22864ULL: goto x86_l_5950;
	case 22869ULL: goto x86_l_5955;
	case 22871ULL: goto x86_l_5957;
	case 22875ULL: goto x86_l_595b;
	case 22877ULL: goto x86_l_595d;
	case 22883ULL: goto x86_l_5963;
	case 22886ULL: goto x86_l_5966;
	case 22888ULL: goto x86_l_5968;
	case 22894ULL: goto x86_l_596e;
	case 22899ULL: goto x86_l_5973;
	case 22905ULL: goto x86_l_5979;
	case 22908ULL: goto x86_l_597c;
	case 22910ULL: goto x86_l_597e;
	case 22915ULL: goto x86_l_5983;
	case 22917ULL: goto x86_l_5985;
	case 22920ULL: goto x86_l_5988;
	case 22926ULL: goto x86_l_598e;
	case 22930ULL: goto x86_l_5992;
	case 22936ULL: goto x86_l_5998;
	case 22940ULL: goto x86_l_599c;
	case 22943ULL: goto x86_l_599f;
	case 22948ULL: goto x86_l_59a4;
	case 22953ULL: goto x86_l_59a9;
	case 22956ULL: goto x86_l_59ac;
	case 22962ULL: goto x86_l_59b2;
	case 22966ULL: goto x86_l_59b6;
	case 22971ULL: goto x86_l_59bb;
	case 22977ULL: goto x86_l_59c1;
	case 22981ULL: goto x86_l_59c5;
	case 22986ULL: goto x86_l_59ca;
	case 22991ULL: goto x86_l_59cf;
	case 22996ULL: goto x86_l_59d4;
	case 23000ULL: goto x86_l_59d8;
	case 23004ULL: goto x86_l_59dc;
	case 23009ULL: goto x86_l_59e1;
	case 23011ULL: goto x86_l_59e3;
	case 23015ULL: goto x86_l_59e7;
	case 23018ULL: goto x86_l_59ea;
	case 23023ULL: goto x86_l_59ef;
	case 23028ULL: goto x86_l_59f4;
	case 23032ULL: goto x86_l_59f8;
	case 23037ULL: goto x86_l_59fd;
	case 23039ULL: goto x86_l_59ff;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23053ULL: goto x86_l_5a0d;
	case 23058ULL: goto x86_l_5a12;
	case 23062ULL: goto x86_l_5a16;
	case 23067ULL: goto x86_l_5a1b;
	case 23069ULL: goto x86_l_5a1d;
	case 23073ULL: goto x86_l_5a21;
	case 23077ULL: goto x86_l_5a25;
	case 23082ULL: goto x86_l_5a2a;
	case 23087ULL: goto x86_l_5a2f;
	case 23092ULL: goto x86_l_5a34;
	case 23097ULL: goto x86_l_5a39;
	case 23100ULL: goto x86_l_5a3c;
	case 23102ULL: goto x86_l_5a3e;
	case 23107ULL: goto x86_l_5a43;
	case 23112ULL: goto x86_l_5a48;
	case 23116ULL: goto x86_l_5a4c;
	case 23121ULL: goto x86_l_5a51;
	case 23126ULL: goto x86_l_5a56;
	case 23131ULL: goto x86_l_5a5b;
	case 23136ULL: goto x86_l_5a60;
	case 23138ULL: goto x86_l_5a62;
	case 23143ULL: goto x86_l_5a67;
	case 23146ULL: goto x86_l_5a6a;
	case 23152ULL: goto x86_l_5a70;
	case 23157ULL: goto x86_l_5a75;
	case 23160ULL: goto x86_l_5a78;
	case 23166ULL: goto x86_l_5a7e;
	case 23170ULL: goto x86_l_5a82;
	case 23175ULL: goto x86_l_5a87;
	case 23180ULL: goto x86_l_5a8c;
	case 23185ULL: goto x86_l_5a91;
	case 23190ULL: goto x86_l_5a96;
	case 23192ULL: goto x86_l_5a98;
	case 23196ULL: goto x86_l_5a9c;
	case 23198ULL: goto x86_l_5a9e;
	case 23204ULL: goto x86_l_5aa4;
	case 23207ULL: goto x86_l_5aa7;
	case 23209ULL: goto x86_l_5aa9;
	case 23215ULL: goto x86_l_5aaf;
	case 23220ULL: goto x86_l_5ab4;
	case 23226ULL: goto x86_l_5aba;
	case 23229ULL: goto x86_l_5abd;
	case 23231ULL: goto x86_l_5abf;
	case 23236ULL: goto x86_l_5ac4;
	case 23238ULL: goto x86_l_5ac6;
	case 23241ULL: goto x86_l_5ac9;
	case 23247ULL: goto x86_l_5acf;
	case 23251ULL: goto x86_l_5ad3;
	case 23257ULL: goto x86_l_5ad9;
	case 23261ULL: goto x86_l_5add;
	case 23264ULL: goto x86_l_5ae0;
	case 23269ULL: goto x86_l_5ae5;
	case 23274ULL: goto x86_l_5aea;
	case 23277ULL: goto x86_l_5aed;
	case 23283ULL: goto x86_l_5af3;
	case 23287ULL: goto x86_l_5af7;
	case 23292ULL: goto x86_l_5afc;
	case 23298ULL: goto x86_l_5b02;
	case 23302ULL: goto x86_l_5b06;
	case 23307ULL: goto x86_l_5b0b;
	case 23312ULL: goto x86_l_5b10;
	case 23317ULL: goto x86_l_5b15;
	case 23321ULL: goto x86_l_5b19;
	case 23325ULL: goto x86_l_5b1d;
	case 23330ULL: goto x86_l_5b22;
	case 23332ULL: goto x86_l_5b24;
	case 23336ULL: goto x86_l_5b28;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23349ULL: goto x86_l_5b35;
	case 23353ULL: goto x86_l_5b39;
	case 23358ULL: goto x86_l_5b3e;
	case 23360ULL: goto x86_l_5b40;
	case 23364ULL: goto x86_l_5b44;
	case 23369ULL: goto x86_l_5b49;
	case 23374ULL: goto x86_l_5b4e;
	case 23379ULL: goto x86_l_5b53;
	case 23383ULL: goto x86_l_5b57;
	case 23388ULL: goto x86_l_5b5c;
	case 23390ULL: goto x86_l_5b5e;
	case 23394ULL: goto x86_l_5b62;
	case 23398ULL: goto x86_l_5b66;
	case 23403ULL: goto x86_l_5b6b;
	case 23408ULL: goto x86_l_5b70;
	case 23413ULL: goto x86_l_5b75;
	case 23418ULL: goto x86_l_5b7a;
	case 23421ULL: goto x86_l_5b7d;
	case 23423ULL: goto x86_l_5b7f;
	case 23428ULL: goto x86_l_5b84;
	case 23433ULL: goto x86_l_5b89;
	case 23437ULL: goto x86_l_5b8d;
	case 23442ULL: goto x86_l_5b92;
	case 23447ULL: goto x86_l_5b97;
	case 23452ULL: goto x86_l_5b9c;
	case 23457ULL: goto x86_l_5ba1;
	case 23459ULL: goto x86_l_5ba3;
	case 23464ULL: goto x86_l_5ba8;
	case 23467ULL: goto x86_l_5bab;
	case 23473ULL: goto x86_l_5bb1;
	case 23478ULL: goto x86_l_5bb6;
	case 23481ULL: goto x86_l_5bb9;
	case 23487ULL: goto x86_l_5bbf;
	case 23491ULL: goto x86_l_5bc3;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23506ULL: goto x86_l_5bd2;
	case 23511ULL: goto x86_l_5bd7;
	case 23513ULL: goto x86_l_5bd9;
	case 23517ULL: goto x86_l_5bdd;
	case 23519ULL: goto x86_l_5bdf;
	case 23525ULL: goto x86_l_5be5;
	case 23528ULL: goto x86_l_5be8;
	case 23530ULL: goto x86_l_5bea;
	case 23536ULL: goto x86_l_5bf0;
	case 23541ULL: goto x86_l_5bf5;
	case 23547ULL: goto x86_l_5bfb;
	case 23550ULL: goto x86_l_5bfe;
	case 23552ULL: goto x86_l_5c00;
	case 23557ULL: goto x86_l_5c05;
	case 23559ULL: goto x86_l_5c07;
	case 23562ULL: goto x86_l_5c0a;
	case 23568ULL: goto x86_l_5c10;
	case 23572ULL: goto x86_l_5c14;
	case 23578ULL: goto x86_l_5c1a;
	case 23582ULL: goto x86_l_5c1e;
	case 23585ULL: goto x86_l_5c21;
	case 23590ULL: goto x86_l_5c26;
	case 23595ULL: goto x86_l_5c2b;
	case 23598ULL: goto x86_l_5c2e;
	case 23604ULL: goto x86_l_5c34;
	case 23608ULL: goto x86_l_5c38;
	case 23613ULL: goto x86_l_5c3d;
	case 23619ULL: goto x86_l_5c43;
	case 23623ULL: goto x86_l_5c47;
	case 23628ULL: goto x86_l_5c4c;
	case 23633ULL: goto x86_l_5c51;
	case 23638ULL: goto x86_l_5c56;
	case 23642ULL: goto x86_l_5c5a;
	case 23646ULL: goto x86_l_5c5e;
	case 23651ULL: goto x86_l_5c63;
	case 23653ULL: goto x86_l_5c65;
	case 23657ULL: goto x86_l_5c69;
	case 23660ULL: goto x86_l_5c6c;
	case 23665ULL: goto x86_l_5c71;
	case 23670ULL: goto x86_l_5c76;
	case 23674ULL: goto x86_l_5c7a;
	case 23679ULL: goto x86_l_5c7f;
	case 23681ULL: goto x86_l_5c81;
	case 23685ULL: goto x86_l_5c85;
	case 23690ULL: goto x86_l_5c8a;
	case 23695ULL: goto x86_l_5c8f;
	case 23700ULL: goto x86_l_5c94;
	case 23704ULL: goto x86_l_5c98;
	case 23709ULL: goto x86_l_5c9d;
	case 23711ULL: goto x86_l_5c9f;
	case 23715ULL: goto x86_l_5ca3;
	case 23719ULL: goto x86_l_5ca7;
	case 23724ULL: goto x86_l_5cac;
	case 23729ULL: goto x86_l_5cb1;
	case 23734ULL: goto x86_l_5cb6;
	case 23739ULL: goto x86_l_5cbb;
	case 23742ULL: goto x86_l_5cbe;
	case 23744ULL: goto x86_l_5cc0;
	case 23749ULL: goto x86_l_5cc5;
	case 23754ULL: goto x86_l_5cca;
	case 23758ULL: goto x86_l_5cce;
	case 23763ULL: goto x86_l_5cd3;
	case 23768ULL: goto x86_l_5cd8;
	case 23773ULL: goto x86_l_5cdd;
	case 23778ULL: goto x86_l_5ce2;
	case 23780ULL: goto x86_l_5ce4;
	case 23785ULL: goto x86_l_5ce9;
	case 23788ULL: goto x86_l_5cec;
	case 23794ULL: goto x86_l_5cf2;
	case 23799ULL: goto x86_l_5cf7;
	case 23802ULL: goto x86_l_5cfa;
	case 23808ULL: goto x86_l_5d00;
	case 23812ULL: goto x86_l_5d04;
	case 23817ULL: goto x86_l_5d09;
	case 23822ULL: goto x86_l_5d0e;
	case 23827ULL: goto x86_l_5d13;
	case 23832ULL: goto x86_l_5d18;
	case 23834ULL: goto x86_l_5d1a;
	case 23838ULL: goto x86_l_5d1e;
	case 23840ULL: goto x86_l_5d20;
	case 23846ULL: goto x86_l_5d26;
	case 23849ULL: goto x86_l_5d29;
	case 23851ULL: goto x86_l_5d2b;
	case 23857ULL: goto x86_l_5d31;
	case 23862ULL: goto x86_l_5d36;
	case 23868ULL: goto x86_l_5d3c;
	case 23871ULL: goto x86_l_5d3f;
	case 23873ULL: goto x86_l_5d41;
	case 23878ULL: goto x86_l_5d46;
	case 23880ULL: goto x86_l_5d48;
	case 23883ULL: goto x86_l_5d4b;
	case 23889ULL: goto x86_l_5d51;
	case 23893ULL: goto x86_l_5d55;
	case 23899ULL: goto x86_l_5d5b;
	case 23903ULL: goto x86_l_5d5f;
	case 23906ULL: goto x86_l_5d62;
	case 23911ULL: goto x86_l_5d67;
	case 23916ULL: goto x86_l_5d6c;
	case 23919ULL: goto x86_l_5d6f;
	case 23925ULL: goto x86_l_5d75;
	case 23929ULL: goto x86_l_5d79;
	case 23934ULL: goto x86_l_5d7e;
	case 23940ULL: goto x86_l_5d84;
	case 23944ULL: goto x86_l_5d88;
	case 23949ULL: goto x86_l_5d8d;
	case 23954ULL: goto x86_l_5d92;
	case 23959ULL: goto x86_l_5d97;
	case 23963ULL: goto x86_l_5d9b;
	case 23967ULL: goto x86_l_5d9f;
	case 23972ULL: goto x86_l_5da4;
	case 23974ULL: goto x86_l_5da6;
	case 23978ULL: goto x86_l_5daa;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23991ULL: goto x86_l_5db7;
	case 23995ULL: goto x86_l_5dbb;
	case 24000ULL: goto x86_l_5dc0;
	case 24002ULL: goto x86_l_5dc2;
	case 24006ULL: goto x86_l_5dc6;
	case 24011ULL: goto x86_l_5dcb;
	case 24016ULL: goto x86_l_5dd0;
	case 24021ULL: goto x86_l_5dd5;
	case 24025ULL: goto x86_l_5dd9;
	case 24030ULL: goto x86_l_5dde;
	case 24032ULL: goto x86_l_5de0;
	case 24036ULL: goto x86_l_5de4;
	case 24040ULL: goto x86_l_5de8;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24060ULL: goto x86_l_5dfc;
	case 24063ULL: goto x86_l_5dff;
	case 24065ULL: goto x86_l_5e01;
	case 24070ULL: goto x86_l_5e06;
	case 24075ULL: goto x86_l_5e0b;
	case 24079ULL: goto x86_l_5e0f;
	case 24084ULL: goto x86_l_5e14;
	case 24089ULL: goto x86_l_5e19;
	case 24094ULL: goto x86_l_5e1e;
	case 24099ULL: goto x86_l_5e23;
	case 24101ULL: goto x86_l_5e25;
	case 24106ULL: goto x86_l_5e2a;
	case 24109ULL: goto x86_l_5e2d;
	case 24115ULL: goto x86_l_5e33;
	case 24120ULL: goto x86_l_5e38;
	case 24123ULL: goto x86_l_5e3b;
	case 24129ULL: goto x86_l_5e41;
	case 24133ULL: goto x86_l_5e45;
	case 24138ULL: goto x86_l_5e4a;
	case 24143ULL: goto x86_l_5e4f;
	case 24148ULL: goto x86_l_5e54;
	case 24153ULL: goto x86_l_5e59;
	case 24155ULL: goto x86_l_5e5b;
	case 24159ULL: goto x86_l_5e5f;
	case 24161ULL: goto x86_l_5e61;
	case 24167ULL: goto x86_l_5e67;
	case 24170ULL: goto x86_l_5e6a;
	case 24172ULL: goto x86_l_5e6c;
	case 24178ULL: goto x86_l_5e72;
	case 24183ULL: goto x86_l_5e77;
	case 24189ULL: goto x86_l_5e7d;
	case 24192ULL: goto x86_l_5e80;
	case 24194ULL: goto x86_l_5e82;
	case 24199ULL: goto x86_l_5e87;
	case 24201ULL: goto x86_l_5e89;
	case 24204ULL: goto x86_l_5e8c;
	case 24210ULL: goto x86_l_5e92;
	case 24214ULL: goto x86_l_5e96;
	case 24220ULL: goto x86_l_5e9c;
	case 24224ULL: goto x86_l_5ea0;
	case 24227ULL: goto x86_l_5ea3;
	case 24232ULL: goto x86_l_5ea8;
	case 24237ULL: goto x86_l_5ead;
	case 24240ULL: goto x86_l_5eb0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5847:
	/* 0x5847: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_584d:
	/* 0x584d: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5851:
	/* 0x5851: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5857:
	/* 0x5857: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_585b:
	/* 0x585b: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_585e:
	/* 0x585e: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5863:
	/* 0x5863: jmp    5a25 <trace_security_file_mprotect+0x5a25> */
	goto x86_l_5a25;
x86_l_5868:
	/* 0x5868: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_586b:
	/* 0x586b: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_5871:
	/* 0x5871: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5875:
	/* 0x5875: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_587a:
	/* 0x587a: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_5880:
	/* 0x5880: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5884:
	/* 0x5884: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5889:
	/* 0x5889: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_588e:
	/* 0x588e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5893:
	/* 0x5893: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5897:
	/* 0x5897: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_589b:
	/* 0x589b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a0:
	/* 0x58a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a2:
	/* 0x58a2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58a6:
	/* 0x58a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58a9:
	/* 0x58a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58ae:
	/* 0x58ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58b3:
	/* 0x58b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58b7:
	/* 0x58b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58bc:
	/* 0x58bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58be:
	/* 0x58be: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c2:
	/* 0x58c2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58c7:
	/* 0x58c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58cc:
	/* 0x58cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58d1:
	/* 0x58d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58d5:
	/* 0x58d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58da:
	/* 0x58da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58dc:
	/* 0x58dc: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58e0:
	/* 0x58e0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_58e4:
	/* 0x58e4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58e9:
	/* 0x58e9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_58ee:
	/* 0x58ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58f3:
	/* 0x58f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58f8:
	/* 0x58f8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_58fb:
	/* 0x58fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58fd:
	/* 0x58fd: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5902:
	/* 0x5902: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5907:
	/* 0x5907: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_590b:
	/* 0x590b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5910:
	/* 0x5910: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5915:
	/* 0x5915: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_591a:
	/* 0x591a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_591f:
	/* 0x591f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5921:
	/* 0x5921: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5926:
	/* 0x5926: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5929:
	/* 0x5929: je     5aea <trace_security_file_mprotect+0x5aea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5aea;
	}
x86_l_592f:
	/* 0x592f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5934:
	/* 0x5934: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5937:
	/* 0x5937: je     5aea <trace_security_file_mprotect+0x5aea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5aea;
	}
x86_l_593d:
	/* 0x593d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5941:
	/* 0x5941: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5946:
	/* 0x5946: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_594b:
	/* 0x594b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5950:
	/* 0x5950: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5955:
	/* 0x5955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5957:
	/* 0x5957: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_595b:
	/* 0x595b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_595d:
	/* 0x595d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5963:
	/* 0x5963: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5966:
	/* 0x5966: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5968:
	/* 0x5968: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_596e:
	/* 0x596e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5973:
	/* 0x5973: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5979:
	/* 0x5979: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_597c:
	/* 0x597c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_597e:
	/* 0x597e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5983:
	/* 0x5983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5985:
	/* 0x5985: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5988:
	/* 0x5988: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_598e:
	/* 0x598e: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5992:
	/* 0x5992: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5998:
	/* 0x5998: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_599c:
	/* 0x599c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_599f:
	/* 0x599f: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a4:
	/* 0x59a4: jmp    5b66 <trace_security_file_mprotect+0x5b66> */
	goto x86_l_5b66;
x86_l_59a9:
	/* 0x59a9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_59ac:
	/* 0x59ac: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_59b2:
	/* 0x59b2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59b6:
	/* 0x59b6: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_59bb:
	/* 0x59bb: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_59c1:
	/* 0x59c1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59c5:
	/* 0x59c5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59ca:
	/* 0x59ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59cf:
	/* 0x59cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59d4:
	/* 0x59d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59d8:
	/* 0x59d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59dc:
	/* 0x59dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59e1:
	/* 0x59e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e3:
	/* 0x59e3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e7:
	/* 0x59e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59ea:
	/* 0x59ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59ef:
	/* 0x59ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59f4:
	/* 0x59f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59f8:
	/* 0x59f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59fd:
	/* 0x59fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ff:
	/* 0x59ff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a03:
	/* 0x5a03: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a08:
	/* 0x5a08: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a0d:
	/* 0x5a0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a12:
	/* 0x5a12: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a16:
	/* 0x5a16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a1b:
	/* 0x5a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a1d:
	/* 0x5a1d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a21:
	/* 0x5a21: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a25:
	/* 0x5a25: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a2a:
	/* 0x5a2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a2f:
	/* 0x5a2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a34:
	/* 0x5a34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a39:
	/* 0x5a39: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5a3c:
	/* 0x5a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a3e:
	/* 0x5a3e: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a43:
	/* 0x5a43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a48:
	/* 0x5a48: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a4c:
	/* 0x5a4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a51:
	/* 0x5a51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a56:
	/* 0x5a56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a5b:
	/* 0x5a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a60:
	/* 0x5a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a62:
	/* 0x5a62: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a67:
	/* 0x5a67: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5a6a:
	/* 0x5a6a: je     5c2b <trace_security_file_mprotect+0x5c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c2b;
	}
x86_l_5a70:
	/* 0x5a70: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a75:
	/* 0x5a75: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5a78:
	/* 0x5a78: je     5c2b <trace_security_file_mprotect+0x5c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c2b;
	}
x86_l_5a7e:
	/* 0x5a7e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a82:
	/* 0x5a82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a87:
	/* 0x5a87: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5a8c:
	/* 0x5a8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a91:
	/* 0x5a91: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5a96:
	/* 0x5a96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a98:
	/* 0x5a98: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a9c:
	/* 0x5a9c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5a9e:
	/* 0x5a9e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5aa4:
	/* 0x5aa4: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5aa7:
	/* 0x5aa7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5aa9:
	/* 0x5aa9: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_5aaf:
	/* 0x5aaf: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ab4:
	/* 0x5ab4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5aba:
	/* 0x5aba: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5abd:
	/* 0x5abd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5abf:
	/* 0x5abf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5ac4:
	/* 0x5ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac6:
	/* 0x5ac6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ac9:
	/* 0x5ac9: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_5acf:
	/* 0x5acf: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ad3:
	/* 0x5ad3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ad9:
	/* 0x5ad9: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5add:
	/* 0x5add: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ae0:
	/* 0x5ae0: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae5:
	/* 0x5ae5: jmp    5ca7 <trace_security_file_mprotect+0x5ca7> */
	goto x86_l_5ca7;
x86_l_5aea:
	/* 0x5aea: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5aed:
	/* 0x5aed: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_5af3:
	/* 0x5af3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af7:
	/* 0x5af7: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5afc:
	/* 0x5afc: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_5b02:
	/* 0x5b02: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b06:
	/* 0x5b06: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b0b:
	/* 0x5b0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b10:
	/* 0x5b10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b15:
	/* 0x5b15: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b19:
	/* 0x5b19: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b1d:
	/* 0x5b1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b22:
	/* 0x5b22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b24:
	/* 0x5b24: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b28:
	/* 0x5b28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5b2b:
	/* 0x5b2b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b30:
	/* 0x5b30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b35:
	/* 0x5b35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b39:
	/* 0x5b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b3e:
	/* 0x5b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b40:
	/* 0x5b40: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b44:
	/* 0x5b44: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b49:
	/* 0x5b49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b4e:
	/* 0x5b4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b53:
	/* 0x5b53: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b57:
	/* 0x5b57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b5c:
	/* 0x5b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5e:
	/* 0x5b5e: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b62:
	/* 0x5b62: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b66:
	/* 0x5b66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b6b:
	/* 0x5b6b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b70:
	/* 0x5b70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b75:
	/* 0x5b75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b7a:
	/* 0x5b7a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5b7d:
	/* 0x5b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b7f:
	/* 0x5b7f: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b84:
	/* 0x5b84: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b89:
	/* 0x5b89: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b8d:
	/* 0x5b8d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b92:
	/* 0x5b92: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b97:
	/* 0x5b97: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b9c:
	/* 0x5b9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ba1:
	/* 0x5ba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ba3:
	/* 0x5ba3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ba8:
	/* 0x5ba8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5bab:
	/* 0x5bab: je     5d6c <trace_security_file_mprotect+0x5d6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d6c;
	}
x86_l_5bb1:
	/* 0x5bb1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bb6:
	/* 0x5bb6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5bb9:
	/* 0x5bb9: je     5d6c <trace_security_file_mprotect+0x5d6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d6c;
	}
x86_l_5bbf:
	/* 0x5bbf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5bc3:
	/* 0x5bc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bc8:
	/* 0x5bc8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5bcd:
	/* 0x5bcd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bd2:
	/* 0x5bd2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5bd7:
	/* 0x5bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bd9:
	/* 0x5bd9: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5bdd:
	/* 0x5bdd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5bdf:
	/* 0x5bdf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5be5:
	/* 0x5be5: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5be8:
	/* 0x5be8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5bea:
	/* 0x5bea: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_5bf0:
	/* 0x5bf0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bf5:
	/* 0x5bf5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5bfb:
	/* 0x5bfb: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5bfe:
	/* 0x5bfe: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5c00:
	/* 0x5c00: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5c05:
	/* 0x5c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c07:
	/* 0x5c07: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c0a:
	/* 0x5c0a: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_5c10:
	/* 0x5c10: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5c14:
	/* 0x5c14: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5c1a:
	/* 0x5c1a: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5c1e:
	/* 0x5c1e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c21:
	/* 0x5c21: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c26:
	/* 0x5c26: jmp    5de8 <trace_security_file_mprotect+0x5de8> */
	goto x86_l_5de8;
x86_l_5c2b:
	/* 0x5c2b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5c2e:
	/* 0x5c2e: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_5c34:
	/* 0x5c34: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c38:
	/* 0x5c38: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5c3d:
	/* 0x5c3d: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_5c43:
	/* 0x5c43: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c47:
	/* 0x5c47: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4c:
	/* 0x5c4c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c51:
	/* 0x5c51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c56:
	/* 0x5c56: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c5a:
	/* 0x5c5a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c5e:
	/* 0x5c5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c63:
	/* 0x5c63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c65:
	/* 0x5c65: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c69:
	/* 0x5c69: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5c6c:
	/* 0x5c6c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c71:
	/* 0x5c71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c76:
	/* 0x5c76: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c7a:
	/* 0x5c7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c7f:
	/* 0x5c7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c81:
	/* 0x5c81: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c85:
	/* 0x5c85: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c8a:
	/* 0x5c8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c8f:
	/* 0x5c8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c94:
	/* 0x5c94: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c98:
	/* 0x5c98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c9d:
	/* 0x5c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c9f:
	/* 0x5c9f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ca3:
	/* 0x5ca3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ca7:
	/* 0x5ca7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cac:
	/* 0x5cac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cb1:
	/* 0x5cb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cb6:
	/* 0x5cb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cbb:
	/* 0x5cbb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5cbe:
	/* 0x5cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc0:
	/* 0x5cc0: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cc5:
	/* 0x5cc5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cca:
	/* 0x5cca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5cce:
	/* 0x5cce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cd3:
	/* 0x5cd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cd8:
	/* 0x5cd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cdd:
	/* 0x5cdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ce2:
	/* 0x5ce2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ce4:
	/* 0x5ce4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce9:
	/* 0x5ce9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5cec:
	/* 0x5cec: je     5ead <trace_security_file_mprotect+0x5ead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ead;
	}
x86_l_5cf2:
	/* 0x5cf2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cf7:
	/* 0x5cf7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5cfa:
	/* 0x5cfa: je     5ead <trace_security_file_mprotect+0x5ead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ead;
	}
x86_l_5d00:
	/* 0x5d00: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d04:
	/* 0x5d04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d09:
	/* 0x5d09: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5d0e:
	/* 0x5d0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d13:
	/* 0x5d13: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5d18:
	/* 0x5d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1a:
	/* 0x5d1a: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5d1e:
	/* 0x5d1e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5d20:
	/* 0x5d20: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d26:
	/* 0x5d26: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5d29:
	/* 0x5d29: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d2b:
	/* 0x5d2b: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_5d31:
	/* 0x5d31: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d36:
	/* 0x5d36: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5d3c:
	/* 0x5d3c: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5d3f:
	/* 0x5d3f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5d41:
	/* 0x5d41: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5d46:
	/* 0x5d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d48:
	/* 0x5d48: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5d4b:
	/* 0x5d4b: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_5d51:
	/* 0x5d51: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5d55:
	/* 0x5d55: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5d5b:
	/* 0x5d5b: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5d5f:
	/* 0x5d5f: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d62:
	/* 0x5d62: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d67:
	/* 0x5d67: jmp    5f29 <trace_security_file_mprotect+0x5f29> */
	return 24361ULL;
x86_l_5d6c:
	/* 0x5d6c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5d6f:
	/* 0x5d6f: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_5d75:
	/* 0x5d75: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d79:
	/* 0x5d79: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5d7e:
	/* 0x5d7e: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_5d84:
	/* 0x5d84: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d88:
	/* 0x5d88: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8d:
	/* 0x5d8d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d92:
	/* 0x5d92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d97:
	/* 0x5d97: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d9b:
	/* 0x5d9b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d9f:
	/* 0x5d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5da4:
	/* 0x5da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5da6:
	/* 0x5da6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5daa:
	/* 0x5daa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5dad:
	/* 0x5dad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5db2:
	/* 0x5db2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5db7:
	/* 0x5db7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dbb:
	/* 0x5dbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dc0:
	/* 0x5dc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dc2:
	/* 0x5dc2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dc6:
	/* 0x5dc6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dcb:
	/* 0x5dcb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dd0:
	/* 0x5dd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dd5:
	/* 0x5dd5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dd9:
	/* 0x5dd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dde:
	/* 0x5dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de0:
	/* 0x5de0: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5de4:
	/* 0x5de4: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5de8:
	/* 0x5de8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ded:
	/* 0x5ded: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5df2:
	/* 0x5df2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5df7:
	/* 0x5df7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dfc:
	/* 0x5dfc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5dff:
	/* 0x5dff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e01:
	/* 0x5e01: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e06:
	/* 0x5e06: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e0b:
	/* 0x5e0b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e0f:
	/* 0x5e0f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e14:
	/* 0x5e14: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e19:
	/* 0x5e19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e1e:
	/* 0x5e1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e23:
	/* 0x5e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e25:
	/* 0x5e25: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e2a:
	/* 0x5e2a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5e2d:
	/* 0x5e2d: je     5fee <trace_security_file_mprotect+0x5fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24558ULL;
	}
x86_l_5e33:
	/* 0x5e33: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e38:
	/* 0x5e38: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5e3b:
	/* 0x5e3b: je     5fee <trace_security_file_mprotect+0x5fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24558ULL;
	}
x86_l_5e41:
	/* 0x5e41: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e45:
	/* 0x5e45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e4a:
	/* 0x5e4a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5e4f:
	/* 0x5e4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e54:
	/* 0x5e54: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5e59:
	/* 0x5e59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e5b:
	/* 0x5e5b: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5e5f:
	/* 0x5e5f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5e61:
	/* 0x5e61: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e67:
	/* 0x5e67: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5e6a:
	/* 0x5e6a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e6c:
	/* 0x5e6c: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_5e72:
	/* 0x5e72: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e77:
	/* 0x5e77: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5e7d:
	/* 0x5e7d: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e80:
	/* 0x5e80: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5e82:
	/* 0x5e82: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5e87:
	/* 0x5e87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e89:
	/* 0x5e89: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e8c:
	/* 0x5e8c: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_5e92:
	/* 0x5e92: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5e96:
	/* 0x5e96: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5e9c:
	/* 0x5e9c: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ea0:
	/* 0x5ea0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ea3:
	/* 0x5ea3: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ea8:
	/* 0x5ea8: jmp    606a <trace_security_file_mprotect+0x606a> */
	return 24682ULL;
x86_l_5ead:
	/* 0x5ead: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5eb0:
	/* 0x5eb0: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
	return 24246ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24246ULL: goto x86_l_5eb6;
	case 24250ULL: goto x86_l_5eba;
	case 24255ULL: goto x86_l_5ebf;
	case 24261ULL: goto x86_l_5ec5;
	case 24265ULL: goto x86_l_5ec9;
	case 24270ULL: goto x86_l_5ece;
	case 24275ULL: goto x86_l_5ed3;
	case 24280ULL: goto x86_l_5ed8;
	case 24284ULL: goto x86_l_5edc;
	case 24288ULL: goto x86_l_5ee0;
	case 24293ULL: goto x86_l_5ee5;
	case 24295ULL: goto x86_l_5ee7;
	case 24299ULL: goto x86_l_5eeb;
	case 24302ULL: goto x86_l_5eee;
	case 24307ULL: goto x86_l_5ef3;
	case 24312ULL: goto x86_l_5ef8;
	case 24316ULL: goto x86_l_5efc;
	case 24321ULL: goto x86_l_5f01;
	case 24323ULL: goto x86_l_5f03;
	case 24327ULL: goto x86_l_5f07;
	case 24332ULL: goto x86_l_5f0c;
	case 24337ULL: goto x86_l_5f11;
	case 24342ULL: goto x86_l_5f16;
	case 24346ULL: goto x86_l_5f1a;
	case 24351ULL: goto x86_l_5f1f;
	case 24353ULL: goto x86_l_5f21;
	case 24357ULL: goto x86_l_5f25;
	case 24361ULL: goto x86_l_5f29;
	case 24366ULL: goto x86_l_5f2e;
	case 24371ULL: goto x86_l_5f33;
	case 24376ULL: goto x86_l_5f38;
	case 24381ULL: goto x86_l_5f3d;
	case 24384ULL: goto x86_l_5f40;
	case 24386ULL: goto x86_l_5f42;
	case 24391ULL: goto x86_l_5f47;
	case 24396ULL: goto x86_l_5f4c;
	case 24400ULL: goto x86_l_5f50;
	case 24405ULL: goto x86_l_5f55;
	case 24410ULL: goto x86_l_5f5a;
	case 24415ULL: goto x86_l_5f5f;
	case 24420ULL: goto x86_l_5f64;
	case 24422ULL: goto x86_l_5f66;
	case 24427ULL: goto x86_l_5f6b;
	case 24430ULL: goto x86_l_5f6e;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24444ULL: goto x86_l_5f7c;
	case 24450ULL: goto x86_l_5f82;
	case 24454ULL: goto x86_l_5f86;
	case 24459ULL: goto x86_l_5f8b;
	case 24464ULL: goto x86_l_5f90;
	case 24469ULL: goto x86_l_5f95;
	case 24474ULL: goto x86_l_5f9a;
	case 24476ULL: goto x86_l_5f9c;
	case 24480ULL: goto x86_l_5fa0;
	case 24482ULL: goto x86_l_5fa2;
	case 24488ULL: goto x86_l_5fa8;
	case 24491ULL: goto x86_l_5fab;
	case 24493ULL: goto x86_l_5fad;
	case 24499ULL: goto x86_l_5fb3;
	case 24504ULL: goto x86_l_5fb8;
	case 24510ULL: goto x86_l_5fbe;
	case 24513ULL: goto x86_l_5fc1;
	case 24515ULL: goto x86_l_5fc3;
	case 24520ULL: goto x86_l_5fc8;
	case 24522ULL: goto x86_l_5fca;
	case 24525ULL: goto x86_l_5fcd;
	case 24531ULL: goto x86_l_5fd3;
	case 24535ULL: goto x86_l_5fd7;
	case 24541ULL: goto x86_l_5fdd;
	case 24545ULL: goto x86_l_5fe1;
	case 24548ULL: goto x86_l_5fe4;
	case 24553ULL: goto x86_l_5fe9;
	case 24558ULL: goto x86_l_5fee;
	case 24561ULL: goto x86_l_5ff1;
	case 24567ULL: goto x86_l_5ff7;
	case 24571ULL: goto x86_l_5ffb;
	case 24576ULL: goto x86_l_6000;
	case 24582ULL: goto x86_l_6006;
	case 24586ULL: goto x86_l_600a;
	case 24591ULL: goto x86_l_600f;
	case 24596ULL: goto x86_l_6014;
	case 24601ULL: goto x86_l_6019;
	case 24605ULL: goto x86_l_601d;
	case 24609ULL: goto x86_l_6021;
	case 24614ULL: goto x86_l_6026;
	case 24616ULL: goto x86_l_6028;
	case 24620ULL: goto x86_l_602c;
	case 24623ULL: goto x86_l_602f;
	case 24628ULL: goto x86_l_6034;
	case 24633ULL: goto x86_l_6039;
	case 24637ULL: goto x86_l_603d;
	case 24642ULL: goto x86_l_6042;
	case 24644ULL: goto x86_l_6044;
	case 24648ULL: goto x86_l_6048;
	case 24653ULL: goto x86_l_604d;
	case 24658ULL: goto x86_l_6052;
	case 24663ULL: goto x86_l_6057;
	case 24667ULL: goto x86_l_605b;
	case 24672ULL: goto x86_l_6060;
	case 24674ULL: goto x86_l_6062;
	case 24678ULL: goto x86_l_6066;
	case 24682ULL: goto x86_l_606a;
	case 24687ULL: goto x86_l_606f;
	case 24692ULL: goto x86_l_6074;
	case 24697ULL: goto x86_l_6079;
	case 24702ULL: goto x86_l_607e;
	case 24705ULL: goto x86_l_6081;
	case 24707ULL: goto x86_l_6083;
	case 24712ULL: goto x86_l_6088;
	case 24717ULL: goto x86_l_608d;
	case 24721ULL: goto x86_l_6091;
	case 24726ULL: goto x86_l_6096;
	case 24731ULL: goto x86_l_609b;
	case 24736ULL: goto x86_l_60a0;
	case 24741ULL: goto x86_l_60a5;
	case 24743ULL: goto x86_l_60a7;
	case 24748ULL: goto x86_l_60ac;
	case 24751ULL: goto x86_l_60af;
	case 24757ULL: goto x86_l_60b5;
	case 24762ULL: goto x86_l_60ba;
	case 24765ULL: goto x86_l_60bd;
	case 24771ULL: goto x86_l_60c3;
	case 24775ULL: goto x86_l_60c7;
	case 24780ULL: goto x86_l_60cc;
	case 24785ULL: goto x86_l_60d1;
	case 24790ULL: goto x86_l_60d6;
	case 24795ULL: goto x86_l_60db;
	case 24797ULL: goto x86_l_60dd;
	case 24801ULL: goto x86_l_60e1;
	case 24803ULL: goto x86_l_60e3;
	case 24809ULL: goto x86_l_60e9;
	case 24812ULL: goto x86_l_60ec;
	case 24814ULL: goto x86_l_60ee;
	case 24820ULL: goto x86_l_60f4;
	case 24825ULL: goto x86_l_60f9;
	case 24831ULL: goto x86_l_60ff;
	case 24834ULL: goto x86_l_6102;
	case 24836ULL: goto x86_l_6104;
	case 24841ULL: goto x86_l_6109;
	case 24843ULL: goto x86_l_610b;
	case 24846ULL: goto x86_l_610e;
	case 24852ULL: goto x86_l_6114;
	case 24856ULL: goto x86_l_6118;
	case 24862ULL: goto x86_l_611e;
	case 24866ULL: goto x86_l_6122;
	case 24869ULL: goto x86_l_6125;
	case 24874ULL: goto x86_l_612a;
	case 24879ULL: goto x86_l_612f;
	case 24882ULL: goto x86_l_6132;
	case 24888ULL: goto x86_l_6138;
	case 24892ULL: goto x86_l_613c;
	case 24897ULL: goto x86_l_6141;
	case 24903ULL: goto x86_l_6147;
	case 24907ULL: goto x86_l_614b;
	case 24912ULL: goto x86_l_6150;
	case 24917ULL: goto x86_l_6155;
	case 24922ULL: goto x86_l_615a;
	case 24926ULL: goto x86_l_615e;
	case 24930ULL: goto x86_l_6162;
	case 24935ULL: goto x86_l_6167;
	case 24937ULL: goto x86_l_6169;
	case 24941ULL: goto x86_l_616d;
	case 24944ULL: goto x86_l_6170;
	case 24949ULL: goto x86_l_6175;
	case 24954ULL: goto x86_l_617a;
	case 24958ULL: goto x86_l_617e;
	case 24963ULL: goto x86_l_6183;
	case 24965ULL: goto x86_l_6185;
	case 24969ULL: goto x86_l_6189;
	case 24974ULL: goto x86_l_618e;
	case 24979ULL: goto x86_l_6193;
	case 24984ULL: goto x86_l_6198;
	case 24988ULL: goto x86_l_619c;
	case 24993ULL: goto x86_l_61a1;
	case 24995ULL: goto x86_l_61a3;
	case 24999ULL: goto x86_l_61a7;
	case 25003ULL: goto x86_l_61ab;
	case 25008ULL: goto x86_l_61b0;
	case 25013ULL: goto x86_l_61b5;
	case 25018ULL: goto x86_l_61ba;
	case 25023ULL: goto x86_l_61bf;
	case 25026ULL: goto x86_l_61c2;
	case 25028ULL: goto x86_l_61c4;
	case 25033ULL: goto x86_l_61c9;
	case 25038ULL: goto x86_l_61ce;
	case 25042ULL: goto x86_l_61d2;
	case 25047ULL: goto x86_l_61d7;
	case 25052ULL: goto x86_l_61dc;
	case 25057ULL: goto x86_l_61e1;
	case 25062ULL: goto x86_l_61e6;
	case 25064ULL: goto x86_l_61e8;
	case 25069ULL: goto x86_l_61ed;
	case 25072ULL: goto x86_l_61f0;
	case 25078ULL: goto x86_l_61f6;
	case 25083ULL: goto x86_l_61fb;
	case 25086ULL: goto x86_l_61fe;
	case 25092ULL: goto x86_l_6204;
	case 25096ULL: goto x86_l_6208;
	case 25101ULL: goto x86_l_620d;
	case 25106ULL: goto x86_l_6212;
	case 25111ULL: goto x86_l_6217;
	case 25116ULL: goto x86_l_621c;
	case 25118ULL: goto x86_l_621e;
	case 25122ULL: goto x86_l_6222;
	case 25124ULL: goto x86_l_6224;
	case 25130ULL: goto x86_l_622a;
	case 25133ULL: goto x86_l_622d;
	case 25135ULL: goto x86_l_622f;
	case 25141ULL: goto x86_l_6235;
	case 25146ULL: goto x86_l_623a;
	case 25152ULL: goto x86_l_6240;
	case 25155ULL: goto x86_l_6243;
	case 25157ULL: goto x86_l_6245;
	case 25162ULL: goto x86_l_624a;
	case 25164ULL: goto x86_l_624c;
	case 25167ULL: goto x86_l_624f;
	case 25173ULL: goto x86_l_6255;
	case 25177ULL: goto x86_l_6259;
	case 25183ULL: goto x86_l_625f;
	case 25187ULL: goto x86_l_6263;
	case 25190ULL: goto x86_l_6266;
	case 25195ULL: goto x86_l_626b;
	case 25200ULL: goto x86_l_6270;
	case 25203ULL: goto x86_l_6273;
	case 25209ULL: goto x86_l_6279;
	case 25213ULL: goto x86_l_627d;
	case 25218ULL: goto x86_l_6282;
	case 25224ULL: goto x86_l_6288;
	case 25228ULL: goto x86_l_628c;
	case 25233ULL: goto x86_l_6291;
	case 25238ULL: goto x86_l_6296;
	case 25243ULL: goto x86_l_629b;
	case 25247ULL: goto x86_l_629f;
	case 25251ULL: goto x86_l_62a3;
	case 25256ULL: goto x86_l_62a8;
	case 25258ULL: goto x86_l_62aa;
	case 25262ULL: goto x86_l_62ae;
	case 25265ULL: goto x86_l_62b1;
	case 25270ULL: goto x86_l_62b6;
	case 25275ULL: goto x86_l_62bb;
	case 25279ULL: goto x86_l_62bf;
	case 25284ULL: goto x86_l_62c4;
	case 25286ULL: goto x86_l_62c6;
	case 25290ULL: goto x86_l_62ca;
	case 25295ULL: goto x86_l_62cf;
	case 25300ULL: goto x86_l_62d4;
	case 25305ULL: goto x86_l_62d9;
	case 25309ULL: goto x86_l_62dd;
	case 25314ULL: goto x86_l_62e2;
	case 25316ULL: goto x86_l_62e4;
	case 25320ULL: goto x86_l_62e8;
	case 25324ULL: goto x86_l_62ec;
	case 25329ULL: goto x86_l_62f1;
	case 25334ULL: goto x86_l_62f6;
	case 25339ULL: goto x86_l_62fb;
	case 25344ULL: goto x86_l_6300;
	case 25347ULL: goto x86_l_6303;
	case 25349ULL: goto x86_l_6305;
	case 25354ULL: goto x86_l_630a;
	case 25359ULL: goto x86_l_630f;
	case 25363ULL: goto x86_l_6313;
	case 25368ULL: goto x86_l_6318;
	case 25373ULL: goto x86_l_631d;
	case 25378ULL: goto x86_l_6322;
	case 25383ULL: goto x86_l_6327;
	case 25385ULL: goto x86_l_6329;
	case 25390ULL: goto x86_l_632e;
	case 25393ULL: goto x86_l_6331;
	case 25399ULL: goto x86_l_6337;
	case 25404ULL: goto x86_l_633c;
	case 25407ULL: goto x86_l_633f;
	case 25413ULL: goto x86_l_6345;
	case 25417ULL: goto x86_l_6349;
	case 25422ULL: goto x86_l_634e;
	case 25427ULL: goto x86_l_6353;
	case 25432ULL: goto x86_l_6358;
	case 25437ULL: goto x86_l_635d;
	case 25439ULL: goto x86_l_635f;
	case 25443ULL: goto x86_l_6363;
	case 25445ULL: goto x86_l_6365;
	case 25451ULL: goto x86_l_636b;
	case 25454ULL: goto x86_l_636e;
	case 25456ULL: goto x86_l_6370;
	case 25462ULL: goto x86_l_6376;
	case 25467ULL: goto x86_l_637b;
	case 25473ULL: goto x86_l_6381;
	case 25476ULL: goto x86_l_6384;
	case 25478ULL: goto x86_l_6386;
	case 25483ULL: goto x86_l_638b;
	case 25485ULL: goto x86_l_638d;
	case 25488ULL: goto x86_l_6390;
	case 25494ULL: goto x86_l_6396;
	case 25498ULL: goto x86_l_639a;
	case 25504ULL: goto x86_l_63a0;
	case 25508ULL: goto x86_l_63a4;
	case 25511ULL: goto x86_l_63a7;
	case 25516ULL: goto x86_l_63ac;
	case 25521ULL: goto x86_l_63b1;
	case 25524ULL: goto x86_l_63b4;
	case 25530ULL: goto x86_l_63ba;
	case 25534ULL: goto x86_l_63be;
	case 25539ULL: goto x86_l_63c3;
	case 25545ULL: goto x86_l_63c9;
	case 25549ULL: goto x86_l_63cd;
	case 25554ULL: goto x86_l_63d2;
	case 25559ULL: goto x86_l_63d7;
	case 25564ULL: goto x86_l_63dc;
	case 25568ULL: goto x86_l_63e0;
	case 25572ULL: goto x86_l_63e4;
	case 25577ULL: goto x86_l_63e9;
	case 25579ULL: goto x86_l_63eb;
	case 25583ULL: goto x86_l_63ef;
	case 25586ULL: goto x86_l_63f2;
	case 25591ULL: goto x86_l_63f7;
	case 25596ULL: goto x86_l_63fc;
	case 25600ULL: goto x86_l_6400;
	case 25605ULL: goto x86_l_6405;
	case 25607ULL: goto x86_l_6407;
	case 25611ULL: goto x86_l_640b;
	case 25616ULL: goto x86_l_6410;
	case 25621ULL: goto x86_l_6415;
	case 25626ULL: goto x86_l_641a;
	case 25630ULL: goto x86_l_641e;
	case 25635ULL: goto x86_l_6423;
	case 25637ULL: goto x86_l_6425;
	case 25641ULL: goto x86_l_6429;
	case 25645ULL: goto x86_l_642d;
	case 25650ULL: goto x86_l_6432;
	case 25655ULL: goto x86_l_6437;
	case 25660ULL: goto x86_l_643c;
	case 25665ULL: goto x86_l_6441;
	case 25668ULL: goto x86_l_6444;
	case 25670ULL: goto x86_l_6446;
	case 25675ULL: goto x86_l_644b;
	case 25680ULL: goto x86_l_6450;
	case 25684ULL: goto x86_l_6454;
	case 25689ULL: goto x86_l_6459;
	case 25694ULL: goto x86_l_645e;
	case 25699ULL: goto x86_l_6463;
	case 25704ULL: goto x86_l_6468;
	case 25706ULL: goto x86_l_646a;
	case 25711ULL: goto x86_l_646f;
	case 25714ULL: goto x86_l_6472;
	case 25720ULL: goto x86_l_6478;
	case 25725ULL: goto x86_l_647d;
	case 25728ULL: goto x86_l_6480;
	case 25734ULL: goto x86_l_6486;
	case 25738ULL: goto x86_l_648a;
	case 25743ULL: goto x86_l_648f;
	case 25748ULL: goto x86_l_6494;
	case 25753ULL: goto x86_l_6499;
	case 25758ULL: goto x86_l_649e;
	case 25760ULL: goto x86_l_64a0;
	case 25764ULL: goto x86_l_64a4;
	case 25766ULL: goto x86_l_64a6;
	case 25772ULL: goto x86_l_64ac;
	case 25775ULL: goto x86_l_64af;
	case 25777ULL: goto x86_l_64b1;
	case 25783ULL: goto x86_l_64b7;
	case 25788ULL: goto x86_l_64bc;
	case 25794ULL: goto x86_l_64c2;
	case 25797ULL: goto x86_l_64c5;
	case 25799ULL: goto x86_l_64c7;
	case 25804ULL: goto x86_l_64cc;
	case 25806ULL: goto x86_l_64ce;
	case 25809ULL: goto x86_l_64d1;
	case 25815ULL: goto x86_l_64d7;
	case 25819ULL: goto x86_l_64db;
	case 25825ULL: goto x86_l_64e1;
	case 25829ULL: goto x86_l_64e5;
	case 25832ULL: goto x86_l_64e8;
	case 25837ULL: goto x86_l_64ed;
	case 25842ULL: goto x86_l_64f2;
	case 25845ULL: goto x86_l_64f5;
	case 25851ULL: goto x86_l_64fb;
	case 25855ULL: goto x86_l_64ff;
	case 25860ULL: goto x86_l_6504;
	case 25866ULL: goto x86_l_650a;
	case 25870ULL: goto x86_l_650e;
	case 25875ULL: goto x86_l_6513;
	case 25880ULL: goto x86_l_6518;
	case 25885ULL: goto x86_l_651d;
	case 25889ULL: goto x86_l_6521;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5eb6:
	/* 0x5eb6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eba:
	/* 0x5eba: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5ebf:
	/* 0x5ebf: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_5ec5:
	/* 0x5ec5: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ec9:
	/* 0x5ec9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ece:
	/* 0x5ece: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ed3:
	/* 0x5ed3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ed8:
	/* 0x5ed8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5edc:
	/* 0x5edc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ee0:
	/* 0x5ee0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ee5:
	/* 0x5ee5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee7:
	/* 0x5ee7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eeb:
	/* 0x5eeb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5eee:
	/* 0x5eee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ef3:
	/* 0x5ef3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ef8:
	/* 0x5ef8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5efc:
	/* 0x5efc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f01:
	/* 0x5f01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f03:
	/* 0x5f03: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f07:
	/* 0x5f07: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f0c:
	/* 0x5f0c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f11:
	/* 0x5f11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f16:
	/* 0x5f16: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f1a:
	/* 0x5f1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f1f:
	/* 0x5f1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f21:
	/* 0x5f21: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f25:
	/* 0x5f25: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f29:
	/* 0x5f29: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f2e:
	/* 0x5f2e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f33:
	/* 0x5f33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f38:
	/* 0x5f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f3d:
	/* 0x5f3d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5f40:
	/* 0x5f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f42:
	/* 0x5f42: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f47:
	/* 0x5f47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f4c:
	/* 0x5f4c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f50:
	/* 0x5f50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f55:
	/* 0x5f55: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f5a:
	/* 0x5f5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f5f:
	/* 0x5f5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f64:
	/* 0x5f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f66:
	/* 0x5f66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6b:
	/* 0x5f6b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5f6e:
	/* 0x5f6e: je     612f <trace_security_file_mprotect+0x612f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_612f;
	}
x86_l_5f74:
	/* 0x5f74: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f79:
	/* 0x5f79: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5f7c:
	/* 0x5f7c: je     612f <trace_security_file_mprotect+0x612f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_612f;
	}
x86_l_5f82:
	/* 0x5f82: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f86:
	/* 0x5f86: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f8b:
	/* 0x5f8b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5f90:
	/* 0x5f90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f95:
	/* 0x5f95: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5f9a:
	/* 0x5f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f9c:
	/* 0x5f9c: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5fa0:
	/* 0x5fa0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5fa2:
	/* 0x5fa2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5fa8:
	/* 0x5fa8: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5fab:
	/* 0x5fab: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fad:
	/* 0x5fad: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_5fb3:
	/* 0x5fb3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fb8:
	/* 0x5fb8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5fbe:
	/* 0x5fbe: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5fc1:
	/* 0x5fc1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5fc3:
	/* 0x5fc3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5fc8:
	/* 0x5fc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fca:
	/* 0x5fca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5fcd:
	/* 0x5fcd: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_5fd3:
	/* 0x5fd3: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5fd7:
	/* 0x5fd7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5fdd:
	/* 0x5fdd: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5fe1:
	/* 0x5fe1: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fe4:
	/* 0x5fe4: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fe9:
	/* 0x5fe9: jmp    61ab <trace_security_file_mprotect+0x61ab> */
	goto x86_l_61ab;
x86_l_5fee:
	/* 0x5fee: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5ff1:
	/* 0x5ff1: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_5ff7:
	/* 0x5ff7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ffb:
	/* 0x5ffb: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6000:
	/* 0x6000: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_6006:
	/* 0x6006: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_600a:
	/* 0x600a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_600f:
	/* 0x600f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6014:
	/* 0x6014: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6019:
	/* 0x6019: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_601d:
	/* 0x601d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6021:
	/* 0x6021: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6026:
	/* 0x6026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6028:
	/* 0x6028: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_602c:
	/* 0x602c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_602f:
	/* 0x602f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6034:
	/* 0x6034: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6039:
	/* 0x6039: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_603d:
	/* 0x603d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6042:
	/* 0x6042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6044:
	/* 0x6044: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6048:
	/* 0x6048: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_604d:
	/* 0x604d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6052:
	/* 0x6052: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6057:
	/* 0x6057: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_605b:
	/* 0x605b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6060:
	/* 0x6060: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6062:
	/* 0x6062: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6066:
	/* 0x6066: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_606a:
	/* 0x606a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_606f:
	/* 0x606f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6074:
	/* 0x6074: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6079:
	/* 0x6079: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_607e:
	/* 0x607e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6081:
	/* 0x6081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6083:
	/* 0x6083: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6088:
	/* 0x6088: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_608d:
	/* 0x608d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6091:
	/* 0x6091: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6096:
	/* 0x6096: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_609b:
	/* 0x609b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60a0:
	/* 0x60a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60a5:
	/* 0x60a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a7:
	/* 0x60a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60ac:
	/* 0x60ac: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_60af:
	/* 0x60af: je     6270 <trace_security_file_mprotect+0x6270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6270;
	}
x86_l_60b5:
	/* 0x60b5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60ba:
	/* 0x60ba: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_60bd:
	/* 0x60bd: je     6270 <trace_security_file_mprotect+0x6270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6270;
	}
x86_l_60c3:
	/* 0x60c3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_60c7:
	/* 0x60c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60cc:
	/* 0x60cc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_60d1:
	/* 0x60d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60d6:
	/* 0x60d6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_60db:
	/* 0x60db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60dd:
	/* 0x60dd: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_60e1:
	/* 0x60e1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_60e3:
	/* 0x60e3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_60e9:
	/* 0x60e9: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_60ec:
	/* 0x60ec: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_60ee:
	/* 0x60ee: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_60f4:
	/* 0x60f4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60f9:
	/* 0x60f9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_60ff:
	/* 0x60ff: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6102:
	/* 0x6102: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6104:
	/* 0x6104: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6109:
	/* 0x6109: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_610b:
	/* 0x610b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_610e:
	/* 0x610e: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_6114:
	/* 0x6114: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6118:
	/* 0x6118: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_611e:
	/* 0x611e: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6122:
	/* 0x6122: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6125:
	/* 0x6125: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_612a:
	/* 0x612a: jmp    62ec <trace_security_file_mprotect+0x62ec> */
	goto x86_l_62ec;
x86_l_612f:
	/* 0x612f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6132:
	/* 0x6132: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_6138:
	/* 0x6138: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_613c:
	/* 0x613c: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6141:
	/* 0x6141: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_6147:
	/* 0x6147: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_614b:
	/* 0x614b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6150:
	/* 0x6150: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6155:
	/* 0x6155: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_615a:
	/* 0x615a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_615e:
	/* 0x615e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6162:
	/* 0x6162: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6167:
	/* 0x6167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6169:
	/* 0x6169: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_616d:
	/* 0x616d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6170:
	/* 0x6170: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6175:
	/* 0x6175: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_617a:
	/* 0x617a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_617e:
	/* 0x617e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6183:
	/* 0x6183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6185:
	/* 0x6185: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6189:
	/* 0x6189: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_618e:
	/* 0x618e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6193:
	/* 0x6193: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6198:
	/* 0x6198: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_619c:
	/* 0x619c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61a1:
	/* 0x61a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61a3:
	/* 0x61a3: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61a7:
	/* 0x61a7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_61ab:
	/* 0x61ab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61b0:
	/* 0x61b0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61b5:
	/* 0x61b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61ba:
	/* 0x61ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61bf:
	/* 0x61bf: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_61c2:
	/* 0x61c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61c4:
	/* 0x61c4: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61c9:
	/* 0x61c9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61ce:
	/* 0x61ce: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61d2:
	/* 0x61d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61d7:
	/* 0x61d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61dc:
	/* 0x61dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61e1:
	/* 0x61e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61e6:
	/* 0x61e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61e8:
	/* 0x61e8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61ed:
	/* 0x61ed: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_61f0:
	/* 0x61f0: je     63b1 <trace_security_file_mprotect+0x63b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63b1;
	}
x86_l_61f6:
	/* 0x61f6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61fb:
	/* 0x61fb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_61fe:
	/* 0x61fe: je     63b1 <trace_security_file_mprotect+0x63b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63b1;
	}
x86_l_6204:
	/* 0x6204: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6208:
	/* 0x6208: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_620d:
	/* 0x620d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6212:
	/* 0x6212: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6217:
	/* 0x6217: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_621c:
	/* 0x621c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_621e:
	/* 0x621e: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6222:
	/* 0x6222: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6224:
	/* 0x6224: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_622a:
	/* 0x622a: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_622d:
	/* 0x622d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_622f:
	/* 0x622f: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_6235:
	/* 0x6235: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_623a:
	/* 0x623a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6240:
	/* 0x6240: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6243:
	/* 0x6243: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6245:
	/* 0x6245: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_624a:
	/* 0x624a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_624c:
	/* 0x624c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_624f:
	/* 0x624f: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_6255:
	/* 0x6255: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6259:
	/* 0x6259: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_625f:
	/* 0x625f: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6263:
	/* 0x6263: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6266:
	/* 0x6266: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_626b:
	/* 0x626b: jmp    642d <trace_security_file_mprotect+0x642d> */
	goto x86_l_642d;
x86_l_6270:
	/* 0x6270: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6273:
	/* 0x6273: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_6279:
	/* 0x6279: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_627d:
	/* 0x627d: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6282:
	/* 0x6282: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_6288:
	/* 0x6288: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_628c:
	/* 0x628c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6291:
	/* 0x6291: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6296:
	/* 0x6296: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_629b:
	/* 0x629b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_629f:
	/* 0x629f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_62a3:
	/* 0x62a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62a8:
	/* 0x62a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62aa:
	/* 0x62aa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62ae:
	/* 0x62ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_62b1:
	/* 0x62b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62b6:
	/* 0x62b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62bb:
	/* 0x62bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62bf:
	/* 0x62bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62c4:
	/* 0x62c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62c6:
	/* 0x62c6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62ca:
	/* 0x62ca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62cf:
	/* 0x62cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62d4:
	/* 0x62d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62d9:
	/* 0x62d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62dd:
	/* 0x62dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62e2:
	/* 0x62e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62e4:
	/* 0x62e4: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62e8:
	/* 0x62e8: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_62ec:
	/* 0x62ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62f1:
	/* 0x62f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_62f6:
	/* 0x62f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62fb:
	/* 0x62fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6300:
	/* 0x6300: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6303:
	/* 0x6303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6305:
	/* 0x6305: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_630a:
	/* 0x630a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_630f:
	/* 0x630f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6313:
	/* 0x6313: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6318:
	/* 0x6318: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_631d:
	/* 0x631d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6322:
	/* 0x6322: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6327:
	/* 0x6327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6329:
	/* 0x6329: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_632e:
	/* 0x632e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6331:
	/* 0x6331: je     64f2 <trace_security_file_mprotect+0x64f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64f2;
	}
x86_l_6337:
	/* 0x6337: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_633c:
	/* 0x633c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_633f:
	/* 0x633f: je     64f2 <trace_security_file_mprotect+0x64f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64f2;
	}
x86_l_6345:
	/* 0x6345: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6349:
	/* 0x6349: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_634e:
	/* 0x634e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6353:
	/* 0x6353: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6358:
	/* 0x6358: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_635d:
	/* 0x635d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_635f:
	/* 0x635f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6363:
	/* 0x6363: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6365:
	/* 0x6365: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_636b:
	/* 0x636b: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_636e:
	/* 0x636e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6370:
	/* 0x6370: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_6376:
	/* 0x6376: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_637b:
	/* 0x637b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6381:
	/* 0x6381: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6384:
	/* 0x6384: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6386:
	/* 0x6386: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_638b:
	/* 0x638b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_638d:
	/* 0x638d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6390:
	/* 0x6390: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_6396:
	/* 0x6396: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_639a:
	/* 0x639a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_63a0:
	/* 0x63a0: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_63a4:
	/* 0x63a4: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_63a7:
	/* 0x63a7: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63ac:
	/* 0x63ac: jmp    656e <trace_security_file_mprotect+0x656e> */
	return 25966ULL;
x86_l_63b1:
	/* 0x63b1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_63b4:
	/* 0x63b4: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_63ba:
	/* 0x63ba: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63be:
	/* 0x63be: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_63c3:
	/* 0x63c3: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_63c9:
	/* 0x63c9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_63cd:
	/* 0x63cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63d2:
	/* 0x63d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_63d7:
	/* 0x63d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63dc:
	/* 0x63dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63e0:
	/* 0x63e0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_63e4:
	/* 0x63e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63e9:
	/* 0x63e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63eb:
	/* 0x63eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63ef:
	/* 0x63ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_63f2:
	/* 0x63f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_63f7:
	/* 0x63f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63fc:
	/* 0x63fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6400:
	/* 0x6400: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6405:
	/* 0x6405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6407:
	/* 0x6407: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_640b:
	/* 0x640b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6410:
	/* 0x6410: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6415:
	/* 0x6415: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_641a:
	/* 0x641a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_641e:
	/* 0x641e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6423:
	/* 0x6423: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6425:
	/* 0x6425: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6429:
	/* 0x6429: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_642d:
	/* 0x642d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6432:
	/* 0x6432: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6437:
	/* 0x6437: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_643c:
	/* 0x643c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6441:
	/* 0x6441: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6444:
	/* 0x6444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6446:
	/* 0x6446: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_644b:
	/* 0x644b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6450:
	/* 0x6450: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6454:
	/* 0x6454: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6459:
	/* 0x6459: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_645e:
	/* 0x645e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6463:
	/* 0x6463: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6468:
	/* 0x6468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_646a:
	/* 0x646a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646f:
	/* 0x646f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6472:
	/* 0x6472: je     6633 <trace_security_file_mprotect+0x6633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26163ULL;
	}
x86_l_6478:
	/* 0x6478: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_647d:
	/* 0x647d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6480:
	/* 0x6480: je     6633 <trace_security_file_mprotect+0x6633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26163ULL;
	}
x86_l_6486:
	/* 0x6486: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_648a:
	/* 0x648a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_648f:
	/* 0x648f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6494:
	/* 0x6494: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6499:
	/* 0x6499: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_649e:
	/* 0x649e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64a0:
	/* 0x64a0: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64a4:
	/* 0x64a4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_64a6:
	/* 0x64a6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_64ac:
	/* 0x64ac: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_64af:
	/* 0x64af: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_64b1:
	/* 0x64b1: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_64b7:
	/* 0x64b7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64bc:
	/* 0x64bc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_64c2:
	/* 0x64c2: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_64c5:
	/* 0x64c5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_64c7:
	/* 0x64c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_64cc:
	/* 0x64cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64ce:
	/* 0x64ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64d1:
	/* 0x64d1: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_64d7:
	/* 0x64d7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_64db:
	/* 0x64db: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_64e1:
	/* 0x64e1: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_64e5:
	/* 0x64e5: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_64e8:
	/* 0x64e8: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64ed:
	/* 0x64ed: jmp    66af <trace_security_file_mprotect+0x66af> */
	return 26287ULL;
x86_l_64f2:
	/* 0x64f2: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_64f5:
	/* 0x64f5: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_64fb:
	/* 0x64fb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64ff:
	/* 0x64ff: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6504:
	/* 0x6504: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_650a:
	/* 0x650a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_650e:
	/* 0x650e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6513:
	/* 0x6513: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6518:
	/* 0x6518: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_651d:
	/* 0x651d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6521:
	/* 0x6521: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	return 25893ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_15(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 25893ULL: goto x86_l_6525;
	case 25898ULL: goto x86_l_652a;
	case 25900ULL: goto x86_l_652c;
	case 25904ULL: goto x86_l_6530;
	case 25907ULL: goto x86_l_6533;
	case 25912ULL: goto x86_l_6538;
	case 25917ULL: goto x86_l_653d;
	case 25921ULL: goto x86_l_6541;
	case 25926ULL: goto x86_l_6546;
	case 25928ULL: goto x86_l_6548;
	case 25932ULL: goto x86_l_654c;
	case 25937ULL: goto x86_l_6551;
	case 25942ULL: goto x86_l_6556;
	case 25947ULL: goto x86_l_655b;
	case 25951ULL: goto x86_l_655f;
	case 25956ULL: goto x86_l_6564;
	case 25958ULL: goto x86_l_6566;
	case 25962ULL: goto x86_l_656a;
	case 25966ULL: goto x86_l_656e;
	case 25971ULL: goto x86_l_6573;
	case 25976ULL: goto x86_l_6578;
	case 25981ULL: goto x86_l_657d;
	case 25986ULL: goto x86_l_6582;
	case 25989ULL: goto x86_l_6585;
	case 25991ULL: goto x86_l_6587;
	case 25996ULL: goto x86_l_658c;
	case 26001ULL: goto x86_l_6591;
	case 26005ULL: goto x86_l_6595;
	case 26010ULL: goto x86_l_659a;
	case 26015ULL: goto x86_l_659f;
	case 26020ULL: goto x86_l_65a4;
	case 26025ULL: goto x86_l_65a9;
	case 26027ULL: goto x86_l_65ab;
	case 26032ULL: goto x86_l_65b0;
	case 26035ULL: goto x86_l_65b3;
	case 26041ULL: goto x86_l_65b9;
	case 26046ULL: goto x86_l_65be;
	case 26049ULL: goto x86_l_65c1;
	case 26055ULL: goto x86_l_65c7;
	case 26059ULL: goto x86_l_65cb;
	case 26064ULL: goto x86_l_65d0;
	case 26069ULL: goto x86_l_65d5;
	case 26074ULL: goto x86_l_65da;
	case 26079ULL: goto x86_l_65df;
	case 26081ULL: goto x86_l_65e1;
	case 26085ULL: goto x86_l_65e5;
	case 26087ULL: goto x86_l_65e7;
	case 26093ULL: goto x86_l_65ed;
	case 26096ULL: goto x86_l_65f0;
	case 26098ULL: goto x86_l_65f2;
	case 26104ULL: goto x86_l_65f8;
	case 26109ULL: goto x86_l_65fd;
	case 26115ULL: goto x86_l_6603;
	case 26118ULL: goto x86_l_6606;
	case 26120ULL: goto x86_l_6608;
	case 26125ULL: goto x86_l_660d;
	case 26127ULL: goto x86_l_660f;
	case 26130ULL: goto x86_l_6612;
	case 26136ULL: goto x86_l_6618;
	case 26140ULL: goto x86_l_661c;
	case 26146ULL: goto x86_l_6622;
	case 26150ULL: goto x86_l_6626;
	case 26153ULL: goto x86_l_6629;
	case 26158ULL: goto x86_l_662e;
	case 26163ULL: goto x86_l_6633;
	case 26166ULL: goto x86_l_6636;
	case 26172ULL: goto x86_l_663c;
	case 26176ULL: goto x86_l_6640;
	case 26181ULL: goto x86_l_6645;
	case 26187ULL: goto x86_l_664b;
	case 26191ULL: goto x86_l_664f;
	case 26196ULL: goto x86_l_6654;
	case 26201ULL: goto x86_l_6659;
	case 26206ULL: goto x86_l_665e;
	case 26210ULL: goto x86_l_6662;
	case 26214ULL: goto x86_l_6666;
	case 26219ULL: goto x86_l_666b;
	case 26221ULL: goto x86_l_666d;
	case 26225ULL: goto x86_l_6671;
	case 26228ULL: goto x86_l_6674;
	case 26233ULL: goto x86_l_6679;
	case 26238ULL: goto x86_l_667e;
	case 26242ULL: goto x86_l_6682;
	case 26247ULL: goto x86_l_6687;
	case 26249ULL: goto x86_l_6689;
	case 26253ULL: goto x86_l_668d;
	case 26258ULL: goto x86_l_6692;
	case 26263ULL: goto x86_l_6697;
	case 26268ULL: goto x86_l_669c;
	case 26272ULL: goto x86_l_66a0;
	case 26277ULL: goto x86_l_66a5;
	case 26279ULL: goto x86_l_66a7;
	case 26283ULL: goto x86_l_66ab;
	case 26287ULL: goto x86_l_66af;
	case 26292ULL: goto x86_l_66b4;
	case 26297ULL: goto x86_l_66b9;
	case 26302ULL: goto x86_l_66be;
	case 26307ULL: goto x86_l_66c3;
	case 26310ULL: goto x86_l_66c6;
	case 26312ULL: goto x86_l_66c8;
	case 26317ULL: goto x86_l_66cd;
	case 26322ULL: goto x86_l_66d2;
	case 26326ULL: goto x86_l_66d6;
	case 26331ULL: goto x86_l_66db;
	case 26336ULL: goto x86_l_66e0;
	case 26341ULL: goto x86_l_66e5;
	case 26346ULL: goto x86_l_66ea;
	case 26348ULL: goto x86_l_66ec;
	case 26353ULL: goto x86_l_66f1;
	case 26356ULL: goto x86_l_66f4;
	case 26362ULL: goto x86_l_66fa;
	case 26367ULL: goto x86_l_66ff;
	case 26370ULL: goto x86_l_6702;
	case 26376ULL: goto x86_l_6708;
	case 26380ULL: goto x86_l_670c;
	case 26385ULL: goto x86_l_6711;
	case 26390ULL: goto x86_l_6716;
	case 26395ULL: goto x86_l_671b;
	case 26400ULL: goto x86_l_6720;
	case 26402ULL: goto x86_l_6722;
	case 26406ULL: goto x86_l_6726;
	case 26408ULL: goto x86_l_6728;
	case 26414ULL: goto x86_l_672e;
	case 26417ULL: goto x86_l_6731;
	case 26419ULL: goto x86_l_6733;
	case 26425ULL: goto x86_l_6739;
	case 26430ULL: goto x86_l_673e;
	case 26436ULL: goto x86_l_6744;
	case 26439ULL: goto x86_l_6747;
	case 26441ULL: goto x86_l_6749;
	case 26446ULL: goto x86_l_674e;
	case 26448ULL: goto x86_l_6750;
	case 26451ULL: goto x86_l_6753;
	case 26457ULL: goto x86_l_6759;
	case 26461ULL: goto x86_l_675d;
	case 26467ULL: goto x86_l_6763;
	case 26471ULL: goto x86_l_6767;
	case 26474ULL: goto x86_l_676a;
	case 26479ULL: goto x86_l_676f;
	case 26484ULL: goto x86_l_6774;
	case 26487ULL: goto x86_l_6777;
	case 26493ULL: goto x86_l_677d;
	case 26497ULL: goto x86_l_6781;
	case 26502ULL: goto x86_l_6786;
	case 26508ULL: goto x86_l_678c;
	case 26512ULL: goto x86_l_6790;
	case 26517ULL: goto x86_l_6795;
	case 26522ULL: goto x86_l_679a;
	case 26527ULL: goto x86_l_679f;
	case 26531ULL: goto x86_l_67a3;
	case 26535ULL: goto x86_l_67a7;
	case 26540ULL: goto x86_l_67ac;
	case 26542ULL: goto x86_l_67ae;
	case 26546ULL: goto x86_l_67b2;
	case 26549ULL: goto x86_l_67b5;
	case 26554ULL: goto x86_l_67ba;
	case 26559ULL: goto x86_l_67bf;
	case 26563ULL: goto x86_l_67c3;
	case 26568ULL: goto x86_l_67c8;
	case 26570ULL: goto x86_l_67ca;
	case 26574ULL: goto x86_l_67ce;
	case 26579ULL: goto x86_l_67d3;
	case 26584ULL: goto x86_l_67d8;
	case 26589ULL: goto x86_l_67dd;
	case 26593ULL: goto x86_l_67e1;
	case 26598ULL: goto x86_l_67e6;
	case 26600ULL: goto x86_l_67e8;
	case 26604ULL: goto x86_l_67ec;
	case 26608ULL: goto x86_l_67f0;
	case 26613ULL: goto x86_l_67f5;
	case 26618ULL: goto x86_l_67fa;
	case 26623ULL: goto x86_l_67ff;
	case 26628ULL: goto x86_l_6804;
	case 26631ULL: goto x86_l_6807;
	case 26633ULL: goto x86_l_6809;
	case 26638ULL: goto x86_l_680e;
	case 26643ULL: goto x86_l_6813;
	case 26647ULL: goto x86_l_6817;
	case 26652ULL: goto x86_l_681c;
	case 26657ULL: goto x86_l_6821;
	case 26662ULL: goto x86_l_6826;
	case 26667ULL: goto x86_l_682b;
	case 26669ULL: goto x86_l_682d;
	case 26674ULL: goto x86_l_6832;
	case 26677ULL: goto x86_l_6835;
	case 26683ULL: goto x86_l_683b;
	case 26688ULL: goto x86_l_6840;
	case 26691ULL: goto x86_l_6843;
	case 26697ULL: goto x86_l_6849;
	case 26701ULL: goto x86_l_684d;
	case 26706ULL: goto x86_l_6852;
	case 26711ULL: goto x86_l_6857;
	case 26716ULL: goto x86_l_685c;
	case 26721ULL: goto x86_l_6861;
	case 26723ULL: goto x86_l_6863;
	case 26727ULL: goto x86_l_6867;
	case 26729ULL: goto x86_l_6869;
	case 26735ULL: goto x86_l_686f;
	case 26738ULL: goto x86_l_6872;
	case 26740ULL: goto x86_l_6874;
	case 26746ULL: goto x86_l_687a;
	case 26751ULL: goto x86_l_687f;
	case 26757ULL: goto x86_l_6885;
	case 26760ULL: goto x86_l_6888;
	case 26762ULL: goto x86_l_688a;
	case 26767ULL: goto x86_l_688f;
	case 26769ULL: goto x86_l_6891;
	case 26772ULL: goto x86_l_6894;
	case 26778ULL: goto x86_l_689a;
	case 26782ULL: goto x86_l_689e;
	case 26788ULL: goto x86_l_68a4;
	case 26792ULL: goto x86_l_68a8;
	case 26795ULL: goto x86_l_68ab;
	case 26800ULL: goto x86_l_68b0;
	case 26805ULL: goto x86_l_68b5;
	case 26808ULL: goto x86_l_68b8;
	case 26814ULL: goto x86_l_68be;
	case 26818ULL: goto x86_l_68c2;
	case 26823ULL: goto x86_l_68c7;
	case 26829ULL: goto x86_l_68cd;
	case 26833ULL: goto x86_l_68d1;
	case 26838ULL: goto x86_l_68d6;
	case 26843ULL: goto x86_l_68db;
	case 26848ULL: goto x86_l_68e0;
	case 26852ULL: goto x86_l_68e4;
	case 26856ULL: goto x86_l_68e8;
	case 26861ULL: goto x86_l_68ed;
	case 26863ULL: goto x86_l_68ef;
	case 26867ULL: goto x86_l_68f3;
	case 26870ULL: goto x86_l_68f6;
	case 26875ULL: goto x86_l_68fb;
	case 26880ULL: goto x86_l_6900;
	case 26884ULL: goto x86_l_6904;
	case 26889ULL: goto x86_l_6909;
	case 26891ULL: goto x86_l_690b;
	case 26895ULL: goto x86_l_690f;
	case 26900ULL: goto x86_l_6914;
	case 26905ULL: goto x86_l_6919;
	case 26910ULL: goto x86_l_691e;
	case 26914ULL: goto x86_l_6922;
	case 26919ULL: goto x86_l_6927;
	case 26921ULL: goto x86_l_6929;
	case 26925ULL: goto x86_l_692d;
	case 26929ULL: goto x86_l_6931;
	case 26934ULL: goto x86_l_6936;
	case 26939ULL: goto x86_l_693b;
	case 26944ULL: goto x86_l_6940;
	case 26949ULL: goto x86_l_6945;
	case 26952ULL: goto x86_l_6948;
	case 26954ULL: goto x86_l_694a;
	case 26959ULL: goto x86_l_694f;
	case 26964ULL: goto x86_l_6954;
	case 26968ULL: goto x86_l_6958;
	case 26973ULL: goto x86_l_695d;
	case 26978ULL: goto x86_l_6962;
	case 26983ULL: goto x86_l_6967;
	case 26988ULL: goto x86_l_696c;
	case 26990ULL: goto x86_l_696e;
	case 26995ULL: goto x86_l_6973;
	case 26998ULL: goto x86_l_6976;
	case 27004ULL: goto x86_l_697c;
	case 27009ULL: goto x86_l_6981;
	case 27012ULL: goto x86_l_6984;
	case 27018ULL: goto x86_l_698a;
	case 27022ULL: goto x86_l_698e;
	case 27027ULL: goto x86_l_6993;
	case 27032ULL: goto x86_l_6998;
	case 27037ULL: goto x86_l_699d;
	case 27042ULL: goto x86_l_69a2;
	case 27044ULL: goto x86_l_69a4;
	case 27048ULL: goto x86_l_69a8;
	case 27050ULL: goto x86_l_69aa;
	case 27056ULL: goto x86_l_69b0;
	case 27059ULL: goto x86_l_69b3;
	case 27061ULL: goto x86_l_69b5;
	case 27067ULL: goto x86_l_69bb;
	case 27072ULL: goto x86_l_69c0;
	case 27078ULL: goto x86_l_69c6;
	case 27081ULL: goto x86_l_69c9;
	case 27083ULL: goto x86_l_69cb;
	case 27088ULL: goto x86_l_69d0;
	case 27090ULL: goto x86_l_69d2;
	case 27093ULL: goto x86_l_69d5;
	case 27099ULL: goto x86_l_69db;
	case 27103ULL: goto x86_l_69df;
	case 27109ULL: goto x86_l_69e5;
	case 27113ULL: goto x86_l_69e9;
	case 27116ULL: goto x86_l_69ec;
	case 27121ULL: goto x86_l_69f1;
	case 27126ULL: goto x86_l_69f6;
	case 27129ULL: goto x86_l_69f9;
	case 27135ULL: goto x86_l_69ff;
	case 27139ULL: goto x86_l_6a03;
	case 27144ULL: goto x86_l_6a08;
	case 27150ULL: goto x86_l_6a0e;
	case 27154ULL: goto x86_l_6a12;
	case 27159ULL: goto x86_l_6a17;
	case 27164ULL: goto x86_l_6a1c;
	case 27169ULL: goto x86_l_6a21;
	case 27173ULL: goto x86_l_6a25;
	case 27177ULL: goto x86_l_6a29;
	case 27182ULL: goto x86_l_6a2e;
	case 27184ULL: goto x86_l_6a30;
	case 27188ULL: goto x86_l_6a34;
	case 27191ULL: goto x86_l_6a37;
	case 27196ULL: goto x86_l_6a3c;
	case 27201ULL: goto x86_l_6a41;
	case 27205ULL: goto x86_l_6a45;
	case 27210ULL: goto x86_l_6a4a;
	case 27212ULL: goto x86_l_6a4c;
	case 27216ULL: goto x86_l_6a50;
	case 27221ULL: goto x86_l_6a55;
	case 27226ULL: goto x86_l_6a5a;
	case 27231ULL: goto x86_l_6a5f;
	case 27235ULL: goto x86_l_6a63;
	case 27240ULL: goto x86_l_6a68;
	case 27242ULL: goto x86_l_6a6a;
	case 27247ULL: goto x86_l_6a6f;
	case 27250ULL: goto x86_l_6a72;
	case 27256ULL: goto x86_l_6a78;
	case 27260ULL: goto x86_l_6a7c;
	case 27265ULL: goto x86_l_6a81;
	case 27271ULL: goto x86_l_6a87;
	case 27275ULL: goto x86_l_6a8b;
	case 27280ULL: goto x86_l_6a90;
	case 27285ULL: goto x86_l_6a95;
	case 27290ULL: goto x86_l_6a9a;
	case 27294ULL: goto x86_l_6a9e;
	case 27298ULL: goto x86_l_6aa2;
	case 27303ULL: goto x86_l_6aa7;
	case 27305ULL: goto x86_l_6aa9;
	case 27309ULL: goto x86_l_6aad;
	case 27312ULL: goto x86_l_6ab0;
	case 27317ULL: goto x86_l_6ab5;
	case 27322ULL: goto x86_l_6aba;
	case 27326ULL: goto x86_l_6abe;
	case 27331ULL: goto x86_l_6ac3;
	case 27333ULL: goto x86_l_6ac5;
	case 27337ULL: goto x86_l_6ac9;
	case 27342ULL: goto x86_l_6ace;
	case 27347ULL: goto x86_l_6ad3;
	case 27352ULL: goto x86_l_6ad8;
	case 27356ULL: goto x86_l_6adc;
	case 27361ULL: goto x86_l_6ae1;
	case 27363ULL: goto x86_l_6ae3;
	case 27367ULL: goto x86_l_6ae7;
	case 27371ULL: goto x86_l_6aeb;
	case 27376ULL: goto x86_l_6af0;
	case 27381ULL: goto x86_l_6af5;
	case 27386ULL: goto x86_l_6afa;
	case 27391ULL: goto x86_l_6aff;
	case 27394ULL: goto x86_l_6b02;
	case 27396ULL: goto x86_l_6b04;
	case 27401ULL: goto x86_l_6b09;
	case 27406ULL: goto x86_l_6b0e;
	case 27410ULL: goto x86_l_6b12;
	case 27415ULL: goto x86_l_6b17;
	case 27420ULL: goto x86_l_6b1c;
	case 27425ULL: goto x86_l_6b21;
	case 27430ULL: goto x86_l_6b26;
	case 27432ULL: goto x86_l_6b28;
	case 27437ULL: goto x86_l_6b2d;
	case 27440ULL: goto x86_l_6b30;
	case 27442ULL: goto x86_l_6b32;
	case 27447ULL: goto x86_l_6b37;
	case 27450ULL: goto x86_l_6b3a;
	case 27452ULL: goto x86_l_6b3c;
	case 27456ULL: goto x86_l_6b40;
	case 27461ULL: goto x86_l_6b45;
	case 27466ULL: goto x86_l_6b4a;
	case 27471ULL: goto x86_l_6b4f;
	case 27476ULL: goto x86_l_6b54;
	case 27478ULL: goto x86_l_6b56;
	case 27482ULL: goto x86_l_6b5a;
	case 27484ULL: goto x86_l_6b5c;
	case 27490ULL: goto x86_l_6b62;
	case 27493ULL: goto x86_l_6b65;
	case 27495ULL: goto x86_l_6b67;
	case 27501ULL: goto x86_l_6b6d;
	case 27506ULL: goto x86_l_6b72;
	case 27512ULL: goto x86_l_6b78;
	case 27515ULL: goto x86_l_6b7b;
	case 27517ULL: goto x86_l_6b7d;
	case 27522ULL: goto x86_l_6b82;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6525:
	/* 0x6525: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_652a:
	/* 0x652a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652c:
	/* 0x652c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6530:
	/* 0x6530: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6533:
	/* 0x6533: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6538:
	/* 0x6538: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_653d:
	/* 0x653d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6541:
	/* 0x6541: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6546:
	/* 0x6546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6548:
	/* 0x6548: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_654c:
	/* 0x654c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6551:
	/* 0x6551: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6556:
	/* 0x6556: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_655b:
	/* 0x655b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655f:
	/* 0x655f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6564:
	/* 0x6564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6566:
	/* 0x6566: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_656a:
	/* 0x656a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_656e:
	/* 0x656e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6573:
	/* 0x6573: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6578:
	/* 0x6578: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_657d:
	/* 0x657d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6582:
	/* 0x6582: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6585:
	/* 0x6585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6587:
	/* 0x6587: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_658c:
	/* 0x658c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6591:
	/* 0x6591: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6595:
	/* 0x6595: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_659a:
	/* 0x659a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_659f:
	/* 0x659f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65a4:
	/* 0x65a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65a9:
	/* 0x65a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65ab:
	/* 0x65ab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65b0:
	/* 0x65b0: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65b3:
	/* 0x65b3: je     6774 <trace_security_file_mprotect+0x6774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6774;
	}
x86_l_65b9:
	/* 0x65b9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65be:
	/* 0x65be: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_65c1:
	/* 0x65c1: je     6774 <trace_security_file_mprotect+0x6774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6774;
	}
x86_l_65c7:
	/* 0x65c7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_65cb:
	/* 0x65cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65d0:
	/* 0x65d0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_65d5:
	/* 0x65d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65da:
	/* 0x65da: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_65df:
	/* 0x65df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65e1:
	/* 0x65e1: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_65e5:
	/* 0x65e5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_65e7:
	/* 0x65e7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65ed:
	/* 0x65ed: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_65f0:
	/* 0x65f0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_65f2:
	/* 0x65f2: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_65f8:
	/* 0x65f8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65fd:
	/* 0x65fd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6603:
	/* 0x6603: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6606:
	/* 0x6606: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6608:
	/* 0x6608: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_660d:
	/* 0x660d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_660f:
	/* 0x660f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6612:
	/* 0x6612: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_6618:
	/* 0x6618: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_661c:
	/* 0x661c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6622:
	/* 0x6622: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6626:
	/* 0x6626: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6629:
	/* 0x6629: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_662e:
	/* 0x662e: jmp    67f0 <trace_security_file_mprotect+0x67f0> */
	goto x86_l_67f0;
x86_l_6633:
	/* 0x6633: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6636:
	/* 0x6636: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_663c:
	/* 0x663c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6640:
	/* 0x6640: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6645:
	/* 0x6645: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_664b:
	/* 0x664b: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_664f:
	/* 0x664f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6654:
	/* 0x6654: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6659:
	/* 0x6659: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_665e:
	/* 0x665e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6662:
	/* 0x6662: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6666:
	/* 0x6666: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_666b:
	/* 0x666b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666d:
	/* 0x666d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6671:
	/* 0x6671: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6674:
	/* 0x6674: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6679:
	/* 0x6679: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_667e:
	/* 0x667e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6682:
	/* 0x6682: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6687:
	/* 0x6687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6689:
	/* 0x6689: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_668d:
	/* 0x668d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6692:
	/* 0x6692: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6697:
	/* 0x6697: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_669c:
	/* 0x669c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66a0:
	/* 0x66a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66a5:
	/* 0x66a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a7:
	/* 0x66a7: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66ab:
	/* 0x66ab: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_66af:
	/* 0x66af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66b4:
	/* 0x66b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66b9:
	/* 0x66b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66be:
	/* 0x66be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66c3:
	/* 0x66c3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_66c6:
	/* 0x66c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66c8:
	/* 0x66c8: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66cd:
	/* 0x66cd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66d2:
	/* 0x66d2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_66d6:
	/* 0x66d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66db:
	/* 0x66db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66e0:
	/* 0x66e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66e5:
	/* 0x66e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66ea:
	/* 0x66ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66ec:
	/* 0x66ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66f1:
	/* 0x66f1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_66f4:
	/* 0x66f4: je     68b5 <trace_security_file_mprotect+0x68b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68b5;
	}
x86_l_66fa:
	/* 0x66fa: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66ff:
	/* 0x66ff: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6702:
	/* 0x6702: je     68b5 <trace_security_file_mprotect+0x68b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68b5;
	}
x86_l_6708:
	/* 0x6708: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_670c:
	/* 0x670c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6711:
	/* 0x6711: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6716:
	/* 0x6716: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_671b:
	/* 0x671b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6720:
	/* 0x6720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6722:
	/* 0x6722: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6726:
	/* 0x6726: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6728:
	/* 0x6728: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_672e:
	/* 0x672e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_6731:
	/* 0x6731: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6733:
	/* 0x6733: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_6739:
	/* 0x6739: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_673e:
	/* 0x673e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6744:
	/* 0x6744: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6747:
	/* 0x6747: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6749:
	/* 0x6749: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_674e:
	/* 0x674e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6750:
	/* 0x6750: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6753:
	/* 0x6753: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_6759:
	/* 0x6759: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_675d:
	/* 0x675d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6763:
	/* 0x6763: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6767:
	/* 0x6767: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_676a:
	/* 0x676a: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_676f:
	/* 0x676f: jmp    6931 <trace_security_file_mprotect+0x6931> */
	goto x86_l_6931;
x86_l_6774:
	/* 0x6774: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6777:
	/* 0x6777: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_677d:
	/* 0x677d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6781:
	/* 0x6781: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6786:
	/* 0x6786: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_678c:
	/* 0x678c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6790:
	/* 0x6790: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6795:
	/* 0x6795: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_679a:
	/* 0x679a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_679f:
	/* 0x679f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67a3:
	/* 0x67a3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_67a7:
	/* 0x67a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67ac:
	/* 0x67ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67ae:
	/* 0x67ae: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67b2:
	/* 0x67b2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_67b5:
	/* 0x67b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_67ba:
	/* 0x67ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67bf:
	/* 0x67bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67c3:
	/* 0x67c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67c8:
	/* 0x67c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67ca:
	/* 0x67ca: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67ce:
	/* 0x67ce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67d3:
	/* 0x67d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_67d8:
	/* 0x67d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67dd:
	/* 0x67dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67e1:
	/* 0x67e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67e6:
	/* 0x67e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67e8:
	/* 0x67e8: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67ec:
	/* 0x67ec: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_67f0:
	/* 0x67f0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_67f5:
	/* 0x67f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_67fa:
	/* 0x67fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67ff:
	/* 0x67ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6804:
	/* 0x6804: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6807:
	/* 0x6807: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6809:
	/* 0x6809: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_680e:
	/* 0x680e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6813:
	/* 0x6813: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6817:
	/* 0x6817: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_681c:
	/* 0x681c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6821:
	/* 0x6821: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6826:
	/* 0x6826: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_682b:
	/* 0x682b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_682d:
	/* 0x682d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6832:
	/* 0x6832: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6835:
	/* 0x6835: je     69f6 <trace_security_file_mprotect+0x69f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69f6;
	}
x86_l_683b:
	/* 0x683b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6840:
	/* 0x6840: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6843:
	/* 0x6843: je     69f6 <trace_security_file_mprotect+0x69f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69f6;
	}
x86_l_6849:
	/* 0x6849: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_684d:
	/* 0x684d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6852:
	/* 0x6852: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6857:
	/* 0x6857: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_685c:
	/* 0x685c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6861:
	/* 0x6861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6863:
	/* 0x6863: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6867:
	/* 0x6867: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6869:
	/* 0x6869: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_686f:
	/* 0x686f: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_6872:
	/* 0x6872: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6874:
	/* 0x6874: jb     4561 <trace_security_file_mprotect+0x4561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 17761ULL;
	}
x86_l_687a:
	/* 0x687a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_687f:
	/* 0x687f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6885:
	/* 0x6885: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6888:
	/* 0x6888: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_688a:
	/* 0x688a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_688f:
	/* 0x688f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6891:
	/* 0x6891: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6894:
	/* 0x6894: jl     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 18790ULL;
	}
x86_l_689a:
	/* 0x689a: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_689e:
	/* 0x689e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_68a4:
	/* 0x68a4: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_68a8:
	/* 0x68a8: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_68ab:
	/* 0x68ab: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_68b0:
	/* 0x68b0: jmp    4966 <trace_security_file_mprotect+0x4966> */
	return 18790ULL;
x86_l_68b5:
	/* 0x68b5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_68b8:
	/* 0x68b8: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_68be:
	/* 0x68be: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68c2:
	/* 0x68c2: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_68c7:
	/* 0x68c7: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_68cd:
	/* 0x68cd: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_68d1:
	/* 0x68d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_68d6:
	/* 0x68d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_68db:
	/* 0x68db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68e0:
	/* 0x68e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68e4:
	/* 0x68e4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_68e8:
	/* 0x68e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68ed:
	/* 0x68ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68ef:
	/* 0x68ef: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68f3:
	/* 0x68f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_68f6:
	/* 0x68f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_68fb:
	/* 0x68fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6900:
	/* 0x6900: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6904:
	/* 0x6904: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6909:
	/* 0x6909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_690b:
	/* 0x690b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_690f:
	/* 0x690f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6914:
	/* 0x6914: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6919:
	/* 0x6919: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_691e:
	/* 0x691e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6922:
	/* 0x6922: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6927:
	/* 0x6927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6929:
	/* 0x6929: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692d:
	/* 0x692d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6931:
	/* 0x6931: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6936:
	/* 0x6936: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_693b:
	/* 0x693b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6940:
	/* 0x6940: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6945:
	/* 0x6945: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6948:
	/* 0x6948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694a:
	/* 0x694a: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_694f:
	/* 0x694f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6954:
	/* 0x6954: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6958:
	/* 0x6958: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_695d:
	/* 0x695d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6962:
	/* 0x6962: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6967:
	/* 0x6967: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_696c:
	/* 0x696c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696e:
	/* 0x696e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6973:
	/* 0x6973: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6976:
	/* 0x6976: je     6a6f <trace_security_file_mprotect+0x6a6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a6f;
	}
x86_l_697c:
	/* 0x697c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6981:
	/* 0x6981: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6984:
	/* 0x6984: je     6a6f <trace_security_file_mprotect+0x6a6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a6f;
	}
x86_l_698a:
	/* 0x698a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_698e:
	/* 0x698e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6993:
	/* 0x6993: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6998:
	/* 0x6998: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_699d:
	/* 0x699d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_69a2:
	/* 0x69a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69a4:
	/* 0x69a4: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_69a8:
	/* 0x69a8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_69aa:
	/* 0x69aa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_69b0:
	/* 0x69b0: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_69b3:
	/* 0x69b3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_69b5:
	/* 0x69b5: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_69bb:
	/* 0x69bb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69c0:
	/* 0x69c0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_69c6:
	/* 0x69c6: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_69c9:
	/* 0x69c9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_69cb:
	/* 0x69cb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_69d0:
	/* 0x69d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69d2:
	/* 0x69d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_69d5:
	/* 0x69d5: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_69db:
	/* 0x69db: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_69df:
	/* 0x69df: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_69e5:
	/* 0x69e5: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_69e9:
	/* 0x69e9: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_69ec:
	/* 0x69ec: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69f1:
	/* 0x69f1: jmp    6aeb <trace_security_file_mprotect+0x6aeb> */
	goto x86_l_6aeb;
x86_l_69f6:
	/* 0x69f6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_69f9:
	/* 0x69f9: jne    4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18790ULL;
	}
x86_l_69ff:
	/* 0x69ff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a03:
	/* 0x6a03: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6a08:
	/* 0x6a08: je     4966 <trace_security_file_mprotect+0x4966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18790ULL;
	}
x86_l_6a0e:
	/* 0x6a0e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a12:
	/* 0x6a12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a17:
	/* 0x6a17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6a1c:
	/* 0x6a1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a21:
	/* 0x6a21: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a25:
	/* 0x6a25: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a29:
	/* 0x6a29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a2e:
	/* 0x6a2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a30:
	/* 0x6a30: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a34:
	/* 0x6a34: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6a37:
	/* 0x6a37: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6a3c:
	/* 0x6a3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a41:
	/* 0x6a41: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a45:
	/* 0x6a45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a4a:
	/* 0x6a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a4c:
	/* 0x6a4c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a50:
	/* 0x6a50: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a55:
	/* 0x6a55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6a5a:
	/* 0x6a5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a5f:
	/* 0x6a5f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a63:
	/* 0x6a63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a68:
	/* 0x6a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a6a:
	/* 0x6a6a: jmp    4966 <trace_security_file_mprotect+0x4966> */
	return 18790ULL;
x86_l_6a6f:
	/* 0x6a6f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6a72:
	/* 0x6a72: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_6a78:
	/* 0x6a78: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a7c:
	/* 0x6a7c: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6a81:
	/* 0x6a81: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_6a87:
	/* 0x6a87: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a8b:
	/* 0x6a8b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a90:
	/* 0x6a90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6a95:
	/* 0x6a95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a9a:
	/* 0x6a9a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a9e:
	/* 0x6a9e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6aa2:
	/* 0x6aa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6aa7:
	/* 0x6aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6aa9:
	/* 0x6aa9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6aad:
	/* 0x6aad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6ab0:
	/* 0x6ab0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6ab5:
	/* 0x6ab5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6aba:
	/* 0x6aba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6abe:
	/* 0x6abe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ac3:
	/* 0x6ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ac5:
	/* 0x6ac5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ac9:
	/* 0x6ac9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ace:
	/* 0x6ace: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6ad3:
	/* 0x6ad3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ad8:
	/* 0x6ad8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6adc:
	/* 0x6adc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ae1:
	/* 0x6ae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ae3:
	/* 0x6ae3: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ae7:
	/* 0x6ae7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6aeb:
	/* 0x6aeb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6af0:
	/* 0x6af0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6af5:
	/* 0x6af5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6afa:
	/* 0x6afa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6aff:
	/* 0x6aff: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6b02:
	/* 0x6b02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b04:
	/* 0x6b04: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b09:
	/* 0x6b09: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b0e:
	/* 0x6b0e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6b12:
	/* 0x6b12: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b17:
	/* 0x6b17: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b1c:
	/* 0x6b1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b21:
	/* 0x6b21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b26:
	/* 0x6b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b28:
	/* 0x6b28: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b2d:
	/* 0x6b2d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6b30:
	/* 0x6b30: je     6ba8 <trace_security_file_mprotect+0x6ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 27560ULL;
	}
x86_l_6b32:
	/* 0x6b32: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b37:
	/* 0x6b37: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6b3a:
	/* 0x6b3a: je     6ba8 <trace_security_file_mprotect+0x6ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 27560ULL;
	}
x86_l_6b3c:
	/* 0x6b3c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b40:
	/* 0x6b40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b45:
	/* 0x6b45: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6b4a:
	/* 0x6b4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b4f:
	/* 0x6b4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6b54:
	/* 0x6b54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b56:
	/* 0x6b56: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6b5a:
	/* 0x6b5a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6b5c:
	/* 0x6b5c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b62:
	/* 0x6b62: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_6b65:
	/* 0x6b65: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6b67:
	/* 0x6b67: jb     34aa <trace_security_file_mprotect+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13482ULL;
	}
x86_l_6b6d:
	/* 0x6b6d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b72:
	/* 0x6b72: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6b78:
	/* 0x6b78: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6b7b:
	/* 0x6b7b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6b7d:
	/* 0x6b7d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6b82:
	/* 0x6b82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 27524ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_16(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 27524ULL: goto x86_l_6b84;
	case 27527ULL: goto x86_l_6b87;
	case 27533ULL: goto x86_l_6b8d;
	case 27537ULL: goto x86_l_6b91;
	case 27543ULL: goto x86_l_6b97;
	case 27547ULL: goto x86_l_6b9b;
	case 27550ULL: goto x86_l_6b9e;
	case 27555ULL: goto x86_l_6ba3;
	case 27560ULL: goto x86_l_6ba8;
	case 27563ULL: goto x86_l_6bab;
	case 27569ULL: goto x86_l_6bb1;
	case 27573ULL: goto x86_l_6bb5;
	case 27578ULL: goto x86_l_6bba;
	case 27584ULL: goto x86_l_6bc0;
	case 27588ULL: goto x86_l_6bc4;
	case 27593ULL: goto x86_l_6bc9;
	case 27598ULL: goto x86_l_6bce;
	case 27603ULL: goto x86_l_6bd3;
	case 27607ULL: goto x86_l_6bd7;
	case 27611ULL: goto x86_l_6bdb;
	case 27616ULL: goto x86_l_6be0;
	case 27618ULL: goto x86_l_6be2;
	case 27622ULL: goto x86_l_6be6;
	case 27625ULL: goto x86_l_6be9;
	case 27630ULL: goto x86_l_6bee;
	case 27635ULL: goto x86_l_6bf3;
	case 27639ULL: goto x86_l_6bf7;
	case 27644ULL: goto x86_l_6bfc;
	case 27646ULL: goto x86_l_6bfe;
	case 27650ULL: goto x86_l_6c02;
	case 27655ULL: goto x86_l_6c07;
	case 27660ULL: goto x86_l_6c0c;
	case 27665ULL: goto x86_l_6c11;
	case 27669ULL: goto x86_l_6c15;
	case 27674ULL: goto x86_l_6c1a;
	case 27676ULL: goto x86_l_6c1c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b84:
	/* 0x6b84: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6b87:
	/* 0x6b87: jl     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12901ULL;
	}
x86_l_6b8d:
	/* 0x6b8d: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6b91:
	/* 0x6b91: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6b97:
	/* 0x6b97: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6b9b:
	/* 0x6b9b: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6b9e:
	/* 0x6b9e: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ba3:
	/* 0x6ba3: jmp    3265 <trace_security_file_mprotect+0x3265> */
	return 12901ULL;
x86_l_6ba8:
	/* 0x6ba8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6bab:
	/* 0x6bab: jne    3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12901ULL;
	}
x86_l_6bb1:
	/* 0x6bb1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bb5:
	/* 0x6bb5: cmp    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6bba:
	/* 0x6bba: je     3265 <trace_security_file_mprotect+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12901ULL;
	}
x86_l_6bc0:
	/* 0x6bc0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6bc4:
	/* 0x6bc4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6bc9:
	/* 0x6bc9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6bce:
	/* 0x6bce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6bd3:
	/* 0x6bd3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bd7:
	/* 0x6bd7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6bdb:
	/* 0x6bdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6be0:
	/* 0x6be0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6be2:
	/* 0x6be2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6be6:
	/* 0x6be6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6be9:
	/* 0x6be9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6bee:
	/* 0x6bee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6bf3:
	/* 0x6bf3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bf7:
	/* 0x6bf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bfc:
	/* 0x6bfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bfe:
	/* 0x6bfe: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c02:
	/* 0x6c02: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c07:
	/* 0x6c07: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6c0c:
	/* 0x6c0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c11:
	/* 0x6c11: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c15:
	/* 0x6c15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c1a:
	/* 0x6c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c1c:
	/* 0x6c1c: jmp    3265 <trace_security_file_mprotect+0x3265> */
	return 12901ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_security_file_mprotect_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 24720U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2201ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2206ULL && __x86_pc <= 3941ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3943ULL && __x86_pc <= 5515ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5520ULL && __x86_pc <= 7333ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7342ULL && __x86_pc <= 9084ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9089ULL && __x86_pc <= 10809ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10812ULL && __x86_pc <= 12455ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12458ULL && __x86_pc <= 14183ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14186ULL && __x86_pc <= 15989ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15994ULL && __x86_pc <= 17689ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17692ULL && __x86_pc <= 19317ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19321ULL && __x86_pc <= 20957ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20960ULL && __x86_pc <= 22596ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22599ULL && __x86_pc <= 24240ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 24246ULL && __x86_pc <= 25889ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_14(__x86_state, __x86_pc);
		else if (__x86_pc >= 25893ULL && __x86_pc <= 27522ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_15(__x86_state, __x86_pc);
		else if (__x86_pc >= 27524ULL && __x86_pc <= 27676ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_16(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

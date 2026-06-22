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
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 25ULL: goto x86_l_19;
	case 37ULL: goto x86_l_25;
	case 49ULL: goto x86_l_31;
	case 61ULL: goto x86_l_3d;
	case 73ULL: goto x86_l_49;
	case 85ULL: goto x86_l_55;
	case 97ULL: goto x86_l_61;
	case 109ULL: goto x86_l_6d;
	case 121ULL: goto x86_l_79;
	case 126ULL: goto x86_l_7e;
	case 128ULL: goto x86_l_80;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 141ULL: goto x86_l_8d;
	case 145ULL: goto x86_l_91;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 162ULL: goto x86_l_a2;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 213ULL: goto x86_l_d5;
	case 215ULL: goto x86_l_d7;
	case 219ULL: goto x86_l_db;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 241ULL: goto x86_l_f1;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 250ULL: goto x86_l_fa;
	case 254ULL: goto x86_l_fe;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 268ULL: goto x86_l_10c;
	case 273ULL: goto x86_l_111;
	case 275ULL: goto x86_l_113;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 284ULL: goto x86_l_11c;
	case 289ULL: goto x86_l_121;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 328ULL: goto x86_l_148;
	case 333ULL: goto x86_l_14d;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 347ULL: goto x86_l_15b;
	case 350ULL: goto x86_l_15e;
	case 356ULL: goto x86_l_164;
	case 359ULL: goto x86_l_167;
	case 369ULL: goto x86_l_171;
	case 377ULL: goto x86_l_179;
	case 388ULL: goto x86_l_184;
	case 399ULL: goto x86_l_18f;
	case 410ULL: goto x86_l_19a;
	case 421ULL: goto x86_l_1a5;
	case 432ULL: goto x86_l_1b0;
	case 443ULL: goto x86_l_1bb;
	case 454ULL: goto x86_l_1c6;
	case 465ULL: goto x86_l_1d1;
	case 472ULL: goto x86_l_1d8;
	case 480ULL: goto x86_l_1e0;
	case 488ULL: goto x86_l_1e8;
	case 496ULL: goto x86_l_1f0;
	case 504ULL: goto x86_l_1f8;
	case 512ULL: goto x86_l_200;
	case 520ULL: goto x86_l_208;
	case 528ULL: goto x86_l_210;
	case 536ULL: goto x86_l_218;
	case 544ULL: goto x86_l_220;
	case 552ULL: goto x86_l_228;
	case 560ULL: goto x86_l_230;
	case 568ULL: goto x86_l_238;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 583ULL: goto x86_l_247;
	case 587ULL: goto x86_l_24b;
	case 591ULL: goto x86_l_24f;
	case 595ULL: goto x86_l_253;
	case 603ULL: goto x86_l_25b;
	case 608ULL: goto x86_l_260;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 629ULL: goto x86_l_275;
	case 633ULL: goto x86_l_279;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 653ULL: goto x86_l_28d;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 666ULL: goto x86_l_29a;
	case 670ULL: goto x86_l_29e;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 689ULL: goto x86_l_2b1;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 713ULL: goto x86_l_2c9;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 738ULL: goto x86_l_2e2;
	case 743ULL: goto x86_l_2e7;
	case 746ULL: goto x86_l_2ea;
	case 750ULL: goto x86_l_2ee;
	case 758ULL: goto x86_l_2f6;
	case 763ULL: goto x86_l_2fb;
	case 770ULL: goto x86_l_302;
	case 775ULL: goto x86_l_307;
	case 777ULL: goto x86_l_309;
	case 780ULL: goto x86_l_30c;
	case 786ULL: goto x86_l_312;
	case 790ULL: goto x86_l_316;
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
	case 1047ULL: goto x86_l_417;
	case 1058ULL: goto x86_l_422;
	case 1069ULL: goto x86_l_42d;
	case 1080ULL: goto x86_l_438;
	case 1091ULL: goto x86_l_443;
	case 1102ULL: goto x86_l_44e;
	case 1113ULL: goto x86_l_459;
	case 1124ULL: goto x86_l_464;
	case 1132ULL: goto x86_l_46c;
	case 1140ULL: goto x86_l_474;
	case 1148ULL: goto x86_l_47c;
	case 1156ULL: goto x86_l_484;
	case 1164ULL: goto x86_l_48c;
	case 1172ULL: goto x86_l_494;
	case 1180ULL: goto x86_l_49c;
	case 1188ULL: goto x86_l_4a4;
	case 1196ULL: goto x86_l_4ac;
	case 1204ULL: goto x86_l_4b4;
	case 1212ULL: goto x86_l_4bc;
	case 1220ULL: goto x86_l_4c4;
	case 1228ULL: goto x86_l_4cc;
	case 1236ULL: goto x86_l_4d4;
	case 1244ULL: goto x86_l_4dc;
	case 1251ULL: goto x86_l_4e3;
	case 1257ULL: goto x86_l_4e9;
	case 1264ULL: goto x86_l_4f0;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1296ULL: goto x86_l_510;
	case 1298ULL: goto x86_l_512;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1327ULL: goto x86_l_52f;
	case 1331ULL: goto x86_l_533;
	case 1339ULL: goto x86_l_53b;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1367ULL: goto x86_l_557;
	case 1375ULL: goto x86_l_55f;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1394ULL: goto x86_l_572;
	case 1405ULL: goto x86_l_57d;
	case 1416ULL: goto x86_l_588;
	case 1427ULL: goto x86_l_593;
	case 1438ULL: goto x86_l_59e;
	case 1449ULL: goto x86_l_5a9;
	case 1460ULL: goto x86_l_5b4;
	case 1471ULL: goto x86_l_5bf;
	case 1482ULL: goto x86_l_5ca;
	case 1490ULL: goto x86_l_5d2;
	case 1498ULL: goto x86_l_5da;
	case 1506ULL: goto x86_l_5e2;
	case 1514ULL: goto x86_l_5ea;
	case 1522ULL: goto x86_l_5f2;
	case 1530ULL: goto x86_l_5fa;
	case 1538ULL: goto x86_l_602;
	case 1546ULL: goto x86_l_60a;
	case 1554ULL: goto x86_l_612;
	case 1562ULL: goto x86_l_61a;
	case 1570ULL: goto x86_l_622;
	case 1578ULL: goto x86_l_62a;
	case 1586ULL: goto x86_l_632;
	case 1594ULL: goto x86_l_63a;
	case 1602ULL: goto x86_l_642;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1622ULL: goto x86_l_656;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1635ULL: goto x86_l_663;
	case 1638ULL: goto x86_l_666;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1654ULL: goto x86_l_676;
	case 1656ULL: goto x86_l_678;
	case 1659ULL: goto x86_l_67b;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1675ULL: goto x86_l_68b;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1697ULL: goto x86_l_6a1;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1712ULL: goto x86_l_6b0;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1793ULL: goto x86_l_701;
	case 1801ULL: goto x86_l_709;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1848ULL: goto x86_l_738;
	case 1850ULL: goto x86_l_73a;
	case 1854ULL: goto x86_l_73e;
	case 1858ULL: goto x86_l_742;
	case 1862ULL: goto x86_l_746;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1883ULL: goto x86_l_75b;
	case 1887ULL: goto x86_l_75f;
	case 1891ULL: goto x86_l_763;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1960ULL: goto x86_l_7a8;
	case 1962ULL: goto x86_l_7aa;
	case 1966ULL: goto x86_l_7ae;
	case 1970ULL: goto x86_l_7b2;
	case 1974ULL: goto x86_l_7b6;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1993ULL: goto x86_l_7c9;
	case 1995ULL: goto x86_l_7cb;
	case 1999ULL: goto x86_l_7cf;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2046ULL: goto x86_l_7fe;
	case 2048ULL: goto x86_l_800;
	case 2052ULL: goto x86_l_804;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2107ULL: goto x86_l_83b;
	case 2111ULL: goto x86_l_83f;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2207ULL: goto x86_l_89f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 392ULL);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    QWORD PTR [rsp+0x180],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1649267441664ULL);
x86_l_19:
	/* 0x19: mov    QWORD PTR [rsp+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_25:
	/* 0x25: mov    QWORD PTR [rsp+0x170],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1580547964928ULL);
x86_l_31:
	/* 0x31: mov    QWORD PTR [rsp+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_3d:
	/* 0x3d: mov    QWORD PTR [rsp+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_49:
	/* 0x49: mov    QWORD PTR [rsp+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_55:
	/* 0x55: mov    QWORD PTR [rsp+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_61:
	/* 0x61: mov    QWORD PTR [rsp+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_79:
	/* 0x79: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_7e:
	/* 0x7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80:
	/* 0x80: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_83:
	/* 0x83: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_88:
	/* 0x88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a:
	/* 0x8a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_91:
	/* 0x91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96:
	/* 0x96: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b:
	/* 0x9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0:
	/* 0xa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2:
	/* 0xa2: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_aa:
	/* 0xaa: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_af:
	/* 0xaf: jne    121 <trace_security_file_mprotect+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_121;
	}
x86_l_b1:
	/* 0xb1: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_b6:
	/* 0xb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8:
	/* 0xb8: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_bd:
	/* 0xbd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c0:
	/* 0xc0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c2:
	/* 0xc2: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c6:
	/* 0xc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb:
	/* 0xcb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d0:
	/* 0xd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d5:
	/* 0xd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df:
	/* 0xdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e4:
	/* 0xe4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e9:
	/* 0xe9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ee:
	/* 0xee: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3:
	/* 0xf3: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_f8:
	/* 0xf8: jne    100 <trace_security_file_mprotect+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_100;
	}
x86_l_fa:
	/* 0xfa: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe:
	/* 0xfe: jmp    121 <trace_security_file_mprotect+0x121> */
	goto x86_l_121;
x86_l_100:
	/* 0x100: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_105:
	/* 0x105: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_10c:
	/* 0x10c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_111:
	/* 0x111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113:
	/* 0x113: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_116:
	/* 0x116: je     11c <trace_security_file_mprotect+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11c;
	}
x86_l_118:
	/* 0x118: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a:
	/* 0x11a: jmp    121 <trace_security_file_mprotect+0x121> */
	goto x86_l_121;
x86_l_11c:
	/* 0x11c: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_121:
	/* 0x121: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_129:
	/* 0x129: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e:
	/* 0x12e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_135:
	/* 0x135: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13a:
	/* 0x13a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c:
	/* 0x13c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_145:
	/* 0x145: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_148:
	/* 0x148: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d:
	/* 0x14d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_154:
	/* 0x154: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_159:
	/* 0x159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b:
	/* 0x15b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e:
	/* 0x15e: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_164:
	/* 0x164: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_167:
	/* 0x167: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_171:
	/* 0x171: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1a5:
	/* 0x1a5: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1bb:
	/* 0x1bb: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1d8:
	/* 0x1d8: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f0:
	/* 0x1f0: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_200:
	/* 0x200: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_208:
	/* 0x208: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_210:
	/* 0x210: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_218:
	/* 0x218: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_220:
	/* 0x220: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_228:
	/* 0x228: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_230:
	/* 0x230: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_238:
	/* 0x238: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_240:
	/* 0x240: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24b:
	/* 0x24b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_24f:
	/* 0x24f: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_253:
	/* 0x253: mov    DWORD PTR [r14+0x70],0x2ec */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337900ULL);
x86_l_25b:
	/* 0x25b: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_260:
	/* 0x260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262:
	/* 0x262: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265:
	/* 0x265: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_26a:
	/* 0x26a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c:
	/* 0x26c: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_271:
	/* 0x271: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_275:
	/* 0x275: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_279:
	/* 0x279: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c:
	/* 0x27c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_281:
	/* 0x281: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_288:
	/* 0x288: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d:
	/* 0x28d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_295:
	/* 0x295: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_298:
	/* 0x298: je     2e7 <trace_security_file_mprotect+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e7;
	}
x86_l_29a:
	/* 0x29a: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29e:
	/* 0x29e: mov    DWORD PTR [rsp+0xb8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2a5:
	/* 0x2a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aa:
	/* 0x2aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2b1:
	/* 0x2b1: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2b9:
	/* 0x2b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb:
	/* 0x2bb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: mov    QWORD PTR [rsp+0xc0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2c9:
	/* 0x2c9: je     528 <trace_security_file_mprotect+0x528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_528;
	}
x86_l_2cf:
	/* 0x2cf: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2d5:
	/* 0x2d5: jne    a8b <trace_security_file_mprotect+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_2db:
	/* 0x2db: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2e0:
	/* 0x2e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2:
	/* 0x2e2: jmp    b12 <trace_security_file_mprotect+0xb12> */
	return 2834ULL;
x86_l_2e7:
	/* 0x2e7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea:
	/* 0x2ea: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee:
	/* 0x2ee: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f6:
	/* 0x2f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fb:
	/* 0x2fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_302:
	/* 0x302: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_307:
	/* 0x307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309:
	/* 0x309: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30c:
	/* 0x30c: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_312:
	/* 0x312: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316:
	/* 0x316: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31a:
	/* 0x31a: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_325:
	/* 0x325: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_330:
	/* 0x330: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_33b:
	/* 0x33b: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_346:
	/* 0x346: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_351:
	/* 0x351: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_35c:
	/* 0x35c: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_367:
	/* 0x367: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_372:
	/* 0x372: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_37d:
	/* 0x37d: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_388:
	/* 0x388: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_39e:
	/* 0x39e: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3b4:
	/* 0x3b4: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3bf:
	/* 0x3bf: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3ca:
	/* 0x3ca: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3d5:
	/* 0x3d5: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3e0:
	/* 0x3e0: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3eb:
	/* 0x3eb: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3f6:
	/* 0x3f6: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_401:
	/* 0x401: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_40c:
	/* 0x40c: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_417:
	/* 0x417: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_422:
	/* 0x422: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_42d:
	/* 0x42d: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_438:
	/* 0x438: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_459:
	/* 0x459: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_464:
	/* 0x464: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_484:
	/* 0x484: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_494:
	/* 0x494: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_49c:
	/* 0x49c: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4ac:
	/* 0x4ac: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4b4:
	/* 0x4b4: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4c4:
	/* 0x4c4: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4cc:
	/* 0x4cc: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d4:
	/* 0x4d4: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e3:
	/* 0x4e3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4e9:
	/* 0x4e9: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4f0:
	/* 0x4f0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f5:
	/* 0x4f5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4fa:
	/* 0x4fa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4fd:
	/* 0x4fd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_500:
	/* 0x500: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_503:
	/* 0x503: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_508:
	/* 0x508: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50d:
	/* 0x50d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_510:
	/* 0x510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512:
	/* 0x512: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_51a:
	/* 0x51a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51d:
	/* 0x51d: jne    29a <trace_security_file_mprotect+0x29a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29a;
	}
x86_l_523:
	/* 0x523: jmp    3c1c <trace_security_file_mprotect+0x3c1c> */
	return 15388ULL;
x86_l_528:
	/* 0x528: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_52f:
	/* 0x52f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_533:
	/* 0x533: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_53b:
	/* 0x53b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_540:
	/* 0x540: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_547:
	/* 0x547: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c:
	/* 0x54c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e:
	/* 0x54e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_551:
	/* 0x551: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_557:
	/* 0x557: mov    QWORD PTR [rsp+0xb0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_55f:
	/* 0x55f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_563:
	/* 0x563: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_588:
	/* 0x588: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_59e:
	/* 0x59e: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5a9:
	/* 0x5a9: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5b4:
	/* 0x5b4: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5bf:
	/* 0x5bf: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5ca:
	/* 0x5ca: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5da:
	/* 0x5da: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5e2:
	/* 0x5e2: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5ea:
	/* 0x5ea: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5fa:
	/* 0x5fa: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_602:
	/* 0x602: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_60a:
	/* 0x60a: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_622:
	/* 0x622: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_62a:
	/* 0x62a: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_63a:
	/* 0x63a: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_642:
	/* 0x642: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_649:
	/* 0x649: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_64f:
	/* 0x64f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_656:
	/* 0x656: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65b:
	/* 0x65b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_660:
	/* 0x660: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_663:
	/* 0x663: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_666:
	/* 0x666: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_669:
	/* 0x669: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66e:
	/* 0x66e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_673:
	/* 0x673: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_676:
	/* 0x676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_678:
	/* 0x678: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67b:
	/* 0x67b: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_681:
	/* 0x681: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_684:
	/* 0x684: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_68b:
	/* 0x68b: lea    rbp,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68f:
	/* 0x68f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_694:
	/* 0x694: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_699:
	/* 0x699: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69e:
	/* 0x69e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6a1:
	/* 0x6a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a3:
	/* 0x6a3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a8:
	/* 0x6a8: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6b0:
	/* 0x6b0: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b4:
	/* 0x6b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b9:
	/* 0x6b9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6be:
	/* 0x6be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c3:
	/* 0x6c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c5:
	/* 0x6c5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ca:
	/* 0x6ca: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6ce:
	/* 0x6ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d3:
	/* 0x6d3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d8:
	/* 0x6d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6dd:
	/* 0x6dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6df:
	/* 0x6df: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e4:
	/* 0x6e4: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ed:
	/* 0x6ed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f2:
	/* 0x6f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6f7:
	/* 0x6f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f9:
	/* 0x6f9: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6fd:
	/* 0x6fd: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_701:
	/* 0x701: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_709:
	/* 0x709: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x71c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_71f:
	/* 0x71f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_721:
	/* 0x721: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_726:
	/* 0x726: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72b:
	/* 0x72b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_730:
	/* 0x730: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_735:
	/* 0x735: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_738:
	/* 0x738: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73a:
	/* 0x73a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_73e:
	/* 0x73e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_742:
	/* 0x742: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_746:
	/* 0x746: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_74a:
	/* 0x74a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74f:
	/* 0x74f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_754:
	/* 0x754: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_759:
	/* 0x759: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75b:
	/* 0x75b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75f:
	/* 0x75f: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_763:
	/* 0x763: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_768:
	/* 0x768: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_76d:
	/* 0x76d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_772:
	/* 0x772: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_775:
	/* 0x775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_777:
	/* 0x777: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77c:
	/* 0x77c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_780:
	/* 0x780: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_785:
	/* 0x785: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_78a:
	/* 0x78a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78f:
	/* 0x78f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_791:
	/* 0x791: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_796:
	/* 0x796: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_79b:
	/* 0x79b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a0:
	/* 0x7a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7a5:
	/* 0x7a5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7aa:
	/* 0x7aa: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ae:
	/* 0x7ae: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7b2:
	/* 0x7b2: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7b6:
	/* 0x7b6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7ba:
	/* 0x7ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7bf:
	/* 0x7bf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c4:
	/* 0x7c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c9:
	/* 0x7c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cb:
	/* 0x7cb: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7cf:
	/* 0x7cf: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d3:
	/* 0x7d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d8:
	/* 0x7d8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7dd:
	/* 0x7dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e2:
	/* 0x7e2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7e5:
	/* 0x7e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e7:
	/* 0x7e7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ec:
	/* 0x7ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f1:
	/* 0x7f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f6:
	/* 0x7f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7fb:
	/* 0x7fb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7fe:
	/* 0x7fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_800:
	/* 0x800: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_804:
	/* 0x804: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_808:
	/* 0x808: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_80c:
	/* 0x80c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_810:
	/* 0x810: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_815:
	/* 0x815: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_81a:
	/* 0x81a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81f:
	/* 0x81f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_821:
	/* 0x821: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_826:
	/* 0x826: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_82a:
	/* 0x82a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_82f:
	/* 0x82f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_834:
	/* 0x834: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_839:
	/* 0x839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83b:
	/* 0x83b: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83f:
	/* 0x83f: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_843:
	/* 0x843: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_848:
	/* 0x848: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_84d:
	/* 0x84d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_852:
	/* 0x852: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_855:
	/* 0x855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_857:
	/* 0x857: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_85c:
	/* 0x85c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_861:
	/* 0x861: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_866:
	/* 0x866: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_86b:
	/* 0x86b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_870:
	/* 0x870: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_874:
	/* 0x874: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_878:
	/* 0x878: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_87c:
	/* 0x87c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_880:
	/* 0x880: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_885:
	/* 0x885: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88a:
	/* 0x88a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_896:
	/* 0x896: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_89a:
	/* 0x89a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89f:
	/* 0x89f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 2212ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2219ULL: goto x86_l_8ab;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2268ULL: goto x86_l_8dc;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2303ULL: goto x86_l_8ff;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2323ULL: goto x86_l_913;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2350ULL: goto x86_l_92e;
	case 2355ULL: goto x86_l_933;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2398ULL: goto x86_l_95e;
	case 2402ULL: goto x86_l_962;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2413ULL: goto x86_l_96d;
	case 2417ULL: goto x86_l_971;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2455ULL: goto x86_l_997;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2485ULL: goto x86_l_9b5;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2562ULL: goto x86_l_a02;
	case 2570ULL: goto x86_l_a0a;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2608ULL: goto x86_l_a30;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2679ULL: goto x86_l_a77;
	case 2687ULL: goto x86_l_a7f;
	case 2693ULL: goto x86_l_a85;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2755ULL: goto x86_l_ac3;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2865ULL: goto x86_l_b31;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2873ULL: goto x86_l_b39;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2904ULL: goto x86_l_b58;
	case 2910ULL: goto x86_l_b5e;
	case 2921ULL: goto x86_l_b69;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2971ULL: goto x86_l_b9b;
	case 2973ULL: goto x86_l_b9d;
	case 2976ULL: goto x86_l_ba0;
	case 2978ULL: goto x86_l_ba2;
	case 2982ULL: goto x86_l_ba6;
	case 2989ULL: goto x86_l_bad;
	case 2992ULL: goto x86_l_bb0;
	case 2999ULL: goto x86_l_bb7;
	case 3003ULL: goto x86_l_bbb;
	case 3007ULL: goto x86_l_bbf;
	case 3014ULL: goto x86_l_bc6;
	case 3021ULL: goto x86_l_bcd;
	case 3025ULL: goto x86_l_bd1;
	case 3032ULL: goto x86_l_bd8;
	case 3036ULL: goto x86_l_bdc;
	case 3043ULL: goto x86_l_be3;
	case 3047ULL: goto x86_l_be7;
	case 3054ULL: goto x86_l_bee;
	case 3058ULL: goto x86_l_bf2;
	case 3065ULL: goto x86_l_bf9;
	case 3072ULL: goto x86_l_c00;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3099ULL: goto x86_l_c1b;
	case 3103ULL: goto x86_l_c1f;
	case 3107ULL: goto x86_l_c23;
	case 3115ULL: goto x86_l_c2b;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3198ULL: goto x86_l_c7e;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3210ULL: goto x86_l_c8a;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3234ULL: goto x86_l_ca2;
	case 3238ULL: goto x86_l_ca6;
	case 3240ULL: goto x86_l_ca8;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3261ULL: goto x86_l_cbd;
	case 3266ULL: goto x86_l_cc2;
	case 3270ULL: goto x86_l_cc6;
	case 3278ULL: goto x86_l_cce;
	case 3286ULL: goto x86_l_cd6;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3310ULL: goto x86_l_cee;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3323ULL: goto x86_l_cfb;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3357ULL: goto x86_l_d1d;
	case 3361ULL: goto x86_l_d21;
	case 3369ULL: goto x86_l_d29;
	case 3371ULL: goto x86_l_d2b;
	case 3379ULL: goto x86_l_d33;
	case 3387ULL: goto x86_l_d3b;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3412ULL: goto x86_l_d54;
	case 3415ULL: goto x86_l_d57;
	case 3421ULL: goto x86_l_d5d;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3448ULL: goto x86_l_d78;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3489ULL: goto x86_l_da1;
	case 3496ULL: goto x86_l_da8;
	case 3499ULL: goto x86_l_dab;
	case 3502ULL: goto x86_l_dae;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3534ULL: goto x86_l_dce;
	case 3537ULL: goto x86_l_dd1;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3555ULL: goto x86_l_de3;
	case 3563ULL: goto x86_l_deb;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3577ULL: goto x86_l_df9;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3606ULL: goto x86_l_e16;
	case 3612ULL: goto x86_l_e1c;
	case 3619ULL: goto x86_l_e23;
	case 3627ULL: goto x86_l_e2b;
	case 3634ULL: goto x86_l_e32;
	case 3642ULL: goto x86_l_e3a;
	case 3649ULL: goto x86_l_e41;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3674ULL: goto x86_l_e5a;
	case 3679ULL: goto x86_l_e5f;
	case 3681ULL: goto x86_l_e61;
	case 3684ULL: goto x86_l_e64;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3728ULL: goto x86_l_e90;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3740ULL: goto x86_l_e9c;
	case 3748ULL: goto x86_l_ea4;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3775ULL: goto x86_l_ebf;
	case 3778ULL: goto x86_l_ec2;
	case 3780ULL: goto x86_l_ec4;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3807ULL: goto x86_l_edf;
	case 3810ULL: goto x86_l_ee2;
	case 3812ULL: goto x86_l_ee4;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3835ULL: goto x86_l_efb;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3852ULL: goto x86_l_f0c;
	case 3859ULL: goto x86_l_f13;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3897ULL: goto x86_l_f39;
	case 3899ULL: goto x86_l_f3b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_8a4:
	/* 0x8a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8a9:
	/* 0x8a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ab:
	/* 0x8ab: cmp    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_8af:
	/* 0x8af: jne    907 <trace_security_file_mprotect+0x907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_907;
	}
x86_l_8b1:
	/* 0x8b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b6:
	/* 0x8b6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8bb:
	/* 0x8bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c0:
	/* 0x8c0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ca:
	/* 0x8ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d4:
	/* 0x8d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8d9:
	/* 0x8d9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8dc:
	/* 0x8dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8de:
	/* 0x8de: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e2:
	/* 0x8e2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8e6:
	/* 0x8e6: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ea:
	/* 0x8ea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f3:
	/* 0x8f3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8f8:
	/* 0x8f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8fd:
	/* 0x8fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ff:
	/* 0x8ff: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_903:
	/* 0x903: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_907:
	/* 0x907: mov    DWORD PTR [r13+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_90b:
	/* 0x90b: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_913:
	/* 0x913: lea    rbp,[r15+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_91a:
	/* 0x91a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91f:
	/* 0x91f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_924:
	/* 0x924: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_929:
	/* 0x929: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_92c:
	/* 0x92c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92e:
	/* 0x92e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_933:
	/* 0x933: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_937:
	/* 0x937: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93c:
	/* 0x93c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_941:
	/* 0x941: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_946:
	/* 0x946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_948:
	/* 0x948: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94d:
	/* 0x94d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_952:
	/* 0x952: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_957:
	/* 0x957: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_95c:
	/* 0x95c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95e:
	/* 0x95e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_962:
	/* 0x962: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_966:
	/* 0x966: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_96b:
	/* 0x96b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96d:
	/* 0x96d: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_971:
	/* 0x971: lea    rdx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_975:
	/* 0x975: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_97a:
	/* 0x97a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97f:
	/* 0x97f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_984:
	/* 0x984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_986:
	/* 0x986: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98b:
	/* 0x98b: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98f:
	/* 0x98f: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_997:
	/* 0x997: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_99b:
	/* 0x99b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a0:
	/* 0x9a0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a5:
	/* 0x9a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9aa:
	/* 0x9aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ac:
	/* 0x9ac: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b1:
	/* 0x9b1: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9b5:
	/* 0x9b5: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9b9:
	/* 0x9b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9be:
	/* 0x9be: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c3:
	/* 0x9c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c8:
	/* 0x9c8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9cb:
	/* 0x9cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cd:
	/* 0x9cd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d2:
	/* 0x9d2: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9d6:
	/* 0x9d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9db:
	/* 0x9db: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e0:
	/* 0x9e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9e5:
	/* 0x9e5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9e8:
	/* 0x9e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ea:
	/* 0x9ea: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_9ef:
	/* 0x9ef: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_9f7:
	/* 0x9f7: je     9fe <trace_security_file_mprotect+0x9fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9fe;
	}
x86_l_9f9:
	/* 0x9f9: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_9fe:
	/* 0x9fe: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a02:
	/* 0xa02: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a0a:
	/* 0xa0a: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a12:
	/* 0xa12: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a17:
	/* 0xa17: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a1c:
	/* 0xa1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1e:
	/* 0xa1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a23:
	/* 0xa23: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a28:
	/* 0xa28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2d:
	/* 0xa2d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a30:
	/* 0xa30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a32:
	/* 0xa32: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a37:
	/* 0xa37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3c:
	/* 0xa3c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a41:
	/* 0xa41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a46:
	/* 0xa46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a48:
	/* 0xa48: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a4d:
	/* 0xa4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a52:
	/* 0xa52: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a57:
	/* 0xa57: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a5a:
	/* 0xa5a: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a5f:
	/* 0xa5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a61:
	/* 0xa61: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_a64:
	/* 0xa64: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_a68:
	/* 0xa68: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_a6d:
	/* 0xa6d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a72:
	/* 0xa72: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a75:
	/* 0xa75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a77:
	/* 0xa77: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a7f:
	/* 0xa7f: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a85:
	/* 0xa85: je     2db <trace_security_file_mprotect+0x2db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 731ULL;
	}
x86_l_a8b:
	/* 0xa8b: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a90:
	/* 0xa90: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a97:
	/* 0xa97: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a9c:
	/* 0xa9c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa1:
	/* 0xaa1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa6:
	/* 0xaa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa8:
	/* 0xaa8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aad:
	/* 0xaad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab2:
	/* 0xab2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab7:
	/* 0xab7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_abc:
	/* 0xabc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abe:
	/* 0xabe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ac3:
	/* 0xac3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac8:
	/* 0xac8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_acd:
	/* 0xacd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ad2:
	/* 0xad2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad4:
	/* 0xad4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ad9:
	/* 0xad9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ade:
	/* 0xade: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ae3:
	/* 0xae3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae8:
	/* 0xae8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aea:
	/* 0xaea: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aef:
	/* 0xaef: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_af2:
	/* 0xaf2: je     b10 <trace_security_file_mprotect+0xb10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b10;
	}
x86_l_af4:
	/* 0xaf4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afd:
	/* 0xafd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b02:
	/* 0xb02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b07:
	/* 0xb07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b09:
	/* 0xb09: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b0e:
	/* 0xb0e: jmp    b12 <trace_security_file_mprotect+0xb12> */
	goto x86_l_b12;
x86_l_b10:
	/* 0xb10: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b12:
	/* 0xb12: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b16:
	/* 0xb16: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1a:
	/* 0xb1a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1e:
	/* 0xb1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b23:
	/* 0xb23: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b2a:
	/* 0xb2a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b2f:
	/* 0xb2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b31:
	/* 0xb31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b34:
	/* 0xb34: je     b4d <trace_security_file_mprotect+0xb4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b4d;
	}
x86_l_b36:
	/* 0xb36: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b39:
	/* 0xb39: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_b40:
	/* 0xb40: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_b43:
	/* 0xb43: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b46:
	/* 0xb46: jne    b4d <trace_security_file_mprotect+0xb4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b4d;
	}
x86_l_b48:
	/* 0xb48: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_b4d:
	/* 0xb4d: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_b52:
	/* 0xb52: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_b58:
	/* 0xb58: jne    3daa <trace_security_file_mprotect+0x3daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15786ULL;
	}
x86_l_b5e:
	/* 0xb5e: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_b69:
	/* 0xb69: mov    DWORD PTR [rsp+0x30],0x2ec */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430956ULL);
x86_l_b71:
	/* 0xb71: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b7b:
	/* 0xb7b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b82:
	/* 0xb82: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b87:
	/* 0xb87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b89:
	/* 0xb89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b8c:
	/* 0xb8c: je     bf9 <trace_security_file_mprotect+0xbf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf9;
	}
x86_l_b8e:
	/* 0xb8e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b93:
	/* 0xb93: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b98:
	/* 0xb98: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b9b:
	/* 0xb9b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b9d:
	/* 0xb9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba0:
	/* 0xba0: je     bf9 <trace_security_file_mprotect+0xbf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf9;
	}
x86_l_ba2:
	/* 0xba2: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba6:
	/* 0xba6: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_bad:
	/* 0xbad: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb0:
	/* 0xbb0: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_bb7:
	/* 0xbb7: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bbb:
	/* 0xbbb: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bbf:
	/* 0xbbf: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_bc6:
	/* 0xbc6: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_bcd:
	/* 0xbcd: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd1:
	/* 0xbd1: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_bd8:
	/* 0xbd8: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bdc:
	/* 0xbdc: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_be3:
	/* 0xbe3: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_be7:
	/* 0xbe7: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_bee:
	/* 0xbee: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bf2:
	/* 0xbf2: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_bf9:
	/* 0xbf9: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c00:
	/* 0xc00: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c07:
	/* 0xc07: mov    eax,DWORD PTR [r14+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_c0b:
	/* 0xc0b: cmp    eax,0x149 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 329ULL);
x86_l_c10:
	/* 0xc10: je     c1b <trace_security_file_mprotect+0xc1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1b;
	}
x86_l_c12:
	/* 0xc12: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_c15:
	/* 0xc15: jne    3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15388ULL;
	}
x86_l_c1b:
	/* 0xc1b: mov    rbx,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c1f:
	/* 0xc1f: mov    rax,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c23:
	/* 0xc23: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c2b:
	/* 0xc2b: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c2f:
	/* 0xc2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c34:
	/* 0xc34: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c39:
	/* 0xc39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c3e:
	/* 0xc3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c40:
	/* 0xc40: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c45:
	/* 0xc45: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_c4d:
	/* 0xc4d: add    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_c51:
	/* 0xc51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c56:
	/* 0xc56: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c5b:
	/* 0xc5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c60:
	/* 0xc60: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_c63:
	/* 0xc63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c65:
	/* 0xc65: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c6a:
	/* 0xc6a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6f:
	/* 0xc6f: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_c74:
	/* 0xc74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c76:
	/* 0xc76: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_c7b:
	/* 0xc7b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c7e:
	/* 0xc7e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c80:
	/* 0xc80: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_c8a:
	/* 0xc8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c8f:
	/* 0xc8f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c94:
	/* 0xc94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c99:
	/* 0xc99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9b:
	/* 0xc9b: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_ca0:
	/* 0xca0: jne    ca8 <trace_security_file_mprotect+0xca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ca8;
	}
x86_l_ca2:
	/* 0xca2: mov    rax,QWORD PTR [rbp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ca6:
	/* 0xca6: jmp    cc2 <trace_security_file_mprotect+0xcc2> */
	goto x86_l_cc2;
x86_l_ca8:
	/* 0xca8: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cac:
	/* 0xcac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb1:
	/* 0xcb1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cb6:
	/* 0xcb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cbb:
	/* 0xcbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbd:
	/* 0xcbd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cc2:
	/* 0xcc2: lea    rcx,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cc6:
	/* 0xcc6: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cce:
	/* 0xcce: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_cdd:
	/* 0xcdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce2:
	/* 0xce2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce7:
	/* 0xce7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cec:
	/* 0xcec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cee:
	/* 0xcee: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_cf3:
	/* 0xcf3: jne    cfb <trace_security_file_mprotect+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cfb;
	}
x86_l_cf5:
	/* 0xcf5: mov    rax,QWORD PTR [rbp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cf9:
	/* 0xcf9: jmp    d15 <trace_security_file_mprotect+0xd15> */
	goto x86_l_d15;
x86_l_cfb:
	/* 0xcfb: lea    rdx,[rbp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cff:
	/* 0xcff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d04:
	/* 0xd04: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d09:
	/* 0xd09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d0e:
	/* 0xd0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d10:
	/* 0xd10: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d15:
	/* 0xd15: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d1d:
	/* 0xd1d: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d21:
	/* 0xd21: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d29:
	/* 0xd29: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d2b:
	/* 0xd2b: mov    QWORD PTR [rsp+0xd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d33:
	/* 0xd33: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d3b:
	/* 0xd3b: mov    QWORD PTR [rsp+0xb0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d43:
	/* 0xd43: jne    d4d <trace_security_file_mprotect+0xd4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4d;
	}
x86_l_d45:
	/* 0xd45: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d48:
	/* 0xd48: jmp    1516 <trace_security_file_mprotect+0x1516> */
	return 5398ULL;
x86_l_d4d:
	/* 0xd4d: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d54:
	/* 0xd54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d57:
	/* 0xd57: je     f0c <trace_security_file_mprotect+0xf0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f0c;
	}
x86_l_d5d:
	/* 0xd5d: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d65:
	/* 0xd65: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d68:
	/* 0xd68: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6b:
	/* 0xd6b: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d6e:
	/* 0xd6e: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_d72:
	/* 0xd72: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d75:
	/* 0xd75: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d78:
	/* 0xd78: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d7f:
	/* 0xd7f: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d82:
	/* 0xd82: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d89:
	/* 0xd89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8c:
	/* 0xd8c: je     dae <trace_security_file_mprotect+0xdae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dae;
	}
x86_l_d8e:
	/* 0xd8e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d90:
	/* 0xd90: cmp    BYTE PTR [r13+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d98:
	/* 0xd98: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d9b:
	/* 0xd9b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d9e:
	/* 0xd9e: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_da1:
	/* 0xda1: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_da8:
	/* 0xda8: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dab:
	/* 0xdab: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dae:
	/* 0xdae: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_db5:
	/* 0xdb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: je     dd4 <trace_security_file_mprotect+0xdd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd4;
	}
x86_l_dba:
	/* 0xdba: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_dbe:
	/* 0xdbe: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dc1:
	/* 0xdc1: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_dc4:
	/* 0xdc4: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_dc7:
	/* 0xdc7: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_dce:
	/* 0xdce: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dd1:
	/* 0xdd1: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dd4:
	/* 0xdd4: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_ddb:
	/* 0xddb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: je     dff <trace_security_file_mprotect+0xdff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dff;
	}
x86_l_de0:
	/* 0xde0: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_de3:
	/* 0xde3: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_deb:
	/* 0xdeb: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_def:
	/* 0xdef: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_df2:
	/* 0xdf2: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_df9:
	/* 0xdf9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dfc:
	/* 0xdfc: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dff:
	/* 0xdff: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_e04:
	/* 0xe04: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_e0b:
	/* 0xe0b: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e16:
	/* 0xe16: je     f77 <trace_security_file_mprotect+0xf77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3959ULL;
	}
x86_l_e1c:
	/* 0xe1c: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e23:
	/* 0xe23: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e2b:
	/* 0xe2b: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e32:
	/* 0xe32: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e3a:
	/* 0xe3a: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e41:
	/* 0xe41: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e49:
	/* 0xe49: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e4e:
	/* 0xe4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e53:
	/* 0xe53: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e5a:
	/* 0xe5a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e5f:
	/* 0xe5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e61:
	/* 0xe61: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e64:
	/* 0xe64: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e68:
	/* 0xe68: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e6d:
	/* 0xe6d: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e74:
	/* 0xe74: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e77:
	/* 0xe77: je     e99 <trace_security_file_mprotect+0xe99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e99;
	}
x86_l_e79:
	/* 0xe79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7e:
	/* 0xe7e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e83:
	/* 0xe83: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e88:
	/* 0xe88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e8b:
	/* 0xe8b: je     e99 <trace_security_file_mprotect+0xe99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e99;
	}
x86_l_e8d:
	/* 0xe8d: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e90:
	/* 0xe90: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e94:
	/* 0xe94: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e97:
	/* 0xe97: jmp    e9c <trace_security_file_mprotect+0xe9c> */
	goto x86_l_e9c;
x86_l_e99:
	/* 0xe99: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9c:
	/* 0xe9c: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ea4:
	/* 0xea4: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_eac:
	/* 0xeac: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eb1:
	/* 0xeb1: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_eb4:
	/* 0xeb4: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: jb     ecf <trace_security_file_mprotect+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ecf;
	}
x86_l_eb9:
	/* 0xeb9: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ebd:
	/* 0xebd: je     ec4 <trace_security_file_mprotect+0xec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec4;
	}
x86_l_ebf:
	/* 0xebf: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ec2:
	/* 0xec2: jbe    ecf <trace_security_file_mprotect+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ecf;
	}
x86_l_ec4:
	/* 0xec4: and    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 200ULL);
x86_l_ecc:
	/* 0xecc: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_ecf:
	/* 0xecf: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ed3:
	/* 0xed3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ed8:
	/* 0xed8: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_edf:
	/* 0xedf: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_ee2:
	/* 0xee2: je     f28 <trace_security_file_mprotect+0xf28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f28;
	}
x86_l_ee4:
	/* 0xee4: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_eec:
	/* 0xeec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef1:
	/* 0xef1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef6:
	/* 0xef6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ef9:
	/* 0xef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efb:
	/* 0xefb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_efe:
	/* 0xefe: je     f39 <trace_security_file_mprotect+0xf39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f39;
	}
x86_l_f00:
	/* 0xf00: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f03:
	/* 0xf03: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f07:
	/* 0xf07: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f0a:
	/* 0xf0a: jmp    f3b <trace_security_file_mprotect+0xf3b> */
	goto x86_l_f3b;
x86_l_f0c:
	/* 0xf0c: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f13:
	/* 0xf13: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_f1a:
	/* 0xf1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1d:
	/* 0xf1d: jne    d8e <trace_security_file_mprotect+0xd8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d8e;
	}
x86_l_f23:
	/* 0xf23: jmp    dae <trace_security_file_mprotect+0xdae> */
	goto x86_l_dae;
x86_l_f28:
	/* 0xf28: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2a:
	/* 0xf2a: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f2d:
	/* 0xf2d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f32:
	/* 0xf32: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f35:
	/* 0xf35: jae    f58 <trace_security_file_mprotect+0xf58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3928ULL;
	}
x86_l_f37:
	/* 0xf37: jmp    f6e <trace_security_file_mprotect+0xf6e> */
	return 3950ULL;
x86_l_f39:
	/* 0xf39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f3b:
	/* 0xf3b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
	return 3907ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3907ULL: goto x86_l_f43;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3932ULL: goto x86_l_f5c;
	case 3934ULL: goto x86_l_f5e;
	case 3937ULL: goto x86_l_f61;
	case 3939ULL: goto x86_l_f63;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3959ULL: goto x86_l_f77;
	case 3967ULL: goto x86_l_f7f;
	case 3973ULL: goto x86_l_f85;
	case 3978ULL: goto x86_l_f8a;
	case 3980ULL: goto x86_l_f8c;
	case 3984ULL: goto x86_l_f90;
	case 3991ULL: goto x86_l_f97;
	case 3998ULL: goto x86_l_f9e;
	case 4006ULL: goto x86_l_fa6;
	case 4013ULL: goto x86_l_fad;
	case 4020ULL: goto x86_l_fb4;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4052ULL: goto x86_l_fd4;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4068ULL: goto x86_l_fe4;
	case 4071ULL: goto x86_l_fe7;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4086ULL: goto x86_l_ff6;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4105ULL: goto x86_l_1009;
	case 4107ULL: goto x86_l_100b;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4118ULL: goto x86_l_1016;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4141ULL: goto x86_l_102d;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4160ULL: goto x86_l_1040;
	case 4168ULL: goto x86_l_1048;
	case 4170ULL: goto x86_l_104a;
	case 4173ULL: goto x86_l_104d;
	case 4175ULL: goto x86_l_104f;
	case 4183ULL: goto x86_l_1057;
	case 4186ULL: goto x86_l_105a;
	case 4189ULL: goto x86_l_105d;
	case 4192ULL: goto x86_l_1060;
	case 4200ULL: goto x86_l_1068;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4244ULL: goto x86_l_1094;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4287ULL: goto x86_l_10bf;
	case 4291ULL: goto x86_l_10c3;
	case 4298ULL: goto x86_l_10ca;
	case 4305ULL: goto x86_l_10d1;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4332ULL: goto x86_l_10ec;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4377ULL: goto x86_l_1119;
	case 4380ULL: goto x86_l_111c;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4397ULL: goto x86_l_112d;
	case 4403ULL: goto x86_l_1133;
	case 4410ULL: goto x86_l_113a;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4454ULL: goto x86_l_1166;
	case 4456ULL: goto x86_l_1168;
	case 4460ULL: goto x86_l_116c;
	case 4464ULL: goto x86_l_1170;
	case 4468ULL: goto x86_l_1174;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4530ULL: goto x86_l_11b2;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4571ULL: goto x86_l_11db;
	case 4574ULL: goto x86_l_11de;
	case 4576ULL: goto x86_l_11e0;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4612ULL: goto x86_l_1204;
	case 4615ULL: goto x86_l_1207;
	case 4618ULL: goto x86_l_120a;
	case 4621ULL: goto x86_l_120d;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4711ULL: goto x86_l_1267;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4740ULL: goto x86_l_1284;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4774ULL: goto x86_l_12a6;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4802ULL: goto x86_l_12c2;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4811ULL: goto x86_l_12cb;
	case 4814ULL: goto x86_l_12ce;
	case 4816ULL: goto x86_l_12d0;
	case 4818ULL: goto x86_l_12d2;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4830ULL: goto x86_l_12de;
	case 4838ULL: goto x86_l_12e6;
	case 4846ULL: goto x86_l_12ee;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4878ULL: goto x86_l_130e;
	case 4885ULL: goto x86_l_1315;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4937ULL: goto x86_l_1349;
	case 4940ULL: goto x86_l_134c;
	case 4942ULL: goto x86_l_134e;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4956ULL: goto x86_l_135c;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4965ULL: goto x86_l_1365;
	case 4968ULL: goto x86_l_1368;
	case 4976ULL: goto x86_l_1370;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4992ULL: goto x86_l_1380;
	case 4996ULL: goto x86_l_1384;
	case 5003ULL: goto x86_l_138b;
	case 5006ULL: goto x86_l_138e;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5030ULL: goto x86_l_13a6;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5060ULL: goto x86_l_13c4;
	case 5062ULL: goto x86_l_13c6;
	case 5065ULL: goto x86_l_13c9;
	case 5069ULL: goto x86_l_13cd;
	case 5072ULL: goto x86_l_13d0;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5134ULL: goto x86_l_140e;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5154ULL: goto x86_l_1422;
	case 5162ULL: goto x86_l_142a;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5176ULL: goto x86_l_1438;
	case 5179ULL: goto x86_l_143b;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5195ULL: goto x86_l_144b;
	case 5202ULL: goto x86_l_1452;
	case 5205ULL: goto x86_l_1455;
	case 5211ULL: goto x86_l_145b;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5252ULL: goto x86_l_1484;
	case 5255ULL: goto x86_l_1487;
	case 5257ULL: goto x86_l_1489;
	case 5260ULL: goto x86_l_148c;
	case 5268ULL: goto x86_l_1494;
	case 5272ULL: goto x86_l_1498;
	case 5277ULL: goto x86_l_149d;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5317ULL: goto x86_l_14c5;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5358ULL: goto x86_l_14ee;
	case 5366ULL: goto x86_l_14f6;
	case 5374ULL: goto x86_l_14fe;
	case 5376ULL: goto x86_l_1500;
	case 5384ULL: goto x86_l_1508;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5398ULL: goto x86_l_1516;
	case 5405ULL: goto x86_l_151d;
	case 5409ULL: goto x86_l_1521;
	case 5417ULL: goto x86_l_1529;
	case 5424ULL: goto x86_l_1530;
	case 5432ULL: goto x86_l_1538;
	case 5438ULL: goto x86_l_153e;
	case 5446ULL: goto x86_l_1546;
	case 5455ULL: goto x86_l_154f;
	case 5464ULL: goto x86_l_1558;
	case 5473ULL: goto x86_l_1561;
	case 5482ULL: goto x86_l_156a;
	case 5491ULL: goto x86_l_1573;
	case 5500ULL: goto x86_l_157c;
	case 5509ULL: goto x86_l_1585;
	case 5514ULL: goto x86_l_158a;
	case 5517ULL: goto x86_l_158d;
	case 5523ULL: goto x86_l_1593;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5550ULL: goto x86_l_15ae;
	case 5553ULL: goto x86_l_15b1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f43:
	/* 0xf43: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f4b:
	/* 0xf4b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f4e:
	/* 0xf4e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f53:
	/* 0xf53: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: jb     f6e <trace_security_file_mprotect+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f6e;
	}
x86_l_f58:
	/* 0xf58: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f5c:
	/* 0xf5c: je     f63 <trace_security_file_mprotect+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f63;
	}
x86_l_f5e:
	/* 0xf5e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f61:
	/* 0xf61: jbe    f6e <trace_security_file_mprotect+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f6e;
	}
x86_l_f63:
	/* 0xf63: and    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 200ULL);
x86_l_f6b:
	/* 0xf6b: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_f6e:
	/* 0xf6e: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_f71:
	/* 0xf71: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f74:
	/* 0xf74: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f77:
	/* 0xf77: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f7f:
	/* 0xf7f: je     1025 <trace_security_file_mprotect+0x1025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1025;
	}
x86_l_f85:
	/* 0xf85: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f8a:
	/* 0xf8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8c:
	/* 0xf8c: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f90:
	/* 0xf90: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_f97:
	/* 0xf97: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f9e:
	/* 0xf9e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fa6:
	/* 0xfa6: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_fad:
	/* 0xfad: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_fb4:
	/* 0xfb4: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_fbc:
	/* 0xfbc: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc1:
	/* 0xfc1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc6:
	/* 0xfc6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_fcd:
	/* 0xfcd: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd2:
	/* 0xfd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd4:
	/* 0xfd4: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd8:
	/* 0xfd8: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fdd:
	/* 0xfdd: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fe4:
	/* 0xfe4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe7:
	/* 0xfe7: je     1009 <trace_security_file_mprotect+0x1009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1009;
	}
x86_l_fe9:
	/* 0xfe9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fee:
	/* 0xfee: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ff3:
	/* 0xff3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ff6:
	/* 0xff6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ff8:
	/* 0xff8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: je     1009 <trace_security_file_mprotect+0x1009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1009;
	}
x86_l_ffd:
	/* 0xffd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1000:
	/* 0x1000: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1004:
	/* 0x1004: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1007:
	/* 0x1007: jmp    100b <trace_security_file_mprotect+0x100b> */
	goto x86_l_100b;
x86_l_1009:
	/* 0x1009: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100b:
	/* 0x100b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_100e:
	/* 0x100e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1013:
	/* 0x1013: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1016:
	/* 0x1016: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1019:
	/* 0x1019: jae    103c <trace_security_file_mprotect+0x103c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_103c;
	}
x86_l_101b:
	/* 0x101b: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1023:
	/* 0x1023: jmp    105a <trace_security_file_mprotect+0x105a> */
	goto x86_l_105a;
x86_l_1025:
	/* 0x1025: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_102d:
	/* 0x102d: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1035:
	/* 0x1035: jne    106e <trace_security_file_mprotect+0x106e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_106e;
	}
x86_l_1037:
	/* 0x1037: jmp    1125 <trace_security_file_mprotect+0x1125> */
	goto x86_l_1125;
x86_l_103c:
	/* 0x103c: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1040:
	/* 0x1040: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1048:
	/* 0x1048: je     104f <trace_security_file_mprotect+0x104f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104f;
	}
x86_l_104a:
	/* 0x104a: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_104d:
	/* 0x104d: jbe    105a <trace_security_file_mprotect+0x105a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_105a;
	}
x86_l_104f:
	/* 0x104f: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1057:
	/* 0x1057: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_105a:
	/* 0x105a: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_105d:
	/* 0x105d: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1060:
	/* 0x1060: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1068:
	/* 0x1068: je     1125 <trace_security_file_mprotect+0x1125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1125;
	}
x86_l_106e:
	/* 0x106e: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1073:
	/* 0x1073: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_107a:
	/* 0x107a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107f:
	/* 0x107f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1084:
	/* 0x1084: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1089:
	/* 0x1089: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108b:
	/* 0x108b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1090:
	/* 0x1090: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1094:
	/* 0x1094: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1099:
	/* 0x1099: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109e:
	/* 0x109e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10a3:
	/* 0x10a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a5:
	/* 0x10a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10aa:
	/* 0x10aa: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10af:
	/* 0x10af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b4:
	/* 0x10b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10b9:
	/* 0x10b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bb:
	/* 0x10bb: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bf:
	/* 0x10bf: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10c3:
	/* 0x10c3: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_10ca:
	/* 0x10ca: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_10d1:
	/* 0x10d1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10d4:
	/* 0x10d4: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d9:
	/* 0x10d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10de:
	/* 0x10de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_10e5:
	/* 0x10e5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ea:
	/* 0x10ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ec:
	/* 0x10ec: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10f3:
	/* 0x10f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: je     1117 <trace_security_file_mprotect+0x1117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1117;
	}
x86_l_10f8:
	/* 0x10f8: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10fc:
	/* 0x10fc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1101:
	/* 0x1101: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1104:
	/* 0x1104: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1106:
	/* 0x1106: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1109:
	/* 0x1109: je     1117 <trace_security_file_mprotect+0x1117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1117;
	}
x86_l_110b:
	/* 0x110b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110e:
	/* 0x110e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1112:
	/* 0x1112: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1115:
	/* 0x1115: jmp    1119 <trace_security_file_mprotect+0x1119> */
	goto x86_l_1119;
x86_l_1117:
	/* 0x1117: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1119:
	/* 0x1119: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_111c:
	/* 0x111c: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_111f:
	/* 0x111f: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1122:
	/* 0x1122: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1125:
	/* 0x1125: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_112d:
	/* 0x112d: je     120d <trace_security_file_mprotect+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120d;
	}
x86_l_1133:
	/* 0x1133: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_113a:
	/* 0x113a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_113e:
	/* 0x113e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1143:
	/* 0x1143: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1148:
	/* 0x1148: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_114d:
	/* 0x114d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114f:
	/* 0x114f: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1154:
	/* 0x1154: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1159:
	/* 0x1159: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_115e:
	/* 0x115e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1163:
	/* 0x1163: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1166:
	/* 0x1166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1168:
	/* 0x1168: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_116c:
	/* 0x116c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1170:
	/* 0x1170: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1174:
	/* 0x1174: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1178:
	/* 0x1178: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_117d:
	/* 0x117d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1182:
	/* 0x1182: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1187:
	/* 0x1187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1189:
	/* 0x1189: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_118e:
	/* 0x118e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1192:
	/* 0x1192: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1197:
	/* 0x1197: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_119c:
	/* 0x119c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11a1:
	/* 0x11a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a3:
	/* 0x11a3: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11a7:
	/* 0x11a7: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11ab:
	/* 0x11ab: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_11b2:
	/* 0x11b2: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_11b9:
	/* 0x11b9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11bc:
	/* 0x11bc: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11c1:
	/* 0x11c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11c6:
	/* 0x11c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_11cd:
	/* 0x11cd: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11d2:
	/* 0x11d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d4:
	/* 0x11d4: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11db:
	/* 0x11db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11de:
	/* 0x11de: je     11ff <trace_security_file_mprotect+0x11ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ff;
	}
x86_l_11e0:
	/* 0x11e0: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11e4:
	/* 0x11e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e9:
	/* 0x11e9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11ec:
	/* 0x11ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11ee:
	/* 0x11ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: je     11ff <trace_security_file_mprotect+0x11ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ff;
	}
x86_l_11f3:
	/* 0x11f3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f6:
	/* 0x11f6: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11fa:
	/* 0x11fa: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11fd:
	/* 0x11fd: jmp    1201 <trace_security_file_mprotect+0x1201> */
	goto x86_l_1201;
x86_l_11ff:
	/* 0x11ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1201:
	/* 0x1201: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1204:
	/* 0x1204: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1207:
	/* 0x1207: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_120a:
	/* 0x120a: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_120d:
	/* 0x120d: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1215:
	/* 0x1215: je     12e6 <trace_security_file_mprotect+0x12e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e6;
	}
x86_l_121b:
	/* 0x121b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1220:
	/* 0x1220: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1227:
	/* 0x1227: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_122c:
	/* 0x122c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1231:
	/* 0x1231: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1236:
	/* 0x1236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1238:
	/* 0x1238: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_123d:
	/* 0x123d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1242:
	/* 0x1242: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1247:
	/* 0x1247: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_124c:
	/* 0x124c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124e:
	/* 0x124e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1253:
	/* 0x1253: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1258:
	/* 0x1258: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_125d:
	/* 0x125d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1260:
	/* 0x1260: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1265:
	/* 0x1265: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1267:
	/* 0x1267: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_126b:
	/* 0x126b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1270:
	/* 0x1270: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1273:
	/* 0x1273: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1278:
	/* 0x1278: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127d:
	/* 0x127d: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1284:
	/* 0x1284: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_128b:
	/* 0x128b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_128e:
	/* 0x128e: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1293:
	/* 0x1293: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1298:
	/* 0x1298: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_129f:
	/* 0x129f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a4:
	/* 0x12a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a6:
	/* 0x12a6: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12ad:
	/* 0x12ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: je     12d0 <trace_security_file_mprotect+0x12d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d0;
	}
x86_l_12b2:
	/* 0x12b2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12b7:
	/* 0x12b7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12ba:
	/* 0x12ba: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_12bd:
	/* 0x12bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12bf:
	/* 0x12bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c2:
	/* 0x12c2: je     12d0 <trace_security_file_mprotect+0x12d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d0;
	}
x86_l_12c4:
	/* 0x12c4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c7:
	/* 0x12c7: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cb:
	/* 0x12cb: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12ce:
	/* 0x12ce: jmp    12d2 <trace_security_file_mprotect+0x12d2> */
	goto x86_l_12d2;
x86_l_12d0:
	/* 0x12d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d2:
	/* 0x12d2: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12d5:
	/* 0x12d5: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12d8:
	/* 0x12d8: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12db:
	/* 0x12db: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_12de:
	/* 0x12de: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_12e6:
	/* 0x12e6: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12ee:
	/* 0x12ee: je     1370 <trace_security_file_mprotect+0x1370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1370;
	}
x86_l_12f4:
	/* 0x12f4: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12f8:
	/* 0x12f8: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1305:
	/* 0x1305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1307:
	/* 0x1307: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_130e:
	/* 0x130e: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1315:
	/* 0x1315: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1318:
	/* 0x1318: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_131d:
	/* 0x131d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1322:
	/* 0x1322: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1329:
	/* 0x1329: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_132e:
	/* 0x132e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1330:
	/* 0x1330: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1337:
	/* 0x1337: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_133a:
	/* 0x133a: je     135a <trace_security_file_mprotect+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135a;
	}
x86_l_133c:
	/* 0x133c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1341:
	/* 0x1341: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1347:
	/* 0x1347: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1349:
	/* 0x1349: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_134c:
	/* 0x134c: je     135a <trace_security_file_mprotect+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135a;
	}
x86_l_134e:
	/* 0x134e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1351:
	/* 0x1351: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1355:
	/* 0x1355: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1358:
	/* 0x1358: jmp    135c <trace_security_file_mprotect+0x135c> */
	goto x86_l_135c;
x86_l_135a:
	/* 0x135a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_135c:
	/* 0x135c: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_135f:
	/* 0x135f: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1362:
	/* 0x1362: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1365:
	/* 0x1365: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1368:
	/* 0x1368: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1370:
	/* 0x1370: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1377:
	/* 0x1377: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_137a:
	/* 0x137a: je     13e0 <trace_security_file_mprotect+0x13e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e0;
	}
x86_l_137c:
	/* 0x137c: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1380:
	/* 0x1380: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1384:
	/* 0x1384: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_138b:
	/* 0x138b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_138e:
	/* 0x138e: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1393:
	/* 0x1393: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1398:
	/* 0x1398: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_139f:
	/* 0x139f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a4:
	/* 0x13a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a6:
	/* 0x13a6: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13ad:
	/* 0x13ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: je     13d2 <trace_security_file_mprotect+0x13d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d2;
	}
x86_l_13b2:
	/* 0x13b2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13b7:
	/* 0x13b7: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13bc:
	/* 0x13bc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13bf:
	/* 0x13bf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13c1:
	/* 0x13c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c4:
	/* 0x13c4: je     13d2 <trace_security_file_mprotect+0x13d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d2;
	}
x86_l_13c6:
	/* 0x13c6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c9:
	/* 0x13c9: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13cd:
	/* 0x13cd: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d0:
	/* 0x13d0: jmp    13d4 <trace_security_file_mprotect+0x13d4> */
	goto x86_l_13d4;
x86_l_13d2:
	/* 0x13d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d4:
	/* 0x13d4: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13d7:
	/* 0x13d7: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_13da:
	/* 0x13da: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13dd:
	/* 0x13dd: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13e0:
	/* 0x13e0: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13e7:
	/* 0x13e7: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: je     144b <trace_security_file_mprotect+0x144b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_144b;
	}
x86_l_13ec:
	/* 0x13ec: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13f3:
	/* 0x13f3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13f6:
	/* 0x13f6: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13fb:
	/* 0x13fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1400:
	/* 0x1400: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1407:
	/* 0x1407: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_140c:
	/* 0x140c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140e:
	/* 0x140e: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1415:
	/* 0x1415: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: je     143d <trace_security_file_mprotect+0x143d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_143d;
	}
x86_l_141a:
	/* 0x141a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_141f:
	/* 0x141f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1422:
	/* 0x1422: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_142a:
	/* 0x142a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_142c:
	/* 0x142c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142f:
	/* 0x142f: je     143d <trace_security_file_mprotect+0x143d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_143d;
	}
x86_l_1431:
	/* 0x1431: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1434:
	/* 0x1434: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1438:
	/* 0x1438: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_143b:
	/* 0x143b: jmp    143f <trace_security_file_mprotect+0x143f> */
	goto x86_l_143f;
x86_l_143d:
	/* 0x143d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143f:
	/* 0x143f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1442:
	/* 0x1442: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1445:
	/* 0x1445: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1448:
	/* 0x1448: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_144b:
	/* 0x144b: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1452:
	/* 0x1452: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1455:
	/* 0x1455: je     14dc <trace_security_file_mprotect+0x14dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14dc;
	}
x86_l_145b:
	/* 0x145b: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1462:
	/* 0x1462: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1465:
	/* 0x1465: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146a:
	/* 0x146a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_146f:
	/* 0x146f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1476:
	/* 0x1476: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147b:
	/* 0x147b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147d:
	/* 0x147d: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1484:
	/* 0x1484: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1487:
	/* 0x1487: je     14ce <trace_security_file_mprotect+0x14ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ce;
	}
x86_l_1489:
	/* 0x1489: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_148c:
	/* 0x148c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1494:
	/* 0x1494: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1498:
	/* 0x1498: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_149d:
	/* 0x149d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14a0:
	/* 0x14a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a2:
	/* 0x14a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a5:
	/* 0x14a5: jne    14c2 <trace_security_file_mprotect+0x14c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14c2;
	}
x86_l_14a7:
	/* 0x14a7: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14af:
	/* 0x14af: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b3:
	/* 0x14b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b8:
	/* 0x14b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bd:
	/* 0x14bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c0:
	/* 0x14c0: je     14ce <trace_security_file_mprotect+0x14ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ce;
	}
x86_l_14c2:
	/* 0x14c2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c5:
	/* 0x14c5: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c9:
	/* 0x14c9: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14cc:
	/* 0x14cc: jmp    14d0 <trace_security_file_mprotect+0x14d0> */
	goto x86_l_14d0;
x86_l_14ce:
	/* 0x14ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d0:
	/* 0x14d0: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d3:
	/* 0x14d3: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_14d6:
	/* 0x14d6: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d9:
	/* 0x14d9: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_14dc:
	/* 0x14dc: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14e3:
	/* 0x14e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e6:
	/* 0x14e6: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14ee:
	/* 0x14ee: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14f6:
	/* 0x14f6: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14fe:
	/* 0x14fe: je     150f <trace_security_file_mprotect+0x150f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150f;
	}
x86_l_1500:
	/* 0x1500: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1508:
	/* 0x1508: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_150c:
	/* 0x150c: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_150f:
	/* 0x150f: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1516:
	/* 0x1516: lea    rcx,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_151d:
	/* 0x151d: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1521:
	/* 0x1521: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1529:
	/* 0x1529: and    QWORD PTR [r14+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1530:
	/* 0x1530: mov    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1538:
	/* 0x1538: je     2185 <trace_security_file_mprotect+0x2185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8581ULL;
	}
x86_l_153e:
	/* 0x153e: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1546:
	/* 0x1546: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_154f:
	/* 0x154f: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1558:
	/* 0x1558: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1561:
	/* 0x1561: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_156a:
	/* 0x156a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1573:
	/* 0x1573: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_157c:
	/* 0x157c: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1585:
	/* 0x1585: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_158a:
	/* 0x158a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_158d:
	/* 0x158d: je     16dd <trace_security_file_mprotect+0x16dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5853ULL;
	}
x86_l_1593:
	/* 0x1593: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_159b:
	/* 0x159b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a0:
	/* 0x15a0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_15a7:
	/* 0x15a7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ac:
	/* 0x15ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ae:
	/* 0x15ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b1:
	/* 0x15b1: je     16ec <trace_security_file_mprotect+0x16ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5868ULL;
	}
	return 5559ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5559ULL: goto x86_l_15b7;
	case 5562ULL: goto x86_l_15ba;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5603ULL: goto x86_l_15e3;
	case 5608ULL: goto x86_l_15e8;
	case 5613ULL: goto x86_l_15ed;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5626ULL: goto x86_l_15fa;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5818ULL: goto x86_l_16ba;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5834ULL: goto x86_l_16ca;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5895ULL: goto x86_l_1707;
	case 5901ULL: goto x86_l_170d;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5950ULL: goto x86_l_173e;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6054ULL: goto x86_l_17a6;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6064ULL: goto x86_l_17b0;
	case 6066ULL: goto x86_l_17b2;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6087ULL: goto x86_l_17c7;
	case 6091ULL: goto x86_l_17cb;
	case 6093ULL: goto x86_l_17cd;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6126ULL: goto x86_l_17ee;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6141ULL: goto x86_l_17fd;
	case 6145ULL: goto x86_l_1801;
	case 6151ULL: goto x86_l_1807;
	case 6155ULL: goto x86_l_180b;
	case 6158ULL: goto x86_l_180e;
	case 6163ULL: goto x86_l_1813;
	case 6168ULL: goto x86_l_1818;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6189ULL: goto x86_l_182d;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6241ULL: goto x86_l_1861;
	case 6244ULL: goto x86_l_1864;
	case 6251ULL: goto x86_l_186b;
	case 6254ULL: goto x86_l_186e;
	case 6258ULL: goto x86_l_1872;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6276ULL: goto x86_l_1884;
	case 6278ULL: goto x86_l_1886;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6301ULL: goto x86_l_189d;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6385ULL: goto x86_l_18f1;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6426ULL: goto x86_l_191a;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6454ULL: goto x86_l_1936;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6568ULL: goto x86_l_19a8;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6586ULL: goto x86_l_19ba;
	case 6594ULL: goto x86_l_19c2;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6667ULL: goto x86_l_1a0b;
	case 6675ULL: goto x86_l_1a13;
	case 6686ULL: goto x86_l_1a1e;
	case 6694ULL: goto x86_l_1a26;
	case 6702ULL: goto x86_l_1a2e;
	case 6710ULL: goto x86_l_1a36;
	case 6716ULL: goto x86_l_1a3c;
	case 6718ULL: goto x86_l_1a3e;
	case 6727ULL: goto x86_l_1a47;
	case 6735ULL: goto x86_l_1a4f;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6763ULL: goto x86_l_1a6b;
	case 6767ULL: goto x86_l_1a6f;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6782ULL: goto x86_l_1a7e;
	case 6784ULL: goto x86_l_1a80;
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6796ULL: goto x86_l_1a8c;
	case 6803ULL: goto x86_l_1a93;
	case 6805ULL: goto x86_l_1a95;
	case 6813ULL: goto x86_l_1a9d;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6832ULL: goto x86_l_1ab0;
	case 6839ULL: goto x86_l_1ab7;
	case 6847ULL: goto x86_l_1abf;
	case 6854ULL: goto x86_l_1ac6;
	case 6856ULL: goto x86_l_1ac8;
	case 6865ULL: goto x86_l_1ad1;
	case 6871ULL: goto x86_l_1ad7;
	case 6873ULL: goto x86_l_1ad9;
	case 6877ULL: goto x86_l_1add;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6909ULL: goto x86_l_1afd;
	case 6912ULL: goto x86_l_1b00;
	case 6920ULL: goto x86_l_1b08;
	case 6927ULL: goto x86_l_1b0f;
	case 6935ULL: goto x86_l_1b17;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6961ULL: goto x86_l_1b31;
	case 6969ULL: goto x86_l_1b39;
	case 6973ULL: goto x86_l_1b3d;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6995ULL: goto x86_l_1b53;
	case 6997ULL: goto x86_l_1b55;
	case 7000ULL: goto x86_l_1b58;
	case 7008ULL: goto x86_l_1b60;
	case 7015ULL: goto x86_l_1b67;
	case 7023ULL: goto x86_l_1b6f;
	case 7030ULL: goto x86_l_1b76;
	case 7032ULL: goto x86_l_1b78;
	case 7041ULL: goto x86_l_1b81;
	case 7047ULL: goto x86_l_1b87;
	case 7049ULL: goto x86_l_1b89;
	case 7053ULL: goto x86_l_1b8d;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7096ULL: goto x86_l_1bb8;
	case 7103ULL: goto x86_l_1bbf;
	case 7111ULL: goto x86_l_1bc7;
	case 7118ULL: goto x86_l_1bce;
	case 7120ULL: goto x86_l_1bd0;
	case 7129ULL: goto x86_l_1bd9;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7141ULL: goto x86_l_1be5;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7184ULL: goto x86_l_1c10;
	case 7191ULL: goto x86_l_1c17;
	case 7199ULL: goto x86_l_1c1f;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7229ULL: goto x86_l_1c3d;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7272ULL: goto x86_l_1c68;
	case 7279ULL: goto x86_l_1c6f;
	case 7287ULL: goto x86_l_1c77;
	case 7293ULL: goto x86_l_1c7d;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7363ULL: goto x86_l_1cc3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15b7:
	/* 0x15b7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15ba:
	/* 0x15ba: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15be:
	/* 0x15be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15c3:
	/* 0x15c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c8:
	/* 0x15c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15cd:
	/* 0x15cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cf:
	/* 0x15cf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d4:
	/* 0x15d4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d9:
	/* 0x15d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15de:
	/* 0x15de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e3:
	/* 0x15e3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e8:
	/* 0x15e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15ed:
	/* 0x15ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ef:
	/* 0x15ef: test   BYTE PTR [rsp+0x10],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476768ULL);
x86_l_15f4:
	/* 0x15f4: jne    16f3 <trace_security_file_mprotect+0x16f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f3;
	}
x86_l_15fa:
	/* 0x15fa: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1603:
	/* 0x1603: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1608:
	/* 0x1608: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_160d:
	/* 0x160d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160f:
	/* 0x160f: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1614:
	/* 0x1614: lea    rax,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_1618:
	/* 0x1618: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161c:
	/* 0x161c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1621:
	/* 0x1621: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1625:
	/* 0x1625: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_162a:
	/* 0x162a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1636:
	/* 0x1636: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_163b:
	/* 0x163b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1640:
	/* 0x1640: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1643:
	/* 0x1643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1645:
	/* 0x1645: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164a:
	/* 0x164a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_164f:
	/* 0x164f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1653:
	/* 0x1653: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1658:
	/* 0x1658: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165d:
	/* 0x165d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1662:
	/* 0x1662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1664:
	/* 0x1664: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1669:
	/* 0x1669: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_166c:
	/* 0x166c: je     1704 <trace_security_file_mprotect+0x1704> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1704;
	}
x86_l_1672:
	/* 0x1672: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1677:
	/* 0x1677: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_167a:
	/* 0x167a: je     1704 <trace_security_file_mprotect+0x1704> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1704;
	}
x86_l_1680:
	/* 0x1680: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1684:
	/* 0x1684: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1689:
	/* 0x1689: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168e:
	/* 0x168e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1693:
	/* 0x1693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1695:
	/* 0x1695: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1699:
	/* 0x1699: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_169e:
	/* 0x169e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_16a0:
	/* 0x16a0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a6:
	/* 0x16a6: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_16a8:
	/* 0x16a8: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_16aa:
	/* 0x16aa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16b0:
	/* 0x16b0: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b3:
	/* 0x16b3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_16b8:
	/* 0x16b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ba:
	/* 0x16ba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16bd:
	/* 0x16bd: jl     1833 <trace_security_file_mprotect+0x1833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1833;
	}
x86_l_16c3:
	/* 0x16c3: mov    BYTE PTR [rbx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_16ca:
	/* 0x16ca: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_16d0:
	/* 0x16d0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16d3:
	/* 0x16d3: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d8:
	/* 0x16d8: jmp    176b <trace_security_file_mprotect+0x176b> */
	goto x86_l_176b;
x86_l_16dd:
	/* 0x16dd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e0:
	/* 0x16e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e2:
	/* 0x16e2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e5:
	/* 0x16e5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e7:
	/* 0x16e7: jmp    19a8 <trace_security_file_mprotect+0x19a8> */
	goto x86_l_19a8;
x86_l_16ec:
	/* 0x16ec: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ee:
	/* 0x16ee: jmp    186e <trace_security_file_mprotect+0x186e> */
	goto x86_l_186e;
x86_l_16f3:
	/* 0x16f3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_16f8:
	/* 0x16f8: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_16ff:
	/* 0x16ff: jmp    1857 <trace_security_file_mprotect+0x1857> */
	goto x86_l_1857;
x86_l_1704:
	/* 0x1704: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1707:
	/* 0x1707: jne    1833 <trace_security_file_mprotect+0x1833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1833;
	}
x86_l_170d:
	/* 0x170d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1711:
	/* 0x1711: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1716:
	/* 0x1716: je     1833 <trace_security_file_mprotect+0x1833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1833;
	}
x86_l_171c:
	/* 0x171c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1721:
	/* 0x1721: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1725:
	/* 0x1725: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1729:
	/* 0x1729: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172e:
	/* 0x172e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1733:
	/* 0x1733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1735:
	/* 0x1735: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_173a:
	/* 0x173a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173e:
	/* 0x173e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1741:
	/* 0x1741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_174d:
	/* 0x174d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1751:
	/* 0x1751: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1756:
	/* 0x1756: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175b:
	/* 0x175b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175d:
	/* 0x175d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1761:
	/* 0x1761: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1765:
	/* 0x1765: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_176b:
	/* 0x176b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1770:
	/* 0x1770: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1775:
	/* 0x1775: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177a:
	/* 0x177a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_177d:
	/* 0x177d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177f:
	/* 0x177f: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1784:
	/* 0x1784: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1789:
	/* 0x1789: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_178d:
	/* 0x178d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1792:
	/* 0x1792: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1797:
	/* 0x1797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179c:
	/* 0x179c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179e:
	/* 0x179e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a3:
	/* 0x17a3: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_17a6:
	/* 0x17a6: je     1818 <trace_security_file_mprotect+0x1818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1818;
	}
x86_l_17a8:
	/* 0x17a8: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ad:
	/* 0x17ad: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_17b0:
	/* 0x17b0: je     1818 <trace_security_file_mprotect+0x1818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1818;
	}
x86_l_17b2:
	/* 0x17b2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17b6:
	/* 0x17b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17bb:
	/* 0x17bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c0:
	/* 0x17c0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17c5:
	/* 0x17c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c7:
	/* 0x17c7: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17cb:
	/* 0x17cb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_17cd:
	/* 0x17cd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d3:
	/* 0x17d3: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_17d6:
	/* 0x17d6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17d8:
	/* 0x17d8: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17dd:
	/* 0x17dd: jb     2e47 <trace_security_file_mprotect+0x2e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11847ULL;
	}
x86_l_17e3:
	/* 0x17e3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17e8:
	/* 0x17e8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_17ee:
	/* 0x17ee: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17f1:
	/* 0x17f1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_17f6:
	/* 0x17f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f8:
	/* 0x17f8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17fb:
	/* 0x17fb: jl     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1826;
	}
x86_l_17fd:
	/* 0x17fd: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1801:
	/* 0x1801: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1807:
	/* 0x1807: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_180b:
	/* 0x180b: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_180e:
	/* 0x180e: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1813:
	/* 0x1813: jmp    2dcf <trace_security_file_mprotect+0x2dcf> */
	return 11727ULL;
x86_l_1818:
	/* 0x1818: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_181b:
	/* 0x181b: je     2d72 <trace_security_file_mprotect+0x2d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11634ULL;
	}
x86_l_1821:
	/* 0x1821: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1826:
	/* 0x1826: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_182d:
	/* 0x182d: jne    2e47 <trace_security_file_mprotect+0x2e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11847ULL;
	}
x86_l_1833:
	/* 0x1833: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1838:
	/* 0x1838: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_183c:
	/* 0x183c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1841:
	/* 0x1841: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1846:
	/* 0x1846: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_184b:
	/* 0x184b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184d:
	/* 0x184d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1852:
	/* 0x1852: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1857:
	/* 0x1857: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_185a:
	/* 0x185a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_185f:
	/* 0x185f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1861:
	/* 0x1861: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1864:
	/* 0x1864: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_186b:
	/* 0x186b: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_186e:
	/* 0x186e: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1872:
	/* 0x1872: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1877:
	/* 0x1877: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187c:
	/* 0x187c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1881:
	/* 0x1881: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1884:
	/* 0x1884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1886:
	/* 0x1886: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_188f:
	/* 0x188f: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1894:
	/* 0x1894: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_189d:
	/* 0x189d: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a1:
	/* 0x18a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18a6:
	/* 0x18a6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ab:
	/* 0x18ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18b0:
	/* 0x18b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b2:
	/* 0x18b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b7:
	/* 0x18b7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18bc:
	/* 0x18bc: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_18c0:
	/* 0x18c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18c5:
	/* 0x18c5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ca:
	/* 0x18ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18cf:
	/* 0x18cf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18d2:
	/* 0x18d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d4:
	/* 0x18d4: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d8:
	/* 0x18d8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18dd:
	/* 0x18dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18e2:
	/* 0x18e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e7:
	/* 0x18e7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ec:
	/* 0x18ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18f1:
	/* 0x18f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f3:
	/* 0x18f3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f8:
	/* 0x18f8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_18fb:
	/* 0x18fb: js     1921 <trace_security_file_mprotect+0x1921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1921;
	}
x86_l_18fd:
	/* 0x18fd: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1902:
	/* 0x1902: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1907:
	/* 0x1907: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190c:
	/* 0x190c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1911:
	/* 0x1911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1913:
	/* 0x1913: imul   r15,r15,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R15, X86_R15, X86_WIDTH_64, 1000000000ULL);
x86_l_191a:
	/* 0x191a: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_191f:
	/* 0x191f: jmp    1924 <trace_security_file_mprotect+0x1924> */
	goto x86_l_1924;
x86_l_1921:
	/* 0x1921: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1924:
	/* 0x1924: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1929:
	/* 0x1929: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192e:
	/* 0x192e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1933:
	/* 0x1933: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1936:
	/* 0x1936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1938:
	/* 0x1938: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_193d:
	/* 0x193d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1942:
	/* 0x1942: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1946:
	/* 0x1946: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_194b:
	/* 0x194b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1950:
	/* 0x1950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1952:
	/* 0x1952: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1957:
	/* 0x1957: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195c:
	/* 0x195c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1961:
	/* 0x1961: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1966:
	/* 0x1966: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1968:
	/* 0x1968: mov    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_196d:
	/* 0x196d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1972:
	/* 0x1972: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1977:
	/* 0x1977: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197c:
	/* 0x197c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_197f:
	/* 0x197f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1981:
	/* 0x1981: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1986:
	/* 0x1986: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198b:
	/* 0x198b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_198f:
	/* 0x198f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1994:
	/* 0x1994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1999:
	/* 0x1999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199b:
	/* 0x199b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19a0:
	/* 0x19a0: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_19a8:
	/* 0x19a8: mov    QWORD PTR [rsp+0xf0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_19b0:
	/* 0x19b0: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19b5:
	/* 0x19b5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19ba:
	/* 0x19ba: mov    QWORD PTR [rsp+0xf8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_19c2:
	/* 0x19c2: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_19ca:
	/* 0x19ca: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19cf:
	/* 0x19cf: mov    QWORD PTR [rsp+0x108],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_19d7:
	/* 0x19d7: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19dc:
	/* 0x19dc: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_19e4:
	/* 0x19e4: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19e9:
	/* 0x19e9: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_19f1:
	/* 0x19f1: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19f6:
	/* 0x19f6: mov    QWORD PTR [rsp+0x120],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_19fe:
	/* 0x19fe: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a03:
	/* 0x1a03: mov    QWORD PTR [rsp+0x128],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    DWORD PTR [rsp+0x130],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_1a13:
	/* 0x1a13: mov    DWORD PTR [rsp+0x134],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_1a26:
	/* 0x1a26: mov    QWORD PTR [rsp+0x140],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1a2e:
	/* 0x1a2e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a36:
	/* 0x1a36: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1a3c:
	/* 0x1a3c: ja     1ab7 <trace_security_file_mprotect+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab7;
	}
x86_l_1a3e:
	/* 0x1a3e: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1a47:
	/* 0x1a47: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1a57:
	/* 0x1a57: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1a5c:
	/* 0x1a5c: ja     1ab7 <trace_security_file_mprotect+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab7;
	}
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a63:
	/* 0x1a63: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a6b:
	/* 0x1a6b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a6f:
	/* 0x1a6f: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1a76:
	/* 0x1a76: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a7b:
	/* 0x1a7b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a7e:
	/* 0x1a7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a80:
	/* 0x1a80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a82:
	/* 0x1a82: jle    1ab7 <trace_security_file_mprotect+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ab7;
	}
x86_l_1a84:
	/* 0x1a84: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a8c:
	/* 0x1a8c: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1a93:
	/* 0x1a93: ja     1ab7 <trace_security_file_mprotect+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab7;
	}
x86_l_1a95:
	/* 0x1a95: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1a9d:
	/* 0x1a9d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1aa5:
	/* 0x1aa5: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ab0:
	/* 0x1ab0: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ab7:
	/* 0x1ab7: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1abf:
	/* 0x1abf: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1ac6:
	/* 0x1ac6: ja     1b0f <trace_security_file_mprotect+0x1b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b0f;
	}
x86_l_1ac8:
	/* 0x1ac8: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1ad1:
	/* 0x1ad1: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1ad7:
	/* 0x1ad7: ja     1b0f <trace_security_file_mprotect+0x1b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b0f;
	}
x86_l_1ad9:
	/* 0x1ad9: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1add:
	/* 0x1add: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae9:
	/* 0x1ae9: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1af1:
	/* 0x1af1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1af6:
	/* 0x1af6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af8:
	/* 0x1af8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1afb:
	/* 0x1afb: js     1b0f <trace_security_file_mprotect+0x1b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b0f;
	}
x86_l_1afd:
	/* 0x1afd: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1b00:
	/* 0x1b00: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b08:
	/* 0x1b08: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1b0f:
	/* 0x1b0f: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b17:
	/* 0x1b17: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1b1e:
	/* 0x1b1e: ja     1b67 <trace_security_file_mprotect+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b67;
	}
x86_l_1b20:
	/* 0x1b20: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1b29:
	/* 0x1b29: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1b2f:
	/* 0x1b2f: ja     1b67 <trace_security_file_mprotect+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b67;
	}
x86_l_1b31:
	/* 0x1b31: lea    rdx,[rsp+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1b39:
	/* 0x1b39: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1b3d:
	/* 0x1b3d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1b44:
	/* 0x1b44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b49:
	/* 0x1b49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b4e:
	/* 0x1b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b50:
	/* 0x1b50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b53:
	/* 0x1b53: js     1b67 <trace_security_file_mprotect+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b67;
	}
x86_l_1b55:
	/* 0x1b55: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1b58:
	/* 0x1b58: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b60:
	/* 0x1b60: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1b67:
	/* 0x1b67: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b6f:
	/* 0x1b6f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1b76:
	/* 0x1b76: ja     1bbf <trace_security_file_mprotect+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bbf;
	}
x86_l_1b78:
	/* 0x1b78: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1b81:
	/* 0x1b81: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1b87:
	/* 0x1b87: ja     1bbf <trace_security_file_mprotect+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bbf;
	}
x86_l_1b89:
	/* 0x1b89: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1b8d:
	/* 0x1b8d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1b94:
	/* 0x1b94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b99:
	/* 0x1b99: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba6:
	/* 0x1ba6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba8:
	/* 0x1ba8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bab:
	/* 0x1bab: js     1bbf <trace_security_file_mprotect+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1bbf;
	}
x86_l_1bad:
	/* 0x1bad: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1bb8:
	/* 0x1bb8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1bbf:
	/* 0x1bbf: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bc7:
	/* 0x1bc7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1bce:
	/* 0x1bce: ja     1c17 <trace_security_file_mprotect+0x1c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c17;
	}
x86_l_1bd0:
	/* 0x1bd0: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1bd9:
	/* 0x1bd9: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1bdf:
	/* 0x1bdf: ja     1c17 <trace_security_file_mprotect+0x1c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c17;
	}
x86_l_1be1:
	/* 0x1be1: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1be5:
	/* 0x1be5: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1bec:
	/* 0x1bec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf1:
	/* 0x1bf1: lea    rdx,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1bf9:
	/* 0x1bf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bfe:
	/* 0x1bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c00:
	/* 0x1c00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c03:
	/* 0x1c03: js     1c17 <trace_security_file_mprotect+0x1c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c17;
	}
x86_l_1c05:
	/* 0x1c05: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1c08:
	/* 0x1c08: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c10:
	/* 0x1c10: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1c17:
	/* 0x1c17: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c1f:
	/* 0x1c1f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1c26:
	/* 0x1c26: ja     1c6f <trace_security_file_mprotect+0x1c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c6f;
	}
x86_l_1c28:
	/* 0x1c28: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_1c31:
	/* 0x1c31: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1c37:
	/* 0x1c37: ja     1c6f <trace_security_file_mprotect+0x1c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c6f;
	}
x86_l_1c39:
	/* 0x1c39: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c3d:
	/* 0x1c3d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1c44:
	/* 0x1c44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c49:
	/* 0x1c49: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1c51:
	/* 0x1c51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c56:
	/* 0x1c56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c58:
	/* 0x1c58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: js     1c6f <trace_security_file_mprotect+0x1c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c6f;
	}
x86_l_1c5d:
	/* 0x1c5d: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1c60:
	/* 0x1c60: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c68:
	/* 0x1c68: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1c6f:
	/* 0x1c6f: cmp    DWORD PTR [r14+0x74],0x149 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206665ULL);
x86_l_1c77:
	/* 0x1c77: jne    1d18 <trace_security_file_mprotect+0x1d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7448ULL;
	}
x86_l_1c7d:
	/* 0x1c7d: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1c84:
	/* 0x1c84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c89:
	/* 0x1c89: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c93:
	/* 0x1c93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c95:
	/* 0x1c95: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1c9a:
	/* 0x1c9a: jne    1ca2 <trace_security_file_mprotect+0x1ca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ca2;
	}
x86_l_1c9c:
	/* 0x1c9c: mov    rax,QWORD PTR [rbp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ca0:
	/* 0x1ca0: jmp    1cbf <trace_security_file_mprotect+0x1cbf> */
	goto x86_l_1cbf;
x86_l_1ca2:
	/* 0x1ca2: add    rbp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cab:
	/* 0x1cab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb5:
	/* 0x1cb5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1cb8:
	/* 0x1cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cba:
	/* 0x1cba: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cc3:
	/* 0x1cc3: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
	return 7371ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7371ULL: goto x86_l_1ccb;
	case 7378ULL: goto x86_l_1cd2;
	case 7380ULL: goto x86_l_1cd4;
	case 7389ULL: goto x86_l_1cdd;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7441ULL: goto x86_l_1d11;
	case 7448ULL: goto x86_l_1d18;
	case 7455ULL: goto x86_l_1d1f;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7565ULL: goto x86_l_1d8d;
	case 7569ULL: goto x86_l_1d91;
	case 7573ULL: goto x86_l_1d95;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7626ULL: goto x86_l_1dca;
	case 7630ULL: goto x86_l_1dce;
	case 7634ULL: goto x86_l_1dd2;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7659ULL: goto x86_l_1deb;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7681ULL: goto x86_l_1e01;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7742ULL: goto x86_l_1e3e;
	case 7746ULL: goto x86_l_1e42;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7793ULL: goto x86_l_1e71;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7828ULL: goto x86_l_1e94;
	case 7832ULL: goto x86_l_1e98;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 7999ULL: goto x86_l_1f3f;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8044ULL: goto x86_l_1f6c;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8077ULL: goto x86_l_1f8d;
	case 8081ULL: goto x86_l_1f91;
	case 8085ULL: goto x86_l_1f95;
	case 8089ULL: goto x86_l_1f99;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8164ULL: goto x86_l_1fe4;
	case 8168ULL: goto x86_l_1fe8;
	case 8172ULL: goto x86_l_1fec;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8240ULL: goto x86_l_2030;
	case 8242ULL: goto x86_l_2032;
	case 8247ULL: goto x86_l_2037;
	case 8251ULL: goto x86_l_203b;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8284ULL: goto x86_l_205c;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8311ULL: goto x86_l_2077;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8336ULL: goto x86_l_2090;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8390ULL: goto x86_l_20c6;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8463ULL: goto x86_l_210f;
	case 8465ULL: goto x86_l_2111;
	case 8473ULL: goto x86_l_2119;
	case 8477ULL: goto x86_l_211d;
	case 8485ULL: goto x86_l_2125;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8509ULL: goto x86_l_213d;
	case 8511ULL: goto x86_l_213f;
	case 8513ULL: goto x86_l_2141;
	case 8517ULL: goto x86_l_2145;
	case 8525ULL: goto x86_l_214d;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8544ULL: goto x86_l_2160;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8581ULL: goto x86_l_2185;
	case 8589ULL: goto x86_l_218d;
	case 8599ULL: goto x86_l_2197;
	case 8607ULL: goto x86_l_219f;
	case 8615ULL: goto x86_l_21a7;
	case 8623ULL: goto x86_l_21af;
	case 8631ULL: goto x86_l_21b7;
	case 8639ULL: goto x86_l_21bf;
	case 8647ULL: goto x86_l_21c7;
	case 8655ULL: goto x86_l_21cf;
	case 8663ULL: goto x86_l_21d7;
	case 8670ULL: goto x86_l_21de;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8704ULL: goto x86_l_2200;
	case 8711ULL: goto x86_l_2207;
	case 8716ULL: goto x86_l_220c;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8740ULL: goto x86_l_2224;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8751ULL: goto x86_l_222f;
	case 8755ULL: goto x86_l_2233;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8772ULL: goto x86_l_2244;
	case 8779ULL: goto x86_l_224b;
	case 8783ULL: goto x86_l_224f;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8801ULL: goto x86_l_2261;
	case 8805ULL: goto x86_l_2265;
	case 8812ULL: goto x86_l_226c;
	case 8816ULL: goto x86_l_2270;
	case 8823ULL: goto x86_l_2277;
	case 8827ULL: goto x86_l_227b;
	case 8831ULL: goto x86_l_227f;
	case 8838ULL: goto x86_l_2286;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8856ULL: goto x86_l_2298;
	case 8859ULL: goto x86_l_229b;
	case 8866ULL: goto x86_l_22a2;
	case 8874ULL: goto x86_l_22aa;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8935ULL: goto x86_l_22e7;
	case 8938ULL: goto x86_l_22ea;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8960ULL: goto x86_l_2300;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8976ULL: goto x86_l_2310;
	case 8979ULL: goto x86_l_2313;
	case 8982ULL: goto x86_l_2316;
	case 8989ULL: goto x86_l_231d;
	case 8992ULL: goto x86_l_2320;
	case 8994ULL: goto x86_l_2322;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9014ULL: goto x86_l_2336;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9027ULL: goto x86_l_2343;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9043ULL: goto x86_l_2353;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9057ULL: goto x86_l_2361;
	case 9060ULL: goto x86_l_2364;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9086ULL: goto x86_l_237e;
	case 9092ULL: goto x86_l_2384;
	case 9099ULL: goto x86_l_238b;
	case 9107ULL: goto x86_l_2393;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ccb:
	/* 0x1ccb: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1cd2:
	/* 0x1cd2: ja     1d18 <trace_security_file_mprotect+0x1d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d18;
	}
x86_l_1cd4:
	/* 0x1cd4: mov    BYTE PTR [r14+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_1cdd:
	/* 0x1cdd: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1ce3:
	/* 0x1ce3: ja     1d18 <trace_security_file_mprotect+0x1d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d18;
	}
x86_l_1ce5:
	/* 0x1ce5: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ce9:
	/* 0x1ce9: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cf5:
	/* 0x1cf5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cff:
	/* 0x1cff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d01:
	/* 0x1d01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d04:
	/* 0x1d04: js     1d18 <trace_security_file_mprotect+0x1d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d18;
	}
x86_l_1d06:
	/* 0x1d06: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1d09:
	/* 0x1d09: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d11:
	/* 0x1d11: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d18:
	/* 0x1d18: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1d1f:
	/* 0x1d1f: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d23:
	/* 0x1d23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d28:
	/* 0x1d28: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d32:
	/* 0x1d32: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d35:
	/* 0x1d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d37:
	/* 0x1d37: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d44:
	/* 0x1d44: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d48:
	/* 0x1d48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d4d:
	/* 0x1d4d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d52:
	/* 0x1d52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d57:
	/* 0x1d57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d59:
	/* 0x1d59: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d5e:
	/* 0x1d5e: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1d62:
	/* 0x1d62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d67:
	/* 0x1d67: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d71:
	/* 0x1d71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d73:
	/* 0x1d73: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d78:
	/* 0x1d78: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d81:
	/* 0x1d81: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d86:
	/* 0x1d86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d8b:
	/* 0x1d8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8d:
	/* 0x1d8d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d91:
	/* 0x1d91: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d95:
	/* 0x1d95: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d99:
	/* 0x1d99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d9e:
	/* 0x1d9e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1da3:
	/* 0x1da3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da8:
	/* 0x1da8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dad:
	/* 0x1dad: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1db2:
	/* 0x1db2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1db7:
	/* 0x1db7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc1:
	/* 0x1dc1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dc4:
	/* 0x1dc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc6:
	/* 0x1dc6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dca:
	/* 0x1dca: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1dce:
	/* 0x1dce: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1dd2:
	/* 0x1dd2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ddb:
	/* 0x1ddb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1de0:
	/* 0x1de0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de5:
	/* 0x1de5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de7:
	/* 0x1de7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1deb:
	/* 0x1deb: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1def:
	/* 0x1def: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1df4:
	/* 0x1df4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df9:
	/* 0x1df9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e01:
	/* 0x1e01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e03:
	/* 0x1e03: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e08:
	/* 0x1e08: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e0c:
	/* 0x1e0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e11:
	/* 0x1e11: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e16:
	/* 0x1e16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e1b:
	/* 0x1e1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1d:
	/* 0x1e1d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e22:
	/* 0x1e22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e27:
	/* 0x1e27: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e31:
	/* 0x1e31: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e34:
	/* 0x1e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e36:
	/* 0x1e36: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e3a:
	/* 0x1e3a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e3e:
	/* 0x1e3e: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e42:
	/* 0x1e42: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e46:
	/* 0x1e46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e4b:
	/* 0x1e4b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e50:
	/* 0x1e50: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e55:
	/* 0x1e55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e57:
	/* 0x1e57: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e64:
	/* 0x1e64: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e69:
	/* 0x1e69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e71:
	/* 0x1e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e73:
	/* 0x1e73: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e78:
	/* 0x1e78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7d:
	/* 0x1e7d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e82:
	/* 0x1e82: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e87:
	/* 0x1e87: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e8a:
	/* 0x1e8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8c:
	/* 0x1e8c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e90:
	/* 0x1e90: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e94:
	/* 0x1e94: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e98:
	/* 0x1e98: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ea1:
	/* 0x1ea1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eab:
	/* 0x1eab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ead:
	/* 0x1ead: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb2:
	/* 0x1eb2: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1eb6:
	/* 0x1eb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ebb:
	/* 0x1ebb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ec5:
	/* 0x1ec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec7:
	/* 0x1ec7: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ecc:
	/* 0x1ecc: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ed5:
	/* 0x1ed5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eda:
	/* 0x1eda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1edf:
	/* 0x1edf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ee2:
	/* 0x1ee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee4:
	/* 0x1ee4: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eee:
	/* 0x1eee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1efb:
	/* 0x1efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efd:
	/* 0x1efd: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f01:
	/* 0x1f01: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1f05:
	/* 0x1f05: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f09:
	/* 0x1f09: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f12:
	/* 0x1f12: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f17:
	/* 0x1f17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f1c:
	/* 0x1f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1e:
	/* 0x1f1e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f23:
	/* 0x1f23: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1f27:
	/* 0x1f27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f2c:
	/* 0x1f2c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f31:
	/* 0x1f31: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f36:
	/* 0x1f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f38:
	/* 0x1f38: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_1f3d:
	/* 0x1f3d: jne    1f95 <trace_security_file_mprotect+0x1f95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f95;
	}
x86_l_1f3f:
	/* 0x1f3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f44:
	/* 0x1f44: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f49:
	/* 0x1f49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f51:
	/* 0x1f51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f53:
	/* 0x1f53: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f58:
	/* 0x1f58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f5d:
	/* 0x1f5d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f62:
	/* 0x1f62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f67:
	/* 0x1f67: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f6a:
	/* 0x1f6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6c:
	/* 0x1f6c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f70:
	/* 0x1f70: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1f74:
	/* 0x1f74: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f78:
	/* 0x1f78: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f7c:
	/* 0x1f7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f81:
	/* 0x1f81: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f86:
	/* 0x1f86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f8b:
	/* 0x1f8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8d:
	/* 0x1f8d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f91:
	/* 0x1f91: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f95:
	/* 0x1f95: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f99:
	/* 0x1f99: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa5:
	/* 0x1fa5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1faa:
	/* 0x1faa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1faf:
	/* 0x1faf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fb2:
	/* 0x1fb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb4:
	/* 0x1fb4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb9:
	/* 0x1fb9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fc2:
	/* 0x1fc2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc7:
	/* 0x1fc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fcc:
	/* 0x1fcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fce:
	/* 0x1fce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fd8:
	/* 0x1fd8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fe2:
	/* 0x1fe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe4:
	/* 0x1fe4: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1fec:
	/* 0x1fec: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1ff1:
	/* 0x1ff1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff3:
	/* 0x1ff3: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ff7:
	/* 0x1ff7: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2000:
	/* 0x2000: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2005:
	/* 0x2005: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200a:
	/* 0x200a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200c:
	/* 0x200c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2011:
	/* 0x2011: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2015:
	/* 0x2015: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_201d:
	/* 0x201d: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2021:
	/* 0x2021: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2026:
	/* 0x2026: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_202b:
	/* 0x202b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2030:
	/* 0x2030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2032:
	/* 0x2032: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2037:
	/* 0x2037: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_203b:
	/* 0x203b: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_203f:
	/* 0x203f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2044:
	/* 0x2044: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2049:
	/* 0x2049: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_204e:
	/* 0x204e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2051:
	/* 0x2051: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2053:
	/* 0x2053: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2058:
	/* 0x2058: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_205c:
	/* 0x205c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2061:
	/* 0x2061: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2066:
	/* 0x2066: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_206b:
	/* 0x206b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_206e:
	/* 0x206e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2070:
	/* 0x2070: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_2075:
	/* 0x2075: je     207c <trace_security_file_mprotect+0x207c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207c;
	}
x86_l_2077:
	/* 0x2077: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_207c:
	/* 0x207c: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2080:
	/* 0x2080: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2088:
	/* 0x2088: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2090:
	/* 0x2090: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2095:
	/* 0x2095: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_209a:
	/* 0x209a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209c:
	/* 0x209c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a1:
	/* 0x20a1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20a6:
	/* 0x20a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ab:
	/* 0x20ab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20ae:
	/* 0x20ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b0:
	/* 0x20b0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20b5:
	/* 0x20b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ba:
	/* 0x20ba: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20bf:
	/* 0x20bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c4:
	/* 0x20c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c6:
	/* 0x20c6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20cb:
	/* 0x20cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20d0:
	/* 0x20d0: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20d5:
	/* 0x20d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20d8:
	/* 0x20d8: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_20dd:
	/* 0x20dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20df:
	/* 0x20df: lea    rdi,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_20e3:
	/* 0x20e3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_20e8:
	/* 0x20e8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20ed:
	/* 0x20ed: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_20f0:
	/* 0x20f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f2:
	/* 0x20f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f7:
	/* 0x20f7: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_20ff:
	/* 0x20ff: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2102:
	/* 0x2102: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2107:
	/* 0x2107: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_210f:
	/* 0x210f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2111:
	/* 0x2111: mov    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2119:
	/* 0x2119: test   BYTE PTR [rbx+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_211d:
	/* 0x211d: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2125:
	/* 0x2125: je     2145 <trace_security_file_mprotect+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2145;
	}
x86_l_2127:
	/* 0x2127: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_212c:
	/* 0x212c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2133:
	/* 0x2133: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2138:
	/* 0x2138: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_213b:
	/* 0x213b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213d:
	/* 0x213d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_213f:
	/* 0x213f: js     2145 <trace_security_file_mprotect+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2145;
	}
x86_l_2141:
	/* 0x2141: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2145:
	/* 0x2145: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_214d:
	/* 0x214d: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2152:
	/* 0x2152: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2157:
	/* 0x2157: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_215a:
	/* 0x215a: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2160:
	/* 0x2160: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2164:
	/* 0x2164: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2169:
	/* 0x2169: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2170:
	/* 0x2170: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2175:
	/* 0x2175: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2178:
	/* 0x2178: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_217b:
	/* 0x217b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217d:
	/* 0x217d: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2185:
	/* 0x2185: mov    DWORD PTR [r14+0x70],0x2d4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337876ULL);
x86_l_218d:
	/* 0x218d: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_2197:
	/* 0x2197: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_219f:
	/* 0x219f: mov    QWORD PTR [rcx+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_21a7:
	/* 0x21a7: mov    QWORD PTR [rcx+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_21af:
	/* 0x21af: mov    QWORD PTR [rcx+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_21b7:
	/* 0x21b7: mov    QWORD PTR [rcx+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_21bf:
	/* 0x21bf: mov    QWORD PTR [rcx+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_21c7:
	/* 0x21c7: mov    QWORD PTR [rcx+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_21cf:
	/* 0x21cf: mov    QWORD PTR [rcx+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_21d7:
	/* 0x21d7: mov    QWORD PTR [rcx],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_21de:
	/* 0x21de: mov    QWORD PTR [r14+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_21e9:
	/* 0x21e9: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_21ee:
	/* 0x21ee: mov    DWORD PTR [rsp+0x30],0x2d4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430932ULL);
x86_l_21f6:
	/* 0x21f6: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21fb:
	/* 0x21fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2200:
	/* 0x2200: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_2207:
	/* 0x2207: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220c:
	/* 0x220c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220e:
	/* 0x220e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2211:
	/* 0x2211: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_2217:
	/* 0x2217: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_221c:
	/* 0x221c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2221:
	/* 0x2221: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2224:
	/* 0x2224: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2226:
	/* 0x2226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2229:
	/* 0x2229: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_222f:
	/* 0x222f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2233:
	/* 0x2233: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_223a:
	/* 0x223a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223d:
	/* 0x223d: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_2244:
	/* 0x2244: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_224b:
	/* 0x224b: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_224f:
	/* 0x224f: mov    QWORD PTR [r14+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_2256:
	/* 0x2256: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_225a:
	/* 0x225a: mov    QWORD PTR [r14+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_2261:
	/* 0x2261: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2265:
	/* 0x2265: mov    QWORD PTR [r14+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_226c:
	/* 0x226c: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2270:
	/* 0x2270: mov    QWORD PTR [r14+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_2277:
	/* 0x2277: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_227b:
	/* 0x227b: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_227f:
	/* 0x227f: mov    QWORD PTR [r14+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2286:
	/* 0x2286: mov    QWORD PTR [r14+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_228d:
	/* 0x228d: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_228f:
	/* 0x228f: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2293:
	/* 0x2293: jne    22b5 <trace_security_file_mprotect+0x22b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b5;
	}
x86_l_2295:
	/* 0x2295: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2298:
	/* 0x2298: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_229b:
	/* 0x229b: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_22a2:
	/* 0x22a2: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_22aa:
	/* 0x22aa: jne    2a7b <trace_security_file_mprotect+0x2a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10875ULL;
	}
x86_l_22b0:
	/* 0x22b0: jmp    2a6f <trace_security_file_mprotect+0x2a6f> */
	return 10863ULL;
x86_l_22b5:
	/* 0x22b5: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_22bc:
	/* 0x22bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22bf:
	/* 0x22bf: je     2474 <trace_security_file_mprotect+0x2474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9332ULL;
	}
x86_l_22c5:
	/* 0x22c5: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_22cd:
	/* 0x22cd: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_22d0:
	/* 0x22d0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22d3:
	/* 0x22d3: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_22d6:
	/* 0x22d6: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_22da:
	/* 0x22da: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22dd:
	/* 0x22dd: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_22e0:
	/* 0x22e0: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_22e7:
	/* 0x22e7: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22ea:
	/* 0x22ea: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_22f1:
	/* 0x22f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f4:
	/* 0x22f4: je     2316 <trace_security_file_mprotect+0x2316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2316;
	}
x86_l_22f6:
	/* 0x22f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22f8:
	/* 0x22f8: cmp    BYTE PTR [r13+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_2300:
	/* 0x2300: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2303:
	/* 0x2303: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2306:
	/* 0x2306: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2309:
	/* 0x2309: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_2310:
	/* 0x2310: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2313:
	/* 0x2313: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2316:
	/* 0x2316: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_231d:
	/* 0x231d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2320:
	/* 0x2320: je     233c <trace_security_file_mprotect+0x233c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233c;
	}
x86_l_2322:
	/* 0x2322: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2326:
	/* 0x2326: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2329:
	/* 0x2329: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_232c:
	/* 0x232c: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_232f:
	/* 0x232f: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_2336:
	/* 0x2336: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2339:
	/* 0x2339: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_233c:
	/* 0x233c: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2343:
	/* 0x2343: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2346:
	/* 0x2346: je     2367 <trace_security_file_mprotect+0x2367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2367;
	}
x86_l_2348:
	/* 0x2348: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_234b:
	/* 0x234b: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2353:
	/* 0x2353: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2357:
	/* 0x2357: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_235a:
	/* 0x235a: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_2361:
	/* 0x2361: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2364:
	/* 0x2364: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2367:
	/* 0x2367: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_236c:
	/* 0x236c: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_2373:
	/* 0x2373: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2376:
	/* 0x2376: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_237e:
	/* 0x237e: je     24d2 <trace_security_file_mprotect+0x24d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9426ULL;
	}
x86_l_2384:
	/* 0x2384: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_238b:
	/* 0x238b: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2393:
	/* 0x2393: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
	return 9114ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9114ULL: goto x86_l_239a;
	case 9122ULL: goto x86_l_23a2;
	case 9129ULL: goto x86_l_23a9;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9180ULL: goto x86_l_23dc;
	case 9183ULL: goto x86_l_23df;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9198ULL: goto x86_l_23ee;
	case 9200ULL: goto x86_l_23f0;
	case 9203ULL: goto x86_l_23f3;
	case 9205ULL: goto x86_l_23f5;
	case 9208ULL: goto x86_l_23f8;
	case 9212ULL: goto x86_l_23fc;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9228ULL: goto x86_l_240c;
	case 9236ULL: goto x86_l_2414;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9253ULL: goto x86_l_2425;
	case 9255ULL: goto x86_l_2427;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9268ULL: goto x86_l_2434;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9318ULL: goto x86_l_2466;
	case 9320ULL: goto x86_l_2468;
	case 9323ULL: goto x86_l_246b;
	case 9327ULL: goto x86_l_246f;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9339ULL: goto x86_l_247b;
	case 9346ULL: goto x86_l_2482;
	case 9349ULL: goto x86_l_2485;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9362ULL: goto x86_l_2492;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9374ULL: goto x86_l_249e;
	case 9382ULL: goto x86_l_24a6;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9399ULL: goto x86_l_24b7;
	case 9401ULL: goto x86_l_24b9;
	case 9404ULL: goto x86_l_24bc;
	case 9406ULL: goto x86_l_24be;
	case 9414ULL: goto x86_l_24c6;
	case 9417ULL: goto x86_l_24c9;
	case 9420ULL: goto x86_l_24cc;
	case 9423ULL: goto x86_l_24cf;
	case 9426ULL: goto x86_l_24d2;
	case 9434ULL: goto x86_l_24da;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9451ULL: goto x86_l_24eb;
	case 9458ULL: goto x86_l_24f2;
	case 9465ULL: goto x86_l_24f9;
	case 9473ULL: goto x86_l_2501;
	case 9480ULL: goto x86_l_2508;
	case 9487ULL: goto x86_l_250f;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9519ULL: goto x86_l_252f;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9535ULL: goto x86_l_253f;
	case 9538ULL: goto x86_l_2542;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9567ULL: goto x86_l_255f;
	case 9570ULL: goto x86_l_2562;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9598ULL: goto x86_l_257e;
	case 9600ULL: goto x86_l_2580;
	case 9608ULL: goto x86_l_2588;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9637ULL: goto x86_l_25a5;
	case 9640ULL: goto x86_l_25a8;
	case 9643ULL: goto x86_l_25ab;
	case 9646ULL: goto x86_l_25ae;
	case 9654ULL: goto x86_l_25b6;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9694ULL: goto x86_l_25de;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9737ULL: goto x86_l_2609;
	case 9741ULL: goto x86_l_260d;
	case 9745ULL: goto x86_l_2611;
	case 9752ULL: goto x86_l_2618;
	case 9759ULL: goto x86_l_261f;
	case 9762ULL: goto x86_l_2622;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9786ULL: goto x86_l_263a;
	case 9793ULL: goto x86_l_2641;
	case 9796ULL: goto x86_l_2644;
	case 9798ULL: goto x86_l_2646;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9815ULL: goto x86_l_2657;
	case 9817ULL: goto x86_l_2659;
	case 9820ULL: goto x86_l_265c;
	case 9824ULL: goto x86_l_2660;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9831ULL: goto x86_l_2667;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9851ULL: goto x86_l_267b;
	case 9857ULL: goto x86_l_2681;
	case 9864ULL: goto x86_l_2688;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9878ULL: goto x86_l_2696;
	case 9883ULL: goto x86_l_269b;
	case 9885ULL: goto x86_l_269d;
	case 9890ULL: goto x86_l_26a2;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9908ULL: goto x86_l_26b4;
	case 9910ULL: goto x86_l_26b6;
	case 9914ULL: goto x86_l_26ba;
	case 9918ULL: goto x86_l_26be;
	case 9922ULL: goto x86_l_26c2;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9973ULL: goto x86_l_26f5;
	case 9977ULL: goto x86_l_26f9;
	case 9984ULL: goto x86_l_2700;
	case 9991ULL: goto x86_l_2707;
	case 9994ULL: goto x86_l_270a;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10018ULL: goto x86_l_2722;
	case 10025ULL: goto x86_l_2729;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10047ULL: goto x86_l_273f;
	case 10049ULL: goto x86_l_2741;
	case 10052ULL: goto x86_l_2744;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10066ULL: goto x86_l_2752;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10075ULL: goto x86_l_275b;
	case 10083ULL: goto x86_l_2763;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10194ULL: goto x86_l_27d2;
	case 10201ULL: goto x86_l_27d9;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10228ULL: goto x86_l_27f4;
	case 10235ULL: goto x86_l_27fb;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10251ULL: goto x86_l_280b;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10268ULL: goto x86_l_281c;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10275ULL: goto x86_l_2823;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10284ULL: goto x86_l_282c;
	case 10292ULL: goto x86_l_2834;
	case 10300ULL: goto x86_l_283c;
	case 10306ULL: goto x86_l_2842;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10325ULL: goto x86_l_2855;
	case 10332ULL: goto x86_l_285c;
	case 10339ULL: goto x86_l_2863;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10373ULL: goto x86_l_2885;
	case 10376ULL: goto x86_l_2888;
	case 10378ULL: goto x86_l_288a;
	case 10383ULL: goto x86_l_288f;
	case 10386ULL: goto x86_l_2892;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10394ULL: goto x86_l_289a;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10406ULL: goto x86_l_28a6;
	case 10408ULL: goto x86_l_28a8;
	case 10410ULL: goto x86_l_28aa;
	case 10413ULL: goto x86_l_28ad;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10430ULL: goto x86_l_28be;
	case 10437ULL: goto x86_l_28c5;
	case 10440ULL: goto x86_l_28c8;
	case 10442ULL: goto x86_l_28ca;
	case 10446ULL: goto x86_l_28ce;
	case 10450ULL: goto x86_l_28d2;
	case 10457ULL: goto x86_l_28d9;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10491ULL: goto x86_l_28fb;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10509ULL: goto x86_l_290d;
	case 10511ULL: goto x86_l_290f;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10519ULL: goto x86_l_2917;
	case 10523ULL: goto x86_l_291b;
	case 10526ULL: goto x86_l_291e;
	case 10528ULL: goto x86_l_2920;
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10536ULL: goto x86_l_2928;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10554ULL: goto x86_l_293a;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10588ULL: goto x86_l_295c;
	case 10595ULL: goto x86_l_2963;
	case 10598ULL: goto x86_l_2966;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10608ULL: goto x86_l_2970;
	case 10616ULL: goto x86_l_2978;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10630ULL: goto x86_l_2986;
	case 10633ULL: goto x86_l_2989;
	case 10635ULL: goto x86_l_298b;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10649ULL: goto x86_l_2999;
	case 10656ULL: goto x86_l_29a0;
	case 10659ULL: goto x86_l_29a3;
	case 10665ULL: goto x86_l_29a9;
	case 10672ULL: goto x86_l_29b0;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_239a:
	/* 0x239a: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_23a2:
	/* 0x23a2: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_23a9:
	/* 0x23a9: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23b1:
	/* 0x23b1: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23b6:
	/* 0x23b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23bb:
	/* 0x23bb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_23c2:
	/* 0x23c2: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23c7:
	/* 0x23c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c9:
	/* 0x23c9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23d0:
	/* 0x23d0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23d5:
	/* 0x23d5: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23dc:
	/* 0x23dc: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_23df:
	/* 0x23df: je     2401 <trace_security_file_mprotect+0x2401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2401;
	}
x86_l_23e1:
	/* 0x23e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23e6:
	/* 0x23e6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23eb:
	/* 0x23eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23ee:
	/* 0x23ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f0:
	/* 0x23f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23f3:
	/* 0x23f3: je     2401 <trace_security_file_mprotect+0x2401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2401;
	}
x86_l_23f5:
	/* 0x23f5: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f8:
	/* 0x23f8: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23fc:
	/* 0x23fc: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23ff:
	/* 0x23ff: jmp    2404 <trace_security_file_mprotect+0x2404> */
	goto x86_l_2404;
x86_l_2401:
	/* 0x2401: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2404:
	/* 0x2404: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_240c:
	/* 0x240c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2414:
	/* 0x2414: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2419:
	/* 0x2419: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_241c:
	/* 0x241c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_241f:
	/* 0x241f: jb     2437 <trace_security_file_mprotect+0x2437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2437;
	}
x86_l_2421:
	/* 0x2421: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2425:
	/* 0x2425: je     242c <trace_security_file_mprotect+0x242c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242c;
	}
x86_l_2427:
	/* 0x2427: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_242a:
	/* 0x242a: jbe    2437 <trace_security_file_mprotect+0x2437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2437;
	}
x86_l_242c:
	/* 0x242c: and    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 200ULL);
x86_l_2434:
	/* 0x2434: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2437:
	/* 0x2437: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_243b:
	/* 0x243b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2440:
	/* 0x2440: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2447:
	/* 0x2447: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_244a:
	/* 0x244a: je     2490 <trace_security_file_mprotect+0x2490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2490;
	}
x86_l_244c:
	/* 0x244c: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2454:
	/* 0x2454: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2459:
	/* 0x2459: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_245e:
	/* 0x245e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2461:
	/* 0x2461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2463:
	/* 0x2463: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2466:
	/* 0x2466: je     2494 <trace_security_file_mprotect+0x2494> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2494;
	}
x86_l_2468:
	/* 0x2468: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246b:
	/* 0x246b: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_246f:
	/* 0x246f: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2472:
	/* 0x2472: jmp    2496 <trace_security_file_mprotect+0x2496> */
	goto x86_l_2496;
x86_l_2474:
	/* 0x2474: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_247b:
	/* 0x247b: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_2482:
	/* 0x2482: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2485:
	/* 0x2485: jne    22f6 <trace_security_file_mprotect+0x22f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8950ULL;
	}
x86_l_248b:
	/* 0x248b: jmp    2316 <trace_security_file_mprotect+0x2316> */
	return 8982ULL;
x86_l_2490:
	/* 0x2490: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2492:
	/* 0x2492: jmp    24a6 <trace_security_file_mprotect+0x24a6> */
	goto x86_l_24a6;
x86_l_2494:
	/* 0x2494: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2496:
	/* 0x2496: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_249e:
	/* 0x249e: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_24a6:
	/* 0x24a6: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24a9:
	/* 0x24a9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ae:
	/* 0x24ae: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_24b1:
	/* 0x24b1: jb     24c9 <trace_security_file_mprotect+0x24c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24c9;
	}
x86_l_24b3:
	/* 0x24b3: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_24b7:
	/* 0x24b7: je     24be <trace_security_file_mprotect+0x24be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24be;
	}
x86_l_24b9:
	/* 0x24b9: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_24bc:
	/* 0x24bc: jbe    24c9 <trace_security_file_mprotect+0x24c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24c9;
	}
x86_l_24be:
	/* 0x24be: and    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 200ULL);
x86_l_24c6:
	/* 0x24c6: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_24c9:
	/* 0x24c9: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_24cc:
	/* 0x24cc: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24cf:
	/* 0x24cf: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_24d2:
	/* 0x24d2: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_24da:
	/* 0x24da: je     2580 <trace_security_file_mprotect+0x2580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2580;
	}
x86_l_24e0:
	/* 0x24e0: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_24e5:
	/* 0x24e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e7:
	/* 0x24e7: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24eb:
	/* 0x24eb: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_24f2:
	/* 0x24f2: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_24f9:
	/* 0x24f9: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2501:
	/* 0x2501: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_2508:
	/* 0x2508: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_250f:
	/* 0x250f: movzx  eax,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_2517:
	/* 0x2517: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_251c:
	/* 0x251c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2521:
	/* 0x2521: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_2528:
	/* 0x2528: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_252d:
	/* 0x252d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252f:
	/* 0x252f: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2533:
	/* 0x2533: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2538:
	/* 0x2538: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_253f:
	/* 0x253f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2542:
	/* 0x2542: je     2564 <trace_security_file_mprotect+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2564;
	}
x86_l_2544:
	/* 0x2544: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2549:
	/* 0x2549: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_254e:
	/* 0x254e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2551:
	/* 0x2551: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2553:
	/* 0x2553: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2556:
	/* 0x2556: je     2564 <trace_security_file_mprotect+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2564;
	}
x86_l_2558:
	/* 0x2558: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_255b:
	/* 0x255b: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255f:
	/* 0x255f: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2562:
	/* 0x2562: jmp    2566 <trace_security_file_mprotect+0x2566> */
	goto x86_l_2566;
x86_l_2564:
	/* 0x2564: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2566:
	/* 0x2566: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2569:
	/* 0x2569: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_256e:
	/* 0x256e: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2571:
	/* 0x2571: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: jae    258a <trace_security_file_mprotect+0x258a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_258a;
	}
x86_l_2576:
	/* 0x2576: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_257e:
	/* 0x257e: jmp    25a8 <trace_security_file_mprotect+0x25a8> */
	goto x86_l_25a8;
x86_l_2580:
	/* 0x2580: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_2588:
	/* 0x2588: jmp    25ae <trace_security_file_mprotect+0x25ae> */
	goto x86_l_25ae;
x86_l_258a:
	/* 0x258a: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_258e:
	/* 0x258e: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_2596:
	/* 0x2596: je     259d <trace_security_file_mprotect+0x259d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259d;
	}
x86_l_2598:
	/* 0x2598: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_259b:
	/* 0x259b: jbe    25a8 <trace_security_file_mprotect+0x25a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_25a8;
	}
x86_l_259d:
	/* 0x259d: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_25a5:
	/* 0x25a5: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_25a8:
	/* 0x25a8: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25ab:
	/* 0x25ab: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_25ae:
	/* 0x25ae: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_25b6:
	/* 0x25b6: je     2673 <trace_security_file_mprotect+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2673;
	}
x86_l_25bc:
	/* 0x25bc: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_25c1:
	/* 0x25c1: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_25c8:
	/* 0x25c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25cd:
	/* 0x25cd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d2:
	/* 0x25d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d7:
	/* 0x25d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d9:
	/* 0x25d9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25de:
	/* 0x25de: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25e2:
	/* 0x25e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25e7:
	/* 0x25e7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ec:
	/* 0x25ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f1:
	/* 0x25f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f3:
	/* 0x25f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25f8:
	/* 0x25f8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25fd:
	/* 0x25fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2602:
	/* 0x2602: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2607:
	/* 0x2607: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2609:
	/* 0x2609: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260d:
	/* 0x260d: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2611:
	/* 0x2611: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_2618:
	/* 0x2618: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_261f:
	/* 0x261f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2622:
	/* 0x2622: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2627:
	/* 0x2627: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_262c:
	/* 0x262c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_2633:
	/* 0x2633: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2638:
	/* 0x2638: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263a:
	/* 0x263a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2641:
	/* 0x2641: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2644:
	/* 0x2644: je     2665 <trace_security_file_mprotect+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2665;
	}
x86_l_2646:
	/* 0x2646: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_264a:
	/* 0x264a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_264f:
	/* 0x264f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2652:
	/* 0x2652: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2654:
	/* 0x2654: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2657:
	/* 0x2657: je     2665 <trace_security_file_mprotect+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2665;
	}
x86_l_2659:
	/* 0x2659: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265c:
	/* 0x265c: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2660:
	/* 0x2660: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2663:
	/* 0x2663: jmp    2667 <trace_security_file_mprotect+0x2667> */
	goto x86_l_2667;
x86_l_2665:
	/* 0x2665: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2667:
	/* 0x2667: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_266a:
	/* 0x266a: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_266d:
	/* 0x266d: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2670:
	/* 0x2670: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2673:
	/* 0x2673: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_267b:
	/* 0x267b: je     275b <trace_security_file_mprotect+0x275b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_275b;
	}
x86_l_2681:
	/* 0x2681: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2688:
	/* 0x2688: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_268c:
	/* 0x268c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2691:
	/* 0x2691: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2696:
	/* 0x2696: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_269b:
	/* 0x269b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269d:
	/* 0x269d: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26a2:
	/* 0x26a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a7:
	/* 0x26a7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ac:
	/* 0x26ac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b1:
	/* 0x26b1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_26b4:
	/* 0x26b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b6:
	/* 0x26b6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ba:
	/* 0x26ba: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_26be:
	/* 0x26be: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_26c2:
	/* 0x26c2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26c6:
	/* 0x26c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26cb:
	/* 0x26cb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d0:
	/* 0x26d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d5:
	/* 0x26d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d7:
	/* 0x26d7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26dc:
	/* 0x26dc: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_26e0:
	/* 0x26e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26e5:
	/* 0x26e5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ea:
	/* 0x26ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26ef:
	/* 0x26ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f1:
	/* 0x26f1: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26f5:
	/* 0x26f5: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26f9:
	/* 0x26f9: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_2700:
	/* 0x2700: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_2707:
	/* 0x2707: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_270a:
	/* 0x270a: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_270f:
	/* 0x270f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2714:
	/* 0x2714: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_271b:
	/* 0x271b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2720:
	/* 0x2720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2722:
	/* 0x2722: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2729:
	/* 0x2729: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_272c:
	/* 0x272c: je     274d <trace_security_file_mprotect+0x274d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274d;
	}
x86_l_272e:
	/* 0x272e: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2732:
	/* 0x2732: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2737:
	/* 0x2737: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_273a:
	/* 0x273a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_273c:
	/* 0x273c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_273f:
	/* 0x273f: je     274d <trace_security_file_mprotect+0x274d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274d;
	}
x86_l_2741:
	/* 0x2741: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2744:
	/* 0x2744: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2748:
	/* 0x2748: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_274b:
	/* 0x274b: jmp    274f <trace_security_file_mprotect+0x274f> */
	goto x86_l_274f;
x86_l_274d:
	/* 0x274d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274f:
	/* 0x274f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2752:
	/* 0x2752: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2755:
	/* 0x2755: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2758:
	/* 0x2758: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_275b:
	/* 0x275b: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_2763:
	/* 0x2763: je     2834 <trace_security_file_mprotect+0x2834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2834;
	}
x86_l_2769:
	/* 0x2769: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_276e:
	/* 0x276e: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2775:
	/* 0x2775: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_277a:
	/* 0x277a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_277f:
	/* 0x277f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2784:
	/* 0x2784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2786:
	/* 0x2786: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_278b:
	/* 0x278b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2790:
	/* 0x2790: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2795:
	/* 0x2795: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279a:
	/* 0x279a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279c:
	/* 0x279c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27a1:
	/* 0x27a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27a6:
	/* 0x27a6: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ab:
	/* 0x27ab: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_27ae:
	/* 0x27ae: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_27b3:
	/* 0x27b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b5:
	/* 0x27b5: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_27b9:
	/* 0x27b9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_27be:
	/* 0x27be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27c1:
	/* 0x27c1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27c6:
	/* 0x27c6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27c9:
	/* 0x27c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cb:
	/* 0x27cb: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_27d2:
	/* 0x27d2: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_27d9:
	/* 0x27d9: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_27dc:
	/* 0x27dc: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27e1:
	/* 0x27e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27e6:
	/* 0x27e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_27ed:
	/* 0x27ed: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27f2:
	/* 0x27f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f4:
	/* 0x27f4: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_27fb:
	/* 0x27fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27fe:
	/* 0x27fe: je     281e <trace_security_file_mprotect+0x281e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281e;
	}
x86_l_2800:
	/* 0x2800: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2805:
	/* 0x2805: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2808:
	/* 0x2808: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_280b:
	/* 0x280b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_280d:
	/* 0x280d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2810:
	/* 0x2810: je     281e <trace_security_file_mprotect+0x281e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281e;
	}
x86_l_2812:
	/* 0x2812: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2815:
	/* 0x2815: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2819:
	/* 0x2819: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_281c:
	/* 0x281c: jmp    2820 <trace_security_file_mprotect+0x2820> */
	goto x86_l_2820;
x86_l_281e:
	/* 0x281e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2820:
	/* 0x2820: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2823:
	/* 0x2823: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2826:
	/* 0x2826: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2829:
	/* 0x2829: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_282c:
	/* 0x282c: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_2834:
	/* 0x2834: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_283c:
	/* 0x283c: je     28be <trace_security_file_mprotect+0x28be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28be;
	}
x86_l_2842:
	/* 0x2842: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2846:
	/* 0x2846: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_284b:
	/* 0x284b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_284e:
	/* 0x284e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2853:
	/* 0x2853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2855:
	/* 0x2855: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_285c:
	/* 0x285c: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_2863:
	/* 0x2863: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2866:
	/* 0x2866: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_286b:
	/* 0x286b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2870:
	/* 0x2870: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_2877:
	/* 0x2877: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2885:
	/* 0x2885: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2888:
	/* 0x2888: je     28a8 <trace_security_file_mprotect+0x28a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a8;
	}
x86_l_288a:
	/* 0x288a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_288f:
	/* 0x288f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2892:
	/* 0x2892: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2895:
	/* 0x2895: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2897:
	/* 0x2897: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_289a:
	/* 0x289a: je     28a8 <trace_security_file_mprotect+0x28a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a8;
	}
x86_l_289c:
	/* 0x289c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_289f:
	/* 0x289f: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a3:
	/* 0x28a3: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28a6:
	/* 0x28a6: jmp    28aa <trace_security_file_mprotect+0x28aa> */
	goto x86_l_28aa;
x86_l_28a8:
	/* 0x28a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28aa:
	/* 0x28aa: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28ad:
	/* 0x28ad: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_28b0:
	/* 0x28b0: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_28b3:
	/* 0x28b3: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_28b6:
	/* 0x28b6: movzx  ebp,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_28be:
	/* 0x28be: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_28c5:
	/* 0x28c5: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_28c8:
	/* 0x28c8: je     292e <trace_security_file_mprotect+0x292e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_292e;
	}
x86_l_28ca:
	/* 0x28ca: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ce:
	/* 0x28ce: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28d2:
	/* 0x28d2: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_28d9:
	/* 0x28d9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28dc:
	/* 0x28dc: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28e1:
	/* 0x28e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e6:
	/* 0x28e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_28ed:
	/* 0x28ed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f2:
	/* 0x28f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f4:
	/* 0x28f4: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_28fb:
	/* 0x28fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28fe:
	/* 0x28fe: je     2920 <trace_security_file_mprotect+0x2920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2920;
	}
x86_l_2900:
	/* 0x2900: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2905:
	/* 0x2905: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_290a:
	/* 0x290a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_290d:
	/* 0x290d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_290f:
	/* 0x290f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2912:
	/* 0x2912: je     2920 <trace_security_file_mprotect+0x2920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2920;
	}
x86_l_2914:
	/* 0x2914: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2917:
	/* 0x2917: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291b:
	/* 0x291b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_291e:
	/* 0x291e: jmp    2922 <trace_security_file_mprotect+0x2922> */
	goto x86_l_2922;
x86_l_2920:
	/* 0x2920: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2922:
	/* 0x2922: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2925:
	/* 0x2925: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2928:
	/* 0x2928: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_292b:
	/* 0x292b: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_292e:
	/* 0x292e: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_2935:
	/* 0x2935: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2938:
	/* 0x2938: je     2999 <trace_security_file_mprotect+0x2999> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2999;
	}
x86_l_293a:
	/* 0x293a: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_2941:
	/* 0x2941: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2944:
	/* 0x2944: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2949:
	/* 0x2949: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294e:
	/* 0x294e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_2955:
	/* 0x2955: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_295a:
	/* 0x295a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295c:
	/* 0x295c: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2963:
	/* 0x2963: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2966:
	/* 0x2966: je     298b <trace_security_file_mprotect+0x298b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_298b;
	}
x86_l_2968:
	/* 0x2968: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_296d:
	/* 0x296d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2970:
	/* 0x2970: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2978:
	/* 0x2978: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_297a:
	/* 0x297a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297d:
	/* 0x297d: je     298b <trace_security_file_mprotect+0x298b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_298b;
	}
x86_l_297f:
	/* 0x297f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2982:
	/* 0x2982: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2986:
	/* 0x2986: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2989:
	/* 0x2989: jmp    298d <trace_security_file_mprotect+0x298d> */
	goto x86_l_298d;
x86_l_298b:
	/* 0x298b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_298d:
	/* 0x298d: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2990:
	/* 0x2990: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2993:
	/* 0x2993: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2996:
	/* 0x2996: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2999:
	/* 0x2999: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_29a0:
	/* 0x29a0: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_29a3:
	/* 0x29a3: je     2a2a <trace_security_file_mprotect+0x2a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10794ULL;
	}
x86_l_29a9:
	/* 0x29a9: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_29b0:
	/* 0x29b0: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_29b3:
	/* 0x29b3: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29b8:
	/* 0x29b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29bd:
	/* 0x29bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_29c4:
	/* 0x29c4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29c9:
	/* 0x29c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29cb:
	/* 0x29cb: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
	return 10706ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10722ULL: goto x86_l_29e2;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10736ULL: goto x86_l_29f0;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10749ULL: goto x86_l_29fd;
	case 10753ULL: goto x86_l_2a01;
	case 10758ULL: goto x86_l_2a06;
	case 10761ULL: goto x86_l_2a09;
	case 10763ULL: goto x86_l_2a0b;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10771ULL: goto x86_l_2a13;
	case 10775ULL: goto x86_l_2a17;
	case 10778ULL: goto x86_l_2a1a;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10791ULL: goto x86_l_2a27;
	case 10794ULL: goto x86_l_2a2a;
	case 10801ULL: goto x86_l_2a31;
	case 10804ULL: goto x86_l_2a34;
	case 10812ULL: goto x86_l_2a3c;
	case 10814ULL: goto x86_l_2a3e;
	case 10822ULL: goto x86_l_2a46;
	case 10826ULL: goto x86_l_2a4a;
	case 10829ULL: goto x86_l_2a4d;
	case 10836ULL: goto x86_l_2a54;
	case 10843ULL: goto x86_l_2a5b;
	case 10846ULL: goto x86_l_2a5e;
	case 10853ULL: goto x86_l_2a65;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10869ULL: goto x86_l_2a75;
	case 10875ULL: goto x86_l_2a7b;
	case 10884ULL: goto x86_l_2a84;
	case 10890ULL: goto x86_l_2a8a;
	case 10899ULL: goto x86_l_2a93;
	case 10908ULL: goto x86_l_2a9c;
	case 10917ULL: goto x86_l_2aa5;
	case 10926ULL: goto x86_l_2aae;
	case 10935ULL: goto x86_l_2ab7;
	case 10944ULL: goto x86_l_2ac0;
	case 10953ULL: goto x86_l_2ac9;
	case 10959ULL: goto x86_l_2acf;
	case 10965ULL: goto x86_l_2ad5;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 11001ULL: goto x86_l_2af9;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11073ULL: goto x86_l_2b41;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11103ULL: goto x86_l_2b5f;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11193ULL: goto x86_l_2bb9;
	case 11198ULL: goto x86_l_2bbe;
	case 11201ULL: goto x86_l_2bc1;
	case 11207ULL: goto x86_l_2bc7;
	case 11211ULL: goto x86_l_2bcb;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11228ULL: goto x86_l_2bdc;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11239ULL: goto x86_l_2be7;
	case 11245ULL: goto x86_l_2bed;
	case 11247ULL: goto x86_l_2bef;
	case 11249ULL: goto x86_l_2bf1;
	case 11255ULL: goto x86_l_2bf7;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11268ULL: goto x86_l_2c04;
	case 11274ULL: goto x86_l_2c0a;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11303ULL: goto x86_l_2c27;
	case 11305ULL: goto x86_l_2c29;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11333ULL: goto x86_l_2c45;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11354ULL: goto x86_l_2c5a;
	case 11360ULL: goto x86_l_2c60;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11384ULL: goto x86_l_2c78;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11409ULL: goto x86_l_2c91;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11440ULL: goto x86_l_2cb0;
	case 11444ULL: goto x86_l_2cb4;
	case 11448ULL: goto x86_l_2cb8;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11472ULL: goto x86_l_2cd0;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11513ULL: goto x86_l_2cf9;
	case 11519ULL: goto x86_l_2cff;
	case 11524ULL: goto x86_l_2d04;
	case 11527ULL: goto x86_l_2d07;
	case 11533ULL: goto x86_l_2d0d;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11554ULL: goto x86_l_2d22;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11566ULL: goto x86_l_2d2e;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11588ULL: goto x86_l_2d44;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11598ULL: goto x86_l_2d4e;
	case 11601ULL: goto x86_l_2d51;
	case 11607ULL: goto x86_l_2d57;
	case 11611ULL: goto x86_l_2d5b;
	case 11617ULL: goto x86_l_2d61;
	case 11621ULL: goto x86_l_2d65;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11654ULL: goto x86_l_2d86;
	case 11659ULL: goto x86_l_2d8b;
	case 11663ULL: goto x86_l_2d8f;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11688ULL: goto x86_l_2da8;
	case 11691ULL: goto x86_l_2dab;
	case 11696ULL: goto x86_l_2db0;
	case 11698ULL: goto x86_l_2db2;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11719ULL: goto x86_l_2dc7;
	case 11723ULL: goto x86_l_2dcb;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11745ULL: goto x86_l_2de1;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11786ULL: goto x86_l_2e0a;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11796ULL: goto x86_l_2e14;
	case 11798ULL: goto x86_l_2e16;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11825ULL: goto x86_l_2e31;
	case 11831ULL: goto x86_l_2e37;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11858ULL: goto x86_l_2e52;
	case 11862ULL: goto x86_l_2e56;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11883ULL: goto x86_l_2e6b;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11912ULL: goto x86_l_2e88;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11966ULL: goto x86_l_2ebe;
	case 11968ULL: goto x86_l_2ec0;
	case 11972ULL: goto x86_l_2ec4;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11984ULL: goto x86_l_2ed0;
	case 11990ULL: goto x86_l_2ed6;
	case 11997ULL: goto x86_l_2edd;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12092ULL: goto x86_l_2f3c;
	case 12096ULL: goto x86_l_2f40;
	case 12102ULL: goto x86_l_2f46;
	case 12106ULL: goto x86_l_2f4a;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12173ULL: goto x86_l_2f8d;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12187ULL: goto x86_l_2f9b;
	case 12193ULL: goto x86_l_2fa1;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12214ULL: goto x86_l_2fb6;
	case 12218ULL: goto x86_l_2fba;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12229ULL: goto x86_l_2fc5;
	case 12231ULL: goto x86_l_2fc7;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12258ULL: goto x86_l_2fe2;
	case 12261ULL: goto x86_l_2fe5;
	case 12266ULL: goto x86_l_2fea;
	case 12272ULL: goto x86_l_2ff0;
	case 12276ULL: goto x86_l_2ff4;
	case 12282ULL: goto x86_l_2ffa;
	case 12286ULL: goto x86_l_2ffe;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12323ULL: goto x86_l_3023;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12348ULL: goto x86_l_303c;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12367ULL: goto x86_l_304f;
	case 12372ULL: goto x86_l_3054;
	case 12377ULL: goto x86_l_3059;
	case 12379ULL: goto x86_l_305b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29d2:
	/* 0x29d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29d5:
	/* 0x29d5: je     2a1c <trace_security_file_mprotect+0x2a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1c;
	}
x86_l_29d7:
	/* 0x29d7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_29da:
	/* 0x29da: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_29e2:
	/* 0x29e2: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29e6:
	/* 0x29e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29eb:
	/* 0x29eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29ee:
	/* 0x29ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f0:
	/* 0x29f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29f3:
	/* 0x29f3: jne    2a10 <trace_security_file_mprotect+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a10;
	}
x86_l_29f5:
	/* 0x29f5: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_29fd:
	/* 0x29fd: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a01:
	/* 0x2a01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a06:
	/* 0x2a06: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a09:
	/* 0x2a09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0b:
	/* 0x2a0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a0e:
	/* 0x2a0e: je     2a1c <trace_security_file_mprotect+0x2a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1c;
	}
x86_l_2a10:
	/* 0x2a10: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a13:
	/* 0x2a13: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a17:
	/* 0x2a17: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2a1a:
	/* 0x2a1a: jmp    2a1e <trace_security_file_mprotect+0x2a1e> */
	goto x86_l_2a1e;
x86_l_2a1c:
	/* 0x2a1c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a1e:
	/* 0x2a1e: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a21:
	/* 0x2a21: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a24:
	/* 0x2a24: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a27:
	/* 0x2a27: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a2a:
	/* 0x2a2a: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2a31:
	/* 0x2a31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a34:
	/* 0x2a34: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2a3c:
	/* 0x2a3c: je     2a4d <trace_security_file_mprotect+0x2a4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4d;
	}
x86_l_2a3e:
	/* 0x2a3e: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a46:
	/* 0x2a46: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_2a4a:
	/* 0x2a4a: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a4d:
	/* 0x2a4d: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2a54:
	/* 0x2a54: mov    rcx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a5b:
	/* 0x2a5b: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a5e:
	/* 0x2a5e: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a65:
	/* 0x2a65: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2a6d:
	/* 0x2a6d: jne    2a7b <trace_security_file_mprotect+0x2a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a7b;
	}
x86_l_2a6f:
	/* 0x2a6f: test   BYTE PTR [r12+0x4],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869188ULL);
x86_l_2a75:
	/* 0x2a75: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_2a7b:
	/* 0x2a7b: cmp    QWORD PTR [rsp+0x138],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2a84:
	/* 0x2a84: jne    32c9 <trace_security_file_mprotect+0x32c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13001ULL;
	}
x86_l_2a8a:
	/* 0x2a8a: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2a93:
	/* 0x2a93: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2aae:
	/* 0x2aae: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2ac0:
	/* 0x2ac0: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2ac9:
	/* 0x2ac9: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2acf:
	/* 0x2acf: je     2c24 <trace_security_file_mprotect+0x2c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c24;
	}
x86_l_2ad5:
	/* 0x2ad5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2add:
	/* 0x2add: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_2ae9:
	/* 0x2ae9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aee:
	/* 0x2aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af0:
	/* 0x2af0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2af3:
	/* 0x2af3: je     2c32 <trace_security_file_mprotect+0x2c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c32;
	}
x86_l_2af9:
	/* 0x2af9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2afc:
	/* 0x2afc: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b01:
	/* 0x2b01: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b05:
	/* 0x2b05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b14:
	/* 0x2b14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b16:
	/* 0x2b16: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1b:
	/* 0x2b1b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b20:
	/* 0x2b20: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b25:
	/* 0x2b25: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2a:
	/* 0x2b2a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b34:
	/* 0x2b34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b36:
	/* 0x2b36: test   BYTE PTR [rsp+0x10],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476768ULL);
x86_l_2b3b:
	/* 0x2b3b: jne    2c39 <trace_security_file_mprotect+0x2c39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c39;
	}
x86_l_2b41:
	/* 0x2b41: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b45:
	/* 0x2b45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4a:
	/* 0x2b4a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b54:
	/* 0x2b54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b56:
	/* 0x2b56: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5b:
	/* 0x2b5b: lea    rax,[r13-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b63:
	/* 0x2b63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b68:
	/* 0x2b68: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6c:
	/* 0x2b6c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b71:
	/* 0x2b71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b76:
	/* 0x2b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b78:
	/* 0x2b78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b7d:
	/* 0x2b7d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b82:
	/* 0x2b82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b87:
	/* 0x2b87: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b8a:
	/* 0x2b8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8c:
	/* 0x2b8c: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b91:
	/* 0x2b91: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b96:
	/* 0x2b96: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b9a:
	/* 0x2b9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b9f:
	/* 0x2b9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba9:
	/* 0x2ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bab:
	/* 0x2bab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bb0:
	/* 0x2bb0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2bb3:
	/* 0x2bb3: je     2c57 <trace_security_file_mprotect+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c57;
	}
x86_l_2bb9:
	/* 0x2bb9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bbe:
	/* 0x2bbe: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2bc1:
	/* 0x2bc1: je     2c57 <trace_security_file_mprotect+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c57;
	}
x86_l_2bc7:
	/* 0x2bc7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd0:
	/* 0x2bd0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd5:
	/* 0x2bd5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bda:
	/* 0x2bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdc:
	/* 0x2bdc: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2be0:
	/* 0x2be0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2be5:
	/* 0x2be5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2be7:
	/* 0x2be7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bed:
	/* 0x2bed: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2bef:
	/* 0x2bef: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2bf1:
	/* 0x2bf1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bf7:
	/* 0x2bf7: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bfa:
	/* 0x2bfa: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2bff:
	/* 0x2bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c01:
	/* 0x2c01: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c04:
	/* 0x2c04: jl     2ee3 <trace_security_file_mprotect+0x2ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2ee3;
	}
x86_l_2c0a:
	/* 0x2c0a: mov    BYTE PTR [rbx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_2c11:
	/* 0x2c11: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_2c17:
	/* 0x2c17: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c1a:
	/* 0x2c1a: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1f:
	/* 0x2c1f: jmp    2cbe <trace_security_file_mprotect+0x2cbe> */
	goto x86_l_2cbe;
x86_l_2c24:
	/* 0x2c24: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c27:
	/* 0x2c27: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c29:
	/* 0x2c29: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c2b:
	/* 0x2c2b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c2d:
	/* 0x2c2d: jmp    323c <trace_security_file_mprotect+0x323c> */
	return 12860ULL;
x86_l_2c32:
	/* 0x2c32: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c34:
	/* 0x2c34: jmp    3106 <trace_security_file_mprotect+0x3106> */
	return 12550ULL;
x86_l_2c39:
	/* 0x2c39: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c3e:
	/* 0x2c3e: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2c45:
	/* 0x2c45: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2c48:
	/* 0x2c48: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c4d:
	/* 0x2c4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4f:
	/* 0x2c4f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c52:
	/* 0x2c52: jmp    30fc <trace_security_file_mprotect+0x30fc> */
	return 12540ULL;
x86_l_2c57:
	/* 0x2c57: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c5a:
	/* 0x2c5a: jne    2ee3 <trace_security_file_mprotect+0x2ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ee3;
	}
x86_l_2c60:
	/* 0x2c60: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c64:
	/* 0x2c64: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2c69:
	/* 0x2c69: je     2ee3 <trace_security_file_mprotect+0x2ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee3;
	}
x86_l_2c6f:
	/* 0x2c6f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c74:
	/* 0x2c74: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c78:
	/* 0x2c78: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c7c:
	/* 0x2c7c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c81:
	/* 0x2c81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c86:
	/* 0x2c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c88:
	/* 0x2c88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c91:
	/* 0x2c91: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c94:
	/* 0x2c94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c99:
	/* 0x2c99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9b:
	/* 0x2c9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca4:
	/* 0x2ca4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cae:
	/* 0x2cae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb0:
	/* 0x2cb0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb4:
	/* 0x2cb4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_2cbe:
	/* 0x2cbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cc3:
	/* 0x2cc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2cd0:
	/* 0x2cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd2:
	/* 0x2cd2: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cdc:
	/* 0x2cdc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ce5:
	/* 0x2ce5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cea:
	/* 0x2cea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cef:
	/* 0x2cef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf1:
	/* 0x2cf1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf6:
	/* 0x2cf6: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2cf9:
	/* 0x2cf9: je     2ecd <trace_security_file_mprotect+0x2ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecd;
	}
x86_l_2cff:
	/* 0x2cff: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d04:
	/* 0x2d04: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d07:
	/* 0x2d07: je     2ecd <trace_security_file_mprotect+0x2ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecd;
	}
x86_l_2d0d:
	/* 0x2d0d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d11:
	/* 0x2d11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d16:
	/* 0x2d16: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d1b:
	/* 0x2d1b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d20:
	/* 0x2d20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d22:
	/* 0x2d22: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d26:
	/* 0x2d26: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d28:
	/* 0x2d28: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_2d31:
	/* 0x2d31: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d33:
	/* 0x2d33: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_2d39:
	/* 0x2d39: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d3e:
	/* 0x2d3e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d44:
	/* 0x2d44: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d47:
	/* 0x2d47: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d4c:
	/* 0x2d4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4e:
	/* 0x2d4e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d51:
	/* 0x2d51: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2ed6;
	}
x86_l_2d57:
	/* 0x2d57: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d5b:
	/* 0x2d5b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d61:
	/* 0x2d61: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d65:
	/* 0x2d65: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d68:
	/* 0x2d68: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6d:
	/* 0x2d6d: jmp    3063 <trace_security_file_mprotect+0x3063> */
	return 12387ULL;
x86_l_2d72:
	/* 0x2d72: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d76:
	/* 0x2d76: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2d7b:
	/* 0x2d7b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d80:
	/* 0x2d80: je     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6182ULL;
	}
x86_l_2d86:
	/* 0x2d86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d8b:
	/* 0x2d8b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8f:
	/* 0x2d8f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d93:
	/* 0x2d93: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d98:
	/* 0x2d98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d9d:
	/* 0x2d9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9f:
	/* 0x2d9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2da4:
	/* 0x2da4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da8:
	/* 0x2da8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2dab:
	/* 0x2dab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db0:
	/* 0x2db0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db2:
	/* 0x2db2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2db7:
	/* 0x2db7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dbb:
	/* 0x2dbb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc5:
	/* 0x2dc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc7:
	/* 0x2dc7: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dcb:
	/* 0x2dcb: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dcf:
	/* 0x2dcf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dd4:
	/* 0x2dd4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dde:
	/* 0x2dde: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2de1:
	/* 0x2de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de3:
	/* 0x2de3: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de8:
	/* 0x2de8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ded:
	/* 0x2ded: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2df1:
	/* 0x2df1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2df6:
	/* 0x2df6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfb:
	/* 0x2dfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e00:
	/* 0x2e00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e02:
	/* 0x2e02: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e07:
	/* 0x2e07: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e0a:
	/* 0x2e0a: je     2e62 <trace_security_file_mprotect+0x2e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e62;
	}
x86_l_2e0c:
	/* 0x2e0c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e11:
	/* 0x2e11: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e14:
	/* 0x2e14: je     2e62 <trace_security_file_mprotect+0x2e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e62;
	}
x86_l_2e16:
	/* 0x2e16: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e1a:
	/* 0x2e1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e1f:
	/* 0x2e1f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e24:
	/* 0x2e24: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e29:
	/* 0x2e29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2b:
	/* 0x2e2b: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e2f:
	/* 0x2e2f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e31:
	/* 0x2e31: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e37:
	/* 0x2e37: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_2e3a:
	/* 0x2e3a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e3c:
	/* 0x2e3c: jae    2f19 <trace_security_file_mprotect+0x2f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f19;
	}
x86_l_2e42:
	/* 0x2e42: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e47:
	/* 0x2e47: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e4a:
	/* 0x2e4a: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_2e4d:
	/* 0x2e4d: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e52:
	/* 0x2e52: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2e56:
	/* 0x2e56: mov    BYTE PTR [rbx+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_2e5d:
	/* 0x2e5d: jmp    1864 <trace_security_file_mprotect+0x1864> */
	return 6244ULL;
x86_l_2e62:
	/* 0x2e62: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e65:
	/* 0x2e65: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_2e6b:
	/* 0x2e6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e6f:
	/* 0x2e6f: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2e74:
	/* 0x2e74: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e79:
	/* 0x2e79: je     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6182ULL;
	}
x86_l_2e7f:
	/* 0x2e7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e84:
	/* 0x2e84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e88:
	/* 0x2e88: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e8c:
	/* 0x2e8c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e91:
	/* 0x2e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e96:
	/* 0x2e96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e98:
	/* 0x2e98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea1:
	/* 0x2ea1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ea4:
	/* 0x2ea4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea9:
	/* 0x2ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eab:
	/* 0x2eab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eb4:
	/* 0x2eb4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebe:
	/* 0x2ebe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec0:
	/* 0x2ec0: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec4:
	/* 0x2ec4: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ec8:
	/* 0x2ec8: jmp    2f52 <trace_security_file_mprotect+0x2f52> */
	goto x86_l_2f52;
x86_l_2ecd:
	/* 0x2ecd: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ed0:
	/* 0x2ed0: je     300b <trace_security_file_mprotect+0x300b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_300b;
	}
x86_l_2ed6:
	/* 0x2ed6: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_2edd:
	/* 0x2edd: jne    30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12510ULL;
	}
x86_l_2ee3:
	/* 0x2ee3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee8:
	/* 0x2ee8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2eec:
	/* 0x2eec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ef1:
	/* 0x2ef1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2efb:
	/* 0x2efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efd:
	/* 0x2efd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f02:
	/* 0x2f02: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f07:
	/* 0x2f07: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2f0a:
	/* 0x2f0a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f0f:
	/* 0x2f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f11:
	/* 0x2f11: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f14:
	/* 0x2f14: jmp    30f4 <trace_security_file_mprotect+0x30f4> */
	return 12532ULL;
x86_l_2f19:
	/* 0x2f19: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f1e:
	/* 0x2f1e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f24:
	/* 0x2f24: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f27:
	/* 0x2f27: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f2c:
	/* 0x2f2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f2e:
	/* 0x2f2e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f31:
	/* 0x2f31: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f36:
	/* 0x2f36: jl     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6182ULL;
	}
x86_l_2f3c:
	/* 0x2f3c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f40:
	/* 0x2f40: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f46:
	/* 0x2f46: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f4a:
	/* 0x2f4a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f4d:
	/* 0x2f4d: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f52:
	/* 0x2f52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f57:
	/* 0x2f57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f5c:
	/* 0x2f5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f61:
	/* 0x2f61: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2f64:
	/* 0x2f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f66:
	/* 0x2f66: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6b:
	/* 0x2f6b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f70:
	/* 0x2f70: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f74:
	/* 0x2f74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f79:
	/* 0x2f79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f83:
	/* 0x2f83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f85:
	/* 0x2f85: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f8a:
	/* 0x2f8a: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f8d:
	/* 0x2f8d: je     3c2d <trace_security_file_mprotect+0x3c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15405ULL;
	}
x86_l_2f93:
	/* 0x2f93: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f98:
	/* 0x2f98: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f9b:
	/* 0x2f9b: je     3c2d <trace_security_file_mprotect+0x3c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15405ULL;
	}
x86_l_2fa1:
	/* 0x2fa1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fa5:
	/* 0x2fa5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2faa:
	/* 0x2faa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2faf:
	/* 0x2faf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2fb4:
	/* 0x2fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb6:
	/* 0x2fb6: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2fba:
	/* 0x2fba: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fbc:
	/* 0x2fbc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_2fc5:
	/* 0x2fc5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fc7:
	/* 0x2fc7: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e42;
	}
x86_l_2fcd:
	/* 0x2fcd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fd2:
	/* 0x2fd2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2fd8:
	/* 0x2fd8: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fdb:
	/* 0x2fdb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2fe0:
	/* 0x2fe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe2:
	/* 0x2fe2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fe5:
	/* 0x2fe5: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fea:
	/* 0x2fea: jl     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6182ULL;
	}
x86_l_2ff0:
	/* 0x2ff0: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2ff4:
	/* 0x2ff4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ffa:
	/* 0x2ffa: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ffe:
	/* 0x2ffe: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3001:
	/* 0x3001: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3006:
	/* 0x3006: jmp    3c93 <trace_security_file_mprotect+0x3c93> */
	return 15507ULL;
x86_l_300b:
	/* 0x300b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_300f:
	/* 0x300f: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3014:
	/* 0x3014: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed6;
	}
x86_l_301a:
	/* 0x301a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_301f:
	/* 0x301f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3023:
	/* 0x3023: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3027:
	/* 0x3027: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_302c:
	/* 0x302c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3031:
	/* 0x3031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3033:
	/* 0x3033: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3038:
	/* 0x3038: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303c:
	/* 0x303c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_303f:
	/* 0x303f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3044:
	/* 0x3044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3046:
	/* 0x3046: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_304b:
	/* 0x304b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304f:
	/* 0x304f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3054:
	/* 0x3054: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3059:
	/* 0x3059: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305b:
	/* 0x305b: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 12383ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12383ULL: goto x86_l_305f;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
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
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12460ULL: goto x86_l_30ac;
	case 12466ULL: goto x86_l_30b2;
	case 12470ULL: goto x86_l_30b6;
	case 12475ULL: goto x86_l_30bb;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12487ULL: goto x86_l_30c7;
	case 12491ULL: goto x86_l_30cb;
	case 12493ULL: goto x86_l_30cd;
	case 12499ULL: goto x86_l_30d3;
	case 12502ULL: goto x86_l_30d6;
	case 12504ULL: goto x86_l_30d8;
	case 12510ULL: goto x86_l_30de;
	case 12513ULL: goto x86_l_30e1;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12540ULL: goto x86_l_30fc;
	case 12547ULL: goto x86_l_3103;
	case 12550ULL: goto x86_l_3106;
	case 12555ULL: goto x86_l_310b;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12574ULL: goto x86_l_311e;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12652ULL: goto x86_l_316c;
	case 12655ULL: goto x86_l_316f;
	case 12657ULL: goto x86_l_3171;
	case 12661ULL: goto x86_l_3175;
	case 12666ULL: goto x86_l_317a;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12686ULL: goto x86_l_318e;
	case 12688ULL: goto x86_l_3190;
	case 12693ULL: goto x86_l_3195;
	case 12696ULL: goto x86_l_3198;
	case 12698ULL: goto x86_l_319a;
	case 12703ULL: goto x86_l_319f;
	case 12708ULL: goto x86_l_31a4;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12752ULL: goto x86_l_31d0;
	case 12755ULL: goto x86_l_31d3;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12827ULL: goto x86_l_321b;
	case 12829ULL: goto x86_l_321d;
	case 12834ULL: goto x86_l_3222;
	case 12839ULL: goto x86_l_3227;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12886ULL: goto x86_l_3256;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12933ULL: goto x86_l_3285;
	case 12938ULL: goto x86_l_328a;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12959ULL: goto x86_l_329f;
	case 12966ULL: goto x86_l_32a6;
	case 12977ULL: goto x86_l_32b1;
	case 12985ULL: goto x86_l_32b9;
	case 12993ULL: goto x86_l_32c1;
	case 13001ULL: goto x86_l_32c9;
	case 13010ULL: goto x86_l_32d2;
	case 13016ULL: goto x86_l_32d8;
	case 13025ULL: goto x86_l_32e1;
	case 13027ULL: goto x86_l_32e3;
	case 13035ULL: goto x86_l_32eb;
	case 13038ULL: goto x86_l_32ee;
	case 13040ULL: goto x86_l_32f0;
	case 13048ULL: goto x86_l_32f8;
	case 13050ULL: goto x86_l_32fa;
	case 13052ULL: goto x86_l_32fc;
	case 13054ULL: goto x86_l_32fe;
	case 13057ULL: goto x86_l_3301;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13076ULL: goto x86_l_3314;
	case 13084ULL: goto x86_l_331c;
	case 13087ULL: goto x86_l_331f;
	case 13089ULL: goto x86_l_3321;
	case 13097ULL: goto x86_l_3329;
	case 13100ULL: goto x86_l_332c;
	case 13102ULL: goto x86_l_332e;
	case 13104ULL: goto x86_l_3330;
	case 13106ULL: goto x86_l_3332;
	case 13112ULL: goto x86_l_3338;
	case 13120ULL: goto x86_l_3340;
	case 13122ULL: goto x86_l_3342;
	case 13130ULL: goto x86_l_334a;
	case 13132ULL: goto x86_l_334c;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13141ULL: goto x86_l_3355;
	case 13144ULL: goto x86_l_3358;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13157ULL: goto x86_l_3365;
	case 13163ULL: goto x86_l_336b;
	case 13165ULL: goto x86_l_336d;
	case 13168ULL: goto x86_l_3370;
	case 13176ULL: goto x86_l_3378;
	case 13178ULL: goto x86_l_337a;
	case 13180ULL: goto x86_l_337c;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13193ULL: goto x86_l_3389;
	case 13199ULL: goto x86_l_338f;
	case 13201ULL: goto x86_l_3391;
	case 13209ULL: goto x86_l_3399;
	case 13211ULL: goto x86_l_339b;
	case 13218ULL: goto x86_l_33a2;
	case 13226ULL: goto x86_l_33aa;
	case 13233ULL: goto x86_l_33b1;
	case 13235ULL: goto x86_l_33b3;
	case 13244ULL: goto x86_l_33bc;
	case 13250ULL: goto x86_l_33c2;
	case 13252ULL: goto x86_l_33c4;
	case 13256ULL: goto x86_l_33c8;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13283ULL: goto x86_l_33e3;
	case 13285ULL: goto x86_l_33e5;
	case 13288ULL: goto x86_l_33e8;
	case 13296ULL: goto x86_l_33f0;
	case 13303ULL: goto x86_l_33f7;
	case 13311ULL: goto x86_l_33ff;
	case 13318ULL: goto x86_l_3406;
	case 13320ULL: goto x86_l_3408;
	case 13329ULL: goto x86_l_3411;
	case 13335ULL: goto x86_l_3417;
	case 13337ULL: goto x86_l_3419;
	case 13341ULL: goto x86_l_341d;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13361ULL: goto x86_l_3431;
	case 13366ULL: goto x86_l_3436;
	case 13368ULL: goto x86_l_3438;
	case 13371ULL: goto x86_l_343b;
	case 13373ULL: goto x86_l_343d;
	case 13376ULL: goto x86_l_3440;
	case 13384ULL: goto x86_l_3448;
	case 13391ULL: goto x86_l_344f;
	case 13399ULL: goto x86_l_3457;
	case 13406ULL: goto x86_l_345e;
	case 13408ULL: goto x86_l_3460;
	case 13417ULL: goto x86_l_3469;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13429ULL: goto x86_l_3475;
	case 13436ULL: goto x86_l_347c;
	case 13441ULL: goto x86_l_3481;
	case 13449ULL: goto x86_l_3489;
	case 13454ULL: goto x86_l_348e;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13464ULL: goto x86_l_3498;
	case 13472ULL: goto x86_l_34a0;
	case 13479ULL: goto x86_l_34a7;
	case 13487ULL: goto x86_l_34af;
	case 13494ULL: goto x86_l_34b6;
	case 13496ULL: goto x86_l_34b8;
	case 13505ULL: goto x86_l_34c1;
	case 13511ULL: goto x86_l_34c7;
	case 13513ULL: goto x86_l_34c9;
	case 13517ULL: goto x86_l_34cd;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13537ULL: goto x86_l_34e1;
	case 13542ULL: goto x86_l_34e6;
	case 13544ULL: goto x86_l_34e8;
	case 13547ULL: goto x86_l_34eb;
	case 13549ULL: goto x86_l_34ed;
	case 13552ULL: goto x86_l_34f0;
	case 13560ULL: goto x86_l_34f8;
	case 13567ULL: goto x86_l_34ff;
	case 13575ULL: goto x86_l_3507;
	case 13582ULL: goto x86_l_350e;
	case 13584ULL: goto x86_l_3510;
	case 13593ULL: goto x86_l_3519;
	case 13599ULL: goto x86_l_351f;
	case 13601ULL: goto x86_l_3521;
	case 13605ULL: goto x86_l_3525;
	case 13612ULL: goto x86_l_352c;
	case 13617ULL: goto x86_l_3531;
	case 13625ULL: goto x86_l_3539;
	case 13630ULL: goto x86_l_353e;
	case 13632ULL: goto x86_l_3540;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13640ULL: goto x86_l_3548;
	case 13648ULL: goto x86_l_3550;
	case 13655ULL: goto x86_l_3557;
	case 13663ULL: goto x86_l_355f;
	case 13666ULL: goto x86_l_3562;
	case 13672ULL: goto x86_l_3568;
	case 13680ULL: goto x86_l_3570;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13697ULL: goto x86_l_3581;
	case 13705ULL: goto x86_l_3589;
	case 13713ULL: goto x86_l_3591;
	case 13718ULL: goto x86_l_3596;
	case 13720ULL: goto x86_l_3598;
	case 13725ULL: goto x86_l_359d;
	case 13733ULL: goto x86_l_35a5;
	case 13737ULL: goto x86_l_35a9;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13751ULL: goto x86_l_35b7;
	case 13753ULL: goto x86_l_35b9;
	case 13755ULL: goto x86_l_35bb;
	case 13763ULL: goto x86_l_35c3;
	case 13770ULL: goto x86_l_35ca;
	case 13772ULL: goto x86_l_35cc;
	case 13780ULL: goto x86_l_35d4;
	case 13788ULL: goto x86_l_35dc;
	case 13791ULL: goto x86_l_35df;
	case 13799ULL: goto x86_l_35e7;
	case 13806ULL: goto x86_l_35ee;
	case 13814ULL: goto x86_l_35f6;
	case 13821ULL: goto x86_l_35fd;
	case 13823ULL: goto x86_l_35ff;
	case 13832ULL: goto x86_l_3608;
	case 13838ULL: goto x86_l_360e;
	case 13840ULL: goto x86_l_3610;
	case 13848ULL: goto x86_l_3618;
	case 13852ULL: goto x86_l_361c;
	case 13859ULL: goto x86_l_3623;
	case 13864ULL: goto x86_l_3628;
	case 13869ULL: goto x86_l_362d;
	case 13871ULL: goto x86_l_362f;
	case 13874ULL: goto x86_l_3632;
	case 13876ULL: goto x86_l_3634;
	case 13879ULL: goto x86_l_3637;
	case 13887ULL: goto x86_l_363f;
	case 13894ULL: goto x86_l_3646;
	case 13902ULL: goto x86_l_364e;
	case 13909ULL: goto x86_l_3655;
	case 13911ULL: goto x86_l_3657;
	case 13920ULL: goto x86_l_3660;
	case 13926ULL: goto x86_l_3666;
	case 13928ULL: goto x86_l_3668;
	case 13936ULL: goto x86_l_3670;
	case 13940ULL: goto x86_l_3674;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13957ULL: goto x86_l_3685;
	case 13959ULL: goto x86_l_3687;
	case 13962ULL: goto x86_l_368a;
	case 13964ULL: goto x86_l_368c;
	case 13967ULL: goto x86_l_368f;
	case 13975ULL: goto x86_l_3697;
	case 13982ULL: goto x86_l_369e;
	case 13990ULL: goto x86_l_36a6;
	case 13997ULL: goto x86_l_36ad;
	case 13999ULL: goto x86_l_36af;
	case 14008ULL: goto x86_l_36b8;
	case 14014ULL: goto x86_l_36be;
	case 14016ULL: goto x86_l_36c0;
	case 14024ULL: goto x86_l_36c8;
	case 14028ULL: goto x86_l_36cc;
	case 14035ULL: goto x86_l_36d3;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14047ULL: goto x86_l_36df;
	case 14050ULL: goto x86_l_36e2;
	case 14052ULL: goto x86_l_36e4;
	case 14055ULL: goto x86_l_36e7;
	case 14063ULL: goto x86_l_36ef;
	case 14070ULL: goto x86_l_36f6;
	case 14077ULL: goto x86_l_36fd;
	case 14081ULL: goto x86_l_3701;
	case 14086ULL: goto x86_l_3706;
	case 14091ULL: goto x86_l_370b;
	case 14096ULL: goto x86_l_3710;
	case 14099ULL: goto x86_l_3713;
	case 14101ULL: goto x86_l_3715;
	case 14106ULL: goto x86_l_371a;
	case 14114ULL: goto x86_l_3722;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14128ULL: goto x86_l_3730;
	case 14133ULL: goto x86_l_3735;
	case 14135ULL: goto x86_l_3737;
	case 14140ULL: goto x86_l_373c;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14161ULL: goto x86_l_3751;
	case 14166ULL: goto x86_l_3756;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14180ULL: goto x86_l_3764;
	case 14185ULL: goto x86_l_3769;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14195ULL: goto x86_l_3773;
	case 14199ULL: goto x86_l_3777;
	case 14204ULL: goto x86_l_377c;
	case 14209ULL: goto x86_l_3781;
	case 14214ULL: goto x86_l_3786;
	case 14217ULL: goto x86_l_3789;
	case 14219ULL: goto x86_l_378b;
	case 14224ULL: goto x86_l_3790;
	case 14229ULL: goto x86_l_3795;
	case 14234ULL: goto x86_l_379a;
	case 14239ULL: goto x86_l_379f;
	case 14242ULL: goto x86_l_37a2;
	case 14244ULL: goto x86_l_37a4;
	case 14248ULL: goto x86_l_37a8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_305f:
	/* 0x305f: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3063:
	/* 0x3063: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3068:
	/* 0x3068: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306d:
	/* 0x306d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3072:
	/* 0x3072: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3075:
	/* 0x3075: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3077:
	/* 0x3077: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_307c:
	/* 0x307c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3081:
	/* 0x3081: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3085:
	/* 0x3085: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_308a:
	/* 0x308a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_308f:
	/* 0x308f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3094:
	/* 0x3094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3096:
	/* 0x3096: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309b:
	/* 0x309b: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_309e:
	/* 0x309e: je     3d47 <trace_security_file_mprotect+0x3d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15687ULL;
	}
x86_l_30a4:
	/* 0x30a4: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a9:
	/* 0x30a9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_30ac:
	/* 0x30ac: je     3d47 <trace_security_file_mprotect+0x3d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15687ULL;
	}
x86_l_30b2:
	/* 0x30b2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30b6:
	/* 0x30b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30bb:
	/* 0x30bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c0:
	/* 0x30c0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30c5:
	/* 0x30c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c7:
	/* 0x30c7: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_30cb:
	/* 0x30cb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30cd:
	/* 0x30cd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30d3:
	/* 0x30d3: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_30d6:
	/* 0x30d6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30d8:
	/* 0x30d8: jae    3ddd <trace_security_file_mprotect+0x3ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15837ULL;
	}
x86_l_30de:
	/* 0x30de: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_30e1:
	/* 0x30e1: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_30e4:
	/* 0x30e4: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_30e9:
	/* 0x30e9: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_30ed:
	/* 0x30ed: mov    BYTE PTR [rbx+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_30f4:
	/* 0x30f4: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_30fc:
	/* 0x30fc: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3103:
	/* 0x3103: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3106:
	/* 0x3106: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_310b:
	/* 0x310b: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_310f:
	/* 0x310f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3114:
	/* 0x3114: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3119:
	/* 0x3119: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_311e:
	/* 0x311e: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_3121:
	/* 0x3121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3123:
	/* 0x3123: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_312c:
	/* 0x312c: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3131:
	/* 0x3131: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_313a:
	/* 0x313a: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_313e:
	/* 0x313e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3143:
	/* 0x3143: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3148:
	/* 0x3148: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314d:
	/* 0x314d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314f:
	/* 0x314f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3154:
	/* 0x3154: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3159:
	/* 0x3159: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_315d:
	/* 0x315d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3162:
	/* 0x3162: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3167:
	/* 0x3167: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_316c:
	/* 0x316c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_316f:
	/* 0x316f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3171:
	/* 0x3171: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3175:
	/* 0x3175: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317a:
	/* 0x317a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_317f:
	/* 0x317f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3184:
	/* 0x3184: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3189:
	/* 0x3189: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_318e:
	/* 0x318e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3190:
	/* 0x3190: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3195:
	/* 0x3195: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3198:
	/* 0x3198: js     31be <trace_security_file_mprotect+0x31be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31be;
	}
x86_l_319a:
	/* 0x319a: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_319f:
	/* 0x319f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a4:
	/* 0x31a4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a9:
	/* 0x31a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ae:
	/* 0x31ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b0:
	/* 0x31b0: imul   r15,r15,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R15, X86_R15, X86_WIDTH_64, 1000000000ULL);
x86_l_31b7:
	/* 0x31b7: add    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_31bc:
	/* 0x31bc: jmp    31c1 <trace_security_file_mprotect+0x31c1> */
	goto x86_l_31c1;
x86_l_31be:
	/* 0x31be: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31c1:
	/* 0x31c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31c6:
	/* 0x31c6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31cb:
	/* 0x31cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d0:
	/* 0x31d0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31d3:
	/* 0x31d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d5:
	/* 0x31d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31da:
	/* 0x31da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31df:
	/* 0x31df: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31e3:
	/* 0x31e3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e8:
	/* 0x31e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ed:
	/* 0x31ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ef:
	/* 0x31ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31f4:
	/* 0x31f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f9:
	/* 0x31f9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31fe:
	/* 0x31fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3203:
	/* 0x3203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3205:
	/* 0x3205: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3209:
	/* 0x3209: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_320e:
	/* 0x320e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3213:
	/* 0x3213: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3218:
	/* 0x3218: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_321b:
	/* 0x321b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321d:
	/* 0x321d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3222:
	/* 0x3222: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3227:
	/* 0x3227: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_322b:
	/* 0x322b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3230:
	/* 0x3230: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3235:
	/* 0x3235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3237:
	/* 0x3237: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_323c:
	/* 0x323c: mov    QWORD PTR [rsp+0xf0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3244:
	/* 0x3244: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3249:
	/* 0x3249: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_324e:
	/* 0x324e: mov    QWORD PTR [rsp+0xf8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3256:
	/* 0x3256: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_325e:
	/* 0x325e: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3263:
	/* 0x3263: mov    QWORD PTR [rsp+0x108],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_326b:
	/* 0x326b: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3270:
	/* 0x3270: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3278:
	/* 0x3278: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_327d:
	/* 0x327d: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3285:
	/* 0x3285: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_328a:
	/* 0x328a: mov    QWORD PTR [rsp+0x120],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3292:
	/* 0x3292: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3297:
	/* 0x3297: mov    QWORD PTR [rsp+0x128],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_329f:
	/* 0x329f: mov    DWORD PTR [rsp+0x130],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_32a6:
	/* 0x32a6: mov    DWORD PTR [rsp+0x134],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_32b1:
	/* 0x32b1: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_32b9:
	/* 0x32b9: mov    QWORD PTR [rsp+0x140],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_32c1:
	/* 0x32c1: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_32c9:
	/* 0x32c9: cmp    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_32d2:
	/* 0x32d2: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_32d8:
	/* 0x32d8: cmp    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_32e1:
	/* 0x32e1: je     3308 <trace_security_file_mprotect+0x3308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3308;
	}
x86_l_32e3:
	/* 0x32e3: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_32eb:
	/* 0x32eb: test   dl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_32ee:
	/* 0x32ee: jne    3321 <trace_security_file_mprotect+0x3321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3321;
	}
x86_l_32f0:
	/* 0x32f0: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_32f8:
	/* 0x32f8: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_32fa:
	/* 0x32fa: jne    3342 <trace_security_file_mprotect+0x3342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3342;
	}
x86_l_32fc:
	/* 0x32fc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32fe:
	/* 0x32fe: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_3301:
	/* 0x3301: jne    3355 <trace_security_file_mprotect+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3355;
	}
x86_l_3303:
	/* 0x3303: jmp    3387 <trace_security_file_mprotect+0x3387> */
	goto x86_l_3387;
x86_l_3308:
	/* 0x3308: mov    QWORD PTR [rsp+0xd8],0x1000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712940032ULL);
x86_l_3314:
	/* 0x3314: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_331c:
	/* 0x331c: test   dl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_331f:
	/* 0x331f: je     32f0 <trace_security_file_mprotect+0x32f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f0;
	}
x86_l_3321:
	/* 0x3321: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3329:
	/* 0x3329: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_332c:
	/* 0x332c: jne    3353 <trace_security_file_mprotect+0x3353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3353;
	}
x86_l_332e:
	/* 0x332e: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3330:
	/* 0x3330: test   al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_3332:
	/* 0x3332: jne    3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15388ULL;
	}
x86_l_3338:
	/* 0x3338: mov    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_3340:
	/* 0x3340: jmp    338f <trace_security_file_mprotect+0x338f> */
	goto x86_l_338f;
x86_l_3342:
	/* 0x3342: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_334a:
	/* 0x334a: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_334c:
	/* 0x334c: test   dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_334f:
	/* 0x334f: jne    3355 <trace_security_file_mprotect+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3355;
	}
x86_l_3351:
	/* 0x3351: jmp    3387 <trace_security_file_mprotect+0x3387> */
	goto x86_l_3387;
x86_l_3353:
	/* 0x3353: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3355:
	/* 0x3355: and    eax,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 6ULL);
x86_l_3358:
	/* 0x3358: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_335b:
	/* 0x335b: jne    3387 <trace_security_file_mprotect+0x3387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3387;
	}
x86_l_335d:
	/* 0x335d: mov    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_3365:
	/* 0x3365: movzx  eax,BYTE PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_336b:
	/* 0x336b: and    al,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 4ULL);
x86_l_336d:
	/* 0x336d: shr    al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 2ULL);
x86_l_3370:
	/* 0x3370: cmp    QWORD PTR [r14+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3378:
	/* 0x3378: jne    339b <trace_security_file_mprotect+0x339b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_339b;
	}
x86_l_337a:
	/* 0x337a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_337c:
	/* 0x337c: jne    3b66 <trace_security_file_mprotect+0x3b66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15206ULL;
	}
x86_l_3382:
	/* 0x3382: jmp    3c1c <trace_security_file_mprotect+0x3c1c> */
	return 15388ULL;
x86_l_3387:
	/* 0x3387: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3389:
	/* 0x3389: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15388ULL;
	}
x86_l_338f:
	/* 0x338f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3391:
	/* 0x3391: cmp    QWORD PTR [r14+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3399:
	/* 0x3399: je     337a <trace_security_file_mprotect+0x337a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_337a;
	}
x86_l_339b:
	/* 0x339b: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_33a2:
	/* 0x33a2: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33aa:
	/* 0x33aa: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_33b1:
	/* 0x33b1: ja     33f7 <trace_security_file_mprotect+0x33f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33f7;
	}
x86_l_33b3:
	/* 0x33b3: mov    BYTE PTR [r14+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_33bc:
	/* 0x33bc: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_33c2:
	/* 0x33c2: ja     33f7 <trace_security_file_mprotect+0x33f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33f7;
	}
x86_l_33c4:
	/* 0x33c4: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_33c8:
	/* 0x33c8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_33cf:
	/* 0x33cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33d4:
	/* 0x33d4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d9:
	/* 0x33d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33de:
	/* 0x33de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e0:
	/* 0x33e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33e3:
	/* 0x33e3: js     33f7 <trace_security_file_mprotect+0x33f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33f7;
	}
x86_l_33e5:
	/* 0x33e5: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_33e8:
	/* 0x33e8: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_33f0:
	/* 0x33f0: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_33f7:
	/* 0x33f7: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33ff:
	/* 0x33ff: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3406:
	/* 0x3406: ja     344f <trace_security_file_mprotect+0x344f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_344f;
	}
x86_l_3408:
	/* 0x3408: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_3411:
	/* 0x3411: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3417:
	/* 0x3417: ja     344f <trace_security_file_mprotect+0x344f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_344f;
	}
x86_l_3419:
	/* 0x3419: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_341d:
	/* 0x341d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3424:
	/* 0x3424: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3429:
	/* 0x3429: lea    rdx,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3431:
	/* 0x3431: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3436:
	/* 0x3436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3438:
	/* 0x3438: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_343b:
	/* 0x343b: js     344f <trace_security_file_mprotect+0x344f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_344f;
	}
x86_l_343d:
	/* 0x343d: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3440:
	/* 0x3440: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3448:
	/* 0x3448: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_344f:
	/* 0x344f: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3457:
	/* 0x3457: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_345e:
	/* 0x345e: ja     34a7 <trace_security_file_mprotect+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34a7;
	}
x86_l_3460:
	/* 0x3460: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_3469:
	/* 0x3469: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_346f:
	/* 0x346f: ja     34a7 <trace_security_file_mprotect+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34a7;
	}
x86_l_3471:
	/* 0x3471: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3475:
	/* 0x3475: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_347c:
	/* 0x347c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3481:
	/* 0x3481: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3489:
	/* 0x3489: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_348e:
	/* 0x348e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3490:
	/* 0x3490: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3493:
	/* 0x3493: js     34a7 <trace_security_file_mprotect+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34a7;
	}
x86_l_3495:
	/* 0x3495: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3498:
	/* 0x3498: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34a0:
	/* 0x34a0: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_34a7:
	/* 0x34a7: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34af:
	/* 0x34af: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_34b6:
	/* 0x34b6: ja     34ff <trace_security_file_mprotect+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34ff;
	}
x86_l_34b8:
	/* 0x34b8: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_34c1:
	/* 0x34c1: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_34c7:
	/* 0x34c7: ja     34ff <trace_security_file_mprotect+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34ff;
	}
x86_l_34c9:
	/* 0x34c9: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_34cd:
	/* 0x34cd: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_34d4:
	/* 0x34d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34d9:
	/* 0x34d9: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_34e1:
	/* 0x34e1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34e6:
	/* 0x34e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e8:
	/* 0x34e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34eb:
	/* 0x34eb: js     34ff <trace_security_file_mprotect+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34ff;
	}
x86_l_34ed:
	/* 0x34ed: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_34f0:
	/* 0x34f0: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34f8:
	/* 0x34f8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_34ff:
	/* 0x34ff: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3507:
	/* 0x3507: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_350e:
	/* 0x350e: ja     3557 <trace_security_file_mprotect+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3557;
	}
x86_l_3510:
	/* 0x3510: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_3519:
	/* 0x3519: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_351f:
	/* 0x351f: ja     3557 <trace_security_file_mprotect+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3557;
	}
x86_l_3521:
	/* 0x3521: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3525:
	/* 0x3525: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_352c:
	/* 0x352c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3531:
	/* 0x3531: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3539:
	/* 0x3539: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_353e:
	/* 0x353e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3540:
	/* 0x3540: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3543:
	/* 0x3543: js     3557 <trace_security_file_mprotect+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3557;
	}
x86_l_3545:
	/* 0x3545: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3548:
	/* 0x3548: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3550:
	/* 0x3550: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3557:
	/* 0x3557: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_355f:
	/* 0x355f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3562:
	/* 0x3562: je     36f6 <trace_security_file_mprotect+0x36f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f6;
	}
x86_l_3568:
	/* 0x3568: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3570:
	/* 0x3570: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_3576:
	/* 0x3576: ja     35ee <trace_security_file_mprotect+0x35ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35ee;
	}
x86_l_3578:
	/* 0x3578: mov    BYTE PTR [r14+rax*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519557ULL);
x86_l_3581:
	/* 0x3581: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3589:
	/* 0x3589: mov    WORD PTR [r14+0x7d96],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32150ULL);
x86_l_3591:
	/* 0x3591: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_3596:
	/* 0x3596: ja     35ee <trace_security_file_mprotect+0x35ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35ee;
	}
x86_l_3598:
	/* 0x3598: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_359d:
	/* 0x359d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35a5:
	/* 0x35a5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_35a9:
	/* 0x35a9: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_35b0:
	/* 0x35b0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35b5:
	/* 0x35b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b7:
	/* 0x35b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35b9:
	/* 0x35b9: jle    35ee <trace_security_file_mprotect+0x35ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_35ee;
	}
x86_l_35bb:
	/* 0x35bb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35c3:
	/* 0x35c3: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_35ca:
	/* 0x35ca: ja     35ee <trace_security_file_mprotect+0x35ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35ee;
	}
x86_l_35cc:
	/* 0x35cc: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_35d4:
	/* 0x35d4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_35dc:
	/* 0x35dc: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_35df:
	/* 0x35df: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35e7:
	/* 0x35e7: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_35ee:
	/* 0x35ee: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35f6:
	/* 0x35f6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_35fd:
	/* 0x35fd: ja     3646 <trace_security_file_mprotect+0x3646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3646;
	}
x86_l_35ff:
	/* 0x35ff: mov    BYTE PTR [r14+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_3608:
	/* 0x3608: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_360e:
	/* 0x360e: ja     3646 <trace_security_file_mprotect+0x3646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3646;
	}
x86_l_3610:
	/* 0x3610: lea    rdx,[rsp+0x130] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3618:
	/* 0x3618: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_361c:
	/* 0x361c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3623:
	/* 0x3623: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3628:
	/* 0x3628: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_362d:
	/* 0x362d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362f:
	/* 0x362f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3632:
	/* 0x3632: js     3646 <trace_security_file_mprotect+0x3646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3646;
	}
x86_l_3634:
	/* 0x3634: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3637:
	/* 0x3637: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_363f:
	/* 0x363f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3646:
	/* 0x3646: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_364e:
	/* 0x364e: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3655:
	/* 0x3655: ja     369e <trace_security_file_mprotect+0x369e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_369e;
	}
x86_l_3657:
	/* 0x3657: mov    BYTE PTR [r14+rbx*1+0x89],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519559ULL);
x86_l_3660:
	/* 0x3660: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3666:
	/* 0x3666: ja     369e <trace_security_file_mprotect+0x369e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_369e;
	}
x86_l_3668:
	/* 0x3668: lea    rdx,[rsp+0x138] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3670:
	/* 0x3670: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3674:
	/* 0x3674: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_367b:
	/* 0x367b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3680:
	/* 0x3680: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3685:
	/* 0x3685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3687:
	/* 0x3687: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_368a:
	/* 0x368a: js     369e <trace_security_file_mprotect+0x369e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_369e;
	}
x86_l_368c:
	/* 0x368c: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_368f:
	/* 0x368f: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3697:
	/* 0x3697: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_369e:
	/* 0x369e: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36a6:
	/* 0x36a6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_36ad:
	/* 0x36ad: ja     36f6 <trace_security_file_mprotect+0x36f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_36f6;
	}
x86_l_36af:
	/* 0x36af: mov    BYTE PTR [r14+rbx*1+0x89],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519560ULL);
x86_l_36b8:
	/* 0x36b8: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_36be:
	/* 0x36be: ja     36f6 <trace_security_file_mprotect+0x36f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_36f6;
	}
x86_l_36c0:
	/* 0x36c0: lea    rdx,[rsp+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_36c8:
	/* 0x36c8: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_36cc:
	/* 0x36cc: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_36d3:
	/* 0x36d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36d8:
	/* 0x36d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36dd:
	/* 0x36dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36df:
	/* 0x36df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36e2:
	/* 0x36e2: js     36f6 <trace_security_file_mprotect+0x36f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36f6;
	}
x86_l_36e4:
	/* 0x36e4: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_36e7:
	/* 0x36e7: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_36ef:
	/* 0x36ef: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_36f6:
	/* 0x36f6: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_36fd:
	/* 0x36fd: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3701:
	/* 0x3701: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3706:
	/* 0x3706: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_370b:
	/* 0x370b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3710:
	/* 0x3710: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3713:
	/* 0x3713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3715:
	/* 0x3715: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_371a:
	/* 0x371a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3722:
	/* 0x3722: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3726:
	/* 0x3726: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_372b:
	/* 0x372b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3730:
	/* 0x3730: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3735:
	/* 0x3735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3737:
	/* 0x3737: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_373c:
	/* 0x373c: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3740:
	/* 0x3740: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3745:
	/* 0x3745: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_374a:
	/* 0x374a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_374f:
	/* 0x374f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3751:
	/* 0x3751: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3756:
	/* 0x3756: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_375a:
	/* 0x375a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_375f:
	/* 0x375f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3764:
	/* 0x3764: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3769:
	/* 0x3769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376b:
	/* 0x376b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_376f:
	/* 0x376f: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3773:
	/* 0x3773: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3777:
	/* 0x3777: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_377c:
	/* 0x377c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3781:
	/* 0x3781: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3786:
	/* 0x3786: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3789:
	/* 0x3789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378b:
	/* 0x378b: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3790:
	/* 0x3790: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3795:
	/* 0x3795: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_379a:
	/* 0x379a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_379f:
	/* 0x379f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_37a2:
	/* 0x37a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37a4:
	/* 0x37a4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37a8:
	/* 0x37a8: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
	return 14252ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14252ULL: goto x86_l_37ac;
	case 14256ULL: goto x86_l_37b0;
	case 14260ULL: goto x86_l_37b4;
	case 14265ULL: goto x86_l_37b9;
	case 14270ULL: goto x86_l_37be;
	case 14275ULL: goto x86_l_37c3;
	case 14277ULL: goto x86_l_37c5;
	case 14281ULL: goto x86_l_37c9;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14303ULL: goto x86_l_37df;
	case 14305ULL: goto x86_l_37e1;
	case 14310ULL: goto x86_l_37e6;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14324ULL: goto x86_l_37f4;
	case 14329ULL: goto x86_l_37f9;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14341ULL: goto x86_l_3805;
	case 14346ULL: goto x86_l_380a;
	case 14351ULL: goto x86_l_380f;
	case 14354ULL: goto x86_l_3812;
	case 14356ULL: goto x86_l_3814;
	case 14360ULL: goto x86_l_3818;
	case 14364ULL: goto x86_l_381c;
	case 14368ULL: goto x86_l_3820;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14382ULL: goto x86_l_382e;
	case 14387ULL: goto x86_l_3833;
	case 14389ULL: goto x86_l_3835;
	case 14393ULL: goto x86_l_3839;
	case 14397ULL: goto x86_l_383d;
	case 14402ULL: goto x86_l_3842;
	case 14407ULL: goto x86_l_3847;
	case 14412ULL: goto x86_l_384c;
	case 14415ULL: goto x86_l_384f;
	case 14417ULL: goto x86_l_3851;
	case 14422ULL: goto x86_l_3856;
	case 14427ULL: goto x86_l_385b;
	case 14432ULL: goto x86_l_3860;
	case 14437ULL: goto x86_l_3865;
	case 14440ULL: goto x86_l_3868;
	case 14442ULL: goto x86_l_386a;
	case 14446ULL: goto x86_l_386e;
	case 14450ULL: goto x86_l_3872;
	case 14454ULL: goto x86_l_3876;
	case 14458ULL: goto x86_l_387a;
	case 14463ULL: goto x86_l_387f;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14484ULL: goto x86_l_3894;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14499ULL: goto x86_l_38a3;
	case 14501ULL: goto x86_l_38a5;
	case 14506ULL: goto x86_l_38aa;
	case 14510ULL: goto x86_l_38ae;
	case 14515ULL: goto x86_l_38b3;
	case 14520ULL: goto x86_l_38b8;
	case 14525ULL: goto x86_l_38bd;
	case 14528ULL: goto x86_l_38c0;
	case 14530ULL: goto x86_l_38c2;
	case 14535ULL: goto x86_l_38c7;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14550ULL: goto x86_l_38d6;
	case 14553ULL: goto x86_l_38d9;
	case 14555ULL: goto x86_l_38db;
	case 14559ULL: goto x86_l_38df;
	case 14563ULL: goto x86_l_38e3;
	case 14567ULL: goto x86_l_38e7;
	case 14571ULL: goto x86_l_38eb;
	case 14576ULL: goto x86_l_38f0;
	case 14581ULL: goto x86_l_38f5;
	case 14586ULL: goto x86_l_38fa;
	case 14588ULL: goto x86_l_38fc;
	case 14593ULL: goto x86_l_3901;
	case 14597ULL: goto x86_l_3905;
	case 14602ULL: goto x86_l_390a;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14614ULL: goto x86_l_3916;
	case 14619ULL: goto x86_l_391b;
	case 14621ULL: goto x86_l_391d;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14636ULL: goto x86_l_392c;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14656ULL: goto x86_l_3940;
	case 14661ULL: goto x86_l_3945;
	case 14664ULL: goto x86_l_3948;
	case 14666ULL: goto x86_l_394a;
	case 14670ULL: goto x86_l_394e;
	case 14674ULL: goto x86_l_3952;
	case 14678ULL: goto x86_l_3956;
	case 14682ULL: goto x86_l_395a;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14697ULL: goto x86_l_3969;
	case 14699ULL: goto x86_l_396b;
	case 14703ULL: goto x86_l_396f;
	case 14707ULL: goto x86_l_3973;
	case 14711ULL: goto x86_l_3977;
	case 14718ULL: goto x86_l_397e;
	case 14723ULL: goto x86_l_3983;
	case 14728ULL: goto x86_l_3988;
	case 14733ULL: goto x86_l_398d;
	case 14736ULL: goto x86_l_3990;
	case 14738ULL: goto x86_l_3992;
	case 14743ULL: goto x86_l_3997;
	case 14747ULL: goto x86_l_399b;
	case 14752ULL: goto x86_l_39a0;
	case 14757ULL: goto x86_l_39a5;
	case 14762ULL: goto x86_l_39aa;
	case 14764ULL: goto x86_l_39ac;
	case 14769ULL: goto x86_l_39b1;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14786ULL: goto x86_l_39c2;
	case 14790ULL: goto x86_l_39c6;
	case 14794ULL: goto x86_l_39ca;
	case 14799ULL: goto x86_l_39cf;
	case 14801ULL: goto x86_l_39d1;
	case 14805ULL: goto x86_l_39d5;
	case 14809ULL: goto x86_l_39d9;
	case 14814ULL: goto x86_l_39de;
	case 14819ULL: goto x86_l_39e3;
	case 14824ULL: goto x86_l_39e8;
	case 14826ULL: goto x86_l_39ea;
	case 14831ULL: goto x86_l_39ef;
	case 14835ULL: goto x86_l_39f3;
	case 14843ULL: goto x86_l_39fb;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14873ULL: goto x86_l_3a19;
	case 14877ULL: goto x86_l_3a1d;
	case 14882ULL: goto x86_l_3a22;
	case 14887ULL: goto x86_l_3a27;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14897ULL: goto x86_l_3a31;
	case 14902ULL: goto x86_l_3a36;
	case 14906ULL: goto x86_l_3a3a;
	case 14911ULL: goto x86_l_3a3f;
	case 14916ULL: goto x86_l_3a44;
	case 14921ULL: goto x86_l_3a49;
	case 14924ULL: goto x86_l_3a4c;
	case 14926ULL: goto x86_l_3a4e;
	case 14931ULL: goto x86_l_3a53;
	case 14933ULL: goto x86_l_3a55;
	case 14938ULL: goto x86_l_3a5a;
	case 14942ULL: goto x86_l_3a5e;
	case 14950ULL: goto x86_l_3a66;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14968ULL: goto x86_l_3a78;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14988ULL: goto x86_l_3a8c;
	case 14990ULL: goto x86_l_3a8e;
	case 14995ULL: goto x86_l_3a93;
	case 15000ULL: goto x86_l_3a98;
	case 15005ULL: goto x86_l_3a9d;
	case 15010ULL: goto x86_l_3aa2;
	case 15012ULL: goto x86_l_3aa4;
	case 15017ULL: goto x86_l_3aa9;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15037ULL: goto x86_l_3abd;
	case 15041ULL: goto x86_l_3ac1;
	case 15046ULL: goto x86_l_3ac6;
	case 15051ULL: goto x86_l_3acb;
	case 15054ULL: goto x86_l_3ace;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15069ULL: goto x86_l_3add;
	case 15074ULL: goto x86_l_3ae2;
	case 15082ULL: goto x86_l_3aea;
	case 15084ULL: goto x86_l_3aec;
	case 15092ULL: goto x86_l_3af4;
	case 15096ULL: goto x86_l_3af8;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15118ULL: goto x86_l_3b0e;
	case 15123ULL: goto x86_l_3b13;
	case 15126ULL: goto x86_l_3b16;
	case 15128ULL: goto x86_l_3b18;
	case 15130ULL: goto x86_l_3b1a;
	case 15132ULL: goto x86_l_3b1c;
	case 15136ULL: goto x86_l_3b20;
	case 15144ULL: goto x86_l_3b28;
	case 15149ULL: goto x86_l_3b2d;
	case 15154ULL: goto x86_l_3b32;
	case 15157ULL: goto x86_l_3b35;
	case 15163ULL: goto x86_l_3b3b;
	case 15167ULL: goto x86_l_3b3f;
	case 15172ULL: goto x86_l_3b44;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15187ULL: goto x86_l_3b53;
	case 15190ULL: goto x86_l_3b56;
	case 15192ULL: goto x86_l_3b58;
	case 15200ULL: goto x86_l_3b60;
	case 15206ULL: goto x86_l_3b66;
	case 15210ULL: goto x86_l_3b6a;
	case 15214ULL: goto x86_l_3b6e;
	case 15222ULL: goto x86_l_3b76;
	case 15230ULL: goto x86_l_3b7e;
	case 15235ULL: goto x86_l_3b83;
	case 15240ULL: goto x86_l_3b88;
	case 15243ULL: goto x86_l_3b8b;
	case 15245ULL: goto x86_l_3b8d;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15270ULL: goto x86_l_3ba6;
	case 15278ULL: goto x86_l_3bae;
	case 15286ULL: goto x86_l_3bb6;
	case 15298ULL: goto x86_l_3bc2;
	case 15305ULL: goto x86_l_3bc9;
	case 15312ULL: goto x86_l_3bd0;
	case 15320ULL: goto x86_l_3bd8;
	case 15325ULL: goto x86_l_3bdd;
	case 15327ULL: goto x86_l_3bdf;
	case 15332ULL: goto x86_l_3be4;
	case 15340ULL: goto x86_l_3bec;
	case 15344ULL: goto x86_l_3bf0;
	case 15351ULL: goto x86_l_3bf7;
	case 15359ULL: goto x86_l_3bff;
	case 15364ULL: goto x86_l_3c04;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15378ULL: goto x86_l_3c12;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15388ULL: goto x86_l_3c1c;
	case 15390ULL: goto x86_l_3c1e;
	case 15397ULL: goto x86_l_3c25;
	case 15399ULL: goto x86_l_3c27;
	case 15400ULL: goto x86_l_3c28;
	case 15405ULL: goto x86_l_3c2d;
	case 15408ULL: goto x86_l_3c30;
	case 15414ULL: goto x86_l_3c36;
	case 15418ULL: goto x86_l_3c3a;
	case 15423ULL: goto x86_l_3c3f;
	case 15428ULL: goto x86_l_3c44;
	case 15434ULL: goto x86_l_3c4a;
	case 15439ULL: goto x86_l_3c4f;
	case 15443ULL: goto x86_l_3c53;
	case 15447ULL: goto x86_l_3c57;
	case 15452ULL: goto x86_l_3c5c;
	case 15457ULL: goto x86_l_3c61;
	case 15459ULL: goto x86_l_3c63;
	case 15464ULL: goto x86_l_3c68;
	case 15468ULL: goto x86_l_3c6c;
	case 15471ULL: goto x86_l_3c6f;
	case 15476ULL: goto x86_l_3c74;
	case 15478ULL: goto x86_l_3c76;
	case 15483ULL: goto x86_l_3c7b;
	case 15487ULL: goto x86_l_3c7f;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15499ULL: goto x86_l_3c8b;
	case 15503ULL: goto x86_l_3c8f;
	case 15507ULL: goto x86_l_3c93;
	case 15512ULL: goto x86_l_3c98;
	case 15517ULL: goto x86_l_3c9d;
	case 15522ULL: goto x86_l_3ca2;
	case 15525ULL: goto x86_l_3ca5;
	case 15527ULL: goto x86_l_3ca7;
	case 15532ULL: goto x86_l_3cac;
	case 15537ULL: goto x86_l_3cb1;
	case 15541ULL: goto x86_l_3cb5;
	case 15546ULL: goto x86_l_3cba;
	case 15551ULL: goto x86_l_3cbf;
	case 15556ULL: goto x86_l_3cc4;
	case 15558ULL: goto x86_l_3cc6;
	case 15563ULL: goto x86_l_3ccb;
	case 15566ULL: goto x86_l_3cce;
	case 15572ULL: goto x86_l_3cd4;
	case 15577ULL: goto x86_l_3cd9;
	case 15580ULL: goto x86_l_3cdc;
	case 15586ULL: goto x86_l_3ce2;
	case 15590ULL: goto x86_l_3ce6;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15605ULL: goto x86_l_3cf5;
	case 15607ULL: goto x86_l_3cf7;
	case 15611ULL: goto x86_l_3cfb;
	case 15613ULL: goto x86_l_3cfd;
	case 15619ULL: goto x86_l_3d03;
	case 15622ULL: goto x86_l_3d06;
	case 15624ULL: goto x86_l_3d08;
	case 15630ULL: goto x86_l_3d0e;
	case 15635ULL: goto x86_l_3d13;
	case 15641ULL: goto x86_l_3d19;
	case 15644ULL: goto x86_l_3d1c;
	case 15649ULL: goto x86_l_3d21;
	case 15651ULL: goto x86_l_3d23;
	case 15654ULL: goto x86_l_3d26;
	case 15660ULL: goto x86_l_3d2c;
	case 15664ULL: goto x86_l_3d30;
	case 15670ULL: goto x86_l_3d36;
	case 15674ULL: goto x86_l_3d3a;
	case 15677ULL: goto x86_l_3d3d;
	case 15682ULL: goto x86_l_3d42;
	case 15687ULL: goto x86_l_3d47;
	case 15690ULL: goto x86_l_3d4a;
	case 15696ULL: goto x86_l_3d50;
	case 15700ULL: goto x86_l_3d54;
	case 15705ULL: goto x86_l_3d59;
	case 15711ULL: goto x86_l_3d5f;
	case 15716ULL: goto x86_l_3d64;
	case 15720ULL: goto x86_l_3d68;
	case 15724ULL: goto x86_l_3d6c;
	case 15729ULL: goto x86_l_3d71;
	case 15734ULL: goto x86_l_3d76;
	case 15736ULL: goto x86_l_3d78;
	case 15741ULL: goto x86_l_3d7d;
	case 15745ULL: goto x86_l_3d81;
	case 15748ULL: goto x86_l_3d84;
	case 15753ULL: goto x86_l_3d89;
	case 15755ULL: goto x86_l_3d8b;
	case 15760ULL: goto x86_l_3d90;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15776ULL: goto x86_l_3da0;
	case 15780ULL: goto x86_l_3da4;
	case 15784ULL: goto x86_l_3da8;
	case 15786ULL: goto x86_l_3daa;
	case 15793ULL: goto x86_l_3db1;
	case 15796ULL: goto x86_l_3db4;
	case 15800ULL: goto x86_l_3db8;
	case 15805ULL: goto x86_l_3dbd;
	case 15810ULL: goto x86_l_3dc2;
	case 15812ULL: goto x86_l_3dc4;
	case 15815ULL: goto x86_l_3dc7;
	case 15821ULL: goto x86_l_3dcd;
	case 15827ULL: goto x86_l_3dd3;
	case 15832ULL: goto x86_l_3dd8;
	case 15837ULL: goto x86_l_3ddd;
	case 15842ULL: goto x86_l_3de2;
	case 15848ULL: goto x86_l_3de8;
	case 15851ULL: goto x86_l_3deb;
	case 15856ULL: goto x86_l_3df0;
	case 15858ULL: goto x86_l_3df2;
	case 15861ULL: goto x86_l_3df5;
	case 15867ULL: goto x86_l_3dfb;
	case 15871ULL: goto x86_l_3dff;
	case 15877ULL: goto x86_l_3e05;
	case 15881ULL: goto x86_l_3e09;
	case 15884ULL: goto x86_l_3e0c;
	case 15889ULL: goto x86_l_3e11;
	case 15894ULL: goto x86_l_3e16;
	case 15899ULL: goto x86_l_3e1b;
	case 15904ULL: goto x86_l_3e20;
	case 15907ULL: goto x86_l_3e23;
	case 15909ULL: goto x86_l_3e25;
	case 15914ULL: goto x86_l_3e2a;
	case 15919ULL: goto x86_l_3e2f;
	case 15923ULL: goto x86_l_3e33;
	case 15928ULL: goto x86_l_3e38;
	case 15933ULL: goto x86_l_3e3d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_37ac:
	/* 0x37ac: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37b0:
	/* 0x37b0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37b4:
	/* 0x37b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37b9:
	/* 0x37b9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37be:
	/* 0x37be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37c3:
	/* 0x37c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37c5:
	/* 0x37c5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37c9:
	/* 0x37c9: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_37cd:
	/* 0x37cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37d2:
	/* 0x37d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37d7:
	/* 0x37d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37dc:
	/* 0x37dc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_37df:
	/* 0x37df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e1:
	/* 0x37e1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37e6:
	/* 0x37e6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37ea:
	/* 0x37ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ef:
	/* 0x37ef: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37f4:
	/* 0x37f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37f9:
	/* 0x37f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37fb:
	/* 0x37fb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3800:
	/* 0x3800: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3805:
	/* 0x3805: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_380a:
	/* 0x380a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_380f:
	/* 0x380f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3812:
	/* 0x3812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3814:
	/* 0x3814: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3818:
	/* 0x3818: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_381c:
	/* 0x381c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3820:
	/* 0x3820: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3824:
	/* 0x3824: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3829:
	/* 0x3829: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_382e:
	/* 0x382e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3833:
	/* 0x3833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3835:
	/* 0x3835: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3839:
	/* 0x3839: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_383d:
	/* 0x383d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3842:
	/* 0x3842: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3847:
	/* 0x3847: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_384c:
	/* 0x384c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_384f:
	/* 0x384f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3851:
	/* 0x3851: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3856:
	/* 0x3856: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_385b:
	/* 0x385b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3860:
	/* 0x3860: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3865:
	/* 0x3865: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3868:
	/* 0x3868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_386a:
	/* 0x386a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_386e:
	/* 0x386e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3872:
	/* 0x3872: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3876:
	/* 0x3876: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_387a:
	/* 0x387a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_387f:
	/* 0x387f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3884:
	/* 0x3884: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3889:
	/* 0x3889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_388b:
	/* 0x388b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3890:
	/* 0x3890: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3894:
	/* 0x3894: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3899:
	/* 0x3899: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_389e:
	/* 0x389e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38a3:
	/* 0x38a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a5:
	/* 0x38a5: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38aa:
	/* 0x38aa: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ae:
	/* 0x38ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38b3:
	/* 0x38b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38b8:
	/* 0x38b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38bd:
	/* 0x38bd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_38c0:
	/* 0x38c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38c2:
	/* 0x38c2: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38c7:
	/* 0x38c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38cc:
	/* 0x38cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38d1:
	/* 0x38d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38d6:
	/* 0x38d6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_38d9:
	/* 0x38d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38db:
	/* 0x38db: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38df:
	/* 0x38df: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_38e3:
	/* 0x38e3: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38e7:
	/* 0x38e7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_38eb:
	/* 0x38eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38f0:
	/* 0x38f0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38f5:
	/* 0x38f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38fa:
	/* 0x38fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38fc:
	/* 0x38fc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3901:
	/* 0x3901: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3905:
	/* 0x3905: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_390a:
	/* 0x390a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_390f:
	/* 0x390f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3914:
	/* 0x3914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3916:
	/* 0x3916: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_391b:
	/* 0x391b: jne    3973 <trace_security_file_mprotect+0x3973> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3973;
	}
x86_l_391d:
	/* 0x391d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3922:
	/* 0x3922: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3927:
	/* 0x3927: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392c:
	/* 0x392c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_392f:
	/* 0x392f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3931:
	/* 0x3931: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3936:
	/* 0x3936: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_393b:
	/* 0x393b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3940:
	/* 0x3940: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3945:
	/* 0x3945: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3948:
	/* 0x3948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_394a:
	/* 0x394a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_394e:
	/* 0x394e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3952:
	/* 0x3952: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3956:
	/* 0x3956: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_395a:
	/* 0x395a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_395f:
	/* 0x395f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3964:
	/* 0x3964: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3969:
	/* 0x3969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396b:
	/* 0x396b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_396f:
	/* 0x396f: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3973:
	/* 0x3973: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3977:
	/* 0x3977: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_397e:
	/* 0x397e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3983:
	/* 0x3983: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3988:
	/* 0x3988: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_398d:
	/* 0x398d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3990:
	/* 0x3990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3992:
	/* 0x3992: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3997:
	/* 0x3997: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_399b:
	/* 0x399b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39a0:
	/* 0x39a0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39a5:
	/* 0x39a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39aa:
	/* 0x39aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ac:
	/* 0x39ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39b1:
	/* 0x39b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39b6:
	/* 0x39b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39bb:
	/* 0x39bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39c0:
	/* 0x39c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c2:
	/* 0x39c2: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c6:
	/* 0x39c6: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_39ca:
	/* 0x39ca: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_39cf:
	/* 0x39cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d1:
	/* 0x39d1: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39d5:
	/* 0x39d5: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39d9:
	/* 0x39d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39de:
	/* 0x39de: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39e3:
	/* 0x39e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39e8:
	/* 0x39e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ea:
	/* 0x39ea: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39ef:
	/* 0x39ef: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39f3:
	/* 0x39f3: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_39fb:
	/* 0x39fb: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_39ff:
	/* 0x39ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a04:
	/* 0x3a04: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a09:
	/* 0x3a09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a0e:
	/* 0x3a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a10:
	/* 0x3a10: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a15:
	/* 0x3a15: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3a19:
	/* 0x3a19: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3a1d:
	/* 0x3a1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a22:
	/* 0x3a22: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a27:
	/* 0x3a27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a2c:
	/* 0x3a2c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3a2f:
	/* 0x3a2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a31:
	/* 0x3a31: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a36:
	/* 0x3a36: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a3a:
	/* 0x3a3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a3f:
	/* 0x3a3f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a44:
	/* 0x3a44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a49:
	/* 0x3a49: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3a4c:
	/* 0x3a4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a4e:
	/* 0x3a4e: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_3a53:
	/* 0x3a53: je     3a5a <trace_security_file_mprotect+0x3a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a5a;
	}
x86_l_3a55:
	/* 0x3a55: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_3a5a:
	/* 0x3a5a: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3a5e:
	/* 0x3a5e: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_3a66:
	/* 0x3a66: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_3a6e:
	/* 0x3a6e: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_3a73:
	/* 0x3a73: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3a78:
	/* 0x3a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7a:
	/* 0x3a7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a7f:
	/* 0x3a7f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a84:
	/* 0x3a84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a89:
	/* 0x3a89: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3a8c:
	/* 0x3a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a8e:
	/* 0x3a8e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a93:
	/* 0x3a93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a98:
	/* 0x3a98: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a9d:
	/* 0x3a9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa2:
	/* 0x3aa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa4:
	/* 0x3aa4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3aa9:
	/* 0x3aa9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3aae:
	/* 0x3aae: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ab3:
	/* 0x3ab3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3ab6:
	/* 0x3ab6: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_3abb:
	/* 0x3abb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3abd:
	/* 0x3abd: lea    rdi,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3ac1:
	/* 0x3ac1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3ac6:
	/* 0x3ac6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3acb:
	/* 0x3acb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3ace:
	/* 0x3ace: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ad0:
	/* 0x3ad0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    rdi,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3add:
	/* 0x3add: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_3ae2:
	/* 0x3ae2: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3aea:
	/* 0x3aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aec:
	/* 0x3aec: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3af4:
	/* 0x3af4: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_3af8:
	/* 0x3af8: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3b00:
	/* 0x3b00: je     3b20 <trace_security_file_mprotect+0x3b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b20;
	}
x86_l_3b02:
	/* 0x3b02: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_3b07:
	/* 0x3b07: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_3b0e:
	/* 0x3b0e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_3b13:
	/* 0x3b13: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3b16:
	/* 0x3b16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b18:
	/* 0x3b18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b1a:
	/* 0x3b1a: js     3b20 <trace_security_file_mprotect+0x3b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b20;
	}
x86_l_3b1c:
	/* 0x3b1c: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b20:
	/* 0x3b20: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b28:
	/* 0x3b28: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_3b2d:
	/* 0x3b2d: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_3b32:
	/* 0x3b32: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_3b35:
	/* 0x3b35: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_3b3b:
	/* 0x3b3b: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3b3f:
	/* 0x3b3f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3b44:
	/* 0x3b44: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_3b4b:
	/* 0x3b4b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b50:
	/* 0x3b50: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3b53:
	/* 0x3b53: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3b56:
	/* 0x3b56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b58:
	/* 0x3b58: cmp    BYTE PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3b60:
	/* 0x3b60: je     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c1c;
	}
x86_l_3b66:
	/* 0x3b66: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3b6a:
	/* 0x3b6a: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    BYTE PTR [rsp+0x148],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273090ULL);
x86_l_3b76:
	/* 0x3b76: lea    rdi,[rsp+0x149] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 329ULL);
x86_l_3b7e:
	/* 0x3b7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b83:
	/* 0x3b83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b88:
	/* 0x3b88: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3b8b:
	/* 0x3b8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b8d:
	/* 0x3b8d: lea    rdi,[rsp+0x151] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 337ULL);
x86_l_3b95:
	/* 0x3b95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b9a:
	/* 0x3b9a: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b9f:
	/* 0x3b9f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba4:
	/* 0x3ba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba6:
	/* 0x3ba6: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3bae:
	/* 0x3bae: mov    QWORD PTR [rsp+0x168],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3bb6:
	/* 0x3bb6: mov    QWORD PTR [rsp+0x170],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1580547964928ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    eax,DWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3bc9:
	/* 0x3bc9: mov    DWORD PTR [rsp+0x178],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3bd0:
	/* 0x3bd0: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bd8:
	/* 0x3bd8: cmp    eax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31935ULL);
x86_l_3bdd:
	/* 0x3bdd: ja     3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3c1c;
	}
x86_l_3bdf:
	/* 0x3bdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3be4:
	/* 0x3be4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bec:
	/* 0x3bec: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bf0:
	/* 0x3bf0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bf7:
	/* 0x3bf7: lea    rdx,[rsp+0x148] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3bff:
	/* 0x3bff: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_3c04:
	/* 0x3c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c06:
	/* 0x3c06: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_3c12:
	/* 0x3c12: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3c15:
	/* 0x3c15: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3c1a:
	/* 0x3c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1c:
	/* 0x3c1c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c1e:
	/* 0x3c1e: add    rsp,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_3c25:
	/* 0x3c25: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3c27:
	/* 0x3c27: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3c28:
	/* 0x3c28: jmp    6104 <trace_security_file_mprotect+0x6104> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3c2d:
	/* 0x3c2d: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3c30:
	/* 0x3c30: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_3c36:
	/* 0x3c36: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c3a:
	/* 0x3c3a: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3c3f:
	/* 0x3c3f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c44:
	/* 0x3c44: je     1826 <trace_security_file_mprotect+0x1826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6182ULL;
	}
x86_l_3c4a:
	/* 0x3c4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c4f:
	/* 0x3c4f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c53:
	/* 0x3c53: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c57:
	/* 0x3c57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5c:
	/* 0x3c5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c61:
	/* 0x3c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c63:
	/* 0x3c63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c68:
	/* 0x3c68: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6c:
	/* 0x3c6c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c6f:
	/* 0x3c6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c74:
	/* 0x3c74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c76:
	/* 0x3c76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c7b:
	/* 0x3c7b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c7f:
	/* 0x3c7f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c84:
	/* 0x3c84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c89:
	/* 0x3c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8b:
	/* 0x3c8b: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8f:
	/* 0x3c8f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c93:
	/* 0x3c93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c98:
	/* 0x3c98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c9d:
	/* 0x3c9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ca2:
	/* 0x3ca2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3ca5:
	/* 0x3ca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca7:
	/* 0x3ca7: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cac:
	/* 0x3cac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cb1:
	/* 0x3cb1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3cb5:
	/* 0x3cb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cba:
	/* 0x3cba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cbf:
	/* 0x3cbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc4:
	/* 0x3cc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc6:
	/* 0x3cc6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ccb:
	/* 0x3ccb: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3cce:
	/* 0x3cce: je     3ec5 <trace_security_file_mprotect+0x3ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16069ULL;
	}
x86_l_3cd4:
	/* 0x3cd4: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd9:
	/* 0x3cd9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3cdc:
	/* 0x3cdc: je     3ec5 <trace_security_file_mprotect+0x3ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16069ULL;
	}
x86_l_3ce2:
	/* 0x3ce2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3ce6:
	/* 0x3ce6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ceb:
	/* 0x3ceb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf0:
	/* 0x3cf0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3cf5:
	/* 0x3cf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf7:
	/* 0x3cf7: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3cfb:
	/* 0x3cfb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3cfd:
	/* 0x3cfd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d03:
	/* 0x3d03: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3d06:
	/* 0x3d06: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d08:
	/* 0x3d08: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_3d0e:
	/* 0x3d0e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d13:
	/* 0x3d13: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3d19:
	/* 0x3d19: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d1c:
	/* 0x3d1c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3d21:
	/* 0x3d21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d23:
	/* 0x3d23: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d26:
	/* 0x3d26: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_3d2c:
	/* 0x3d2c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d30:
	/* 0x3d30: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3d36:
	/* 0x3d36: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3d3a:
	/* 0x3d3a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d3d:
	/* 0x3d3d: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d42:
	/* 0x3d42: jmp    3f26 <trace_security_file_mprotect+0x3f26> */
	return 16166ULL;
x86_l_3d47:
	/* 0x3d47: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3d4a:
	/* 0x3d4a: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_3d50:
	/* 0x3d50: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d54:
	/* 0x3d54: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3d59:
	/* 0x3d59: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_3d5f:
	/* 0x3d5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d64:
	/* 0x3d64: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d68:
	/* 0x3d68: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d6c:
	/* 0x3d6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d71:
	/* 0x3d71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d76:
	/* 0x3d76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d78:
	/* 0x3d78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d7d:
	/* 0x3d7d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d81:
	/* 0x3d81: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d84:
	/* 0x3d84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d89:
	/* 0x3d89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d8b:
	/* 0x3d8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d90:
	/* 0x3d90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d94:
	/* 0x3d94: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d99:
	/* 0x3d99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d9e:
	/* 0x3d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da0:
	/* 0x3da0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da4:
	/* 0x3da4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3da8:
	/* 0x3da8: jmp    3e11 <trace_security_file_mprotect+0x3e11> */
	goto x86_l_3e11;
x86_l_3daa:
	/* 0x3daa: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_3db1:
	/* 0x3db1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3db4:
	/* 0x3db4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3db8:
	/* 0x3db8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dbd:
	/* 0x3dbd: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_3dc2:
	/* 0x3dc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc4:
	/* 0x3dc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dc7:
	/* 0x3dc7: jne    3c1c <trace_security_file_mprotect+0x3c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c1c;
	}
x86_l_3dcd:
	/* 0x3dcd: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3dd3:
	/* 0x3dd3: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_3dd8:
	/* 0x3dd8: jmp    b5e <trace_security_file_mprotect+0xb5e> */
	return 2910ULL;
x86_l_3ddd:
	/* 0x3ddd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3de2:
	/* 0x3de2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3de8:
	/* 0x3de8: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3deb:
	/* 0x3deb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3df0:
	/* 0x3df0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df2:
	/* 0x3df2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3df5:
	/* 0x3df5: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_3dfb:
	/* 0x3dfb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3dff:
	/* 0x3dff: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3e05:
	/* 0x3e05: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3e09:
	/* 0x3e09: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e0c:
	/* 0x3e0c: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e11:
	/* 0x3e11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e16:
	/* 0x3e16: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e1b:
	/* 0x3e1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e20:
	/* 0x3e20: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3e23:
	/* 0x3e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e25:
	/* 0x3e25: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e2a:
	/* 0x3e2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e2f:
	/* 0x3e2f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3e33:
	/* 0x3e33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e38:
	/* 0x3e38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e3d:
	/* 0x3e3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 15938ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15938ULL: goto x86_l_3e42;
	case 15940ULL: goto x86_l_3e44;
	case 15945ULL: goto x86_l_3e49;
	case 15948ULL: goto x86_l_3e4c;
	case 15954ULL: goto x86_l_3e52;
	case 15959ULL: goto x86_l_3e57;
	case 15962ULL: goto x86_l_3e5a;
	case 15968ULL: goto x86_l_3e60;
	case 15972ULL: goto x86_l_3e64;
	case 15977ULL: goto x86_l_3e69;
	case 15982ULL: goto x86_l_3e6e;
	case 15987ULL: goto x86_l_3e73;
	case 15989ULL: goto x86_l_3e75;
	case 15993ULL: goto x86_l_3e79;
	case 15995ULL: goto x86_l_3e7b;
	case 16001ULL: goto x86_l_3e81;
	case 16004ULL: goto x86_l_3e84;
	case 16006ULL: goto x86_l_3e86;
	case 16012ULL: goto x86_l_3e8c;
	case 16017ULL: goto x86_l_3e91;
	case 16023ULL: goto x86_l_3e97;
	case 16026ULL: goto x86_l_3e9a;
	case 16031ULL: goto x86_l_3e9f;
	case 16033ULL: goto x86_l_3ea1;
	case 16036ULL: goto x86_l_3ea4;
	case 16042ULL: goto x86_l_3eaa;
	case 16046ULL: goto x86_l_3eae;
	case 16052ULL: goto x86_l_3eb4;
	case 16056ULL: goto x86_l_3eb8;
	case 16059ULL: goto x86_l_3ebb;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16072ULL: goto x86_l_3ec8;
	case 16078ULL: goto x86_l_3ece;
	case 16082ULL: goto x86_l_3ed2;
	case 16087ULL: goto x86_l_3ed7;
	case 16093ULL: goto x86_l_3edd;
	case 16098ULL: goto x86_l_3ee2;
	case 16102ULL: goto x86_l_3ee6;
	case 16106ULL: goto x86_l_3eea;
	case 16111ULL: goto x86_l_3eef;
	case 16116ULL: goto x86_l_3ef4;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16127ULL: goto x86_l_3eff;
	case 16130ULL: goto x86_l_3f02;
	case 16135ULL: goto x86_l_3f07;
	case 16137ULL: goto x86_l_3f09;
	case 16142ULL: goto x86_l_3f0e;
	case 16146ULL: goto x86_l_3f12;
	case 16151ULL: goto x86_l_3f17;
	case 16156ULL: goto x86_l_3f1c;
	case 16158ULL: goto x86_l_3f1e;
	case 16162ULL: goto x86_l_3f22;
	case 16166ULL: goto x86_l_3f26;
	case 16171ULL: goto x86_l_3f2b;
	case 16176ULL: goto x86_l_3f30;
	case 16181ULL: goto x86_l_3f35;
	case 16184ULL: goto x86_l_3f38;
	case 16186ULL: goto x86_l_3f3a;
	case 16191ULL: goto x86_l_3f3f;
	case 16196ULL: goto x86_l_3f44;
	case 16200ULL: goto x86_l_3f48;
	case 16205ULL: goto x86_l_3f4d;
	case 16210ULL: goto x86_l_3f52;
	case 16215ULL: goto x86_l_3f57;
	case 16217ULL: goto x86_l_3f59;
	case 16222ULL: goto x86_l_3f5e;
	case 16225ULL: goto x86_l_3f61;
	case 16231ULL: goto x86_l_3f67;
	case 16236ULL: goto x86_l_3f6c;
	case 16239ULL: goto x86_l_3f6f;
	case 16245ULL: goto x86_l_3f75;
	case 16249ULL: goto x86_l_3f79;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16264ULL: goto x86_l_3f88;
	case 16266ULL: goto x86_l_3f8a;
	case 16270ULL: goto x86_l_3f8e;
	case 16272ULL: goto x86_l_3f90;
	case 16278ULL: goto x86_l_3f96;
	case 16281ULL: goto x86_l_3f99;
	case 16283ULL: goto x86_l_3f9b;
	case 16289ULL: goto x86_l_3fa1;
	case 16294ULL: goto x86_l_3fa6;
	case 16300ULL: goto x86_l_3fac;
	case 16303ULL: goto x86_l_3faf;
	case 16308ULL: goto x86_l_3fb4;
	case 16310ULL: goto x86_l_3fb6;
	case 16313ULL: goto x86_l_3fb9;
	case 16319ULL: goto x86_l_3fbf;
	case 16323ULL: goto x86_l_3fc3;
	case 16329ULL: goto x86_l_3fc9;
	case 16333ULL: goto x86_l_3fcd;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16346ULL: goto x86_l_3fda;
	case 16349ULL: goto x86_l_3fdd;
	case 16355ULL: goto x86_l_3fe3;
	case 16359ULL: goto x86_l_3fe7;
	case 16364ULL: goto x86_l_3fec;
	case 16370ULL: goto x86_l_3ff2;
	case 16375ULL: goto x86_l_3ff7;
	case 16379ULL: goto x86_l_3ffb;
	case 16383ULL: goto x86_l_3fff;
	case 16388ULL: goto x86_l_4004;
	case 16393ULL: goto x86_l_4009;
	case 16395ULL: goto x86_l_400b;
	case 16400ULL: goto x86_l_4010;
	case 16404ULL: goto x86_l_4014;
	case 16407ULL: goto x86_l_4017;
	case 16412ULL: goto x86_l_401c;
	case 16414ULL: goto x86_l_401e;
	case 16419ULL: goto x86_l_4023;
	case 16423ULL: goto x86_l_4027;
	case 16428ULL: goto x86_l_402c;
	case 16433ULL: goto x86_l_4031;
	case 16435ULL: goto x86_l_4033;
	case 16439ULL: goto x86_l_4037;
	case 16443ULL: goto x86_l_403b;
	case 16448ULL: goto x86_l_4040;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16461ULL: goto x86_l_404d;
	case 16463ULL: goto x86_l_404f;
	case 16468ULL: goto x86_l_4054;
	case 16473ULL: goto x86_l_4059;
	case 16477ULL: goto x86_l_405d;
	case 16482ULL: goto x86_l_4062;
	case 16487ULL: goto x86_l_4067;
	case 16492ULL: goto x86_l_406c;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16502ULL: goto x86_l_4076;
	case 16508ULL: goto x86_l_407c;
	case 16513ULL: goto x86_l_4081;
	case 16516ULL: goto x86_l_4084;
	case 16522ULL: goto x86_l_408a;
	case 16526ULL: goto x86_l_408e;
	case 16531ULL: goto x86_l_4093;
	case 16536ULL: goto x86_l_4098;
	case 16541ULL: goto x86_l_409d;
	case 16543ULL: goto x86_l_409f;
	case 16547ULL: goto x86_l_40a3;
	case 16549ULL: goto x86_l_40a5;
	case 16555ULL: goto x86_l_40ab;
	case 16558ULL: goto x86_l_40ae;
	case 16560ULL: goto x86_l_40b0;
	case 16566ULL: goto x86_l_40b6;
	case 16571ULL: goto x86_l_40bb;
	case 16577ULL: goto x86_l_40c1;
	case 16580ULL: goto x86_l_40c4;
	case 16585ULL: goto x86_l_40c9;
	case 16587ULL: goto x86_l_40cb;
	case 16590ULL: goto x86_l_40ce;
	case 16596ULL: goto x86_l_40d4;
	case 16600ULL: goto x86_l_40d8;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16613ULL: goto x86_l_40e5;
	case 16618ULL: goto x86_l_40ea;
	case 16623ULL: goto x86_l_40ef;
	case 16626ULL: goto x86_l_40f2;
	case 16632ULL: goto x86_l_40f8;
	case 16636ULL: goto x86_l_40fc;
	case 16641ULL: goto x86_l_4101;
	case 16647ULL: goto x86_l_4107;
	case 16652ULL: goto x86_l_410c;
	case 16656ULL: goto x86_l_4110;
	case 16660ULL: goto x86_l_4114;
	case 16665ULL: goto x86_l_4119;
	case 16670ULL: goto x86_l_411e;
	case 16672ULL: goto x86_l_4120;
	case 16677ULL: goto x86_l_4125;
	case 16681ULL: goto x86_l_4129;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16691ULL: goto x86_l_4133;
	case 16696ULL: goto x86_l_4138;
	case 16700ULL: goto x86_l_413c;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16712ULL: goto x86_l_4148;
	case 16716ULL: goto x86_l_414c;
	case 16720ULL: goto x86_l_4150;
	case 16725ULL: goto x86_l_4155;
	case 16730ULL: goto x86_l_415a;
	case 16735ULL: goto x86_l_415f;
	case 16738ULL: goto x86_l_4162;
	case 16740ULL: goto x86_l_4164;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16754ULL: goto x86_l_4172;
	case 16759ULL: goto x86_l_4177;
	case 16764ULL: goto x86_l_417c;
	case 16769ULL: goto x86_l_4181;
	case 16771ULL: goto x86_l_4183;
	case 16776ULL: goto x86_l_4188;
	case 16779ULL: goto x86_l_418b;
	case 16785ULL: goto x86_l_4191;
	case 16790ULL: goto x86_l_4196;
	case 16793ULL: goto x86_l_4199;
	case 16799ULL: goto x86_l_419f;
	case 16803ULL: goto x86_l_41a3;
	case 16808ULL: goto x86_l_41a8;
	case 16813ULL: goto x86_l_41ad;
	case 16818ULL: goto x86_l_41b2;
	case 16820ULL: goto x86_l_41b4;
	case 16824ULL: goto x86_l_41b8;
	case 16826ULL: goto x86_l_41ba;
	case 16832ULL: goto x86_l_41c0;
	case 16835ULL: goto x86_l_41c3;
	case 16837ULL: goto x86_l_41c5;
	case 16843ULL: goto x86_l_41cb;
	case 16848ULL: goto x86_l_41d0;
	case 16854ULL: goto x86_l_41d6;
	case 16857ULL: goto x86_l_41d9;
	case 16862ULL: goto x86_l_41de;
	case 16864ULL: goto x86_l_41e0;
	case 16867ULL: goto x86_l_41e3;
	case 16873ULL: goto x86_l_41e9;
	case 16877ULL: goto x86_l_41ed;
	case 16883ULL: goto x86_l_41f3;
	case 16887ULL: goto x86_l_41f7;
	case 16890ULL: goto x86_l_41fa;
	case 16895ULL: goto x86_l_41ff;
	case 16900ULL: goto x86_l_4204;
	case 16903ULL: goto x86_l_4207;
	case 16909ULL: goto x86_l_420d;
	case 16913ULL: goto x86_l_4211;
	case 16918ULL: goto x86_l_4216;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16933ULL: goto x86_l_4225;
	case 16937ULL: goto x86_l_4229;
	case 16942ULL: goto x86_l_422e;
	case 16947ULL: goto x86_l_4233;
	case 16949ULL: goto x86_l_4235;
	case 16954ULL: goto x86_l_423a;
	case 16958ULL: goto x86_l_423e;
	case 16961ULL: goto x86_l_4241;
	case 16966ULL: goto x86_l_4246;
	case 16968ULL: goto x86_l_4248;
	case 16973ULL: goto x86_l_424d;
	case 16977ULL: goto x86_l_4251;
	case 16982ULL: goto x86_l_4256;
	case 16987ULL: goto x86_l_425b;
	case 16989ULL: goto x86_l_425d;
	case 16993ULL: goto x86_l_4261;
	case 16997ULL: goto x86_l_4265;
	case 17002ULL: goto x86_l_426a;
	case 17007ULL: goto x86_l_426f;
	case 17012ULL: goto x86_l_4274;
	case 17015ULL: goto x86_l_4277;
	case 17017ULL: goto x86_l_4279;
	case 17022ULL: goto x86_l_427e;
	case 17027ULL: goto x86_l_4283;
	case 17031ULL: goto x86_l_4287;
	case 17036ULL: goto x86_l_428c;
	case 17041ULL: goto x86_l_4291;
	case 17046ULL: goto x86_l_4296;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17056ULL: goto x86_l_42a0;
	case 17062ULL: goto x86_l_42a6;
	case 17067ULL: goto x86_l_42ab;
	case 17070ULL: goto x86_l_42ae;
	case 17076ULL: goto x86_l_42b4;
	case 17080ULL: goto x86_l_42b8;
	case 17085ULL: goto x86_l_42bd;
	case 17090ULL: goto x86_l_42c2;
	case 17095ULL: goto x86_l_42c7;
	case 17097ULL: goto x86_l_42c9;
	case 17101ULL: goto x86_l_42cd;
	case 17103ULL: goto x86_l_42cf;
	case 17109ULL: goto x86_l_42d5;
	case 17112ULL: goto x86_l_42d8;
	case 17114ULL: goto x86_l_42da;
	case 17120ULL: goto x86_l_42e0;
	case 17125ULL: goto x86_l_42e5;
	case 17131ULL: goto x86_l_42eb;
	case 17134ULL: goto x86_l_42ee;
	case 17139ULL: goto x86_l_42f3;
	case 17141ULL: goto x86_l_42f5;
	case 17144ULL: goto x86_l_42f8;
	case 17150ULL: goto x86_l_42fe;
	case 17154ULL: goto x86_l_4302;
	case 17160ULL: goto x86_l_4308;
	case 17164ULL: goto x86_l_430c;
	case 17167ULL: goto x86_l_430f;
	case 17172ULL: goto x86_l_4314;
	case 17177ULL: goto x86_l_4319;
	case 17180ULL: goto x86_l_431c;
	case 17186ULL: goto x86_l_4322;
	case 17190ULL: goto x86_l_4326;
	case 17195ULL: goto x86_l_432b;
	case 17201ULL: goto x86_l_4331;
	case 17206ULL: goto x86_l_4336;
	case 17210ULL: goto x86_l_433a;
	case 17214ULL: goto x86_l_433e;
	case 17219ULL: goto x86_l_4343;
	case 17224ULL: goto x86_l_4348;
	case 17226ULL: goto x86_l_434a;
	case 17231ULL: goto x86_l_434f;
	case 17235ULL: goto x86_l_4353;
	case 17238ULL: goto x86_l_4356;
	case 17243ULL: goto x86_l_435b;
	case 17245ULL: goto x86_l_435d;
	case 17250ULL: goto x86_l_4362;
	case 17254ULL: goto x86_l_4366;
	case 17259ULL: goto x86_l_436b;
	case 17264ULL: goto x86_l_4370;
	case 17266ULL: goto x86_l_4372;
	case 17270ULL: goto x86_l_4376;
	case 17274ULL: goto x86_l_437a;
	case 17279ULL: goto x86_l_437f;
	case 17284ULL: goto x86_l_4384;
	case 17289ULL: goto x86_l_4389;
	case 17292ULL: goto x86_l_438c;
	case 17294ULL: goto x86_l_438e;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17308ULL: goto x86_l_439c;
	case 17313ULL: goto x86_l_43a1;
	case 17318ULL: goto x86_l_43a6;
	case 17323ULL: goto x86_l_43ab;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17333ULL: goto x86_l_43b5;
	case 17339ULL: goto x86_l_43bb;
	case 17344ULL: goto x86_l_43c0;
	case 17347ULL: goto x86_l_43c3;
	case 17353ULL: goto x86_l_43c9;
	case 17357ULL: goto x86_l_43cd;
	case 17362ULL: goto x86_l_43d2;
	case 17367ULL: goto x86_l_43d7;
	case 17372ULL: goto x86_l_43dc;
	case 17374ULL: goto x86_l_43de;
	case 17378ULL: goto x86_l_43e2;
	case 17380ULL: goto x86_l_43e4;
	case 17386ULL: goto x86_l_43ea;
	case 17389ULL: goto x86_l_43ed;
	case 17391ULL: goto x86_l_43ef;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17408ULL: goto x86_l_4400;
	case 17411ULL: goto x86_l_4403;
	case 17416ULL: goto x86_l_4408;
	case 17418ULL: goto x86_l_440a;
	case 17421ULL: goto x86_l_440d;
	case 17427ULL: goto x86_l_4413;
	case 17431ULL: goto x86_l_4417;
	case 17437ULL: goto x86_l_441d;
	case 17441ULL: goto x86_l_4421;
	case 17444ULL: goto x86_l_4424;
	case 17449ULL: goto x86_l_4429;
	case 17454ULL: goto x86_l_442e;
	case 17457ULL: goto x86_l_4431;
	case 17463ULL: goto x86_l_4437;
	case 17467ULL: goto x86_l_443b;
	case 17472ULL: goto x86_l_4440;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17487ULL: goto x86_l_444f;
	case 17491ULL: goto x86_l_4453;
	case 17496ULL: goto x86_l_4458;
	case 17501ULL: goto x86_l_445d;
	case 17503ULL: goto x86_l_445f;
	case 17508ULL: goto x86_l_4464;
	case 17512ULL: goto x86_l_4468;
	case 17515ULL: goto x86_l_446b;
	case 17520ULL: goto x86_l_4470;
	case 17522ULL: goto x86_l_4472;
	case 17527ULL: goto x86_l_4477;
	case 17531ULL: goto x86_l_447b;
	case 17536ULL: goto x86_l_4480;
	case 17541ULL: goto x86_l_4485;
	case 17543ULL: goto x86_l_4487;
	case 17547ULL: goto x86_l_448b;
	case 17551ULL: goto x86_l_448f;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17569ULL: goto x86_l_44a1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3e42:
	/* 0x3e42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e44:
	/* 0x3e44: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e49:
	/* 0x3e49: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3e4c:
	/* 0x3e4c: je     3fda <trace_security_file_mprotect+0x3fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fda;
	}
x86_l_3e52:
	/* 0x3e52: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e57:
	/* 0x3e57: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e5a:
	/* 0x3e5a: je     3fda <trace_security_file_mprotect+0x3fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fda;
	}
x86_l_3e60:
	/* 0x3e60: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e64:
	/* 0x3e64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e69:
	/* 0x3e69: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e6e:
	/* 0x3e6e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3e73:
	/* 0x3e73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e75:
	/* 0x3e75: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3e79:
	/* 0x3e79: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3e7b:
	/* 0x3e7b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e81:
	/* 0x3e81: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3e84:
	/* 0x3e84: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e86:
	/* 0x3e86: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_3e8c:
	/* 0x3e8c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e91:
	/* 0x3e91: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3e97:
	/* 0x3e97: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e9a:
	/* 0x3e9a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3e9f:
	/* 0x3e9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea1:
	/* 0x3ea1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ea4:
	/* 0x3ea4: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_3eaa:
	/* 0x3eaa: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3eae:
	/* 0x3eae: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3eb4:
	/* 0x3eb4: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3eb8:
	/* 0x3eb8: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ebb:
	/* 0x3ebb: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec0:
	/* 0x3ec0: jmp    403b <trace_security_file_mprotect+0x403b> */
	goto x86_l_403b;
x86_l_3ec5:
	/* 0x3ec5: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3ec8:
	/* 0x3ec8: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_3ece:
	/* 0x3ece: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed2:
	/* 0x3ed2: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3ed7:
	/* 0x3ed7: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_3edd:
	/* 0x3edd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee6:
	/* 0x3ee6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3eea:
	/* 0x3eea: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eef:
	/* 0x3eef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef4:
	/* 0x3ef4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef6:
	/* 0x3ef6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3efb:
	/* 0x3efb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eff:
	/* 0x3eff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f02:
	/* 0x3f02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f07:
	/* 0x3f07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f09:
	/* 0x3f09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f0e:
	/* 0x3f0e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f12:
	/* 0x3f12: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f17:
	/* 0x3f17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f1c:
	/* 0x3f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f1e:
	/* 0x3f1e: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f22:
	/* 0x3f22: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f26:
	/* 0x3f26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f2b:
	/* 0x3f2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f30:
	/* 0x3f30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f35:
	/* 0x3f35: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3f38:
	/* 0x3f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3a:
	/* 0x3f3a: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f3f:
	/* 0x3f3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f44:
	/* 0x3f44: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f48:
	/* 0x3f48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f4d:
	/* 0x3f4d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f52:
	/* 0x3f52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f57:
	/* 0x3f57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f59:
	/* 0x3f59: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f5e:
	/* 0x3f5e: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3f61:
	/* 0x3f61: je     40ef <trace_security_file_mprotect+0x40ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40ef;
	}
x86_l_3f67:
	/* 0x3f67: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f6c:
	/* 0x3f6c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3f6f:
	/* 0x3f6f: je     40ef <trace_security_file_mprotect+0x40ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40ef;
	}
x86_l_3f75:
	/* 0x3f75: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f79:
	/* 0x3f79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f7e:
	/* 0x3f7e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f83:
	/* 0x3f83: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f88:
	/* 0x3f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8a:
	/* 0x3f8a: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3f8e:
	/* 0x3f8e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f90:
	/* 0x3f90: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f96:
	/* 0x3f96: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3f99:
	/* 0x3f99: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f9b:
	/* 0x3f9b: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_3fa1:
	/* 0x3fa1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fa6:
	/* 0x3fa6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3fac:
	/* 0x3fac: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3faf:
	/* 0x3faf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3fb4:
	/* 0x3fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fb6:
	/* 0x3fb6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3fb9:
	/* 0x3fb9: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_3fbf:
	/* 0x3fbf: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3fc3:
	/* 0x3fc3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3fc9:
	/* 0x3fc9: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3fcd:
	/* 0x3fcd: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fd0:
	/* 0x3fd0: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd5:
	/* 0x3fd5: jmp    4150 <trace_security_file_mprotect+0x4150> */
	goto x86_l_4150;
x86_l_3fda:
	/* 0x3fda: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3fdd:
	/* 0x3fdd: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_3fe3:
	/* 0x3fe3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe7:
	/* 0x3fe7: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3fec:
	/* 0x3fec: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_3ff2:
	/* 0x3ff2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ff7:
	/* 0x3ff7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ffb:
	/* 0x3ffb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fff:
	/* 0x3fff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4004:
	/* 0x4004: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4009:
	/* 0x4009: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_400b:
	/* 0x400b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4010:
	/* 0x4010: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4014:
	/* 0x4014: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4017:
	/* 0x4017: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_401c:
	/* 0x401c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401e:
	/* 0x401e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4023:
	/* 0x4023: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4027:
	/* 0x4027: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_402c:
	/* 0x402c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4031:
	/* 0x4031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4033:
	/* 0x4033: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4037:
	/* 0x4037: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_403b:
	/* 0x403b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4040:
	/* 0x4040: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4045:
	/* 0x4045: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_404a:
	/* 0x404a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_404d:
	/* 0x404d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_404f:
	/* 0x404f: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4054:
	/* 0x4054: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4059:
	/* 0x4059: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_405d:
	/* 0x405d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4062:
	/* 0x4062: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4067:
	/* 0x4067: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_406c:
	/* 0x406c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406e:
	/* 0x406e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4073:
	/* 0x4073: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4076:
	/* 0x4076: je     4204 <trace_security_file_mprotect+0x4204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4204;
	}
x86_l_407c:
	/* 0x407c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4081:
	/* 0x4081: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4084:
	/* 0x4084: je     4204 <trace_security_file_mprotect+0x4204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4204;
	}
x86_l_408a:
	/* 0x408a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_408e:
	/* 0x408e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4093:
	/* 0x4093: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4098:
	/* 0x4098: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_409d:
	/* 0x409d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409f:
	/* 0x409f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_40a3:
	/* 0x40a3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_40a5:
	/* 0x40a5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_40ab:
	/* 0x40ab: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_40ae:
	/* 0x40ae: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40b0:
	/* 0x40b0: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_40b6:
	/* 0x40b6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40bb:
	/* 0x40bb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_40c1:
	/* 0x40c1: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40c4:
	/* 0x40c4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_40c9:
	/* 0x40c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40cb:
	/* 0x40cb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_40ce:
	/* 0x40ce: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_40d4:
	/* 0x40d4: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_40d8:
	/* 0x40d8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_40de:
	/* 0x40de: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_40e2:
	/* 0x40e2: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40e5:
	/* 0x40e5: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40ea:
	/* 0x40ea: jmp    4265 <trace_security_file_mprotect+0x4265> */
	goto x86_l_4265;
x86_l_40ef:
	/* 0x40ef: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_40f2:
	/* 0x40f2: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_40f8:
	/* 0x40f8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40fc:
	/* 0x40fc: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4101:
	/* 0x4101: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_4107:
	/* 0x4107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_410c:
	/* 0x410c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4110:
	/* 0x4110: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4114:
	/* 0x4114: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4119:
	/* 0x4119: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_411e:
	/* 0x411e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4120:
	/* 0x4120: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4125:
	/* 0x4125: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4129:
	/* 0x4129: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_412c:
	/* 0x412c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4131:
	/* 0x4131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4133:
	/* 0x4133: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4138:
	/* 0x4138: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_413c:
	/* 0x413c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4141:
	/* 0x4141: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4146:
	/* 0x4146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4148:
	/* 0x4148: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414c:
	/* 0x414c: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4150:
	/* 0x4150: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4155:
	/* 0x4155: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_415a:
	/* 0x415a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_415f:
	/* 0x415f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4162:
	/* 0x4162: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4164:
	/* 0x4164: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4169:
	/* 0x4169: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_416e:
	/* 0x416e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4172:
	/* 0x4172: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4177:
	/* 0x4177: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_417c:
	/* 0x417c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4181:
	/* 0x4181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4183:
	/* 0x4183: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4188:
	/* 0x4188: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_418b:
	/* 0x418b: je     4319 <trace_security_file_mprotect+0x4319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4319;
	}
x86_l_4191:
	/* 0x4191: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4196:
	/* 0x4196: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4199:
	/* 0x4199: je     4319 <trace_security_file_mprotect+0x4319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4319;
	}
x86_l_419f:
	/* 0x419f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_41a3:
	/* 0x41a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41a8:
	/* 0x41a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41ad:
	/* 0x41ad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_41b2:
	/* 0x41b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b4:
	/* 0x41b4: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_41b8:
	/* 0x41b8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_41ba:
	/* 0x41ba: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41c0:
	/* 0x41c0: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_41c3:
	/* 0x41c3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_41c5:
	/* 0x41c5: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_41cb:
	/* 0x41cb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41d0:
	/* 0x41d0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_41d6:
	/* 0x41d6: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_41d9:
	/* 0x41d9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_41de:
	/* 0x41de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e0:
	/* 0x41e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_41e3:
	/* 0x41e3: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_41e9:
	/* 0x41e9: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_41ed:
	/* 0x41ed: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_41f3:
	/* 0x41f3: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_41f7:
	/* 0x41f7: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_41fa:
	/* 0x41fa: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ff:
	/* 0x41ff: jmp    437a <trace_security_file_mprotect+0x437a> */
	goto x86_l_437a;
x86_l_4204:
	/* 0x4204: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4207:
	/* 0x4207: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_420d:
	/* 0x420d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4211:
	/* 0x4211: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4216:
	/* 0x4216: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_421c:
	/* 0x421c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4221:
	/* 0x4221: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4225:
	/* 0x4225: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4229:
	/* 0x4229: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_422e:
	/* 0x422e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4233:
	/* 0x4233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4235:
	/* 0x4235: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_423a:
	/* 0x423a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_423e:
	/* 0x423e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4241:
	/* 0x4241: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4246:
	/* 0x4246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4248:
	/* 0x4248: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_424d:
	/* 0x424d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4251:
	/* 0x4251: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4256:
	/* 0x4256: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425b:
	/* 0x425b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425d:
	/* 0x425d: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4261:
	/* 0x4261: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4265:
	/* 0x4265: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_426a:
	/* 0x426a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_426f:
	/* 0x426f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4274:
	/* 0x4274: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4277:
	/* 0x4277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4279:
	/* 0x4279: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_427e:
	/* 0x427e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4283:
	/* 0x4283: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4287:
	/* 0x4287: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_428c:
	/* 0x428c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4291:
	/* 0x4291: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4296:
	/* 0x4296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4298:
	/* 0x4298: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429d:
	/* 0x429d: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_42a0:
	/* 0x42a0: je     442e <trace_security_file_mprotect+0x442e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_442e;
	}
x86_l_42a6:
	/* 0x42a6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42ab:
	/* 0x42ab: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_42ae:
	/* 0x42ae: je     442e <trace_security_file_mprotect+0x442e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_442e;
	}
x86_l_42b4:
	/* 0x42b4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_42b8:
	/* 0x42b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42bd:
	/* 0x42bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42c2:
	/* 0x42c2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_42c7:
	/* 0x42c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42c9:
	/* 0x42c9: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_42cd:
	/* 0x42cd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_42cf:
	/* 0x42cf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_42d5:
	/* 0x42d5: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_42d8:
	/* 0x42d8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_42da:
	/* 0x42da: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_42e0:
	/* 0x42e0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42e5:
	/* 0x42e5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_42eb:
	/* 0x42eb: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_42ee:
	/* 0x42ee: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_42f3:
	/* 0x42f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f5:
	/* 0x42f5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_42f8:
	/* 0x42f8: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_42fe:
	/* 0x42fe: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4302:
	/* 0x4302: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4308:
	/* 0x4308: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_430c:
	/* 0x430c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_430f:
	/* 0x430f: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4314:
	/* 0x4314: jmp    448f <trace_security_file_mprotect+0x448f> */
	goto x86_l_448f;
x86_l_4319:
	/* 0x4319: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_431c:
	/* 0x431c: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_4322:
	/* 0x4322: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4326:
	/* 0x4326: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_432b:
	/* 0x432b: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_4331:
	/* 0x4331: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4336:
	/* 0x4336: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_433a:
	/* 0x433a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_433e:
	/* 0x433e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4343:
	/* 0x4343: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4348:
	/* 0x4348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_434a:
	/* 0x434a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_434f:
	/* 0x434f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4353:
	/* 0x4353: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4356:
	/* 0x4356: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_435b:
	/* 0x435b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_435d:
	/* 0x435d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4362:
	/* 0x4362: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4366:
	/* 0x4366: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_436b:
	/* 0x436b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4370:
	/* 0x4370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4372:
	/* 0x4372: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4376:
	/* 0x4376: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_437a:
	/* 0x437a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_437f:
	/* 0x437f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4384:
	/* 0x4384: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4389:
	/* 0x4389: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_438c:
	/* 0x438c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_438e:
	/* 0x438e: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4393:
	/* 0x4393: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4398:
	/* 0x4398: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_439c:
	/* 0x439c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43a1:
	/* 0x43a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43a6:
	/* 0x43a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43ab:
	/* 0x43ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43ad:
	/* 0x43ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43b2:
	/* 0x43b2: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_43b5:
	/* 0x43b5: je     4543 <trace_security_file_mprotect+0x4543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17731ULL;
	}
x86_l_43bb:
	/* 0x43bb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43c0:
	/* 0x43c0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_43c3:
	/* 0x43c3: je     4543 <trace_security_file_mprotect+0x4543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17731ULL;
	}
x86_l_43c9:
	/* 0x43c9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_43cd:
	/* 0x43cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43d2:
	/* 0x43d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43d7:
	/* 0x43d7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_43dc:
	/* 0x43dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43de:
	/* 0x43de: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_43e2:
	/* 0x43e2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_43e4:
	/* 0x43e4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_43ea:
	/* 0x43ea: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_43ed:
	/* 0x43ed: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43ef:
	/* 0x43ef: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_43f5:
	/* 0x43f5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43fa:
	/* 0x43fa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4400:
	/* 0x4400: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4403:
	/* 0x4403: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4408:
	/* 0x4408: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440a:
	/* 0x440a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_440d:
	/* 0x440d: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_4413:
	/* 0x4413: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4417:
	/* 0x4417: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_441d:
	/* 0x441d: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4421:
	/* 0x4421: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4424:
	/* 0x4424: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4429:
	/* 0x4429: jmp    45a4 <trace_security_file_mprotect+0x45a4> */
	return 17828ULL;
x86_l_442e:
	/* 0x442e: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4431:
	/* 0x4431: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_4437:
	/* 0x4437: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_443b:
	/* 0x443b: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4440:
	/* 0x4440: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_4446:
	/* 0x4446: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_444b:
	/* 0x444b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_444f:
	/* 0x444f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4453:
	/* 0x4453: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4458:
	/* 0x4458: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_445d:
	/* 0x445d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445f:
	/* 0x445f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4464:
	/* 0x4464: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4468:
	/* 0x4468: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_446b:
	/* 0x446b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4470:
	/* 0x4470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4472:
	/* 0x4472: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4477:
	/* 0x4477: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_447b:
	/* 0x447b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4480:
	/* 0x4480: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4485:
	/* 0x4485: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4487:
	/* 0x4487: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448b:
	/* 0x448b: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_448f:
	/* 0x448f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4494:
	/* 0x4494: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4499:
	/* 0x4499: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_449e:
	/* 0x449e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_44a1:
	/* 0x44a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 17571ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17571ULL: goto x86_l_44a3;
	case 17576ULL: goto x86_l_44a8;
	case 17581ULL: goto x86_l_44ad;
	case 17585ULL: goto x86_l_44b1;
	case 17590ULL: goto x86_l_44b6;
	case 17595ULL: goto x86_l_44bb;
	case 17600ULL: goto x86_l_44c0;
	case 17602ULL: goto x86_l_44c2;
	case 17607ULL: goto x86_l_44c7;
	case 17610ULL: goto x86_l_44ca;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17624ULL: goto x86_l_44d8;
	case 17630ULL: goto x86_l_44de;
	case 17634ULL: goto x86_l_44e2;
	case 17639ULL: goto x86_l_44e7;
	case 17644ULL: goto x86_l_44ec;
	case 17649ULL: goto x86_l_44f1;
	case 17651ULL: goto x86_l_44f3;
	case 17655ULL: goto x86_l_44f7;
	case 17657ULL: goto x86_l_44f9;
	case 17663ULL: goto x86_l_44ff;
	case 17666ULL: goto x86_l_4502;
	case 17668ULL: goto x86_l_4504;
	case 17674ULL: goto x86_l_450a;
	case 17679ULL: goto x86_l_450f;
	case 17685ULL: goto x86_l_4515;
	case 17688ULL: goto x86_l_4518;
	case 17693ULL: goto x86_l_451d;
	case 17695ULL: goto x86_l_451f;
	case 17698ULL: goto x86_l_4522;
	case 17704ULL: goto x86_l_4528;
	case 17708ULL: goto x86_l_452c;
	case 17714ULL: goto x86_l_4532;
	case 17718ULL: goto x86_l_4536;
	case 17721ULL: goto x86_l_4539;
	case 17726ULL: goto x86_l_453e;
	case 17731ULL: goto x86_l_4543;
	case 17734ULL: goto x86_l_4546;
	case 17740ULL: goto x86_l_454c;
	case 17744ULL: goto x86_l_4550;
	case 17749ULL: goto x86_l_4555;
	case 17755ULL: goto x86_l_455b;
	case 17760ULL: goto x86_l_4560;
	case 17764ULL: goto x86_l_4564;
	case 17768ULL: goto x86_l_4568;
	case 17773ULL: goto x86_l_456d;
	case 17778ULL: goto x86_l_4572;
	case 17780ULL: goto x86_l_4574;
	case 17785ULL: goto x86_l_4579;
	case 17789ULL: goto x86_l_457d;
	case 17792ULL: goto x86_l_4580;
	case 17797ULL: goto x86_l_4585;
	case 17799ULL: goto x86_l_4587;
	case 17804ULL: goto x86_l_458c;
	case 17808ULL: goto x86_l_4590;
	case 17813ULL: goto x86_l_4595;
	case 17818ULL: goto x86_l_459a;
	case 17820ULL: goto x86_l_459c;
	case 17824ULL: goto x86_l_45a0;
	case 17828ULL: goto x86_l_45a4;
	case 17833ULL: goto x86_l_45a9;
	case 17838ULL: goto x86_l_45ae;
	case 17843ULL: goto x86_l_45b3;
	case 17846ULL: goto x86_l_45b6;
	case 17848ULL: goto x86_l_45b8;
	case 17853ULL: goto x86_l_45bd;
	case 17858ULL: goto x86_l_45c2;
	case 17862ULL: goto x86_l_45c6;
	case 17867ULL: goto x86_l_45cb;
	case 17872ULL: goto x86_l_45d0;
	case 17877ULL: goto x86_l_45d5;
	case 17879ULL: goto x86_l_45d7;
	case 17884ULL: goto x86_l_45dc;
	case 17887ULL: goto x86_l_45df;
	case 17893ULL: goto x86_l_45e5;
	case 17898ULL: goto x86_l_45ea;
	case 17901ULL: goto x86_l_45ed;
	case 17907ULL: goto x86_l_45f3;
	case 17911ULL: goto x86_l_45f7;
	case 17916ULL: goto x86_l_45fc;
	case 17921ULL: goto x86_l_4601;
	case 17926ULL: goto x86_l_4606;
	case 17928ULL: goto x86_l_4608;
	case 17932ULL: goto x86_l_460c;
	case 17934ULL: goto x86_l_460e;
	case 17940ULL: goto x86_l_4614;
	case 17943ULL: goto x86_l_4617;
	case 17945ULL: goto x86_l_4619;
	case 17951ULL: goto x86_l_461f;
	case 17956ULL: goto x86_l_4624;
	case 17962ULL: goto x86_l_462a;
	case 17965ULL: goto x86_l_462d;
	case 17970ULL: goto x86_l_4632;
	case 17972ULL: goto x86_l_4634;
	case 17975ULL: goto x86_l_4637;
	case 17981ULL: goto x86_l_463d;
	case 17985ULL: goto x86_l_4641;
	case 17991ULL: goto x86_l_4647;
	case 17995ULL: goto x86_l_464b;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18008ULL: goto x86_l_4658;
	case 18011ULL: goto x86_l_465b;
	case 18017ULL: goto x86_l_4661;
	case 18021ULL: goto x86_l_4665;
	case 18026ULL: goto x86_l_466a;
	case 18032ULL: goto x86_l_4670;
	case 18037ULL: goto x86_l_4675;
	case 18041ULL: goto x86_l_4679;
	case 18045ULL: goto x86_l_467d;
	case 18050ULL: goto x86_l_4682;
	case 18055ULL: goto x86_l_4687;
	case 18057ULL: goto x86_l_4689;
	case 18062ULL: goto x86_l_468e;
	case 18066ULL: goto x86_l_4692;
	case 18069ULL: goto x86_l_4695;
	case 18074ULL: goto x86_l_469a;
	case 18076ULL: goto x86_l_469c;
	case 18081ULL: goto x86_l_46a1;
	case 18085ULL: goto x86_l_46a5;
	case 18090ULL: goto x86_l_46aa;
	case 18095ULL: goto x86_l_46af;
	case 18097ULL: goto x86_l_46b1;
	case 18101ULL: goto x86_l_46b5;
	case 18105ULL: goto x86_l_46b9;
	case 18110ULL: goto x86_l_46be;
	case 18115ULL: goto x86_l_46c3;
	case 18120ULL: goto x86_l_46c8;
	case 18123ULL: goto x86_l_46cb;
	case 18125ULL: goto x86_l_46cd;
	case 18130ULL: goto x86_l_46d2;
	case 18135ULL: goto x86_l_46d7;
	case 18139ULL: goto x86_l_46db;
	case 18144ULL: goto x86_l_46e0;
	case 18149ULL: goto x86_l_46e5;
	case 18154ULL: goto x86_l_46ea;
	case 18156ULL: goto x86_l_46ec;
	case 18161ULL: goto x86_l_46f1;
	case 18164ULL: goto x86_l_46f4;
	case 18170ULL: goto x86_l_46fa;
	case 18175ULL: goto x86_l_46ff;
	case 18178ULL: goto x86_l_4702;
	case 18184ULL: goto x86_l_4708;
	case 18188ULL: goto x86_l_470c;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18205ULL: goto x86_l_471d;
	case 18209ULL: goto x86_l_4721;
	case 18211ULL: goto x86_l_4723;
	case 18217ULL: goto x86_l_4729;
	case 18220ULL: goto x86_l_472c;
	case 18222ULL: goto x86_l_472e;
	case 18228ULL: goto x86_l_4734;
	case 18233ULL: goto x86_l_4739;
	case 18239ULL: goto x86_l_473f;
	case 18242ULL: goto x86_l_4742;
	case 18247ULL: goto x86_l_4747;
	case 18249ULL: goto x86_l_4749;
	case 18252ULL: goto x86_l_474c;
	case 18258ULL: goto x86_l_4752;
	case 18262ULL: goto x86_l_4756;
	case 18268ULL: goto x86_l_475c;
	case 18272ULL: goto x86_l_4760;
	case 18275ULL: goto x86_l_4763;
	case 18280ULL: goto x86_l_4768;
	case 18285ULL: goto x86_l_476d;
	case 18288ULL: goto x86_l_4770;
	case 18294ULL: goto x86_l_4776;
	case 18298ULL: goto x86_l_477a;
	case 18303ULL: goto x86_l_477f;
	case 18309ULL: goto x86_l_4785;
	case 18314ULL: goto x86_l_478a;
	case 18318ULL: goto x86_l_478e;
	case 18322ULL: goto x86_l_4792;
	case 18327ULL: goto x86_l_4797;
	case 18332ULL: goto x86_l_479c;
	case 18334ULL: goto x86_l_479e;
	case 18339ULL: goto x86_l_47a3;
	case 18343ULL: goto x86_l_47a7;
	case 18346ULL: goto x86_l_47aa;
	case 18351ULL: goto x86_l_47af;
	case 18353ULL: goto x86_l_47b1;
	case 18358ULL: goto x86_l_47b6;
	case 18362ULL: goto x86_l_47ba;
	case 18367ULL: goto x86_l_47bf;
	case 18372ULL: goto x86_l_47c4;
	case 18374ULL: goto x86_l_47c6;
	case 18378ULL: goto x86_l_47ca;
	case 18382ULL: goto x86_l_47ce;
	case 18387ULL: goto x86_l_47d3;
	case 18392ULL: goto x86_l_47d8;
	case 18397ULL: goto x86_l_47dd;
	case 18400ULL: goto x86_l_47e0;
	case 18402ULL: goto x86_l_47e2;
	case 18407ULL: goto x86_l_47e7;
	case 18412ULL: goto x86_l_47ec;
	case 18416ULL: goto x86_l_47f0;
	case 18421ULL: goto x86_l_47f5;
	case 18426ULL: goto x86_l_47fa;
	case 18431ULL: goto x86_l_47ff;
	case 18433ULL: goto x86_l_4801;
	case 18438ULL: goto x86_l_4806;
	case 18441ULL: goto x86_l_4809;
	case 18447ULL: goto x86_l_480f;
	case 18452ULL: goto x86_l_4814;
	case 18455ULL: goto x86_l_4817;
	case 18461ULL: goto x86_l_481d;
	case 18465ULL: goto x86_l_4821;
	case 18470ULL: goto x86_l_4826;
	case 18475ULL: goto x86_l_482b;
	case 18480ULL: goto x86_l_4830;
	case 18482ULL: goto x86_l_4832;
	case 18486ULL: goto x86_l_4836;
	case 18488ULL: goto x86_l_4838;
	case 18494ULL: goto x86_l_483e;
	case 18497ULL: goto x86_l_4841;
	case 18499ULL: goto x86_l_4843;
	case 18505ULL: goto x86_l_4849;
	case 18510ULL: goto x86_l_484e;
	case 18516ULL: goto x86_l_4854;
	case 18519ULL: goto x86_l_4857;
	case 18524ULL: goto x86_l_485c;
	case 18526ULL: goto x86_l_485e;
	case 18529ULL: goto x86_l_4861;
	case 18535ULL: goto x86_l_4867;
	case 18539ULL: goto x86_l_486b;
	case 18545ULL: goto x86_l_4871;
	case 18549ULL: goto x86_l_4875;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18562ULL: goto x86_l_4882;
	case 18565ULL: goto x86_l_4885;
	case 18571ULL: goto x86_l_488b;
	case 18575ULL: goto x86_l_488f;
	case 18580ULL: goto x86_l_4894;
	case 18586ULL: goto x86_l_489a;
	case 18591ULL: goto x86_l_489f;
	case 18595ULL: goto x86_l_48a3;
	case 18599ULL: goto x86_l_48a7;
	case 18604ULL: goto x86_l_48ac;
	case 18609ULL: goto x86_l_48b1;
	case 18611ULL: goto x86_l_48b3;
	case 18616ULL: goto x86_l_48b8;
	case 18620ULL: goto x86_l_48bc;
	case 18623ULL: goto x86_l_48bf;
	case 18628ULL: goto x86_l_48c4;
	case 18630ULL: goto x86_l_48c6;
	case 18635ULL: goto x86_l_48cb;
	case 18639ULL: goto x86_l_48cf;
	case 18644ULL: goto x86_l_48d4;
	case 18649ULL: goto x86_l_48d9;
	case 18651ULL: goto x86_l_48db;
	case 18655ULL: goto x86_l_48df;
	case 18659ULL: goto x86_l_48e3;
	case 18664ULL: goto x86_l_48e8;
	case 18669ULL: goto x86_l_48ed;
	case 18674ULL: goto x86_l_48f2;
	case 18677ULL: goto x86_l_48f5;
	case 18679ULL: goto x86_l_48f7;
	case 18684ULL: goto x86_l_48fc;
	case 18689ULL: goto x86_l_4901;
	case 18693ULL: goto x86_l_4905;
	case 18698ULL: goto x86_l_490a;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18710ULL: goto x86_l_4916;
	case 18715ULL: goto x86_l_491b;
	case 18718ULL: goto x86_l_491e;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18732ULL: goto x86_l_492c;
	case 18738ULL: goto x86_l_4932;
	case 18742ULL: goto x86_l_4936;
	case 18747ULL: goto x86_l_493b;
	case 18752ULL: goto x86_l_4940;
	case 18757ULL: goto x86_l_4945;
	case 18759ULL: goto x86_l_4947;
	case 18763ULL: goto x86_l_494b;
	case 18765ULL: goto x86_l_494d;
	case 18771ULL: goto x86_l_4953;
	case 18774ULL: goto x86_l_4956;
	case 18776ULL: goto x86_l_4958;
	case 18782ULL: goto x86_l_495e;
	case 18787ULL: goto x86_l_4963;
	case 18793ULL: goto x86_l_4969;
	case 18796ULL: goto x86_l_496c;
	case 18801ULL: goto x86_l_4971;
	case 18803ULL: goto x86_l_4973;
	case 18806ULL: goto x86_l_4976;
	case 18812ULL: goto x86_l_497c;
	case 18816ULL: goto x86_l_4980;
	case 18822ULL: goto x86_l_4986;
	case 18826ULL: goto x86_l_498a;
	case 18829ULL: goto x86_l_498d;
	case 18834ULL: goto x86_l_4992;
	case 18839ULL: goto x86_l_4997;
	case 18842ULL: goto x86_l_499a;
	case 18848ULL: goto x86_l_49a0;
	case 18852ULL: goto x86_l_49a4;
	case 18857ULL: goto x86_l_49a9;
	case 18863ULL: goto x86_l_49af;
	case 18868ULL: goto x86_l_49b4;
	case 18872ULL: goto x86_l_49b8;
	case 18876ULL: goto x86_l_49bc;
	case 18881ULL: goto x86_l_49c1;
	case 18886ULL: goto x86_l_49c6;
	case 18888ULL: goto x86_l_49c8;
	case 18893ULL: goto x86_l_49cd;
	case 18897ULL: goto x86_l_49d1;
	case 18900ULL: goto x86_l_49d4;
	case 18905ULL: goto x86_l_49d9;
	case 18907ULL: goto x86_l_49db;
	case 18912ULL: goto x86_l_49e0;
	case 18916ULL: goto x86_l_49e4;
	case 18921ULL: goto x86_l_49e9;
	case 18926ULL: goto x86_l_49ee;
	case 18928ULL: goto x86_l_49f0;
	case 18932ULL: goto x86_l_49f4;
	case 18936ULL: goto x86_l_49f8;
	case 18941ULL: goto x86_l_49fd;
	case 18946ULL: goto x86_l_4a02;
	case 18951ULL: goto x86_l_4a07;
	case 18954ULL: goto x86_l_4a0a;
	case 18956ULL: goto x86_l_4a0c;
	case 18961ULL: goto x86_l_4a11;
	case 18966ULL: goto x86_l_4a16;
	case 18970ULL: goto x86_l_4a1a;
	case 18975ULL: goto x86_l_4a1f;
	case 18980ULL: goto x86_l_4a24;
	case 18985ULL: goto x86_l_4a29;
	case 18987ULL: goto x86_l_4a2b;
	case 18992ULL: goto x86_l_4a30;
	case 18995ULL: goto x86_l_4a33;
	case 19001ULL: goto x86_l_4a39;
	case 19006ULL: goto x86_l_4a3e;
	case 19009ULL: goto x86_l_4a41;
	case 19015ULL: goto x86_l_4a47;
	case 19019ULL: goto x86_l_4a4b;
	case 19024ULL: goto x86_l_4a50;
	case 19029ULL: goto x86_l_4a55;
	case 19034ULL: goto x86_l_4a5a;
	case 19036ULL: goto x86_l_4a5c;
	case 19040ULL: goto x86_l_4a60;
	case 19042ULL: goto x86_l_4a62;
	case 19048ULL: goto x86_l_4a68;
	case 19051ULL: goto x86_l_4a6b;
	case 19053ULL: goto x86_l_4a6d;
	case 19059ULL: goto x86_l_4a73;
	case 19064ULL: goto x86_l_4a78;
	case 19070ULL: goto x86_l_4a7e;
	case 19073ULL: goto x86_l_4a81;
	case 19078ULL: goto x86_l_4a86;
	case 19080ULL: goto x86_l_4a88;
	case 19083ULL: goto x86_l_4a8b;
	case 19089ULL: goto x86_l_4a91;
	case 19093ULL: goto x86_l_4a95;
	case 19099ULL: goto x86_l_4a9b;
	case 19103ULL: goto x86_l_4a9f;
	case 19106ULL: goto x86_l_4aa2;
	case 19111ULL: goto x86_l_4aa7;
	case 19116ULL: goto x86_l_4aac;
	case 19119ULL: goto x86_l_4aaf;
	case 19125ULL: goto x86_l_4ab5;
	case 19129ULL: goto x86_l_4ab9;
	case 19134ULL: goto x86_l_4abe;
	case 19140ULL: goto x86_l_4ac4;
	case 19145ULL: goto x86_l_4ac9;
	case 19149ULL: goto x86_l_4acd;
	case 19153ULL: goto x86_l_4ad1;
	case 19158ULL: goto x86_l_4ad6;
	case 19163ULL: goto x86_l_4adb;
	case 19165ULL: goto x86_l_4add;
	case 19170ULL: goto x86_l_4ae2;
	case 19174ULL: goto x86_l_4ae6;
	case 19177ULL: goto x86_l_4ae9;
	case 19182ULL: goto x86_l_4aee;
	case 19184ULL: goto x86_l_4af0;
	case 19189ULL: goto x86_l_4af5;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19203ULL: goto x86_l_4b03;
	case 19205ULL: goto x86_l_4b05;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44a3:
	/* 0x44a3: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44a8:
	/* 0x44a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44ad:
	/* 0x44ad: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44b1:
	/* 0x44b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44b6:
	/* 0x44b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44bb:
	/* 0x44bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44c0:
	/* 0x44c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44c2:
	/* 0x44c2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44c7:
	/* 0x44c7: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_44ca:
	/* 0x44ca: je     4658 <trace_security_file_mprotect+0x4658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4658;
	}
x86_l_44d0:
	/* 0x44d0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d5:
	/* 0x44d5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_44d8:
	/* 0x44d8: je     4658 <trace_security_file_mprotect+0x4658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4658;
	}
x86_l_44de:
	/* 0x44de: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_44e2:
	/* 0x44e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44e7:
	/* 0x44e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44ec:
	/* 0x44ec: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44f1:
	/* 0x44f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f3:
	/* 0x44f3: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_44f7:
	/* 0x44f7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44f9:
	/* 0x44f9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44ff:
	/* 0x44ff: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4502:
	/* 0x4502: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4504:
	/* 0x4504: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_450a:
	/* 0x450a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_450f:
	/* 0x450f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4515:
	/* 0x4515: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4518:
	/* 0x4518: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_451d:
	/* 0x451d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_451f:
	/* 0x451f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4522:
	/* 0x4522: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_4528:
	/* 0x4528: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_452c:
	/* 0x452c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4532:
	/* 0x4532: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4536:
	/* 0x4536: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4539:
	/* 0x4539: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_453e:
	/* 0x453e: jmp    46b9 <trace_security_file_mprotect+0x46b9> */
	goto x86_l_46b9;
x86_l_4543:
	/* 0x4543: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4546:
	/* 0x4546: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_454c:
	/* 0x454c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4550:
	/* 0x4550: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4555:
	/* 0x4555: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_455b:
	/* 0x455b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4560:
	/* 0x4560: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4564:
	/* 0x4564: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4568:
	/* 0x4568: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_456d:
	/* 0x456d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4572:
	/* 0x4572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4574:
	/* 0x4574: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4579:
	/* 0x4579: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457d:
	/* 0x457d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4580:
	/* 0x4580: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4585:
	/* 0x4585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4587:
	/* 0x4587: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_458c:
	/* 0x458c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4590:
	/* 0x4590: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4595:
	/* 0x4595: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_459a:
	/* 0x459a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_459c:
	/* 0x459c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a0:
	/* 0x45a0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45a4:
	/* 0x45a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45a9:
	/* 0x45a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45ae:
	/* 0x45ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45b3:
	/* 0x45b3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_45b6:
	/* 0x45b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45b8:
	/* 0x45b8: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45bd:
	/* 0x45bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c2:
	/* 0x45c2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_45c6:
	/* 0x45c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45cb:
	/* 0x45cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45d0:
	/* 0x45d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d5:
	/* 0x45d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d7:
	/* 0x45d7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45dc:
	/* 0x45dc: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_45df:
	/* 0x45df: je     476d <trace_security_file_mprotect+0x476d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_476d;
	}
x86_l_45e5:
	/* 0x45e5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45ea:
	/* 0x45ea: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_45ed:
	/* 0x45ed: je     476d <trace_security_file_mprotect+0x476d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_476d;
	}
x86_l_45f3:
	/* 0x45f3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45f7:
	/* 0x45f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45fc:
	/* 0x45fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4601:
	/* 0x4601: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4606:
	/* 0x4606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4608:
	/* 0x4608: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_460c:
	/* 0x460c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_460e:
	/* 0x460e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4614:
	/* 0x4614: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4617:
	/* 0x4617: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4619:
	/* 0x4619: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_461f:
	/* 0x461f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4624:
	/* 0x4624: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_462a:
	/* 0x462a: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_462d:
	/* 0x462d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4632:
	/* 0x4632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4634:
	/* 0x4634: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4637:
	/* 0x4637: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_463d:
	/* 0x463d: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4641:
	/* 0x4641: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4647:
	/* 0x4647: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_464b:
	/* 0x464b: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_464e:
	/* 0x464e: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4653:
	/* 0x4653: jmp    47ce <trace_security_file_mprotect+0x47ce> */
	goto x86_l_47ce;
x86_l_4658:
	/* 0x4658: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_465b:
	/* 0x465b: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_4661:
	/* 0x4661: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4665:
	/* 0x4665: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_466a:
	/* 0x466a: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_4670:
	/* 0x4670: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4675:
	/* 0x4675: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4679:
	/* 0x4679: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_467d:
	/* 0x467d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4682:
	/* 0x4682: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4687:
	/* 0x4687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4689:
	/* 0x4689: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_468e:
	/* 0x468e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4692:
	/* 0x4692: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4695:
	/* 0x4695: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_469a:
	/* 0x469a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_469c:
	/* 0x469c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46a1:
	/* 0x46a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a5:
	/* 0x46a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46aa:
	/* 0x46aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46af:
	/* 0x46af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b1:
	/* 0x46b1: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b5:
	/* 0x46b5: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46b9:
	/* 0x46b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46be:
	/* 0x46be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46c3:
	/* 0x46c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46c8:
	/* 0x46c8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46cb:
	/* 0x46cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46cd:
	/* 0x46cd: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46d2:
	/* 0x46d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d7:
	/* 0x46d7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46db:
	/* 0x46db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46e0:
	/* 0x46e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46e5:
	/* 0x46e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ea:
	/* 0x46ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ec:
	/* 0x46ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46f1:
	/* 0x46f1: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_46f4:
	/* 0x46f4: je     4882 <trace_security_file_mprotect+0x4882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4882;
	}
x86_l_46fa:
	/* 0x46fa: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ff:
	/* 0x46ff: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4702:
	/* 0x4702: je     4882 <trace_security_file_mprotect+0x4882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4882;
	}
x86_l_4708:
	/* 0x4708: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_470c:
	/* 0x470c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4711:
	/* 0x4711: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4716:
	/* 0x4716: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_471b:
	/* 0x471b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471d:
	/* 0x471d: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4721:
	/* 0x4721: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4723:
	/* 0x4723: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4729:
	/* 0x4729: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_472c:
	/* 0x472c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_472e:
	/* 0x472e: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_4734:
	/* 0x4734: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4739:
	/* 0x4739: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_473f:
	/* 0x473f: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4742:
	/* 0x4742: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4747:
	/* 0x4747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4749:
	/* 0x4749: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_474c:
	/* 0x474c: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_4752:
	/* 0x4752: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4756:
	/* 0x4756: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_475c:
	/* 0x475c: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4760:
	/* 0x4760: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4763:
	/* 0x4763: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4768:
	/* 0x4768: jmp    48e3 <trace_security_file_mprotect+0x48e3> */
	goto x86_l_48e3;
x86_l_476d:
	/* 0x476d: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4770:
	/* 0x4770: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_4776:
	/* 0x4776: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_477a:
	/* 0x477a: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_477f:
	/* 0x477f: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_4785:
	/* 0x4785: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_478a:
	/* 0x478a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_478e:
	/* 0x478e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4792:
	/* 0x4792: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4797:
	/* 0x4797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_479c:
	/* 0x479c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479e:
	/* 0x479e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47a3:
	/* 0x47a3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a7:
	/* 0x47a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47aa:
	/* 0x47aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47af:
	/* 0x47af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b1:
	/* 0x47b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47b6:
	/* 0x47b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47ba:
	/* 0x47ba: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47bf:
	/* 0x47bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47c4:
	/* 0x47c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c6:
	/* 0x47c6: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47ca:
	/* 0x47ca: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_47ce:
	/* 0x47ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47d3:
	/* 0x47d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47d8:
	/* 0x47d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47dd:
	/* 0x47dd: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_47e0:
	/* 0x47e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47e2:
	/* 0x47e2: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47e7:
	/* 0x47e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47ec:
	/* 0x47ec: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_47f0:
	/* 0x47f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47f5:
	/* 0x47f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47fa:
	/* 0x47fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ff:
	/* 0x47ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4801:
	/* 0x4801: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4806:
	/* 0x4806: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4809:
	/* 0x4809: je     4997 <trace_security_file_mprotect+0x4997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4997;
	}
x86_l_480f:
	/* 0x480f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4814:
	/* 0x4814: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4817:
	/* 0x4817: je     4997 <trace_security_file_mprotect+0x4997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4997;
	}
x86_l_481d:
	/* 0x481d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4821:
	/* 0x4821: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4826:
	/* 0x4826: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_482b:
	/* 0x482b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4830:
	/* 0x4830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4832:
	/* 0x4832: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4836:
	/* 0x4836: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4838:
	/* 0x4838: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_483e:
	/* 0x483e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4841:
	/* 0x4841: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4843:
	/* 0x4843: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_4849:
	/* 0x4849: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_484e:
	/* 0x484e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4854:
	/* 0x4854: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4857:
	/* 0x4857: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_485c:
	/* 0x485c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485e:
	/* 0x485e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4861:
	/* 0x4861: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_4867:
	/* 0x4867: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_486b:
	/* 0x486b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4871:
	/* 0x4871: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4875:
	/* 0x4875: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4878:
	/* 0x4878: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487d:
	/* 0x487d: jmp    49f8 <trace_security_file_mprotect+0x49f8> */
	goto x86_l_49f8;
x86_l_4882:
	/* 0x4882: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4885:
	/* 0x4885: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_488b:
	/* 0x488b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_488f:
	/* 0x488f: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4894:
	/* 0x4894: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_489a:
	/* 0x489a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_489f:
	/* 0x489f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48a3:
	/* 0x48a3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_48a7:
	/* 0x48a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48ac:
	/* 0x48ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48b1:
	/* 0x48b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48b3:
	/* 0x48b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48b8:
	/* 0x48b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48bc:
	/* 0x48bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48bf:
	/* 0x48bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48c4:
	/* 0x48c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48c6:
	/* 0x48c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48cb:
	/* 0x48cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48cf:
	/* 0x48cf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48d4:
	/* 0x48d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d9:
	/* 0x48d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48db:
	/* 0x48db: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48df:
	/* 0x48df: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48e3:
	/* 0x48e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48e8:
	/* 0x48e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48ed:
	/* 0x48ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48f2:
	/* 0x48f2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_48f5:
	/* 0x48f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f7:
	/* 0x48f7: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48fc:
	/* 0x48fc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4901:
	/* 0x4901: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4905:
	/* 0x4905: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_490a:
	/* 0x490a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_490f:
	/* 0x490f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4914:
	/* 0x4914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4916:
	/* 0x4916: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491b:
	/* 0x491b: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_491e:
	/* 0x491e: je     4aac <trace_security_file_mprotect+0x4aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aac;
	}
x86_l_4924:
	/* 0x4924: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4929:
	/* 0x4929: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_492c:
	/* 0x492c: je     4aac <trace_security_file_mprotect+0x4aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aac;
	}
x86_l_4932:
	/* 0x4932: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4936:
	/* 0x4936: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_493b:
	/* 0x493b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4940:
	/* 0x4940: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4945:
	/* 0x4945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4947:
	/* 0x4947: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_494b:
	/* 0x494b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_494d:
	/* 0x494d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4953:
	/* 0x4953: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4956:
	/* 0x4956: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4958:
	/* 0x4958: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_495e:
	/* 0x495e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4963:
	/* 0x4963: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4969:
	/* 0x4969: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_496c:
	/* 0x496c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4971:
	/* 0x4971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4973:
	/* 0x4973: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4976:
	/* 0x4976: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_497c:
	/* 0x497c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4980:
	/* 0x4980: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4986:
	/* 0x4986: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_498a:
	/* 0x498a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_498d:
	/* 0x498d: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4992:
	/* 0x4992: jmp    4b0d <trace_security_file_mprotect+0x4b0d> */
	return 19213ULL;
x86_l_4997:
	/* 0x4997: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_499a:
	/* 0x499a: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_49a0:
	/* 0x49a0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49a4:
	/* 0x49a4: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_49a9:
	/* 0x49a9: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_49af:
	/* 0x49af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49b4:
	/* 0x49b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b8:
	/* 0x49b8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49bc:
	/* 0x49bc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49c1:
	/* 0x49c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c6:
	/* 0x49c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c8:
	/* 0x49c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49cd:
	/* 0x49cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49d1:
	/* 0x49d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49d4:
	/* 0x49d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d9:
	/* 0x49d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49db:
	/* 0x49db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49e0:
	/* 0x49e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e4:
	/* 0x49e4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49e9:
	/* 0x49e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49ee:
	/* 0x49ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f0:
	/* 0x49f0: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f4:
	/* 0x49f4: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_49f8:
	/* 0x49f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49fd:
	/* 0x49fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a02:
	/* 0x4a02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a07:
	/* 0x4a07: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4a0a:
	/* 0x4a0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a0c:
	/* 0x4a0c: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a11:
	/* 0x4a11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a16:
	/* 0x4a16: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a1a:
	/* 0x4a1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a1f:
	/* 0x4a1f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a24:
	/* 0x4a24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a29:
	/* 0x4a29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a2b:
	/* 0x4a2b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a30:
	/* 0x4a30: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4a33:
	/* 0x4a33: je     4bc1 <trace_security_file_mprotect+0x4bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19393ULL;
	}
x86_l_4a39:
	/* 0x4a39: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a3e:
	/* 0x4a3e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4a41:
	/* 0x4a41: je     4bc1 <trace_security_file_mprotect+0x4bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19393ULL;
	}
x86_l_4a47:
	/* 0x4a47: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a4b:
	/* 0x4a4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a50:
	/* 0x4a50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a55:
	/* 0x4a55: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4a5a:
	/* 0x4a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5c:
	/* 0x4a5c: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4a60:
	/* 0x4a60: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a62:
	/* 0x4a62: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a68:
	/* 0x4a68: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4a6b:
	/* 0x4a6b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4a6d:
	/* 0x4a6d: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_4a73:
	/* 0x4a73: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a78:
	/* 0x4a78: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4a7e:
	/* 0x4a7e: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4a81:
	/* 0x4a81: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4a86:
	/* 0x4a86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a88:
	/* 0x4a88: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a8b:
	/* 0x4a8b: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_4a91:
	/* 0x4a91: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4a95:
	/* 0x4a95: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4a9b:
	/* 0x4a9b: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4a9f:
	/* 0x4a9f: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4aa2:
	/* 0x4aa2: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aa7:
	/* 0x4aa7: jmp    4c22 <trace_security_file_mprotect+0x4c22> */
	return 19490ULL;
x86_l_4aac:
	/* 0x4aac: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4aaf:
	/* 0x4aaf: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_4ab5:
	/* 0x4ab5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ab9:
	/* 0x4ab9: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4abe:
	/* 0x4abe: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_4ac4:
	/* 0x4ac4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ac9:
	/* 0x4ac9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4acd:
	/* 0x4acd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ad1:
	/* 0x4ad1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad6:
	/* 0x4ad6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4adb:
	/* 0x4adb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4add:
	/* 0x4add: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ae2:
	/* 0x4ae2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae6:
	/* 0x4ae6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ae9:
	/* 0x4ae9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aee:
	/* 0x4aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4af0:
	/* 0x4af0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4af5:
	/* 0x4af5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4af9:
	/* 0x4af9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4afe:
	/* 0x4afe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b03:
	/* 0x4b03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b05:
	/* 0x4b05: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 19209ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19209ULL: goto x86_l_4b09;
	case 19213ULL: goto x86_l_4b0d;
	case 19218ULL: goto x86_l_4b12;
	case 19223ULL: goto x86_l_4b17;
	case 19228ULL: goto x86_l_4b1c;
	case 19231ULL: goto x86_l_4b1f;
	case 19233ULL: goto x86_l_4b21;
	case 19238ULL: goto x86_l_4b26;
	case 19243ULL: goto x86_l_4b2b;
	case 19247ULL: goto x86_l_4b2f;
	case 19252ULL: goto x86_l_4b34;
	case 19257ULL: goto x86_l_4b39;
	case 19262ULL: goto x86_l_4b3e;
	case 19264ULL: goto x86_l_4b40;
	case 19269ULL: goto x86_l_4b45;
	case 19272ULL: goto x86_l_4b48;
	case 19278ULL: goto x86_l_4b4e;
	case 19283ULL: goto x86_l_4b53;
	case 19286ULL: goto x86_l_4b56;
	case 19292ULL: goto x86_l_4b5c;
	case 19296ULL: goto x86_l_4b60;
	case 19301ULL: goto x86_l_4b65;
	case 19306ULL: goto x86_l_4b6a;
	case 19311ULL: goto x86_l_4b6f;
	case 19313ULL: goto x86_l_4b71;
	case 19317ULL: goto x86_l_4b75;
	case 19319ULL: goto x86_l_4b77;
	case 19325ULL: goto x86_l_4b7d;
	case 19328ULL: goto x86_l_4b80;
	case 19330ULL: goto x86_l_4b82;
	case 19336ULL: goto x86_l_4b88;
	case 19341ULL: goto x86_l_4b8d;
	case 19347ULL: goto x86_l_4b93;
	case 19350ULL: goto x86_l_4b96;
	case 19355ULL: goto x86_l_4b9b;
	case 19357ULL: goto x86_l_4b9d;
	case 19360ULL: goto x86_l_4ba0;
	case 19366ULL: goto x86_l_4ba6;
	case 19370ULL: goto x86_l_4baa;
	case 19376ULL: goto x86_l_4bb0;
	case 19380ULL: goto x86_l_4bb4;
	case 19383ULL: goto x86_l_4bb7;
	case 19388ULL: goto x86_l_4bbc;
	case 19393ULL: goto x86_l_4bc1;
	case 19396ULL: goto x86_l_4bc4;
	case 19402ULL: goto x86_l_4bca;
	case 19406ULL: goto x86_l_4bce;
	case 19411ULL: goto x86_l_4bd3;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19426ULL: goto x86_l_4be2;
	case 19430ULL: goto x86_l_4be6;
	case 19435ULL: goto x86_l_4beb;
	case 19440ULL: goto x86_l_4bf0;
	case 19442ULL: goto x86_l_4bf2;
	case 19447ULL: goto x86_l_4bf7;
	case 19451ULL: goto x86_l_4bfb;
	case 19454ULL: goto x86_l_4bfe;
	case 19459ULL: goto x86_l_4c03;
	case 19461ULL: goto x86_l_4c05;
	case 19466ULL: goto x86_l_4c0a;
	case 19470ULL: goto x86_l_4c0e;
	case 19475ULL: goto x86_l_4c13;
	case 19480ULL: goto x86_l_4c18;
	case 19482ULL: goto x86_l_4c1a;
	case 19486ULL: goto x86_l_4c1e;
	case 19490ULL: goto x86_l_4c22;
	case 19495ULL: goto x86_l_4c27;
	case 19500ULL: goto x86_l_4c2c;
	case 19505ULL: goto x86_l_4c31;
	case 19508ULL: goto x86_l_4c34;
	case 19510ULL: goto x86_l_4c36;
	case 19515ULL: goto x86_l_4c3b;
	case 19520ULL: goto x86_l_4c40;
	case 19524ULL: goto x86_l_4c44;
	case 19529ULL: goto x86_l_4c49;
	case 19534ULL: goto x86_l_4c4e;
	case 19539ULL: goto x86_l_4c53;
	case 19541ULL: goto x86_l_4c55;
	case 19546ULL: goto x86_l_4c5a;
	case 19549ULL: goto x86_l_4c5d;
	case 19555ULL: goto x86_l_4c63;
	case 19560ULL: goto x86_l_4c68;
	case 19563ULL: goto x86_l_4c6b;
	case 19569ULL: goto x86_l_4c71;
	case 19573ULL: goto x86_l_4c75;
	case 19578ULL: goto x86_l_4c7a;
	case 19583ULL: goto x86_l_4c7f;
	case 19588ULL: goto x86_l_4c84;
	case 19590ULL: goto x86_l_4c86;
	case 19594ULL: goto x86_l_4c8a;
	case 19596ULL: goto x86_l_4c8c;
	case 19602ULL: goto x86_l_4c92;
	case 19605ULL: goto x86_l_4c95;
	case 19607ULL: goto x86_l_4c97;
	case 19613ULL: goto x86_l_4c9d;
	case 19618ULL: goto x86_l_4ca2;
	case 19624ULL: goto x86_l_4ca8;
	case 19627ULL: goto x86_l_4cab;
	case 19632ULL: goto x86_l_4cb0;
	case 19634ULL: goto x86_l_4cb2;
	case 19637ULL: goto x86_l_4cb5;
	case 19643ULL: goto x86_l_4cbb;
	case 19647ULL: goto x86_l_4cbf;
	case 19653ULL: goto x86_l_4cc5;
	case 19657ULL: goto x86_l_4cc9;
	case 19660ULL: goto x86_l_4ccc;
	case 19665ULL: goto x86_l_4cd1;
	case 19670ULL: goto x86_l_4cd6;
	case 19673ULL: goto x86_l_4cd9;
	case 19679ULL: goto x86_l_4cdf;
	case 19683ULL: goto x86_l_4ce3;
	case 19688ULL: goto x86_l_4ce8;
	case 19694ULL: goto x86_l_4cee;
	case 19699ULL: goto x86_l_4cf3;
	case 19703ULL: goto x86_l_4cf7;
	case 19707ULL: goto x86_l_4cfb;
	case 19712ULL: goto x86_l_4d00;
	case 19717ULL: goto x86_l_4d05;
	case 19719ULL: goto x86_l_4d07;
	case 19724ULL: goto x86_l_4d0c;
	case 19728ULL: goto x86_l_4d10;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19738ULL: goto x86_l_4d1a;
	case 19743ULL: goto x86_l_4d1f;
	case 19747ULL: goto x86_l_4d23;
	case 19752ULL: goto x86_l_4d28;
	case 19757ULL: goto x86_l_4d2d;
	case 19759ULL: goto x86_l_4d2f;
	case 19763ULL: goto x86_l_4d33;
	case 19767ULL: goto x86_l_4d37;
	case 19772ULL: goto x86_l_4d3c;
	case 19777ULL: goto x86_l_4d41;
	case 19782ULL: goto x86_l_4d46;
	case 19785ULL: goto x86_l_4d49;
	case 19787ULL: goto x86_l_4d4b;
	case 19792ULL: goto x86_l_4d50;
	case 19797ULL: goto x86_l_4d55;
	case 19801ULL: goto x86_l_4d59;
	case 19806ULL: goto x86_l_4d5e;
	case 19811ULL: goto x86_l_4d63;
	case 19816ULL: goto x86_l_4d68;
	case 19818ULL: goto x86_l_4d6a;
	case 19823ULL: goto x86_l_4d6f;
	case 19826ULL: goto x86_l_4d72;
	case 19832ULL: goto x86_l_4d78;
	case 19837ULL: goto x86_l_4d7d;
	case 19840ULL: goto x86_l_4d80;
	case 19846ULL: goto x86_l_4d86;
	case 19850ULL: goto x86_l_4d8a;
	case 19855ULL: goto x86_l_4d8f;
	case 19860ULL: goto x86_l_4d94;
	case 19865ULL: goto x86_l_4d99;
	case 19867ULL: goto x86_l_4d9b;
	case 19871ULL: goto x86_l_4d9f;
	case 19873ULL: goto x86_l_4da1;
	case 19879ULL: goto x86_l_4da7;
	case 19882ULL: goto x86_l_4daa;
	case 19884ULL: goto x86_l_4dac;
	case 19890ULL: goto x86_l_4db2;
	case 19895ULL: goto x86_l_4db7;
	case 19901ULL: goto x86_l_4dbd;
	case 19904ULL: goto x86_l_4dc0;
	case 19909ULL: goto x86_l_4dc5;
	case 19911ULL: goto x86_l_4dc7;
	case 19914ULL: goto x86_l_4dca;
	case 19920ULL: goto x86_l_4dd0;
	case 19924ULL: goto x86_l_4dd4;
	case 19930ULL: goto x86_l_4dda;
	case 19934ULL: goto x86_l_4dde;
	case 19937ULL: goto x86_l_4de1;
	case 19942ULL: goto x86_l_4de6;
	case 19947ULL: goto x86_l_4deb;
	case 19950ULL: goto x86_l_4dee;
	case 19956ULL: goto x86_l_4df4;
	case 19960ULL: goto x86_l_4df8;
	case 19965ULL: goto x86_l_4dfd;
	case 19971ULL: goto x86_l_4e03;
	case 19976ULL: goto x86_l_4e08;
	case 19980ULL: goto x86_l_4e0c;
	case 19984ULL: goto x86_l_4e10;
	case 19989ULL: goto x86_l_4e15;
	case 19994ULL: goto x86_l_4e1a;
	case 19996ULL: goto x86_l_4e1c;
	case 20001ULL: goto x86_l_4e21;
	case 20005ULL: goto x86_l_4e25;
	case 20008ULL: goto x86_l_4e28;
	case 20013ULL: goto x86_l_4e2d;
	case 20015ULL: goto x86_l_4e2f;
	case 20020ULL: goto x86_l_4e34;
	case 20024ULL: goto x86_l_4e38;
	case 20029ULL: goto x86_l_4e3d;
	case 20034ULL: goto x86_l_4e42;
	case 20036ULL: goto x86_l_4e44;
	case 20040ULL: goto x86_l_4e48;
	case 20044ULL: goto x86_l_4e4c;
	case 20049ULL: goto x86_l_4e51;
	case 20054ULL: goto x86_l_4e56;
	case 20059ULL: goto x86_l_4e5b;
	case 20062ULL: goto x86_l_4e5e;
	case 20064ULL: goto x86_l_4e60;
	case 20069ULL: goto x86_l_4e65;
	case 20074ULL: goto x86_l_4e6a;
	case 20078ULL: goto x86_l_4e6e;
	case 20083ULL: goto x86_l_4e73;
	case 20088ULL: goto x86_l_4e78;
	case 20093ULL: goto x86_l_4e7d;
	case 20095ULL: goto x86_l_4e7f;
	case 20100ULL: goto x86_l_4e84;
	case 20103ULL: goto x86_l_4e87;
	case 20109ULL: goto x86_l_4e8d;
	case 20114ULL: goto x86_l_4e92;
	case 20117ULL: goto x86_l_4e95;
	case 20123ULL: goto x86_l_4e9b;
	case 20127ULL: goto x86_l_4e9f;
	case 20132ULL: goto x86_l_4ea4;
	case 20137ULL: goto x86_l_4ea9;
	case 20142ULL: goto x86_l_4eae;
	case 20144ULL: goto x86_l_4eb0;
	case 20148ULL: goto x86_l_4eb4;
	case 20150ULL: goto x86_l_4eb6;
	case 20156ULL: goto x86_l_4ebc;
	case 20159ULL: goto x86_l_4ebf;
	case 20161ULL: goto x86_l_4ec1;
	case 20167ULL: goto x86_l_4ec7;
	case 20172ULL: goto x86_l_4ecc;
	case 20178ULL: goto x86_l_4ed2;
	case 20181ULL: goto x86_l_4ed5;
	case 20186ULL: goto x86_l_4eda;
	case 20188ULL: goto x86_l_4edc;
	case 20191ULL: goto x86_l_4edf;
	case 20197ULL: goto x86_l_4ee5;
	case 20201ULL: goto x86_l_4ee9;
	case 20207ULL: goto x86_l_4eef;
	case 20211ULL: goto x86_l_4ef3;
	case 20214ULL: goto x86_l_4ef6;
	case 20219ULL: goto x86_l_4efb;
	case 20224ULL: goto x86_l_4f00;
	case 20227ULL: goto x86_l_4f03;
	case 20233ULL: goto x86_l_4f09;
	case 20237ULL: goto x86_l_4f0d;
	case 20242ULL: goto x86_l_4f12;
	case 20248ULL: goto x86_l_4f18;
	case 20253ULL: goto x86_l_4f1d;
	case 20257ULL: goto x86_l_4f21;
	case 20261ULL: goto x86_l_4f25;
	case 20266ULL: goto x86_l_4f2a;
	case 20271ULL: goto x86_l_4f2f;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	case 20282ULL: goto x86_l_4f3a;
	case 20285ULL: goto x86_l_4f3d;
	case 20290ULL: goto x86_l_4f42;
	case 20292ULL: goto x86_l_4f44;
	case 20297ULL: goto x86_l_4f49;
	case 20301ULL: goto x86_l_4f4d;
	case 20306ULL: goto x86_l_4f52;
	case 20311ULL: goto x86_l_4f57;
	case 20313ULL: goto x86_l_4f59;
	case 20317ULL: goto x86_l_4f5d;
	case 20321ULL: goto x86_l_4f61;
	case 20326ULL: goto x86_l_4f66;
	case 20331ULL: goto x86_l_4f6b;
	case 20336ULL: goto x86_l_4f70;
	case 20339ULL: goto x86_l_4f73;
	case 20341ULL: goto x86_l_4f75;
	case 20346ULL: goto x86_l_4f7a;
	case 20351ULL: goto x86_l_4f7f;
	case 20355ULL: goto x86_l_4f83;
	case 20360ULL: goto x86_l_4f88;
	case 20365ULL: goto x86_l_4f8d;
	case 20370ULL: goto x86_l_4f92;
	case 20372ULL: goto x86_l_4f94;
	case 20377ULL: goto x86_l_4f99;
	case 20380ULL: goto x86_l_4f9c;
	case 20386ULL: goto x86_l_4fa2;
	case 20391ULL: goto x86_l_4fa7;
	case 20394ULL: goto x86_l_4faa;
	case 20400ULL: goto x86_l_4fb0;
	case 20404ULL: goto x86_l_4fb4;
	case 20409ULL: goto x86_l_4fb9;
	case 20414ULL: goto x86_l_4fbe;
	case 20419ULL: goto x86_l_4fc3;
	case 20421ULL: goto x86_l_4fc5;
	case 20425ULL: goto x86_l_4fc9;
	case 20427ULL: goto x86_l_4fcb;
	case 20433ULL: goto x86_l_4fd1;
	case 20436ULL: goto x86_l_4fd4;
	case 20438ULL: goto x86_l_4fd6;
	case 20444ULL: goto x86_l_4fdc;
	case 20449ULL: goto x86_l_4fe1;
	case 20455ULL: goto x86_l_4fe7;
	case 20458ULL: goto x86_l_4fea;
	case 20463ULL: goto x86_l_4fef;
	case 20465ULL: goto x86_l_4ff1;
	case 20468ULL: goto x86_l_4ff4;
	case 20474ULL: goto x86_l_4ffa;
	case 20478ULL: goto x86_l_4ffe;
	case 20484ULL: goto x86_l_5004;
	case 20488ULL: goto x86_l_5008;
	case 20491ULL: goto x86_l_500b;
	case 20496ULL: goto x86_l_5010;
	case 20501ULL: goto x86_l_5015;
	case 20504ULL: goto x86_l_5018;
	case 20510ULL: goto x86_l_501e;
	case 20514ULL: goto x86_l_5022;
	case 20519ULL: goto x86_l_5027;
	case 20525ULL: goto x86_l_502d;
	case 20530ULL: goto x86_l_5032;
	case 20534ULL: goto x86_l_5036;
	case 20538ULL: goto x86_l_503a;
	case 20543ULL: goto x86_l_503f;
	case 20548ULL: goto x86_l_5044;
	case 20550ULL: goto x86_l_5046;
	case 20555ULL: goto x86_l_504b;
	case 20559ULL: goto x86_l_504f;
	case 20562ULL: goto x86_l_5052;
	case 20567ULL: goto x86_l_5057;
	case 20569ULL: goto x86_l_5059;
	case 20574ULL: goto x86_l_505e;
	case 20578ULL: goto x86_l_5062;
	case 20583ULL: goto x86_l_5067;
	case 20588ULL: goto x86_l_506c;
	case 20590ULL: goto x86_l_506e;
	case 20594ULL: goto x86_l_5072;
	case 20598ULL: goto x86_l_5076;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20613ULL: goto x86_l_5085;
	case 20616ULL: goto x86_l_5088;
	case 20618ULL: goto x86_l_508a;
	case 20623ULL: goto x86_l_508f;
	case 20628ULL: goto x86_l_5094;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20642ULL: goto x86_l_50a2;
	case 20647ULL: goto x86_l_50a7;
	case 20649ULL: goto x86_l_50a9;
	case 20654ULL: goto x86_l_50ae;
	case 20657ULL: goto x86_l_50b1;
	case 20663ULL: goto x86_l_50b7;
	case 20668ULL: goto x86_l_50bc;
	case 20671ULL: goto x86_l_50bf;
	case 20677ULL: goto x86_l_50c5;
	case 20681ULL: goto x86_l_50c9;
	case 20686ULL: goto x86_l_50ce;
	case 20691ULL: goto x86_l_50d3;
	case 20696ULL: goto x86_l_50d8;
	case 20698ULL: goto x86_l_50da;
	case 20702ULL: goto x86_l_50de;
	case 20704ULL: goto x86_l_50e0;
	case 20710ULL: goto x86_l_50e6;
	case 20713ULL: goto x86_l_50e9;
	case 20715ULL: goto x86_l_50eb;
	case 20721ULL: goto x86_l_50f1;
	case 20726ULL: goto x86_l_50f6;
	case 20732ULL: goto x86_l_50fc;
	case 20735ULL: goto x86_l_50ff;
	case 20740ULL: goto x86_l_5104;
	case 20742ULL: goto x86_l_5106;
	case 20745ULL: goto x86_l_5109;
	case 20751ULL: goto x86_l_510f;
	case 20755ULL: goto x86_l_5113;
	case 20761ULL: goto x86_l_5119;
	case 20765ULL: goto x86_l_511d;
	case 20768ULL: goto x86_l_5120;
	case 20773ULL: goto x86_l_5125;
	case 20778ULL: goto x86_l_512a;
	case 20781ULL: goto x86_l_512d;
	case 20787ULL: goto x86_l_5133;
	case 20791ULL: goto x86_l_5137;
	case 20796ULL: goto x86_l_513c;
	case 20802ULL: goto x86_l_5142;
	case 20807ULL: goto x86_l_5147;
	case 20811ULL: goto x86_l_514b;
	case 20815ULL: goto x86_l_514f;
	case 20820ULL: goto x86_l_5154;
	case 20825ULL: goto x86_l_5159;
	case 20827ULL: goto x86_l_515b;
	case 20832ULL: goto x86_l_5160;
	case 20836ULL: goto x86_l_5164;
	case 20839ULL: goto x86_l_5167;
	case 20844ULL: goto x86_l_516c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4b09:
	/* 0x4b09: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b0d:
	/* 0x4b0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b12:
	/* 0x4b12: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b17:
	/* 0x4b17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1c:
	/* 0x4b1c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4b1f:
	/* 0x4b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b21:
	/* 0x4b21: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b26:
	/* 0x4b26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b2b:
	/* 0x4b2b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b2f:
	/* 0x4b2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b34:
	/* 0x4b34: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b39:
	/* 0x4b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b3e:
	/* 0x4b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b40:
	/* 0x4b40: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b45:
	/* 0x4b45: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4b48:
	/* 0x4b48: je     4cd6 <trace_security_file_mprotect+0x4cd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cd6;
	}
x86_l_4b4e:
	/* 0x4b4e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b53:
	/* 0x4b53: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4b56:
	/* 0x4b56: je     4cd6 <trace_security_file_mprotect+0x4cd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cd6;
	}
x86_l_4b5c:
	/* 0x4b5c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b60:
	/* 0x4b60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b65:
	/* 0x4b65: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b6a:
	/* 0x4b6a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4b6f:
	/* 0x4b6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b71:
	/* 0x4b71: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b75:
	/* 0x4b75: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4b77:
	/* 0x4b77: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4b7d:
	/* 0x4b7d: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4b80:
	/* 0x4b80: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4b82:
	/* 0x4b82: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_4b88:
	/* 0x4b88: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b8d:
	/* 0x4b8d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4b93:
	/* 0x4b93: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4b96:
	/* 0x4b96: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4b9b:
	/* 0x4b9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9d:
	/* 0x4b9d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ba0:
	/* 0x4ba0: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_4ba6:
	/* 0x4ba6: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4baa:
	/* 0x4baa: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4bb0:
	/* 0x4bb0: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4bb4:
	/* 0x4bb4: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4bb7:
	/* 0x4bb7: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bbc:
	/* 0x4bbc: jmp    4d37 <trace_security_file_mprotect+0x4d37> */
	goto x86_l_4d37;
x86_l_4bc1:
	/* 0x4bc1: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4bc4:
	/* 0x4bc4: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_4bca:
	/* 0x4bca: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bce:
	/* 0x4bce: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4bd3:
	/* 0x4bd3: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_4bd9:
	/* 0x4bd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bde:
	/* 0x4bde: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4be2:
	/* 0x4be2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4be6:
	/* 0x4be6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4beb:
	/* 0x4beb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bf0:
	/* 0x4bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf2:
	/* 0x4bf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bf7:
	/* 0x4bf7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bfb:
	/* 0x4bfb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4bfe:
	/* 0x4bfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c03:
	/* 0x4c03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c05:
	/* 0x4c05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c0a:
	/* 0x4c0a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c0e:
	/* 0x4c0e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c13:
	/* 0x4c13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c18:
	/* 0x4c18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c1a:
	/* 0x4c1a: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c1e:
	/* 0x4c1e: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c22:
	/* 0x4c22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c27:
	/* 0x4c27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c2c:
	/* 0x4c2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c31:
	/* 0x4c31: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4c34:
	/* 0x4c34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c36:
	/* 0x4c36: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c3b:
	/* 0x4c3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c40:
	/* 0x4c40: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c44:
	/* 0x4c44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c49:
	/* 0x4c49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c4e:
	/* 0x4c4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c53:
	/* 0x4c53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c55:
	/* 0x4c55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5a:
	/* 0x4c5a: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4c5d:
	/* 0x4c5d: je     4deb <trace_security_file_mprotect+0x4deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4deb;
	}
x86_l_4c63:
	/* 0x4c63: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c68:
	/* 0x4c68: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4c6b:
	/* 0x4c6b: je     4deb <trace_security_file_mprotect+0x4deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4deb;
	}
x86_l_4c71:
	/* 0x4c71: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c75:
	/* 0x4c75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c7a:
	/* 0x4c7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c7f:
	/* 0x4c7f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4c84:
	/* 0x4c84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c86:
	/* 0x4c86: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4c8a:
	/* 0x4c8a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c8c:
	/* 0x4c8c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c92:
	/* 0x4c92: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4c95:
	/* 0x4c95: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c97:
	/* 0x4c97: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_4c9d:
	/* 0x4c9d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ca2:
	/* 0x4ca2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4ca8:
	/* 0x4ca8: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4cab:
	/* 0x4cab: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4cb0:
	/* 0x4cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb2:
	/* 0x4cb2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4cb5:
	/* 0x4cb5: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_4cbb:
	/* 0x4cbb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4cbf:
	/* 0x4cbf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4cc5:
	/* 0x4cc5: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4cc9:
	/* 0x4cc9: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ccc:
	/* 0x4ccc: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd1:
	/* 0x4cd1: jmp    4e4c <trace_security_file_mprotect+0x4e4c> */
	goto x86_l_4e4c;
x86_l_4cd6:
	/* 0x4cd6: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4cd9:
	/* 0x4cd9: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_4cdf:
	/* 0x4cdf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce3:
	/* 0x4ce3: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4ce8:
	/* 0x4ce8: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_4cee:
	/* 0x4cee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cf3:
	/* 0x4cf3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cf7:
	/* 0x4cf7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4cfb:
	/* 0x4cfb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d00:
	/* 0x4d00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d05:
	/* 0x4d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d07:
	/* 0x4d07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d0c:
	/* 0x4d0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d10:
	/* 0x4d10: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d13:
	/* 0x4d13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d18:
	/* 0x4d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d1a:
	/* 0x4d1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d1f:
	/* 0x4d1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d23:
	/* 0x4d23: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d28:
	/* 0x4d28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d2d:
	/* 0x4d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d2f:
	/* 0x4d2f: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d33:
	/* 0x4d33: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d37:
	/* 0x4d37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d3c:
	/* 0x4d3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d41:
	/* 0x4d41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d46:
	/* 0x4d46: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4d49:
	/* 0x4d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d4b:
	/* 0x4d4b: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d50:
	/* 0x4d50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d55:
	/* 0x4d55: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d59:
	/* 0x4d59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d5e:
	/* 0x4d5e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d63:
	/* 0x4d63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d68:
	/* 0x4d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d6a:
	/* 0x4d6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d6f:
	/* 0x4d6f: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4d72:
	/* 0x4d72: je     4f00 <trace_security_file_mprotect+0x4f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f00;
	}
x86_l_4d78:
	/* 0x4d78: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d7d:
	/* 0x4d7d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4d80:
	/* 0x4d80: je     4f00 <trace_security_file_mprotect+0x4f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f00;
	}
x86_l_4d86:
	/* 0x4d86: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d8a:
	/* 0x4d8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d8f:
	/* 0x4d8f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d94:
	/* 0x4d94: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4d99:
	/* 0x4d99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d9b:
	/* 0x4d9b: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4d9f:
	/* 0x4d9f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4da1:
	/* 0x4da1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4da7:
	/* 0x4da7: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4daa:
	/* 0x4daa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4dac:
	/* 0x4dac: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_4db2:
	/* 0x4db2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4db7:
	/* 0x4db7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4dbd:
	/* 0x4dbd: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dc0:
	/* 0x4dc0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4dc5:
	/* 0x4dc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc7:
	/* 0x4dc7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4dca:
	/* 0x4dca: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_4dd0:
	/* 0x4dd0: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4dd4:
	/* 0x4dd4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4dda:
	/* 0x4dda: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4dde:
	/* 0x4dde: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4de1:
	/* 0x4de1: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de6:
	/* 0x4de6: jmp    4f61 <trace_security_file_mprotect+0x4f61> */
	goto x86_l_4f61;
x86_l_4deb:
	/* 0x4deb: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4dee:
	/* 0x4dee: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_4df4:
	/* 0x4df4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df8:
	/* 0x4df8: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4dfd:
	/* 0x4dfd: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_4e03:
	/* 0x4e03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e08:
	/* 0x4e08: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e0c:
	/* 0x4e0c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e10:
	/* 0x4e10: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e15:
	/* 0x4e15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e1a:
	/* 0x4e1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1c:
	/* 0x4e1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e21:
	/* 0x4e21: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e25:
	/* 0x4e25: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e28:
	/* 0x4e28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e2d:
	/* 0x4e2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2f:
	/* 0x4e2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e34:
	/* 0x4e34: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e38:
	/* 0x4e38: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e3d:
	/* 0x4e3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e42:
	/* 0x4e42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e44:
	/* 0x4e44: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e48:
	/* 0x4e48: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e4c:
	/* 0x4e4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e51:
	/* 0x4e51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e56:
	/* 0x4e56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e5b:
	/* 0x4e5b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4e5e:
	/* 0x4e5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e60:
	/* 0x4e60: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e65:
	/* 0x4e65: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e6a:
	/* 0x4e6a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e6e:
	/* 0x4e6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e73:
	/* 0x4e73: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e78:
	/* 0x4e78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e7d:
	/* 0x4e7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e7f:
	/* 0x4e7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e84:
	/* 0x4e84: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4e87:
	/* 0x4e87: je     5015 <trace_security_file_mprotect+0x5015> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5015;
	}
x86_l_4e8d:
	/* 0x4e8d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e92:
	/* 0x4e92: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4e95:
	/* 0x4e95: je     5015 <trace_security_file_mprotect+0x5015> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5015;
	}
x86_l_4e9b:
	/* 0x4e9b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e9f:
	/* 0x4e9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ea4:
	/* 0x4ea4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ea9:
	/* 0x4ea9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4eae:
	/* 0x4eae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb0:
	/* 0x4eb0: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4eb4:
	/* 0x4eb4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4eb6:
	/* 0x4eb6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ebc:
	/* 0x4ebc: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4ebf:
	/* 0x4ebf: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ec1:
	/* 0x4ec1: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_4ec7:
	/* 0x4ec7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ecc:
	/* 0x4ecc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4ed2:
	/* 0x4ed2: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ed5:
	/* 0x4ed5: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4eda:
	/* 0x4eda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4edc:
	/* 0x4edc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4edf:
	/* 0x4edf: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_4ee5:
	/* 0x4ee5: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ee9:
	/* 0x4ee9: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4eef:
	/* 0x4eef: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4ef3:
	/* 0x4ef3: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ef6:
	/* 0x4ef6: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4efb:
	/* 0x4efb: jmp    5076 <trace_security_file_mprotect+0x5076> */
	goto x86_l_5076;
x86_l_4f00:
	/* 0x4f00: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4f03:
	/* 0x4f03: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_4f09:
	/* 0x4f09: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f0d:
	/* 0x4f0d: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_4f12:
	/* 0x4f12: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_4f18:
	/* 0x4f18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f1d:
	/* 0x4f1d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f21:
	/* 0x4f21: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f25:
	/* 0x4f25: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f2a:
	/* 0x4f2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f2f:
	/* 0x4f2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f31:
	/* 0x4f31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f36:
	/* 0x4f36: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f3a:
	/* 0x4f3a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f3d:
	/* 0x4f3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f42:
	/* 0x4f42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f44:
	/* 0x4f44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f49:
	/* 0x4f49: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f4d:
	/* 0x4f4d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f52:
	/* 0x4f52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f57:
	/* 0x4f57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f59:
	/* 0x4f59: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f5d:
	/* 0x4f5d: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f61:
	/* 0x4f61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f66:
	/* 0x4f66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f6b:
	/* 0x4f6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f70:
	/* 0x4f70: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4f73:
	/* 0x4f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f75:
	/* 0x4f75: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f7f:
	/* 0x4f7f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f83:
	/* 0x4f83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f88:
	/* 0x4f88: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f8d:
	/* 0x4f8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f92:
	/* 0x4f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f94:
	/* 0x4f94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f99:
	/* 0x4f99: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4f9c:
	/* 0x4f9c: je     512a <trace_security_file_mprotect+0x512a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_512a;
	}
x86_l_4fa2:
	/* 0x4fa2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fa7:
	/* 0x4fa7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4faa:
	/* 0x4faa: je     512a <trace_security_file_mprotect+0x512a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_512a;
	}
x86_l_4fb0:
	/* 0x4fb0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4fb4:
	/* 0x4fb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fb9:
	/* 0x4fb9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fbe:
	/* 0x4fbe: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4fc3:
	/* 0x4fc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fc5:
	/* 0x4fc5: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4fc9:
	/* 0x4fc9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4fcb:
	/* 0x4fcb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fd1:
	/* 0x4fd1: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4fd4:
	/* 0x4fd4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4fd6:
	/* 0x4fd6: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_4fdc:
	/* 0x4fdc: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fe1:
	/* 0x4fe1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4fe7:
	/* 0x4fe7: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fea:
	/* 0x4fea: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4fef:
	/* 0x4fef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff1:
	/* 0x4ff1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ff4:
	/* 0x4ff4: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_4ffa:
	/* 0x4ffa: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ffe:
	/* 0x4ffe: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5004:
	/* 0x5004: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5008:
	/* 0x5008: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_500b:
	/* 0x500b: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5010:
	/* 0x5010: jmp    518b <trace_security_file_mprotect+0x518b> */
	return 20875ULL;
x86_l_5015:
	/* 0x5015: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5018:
	/* 0x5018: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_501e:
	/* 0x501e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5022:
	/* 0x5022: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5027:
	/* 0x5027: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_502d:
	/* 0x502d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5032:
	/* 0x5032: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5036:
	/* 0x5036: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_503a:
	/* 0x503a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_503f:
	/* 0x503f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5044:
	/* 0x5044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5046:
	/* 0x5046: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_504b:
	/* 0x504b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_504f:
	/* 0x504f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5052:
	/* 0x5052: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5057:
	/* 0x5057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5059:
	/* 0x5059: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_505e:
	/* 0x505e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5062:
	/* 0x5062: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5067:
	/* 0x5067: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_506c:
	/* 0x506c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506e:
	/* 0x506e: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5072:
	/* 0x5072: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5076:
	/* 0x5076: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_507b:
	/* 0x507b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5080:
	/* 0x5080: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5085:
	/* 0x5085: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5088:
	/* 0x5088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508a:
	/* 0x508a: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_508f:
	/* 0x508f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5094:
	/* 0x5094: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5098:
	/* 0x5098: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_509d:
	/* 0x509d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50a2:
	/* 0x50a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50a7:
	/* 0x50a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50a9:
	/* 0x50a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50ae:
	/* 0x50ae: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_50b1:
	/* 0x50b1: je     523f <trace_security_file_mprotect+0x523f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21055ULL;
	}
x86_l_50b7:
	/* 0x50b7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50bc:
	/* 0x50bc: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_50bf:
	/* 0x50bf: je     523f <trace_security_file_mprotect+0x523f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21055ULL;
	}
x86_l_50c5:
	/* 0x50c5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50c9:
	/* 0x50c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50ce:
	/* 0x50ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50d3:
	/* 0x50d3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_50d8:
	/* 0x50d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50da:
	/* 0x50da: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_50de:
	/* 0x50de: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_50e0:
	/* 0x50e0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50e6:
	/* 0x50e6: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_50e9:
	/* 0x50e9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_50eb:
	/* 0x50eb: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_50f1:
	/* 0x50f1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50f6:
	/* 0x50f6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_50fc:
	/* 0x50fc: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50ff:
	/* 0x50ff: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5104:
	/* 0x5104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5106:
	/* 0x5106: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5109:
	/* 0x5109: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_510f:
	/* 0x510f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5113:
	/* 0x5113: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5119:
	/* 0x5119: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_511d:
	/* 0x511d: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5120:
	/* 0x5120: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5125:
	/* 0x5125: jmp    52a0 <trace_security_file_mprotect+0x52a0> */
	return 21152ULL;
x86_l_512a:
	/* 0x512a: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_512d:
	/* 0x512d: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_5133:
	/* 0x5133: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5137:
	/* 0x5137: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_513c:
	/* 0x513c: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_5142:
	/* 0x5142: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5147:
	/* 0x5147: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_514b:
	/* 0x514b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_514f:
	/* 0x514f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5154:
	/* 0x5154: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5159:
	/* 0x5159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_515b:
	/* 0x515b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5160:
	/* 0x5160: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5164:
	/* 0x5164: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5167:
	/* 0x5167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_516c:
	/* 0x516c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 20846ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20846ULL: goto x86_l_516e;
	case 20851ULL: goto x86_l_5173;
	case 20855ULL: goto x86_l_5177;
	case 20860ULL: goto x86_l_517c;
	case 20865ULL: goto x86_l_5181;
	case 20867ULL: goto x86_l_5183;
	case 20871ULL: goto x86_l_5187;
	case 20875ULL: goto x86_l_518b;
	case 20880ULL: goto x86_l_5190;
	case 20885ULL: goto x86_l_5195;
	case 20890ULL: goto x86_l_519a;
	case 20893ULL: goto x86_l_519d;
	case 20895ULL: goto x86_l_519f;
	case 20900ULL: goto x86_l_51a4;
	case 20905ULL: goto x86_l_51a9;
	case 20909ULL: goto x86_l_51ad;
	case 20914ULL: goto x86_l_51b2;
	case 20919ULL: goto x86_l_51b7;
	case 20924ULL: goto x86_l_51bc;
	case 20926ULL: goto x86_l_51be;
	case 20931ULL: goto x86_l_51c3;
	case 20934ULL: goto x86_l_51c6;
	case 20940ULL: goto x86_l_51cc;
	case 20945ULL: goto x86_l_51d1;
	case 20948ULL: goto x86_l_51d4;
	case 20954ULL: goto x86_l_51da;
	case 20958ULL: goto x86_l_51de;
	case 20963ULL: goto x86_l_51e3;
	case 20968ULL: goto x86_l_51e8;
	case 20973ULL: goto x86_l_51ed;
	case 20975ULL: goto x86_l_51ef;
	case 20979ULL: goto x86_l_51f3;
	case 20981ULL: goto x86_l_51f5;
	case 20987ULL: goto x86_l_51fb;
	case 20990ULL: goto x86_l_51fe;
	case 20992ULL: goto x86_l_5200;
	case 20998ULL: goto x86_l_5206;
	case 21003ULL: goto x86_l_520b;
	case 21009ULL: goto x86_l_5211;
	case 21012ULL: goto x86_l_5214;
	case 21017ULL: goto x86_l_5219;
	case 21019ULL: goto x86_l_521b;
	case 21022ULL: goto x86_l_521e;
	case 21028ULL: goto x86_l_5224;
	case 21032ULL: goto x86_l_5228;
	case 21038ULL: goto x86_l_522e;
	case 21042ULL: goto x86_l_5232;
	case 21045ULL: goto x86_l_5235;
	case 21050ULL: goto x86_l_523a;
	case 21055ULL: goto x86_l_523f;
	case 21058ULL: goto x86_l_5242;
	case 21064ULL: goto x86_l_5248;
	case 21068ULL: goto x86_l_524c;
	case 21073ULL: goto x86_l_5251;
	case 21079ULL: goto x86_l_5257;
	case 21084ULL: goto x86_l_525c;
	case 21088ULL: goto x86_l_5260;
	case 21092ULL: goto x86_l_5264;
	case 21097ULL: goto x86_l_5269;
	case 21102ULL: goto x86_l_526e;
	case 21104ULL: goto x86_l_5270;
	case 21109ULL: goto x86_l_5275;
	case 21113ULL: goto x86_l_5279;
	case 21116ULL: goto x86_l_527c;
	case 21121ULL: goto x86_l_5281;
	case 21123ULL: goto x86_l_5283;
	case 21128ULL: goto x86_l_5288;
	case 21132ULL: goto x86_l_528c;
	case 21137ULL: goto x86_l_5291;
	case 21142ULL: goto x86_l_5296;
	case 21144ULL: goto x86_l_5298;
	case 21148ULL: goto x86_l_529c;
	case 21152ULL: goto x86_l_52a0;
	case 21157ULL: goto x86_l_52a5;
	case 21162ULL: goto x86_l_52aa;
	case 21167ULL: goto x86_l_52af;
	case 21170ULL: goto x86_l_52b2;
	case 21172ULL: goto x86_l_52b4;
	case 21177ULL: goto x86_l_52b9;
	case 21182ULL: goto x86_l_52be;
	case 21186ULL: goto x86_l_52c2;
	case 21191ULL: goto x86_l_52c7;
	case 21196ULL: goto x86_l_52cc;
	case 21201ULL: goto x86_l_52d1;
	case 21203ULL: goto x86_l_52d3;
	case 21208ULL: goto x86_l_52d8;
	case 21211ULL: goto x86_l_52db;
	case 21217ULL: goto x86_l_52e1;
	case 21222ULL: goto x86_l_52e6;
	case 21225ULL: goto x86_l_52e9;
	case 21231ULL: goto x86_l_52ef;
	case 21235ULL: goto x86_l_52f3;
	case 21240ULL: goto x86_l_52f8;
	case 21245ULL: goto x86_l_52fd;
	case 21250ULL: goto x86_l_5302;
	case 21252ULL: goto x86_l_5304;
	case 21256ULL: goto x86_l_5308;
	case 21258ULL: goto x86_l_530a;
	case 21264ULL: goto x86_l_5310;
	case 21267ULL: goto x86_l_5313;
	case 21269ULL: goto x86_l_5315;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21286ULL: goto x86_l_5326;
	case 21289ULL: goto x86_l_5329;
	case 21294ULL: goto x86_l_532e;
	case 21296ULL: goto x86_l_5330;
	case 21299ULL: goto x86_l_5333;
	case 21305ULL: goto x86_l_5339;
	case 21309ULL: goto x86_l_533d;
	case 21315ULL: goto x86_l_5343;
	case 21319ULL: goto x86_l_5347;
	case 21322ULL: goto x86_l_534a;
	case 21327ULL: goto x86_l_534f;
	case 21332ULL: goto x86_l_5354;
	case 21335ULL: goto x86_l_5357;
	case 21341ULL: goto x86_l_535d;
	case 21345ULL: goto x86_l_5361;
	case 21350ULL: goto x86_l_5366;
	case 21356ULL: goto x86_l_536c;
	case 21361ULL: goto x86_l_5371;
	case 21365ULL: goto x86_l_5375;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21381ULL: goto x86_l_5385;
	case 21386ULL: goto x86_l_538a;
	case 21390ULL: goto x86_l_538e;
	case 21393ULL: goto x86_l_5391;
	case 21398ULL: goto x86_l_5396;
	case 21400ULL: goto x86_l_5398;
	case 21405ULL: goto x86_l_539d;
	case 21409ULL: goto x86_l_53a1;
	case 21414ULL: goto x86_l_53a6;
	case 21419ULL: goto x86_l_53ab;
	case 21421ULL: goto x86_l_53ad;
	case 21425ULL: goto x86_l_53b1;
	case 21429ULL: goto x86_l_53b5;
	case 21434ULL: goto x86_l_53ba;
	case 21439ULL: goto x86_l_53bf;
	case 21444ULL: goto x86_l_53c4;
	case 21447ULL: goto x86_l_53c7;
	case 21449ULL: goto x86_l_53c9;
	case 21454ULL: goto x86_l_53ce;
	case 21459ULL: goto x86_l_53d3;
	case 21463ULL: goto x86_l_53d7;
	case 21468ULL: goto x86_l_53dc;
	case 21473ULL: goto x86_l_53e1;
	case 21478ULL: goto x86_l_53e6;
	case 21480ULL: goto x86_l_53e8;
	case 21485ULL: goto x86_l_53ed;
	case 21488ULL: goto x86_l_53f0;
	case 21494ULL: goto x86_l_53f6;
	case 21499ULL: goto x86_l_53fb;
	case 21502ULL: goto x86_l_53fe;
	case 21508ULL: goto x86_l_5404;
	case 21512ULL: goto x86_l_5408;
	case 21517ULL: goto x86_l_540d;
	case 21522ULL: goto x86_l_5412;
	case 21527ULL: goto x86_l_5417;
	case 21529ULL: goto x86_l_5419;
	case 21533ULL: goto x86_l_541d;
	case 21535ULL: goto x86_l_541f;
	case 21541ULL: goto x86_l_5425;
	case 21544ULL: goto x86_l_5428;
	case 21546ULL: goto x86_l_542a;
	case 21552ULL: goto x86_l_5430;
	case 21557ULL: goto x86_l_5435;
	case 21563ULL: goto x86_l_543b;
	case 21566ULL: goto x86_l_543e;
	case 21571ULL: goto x86_l_5443;
	case 21573ULL: goto x86_l_5445;
	case 21576ULL: goto x86_l_5448;
	case 21582ULL: goto x86_l_544e;
	case 21586ULL: goto x86_l_5452;
	case 21592ULL: goto x86_l_5458;
	case 21596ULL: goto x86_l_545c;
	case 21599ULL: goto x86_l_545f;
	case 21604ULL: goto x86_l_5464;
	case 21609ULL: goto x86_l_5469;
	case 21612ULL: goto x86_l_546c;
	case 21618ULL: goto x86_l_5472;
	case 21622ULL: goto x86_l_5476;
	case 21627ULL: goto x86_l_547b;
	case 21633ULL: goto x86_l_5481;
	case 21638ULL: goto x86_l_5486;
	case 21642ULL: goto x86_l_548a;
	case 21646ULL: goto x86_l_548e;
	case 21651ULL: goto x86_l_5493;
	case 21656ULL: goto x86_l_5498;
	case 21658ULL: goto x86_l_549a;
	case 21663ULL: goto x86_l_549f;
	case 21667ULL: goto x86_l_54a3;
	case 21670ULL: goto x86_l_54a6;
	case 21675ULL: goto x86_l_54ab;
	case 21677ULL: goto x86_l_54ad;
	case 21682ULL: goto x86_l_54b2;
	case 21686ULL: goto x86_l_54b6;
	case 21691ULL: goto x86_l_54bb;
	case 21696ULL: goto x86_l_54c0;
	case 21698ULL: goto x86_l_54c2;
	case 21702ULL: goto x86_l_54c6;
	case 21706ULL: goto x86_l_54ca;
	case 21711ULL: goto x86_l_54cf;
	case 21716ULL: goto x86_l_54d4;
	case 21721ULL: goto x86_l_54d9;
	case 21724ULL: goto x86_l_54dc;
	case 21726ULL: goto x86_l_54de;
	case 21731ULL: goto x86_l_54e3;
	case 21736ULL: goto x86_l_54e8;
	case 21740ULL: goto x86_l_54ec;
	case 21745ULL: goto x86_l_54f1;
	case 21750ULL: goto x86_l_54f6;
	case 21755ULL: goto x86_l_54fb;
	case 21757ULL: goto x86_l_54fd;
	case 21762ULL: goto x86_l_5502;
	case 21765ULL: goto x86_l_5505;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21779ULL: goto x86_l_5513;
	case 21785ULL: goto x86_l_5519;
	case 21789ULL: goto x86_l_551d;
	case 21794ULL: goto x86_l_5522;
	case 21799ULL: goto x86_l_5527;
	case 21804ULL: goto x86_l_552c;
	case 21806ULL: goto x86_l_552e;
	case 21810ULL: goto x86_l_5532;
	case 21812ULL: goto x86_l_5534;
	case 21818ULL: goto x86_l_553a;
	case 21821ULL: goto x86_l_553d;
	case 21823ULL: goto x86_l_553f;
	case 21829ULL: goto x86_l_5545;
	case 21834ULL: goto x86_l_554a;
	case 21840ULL: goto x86_l_5550;
	case 21843ULL: goto x86_l_5553;
	case 21848ULL: goto x86_l_5558;
	case 21850ULL: goto x86_l_555a;
	case 21853ULL: goto x86_l_555d;
	case 21859ULL: goto x86_l_5563;
	case 21863ULL: goto x86_l_5567;
	case 21869ULL: goto x86_l_556d;
	case 21873ULL: goto x86_l_5571;
	case 21876ULL: goto x86_l_5574;
	case 21881ULL: goto x86_l_5579;
	case 21886ULL: goto x86_l_557e;
	case 21889ULL: goto x86_l_5581;
	case 21895ULL: goto x86_l_5587;
	case 21899ULL: goto x86_l_558b;
	case 21904ULL: goto x86_l_5590;
	case 21910ULL: goto x86_l_5596;
	case 21915ULL: goto x86_l_559b;
	case 21919ULL: goto x86_l_559f;
	case 21923ULL: goto x86_l_55a3;
	case 21928ULL: goto x86_l_55a8;
	case 21933ULL: goto x86_l_55ad;
	case 21935ULL: goto x86_l_55af;
	case 21940ULL: goto x86_l_55b4;
	case 21944ULL: goto x86_l_55b8;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21954ULL: goto x86_l_55c2;
	case 21959ULL: goto x86_l_55c7;
	case 21963ULL: goto x86_l_55cb;
	case 21968ULL: goto x86_l_55d0;
	case 21973ULL: goto x86_l_55d5;
	case 21975ULL: goto x86_l_55d7;
	case 21979ULL: goto x86_l_55db;
	case 21983ULL: goto x86_l_55df;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22001ULL: goto x86_l_55f1;
	case 22003ULL: goto x86_l_55f3;
	case 22008ULL: goto x86_l_55f8;
	case 22013ULL: goto x86_l_55fd;
	case 22017ULL: goto x86_l_5601;
	case 22022ULL: goto x86_l_5606;
	case 22027ULL: goto x86_l_560b;
	case 22032ULL: goto x86_l_5610;
	case 22034ULL: goto x86_l_5612;
	case 22039ULL: goto x86_l_5617;
	case 22042ULL: goto x86_l_561a;
	case 22048ULL: goto x86_l_5620;
	case 22053ULL: goto x86_l_5625;
	case 22056ULL: goto x86_l_5628;
	case 22062ULL: goto x86_l_562e;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22076ULL: goto x86_l_563c;
	case 22081ULL: goto x86_l_5641;
	case 22083ULL: goto x86_l_5643;
	case 22087ULL: goto x86_l_5647;
	case 22089ULL: goto x86_l_5649;
	case 22095ULL: goto x86_l_564f;
	case 22098ULL: goto x86_l_5652;
	case 22100ULL: goto x86_l_5654;
	case 22106ULL: goto x86_l_565a;
	case 22111ULL: goto x86_l_565f;
	case 22117ULL: goto x86_l_5665;
	case 22120ULL: goto x86_l_5668;
	case 22125ULL: goto x86_l_566d;
	case 22127ULL: goto x86_l_566f;
	case 22130ULL: goto x86_l_5672;
	case 22136ULL: goto x86_l_5678;
	case 22140ULL: goto x86_l_567c;
	case 22146ULL: goto x86_l_5682;
	case 22150ULL: goto x86_l_5686;
	case 22153ULL: goto x86_l_5689;
	case 22158ULL: goto x86_l_568e;
	case 22163ULL: goto x86_l_5693;
	case 22166ULL: goto x86_l_5696;
	case 22172ULL: goto x86_l_569c;
	case 22176ULL: goto x86_l_56a0;
	case 22181ULL: goto x86_l_56a5;
	case 22187ULL: goto x86_l_56ab;
	case 22192ULL: goto x86_l_56b0;
	case 22196ULL: goto x86_l_56b4;
	case 22200ULL: goto x86_l_56b8;
	case 22205ULL: goto x86_l_56bd;
	case 22210ULL: goto x86_l_56c2;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22221ULL: goto x86_l_56cd;
	case 22224ULL: goto x86_l_56d0;
	case 22229ULL: goto x86_l_56d5;
	case 22231ULL: goto x86_l_56d7;
	case 22236ULL: goto x86_l_56dc;
	case 22240ULL: goto x86_l_56e0;
	case 22245ULL: goto x86_l_56e5;
	case 22250ULL: goto x86_l_56ea;
	case 22252ULL: goto x86_l_56ec;
	case 22256ULL: goto x86_l_56f0;
	case 22260ULL: goto x86_l_56f4;
	case 22265ULL: goto x86_l_56f9;
	case 22270ULL: goto x86_l_56fe;
	case 22275ULL: goto x86_l_5703;
	case 22278ULL: goto x86_l_5706;
	case 22280ULL: goto x86_l_5708;
	case 22285ULL: goto x86_l_570d;
	case 22290ULL: goto x86_l_5712;
	case 22294ULL: goto x86_l_5716;
	case 22299ULL: goto x86_l_571b;
	case 22304ULL: goto x86_l_5720;
	case 22309ULL: goto x86_l_5725;
	case 22311ULL: goto x86_l_5727;
	case 22316ULL: goto x86_l_572c;
	case 22319ULL: goto x86_l_572f;
	case 22325ULL: goto x86_l_5735;
	case 22330ULL: goto x86_l_573a;
	case 22333ULL: goto x86_l_573d;
	case 22339ULL: goto x86_l_5743;
	case 22343ULL: goto x86_l_5747;
	case 22348ULL: goto x86_l_574c;
	case 22353ULL: goto x86_l_5751;
	case 22358ULL: goto x86_l_5756;
	case 22360ULL: goto x86_l_5758;
	case 22364ULL: goto x86_l_575c;
	case 22366ULL: goto x86_l_575e;
	case 22372ULL: goto x86_l_5764;
	case 22375ULL: goto x86_l_5767;
	case 22377ULL: goto x86_l_5769;
	case 22383ULL: goto x86_l_576f;
	case 22388ULL: goto x86_l_5774;
	case 22394ULL: goto x86_l_577a;
	case 22397ULL: goto x86_l_577d;
	case 22402ULL: goto x86_l_5782;
	case 22404ULL: goto x86_l_5784;
	case 22407ULL: goto x86_l_5787;
	case 22413ULL: goto x86_l_578d;
	case 22417ULL: goto x86_l_5791;
	case 22423ULL: goto x86_l_5797;
	case 22427ULL: goto x86_l_579b;
	case 22430ULL: goto x86_l_579e;
	case 22435ULL: goto x86_l_57a3;
	case 22440ULL: goto x86_l_57a8;
	case 22443ULL: goto x86_l_57ab;
	case 22449ULL: goto x86_l_57b1;
	case 22453ULL: goto x86_l_57b5;
	case 22458ULL: goto x86_l_57ba;
	case 22464ULL: goto x86_l_57c0;
	case 22469ULL: goto x86_l_57c5;
	case 22473ULL: goto x86_l_57c9;
	case 22477ULL: goto x86_l_57cd;
	case 22482ULL: goto x86_l_57d2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_516e:
	/* 0x516e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5173:
	/* 0x5173: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5177:
	/* 0x5177: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_517c:
	/* 0x517c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5181:
	/* 0x5181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5183:
	/* 0x5183: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5187:
	/* 0x5187: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_518b:
	/* 0x518b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5190:
	/* 0x5190: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5195:
	/* 0x5195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_519a:
	/* 0x519a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_519d:
	/* 0x519d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519f:
	/* 0x519f: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51a4:
	/* 0x51a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a9:
	/* 0x51a9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51ad:
	/* 0x51ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51b2:
	/* 0x51b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51b7:
	/* 0x51b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51bc:
	/* 0x51bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51be:
	/* 0x51be: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c3:
	/* 0x51c3: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_51c6:
	/* 0x51c6: je     5354 <trace_security_file_mprotect+0x5354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5354;
	}
x86_l_51cc:
	/* 0x51cc: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51d1:
	/* 0x51d1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_51d4:
	/* 0x51d4: je     5354 <trace_security_file_mprotect+0x5354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5354;
	}
x86_l_51da:
	/* 0x51da: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51de:
	/* 0x51de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51e3:
	/* 0x51e3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51e8:
	/* 0x51e8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_51ed:
	/* 0x51ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ef:
	/* 0x51ef: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_51f3:
	/* 0x51f3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_51f5:
	/* 0x51f5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51fb:
	/* 0x51fb: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_51fe:
	/* 0x51fe: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5200:
	/* 0x5200: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5206:
	/* 0x5206: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_520b:
	/* 0x520b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5211:
	/* 0x5211: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5214:
	/* 0x5214: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5219:
	/* 0x5219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521b:
	/* 0x521b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_521e:
	/* 0x521e: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_5224:
	/* 0x5224: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5228:
	/* 0x5228: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_522e:
	/* 0x522e: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5232:
	/* 0x5232: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5235:
	/* 0x5235: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_523a:
	/* 0x523a: jmp    53b5 <trace_security_file_mprotect+0x53b5> */
	goto x86_l_53b5;
x86_l_523f:
	/* 0x523f: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5242:
	/* 0x5242: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_5248:
	/* 0x5248: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_524c:
	/* 0x524c: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5251:
	/* 0x5251: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_5257:
	/* 0x5257: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_525c:
	/* 0x525c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5260:
	/* 0x5260: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5264:
	/* 0x5264: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5269:
	/* 0x5269: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_526e:
	/* 0x526e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5270:
	/* 0x5270: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5275:
	/* 0x5275: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5279:
	/* 0x5279: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_527c:
	/* 0x527c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5281:
	/* 0x5281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5283:
	/* 0x5283: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5288:
	/* 0x5288: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_528c:
	/* 0x528c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5291:
	/* 0x5291: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5296:
	/* 0x5296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5298:
	/* 0x5298: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_529c:
	/* 0x529c: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52a0:
	/* 0x52a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52a5:
	/* 0x52a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52aa:
	/* 0x52aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52af:
	/* 0x52af: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_52b2:
	/* 0x52b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b4:
	/* 0x52b4: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52b9:
	/* 0x52b9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52be:
	/* 0x52be: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52c2:
	/* 0x52c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52c7:
	/* 0x52c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52cc:
	/* 0x52cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52d1:
	/* 0x52d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52d3:
	/* 0x52d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52d8:
	/* 0x52d8: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_52db:
	/* 0x52db: je     5469 <trace_security_file_mprotect+0x5469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5469;
	}
x86_l_52e1:
	/* 0x52e1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52e6:
	/* 0x52e6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_52e9:
	/* 0x52e9: je     5469 <trace_security_file_mprotect+0x5469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5469;
	}
x86_l_52ef:
	/* 0x52ef: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52f3:
	/* 0x52f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52f8:
	/* 0x52f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52fd:
	/* 0x52fd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5302:
	/* 0x5302: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5304:
	/* 0x5304: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5308:
	/* 0x5308: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_530a:
	/* 0x530a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5310:
	/* 0x5310: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5313:
	/* 0x5313: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5315:
	/* 0x5315: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_531b:
	/* 0x531b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5320:
	/* 0x5320: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5326:
	/* 0x5326: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5329:
	/* 0x5329: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_532e:
	/* 0x532e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5330:
	/* 0x5330: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5333:
	/* 0x5333: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_5339:
	/* 0x5339: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_533d:
	/* 0x533d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5343:
	/* 0x5343: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5347:
	/* 0x5347: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_534a:
	/* 0x534a: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_534f:
	/* 0x534f: jmp    54ca <trace_security_file_mprotect+0x54ca> */
	goto x86_l_54ca;
x86_l_5354:
	/* 0x5354: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5357:
	/* 0x5357: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_535d:
	/* 0x535d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5361:
	/* 0x5361: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5366:
	/* 0x5366: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_536c:
	/* 0x536c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5371:
	/* 0x5371: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5375:
	/* 0x5375: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5379:
	/* 0x5379: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_537e:
	/* 0x537e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5383:
	/* 0x5383: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5385:
	/* 0x5385: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_538a:
	/* 0x538a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_538e:
	/* 0x538e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5391:
	/* 0x5391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5396:
	/* 0x5396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5398:
	/* 0x5398: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_539d:
	/* 0x539d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53a1:
	/* 0x53a1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53a6:
	/* 0x53a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53ab:
	/* 0x53ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53ad:
	/* 0x53ad: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53b1:
	/* 0x53b1: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_53b5:
	/* 0x53b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53ba:
	/* 0x53ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53bf:
	/* 0x53bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53c4:
	/* 0x53c4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_53c7:
	/* 0x53c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53c9:
	/* 0x53c9: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53ce:
	/* 0x53ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53d3:
	/* 0x53d3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_53d7:
	/* 0x53d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53dc:
	/* 0x53dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53e1:
	/* 0x53e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53e6:
	/* 0x53e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53e8:
	/* 0x53e8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53ed:
	/* 0x53ed: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_53f0:
	/* 0x53f0: je     557e <trace_security_file_mprotect+0x557e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557e;
	}
x86_l_53f6:
	/* 0x53f6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53fb:
	/* 0x53fb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_53fe:
	/* 0x53fe: je     557e <trace_security_file_mprotect+0x557e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557e;
	}
x86_l_5404:
	/* 0x5404: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5408:
	/* 0x5408: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_540d:
	/* 0x540d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5412:
	/* 0x5412: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5417:
	/* 0x5417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5419:
	/* 0x5419: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_541d:
	/* 0x541d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_541f:
	/* 0x541f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5425:
	/* 0x5425: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5428:
	/* 0x5428: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_542a:
	/* 0x542a: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5430:
	/* 0x5430: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5435:
	/* 0x5435: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_543b:
	/* 0x543b: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_543e:
	/* 0x543e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5443:
	/* 0x5443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5445:
	/* 0x5445: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5448:
	/* 0x5448: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_544e:
	/* 0x544e: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5452:
	/* 0x5452: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5458:
	/* 0x5458: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_545c:
	/* 0x545c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_545f:
	/* 0x545f: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5464:
	/* 0x5464: jmp    55df <trace_security_file_mprotect+0x55df> */
	goto x86_l_55df;
x86_l_5469:
	/* 0x5469: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_546c:
	/* 0x546c: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_5472:
	/* 0x5472: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5476:
	/* 0x5476: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_547b:
	/* 0x547b: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_5481:
	/* 0x5481: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5486:
	/* 0x5486: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_548a:
	/* 0x548a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_548e:
	/* 0x548e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5493:
	/* 0x5493: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5498:
	/* 0x5498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549a:
	/* 0x549a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_549f:
	/* 0x549f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54a3:
	/* 0x54a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54a6:
	/* 0x54a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54ab:
	/* 0x54ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54ad:
	/* 0x54ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54b2:
	/* 0x54b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54b6:
	/* 0x54b6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54bb:
	/* 0x54bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c0:
	/* 0x54c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54c2:
	/* 0x54c2: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c6:
	/* 0x54c6: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_54ca:
	/* 0x54ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54cf:
	/* 0x54cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54d4:
	/* 0x54d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54d9:
	/* 0x54d9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_54dc:
	/* 0x54dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54de:
	/* 0x54de: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54e3:
	/* 0x54e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e8:
	/* 0x54e8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54ec:
	/* 0x54ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54f1:
	/* 0x54f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54f6:
	/* 0x54f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54fb:
	/* 0x54fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54fd:
	/* 0x54fd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5502:
	/* 0x5502: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5505:
	/* 0x5505: je     5693 <trace_security_file_mprotect+0x5693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5693;
	}
x86_l_550b:
	/* 0x550b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5510:
	/* 0x5510: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5513:
	/* 0x5513: je     5693 <trace_security_file_mprotect+0x5693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5693;
	}
x86_l_5519:
	/* 0x5519: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_551d:
	/* 0x551d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5522:
	/* 0x5522: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5527:
	/* 0x5527: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_552c:
	/* 0x552c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552e:
	/* 0x552e: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5532:
	/* 0x5532: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5534:
	/* 0x5534: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_553a:
	/* 0x553a: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_553d:
	/* 0x553d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_553f:
	/* 0x553f: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_5545:
	/* 0x5545: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_554a:
	/* 0x554a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5550:
	/* 0x5550: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5553:
	/* 0x5553: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5558:
	/* 0x5558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555a:
	/* 0x555a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_555d:
	/* 0x555d: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_5563:
	/* 0x5563: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5567:
	/* 0x5567: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_556d:
	/* 0x556d: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5571:
	/* 0x5571: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5574:
	/* 0x5574: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5579:
	/* 0x5579: jmp    56f4 <trace_security_file_mprotect+0x56f4> */
	goto x86_l_56f4;
x86_l_557e:
	/* 0x557e: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5581:
	/* 0x5581: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_5587:
	/* 0x5587: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_558b:
	/* 0x558b: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5590:
	/* 0x5590: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_5596:
	/* 0x5596: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_559b:
	/* 0x559b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_559f:
	/* 0x559f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_55a3:
	/* 0x55a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55a8:
	/* 0x55a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55ad:
	/* 0x55ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55af:
	/* 0x55af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55b4:
	/* 0x55b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55b8:
	/* 0x55b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55bb:
	/* 0x55bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55c0:
	/* 0x55c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c2:
	/* 0x55c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55c7:
	/* 0x55c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55cb:
	/* 0x55cb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55d0:
	/* 0x55d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55d5:
	/* 0x55d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55d7:
	/* 0x55d7: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55db:
	/* 0x55db: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_55df:
	/* 0x55df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55e4:
	/* 0x55e4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55e9:
	/* 0x55e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55ee:
	/* 0x55ee: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_55f1:
	/* 0x55f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f3:
	/* 0x55f3: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55f8:
	/* 0x55f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55fd:
	/* 0x55fd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5601:
	/* 0x5601: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5606:
	/* 0x5606: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_560b:
	/* 0x560b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5610:
	/* 0x5610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5612:
	/* 0x5612: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5617:
	/* 0x5617: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_561a:
	/* 0x561a: je     57a8 <trace_security_file_mprotect+0x57a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57a8;
	}
x86_l_5620:
	/* 0x5620: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5625:
	/* 0x5625: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5628:
	/* 0x5628: je     57a8 <trace_security_file_mprotect+0x57a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57a8;
	}
x86_l_562e:
	/* 0x562e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5632:
	/* 0x5632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5637:
	/* 0x5637: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_563c:
	/* 0x563c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5641:
	/* 0x5641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5643:
	/* 0x5643: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5647:
	/* 0x5647: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5649:
	/* 0x5649: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_564f:
	/* 0x564f: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5652:
	/* 0x5652: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5654:
	/* 0x5654: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_565a:
	/* 0x565a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_565f:
	/* 0x565f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5665:
	/* 0x5665: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5668:
	/* 0x5668: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_566d:
	/* 0x566d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_566f:
	/* 0x566f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5672:
	/* 0x5672: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_5678:
	/* 0x5678: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_567c:
	/* 0x567c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5682:
	/* 0x5682: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5686:
	/* 0x5686: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5689:
	/* 0x5689: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_568e:
	/* 0x568e: jmp    5809 <trace_security_file_mprotect+0x5809> */
	return 22537ULL;
x86_l_5693:
	/* 0x5693: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5696:
	/* 0x5696: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_569c:
	/* 0x569c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56a0:
	/* 0x56a0: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_56a5:
	/* 0x56a5: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_56ab:
	/* 0x56ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56b0:
	/* 0x56b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56b4:
	/* 0x56b4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_56b8:
	/* 0x56b8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56bd:
	/* 0x56bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56c2:
	/* 0x56c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56c4:
	/* 0x56c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56c9:
	/* 0x56c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56cd:
	/* 0x56cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56d0:
	/* 0x56d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56d5:
	/* 0x56d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56d7:
	/* 0x56d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56dc:
	/* 0x56dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e0:
	/* 0x56e0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56e5:
	/* 0x56e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56ea:
	/* 0x56ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ec:
	/* 0x56ec: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56f0:
	/* 0x56f0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_56f4:
	/* 0x56f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56f9:
	/* 0x56f9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56fe:
	/* 0x56fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5703:
	/* 0x5703: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5706:
	/* 0x5706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5708:
	/* 0x5708: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_570d:
	/* 0x570d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5712:
	/* 0x5712: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5716:
	/* 0x5716: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_571b:
	/* 0x571b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5720:
	/* 0x5720: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5725:
	/* 0x5725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5727:
	/* 0x5727: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_572c:
	/* 0x572c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_572f:
	/* 0x572f: je     58bd <trace_security_file_mprotect+0x58bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22717ULL;
	}
x86_l_5735:
	/* 0x5735: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_573a:
	/* 0x573a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_573d:
	/* 0x573d: je     58bd <trace_security_file_mprotect+0x58bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22717ULL;
	}
x86_l_5743:
	/* 0x5743: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5747:
	/* 0x5747: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_574c:
	/* 0x574c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5751:
	/* 0x5751: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5756:
	/* 0x5756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5758:
	/* 0x5758: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_575c:
	/* 0x575c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_575e:
	/* 0x575e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5764:
	/* 0x5764: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5767:
	/* 0x5767: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5769:
	/* 0x5769: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_576f:
	/* 0x576f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5774:
	/* 0x5774: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_577a:
	/* 0x577a: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_577d:
	/* 0x577d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5782:
	/* 0x5782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5784:
	/* 0x5784: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5787:
	/* 0x5787: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_578d:
	/* 0x578d: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5791:
	/* 0x5791: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5797:
	/* 0x5797: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_579b:
	/* 0x579b: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_579e:
	/* 0x579e: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a3:
	/* 0x57a3: jmp    591e <trace_security_file_mprotect+0x591e> */
	return 22814ULL;
x86_l_57a8:
	/* 0x57a8: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_57ab:
	/* 0x57ab: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_57b1:
	/* 0x57b1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57b5:
	/* 0x57b5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_57ba:
	/* 0x57ba: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_57c0:
	/* 0x57c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57c5:
	/* 0x57c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c9:
	/* 0x57c9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57cd:
	/* 0x57cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d2:
	/* 0x57d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 22487ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22487ULL: goto x86_l_57d7;
	case 22489ULL: goto x86_l_57d9;
	case 22494ULL: goto x86_l_57de;
	case 22498ULL: goto x86_l_57e2;
	case 22501ULL: goto x86_l_57e5;
	case 22506ULL: goto x86_l_57ea;
	case 22508ULL: goto x86_l_57ec;
	case 22513ULL: goto x86_l_57f1;
	case 22517ULL: goto x86_l_57f5;
	case 22522ULL: goto x86_l_57fa;
	case 22527ULL: goto x86_l_57ff;
	case 22529ULL: goto x86_l_5801;
	case 22533ULL: goto x86_l_5805;
	case 22537ULL: goto x86_l_5809;
	case 22542ULL: goto x86_l_580e;
	case 22547ULL: goto x86_l_5813;
	case 22552ULL: goto x86_l_5818;
	case 22555ULL: goto x86_l_581b;
	case 22557ULL: goto x86_l_581d;
	case 22562ULL: goto x86_l_5822;
	case 22567ULL: goto x86_l_5827;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22581ULL: goto x86_l_5835;
	case 22586ULL: goto x86_l_583a;
	case 22588ULL: goto x86_l_583c;
	case 22593ULL: goto x86_l_5841;
	case 22596ULL: goto x86_l_5844;
	case 22602ULL: goto x86_l_584a;
	case 22607ULL: goto x86_l_584f;
	case 22610ULL: goto x86_l_5852;
	case 22616ULL: goto x86_l_5858;
	case 22620ULL: goto x86_l_585c;
	case 22625ULL: goto x86_l_5861;
	case 22630ULL: goto x86_l_5866;
	case 22635ULL: goto x86_l_586b;
	case 22637ULL: goto x86_l_586d;
	case 22641ULL: goto x86_l_5871;
	case 22643ULL: goto x86_l_5873;
	case 22649ULL: goto x86_l_5879;
	case 22652ULL: goto x86_l_587c;
	case 22654ULL: goto x86_l_587e;
	case 22660ULL: goto x86_l_5884;
	case 22665ULL: goto x86_l_5889;
	case 22671ULL: goto x86_l_588f;
	case 22674ULL: goto x86_l_5892;
	case 22679ULL: goto x86_l_5897;
	case 22681ULL: goto x86_l_5899;
	case 22684ULL: goto x86_l_589c;
	case 22690ULL: goto x86_l_58a2;
	case 22694ULL: goto x86_l_58a6;
	case 22700ULL: goto x86_l_58ac;
	case 22704ULL: goto x86_l_58b0;
	case 22707ULL: goto x86_l_58b3;
	case 22712ULL: goto x86_l_58b8;
	case 22717ULL: goto x86_l_58bd;
	case 22720ULL: goto x86_l_58c0;
	case 22726ULL: goto x86_l_58c6;
	case 22730ULL: goto x86_l_58ca;
	case 22735ULL: goto x86_l_58cf;
	case 22741ULL: goto x86_l_58d5;
	case 22746ULL: goto x86_l_58da;
	case 22750ULL: goto x86_l_58de;
	case 22754ULL: goto x86_l_58e2;
	case 22759ULL: goto x86_l_58e7;
	case 22764ULL: goto x86_l_58ec;
	case 22766ULL: goto x86_l_58ee;
	case 22771ULL: goto x86_l_58f3;
	case 22775ULL: goto x86_l_58f7;
	case 22778ULL: goto x86_l_58fa;
	case 22783ULL: goto x86_l_58ff;
	case 22785ULL: goto x86_l_5901;
	case 22790ULL: goto x86_l_5906;
	case 22794ULL: goto x86_l_590a;
	case 22799ULL: goto x86_l_590f;
	case 22804ULL: goto x86_l_5914;
	case 22806ULL: goto x86_l_5916;
	case 22810ULL: goto x86_l_591a;
	case 22814ULL: goto x86_l_591e;
	case 22819ULL: goto x86_l_5923;
	case 22824ULL: goto x86_l_5928;
	case 22829ULL: goto x86_l_592d;
	case 22832ULL: goto x86_l_5930;
	case 22834ULL: goto x86_l_5932;
	case 22839ULL: goto x86_l_5937;
	case 22844ULL: goto x86_l_593c;
	case 22848ULL: goto x86_l_5940;
	case 22853ULL: goto x86_l_5945;
	case 22858ULL: goto x86_l_594a;
	case 22863ULL: goto x86_l_594f;
	case 22865ULL: goto x86_l_5951;
	case 22870ULL: goto x86_l_5956;
	case 22873ULL: goto x86_l_5959;
	case 22879ULL: goto x86_l_595f;
	case 22884ULL: goto x86_l_5964;
	case 22887ULL: goto x86_l_5967;
	case 22893ULL: goto x86_l_596d;
	case 22897ULL: goto x86_l_5971;
	case 22902ULL: goto x86_l_5976;
	case 22907ULL: goto x86_l_597b;
	case 22912ULL: goto x86_l_5980;
	case 22914ULL: goto x86_l_5982;
	case 22918ULL: goto x86_l_5986;
	case 22920ULL: goto x86_l_5988;
	case 22926ULL: goto x86_l_598e;
	case 22929ULL: goto x86_l_5991;
	case 22931ULL: goto x86_l_5993;
	case 22937ULL: goto x86_l_5999;
	case 22942ULL: goto x86_l_599e;
	case 22948ULL: goto x86_l_59a4;
	case 22951ULL: goto x86_l_59a7;
	case 22956ULL: goto x86_l_59ac;
	case 22958ULL: goto x86_l_59ae;
	case 22961ULL: goto x86_l_59b1;
	case 22967ULL: goto x86_l_59b7;
	case 22971ULL: goto x86_l_59bb;
	case 22977ULL: goto x86_l_59c1;
	case 22981ULL: goto x86_l_59c5;
	case 22984ULL: goto x86_l_59c8;
	case 22989ULL: goto x86_l_59cd;
	case 22994ULL: goto x86_l_59d2;
	case 22997ULL: goto x86_l_59d5;
	case 23003ULL: goto x86_l_59db;
	case 23007ULL: goto x86_l_59df;
	case 23012ULL: goto x86_l_59e4;
	case 23018ULL: goto x86_l_59ea;
	case 23023ULL: goto x86_l_59ef;
	case 23027ULL: goto x86_l_59f3;
	case 23031ULL: goto x86_l_59f7;
	case 23036ULL: goto x86_l_59fc;
	case 23041ULL: goto x86_l_5a01;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23052ULL: goto x86_l_5a0c;
	case 23055ULL: goto x86_l_5a0f;
	case 23060ULL: goto x86_l_5a14;
	case 23062ULL: goto x86_l_5a16;
	case 23067ULL: goto x86_l_5a1b;
	case 23071ULL: goto x86_l_5a1f;
	case 23076ULL: goto x86_l_5a24;
	case 23081ULL: goto x86_l_5a29;
	case 23083ULL: goto x86_l_5a2b;
	case 23087ULL: goto x86_l_5a2f;
	case 23091ULL: goto x86_l_5a33;
	case 23096ULL: goto x86_l_5a38;
	case 23101ULL: goto x86_l_5a3d;
	case 23106ULL: goto x86_l_5a42;
	case 23109ULL: goto x86_l_5a45;
	case 23111ULL: goto x86_l_5a47;
	case 23116ULL: goto x86_l_5a4c;
	case 23121ULL: goto x86_l_5a51;
	case 23125ULL: goto x86_l_5a55;
	case 23130ULL: goto x86_l_5a5a;
	case 23135ULL: goto x86_l_5a5f;
	case 23140ULL: goto x86_l_5a64;
	case 23142ULL: goto x86_l_5a66;
	case 23147ULL: goto x86_l_5a6b;
	case 23150ULL: goto x86_l_5a6e;
	case 23156ULL: goto x86_l_5a74;
	case 23161ULL: goto x86_l_5a79;
	case 23164ULL: goto x86_l_5a7c;
	case 23170ULL: goto x86_l_5a82;
	case 23174ULL: goto x86_l_5a86;
	case 23179ULL: goto x86_l_5a8b;
	case 23184ULL: goto x86_l_5a90;
	case 23189ULL: goto x86_l_5a95;
	case 23191ULL: goto x86_l_5a97;
	case 23195ULL: goto x86_l_5a9b;
	case 23197ULL: goto x86_l_5a9d;
	case 23203ULL: goto x86_l_5aa3;
	case 23206ULL: goto x86_l_5aa6;
	case 23208ULL: goto x86_l_5aa8;
	case 23214ULL: goto x86_l_5aae;
	case 23219ULL: goto x86_l_5ab3;
	case 23225ULL: goto x86_l_5ab9;
	case 23228ULL: goto x86_l_5abc;
	case 23233ULL: goto x86_l_5ac1;
	case 23235ULL: goto x86_l_5ac3;
	case 23238ULL: goto x86_l_5ac6;
	case 23244ULL: goto x86_l_5acc;
	case 23248ULL: goto x86_l_5ad0;
	case 23254ULL: goto x86_l_5ad6;
	case 23258ULL: goto x86_l_5ada;
	case 23261ULL: goto x86_l_5add;
	case 23266ULL: goto x86_l_5ae2;
	case 23271ULL: goto x86_l_5ae7;
	case 23274ULL: goto x86_l_5aea;
	case 23280ULL: goto x86_l_5af0;
	case 23284ULL: goto x86_l_5af4;
	case 23289ULL: goto x86_l_5af9;
	case 23295ULL: goto x86_l_5aff;
	case 23300ULL: goto x86_l_5b04;
	case 23304ULL: goto x86_l_5b08;
	case 23308ULL: goto x86_l_5b0c;
	case 23313ULL: goto x86_l_5b11;
	case 23318ULL: goto x86_l_5b16;
	case 23320ULL: goto x86_l_5b18;
	case 23325ULL: goto x86_l_5b1d;
	case 23329ULL: goto x86_l_5b21;
	case 23332ULL: goto x86_l_5b24;
	case 23337ULL: goto x86_l_5b29;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23348ULL: goto x86_l_5b34;
	case 23353ULL: goto x86_l_5b39;
	case 23358ULL: goto x86_l_5b3e;
	case 23360ULL: goto x86_l_5b40;
	case 23364ULL: goto x86_l_5b44;
	case 23368ULL: goto x86_l_5b48;
	case 23373ULL: goto x86_l_5b4d;
	case 23378ULL: goto x86_l_5b52;
	case 23383ULL: goto x86_l_5b57;
	case 23386ULL: goto x86_l_5b5a;
	case 23388ULL: goto x86_l_5b5c;
	case 23393ULL: goto x86_l_5b61;
	case 23398ULL: goto x86_l_5b66;
	case 23402ULL: goto x86_l_5b6a;
	case 23407ULL: goto x86_l_5b6f;
	case 23412ULL: goto x86_l_5b74;
	case 23417ULL: goto x86_l_5b79;
	case 23419ULL: goto x86_l_5b7b;
	case 23424ULL: goto x86_l_5b80;
	case 23427ULL: goto x86_l_5b83;
	case 23433ULL: goto x86_l_5b89;
	case 23438ULL: goto x86_l_5b8e;
	case 23441ULL: goto x86_l_5b91;
	case 23447ULL: goto x86_l_5b97;
	case 23451ULL: goto x86_l_5b9b;
	case 23456ULL: goto x86_l_5ba0;
	case 23461ULL: goto x86_l_5ba5;
	case 23466ULL: goto x86_l_5baa;
	case 23468ULL: goto x86_l_5bac;
	case 23472ULL: goto x86_l_5bb0;
	case 23474ULL: goto x86_l_5bb2;
	case 23480ULL: goto x86_l_5bb8;
	case 23483ULL: goto x86_l_5bbb;
	case 23485ULL: goto x86_l_5bbd;
	case 23491ULL: goto x86_l_5bc3;
	case 23496ULL: goto x86_l_5bc8;
	case 23502ULL: goto x86_l_5bce;
	case 23505ULL: goto x86_l_5bd1;
	case 23510ULL: goto x86_l_5bd6;
	case 23512ULL: goto x86_l_5bd8;
	case 23515ULL: goto x86_l_5bdb;
	case 23521ULL: goto x86_l_5be1;
	case 23525ULL: goto x86_l_5be5;
	case 23531ULL: goto x86_l_5beb;
	case 23535ULL: goto x86_l_5bef;
	case 23538ULL: goto x86_l_5bf2;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23551ULL: goto x86_l_5bff;
	case 23557ULL: goto x86_l_5c05;
	case 23561ULL: goto x86_l_5c09;
	case 23566ULL: goto x86_l_5c0e;
	case 23572ULL: goto x86_l_5c14;
	case 23577ULL: goto x86_l_5c19;
	case 23581ULL: goto x86_l_5c1d;
	case 23585ULL: goto x86_l_5c21;
	case 23590ULL: goto x86_l_5c26;
	case 23595ULL: goto x86_l_5c2b;
	case 23597ULL: goto x86_l_5c2d;
	case 23602ULL: goto x86_l_5c32;
	case 23606ULL: goto x86_l_5c36;
	case 23609ULL: goto x86_l_5c39;
	case 23614ULL: goto x86_l_5c3e;
	case 23616ULL: goto x86_l_5c40;
	case 23621ULL: goto x86_l_5c45;
	case 23625ULL: goto x86_l_5c49;
	case 23630ULL: goto x86_l_5c4e;
	case 23635ULL: goto x86_l_5c53;
	case 23637ULL: goto x86_l_5c55;
	case 23641ULL: goto x86_l_5c59;
	case 23645ULL: goto x86_l_5c5d;
	case 23650ULL: goto x86_l_5c62;
	case 23655ULL: goto x86_l_5c67;
	case 23660ULL: goto x86_l_5c6c;
	case 23663ULL: goto x86_l_5c6f;
	case 23665ULL: goto x86_l_5c71;
	case 23670ULL: goto x86_l_5c76;
	case 23675ULL: goto x86_l_5c7b;
	case 23679ULL: goto x86_l_5c7f;
	case 23684ULL: goto x86_l_5c84;
	case 23689ULL: goto x86_l_5c89;
	case 23694ULL: goto x86_l_5c8e;
	case 23696ULL: goto x86_l_5c90;
	case 23701ULL: goto x86_l_5c95;
	case 23704ULL: goto x86_l_5c98;
	case 23710ULL: goto x86_l_5c9e;
	case 23715ULL: goto x86_l_5ca3;
	case 23718ULL: goto x86_l_5ca6;
	case 23724ULL: goto x86_l_5cac;
	case 23728ULL: goto x86_l_5cb0;
	case 23733ULL: goto x86_l_5cb5;
	case 23738ULL: goto x86_l_5cba;
	case 23743ULL: goto x86_l_5cbf;
	case 23745ULL: goto x86_l_5cc1;
	case 23749ULL: goto x86_l_5cc5;
	case 23751ULL: goto x86_l_5cc7;
	case 23757ULL: goto x86_l_5ccd;
	case 23760ULL: goto x86_l_5cd0;
	case 23762ULL: goto x86_l_5cd2;
	case 23768ULL: goto x86_l_5cd8;
	case 23773ULL: goto x86_l_5cdd;
	case 23779ULL: goto x86_l_5ce3;
	case 23782ULL: goto x86_l_5ce6;
	case 23787ULL: goto x86_l_5ceb;
	case 23789ULL: goto x86_l_5ced;
	case 23792ULL: goto x86_l_5cf0;
	case 23798ULL: goto x86_l_5cf6;
	case 23802ULL: goto x86_l_5cfa;
	case 23808ULL: goto x86_l_5d00;
	case 23812ULL: goto x86_l_5d04;
	case 23815ULL: goto x86_l_5d07;
	case 23820ULL: goto x86_l_5d0c;
	case 23825ULL: goto x86_l_5d11;
	case 23828ULL: goto x86_l_5d14;
	case 23834ULL: goto x86_l_5d1a;
	case 23838ULL: goto x86_l_5d1e;
	case 23843ULL: goto x86_l_5d23;
	case 23849ULL: goto x86_l_5d29;
	case 23854ULL: goto x86_l_5d2e;
	case 23858ULL: goto x86_l_5d32;
	case 23862ULL: goto x86_l_5d36;
	case 23867ULL: goto x86_l_5d3b;
	case 23872ULL: goto x86_l_5d40;
	case 23874ULL: goto x86_l_5d42;
	case 23879ULL: goto x86_l_5d47;
	case 23883ULL: goto x86_l_5d4b;
	case 23886ULL: goto x86_l_5d4e;
	case 23891ULL: goto x86_l_5d53;
	case 23893ULL: goto x86_l_5d55;
	case 23898ULL: goto x86_l_5d5a;
	case 23902ULL: goto x86_l_5d5e;
	case 23907ULL: goto x86_l_5d63;
	case 23912ULL: goto x86_l_5d68;
	case 23914ULL: goto x86_l_5d6a;
	case 23918ULL: goto x86_l_5d6e;
	case 23922ULL: goto x86_l_5d72;
	case 23927ULL: goto x86_l_5d77;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23940ULL: goto x86_l_5d84;
	case 23942ULL: goto x86_l_5d86;
	case 23947ULL: goto x86_l_5d8b;
	case 23952ULL: goto x86_l_5d90;
	case 23956ULL: goto x86_l_5d94;
	case 23961ULL: goto x86_l_5d99;
	case 23966ULL: goto x86_l_5d9e;
	case 23971ULL: goto x86_l_5da3;
	case 23973ULL: goto x86_l_5da5;
	case 23978ULL: goto x86_l_5daa;
	case 23981ULL: goto x86_l_5dad;
	case 23987ULL: goto x86_l_5db3;
	case 23992ULL: goto x86_l_5db8;
	case 23995ULL: goto x86_l_5dbb;
	case 24001ULL: goto x86_l_5dc1;
	case 24005ULL: goto x86_l_5dc5;
	case 24010ULL: goto x86_l_5dca;
	case 24015ULL: goto x86_l_5dcf;
	case 24020ULL: goto x86_l_5dd4;
	case 24022ULL: goto x86_l_5dd6;
	case 24026ULL: goto x86_l_5dda;
	case 24028ULL: goto x86_l_5ddc;
	case 24034ULL: goto x86_l_5de2;
	case 24037ULL: goto x86_l_5de5;
	case 24039ULL: goto x86_l_5de7;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24056ULL: goto x86_l_5df8;
	case 24059ULL: goto x86_l_5dfb;
	case 24064ULL: goto x86_l_5e00;
	case 24066ULL: goto x86_l_5e02;
	case 24069ULL: goto x86_l_5e05;
	case 24075ULL: goto x86_l_5e0b;
	case 24079ULL: goto x86_l_5e0f;
	case 24085ULL: goto x86_l_5e15;
	case 24089ULL: goto x86_l_5e19;
	case 24092ULL: goto x86_l_5e1c;
	case 24097ULL: goto x86_l_5e21;
	case 24102ULL: goto x86_l_5e26;
	case 24105ULL: goto x86_l_5e29;
	case 24111ULL: goto x86_l_5e2f;
	case 24115ULL: goto x86_l_5e33;
	default: return 0xffffffffffffffffULL;
	}
x86_l_57d7:
	/* 0x57d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d9:
	/* 0x57d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57de:
	/* 0x57de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57e2:
	/* 0x57e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57e5:
	/* 0x57e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57ea:
	/* 0x57ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57ec:
	/* 0x57ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57f1:
	/* 0x57f1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57f5:
	/* 0x57f5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57fa:
	/* 0x57fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57ff:
	/* 0x57ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5801:
	/* 0x5801: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5805:
	/* 0x5805: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5809:
	/* 0x5809: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_580e:
	/* 0x580e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5813:
	/* 0x5813: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5818:
	/* 0x5818: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_581b:
	/* 0x581b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_581d:
	/* 0x581d: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5822:
	/* 0x5822: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5827:
	/* 0x5827: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_582b:
	/* 0x582b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5830:
	/* 0x5830: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5835:
	/* 0x5835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_583a:
	/* 0x583a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_583c:
	/* 0x583c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5841:
	/* 0x5841: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5844:
	/* 0x5844: je     59d2 <trace_security_file_mprotect+0x59d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d2;
	}
x86_l_584a:
	/* 0x584a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_584f:
	/* 0x584f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5852:
	/* 0x5852: je     59d2 <trace_security_file_mprotect+0x59d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d2;
	}
x86_l_5858:
	/* 0x5858: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_585c:
	/* 0x585c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5861:
	/* 0x5861: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5866:
	/* 0x5866: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_586b:
	/* 0x586b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586d:
	/* 0x586d: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5871:
	/* 0x5871: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5873:
	/* 0x5873: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5879:
	/* 0x5879: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_587c:
	/* 0x587c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_587e:
	/* 0x587e: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5884:
	/* 0x5884: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5889:
	/* 0x5889: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_588f:
	/* 0x588f: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5892:
	/* 0x5892: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5897:
	/* 0x5897: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5899:
	/* 0x5899: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_589c:
	/* 0x589c: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_58a2:
	/* 0x58a2: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_58a6:
	/* 0x58a6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_58ac:
	/* 0x58ac: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_58b0:
	/* 0x58b0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_58b3:
	/* 0x58b3: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58b8:
	/* 0x58b8: jmp    5a33 <trace_security_file_mprotect+0x5a33> */
	goto x86_l_5a33;
x86_l_58bd:
	/* 0x58bd: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_58c0:
	/* 0x58c0: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_58c6:
	/* 0x58c6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58ca:
	/* 0x58ca: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_58cf:
	/* 0x58cf: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_58d5:
	/* 0x58d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58da:
	/* 0x58da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58de:
	/* 0x58de: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_58e2:
	/* 0x58e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58e7:
	/* 0x58e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58ec:
	/* 0x58ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58ee:
	/* 0x58ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58f3:
	/* 0x58f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58f7:
	/* 0x58f7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58fa:
	/* 0x58fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58ff:
	/* 0x58ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5901:
	/* 0x5901: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5906:
	/* 0x5906: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_590a:
	/* 0x590a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_590f:
	/* 0x590f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5914:
	/* 0x5914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5916:
	/* 0x5916: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_591a:
	/* 0x591a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_591e:
	/* 0x591e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5923:
	/* 0x5923: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5928:
	/* 0x5928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_592d:
	/* 0x592d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5930:
	/* 0x5930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5932:
	/* 0x5932: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5937:
	/* 0x5937: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_593c:
	/* 0x593c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5940:
	/* 0x5940: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5945:
	/* 0x5945: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_594a:
	/* 0x594a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_594f:
	/* 0x594f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5951:
	/* 0x5951: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5956:
	/* 0x5956: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5959:
	/* 0x5959: je     5ae7 <trace_security_file_mprotect+0x5ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ae7;
	}
x86_l_595f:
	/* 0x595f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5964:
	/* 0x5964: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5967:
	/* 0x5967: je     5ae7 <trace_security_file_mprotect+0x5ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ae7;
	}
x86_l_596d:
	/* 0x596d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5971:
	/* 0x5971: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5976:
	/* 0x5976: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_597b:
	/* 0x597b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5980:
	/* 0x5980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5982:
	/* 0x5982: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5986:
	/* 0x5986: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5988:
	/* 0x5988: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_598e:
	/* 0x598e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5991:
	/* 0x5991: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5993:
	/* 0x5993: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_5999:
	/* 0x5999: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_599e:
	/* 0x599e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_59a4:
	/* 0x59a4: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_59a7:
	/* 0x59a7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_59ac:
	/* 0x59ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ae:
	/* 0x59ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_59b1:
	/* 0x59b1: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_59b7:
	/* 0x59b7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_59bb:
	/* 0x59bb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_59c1:
	/* 0x59c1: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_59c5:
	/* 0x59c5: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_59c8:
	/* 0x59c8: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59cd:
	/* 0x59cd: jmp    5b48 <trace_security_file_mprotect+0x5b48> */
	goto x86_l_5b48;
x86_l_59d2:
	/* 0x59d2: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_59d5:
	/* 0x59d5: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_59db:
	/* 0x59db: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59df:
	/* 0x59df: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_59e4:
	/* 0x59e4: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_59ea:
	/* 0x59ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59ef:
	/* 0x59ef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59f3:
	/* 0x59f3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59f7:
	/* 0x59f7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59fc:
	/* 0x59fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a01:
	/* 0x5a01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a03:
	/* 0x5a03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a08:
	/* 0x5a08: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a0c:
	/* 0x5a0c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a0f:
	/* 0x5a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a14:
	/* 0x5a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a16:
	/* 0x5a16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a1b:
	/* 0x5a1b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a1f:
	/* 0x5a1f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a24:
	/* 0x5a24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a29:
	/* 0x5a29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a2b:
	/* 0x5a2b: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a2f:
	/* 0x5a2f: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a33:
	/* 0x5a33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a38:
	/* 0x5a38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a3d:
	/* 0x5a3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a42:
	/* 0x5a42: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a45:
	/* 0x5a45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a47:
	/* 0x5a47: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a4c:
	/* 0x5a4c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a51:
	/* 0x5a51: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a55:
	/* 0x5a55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a5a:
	/* 0x5a5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a5f:
	/* 0x5a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a64:
	/* 0x5a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a66:
	/* 0x5a66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6b:
	/* 0x5a6b: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5a6e:
	/* 0x5a6e: je     5bfc <trace_security_file_mprotect+0x5bfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bfc;
	}
x86_l_5a74:
	/* 0x5a74: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a79:
	/* 0x5a79: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5a7c:
	/* 0x5a7c: je     5bfc <trace_security_file_mprotect+0x5bfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bfc;
	}
x86_l_5a82:
	/* 0x5a82: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a86:
	/* 0x5a86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a8b:
	/* 0x5a8b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a90:
	/* 0x5a90: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5a95:
	/* 0x5a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a97:
	/* 0x5a97: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a9b:
	/* 0x5a9b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5a9d:
	/* 0x5a9d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5aa3:
	/* 0x5aa3: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5aa6:
	/* 0x5aa6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5aa8:
	/* 0x5aa8: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5aae:
	/* 0x5aae: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ab3:
	/* 0x5ab3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5ab9:
	/* 0x5ab9: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5abc:
	/* 0x5abc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5ac1:
	/* 0x5ac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac3:
	/* 0x5ac3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ac6:
	/* 0x5ac6: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_5acc:
	/* 0x5acc: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ad0:
	/* 0x5ad0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ad6:
	/* 0x5ad6: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ada:
	/* 0x5ada: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5add:
	/* 0x5add: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae2:
	/* 0x5ae2: jmp    5c5d <trace_security_file_mprotect+0x5c5d> */
	goto x86_l_5c5d;
x86_l_5ae7:
	/* 0x5ae7: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5aea:
	/* 0x5aea: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_5af0:
	/* 0x5af0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af4:
	/* 0x5af4: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5af9:
	/* 0x5af9: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_5aff:
	/* 0x5aff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b04:
	/* 0x5b04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b08:
	/* 0x5b08: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b0c:
	/* 0x5b0c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b11:
	/* 0x5b11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b16:
	/* 0x5b16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b18:
	/* 0x5b18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b1d:
	/* 0x5b1d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b21:
	/* 0x5b21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5b24:
	/* 0x5b24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b29:
	/* 0x5b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b2b:
	/* 0x5b2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b30:
	/* 0x5b30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b34:
	/* 0x5b34: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b39:
	/* 0x5b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b3e:
	/* 0x5b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b40:
	/* 0x5b40: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b44:
	/* 0x5b44: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b48:
	/* 0x5b48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b4d:
	/* 0x5b4d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b52:
	/* 0x5b52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b57:
	/* 0x5b57: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5b5a:
	/* 0x5b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5c:
	/* 0x5b5c: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b61:
	/* 0x5b61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b66:
	/* 0x5b66: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b6a:
	/* 0x5b6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b6f:
	/* 0x5b6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b74:
	/* 0x5b74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b79:
	/* 0x5b79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b7b:
	/* 0x5b7b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b80:
	/* 0x5b80: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5b83:
	/* 0x5b83: je     5d11 <trace_security_file_mprotect+0x5d11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d11;
	}
x86_l_5b89:
	/* 0x5b89: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b8e:
	/* 0x5b8e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5b91:
	/* 0x5b91: je     5d11 <trace_security_file_mprotect+0x5d11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d11;
	}
x86_l_5b97:
	/* 0x5b97: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b9b:
	/* 0x5b9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ba0:
	/* 0x5ba0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ba5:
	/* 0x5ba5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5baa:
	/* 0x5baa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bac:
	/* 0x5bac: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5bb0:
	/* 0x5bb0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5bb2:
	/* 0x5bb2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5bb8:
	/* 0x5bb8: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5bbb:
	/* 0x5bbb: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5bbd:
	/* 0x5bbd: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_5bc3:
	/* 0x5bc3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bc8:
	/* 0x5bc8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5bce:
	/* 0x5bce: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5bd1:
	/* 0x5bd1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5bd6:
	/* 0x5bd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bd8:
	/* 0x5bd8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5bdb:
	/* 0x5bdb: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_5be1:
	/* 0x5be1: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5be5:
	/* 0x5be5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5beb:
	/* 0x5beb: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5bef:
	/* 0x5bef: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5bf2:
	/* 0x5bf2: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bf7:
	/* 0x5bf7: jmp    5d72 <trace_security_file_mprotect+0x5d72> */
	goto x86_l_5d72;
x86_l_5bfc:
	/* 0x5bfc: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5bff:
	/* 0x5bff: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_5c05:
	/* 0x5c05: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c09:
	/* 0x5c09: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5c0e:
	/* 0x5c0e: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_5c14:
	/* 0x5c14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c19:
	/* 0x5c19: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c1d:
	/* 0x5c1d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c21:
	/* 0x5c21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c26:
	/* 0x5c26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c2b:
	/* 0x5c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2d:
	/* 0x5c2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c32:
	/* 0x5c32: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c36:
	/* 0x5c36: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5c39:
	/* 0x5c39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c3e:
	/* 0x5c3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c40:
	/* 0x5c40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c45:
	/* 0x5c45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c49:
	/* 0x5c49: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c4e:
	/* 0x5c4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c53:
	/* 0x5c53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c55:
	/* 0x5c55: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c59:
	/* 0x5c59: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c5d:
	/* 0x5c5d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c62:
	/* 0x5c62: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c67:
	/* 0x5c67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c6c:
	/* 0x5c6c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5c6f:
	/* 0x5c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c71:
	/* 0x5c71: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c76:
	/* 0x5c76: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c7b:
	/* 0x5c7b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c7f:
	/* 0x5c7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c84:
	/* 0x5c84: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c89:
	/* 0x5c89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c8e:
	/* 0x5c8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c90:
	/* 0x5c90: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c95:
	/* 0x5c95: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5c98:
	/* 0x5c98: je     5e26 <trace_security_file_mprotect+0x5e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e26;
	}
x86_l_5c9e:
	/* 0x5c9e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ca3:
	/* 0x5ca3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5ca6:
	/* 0x5ca6: je     5e26 <trace_security_file_mprotect+0x5e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e26;
	}
x86_l_5cac:
	/* 0x5cac: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5cb0:
	/* 0x5cb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cb5:
	/* 0x5cb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cba:
	/* 0x5cba: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5cbf:
	/* 0x5cbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc1:
	/* 0x5cc1: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5cc5:
	/* 0x5cc5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5cc7:
	/* 0x5cc7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ccd:
	/* 0x5ccd: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5cd0:
	/* 0x5cd0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5cd2:
	/* 0x5cd2: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5cd8:
	/* 0x5cd8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5cdd:
	/* 0x5cdd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5ce3:
	/* 0x5ce3: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ce6:
	/* 0x5ce6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5ceb:
	/* 0x5ceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ced:
	/* 0x5ced: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5cf0:
	/* 0x5cf0: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_5cf6:
	/* 0x5cf6: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5cfa:
	/* 0x5cfa: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5d00:
	/* 0x5d00: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5d04:
	/* 0x5d04: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d07:
	/* 0x5d07: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0c:
	/* 0x5d0c: jmp    5e87 <trace_security_file_mprotect+0x5e87> */
	return 24199ULL;
x86_l_5d11:
	/* 0x5d11: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5d14:
	/* 0x5d14: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_5d1a:
	/* 0x5d1a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d1e:
	/* 0x5d1e: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5d23:
	/* 0x5d23: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_5d29:
	/* 0x5d29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d2e:
	/* 0x5d2e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d32:
	/* 0x5d32: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d36:
	/* 0x5d36: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d3b:
	/* 0x5d3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d40:
	/* 0x5d40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d42:
	/* 0x5d42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d47:
	/* 0x5d47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d4b:
	/* 0x5d4b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d4e:
	/* 0x5d4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d53:
	/* 0x5d53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d55:
	/* 0x5d55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d5a:
	/* 0x5d5a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5e:
	/* 0x5d5e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d63:
	/* 0x5d63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d68:
	/* 0x5d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d6a:
	/* 0x5d6a: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d6e:
	/* 0x5d6e: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d72:
	/* 0x5d72: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d77:
	/* 0x5d77: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d7c:
	/* 0x5d7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d81:
	/* 0x5d81: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5d84:
	/* 0x5d84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d86:
	/* 0x5d86: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d8b:
	/* 0x5d8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d90:
	/* 0x5d90: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d94:
	/* 0x5d94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d99:
	/* 0x5d99: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d9e:
	/* 0x5d9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5da3:
	/* 0x5da3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5da5:
	/* 0x5da5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5daa:
	/* 0x5daa: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5dad:
	/* 0x5dad: je     5f3b <trace_security_file_mprotect+0x5f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24379ULL;
	}
x86_l_5db3:
	/* 0x5db3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5db8:
	/* 0x5db8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5dbb:
	/* 0x5dbb: je     5f3b <trace_security_file_mprotect+0x5f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24379ULL;
	}
x86_l_5dc1:
	/* 0x5dc1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5dc5:
	/* 0x5dc5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dca:
	/* 0x5dca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dcf:
	/* 0x5dcf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5dd4:
	/* 0x5dd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dd6:
	/* 0x5dd6: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5dda:
	/* 0x5dda: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5ddc:
	/* 0x5ddc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5de2:
	/* 0x5de2: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5de5:
	/* 0x5de5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5de7:
	/* 0x5de7: jb     2e42 <trace_security_file_mprotect+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11842ULL;
	}
x86_l_5ded:
	/* 0x5ded: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5df2:
	/* 0x5df2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5df8:
	/* 0x5df8: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5dfb:
	/* 0x5dfb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5e00:
	/* 0x5e00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e02:
	/* 0x5e02: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e05:
	/* 0x5e05: jl     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6177ULL;
	}
x86_l_5e0b:
	/* 0x5e0b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5e0f:
	/* 0x5e0f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5e15:
	/* 0x5e15: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5e19:
	/* 0x5e19: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e1c:
	/* 0x5e1c: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e21:
	/* 0x5e21: jmp    1821 <trace_security_file_mprotect+0x1821> */
	return 6177ULL;
x86_l_5e26:
	/* 0x5e26: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5e29:
	/* 0x5e29: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_5e2f:
	/* 0x5e2f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e33:
	/* 0x5e33: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
	return 24120ULL;
}

static __noinline __u64 tracee_trace_security_file_mprotect_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24120ULL: goto x86_l_5e38;
	case 24126ULL: goto x86_l_5e3e;
	case 24131ULL: goto x86_l_5e43;
	case 24135ULL: goto x86_l_5e47;
	case 24139ULL: goto x86_l_5e4b;
	case 24144ULL: goto x86_l_5e50;
	case 24149ULL: goto x86_l_5e55;
	case 24151ULL: goto x86_l_5e57;
	case 24156ULL: goto x86_l_5e5c;
	case 24160ULL: goto x86_l_5e60;
	case 24163ULL: goto x86_l_5e63;
	case 24168ULL: goto x86_l_5e68;
	case 24170ULL: goto x86_l_5e6a;
	case 24175ULL: goto x86_l_5e6f;
	case 24179ULL: goto x86_l_5e73;
	case 24184ULL: goto x86_l_5e78;
	case 24189ULL: goto x86_l_5e7d;
	case 24191ULL: goto x86_l_5e7f;
	case 24195ULL: goto x86_l_5e83;
	case 24199ULL: goto x86_l_5e87;
	case 24204ULL: goto x86_l_5e8c;
	case 24209ULL: goto x86_l_5e91;
	case 24214ULL: goto x86_l_5e96;
	case 24217ULL: goto x86_l_5e99;
	case 24219ULL: goto x86_l_5e9b;
	case 24224ULL: goto x86_l_5ea0;
	case 24229ULL: goto x86_l_5ea5;
	case 24233ULL: goto x86_l_5ea9;
	case 24238ULL: goto x86_l_5eae;
	case 24243ULL: goto x86_l_5eb3;
	case 24248ULL: goto x86_l_5eb8;
	case 24250ULL: goto x86_l_5eba;
	case 24255ULL: goto x86_l_5ebf;
	case 24258ULL: goto x86_l_5ec2;
	case 24264ULL: goto x86_l_5ec8;
	case 24269ULL: goto x86_l_5ecd;
	case 24272ULL: goto x86_l_5ed0;
	case 24278ULL: goto x86_l_5ed6;
	case 24282ULL: goto x86_l_5eda;
	case 24287ULL: goto x86_l_5edf;
	case 24292ULL: goto x86_l_5ee4;
	case 24297ULL: goto x86_l_5ee9;
	case 24299ULL: goto x86_l_5eeb;
	case 24303ULL: goto x86_l_5eef;
	case 24305ULL: goto x86_l_5ef1;
	case 24311ULL: goto x86_l_5ef7;
	case 24314ULL: goto x86_l_5efa;
	case 24316ULL: goto x86_l_5efc;
	case 24322ULL: goto x86_l_5f02;
	case 24327ULL: goto x86_l_5f07;
	case 24333ULL: goto x86_l_5f0d;
	case 24336ULL: goto x86_l_5f10;
	case 24341ULL: goto x86_l_5f15;
	case 24343ULL: goto x86_l_5f17;
	case 24346ULL: goto x86_l_5f1a;
	case 24352ULL: goto x86_l_5f20;
	case 24356ULL: goto x86_l_5f24;
	case 24362ULL: goto x86_l_5f2a;
	case 24366ULL: goto x86_l_5f2e;
	case 24369ULL: goto x86_l_5f31;
	case 24374ULL: goto x86_l_5f36;
	case 24379ULL: goto x86_l_5f3b;
	case 24382ULL: goto x86_l_5f3e;
	case 24388ULL: goto x86_l_5f44;
	case 24392ULL: goto x86_l_5f48;
	case 24397ULL: goto x86_l_5f4d;
	case 24403ULL: goto x86_l_5f53;
	case 24408ULL: goto x86_l_5f58;
	case 24412ULL: goto x86_l_5f5c;
	case 24416ULL: goto x86_l_5f60;
	case 24421ULL: goto x86_l_5f65;
	case 24426ULL: goto x86_l_5f6a;
	case 24428ULL: goto x86_l_5f6c;
	case 24433ULL: goto x86_l_5f71;
	case 24437ULL: goto x86_l_5f75;
	case 24440ULL: goto x86_l_5f78;
	case 24445ULL: goto x86_l_5f7d;
	case 24447ULL: goto x86_l_5f7f;
	case 24452ULL: goto x86_l_5f84;
	case 24456ULL: goto x86_l_5f88;
	case 24461ULL: goto x86_l_5f8d;
	case 24466ULL: goto x86_l_5f92;
	case 24468ULL: goto x86_l_5f94;
	case 24473ULL: goto x86_l_5f99;
	case 24476ULL: goto x86_l_5f9c;
	case 24482ULL: goto x86_l_5fa2;
	case 24486ULL: goto x86_l_5fa6;
	case 24491ULL: goto x86_l_5fab;
	case 24497ULL: goto x86_l_5fb1;
	case 24502ULL: goto x86_l_5fb6;
	case 24506ULL: goto x86_l_5fba;
	case 24510ULL: goto x86_l_5fbe;
	case 24515ULL: goto x86_l_5fc3;
	case 24520ULL: goto x86_l_5fc8;
	case 24522ULL: goto x86_l_5fca;
	case 24527ULL: goto x86_l_5fcf;
	case 24531ULL: goto x86_l_5fd3;
	case 24534ULL: goto x86_l_5fd6;
	case 24539ULL: goto x86_l_5fdb;
	case 24541ULL: goto x86_l_5fdd;
	case 24546ULL: goto x86_l_5fe2;
	case 24550ULL: goto x86_l_5fe6;
	case 24555ULL: goto x86_l_5feb;
	case 24560ULL: goto x86_l_5ff0;
	case 24562ULL: goto x86_l_5ff2;
	case 24566ULL: goto x86_l_5ff6;
	case 24570ULL: goto x86_l_5ffa;
	case 24575ULL: goto x86_l_5fff;
	case 24580ULL: goto x86_l_6004;
	case 24585ULL: goto x86_l_6009;
	case 24588ULL: goto x86_l_600c;
	case 24590ULL: goto x86_l_600e;
	case 24595ULL: goto x86_l_6013;
	case 24600ULL: goto x86_l_6018;
	case 24604ULL: goto x86_l_601c;
	case 24609ULL: goto x86_l_6021;
	case 24614ULL: goto x86_l_6026;
	case 24619ULL: goto x86_l_602b;
	case 24621ULL: goto x86_l_602d;
	case 24626ULL: goto x86_l_6032;
	case 24629ULL: goto x86_l_6035;
	case 24631ULL: goto x86_l_6037;
	case 24636ULL: goto x86_l_603c;
	case 24639ULL: goto x86_l_603f;
	case 24641ULL: goto x86_l_6041;
	case 24645ULL: goto x86_l_6045;
	case 24650ULL: goto x86_l_604a;
	case 24655ULL: goto x86_l_604f;
	case 24660ULL: goto x86_l_6054;
	case 24662ULL: goto x86_l_6056;
	case 24666ULL: goto x86_l_605a;
	case 24668ULL: goto x86_l_605c;
	case 24674ULL: goto x86_l_6062;
	case 24677ULL: goto x86_l_6065;
	case 24679ULL: goto x86_l_6067;
	case 24685ULL: goto x86_l_606d;
	case 24690ULL: goto x86_l_6072;
	case 24696ULL: goto x86_l_6078;
	case 24699ULL: goto x86_l_607b;
	case 24704ULL: goto x86_l_6080;
	case 24706ULL: goto x86_l_6082;
	case 24709ULL: goto x86_l_6085;
	case 24715ULL: goto x86_l_608b;
	case 24719ULL: goto x86_l_608f;
	case 24725ULL: goto x86_l_6095;
	case 24729ULL: goto x86_l_6099;
	case 24732ULL: goto x86_l_609c;
	case 24737ULL: goto x86_l_60a1;
	case 24742ULL: goto x86_l_60a6;
	case 24745ULL: goto x86_l_60a9;
	case 24751ULL: goto x86_l_60af;
	case 24755ULL: goto x86_l_60b3;
	case 24760ULL: goto x86_l_60b8;
	case 24766ULL: goto x86_l_60be;
	case 24771ULL: goto x86_l_60c3;
	case 24775ULL: goto x86_l_60c7;
	case 24779ULL: goto x86_l_60cb;
	case 24784ULL: goto x86_l_60d0;
	case 24789ULL: goto x86_l_60d5;
	case 24791ULL: goto x86_l_60d7;
	case 24796ULL: goto x86_l_60dc;
	case 24800ULL: goto x86_l_60e0;
	case 24803ULL: goto x86_l_60e3;
	case 24808ULL: goto x86_l_60e8;
	case 24810ULL: goto x86_l_60ea;
	case 24815ULL: goto x86_l_60ef;
	case 24819ULL: goto x86_l_60f3;
	case 24824ULL: goto x86_l_60f8;
	case 24829ULL: goto x86_l_60fd;
	case 24831ULL: goto x86_l_60ff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5e38:
	/* 0x5e38: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_5e3e:
	/* 0x5e3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e43:
	/* 0x5e43: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e47:
	/* 0x5e47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e4b:
	/* 0x5e4b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e50:
	/* 0x5e50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e55:
	/* 0x5e55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e57:
	/* 0x5e57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e5c:
	/* 0x5e5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e60:
	/* 0x5e60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5e63:
	/* 0x5e63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e68:
	/* 0x5e68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e6a:
	/* 0x5e6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e6f:
	/* 0x5e6f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e73:
	/* 0x5e73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e78:
	/* 0x5e78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e7d:
	/* 0x5e7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e7f:
	/* 0x5e7f: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e83:
	/* 0x5e83: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e87:
	/* 0x5e87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e8c:
	/* 0x5e8c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e91:
	/* 0x5e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e96:
	/* 0x5e96: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5e99:
	/* 0x5e99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e9b:
	/* 0x5e9b: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ea0:
	/* 0x5ea0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ea5:
	/* 0x5ea5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ea9:
	/* 0x5ea9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5eae:
	/* 0x5eae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5eb3:
	/* 0x5eb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eb8:
	/* 0x5eb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eba:
	/* 0x5eba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ebf:
	/* 0x5ebf: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5ec2:
	/* 0x5ec2: je     5f99 <trace_security_file_mprotect+0x5f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f99;
	}
x86_l_5ec8:
	/* 0x5ec8: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ecd:
	/* 0x5ecd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5ed0:
	/* 0x5ed0: je     5f99 <trace_security_file_mprotect+0x5f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f99;
	}
x86_l_5ed6:
	/* 0x5ed6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5eda:
	/* 0x5eda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5edf:
	/* 0x5edf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ee4:
	/* 0x5ee4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5ee9:
	/* 0x5ee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eeb:
	/* 0x5eeb: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5eef:
	/* 0x5eef: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5ef1:
	/* 0x5ef1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ef7:
	/* 0x5ef7: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5efa:
	/* 0x5efa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5efc:
	/* 0x5efc: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_5f02:
	/* 0x5f02: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f07:
	/* 0x5f07: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5f0d:
	/* 0x5f0d: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5f10:
	/* 0x5f10: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5f15:
	/* 0x5f15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f17:
	/* 0x5f17: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5f1a:
	/* 0x5f1a: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_5f20:
	/* 0x5f20: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5f24:
	/* 0x5f24: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5f2a:
	/* 0x5f2a: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5f2e:
	/* 0x5f2e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5f31:
	/* 0x5f31: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f36:
	/* 0x5f36: jmp    5ffa <trace_security_file_mprotect+0x5ffa> */
	goto x86_l_5ffa;
x86_l_5f3b:
	/* 0x5f3b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5f3e:
	/* 0x5f3e: jne    1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6177ULL;
	}
x86_l_5f44:
	/* 0x5f44: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f48:
	/* 0x5f48: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5f4d:
	/* 0x5f4d: je     1821 <trace_security_file_mprotect+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6177ULL;
	}
x86_l_5f53:
	/* 0x5f53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f58:
	/* 0x5f58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f5c:
	/* 0x5f5c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f60:
	/* 0x5f60: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f65:
	/* 0x5f65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f6a:
	/* 0x5f6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f6c:
	/* 0x5f6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f71:
	/* 0x5f71: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f75:
	/* 0x5f75: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f78:
	/* 0x5f78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f7d:
	/* 0x5f7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f7f:
	/* 0x5f7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f84:
	/* 0x5f84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f88:
	/* 0x5f88: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f8d:
	/* 0x5f8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f92:
	/* 0x5f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f94:
	/* 0x5f94: jmp    1821 <trace_security_file_mprotect+0x1821> */
	return 6177ULL;
x86_l_5f99:
	/* 0x5f99: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5f9c:
	/* 0x5f9c: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_5fa2:
	/* 0x5fa2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fa6:
	/* 0x5fa6: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_5fab:
	/* 0x5fab: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_5fb1:
	/* 0x5fb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fb6:
	/* 0x5fb6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fba:
	/* 0x5fba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5fbe:
	/* 0x5fbe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fc3:
	/* 0x5fc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fc8:
	/* 0x5fc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fca:
	/* 0x5fca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fcf:
	/* 0x5fcf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd3:
	/* 0x5fd3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5fd6:
	/* 0x5fd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fdb:
	/* 0x5fdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fdd:
	/* 0x5fdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fe2:
	/* 0x5fe2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fe6:
	/* 0x5fe6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5feb:
	/* 0x5feb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ff0:
	/* 0x5ff0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff2:
	/* 0x5ff2: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ff6:
	/* 0x5ff6: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ffa:
	/* 0x5ffa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fff:
	/* 0x5fff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6004:
	/* 0x6004: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6009:
	/* 0x6009: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_600c:
	/* 0x600c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_600e:
	/* 0x600e: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6013:
	/* 0x6013: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6018:
	/* 0x6018: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_601c:
	/* 0x601c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6021:
	/* 0x6021: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6026:
	/* 0x6026: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_602b:
	/* 0x602b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602d:
	/* 0x602d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6032:
	/* 0x6032: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6035:
	/* 0x6035: je     60a6 <trace_security_file_mprotect+0x60a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60a6;
	}
x86_l_6037:
	/* 0x6037: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_603c:
	/* 0x603c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_603f:
	/* 0x603f: je     60a6 <trace_security_file_mprotect+0x60a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60a6;
	}
x86_l_6041:
	/* 0x6041: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6045:
	/* 0x6045: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_604a:
	/* 0x604a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_604f:
	/* 0x604f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6054:
	/* 0x6054: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6056:
	/* 0x6056: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_605a:
	/* 0x605a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_605c:
	/* 0x605c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6062:
	/* 0x6062: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_6065:
	/* 0x6065: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6067:
	/* 0x6067: jb     30de <trace_security_file_mprotect+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12510ULL;
	}
x86_l_606d:
	/* 0x606d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6072:
	/* 0x6072: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6078:
	/* 0x6078: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_607b:
	/* 0x607b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6080:
	/* 0x6080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6082:
	/* 0x6082: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6085:
	/* 0x6085: jl     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11990ULL;
	}
x86_l_608b:
	/* 0x608b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_608f:
	/* 0x608f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6095:
	/* 0x6095: mov    BYTE PTR [rbx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6099:
	/* 0x6099: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_609c:
	/* 0x609c: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a1:
	/* 0x60a1: jmp    2ed6 <trace_security_file_mprotect+0x2ed6> */
	return 11990ULL;
x86_l_60a6:
	/* 0x60a6: cmp    rdx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_60a9:
	/* 0x60a9: jne    2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11990ULL;
	}
x86_l_60af:
	/* 0x60af: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60b3:
	/* 0x60b3: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_60b8:
	/* 0x60b8: je     2ed6 <trace_security_file_mprotect+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11990ULL;
	}
x86_l_60be:
	/* 0x60be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60c3:
	/* 0x60c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60c7:
	/* 0x60c7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_60cb:
	/* 0x60cb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60d0:
	/* 0x60d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60d5:
	/* 0x60d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60d7:
	/* 0x60d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60dc:
	/* 0x60dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60e0:
	/* 0x60e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_60e3:
	/* 0x60e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60e8:
	/* 0x60e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60ea:
	/* 0x60ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60ef:
	/* 0x60ef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60f3:
	/* 0x60f3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60f8:
	/* 0x60f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60fd:
	/* 0x60fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60ff:
	/* 0x60ff: jmp    2ed6 <trace_security_file_mprotect+0x2ed6> */
	return 11990ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 22184U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2207ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2212ULL && __x86_pc <= 3899ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3907ULL && __x86_pc <= 5553ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5559ULL && __x86_pc <= 7363ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7371ULL && __x86_pc <= 9107ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9114ULL && __x86_pc <= 10699ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10706ULL && __x86_pc <= 12379ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12383ULL && __x86_pc <= 14248ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14252ULL && __x86_pc <= 15933ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15938ULL && __x86_pc <= 17569ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17571ULL && __x86_pc <= 19205ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19209ULL && __x86_pc <= 20844ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20846ULL && __x86_pc <= 22482ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22487ULL && __x86_pc <= 24115ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 24120ULL && __x86_pc <= 24831ULL)
			__x86_pc = tracee_trace_security_file_mprotect_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char args_map;
extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char io_file_path_cache_map;
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

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_0(
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
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 39ULL: goto x86_l_27;
	case 42ULL: goto x86_l_2a;
	case 47ULL: goto x86_l_2f;
	case 54ULL: goto x86_l_36;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 66ULL: goto x86_l_42;
	case 69ULL: goto x86_l_45;
	case 75ULL: goto x86_l_4b;
	case 83ULL: goto x86_l_53;
	case 86ULL: goto x86_l_56;
	case 90ULL: goto x86_l_5a;
	case 98ULL: goto x86_l_62;
	case 102ULL: goto x86_l_66;
	case 110ULL: goto x86_l_6e;
	case 114ULL: goto x86_l_72;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 129ULL: goto x86_l_81;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
	case 139ULL: goto x86_l_8b;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 168ULL: goto x86_l_a8;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 183ULL: goto x86_l_b7;
	case 188ULL: goto x86_l_bc;
	case 190ULL: goto x86_l_be;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 200ULL: goto x86_l_c8;
	case 203ULL: goto x86_l_cb;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 246ULL: goto x86_l_f6;
	case 250ULL: goto x86_l_fa;
	case 252ULL: goto x86_l_fc;
	case 259ULL: goto x86_l_103;
	case 264ULL: goto x86_l_108;
	case 269ULL: goto x86_l_10d;
	case 271ULL: goto x86_l_10f;
	case 274ULL: goto x86_l_112;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 293ULL: goto x86_l_125;
	case 301ULL: goto x86_l_12d;
	case 308ULL: goto x86_l_134;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 339ULL: goto x86_l_153;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 373ULL: goto x86_l_175;
	case 381ULL: goto x86_l_17d;
	case 392ULL: goto x86_l_188;
	case 403ULL: goto x86_l_193;
	case 414ULL: goto x86_l_19e;
	case 425ULL: goto x86_l_1a9;
	case 436ULL: goto x86_l_1b4;
	case 447ULL: goto x86_l_1bf;
	case 458ULL: goto x86_l_1ca;
	case 469ULL: goto x86_l_1d5;
	case 476ULL: goto x86_l_1dc;
	case 484ULL: goto x86_l_1e4;
	case 492ULL: goto x86_l_1ec;
	case 500ULL: goto x86_l_1f4;
	case 508ULL: goto x86_l_1fc;
	case 516ULL: goto x86_l_204;
	case 524ULL: goto x86_l_20c;
	case 532ULL: goto x86_l_214;
	case 540ULL: goto x86_l_21c;
	case 548ULL: goto x86_l_224;
	case 556ULL: goto x86_l_22c;
	case 564ULL: goto x86_l_234;
	case 572ULL: goto x86_l_23c;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 591ULL: goto x86_l_24f;
	case 595ULL: goto x86_l_253;
	case 599ULL: goto x86_l_257;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 633ULL: goto x86_l_279;
	case 637ULL: goto x86_l_27d;
	case 640ULL: goto x86_l_280;
	case 647ULL: goto x86_l_287;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 678ULL: goto x86_l_2a6;
	case 685ULL: goto x86_l_2ad;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 700ULL: goto x86_l_2bc;
	case 703ULL: goto x86_l_2bf;
	case 706ULL: goto x86_l_2c2;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 742ULL: goto x86_l_2e6;
	case 750ULL: goto x86_l_2ee;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 767ULL: goto x86_l_2ff;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 785ULL: goto x86_l_311;
	case 789ULL: goto x86_l_315;
	case 800ULL: goto x86_l_320;
	case 811ULL: goto x86_l_32b;
	case 822ULL: goto x86_l_336;
	case 833ULL: goto x86_l_341;
	case 844ULL: goto x86_l_34c;
	case 855ULL: goto x86_l_357;
	case 866ULL: goto x86_l_362;
	case 877ULL: goto x86_l_36d;
	case 888ULL: goto x86_l_378;
	case 899ULL: goto x86_l_383;
	case 910ULL: goto x86_l_38e;
	case 921ULL: goto x86_l_399;
	case 932ULL: goto x86_l_3a4;
	case 943ULL: goto x86_l_3af;
	case 954ULL: goto x86_l_3ba;
	case 965ULL: goto x86_l_3c5;
	case 976ULL: goto x86_l_3d0;
	case 987ULL: goto x86_l_3db;
	case 998ULL: goto x86_l_3e6;
	case 1009ULL: goto x86_l_3f1;
	case 1020ULL: goto x86_l_3fc;
	case 1031ULL: goto x86_l_407;
	case 1042ULL: goto x86_l_412;
	case 1053ULL: goto x86_l_41d;
	case 1064ULL: goto x86_l_428;
	case 1075ULL: goto x86_l_433;
	case 1086ULL: goto x86_l_43e;
	case 1097ULL: goto x86_l_449;
	case 1108ULL: goto x86_l_454;
	case 1119ULL: goto x86_l_45f;
	case 1127ULL: goto x86_l_467;
	case 1135ULL: goto x86_l_46f;
	case 1143ULL: goto x86_l_477;
	case 1151ULL: goto x86_l_47f;
	case 1159ULL: goto x86_l_487;
	case 1167ULL: goto x86_l_48f;
	case 1175ULL: goto x86_l_497;
	case 1183ULL: goto x86_l_49f;
	case 1191ULL: goto x86_l_4a7;
	case 1199ULL: goto x86_l_4af;
	case 1207ULL: goto x86_l_4b7;
	case 1215ULL: goto x86_l_4bf;
	case 1223ULL: goto x86_l_4c7;
	case 1231ULL: goto x86_l_4cf;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1286ULL: goto x86_l_506;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1296ULL: goto x86_l_510;
	case 1302ULL: goto x86_l_516;
	case 1307ULL: goto x86_l_51b;
	case 1314ULL: goto x86_l_522;
	case 1318ULL: goto x86_l_526;
	case 1326ULL: goto x86_l_52e;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1350ULL: goto x86_l_546;
	case 1353ULL: goto x86_l_549;
	case 1359ULL: goto x86_l_54f;
	case 1362ULL: goto x86_l_552;
	case 1366ULL: goto x86_l_556;
	case 1370ULL: goto x86_l_55a;
	case 1381ULL: goto x86_l_565;
	case 1392ULL: goto x86_l_570;
	case 1403ULL: goto x86_l_57b;
	case 1414ULL: goto x86_l_586;
	case 1425ULL: goto x86_l_591;
	case 1436ULL: goto x86_l_59c;
	case 1447ULL: goto x86_l_5a7;
	case 1458ULL: goto x86_l_5b2;
	case 1469ULL: goto x86_l_5bd;
	case 1477ULL: goto x86_l_5c5;
	case 1485ULL: goto x86_l_5cd;
	case 1493ULL: goto x86_l_5d5;
	case 1501ULL: goto x86_l_5dd;
	case 1509ULL: goto x86_l_5e5;
	case 1517ULL: goto x86_l_5ed;
	case 1525ULL: goto x86_l_5f5;
	case 1533ULL: goto x86_l_5fd;
	case 1541ULL: goto x86_l_605;
	case 1549ULL: goto x86_l_60d;
	case 1557ULL: goto x86_l_615;
	case 1565ULL: goto x86_l_61d;
	case 1573ULL: goto x86_l_625;
	case 1581ULL: goto x86_l_62d;
	case 1589ULL: goto x86_l_635;
	case 1596ULL: goto x86_l_63c;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1621ULL: goto x86_l_655;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1636ULL: goto x86_l_664;
	case 1638ULL: goto x86_l_666;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1650ULL: goto x86_l_672;
	case 1657ULL: goto x86_l_679;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1767ULL: goto x86_l_6e7;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1789ULL: goto x86_l_6fd;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1873ULL: goto x86_l_751;
	case 1877ULL: goto x86_l_755;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1933ULL: goto x86_l_78d;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 1996ULL: goto x86_l_7cc;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2034ULL: goto x86_l_7f2;
	case 2038ULL: goto x86_l_7f6;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2098ULL: goto x86_l_832;
	case 2102ULL: goto x86_l_836;
	case 2106ULL: goto x86_l_83a;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2136ULL: goto x86_l_858;
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
	/* 0xa: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: movabs rbp,0x2d100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 3096671420416ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27:
	/* 0x27: or     rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a:
	/* 0x2a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f:
	/* 0x2f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_36:
	/* 0x36: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b:
	/* 0x3b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40:
	/* 0x40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42:
	/* 0x42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_45:
	/* 0x45: je     2047 <trace_ret_vfs_writev+0x2047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8263ULL;
	}
x86_l_4b:
	/* 0x4b: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_53:
	/* 0x53: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56:
	/* 0x56: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_62:
	/* 0x62: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_6e:
	/* 0x6e: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_7f:
	/* 0x7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81:
	/* 0x81: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_89:
	/* 0x89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b:
	/* 0x8b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8e:
	/* 0x8e: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_92:
	/* 0x92: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_97:
	/* 0x97: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9c:
	/* 0x9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a1:
	/* 0xa1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a6:
	/* 0xa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8:
	/* 0xa8: test   DWORD PTR [rsp+0x50],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343599480832ULL);
x86_l_b0:
	/* 0xb0: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_b5:
	/* 0xb5: jne    11d <trace_ret_vfs_writev+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11d;
	}
x86_l_b7:
	/* 0xb7: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_bc:
	/* 0xbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be:
	/* 0xbe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_c6:
	/* 0xc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8:
	/* 0xc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb:
	/* 0xcb: je     d2 <trace_ret_vfs_writev+0xd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2;
	}
x86_l_cd:
	/* 0xcd: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d0:
	/* 0xd0: jmp    d2 <trace_ret_vfs_writev+0xd2> */
	goto x86_l_d2;
x86_l_d2:
	/* 0xd2: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6:
	/* 0xd6: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_db:
	/* 0xdb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e0:
	/* 0xe0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5:
	/* 0xe5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ea:
	/* 0xea: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_f4:
	/* 0xf4: jne    fc <trace_ret_vfs_writev+0xfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fc;
	}
x86_l_f6:
	/* 0xf6: mov    ebx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fa:
	/* 0xfa: jmp    11d <trace_ret_vfs_writev+0x11d> */
	goto x86_l_11d;
x86_l_fc:
	/* 0xfc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_103:
	/* 0x103: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_108:
	/* 0x108: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d:
	/* 0x10d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f:
	/* 0x10f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112:
	/* 0x112: je     118 <trace_ret_vfs_writev+0x118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118;
	}
x86_l_114:
	/* 0x114: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116:
	/* 0x116: jmp    11d <trace_ret_vfs_writev+0x11d> */
	goto x86_l_11d;
x86_l_118:
	/* 0x118: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_11d:
	/* 0x11d: mov    QWORD PTR [rsp+0xd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_125:
	/* 0x125: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_12d:
	/* 0x12d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_134:
	/* 0x134: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_139:
	/* 0x139: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e:
	/* 0x13e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140:
	/* 0x140: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_143:
	/* 0x143: je     2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_149:
	/* 0x149: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_14c:
	/* 0x14c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_153:
	/* 0x153: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_158:
	/* 0x158: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d:
	/* 0x15d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f:
	/* 0x15f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162:
	/* 0x162: je     2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_168:
	/* 0x168: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_175:
	/* 0x175: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_193:
	/* 0x193: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [r14+0x7dd0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1dc:
	/* 0x1dc: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e4:
	/* 0x1e4: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ec:
	/* 0x1ec: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f4:
	/* 0x1f4: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1fc:
	/* 0x1fc: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_204:
	/* 0x204: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20c:
	/* 0x20c: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_214:
	/* 0x214: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_21c:
	/* 0x21c: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_224:
	/* 0x224: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_22c:
	/* 0x22c: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_234:
	/* 0x234: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_23c:
	/* 0x23c: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_244:
	/* 0x244: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_249:
	/* 0x249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b:
	/* 0x24b: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24f:
	/* 0x24f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_253:
	/* 0x253: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_257:
	/* 0x257: mov    DWORD PTR [r14+0x70],0x2d1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337873ULL);
x86_l_25f:
	/* 0x25f: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_264:
	/* 0x264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266:
	/* 0x266: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269:
	/* 0x269: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_26e:
	/* 0x26e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270:
	/* 0x270: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_275:
	/* 0x275: mov    DWORD PTR [r14+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_279:
	/* 0x279: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_27d:
	/* 0x27d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280:
	/* 0x280: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_287:
	/* 0x287: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_28a:
	/* 0x28a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f:
	/* 0x28f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291:
	/* 0x291: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_296:
	/* 0x296: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: je     2df <trace_ret_vfs_writev+0x2df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df;
	}
x86_l_29b:
	/* 0x29b: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29f:
	/* 0x29f: mov    DWORD PTR [rsp+0xc4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2a6:
	/* 0x2a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2ad:
	/* 0x2ad: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2b5:
	/* 0x2b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ba:
	/* 0x2ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc:
	/* 0x2bc: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2bf:
	/* 0x2bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: je     51b <trace_ret_vfs_writev+0x51b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51b;
	}
x86_l_2c8:
	/* 0x2c8: test   BYTE PTR [r13+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2cd:
	/* 0x2cd: jne    b2d <trace_ret_vfs_writev+0xb2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2861ULL;
	}
x86_l_2d3:
	/* 0x2d3: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2d8:
	/* 0x2d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da:
	/* 0x2da: jmp    bd7 <trace_ret_vfs_writev+0xbd7> */
	return 3031ULL;
x86_l_2df:
	/* 0x2df: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2:
	/* 0x2e2: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e6:
	/* 0x2e6: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ee:
	/* 0x2ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2f5:
	/* 0x2f5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa:
	/* 0x2fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ff:
	/* 0x2ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301:
	/* 0x301: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_304:
	/* 0x304: je     2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_30a:
	/* 0x30a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_311:
	/* 0x311: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_315:
	/* 0x315: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_320:
	/* 0x320: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_32b:
	/* 0x32b: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_336:
	/* 0x336: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_341:
	/* 0x341: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_34c:
	/* 0x34c: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_357:
	/* 0x357: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_362:
	/* 0x362: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_36d:
	/* 0x36d: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_378:
	/* 0x378: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3d0:
	/* 0x3d0: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_467:
	/* 0x467: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_46f:
	/* 0x46f: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_477:
	/* 0x477: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_48f:
	/* 0x48f: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_497:
	/* 0x497: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_49f:
	/* 0x49f: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4a7:
	/* 0x4a7: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4af:
	/* 0x4af: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4b7:
	/* 0x4b7: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4bf:
	/* 0x4bf: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4c7:
	/* 0x4c7: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4cf:
	/* 0x4cf: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4d7:
	/* 0x4d7: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4de:
	/* 0x4de: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4e5:
	/* 0x4e5: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4ea:
	/* 0x4ea: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ef:
	/* 0x4ef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4f4:
	/* 0x4f4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f9:
	/* 0x4f9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fe:
	/* 0x4fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_503:
	/* 0x503: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_506:
	/* 0x506: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508:
	/* 0x508: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d:
	/* 0x50d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_510:
	/* 0x510: jne    29b <trace_ret_vfs_writev+0x29b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b;
	}
x86_l_516:
	/* 0x516: jmp    2023 <trace_ret_vfs_writev+0x2023> */
	return 8227ULL;
x86_l_51b:
	/* 0x51b: mov    eax,DWORD PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_522:
	/* 0x522: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_526:
	/* 0x526: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_52e:
	/* 0x52e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_535:
	/* 0x535: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53a:
	/* 0x53a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53f:
	/* 0x53f: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_544:
	/* 0x544: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_546:
	/* 0x546: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_549:
	/* 0x549: je     2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_54f:
	/* 0x54f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_552:
	/* 0x552: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_556:
	/* 0x556: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_55a:
	/* 0x55a: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_565:
	/* 0x565: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_591:
	/* 0x591: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5b2:
	/* 0x5b2: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5c5:
	/* 0x5c5: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5cd:
	/* 0x5cd: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5dd:
	/* 0x5dd: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5e5:
	/* 0x5e5: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5ed:
	/* 0x5ed: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_605:
	/* 0x605: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_60d:
	/* 0x60d: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_615:
	/* 0x615: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_61d:
	/* 0x61d: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_625:
	/* 0x625: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_62d:
	/* 0x62d: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_635:
	/* 0x635: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63c:
	/* 0x63c: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_643:
	/* 0x643: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_648:
	/* 0x648: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64d:
	/* 0x64d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_652:
	/* 0x652: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_655:
	/* 0x655: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657:
	/* 0x657: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65c:
	/* 0x65c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_661:
	/* 0x661: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_664:
	/* 0x664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666:
	/* 0x666: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_669:
	/* 0x669: je     2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_66f:
	/* 0x66f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_672:
	/* 0x672: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_679:
	/* 0x679: lea    r12,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_67d:
	/* 0x67d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_682:
	/* 0x682: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_687:
	/* 0x687: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68c:
	/* 0x68c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_691:
	/* 0x691: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_69b:
	/* 0x69b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a0:
	/* 0x6a0: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a4:
	/* 0x6a4: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6a9:
	/* 0x6a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6ae:
	/* 0x6ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b3:
	/* 0x6b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b8:
	/* 0x6b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ba:
	/* 0x6ba: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6bf:
	/* 0x6bf: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6c3:
	/* 0x6c3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6c8:
	/* 0x6c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6cd:
	/* 0x6cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d2:
	/* 0x6d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d7:
	/* 0x6d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d9:
	/* 0x6d9: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6de:
	/* 0x6de: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e3:
	/* 0x6e3: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6e7:
	/* 0x6e7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ec:
	/* 0x6ec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6f1:
	/* 0x6f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f6:
	/* 0x6f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6fb:
	/* 0x6fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fd:
	/* 0x6fd: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_701:
	/* 0x701: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_704:
	/* 0x704: mov    QWORD PTR [rsp+0xc8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_70c:
	/* 0x70c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_710:
	/* 0x710: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_715:
	/* 0x715: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_71a:
	/* 0x71a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_71f:
	/* 0x71f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_724:
	/* 0x724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_729:
	/* 0x729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72b:
	/* 0x72b: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_730:
	/* 0x730: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_735:
	/* 0x735: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_73a:
	/* 0x73a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73f:
	/* 0x73f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_744:
	/* 0x744: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_74d:
	/* 0x74d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_751:
	/* 0x751: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_755:
	/* 0x755: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_759:
	/* 0x759: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_75e:
	/* 0x75e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_763:
	/* 0x763: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_768:
	/* 0x768: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_76d:
	/* 0x76d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76f:
	/* 0x76f: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_773:
	/* 0x773: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_776:
	/* 0x776: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_77b:
	/* 0x77b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_780:
	/* 0x780: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_785:
	/* 0x785: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78a:
	/* 0x78a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_78d:
	/* 0x78d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78f:
	/* 0x78f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_794:
	/* 0x794: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_798:
	/* 0x798: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_79d:
	/* 0x79d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a2:
	/* 0x7a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a7:
	/* 0x7a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b3:
	/* 0x7b3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b8:
	/* 0x7b8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7bd:
	/* 0x7bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c2:
	/* 0x7c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c7:
	/* 0x7c7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7ca:
	/* 0x7ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cc:
	/* 0x7cc: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7d0:
	/* 0x7d0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7d4:
	/* 0x7d4: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7d8:
	/* 0x7d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7dc:
	/* 0x7dc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7e1:
	/* 0x7e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7e6:
	/* 0x7e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7eb:
	/* 0x7eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f0:
	/* 0x7f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f2:
	/* 0x7f2: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7f6:
	/* 0x7f6: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f9:
	/* 0x7f9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7fe:
	/* 0x7fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_803:
	/* 0x803: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_808:
	/* 0x808: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_80d:
	/* 0x80d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_812:
	/* 0x812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_814:
	/* 0x814: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_819:
	/* 0x819: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_81e:
	/* 0x81e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_823:
	/* 0x823: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_828:
	/* 0x828: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82d:
	/* 0x82d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_830:
	/* 0x830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_832:
	/* 0x832: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_836:
	/* 0x836: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_83a:
	/* 0x83a: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_83e:
	/* 0x83e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_842:
	/* 0x842: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_847:
	/* 0x847: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_84c:
	/* 0x84c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_851:
	/* 0x851: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_856:
	/* 0x856: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_858:
	/* 0x858: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 2141ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2238ULL: goto x86_l_8be;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2248ULL: goto x86_l_8c8;
	case 2252ULL: goto x86_l_8cc;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2367ULL: goto x86_l_93f;
	case 2370ULL: goto x86_l_942;
	case 2372ULL: goto x86_l_944;
	case 2376ULL: goto x86_l_948;
	case 2380ULL: goto x86_l_94c;
	case 2384ULL: goto x86_l_950;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2410ULL: goto x86_l_96a;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2432ULL: goto x86_l_980;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2527ULL: goto x86_l_9df;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
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
	case 2698ULL: goto x86_l_a8a;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2712ULL: goto x86_l_a98;
	case 2716ULL: goto x86_l_a9c;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2764ULL: goto x86_l_acc;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2793ULL: goto x86_l_ae9;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2826ULL: goto x86_l_b0a;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2959ULL: goto x86_l_b8f;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3035ULL: goto x86_l_bdb;
	case 3039ULL: goto x86_l_bdf;
	case 3043ULL: goto x86_l_be3;
	case 3050ULL: goto x86_l_bea;
	case 3055ULL: goto x86_l_bef;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3076ULL: goto x86_l_c04;
	case 3079ULL: goto x86_l_c07;
	case 3082ULL: goto x86_l_c0a;
	case 3084ULL: goto x86_l_c0c;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3099ULL: goto x86_l_c1b;
	case 3105ULL: goto x86_l_c21;
	case 3116ULL: goto x86_l_c2c;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3148ULL: goto x86_l_c4c;
	case 3151ULL: goto x86_l_c4f;
	case 3153ULL: goto x86_l_c51;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3184ULL: goto x86_l_c70;
	case 3187ULL: goto x86_l_c73;
	case 3194ULL: goto x86_l_c7a;
	case 3198ULL: goto x86_l_c7e;
	case 3202ULL: goto x86_l_c82;
	case 3209ULL: goto x86_l_c89;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3238ULL: goto x86_l_ca6;
	case 3242ULL: goto x86_l_caa;
	case 3249ULL: goto x86_l_cb1;
	case 3253ULL: goto x86_l_cb5;
	case 3260ULL: goto x86_l_cbc;
	case 3267ULL: goto x86_l_cc3;
	case 3274ULL: goto x86_l_cca;
	case 3278ULL: goto x86_l_cce;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3295ULL: goto x86_l_cdf;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3313ULL: goto x86_l_cf1;
	case 3319ULL: goto x86_l_cf7;
	case 3328ULL: goto x86_l_d00;
	case 3337ULL: goto x86_l_d09;
	case 3346ULL: goto x86_l_d12;
	case 3355ULL: goto x86_l_d1b;
	case 3363ULL: goto x86_l_d23;
	case 3369ULL: goto x86_l_d29;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3420ULL: goto x86_l_d5c;
	case 3429ULL: goto x86_l_d65;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3492ULL: goto x86_l_da4;
	case 3494ULL: goto x86_l_da6;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3604ULL: goto x86_l_e14;
	case 3611ULL: goto x86_l_e1b;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	case 3625ULL: goto x86_l_e29;
	case 3628ULL: goto x86_l_e2c;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3645ULL: goto x86_l_e3d;
	case 3648ULL: goto x86_l_e40;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3660ULL: goto x86_l_e4c;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3689ULL: goto x86_l_e69;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3701ULL: goto x86_l_e75;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3711ULL: goto x86_l_e7f;
	case 3714ULL: goto x86_l_e82;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3727ULL: goto x86_l_e8f;
	case 3734ULL: goto x86_l_e96;
	case 3737ULL: goto x86_l_e99;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3793ULL: goto x86_l_ed1;
	case 3800ULL: goto x86_l_ed8;
	case 3808ULL: goto x86_l_ee0;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3827ULL: goto x86_l_ef3;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3859ULL: goto x86_l_f13;
	case 3862ULL: goto x86_l_f16;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	default: return 0xffffffffffffffffULL;
	}
x86_l_85d:
	/* 0x85d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_861:
	/* 0x861: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_866:
	/* 0x866: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_86b:
	/* 0x86b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_870:
	/* 0x870: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_875:
	/* 0x875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_877:
	/* 0x877: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_87a:
	/* 0x87a: mov    ebx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_87e:
	/* 0x87e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_883:
	/* 0x883: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_887:
	/* 0x887: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_88c:
	/* 0x88c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_891:
	/* 0x891: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_896:
	/* 0x896: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_89b:
	/* 0x89b: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8a0:
	/* 0x8a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a2:
	/* 0x8a2: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8a7:
	/* 0x8a7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8ac:
	/* 0x8ac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8b1:
	/* 0x8b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b6:
	/* 0x8b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8bb:
	/* 0x8bb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8be:
	/* 0x8be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c0:
	/* 0x8c0: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8c4:
	/* 0x8c4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8c8:
	/* 0x8c8: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8cc:
	/* 0x8cc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8d0:
	/* 0x8d0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0x8e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e6:
	/* 0x8e6: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8eb:
	/* 0x8eb: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8ef:
	/* 0x8ef: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f4:
	/* 0x8f4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f9:
	/* 0x8f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fe:
	/* 0x8fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_903:
	/* 0x903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_905:
	/* 0x905: cmp    ebx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 80ULL);
x86_l_909:
	/* 0x909: jne    973 <trace_ret_vfs_writev+0x973> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_973;
	}
x86_l_90b:
	/* 0x90b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_910:
	/* 0x910: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_915:
	/* 0x915: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91a:
	/* 0x91a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_91f:
	/* 0x91f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_924:
	/* 0x924: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_926:
	/* 0x926: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_92b:
	/* 0x92b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_930:
	/* 0x930: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_935:
	/* 0x935: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93a:
	/* 0x93a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_93f:
	/* 0x93f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_942:
	/* 0x942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_944:
	/* 0x944: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_948:
	/* 0x948: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_94c:
	/* 0x94c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_950:
	/* 0x950: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_954:
	/* 0x954: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_959:
	/* 0x959: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_95e:
	/* 0x95e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_963:
	/* 0x963: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_968:
	/* 0x968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96a:
	/* 0x96a: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_96e:
	/* 0x96e: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_973:
	/* 0x973: mov    DWORD PTR [r12+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_978:
	/* 0x978: mov    rbx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_980:
	/* 0x980: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_987:
	/* 0x987: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_98c:
	/* 0x98c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_991:
	/* 0x991: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_996:
	/* 0x996: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_99b:
	/* 0x99b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_99e:
	/* 0x99e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a0:
	/* 0x9a0: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9a5:
	/* 0x9a5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9a9:
	/* 0x9a9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ae:
	/* 0x9ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9b3:
	/* 0x9b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b8:
	/* 0x9b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bd:
	/* 0x9bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bf:
	/* 0x9bf: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c4:
	/* 0x9c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c9:
	/* 0x9c9: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9ce:
	/* 0x9ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d3:
	/* 0x9d3: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9d8:
	/* 0x9d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9dd:
	/* 0x9dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9df:
	/* 0x9df: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9e3:
	/* 0x9e3: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_9e8:
	/* 0x9e8: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_9ed:
	/* 0x9ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ef:
	/* 0x9ef: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f4:
	/* 0x9f4: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9f8:
	/* 0x9f8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9fd:
	/* 0x9fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a02:
	/* 0xa02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a07:
	/* 0xa07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0c:
	/* 0xa0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0e:
	/* 0xa0e: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a13:
	/* 0xa13: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a17:
	/* 0xa17: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a1c:
	/* 0xa1c: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a20:
	/* 0xa20: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a25:
	/* 0xa25: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a2a:
	/* 0xa2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a2f:
	/* 0xa2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a3b:
	/* 0xa3b: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a40:
	/* 0xa40: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a45:
	/* 0xa45: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a49:
	/* 0xa49: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a4e:
	/* 0xa4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a53:
	/* 0xa53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a58:
	/* 0xa58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a5d:
	/* 0xa5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5f:
	/* 0xa5f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a69:
	/* 0xa69: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0xa82: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_a87:
	/* 0xa87: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_a8a:
	/* 0xa8a: je     a90 <trace_ret_vfs_writev+0xa90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a90;
	}
x86_l_a8c:
	/* 0xa8c: or     BYTE PTR [rbx+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a90:
	/* 0xa90: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a98:
	/* 0xa98: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a9c:
	/* 0xa9c: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_aa4:
	/* 0xaa4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aa9:
	/* 0xaa9: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_aae:
	/* 0xaae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ab3:
	/* 0xab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab5:
	/* 0xab5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aba:
	/* 0xaba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_abf:
	/* 0xabf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ac4:
	/* 0xac4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ac9:
	/* 0xac9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ace:
	/* 0xace: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ad3:
	/* 0xad3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ad8:
	/* 0xad8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_add:
	/* 0xadd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ae2:
	/* 0xae2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae7:
	/* 0xae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae9:
	/* 0xae9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aee:
	/* 0xaee: lea    r15,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af3:
	/* 0xaf3: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afd:
	/* 0xafd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_b00:
	/* 0xb00: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b05:
	/* 0xb05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b07:
	/* 0xb07: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b0e:
	/* 0xb0e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b13:
	/* 0xb13: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b18:
	/* 0xb18: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b1d:
	/* 0xb1d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b20:
	/* 0xb20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b22:
	/* 0xb22: test   BYTE PTR [r13+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b27:
	/* 0xb27: je     2d3 <trace_ret_vfs_writev+0x2d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 723ULL;
	}
x86_l_b2d:
	/* 0xb2d: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b32:
	/* 0xb32: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b39:
	/* 0xb39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b3e:
	/* 0xb3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b43:
	/* 0xb43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b48:
	/* 0xb48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b4d:
	/* 0xb4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4f:
	/* 0xb4f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b54:
	/* 0xb54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b59:
	/* 0xb59: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b5e:
	/* 0xb5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b63:
	/* 0xb63: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b68:
	/* 0xb68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6d:
	/* 0xb6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6f:
	/* 0xb6f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b74:
	/* 0xb74: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b79:
	/* 0xb79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b7e:
	/* 0xb7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b83:
	/* 0xb83: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b88:
	/* 0xb88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b8d:
	/* 0xb8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8f:
	/* 0xb8f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b94:
	/* 0xb94: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b99:
	/* 0xb99: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b9e:
	/* 0xb9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba3:
	/* 0xba3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba8:
	/* 0xba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_baa:
	/* 0xbaa: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_baf:
	/* 0xbaf: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bb2:
	/* 0xbb2: je     bd5 <trace_ret_vfs_writev+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd5;
	}
x86_l_bb4:
	/* 0xbb4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bb8:
	/* 0xbb8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bbd:
	/* 0xbbd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bc2:
	/* 0xbc2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc7:
	/* 0xbc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bcc:
	/* 0xbcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bce:
	/* 0xbce: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bd3:
	/* 0xbd3: jmp    bd7 <trace_ret_vfs_writev+0xbd7> */
	goto x86_l_bd7;
x86_l_bd5:
	/* 0xbd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd7:
	/* 0xbd7: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bdf:
	/* 0xbdf: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be3:
	/* 0xbe3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_bea:
	/* 0xbea: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bef:
	/* 0xbef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf4:
	/* 0xbf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf6:
	/* 0xbf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf9:
	/* 0xbf9: je     c11 <trace_ret_vfs_writev+0xc11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c11;
	}
x86_l_bfb:
	/* 0xbfb: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_bfe:
	/* 0xbfe: mov    BYTE PTR [rbx+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c04:
	/* 0xc04: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c07:
	/* 0xc07: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c0a:
	/* 0xc0a: jne    c11 <trace_ret_vfs_writev+0xc11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c11;
	}
x86_l_c0c:
	/* 0xc0c: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c11:
	/* 0xc11: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c16:
	/* 0xc16: cmp    ax,WORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c1b:
	/* 0xc1b: jne    2315 <trace_ret_vfs_writev+0x2315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8981ULL;
	}
x86_l_c21:
	/* 0xc21: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c2c:
	/* 0xc2c: mov    DWORD PTR [rsp+0x50],0x2d1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597384401ULL);
x86_l_c34:
	/* 0xc34: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c39:
	/* 0xc39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c40:
	/* 0xc40: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c45:
	/* 0xc45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4a:
	/* 0xc4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4c:
	/* 0xc4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c4f:
	/* 0xc4f: je     cbc <trace_ret_vfs_writev+0xcbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cbc;
	}
x86_l_c51:
	/* 0xc51: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c54:
	/* 0xc54: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c59:
	/* 0xc59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c5e:
	/* 0xc5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c60:
	/* 0xc60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c63:
	/* 0xc63: je     cbc <trace_ret_vfs_writev+0xcbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cbc;
	}
x86_l_c65:
	/* 0xc65: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c69:
	/* 0xc69: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c70:
	/* 0xc70: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c73:
	/* 0xc73: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c7a:
	/* 0xc7a: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7e:
	/* 0xc7e: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c82:
	/* 0xc82: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_c89:
	/* 0xc89: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_c90:
	/* 0xc90: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c94:
	/* 0xc94: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_c9b:
	/* 0xc9b: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c9f:
	/* 0xc9f: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_ca6:
	/* 0xca6: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_caa:
	/* 0xcaa: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_cb1:
	/* 0xcb1: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cb5:
	/* 0xcb5: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_cbc:
	/* 0xcbc: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_cc3:
	/* 0xcc3: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cca:
	/* 0xcca: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cce:
	/* 0xcce: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_cd2:
	/* 0xcd2: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cd7:
	/* 0xcd7: mov    QWORD PTR [rsp+0xc8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_cdf:
	/* 0xcdf: jne    e04 <trace_ret_vfs_writev+0xe04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e04;
	}
x86_l_ce5:
	/* 0xce5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce7:
	/* 0xce7: and    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_cea:
	/* 0xcea: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cf1:
	/* 0xcf1: je     185b <trace_ret_vfs_writev+0x185b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6235ULL;
	}
x86_l_cf7:
	/* 0xcf7: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d00:
	/* 0xd00: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d09:
	/* 0xd09: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d12:
	/* 0xd12: cmp    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_d1b:
	/* 0xd1b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d23:
	/* 0xd23: je     10a2 <trace_ret_vfs_writev+0x10a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4258ULL;
	}
x86_l_d29:
	/* 0xd29: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d31:
	/* 0xd31: lea    r12,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d35:
	/* 0xd35: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d3a:
	/* 0xd3a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3f:
	/* 0xd3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d44:
	/* 0xd44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d49:
	/* 0xd49: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4e:
	/* 0xd4e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d53:
	/* 0xd53: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d5c:
	/* 0xd5c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_d65:
	/* 0xd65: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d69:
	/* 0xd69: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6e:
	/* 0xd6e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d73:
	/* 0xd73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d78:
	/* 0xd78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7d:
	/* 0xd7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7f:
	/* 0xd7f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d84:
	/* 0xd84: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d89:
	/* 0xd89: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_d8d:
	/* 0xd8d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d92:
	/* 0xd92: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d97:
	/* 0xd97: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d9c:
	/* 0xd9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_da1:
	/* 0xda1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_da4:
	/* 0xda4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da6:
	/* 0xda6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_daa:
	/* 0xdaa: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_daf:
	/* 0xdaf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db4:
	/* 0xdb4: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db9:
	/* 0xdb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dbe:
	/* 0xdbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dc3:
	/* 0xdc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dc8:
	/* 0xdc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dca:
	/* 0xdca: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcf:
	/* 0xdcf: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_dd2:
	/* 0xdd2: js     fdf <trace_ret_vfs_writev+0xfdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4063ULL;
	}
x86_l_dd8:
	/* 0xdd8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ddd:
	/* 0xddd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de2:
	/* 0xde2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dec:
	/* 0xdec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df1:
	/* 0xdf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df3:
	/* 0xdf3: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_dfa:
	/* 0xdfa: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_dff:
	/* 0xdff: jmp    fe1 <trace_ret_vfs_writev+0xfe1> */
	return 4065ULL;
x86_l_e04:
	/* 0xe04: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_e0b:
	/* 0xe0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: je     fc3 <trace_ret_vfs_writev+0xfc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4035ULL;
	}
x86_l_e14:
	/* 0xe14: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_e1b:
	/* 0xe1b: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_e1e:
	/* 0xe1e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e20:
	/* 0xe20: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_e23:
	/* 0xe23: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_e26:
	/* 0xe26: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e29:
	/* 0xe29: neg    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e2c:
	/* 0xe2c: xor    rbx,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_e33:
	/* 0xe33: or     rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e36:
	/* 0xe36: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e3d:
	/* 0xe3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e40:
	/* 0xe40: je     e69 <trace_ret_vfs_writev+0xe69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e69;
	}
x86_l_e42:
	/* 0xe42: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e44:
	/* 0xe44: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e4c:
	/* 0xe4c: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_e53:
	/* 0xe53: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_e56:
	/* 0xe56: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e59:
	/* 0xe59: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e5c:
	/* 0xe5c: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_e63:
	/* 0xe63: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e66:
	/* 0xe66: and    rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e69:
	/* 0xe69: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_e70:
	/* 0xe70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e73:
	/* 0xe73: je     e8f <trace_ret_vfs_writev+0xe8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8f;
	}
x86_l_e75:
	/* 0xe75: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_e79:
	/* 0xe79: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e7c:
	/* 0xe7c: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_e7f:
	/* 0xe7f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e82:
	/* 0xe82: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_e89:
	/* 0xe89: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e8c:
	/* 0xe8c: and    rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e8f:
	/* 0xe8f: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_e96:
	/* 0xe96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e99:
	/* 0xe99: je     eb7 <trace_ret_vfs_writev+0xeb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb7;
	}
x86_l_e9b:
	/* 0xe9b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e9e:
	/* 0xe9e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea3:
	/* 0xea3: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ea7:
	/* 0xea7: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_eaa:
	/* 0xeaa: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_eb1:
	/* 0xeb1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_eb4:
	/* 0xeb4: and    rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_eb7:
	/* 0xeb7: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ebc:
	/* 0xebc: mov    rbp,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_ec3:
	/* 0xec3: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ecb:
	/* 0xecb: je     1291 <trace_ret_vfs_writev+0x1291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4753ULL;
	}
x86_l_ed1:
	/* 0xed1: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_ed8:
	/* 0xed8: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ee0:
	/* 0xee0: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_ee7:
	/* 0xee7: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_eec:
	/* 0xeec: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_ef3:
	/* 0xef3: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_efb:
	/* 0xefb: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f00:
	/* 0xf00: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_f07:
	/* 0xf07: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f0c:
	/* 0xf0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f11:
	/* 0xf11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f13:
	/* 0xf13: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f16:
	/* 0xf16: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f1a:
	/* 0xf1a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f1f:
	/* 0xf1f: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f26:
	/* 0xf26: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f29:
	/* 0xf29: je     f4b <trace_ret_vfs_writev+0xf4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3915ULL;
	}
x86_l_f2b:
	/* 0xf2b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f30:
	/* 0xf30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f35:
	/* 0xf35: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
	return 3896ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3906ULL: goto x86_l_f42;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3939ULL: goto x86_l_f63;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3953ULL: goto x86_l_f71;
	case 3955ULL: goto x86_l_f73;
	case 3963ULL: goto x86_l_f7b;
	case 3966ULL: goto x86_l_f7e;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4023ULL: goto x86_l_fb7;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4042ULL: goto x86_l_fca;
	case 4049ULL: goto x86_l_fd1;
	case 4052ULL: goto x86_l_fd4;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4093ULL: goto x86_l_ffd;
	case 4095ULL: goto x86_l_fff;
	case 4100ULL: goto x86_l_1004;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4124ULL: goto x86_l_101c;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4167ULL: goto x86_l_1047;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4233ULL: goto x86_l_1089;
	case 4238ULL: goto x86_l_108e;
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4258ULL: goto x86_l_10a2;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4277ULL: goto x86_l_10b5;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4289ULL: goto x86_l_10c1;
	case 4297ULL: goto x86_l_10c9;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4336ULL: goto x86_l_10f0;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4410ULL: goto x86_l_113a;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4445ULL: goto x86_l_115d;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4503ULL: goto x86_l_1197;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4519ULL: goto x86_l_11a7;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4606ULL: goto x86_l_11fe;
	case 4612ULL: goto x86_l_1204;
	case 4614ULL: goto x86_l_1206;
	case 4616ULL: goto x86_l_1208;
	case 4622ULL: goto x86_l_120e;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4635ULL: goto x86_l_121b;
	case 4641ULL: goto x86_l_1221;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4696ULL: goto x86_l_1258;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4753ULL: goto x86_l_1291;
	case 4761ULL: goto x86_l_1299;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4774ULL: goto x86_l_12a6;
	case 4778ULL: goto x86_l_12aa;
	case 4785ULL: goto x86_l_12b1;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4804ULL: goto x86_l_12c4;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4821ULL: goto x86_l_12d5;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4838ULL: goto x86_l_12e6;
	case 4840ULL: goto x86_l_12e8;
	case 4843ULL: goto x86_l_12eb;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4876ULL: goto x86_l_130c;
	case 4879ULL: goto x86_l_130f;
	case 4881ULL: goto x86_l_1311;
	case 4884ULL: goto x86_l_1314;
	case 4888ULL: goto x86_l_1318;
	case 4891ULL: goto x86_l_131b;
	case 4893ULL: goto x86_l_131d;
	case 4895ULL: goto x86_l_131f;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4931ULL: goto x86_l_1343;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4965ULL: goto x86_l_1365;
	case 4968ULL: goto x86_l_1368;
	case 4976ULL: goto x86_l_1370;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5083ULL: goto x86_l_13db;
	case 5087ULL: goto x86_l_13df;
	case 5094ULL: goto x86_l_13e6;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5166ULL: goto x86_l_142e;
	case 5169ULL: goto x86_l_1431;
	case 5171ULL: goto x86_l_1433;
	case 5173ULL: goto x86_l_1435;
	case 5176ULL: goto x86_l_1438;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5185ULL: goto x86_l_1441;
	case 5193ULL: goto x86_l_1449;
	case 5199ULL: goto x86_l_144f;
	case 5206ULL: goto x86_l_1456;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5266ULL: goto x86_l_1492;
	case 5270ULL: goto x86_l_1496;
	case 5274ULL: goto x86_l_149a;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5335ULL: goto x86_l_14d7;
	case 5339ULL: goto x86_l_14db;
	case 5346ULL: goto x86_l_14e2;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5378ULL: goto x86_l_1502;
	case 5380ULL: goto x86_l_1504;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5414ULL: goto x86_l_1526;
	case 5418ULL: goto x86_l_152a;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5437ULL: goto x86_l_153d;
	case 5445ULL: goto x86_l_1545;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5512ULL: goto x86_l_1588;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5535ULL: goto x86_l_159f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f38:
	/* 0xf38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3a:
	/* 0xf3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f3d:
	/* 0xf3d: je     f4b <trace_ret_vfs_writev+0xf4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f4b;
	}
x86_l_f3f:
	/* 0xf3f: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f42:
	/* 0xf42: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f46:
	/* 0xf46: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f49:
	/* 0xf49: jmp    f4e <trace_ret_vfs_writev+0xf4e> */
	goto x86_l_f4e;
x86_l_f4b:
	/* 0xf4b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4e:
	/* 0xf4e: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_f56:
	/* 0xf56: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f5b:
	/* 0xf5b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f60:
	/* 0xf60: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f63:
	/* 0xf63: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f66:
	/* 0xf66: jb     f7e <trace_ret_vfs_writev+0xf7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f7e;
	}
x86_l_f68:
	/* 0xf68: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f6c:
	/* 0xf6c: je     f73 <trace_ret_vfs_writev+0xf73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f73;
	}
x86_l_f6e:
	/* 0xf6e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f71:
	/* 0xf71: jbe    f7e <trace_ret_vfs_writev+0xf7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f7e;
	}
x86_l_f73:
	/* 0xf73: and    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 216ULL);
x86_l_f7b:
	/* 0xf7b: or     r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_f7e:
	/* 0xf7e: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f82:
	/* 0xf82: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f87:
	/* 0xf87: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f8e:
	/* 0xf8e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f91:
	/* 0xf91: je     1245 <trace_ret_vfs_writev+0x1245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1245;
	}
x86_l_f97:
	/* 0xf97: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f9c:
	/* 0xf9c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fa1:
	/* 0xfa1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa6:
	/* 0xfa6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fab:
	/* 0xfab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: je     1256 <trace_ret_vfs_writev+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1256;
	}
x86_l_fb4:
	/* 0xfb4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb7:
	/* 0xfb7: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fbb:
	/* 0xfbb: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fbe:
	/* 0xfbe: jmp    1258 <trace_ret_vfs_writev+0x1258> */
	goto x86_l_1258;
x86_l_fc3:
	/* 0xfc3: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fca:
	/* 0xfca: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_fd1:
	/* 0xfd1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd4:
	/* 0xfd4: jne    e42 <trace_ret_vfs_writev+0xe42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3650ULL;
	}
x86_l_fda:
	/* 0xfda: jmp    e69 <trace_ret_vfs_writev+0xe69> */
	return 3689ULL;
x86_l_fdf:
	/* 0xfdf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fe1:
	/* 0xfe1: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fe6:
	/* 0xfe6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_feb:
	/* 0xfeb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ff0:
	/* 0xff0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff5:
	/* 0xff5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ffa:
	/* 0xffa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ffd:
	/* 0xffd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fff:
	/* 0xfff: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1004:
	/* 0x1004: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1008:
	/* 0x1008: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100d:
	/* 0x100d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1012:
	/* 0x1012: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1017:
	/* 0x1017: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101c:
	/* 0x101c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1020:
	/* 0x1020: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1025:
	/* 0x1025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1027:
	/* 0x1027: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_102c:
	/* 0x102c: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1031:
	/* 0x1031: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1036:
	/* 0x1036: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_103b:
	/* 0x103b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1040:
	/* 0x1040: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1045:
	/* 0x1045: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1047:
	/* 0x1047: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_104b:
	/* 0x104b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_104f:
	/* 0x104f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1054:
	/* 0x1054: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1059:
	/* 0x1059: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105e:
	/* 0x105e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1063:
	/* 0x1063: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1066:
	/* 0x1066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1068:
	/* 0x1068: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106d:
	/* 0x106d: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1071:
	/* 0x1071: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1076:
	/* 0x1076: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_107b:
	/* 0x107b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1080:
	/* 0x1080: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1085:
	/* 0x1085: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1089:
	/* 0x1089: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_108e:
	/* 0x108e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1090:
	/* 0x1090: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1095:
	/* 0x1095: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_109a:
	/* 0x109a: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10a2:
	/* 0x10a2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_10a9:
	/* 0x10a9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10ae:
	/* 0x10ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b3:
	/* 0x10b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b5:
	/* 0x10b5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_10b8:
	/* 0x10b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10bb:
	/* 0x10bb: jne    1b9e <trace_ret_vfs_writev+0x1b9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7070ULL;
	}
x86_l_10c1:
	/* 0x10c1: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10c9:
	/* 0x10c9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_10d0:
	/* 0x10d0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10d5:
	/* 0x10d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10da:
	/* 0x10da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10dc:
	/* 0x10dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10df:
	/* 0x10df: je     1b9b <trace_ret_vfs_writev+0x1b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7067ULL;
	}
x86_l_10e5:
	/* 0x10e5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_10e8:
	/* 0x10e8: mov    r15,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_10f0:
	/* 0x10f0: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f4:
	/* 0x10f4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10f9:
	/* 0x10f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10fe:
	/* 0x10fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1103:
	/* 0x1103: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1108:
	/* 0x1108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110a:
	/* 0x110a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_110f:
	/* 0x110f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1114:
	/* 0x1114: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1119:
	/* 0x1119: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_111e:
	/* 0x111e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1123:
	/* 0x1123: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1128:
	/* 0x1128: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_112d:
	/* 0x112d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112f:
	/* 0x112f: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_1134:
	/* 0x1134: jne    1868 <trace_ret_vfs_writev+0x1868> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6248ULL;
	}
x86_l_113a:
	/* 0x113a: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113e:
	/* 0x113e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1143:
	/* 0x1143: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1148:
	/* 0x1148: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_114d:
	/* 0x114d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1152:
	/* 0x1152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1154:
	/* 0x1154: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1159:
	/* 0x1159: lea    rcx,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_115d:
	/* 0x115d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1161:
	/* 0x1161: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1166:
	/* 0x1166: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_116b:
	/* 0x116b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1170:
	/* 0x1170: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1174:
	/* 0x1174: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1179:
	/* 0x1179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117b:
	/* 0x117b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x118f: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1194:
	/* 0x1194: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1197:
	/* 0x1197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1199:
	/* 0x1199: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_119e:
	/* 0x119e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a3:
	/* 0x11a3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_11a7:
	/* 0x11a7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ac:
	/* 0x11ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11b1:
	/* 0x11b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11b6:
	/* 0x11b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11bb:
	/* 0x11bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bd:
	/* 0x11bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11c2:
	/* 0x11c2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: je     188a <trace_ret_vfs_writev+0x188a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6282ULL;
	}
x86_l_11cb:
	/* 0x11cb: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11d0:
	/* 0x11d0: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11d3:
	/* 0x11d3: je     188a <trace_ret_vfs_writev+0x188a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6282ULL;
	}
x86_l_11d9:
	/* 0x11d9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11dd:
	/* 0x11dd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e2:
	/* 0x11e2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_11e7:
	/* 0x11e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ec:
	/* 0x11ec: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11f1:
	/* 0x11f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f3:
	/* 0x11f3: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11f7:
	/* 0x11f7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11fc:
	/* 0x11fc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11fe:
	/* 0x11fe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1204:
	/* 0x1204: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1206:
	/* 0x1206: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1208:
	/* 0x1208: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_120e:
	/* 0x120e: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1211:
	/* 0x1211: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1216:
	/* 0x1216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1218:
	/* 0x1218: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_121b:
	/* 0x121b: jl     1a01 <trace_ret_vfs_writev+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6657ULL;
	}
x86_l_1221:
	/* 0x1221: mov    BYTE PTR [r12+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_122a:
	/* 0x122a: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_122f:
	/* 0x122f: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1231:
	/* 0x1231: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1236:
	/* 0x1236: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_123b:
	/* 0x123b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1240:
	/* 0x1240: jmp    1910 <trace_ret_vfs_writev+0x1910> */
	return 6416ULL;
x86_l_1245:
	/* 0x1245: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1247:
	/* 0x1247: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_124a:
	/* 0x124a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_124f:
	/* 0x124f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1252:
	/* 0x1252: jae    1272 <trace_ret_vfs_writev+0x1272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1272;
	}
x86_l_1254:
	/* 0x1254: jmp    1288 <trace_ret_vfs_writev+0x1288> */
	goto x86_l_1288;
x86_l_1256:
	/* 0x1256: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1258:
	/* 0x1258: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1260:
	/* 0x1260: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1265:
	/* 0x1265: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1268:
	/* 0x1268: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_126d:
	/* 0x126d: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1270:
	/* 0x1270: jb     1288 <trace_ret_vfs_writev+0x1288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1288;
	}
x86_l_1272:
	/* 0x1272: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1276:
	/* 0x1276: je     127d <trace_ret_vfs_writev+0x127d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127d;
	}
x86_l_1278:
	/* 0x1278: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: jbe    1288 <trace_ret_vfs_writev+0x1288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1288;
	}
x86_l_127d:
	/* 0x127d: and    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 216ULL);
x86_l_1285:
	/* 0x1285: or     rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_1288:
	/* 0x1288: or     r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_128b:
	/* 0x128b: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_128e:
	/* 0x128e: and    rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1291:
	/* 0x1291: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1299:
	/* 0x1299: je     1336 <trace_ret_vfs_writev+0x1336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1336;
	}
x86_l_129f:
	/* 0x129f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_12a4:
	/* 0x12a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a6:
	/* 0x12a6: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12aa:
	/* 0x12aa: mov    r15,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_12b1:
	/* 0x12b1: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_12b8:
	/* 0x12b8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12bd:
	/* 0x12bd: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_12c4:
	/* 0x12c4: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_12cb:
	/* 0x12cb: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_12d0:
	/* 0x12d0: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12d5:
	/* 0x12d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_12dc:
	/* 0x12dc: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12e1:
	/* 0x12e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e6:
	/* 0x12e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e8:
	/* 0x12e8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12eb:
	/* 0x12eb: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ef:
	/* 0x12ef: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12f4:
	/* 0x12f4: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12fb:
	/* 0x12fb: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_12fe:
	/* 0x12fe: je     131d <trace_ret_vfs_writev+0x131d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131d;
	}
x86_l_1300:
	/* 0x1300: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1305:
	/* 0x1305: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130a:
	/* 0x130a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130c:
	/* 0x130c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_130f:
	/* 0x130f: je     131d <trace_ret_vfs_writev+0x131d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131d;
	}
x86_l_1311:
	/* 0x1311: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1314:
	/* 0x1314: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1318:
	/* 0x1318: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_131b:
	/* 0x131b: jmp    131f <trace_ret_vfs_writev+0x131f> */
	goto x86_l_131f;
x86_l_131d:
	/* 0x131d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131f:
	/* 0x131f: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1322:
	/* 0x1322: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1327:
	/* 0x1327: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_132a:
	/* 0x132a: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_132d:
	/* 0x132d: jae    134a <trace_ret_vfs_writev+0x134a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_134a;
	}
x86_l_132f:
	/* 0x132f: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_1334:
	/* 0x1334: jmp    1362 <trace_ret_vfs_writev+0x1362> */
	goto x86_l_1362;
x86_l_1336:
	/* 0x1336: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_133b:
	/* 0x133b: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1343:
	/* 0x1343: jne    1376 <trace_ret_vfs_writev+0x1376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1376;
	}
x86_l_1345:
	/* 0x1345: jmp    1441 <trace_ret_vfs_writev+0x1441> */
	goto x86_l_1441;
x86_l_134a:
	/* 0x134a: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_134e:
	/* 0x134e: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_1353:
	/* 0x1353: je     135a <trace_ret_vfs_writev+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135a;
	}
x86_l_1355:
	/* 0x1355: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1358:
	/* 0x1358: jbe    1362 <trace_ret_vfs_writev+0x1362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1362;
	}
x86_l_135a:
	/* 0x135a: and    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 72ULL);
x86_l_135f:
	/* 0x135f: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_1362:
	/* 0x1362: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1365:
	/* 0x1365: and    rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1368:
	/* 0x1368: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1370:
	/* 0x1370: je     1441 <trace_ret_vfs_writev+0x1441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1441;
	}
x86_l_1376:
	/* 0x1376: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_137b:
	/* 0x137b: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1382:
	/* 0x1382: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1387:
	/* 0x1387: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_138c:
	/* 0x138c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1391:
	/* 0x1391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1396:
	/* 0x1396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1398:
	/* 0x1398: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_139d:
	/* 0x139d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13a1:
	/* 0x13a1: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13a6:
	/* 0x13a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13ab:
	/* 0x13ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13b0:
	/* 0x13b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b5:
	/* 0x13b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b7:
	/* 0x13b7: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13bc:
	/* 0x13bc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c1:
	/* 0x13c1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_13c6:
	/* 0x13c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13cb:
	/* 0x13cb: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13d0:
	/* 0x13d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13d5:
	/* 0x13d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d7:
	/* 0x13d7: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13db:
	/* 0x13db: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13df:
	/* 0x13df: mov    r15,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_13e6:
	/* 0x13e6: mov    r12,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_13ed:
	/* 0x13ed: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13f2:
	/* 0x13f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_13f9:
	/* 0x13f9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13fe:
	/* 0x13fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1403:
	/* 0x1403: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1406:
	/* 0x1406: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1408:
	/* 0x1408: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_140f:
	/* 0x140f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1412:
	/* 0x1412: je     1433 <trace_ret_vfs_writev+0x1433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1433;
	}
x86_l_1414:
	/* 0x1414: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1417:
	/* 0x1417: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_141b:
	/* 0x141b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1420:
	/* 0x1420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1422:
	/* 0x1422: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1425:
	/* 0x1425: je     1433 <trace_ret_vfs_writev+0x1433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1433;
	}
x86_l_1427:
	/* 0x1427: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142a:
	/* 0x142a: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142e:
	/* 0x142e: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1431:
	/* 0x1431: jmp    1435 <trace_ret_vfs_writev+0x1435> */
	goto x86_l_1435;
x86_l_1433:
	/* 0x1433: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1435:
	/* 0x1435: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1438:
	/* 0x1438: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_143b:
	/* 0x143b: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_143e:
	/* 0x143e: and    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1441:
	/* 0x1441: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1449:
	/* 0x1449: je     153d <trace_ret_vfs_writev+0x153d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_153d;
	}
x86_l_144f:
	/* 0x144f: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1456:
	/* 0x1456: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_145a:
	/* 0x145a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_145f:
	/* 0x145f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1464:
	/* 0x1464: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1469:
	/* 0x1469: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_146e:
	/* 0x146e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1470:
	/* 0x1470: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1475:
	/* 0x1475: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_147a:
	/* 0x147a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_147f:
	/* 0x147f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1484:
	/* 0x1484: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1489:
	/* 0x1489: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_148c:
	/* 0x148c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148e:
	/* 0x148e: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1492:
	/* 0x1492: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1496:
	/* 0x1496: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_149a:
	/* 0x149a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_149e:
	/* 0x149e: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14a3:
	/* 0x14a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14a8:
	/* 0x14a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14ad:
	/* 0x14ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b2:
	/* 0x14b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b4:
	/* 0x14b4: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14b9:
	/* 0x14b9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_14bd:
	/* 0x14bd: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14c2:
	/* 0x14c2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14c7:
	/* 0x14c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14cc:
	/* 0x14cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14d7:
	/* 0x14d7: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14db:
	/* 0x14db: mov    r15,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_14e2:
	/* 0x14e2: mov    r12,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_14e9:
	/* 0x14e9: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14ee:
	/* 0x14ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_14f5:
	/* 0x14f5: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14fa:
	/* 0x14fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ff:
	/* 0x14ff: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1502:
	/* 0x1502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1504:
	/* 0x1504: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_150b:
	/* 0x150b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: je     152f <trace_ret_vfs_writev+0x152f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152f;
	}
x86_l_1510:
	/* 0x1510: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1517:
	/* 0x1517: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_151c:
	/* 0x151c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151e:
	/* 0x151e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1521:
	/* 0x1521: je     152f <trace_ret_vfs_writev+0x152f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152f;
	}
x86_l_1523:
	/* 0x1523: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1526:
	/* 0x1526: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_152a:
	/* 0x152a: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_152d:
	/* 0x152d: jmp    1531 <trace_ret_vfs_writev+0x1531> */
	goto x86_l_1531;
x86_l_152f:
	/* 0x152f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1531:
	/* 0x1531: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1534:
	/* 0x1534: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1537:
	/* 0x1537: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_153a:
	/* 0x153a: and    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_153d:
	/* 0x153d: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1545:
	/* 0x1545: je     1627 <trace_ret_vfs_writev+0x1627> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5671ULL;
	}
x86_l_154b:
	/* 0x154b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1550:
	/* 0x1550: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1557:
	/* 0x1557: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_155c:
	/* 0x155c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1561:
	/* 0x1561: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1566:
	/* 0x1566: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_156b:
	/* 0x156b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156d:
	/* 0x156d: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1572:
	/* 0x1572: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1577:
	/* 0x1577: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_157c:
	/* 0x157c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1581:
	/* 0x1581: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1586:
	/* 0x1586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1588:
	/* 0x1588: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_158d:
	/* 0x158d: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1592:
	/* 0x1592: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1597:
	/* 0x1597: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_159c:
	/* 0x159c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_159f:
	/* 0x159f: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
	return 5540ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5567ULL: goto x86_l_15bf;
	case 5569ULL: goto x86_l_15c1;
	case 5576ULL: goto x86_l_15c8;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5593ULL: goto x86_l_15d9;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5615ULL: goto x86_l_15ef;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5659ULL: goto x86_l_161b;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5690ULL: goto x86_l_163a;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5714ULL: goto x86_l_1652;
	case 5721ULL: goto x86_l_1659;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5762ULL: goto x86_l_1682;
	case 5765ULL: goto x86_l_1685;
	case 5767ULL: goto x86_l_1687;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5792ULL: goto x86_l_16a0;
	case 5795ULL: goto x86_l_16a3;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5870ULL: goto x86_l_16ee;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5882ULL: goto x86_l_16fa;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5897ULL: goto x86_l_1709;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5909ULL: goto x86_l_1715;
	case 5912ULL: goto x86_l_1718;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5919ULL: goto x86_l_171f;
	case 5922ULL: goto x86_l_1722;
	case 5925ULL: goto x86_l_1725;
	case 5928ULL: goto x86_l_1728;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5940ULL: goto x86_l_1734;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5959ULL: goto x86_l_1747;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5972ULL: goto x86_l_1754;
	case 5974ULL: goto x86_l_1756;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5986ULL: goto x86_l_1762;
	case 5989ULL: goto x86_l_1765;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6000ULL: goto x86_l_1770;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6008ULL: goto x86_l_1778;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6031ULL: goto x86_l_178f;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6043ULL: goto x86_l_179b;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6075ULL: goto x86_l_17bb;
	case 6077ULL: goto x86_l_17bd;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6089ULL: goto x86_l_17c9;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6109ULL: goto x86_l_17dd;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6133ULL: goto x86_l_17f5;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6140ULL: goto x86_l_17fc;
	case 6143ULL: goto x86_l_17ff;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6163ULL: goto x86_l_1813;
	case 6166ULL: goto x86_l_1816;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6212ULL: goto x86_l_1844;
	case 6219ULL: goto x86_l_184b;
	case 6222ULL: goto x86_l_184e;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6255ULL: goto x86_l_186f;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6340ULL: goto x86_l_18c4;
	case 6344ULL: goto x86_l_18c8;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6361ULL: goto x86_l_18d9;
	case 6366ULL: goto x86_l_18de;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6402ULL: goto x86_l_1902;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6439ULL: goto x86_l_1927;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6499ULL: goto x86_l_1963;
	case 6505ULL: goto x86_l_1969;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6529ULL: goto x86_l_1981;
	case 6531ULL: goto x86_l_1983;
	case 6535ULL: goto x86_l_1987;
	case 6537ULL: goto x86_l_1989;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6550ULL: goto x86_l_1996;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6651ULL: goto x86_l_19fb;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6715ULL: goto x86_l_1a3b;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6742ULL: goto x86_l_1a56;
	case 6744ULL: goto x86_l_1a58;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6767ULL: goto x86_l_1a6f;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6806ULL: goto x86_l_1a96;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6836ULL: goto x86_l_1ab4;
	case 6840ULL: goto x86_l_1ab8;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6933ULL: goto x86_l_1b15;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6959ULL: goto x86_l_1b2f;
	case 6963ULL: goto x86_l_1b33;
	case 6965ULL: goto x86_l_1b35;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6980ULL: goto x86_l_1b44;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7005ULL: goto x86_l_1b5d;
	case 7014ULL: goto x86_l_1b66;
	case 7020ULL: goto x86_l_1b6c;
	case 7028ULL: goto x86_l_1b74;
	case 7030ULL: goto x86_l_1b76;
	case 7036ULL: goto x86_l_1b7c;
	case 7039ULL: goto x86_l_1b7f;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7061ULL: goto x86_l_1b95;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15a4:
	/* 0x15a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a6:
	/* 0x15a6: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_15aa:
	/* 0x15aa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_15af:
	/* 0x15af: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_15b4:
	/* 0x15b4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_15b7:
	/* 0x15b7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_15bc:
	/* 0x15bc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_15bf:
	/* 0x15bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c1:
	/* 0x15c1: mov    r12,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_15c8:
	/* 0x15c8: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_15cf:
	/* 0x15cf: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_15d4:
	/* 0x15d4: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15d9:
	/* 0x15d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_15e0:
	/* 0x15e0: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ea:
	/* 0x15ea: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15ed:
	/* 0x15ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ef:
	/* 0x15ef: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15f6:
	/* 0x15f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f9:
	/* 0x15f9: je     1619 <trace_ret_vfs_writev+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1619;
	}
x86_l_15fb:
	/* 0x15fb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1603:
	/* 0x1603: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1606:
	/* 0x1606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1608:
	/* 0x1608: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: je     1619 <trace_ret_vfs_writev+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1619;
	}
x86_l_160d:
	/* 0x160d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1610:
	/* 0x1610: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1614:
	/* 0x1614: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1617:
	/* 0x1617: jmp    161b <trace_ret_vfs_writev+0x161b> */
	goto x86_l_161b;
x86_l_1619:
	/* 0x1619: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161b:
	/* 0x161b: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_161e:
	/* 0x161e: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1621:
	/* 0x1621: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_1624:
	/* 0x1624: and    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1627:
	/* 0x1627: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_162f:
	/* 0x162f: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_1634:
	/* 0x1634: je     16b8 <trace_ret_vfs_writev+0x16b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b8;
	}
x86_l_163a:
	/* 0x163a: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_163e:
	/* 0x163e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1643:
	/* 0x1643: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1648:
	/* 0x1648: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_164b:
	/* 0x164b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1650:
	/* 0x1650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1652:
	/* 0x1652: mov    r12,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1659:
	/* 0x1659: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1660:
	/* 0x1660: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1665:
	/* 0x1665: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_166c:
	/* 0x166c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1671:
	/* 0x1671: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1676:
	/* 0x1676: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1679:
	/* 0x1679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167b:
	/* 0x167b: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1682:
	/* 0x1682: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1685:
	/* 0x1685: je     16a5 <trace_ret_vfs_writev+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16a5;
	}
x86_l_1687:
	/* 0x1687: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_168a:
	/* 0x168a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_168f:
	/* 0x168f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1692:
	/* 0x1692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1694:
	/* 0x1694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1697:
	/* 0x1697: je     16a5 <trace_ret_vfs_writev+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16a5;
	}
x86_l_1699:
	/* 0x1699: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169c:
	/* 0x169c: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a0:
	/* 0x16a0: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16a3:
	/* 0x16a3: jmp    16a7 <trace_ret_vfs_writev+0x16a7> */
	goto x86_l_16a7;
x86_l_16a5:
	/* 0x16a5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a7:
	/* 0x16a7: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16aa:
	/* 0x16aa: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_16ad:
	/* 0x16ad: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_16b0:
	/* 0x16b0: and    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_16b3:
	/* 0x16b3: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_16b8:
	/* 0x16b8: mov    r15,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_16bf:
	/* 0x16bf: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_16c2:
	/* 0x16c2: je     1728 <trace_ret_vfs_writev+0x1728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1728;
	}
x86_l_16c4:
	/* 0x16c4: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16c8:
	/* 0x16c8: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16cc:
	/* 0x16cc: mov    r12,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_16d3:
	/* 0x16d3: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d8:
	/* 0x16d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_16df:
	/* 0x16df: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e4:
	/* 0x16e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e9:
	/* 0x16e9: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16ec:
	/* 0x16ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ee:
	/* 0x16ee: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_16f5:
	/* 0x16f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f8:
	/* 0x16f8: je     171a <trace_ret_vfs_writev+0x171a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_171a;
	}
x86_l_16fa:
	/* 0x16fa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16fd:
	/* 0x16fd: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1702:
	/* 0x1702: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1707:
	/* 0x1707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1709:
	/* 0x1709: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170c:
	/* 0x170c: je     171a <trace_ret_vfs_writev+0x171a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_171a;
	}
x86_l_170e:
	/* 0x170e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1711:
	/* 0x1711: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1715:
	/* 0x1715: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1718:
	/* 0x1718: jmp    171c <trace_ret_vfs_writev+0x171c> */
	goto x86_l_171c;
x86_l_171a:
	/* 0x171a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171c:
	/* 0x171c: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_171f:
	/* 0x171f: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1722:
	/* 0x1722: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1725:
	/* 0x1725: and    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1728:
	/* 0x1728: mov    r15,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_172f:
	/* 0x172f: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1732:
	/* 0x1732: je     178f <trace_ret_vfs_writev+0x178f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_178f;
	}
x86_l_1734:
	/* 0x1734: mov    r12,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_173b:
	/* 0x173b: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1740:
	/* 0x1740: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1747:
	/* 0x1747: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_174c:
	/* 0x174c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1751:
	/* 0x1751: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1754:
	/* 0x1754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1756:
	/* 0x1756: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_175d:
	/* 0x175d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1760:
	/* 0x1760: je     1781 <trace_ret_vfs_writev+0x1781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1781;
	}
x86_l_1762:
	/* 0x1762: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1765:
	/* 0x1765: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1769:
	/* 0x1769: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_176e:
	/* 0x176e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1770:
	/* 0x1770: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1773:
	/* 0x1773: je     1781 <trace_ret_vfs_writev+0x1781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1781;
	}
x86_l_1775:
	/* 0x1775: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1778:
	/* 0x1778: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177c:
	/* 0x177c: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_177f:
	/* 0x177f: jmp    1783 <trace_ret_vfs_writev+0x1783> */
	goto x86_l_1783;
x86_l_1781:
	/* 0x1781: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1783:
	/* 0x1783: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1786:
	/* 0x1786: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1789:
	/* 0x1789: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_178c:
	/* 0x178c: and    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_178f:
	/* 0x178f: mov    r12,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1796:
	/* 0x1796: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1799:
	/* 0x1799: je     1816 <trace_ret_vfs_writev+0x1816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1816;
	}
x86_l_179b:
	/* 0x179b: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_17a2:
	/* 0x17a2: mov    WORD PTR [rsp+0x50],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17a7:
	/* 0x17a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_17ae:
	/* 0x17ae: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17b3:
	/* 0x17b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17b8:
	/* 0x17b8: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17bb:
	/* 0x17bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bd:
	/* 0x17bd: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17c4:
	/* 0x17c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17c7:
	/* 0x17c7: je     1808 <trace_ret_vfs_writev+0x1808> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1808;
	}
x86_l_17c9:
	/* 0x17c9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_17cc:
	/* 0x17cc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d1:
	/* 0x17d1: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17d5:
	/* 0x17d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17da:
	/* 0x17da: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_17dd:
	/* 0x17dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17df:
	/* 0x17df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17e2:
	/* 0x17e2: jne    17fc <trace_ret_vfs_writev+0x17fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17fc;
	}
x86_l_17e4:
	/* 0x17e4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e9:
	/* 0x17e9: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ed:
	/* 0x17ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f2:
	/* 0x17f2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_17f5:
	/* 0x17f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f7:
	/* 0x17f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17fa:
	/* 0x17fa: je     1808 <trace_ret_vfs_writev+0x1808> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1808;
	}
x86_l_17fc:
	/* 0x17fc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ff:
	/* 0x17ff: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1803:
	/* 0x1803: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1806:
	/* 0x1806: jmp    180a <trace_ret_vfs_writev+0x180a> */
	goto x86_l_180a;
x86_l_1808:
	/* 0x1808: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180a:
	/* 0x180a: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_180d:
	/* 0x180d: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1810:
	/* 0x1810: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1813:
	/* 0x1813: and    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1816:
	/* 0x1816: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_181d:
	/* 0x181d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1820:
	/* 0x1820: movabs rbp,0x2d100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 3096671420416ULL);
x86_l_182a:
	/* 0x182a: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_182f:
	/* 0x182f: je     183d <trace_ret_vfs_writev+0x183d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183d;
	}
x86_l_1831:
	/* 0x1831: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1836:
	/* 0x1836: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_183a:
	/* 0x183a: or     rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_183d:
	/* 0x183d: and    rbx,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1844:
	/* 0x1844: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_184b:
	/* 0x184b: and    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_184e:
	/* 0x184e: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1855:
	/* 0x1855: jne    cf7 <trace_ret_vfs_writev+0xcf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3319ULL;
	}
x86_l_185b:
	/* 0x185b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1863:
	/* 0x1863: jmp    2008 <trace_ret_vfs_writev+0x2008> */
	return 8200ULL;
x86_l_1868:
	/* 0x1868: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_186f:
	/* 0x186f: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1874:
	/* 0x1874: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1879:
	/* 0x1879: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_187c:
	/* 0x187c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1881:
	/* 0x1881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1883:
	/* 0x1883: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1885:
	/* 0x1885: jmp    1b76 <trace_ret_vfs_writev+0x1b76> */
	goto x86_l_1b76;
x86_l_188a:
	/* 0x188a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_188d:
	/* 0x188d: jne    1a01 <trace_ret_vfs_writev+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a01;
	}
x86_l_1893:
	/* 0x1893: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1897:
	/* 0x1897: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_189c:
	/* 0x189c: je     1a01 <trace_ret_vfs_writev+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a01;
	}
x86_l_18a2:
	/* 0x18a2: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18a6:
	/* 0x18a6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ab:
	/* 0x18ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b0:
	/* 0x18b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18b5:
	/* 0x18b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b9:
	/* 0x18b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18bd:
	/* 0x18bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c2:
	/* 0x18c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c4:
	/* 0x18c4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18c8:
	/* 0x18c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18cb:
	/* 0x18cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18d0:
	/* 0x18d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18d5:
	/* 0x18d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d9:
	/* 0x18d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18de:
	/* 0x18de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e0:
	/* 0x18e0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e4:
	/* 0x18e4: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18e9:
	/* 0x18e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18ee:
	/* 0x18ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18f3:
	/* 0x18f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f7:
	/* 0x18f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18fc:
	/* 0x18fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fe:
	/* 0x18fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1902:
	/* 0x1902: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1906:
	/* 0x1906: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_190b:
	/* 0x190b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1910:
	/* 0x1910: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1915:
	/* 0x1915: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_191a:
	/* 0x191a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_191f:
	/* 0x191f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1924:
	/* 0x1924: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_1927:
	/* 0x1927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1929:
	/* 0x1929: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192e:
	/* 0x192e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1933:
	/* 0x1933: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1937:
	/* 0x1937: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_193c:
	/* 0x193c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1941:
	/* 0x1941: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1946:
	/* 0x1946: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194b:
	/* 0x194b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194d:
	/* 0x194d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1952:
	/* 0x1952: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1955:
	/* 0x1955: je     19e6 <trace_ret_vfs_writev+0x19e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e6;
	}
x86_l_195b:
	/* 0x195b: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1960:
	/* 0x1960: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1963:
	/* 0x1963: je     19e6 <trace_ret_vfs_writev+0x19e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e6;
	}
x86_l_1969:
	/* 0x1969: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_196d:
	/* 0x196d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1972:
	/* 0x1972: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1977:
	/* 0x1977: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_197c:
	/* 0x197c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1981:
	/* 0x1981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1983:
	/* 0x1983: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1987:
	/* 0x1987: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1989:
	/* 0x1989: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_198f:
	/* 0x198f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1994:
	/* 0x1994: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1996:
	/* 0x1996: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1998:
	/* 0x1998: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_199d:
	/* 0x199d: jb     1b4f <trace_ret_vfs_writev+0x1b4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b4f;
	}
x86_l_19a3:
	/* 0x19a3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a8:
	/* 0x19a8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19ae:
	/* 0x19ae: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19b1:
	/* 0x19b1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_19b3:
	/* 0x19b3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19b8:
	/* 0x19b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ba:
	/* 0x19ba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19bd:
	/* 0x19bd: jl     19f0 <trace_ret_vfs_writev+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_19f0;
	}
x86_l_19bf:
	/* 0x19bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c4:
	/* 0x19c4: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_19c7:
	/* 0x19c7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_19cd:
	/* 0x19cd: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_19d2:
	/* 0x19d2: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19d4:
	/* 0x19d4: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d9:
	/* 0x19d9: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19de:
	/* 0x19de: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19e1:
	/* 0x19e1: jmp    1abc <trace_ret_vfs_writev+0x1abc> */
	goto x86_l_1abc;
x86_l_19e6:
	/* 0x19e6: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19e9:
	/* 0x19e9: je     1a48 <trace_ret_vfs_writev+0x1a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a48;
	}
x86_l_19eb:
	/* 0x19eb: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f0:
	/* 0x19f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f5:
	/* 0x19f5: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_19fb:
	/* 0x19fb: jne    1b4f <trace_ret_vfs_writev+0x1b4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b4f;
	}
x86_l_1a01:
	/* 0x1a01: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a06:
	/* 0x1a06: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a0a:
	/* 0x1a0a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1a14:
	/* 0x1a14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a19:
	/* 0x1a19: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a1e:
	/* 0x1a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a20:
	/* 0x1a20: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a25:
	/* 0x1a25: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a32:
	/* 0x1a32: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a37:
	/* 0x1a37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a39:
	/* 0x1a39: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3b:
	/* 0x1a3b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a43:
	/* 0x1a43: jmp    1b76 <trace_ret_vfs_writev+0x1b76> */
	goto x86_l_1b76;
x86_l_1a48:
	/* 0x1a48: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4c:
	/* 0x1a4c: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1a51:
	/* 0x1a51: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a56:
	/* 0x1a56: je     19f0 <trace_ret_vfs_writev+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1a58:
	/* 0x1a58: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a5c:
	/* 0x1a5c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a61:
	/* 0x1a61: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a66:
	/* 0x1a66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a6f:
	/* 0x1a6f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a73:
	/* 0x1a73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a78:
	/* 0x1a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7a:
	/* 0x1a7a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a81:
	/* 0x1a81: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a86:
	/* 0x1a86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a94:
	/* 0x1a94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a96:
	/* 0x1a96: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9a:
	/* 0x1a9a: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aad:
	/* 0x1aad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab2:
	/* 0x1ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab4:
	/* 0x1ab4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab8:
	/* 0x1ab8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1abc:
	/* 0x1abc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x1ad0: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_1ad3:
	/* 0x1ad3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad5:
	/* 0x1ad5: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ada:
	/* 0x1ada: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1adf:
	/* 0x1adf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ae3:
	/* 0x1ae3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aed:
	/* 0x1aed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1af2:
	/* 0x1af2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af7:
	/* 0x1af7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af9:
	/* 0x1af9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1afe:
	/* 0x1afe: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b01:
	/* 0x1b01: je     205f <trace_ret_vfs_writev+0x205f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8287ULL;
	}
x86_l_1b07:
	/* 0x1b07: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0c:
	/* 0x1b0c: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b0f:
	/* 0x1b0f: je     205f <trace_ret_vfs_writev+0x205f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8287ULL;
	}
x86_l_1b15:
	/* 0x1b15: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b19:
	/* 0x1b19: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b23:
	/* 0x1b23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b28:
	/* 0x1b28: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b2d:
	/* 0x1b2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2f:
	/* 0x1b2f: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b33:
	/* 0x1b33: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b35:
	/* 0x1b35: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b40:
	/* 0x1b40: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1b42:
	/* 0x1b42: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b44:
	/* 0x1b44: jae    20e2 <trace_ret_vfs_writev+0x20e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8418ULL;
	}
x86_l_1b4a:
	/* 0x1b4a: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b4f:
	/* 0x1b4f: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1b51:
	/* 0x1b51: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1b53:
	/* 0x1b53: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1b58:
	/* 0x1b58: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    BYTE PTR [r12+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1b66:
	/* 0x1b66: cmp    edx,0x6fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28671ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b74:
	/* 0x1b74: ja     1b9b <trace_ret_vfs_writev+0x1b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b9b;
	}
x86_l_1b76:
	/* 0x1b76: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1b7c:
	/* 0x1b7c: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b7f:
	/* 0x1b7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1b86:
	/* 0x1b86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b88:
	/* 0x1b88: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b92:
	/* 0x1b92: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b95:
	/* 0x1b95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b97:
	/* 0x1b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b99:
	/* 0x1b99: jmp    1b9e <trace_ret_vfs_writev+0x1b9e> */
	goto x86_l_1b9e;
x86_l_1b9b:
	/* 0x1b9b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b9e:
	/* 0x1b9e: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    rax,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb5:
	/* 0x1bb5: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1bbd:
	/* 0x1bbd: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    r15,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1bca:
	/* 0x1bca: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bce:
	/* 0x1bce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 7128ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7141ULL: goto x86_l_1be5;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7301ULL: goto x86_l_1c85;
	case 7310ULL: goto x86_l_1c8e;
	case 7318ULL: goto x86_l_1c96;
	case 7321ULL: goto x86_l_1c99;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7345ULL: goto x86_l_1cb1;
	case 7350ULL: goto x86_l_1cb6;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7377ULL: goto x86_l_1cd1;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7394ULL: goto x86_l_1ce2;
	case 7402ULL: goto x86_l_1cea;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7423ULL: goto x86_l_1cff;
	case 7431ULL: goto x86_l_1d07;
	case 7439ULL: goto x86_l_1d0f;
	case 7445ULL: goto x86_l_1d15;
	case 7447ULL: goto x86_l_1d17;
	case 7451ULL: goto x86_l_1d1b;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7476ULL: goto x86_l_1d34;
	case 7480ULL: goto x86_l_1d38;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7495ULL: goto x86_l_1d47;
	case 7497ULL: goto x86_l_1d49;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7509ULL: goto x86_l_1d55;
	case 7516ULL: goto x86_l_1d5c;
	case 7518ULL: goto x86_l_1d5e;
	case 7526ULL: goto x86_l_1d66;
	case 7534ULL: goto x86_l_1d6e;
	case 7537ULL: goto x86_l_1d71;
	case 7545ULL: goto x86_l_1d79;
	case 7552ULL: goto x86_l_1d80;
	case 7560ULL: goto x86_l_1d88;
	case 7567ULL: goto x86_l_1d8f;
	case 7569ULL: goto x86_l_1d91;
	case 7578ULL: goto x86_l_1d9a;
	case 7585ULL: goto x86_l_1da1;
	case 7587ULL: goto x86_l_1da3;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7640ULL: goto x86_l_1dd8;
	case 7647ULL: goto x86_l_1ddf;
	case 7655ULL: goto x86_l_1de7;
	case 7662ULL: goto x86_l_1dee;
	case 7664ULL: goto x86_l_1df0;
	case 7673ULL: goto x86_l_1df9;
	case 7680ULL: goto x86_l_1e00;
	case 7682ULL: goto x86_l_1e02;
	case 7690ULL: goto x86_l_1e0a;
	case 7694ULL: goto x86_l_1e0e;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7727ULL: goto x86_l_1e2f;
	case 7735ULL: goto x86_l_1e37;
	case 7742ULL: goto x86_l_1e3e;
	case 7750ULL: goto x86_l_1e46;
	case 7757ULL: goto x86_l_1e4d;
	case 7759ULL: goto x86_l_1e4f;
	case 7768ULL: goto x86_l_1e58;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7793ULL: goto x86_l_1e71;
	case 7798ULL: goto x86_l_1e76;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7819ULL: goto x86_l_1e8b;
	case 7827ULL: goto x86_l_1e93;
	case 7834ULL: goto x86_l_1e9a;
	case 7842ULL: goto x86_l_1ea2;
	case 7849ULL: goto x86_l_1ea9;
	case 7851ULL: goto x86_l_1eab;
	case 7860ULL: goto x86_l_1eb4;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7873ULL: goto x86_l_1ec1;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7907ULL: goto x86_l_1ee3;
	case 7911ULL: goto x86_l_1ee7;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7945ULL: goto x86_l_1f09;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7963ULL: goto x86_l_1f1b;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8018ULL: goto x86_l_1f52;
	case 8025ULL: goto x86_l_1f59;
	case 8029ULL: goto x86_l_1f5d;
	case 8033ULL: goto x86_l_1f61;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8053ULL: goto x86_l_1f75;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8102ULL: goto x86_l_1fa6;
	case 8104ULL: goto x86_l_1fa8;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8160ULL: goto x86_l_1fe0;
	case 8166ULL: goto x86_l_1fe6;
	case 8170ULL: goto x86_l_1fea;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8200ULL: goto x86_l_2008;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8263ULL: goto x86_l_2047;
	case 8265ULL: goto x86_l_2049;
	case 8272ULL: goto x86_l_2050;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8290ULL: goto x86_l_2062;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8354ULL: goto x86_l_20a2;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8533ULL: goto x86_l_2155;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8572ULL: goto x86_l_217c;
	case 8578ULL: goto x86_l_2182;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8608ULL: goto x86_l_21a0;
	case 8610ULL: goto x86_l_21a2;
	case 8616ULL: goto x86_l_21a8;
	case 8621ULL: goto x86_l_21ad;
	case 8623ULL: goto x86_l_21af;
	case 8625ULL: goto x86_l_21b1;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8642ULL: goto x86_l_21c2;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8707ULL: goto x86_l_2203;
	case 8713ULL: goto x86_l_2209;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8751ULL: goto x86_l_222f;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8779ULL: goto x86_l_224b;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8820ULL: goto x86_l_2274;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8843ULL: goto x86_l_228b;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8865ULL: goto x86_l_22a1;
	case 8869ULL: goto x86_l_22a5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bd8:
	/* 0x1bd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be2:
	/* 0x1be2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1be5:
	/* 0x1be5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be7:
	/* 0x1be7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bec:
	/* 0x1bec: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1bf0:
	/* 0x1bf0: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bff:
	/* 0x1bff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c04:
	/* 0x1c04: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c08:
	/* 0x1c08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c0d:
	/* 0x1c0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0f:
	/* 0x1c0f: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c14:
	/* 0x1c14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c17:
	/* 0x1c17: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c21:
	/* 0x1c21: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c26:
	/* 0x1c26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c2b:
	/* 0x1c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2d:
	/* 0x1c2d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c30:
	/* 0x1c30: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c37:
	/* 0x1c37: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c41:
	/* 0x1c41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c46:
	/* 0x1c46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c4e:
	/* 0x1c4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c50:
	/* 0x1c50: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c55:
	/* 0x1c55: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c59:
	/* 0x1c59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c63:
	/* 0x1c63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c68:
	/* 0x1c68: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c6d:
	/* 0x1c6d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c71:
	/* 0x1c71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c76:
	/* 0x1c76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c78:
	/* 0x1c78: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1c85:
	/* 0x1c85: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1c96:
	/* 0x1c96: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1c99:
	/* 0x1c99: je     1cde <trace_ret_vfs_writev+0x1cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cde;
	}
x86_l_1c9b:
	/* 0x1c9b: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ca5:
	/* 0x1ca5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1caa:
	/* 0x1caa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1caf:
	/* 0x1caf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb1:
	/* 0x1cb1: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cb6:
	/* 0x1cb6: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1cba:
	/* 0x1cba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cbd:
	/* 0x1cbd: je     1cc9 <trace_ret_vfs_writev+0x1cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc9;
	}
x86_l_1cbf:
	/* 0x1cbf: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc1:
	/* 0x1cc1: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1cc4:
	/* 0x1cc4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cc9:
	/* 0x1cc9: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cd1:
	/* 0x1cd1: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1cd7:
	/* 0x1cd7: jbe    1cf6 <trace_ret_vfs_writev+0x1cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cf6;
	}
x86_l_1cd9:
	/* 0x1cd9: jmp    1d80 <trace_ret_vfs_writev+0x1d80> */
	goto x86_l_1d80;
x86_l_1cde:
	/* 0x1cde: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1ce2:
	/* 0x1ce2: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cea:
	/* 0x1cea: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1cf0:
	/* 0x1cf0: ja     1d80 <trace_ret_vfs_writev+0x1d80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d80;
	}
x86_l_1cf6:
	/* 0x1cf6: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1cff:
	/* 0x1cff: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d07:
	/* 0x1d07: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1d0f:
	/* 0x1d0f: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1d15:
	/* 0x1d15: ja     1d80 <trace_ret_vfs_writev+0x1d80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d80;
	}
x86_l_1d17:
	/* 0x1d17: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d1b:
	/* 0x1d1b: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1d22:
	/* 0x1d22: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1d27:
	/* 0x1d27: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1d2c:
	/* 0x1d2c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d34:
	/* 0x1d34: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d38:
	/* 0x1d38: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d44:
	/* 0x1d44: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d47:
	/* 0x1d47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d49:
	/* 0x1d49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d4b:
	/* 0x1d4b: jle    1d80 <trace_ret_vfs_writev+0x1d80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1d80;
	}
x86_l_1d4d:
	/* 0x1d4d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d55:
	/* 0x1d55: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1d5c:
	/* 0x1d5c: ja     1d80 <trace_ret_vfs_writev+0x1d80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d80;
	}
x86_l_1d5e:
	/* 0x1d5e: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1d66:
	/* 0x1d66: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d6e:
	/* 0x1d6e: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1d71:
	/* 0x1d71: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d79:
	/* 0x1d79: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d80:
	/* 0x1d80: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d88:
	/* 0x1d88: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_1d8f:
	/* 0x1d8f: ja     1ddf <trace_ret_vfs_writev+0x1ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ddf;
	}
x86_l_1d91:
	/* 0x1d91: mov    BYTE PTR [r14+r15*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519553ULL);
x86_l_1d9a:
	/* 0x1d9a: cmp    r15d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31995ULL);
x86_l_1da1:
	/* 0x1da1: ja     1ddf <trace_ret_vfs_writev+0x1ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ddf;
	}
x86_l_1da3:
	/* 0x1da3: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1dab:
	/* 0x1dab: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1daf:
	/* 0x1daf: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1db6:
	/* 0x1db6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc5:
	/* 0x1dc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc7:
	/* 0x1dc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dca:
	/* 0x1dca: js     1ddf <trace_ret_vfs_writev+0x1ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ddf;
	}
x86_l_1dcc:
	/* 0x1dcc: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1dd8:
	/* 0x1dd8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ddf:
	/* 0x1ddf: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1de7:
	/* 0x1de7: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_1dee:
	/* 0x1dee: ja     1e3e <trace_ret_vfs_writev+0x1e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e3e;
	}
x86_l_1df0:
	/* 0x1df0: mov    BYTE PTR [r14+r15*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519554ULL);
x86_l_1df9:
	/* 0x1df9: cmp    r15d,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31991ULL);
x86_l_1e00:
	/* 0x1e00: ja     1e3e <trace_ret_vfs_writev+0x1e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e3e;
	}
x86_l_1e02:
	/* 0x1e02: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e0a:
	/* 0x1e0a: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e0e:
	/* 0x1e0e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e15:
	/* 0x1e15: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1f:
	/* 0x1e1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e24:
	/* 0x1e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e26:
	/* 0x1e26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e29:
	/* 0x1e29: js     1e3e <trace_ret_vfs_writev+0x1e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e3e;
	}
x86_l_1e2b:
	/* 0x1e2b: add    r15d,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e37:
	/* 0x1e37: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e3e:
	/* 0x1e3e: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e46:
	/* 0x1e46: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_1e4d:
	/* 0x1e4d: ja     1e9a <trace_ret_vfs_writev+0x1e9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e9a;
	}
x86_l_1e4f:
	/* 0x1e4f: mov    BYTE PTR [r14+r15*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519555ULL);
x86_l_1e58:
	/* 0x1e58: cmp    r15d,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31991ULL);
x86_l_1e5f:
	/* 0x1e5f: ja     1e9a <trace_ret_vfs_writev+0x1e9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e9a;
	}
x86_l_1e61:
	/* 0x1e61: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e66:
	/* 0x1e66: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e6a:
	/* 0x1e6a: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e71:
	/* 0x1e71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e76:
	/* 0x1e76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e7b:
	/* 0x1e7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e80:
	/* 0x1e80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e82:
	/* 0x1e82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e85:
	/* 0x1e85: js     1e9a <trace_ret_vfs_writev+0x1e9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e9a;
	}
x86_l_1e87:
	/* 0x1e87: add    r15d,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e93:
	/* 0x1e93: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e9a:
	/* 0x1e9a: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ea2:
	/* 0x1ea2: cmp    r15,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 31999ULL);
x86_l_1ea9:
	/* 0x1ea9: ja     1ef6 <trace_ret_vfs_writev+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ef6;
	}
x86_l_1eab:
	/* 0x1eab: mov    BYTE PTR [r14+r15*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519556ULL);
x86_l_1eb4:
	/* 0x1eb4: cmp    r15d,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31991ULL);
x86_l_1ebb:
	/* 0x1ebb: ja     1ef6 <trace_ret_vfs_writev+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ef6;
	}
x86_l_1ebd:
	/* 0x1ebd: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ec1:
	/* 0x1ec1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ec8:
	/* 0x1ec8: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ed7:
	/* 0x1ed7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1edc:
	/* 0x1edc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ede:
	/* 0x1ede: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee1:
	/* 0x1ee1: js     1ef6 <trace_ret_vfs_writev+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ef6;
	}
x86_l_1ee3:
	/* 0x1ee3: add    r15d,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1eef:
	/* 0x1eef: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ef6:
	/* 0x1ef6: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1efa:
	/* 0x1efa: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1efd:
	/* 0x1efd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f01:
	/* 0x1f01: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f09:
	/* 0x1f09: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1f10:
	/* 0x1f10: ja     1f59 <trace_ret_vfs_writev+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f59;
	}
x86_l_1f12:
	/* 0x1f12: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_1f1b:
	/* 0x1f1b: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1f21:
	/* 0x1f21: ja     1f59 <trace_ret_vfs_writev+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f59;
	}
x86_l_1f23:
	/* 0x1f23: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f27:
	/* 0x1f27: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1f31:
	/* 0x1f31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f36:
	/* 0x1f36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f40:
	/* 0x1f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f42:
	/* 0x1f42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f45:
	/* 0x1f45: js     1f59 <trace_ret_vfs_writev+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f59;
	}
x86_l_1f47:
	/* 0x1f47: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f52:
	/* 0x1f52: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1f59:
	/* 0x1f59: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    rdx,QWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f61:
	/* 0x1f61: mov    r8d,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1f65:
	/* 0x1f65: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f6d:
	/* 0x1f6d: mov    r9,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1f75:
	/* 0x1f75: mov    rsi,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R9, X86_WIDTH_64);
x86_l_1f78:
	/* 0x1f78: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    QWORD PTR [r14+0x24],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f83:
	/* 0x1f83: and    r8d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1f87:
	/* 0x1f87: or     DWORD PTR [r14+0x5c],r8d */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 92ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1f90:
	/* 0x1f90: mov    rdi,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_64);
x86_l_1f93:
	/* 0x1f93: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1f96:
	/* 0x1f96: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1f99:
	/* 0x1f99: test   BYTE PTR [r13+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1f9e:
	/* 0x1f9e: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1fa6:
	/* 0x1fa6: je     1fcb <trace_ret_vfs_writev+0x1fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fcb;
	}
x86_l_1fa8:
	/* 0x1fa8: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1faf:
	/* 0x1faf: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fc1:
	/* 0x1fc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc3:
	/* 0x1fc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fc5:
	/* 0x1fc5: js     1fcb <trace_ret_vfs_writev+0x1fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fcb;
	}
x86_l_1fc7:
	/* 0x1fc7: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1fcb:
	/* 0x1fcb: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fd3:
	/* 0x1fd3: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1fdd:
	/* 0x1fdd: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1fe0:
	/* 0x1fe0: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1fe6:
	/* 0x1fe6: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1fea:
	/* 0x1fea: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1ff1:
	/* 0x1ff1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2000:
	/* 0x2000: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2003:
	/* 0x2003: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2006:
	/* 0x2006: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2008:
	/* 0x2008: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_200f:
	/* 0x200f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2014:
	/* 0x2014: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2019:
	/* 0x2019: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_201c:
	/* 0x201c: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2021:
	/* 0x2021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2023:
	/* 0x2023: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2028:
	/* 0x2028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202a:
	/* 0x202a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_202c:
	/* 0x202c: or     rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_202f:
	/* 0x202f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2034:
	/* 0x2034: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_203b:
	/* 0x203b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2045:
	/* 0x2045: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2047:
	/* 0x2047: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2049:
	/* 0x2049: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2050:
	/* 0x2050: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2051:
	/* 0x2051: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2055:
	/* 0x2055: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2057:
	/* 0x2057: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2059:
	/* 0x2059: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_205a:
	/* 0x205a: jmp    37b7 <trace_ret_vfs_writev+0x37b7> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_205f:
	/* 0x205f: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2062:
	/* 0x2062: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2068:
	/* 0x2068: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_206c:
	/* 0x206c: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2071:
	/* 0x2071: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2076:
	/* 0x2076: je     19f0 <trace_ret_vfs_writev+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_207c:
	/* 0x207c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2080:
	/* 0x2080: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2085:
	/* 0x2085: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_208a:
	/* 0x208a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_208f:
	/* 0x208f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2093:
	/* 0x2093: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2097:
	/* 0x2097: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_209c:
	/* 0x209c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209e:
	/* 0x209e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a2:
	/* 0x20a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a5:
	/* 0x20a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20aa:
	/* 0x20aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20af:
	/* 0x20af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b3:
	/* 0x20b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b8:
	/* 0x20b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ba:
	/* 0x20ba: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20be:
	/* 0x20be: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20c3:
	/* 0x20c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20c8:
	/* 0x20c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20cd:
	/* 0x20cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d1:
	/* 0x20d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20d6:
	/* 0x20d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d8:
	/* 0x20d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20dc:
	/* 0x20dc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20e0:
	/* 0x20e0: jmp    2129 <trace_ret_vfs_writev+0x2129> */
	goto x86_l_2129;
x86_l_20e2:
	/* 0x20e2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20e7:
	/* 0x20e7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_20ed:
	/* 0x20ed: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20f0:
	/* 0x20f0: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_20f2:
	/* 0x20f2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_20f7:
	/* 0x20f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f9:
	/* 0x20f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20fc:
	/* 0x20fc: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2101:
	/* 0x2101: jl     19f0 <trace_ret_vfs_writev+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6640ULL;
	}
x86_l_2107:
	/* 0x2107: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210c:
	/* 0x210c: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_210f:
	/* 0x210f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2115:
	/* 0x2115: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_211a:
	/* 0x211a: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_211c:
	/* 0x211c: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2121:
	/* 0x2121: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2126:
	/* 0x2126: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2129:
	/* 0x2129: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_212e:
	/* 0x212e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2133:
	/* 0x2133: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2138:
	/* 0x2138: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_213d:
	/* 0x213d: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2140:
	/* 0x2140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2142:
	/* 0x2142: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2147:
	/* 0x2147: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_214c:
	/* 0x214c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2150:
	/* 0x2150: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2155:
	/* 0x2155: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_215a:
	/* 0x215a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215f:
	/* 0x215f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2164:
	/* 0x2164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2166:
	/* 0x2166: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216b:
	/* 0x216b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_216e:
	/* 0x216e: je     2200 <trace_ret_vfs_writev+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2200;
	}
x86_l_2174:
	/* 0x2174: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2179:
	/* 0x2179: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_217c:
	/* 0x217c: je     2200 <trace_ret_vfs_writev+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2200;
	}
x86_l_2182:
	/* 0x2182: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2186:
	/* 0x2186: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_218b:
	/* 0x218b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2190:
	/* 0x2190: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2195:
	/* 0x2195: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_219a:
	/* 0x219a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219c:
	/* 0x219c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_21a0:
	/* 0x21a0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_21a2:
	/* 0x21a2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21a8:
	/* 0x21a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ad:
	/* 0x21ad: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_21af:
	/* 0x21af: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21b1:
	/* 0x21b1: jb     1b4a <trace_ret_vfs_writev+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6986ULL;
	}
x86_l_21b7:
	/* 0x21b7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21bc:
	/* 0x21bc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_21c2:
	/* 0x21c2: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21c5:
	/* 0x21c5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_21c7:
	/* 0x21c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_21cc:
	/* 0x21cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ce:
	/* 0x21ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21d1:
	/* 0x21d1: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d6:
	/* 0x21d6: jl     19f0 <trace_ret_vfs_writev+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6640ULL;
	}
x86_l_21dc:
	/* 0x21dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e1:
	/* 0x21e1: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_21e4:
	/* 0x21e4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_21ea:
	/* 0x21ea: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_21ef:
	/* 0x21ef: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21f1:
	/* 0x21f1: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f6:
	/* 0x21f6: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21fb:
	/* 0x21fb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21fe:
	/* 0x21fe: jmp    227c <trace_ret_vfs_writev+0x227c> */
	goto x86_l_227c;
x86_l_2200:
	/* 0x2200: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2203:
	/* 0x2203: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2209:
	/* 0x2209: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220d:
	/* 0x220d: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2212:
	/* 0x2212: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2218:
	/* 0x2218: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_221c:
	/* 0x221c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2221:
	/* 0x2221: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2226:
	/* 0x2226: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_222b:
	/* 0x222b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222f:
	/* 0x222f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2233:
	/* 0x2233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2238:
	/* 0x2238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223a:
	/* 0x223a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223e:
	/* 0x223e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2241:
	/* 0x2241: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2246:
	/* 0x2246: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_224b:
	/* 0x224b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_224f:
	/* 0x224f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2254:
	/* 0x2254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2256:
	/* 0x2256: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225a:
	/* 0x225a: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_225f:
	/* 0x225f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2264:
	/* 0x2264: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2269:
	/* 0x2269: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226d:
	/* 0x226d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2272:
	/* 0x2272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2274:
	/* 0x2274: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2278:
	/* 0x2278: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_227c:
	/* 0x227c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2281:
	/* 0x2281: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2286:
	/* 0x2286: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_228b:
	/* 0x228b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2290:
	/* 0x2290: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2295:
	/* 0x2295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2297:
	/* 0x2297: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_229c:
	/* 0x229c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22a1:
	/* 0x22a1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22a5:
	/* 0x22a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 8874ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8913ULL: goto x86_l_22d1;
	case 8915ULL: goto x86_l_22d3;
	case 8919ULL: goto x86_l_22d7;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8939ULL: goto x86_l_22eb;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9010ULL: goto x86_l_2332;
	case 9012ULL: goto x86_l_2334;
	case 9015ULL: goto x86_l_2337;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9060ULL: goto x86_l_2364;
	case 9064ULL: goto x86_l_2368;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9083ULL: goto x86_l_237b;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9156ULL: goto x86_l_23c4;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9178ULL: goto x86_l_23da;
	case 9181ULL: goto x86_l_23dd;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9276ULL: goto x86_l_243c;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9343ULL: goto x86_l_247f;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9362ULL: goto x86_l_2492;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9379ULL: goto x86_l_24a3;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9439ULL: goto x86_l_24df;
	case 9445ULL: goto x86_l_24e5;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9570ULL: goto x86_l_2562;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9606ULL: goto x86_l_2586;
	case 9611ULL: goto x86_l_258b;
	case 9616ULL: goto x86_l_2590;
	case 9621ULL: goto x86_l_2595;
	case 9626ULL: goto x86_l_259a;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9678ULL: goto x86_l_25ce;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9697ULL: goto x86_l_25e1;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9726ULL: goto x86_l_25fe;
	case 9729ULL: goto x86_l_2601;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9743ULL: goto x86_l_260f;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9774ULL: goto x86_l_262e;
	case 9780ULL: goto x86_l_2634;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9795ULL: goto x86_l_2643;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9809ULL: goto x86_l_2651;
	case 9814ULL: goto x86_l_2656;
	case 9818ULL: goto x86_l_265a;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9833ULL: goto x86_l_2669;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9846ULL: goto x86_l_2676;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9857ULL: goto x86_l_2681;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9871ULL: goto x86_l_268f;
	case 9876ULL: goto x86_l_2694;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9887ULL: goto x86_l_269f;
	case 9891ULL: goto x86_l_26a3;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9977ULL: goto x86_l_26f9;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9987ULL: goto x86_l_2703;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10013ULL: goto x86_l_271d;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10064ULL: goto x86_l_2750;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10115ULL: goto x86_l_2783;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10130ULL: goto x86_l_2792;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10149ULL: goto x86_l_27a5;
	case 10153ULL: goto x86_l_27a9;
	case 10157ULL: goto x86_l_27ad;
	case 10162ULL: goto x86_l_27b2;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10215ULL: goto x86_l_27e7;
	case 10220ULL: goto x86_l_27ec;
	case 10222ULL: goto x86_l_27ee;
	case 10226ULL: goto x86_l_27f2;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10272ULL: goto x86_l_2820;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10296ULL: goto x86_l_2838;
	case 10298ULL: goto x86_l_283a;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10348ULL: goto x86_l_286c;
	case 10352ULL: goto x86_l_2870;
	case 10354ULL: goto x86_l_2872;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10367ULL: goto x86_l_287f;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10387ULL: goto x86_l_2893;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10413ULL: goto x86_l_28ad;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10450ULL: goto x86_l_28d2;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10488ULL: goto x86_l_28f8;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10503ULL: goto x86_l_2907;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10520ULL: goto x86_l_2918;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22aa:
	/* 0x22aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22af:
	/* 0x22af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x22c0: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_22c3:
	/* 0x22c3: je     234c <trace_ret_vfs_writev+0x234c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_234c;
	}
x86_l_22c9:
	/* 0x22c9: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22ce:
	/* 0x22ce: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_22d1:
	/* 0x22d1: je     234c <trace_ret_vfs_writev+0x234c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_234c;
	}
x86_l_22d3:
	/* 0x22d3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22d7:
	/* 0x22d7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22dc:
	/* 0x22dc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_22e1:
	/* 0x22e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22e6:
	/* 0x22e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22eb:
	/* 0x22eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ed:
	/* 0x22ed: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22f1:
	/* 0x22f1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22f3:
	/* 0x22f3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f9:
	/* 0x22f9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22fe:
	/* 0x22fe: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2300:
	/* 0x2300: jae    23cf <trace_ret_vfs_writev+0x23cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23cf;
	}
x86_l_2306:
	/* 0x2306: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230b:
	/* 0x230b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2310:
	/* 0x2310: jmp    1b4f <trace_ret_vfs_writev+0x1b4f> */
	return 6991ULL;
x86_l_2315:
	/* 0x2315: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_231c:
	/* 0x231c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_231f:
	/* 0x231f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2323:
	/* 0x2323: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2328:
	/* 0x2328: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_232d:
	/* 0x232d: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2332:
	/* 0x2332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2334:
	/* 0x2334: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2337:
	/* 0x2337: jne    2023 <trace_ret_vfs_writev+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8227ULL;
	}
x86_l_233d:
	/* 0x233d: movzx  eax,WORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2342:
	/* 0x2342: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2347:
	/* 0x2347: jmp    c21 <trace_ret_vfs_writev+0xc21> */
	return 3105ULL;
x86_l_234c:
	/* 0x234c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_234f:
	/* 0x234f: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2355:
	/* 0x2355: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2359:
	/* 0x2359: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_235e:
	/* 0x235e: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2364:
	/* 0x2364: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2368:
	/* 0x2368: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236d:
	/* 0x236d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2372:
	/* 0x2372: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2377:
	/* 0x2377: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_237b:
	/* 0x237b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_237f:
	/* 0x237f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2384:
	/* 0x2384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2386:
	/* 0x2386: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238a:
	/* 0x238a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_238d:
	/* 0x238d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2392:
	/* 0x2392: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2397:
	/* 0x2397: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239b:
	/* 0x239b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a0:
	/* 0x23a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a2:
	/* 0x23a2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a6:
	/* 0x23a6: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23ab:
	/* 0x23ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23b0:
	/* 0x23b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23b5:
	/* 0x23b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23b9:
	/* 0x23b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23be:
	/* 0x23be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c0:
	/* 0x23c0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c4:
	/* 0x23c4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_23c8:
	/* 0x23c8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23cd:
	/* 0x23cd: jmp    240e <trace_ret_vfs_writev+0x240e> */
	goto x86_l_240e;
x86_l_23cf:
	/* 0x23cf: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23d4:
	/* 0x23d4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23da:
	/* 0x23da: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23dd:
	/* 0x23dd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_23df:
	/* 0x23df: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_23e4:
	/* 0x23e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e6:
	/* 0x23e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23e9:
	/* 0x23e9: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_23ef:
	/* 0x23ef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f4:
	/* 0x23f4: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_23f7:
	/* 0x23f7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_23fd:
	/* 0x23fd: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2402:
	/* 0x2402: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2404:
	/* 0x2404: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2409:
	/* 0x2409: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240e:
	/* 0x240e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2413:
	/* 0x2413: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2418:
	/* 0x2418: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_241d:
	/* 0x241d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2422:
	/* 0x2422: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2427:
	/* 0x2427: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2429:
	/* 0x2429: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_242e:
	/* 0x242e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2433:
	/* 0x2433: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2437:
	/* 0x2437: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_243c:
	/* 0x243c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2441:
	/* 0x2441: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2446:
	/* 0x2446: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_244b:
	/* 0x244b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244d:
	/* 0x244d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2452:
	/* 0x2452: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2455:
	/* 0x2455: je     24dc <trace_ret_vfs_writev+0x24dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24dc;
	}
x86_l_245b:
	/* 0x245b: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2460:
	/* 0x2460: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2463:
	/* 0x2463: je     24dc <trace_ret_vfs_writev+0x24dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24dc;
	}
x86_l_2465:
	/* 0x2465: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2469:
	/* 0x2469: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_246e:
	/* 0x246e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2473:
	/* 0x2473: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2478:
	/* 0x2478: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_247d:
	/* 0x247d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247f:
	/* 0x247f: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2483:
	/* 0x2483: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2485:
	/* 0x2485: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_248b:
	/* 0x248b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2490:
	/* 0x2490: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2492:
	/* 0x2492: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2306;
	}
x86_l_2498:
	/* 0x2498: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_249d:
	/* 0x249d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24a3:
	/* 0x24a3: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24a6:
	/* 0x24a6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_24a8:
	/* 0x24a8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_24ad:
	/* 0x24ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24af:
	/* 0x24af: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24b2:
	/* 0x24b2: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_24b8:
	/* 0x24b8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bd:
	/* 0x24bd: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_24c0:
	/* 0x24c0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_24c6:
	/* 0x24c6: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_24cb:
	/* 0x24cb: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24cd:
	/* 0x24cd: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d2:
	/* 0x24d2: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d7:
	/* 0x24d7: jmp    255d <trace_ret_vfs_writev+0x255d> */
	goto x86_l_255d;
x86_l_24dc:
	/* 0x24dc: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_24df:
	/* 0x24df: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_24e5:
	/* 0x24e5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e9:
	/* 0x24e9: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_24ee:
	/* 0x24ee: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_24f4:
	/* 0x24f4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24f8:
	/* 0x24f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24fd:
	/* 0x24fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2502:
	/* 0x2502: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2507:
	/* 0x2507: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250b:
	/* 0x250b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_250f:
	/* 0x250f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2514:
	/* 0x2514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2516:
	/* 0x2516: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251a:
	/* 0x251a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_251d:
	/* 0x251d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2522:
	/* 0x2522: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2527:
	/* 0x2527: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252b:
	/* 0x252b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2530:
	/* 0x2530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2532:
	/* 0x2532: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2536:
	/* 0x2536: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_253b:
	/* 0x253b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2540:
	/* 0x2540: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2545:
	/* 0x2545: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2549:
	/* 0x2549: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_254e:
	/* 0x254e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2550:
	/* 0x2550: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2554:
	/* 0x2554: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2558:
	/* 0x2558: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_255d:
	/* 0x255d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2562:
	/* 0x2562: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2567:
	/* 0x2567: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_256c:
	/* 0x256c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2571:
	/* 0x2571: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2576:
	/* 0x2576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2578:
	/* 0x2578: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_257d:
	/* 0x257d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2582:
	/* 0x2582: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2586:
	/* 0x2586: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258b:
	/* 0x258b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2590:
	/* 0x2590: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2595:
	/* 0x2595: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_259a:
	/* 0x259a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259c:
	/* 0x259c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a1:
	/* 0x25a1: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25a4:
	/* 0x25a4: je     262b <trace_ret_vfs_writev+0x262b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262b;
	}
x86_l_25aa:
	/* 0x25aa: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25af:
	/* 0x25af: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_25b2:
	/* 0x25b2: je     262b <trace_ret_vfs_writev+0x262b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262b;
	}
x86_l_25b4:
	/* 0x25b4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25b8:
	/* 0x25b8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25bd:
	/* 0x25bd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25c2:
	/* 0x25c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25c7:
	/* 0x25c7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25cc:
	/* 0x25cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ce:
	/* 0x25ce: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25d2:
	/* 0x25d2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_25d4:
	/* 0x25d4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25da:
	/* 0x25da: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25df:
	/* 0x25df: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25e1:
	/* 0x25e1: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2306;
	}
x86_l_25e7:
	/* 0x25e7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25ec:
	/* 0x25ec: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25f2:
	/* 0x25f2: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25f5:
	/* 0x25f5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_25f7:
	/* 0x25f7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_25fc:
	/* 0x25fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fe:
	/* 0x25fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2601:
	/* 0x2601: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2607:
	/* 0x2607: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260c:
	/* 0x260c: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_260f:
	/* 0x260f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2615:
	/* 0x2615: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_261a:
	/* 0x261a: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_261c:
	/* 0x261c: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2621:
	/* 0x2621: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2626:
	/* 0x2626: jmp    26ac <trace_ret_vfs_writev+0x26ac> */
	goto x86_l_26ac;
x86_l_262b:
	/* 0x262b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_262e:
	/* 0x262e: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2634:
	/* 0x2634: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2638:
	/* 0x2638: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_263d:
	/* 0x263d: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2643:
	/* 0x2643: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2647:
	/* 0x2647: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264c:
	/* 0x264c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2651:
	/* 0x2651: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2656:
	/* 0x2656: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265a:
	/* 0x265a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_265e:
	/* 0x265e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2663:
	/* 0x2663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2665:
	/* 0x2665: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2669:
	/* 0x2669: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_266c:
	/* 0x266c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2671:
	/* 0x2671: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2676:
	/* 0x2676: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267a:
	/* 0x267a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_267f:
	/* 0x267f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2681:
	/* 0x2681: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2685:
	/* 0x2685: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_268a:
	/* 0x268a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_268f:
	/* 0x268f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2694:
	/* 0x2694: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2698:
	/* 0x2698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_269d:
	/* 0x269d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269f:
	/* 0x269f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a3:
	/* 0x26a3: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26a7:
	/* 0x26a7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26ac:
	/* 0x26ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26b1:
	/* 0x26b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26b6:
	/* 0x26b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26bb:
	/* 0x26bb: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26c0:
	/* 0x26c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c5:
	/* 0x26c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c7:
	/* 0x26c7: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26cc:
	/* 0x26cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d1:
	/* 0x26d1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26d5:
	/* 0x26d5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26da:
	/* 0x26da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26df:
	/* 0x26df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26e4:
	/* 0x26e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e9:
	/* 0x26e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26eb:
	/* 0x26eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f0:
	/* 0x26f0: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_26f3:
	/* 0x26f3: je     277a <trace_ret_vfs_writev+0x277a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277a;
	}
x86_l_26f9:
	/* 0x26f9: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26fe:
	/* 0x26fe: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2701:
	/* 0x2701: je     277a <trace_ret_vfs_writev+0x277a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277a;
	}
x86_l_2703:
	/* 0x2703: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2707:
	/* 0x2707: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_270c:
	/* 0x270c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2711:
	/* 0x2711: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2716:
	/* 0x2716: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_271b:
	/* 0x271b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271d:
	/* 0x271d: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2721:
	/* 0x2721: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2723:
	/* 0x2723: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2729:
	/* 0x2729: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272e:
	/* 0x272e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2730:
	/* 0x2730: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2306;
	}
x86_l_2736:
	/* 0x2736: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_273b:
	/* 0x273b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2741:
	/* 0x2741: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2744:
	/* 0x2744: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2746:
	/* 0x2746: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_274b:
	/* 0x274b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274d:
	/* 0x274d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2750:
	/* 0x2750: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2756:
	/* 0x2756: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_275b:
	/* 0x275b: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_275e:
	/* 0x275e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2764:
	/* 0x2764: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2769:
	/* 0x2769: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_276b:
	/* 0x276b: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2770:
	/* 0x2770: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2775:
	/* 0x2775: jmp    27fb <trace_ret_vfs_writev+0x27fb> */
	goto x86_l_27fb;
x86_l_277a:
	/* 0x277a: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_277d:
	/* 0x277d: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2783:
	/* 0x2783: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2787:
	/* 0x2787: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_278c:
	/* 0x278c: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2792:
	/* 0x2792: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2796:
	/* 0x2796: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_279b:
	/* 0x279b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27a0:
	/* 0x27a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27a5:
	/* 0x27a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a9:
	/* 0x27a9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27ad:
	/* 0x27ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27b2:
	/* 0x27b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b4:
	/* 0x27b4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27bb:
	/* 0x27bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27c0:
	/* 0x27c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27c5:
	/* 0x27c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c9:
	/* 0x27c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ce:
	/* 0x27ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d0:
	/* 0x27d0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d4:
	/* 0x27d4: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27d9:
	/* 0x27d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27de:
	/* 0x27de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e3:
	/* 0x27e3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e7:
	/* 0x27e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ec:
	/* 0x27ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ee:
	/* 0x27ee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f2:
	/* 0x27f2: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27f6:
	/* 0x27f6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27fb:
	/* 0x27fb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2800:
	/* 0x2800: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2805:
	/* 0x2805: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_280a:
	/* 0x280a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_280f:
	/* 0x280f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2814:
	/* 0x2814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2816:
	/* 0x2816: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_281b:
	/* 0x281b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2820:
	/* 0x2820: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2824:
	/* 0x2824: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2829:
	/* 0x2829: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_282e:
	/* 0x282e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2833:
	/* 0x2833: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2838:
	/* 0x2838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283a:
	/* 0x283a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_283f:
	/* 0x283f: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2842:
	/* 0x2842: je     28c9 <trace_ret_vfs_writev+0x28c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c9;
	}
x86_l_2848:
	/* 0x2848: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_284d:
	/* 0x284d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2850:
	/* 0x2850: je     28c9 <trace_ret_vfs_writev+0x28c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c9;
	}
x86_l_2852:
	/* 0x2852: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2856:
	/* 0x2856: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_285b:
	/* 0x285b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2860:
	/* 0x2860: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2865:
	/* 0x2865: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_286a:
	/* 0x286a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286c:
	/* 0x286c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2870:
	/* 0x2870: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2872:
	/* 0x2872: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2878:
	/* 0x2878: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287d:
	/* 0x287d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_287f:
	/* 0x287f: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2306;
	}
x86_l_2885:
	/* 0x2885: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_288a:
	/* 0x288a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2890:
	/* 0x2890: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2893:
	/* 0x2893: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2895:
	/* 0x2895: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_289a:
	/* 0x289a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289c:
	/* 0x289c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_289f:
	/* 0x289f: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_28a5:
	/* 0x28a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28aa:
	/* 0x28aa: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_28ad:
	/* 0x28ad: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_28b3:
	/* 0x28b3: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_28b8:
	/* 0x28b8: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28ba:
	/* 0x28ba: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28bf:
	/* 0x28bf: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c4:
	/* 0x28c4: jmp    294a <trace_ret_vfs_writev+0x294a> */
	return 10570ULL;
x86_l_28c9:
	/* 0x28c9: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28cc:
	/* 0x28cc: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_28d2:
	/* 0x28d2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d6:
	/* 0x28d6: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_28db:
	/* 0x28db: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_28e1:
	/* 0x28e1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28e5:
	/* 0x28e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ea:
	/* 0x28ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28ef:
	/* 0x28ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28f4:
	/* 0x28f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f8:
	/* 0x28f8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28fc:
	/* 0x28fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2901:
	/* 0x2901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2903:
	/* 0x2903: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2907:
	/* 0x2907: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_290a:
	/* 0x290a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_290f:
	/* 0x290f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2914:
	/* 0x2914: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2918:
	/* 0x2918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 10525ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10541ULL: goto x86_l_292d;
	case 10546ULL: goto x86_l_2932;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10557ULL: goto x86_l_293d;
	case 10561ULL: goto x86_l_2941;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10633ULL: goto x86_l_2989;
	case 10638ULL: goto x86_l_298e;
	case 10641ULL: goto x86_l_2991;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10655ULL: goto x86_l_299f;
	case 10657ULL: goto x86_l_29a1;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10689ULL: goto x86_l_29c1;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10702ULL: goto x86_l_29ce;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10719ULL: goto x86_l_29df;
	case 10722ULL: goto x86_l_29e2;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10748ULL: goto x86_l_29fc;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10789ULL: goto x86_l_2a25;
	case 10794ULL: goto x86_l_2a2a;
	case 10800ULL: goto x86_l_2a30;
	case 10804ULL: goto x86_l_2a34;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10819ULL: goto x86_l_2a43;
	case 10823ULL: goto x86_l_2a47;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10834ULL: goto x86_l_2a52;
	case 10838ULL: goto x86_l_2a56;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10862ULL: goto x86_l_2a6e;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10885ULL: goto x86_l_2a85;
	case 10890ULL: goto x86_l_2a8a;
	case 10892ULL: goto x86_l_2a8c;
	case 10896ULL: goto x86_l_2a90;
	case 10900ULL: goto x86_l_2a94;
	case 10905ULL: goto x86_l_2a99;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10968ULL: goto x86_l_2ad8;
	case 10973ULL: goto x86_l_2add;
	case 10976ULL: goto x86_l_2ae0;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10990ULL: goto x86_l_2aee;
	case 10992ULL: goto x86_l_2af0;
	case 10996ULL: goto x86_l_2af4;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11018ULL: goto x86_l_2b0a;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11054ULL: goto x86_l_2b2e;
	case 11057ULL: goto x86_l_2b31;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11066ULL: goto x86_l_2b3a;
	case 11069ULL: goto x86_l_2b3d;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11083ULL: goto x86_l_2b4b;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11120ULL: goto x86_l_2b70;
	case 11124ULL: goto x86_l_2b74;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11158ULL: goto x86_l_2b96;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11176ULL: goto x86_l_2ba8;
	case 11181ULL: goto x86_l_2bad;
	case 11186ULL: goto x86_l_2bb2;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11197ULL: goto x86_l_2bbd;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11211ULL: goto x86_l_2bcb;
	case 11216ULL: goto x86_l_2bd0;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11227ULL: goto x86_l_2bdb;
	case 11231ULL: goto x86_l_2bdf;
	case 11235ULL: goto x86_l_2be3;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11296ULL: goto x86_l_2c20;
	case 11301ULL: goto x86_l_2c25;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11311ULL: goto x86_l_2c2f;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11325ULL: goto x86_l_2c3d;
	case 11327ULL: goto x86_l_2c3f;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11353ULL: goto x86_l_2c59;
	case 11357ULL: goto x86_l_2c5d;
	case 11359ULL: goto x86_l_2c5f;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11389ULL: goto x86_l_2c7d;
	case 11392ULL: goto x86_l_2c80;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11401ULL: goto x86_l_2c89;
	case 11404ULL: goto x86_l_2c8c;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11418ULL: goto x86_l_2c9a;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11449ULL: goto x86_l_2cb9;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11470ULL: goto x86_l_2cce;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11489ULL: goto x86_l_2ce1;
	case 11493ULL: goto x86_l_2ce5;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11504ULL: goto x86_l_2cf0;
	case 11508ULL: goto x86_l_2cf4;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11566ULL: goto x86_l_2d2e;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11646ULL: goto x86_l_2d7e;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11692ULL: goto x86_l_2dac;
	case 11694ULL: goto x86_l_2dae;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11707ULL: goto x86_l_2dbb;
	case 11713ULL: goto x86_l_2dc1;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11727ULL: goto x86_l_2dcf;
	case 11729ULL: goto x86_l_2dd1;
	case 11734ULL: goto x86_l_2dd6;
	case 11736ULL: goto x86_l_2dd8;
	case 11739ULL: goto x86_l_2ddb;
	case 11745ULL: goto x86_l_2de1;
	case 11750ULL: goto x86_l_2de6;
	case 11753ULL: goto x86_l_2de9;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11781ULL: goto x86_l_2e05;
	case 11784ULL: goto x86_l_2e08;
	case 11790ULL: goto x86_l_2e0e;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11805ULL: goto x86_l_2e1d;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11828ULL: goto x86_l_2e34;
	case 11832ULL: goto x86_l_2e38;
	case 11837ULL: goto x86_l_2e3d;
	case 11839ULL: goto x86_l_2e3f;
	case 11843ULL: goto x86_l_2e43;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11860ULL: goto x86_l_2e54;
	case 11865ULL: goto x86_l_2e59;
	case 11867ULL: goto x86_l_2e5b;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
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
	case 11997ULL: goto x86_l_2edd;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12023ULL: goto x86_l_2ef7;
	case 12027ULL: goto x86_l_2efb;
	case 12029ULL: goto x86_l_2efd;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12074ULL: goto x86_l_2f2a;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12088ULL: goto x86_l_2f38;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12119ULL: goto x86_l_2f57;
	case 12125ULL: goto x86_l_2f5d;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12140ULL: goto x86_l_2f6c;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12163ULL: goto x86_l_2f83;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_291d:
	/* 0x291d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291f:
	/* 0x291f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2923:
	/* 0x2923: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2928:
	/* 0x2928: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_292d:
	/* 0x292d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2932:
	/* 0x2932: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2936:
	/* 0x2936: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_293b:
	/* 0x293b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293d:
	/* 0x293d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2941:
	/* 0x2941: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2945:
	/* 0x2945: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_294a:
	/* 0x294a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_294f:
	/* 0x294f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2954:
	/* 0x2954: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2959:
	/* 0x2959: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_295e:
	/* 0x295e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2963:
	/* 0x2963: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2965:
	/* 0x2965: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296a:
	/* 0x296a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_296f:
	/* 0x296f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2973:
	/* 0x2973: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2978:
	/* 0x2978: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_297d:
	/* 0x297d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2982:
	/* 0x2982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2987:
	/* 0x2987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2989:
	/* 0x2989: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_298e:
	/* 0x298e: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2991:
	/* 0x2991: je     2a18 <trace_ret_vfs_writev+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a18;
	}
x86_l_2997:
	/* 0x2997: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_299c:
	/* 0x299c: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_299f:
	/* 0x299f: je     2a18 <trace_ret_vfs_writev+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a18;
	}
x86_l_29a1:
	/* 0x29a1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29a5:
	/* 0x29a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29aa:
	/* 0x29aa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_29af:
	/* 0x29af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b4:
	/* 0x29b4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29b9:
	/* 0x29b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29bb:
	/* 0x29bb: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_29bf:
	/* 0x29bf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29c1:
	/* 0x29c1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29c7:
	/* 0x29c7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29cc:
	/* 0x29cc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29ce:
	/* 0x29ce: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_29d4:
	/* 0x29d4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29d9:
	/* 0x29d9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29df:
	/* 0x29df: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29e2:
	/* 0x29e2: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_29e4:
	/* 0x29e4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_29e9:
	/* 0x29e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29eb:
	/* 0x29eb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29ee:
	/* 0x29ee: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_29f4:
	/* 0x29f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29f9:
	/* 0x29f9: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_29fc:
	/* 0x29fc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a02:
	/* 0x2a02: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a07:
	/* 0x2a07: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a09:
	/* 0x2a09: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a13:
	/* 0x2a13: jmp    2a99 <trace_ret_vfs_writev+0x2a99> */
	goto x86_l_2a99;
x86_l_2a18:
	/* 0x2a18: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a1b:
	/* 0x2a1b: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2a21:
	/* 0x2a21: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a25:
	/* 0x2a25: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2a2a:
	/* 0x2a2a: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2a30:
	/* 0x2a30: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a34:
	/* 0x2a34: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a39:
	/* 0x2a39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a3e:
	/* 0x2a3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a43:
	/* 0x2a43: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a47:
	/* 0x2a47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a50:
	/* 0x2a50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a52:
	/* 0x2a52: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a56:
	/* 0x2a56: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a59:
	/* 0x2a59: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a5e:
	/* 0x2a5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a63:
	/* 0x2a63: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a67:
	/* 0x2a67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a6c:
	/* 0x2a6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6e:
	/* 0x2a6e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a72:
	/* 0x2a72: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a77:
	/* 0x2a77: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a7c:
	/* 0x2a7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a81:
	/* 0x2a81: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a85:
	/* 0x2a85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8a:
	/* 0x2a8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8c:
	/* 0x2a8c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a90:
	/* 0x2a90: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a94:
	/* 0x2a94: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a99:
	/* 0x2a99: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aad:
	/* 0x2aad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ab2:
	/* 0x2ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab4:
	/* 0x2ab4: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abe:
	/* 0x2abe: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ac2:
	/* 0x2ac2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2acc:
	/* 0x2acc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ad6:
	/* 0x2ad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad8:
	/* 0x2ad8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2add:
	/* 0x2add: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ae0:
	/* 0x2ae0: je     2b67 <trace_ret_vfs_writev+0x2b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b67;
	}
x86_l_2ae6:
	/* 0x2ae6: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aeb:
	/* 0x2aeb: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2aee:
	/* 0x2aee: je     2b67 <trace_ret_vfs_writev+0x2b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b67;
	}
x86_l_2af0:
	/* 0x2af0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2af4:
	/* 0x2af4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2af9:
	/* 0x2af9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2afe:
	/* 0x2afe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b03:
	/* 0x2b03: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b08:
	/* 0x2b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0a:
	/* 0x2b0a: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b0e:
	/* 0x2b0e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b10:
	/* 0x2b10: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b16:
	/* 0x2b16: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1b:
	/* 0x2b1b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b1d:
	/* 0x2b1d: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_2b23:
	/* 0x2b23: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b28:
	/* 0x2b28: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b2e:
	/* 0x2b2e: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b31:
	/* 0x2b31: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2b33:
	/* 0x2b33: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b38:
	/* 0x2b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3a:
	/* 0x2b3a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b3d:
	/* 0x2b3d: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2b43:
	/* 0x2b43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b48:
	/* 0x2b48: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2b4b:
	/* 0x2b4b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2b51:
	/* 0x2b51: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2b56:
	/* 0x2b56: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b58:
	/* 0x2b58: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b62:
	/* 0x2b62: jmp    2be8 <trace_ret_vfs_writev+0x2be8> */
	goto x86_l_2be8;
x86_l_2b67:
	/* 0x2b67: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b6a:
	/* 0x2b6a: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2b70:
	/* 0x2b70: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b74:
	/* 0x2b74: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2b79:
	/* 0x2b79: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2b7f:
	/* 0x2b7f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b83:
	/* 0x2b83: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b88:
	/* 0x2b88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b8d:
	/* 0x2b8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b92:
	/* 0x2b92: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b96:
	/* 0x2b96: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b9a:
	/* 0x2b9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b9f:
	/* 0x2b9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba1:
	/* 0x2ba1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ba5:
	/* 0x2ba5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ba8:
	/* 0x2ba8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bad:
	/* 0x2bad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bbb:
	/* 0x2bbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bbd:
	/* 0x2bbd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc1:
	/* 0x2bc1: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd4:
	/* 0x2bd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd9:
	/* 0x2bd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdb:
	/* 0x2bdb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bdf:
	/* 0x2bdf: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2be3:
	/* 0x2be3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2be8:
	/* 0x2be8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bed:
	/* 0x2bed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c01:
	/* 0x2c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c03:
	/* 0x2c03: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c08:
	/* 0x2c08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c0d:
	/* 0x2c0d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c11:
	/* 0x2c11: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c16:
	/* 0x2c16: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c20:
	/* 0x2c20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c25:
	/* 0x2c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c27:
	/* 0x2c27: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c2c:
	/* 0x2c2c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c2f:
	/* 0x2c2f: je     2cb6 <trace_ret_vfs_writev+0x2cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb6;
	}
x86_l_2c35:
	/* 0x2c35: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c3a:
	/* 0x2c3a: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2c3d:
	/* 0x2c3d: je     2cb6 <trace_ret_vfs_writev+0x2cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb6;
	}
x86_l_2c3f:
	/* 0x2c3f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c43:
	/* 0x2c43: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c48:
	/* 0x2c48: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c52:
	/* 0x2c52: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c57:
	/* 0x2c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c59:
	/* 0x2c59: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2c5d:
	/* 0x2c5d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c5f:
	/* 0x2c5f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c65:
	/* 0x2c65: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6a:
	/* 0x2c6a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c6c:
	/* 0x2c6c: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_2c72:
	/* 0x2c72: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c77:
	/* 0x2c77: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c7d:
	/* 0x2c7d: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c80:
	/* 0x2c80: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2c82:
	/* 0x2c82: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c87:
	/* 0x2c87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c89:
	/* 0x2c89: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c8c:
	/* 0x2c8c: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2c92:
	/* 0x2c92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c97:
	/* 0x2c97: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c9a:
	/* 0x2c9a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ca5:
	/* 0x2ca5: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ca7:
	/* 0x2ca7: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cac:
	/* 0x2cac: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb1:
	/* 0x2cb1: jmp    2d37 <trace_ret_vfs_writev+0x2d37> */
	goto x86_l_2d37;
x86_l_2cb6:
	/* 0x2cb6: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2cb9:
	/* 0x2cb9: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2cbf:
	/* 0x2cbf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc3:
	/* 0x2cc3: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2cc8:
	/* 0x2cc8: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2cce:
	/* 0x2cce: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cd2:
	/* 0x2cd2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ce1:
	/* 0x2ce1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce5:
	/* 0x2ce5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cee:
	/* 0x2cee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf0:
	/* 0x2cf0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2cf7:
	/* 0x2cf7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d01:
	/* 0x2d01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d05:
	/* 0x2d05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d0a:
	/* 0x2d0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0c:
	/* 0x2d0c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d10:
	/* 0x2d10: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d15:
	/* 0x2d15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d23:
	/* 0x2d23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d28:
	/* 0x2d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2a:
	/* 0x2d2a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d2e:
	/* 0x2d2e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d32:
	/* 0x2d32: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d37:
	/* 0x2d37: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d3c:
	/* 0x2d3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d41:
	/* 0x2d41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d46:
	/* 0x2d46: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d50:
	/* 0x2d50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d52:
	/* 0x2d52: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d57:
	/* 0x2d57: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5c:
	/* 0x2d5c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d60:
	/* 0x2d60: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d65:
	/* 0x2d65: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d74:
	/* 0x2d74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d76:
	/* 0x2d76: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d7b:
	/* 0x2d7b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d7e:
	/* 0x2d7e: je     2e05 <trace_ret_vfs_writev+0x2e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e05;
	}
x86_l_2d84:
	/* 0x2d84: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d89:
	/* 0x2d89: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2d8c:
	/* 0x2d8c: je     2e05 <trace_ret_vfs_writev+0x2e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e05;
	}
x86_l_2d8e:
	/* 0x2d8e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d92:
	/* 0x2d92: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d97:
	/* 0x2d97: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2da1:
	/* 0x2da1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2da6:
	/* 0x2da6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da8:
	/* 0x2da8: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dac:
	/* 0x2dac: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dae:
	/* 0x2dae: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2db4:
	/* 0x2db4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db9:
	/* 0x2db9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dbb:
	/* 0x2dbb: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_2dc1:
	/* 0x2dc1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dc6:
	/* 0x2dc6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2dcc:
	/* 0x2dcc: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dcf:
	/* 0x2dcf: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2dd1:
	/* 0x2dd1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2dd6:
	/* 0x2dd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd8:
	/* 0x2dd8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ddb:
	/* 0x2ddb: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2de1:
	/* 0x2de1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2de6:
	/* 0x2de6: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2de9:
	/* 0x2de9: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2def:
	/* 0x2def: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2df4:
	/* 0x2df4: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2df6:
	/* 0x2df6: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dfb:
	/* 0x2dfb: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e00:
	/* 0x2e00: jmp    2e86 <trace_ret_vfs_writev+0x2e86> */
	goto x86_l_2e86;
x86_l_2e05:
	/* 0x2e05: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e08:
	/* 0x2e08: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2e0e:
	/* 0x2e0e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e12:
	/* 0x2e12: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2e17:
	/* 0x2e17: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2e1d:
	/* 0x2e1d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e21:
	/* 0x2e21: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e26:
	/* 0x2e26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e30:
	/* 0x2e30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e34:
	/* 0x2e34: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e38:
	/* 0x2e38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e3d:
	/* 0x2e3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e3f:
	/* 0x2e3f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e43:
	/* 0x2e43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e46:
	/* 0x2e46: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e50:
	/* 0x2e50: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e54:
	/* 0x2e54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e59:
	/* 0x2e59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5b:
	/* 0x2e5b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5f:
	/* 0x2e5f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e64:
	/* 0x2e64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e69:
	/* 0x2e69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e72:
	/* 0x2e72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e77:
	/* 0x2e77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e79:
	/* 0x2e79: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7d:
	/* 0x2e7d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e81:
	/* 0x2e81: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e86:
	/* 0x2e86: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e90:
	/* 0x2e90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e95:
	/* 0x2e95: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e9f:
	/* 0x2e9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea1:
	/* 0x2ea1: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eab:
	/* 0x2eab: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2eaf:
	/* 0x2eaf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x2ec5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eca:
	/* 0x2eca: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ecd:
	/* 0x2ecd: je     2f54 <trace_ret_vfs_writev+0x2f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f54;
	}
x86_l_2ed3:
	/* 0x2ed3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2edb:
	/* 0x2edb: je     2f54 <trace_ret_vfs_writev+0x2f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f54;
	}
x86_l_2edd:
	/* 0x2edd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ee1:
	/* 0x2ee1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee6:
	/* 0x2ee6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2eeb:
	/* 0x2eeb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ef0:
	/* 0x2ef0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ef5:
	/* 0x2ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef7:
	/* 0x2ef7: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2efb:
	/* 0x2efb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2efd:
	/* 0x2efd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f03:
	/* 0x2f03: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f08:
	/* 0x2f08: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f0a:
	/* 0x2f0a: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_2f10:
	/* 0x2f10: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f15:
	/* 0x2f15: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f1b:
	/* 0x2f1b: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f1e:
	/* 0x2f1e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2f20:
	/* 0x2f20: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f25:
	/* 0x2f25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f27:
	/* 0x2f27: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f2a:
	/* 0x2f2a: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_2f30:
	/* 0x2f30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f35:
	/* 0x2f35: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f38:
	/* 0x2f38: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f43:
	/* 0x2f43: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f45:
	/* 0x2f45: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4a:
	/* 0x2f4a: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4f:
	/* 0x2f4f: jmp    2fd5 <trace_ret_vfs_writev+0x2fd5> */
	return 12245ULL;
x86_l_2f54:
	/* 0x2f54: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f57:
	/* 0x2f57: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_2f5d:
	/* 0x2f5d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f61:
	/* 0x2f61: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2f66:
	/* 0x2f66: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_2f6c:
	/* 0x2f6c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f70:
	/* 0x2f70: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f75:
	/* 0x2f75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f7f:
	/* 0x2f7f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f83:
	/* 0x2f83: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f87:
	/* 0x2f87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8c:
	/* 0x2f8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 12174ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12174ULL: goto x86_l_2f8e;
	case 12178ULL: goto x86_l_2f92;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12191ULL: goto x86_l_2f9f;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12202ULL: goto x86_l_2faa;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12221ULL: goto x86_l_2fbd;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12232ULL: goto x86_l_2fc8;
	case 12236ULL: goto x86_l_2fcc;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12330ULL: goto x86_l_302a;
	case 12332ULL: goto x86_l_302c;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12358ULL: goto x86_l_3046;
	case 12362ULL: goto x86_l_304a;
	case 12364ULL: goto x86_l_304c;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12377ULL: goto x86_l_3059;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12399ULL: goto x86_l_306f;
	case 12404ULL: goto x86_l_3074;
	case 12406ULL: goto x86_l_3076;
	case 12409ULL: goto x86_l_3079;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12436ULL: goto x86_l_3094;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12475ULL: goto x86_l_30bb;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12498ULL: goto x86_l_30d2;
	case 12502ULL: goto x86_l_30d6;
	case 12507ULL: goto x86_l_30db;
	case 12509ULL: goto x86_l_30dd;
	case 12513ULL: goto x86_l_30e1;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12537ULL: goto x86_l_30f9;
	case 12541ULL: goto x86_l_30fd;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12560ULL: goto x86_l_3110;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12571ULL: goto x86_l_311b;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12643ULL: goto x86_l_3163;
	case 12648ULL: goto x86_l_3168;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12693ULL: goto x86_l_3195;
	case 12697ULL: goto x86_l_3199;
	case 12699ULL: goto x86_l_319b;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12712ULL: goto x86_l_31a8;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12729ULL: goto x86_l_31b9;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12739ULL: goto x86_l_31c3;
	case 12741ULL: goto x86_l_31c5;
	case 12744ULL: goto x86_l_31c8;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12789ULL: goto x86_l_31f5;
	case 12795ULL: goto x86_l_31fb;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12810ULL: goto x86_l_320a;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12829ULL: goto x86_l_321d;
	case 12833ULL: goto x86_l_3221;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12844ULL: goto x86_l_322c;
	case 12848ULL: goto x86_l_3230;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12865ULL: goto x86_l_3241;
	case 12870ULL: goto x86_l_3246;
	case 12872ULL: goto x86_l_3248;
	case 12876ULL: goto x86_l_324c;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12891ULL: goto x86_l_325b;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12902ULL: goto x86_l_3266;
	case 12906ULL: goto x86_l_326a;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12986ULL: goto x86_l_32ba;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13006ULL: goto x86_l_32ce;
	case 13011ULL: goto x86_l_32d3;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13026ULL: goto x86_l_32e2;
	case 13028ULL: goto x86_l_32e4;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13047ULL: goto x86_l_32f7;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13064ULL: goto x86_l_3308;
	case 13067ULL: goto x86_l_330b;
	case 13069ULL: goto x86_l_330d;
	case 13074ULL: goto x86_l_3312;
	case 13076ULL: goto x86_l_3314;
	case 13079ULL: goto x86_l_3317;
	case 13085ULL: goto x86_l_331d;
	case 13090ULL: goto x86_l_3322;
	case 13093ULL: goto x86_l_3325;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13116ULL: goto x86_l_333c;
	case 13121ULL: goto x86_l_3341;
	case 13124ULL: goto x86_l_3344;
	case 13130ULL: goto x86_l_334a;
	case 13134ULL: goto x86_l_334e;
	case 13139ULL: goto x86_l_3353;
	case 13145ULL: goto x86_l_3359;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13159ULL: goto x86_l_3367;
	case 13164ULL: goto x86_l_336c;
	case 13168ULL: goto x86_l_3370;
	case 13172ULL: goto x86_l_3374;
	case 13177ULL: goto x86_l_3379;
	case 13179ULL: goto x86_l_337b;
	case 13183ULL: goto x86_l_337f;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13200ULL: goto x86_l_3390;
	case 13205ULL: goto x86_l_3395;
	case 13207ULL: goto x86_l_3397;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13230ULL: goto x86_l_33ae;
	case 13235ULL: goto x86_l_33b3;
	case 13237ULL: goto x86_l_33b5;
	case 13241ULL: goto x86_l_33b9;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13255ULL: goto x86_l_33c7;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13291ULL: goto x86_l_33eb;
	case 13296ULL: goto x86_l_33f0;
	case 13301ULL: goto x86_l_33f5;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13313ULL: goto x86_l_3401;
	case 13318ULL: goto x86_l_3406;
	case 13321ULL: goto x86_l_3409;
	case 13327ULL: goto x86_l_340f;
	case 13332ULL: goto x86_l_3414;
	case 13335ULL: goto x86_l_3417;
	case 13337ULL: goto x86_l_3419;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13351ULL: goto x86_l_3427;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13363ULL: goto x86_l_3433;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13382ULL: goto x86_l_3446;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13399ULL: goto x86_l_3457;
	case 13402ULL: goto x86_l_345a;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13411ULL: goto x86_l_3463;
	case 13414ULL: goto x86_l_3466;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13428ULL: goto x86_l_3474;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13441ULL: goto x86_l_3481;
	case 13446ULL: goto x86_l_3486;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13465ULL: goto x86_l_3499;
	case 13469ULL: goto x86_l_349d;
	case 13474ULL: goto x86_l_34a2;
	case 13480ULL: goto x86_l_34a8;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13494ULL: goto x86_l_34b6;
	case 13499ULL: goto x86_l_34bb;
	case 13503ULL: goto x86_l_34bf;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13514ULL: goto x86_l_34ca;
	case 13518ULL: goto x86_l_34ce;
	case 13521ULL: goto x86_l_34d1;
	case 13526ULL: goto x86_l_34d6;
	case 13531ULL: goto x86_l_34db;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13542ULL: goto x86_l_34e6;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13556ULL: goto x86_l_34f4;
	case 13561ULL: goto x86_l_34f9;
	case 13565ULL: goto x86_l_34fd;
	case 13570ULL: goto x86_l_3502;
	case 13572ULL: goto x86_l_3504;
	case 13576ULL: goto x86_l_3508;
	case 13580ULL: goto x86_l_350c;
	case 13585ULL: goto x86_l_3511;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13612ULL: goto x86_l_352c;
	case 13617ULL: goto x86_l_3531;
	case 13622ULL: goto x86_l_3536;
	case 13626ULL: goto x86_l_353a;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13656ULL: goto x86_l_3558;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	case 13676ULL: goto x86_l_356c;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13698ULL: goto x86_l_3582;
	case 13702ULL: goto x86_l_3586;
	case 13704ULL: goto x86_l_3588;
	case 13710ULL: goto x86_l_358e;
	case 13715ULL: goto x86_l_3593;
	case 13717ULL: goto x86_l_3595;
	case 13723ULL: goto x86_l_359b;
	case 13728ULL: goto x86_l_35a0;
	case 13734ULL: goto x86_l_35a6;
	case 13737ULL: goto x86_l_35a9;
	case 13739ULL: goto x86_l_35ab;
	case 13744ULL: goto x86_l_35b0;
	case 13746ULL: goto x86_l_35b2;
	case 13749ULL: goto x86_l_35b5;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13763ULL: goto x86_l_35c3;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13786ULL: goto x86_l_35da;
	case 13791ULL: goto x86_l_35df;
	case 13794ULL: goto x86_l_35e2;
	case 13800ULL: goto x86_l_35e8;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13815ULL: goto x86_l_35f7;
	case 13819ULL: goto x86_l_35fb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f8e:
	/* 0x2f8e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f92:
	/* 0x2f92: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f95:
	/* 0x2f95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f9a:
	/* 0x2f9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f9f:
	/* 0x2f9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa3:
	/* 0x2fa3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa8:
	/* 0x2fa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2faa:
	/* 0x2faa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fae:
	/* 0x2fae: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fbd:
	/* 0x2fbd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fc6:
	/* 0x2fc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc8:
	/* 0x2fc8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fcc:
	/* 0x2fcc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fd0:
	/* 0x2fd0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fd5:
	/* 0x2fd5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fda:
	/* 0x2fda: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fe9:
	/* 0x2fe9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fee:
	/* 0x2fee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff0:
	/* 0x2ff0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ffa:
	/* 0x2ffa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ffe:
	/* 0x2ffe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3003:
	/* 0x3003: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3008:
	/* 0x3008: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_300d:
	/* 0x300d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3012:
	/* 0x3012: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3014:
	/* 0x3014: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3019:
	/* 0x3019: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_301c:
	/* 0x301c: je     30a3 <trace_ret_vfs_writev+0x30a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30a3;
	}
x86_l_3022:
	/* 0x3022: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3027:
	/* 0x3027: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_302a:
	/* 0x302a: je     30a3 <trace_ret_vfs_writev+0x30a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30a3;
	}
x86_l_302c:
	/* 0x302c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3030:
	/* 0x3030: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3035:
	/* 0x3035: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_303a:
	/* 0x303a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_303f:
	/* 0x303f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3044:
	/* 0x3044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3046:
	/* 0x3046: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_304a:
	/* 0x304a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_304c:
	/* 0x304c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3052:
	/* 0x3052: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3057:
	/* 0x3057: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3059:
	/* 0x3059: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_305f:
	/* 0x305f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3064:
	/* 0x3064: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_306a:
	/* 0x306a: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_306d:
	/* 0x306d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_306f:
	/* 0x306f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3074:
	/* 0x3074: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3076:
	/* 0x3076: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3079:
	/* 0x3079: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_307f:
	/* 0x307f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3084:
	/* 0x3084: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3087:
	/* 0x3087: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_308d:
	/* 0x308d: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3092:
	/* 0x3092: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3094:
	/* 0x3094: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3099:
	/* 0x3099: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_309e:
	/* 0x309e: jmp    3124 <trace_ret_vfs_writev+0x3124> */
	goto x86_l_3124;
x86_l_30a3:
	/* 0x30a3: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_30a6:
	/* 0x30a6: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_30ac:
	/* 0x30ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b0:
	/* 0x30b0: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_30b5:
	/* 0x30b5: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_30bb:
	/* 0x30bb: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30bf:
	/* 0x30bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c4:
	/* 0x30c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30c9:
	/* 0x30c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ce:
	/* 0x30ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d2:
	/* 0x30d2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30d6:
	/* 0x30d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30db:
	/* 0x30db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30dd:
	/* 0x30dd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e1:
	/* 0x30e1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30e4:
	/* 0x30e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30e9:
	/* 0x30e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ee:
	/* 0x30ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f2:
	/* 0x30f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f7:
	/* 0x30f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f9:
	/* 0x30f9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30fd:
	/* 0x30fd: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3102:
	/* 0x3102: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3107:
	/* 0x3107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_310c:
	/* 0x310c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3110:
	/* 0x3110: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3115:
	/* 0x3115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3117:
	/* 0x3117: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311b:
	/* 0x311b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_311f:
	/* 0x311f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3124:
	/* 0x3124: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3129:
	/* 0x3129: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_312e:
	/* 0x312e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3133:
	/* 0x3133: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3138:
	/* 0x3138: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_313d:
	/* 0x313d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313f:
	/* 0x313f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3144:
	/* 0x3144: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3149:
	/* 0x3149: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_314d:
	/* 0x314d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3152:
	/* 0x3152: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3157:
	/* 0x3157: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_315c:
	/* 0x315c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3161:
	/* 0x3161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3163:
	/* 0x3163: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3168:
	/* 0x3168: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_316b:
	/* 0x316b: je     31f2 <trace_ret_vfs_writev+0x31f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f2;
	}
x86_l_3171:
	/* 0x3171: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3176:
	/* 0x3176: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3179:
	/* 0x3179: je     31f2 <trace_ret_vfs_writev+0x31f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f2;
	}
x86_l_317b:
	/* 0x317b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_317f:
	/* 0x317f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3184:
	/* 0x3184: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3189:
	/* 0x3189: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_318e:
	/* 0x318e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3193:
	/* 0x3193: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3195:
	/* 0x3195: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3199:
	/* 0x3199: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_319b:
	/* 0x319b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31a1:
	/* 0x31a1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a6:
	/* 0x31a6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31a8:
	/* 0x31a8: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_31ae:
	/* 0x31ae: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31b3:
	/* 0x31b3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_31b9:
	/* 0x31b9: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31bc:
	/* 0x31bc: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_31be:
	/* 0x31be: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_31c3:
	/* 0x31c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c5:
	/* 0x31c5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31c8:
	/* 0x31c8: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_31ce:
	/* 0x31ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31d3:
	/* 0x31d3: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_31d6:
	/* 0x31d6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_31dc:
	/* 0x31dc: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_31e1:
	/* 0x31e1: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31e3:
	/* 0x31e3: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e8:
	/* 0x31e8: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ed:
	/* 0x31ed: jmp    3273 <trace_ret_vfs_writev+0x3273> */
	goto x86_l_3273;
x86_l_31f2:
	/* 0x31f2: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31f5:
	/* 0x31f5: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_31fb:
	/* 0x31fb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31ff:
	/* 0x31ff: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3204:
	/* 0x3204: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_320a:
	/* 0x320a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_320e:
	/* 0x320e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3213:
	/* 0x3213: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3218:
	/* 0x3218: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_321d:
	/* 0x321d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3221:
	/* 0x3221: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3225:
	/* 0x3225: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_322a:
	/* 0x322a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322c:
	/* 0x322c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3230:
	/* 0x3230: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3233:
	/* 0x3233: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3238:
	/* 0x3238: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_323d:
	/* 0x323d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3241:
	/* 0x3241: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3246:
	/* 0x3246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3248:
	/* 0x3248: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324c:
	/* 0x324c: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3251:
	/* 0x3251: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3256:
	/* 0x3256: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_325b:
	/* 0x325b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_325f:
	/* 0x325f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3264:
	/* 0x3264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3266:
	/* 0x3266: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_326a:
	/* 0x326a: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_326e:
	/* 0x326e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3273:
	/* 0x3273: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3278:
	/* 0x3278: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_327d:
	/* 0x327d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3282:
	/* 0x3282: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3287:
	/* 0x3287: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_328c:
	/* 0x328c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328e:
	/* 0x328e: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3293:
	/* 0x3293: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3298:
	/* 0x3298: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_329c:
	/* 0x329c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32a1:
	/* 0x32a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32a6:
	/* 0x32a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32ab:
	/* 0x32ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b0:
	/* 0x32b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b2:
	/* 0x32b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32b7:
	/* 0x32b7: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32ba:
	/* 0x32ba: je     3341 <trace_ret_vfs_writev+0x3341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3341;
	}
x86_l_32c0:
	/* 0x32c0: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32c5:
	/* 0x32c5: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_32c8:
	/* 0x32c8: je     3341 <trace_ret_vfs_writev+0x3341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3341;
	}
x86_l_32ca:
	/* 0x32ca: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32ce:
	/* 0x32ce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32d3:
	/* 0x32d3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32d8:
	/* 0x32d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32dd:
	/* 0x32dd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32e2:
	/* 0x32e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e4:
	/* 0x32e4: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32e8:
	/* 0x32e8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_32ea:
	/* 0x32ea: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_32f0:
	/* 0x32f0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f5:
	/* 0x32f5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32f7:
	/* 0x32f7: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_32fd:
	/* 0x32fd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3302:
	/* 0x3302: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3308:
	/* 0x3308: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_330b:
	/* 0x330b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_330d:
	/* 0x330d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3312:
	/* 0x3312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3314:
	/* 0x3314: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3317:
	/* 0x3317: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_331d:
	/* 0x331d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3322:
	/* 0x3322: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3325:
	/* 0x3325: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_332b:
	/* 0x332b: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3330:
	/* 0x3330: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3332:
	/* 0x3332: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3337:
	/* 0x3337: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_333c:
	/* 0x333c: jmp    33c2 <trace_ret_vfs_writev+0x33c2> */
	goto x86_l_33c2;
x86_l_3341:
	/* 0x3341: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3344:
	/* 0x3344: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_334a:
	/* 0x334a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_334e:
	/* 0x334e: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3353:
	/* 0x3353: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_3359:
	/* 0x3359: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_335d:
	/* 0x335d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3362:
	/* 0x3362: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3367:
	/* 0x3367: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_336c:
	/* 0x336c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3370:
	/* 0x3370: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3374:
	/* 0x3374: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3379:
	/* 0x3379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337b:
	/* 0x337b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337f:
	/* 0x337f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3382:
	/* 0x3382: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3387:
	/* 0x3387: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_338c:
	/* 0x338c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3390:
	/* 0x3390: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3395:
	/* 0x3395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3397:
	/* 0x3397: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_339b:
	/* 0x339b: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_33a0:
	/* 0x33a0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33a5:
	/* 0x33a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33aa:
	/* 0x33aa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ae:
	/* 0x33ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b3:
	/* 0x33b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b5:
	/* 0x33b5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b9:
	/* 0x33b9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33bd:
	/* 0x33bd: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33c2:
	/* 0x33c2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33c7:
	/* 0x33c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33cc:
	/* 0x33cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33d1:
	/* 0x33d1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33d6:
	/* 0x33d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33db:
	/* 0x33db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dd:
	/* 0x33dd: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33e2:
	/* 0x33e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e7:
	/* 0x33e7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33eb:
	/* 0x33eb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33f0:
	/* 0x33f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33f5:
	/* 0x33f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33fa:
	/* 0x33fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33ff:
	/* 0x33ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3401:
	/* 0x3401: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3406:
	/* 0x3406: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3409:
	/* 0x3409: je     3490 <trace_ret_vfs_writev+0x3490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3490;
	}
x86_l_340f:
	/* 0x340f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3414:
	/* 0x3414: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3417:
	/* 0x3417: je     3490 <trace_ret_vfs_writev+0x3490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3490;
	}
x86_l_3419:
	/* 0x3419: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_341d:
	/* 0x341d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3422:
	/* 0x3422: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3427:
	/* 0x3427: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_342c:
	/* 0x342c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3431:
	/* 0x3431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3433:
	/* 0x3433: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3437:
	/* 0x3437: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3439:
	/* 0x3439: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_343f:
	/* 0x343f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3444:
	/* 0x3444: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3446:
	/* 0x3446: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_344c:
	/* 0x344c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3451:
	/* 0x3451: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3457:
	/* 0x3457: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_345a:
	/* 0x345a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_345c:
	/* 0x345c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3461:
	/* 0x3461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3463:
	/* 0x3463: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3466:
	/* 0x3466: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_346c:
	/* 0x346c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3471:
	/* 0x3471: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3474:
	/* 0x3474: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_347a:
	/* 0x347a: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_347f:
	/* 0x347f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3481:
	/* 0x3481: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3486:
	/* 0x3486: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348b:
	/* 0x348b: jmp    3511 <trace_ret_vfs_writev+0x3511> */
	goto x86_l_3511;
x86_l_3490:
	/* 0x3490: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3493:
	/* 0x3493: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_3499:
	/* 0x3499: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_349d:
	/* 0x349d: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_34a2:
	/* 0x34a2: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_34a8:
	/* 0x34a8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34ac:
	/* 0x34ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34b1:
	/* 0x34b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34b6:
	/* 0x34b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34bb:
	/* 0x34bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34bf:
	/* 0x34bf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34c3:
	/* 0x34c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34c8:
	/* 0x34c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ca:
	/* 0x34ca: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ce:
	/* 0x34ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34d1:
	/* 0x34d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34d6:
	/* 0x34d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34db:
	/* 0x34db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34df:
	/* 0x34df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34e4:
	/* 0x34e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e6:
	/* 0x34e6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ea:
	/* 0x34ea: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34ef:
	/* 0x34ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34f4:
	/* 0x34f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34f9:
	/* 0x34f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34fd:
	/* 0x34fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3502:
	/* 0x3502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3504:
	/* 0x3504: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3508:
	/* 0x3508: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_350c:
	/* 0x350c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3511:
	/* 0x3511: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3516:
	/* 0x3516: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_351b:
	/* 0x351b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3520:
	/* 0x3520: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3525:
	/* 0x3525: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_352a:
	/* 0x352a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_352c:
	/* 0x352c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3531:
	/* 0x3531: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3536:
	/* 0x3536: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_353a:
	/* 0x353a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_353f:
	/* 0x353f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3544:
	/* 0x3544: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3549:
	/* 0x3549: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_354e:
	/* 0x354e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3550:
	/* 0x3550: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3555:
	/* 0x3555: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3558:
	/* 0x3558: je     35df <trace_ret_vfs_writev+0x35df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35df;
	}
x86_l_355e:
	/* 0x355e: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3563:
	/* 0x3563: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3566:
	/* 0x3566: je     35df <trace_ret_vfs_writev+0x35df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35df;
	}
x86_l_3568:
	/* 0x3568: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_356c:
	/* 0x356c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3571:
	/* 0x3571: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3576:
	/* 0x3576: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_357b:
	/* 0x357b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3580:
	/* 0x3580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3582:
	/* 0x3582: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3586:
	/* 0x3586: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3588:
	/* 0x3588: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_358e:
	/* 0x358e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3593:
	/* 0x3593: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3595:
	/* 0x3595: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_359b:
	/* 0x359b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35a0:
	/* 0x35a0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_35a6:
	/* 0x35a6: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35a9:
	/* 0x35a9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_35ab:
	/* 0x35ab: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_35b0:
	/* 0x35b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b2:
	/* 0x35b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35b5:
	/* 0x35b5: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_35bb:
	/* 0x35bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35c0:
	/* 0x35c0: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_35c3:
	/* 0x35c3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_35c9:
	/* 0x35c9: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_35ce:
	/* 0x35ce: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35d0:
	/* 0x35d0: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d5:
	/* 0x35d5: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35da:
	/* 0x35da: jmp    3660 <trace_ret_vfs_writev+0x3660> */
	return 13920ULL;
x86_l_35df:
	/* 0x35df: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_35e2:
	/* 0x35e2: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_35e8:
	/* 0x35e8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ec:
	/* 0x35ec: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_35f1:
	/* 0x35f1: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_35f7:
	/* 0x35f7: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35fb:
	/* 0x35fb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 13824ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13824ULL: goto x86_l_3600;
	case 13829ULL: goto x86_l_3605;
	case 13834ULL: goto x86_l_360a;
	case 13838ULL: goto x86_l_360e;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13849ULL: goto x86_l_3619;
	case 13853ULL: goto x86_l_361d;
	case 13856ULL: goto x86_l_3620;
	case 13861ULL: goto x86_l_3625;
	case 13866ULL: goto x86_l_362a;
	case 13870ULL: goto x86_l_362e;
	case 13875ULL: goto x86_l_3633;
	case 13877ULL: goto x86_l_3635;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13891ULL: goto x86_l_3643;
	case 13896ULL: goto x86_l_3648;
	case 13900ULL: goto x86_l_364c;
	case 13905ULL: goto x86_l_3651;
	case 13907ULL: goto x86_l_3653;
	case 13911ULL: goto x86_l_3657;
	case 13915ULL: goto x86_l_365b;
	case 13920ULL: goto x86_l_3660;
	case 13925ULL: goto x86_l_3665;
	case 13930ULL: goto x86_l_366a;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13945ULL: goto x86_l_3679;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13957ULL: goto x86_l_3685;
	case 13961ULL: goto x86_l_3689;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13976ULL: goto x86_l_3698;
	case 13981ULL: goto x86_l_369d;
	case 13983ULL: goto x86_l_369f;
	case 13988ULL: goto x86_l_36a4;
	case 13991ULL: goto x86_l_36a7;
	case 13997ULL: goto x86_l_36ad;
	case 14002ULL: goto x86_l_36b2;
	case 14005ULL: goto x86_l_36b5;
	case 14011ULL: goto x86_l_36bb;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14035ULL: goto x86_l_36d3;
	case 14037ULL: goto x86_l_36d5;
	case 14041ULL: goto x86_l_36d9;
	case 14043ULL: goto x86_l_36db;
	case 14049ULL: goto x86_l_36e1;
	case 14054ULL: goto x86_l_36e6;
	case 14056ULL: goto x86_l_36e8;
	case 14062ULL: goto x86_l_36ee;
	case 14067ULL: goto x86_l_36f3;
	case 14073ULL: goto x86_l_36f9;
	case 14076ULL: goto x86_l_36fc;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14085ULL: goto x86_l_3705;
	case 14088ULL: goto x86_l_3708;
	case 14094ULL: goto x86_l_370e;
	case 14099ULL: goto x86_l_3713;
	case 14102ULL: goto x86_l_3716;
	case 14108ULL: goto x86_l_371c;
	case 14113ULL: goto x86_l_3721;
	case 14115ULL: goto x86_l_3723;
	case 14120ULL: goto x86_l_3728;
	case 14125ULL: goto x86_l_372d;
	case 14131ULL: goto x86_l_3733;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14145ULL: goto x86_l_3741;
	case 14151ULL: goto x86_l_3747;
	case 14155ULL: goto x86_l_374b;
	case 14160ULL: goto x86_l_3750;
	case 14166ULL: goto x86_l_3756;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14180ULL: goto x86_l_3764;
	case 14185ULL: goto x86_l_3769;
	case 14189ULL: goto x86_l_376d;
	case 14193ULL: goto x86_l_3771;
	case 14198ULL: goto x86_l_3776;
	case 14200ULL: goto x86_l_3778;
	case 14204ULL: goto x86_l_377c;
	case 14207ULL: goto x86_l_377f;
	case 14212ULL: goto x86_l_3784;
	case 14217ULL: goto x86_l_3789;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14228ULL: goto x86_l_3794;
	case 14232ULL: goto x86_l_3798;
	case 14237ULL: goto x86_l_379d;
	case 14242ULL: goto x86_l_37a2;
	case 14247ULL: goto x86_l_37a7;
	case 14251ULL: goto x86_l_37ab;
	case 14256ULL: goto x86_l_37b0;
	case 14258ULL: goto x86_l_37b2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3600:
	/* 0x3600: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3605:
	/* 0x3605: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_360a:
	/* 0x360a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_360e:
	/* 0x360e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3612:
	/* 0x3612: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3617:
	/* 0x3617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3619:
	/* 0x3619: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_361d:
	/* 0x361d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3620:
	/* 0x3620: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3625:
	/* 0x3625: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_362a:
	/* 0x362a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_362e:
	/* 0x362e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3633:
	/* 0x3633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3635:
	/* 0x3635: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3639:
	/* 0x3639: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_363e:
	/* 0x363e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3643:
	/* 0x3643: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3648:
	/* 0x3648: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_364c:
	/* 0x364c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3651:
	/* 0x3651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3653:
	/* 0x3653: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3657:
	/* 0x3657: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_365b:
	/* 0x365b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3660:
	/* 0x3660: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3665:
	/* 0x3665: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_366a:
	/* 0x366a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_366f:
	/* 0x366f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3674:
	/* 0x3674: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3679:
	/* 0x3679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367b:
	/* 0x367b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3680:
	/* 0x3680: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3685:
	/* 0x3685: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3689:
	/* 0x3689: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_368e:
	/* 0x368e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3693:
	/* 0x3693: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3698:
	/* 0x3698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_369d:
	/* 0x369d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369f:
	/* 0x369f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a4:
	/* 0x36a4: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_36a7:
	/* 0x36a7: je     373e <trace_ret_vfs_writev+0x373e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_373e;
	}
x86_l_36ad:
	/* 0x36ad: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36b2:
	/* 0x36b2: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_36b5:
	/* 0x36b5: je     373e <trace_ret_vfs_writev+0x373e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_373e;
	}
x86_l_36bb:
	/* 0x36bb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36bf:
	/* 0x36bf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36c4:
	/* 0x36c4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_36c9:
	/* 0x36c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36ce:
	/* 0x36ce: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_36d3:
	/* 0x36d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d5:
	/* 0x36d5: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_36d9:
	/* 0x36d9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_36db:
	/* 0x36db: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_36e1:
	/* 0x36e1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36e6:
	/* 0x36e6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36e8:
	/* 0x36e8: jb     2306 <trace_ret_vfs_writev+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8966ULL;
	}
x86_l_36ee:
	/* 0x36ee: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36f3:
	/* 0x36f3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_36f9:
	/* 0x36f9: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36fc:
	/* 0x36fc: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_36fe:
	/* 0x36fe: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3703:
	/* 0x3703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3705:
	/* 0x3705: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3708:
	/* 0x3708: jl     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6635ULL;
	}
x86_l_370e:
	/* 0x370e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3713:
	/* 0x3713: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3716:
	/* 0x3716: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_371c:
	/* 0x371c: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3721:
	/* 0x3721: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3723:
	/* 0x3723: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3728:
	/* 0x3728: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_372d:
	/* 0x372d: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_3733:
	/* 0x3733: je     1a01 <trace_ret_vfs_writev+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6657ULL;
	}
x86_l_3739:
	/* 0x3739: jmp    1b4f <trace_ret_vfs_writev+0x1b4f> */
	return 6991ULL;
x86_l_373e:
	/* 0x373e: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3741:
	/* 0x3741: jne    19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6635ULL;
	}
x86_l_3747:
	/* 0x3747: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_374b:
	/* 0x374b: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3750:
	/* 0x3750: je     19eb <trace_ret_vfs_writev+0x19eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6635ULL;
	}
x86_l_3756:
	/* 0x3756: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_375a:
	/* 0x375a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375f:
	/* 0x375f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3764:
	/* 0x3764: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3769:
	/* 0x3769: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376d:
	/* 0x376d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3771:
	/* 0x3771: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3776:
	/* 0x3776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3778:
	/* 0x3778: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_377c:
	/* 0x377c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_377f:
	/* 0x377f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3784:
	/* 0x3784: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3789:
	/* 0x3789: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378d:
	/* 0x378d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3792:
	/* 0x3792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3794:
	/* 0x3794: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3798:
	/* 0x3798: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_379d:
	/* 0x379d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37a2:
	/* 0x37a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37a7:
	/* 0x37a7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37ab:
	/* 0x37ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b0:
	/* 0x37b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b2:
	/* 0x37b2: jmp    19eb <trace_ret_vfs_writev+0x19eb> */
	return 6635ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_vfs_writev_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12692U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2136ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2141ULL && __x86_pc <= 3893ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3896ULL && __x86_pc <= 5535ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5540ULL && __x86_pc <= 7123ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7128ULL && __x86_pc <= 8869ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8874ULL && __x86_pc <= 10520ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10525ULL && __x86_pc <= 12172ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12174ULL && __x86_pc <= 13819ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13824ULL && __x86_pc <= 14258ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

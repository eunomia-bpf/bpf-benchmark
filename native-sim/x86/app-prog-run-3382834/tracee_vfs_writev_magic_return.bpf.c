extern char args_map;
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
extern char io_file_path_cache_map;
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

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_0(
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
	case 50ULL: goto x86_l_32;
	case 57ULL: goto x86_l_39;
	case 65ULL: goto x86_l_41;
	case 70ULL: goto x86_l_46;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 81ULL: goto x86_l_51;
	case 89ULL: goto x86_l_59;
	case 92ULL: goto x86_l_5c;
	case 97ULL: goto x86_l_61;
	case 101ULL: goto x86_l_65;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 154ULL: goto x86_l_9a;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 164ULL: goto x86_l_a4;
	case 167ULL: goto x86_l_a7;
	case 171ULL: goto x86_l_ab;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 196ULL: goto x86_l_c4;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 221ULL: goto x86_l_dd;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 231ULL: goto x86_l_e7;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 239ULL: goto x86_l_ef;
	case 241ULL: goto x86_l_f1;
	case 245ULL: goto x86_l_f5;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 281ULL: goto x86_l_119;
	case 283ULL: goto x86_l_11b;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 306ULL: goto x86_l_132;
	case 308ULL: goto x86_l_134;
	case 311ULL: goto x86_l_137;
	case 313ULL: goto x86_l_139;
	case 315ULL: goto x86_l_13b;
	case 317ULL: goto x86_l_13d;
	case 322ULL: goto x86_l_142;
	case 330ULL: goto x86_l_14a;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 349ULL: goto x86_l_15d;
	case 352ULL: goto x86_l_160;
	case 358ULL: goto x86_l_166;
	case 361ULL: goto x86_l_169;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 402ULL: goto x86_l_192;
	case 410ULL: goto x86_l_19a;
	case 421ULL: goto x86_l_1a5;
	case 432ULL: goto x86_l_1b0;
	case 443ULL: goto x86_l_1bb;
	case 454ULL: goto x86_l_1c6;
	case 465ULL: goto x86_l_1d1;
	case 476ULL: goto x86_l_1dc;
	case 487ULL: goto x86_l_1e7;
	case 498ULL: goto x86_l_1f2;
	case 505ULL: goto x86_l_1f9;
	case 513ULL: goto x86_l_201;
	case 521ULL: goto x86_l_209;
	case 529ULL: goto x86_l_211;
	case 537ULL: goto x86_l_219;
	case 545ULL: goto x86_l_221;
	case 553ULL: goto x86_l_229;
	case 561ULL: goto x86_l_231;
	case 569ULL: goto x86_l_239;
	case 577ULL: goto x86_l_241;
	case 585ULL: goto x86_l_249;
	case 593ULL: goto x86_l_251;
	case 601ULL: goto x86_l_259;
	case 609ULL: goto x86_l_261;
	case 614ULL: goto x86_l_266;
	case 616ULL: goto x86_l_268;
	case 620ULL: goto x86_l_26c;
	case 624ULL: goto x86_l_270;
	case 628ULL: goto x86_l_274;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 643ULL: goto x86_l_283;
	case 646ULL: goto x86_l_286;
	case 651ULL: goto x86_l_28b;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 662ULL: goto x86_l_296;
	case 666ULL: goto x86_l_29a;
	case 670ULL: goto x86_l_29e;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 689ULL: goto x86_l_2b1;
	case 692ULL: goto x86_l_2b4;
	case 695ULL: goto x86_l_2b7;
	case 697ULL: goto x86_l_2b9;
	case 705ULL: goto x86_l_2c1;
	case 713ULL: goto x86_l_2c9;
	case 717ULL: goto x86_l_2cd;
	case 724ULL: goto x86_l_2d4;
	case 731ULL: goto x86_l_2db;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 746ULL: goto x86_l_2ea;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 757ULL: goto x86_l_2f5;
	case 763ULL: goto x86_l_2fb;
	case 769ULL: goto x86_l_301;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 806ULL: goto x86_l_326;
	case 813ULL: goto x86_l_32d;
	case 821ULL: goto x86_l_335;
	case 826ULL: goto x86_l_33a;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 840ULL: goto x86_l_348;
	case 844ULL: goto x86_l_34c;
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
	case 1049ULL: goto x86_l_419;
	case 1060ULL: goto x86_l_424;
	case 1071ULL: goto x86_l_42f;
	case 1082ULL: goto x86_l_43a;
	case 1093ULL: goto x86_l_445;
	case 1104ULL: goto x86_l_450;
	case 1115ULL: goto x86_l_45b;
	case 1126ULL: goto x86_l_466;
	case 1137ULL: goto x86_l_471;
	case 1148ULL: goto x86_l_47c;
	case 1159ULL: goto x86_l_487;
	case 1170ULL: goto x86_l_492;
	case 1181ULL: goto x86_l_49d;
	case 1189ULL: goto x86_l_4a5;
	case 1197ULL: goto x86_l_4ad;
	case 1205ULL: goto x86_l_4b5;
	case 1213ULL: goto x86_l_4bd;
	case 1221ULL: goto x86_l_4c5;
	case 1229ULL: goto x86_l_4cd;
	case 1237ULL: goto x86_l_4d5;
	case 1245ULL: goto x86_l_4dd;
	case 1253ULL: goto x86_l_4e5;
	case 1261ULL: goto x86_l_4ed;
	case 1269ULL: goto x86_l_4f5;
	case 1277ULL: goto x86_l_4fd;
	case 1285ULL: goto x86_l_505;
	case 1293ULL: goto x86_l_50d;
	case 1301ULL: goto x86_l_515;
	case 1308ULL: goto x86_l_51c;
	case 1315ULL: goto x86_l_523;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1336ULL: goto x86_l_538;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1356ULL: goto x86_l_54c;
	case 1359ULL: goto x86_l_54f;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1382ULL: goto x86_l_566;
	case 1386ULL: goto x86_l_56a;
	case 1397ULL: goto x86_l_575;
	case 1404ULL: goto x86_l_57c;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1423ULL: goto x86_l_58f;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1434ULL: goto x86_l_59a;
	case 1437ULL: goto x86_l_59d;
	case 1445ULL: goto x86_l_5a5;
	case 1449ULL: goto x86_l_5a9;
	case 1456ULL: goto x86_l_5b0;
	case 1467ULL: goto x86_l_5bb;
	case 1478ULL: goto x86_l_5c6;
	case 1489ULL: goto x86_l_5d1;
	case 1500ULL: goto x86_l_5dc;
	case 1511ULL: goto x86_l_5e7;
	case 1522ULL: goto x86_l_5f2;
	case 1533ULL: goto x86_l_5fd;
	case 1544ULL: goto x86_l_608;
	case 1555ULL: goto x86_l_613;
	case 1563ULL: goto x86_l_61b;
	case 1571ULL: goto x86_l_623;
	case 1579ULL: goto x86_l_62b;
	case 1587ULL: goto x86_l_633;
	case 1595ULL: goto x86_l_63b;
	case 1603ULL: goto x86_l_643;
	case 1611ULL: goto x86_l_64b;
	case 1619ULL: goto x86_l_653;
	case 1627ULL: goto x86_l_65b;
	case 1635ULL: goto x86_l_663;
	case 1643ULL: goto x86_l_66b;
	case 1651ULL: goto x86_l_673;
	case 1659ULL: goto x86_l_67b;
	case 1667ULL: goto x86_l_683;
	case 1675ULL: goto x86_l_68b;
	case 1682ULL: goto x86_l_692;
	case 1689ULL: goto x86_l_699;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1736ULL: goto x86_l_6c8;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1751ULL: goto x86_l_6d7;
	case 1755ULL: goto x86_l_6db;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1791ULL: goto x86_l_6ff;
	case 1799ULL: goto x86_l_707;
	case 1803ULL: goto x86_l_70b;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1836ULL: goto x86_l_72c;
	case 1840ULL: goto x86_l_730;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1873ULL: goto x86_l_751;
	case 1877ULL: goto x86_l_755;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1909ULL: goto x86_l_775;
	case 1912ULL: goto x86_l_778;
	case 1920ULL: goto x86_l_780;
	case 1924ULL: goto x86_l_784;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1960ULL: goto x86_l_7a8;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1986ULL: goto x86_l_7c2;
	case 1988ULL: goto x86_l_7c4;
	case 1995ULL: goto x86_l_7cb;
	case 1999ULL: goto x86_l_7cf;
	case 2003ULL: goto x86_l_7d3;
	case 2007ULL: goto x86_l_7d7;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2032ULL: goto x86_l_7f0;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2078ULL: goto x86_l_81e;
	case 2082ULL: goto x86_l_822;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2107ULL: goto x86_l_83b;
	case 2115ULL: goto x86_l_843;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2180ULL: goto x86_l_884;
	case 2185ULL: goto x86_l_889;
	case 2187ULL: goto x86_l_88b;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2228ULL: goto x86_l_8b4;
	case 2236ULL: goto x86_l_8bc;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2259ULL: goto x86_l_8d3;
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
	/* 0xa: sub    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 328ULL);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: movabs rbx,0x2d700000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3122441224192ULL);
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
	/* 0x27: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a:
	/* 0x2a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_32:
	/* 0x32: mov    rdi,QWORD PTR [rip+0x37b8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_39:
	/* 0x39: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_41:
	/* 0x41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46:
	/* 0x46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48:
	/* 0x48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_51:
	/* 0x51: mov    QWORD PTR [rsp+0x140],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_59:
	/* 0x59: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c:
	/* 0x5c: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61:
	/* 0x61: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65:
	/* 0x65: mov    r15,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69:
	/* 0x69: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6e:
	/* 0x6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70:
	/* 0x70: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72:
	/* 0x72: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_75:
	/* 0x75: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7d:
	/* 0x7d: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_84:
	/* 0x84: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8c:
	/* 0x8c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_98:
	/* 0x98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a:
	/* 0x9a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_a2:
	/* 0xa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4:
	/* 0xa4: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab:
	/* 0xab: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b3:
	/* 0xb3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b8:
	/* 0xb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bd:
	/* 0xbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c2:
	/* 0xc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4:
	/* 0xc4: test   DWORD PTR [rsp+0xb0],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755916341248ULL);
x86_l_cf:
	/* 0xcf: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_d4:
	/* 0xd4: jne    142 <vfs_writev_magic_return+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_142;
	}
x86_l_d6:
	/* 0xd6: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_db:
	/* 0xdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd:
	/* 0xdd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e0:
	/* 0xe0: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_e5:
	/* 0xe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7:
	/* 0xe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea:
	/* 0xea: je     f1 <vfs_writev_magic_return+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f1;
	}
x86_l_ec:
	/* 0xec: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ef:
	/* 0xef: jmp    f1 <vfs_writev_magic_return+0xf1> */
	goto x86_l_f1;
x86_l_f1:
	/* 0xf1: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5:
	/* 0xf5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fd:
	/* 0xfd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_102:
	/* 0x102: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107:
	/* 0x107: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10c:
	/* 0x10c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111:
	/* 0x111: test   BYTE PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_119:
	/* 0x119: jne    121 <vfs_writev_magic_return+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_121;
	}
x86_l_11b:
	/* 0x11b: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11f:
	/* 0x11f: jmp    142 <vfs_writev_magic_return+0x142> */
	goto x86_l_142;
x86_l_121:
	/* 0x121: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_128:
	/* 0x128: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12d:
	/* 0x12d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132:
	/* 0x132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134:
	/* 0x134: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_137:
	/* 0x137: je     13d <vfs_writev_magic_return+0x13d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d;
	}
x86_l_139:
	/* 0x139: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b:
	/* 0x13b: jmp    142 <vfs_writev_magic_return+0x142> */
	goto x86_l_142;
x86_l_13d:
	/* 0x13d: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_142:
	/* 0x142: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_14a:
	/* 0x14a: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_151:
	/* 0x151: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
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
	/* 0x160: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_166:
	/* 0x166: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_170:
	/* 0x170: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_175:
	/* 0x175: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a:
	/* 0x17a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c:
	/* 0x17c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f:
	/* 0x17f: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_185:
	/* 0x185: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_188:
	/* 0x188: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_192:
	/* 0x192: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_1a5:
	/* 0x1a5: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1bb:
	/* 0x1bb: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1dc:
	/* 0x1dc: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1e7:
	/* 0x1e7: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1f2:
	/* 0x1f2: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1f9:
	/* 0x1f9: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_201:
	/* 0x201: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_209:
	/* 0x209: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_211:
	/* 0x211: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_219:
	/* 0x219: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_221:
	/* 0x221: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_229:
	/* 0x229: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_231:
	/* 0x231: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_239:
	/* 0x239: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_241:
	/* 0x241: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_249:
	/* 0x249: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_251:
	/* 0x251: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_259:
	/* 0x259: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_261:
	/* 0x261: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26c:
	/* 0x26c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_270:
	/* 0x270: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_274:
	/* 0x274: mov    DWORD PTR [r14+0x70],0x2d7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337879ULL);
x86_l_27c:
	/* 0x27c: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_281:
	/* 0x281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283:
	/* 0x283: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286:
	/* 0x286: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_28b:
	/* 0x28b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d:
	/* 0x28d: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_292:
	/* 0x292: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_296:
	/* 0x296: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_29a:
	/* 0x29a: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29e:
	/* 0x29e: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2a5:
	/* 0x2a5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aa:
	/* 0x2aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2af:
	/* 0x2af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1:
	/* 0x2b1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7:
	/* 0x2b7: je     313 <vfs_writev_magic_return+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313;
	}
x86_l_2b9:
	/* 0x2b9: mov    QWORD PTR [rsp+0x110],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2c1:
	/* 0x2c1: mov    QWORD PTR [rsp+0x120],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2c9:
	/* 0x2c9: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd:
	/* 0x2cd: mov    DWORD PTR [rsp+0x10c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_2d4:
	/* 0x2d4: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2db:
	/* 0x2db: lea    rsi,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_2e3:
	/* 0x2e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e8:
	/* 0x2e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea:
	/* 0x2ea: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ed:
	/* 0x2ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f5:
	/* 0x2f5: je     55a <vfs_writev_magic_return+0x55a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55a;
	}
x86_l_2fb:
	/* 0x2fb: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_301:
	/* 0x301: jne    c41 <vfs_writev_magic_return+0xc41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3137ULL;
	}
x86_l_307:
	/* 0x307: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_30c:
	/* 0x30c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e:
	/* 0x30e: jmp    d06 <vfs_writev_magic_return+0xd06> */
	return 3334ULL;
x86_l_313:
	/* 0x313: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_317:
	/* 0x317: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31b:
	/* 0x31b: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_326:
	/* 0x326: mov    rdi,QWORD PTR [rip+0x37b8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_32d:
	/* 0x32d: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_335:
	/* 0x335: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33a:
	/* 0x33a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c:
	/* 0x33c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f:
	/* 0x33f: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_345:
	/* 0x345: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_348:
	/* 0x348: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34c:
	/* 0x34c: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_353:
	/* 0x353: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_35e:
	/* 0x35e: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_369:
	/* 0x369: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_374:
	/* 0x374: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_37f:
	/* 0x37f: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_38a:
	/* 0x38a: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_395:
	/* 0x395: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_3c1:
	/* 0x3c1: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3cc:
	/* 0x3cc: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3e2:
	/* 0x3e2: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3ed:
	/* 0x3ed: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3f8:
	/* 0x3f8: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_403:
	/* 0x403: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_40e:
	/* 0x40e: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_419:
	/* 0x419: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_42f:
	/* 0x42f: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_43a:
	/* 0x43a: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_450:
	/* 0x450: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_471:
	/* 0x471: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_492:
	/* 0x492: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4a5:
	/* 0x4a5: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4ad:
	/* 0x4ad: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4b5:
	/* 0x4b5: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4bd:
	/* 0x4bd: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4cd:
	/* 0x4cd: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4d5:
	/* 0x4d5: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4e5:
	/* 0x4e5: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4f5:
	/* 0x4f5: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4fd:
	/* 0x4fd: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_505:
	/* 0x505: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_50d:
	/* 0x50d: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_515:
	/* 0x515: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51c:
	/* 0x51c: mov    rbx,QWORD PTR [rip+0x37b8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_523:
	/* 0x523: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_52b:
	/* 0x52b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_530:
	/* 0x530: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_535:
	/* 0x535: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_538:
	/* 0x538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53a:
	/* 0x53a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53f:
	/* 0x53f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_544:
	/* 0x544: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_547:
	/* 0x547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549:
	/* 0x549: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_54c:
	/* 0x54c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54f:
	/* 0x54f: jne    2b9 <vfs_writev_magic_return+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9;
	}
x86_l_555:
	/* 0x555: jmp    2db8 <vfs_writev_magic_return+0x2db8> */
	return 11704ULL;
x86_l_55a:
	/* 0x55a: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55f:
	/* 0x55f: mov    eax,DWORD PTR [rsp+0x10c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_566:
	/* 0x566: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56a:
	/* 0x56a: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_575:
	/* 0x575: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_57c:
	/* 0x57c: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_584:
	/* 0x584: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_589:
	/* 0x589: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_58f:
	/* 0x58f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_591:
	/* 0x591: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_594:
	/* 0x594: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_59a:
	/* 0x59a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_5a5:
	/* 0x5a5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a9:
	/* 0x5a9: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_5bb:
	/* 0x5bb: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5d1:
	/* 0x5d1: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_608:
	/* 0x608: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_613:
	/* 0x613: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_61b:
	/* 0x61b: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_63b:
	/* 0x63b: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_643:
	/* 0x643: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_64b:
	/* 0x64b: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_653:
	/* 0x653: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_65b:
	/* 0x65b: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_663:
	/* 0x663: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_66b:
	/* 0x66b: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_673:
	/* 0x673: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_67b:
	/* 0x67b: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_683:
	/* 0x683: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_68b:
	/* 0x68b: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: mov    rbx,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_699:
	/* 0x699: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6a6:
	/* 0x6a6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6ab:
	/* 0x6ab: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6ae:
	/* 0x6ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b0:
	/* 0x6b0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b5:
	/* 0x6b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ba:
	/* 0x6ba: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6bd:
	/* 0x6bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bf:
	/* 0x6bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_6c8:
	/* 0x6c8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d0:
	/* 0x6d0: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_6d7:
	/* 0x6d7: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6db:
	/* 0x6db: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6e3:
	/* 0x6e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ed:
	/* 0x6ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f2:
	/* 0x6f2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6ff:
	/* 0x6ff: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_707:
	/* 0x707: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_70b:
	/* 0x70b: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_724:
	/* 0x724: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_72c:
	/* 0x72c: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_730:
	/* 0x730: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_738:
	/* 0x738: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_73d:
	/* 0x73d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_742:
	/* 0x742: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_751:
	/* 0x751: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_755:
	/* 0x755: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_75d:
	/* 0x75d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_762:
	/* 0x762: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_767:
	/* 0x767: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_76c:
	/* 0x76c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76e:
	/* 0x76e: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_775:
	/* 0x775: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_778:
	/* 0x778: mov    QWORD PTR [rsp+0x130],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_780:
	/* 0x780: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_784:
	/* 0x784: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x7a0: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7a8:
	/* 0x7a8: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7b0:
	/* 0x7b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7b5:
	/* 0x7b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ba:
	/* 0x7ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7bf:
	/* 0x7bf: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7c2:
	/* 0x7c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c4:
	/* 0x7c4: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7cb:
	/* 0x7cb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7cf:
	/* 0x7cf: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7d3:
	/* 0x7d3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7d7:
	/* 0x7d7: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7df:
	/* 0x7df: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7e4:
	/* 0x7e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e9:
	/* 0x7e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7ee:
	/* 0x7ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f0:
	/* 0x7f0: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7f7:
	/* 0x7f7: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7fa:
	/* 0x7fa: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_802:
	/* 0x802: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_807:
	/* 0x807: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80c:
	/* 0x80c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_811:
	/* 0x811: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_814:
	/* 0x814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_816:
	/* 0x816: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_81e:
	/* 0x81e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_822:
	/* 0x822: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_82a:
	/* 0x82a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_82f:
	/* 0x82f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_834:
	/* 0x834: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_839:
	/* 0x839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83b:
	/* 0x83b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_843:
	/* 0x843: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_84b:
	/* 0x84b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_850:
	/* 0x850: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_855:
	/* 0x855: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_85a:
	/* 0x85a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85f:
	/* 0x85f: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_866:
	/* 0x866: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_86a:
	/* 0x86a: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_86e:
	/* 0x86e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_872:
	/* 0x872: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_87a:
	/* 0x87a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_87f:
	/* 0x87f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_884:
	/* 0x884: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_889:
	/* 0x889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88b:
	/* 0x88b: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_892:
	/* 0x892: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_895:
	/* 0x895: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_89d:
	/* 0x89d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8a2:
	/* 0x8a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a7:
	/* 0x8a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ac:
	/* 0x8ac: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8af:
	/* 0x8af: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b4:
	/* 0x8b4: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8bc:
	/* 0x8bc: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8c4:
	/* 0x8c4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8c9:
	/* 0x8c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ce:
	/* 0x8ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8d3:
	/* 0x8d3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
	return 2262ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2271ULL: goto x86_l_8df;
	case 2275ULL: goto x86_l_8e3;
	case 2279ULL: goto x86_l_8e7;
	case 2283ULL: goto x86_l_8eb;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2308ULL: goto x86_l_904;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2386ULL: goto x86_l_952;
	case 2388ULL: goto x86_l_954;
	case 2396ULL: goto x86_l_95c;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2422ULL: goto x86_l_976;
	case 2424ULL: goto x86_l_978;
	case 2431ULL: goto x86_l_97f;
	case 2435ULL: goto x86_l_983;
	case 2439ULL: goto x86_l_987;
	case 2443ULL: goto x86_l_98b;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2468ULL: goto x86_l_9a4;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2505ULL: goto x86_l_9c9;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2550ULL: goto x86_l_9f6;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2573ULL: goto x86_l_a0d;
	case 2576ULL: goto x86_l_a10;
	case 2578ULL: goto x86_l_a12;
	case 2585ULL: goto x86_l_a19;
	case 2589ULL: goto x86_l_a1d;
	case 2593ULL: goto x86_l_a21;
	case 2597ULL: goto x86_l_a25;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2622ULL: goto x86_l_a3e;
	case 2629ULL: goto x86_l_a45;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2645ULL: goto x86_l_a55;
	case 2652ULL: goto x86_l_a5c;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2678ULL: goto x86_l_a76;
	case 2680ULL: goto x86_l_a78;
	case 2688ULL: goto x86_l_a80;
	case 2692ULL: goto x86_l_a84;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2717ULL: goto x86_l_a9d;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2778ULL: goto x86_l_ada;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2803ULL: goto x86_l_af3;
	case 2811ULL: goto x86_l_afb;
	case 2815ULL: goto x86_l_aff;
	case 2823ULL: goto x86_l_b07;
	case 2827ULL: goto x86_l_b0b;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2860ULL: goto x86_l_b2c;
	case 2864ULL: goto x86_l_b30;
	case 2868ULL: goto x86_l_b34;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2896ULL: goto x86_l_b50;
	case 2904ULL: goto x86_l_b58;
	case 2908ULL: goto x86_l_b5c;
	case 2916ULL: goto x86_l_b64;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2944ULL: goto x86_l_b80;
	case 2952ULL: goto x86_l_b88;
	case 2954ULL: goto x86_l_b8a;
	case 2959ULL: goto x86_l_b8f;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3032ULL: goto x86_l_bd8;
	case 3040ULL: goto x86_l_be0;
	case 3045ULL: goto x86_l_be5;
	case 3050ULL: goto x86_l_bea;
	case 3055ULL: goto x86_l_bef;
	case 3057ULL: goto x86_l_bf1;
	case 3065ULL: goto x86_l_bf9;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3131ULL: goto x86_l_c3b;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3206ULL: goto x86_l_c86;
	case 3214ULL: goto x86_l_c8e;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3255ULL: goto x86_l_cb7;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3280ULL: goto x86_l_cd0;
	case 3288ULL: goto x86_l_cd8;
	case 3291ULL: goto x86_l_cdb;
	case 3293ULL: goto x86_l_cdd;
	case 3297ULL: goto x86_l_ce1;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3322ULL: goto x86_l_cfa;
	case 3330ULL: goto x86_l_d02;
	case 3332ULL: goto x86_l_d04;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3342ULL: goto x86_l_d0e;
	case 3346ULL: goto x86_l_d12;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3373ULL: goto x86_l_d2d;
	case 3380ULL: goto x86_l_d34;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3410ULL: goto x86_l_d52;
	case 3421ULL: goto x86_l_d5d;
	case 3432ULL: goto x86_l_d68;
	case 3440ULL: goto x86_l_d70;
	case 3447ULL: goto x86_l_d77;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3511ULL: goto x86_l_db7;
	case 3515ULL: goto x86_l_dbb;
	case 3519ULL: goto x86_l_dbf;
	case 3526ULL: goto x86_l_dc6;
	case 3533ULL: goto x86_l_dcd;
	case 3537ULL: goto x86_l_dd1;
	case 3544ULL: goto x86_l_dd8;
	case 3548ULL: goto x86_l_ddc;
	case 3555ULL: goto x86_l_de3;
	case 3559ULL: goto x86_l_de7;
	case 3566ULL: goto x86_l_dee;
	case 3570ULL: goto x86_l_df2;
	case 3577ULL: goto x86_l_df9;
	case 3584ULL: goto x86_l_e00;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3599ULL: goto x86_l_e0f;
	case 3607ULL: goto x86_l_e17;
	case 3609ULL: goto x86_l_e19;
	case 3611ULL: goto x86_l_e1b;
	case 3613ULL: goto x86_l_e1d;
	case 3616ULL: goto x86_l_e20;
	case 3623ULL: goto x86_l_e27;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3650ULL: goto x86_l_e42;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3663ULL: goto x86_l_e4f;
	case 3666ULL: goto x86_l_e52;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3700ULL: goto x86_l_e74;
	case 3708ULL: goto x86_l_e7c;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3737ULL: goto x86_l_e99;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3769ULL: goto x86_l_eb9;
	case 3772ULL: goto x86_l_ebc;
	case 3775ULL: goto x86_l_ebf;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3793ULL: goto x86_l_ed1;
	case 3795ULL: goto x86_l_ed3;
	case 3798ULL: goto x86_l_ed6;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3846ULL: goto x86_l_f06;
	case 3852ULL: goto x86_l_f0c;
	case 3859ULL: goto x86_l_f13;
	case 3867ULL: goto x86_l_f1b;
	case 3874ULL: goto x86_l_f22;
	case 3881ULL: goto x86_l_f29;
	case 3889ULL: goto x86_l_f31;
	case 3897ULL: goto x86_l_f39;
	case 3904ULL: goto x86_l_f40;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3926ULL: goto x86_l_f56;
	case 3934ULL: goto x86_l_f5e;
	case 3941ULL: goto x86_l_f65;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3964ULL: goto x86_l_f7c;
	case 3967ULL: goto x86_l_f7f;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3976ULL: goto x86_l_f88;
	case 3979ULL: goto x86_l_f8b;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3991ULL: goto x86_l_f97;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4005ULL: goto x86_l_fa5;
	case 4007ULL: goto x86_l_fa7;
	case 4011ULL: goto x86_l_fab;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4037ULL: goto x86_l_fc5;
	case 4045ULL: goto x86_l_fcd;
	case 4052ULL: goto x86_l_fd4;
	case 4055ULL: goto x86_l_fd7;
	case 4057ULL: goto x86_l_fd9;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4073ULL: goto x86_l_fe9;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4080ULL: goto x86_l_ff0;
	case 4083ULL: goto x86_l_ff3;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4099ULL: goto x86_l_1003;
	case 4106ULL: goto x86_l_100a;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	default: return 0xffffffffffffffffULL;
	}
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8df:
	/* 0x8df: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8e3:
	/* 0x8e3: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8e7:
	/* 0x8e7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8eb:
	/* 0x8eb: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8f3:
	/* 0x8f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8f8:
	/* 0x8f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fd:
	/* 0x8fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_902:
	/* 0x902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_904:
	/* 0x904: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_90c:
	/* 0x90c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_910:
	/* 0x910: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_918:
	/* 0x918: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_91d:
	/* 0x91d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_922:
	/* 0x922: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_92c:
	/* 0x92c: mov    ebp,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_933:
	/* 0x933: lea    r15,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_938:
	/* 0x938: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_940:
	/* 0x940: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_945:
	/* 0x945: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94a:
	/* 0x94a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_94f:
	/* 0x94f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_952:
	/* 0x952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_954:
	/* 0x954: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_95c:
	/* 0x95c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_964:
	/* 0x964: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_969:
	/* 0x969: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96e:
	/* 0x96e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_973:
	/* 0x973: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_976:
	/* 0x976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_978:
	/* 0x978: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_97f:
	/* 0x97f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_983:
	/* 0x983: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_987:
	/* 0x987: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_98b:
	/* 0x98b: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_993:
	/* 0x993: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_998:
	/* 0x998: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_99d:
	/* 0x99d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a2:
	/* 0x9a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a4:
	/* 0x9a4: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9ac:
	/* 0x9ac: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_9b0:
	/* 0x9b0: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9b8:
	/* 0x9b8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9bd:
	/* 0x9bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c2:
	/* 0x9c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9c7:
	/* 0x9c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c9:
	/* 0x9c9: cmp    ebp,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 176ULL);
x86_l_9d0:
	/* 0x9d0: jne    a49 <vfs_writev_magic_return+0xa49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a49;
	}
x86_l_9d2:
	/* 0x9d2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9da:
	/* 0x9da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9df:
	/* 0x9df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9e4:
	/* 0x9e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e9:
	/* 0x9e9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9ec:
	/* 0x9ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ee:
	/* 0x9ee: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9f6:
	/* 0x9f6: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9fe:
	/* 0x9fe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a03:
	/* 0xa03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a08:
	/* 0xa08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0d:
	/* 0xa0d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a10:
	/* 0xa10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a12:
	/* 0xa12: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a19:
	/* 0xa19: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_a1d:
	/* 0xa1d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a21:
	/* 0xa21: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a25:
	/* 0xa25: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a2d:
	/* 0xa2d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a32:
	/* 0xa32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a37:
	/* 0xa37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a3c:
	/* 0xa3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3e:
	/* 0xa3e: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a45:
	/* 0xa45: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a49:
	/* 0xa49: mov    DWORD PTR [r13+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a4d:
	/* 0xa4d: mov    rbx,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_a55:
	/* 0xa55: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a5c:
	/* 0xa5c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a64:
	/* 0xa64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a69:
	/* 0xa69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a6e:
	/* 0xa6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a73:
	/* 0xa73: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a76:
	/* 0xa76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a78:
	/* 0xa78: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a80:
	/* 0xa80: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a84:
	/* 0xa84: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a8c:
	/* 0xa8c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a91:
	/* 0xa91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a96:
	/* 0xa96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a9b:
	/* 0xa9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9d:
	/* 0xa9d: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aa5:
	/* 0xaa5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aaa:
	/* 0xaaa: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_aaf:
	/* 0xaaf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ab4:
	/* 0xab4: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_abc:
	/* 0xabc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ac1:
	/* 0xac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac3:
	/* 0xac3: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ac7:
	/* 0xac7: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_ad0:
	/* 0xad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad2:
	/* 0xad2: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad6:
	/* 0xad6: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ada:
	/* 0xada: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0xaf3: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_afb:
	/* 0xafb: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aff:
	/* 0xaff: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b07:
	/* 0xb07: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_b0b:
	/* 0xb0b: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b13:
	/* 0xb13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b18:
	/* 0xb18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1d:
	/* 0xb1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b22:
	/* 0xb22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b24:
	/* 0xb24: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b2c:
	/* 0xb2c: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b30:
	/* 0xb30: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_b34:
	/* 0xb34: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b3c:
	/* 0xb3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b41:
	/* 0xb41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b46:
	/* 0xb46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b4b:
	/* 0xb4b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b50:
	/* 0xb50: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b58:
	/* 0xb58: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b5c:
	/* 0xb5c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b64:
	/* 0xb64: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b69:
	/* 0xb69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6e:
	/* 0xb6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b73:
	/* 0xb73: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b76:
	/* 0xb76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b78:
	/* 0xb78: test   BYTE PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_b80:
	/* 0xb80: mov    r12,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_b88:
	/* 0xb88: je     b8f <vfs_writev_magic_return+0xb8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8f;
	}
x86_l_b8a:
	/* 0xb8a: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_b8f:
	/* 0xb8f: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_b97:
	/* 0xb97: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b9b:
	/* 0xb9b: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_ba3:
	/* 0xba3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ba8:
	/* 0xba8: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_bad:
	/* 0xbad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_bb2:
	/* 0xbb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb4:
	/* 0xbb4: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bbc:
	/* 0xbbc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bc1:
	/* 0xbc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc6:
	/* 0xbc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bcb:
	/* 0xbcb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_bce:
	/* 0xbce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd0:
	/* 0xbd0: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bd8:
	/* 0xbd8: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_be0:
	/* 0xbe0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be5:
	/* 0xbe5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bea:
	/* 0xbea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bef:
	/* 0xbef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf1:
	/* 0xbf1: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bf9:
	/* 0xbf9: lea    rbx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c01:
	/* 0xc01: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_c06:
	/* 0xc06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c0b:
	/* 0xc0b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c0e:
	/* 0xc0e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_c13:
	/* 0xc13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c15:
	/* 0xc15: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_c18:
	/* 0xc18: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_c1c:
	/* 0xc1c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_c21:
	/* 0xc21: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_c26:
	/* 0xc26: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c2b:
	/* 0xc2b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_c2e:
	/* 0xc2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c30:
	/* 0xc30: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c35:
	/* 0xc35: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_c3b:
	/* 0xc3b: je     307 <vfs_writev_magic_return+0x307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 775ULL;
	}
x86_l_c41:
	/* 0xc41: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_c46:
	/* 0xc46: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_c4d:
	/* 0xc4d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c52:
	/* 0xc52: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c57:
	/* 0xc57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c5c:
	/* 0xc5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c61:
	/* 0xc61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c63:
	/* 0xc63: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c68:
	/* 0xc68: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c70:
	/* 0xc70: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c75:
	/* 0xc75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c7a:
	/* 0xc7a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c7f:
	/* 0xc7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c84:
	/* 0xc84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c86:
	/* 0xc86: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c8e:
	/* 0xc8e: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c96:
	/* 0xc96: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c9b:
	/* 0xc9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ca0:
	/* 0xca0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ca8:
	/* 0xca8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cad:
	/* 0xcad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caf:
	/* 0xcaf: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cb7:
	/* 0xcb7: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cbf:
	/* 0xcbf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cc4:
	/* 0xcc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cc9:
	/* 0xcc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cce:
	/* 0xcce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd0:
	/* 0xcd0: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cd8:
	/* 0xcd8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_cdb:
	/* 0xcdb: je     d04 <vfs_writev_magic_return+0xd04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d04;
	}
x86_l_cdd:
	/* 0xcdd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ce1:
	/* 0xce1: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ce9:
	/* 0xce9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cee:
	/* 0xcee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cf3:
	/* 0xcf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf8:
	/* 0xcf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfa:
	/* 0xcfa: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d02:
	/* 0xd02: jmp    d06 <vfs_writev_magic_return+0xd06> */
	goto x86_l_d06;
x86_l_d04:
	/* 0xd04: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d06:
	/* 0xd06: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0a:
	/* 0xd0a: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0e:
	/* 0xd0e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d12:
	/* 0xd12: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_d19:
	/* 0xd19: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d1e:
	/* 0xd1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d23:
	/* 0xd23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d25:
	/* 0xd25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d28:
	/* 0xd28: je     d41 <vfs_writev_magic_return+0xd41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d41;
	}
x86_l_d2a:
	/* 0xd2a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d2d:
	/* 0xd2d: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_d34:
	/* 0xd34: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_d37:
	/* 0xd37: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_d3a:
	/* 0xd3a: jne    d41 <vfs_writev_magic_return+0xd41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d41;
	}
x86_l_d3c:
	/* 0xd3c: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_d41:
	/* 0xd41: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_d46:
	/* 0xd46: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_d4c:
	/* 0xd4c: jne    2d84 <vfs_writev_magic_return+0x2d84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11652ULL;
	}
x86_l_d52:
	/* 0xd52: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_d5d:
	/* 0xd5d: mov    DWORD PTR [rsp+0xb0],0x2d7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244823ULL);
x86_l_d68:
	/* 0xd68: mov    WORD PTR [rsp+0x80],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d7f:
	/* 0xd7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d84:
	/* 0xd84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d86:
	/* 0xd86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d89:
	/* 0xd89: je     df9 <vfs_writev_magic_return+0xdf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df9;
	}
x86_l_d8b:
	/* 0xd8b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d8e:
	/* 0xd8e: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d96:
	/* 0xd96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d9b:
	/* 0xd9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9d:
	/* 0xd9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: je     df9 <vfs_writev_magic_return+0xdf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df9;
	}
x86_l_da2:
	/* 0xda2: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da6:
	/* 0xda6: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_dad:
	/* 0xdad: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db0:
	/* 0xdb0: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_db7:
	/* 0xdb7: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbb:
	/* 0xdbb: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dbf:
	/* 0xdbf: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_dc6:
	/* 0xdc6: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_dcd:
	/* 0xdcd: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd1:
	/* 0xdd1: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_dd8:
	/* 0xdd8: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ddc:
	/* 0xddc: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_de3:
	/* 0xde3: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de7:
	/* 0xde7: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_dee:
	/* 0xdee: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_df2:
	/* 0xdf2: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_df9:
	/* 0xdf9: mov    rdx,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_e00:
	/* 0xe00: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e07:
	/* 0xe07: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e0b:
	/* 0xe0b: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_e0f:
	/* 0xe0f: mov    QWORD PTR [rsp+0x130],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_e17:
	/* 0xe17: jne    e32 <vfs_writev_magic_return+0xe32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e32;
	}
x86_l_e19:
	/* 0xe19: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1b:
	/* 0xe1b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1d:
	/* 0xe1d: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e27:
	/* 0xe27: jne    16d6 <vfs_writev_magic_return+0x16d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5846ULL;
	}
x86_l_e2d:
	/* 0xe2d: jmp    2dba <vfs_writev_magic_return+0x2dba> */
	return 11706ULL;
x86_l_e32:
	/* 0xe32: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_e39:
	/* 0xe39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3c:
	/* 0xe3c: je     ffc <vfs_writev_magic_return+0xffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ffc;
	}
x86_l_e42:
	/* 0xe42: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_e4a:
	/* 0xe4a: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_e4d:
	/* 0xe4d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4f:
	/* 0xe4f: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_e52:
	/* 0xe52: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_e56:
	/* 0xe56: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e59:
	/* 0xe59: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e5c:
	/* 0xe5c: xor    rbp,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_e63:
	/* 0xe63: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e66:
	/* 0xe66: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e6d:
	/* 0xe6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e70:
	/* 0xe70: je     e99 <vfs_writev_magic_return+0xe99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e99;
	}
x86_l_e72:
	/* 0xe72: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e74:
	/* 0xe74: mov    rdx,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_e7c:
	/* 0xe7c: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_e83:
	/* 0xe83: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_e86:
	/* 0xe86: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e89:
	/* 0xe89: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e8c:
	/* 0xe8c: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_e93:
	/* 0xe93: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e96:
	/* 0xe96: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e99:
	/* 0xe99: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_ea0:
	/* 0xea0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea3:
	/* 0xea3: je     ebf <vfs_writev_magic_return+0xebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebf;
	}
x86_l_ea5:
	/* 0xea5: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ea9:
	/* 0xea9: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eac:
	/* 0xeac: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_eaf:
	/* 0xeaf: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_eb2:
	/* 0xeb2: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_eb9:
	/* 0xeb9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ebc:
	/* 0xebc: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ebf:
	/* 0xebf: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_ec6:
	/* 0xec6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec9:
	/* 0xec9: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_ed1:
	/* 0xed1: je     eea <vfs_writev_magic_return+0xeea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eea;
	}
x86_l_ed3:
	/* 0xed3: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ed6:
	/* 0xed6: movsx  rcx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_eda:
	/* 0xeda: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_edd:
	/* 0xedd: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_ee4:
	/* 0xee4: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ee7:
	/* 0xee7: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_eea:
	/* 0xeea: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_eef:
	/* 0xeef: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_ef6:
	/* 0xef6: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_ef9:
	/* 0xef9: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efe:
	/* 0xefe: mov    WORD PTR [rsp+0xa8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f06:
	/* 0xf06: je     106a <vfs_writev_magic_return+0x106a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4202ULL;
	}
x86_l_f0c:
	/* 0xf0c: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_f13:
	/* 0xf13: mov    QWORD PTR [rsp+0x138],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_f1b:
	/* 0xf1b: mov    r13,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_f22:
	/* 0xf22: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_f29:
	/* 0xf29: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_f31:
	/* 0xf31: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f39:
	/* 0xf39: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_f40:
	/* 0xf40: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f48:
	/* 0xf48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4d:
	/* 0xf4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4f:
	/* 0xf4f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f52:
	/* 0xf52: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f56:
	/* 0xf56: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f5e:
	/* 0xf5e: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f65:
	/* 0xf65: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f68:
	/* 0xf68: je     f8d <vfs_writev_magic_return+0xf8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8d;
	}
x86_l_f6a:
	/* 0xf6a: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f72:
	/* 0xf72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f77:
	/* 0xf77: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f7a:
	/* 0xf7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7c:
	/* 0xf7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7f:
	/* 0xf7f: je     f8d <vfs_writev_magic_return+0xf8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8d;
	}
x86_l_f81:
	/* 0xf81: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f84:
	/* 0xf84: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f88:
	/* 0xf88: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f8b:
	/* 0xf8b: jmp    f8f <vfs_writev_magic_return+0xf8f> */
	goto x86_l_f8f;
x86_l_f8d:
	/* 0xf8d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8f:
	/* 0xf8f: mov    rdx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_f97:
	/* 0xf97: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f9f:
	/* 0xf9f: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_fa2:
	/* 0xfa2: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_fa5:
	/* 0xfa5: jb     fbd <vfs_writev_magic_return+0xfbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_fbd;
	}
x86_l_fa7:
	/* 0xfa7: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fab:
	/* 0xfab: je     fb2 <vfs_writev_magic_return+0xfb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb2;
	}
x86_l_fad:
	/* 0xfad: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: jbe    fbd <vfs_writev_magic_return+0xfbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fbd;
	}
x86_l_fb2:
	/* 0xfb2: and    r14,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 312ULL);
x86_l_fba:
	/* 0xfba: or     rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_fbd:
	/* 0xfbd: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fc2:
	/* 0xfc2: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fc5:
	/* 0xfc5: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fcd:
	/* 0xfcd: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fd4:
	/* 0xfd4: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_fd7:
	/* 0xfd7: je     1018 <vfs_writev_magic_return+0x1018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4120ULL;
	}
x86_l_fd9:
	/* 0xfd9: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fe1:
	/* 0xfe1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fe6:
	/* 0xfe6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fe9:
	/* 0xfe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_feb:
	/* 0xfeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fee:
	/* 0xfee: je     102c <vfs_writev_magic_return+0x102c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4140ULL;
	}
x86_l_ff0:
	/* 0xff0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff3:
	/* 0xff3: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff7:
	/* 0xff7: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ffa:
	/* 0xffa: jmp    102e <vfs_writev_magic_return+0x102e> */
	return 4142ULL;
x86_l_ffc:
	/* 0xffc: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1003:
	/* 0x1003: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_100a:
	/* 0x100a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100d:
	/* 0x100d: jne    e72 <vfs_writev_magic_return+0xe72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e72;
	}
x86_l_1013:
	/* 0x1013: jmp    e99 <vfs_writev_magic_return+0xe99> */
	goto x86_l_e99;
	return 4120ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4120ULL: goto x86_l_1018;
	case 4122ULL: goto x86_l_101a;
	case 4125ULL: goto x86_l_101d;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4138ULL: goto x86_l_102a;
	case 4140ULL: goto x86_l_102c;
	case 4142ULL: goto x86_l_102e;
	case 4150ULL: goto x86_l_1036;
	case 4153ULL: goto x86_l_1039;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4210ULL: goto x86_l_1072;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4223ULL: goto x86_l_107f;
	case 4227ULL: goto x86_l_1083;
	case 4234ULL: goto x86_l_108a;
	case 4241ULL: goto x86_l_1091;
	case 4249ULL: goto x86_l_1099;
	case 4256ULL: goto x86_l_10a0;
	case 4263ULL: goto x86_l_10a7;
	case 4271ULL: goto x86_l_10af;
	case 4279ULL: goto x86_l_10b7;
	case 4286ULL: goto x86_l_10be;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4301ULL: goto x86_l_10cd;
	case 4304ULL: goto x86_l_10d0;
	case 4308ULL: goto x86_l_10d4;
	case 4316ULL: goto x86_l_10dc;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4336ULL: goto x86_l_10f0;
	case 4341ULL: goto x86_l_10f5;
	case 4343ULL: goto x86_l_10f7;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4373ULL: goto x86_l_1115;
	case 4376ULL: goto x86_l_1118;
	case 4379ULL: goto x86_l_111b;
	case 4381ULL: goto x86_l_111d;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4401ULL: goto x86_l_1131;
	case 4409ULL: goto x86_l_1139;
	case 4411ULL: goto x86_l_113b;
	case 4416ULL: goto x86_l_1140;
	case 4420ULL: goto x86_l_1144;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4444ULL: goto x86_l_115c;
	case 4447ULL: goto x86_l_115f;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4461ULL: goto x86_l_116d;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4479ULL: goto x86_l_117f;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4504ULL: goto x86_l_1198;
	case 4512ULL: goto x86_l_11a0;
	case 4516ULL: goto x86_l_11a4;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4541ULL: goto x86_l_11bd;
	case 4549ULL: goto x86_l_11c5;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4594ULL: goto x86_l_11f2;
	case 4601ULL: goto x86_l_11f9;
	case 4610ULL: goto x86_l_1202;
	case 4617ULL: goto x86_l_1209;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4648ULL: goto x86_l_1228;
	case 4651ULL: goto x86_l_122b;
	case 4653ULL: goto x86_l_122d;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4664ULL: goto x86_l_1238;
	case 4667ULL: goto x86_l_123b;
	case 4669ULL: goto x86_l_123d;
	case 4672ULL: goto x86_l_1240;
	case 4676ULL: goto x86_l_1244;
	case 4679ULL: goto x86_l_1247;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4686ULL: goto x86_l_124e;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4708ULL: goto x86_l_1264;
	case 4714ULL: goto x86_l_126a;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4750ULL: goto x86_l_128e;
	case 4758ULL: goto x86_l_1296;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4801ULL: goto x86_l_12c1;
	case 4805ULL: goto x86_l_12c5;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4838ULL: goto x86_l_12e6;
	case 4842ULL: goto x86_l_12ea;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4874ULL: goto x86_l_130a;
	case 4878ULL: goto x86_l_130e;
	case 4885ULL: goto x86_l_1315;
	case 4892ULL: goto x86_l_131c;
	case 4901ULL: goto x86_l_1325;
	case 4908ULL: goto x86_l_132c;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4926ULL: goto x86_l_133e;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4939ULL: goto x86_l_134b;
	case 4942ULL: goto x86_l_134e;
	case 4944ULL: goto x86_l_1350;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4972ULL: goto x86_l_136c;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5017ULL: goto x86_l_1399;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5050ULL: goto x86_l_13ba;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5083ULL: goto x86_l_13db;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5104ULL: goto x86_l_13f0;
	case 5109ULL: goto x86_l_13f5;
	case 5111ULL: goto x86_l_13f7;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5138ULL: goto x86_l_1412;
	case 5145ULL: goto x86_l_1419;
	case 5152ULL: goto x86_l_1420;
	case 5161ULL: goto x86_l_1429;
	case 5168ULL: goto x86_l_1430;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5292ULL: goto x86_l_14ac;
	case 5299ULL: goto x86_l_14b3;
	case 5308ULL: goto x86_l_14bc;
	case 5315ULL: goto x86_l_14c3;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5356ULL: goto x86_l_14ec;
	case 5358ULL: goto x86_l_14ee;
	case 5361ULL: goto x86_l_14f1;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5459ULL: goto x86_l_1553;
	case 5462ULL: goto x86_l_1556;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5475ULL: goto x86_l_1563;
	case 5480ULL: goto x86_l_1568;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5494ULL: goto x86_l_1576;
	case 5497ULL: goto x86_l_1579;
	case 5499ULL: goto x86_l_157b;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5530ULL: goto x86_l_159a;
	case 5537ULL: goto x86_l_15a1;
	case 5546ULL: goto x86_l_15aa;
	case 5553ULL: goto x86_l_15b1;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5600ULL: goto x86_l_15e0;
	case 5603ULL: goto x86_l_15e3;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5612ULL: goto x86_l_15ec;
	case 5615ULL: goto x86_l_15ef;
	case 5617ULL: goto x86_l_15f1;
	case 5619ULL: goto x86_l_15f3;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5643ULL: goto x86_l_160b;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5659ULL: goto x86_l_161b;
	case 5668ULL: goto x86_l_1624;
	case 5675ULL: goto x86_l_162b;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5693ULL: goto x86_l_163d;
	case 5700ULL: goto x86_l_1644;
	case 5703ULL: goto x86_l_1647;
	case 5705ULL: goto x86_l_1649;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5749ULL: goto x86_l_1675;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5756ULL: goto x86_l_167c;
	case 5759ULL: goto x86_l_167f;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5782ULL: goto x86_l_1696;
	case 5789ULL: goto x86_l_169d;
	case 5792ULL: goto x86_l_16a0;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1018:
	/* 0x1018: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_101a:
	/* 0x101a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_101d:
	/* 0x101d: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1025:
	/* 0x1025: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: jae    1046 <vfs_writev_magic_return+0x1046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1046;
	}
x86_l_102a:
	/* 0x102a: jmp    105c <vfs_writev_magic_return+0x105c> */
	goto x86_l_105c;
x86_l_102c:
	/* 0x102c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_102e:
	/* 0x102e: mov    rdx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1036:
	/* 0x1036: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1039:
	/* 0x1039: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1041:
	/* 0x1041: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: jb     105c <vfs_writev_magic_return+0x105c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_105c;
	}
x86_l_1046:
	/* 0x1046: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_104a:
	/* 0x104a: je     1051 <vfs_writev_magic_return+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1051;
	}
x86_l_104c:
	/* 0x104c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_104f:
	/* 0x104f: jbe    105c <vfs_writev_magic_return+0x105c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_105c;
	}
x86_l_1051:
	/* 0x1051: and    r14,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 312ULL);
x86_l_1059:
	/* 0x1059: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_105c:
	/* 0x105c: or     rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_105f:
	/* 0x105f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1062:
	/* 0x1062: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1065:
	/* 0x1065: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_106a:
	/* 0x106a: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1072:
	/* 0x1072: je     1128 <vfs_writev_magic_return+0x1128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1128;
	}
x86_l_1078:
	/* 0x1078: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_107d:
	/* 0x107d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107f:
	/* 0x107f: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1083:
	/* 0x1083: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_108a:
	/* 0x108a: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1091:
	/* 0x1091: mov    QWORD PTR [rsp+0x118],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1099:
	/* 0x1099: mov    r13,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_10a0:
	/* 0x10a0: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_10a7:
	/* 0x10a7: movzx  eax,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_10af:
	/* 0x10af: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10b7:
	/* 0x10b7: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_10be:
	/* 0x10be: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10c6:
	/* 0x10c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10cb:
	/* 0x10cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cd:
	/* 0x10cd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10d0:
	/* 0x10d0: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d4:
	/* 0x10d4: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10dc:
	/* 0x10dc: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10e3:
	/* 0x10e3: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_10e6:
	/* 0x10e6: je     1108 <vfs_writev_magic_return+0x1108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1108;
	}
x86_l_10e8:
	/* 0x10e8: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10f0:
	/* 0x10f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f5:
	/* 0x10f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f7:
	/* 0x10f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: je     1108 <vfs_writev_magic_return+0x1108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1108;
	}
x86_l_10fc:
	/* 0x10fc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ff:
	/* 0x10ff: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1103:
	/* 0x1103: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1106:
	/* 0x1106: jmp    110a <vfs_writev_magic_return+0x110a> */
	goto x86_l_110a;
x86_l_1108:
	/* 0x1108: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110a:
	/* 0x110a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_110d:
	/* 0x110d: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1115:
	/* 0x1115: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1118:
	/* 0x1118: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_111b:
	/* 0x111b: jae    1140 <vfs_writev_magic_return+0x1140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1140;
	}
x86_l_111d:
	/* 0x111d: movzx  r13d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1126:
	/* 0x1126: jmp    115f <vfs_writev_magic_return+0x115f> */
	goto x86_l_115f;
x86_l_1128:
	/* 0x1128: movzx  r13d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1131:
	/* 0x1131: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1139:
	/* 0x1139: jne    1173 <vfs_writev_magic_return+0x1173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1173;
	}
x86_l_113b:
	/* 0x113b: jmp    125c <vfs_writev_magic_return+0x125c> */
	goto x86_l_125c;
x86_l_1140:
	/* 0x1140: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1144:
	/* 0x1144: movzx  r13d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_114d:
	/* 0x114d: je     1154 <vfs_writev_magic_return+0x1154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1154;
	}
x86_l_114f:
	/* 0x114f: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1152:
	/* 0x1152: jbe    115f <vfs_writev_magic_return+0x115f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_115f;
	}
x86_l_1154:
	/* 0x1154: and    r15,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 280ULL);
x86_l_115c:
	/* 0x115c: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_115f:
	/* 0x115f: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1162:
	/* 0x1162: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1165:
	/* 0x1165: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_116d:
	/* 0x116d: je     125c <vfs_writev_magic_return+0x125c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125c;
	}
x86_l_1173:
	/* 0x1173: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1178:
	/* 0x1178: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_117f:
	/* 0x117f: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1187:
	/* 0x1187: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_118c:
	/* 0x118c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1191:
	/* 0x1191: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1196:
	/* 0x1196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1198:
	/* 0x1198: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11a0:
	/* 0x11a0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11a4:
	/* 0x11a4: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x11bd: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11c5:
	/* 0x11c5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11ca:
	/* 0x11ca: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_11cf:
	/* 0x11cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11d4:
	/* 0x11d4: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11dc:
	/* 0x11dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11e1:
	/* 0x11e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e3:
	/* 0x11e3: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11e7:
	/* 0x11e7: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11eb:
	/* 0x11eb: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_11f2:
	/* 0x11f2: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_11f9:
	/* 0x11f9: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1202:
	/* 0x1202: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_1209:
	/* 0x1209: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1211:
	/* 0x1211: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1216:
	/* 0x1216: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1219:
	/* 0x1219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121b:
	/* 0x121b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1221:
	/* 0x1221: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1228:
	/* 0x1228: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_122b:
	/* 0x122b: je     1249 <vfs_writev_magic_return+0x1249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1249;
	}
x86_l_122d:
	/* 0x122d: lea    rsi,[rax+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1231:
	/* 0x1231: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1236:
	/* 0x1236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1238:
	/* 0x1238: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123b:
	/* 0x123b: je     1249 <vfs_writev_magic_return+0x1249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1249;
	}
x86_l_123d:
	/* 0x123d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1240:
	/* 0x1240: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1244:
	/* 0x1244: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1247:
	/* 0x1247: jmp    124b <vfs_writev_magic_return+0x124b> */
	goto x86_l_124b;
x86_l_1249:
	/* 0x1249: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124b:
	/* 0x124b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_124e:
	/* 0x124e: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1251:
	/* 0x1251: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1254:
	/* 0x1254: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1257:
	/* 0x1257: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_125c:
	/* 0x125c: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1264:
	/* 0x1264: je     137f <vfs_writev_magic_return+0x137f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_137f;
	}
x86_l_126a:
	/* 0x126a: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1271:
	/* 0x1271: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1275:
	/* 0x1275: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x128e: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1296:
	/* 0x1296: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_129e:
	/* 0x129e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12a3:
	/* 0x12a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12a8:
	/* 0x12a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12ad:
	/* 0x12ad: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b2:
	/* 0x12b2: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12b9:
	/* 0x12b9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_12bd:
	/* 0x12bd: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_12c1:
	/* 0x12c1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12c5:
	/* 0x12c5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12cd:
	/* 0x12cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d2:
	/* 0x12d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12d7:
	/* 0x12d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12dc:
	/* 0x12dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12de:
	/* 0x12de: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12e6:
	/* 0x12e6: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_12ea:
	/* 0x12ea: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12f2:
	/* 0x12f2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12f7:
	/* 0x12f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12fc:
	/* 0x12fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1301:
	/* 0x1301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1303:
	/* 0x1303: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_130a:
	/* 0x130a: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_130e:
	/* 0x130e: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1315:
	/* 0x1315: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_131c:
	/* 0x131c: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1325:
	/* 0x1325: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_132c:
	/* 0x132c: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1334:
	/* 0x1334: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1339:
	/* 0x1339: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_133c:
	/* 0x133c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133e:
	/* 0x133e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1341:
	/* 0x1341: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_134b:
	/* 0x134b: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_134e:
	/* 0x134e: je     136c <vfs_writev_magic_return+0x136c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_136c;
	}
x86_l_1350:
	/* 0x1350: lea    rsi,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1354:
	/* 0x1354: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1359:
	/* 0x1359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135b:
	/* 0x135b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_135e:
	/* 0x135e: je     136c <vfs_writev_magic_return+0x136c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_136c;
	}
x86_l_1360:
	/* 0x1360: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1363:
	/* 0x1363: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1367:
	/* 0x1367: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_136a:
	/* 0x136a: jmp    136e <vfs_writev_magic_return+0x136e> */
	goto x86_l_136e;
x86_l_136c:
	/* 0x136c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_136e:
	/* 0x136e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1371:
	/* 0x1371: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1374:
	/* 0x1374: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1377:
	/* 0x1377: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_137a:
	/* 0x137a: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_137f:
	/* 0x137f: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1387:
	/* 0x1387: je     147f <vfs_writev_magic_return+0x147f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147f;
	}
x86_l_138d:
	/* 0x138d: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1392:
	/* 0x1392: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1399:
	/* 0x1399: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13a1:
	/* 0x13a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13a6:
	/* 0x13a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13ab:
	/* 0x13ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b0:
	/* 0x13b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b2:
	/* 0x13b2: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13ba:
	/* 0x13ba: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13c2:
	/* 0x13c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13c7:
	/* 0x13c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13cc:
	/* 0x13cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13d1:
	/* 0x13d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d3:
	/* 0x13d3: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13db:
	/* 0x13db: lea    r12,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13e3:
	/* 0x13e3: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_13e8:
	/* 0x13e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13ed:
	/* 0x13ed: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_13f0:
	/* 0x13f0: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_13f5:
	/* 0x13f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f7:
	/* 0x13f7: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_13fb:
	/* 0x13fb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1400:
	/* 0x1400: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1405:
	/* 0x1405: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1408:
	/* 0x1408: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_140d:
	/* 0x140d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1412:
	/* 0x1412: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1419:
	/* 0x1419: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1420:
	/* 0x1420: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1429:
	/* 0x1429: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1430:
	/* 0x1430: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1438:
	/* 0x1438: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143d:
	/* 0x143d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1449:
	/* 0x1449: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_144c:
	/* 0x144c: je     146c <vfs_writev_magic_return+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146c;
	}
x86_l_144e:
	/* 0x144e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1451:
	/* 0x1451: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1456:
	/* 0x1456: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145e:
	/* 0x145e: je     146c <vfs_writev_magic_return+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146c;
	}
x86_l_1460:
	/* 0x1460: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1463:
	/* 0x1463: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1467:
	/* 0x1467: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_146a:
	/* 0x146a: jmp    146e <vfs_writev_magic_return+0x146e> */
	goto x86_l_146e;
x86_l_146c:
	/* 0x146c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_146e:
	/* 0x146e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1471:
	/* 0x1471: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1474:
	/* 0x1474: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1477:
	/* 0x1477: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_147a:
	/* 0x147a: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_147f:
	/* 0x147f: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1487:
	/* 0x1487: je     1512 <vfs_writev_magic_return+0x1512> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1512;
	}
x86_l_148d:
	/* 0x148d: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1491:
	/* 0x1491: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1496:
	/* 0x1496: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_149b:
	/* 0x149b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_149e:
	/* 0x149e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_14a3:
	/* 0x14a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a5:
	/* 0x14a5: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_14ac:
	/* 0x14ac: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_14b3:
	/* 0x14b3: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14bc:
	/* 0x14bc: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_14c3:
	/* 0x14c3: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14cb:
	/* 0x14cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d0:
	/* 0x14d0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14d3:
	/* 0x14d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d5:
	/* 0x14d5: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14dc:
	/* 0x14dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14df:
	/* 0x14df: je     14ff <vfs_writev_magic_return+0x14ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ff;
	}
x86_l_14e1:
	/* 0x14e1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14e4:
	/* 0x14e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14e9:
	/* 0x14e9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_14ec:
	/* 0x14ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ee:
	/* 0x14ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f1:
	/* 0x14f1: je     14ff <vfs_writev_magic_return+0x14ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ff;
	}
x86_l_14f3:
	/* 0x14f3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f6:
	/* 0x14f6: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fa:
	/* 0x14fa: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14fd:
	/* 0x14fd: jmp    1501 <vfs_writev_magic_return+0x1501> */
	goto x86_l_1501;
x86_l_14ff:
	/* 0x14ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1501:
	/* 0x1501: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1504:
	/* 0x1504: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1507:
	/* 0x1507: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_150a:
	/* 0x150a: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_150d:
	/* 0x150d: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1512:
	/* 0x1512: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1519:
	/* 0x1519: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_151c:
	/* 0x151c: je     158e <vfs_writev_magic_return+0x158e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158e;
	}
x86_l_151e:
	/* 0x151e: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1522:
	/* 0x1522: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1529:
	/* 0x1529: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1530:
	/* 0x1530: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1536:
	/* 0x1536: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_153d:
	/* 0x153d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1542:
	/* 0x1542: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1547:
	/* 0x1547: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_154a:
	/* 0x154a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154c:
	/* 0x154c: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1553:
	/* 0x1553: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1556:
	/* 0x1556: je     157b <vfs_writev_magic_return+0x157b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157b;
	}
x86_l_1558:
	/* 0x1558: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_155b:
	/* 0x155b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1563:
	/* 0x1563: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1568:
	/* 0x1568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156a:
	/* 0x156a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_156d:
	/* 0x156d: je     157b <vfs_writev_magic_return+0x157b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157b;
	}
x86_l_156f:
	/* 0x156f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1572:
	/* 0x1572: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1576:
	/* 0x1576: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1579:
	/* 0x1579: jmp    157d <vfs_writev_magic_return+0x157d> */
	goto x86_l_157d;
x86_l_157b:
	/* 0x157b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157d:
	/* 0x157d: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1580:
	/* 0x1580: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1583:
	/* 0x1583: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1586:
	/* 0x1586: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1589:
	/* 0x1589: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_158e:
	/* 0x158e: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1595:
	/* 0x1595: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1598:
	/* 0x1598: je     1604 <vfs_writev_magic_return+0x1604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1604;
	}
x86_l_159a:
	/* 0x159a: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_15a1:
	/* 0x15a1: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15aa:
	/* 0x15aa: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_15b1:
	/* 0x15b1: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15b9:
	/* 0x15b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15be:
	/* 0x15be: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15c1:
	/* 0x15c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c3:
	/* 0x15c3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15c6:
	/* 0x15c6: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_15c9:
	/* 0x15c9: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15d0:
	/* 0x15d0: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_15d3:
	/* 0x15d3: je     15f1 <vfs_writev_magic_return+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f1;
	}
x86_l_15d5:
	/* 0x15d5: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15d9:
	/* 0x15d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15de:
	/* 0x15de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e0:
	/* 0x15e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e3:
	/* 0x15e3: je     15f1 <vfs_writev_magic_return+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f1;
	}
x86_l_15e5:
	/* 0x15e5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e8:
	/* 0x15e8: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ec:
	/* 0x15ec: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15ef:
	/* 0x15ef: jmp    15f3 <vfs_writev_magic_return+0x15f3> */
	goto x86_l_15f3;
x86_l_15f1:
	/* 0x15f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f3:
	/* 0x15f3: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15f6:
	/* 0x15f6: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_15f9:
	/* 0x15f9: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15fc:
	/* 0x15fc: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_15ff:
	/* 0x15ff: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1604:
	/* 0x1604: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_160b:
	/* 0x160b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_160e:
	/* 0x160e: je     1696 <vfs_writev_magic_return+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1614:
	/* 0x1614: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_161b:
	/* 0x161b: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1624:
	/* 0x1624: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_162b:
	/* 0x162b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1633:
	/* 0x1633: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1638:
	/* 0x1638: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_163b:
	/* 0x163b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163d:
	/* 0x163d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1644:
	/* 0x1644: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1647:
	/* 0x1647: je     1688 <vfs_writev_magic_return+0x1688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1688;
	}
x86_l_1649:
	/* 0x1649: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_164c:
	/* 0x164c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1651:
	/* 0x1651: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1655:
	/* 0x1655: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165a:
	/* 0x165a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_165d:
	/* 0x165d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165f:
	/* 0x165f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1662:
	/* 0x1662: jne    167c <vfs_writev_magic_return+0x167c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_167c;
	}
x86_l_1664:
	/* 0x1664: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1669:
	/* 0x1669: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_166d:
	/* 0x166d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1672:
	/* 0x1672: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1675:
	/* 0x1675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1677:
	/* 0x1677: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_167a:
	/* 0x167a: je     1688 <vfs_writev_magic_return+0x1688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1688;
	}
x86_l_167c:
	/* 0x167c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167f:
	/* 0x167f: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1683:
	/* 0x1683: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1686:
	/* 0x1686: jmp    168a <vfs_writev_magic_return+0x168a> */
	goto x86_l_168a;
x86_l_1688:
	/* 0x1688: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168a:
	/* 0x168a: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_168d:
	/* 0x168d: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1690:
	/* 0x1690: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1693:
	/* 0x1693: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1696:
	/* 0x1696: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_169d:
	/* 0x169d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a0:
	/* 0x16a0: mov    r12,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_16a8:
	/* 0x16a8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ad:
	/* 0x16ad: je     16b6 <vfs_writev_magic_return+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5814ULL;
	}
x86_l_16af:
	/* 0x16af: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
	return 5811ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5811ULL: goto x86_l_16b3;
	case 5814ULL: goto x86_l_16b6;
	case 5816ULL: goto x86_l_16b8;
	case 5823ULL: goto x86_l_16bf;
	case 5830ULL: goto x86_l_16c6;
	case 5833ULL: goto x86_l_16c9;
	case 5840ULL: goto x86_l_16d0;
	case 5846ULL: goto x86_l_16d6;
	case 5854ULL: goto x86_l_16de;
	case 5857ULL: goto x86_l_16e1;
	case 5864ULL: goto x86_l_16e8;
	case 5866ULL: goto x86_l_16ea;
	case 5872ULL: goto x86_l_16f0;
	case 5884ULL: goto x86_l_16fc;
	case 5896ULL: goto x86_l_1708;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5949ULL: goto x86_l_173d;
	case 5951ULL: goto x86_l_173f;
	case 5956ULL: goto x86_l_1744;
	case 5965ULL: goto x86_l_174d;
	case 5974ULL: goto x86_l_1756;
	case 5978ULL: goto x86_l_175a;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6003ULL: goto x86_l_1773;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6020ULL: goto x86_l_1784;
	case 6028ULL: goto x86_l_178c;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6046ULL: goto x86_l_179e;
	case 6048ULL: goto x86_l_17a0;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6140ULL: goto x86_l_17fc;
	case 6148ULL: goto x86_l_1804;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6194ULL: goto x86_l_1832;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6228ULL: goto x86_l_1854;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6270ULL: goto x86_l_187e;
	case 6277ULL: goto x86_l_1885;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6303ULL: goto x86_l_189f;
	case 6305ULL: goto x86_l_18a1;
	case 6313ULL: goto x86_l_18a9;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6340ULL: goto x86_l_18c4;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6376ULL: goto x86_l_18e8;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6391ULL: goto x86_l_18f7;
	case 6394ULL: goto x86_l_18fa;
	case 6397ULL: goto x86_l_18fd;
	case 6403ULL: goto x86_l_1903;
	case 6411ULL: goto x86_l_190b;
	case 6418ULL: goto x86_l_1912;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6430ULL: goto x86_l_191e;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6442ULL: goto x86_l_192a;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6617ULL: goto x86_l_19d9;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6635ULL: goto x86_l_19eb;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6661ULL: goto x86_l_1a05;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6718ULL: goto x86_l_1a3e;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6729ULL: goto x86_l_1a49;
	case 6735ULL: goto x86_l_1a4f;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6745ULL: goto x86_l_1a59;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6755ULL: goto x86_l_1a63;
	case 6758ULL: goto x86_l_1a66;
	case 6764ULL: goto x86_l_1a6c;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6779ULL: goto x86_l_1a7b;
	case 6784ULL: goto x86_l_1a80;
	case 6792ULL: goto x86_l_1a88;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6852ULL: goto x86_l_1ac4;
	case 6856ULL: goto x86_l_1ac8;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7011ULL: goto x86_l_1b63;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7035ULL: goto x86_l_1b7b;
	case 7037ULL: goto x86_l_1b7d;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7062ULL: goto x86_l_1b96;
	case 7068ULL: goto x86_l_1b9c;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7094ULL: goto x86_l_1bb6;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7137ULL: goto x86_l_1be1;
	case 7140ULL: goto x86_l_1be4;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7162ULL: goto x86_l_1bfa;
	case 7168ULL: goto x86_l_1c00;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7222ULL: goto x86_l_1c36;
	case 7228ULL: goto x86_l_1c3c;
	case 7236ULL: goto x86_l_1c44;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7255ULL: goto x86_l_1c57;
	case 7260ULL: goto x86_l_1c5c;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7295ULL: goto x86_l_1c7f;
	case 7298ULL: goto x86_l_1c82;
	case 7305ULL: goto x86_l_1c89;
	case 7307ULL: goto x86_l_1c8b;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7323ULL: goto x86_l_1c9b;
	case 7325ULL: goto x86_l_1c9d;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7353ULL: goto x86_l_1cb9;
	case 7357ULL: goto x86_l_1cbd;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7391ULL: goto x86_l_1cdf;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7421ULL: goto x86_l_1cfd;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7502ULL: goto x86_l_1d4e;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7536ULL: goto x86_l_1d70;
	case 7539ULL: goto x86_l_1d73;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7606ULL: goto x86_l_1db6;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7619ULL: goto x86_l_1dc3;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7632ULL: goto x86_l_1dd0;
	case 7640ULL: goto x86_l_1dd8;
	case 7646ULL: goto x86_l_1dde;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16b3:
	/* 0x16b3: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16b6:
	/* 0x16b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b8:
	/* 0x16b8: and    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_16bf:
	/* 0x16bf: mov    rdx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16c6:
	/* 0x16c6: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_16c9:
	/* 0x16c9: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16d0:
	/* 0x16d0: je     2dba <vfs_writev_magic_return+0x2dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11706ULL;
	}
x86_l_16d6:
	/* 0x16d6: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_16de:
	/* 0x16de: mov    eax,DWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16e1:
	/* 0x16e1: mov    DWORD PTR [rsp+0x10c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_16e8:
	/* 0x16e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ea:
	/* 0x16ea: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_16f0:
	/* 0x16f0: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_16fc:
	/* 0x16fc: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_1708:
	/* 0x1708: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1714:
	/* 0x1714: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1719:
	/* 0x1719: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_171c:
	/* 0x171c: je     18e1 <vfs_writev_magic_return+0x18e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18e1;
	}
x86_l_1722:
	/* 0x1722: lea    rbx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1726:
	/* 0x1726: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_172b:
	/* 0x172b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1730:
	/* 0x1730: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1735:
	/* 0x1735: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173a:
	/* 0x173a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_173d:
	/* 0x173d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173f:
	/* 0x173f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1744:
	/* 0x1744: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_174d:
	/* 0x174d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1756:
	/* 0x1756: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_175a:
	/* 0x175a: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1762:
	/* 0x1762: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1767:
	/* 0x1767: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_176c:
	/* 0x176c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1771:
	/* 0x1771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1773:
	/* 0x1773: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_177b:
	/* 0x177b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1780:
	/* 0x1780: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1784:
	/* 0x1784: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_178c:
	/* 0x178c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1791:
	/* 0x1791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1796:
	/* 0x1796: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179b:
	/* 0x179b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_179e:
	/* 0x179e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a0:
	/* 0x17a0: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17a7:
	/* 0x17a7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17ac:
	/* 0x17ac: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17b4:
	/* 0x17b4: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17b9:
	/* 0x17b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17be:
	/* 0x17be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17c3:
	/* 0x17c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c8:
	/* 0x17c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ca:
	/* 0x17ca: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17d2:
	/* 0x17d2: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_17d5:
	/* 0x17d5: js     1806 <vfs_writev_magic_return+0x1806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1806;
	}
x86_l_17d7:
	/* 0x17d7: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17dc:
	/* 0x17dc: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17e4:
	/* 0x17e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17e9:
	/* 0x17e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17ee:
	/* 0x17ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f3:
	/* 0x17f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f5:
	/* 0x17f5: imul   rax,r14,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_R14, X86_WIDTH_64, 1000000000ULL);
x86_l_17fc:
	/* 0x17fc: add    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1804:
	/* 0x1804: jmp    1808 <vfs_writev_magic_return+0x1808> */
	goto x86_l_1808;
x86_l_1806:
	/* 0x1806: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1808:
	/* 0x1808: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1810:
	/* 0x1810: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1815:
	/* 0x1815: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_181a:
	/* 0x181a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_181f:
	/* 0x181f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1824:
	/* 0x1824: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1827:
	/* 0x1827: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1829:
	/* 0x1829: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_182e:
	/* 0x182e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1832:
	/* 0x1832: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_183a:
	/* 0x183a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_183f:
	/* 0x183f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1844:
	/* 0x1844: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1849:
	/* 0x1849: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_184d:
	/* 0x184d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1852:
	/* 0x1852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1854:
	/* 0x1854: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_185c:
	/* 0x185c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1861:
	/* 0x1861: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1866:
	/* 0x1866: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_186b:
	/* 0x186b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1873:
	/* 0x1873: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1878:
	/* 0x1878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187a:
	/* 0x187a: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_187e:
	/* 0x187e: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1885:
	/* 0x1885: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_188d:
	/* 0x188d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1892:
	/* 0x1892: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1897:
	/* 0x1897: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189c:
	/* 0x189c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_189f:
	/* 0x189f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a1:
	/* 0x18a1: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18a9:
	/* 0x18a9: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18ad:
	/* 0x18ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18b2:
	/* 0x18b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b7:
	/* 0x18b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18bc:
	/* 0x18bc: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18c4:
	/* 0x18c4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18c8:
	/* 0x18c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18cd:
	/* 0x18cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cf:
	/* 0x18cf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18d4:
	/* 0x18d4: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_18dc:
	/* 0x18dc: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18e1:
	/* 0x18e1: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_18e8:
	/* 0x18e8: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18f0:
	/* 0x18f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f5:
	/* 0x18f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f7:
	/* 0x18f7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_18fa:
	/* 0x18fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18fd:
	/* 0x18fd: jne    1de7 <vfs_writev_magic_return+0x1de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7655ULL;
	}
x86_l_1903:
	/* 0x1903: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_190b:
	/* 0x190b: mov    rdi,QWORD PTR [rip+0x37b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_1912:
	/* 0x1912: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1917:
	/* 0x1917: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_191c:
	/* 0x191c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191e:
	/* 0x191e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1921:
	/* 0x1921: je     1de4 <vfs_writev_magic_return+0x1de4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7652ULL;
	}
x86_l_1927:
	/* 0x1927: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_192a:
	/* 0x192a: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192e:
	/* 0x192e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1933:
	/* 0x1933: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1938:
	/* 0x1938: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_193d:
	/* 0x193d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1942:
	/* 0x1942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1944:
	/* 0x1944: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1949:
	/* 0x1949: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1951:
	/* 0x1951: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1956:
	/* 0x1956: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_195b:
	/* 0x195b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1960:
	/* 0x1960: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1968:
	/* 0x1968: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_196d:
	/* 0x196d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196f:
	/* 0x196f: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_1974:
	/* 0x1974: jne    1a95 <vfs_writev_magic_return+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a95;
	}
x86_l_197a:
	/* 0x197a: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197e:
	/* 0x197e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1983:
	/* 0x1983: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1988:
	/* 0x1988: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_198d:
	/* 0x198d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1992:
	/* 0x1992: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1994:
	/* 0x1994: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1999:
	/* 0x1999: lea    rcx,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_199d:
	/* 0x199d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a2:
	/* 0x19a2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a7:
	/* 0x19a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19ac:
	/* 0x19ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19b1:
	/* 0x19b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b6:
	/* 0x19b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19bb:
	/* 0x19bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bd:
	/* 0x19bd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19c2:
	/* 0x19c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19c7:
	/* 0x19c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19cc:
	/* 0x19cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19d1:
	/* 0x19d1: mov    QWORD PTR [rsp+0xa8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_19d9:
	/* 0x19d9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_19dc:
	/* 0x19dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19de:
	/* 0x19de: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19e3:
	/* 0x19e3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19eb:
	/* 0x19eb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_19ef:
	/* 0x19ef: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19f4:
	/* 0x19f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19f9:
	/* 0x19f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19fe:
	/* 0x19fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a03:
	/* 0x1a03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a05:
	/* 0x1a05: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a0d:
	/* 0x1a0d: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: je     1aab <vfs_writev_magic_return+0x1aab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aab;
	}
x86_l_1a16:
	/* 0x1a16: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a1b:
	/* 0x1a1b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a1e:
	/* 0x1a1e: je     1aab <vfs_writev_magic_return+0x1aab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aab;
	}
x86_l_1a24:
	/* 0x1a24: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a28:
	/* 0x1a28: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a37:
	/* 0x1a37: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a3c:
	/* 0x1a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3e:
	/* 0x1a3e: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1a42:
	/* 0x1a42: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a47:
	/* 0x1a47: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1a49:
	/* 0x1a49: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1a51:
	/* 0x1a51: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1a53:
	/* 0x1a53: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1a59:
	/* 0x1a59: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a5c:
	/* 0x1a5c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a61:
	/* 0x1a61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a63:
	/* 0x1a63: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a66:
	/* 0x1a66: jl     1c3c <vfs_writev_magic_return+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1c3c;
	}
x86_l_1a6c:
	/* 0x1a6c: mov    BYTE PTR [r13+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_1a74:
	/* 0x1a74: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_1a79:
	/* 0x1a79: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a7b:
	/* 0x1a7b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a80:
	/* 0x1a80: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a88:
	/* 0x1a88: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a90:
	/* 0x1a90: jmp    1b3d <vfs_writev_magic_return+0x1b3d> */
	goto x86_l_1b3d;
x86_l_1a95:
	/* 0x1a95: lea    rdx,[rip+0x37b0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 14256ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1aa6:
	/* 0x1aa6: jmp    1c6d <vfs_writev_magic_return+0x1c6d> */
	goto x86_l_1c6d;
x86_l_1aab:
	/* 0x1aab: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: jne    1c3c <vfs_writev_magic_return+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c3c;
	}
x86_l_1ab4:
	/* 0x1ab4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab9:
	/* 0x1ab9: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1abe:
	/* 0x1abe: je     1c3c <vfs_writev_magic_return+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c3c;
	}
x86_l_1ac4:
	/* 0x1ac4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ac8:
	/* 0x1ac8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ada:
	/* 0x1ada: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1adf:
	/* 0x1adf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae8:
	/* 0x1ae8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aea:
	/* 0x1aea: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aef:
	/* 0x1aef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af4:
	/* 0x1af4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1af9:
	/* 0x1af9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1afe:
	/* 0x1afe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b03:
	/* 0x1b03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b08:
	/* 0x1b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0a:
	/* 0x1b0a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0f:
	/* 0x1b0f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b14:
	/* 0x1b14: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b19:
	/* 0x1b19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b23:
	/* 0x1b23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b28:
	/* 0x1b28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2a:
	/* 0x1b2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2f:
	/* 0x1b2f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b33:
	/* 0x1b33: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1b38:
	/* 0x1b38: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3d:
	/* 0x1b3d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b42:
	/* 0x1b42: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b47:
	/* 0x1b47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b51:
	/* 0x1b51: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1b54:
	/* 0x1b54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b56:
	/* 0x1b56: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b63:
	/* 0x1b63: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b67:
	/* 0x1b67: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b71:
	/* 0x1b71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b76:
	/* 0x1b76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b7b:
	/* 0x1b7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7d:
	/* 0x1b7d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b85:
	/* 0x1b85: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: je     1c1d <vfs_writev_magic_return+0x1c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c1d;
	}
x86_l_1b8e:
	/* 0x1b8e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b93:
	/* 0x1b93: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b96:
	/* 0x1b96: je     1c1d <vfs_writev_magic_return+0x1c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c1d;
	}
x86_l_1b9c:
	/* 0x1b9c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ba0:
	/* 0x1ba0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1baa:
	/* 0x1baa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1baf:
	/* 0x1baf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1bb4:
	/* 0x1bb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb6:
	/* 0x1bb6: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1bba:
	/* 0x1bba: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1bbc:
	/* 0x1bbc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1bc9:
	/* 0x1bc9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1bcb:
	/* 0x1bcb: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bd0:
	/* 0x1bd0: jb     1dc1 <vfs_writev_magic_return+0x1dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dc1;
	}
x86_l_1bd6:
	/* 0x1bd6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bdb:
	/* 0x1bdb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1be1:
	/* 0x1be1: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1be4:
	/* 0x1be4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1be6:
	/* 0x1be6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1beb:
	/* 0x1beb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bed:
	/* 0x1bed: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bf0:
	/* 0x1bf0: jl     1c2b <vfs_writev_magic_return+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1c2b;
	}
x86_l_1bf2:
	/* 0x1bf2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bf7:
	/* 0x1bf7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1bfa:
	/* 0x1bfa: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1c00:
	/* 0x1c00: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1c06:
	/* 0x1c06: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c08:
	/* 0x1c08: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c15:
	/* 0x1c15: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1c18:
	/* 0x1c18: jmp    1d28 <vfs_writev_magic_return+0x1d28> */
	goto x86_l_1d28;
x86_l_1c1d:
	/* 0x1c1d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1c20:
	/* 0x1c20: je     1ca4 <vfs_writev_magic_return+0x1ca4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca4;
	}
x86_l_1c26:
	/* 0x1c26: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c30:
	/* 0x1c30: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_1c36:
	/* 0x1c36: jne    1dc1 <vfs_writev_magic_return+0x1dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dc1;
	}
x86_l_1c3c:
	/* 0x1c3c: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c44:
	/* 0x1c44: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c48:
	/* 0x1c48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c52:
	/* 0x1c52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c57:
	/* 0x1c57: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c5c:
	/* 0x1c5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5e:
	/* 0x1c5e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c63:
	/* 0x1c63: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1c68:
	/* 0x1c68: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1c70:
	/* 0x1c70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c75:
	/* 0x1c75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c77:
	/* 0x1c77: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c79:
	/* 0x1c79: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1c7f:
	/* 0x1c7f: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c82:
	/* 0x1c82: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1c89:
	/* 0x1c89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c8b:
	/* 0x1c8b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c93:
	/* 0x1c93: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c98:
	/* 0x1c98: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c9b:
	/* 0x1c9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c9d:
	/* 0x1c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9f:
	/* 0x1c9f: jmp    1de7 <vfs_writev_magic_return+0x1de7> */
	return 7655ULL;
x86_l_1ca4:
	/* 0x1ca4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca9:
	/* 0x1ca9: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1cae:
	/* 0x1cae: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb3:
	/* 0x1cb3: je     1c2b <vfs_writev_magic_return+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2b;
	}
x86_l_1cb9:
	/* 0x1cb9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cbd:
	/* 0x1cbd: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cca:
	/* 0x1cca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd4:
	/* 0x1cd4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cdd:
	/* 0x1cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cdf:
	/* 0x1cdf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce4:
	/* 0x1ce4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cee:
	/* 0x1cee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf8:
	/* 0x1cf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cfd:
	/* 0x1cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cff:
	/* 0x1cff: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d04:
	/* 0x1d04: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d09:
	/* 0x1d09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d13:
	/* 0x1d13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d18:
	/* 0x1d18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d1d:
	/* 0x1d1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1f:
	/* 0x1d1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d24:
	/* 0x1d24: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d28:
	/* 0x1d28: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d32:
	/* 0x1d32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d37:
	/* 0x1d37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1d3f:
	/* 0x1d3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d41:
	/* 0x1d41: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d46:
	/* 0x1d46: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d4e:
	/* 0x1d4e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d52:
	/* 0x1d52: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d57:
	/* 0x1d57: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d61:
	/* 0x1d61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d70:
	/* 0x1d70: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1d73:
	/* 0x1d73: je     2b05 <vfs_writev_magic_return+0x2b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11013ULL;
	}
x86_l_1d79:
	/* 0x1d79: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d7e:
	/* 0x1d7e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d81:
	/* 0x1d81: je     2b05 <vfs_writev_magic_return+0x2b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11013ULL;
	}
x86_l_1d87:
	/* 0x1d87: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d8b:
	/* 0x1d8b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d90:
	/* 0x1d90: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d95:
	/* 0x1d95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d9f:
	/* 0x1d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da1:
	/* 0x1da1: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1da5:
	/* 0x1da5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1da7:
	/* 0x1da7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dad:
	/* 0x1dad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1db2:
	/* 0x1db2: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1db4:
	/* 0x1db4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1db6:
	/* 0x1db6: jae    2c5a <vfs_writev_magic_return+0x2c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11354ULL;
	}
x86_l_1dbc:
	/* 0x1dbc: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc1:
	/* 0x1dc1: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1dc3:
	/* 0x1dc3: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1dc5:
	/* 0x1dc5: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1dca:
	/* 0x1dca: mov    BYTE PTR [r13+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    BYTE PTR [r13+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1dd8:
	/* 0x1dd8: cmp    edx,0x6fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28671ULL);
x86_l_1dde:
	/* 0x1dde: jbe    1c79 <vfs_writev_magic_return+0x1c79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c79;
	}
	return 7652ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7652ULL: goto x86_l_1de4;
	case 7655ULL: goto x86_l_1de7;
	case 7663ULL: goto x86_l_1def;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7701ULL: goto x86_l_1e15;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7728ULL: goto x86_l_1e30;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7773ULL: goto x86_l_1e5d;
	case 7777ULL: goto x86_l_1e61;
	case 7784ULL: goto x86_l_1e68;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7847ULL: goto x86_l_1ea7;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7871ULL: goto x86_l_1ebf;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7897ULL: goto x86_l_1ed9;
	case 7909ULL: goto x86_l_1ee5;
	case 7921ULL: goto x86_l_1ef1;
	case 7933ULL: goto x86_l_1efd;
	case 7945ULL: goto x86_l_1f09;
	case 7953ULL: goto x86_l_1f11;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7973ULL: goto x86_l_1f25;
	case 7982ULL: goto x86_l_1f2e;
	case 7990ULL: goto x86_l_1f36;
	case 7998ULL: goto x86_l_1f3e;
	case 8004ULL: goto x86_l_1f44;
	case 8006ULL: goto x86_l_1f46;
	case 8010ULL: goto x86_l_1f4a;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8053ULL: goto x86_l_1f75;
	case 8055ULL: goto x86_l_1f77;
	case 8057ULL: goto x86_l_1f79;
	case 8065ULL: goto x86_l_1f81;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8082ULL: goto x86_l_1f92;
	case 8090ULL: goto x86_l_1f9a;
	case 8093ULL: goto x86_l_1f9d;
	case 8101ULL: goto x86_l_1fa5;
	case 8108ULL: goto x86_l_1fac;
	case 8117ULL: goto x86_l_1fb5;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8141ULL: goto x86_l_1fcd;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8156ULL: goto x86_l_1fdc;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8206ULL: goto x86_l_200e;
	case 8210ULL: goto x86_l_2012;
	case 8218ULL: goto x86_l_201a;
	case 8225ULL: goto x86_l_2021;
	case 8231ULL: goto x86_l_2027;
	case 8240ULL: goto x86_l_2030;
	case 8244ULL: goto x86_l_2034;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8278ULL: goto x86_l_2056;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8306ULL: goto x86_l_2072;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8334ULL: goto x86_l_208e;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8355ULL: goto x86_l_20a3;
	case 8362ULL: goto x86_l_20aa;
	case 8370ULL: goto x86_l_20b2;
	case 8377ULL: goto x86_l_20b9;
	case 8379ULL: goto x86_l_20bb;
	case 8388ULL: goto x86_l_20c4;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8448ULL: goto x86_l_2100;
	case 8455ULL: goto x86_l_2107;
	case 8463ULL: goto x86_l_210f;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8481ULL: goto x86_l_2121;
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8497ULL: goto x86_l_2131;
	case 8501ULL: goto x86_l_2135;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8523ULL: goto x86_l_214b;
	case 8525ULL: goto x86_l_214d;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8533ULL: goto x86_l_2155;
	case 8541ULL: goto x86_l_215d;
	case 8548ULL: goto x86_l_2164;
	case 8556ULL: goto x86_l_216c;
	case 8563ULL: goto x86_l_2173;
	case 8565ULL: goto x86_l_2175;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8586ULL: goto x86_l_218a;
	case 8593ULL: goto x86_l_2191;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8621ULL: goto x86_l_21ad;
	case 8623ULL: goto x86_l_21af;
	case 8626ULL: goto x86_l_21b2;
	case 8634ULL: goto x86_l_21ba;
	case 8641ULL: goto x86_l_21c1;
	case 8648ULL: goto x86_l_21c8;
	case 8655ULL: goto x86_l_21cf;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8686ULL: goto x86_l_21ee;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8703ULL: goto x86_l_21ff;
	case 8711ULL: goto x86_l_2207;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8733ULL: goto x86_l_221d;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8755ULL: goto x86_l_2233;
	case 8758ULL: goto x86_l_2236;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8790ULL: goto x86_l_2256;
	case 8797ULL: goto x86_l_225d;
	case 8803ULL: goto x86_l_2263;
	case 8806ULL: goto x86_l_2266;
	case 8809ULL: goto x86_l_2269;
	case 8812ULL: goto x86_l_226c;
	case 8818ULL: goto x86_l_2272;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8853ULL: goto x86_l_2295;
	case 8860ULL: goto x86_l_229c;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8888ULL: goto x86_l_22b8;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8914ULL: goto x86_l_22d2;
	case 8917ULL: goto x86_l_22d5;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8963ULL: goto x86_l_2303;
	case 8965ULL: goto x86_l_2305;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8986ULL: goto x86_l_231a;
	case 8993ULL: goto x86_l_2321;
	case 8996ULL: goto x86_l_2324;
	case 9000ULL: goto x86_l_2328;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9032ULL: goto x86_l_2348;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9053ULL: goto x86_l_235d;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9075ULL: goto x86_l_2373;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9093ULL: goto x86_l_2385;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9110ULL: goto x86_l_2396;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9124ULL: goto x86_l_23a4;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9136ULL: goto x86_l_23b0;
	case 9142ULL: goto x86_l_23b6;
	case 9151ULL: goto x86_l_23bf;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9182ULL: goto x86_l_23de;
	case 9184ULL: goto x86_l_23e0;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9196ULL: goto x86_l_23ec;
	case 9203ULL: goto x86_l_23f3;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9223ULL: goto x86_l_2407;
	case 9227ULL: goto x86_l_240b;
	case 9231ULL: goto x86_l_240f;
	case 9238ULL: goto x86_l_2416;
	case 9243ULL: goto x86_l_241b;
	case 9248ULL: goto x86_l_2420;
	case 9250ULL: goto x86_l_2422;
	case 9257ULL: goto x86_l_2429;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9283ULL: goto x86_l_2443;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9324ULL: goto x86_l_246c;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9346ULL: goto x86_l_2482;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9357ULL: goto x86_l_248d;
	case 9360ULL: goto x86_l_2490;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9374ULL: goto x86_l_249e;
	case 9377ULL: goto x86_l_24a1;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9386ULL: goto x86_l_24aa;
	case 9388ULL: goto x86_l_24ac;
	case 9395ULL: goto x86_l_24b3;
	case 9398ULL: goto x86_l_24b6;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9427ULL: goto x86_l_24d3;
	case 9430ULL: goto x86_l_24d6;
	case 9437ULL: goto x86_l_24dd;
	case 9446ULL: goto x86_l_24e6;
	case 9449ULL: goto x86_l_24e9;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9474ULL: goto x86_l_2502;
	case 9482ULL: goto x86_l_250a;
	case 9485ULL: goto x86_l_250d;
	case 9493ULL: goto x86_l_2515;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9510ULL: goto x86_l_2526;
	case 9512ULL: goto x86_l_2528;
	case 9515ULL: goto x86_l_252b;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9529ULL: goto x86_l_2539;
	case 9535ULL: goto x86_l_253f;
	case 9538ULL: goto x86_l_2542;
	case 9545ULL: goto x86_l_2549;
	case 9551ULL: goto x86_l_254f;
	case 9558ULL: goto x86_l_2556;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1de4:
	/* 0x1de4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de7:
	/* 0x1de7: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1def:
	/* 0x1def: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1df3:
	/* 0x1df3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df8:
	/* 0x1df8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e02:
	/* 0x1e02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e07:
	/* 0x1e07: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e0a:
	/* 0x1e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0c:
	/* 0x1e0c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e11:
	/* 0x1e11: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e15:
	/* 0x1e15: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e1d:
	/* 0x1e1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e22:
	/* 0x1e22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e27:
	/* 0x1e27: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e2c:
	/* 0x1e2c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e30:
	/* 0x1e30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e35:
	/* 0x1e35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e37:
	/* 0x1e37: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e3f:
	/* 0x1e3f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e44:
	/* 0x1e44: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1e49:
	/* 0x1e49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e56:
	/* 0x1e56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e5b:
	/* 0x1e5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5d:
	/* 0x1e5d: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e61:
	/* 0x1e61: mov    DWORD PTR [rsp+0xf0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1e68:
	/* 0x1e68: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e70:
	/* 0x1e70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e75:
	/* 0x1e75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e82:
	/* 0x1e82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e84:
	/* 0x1e84: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e8c:
	/* 0x1e8c: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e90:
	/* 0x1e90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e95:
	/* 0x1e95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ea7:
	/* 0x1ea7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1eab:
	/* 0x1eab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb0:
	/* 0x1eb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb2:
	/* 0x1eb2: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    r15d,DWORD PTR [rsp+0x10c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1ec7:
	/* 0x1ec7: cmp    r15d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1ecb:
	/* 0x1ecb: mov    ebx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1ed5:
	/* 0x1ed5: cmovb  ebp,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R15, X86_WIDTH_32, X86_CC_B);
x86_l_1ed9:
	/* 0x1ed9: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1efd:
	/* 0x1efd: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1f09:
	/* 0x1f09: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f11:
	/* 0x1f11: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1f17:
	/* 0x1f17: ja     1fac <vfs_writev_magic_return+0x1fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fac;
	}
x86_l_1f1d:
	/* 0x1f1d: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f25:
	/* 0x1f25: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1f2e:
	/* 0x1f2e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f36:
	/* 0x1f36: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1f3e:
	/* 0x1f3e: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1f44:
	/* 0x1f44: ja     1fac <vfs_writev_magic_return+0x1fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fac;
	}
x86_l_1f46:
	/* 0x1f46: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f4a:
	/* 0x1f4a: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1f51:
	/* 0x1f51: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f56:
	/* 0x1f56: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f5b:
	/* 0x1f5b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f63:
	/* 0x1f63: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f67:
	/* 0x1f67: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f73:
	/* 0x1f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f75:
	/* 0x1f75: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f77:
	/* 0x1f77: jle    1fac <vfs_writev_magic_return+0x1fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fac;
	}
x86_l_1f79:
	/* 0x1f79: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f81:
	/* 0x1f81: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1f88:
	/* 0x1f88: ja     1fac <vfs_writev_magic_return+0x1fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fac;
	}
x86_l_1f8a:
	/* 0x1f8a: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1f92:
	/* 0x1f92: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f9a:
	/* 0x1f9a: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1fa5:
	/* 0x1fa5: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1fac:
	/* 0x1fac: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1fbe:
	/* 0x1fbe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc3:
	/* 0x1fc3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fc8:
	/* 0x1fc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    rdx,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1fd5:
	/* 0x1fd5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fda:
	/* 0x1fda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fdc:
	/* 0x1fdc: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1fe4:
	/* 0x1fe4: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1fe7:
	/* 0x1fe7: cmovb  ebx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1fea:
	/* 0x1fea: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fef:
	/* 0x1fef: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2001:
	/* 0x2001: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2003:
	/* 0x2003: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2005:
	/* 0x2005: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_2008:
	/* 0x2008: je     20aa <vfs_writev_magic_return+0x20aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20aa;
	}
x86_l_200e:
	/* 0x200e: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2012:
	/* 0x2012: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_201a:
	/* 0x201a: cmp    rbx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 27899ULL);
x86_l_2021:
	/* 0x2021: ja     20aa <vfs_writev_magic_return+0x20aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20aa;
	}
x86_l_2027:
	/* 0x2027: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_2030:
	/* 0x2030: lea    rdi,[r14+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_2034:
	/* 0x2034: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_203b:
	/* 0x203b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2040:
	/* 0x2040: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2045:
	/* 0x2045: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_204a:
	/* 0x204a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_204f:
	/* 0x204f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2051:
	/* 0x2051: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2054:
	/* 0x2054: jne    20aa <vfs_writev_magic_return+0x20aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20aa;
	}
x86_l_2056:
	/* 0x2056: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_205a:
	/* 0x205a: cmp    eax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_205f:
	/* 0x205f: jb     206e <vfs_writev_magic_return+0x206e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_206e;
	}
x86_l_2061:
	/* 0x2061: mov    DWORD PTR [rsp+0x30],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158434303ULL);
x86_l_2069:
	/* 0x2069: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_206e:
	/* 0x206e: lea    rdi,[r14+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_2072:
	/* 0x2072: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_2079:
	/* 0x2079: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_207b:
	/* 0x207b: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2083:
	/* 0x2083: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2088:
	/* 0x2088: mov    esi,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_208c:
	/* 0x208c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208e:
	/* 0x208e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2091:
	/* 0x2091: jne    20aa <vfs_writev_magic_return+0x20aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20aa;
	}
x86_l_2093:
	/* 0x2093: add    rbx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2097:
	/* 0x2097: add    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_209b:
	/* 0x209b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20a3:
	/* 0x20a3: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_20aa:
	/* 0x20aa: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20b2:
	/* 0x20b2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_20b9:
	/* 0x20b9: ja     2107 <vfs_writev_magic_return+0x2107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2107;
	}
x86_l_20bb:
	/* 0x20bb: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_20c4:
	/* 0x20c4: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_20ca:
	/* 0x20ca: ja     2107 <vfs_writev_magic_return+0x2107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2107;
	}
x86_l_20cc:
	/* 0x20cc: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_20d4:
	/* 0x20d4: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_20d8:
	/* 0x20d8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_20df:
	/* 0x20df: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20e4:
	/* 0x20e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20e9:
	/* 0x20e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ee:
	/* 0x20ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f0:
	/* 0x20f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20f3:
	/* 0x20f3: js     2107 <vfs_writev_magic_return+0x2107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2107;
	}
x86_l_20f5:
	/* 0x20f5: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_20f8:
	/* 0x20f8: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2100:
	/* 0x2100: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2107:
	/* 0x2107: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_210f:
	/* 0x210f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2116:
	/* 0x2116: ja     2164 <vfs_writev_magic_return+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2164;
	}
x86_l_2118:
	/* 0x2118: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_2121:
	/* 0x2121: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2127:
	/* 0x2127: ja     2164 <vfs_writev_magic_return+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2164;
	}
x86_l_2129:
	/* 0x2129: lea    rdx,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2131:
	/* 0x2131: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2135:
	/* 0x2135: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_213c:
	/* 0x213c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2141:
	/* 0x2141: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2146:
	/* 0x2146: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_214b:
	/* 0x214b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214d:
	/* 0x214d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2150:
	/* 0x2150: js     2164 <vfs_writev_magic_return+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2164;
	}
x86_l_2152:
	/* 0x2152: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2155:
	/* 0x2155: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_215d:
	/* 0x215d: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2164:
	/* 0x2164: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_216c:
	/* 0x216c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2173:
	/* 0x2173: ja     21c1 <vfs_writev_magic_return+0x21c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21c1;
	}
x86_l_2175:
	/* 0x2175: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_217e:
	/* 0x217e: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2184:
	/* 0x2184: ja     21c1 <vfs_writev_magic_return+0x21c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21c1;
	}
x86_l_2186:
	/* 0x2186: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_218a:
	/* 0x218a: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2191:
	/* 0x2191: lea    rdx,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_2199:
	/* 0x2199: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_219e:
	/* 0x219e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a3:
	/* 0x21a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a8:
	/* 0x21a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21aa:
	/* 0x21aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ad:
	/* 0x21ad: js     21c1 <vfs_writev_magic_return+0x21c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_21c1;
	}
x86_l_21af:
	/* 0x21af: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_21b2:
	/* 0x21b2: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21ba:
	/* 0x21ba: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_21c1:
	/* 0x21c1: lea    r13,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_21c8:
	/* 0x21c8: mov    rbp,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_21cf:
	/* 0x21cf: mov    r15,QWORD PTR [r14+0x7df8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_21d6:
	/* 0x21d6: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_21d9:
	/* 0x21d9: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_21e1:
	/* 0x21e1: je     2300 <vfs_writev_magic_return+0x2300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2300;
	}
x86_l_21e7:
	/* 0x21e7: or     rbp,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 32240ULL);
x86_l_21ee:
	/* 0x21ee: mov    r12d,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21f2:
	/* 0x21f2: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_21f7:
	/* 0x21f7: mov    WORD PTR [rsp+0x120],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_21ff:
	/* 0x21ff: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2207:
	/* 0x2207: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_bufs)));
x86_l_220e:
	/* 0x220e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2213:
	/* 0x2213: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2218:
	/* 0x2218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221a:
	/* 0x221a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_221d:
	/* 0x221d: je     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253f;
	}
x86_l_2223:
	/* 0x2223: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2226:
	/* 0x2226: mov    DWORD PTR [rsp+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222b:
	/* 0x222b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222e:
	/* 0x222e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2233:
	/* 0x2233: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2236:
	/* 0x2236: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2238:
	/* 0x2238: call   59e9 <vfs_writev_magic_return+0x59e9> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_223d:
	/* 0x223d: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2242:
	/* 0x2242: cmp    rax,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31995ULL);
x86_l_2248:
	/* 0x2248: ja     2542 <vfs_writev_magic_return+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2542;
	}
x86_l_224e:
	/* 0x224e: mov    esi,DWORD PTR [rax+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2256:
	/* 0x2256: cmp    rsi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 256ULL);
x86_l_225d:
	/* 0x225d: ja     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_253f;
	}
x86_l_2263:
	/* 0x2263: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2266:
	/* 0x2266: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2269:
	/* 0x2269: lea    ecx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_226c:
	/* 0x226c: cmp    ecx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2272:
	/* 0x2272: ja     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_253f;
	}
x86_l_2278:
	/* 0x2278: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_227c:
	/* 0x227c: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2283:
	/* 0x2283: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2288:
	/* 0x2288: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_228b:
	/* 0x228b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228d:
	/* 0x228d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228f:
	/* 0x228f: je     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253f;
	}
x86_l_2295:
	/* 0x2295: mov    r12,QWORD PTR [r14+0x7e10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_229c:
	/* 0x229c: movzx  eax,WORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 288ULL);
x86_l_22a4:
	/* 0x22a4: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a9:
	/* 0x22a9: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_22b0:
	/* 0x22b0: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b4:
	/* 0x22b4: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_22b8:
	/* 0x22b8: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_exact_version)));
x86_l_22bf:
	/* 0x22bf: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22c4:
	/* 0x22c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22c9:
	/* 0x22c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22cb:
	/* 0x22cb: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_22d2:
	/* 0x22d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22d5:
	/* 0x22d5: je     24a6 <vfs_writev_magic_return+0x24a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a6;
	}
x86_l_22db:
	/* 0x22db: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22de:
	/* 0x22de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22e3:
	/* 0x22e3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_22e6:
	/* 0x22e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e8:
	/* 0x22e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22eb:
	/* 0x22eb: je     24aa <vfs_writev_magic_return+0x24aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24aa;
	}
x86_l_22f1:
	/* 0x22f1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f4:
	/* 0x22f4: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f8:
	/* 0x22f8: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22fb:
	/* 0x22fb: jmp    24b3 <vfs_writev_magic_return+0x24b3> */
	goto x86_l_24b3;
x86_l_2300:
	/* 0x2300: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2303:
	/* 0x2303: jne    2313 <vfs_writev_magic_return+0x2313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2313;
	}
x86_l_2305:
	/* 0x2305: cmp    QWORD PTR [r14+0x7df0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138469745623040ULL);
x86_l_230d:
	/* 0x230d: je     244c <vfs_writev_magic_return+0x244c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244c;
	}
x86_l_2313:
	/* 0x2313: lea    r12,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_231a:
	/* 0x231a: mov    rbx,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2321:
	/* 0x2321: or     rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2324:
	/* 0x2324: mov    eax,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2328:
	/* 0x2328: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_232c:
	/* 0x232c: movzx  r15d,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2331:
	/* 0x2331: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2333:
	/* 0x2333: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2335:
	/* 0x2335: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2337:
	/* 0x2337: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_233a:
	/* 0x233a: je     24ef <vfs_writev_magic_return+0x24ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ef;
	}
x86_l_2340:
	/* 0x2340: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2348:
	/* 0x2348: mov    QWORD PTR [rsp+0x110],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2350:
	/* 0x2350: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2355:
	/* 0x2355: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_235d:
	/* 0x235d: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_2364:
	/* 0x2364: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2369:
	/* 0x2369: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_236e:
	/* 0x236e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2370:
	/* 0x2370: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2373:
	/* 0x2373: je     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253f;
	}
x86_l_2379:
	/* 0x2379: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_237e:
	/* 0x237e: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_2385:
	/* 0x2385: ja     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_253f;
	}
x86_l_238b:
	/* 0x238b: lea    edx,[rcx+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_238e:
	/* 0x238e: mov    ecx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2396:
	/* 0x2396: cmp    ecx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_239c:
	/* 0x239c: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_23a1:
	/* 0x23a1: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_23a4:
	/* 0x23a4: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_23a7:
	/* 0x23a7: lea    edx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23aa:
	/* 0x23aa: cmp    edx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_23b0:
	/* 0x23b0: ja     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_253f;
	}
x86_l_23b6:
	/* 0x23b6: mov    WORD PTR [rsp+0x120],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_23bf:
	/* 0x23bf: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_23c2:
	/* 0x23c2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_23c5:
	/* 0x23c5: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23c9:
	/* 0x23c9: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_23cc:
	/* 0x23cc: lea    rdx,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23d0:
	/* 0x23d0: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23d7:
	/* 0x23d7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_23dc:
	/* 0x23dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23de:
	/* 0x23de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23e0:
	/* 0x23e0: je     249b <vfs_writev_magic_return+0x249b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249b;
	}
x86_l_23e6:
	/* 0x23e6: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_23e9:
	/* 0x23e9: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ec:
	/* 0x23ec: mov    r15,QWORD PTR [r15+0x7e00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_23f3:
	/* 0x23f3: movzx  eax,WORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 288ULL);
x86_l_23fb:
	/* 0x23fb: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2400:
	/* 0x2400: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_2407:
	/* 0x2407: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_240b:
	/* 0x240b: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_240f:
	/* 0x240f: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_prefix_version)));
x86_l_2416:
	/* 0x2416: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_241b:
	/* 0x241b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2420:
	/* 0x2420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2422:
	/* 0x2422: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2429:
	/* 0x2429: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_242c:
	/* 0x242c: je     2458 <vfs_writev_magic_return+0x2458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2458;
	}
x86_l_242e:
	/* 0x242e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2431:
	/* 0x2431: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2436:
	/* 0x2436: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2439:
	/* 0x2439: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243b:
	/* 0x243b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243e:
	/* 0x243e: je     2458 <vfs_writev_magic_return+0x2458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2458;
	}
x86_l_2440:
	/* 0x2440: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2443:
	/* 0x2443: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2447:
	/* 0x2447: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_244a:
	/* 0x244a: jmp    245a <vfs_writev_magic_return+0x245a> */
	goto x86_l_245a;
x86_l_244c:
	/* 0x244c: mov    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32496ULL);
x86_l_2453:
	/* 0x2453: jmp    2542 <vfs_writev_magic_return+0x2542> */
	goto x86_l_2542;
x86_l_2458:
	/* 0x2458: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_245a:
	/* 0x245a: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_245f:
	/* 0x245f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2464:
	/* 0x2464: mov    rsi,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_246c:
	/* 0x246c: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2474:
	/* 0x2474: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2477:
	/* 0x2477: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_247a:
	/* 0x247a: andn   rax,r15,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_247f:
	/* 0x247f: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2482:
	/* 0x2482: andn   rax,rbp,r15 */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_2487:
	/* 0x2487: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_248a:
	/* 0x248a: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_248d:
	/* 0x248d: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2490:
	/* 0x2490: movzx  r15d,WORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 288ULL);
x86_l_2499:
	/* 0x2499: jmp    24ef <vfs_writev_magic_return+0x24ef> */
	goto x86_l_24ef;
x86_l_249b:
	/* 0x249b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_249e:
	/* 0x249e: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_24a1:
	/* 0x24a1: jmp    2542 <vfs_writev_magic_return+0x2542> */
	goto x86_l_2542;
x86_l_24a6:
	/* 0x24a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a8:
	/* 0x24a8: jmp    24b3 <vfs_writev_magic_return+0x24b3> */
	goto x86_l_24b3;
x86_l_24aa:
	/* 0x24aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24ac:
	/* 0x24ac: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_24b3:
	/* 0x24b3: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24b6:
	/* 0x24b6: lea    r12,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_24bd:
	/* 0x24bd: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_24c0:
	/* 0x24c0: and    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_24c3:
	/* 0x24c3: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24c6:
	/* 0x24c6: andn   rsi,rax,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RSI, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_24cb:
	/* 0x24cb: andn   rdi,rdx,rax */
	X86_SIM_L_EXEC_ANDN(X86_RDI, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_24d0:
	/* 0x24d0: and    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_24d3:
	/* 0x24d3: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_24d6:
	/* 0x24d6: mov    rbp,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_24dd:
	/* 0x24dd: movzx  r15d,WORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 288ULL);
x86_l_24e6:
	/* 0x24e6: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_24e9:
	/* 0x24e9: jne    2340 <vfs_writev_magic_return+0x2340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2340;
	}
x86_l_24ef:
	/* 0x24ef: cmp    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f4:
	/* 0x24f4: je     2c3d <vfs_writev_magic_return+0x2c3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11325ULL;
	}
x86_l_24fa:
	/* 0x24fa: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2502:
	/* 0x2502: mov    QWORD PTR [rsp+0x110],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_250a:
	/* 0x250a: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_250d:
	/* 0x250d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2515:
	/* 0x2515: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_251c:
	/* 0x251c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2521:
	/* 0x2521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2526:
	/* 0x2526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2528:
	/* 0x2528: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_252b:
	/* 0x252b: je     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253f;
	}
x86_l_252d:
	/* 0x252d: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2532:
	/* 0x2532: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_2539:
	/* 0x2539: jbe    2a70 <vfs_writev_magic_return+0x2a70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10864ULL;
	}
x86_l_253f:
	/* 0x253f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2542:
	/* 0x2542: and    QWORD PTR [r14+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_2549:
	/* 0x2549: je     2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11704ULL;
	}
x86_l_254f:
	/* 0x254f: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2556:
	/* 0x2556: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_255a:
	/* 0x255a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_255f:
	/* 0x255f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2564:
	/* 0x2564: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 9577ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9585ULL: goto x86_l_2571;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9611ULL: goto x86_l_258b;
	case 9616ULL: goto x86_l_2590;
	case 9621ULL: goto x86_l_2595;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9685ULL: goto x86_l_25d5;
	case 9689ULL: goto x86_l_25d9;
	case 9693ULL: goto x86_l_25dd;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9720ULL: goto x86_l_25f8;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9750ULL: goto x86_l_2616;
	case 9752ULL: goto x86_l_2618;
	case 9756ULL: goto x86_l_261c;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9790ULL: goto x86_l_263e;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9832ULL: goto x86_l_2668;
	case 9837ULL: goto x86_l_266d;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9874ULL: goto x86_l_2692;
	case 9879ULL: goto x86_l_2697;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9888ULL: goto x86_l_26a0;
	case 9892ULL: goto x86_l_26a4;
	case 9896ULL: goto x86_l_26a8;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9926ULL: goto x86_l_26c6;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9953ULL: goto x86_l_26e1;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9980ULL: goto x86_l_26fc;
	case 9983ULL: goto x86_l_26ff;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9993ULL: goto x86_l_2709;
	case 9997ULL: goto x86_l_270d;
	case 10001ULL: goto x86_l_2711;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10086ULL: goto x86_l_2766;
	case 10088ULL: goto x86_l_2768;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10122ULL: goto x86_l_278a;
	case 10126ULL: goto x86_l_278e;
	case 10130ULL: goto x86_l_2792;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10149ULL: goto x86_l_27a5;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10253ULL: goto x86_l_280d;
	case 10257ULL: goto x86_l_2811;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10291ULL: goto x86_l_2833;
	case 10295ULL: goto x86_l_2837;
	case 10299ULL: goto x86_l_283b;
	case 10306ULL: goto x86_l_2842;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10333ULL: goto x86_l_285d;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
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
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10398ULL: goto x86_l_289e;
	case 10402ULL: goto x86_l_28a2;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10413ULL: goto x86_l_28ad;
	case 10417ULL: goto x86_l_28b1;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10457ULL: goto x86_l_28d9;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10492ULL: goto x86_l_28fc;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10519ULL: goto x86_l_2917;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10575ULL: goto x86_l_294f;
	case 10579ULL: goto x86_l_2953;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10627ULL: goto x86_l_2983;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10693ULL: goto x86_l_29c5;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10711ULL: goto x86_l_29d7;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10723ULL: goto x86_l_29e3;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10749ULL: goto x86_l_29fd;
	case 10753ULL: goto x86_l_2a01;
	case 10761ULL: goto x86_l_2a09;
	case 10763ULL: goto x86_l_2a0b;
	case 10770ULL: goto x86_l_2a12;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10790ULL: goto x86_l_2a26;
	case 10792ULL: goto x86_l_2a28;
	case 10794ULL: goto x86_l_2a2a;
	case 10798ULL: goto x86_l_2a2e;
	case 10806ULL: goto x86_l_2a36;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10819ULL: goto x86_l_2a43;
	case 10825ULL: goto x86_l_2a49;
	case 10829ULL: goto x86_l_2a4d;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10854ULL: goto x86_l_2a66;
	case 10857ULL: goto x86_l_2a69;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10872ULL: goto x86_l_2a78;
	case 10878ULL: goto x86_l_2a7e;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10902ULL: goto x86_l_2a96;
	case 10908ULL: goto x86_l_2a9c;
	case 10910ULL: goto x86_l_2a9e;
	case 10913ULL: goto x86_l_2aa1;
	case 10915ULL: goto x86_l_2aa3;
	case 10921ULL: goto x86_l_2aa9;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10933ULL: goto x86_l_2ab5;
	case 10939ULL: goto x86_l_2abb;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10958ULL: goto x86_l_2ace;
	case 10960ULL: goto x86_l_2ad0;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10967ULL: goto x86_l_2ad7;
	case 10973ULL: goto x86_l_2add;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10990ULL: goto x86_l_2aee;
	case 10995ULL: goto x86_l_2af3;
	case 10998ULL: goto x86_l_2af6;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11016ULL: goto x86_l_2b08;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11047ULL: goto x86_l_2b27;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11162ULL: goto x86_l_2b9a;
	case 11164ULL: goto x86_l_2b9c;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11178ULL: goto x86_l_2baa;
	case 11181ULL: goto x86_l_2bad;
	case 11183ULL: goto x86_l_2baf;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11202ULL: goto x86_l_2bc2;
	case 11206ULL: goto x86_l_2bc6;
	case 11210ULL: goto x86_l_2bca;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11236ULL: goto x86_l_2be4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2569:
	/* 0x2569: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_256e:
	/* 0x256e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2571:
	/* 0x2571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2573:
	/* 0x2573: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2578:
	/* 0x2578: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_257d:
	/* 0x257d: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2581:
	/* 0x2581: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2586:
	/* 0x2586: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_258b:
	/* 0x258b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2590:
	/* 0x2590: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2595:
	/* 0x2595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2597:
	/* 0x2597: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_259c:
	/* 0x259c: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_25a0:
	/* 0x25a0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25a5:
	/* 0x25a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25aa:
	/* 0x25aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25af:
	/* 0x25af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25b4:
	/* 0x25b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b6:
	/* 0x25b6: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25bb:
	/* 0x25bb: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_25bf:
	/* 0x25bf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25c4:
	/* 0x25c4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25c9:
	/* 0x25c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25ce:
	/* 0x25ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25d3:
	/* 0x25d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d5:
	/* 0x25d5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d9:
	/* 0x25d9: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_25dd:
	/* 0x25dd: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25e1:
	/* 0x25e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25e6:
	/* 0x25e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25eb:
	/* 0x25eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25f0:
	/* 0x25f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f5:
	/* 0x25f5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25f8:
	/* 0x25f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fa:
	/* 0x25fa: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ff:
	/* 0x25ff: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2604:
	/* 0x2604: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2609:
	/* 0x2609: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_260e:
	/* 0x260e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2613:
	/* 0x2613: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2616:
	/* 0x2616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2618:
	/* 0x2618: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_261c:
	/* 0x261c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2620:
	/* 0x2620: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2624:
	/* 0x2624: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2628:
	/* 0x2628: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262d:
	/* 0x262d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2632:
	/* 0x2632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2637:
	/* 0x2637: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_263c:
	/* 0x263c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263e:
	/* 0x263e: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2642:
	/* 0x2642: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2646:
	/* 0x2646: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_264b:
	/* 0x264b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2650:
	/* 0x2650: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2655:
	/* 0x2655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_265a:
	/* 0x265a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_265d:
	/* 0x265d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265f:
	/* 0x265f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2664:
	/* 0x2664: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2668:
	/* 0x2668: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_266d:
	/* 0x266d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2672:
	/* 0x2672: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2677:
	/* 0x2677: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_267c:
	/* 0x267c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267e:
	/* 0x267e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2683:
	/* 0x2683: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2688:
	/* 0x2688: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_268d:
	/* 0x268d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2692:
	/* 0x2692: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2697:
	/* 0x2697: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_269a:
	/* 0x269a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269c:
	/* 0x269c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26a0:
	/* 0x26a0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_26a4:
	/* 0x26a4: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_26a8:
	/* 0x26a8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26ac:
	/* 0x26ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26b1:
	/* 0x26b1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_26b6:
	/* 0x26b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26bb:
	/* 0x26bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26c0:
	/* 0x26c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c2:
	/* 0x26c2: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26c6:
	/* 0x26c6: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26ca:
	/* 0x26ca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26cf:
	/* 0x26cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26d4:
	/* 0x26d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26d9:
	/* 0x26d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26de:
	/* 0x26de: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26e1:
	/* 0x26e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e3:
	/* 0x26e3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26e8:
	/* 0x26e8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ed:
	/* 0x26ed: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_26f2:
	/* 0x26f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26f7:
	/* 0x26f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26fc:
	/* 0x26fc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_26ff:
	/* 0x26ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2701:
	/* 0x2701: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2705:
	/* 0x2705: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2709:
	/* 0x2709: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_270d:
	/* 0x270d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2711:
	/* 0x2711: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2716:
	/* 0x2716: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_271b:
	/* 0x271b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2720:
	/* 0x2720: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2725:
	/* 0x2725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2727:
	/* 0x2727: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_272c:
	/* 0x272c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2730:
	/* 0x2730: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2735:
	/* 0x2735: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_273a:
	/* 0x273a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_273f:
	/* 0x273f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2744:
	/* 0x2744: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2746:
	/* 0x2746: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_274b:
	/* 0x274b: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274f:
	/* 0x274f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2754:
	/* 0x2754: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2759:
	/* 0x2759: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_275e:
	/* 0x275e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2763:
	/* 0x2763: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2766:
	/* 0x2766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2768:
	/* 0x2768: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_276d:
	/* 0x276d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2772:
	/* 0x2772: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2777:
	/* 0x2777: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_277c:
	/* 0x277c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2781:
	/* 0x2781: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2784:
	/* 0x2784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2786:
	/* 0x2786: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_278a:
	/* 0x278a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_278e:
	/* 0x278e: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2792:
	/* 0x2792: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2796:
	/* 0x2796: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_279b:
	/* 0x279b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27a0:
	/* 0x27a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27a5:
	/* 0x27a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27aa:
	/* 0x27aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ac:
	/* 0x27ac: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27b1:
	/* 0x27b1: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_27b5:
	/* 0x27b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ba:
	/* 0x27ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_27bf:
	/* 0x27bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27c4:
	/* 0x27c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27c9:
	/* 0x27c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cb:
	/* 0x27cb: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_27d0:
	/* 0x27d0: jne    2837 <vfs_writev_magic_return+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2837;
	}
x86_l_27d2:
	/* 0x27d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d7:
	/* 0x27d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27dc:
	/* 0x27dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e1:
	/* 0x27e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e6:
	/* 0x27e6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27e9:
	/* 0x27e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27eb:
	/* 0x27eb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27f0:
	/* 0x27f0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27f5:
	/* 0x27f5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_27fa:
	/* 0x27fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27ff:
	/* 0x27ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2804:
	/* 0x2804: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2807:
	/* 0x2807: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2809:
	/* 0x2809: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_280d:
	/* 0x280d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2811:
	/* 0x2811: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2815:
	/* 0x2815: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2819:
	/* 0x2819: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_281e:
	/* 0x281e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2823:
	/* 0x2823: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2828:
	/* 0x2828: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_282d:
	/* 0x282d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282f:
	/* 0x282f: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2833:
	/* 0x2833: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2837:
	/* 0x2837: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_283b:
	/* 0x283b: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2842:
	/* 0x2842: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2847:
	/* 0x2847: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_284c:
	/* 0x284c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2851:
	/* 0x2851: lea    r12,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2855:
	/* 0x2855: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_285a:
	/* 0x285a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_285d:
	/* 0x285d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285f:
	/* 0x285f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2864:
	/* 0x2864: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2868:
	/* 0x2868: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_286d:
	/* 0x286d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2872:
	/* 0x2872: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2883:
	/* 0x2883: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2888:
	/* 0x2888: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_288d:
	/* 0x288d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2892:
	/* 0x2892: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2897:
	/* 0x2897: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_289c:
	/* 0x289c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289e:
	/* 0x289e: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28a2:
	/* 0x28a2: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_28a6:
	/* 0x28a6: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_28ab:
	/* 0x28ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ad:
	/* 0x28ad: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28b1:
	/* 0x28b1: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28b5:
	/* 0x28b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28ba:
	/* 0x28ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28c4:
	/* 0x28c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c9:
	/* 0x28c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28cb:
	/* 0x28cb: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28d0:
	/* 0x28d0: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d4:
	/* 0x28d4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28d9:
	/* 0x28d9: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_28dd:
	/* 0x28dd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28e2:
	/* 0x28e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28e7:
	/* 0x28e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28ec:
	/* 0x28ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28f1:
	/* 0x28f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f3:
	/* 0x28f3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28f8:
	/* 0x28f8: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28fc:
	/* 0x28fc: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2900:
	/* 0x2900: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2905:
	/* 0x2905: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_290a:
	/* 0x290a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_290f:
	/* 0x290f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2914:
	/* 0x2914: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2917:
	/* 0x2917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2919:
	/* 0x2919: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_291e:
	/* 0x291e: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2922:
	/* 0x2922: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2927:
	/* 0x2927: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_292c:
	/* 0x292c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2931:
	/* 0x2931: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2936:
	/* 0x2936: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2939:
	/* 0x2939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293b:
	/* 0x293b: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_2940:
	/* 0x2940: je     2947 <vfs_writev_magic_return+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2947;
	}
x86_l_2942:
	/* 0x2942: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2947:
	/* 0x2947: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_294f:
	/* 0x294f: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2953:
	/* 0x2953: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_295b:
	/* 0x295b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2960:
	/* 0x2960: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2965:
	/* 0x2965: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_296a:
	/* 0x296a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296c:
	/* 0x296c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2971:
	/* 0x2971: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2976:
	/* 0x2976: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_297b:
	/* 0x297b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2980:
	/* 0x2980: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2983:
	/* 0x2983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2985:
	/* 0x2985: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_298a:
	/* 0x298a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_298f:
	/* 0x298f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2994:
	/* 0x2994: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2999:
	/* 0x2999: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_299e:
	/* 0x299e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a0:
	/* 0x29a0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29a5:
	/* 0x29a5: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29aa:
	/* 0x29aa: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_29af:
	/* 0x29af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b4:
	/* 0x29b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29b7:
	/* 0x29b7: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_29bc:
	/* 0x29bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29be:
	/* 0x29be: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_29c1:
	/* 0x29c1: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_29c5:
	/* 0x29c5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_29ca:
	/* 0x29ca: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_29cf:
	/* 0x29cf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29d4:
	/* 0x29d4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_29d7:
	/* 0x29d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d9:
	/* 0x29d9: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_29de:
	/* 0x29de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e3:
	/* 0x29e3: mov    rdi,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_29eb:
	/* 0x29eb: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_29f0:
	/* 0x29f0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29f3:
	/* 0x29f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f5:
	/* 0x29f5: mov    rax,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_29fd:
	/* 0x29fd: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2a01:
	/* 0x2a01: mov    rbx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2a09:
	/* 0x2a09: je     2a2e <vfs_writev_magic_return+0x2a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2e;
	}
x86_l_2a0b:
	/* 0x2a0b: mov    rsi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2a12:
	/* 0x2a12: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2a17:
	/* 0x2a17: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2a1c:
	/* 0x2a1c: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2a21:
	/* 0x2a21: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a24:
	/* 0x2a24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a26:
	/* 0x2a26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a28:
	/* 0x2a28: js     2a2e <vfs_writev_magic_return+0x2a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a2e;
	}
x86_l_2a2a:
	/* 0x2a2a: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2a2e:
	/* 0x2a2e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a36:
	/* 0x2a36: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2a40:
	/* 0x2a40: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2a43:
	/* 0x2a43: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2a49:
	/* 0x2a49: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a4d:
	/* 0x2a4d: mov    rsi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2a54:
	/* 0x2a54: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2a59:
	/* 0x2a59: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2a5e:
	/* 0x2a5e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2a63:
	/* 0x2a63: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a66:
	/* 0x2a66: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2a69:
	/* 0x2a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6b:
	/* 0x2a6b: jmp    2dba <vfs_writev_magic_return+0x2dba> */
	return 11706ULL;
x86_l_2a70:
	/* 0x2a70: mov    edx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2a78:
	/* 0x2a78: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2a7e:
	/* 0x2a7e: jbe    2a9e <vfs_writev_magic_return+0x2a9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a9e;
	}
x86_l_2a80:
	/* 0x2a80: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a82:
	/* 0x2a82: add    ecx,0xffffff05 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967045ULL);
x86_l_2a88:
	/* 0x2a88: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a8b:
	/* 0x2a8b: mov    edx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 255ULL);
x86_l_2a90:
	/* 0x2a90: cmp    ecx,0x7c00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31744ULL);
x86_l_2a96:
	/* 0x2a96: ja     253f <vfs_writev_magic_return+0x253f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9535ULL;
	}
x86_l_2a9c:
	/* 0x2a9c: jmp    2acc <vfs_writev_magic_return+0x2acc> */
	goto x86_l_2acc;
x86_l_2a9e:
	/* 0x2a9e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aa1:
	/* 0x2aa1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2aa3:
	/* 0x2aa3: je     2542 <vfs_writev_magic_return+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9538ULL;
	}
x86_l_2aa9:
	/* 0x2aa9: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2aac:
	/* 0x2aac: add    esi,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2aaf:
	/* 0x2aaf: cmp    esi,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 32000ULL);
x86_l_2ab5:
	/* 0x2ab5: ja     2542 <vfs_writev_magic_return+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9538ULL;
	}
x86_l_2abb:
	/* 0x2abb: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2abd:
	/* 0x2abd: and    edx,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 255ULL);
x86_l_2ac3:
	/* 0x2ac3: je     2b97 <vfs_writev_magic_return+0x2b97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b97;
	}
x86_l_2ac9:
	/* 0x2ac9: add    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2acc:
	/* 0x2acc: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2ace:
	/* 0x2ace: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ad0:
	/* 0x2ad0: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2ad2:
	/* 0x2ad2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad5:
	/* 0x2ad5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad7:
	/* 0x2ad7: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_2add:
	/* 0x2add: ja     2542 <vfs_writev_magic_return+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9538ULL;
	}
x86_l_2ae3:
	/* 0x2ae3: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2ae5:
	/* 0x2ae5: movzx  edi,BYTE PTR [r14+rdi*1+0x89] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 0, X86_WIDTH_8), 137ULL);
x86_l_2aee:
	/* 0x2aee: mov    BYTE PTR [rax+rdx*1+0x4],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_2af3:
	/* 0x2af3: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2af6:
	/* 0x2af6: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2af8:
	/* 0x2af8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2afb:
	/* 0x2afb: jne    2ad7 <vfs_writev_magic_return+0x2ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ad7;
	}
x86_l_2afd:
	/* 0x2afd: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_2b00:
	/* 0x2b00: jmp    2b9c <vfs_writev_magic_return+0x2b9c> */
	goto x86_l_2b9c;
x86_l_2b05:
	/* 0x2b05: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2b08:
	/* 0x2b08: jne    1c26 <vfs_writev_magic_return+0x1c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7206ULL;
	}
x86_l_2b0e:
	/* 0x2b0e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b13:
	/* 0x2b13: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2b18:
	/* 0x2b18: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b1d:
	/* 0x2b1d: je     1c2b <vfs_writev_magic_return+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7211ULL;
	}
x86_l_2b23:
	/* 0x2b23: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b27:
	/* 0x2b27: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b34:
	/* 0x2b34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b39:
	/* 0x2b39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3e:
	/* 0x2b3e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b42:
	/* 0x2b42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b47:
	/* 0x2b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b49:
	/* 0x2b49: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4e:
	/* 0x2b4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b53:
	/* 0x2b53: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b58:
	/* 0x2b58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b62:
	/* 0x2b62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b67:
	/* 0x2b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b69:
	/* 0x2b69: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6e:
	/* 0x2b6e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b73:
	/* 0x2b73: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b78:
	/* 0x2b78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b7d:
	/* 0x2b7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b82:
	/* 0x2b82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b87:
	/* 0x2b87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b89:
	/* 0x2b89: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b8e:
	/* 0x2b8e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b92:
	/* 0x2b92: jmp    2ca5 <vfs_writev_magic_return+0x2ca5> */
	return 11429ULL;
x86_l_2b97:
	/* 0x2b97: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_2b9a:
	/* 0x2b9a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b9c:
	/* 0x2b9c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2b9e:
	/* 0x2b9e: mov    BYTE PTR [rax+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_2ba3:
	/* 0x2ba3: lea    ecx,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_2baa:
	/* 0x2baa: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2bad:
	/* 0x2bad: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2baf:
	/* 0x2baf: mov    r15,QWORD PTR [r14+0x7e08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    WORD PTR [rsp+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bbb:
	/* 0x2bbb: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2bca:
	/* 0x2bca: mov    rdi,QWORD PTR [rip+0x37ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_suffix_version)));
x86_l_2bd1:
	/* 0x2bd1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bdb:
	/* 0x2bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdd:
	/* 0x2bdd: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2be4:
	/* 0x2be4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 11239ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11239ULL: goto x86_l_2be7;
	case 11241ULL: goto x86_l_2be9;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11252ULL: goto x86_l_2bf4;
	case 11254ULL: goto x86_l_2bf6;
	case 11257ULL: goto x86_l_2bf9;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11271ULL: goto x86_l_2c07;
	case 11273ULL: goto x86_l_2c09;
	case 11276ULL: goto x86_l_2c0c;
	case 11284ULL: goto x86_l_2c14;
	case 11292ULL: goto x86_l_2c1c;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11330ULL: goto x86_l_2c42;
	case 11333ULL: goto x86_l_2c45;
	case 11336ULL: goto x86_l_2c48;
	case 11339ULL: goto x86_l_2c4b;
	case 11346ULL: goto x86_l_2c52;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11365ULL: goto x86_l_2c65;
	case 11368ULL: goto x86_l_2c68;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11391ULL: goto x86_l_2c7f;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11405ULL: goto x86_l_2c8d;
	case 11411ULL: goto x86_l_2c93;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11467ULL: goto x86_l_2ccb;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11501ULL: goto x86_l_2ced;
	case 11504ULL: goto x86_l_2cf0;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11518ULL: goto x86_l_2cfe;
	case 11524ULL: goto x86_l_2d04;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11550ULL: goto x86_l_2d1e;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11588ULL: goto x86_l_2d44;
	case 11591ULL: goto x86_l_2d47;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11600ULL: goto x86_l_2d50;
	case 11603ULL: goto x86_l_2d53;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11617ULL: goto x86_l_2d61;
	case 11623ULL: goto x86_l_2d67;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11652ULL: goto x86_l_2d84;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11681ULL: goto x86_l_2da1;
	case 11683ULL: goto x86_l_2da3;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11706ULL: goto x86_l_2dba;
	case 11713ULL: goto x86_l_2dc1;
	case 11714ULL: goto x86_l_2dc2;
	case 11716ULL: goto x86_l_2dc4;
	case 11718ULL: goto x86_l_2dc6;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11731ULL: goto x86_l_2dd3;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11753ULL: goto x86_l_2de9;
	case 11757ULL: goto x86_l_2ded;
	case 11765ULL: goto x86_l_2df5;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11821ULL: goto x86_l_2e2d;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11894ULL: goto x86_l_2e76;
	case 11902ULL: goto x86_l_2e7e;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11936ULL: goto x86_l_2ea0;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11949ULL: goto x86_l_2ead;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11981ULL: goto x86_l_2ecd;
	case 11983ULL: goto x86_l_2ecf;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11996ULL: goto x86_l_2edc;
	case 12002ULL: goto x86_l_2ee2;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12025ULL: goto x86_l_2ef9;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12047ULL: goto x86_l_2f0f;
	case 12051ULL: goto x86_l_2f13;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12122ULL: goto x86_l_2f5a;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12158ULL: goto x86_l_2f7e;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12171ULL: goto x86_l_2f8b;
	case 12174ULL: goto x86_l_2f8e;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12200ULL: goto x86_l_2fa8;
	case 12206ULL: goto x86_l_2fae;
	case 12212ULL: goto x86_l_2fb4;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12265ULL: goto x86_l_2fe9;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12291ULL: goto x86_l_3003;
	case 12299ULL: goto x86_l_300b;
	case 12302ULL: goto x86_l_300e;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12342ULL: goto x86_l_3036;
	case 12344ULL: goto x86_l_3038;
	case 12348ULL: goto x86_l_303c;
	case 12350ULL: goto x86_l_303e;
	case 12356ULL: goto x86_l_3044;
	case 12361ULL: goto x86_l_3049;
	case 12363ULL: goto x86_l_304b;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12380ULL: goto x86_l_305c;
	case 12383ULL: goto x86_l_305f;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12392ULL: goto x86_l_3068;
	case 12395ULL: goto x86_l_306b;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12419ULL: goto x86_l_3083;
	case 12424ULL: goto x86_l_3088;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12440ULL: goto x86_l_3098;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12463ULL: goto x86_l_30af;
	case 12469ULL: goto x86_l_30b5;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12486ULL: goto x86_l_30c6;
	case 12490ULL: goto x86_l_30ca;
	case 12498ULL: goto x86_l_30d2;
	case 12503ULL: goto x86_l_30d7;
	case 12508ULL: goto x86_l_30dc;
	case 12513ULL: goto x86_l_30e1;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12566ULL: goto x86_l_3116;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12586ULL: goto x86_l_312a;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12597ULL: goto x86_l_3135;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12615ULL: goto x86_l_3147;
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12627ULL: goto x86_l_3153;
	case 12635ULL: goto x86_l_315b;
	case 12639ULL: goto x86_l_315f;
	case 12644ULL: goto x86_l_3164;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12661ULL: goto x86_l_3175;
	case 12669ULL: goto x86_l_317d;
	case 12672ULL: goto x86_l_3180;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12686ULL: goto x86_l_318e;
	case 12688ULL: goto x86_l_3190;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	case 12714ULL: goto x86_l_31aa;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12733ULL: goto x86_l_31bd;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12750ULL: goto x86_l_31ce;
	case 12753ULL: goto x86_l_31d1;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12762ULL: goto x86_l_31da;
	case 12765ULL: goto x86_l_31dd;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12791ULL: goto x86_l_31f7;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12814ULL: goto x86_l_320e;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12836ULL: goto x86_l_3224;
	case 12840ULL: goto x86_l_3228;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12867ULL: goto x86_l_3243;
	case 12872ULL: goto x86_l_3248;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12916ULL: goto x86_l_3274;
	case 12921ULL: goto x86_l_3279;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2be7:
	/* 0x2be7: je     2c07 <vfs_writev_magic_return+0x2c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c07;
	}
x86_l_2be9:
	/* 0x2be9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2bec:
	/* 0x2bec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bf4:
	/* 0x2bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf6:
	/* 0x2bf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf9:
	/* 0x2bf9: je     2c07 <vfs_writev_magic_return+0x2c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c07;
	}
x86_l_2bfb:
	/* 0x2bfb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bfe:
	/* 0x2bfe: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c02:
	/* 0x2c02: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2c05:
	/* 0x2c05: jmp    2c09 <vfs_writev_magic_return+0x2c09> */
	goto x86_l_2c09;
x86_l_2c07:
	/* 0x2c07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c09:
	/* 0x2c09: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2c0c:
	/* 0x2c0c: mov    rsi,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2c14:
	/* 0x2c14: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c1c:
	/* 0x2c1c: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c1f:
	/* 0x2c1f: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c22:
	/* 0x2c22: andn   rax,r15,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_2c27:
	/* 0x2c27: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c2a:
	/* 0x2c2a: andn   rax,r14,r15 */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2c2f:
	/* 0x2c2f: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c32:
	/* 0x2c32: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c35:
	/* 0x2c35: or     rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c38:
	/* 0x2c38: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c3d:
	/* 0x2c3d: andn   rax,rdi,rdx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2c42:
	/* 0x2c42: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2c45:
	/* 0x2c45: or     rbx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c48:
	/* 0x2c48: or     rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c4b:
	/* 0x2c4b: and    rbx,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2c52:
	/* 0x2c52: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2c55:
	/* 0x2c55: jmp    2542 <vfs_writev_magic_return+0x2542> */
	return 9538ULL;
x86_l_2c5a:
	/* 0x2c5a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c5f:
	/* 0x2c5f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c65:
	/* 0x2c65: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c68:
	/* 0x2c68: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2c6a:
	/* 0x2c6a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c6f:
	/* 0x2c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c71:
	/* 0x2c71: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c74:
	/* 0x2c74: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c79:
	/* 0x2c79: jl     1c2b <vfs_writev_magic_return+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7211ULL;
	}
x86_l_2c7f:
	/* 0x2c7f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c84:
	/* 0x2c84: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c87:
	/* 0x2c87: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c93:
	/* 0x2c93: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c95:
	/* 0x2c95: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ca2:
	/* 0x2ca2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2ca5:
	/* 0x2ca5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2caa:
	/* 0x2caa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2caf:
	/* 0x2caf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_2cbc:
	/* 0x2cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbe:
	/* 0x2cbe: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ccb:
	/* 0x2ccb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ccf:
	/* 0x2ccf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cd4:
	/* 0x2cd4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cde:
	/* 0x2cde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ce3:
	/* 0x2ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce5:
	/* 0x2ce5: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ced:
	/* 0x2ced: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2cf0:
	/* 0x2cf0: je     2dd0 <vfs_writev_magic_return+0x2dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd0;
	}
x86_l_2cf6:
	/* 0x2cf6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cfb:
	/* 0x2cfb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cfe:
	/* 0x2cfe: je     2dd0 <vfs_writev_magic_return+0x2dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd0;
	}
x86_l_2d04:
	/* 0x2d04: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d08:
	/* 0x2d08: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d12:
	/* 0x2d12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d17:
	/* 0x2d17: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d1c:
	/* 0x2d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1e:
	/* 0x2d1e: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2d22:
	/* 0x2d22: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d24:
	/* 0x2d24: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d2a:
	/* 0x2d2a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2f:
	/* 0x2d2f: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2d31:
	/* 0x2d31: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d33:
	/* 0x2d33: jb     1dbc <vfs_writev_magic_return+0x1dbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7612ULL;
	}
x86_l_2d39:
	/* 0x2d39: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d3e:
	/* 0x2d3e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d44:
	/* 0x2d44: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d47:
	/* 0x2d47: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2d49:
	/* 0x2d49: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d4e:
	/* 0x2d4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d50:
	/* 0x2d50: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d53:
	/* 0x2d53: jl     1c26 <vfs_writev_magic_return+0x1c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7206ULL;
	}
x86_l_2d59:
	/* 0x2d59: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5e:
	/* 0x2d5e: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d61:
	/* 0x2d61: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d67:
	/* 0x2d67: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d6d:
	/* 0x2d6d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d6f:
	/* 0x2d6f: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d74:
	/* 0x2d74: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2d7f:
	/* 0x2d7f: jmp    2e58 <vfs_writev_magic_return+0x2e58> */
	goto x86_l_2e58;
x86_l_2d84:
	/* 0x2d84: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2d8b:
	/* 0x2d8b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d8e:
	/* 0x2d8e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d92:
	/* 0x2d92: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2d97:
	/* 0x2d97: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2da1:
	/* 0x2da1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da3:
	/* 0x2da3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2da6:
	/* 0x2da6: jne    2db8 <vfs_writev_magic_return+0x2db8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2db8;
	}
x86_l_2da8:
	/* 0x2da8: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2dae:
	/* 0x2dae: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2db3:
	/* 0x2db3: jmp    d52 <vfs_writev_magic_return+0xd52> */
	return 3410ULL;
x86_l_2db8:
	/* 0x2db8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dba:
	/* 0x2dba: add    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 328ULL);
x86_l_2dc1:
	/* 0x2dc1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2dc2:
	/* 0x2dc2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2dc4:
	/* 0x2dc4: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2dc6:
	/* 0x2dc6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2dc8:
	/* 0x2dc8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2dca:
	/* 0x2dca: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2dcb:
	/* 0x2dcb: jmp    446a <vfs_writev_magic_return+0x446a> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2dd0:
	/* 0x2dd0: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2dd3:
	/* 0x2dd3: jne    1c26 <vfs_writev_magic_return+0x1c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7206ULL;
	}
x86_l_2dd9:
	/* 0x2dd9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dde:
	/* 0x2dde: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2de3:
	/* 0x2de3: je     1c26 <vfs_writev_magic_return+0x1c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7206ULL;
	}
x86_l_2de9:
	/* 0x2de9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ded:
	/* 0x2ded: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2df5:
	/* 0x2df5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dff:
	/* 0x2dff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e04:
	/* 0x2e04: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e08:
	/* 0x2e08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e0d:
	/* 0x2e0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0f:
	/* 0x2e0f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e14:
	/* 0x2e14: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e19:
	/* 0x2e19: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e1e:
	/* 0x2e1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e23:
	/* 0x2e23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e28:
	/* 0x2e28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e2d:
	/* 0x2e2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2f:
	/* 0x2e2f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e34:
	/* 0x2e34: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e39:
	/* 0x2e39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e43:
	/* 0x2e43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e48:
	/* 0x2e48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e4d:
	/* 0x2e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4f:
	/* 0x2e4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e54:
	/* 0x2e54: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e58:
	/* 0x2e58: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e62:
	/* 0x2e62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e67:
	/* 0x2e67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_2e6f:
	/* 0x2e6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e71:
	/* 0x2e71: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e76:
	/* 0x2e76: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e7e:
	/* 0x2e7e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e82:
	/* 0x2e82: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e87:
	/* 0x2e87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e91:
	/* 0x2e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e96:
	/* 0x2e96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e98:
	/* 0x2e98: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ea0:
	/* 0x2ea0: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2ea3:
	/* 0x2ea3: je     2ef6 <vfs_writev_magic_return+0x2ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef6;
	}
x86_l_2ea5:
	/* 0x2ea5: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eaa:
	/* 0x2eaa: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ead:
	/* 0x2ead: je     2ef6 <vfs_writev_magic_return+0x2ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef6;
	}
x86_l_2eaf:
	/* 0x2eaf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2eb3:
	/* 0x2eb3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ec7:
	/* 0x2ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec9:
	/* 0x2ec9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ecd:
	/* 0x2ecd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ecf:
	/* 0x2ecf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eda:
	/* 0x2eda: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2edc:
	/* 0x2edc: jae    2f80 <vfs_writev_magic_return+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f80;
	}
x86_l_2ee2:
	/* 0x2ee2: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ee7:
	/* 0x2ee7: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eec:
	/* 0x2eec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef1:
	/* 0x2ef1: jmp    1dc1 <vfs_writev_magic_return+0x1dc1> */
	return 7617ULL;
x86_l_2ef6:
	/* 0x2ef6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2ef9:
	/* 0x2ef9: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_309a;
	}
x86_l_2eff:
	/* 0x2eff: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f04:
	/* 0x2f04: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2f09:
	/* 0x2f09: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_309a;
	}
x86_l_2f0f:
	/* 0x2f0f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f13:
	/* 0x2f13: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f1b:
	/* 0x2f1b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f20:
	/* 0x2f20: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f25:
	/* 0x2f25: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f2a:
	/* 0x2f2a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f33:
	/* 0x2f33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f35:
	/* 0x2f35: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3a:
	/* 0x2f3a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f44:
	/* 0x2f44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f49:
	/* 0x2f49: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f53:
	/* 0x2f53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f55:
	/* 0x2f55: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f5a:
	/* 0x2f5a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f64:
	/* 0x2f64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f69:
	/* 0x2f69: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f73:
	/* 0x2f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f75:
	/* 0x2f75: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7a:
	/* 0x2f7a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f7e:
	/* 0x2f7e: jmp    2fc3 <vfs_writev_magic_return+0x2fc3> */
	goto x86_l_2fc3;
x86_l_2f80:
	/* 0x2f80: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f85:
	/* 0x2f85: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f8b:
	/* 0x2f8b: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f8e:
	/* 0x2f8e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2f90:
	/* 0x2f90: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f95:
	/* 0x2f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f97:
	/* 0x2f97: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f9a:
	/* 0x2f9a: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_309a;
	}
x86_l_2fa0:
	/* 0x2fa0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa5:
	/* 0x2fa5: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2fa8:
	/* 0x2fa8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2fae:
	/* 0x2fae: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2fb4:
	/* 0x2fb4: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fb6:
	/* 0x2fb6: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fbb:
	/* 0x2fbb: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2fc3:
	/* 0x2fc3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fcd:
	/* 0x2fcd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2fd5:
	/* 0x2fd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fda:
	/* 0x2fda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdc:
	/* 0x2fdc: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fe1:
	/* 0x2fe1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2fe9:
	/* 0x2fe9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fed:
	/* 0x2fed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ffc:
	/* 0x2ffc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3001:
	/* 0x3001: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3003:
	/* 0x3003: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_300b:
	/* 0x300b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_300e:
	/* 0x300e: je     3095 <vfs_writev_magic_return+0x3095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3095;
	}
x86_l_3014:
	/* 0x3014: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3019:
	/* 0x3019: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_301c:
	/* 0x301c: je     3095 <vfs_writev_magic_return+0x3095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3095;
	}
x86_l_301e:
	/* 0x301e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3022:
	/* 0x3022: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3027:
	/* 0x3027: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_302c:
	/* 0x302c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3031:
	/* 0x3031: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3036:
	/* 0x3036: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3038:
	/* 0x3038: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_303c:
	/* 0x303c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_303e:
	/* 0x303e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3044:
	/* 0x3044: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3049:
	/* 0x3049: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_304b:
	/* 0x304b: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ee2;
	}
x86_l_3051:
	/* 0x3051: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3056:
	/* 0x3056: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_305c:
	/* 0x305c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_305f:
	/* 0x305f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3061:
	/* 0x3061: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3066:
	/* 0x3066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3068:
	/* 0x3068: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_306b:
	/* 0x306b: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_309a;
	}
x86_l_306d:
	/* 0x306d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3072:
	/* 0x3072: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3075:
	/* 0x3075: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_307b:
	/* 0x307b: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3081:
	/* 0x3081: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3083:
	/* 0x3083: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3088:
	/* 0x3088: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3090:
	/* 0x3090: jmp    3135 <vfs_writev_magic_return+0x3135> */
	goto x86_l_3135;
x86_l_3095:
	/* 0x3095: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3098:
	/* 0x3098: je     30ba <vfs_writev_magic_return+0x30ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ba;
	}
x86_l_309a:
	/* 0x309a: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_309f:
	/* 0x309f: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30a4:
	/* 0x30a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a9:
	/* 0x30a9: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_30af:
	/* 0x30af: je     1c3c <vfs_writev_magic_return+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7228ULL;
	}
x86_l_30b5:
	/* 0x30b5: jmp    1dc1 <vfs_writev_magic_return+0x1dc1> */
	return 7617ULL;
x86_l_30ba:
	/* 0x30ba: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30bf:
	/* 0x30bf: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_30c4:
	/* 0x30c4: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_309a;
	}
x86_l_30c6:
	/* 0x30c6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30ca:
	/* 0x30ca: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30d2:
	/* 0x30d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30d7:
	/* 0x30d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30dc:
	/* 0x30dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e1:
	/* 0x30e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30e5:
	/* 0x30e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ea:
	/* 0x30ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ec:
	/* 0x30ec: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f1:
	/* 0x30f1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f6:
	/* 0x30f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30fb:
	/* 0x30fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3100:
	/* 0x3100: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3105:
	/* 0x3105: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_310a:
	/* 0x310a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310c:
	/* 0x310c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3111:
	/* 0x3111: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3116:
	/* 0x3116: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_311b:
	/* 0x311b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3120:
	/* 0x3120: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3125:
	/* 0x3125: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_312a:
	/* 0x312a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312c:
	/* 0x312c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3131:
	/* 0x3131: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3135:
	/* 0x3135: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_313a:
	/* 0x313a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_313f:
	/* 0x313f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3144:
	/* 0x3144: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3147:
	/* 0x3147: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314c:
	/* 0x314c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314e:
	/* 0x314e: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3153:
	/* 0x3153: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_315b:
	/* 0x315b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_315f:
	/* 0x315f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3164:
	/* 0x3164: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3169:
	/* 0x3169: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_316e:
	/* 0x316e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3173:
	/* 0x3173: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3175:
	/* 0x3175: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_317d:
	/* 0x317d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3180:
	/* 0x3180: je     320b <vfs_writev_magic_return+0x320b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_320b;
	}
x86_l_3186:
	/* 0x3186: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_318b:
	/* 0x318b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_318e:
	/* 0x318e: je     320b <vfs_writev_magic_return+0x320b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_320b;
	}
x86_l_3190:
	/* 0x3190: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3194:
	/* 0x3194: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3199:
	/* 0x3199: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_319e:
	/* 0x319e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a3:
	/* 0x31a3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31a8:
	/* 0x31a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31aa:
	/* 0x31aa: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_31ae:
	/* 0x31ae: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31b0:
	/* 0x31b0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31b6:
	/* 0x31b6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31bb:
	/* 0x31bb: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31bd:
	/* 0x31bd: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ee2;
	}
x86_l_31c3:
	/* 0x31c3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_31c8:
	/* 0x31c8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_31ce:
	/* 0x31ce: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31d1:
	/* 0x31d1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_31d3:
	/* 0x31d3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_31d8:
	/* 0x31d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31da:
	/* 0x31da: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31dd:
	/* 0x31dd: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_309a;
	}
x86_l_31e3:
	/* 0x31e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e8:
	/* 0x31e8: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_31eb:
	/* 0x31eb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_31f1:
	/* 0x31f1: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_31f7:
	/* 0x31f7: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31f9:
	/* 0x31f9: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31fe:
	/* 0x31fe: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3206:
	/* 0x3206: jmp    3293 <vfs_writev_magic_return+0x3293> */
	return 12947ULL;
x86_l_320b:
	/* 0x320b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_320e:
	/* 0x320e: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_309a;
	}
x86_l_3214:
	/* 0x3214: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3219:
	/* 0x3219: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_321e:
	/* 0x321e: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_309a;
	}
x86_l_3224:
	/* 0x3224: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3228:
	/* 0x3228: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3230:
	/* 0x3230: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3235:
	/* 0x3235: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_323a:
	/* 0x323a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_323f:
	/* 0x323f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3243:
	/* 0x3243: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3248:
	/* 0x3248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324a:
	/* 0x324a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_324f:
	/* 0x324f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3254:
	/* 0x3254: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3259:
	/* 0x3259: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_325e:
	/* 0x325e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3263:
	/* 0x3263: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3268:
	/* 0x3268: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326a:
	/* 0x326a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_326f:
	/* 0x326f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3274:
	/* 0x3274: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3279:
	/* 0x3279: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 12926ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12926ULL: goto x86_l_327e;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12962ULL: goto x86_l_32a2;
	case 12965ULL: goto x86_l_32a5;
	case 12970ULL: goto x86_l_32aa;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12985ULL: goto x86_l_32b9;
	case 12989ULL: goto x86_l_32bd;
	case 12994ULL: goto x86_l_32c2;
	case 12999ULL: goto x86_l_32c7;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13011ULL: goto x86_l_32d3;
	case 13019ULL: goto x86_l_32db;
	case 13022ULL: goto x86_l_32de;
	case 13028ULL: goto x86_l_32e4;
	case 13033ULL: goto x86_l_32e9;
	case 13036ULL: goto x86_l_32ec;
	case 13038ULL: goto x86_l_32ee;
	case 13042ULL: goto x86_l_32f2;
	case 13047ULL: goto x86_l_32f7;
	case 13052ULL: goto x86_l_32fc;
	case 13057ULL: goto x86_l_3301;
	case 13062ULL: goto x86_l_3306;
	case 13064ULL: goto x86_l_3308;
	case 13068ULL: goto x86_l_330c;
	case 13070ULL: goto x86_l_330e;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13083ULL: goto x86_l_331b;
	case 13089ULL: goto x86_l_3321;
	case 13094ULL: goto x86_l_3326;
	case 13100ULL: goto x86_l_332c;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13112ULL: goto x86_l_3338;
	case 13115ULL: goto x86_l_333b;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13129ULL: goto x86_l_3349;
	case 13135ULL: goto x86_l_334f;
	case 13141ULL: goto x86_l_3355;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13156ULL: goto x86_l_3364;
	case 13161ULL: goto x86_l_3369;
	case 13164ULL: goto x86_l_336c;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13180ULL: goto x86_l_337c;
	case 13186ULL: goto x86_l_3382;
	case 13190ULL: goto x86_l_3386;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13217ULL: goto x86_l_33a1;
	case 13222ULL: goto x86_l_33a6;
	case 13224ULL: goto x86_l_33a8;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13239ULL: goto x86_l_33b7;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13286ULL: goto x86_l_33e6;
	case 13288ULL: goto x86_l_33e8;
	case 13293ULL: goto x86_l_33ed;
	case 13297ULL: goto x86_l_33f1;
	case 13302ULL: goto x86_l_33f6;
	case 13307ULL: goto x86_l_33fb;
	case 13312ULL: goto x86_l_3400;
	case 13315ULL: goto x86_l_3403;
	case 13320ULL: goto x86_l_3408;
	case 13322ULL: goto x86_l_340a;
	case 13327ULL: goto x86_l_340f;
	case 13335ULL: goto x86_l_3417;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13349ULL: goto x86_l_3425;
	case 13354ULL: goto x86_l_342a;
	case 13359ULL: goto x86_l_342f;
	case 13361ULL: goto x86_l_3431;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13383ULL: goto x86_l_3447;
	case 13386ULL: goto x86_l_344a;
	case 13388ULL: goto x86_l_344c;
	case 13392ULL: goto x86_l_3450;
	case 13397ULL: goto x86_l_3455;
	case 13402ULL: goto x86_l_345a;
	case 13407ULL: goto x86_l_345f;
	case 13412ULL: goto x86_l_3464;
	case 13414ULL: goto x86_l_3466;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13426ULL: goto x86_l_3472;
	case 13431ULL: goto x86_l_3477;
	case 13433ULL: goto x86_l_3479;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13450ULL: goto x86_l_348a;
	case 13453ULL: goto x86_l_348d;
	case 13455ULL: goto x86_l_348f;
	case 13460ULL: goto x86_l_3494;
	case 13462ULL: goto x86_l_3496;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13476ULL: goto x86_l_34a4;
	case 13479ULL: goto x86_l_34a7;
	case 13485ULL: goto x86_l_34ad;
	case 13491ULL: goto x86_l_34b3;
	case 13493ULL: goto x86_l_34b5;
	case 13498ULL: goto x86_l_34ba;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13530ULL: goto x86_l_34da;
	case 13536ULL: goto x86_l_34e0;
	case 13540ULL: goto x86_l_34e4;
	case 13548ULL: goto x86_l_34ec;
	case 13553ULL: goto x86_l_34f1;
	case 13558ULL: goto x86_l_34f6;
	case 13563ULL: goto x86_l_34fb;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13599ULL: goto x86_l_351f;
	case 13604ULL: goto x86_l_3524;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13647ULL: goto x86_l_354f;
	case 13652ULL: goto x86_l_3554;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13685ULL: goto x86_l_3575;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13699ULL: goto x86_l_3583;
	case 13704ULL: goto x86_l_3588;
	case 13709ULL: goto x86_l_358d;
	case 13711ULL: goto x86_l_358f;
	case 13719ULL: goto x86_l_3597;
	case 13722ULL: goto x86_l_359a;
	case 13728ULL: goto x86_l_35a0;
	case 13733ULL: goto x86_l_35a5;
	case 13736ULL: goto x86_l_35a8;
	case 13738ULL: goto x86_l_35aa;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13764ULL: goto x86_l_35c4;
	case 13768ULL: goto x86_l_35c8;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13783ULL: goto x86_l_35d7;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13800ULL: goto x86_l_35e8;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13812ULL: goto x86_l_35f4;
	case 13815ULL: goto x86_l_35f7;
	case 13821ULL: goto x86_l_35fd;
	case 13826ULL: goto x86_l_3602;
	case 13829ULL: goto x86_l_3605;
	case 13835ULL: goto x86_l_360b;
	case 13841ULL: goto x86_l_3611;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13856ULL: goto x86_l_3620;
	case 13861ULL: goto x86_l_3625;
	case 13864ULL: goto x86_l_3628;
	case 13870ULL: goto x86_l_362e;
	case 13875ULL: goto x86_l_3633;
	case 13880ULL: goto x86_l_3638;
	case 13886ULL: goto x86_l_363e;
	case 13890ULL: goto x86_l_3642;
	case 13898ULL: goto x86_l_364a;
	case 13903ULL: goto x86_l_364f;
	case 13908ULL: goto x86_l_3654;
	case 13913ULL: goto x86_l_3659;
	case 13917ULL: goto x86_l_365d;
	case 13922ULL: goto x86_l_3662;
	case 13924ULL: goto x86_l_3664;
	case 13929ULL: goto x86_l_3669;
	case 13934ULL: goto x86_l_366e;
	case 13939ULL: goto x86_l_3673;
	case 13944ULL: goto x86_l_3678;
	case 13949ULL: goto x86_l_367d;
	case 13954ULL: goto x86_l_3682;
	case 13956ULL: goto x86_l_3684;
	case 13961ULL: goto x86_l_3689;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13976ULL: goto x86_l_3698;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 13997ULL: goto x86_l_36ad;
	case 14002ULL: goto x86_l_36b2;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14022ULL: goto x86_l_36c6;
	case 14027ULL: goto x86_l_36cb;
	case 14035ULL: goto x86_l_36d3;
	case 14039ULL: goto x86_l_36d7;
	case 14044ULL: goto x86_l_36dc;
	case 14049ULL: goto x86_l_36e1;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14061ULL: goto x86_l_36ed;
	case 14069ULL: goto x86_l_36f5;
	case 14072ULL: goto x86_l_36f8;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14086ULL: goto x86_l_3706;
	case 14088ULL: goto x86_l_3708;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14112ULL: goto x86_l_3720;
	case 14114ULL: goto x86_l_3722;
	case 14118ULL: goto x86_l_3726;
	case 14120ULL: goto x86_l_3728;
	case 14126ULL: goto x86_l_372e;
	case 14131ULL: goto x86_l_3733;
	case 14133ULL: goto x86_l_3735;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14150ULL: goto x86_l_3746;
	case 14153ULL: goto x86_l_3749;
	case 14155ULL: goto x86_l_374b;
	case 14160ULL: goto x86_l_3750;
	case 14162ULL: goto x86_l_3752;
	case 14165ULL: goto x86_l_3755;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14179ULL: goto x86_l_3763;
	case 14185ULL: goto x86_l_3769;
	case 14191ULL: goto x86_l_376f;
	case 14193ULL: goto x86_l_3771;
	case 14198ULL: goto x86_l_3776;
	case 14206ULL: goto x86_l_377e;
	case 14211ULL: goto x86_l_3783;
	case 14214ULL: goto x86_l_3786;
	case 14220ULL: goto x86_l_378c;
	case 14225ULL: goto x86_l_3791;
	case 14230ULL: goto x86_l_3796;
	case 14236ULL: goto x86_l_379c;
	case 14240ULL: goto x86_l_37a0;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14258ULL: goto x86_l_37b2;
	case 14263ULL: goto x86_l_37b7;
	case 14267ULL: goto x86_l_37bb;
	case 14272ULL: goto x86_l_37c0;
	case 14274ULL: goto x86_l_37c2;
	case 14279ULL: goto x86_l_37c7;
	case 14284ULL: goto x86_l_37cc;
	case 14289ULL: goto x86_l_37d1;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14306ULL: goto x86_l_37e2;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14338ULL: goto x86_l_3802;
	case 14343ULL: goto x86_l_3807;
	case 14347ULL: goto x86_l_380b;
	case 14352ULL: goto x86_l_3810;
	case 14357ULL: goto x86_l_3815;
	case 14362ULL: goto x86_l_381a;
	case 14365ULL: goto x86_l_381d;
	case 14370ULL: goto x86_l_3822;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14385ULL: goto x86_l_3831;
	case 14389ULL: goto x86_l_3835;
	case 14394ULL: goto x86_l_383a;
	case 14399ULL: goto x86_l_383f;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14411ULL: goto x86_l_384b;
	case 14419ULL: goto x86_l_3853;
	case 14422ULL: goto x86_l_3856;
	case 14428ULL: goto x86_l_385c;
	case 14433ULL: goto x86_l_3861;
	case 14436ULL: goto x86_l_3864;
	case 14438ULL: goto x86_l_3866;
	case 14442ULL: goto x86_l_386a;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14462ULL: goto x86_l_387e;
	case 14464ULL: goto x86_l_3880;
	case 14468ULL: goto x86_l_3884;
	case 14470ULL: goto x86_l_3886;
	case 14476ULL: goto x86_l_388c;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14500ULL: goto x86_l_38a4;
	case 14503ULL: goto x86_l_38a7;
	case 14505ULL: goto x86_l_38a9;
	case 14510ULL: goto x86_l_38ae;
	case 14512ULL: goto x86_l_38b0;
	case 14515ULL: goto x86_l_38b3;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14529ULL: goto x86_l_38c1;
	case 14535ULL: goto x86_l_38c7;
	case 14541ULL: goto x86_l_38cd;
	case 14543ULL: goto x86_l_38cf;
	case 14548ULL: goto x86_l_38d4;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14564ULL: goto x86_l_38e4;
	case 14570ULL: goto x86_l_38ea;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14586ULL: goto x86_l_38fa;
	case 14590ULL: goto x86_l_38fe;
	case 14598ULL: goto x86_l_3906;
	case 14603ULL: goto x86_l_390b;
	case 14608ULL: goto x86_l_3910;
	case 14613ULL: goto x86_l_3915;
	case 14617ULL: goto x86_l_3919;
	case 14622ULL: goto x86_l_391e;
	case 14624ULL: goto x86_l_3920;
	case 14629ULL: goto x86_l_3925;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14644ULL: goto x86_l_3934;
	case 14649ULL: goto x86_l_3939;
	case 14654ULL: goto x86_l_393e;
	case 14656ULL: goto x86_l_3940;
	case 14661ULL: goto x86_l_3945;
	case 14666ULL: goto x86_l_394a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_327e:
	/* 0x327e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3283:
	/* 0x3283: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3288:
	/* 0x3288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328a:
	/* 0x328a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_328f:
	/* 0x328f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3293:
	/* 0x3293: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3298:
	/* 0x3298: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_329d:
	/* 0x329d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32a2:
	/* 0x32a2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_32a5:
	/* 0x32a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32aa:
	/* 0x32aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ac:
	/* 0x32ac: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32b1:
	/* 0x32b1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_32b9:
	/* 0x32b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32bd:
	/* 0x32bd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32c2:
	/* 0x32c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32c7:
	/* 0x32c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32cc:
	/* 0x32cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32d1:
	/* 0x32d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d3:
	/* 0x32d3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_32db:
	/* 0x32db: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_32de:
	/* 0x32de: je     3369 <vfs_writev_magic_return+0x3369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3369;
	}
x86_l_32e4:
	/* 0x32e4: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32e9:
	/* 0x32e9: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32ec:
	/* 0x32ec: je     3369 <vfs_writev_magic_return+0x3369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3369;
	}
x86_l_32ee:
	/* 0x32ee: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32f2:
	/* 0x32f2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32f7:
	/* 0x32f7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32fc:
	/* 0x32fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3301:
	/* 0x3301: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3306:
	/* 0x3306: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3308:
	/* 0x3308: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_330c:
	/* 0x330c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_330e:
	/* 0x330e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3314:
	/* 0x3314: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3319:
	/* 0x3319: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_331b:
	/* 0x331b: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3321:
	/* 0x3321: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3326:
	/* 0x3326: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_332c:
	/* 0x332c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_332f:
	/* 0x332f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3331:
	/* 0x3331: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3336:
	/* 0x3336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3338:
	/* 0x3338: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_333b:
	/* 0x333b: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3341:
	/* 0x3341: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3346:
	/* 0x3346: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3349:
	/* 0x3349: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_334f:
	/* 0x334f: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3355:
	/* 0x3355: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3357:
	/* 0x3357: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_335c:
	/* 0x335c: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3364:
	/* 0x3364: jmp    33f1 <vfs_writev_magic_return+0x33f1> */
	goto x86_l_33f1;
x86_l_3369:
	/* 0x3369: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_336c:
	/* 0x336c: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3372:
	/* 0x3372: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3377:
	/* 0x3377: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_337c:
	/* 0x337c: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3382:
	/* 0x3382: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3386:
	/* 0x3386: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_338e:
	/* 0x338e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3393:
	/* 0x3393: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3398:
	/* 0x3398: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_339d:
	/* 0x339d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33a1:
	/* 0x33a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33a6:
	/* 0x33a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a8:
	/* 0x33a8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33ad:
	/* 0x33ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33b2:
	/* 0x33b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33b7:
	/* 0x33b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33bc:
	/* 0x33bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c1:
	/* 0x33c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c6:
	/* 0x33c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c8:
	/* 0x33c8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33cd:
	/* 0x33cd: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33d2:
	/* 0x33d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33d7:
	/* 0x33d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33dc:
	/* 0x33dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33e1:
	/* 0x33e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e6:
	/* 0x33e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e8:
	/* 0x33e8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33ed:
	/* 0x33ed: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33f1:
	/* 0x33f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33f6:
	/* 0x33f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33fb:
	/* 0x33fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3400:
	/* 0x3400: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3403:
	/* 0x3403: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3408:
	/* 0x3408: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340a:
	/* 0x340a: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_340f:
	/* 0x340f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3417:
	/* 0x3417: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_341b:
	/* 0x341b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3420:
	/* 0x3420: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3425:
	/* 0x3425: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_342a:
	/* 0x342a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_342f:
	/* 0x342f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3431:
	/* 0x3431: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3439:
	/* 0x3439: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_343c:
	/* 0x343c: je     34c7 <vfs_writev_magic_return+0x34c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34c7;
	}
x86_l_3442:
	/* 0x3442: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3447:
	/* 0x3447: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_344a:
	/* 0x344a: je     34c7 <vfs_writev_magic_return+0x34c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34c7;
	}
x86_l_344c:
	/* 0x344c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3450:
	/* 0x3450: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3455:
	/* 0x3455: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_345a:
	/* 0x345a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_345f:
	/* 0x345f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3464:
	/* 0x3464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3466:
	/* 0x3466: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_346a:
	/* 0x346a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_346c:
	/* 0x346c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3472:
	/* 0x3472: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3477:
	/* 0x3477: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3479:
	/* 0x3479: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_347f:
	/* 0x347f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3484:
	/* 0x3484: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_348a:
	/* 0x348a: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_348d:
	/* 0x348d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_348f:
	/* 0x348f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3494:
	/* 0x3494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3496:
	/* 0x3496: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3499:
	/* 0x3499: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_349f:
	/* 0x349f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a4:
	/* 0x34a4: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_34a7:
	/* 0x34a7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34ad:
	/* 0x34ad: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34b3:
	/* 0x34b3: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34b5:
	/* 0x34b5: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ba:
	/* 0x34ba: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_34c2:
	/* 0x34c2: jmp    354f <vfs_writev_magic_return+0x354f> */
	goto x86_l_354f;
x86_l_34c7:
	/* 0x34c7: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_34ca:
	/* 0x34ca: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_34d0:
	/* 0x34d0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d5:
	/* 0x34d5: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_34da:
	/* 0x34da: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_34e0:
	/* 0x34e0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34e4:
	/* 0x34e4: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_34ec:
	/* 0x34ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34f1:
	/* 0x34f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34f6:
	/* 0x34f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34fb:
	/* 0x34fb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34ff:
	/* 0x34ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3504:
	/* 0x3504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3506:
	/* 0x3506: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350b:
	/* 0x350b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3510:
	/* 0x3510: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3515:
	/* 0x3515: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_351a:
	/* 0x351a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_351f:
	/* 0x351f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3524:
	/* 0x3524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3526:
	/* 0x3526: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_352b:
	/* 0x352b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3530:
	/* 0x3530: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3535:
	/* 0x3535: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_353a:
	/* 0x353a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_353f:
	/* 0x353f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3544:
	/* 0x3544: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3546:
	/* 0x3546: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_354b:
	/* 0x354b: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_354f:
	/* 0x354f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3554:
	/* 0x3554: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3559:
	/* 0x3559: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_355e:
	/* 0x355e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3561:
	/* 0x3561: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3566:
	/* 0x3566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3568:
	/* 0x3568: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_356d:
	/* 0x356d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3575:
	/* 0x3575: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3579:
	/* 0x3579: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_357e:
	/* 0x357e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3583:
	/* 0x3583: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3588:
	/* 0x3588: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_358d:
	/* 0x358d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358f:
	/* 0x358f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3597:
	/* 0x3597: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_359a:
	/* 0x359a: je     3625 <vfs_writev_magic_return+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3625;
	}
x86_l_35a0:
	/* 0x35a0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35a5:
	/* 0x35a5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35a8:
	/* 0x35a8: je     3625 <vfs_writev_magic_return+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3625;
	}
x86_l_35aa:
	/* 0x35aa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35ae:
	/* 0x35ae: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35b3:
	/* 0x35b3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_35b8:
	/* 0x35b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35bd:
	/* 0x35bd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_35c2:
	/* 0x35c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c4:
	/* 0x35c4: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_35c8:
	/* 0x35c8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35ca:
	/* 0x35ca: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35d0:
	/* 0x35d0: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d5:
	/* 0x35d5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35d7:
	/* 0x35d7: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_35dd:
	/* 0x35dd: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35e2:
	/* 0x35e2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_35e8:
	/* 0x35e8: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35eb:
	/* 0x35eb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_35ed:
	/* 0x35ed: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_35f2:
	/* 0x35f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f4:
	/* 0x35f4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35f7:
	/* 0x35f7: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_35fd:
	/* 0x35fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3602:
	/* 0x3602: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3605:
	/* 0x3605: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_360b:
	/* 0x360b: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3611:
	/* 0x3611: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3613:
	/* 0x3613: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3618:
	/* 0x3618: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3620:
	/* 0x3620: jmp    36ad <vfs_writev_magic_return+0x36ad> */
	goto x86_l_36ad;
x86_l_3625:
	/* 0x3625: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3628:
	/* 0x3628: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_362e:
	/* 0x362e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3633:
	/* 0x3633: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3638:
	/* 0x3638: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_363e:
	/* 0x363e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3642:
	/* 0x3642: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_364a:
	/* 0x364a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_364f:
	/* 0x364f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3654:
	/* 0x3654: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3659:
	/* 0x3659: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_365d:
	/* 0x365d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3662:
	/* 0x3662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3664:
	/* 0x3664: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3669:
	/* 0x3669: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366e:
	/* 0x366e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3673:
	/* 0x3673: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3678:
	/* 0x3678: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_367d:
	/* 0x367d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3682:
	/* 0x3682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3684:
	/* 0x3684: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3689:
	/* 0x3689: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_368e:
	/* 0x368e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3693:
	/* 0x3693: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3698:
	/* 0x3698: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_369d:
	/* 0x369d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36a2:
	/* 0x36a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a4:
	/* 0x36a4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a9:
	/* 0x36a9: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36ad:
	/* 0x36ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36b2:
	/* 0x36b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36b7:
	/* 0x36b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36bc:
	/* 0x36bc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_36bf:
	/* 0x36bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36c4:
	/* 0x36c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c6:
	/* 0x36c6: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36cb:
	/* 0x36cb: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_36d3:
	/* 0x36d3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_36d7:
	/* 0x36d7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36dc:
	/* 0x36dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36e1:
	/* 0x36e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36e6:
	/* 0x36e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36eb:
	/* 0x36eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ed:
	/* 0x36ed: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_36f5:
	/* 0x36f5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_36f8:
	/* 0x36f8: je     3783 <vfs_writev_magic_return+0x3783> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3783;
	}
x86_l_36fe:
	/* 0x36fe: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3703:
	/* 0x3703: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3706:
	/* 0x3706: je     3783 <vfs_writev_magic_return+0x3783> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3783;
	}
x86_l_3708:
	/* 0x3708: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_370c:
	/* 0x370c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3711:
	/* 0x3711: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3716:
	/* 0x3716: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_371b:
	/* 0x371b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3720:
	/* 0x3720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3722:
	/* 0x3722: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3726:
	/* 0x3726: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3728:
	/* 0x3728: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_372e:
	/* 0x372e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3733:
	/* 0x3733: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3735:
	/* 0x3735: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_373b:
	/* 0x373b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3740:
	/* 0x3740: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3746:
	/* 0x3746: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3749:
	/* 0x3749: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_374b:
	/* 0x374b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3750:
	/* 0x3750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3752:
	/* 0x3752: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3755:
	/* 0x3755: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_375b:
	/* 0x375b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3760:
	/* 0x3760: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3763:
	/* 0x3763: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3769:
	/* 0x3769: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_376f:
	/* 0x376f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3771:
	/* 0x3771: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3776:
	/* 0x3776: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_377e:
	/* 0x377e: jmp    380b <vfs_writev_magic_return+0x380b> */
	goto x86_l_380b;
x86_l_3783:
	/* 0x3783: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3786:
	/* 0x3786: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_378c:
	/* 0x378c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3791:
	/* 0x3791: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3796:
	/* 0x3796: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_379c:
	/* 0x379c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37a0:
	/* 0x37a0: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_37a8:
	/* 0x37a8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37ad:
	/* 0x37ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37b2:
	/* 0x37b2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37b7:
	/* 0x37b7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37bb:
	/* 0x37bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37c0:
	/* 0x37c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37c2:
	/* 0x37c2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c7:
	/* 0x37c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37cc:
	/* 0x37cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37d1:
	/* 0x37d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37d6:
	/* 0x37d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37db:
	/* 0x37db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37e0:
	/* 0x37e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e2:
	/* 0x37e2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37e7:
	/* 0x37e7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37ec:
	/* 0x37ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37f1:
	/* 0x37f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37f6:
	/* 0x37f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37fb:
	/* 0x37fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3800:
	/* 0x3800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3802:
	/* 0x3802: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3807:
	/* 0x3807: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_380b:
	/* 0x380b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3810:
	/* 0x3810: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3815:
	/* 0x3815: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_381a:
	/* 0x381a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_381d:
	/* 0x381d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3822:
	/* 0x3822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3824:
	/* 0x3824: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3829:
	/* 0x3829: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3831:
	/* 0x3831: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3835:
	/* 0x3835: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_383a:
	/* 0x383a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_383f:
	/* 0x383f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3844:
	/* 0x3844: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3849:
	/* 0x3849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_384b:
	/* 0x384b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3853:
	/* 0x3853: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3856:
	/* 0x3856: je     38e1 <vfs_writev_magic_return+0x38e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e1;
	}
x86_l_385c:
	/* 0x385c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3861:
	/* 0x3861: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3864:
	/* 0x3864: je     38e1 <vfs_writev_magic_return+0x38e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e1;
	}
x86_l_3866:
	/* 0x3866: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_386a:
	/* 0x386a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_386f:
	/* 0x386f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3874:
	/* 0x3874: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3879:
	/* 0x3879: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_387e:
	/* 0x387e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3880:
	/* 0x3880: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3884:
	/* 0x3884: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3886:
	/* 0x3886: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_388c:
	/* 0x388c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3891:
	/* 0x3891: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3893:
	/* 0x3893: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3899:
	/* 0x3899: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_389e:
	/* 0x389e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_38a4:
	/* 0x38a4: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38a7:
	/* 0x38a7: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_38a9:
	/* 0x38a9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_38ae:
	/* 0x38ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b0:
	/* 0x38b0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38b3:
	/* 0x38b3: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_38b9:
	/* 0x38b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38be:
	/* 0x38be: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_38c1:
	/* 0x38c1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_38c7:
	/* 0x38c7: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_38cd:
	/* 0x38cd: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38cf:
	/* 0x38cf: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d4:
	/* 0x38d4: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_38dc:
	/* 0x38dc: jmp    3969 <vfs_writev_magic_return+0x3969> */
	return 14697ULL;
x86_l_38e1:
	/* 0x38e1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_38e4:
	/* 0x38e4: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_38ea:
	/* 0x38ea: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38ef:
	/* 0x38ef: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_38f4:
	/* 0x38f4: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_38fa:
	/* 0x38fa: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38fe:
	/* 0x38fe: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3906:
	/* 0x3906: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_390b:
	/* 0x390b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3910:
	/* 0x3910: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3915:
	/* 0x3915: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3919:
	/* 0x3919: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_391e:
	/* 0x391e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3920:
	/* 0x3920: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3925:
	/* 0x3925: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_392a:
	/* 0x392a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_392f:
	/* 0x392f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3934:
	/* 0x3934: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3939:
	/* 0x3939: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_393e:
	/* 0x393e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3940:
	/* 0x3940: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3945:
	/* 0x3945: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_394a:
	/* 0x394a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 14671ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14671ULL: goto x86_l_394f;
	case 14676ULL: goto x86_l_3954;
	case 14681ULL: goto x86_l_3959;
	case 14686ULL: goto x86_l_395e;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14697ULL: goto x86_l_3969;
	case 14702ULL: goto x86_l_396e;
	case 14707ULL: goto x86_l_3973;
	case 14712ULL: goto x86_l_3978;
	case 14715ULL: goto x86_l_397b;
	case 14720ULL: goto x86_l_3980;
	case 14722ULL: goto x86_l_3982;
	case 14727ULL: goto x86_l_3987;
	case 14735ULL: goto x86_l_398f;
	case 14739ULL: goto x86_l_3993;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14754ULL: goto x86_l_39a2;
	case 14759ULL: goto x86_l_39a7;
	case 14761ULL: goto x86_l_39a9;
	case 14769ULL: goto x86_l_39b1;
	case 14772ULL: goto x86_l_39b4;
	case 14778ULL: goto x86_l_39ba;
	case 14783ULL: goto x86_l_39bf;
	case 14786ULL: goto x86_l_39c2;
	case 14788ULL: goto x86_l_39c4;
	case 14792ULL: goto x86_l_39c8;
	case 14797ULL: goto x86_l_39cd;
	case 14802ULL: goto x86_l_39d2;
	case 14807ULL: goto x86_l_39d7;
	case 14812ULL: goto x86_l_39dc;
	case 14814ULL: goto x86_l_39de;
	case 14818ULL: goto x86_l_39e2;
	case 14820ULL: goto x86_l_39e4;
	case 14826ULL: goto x86_l_39ea;
	case 14831ULL: goto x86_l_39ef;
	case 14833ULL: goto x86_l_39f1;
	case 14839ULL: goto x86_l_39f7;
	case 14844ULL: goto x86_l_39fc;
	case 14850ULL: goto x86_l_3a02;
	case 14853ULL: goto x86_l_3a05;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14862ULL: goto x86_l_3a0e;
	case 14865ULL: goto x86_l_3a11;
	case 14871ULL: goto x86_l_3a17;
	case 14876ULL: goto x86_l_3a1c;
	case 14879ULL: goto x86_l_3a1f;
	case 14885ULL: goto x86_l_3a25;
	case 14891ULL: goto x86_l_3a2b;
	case 14893ULL: goto x86_l_3a2d;
	case 14898ULL: goto x86_l_3a32;
	case 14906ULL: goto x86_l_3a3a;
	case 14911ULL: goto x86_l_3a3f;
	case 14914ULL: goto x86_l_3a42;
	case 14920ULL: goto x86_l_3a48;
	case 14925ULL: goto x86_l_3a4d;
	case 14930ULL: goto x86_l_3a52;
	case 14936ULL: goto x86_l_3a58;
	case 14940ULL: goto x86_l_3a5c;
	case 14948ULL: goto x86_l_3a64;
	case 14953ULL: goto x86_l_3a69;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14967ULL: goto x86_l_3a77;
	case 14972ULL: goto x86_l_3a7c;
	case 14974ULL: goto x86_l_3a7e;
	case 14979ULL: goto x86_l_3a83;
	case 14984ULL: goto x86_l_3a88;
	case 14989ULL: goto x86_l_3a8d;
	case 14994ULL: goto x86_l_3a92;
	case 14999ULL: goto x86_l_3a97;
	case 15004ULL: goto x86_l_3a9c;
	case 15006ULL: goto x86_l_3a9e;
	case 15011ULL: goto x86_l_3aa3;
	case 15016ULL: goto x86_l_3aa8;
	case 15021ULL: goto x86_l_3aad;
	case 15026ULL: goto x86_l_3ab2;
	case 15031ULL: goto x86_l_3ab7;
	case 15036ULL: goto x86_l_3abc;
	case 15038ULL: goto x86_l_3abe;
	case 15043ULL: goto x86_l_3ac3;
	case 15047ULL: goto x86_l_3ac7;
	case 15052ULL: goto x86_l_3acc;
	case 15057ULL: goto x86_l_3ad1;
	case 15062ULL: goto x86_l_3ad6;
	case 15065ULL: goto x86_l_3ad9;
	case 15070ULL: goto x86_l_3ade;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15085ULL: goto x86_l_3aed;
	case 15089ULL: goto x86_l_3af1;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15109ULL: goto x86_l_3b05;
	case 15111ULL: goto x86_l_3b07;
	case 15119ULL: goto x86_l_3b0f;
	case 15122ULL: goto x86_l_3b12;
	case 15128ULL: goto x86_l_3b18;
	case 15133ULL: goto x86_l_3b1d;
	case 15136ULL: goto x86_l_3b20;
	case 15138ULL: goto x86_l_3b22;
	case 15142ULL: goto x86_l_3b26;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15157ULL: goto x86_l_3b35;
	case 15162ULL: goto x86_l_3b3a;
	case 15164ULL: goto x86_l_3b3c;
	case 15168ULL: goto x86_l_3b40;
	case 15170ULL: goto x86_l_3b42;
	case 15176ULL: goto x86_l_3b48;
	case 15181ULL: goto x86_l_3b4d;
	case 15183ULL: goto x86_l_3b4f;
	case 15189ULL: goto x86_l_3b55;
	case 15194ULL: goto x86_l_3b5a;
	case 15200ULL: goto x86_l_3b60;
	case 15203ULL: goto x86_l_3b63;
	case 15205ULL: goto x86_l_3b65;
	case 15210ULL: goto x86_l_3b6a;
	case 15212ULL: goto x86_l_3b6c;
	case 15215ULL: goto x86_l_3b6f;
	case 15221ULL: goto x86_l_3b75;
	case 15226ULL: goto x86_l_3b7a;
	case 15229ULL: goto x86_l_3b7d;
	case 15235ULL: goto x86_l_3b83;
	case 15241ULL: goto x86_l_3b89;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15256ULL: goto x86_l_3b98;
	case 15261ULL: goto x86_l_3b9d;
	case 15264ULL: goto x86_l_3ba0;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15280ULL: goto x86_l_3bb0;
	case 15286ULL: goto x86_l_3bb6;
	case 15290ULL: goto x86_l_3bba;
	case 15298ULL: goto x86_l_3bc2;
	case 15303ULL: goto x86_l_3bc7;
	case 15308ULL: goto x86_l_3bcc;
	case 15313ULL: goto x86_l_3bd1;
	case 15317ULL: goto x86_l_3bd5;
	case 15322ULL: goto x86_l_3bda;
	case 15324ULL: goto x86_l_3bdc;
	case 15329ULL: goto x86_l_3be1;
	case 15334ULL: goto x86_l_3be6;
	case 15339ULL: goto x86_l_3beb;
	case 15344ULL: goto x86_l_3bf0;
	case 15349ULL: goto x86_l_3bf5;
	case 15354ULL: goto x86_l_3bfa;
	case 15356ULL: goto x86_l_3bfc;
	case 15361ULL: goto x86_l_3c01;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15388ULL: goto x86_l_3c1c;
	case 15393ULL: goto x86_l_3c21;
	case 15397ULL: goto x86_l_3c25;
	case 15402ULL: goto x86_l_3c2a;
	case 15407ULL: goto x86_l_3c2f;
	case 15412ULL: goto x86_l_3c34;
	case 15415ULL: goto x86_l_3c37;
	case 15420ULL: goto x86_l_3c3c;
	case 15422ULL: goto x86_l_3c3e;
	case 15427ULL: goto x86_l_3c43;
	case 15435ULL: goto x86_l_3c4b;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15459ULL: goto x86_l_3c63;
	case 15461ULL: goto x86_l_3c65;
	case 15469ULL: goto x86_l_3c6d;
	case 15472ULL: goto x86_l_3c70;
	case 15478ULL: goto x86_l_3c76;
	case 15483ULL: goto x86_l_3c7b;
	case 15486ULL: goto x86_l_3c7e;
	case 15488ULL: goto x86_l_3c80;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15512ULL: goto x86_l_3c98;
	case 15514ULL: goto x86_l_3c9a;
	case 15518ULL: goto x86_l_3c9e;
	case 15520ULL: goto x86_l_3ca0;
	case 15526ULL: goto x86_l_3ca6;
	case 15531ULL: goto x86_l_3cab;
	case 15533ULL: goto x86_l_3cad;
	case 15539ULL: goto x86_l_3cb3;
	case 15544ULL: goto x86_l_3cb8;
	case 15550ULL: goto x86_l_3cbe;
	case 15553ULL: goto x86_l_3cc1;
	case 15555ULL: goto x86_l_3cc3;
	case 15560ULL: goto x86_l_3cc8;
	case 15562ULL: goto x86_l_3cca;
	case 15565ULL: goto x86_l_3ccd;
	case 15571ULL: goto x86_l_3cd3;
	case 15576ULL: goto x86_l_3cd8;
	case 15579ULL: goto x86_l_3cdb;
	case 15585ULL: goto x86_l_3ce1;
	case 15591ULL: goto x86_l_3ce7;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15606ULL: goto x86_l_3cf6;
	case 15611ULL: goto x86_l_3cfb;
	case 15614ULL: goto x86_l_3cfe;
	case 15620ULL: goto x86_l_3d04;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15636ULL: goto x86_l_3d14;
	case 15640ULL: goto x86_l_3d18;
	case 15648ULL: goto x86_l_3d20;
	case 15653ULL: goto x86_l_3d25;
	case 15658ULL: goto x86_l_3d2a;
	case 15663ULL: goto x86_l_3d2f;
	case 15667ULL: goto x86_l_3d33;
	case 15672ULL: goto x86_l_3d38;
	case 15674ULL: goto x86_l_3d3a;
	case 15679ULL: goto x86_l_3d3f;
	case 15684ULL: goto x86_l_3d44;
	case 15689ULL: goto x86_l_3d49;
	case 15694ULL: goto x86_l_3d4e;
	case 15699ULL: goto x86_l_3d53;
	case 15704ULL: goto x86_l_3d58;
	case 15706ULL: goto x86_l_3d5a;
	case 15711ULL: goto x86_l_3d5f;
	case 15716ULL: goto x86_l_3d64;
	case 15721ULL: goto x86_l_3d69;
	case 15726ULL: goto x86_l_3d6e;
	case 15731ULL: goto x86_l_3d73;
	case 15736ULL: goto x86_l_3d78;
	case 15738ULL: goto x86_l_3d7a;
	case 15743ULL: goto x86_l_3d7f;
	case 15747ULL: goto x86_l_3d83;
	case 15752ULL: goto x86_l_3d88;
	case 15757ULL: goto x86_l_3d8d;
	case 15762ULL: goto x86_l_3d92;
	case 15765ULL: goto x86_l_3d95;
	case 15770ULL: goto x86_l_3d9a;
	case 15772ULL: goto x86_l_3d9c;
	case 15777ULL: goto x86_l_3da1;
	case 15785ULL: goto x86_l_3da9;
	case 15789ULL: goto x86_l_3dad;
	case 15794ULL: goto x86_l_3db2;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15811ULL: goto x86_l_3dc3;
	case 15819ULL: goto x86_l_3dcb;
	case 15822ULL: goto x86_l_3dce;
	case 15828ULL: goto x86_l_3dd4;
	case 15833ULL: goto x86_l_3dd9;
	case 15836ULL: goto x86_l_3ddc;
	case 15838ULL: goto x86_l_3dde;
	case 15842ULL: goto x86_l_3de2;
	case 15847ULL: goto x86_l_3de7;
	case 15852ULL: goto x86_l_3dec;
	case 15857ULL: goto x86_l_3df1;
	case 15862ULL: goto x86_l_3df6;
	case 15864ULL: goto x86_l_3df8;
	case 15868ULL: goto x86_l_3dfc;
	case 15870ULL: goto x86_l_3dfe;
	case 15876ULL: goto x86_l_3e04;
	case 15881ULL: goto x86_l_3e09;
	case 15883ULL: goto x86_l_3e0b;
	case 15889ULL: goto x86_l_3e11;
	case 15894ULL: goto x86_l_3e16;
	case 15900ULL: goto x86_l_3e1c;
	case 15903ULL: goto x86_l_3e1f;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15912ULL: goto x86_l_3e28;
	case 15915ULL: goto x86_l_3e2b;
	case 15921ULL: goto x86_l_3e31;
	case 15926ULL: goto x86_l_3e36;
	case 15929ULL: goto x86_l_3e39;
	case 15935ULL: goto x86_l_3e3f;
	case 15941ULL: goto x86_l_3e45;
	case 15943ULL: goto x86_l_3e47;
	case 15948ULL: goto x86_l_3e4c;
	case 15956ULL: goto x86_l_3e54;
	case 15961ULL: goto x86_l_3e59;
	case 15964ULL: goto x86_l_3e5c;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15980ULL: goto x86_l_3e6c;
	case 15986ULL: goto x86_l_3e72;
	case 15990ULL: goto x86_l_3e76;
	case 15998ULL: goto x86_l_3e7e;
	case 16003ULL: goto x86_l_3e83;
	case 16008ULL: goto x86_l_3e88;
	case 16013ULL: goto x86_l_3e8d;
	case 16017ULL: goto x86_l_3e91;
	case 16022ULL: goto x86_l_3e96;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16049ULL: goto x86_l_3eb1;
	case 16054ULL: goto x86_l_3eb6;
	case 16056ULL: goto x86_l_3eb8;
	case 16061ULL: goto x86_l_3ebd;
	case 16066ULL: goto x86_l_3ec2;
	case 16071ULL: goto x86_l_3ec7;
	case 16076ULL: goto x86_l_3ecc;
	case 16081ULL: goto x86_l_3ed1;
	case 16086ULL: goto x86_l_3ed6;
	case 16088ULL: goto x86_l_3ed8;
	case 16093ULL: goto x86_l_3edd;
	case 16097ULL: goto x86_l_3ee1;
	case 16102ULL: goto x86_l_3ee6;
	case 16107ULL: goto x86_l_3eeb;
	case 16112ULL: goto x86_l_3ef0;
	case 16115ULL: goto x86_l_3ef3;
	case 16120ULL: goto x86_l_3ef8;
	case 16122ULL: goto x86_l_3efa;
	case 16127ULL: goto x86_l_3eff;
	case 16135ULL: goto x86_l_3f07;
	case 16139ULL: goto x86_l_3f0b;
	case 16144ULL: goto x86_l_3f10;
	case 16149ULL: goto x86_l_3f15;
	case 16154ULL: goto x86_l_3f1a;
	case 16159ULL: goto x86_l_3f1f;
	case 16161ULL: goto x86_l_3f21;
	case 16169ULL: goto x86_l_3f29;
	case 16172ULL: goto x86_l_3f2c;
	case 16178ULL: goto x86_l_3f32;
	case 16183ULL: goto x86_l_3f37;
	case 16186ULL: goto x86_l_3f3a;
	case 16188ULL: goto x86_l_3f3c;
	case 16192ULL: goto x86_l_3f40;
	case 16197ULL: goto x86_l_3f45;
	case 16202ULL: goto x86_l_3f4a;
	case 16207ULL: goto x86_l_3f4f;
	case 16212ULL: goto x86_l_3f54;
	case 16214ULL: goto x86_l_3f56;
	case 16218ULL: goto x86_l_3f5a;
	case 16220ULL: goto x86_l_3f5c;
	case 16226ULL: goto x86_l_3f62;
	case 16231ULL: goto x86_l_3f67;
	case 16233ULL: goto x86_l_3f69;
	case 16239ULL: goto x86_l_3f6f;
	case 16244ULL: goto x86_l_3f74;
	case 16250ULL: goto x86_l_3f7a;
	case 16253ULL: goto x86_l_3f7d;
	case 16255ULL: goto x86_l_3f7f;
	case 16260ULL: goto x86_l_3f84;
	case 16262ULL: goto x86_l_3f86;
	case 16265ULL: goto x86_l_3f89;
	case 16271ULL: goto x86_l_3f8f;
	case 16276ULL: goto x86_l_3f94;
	case 16279ULL: goto x86_l_3f97;
	case 16285ULL: goto x86_l_3f9d;
	case 16291ULL: goto x86_l_3fa3;
	case 16293ULL: goto x86_l_3fa5;
	case 16298ULL: goto x86_l_3faa;
	case 16306ULL: goto x86_l_3fb2;
	case 16311ULL: goto x86_l_3fb7;
	case 16314ULL: goto x86_l_3fba;
	case 16320ULL: goto x86_l_3fc0;
	case 16325ULL: goto x86_l_3fc5;
	case 16330ULL: goto x86_l_3fca;
	case 16336ULL: goto x86_l_3fd0;
	case 16340ULL: goto x86_l_3fd4;
	case 16348ULL: goto x86_l_3fdc;
	case 16353ULL: goto x86_l_3fe1;
	case 16358ULL: goto x86_l_3fe6;
	case 16363ULL: goto x86_l_3feb;
	case 16367ULL: goto x86_l_3fef;
	case 16372ULL: goto x86_l_3ff4;
	case 16374ULL: goto x86_l_3ff6;
	case 16379ULL: goto x86_l_3ffb;
	case 16384ULL: goto x86_l_4000;
	case 16389ULL: goto x86_l_4005;
	case 16394ULL: goto x86_l_400a;
	case 16399ULL: goto x86_l_400f;
	case 16404ULL: goto x86_l_4014;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_394f:
	/* 0x394f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3954:
	/* 0x3954: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3959:
	/* 0x3959: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_395e:
	/* 0x395e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3960:
	/* 0x3960: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3965:
	/* 0x3965: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3969:
	/* 0x3969: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_396e:
	/* 0x396e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3973:
	/* 0x3973: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3978:
	/* 0x3978: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_397b:
	/* 0x397b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3980:
	/* 0x3980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3982:
	/* 0x3982: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3987:
	/* 0x3987: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_398f:
	/* 0x398f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3993:
	/* 0x3993: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3998:
	/* 0x3998: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_399d:
	/* 0x399d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39a2:
	/* 0x39a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39a7:
	/* 0x39a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39a9:
	/* 0x39a9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_39b1:
	/* 0x39b1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_39b4:
	/* 0x39b4: je     3a3f <vfs_writev_magic_return+0x3a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a3f;
	}
x86_l_39ba:
	/* 0x39ba: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39bf:
	/* 0x39bf: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_39c2:
	/* 0x39c2: je     3a3f <vfs_writev_magic_return+0x3a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a3f;
	}
x86_l_39c4:
	/* 0x39c4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_39c8:
	/* 0x39c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39cd:
	/* 0x39cd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_39d2:
	/* 0x39d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39d7:
	/* 0x39d7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39dc:
	/* 0x39dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39de:
	/* 0x39de: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_39e2:
	/* 0x39e2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_39e4:
	/* 0x39e4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_39ea:
	/* 0x39ea: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ef:
	/* 0x39ef: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39f1:
	/* 0x39f1: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_39f7:
	/* 0x39f7: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_39fc:
	/* 0x39fc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3a02:
	/* 0x3a02: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a05:
	/* 0x3a05: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3a07:
	/* 0x3a07: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3a0c:
	/* 0x3a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a0e:
	/* 0x3a0e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a11:
	/* 0x3a11: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3a17:
	/* 0x3a17: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1c:
	/* 0x3a1c: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3a1f:
	/* 0x3a1f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3a25:
	/* 0x3a25: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3a2b:
	/* 0x3a2b: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a2d:
	/* 0x3a2d: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a32:
	/* 0x3a32: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a3a:
	/* 0x3a3a: jmp    3ac7 <vfs_writev_magic_return+0x3ac7> */
	goto x86_l_3ac7;
x86_l_3a3f:
	/* 0x3a3f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3a42:
	/* 0x3a42: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3a48:
	/* 0x3a48: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a4d:
	/* 0x3a4d: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3a52:
	/* 0x3a52: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3a58:
	/* 0x3a58: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a5c:
	/* 0x3a5c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a64:
	/* 0x3a64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a69:
	/* 0x3a69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a6e:
	/* 0x3a6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a73:
	/* 0x3a73: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a77:
	/* 0x3a77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a7c:
	/* 0x3a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7e:
	/* 0x3a7e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a83:
	/* 0x3a83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a88:
	/* 0x3a88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a8d:
	/* 0x3a8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a92:
	/* 0x3a92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a97:
	/* 0x3a97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a9c:
	/* 0x3a9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9e:
	/* 0x3a9e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aa3:
	/* 0x3aa3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3aa8:
	/* 0x3aa8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aad:
	/* 0x3aad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ab2:
	/* 0x3ab2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ab7:
	/* 0x3ab7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3abc:
	/* 0x3abc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3abe:
	/* 0x3abe: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ac3:
	/* 0x3ac3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3ac7:
	/* 0x3ac7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3acc:
	/* 0x3acc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ad1:
	/* 0x3ad1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ad6:
	/* 0x3ad6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3ad9:
	/* 0x3ad9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ade:
	/* 0x3ade: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ae0:
	/* 0x3ae0: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ae5:
	/* 0x3ae5: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3aed:
	/* 0x3aed: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3af1:
	/* 0x3af1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3af6:
	/* 0x3af6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3afb:
	/* 0x3afb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b00:
	/* 0x3b00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b05:
	/* 0x3b05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b07:
	/* 0x3b07: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b0f:
	/* 0x3b0f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3b12:
	/* 0x3b12: je     3b9d <vfs_writev_magic_return+0x3b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b9d;
	}
x86_l_3b18:
	/* 0x3b18: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b1d:
	/* 0x3b1d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b20:
	/* 0x3b20: je     3b9d <vfs_writev_magic_return+0x3b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b9d;
	}
x86_l_3b22:
	/* 0x3b22: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b26:
	/* 0x3b26: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b2b:
	/* 0x3b2b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3b30:
	/* 0x3b30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b35:
	/* 0x3b35: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3b3a:
	/* 0x3b3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b3c:
	/* 0x3b3c: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3b40:
	/* 0x3b40: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3b42:
	/* 0x3b42: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3b48:
	/* 0x3b48: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b4d:
	/* 0x3b4d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3b4f:
	/* 0x3b4f: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3b55:
	/* 0x3b55: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b5a:
	/* 0x3b5a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3b60:
	/* 0x3b60: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b63:
	/* 0x3b63: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3b65:
	/* 0x3b65: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3b6a:
	/* 0x3b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6c:
	/* 0x3b6c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3b6f:
	/* 0x3b6f: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3b75:
	/* 0x3b75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b7a:
	/* 0x3b7a: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3b7d:
	/* 0x3b7d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3b83:
	/* 0x3b83: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3b89:
	/* 0x3b89: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3b8b:
	/* 0x3b8b: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b90:
	/* 0x3b90: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b98:
	/* 0x3b98: jmp    3c25 <vfs_writev_magic_return+0x3c25> */
	goto x86_l_3c25;
x86_l_3b9d:
	/* 0x3b9d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3ba0:
	/* 0x3ba0: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3ba6:
	/* 0x3ba6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bab:
	/* 0x3bab: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3bb0:
	/* 0x3bb0: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3bb6:
	/* 0x3bb6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3bba:
	/* 0x3bba: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bc7:
	/* 0x3bc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bcc:
	/* 0x3bcc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bd1:
	/* 0x3bd1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3bd5:
	/* 0x3bd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bda:
	/* 0x3bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bdc:
	/* 0x3bdc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3be1:
	/* 0x3be1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3be6:
	/* 0x3be6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3beb:
	/* 0x3beb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bf0:
	/* 0x3bf0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bf5:
	/* 0x3bf5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bfa:
	/* 0x3bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bfc:
	/* 0x3bfc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c01:
	/* 0x3c01: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c06:
	/* 0x3c06: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c10:
	/* 0x3c10: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c15:
	/* 0x3c15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c1a:
	/* 0x3c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1c:
	/* 0x3c1c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c21:
	/* 0x3c21: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c25:
	/* 0x3c25: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c2a:
	/* 0x3c2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c2f:
	/* 0x3c2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c34:
	/* 0x3c34: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3c37:
	/* 0x3c37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c3c:
	/* 0x3c3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3e:
	/* 0x3c3e: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c43:
	/* 0x3c43: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3c4b:
	/* 0x3c4b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c4f:
	/* 0x3c4f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c54:
	/* 0x3c54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c59:
	/* 0x3c59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c5e:
	/* 0x3c5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c63:
	/* 0x3c63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c65:
	/* 0x3c65: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3c6d:
	/* 0x3c6d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3c70:
	/* 0x3c70: je     3cfb <vfs_writev_magic_return+0x3cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfb;
	}
x86_l_3c76:
	/* 0x3c76: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c7b:
	/* 0x3c7b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3c7e:
	/* 0x3c7e: je     3cfb <vfs_writev_magic_return+0x3cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfb;
	}
x86_l_3c80:
	/* 0x3c80: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c84:
	/* 0x3c84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c89:
	/* 0x3c89: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3c8e:
	/* 0x3c8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c93:
	/* 0x3c93: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3c98:
	/* 0x3c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9a:
	/* 0x3c9a: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3c9e:
	/* 0x3c9e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ca0:
	/* 0x3ca0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ca6:
	/* 0x3ca6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cab:
	/* 0x3cab: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3cad:
	/* 0x3cad: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3cb3:
	/* 0x3cb3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3cb8:
	/* 0x3cb8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3cbe:
	/* 0x3cbe: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3cc1:
	/* 0x3cc1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3cc3:
	/* 0x3cc3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3cc8:
	/* 0x3cc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cca:
	/* 0x3cca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ccd:
	/* 0x3ccd: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3cd3:
	/* 0x3cd3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd8:
	/* 0x3cd8: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3cdb:
	/* 0x3cdb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3ce1:
	/* 0x3ce1: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ce7:
	/* 0x3ce7: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ce9:
	/* 0x3ce9: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cee:
	/* 0x3cee: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3cf6:
	/* 0x3cf6: jmp    3d83 <vfs_writev_magic_return+0x3d83> */
	goto x86_l_3d83;
x86_l_3cfb:
	/* 0x3cfb: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3cfe:
	/* 0x3cfe: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3d04:
	/* 0x3d04: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d09:
	/* 0x3d09: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3d0e:
	/* 0x3d0e: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3d14:
	/* 0x3d14: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d18:
	/* 0x3d18: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3d20:
	/* 0x3d20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d25:
	/* 0x3d25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d2a:
	/* 0x3d2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d2f:
	/* 0x3d2f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d33:
	/* 0x3d33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d38:
	/* 0x3d38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d3a:
	/* 0x3d3a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3f:
	/* 0x3d3f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d44:
	/* 0x3d44: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d49:
	/* 0x3d49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d4e:
	/* 0x3d4e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d53:
	/* 0x3d53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d58:
	/* 0x3d58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d5a:
	/* 0x3d5a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d5f:
	/* 0x3d5f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d64:
	/* 0x3d64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d69:
	/* 0x3d69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d6e:
	/* 0x3d6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d73:
	/* 0x3d73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d78:
	/* 0x3d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d7a:
	/* 0x3d7a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d7f:
	/* 0x3d7f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d83:
	/* 0x3d83: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d88:
	/* 0x3d88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d8d:
	/* 0x3d8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d92:
	/* 0x3d92: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3d95:
	/* 0x3d95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d9a:
	/* 0x3d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d9c:
	/* 0x3d9c: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3da1:
	/* 0x3da1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3da9:
	/* 0x3da9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3dad:
	/* 0x3dad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3db2:
	/* 0x3db2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3db7:
	/* 0x3db7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dbc:
	/* 0x3dbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dc1:
	/* 0x3dc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc3:
	/* 0x3dc3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3dcb:
	/* 0x3dcb: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3dce:
	/* 0x3dce: je     3e59 <vfs_writev_magic_return+0x3e59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e59;
	}
x86_l_3dd4:
	/* 0x3dd4: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dd9:
	/* 0x3dd9: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3ddc:
	/* 0x3ddc: je     3e59 <vfs_writev_magic_return+0x3e59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e59;
	}
x86_l_3dde:
	/* 0x3dde: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3de2:
	/* 0x3de2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3de7:
	/* 0x3de7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3dec:
	/* 0x3dec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3df1:
	/* 0x3df1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3df6:
	/* 0x3df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df8:
	/* 0x3df8: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3dfc:
	/* 0x3dfc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3dfe:
	/* 0x3dfe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e04:
	/* 0x3e04: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e09:
	/* 0x3e09: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e0b:
	/* 0x3e0b: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3e11:
	/* 0x3e11: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e16:
	/* 0x3e16: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3e1c:
	/* 0x3e1c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e1f:
	/* 0x3e1f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3e21:
	/* 0x3e21: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3e26:
	/* 0x3e26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e28:
	/* 0x3e28: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3e2b:
	/* 0x3e2b: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3e31:
	/* 0x3e31: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e36:
	/* 0x3e36: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3e39:
	/* 0x3e39: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3e3f:
	/* 0x3e3f: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3e45:
	/* 0x3e45: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e47:
	/* 0x3e47: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e4c:
	/* 0x3e4c: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e54:
	/* 0x3e54: jmp    3ee1 <vfs_writev_magic_return+0x3ee1> */
	goto x86_l_3ee1;
x86_l_3e59:
	/* 0x3e59: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3e5c:
	/* 0x3e5c: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3e62:
	/* 0x3e62: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e67:
	/* 0x3e67: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3e6c:
	/* 0x3e6c: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3e72:
	/* 0x3e72: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3e76:
	/* 0x3e76: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e7e:
	/* 0x3e7e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e83:
	/* 0x3e83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e88:
	/* 0x3e88: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e8d:
	/* 0x3e8d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3e91:
	/* 0x3e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e96:
	/* 0x3e96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e98:
	/* 0x3e98: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e9d:
	/* 0x3e9d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea2:
	/* 0x3ea2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ea7:
	/* 0x3ea7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3eac:
	/* 0x3eac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb1:
	/* 0x3eb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eb6:
	/* 0x3eb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eb8:
	/* 0x3eb8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ebd:
	/* 0x3ebd: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ec2:
	/* 0x3ec2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ec7:
	/* 0x3ec7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ecc:
	/* 0x3ecc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed1:
	/* 0x3ed1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ed6:
	/* 0x3ed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed8:
	/* 0x3ed8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3edd:
	/* 0x3edd: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3ee1:
	/* 0x3ee1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ee6:
	/* 0x3ee6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eeb:
	/* 0x3eeb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ef0:
	/* 0x3ef0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3ef3:
	/* 0x3ef3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef8:
	/* 0x3ef8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3efa:
	/* 0x3efa: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3eff:
	/* 0x3eff: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f07:
	/* 0x3f07: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f0b:
	/* 0x3f0b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f10:
	/* 0x3f10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f15:
	/* 0x3f15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f1a:
	/* 0x3f1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f1f:
	/* 0x3f1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f21:
	/* 0x3f21: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f29:
	/* 0x3f29: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3f2c:
	/* 0x3f2c: je     3fb7 <vfs_writev_magic_return+0x3fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fb7;
	}
x86_l_3f32:
	/* 0x3f32: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f37:
	/* 0x3f37: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3f3a:
	/* 0x3f3a: je     3fb7 <vfs_writev_magic_return+0x3fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fb7;
	}
x86_l_3f3c:
	/* 0x3f3c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f40:
	/* 0x3f40: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f45:
	/* 0x3f45: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3f4a:
	/* 0x3f4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f4f:
	/* 0x3f4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f54:
	/* 0x3f54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f56:
	/* 0x3f56: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3f5a:
	/* 0x3f5a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f5c:
	/* 0x3f5c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f62:
	/* 0x3f62: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f67:
	/* 0x3f67: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f69:
	/* 0x3f69: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_3f6f:
	/* 0x3f6f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3f74:
	/* 0x3f74: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3f7a:
	/* 0x3f7a: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f7d:
	/* 0x3f7d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3f7f:
	/* 0x3f7f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3f84:
	/* 0x3f84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f86:
	/* 0x3f86: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3f89:
	/* 0x3f89: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_3f8f:
	/* 0x3f8f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f94:
	/* 0x3f94: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3f97:
	/* 0x3f97: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3f9d:
	/* 0x3f9d: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3fa3:
	/* 0x3fa3: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fa5:
	/* 0x3fa5: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3faa:
	/* 0x3faa: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fb2:
	/* 0x3fb2: jmp    403f <vfs_writev_magic_return+0x403f> */
	return 16447ULL;
x86_l_3fb7:
	/* 0x3fb7: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3fba:
	/* 0x3fba: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_3fc0:
	/* 0x3fc0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fc5:
	/* 0x3fc5: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3fca:
	/* 0x3fca: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_3fd0:
	/* 0x3fd0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fd4:
	/* 0x3fd4: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fdc:
	/* 0x3fdc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fe1:
	/* 0x3fe1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fe6:
	/* 0x3fe6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3feb:
	/* 0x3feb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fef:
	/* 0x3fef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ff4:
	/* 0x3ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff6:
	/* 0x3ff6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ffb:
	/* 0x3ffb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4000:
	/* 0x4000: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4005:
	/* 0x4005: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_400a:
	/* 0x400a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_400f:
	/* 0x400f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4014:
	/* 0x4014: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4016:
	/* 0x4016: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_401b:
	/* 0x401b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 16416ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16416ULL: goto x86_l_4020;
	case 16421ULL: goto x86_l_4025;
	case 16426ULL: goto x86_l_402a;
	case 16431ULL: goto x86_l_402f;
	case 16436ULL: goto x86_l_4034;
	case 16438ULL: goto x86_l_4036;
	case 16443ULL: goto x86_l_403b;
	case 16447ULL: goto x86_l_403f;
	case 16452ULL: goto x86_l_4044;
	case 16457ULL: goto x86_l_4049;
	case 16462ULL: goto x86_l_404e;
	case 16465ULL: goto x86_l_4051;
	case 16470ULL: goto x86_l_4056;
	case 16472ULL: goto x86_l_4058;
	case 16477ULL: goto x86_l_405d;
	case 16485ULL: goto x86_l_4065;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16504ULL: goto x86_l_4078;
	case 16509ULL: goto x86_l_407d;
	case 16511ULL: goto x86_l_407f;
	case 16519ULL: goto x86_l_4087;
	case 16522ULL: goto x86_l_408a;
	case 16528ULL: goto x86_l_4090;
	case 16533ULL: goto x86_l_4095;
	case 16536ULL: goto x86_l_4098;
	case 16538ULL: goto x86_l_409a;
	case 16542ULL: goto x86_l_409e;
	case 16547ULL: goto x86_l_40a3;
	case 16552ULL: goto x86_l_40a8;
	case 16557ULL: goto x86_l_40ad;
	case 16562ULL: goto x86_l_40b2;
	case 16564ULL: goto x86_l_40b4;
	case 16568ULL: goto x86_l_40b8;
	case 16570ULL: goto x86_l_40ba;
	case 16576ULL: goto x86_l_40c0;
	case 16581ULL: goto x86_l_40c5;
	case 16583ULL: goto x86_l_40c7;
	case 16589ULL: goto x86_l_40cd;
	case 16594ULL: goto x86_l_40d2;
	case 16600ULL: goto x86_l_40d8;
	case 16603ULL: goto x86_l_40db;
	case 16605ULL: goto x86_l_40dd;
	case 16610ULL: goto x86_l_40e2;
	case 16612ULL: goto x86_l_40e4;
	case 16615ULL: goto x86_l_40e7;
	case 16621ULL: goto x86_l_40ed;
	case 16626ULL: goto x86_l_40f2;
	case 16629ULL: goto x86_l_40f5;
	case 16635ULL: goto x86_l_40fb;
	case 16641ULL: goto x86_l_4101;
	case 16643ULL: goto x86_l_4103;
	case 16648ULL: goto x86_l_4108;
	case 16656ULL: goto x86_l_4110;
	case 16661ULL: goto x86_l_4115;
	case 16664ULL: goto x86_l_4118;
	case 16670ULL: goto x86_l_411e;
	case 16675ULL: goto x86_l_4123;
	case 16680ULL: goto x86_l_4128;
	case 16686ULL: goto x86_l_412e;
	case 16690ULL: goto x86_l_4132;
	case 16698ULL: goto x86_l_413a;
	case 16703ULL: goto x86_l_413f;
	case 16708ULL: goto x86_l_4144;
	case 16713ULL: goto x86_l_4149;
	case 16717ULL: goto x86_l_414d;
	case 16722ULL: goto x86_l_4152;
	case 16724ULL: goto x86_l_4154;
	case 16729ULL: goto x86_l_4159;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16744ULL: goto x86_l_4168;
	case 16749ULL: goto x86_l_416d;
	case 16754ULL: goto x86_l_4172;
	case 16756ULL: goto x86_l_4174;
	case 16761ULL: goto x86_l_4179;
	case 16766ULL: goto x86_l_417e;
	case 16771ULL: goto x86_l_4183;
	case 16776ULL: goto x86_l_4188;
	case 16781ULL: goto x86_l_418d;
	case 16786ULL: goto x86_l_4192;
	case 16788ULL: goto x86_l_4194;
	case 16793ULL: goto x86_l_4199;
	case 16797ULL: goto x86_l_419d;
	case 16802ULL: goto x86_l_41a2;
	case 16807ULL: goto x86_l_41a7;
	case 16812ULL: goto x86_l_41ac;
	case 16815ULL: goto x86_l_41af;
	case 16820ULL: goto x86_l_41b4;
	case 16822ULL: goto x86_l_41b6;
	case 16827ULL: goto x86_l_41bb;
	case 16835ULL: goto x86_l_41c3;
	case 16839ULL: goto x86_l_41c7;
	case 16844ULL: goto x86_l_41cc;
	case 16849ULL: goto x86_l_41d1;
	case 16854ULL: goto x86_l_41d6;
	case 16859ULL: goto x86_l_41db;
	case 16861ULL: goto x86_l_41dd;
	case 16869ULL: goto x86_l_41e5;
	case 16872ULL: goto x86_l_41e8;
	case 16878ULL: goto x86_l_41ee;
	case 16883ULL: goto x86_l_41f3;
	case 16886ULL: goto x86_l_41f6;
	case 16888ULL: goto x86_l_41f8;
	case 16892ULL: goto x86_l_41fc;
	case 16897ULL: goto x86_l_4201;
	case 16902ULL: goto x86_l_4206;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16914ULL: goto x86_l_4212;
	case 16918ULL: goto x86_l_4216;
	case 16920ULL: goto x86_l_4218;
	case 16926ULL: goto x86_l_421e;
	case 16931ULL: goto x86_l_4223;
	case 16933ULL: goto x86_l_4225;
	case 16939ULL: goto x86_l_422b;
	case 16944ULL: goto x86_l_4230;
	case 16950ULL: goto x86_l_4236;
	case 16953ULL: goto x86_l_4239;
	case 16955ULL: goto x86_l_423b;
	case 16960ULL: goto x86_l_4240;
	case 16962ULL: goto x86_l_4242;
	case 16965ULL: goto x86_l_4245;
	case 16971ULL: goto x86_l_424b;
	case 16976ULL: goto x86_l_4250;
	case 16979ULL: goto x86_l_4253;
	case 16985ULL: goto x86_l_4259;
	case 16991ULL: goto x86_l_425f;
	case 16993ULL: goto x86_l_4261;
	case 16998ULL: goto x86_l_4266;
	case 17006ULL: goto x86_l_426e;
	case 17011ULL: goto x86_l_4273;
	case 17014ULL: goto x86_l_4276;
	case 17020ULL: goto x86_l_427c;
	case 17025ULL: goto x86_l_4281;
	case 17030ULL: goto x86_l_4286;
	case 17036ULL: goto x86_l_428c;
	case 17040ULL: goto x86_l_4290;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17058ULL: goto x86_l_42a2;
	case 17063ULL: goto x86_l_42a7;
	case 17067ULL: goto x86_l_42ab;
	case 17072ULL: goto x86_l_42b0;
	case 17074ULL: goto x86_l_42b2;
	case 17079ULL: goto x86_l_42b7;
	case 17084ULL: goto x86_l_42bc;
	case 17089ULL: goto x86_l_42c1;
	case 17094ULL: goto x86_l_42c6;
	case 17099ULL: goto x86_l_42cb;
	case 17104ULL: goto x86_l_42d0;
	case 17106ULL: goto x86_l_42d2;
	case 17111ULL: goto x86_l_42d7;
	case 17116ULL: goto x86_l_42dc;
	case 17121ULL: goto x86_l_42e1;
	case 17126ULL: goto x86_l_42e6;
	case 17131ULL: goto x86_l_42eb;
	case 17136ULL: goto x86_l_42f0;
	case 17138ULL: goto x86_l_42f2;
	case 17143ULL: goto x86_l_42f7;
	case 17147ULL: goto x86_l_42fb;
	case 17152ULL: goto x86_l_4300;
	case 17157ULL: goto x86_l_4305;
	case 17162ULL: goto x86_l_430a;
	case 17165ULL: goto x86_l_430d;
	case 17170ULL: goto x86_l_4312;
	case 17172ULL: goto x86_l_4314;
	case 17177ULL: goto x86_l_4319;
	case 17185ULL: goto x86_l_4321;
	case 17189ULL: goto x86_l_4325;
	case 17194ULL: goto x86_l_432a;
	case 17199ULL: goto x86_l_432f;
	case 17204ULL: goto x86_l_4334;
	case 17209ULL: goto x86_l_4339;
	case 17211ULL: goto x86_l_433b;
	case 17219ULL: goto x86_l_4343;
	case 17222ULL: goto x86_l_4346;
	case 17228ULL: goto x86_l_434c;
	case 17233ULL: goto x86_l_4351;
	case 17236ULL: goto x86_l_4354;
	case 17242ULL: goto x86_l_435a;
	case 17246ULL: goto x86_l_435e;
	case 17251ULL: goto x86_l_4363;
	case 17256ULL: goto x86_l_4368;
	case 17261ULL: goto x86_l_436d;
	case 17266ULL: goto x86_l_4372;
	case 17268ULL: goto x86_l_4374;
	case 17272ULL: goto x86_l_4378;
	case 17274ULL: goto x86_l_437a;
	case 17280ULL: goto x86_l_4380;
	case 17285ULL: goto x86_l_4385;
	case 17287ULL: goto x86_l_4387;
	case 17293ULL: goto x86_l_438d;
	case 17298ULL: goto x86_l_4392;
	case 17304ULL: goto x86_l_4398;
	case 17307ULL: goto x86_l_439b;
	case 17309ULL: goto x86_l_439d;
	case 17314ULL: goto x86_l_43a2;
	case 17316ULL: goto x86_l_43a4;
	case 17319ULL: goto x86_l_43a7;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17333ULL: goto x86_l_43b5;
	case 17339ULL: goto x86_l_43bb;
	case 17345ULL: goto x86_l_43c1;
	case 17347ULL: goto x86_l_43c3;
	case 17355ULL: goto x86_l_43cb;
	case 17360ULL: goto x86_l_43d0;
	case 17365ULL: goto x86_l_43d5;
	case 17371ULL: goto x86_l_43db;
	case 17377ULL: goto x86_l_43e1;
	case 17382ULL: goto x86_l_43e6;
	case 17385ULL: goto x86_l_43e9;
	case 17391ULL: goto x86_l_43ef;
	case 17396ULL: goto x86_l_43f4;
	case 17401ULL: goto x86_l_43f9;
	case 17407ULL: goto x86_l_43ff;
	case 17411ULL: goto x86_l_4403;
	case 17419ULL: goto x86_l_440b;
	case 17424ULL: goto x86_l_4410;
	case 17429ULL: goto x86_l_4415;
	case 17434ULL: goto x86_l_441a;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17445ULL: goto x86_l_4425;
	case 17450ULL: goto x86_l_442a;
	case 17455ULL: goto x86_l_442f;
	case 17460ULL: goto x86_l_4434;
	case 17465ULL: goto x86_l_4439;
	case 17470ULL: goto x86_l_443e;
	case 17475ULL: goto x86_l_4443;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17487ULL: goto x86_l_444f;
	case 17492ULL: goto x86_l_4454;
	case 17497ULL: goto x86_l_4459;
	case 17502ULL: goto x86_l_445e;
	case 17507ULL: goto x86_l_4463;
	case 17509ULL: goto x86_l_4465;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4020:
	/* 0x4020: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4025:
	/* 0x4025: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_402a:
	/* 0x402a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_402f:
	/* 0x402f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4034:
	/* 0x4034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4036:
	/* 0x4036: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_403b:
	/* 0x403b: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_403f:
	/* 0x403f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4044:
	/* 0x4044: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4049:
	/* 0x4049: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_404e:
	/* 0x404e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4051:
	/* 0x4051: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4056:
	/* 0x4056: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4058:
	/* 0x4058: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_405d:
	/* 0x405d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4065:
	/* 0x4065: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4069:
	/* 0x4069: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_406e:
	/* 0x406e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4073:
	/* 0x4073: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4078:
	/* 0x4078: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_407d:
	/* 0x407d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_407f:
	/* 0x407f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4087:
	/* 0x4087: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_408a:
	/* 0x408a: je     4115 <vfs_writev_magic_return+0x4115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4115;
	}
x86_l_4090:
	/* 0x4090: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4095:
	/* 0x4095: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4098:
	/* 0x4098: je     4115 <vfs_writev_magic_return+0x4115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4115;
	}
x86_l_409a:
	/* 0x409a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_409e:
	/* 0x409e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40a3:
	/* 0x40a3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_40a8:
	/* 0x40a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40ad:
	/* 0x40ad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_40b2:
	/* 0x40b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b4:
	/* 0x40b4: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_40b8:
	/* 0x40b8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_40ba:
	/* 0x40ba: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_40c0:
	/* 0x40c0: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40c5:
	/* 0x40c5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40c7:
	/* 0x40c7: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_40cd:
	/* 0x40cd: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_40d2:
	/* 0x40d2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_40d8:
	/* 0x40d8: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40db:
	/* 0x40db: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_40dd:
	/* 0x40dd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_40e2:
	/* 0x40e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e4:
	/* 0x40e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_40e7:
	/* 0x40e7: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_40ed:
	/* 0x40ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40f2:
	/* 0x40f2: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_40f5:
	/* 0x40f5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_40fb:
	/* 0x40fb: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4101:
	/* 0x4101: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4103:
	/* 0x4103: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4108:
	/* 0x4108: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4110:
	/* 0x4110: jmp    419d <vfs_writev_magic_return+0x419d> */
	goto x86_l_419d;
x86_l_4115:
	/* 0x4115: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4118:
	/* 0x4118: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_411e:
	/* 0x411e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4123:
	/* 0x4123: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_4128:
	/* 0x4128: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_412e:
	/* 0x412e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4132:
	/* 0x4132: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_413a:
	/* 0x413a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_413f:
	/* 0x413f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4144:
	/* 0x4144: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4149:
	/* 0x4149: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_414d:
	/* 0x414d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4152:
	/* 0x4152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4154:
	/* 0x4154: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4159:
	/* 0x4159: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_415e:
	/* 0x415e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4163:
	/* 0x4163: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4168:
	/* 0x4168: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_416d:
	/* 0x416d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4172:
	/* 0x4172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4174:
	/* 0x4174: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4179:
	/* 0x4179: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_417e:
	/* 0x417e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4183:
	/* 0x4183: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4188:
	/* 0x4188: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_418d:
	/* 0x418d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4192:
	/* 0x4192: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4194:
	/* 0x4194: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4199:
	/* 0x4199: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_419d:
	/* 0x419d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41a2:
	/* 0x41a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41a7:
	/* 0x41a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41ac:
	/* 0x41ac: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_41af:
	/* 0x41af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b4:
	/* 0x41b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b6:
	/* 0x41b6: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41bb:
	/* 0x41bb: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_41c3:
	/* 0x41c3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_41c7:
	/* 0x41c7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41cc:
	/* 0x41cc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41d1:
	/* 0x41d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41d6:
	/* 0x41d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41db:
	/* 0x41db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41dd:
	/* 0x41dd: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_41e5:
	/* 0x41e5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_41e8:
	/* 0x41e8: je     4273 <vfs_writev_magic_return+0x4273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4273;
	}
x86_l_41ee:
	/* 0x41ee: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41f3:
	/* 0x41f3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_41f6:
	/* 0x41f6: je     4273 <vfs_writev_magic_return+0x4273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4273;
	}
x86_l_41f8:
	/* 0x41f8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_41fc:
	/* 0x41fc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4201:
	/* 0x4201: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4206:
	/* 0x4206: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_420b:
	/* 0x420b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4210:
	/* 0x4210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4212:
	/* 0x4212: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4216:
	/* 0x4216: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4218:
	/* 0x4218: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_421e:
	/* 0x421e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4223:
	/* 0x4223: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4225:
	/* 0x4225: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_422b:
	/* 0x422b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4230:
	/* 0x4230: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4236:
	/* 0x4236: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4239:
	/* 0x4239: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_423b:
	/* 0x423b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4240:
	/* 0x4240: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4242:
	/* 0x4242: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4245:
	/* 0x4245: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_424b:
	/* 0x424b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4250:
	/* 0x4250: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4253:
	/* 0x4253: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4259:
	/* 0x4259: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_425f:
	/* 0x425f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4261:
	/* 0x4261: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4266:
	/* 0x4266: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_426e:
	/* 0x426e: jmp    42fb <vfs_writev_magic_return+0x42fb> */
	goto x86_l_42fb;
x86_l_4273:
	/* 0x4273: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4276:
	/* 0x4276: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_427c:
	/* 0x427c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4281:
	/* 0x4281: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_4286:
	/* 0x4286: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_428c:
	/* 0x428c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4290:
	/* 0x4290: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4298:
	/* 0x4298: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_429d:
	/* 0x429d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42a2:
	/* 0x42a2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a7:
	/* 0x42a7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42ab:
	/* 0x42ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42b0:
	/* 0x42b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42b2:
	/* 0x42b2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42b7:
	/* 0x42b7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42bc:
	/* 0x42bc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42c1:
	/* 0x42c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42c6:
	/* 0x42c6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42cb:
	/* 0x42cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42d0:
	/* 0x42d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d2:
	/* 0x42d2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42d7:
	/* 0x42d7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_42dc:
	/* 0x42dc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42e1:
	/* 0x42e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42e6:
	/* 0x42e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42eb:
	/* 0x42eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42f0:
	/* 0x42f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f2:
	/* 0x42f2: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f7:
	/* 0x42f7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_42fb:
	/* 0x42fb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4300:
	/* 0x4300: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4305:
	/* 0x4305: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_430a:
	/* 0x430a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_430d:
	/* 0x430d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4312:
	/* 0x4312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4314:
	/* 0x4314: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4319:
	/* 0x4319: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4321:
	/* 0x4321: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4325:
	/* 0x4325: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_432a:
	/* 0x432a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_432f:
	/* 0x432f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4334:
	/* 0x4334: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4339:
	/* 0x4339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433b:
	/* 0x433b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4343:
	/* 0x4343: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4346:
	/* 0x4346: je     43e6 <vfs_writev_magic_return+0x43e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e6;
	}
x86_l_434c:
	/* 0x434c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4351:
	/* 0x4351: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4354:
	/* 0x4354: je     43e6 <vfs_writev_magic_return+0x43e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e6;
	}
x86_l_435a:
	/* 0x435a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_435e:
	/* 0x435e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4363:
	/* 0x4363: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4368:
	/* 0x4368: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_436d:
	/* 0x436d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4372:
	/* 0x4372: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4374:
	/* 0x4374: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4378:
	/* 0x4378: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_437a:
	/* 0x437a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4380:
	/* 0x4380: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4385:
	/* 0x4385: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4387:
	/* 0x4387: jb     2ee2 <vfs_writev_magic_return+0x2ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12002ULL;
	}
x86_l_438d:
	/* 0x438d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4392:
	/* 0x4392: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4398:
	/* 0x4398: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_439b:
	/* 0x439b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_439d:
	/* 0x439d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_43a2:
	/* 0x43a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43a4:
	/* 0x43a4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43a7:
	/* 0x43a7: jl     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 12442ULL;
	}
x86_l_43ad:
	/* 0x43ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b2:
	/* 0x43b2: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_43b5:
	/* 0x43b5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_43bb:
	/* 0x43bb: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_43c1:
	/* 0x43c1: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43c3:
	/* 0x43c3: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_43cb:
	/* 0x43cb: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43d0:
	/* 0x43d0: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43d5:
	/* 0x43d5: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_43db:
	/* 0x43db: je     1c3c <vfs_writev_magic_return+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7228ULL;
	}
x86_l_43e1:
	/* 0x43e1: jmp    1dc1 <vfs_writev_magic_return+0x1dc1> */
	return 7617ULL;
x86_l_43e6:
	/* 0x43e6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_43e9:
	/* 0x43e9: jne    309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12442ULL;
	}
x86_l_43ef:
	/* 0x43ef: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f4:
	/* 0x43f4: cmp    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_43f9:
	/* 0x43f9: je     309a <vfs_writev_magic_return+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12442ULL;
	}
x86_l_43ff:
	/* 0x43ff: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4403:
	/* 0x4403: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_440b:
	/* 0x440b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4410:
	/* 0x4410: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4415:
	/* 0x4415: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_441a:
	/* 0x441a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_441e:
	/* 0x441e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4423:
	/* 0x4423: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4425:
	/* 0x4425: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442a:
	/* 0x442a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442f:
	/* 0x442f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4434:
	/* 0x4434: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4439:
	/* 0x4439: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443e:
	/* 0x443e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4443:
	/* 0x4443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4445:
	/* 0x4445: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444a:
	/* 0x444a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_444f:
	/* 0x444f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4454:
	/* 0x4454: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4459:
	/* 0x4459: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_445e:
	/* 0x445e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4463:
	/* 0x4463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4465:
	/* 0x4465: jmp    309a <vfs_writev_magic_return+0x309a> */
	return 12442ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_vfs_writev_magic_return_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 14784U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2259ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2262ULL && __x86_pc <= 4115ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 4120ULL && __x86_pc <= 5807ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5811ULL && __x86_pc <= 7646ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7652ULL && __x86_pc <= 9572ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9577ULL && __x86_pc <= 11236ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11239ULL && __x86_pc <= 12921ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12926ULL && __x86_pc <= 14666ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14671ULL && __x86_pc <= 16411ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16416ULL && __x86_pc <= 17509ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

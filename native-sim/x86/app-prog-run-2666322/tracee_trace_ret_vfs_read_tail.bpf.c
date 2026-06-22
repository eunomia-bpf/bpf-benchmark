extern char args_map;
extern char bufs;
extern char config_map;
extern char containers_map;
extern char elf_files_map;
extern char event_data_map;
extern char file_read_path_filter;
extern char file_type_filter;
extern char io_file_path_cache_map;
extern char ksymbols_map;
extern char logs;
extern char logs_count;
extern char proc_info_map;
extern char prog_array;
extern char scratch_map;
extern char sys_32_to_64_map;
extern char task_info_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static const __u64 __x86_rodata_0[2] = {8464849087293777967ULL, 8588143708369942382ULL};

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 30ULL: goto x86_l_1e;
	case 32ULL: goto x86_l_20;
	case 35ULL: goto x86_l_23;
	case 40ULL: goto x86_l_28;
	case 45ULL: goto x86_l_2d;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 59ULL: goto x86_l_3b;
	case 62ULL: goto x86_l_3e;
	case 68ULL: goto x86_l_44;
	case 76ULL: goto x86_l_4c;
	case 79ULL: goto x86_l_4f;
	case 83ULL: goto x86_l_53;
	case 91ULL: goto x86_l_5b;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 102ULL: goto x86_l_66;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 124ULL: goto x86_l_7c;
	case 129ULL: goto x86_l_81;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 141ULL: goto x86_l_8d;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 204ULL: goto x86_l_cc;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 236ULL: goto x86_l_ec;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 245ULL: goto x86_l_f5;
	case 249ULL: goto x86_l_f9;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 270ULL: goto x86_l_10e;
	case 273ULL: goto x86_l_111;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 292ULL: goto x86_l_124;
	case 297ULL: goto x86_l_129;
	case 304ULL: goto x86_l_130;
	case 309ULL: goto x86_l_135;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 328ULL: goto x86_l_148;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 365ULL: goto x86_l_16d;
	case 374ULL: goto x86_l_176;
	case 386ULL: goto x86_l_182;
	case 398ULL: goto x86_l_18e;
	case 410ULL: goto x86_l_19a;
	case 422ULL: goto x86_l_1a6;
	case 434ULL: goto x86_l_1b2;
	case 446ULL: goto x86_l_1be;
	case 458ULL: goto x86_l_1ca;
	case 470ULL: goto x86_l_1d6;
	case 478ULL: goto x86_l_1de;
	case 487ULL: goto x86_l_1e7;
	case 496ULL: goto x86_l_1f0;
	case 505ULL: goto x86_l_1f9;
	case 514ULL: goto x86_l_202;
	case 523ULL: goto x86_l_20b;
	case 532ULL: goto x86_l_214;
	case 541ULL: goto x86_l_21d;
	case 550ULL: goto x86_l_226;
	case 559ULL: goto x86_l_22f;
	case 568ULL: goto x86_l_238;
	case 577ULL: goto x86_l_241;
	case 586ULL: goto x86_l_24a;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 602ULL: goto x86_l_25a;
	case 607ULL: goto x86_l_25f;
	case 611ULL: goto x86_l_263;
	case 616ULL: goto x86_l_268;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 659ULL: goto x86_l_293;
	case 663ULL: goto x86_l_297;
	case 668ULL: goto x86_l_29c;
	case 675ULL: goto x86_l_2a3;
	case 680ULL: goto x86_l_2a8;
	case 682ULL: goto x86_l_2aa;
	case 685ULL: goto x86_l_2ad;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 711ULL: goto x86_l_2c7;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 724ULL: goto x86_l_2d4;
	case 727ULL: goto x86_l_2d7;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 759ULL: goto x86_l_2f7;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 803ULL: goto x86_l_323;
	case 807ULL: goto x86_l_327;
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
	case 1130ULL: goto x86_l_46a;
	case 1141ULL: goto x86_l_475;
	case 1149ULL: goto x86_l_47d;
	case 1157ULL: goto x86_l_485;
	case 1165ULL: goto x86_l_48d;
	case 1173ULL: goto x86_l_495;
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
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1310ULL: goto x86_l_51e;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1318ULL: goto x86_l_526;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1337ULL: goto x86_l_539;
	case 1344ULL: goto x86_l_540;
	case 1348ULL: goto x86_l_544;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1403ULL: goto x86_l_57b;
	case 1414ULL: goto x86_l_586;
	case 1425ULL: goto x86_l_591;
	case 1436ULL: goto x86_l_59c;
	case 1447ULL: goto x86_l_5a7;
	case 1458ULL: goto x86_l_5b2;
	case 1469ULL: goto x86_l_5bd;
	case 1480ULL: goto x86_l_5c8;
	case 1491ULL: goto x86_l_5d3;
	case 1499ULL: goto x86_l_5db;
	case 1507ULL: goto x86_l_5e3;
	case 1515ULL: goto x86_l_5eb;
	case 1523ULL: goto x86_l_5f3;
	case 1531ULL: goto x86_l_5fb;
	case 1539ULL: goto x86_l_603;
	case 1547ULL: goto x86_l_60b;
	case 1555ULL: goto x86_l_613;
	case 1563ULL: goto x86_l_61b;
	case 1571ULL: goto x86_l_623;
	case 1579ULL: goto x86_l_62b;
	case 1587ULL: goto x86_l_633;
	case 1595ULL: goto x86_l_63b;
	case 1603ULL: goto x86_l_643;
	case 1611ULL: goto x86_l_64b;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1674ULL: goto x86_l_68a;
	case 1677ULL: goto x86_l_68d;
	case 1685ULL: goto x86_l_695;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1711ULL: goto x86_l_6af;
	case 1716ULL: goto x86_l_6b4;
	case 1724ULL: goto x86_l_6bc;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1784ULL: goto x86_l_6f8;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
	case 1817ULL: goto x86_l_719;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1874ULL: goto x86_l_752;
	case 1878ULL: goto x86_l_756;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1977ULL: goto x86_l_7b9;
	case 1979ULL: goto x86_l_7bb;
	case 1983ULL: goto x86_l_7bf;
	case 1987ULL: goto x86_l_7c3;
	case 1991ULL: goto x86_l_7c7;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2016ULL: goto x86_l_7e0;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2064ULL: goto x86_l_810;
	case 2068ULL: goto x86_l_814;
	case 2072ULL: goto x86_l_818;
	case 2076ULL: goto x86_l_81c;
	case 2080ULL: goto x86_l_820;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2106ULL: goto x86_l_83a;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2127ULL: goto x86_l_84f;
	case 2135ULL: goto x86_l_857;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
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
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: movabs rbx,0x2d200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3100966387712ULL);
x86_l_17:
	/* 0x17: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c:
	/* 0x1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e:
	/* 0x1e: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20:
	/* 0x20: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_23:
	/* 0x23: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28:
	/* 0x28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d:
	/* 0x2d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_34:
	/* 0x34: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39:
	/* 0x39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b:
	/* 0x3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_44:
	/* 0x44: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4c:
	/* 0x4c: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f:
	/* 0x4f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53:
	/* 0x53: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5b:
	/* 0x5b: mov    r15,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_64:
	/* 0x64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66:
	/* 0x66: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_68:
	/* 0x68: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70:
	/* 0x70: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_75:
	/* 0x75: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_7c:
	/* 0x7c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_81:
	/* 0x81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83:
	/* 0x83: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_88:
	/* 0x88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a:
	/* 0x8a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9b:
	/* 0x9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a0:
	/* 0xa0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a5:
	/* 0xa5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_aa:
	/* 0xaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac:
	/* 0xac: test   DWORD PTR [rsp+0x50],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343599480832ULL);
x86_l_b4:
	/* 0xb4: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_b9:
	/* 0xb9: jne    11c <trace_ret_vfs_read_tail+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11c;
	}
x86_l_bb:
	/* 0xbb: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_c0:
	/* 0xc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2:
	/* 0xc2: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_c7:
	/* 0xc7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cc:
	/* 0xcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: je     d6 <trace_ret_vfs_read_tail+0xd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6;
	}
x86_l_d1:
	/* 0xd1: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d4:
	/* 0xd4: jmp    d6 <trace_ret_vfs_read_tail+0xd6> */
	goto x86_l_d6;
x86_l_d6:
	/* 0xd6: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_da:
	/* 0xda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_df:
	/* 0xdf: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e4:
	/* 0xe4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e9:
	/* 0xe9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ec:
	/* 0xec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee:
	/* 0xee: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_f3:
	/* 0xf3: jne    fb <trace_ret_vfs_read_tail+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fb;
	}
x86_l_f5:
	/* 0xf5: mov    ebx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f9:
	/* 0xf9: jmp    11c <trace_ret_vfs_read_tail+0x11c> */
	goto x86_l_11c;
x86_l_fb:
	/* 0xfb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_100:
	/* 0x100: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_107:
	/* 0x107: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10c:
	/* 0x10c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e:
	/* 0x10e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: je     117 <trace_ret_vfs_read_tail+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117;
	}
x86_l_113:
	/* 0x113: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115:
	/* 0x115: jmp    11c <trace_ret_vfs_read_tail+0x11c> */
	goto x86_l_11c;
x86_l_117:
	/* 0x117: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_124:
	/* 0x124: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_129:
	/* 0x129: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_130:
	/* 0x130: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_135:
	/* 0x135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137:
	/* 0x137: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13a:
	/* 0x13a: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_140:
	/* 0x140: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_143:
	/* 0x143: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_148:
	/* 0x148: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_14f:
	/* 0x14f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_154:
	/* 0x154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156:
	/* 0x156: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_15f:
	/* 0x15f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_162:
	/* 0x162: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_16d:
	/* 0x16d: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_182:
	/* 0x182: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [r12+0x7dd0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1de:
	/* 0x1de: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e7:
	/* 0x1e7: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f0:
	/* 0x1f0: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f9:
	/* 0x1f9: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_202:
	/* 0x202: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20b:
	/* 0x20b: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_214:
	/* 0x214: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_21d:
	/* 0x21d: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_226:
	/* 0x226: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_22f:
	/* 0x22f: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_238:
	/* 0x238: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_241:
	/* 0x241: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_24a:
	/* 0x24a: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_253:
	/* 0x253: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_258:
	/* 0x258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a:
	/* 0x25a: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25f:
	/* 0x25f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_263:
	/* 0x263: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_268:
	/* 0x268: mov    DWORD PTR [r12+0x70],0x31b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337947ULL);
x86_l_271:
	/* 0x271: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_276:
	/* 0x276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278:
	/* 0x278: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c:
	/* 0x27c: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_281:
	/* 0x281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283:
	/* 0x283: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_289:
	/* 0x289: mov    DWORD PTR [r12+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_28e:
	/* 0x28e: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_293:
	/* 0x293: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_297:
	/* 0x297: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29c:
	/* 0x29c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2a3:
	/* 0x2a3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a8:
	/* 0x2a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa:
	/* 0x2aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ad:
	/* 0x2ad: je     2f4 <trace_ret_vfs_read_tail+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4;
	}
x86_l_2af:
	/* 0x2af: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b4:
	/* 0x2b4: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2bb:
	/* 0x2bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c0:
	/* 0x2c0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2c7:
	/* 0x2c7: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2cf:
	/* 0x2cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1:
	/* 0x2d1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2d4:
	/* 0x2d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: je     534 <trace_ret_vfs_read_tail+0x534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_534;
	}
x86_l_2dd:
	/* 0x2dd: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2e2:
	/* 0x2e2: jne    a98 <trace_ret_vfs_read_tail+0xa98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2712ULL;
	}
x86_l_2e8:
	/* 0x2e8: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2ed:
	/* 0x2ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef:
	/* 0x2ef: jmp    b20 <trace_ret_vfs_read_tail+0xb20> */
	return 2848ULL;
x86_l_2f4:
	/* 0x2f4: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_2f7:
	/* 0x2f7: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb:
	/* 0x2fb: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ff:
	/* 0x2ff: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_307:
	/* 0x307: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30c:
	/* 0x30c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_313:
	/* 0x313: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_318:
	/* 0x318: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a:
	/* 0x31a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31d:
	/* 0x31d: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_323:
	/* 0x323: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_327:
	/* 0x327: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_32b:
	/* 0x32b: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_336:
	/* 0x336: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_341:
	/* 0x341: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_34c:
	/* 0x34c: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_357:
	/* 0x357: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_362:
	/* 0x362: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_36d:
	/* 0x36d: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_378:
	/* 0x378: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3d0:
	/* 0x3d0: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_47d:
	/* 0x47d: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_485:
	/* 0x485: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_48d:
	/* 0x48d: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_495:
	/* 0x495: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4a5:
	/* 0x4a5: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4ad:
	/* 0x4ad: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4b5:
	/* 0x4b5: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4bd:
	/* 0x4bd: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4cd:
	/* 0x4cd: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d5:
	/* 0x4d5: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e5:
	/* 0x4e5: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f4:
	/* 0x4f4: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4fa:
	/* 0x4fa: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_501:
	/* 0x501: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_506:
	/* 0x506: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_50b:
	/* 0x50b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_50e:
	/* 0x50e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_514:
	/* 0x514: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_519:
	/* 0x519: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_51e:
	/* 0x51e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_521:
	/* 0x521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_523:
	/* 0x523: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_526:
	/* 0x526: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_529:
	/* 0x529: jne    2af <trace_ret_vfs_read_tail+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af;
	}
x86_l_52f:
	/* 0x52f: jmp    1c88 <trace_ret_vfs_read_tail+0x1c88> */
	return 7304ULL;
x86_l_534:
	/* 0x534: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_539:
	/* 0x539: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_540:
	/* 0x540: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_544:
	/* 0x544: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_54c:
	/* 0x54c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_551:
	/* 0x551: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_558:
	/* 0x558: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55d:
	/* 0x55d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f:
	/* 0x55f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_562:
	/* 0x562: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_568:
	/* 0x568: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56c:
	/* 0x56c: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_591:
	/* 0x591: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5b2:
	/* 0x5b2: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5db:
	/* 0x5db: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5e3:
	/* 0x5e3: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5eb:
	/* 0x5eb: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5f3:
	/* 0x5f3: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5fb:
	/* 0x5fb: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_603:
	/* 0x603: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_60b:
	/* 0x60b: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_613:
	/* 0x613: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_61b:
	/* 0x61b: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_63b:
	/* 0x63b: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_643:
	/* 0x643: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_64b:
	/* 0x64b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_652:
	/* 0x652: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_658:
	/* 0x658: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_65f:
	/* 0x65f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_664:
	/* 0x664: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_669:
	/* 0x669: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_66c:
	/* 0x66c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66f:
	/* 0x66f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_672:
	/* 0x672: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_677:
	/* 0x677: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_67c:
	/* 0x67c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681:
	/* 0x681: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_684:
	/* 0x684: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_68a:
	/* 0x68a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_68d:
	/* 0x68d: mov    rbx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_695:
	/* 0x695: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_699:
	/* 0x699: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_69e:
	/* 0x69e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a3:
	/* 0x6a3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6a8:
	/* 0x6a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ad:
	/* 0x6ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6af:
	/* 0x6af: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6b4:
	/* 0x6b4: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_6bc:
	/* 0x6bc: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c0:
	/* 0x6c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c5:
	/* 0x6c5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ca:
	/* 0x6ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6cf:
	/* 0x6cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d1:
	/* 0x6d1: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6d6:
	/* 0x6d6: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6da:
	/* 0x6da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6df:
	/* 0x6df: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6e4:
	/* 0x6e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e9:
	/* 0x6e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6eb:
	/* 0x6eb: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_6f8:
	/* 0x6f8: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6fc:
	/* 0x6fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_701:
	/* 0x701: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_706:
	/* 0x706: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_70b:
	/* 0x70b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70d:
	/* 0x70d: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_711:
	/* 0x711: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_714:
	/* 0x714: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_719:
	/* 0x719: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_71d:
	/* 0x71d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_722:
	/* 0x722: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_727:
	/* 0x727: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_72c:
	/* 0x72c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_731:
	/* 0x731: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_736:
	/* 0x736: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73b:
	/* 0x73b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_740:
	/* 0x740: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_745:
	/* 0x745: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_748:
	/* 0x748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74a:
	/* 0x74a: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_74e:
	/* 0x74e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_752:
	/* 0x752: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_756:
	/* 0x756: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_75a:
	/* 0x75a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75f:
	/* 0x75f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_764:
	/* 0x764: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_76f:
	/* 0x76f: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_772:
	/* 0x772: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_777:
	/* 0x777: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_77c:
	/* 0x77c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_781:
	/* 0x781: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_786:
	/* 0x786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_788:
	/* 0x788: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78d:
	/* 0x78d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_791:
	/* 0x791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_796:
	/* 0x796: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_79b:
	/* 0x79b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a0:
	/* 0x7a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a2:
	/* 0x7a2: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ac:
	/* 0x7ac: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b1:
	/* 0x7b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7b9:
	/* 0x7b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bb:
	/* 0x7bb: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7bf:
	/* 0x7bf: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7c3:
	/* 0x7c3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_7c7:
	/* 0x7c7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7cb:
	/* 0x7cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d0:
	/* 0x7d0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7d5:
	/* 0x7d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7e0:
	/* 0x7e0: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e3:
	/* 0x7e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e8:
	/* 0x7e8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7ed:
	/* 0x7ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f2:
	/* 0x7f2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7f5:
	/* 0x7f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f7:
	/* 0x7f7: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7fc:
	/* 0x7fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_801:
	/* 0x801: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_806:
	/* 0x806: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_80b:
	/* 0x80b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_80e:
	/* 0x80e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_810:
	/* 0x810: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_814:
	/* 0x814: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_818:
	/* 0x818: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_81c:
	/* 0x81c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_820:
	/* 0x820: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_825:
	/* 0x825: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_82a:
	/* 0x82a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_82f:
	/* 0x82f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_831:
	/* 0x831: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_836:
	/* 0x836: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_83a:
	/* 0x83a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_83f:
	/* 0x83f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_844:
	/* 0x844: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_849:
	/* 0x849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84b:
	/* 0x84b: mov    ebx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_84f:
	/* 0x84f: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_857:
	/* 0x857: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_85b:
	/* 0x85b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_860:
	/* 0x860: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_865:
	/* 0x865: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_86f:
	/* 0x86f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_871:
	/* 0x871: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_876:
	/* 0x876: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2171ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2186ULL: goto x86_l_88a;
	case 2190ULL: goto x86_l_88e;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2296ULL: goto x86_l_8f8;
	case 2298ULL: goto x86_l_8fa;
	case 2302ULL: goto x86_l_8fe;
	case 2306ULL: goto x86_l_902;
	case 2310ULL: goto x86_l_906;
	case 2314ULL: goto x86_l_90a;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2371ULL: goto x86_l_943;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2457ULL: goto x86_l_999;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2468ULL: goto x86_l_9a4;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2506ULL: goto x86_l_9ca;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2571ULL: goto x86_l_a0b;
	case 2575ULL: goto x86_l_a0f;
	case 2579ULL: goto x86_l_a13;
	case 2587ULL: goto x86_l_a1b;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2649ULL: goto x86_l_a59;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2846ULL: goto x86_l_b1e;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2857ULL: goto x86_l_b29;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2900ULL: goto x86_l_b54;
	case 2902ULL: goto x86_l_b56;
	case 2908ULL: goto x86_l_b5c;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2925ULL: goto x86_l_b6d;
	case 2937ULL: goto x86_l_b79;
	case 2949ULL: goto x86_l_b85;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2968ULL: goto x86_l_b98;
	case 2972ULL: goto x86_l_b9c;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2995ULL: goto x86_l_bb3;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3020ULL: goto x86_l_bcc;
	case 3028ULL: goto x86_l_bd4;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3047ULL: goto x86_l_be7;
	case 3055ULL: goto x86_l_bef;
	case 3057ULL: goto x86_l_bf1;
	case 3059ULL: goto x86_l_bf3;
	case 3067ULL: goto x86_l_bfb;
	case 3076ULL: goto x86_l_c04;
	case 3085ULL: goto x86_l_c0d;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3128ULL: goto x86_l_c38;
	case 3130ULL: goto x86_l_c3a;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3153ULL: goto x86_l_c51;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3208ULL: goto x86_l_c88;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3247ULL: goto x86_l_caf;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3271ULL: goto x86_l_cc7;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3322ULL: goto x86_l_cfa;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3360ULL: goto x86_l_d20;
	case 3364ULL: goto x86_l_d24;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3452ULL: goto x86_l_d7c;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3481ULL: goto x86_l_d99;
	case 3486ULL: goto x86_l_d9e;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3505ULL: goto x86_l_db1;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3517ULL: goto x86_l_dbd;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3530ULL: goto x86_l_dca;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3578ULL: goto x86_l_dfa;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3595ULL: goto x86_l_e0b;
	case 3600ULL: goto x86_l_e10;
	case 3602ULL: goto x86_l_e12;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3650ULL: goto x86_l_e42;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3704ULL: goto x86_l_e78;
	case 3709ULL: goto x86_l_e7d;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3735ULL: goto x86_l_e97;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3806ULL: goto x86_l_ede;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	default: return 0xffffffffffffffffULL;
	}
x86_l_87b:
	/* 0x87b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_880:
	/* 0x880: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_885:
	/* 0x885: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_888:
	/* 0x888: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88a:
	/* 0x88a: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_88e:
	/* 0x88e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_892:
	/* 0x892: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_896:
	/* 0x896: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_89a:
	/* 0x89a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89f:
	/* 0x89f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8a4:
	/* 0x8a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a9:
	/* 0x8a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ab:
	/* 0x8ab: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8b0:
	/* 0x8b0: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8b4:
	/* 0x8b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b9:
	/* 0x8b9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8be:
	/* 0x8be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: cmp    ebx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 80ULL);
x86_l_8c9:
	/* 0x8c9: jne    922 <trace_ret_vfs_read_tail+0x922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_922;
	}
x86_l_8cb:
	/* 0x8cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d0:
	/* 0x8d0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8d5:
	/* 0x8d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8da:
	/* 0x8da: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8df:
	/* 0x8df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e1:
	/* 0x8e1: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e6:
	/* 0x8e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8eb:
	/* 0x8eb: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f0:
	/* 0x8f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8f5:
	/* 0x8f5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8f8:
	/* 0x8f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fa:
	/* 0x8fa: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8fe:
	/* 0x8fe: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_902:
	/* 0x902: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_906:
	/* 0x906: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_90a:
	/* 0x90a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_90f:
	/* 0x90f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_914:
	/* 0x914: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_919:
	/* 0x919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91b:
	/* 0x91b: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_91f:
	/* 0x91f: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_922:
	/* 0x922: mov    DWORD PTR [rbp+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_925:
	/* 0x925: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_92a:
	/* 0x92a: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_931:
	/* 0x931: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_936:
	/* 0x936: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_93b:
	/* 0x93b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_940:
	/* 0x940: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_943:
	/* 0x943: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_94a:
	/* 0x94a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_94e:
	/* 0x94e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_953:
	/* 0x953: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_958:
	/* 0x958: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95d:
	/* 0x95d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95f:
	/* 0x95f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_964:
	/* 0x964: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_969:
	/* 0x969: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_96e:
	/* 0x96e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_973:
	/* 0x973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_975:
	/* 0x975: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_979:
	/* 0x979: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_97c:
	/* 0x97c: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_981:
	/* 0x981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_983:
	/* 0x983: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_986:
	/* 0x986: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_98a:
	/* 0x98a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_98f:
	/* 0x98f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_994:
	/* 0x994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_999:
	/* 0x999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99b:
	/* 0x99b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9a0:
	/* 0x9a0: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a4:
	/* 0x9a4: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_9ac:
	/* 0x9ac: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9b0:
	/* 0x9b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b5:
	/* 0x9b5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ba:
	/* 0x9ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bf:
	/* 0x9bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c1:
	/* 0x9c1: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9ca:
	/* 0x9ca: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_9d2:
	/* 0x9d2: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9d6:
	/* 0x9d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9db:
	/* 0x9db: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9e0:
	/* 0x9e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e5:
	/* 0x9e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e7:
	/* 0x9e7: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ec:
	/* 0x9ec: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f0:
	/* 0x9f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f5:
	/* 0x9f5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9fa:
	/* 0x9fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9ff:
	/* 0x9ff: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a02:
	/* 0xa02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a04:
	/* 0xa04: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_a09:
	/* 0xa09: je     a0f <trace_ret_vfs_read_tail+0xa0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a0f;
	}
x86_l_a0b:
	/* 0xa0b: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a0f:
	/* 0xa0f: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a13:
	/* 0xa13: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a1b:
	/* 0xa1b: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a23:
	/* 0xa23: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a28:
	/* 0xa28: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a2d:
	/* 0xa2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2f:
	/* 0xa2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a34:
	/* 0xa34: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a39:
	/* 0xa39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3e:
	/* 0xa3e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a41:
	/* 0xa41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a43:
	/* 0xa43: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a48:
	/* 0xa48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a4d:
	/* 0xa4d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a52:
	/* 0xa52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a57:
	/* 0xa57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a59:
	/* 0xa59: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a5e:
	/* 0xa5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a63:
	/* 0xa63: lea    r13,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a68:
	/* 0xa68: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a70:
	/* 0xa70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a72:
	/* 0xa72: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_a75:
	/* 0xa75: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_a79:
	/* 0xa79: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_a7e:
	/* 0xa7e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a83:
	/* 0xa83: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a86:
	/* 0xa86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a88:
	/* 0xa88: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a8d:
	/* 0xa8d: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a92:
	/* 0xa92: je     2e8 <trace_ret_vfs_read_tail+0x2e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 744ULL;
	}
x86_l_a98:
	/* 0xa98: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a9d:
	/* 0xa9d: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_aa5:
	/* 0xaa5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aaa:
	/* 0xaaa: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aaf:
	/* 0xaaf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab4:
	/* 0xab4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab6:
	/* 0xab6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_abb:
	/* 0xabb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ac0:
	/* 0xac0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ac5:
	/* 0xac5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ad1:
	/* 0xad1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad6:
	/* 0xad6: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_adb:
	/* 0xadb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae0:
	/* 0xae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae2:
	/* 0xae2: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ae7:
	/* 0xae7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aec:
	/* 0xaec: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af1:
	/* 0xaf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af6:
	/* 0xaf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af8:
	/* 0xaf8: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_afd:
	/* 0xafd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b00:
	/* 0xb00: je     b1e <trace_ret_vfs_read_tail+0xb1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1e;
	}
x86_l_b02:
	/* 0xb02: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b06:
	/* 0xb06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b0b:
	/* 0xb0b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b10:
	/* 0xb10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b15:
	/* 0xb15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b17:
	/* 0xb17: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b1c:
	/* 0xb1c: jmp    b20 <trace_ret_vfs_read_tail+0xb20> */
	goto x86_l_b20;
x86_l_b1e:
	/* 0xb1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b20:
	/* 0xb20: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b25:
	/* 0xb25: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b29:
	/* 0xb29: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b2d:
	/* 0xb2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b32:
	/* 0xb32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b39:
	/* 0xb39: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b3e:
	/* 0xb3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b40:
	/* 0xb40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: je     b5c <trace_ret_vfs_read_tail+0xb5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5c;
	}
x86_l_b45:
	/* 0xb45: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b48:
	/* 0xb48: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_b4e:
	/* 0xb4e: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_b51:
	/* 0xb51: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b54:
	/* 0xb54: jne    b5c <trace_ret_vfs_read_tail+0xb5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5c;
	}
x86_l_b56:
	/* 0xb56: or     BYTE PTR [r12+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_b5c:
	/* 0xb5c: movzx  eax,WORD PTR [r12+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_b62:
	/* 0xb62: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_b67:
	/* 0xb67: jne    2033 <trace_ret_vfs_read_tail+0x2033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8243ULL;
	}
x86_l_b6d:
	/* 0xb6d: mov    QWORD PTR [r12+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_b79:
	/* 0xb79: mov    QWORD PTR [r12+0x80],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781183ULL);
x86_l_b85:
	/* 0xb85: test   BYTE PTR [r14+0x5],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836481ULL);
x86_l_b8a:
	/* 0xb8a: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7304ULL;
	}
x86_l_b90:
	/* 0xb90: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b98:
	/* 0xb98: mov    rbx,QWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b9c:
	/* 0xb9c: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_ba8:
	/* 0xba8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rsp+0xc0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_bb3:
	/* 0xbb3: je     bf1 <trace_ret_vfs_read_tail+0xbf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf1;
	}
x86_l_bb5:
	/* 0xbb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bba:
	/* 0xbba: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bc2:
	/* 0xbc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc7:
	/* 0xbc7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_bca:
	/* 0xbca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcc:
	/* 0xbcc: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bd4:
	/* 0xbd4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_bd7:
	/* 0xbd7: je     bf1 <trace_ret_vfs_read_tail+0xbf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf1;
	}
x86_l_bd9:
	/* 0xbd9: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_bdc:
	/* 0xbdc: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_be7:
	/* 0xbe7: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bef:
	/* 0xbef: jmp    bfb <trace_ret_vfs_read_tail+0xbfb> */
	goto x86_l_bfb;
x86_l_bf1:
	/* 0xbf1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf3:
	/* 0xbf3: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_bfb:
	/* 0xbfb: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_c04:
	/* 0xc04: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_c0d:
	/* 0xc0d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_c16:
	/* 0xc16: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c19:
	/* 0xc19: je     d63 <trace_ret_vfs_read_tail+0xd63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d63;
	}
x86_l_c1f:
	/* 0xc1f: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_c22:
	/* 0xc22: lea    r14,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c26:
	/* 0xc26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c2b:
	/* 0xc2b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c30:
	/* 0xc30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c35:
	/* 0xc35: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c38:
	/* 0xc38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3a:
	/* 0xc3a: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_c43:
	/* 0xc43: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c48:
	/* 0xc48: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_c51:
	/* 0xc51: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c55:
	/* 0xc55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c5a:
	/* 0xc5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5f:
	/* 0xc5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c64:
	/* 0xc64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c66:
	/* 0xc66: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6b:
	/* 0xc6b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c70:
	/* 0xc70: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c74:
	/* 0xc74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c79:
	/* 0xc79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7e:
	/* 0xc7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c83:
	/* 0xc83: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c86:
	/* 0xc86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c88:
	/* 0xc88: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8c:
	/* 0xc8c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c91:
	/* 0xc91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c96:
	/* 0xc96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9b:
	/* 0xc9b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca0:
	/* 0xca0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca5:
	/* 0xca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca7:
	/* 0xca7: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cac:
	/* 0xcac: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_caf:
	/* 0xcaf: js     cd5 <trace_ret_vfs_read_tail+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_cd5;
	}
x86_l_cb1:
	/* 0xcb1: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cb6:
	/* 0xcb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cbb:
	/* 0xcbb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc0:
	/* 0xcc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cc5:
	/* 0xcc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc7:
	/* 0xcc7: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_cce:
	/* 0xcce: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_cd3:
	/* 0xcd3: jmp    cd7 <trace_ret_vfs_read_tail+0xcd7> */
	goto x86_l_cd7;
x86_l_cd5:
	/* 0xcd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd7:
	/* 0xcd7: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cdc:
	/* 0xcdc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce1:
	/* 0xce1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ce6:
	/* 0xce6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ceb:
	/* 0xceb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_cee:
	/* 0xcee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf0:
	/* 0xcf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cf5:
	/* 0xcf5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cfa:
	/* 0xcfa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cfe:
	/* 0xcfe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d03:
	/* 0xd03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d08:
	/* 0xd08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0a:
	/* 0xd0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0f:
	/* 0xd0f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d14:
	/* 0xd14: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d19:
	/* 0xd19: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d1e:
	/* 0xd1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d20:
	/* 0xd20: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d24:
	/* 0xd24: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d28:
	/* 0xd28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d2d:
	/* 0xd2d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d32:
	/* 0xd32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_d3a:
	/* 0xd3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3c:
	/* 0xd3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d41:
	/* 0xd41: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d46:
	/* 0xd46: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d4a:
	/* 0xd4a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d4f:
	/* 0xd4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d54:
	/* 0xd54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d56:
	/* 0xd56: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d5b:
	/* 0xd5b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d60:
	/* 0xd60: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_d63:
	/* 0xd63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d68:
	/* 0xd68: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_d6f:
	/* 0xd6f: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d74:
	/* 0xd74: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_d77:
	/* 0xd77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d79:
	/* 0xd79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d7c:
	/* 0xd7c: je     ea2 <trace_ret_vfs_read_tail+0xea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea2;
	}
x86_l_d82:
	/* 0xd82: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d85:
	/* 0xd85: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d8d:
	/* 0xd8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d92:
	/* 0xd92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_read_path_filter)));
x86_l_d99:
	/* 0xd99: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9e:
	/* 0xd9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da0:
	/* 0xda0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da3:
	/* 0xda3: je     23fb <trace_ret_vfs_read_tail+0x23fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9211ULL;
	}
x86_l_da9:
	/* 0xda9: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_dac:
	/* 0xdac: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_daf:
	/* 0xdaf: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_db1:
	/* 0xdb1: je     1012 <trace_ret_vfs_read_tail+0x1012> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4114ULL;
	}
x86_l_db7:
	/* 0xdb7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db9:
	/* 0xdb9: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_dbd:
	/* 0xdbd: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_dc3:
	/* 0xdc3: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_dc8:
	/* 0xdc8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_dca:
	/* 0xdca: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_dd0:
	/* 0xdd0: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_dd5:
	/* 0xdd5: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_ddb:
	/* 0xddb: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_de0:
	/* 0xde0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_de2:
	/* 0xde2: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_de8:
	/* 0xde8: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_ded:
	/* 0xded: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_df3:
	/* 0xdf3: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_df8:
	/* 0xdf8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_dfa:
	/* 0xdfa: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e00:
	/* 0xe00: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_e05:
	/* 0xe05: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e0b:
	/* 0xe0b: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_e10:
	/* 0xe10: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e12:
	/* 0xe12: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e18:
	/* 0xe18: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_e1d:
	/* 0xe1d: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e23:
	/* 0xe23: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_e28:
	/* 0xe28: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e2a:
	/* 0xe2a: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e30:
	/* 0xe30: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_e35:
	/* 0xe35: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e3b:
	/* 0xe3b: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_e40:
	/* 0xe40: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e42:
	/* 0xe42: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e48:
	/* 0xe48: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_e4d:
	/* 0xe4d: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e53:
	/* 0xe53: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_e58:
	/* 0xe58: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e5a:
	/* 0xe5a: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e60:
	/* 0xe60: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_e65:
	/* 0xe65: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e6b:
	/* 0xe6b: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_e70:
	/* 0xe70: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e72:
	/* 0xe72: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5481ULL;
	}
x86_l_e78:
	/* 0xe78: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_e7d:
	/* 0xe7d: jne    1150 <trace_ret_vfs_read_tail+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4432ULL;
	}
x86_l_e83:
	/* 0xe83: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_e86:
	/* 0xe86: je     1146 <trace_ret_vfs_read_tail+0x1146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4422ULL;
	}
x86_l_e8c:
	/* 0xe8c: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_e91:
	/* 0xe91: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_e95:
	/* 0xe95: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_e97:
	/* 0xe97: jne    db9 <trace_ret_vfs_read_tail+0xdb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_db9;
	}
x86_l_e9d:
	/* 0xe9d: jmp    1569 <trace_ret_vfs_read_tail+0x1569> */
	return 5481ULL;
x86_l_ea2:
	/* 0xea2: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_eaa:
	/* 0xeaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eaf:
	/* 0xeaf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_eb6:
	/* 0xeb6: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ebb:
	/* 0xebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebd:
	/* 0xebd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec0:
	/* 0xec0: je     1706 <trace_ret_vfs_read_tail+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5894ULL;
	}
x86_l_ec6:
	/* 0xec6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ec9:
	/* 0xec9: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecd:
	/* 0xecd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed2:
	/* 0xed2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ed7:
	/* 0xed7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_edc:
	/* 0xedc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ede:
	/* 0xede: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ee3:
	/* 0xee3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee8:
	/* 0xee8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eed:
	/* 0xeed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef2:
	/* 0xef2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ef7:
	/* 0xef7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_efc:
	/* 0xefc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efe:
	/* 0xefe: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_f03:
	/* 0xf03: jne    101a <trace_ret_vfs_read_tail+0x101a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4122ULL;
	}
x86_l_f09:
	/* 0xf09: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f0e:
	/* 0xf0e: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f12:
	/* 0xf12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f17:
	/* 0xf17: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f1c:
	/* 0xf1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f21:
	/* 0xf21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f23:
	/* 0xf23: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f28:
	/* 0xf28: lea    rax,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_f2c:
	/* 0xf2c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f31:
	/* 0xf31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f36:
	/* 0xf36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 3899ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3926ULL: goto x86_l_f56;
	case 3934ULL: goto x86_l_f5e;
	case 3937ULL: goto x86_l_f61;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3992ULL: goto x86_l_f98;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4040ULL: goto x86_l_fc8;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4087ULL: goto x86_l_ff7;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4142ULL: goto x86_l_102e;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4251ULL: goto x86_l_109b;
	case 4257ULL: goto x86_l_10a1;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4272ULL: goto x86_l_10b0;
	case 4280ULL: goto x86_l_10b8;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4311ULL: goto x86_l_10d7;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4321ULL: goto x86_l_10e1;
	case 4323ULL: goto x86_l_10e3;
	case 4328ULL: goto x86_l_10e8;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4366ULL: goto x86_l_110e;
	case 4369ULL: goto x86_l_1111;
	case 4371ULL: goto x86_l_1113;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4395ULL: goto x86_l_112b;
	case 4398ULL: goto x86_l_112e;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4412ULL: goto x86_l_113c;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4426ULL: goto x86_l_114a;
	case 4432ULL: goto x86_l_1150;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4501ULL: goto x86_l_1195;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4573ULL: goto x86_l_11dd;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4597ULL: goto x86_l_11f5;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4627ULL: goto x86_l_1213;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4669ULL: goto x86_l_123d;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4686ULL: goto x86_l_124e;
	case 4689ULL: goto x86_l_1251;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4733ULL: goto x86_l_127d;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4743ULL: goto x86_l_1287;
	case 4746ULL: goto x86_l_128a;
	case 4751ULL: goto x86_l_128f;
	case 4757ULL: goto x86_l_1295;
	case 4762ULL: goto x86_l_129a;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4794ULL: goto x86_l_12ba;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4846ULL: goto x86_l_12ee;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4873ULL: goto x86_l_1309;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4927ULL: goto x86_l_133f;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4939ULL: goto x86_l_134b;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4968ULL: goto x86_l_1368;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4982ULL: goto x86_l_1376;
	case 4988ULL: goto x86_l_137c;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5051ULL: goto x86_l_13bb;
	case 5057ULL: goto x86_l_13c1;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5110ULL: goto x86_l_13f6;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5147ULL: goto x86_l_141b;
	case 5153ULL: goto x86_l_1421;
	case 5158ULL: goto x86_l_1426;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5171ULL: goto x86_l_1433;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5188ULL: goto x86_l_1444;
	case 5193ULL: goto x86_l_1449;
	case 5195ULL: goto x86_l_144b;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5284ULL: goto x86_l_14a4;
	case 5289ULL: goto x86_l_14a9;
	case 5291ULL: goto x86_l_14ab;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5404ULL: goto x86_l_151c;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	case 5428ULL: goto x86_l_1534;
	case 5434ULL: goto x86_l_153a;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5450ULL: goto x86_l_154a;
	case 5455ULL: goto x86_l_154f;
	case 5459ULL: goto x86_l_1553;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5470ULL: goto x86_l_155e;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5607ULL: goto x86_l_15e7;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f3b:
	/* 0xf3b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f40:
	/* 0xf40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f45:
	/* 0xf45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f47:
	/* 0xf47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f4c:
	/* 0xf4c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f51:
	/* 0xf51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f56:
	/* 0xf56: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f5e:
	/* 0xf5e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f61:
	/* 0xf61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f63:
	/* 0xf63: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f68:
	/* 0xf68: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6d:
	/* 0xf6d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f71:
	/* 0xf71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f76:
	/* 0xf76: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f7b:
	/* 0xf7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f80:
	/* 0xf80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f82:
	/* 0xf82: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f87:
	/* 0xf87: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: je     102b <trace_ret_vfs_read_tail+0x102b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102b;
	}
x86_l_f90:
	/* 0xf90: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f95:
	/* 0xf95: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f98:
	/* 0xf98: je     102b <trace_ret_vfs_read_tail+0x102b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102b;
	}
x86_l_f9e:
	/* 0xf9e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fa2:
	/* 0xfa2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa7:
	/* 0xfa7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fac:
	/* 0xfac: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_fb1:
	/* 0xfb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb3:
	/* 0xfb3: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_fb7:
	/* 0xfb7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fbc:
	/* 0xfbc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fbe:
	/* 0xfbe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fc4:
	/* 0xfc4: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_fc6:
	/* 0xfc6: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_fc8:
	/* 0xfc8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_fce:
	/* 0xfce: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_fd3:
	/* 0xfd3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_fd8:
	/* 0xfd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fda:
	/* 0xfda: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fdd:
	/* 0xfdd: jl     16a5 <trace_ret_vfs_read_tail+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5797ULL;
	}
x86_l_fe3:
	/* 0xfe3: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_feb:
	/* 0xfeb: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ff0:
	/* 0xff0: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_ff7:
	/* 0xff7: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_ffd:
	/* 0xffd: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1000:
	/* 0x1000: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1005:
	/* 0x1005: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_100d:
	/* 0x100d: jmp    10a1 <trace_ret_vfs_read_tail+0x10a1> */
	goto x86_l_10a1;
x86_l_1012:
	/* 0x1012: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1015:
	/* 0x1015: jmp    1558 <trace_ret_vfs_read_tail+0x1558> */
	goto x86_l_1558;
x86_l_101a:
	/* 0x101a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_101f:
	/* 0x101f: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1026:
	/* 0x1026: jmp    16ce <trace_ret_vfs_read_tail+0x16ce> */
	return 5838ULL;
x86_l_102b:
	/* 0x102b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_102e:
	/* 0x102e: jne    16a5 <trace_ret_vfs_read_tail+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5797ULL;
	}
x86_l_1034:
	/* 0x1034: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1039:
	/* 0x1039: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_103e:
	/* 0x103e: je     16a5 <trace_ret_vfs_read_tail+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5797ULL;
	}
x86_l_1044:
	/* 0x1044: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_1047:
	/* 0x1047: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_104c:
	/* 0x104c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1051:
	/* 0x1051: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1056:
	/* 0x1056: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_105a:
	/* 0x105a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105f:
	/* 0x105f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1064:
	/* 0x1064: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1066:
	/* 0x1066: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_106b:
	/* 0x106b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1070:
	/* 0x1070: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1075:
	/* 0x1075: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107a:
	/* 0x107a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107c:
	/* 0x107c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1081:
	/* 0x1081: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1086:
	/* 0x1086: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_108b:
	/* 0x108b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1090:
	/* 0x1090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1092:
	/* 0x1092: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1097:
	/* 0x1097: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_109b:
	/* 0x109b: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_10a1:
	/* 0x10a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a6:
	/* 0x10a6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10ab:
	/* 0x10ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b0:
	/* 0x10b0: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10b8:
	/* 0x10b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ba:
	/* 0x10ba: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10bf:
	/* 0x10bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c4:
	/* 0x10c4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_10c8:
	/* 0x10c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10cd:
	/* 0x10cd: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10d2:
	/* 0x10d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d7:
	/* 0x10d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d9:
	/* 0x10d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10de:
	/* 0x10de: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10e1:
	/* 0x10e1: je     112b <trace_ret_vfs_read_tail+0x112b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112b;
	}
x86_l_10e3:
	/* 0x10e3: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10e8:
	/* 0x10e8: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10eb:
	/* 0x10eb: je     112b <trace_ret_vfs_read_tail+0x112b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112b;
	}
x86_l_10ed:
	/* 0x10ed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10f1:
	/* 0x10f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f6:
	/* 0x10f6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10fb:
	/* 0x10fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1100:
	/* 0x1100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1102:
	/* 0x1102: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1106:
	/* 0x1106: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1108:
	/* 0x1108: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_110e:
	/* 0x110e: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1111:
	/* 0x1111: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1113:
	/* 0x1113: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_1116:
	/* 0x1116: jae    126d <trace_ret_vfs_read_tail+0x126d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_126d;
	}
x86_l_111c:
	/* 0x111c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1121:
	/* 0x1121: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1126:
	/* 0x1126: jmp    1d66 <trace_ret_vfs_read_tail+0x1d66> */
	return 7526ULL;
x86_l_112b:
	/* 0x112b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_112e:
	/* 0x112e: je     12bc <trace_ret_vfs_read_tail+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bc;
	}
x86_l_1134:
	/* 0x1134: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1139:
	/* 0x1139: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_113c:
	/* 0x113c: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1141:
	/* 0x1141: jmp    1698 <trace_ret_vfs_read_tail+0x1698> */
	return 5784ULL;
x86_l_1146:
	/* 0x1146: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_114a:
	/* 0x114a: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1150:
	/* 0x1150: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1158:
	/* 0x1158: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_115d:
	/* 0x115d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_read_path_filter)));
x86_l_1164:
	/* 0x1164: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1169:
	/* 0x1169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116b:
	/* 0x116b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_116e:
	/* 0x116e: je     23e9 <trace_ret_vfs_read_tail+0x23e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9193ULL;
	}
x86_l_1174:
	/* 0x1174: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1177:
	/* 0x1177: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_117a:
	/* 0x117a: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_117c:
	/* 0x117c: je     1558 <trace_ret_vfs_read_tail+0x1558> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1558;
	}
x86_l_1182:
	/* 0x1182: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1184:
	/* 0x1184: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1188:
	/* 0x1188: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_118e:
	/* 0x118e: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1193:
	/* 0x1193: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1195:
	/* 0x1195: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_119b:
	/* 0x119b: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_11a0:
	/* 0x11a0: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_11a6:
	/* 0x11a6: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_11ab:
	/* 0x11ab: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_11ad:
	/* 0x11ad: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_11b3:
	/* 0x11b3: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_11b8:
	/* 0x11b8: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_11be:
	/* 0x11be: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_11c3:
	/* 0x11c3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_11c5:
	/* 0x11c5: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_11cb:
	/* 0x11cb: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_11d0:
	/* 0x11d0: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_11d6:
	/* 0x11d6: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_11db:
	/* 0x11db: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_11dd:
	/* 0x11dd: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_11e3:
	/* 0x11e3: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_11e8:
	/* 0x11e8: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_11ee:
	/* 0x11ee: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_11f3:
	/* 0x11f3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_11f5:
	/* 0x11f5: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_11fb:
	/* 0x11fb: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1200:
	/* 0x1200: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_1206:
	/* 0x1206: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_120b:
	/* 0x120b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_120d:
	/* 0x120d: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1213:
	/* 0x1213: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1218:
	/* 0x1218: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_121e:
	/* 0x121e: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1223:
	/* 0x1223: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1225:
	/* 0x1225: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_122b:
	/* 0x122b: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1230:
	/* 0x1230: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_1236:
	/* 0x1236: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_123b:
	/* 0x123b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_123d:
	/* 0x123d: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1243:
	/* 0x1243: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1248:
	/* 0x1248: jne    13c1 <trace_ret_vfs_read_tail+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c1;
	}
x86_l_124e:
	/* 0x124e: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1251:
	/* 0x1251: je     13b7 <trace_ret_vfs_read_tail+0x13b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b7;
	}
x86_l_1257:
	/* 0x1257: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_125c:
	/* 0x125c: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1260:
	/* 0x1260: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1262:
	/* 0x1262: jne    1184 <trace_ret_vfs_read_tail+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1184;
	}
x86_l_1268:
	/* 0x1268: jmp    1569 <trace_ret_vfs_read_tail+0x1569> */
	goto x86_l_1569;
x86_l_126d:
	/* 0x126d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1272:
	/* 0x1272: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1278:
	/* 0x1278: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_127d:
	/* 0x127d: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1280:
	/* 0x1280: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1285:
	/* 0x1285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1287:
	/* 0x1287: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_128a:
	/* 0x128a: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_128f:
	/* 0x128f: jl     1693 <trace_ret_vfs_read_tail+0x1693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5779ULL;
	}
x86_l_1295:
	/* 0x1295: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_129a:
	/* 0x129a: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_129e:
	/* 0x129e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_12a4:
	/* 0x12a4: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_12aa:
	/* 0x12aa: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12ad:
	/* 0x12ad: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b2:
	/* 0x12b2: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12ba:
	/* 0x12ba: jmp    1328 <trace_ret_vfs_read_tail+0x1328> */
	goto x86_l_1328;
x86_l_12bc:
	/* 0x12bc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c1:
	/* 0x12c1: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_12c6:
	/* 0x12c6: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_12c9:
	/* 0x12c9: je     14f3 <trace_ret_vfs_read_tail+0x14f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f3;
	}
x86_l_12cf:
	/* 0x12cf: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12d4:
	/* 0x12d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12d9:
	/* 0x12d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12de:
	/* 0x12de: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_12e2:
	/* 0x12e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e7:
	/* 0x12e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ec:
	/* 0x12ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ee:
	/* 0x12ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12f3:
	/* 0x12f3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f8:
	/* 0x12f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fd:
	/* 0x12fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1302:
	/* 0x1302: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1304:
	/* 0x1304: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1309:
	/* 0x1309: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130e:
	/* 0x130e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1313:
	/* 0x1313: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1318:
	/* 0x1318: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131a:
	/* 0x131a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131f:
	/* 0x131f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1323:
	/* 0x1323: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1328:
	/* 0x1328: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_132d:
	/* 0x132d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1332:
	/* 0x1332: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1337:
	/* 0x1337: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_133f:
	/* 0x133f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1341:
	/* 0x1341: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1346:
	/* 0x1346: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134b:
	/* 0x134b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_134f:
	/* 0x134f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1354:
	/* 0x1354: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1359:
	/* 0x1359: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135e:
	/* 0x135e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1360:
	/* 0x1360: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1365:
	/* 0x1365: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1368:
	/* 0x1368: je     14db <trace_ret_vfs_read_tail+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14db;
	}
x86_l_136e:
	/* 0x136e: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1373:
	/* 0x1373: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1376:
	/* 0x1376: je     14db <trace_ret_vfs_read_tail+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14db;
	}
x86_l_137c:
	/* 0x137c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1380:
	/* 0x1380: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1385:
	/* 0x1385: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_138a:
	/* 0x138a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_138f:
	/* 0x138f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1391:
	/* 0x1391: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1395:
	/* 0x1395: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1397:
	/* 0x1397: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_139d:
	/* 0x139d: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_13a0:
	/* 0x13a0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13a2:
	/* 0x13a2: jae    1502 <trace_ret_vfs_read_tail+0x1502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1502;
	}
x86_l_13a8:
	/* 0x13a8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13ad:
	/* 0x13ad: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13b2:
	/* 0x13b2: jmp    1d66 <trace_ret_vfs_read_tail+0x1d66> */
	return 7526ULL;
x86_l_13b7:
	/* 0x13b7: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_13bb:
	/* 0x13bb: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_13c1:
	/* 0x13c1: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_13c9:
	/* 0x13c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ce:
	/* 0x13ce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_read_path_filter)));
x86_l_13d5:
	/* 0x13d5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13da:
	/* 0x13da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dc:
	/* 0x13dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13df:
	/* 0x13df: je     23e9 <trace_ret_vfs_read_tail+0x23e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9193ULL;
	}
x86_l_13e5:
	/* 0x13e5: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_13e8:
	/* 0x13e8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_13ea:
	/* 0x13ea: je     1558 <trace_ret_vfs_read_tail+0x1558> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1558;
	}
x86_l_13f0:
	/* 0x13f0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f2:
	/* 0x13f2: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13f6:
	/* 0x13f6: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_13fc:
	/* 0x13fc: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1401:
	/* 0x1401: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1403:
	/* 0x1403: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1409:
	/* 0x1409: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_140e:
	/* 0x140e: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_1414:
	/* 0x1414: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1419:
	/* 0x1419: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_141b:
	/* 0x141b: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1421:
	/* 0x1421: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1426:
	/* 0x1426: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_142c:
	/* 0x142c: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1431:
	/* 0x1431: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1433:
	/* 0x1433: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1439:
	/* 0x1439: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_143e:
	/* 0x143e: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_1444:
	/* 0x1444: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1449:
	/* 0x1449: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_144b:
	/* 0x144b: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1451:
	/* 0x1451: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1456:
	/* 0x1456: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_145c:
	/* 0x145c: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1461:
	/* 0x1461: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1463:
	/* 0x1463: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1469:
	/* 0x1469: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_146e:
	/* 0x146e: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_1474:
	/* 0x1474: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1479:
	/* 0x1479: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_147b:
	/* 0x147b: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1481:
	/* 0x1481: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1486:
	/* 0x1486: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_148c:
	/* 0x148c: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1491:
	/* 0x1491: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1493:
	/* 0x1493: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1499:
	/* 0x1499: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_149e:
	/* 0x149e: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_14a4:
	/* 0x14a4: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_14a9:
	/* 0x14a9: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_14ab:
	/* 0x14ab: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_14b1:
	/* 0x14b1: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_14b6:
	/* 0x14b6: jne    1555 <trace_ret_vfs_read_tail+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1555;
	}
x86_l_14bc:
	/* 0x14bc: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_14bf:
	/* 0x14bf: je     154f <trace_ret_vfs_read_tail+0x154f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_154f;
	}
x86_l_14c5:
	/* 0x14c5: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_14ca:
	/* 0x14ca: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_14ce:
	/* 0x14ce: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_14d0:
	/* 0x14d0: jne    13f2 <trace_ret_vfs_read_tail+0x13f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13f2;
	}
x86_l_14d6:
	/* 0x14d6: jmp    1569 <trace_ret_vfs_read_tail+0x1569> */
	goto x86_l_1569;
x86_l_14db:
	/* 0x14db: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14de:
	/* 0x14de: je     1571 <trace_ret_vfs_read_tail+0x1571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1571;
	}
x86_l_14e4:
	/* 0x14e4: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14e9:
	/* 0x14e9: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14ee:
	/* 0x14ee: jmp    1698 <trace_ret_vfs_read_tail+0x1698> */
	return 5784ULL;
x86_l_14f3:
	/* 0x14f3: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f8:
	/* 0x14f8: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14fd:
	/* 0x14fd: jmp    1698 <trace_ret_vfs_read_tail+0x1698> */
	return 5784ULL;
x86_l_1502:
	/* 0x1502: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1507:
	/* 0x1507: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_150d:
	/* 0x150d: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1512:
	/* 0x1512: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1515:
	/* 0x1515: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_151a:
	/* 0x151a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151c:
	/* 0x151c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_151f:
	/* 0x151f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1524:
	/* 0x1524: jl     1693 <trace_ret_vfs_read_tail+0x1693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5779ULL;
	}
x86_l_152a:
	/* 0x152a: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_152e:
	/* 0x152e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1534:
	/* 0x1534: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_153a:
	/* 0x153a: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_153d:
	/* 0x153d: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1542:
	/* 0x1542: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_154a:
	/* 0x154a: jmp    15d5 <trace_ret_vfs_read_tail+0x15d5> */
	goto x86_l_15d5;
x86_l_154f:
	/* 0x154f: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_1553:
	/* 0x1553: je     1569 <trace_ret_vfs_read_tail+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1569;
	}
x86_l_1555:
	/* 0x1555: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1558:
	/* 0x1558: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_155b:
	/* 0x155b: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_155e:
	/* 0x155e: jne    1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7304ULL;
	}
x86_l_1564:
	/* 0x1564: jmp    1706 <trace_ret_vfs_read_tail+0x1706> */
	return 5894ULL;
x86_l_1569:
	/* 0x1569: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_156c:
	/* 0x156c: jmp    1706 <trace_ret_vfs_read_tail+0x1706> */
	return 5894ULL;
x86_l_1571:
	/* 0x1571: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1576:
	/* 0x1576: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_157b:
	/* 0x157b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1580:
	/* 0x1580: je     1693 <trace_ret_vfs_read_tail+0x1693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5779ULL;
	}
x86_l_1586:
	/* 0x1586: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_158b:
	/* 0x158b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1590:
	/* 0x1590: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1594:
	/* 0x1594: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1599:
	/* 0x1599: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_159e:
	/* 0x159e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a0:
	/* 0x15a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15a5:
	/* 0x15a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15aa:
	/* 0x15aa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15af:
	/* 0x15af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15b4:
	/* 0x15b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b6:
	/* 0x15b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15bb:
	/* 0x15bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c0:
	/* 0x15c0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15c5:
	/* 0x15c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ca:
	/* 0x15ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cc:
	/* 0x15cc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d1:
	/* 0x15d1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15d5:
	/* 0x15d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15da:
	/* 0x15da: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15df:
	/* 0x15df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15e4:
	/* 0x15e4: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_15e7:
	/* 0x15e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e9:
	/* 0x15e9: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15ee:
	/* 0x15ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15f3:
	/* 0x15f3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_15f7:
	/* 0x15f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15fc:
	/* 0x15fc: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1601:
	/* 0x1601: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1606:
	/* 0x1606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1608:
	/* 0x1608: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 5645ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5654ULL: goto x86_l_1616;
	case 5659ULL: goto x86_l_161b;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5693ULL: goto x86_l_163d;
	case 5695ULL: goto x86_l_163f;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5706ULL: goto x86_l_164a;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5744ULL: goto x86_l_1670;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5791ULL: goto x86_l_169f;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5848ULL: goto x86_l_16d8;
	case 5851ULL: goto x86_l_16db;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5894ULL: goto x86_l_1706;
	case 5903ULL: goto x86_l_170f;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5930ULL: goto x86_l_172a;
	case 5933ULL: goto x86_l_172d;
	case 5939ULL: goto x86_l_1733;
	case 5942ULL: goto x86_l_1736;
	case 5945ULL: goto x86_l_1739;
	case 5951ULL: goto x86_l_173f;
	case 5956ULL: goto x86_l_1744;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5970ULL: goto x86_l_1752;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6012ULL: goto x86_l_177c;
	case 6018ULL: goto x86_l_1782;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6039ULL: goto x86_l_1797;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6150ULL: goto x86_l_1806;
	case 6162ULL: goto x86_l_1812;
	case 6171ULL: goto x86_l_181b;
	case 6180ULL: goto x86_l_1824;
	case 6189ULL: goto x86_l_182d;
	case 6198ULL: goto x86_l_1836;
	case 6207ULL: goto x86_l_183f;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6253ULL: goto x86_l_186d;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6261ULL: goto x86_l_1875;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6276ULL: goto x86_l_1884;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6290ULL: goto x86_l_1892;
	case 6296ULL: goto x86_l_1898;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6305ULL: goto x86_l_18a1;
	case 6308ULL: goto x86_l_18a4;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6318ULL: goto x86_l_18ae;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6359ULL: goto x86_l_18d7;
	case 6364ULL: goto x86_l_18dc;
	case 6366ULL: goto x86_l_18de;
	case 6369ULL: goto x86_l_18e1;
	case 6375ULL: goto x86_l_18e7;
	case 6378ULL: goto x86_l_18ea;
	case 6382ULL: goto x86_l_18ee;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6404ULL: goto x86_l_1904;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6423ULL: goto x86_l_1917;
	case 6426ULL: goto x86_l_191a;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6436ULL: goto x86_l_1924;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6457ULL: goto x86_l_1939;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6495ULL: goto x86_l_195f;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6530ULL: goto x86_l_1982;
	case 6532ULL: goto x86_l_1984;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6551ULL: goto x86_l_1997;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6592ULL: goto x86_l_19c0;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6659ULL: goto x86_l_1a03;
	case 6661ULL: goto x86_l_1a05;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6671ULL: goto x86_l_1a0f;
	case 6677ULL: goto x86_l_1a15;
	case 6679ULL: goto x86_l_1a17;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6697ULL: goto x86_l_1a29;
	case 6705ULL: goto x86_l_1a31;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6721ULL: goto x86_l_1a41;
	case 6724ULL: goto x86_l_1a44;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6734ULL: goto x86_l_1a4e;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6754ULL: goto x86_l_1a62;
	case 6760ULL: goto x86_l_1a68;
	case 6766ULL: goto x86_l_1a6e;
	case 6769ULL: goto x86_l_1a71;
	case 6775ULL: goto x86_l_1a77;
	case 6787ULL: goto x86_l_1a83;
	case 6799ULL: goto x86_l_1a8f;
	case 6808ULL: goto x86_l_1a98;
	case 6817ULL: goto x86_l_1aa1;
	case 6826ULL: goto x86_l_1aaa;
	case 6835ULL: goto x86_l_1ab3;
	case 6844ULL: goto x86_l_1abc;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6900ULL: goto x86_l_1af4;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6928ULL: goto x86_l_1b10;
	case 6932ULL: goto x86_l_1b14;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7096ULL: goto x86_l_1bb8;
	case 7099ULL: goto x86_l_1bbb;
	case 7104ULL: goto x86_l_1bc0;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7162ULL: goto x86_l_1bfa;
	case 7164ULL: goto x86_l_1bfc;
	case 7169ULL: goto x86_l_1c01;
	case 7174ULL: goto x86_l_1c06;
	case 7179ULL: goto x86_l_1c0b;
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7217ULL: goto x86_l_1c31;
	case 7224ULL: goto x86_l_1c38;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7254ULL: goto x86_l_1c56;
	case 7258ULL: goto x86_l_1c5a;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7289ULL: goto x86_l_1c79;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7304ULL: goto x86_l_1c88;
	case 7306ULL: goto x86_l_1c8a;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7330ULL: goto x86_l_1ca2;
	case 7339ULL: goto x86_l_1cab;
	case 7342ULL: goto x86_l_1cae;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7394ULL: goto x86_l_1ce2;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_160d:
	/* 0x160d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1610:
	/* 0x1610: je     1f10 <trace_ret_vfs_read_tail+0x1f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7952ULL;
	}
x86_l_1616:
	/* 0x1616: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_161b:
	/* 0x161b: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_161e:
	/* 0x161e: je     1f10 <trace_ret_vfs_read_tail+0x1f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7952ULL;
	}
x86_l_1624:
	/* 0x1624: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1628:
	/* 0x1628: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_162d:
	/* 0x162d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1632:
	/* 0x1632: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1637:
	/* 0x1637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1639:
	/* 0x1639: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_163d:
	/* 0x163d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_163f:
	/* 0x163f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1645:
	/* 0x1645: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1648:
	/* 0x1648: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_164a:
	/* 0x164a: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_1650:
	/* 0x1650: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1655:
	/* 0x1655: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_165b:
	/* 0x165b: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1660:
	/* 0x1660: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1665:
	/* 0x1665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1667:
	/* 0x1667: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_166a:
	/* 0x166a: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_1670:
	/* 0x1670: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1674:
	/* 0x1674: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_167a:
	/* 0x167a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_167f:
	/* 0x167f: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1683:
	/* 0x1683: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1686:
	/* 0x1686: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168b:
	/* 0x168b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_168e:
	/* 0x168e: jmp    1f78 <trace_ret_vfs_read_tail+0x1f78> */
	return 8056ULL;
x86_l_1693:
	/* 0x1693: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1698:
	/* 0x1698: cmp    r14d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_169f:
	/* 0x169f: jne    1d66 <trace_ret_vfs_read_tail+0x1d66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7526ULL;
	}
x86_l_16a5:
	/* 0x16a5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16aa:
	/* 0x16aa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16ae:
	/* 0x16ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16b3:
	/* 0x16b3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16b8:
	/* 0x16b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_16bd:
	/* 0x16bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bf:
	/* 0x16bf: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16c4:
	/* 0x16c4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_16c9:
	/* 0x16c9: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16ce:
	/* 0x16ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16d1:
	/* 0x16d1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16d6:
	/* 0x16d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d8:
	/* 0x16d8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16db:
	/* 0x16db: and    r14d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16e2:
	/* 0x16e2: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16e5:
	/* 0x16e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16ea:
	/* 0x16ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_16f1:
	/* 0x16f1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16f6:
	/* 0x16f6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_16f9:
	/* 0x16f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16fb:
	/* 0x16fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fd:
	/* 0x16fd: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1700:
	/* 0x1700: jne    d85 <trace_ret_vfs_read_tail+0xd85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3461ULL;
	}
x86_l_1706:
	/* 0x1706: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_170f:
	/* 0x170f: mov    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1717:
	/* 0x1717: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171c:
	/* 0x171c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_1723:
	/* 0x1723: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1728:
	/* 0x1728: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172a:
	/* 0x172a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172d:
	/* 0x172d: je     208a <trace_ret_vfs_read_tail+0x208a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8330ULL;
	}
x86_l_1733:
	/* 0x1733: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1736:
	/* 0x1736: test   BYTE PTR [rax],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1739:
	/* 0x1739: je     18c2 <trace_ret_vfs_read_tail+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c2;
	}
x86_l_173f:
	/* 0x173f: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1744:
	/* 0x1744: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1748:
	/* 0x1748: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_174d:
	/* 0x174d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1752:
	/* 0x1752: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1757:
	/* 0x1757: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_175a:
	/* 0x175a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175c:
	/* 0x175c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1761:
	/* 0x1761: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1766:
	/* 0x1766: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_176b:
	/* 0x176b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1770:
	/* 0x1770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1772:
	/* 0x1772: movzx  ebx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1777:
	/* 0x1777: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177a:
	/* 0x177a: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_177c:
	/* 0x177c: je     189d <trace_ret_vfs_read_tail+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189d;
	}
x86_l_1782:
	/* 0x1782: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1786:
	/* 0x1786: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_178b:
	/* 0x178b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1790:
	/* 0x1790: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1795:
	/* 0x1795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1797:
	/* 0x1797: movabs rax,0x6972775f65706970 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598266772934912368ULL);
x86_l_17a1:
	/* 0x17a1: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17a6:
	/* 0x17a6: mov    DWORD PTR [rsp+0x2f],0x657469 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 201870111849ULL);
x86_l_17ae:
	/* 0x17ae: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17b3:
	/* 0x17b3: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17b8:
	/* 0x17b8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17c1:
	/* 0x17c1: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17c6:
	/* 0x17c6: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ca:
	/* 0x17ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17cf:
	/* 0x17cf: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17d4:
	/* 0x17d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17d9:
	/* 0x17d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17db:
	/* 0x17db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17e0:
	/* 0x17e0: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17e5:
	/* 0x17e5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17e9:
	/* 0x17e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ee:
	/* 0x17ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f3:
	/* 0x17f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f5:
	/* 0x17f5: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17fa:
	/* 0x17fa: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1806:
	/* 0x1806: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1812:
	/* 0x1812: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_181b:
	/* 0x181b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1824:
	/* 0x1824: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_182d:
	/* 0x182d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1836:
	/* 0x1836: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_183f:
	/* 0x183f: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1848:
	/* 0x1848: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_184d:
	/* 0x184d: lea    r13,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1852:
	/* 0x1852: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1857:
	/* 0x1857: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_185a:
	/* 0x185a: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_185f:
	/* 0x185f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1861:
	/* 0x1861: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1866:
	/* 0x1866: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ksymbols_map)));
x86_l_186d:
	/* 0x186d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1870:
	/* 0x1870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1872:
	/* 0x1872: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1875:
	/* 0x1875: je     1886 <trace_ret_vfs_read_tail+0x1886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1886;
	}
x86_l_1877:
	/* 0x1877: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187a:
	/* 0x187a: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_187d:
	/* 0x187d: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1882:
	/* 0x1882: je     1892 <trace_ret_vfs_read_tail+0x1892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1892;
	}
x86_l_1884:
	/* 0x1884: jmp    189a <trace_ret_vfs_read_tail+0x189a> */
	goto x86_l_189a;
x86_l_1886:
	/* 0x1886: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1888:
	/* 0x1888: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_188b:
	/* 0x188b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1890:
	/* 0x1890: jne    189a <trace_ret_vfs_read_tail+0x189a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_189a;
	}
x86_l_1892:
	/* 0x1892: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1898:
	/* 0x1898: jne    18bd <trace_ret_vfs_read_tail+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18bd;
	}
x86_l_189a:
	/* 0x189a: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189d:
	/* 0x189d: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_189f:
	/* 0x189f: je     18ac <trace_ret_vfs_read_tail+0x18ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ac;
	}
x86_l_18a1:
	/* 0x18a1: movzx  ecx,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_18a4:
	/* 0x18a4: cmp    ecx,0x3fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16383ULL);
x86_l_18aa:
	/* 0x18aa: ja     18bd <trace_ret_vfs_read_tail+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18bd;
	}
x86_l_18ac:
	/* 0x18ac: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_18ae:
	/* 0x18ae: je     1a19 <trace_ret_vfs_read_tail+0x1a19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a19;
	}
x86_l_18b4:
	/* 0x18b4: test   bx,bx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_16);
x86_l_18b7:
	/* 0x18b7: jns    1a19 <trace_ret_vfs_read_tail+0x1a19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1a19;
	}
x86_l_18bd:
	/* 0x18bd: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c2:
	/* 0x18c2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18cb:
	/* 0x18cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18d0:
	/* 0x18d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_18d7:
	/* 0x18d7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18dc:
	/* 0x18dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18de:
	/* 0x18de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18e1:
	/* 0x18e1: je     21a6 <trace_ret_vfs_read_tail+0x21a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8614ULL;
	}
x86_l_18e7:
	/* 0x18e7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_18ea:
	/* 0x18ea: test   BYTE PTR [rax+0x2],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934599ULL);
x86_l_18ee:
	/* 0x18ee: je     1a77 <trace_ret_vfs_read_tail+0x1a77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a77;
	}
x86_l_18f4:
	/* 0x18f4: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_18f9:
	/* 0x18f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fb:
	/* 0x18fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18fe:
	/* 0x18fe: je     19f5 <trace_ret_vfs_read_tail+0x19f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f5;
	}
x86_l_1904:
	/* 0x1904: sub    rax,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1908:
	/* 0x1908: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_190d:
	/* 0x190d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1912:
	/* 0x1912: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1917:
	/* 0x1917: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_191a:
	/* 0x191a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_191c:
	/* 0x191c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1921:
	/* 0x1921: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1924:
	/* 0x1924: je     1a07 <trace_ret_vfs_read_tail+0x1a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a07;
	}
x86_l_192a:
	/* 0x192a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_192f:
	/* 0x192f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1934:
	/* 0x1934: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1939:
	/* 0x1939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193b:
	/* 0x193b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1940:
	/* 0x1940: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1945:
	/* 0x1945: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_194a:
	/* 0x194a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194f:
	/* 0x194f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1951:
	/* 0x1951: mov    rbp,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1956:
	/* 0x1956: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1959:
	/* 0x1959: je     1a3c <trace_ret_vfs_read_tail+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3c;
	}
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1968:
	/* 0x1968: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_196d:
	/* 0x196d: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1972:
	/* 0x1972: lea    r15,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1977:
	/* 0x1977: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_197a:
	/* 0x197a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197f:
	/* 0x197f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1982:
	/* 0x1982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1984:
	/* 0x1984: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1986:
	/* 0x1986: cmp    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_198b:
	/* 0x198b: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_198e:
	/* 0x198e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1997:
	/* 0x1997: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199b:
	/* 0x199b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19a0:
	/* 0x19a0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19a3:
	/* 0x19a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a8:
	/* 0x19a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19aa:
	/* 0x19aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19ac:
	/* 0x19ac: cmp    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19b1:
	/* 0x19b1: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_19b4:
	/* 0x19b4: lea    ebx,[rbx+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_19b7:
	/* 0x19b7: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_19c0:
	/* 0x19c0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19c9:
	/* 0x19c9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19cc:
	/* 0x19cc: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19d1:
	/* 0x19d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19d6:
	/* 0x19d6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_19d9:
	/* 0x19d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19db:
	/* 0x19db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19dd:
	/* 0x19dd: cmp    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19e2:
	/* 0x19e2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_19e5:
	/* 0x19e5: lea    eax,[rbx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_19e8:
	/* 0x19e8: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19eb:
	/* 0x19eb: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_19f1:
	/* 0x19f1: jne    1a4c <trace_ret_vfs_read_tail+0x1a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4c;
	}
x86_l_19f3:
	/* 0x19f3: jmp    1a53 <trace_ret_vfs_read_tail+0x1a53> */
	goto x86_l_1a53;
x86_l_19f5:
	/* 0x19f5: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_19fa:
	/* 0x19fa: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fd:
	/* 0x19fd: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1a03:
	/* 0x1a03: jne    1a4c <trace_ret_vfs_read_tail+0x1a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4c;
	}
x86_l_1a05:
	/* 0x1a05: jmp    1a53 <trace_ret_vfs_read_tail+0x1a53> */
	goto x86_l_1a53;
x86_l_1a07:
	/* 0x1a07: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0f:
	/* 0x1a0f: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1a15:
	/* 0x1a15: jne    1a4c <trace_ret_vfs_read_tail+0x1a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4c;
	}
x86_l_1a17:
	/* 0x1a17: jmp    1a53 <trace_ret_vfs_read_tail+0x1a53> */
	goto x86_l_1a53;
x86_l_1a19:
	/* 0x1a19: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_1a1c:
	/* 0x1a1c: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a23:
	/* 0x1a23: jne    1c99 <trace_ret_vfs_read_tail+0x1c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c99;
	}
x86_l_1a29:
	/* 0x1a29: cmp    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1a31:
	/* 0x1a31: jne    18c2 <trace_ret_vfs_read_tail+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18c2;
	}
x86_l_1a37:
	/* 0x1a37: jmp    1c88 <trace_ret_vfs_read_tail+0x1c88> */
	goto x86_l_1c88;
x86_l_1a3c:
	/* 0x1a3c: mov    eax,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967293ULL);
x86_l_1a41:
	/* 0x1a41: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a44:
	/* 0x1a44: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1a4a:
	/* 0x1a4a: je     1a53 <trace_ret_vfs_read_tail+0x1a53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a53;
	}
x86_l_1a4c:
	/* 0x1a4c: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1a4e:
	/* 0x1a4e: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1a51:
	/* 0x1a51: jne    1a77 <trace_ret_vfs_read_tail+0x1a77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a77;
	}
x86_l_1a53:
	/* 0x1a53: test   ecx,0x20000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 131072ULL);
x86_l_1a59:
	/* 0x1a59: je     1a62 <trace_ret_vfs_read_tail+0x1a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a62;
	}
x86_l_1a5b:
	/* 0x1a5b: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1a5d:
	/* 0x1a5d: and    edx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_1a60:
	/* 0x1a60: jne    1a77 <trace_ret_vfs_read_tail+0x1a77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a77;
	}
x86_l_1a62:
	/* 0x1a62: test   ecx,0x40000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 262144ULL);
x86_l_1a68:
	/* 0x1a68: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c88;
	}
x86_l_1a6e:
	/* 0x1a6e: and    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4ULL);
x86_l_1a71:
	/* 0x1a71: je     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c88;
	}
x86_l_1a77:
	/* 0x1a77: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1a83:
	/* 0x1a83: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1a98:
	/* 0x1a98: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1abc:
	/* 0x1abc: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1aca:
	/* 0x1aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acc:
	/* 0x1acc: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    rbx,QWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1add:
	/* 0x1add: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1aea:
	/* 0x1aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aec:
	/* 0x1aec: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1af1:
	/* 0x1af1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af4:
	/* 0x1af4: je     1afe <trace_ret_vfs_read_tail+0x1afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1afe;
	}
x86_l_1af6:
	/* 0x1af6: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1af9:
	/* 0x1af9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1afe:
	/* 0x1afe: mov    BYTE PTR [rsp+0x50],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383685ULL);
x86_l_1b03:
	/* 0x1b03: lea    r14,[rsp+0x51] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_1b08:
	/* 0x1b08: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b10:
	/* 0x1b10: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b14:
	/* 0x1b14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b19:
	/* 0x1b19: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b23:
	/* 0x1b23: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b28:
	/* 0x1b28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b32:
	/* 0x1b32: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b36:
	/* 0x1b36: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b40:
	/* 0x1b40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b42:
	/* 0x1b42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b47:
	/* 0x1b47: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1b4f:
	/* 0x1b4f: lea    r13,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1b57:
	/* 0x1b57: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b5a:
	/* 0x1b5a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b5f:
	/* 0x1b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b61:
	/* 0x1b61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b66:
	/* 0x1b66: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b6b:
	/* 0x1b6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b70:
	/* 0x1b70: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b73:
	/* 0x1b73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b75:
	/* 0x1b75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b7f:
	/* 0x1b7f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b83:
	/* 0x1b83: lea    rbp,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b88:
	/* 0x1b88: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1b8b:
	/* 0x1b8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b90:
	/* 0x1b90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b92:
	/* 0x1b92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b97:
	/* 0x1b97: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ba4:
	/* 0x1ba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba6:
	/* 0x1ba6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bab:
	/* 0x1bab: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bb0:
	/* 0x1bb0: lea    r15,[rsp+0xce] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206ULL);
x86_l_1bb8:
	/* 0x1bb8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bbb:
	/* 0x1bbb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1bc0:
	/* 0x1bc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc2:
	/* 0x1bc2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1bca:
	/* 0x1bca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bd2:
	/* 0x1bd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd4:
	/* 0x1bd4: lea    rdi,[rsp+0x55] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bde:
	/* 0x1bde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be3:
	/* 0x1be3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1be6:
	/* 0x1be6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be8:
	/* 0x1be8: lea    rdi,[rsp+0x5d] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1bed:
	/* 0x1bed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1bfa:
	/* 0x1bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfc:
	/* 0x1bfc: lea    rdi,[rsp+0x61] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1c01:
	/* 0x1c01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c06:
	/* 0x1c06: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c10:
	/* 0x1c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c12:
	/* 0x1c12: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c17:
	/* 0x1c17: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c24:
	/* 0x1c24: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c29:
	/* 0x1c29: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c31:
	/* 0x1c31: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c38:
	/* 0x1c38: movzx  eax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c41:
	/* 0x1c41: cmp    eax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31935ULL);
x86_l_1c46:
	/* 0x1c46: ja     1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c88;
	}
x86_l_1c48:
	/* 0x1c48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c4d:
	/* 0x1c4d: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c56:
	/* 0x1c56: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c5a:
	/* 0x1c5a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c61:
	/* 0x1c61: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c66:
	/* 0x1c66: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_1c6b:
	/* 0x1c6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6d:
	/* 0x1c6d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c72:
	/* 0x1c72: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_1c79:
	/* 0x1c79: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c81:
	/* 0x1c81: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1c86:
	/* 0x1c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c88:
	/* 0x1c88: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c8a:
	/* 0x1c8a: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_1c91:
	/* 0x1c91: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1c93:
	/* 0x1c93: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1c94:
	/* 0x1c94: jmp    356d <.L.str.5+0x355d> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1c99:
	/* 0x1c99: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ca2:
	/* 0x1ca2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1cab:
	/* 0x1cab: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1cae:
	/* 0x1cae: je     1e21 <trace_ret_vfs_read_tail+0x1e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7713ULL;
	}
x86_l_1cb4:
	/* 0x1cb4: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_1cb7:
	/* 0x1cb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cbc:
	/* 0x1cbc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1cc9:
	/* 0x1cc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccb:
	/* 0x1ccb: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1cd4:
	/* 0x1cd4: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1ce2:
	/* 0x1ce2: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ceb:
	/* 0x1ceb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 7408ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7447ULL: goto x86_l_1d17;
	case 7449ULL: goto x86_l_1d19;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7512ULL: goto x86_l_1d58;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7546ULL: goto x86_l_1d7a;
	case 7553ULL: goto x86_l_1d81;
	case 7560ULL: goto x86_l_1d88;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7622ULL: goto x86_l_1dc6;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7646ULL: goto x86_l_1dde;
	case 7650ULL: goto x86_l_1de2;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7672ULL: goto x86_l_1df8;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7713ULL: goto x86_l_1e21;
	case 7722ULL: goto x86_l_1e2a;
	case 7731ULL: goto x86_l_1e33;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7761ULL: goto x86_l_1e51;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7778ULL: goto x86_l_1e62;
	case 7783ULL: goto x86_l_1e67;
	case 7792ULL: goto x86_l_1e70;
	case 7801ULL: goto x86_l_1e79;
	case 7810ULL: goto x86_l_1e82;
	case 7819ULL: goto x86_l_1e8b;
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7843ULL: goto x86_l_1ea3;
	case 7848ULL: goto x86_l_1ea8;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7886ULL: goto x86_l_1ece;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7919ULL: goto x86_l_1eef;
	case 7921ULL: goto x86_l_1ef1;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7940ULL: goto x86_l_1f04;
	case 7945ULL: goto x86_l_1f09;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7955ULL: goto x86_l_1f13;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8025ULL: goto x86_l_1f59;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8074ULL: goto x86_l_1f8a;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8156ULL: goto x86_l_1fdc;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8202ULL: goto x86_l_200a;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8215ULL: goto x86_l_2017;
	case 8221ULL: goto x86_l_201d;
	case 8226ULL: goto x86_l_2022;
	case 8230ULL: goto x86_l_2026;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8243ULL: goto x86_l_2033;
	case 8251ULL: goto x86_l_203b;
	case 8254ULL: goto x86_l_203e;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8273ULL: goto x86_l_2051;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8290ULL: goto x86_l_2062;
	case 8302ULL: goto x86_l_206e;
	case 8314ULL: goto x86_l_207a;
	case 8319ULL: goto x86_l_207f;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8339ULL: goto x86_l_2093;
	case 8345ULL: goto x86_l_2099;
	case 8350ULL: goto x86_l_209e;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8399ULL: goto x86_l_20cf;
	case 8402ULL: goto x86_l_20d2;
	case 8406ULL: goto x86_l_20d6;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8421ULL: goto x86_l_20e5;
	case 8425ULL: goto x86_l_20e9;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8440ULL: goto x86_l_20f8;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8471ULL: goto x86_l_2117;
	case 8480ULL: goto x86_l_2120;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8517ULL: goto x86_l_2145;
	case 8520ULL: goto x86_l_2148;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8533ULL: goto x86_l_2155;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8544ULL: goto x86_l_2160;
	case 8547ULL: goto x86_l_2163;
	case 8553ULL: goto x86_l_2169;
	case 8559ULL: goto x86_l_216f;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8589ULL: goto x86_l_218d;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8602ULL: goto x86_l_219a;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8623ULL: goto x86_l_21af;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8675ULL: goto x86_l_21e3;
	case 8678ULL: goto x86_l_21e6;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8695ULL: goto x86_l_21f7;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8714ULL: goto x86_l_220a;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8729ULL: goto x86_l_2219;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8746ULL: goto x86_l_222a;
	case 8751ULL: goto x86_l_222f;
	case 8760ULL: goto x86_l_2238;
	case 8768ULL: goto x86_l_2240;
	case 8773ULL: goto x86_l_2245;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8806ULL: goto x86_l_2266;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8835ULL: goto x86_l_2283;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8875ULL: goto x86_l_22ab;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8905ULL: goto x86_l_22c9;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9024ULL: goto x86_l_2340;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9106ULL: goto x86_l_2392;
	case 9110ULL: goto x86_l_2396;
	case 9112ULL: goto x86_l_2398;
	case 9118ULL: goto x86_l_239e;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9155ULL: goto x86_l_23c3;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9180ULL: goto x86_l_23dc;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9202ULL: goto x86_l_23f2;
	case 9205ULL: goto x86_l_23f5;
	case 9211ULL: goto x86_l_23fb;
	case 9219ULL: goto x86_l_2403;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cf0:
	/* 0x1cf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf5:
	/* 0x1cf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf7:
	/* 0x1cf7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d01:
	/* 0x1d01: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1d05:
	/* 0x1d05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d0a:
	/* 0x1d0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d14:
	/* 0x1d14: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d17:
	/* 0x1d17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d19:
	/* 0x1d19: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d22:
	/* 0x1d22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d27:
	/* 0x1d27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d2c:
	/* 0x1d2c: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d31:
	/* 0x1d31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d36:
	/* 0x1d36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d38:
	/* 0x1d38: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3d:
	/* 0x1d3d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1d40:
	/* 0x1d40: js     1d93 <trace_ret_vfs_read_tail+0x1d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d93;
	}
x86_l_1d42:
	/* 0x1d42: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d47:
	/* 0x1d47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d4c:
	/* 0x1d4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d51:
	/* 0x1d51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d56:
	/* 0x1d56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d58:
	/* 0x1d58: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1d5f:
	/* 0x1d5f: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d64:
	/* 0x1d64: jmp    1d95 <trace_ret_vfs_read_tail+0x1d95> */
	goto x86_l_1d95;
x86_l_1d66:
	/* 0x1d66: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1d69:
	/* 0x1d69: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1d6c:
	/* 0x1d6c: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1d71:
	/* 0x1d71: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d76:
	/* 0x1d76: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    BYTE PTR [rbx+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1d81:
	/* 0x1d81: cmp    r14d,0x7000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28672ULL);
x86_l_1d88:
	/* 0x1d88: jb     16db <trace_ret_vfs_read_tail+0x16db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5851ULL;
	}
x86_l_1d8e:
	/* 0x1d8e: jmp    1706 <trace_ret_vfs_read_tail+0x1706> */
	return 5894ULL;
x86_l_1d93:
	/* 0x1d93: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d95:
	/* 0x1d95: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d9f:
	/* 0x1d9f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1da4:
	/* 0x1da4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da9:
	/* 0x1da9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1dac:
	/* 0x1dac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dae:
	/* 0x1dae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1db3:
	/* 0x1db3: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1db8:
	/* 0x1db8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dbc:
	/* 0x1dbc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc1:
	/* 0x1dc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dc6:
	/* 0x1dc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc8:
	/* 0x1dc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd2:
	/* 0x1dd2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ddc:
	/* 0x1ddc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dde:
	/* 0x1dde: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de2:
	/* 0x1de2: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1de6:
	/* 0x1de6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1deb:
	/* 0x1deb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df0:
	/* 0x1df0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1df5:
	/* 0x1df5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1df8:
	/* 0x1df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfa:
	/* 0x1dfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dff:
	/* 0x1dff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e04:
	/* 0x1e04: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e08:
	/* 0x1e08: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e12:
	/* 0x1e12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e14:
	/* 0x1e14: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e19:
	/* 0x1e19: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_1e21:
	/* 0x1e21: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1e2a:
	/* 0x1e2a: cmp    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_1e33:
	/* 0x1e33: je     1e67 <trace_ret_vfs_read_tail+0x1e67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e67;
	}
x86_l_1e35:
	/* 0x1e35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e3a:
	/* 0x1e3a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_1e41:
	/* 0x1e41: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e46:
	/* 0x1e46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e48:
	/* 0x1e48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e4b:
	/* 0x1e4b: je     1a29 <trace_ret_vfs_read_tail+0x1a29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6697ULL;
	}
x86_l_1e51:
	/* 0x1e51: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e54:
	/* 0x1e54: je     1a29 <trace_ret_vfs_read_tail+0x1a29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6697ULL;
	}
x86_l_1e5a:
	/* 0x1e5a: mov    BYTE PTR [rsp+0x9c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898177ULL);
x86_l_1e62:
	/* 0x1e62: jmp    1a29 <trace_ret_vfs_read_tail+0x1a29> */
	return 6697ULL;
x86_l_1e67:
	/* 0x1e67: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1e70:
	/* 0x1e70: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1e79:
	/* 0x1e79: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1e82:
	/* 0x1e82: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e93:
	/* 0x1e93: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1e96:
	/* 0x1e96: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_1e9b:
	/* 0x1e9b: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1e9e:
	/* 0x1e9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ea3:
	/* 0x1ea3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1eb0:
	/* 0x1eb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb2:
	/* 0x1eb2: cmp    BYTE PTR [rsp+0x50],0x7f */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383807ULL);
x86_l_1eb7:
	/* 0x1eb7: jne    1ef8 <trace_ret_vfs_read_tail+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef8;
	}
x86_l_1eb9:
	/* 0x1eb9: cmp    BYTE PTR [rsp+0x51],0x45 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 347892351045ULL);
x86_l_1ebe:
	/* 0x1ebe: jne    1ef8 <trace_ret_vfs_read_tail+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef8;
	}
x86_l_1ec0:
	/* 0x1ec0: cmp    BYTE PTR [rsp+0x52],0x4c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 352187318348ULL);
x86_l_1ec5:
	/* 0x1ec5: jne    1ef8 <trace_ret_vfs_read_tail+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef8;
	}
x86_l_1ec7:
	/* 0x1ec7: cmp    BYTE PTR [rsp+0x53],0x46 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285638ULL);
x86_l_1ecc:
	/* 0x1ecc: jne    1ef8 <trace_ret_vfs_read_tail+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef8;
	}
x86_l_1ece:
	/* 0x1ece: mov    BYTE PTR [rsp+0x9c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898177ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1edb:
	/* 0x1edb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_1ee2:
	/* 0x1ee2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ee7:
	/* 0x1ee7: lea    rdx,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1eef:
	/* 0x1eef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef1:
	/* 0x1ef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef3:
	/* 0x1ef3: jmp    1a29 <trace_ret_vfs_read_tail+0x1a29> */
	return 6697ULL;
x86_l_1ef8:
	/* 0x1ef8: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1efd:
	/* 0x1efd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_1f04:
	/* 0x1f04: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f09:
	/* 0x1f09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0b:
	/* 0x1f0b: jmp    1a29 <trace_ret_vfs_read_tail+0x1a29> */
	return 6697ULL;
x86_l_1f10:
	/* 0x1f10: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f13:
	/* 0x1f13: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_1f19:
	/* 0x1f19: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1e:
	/* 0x1f1e: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_1f23:
	/* 0x1f23: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_1f29:
	/* 0x1f29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f33:
	/* 0x1f33: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f37:
	/* 0x1f37: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f41:
	/* 0x1f41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f43:
	/* 0x1f43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f48:
	/* 0x1f48: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f4d:
	/* 0x1f4d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f52:
	/* 0x1f52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f57:
	/* 0x1f57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f59:
	/* 0x1f59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f63:
	/* 0x1f63: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f68:
	/* 0x1f68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f6d:
	/* 0x1f6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6f:
	/* 0x1f6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f74:
	/* 0x1f74: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f78:
	/* 0x1f78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f7d:
	/* 0x1f7d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f82:
	/* 0x1f82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f87:
	/* 0x1f87: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1f8a:
	/* 0x1f8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8c:
	/* 0x1f8c: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f91:
	/* 0x1f91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f96:
	/* 0x1f96: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f9f:
	/* 0x1f9f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa9:
	/* 0x1fa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fab:
	/* 0x1fab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb0:
	/* 0x1fb0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fb3:
	/* 0x1fb3: je     22c6 <trace_ret_vfs_read_tail+0x22c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c6;
	}
x86_l_1fb9:
	/* 0x1fb9: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fbe:
	/* 0x1fbe: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1fc1:
	/* 0x1fc1: je     22c6 <trace_ret_vfs_read_tail+0x22c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c6;
	}
x86_l_1fc7:
	/* 0x1fc7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fd0:
	/* 0x1fd0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fd5:
	/* 0x1fd5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fda:
	/* 0x1fda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fdc:
	/* 0x1fdc: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1fe0:
	/* 0x1fe0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1fe2:
	/* 0x1fe2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1feb:
	/* 0x1feb: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fed:
	/* 0x1fed: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_1ff3:
	/* 0x1ff3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ff8:
	/* 0x1ff8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1ffe:
	/* 0x1ffe: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2003:
	/* 0x2003: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2008:
	/* 0x2008: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200a:
	/* 0x200a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_200d:
	/* 0x200d: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2013:
	/* 0x2013: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2017:
	/* 0x2017: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_201d:
	/* 0x201d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2022:
	/* 0x2022: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2026:
	/* 0x2026: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2029:
	/* 0x2029: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_202e:
	/* 0x202e: jmp    232e <trace_ret_vfs_read_tail+0x232e> */
	goto x86_l_232e;
x86_l_2033:
	/* 0x2033: lea    rdi,[r12+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_203b:
	/* 0x203b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_203e:
	/* 0x203e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2042:
	/* 0x2042: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2047:
	/* 0x2047: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_204c:
	/* 0x204c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204e:
	/* 0x204e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2051:
	/* 0x2051: jne    1c88 <trace_ret_vfs_read_tail+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7304ULL;
	}
x86_l_2057:
	/* 0x2057: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_205c:
	/* 0x205c: mov    WORD PTR [r12+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2062:
	/* 0x2062: mov    QWORD PTR [r12+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_206e:
	/* 0x206e: mov    QWORD PTR [r12+0x80],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781183ULL);
x86_l_207a:
	/* 0x207a: test   BYTE PTR [r14+0x5],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836481ULL);
x86_l_207f:
	/* 0x207f: jne    b90 <trace_ret_vfs_read_tail+0xb90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2960ULL;
	}
x86_l_2085:
	/* 0x2085: jmp    1c88 <trace_ret_vfs_read_tail+0x1c88> */
	return 7304ULL;
x86_l_208a:
	/* 0x208a: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_2093:
	/* 0x2093: je     18c2 <trace_ret_vfs_read_tail+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6338ULL;
	}
x86_l_2099:
	/* 0x2099: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_209e:
	/* 0x209e: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20a6:
	/* 0x20a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20ab:
	/* 0x20ab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_20b2:
	/* 0x20b2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20b7:
	/* 0x20b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b9:
	/* 0x20b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20bc:
	/* 0x20bc: je     18bd <trace_ret_vfs_read_tail+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6333ULL;
	}
x86_l_20c2:
	/* 0x20c2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_20c5:
	/* 0x20c5: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_20cf:
	/* 0x20cf: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d2:
	/* 0x20d2: lea    r15,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d6:
	/* 0x20d6: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20de:
	/* 0x20de: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_20e3:
	/* 0x20e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e5:
	/* 0x20e5: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20e9:
	/* 0x20e9: mov    DWORD PTR [r14+0x1c],0x58 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084376ULL);
x86_l_20f1:
	/* 0x20f1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_20f4:
	/* 0x20f4: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_20f8:
	/* 0x20f8: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_20ff:
	/* 0x20ff: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_2104:
	/* 0x2104: call   2109 <trace_ret_vfs_read_tail+0x2109> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_2109:
	/* 0x2109: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_210e:
	/* 0x210e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2117:
	/* 0x2117: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2120:
	/* 0x2120: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_2128:
	/* 0x2128: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_212d:
	/* 0x212d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212f:
	/* 0x212f: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2134:
	/* 0x2134: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2139:
	/* 0x2139: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_2140:
	/* 0x2140: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2143:
	/* 0x2143: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2145:
	/* 0x2145: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2148:
	/* 0x2148: je     2ab9 <trace_ret_vfs_read_tail+0x2ab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10937ULL;
	}
x86_l_214e:
	/* 0x214e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2155:
	/* 0x2155: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2157:
	/* 0x2157: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_215c:
	/* 0x215c: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2160:
	/* 0x2160: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2163:
	/* 0x2163: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_2169:
	/* 0x2169: jb     18bd <trace_ret_vfs_read_tail+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6333ULL;
	}
x86_l_216f:
	/* 0x216f: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2172:
	/* 0x2172: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2176:
	/* 0x2176: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_217b:
	/* 0x217b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_2182:
	/* 0x2182: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2187:
	/* 0x2187: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_218d:
	/* 0x218d: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2195:
	/* 0x2195: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2198:
	/* 0x2198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219a:
	/* 0x219a: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a1:
	/* 0x21a1: jmp    18bd <trace_ret_vfs_read_tail+0x18bd> */
	return 6333ULL;
x86_l_21a6:
	/* 0x21a6: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_21af:
	/* 0x21af: je     1a77 <trace_ret_vfs_read_tail+0x1a77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6775ULL;
	}
x86_l_21b5:
	/* 0x21b5: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ba:
	/* 0x21ba: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21bf:
	/* 0x21bf: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_21c7:
	/* 0x21c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21cc:
	/* 0x21cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_21d3:
	/* 0x21d3: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21d8:
	/* 0x21d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21da:
	/* 0x21da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21dd:
	/* 0x21dd: je     22b7 <trace_ret_vfs_read_tail+0x22b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b7;
	}
x86_l_21e3:
	/* 0x21e3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_21e6:
	/* 0x21e6: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_21f0:
	/* 0x21f0: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f3:
	/* 0x21f3: lea    rbx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21f7:
	/* 0x21f7: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21ff:
	/* 0x21ff: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2204:
	/* 0x2204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2206:
	/* 0x2206: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_220a:
	/* 0x220a: mov    DWORD PTR [r14+0x1c],0x9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084443ULL);
x86_l_2212:
	/* 0x2212: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2215:
	/* 0x2215: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2219:
	/* 0x2219: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2220:
	/* 0x2220: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_2225:
	/* 0x2225: call   222a <trace_ret_vfs_read_tail+0x222a> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_222a:
	/* 0x222a: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_222f:
	/* 0x222f: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2238:
	/* 0x2238: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_2240:
	/* 0x2240: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2245:
	/* 0x2245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2247:
	/* 0x2247: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_224a:
	/* 0x224a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_224f:
	/* 0x224f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2254:
	/* 0x2254: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_225b:
	/* 0x225b: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_225e:
	/* 0x225e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2261:
	/* 0x2261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2263:
	/* 0x2263: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2266:
	/* 0x2266: je     2aef <trace_ret_vfs_read_tail+0x2aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10991ULL;
	}
x86_l_226c:
	/* 0x226c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2273:
	/* 0x2273: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2275:
	/* 0x2275: mov    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2279:
	/* 0x2279: sub    r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_227c:
	/* 0x227c: cmp    r13,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2000000001ULL);
x86_l_2283:
	/* 0x2283: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_228b:
	/* 0x228b: jb     22b7 <trace_ret_vfs_read_tail+0x22b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_22b7;
	}
x86_l_228d:
	/* 0x228d: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2290:
	/* 0x2290: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2294:
	/* 0x2294: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2299:
	/* 0x2299: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_22a0:
	/* 0x22a0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_22a5:
	/* 0x22a5: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_22ab:
	/* 0x22ab: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_22ae:
	/* 0x22ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b0:
	/* 0x22b0: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22b7:
	/* 0x22b7: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22bc:
	/* 0x22bc: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22c1:
	/* 0x22c1: jmp    1a77 <trace_ret_vfs_read_tail+0x1a77> */
	return 6775ULL;
x86_l_22c6:
	/* 0x22c6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22c9:
	/* 0x22c9: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_22cf:
	/* 0x22cf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d4:
	/* 0x22d4: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_22d9:
	/* 0x22d9: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_22df:
	/* 0x22df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22e4:
	/* 0x22e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e9:
	/* 0x22e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22ed:
	/* 0x22ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f2:
	/* 0x22f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f7:
	/* 0x22f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f9:
	/* 0x22f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22fe:
	/* 0x22fe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2303:
	/* 0x2303: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2308:
	/* 0x2308: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_230d:
	/* 0x230d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230f:
	/* 0x230f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2314:
	/* 0x2314: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2319:
	/* 0x2319: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_231e:
	/* 0x231e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2323:
	/* 0x2323: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2325:
	/* 0x2325: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232a:
	/* 0x232a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_232e:
	/* 0x232e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2333:
	/* 0x2333: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2338:
	/* 0x2338: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_233d:
	/* 0x233d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2340:
	/* 0x2340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2342:
	/* 0x2342: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2347:
	/* 0x2347: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234c:
	/* 0x234c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2350:
	/* 0x2350: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2355:
	/* 0x2355: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_235a:
	/* 0x235a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_235f:
	/* 0x235f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2361:
	/* 0x2361: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2366:
	/* 0x2366: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2369:
	/* 0x2369: je     2504 <trace_ret_vfs_read_tail+0x2504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9476ULL;
	}
x86_l_236f:
	/* 0x236f: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2374:
	/* 0x2374: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2377:
	/* 0x2377: je     2504 <trace_ret_vfs_read_tail+0x2504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9476ULL;
	}
x86_l_237d:
	/* 0x237d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2381:
	/* 0x2381: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2386:
	/* 0x2386: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_238b:
	/* 0x238b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2390:
	/* 0x2390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2392:
	/* 0x2392: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2396:
	/* 0x2396: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2398:
	/* 0x2398: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_239e:
	/* 0x239e: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_23a1:
	/* 0x23a1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23a3:
	/* 0x23a3: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_23a9:
	/* 0x23a9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23ae:
	/* 0x23ae: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23b4:
	/* 0x23b4: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_23b9:
	/* 0x23b9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_23be:
	/* 0x23be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c0:
	/* 0x23c0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23c3:
	/* 0x23c3: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_23c9:
	/* 0x23c9: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_23cd:
	/* 0x23cd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_23d3:
	/* 0x23d3: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23d8:
	/* 0x23d8: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_23dc:
	/* 0x23dc: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23df:
	/* 0x23df: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e4:
	/* 0x23e4: jmp    256c <trace_ret_vfs_read_tail+0x256c> */
	return 9580ULL;
x86_l_23e9:
	/* 0x23e9: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_23f2:
	/* 0x23f2: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_23f5:
	/* 0x23f5: je     1706 <trace_ret_vfs_read_tail+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5894ULL;
	}
x86_l_23fb:
	/* 0x23fb: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2403:
	/* 0x2403: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 9224ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9224ULL: goto x86_l_2408;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9238ULL: goto x86_l_2416;
	case 9241ULL: goto x86_l_2419;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9267ULL: goto x86_l_2433;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9294ULL: goto x86_l_244e;
	case 9297ULL: goto x86_l_2451;
	case 9301ULL: goto x86_l_2455;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9332ULL: goto x86_l_2474;
	case 9341ULL: goto x86_l_247d;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9356ULL: goto x86_l_248c;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9387ULL: goto x86_l_24ab;
	case 9391ULL: goto x86_l_24af;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9402ULL: goto x86_l_24ba;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9424ULL: goto x86_l_24d0;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9451ULL: goto x86_l_24eb;
	case 9459ULL: goto x86_l_24f3;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9479ULL: goto x86_l_2507;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9598ULL: goto x86_l_257e;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9639ULL: goto x86_l_25a7;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9649ULL: goto x86_l_25b1;
	case 9651ULL: goto x86_l_25b3;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9676ULL: goto x86_l_25cc;
	case 9678ULL: goto x86_l_25ce;
	case 9684ULL: goto x86_l_25d4;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9718ULL: goto x86_l_25f6;
	case 9721ULL: goto x86_l_25f9;
	case 9727ULL: goto x86_l_25ff;
	case 9731ULL: goto x86_l_2603;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9746ULL: goto x86_l_2612;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9756ULL: goto x86_l_261c;
	case 9759ULL: goto x86_l_261f;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9791ULL: goto x86_l_263f;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9878ULL: goto x86_l_2696;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9890ULL: goto x86_l_26a2;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9929ULL: goto x86_l_26c9;
	case 9931ULL: goto x86_l_26cb;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9956ULL: goto x86_l_26e4;
	case 9958ULL: goto x86_l_26e6;
	case 9964ULL: goto x86_l_26ec;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9975ULL: goto x86_l_26f7;
	case 9980ULL: goto x86_l_26fc;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10026ULL: goto x86_l_272a;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10036ULL: goto x86_l_2734;
	case 10039ULL: goto x86_l_2737;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10129ULL: goto x86_l_2791;
	case 10131ULL: goto x86_l_2793;
	case 10136ULL: goto x86_l_2798;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10158ULL: goto x86_l_27ae;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10184ULL: goto x86_l_27c8;
	case 10189ULL: goto x86_l_27cd;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10215ULL: goto x86_l_27e7;
	case 10220ULL: goto x86_l_27ec;
	case 10225ULL: goto x86_l_27f1;
	case 10230ULL: goto x86_l_27f6;
	case 10232ULL: goto x86_l_27f8;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10291ULL: goto x86_l_2833;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10306ULL: goto x86_l_2842;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10387ULL: goto x86_l_2893;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10438ULL: goto x86_l_28c6;
	case 10440ULL: goto x86_l_28c8;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10479ULL: goto x86_l_28ef;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10489ULL: goto x86_l_28f9;
	case 10491ULL: goto x86_l_28fb;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10512ULL: goto x86_l_2910;
	case 10516ULL: goto x86_l_2914;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10571ULL: goto x86_l_294b;
	case 10577ULL: goto x86_l_2951;
	case 10582ULL: goto x86_l_2956;
	case 10586ULL: goto x86_l_295a;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10599ULL: goto x86_l_2967;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10689ULL: goto x86_l_29c1;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10700ULL: goto x86_l_29cc;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10718ULL: goto x86_l_29de;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10759ULL: goto x86_l_2a07;
	case 10765ULL: goto x86_l_2a0d;
	case 10770ULL: goto x86_l_2a12;
	case 10773ULL: goto x86_l_2a15;
	case 10779ULL: goto x86_l_2a1b;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10800ULL: goto x86_l_2a30;
	case 10804ULL: goto x86_l_2a34;
	case 10806ULL: goto x86_l_2a36;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10849ULL: goto x86_l_2a61;
	case 10855ULL: goto x86_l_2a67;
	case 10859ULL: goto x86_l_2a6b;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10874ULL: goto x86_l_2a7a;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10899ULL: goto x86_l_2a93;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2408:
	/* 0x2408: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_240f:
	/* 0x240f: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2414:
	/* 0x2414: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2416:
	/* 0x2416: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2419:
	/* 0x2419: je     1706 <trace_ret_vfs_read_tail+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5894ULL;
	}
x86_l_241f:
	/* 0x241f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2422:
	/* 0x2422: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_242c:
	/* 0x242c: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_242f:
	/* 0x242f: lea    rbx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2433:
	/* 0x2433: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_243b:
	/* 0x243b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2440:
	/* 0x2440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2442:
	/* 0x2442: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2446:
	/* 0x2446: mov    DWORD PTR [r14+0x1c],0x37 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084343ULL);
x86_l_244e:
	/* 0x244e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2451:
	/* 0x2451: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2455:
	/* 0x2455: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_245c:
	/* 0x245c: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_2461:
	/* 0x2461: call   2466 <trace_ret_vfs_read_tail+0x2466> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_2466:
	/* 0x2466: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_246b:
	/* 0x246b: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2474:
	/* 0x2474: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_247d:
	/* 0x247d: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_248a:
	/* 0x248a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248c:
	/* 0x248c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2491:
	/* 0x2491: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2496:
	/* 0x2496: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_249d:
	/* 0x249d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_24a0:
	/* 0x24a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a2:
	/* 0x24a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a5:
	/* 0x24a5: je     2a87 <trace_ret_vfs_read_tail+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a87;
	}
x86_l_24ab:
	/* 0x24ab: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24af:
	/* 0x24af: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24b1:
	/* 0x24b1: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24b6:
	/* 0x24b6: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ba:
	/* 0x24ba: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_24bd:
	/* 0x24bd: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_24c0:
	/* 0x24c0: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_24c7:
	/* 0x24c7: jb     1706 <trace_ret_vfs_read_tail+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5894ULL;
	}
x86_l_24cd:
	/* 0x24cd: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d0:
	/* 0x24d0: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d4:
	/* 0x24d4: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_24d9:
	/* 0x24d9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_24e0:
	/* 0x24e0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_24e5:
	/* 0x24e5: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_24eb:
	/* 0x24eb: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24f3:
	/* 0x24f3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_24f6:
	/* 0x24f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f8:
	/* 0x24f8: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ff:
	/* 0x24ff: jmp    1706 <trace_ret_vfs_read_tail+0x1706> */
	return 5894ULL;
x86_l_2504:
	/* 0x2504: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2507:
	/* 0x2507: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_250d:
	/* 0x250d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2512:
	/* 0x2512: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2517:
	/* 0x2517: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_251d:
	/* 0x251d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2522:
	/* 0x2522: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2527:
	/* 0x2527: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_252b:
	/* 0x252b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2530:
	/* 0x2530: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2535:
	/* 0x2535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2537:
	/* 0x2537: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_253c:
	/* 0x253c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2541:
	/* 0x2541: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2546:
	/* 0x2546: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_254b:
	/* 0x254b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254d:
	/* 0x254d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2552:
	/* 0x2552: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2557:
	/* 0x2557: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_255c:
	/* 0x255c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2561:
	/* 0x2561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2563:
	/* 0x2563: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2568:
	/* 0x2568: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_256c:
	/* 0x256c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2571:
	/* 0x2571: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2576:
	/* 0x2576: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_257b:
	/* 0x257b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_257e:
	/* 0x257e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2580:
	/* 0x2580: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2585:
	/* 0x2585: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258a:
	/* 0x258a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_258e:
	/* 0x258e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2593:
	/* 0x2593: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2598:
	/* 0x2598: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_259d:
	/* 0x259d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259f:
	/* 0x259f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a4:
	/* 0x25a4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25a7:
	/* 0x25a7: je     261c <trace_ret_vfs_read_tail+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_261c;
	}
x86_l_25a9:
	/* 0x25a9: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25ae:
	/* 0x25ae: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_25b1:
	/* 0x25b1: je     261c <trace_ret_vfs_read_tail+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_261c;
	}
x86_l_25b3:
	/* 0x25b3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25b7:
	/* 0x25b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25bc:
	/* 0x25bc: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25c1:
	/* 0x25c1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25c6:
	/* 0x25c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c8:
	/* 0x25c8: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_25cc:
	/* 0x25cc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_25ce:
	/* 0x25ce: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25d4:
	/* 0x25d4: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_25d7:
	/* 0x25d7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25d9:
	/* 0x25d9: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_25df:
	/* 0x25df: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25e4:
	/* 0x25e4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25ea:
	/* 0x25ea: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_25ef:
	/* 0x25ef: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_25f4:
	/* 0x25f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f6:
	/* 0x25f6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25f9:
	/* 0x25f9: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_25ff:
	/* 0x25ff: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2603:
	/* 0x2603: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2609:
	/* 0x2609: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_260e:
	/* 0x260e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2612:
	/* 0x2612: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2615:
	/* 0x2615: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261a:
	/* 0x261a: jmp    2684 <trace_ret_vfs_read_tail+0x2684> */
	goto x86_l_2684;
x86_l_261c:
	/* 0x261c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_261f:
	/* 0x261f: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2625:
	/* 0x2625: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262a:
	/* 0x262a: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_262f:
	/* 0x262f: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2635:
	/* 0x2635: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_263a:
	/* 0x263a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_263f:
	/* 0x263f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2643:
	/* 0x2643: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2648:
	/* 0x2648: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_264d:
	/* 0x264d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264f:
	/* 0x264f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2654:
	/* 0x2654: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2659:
	/* 0x2659: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_265e:
	/* 0x265e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2663:
	/* 0x2663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2665:
	/* 0x2665: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_266a:
	/* 0x266a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266f:
	/* 0x266f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2674:
	/* 0x2674: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2679:
	/* 0x2679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267b:
	/* 0x267b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2680:
	/* 0x2680: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2684:
	/* 0x2684: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2689:
	/* 0x2689: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_268e:
	/* 0x268e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2693:
	/* 0x2693: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2696:
	/* 0x2696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2698:
	/* 0x2698: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_269d:
	/* 0x269d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26a2:
	/* 0x26a2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26a6:
	/* 0x26a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26ab:
	/* 0x26ab: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26b0:
	/* 0x26b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26b5:
	/* 0x26b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b7:
	/* 0x26b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26bc:
	/* 0x26bc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_26bf:
	/* 0x26bf: je     2734 <trace_ret_vfs_read_tail+0x2734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2734;
	}
x86_l_26c1:
	/* 0x26c1: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26c6:
	/* 0x26c6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_26c9:
	/* 0x26c9: je     2734 <trace_ret_vfs_read_tail+0x2734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2734;
	}
x86_l_26cb:
	/* 0x26cb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26cf:
	/* 0x26cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26d4:
	/* 0x26d4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26d9:
	/* 0x26d9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26de:
	/* 0x26de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e0:
	/* 0x26e0: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_26e4:
	/* 0x26e4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_26e6:
	/* 0x26e6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26ec:
	/* 0x26ec: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_26ef:
	/* 0x26ef: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26f1:
	/* 0x26f1: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_26f7:
	/* 0x26f7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26fc:
	/* 0x26fc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2702:
	/* 0x2702: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2707:
	/* 0x2707: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_270c:
	/* 0x270c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270e:
	/* 0x270e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2711:
	/* 0x2711: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2717:
	/* 0x2717: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_271b:
	/* 0x271b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2721:
	/* 0x2721: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2726:
	/* 0x2726: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_272a:
	/* 0x272a: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_272d:
	/* 0x272d: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2732:
	/* 0x2732: jmp    279c <trace_ret_vfs_read_tail+0x279c> */
	goto x86_l_279c;
x86_l_2734:
	/* 0x2734: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2737:
	/* 0x2737: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_273d:
	/* 0x273d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2742:
	/* 0x2742: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2747:
	/* 0x2747: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_274d:
	/* 0x274d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2752:
	/* 0x2752: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2757:
	/* 0x2757: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_275b:
	/* 0x275b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2760:
	/* 0x2760: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2765:
	/* 0x2765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2767:
	/* 0x2767: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_276c:
	/* 0x276c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2771:
	/* 0x2771: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2776:
	/* 0x2776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_277b:
	/* 0x277b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277d:
	/* 0x277d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2782:
	/* 0x2782: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2787:
	/* 0x2787: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_278c:
	/* 0x278c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2791:
	/* 0x2791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2793:
	/* 0x2793: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2798:
	/* 0x2798: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_279c:
	/* 0x279c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27a1:
	/* 0x27a1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27a6:
	/* 0x27a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ab:
	/* 0x27ab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_27ae:
	/* 0x27ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b0:
	/* 0x27b0: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27b5:
	/* 0x27b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ba:
	/* 0x27ba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27be:
	/* 0x27be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27c3:
	/* 0x27c3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27c8:
	/* 0x27c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27cd:
	/* 0x27cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cf:
	/* 0x27cf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d4:
	/* 0x27d4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27d7:
	/* 0x27d7: je     284c <trace_ret_vfs_read_tail+0x284c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284c;
	}
x86_l_27d9:
	/* 0x27d9: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27de:
	/* 0x27de: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_27e1:
	/* 0x27e1: je     284c <trace_ret_vfs_read_tail+0x284c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284c;
	}
x86_l_27e3:
	/* 0x27e3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27e7:
	/* 0x27e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27ec:
	/* 0x27ec: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27f1:
	/* 0x27f1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27f6:
	/* 0x27f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f8:
	/* 0x27f8: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_27fc:
	/* 0x27fc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_27fe:
	/* 0x27fe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2804:
	/* 0x2804: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2807:
	/* 0x2807: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2809:
	/* 0x2809: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_280f:
	/* 0x280f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2814:
	/* 0x2814: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_281a:
	/* 0x281a: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_281f:
	/* 0x281f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2824:
	/* 0x2824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2826:
	/* 0x2826: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2829:
	/* 0x2829: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_282f:
	/* 0x282f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2833:
	/* 0x2833: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2839:
	/* 0x2839: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_283e:
	/* 0x283e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2842:
	/* 0x2842: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2845:
	/* 0x2845: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_284a:
	/* 0x284a: jmp    28b4 <trace_ret_vfs_read_tail+0x28b4> */
	goto x86_l_28b4;
x86_l_284c:
	/* 0x284c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_284f:
	/* 0x284f: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2855:
	/* 0x2855: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_285a:
	/* 0x285a: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_285f:
	/* 0x285f: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2865:
	/* 0x2865: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_286a:
	/* 0x286a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_286f:
	/* 0x286f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2873:
	/* 0x2873: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2878:
	/* 0x2878: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287d:
	/* 0x287d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287f:
	/* 0x287f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2884:
	/* 0x2884: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2889:
	/* 0x2889: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288e:
	/* 0x288e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2893:
	/* 0x2893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2895:
	/* 0x2895: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_289a:
	/* 0x289a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_289f:
	/* 0x289f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28a4:
	/* 0x28a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28a9:
	/* 0x28a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ab:
	/* 0x28ab: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b0:
	/* 0x28b0: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28b4:
	/* 0x28b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28b9:
	/* 0x28b9: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28be:
	/* 0x28be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c3:
	/* 0x28c3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28c6:
	/* 0x28c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c8:
	/* 0x28c8: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28cd:
	/* 0x28cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28d2:
	/* 0x28d2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28d6:
	/* 0x28d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28db:
	/* 0x28db: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28e0:
	/* 0x28e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28e5:
	/* 0x28e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e7:
	/* 0x28e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ec:
	/* 0x28ec: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28ef:
	/* 0x28ef: je     2964 <trace_ret_vfs_read_tail+0x2964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2964;
	}
x86_l_28f1:
	/* 0x28f1: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28f6:
	/* 0x28f6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_28f9:
	/* 0x28f9: je     2964 <trace_ret_vfs_read_tail+0x2964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2964;
	}
x86_l_28fb:
	/* 0x28fb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28ff:
	/* 0x28ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2904:
	/* 0x2904: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2909:
	/* 0x2909: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_290e:
	/* 0x290e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2910:
	/* 0x2910: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2914:
	/* 0x2914: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2916:
	/* 0x2916: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_291c:
	/* 0x291c: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_291f:
	/* 0x291f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2921:
	/* 0x2921: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2927:
	/* 0x2927: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_292c:
	/* 0x292c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2932:
	/* 0x2932: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2937:
	/* 0x2937: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_293c:
	/* 0x293c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293e:
	/* 0x293e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2941:
	/* 0x2941: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2947:
	/* 0x2947: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_294b:
	/* 0x294b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2951:
	/* 0x2951: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2956:
	/* 0x2956: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_295a:
	/* 0x295a: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_295d:
	/* 0x295d: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2962:
	/* 0x2962: jmp    29cc <trace_ret_vfs_read_tail+0x29cc> */
	goto x86_l_29cc;
x86_l_2964:
	/* 0x2964: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2967:
	/* 0x2967: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_296d:
	/* 0x296d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2972:
	/* 0x2972: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2977:
	/* 0x2977: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_297d:
	/* 0x297d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2982:
	/* 0x2982: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2987:
	/* 0x2987: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_298b:
	/* 0x298b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2990:
	/* 0x2990: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2995:
	/* 0x2995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2997:
	/* 0x2997: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_299c:
	/* 0x299c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a1:
	/* 0x29a1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a6:
	/* 0x29a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ab:
	/* 0x29ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ad:
	/* 0x29ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b2:
	/* 0x29b2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b7:
	/* 0x29b7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29bc:
	/* 0x29bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c1:
	/* 0x29c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c3:
	/* 0x29c3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c8:
	/* 0x29c8: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29cc:
	/* 0x29cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29d1:
	/* 0x29d1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29d6:
	/* 0x29d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29db:
	/* 0x29db: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_29de:
	/* 0x29de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e0:
	/* 0x29e0: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29e5:
	/* 0x29e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ea:
	/* 0x29ea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29ee:
	/* 0x29ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29f3:
	/* 0x29f3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29f8:
	/* 0x29f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29fd:
	/* 0x29fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ff:
	/* 0x29ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a04:
	/* 0x2a04: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a07:
	/* 0x2a07: je     2b2e <trace_ret_vfs_read_tail+0x2b2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11054ULL;
	}
x86_l_2a0d:
	/* 0x2a0d: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a12:
	/* 0x2a12: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2a15:
	/* 0x2a15: je     2b2e <trace_ret_vfs_read_tail+0x2b2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11054ULL;
	}
x86_l_2a1b:
	/* 0x2a1b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a24:
	/* 0x2a24: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a29:
	/* 0x2a29: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a2e:
	/* 0x2a2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a30:
	/* 0x2a30: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a34:
	/* 0x2a34: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a36:
	/* 0x2a36: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a3c:
	/* 0x2a3c: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2a3f:
	/* 0x2a3f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a41:
	/* 0x2a41: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2a47:
	/* 0x2a47: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a4c:
	/* 0x2a4c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a52:
	/* 0x2a52: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2a57:
	/* 0x2a57: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a5c:
	/* 0x2a5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5e:
	/* 0x2a5e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a61:
	/* 0x2a61: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2a67:
	/* 0x2a67: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a6b:
	/* 0x2a6b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a71:
	/* 0x2a71: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a76:
	/* 0x2a76: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a7a:
	/* 0x2a7a: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a7d:
	/* 0x2a7d: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a82:
	/* 0x2a82: jmp    2b96 <trace_ret_vfs_read_tail+0x2b96> */
	return 11158ULL;
x86_l_2a87:
	/* 0x2a87: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_2a93:
	/* 0x2a93: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
	return 10902ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10907ULL: goto x86_l_2a9b;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10919ULL: goto x86_l_2aa7;
	case 10926ULL: goto x86_l_2aae;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10949ULL: goto x86_l_2ac5;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10974ULL: goto x86_l_2ade;
	case 10980ULL: goto x86_l_2ae4;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10996ULL: goto x86_l_2af4;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11016ULL: goto x86_l_2b08;
	case 11018ULL: goto x86_l_2b0a;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11028ULL: goto x86_l_2b14;
	case 11035ULL: goto x86_l_2b1b;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11057ULL: goto x86_l_2b31;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11105ULL: goto x86_l_2b61;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11137ULL: goto x86_l_2b81;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11176ULL: goto x86_l_2ba8;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11188ULL: goto x86_l_2bb4;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11207ULL: goto x86_l_2bc7;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11217ULL: goto x86_l_2bd1;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11250ULL: goto x86_l_2bf2;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11273ULL: goto x86_l_2c09;
	case 11278ULL: goto x86_l_2c0e;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11296ULL: goto x86_l_2c20;
	case 11299ULL: goto x86_l_2c23;
	case 11305ULL: goto x86_l_2c29;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11324ULL: goto x86_l_2c3c;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11334ULL: goto x86_l_2c46;
	case 11337ULL: goto x86_l_2c49;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11395ULL: goto x86_l_2c83;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11456ULL: goto x86_l_2cc0;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11530ULL: goto x86_l_2d0a;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11547ULL: goto x86_l_2d1b;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11576ULL: goto x86_l_2d38;
	case 11579ULL: goto x86_l_2d3b;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11614ULL: goto x86_l_2d5e;
	case 11617ULL: goto x86_l_2d61;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11787ULL: goto x86_l_2e0b;
	case 11789ULL: goto x86_l_2e0d;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11810ULL: goto x86_l_2e22;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11822ULL: goto x86_l_2e2e;
	case 11825ULL: goto x86_l_2e31;
	case 11827ULL: goto x86_l_2e33;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11865ULL: goto x86_l_2e59;
	case 11869ULL: goto x86_l_2e5d;
	case 11875ULL: goto x86_l_2e63;
	case 11880ULL: goto x86_l_2e68;
	case 11884ULL: goto x86_l_2e6c;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11894ULL: goto x86_l_2e76;
	case 11897ULL: goto x86_l_2e79;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11945ULL: goto x86_l_2ea9;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11987ULL: goto x86_l_2ed3;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12016ULL: goto x86_l_2ef0;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12069ULL: goto x86_l_2f25;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12090ULL: goto x86_l_2f3a;
	case 12094ULL: goto x86_l_2f3e;
	case 12096ULL: goto x86_l_2f40;
	case 12102ULL: goto x86_l_2f46;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12136ULL: goto x86_l_2f68;
	case 12139ULL: goto x86_l_2f6b;
	case 12145ULL: goto x86_l_2f71;
	case 12149ULL: goto x86_l_2f75;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12164ULL: goto x86_l_2f84;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12174ULL: goto x86_l_2f8e;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12213ULL: goto x86_l_2fb5;
	case 12218ULL: goto x86_l_2fba;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12235ULL: goto x86_l_2fcb;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12262ULL: goto x86_l_2fe6;
	case 12267ULL: goto x86_l_2feb;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12329ULL: goto x86_l_3029;
	case 12334ULL: goto x86_l_302e;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12347ULL: goto x86_l_303b;
	case 12349ULL: goto x86_l_303d;
	case 12353ULL: goto x86_l_3041;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12368ULL: goto x86_l_3050;
	case 12370ULL: goto x86_l_3052;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12382ULL: goto x86_l_305e;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12393ULL: goto x86_l_3069;
	case 12398ULL: goto x86_l_306e;
	case 12404ULL: goto x86_l_3074;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12416ULL: goto x86_l_3080;
	case 12419ULL: goto x86_l_3083;
	case 12425ULL: goto x86_l_3089;
	case 12429ULL: goto x86_l_308d;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12444ULL: goto x86_l_309c;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12454ULL: goto x86_l_30a6;
	case 12457ULL: goto x86_l_30a9;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12493ULL: goto x86_l_30cd;
	case 12498ULL: goto x86_l_30d2;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a96:
	/* 0x2a96: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a98:
	/* 0x2a98: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2a9b:
	/* 0x2a9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9d:
	/* 0x2a9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9f:
	/* 0x2a9f: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2aa4:
	/* 0x2aa4: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2aa7:
	/* 0x2aa7: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_2aae:
	/* 0x2aae: jb     1706 <trace_ret_vfs_read_tail+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5894ULL;
	}
x86_l_2ab4:
	/* 0x2ab4: jmp    24cd <trace_ret_vfs_read_tail+0x24cd> */
	return 9421ULL;
x86_l_2ab9:
	/* 0x2ab9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2abe:
	/* 0x2abe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_2ac5:
	/* 0x2ac5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ac7:
	/* 0x2ac7: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2acc:
	/* 0x2acc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2acf:
	/* 0x2acf: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ad2:
	/* 0x2ad2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad4:
	/* 0x2ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad6:
	/* 0x2ad6: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2adb:
	/* 0x2adb: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ade:
	/* 0x2ade: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_2ae4:
	/* 0x2ae4: jb     18bd <trace_ret_vfs_read_tail+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6333ULL;
	}
x86_l_2aea:
	/* 0x2aea: jmp    216f <trace_ret_vfs_read_tail+0x216f> */
	return 8559ULL;
x86_l_2aef:
	/* 0x2aef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2af4:
	/* 0x2af4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_2afb:
	/* 0x2afb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2afd:
	/* 0x2afd: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b02:
	/* 0x2b02: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2b08:
	/* 0x2b08: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b0a:
	/* 0x2b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0c:
	/* 0x2b0c: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b11:
	/* 0x2b11: sub    r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2b14:
	/* 0x2b14: cmp    r13,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2000000001ULL);
x86_l_2b1b:
	/* 0x2b1b: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b23:
	/* 0x2b23: jae    228d <trace_ret_vfs_read_tail+0x228d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8845ULL;
	}
x86_l_2b29:
	/* 0x2b29: jmp    22b7 <trace_ret_vfs_read_tail+0x22b7> */
	return 8887ULL;
x86_l_2b2e:
	/* 0x2b2e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b31:
	/* 0x2b31: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2b37:
	/* 0x2b37: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3c:
	/* 0x2b3c: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2b41:
	/* 0x2b41: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2b47:
	/* 0x2b47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4c:
	/* 0x2b4c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b51:
	/* 0x2b51: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b55:
	/* 0x2b55: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b5f:
	/* 0x2b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b61:
	/* 0x2b61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b66:
	/* 0x2b66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6b:
	/* 0x2b6b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b70:
	/* 0x2b70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b75:
	/* 0x2b75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b77:
	/* 0x2b77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b7c:
	/* 0x2b7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b81:
	/* 0x2b81: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b86:
	/* 0x2b86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8b:
	/* 0x2b8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8d:
	/* 0x2b8d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b92:
	/* 0x2b92: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b96:
	/* 0x2b96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b9b:
	/* 0x2b9b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba5:
	/* 0x2ba5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ba8:
	/* 0x2ba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2baa:
	/* 0x2baa: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2baf:
	/* 0x2baf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb4:
	/* 0x2bb4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bb8:
	/* 0x2bb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bbd:
	/* 0x2bbd: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc7:
	/* 0x2bc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc9:
	/* 0x2bc9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bce:
	/* 0x2bce: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2bd1:
	/* 0x2bd1: je     2c46 <trace_ret_vfs_read_tail+0x2c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c46;
	}
x86_l_2bd3:
	/* 0x2bd3: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bd8:
	/* 0x2bd8: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2bdb:
	/* 0x2bdb: je     2c46 <trace_ret_vfs_read_tail+0x2c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c46;
	}
x86_l_2bdd:
	/* 0x2bdd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2be1:
	/* 0x2be1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2be6:
	/* 0x2be6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2beb:
	/* 0x2beb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bf0:
	/* 0x2bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf2:
	/* 0x2bf2: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2bf6:
	/* 0x2bf6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2bf8:
	/* 0x2bf8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bfe:
	/* 0x2bfe: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2c01:
	/* 0x2c01: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c03:
	/* 0x2c03: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2c09:
	/* 0x2c09: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c0e:
	/* 0x2c0e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c14:
	/* 0x2c14: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c19:
	/* 0x2c19: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c1e:
	/* 0x2c1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c20:
	/* 0x2c20: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c23:
	/* 0x2c23: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2c29:
	/* 0x2c29: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c2d:
	/* 0x2c2d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c33:
	/* 0x2c33: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c38:
	/* 0x2c38: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c3c:
	/* 0x2c3c: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c3f:
	/* 0x2c3f: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c44:
	/* 0x2c44: jmp    2cae <trace_ret_vfs_read_tail+0x2cae> */
	goto x86_l_2cae;
x86_l_2c46:
	/* 0x2c46: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c49:
	/* 0x2c49: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2c4f:
	/* 0x2c4f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c54:
	/* 0x2c54: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2c59:
	/* 0x2c59: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2c5f:
	/* 0x2c5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c64:
	/* 0x2c64: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c69:
	/* 0x2c69: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c6d:
	/* 0x2c6d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c72:
	/* 0x2c72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c77:
	/* 0x2c77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c79:
	/* 0x2c79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c83:
	/* 0x2c83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c88:
	/* 0x2c88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c8d:
	/* 0x2c8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8f:
	/* 0x2c8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c94:
	/* 0x2c94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c99:
	/* 0x2c99: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c9e:
	/* 0x2c9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca3:
	/* 0x2ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca5:
	/* 0x2ca5: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2caa:
	/* 0x2caa: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cae:
	/* 0x2cae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb3:
	/* 0x2cb3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cbd:
	/* 0x2cbd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2cc0:
	/* 0x2cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc2:
	/* 0x2cc2: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cc7:
	/* 0x2cc7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccc:
	/* 0x2ccc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cd0:
	/* 0x2cd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd5:
	/* 0x2cd5: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cda:
	/* 0x2cda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cdf:
	/* 0x2cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce1:
	/* 0x2ce1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce6:
	/* 0x2ce6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ce9:
	/* 0x2ce9: je     2d5e <trace_ret_vfs_read_tail+0x2d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5e;
	}
x86_l_2ceb:
	/* 0x2ceb: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cf0:
	/* 0x2cf0: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2cf3:
	/* 0x2cf3: je     2d5e <trace_ret_vfs_read_tail+0x2d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5e;
	}
x86_l_2cf5:
	/* 0x2cf5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cfe:
	/* 0x2cfe: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d03:
	/* 0x2d03: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d08:
	/* 0x2d08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0a:
	/* 0x2d0a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d0e:
	/* 0x2d0e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d10:
	/* 0x2d10: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d16:
	/* 0x2d16: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2d19:
	/* 0x2d19: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d1b:
	/* 0x2d1b: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2d21:
	/* 0x2d21: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d26:
	/* 0x2d26: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d2c:
	/* 0x2d2c: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2d31:
	/* 0x2d31: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d36:
	/* 0x2d36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d38:
	/* 0x2d38: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d3b:
	/* 0x2d3b: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2d41:
	/* 0x2d41: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d45:
	/* 0x2d45: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d50:
	/* 0x2d50: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d54:
	/* 0x2d54: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d57:
	/* 0x2d57: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5c:
	/* 0x2d5c: jmp    2dc6 <trace_ret_vfs_read_tail+0x2dc6> */
	goto x86_l_2dc6;
x86_l_2d5e:
	/* 0x2d5e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d61:
	/* 0x2d61: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2d67:
	/* 0x2d67: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6c:
	/* 0x2d6c: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2d71:
	/* 0x2d71: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2d77:
	/* 0x2d77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d81:
	/* 0x2d81: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d85:
	/* 0x2d85: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8f:
	/* 0x2d8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d91:
	/* 0x2d91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d96:
	/* 0x2d96: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9b:
	/* 0x2d9b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da0:
	/* 0x2da0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da5:
	/* 0x2da5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da7:
	/* 0x2da7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dac:
	/* 0x2dac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db1:
	/* 0x2db1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2db6:
	/* 0x2db6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dbb:
	/* 0x2dbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbd:
	/* 0x2dbd: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc2:
	/* 0x2dc2: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dcb:
	/* 0x2dcb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2dd8:
	/* 0x2dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dda:
	/* 0x2dda: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de4:
	/* 0x2de4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2de8:
	/* 0x2de8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ded:
	/* 0x2ded: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2df2:
	/* 0x2df2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df7:
	/* 0x2df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df9:
	/* 0x2df9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfe:
	/* 0x2dfe: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e01:
	/* 0x2e01: je     2e76 <trace_ret_vfs_read_tail+0x2e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e76;
	}
x86_l_2e03:
	/* 0x2e03: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e08:
	/* 0x2e08: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2e0b:
	/* 0x2e0b: je     2e76 <trace_ret_vfs_read_tail+0x2e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e76;
	}
x86_l_2e0d:
	/* 0x2e0d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e11:
	/* 0x2e11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e16:
	/* 0x2e16: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e20:
	/* 0x2e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e22:
	/* 0x2e22: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2e26:
	/* 0x2e26: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e28:
	/* 0x2e28: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e2e:
	/* 0x2e2e: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2e31:
	/* 0x2e31: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e33:
	/* 0x2e33: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2e39:
	/* 0x2e39: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e3e:
	/* 0x2e3e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e44:
	/* 0x2e44: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2e49:
	/* 0x2e49: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2e4e:
	/* 0x2e4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e50:
	/* 0x2e50: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e53:
	/* 0x2e53: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2e59:
	/* 0x2e59: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e5d:
	/* 0x2e5d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e63:
	/* 0x2e63: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e68:
	/* 0x2e68: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e6c:
	/* 0x2e6c: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e6f:
	/* 0x2e6f: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e74:
	/* 0x2e74: jmp    2ede <trace_ret_vfs_read_tail+0x2ede> */
	goto x86_l_2ede;
x86_l_2e76:
	/* 0x2e76: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e79:
	/* 0x2e79: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2e7f:
	/* 0x2e7f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e84:
	/* 0x2e84: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2e89:
	/* 0x2e89: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2e8f:
	/* 0x2e8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e94:
	/* 0x2e94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e99:
	/* 0x2e99: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e9d:
	/* 0x2e9d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea7:
	/* 0x2ea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea9:
	/* 0x2ea9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eae:
	/* 0x2eae: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb3:
	/* 0x2eb3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebd:
	/* 0x2ebd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebf:
	/* 0x2ebf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ec4:
	/* 0x2ec4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ec9:
	/* 0x2ec9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ece:
	/* 0x2ece: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ed3:
	/* 0x2ed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed5:
	/* 0x2ed5: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eda:
	/* 0x2eda: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ede:
	/* 0x2ede: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ee3:
	/* 0x2ee3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eed:
	/* 0x2eed: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ef0:
	/* 0x2ef0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef2:
	/* 0x2ef2: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ef7:
	/* 0x2ef7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2efc:
	/* 0x2efc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f00:
	/* 0x2f00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f05:
	/* 0x2f05: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f0a:
	/* 0x2f0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f0f:
	/* 0x2f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f11:
	/* 0x2f11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f16:
	/* 0x2f16: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f19:
	/* 0x2f19: je     2f8e <trace_ret_vfs_read_tail+0x2f8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f8e;
	}
x86_l_2f1b:
	/* 0x2f1b: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f20:
	/* 0x2f20: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2f23:
	/* 0x2f23: je     2f8e <trace_ret_vfs_read_tail+0x2f8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f8e;
	}
x86_l_2f25:
	/* 0x2f25: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f29:
	/* 0x2f29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f2e:
	/* 0x2f2e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f33:
	/* 0x2f33: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f38:
	/* 0x2f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3a:
	/* 0x2f3a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2f3e:
	/* 0x2f3e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f40:
	/* 0x2f40: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f46:
	/* 0x2f46: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2f49:
	/* 0x2f49: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f4b:
	/* 0x2f4b: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_2f51:
	/* 0x2f51: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f56:
	/* 0x2f56: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f5c:
	/* 0x2f5c: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2f61:
	/* 0x2f61: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f66:
	/* 0x2f66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f68:
	/* 0x2f68: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f6b:
	/* 0x2f6b: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_2f71:
	/* 0x2f71: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f75:
	/* 0x2f75: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f80:
	/* 0x2f80: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f84:
	/* 0x2f84: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f87:
	/* 0x2f87: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f8c:
	/* 0x2f8c: jmp    2ff6 <trace_ret_vfs_read_tail+0x2ff6> */
	goto x86_l_2ff6;
x86_l_2f8e:
	/* 0x2f8e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f91:
	/* 0x2f91: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_2f97:
	/* 0x2f97: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f9c:
	/* 0x2f9c: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2fa1:
	/* 0x2fa1: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_2fa7:
	/* 0x2fa7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fac:
	/* 0x2fac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb1:
	/* 0x2fb1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fb5:
	/* 0x2fb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fba:
	/* 0x2fba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fbf:
	/* 0x2fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc1:
	/* 0x2fc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fc6:
	/* 0x2fc6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fcb:
	/* 0x2fcb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd0:
	/* 0x2fd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd5:
	/* 0x2fd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd7:
	/* 0x2fd7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fdc:
	/* 0x2fdc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fe1:
	/* 0x2fe1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fe6:
	/* 0x2fe6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2feb:
	/* 0x2feb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fed:
	/* 0x2fed: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff2:
	/* 0x2ff2: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ff6:
	/* 0x2ff6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ffb:
	/* 0x2ffb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3000:
	/* 0x3000: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3005:
	/* 0x3005: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3008:
	/* 0x3008: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300a:
	/* 0x300a: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_300f:
	/* 0x300f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3014:
	/* 0x3014: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3018:
	/* 0x3018: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_301d:
	/* 0x301d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3022:
	/* 0x3022: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3027:
	/* 0x3027: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3029:
	/* 0x3029: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302e:
	/* 0x302e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3031:
	/* 0x3031: je     30a6 <trace_ret_vfs_read_tail+0x30a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30a6;
	}
x86_l_3033:
	/* 0x3033: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3038:
	/* 0x3038: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_303b:
	/* 0x303b: je     30a6 <trace_ret_vfs_read_tail+0x30a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30a6;
	}
x86_l_303d:
	/* 0x303d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3041:
	/* 0x3041: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3046:
	/* 0x3046: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_304b:
	/* 0x304b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3050:
	/* 0x3050: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3052:
	/* 0x3052: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3056:
	/* 0x3056: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3058:
	/* 0x3058: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_305e:
	/* 0x305e: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3061:
	/* 0x3061: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3063:
	/* 0x3063: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_3069:
	/* 0x3069: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_306e:
	/* 0x306e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3074:
	/* 0x3074: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_3079:
	/* 0x3079: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_307e:
	/* 0x307e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3080:
	/* 0x3080: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3083:
	/* 0x3083: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_3089:
	/* 0x3089: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_308d:
	/* 0x308d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3093:
	/* 0x3093: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3098:
	/* 0x3098: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_309c:
	/* 0x309c: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_309f:
	/* 0x309f: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a4:
	/* 0x30a4: jmp    310e <trace_ret_vfs_read_tail+0x310e> */
	return 12558ULL;
x86_l_30a6:
	/* 0x30a6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30a9:
	/* 0x30a9: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_30af:
	/* 0x30af: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30b4:
	/* 0x30b4: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_30b9:
	/* 0x30b9: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_30bf:
	/* 0x30bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c4:
	/* 0x30c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c9:
	/* 0x30c9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30cd:
	/* 0x30cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30d2:
	/* 0x30d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d7:
	/* 0x30d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d9:
	/* 0x30d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30de:
	/* 0x30de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e3:
	/* 0x30e3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e8:
	/* 0x30e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ed:
	/* 0x30ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ef:
	/* 0x30ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30f4:
	/* 0x30f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 12537ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_read_tail_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12554ULL: goto x86_l_310a;
	case 12558ULL: goto x86_l_310e;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12576ULL: goto x86_l_3120;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12588ULL: goto x86_l_312c;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12617ULL: goto x86_l_3149;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12627ULL: goto x86_l_3153;
	case 12629ULL: goto x86_l_3155;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12643ULL: goto x86_l_3163;
	case 12648ULL: goto x86_l_3168;
	case 12650ULL: goto x86_l_316a;
	case 12654ULL: goto x86_l_316e;
	case 12656ULL: goto x86_l_3170;
	case 12662ULL: goto x86_l_3176;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12696ULL: goto x86_l_3198;
	case 12699ULL: goto x86_l_319b;
	case 12705ULL: goto x86_l_31a1;
	case 12709ULL: goto x86_l_31a5;
	case 12715ULL: goto x86_l_31ab;
	case 12720ULL: goto x86_l_31b0;
	case 12724ULL: goto x86_l_31b4;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12743ULL: goto x86_l_31c7;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12783ULL: goto x86_l_31ef;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12822ULL: goto x86_l_3216;
	case 12827ULL: goto x86_l_321b;
	case 12829ULL: goto x86_l_321d;
	case 12834ULL: goto x86_l_3222;
	case 12838ULL: goto x86_l_3226;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12856ULL: goto x86_l_3238;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12897ULL: goto x86_l_3261;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12909ULL: goto x86_l_326d;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12930ULL: goto x86_l_3282;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12942ULL: goto x86_l_328e;
	case 12945ULL: goto x86_l_3291;
	case 12947ULL: goto x86_l_3293;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12964ULL: goto x86_l_32a4;
	case 12969ULL: goto x86_l_32a9;
	case 12974ULL: goto x86_l_32ae;
	case 12976ULL: goto x86_l_32b0;
	case 12979ULL: goto x86_l_32b3;
	case 12985ULL: goto x86_l_32b9;
	case 12989ULL: goto x86_l_32bd;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13004ULL: goto x86_l_32cc;
	case 13007ULL: goto x86_l_32cf;
	case 13012ULL: goto x86_l_32d4;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13033ULL: goto x86_l_32e9;
	case 13039ULL: goto x86_l_32ef;
	case 13044ULL: goto x86_l_32f4;
	case 13049ULL: goto x86_l_32f9;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13102ULL: goto x86_l_332e;
	case 13107ULL: goto x86_l_3333;
	case 13109ULL: goto x86_l_3335;
	case 13114ULL: goto x86_l_333a;
	case 13118ULL: goto x86_l_333e;
	case 13123ULL: goto x86_l_3343;
	case 13128ULL: goto x86_l_3348;
	case 13133ULL: goto x86_l_334d;
	case 13136ULL: goto x86_l_3350;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13152ULL: goto x86_l_3360;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13169ULL: goto x86_l_3371;
	case 13174ULL: goto x86_l_3376;
	case 13177ULL: goto x86_l_3379;
	case 13179ULL: goto x86_l_337b;
	case 13184ULL: goto x86_l_3380;
	case 13187ULL: goto x86_l_3383;
	case 13189ULL: goto x86_l_3385;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13210ULL: goto x86_l_339a;
	case 13214ULL: goto x86_l_339e;
	case 13216ULL: goto x86_l_33a0;
	case 13222ULL: goto x86_l_33a6;
	case 13225ULL: goto x86_l_33a9;
	case 13227ULL: goto x86_l_33ab;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13259ULL: goto x86_l_33cb;
	case 13265ULL: goto x86_l_33d1;
	case 13269ULL: goto x86_l_33d5;
	case 13275ULL: goto x86_l_33db;
	case 13280ULL: goto x86_l_33e0;
	case 13284ULL: goto x86_l_33e4;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13294ULL: goto x86_l_33ee;
	case 13297ULL: goto x86_l_33f1;
	case 13303ULL: goto x86_l_33f7;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13365ULL: goto x86_l_3435;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13382ULL: goto x86_l_3446;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13416ULL: goto x86_l_3468;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13449ULL: goto x86_l_3489;
	case 13454ULL: goto x86_l_348e;
	case 13457ULL: goto x86_l_3491;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13467ULL: goto x86_l_349b;
	case 13469ULL: goto x86_l_349d;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13490ULL: goto x86_l_34b2;
	case 13494ULL: goto x86_l_34b6;
	case 13496ULL: goto x86_l_34b8;
	case 13502ULL: goto x86_l_34be;
	case 13505ULL: goto x86_l_34c1;
	case 13507ULL: goto x86_l_34c3;
	case 13513ULL: goto x86_l_34c9;
	case 13518ULL: goto x86_l_34ce;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13536ULL: goto x86_l_34e0;
	case 13539ULL: goto x86_l_34e3;
	case 13545ULL: goto x86_l_34e9;
	case 13549ULL: goto x86_l_34ed;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13564ULL: goto x86_l_34fc;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13577ULL: goto x86_l_3509;
	case 13580ULL: goto x86_l_350c;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13596ULL: goto x86_l_351c;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13628ULL: goto x86_l_353c;
	case 13633ULL: goto x86_l_3541;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13650ULL: goto x86_l_3552;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30f9:
	/* 0x30f9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30fe:
	/* 0x30fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3103:
	/* 0x3103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3105:
	/* 0x3105: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_310a:
	/* 0x310a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_310e:
	/* 0x310e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3113:
	/* 0x3113: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3118:
	/* 0x3118: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_311d:
	/* 0x311d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3120:
	/* 0x3120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3122:
	/* 0x3122: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3127:
	/* 0x3127: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_312c:
	/* 0x312c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3130:
	/* 0x3130: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3135:
	/* 0x3135: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_313a:
	/* 0x313a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_313f:
	/* 0x313f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3141:
	/* 0x3141: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3146:
	/* 0x3146: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3149:
	/* 0x3149: je     31be <trace_ret_vfs_read_tail+0x31be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31be;
	}
x86_l_314b:
	/* 0x314b: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3150:
	/* 0x3150: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3153:
	/* 0x3153: je     31be <trace_ret_vfs_read_tail+0x31be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31be;
	}
x86_l_3155:
	/* 0x3155: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3159:
	/* 0x3159: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_315e:
	/* 0x315e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3163:
	/* 0x3163: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3168:
	/* 0x3168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316a:
	/* 0x316a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_316e:
	/* 0x316e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3170:
	/* 0x3170: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3176:
	/* 0x3176: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3179:
	/* 0x3179: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_317b:
	/* 0x317b: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_3181:
	/* 0x3181: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3186:
	/* 0x3186: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_318c:
	/* 0x318c: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_3191:
	/* 0x3191: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3196:
	/* 0x3196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3198:
	/* 0x3198: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_319b:
	/* 0x319b: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_31a1:
	/* 0x31a1: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_31a5:
	/* 0x31a5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_31ab:
	/* 0x31ab: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31b0:
	/* 0x31b0: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_31b4:
	/* 0x31b4: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31b7:
	/* 0x31b7: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31bc:
	/* 0x31bc: jmp    3226 <trace_ret_vfs_read_tail+0x3226> */
	goto x86_l_3226;
x86_l_31be:
	/* 0x31be: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31c1:
	/* 0x31c1: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_31c7:
	/* 0x31c7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31cc:
	/* 0x31cc: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_31d1:
	/* 0x31d1: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_31d7:
	/* 0x31d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31dc:
	/* 0x31dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e1:
	/* 0x31e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31e5:
	/* 0x31e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ea:
	/* 0x31ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ef:
	/* 0x31ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f1:
	/* 0x31f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31f6:
	/* 0x31f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fb:
	/* 0x31fb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3200:
	/* 0x3200: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3205:
	/* 0x3205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3207:
	/* 0x3207: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_320c:
	/* 0x320c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3211:
	/* 0x3211: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3216:
	/* 0x3216: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_321b:
	/* 0x321b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321d:
	/* 0x321d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3222:
	/* 0x3222: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3226:
	/* 0x3226: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_322b:
	/* 0x322b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3230:
	/* 0x3230: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3235:
	/* 0x3235: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3238:
	/* 0x3238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323a:
	/* 0x323a: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_323f:
	/* 0x323f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3244:
	/* 0x3244: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3248:
	/* 0x3248: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_324d:
	/* 0x324d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3252:
	/* 0x3252: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3257:
	/* 0x3257: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3259:
	/* 0x3259: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325e:
	/* 0x325e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3261:
	/* 0x3261: je     32d6 <trace_ret_vfs_read_tail+0x32d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d6;
	}
x86_l_3263:
	/* 0x3263: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3268:
	/* 0x3268: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_326b:
	/* 0x326b: je     32d6 <trace_ret_vfs_read_tail+0x32d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d6;
	}
x86_l_326d:
	/* 0x326d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3271:
	/* 0x3271: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3276:
	/* 0x3276: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_327b:
	/* 0x327b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3280:
	/* 0x3280: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3282:
	/* 0x3282: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3286:
	/* 0x3286: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3288:
	/* 0x3288: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_328e:
	/* 0x328e: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3291:
	/* 0x3291: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3293:
	/* 0x3293: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_3299:
	/* 0x3299: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_329e:
	/* 0x329e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_32a4:
	/* 0x32a4: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_32a9:
	/* 0x32a9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_32ae:
	/* 0x32ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b0:
	/* 0x32b0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32b3:
	/* 0x32b3: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_32b9:
	/* 0x32b9: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_32bd:
	/* 0x32bd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_32c3:
	/* 0x32c3: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32c8:
	/* 0x32c8: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_32cc:
	/* 0x32cc: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32cf:
	/* 0x32cf: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d4:
	/* 0x32d4: jmp    333e <trace_ret_vfs_read_tail+0x333e> */
	goto x86_l_333e;
x86_l_32d6:
	/* 0x32d6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32d9:
	/* 0x32d9: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_32df:
	/* 0x32df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e4:
	/* 0x32e4: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_32e9:
	/* 0x32e9: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_32ef:
	/* 0x32ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32f4:
	/* 0x32f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f9:
	/* 0x32f9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32fd:
	/* 0x32fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3302:
	/* 0x3302: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3307:
	/* 0x3307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3309:
	/* 0x3309: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_330e:
	/* 0x330e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3313:
	/* 0x3313: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3318:
	/* 0x3318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_331d:
	/* 0x331d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331f:
	/* 0x331f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3324:
	/* 0x3324: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3329:
	/* 0x3329: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_332e:
	/* 0x332e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3333:
	/* 0x3333: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3335:
	/* 0x3335: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_333a:
	/* 0x333a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_333e:
	/* 0x333e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3343:
	/* 0x3343: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3348:
	/* 0x3348: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_334d:
	/* 0x334d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3350:
	/* 0x3350: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3352:
	/* 0x3352: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3357:
	/* 0x3357: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_335c:
	/* 0x335c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3360:
	/* 0x3360: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3365:
	/* 0x3365: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_336a:
	/* 0x336a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_336f:
	/* 0x336f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3371:
	/* 0x3371: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3376:
	/* 0x3376: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3379:
	/* 0x3379: je     33ee <trace_ret_vfs_read_tail+0x33ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33ee;
	}
x86_l_337b:
	/* 0x337b: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3380:
	/* 0x3380: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3383:
	/* 0x3383: je     33ee <trace_ret_vfs_read_tail+0x33ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33ee;
	}
x86_l_3385:
	/* 0x3385: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3389:
	/* 0x3389: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_338e:
	/* 0x338e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3393:
	/* 0x3393: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3398:
	/* 0x3398: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339a:
	/* 0x339a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_339e:
	/* 0x339e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_33a0:
	/* 0x33a0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_33a6:
	/* 0x33a6: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_33a9:
	/* 0x33a9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33ab:
	/* 0x33ab: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_33b1:
	/* 0x33b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33b6:
	/* 0x33b6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_33bc:
	/* 0x33bc: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_33c1:
	/* 0x33c1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_33c6:
	/* 0x33c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c8:
	/* 0x33c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33cb:
	/* 0x33cb: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_33d1:
	/* 0x33d1: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_33d5:
	/* 0x33d5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_33db:
	/* 0x33db: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_33e0:
	/* 0x33e0: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_33e4:
	/* 0x33e4: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33e7:
	/* 0x33e7: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ec:
	/* 0x33ec: jmp    3456 <trace_ret_vfs_read_tail+0x3456> */
	goto x86_l_3456;
x86_l_33ee:
	/* 0x33ee: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_33f1:
	/* 0x33f1: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_33f7:
	/* 0x33f7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33fc:
	/* 0x33fc: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3401:
	/* 0x3401: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_3407:
	/* 0x3407: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_340c:
	/* 0x340c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3411:
	/* 0x3411: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3415:
	/* 0x3415: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_341a:
	/* 0x341a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_341f:
	/* 0x341f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3421:
	/* 0x3421: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3426:
	/* 0x3426: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342b:
	/* 0x342b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3430:
	/* 0x3430: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3435:
	/* 0x3435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3437:
	/* 0x3437: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_343c:
	/* 0x343c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3441:
	/* 0x3441: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3446:
	/* 0x3446: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_344b:
	/* 0x344b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344d:
	/* 0x344d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3452:
	/* 0x3452: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3456:
	/* 0x3456: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_345b:
	/* 0x345b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3460:
	/* 0x3460: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3465:
	/* 0x3465: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3468:
	/* 0x3468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_346a:
	/* 0x346a: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_346f:
	/* 0x346f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3474:
	/* 0x3474: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3478:
	/* 0x3478: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_347d:
	/* 0x347d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3482:
	/* 0x3482: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3487:
	/* 0x3487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3489:
	/* 0x3489: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348e:
	/* 0x348e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3491:
	/* 0x3491: je     3509 <trace_ret_vfs_read_tail+0x3509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3509;
	}
x86_l_3493:
	/* 0x3493: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3498:
	/* 0x3498: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_349b:
	/* 0x349b: je     3509 <trace_ret_vfs_read_tail+0x3509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3509;
	}
x86_l_349d:
	/* 0x349d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34a1:
	/* 0x34a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34a6:
	/* 0x34a6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34ab:
	/* 0x34ab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_34b0:
	/* 0x34b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b2:
	/* 0x34b2: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_34b6:
	/* 0x34b6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_34b8:
	/* 0x34b8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34be:
	/* 0x34be: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_34c1:
	/* 0x34c1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34c3:
	/* 0x34c3: jb     13a8 <trace_ret_vfs_read_tail+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5032ULL;
	}
x86_l_34c9:
	/* 0x34c9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34ce:
	/* 0x34ce: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_34d4:
	/* 0x34d4: add    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_34d9:
	/* 0x34d9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_34de:
	/* 0x34de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e0:
	/* 0x34e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34e3:
	/* 0x34e3: jl     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5348ULL;
	}
x86_l_34e9:
	/* 0x34e9: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_34ed:
	/* 0x34ed: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34f3:
	/* 0x34f3: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_34f8:
	/* 0x34f8: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34fc:
	/* 0x34fc: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34ff:
	/* 0x34ff: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3504:
	/* 0x3504: jmp    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	return 5348ULL;
x86_l_3509:
	/* 0x3509: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_350c:
	/* 0x350c: jne    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_3512:
	/* 0x3512: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3517:
	/* 0x3517: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_351c:
	/* 0x351c: je     14e4 <trace_ret_vfs_read_tail+0x14e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5348ULL;
	}
x86_l_3522:
	/* 0x3522: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3527:
	/* 0x3527: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_352c:
	/* 0x352c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3530:
	/* 0x3530: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3535:
	/* 0x3535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_353a:
	/* 0x353a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353c:
	/* 0x353c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3541:
	/* 0x3541: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3546:
	/* 0x3546: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_354b:
	/* 0x354b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3550:
	/* 0x3550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3552:
	/* 0x3552: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3557:
	/* 0x3557: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355c:
	/* 0x355c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3561:
	/* 0x3561: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3566:
	/* 0x3566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3568:
	/* 0x3568: jmp    14e4 <trace_ret_vfs_read_tail+0x14e4> */
	return 5348ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_vfs_read_tail_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11824U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2166ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2171ULL && __x86_pc <= 3894ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3899ULL && __x86_pc <= 5640ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5645ULL && __x86_pc <= 7403ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7408ULL && __x86_pc <= 9219ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9224ULL && __x86_pc <= 10899ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10902ULL && __x86_pc <= 12532ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12537ULL && __x86_pc <= 13672ULL)
			__x86_pc = tracee_trace_ret_vfs_read_tail_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

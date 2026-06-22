extern char args_map;
extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char elf_files_map;
extern char event_data_map;
extern char file_type_filter;
extern char file_write_path_filter;
extern char io_file_path_cache_map;
extern char ksymbols_map;
extern char logs;
extern char logs_count;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char prog_array;
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

static const __u64 __x86_rodata_0[2] = {8464849087293777967ULL, 8588143708369942382ULL};

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_0(
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
	case 47ULL: goto x86_l_2f;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 59ULL: goto x86_l_3b;
	case 62ULL: goto x86_l_3e;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 75ULL: goto x86_l_4b;
	case 83ULL: goto x86_l_53;
	case 87ULL: goto x86_l_57;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 102ULL: goto x86_l_66;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 119ULL: goto x86_l_77;
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
	case 175ULL: goto x86_l_af;
	case 177ULL: goto x86_l_b1;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 214ULL: goto x86_l_d6;
	case 217ULL: goto x86_l_d9;
	case 219ULL: goto x86_l_db;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 246ULL: goto x86_l_f6;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 255ULL: goto x86_l_ff;
	case 259ULL: goto x86_l_103;
	case 261ULL: goto x86_l_105;
	case 268ULL: goto x86_l_10c;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 302ULL: goto x86_l_12e;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 330ULL: goto x86_l_14a;
	case 333ULL: goto x86_l_14d;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 350ULL: goto x86_l_15e;
	case 352ULL: goto x86_l_160;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 380ULL: goto x86_l_17c;
	case 389ULL: goto x86_l_185;
	case 401ULL: goto x86_l_191;
	case 413ULL: goto x86_l_19d;
	case 425ULL: goto x86_l_1a9;
	case 437ULL: goto x86_l_1b5;
	case 449ULL: goto x86_l_1c1;
	case 461ULL: goto x86_l_1cd;
	case 473ULL: goto x86_l_1d9;
	case 485ULL: goto x86_l_1e5;
	case 493ULL: goto x86_l_1ed;
	case 502ULL: goto x86_l_1f6;
	case 511ULL: goto x86_l_1ff;
	case 520ULL: goto x86_l_208;
	case 529ULL: goto x86_l_211;
	case 538ULL: goto x86_l_21a;
	case 547ULL: goto x86_l_223;
	case 556ULL: goto x86_l_22c;
	case 565ULL: goto x86_l_235;
	case 574ULL: goto x86_l_23e;
	case 583ULL: goto x86_l_247;
	case 592ULL: goto x86_l_250;
	case 601ULL: goto x86_l_259;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 626ULL: goto x86_l_272;
	case 631ULL: goto x86_l_277;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 658ULL: goto x86_l_292;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 684ULL: goto x86_l_2ac;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 710ULL: goto x86_l_2c6;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 724ULL: goto x86_l_2d4;
	case 731ULL: goto x86_l_2db;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 746ULL: goto x86_l_2ea;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 758ULL: goto x86_l_2f6;
	case 762ULL: goto x86_l_2fa;
	case 768ULL: goto x86_l_300;
	case 773ULL: goto x86_l_305;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 795ULL: goto x86_l_31b;
	case 802ULL: goto x86_l_322;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 817ULL: goto x86_l_331;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 830ULL: goto x86_l_33e;
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
	case 1054ULL: goto x86_l_41e;
	case 1065ULL: goto x86_l_429;
	case 1076ULL: goto x86_l_434;
	case 1087ULL: goto x86_l_43f;
	case 1098ULL: goto x86_l_44a;
	case 1109ULL: goto x86_l_455;
	case 1120ULL: goto x86_l_460;
	case 1131ULL: goto x86_l_46b;
	case 1142ULL: goto x86_l_476;
	case 1153ULL: goto x86_l_481;
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
	case 1252ULL: goto x86_l_4e4;
	case 1260ULL: goto x86_l_4ec;
	case 1268ULL: goto x86_l_4f4;
	case 1276ULL: goto x86_l_4fc;
	case 1284ULL: goto x86_l_504;
	case 1291ULL: goto x86_l_50b;
	case 1298ULL: goto x86_l_512;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1331ULL: goto x86_l_533;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1341ULL: goto x86_l_53d;
	case 1347ULL: goto x86_l_543;
	case 1352ULL: goto x86_l_548;
	case 1359ULL: goto x86_l_54f;
	case 1363ULL: goto x86_l_553;
	case 1371ULL: goto x86_l_55b;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1395ULL: goto x86_l_573;
	case 1398ULL: goto x86_l_576;
	case 1404ULL: goto x86_l_57c;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1415ULL: goto x86_l_587;
	case 1426ULL: goto x86_l_592;
	case 1437ULL: goto x86_l_59d;
	case 1448ULL: goto x86_l_5a8;
	case 1459ULL: goto x86_l_5b3;
	case 1470ULL: goto x86_l_5be;
	case 1481ULL: goto x86_l_5c9;
	case 1492ULL: goto x86_l_5d4;
	case 1503ULL: goto x86_l_5df;
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
	case 1610ULL: goto x86_l_64a;
	case 1618ULL: goto x86_l_652;
	case 1626ULL: goto x86_l_65a;
	case 1634ULL: goto x86_l_662;
	case 1641ULL: goto x86_l_669;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1666ULL: goto x86_l_682;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1683ULL: goto x86_l_693;
	case 1686ULL: goto x86_l_696;
	case 1692ULL: goto x86_l_69c;
	case 1695ULL: goto x86_l_69f;
	case 1703ULL: goto x86_l_6a7;
	case 1707ULL: goto x86_l_6ab;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1817ULL: goto x86_l_719;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1883ULL: goto x86_l_75b;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1913ULL: goto x86_l_779;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1951ULL: goto x86_l_79f;
	case 1953ULL: goto x86_l_7a1;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1984ULL: goto x86_l_7c0;
	case 1989ULL: goto x86_l_7c5;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2050ULL: goto x86_l_802;
	case 2052ULL: goto x86_l_804;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2090ULL: goto x86_l_82a;
	case 2094ULL: goto x86_l_82e;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
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
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: movabs rbx,0x2ef00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3225520439296ULL);
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
	/* 0x28: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_2f:
	/* 0x2f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34:
	/* 0x34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39:
	/* 0x39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b:
	/* 0x3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_44:
	/* 0x44: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47:
	/* 0x47: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b:
	/* 0x4b: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_53:
	/* 0x53: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57:
	/* 0x57: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
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
	/* 0x70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_77:
	/* 0x77: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7c:
	/* 0x7c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
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
	/* 0x8a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
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
	/* 0x9b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a0:
	/* 0xa0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a5:
	/* 0xa5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aa:
	/* 0xaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_af:
	/* 0xaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1:
	/* 0xb1: test   DWORD PTR [rsp+0x50],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343599480832ULL);
x86_l_b9:
	/* 0xb9: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_be:
	/* 0xbe: jne    126 <trace_ret_kernel_write_tail+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_126;
	}
x86_l_c0:
	/* 0xc0: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_c5:
	/* 0xc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7:
	/* 0xc7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_cf:
	/* 0xcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1:
	/* 0xd1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4:
	/* 0xd4: je     db <trace_ret_kernel_write_tail+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db;
	}
x86_l_d6:
	/* 0xd6: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d9:
	/* 0xd9: jmp    db <trace_ret_kernel_write_tail+0xdb> */
	goto x86_l_db;
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df:
	/* 0xdf: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e4:
	/* 0xe4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e9:
	/* 0xe9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ee:
	/* 0xee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f3:
	/* 0xf3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f6:
	/* 0xf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8:
	/* 0xf8: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_fd:
	/* 0xfd: jne    105 <trace_ret_kernel_write_tail+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105;
	}
x86_l_ff:
	/* 0xff: mov    ebx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_103:
	/* 0x103: jmp    126 <trace_ret_kernel_write_tail+0x126> */
	goto x86_l_126;
x86_l_105:
	/* 0x105: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_10c:
	/* 0x10c: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_111:
	/* 0x111: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116:
	/* 0x116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118:
	/* 0x118: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: je     121 <trace_ret_kernel_write_tail+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121;
	}
x86_l_11d:
	/* 0x11d: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f:
	/* 0x11f: jmp    126 <trace_ret_kernel_write_tail+0x126> */
	goto x86_l_126;
x86_l_121:
	/* 0x121: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_126:
	/* 0x126: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_12e:
	/* 0x12e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_135:
	/* 0x135: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a:
	/* 0x13a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f:
	/* 0x13f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141:
	/* 0x141: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_144:
	/* 0x144: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_14a:
	/* 0x14a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_14d:
	/* 0x14d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_154:
	/* 0x154: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_159:
	/* 0x159: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15e:
	/* 0x15e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160:
	/* 0x160: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_168:
	/* 0x168: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_171:
	/* 0x171: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_17c:
	/* 0x17c: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_185:
	/* 0x185: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1b5:
	/* 0x1b5: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1d9:
	/* 0x1d9: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1e5:
	/* 0x1e5: mov    QWORD PTR [r12+0x7dd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1ed:
	/* 0x1ed: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ff:
	/* 0x1ff: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_208:
	/* 0x208: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_211:
	/* 0x211: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_223:
	/* 0x223: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_22c:
	/* 0x22c: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_235:
	/* 0x235: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_247:
	/* 0x247: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_250:
	/* 0x250: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_259:
	/* 0x259: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_262:
	/* 0x262: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_267:
	/* 0x267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269:
	/* 0x269: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26e:
	/* 0x26e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_272:
	/* 0x272: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_277:
	/* 0x277: mov    DWORD PTR [r12+0x70],0x31b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337947ULL);
x86_l_280:
	/* 0x280: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_285:
	/* 0x285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287:
	/* 0x287: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b:
	/* 0x28b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_290:
	/* 0x290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292:
	/* 0x292: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_298:
	/* 0x298: mov    DWORD PTR [r12+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_29d:
	/* 0x29d: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2a2:
	/* 0x2a2: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5:
	/* 0x2a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2ac:
	/* 0x2ac: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2af:
	/* 0x2af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4:
	/* 0x2b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6:
	/* 0x2b6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bb:
	/* 0x2bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c6:
	/* 0x2c6: je     30c <trace_ret_kernel_write_tail+0x30c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c;
	}
x86_l_2c8:
	/* 0x2c8: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd:
	/* 0x2cd: mov    DWORD PTR [rsp+0xb8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2d4:
	/* 0x2d4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2db:
	/* 0x2db: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
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
	/* 0x2f0: je     548 <trace_ret_kernel_write_tail+0x548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_548;
	}
x86_l_2f6:
	/* 0x2f6: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2fa:
	/* 0x2fa: jne    b6d <trace_ret_kernel_write_tail+0xb6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2925ULL;
	}
x86_l_300:
	/* 0x300: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_305:
	/* 0x305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_307:
	/* 0x307: jmp    c18 <trace_ret_kernel_write_tail+0xc18> */
	return 3096ULL;
x86_l_30c:
	/* 0x30c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f:
	/* 0x30f: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_313:
	/* 0x313: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_31b:
	/* 0x31b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_322:
	/* 0x322: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327:
	/* 0x327: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32c:
	/* 0x32c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e:
	/* 0x32e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_331:
	/* 0x331: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_337:
	/* 0x337: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33e:
	/* 0x33e: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_342:
	/* 0x342: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_34d:
	/* 0x34d: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_358:
	/* 0x358: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_363:
	/* 0x363: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_36e:
	/* 0x36e: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_379:
	/* 0x379: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_384:
	/* 0x384: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_39a:
	/* 0x39a: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_3a5:
	/* 0x3a5: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_3b0:
	/* 0x3b0: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3bb:
	/* 0x3bb: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3c6:
	/* 0x3c6: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3d1:
	/* 0x3d1: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3dc:
	/* 0x3dc: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3e7:
	/* 0x3e7: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3f2:
	/* 0x3f2: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3fd:
	/* 0x3fd: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_408:
	/* 0x408: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_413:
	/* 0x413: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_41e:
	/* 0x41e: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_429:
	/* 0x429: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_43f:
	/* 0x43f: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_44a:
	/* 0x44a: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_455:
	/* 0x455: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_460:
	/* 0x460: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_481:
	/* 0x481: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_494:
	/* 0x494: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_49c:
	/* 0x49c: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4ac:
	/* 0x4ac: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4b4:
	/* 0x4b4: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4c4:
	/* 0x4c4: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4cc:
	/* 0x4cc: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4d4:
	/* 0x4d4: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4e4:
	/* 0x4e4: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4ec:
	/* 0x4ec: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4f4:
	/* 0x4f4: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4fc:
	/* 0x4fc: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_504:
	/* 0x504: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50b:
	/* 0x50b: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_512:
	/* 0x512: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_517:
	/* 0x517: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_51c:
	/* 0x51c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_521:
	/* 0x521: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_524:
	/* 0x524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526:
	/* 0x526: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52b:
	/* 0x52b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_530:
	/* 0x530: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_533:
	/* 0x533: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_535:
	/* 0x535: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_53a:
	/* 0x53a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53d:
	/* 0x53d: jne    2c8 <trace_ret_kernel_write_tail+0x2c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c8;
	}
x86_l_543:
	/* 0x543: jmp    30d4 <trace_ret_kernel_write_tail+0x30d4> */
	return 12500ULL;
x86_l_548:
	/* 0x548: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_54f:
	/* 0x54f: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_553:
	/* 0x553: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_55b:
	/* 0x55b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_562:
	/* 0x562: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_567:
	/* 0x567: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56c:
	/* 0x56c: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_571:
	/* 0x571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573:
	/* 0x573: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_576:
	/* 0x576: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_57c:
	/* 0x57c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_57f:
	/* 0x57f: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_583:
	/* 0x583: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_587:
	/* 0x587: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_592:
	/* 0x592: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5be:
	/* 0x5be: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5c9:
	/* 0x5c9: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5d4:
	/* 0x5d4: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5ea:
	/* 0x5ea: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5fa:
	/* 0x5fa: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_602:
	/* 0x602: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_60a:
	/* 0x60a: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_622:
	/* 0x622: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_62a:
	/* 0x62a: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_63a:
	/* 0x63a: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_642:
	/* 0x642: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_64a:
	/* 0x64a: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_652:
	/* 0x652: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_65a:
	/* 0x65a: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_662:
	/* 0x662: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_669:
	/* 0x669: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_670:
	/* 0x670: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_675:
	/* 0x675: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67a:
	/* 0x67a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_67f:
	/* 0x67f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_682:
	/* 0x682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_684:
	/* 0x684: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_689:
	/* 0x689: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68e:
	/* 0x68e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_691:
	/* 0x691: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_693:
	/* 0x693: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_696:
	/* 0x696: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_69c:
	/* 0x69c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_69f:
	/* 0x69f: mov    rbx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_6a7:
	/* 0x6a7: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ab:
	/* 0x6ab: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6b3:
	/* 0x6b3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0x6c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c9:
	/* 0x6c9: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d3:
	/* 0x6d3: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d7:
	/* 0x6d7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6dc:
	/* 0x6dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e1:
	/* 0x6e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e6:
	/* 0x6e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6eb:
	/* 0x6eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ed:
	/* 0x6ed: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6f2:
	/* 0x6f2: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6f6:
	/* 0x6f6: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6fb:
	/* 0x6fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_700:
	/* 0x700: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_705:
	/* 0x705: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70a:
	/* 0x70a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70c:
	/* 0x70c: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_711:
	/* 0x711: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_719:
	/* 0x719: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_71d:
	/* 0x71d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_722:
	/* 0x722: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_727:
	/* 0x727: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72c:
	/* 0x72c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_731:
	/* 0x731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_733:
	/* 0x733: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_737:
	/* 0x737: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_740:
	/* 0x740: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_744:
	/* 0x744: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_749:
	/* 0x749: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_74e:
	/* 0x74e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_753:
	/* 0x753: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_758:
	/* 0x758: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_75b:
	/* 0x75b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75d:
	/* 0x75d: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_762:
	/* 0x762: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_767:
	/* 0x767: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_76c:
	/* 0x76c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_771:
	/* 0x771: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_776:
	/* 0x776: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_779:
	/* 0x779: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77b:
	/* 0x77b: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_77f:
	/* 0x77f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_783:
	/* 0x783: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_787:
	/* 0x787: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_78b:
	/* 0x78b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_790:
	/* 0x790: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_795:
	/* 0x795: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_79a:
	/* 0x79a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_79f:
	/* 0x79f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a1:
	/* 0x7a1: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a5:
	/* 0x7a5: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7a9:
	/* 0x7a9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7ae:
	/* 0x7ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b8:
	/* 0x7b8: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7c0:
	/* 0x7c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7c5:
	/* 0x7c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c7:
	/* 0x7c7: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7cc:
	/* 0x7cc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7d0:
	/* 0x7d0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7d5:
	/* 0x7d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7da:
	/* 0x7da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7df:
	/* 0x7df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7eb:
	/* 0x7eb: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7f0:
	/* 0x7f0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7f5:
	/* 0x7f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7fa:
	/* 0x7fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7ff:
	/* 0x7ff: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_802:
	/* 0x802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_804:
	/* 0x804: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_808:
	/* 0x808: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_80c:
	/* 0x80c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_810:
	/* 0x810: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_814:
	/* 0x814: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_819:
	/* 0x819: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_81e:
	/* 0x81e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_823:
	/* 0x823: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_828:
	/* 0x828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82a:
	/* 0x82a: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_82e:
	/* 0x82e: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_832:
	/* 0x832: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_837:
	/* 0x837: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_83c:
	/* 0x83c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_841:
	/* 0x841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_846:
	/* 0x846: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_849:
	/* 0x849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84b:
	/* 0x84b: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_850:
	/* 0x850: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_855:
	/* 0x855: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_85a:
	/* 0x85a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_85f:
	/* 0x85f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_864:
	/* 0x864: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_867:
	/* 0x867: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_869:
	/* 0x869: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_86d:
	/* 0x86d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_871:
	/* 0x871: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_875:
	/* 0x875: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_879:
	/* 0x879: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_87e:
	/* 0x87e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_883:
	/* 0x883: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_888:
	/* 0x888: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 2189ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2189ULL: goto x86_l_88d;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2200ULL: goto x86_l_898;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2222ULL: goto x86_l_8ae;
	case 2226ULL: goto x86_l_8b2;
	case 2233ULL: goto x86_l_8b9;
	case 2241ULL: goto x86_l_8c1;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2268ULL: goto x86_l_8dc;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2304ULL: goto x86_l_900;
	case 2308ULL: goto x86_l_904;
	case 2312ULL: goto x86_l_908;
	case 2316ULL: goto x86_l_90c;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2354ULL: goto x86_l_932;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2376ULL: goto x86_l_948;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2441ULL: goto x86_l_989;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2475ULL: goto x86_l_9ab;
	case 2479ULL: goto x86_l_9af;
	case 2483ULL: goto x86_l_9b3;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2522ULL: goto x86_l_9da;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2587ULL: goto x86_l_a1b;
	case 2591ULL: goto x86_l_a1f;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2602ULL: goto x86_l_a2a;
	case 2606ULL: goto x86_l_a2e;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2681ULL: goto x86_l_a79;
	case 2689ULL: goto x86_l_a81;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2747ULL: goto x86_l_abb;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2769ULL: goto x86_l_ad1;
	case 2773ULL: goto x86_l_ad5;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2870ULL: goto x86_l_b36;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2915ULL: goto x86_l_b63;
	case 2919ULL: goto x86_l_b67;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2938ULL: goto x86_l_b7a;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2990ULL: goto x86_l_bae;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3059ULL: goto x86_l_bf3;
	case 3061ULL: goto x86_l_bf5;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3105ULL: goto x86_l_c21;
	case 3109ULL: goto x86_l_c25;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3131ULL: goto x86_l_c3b;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3149ULL: goto x86_l_c4d;
	case 3151ULL: goto x86_l_c4f;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3171ULL: goto x86_l_c63;
	case 3175ULL: goto x86_l_c67;
	case 3181ULL: goto x86_l_c6d;
	case 3193ULL: goto x86_l_c79;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3239ULL: goto x86_l_ca7;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3256ULL: goto x86_l_cb8;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3302ULL: goto x86_l_ce6;
	case 3305ULL: goto x86_l_ce9;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3317ULL: goto x86_l_cf5;
	case 3320ULL: goto x86_l_cf8;
	case 3323ULL: goto x86_l_cfb;
	case 3326ULL: goto x86_l_cfe;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3348ULL: goto x86_l_d14;
	case 3351ULL: goto x86_l_d17;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3406ULL: goto x86_l_d4e;
	case 3409ULL: goto x86_l_d51;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3423ULL: goto x86_l_d5f;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3458ULL: goto x86_l_d82;
	case 3466ULL: goto x86_l_d8a;
	case 3474ULL: goto x86_l_d92;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3517ULL: goto x86_l_dbd;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3592ULL: goto x86_l_e08;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3616ULL: goto x86_l_e20;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3639ULL: goto x86_l_e37;
	case 3642ULL: goto x86_l_e3a;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3664ULL: goto x86_l_e50;
	case 3667ULL: goto x86_l_e53;
	case 3671ULL: goto x86_l_e57;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3683ULL: goto x86_l_e63;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3797ULL: goto x86_l_ed5;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3810ULL: goto x86_l_ee2;
	case 3815ULL: goto x86_l_ee7;
	case 3823ULL: goto x86_l_eef;
	case 3831ULL: goto x86_l_ef7;
	case 3839ULL: goto x86_l_eff;
	case 3842ULL: goto x86_l_f02;
	case 3850ULL: goto x86_l_f0a;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3885ULL: goto x86_l_f2d;
	case 3888ULL: goto x86_l_f30;
	default: return 0xffffffffffffffffULL;
	}
x86_l_88d:
	/* 0x88d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88f:
	/* 0x88f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_894:
	/* 0x894: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_898:
	/* 0x898: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_89d:
	/* 0x89d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8a2:
	/* 0x8a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a7:
	/* 0x8a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8ac:
	/* 0x8ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ae:
	/* 0x8ae: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8b2:
	/* 0x8b2: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8b9:
	/* 0x8b9: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8c1:
	/* 0x8c1: lea    r14,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c5:
	/* 0x8c5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8ca:
	/* 0x8ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8cf:
	/* 0x8cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d4:
	/* 0x8d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d9:
	/* 0x8d9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_8dc:
	/* 0x8dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8de:
	/* 0x8de: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e3:
	/* 0x8e3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e8:
	/* 0x8e8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8ed:
	/* 0x8ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f2:
	/* 0x8f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8f7:
	/* 0x8f7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8fa:
	/* 0x8fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fc:
	/* 0x8fc: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_900:
	/* 0x900: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_904:
	/* 0x904: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_908:
	/* 0x908: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_90c:
	/* 0x90c: mov    ebx,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_913:
	/* 0x913: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_918:
	/* 0x918: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_91d:
	/* 0x91d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_922:
	/* 0x922: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_92e:
	/* 0x92e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_932:
	/* 0x932: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0x946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_948:
	/* 0x948: cmp    ebx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 80ULL);
x86_l_94c:
	/* 0x94c: jne    9b3 <trace_ret_kernel_write_tail+0x9b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b3;
	}
x86_l_94e:
	/* 0x94e: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_953:
	/* 0x953: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_958:
	/* 0x958: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_95d:
	/* 0x95d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_962:
	/* 0x962: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_965:
	/* 0x965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_967:
	/* 0x967: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_96c:
	/* 0x96c: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_971:
	/* 0x971: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_976:
	/* 0x976: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_97b:
	/* 0x97b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_980:
	/* 0x980: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_983:
	/* 0x983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_985:
	/* 0x985: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_989:
	/* 0x989: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_98d:
	/* 0x98d: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_991:
	/* 0x991: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_995:
	/* 0x995: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_99a:
	/* 0x99a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_99f:
	/* 0x99f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a4:
	/* 0x9a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9a9:
	/* 0x9a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ab:
	/* 0x9ab: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9af:
	/* 0x9af: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b3:
	/* 0x9b3: mov    DWORD PTR [r13+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b7:
	/* 0x9b7: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9bc:
	/* 0x9bc: lea    r14,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9c3:
	/* 0x9c3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c8:
	/* 0x9c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9cd:
	/* 0x9cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d2:
	/* 0x9d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d7:
	/* 0x9d7: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9da:
	/* 0x9da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9dc:
	/* 0x9dc: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9e1:
	/* 0x9e1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9e5:
	/* 0x9e5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ea:
	/* 0x9ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f4:
	/* 0x9f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f9:
	/* 0x9f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fb:
	/* 0x9fb: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a00:
	/* 0xa00: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a05:
	/* 0xa05: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a0a:
	/* 0xa0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a0f:
	/* 0xa0f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a14:
	/* 0xa14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a19:
	/* 0xa19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1b:
	/* 0xa1b: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a1f:
	/* 0xa1f: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a23:
	/* 0xa23: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a28:
	/* 0xa28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2a:
	/* 0xa2a: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a2e:
	/* 0xa2e: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a32:
	/* 0xa32: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a37:
	/* 0xa37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a3c:
	/* 0xa3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a41:
	/* 0xa41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a46:
	/* 0xa46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a48:
	/* 0xa48: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a51:
	/* 0xa51: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a56:
	/* 0xa56: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a5a:
	/* 0xa5a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a5f:
	/* 0xa5f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a64:
	/* 0xa64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a69:
	/* 0xa69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a6e:
	/* 0xa6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a70:
	/* 0xa70: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a75:
	/* 0xa75: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a79:
	/* 0xa79: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a81:
	/* 0xa81: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a85:
	/* 0xa85: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a8a:
	/* 0xa8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a8f:
	/* 0xa8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a94:
	/* 0xa94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a99:
	/* 0xa99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9b:
	/* 0xa9b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aa0:
	/* 0xaa0: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aa4:
	/* 0xaa4: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aa9:
	/* 0xaa9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_aae:
	/* 0xaae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ab3:
	/* 0xab3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ab8:
	/* 0xab8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_abb:
	/* 0xabb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abd:
	/* 0xabd: test   BYTE PTR [rsp+0x50],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383682ULL);
x86_l_ac2:
	/* 0xac2: je     ac9 <trace_ret_kernel_write_tail+0xac9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac9;
	}
x86_l_ac4:
	/* 0xac4: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_ac9:
	/* 0xac9: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_ad1:
	/* 0xad1: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ad5:
	/* 0xad5: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_add:
	/* 0xadd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ae2:
	/* 0xae2: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_ae7:
	/* 0xae7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_aec:
	/* 0xaec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aee:
	/* 0xaee: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af3:
	/* 0xaf3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afd:
	/* 0xafd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b02:
	/* 0xb02: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b05:
	/* 0xb05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b07:
	/* 0xb07: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b0c:
	/* 0xb0c: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b11:
	/* 0xb11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b16:
	/* 0xb16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1b:
	/* 0xb1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b20:
	/* 0xb20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b22:
	/* 0xb22: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b27:
	/* 0xb27: lea    rbx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b2c:
	/* 0xb2c: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_b31:
	/* 0xb31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b36:
	/* 0xb36: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b39:
	/* 0xb39: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b3e:
	/* 0xb3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b40:
	/* 0xb40: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b47:
	/* 0xb47: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b4c:
	/* 0xb4c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b51:
	/* 0xb51: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b56:
	/* 0xb56: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b59:
	/* 0xb59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5b:
	/* 0xb5b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b63:
	/* 0xb63: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b67:
	/* 0xb67: je     300 <trace_ret_kernel_write_tail+0x300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 768ULL;
	}
x86_l_b6d:
	/* 0xb6d: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b72:
	/* 0xb72: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b7a:
	/* 0xb7a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b7f:
	/* 0xb7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b84:
	/* 0xb84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b89:
	/* 0xb89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b8e:
	/* 0xb8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b90:
	/* 0xb90: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b95:
	/* 0xb95: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9a:
	/* 0xb9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b9f:
	/* 0xb9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba4:
	/* 0xba4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ba9:
	/* 0xba9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bae:
	/* 0xbae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb0:
	/* 0xbb0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb5:
	/* 0xbb5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bba:
	/* 0xbba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bbf:
	/* 0xbbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc4:
	/* 0xbc4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc9:
	/* 0xbc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bce:
	/* 0xbce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd0:
	/* 0xbd0: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bd5:
	/* 0xbd5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bda:
	/* 0xbda: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bdf:
	/* 0xbdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_be4:
	/* 0xbe4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be9:
	/* 0xbe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_beb:
	/* 0xbeb: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bf0:
	/* 0xbf0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bf3:
	/* 0xbf3: je     c16 <trace_ret_kernel_write_tail+0xc16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c16;
	}
x86_l_bf5:
	/* 0xbf5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bf9:
	/* 0xbf9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bfe:
	/* 0xbfe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c03:
	/* 0xc03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c08:
	/* 0xc08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c0d:
	/* 0xc0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0f:
	/* 0xc0f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c14:
	/* 0xc14: jmp    c18 <trace_ret_kernel_write_tail+0xc18> */
	goto x86_l_c18;
x86_l_c16:
	/* 0xc16: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c18:
	/* 0xc18: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c1d:
	/* 0xc1d: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c21:
	/* 0xc21: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c25:
	/* 0xc25: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c2c:
	/* 0xc2c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c31:
	/* 0xc31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c36:
	/* 0xc36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c38:
	/* 0xc38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3b:
	/* 0xc3b: je     c55 <trace_ret_kernel_write_tail+0xc55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c55;
	}
x86_l_c3d:
	/* 0xc3d: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c40:
	/* 0xc40: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c47:
	/* 0xc47: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c4a:
	/* 0xc4a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c4d:
	/* 0xc4d: jne    c55 <trace_ret_kernel_write_tail+0xc55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c55;
	}
x86_l_c4f:
	/* 0xc4f: or     BYTE PTR [r12+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c55:
	/* 0xc55: movzx  eax,WORD PTR [r12+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c5b:
	/* 0xc5b: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c63:
	/* 0xc63: cmp    ax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c67:
	/* 0xc67: jne    1fe1 <trace_ret_kernel_write_tail+0x1fe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8161ULL;
	}
x86_l_c6d:
	/* 0xc6d: mov    QWORD PTR [r12+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_c79:
	/* 0xc79: mov    QWORD PTR [r12+0x80],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781183ULL);
x86_l_c85:
	/* 0xc85: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c87:
	/* 0xc87: cmp    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_c8c:
	/* 0xc8c: jne    c9f <trace_ret_kernel_write_tail+0xc9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c9f;
	}
x86_l_c8e:
	/* 0xc8e: mov    QWORD PTR [r12+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_c9a:
	/* 0xc9a: jmp    30d4 <trace_ret_kernel_write_tail+0x30d4> */
	return 12500ULL;
x86_l_c9f:
	/* 0xc9f: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ca7:
	/* 0xca7: mov    rax,QWORD PTR [r12+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_caf:
	/* 0xcaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb2:
	/* 0xcb2: je     e5c <trace_ret_kernel_write_tail+0xe5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5c;
	}
x86_l_cb8:
	/* 0xcb8: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_cc0:
	/* 0xcc0: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_cc3:
	/* 0xcc3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc6:
	/* 0xcc6: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_cc9:
	/* 0xcc9: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_ccd:
	/* 0xccd: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cd0:
	/* 0xcd0: neg    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cd3:
	/* 0xcd3: xor    r15,QWORD PTR [r12+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_cdb:
	/* 0xcdb: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cde:
	/* 0xcde: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ce6:
	/* 0xce6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce9:
	/* 0xce9: je     d0c <trace_ret_kernel_write_tail+0xd0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d0c;
	}
x86_l_ceb:
	/* 0xceb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ced:
	/* 0xced: cmp    BYTE PTR [r13+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_cf5:
	/* 0xcf5: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cf8:
	/* 0xcf8: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cfb:
	/* 0xcfb: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cfe:
	/* 0xcfe: xor    rcx,QWORD PTR [r12+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d06:
	/* 0xd06: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d09:
	/* 0xd09: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d0c:
	/* 0xd0c: mov    rax,QWORD PTR [r12+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d14:
	/* 0xd14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d17:
	/* 0xd17: je     d35 <trace_ret_kernel_write_tail+0xd35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d35;
	}
x86_l_d19:
	/* 0xd19: mov    ecx,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d1e:
	/* 0xd1e: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d21:
	/* 0xd21: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d24:
	/* 0xd24: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d27:
	/* 0xd27: xor    rcx,QWORD PTR [r12+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d2f:
	/* 0xd2f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d32:
	/* 0xd32: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d35:
	/* 0xd35: mov    rax,QWORD PTR [r12+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d3d:
	/* 0xd3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: je     d5f <trace_ret_kernel_write_tail+0xd5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d5f;
	}
x86_l_d42:
	/* 0xd42: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d45:
	/* 0xd45: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d4a:
	/* 0xd4a: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d4e:
	/* 0xd4e: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d51:
	/* 0xd51: xor    rcx,QWORD PTR [r12+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_d59:
	/* 0xd59: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d5c:
	/* 0xd5c: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d5f:
	/* 0xd5f: mov    rbx,QWORD PTR [r12+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_d67:
	/* 0xd67: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_d6a:
	/* 0xd6a: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d6f:
	/* 0xd6f: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d74:
	/* 0xd74: je     ecc <trace_ret_kernel_write_tail+0xecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ecc;
	}
x86_l_d7a:
	/* 0xd7a: mov    rax,QWORD PTR [r12+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_d82:
	/* 0xd82: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_d8a:
	/* 0xd8a: mov    rbp,QWORD PTR [r12+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_d92:
	/* 0xd92: mov    rax,QWORD PTR [r12+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_d9a:
	/* 0xd9a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d9f:
	/* 0xd9f: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_da7:
	/* 0xda7: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dac:
	/* 0xdac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_db3:
	/* 0xdb3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_db8:
	/* 0xdb8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dbd:
	/* 0xdbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbf:
	/* 0xdbf: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dc7:
	/* 0xdc7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dcc:
	/* 0xdcc: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_dd3:
	/* 0xdd3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_dd6:
	/* 0xdd6: je     df8 <trace_ret_kernel_write_tail+0xdf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df8;
	}
x86_l_dd8:
	/* 0xdd8: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ddd:
	/* 0xddd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_de2:
	/* 0xde2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_de5:
	/* 0xde5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de7:
	/* 0xde7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dea:
	/* 0xdea: je     df8 <trace_ret_kernel_write_tail+0xdf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df8;
	}
x86_l_dec:
	/* 0xdec: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_def:
	/* 0xdef: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df3:
	/* 0xdf3: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_df6:
	/* 0xdf6: jmp    dfb <trace_ret_kernel_write_tail+0xdfb> */
	goto x86_l_dfb;
x86_l_df8:
	/* 0xdf8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dfb:
	/* 0xdfb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e00:
	/* 0xe00: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e05:
	/* 0xe05: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e08:
	/* 0xe08: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e0b:
	/* 0xe0b: jb     e23 <trace_ret_kernel_write_tail+0xe23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e23;
	}
x86_l_e0d:
	/* 0xe0d: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e11:
	/* 0xe11: je     e18 <trace_ret_kernel_write_tail+0xe18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e18;
	}
x86_l_e13:
	/* 0xe13: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e16:
	/* 0xe16: jbe    e23 <trace_ret_kernel_write_tail+0xe23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e23;
	}
x86_l_e18:
	/* 0xe18: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_e20:
	/* 0xe20: or     r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_e23:
	/* 0xe23: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e28:
	/* 0xe28: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e2b:
	/* 0xe2b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e30:
	/* 0xe30: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e37:
	/* 0xe37: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e3a:
	/* 0xe3a: je     e79 <trace_ret_kernel_write_tail+0xe79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e79;
	}
x86_l_e3c:
	/* 0xe3c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e41:
	/* 0xe41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e46:
	/* 0xe46: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e49:
	/* 0xe49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4b:
	/* 0xe4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: je     ea5 <trace_ret_kernel_write_tail+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea5;
	}
x86_l_e50:
	/* 0xe50: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e53:
	/* 0xe53: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e57:
	/* 0xe57: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e5a:
	/* 0xe5a: jmp    ea7 <trace_ret_kernel_write_tail+0xea7> */
	goto x86_l_ea7;
x86_l_e5c:
	/* 0xe5c: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e63:
	/* 0xe63: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e6b:
	/* 0xe6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6e:
	/* 0xe6e: jne    ceb <trace_ret_kernel_write_tail+0xceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ceb;
	}
x86_l_e74:
	/* 0xe74: jmp    d0c <trace_ret_kernel_write_tail+0xd0c> */
	goto x86_l_d0c;
x86_l_e79:
	/* 0xe79: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7b:
	/* 0xe7b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e7e:
	/* 0xe7e: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e83:
	/* 0xe83: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: jb     eb9 <trace_ret_kernel_write_tail+0xeb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_eb9;
	}
x86_l_e88:
	/* 0xe88: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e8c:
	/* 0xe8c: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e91:
	/* 0xe91: je     e98 <trace_ret_kernel_write_tail+0xe98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e98;
	}
x86_l_e93:
	/* 0xe93: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e96:
	/* 0xe96: jbe    ebe <trace_ret_kernel_write_tail+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ebe;
	}
x86_l_e98:
	/* 0xe98: and    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_ea0:
	/* 0xea0: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_ea3:
	/* 0xea3: jmp    ebe <trace_ret_kernel_write_tail+0xebe> */
	goto x86_l_ebe;
x86_l_ea5:
	/* 0xea5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea7:
	/* 0xea7: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_eac:
	/* 0xeac: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eaf:
	/* 0xeaf: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_eb4:
	/* 0xeb4: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: jae    e88 <trace_ret_kernel_write_tail+0xe88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e88;
	}
x86_l_eb9:
	/* 0xeb9: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ebe:
	/* 0xebe: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec1:
	/* 0xec1: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec4:
	/* 0xec4: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_ec7:
	/* 0xec7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecc:
	/* 0xecc: cmp    QWORD PTR [r12+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_ed5:
	/* 0xed5: je     f91 <trace_ret_kernel_write_tail+0xf91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3985ULL;
	}
x86_l_edb:
	/* 0xedb: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_ee0:
	/* 0xee0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee2:
	/* 0xee2: mov    DWORD PTR [r12+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee7:
	/* 0xee7: mov    rbx,QWORD PTR [r12+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_eef:
	/* 0xeef: mov    r14,QWORD PTR [r12+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_ef7:
	/* 0xef7: mov    r13,QWORD PTR [r12+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_eff:
	/* 0xeff: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_f02:
	/* 0xf02: mov    r12,QWORD PTR [r12+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f0a:
	/* 0xf0a: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_f12:
	/* 0xf12: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f17:
	/* 0xf17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f1e:
	/* 0xf1e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f23:
	/* 0xf23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f28:
	/* 0xf28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2a:
	/* 0xf2a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f2d:
	/* 0xf2d: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f30:
	/* 0xf30: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 3893ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3893ULL: goto x86_l_f35;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3929ULL: goto x86_l_f59;
	case 3932ULL: goto x86_l_f5c;
	case 3934ULL: goto x86_l_f5e;
	case 3936ULL: goto x86_l_f60;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3963ULL: goto x86_l_f7b;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3985ULL: goto x86_l_f91;
	case 3994ULL: goto x86_l_f9a;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4098ULL: goto x86_l_1002;
	case 4102ULL: goto x86_l_1006;
	case 4107ULL: goto x86_l_100b;
	case 4115ULL: goto x86_l_1013;
	case 4123ULL: goto x86_l_101b;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4171ULL: goto x86_l_104b;
	case 4174ULL: goto x86_l_104e;
	case 4176ULL: goto x86_l_1050;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4187ULL: goto x86_l_105b;
	case 4190ULL: goto x86_l_105e;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4199ULL: goto x86_l_1067;
	case 4202ULL: goto x86_l_106a;
	case 4204ULL: goto x86_l_106c;
	case 4206ULL: goto x86_l_106e;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4232ULL: goto x86_l_1088;
	case 4238ULL: goto x86_l_108e;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4300ULL: goto x86_l_10cc;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4310ULL: goto x86_l_10d6;
	case 4314ULL: goto x86_l_10da;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4371ULL: goto x86_l_1113;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4388ULL: goto x86_l_1124;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4444ULL: goto x86_l_115c;
	case 4447ULL: goto x86_l_115f;
	case 4449ULL: goto x86_l_1161;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4468ULL: goto x86_l_1174;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4477ULL: goto x86_l_117d;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4491ULL: goto x86_l_118b;
	case 4496ULL: goto x86_l_1190;
	case 4505ULL: goto x86_l_1199;
	case 4511ULL: goto x86_l_119f;
	case 4516ULL: goto x86_l_11a4;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4546ULL: goto x86_l_11c2;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4639ULL: goto x86_l_121f;
	case 4647ULL: goto x86_l_1227;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4719ULL: goto x86_l_126f;
	case 4722ULL: goto x86_l_1272;
	case 4724ULL: goto x86_l_1274;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4752ULL: goto x86_l_1290;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4791ULL: goto x86_l_12b7;
	case 4799ULL: goto x86_l_12bf;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4829ULL: goto x86_l_12dd;
	case 4832ULL: goto x86_l_12e0;
	case 4834ULL: goto x86_l_12e2;
	case 4841ULL: goto x86_l_12e9;
	case 4844ULL: goto x86_l_12ec;
	case 4846ULL: goto x86_l_12ee;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4867ULL: goto x86_l_1303;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4876ULL: goto x86_l_130c;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4925ULL: goto x86_l_133d;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4987ULL: goto x86_l_137b;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 4999ULL: goto x86_l_1387;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5006ULL: goto x86_l_138e;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5044ULL: goto x86_l_13b4;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5097ULL: goto x86_l_13e9;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5120ULL: goto x86_l_1400;
	case 5123ULL: goto x86_l_1403;
	case 5125ULL: goto x86_l_1405;
	case 5127ULL: goto x86_l_1407;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5144ULL: goto x86_l_1418;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5161ULL: goto x86_l_1429;
	case 5169ULL: goto x86_l_1431;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5202ULL: goto x86_l_1452;
	case 5204ULL: goto x86_l_1454;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5279ULL: goto x86_l_149f;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5287ULL: goto x86_l_14a7;
	case 5290ULL: goto x86_l_14aa;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5306ULL: goto x86_l_14ba;
	case 5309ULL: goto x86_l_14bd;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5339ULL: goto x86_l_14db;
	case 5347ULL: goto x86_l_14e3;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5371ULL: goto x86_l_14fb;
	case 5375ULL: goto x86_l_14ff;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5416ULL: goto x86_l_1528;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5424ULL: goto x86_l_1530;
	case 5427ULL: goto x86_l_1533;
	case 5435ULL: goto x86_l_153b;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5447ULL: goto x86_l_1547;
	case 5455ULL: goto x86_l_154f;
	case 5463ULL: goto x86_l_1557;
	case 5472ULL: goto x86_l_1560;
	case 5481ULL: goto x86_l_1569;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5526ULL: goto x86_l_1596;
	case 5528ULL: goto x86_l_1598;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f35:
	/* 0xf35: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f3c:
	/* 0xf3c: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: je     f5e <trace_ret_kernel_write_tail+0xf5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f5e;
	}
x86_l_f41:
	/* 0xf41: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f46:
	/* 0xf46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f50:
	/* 0xf50: je     f5e <trace_ret_kernel_write_tail+0xf5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f5e;
	}
x86_l_f52:
	/* 0xf52: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f55:
	/* 0xf55: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f59:
	/* 0xf59: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f5c:
	/* 0xf5c: jmp    f60 <trace_ret_kernel_write_tail+0xf60> */
	goto x86_l_f60;
x86_l_f5e:
	/* 0xf5e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f60:
	/* 0xf60: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f63:
	/* 0xf63: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f68:
	/* 0xf68: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f6b:
	/* 0xf6b: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f6e:
	/* 0xf6e: jb     f81 <trace_ret_kernel_write_tail+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f81;
	}
x86_l_f70:
	/* 0xf70: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f74:
	/* 0xf74: je     f7b <trace_ret_kernel_write_tail+0xf7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7b;
	}
x86_l_f76:
	/* 0xf76: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_f79:
	/* 0xf79: jbe    f81 <trace_ret_kernel_write_tail+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f81;
	}
x86_l_f7b:
	/* 0xf7b: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_f7e:
	/* 0xf7e: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_f81:
	/* 0xf81: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f84:
	/* 0xf84: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_f87:
	/* 0xf87: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f8c:
	/* 0xf8c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f91:
	/* 0xf91: cmp    QWORD PTR [r12+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_f9a:
	/* 0xf9a: je     107f <trace_ret_kernel_write_tail+0x107f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107f;
	}
x86_l_fa0:
	/* 0xfa0: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_fa5:
	/* 0xfa5: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_fad:
	/* 0xfad: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fb2:
	/* 0xfb2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fb7:
	/* 0xfb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fbc:
	/* 0xfbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc1:
	/* 0xfc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc3:
	/* 0xfc3: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fc8:
	/* 0xfc8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fcc:
	/* 0xfcc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fd1:
	/* 0xfd1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fd6:
	/* 0xfd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fdb:
	/* 0xfdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fe0:
	/* 0xfe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe2:
	/* 0xfe2: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe7:
	/* 0xfe7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fec:
	/* 0xfec: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ff1:
	/* 0xff1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff6:
	/* 0xff6: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ffb:
	/* 0xffb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1000:
	/* 0x1000: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1002:
	/* 0x1002: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1006:
	/* 0x1006: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_100b:
	/* 0x100b: mov    rbx,QWORD PTR [r12+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1013:
	/* 0x1013: mov    r14,QWORD PTR [r12+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_101b:
	/* 0x101b: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1023:
	/* 0x1023: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1028:
	/* 0x1028: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_102f:
	/* 0x102f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1034:
	/* 0x1034: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1039:
	/* 0x1039: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_103c:
	/* 0x103c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103e:
	/* 0x103e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1041:
	/* 0x1041: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_104b:
	/* 0x104b: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_104e:
	/* 0x104e: je     106c <trace_ret_kernel_write_tail+0x106c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106c;
	}
x86_l_1050:
	/* 0x1050: lea    rsi,[rax+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1054:
	/* 0x1054: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1059:
	/* 0x1059: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105b:
	/* 0x105b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105e:
	/* 0x105e: je     106c <trace_ret_kernel_write_tail+0x106c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106c;
	}
x86_l_1060:
	/* 0x1060: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1063:
	/* 0x1063: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1067:
	/* 0x1067: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_106a:
	/* 0x106a: jmp    106e <trace_ret_kernel_write_tail+0x106e> */
	goto x86_l_106e;
x86_l_106c:
	/* 0x106c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106e:
	/* 0x106e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1071:
	/* 0x1071: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1074:
	/* 0x1074: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1077:
	/* 0x1077: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_107a:
	/* 0x107a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107f:
	/* 0x107f: cmp    QWORD PTR [r12+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1088:
	/* 0x1088: je     1190 <trace_ret_kernel_write_tail+0x1190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1190;
	}
x86_l_108e:
	/* 0x108e: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1096:
	/* 0x1096: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_109a:
	/* 0x109a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_109f:
	/* 0x109f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10b5:
	/* 0x10b5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10ba:
	/* 0x10ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10bf:
	/* 0x10bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10c4:
	/* 0x10c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10c9:
	/* 0x10c9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10cc:
	/* 0x10cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ce:
	/* 0x10ce: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10d2:
	/* 0x10d2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_10d6:
	/* 0x10d6: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_10da:
	/* 0x10da: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10de:
	/* 0x10de: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10e3:
	/* 0x10e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10e8:
	/* 0x10e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ed:
	/* 0x10ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10f2:
	/* 0x10f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f4:
	/* 0x10f4: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10f9:
	/* 0x10f9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_10fd:
	/* 0x10fd: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1102:
	/* 0x1102: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1107:
	/* 0x1107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_110c:
	/* 0x110c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1111:
	/* 0x1111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1113:
	/* 0x1113: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1117:
	/* 0x1117: mov    DWORD PTR [r12+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_111c:
	/* 0x111c: mov    rbx,QWORD PTR [r12+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1124:
	/* 0x1124: mov    r14,QWORD PTR [r12+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_112c:
	/* 0x112c: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1134:
	/* 0x1134: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1139:
	/* 0x1139: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1140:
	/* 0x1140: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1145:
	/* 0x1145: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114a:
	/* 0x114a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_114d:
	/* 0x114d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114f:
	/* 0x114f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1152:
	/* 0x1152: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1155:
	/* 0x1155: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_115c:
	/* 0x115c: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_115f:
	/* 0x115f: je     117d <trace_ret_kernel_write_tail+0x117d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117d;
	}
x86_l_1161:
	/* 0x1161: lea    rsi,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1165:
	/* 0x1165: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116a:
	/* 0x116a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116c:
	/* 0x116c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: je     117d <trace_ret_kernel_write_tail+0x117d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117d;
	}
x86_l_1171:
	/* 0x1171: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1174:
	/* 0x1174: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1178:
	/* 0x1178: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_117b:
	/* 0x117b: jmp    117f <trace_ret_kernel_write_tail+0x117f> */
	goto x86_l_117f;
x86_l_117d:
	/* 0x117d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_117f:
	/* 0x117f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1182:
	/* 0x1182: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1185:
	/* 0x1185: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1188:
	/* 0x1188: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_118b:
	/* 0x118b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1190:
	/* 0x1190: cmp    QWORD PTR [r12+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1199:
	/* 0x1199: je     1287 <trace_ret_kernel_write_tail+0x1287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1287;
	}
x86_l_119f:
	/* 0x119f: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11a4:
	/* 0x11a4: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_11ac:
	/* 0x11ac: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11b1:
	/* 0x11b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11b6:
	/* 0x11b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11bb:
	/* 0x11bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c0:
	/* 0x11c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c2:
	/* 0x11c2: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11c7:
	/* 0x11c7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11cc:
	/* 0x11cc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11d1:
	/* 0x11d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11d6:
	/* 0x11d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11db:
	/* 0x11db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11dd:
	/* 0x11dd: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11e2:
	/* 0x11e2: lea    rbx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11e7:
	/* 0x11e7: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_11ec:
	/* 0x11ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11f1:
	/* 0x11f1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11f4:
	/* 0x11f4: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_11f9:
	/* 0x11f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fb:
	/* 0x11fb: lea    r13,[r12+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1200:
	/* 0x1200: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1205:
	/* 0x1205: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_120a:
	/* 0x120a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_120d:
	/* 0x120d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1212:
	/* 0x1212: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1215:
	/* 0x1215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1217:
	/* 0x1217: mov    rbx,QWORD PTR [r12+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_121f:
	/* 0x121f: mov    r14,QWORD PTR [r12+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1227:
	/* 0x1227: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_122f:
	/* 0x122f: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1234:
	/* 0x1234: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_123b:
	/* 0x123b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1240:
	/* 0x1240: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1245:
	/* 0x1245: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1248:
	/* 0x1248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124a:
	/* 0x124a: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1251:
	/* 0x1251: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: je     1274 <trace_ret_kernel_write_tail+0x1274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1274;
	}
x86_l_1256:
	/* 0x1256: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1259:
	/* 0x1259: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_125e:
	/* 0x125e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1261:
	/* 0x1261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1263:
	/* 0x1263: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1266:
	/* 0x1266: je     1274 <trace_ret_kernel_write_tail+0x1274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1274;
	}
x86_l_1268:
	/* 0x1268: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126b:
	/* 0x126b: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_126f:
	/* 0x126f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1272:
	/* 0x1272: jmp    1276 <trace_ret_kernel_write_tail+0x1276> */
	goto x86_l_1276;
x86_l_1274:
	/* 0x1274: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1276:
	/* 0x1276: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1279:
	/* 0x1279: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_127c:
	/* 0x127c: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_127f:
	/* 0x127f: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1282:
	/* 0x1282: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1287:
	/* 0x1287: cmp    QWORD PTR [r12+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1290:
	/* 0x1290: je     131f <trace_ret_kernel_write_tail+0x131f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131f;
	}
x86_l_1296:
	/* 0x1296: lea    r13,[r12+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_129b:
	/* 0x129b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12a0:
	/* 0x12a0: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12a5:
	/* 0x12a5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_12a8:
	/* 0x12a8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12ad:
	/* 0x12ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12af:
	/* 0x12af: mov    rbx,QWORD PTR [r12+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12b7:
	/* 0x12b7: mov    r14,QWORD PTR [r12+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12bf:
	/* 0x12bf: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_12c7:
	/* 0x12c7: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12cc:
	/* 0x12cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12d3:
	/* 0x12d3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12d8:
	/* 0x12d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12dd:
	/* 0x12dd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12e0:
	/* 0x12e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e2:
	/* 0x12e2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12e9:
	/* 0x12e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ec:
	/* 0x12ec: je     130c <trace_ret_kernel_write_tail+0x130c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_130c;
	}
x86_l_12ee:
	/* 0x12ee: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12f1:
	/* 0x12f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f6:
	/* 0x12f6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_12f9:
	/* 0x12f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fb:
	/* 0x12fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12fe:
	/* 0x12fe: je     130c <trace_ret_kernel_write_tail+0x130c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_130c;
	}
x86_l_1300:
	/* 0x1300: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1303:
	/* 0x1303: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1307:
	/* 0x1307: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_130a:
	/* 0x130a: jmp    130e <trace_ret_kernel_write_tail+0x130e> */
	goto x86_l_130e;
x86_l_130c:
	/* 0x130c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130e:
	/* 0x130e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1311:
	/* 0x1311: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1314:
	/* 0x1314: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1317:
	/* 0x1317: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_131a:
	/* 0x131a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_131f:
	/* 0x131f: mov    rbx,QWORD PTR [r12+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1327:
	/* 0x1327: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_132a:
	/* 0x132a: je     139f <trace_ret_kernel_write_tail+0x139f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139f;
	}
x86_l_132c:
	/* 0x132c: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1331:
	/* 0x1331: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1335:
	/* 0x1335: mov    r14,QWORD PTR [r12+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_133d:
	/* 0x133d: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1345:
	/* 0x1345: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_134a:
	/* 0x134a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1351:
	/* 0x1351: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1356:
	/* 0x1356: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_135b:
	/* 0x135b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_135e:
	/* 0x135e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1360:
	/* 0x1360: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1367:
	/* 0x1367: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_136a:
	/* 0x136a: je     138c <trace_ret_kernel_write_tail+0x138c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_138c;
	}
x86_l_136c:
	/* 0x136c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_136f:
	/* 0x136f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1374:
	/* 0x1374: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1379:
	/* 0x1379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137b:
	/* 0x137b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_137e:
	/* 0x137e: je     138c <trace_ret_kernel_write_tail+0x138c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_138c;
	}
x86_l_1380:
	/* 0x1380: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1383:
	/* 0x1383: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1387:
	/* 0x1387: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_138a:
	/* 0x138a: jmp    138e <trace_ret_kernel_write_tail+0x138e> */
	goto x86_l_138e;
x86_l_138c:
	/* 0x138c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138e:
	/* 0x138e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1391:
	/* 0x1391: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1394:
	/* 0x1394: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1397:
	/* 0x1397: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_139a:
	/* 0x139a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139f:
	/* 0x139f: mov    rbx,QWORD PTR [r12+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13a7:
	/* 0x13a7: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13aa:
	/* 0x13aa: je     1418 <trace_ret_kernel_write_tail+0x1418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1418;
	}
x86_l_13ac:
	/* 0x13ac: mov    r14,QWORD PTR [r12+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13b4:
	/* 0x13b4: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_13bc:
	/* 0x13bc: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13c1:
	/* 0x13c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13c8:
	/* 0x13c8: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13cd:
	/* 0x13cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d2:
	/* 0x13d2: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d5:
	/* 0x13d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d7:
	/* 0x13d7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13da:
	/* 0x13da: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_13dd:
	/* 0x13dd: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13e4:
	/* 0x13e4: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_13e7:
	/* 0x13e7: je     1405 <trace_ret_kernel_write_tail+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_13e9:
	/* 0x13e9: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13ed:
	/* 0x13ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f2:
	/* 0x13f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f4:
	/* 0x13f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f7:
	/* 0x13f7: je     1405 <trace_ret_kernel_write_tail+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_13f9:
	/* 0x13f9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13fc:
	/* 0x13fc: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1400:
	/* 0x1400: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1403:
	/* 0x1403: jmp    1407 <trace_ret_kernel_write_tail+0x1407> */
	goto x86_l_1407;
x86_l_1405:
	/* 0x1405: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1407:
	/* 0x1407: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_140a:
	/* 0x140a: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_140d:
	/* 0x140d: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1410:
	/* 0x1410: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1413:
	/* 0x1413: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1418:
	/* 0x1418: mov    rbx,QWORD PTR [r12+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1420:
	/* 0x1420: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1423:
	/* 0x1423: je     14b2 <trace_ret_kernel_write_tail+0x14b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b2;
	}
x86_l_1429:
	/* 0x1429: mov    r14,QWORD PTR [r12+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1431:
	/* 0x1431: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1439:
	/* 0x1439: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_143e:
	/* 0x143e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1445:
	/* 0x1445: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_144a:
	/* 0x144a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144f:
	/* 0x144f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1452:
	/* 0x1452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1454:
	/* 0x1454: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_145b:
	/* 0x145b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145e:
	/* 0x145e: je     149f <trace_ret_kernel_write_tail+0x149f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_149f;
	}
x86_l_1460:
	/* 0x1460: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1463:
	/* 0x1463: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1468:
	/* 0x1468: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_146c:
	/* 0x146c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1471:
	/* 0x1471: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1474:
	/* 0x1474: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1476:
	/* 0x1476: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1479:
	/* 0x1479: jne    1493 <trace_ret_kernel_write_tail+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1493;
	}
x86_l_147b:
	/* 0x147b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1480:
	/* 0x1480: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1484:
	/* 0x1484: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1489:
	/* 0x1489: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_148c:
	/* 0x148c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148e:
	/* 0x148e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1491:
	/* 0x1491: je     149f <trace_ret_kernel_write_tail+0x149f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_149f;
	}
x86_l_1493:
	/* 0x1493: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1496:
	/* 0x1496: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_149a:
	/* 0x149a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_149d:
	/* 0x149d: jmp    14a1 <trace_ret_kernel_write_tail+0x14a1> */
	goto x86_l_14a1;
x86_l_149f:
	/* 0x149f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a1:
	/* 0x14a1: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14a4:
	/* 0x14a4: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_14a7:
	/* 0x14a7: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14aa:
	/* 0x14aa: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_14ad:
	/* 0x14ad: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b2:
	/* 0x14b2: mov    rax,QWORD PTR [r12+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14ba:
	/* 0x14ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14bd:
	/* 0x14bd: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14c5:
	/* 0x14c5: je     14d3 <trace_ret_kernel_write_tail+0x14d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d3;
	}
x86_l_14c7:
	/* 0x14c7: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14cc:
	/* 0x14cc: and    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14d0:
	/* 0x14d0: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d3:
	/* 0x14d3: and    r15,QWORD PTR [r12+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14db:
	/* 0x14db: and    QWORD PTR [r12+0x80],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R12, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_14e3:
	/* 0x14e3: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_14e9:
	/* 0x14e9: test   BYTE PTR [rcx+0x4],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_14ed:
	/* 0x14ed: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_14f3:
	/* 0x14f3: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14fb:
	/* 0x14fb: mov    rbx,QWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14ff:
	/* 0x14ff: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1507:
	/* 0x1507: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_150c:
	/* 0x150c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1511:
	/* 0x1511: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1519:
	/* 0x1519: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151e:
	/* 0x151e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1520:
	/* 0x1520: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1528:
	/* 0x1528: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_152b:
	/* 0x152b: je     1545 <trace_ret_kernel_write_tail+0x1545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1545;
	}
x86_l_152d:
	/* 0x152d: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1530:
	/* 0x1530: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1533:
	/* 0x1533: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_153b:
	/* 0x153b: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1543:
	/* 0x1543: jmp    154f <trace_ret_kernel_write_tail+0x154f> */
	goto x86_l_154f;
x86_l_1545:
	/* 0x1545: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1547:
	/* 0x1547: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_154f:
	/* 0x154f: mov    QWORD PTR [rsp+0xa0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1557:
	/* 0x1557: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1560:
	/* 0x1560: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1569:
	/* 0x1569: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1572:
	/* 0x1572: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1575:
	/* 0x1575: je     1702 <trace_ret_kernel_write_tail+0x1702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5890ULL;
	}
x86_l_157b:
	/* 0x157b: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_157f:
	/* 0x157f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1584:
	/* 0x1584: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1589:
	/* 0x1589: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_158e:
	/* 0x158e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1593:
	/* 0x1593: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1596:
	/* 0x1596: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1598:
	/* 0x1598: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 5533ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5533ULL: goto x86_l_159d;
	case 5542ULL: goto x86_l_15a6;
	case 5551ULL: goto x86_l_15af;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5660ULL: goto x86_l_161c;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	case 5811ULL: goto x86_l_16b3;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5910ULL: goto x86_l_1716;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5921ULL: goto x86_l_1721;
	case 5924ULL: goto x86_l_1724;
	case 5932ULL: goto x86_l_172c;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5973ULL: goto x86_l_1755;
	case 5977ULL: goto x86_l_1759;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5990ULL: goto x86_l_1766;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6014ULL: goto x86_l_177e;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6038ULL: goto x86_l_1796;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6086ULL: goto x86_l_17c6;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6158ULL: goto x86_l_180e;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6175ULL: goto x86_l_181f;
	case 6178ULL: goto x86_l_1822;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6195ULL: goto x86_l_1833;
	case 6201ULL: goto x86_l_1839;
	case 6206ULL: goto x86_l_183e;
	case 6214ULL: goto x86_l_1846;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6233ULL: goto x86_l_1859;
	case 6236ULL: goto x86_l_185c;
	case 6242ULL: goto x86_l_1862;
	case 6245ULL: goto x86_l_1865;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6359ULL: goto x86_l_18d7;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6378ULL: goto x86_l_18ea;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6389ULL: goto x86_l_18f5;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6475ULL: goto x86_l_194b;
	case 6481ULL: goto x86_l_1951;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6518ULL: goto x86_l_1976;
	case 6524ULL: goto x86_l_197c;
	case 6526ULL: goto x86_l_197e;
	case 6528ULL: goto x86_l_1980;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6567ULL: goto x86_l_19a7;
	case 6573ULL: goto x86_l_19ad;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6656ULL: goto x86_l_1a00;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6679ULL: goto x86_l_1a17;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6718ULL: goto x86_l_1a3e;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	case 6752ULL: goto x86_l_1a60;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6794ULL: goto x86_l_1a8a;
	case 6799ULL: goto x86_l_1a8f;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6875ULL: goto x86_l_1adb;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6887ULL: goto x86_l_1ae7;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6936ULL: goto x86_l_1b18;
	case 6940ULL: goto x86_l_1b1c;
	case 6946ULL: goto x86_l_1b22;
	case 6952ULL: goto x86_l_1b28;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6991ULL: goto x86_l_1b4f;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7058ULL: goto x86_l_1b92;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7078ULL: goto x86_l_1ba6;
	case 7084ULL: goto x86_l_1bac;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7136ULL: goto x86_l_1be0;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7159ULL: goto x86_l_1bf7;
	case 7164ULL: goto x86_l_1bfc;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7201ULL: goto x86_l_1c21;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7249ULL: goto x86_l_1c51;
	default: return 0xffffffffffffffffULL;
	}
x86_l_159d:
	/* 0x159d: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_15a6:
	/* 0x15a6: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15af:
	/* 0x15af: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b3:
	/* 0x15b3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b8:
	/* 0x15b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15bd:
	/* 0x15bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15c2:
	/* 0x15c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c7:
	/* 0x15c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c9:
	/* 0x15c9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ce:
	/* 0x15ce: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15d3:
	/* 0x15d3: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_15d7:
	/* 0x15d7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15dc:
	/* 0x15dc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15e1:
	/* 0x15e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15e6:
	/* 0x15e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15eb:
	/* 0x15eb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f0:
	/* 0x15f0: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f4:
	/* 0x15f4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15f9:
	/* 0x15f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15fe:
	/* 0x15fe: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1603:
	/* 0x1603: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1608:
	/* 0x1608: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_160d:
	/* 0x160d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1612:
	/* 0x1612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1614:
	/* 0x1614: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1619:
	/* 0x1619: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_161c:
	/* 0x161c: js     1647 <trace_ret_kernel_write_tail+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1647;
	}
x86_l_161e:
	/* 0x161e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1623:
	/* 0x1623: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1628:
	/* 0x1628: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_162d:
	/* 0x162d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1632:
	/* 0x1632: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1637:
	/* 0x1637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1639:
	/* 0x1639: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1640:
	/* 0x1640: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1645:
	/* 0x1645: jmp    1649 <trace_ret_kernel_write_tail+0x1649> */
	goto x86_l_1649;
x86_l_1647:
	/* 0x1647: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1649:
	/* 0x1649: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_164e:
	/* 0x164e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1653:
	/* 0x1653: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1658:
	/* 0x1658: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_165d:
	/* 0x165d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1662:
	/* 0x1662: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1665:
	/* 0x1665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1667:
	/* 0x1667: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166c:
	/* 0x166c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1670:
	/* 0x1670: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1675:
	/* 0x1675: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_167a:
	/* 0x167a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_167f:
	/* 0x167f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1684:
	/* 0x1684: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1688:
	/* 0x1688: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_168d:
	/* 0x168d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168f:
	/* 0x168f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1694:
	/* 0x1694: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1699:
	/* 0x1699: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_169e:
	/* 0x169e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16a3:
	/* 0x16a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a8:
	/* 0x16a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16ad:
	/* 0x16ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16af:
	/* 0x16af: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b3:
	/* 0x16b3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16b7:
	/* 0x16b7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16bc:
	/* 0x16bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16c1:
	/* 0x16c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16c6:
	/* 0x16c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16cb:
	/* 0x16cb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_16ce:
	/* 0x16ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d0:
	/* 0x16d0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d5:
	/* 0x16d5: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16d9:
	/* 0x16d9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16de:
	/* 0x16de: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16e3:
	/* 0x16e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16e8:
	/* 0x16e8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ed:
	/* 0x16ed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16f1:
	/* 0x16f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f6:
	/* 0x16f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f8:
	/* 0x16f8: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16fd:
	/* 0x16fd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1702:
	/* 0x1702: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1709:
	/* 0x1709: lea    rbx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_170e:
	/* 0x170e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1713:
	/* 0x1713: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1716:
	/* 0x1716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1718:
	/* 0x1718: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: je     183e <trace_ret_kernel_write_tail+0x183e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183e;
	}
x86_l_1721:
	/* 0x1721: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1724:
	/* 0x1724: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_172c:
	/* 0x172c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1733:
	/* 0x1733: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1738:
	/* 0x1738: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173d:
	/* 0x173d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173f:
	/* 0x173f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1742:
	/* 0x1742: je     38d4 <trace_ret_kernel_write_tail+0x38d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14548ULL;
	}
x86_l_1748:
	/* 0x1748: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_174b:
	/* 0x174b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_174d:
	/* 0x174d: je     19bd <trace_ret_kernel_write_tail+0x19bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19bd;
	}
x86_l_1753:
	/* 0x1753: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1755:
	/* 0x1755: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1759:
	/* 0x1759: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_175f:
	/* 0x175f: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1764:
	/* 0x1764: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1766:
	/* 0x1766: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_176c:
	/* 0x176c: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1771:
	/* 0x1771: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_1777:
	/* 0x1777: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_177c:
	/* 0x177c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_177e:
	/* 0x177e: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1784:
	/* 0x1784: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1789:
	/* 0x1789: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_178f:
	/* 0x178f: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1794:
	/* 0x1794: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1796:
	/* 0x1796: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_179c:
	/* 0x179c: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_17a1:
	/* 0x17a1: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_17a7:
	/* 0x17a7: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_17ac:
	/* 0x17ac: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17ae:
	/* 0x17ae: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_17b4:
	/* 0x17b4: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_17b9:
	/* 0x17b9: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_17bf:
	/* 0x17bf: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_17c4:
	/* 0x17c4: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17c6:
	/* 0x17c6: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_17cc:
	/* 0x17cc: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_17d1:
	/* 0x17d1: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_17d7:
	/* 0x17d7: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_17dc:
	/* 0x17dc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17de:
	/* 0x17de: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_17e4:
	/* 0x17e4: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_17e9:
	/* 0x17e9: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_17ef:
	/* 0x17ef: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_17f4:
	/* 0x17f4: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17f6:
	/* 0x17f6: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_17fc:
	/* 0x17fc: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1801:
	/* 0x1801: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_1807:
	/* 0x1807: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_180c:
	/* 0x180c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_180e:
	/* 0x180e: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1814:
	/* 0x1814: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1819:
	/* 0x1819: jne    1bac <trace_ret_kernel_write_tail+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bac;
	}
x86_l_181f:
	/* 0x181f: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1822:
	/* 0x1822: je     1ba2 <trace_ret_kernel_write_tail+0x1ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ba2;
	}
x86_l_1828:
	/* 0x1828: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_182d:
	/* 0x182d: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1831:
	/* 0x1831: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1833:
	/* 0x1833: jne    1755 <trace_ret_kernel_write_tail+0x1755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1755;
	}
x86_l_1839:
	/* 0x1839: jmp    214b <trace_ret_kernel_write_tail+0x214b> */
	return 8523ULL;
x86_l_183e:
	/* 0x183e: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1846:
	/* 0x1846: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_184d:
	/* 0x184d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1852:
	/* 0x1852: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1857:
	/* 0x1857: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1859:
	/* 0x1859: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_185c:
	/* 0x185c: je     2153 <trace_ret_kernel_write_tail+0x2153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8531ULL;
	}
x86_l_1862:
	/* 0x1862: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1865:
	/* 0x1865: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1869:
	/* 0x1869: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_186e:
	/* 0x186e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1873:
	/* 0x1873: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1878:
	/* 0x1878: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_187d:
	/* 0x187d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187f:
	/* 0x187f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1884:
	/* 0x1884: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1889:
	/* 0x1889: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188e:
	/* 0x188e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1893:
	/* 0x1893: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1898:
	/* 0x1898: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_189d:
	/* 0x189d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a2:
	/* 0x18a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a4:
	/* 0x18a4: test   BYTE PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215136ULL);
x86_l_18a9:
	/* 0x18a9: jne    19c5 <trace_ret_kernel_write_tail+0x19c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19c5;
	}
x86_l_18af:
	/* 0x18af: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18b4:
	/* 0x18b4: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b8:
	/* 0x18b8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18bd:
	/* 0x18bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18c2:
	/* 0x18c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18c7:
	/* 0x18c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18cc:
	/* 0x18cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ce:
	/* 0x18ce: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18d3:
	/* 0x18d3: lea    rcx,[r14-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_18d7:
	/* 0x18d7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18db:
	/* 0x18db: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18e0:
	/* 0x18e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18e5:
	/* 0x18e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18ea:
	/* 0x18ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ee:
	/* 0x18ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18f3:
	/* 0x18f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f5:
	/* 0x18f5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18fa:
	/* 0x18fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18ff:
	/* 0x18ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1904:
	/* 0x1904: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1909:
	/* 0x1909: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_190c:
	/* 0x190c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_190f:
	/* 0x190f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1911:
	/* 0x1911: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1916:
	/* 0x1916: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191b:
	/* 0x191b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_191f:
	/* 0x191f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1924:
	/* 0x1924: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1929:
	/* 0x1929: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_192e:
	/* 0x192e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1933:
	/* 0x1933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1935:
	/* 0x1935: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193a:
	/* 0x193a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_193d:
	/* 0x193d: je     19e8 <trace_ret_kernel_write_tail+0x19e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e8;
	}
x86_l_1943:
	/* 0x1943: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1948:
	/* 0x1948: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_194b:
	/* 0x194b: je     19e8 <trace_ret_kernel_write_tail+0x19e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e8;
	}
x86_l_1951:
	/* 0x1951: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1955:
	/* 0x1955: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_195a:
	/* 0x195a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_195f:
	/* 0x195f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1964:
	/* 0x1964: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1969:
	/* 0x1969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196b:
	/* 0x196b: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_196f:
	/* 0x196f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1974:
	/* 0x1974: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1976:
	/* 0x1976: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_197c:
	/* 0x197c: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_197e:
	/* 0x197e: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1980:
	/* 0x1980: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1986:
	/* 0x1986: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_198b:
	/* 0x198b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1990:
	/* 0x1990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1992:
	/* 0x1992: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1995:
	/* 0x1995: jl     1b55 <trace_ret_kernel_write_tail+0x1b55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b55;
	}
x86_l_199b:
	/* 0x199b: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19a0:
	/* 0x19a0: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_19a7:
	/* 0x19a7: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_19ad:
	/* 0x19ad: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19b0:
	/* 0x19b0: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b5:
	/* 0x19b5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19b8:
	/* 0x19b8: jmp    1a6a <trace_ret_kernel_write_tail+0x1a6a> */
	goto x86_l_1a6a;
x86_l_19bd:
	/* 0x19bd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c0:
	/* 0x19c0: jmp    2138 <trace_ret_kernel_write_tail+0x2138> */
	return 8504ULL;
x86_l_19c5:
	/* 0x19c5: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_19cc:
	/* 0x19cc: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_19d1:
	/* 0x19d1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19d6:
	/* 0x19d6: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_19d9:
	/* 0x19d9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19de:
	/* 0x19de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e0:
	/* 0x19e0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e3:
	/* 0x19e3: jmp    1e0a <trace_ret_kernel_write_tail+0x1e0a> */
	return 7690ULL;
x86_l_19e8:
	/* 0x19e8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_19eb:
	/* 0x19eb: jne    1b55 <trace_ret_kernel_write_tail+0x1b55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b55;
	}
x86_l_19f1:
	/* 0x19f1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f5:
	/* 0x19f5: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_19fa:
	/* 0x19fa: je     1b55 <trace_ret_kernel_write_tail+0x1b55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b55;
	}
x86_l_1a00:
	/* 0x1a00: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a04:
	/* 0x1a04: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a09:
	/* 0x1a09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a13:
	/* 0x1a13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a17:
	/* 0x1a17: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a20:
	/* 0x1a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a22:
	/* 0x1a22: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a29:
	/* 0x1a29: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a33:
	/* 0x1a33: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a37:
	/* 0x1a37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a3c:
	/* 0x1a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3e:
	/* 0x1a3e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a42:
	/* 0x1a42: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a47:
	/* 0x1a47: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a51:
	/* 0x1a51: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a55:
	/* 0x1a55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a5a:
	/* 0x1a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5c:
	/* 0x1a5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a60:
	/* 0x1a60: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a64:
	/* 0x1a64: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_1a6a:
	/* 0x1a6a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a74:
	/* 0x1a74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a79:
	/* 0x1a79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a83:
	/* 0x1a83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a85:
	/* 0x1a85: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8f:
	/* 0x1a8f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a93:
	/* 0x1a93: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a98:
	/* 0x1a98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a9d:
	/* 0x1a9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa7:
	/* 0x1aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa9:
	/* 0x1aa9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aae:
	/* 0x1aae: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ab1:
	/* 0x1ab1: je     1b3a <trace_ret_kernel_write_tail+0x1b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b3a;
	}
x86_l_1ab7:
	/* 0x1ab7: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1abc:
	/* 0x1abc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1abf:
	/* 0x1abf: je     1b3a <trace_ret_kernel_write_tail+0x1b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b3a;
	}
x86_l_1ac1:
	/* 0x1ac1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ac5:
	/* 0x1ac5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aca:
	/* 0x1aca: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1acf:
	/* 0x1acf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ad9:
	/* 0x1ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adb:
	/* 0x1adb: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1adf:
	/* 0x1adf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ae1:
	/* 0x1ae1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1aea:
	/* 0x1aea: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1aec:
	/* 0x1aec: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af1:
	/* 0x1af1: jb     1dd7 <trace_ret_kernel_write_tail+0x1dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7639ULL;
	}
x86_l_1af7:
	/* 0x1af7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1afc:
	/* 0x1afc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1b02:
	/* 0x1b02: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b07:
	/* 0x1b07: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b0a:
	/* 0x1b0a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1b0c:
	/* 0x1b0c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b11:
	/* 0x1b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b13:
	/* 0x1b13: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b16:
	/* 0x1b16: jl     1b48 <trace_ret_kernel_write_tail+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b48;
	}
x86_l_1b18:
	/* 0x1b18: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1b1c:
	/* 0x1b1c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1b22:
	/* 0x1b22: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1b28:
	/* 0x1b28: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b2b:
	/* 0x1b2b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b30:
	/* 0x1b30: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b35:
	/* 0x1b35: jmp    1d46 <trace_ret_kernel_write_tail+0x1d46> */
	return 7494ULL;
x86_l_1b3a:
	/* 0x1b3a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b3d:
	/* 0x1b3d: je     1cc9 <trace_ret_kernel_write_tail+0x1cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7369ULL;
	}
x86_l_1b43:
	/* 0x1b43: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b48:
	/* 0x1b48: cmp    r14d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_1b4f:
	/* 0x1b4f: jne    1dd7 <trace_ret_kernel_write_tail+0x1dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7639ULL;
	}
x86_l_1b55:
	/* 0x1b55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b5a:
	/* 0x1b5a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b5e:
	/* 0x1b5e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b63:
	/* 0x1b63: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b68:
	/* 0x1b68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b72:
	/* 0x1b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b74:
	/* 0x1b74: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b79:
	/* 0x1b79: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b83:
	/* 0x1b83: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b88:
	/* 0x1b88: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b8b:
	/* 0x1b8b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b90:
	/* 0x1b90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b92:
	/* 0x1b92: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b95:
	/* 0x1b95: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b9d:
	/* 0x1b9d: jmp    1e0a <trace_ret_kernel_write_tail+0x1e0a> */
	return 7690ULL;
x86_l_1ba2:
	/* 0x1ba2: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_1ba6:
	/* 0x1ba6: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1bac:
	/* 0x1bac: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1bbb:
	/* 0x1bbb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc0:
	/* 0x1bc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bc5:
	/* 0x1bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc7:
	/* 0x1bc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bca:
	/* 0x1bca: je     38c3 <trace_ret_kernel_write_tail+0x38c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14531ULL;
	}
x86_l_1bd0:
	/* 0x1bd0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1bd6:
	/* 0x1bd6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1bd8:
	/* 0x1bd8: je     2138 <trace_ret_kernel_write_tail+0x2138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8504ULL;
	}
x86_l_1bde:
	/* 0x1bde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be0:
	/* 0x1be0: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1be4:
	/* 0x1be4: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_1bea:
	/* 0x1bea: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1bef:
	/* 0x1bef: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1bf1:
	/* 0x1bf1: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1bf7:
	/* 0x1bf7: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1bfc:
	/* 0x1bfc: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_1c02:
	/* 0x1c02: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1c07:
	/* 0x1c07: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c09:
	/* 0x1c09: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1c0f:
	/* 0x1c0f: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1c14:
	/* 0x1c14: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_1c1a:
	/* 0x1c1a: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1c1f:
	/* 0x1c1f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c21:
	/* 0x1c21: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1c27:
	/* 0x1c27: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1c2c:
	/* 0x1c2c: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_1c32:
	/* 0x1c32: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1c37:
	/* 0x1c37: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c39:
	/* 0x1c39: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
x86_l_1c3f:
	/* 0x1c3f: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1c44:
	/* 0x1c44: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_1c4a:
	/* 0x1c4a: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1c4f:
	/* 0x1c4f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c51:
	/* 0x1c51: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8523ULL;
	}
	return 7255ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7255ULL: goto x86_l_1c57;
	case 7260ULL: goto x86_l_1c5c;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7297ULL: goto x86_l_1c81;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7321ULL: goto x86_l_1c99;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7338ULL: goto x86_l_1caa;
	case 7341ULL: goto x86_l_1cad;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7356ULL: goto x86_l_1cbc;
	case 7358ULL: goto x86_l_1cbe;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7373ULL: goto x86_l_1ccd;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7394ULL: goto x86_l_1ce2;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7417ULL: goto x86_l_1cf9;
	case 7421ULL: goto x86_l_1cfd;
	case 7426ULL: goto x86_l_1d02;
	case 7428ULL: goto x86_l_1d04;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7490ULL: goto x86_l_1d42;
	case 7494ULL: goto x86_l_1d46;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7535ULL: goto x86_l_1d6f;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7565ULL: goto x86_l_1d8d;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7615ULL: goto x86_l_1dbf;
	case 7617ULL: goto x86_l_1dc1;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7661ULL: goto x86_l_1ded;
	case 7669ULL: goto x86_l_1df5;
	case 7676ULL: goto x86_l_1dfc;
	case 7684ULL: goto x86_l_1e04;
	case 7690ULL: goto x86_l_1e0a;
	case 7697ULL: goto x86_l_1e11;
	case 7700ULL: goto x86_l_1e14;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7729ULL: goto x86_l_1e31;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7744ULL: goto x86_l_1e40;
	case 7750ULL: goto x86_l_1e46;
	case 7758ULL: goto x86_l_1e4e;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7803ULL: goto x86_l_1e7b;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7833ULL: goto x86_l_1e99;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7857ULL: goto x86_l_1eb1;
	case 7862ULL: goto x86_l_1eb6;
	case 7864ULL: goto x86_l_1eb8;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7888ULL: goto x86_l_1ed0;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7912ULL: goto x86_l_1ee8;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7960ULL: goto x86_l_1f18;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8001ULL: goto x86_l_1f41;
	case 8004ULL: goto x86_l_1f44;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8019ULL: goto x86_l_1f53;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8041ULL: goto x86_l_1f69;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8056ULL: goto x86_l_1f78;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8094ULL: goto x86_l_1f9e;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8118ULL: goto x86_l_1fb6;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8169ULL: goto x86_l_1fe9;
	case 8172ULL: goto x86_l_1fec;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8196ULL: goto x86_l_2004;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8214ULL: goto x86_l_2016;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8246ULL: goto x86_l_2036;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8262ULL: goto x86_l_2046;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8316ULL: goto x86_l_207c;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8362ULL: goto x86_l_20aa;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8412ULL: goto x86_l_20dc;
	case 8414ULL: goto x86_l_20de;
	case 8420ULL: goto x86_l_20e4;
	case 8423ULL: goto x86_l_20e7;
	case 8425ULL: goto x86_l_20e9;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8463ULL: goto x86_l_210f;
	case 8467ULL: goto x86_l_2113;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8482ULL: goto x86_l_2122;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8523ULL: goto x86_l_214b;
	case 8531ULL: goto x86_l_2153;
	case 8540ULL: goto x86_l_215c;
	case 8548ULL: goto x86_l_2164;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8567ULL: goto x86_l_2177;
	case 8570ULL: goto x86_l_217a;
	case 8576ULL: goto x86_l_2180;
	case 8579ULL: goto x86_l_2183;
	case 8582ULL: goto x86_l_2186;
	case 8588ULL: goto x86_l_218c;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8615ULL: goto x86_l_21a7;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8655ULL: goto x86_l_21cf;
	case 8659ULL: goto x86_l_21d3;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8716ULL: goto x86_l_220c;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8808ULL: goto x86_l_2268;
	case 8820ULL: goto x86_l_2274;
	case 8829ULL: goto x86_l_227d;
	case 8838ULL: goto x86_l_2286;
	case 8847ULL: goto x86_l_228f;
	case 8856ULL: goto x86_l_2298;
	case 8865ULL: goto x86_l_22a1;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8909ULL: goto x86_l_22cd;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8924ULL: goto x86_l_22dc;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8931ULL: goto x86_l_22e3;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8965ULL: goto x86_l_2305;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8985ULL: goto x86_l_2319;
	case 8991ULL: goto x86_l_231f;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9013ULL: goto x86_l_2335;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c57:
	/* 0x1c57: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1c5c:
	/* 0x1c5c: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1c62:
	/* 0x1c62: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1c67:
	/* 0x1c67: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c69:
	/* 0x1c69: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1c6f:
	/* 0x1c6f: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1c74:
	/* 0x1c74: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1c7a:
	/* 0x1c7a: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1c7f:
	/* 0x1c7f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c81:
	/* 0x1c81: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1c87:
	/* 0x1c87: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1c8c:
	/* 0x1c8c: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1c92:
	/* 0x1c92: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1c97:
	/* 0x1c97: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c99:
	/* 0x1c99: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1c9f:
	/* 0x1c9f: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1ca4:
	/* 0x1ca4: jne    1e46 <trace_ret_kernel_write_tail+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1caa:
	/* 0x1caa: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1cad:
	/* 0x1cad: je     1e3c <trace_ret_kernel_write_tail+0x1e3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e3c;
	}
x86_l_1cb3:
	/* 0x1cb3: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_1cb8:
	/* 0x1cb8: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1cbc:
	/* 0x1cbc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1cbe:
	/* 0x1cbe: jne    1be0 <trace_ret_kernel_write_tail+0x1be0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7136ULL;
	}
x86_l_1cc4:
	/* 0x1cc4: jmp    214b <trace_ret_kernel_write_tail+0x214b> */
	goto x86_l_214b;
x86_l_1cc9:
	/* 0x1cc9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccd:
	/* 0x1ccd: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1cd2:
	/* 0x1cd2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cdc:
	/* 0x1cdc: je     1b48 <trace_ret_kernel_write_tail+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6984ULL;
	}
x86_l_1ce2:
	/* 0x1ce2: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ce6:
	/* 0x1ce6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf9:
	/* 0x1cf9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cfd:
	/* 0x1cfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d02:
	/* 0x1d02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d04:
	/* 0x1d04: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d0b:
	/* 0x1d0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d10:
	/* 0x1d10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d15:
	/* 0x1d15: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d19:
	/* 0x1d19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d1e:
	/* 0x1d1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d20:
	/* 0x1d20: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d24:
	/* 0x1d24: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d29:
	/* 0x1d29: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d33:
	/* 0x1d33: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d37:
	/* 0x1d37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3c:
	/* 0x1d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3e:
	/* 0x1d3e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d42:
	/* 0x1d42: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d46:
	/* 0x1d46: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d4b:
	/* 0x1d4b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d50:
	/* 0x1d50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d55:
	/* 0x1d55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d5f:
	/* 0x1d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d61:
	/* 0x1d61: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d66:
	/* 0x1d66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6b:
	/* 0x1d6b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d6f:
	/* 0x1d6f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d74:
	/* 0x1d74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d79:
	/* 0x1d79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d83:
	/* 0x1d83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d85:
	/* 0x1d85: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d8a:
	/* 0x1d8a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d8d:
	/* 0x1d8d: je     1f60 <trace_ret_kernel_write_tail+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f60;
	}
x86_l_1d93:
	/* 0x1d93: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d98:
	/* 0x1d98: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d9b:
	/* 0x1d9b: je     1f60 <trace_ret_kernel_write_tail+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f60;
	}
x86_l_1da1:
	/* 0x1da1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1da5:
	/* 0x1da5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1daa:
	/* 0x1daa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1daf:
	/* 0x1daf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1db4:
	/* 0x1db4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1db9:
	/* 0x1db9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbb:
	/* 0x1dbb: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1dbf:
	/* 0x1dbf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1dc1:
	/* 0x1dc1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1dca:
	/* 0x1dca: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1dcc:
	/* 0x1dcc: jae    2021 <trace_ret_kernel_write_tail+0x2021> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2021;
	}
x86_l_1dd2:
	/* 0x1dd2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd7:
	/* 0x1dd7: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1dda:
	/* 0x1dda: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1ddd:
	/* 0x1ddd: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1de2:
	/* 0x1de2: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1de7:
	/* 0x1de7: mov    BYTE PTR [r13+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1ded:
	/* 0x1ded: mov    BYTE PTR [r13+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1df5:
	/* 0x1df5: cmp    r14d,0x7000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28672ULL);
x86_l_1dfc:
	/* 0x1dfc: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e04:
	/* 0x1e04: jae    2153 <trace_ret_kernel_write_tail+0x2153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2153;
	}
x86_l_1e0a:
	/* 0x1e0a: and    r14d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1e11:
	/* 0x1e11: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e14:
	/* 0x1e14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1e1b:
	/* 0x1e1b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e1d:
	/* 0x1e1d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e22:
	/* 0x1e22: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e27:
	/* 0x1e27: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e2a:
	/* 0x1e2a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e2c:
	/* 0x1e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2e:
	/* 0x1e2e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1e31:
	/* 0x1e31: jne    1724 <trace_ret_kernel_write_tail+0x1724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5924ULL;
	}
x86_l_1e37:
	/* 0x1e37: jmp    2153 <trace_ret_kernel_write_tail+0x2153> */
	goto x86_l_2153;
x86_l_1e3c:
	/* 0x1e3c: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_1e40:
	/* 0x1e40: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1e46:
	/* 0x1e46: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1e55:
	/* 0x1e55: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e5f:
	/* 0x1e5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e61:
	/* 0x1e61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e64:
	/* 0x1e64: je     38c3 <trace_ret_kernel_write_tail+0x38c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14531ULL;
	}
x86_l_1e6a:
	/* 0x1e6a: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e6d:
	/* 0x1e6d: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1e6f:
	/* 0x1e6f: je     2138 <trace_ret_kernel_write_tail+0x2138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2138;
	}
x86_l_1e75:
	/* 0x1e75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e77:
	/* 0x1e77: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e7b:
	/* 0x1e7b: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1e81:
	/* 0x1e81: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1e86:
	/* 0x1e86: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1e88:
	/* 0x1e88: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1e8e:
	/* 0x1e8e: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1e93:
	/* 0x1e93: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1e99:
	/* 0x1e99: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1e9e:
	/* 0x1e9e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ea0:
	/* 0x1ea0: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1ea6:
	/* 0x1ea6: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1eab:
	/* 0x1eab: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1eb1:
	/* 0x1eb1: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1eb6:
	/* 0x1eb6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1eb8:
	/* 0x1eb8: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1ebe:
	/* 0x1ebe: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1ec3:
	/* 0x1ec3: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1ec9:
	/* 0x1ec9: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1ece:
	/* 0x1ece: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ed0:
	/* 0x1ed0: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1ed6:
	/* 0x1ed6: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1edb:
	/* 0x1edb: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1ee1:
	/* 0x1ee1: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1ee6:
	/* 0x1ee6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ee8:
	/* 0x1ee8: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1eee:
	/* 0x1eee: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1ef3:
	/* 0x1ef3: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1ef9:
	/* 0x1ef9: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1efe:
	/* 0x1efe: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f00:
	/* 0x1f00: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1f06:
	/* 0x1f06: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1f0b:
	/* 0x1f0b: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1f11:
	/* 0x1f11: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1f16:
	/* 0x1f16: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f18:
	/* 0x1f18: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1f1e:
	/* 0x1f1e: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1f23:
	/* 0x1f23: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1f29:
	/* 0x1f29: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1f2e:
	/* 0x1f2e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f30:
	/* 0x1f30: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_1f36:
	/* 0x1f36: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1f3b:
	/* 0x1f3b: jne    2135 <trace_ret_kernel_write_tail+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2135;
	}
x86_l_1f41:
	/* 0x1f41: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1f44:
	/* 0x1f44: je     212f <trace_ret_kernel_write_tail+0x212f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212f;
	}
x86_l_1f4a:
	/* 0x1f4a: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_1f4f:
	/* 0x1f4f: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1f53:
	/* 0x1f53: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f55:
	/* 0x1f55: jne    1e77 <trace_ret_kernel_write_tail+0x1e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e77;
	}
x86_l_1f5b:
	/* 0x1f5b: jmp    214b <trace_ret_kernel_write_tail+0x214b> */
	goto x86_l_214b;
x86_l_1f60:
	/* 0x1f60: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f63:
	/* 0x1f63: jne    1b43 <trace_ret_kernel_write_tail+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6979ULL;
	}
x86_l_1f69:
	/* 0x1f69: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6d:
	/* 0x1f6d: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1f72:
	/* 0x1f72: je     1b43 <trace_ret_kernel_write_tail+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6979ULL;
	}
x86_l_1f78:
	/* 0x1f78: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f7c:
	/* 0x1f7c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f81:
	/* 0x1f81: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f86:
	/* 0x1f86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f8f:
	/* 0x1f8f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f93:
	/* 0x1f93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f98:
	/* 0x1f98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9a:
	/* 0x1f9a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9e:
	/* 0x1f9e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fa1:
	/* 0x1fa1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fab:
	/* 0x1fab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1faf:
	/* 0x1faf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb4:
	/* 0x1fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb6:
	/* 0x1fb6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fba:
	/* 0x1fba: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fd2:
	/* 0x1fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd4:
	/* 0x1fd4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd8:
	/* 0x1fd8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fdc:
	/* 0x1fdc: jmp    2063 <trace_ret_kernel_write_tail+0x2063> */
	goto x86_l_2063;
x86_l_1fe1:
	/* 0x1fe1: lea    rdi,[r12+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1fec:
	/* 0x1fec: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1ff5:
	/* 0x1ff5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1fff:
	/* 0x1fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2001:
	/* 0x2001: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2004:
	/* 0x2004: jne    30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12500ULL;
	}
x86_l_200a:
	/* 0x200a: movzx  eax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_200e:
	/* 0x200e: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2016:
	/* 0x2016: mov    WORD PTR [r12+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_201c:
	/* 0x201c: jmp    c6d <trace_ret_kernel_write_tail+0xc6d> */
	return 3181ULL;
x86_l_2021:
	/* 0x2021: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2026:
	/* 0x2026: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_202c:
	/* 0x202c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_202f:
	/* 0x202f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2031:
	/* 0x2031: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2036:
	/* 0x2036: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2038:
	/* 0x2038: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_203b:
	/* 0x203b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2040:
	/* 0x2040: jl     1b48 <trace_ret_kernel_write_tail+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6984ULL;
	}
x86_l_2046:
	/* 0x2046: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_204a:
	/* 0x204a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2050:
	/* 0x2050: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2056:
	/* 0x2056: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2059:
	/* 0x2059: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205e:
	/* 0x205e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2063:
	/* 0x2063: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2068:
	/* 0x2068: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_206d:
	/* 0x206d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2072:
	/* 0x2072: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2077:
	/* 0x2077: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_207c:
	/* 0x207c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_207e:
	/* 0x207e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2083:
	/* 0x2083: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2088:
	/* 0x2088: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_208c:
	/* 0x208c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2091:
	/* 0x2091: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2096:
	/* 0x2096: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_209b:
	/* 0x209b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a0:
	/* 0x20a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a2:
	/* 0x20a2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a7:
	/* 0x20a7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20aa:
	/* 0x20aa: je     325b <trace_ret_kernel_write_tail+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_20b0:
	/* 0x20b0: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b5:
	/* 0x20b5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20b8:
	/* 0x20b8: je     325b <trace_ret_kernel_write_tail+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_20be:
	/* 0x20be: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20c2:
	/* 0x20c2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c7:
	/* 0x20c7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_20cc:
	/* 0x20cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20d1:
	/* 0x20d1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20d6:
	/* 0x20d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d8:
	/* 0x20d8: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20dc:
	/* 0x20dc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_20de:
	/* 0x20de: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e4:
	/* 0x20e4: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_20e7:
	/* 0x20e7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20e9:
	/* 0x20e9: jb     1dd2 <trace_ret_kernel_write_tail+0x1dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dd2;
	}
x86_l_20ef:
	/* 0x20ef: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20f4:
	/* 0x20f4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_20fa:
	/* 0x20fa: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20fd:
	/* 0x20fd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_20ff:
	/* 0x20ff: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2104:
	/* 0x2104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2106:
	/* 0x2106: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2109:
	/* 0x2109: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_210f:
	/* 0x210f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2113:
	/* 0x2113: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2119:
	/* 0x2119: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_211e:
	/* 0x211e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2122:
	/* 0x2122: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2125:
	/* 0x2125: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212a:
	/* 0x212a: jmp    32dc <trace_ret_kernel_write_tail+0x32dc> */
	return 13020ULL;
x86_l_212f:
	/* 0x212f: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_2133:
	/* 0x2133: je     214b <trace_ret_kernel_write_tail+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214b;
	}
x86_l_2135:
	/* 0x2135: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_2138:
	/* 0x2138: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_213b:
	/* 0x213b: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2143:
	/* 0x2143: jne    30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12500ULL;
	}
x86_l_2149:
	/* 0x2149: jmp    2153 <trace_ret_kernel_write_tail+0x2153> */
	goto x86_l_2153;
x86_l_214b:
	/* 0x214b: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2153:
	/* 0x2153: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_215c:
	/* 0x215c: mov    BYTE PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2164:
	/* 0x2164: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_216b:
	/* 0x216b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2170:
	/* 0x2170: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2175:
	/* 0x2175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2177:
	/* 0x2177: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_217a:
	/* 0x217a: je     34b1 <trace_ret_kernel_write_tail+0x34b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13489ULL;
	}
x86_l_2180:
	/* 0x2180: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2183:
	/* 0x2183: test   BYTE PTR [rax],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_2186:
	/* 0x2186: je     232c <trace_ret_kernel_write_tail+0x232c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232c;
	}
x86_l_218c:
	/* 0x218c: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2190:
	/* 0x2190: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2195:
	/* 0x2195: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_219a:
	/* 0x219a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_219f:
	/* 0x219f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a4:
	/* 0x21a4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_21a7:
	/* 0x21a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a9:
	/* 0x21a9: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21ae:
	/* 0x21ae: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21b3:
	/* 0x21b3: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_21b8:
	/* 0x21b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21bd:
	/* 0x21bd: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21c2:
	/* 0x21c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_21c7:
	/* 0x21c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c9:
	/* 0x21c9: movzx  r15d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_21cf:
	/* 0x21cf: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d3:
	/* 0x21d3: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_21d5:
	/* 0x21d5: je     22fd <trace_ret_kernel_write_tail+0x22fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fd;
	}
x86_l_21db:
	/* 0x21db: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21df:
	/* 0x21df: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21e4:
	/* 0x21e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21e9:
	/* 0x21e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21ee:
	/* 0x21ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f3:
	/* 0x21f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f5:
	/* 0x21f5: movabs rax,0x6972775f65706970 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598266772934912368ULL);
x86_l_21ff:
	/* 0x21ff: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2204:
	/* 0x2204: mov    DWORD PTR [rsp+0x1f],0x657469 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 133150635113ULL);
x86_l_220c:
	/* 0x220c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2215:
	/* 0x2215: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_221a:
	/* 0x221a: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_221e:
	/* 0x221e: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2223:
	/* 0x2223: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2228:
	/* 0x2228: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_222d:
	/* 0x222d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2232:
	/* 0x2232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2234:
	/* 0x2234: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2239:
	/* 0x2239: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_223d:
	/* 0x223d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2242:
	/* 0x2242: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2247:
	/* 0x2247: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_224c:
	/* 0x224c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2251:
	/* 0x2251: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2255:
	/* 0x2255: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_225a:
	/* 0x225a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225c:
	/* 0x225c: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2268:
	/* 0x2268: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2274:
	/* 0x2274: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_227d:
	/* 0x227d: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2286:
	/* 0x2286: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_228f:
	/* 0x228f: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2298:
	/* 0x2298: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_22a1:
	/* 0x22a1: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_22aa:
	/* 0x22aa: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22af:
	/* 0x22af: lea    rbx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22b4:
	/* 0x22b4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22b9:
	/* 0x22b9: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_22be:
	/* 0x22be: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_22c3:
	/* 0x22c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_22cb:
	/* 0x22cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22cd:
	/* 0x22cd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ksymbols_map)));
x86_l_22d4:
	/* 0x22d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22d9:
	/* 0x22d9: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_22dc:
	/* 0x22dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22de:
	/* 0x22de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e1:
	/* 0x22e1: je     22e8 <trace_ret_kernel_write_tail+0x22e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e8;
	}
x86_l_22e3:
	/* 0x22e3: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e6:
	/* 0x22e6: jmp    22ea <trace_ret_kernel_write_tail+0x22ea> */
	goto x86_l_22ea;
x86_l_22e8:
	/* 0x22e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22ea:
	/* 0x22ea: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_22ed:
	/* 0x22ed: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22f2:
	/* 0x22f2: jne    22f9 <trace_ret_kernel_write_tail+0x22f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f9;
	}
x86_l_22f4:
	/* 0x22f4: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_22f7:
	/* 0x22f7: jne    231f <trace_ret_kernel_write_tail+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_231f;
	}
x86_l_22f9:
	/* 0x22f9: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22fd:
	/* 0x22fd: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_22ff:
	/* 0x22ff: je     230d <trace_ret_kernel_write_tail+0x230d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_230d;
	}
x86_l_2301:
	/* 0x2301: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2305:
	/* 0x2305: cmp    ecx,0x3fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16383ULL);
x86_l_230b:
	/* 0x230b: ja     231f <trace_ret_kernel_write_tail+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_231f;
	}
x86_l_230d:
	/* 0x230d: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_230f:
	/* 0x230f: je     248a <trace_ret_kernel_write_tail+0x248a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9354ULL;
	}
x86_l_2315:
	/* 0x2315: test   r15w,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_16);
x86_l_2319:
	/* 0x2319: jns    248a <trace_ret_kernel_write_tail+0x248a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9354ULL;
	}
x86_l_231f:
	/* 0x231f: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2327:
	/* 0x2327: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_232c:
	/* 0x232c: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2335:
	/* 0x2335: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_233c:
	/* 0x233c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2341:
	/* 0x2341: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2346:
	/* 0x2346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 9032ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9054ULL: goto x86_l_235e;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9070ULL: goto x86_l_236e;
	case 9073ULL: goto x86_l_2371;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9107ULL: goto x86_l_2393;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9155ULL: goto x86_l_23c3;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9175ULL: goto x86_l_23d7;
	case 9181ULL: goto x86_l_23dd;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9233ULL: goto x86_l_2411;
	case 9242ULL: goto x86_l_241a;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9268ULL: goto x86_l_2434;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9281ULL: goto x86_l_2441;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9354ULL: goto x86_l_248a;
	case 9356ULL: goto x86_l_248c;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9375ULL: goto x86_l_249f;
	case 9383ULL: goto x86_l_24a7;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9402ULL: goto x86_l_24ba;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9417ULL: goto x86_l_24c9;
	case 9423ULL: goto x86_l_24cf;
	case 9425ULL: goto x86_l_24d1;
	case 9427ULL: goto x86_l_24d3;
	case 9430ULL: goto x86_l_24d6;
	case 9432ULL: goto x86_l_24d8;
	case 9438ULL: goto x86_l_24de;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9453ULL: goto x86_l_24ed;
	case 9462ULL: goto x86_l_24f6;
	case 9471ULL: goto x86_l_24ff;
	case 9480ULL: goto x86_l_2508;
	case 9483ULL: goto x86_l_250b;
	case 9489ULL: goto x86_l_2511;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9532ULL: goto x86_l_253c;
	case 9541ULL: goto x86_l_2545;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9604ULL: goto x86_l_2584;
	case 9606ULL: goto x86_l_2586;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9635ULL: goto x86_l_25a3;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9723ULL: goto x86_l_25fb;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9801ULL: goto x86_l_2649;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9887ULL: goto x86_l_269f;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9899ULL: goto x86_l_26ab;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9913ULL: goto x86_l_26b9;
	case 9915ULL: goto x86_l_26bb;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9934ULL: goto x86_l_26ce;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9956ULL: goto x86_l_26e4;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10039ULL: goto x86_l_2737;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10053ULL: goto x86_l_2745;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10065ULL: goto x86_l_2751;
	case 10070ULL: goto x86_l_2756;
	case 10074ULL: goto x86_l_275a;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10093ULL: goto x86_l_276d;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10127ULL: goto x86_l_278f;
	case 10129ULL: goto x86_l_2791;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10153ULL: goto x86_l_27a9;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10173ULL: goto x86_l_27bd;
	case 10179ULL: goto x86_l_27c3;
	case 10184ULL: goto x86_l_27c8;
	case 10187ULL: goto x86_l_27cb;
	case 10193ULL: goto x86_l_27d1;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10223ULL: goto x86_l_27ef;
	case 10228ULL: goto x86_l_27f4;
	case 10230ULL: goto x86_l_27f6;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10246ULL: goto x86_l_2806;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10256ULL: goto x86_l_2810;
	case 10259ULL: goto x86_l_2813;
	case 10265ULL: goto x86_l_2819;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10290ULL: goto x86_l_2832;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10317ULL: goto x86_l_284d;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10333ULL: goto x86_l_285d;
	case 10342ULL: goto x86_l_2866;
	case 10345ULL: goto x86_l_2869;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10374ULL: goto x86_l_2886;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10390ULL: goto x86_l_2896;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10439ULL: goto x86_l_28c7;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10464ULL: goto x86_l_28e0;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10478ULL: goto x86_l_28ee;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10541ULL: goto x86_l_292d;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10582ULL: goto x86_l_2956;
	case 10586ULL: goto x86_l_295a;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10605ULL: goto x86_l_296d;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10620ULL: goto x86_l_297c;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10644ULL: goto x86_l_2994;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10674ULL: goto x86_l_29b2;
	case 10678ULL: goto x86_l_29b6;
	case 10682ULL: goto x86_l_29ba;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2348:
	/* 0x2348: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_234b:
	/* 0x234b: je     35d5 <trace_ret_kernel_write_tail+0x35d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13781ULL;
	}
x86_l_2351:
	/* 0x2351: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2354:
	/* 0x2354: test   BYTE PTR [rax+0x2],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934599ULL);
x86_l_2358:
	/* 0x2358: je     24ed <trace_ret_kernel_write_tail+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ed;
	}
x86_l_235e:
	/* 0x235e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2363:
	/* 0x2363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2365:
	/* 0x2365: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2368:
	/* 0x2368: je     247c <trace_ret_kernel_write_tail+0x247c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247c;
	}
x86_l_236e:
	/* 0x236e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2371:
	/* 0x2371: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2375:
	/* 0x2375: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_237a:
	/* 0x237a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_237f:
	/* 0x237f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2384:
	/* 0x2384: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2389:
	/* 0x2389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238b:
	/* 0x238b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2390:
	/* 0x2390: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2393:
	/* 0x2393: je     2483 <trace_ret_kernel_write_tail+0x2483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2483;
	}
x86_l_2399:
	/* 0x2399: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_239e:
	/* 0x239e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23a3:
	/* 0x23a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23a8:
	/* 0x23a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ad:
	/* 0x23ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23af:
	/* 0x23af: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23b4:
	/* 0x23b4: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23b9:
	/* 0x23b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23be:
	/* 0x23be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23c3:
	/* 0x23c3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c8:
	/* 0x23c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23cd:
	/* 0x23cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23cf:
	/* 0x23cf: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23d4:
	/* 0x23d4: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_23d7:
	/* 0x23d7: je     24b2 <trace_ret_kernel_write_tail+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b2;
	}
x86_l_23dd:
	/* 0x23dd: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_23e6:
	/* 0x23e6: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23eb:
	/* 0x23eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23f0:
	/* 0x23f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f5:
	/* 0x23f5: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_23f8:
	/* 0x23f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23fd:
	/* 0x23fd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2400:
	/* 0x2400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2402:
	/* 0x2402: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2404:
	/* 0x2404: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2409:
	/* 0x2409: cmp    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_240e:
	/* 0x240e: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_2411:
	/* 0x2411: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_241a:
	/* 0x241a: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_241e:
	/* 0x241e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2423:
	/* 0x2423: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2428:
	/* 0x2428: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_242b:
	/* 0x242b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2430:
	/* 0x2430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2432:
	/* 0x2432: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2434:
	/* 0x2434: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2439:
	/* 0x2439: cmp    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_243e:
	/* 0x243e: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2441:
	/* 0x2441: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_244a:
	/* 0x244a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_244e:
	/* 0x244e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2453:
	/* 0x2453: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2458:
	/* 0x2458: lea    ebx,[rbx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_245b:
	/* 0x245b: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_245e:
	/* 0x245e: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2463:
	/* 0x2463: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2468:
	/* 0x2468: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_246b:
	/* 0x246b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246d:
	/* 0x246d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_246f:
	/* 0x246f: cmp    QWORD PTR [rsp+0x50],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2474:
	/* 0x2474: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2477:
	/* 0x2477: lea    eax,[rbx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_247a:
	/* 0x247a: jmp    24b7 <trace_ret_kernel_write_tail+0x24b7> */
	goto x86_l_24b7;
x86_l_247c:
	/* 0x247c: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2481:
	/* 0x2481: jmp    24b7 <trace_ret_kernel_write_tail+0x24b7> */
	goto x86_l_24b7;
x86_l_2483:
	/* 0x2483: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_2488:
	/* 0x2488: jmp    24b7 <trace_ret_kernel_write_tail+0x24b7> */
	goto x86_l_24b7;
x86_l_248a:
	/* 0x248a: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_248c:
	/* 0x248c: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2494:
	/* 0x2494: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2499:
	/* 0x2499: jne    2854 <trace_ret_kernel_write_tail+0x2854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2854;
	}
x86_l_249f:
	/* 0x249f: cmp    BYTE PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_24a7:
	/* 0x24a7: jne    232c <trace_ret_kernel_write_tail+0x232c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9004ULL;
	}
x86_l_24ad:
	/* 0x24ad: jmp    30d4 <trace_ret_kernel_write_tail+0x30d4> */
	return 12500ULL;
x86_l_24b2:
	/* 0x24b2: mov    eax,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967293ULL);
x86_l_24b7:
	/* 0x24b7: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ba:
	/* 0x24ba: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_24c0:
	/* 0x24c0: je     24c9 <trace_ret_kernel_write_tail+0x24c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c9;
	}
x86_l_24c2:
	/* 0x24c2: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_24c4:
	/* 0x24c4: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_24c7:
	/* 0x24c7: jne    24ed <trace_ret_kernel_write_tail+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24ed;
	}
x86_l_24c9:
	/* 0x24c9: test   ecx,0x20000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 131072ULL);
x86_l_24cf:
	/* 0x24cf: je     24d8 <trace_ret_kernel_write_tail+0x24d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d8;
	}
x86_l_24d1:
	/* 0x24d1: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_24d3:
	/* 0x24d3: and    edx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_24d6:
	/* 0x24d6: jne    24ed <trace_ret_kernel_write_tail+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24ed;
	}
x86_l_24d8:
	/* 0x24d8: test   ecx,0x40000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 262144ULL);
x86_l_24de:
	/* 0x24de: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_24e4:
	/* 0x24e4: and    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4ULL);
x86_l_24e7:
	/* 0x24e7: je     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_24ed:
	/* 0x24ed: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_24f6:
	/* 0x24f6: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_24ff:
	/* 0x24ff: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2508:
	/* 0x2508: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_250b:
	/* 0x250b: je     2698 <trace_ret_kernel_write_tail+0x2698> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2698;
	}
x86_l_2511:
	/* 0x2511: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2515:
	/* 0x2515: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_251a:
	/* 0x251a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_251f:
	/* 0x251f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2524:
	/* 0x2524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2529:
	/* 0x2529: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_252c:
	/* 0x252c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252e:
	/* 0x252e: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2533:
	/* 0x2533: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_253c:
	/* 0x253c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2545:
	/* 0x2545: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2549:
	/* 0x2549: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_254e:
	/* 0x254e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2553:
	/* 0x2553: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2558:
	/* 0x2558: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255d:
	/* 0x255d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255f:
	/* 0x255f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2564:
	/* 0x2564: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2569:
	/* 0x2569: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_256d:
	/* 0x256d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2572:
	/* 0x2572: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2577:
	/* 0x2577: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_257c:
	/* 0x257c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2581:
	/* 0x2581: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2584:
	/* 0x2584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2586:
	/* 0x2586: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_258a:
	/* 0x258a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258f:
	/* 0x258f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2594:
	/* 0x2594: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2599:
	/* 0x2599: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_259e:
	/* 0x259e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25a3:
	/* 0x25a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25a8:
	/* 0x25a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25aa:
	/* 0x25aa: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25af:
	/* 0x25af: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_25b2:
	/* 0x25b2: js     25dd <trace_ret_kernel_write_tail+0x25dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25dd;
	}
x86_l_25b4:
	/* 0x25b4: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b9:
	/* 0x25b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25be:
	/* 0x25be: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25c3:
	/* 0x25c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25c8:
	/* 0x25c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25cd:
	/* 0x25cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cf:
	/* 0x25cf: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_25d6:
	/* 0x25d6: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25db:
	/* 0x25db: jmp    25df <trace_ret_kernel_write_tail+0x25df> */
	goto x86_l_25df;
x86_l_25dd:
	/* 0x25dd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25df:
	/* 0x25df: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25e4:
	/* 0x25e4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25e9:
	/* 0x25e9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25ee:
	/* 0x25ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25f3:
	/* 0x25f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f8:
	/* 0x25f8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_25fb:
	/* 0x25fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fd:
	/* 0x25fd: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2602:
	/* 0x2602: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2606:
	/* 0x2606: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260b:
	/* 0x260b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2610:
	/* 0x2610: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2615:
	/* 0x2615: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_261a:
	/* 0x261a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_261e:
	/* 0x261e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2623:
	/* 0x2623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2625:
	/* 0x2625: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262a:
	/* 0x262a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262f:
	/* 0x262f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2634:
	/* 0x2634: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2639:
	/* 0x2639: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_263e:
	/* 0x263e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2643:
	/* 0x2643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2645:
	/* 0x2645: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2649:
	/* 0x2649: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_264d:
	/* 0x264d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2652:
	/* 0x2652: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2657:
	/* 0x2657: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_265c:
	/* 0x265c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2661:
	/* 0x2661: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2664:
	/* 0x2664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2666:
	/* 0x2666: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266b:
	/* 0x266b: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_266f:
	/* 0x266f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2674:
	/* 0x2674: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2679:
	/* 0x2679: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_267e:
	/* 0x267e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2683:
	/* 0x2683: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2687:
	/* 0x2687: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_268c:
	/* 0x268c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268e:
	/* 0x268e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2693:
	/* 0x2693: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2698:
	/* 0x2698: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_269f:
	/* 0x269f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26a4:
	/* 0x26a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26a9:
	/* 0x26a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ab:
	/* 0x26ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26ae:
	/* 0x26ae: je     26c6 <trace_ret_kernel_write_tail+0x26c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26c6;
	}
x86_l_26b0:
	/* 0x26b0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_26b3:
	/* 0x26b3: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26b7:
	/* 0x26b7: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_26b9:
	/* 0x26b9: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_26bb:
	/* 0x26bb: je     2dec <trace_ret_kernel_write_tail+0x2dec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11756ULL;
	}
x86_l_26c1:
	/* 0x26c1: jmp    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	return 11849ULL;
x86_l_26c6:
	/* 0x26c6: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_26ce:
	/* 0x26ce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_26d5:
	/* 0x26d5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26da:
	/* 0x26da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26df:
	/* 0x26df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e1:
	/* 0x26e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e4:
	/* 0x26e4: je     2e56 <trace_ret_kernel_write_tail+0x2e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11862ULL;
	}
x86_l_26ea:
	/* 0x26ea: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_26ed:
	/* 0x26ed: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f1:
	/* 0x26f1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26f6:
	/* 0x26f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26fb:
	/* 0x26fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2700:
	/* 0x2700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2705:
	/* 0x2705: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2707:
	/* 0x2707: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_270c:
	/* 0x270c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2711:
	/* 0x2711: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2716:
	/* 0x2716: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_271b:
	/* 0x271b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2720:
	/* 0x2720: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2725:
	/* 0x2725: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_272a:
	/* 0x272a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272c:
	/* 0x272c: test   BYTE PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215136ULL);
x86_l_2731:
	/* 0x2731: jne    2832 <trace_ret_kernel_write_tail+0x2832> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2832;
	}
x86_l_2737:
	/* 0x2737: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273b:
	/* 0x273b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2740:
	/* 0x2740: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2745:
	/* 0x2745: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_274a:
	/* 0x274a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_274f:
	/* 0x274f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2751:
	/* 0x2751: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2756:
	/* 0x2756: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_275a:
	/* 0x275a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_275e:
	/* 0x275e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2763:
	/* 0x2763: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2768:
	/* 0x2768: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_276d:
	/* 0x276d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2771:
	/* 0x2771: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2776:
	/* 0x2776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2778:
	/* 0x2778: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277d:
	/* 0x277d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2782:
	/* 0x2782: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2787:
	/* 0x2787: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_278c:
	/* 0x278c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_278f:
	/* 0x278f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2791:
	/* 0x2791: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2796:
	/* 0x2796: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_279b:
	/* 0x279b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_279f:
	/* 0x279f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27a4:
	/* 0x27a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27a9:
	/* 0x27a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27ae:
	/* 0x27ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27b3:
	/* 0x27b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b5:
	/* 0x27b5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27ba:
	/* 0x27ba: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_27bd:
	/* 0x27bd: je     293e <trace_ret_kernel_write_tail+0x293e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_293e;
	}
x86_l_27c3:
	/* 0x27c3: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27c8:
	/* 0x27c8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27cb:
	/* 0x27cb: je     293e <trace_ret_kernel_write_tail+0x293e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_293e;
	}
x86_l_27d1:
	/* 0x27d1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27d5:
	/* 0x27d5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27da:
	/* 0x27da: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27df:
	/* 0x27df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e4:
	/* 0x27e4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27e9:
	/* 0x27e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27eb:
	/* 0x27eb: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_27ef:
	/* 0x27ef: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27f4:
	/* 0x27f4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_27f6:
	/* 0x27f6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27fc:
	/* 0x27fc: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_27fe:
	/* 0x27fe: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2800:
	/* 0x2800: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2806:
	/* 0x2806: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2809:
	/* 0x2809: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_280e:
	/* 0x280e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2810:
	/* 0x2810: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2813:
	/* 0x2813: jl     2a95 <trace_ret_kernel_write_tail+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10901ULL;
	}
x86_l_2819:
	/* 0x2819: mov    BYTE PTR [r14+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_2821:
	/* 0x2821: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2826:
	/* 0x2826: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2828:
	/* 0x2828: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282d:
	/* 0x282d: jmp    29bf <trace_ret_kernel_write_tail+0x29bf> */
	goto x86_l_29bf;
x86_l_2832:
	/* 0x2832: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2839:
	/* 0x2839: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_283e:
	/* 0x283e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2843:
	/* 0x2843: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2846:
	/* 0x2846: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_284b:
	/* 0x284b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284d:
	/* 0x284d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284f:
	/* 0x284f: jmp    2dbf <trace_ret_kernel_write_tail+0x2dbf> */
	return 11711ULL;
x86_l_2854:
	/* 0x2854: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_285d:
	/* 0x285d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2866:
	/* 0x2866: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2869:
	/* 0x2869: je     2b99 <trace_ret_kernel_write_tail+0x2b99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11161ULL;
	}
x86_l_286f:
	/* 0x286f: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2874:
	/* 0x2874: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2879:
	/* 0x2879: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_287e:
	/* 0x287e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2883:
	/* 0x2883: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2886:
	/* 0x2886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2888:
	/* 0x2888: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_288d:
	/* 0x288d: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2896:
	/* 0x2896: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_289f:
	/* 0x289f: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28a3:
	/* 0x28a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a8:
	/* 0x28a8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28ad:
	/* 0x28ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28b2:
	/* 0x28b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b7:
	/* 0x28b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b9:
	/* 0x28b9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28be:
	/* 0x28be: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28c3:
	/* 0x28c3: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_28c7:
	/* 0x28c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28cc:
	/* 0x28cc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28d1:
	/* 0x28d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28d6:
	/* 0x28d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28db:
	/* 0x28db: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28de:
	/* 0x28de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e0:
	/* 0x28e0: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e4:
	/* 0x28e4: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28e9:
	/* 0x28e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ee:
	/* 0x28ee: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28f3:
	/* 0x28f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28f8:
	/* 0x28f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28fd:
	/* 0x28fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2902:
	/* 0x2902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2904:
	/* 0x2904: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2909:
	/* 0x2909: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_290c:
	/* 0x290c: js     2ae1 <trace_ret_kernel_write_tail+0x2ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10977ULL;
	}
x86_l_2912:
	/* 0x2912: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2917:
	/* 0x2917: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291c:
	/* 0x291c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2921:
	/* 0x2921: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2926:
	/* 0x2926: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_292b:
	/* 0x292b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292d:
	/* 0x292d: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_2934:
	/* 0x2934: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2939:
	/* 0x2939: jmp    2ae3 <trace_ret_kernel_write_tail+0x2ae3> */
	return 10979ULL;
x86_l_293e:
	/* 0x293e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2941:
	/* 0x2941: jne    2a95 <trace_ret_kernel_write_tail+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10901ULL;
	}
x86_l_2947:
	/* 0x2947: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294b:
	/* 0x294b: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2950:
	/* 0x2950: je     2a95 <trace_ret_kernel_write_tail+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10901ULL;
	}
x86_l_2956:
	/* 0x2956: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_295a:
	/* 0x295a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_295f:
	/* 0x295f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2964:
	/* 0x2964: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2969:
	/* 0x2969: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296d:
	/* 0x296d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2971:
	/* 0x2971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2976:
	/* 0x2976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2978:
	/* 0x2978: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297c:
	/* 0x297c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_297f:
	/* 0x297f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2984:
	/* 0x2984: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2989:
	/* 0x2989: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298d:
	/* 0x298d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2992:
	/* 0x2992: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2994:
	/* 0x2994: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2998:
	/* 0x2998: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_299d:
	/* 0x299d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29a2:
	/* 0x29a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29a7:
	/* 0x29a7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ab:
	/* 0x29ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b0:
	/* 0x29b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b2:
	/* 0x29b2: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b6:
	/* 0x29b6: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29ba:
	/* 0x29ba: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_29bf:
	/* 0x29bf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29c4:
	/* 0x29c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29c9:
	/* 0x29c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ce:
	/* 0x29ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29d3:
	/* 0x29d3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_29d6:
	/* 0x29d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d8:
	/* 0x29d8: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29dd:
	/* 0x29dd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29e2:
	/* 0x29e2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29e6:
	/* 0x29e6: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29eb:
	/* 0x29eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29f0:
	/* 0x29f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 10741ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10756ULL: goto x86_l_2a04;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10772ULL: goto x86_l_2a14;
	case 10777ULL: goto x86_l_2a19;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10794ULL: goto x86_l_2a2a;
	case 10798ULL: goto x86_l_2a2e;
	case 10800ULL: goto x86_l_2a30;
	case 10806ULL: goto x86_l_2a36;
	case 10808ULL: goto x86_l_2a38;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10847ULL: goto x86_l_2a5f;
	case 10849ULL: goto x86_l_2a61;
	case 10852ULL: goto x86_l_2a64;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10878ULL: goto x86_l_2a7e;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10895ULL: goto x86_l_2a8f;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11007ULL: goto x86_l_2aff;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11079ULL: goto x86_l_2b47;
	case 11082ULL: goto x86_l_2b4a;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11109ULL: goto x86_l_2b65;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11170ULL: goto x86_l_2ba2;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11198ULL: goto x86_l_2bbe;
	case 11200ULL: goto x86_l_2bc0;
	case 11203ULL: goto x86_l_2bc3;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11218ULL: goto x86_l_2bd2;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11240ULL: goto x86_l_2be8;
	case 11249ULL: goto x86_l_2bf1;
	case 11258ULL: goto x86_l_2bfa;
	case 11267ULL: goto x86_l_2c03;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11296ULL: goto x86_l_2c20;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11318ULL: goto x86_l_2c36;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11334ULL: goto x86_l_2c46;
	case 11342ULL: goto x86_l_2c4e;
	case 11349ULL: goto x86_l_2c55;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11371ULL: goto x86_l_2c6b;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11395ULL: goto x86_l_2c83;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11422ULL: goto x86_l_2c9e;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11445ULL: goto x86_l_2cb5;
	case 11449ULL: goto x86_l_2cb9;
	case 11454ULL: goto x86_l_2cbe;
	case 11456ULL: goto x86_l_2cc0;
	case 11460ULL: goto x86_l_2cc4;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11514ULL: goto x86_l_2cfa;
	case 11518ULL: goto x86_l_2cfe;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11591ULL: goto x86_l_2d47;
	case 11597ULL: goto x86_l_2d4d;
	case 11602ULL: goto x86_l_2d52;
	case 11605ULL: goto x86_l_2d55;
	case 11611ULL: goto x86_l_2d5b;
	case 11615ULL: goto x86_l_2d5f;
	case 11620ULL: goto x86_l_2d64;
	case 11625ULL: goto x86_l_2d69;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11637ULL: goto x86_l_2d75;
	case 11641ULL: goto x86_l_2d79;
	case 11643ULL: goto x86_l_2d7b;
	case 11649ULL: goto x86_l_2d81;
	case 11651ULL: goto x86_l_2d83;
	case 11653ULL: goto x86_l_2d85;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11678ULL: goto x86_l_2d9e;
	case 11686ULL: goto x86_l_2da6;
	case 11692ULL: goto x86_l_2dac;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11711ULL: goto x86_l_2dbf;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11727ULL: goto x86_l_2dcf;
	case 11729ULL: goto x86_l_2dd1;
	case 11734ULL: goto x86_l_2dd6;
	case 11739ULL: goto x86_l_2ddb;
	case 11742ULL: goto x86_l_2dde;
	case 11744ULL: goto x86_l_2de0;
	case 11746ULL: goto x86_l_2de2;
	case 11750ULL: goto x86_l_2de6;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11763ULL: goto x86_l_2df3;
	case 11765ULL: goto x86_l_2df5;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11787ULL: goto x86_l_2e0b;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11796ULL: goto x86_l_2e14;
	case 11798ULL: goto x86_l_2e16;
	case 11800ULL: goto x86_l_2e18;
	case 11805ULL: goto x86_l_2e1d;
	case 11807ULL: goto x86_l_2e1f;
	case 11809ULL: goto x86_l_2e21;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11829ULL: goto x86_l_2e35;
	case 11831ULL: goto x86_l_2e37;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11840ULL: goto x86_l_2e40;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11862ULL: goto x86_l_2e56;
	case 11864ULL: goto x86_l_2e58;
	case 11876ULL: goto x86_l_2e64;
	case 11888ULL: goto x86_l_2e70;
	case 11897ULL: goto x86_l_2e79;
	case 11906ULL: goto x86_l_2e82;
	case 11915ULL: goto x86_l_2e8b;
	case 11924ULL: goto x86_l_2e94;
	case 11933ULL: goto x86_l_2e9d;
	case 11942ULL: goto x86_l_2ea6;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11984ULL: goto x86_l_2ed0;
	case 11986ULL: goto x86_l_2ed2;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12006ULL: goto x86_l_2ee6;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12038ULL: goto x86_l_2f06;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12125ULL: goto x86_l_2f5d;
	case 12130ULL: goto x86_l_2f62;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12164ULL: goto x86_l_2f84;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12245ULL: goto x86_l_2fd5;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12261ULL: goto x86_l_2fe5;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12323ULL: goto x86_l_3023;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12335ULL: goto x86_l_302f;
	case 12340ULL: goto x86_l_3034;
	case 12348ULL: goto x86_l_303c;
	case 12353ULL: goto x86_l_3041;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12396ULL: goto x86_l_306c;
	case 12403ULL: goto x86_l_3073;
	case 12412ULL: goto x86_l_307c;
	case 12418ULL: goto x86_l_3082;
	case 12420ULL: goto x86_l_3084;
	case 12424ULL: goto x86_l_3088;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29f5:
	/* 0x29f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29fa:
	/* 0x29fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fc:
	/* 0x29fc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a01:
	/* 0x2a01: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a04:
	/* 0x2a04: je     2a7b <trace_ret_kernel_write_tail+0x2a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a7b;
	}
x86_l_2a06:
	/* 0x2a06: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a0b:
	/* 0x2a0b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a0e:
	/* 0x2a0e: je     2a7b <trace_ret_kernel_write_tail+0x2a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a7b;
	}
x86_l_2a10:
	/* 0x2a10: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a14:
	/* 0x2a14: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a19:
	/* 0x2a19: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a23:
	/* 0x2a23: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a28:
	/* 0x2a28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2a:
	/* 0x2a2a: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a2e:
	/* 0x2a2e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a30:
	/* 0x2a30: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a36:
	/* 0x2a36: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2a38:
	/* 0x2a38: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a3a:
	/* 0x2a3a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3f:
	/* 0x2a3f: jb     2d90 <trace_ret_kernel_write_tail+0x2d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d90;
	}
x86_l_2a45:
	/* 0x2a45: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a4a:
	/* 0x2a4a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a50:
	/* 0x2a50: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a53:
	/* 0x2a53: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2a55:
	/* 0x2a55: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a5a:
	/* 0x2a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5c:
	/* 0x2a5c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a5f:
	/* 0x2a5f: jl     2a89 <trace_ret_kernel_write_tail+0x2a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2a89;
	}
x86_l_2a61:
	/* 0x2a61: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a64:
	/* 0x2a64: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a6f:
	/* 0x2a6f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a71:
	/* 0x2a71: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a76:
	/* 0x2a76: jmp    2d02 <trace_ret_kernel_write_tail+0x2d02> */
	goto x86_l_2d02;
x86_l_2a7b:
	/* 0x2a7b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a7e:
	/* 0x2a7e: je     2c8a <trace_ret_kernel_write_tail+0x2c8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c8a;
	}
x86_l_2a84:
	/* 0x2a84: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a89:
	/* 0x2a89: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2a8f:
	/* 0x2a8f: jne    2d90 <trace_ret_kernel_write_tail+0x2d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d90;
	}
x86_l_2a95:
	/* 0x2a95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a9a:
	/* 0x2a9a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a9e:
	/* 0x2a9e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aad:
	/* 0x2aad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ab2:
	/* 0x2ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab4:
	/* 0x2ab4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2abe:
	/* 0x2abe: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2ac6:
	/* 0x2ac6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2acb:
	/* 0x2acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acd:
	/* 0x2acd: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2acf:
	/* 0x2acf: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2adc:
	/* 0x2adc: jmp    2dbf <trace_ret_kernel_write_tail+0x2dbf> */
	goto x86_l_2dbf;
x86_l_2ae1:
	/* 0x2ae1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ae3:
	/* 0x2ae3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ae8:
	/* 0x2ae8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2aed:
	/* 0x2aed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2af2:
	/* 0x2af2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af7:
	/* 0x2af7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afc:
	/* 0x2afc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2aff:
	/* 0x2aff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b01:
	/* 0x2b01: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b06:
	/* 0x2b06: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b1e:
	/* 0x2b1e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b22:
	/* 0x2b22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b27:
	/* 0x2b27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b29:
	/* 0x2b29: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2e:
	/* 0x2b2e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b31:
	/* 0x2b31: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2b36:
	/* 0x2b36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b40:
	/* 0x2b40: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b45:
	/* 0x2b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b47:
	/* 0x2b47: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b4e:
	/* 0x2b4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b53:
	/* 0x2b53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b58:
	/* 0x2b58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b62:
	/* 0x2b62: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2b65:
	/* 0x2b65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b67:
	/* 0x2b67: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6c:
	/* 0x2b6c: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b70:
	/* 0x2b70: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b75:
	/* 0x2b75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b7a:
	/* 0x2b7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b84:
	/* 0x2b84: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b88:
	/* 0x2b88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8d:
	/* 0x2b8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8f:
	/* 0x2b8f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b94:
	/* 0x2b94: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b99:
	/* 0x2b99: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2ba2:
	/* 0x2ba2: cmp    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2bab:
	/* 0x2bab: je     2bdf <trace_ret_kernel_write_tail+0x2bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bdf;
	}
x86_l_2bad:
	/* 0x2bad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2bb4:
	/* 0x2bb4: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bb9:
	/* 0x2bb9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bbe:
	/* 0x2bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc0:
	/* 0x2bc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bc3:
	/* 0x2bc3: je     249f <trace_ret_kernel_write_tail+0x249f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9375ULL;
	}
x86_l_2bc9:
	/* 0x2bc9: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bcc:
	/* 0x2bcc: je     249f <trace_ret_kernel_write_tail+0x249f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9375ULL;
	}
x86_l_2bd2:
	/* 0x2bd2: mov    BYTE PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_2bda:
	/* 0x2bda: jmp    249f <trace_ret_kernel_write_tail+0x249f> */
	return 9375ULL;
x86_l_2bdf:
	/* 0x2bdf: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2be8:
	/* 0x2be8: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2c03:
	/* 0x2c03: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c0b:
	/* 0x2c0b: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_2c0e:
	/* 0x2c0e: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_2c13:
	/* 0x2c13: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2c16:
	/* 0x2c16: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c20:
	/* 0x2c20: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2c28:
	/* 0x2c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2a:
	/* 0x2c2a: cmp    BYTE PTR [rsp+0x50],0x7f */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383807ULL);
x86_l_2c2f:
	/* 0x2c2f: jne    2c72 <trace_ret_kernel_write_tail+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c72;
	}
x86_l_2c31:
	/* 0x2c31: cmp    BYTE PTR [rsp+0x51],0x45 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 347892351045ULL);
x86_l_2c36:
	/* 0x2c36: jne    2c72 <trace_ret_kernel_write_tail+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c72;
	}
x86_l_2c38:
	/* 0x2c38: cmp    BYTE PTR [rsp+0x52],0x4c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 352187318348ULL);
x86_l_2c3d:
	/* 0x2c3d: jne    2c72 <trace_ret_kernel_write_tail+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c72;
	}
x86_l_2c3f:
	/* 0x2c3f: cmp    BYTE PTR [rsp+0x53],0x46 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285638ULL);
x86_l_2c44:
	/* 0x2c44: jne    2c72 <trace_ret_kernel_write_tail+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c72;
	}
x86_l_2c46:
	/* 0x2c46: mov    BYTE PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2c55:
	/* 0x2c55: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c57:
	/* 0x2c57: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c5c:
	/* 0x2c5c: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c64:
	/* 0x2c64: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c69:
	/* 0x2c69: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c6b:
	/* 0x2c6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6d:
	/* 0x2c6d: jmp    249f <trace_ret_kernel_write_tail+0x249f> */
	return 9375ULL;
x86_l_2c72:
	/* 0x2c72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2c79:
	/* 0x2c79: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c83:
	/* 0x2c83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c85:
	/* 0x2c85: jmp    249f <trace_ret_kernel_write_tail+0x249f> */
	return 9375ULL;
x86_l_2c8a:
	/* 0x2c8a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8e:
	/* 0x2c8e: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2c93:
	/* 0x2c93: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c98:
	/* 0x2c98: je     2a89 <trace_ret_kernel_write_tail+0x2a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a89;
	}
x86_l_2c9e:
	/* 0x2c9e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ca2:
	/* 0x2ca2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cac:
	/* 0x2cac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb1:
	/* 0x2cb1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb5:
	/* 0x2cb5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cbe:
	/* 0x2cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc0:
	/* 0x2cc0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc4:
	/* 0x2cc4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2cc7:
	/* 0x2cc7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cda:
	/* 0x2cda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdc:
	/* 0x2cdc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce0:
	/* 0x2ce0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ce5:
	/* 0x2ce5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cea:
	/* 0x2cea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cef:
	/* 0x2cef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf3:
	/* 0x2cf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf8:
	/* 0x2cf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cfa:
	/* 0x2cfa: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfe:
	/* 0x2cfe: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d02:
	/* 0x2d02: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d07:
	/* 0x2d07: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d0c:
	/* 0x2d0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d11:
	/* 0x2d11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d16:
	/* 0x2d16: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d19:
	/* 0x2d19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1b:
	/* 0x2d1b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d20:
	/* 0x2d20: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d25:
	/* 0x2d25: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d29:
	/* 0x2d29: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d33:
	/* 0x2d33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d38:
	/* 0x2d38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d3d:
	/* 0x2d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3f:
	/* 0x2d3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d44:
	/* 0x2d44: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d47:
	/* 0x2d47: je     30e5 <trace_ret_kernel_write_tail+0x30e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12517ULL;
	}
x86_l_2d4d:
	/* 0x2d4d: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d52:
	/* 0x2d52: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d55:
	/* 0x2d55: je     30e5 <trace_ret_kernel_write_tail+0x30e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12517ULL;
	}
x86_l_2d5b:
	/* 0x2d5b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d5f:
	/* 0x2d5f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d64:
	/* 0x2d64: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d69:
	/* 0x2d69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d6e:
	/* 0x2d6e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d73:
	/* 0x2d73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d75:
	/* 0x2d75: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d79:
	/* 0x2d79: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d7b:
	/* 0x2d7b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d81:
	/* 0x2d81: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2d83:
	/* 0x2d83: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d85:
	/* 0x2d85: jae    3163 <trace_ret_kernel_write_tail+0x3163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12643ULL;
	}
x86_l_2d8b:
	/* 0x2d8b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d90:
	/* 0x2d90: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2d92:
	/* 0x2d92: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2d94:
	/* 0x2d94: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d99:
	/* 0x2d99: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    BYTE PTR [r14+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_2da6:
	/* 0x2da6: cmp    ebx,0x7000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 28672ULL);
x86_l_2dac:
	/* 0x2dac: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2db4:
	/* 0x2db4: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2db9:
	/* 0x2db9: jae    2e56 <trace_ret_kernel_write_tail+0x2e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e56;
	}
x86_l_2dbf:
	/* 0x2dbf: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2dc5:
	/* 0x2dc5: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dc8:
	/* 0x2dc8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_2dcf:
	/* 0x2dcf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dd1:
	/* 0x2dd1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dd6:
	/* 0x2dd6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ddb:
	/* 0x2ddb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2dde:
	/* 0x2dde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de0:
	/* 0x2de0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de2:
	/* 0x2de2: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2de6:
	/* 0x2de6: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_2de8:
	/* 0x2de8: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_2dea:
	/* 0x2dea: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2dec:
	/* 0x2dec: movzx  eax,BYTE PTR [r14+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_2df1:
	/* 0x2df1: mov    cl,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 100ULL);
x86_l_2df3:
	/* 0x2df3: cmp    al,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 100ULL);
x86_l_2df5:
	/* 0x2df5: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2df7:
	/* 0x2df7: movzx  eax,BYTE PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    cl,0x65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 101ULL);
x86_l_2dfe:
	/* 0x2dfe: cmp    al,0x65 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 101ULL);
x86_l_2e00:
	/* 0x2e00: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e02:
	/* 0x2e02: movzx  eax,BYTE PTR [r14+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_2e07:
	/* 0x2e07: mov    cl,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 118ULL);
x86_l_2e09:
	/* 0x2e09: cmp    al,0x76 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 118ULL);
x86_l_2e0b:
	/* 0x2e0b: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e0d:
	/* 0x2e0d: movzx  eax,BYTE PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_2e12:
	/* 0x2e12: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_2e14:
	/* 0x2e14: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_2e16:
	/* 0x2e16: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e18:
	/* 0x2e18: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    cl,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 110ULL);
x86_l_2e1f:
	/* 0x2e1f: cmp    al,0x6e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 110ULL);
x86_l_2e21:
	/* 0x2e21: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e23:
	/* 0x2e23: movzx  eax,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e28:
	/* 0x2e28: mov    cl,0x75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 117ULL);
x86_l_2e2a:
	/* 0x2e2a: cmp    al,0x75 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 117ULL);
x86_l_2e2c:
	/* 0x2e2c: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e2e:
	/* 0x2e2e: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e33:
	/* 0x2e33: mov    cl,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 108ULL);
x86_l_2e35:
	/* 0x2e35: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_2e37:
	/* 0x2e37: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e39:
	/* 0x2e39: movzx  eax,BYTE PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2e3e:
	/* 0x2e3e: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_2e40:
	/* 0x2e40: jne    2e49 <trace_ret_kernel_write_tail+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e49;
	}
x86_l_2e42:
	/* 0x2e42: movzx  eax,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2e47:
	/* 0x2e47: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e49:
	/* 0x2e49: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e4b:
	/* 0x2e4b: cmp    cl,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_2e4d:
	/* 0x2e4d: jne    2e58 <trace_ret_kernel_write_tail+0x2e58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e58;
	}
x86_l_2e4f:
	/* 0x2e4f: mov    ebx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e54:
	/* 0x2e54: jmp    2e58 <trace_ret_kernel_write_tail+0x2e58> */
	goto x86_l_2e58;
x86_l_2e56:
	/* 0x2e56: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e58:
	/* 0x2e58: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2e64:
	/* 0x2e64: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2e70:
	/* 0x2e70: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2e79:
	/* 0x2e79: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2e82:
	/* 0x2e82: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2e94:
	/* 0x2e94: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    r14,QWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2eaa:
	/* 0x2eaa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec6:
	/* 0x2ec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec8:
	/* 0x2ec8: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ecd:
	/* 0x2ecd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ed0:
	/* 0x2ed0: je     2eda <trace_ret_kernel_write_tail+0x2eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eda;
	}
x86_l_2ed2:
	/* 0x2ed2: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ed5:
	/* 0x2ed5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eda:
	/* 0x2eda: mov    BYTE PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_2edf:
	/* 0x2edf: mov    DWORD PTR [rsp+0xa8],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2ee6:
	/* 0x2ee6: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2eea:
	/* 0x2eea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eef:
	/* 0x2eef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ef9:
	/* 0x2ef9: lea    r14,[rsp+0x51] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2efe:
	/* 0x2efe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f03:
	/* 0x2f03: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2f06:
	/* 0x2f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f08:
	/* 0x2f08: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f0d:
	/* 0x2f0d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f11:
	/* 0x2f11: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f16:
	/* 0x2f16: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f1b:
	/* 0x2f1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f20:
	/* 0x2f20: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f25:
	/* 0x2f25: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f29:
	/* 0x2f29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f2e:
	/* 0x2f2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f30:
	/* 0x2f30: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f35:
	/* 0x2f35: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f38:
	/* 0x2f38: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f42:
	/* 0x2f42: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f47:
	/* 0x2f47: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f4c:
	/* 0x2f4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4e:
	/* 0x2f4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f53:
	/* 0x2f53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f58:
	/* 0x2f58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f5d:
	/* 0x2f5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f62:
	/* 0x2f62: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2f65:
	/* 0x2f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f67:
	/* 0x2f67: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6c:
	/* 0x2f6c: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f70:
	/* 0x2f70: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f75:
	/* 0x2f75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f7f:
	/* 0x2f7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f84:
	/* 0x2f84: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f88:
	/* 0x2f88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8d:
	/* 0x2f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8f:
	/* 0x2f8f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f94:
	/* 0x2f94: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f99:
	/* 0x2f99: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f9e:
	/* 0x2f9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fa3:
	/* 0x2fa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fad:
	/* 0x2fad: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2fb0:
	/* 0x2fb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb2:
	/* 0x2fb2: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fb7:
	/* 0x2fb7: lea    rdi,[rsp+0xae] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 174ULL);
x86_l_2fbf:
	/* 0x2fbf: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fc4:
	/* 0x2fc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fce:
	/* 0x2fce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2fd3:
	/* 0x2fd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd5:
	/* 0x2fd5: movzx  eax,WORD PTR [rsp+0xae] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 174ULL);
x86_l_2fdd:
	/* 0x2fdd: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fe2:
	/* 0x2fe2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2fe5:
	/* 0x2fe5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2fea:
	/* 0x2fea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fef:
	/* 0x2fef: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2ff2:
	/* 0x2ff2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ff7:
	/* 0x2ff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff9:
	/* 0x2ff9: lea    rdi,[rsp+0x55] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2ffe:
	/* 0x2ffe: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x3014: lea    rdi,[rsp+0x5d] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_3019:
	/* 0x3019: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_301e:
	/* 0x301e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3023:
	/* 0x3023: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3028:
	/* 0x3028: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_302d:
	/* 0x302d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302f:
	/* 0x302f: lea    rdi,[rsp+0x61] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_3034:
	/* 0x3034: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_303c:
	/* 0x303c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3041:
	/* 0x3041: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3046:
	/* 0x3046: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_304b:
	/* 0x304b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_304d:
	/* 0x304d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3052:
	/* 0x3052: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3057:
	/* 0x3057: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_305f:
	/* 0x305f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3064:
	/* 0x3064: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_306c:
	/* 0x306c: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3073:
	/* 0x3073: movzx  eax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_307c:
	/* 0x307c: cmp    rax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31935ULL);
x86_l_3082:
	/* 0x3082: ja     30d4 <trace_ret_kernel_write_tail+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12500ULL;
	}
x86_l_3084:
	/* 0x3084: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3088:
	/* 0x3088: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_308f:
	/* 0x308f: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3094:
	/* 0x3094: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
	return 12441ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12455ULL: goto x86_l_30a7;
	case 12459ULL: goto x86_l_30ab;
	case 12466ULL: goto x86_l_30b2;
	case 12471ULL: goto x86_l_30b7;
	case 12473ULL: goto x86_l_30b9;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12490ULL: goto x86_l_30ca;
	case 12493ULL: goto x86_l_30cd;
	case 12498ULL: goto x86_l_30d2;
	case 12500ULL: goto x86_l_30d4;
	case 12502ULL: goto x86_l_30d6;
	case 12509ULL: goto x86_l_30dd;
	case 12511ULL: goto x86_l_30df;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12520ULL: goto x86_l_30e8;
	case 12526ULL: goto x86_l_30ee;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12541ULL: goto x86_l_30fd;
	case 12545ULL: goto x86_l_3101;
	case 12550ULL: goto x86_l_3106;
	case 12555ULL: goto x86_l_310b;
	case 12560ULL: goto x86_l_3110;
	case 12564ULL: goto x86_l_3114;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12575ULL: goto x86_l_311f;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12603ULL: goto x86_l_313b;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12633ULL: goto x86_l_3159;
	case 12637ULL: goto x86_l_315d;
	case 12641ULL: goto x86_l_3161;
	case 12643ULL: goto x86_l_3163;
	case 12648ULL: goto x86_l_3168;
	case 12654ULL: goto x86_l_316e;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12666ULL: goto x86_l_317a;
	case 12669ULL: goto x86_l_317d;
	case 12675ULL: goto x86_l_3183;
	case 12678ULL: goto x86_l_3186;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12719ULL: goto x86_l_31af;
	case 12721ULL: goto x86_l_31b1;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12765ULL: goto x86_l_31dd;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12789ULL: goto x86_l_31f5;
	case 12794ULL: goto x86_l_31fa;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12815ULL: goto x86_l_320f;
	case 12817ULL: goto x86_l_3211;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12844ULL: goto x86_l_322c;
	case 12847ULL: goto x86_l_322f;
	case 12849ULL: goto x86_l_3231;
	case 12854ULL: goto x86_l_3236;
	case 12856ULL: goto x86_l_3238;
	case 12859ULL: goto x86_l_323b;
	case 12865ULL: goto x86_l_3241;
	case 12868ULL: goto x86_l_3244;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12891ULL: goto x86_l_325b;
	case 12894ULL: goto x86_l_325e;
	case 12900ULL: goto x86_l_3264;
	case 12904ULL: goto x86_l_3268;
	case 12909ULL: goto x86_l_326d;
	case 12915ULL: goto x86_l_3273;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12929ULL: goto x86_l_3281;
	case 12934ULL: goto x86_l_3286;
	case 12938ULL: goto x86_l_328a;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12949ULL: goto x86_l_3295;
	case 12953ULL: goto x86_l_3299;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12977ULL: goto x86_l_32b1;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12996ULL: goto x86_l_32c4;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13007ULL: goto x86_l_32cf;
	case 13011ULL: goto x86_l_32d3;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13025ULL: goto x86_l_32e1;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13047ULL: goto x86_l_32f7;
	case 13052ULL: goto x86_l_32fc;
	case 13057ULL: goto x86_l_3301;
	case 13061ULL: goto x86_l_3305;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13083ULL: goto x86_l_331b;
	case 13088ULL: goto x86_l_3320;
	case 13091ULL: goto x86_l_3323;
	case 13097ULL: goto x86_l_3329;
	case 13102ULL: goto x86_l_332e;
	case 13105ULL: goto x86_l_3331;
	case 13111ULL: goto x86_l_3337;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13141ULL: goto x86_l_3355;
	case 13143ULL: goto x86_l_3357;
	case 13149ULL: goto x86_l_335d;
	case 13152ULL: goto x86_l_3360;
	case 13154ULL: goto x86_l_3362;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13173ULL: goto x86_l_3375;
	case 13179ULL: goto x86_l_337b;
	case 13183ULL: goto x86_l_337f;
	case 13188ULL: goto x86_l_3384;
	case 13194ULL: goto x86_l_338a;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13217ULL: goto x86_l_33a1;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13232ULL: goto x86_l_33b0;
	case 13235ULL: goto x86_l_33b3;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13279ULL: goto x86_l_33df;
	case 13284ULL: goto x86_l_33e4;
	case 13286ULL: goto x86_l_33e6;
	case 13290ULL: goto x86_l_33ea;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13317ULL: goto x86_l_3405;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13363ULL: goto x86_l_3433;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13377ULL: goto x86_l_3441;
	case 13383ULL: goto x86_l_3447;
	case 13387ULL: goto x86_l_344b;
	case 13392ULL: goto x86_l_3450;
	case 13397ULL: goto x86_l_3455;
	case 13402ULL: goto x86_l_345a;
	case 13407ULL: goto x86_l_345f;
	case 13409ULL: goto x86_l_3461;
	case 13413ULL: goto x86_l_3465;
	case 13415ULL: goto x86_l_3467;
	case 13421ULL: goto x86_l_346d;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13431ULL: goto x86_l_3477;
	case 13436ULL: goto x86_l_347c;
	case 13442ULL: goto x86_l_3482;
	case 13445ULL: goto x86_l_3485;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13454ULL: goto x86_l_348e;
	case 13457ULL: goto x86_l_3491;
	case 13463ULL: goto x86_l_3497;
	case 13466ULL: goto x86_l_349a;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13479ULL: goto x86_l_34a7;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13492ULL: goto x86_l_34b4;
	case 13498ULL: goto x86_l_34ba;
	case 13506ULL: goto x86_l_34c2;
	case 13513ULL: goto x86_l_34c9;
	case 13518ULL: goto x86_l_34ce;
	case 13523ULL: goto x86_l_34d3;
	case 13525ULL: goto x86_l_34d5;
	case 13528ULL: goto x86_l_34d8;
	case 13534ULL: goto x86_l_34de;
	case 13537ULL: goto x86_l_34e1;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13554ULL: goto x86_l_34f2;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13573ULL: goto x86_l_3505;
	case 13581ULL: goto x86_l_350d;
	case 13584ULL: goto x86_l_3510;
	case 13588ULL: goto x86_l_3514;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13619ULL: goto x86_l_3533;
	case 13628ULL: goto x86_l_353c;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13663ULL: goto x86_l_355f;
	case 13665ULL: goto x86_l_3561;
	case 13668ULL: goto x86_l_3564;
	case 13674ULL: goto x86_l_356a;
	case 13677ULL: goto x86_l_356d;
	case 13681ULL: goto x86_l_3571;
	case 13683ULL: goto x86_l_3573;
	case 13688ULL: goto x86_l_3578;
	case 13692ULL: goto x86_l_357c;
	case 13695ULL: goto x86_l_357f;
	case 13701ULL: goto x86_l_3585;
	case 13703ULL: goto x86_l_3587;
	case 13706ULL: goto x86_l_358a;
	case 13710ULL: goto x86_l_358e;
	case 13717ULL: goto x86_l_3595;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13751ULL: goto x86_l_35b7;
	case 13754ULL: goto x86_l_35ba;
	case 13756ULL: goto x86_l_35bc;
	case 13763ULL: goto x86_l_35c3;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13784ULL: goto x86_l_35d8;
	case 13790ULL: goto x86_l_35de;
	case 13798ULL: goto x86_l_35e6;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13815ULL: goto x86_l_35f7;
	case 13817ULL: goto x86_l_35f9;
	case 13820ULL: goto x86_l_35fc;
	case 13826ULL: goto x86_l_3602;
	case 13829ULL: goto x86_l_3605;
	case 13839ULL: goto x86_l_360f;
	case 13842ULL: goto x86_l_3612;
	case 13846ULL: goto x86_l_3616;
	case 13854ULL: goto x86_l_361e;
	case 13859ULL: goto x86_l_3623;
	case 13861ULL: goto x86_l_3625;
	case 13865ULL: goto x86_l_3629;
	case 13873ULL: goto x86_l_3631;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13887ULL: goto x86_l_363f;
	case 13892ULL: goto x86_l_3644;
	case 13897ULL: goto x86_l_3649;
	case 13902ULL: goto x86_l_364e;
	case 13911ULL: goto x86_l_3657;
	case 13920ULL: goto x86_l_3660;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13955ULL: goto x86_l_3683;
	case 13957ULL: goto x86_l_3685;
	case 13960ULL: goto x86_l_3688;
	case 13966ULL: goto x86_l_368e;
	case 13969ULL: goto x86_l_3691;
	case 13973ULL: goto x86_l_3695;
	case 13975ULL: goto x86_l_3697;
	case 13980ULL: goto x86_l_369c;
	case 13984ULL: goto x86_l_36a0;
	case 13987ULL: goto x86_l_36a3;
	case 13993ULL: goto x86_l_36a9;
	case 13995ULL: goto x86_l_36ab;
	case 13998ULL: goto x86_l_36ae;
	case 14002ULL: goto x86_l_36b2;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14032ULL: goto x86_l_36d0;
	case 14037ULL: goto x86_l_36d5;
	case 14043ULL: goto x86_l_36db;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14055ULL: goto x86_l_36e7;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14078ULL: goto x86_l_36fe;
	case 14081ULL: goto x86_l_3701;
	case 14087ULL: goto x86_l_3707;
	case 14091ULL: goto x86_l_370b;
	case 14096ULL: goto x86_l_3710;
	case 14102ULL: goto x86_l_3716;
	case 14106ULL: goto x86_l_371a;
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14121ULL: goto x86_l_3729;
	case 14125ULL: goto x86_l_372d;
	case 14129ULL: goto x86_l_3731;
	case 14134ULL: goto x86_l_3736;
	case 14136ULL: goto x86_l_3738;
	case 14140ULL: goto x86_l_373c;
	case 14143ULL: goto x86_l_373f;
	case 14148ULL: goto x86_l_3744;
	case 14153ULL: goto x86_l_3749;
	case 14157ULL: goto x86_l_374d;
	case 14162ULL: goto x86_l_3752;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3099:
	/* 0x3099: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_309e:
	/* 0x309e: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30a7:
	/* 0x30a7: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30ab:
	/* 0x30ab: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30b2:
	/* 0x30b2: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_30b7:
	/* 0x30b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b9:
	/* 0x30b9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_30c0:
	/* 0x30c0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_30c5:
	/* 0x30c5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_30ca:
	/* 0x30ca: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_30cd:
	/* 0x30cd: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_30d2:
	/* 0x30d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d4:
	/* 0x30d4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d6:
	/* 0x30d6: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_30dd:
	/* 0x30dd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_30df:
	/* 0x30df: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_30e0:
	/* 0x30e0: jmp    604d <.L.str.5+0x603d> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_30e5:
	/* 0x30e5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_30e8:
	/* 0x30e8: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_30ee:
	/* 0x30ee: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f2:
	/* 0x30f2: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_30f7:
	/* 0x30f7: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_30fd:
	/* 0x30fd: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3101:
	/* 0x3101: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3106:
	/* 0x3106: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_310b:
	/* 0x310b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3110:
	/* 0x3110: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3114:
	/* 0x3114: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3118:
	/* 0x3118: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_311d:
	/* 0x311d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311f:
	/* 0x311f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3123:
	/* 0x3123: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3126:
	/* 0x3126: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_312b:
	/* 0x312b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3130:
	/* 0x3130: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3134:
	/* 0x3134: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3139:
	/* 0x3139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313b:
	/* 0x313b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_313f:
	/* 0x313f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3144:
	/* 0x3144: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3149:
	/* 0x3149: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_314e:
	/* 0x314e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3152:
	/* 0x3152: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3157:
	/* 0x3157: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3159:
	/* 0x3159: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_315d:
	/* 0x315d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3161:
	/* 0x3161: jmp    3198 <trace_ret_kernel_write_tail+0x3198> */
	goto x86_l_3198;
x86_l_3163:
	/* 0x3163: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3168:
	/* 0x3168: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_316e:
	/* 0x316e: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3171:
	/* 0x3171: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3173:
	/* 0x3173: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3178:
	/* 0x3178: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317a:
	/* 0x317a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_317d:
	/* 0x317d: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_3183:
	/* 0x3183: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3186:
	/* 0x3186: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_318c:
	/* 0x318c: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3191:
	/* 0x3191: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3193:
	/* 0x3193: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3198:
	/* 0x3198: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_319d:
	/* 0x319d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a2:
	/* 0x31a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a7:
	/* 0x31a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ac:
	/* 0x31ac: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_31af:
	/* 0x31af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b1:
	/* 0x31b1: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31b6:
	/* 0x31b6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31bb:
	/* 0x31bb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31bf:
	/* 0x31bf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31c4:
	/* 0x31c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31c9:
	/* 0x31c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31ce:
	/* 0x31ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d3:
	/* 0x31d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d5:
	/* 0x31d5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31da:
	/* 0x31da: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31dd:
	/* 0x31dd: je     3372 <trace_ret_kernel_write_tail+0x3372> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3372;
	}
x86_l_31e3:
	/* 0x31e3: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31e8:
	/* 0x31e8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31eb:
	/* 0x31eb: je     3372 <trace_ret_kernel_write_tail+0x3372> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3372;
	}
x86_l_31f1:
	/* 0x31f1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31f5:
	/* 0x31f5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31fa:
	/* 0x31fa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31ff:
	/* 0x31ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3204:
	/* 0x3204: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3209:
	/* 0x3209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320b:
	/* 0x320b: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_320f:
	/* 0x320f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3211:
	/* 0x3211: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3217:
	/* 0x3217: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3219:
	/* 0x3219: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_321b:
	/* 0x321b: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_3221:
	/* 0x3221: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3226:
	/* 0x3226: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_322c:
	/* 0x322c: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_322f:
	/* 0x322f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3231:
	/* 0x3231: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3236:
	/* 0x3236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3238:
	/* 0x3238: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_323b:
	/* 0x323b: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_3241:
	/* 0x3241: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3244:
	/* 0x3244: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_324a:
	/* 0x324a: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_324f:
	/* 0x324f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3251:
	/* 0x3251: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3256:
	/* 0x3256: jmp    33ee <trace_ret_kernel_write_tail+0x33ee> */
	goto x86_l_33ee;
x86_l_325b:
	/* 0x325b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_325e:
	/* 0x325e: jne    1b43 <trace_ret_kernel_write_tail+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6979ULL;
	}
x86_l_3264:
	/* 0x3264: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3268:
	/* 0x3268: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_326d:
	/* 0x326d: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_3273:
	/* 0x3273: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3277:
	/* 0x3277: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327c:
	/* 0x327c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3281:
	/* 0x3281: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3286:
	/* 0x3286: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328a:
	/* 0x328a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_328e:
	/* 0x328e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3293:
	/* 0x3293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3295:
	/* 0x3295: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3299:
	/* 0x3299: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_329c:
	/* 0x329c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32a1:
	/* 0x32a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32a6:
	/* 0x32a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32aa:
	/* 0x32aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32af:
	/* 0x32af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b1:
	/* 0x32b1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b5:
	/* 0x32b5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ba:
	/* 0x32ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32bf:
	/* 0x32bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32c4:
	/* 0x32c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c8:
	/* 0x32c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32cd:
	/* 0x32cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cf:
	/* 0x32cf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d3:
	/* 0x32d3: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32d7:
	/* 0x32d7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32dc:
	/* 0x32dc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32e1:
	/* 0x32e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32e6:
	/* 0x32e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32eb:
	/* 0x32eb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32f0:
	/* 0x32f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f5:
	/* 0x32f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f7:
	/* 0x32f7: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32fc:
	/* 0x32fc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3301:
	/* 0x3301: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3305:
	/* 0x3305: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_330a:
	/* 0x330a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_330f:
	/* 0x330f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3314:
	/* 0x3314: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3319:
	/* 0x3319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331b:
	/* 0x331b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3320:
	/* 0x3320: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3323:
	/* 0x3323: je     36fe <trace_ret_kernel_write_tail+0x36fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36fe;
	}
x86_l_3329:
	/* 0x3329: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_332e:
	/* 0x332e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3331:
	/* 0x3331: je     36fe <trace_ret_kernel_write_tail+0x36fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36fe;
	}
x86_l_3337:
	/* 0x3337: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_333b:
	/* 0x333b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3340:
	/* 0x3340: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3345:
	/* 0x3345: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_334a:
	/* 0x334a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_334f:
	/* 0x334f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3351:
	/* 0x3351: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3355:
	/* 0x3355: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3357:
	/* 0x3357: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_335d:
	/* 0x335d: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3360:
	/* 0x3360: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3362:
	/* 0x3362: jae    39f3 <trace_ret_kernel_write_tail+0x39f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14835ULL;
	}
x86_l_3368:
	/* 0x3368: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_336d:
	/* 0x336d: jmp    1dd2 <trace_ret_kernel_write_tail+0x1dd2> */
	return 7634ULL;
x86_l_3372:
	/* 0x3372: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3375:
	/* 0x3375: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_337b:
	/* 0x337b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337f:
	/* 0x337f: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3384:
	/* 0x3384: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_338a:
	/* 0x338a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_338e:
	/* 0x338e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3393:
	/* 0x3393: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3398:
	/* 0x3398: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_339d:
	/* 0x339d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a1:
	/* 0x33a1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33a5:
	/* 0x33a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33aa:
	/* 0x33aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ac:
	/* 0x33ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b0:
	/* 0x33b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33b3:
	/* 0x33b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33b8:
	/* 0x33b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33bd:
	/* 0x33bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c1:
	/* 0x33c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c6:
	/* 0x33c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c8:
	/* 0x33c8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33cc:
	/* 0x33cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33d1:
	/* 0x33d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33d6:
	/* 0x33d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33db:
	/* 0x33db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33df:
	/* 0x33df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e4:
	/* 0x33e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e6:
	/* 0x33e6: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ea:
	/* 0x33ea: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33ee:
	/* 0x33ee: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33f3:
	/* 0x33f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33f8:
	/* 0x33f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33fd:
	/* 0x33fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3402:
	/* 0x3402: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3405:
	/* 0x3405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3407:
	/* 0x3407: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340c:
	/* 0x340c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3411:
	/* 0x3411: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3415:
	/* 0x3415: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_341a:
	/* 0x341a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_341f:
	/* 0x341f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3424:
	/* 0x3424: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3429:
	/* 0x3429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342b:
	/* 0x342b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3430:
	/* 0x3430: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3433:
	/* 0x3433: je     3784 <trace_ret_kernel_write_tail+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_3439:
	/* 0x3439: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_343e:
	/* 0x343e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3441:
	/* 0x3441: je     3784 <trace_ret_kernel_write_tail+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_3447:
	/* 0x3447: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_344b:
	/* 0x344b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3450:
	/* 0x3450: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3455:
	/* 0x3455: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_345a:
	/* 0x345a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_345f:
	/* 0x345f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3461:
	/* 0x3461: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3465:
	/* 0x3465: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3467:
	/* 0x3467: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_346d:
	/* 0x346d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_346f:
	/* 0x346f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3471:
	/* 0x3471: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_3477:
	/* 0x3477: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_347c:
	/* 0x347c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3482:
	/* 0x3482: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3485:
	/* 0x3485: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3487:
	/* 0x3487: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_348c:
	/* 0x348c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_348e:
	/* 0x348e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3491:
	/* 0x3491: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_3497:
	/* 0x3497: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_349a:
	/* 0x349a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34a0:
	/* 0x34a0: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34a5:
	/* 0x34a5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34a7:
	/* 0x34a7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34ac:
	/* 0x34ac: jmp    3800 <trace_ret_kernel_write_tail+0x3800> */
	return 14336ULL;
x86_l_34b1:
	/* 0x34b1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_34b4:
	/* 0x34b4: je     35c3 <trace_ret_kernel_write_tail+0x35c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c3;
	}
x86_l_34ba:
	/* 0x34ba: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_34c2:
	/* 0x34c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_34c9:
	/* 0x34c9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34ce:
	/* 0x34ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34d3:
	/* 0x34d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d5:
	/* 0x34d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34d8:
	/* 0x34d8: je     35c3 <trace_ret_kernel_write_tail+0x35c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c3;
	}
x86_l_34de:
	/* 0x34de: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34e1:
	/* 0x34e1: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_34eb:
	/* 0x34eb: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ee:
	/* 0x34ee: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34f2:
	/* 0x34f2: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34fa:
	/* 0x34fa: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_34ff:
	/* 0x34ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3501:
	/* 0x3501: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3505:
	/* 0x3505: mov    DWORD PTR [r14+0x1c],0x58 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084376ULL);
x86_l_350d:
	/* 0x350d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3510:
	/* 0x3510: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3514:
	/* 0x3514: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_351b:
	/* 0x351b: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_3520:
	/* 0x3520: call   3525 <trace_ret_kernel_write_tail+0x3525> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_3525:
	/* 0x3525: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_352a:
	/* 0x352a: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3533:
	/* 0x3533: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_353c:
	/* 0x353c: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_3544:
	/* 0x3544: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3549:
	/* 0x3549: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354b:
	/* 0x354b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3550:
	/* 0x3550: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3557:
	/* 0x3557: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_355c:
	/* 0x355c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_355f:
	/* 0x355f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3561:
	/* 0x3561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3564:
	/* 0x3564: je     47f1 <trace_ret_kernel_write_tail+0x47f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18417ULL;
	}
x86_l_356a:
	/* 0x356a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_356d:
	/* 0x356d: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3571:
	/* 0x3571: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3573:
	/* 0x3573: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3578:
	/* 0x3578: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_357c:
	/* 0x357c: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_357f:
	/* 0x357f: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_3585:
	/* 0x3585: jb     35c3 <trace_ret_kernel_write_tail+0x35c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_35c3;
	}
x86_l_3587:
	/* 0x3587: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_358a:
	/* 0x358a: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_358e:
	/* 0x358e: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_3595:
	/* 0x3595: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_359a:
	/* 0x359a: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_359f:
	/* 0x359f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_35a4:
	/* 0x35a4: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_35ac:
	/* 0x35ac: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_35b1:
	/* 0x35b1: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_35b7:
	/* 0x35b7: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_35ba:
	/* 0x35ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35bc:
	/* 0x35bc: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c3:
	/* 0x35c3: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_35cb:
	/* 0x35cb: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35d0:
	/* 0x35d0: jmp    2327 <trace_ret_kernel_write_tail+0x2327> */
	return 8999ULL;
x86_l_35d5:
	/* 0x35d5: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_35d8:
	/* 0x35d8: je     24ed <trace_ret_kernel_write_tail+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9453ULL;
	}
x86_l_35de:
	/* 0x35de: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_35e6:
	/* 0x35e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_35ed:
	/* 0x35ed: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35f2:
	/* 0x35f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35f7:
	/* 0x35f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f9:
	/* 0x35f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35fc:
	/* 0x35fc: je     36e7 <trace_ret_kernel_write_tail+0x36e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e7;
	}
x86_l_3602:
	/* 0x3602: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3605:
	/* 0x3605: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_360f:
	/* 0x360f: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3612:
	/* 0x3612: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3616:
	/* 0x3616: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_361e:
	/* 0x361e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3623:
	/* 0x3623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3625:
	/* 0x3625: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3629:
	/* 0x3629: mov    DWORD PTR [r14+0x1c],0x9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084443ULL);
x86_l_3631:
	/* 0x3631: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3634:
	/* 0x3634: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3638:
	/* 0x3638: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_363f:
	/* 0x363f: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_3644:
	/* 0x3644: call   3649 <trace_ret_kernel_write_tail+0x3649> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_3649:
	/* 0x3649: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_364e:
	/* 0x364e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3657:
	/* 0x3657: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3660:
	/* 0x3660: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_3668:
	/* 0x3668: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_366d:
	/* 0x366d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366f:
	/* 0x366f: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3674:
	/* 0x3674: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_367b:
	/* 0x367b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3680:
	/* 0x3680: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3683:
	/* 0x3683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3685:
	/* 0x3685: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3688:
	/* 0x3688: je     4827 <trace_ret_kernel_write_tail+0x4827> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18471ULL;
	}
x86_l_368e:
	/* 0x368e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3691:
	/* 0x3691: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3695:
	/* 0x3695: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3697:
	/* 0x3697: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_369c:
	/* 0x369c: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a0:
	/* 0x36a0: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36a3:
	/* 0x36a3: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_36a9:
	/* 0x36a9: jb     36e7 <trace_ret_kernel_write_tail+0x36e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36e7;
	}
x86_l_36ab:
	/* 0x36ab: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36ae:
	/* 0x36ae: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36b2:
	/* 0x36b2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_36b9:
	/* 0x36b9: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_36be:
	/* 0x36be: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_36c3:
	/* 0x36c3: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_36c8:
	/* 0x36c8: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_36d0:
	/* 0x36d0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_36d5:
	/* 0x36d5: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_36db:
	/* 0x36db: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_36de:
	/* 0x36de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36e0:
	/* 0x36e0: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e7:
	/* 0x36e7: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_36ef:
	/* 0x36ef: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36f4:
	/* 0x36f4: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36f9:
	/* 0x36f9: jmp    24ed <trace_ret_kernel_write_tail+0x24ed> */
	return 9453ULL;
x86_l_36fe:
	/* 0x36fe: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3701:
	/* 0x3701: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_3707:
	/* 0x3707: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_370b:
	/* 0x370b: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3710:
	/* 0x3710: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_3716:
	/* 0x3716: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_371a:
	/* 0x371a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_371f:
	/* 0x371f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3724:
	/* 0x3724: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3729:
	/* 0x3729: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_372d:
	/* 0x372d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3731:
	/* 0x3731: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3736:
	/* 0x3736: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3738:
	/* 0x3738: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_373c:
	/* 0x373c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_373f:
	/* 0x373f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3744:
	/* 0x3744: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3749:
	/* 0x3749: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_374d:
	/* 0x374d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3752:
	/* 0x3752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 14164ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14164ULL: goto x86_l_3754;
	case 14168ULL: goto x86_l_3758;
	case 14173ULL: goto x86_l_375d;
	case 14178ULL: goto x86_l_3762;
	case 14183ULL: goto x86_l_3767;
	case 14187ULL: goto x86_l_376b;
	case 14192ULL: goto x86_l_3770;
	case 14194ULL: goto x86_l_3772;
	case 14198ULL: goto x86_l_3776;
	case 14202ULL: goto x86_l_377a;
	case 14207ULL: goto x86_l_377f;
	case 14212ULL: goto x86_l_3784;
	case 14215ULL: goto x86_l_3787;
	case 14221ULL: goto x86_l_378d;
	case 14225ULL: goto x86_l_3791;
	case 14230ULL: goto x86_l_3796;
	case 14236ULL: goto x86_l_379c;
	case 14240ULL: goto x86_l_37a0;
	case 14245ULL: goto x86_l_37a5;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14259ULL: goto x86_l_37b3;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14274ULL: goto x86_l_37c2;
	case 14277ULL: goto x86_l_37c5;
	case 14282ULL: goto x86_l_37ca;
	case 14287ULL: goto x86_l_37cf;
	case 14291ULL: goto x86_l_37d3;
	case 14296ULL: goto x86_l_37d8;
	case 14298ULL: goto x86_l_37da;
	case 14302ULL: goto x86_l_37de;
	case 14307ULL: goto x86_l_37e3;
	case 14312ULL: goto x86_l_37e8;
	case 14317ULL: goto x86_l_37ed;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14328ULL: goto x86_l_37f8;
	case 14332ULL: goto x86_l_37fc;
	case 14336ULL: goto x86_l_3800;
	case 14341ULL: goto x86_l_3805;
	case 14346ULL: goto x86_l_380a;
	case 14351ULL: goto x86_l_380f;
	case 14356ULL: goto x86_l_3814;
	case 14359ULL: goto x86_l_3817;
	case 14361ULL: goto x86_l_3819;
	case 14366ULL: goto x86_l_381e;
	case 14371ULL: goto x86_l_3823;
	case 14375ULL: goto x86_l_3827;
	case 14380ULL: goto x86_l_382c;
	case 14385ULL: goto x86_l_3831;
	case 14390ULL: goto x86_l_3836;
	case 14395ULL: goto x86_l_383b;
	case 14397ULL: goto x86_l_383d;
	case 14402ULL: goto x86_l_3842;
	case 14405ULL: goto x86_l_3845;
	case 14411ULL: goto x86_l_384b;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14425ULL: goto x86_l_3859;
	case 14429ULL: goto x86_l_385d;
	case 14434ULL: goto x86_l_3862;
	case 14439ULL: goto x86_l_3867;
	case 14444ULL: goto x86_l_386c;
	case 14449ULL: goto x86_l_3871;
	case 14451ULL: goto x86_l_3873;
	case 14455ULL: goto x86_l_3877;
	case 14457ULL: goto x86_l_3879;
	case 14463ULL: goto x86_l_387f;
	case 14465ULL: goto x86_l_3881;
	case 14467ULL: goto x86_l_3883;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14484ULL: goto x86_l_3894;
	case 14487ULL: goto x86_l_3897;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14496ULL: goto x86_l_38a0;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14508ULL: goto x86_l_38ac;
	case 14514ULL: goto x86_l_38b2;
	case 14519ULL: goto x86_l_38b7;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14539ULL: goto x86_l_38cb;
	case 14542ULL: goto x86_l_38ce;
	case 14548ULL: goto x86_l_38d4;
	case 14556ULL: goto x86_l_38dc;
	case 14563ULL: goto x86_l_38e3;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14575ULL: goto x86_l_38ef;
	case 14578ULL: goto x86_l_38f2;
	case 14584ULL: goto x86_l_38f8;
	case 14587ULL: goto x86_l_38fb;
	case 14597ULL: goto x86_l_3905;
	case 14600ULL: goto x86_l_3908;
	case 14604ULL: goto x86_l_390c;
	case 14612ULL: goto x86_l_3914;
	case 14617ULL: goto x86_l_3919;
	case 14619ULL: goto x86_l_391b;
	case 14623ULL: goto x86_l_391f;
	case 14631ULL: goto x86_l_3927;
	case 14634ULL: goto x86_l_392a;
	case 14638ULL: goto x86_l_392e;
	case 14645ULL: goto x86_l_3935;
	case 14650ULL: goto x86_l_393a;
	case 14655ULL: goto x86_l_393f;
	case 14660ULL: goto x86_l_3944;
	case 14669ULL: goto x86_l_394d;
	case 14678ULL: goto x86_l_3956;
	case 14686ULL: goto x86_l_395e;
	case 14691ULL: goto x86_l_3963;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14705ULL: goto x86_l_3971;
	case 14710ULL: goto x86_l_3976;
	case 14713ULL: goto x86_l_3979;
	case 14715ULL: goto x86_l_397b;
	case 14718ULL: goto x86_l_397e;
	case 14724ULL: goto x86_l_3984;
	case 14728ULL: goto x86_l_3988;
	case 14730ULL: goto x86_l_398a;
	case 14735ULL: goto x86_l_398f;
	case 14739ULL: goto x86_l_3993;
	case 14742ULL: goto x86_l_3996;
	case 14745ULL: goto x86_l_3999;
	case 14752ULL: goto x86_l_39a0;
	case 14754ULL: goto x86_l_39a2;
	case 14756ULL: goto x86_l_39a4;
	case 14760ULL: goto x86_l_39a8;
	case 14767ULL: goto x86_l_39af;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14782ULL: goto x86_l_39be;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14801ULL: goto x86_l_39d1;
	case 14804ULL: goto x86_l_39d4;
	case 14806ULL: goto x86_l_39d6;
	case 14812ULL: goto x86_l_39dc;
	case 14820ULL: goto x86_l_39e4;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14840ULL: goto x86_l_39f8;
	case 14846ULL: goto x86_l_39fe;
	case 14851ULL: goto x86_l_3a03;
	case 14853ULL: goto x86_l_3a05;
	case 14858ULL: goto x86_l_3a0a;
	case 14860ULL: goto x86_l_3a0c;
	case 14863ULL: goto x86_l_3a0f;
	case 14869ULL: goto x86_l_3a15;
	case 14873ULL: goto x86_l_3a19;
	case 14879ULL: goto x86_l_3a1f;
	case 14884ULL: goto x86_l_3a24;
	case 14888ULL: goto x86_l_3a28;
	case 14891ULL: goto x86_l_3a2b;
	case 14896ULL: goto x86_l_3a30;
	case 14901ULL: goto x86_l_3a35;
	case 14906ULL: goto x86_l_3a3a;
	case 14911ULL: goto x86_l_3a3f;
	case 14916ULL: goto x86_l_3a44;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14928ULL: goto x86_l_3a50;
	case 14933ULL: goto x86_l_3a55;
	case 14937ULL: goto x86_l_3a59;
	case 14942ULL: goto x86_l_3a5e;
	case 14947ULL: goto x86_l_3a63;
	case 14952ULL: goto x86_l_3a68;
	case 14957ULL: goto x86_l_3a6d;
	case 14959ULL: goto x86_l_3a6f;
	case 14964ULL: goto x86_l_3a74;
	case 14967ULL: goto x86_l_3a77;
	case 14969ULL: goto x86_l_3a79;
	case 14974ULL: goto x86_l_3a7e;
	case 14977ULL: goto x86_l_3a81;
	case 14979ULL: goto x86_l_3a83;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14998ULL: goto x86_l_3a96;
	case 15003ULL: goto x86_l_3a9b;
	case 15005ULL: goto x86_l_3a9d;
	case 15009ULL: goto x86_l_3aa1;
	case 15011ULL: goto x86_l_3aa3;
	case 15017ULL: goto x86_l_3aa9;
	case 15020ULL: goto x86_l_3aac;
	case 15022ULL: goto x86_l_3aae;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15039ULL: goto x86_l_3abf;
	case 15044ULL: goto x86_l_3ac4;
	case 15046ULL: goto x86_l_3ac6;
	case 15051ULL: goto x86_l_3acb;
	case 15053ULL: goto x86_l_3acd;
	case 15056ULL: goto x86_l_3ad0;
	case 15058ULL: goto x86_l_3ad2;
	case 15062ULL: goto x86_l_3ad6;
	case 15068ULL: goto x86_l_3adc;
	case 15073ULL: goto x86_l_3ae1;
	case 15077ULL: goto x86_l_3ae5;
	case 15080ULL: goto x86_l_3ae8;
	case 15085ULL: goto x86_l_3aed;
	case 15090ULL: goto x86_l_3af2;
	case 15093ULL: goto x86_l_3af5;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15109ULL: goto x86_l_3b05;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15122ULL: goto x86_l_3b12;
	case 15127ULL: goto x86_l_3b17;
	case 15133ULL: goto x86_l_3b1d;
	case 15137ULL: goto x86_l_3b21;
	case 15142ULL: goto x86_l_3b26;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15156ULL: goto x86_l_3b34;
	case 15160ULL: goto x86_l_3b38;
	case 15165ULL: goto x86_l_3b3d;
	case 15167ULL: goto x86_l_3b3f;
	case 15171ULL: goto x86_l_3b43;
	case 15174ULL: goto x86_l_3b46;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15188ULL: goto x86_l_3b54;
	case 15193ULL: goto x86_l_3b59;
	case 15195ULL: goto x86_l_3b5b;
	case 15199ULL: goto x86_l_3b5f;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15218ULL: goto x86_l_3b72;
	case 15223ULL: goto x86_l_3b77;
	case 15225ULL: goto x86_l_3b79;
	case 15229ULL: goto x86_l_3b7d;
	case 15233ULL: goto x86_l_3b81;
	case 15238ULL: goto x86_l_3b86;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15253ULL: goto x86_l_3b95;
	case 15256ULL: goto x86_l_3b98;
	case 15258ULL: goto x86_l_3b9a;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15272ULL: goto x86_l_3ba8;
	case 15277ULL: goto x86_l_3bad;
	case 15282ULL: goto x86_l_3bb2;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15302ULL: goto x86_l_3bc6;
	case 15308ULL: goto x86_l_3bcc;
	case 15313ULL: goto x86_l_3bd1;
	case 15316ULL: goto x86_l_3bd4;
	case 15322ULL: goto x86_l_3bda;
	case 15326ULL: goto x86_l_3bde;
	case 15331ULL: goto x86_l_3be3;
	case 15336ULL: goto x86_l_3be8;
	case 15341ULL: goto x86_l_3bed;
	case 15346ULL: goto x86_l_3bf2;
	case 15348ULL: goto x86_l_3bf4;
	case 15352ULL: goto x86_l_3bf8;
	case 15354ULL: goto x86_l_3bfa;
	case 15360ULL: goto x86_l_3c00;
	case 15362ULL: goto x86_l_3c02;
	case 15364ULL: goto x86_l_3c04;
	case 15370ULL: goto x86_l_3c0a;
	case 15375ULL: goto x86_l_3c0f;
	case 15381ULL: goto x86_l_3c15;
	case 15384ULL: goto x86_l_3c18;
	case 15386ULL: goto x86_l_3c1a;
	case 15391ULL: goto x86_l_3c1f;
	case 15393ULL: goto x86_l_3c21;
	case 15396ULL: goto x86_l_3c24;
	case 15402ULL: goto x86_l_3c2a;
	case 15405ULL: goto x86_l_3c2d;
	case 15411ULL: goto x86_l_3c33;
	case 15416ULL: goto x86_l_3c38;
	case 15418ULL: goto x86_l_3c3a;
	case 15423ULL: goto x86_l_3c3f;
	case 15428ULL: goto x86_l_3c44;
	case 15432ULL: goto x86_l_3c48;
	case 15437ULL: goto x86_l_3c4d;
	case 15443ULL: goto x86_l_3c53;
	case 15447ULL: goto x86_l_3c57;
	case 15452ULL: goto x86_l_3c5c;
	case 15457ULL: goto x86_l_3c61;
	case 15462ULL: goto x86_l_3c66;
	case 15466ULL: goto x86_l_3c6a;
	case 15470ULL: goto x86_l_3c6e;
	case 15475ULL: goto x86_l_3c73;
	case 15477ULL: goto x86_l_3c75;
	case 15481ULL: goto x86_l_3c79;
	case 15484ULL: goto x86_l_3c7c;
	case 15489ULL: goto x86_l_3c81;
	case 15494ULL: goto x86_l_3c86;
	case 15498ULL: goto x86_l_3c8a;
	case 15503ULL: goto x86_l_3c8f;
	case 15505ULL: goto x86_l_3c91;
	case 15509ULL: goto x86_l_3c95;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15524ULL: goto x86_l_3ca4;
	case 15528ULL: goto x86_l_3ca8;
	case 15533ULL: goto x86_l_3cad;
	case 15535ULL: goto x86_l_3caf;
	case 15539ULL: goto x86_l_3cb3;
	case 15543ULL: goto x86_l_3cb7;
	case 15548ULL: goto x86_l_3cbc;
	case 15553ULL: goto x86_l_3cc1;
	case 15558ULL: goto x86_l_3cc6;
	case 15563ULL: goto x86_l_3ccb;
	case 15568ULL: goto x86_l_3cd0;
	case 15573ULL: goto x86_l_3cd5;
	case 15575ULL: goto x86_l_3cd7;
	case 15580ULL: goto x86_l_3cdc;
	case 15585ULL: goto x86_l_3ce1;
	case 15589ULL: goto x86_l_3ce5;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15604ULL: goto x86_l_3cf4;
	case 15609ULL: goto x86_l_3cf9;
	case 15611ULL: goto x86_l_3cfb;
	case 15616ULL: goto x86_l_3d00;
	case 15619ULL: goto x86_l_3d03;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15633ULL: goto x86_l_3d11;
	case 15635ULL: goto x86_l_3d13;
	case 15639ULL: goto x86_l_3d17;
	case 15644ULL: goto x86_l_3d1c;
	case 15649ULL: goto x86_l_3d21;
	case 15654ULL: goto x86_l_3d26;
	case 15659ULL: goto x86_l_3d2b;
	case 15661ULL: goto x86_l_3d2d;
	case 15665ULL: goto x86_l_3d31;
	case 15667ULL: goto x86_l_3d33;
	case 15673ULL: goto x86_l_3d39;
	case 15676ULL: goto x86_l_3d3c;
	case 15678ULL: goto x86_l_3d3e;
	case 15684ULL: goto x86_l_3d44;
	case 15689ULL: goto x86_l_3d49;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15702ULL: goto x86_l_3d56;
	case 15707ULL: goto x86_l_3d5b;
	case 15709ULL: goto x86_l_3d5d;
	case 15712ULL: goto x86_l_3d60;
	case 15718ULL: goto x86_l_3d66;
	case 15722ULL: goto x86_l_3d6a;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15737ULL: goto x86_l_3d79;
	case 15740ULL: goto x86_l_3d7c;
	case 15745ULL: goto x86_l_3d81;
	case 15750ULL: goto x86_l_3d86;
	case 15753ULL: goto x86_l_3d89;
	case 15759ULL: goto x86_l_3d8f;
	case 15763ULL: goto x86_l_3d93;
	case 15768ULL: goto x86_l_3d98;
	case 15774ULL: goto x86_l_3d9e;
	case 15778ULL: goto x86_l_3da2;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15793ULL: goto x86_l_3db1;
	case 15797ULL: goto x86_l_3db5;
	case 15801ULL: goto x86_l_3db9;
	case 15806ULL: goto x86_l_3dbe;
	case 15808ULL: goto x86_l_3dc0;
	case 15812ULL: goto x86_l_3dc4;
	case 15815ULL: goto x86_l_3dc7;
	case 15820ULL: goto x86_l_3dcc;
	case 15825ULL: goto x86_l_3dd1;
	case 15829ULL: goto x86_l_3dd5;
	case 15834ULL: goto x86_l_3dda;
	case 15836ULL: goto x86_l_3ddc;
	case 15840ULL: goto x86_l_3de0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3754:
	/* 0x3754: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3758:
	/* 0x3758: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_375d:
	/* 0x375d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3762:
	/* 0x3762: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3767:
	/* 0x3767: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376b:
	/* 0x376b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3770:
	/* 0x3770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3772:
	/* 0x3772: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3776:
	/* 0x3776: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_377a:
	/* 0x377a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_377f:
	/* 0x377f: jmp    3a30 <trace_ret_kernel_write_tail+0x3a30> */
	goto x86_l_3a30;
x86_l_3784:
	/* 0x3784: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3787:
	/* 0x3787: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_378d:
	/* 0x378d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3791:
	/* 0x3791: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3796:
	/* 0x3796: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_379c:
	/* 0x379c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37a0:
	/* 0x37a0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37a5:
	/* 0x37a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37aa:
	/* 0x37aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37af:
	/* 0x37af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37b3:
	/* 0x37b3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37b7:
	/* 0x37b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37bc:
	/* 0x37bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37be:
	/* 0x37be: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c2:
	/* 0x37c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37c5:
	/* 0x37c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37ca:
	/* 0x37ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37cf:
	/* 0x37cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d3:
	/* 0x37d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d8:
	/* 0x37d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37da:
	/* 0x37da: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37de:
	/* 0x37de: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37e3:
	/* 0x37e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37e8:
	/* 0x37e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ed:
	/* 0x37ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37f1:
	/* 0x37f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37f6:
	/* 0x37f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f8:
	/* 0x37f8: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37fc:
	/* 0x37fc: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3800:
	/* 0x3800: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3805:
	/* 0x3805: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_380a:
	/* 0x380a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_380f:
	/* 0x380f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3814:
	/* 0x3814: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3817:
	/* 0x3817: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3819:
	/* 0x3819: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_381e:
	/* 0x381e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3823:
	/* 0x3823: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3827:
	/* 0x3827: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_382c:
	/* 0x382c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3831:
	/* 0x3831: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3836:
	/* 0x3836: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_383b:
	/* 0x383b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383d:
	/* 0x383d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3842:
	/* 0x3842: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3845:
	/* 0x3845: je     3b05 <trace_ret_kernel_write_tail+0x3b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b05;
	}
x86_l_384b:
	/* 0x384b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3850:
	/* 0x3850: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3853:
	/* 0x3853: je     3b05 <trace_ret_kernel_write_tail+0x3b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b05;
	}
x86_l_3859:
	/* 0x3859: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_385d:
	/* 0x385d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3862:
	/* 0x3862: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3867:
	/* 0x3867: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_386c:
	/* 0x386c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3871:
	/* 0x3871: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3873:
	/* 0x3873: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3877:
	/* 0x3877: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3879:
	/* 0x3879: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_387f:
	/* 0x387f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3881:
	/* 0x3881: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3883:
	/* 0x3883: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_3889:
	/* 0x3889: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_388e:
	/* 0x388e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3894:
	/* 0x3894: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3897:
	/* 0x3897: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3899:
	/* 0x3899: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_389e:
	/* 0x389e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a0:
	/* 0x38a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38a3:
	/* 0x38a3: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_38a9:
	/* 0x38a9: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_38ac:
	/* 0x38ac: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_38b2:
	/* 0x38b2: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_38b7:
	/* 0x38b7: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38b9:
	/* 0x38b9: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38be:
	/* 0x38be: jmp    3b81 <trace_ret_kernel_write_tail+0x3b81> */
	goto x86_l_3b81;
x86_l_38c3:
	/* 0x38c3: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_38cb:
	/* 0x38cb: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_38ce:
	/* 0x38ce: je     2153 <trace_ret_kernel_write_tail+0x2153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8531ULL;
	}
x86_l_38d4:
	/* 0x38d4: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_38dc:
	/* 0x38dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_38e3:
	/* 0x38e3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38e8:
	/* 0x38e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38ed:
	/* 0x38ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ef:
	/* 0x38ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38f2:
	/* 0x38f2: je     39dc <trace_ret_kernel_write_tail+0x39dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39dc;
	}
x86_l_38f8:
	/* 0x38f8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_38fb:
	/* 0x38fb: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_3905:
	/* 0x3905: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3908:
	/* 0x3908: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_390c:
	/* 0x390c: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3914:
	/* 0x3914: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3919:
	/* 0x3919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_391b:
	/* 0x391b: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_391f:
	/* 0x391f: mov    DWORD PTR [r14+0x1c],0x37 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084343ULL);
x86_l_3927:
	/* 0x3927: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_392a:
	/* 0x392a: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_392e:
	/* 0x392e: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_3935:
	/* 0x3935: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_393a:
	/* 0x393a: call   393f <trace_ret_kernel_write_tail+0x393f> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_393f:
	/* 0x393f: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_3944:
	/* 0x3944: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_394d:
	/* 0x394d: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3956:
	/* 0x3956: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_395e:
	/* 0x395e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3963:
	/* 0x3963: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3965:
	/* 0x3965: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_396a:
	/* 0x396a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3971:
	/* 0x3971: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3976:
	/* 0x3976: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3979:
	/* 0x3979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397b:
	/* 0x397b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_397e:
	/* 0x397e: je     467f <trace_ret_kernel_write_tail+0x467f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18047ULL;
	}
x86_l_3984:
	/* 0x3984: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3988:
	/* 0x3988: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_398a:
	/* 0x398a: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_398f:
	/* 0x398f: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3993:
	/* 0x3993: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3996:
	/* 0x3996: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3999:
	/* 0x3999: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_39a0:
	/* 0x39a0: jb     39dc <trace_ret_kernel_write_tail+0x39dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39dc;
	}
x86_l_39a2:
	/* 0x39a2: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a4:
	/* 0x39a4: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39a8:
	/* 0x39a8: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_39af:
	/* 0x39af: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_39b4:
	/* 0x39b4: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_39b9:
	/* 0x39b9: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_39be:
	/* 0x39be: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_39c6:
	/* 0x39c6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_39cb:
	/* 0x39cb: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_39d1:
	/* 0x39d1: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_39d4:
	/* 0x39d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d6:
	/* 0x39d6: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39dc:
	/* 0x39dc: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_39e4:
	/* 0x39e4: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_39e9:
	/* 0x39e9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ee:
	/* 0x39ee: jmp    2153 <trace_ret_kernel_write_tail+0x2153> */
	return 8531ULL;
x86_l_39f3:
	/* 0x39f3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39f8:
	/* 0x39f8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_39fe:
	/* 0x39fe: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_3a03:
	/* 0x3a03: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3a05:
	/* 0x3a05: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3a0a:
	/* 0x3a0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a0c:
	/* 0x3a0c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a0f:
	/* 0x3a0f: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3afb;
	}
x86_l_3a15:
	/* 0x3a15: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3a19:
	/* 0x3a19: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3a1f:
	/* 0x3a1f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a24:
	/* 0x3a24: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3a28:
	/* 0x3a28: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a2b:
	/* 0x3a2b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a30:
	/* 0x3a30: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a35:
	/* 0x3a35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a3a:
	/* 0x3a3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a3f:
	/* 0x3a3f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a44:
	/* 0x3a44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a49:
	/* 0x3a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a4b:
	/* 0x3a4b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a50:
	/* 0x3a50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a55:
	/* 0x3a55: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a59:
	/* 0x3a59: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a5e:
	/* 0x3a5e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a63:
	/* 0x3a63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a68:
	/* 0x3a68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a6d:
	/* 0x3a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6f:
	/* 0x3a6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a74:
	/* 0x3a74: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3a77:
	/* 0x3a77: je     3af2 <trace_ret_kernel_write_tail+0x3af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af2;
	}
x86_l_3a79:
	/* 0x3a79: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a7e:
	/* 0x3a7e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3a81:
	/* 0x3a81: je     3af2 <trace_ret_kernel_write_tail+0x3af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af2;
	}
x86_l_3a83:
	/* 0x3a83: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3a87:
	/* 0x3a87: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3a91:
	/* 0x3a91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a96:
	/* 0x3a96: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3a9b:
	/* 0x3a9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9d:
	/* 0x3a9d: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3aa1:
	/* 0x3aa1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3aa3:
	/* 0x3aa3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3aa9:
	/* 0x3aa9: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3aac:
	/* 0x3aac: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3aae:
	/* 0x3aae: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_3ab4:
	/* 0x3ab4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ab9:
	/* 0x3ab9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3abf:
	/* 0x3abf: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_3ac4:
	/* 0x3ac4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3ac6:
	/* 0x3ac6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3acb:
	/* 0x3acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3acd:
	/* 0x3acd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ad0:
	/* 0x3ad0: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3afb;
	}
x86_l_3ad2:
	/* 0x3ad2: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3ad6:
	/* 0x3ad6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3adc:
	/* 0x3adc: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ae1:
	/* 0x3ae1: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ae5:
	/* 0x3ae5: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ae8:
	/* 0x3ae8: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aed:
	/* 0x3aed: jmp    3cbc <trace_ret_kernel_write_tail+0x3cbc> */
	goto x86_l_3cbc;
x86_l_3af2:
	/* 0x3af2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3af5:
	/* 0x3af5: je     3c44 <trace_ret_kernel_write_tail+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c44;
	}
x86_l_3afb:
	/* 0x3afb: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b00:
	/* 0x3b00: jmp    1b43 <trace_ret_kernel_write_tail+0x1b43> */
	return 6979ULL;
x86_l_3b05:
	/* 0x3b05: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3b08:
	/* 0x3b08: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_3b0e:
	/* 0x3b0e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b12:
	/* 0x3b12: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3b17:
	/* 0x3b17: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_3b1d:
	/* 0x3b1d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b21:
	/* 0x3b21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b26:
	/* 0x3b26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b2b:
	/* 0x3b2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b30:
	/* 0x3b30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b34:
	/* 0x3b34: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b38:
	/* 0x3b38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b3d:
	/* 0x3b3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b3f:
	/* 0x3b3f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b43:
	/* 0x3b43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b46:
	/* 0x3b46: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b4b:
	/* 0x3b4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b50:
	/* 0x3b50: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b54:
	/* 0x3b54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b59:
	/* 0x3b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5b:
	/* 0x3b5b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b5f:
	/* 0x3b5f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b64:
	/* 0x3b64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b69:
	/* 0x3b69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b72:
	/* 0x3b72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b77:
	/* 0x3b77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b79:
	/* 0x3b79: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b7d:
	/* 0x3b7d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b81:
	/* 0x3b81: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b86:
	/* 0x3b86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b8b:
	/* 0x3b8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b90:
	/* 0x3b90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b95:
	/* 0x3b95: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3b98:
	/* 0x3b98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9a:
	/* 0x3b9a: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b9f:
	/* 0x3b9f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ba4:
	/* 0x3ba4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ba8:
	/* 0x3ba8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bad:
	/* 0x3bad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bb2:
	/* 0x3bb2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bbc:
	/* 0x3bbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bbe:
	/* 0x3bbe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bc3:
	/* 0x3bc3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3bc6:
	/* 0x3bc6: je     3ed5 <trace_ret_kernel_write_tail+0x3ed5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16085ULL;
	}
x86_l_3bcc:
	/* 0x3bcc: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bd1:
	/* 0x3bd1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3bd4:
	/* 0x3bd4: je     3ed5 <trace_ret_kernel_write_tail+0x3ed5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16085ULL;
	}
x86_l_3bda:
	/* 0x3bda: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3bde:
	/* 0x3bde: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3be3:
	/* 0x3be3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3be8:
	/* 0x3be8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bed:
	/* 0x3bed: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3bf2:
	/* 0x3bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bf4:
	/* 0x3bf4: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3bf8:
	/* 0x3bf8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3bfa:
	/* 0x3bfa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c00:
	/* 0x3c00: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3c02:
	/* 0x3c02: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c04:
	/* 0x3c04: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_3c0a:
	/* 0x3c0a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c0f:
	/* 0x3c0f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3c15:
	/* 0x3c15: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c18:
	/* 0x3c18: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3c1a:
	/* 0x3c1a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3c1f:
	/* 0x3c1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c21:
	/* 0x3c21: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c24:
	/* 0x3c24: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_3c2a:
	/* 0x3c2a: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3c2d:
	/* 0x3c2d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3c33:
	/* 0x3c33: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3c38:
	/* 0x3c38: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c3a:
	/* 0x3c3a: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c3f:
	/* 0x3c3f: jmp    3f51 <trace_ret_kernel_write_tail+0x3f51> */
	return 16209ULL;
x86_l_3c44:
	/* 0x3c44: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c48:
	/* 0x3c48: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3c4d:
	/* 0x3c4d: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3afb;
	}
x86_l_3c53:
	/* 0x3c53: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c57:
	/* 0x3c57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5c:
	/* 0x3c5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c61:
	/* 0x3c61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c66:
	/* 0x3c66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6a:
	/* 0x3c6a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c6e:
	/* 0x3c6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c73:
	/* 0x3c73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c75:
	/* 0x3c75: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c79:
	/* 0x3c79: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c7c:
	/* 0x3c7c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c81:
	/* 0x3c81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c86:
	/* 0x3c86: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8a:
	/* 0x3c8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c8f:
	/* 0x3c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c91:
	/* 0x3c91: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c95:
	/* 0x3c95: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c9a:
	/* 0x3c9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c9f:
	/* 0x3c9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ca4:
	/* 0x3ca4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ca8:
	/* 0x3ca8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cad:
	/* 0x3cad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3caf:
	/* 0x3caf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cb3:
	/* 0x3cb3: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3cb7:
	/* 0x3cb7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cbc:
	/* 0x3cbc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cc1:
	/* 0x3cc1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cc6:
	/* 0x3cc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ccb:
	/* 0x3ccb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cd0:
	/* 0x3cd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cd5:
	/* 0x3cd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd7:
	/* 0x3cd7: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cdc:
	/* 0x3cdc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ce1:
	/* 0x3ce1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ce5:
	/* 0x3ce5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cea:
	/* 0x3cea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cef:
	/* 0x3cef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cf4:
	/* 0x3cf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cf9:
	/* 0x3cf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cfb:
	/* 0x3cfb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d00:
	/* 0x3d00: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3d03:
	/* 0x3d03: je     3d86 <trace_ret_kernel_write_tail+0x3d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d86;
	}
x86_l_3d09:
	/* 0x3d09: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d0e:
	/* 0x3d0e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3d11:
	/* 0x3d11: je     3d86 <trace_ret_kernel_write_tail+0x3d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d86;
	}
x86_l_3d13:
	/* 0x3d13: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d17:
	/* 0x3d17: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d1c:
	/* 0x3d1c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3d21:
	/* 0x3d21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d26:
	/* 0x3d26: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3d2b:
	/* 0x3d2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2d:
	/* 0x3d2d: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3d31:
	/* 0x3d31: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d33:
	/* 0x3d33: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d39:
	/* 0x3d39: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3d3c:
	/* 0x3d3c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d3e:
	/* 0x3d3e: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_3d44:
	/* 0x3d44: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d49:
	/* 0x3d49: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3d4f:
	/* 0x3d4f: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_3d54:
	/* 0x3d54: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3d56:
	/* 0x3d56: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3d5b:
	/* 0x3d5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d5d:
	/* 0x3d5d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d60:
	/* 0x3d60: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3afb;
	}
x86_l_3d66:
	/* 0x3d66: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d6a:
	/* 0x3d6a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3d70:
	/* 0x3d70: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d75:
	/* 0x3d75: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3d79:
	/* 0x3d79: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d7c:
	/* 0x3d7c: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d81:
	/* 0x3d81: jmp    3e07 <trace_ret_kernel_write_tail+0x3e07> */
	return 15879ULL;
x86_l_3d86:
	/* 0x3d86: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3d89:
	/* 0x3d89: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3afb;
	}
x86_l_3d8f:
	/* 0x3d8f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d93:
	/* 0x3d93: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3d98:
	/* 0x3d98: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3afb;
	}
x86_l_3d9e:
	/* 0x3d9e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3da2:
	/* 0x3da2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3da7:
	/* 0x3da7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dac:
	/* 0x3dac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3db1:
	/* 0x3db1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3db5:
	/* 0x3db5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3db9:
	/* 0x3db9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dbe:
	/* 0x3dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc0:
	/* 0x3dc0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dc4:
	/* 0x3dc4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3dc7:
	/* 0x3dc7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dcc:
	/* 0x3dcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dd1:
	/* 0x3dd1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd5:
	/* 0x3dd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dda:
	/* 0x3dda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ddc:
	/* 0x3ddc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de0:
	/* 0x3de0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 15845ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15845ULL: goto x86_l_3de5;
	case 15850ULL: goto x86_l_3dea;
	case 15855ULL: goto x86_l_3def;
	case 15859ULL: goto x86_l_3df3;
	case 15864ULL: goto x86_l_3df8;
	case 15866ULL: goto x86_l_3dfa;
	case 15870ULL: goto x86_l_3dfe;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15884ULL: goto x86_l_3e0c;
	case 15889ULL: goto x86_l_3e11;
	case 15894ULL: goto x86_l_3e16;
	case 15899ULL: goto x86_l_3e1b;
	case 15904ULL: goto x86_l_3e20;
	case 15906ULL: goto x86_l_3e22;
	case 15911ULL: goto x86_l_3e27;
	case 15916ULL: goto x86_l_3e2c;
	case 15920ULL: goto x86_l_3e30;
	case 15925ULL: goto x86_l_3e35;
	case 15930ULL: goto x86_l_3e3a;
	case 15935ULL: goto x86_l_3e3f;
	case 15940ULL: goto x86_l_3e44;
	case 15942ULL: goto x86_l_3e46;
	case 15947ULL: goto x86_l_3e4b;
	case 15950ULL: goto x86_l_3e4e;
	case 15956ULL: goto x86_l_3e54;
	case 15961ULL: goto x86_l_3e59;
	case 15964ULL: goto x86_l_3e5c;
	case 15970ULL: goto x86_l_3e62;
	case 15974ULL: goto x86_l_3e66;
	case 15979ULL: goto x86_l_3e6b;
	case 15984ULL: goto x86_l_3e70;
	case 15989ULL: goto x86_l_3e75;
	case 15994ULL: goto x86_l_3e7a;
	case 15996ULL: goto x86_l_3e7c;
	case 16000ULL: goto x86_l_3e80;
	case 16002ULL: goto x86_l_3e82;
	case 16008ULL: goto x86_l_3e88;
	case 16011ULL: goto x86_l_3e8b;
	case 16013ULL: goto x86_l_3e8d;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16030ULL: goto x86_l_3e9e;
	case 16035ULL: goto x86_l_3ea3;
	case 16037ULL: goto x86_l_3ea5;
	case 16042ULL: goto x86_l_3eaa;
	case 16044ULL: goto x86_l_3eac;
	case 16047ULL: goto x86_l_3eaf;
	case 16053ULL: goto x86_l_3eb5;
	case 16057ULL: goto x86_l_3eb9;
	case 16063ULL: goto x86_l_3ebf;
	case 16068ULL: goto x86_l_3ec4;
	case 16072ULL: goto x86_l_3ec8;
	case 16075ULL: goto x86_l_3ecb;
	case 16080ULL: goto x86_l_3ed0;
	case 16085ULL: goto x86_l_3ed5;
	case 16088ULL: goto x86_l_3ed8;
	case 16094ULL: goto x86_l_3ede;
	case 16098ULL: goto x86_l_3ee2;
	case 16103ULL: goto x86_l_3ee7;
	case 16109ULL: goto x86_l_3eed;
	case 16113ULL: goto x86_l_3ef1;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16128ULL: goto x86_l_3f00;
	case 16132ULL: goto x86_l_3f04;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16143ULL: goto x86_l_3f0f;
	case 16147ULL: goto x86_l_3f13;
	case 16150ULL: goto x86_l_3f16;
	case 16155ULL: goto x86_l_3f1b;
	case 16160ULL: goto x86_l_3f20;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16171ULL: goto x86_l_3f2b;
	case 16175ULL: goto x86_l_3f2f;
	case 16180ULL: goto x86_l_3f34;
	case 16185ULL: goto x86_l_3f39;
	case 16190ULL: goto x86_l_3f3e;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16201ULL: goto x86_l_3f49;
	case 16205ULL: goto x86_l_3f4d;
	case 16209ULL: goto x86_l_3f51;
	case 16214ULL: goto x86_l_3f56;
	case 16219ULL: goto x86_l_3f5b;
	case 16224ULL: goto x86_l_3f60;
	case 16229ULL: goto x86_l_3f65;
	case 16232ULL: goto x86_l_3f68;
	case 16234ULL: goto x86_l_3f6a;
	case 16239ULL: goto x86_l_3f6f;
	case 16244ULL: goto x86_l_3f74;
	case 16248ULL: goto x86_l_3f78;
	case 16253ULL: goto x86_l_3f7d;
	case 16258ULL: goto x86_l_3f82;
	case 16263ULL: goto x86_l_3f87;
	case 16268ULL: goto x86_l_3f8c;
	case 16270ULL: goto x86_l_3f8e;
	case 16275ULL: goto x86_l_3f93;
	case 16278ULL: goto x86_l_3f96;
	case 16284ULL: goto x86_l_3f9c;
	case 16289ULL: goto x86_l_3fa1;
	case 16292ULL: goto x86_l_3fa4;
	case 16298ULL: goto x86_l_3faa;
	case 16302ULL: goto x86_l_3fae;
	case 16307ULL: goto x86_l_3fb3;
	case 16312ULL: goto x86_l_3fb8;
	case 16317ULL: goto x86_l_3fbd;
	case 16322ULL: goto x86_l_3fc2;
	case 16324ULL: goto x86_l_3fc4;
	case 16328ULL: goto x86_l_3fc8;
	case 16330ULL: goto x86_l_3fca;
	case 16336ULL: goto x86_l_3fd0;
	case 16338ULL: goto x86_l_3fd2;
	case 16340ULL: goto x86_l_3fd4;
	case 16346ULL: goto x86_l_3fda;
	case 16351ULL: goto x86_l_3fdf;
	case 16357ULL: goto x86_l_3fe5;
	case 16360ULL: goto x86_l_3fe8;
	case 16362ULL: goto x86_l_3fea;
	case 16367ULL: goto x86_l_3fef;
	case 16369ULL: goto x86_l_3ff1;
	case 16372ULL: goto x86_l_3ff4;
	case 16378ULL: goto x86_l_3ffa;
	case 16381ULL: goto x86_l_3ffd;
	case 16387ULL: goto x86_l_4003;
	case 16392ULL: goto x86_l_4008;
	case 16394ULL: goto x86_l_400a;
	case 16399ULL: goto x86_l_400f;
	case 16404ULL: goto x86_l_4014;
	case 16407ULL: goto x86_l_4017;
	case 16413ULL: goto x86_l_401d;
	case 16417ULL: goto x86_l_4021;
	case 16422ULL: goto x86_l_4026;
	case 16428ULL: goto x86_l_402c;
	case 16432ULL: goto x86_l_4030;
	case 16437ULL: goto x86_l_4035;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16451ULL: goto x86_l_4043;
	case 16455ULL: goto x86_l_4047;
	case 16460ULL: goto x86_l_404c;
	case 16462ULL: goto x86_l_404e;
	case 16466ULL: goto x86_l_4052;
	case 16469ULL: goto x86_l_4055;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16483ULL: goto x86_l_4063;
	case 16488ULL: goto x86_l_4068;
	case 16490ULL: goto x86_l_406a;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16504ULL: goto x86_l_4078;
	case 16509ULL: goto x86_l_407d;
	case 16513ULL: goto x86_l_4081;
	case 16518ULL: goto x86_l_4086;
	case 16520ULL: goto x86_l_4088;
	case 16524ULL: goto x86_l_408c;
	case 16528ULL: goto x86_l_4090;
	case 16533ULL: goto x86_l_4095;
	case 16538ULL: goto x86_l_409a;
	case 16543ULL: goto x86_l_409f;
	case 16548ULL: goto x86_l_40a4;
	case 16553ULL: goto x86_l_40a9;
	case 16558ULL: goto x86_l_40ae;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16570ULL: goto x86_l_40ba;
	case 16574ULL: goto x86_l_40be;
	case 16579ULL: goto x86_l_40c3;
	case 16584ULL: goto x86_l_40c8;
	case 16589ULL: goto x86_l_40cd;
	case 16594ULL: goto x86_l_40d2;
	case 16596ULL: goto x86_l_40d4;
	case 16601ULL: goto x86_l_40d9;
	case 16604ULL: goto x86_l_40dc;
	case 16610ULL: goto x86_l_40e2;
	case 16615ULL: goto x86_l_40e7;
	case 16618ULL: goto x86_l_40ea;
	case 16624ULL: goto x86_l_40f0;
	case 16628ULL: goto x86_l_40f4;
	case 16633ULL: goto x86_l_40f9;
	case 16638ULL: goto x86_l_40fe;
	case 16643ULL: goto x86_l_4103;
	case 16648ULL: goto x86_l_4108;
	case 16650ULL: goto x86_l_410a;
	case 16654ULL: goto x86_l_410e;
	case 16656ULL: goto x86_l_4110;
	case 16662ULL: goto x86_l_4116;
	case 16665ULL: goto x86_l_4119;
	case 16667ULL: goto x86_l_411b;
	case 16673ULL: goto x86_l_4121;
	case 16678ULL: goto x86_l_4126;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16691ULL: goto x86_l_4133;
	case 16696ULL: goto x86_l_4138;
	case 16698ULL: goto x86_l_413a;
	case 16701ULL: goto x86_l_413d;
	case 16707ULL: goto x86_l_4143;
	case 16711ULL: goto x86_l_4147;
	case 16717ULL: goto x86_l_414d;
	case 16722ULL: goto x86_l_4152;
	case 16726ULL: goto x86_l_4156;
	case 16729ULL: goto x86_l_4159;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16742ULL: goto x86_l_4166;
	case 16748ULL: goto x86_l_416c;
	case 16752ULL: goto x86_l_4170;
	case 16757ULL: goto x86_l_4175;
	case 16763ULL: goto x86_l_417b;
	case 16767ULL: goto x86_l_417f;
	case 16772ULL: goto x86_l_4184;
	case 16777ULL: goto x86_l_4189;
	case 16782ULL: goto x86_l_418e;
	case 16786ULL: goto x86_l_4192;
	case 16790ULL: goto x86_l_4196;
	case 16795ULL: goto x86_l_419b;
	case 16797ULL: goto x86_l_419d;
	case 16801ULL: goto x86_l_41a1;
	case 16804ULL: goto x86_l_41a4;
	case 16809ULL: goto x86_l_41a9;
	case 16814ULL: goto x86_l_41ae;
	case 16818ULL: goto x86_l_41b2;
	case 16823ULL: goto x86_l_41b7;
	case 16825ULL: goto x86_l_41b9;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16844ULL: goto x86_l_41cc;
	case 16848ULL: goto x86_l_41d0;
	case 16853ULL: goto x86_l_41d5;
	case 16855ULL: goto x86_l_41d7;
	case 16859ULL: goto x86_l_41db;
	case 16863ULL: goto x86_l_41df;
	case 16868ULL: goto x86_l_41e4;
	case 16873ULL: goto x86_l_41e9;
	case 16878ULL: goto x86_l_41ee;
	case 16883ULL: goto x86_l_41f3;
	case 16886ULL: goto x86_l_41f6;
	case 16888ULL: goto x86_l_41f8;
	case 16893ULL: goto x86_l_41fd;
	case 16898ULL: goto x86_l_4202;
	case 16902ULL: goto x86_l_4206;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16932ULL: goto x86_l_4224;
	case 16938ULL: goto x86_l_422a;
	case 16943ULL: goto x86_l_422f;
	case 16946ULL: goto x86_l_4232;
	case 16952ULL: goto x86_l_4238;
	case 16956ULL: goto x86_l_423c;
	case 16961ULL: goto x86_l_4241;
	case 16966ULL: goto x86_l_4246;
	case 16971ULL: goto x86_l_424b;
	case 16976ULL: goto x86_l_4250;
	case 16978ULL: goto x86_l_4252;
	case 16982ULL: goto x86_l_4256;
	case 16984ULL: goto x86_l_4258;
	case 16990ULL: goto x86_l_425e;
	case 16992ULL: goto x86_l_4260;
	case 16994ULL: goto x86_l_4262;
	case 17000ULL: goto x86_l_4268;
	case 17005ULL: goto x86_l_426d;
	case 17011ULL: goto x86_l_4273;
	case 17014ULL: goto x86_l_4276;
	case 17016ULL: goto x86_l_4278;
	case 17021ULL: goto x86_l_427d;
	case 17023ULL: goto x86_l_427f;
	case 17026ULL: goto x86_l_4282;
	case 17032ULL: goto x86_l_4288;
	case 17035ULL: goto x86_l_428b;
	case 17041ULL: goto x86_l_4291;
	case 17046ULL: goto x86_l_4296;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17058ULL: goto x86_l_42a2;
	case 17061ULL: goto x86_l_42a5;
	case 17067ULL: goto x86_l_42ab;
	case 17071ULL: goto x86_l_42af;
	case 17076ULL: goto x86_l_42b4;
	case 17082ULL: goto x86_l_42ba;
	case 17086ULL: goto x86_l_42be;
	case 17091ULL: goto x86_l_42c3;
	case 17096ULL: goto x86_l_42c8;
	case 17101ULL: goto x86_l_42cd;
	case 17105ULL: goto x86_l_42d1;
	case 17109ULL: goto x86_l_42d5;
	case 17114ULL: goto x86_l_42da;
	case 17116ULL: goto x86_l_42dc;
	case 17120ULL: goto x86_l_42e0;
	case 17123ULL: goto x86_l_42e3;
	case 17128ULL: goto x86_l_42e8;
	case 17133ULL: goto x86_l_42ed;
	case 17137ULL: goto x86_l_42f1;
	case 17142ULL: goto x86_l_42f6;
	case 17144ULL: goto x86_l_42f8;
	case 17148ULL: goto x86_l_42fc;
	case 17153ULL: goto x86_l_4301;
	case 17158ULL: goto x86_l_4306;
	case 17163ULL: goto x86_l_430b;
	case 17167ULL: goto x86_l_430f;
	case 17172ULL: goto x86_l_4314;
	case 17174ULL: goto x86_l_4316;
	case 17178ULL: goto x86_l_431a;
	case 17182ULL: goto x86_l_431e;
	case 17187ULL: goto x86_l_4323;
	case 17192ULL: goto x86_l_4328;
	case 17197ULL: goto x86_l_432d;
	case 17202ULL: goto x86_l_4332;
	case 17207ULL: goto x86_l_4337;
	case 17212ULL: goto x86_l_433c;
	case 17214ULL: goto x86_l_433e;
	case 17219ULL: goto x86_l_4343;
	case 17224ULL: goto x86_l_4348;
	case 17228ULL: goto x86_l_434c;
	case 17233ULL: goto x86_l_4351;
	case 17238ULL: goto x86_l_4356;
	case 17243ULL: goto x86_l_435b;
	case 17248ULL: goto x86_l_4360;
	case 17250ULL: goto x86_l_4362;
	case 17255ULL: goto x86_l_4367;
	case 17258ULL: goto x86_l_436a;
	case 17264ULL: goto x86_l_4370;
	case 17269ULL: goto x86_l_4375;
	case 17272ULL: goto x86_l_4378;
	case 17278ULL: goto x86_l_437e;
	case 17282ULL: goto x86_l_4382;
	case 17287ULL: goto x86_l_4387;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17302ULL: goto x86_l_4396;
	case 17304ULL: goto x86_l_4398;
	case 17308ULL: goto x86_l_439c;
	case 17310ULL: goto x86_l_439e;
	case 17316ULL: goto x86_l_43a4;
	case 17319ULL: goto x86_l_43a7;
	case 17321ULL: goto x86_l_43a9;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17338ULL: goto x86_l_43ba;
	case 17343ULL: goto x86_l_43bf;
	case 17345ULL: goto x86_l_43c1;
	case 17350ULL: goto x86_l_43c6;
	case 17352ULL: goto x86_l_43c8;
	case 17355ULL: goto x86_l_43cb;
	case 17361ULL: goto x86_l_43d1;
	case 17365ULL: goto x86_l_43d5;
	case 17371ULL: goto x86_l_43db;
	case 17376ULL: goto x86_l_43e0;
	case 17380ULL: goto x86_l_43e4;
	case 17383ULL: goto x86_l_43e7;
	case 17388ULL: goto x86_l_43ec;
	case 17393ULL: goto x86_l_43f1;
	case 17396ULL: goto x86_l_43f4;
	case 17402ULL: goto x86_l_43fa;
	case 17406ULL: goto x86_l_43fe;
	case 17411ULL: goto x86_l_4403;
	case 17417ULL: goto x86_l_4409;
	case 17421ULL: goto x86_l_440d;
	case 17426ULL: goto x86_l_4412;
	case 17431ULL: goto x86_l_4417;
	case 17436ULL: goto x86_l_441c;
	case 17440ULL: goto x86_l_4420;
	case 17444ULL: goto x86_l_4424;
	case 17449ULL: goto x86_l_4429;
	case 17451ULL: goto x86_l_442b;
	case 17455ULL: goto x86_l_442f;
	case 17458ULL: goto x86_l_4432;
	case 17463ULL: goto x86_l_4437;
	case 17468ULL: goto x86_l_443c;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17479ULL: goto x86_l_4447;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17493ULL: goto x86_l_4455;
	case 17498ULL: goto x86_l_445a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3de5:
	/* 0x3de5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dea:
	/* 0x3dea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3def:
	/* 0x3def: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3df3:
	/* 0x3df3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3df8:
	/* 0x3df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dfa:
	/* 0x3dfa: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dfe:
	/* 0x3dfe: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e02:
	/* 0x3e02: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e07:
	/* 0x3e07: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e0c:
	/* 0x3e0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e11:
	/* 0x3e11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e16:
	/* 0x3e16: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e1b:
	/* 0x3e1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e20:
	/* 0x3e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e22:
	/* 0x3e22: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e27:
	/* 0x3e27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e2c:
	/* 0x3e2c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3e30:
	/* 0x3e30: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e35:
	/* 0x3e35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e3a:
	/* 0x3e3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e3f:
	/* 0x3e3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e44:
	/* 0x3e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e46:
	/* 0x3e46: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e4b:
	/* 0x3e4b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e4e:
	/* 0x3e4e: je     4014 <trace_ret_kernel_write_tail+0x4014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4014;
	}
x86_l_3e54:
	/* 0x3e54: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e59:
	/* 0x3e59: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3e5c:
	/* 0x3e5c: je     4014 <trace_ret_kernel_write_tail+0x4014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4014;
	}
x86_l_3e62:
	/* 0x3e62: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e66:
	/* 0x3e66: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e6b:
	/* 0x3e6b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3e70:
	/* 0x3e70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e75:
	/* 0x3e75: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3e7a:
	/* 0x3e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e7c:
	/* 0x3e7c: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3e80:
	/* 0x3e80: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3e82:
	/* 0x3e82: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e88:
	/* 0x3e88: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3e8b:
	/* 0x3e8b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e8d:
	/* 0x3e8d: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_3e93:
	/* 0x3e93: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e98:
	/* 0x3e98: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3e9e:
	/* 0x3e9e: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_3ea3:
	/* 0x3ea3: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3ea5:
	/* 0x3ea5: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3eaa:
	/* 0x3eaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eac:
	/* 0x3eac: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3eaf:
	/* 0x3eaf: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_3eb5:
	/* 0x3eb5: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3eb9:
	/* 0x3eb9: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3ebf:
	/* 0x3ebf: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ec4:
	/* 0x3ec4: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ec8:
	/* 0x3ec8: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ecb:
	/* 0x3ecb: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed0:
	/* 0x3ed0: jmp    4095 <trace_ret_kernel_write_tail+0x4095> */
	goto x86_l_4095;
x86_l_3ed5:
	/* 0x3ed5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3ed8:
	/* 0x3ed8: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_3ede:
	/* 0x3ede: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee2:
	/* 0x3ee2: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3ee7:
	/* 0x3ee7: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_3eed:
	/* 0x3eed: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ef1:
	/* 0x3ef1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ef6:
	/* 0x3ef6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3efb:
	/* 0x3efb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f00:
	/* 0x3f00: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f04:
	/* 0x3f04: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f08:
	/* 0x3f08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f0d:
	/* 0x3f0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f0f:
	/* 0x3f0f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f13:
	/* 0x3f13: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f16:
	/* 0x3f16: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f1b:
	/* 0x3f1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f20:
	/* 0x3f20: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f24:
	/* 0x3f24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f29:
	/* 0x3f29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f2b:
	/* 0x3f2b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f2f:
	/* 0x3f2f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f34:
	/* 0x3f34: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f39:
	/* 0x3f39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f3e:
	/* 0x3f3e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f42:
	/* 0x3f42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f47:
	/* 0x3f47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f49:
	/* 0x3f49: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f4d:
	/* 0x3f4d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f51:
	/* 0x3f51: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f56:
	/* 0x3f56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f5b:
	/* 0x3f5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f60:
	/* 0x3f60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f65:
	/* 0x3f65: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3f68:
	/* 0x3f68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f6a:
	/* 0x3f6a: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f6f:
	/* 0x3f6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f74:
	/* 0x3f74: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f78:
	/* 0x3f78: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f7d:
	/* 0x3f7d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f82:
	/* 0x3f82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f87:
	/* 0x3f87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f8c:
	/* 0x3f8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8e:
	/* 0x3f8e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f93:
	/* 0x3f93: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3f96:
	/* 0x3f96: je     4163 <trace_ret_kernel_write_tail+0x4163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4163;
	}
x86_l_3f9c:
	/* 0x3f9c: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fa1:
	/* 0x3fa1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3fa4:
	/* 0x3fa4: je     4163 <trace_ret_kernel_write_tail+0x4163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4163;
	}
x86_l_3faa:
	/* 0x3faa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3fae:
	/* 0x3fae: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fb3:
	/* 0x3fb3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3fb8:
	/* 0x3fb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fbd:
	/* 0x3fbd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3fc2:
	/* 0x3fc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc4:
	/* 0x3fc4: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3fc8:
	/* 0x3fc8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3fca:
	/* 0x3fca: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3fd2:
	/* 0x3fd2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fd4:
	/* 0x3fd4: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_3fda:
	/* 0x3fda: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3fdf:
	/* 0x3fdf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3fe5:
	/* 0x3fe5: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3fe8:
	/* 0x3fe8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3fea:
	/* 0x3fea: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3fef:
	/* 0x3fef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff1:
	/* 0x3ff1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ff4:
	/* 0x3ff4: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_3ffa:
	/* 0x3ffa: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3ffd:
	/* 0x3ffd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4003:
	/* 0x4003: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4008:
	/* 0x4008: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_400a:
	/* 0x400a: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_400f:
	/* 0x400f: jmp    41df <trace_ret_kernel_write_tail+0x41df> */
	goto x86_l_41df;
x86_l_4014:
	/* 0x4014: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4017:
	/* 0x4017: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_401d:
	/* 0x401d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4021:
	/* 0x4021: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4026:
	/* 0x4026: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_402c:
	/* 0x402c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4030:
	/* 0x4030: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4035:
	/* 0x4035: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_403a:
	/* 0x403a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_403f:
	/* 0x403f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4043:
	/* 0x4043: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4047:
	/* 0x4047: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_404c:
	/* 0x404c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_404e:
	/* 0x404e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4052:
	/* 0x4052: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4055:
	/* 0x4055: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_405a:
	/* 0x405a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_405f:
	/* 0x405f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4063:
	/* 0x4063: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4068:
	/* 0x4068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406a:
	/* 0x406a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_406e:
	/* 0x406e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4073:
	/* 0x4073: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4078:
	/* 0x4078: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_407d:
	/* 0x407d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4081:
	/* 0x4081: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4086:
	/* 0x4086: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4088:
	/* 0x4088: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_408c:
	/* 0x408c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4090:
	/* 0x4090: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4095:
	/* 0x4095: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_409a:
	/* 0x409a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_409f:
	/* 0x409f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40a4:
	/* 0x40a4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_40a9:
	/* 0x40a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40ae:
	/* 0x40ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b0:
	/* 0x40b0: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40b5:
	/* 0x40b5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40ba:
	/* 0x40ba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_40be:
	/* 0x40be: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40c3:
	/* 0x40c3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40c8:
	/* 0x40c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40cd:
	/* 0x40cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40d2:
	/* 0x40d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d4:
	/* 0x40d4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40d9:
	/* 0x40d9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_40dc:
	/* 0x40dc: je     42a2 <trace_ret_kernel_write_tail+0x42a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a2;
	}
x86_l_40e2:
	/* 0x40e2: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40e7:
	/* 0x40e7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_40ea:
	/* 0x40ea: je     42a2 <trace_ret_kernel_write_tail+0x42a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a2;
	}
x86_l_40f0:
	/* 0x40f0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_40f4:
	/* 0x40f4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40f9:
	/* 0x40f9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_40fe:
	/* 0x40fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4103:
	/* 0x4103: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4108:
	/* 0x4108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410a:
	/* 0x410a: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_410e:
	/* 0x410e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4110:
	/* 0x4110: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4116:
	/* 0x4116: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4119:
	/* 0x4119: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_411b:
	/* 0x411b: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_4121:
	/* 0x4121: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4126:
	/* 0x4126: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_412c:
	/* 0x412c: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_4131:
	/* 0x4131: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4133:
	/* 0x4133: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4138:
	/* 0x4138: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_413a:
	/* 0x413a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_413d:
	/* 0x413d: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_4143:
	/* 0x4143: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4147:
	/* 0x4147: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_414d:
	/* 0x414d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4152:
	/* 0x4152: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4156:
	/* 0x4156: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4159:
	/* 0x4159: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_415e:
	/* 0x415e: jmp    4323 <trace_ret_kernel_write_tail+0x4323> */
	goto x86_l_4323;
x86_l_4163:
	/* 0x4163: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4166:
	/* 0x4166: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_416c:
	/* 0x416c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4170:
	/* 0x4170: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4175:
	/* 0x4175: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_417b:
	/* 0x417b: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_417f:
	/* 0x417f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4184:
	/* 0x4184: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4189:
	/* 0x4189: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_418e:
	/* 0x418e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4192:
	/* 0x4192: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4196:
	/* 0x4196: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_419b:
	/* 0x419b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419d:
	/* 0x419d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a1:
	/* 0x41a1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41a4:
	/* 0x41a4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41a9:
	/* 0x41a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41ae:
	/* 0x41ae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b2:
	/* 0x41b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b7:
	/* 0x41b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b9:
	/* 0x41b9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41bd:
	/* 0x41bd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41c2:
	/* 0x41c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41c7:
	/* 0x41c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41cc:
	/* 0x41cc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d0:
	/* 0x41d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d5:
	/* 0x41d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d7:
	/* 0x41d7: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41db:
	/* 0x41db: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_41df:
	/* 0x41df: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41e4:
	/* 0x41e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41e9:
	/* 0x41e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41ee:
	/* 0x41ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41f3:
	/* 0x41f3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_41f6:
	/* 0x41f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f8:
	/* 0x41f8: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41fd:
	/* 0x41fd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4202:
	/* 0x4202: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4206:
	/* 0x4206: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_420b:
	/* 0x420b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4210:
	/* 0x4210: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4215:
	/* 0x4215: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_421a:
	/* 0x421a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_421c:
	/* 0x421c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4221:
	/* 0x4221: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4224:
	/* 0x4224: je     43f1 <trace_ret_kernel_write_tail+0x43f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f1;
	}
x86_l_422a:
	/* 0x422a: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_422f:
	/* 0x422f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4232:
	/* 0x4232: je     43f1 <trace_ret_kernel_write_tail+0x43f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f1;
	}
x86_l_4238:
	/* 0x4238: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_423c:
	/* 0x423c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4241:
	/* 0x4241: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4246:
	/* 0x4246: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_424b:
	/* 0x424b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4250:
	/* 0x4250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4252:
	/* 0x4252: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4256:
	/* 0x4256: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4258:
	/* 0x4258: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_425e:
	/* 0x425e: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4260:
	/* 0x4260: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4262:
	/* 0x4262: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_4268:
	/* 0x4268: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_426d:
	/* 0x426d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4273:
	/* 0x4273: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4276:
	/* 0x4276: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4278:
	/* 0x4278: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_427d:
	/* 0x427d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427f:
	/* 0x427f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4282:
	/* 0x4282: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_4288:
	/* 0x4288: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_428b:
	/* 0x428b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4291:
	/* 0x4291: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4296:
	/* 0x4296: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4298:
	/* 0x4298: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429d:
	/* 0x429d: jmp    446d <trace_ret_kernel_write_tail+0x446d> */
	return 17517ULL;
x86_l_42a2:
	/* 0x42a2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_42a5:
	/* 0x42a5: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_42ab:
	/* 0x42ab: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42af:
	/* 0x42af: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_42b4:
	/* 0x42b4: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_42ba:
	/* 0x42ba: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42be:
	/* 0x42be: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42c3:
	/* 0x42c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42c8:
	/* 0x42c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42cd:
	/* 0x42cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42d1:
	/* 0x42d1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42d5:
	/* 0x42d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42da:
	/* 0x42da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42dc:
	/* 0x42dc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e0:
	/* 0x42e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42e3:
	/* 0x42e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42e8:
	/* 0x42e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42ed:
	/* 0x42ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42f1:
	/* 0x42f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42f6:
	/* 0x42f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f8:
	/* 0x42f8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42fc:
	/* 0x42fc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4301:
	/* 0x4301: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4306:
	/* 0x4306: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_430b:
	/* 0x430b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_430f:
	/* 0x430f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4314:
	/* 0x4314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4316:
	/* 0x4316: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431a:
	/* 0x431a: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_431e:
	/* 0x431e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4323:
	/* 0x4323: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4328:
	/* 0x4328: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_432d:
	/* 0x432d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4332:
	/* 0x4332: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4337:
	/* 0x4337: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_433c:
	/* 0x433c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433e:
	/* 0x433e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4343:
	/* 0x4343: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4348:
	/* 0x4348: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_434c:
	/* 0x434c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4351:
	/* 0x4351: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4356:
	/* 0x4356: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_435b:
	/* 0x435b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4360:
	/* 0x4360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4362:
	/* 0x4362: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4367:
	/* 0x4367: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_436a:
	/* 0x436a: je     4530 <trace_ret_kernel_write_tail+0x4530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17712ULL;
	}
x86_l_4370:
	/* 0x4370: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4375:
	/* 0x4375: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4378:
	/* 0x4378: je     4530 <trace_ret_kernel_write_tail+0x4530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17712ULL;
	}
x86_l_437e:
	/* 0x437e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4382:
	/* 0x4382: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4387:
	/* 0x4387: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_438c:
	/* 0x438c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4391:
	/* 0x4391: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4396:
	/* 0x4396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4398:
	/* 0x4398: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_439c:
	/* 0x439c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_439e:
	/* 0x439e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_43a4:
	/* 0x43a4: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_43a7:
	/* 0x43a7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43a9:
	/* 0x43a9: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_43af:
	/* 0x43af: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43b4:
	/* 0x43b4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_43ba:
	/* 0x43ba: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_43bf:
	/* 0x43bf: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_43c1:
	/* 0x43c1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_43c6:
	/* 0x43c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43c8:
	/* 0x43c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43cb:
	/* 0x43cb: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_43d1:
	/* 0x43d1: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_43d5:
	/* 0x43d5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_43db:
	/* 0x43db: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_43e0:
	/* 0x43e0: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_43e4:
	/* 0x43e4: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43e7:
	/* 0x43e7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43ec:
	/* 0x43ec: jmp    45b1 <trace_ret_kernel_write_tail+0x45b1> */
	return 17841ULL;
x86_l_43f1:
	/* 0x43f1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_43f4:
	/* 0x43f4: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_43fa:
	/* 0x43fa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43fe:
	/* 0x43fe: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4403:
	/* 0x4403: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_4409:
	/* 0x4409: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_440d:
	/* 0x440d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4412:
	/* 0x4412: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4417:
	/* 0x4417: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_441c:
	/* 0x441c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4420:
	/* 0x4420: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4424:
	/* 0x4424: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4429:
	/* 0x4429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_442b:
	/* 0x442b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_442f:
	/* 0x442f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4432:
	/* 0x4432: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4437:
	/* 0x4437: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_443c:
	/* 0x443c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4440:
	/* 0x4440: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4445:
	/* 0x4445: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4447:
	/* 0x4447: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_444b:
	/* 0x444b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4450:
	/* 0x4450: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4455:
	/* 0x4455: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_445a:
	/* 0x445a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 17502ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17502ULL: goto x86_l_445e;
	case 17507ULL: goto x86_l_4463;
	case 17509ULL: goto x86_l_4465;
	case 17513ULL: goto x86_l_4469;
	case 17517ULL: goto x86_l_446d;
	case 17522ULL: goto x86_l_4472;
	case 17527ULL: goto x86_l_4477;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17540ULL: goto x86_l_4484;
	case 17542ULL: goto x86_l_4486;
	case 17547ULL: goto x86_l_448b;
	case 17552ULL: goto x86_l_4490;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17571ULL: goto x86_l_44a3;
	case 17576ULL: goto x86_l_44a8;
	case 17578ULL: goto x86_l_44aa;
	case 17583ULL: goto x86_l_44af;
	case 17586ULL: goto x86_l_44b2;
	case 17592ULL: goto x86_l_44b8;
	case 17597ULL: goto x86_l_44bd;
	case 17600ULL: goto x86_l_44c0;
	case 17606ULL: goto x86_l_44c6;
	case 17610ULL: goto x86_l_44ca;
	case 17615ULL: goto x86_l_44cf;
	case 17620ULL: goto x86_l_44d4;
	case 17625ULL: goto x86_l_44d9;
	case 17630ULL: goto x86_l_44de;
	case 17632ULL: goto x86_l_44e0;
	case 17636ULL: goto x86_l_44e4;
	case 17638ULL: goto x86_l_44e6;
	case 17644ULL: goto x86_l_44ec;
	case 17646ULL: goto x86_l_44ee;
	case 17648ULL: goto x86_l_44f0;
	case 17654ULL: goto x86_l_44f6;
	case 17659ULL: goto x86_l_44fb;
	case 17665ULL: goto x86_l_4501;
	case 17668ULL: goto x86_l_4504;
	case 17670ULL: goto x86_l_4506;
	case 17675ULL: goto x86_l_450b;
	case 17677ULL: goto x86_l_450d;
	case 17680ULL: goto x86_l_4510;
	case 17686ULL: goto x86_l_4516;
	case 17689ULL: goto x86_l_4519;
	case 17695ULL: goto x86_l_451f;
	case 17700ULL: goto x86_l_4524;
	case 17702ULL: goto x86_l_4526;
	case 17707ULL: goto x86_l_452b;
	case 17712ULL: goto x86_l_4530;
	case 17715ULL: goto x86_l_4533;
	case 17721ULL: goto x86_l_4539;
	case 17725ULL: goto x86_l_453d;
	case 17730ULL: goto x86_l_4542;
	case 17736ULL: goto x86_l_4548;
	case 17740ULL: goto x86_l_454c;
	case 17745ULL: goto x86_l_4551;
	case 17750ULL: goto x86_l_4556;
	case 17755ULL: goto x86_l_455b;
	case 17759ULL: goto x86_l_455f;
	case 17763ULL: goto x86_l_4563;
	case 17768ULL: goto x86_l_4568;
	case 17770ULL: goto x86_l_456a;
	case 17774ULL: goto x86_l_456e;
	case 17777ULL: goto x86_l_4571;
	case 17782ULL: goto x86_l_4576;
	case 17787ULL: goto x86_l_457b;
	case 17791ULL: goto x86_l_457f;
	case 17796ULL: goto x86_l_4584;
	case 17798ULL: goto x86_l_4586;
	case 17802ULL: goto x86_l_458a;
	case 17807ULL: goto x86_l_458f;
	case 17812ULL: goto x86_l_4594;
	case 17817ULL: goto x86_l_4599;
	case 17821ULL: goto x86_l_459d;
	case 17826ULL: goto x86_l_45a2;
	case 17828ULL: goto x86_l_45a4;
	case 17832ULL: goto x86_l_45a8;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17846ULL: goto x86_l_45b6;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17861ULL: goto x86_l_45c5;
	case 17866ULL: goto x86_l_45ca;
	case 17868ULL: goto x86_l_45cc;
	case 17873ULL: goto x86_l_45d1;
	case 17878ULL: goto x86_l_45d6;
	case 17882ULL: goto x86_l_45da;
	case 17887ULL: goto x86_l_45df;
	case 17892ULL: goto x86_l_45e4;
	case 17897ULL: goto x86_l_45e9;
	case 17902ULL: goto x86_l_45ee;
	case 17904ULL: goto x86_l_45f0;
	case 17909ULL: goto x86_l_45f5;
	case 17912ULL: goto x86_l_45f8;
	case 17918ULL: goto x86_l_45fe;
	case 17923ULL: goto x86_l_4603;
	case 17926ULL: goto x86_l_4606;
	case 17932ULL: goto x86_l_460c;
	case 17936ULL: goto x86_l_4610;
	case 17941ULL: goto x86_l_4615;
	case 17946ULL: goto x86_l_461a;
	case 17951ULL: goto x86_l_461f;
	case 17956ULL: goto x86_l_4624;
	case 17958ULL: goto x86_l_4626;
	case 17962ULL: goto x86_l_462a;
	case 17964ULL: goto x86_l_462c;
	case 17970ULL: goto x86_l_4632;
	case 17973ULL: goto x86_l_4635;
	case 17975ULL: goto x86_l_4637;
	case 17981ULL: goto x86_l_463d;
	case 17986ULL: goto x86_l_4642;
	case 17992ULL: goto x86_l_4648;
	case 17997ULL: goto x86_l_464d;
	case 17999ULL: goto x86_l_464f;
	case 18004ULL: goto x86_l_4654;
	case 18006ULL: goto x86_l_4656;
	case 18009ULL: goto x86_l_4659;
	case 18015ULL: goto x86_l_465f;
	case 18019ULL: goto x86_l_4663;
	case 18025ULL: goto x86_l_4669;
	case 18030ULL: goto x86_l_466e;
	case 18034ULL: goto x86_l_4672;
	case 18037ULL: goto x86_l_4675;
	case 18042ULL: goto x86_l_467a;
	case 18047ULL: goto x86_l_467f;
	case 18054ULL: goto x86_l_4686;
	case 18057ULL: goto x86_l_4689;
	case 18062ULL: goto x86_l_468e;
	case 18065ULL: goto x86_l_4691;
	case 18068ULL: goto x86_l_4694;
	case 18070ULL: goto x86_l_4696;
	case 18072ULL: goto x86_l_4698;
	case 18077ULL: goto x86_l_469d;
	case 18080ULL: goto x86_l_46a0;
	case 18087ULL: goto x86_l_46a7;
	case 18093ULL: goto x86_l_46ad;
	case 18098ULL: goto x86_l_46b2;
	case 18101ULL: goto x86_l_46b5;
	case 18107ULL: goto x86_l_46bb;
	case 18111ULL: goto x86_l_46bf;
	case 18116ULL: goto x86_l_46c4;
	case 18122ULL: goto x86_l_46ca;
	case 18126ULL: goto x86_l_46ce;
	case 18131ULL: goto x86_l_46d3;
	case 18136ULL: goto x86_l_46d8;
	case 18141ULL: goto x86_l_46dd;
	case 18145ULL: goto x86_l_46e1;
	case 18149ULL: goto x86_l_46e5;
	case 18154ULL: goto x86_l_46ea;
	case 18156ULL: goto x86_l_46ec;
	case 18160ULL: goto x86_l_46f0;
	case 18163ULL: goto x86_l_46f3;
	case 18168ULL: goto x86_l_46f8;
	case 18173ULL: goto x86_l_46fd;
	case 18177ULL: goto x86_l_4701;
	case 18182ULL: goto x86_l_4706;
	case 18184ULL: goto x86_l_4708;
	case 18188ULL: goto x86_l_470c;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18207ULL: goto x86_l_471f;
	case 18212ULL: goto x86_l_4724;
	case 18214ULL: goto x86_l_4726;
	case 18218ULL: goto x86_l_472a;
	case 18222ULL: goto x86_l_472e;
	case 18227ULL: goto x86_l_4733;
	case 18232ULL: goto x86_l_4738;
	case 18237ULL: goto x86_l_473d;
	case 18242ULL: goto x86_l_4742;
	case 18245ULL: goto x86_l_4745;
	case 18247ULL: goto x86_l_4747;
	case 18252ULL: goto x86_l_474c;
	case 18257ULL: goto x86_l_4751;
	case 18261ULL: goto x86_l_4755;
	case 18266ULL: goto x86_l_475a;
	case 18271ULL: goto x86_l_475f;
	case 18276ULL: goto x86_l_4764;
	case 18281ULL: goto x86_l_4769;
	case 18283ULL: goto x86_l_476b;
	case 18288ULL: goto x86_l_4770;
	case 18291ULL: goto x86_l_4773;
	case 18297ULL: goto x86_l_4779;
	case 18302ULL: goto x86_l_477e;
	case 18305ULL: goto x86_l_4781;
	case 18311ULL: goto x86_l_4787;
	case 18315ULL: goto x86_l_478b;
	case 18320ULL: goto x86_l_4790;
	case 18325ULL: goto x86_l_4795;
	case 18330ULL: goto x86_l_479a;
	case 18335ULL: goto x86_l_479f;
	case 18337ULL: goto x86_l_47a1;
	case 18341ULL: goto x86_l_47a5;
	case 18343ULL: goto x86_l_47a7;
	case 18349ULL: goto x86_l_47ad;
	case 18351ULL: goto x86_l_47af;
	case 18353ULL: goto x86_l_47b1;
	case 18359ULL: goto x86_l_47b7;
	case 18364ULL: goto x86_l_47bc;
	case 18370ULL: goto x86_l_47c2;
	case 18373ULL: goto x86_l_47c5;
	case 18375ULL: goto x86_l_47c7;
	case 18380ULL: goto x86_l_47cc;
	case 18382ULL: goto x86_l_47ce;
	case 18385ULL: goto x86_l_47d1;
	case 18391ULL: goto x86_l_47d7;
	case 18394ULL: goto x86_l_47da;
	case 18400ULL: goto x86_l_47e0;
	case 18405ULL: goto x86_l_47e5;
	case 18407ULL: goto x86_l_47e7;
	case 18412ULL: goto x86_l_47ec;
	case 18417ULL: goto x86_l_47f1;
	case 18424ULL: goto x86_l_47f8;
	case 18426ULL: goto x86_l_47fa;
	case 18431ULL: goto x86_l_47ff;
	case 18436ULL: goto x86_l_4804;
	case 18439ULL: goto x86_l_4807;
	case 18442ULL: goto x86_l_480a;
	case 18444ULL: goto x86_l_480c;
	case 18446ULL: goto x86_l_480e;
	case 18451ULL: goto x86_l_4813;
	case 18454ULL: goto x86_l_4816;
	case 18460ULL: goto x86_l_481c;
	case 18466ULL: goto x86_l_4822;
	case 18471ULL: goto x86_l_4827;
	case 18478ULL: goto x86_l_482e;
	case 18480ULL: goto x86_l_4830;
	case 18485ULL: goto x86_l_4835;
	case 18490ULL: goto x86_l_483a;
	case 18493ULL: goto x86_l_483d;
	case 18496ULL: goto x86_l_4840;
	case 18498ULL: goto x86_l_4842;
	case 18500ULL: goto x86_l_4844;
	case 18505ULL: goto x86_l_4849;
	case 18508ULL: goto x86_l_484c;
	case 18514ULL: goto x86_l_4852;
	case 18520ULL: goto x86_l_4858;
	case 18525ULL: goto x86_l_485d;
	case 18528ULL: goto x86_l_4860;
	case 18534ULL: goto x86_l_4866;
	case 18538ULL: goto x86_l_486a;
	case 18543ULL: goto x86_l_486f;
	case 18549ULL: goto x86_l_4875;
	case 18553ULL: goto x86_l_4879;
	case 18558ULL: goto x86_l_487e;
	case 18563ULL: goto x86_l_4883;
	case 18568ULL: goto x86_l_4888;
	case 18572ULL: goto x86_l_488c;
	case 18576ULL: goto x86_l_4890;
	case 18581ULL: goto x86_l_4895;
	case 18583ULL: goto x86_l_4897;
	case 18587ULL: goto x86_l_489b;
	case 18590ULL: goto x86_l_489e;
	case 18595ULL: goto x86_l_48a3;
	case 18600ULL: goto x86_l_48a8;
	case 18604ULL: goto x86_l_48ac;
	case 18609ULL: goto x86_l_48b1;
	case 18611ULL: goto x86_l_48b3;
	case 18615ULL: goto x86_l_48b7;
	case 18620ULL: goto x86_l_48bc;
	case 18625ULL: goto x86_l_48c1;
	case 18630ULL: goto x86_l_48c6;
	case 18634ULL: goto x86_l_48ca;
	case 18639ULL: goto x86_l_48cf;
	case 18641ULL: goto x86_l_48d1;
	case 18645ULL: goto x86_l_48d5;
	case 18649ULL: goto x86_l_48d9;
	case 18654ULL: goto x86_l_48de;
	case 18659ULL: goto x86_l_48e3;
	case 18664ULL: goto x86_l_48e8;
	case 18669ULL: goto x86_l_48ed;
	case 18674ULL: goto x86_l_48f2;
	case 18679ULL: goto x86_l_48f7;
	case 18681ULL: goto x86_l_48f9;
	case 18686ULL: goto x86_l_48fe;
	case 18691ULL: goto x86_l_4903;
	case 18695ULL: goto x86_l_4907;
	case 18700ULL: goto x86_l_490c;
	case 18705ULL: goto x86_l_4911;
	case 18710ULL: goto x86_l_4916;
	case 18715ULL: goto x86_l_491b;
	case 18717ULL: goto x86_l_491d;
	case 18722ULL: goto x86_l_4922;
	case 18725ULL: goto x86_l_4925;
	case 18731ULL: goto x86_l_492b;
	case 18736ULL: goto x86_l_4930;
	case 18739ULL: goto x86_l_4933;
	case 18745ULL: goto x86_l_4939;
	case 18749ULL: goto x86_l_493d;
	case 18754ULL: goto x86_l_4942;
	case 18759ULL: goto x86_l_4947;
	case 18764ULL: goto x86_l_494c;
	case 18769ULL: goto x86_l_4951;
	case 18771ULL: goto x86_l_4953;
	case 18775ULL: goto x86_l_4957;
	case 18777ULL: goto x86_l_4959;
	case 18783ULL: goto x86_l_495f;
	case 18786ULL: goto x86_l_4962;
	case 18788ULL: goto x86_l_4964;
	case 18794ULL: goto x86_l_496a;
	case 18799ULL: goto x86_l_496f;
	case 18805ULL: goto x86_l_4975;
	case 18810ULL: goto x86_l_497a;
	case 18812ULL: goto x86_l_497c;
	case 18817ULL: goto x86_l_4981;
	case 18819ULL: goto x86_l_4983;
	case 18822ULL: goto x86_l_4986;
	case 18828ULL: goto x86_l_498c;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18843ULL: goto x86_l_499b;
	case 18847ULL: goto x86_l_499f;
	case 18850ULL: goto x86_l_49a2;
	case 18855ULL: goto x86_l_49a7;
	case 18860ULL: goto x86_l_49ac;
	case 18863ULL: goto x86_l_49af;
	case 18869ULL: goto x86_l_49b5;
	case 18873ULL: goto x86_l_49b9;
	case 18878ULL: goto x86_l_49be;
	case 18884ULL: goto x86_l_49c4;
	case 18888ULL: goto x86_l_49c8;
	case 18893ULL: goto x86_l_49cd;
	case 18898ULL: goto x86_l_49d2;
	case 18903ULL: goto x86_l_49d7;
	case 18907ULL: goto x86_l_49db;
	case 18911ULL: goto x86_l_49df;
	case 18916ULL: goto x86_l_49e4;
	case 18918ULL: goto x86_l_49e6;
	case 18922ULL: goto x86_l_49ea;
	case 18925ULL: goto x86_l_49ed;
	case 18930ULL: goto x86_l_49f2;
	case 18935ULL: goto x86_l_49f7;
	case 18939ULL: goto x86_l_49fb;
	case 18944ULL: goto x86_l_4a00;
	case 18946ULL: goto x86_l_4a02;
	case 18950ULL: goto x86_l_4a06;
	case 18955ULL: goto x86_l_4a0b;
	case 18960ULL: goto x86_l_4a10;
	case 18965ULL: goto x86_l_4a15;
	case 18969ULL: goto x86_l_4a19;
	case 18974ULL: goto x86_l_4a1e;
	case 18976ULL: goto x86_l_4a20;
	case 18980ULL: goto x86_l_4a24;
	case 18984ULL: goto x86_l_4a28;
	case 18989ULL: goto x86_l_4a2d;
	case 18994ULL: goto x86_l_4a32;
	case 18999ULL: goto x86_l_4a37;
	case 19004ULL: goto x86_l_4a3c;
	case 19007ULL: goto x86_l_4a3f;
	case 19009ULL: goto x86_l_4a41;
	case 19014ULL: goto x86_l_4a46;
	case 19019ULL: goto x86_l_4a4b;
	case 19023ULL: goto x86_l_4a4f;
	case 19028ULL: goto x86_l_4a54;
	case 19033ULL: goto x86_l_4a59;
	case 19038ULL: goto x86_l_4a5e;
	case 19043ULL: goto x86_l_4a63;
	case 19045ULL: goto x86_l_4a65;
	case 19050ULL: goto x86_l_4a6a;
	case 19053ULL: goto x86_l_4a6d;
	case 19059ULL: goto x86_l_4a73;
	case 19064ULL: goto x86_l_4a78;
	case 19067ULL: goto x86_l_4a7b;
	case 19073ULL: goto x86_l_4a81;
	case 19077ULL: goto x86_l_4a85;
	case 19082ULL: goto x86_l_4a8a;
	case 19087ULL: goto x86_l_4a8f;
	case 19092ULL: goto x86_l_4a94;
	case 19097ULL: goto x86_l_4a99;
	case 19099ULL: goto x86_l_4a9b;
	case 19103ULL: goto x86_l_4a9f;
	case 19105ULL: goto x86_l_4aa1;
	case 19111ULL: goto x86_l_4aa7;
	case 19113ULL: goto x86_l_4aa9;
	case 19115ULL: goto x86_l_4aab;
	case 19121ULL: goto x86_l_4ab1;
	case 19126ULL: goto x86_l_4ab6;
	case 19132ULL: goto x86_l_4abc;
	case 19135ULL: goto x86_l_4abf;
	case 19137ULL: goto x86_l_4ac1;
	case 19142ULL: goto x86_l_4ac6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_445e:
	/* 0x445e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4463:
	/* 0x4463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4465:
	/* 0x4465: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4469:
	/* 0x4469: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_446d:
	/* 0x446d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4472:
	/* 0x4472: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4477:
	/* 0x4477: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_447c:
	/* 0x447c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4481:
	/* 0x4481: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4484:
	/* 0x4484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4486:
	/* 0x4486: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_448b:
	/* 0x448b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4490:
	/* 0x4490: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4494:
	/* 0x4494: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4499:
	/* 0x4499: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_449e:
	/* 0x449e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44a3:
	/* 0x44a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44a8:
	/* 0x44a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44aa:
	/* 0x44aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44af:
	/* 0x44af: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_44b2:
	/* 0x44b2: je     46b2 <trace_ret_kernel_write_tail+0x46b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b2;
	}
x86_l_44b8:
	/* 0x44b8: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44bd:
	/* 0x44bd: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_44c0:
	/* 0x44c0: je     46b2 <trace_ret_kernel_write_tail+0x46b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b2;
	}
x86_l_44c6:
	/* 0x44c6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_44ca:
	/* 0x44ca: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44cf:
	/* 0x44cf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_44d4:
	/* 0x44d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44d9:
	/* 0x44d9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44de:
	/* 0x44de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44e0:
	/* 0x44e0: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_44e4:
	/* 0x44e4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44e6:
	/* 0x44e6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44ec:
	/* 0x44ec: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_44ee:
	/* 0x44ee: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44f0:
	/* 0x44f0: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_44f6:
	/* 0x44f6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44fb:
	/* 0x44fb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4501:
	/* 0x4501: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4504:
	/* 0x4504: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4506:
	/* 0x4506: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_450b:
	/* 0x450b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450d:
	/* 0x450d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4510:
	/* 0x4510: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_4516:
	/* 0x4516: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4519:
	/* 0x4519: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_451f:
	/* 0x451f: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4524:
	/* 0x4524: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4526:
	/* 0x4526: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_452b:
	/* 0x452b: jmp    472e <trace_ret_kernel_write_tail+0x472e> */
	goto x86_l_472e;
x86_l_4530:
	/* 0x4530: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4533:
	/* 0x4533: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_4539:
	/* 0x4539: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_453d:
	/* 0x453d: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4542:
	/* 0x4542: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_4548:
	/* 0x4548: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_454c:
	/* 0x454c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4551:
	/* 0x4551: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4556:
	/* 0x4556: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_455b:
	/* 0x455b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455f:
	/* 0x455f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4563:
	/* 0x4563: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4568:
	/* 0x4568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456a:
	/* 0x456a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_456e:
	/* 0x456e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4571:
	/* 0x4571: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4576:
	/* 0x4576: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_457b:
	/* 0x457b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457f:
	/* 0x457f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4584:
	/* 0x4584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4586:
	/* 0x4586: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_458a:
	/* 0x458a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_458f:
	/* 0x458f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4594:
	/* 0x4594: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4599:
	/* 0x4599: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_459d:
	/* 0x459d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45a2:
	/* 0x45a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a4:
	/* 0x45a4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a8:
	/* 0x45a8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45ac:
	/* 0x45ac: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_45b1:
	/* 0x45b1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45b6:
	/* 0x45b6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45bb:
	/* 0x45bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45c0:
	/* 0x45c0: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_45c5:
	/* 0x45c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45ca:
	/* 0x45ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45cc:
	/* 0x45cc: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45d1:
	/* 0x45d1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45d6:
	/* 0x45d6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_45da:
	/* 0x45da: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45df:
	/* 0x45df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45e4:
	/* 0x45e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45e9:
	/* 0x45e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45ee:
	/* 0x45ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f0:
	/* 0x45f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45f5:
	/* 0x45f5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_45f8:
	/* 0x45f8: je     485d <trace_ret_kernel_write_tail+0x485d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485d;
	}
x86_l_45fe:
	/* 0x45fe: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4603:
	/* 0x4603: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4606:
	/* 0x4606: je     485d <trace_ret_kernel_write_tail+0x485d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485d;
	}
x86_l_460c:
	/* 0x460c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4610:
	/* 0x4610: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4615:
	/* 0x4615: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_461a:
	/* 0x461a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_461f:
	/* 0x461f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4624:
	/* 0x4624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4626:
	/* 0x4626: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_462a:
	/* 0x462a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_462c:
	/* 0x462c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4632:
	/* 0x4632: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4635:
	/* 0x4635: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4637:
	/* 0x4637: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_463d:
	/* 0x463d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4642:
	/* 0x4642: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4648:
	/* 0x4648: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_464d:
	/* 0x464d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_464f:
	/* 0x464f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4654:
	/* 0x4654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4656:
	/* 0x4656: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4659:
	/* 0x4659: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_465f:
	/* 0x465f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4663:
	/* 0x4663: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4669:
	/* 0x4669: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_466e:
	/* 0x466e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4672:
	/* 0x4672: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4675:
	/* 0x4675: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_467a:
	/* 0x467a: jmp    48de <trace_ret_kernel_write_tail+0x48de> */
	goto x86_l_48de;
x86_l_467f:
	/* 0x467f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_4686:
	/* 0x4686: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4689:
	/* 0x4689: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_468e:
	/* 0x468e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4691:
	/* 0x4691: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4694:
	/* 0x4694: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4696:
	/* 0x4696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4698:
	/* 0x4698: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_469d:
	/* 0x469d: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_46a0:
	/* 0x46a0: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_46a7:
	/* 0x46a7: jae    39a2 <trace_ret_kernel_write_tail+0x39a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14754ULL;
	}
x86_l_46ad:
	/* 0x46ad: jmp    39dc <trace_ret_kernel_write_tail+0x39dc> */
	return 14812ULL;
x86_l_46b2:
	/* 0x46b2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_46b5:
	/* 0x46b5: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_46bb:
	/* 0x46bb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46bf:
	/* 0x46bf: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_46c4:
	/* 0x46c4: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_46ca:
	/* 0x46ca: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46ce:
	/* 0x46ce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d3:
	/* 0x46d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46d8:
	/* 0x46d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46dd:
	/* 0x46dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e1:
	/* 0x46e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46e5:
	/* 0x46e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ea:
	/* 0x46ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ec:
	/* 0x46ec: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46f0:
	/* 0x46f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46f3:
	/* 0x46f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46f8:
	/* 0x46f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46fd:
	/* 0x46fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4701:
	/* 0x4701: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4706:
	/* 0x4706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4708:
	/* 0x4708: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_470c:
	/* 0x470c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4711:
	/* 0x4711: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4716:
	/* 0x4716: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_471b:
	/* 0x471b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_471f:
	/* 0x471f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4724:
	/* 0x4724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4726:
	/* 0x4726: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472a:
	/* 0x472a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_472e:
	/* 0x472e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4733:
	/* 0x4733: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4738:
	/* 0x4738: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_473d:
	/* 0x473d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4742:
	/* 0x4742: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4745:
	/* 0x4745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4747:
	/* 0x4747: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_474c:
	/* 0x474c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4751:
	/* 0x4751: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4755:
	/* 0x4755: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_475a:
	/* 0x475a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_475f:
	/* 0x475f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4764:
	/* 0x4764: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4769:
	/* 0x4769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_476b:
	/* 0x476b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4770:
	/* 0x4770: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4773:
	/* 0x4773: je     49ac <trace_ret_kernel_write_tail+0x49ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49ac;
	}
x86_l_4779:
	/* 0x4779: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_477e:
	/* 0x477e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4781:
	/* 0x4781: je     49ac <trace_ret_kernel_write_tail+0x49ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49ac;
	}
x86_l_4787:
	/* 0x4787: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_478b:
	/* 0x478b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4790:
	/* 0x4790: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4795:
	/* 0x4795: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_479a:
	/* 0x479a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_479f:
	/* 0x479f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47a1:
	/* 0x47a1: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_47a5:
	/* 0x47a5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_47a7:
	/* 0x47a7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_47ad:
	/* 0x47ad: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_47af:
	/* 0x47af: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_47b1:
	/* 0x47b1: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_47b7:
	/* 0x47b7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47bc:
	/* 0x47bc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_47c2:
	/* 0x47c2: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_47c5:
	/* 0x47c5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_47c7:
	/* 0x47c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_47cc:
	/* 0x47cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ce:
	/* 0x47ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_47d1:
	/* 0x47d1: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_47d7:
	/* 0x47d7: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_47da:
	/* 0x47da: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_47e0:
	/* 0x47e0: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_47e5:
	/* 0x47e5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_47e7:
	/* 0x47e7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47ec:
	/* 0x47ec: jmp    4a28 <trace_ret_kernel_write_tail+0x4a28> */
	goto x86_l_4a28;
x86_l_47f1:
	/* 0x47f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_47f8:
	/* 0x47f8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47fa:
	/* 0x47fa: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_47ff:
	/* 0x47ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4804:
	/* 0x4804: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4807:
	/* 0x4807: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_480a:
	/* 0x480a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_480c:
	/* 0x480c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_480e:
	/* 0x480e: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4813:
	/* 0x4813: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4816:
	/* 0x4816: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_481c:
	/* 0x481c: jae    3587 <trace_ret_kernel_write_tail+0x3587> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13703ULL;
	}
x86_l_4822:
	/* 0x4822: jmp    35c3 <trace_ret_kernel_write_tail+0x35c3> */
	return 13763ULL;
x86_l_4827:
	/* 0x4827: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_482e:
	/* 0x482e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4830:
	/* 0x4830: lea    rbp,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4835:
	/* 0x4835: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_483a:
	/* 0x483a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_483d:
	/* 0x483d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4840:
	/* 0x4840: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4842:
	/* 0x4842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4844:
	/* 0x4844: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4849:
	/* 0x4849: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_484c:
	/* 0x484c: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_4852:
	/* 0x4852: jae    36ab <trace_ret_kernel_write_tail+0x36ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13995ULL;
	}
x86_l_4858:
	/* 0x4858: jmp    36e7 <trace_ret_kernel_write_tail+0x36e7> */
	return 14055ULL;
x86_l_485d:
	/* 0x485d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4860:
	/* 0x4860: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_4866:
	/* 0x4866: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_486a:
	/* 0x486a: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_486f:
	/* 0x486f: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_4875:
	/* 0x4875: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4879:
	/* 0x4879: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487e:
	/* 0x487e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4883:
	/* 0x4883: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4888:
	/* 0x4888: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_488c:
	/* 0x488c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4890:
	/* 0x4890: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4895:
	/* 0x4895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4897:
	/* 0x4897: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_489b:
	/* 0x489b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_489e:
	/* 0x489e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48a3:
	/* 0x48a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48a8:
	/* 0x48a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ac:
	/* 0x48ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48b1:
	/* 0x48b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48b3:
	/* 0x48b3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48b7:
	/* 0x48b7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48bc:
	/* 0x48bc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48c1:
	/* 0x48c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48c6:
	/* 0x48c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ca:
	/* 0x48ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48cf:
	/* 0x48cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d1:
	/* 0x48d1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48d5:
	/* 0x48d5: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48d9:
	/* 0x48d9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48de:
	/* 0x48de: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48e3:
	/* 0x48e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48e8:
	/* 0x48e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48ed:
	/* 0x48ed: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48f2:
	/* 0x48f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48f7:
	/* 0x48f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f9:
	/* 0x48f9: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48fe:
	/* 0x48fe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4903:
	/* 0x4903: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4907:
	/* 0x4907: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_490c:
	/* 0x490c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4911:
	/* 0x4911: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4916:
	/* 0x4916: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_491b:
	/* 0x491b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491d:
	/* 0x491d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4922:
	/* 0x4922: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4925:
	/* 0x4925: je     4aeb <trace_ret_kernel_write_tail+0x4aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19179ULL;
	}
x86_l_492b:
	/* 0x492b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4930:
	/* 0x4930: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4933:
	/* 0x4933: je     4aeb <trace_ret_kernel_write_tail+0x4aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19179ULL;
	}
x86_l_4939:
	/* 0x4939: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_493d:
	/* 0x493d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4942:
	/* 0x4942: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4947:
	/* 0x4947: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_494c:
	/* 0x494c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4951:
	/* 0x4951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4953:
	/* 0x4953: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4957:
	/* 0x4957: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4959:
	/* 0x4959: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_495f:
	/* 0x495f: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4962:
	/* 0x4962: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4964:
	/* 0x4964: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_496a:
	/* 0x496a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_496f:
	/* 0x496f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4975:
	/* 0x4975: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_497a:
	/* 0x497a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_497c:
	/* 0x497c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4981:
	/* 0x4981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4983:
	/* 0x4983: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4986:
	/* 0x4986: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_498c:
	/* 0x498c: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4990:
	/* 0x4990: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4996:
	/* 0x4996: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_499b:
	/* 0x499b: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_499f:
	/* 0x499f: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_49a2:
	/* 0x49a2: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a7:
	/* 0x49a7: jmp    4b6c <trace_ret_kernel_write_tail+0x4b6c> */
	return 19308ULL;
x86_l_49ac:
	/* 0x49ac: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_49af:
	/* 0x49af: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_49b5:
	/* 0x49b5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b9:
	/* 0x49b9: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_49be:
	/* 0x49be: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_49c4:
	/* 0x49c4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49c8:
	/* 0x49c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49cd:
	/* 0x49cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49d2:
	/* 0x49d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49d7:
	/* 0x49d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49db:
	/* 0x49db: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49df:
	/* 0x49df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49e4:
	/* 0x49e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49e6:
	/* 0x49e6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ea:
	/* 0x49ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49ed:
	/* 0x49ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49f2:
	/* 0x49f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49f7:
	/* 0x49f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49fb:
	/* 0x49fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a00:
	/* 0x4a00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a02:
	/* 0x4a02: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a06:
	/* 0x4a06: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a0b:
	/* 0x4a0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a10:
	/* 0x4a10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a15:
	/* 0x4a15: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a19:
	/* 0x4a19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a1e:
	/* 0x4a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a20:
	/* 0x4a20: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a24:
	/* 0x4a24: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a28:
	/* 0x4a28: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a2d:
	/* 0x4a2d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a32:
	/* 0x4a32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a37:
	/* 0x4a37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a3c:
	/* 0x4a3c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4a3f:
	/* 0x4a3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a41:
	/* 0x4a41: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a46:
	/* 0x4a46: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a4b:
	/* 0x4a4b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a4f:
	/* 0x4a4f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a54:
	/* 0x4a54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a59:
	/* 0x4a59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a5e:
	/* 0x4a5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a63:
	/* 0x4a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a65:
	/* 0x4a65: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a6a:
	/* 0x4a6a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4a6d:
	/* 0x4a6d: je     4c3a <trace_ret_kernel_write_tail+0x4c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19514ULL;
	}
x86_l_4a73:
	/* 0x4a73: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a78:
	/* 0x4a78: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4a7b:
	/* 0x4a7b: je     4c3a <trace_ret_kernel_write_tail+0x4c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19514ULL;
	}
x86_l_4a81:
	/* 0x4a81: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a85:
	/* 0x4a85: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a8a:
	/* 0x4a8a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4a8f:
	/* 0x4a8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a94:
	/* 0x4a94: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4a99:
	/* 0x4a99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9b:
	/* 0x4a9b: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4a9f:
	/* 0x4a9f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4aa1:
	/* 0x4aa1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4aa7:
	/* 0x4aa7: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4aa9:
	/* 0x4aa9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4aab:
	/* 0x4aab: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_4ab1:
	/* 0x4ab1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ab6:
	/* 0x4ab6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4abc:
	/* 0x4abc: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4abf:
	/* 0x4abf: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4ac1:
	/* 0x4ac1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4ac6:
	/* 0x4ac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 19144ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19144ULL: goto x86_l_4ac8;
	case 19147ULL: goto x86_l_4acb;
	case 19153ULL: goto x86_l_4ad1;
	case 19156ULL: goto x86_l_4ad4;
	case 19162ULL: goto x86_l_4ada;
	case 19167ULL: goto x86_l_4adf;
	case 19169ULL: goto x86_l_4ae1;
	case 19174ULL: goto x86_l_4ae6;
	case 19179ULL: goto x86_l_4aeb;
	case 19182ULL: goto x86_l_4aee;
	case 19188ULL: goto x86_l_4af4;
	case 19192ULL: goto x86_l_4af8;
	case 19197ULL: goto x86_l_4afd;
	case 19203ULL: goto x86_l_4b03;
	case 19207ULL: goto x86_l_4b07;
	case 19212ULL: goto x86_l_4b0c;
	case 19217ULL: goto x86_l_4b11;
	case 19222ULL: goto x86_l_4b16;
	case 19226ULL: goto x86_l_4b1a;
	case 19230ULL: goto x86_l_4b1e;
	case 19235ULL: goto x86_l_4b23;
	case 19237ULL: goto x86_l_4b25;
	case 19241ULL: goto x86_l_4b29;
	case 19244ULL: goto x86_l_4b2c;
	case 19249ULL: goto x86_l_4b31;
	case 19254ULL: goto x86_l_4b36;
	case 19258ULL: goto x86_l_4b3a;
	case 19263ULL: goto x86_l_4b3f;
	case 19265ULL: goto x86_l_4b41;
	case 19269ULL: goto x86_l_4b45;
	case 19274ULL: goto x86_l_4b4a;
	case 19279ULL: goto x86_l_4b4f;
	case 19284ULL: goto x86_l_4b54;
	case 19288ULL: goto x86_l_4b58;
	case 19293ULL: goto x86_l_4b5d;
	case 19295ULL: goto x86_l_4b5f;
	case 19299ULL: goto x86_l_4b63;
	case 19303ULL: goto x86_l_4b67;
	case 19308ULL: goto x86_l_4b6c;
	case 19313ULL: goto x86_l_4b71;
	case 19318ULL: goto x86_l_4b76;
	case 19323ULL: goto x86_l_4b7b;
	case 19328ULL: goto x86_l_4b80;
	case 19333ULL: goto x86_l_4b85;
	case 19335ULL: goto x86_l_4b87;
	case 19340ULL: goto x86_l_4b8c;
	case 19345ULL: goto x86_l_4b91;
	case 19349ULL: goto x86_l_4b95;
	case 19354ULL: goto x86_l_4b9a;
	case 19359ULL: goto x86_l_4b9f;
	case 19364ULL: goto x86_l_4ba4;
	case 19369ULL: goto x86_l_4ba9;
	case 19371ULL: goto x86_l_4bab;
	case 19376ULL: goto x86_l_4bb0;
	case 19379ULL: goto x86_l_4bb3;
	case 19385ULL: goto x86_l_4bb9;
	case 19390ULL: goto x86_l_4bbe;
	case 19393ULL: goto x86_l_4bc1;
	case 19399ULL: goto x86_l_4bc7;
	case 19403ULL: goto x86_l_4bcb;
	case 19408ULL: goto x86_l_4bd0;
	case 19413ULL: goto x86_l_4bd5;
	case 19418ULL: goto x86_l_4bda;
	case 19423ULL: goto x86_l_4bdf;
	case 19425ULL: goto x86_l_4be1;
	case 19429ULL: goto x86_l_4be5;
	case 19431ULL: goto x86_l_4be7;
	case 19437ULL: goto x86_l_4bed;
	case 19440ULL: goto x86_l_4bf0;
	case 19442ULL: goto x86_l_4bf2;
	case 19448ULL: goto x86_l_4bf8;
	case 19453ULL: goto x86_l_4bfd;
	case 19459ULL: goto x86_l_4c03;
	case 19464ULL: goto x86_l_4c08;
	case 19466ULL: goto x86_l_4c0a;
	case 19471ULL: goto x86_l_4c0f;
	case 19473ULL: goto x86_l_4c11;
	case 19476ULL: goto x86_l_4c14;
	case 19482ULL: goto x86_l_4c1a;
	case 19486ULL: goto x86_l_4c1e;
	case 19492ULL: goto x86_l_4c24;
	case 19497ULL: goto x86_l_4c29;
	case 19501ULL: goto x86_l_4c2d;
	case 19504ULL: goto x86_l_4c30;
	case 19509ULL: goto x86_l_4c35;
	case 19514ULL: goto x86_l_4c3a;
	case 19517ULL: goto x86_l_4c3d;
	case 19523ULL: goto x86_l_4c43;
	case 19527ULL: goto x86_l_4c47;
	case 19532ULL: goto x86_l_4c4c;
	case 19538ULL: goto x86_l_4c52;
	case 19542ULL: goto x86_l_4c56;
	case 19547ULL: goto x86_l_4c5b;
	case 19552ULL: goto x86_l_4c60;
	case 19557ULL: goto x86_l_4c65;
	case 19561ULL: goto x86_l_4c69;
	case 19565ULL: goto x86_l_4c6d;
	case 19570ULL: goto x86_l_4c72;
	case 19572ULL: goto x86_l_4c74;
	case 19576ULL: goto x86_l_4c78;
	case 19579ULL: goto x86_l_4c7b;
	case 19584ULL: goto x86_l_4c80;
	case 19589ULL: goto x86_l_4c85;
	case 19593ULL: goto x86_l_4c89;
	case 19598ULL: goto x86_l_4c8e;
	case 19600ULL: goto x86_l_4c90;
	case 19604ULL: goto x86_l_4c94;
	case 19609ULL: goto x86_l_4c99;
	case 19614ULL: goto x86_l_4c9e;
	case 19619ULL: goto x86_l_4ca3;
	case 19623ULL: goto x86_l_4ca7;
	case 19628ULL: goto x86_l_4cac;
	case 19630ULL: goto x86_l_4cae;
	case 19634ULL: goto x86_l_4cb2;
	case 19638ULL: goto x86_l_4cb6;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19653ULL: goto x86_l_4cc5;
	case 19658ULL: goto x86_l_4cca;
	case 19661ULL: goto x86_l_4ccd;
	case 19663ULL: goto x86_l_4ccf;
	case 19668ULL: goto x86_l_4cd4;
	case 19673ULL: goto x86_l_4cd9;
	case 19677ULL: goto x86_l_4cdd;
	case 19682ULL: goto x86_l_4ce2;
	case 19687ULL: goto x86_l_4ce7;
	case 19692ULL: goto x86_l_4cec;
	case 19697ULL: goto x86_l_4cf1;
	case 19699ULL: goto x86_l_4cf3;
	case 19704ULL: goto x86_l_4cf8;
	case 19707ULL: goto x86_l_4cfb;
	case 19713ULL: goto x86_l_4d01;
	case 19718ULL: goto x86_l_4d06;
	case 19721ULL: goto x86_l_4d09;
	case 19727ULL: goto x86_l_4d0f;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19741ULL: goto x86_l_4d1d;
	case 19746ULL: goto x86_l_4d22;
	case 19751ULL: goto x86_l_4d27;
	case 19753ULL: goto x86_l_4d29;
	case 19757ULL: goto x86_l_4d2d;
	case 19759ULL: goto x86_l_4d2f;
	case 19765ULL: goto x86_l_4d35;
	case 19767ULL: goto x86_l_4d37;
	case 19769ULL: goto x86_l_4d39;
	case 19775ULL: goto x86_l_4d3f;
	case 19780ULL: goto x86_l_4d44;
	case 19786ULL: goto x86_l_4d4a;
	case 19789ULL: goto x86_l_4d4d;
	case 19791ULL: goto x86_l_4d4f;
	case 19796ULL: goto x86_l_4d54;
	case 19798ULL: goto x86_l_4d56;
	case 19801ULL: goto x86_l_4d59;
	case 19807ULL: goto x86_l_4d5f;
	case 19810ULL: goto x86_l_4d62;
	case 19816ULL: goto x86_l_4d68;
	case 19821ULL: goto x86_l_4d6d;
	case 19823ULL: goto x86_l_4d6f;
	case 19828ULL: goto x86_l_4d74;
	case 19833ULL: goto x86_l_4d79;
	case 19836ULL: goto x86_l_4d7c;
	case 19842ULL: goto x86_l_4d82;
	case 19846ULL: goto x86_l_4d86;
	case 19851ULL: goto x86_l_4d8b;
	case 19857ULL: goto x86_l_4d91;
	case 19861ULL: goto x86_l_4d95;
	case 19866ULL: goto x86_l_4d9a;
	case 19871ULL: goto x86_l_4d9f;
	case 19876ULL: goto x86_l_4da4;
	case 19880ULL: goto x86_l_4da8;
	case 19884ULL: goto x86_l_4dac;
	case 19889ULL: goto x86_l_4db1;
	case 19891ULL: goto x86_l_4db3;
	case 19895ULL: goto x86_l_4db7;
	case 19898ULL: goto x86_l_4dba;
	case 19903ULL: goto x86_l_4dbf;
	case 19908ULL: goto x86_l_4dc4;
	case 19912ULL: goto x86_l_4dc8;
	case 19917ULL: goto x86_l_4dcd;
	case 19919ULL: goto x86_l_4dcf;
	case 19923ULL: goto x86_l_4dd3;
	case 19928ULL: goto x86_l_4dd8;
	case 19933ULL: goto x86_l_4ddd;
	case 19938ULL: goto x86_l_4de2;
	case 19942ULL: goto x86_l_4de6;
	case 19947ULL: goto x86_l_4deb;
	case 19949ULL: goto x86_l_4ded;
	case 19953ULL: goto x86_l_4df1;
	case 19957ULL: goto x86_l_4df5;
	case 19962ULL: goto x86_l_4dfa;
	case 19967ULL: goto x86_l_4dff;
	case 19972ULL: goto x86_l_4e04;
	case 19977ULL: goto x86_l_4e09;
	case 19982ULL: goto x86_l_4e0e;
	case 19987ULL: goto x86_l_4e13;
	case 19989ULL: goto x86_l_4e15;
	case 19994ULL: goto x86_l_4e1a;
	case 19999ULL: goto x86_l_4e1f;
	case 20003ULL: goto x86_l_4e23;
	case 20008ULL: goto x86_l_4e28;
	case 20013ULL: goto x86_l_4e2d;
	case 20018ULL: goto x86_l_4e32;
	case 20023ULL: goto x86_l_4e37;
	case 20025ULL: goto x86_l_4e39;
	case 20030ULL: goto x86_l_4e3e;
	case 20033ULL: goto x86_l_4e41;
	case 20039ULL: goto x86_l_4e47;
	case 20044ULL: goto x86_l_4e4c;
	case 20047ULL: goto x86_l_4e4f;
	case 20053ULL: goto x86_l_4e55;
	case 20057ULL: goto x86_l_4e59;
	case 20062ULL: goto x86_l_4e5e;
	case 20067ULL: goto x86_l_4e63;
	case 20072ULL: goto x86_l_4e68;
	case 20077ULL: goto x86_l_4e6d;
	case 20079ULL: goto x86_l_4e6f;
	case 20083ULL: goto x86_l_4e73;
	case 20085ULL: goto x86_l_4e75;
	case 20091ULL: goto x86_l_4e7b;
	case 20094ULL: goto x86_l_4e7e;
	case 20096ULL: goto x86_l_4e80;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20113ULL: goto x86_l_4e91;
	case 20118ULL: goto x86_l_4e96;
	case 20120ULL: goto x86_l_4e98;
	case 20125ULL: goto x86_l_4e9d;
	case 20127ULL: goto x86_l_4e9f;
	case 20130ULL: goto x86_l_4ea2;
	case 20136ULL: goto x86_l_4ea8;
	case 20140ULL: goto x86_l_4eac;
	case 20146ULL: goto x86_l_4eb2;
	case 20151ULL: goto x86_l_4eb7;
	case 20155ULL: goto x86_l_4ebb;
	case 20158ULL: goto x86_l_4ebe;
	case 20163ULL: goto x86_l_4ec3;
	case 20168ULL: goto x86_l_4ec8;
	case 20171ULL: goto x86_l_4ecb;
	case 20177ULL: goto x86_l_4ed1;
	case 20181ULL: goto x86_l_4ed5;
	case 20186ULL: goto x86_l_4eda;
	case 20192ULL: goto x86_l_4ee0;
	case 20196ULL: goto x86_l_4ee4;
	case 20201ULL: goto x86_l_4ee9;
	case 20206ULL: goto x86_l_4eee;
	case 20211ULL: goto x86_l_4ef3;
	case 20215ULL: goto x86_l_4ef7;
	case 20219ULL: goto x86_l_4efb;
	case 20224ULL: goto x86_l_4f00;
	case 20226ULL: goto x86_l_4f02;
	case 20230ULL: goto x86_l_4f06;
	case 20233ULL: goto x86_l_4f09;
	case 20238ULL: goto x86_l_4f0e;
	case 20243ULL: goto x86_l_4f13;
	case 20247ULL: goto x86_l_4f17;
	case 20252ULL: goto x86_l_4f1c;
	case 20254ULL: goto x86_l_4f1e;
	case 20258ULL: goto x86_l_4f22;
	case 20263ULL: goto x86_l_4f27;
	case 20268ULL: goto x86_l_4f2c;
	case 20273ULL: goto x86_l_4f31;
	case 20277ULL: goto x86_l_4f35;
	case 20282ULL: goto x86_l_4f3a;
	case 20284ULL: goto x86_l_4f3c;
	case 20288ULL: goto x86_l_4f40;
	case 20292ULL: goto x86_l_4f44;
	case 20297ULL: goto x86_l_4f49;
	case 20302ULL: goto x86_l_4f4e;
	case 20307ULL: goto x86_l_4f53;
	case 20312ULL: goto x86_l_4f58;
	case 20315ULL: goto x86_l_4f5b;
	case 20317ULL: goto x86_l_4f5d;
	case 20322ULL: goto x86_l_4f62;
	case 20327ULL: goto x86_l_4f67;
	case 20331ULL: goto x86_l_4f6b;
	case 20336ULL: goto x86_l_4f70;
	case 20341ULL: goto x86_l_4f75;
	case 20346ULL: goto x86_l_4f7a;
	case 20351ULL: goto x86_l_4f7f;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20361ULL: goto x86_l_4f89;
	case 20367ULL: goto x86_l_4f8f;
	case 20372ULL: goto x86_l_4f94;
	case 20375ULL: goto x86_l_4f97;
	case 20381ULL: goto x86_l_4f9d;
	case 20385ULL: goto x86_l_4fa1;
	case 20390ULL: goto x86_l_4fa6;
	case 20395ULL: goto x86_l_4fab;
	case 20400ULL: goto x86_l_4fb0;
	case 20405ULL: goto x86_l_4fb5;
	case 20407ULL: goto x86_l_4fb7;
	case 20411ULL: goto x86_l_4fbb;
	case 20413ULL: goto x86_l_4fbd;
	case 20419ULL: goto x86_l_4fc3;
	case 20421ULL: goto x86_l_4fc5;
	case 20423ULL: goto x86_l_4fc7;
	case 20429ULL: goto x86_l_4fcd;
	case 20434ULL: goto x86_l_4fd2;
	case 20440ULL: goto x86_l_4fd8;
	case 20443ULL: goto x86_l_4fdb;
	case 20445ULL: goto x86_l_4fdd;
	case 20450ULL: goto x86_l_4fe2;
	case 20452ULL: goto x86_l_4fe4;
	case 20455ULL: goto x86_l_4fe7;
	case 20461ULL: goto x86_l_4fed;
	case 20464ULL: goto x86_l_4ff0;
	case 20470ULL: goto x86_l_4ff6;
	case 20475ULL: goto x86_l_4ffb;
	case 20477ULL: goto x86_l_4ffd;
	case 20482ULL: goto x86_l_5002;
	case 20487ULL: goto x86_l_5007;
	case 20490ULL: goto x86_l_500a;
	case 20496ULL: goto x86_l_5010;
	case 20500ULL: goto x86_l_5014;
	case 20505ULL: goto x86_l_5019;
	case 20511ULL: goto x86_l_501f;
	case 20515ULL: goto x86_l_5023;
	case 20520ULL: goto x86_l_5028;
	case 20525ULL: goto x86_l_502d;
	case 20530ULL: goto x86_l_5032;
	case 20534ULL: goto x86_l_5036;
	case 20538ULL: goto x86_l_503a;
	case 20543ULL: goto x86_l_503f;
	case 20545ULL: goto x86_l_5041;
	case 20549ULL: goto x86_l_5045;
	case 20552ULL: goto x86_l_5048;
	case 20557ULL: goto x86_l_504d;
	case 20562ULL: goto x86_l_5052;
	case 20566ULL: goto x86_l_5056;
	case 20571ULL: goto x86_l_505b;
	case 20573ULL: goto x86_l_505d;
	case 20577ULL: goto x86_l_5061;
	case 20582ULL: goto x86_l_5066;
	case 20587ULL: goto x86_l_506b;
	case 20592ULL: goto x86_l_5070;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20603ULL: goto x86_l_507b;
	case 20607ULL: goto x86_l_507f;
	case 20611ULL: goto x86_l_5083;
	case 20616ULL: goto x86_l_5088;
	case 20621ULL: goto x86_l_508d;
	case 20626ULL: goto x86_l_5092;
	case 20631ULL: goto x86_l_5097;
	case 20636ULL: goto x86_l_509c;
	case 20641ULL: goto x86_l_50a1;
	case 20643ULL: goto x86_l_50a3;
	case 20648ULL: goto x86_l_50a8;
	case 20653ULL: goto x86_l_50ad;
	case 20657ULL: goto x86_l_50b1;
	case 20662ULL: goto x86_l_50b6;
	case 20667ULL: goto x86_l_50bb;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20679ULL: goto x86_l_50c7;
	case 20684ULL: goto x86_l_50cc;
	case 20687ULL: goto x86_l_50cf;
	case 20693ULL: goto x86_l_50d5;
	case 20698ULL: goto x86_l_50da;
	case 20701ULL: goto x86_l_50dd;
	case 20707ULL: goto x86_l_50e3;
	case 20711ULL: goto x86_l_50e7;
	case 20716ULL: goto x86_l_50ec;
	case 20721ULL: goto x86_l_50f1;
	case 20726ULL: goto x86_l_50f6;
	case 20731ULL: goto x86_l_50fb;
	case 20733ULL: goto x86_l_50fd;
	case 20737ULL: goto x86_l_5101;
	case 20739ULL: goto x86_l_5103;
	case 20745ULL: goto x86_l_5109;
	case 20748ULL: goto x86_l_510c;
	case 20750ULL: goto x86_l_510e;
	case 20756ULL: goto x86_l_5114;
	case 20761ULL: goto x86_l_5119;
	case 20767ULL: goto x86_l_511f;
	case 20772ULL: goto x86_l_5124;
	case 20774ULL: goto x86_l_5126;
	case 20779ULL: goto x86_l_512b;
	case 20781ULL: goto x86_l_512d;
	case 20784ULL: goto x86_l_5130;
	case 20790ULL: goto x86_l_5136;
	case 20794ULL: goto x86_l_513a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4ac8:
	/* 0x4ac8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4acb:
	/* 0x4acb: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_4ad1:
	/* 0x4ad1: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ad4:
	/* 0x4ad4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4ada:
	/* 0x4ada: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4adf:
	/* 0x4adf: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ae1:
	/* 0x4ae1: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ae6:
	/* 0x4ae6: jmp    4cb6 <trace_ret_kernel_write_tail+0x4cb6> */
	goto x86_l_4cb6;
x86_l_4aeb:
	/* 0x4aeb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4aee:
	/* 0x4aee: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_4af4:
	/* 0x4af4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4af8:
	/* 0x4af8: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4afd:
	/* 0x4afd: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_4b03:
	/* 0x4b03: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b07:
	/* 0x4b07: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b0c:
	/* 0x4b0c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b11:
	/* 0x4b11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b16:
	/* 0x4b16: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b1a:
	/* 0x4b1a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b1e:
	/* 0x4b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b23:
	/* 0x4b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b25:
	/* 0x4b25: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b29:
	/* 0x4b29: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b2c:
	/* 0x4b2c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b31:
	/* 0x4b31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b36:
	/* 0x4b36: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b3a:
	/* 0x4b3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b3f:
	/* 0x4b3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b41:
	/* 0x4b41: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b45:
	/* 0x4b45: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b4a:
	/* 0x4b4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b4f:
	/* 0x4b4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b54:
	/* 0x4b54: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b58:
	/* 0x4b58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b5d:
	/* 0x4b5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5f:
	/* 0x4b5f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b63:
	/* 0x4b63: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b67:
	/* 0x4b67: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b6c:
	/* 0x4b6c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b71:
	/* 0x4b71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b76:
	/* 0x4b76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b7b:
	/* 0x4b7b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b80:
	/* 0x4b80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b85:
	/* 0x4b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b87:
	/* 0x4b87: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b8c:
	/* 0x4b8c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b91:
	/* 0x4b91: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b95:
	/* 0x4b95: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b9a:
	/* 0x4b9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b9f:
	/* 0x4b9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ba4:
	/* 0x4ba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ba9:
	/* 0x4ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bab:
	/* 0x4bab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb0:
	/* 0x4bb0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4bb3:
	/* 0x4bb3: je     4d79 <trace_ret_kernel_write_tail+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d79;
	}
x86_l_4bb9:
	/* 0x4bb9: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bbe:
	/* 0x4bbe: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4bc1:
	/* 0x4bc1: je     4d79 <trace_ret_kernel_write_tail+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d79;
	}
x86_l_4bc7:
	/* 0x4bc7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4bcb:
	/* 0x4bcb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bd0:
	/* 0x4bd0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4bd5:
	/* 0x4bd5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bda:
	/* 0x4bda: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4bdf:
	/* 0x4bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4be1:
	/* 0x4be1: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4be5:
	/* 0x4be5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4be7:
	/* 0x4be7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4bed:
	/* 0x4bed: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4bf0:
	/* 0x4bf0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4bf2:
	/* 0x4bf2: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_4bf8:
	/* 0x4bf8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4bfd:
	/* 0x4bfd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4c03:
	/* 0x4c03: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_4c08:
	/* 0x4c08: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4c0a:
	/* 0x4c0a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4c0f:
	/* 0x4c0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c11:
	/* 0x4c11: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c14:
	/* 0x4c14: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_4c1a:
	/* 0x4c1a: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4c1e:
	/* 0x4c1e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4c24:
	/* 0x4c24: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4c29:
	/* 0x4c29: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4c2d:
	/* 0x4c2d: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c30:
	/* 0x4c30: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c35:
	/* 0x4c35: jmp    4dfa <trace_ret_kernel_write_tail+0x4dfa> */
	goto x86_l_4dfa;
x86_l_4c3a:
	/* 0x4c3a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4c3d:
	/* 0x4c3d: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_4c43:
	/* 0x4c43: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c47:
	/* 0x4c47: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4c4c:
	/* 0x4c4c: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_4c52:
	/* 0x4c52: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c56:
	/* 0x4c56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5b:
	/* 0x4c5b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c60:
	/* 0x4c60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c65:
	/* 0x4c65: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c69:
	/* 0x4c69: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c6d:
	/* 0x4c6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c72:
	/* 0x4c72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c74:
	/* 0x4c74: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c78:
	/* 0x4c78: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c7b:
	/* 0x4c7b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c80:
	/* 0x4c80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c85:
	/* 0x4c85: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c89:
	/* 0x4c89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c8e:
	/* 0x4c8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c90:
	/* 0x4c90: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c94:
	/* 0x4c94: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4c99:
	/* 0x4c99: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c9e:
	/* 0x4c9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ca3:
	/* 0x4ca3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca7:
	/* 0x4ca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cac:
	/* 0x4cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cae:
	/* 0x4cae: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cb2:
	/* 0x4cb2: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4cb6:
	/* 0x4cb6: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4cbb:
	/* 0x4cbb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4cc0:
	/* 0x4cc0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cc5:
	/* 0x4cc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cca:
	/* 0x4cca: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4ccd:
	/* 0x4ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ccf:
	/* 0x4ccf: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4cd4:
	/* 0x4cd4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd9:
	/* 0x4cd9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4cdd:
	/* 0x4cdd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce2:
	/* 0x4ce2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ce7:
	/* 0x4ce7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cec:
	/* 0x4cec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cf1:
	/* 0x4cf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cf3:
	/* 0x4cf3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf8:
	/* 0x4cf8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4cfb:
	/* 0x4cfb: je     4ec8 <trace_ret_kernel_write_tail+0x4ec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec8;
	}
x86_l_4d01:
	/* 0x4d01: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d06:
	/* 0x4d06: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4d09:
	/* 0x4d09: je     4ec8 <trace_ret_kernel_write_tail+0x4ec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec8;
	}
x86_l_4d0f:
	/* 0x4d0f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d13:
	/* 0x4d13: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d18:
	/* 0x4d18: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4d1d:
	/* 0x4d1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d22:
	/* 0x4d22: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4d27:
	/* 0x4d27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d29:
	/* 0x4d29: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4d2d:
	/* 0x4d2d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4d2f:
	/* 0x4d2f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d35:
	/* 0x4d35: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4d37:
	/* 0x4d37: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d39:
	/* 0x4d39: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_4d3f:
	/* 0x4d3f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d44:
	/* 0x4d44: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4d4a:
	/* 0x4d4a: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d4d:
	/* 0x4d4d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4d4f:
	/* 0x4d4f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4d54:
	/* 0x4d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d56:
	/* 0x4d56: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d59:
	/* 0x4d59: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_4d5f:
	/* 0x4d5f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4d62:
	/* 0x4d62: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4d68:
	/* 0x4d68: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4d6d:
	/* 0x4d6d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d6f:
	/* 0x4d6f: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d74:
	/* 0x4d74: jmp    4f44 <trace_ret_kernel_write_tail+0x4f44> */
	goto x86_l_4f44;
x86_l_4d79:
	/* 0x4d79: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4d7c:
	/* 0x4d7c: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_4d82:
	/* 0x4d82: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d86:
	/* 0x4d86: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4d8b:
	/* 0x4d8b: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_4d91:
	/* 0x4d91: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d95:
	/* 0x4d95: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d9a:
	/* 0x4d9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d9f:
	/* 0x4d9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4da4:
	/* 0x4da4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4da8:
	/* 0x4da8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4dac:
	/* 0x4dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4db1:
	/* 0x4db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db3:
	/* 0x4db3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4db7:
	/* 0x4db7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4dba:
	/* 0x4dba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4dbf:
	/* 0x4dbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4dc4:
	/* 0x4dc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dc8:
	/* 0x4dc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dcd:
	/* 0x4dcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dcf:
	/* 0x4dcf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd3:
	/* 0x4dd3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4dd8:
	/* 0x4dd8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ddd:
	/* 0x4ddd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4de2:
	/* 0x4de2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4de6:
	/* 0x4de6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4deb:
	/* 0x4deb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ded:
	/* 0x4ded: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df1:
	/* 0x4df1: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4df5:
	/* 0x4df5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4dfa:
	/* 0x4dfa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4dff:
	/* 0x4dff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e04:
	/* 0x4e04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e09:
	/* 0x4e09: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4e0e:
	/* 0x4e0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e13:
	/* 0x4e13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e15:
	/* 0x4e15: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e1a:
	/* 0x4e1a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e1f:
	/* 0x4e1f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e23:
	/* 0x4e23: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e28:
	/* 0x4e28: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e2d:
	/* 0x4e2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e32:
	/* 0x4e32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e37:
	/* 0x4e37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e39:
	/* 0x4e39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3e:
	/* 0x4e3e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4e41:
	/* 0x4e41: je     5007 <trace_ret_kernel_write_tail+0x5007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5007;
	}
x86_l_4e47:
	/* 0x4e47: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e4c:
	/* 0x4e4c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4e4f:
	/* 0x4e4f: je     5007 <trace_ret_kernel_write_tail+0x5007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5007;
	}
x86_l_4e55:
	/* 0x4e55: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e59:
	/* 0x4e59: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e5e:
	/* 0x4e5e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4e63:
	/* 0x4e63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e68:
	/* 0x4e68: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4e6d:
	/* 0x4e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e6f:
	/* 0x4e6f: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4e73:
	/* 0x4e73: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4e75:
	/* 0x4e75: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e7b:
	/* 0x4e7b: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4e7e:
	/* 0x4e7e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e80:
	/* 0x4e80: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_4e86:
	/* 0x4e86: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e8b:
	/* 0x4e8b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4e91:
	/* 0x4e91: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_4e96:
	/* 0x4e96: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4e98:
	/* 0x4e98: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4e9d:
	/* 0x4e9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e9f:
	/* 0x4e9f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ea2:
	/* 0x4ea2: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_4ea8:
	/* 0x4ea8: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4eac:
	/* 0x4eac: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4eb2:
	/* 0x4eb2: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4eb7:
	/* 0x4eb7: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4ebb:
	/* 0x4ebb: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ebe:
	/* 0x4ebe: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ec3:
	/* 0x4ec3: jmp    5088 <trace_ret_kernel_write_tail+0x5088> */
	goto x86_l_5088;
x86_l_4ec8:
	/* 0x4ec8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4ecb:
	/* 0x4ecb: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_4ed1:
	/* 0x4ed1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ed5:
	/* 0x4ed5: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_4eda:
	/* 0x4eda: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_4ee0:
	/* 0x4ee0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ee4:
	/* 0x4ee4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ee9:
	/* 0x4ee9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eee:
	/* 0x4eee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ef3:
	/* 0x4ef3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef7:
	/* 0x4ef7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4efb:
	/* 0x4efb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f00:
	/* 0x4f00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f02:
	/* 0x4f02: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f06:
	/* 0x4f06: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f09:
	/* 0x4f09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f0e:
	/* 0x4f0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f13:
	/* 0x4f13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f17:
	/* 0x4f17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f1c:
	/* 0x4f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f1e:
	/* 0x4f1e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f22:
	/* 0x4f22: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f27:
	/* 0x4f27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f2c:
	/* 0x4f2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f31:
	/* 0x4f31: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f35:
	/* 0x4f35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f3a:
	/* 0x4f3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f3c:
	/* 0x4f3c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f40:
	/* 0x4f40: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f44:
	/* 0x4f44: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f49:
	/* 0x4f49: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f4e:
	/* 0x4f4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f53:
	/* 0x4f53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f58:
	/* 0x4f58: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4f5b:
	/* 0x4f5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f5d:
	/* 0x4f5d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f62:
	/* 0x4f62: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f67:
	/* 0x4f67: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f6b:
	/* 0x4f6b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f70:
	/* 0x4f70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f75:
	/* 0x4f75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f7f:
	/* 0x4f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f81:
	/* 0x4f81: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f86:
	/* 0x4f86: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4f89:
	/* 0x4f89: je     5156 <trace_ret_kernel_write_tail+0x5156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20822ULL;
	}
x86_l_4f8f:
	/* 0x4f8f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f94:
	/* 0x4f94: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4f97:
	/* 0x4f97: je     5156 <trace_ret_kernel_write_tail+0x5156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20822ULL;
	}
x86_l_4f9d:
	/* 0x4f9d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4fa1:
	/* 0x4fa1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fa6:
	/* 0x4fa6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4fab:
	/* 0x4fab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fb0:
	/* 0x4fb0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4fb5:
	/* 0x4fb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fb7:
	/* 0x4fb7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4fbb:
	/* 0x4fbb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4fbd:
	/* 0x4fbd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fc3:
	/* 0x4fc3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4fc5:
	/* 0x4fc5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4fc7:
	/* 0x4fc7: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_4fcd:
	/* 0x4fcd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fd2:
	/* 0x4fd2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4fd8:
	/* 0x4fd8: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fdb:
	/* 0x4fdb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4fdd:
	/* 0x4fdd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4fe2:
	/* 0x4fe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe4:
	/* 0x4fe4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4fe7:
	/* 0x4fe7: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_4fed:
	/* 0x4fed: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ff0:
	/* 0x4ff0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4ff6:
	/* 0x4ff6: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4ffb:
	/* 0x4ffb: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ffd:
	/* 0x4ffd: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5002:
	/* 0x5002: jmp    51d2 <trace_ret_kernel_write_tail+0x51d2> */
	return 20946ULL;
x86_l_5007:
	/* 0x5007: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_500a:
	/* 0x500a: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_5010:
	/* 0x5010: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5014:
	/* 0x5014: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5019:
	/* 0x5019: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_501f:
	/* 0x501f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5023:
	/* 0x5023: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5028:
	/* 0x5028: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
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
	/* 0x503a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_503f:
	/* 0x503f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5041:
	/* 0x5041: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5045:
	/* 0x5045: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5048:
	/* 0x5048: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_504d:
	/* 0x504d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5052:
	/* 0x5052: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5056:
	/* 0x5056: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_505b:
	/* 0x505b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_505d:
	/* 0x505d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5061:
	/* 0x5061: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5066:
	/* 0x5066: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_506b:
	/* 0x506b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5070:
	/* 0x5070: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5074:
	/* 0x5074: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5079:
	/* 0x5079: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_507b:
	/* 0x507b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507f:
	/* 0x507f: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5083:
	/* 0x5083: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5088:
	/* 0x5088: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_508d:
	/* 0x508d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5092:
	/* 0x5092: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5097:
	/* 0x5097: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_509c:
	/* 0x509c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50a1:
	/* 0x50a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50a3:
	/* 0x50a3: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50a8:
	/* 0x50a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50ad:
	/* 0x50ad: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_50b1:
	/* 0x50b1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50b6:
	/* 0x50b6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50bb:
	/* 0x50bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50c0:
	/* 0x50c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50c5:
	/* 0x50c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c7:
	/* 0x50c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50cc:
	/* 0x50cc: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_50cf:
	/* 0x50cf: je     5295 <trace_ret_kernel_write_tail+0x5295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21141ULL;
	}
x86_l_50d5:
	/* 0x50d5: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50da:
	/* 0x50da: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_50dd:
	/* 0x50dd: je     5295 <trace_ret_kernel_write_tail+0x5295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21141ULL;
	}
x86_l_50e3:
	/* 0x50e3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50e7:
	/* 0x50e7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50ec:
	/* 0x50ec: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_50f1:
	/* 0x50f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50f6:
	/* 0x50f6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_50fb:
	/* 0x50fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50fd:
	/* 0x50fd: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5101:
	/* 0x5101: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5103:
	/* 0x5103: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5109:
	/* 0x5109: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_510c:
	/* 0x510c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_510e:
	/* 0x510e: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_5114:
	/* 0x5114: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5119:
	/* 0x5119: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_511f:
	/* 0x511f: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_5124:
	/* 0x5124: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5126:
	/* 0x5126: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_512b:
	/* 0x512b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512d:
	/* 0x512d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5130:
	/* 0x5130: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_5136:
	/* 0x5136: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_513a:
	/* 0x513a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
	return 20800ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20800ULL: goto x86_l_5140;
	case 20805ULL: goto x86_l_5145;
	case 20809ULL: goto x86_l_5149;
	case 20812ULL: goto x86_l_514c;
	case 20817ULL: goto x86_l_5151;
	case 20822ULL: goto x86_l_5156;
	case 20825ULL: goto x86_l_5159;
	case 20831ULL: goto x86_l_515f;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20846ULL: goto x86_l_516e;
	case 20850ULL: goto x86_l_5172;
	case 20855ULL: goto x86_l_5177;
	case 20860ULL: goto x86_l_517c;
	case 20865ULL: goto x86_l_5181;
	case 20869ULL: goto x86_l_5185;
	case 20873ULL: goto x86_l_5189;
	case 20878ULL: goto x86_l_518e;
	case 20880ULL: goto x86_l_5190;
	case 20884ULL: goto x86_l_5194;
	case 20887ULL: goto x86_l_5197;
	case 20892ULL: goto x86_l_519c;
	case 20897ULL: goto x86_l_51a1;
	case 20901ULL: goto x86_l_51a5;
	case 20906ULL: goto x86_l_51aa;
	case 20908ULL: goto x86_l_51ac;
	case 20912ULL: goto x86_l_51b0;
	case 20917ULL: goto x86_l_51b5;
	case 20922ULL: goto x86_l_51ba;
	case 20927ULL: goto x86_l_51bf;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20938ULL: goto x86_l_51ca;
	case 20942ULL: goto x86_l_51ce;
	case 20946ULL: goto x86_l_51d2;
	case 20951ULL: goto x86_l_51d7;
	case 20956ULL: goto x86_l_51dc;
	case 20961ULL: goto x86_l_51e1;
	case 20966ULL: goto x86_l_51e6;
	case 20969ULL: goto x86_l_51e9;
	case 20971ULL: goto x86_l_51eb;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20985ULL: goto x86_l_51f9;
	case 20990ULL: goto x86_l_51fe;
	case 20995ULL: goto x86_l_5203;
	case 21000ULL: goto x86_l_5208;
	case 21005ULL: goto x86_l_520d;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21015ULL: goto x86_l_5217;
	case 21021ULL: goto x86_l_521d;
	case 21026ULL: goto x86_l_5222;
	case 21029ULL: goto x86_l_5225;
	case 21035ULL: goto x86_l_522b;
	case 21039ULL: goto x86_l_522f;
	case 21044ULL: goto x86_l_5234;
	case 21049ULL: goto x86_l_5239;
	case 21054ULL: goto x86_l_523e;
	case 21059ULL: goto x86_l_5243;
	case 21061ULL: goto x86_l_5245;
	case 21065ULL: goto x86_l_5249;
	case 21067ULL: goto x86_l_524b;
	case 21073ULL: goto x86_l_5251;
	case 21075ULL: goto x86_l_5253;
	case 21077ULL: goto x86_l_5255;
	case 21083ULL: goto x86_l_525b;
	case 21088ULL: goto x86_l_5260;
	case 21094ULL: goto x86_l_5266;
	case 21097ULL: goto x86_l_5269;
	case 21099ULL: goto x86_l_526b;
	case 21104ULL: goto x86_l_5270;
	case 21106ULL: goto x86_l_5272;
	case 21109ULL: goto x86_l_5275;
	case 21115ULL: goto x86_l_527b;
	case 21118ULL: goto x86_l_527e;
	case 21124ULL: goto x86_l_5284;
	case 21129ULL: goto x86_l_5289;
	case 21131ULL: goto x86_l_528b;
	case 21136ULL: goto x86_l_5290;
	case 21141ULL: goto x86_l_5295;
	case 21144ULL: goto x86_l_5298;
	case 21150ULL: goto x86_l_529e;
	case 21154ULL: goto x86_l_52a2;
	case 21159ULL: goto x86_l_52a7;
	case 21165ULL: goto x86_l_52ad;
	case 21169ULL: goto x86_l_52b1;
	case 21174ULL: goto x86_l_52b6;
	case 21179ULL: goto x86_l_52bb;
	case 21184ULL: goto x86_l_52c0;
	case 21188ULL: goto x86_l_52c4;
	case 21192ULL: goto x86_l_52c8;
	case 21197ULL: goto x86_l_52cd;
	case 21199ULL: goto x86_l_52cf;
	case 21203ULL: goto x86_l_52d3;
	case 21206ULL: goto x86_l_52d6;
	case 21211ULL: goto x86_l_52db;
	case 21216ULL: goto x86_l_52e0;
	case 21220ULL: goto x86_l_52e4;
	case 21225ULL: goto x86_l_52e9;
	case 21227ULL: goto x86_l_52eb;
	case 21231ULL: goto x86_l_52ef;
	case 21236ULL: goto x86_l_52f4;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21250ULL: goto x86_l_5302;
	case 21255ULL: goto x86_l_5307;
	case 21257ULL: goto x86_l_5309;
	case 21261ULL: goto x86_l_530d;
	case 21265ULL: goto x86_l_5311;
	case 21270ULL: goto x86_l_5316;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21285ULL: goto x86_l_5325;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21297ULL: goto x86_l_5331;
	case 21302ULL: goto x86_l_5336;
	case 21307ULL: goto x86_l_533b;
	case 21311ULL: goto x86_l_533f;
	case 21316ULL: goto x86_l_5344;
	case 21321ULL: goto x86_l_5349;
	case 21326ULL: goto x86_l_534e;
	case 21331ULL: goto x86_l_5353;
	case 21333ULL: goto x86_l_5355;
	case 21338ULL: goto x86_l_535a;
	case 21341ULL: goto x86_l_535d;
	case 21347ULL: goto x86_l_5363;
	case 21352ULL: goto x86_l_5368;
	case 21355ULL: goto x86_l_536b;
	case 21361ULL: goto x86_l_5371;
	case 21365ULL: goto x86_l_5375;
	case 21370ULL: goto x86_l_537a;
	case 21375ULL: goto x86_l_537f;
	case 21380ULL: goto x86_l_5384;
	case 21385ULL: goto x86_l_5389;
	case 21387ULL: goto x86_l_538b;
	case 21391ULL: goto x86_l_538f;
	case 21393ULL: goto x86_l_5391;
	case 21399ULL: goto x86_l_5397;
	case 21402ULL: goto x86_l_539a;
	case 21404ULL: goto x86_l_539c;
	case 21410ULL: goto x86_l_53a2;
	case 21415ULL: goto x86_l_53a7;
	case 21421ULL: goto x86_l_53ad;
	case 21426ULL: goto x86_l_53b2;
	case 21428ULL: goto x86_l_53b4;
	case 21433ULL: goto x86_l_53b9;
	case 21435ULL: goto x86_l_53bb;
	case 21438ULL: goto x86_l_53be;
	case 21444ULL: goto x86_l_53c4;
	case 21448ULL: goto x86_l_53c8;
	case 21454ULL: goto x86_l_53ce;
	case 21459ULL: goto x86_l_53d3;
	case 21463ULL: goto x86_l_53d7;
	case 21466ULL: goto x86_l_53da;
	case 21471ULL: goto x86_l_53df;
	case 21476ULL: goto x86_l_53e4;
	case 21479ULL: goto x86_l_53e7;
	case 21485ULL: goto x86_l_53ed;
	case 21489ULL: goto x86_l_53f1;
	case 21494ULL: goto x86_l_53f6;
	case 21500ULL: goto x86_l_53fc;
	case 21504ULL: goto x86_l_5400;
	case 21509ULL: goto x86_l_5405;
	case 21514ULL: goto x86_l_540a;
	case 21519ULL: goto x86_l_540f;
	case 21523ULL: goto x86_l_5413;
	case 21527ULL: goto x86_l_5417;
	case 21532ULL: goto x86_l_541c;
	case 21534ULL: goto x86_l_541e;
	case 21538ULL: goto x86_l_5422;
	case 21541ULL: goto x86_l_5425;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21555ULL: goto x86_l_5433;
	case 21560ULL: goto x86_l_5438;
	case 21562ULL: goto x86_l_543a;
	case 21566ULL: goto x86_l_543e;
	case 21571ULL: goto x86_l_5443;
	case 21576ULL: goto x86_l_5448;
	case 21581ULL: goto x86_l_544d;
	case 21585ULL: goto x86_l_5451;
	case 21590ULL: goto x86_l_5456;
	case 21592ULL: goto x86_l_5458;
	case 21596ULL: goto x86_l_545c;
	case 21600ULL: goto x86_l_5460;
	case 21605ULL: goto x86_l_5465;
	case 21610ULL: goto x86_l_546a;
	case 21615ULL: goto x86_l_546f;
	case 21620ULL: goto x86_l_5474;
	case 21623ULL: goto x86_l_5477;
	case 21625ULL: goto x86_l_5479;
	case 21630ULL: goto x86_l_547e;
	case 21635ULL: goto x86_l_5483;
	case 21639ULL: goto x86_l_5487;
	case 21644ULL: goto x86_l_548c;
	case 21649ULL: goto x86_l_5491;
	case 21654ULL: goto x86_l_5496;
	case 21659ULL: goto x86_l_549b;
	case 21661ULL: goto x86_l_549d;
	case 21666ULL: goto x86_l_54a2;
	case 21669ULL: goto x86_l_54a5;
	case 21675ULL: goto x86_l_54ab;
	case 21680ULL: goto x86_l_54b0;
	case 21683ULL: goto x86_l_54b3;
	case 21689ULL: goto x86_l_54b9;
	case 21693ULL: goto x86_l_54bd;
	case 21698ULL: goto x86_l_54c2;
	case 21703ULL: goto x86_l_54c7;
	case 21708ULL: goto x86_l_54cc;
	case 21713ULL: goto x86_l_54d1;
	case 21715ULL: goto x86_l_54d3;
	case 21719ULL: goto x86_l_54d7;
	case 21721ULL: goto x86_l_54d9;
	case 21727ULL: goto x86_l_54df;
	case 21729ULL: goto x86_l_54e1;
	case 21731ULL: goto x86_l_54e3;
	case 21737ULL: goto x86_l_54e9;
	case 21742ULL: goto x86_l_54ee;
	case 21748ULL: goto x86_l_54f4;
	case 21751ULL: goto x86_l_54f7;
	case 21753ULL: goto x86_l_54f9;
	case 21758ULL: goto x86_l_54fe;
	case 21760ULL: goto x86_l_5500;
	case 21763ULL: goto x86_l_5503;
	case 21769ULL: goto x86_l_5509;
	case 21772ULL: goto x86_l_550c;
	case 21778ULL: goto x86_l_5512;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21790ULL: goto x86_l_551e;
	case 21795ULL: goto x86_l_5523;
	case 21798ULL: goto x86_l_5526;
	case 21804ULL: goto x86_l_552c;
	case 21808ULL: goto x86_l_5530;
	case 21813ULL: goto x86_l_5535;
	case 21819ULL: goto x86_l_553b;
	case 21823ULL: goto x86_l_553f;
	case 21828ULL: goto x86_l_5544;
	case 21833ULL: goto x86_l_5549;
	case 21838ULL: goto x86_l_554e;
	case 21842ULL: goto x86_l_5552;
	case 21846ULL: goto x86_l_5556;
	case 21851ULL: goto x86_l_555b;
	case 21853ULL: goto x86_l_555d;
	case 21857ULL: goto x86_l_5561;
	case 21860ULL: goto x86_l_5564;
	case 21865ULL: goto x86_l_5569;
	case 21870ULL: goto x86_l_556e;
	case 21874ULL: goto x86_l_5572;
	case 21879ULL: goto x86_l_5577;
	case 21881ULL: goto x86_l_5579;
	case 21885ULL: goto x86_l_557d;
	case 21890ULL: goto x86_l_5582;
	case 21895ULL: goto x86_l_5587;
	case 21900ULL: goto x86_l_558c;
	case 21904ULL: goto x86_l_5590;
	case 21909ULL: goto x86_l_5595;
	case 21911ULL: goto x86_l_5597;
	case 21915ULL: goto x86_l_559b;
	case 21919ULL: goto x86_l_559f;
	case 21924ULL: goto x86_l_55a4;
	case 21929ULL: goto x86_l_55a9;
	case 21934ULL: goto x86_l_55ae;
	case 21939ULL: goto x86_l_55b3;
	case 21944ULL: goto x86_l_55b8;
	case 21949ULL: goto x86_l_55bd;
	case 21951ULL: goto x86_l_55bf;
	case 21956ULL: goto x86_l_55c4;
	case 21961ULL: goto x86_l_55c9;
	case 21965ULL: goto x86_l_55cd;
	case 21970ULL: goto x86_l_55d2;
	case 21975ULL: goto x86_l_55d7;
	case 21980ULL: goto x86_l_55dc;
	case 21985ULL: goto x86_l_55e1;
	case 21987ULL: goto x86_l_55e3;
	case 21992ULL: goto x86_l_55e8;
	case 21995ULL: goto x86_l_55eb;
	case 22001ULL: goto x86_l_55f1;
	case 22006ULL: goto x86_l_55f6;
	case 22009ULL: goto x86_l_55f9;
	case 22015ULL: goto x86_l_55ff;
	case 22019ULL: goto x86_l_5603;
	case 22024ULL: goto x86_l_5608;
	case 22029ULL: goto x86_l_560d;
	case 22034ULL: goto x86_l_5612;
	case 22039ULL: goto x86_l_5617;
	case 22041ULL: goto x86_l_5619;
	case 22045ULL: goto x86_l_561d;
	case 22047ULL: goto x86_l_561f;
	case 22053ULL: goto x86_l_5625;
	case 22056ULL: goto x86_l_5628;
	case 22058ULL: goto x86_l_562a;
	case 22064ULL: goto x86_l_5630;
	case 22069ULL: goto x86_l_5635;
	case 22075ULL: goto x86_l_563b;
	case 22080ULL: goto x86_l_5640;
	case 22082ULL: goto x86_l_5642;
	case 22087ULL: goto x86_l_5647;
	case 22089ULL: goto x86_l_5649;
	case 22092ULL: goto x86_l_564c;
	case 22098ULL: goto x86_l_5652;
	case 22102ULL: goto x86_l_5656;
	case 22108ULL: goto x86_l_565c;
	case 22113ULL: goto x86_l_5661;
	case 22117ULL: goto x86_l_5665;
	case 22120ULL: goto x86_l_5668;
	case 22125ULL: goto x86_l_566d;
	case 22130ULL: goto x86_l_5672;
	case 22133ULL: goto x86_l_5675;
	case 22139ULL: goto x86_l_567b;
	case 22143ULL: goto x86_l_567f;
	case 22148ULL: goto x86_l_5684;
	case 22154ULL: goto x86_l_568a;
	case 22158ULL: goto x86_l_568e;
	case 22163ULL: goto x86_l_5693;
	case 22168ULL: goto x86_l_5698;
	case 22173ULL: goto x86_l_569d;
	case 22177ULL: goto x86_l_56a1;
	case 22181ULL: goto x86_l_56a5;
	case 22186ULL: goto x86_l_56aa;
	case 22188ULL: goto x86_l_56ac;
	case 22192ULL: goto x86_l_56b0;
	case 22195ULL: goto x86_l_56b3;
	case 22200ULL: goto x86_l_56b8;
	case 22205ULL: goto x86_l_56bd;
	case 22209ULL: goto x86_l_56c1;
	case 22214ULL: goto x86_l_56c6;
	case 22216ULL: goto x86_l_56c8;
	case 22220ULL: goto x86_l_56cc;
	case 22225ULL: goto x86_l_56d1;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22239ULL: goto x86_l_56df;
	case 22244ULL: goto x86_l_56e4;
	case 22246ULL: goto x86_l_56e6;
	case 22250ULL: goto x86_l_56ea;
	case 22254ULL: goto x86_l_56ee;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22269ULL: goto x86_l_56fd;
	case 22274ULL: goto x86_l_5702;
	case 22277ULL: goto x86_l_5705;
	case 22279ULL: goto x86_l_5707;
	case 22284ULL: goto x86_l_570c;
	case 22289ULL: goto x86_l_5711;
	case 22293ULL: goto x86_l_5715;
	case 22298ULL: goto x86_l_571a;
	case 22303ULL: goto x86_l_571f;
	case 22308ULL: goto x86_l_5724;
	case 22313ULL: goto x86_l_5729;
	case 22315ULL: goto x86_l_572b;
	case 22320ULL: goto x86_l_5730;
	case 22323ULL: goto x86_l_5733;
	case 22329ULL: goto x86_l_5739;
	case 22334ULL: goto x86_l_573e;
	case 22337ULL: goto x86_l_5741;
	case 22343ULL: goto x86_l_5747;
	case 22347ULL: goto x86_l_574b;
	case 22352ULL: goto x86_l_5750;
	case 22357ULL: goto x86_l_5755;
	case 22362ULL: goto x86_l_575a;
	case 22367ULL: goto x86_l_575f;
	case 22369ULL: goto x86_l_5761;
	case 22373ULL: goto x86_l_5765;
	case 22375ULL: goto x86_l_5767;
	case 22381ULL: goto x86_l_576d;
	case 22383ULL: goto x86_l_576f;
	case 22385ULL: goto x86_l_5771;
	case 22391ULL: goto x86_l_5777;
	case 22396ULL: goto x86_l_577c;
	case 22402ULL: goto x86_l_5782;
	case 22405ULL: goto x86_l_5785;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22414ULL: goto x86_l_578e;
	case 22417ULL: goto x86_l_5791;
	case 22423ULL: goto x86_l_5797;
	case 22426ULL: goto x86_l_579a;
	case 22432ULL: goto x86_l_57a0;
	case 22437ULL: goto x86_l_57a5;
	case 22439ULL: goto x86_l_57a7;
	case 22444ULL: goto x86_l_57ac;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5140:
	/* 0x5140: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5145:
	/* 0x5145: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5149:
	/* 0x5149: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_514c:
	/* 0x514c: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5151:
	/* 0x5151: jmp    5316 <trace_ret_kernel_write_tail+0x5316> */
	goto x86_l_5316;
x86_l_5156:
	/* 0x5156: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5159:
	/* 0x5159: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_515f:
	/* 0x515f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5163:
	/* 0x5163: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5168:
	/* 0x5168: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_516e:
	/* 0x516e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5172:
	/* 0x5172: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5177:
	/* 0x5177: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_517c:
	/* 0x517c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5181:
	/* 0x5181: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5185:
	/* 0x5185: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5189:
	/* 0x5189: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_518e:
	/* 0x518e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5190:
	/* 0x5190: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5194:
	/* 0x5194: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5197:
	/* 0x5197: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_519c:
	/* 0x519c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51a1:
	/* 0x51a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a5:
	/* 0x51a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51aa:
	/* 0x51aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ac:
	/* 0x51ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b0:
	/* 0x51b0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_51b5:
	/* 0x51b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51ba:
	/* 0x51ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51bf:
	/* 0x51bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51c3:
	/* 0x51c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c8:
	/* 0x51c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ca:
	/* 0x51ca: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51ce:
	/* 0x51ce: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51d2:
	/* 0x51d2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51d7:
	/* 0x51d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51dc:
	/* 0x51dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51e1:
	/* 0x51e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51e6:
	/* 0x51e6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_51e9:
	/* 0x51e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51eb:
	/* 0x51eb: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51f0:
	/* 0x51f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51f5:
	/* 0x51f5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51f9:
	/* 0x51f9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51fe:
	/* 0x51fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5203:
	/* 0x5203: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5208:
	/* 0x5208: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_520d:
	/* 0x520d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_520f:
	/* 0x520f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5214:
	/* 0x5214: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5217:
	/* 0x5217: je     53e4 <trace_ret_kernel_write_tail+0x53e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53e4;
	}
x86_l_521d:
	/* 0x521d: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5222:
	/* 0x5222: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5225:
	/* 0x5225: je     53e4 <trace_ret_kernel_write_tail+0x53e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53e4;
	}
x86_l_522b:
	/* 0x522b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_522f:
	/* 0x522f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5234:
	/* 0x5234: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5239:
	/* 0x5239: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_523e:
	/* 0x523e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5243:
	/* 0x5243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5245:
	/* 0x5245: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5249:
	/* 0x5249: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_524b:
	/* 0x524b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5251:
	/* 0x5251: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5253:
	/* 0x5253: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5255:
	/* 0x5255: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_525b:
	/* 0x525b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5260:
	/* 0x5260: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5266:
	/* 0x5266: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5269:
	/* 0x5269: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_526b:
	/* 0x526b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5270:
	/* 0x5270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5272:
	/* 0x5272: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5275:
	/* 0x5275: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_527b:
	/* 0x527b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_527e:
	/* 0x527e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5284:
	/* 0x5284: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5289:
	/* 0x5289: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_528b:
	/* 0x528b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5290:
	/* 0x5290: jmp    5460 <trace_ret_kernel_write_tail+0x5460> */
	goto x86_l_5460;
x86_l_5295:
	/* 0x5295: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5298:
	/* 0x5298: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_529e:
	/* 0x529e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a2:
	/* 0x52a2: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_52a7:
	/* 0x52a7: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_52ad:
	/* 0x52ad: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52b1:
	/* 0x52b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b6:
	/* 0x52b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52bb:
	/* 0x52bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52c0:
	/* 0x52c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c4:
	/* 0x52c4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52c8:
	/* 0x52c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52cd:
	/* 0x52cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52cf:
	/* 0x52cf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52d3:
	/* 0x52d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52d6:
	/* 0x52d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52db:
	/* 0x52db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52e0:
	/* 0x52e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52e4:
	/* 0x52e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52e9:
	/* 0x52e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52eb:
	/* 0x52eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52ef:
	/* 0x52ef: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52f4:
	/* 0x52f4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52f9:
	/* 0x52f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52fe:
	/* 0x52fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5302:
	/* 0x5302: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5307:
	/* 0x5307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5309:
	/* 0x5309: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_530d:
	/* 0x530d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5311:
	/* 0x5311: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5316:
	/* 0x5316: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_531b:
	/* 0x531b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5320:
	/* 0x5320: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5325:
	/* 0x5325: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_532a:
	/* 0x532a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_532f:
	/* 0x532f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5331:
	/* 0x5331: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5336:
	/* 0x5336: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_533b:
	/* 0x533b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_533f:
	/* 0x533f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5344:
	/* 0x5344: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5349:
	/* 0x5349: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_534e:
	/* 0x534e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5353:
	/* 0x5353: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5355:
	/* 0x5355: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535a:
	/* 0x535a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_535d:
	/* 0x535d: je     5523 <trace_ret_kernel_write_tail+0x5523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5523;
	}
x86_l_5363:
	/* 0x5363: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5368:
	/* 0x5368: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_536b:
	/* 0x536b: je     5523 <trace_ret_kernel_write_tail+0x5523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5523;
	}
x86_l_5371:
	/* 0x5371: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5375:
	/* 0x5375: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_537a:
	/* 0x537a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_537f:
	/* 0x537f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5384:
	/* 0x5384: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5389:
	/* 0x5389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_538b:
	/* 0x538b: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_538f:
	/* 0x538f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5391:
	/* 0x5391: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5397:
	/* 0x5397: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_539a:
	/* 0x539a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_539c:
	/* 0x539c: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_53a2:
	/* 0x53a2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53a7:
	/* 0x53a7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_53ad:
	/* 0x53ad: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_53b2:
	/* 0x53b2: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_53b4:
	/* 0x53b4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_53b9:
	/* 0x53b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53bb:
	/* 0x53bb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_53be:
	/* 0x53be: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_53c4:
	/* 0x53c4: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_53c8:
	/* 0x53c8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_53ce:
	/* 0x53ce: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_53d3:
	/* 0x53d3: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_53d7:
	/* 0x53d7: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_53da:
	/* 0x53da: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53df:
	/* 0x53df: jmp    55a4 <trace_ret_kernel_write_tail+0x55a4> */
	goto x86_l_55a4;
x86_l_53e4:
	/* 0x53e4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_53e7:
	/* 0x53e7: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_53ed:
	/* 0x53ed: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53f1:
	/* 0x53f1: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_53f6:
	/* 0x53f6: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_53fc:
	/* 0x53fc: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5400:
	/* 0x5400: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5405:
	/* 0x5405: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_540a:
	/* 0x540a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_540f:
	/* 0x540f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5413:
	/* 0x5413: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5417:
	/* 0x5417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_541c:
	/* 0x541c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_541e:
	/* 0x541e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5422:
	/* 0x5422: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5425:
	/* 0x5425: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_542a:
	/* 0x542a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_542f:
	/* 0x542f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5433:
	/* 0x5433: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5438:
	/* 0x5438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_543a:
	/* 0x543a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_543e:
	/* 0x543e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5443:
	/* 0x5443: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5448:
	/* 0x5448: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_544d:
	/* 0x544d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5451:
	/* 0x5451: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5456:
	/* 0x5456: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5458:
	/* 0x5458: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_545c:
	/* 0x545c: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5460:
	/* 0x5460: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5465:
	/* 0x5465: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_546a:
	/* 0x546a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_546f:
	/* 0x546f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5474:
	/* 0x5474: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5477:
	/* 0x5477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5479:
	/* 0x5479: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_547e:
	/* 0x547e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5483:
	/* 0x5483: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5487:
	/* 0x5487: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_548c:
	/* 0x548c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5491:
	/* 0x5491: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5496:
	/* 0x5496: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_549b:
	/* 0x549b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549d:
	/* 0x549d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a2:
	/* 0x54a2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_54a5:
	/* 0x54a5: je     5672 <trace_ret_kernel_write_tail+0x5672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5672;
	}
x86_l_54ab:
	/* 0x54ab: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54b0:
	/* 0x54b0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_54b3:
	/* 0x54b3: je     5672 <trace_ret_kernel_write_tail+0x5672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5672;
	}
x86_l_54b9:
	/* 0x54b9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_54bd:
	/* 0x54bd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54c2:
	/* 0x54c2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_54c7:
	/* 0x54c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54cc:
	/* 0x54cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_54d1:
	/* 0x54d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54d3:
	/* 0x54d3: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_54d7:
	/* 0x54d7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_54d9:
	/* 0x54d9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_54df:
	/* 0x54df: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_54e1:
	/* 0x54e1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_54e3:
	/* 0x54e3: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_54e9:
	/* 0x54e9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54ee:
	/* 0x54ee: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_54f4:
	/* 0x54f4: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54f7:
	/* 0x54f7: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_54f9:
	/* 0x54f9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_54fe:
	/* 0x54fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5500:
	/* 0x5500: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5503:
	/* 0x5503: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_5509:
	/* 0x5509: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_550c:
	/* 0x550c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5512:
	/* 0x5512: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5517:
	/* 0x5517: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5519:
	/* 0x5519: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_551e:
	/* 0x551e: jmp    56ee <trace_ret_kernel_write_tail+0x56ee> */
	goto x86_l_56ee;
x86_l_5523:
	/* 0x5523: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5526:
	/* 0x5526: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_552c:
	/* 0x552c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5530:
	/* 0x5530: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5535:
	/* 0x5535: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_553b:
	/* 0x553b: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_553f:
	/* 0x553f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5544:
	/* 0x5544: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5549:
	/* 0x5549: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_554e:
	/* 0x554e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5552:
	/* 0x5552: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5556:
	/* 0x5556: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_555b:
	/* 0x555b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555d:
	/* 0x555d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5561:
	/* 0x5561: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5564:
	/* 0x5564: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5569:
	/* 0x5569: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_556e:
	/* 0x556e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5572:
	/* 0x5572: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5577:
	/* 0x5577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5579:
	/* 0x5579: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_557d:
	/* 0x557d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5582:
	/* 0x5582: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5587:
	/* 0x5587: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_558c:
	/* 0x558c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5590:
	/* 0x5590: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5595:
	/* 0x5595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5597:
	/* 0x5597: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_559b:
	/* 0x559b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_559f:
	/* 0x559f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_55a4:
	/* 0x55a4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55a9:
	/* 0x55a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55ae:
	/* 0x55ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55b3:
	/* 0x55b3: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_55b8:
	/* 0x55b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55bd:
	/* 0x55bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55bf:
	/* 0x55bf: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55c4:
	/* 0x55c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55c9:
	/* 0x55c9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_55cd:
	/* 0x55cd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55d2:
	/* 0x55d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55d7:
	/* 0x55d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55dc:
	/* 0x55dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55e1:
	/* 0x55e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55e3:
	/* 0x55e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55e8:
	/* 0x55e8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_55eb:
	/* 0x55eb: je     57b1 <trace_ret_kernel_write_tail+0x57b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22449ULL;
	}
x86_l_55f1:
	/* 0x55f1: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55f6:
	/* 0x55f6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_55f9:
	/* 0x55f9: je     57b1 <trace_ret_kernel_write_tail+0x57b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22449ULL;
	}
x86_l_55ff:
	/* 0x55ff: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5603:
	/* 0x5603: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5608:
	/* 0x5608: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_560d:
	/* 0x560d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5612:
	/* 0x5612: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5617:
	/* 0x5617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5619:
	/* 0x5619: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_561d:
	/* 0x561d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_561f:
	/* 0x561f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5625:
	/* 0x5625: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5628:
	/* 0x5628: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_562a:
	/* 0x562a: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_5630:
	/* 0x5630: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5635:
	/* 0x5635: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_563b:
	/* 0x563b: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_5640:
	/* 0x5640: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5642:
	/* 0x5642: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5647:
	/* 0x5647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5649:
	/* 0x5649: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_564c:
	/* 0x564c: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_5652:
	/* 0x5652: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5656:
	/* 0x5656: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_565c:
	/* 0x565c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5661:
	/* 0x5661: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5665:
	/* 0x5665: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5668:
	/* 0x5668: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_566d:
	/* 0x566d: jmp    5832 <trace_ret_kernel_write_tail+0x5832> */
	return 22578ULL;
x86_l_5672:
	/* 0x5672: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5675:
	/* 0x5675: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_567b:
	/* 0x567b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_567f:
	/* 0x567f: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5684:
	/* 0x5684: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_568a:
	/* 0x568a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_568e:
	/* 0x568e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5693:
	/* 0x5693: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5698:
	/* 0x5698: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_569d:
	/* 0x569d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56a1:
	/* 0x56a1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_56a5:
	/* 0x56a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56aa:
	/* 0x56aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ac:
	/* 0x56ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56b0:
	/* 0x56b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56b3:
	/* 0x56b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56b8:
	/* 0x56b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56bd:
	/* 0x56bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56c1:
	/* 0x56c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56c6:
	/* 0x56c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56c8:
	/* 0x56c8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56cc:
	/* 0x56cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56d1:
	/* 0x56d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56d6:
	/* 0x56d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56db:
	/* 0x56db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56df:
	/* 0x56df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56e4:
	/* 0x56e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e6:
	/* 0x56e6: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56ea:
	/* 0x56ea: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_56ee:
	/* 0x56ee: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_56f3:
	/* 0x56f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_56f8:
	/* 0x56f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56fd:
	/* 0x56fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5702:
	/* 0x5702: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5705:
	/* 0x5705: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5707:
	/* 0x5707: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_570c:
	/* 0x570c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5711:
	/* 0x5711: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5715:
	/* 0x5715: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_571a:
	/* 0x571a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_571f:
	/* 0x571f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5724:
	/* 0x5724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5729:
	/* 0x5729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572b:
	/* 0x572b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5730:
	/* 0x5730: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5733:
	/* 0x5733: je     5900 <trace_ret_kernel_write_tail+0x5900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22784ULL;
	}
x86_l_5739:
	/* 0x5739: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_573e:
	/* 0x573e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5741:
	/* 0x5741: je     5900 <trace_ret_kernel_write_tail+0x5900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22784ULL;
	}
x86_l_5747:
	/* 0x5747: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_574b:
	/* 0x574b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5750:
	/* 0x5750: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5755:
	/* 0x5755: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_575a:
	/* 0x575a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_575f:
	/* 0x575f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5761:
	/* 0x5761: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5765:
	/* 0x5765: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5767:
	/* 0x5767: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_576d:
	/* 0x576d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_576f:
	/* 0x576f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5771:
	/* 0x5771: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_5777:
	/* 0x5777: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_577c:
	/* 0x577c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5782:
	/* 0x5782: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5785:
	/* 0x5785: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5787:
	/* 0x5787: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_578c:
	/* 0x578c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_578e:
	/* 0x578e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5791:
	/* 0x5791: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_5797:
	/* 0x5797: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_579a:
	/* 0x579a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_57a0:
	/* 0x57a0: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_57a5:
	/* 0x57a5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_57a7:
	/* 0x57a7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57ac:
	/* 0x57ac: jmp    597c <trace_ret_kernel_write_tail+0x597c> */
	return 22908ULL;
	return 22449ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22449ULL: goto x86_l_57b1;
	case 22452ULL: goto x86_l_57b4;
	case 22458ULL: goto x86_l_57ba;
	case 22462ULL: goto x86_l_57be;
	case 22467ULL: goto x86_l_57c3;
	case 22473ULL: goto x86_l_57c9;
	case 22477ULL: goto x86_l_57cd;
	case 22482ULL: goto x86_l_57d2;
	case 22487ULL: goto x86_l_57d7;
	case 22492ULL: goto x86_l_57dc;
	case 22496ULL: goto x86_l_57e0;
	case 22500ULL: goto x86_l_57e4;
	case 22505ULL: goto x86_l_57e9;
	case 22507ULL: goto x86_l_57eb;
	case 22511ULL: goto x86_l_57ef;
	case 22514ULL: goto x86_l_57f2;
	case 22519ULL: goto x86_l_57f7;
	case 22524ULL: goto x86_l_57fc;
	case 22528ULL: goto x86_l_5800;
	case 22533ULL: goto x86_l_5805;
	case 22535ULL: goto x86_l_5807;
	case 22539ULL: goto x86_l_580b;
	case 22544ULL: goto x86_l_5810;
	case 22549ULL: goto x86_l_5815;
	case 22554ULL: goto x86_l_581a;
	case 22558ULL: goto x86_l_581e;
	case 22563ULL: goto x86_l_5823;
	case 22565ULL: goto x86_l_5825;
	case 22569ULL: goto x86_l_5829;
	case 22573ULL: goto x86_l_582d;
	case 22578ULL: goto x86_l_5832;
	case 22583ULL: goto x86_l_5837;
	case 22588ULL: goto x86_l_583c;
	case 22593ULL: goto x86_l_5841;
	case 22598ULL: goto x86_l_5846;
	case 22603ULL: goto x86_l_584b;
	case 22605ULL: goto x86_l_584d;
	case 22610ULL: goto x86_l_5852;
	case 22615ULL: goto x86_l_5857;
	case 22619ULL: goto x86_l_585b;
	case 22624ULL: goto x86_l_5860;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22639ULL: goto x86_l_586f;
	case 22641ULL: goto x86_l_5871;
	case 22646ULL: goto x86_l_5876;
	case 22649ULL: goto x86_l_5879;
	case 22655ULL: goto x86_l_587f;
	case 22660ULL: goto x86_l_5884;
	case 22663ULL: goto x86_l_5887;
	case 22669ULL: goto x86_l_588d;
	case 22673ULL: goto x86_l_5891;
	case 22678ULL: goto x86_l_5896;
	case 22683ULL: goto x86_l_589b;
	case 22688ULL: goto x86_l_58a0;
	case 22693ULL: goto x86_l_58a5;
	case 22695ULL: goto x86_l_58a7;
	case 22699ULL: goto x86_l_58ab;
	case 22701ULL: goto x86_l_58ad;
	case 22707ULL: goto x86_l_58b3;
	case 22710ULL: goto x86_l_58b6;
	case 22712ULL: goto x86_l_58b8;
	case 22718ULL: goto x86_l_58be;
	case 22723ULL: goto x86_l_58c3;
	case 22729ULL: goto x86_l_58c9;
	case 22734ULL: goto x86_l_58ce;
	case 22736ULL: goto x86_l_58d0;
	case 22741ULL: goto x86_l_58d5;
	case 22743ULL: goto x86_l_58d7;
	case 22746ULL: goto x86_l_58da;
	case 22752ULL: goto x86_l_58e0;
	case 22756ULL: goto x86_l_58e4;
	case 22762ULL: goto x86_l_58ea;
	case 22767ULL: goto x86_l_58ef;
	case 22771ULL: goto x86_l_58f3;
	case 22774ULL: goto x86_l_58f6;
	case 22779ULL: goto x86_l_58fb;
	case 22784ULL: goto x86_l_5900;
	case 22787ULL: goto x86_l_5903;
	case 22793ULL: goto x86_l_5909;
	case 22797ULL: goto x86_l_590d;
	case 22802ULL: goto x86_l_5912;
	case 22808ULL: goto x86_l_5918;
	case 22812ULL: goto x86_l_591c;
	case 22817ULL: goto x86_l_5921;
	case 22822ULL: goto x86_l_5926;
	case 22827ULL: goto x86_l_592b;
	case 22831ULL: goto x86_l_592f;
	case 22835ULL: goto x86_l_5933;
	case 22840ULL: goto x86_l_5938;
	case 22842ULL: goto x86_l_593a;
	case 22846ULL: goto x86_l_593e;
	case 22849ULL: goto x86_l_5941;
	case 22854ULL: goto x86_l_5946;
	case 22859ULL: goto x86_l_594b;
	case 22863ULL: goto x86_l_594f;
	case 22868ULL: goto x86_l_5954;
	case 22870ULL: goto x86_l_5956;
	case 22874ULL: goto x86_l_595a;
	case 22879ULL: goto x86_l_595f;
	case 22884ULL: goto x86_l_5964;
	case 22889ULL: goto x86_l_5969;
	case 22893ULL: goto x86_l_596d;
	case 22898ULL: goto x86_l_5972;
	case 22900ULL: goto x86_l_5974;
	case 22904ULL: goto x86_l_5978;
	case 22908ULL: goto x86_l_597c;
	case 22913ULL: goto x86_l_5981;
	case 22918ULL: goto x86_l_5986;
	case 22923ULL: goto x86_l_598b;
	case 22928ULL: goto x86_l_5990;
	case 22931ULL: goto x86_l_5993;
	case 22933ULL: goto x86_l_5995;
	case 22938ULL: goto x86_l_599a;
	case 22943ULL: goto x86_l_599f;
	case 22947ULL: goto x86_l_59a3;
	case 22952ULL: goto x86_l_59a8;
	case 22957ULL: goto x86_l_59ad;
	case 22962ULL: goto x86_l_59b2;
	case 22967ULL: goto x86_l_59b7;
	case 22969ULL: goto x86_l_59b9;
	case 22974ULL: goto x86_l_59be;
	case 22977ULL: goto x86_l_59c1;
	case 22983ULL: goto x86_l_59c7;
	case 22988ULL: goto x86_l_59cc;
	case 22991ULL: goto x86_l_59cf;
	case 22997ULL: goto x86_l_59d5;
	case 23001ULL: goto x86_l_59d9;
	case 23006ULL: goto x86_l_59de;
	case 23011ULL: goto x86_l_59e3;
	case 23016ULL: goto x86_l_59e8;
	case 23021ULL: goto x86_l_59ed;
	case 23023ULL: goto x86_l_59ef;
	case 23027ULL: goto x86_l_59f3;
	case 23029ULL: goto x86_l_59f5;
	case 23035ULL: goto x86_l_59fb;
	case 23037ULL: goto x86_l_59fd;
	case 23039ULL: goto x86_l_59ff;
	case 23045ULL: goto x86_l_5a05;
	case 23050ULL: goto x86_l_5a0a;
	case 23056ULL: goto x86_l_5a10;
	case 23059ULL: goto x86_l_5a13;
	case 23061ULL: goto x86_l_5a15;
	case 23066ULL: goto x86_l_5a1a;
	case 23068ULL: goto x86_l_5a1c;
	case 23071ULL: goto x86_l_5a1f;
	case 23077ULL: goto x86_l_5a25;
	case 23080ULL: goto x86_l_5a28;
	case 23086ULL: goto x86_l_5a2e;
	case 23091ULL: goto x86_l_5a33;
	case 23093ULL: goto x86_l_5a35;
	case 23098ULL: goto x86_l_5a3a;
	case 23103ULL: goto x86_l_5a3f;
	case 23106ULL: goto x86_l_5a42;
	case 23112ULL: goto x86_l_5a48;
	case 23116ULL: goto x86_l_5a4c;
	case 23121ULL: goto x86_l_5a51;
	case 23127ULL: goto x86_l_5a57;
	case 23131ULL: goto x86_l_5a5b;
	case 23136ULL: goto x86_l_5a60;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23150ULL: goto x86_l_5a6e;
	case 23154ULL: goto x86_l_5a72;
	case 23159ULL: goto x86_l_5a77;
	case 23161ULL: goto x86_l_5a79;
	case 23165ULL: goto x86_l_5a7d;
	case 23168ULL: goto x86_l_5a80;
	case 23173ULL: goto x86_l_5a85;
	case 23178ULL: goto x86_l_5a8a;
	case 23182ULL: goto x86_l_5a8e;
	case 23187ULL: goto x86_l_5a93;
	case 23189ULL: goto x86_l_5a95;
	case 23193ULL: goto x86_l_5a99;
	case 23198ULL: goto x86_l_5a9e;
	case 23203ULL: goto x86_l_5aa3;
	case 23208ULL: goto x86_l_5aa8;
	case 23212ULL: goto x86_l_5aac;
	case 23217ULL: goto x86_l_5ab1;
	case 23219ULL: goto x86_l_5ab3;
	case 23223ULL: goto x86_l_5ab7;
	case 23227ULL: goto x86_l_5abb;
	case 23232ULL: goto x86_l_5ac0;
	case 23237ULL: goto x86_l_5ac5;
	case 23242ULL: goto x86_l_5aca;
	case 23247ULL: goto x86_l_5acf;
	case 23252ULL: goto x86_l_5ad4;
	case 23257ULL: goto x86_l_5ad9;
	case 23259ULL: goto x86_l_5adb;
	case 23264ULL: goto x86_l_5ae0;
	case 23269ULL: goto x86_l_5ae5;
	case 23273ULL: goto x86_l_5ae9;
	case 23278ULL: goto x86_l_5aee;
	case 23283ULL: goto x86_l_5af3;
	case 23288ULL: goto x86_l_5af8;
	case 23293ULL: goto x86_l_5afd;
	case 23295ULL: goto x86_l_5aff;
	case 23300ULL: goto x86_l_5b04;
	case 23303ULL: goto x86_l_5b07;
	case 23309ULL: goto x86_l_5b0d;
	case 23314ULL: goto x86_l_5b12;
	case 23317ULL: goto x86_l_5b15;
	case 23323ULL: goto x86_l_5b1b;
	case 23327ULL: goto x86_l_5b1f;
	case 23332ULL: goto x86_l_5b24;
	case 23337ULL: goto x86_l_5b29;
	case 23342ULL: goto x86_l_5b2e;
	case 23347ULL: goto x86_l_5b33;
	case 23349ULL: goto x86_l_5b35;
	case 23353ULL: goto x86_l_5b39;
	case 23355ULL: goto x86_l_5b3b;
	case 23361ULL: goto x86_l_5b41;
	case 23364ULL: goto x86_l_5b44;
	case 23366ULL: goto x86_l_5b46;
	case 23372ULL: goto x86_l_5b4c;
	case 23377ULL: goto x86_l_5b51;
	case 23383ULL: goto x86_l_5b57;
	case 23388ULL: goto x86_l_5b5c;
	case 23390ULL: goto x86_l_5b5e;
	case 23395ULL: goto x86_l_5b63;
	case 23397ULL: goto x86_l_5b65;
	case 23400ULL: goto x86_l_5b68;
	case 23406ULL: goto x86_l_5b6e;
	case 23410ULL: goto x86_l_5b72;
	case 23416ULL: goto x86_l_5b78;
	case 23421ULL: goto x86_l_5b7d;
	case 23425ULL: goto x86_l_5b81;
	case 23428ULL: goto x86_l_5b84;
	case 23433ULL: goto x86_l_5b89;
	case 23438ULL: goto x86_l_5b8e;
	case 23441ULL: goto x86_l_5b91;
	case 23447ULL: goto x86_l_5b97;
	case 23451ULL: goto x86_l_5b9b;
	case 23456ULL: goto x86_l_5ba0;
	case 23462ULL: goto x86_l_5ba6;
	case 23466ULL: goto x86_l_5baa;
	case 23471ULL: goto x86_l_5baf;
	case 23476ULL: goto x86_l_5bb4;
	case 23481ULL: goto x86_l_5bb9;
	case 23485ULL: goto x86_l_5bbd;
	case 23489ULL: goto x86_l_5bc1;
	case 23494ULL: goto x86_l_5bc6;
	case 23496ULL: goto x86_l_5bc8;
	case 23500ULL: goto x86_l_5bcc;
	case 23503ULL: goto x86_l_5bcf;
	case 23508ULL: goto x86_l_5bd4;
	case 23513ULL: goto x86_l_5bd9;
	case 23517ULL: goto x86_l_5bdd;
	case 23522ULL: goto x86_l_5be2;
	case 23524ULL: goto x86_l_5be4;
	case 23528ULL: goto x86_l_5be8;
	case 23533ULL: goto x86_l_5bed;
	case 23538ULL: goto x86_l_5bf2;
	case 23543ULL: goto x86_l_5bf7;
	case 23547ULL: goto x86_l_5bfb;
	case 23552ULL: goto x86_l_5c00;
	case 23554ULL: goto x86_l_5c02;
	case 23558ULL: goto x86_l_5c06;
	case 23562ULL: goto x86_l_5c0a;
	case 23567ULL: goto x86_l_5c0f;
	case 23572ULL: goto x86_l_5c14;
	case 23577ULL: goto x86_l_5c19;
	case 23582ULL: goto x86_l_5c1e;
	case 23585ULL: goto x86_l_5c21;
	case 23587ULL: goto x86_l_5c23;
	case 23592ULL: goto x86_l_5c28;
	case 23597ULL: goto x86_l_5c2d;
	case 23601ULL: goto x86_l_5c31;
	case 23606ULL: goto x86_l_5c36;
	case 23611ULL: goto x86_l_5c3b;
	case 23616ULL: goto x86_l_5c40;
	case 23621ULL: goto x86_l_5c45;
	case 23623ULL: goto x86_l_5c47;
	case 23628ULL: goto x86_l_5c4c;
	case 23631ULL: goto x86_l_5c4f;
	case 23637ULL: goto x86_l_5c55;
	case 23642ULL: goto x86_l_5c5a;
	case 23645ULL: goto x86_l_5c5d;
	case 23651ULL: goto x86_l_5c63;
	case 23655ULL: goto x86_l_5c67;
	case 23660ULL: goto x86_l_5c6c;
	case 23665ULL: goto x86_l_5c71;
	case 23670ULL: goto x86_l_5c76;
	case 23675ULL: goto x86_l_5c7b;
	case 23677ULL: goto x86_l_5c7d;
	case 23681ULL: goto x86_l_5c81;
	case 23683ULL: goto x86_l_5c83;
	case 23689ULL: goto x86_l_5c89;
	case 23691ULL: goto x86_l_5c8b;
	case 23693ULL: goto x86_l_5c8d;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23710ULL: goto x86_l_5c9e;
	case 23713ULL: goto x86_l_5ca1;
	case 23715ULL: goto x86_l_5ca3;
	case 23720ULL: goto x86_l_5ca8;
	case 23722ULL: goto x86_l_5caa;
	case 23725ULL: goto x86_l_5cad;
	case 23731ULL: goto x86_l_5cb3;
	case 23734ULL: goto x86_l_5cb6;
	case 23740ULL: goto x86_l_5cbc;
	case 23745ULL: goto x86_l_5cc1;
	case 23747ULL: goto x86_l_5cc3;
	case 23752ULL: goto x86_l_5cc8;
	case 23757ULL: goto x86_l_5ccd;
	case 23760ULL: goto x86_l_5cd0;
	case 23766ULL: goto x86_l_5cd6;
	case 23770ULL: goto x86_l_5cda;
	case 23775ULL: goto x86_l_5cdf;
	case 23781ULL: goto x86_l_5ce5;
	case 23785ULL: goto x86_l_5ce9;
	case 23790ULL: goto x86_l_5cee;
	case 23795ULL: goto x86_l_5cf3;
	case 23800ULL: goto x86_l_5cf8;
	case 23804ULL: goto x86_l_5cfc;
	case 23808ULL: goto x86_l_5d00;
	case 23813ULL: goto x86_l_5d05;
	case 23815ULL: goto x86_l_5d07;
	case 23819ULL: goto x86_l_5d0b;
	case 23822ULL: goto x86_l_5d0e;
	case 23827ULL: goto x86_l_5d13;
	case 23832ULL: goto x86_l_5d18;
	case 23836ULL: goto x86_l_5d1c;
	case 23841ULL: goto x86_l_5d21;
	case 23843ULL: goto x86_l_5d23;
	case 23847ULL: goto x86_l_5d27;
	case 23852ULL: goto x86_l_5d2c;
	case 23857ULL: goto x86_l_5d31;
	case 23862ULL: goto x86_l_5d36;
	case 23866ULL: goto x86_l_5d3a;
	case 23871ULL: goto x86_l_5d3f;
	case 23873ULL: goto x86_l_5d41;
	case 23877ULL: goto x86_l_5d45;
	case 23881ULL: goto x86_l_5d49;
	case 23886ULL: goto x86_l_5d4e;
	case 23891ULL: goto x86_l_5d53;
	case 23896ULL: goto x86_l_5d58;
	case 23901ULL: goto x86_l_5d5d;
	case 23906ULL: goto x86_l_5d62;
	case 23911ULL: goto x86_l_5d67;
	case 23913ULL: goto x86_l_5d69;
	case 23918ULL: goto x86_l_5d6e;
	case 23923ULL: goto x86_l_5d73;
	case 23927ULL: goto x86_l_5d77;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23942ULL: goto x86_l_5d86;
	case 23947ULL: goto x86_l_5d8b;
	case 23949ULL: goto x86_l_5d8d;
	case 23954ULL: goto x86_l_5d92;
	case 23957ULL: goto x86_l_5d95;
	case 23963ULL: goto x86_l_5d9b;
	case 23968ULL: goto x86_l_5da0;
	case 23971ULL: goto x86_l_5da3;
	case 23977ULL: goto x86_l_5da9;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23991ULL: goto x86_l_5db7;
	case 23996ULL: goto x86_l_5dbc;
	case 24001ULL: goto x86_l_5dc1;
	case 24003ULL: goto x86_l_5dc3;
	case 24007ULL: goto x86_l_5dc7;
	case 24009ULL: goto x86_l_5dc9;
	case 24015ULL: goto x86_l_5dcf;
	case 24018ULL: goto x86_l_5dd2;
	case 24020ULL: goto x86_l_5dd4;
	case 24026ULL: goto x86_l_5dda;
	case 24031ULL: goto x86_l_5ddf;
	case 24037ULL: goto x86_l_5de5;
	case 24042ULL: goto x86_l_5dea;
	case 24044ULL: goto x86_l_5dec;
	case 24049ULL: goto x86_l_5df1;
	case 24051ULL: goto x86_l_5df3;
	case 24054ULL: goto x86_l_5df6;
	case 24060ULL: goto x86_l_5dfc;
	case 24064ULL: goto x86_l_5e00;
	case 24070ULL: goto x86_l_5e06;
	case 24075ULL: goto x86_l_5e0b;
	case 24079ULL: goto x86_l_5e0f;
	case 24082ULL: goto x86_l_5e12;
	case 24087ULL: goto x86_l_5e17;
	case 24092ULL: goto x86_l_5e1c;
	case 24095ULL: goto x86_l_5e1f;
	case 24101ULL: goto x86_l_5e25;
	default: return 0xffffffffffffffffULL;
	}
x86_l_57b1:
	/* 0x57b1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_57b4:
	/* 0x57b4: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_57ba:
	/* 0x57ba: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57be:
	/* 0x57be: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_57c3:
	/* 0x57c3: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_57c9:
	/* 0x57c9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57cd:
	/* 0x57cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d2:
	/* 0x57d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57d7:
	/* 0x57d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57dc:
	/* 0x57dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57e0:
	/* 0x57e0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57e4:
	/* 0x57e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e9:
	/* 0x57e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57eb:
	/* 0x57eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57ef:
	/* 0x57ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57f2:
	/* 0x57f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57f7:
	/* 0x57f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57fc:
	/* 0x57fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5800:
	/* 0x5800: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5805:
	/* 0x5805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5807:
	/* 0x5807: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_580b:
	/* 0x580b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5810:
	/* 0x5810: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5815:
	/* 0x5815: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_581a:
	/* 0x581a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_581e:
	/* 0x581e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5823:
	/* 0x5823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5825:
	/* 0x5825: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5829:
	/* 0x5829: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_582d:
	/* 0x582d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5832:
	/* 0x5832: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5837:
	/* 0x5837: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_583c:
	/* 0x583c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5841:
	/* 0x5841: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5846:
	/* 0x5846: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_584b:
	/* 0x584b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_584d:
	/* 0x584d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5852:
	/* 0x5852: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5857:
	/* 0x5857: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_585b:
	/* 0x585b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5860:
	/* 0x5860: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5865:
	/* 0x5865: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_586a:
	/* 0x586a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_586f:
	/* 0x586f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5871:
	/* 0x5871: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5876:
	/* 0x5876: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5879:
	/* 0x5879: je     5a3f <trace_ret_kernel_write_tail+0x5a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3f;
	}
x86_l_587f:
	/* 0x587f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5884:
	/* 0x5884: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5887:
	/* 0x5887: je     5a3f <trace_ret_kernel_write_tail+0x5a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3f;
	}
x86_l_588d:
	/* 0x588d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5891:
	/* 0x5891: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5896:
	/* 0x5896: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_589b:
	/* 0x589b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58a0:
	/* 0x58a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_58a5:
	/* 0x58a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a7:
	/* 0x58a7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_58ab:
	/* 0x58ab: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_58ad:
	/* 0x58ad: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58b3:
	/* 0x58b3: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_58b6:
	/* 0x58b6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_58b8:
	/* 0x58b8: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_58be:
	/* 0x58be: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58c3:
	/* 0x58c3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_58c9:
	/* 0x58c9: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_58ce:
	/* 0x58ce: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_58d0:
	/* 0x58d0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_58d5:
	/* 0x58d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58d7:
	/* 0x58d7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_58da:
	/* 0x58da: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_58e0:
	/* 0x58e0: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_58e4:
	/* 0x58e4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_58ea:
	/* 0x58ea: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_58ef:
	/* 0x58ef: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_58f3:
	/* 0x58f3: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_58f6:
	/* 0x58f6: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58fb:
	/* 0x58fb: jmp    5ac0 <trace_ret_kernel_write_tail+0x5ac0> */
	goto x86_l_5ac0;
x86_l_5900:
	/* 0x5900: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5903:
	/* 0x5903: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_5909:
	/* 0x5909: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_590d:
	/* 0x590d: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5912:
	/* 0x5912: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_5918:
	/* 0x5918: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_591c:
	/* 0x591c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5921:
	/* 0x5921: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5926:
	/* 0x5926: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_592b:
	/* 0x592b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_592f:
	/* 0x592f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5933:
	/* 0x5933: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5938:
	/* 0x5938: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_593a:
	/* 0x593a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_593e:
	/* 0x593e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5941:
	/* 0x5941: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5946:
	/* 0x5946: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_594b:
	/* 0x594b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_594f:
	/* 0x594f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5954:
	/* 0x5954: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5956:
	/* 0x5956: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_595a:
	/* 0x595a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_595f:
	/* 0x595f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5964:
	/* 0x5964: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5969:
	/* 0x5969: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_596d:
	/* 0x596d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5972:
	/* 0x5972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5974:
	/* 0x5974: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5978:
	/* 0x5978: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_597c:
	/* 0x597c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5981:
	/* 0x5981: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5986:
	/* 0x5986: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_598b:
	/* 0x598b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5990:
	/* 0x5990: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5993:
	/* 0x5993: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5995:
	/* 0x5995: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_599a:
	/* 0x599a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_599f:
	/* 0x599f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59a3:
	/* 0x59a3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59a8:
	/* 0x59a8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_59ad:
	/* 0x59ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59b2:
	/* 0x59b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59b7:
	/* 0x59b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59b9:
	/* 0x59b9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59be:
	/* 0x59be: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_59c1:
	/* 0x59c1: je     5b8e <trace_ret_kernel_write_tail+0x5b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b8e;
	}
x86_l_59c7:
	/* 0x59c7: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59cc:
	/* 0x59cc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_59cf:
	/* 0x59cf: je     5b8e <trace_ret_kernel_write_tail+0x5b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b8e;
	}
x86_l_59d5:
	/* 0x59d5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_59d9:
	/* 0x59d9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59de:
	/* 0x59de: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_59e3:
	/* 0x59e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59e8:
	/* 0x59e8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_59ed:
	/* 0x59ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ef:
	/* 0x59ef: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_59f3:
	/* 0x59f3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_59f5:
	/* 0x59f5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_59fb:
	/* 0x59fb: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_59fd:
	/* 0x59fd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_59ff:
	/* 0x59ff: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_5a05:
	/* 0x5a05: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a0a:
	/* 0x5a0a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5a10:
	/* 0x5a10: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a13:
	/* 0x5a13: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5a15:
	/* 0x5a15: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5a1a:
	/* 0x5a1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a1c:
	/* 0x5a1c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a1f:
	/* 0x5a1f: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_5a25:
	/* 0x5a25: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5a28:
	/* 0x5a28: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5a2e:
	/* 0x5a2e: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5a33:
	/* 0x5a33: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a35:
	/* 0x5a35: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a3a:
	/* 0x5a3a: jmp    5c0a <trace_ret_kernel_write_tail+0x5c0a> */
	goto x86_l_5c0a;
x86_l_5a3f:
	/* 0x5a3f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5a42:
	/* 0x5a42: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_5a48:
	/* 0x5a48: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a4c:
	/* 0x5a4c: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5a51:
	/* 0x5a51: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_5a57:
	/* 0x5a57: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a5b:
	/* 0x5a5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a60:
	/* 0x5a60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a65:
	/* 0x5a65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a6a:
	/* 0x5a6a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a6e:
	/* 0x5a6e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a72:
	/* 0x5a72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a77:
	/* 0x5a77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a79:
	/* 0x5a79: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a7d:
	/* 0x5a7d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a80:
	/* 0x5a80: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a85:
	/* 0x5a85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a8a:
	/* 0x5a8a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a8e:
	/* 0x5a8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a93:
	/* 0x5a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a95:
	/* 0x5a95: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a99:
	/* 0x5a99: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a9e:
	/* 0x5a9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5aa3:
	/* 0x5aa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5aa8:
	/* 0x5aa8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aac:
	/* 0x5aac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ab1:
	/* 0x5ab1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab3:
	/* 0x5ab3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ab7:
	/* 0x5ab7: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5abb:
	/* 0x5abb: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5ac0:
	/* 0x5ac0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ac5:
	/* 0x5ac5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5aca:
	/* 0x5aca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5acf:
	/* 0x5acf: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5ad4:
	/* 0x5ad4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ad9:
	/* 0x5ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5adb:
	/* 0x5adb: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ae0:
	/* 0x5ae0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae5:
	/* 0x5ae5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ae9:
	/* 0x5ae9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aee:
	/* 0x5aee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5af3:
	/* 0x5af3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5af8:
	/* 0x5af8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5afd:
	/* 0x5afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aff:
	/* 0x5aff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b04:
	/* 0x5b04: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5b07:
	/* 0x5b07: je     5ccd <trace_ret_kernel_write_tail+0x5ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ccd;
	}
x86_l_5b0d:
	/* 0x5b0d: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b12:
	/* 0x5b12: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5b15:
	/* 0x5b15: je     5ccd <trace_ret_kernel_write_tail+0x5ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ccd;
	}
x86_l_5b1b:
	/* 0x5b1b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b1f:
	/* 0x5b1f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b24:
	/* 0x5b24: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5b29:
	/* 0x5b29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b2e:
	/* 0x5b2e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5b33:
	/* 0x5b33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b35:
	/* 0x5b35: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5b39:
	/* 0x5b39: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5b3b:
	/* 0x5b3b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b41:
	/* 0x5b41: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5b44:
	/* 0x5b44: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b46:
	/* 0x5b46: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_5b4c:
	/* 0x5b4c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b51:
	/* 0x5b51: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5b57:
	/* 0x5b57: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_5b5c:
	/* 0x5b5c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5b5e:
	/* 0x5b5e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5b63:
	/* 0x5b63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b65:
	/* 0x5b65: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b68:
	/* 0x5b68: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_5b6e:
	/* 0x5b6e: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5b72:
	/* 0x5b72: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5b78:
	/* 0x5b78: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b7d:
	/* 0x5b7d: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5b81:
	/* 0x5b81: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b84:
	/* 0x5b84: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b89:
	/* 0x5b89: jmp    5d4e <trace_ret_kernel_write_tail+0x5d4e> */
	goto x86_l_5d4e;
x86_l_5b8e:
	/* 0x5b8e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5b91:
	/* 0x5b91: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_5b97:
	/* 0x5b97: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b9b:
	/* 0x5b9b: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5ba0:
	/* 0x5ba0: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_5ba6:
	/* 0x5ba6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5baa:
	/* 0x5baa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5baf:
	/* 0x5baf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bb4:
	/* 0x5bb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bb9:
	/* 0x5bb9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bbd:
	/* 0x5bbd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5bc1:
	/* 0x5bc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bc6:
	/* 0x5bc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc8:
	/* 0x5bc8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bcc:
	/* 0x5bcc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5bcf:
	/* 0x5bcf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bd4:
	/* 0x5bd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bd9:
	/* 0x5bd9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bdd:
	/* 0x5bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5be2:
	/* 0x5be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5be4:
	/* 0x5be4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5be8:
	/* 0x5be8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5bed:
	/* 0x5bed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bf2:
	/* 0x5bf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bf7:
	/* 0x5bf7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bfb:
	/* 0x5bfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c00:
	/* 0x5c00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c02:
	/* 0x5c02: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c06:
	/* 0x5c06: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c0a:
	/* 0x5c0a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c0f:
	/* 0x5c0f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c14:
	/* 0x5c14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c19:
	/* 0x5c19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c1e:
	/* 0x5c1e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5c21:
	/* 0x5c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c23:
	/* 0x5c23: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c28:
	/* 0x5c28: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c2d:
	/* 0x5c2d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c31:
	/* 0x5c31: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c36:
	/* 0x5c36: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c3b:
	/* 0x5c3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c40:
	/* 0x5c40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c45:
	/* 0x5c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c47:
	/* 0x5c47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4c:
	/* 0x5c4c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5c4f:
	/* 0x5c4f: je     5e1c <trace_ret_kernel_write_tail+0x5e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e1c;
	}
x86_l_5c55:
	/* 0x5c55: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c5a:
	/* 0x5c5a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5c5d:
	/* 0x5c5d: je     5e1c <trace_ret_kernel_write_tail+0x5e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e1c;
	}
x86_l_5c63:
	/* 0x5c63: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c67:
	/* 0x5c67: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c6c:
	/* 0x5c6c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5c71:
	/* 0x5c71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c76:
	/* 0x5c76: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5c7b:
	/* 0x5c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c7d:
	/* 0x5c7d: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5c81:
	/* 0x5c81: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5c83:
	/* 0x5c83: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c89:
	/* 0x5c89: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5c8b:
	/* 0x5c8b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c8d:
	/* 0x5c8d: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_5c93:
	/* 0x5c93: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c98:
	/* 0x5c98: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5c9e:
	/* 0x5c9e: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ca1:
	/* 0x5ca1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5ca3:
	/* 0x5ca3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5ca8:
	/* 0x5ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5caa:
	/* 0x5caa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5cad:
	/* 0x5cad: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_5cb3:
	/* 0x5cb3: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5cb6:
	/* 0x5cb6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5cbc:
	/* 0x5cbc: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5cc1:
	/* 0x5cc1: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5cc3:
	/* 0x5cc3: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc8:
	/* 0x5cc8: jmp    5e98 <trace_ret_kernel_write_tail+0x5e98> */
	return 24216ULL;
x86_l_5ccd:
	/* 0x5ccd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5cd0:
	/* 0x5cd0: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_5cd6:
	/* 0x5cd6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cda:
	/* 0x5cda: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5cdf:
	/* 0x5cdf: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_5ce5:
	/* 0x5ce5: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ce9:
	/* 0x5ce9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cee:
	/* 0x5cee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cf3:
	/* 0x5cf3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cf8:
	/* 0x5cf8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cfc:
	/* 0x5cfc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d00:
	/* 0x5d00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d05:
	/* 0x5d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d07:
	/* 0x5d07: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d0b:
	/* 0x5d0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d0e:
	/* 0x5d0e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d13:
	/* 0x5d13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d18:
	/* 0x5d18: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d1c:
	/* 0x5d1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d21:
	/* 0x5d21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d23:
	/* 0x5d23: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d27:
	/* 0x5d27: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d2c:
	/* 0x5d2c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d31:
	/* 0x5d31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d36:
	/* 0x5d36: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d3a:
	/* 0x5d3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d3f:
	/* 0x5d3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d41:
	/* 0x5d41: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d45:
	/* 0x5d45: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d49:
	/* 0x5d49: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5d4e:
	/* 0x5d4e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d53:
	/* 0x5d53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d58:
	/* 0x5d58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d5d:
	/* 0x5d5d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5d62:
	/* 0x5d62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d67:
	/* 0x5d67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d69:
	/* 0x5d69: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d6e:
	/* 0x5d6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d73:
	/* 0x5d73: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d77:
	/* 0x5d77: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d7c:
	/* 0x5d7c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d81:
	/* 0x5d81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d86:
	/* 0x5d86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d8b:
	/* 0x5d8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8d:
	/* 0x5d8d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d92:
	/* 0x5d92: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5d95:
	/* 0x5d95: je     5f5b <trace_ret_kernel_write_tail+0x5f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24411ULL;
	}
x86_l_5d9b:
	/* 0x5d9b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5da0:
	/* 0x5da0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5da3:
	/* 0x5da3: je     5f5b <trace_ret_kernel_write_tail+0x5f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24411ULL;
	}
x86_l_5da9:
	/* 0x5da9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5dad:
	/* 0x5dad: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5db2:
	/* 0x5db2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5db7:
	/* 0x5db7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dbc:
	/* 0x5dbc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5dc1:
	/* 0x5dc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dc3:
	/* 0x5dc3: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5dc7:
	/* 0x5dc7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5dc9:
	/* 0x5dc9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5dcf:
	/* 0x5dcf: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5dd2:
	/* 0x5dd2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5dd4:
	/* 0x5dd4: jb     3368 <trace_ret_kernel_write_tail+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13160ULL;
	}
x86_l_5dda:
	/* 0x5dda: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ddf:
	/* 0x5ddf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5de5:
	/* 0x5de5: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_5dea:
	/* 0x5dea: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5dec:
	/* 0x5dec: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5df1:
	/* 0x5df1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df3:
	/* 0x5df3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5df6:
	/* 0x5df6: jl     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15099ULL;
	}
x86_l_5dfc:
	/* 0x5dfc: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5e00:
	/* 0x5e00: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5e06:
	/* 0x5e06: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5e0b:
	/* 0x5e0b: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5e0f:
	/* 0x5e0f: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e12:
	/* 0x5e12: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e17:
	/* 0x5e17: jmp    3afb <trace_ret_kernel_write_tail+0x3afb> */
	return 15099ULL;
x86_l_5e1c:
	/* 0x5e1c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5e1f:
	/* 0x5e1f: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_5e25:
	/* 0x5e25: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 24105ULL;
}

static __noinline __u64 tracee_trace_ret_kernel_write_tail_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24105ULL: goto x86_l_5e29;
	case 24110ULL: goto x86_l_5e2e;
	case 24116ULL: goto x86_l_5e34;
	case 24120ULL: goto x86_l_5e38;
	case 24125ULL: goto x86_l_5e3d;
	case 24130ULL: goto x86_l_5e42;
	case 24135ULL: goto x86_l_5e47;
	case 24139ULL: goto x86_l_5e4b;
	case 24143ULL: goto x86_l_5e4f;
	case 24148ULL: goto x86_l_5e54;
	case 24150ULL: goto x86_l_5e56;
	case 24154ULL: goto x86_l_5e5a;
	case 24157ULL: goto x86_l_5e5d;
	case 24162ULL: goto x86_l_5e62;
	case 24167ULL: goto x86_l_5e67;
	case 24171ULL: goto x86_l_5e6b;
	case 24176ULL: goto x86_l_5e70;
	case 24178ULL: goto x86_l_5e72;
	case 24182ULL: goto x86_l_5e76;
	case 24187ULL: goto x86_l_5e7b;
	case 24192ULL: goto x86_l_5e80;
	case 24197ULL: goto x86_l_5e85;
	case 24201ULL: goto x86_l_5e89;
	case 24206ULL: goto x86_l_5e8e;
	case 24208ULL: goto x86_l_5e90;
	case 24212ULL: goto x86_l_5e94;
	case 24216ULL: goto x86_l_5e98;
	case 24221ULL: goto x86_l_5e9d;
	case 24226ULL: goto x86_l_5ea2;
	case 24231ULL: goto x86_l_5ea7;
	case 24236ULL: goto x86_l_5eac;
	case 24239ULL: goto x86_l_5eaf;
	case 24241ULL: goto x86_l_5eb1;
	case 24246ULL: goto x86_l_5eb6;
	case 24251ULL: goto x86_l_5ebb;
	case 24255ULL: goto x86_l_5ebf;
	case 24260ULL: goto x86_l_5ec4;
	case 24265ULL: goto x86_l_5ec9;
	case 24270ULL: goto x86_l_5ece;
	case 24275ULL: goto x86_l_5ed3;
	case 24277ULL: goto x86_l_5ed5;
	case 24282ULL: goto x86_l_5eda;
	case 24285ULL: goto x86_l_5edd;
	case 24291ULL: goto x86_l_5ee3;
	case 24296ULL: goto x86_l_5ee8;
	case 24299ULL: goto x86_l_5eeb;
	case 24305ULL: goto x86_l_5ef1;
	case 24309ULL: goto x86_l_5ef5;
	case 24314ULL: goto x86_l_5efa;
	case 24319ULL: goto x86_l_5eff;
	case 24324ULL: goto x86_l_5f04;
	case 24329ULL: goto x86_l_5f09;
	case 24331ULL: goto x86_l_5f0b;
	case 24335ULL: goto x86_l_5f0f;
	case 24337ULL: goto x86_l_5f11;
	case 24343ULL: goto x86_l_5f17;
	case 24345ULL: goto x86_l_5f19;
	case 24347ULL: goto x86_l_5f1b;
	case 24353ULL: goto x86_l_5f21;
	case 24358ULL: goto x86_l_5f26;
	case 24364ULL: goto x86_l_5f2c;
	case 24367ULL: goto x86_l_5f2f;
	case 24369ULL: goto x86_l_5f31;
	case 24374ULL: goto x86_l_5f36;
	case 24376ULL: goto x86_l_5f38;
	case 24379ULL: goto x86_l_5f3b;
	case 24385ULL: goto x86_l_5f41;
	case 24388ULL: goto x86_l_5f44;
	case 24394ULL: goto x86_l_5f4a;
	case 24399ULL: goto x86_l_5f4f;
	case 24401ULL: goto x86_l_5f51;
	case 24406ULL: goto x86_l_5f56;
	case 24411ULL: goto x86_l_5f5b;
	case 24414ULL: goto x86_l_5f5e;
	case 24420ULL: goto x86_l_5f64;
	case 24424ULL: goto x86_l_5f68;
	case 24429ULL: goto x86_l_5f6d;
	case 24435ULL: goto x86_l_5f73;
	case 24439ULL: goto x86_l_5f77;
	case 24444ULL: goto x86_l_5f7c;
	case 24449ULL: goto x86_l_5f81;
	case 24454ULL: goto x86_l_5f86;
	case 24458ULL: goto x86_l_5f8a;
	case 24462ULL: goto x86_l_5f8e;
	case 24467ULL: goto x86_l_5f93;
	case 24469ULL: goto x86_l_5f95;
	case 24473ULL: goto x86_l_5f99;
	case 24476ULL: goto x86_l_5f9c;
	case 24481ULL: goto x86_l_5fa1;
	case 24486ULL: goto x86_l_5fa6;
	case 24490ULL: goto x86_l_5faa;
	case 24495ULL: goto x86_l_5faf;
	case 24497ULL: goto x86_l_5fb1;
	case 24501ULL: goto x86_l_5fb5;
	case 24506ULL: goto x86_l_5fba;
	case 24511ULL: goto x86_l_5fbf;
	case 24516ULL: goto x86_l_5fc4;
	case 24520ULL: goto x86_l_5fc8;
	case 24525ULL: goto x86_l_5fcd;
	case 24527ULL: goto x86_l_5fcf;
	case 24532ULL: goto x86_l_5fd4;
	case 24535ULL: goto x86_l_5fd7;
	case 24541ULL: goto x86_l_5fdd;
	case 24545ULL: goto x86_l_5fe1;
	case 24550ULL: goto x86_l_5fe6;
	case 24556ULL: goto x86_l_5fec;
	case 24560ULL: goto x86_l_5ff0;
	case 24565ULL: goto x86_l_5ff5;
	case 24570ULL: goto x86_l_5ffa;
	case 24575ULL: goto x86_l_5fff;
	case 24579ULL: goto x86_l_6003;
	case 24583ULL: goto x86_l_6007;
	case 24588ULL: goto x86_l_600c;
	case 24590ULL: goto x86_l_600e;
	case 24594ULL: goto x86_l_6012;
	case 24597ULL: goto x86_l_6015;
	case 24602ULL: goto x86_l_601a;
	case 24607ULL: goto x86_l_601f;
	case 24611ULL: goto x86_l_6023;
	case 24616ULL: goto x86_l_6028;
	case 24618ULL: goto x86_l_602a;
	case 24622ULL: goto x86_l_602e;
	case 24627ULL: goto x86_l_6033;
	case 24632ULL: goto x86_l_6038;
	case 24637ULL: goto x86_l_603d;
	case 24641ULL: goto x86_l_6041;
	case 24646ULL: goto x86_l_6046;
	case 24648ULL: goto x86_l_6048;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5e29:
	/* 0x5e29: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5e2e:
	/* 0x5e2e: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_5e34:
	/* 0x5e34: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e38:
	/* 0x5e38: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e3d:
	/* 0x5e3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e42:
	/* 0x5e42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e47:
	/* 0x5e47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e4b:
	/* 0x5e4b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e4f:
	/* 0x5e4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e54:
	/* 0x5e54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e56:
	/* 0x5e56: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e5a:
	/* 0x5e5a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5e5d:
	/* 0x5e5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e62:
	/* 0x5e62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e67:
	/* 0x5e67: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e6b:
	/* 0x5e6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e70:
	/* 0x5e70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e72:
	/* 0x5e72: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e76:
	/* 0x5e76: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e7b:
	/* 0x5e7b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e80:
	/* 0x5e80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e85:
	/* 0x5e85: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e89:
	/* 0x5e89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e8e:
	/* 0x5e8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e90:
	/* 0x5e90: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e94:
	/* 0x5e94: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e98:
	/* 0x5e98: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e9d:
	/* 0x5e9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ea2:
	/* 0x5ea2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ea7:
	/* 0x5ea7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eac:
	/* 0x5eac: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5eaf:
	/* 0x5eaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eb1:
	/* 0x5eb1: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5eb6:
	/* 0x5eb6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ebb:
	/* 0x5ebb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ebf:
	/* 0x5ebf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ec4:
	/* 0x5ec4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ec9:
	/* 0x5ec9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ece:
	/* 0x5ece: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ed3:
	/* 0x5ed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ed5:
	/* 0x5ed5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eda:
	/* 0x5eda: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5edd:
	/* 0x5edd: je     5fd4 <trace_ret_kernel_write_tail+0x5fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fd4;
	}
x86_l_5ee3:
	/* 0x5ee3: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ee8:
	/* 0x5ee8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5eeb:
	/* 0x5eeb: je     5fd4 <trace_ret_kernel_write_tail+0x5fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fd4;
	}
x86_l_5ef1:
	/* 0x5ef1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ef5:
	/* 0x5ef5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5efa:
	/* 0x5efa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5eff:
	/* 0x5eff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f04:
	/* 0x5f04: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5f09:
	/* 0x5f09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f0b:
	/* 0x5f0b: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5f0f:
	/* 0x5f0f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5f11:
	/* 0x5f11: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5f17:
	/* 0x5f17: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5f19:
	/* 0x5f19: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5f1b:
	/* 0x5f1b: jb     2d8b <trace_ret_kernel_write_tail+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11659ULL;
	}
x86_l_5f21:
	/* 0x5f21: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f26:
	/* 0x5f26: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5f2c:
	/* 0x5f2c: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5f2f:
	/* 0x5f2f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5f31:
	/* 0x5f31: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5f36:
	/* 0x5f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f38:
	/* 0x5f38: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5f3b:
	/* 0x5f3b: jl     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10884ULL;
	}
x86_l_5f41:
	/* 0x5f41: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5f44:
	/* 0x5f44: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5f4a:
	/* 0x5f4a: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5f4f:
	/* 0x5f4f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5f51:
	/* 0x5f51: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f56:
	/* 0x5f56: jmp    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	return 10884ULL;
x86_l_5f5b:
	/* 0x5f5b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5f5e:
	/* 0x5f5e: jne    3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15099ULL;
	}
x86_l_5f64:
	/* 0x5f64: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f68:
	/* 0x5f68: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5f6d:
	/* 0x5f6d: je     3afb <trace_ret_kernel_write_tail+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_5f73:
	/* 0x5f73: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f77:
	/* 0x5f77: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f7c:
	/* 0x5f7c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f81:
	/* 0x5f81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f86:
	/* 0x5f86: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f8a:
	/* 0x5f8a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f8e:
	/* 0x5f8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f93:
	/* 0x5f93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f95:
	/* 0x5f95: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f99:
	/* 0x5f99: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f9c:
	/* 0x5f9c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5fa1:
	/* 0x5fa1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fa6:
	/* 0x5fa6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5faa:
	/* 0x5faa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5faf:
	/* 0x5faf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fb1:
	/* 0x5fb1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fb5:
	/* 0x5fb5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fba:
	/* 0x5fba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5fbf:
	/* 0x5fbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fc4:
	/* 0x5fc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fc8:
	/* 0x5fc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fcd:
	/* 0x5fcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fcf:
	/* 0x5fcf: jmp    3afb <trace_ret_kernel_write_tail+0x3afb> */
	return 15099ULL;
x86_l_5fd4:
	/* 0x5fd4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5fd7:
	/* 0x5fd7: jne    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10884ULL;
	}
x86_l_5fdd:
	/* 0x5fdd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fe1:
	/* 0x5fe1: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_5fe6:
	/* 0x5fe6: je     2a84 <trace_ret_kernel_write_tail+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10884ULL;
	}
x86_l_5fec:
	/* 0x5fec: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ff0:
	/* 0x5ff0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ff5:
	/* 0x5ff5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ffa:
	/* 0x5ffa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fff:
	/* 0x5fff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6003:
	/* 0x6003: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6007:
	/* 0x6007: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_600c:
	/* 0x600c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_600e:
	/* 0x600e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6012:
	/* 0x6012: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6015:
	/* 0x6015: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_601a:
	/* 0x601a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_601f:
	/* 0x601f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6023:
	/* 0x6023: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6028:
	/* 0x6028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602a:
	/* 0x602a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_602e:
	/* 0x602e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6033:
	/* 0x6033: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6038:
	/* 0x6038: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_603d:
	/* 0x603d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6041:
	/* 0x6041: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6046:
	/* 0x6046: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6048:
	/* 0x6048: jmp    2a84 <trace_ret_kernel_write_tail+0x2a84> */
	return 10884ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_kernel_write_tail_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22016U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2184ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2189ULL && __x86_pc <= 3888ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3893ULL && __x86_pc <= 5528ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5533ULL && __x86_pc <= 7249ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7255ULL && __x86_pc <= 9030ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9032ULL && __x86_pc <= 10736ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10741ULL && __x86_pc <= 12436ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12441ULL && __x86_pc <= 14162ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14164ULL && __x86_pc <= 15840ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15845ULL && __x86_pc <= 17498ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17502ULL && __x86_pc <= 19142ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19144ULL && __x86_pc <= 20794ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20800ULL && __x86_pc <= 22444ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22449ULL && __x86_pc <= 24101ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 24105ULL && __x86_pc <= 24648ULL)
			__x86_pc = tracee_trace_ret_kernel_write_tail_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

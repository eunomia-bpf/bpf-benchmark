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

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_0(
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
	case 99ULL: goto x86_l_63;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 116ULL: goto x86_l_74;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 141ULL: goto x86_l_8d;
	case 143ULL: goto x86_l_8f;
	case 148ULL: goto x86_l_94;
	case 150ULL: goto x86_l_96;
	case 153ULL: goto x86_l_99;
	case 158ULL: goto x86_l_9e;
	case 160ULL: goto x86_l_a0;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 204ULL: goto x86_l_cc;
	case 209ULL: goto x86_l_d1;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 221ULL: goto x86_l_dd;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 229ULL: goto x86_l_e5;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 295ULL: goto x86_l_127;
	case 297ULL: goto x86_l_129;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 306ULL: goto x86_l_132;
	case 314ULL: goto x86_l_13a;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 372ULL: goto x86_l_174;
	case 378ULL: goto x86_l_17a;
	case 389ULL: goto x86_l_185;
	case 398ULL: goto x86_l_18e;
	case 410ULL: goto x86_l_19a;
	case 422ULL: goto x86_l_1a6;
	case 434ULL: goto x86_l_1b2;
	case 446ULL: goto x86_l_1be;
	case 458ULL: goto x86_l_1ca;
	case 470ULL: goto x86_l_1d6;
	case 482ULL: goto x86_l_1e2;
	case 494ULL: goto x86_l_1ee;
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
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 626ULL: goto x86_l_272;
	case 631ULL: goto x86_l_277;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 656ULL: goto x86_l_290;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 706ULL: goto x86_l_2c2;
	case 711ULL: goto x86_l_2c7;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 733ULL: goto x86_l_2dd;
	case 740ULL: goto x86_l_2e4;
	case 748ULL: goto x86_l_2ec;
	case 753ULL: goto x86_l_2f1;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 761ULL: goto x86_l_2f9;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 789ULL: goto x86_l_315;
	case 793ULL: goto x86_l_319;
	case 797ULL: goto x86_l_31d;
	case 805ULL: goto x86_l_325;
	case 812ULL: goto x86_l_32c;
	case 817ULL: goto x86_l_331;
	case 822ULL: goto x86_l_336;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 840ULL: goto x86_l_348;
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
	case 1152ULL: goto x86_l_480;
	case 1163ULL: goto x86_l_48b;
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
	case 1262ULL: goto x86_l_4ee;
	case 1270ULL: goto x86_l_4f6;
	case 1278ULL: goto x86_l_4fe;
	case 1286ULL: goto x86_l_506;
	case 1294ULL: goto x86_l_50e;
	case 1301ULL: goto x86_l_515;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1326ULL: goto x86_l_52e;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1341ULL: goto x86_l_53d;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1369ULL: goto x86_l_559;
	case 1373ULL: goto x86_l_55d;
	case 1381ULL: goto x86_l_565;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1408ULL: goto x86_l_580;
	case 1414ULL: goto x86_l_586;
	case 1417ULL: goto x86_l_589;
	case 1421ULL: goto x86_l_58d;
	case 1425ULL: goto x86_l_591;
	case 1436ULL: goto x86_l_59c;
	case 1447ULL: goto x86_l_5a7;
	case 1458ULL: goto x86_l_5b2;
	case 1469ULL: goto x86_l_5bd;
	case 1480ULL: goto x86_l_5c8;
	case 1491ULL: goto x86_l_5d3;
	case 1502ULL: goto x86_l_5de;
	case 1513ULL: goto x86_l_5e9;
	case 1524ULL: goto x86_l_5f4;
	case 1532ULL: goto x86_l_5fc;
	case 1540ULL: goto x86_l_604;
	case 1548ULL: goto x86_l_60c;
	case 1556ULL: goto x86_l_614;
	case 1564ULL: goto x86_l_61c;
	case 1572ULL: goto x86_l_624;
	case 1580ULL: goto x86_l_62c;
	case 1588ULL: goto x86_l_634;
	case 1596ULL: goto x86_l_63c;
	case 1604ULL: goto x86_l_644;
	case 1612ULL: goto x86_l_64c;
	case 1620ULL: goto x86_l_654;
	case 1628ULL: goto x86_l_65c;
	case 1636ULL: goto x86_l_664;
	case 1644ULL: goto x86_l_66c;
	case 1651ULL: goto x86_l_673;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1676ULL: goto x86_l_68c;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1691ULL: goto x86_l_69b;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
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
	case 1819ULL: goto x86_l_71b;
	case 1827ULL: goto x86_l_723;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1853ULL: goto x86_l_73d;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1893ULL: goto x86_l_765;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1925ULL: goto x86_l_785;
	case 1929ULL: goto x86_l_789;
	case 1933ULL: goto x86_l_78d;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1963ULL: goto x86_l_7ab;
	case 1967ULL: goto x86_l_7af;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2062ULL: goto x86_l_80e;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2074ULL: goto x86_l_81a;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2100ULL: goto x86_l_834;
	case 2104ULL: goto x86_l_838;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
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
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: movabs rbx,0x2d100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3096671420416ULL);
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
	/* 0x23: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28:
	/* 0x28: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_2f:
	/* 0x2f: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x3e: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_44:
	/* 0x44: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47:
	/* 0x47: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b:
	/* 0x4b: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_53:
	/* 0x53: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57:
	/* 0x57: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_5f:
	/* 0x5f: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63:
	/* 0x63: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6b:
	/* 0x6b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_74:
	/* 0x74: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c:
	/* 0x7c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_83:
	/* 0x83: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_88:
	/* 0x88: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8d:
	/* 0x8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f:
	/* 0x8f: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_94:
	/* 0x94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96:
	/* 0x96: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_9e:
	/* 0x9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0:
	/* 0xa0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a3:
	/* 0xa3: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a7:
	/* 0xa7: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ac:
	/* 0xac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b1:
	/* 0xb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6:
	/* 0xb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bb:
	/* 0xbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd:
	/* 0xbd: test   DWORD PTR [rsp+0x60],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412318957568ULL);
x86_l_c5:
	/* 0xc5: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_ca:
	/* 0xca: jne    132 <trace_ret_vfs_writev_tail+0x132> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_132;
	}
x86_l_cc:
	/* 0xcc: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_d1:
	/* 0xd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3:
	/* 0xd3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_db:
	/* 0xdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd:
	/* 0xdd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0:
	/* 0xe0: je     e7 <trace_ret_vfs_writev_tail+0xe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e7;
	}
x86_l_e2:
	/* 0xe2: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e5:
	/* 0xe5: jmp    e7 <trace_ret_vfs_writev_tail+0xe7> */
	goto x86_l_e7;
x86_l_e7:
	/* 0xe7: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb:
	/* 0xeb: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f0:
	/* 0xf0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f5:
	/* 0xf5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa:
	/* 0xfa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ff:
	/* 0xff: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_102:
	/* 0x102: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104:
	/* 0x104: test   BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_109:
	/* 0x109: jne    111 <trace_ret_vfs_writev_tail+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_111;
	}
x86_l_10b:
	/* 0x10b: mov    ebx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10f:
	/* 0x10f: jmp    132 <trace_ret_vfs_writev_tail+0x132> */
	goto x86_l_132;
x86_l_111:
	/* 0x111: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_118:
	/* 0x118: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11d:
	/* 0x11d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122:
	/* 0x122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124:
	/* 0x124: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_127:
	/* 0x127: je     12d <trace_ret_vfs_writev_tail+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d;
	}
x86_l_129:
	/* 0x129: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b:
	/* 0x12b: jmp    132 <trace_ret_vfs_writev_tail+0x132> */
	goto x86_l_132;
x86_l_12d:
	/* 0x12d: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_132:
	/* 0x132: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13a:
	/* 0x13a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_141:
	/* 0x141: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_146:
	/* 0x146: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b:
	/* 0x14b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d:
	/* 0x14d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_156:
	/* 0x156: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_160:
	/* 0x160: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_165:
	/* 0x165: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16a:
	/* 0x16a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c:
	/* 0x16c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_171:
	/* 0x171: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_174:
	/* 0x174: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_17a:
	/* 0x17a: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_185:
	/* 0x185: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1ee:
	/* 0x1ee: mov    QWORD PTR [r12+0x7dd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ff:
	/* 0x1ff: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_208:
	/* 0x208: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_211:
	/* 0x211: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_223:
	/* 0x223: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_22c:
	/* 0x22c: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_235:
	/* 0x235: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_247:
	/* 0x247: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_250:
	/* 0x250: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_259:
	/* 0x259: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_262:
	/* 0x262: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_26b:
	/* 0x26b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_270:
	/* 0x270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272:
	/* 0x272: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_277:
	/* 0x277: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_280:
	/* 0x280: mov    DWORD PTR [r12+0x70],0x31b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337947ULL);
x86_l_289:
	/* 0x289: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_28e:
	/* 0x28e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290:
	/* 0x290: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294:
	/* 0x294: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_299:
	/* 0x299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b:
	/* 0x29b: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2a1:
	/* 0x2a1: mov    DWORD PTR [r12+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2a6:
	/* 0x2a6: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ab:
	/* 0x2ab: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2af:
	/* 0x2af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2b6:
	/* 0x2b6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bb:
	/* 0x2bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c0:
	/* 0x2c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2:
	/* 0x2c2: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c7:
	/* 0x2c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cf:
	/* 0x2cf: je     315 <trace_ret_vfs_writev_tail+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315;
	}
x86_l_2d1:
	/* 0x2d1: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d6:
	/* 0x2d6: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2dd:
	/* 0x2dd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2e4:
	/* 0x2e4: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2ec:
	/* 0x2ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1:
	/* 0x2f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3:
	/* 0x2f3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2f6:
	/* 0x2f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: je     552 <trace_ret_vfs_writev_tail+0x552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_552;
	}
x86_l_2ff:
	/* 0x2ff: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_303:
	/* 0x303: jne    b74 <trace_ret_vfs_writev_tail+0xb74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2932ULL;
	}
x86_l_309:
	/* 0x309: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: jmp    c1f <trace_ret_vfs_writev_tail+0xc1f> */
	return 3103ULL;
x86_l_315:
	/* 0x315: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_319:
	/* 0x319: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31d:
	/* 0x31d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_325:
	/* 0x325: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_32c:
	/* 0x32c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_331:
	/* 0x331: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_336:
	/* 0x336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338:
	/* 0x338: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33b:
	/* 0x33b: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_341:
	/* 0x341: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_344:
	/* 0x344: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_348:
	/* 0x348: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_34c:
	/* 0x34c: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_357:
	/* 0x357: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_362:
	/* 0x362: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_36d:
	/* 0x36d: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_378:
	/* 0x378: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3d0:
	/* 0x3d0: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_480:
	/* 0x480: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_49e:
	/* 0x49e: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4a6:
	/* 0x4a6: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4be:
	/* 0x4be: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4d6:
	/* 0x4d6: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4de:
	/* 0x4de: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4ee:
	/* 0x4ee: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4f6:
	/* 0x4f6: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4fe:
	/* 0x4fe: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_506:
	/* 0x506: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_50e:
	/* 0x50e: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_515:
	/* 0x515: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_51c:
	/* 0x51c: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_521:
	/* 0x521: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_526:
	/* 0x526: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_52b:
	/* 0x52b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_530:
	/* 0x530: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_535:
	/* 0x535: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53a:
	/* 0x53a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_53d:
	/* 0x53d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_544:
	/* 0x544: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_547:
	/* 0x547: jne    2d1 <trace_ret_vfs_writev_tail+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d1;
	}
x86_l_54d:
	/* 0x54d: jmp    31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	return 12711ULL;
x86_l_552:
	/* 0x552: mov    eax,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_559:
	/* 0x559: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55d:
	/* 0x55d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_565:
	/* 0x565: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_56c:
	/* 0x56c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_571:
	/* 0x571: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_576:
	/* 0x576: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_57b:
	/* 0x57b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d:
	/* 0x57d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_580:
	/* 0x580: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_586:
	/* 0x586: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_589:
	/* 0x589: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58d:
	/* 0x58d: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_591:
	/* 0x591: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5b2:
	/* 0x5b2: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5de:
	/* 0x5de: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5e9:
	/* 0x5e9: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5f4:
	/* 0x5f4: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5fc:
	/* 0x5fc: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_604:
	/* 0x604: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_60c:
	/* 0x60c: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_614:
	/* 0x614: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_61c:
	/* 0x61c: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_624:
	/* 0x624: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_62c:
	/* 0x62c: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_634:
	/* 0x634: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_63c:
	/* 0x63c: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_644:
	/* 0x644: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_64c:
	/* 0x64c: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_654:
	/* 0x654: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_65c:
	/* 0x65c: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_664:
	/* 0x664: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_66c:
	/* 0x66c: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_673:
	/* 0x673: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_67a:
	/* 0x67a: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_67f:
	/* 0x67f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_684:
	/* 0x684: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_689:
	/* 0x689: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_68c:
	/* 0x68c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68e:
	/* 0x68e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_693:
	/* 0x693: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_698:
	/* 0x698: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_69b:
	/* 0x69b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69d:
	/* 0x69d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a0:
	/* 0x6a0: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_6a6:
	/* 0x6a6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6a9:
	/* 0x6a9: mov    rbx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_6b1:
	/* 0x6b1: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6b5:
	/* 0x6b5: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6bd:
	/* 0x6bd: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6c2:
	/* 0x6c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6c7:
	/* 0x6c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6cc:
	/* 0x6cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d1:
	/* 0x6d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d3:
	/* 0x6d3: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6d8:
	/* 0x6d8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6dd:
	/* 0x6dd: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e1:
	/* 0x6e1: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x6f7: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6fc:
	/* 0x6fc: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_700:
	/* 0x700: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_705:
	/* 0x705: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_70a:
	/* 0x70a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70f:
	/* 0x70f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_714:
	/* 0x714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_716:
	/* 0x716: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_71b:
	/* 0x71b: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_723:
	/* 0x723: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_727:
	/* 0x727: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72c:
	/* 0x72c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_731:
	/* 0x731: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_736:
	/* 0x736: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_73b:
	/* 0x73b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73d:
	/* 0x73d: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_741:
	/* 0x741: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_745:
	/* 0x745: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_74a:
	/* 0x74a: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_74e:
	/* 0x74e: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_753:
	/* 0x753: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_758:
	/* 0x758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75d:
	/* 0x75d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_762:
	/* 0x762: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_765:
	/* 0x765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_767:
	/* 0x767: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_76c:
	/* 0x76c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_771:
	/* 0x771: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_776:
	/* 0x776: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_77b:
	/* 0x77b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_780:
	/* 0x780: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_783:
	/* 0x783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_785:
	/* 0x785: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_789:
	/* 0x789: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_78d:
	/* 0x78d: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_791:
	/* 0x791: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_795:
	/* 0x795: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79a:
	/* 0x79a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_79f:
	/* 0x79f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a4:
	/* 0x7a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7a9:
	/* 0x7a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ab:
	/* 0x7ab: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7af:
	/* 0x7af: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7b3:
	/* 0x7b3: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b8:
	/* 0x7b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7bd:
	/* 0x7bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c2:
	/* 0x7c2: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7ca:
	/* 0x7ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7cf:
	/* 0x7cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d1:
	/* 0x7d1: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7d6:
	/* 0x7d6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7da:
	/* 0x7da: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7df:
	/* 0x7df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7e4:
	/* 0x7e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e9:
	/* 0x7e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ee:
	/* 0x7ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f0:
	/* 0x7f0: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7f5:
	/* 0x7f5: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7fa:
	/* 0x7fa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ff:
	/* 0x7ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_804:
	/* 0x804: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_809:
	/* 0x809: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_80c:
	/* 0x80c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80e:
	/* 0x80e: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_812:
	/* 0x812: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_816:
	/* 0x816: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_81a:
	/* 0x81a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_81e:
	/* 0x81e: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_823:
	/* 0x823: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_828:
	/* 0x828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_82d:
	/* 0x82d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_832:
	/* 0x832: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_834:
	/* 0x834: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_838:
	/* 0x838: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83c:
	/* 0x83c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_841:
	/* 0x841: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_846:
	/* 0x846: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_84b:
	/* 0x84b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_850:
	/* 0x850: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_853:
	/* 0x853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_855:
	/* 0x855: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_85a:
	/* 0x85a: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_85f:
	/* 0x85f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_864:
	/* 0x864: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_869:
	/* 0x869: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_86e:
	/* 0x86e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_871:
	/* 0x871: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_873:
	/* 0x873: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_877:
	/* 0x877: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_87b:
	/* 0x87b: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_87f:
	/* 0x87f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_883:
	/* 0x883: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_888:
	/* 0x888: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 2189ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2236ULL: goto x86_l_8bc;
	case 2243ULL: goto x86_l_8c3;
	case 2251ULL: goto x86_l_8cb;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2278ULL: goto x86_l_8e6;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2310ULL: goto x86_l_906;
	case 2314ULL: goto x86_l_90a;
	case 2318ULL: goto x86_l_90e;
	case 2322ULL: goto x86_l_912;
	case 2326ULL: goto x86_l_916;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2348ULL: goto x86_l_92c;
	case 2353ULL: goto x86_l_931;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2390ULL: goto x86_l_956;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2415ULL: goto x86_l_96f;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2445ULL: goto x86_l_98d;
	case 2447ULL: goto x86_l_98f;
	case 2451ULL: goto x86_l_993;
	case 2455ULL: goto x86_l_997;
	case 2459ULL: goto x86_l_99b;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2489ULL: goto x86_l_9b9;
	case 2493ULL: goto x86_l_9bd;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2699ULL: goto x86_l_a8b;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2723ULL: goto x86_l_aa3;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2757ULL: goto x86_l_ac5;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2779ULL: goto x86_l_adb;
	case 2783ULL: goto x86_l_adf;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2893ULL: goto x86_l_b4d;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2926ULL: goto x86_l_b6e;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3099ULL: goto x86_l_c1b;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3135ULL: goto x86_l_c3f;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3150ULL: goto x86_l_c4e;
	case 3153ULL: goto x86_l_c51;
	case 3156ULL: goto x86_l_c54;
	case 3158ULL: goto x86_l_c56;
	case 3164ULL: goto x86_l_c5c;
	case 3170ULL: goto x86_l_c62;
	case 3178ULL: goto x86_l_c6a;
	case 3182ULL: goto x86_l_c6e;
	case 3188ULL: goto x86_l_c74;
	case 3200ULL: goto x86_l_c80;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3221ULL: goto x86_l_c95;
	case 3233ULL: goto x86_l_ca1;
	case 3238ULL: goto x86_l_ca6;
	case 3246ULL: goto x86_l_cae;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3263ULL: goto x86_l_cbf;
	case 3271ULL: goto x86_l_cc7;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3298ULL: goto x86_l_ce2;
	case 3301ULL: goto x86_l_ce5;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3341ULL: goto x86_l_d0d;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3413ULL: goto x86_l_d55;
	case 3416ULL: goto x86_l_d58;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3457ULL: goto x86_l_d81;
	case 3465ULL: goto x86_l_d89;
	case 3473ULL: goto x86_l_d91;
	case 3481ULL: goto x86_l_d99;
	case 3489ULL: goto x86_l_da1;
	case 3497ULL: goto x86_l_da9;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3549ULL: goto x86_l_ddd;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3569ULL: goto x86_l_df1;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3577ULL: goto x86_l_df9;
	case 3581ULL: goto x86_l_dfd;
	case 3584ULL: goto x86_l_e00;
	case 3586ULL: goto x86_l_e02;
	case 3589ULL: goto x86_l_e05;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3619ULL: goto x86_l_e23;
	case 3621ULL: goto x86_l_e25;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3645ULL: goto x86_l_e3d;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3672ULL: goto x86_l_e58;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3689ULL: goto x86_l_e69;
	case 3696ULL: goto x86_l_e70;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3757ULL: goto x86_l_ead;
	case 3760ULL: goto x86_l_eb0;
	case 3762ULL: goto x86_l_eb2;
	case 3764ULL: goto x86_l_eb4;
	case 3772ULL: goto x86_l_ebc;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3796ULL: goto x86_l_ed4;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3813ULL: goto x86_l_ee5;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3839ULL: goto x86_l_eff;
	case 3847ULL: goto x86_l_f07;
	case 3855ULL: goto x86_l_f0f;
	case 3858ULL: goto x86_l_f12;
	case 3866ULL: goto x86_l_f1a;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_88d:
	/* 0x88d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_892:
	/* 0x892: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_897:
	/* 0x897: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_899:
	/* 0x899: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_89e:
	/* 0x89e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8a2:
	/* 0x8a2: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8a7:
	/* 0x8a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8ac:
	/* 0x8ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b1:
	/* 0x8b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8b6:
	/* 0x8b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b8:
	/* 0x8b8: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8bc:
	/* 0x8bc: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8c3:
	/* 0x8c3: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_8cb:
	/* 0x8cb: lea    r14,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8d4:
	/* 0x8d4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8d9:
	/* 0x8d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8de:
	/* 0x8de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e3:
	/* 0x8e3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_8e6:
	/* 0x8e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e8:
	/* 0x8e8: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8ed:
	/* 0x8ed: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f2:
	/* 0x8f2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f7:
	/* 0x8f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fc:
	/* 0x8fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_901:
	/* 0x901: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_904:
	/* 0x904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_906:
	/* 0x906: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_90a:
	/* 0x90a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_90e:
	/* 0x90e: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_912:
	/* 0x912: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_916:
	/* 0x916: mov    ebx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_91d:
	/* 0x91d: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_922:
	/* 0x922: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_927:
	/* 0x927: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92c:
	/* 0x92c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_931:
	/* 0x931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_933:
	/* 0x933: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_938:
	/* 0x938: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_93c:
	/* 0x93c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_941:
	/* 0x941: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_946:
	/* 0x946: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94b:
	/* 0x94b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_950:
	/* 0x950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_952:
	/* 0x952: cmp    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 96ULL);
x86_l_956:
	/* 0x956: jne    9bd <trace_ret_vfs_writev_tail+0x9bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9bd;
	}
x86_l_958:
	/* 0x958: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_95d:
	/* 0x95d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_962:
	/* 0x962: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_967:
	/* 0x967: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_96c:
	/* 0x96c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_96f:
	/* 0x96f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_971:
	/* 0x971: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_976:
	/* 0x976: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_97b:
	/* 0x97b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_980:
	/* 0x980: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_985:
	/* 0x985: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_98a:
	/* 0x98a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_98d:
	/* 0x98d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98f:
	/* 0x98f: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_993:
	/* 0x993: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_997:
	/* 0x997: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_99b:
	/* 0x99b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_99f:
	/* 0x99f: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9a4:
	/* 0x9a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9a9:
	/* 0x9a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ae:
	/* 0x9ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9b3:
	/* 0x9b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b5:
	/* 0x9b5: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9b9:
	/* 0x9b9: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9bd:
	/* 0x9bd: mov    DWORD PTR [r13+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c1:
	/* 0x9c1: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9c6:
	/* 0x9c6: lea    r14,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9cd:
	/* 0x9cd: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9d2:
	/* 0x9d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9d7:
	/* 0x9d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9dc:
	/* 0x9dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e1:
	/* 0x9e1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9e4:
	/* 0x9e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e6:
	/* 0x9e6: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9eb:
	/* 0x9eb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9ef:
	/* 0x9ef: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f4:
	/* 0x9f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f9:
	/* 0x9f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9fe:
	/* 0x9fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a03:
	/* 0xa03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a05:
	/* 0xa05: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a0a:
	/* 0xa0a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a0f:
	/* 0xa0f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a14:
	/* 0xa14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a19:
	/* 0xa19: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a1e:
	/* 0xa1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a23:
	/* 0xa23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a25:
	/* 0xa25: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a29:
	/* 0xa29: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a2d:
	/* 0xa2d: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a32:
	/* 0xa32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a34:
	/* 0xa34: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a38:
	/* 0xa38: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a3c:
	/* 0xa3c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a41:
	/* 0xa41: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a46:
	/* 0xa46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a4b:
	/* 0xa4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a50:
	/* 0xa50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a52:
	/* 0xa52: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a57:
	/* 0xa57: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5b:
	/* 0xa5b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a60:
	/* 0xa60: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a64:
	/* 0xa64: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a69:
	/* 0xa69: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a6e:
	/* 0xa6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a73:
	/* 0xa73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a78:
	/* 0xa78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7a:
	/* 0xa7a: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a7f:
	/* 0xa7f: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a83:
	/* 0xa83: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a8b:
	/* 0xa8b: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a8f:
	/* 0xa8f: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a94:
	/* 0xa94: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a99:
	/* 0xa99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a9e:
	/* 0xa9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa3:
	/* 0xaa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa5:
	/* 0xaa5: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aaa:
	/* 0xaaa: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aae:
	/* 0xaae: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ab3:
	/* 0xab3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ab8:
	/* 0xab8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_abd:
	/* 0xabd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ac2:
	/* 0xac2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ac5:
	/* 0xac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac7:
	/* 0xac7: test   BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_acc:
	/* 0xacc: je     ad3 <trace_ret_vfs_writev_tail+0xad3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ad3;
	}
x86_l_ace:
	/* 0xace: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_ad3:
	/* 0xad3: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_adb:
	/* 0xadb: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_adf:
	/* 0xadf: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_ae7:
	/* 0xae7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aec:
	/* 0xaec: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_af1:
	/* 0xaf1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_af6:
	/* 0xaf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af8:
	/* 0xaf8: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0xb0c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b0f:
	/* 0xb0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b11:
	/* 0xb11: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b16:
	/* 0xb16: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b1b:
	/* 0xb1b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b20:
	/* 0xb20: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b25:
	/* 0xb25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b2a:
	/* 0xb2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2c:
	/* 0xb2c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b31:
	/* 0xb31: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b36:
	/* 0xb36: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_b3b:
	/* 0xb3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b40:
	/* 0xb40: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b48:
	/* 0xb48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4a:
	/* 0xb4a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_b4d:
	/* 0xb4d: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b51:
	/* 0xb51: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b56:
	/* 0xb56: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b5b:
	/* 0xb5b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b60:
	/* 0xb60: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b63:
	/* 0xb63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b65:
	/* 0xb65: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b6a:
	/* 0xb6a: test   BYTE PTR [rbx+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b6e:
	/* 0xb6e: je     309 <trace_ret_vfs_writev_tail+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 777ULL;
	}
x86_l_b74:
	/* 0xb74: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b79:
	/* 0xb79: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b81:
	/* 0xb81: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b86:
	/* 0xb86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b8b:
	/* 0xb8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b90:
	/* 0xb90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b95:
	/* 0xb95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b97:
	/* 0xb97: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b9c:
	/* 0xb9c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ba1:
	/* 0xba1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba6:
	/* 0xba6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bab:
	/* 0xbab: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bb0:
	/* 0xbb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb5:
	/* 0xbb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb7:
	/* 0xbb7: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bbc:
	/* 0xbbc: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bc1:
	/* 0xbc1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bc6:
	/* 0xbc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bcb:
	/* 0xbcb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd0:
	/* 0xbd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bd5:
	/* 0xbd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd7:
	/* 0xbd7: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bdc:
	/* 0xbdc: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_be1:
	/* 0xbe1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be6:
	/* 0xbe6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_beb:
	/* 0xbeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bf7:
	/* 0xbf7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bfa:
	/* 0xbfa: je     c1d <trace_ret_vfs_writev_tail+0xc1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1d;
	}
x86_l_bfc:
	/* 0xbfc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c00:
	/* 0xc00: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c05:
	/* 0xc05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c0a:
	/* 0xc0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c0f:
	/* 0xc0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c14:
	/* 0xc14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c16:
	/* 0xc16: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c1b:
	/* 0xc1b: jmp    c1f <trace_ret_vfs_writev_tail+0xc1f> */
	goto x86_l_c1f;
x86_l_c1d:
	/* 0xc1d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1f:
	/* 0xc1f: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c24:
	/* 0xc24: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c28:
	/* 0xc28: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c2c:
	/* 0xc2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c33:
	/* 0xc33: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c38:
	/* 0xc38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c3d:
	/* 0xc3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3f:
	/* 0xc3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c42:
	/* 0xc42: je     c5c <trace_ret_vfs_writev_tail+0xc5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5c;
	}
x86_l_c44:
	/* 0xc44: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c47:
	/* 0xc47: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c4e:
	/* 0xc4e: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c51:
	/* 0xc51: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c54:
	/* 0xc54: jne    c5c <trace_ret_vfs_writev_tail+0xc5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c5c;
	}
x86_l_c56:
	/* 0xc56: or     BYTE PTR [r12+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c5c:
	/* 0xc5c: movzx  eax,WORD PTR [r12+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c62:
	/* 0xc62: mov    WORD PTR [rsp+0xb8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c6a:
	/* 0xc6a: cmp    ax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c6e:
	/* 0xc6e: jne    2003 <trace_ret_vfs_writev_tail+0x2003> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8195ULL;
	}
x86_l_c74:
	/* 0xc74: mov    QWORD PTR [r12+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_c80:
	/* 0xc80: mov    QWORD PTR [r12+0x80],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781183ULL);
x86_l_c8c:
	/* 0xc8c: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8e:
	/* 0xc8e: cmp    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_c93:
	/* 0xc93: jne    ca6 <trace_ret_vfs_writev_tail+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ca6;
	}
x86_l_c95:
	/* 0xc95: mov    QWORD PTR [r12+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_ca1:
	/* 0xca1: jmp    31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	return 12711ULL;
x86_l_ca6:
	/* 0xca6: mov    QWORD PTR [rsp+0xb0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cae:
	/* 0xcae: mov    rax,QWORD PTR [r12+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_cb6:
	/* 0xcb6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb9:
	/* 0xcb9: je     e69 <trace_ret_vfs_writev_tail+0xe69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e69;
	}
x86_l_cbf:
	/* 0xcbf: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_cc7:
	/* 0xcc7: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_cca:
	/* 0xcca: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ccd:
	/* 0xccd: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_cd0:
	/* 0xcd0: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_cd4:
	/* 0xcd4: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cd7:
	/* 0xcd7: neg    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cda:
	/* 0xcda: xor    r15,QWORD PTR [r12+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_ce2:
	/* 0xce2: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ce5:
	/* 0xce5: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ced:
	/* 0xced: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf0:
	/* 0xcf0: je     d13 <trace_ret_vfs_writev_tail+0xd13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d13;
	}
x86_l_cf2:
	/* 0xcf2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf4:
	/* 0xcf4: cmp    BYTE PTR [r13+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_cfc:
	/* 0xcfc: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cff:
	/* 0xcff: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d02:
	/* 0xd02: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d05:
	/* 0xd05: xor    rcx,QWORD PTR [r12+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d0d:
	/* 0xd0d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d10:
	/* 0xd10: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d13:
	/* 0xd13: mov    rax,QWORD PTR [r12+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d1b:
	/* 0xd1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1e:
	/* 0xd1e: je     d3c <trace_ret_vfs_writev_tail+0xd3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d3c;
	}
x86_l_d20:
	/* 0xd20: mov    ecx,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d25:
	/* 0xd25: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d28:
	/* 0xd28: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d2b:
	/* 0xd2b: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d2e:
	/* 0xd2e: xor    rcx,QWORD PTR [r12+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d36:
	/* 0xd36: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d39:
	/* 0xd39: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d3c:
	/* 0xd3c: mov    rax,QWORD PTR [r12+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d44:
	/* 0xd44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: je     d66 <trace_ret_vfs_writev_tail+0xd66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d66;
	}
x86_l_d49:
	/* 0xd49: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d4c:
	/* 0xd4c: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d51:
	/* 0xd51: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d55:
	/* 0xd55: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d58:
	/* 0xd58: xor    rcx,QWORD PTR [r12+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_d60:
	/* 0xd60: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d63:
	/* 0xd63: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d66:
	/* 0xd66: mov    rbx,QWORD PTR [r12+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_d6e:
	/* 0xd6e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_d71:
	/* 0xd71: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d76:
	/* 0xd76: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7b:
	/* 0xd7b: je     edc <trace_ret_vfs_writev_tail+0xedc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edc;
	}
x86_l_d81:
	/* 0xd81: mov    rax,QWORD PTR [r12+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_d89:
	/* 0xd89: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d91:
	/* 0xd91: mov    rbp,QWORD PTR [r12+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_d99:
	/* 0xd99: mov    rax,QWORD PTR [r12+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_da1:
	/* 0xda1: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_da9:
	/* 0xda9: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_db1:
	/* 0xdb1: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_db6:
	/* 0xdb6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_dbd:
	/* 0xdbd: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_dc2:
	/* 0xdc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dc7:
	/* 0xdc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc9:
	/* 0xdc9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dcc:
	/* 0xdcc: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dd1:
	/* 0xdd1: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_dd6:
	/* 0xdd6: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ddd:
	/* 0xddd: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: je     e02 <trace_ret_vfs_writev_tail+0xe02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e02;
	}
x86_l_de2:
	/* 0xde2: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dec:
	/* 0xdec: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_def:
	/* 0xdef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df1:
	/* 0xdf1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_df4:
	/* 0xdf4: je     e02 <trace_ret_vfs_writev_tail+0xe02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e02;
	}
x86_l_df6:
	/* 0xdf6: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df9:
	/* 0xdf9: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dfd:
	/* 0xdfd: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e00:
	/* 0xe00: jmp    e05 <trace_ret_vfs_writev_tail+0xe05> */
	goto x86_l_e05;
x86_l_e02:
	/* 0xe02: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e05:
	/* 0xe05: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e0d:
	/* 0xe0d: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e12:
	/* 0xe12: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e15:
	/* 0xe15: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e18:
	/* 0xe18: jb     e30 <trace_ret_vfs_writev_tail+0xe30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e30;
	}
x86_l_e1a:
	/* 0xe1a: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e1e:
	/* 0xe1e: je     e25 <trace_ret_vfs_writev_tail+0xe25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e25;
	}
x86_l_e20:
	/* 0xe20: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e23:
	/* 0xe23: jbe    e30 <trace_ret_vfs_writev_tail+0xe30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e30;
	}
x86_l_e25:
	/* 0xe25: and    r14,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 216ULL);
x86_l_e2d:
	/* 0xe2d: or     r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_e30:
	/* 0xe30: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e35:
	/* 0xe35: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e38:
	/* 0xe38: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e3d:
	/* 0xe3d: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e44:
	/* 0xe44: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e47:
	/* 0xe47: je     e86 <trace_ret_vfs_writev_tail+0xe86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e86;
	}
x86_l_e49:
	/* 0xe49: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e4e:
	/* 0xe4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e53:
	/* 0xe53: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e56:
	/* 0xe56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e58:
	/* 0xe58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e5b:
	/* 0xe5b: je     eb2 <trace_ret_vfs_writev_tail+0xeb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb2;
	}
x86_l_e5d:
	/* 0xe5d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e60:
	/* 0xe60: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e64:
	/* 0xe64: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e67:
	/* 0xe67: jmp    eb4 <trace_ret_vfs_writev_tail+0xeb4> */
	goto x86_l_eb4;
x86_l_e69:
	/* 0xe69: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e70:
	/* 0xe70: mov    rax,QWORD PTR [r12+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e78:
	/* 0xe78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7b:
	/* 0xe7b: jne    cf2 <trace_ret_vfs_writev_tail+0xcf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cf2;
	}
x86_l_e81:
	/* 0xe81: jmp    d13 <trace_ret_vfs_writev_tail+0xd13> */
	goto x86_l_d13;
x86_l_e86:
	/* 0xe86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e88:
	/* 0xe88: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e8b:
	/* 0xe8b: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e90:
	/* 0xe90: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e93:
	/* 0xe93: jb     ec9 <trace_ret_vfs_writev_tail+0xec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec9;
	}
x86_l_e95:
	/* 0xe95: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e99:
	/* 0xe99: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e9e:
	/* 0xe9e: je     ea5 <trace_ret_vfs_writev_tail+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea5;
	}
x86_l_ea0:
	/* 0xea0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ea3:
	/* 0xea3: jbe    ece <trace_ret_vfs_writev_tail+0xece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ece;
	}
x86_l_ea5:
	/* 0xea5: and    r14,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 216ULL);
x86_l_ead:
	/* 0xead: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_eb0:
	/* 0xeb0: jmp    ece <trace_ret_vfs_writev_tail+0xece> */
	goto x86_l_ece;
x86_l_eb2:
	/* 0xeb2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb4:
	/* 0xeb4: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_ebc:
	/* 0xebc: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ebf:
	/* 0xebf: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ec4:
	/* 0xec4: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: jae    e95 <trace_ret_vfs_writev_tail+0xe95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e95;
	}
x86_l_ec9:
	/* 0xec9: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ece:
	/* 0xece: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed1:
	/* 0xed1: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed4:
	/* 0xed4: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_ed7:
	/* 0xed7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_edc:
	/* 0xedc: cmp    QWORD PTR [r12+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_ee5:
	/* 0xee5: je     fa1 <trace_ret_vfs_writev_tail+0xfa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4001ULL;
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
	/* 0xeff: mov    r14,QWORD PTR [r12+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f07:
	/* 0xf07: mov    r13,QWORD PTR [r12+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f0f:
	/* 0xf0f: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_f12:
	/* 0xf12: mov    r12,QWORD PTR [r12+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f1a:
	/* 0xf1a: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_f22:
	/* 0xf22: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f27:
	/* 0xf27: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f2e:
	/* 0xf2e: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f33:
	/* 0xf33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f38:
	/* 0xf38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3a:
	/* 0xf3a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
	return 3901ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3901ULL: goto x86_l_f3d;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3921ULL: goto x86_l_f51;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3966ULL: goto x86_l_f7e;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4001ULL: goto x86_l_fa1;
	case 4010ULL: goto x86_l_faa;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4114ULL: goto x86_l_1012;
	case 4118ULL: goto x86_l_1016;
	case 4123ULL: goto x86_l_101b;
	case 4131ULL: goto x86_l_1023;
	case 4139ULL: goto x86_l_102b;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4174ULL: goto x86_l_104e;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4187ULL: goto x86_l_105b;
	case 4190ULL: goto x86_l_105e;
	case 4192ULL: goto x86_l_1060;
	case 4196ULL: goto x86_l_1064;
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
	case 4239ULL: goto x86_l_108f;
	case 4248ULL: goto x86_l_1098;
	case 4254ULL: goto x86_l_109e;
	case 4262ULL: goto x86_l_10a6;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4318ULL: goto x86_l_10de;
	case 4322ULL: goto x86_l_10e2;
	case 4326ULL: goto x86_l_10e6;
	case 4330ULL: goto x86_l_10ea;
	case 4334ULL: goto x86_l_10ee;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4387ULL: goto x86_l_1123;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4445ULL: goto x86_l_115d;
	case 4447ULL: goto x86_l_115f;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4479ULL: goto x86_l_117f;
	case 4481ULL: goto x86_l_1181;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4491ULL: goto x86_l_118b;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4521ULL: goto x86_l_11a9;
	case 4527ULL: goto x86_l_11af;
	case 4532ULL: goto x86_l_11b4;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4562ULL: goto x86_l_11d2;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4609ULL: goto x86_l_1201;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4645ULL: goto x86_l_1225;
	case 4647ULL: goto x86_l_1227;
	case 4655ULL: goto x86_l_122f;
	case 4663ULL: goto x86_l_1237;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4698ULL: goto x86_l_125a;
	case 4705ULL: goto x86_l_1261;
	case 4708ULL: goto x86_l_1264;
	case 4710ULL: goto x86_l_1266;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4735ULL: goto x86_l_127f;
	case 4738ULL: goto x86_l_1282;
	case 4740ULL: goto x86_l_1284;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4768ULL: goto x86_l_12a0;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4789ULL: goto x86_l_12b5;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4807ULL: goto x86_l_12c7;
	case 4815ULL: goto x86_l_12cf;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4850ULL: goto x86_l_12f2;
	case 4857ULL: goto x86_l_12f9;
	case 4860ULL: goto x86_l_12fc;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4900ULL: goto x86_l_1324;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4933ULL: goto x86_l_1345;
	case 4941ULL: goto x86_l_134d;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4974ULL: goto x86_l_136e;
	case 4976ULL: goto x86_l_1370;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5003ULL: goto x86_l_138b;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5020ULL: goto x86_l_139c;
	case 5022ULL: goto x86_l_139e;
	case 5025ULL: goto x86_l_13a1;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5052ULL: goto x86_l_13bc;
	case 5060ULL: goto x86_l_13c4;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5101ULL: goto x86_l_13ed;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5113ULL: goto x86_l_13f9;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5124ULL: goto x86_l_1404;
	case 5127ULL: goto x86_l_1407;
	case 5129ULL: goto x86_l_1409;
	case 5132ULL: goto x86_l_140c;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5146ULL: goto x86_l_141a;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5168ULL: goto x86_l_1430;
	case 5171ULL: goto x86_l_1433;
	case 5177ULL: goto x86_l_1439;
	case 5185ULL: goto x86_l_1441;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5220ULL: goto x86_l_1464;
	case 5227ULL: goto x86_l_146b;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5268ULL: goto x86_l_1494;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5290ULL: goto x86_l_14aa;
	case 5293ULL: goto x86_l_14ad;
	case 5295ULL: goto x86_l_14af;
	case 5297ULL: goto x86_l_14b1;
	case 5300ULL: goto x86_l_14b4;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5337ULL: goto x86_l_14d9;
	case 5341ULL: goto x86_l_14dd;
	case 5344ULL: goto x86_l_14e0;
	case 5352ULL: goto x86_l_14e8;
	case 5360ULL: goto x86_l_14f0;
	case 5366ULL: goto x86_l_14f6;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5384ULL: goto x86_l_1508;
	case 5388ULL: goto x86_l_150c;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5429ULL: goto x86_l_1535;
	case 5432ULL: goto x86_l_1538;
	case 5434ULL: goto x86_l_153a;
	case 5437ULL: goto x86_l_153d;
	case 5440ULL: goto x86_l_1540;
	case 5448ULL: goto x86_l_1548;
	case 5456ULL: goto x86_l_1550;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5468ULL: goto x86_l_155c;
	case 5477ULL: goto x86_l_1565;
	case 5486ULL: goto x86_l_156e;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f3d:
	/* 0xf3d: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f40:
	/* 0xf40: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f45:
	/* 0xf45: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f4c:
	/* 0xf4c: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_f4f:
	/* 0xf4f: je     f6e <trace_ret_vfs_writev_tail+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6e;
	}
x86_l_f51:
	/* 0xf51: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f56:
	/* 0xf56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5b:
	/* 0xf5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5d:
	/* 0xf5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f60:
	/* 0xf60: je     f6e <trace_ret_vfs_writev_tail+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6e;
	}
x86_l_f62:
	/* 0xf62: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f65:
	/* 0xf65: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f69:
	/* 0xf69: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f6c:
	/* 0xf6c: jmp    f70 <trace_ret_vfs_writev_tail+0xf70> */
	goto x86_l_f70;
x86_l_f6e:
	/* 0xf6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f70:
	/* 0xf70: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f73:
	/* 0xf73: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f78:
	/* 0xf78: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f7b:
	/* 0xf7b: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f7e:
	/* 0xf7e: jb     f91 <trace_ret_vfs_writev_tail+0xf91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f91;
	}
x86_l_f80:
	/* 0xf80: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f84:
	/* 0xf84: je     f8b <trace_ret_vfs_writev_tail+0xf8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8b;
	}
x86_l_f86:
	/* 0xf86: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_f89:
	/* 0xf89: jbe    f91 <trace_ret_vfs_writev_tail+0xf91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f91;
	}
x86_l_f8b:
	/* 0xf8b: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_f8e:
	/* 0xf8e: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_f91:
	/* 0xf91: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f94:
	/* 0xf94: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_f97:
	/* 0xf97: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f9c:
	/* 0xf9c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa1:
	/* 0xfa1: cmp    QWORD PTR [r12+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_faa:
	/* 0xfaa: je     108f <trace_ret_vfs_writev_tail+0x108f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108f;
	}
x86_l_fb0:
	/* 0xfb0: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_fb5:
	/* 0xfb5: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_fbd:
	/* 0xfbd: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fc2:
	/* 0xfc2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc7:
	/* 0xfc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fcc:
	/* 0xfcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd1:
	/* 0xfd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd3:
	/* 0xfd3: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fd8:
	/* 0xfd8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fdc:
	/* 0xfdc: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fe1:
	/* 0xfe1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fe6:
	/* 0xfe6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_feb:
	/* 0xfeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff0:
	/* 0xff0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff2:
	/* 0xff2: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ff7:
	/* 0xff7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ffc:
	/* 0xffc: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1001:
	/* 0x1001: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1006:
	/* 0x1006: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_100b:
	/* 0x100b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1010:
	/* 0x1010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1012:
	/* 0x1012: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1016:
	/* 0x1016: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_101b:
	/* 0x101b: mov    rbx,QWORD PTR [r12+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1023:
	/* 0x1023: mov    r14,QWORD PTR [r12+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_102b:
	/* 0x102b: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1033:
	/* 0x1033: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1038:
	/* 0x1038: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_103f:
	/* 0x103f: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1044:
	/* 0x1044: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1049:
	/* 0x1049: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_104c:
	/* 0x104c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104e:
	/* 0x104e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1051:
	/* 0x1051: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1054:
	/* 0x1054: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_105b:
	/* 0x105b: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_105e:
	/* 0x105e: je     107c <trace_ret_vfs_writev_tail+0x107c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1060:
	/* 0x1060: lea    rsi,[rax+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1064:
	/* 0x1064: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1069:
	/* 0x1069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106b:
	/* 0x106b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: je     107c <trace_ret_vfs_writev_tail+0x107c> */
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
	/* 0x107a: jmp    107e <trace_ret_vfs_writev_tail+0x107e> */
	goto x86_l_107e;
x86_l_107c:
	/* 0x107c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107e:
	/* 0x107e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1081:
	/* 0x1081: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1084:
	/* 0x1084: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1087:
	/* 0x1087: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_108a:
	/* 0x108a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108f:
	/* 0x108f: cmp    QWORD PTR [r12+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1098:
	/* 0x1098: je     11a0 <trace_ret_vfs_writev_tail+0x11a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a0;
	}
x86_l_109e:
	/* 0x109e: mov    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_10a6:
	/* 0x10a6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10aa:
	/* 0x10aa: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10af:
	/* 0x10af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10b4:
	/* 0x10b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b9:
	/* 0x10b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10be:
	/* 0x10be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c0:
	/* 0x10c0: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10c5:
	/* 0x10c5: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10ca:
	/* 0x10ca: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10cf:
	/* 0x10cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d4:
	/* 0x10d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d9:
	/* 0x10d9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10dc:
	/* 0x10dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10de:
	/* 0x10de: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10e2:
	/* 0x10e2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_10e6:
	/* 0x10e6: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_10ea:
	/* 0x10ea: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10ee:
	/* 0x10ee: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10f3:
	/* 0x10f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10f8:
	/* 0x10f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10fd:
	/* 0x10fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1102:
	/* 0x1102: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1104:
	/* 0x1104: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1109:
	/* 0x1109: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_110d:
	/* 0x110d: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1112:
	/* 0x1112: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1117:
	/* 0x1117: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_111c:
	/* 0x111c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1121:
	/* 0x1121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1123:
	/* 0x1123: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1127:
	/* 0x1127: mov    DWORD PTR [r12+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_112c:
	/* 0x112c: mov    rbx,QWORD PTR [r12+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1134:
	/* 0x1134: mov    r14,QWORD PTR [r12+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_113c:
	/* 0x113c: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1144:
	/* 0x1144: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1149:
	/* 0x1149: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1150:
	/* 0x1150: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1155:
	/* 0x1155: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_115a:
	/* 0x115a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_115d:
	/* 0x115d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115f:
	/* 0x115f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1162:
	/* 0x1162: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1165:
	/* 0x1165: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_116c:
	/* 0x116c: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: je     118d <trace_ret_vfs_writev_tail+0x118d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118d;
	}
x86_l_1171:
	/* 0x1171: lea    rsi,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1175:
	/* 0x1175: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_117a:
	/* 0x117a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117c:
	/* 0x117c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_117f:
	/* 0x117f: je     118d <trace_ret_vfs_writev_tail+0x118d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118d;
	}
x86_l_1181:
	/* 0x1181: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1184:
	/* 0x1184: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1188:
	/* 0x1188: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_118b:
	/* 0x118b: jmp    118f <trace_ret_vfs_writev_tail+0x118f> */
	goto x86_l_118f;
x86_l_118d:
	/* 0x118d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118f:
	/* 0x118f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1192:
	/* 0x1192: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1195:
	/* 0x1195: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1198:
	/* 0x1198: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_119b:
	/* 0x119b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a0:
	/* 0x11a0: cmp    QWORD PTR [r12+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11a9:
	/* 0x11a9: je     1297 <trace_ret_vfs_writev_tail+0x1297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1297;
	}
x86_l_11af:
	/* 0x11af: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11b4:
	/* 0x11b4: add    rdx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_11bc:
	/* 0x11bc: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11c1:
	/* 0x11c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11c6:
	/* 0x11c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11cb:
	/* 0x11cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11d0:
	/* 0x11d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d2:
	/* 0x11d2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11d7:
	/* 0x11d7: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11dc:
	/* 0x11dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11e1:
	/* 0x11e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11e6:
	/* 0x11e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11eb:
	/* 0x11eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ed:
	/* 0x11ed: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11f2:
	/* 0x11f2: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11f7:
	/* 0x11f7: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_11fc:
	/* 0x11fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1201:
	/* 0x1201: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1204:
	/* 0x1204: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1209:
	/* 0x1209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120b:
	/* 0x120b: lea    r13,[r12+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1210:
	/* 0x1210: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1215:
	/* 0x1215: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_121a:
	/* 0x121a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_121d:
	/* 0x121d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1222:
	/* 0x1222: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1225:
	/* 0x1225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1227:
	/* 0x1227: mov    rbx,QWORD PTR [r12+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_122f:
	/* 0x122f: mov    r14,QWORD PTR [r12+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1237:
	/* 0x1237: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_123f:
	/* 0x123f: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1244:
	/* 0x1244: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_124b:
	/* 0x124b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1250:
	/* 0x1250: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1255:
	/* 0x1255: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1258:
	/* 0x1258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125a:
	/* 0x125a: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1261:
	/* 0x1261: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1264:
	/* 0x1264: je     1284 <trace_ret_vfs_writev_tail+0x1284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1284;
	}
x86_l_1266:
	/* 0x1266: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1269:
	/* 0x1269: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_126e:
	/* 0x126e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1271:
	/* 0x1271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1273:
	/* 0x1273: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1276:
	/* 0x1276: je     1284 <trace_ret_vfs_writev_tail+0x1284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1284;
	}
x86_l_1278:
	/* 0x1278: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127b:
	/* 0x127b: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_127f:
	/* 0x127f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1282:
	/* 0x1282: jmp    1286 <trace_ret_vfs_writev_tail+0x1286> */
	goto x86_l_1286;
x86_l_1284:
	/* 0x1284: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1286:
	/* 0x1286: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1289:
	/* 0x1289: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_128c:
	/* 0x128c: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_128f:
	/* 0x128f: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1292:
	/* 0x1292: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1297:
	/* 0x1297: cmp    QWORD PTR [r12+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12a0:
	/* 0x12a0: je     132f <trace_ret_vfs_writev_tail+0x132f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132f;
	}
x86_l_12a6:
	/* 0x12a6: lea    r13,[r12+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12ab:
	/* 0x12ab: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12b0:
	/* 0x12b0: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12b5:
	/* 0x12b5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_12b8:
	/* 0x12b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12bd:
	/* 0x12bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12bf:
	/* 0x12bf: mov    rbx,QWORD PTR [r12+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12c7:
	/* 0x12c7: mov    r14,QWORD PTR [r12+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12cf:
	/* 0x12cf: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_12d7:
	/* 0x12d7: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12dc:
	/* 0x12dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12e3:
	/* 0x12e3: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12e8:
	/* 0x12e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ed:
	/* 0x12ed: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12f0:
	/* 0x12f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f2:
	/* 0x12f2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12f9:
	/* 0x12f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12fc:
	/* 0x12fc: je     131c <trace_ret_vfs_writev_tail+0x131c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131c;
	}
x86_l_12fe:
	/* 0x12fe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1301:
	/* 0x1301: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1306:
	/* 0x1306: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1309:
	/* 0x1309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130b:
	/* 0x130b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_130e:
	/* 0x130e: je     131c <trace_ret_vfs_writev_tail+0x131c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131c;
	}
x86_l_1310:
	/* 0x1310: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1313:
	/* 0x1313: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1317:
	/* 0x1317: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_131a:
	/* 0x131a: jmp    131e <trace_ret_vfs_writev_tail+0x131e> */
	goto x86_l_131e;
x86_l_131c:
	/* 0x131c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131e:
	/* 0x131e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1321:
	/* 0x1321: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1324:
	/* 0x1324: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1327:
	/* 0x1327: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_132a:
	/* 0x132a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132f:
	/* 0x132f: mov    rbx,QWORD PTR [r12+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1337:
	/* 0x1337: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_133a:
	/* 0x133a: je     13af <trace_ret_vfs_writev_tail+0x13af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13af;
	}
x86_l_133c:
	/* 0x133c: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1341:
	/* 0x1341: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1345:
	/* 0x1345: mov    r14,QWORD PTR [r12+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_134d:
	/* 0x134d: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1355:
	/* 0x1355: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_135a:
	/* 0x135a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1361:
	/* 0x1361: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1366:
	/* 0x1366: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_136b:
	/* 0x136b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_136e:
	/* 0x136e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1370:
	/* 0x1370: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1377:
	/* 0x1377: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_137a:
	/* 0x137a: je     139c <trace_ret_vfs_writev_tail+0x139c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139c;
	}
x86_l_137c:
	/* 0x137c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_137f:
	/* 0x137f: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1384:
	/* 0x1384: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1389:
	/* 0x1389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138b:
	/* 0x138b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138e:
	/* 0x138e: je     139c <trace_ret_vfs_writev_tail+0x139c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139c;
	}
x86_l_1390:
	/* 0x1390: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1393:
	/* 0x1393: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1397:
	/* 0x1397: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_139a:
	/* 0x139a: jmp    139e <trace_ret_vfs_writev_tail+0x139e> */
	goto x86_l_139e;
x86_l_139c:
	/* 0x139c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139e:
	/* 0x139e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13a1:
	/* 0x13a1: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_13a4:
	/* 0x13a4: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13a7:
	/* 0x13a7: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13aa:
	/* 0x13aa: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13af:
	/* 0x13af: mov    rbx,QWORD PTR [r12+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13b7:
	/* 0x13b7: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13ba:
	/* 0x13ba: je     1428 <trace_ret_vfs_writev_tail+0x1428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1428;
	}
x86_l_13bc:
	/* 0x13bc: mov    r14,QWORD PTR [r12+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13c4:
	/* 0x13c4: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_13cc:
	/* 0x13cc: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13d1:
	/* 0x13d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13d8:
	/* 0x13d8: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13dd:
	/* 0x13dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e2:
	/* 0x13e2: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13e5:
	/* 0x13e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e7:
	/* 0x13e7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_13ed:
	/* 0x13ed: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13f4:
	/* 0x13f4: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_13f7:
	/* 0x13f7: je     1415 <trace_ret_vfs_writev_tail+0x1415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1415;
	}
x86_l_13f9:
	/* 0x13f9: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13fd:
	/* 0x13fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1402:
	/* 0x1402: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1404:
	/* 0x1404: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1407:
	/* 0x1407: je     1415 <trace_ret_vfs_writev_tail+0x1415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1415;
	}
x86_l_1409:
	/* 0x1409: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_140c:
	/* 0x140c: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1410:
	/* 0x1410: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1413:
	/* 0x1413: jmp    1417 <trace_ret_vfs_writev_tail+0x1417> */
	goto x86_l_1417;
x86_l_1415:
	/* 0x1415: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1417:
	/* 0x1417: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_141a:
	/* 0x141a: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_141d:
	/* 0x141d: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1420:
	/* 0x1420: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1423:
	/* 0x1423: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1428:
	/* 0x1428: mov    rbx,QWORD PTR [r12+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1430:
	/* 0x1430: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1433:
	/* 0x1433: je     14c2 <trace_ret_vfs_writev_tail+0x14c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14c2;
	}
x86_l_1439:
	/* 0x1439: mov    r14,QWORD PTR [r12+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1441:
	/* 0x1441: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1449:
	/* 0x1449: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_144e:
	/* 0x144e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1455:
	/* 0x1455: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_145a:
	/* 0x145a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_145f:
	/* 0x145f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1462:
	/* 0x1462: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1464:
	/* 0x1464: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_146b:
	/* 0x146b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146e:
	/* 0x146e: je     14af <trace_ret_vfs_writev_tail+0x14af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14af;
	}
x86_l_1470:
	/* 0x1470: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1473:
	/* 0x1473: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1478:
	/* 0x1478: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_147c:
	/* 0x147c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1481:
	/* 0x1481: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1484:
	/* 0x1484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1486:
	/* 0x1486: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1489:
	/* 0x1489: jne    14a3 <trace_ret_vfs_writev_tail+0x14a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a3;
	}
x86_l_148b:
	/* 0x148b: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1490:
	/* 0x1490: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1494:
	/* 0x1494: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1499:
	/* 0x1499: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_149c:
	/* 0x149c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149e:
	/* 0x149e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a1:
	/* 0x14a1: je     14af <trace_ret_vfs_writev_tail+0x14af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14af;
	}
x86_l_14a3:
	/* 0x14a3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a6:
	/* 0x14a6: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14aa:
	/* 0x14aa: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14ad:
	/* 0x14ad: jmp    14b1 <trace_ret_vfs_writev_tail+0x14b1> */
	goto x86_l_14b1;
x86_l_14af:
	/* 0x14af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b1:
	/* 0x14b1: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14b4:
	/* 0x14b4: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_14b7:
	/* 0x14b7: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14ba:
	/* 0x14ba: and    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_14bd:
	/* 0x14bd: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14c2:
	/* 0x14c2: mov    rax,QWORD PTR [r12+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14ca:
	/* 0x14ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14cd:
	/* 0x14cd: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14d2:
	/* 0x14d2: je     14e0 <trace_ret_vfs_writev_tail+0x14e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e0;
	}
x86_l_14d4:
	/* 0x14d4: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14d9:
	/* 0x14d9: and    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14dd:
	/* 0x14dd: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14e0:
	/* 0x14e0: and    r15,QWORD PTR [r12+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14e8:
	/* 0x14e8: and    QWORD PTR [r12+0x80],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R12, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_14f0:
	/* 0x14f0: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_14f6:
	/* 0x14f6: test   BYTE PTR [rcx+0x4],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_14fa:
	/* 0x14fa: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_1500:
	/* 0x1500: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1508:
	/* 0x1508: mov    rbx,QWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_150c:
	/* 0x150c: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1514:
	/* 0x1514: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1519:
	/* 0x1519: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_151e:
	/* 0x151e: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1526:
	/* 0x1526: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_152b:
	/* 0x152b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152d:
	/* 0x152d: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1535:
	/* 0x1535: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1538:
	/* 0x1538: je     1552 <trace_ret_vfs_writev_tail+0x1552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1552;
	}
x86_l_153a:
	/* 0x153a: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_153d:
	/* 0x153d: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1540:
	/* 0x1540: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1548:
	/* 0x1548: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1550:
	/* 0x1550: jmp    155c <trace_ret_vfs_writev_tail+0x155c> */
	goto x86_l_155c;
x86_l_1552:
	/* 0x1552: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1554:
	/* 0x1554: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_155c:
	/* 0x155c: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1565:
	/* 0x1565: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_156e:
	/* 0x156e: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1577:
	/* 0x1577: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_157a:
	/* 0x157a: je     1707 <trace_ret_vfs_writev_tail+0x1707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5895ULL;
	}
x86_l_1580:
	/* 0x1580: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1584:
	/* 0x1584: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1589:
	/* 0x1589: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_158e:
	/* 0x158e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1593:
	/* 0x1593: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1598:
	/* 0x1598: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5533ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5547ULL: goto x86_l_15ab;
	case 5556ULL: goto x86_l_15b4;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5596ULL: goto x86_l_15dc;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5621ULL: goto x86_l_15f5;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5812ULL: goto x86_l_16b4;
	case 5816ULL: goto x86_l_16b8;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5850ULL: goto x86_l_16da;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5920ULL: goto x86_l_1720;
	case 5926ULL: goto x86_l_1726;
	case 5929ULL: goto x86_l_1729;
	case 5937ULL: goto x86_l_1731;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5959ULL: goto x86_l_1747;
	case 5965ULL: goto x86_l_174d;
	case 5968ULL: goto x86_l_1750;
	case 5970ULL: goto x86_l_1752;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5982ULL: goto x86_l_175e;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6036ULL: goto x86_l_1794;
	case 6041ULL: goto x86_l_1799;
	case 6043ULL: goto x86_l_179b;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6067ULL: goto x86_l_17b3;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6091ULL: goto x86_l_17cb;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6115ULL: goto x86_l_17e3;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6132ULL: goto x86_l_17f4;
	case 6137ULL: goto x86_l_17f9;
	case 6139ULL: goto x86_l_17fb;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6163ULL: goto x86_l_1813;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6206ULL: goto x86_l_183e;
	case 6211ULL: goto x86_l_1843;
	case 6219ULL: goto x86_l_184b;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6247ULL: goto x86_l_1867;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6394ULL: goto x86_l_18fa;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6482ULL: goto x86_l_1952;
	case 6488ULL: goto x86_l_1958;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6556ULL: goto x86_l_199c;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6574ULL: goto x86_l_19ae;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6642ULL: goto x86_l_19f2;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6903ULL: goto x86_l_1af7;
	case 6906ULL: goto x86_l_1afa;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6956ULL: goto x86_l_1b2c;
	case 6962ULL: goto x86_l_1b32;
	case 6968ULL: goto x86_l_1b38;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7007ULL: goto x86_l_1b5f;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7074ULL: goto x86_l_1ba2;
	case 7077ULL: goto x86_l_1ba5;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7094ULL: goto x86_l_1bb6;
	case 7100ULL: goto x86_l_1bbc;
	case 7108ULL: goto x86_l_1bc4;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7144ULL: goto x86_l_1be8;
	case 7150ULL: goto x86_l_1bee;
	case 7152ULL: goto x86_l_1bf0;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7169ULL: goto x86_l_1c01;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7241ULL: goto x86_l_1c49;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_159d:
	/* 0x159d: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15a2:
	/* 0x15a2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_15ab:
	/* 0x15ab: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15b4:
	/* 0x15b4: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b8:
	/* 0x15b8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15bd:
	/* 0x15bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15c2:
	/* 0x15c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15c7:
	/* 0x15c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15cc:
	/* 0x15cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ce:
	/* 0x15ce: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15d3:
	/* 0x15d3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15d8:
	/* 0x15d8: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_15dc:
	/* 0x15dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15e1:
	/* 0x15e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15e6:
	/* 0x15e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15eb:
	/* 0x15eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15f0:
	/* 0x15f0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f5:
	/* 0x15f5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15f9:
	/* 0x15f9: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15fe:
	/* 0x15fe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1603:
	/* 0x1603: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1608:
	/* 0x1608: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_160d:
	/* 0x160d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1612:
	/* 0x1612: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1617:
	/* 0x1617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1619:
	/* 0x1619: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_161e:
	/* 0x161e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1621:
	/* 0x1621: js     164c <trace_ret_vfs_writev_tail+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_164c;
	}
x86_l_1623:
	/* 0x1623: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1628:
	/* 0x1628: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162d:
	/* 0x162d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1637:
	/* 0x1637: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_163c:
	/* 0x163c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163e:
	/* 0x163e: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1645:
	/* 0x1645: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_164a:
	/* 0x164a: jmp    164e <trace_ret_vfs_writev_tail+0x164e> */
	goto x86_l_164e;
x86_l_164c:
	/* 0x164c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164e:
	/* 0x164e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1653:
	/* 0x1653: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1658:
	/* 0x1658: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_165d:
	/* 0x165d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1662:
	/* 0x1662: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1667:
	/* 0x1667: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_166a:
	/* 0x166a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166c:
	/* 0x166c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1671:
	/* 0x1671: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1675:
	/* 0x1675: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167a:
	/* 0x167a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_167f:
	/* 0x167f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1684:
	/* 0x1684: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1689:
	/* 0x1689: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_168d:
	/* 0x168d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1692:
	/* 0x1692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1694:
	/* 0x1694: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1699:
	/* 0x1699: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_169e:
	/* 0x169e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_16a3:
	/* 0x16a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16a8:
	/* 0x16a8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16ad:
	/* 0x16ad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16b2:
	/* 0x16b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b4:
	/* 0x16b4: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16b8:
	/* 0x16b8: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_16bc:
	/* 0x16bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16c1:
	/* 0x16c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16c6:
	/* 0x16c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16cb:
	/* 0x16cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d0:
	/* 0x16d0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_16d3:
	/* 0x16d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d5:
	/* 0x16d5: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16da:
	/* 0x16da: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16de:
	/* 0x16de: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e3:
	/* 0x16e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16e8:
	/* 0x16e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16ed:
	/* 0x16ed: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f2:
	/* 0x16f2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16f6:
	/* 0x16f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16fb:
	/* 0x16fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fd:
	/* 0x16fd: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1702:
	/* 0x1702: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1707:
	/* 0x1707: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_170e:
	/* 0x170e: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1713:
	/* 0x1713: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1718:
	/* 0x1718: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171d:
	/* 0x171d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1720:
	/* 0x1720: je     1843 <trace_ret_vfs_writev_tail+0x1843> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1843;
	}
x86_l_1726:
	/* 0x1726: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1729:
	/* 0x1729: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1731:
	/* 0x1731: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1738:
	/* 0x1738: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_173d:
	/* 0x173d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1742:
	/* 0x1742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1744:
	/* 0x1744: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1747:
	/* 0x1747: je     39d4 <trace_ret_vfs_writev_tail+0x39d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14804ULL;
	}
x86_l_174d:
	/* 0x174d: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1750:
	/* 0x1750: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1752:
	/* 0x1752: je     19c4 <trace_ret_vfs_writev_tail+0x19c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19c4;
	}
x86_l_1758:
	/* 0x1758: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175a:
	/* 0x175a: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_175e:
	/* 0x175e: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_1764:
	/* 0x1764: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1769:
	/* 0x1769: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_176b:
	/* 0x176b: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1771:
	/* 0x1771: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1776:
	/* 0x1776: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_177c:
	/* 0x177c: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1781:
	/* 0x1781: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1783:
	/* 0x1783: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1789:
	/* 0x1789: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_178e:
	/* 0x178e: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_1794:
	/* 0x1794: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1799:
	/* 0x1799: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_179b:
	/* 0x179b: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_17a1:
	/* 0x17a1: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_17a6:
	/* 0x17a6: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_17ac:
	/* 0x17ac: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_17b1:
	/* 0x17b1: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17b3:
	/* 0x17b3: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_17b9:
	/* 0x17b9: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_17be:
	/* 0x17be: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_17c4:
	/* 0x17c4: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_17c9:
	/* 0x17c9: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17cb:
	/* 0x17cb: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_17d1:
	/* 0x17d1: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_17d6:
	/* 0x17d6: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_17dc:
	/* 0x17dc: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_17e1:
	/* 0x17e1: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17e3:
	/* 0x17e3: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_17e9:
	/* 0x17e9: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_17ee:
	/* 0x17ee: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_17f4:
	/* 0x17f4: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_17f9:
	/* 0x17f9: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_17fb:
	/* 0x17fb: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1801:
	/* 0x1801: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1806:
	/* 0x1806: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_180c:
	/* 0x180c: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1811:
	/* 0x1811: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1813:
	/* 0x1813: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1819:
	/* 0x1819: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_181e:
	/* 0x181e: jne    1bbc <trace_ret_vfs_writev_tail+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bbc;
	}
x86_l_1824:
	/* 0x1824: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1827:
	/* 0x1827: je     1bb2 <trace_ret_vfs_writev_tail+0x1bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb2;
	}
x86_l_182d:
	/* 0x182d: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_1832:
	/* 0x1832: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1836:
	/* 0x1836: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1838:
	/* 0x1838: jne    175a <trace_ret_vfs_writev_tail+0x175a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175a;
	}
x86_l_183e:
	/* 0x183e: jmp    216d <trace_ret_vfs_writev_tail+0x216d> */
	return 8557ULL;
x86_l_1843:
	/* 0x1843: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_184b:
	/* 0x184b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_1852:
	/* 0x1852: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1857:
	/* 0x1857: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_185c:
	/* 0x185c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185e:
	/* 0x185e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1861:
	/* 0x1861: je     2175 <trace_ret_vfs_writev_tail+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8565ULL;
	}
x86_l_1867:
	/* 0x1867: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_186a:
	/* 0x186a: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_186e:
	/* 0x186e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1873:
	/* 0x1873: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1878:
	/* 0x1878: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_187d:
	/* 0x187d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1882:
	/* 0x1882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1884:
	/* 0x1884: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1889:
	/* 0x1889: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_188e:
	/* 0x188e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1893:
	/* 0x1893: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1898:
	/* 0x1898: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_189d:
	/* 0x189d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18a2:
	/* 0x18a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a7:
	/* 0x18a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a9:
	/* 0x18a9: test   BYTE PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215136ULL);
x86_l_18ae:
	/* 0x18ae: jne    19cc <trace_ret_vfs_writev_tail+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19cc;
	}
x86_l_18b4:
	/* 0x18b4: mov    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18b9:
	/* 0x18b9: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bd:
	/* 0x18bd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c2:
	/* 0x18c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18c7:
	/* 0x18c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18cc:
	/* 0x18cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18d1:
	/* 0x18d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d3:
	/* 0x18d3: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18d8:
	/* 0x18d8: lea    rcx,[r14-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_18dc:
	/* 0x18dc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e1:
	/* 0x18e1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e6:
	/* 0x18e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18eb:
	/* 0x18eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18f0:
	/* 0x18f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f5:
	/* 0x18f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18fa:
	/* 0x18fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fc:
	/* 0x18fc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1901:
	/* 0x1901: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1906:
	/* 0x1906: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_190b:
	/* 0x190b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1910:
	/* 0x1910: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_1913:
	/* 0x1913: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1916:
	/* 0x1916: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1918:
	/* 0x1918: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_191d:
	/* 0x191d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1922:
	/* 0x1922: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1926:
	/* 0x1926: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_192b:
	/* 0x192b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1930:
	/* 0x1930: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1935:
	/* 0x1935: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193a:
	/* 0x193a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193c:
	/* 0x193c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1941:
	/* 0x1941: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1944:
	/* 0x1944: je     19ef <trace_ret_vfs_writev_tail+0x19ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ef;
	}
x86_l_194a:
	/* 0x194a: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_194f:
	/* 0x194f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1952:
	/* 0x1952: je     19ef <trace_ret_vfs_writev_tail+0x19ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ef;
	}
x86_l_1958:
	/* 0x1958: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_195c:
	/* 0x195c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1961:
	/* 0x1961: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1966:
	/* 0x1966: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_196b:
	/* 0x196b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1970:
	/* 0x1970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1972:
	/* 0x1972: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1976:
	/* 0x1976: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_197b:
	/* 0x197b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_197d:
	/* 0x197d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1983:
	/* 0x1983: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1985:
	/* 0x1985: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1987:
	/* 0x1987: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_198d:
	/* 0x198d: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_1992:
	/* 0x1992: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1997:
	/* 0x1997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1999:
	/* 0x1999: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_199c:
	/* 0x199c: jl     1b65 <trace_ret_vfs_writev_tail+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b65;
	}
x86_l_19a2:
	/* 0x19a2: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19a7:
	/* 0x19a7: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_19ae:
	/* 0x19ae: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_19b4:
	/* 0x19b4: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19b7:
	/* 0x19b7: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19bc:
	/* 0x19bc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19bf:
	/* 0x19bf: jmp    1a7a <trace_ret_vfs_writev_tail+0x1a7a> */
	goto x86_l_1a7a;
x86_l_19c4:
	/* 0x19c4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c7:
	/* 0x19c7: jmp    215a <trace_ret_vfs_writev_tail+0x215a> */
	return 8538ULL;
x86_l_19cc:
	/* 0x19cc: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_19d3:
	/* 0x19d3: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_19d8:
	/* 0x19d8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19dd:
	/* 0x19dd: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_19e0:
	/* 0x19e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19e5:
	/* 0x19e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e7:
	/* 0x19e7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19ea:
	/* 0x19ea: jmp    1e23 <trace_ret_vfs_writev_tail+0x1e23> */
	return 7715ULL;
x86_l_19ef:
	/* 0x19ef: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_19f2:
	/* 0x19f2: jne    1b65 <trace_ret_vfs_writev_tail+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b65;
	}
x86_l_19f8:
	/* 0x19f8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fd:
	/* 0x19fd: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_1a02:
	/* 0x1a02: je     1b65 <trace_ret_vfs_writev_tail+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b65;
	}
x86_l_1a08:
	/* 0x1a08: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a0c:
	/* 0x1a0c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a11:
	/* 0x1a11: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a16:
	/* 0x1a16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a20:
	/* 0x1a20: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a24:
	/* 0x1a24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a29:
	/* 0x1a29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2b:
	/* 0x1a2b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a30:
	/* 0x1a30: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a35:
	/* 0x1a35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a44:
	/* 0x1a44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a49:
	/* 0x1a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4b:
	/* 0x1a4b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a50:
	/* 0x1a50: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a55:
	/* 0x1a55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a5a:
	/* 0x1a5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a64:
	/* 0x1a64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a69:
	/* 0x1a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6b:
	/* 0x1a6b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a70:
	/* 0x1a70: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a74:
	/* 0x1a74: mov    r14d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_1a7a:
	/* 0x1a7a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a84:
	/* 0x1a84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a89:
	/* 0x1a89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a8e:
	/* 0x1a8e: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a93:
	/* 0x1a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a95:
	/* 0x1a95: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a9f:
	/* 0x1a9f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1aa3:
	/* 0x1aa3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aad:
	/* 0x1aad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab7:
	/* 0x1ab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab9:
	/* 0x1ab9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1abe:
	/* 0x1abe: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ac1:
	/* 0x1ac1: je     1b4a <trace_ret_vfs_writev_tail+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4a;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1acc:
	/* 0x1acc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: je     1b4a <trace_ret_vfs_writev_tail+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4a;
	}
x86_l_1ad1:
	/* 0x1ad1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ad5:
	/* 0x1ad5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ada:
	/* 0x1ada: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1adf:
	/* 0x1adf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1aef:
	/* 0x1aef: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1af1:
	/* 0x1af1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1af7:
	/* 0x1af7: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1afa:
	/* 0x1afa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1afc:
	/* 0x1afc: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b01:
	/* 0x1b01: jb     1df0 <trace_ret_vfs_writev_tail+0x1df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7664ULL;
	}
x86_l_1b07:
	/* 0x1b07: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0c:
	/* 0x1b0c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1b12:
	/* 0x1b12: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b17:
	/* 0x1b17: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b1a:
	/* 0x1b1a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1b1c:
	/* 0x1b1c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b21:
	/* 0x1b21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b23:
	/* 0x1b23: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b26:
	/* 0x1b26: jl     1b58 <trace_ret_vfs_writev_tail+0x1b58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1b58;
	}
x86_l_1b28:
	/* 0x1b28: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1b2c:
	/* 0x1b2c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1b32:
	/* 0x1b32: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1b38:
	/* 0x1b38: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b3b:
	/* 0x1b3b: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b40:
	/* 0x1b40: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b45:
	/* 0x1b45: jmp    1d5f <trace_ret_vfs_writev_tail+0x1d5f> */
	return 7519ULL;
x86_l_1b4a:
	/* 0x1b4a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b4d:
	/* 0x1b4d: je     1cd9 <trace_ret_vfs_writev_tail+0x1cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7385ULL;
	}
x86_l_1b53:
	/* 0x1b53: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b58:
	/* 0x1b58: cmp    r14d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16384ULL);
x86_l_1b5f:
	/* 0x1b5f: jne    1df0 <trace_ret_vfs_writev_tail+0x1df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7664ULL;
	}
x86_l_1b65:
	/* 0x1b65: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6a:
	/* 0x1b6a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b6e:
	/* 0x1b6e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b73:
	/* 0x1b73: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b78:
	/* 0x1b78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b82:
	/* 0x1b82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b84:
	/* 0x1b84: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b89:
	/* 0x1b89: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b93:
	/* 0x1b93: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b98:
	/* 0x1b98: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b9b:
	/* 0x1b9b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ba0:
	/* 0x1ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba2:
	/* 0x1ba2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ba5:
	/* 0x1ba5: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bad:
	/* 0x1bad: jmp    1e23 <trace_ret_vfs_writev_tail+0x1e23> */
	return 7715ULL;
x86_l_1bb2:
	/* 0x1bb2: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_1bb6:
	/* 0x1bb6: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1bbc:
	/* 0x1bbc: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1bcb:
	/* 0x1bcb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bd5:
	/* 0x1bd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd7:
	/* 0x1bd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bda:
	/* 0x1bda: je     39c3 <trace_ret_vfs_writev_tail+0x39c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14787ULL;
	}
x86_l_1be0:
	/* 0x1be0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1be3:
	/* 0x1be3: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1be6:
	/* 0x1be6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1be8:
	/* 0x1be8: je     215a <trace_ret_vfs_writev_tail+0x215a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8538ULL;
	}
x86_l_1bee:
	/* 0x1bee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf0:
	/* 0x1bf0: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bf4:
	/* 0x1bf4: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7775ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1bff:
	/* 0x1bff: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c01:
	/* 0x1c01: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1c07:
	/* 0x1c07: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1c0c:
	/* 0x1c0c: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7775ULL;
	}
x86_l_1c12:
	/* 0x1c12: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1c17:
	/* 0x1c17: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c19:
	/* 0x1c19: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1c1f:
	/* 0x1c1f: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1c24:
	/* 0x1c24: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7775ULL;
	}
x86_l_1c2a:
	/* 0x1c2a: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1c2f:
	/* 0x1c2f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c31:
	/* 0x1c31: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1c37:
	/* 0x1c37: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1c3c:
	/* 0x1c3c: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7775ULL;
	}
x86_l_1c42:
	/* 0x1c42: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1c47:
	/* 0x1c47: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c49:
	/* 0x1c49: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8557ULL;
	}
x86_l_1c4f:
	/* 0x1c4f: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1c54:
	/* 0x1c54: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7775ULL;
	}
x86_l_1c5a:
	/* 0x1c5a: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1c5f:
	/* 0x1c5f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
	return 7265ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7265ULL: goto x86_l_1c61;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7313ULL: goto x86_l_1c91;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7330ULL: goto x86_l_1ca2;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7372ULL: goto x86_l_1ccc;
	case 7374ULL: goto x86_l_1cce;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7405ULL: goto x86_l_1ced;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7590ULL: goto x86_l_1da6;
	case 7596ULL: goto x86_l_1dac;
	case 7601ULL: goto x86_l_1db1;
	case 7604ULL: goto x86_l_1db4;
	case 7610ULL: goto x86_l_1dba;
	case 7614ULL: goto x86_l_1dbe;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7640ULL: goto x86_l_1dd8;
	case 7642ULL: goto x86_l_1dda;
	case 7648ULL: goto x86_l_1de0;
	case 7651ULL: goto x86_l_1de3;
	case 7653ULL: goto x86_l_1de5;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7667ULL: goto x86_l_1df3;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7686ULL: goto x86_l_1e06;
	case 7694ULL: goto x86_l_1e0e;
	case 7701ULL: goto x86_l_1e15;
	case 7709ULL: goto x86_l_1e1d;
	case 7715ULL: goto x86_l_1e23;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7769ULL: goto x86_l_1e59;
	case 7775ULL: goto x86_l_1e5f;
	case 7783ULL: goto x86_l_1e67;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7811ULL: goto x86_l_1e83;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7824ULL: goto x86_l_1e90;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7841ULL: goto x86_l_1ea1;
	case 7847ULL: goto x86_l_1ea7;
	case 7852ULL: goto x86_l_1eac;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7887ULL: goto x86_l_1ecf;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7937ULL: goto x86_l_1f01;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8009ULL: goto x86_l_1f49;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8082ULL: goto x86_l_1f92;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8210ULL: goto x86_l_2012;
	case 8215ULL: goto x86_l_2017;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8270ULL: goto x86_l_204e;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8340ULL: goto x86_l_2094;
	case 8345ULL: goto x86_l_2099;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8388ULL: goto x86_l_20c4;
	case 8393ULL: goto x86_l_20c9;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8410ULL: goto x86_l_20da;
	case 8416ULL: goto x86_l_20e0;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8448ULL: goto x86_l_2100;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8501ULL: goto x86_l_2135;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8516ULL: goto x86_l_2144;
	case 8519ULL: goto x86_l_2147;
	case 8524ULL: goto x86_l_214c;
	case 8529ULL: goto x86_l_2151;
	case 8533ULL: goto x86_l_2155;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8541ULL: goto x86_l_215d;
	case 8549ULL: goto x86_l_2165;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8565ULL: goto x86_l_2175;
	case 8574ULL: goto x86_l_217e;
	case 8582ULL: goto x86_l_2186;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8616ULL: goto x86_l_21a8;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8666ULL: goto x86_l_21da;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8701ULL: goto x86_l_21fd;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8727ULL: goto x86_l_2217;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8750ULL: goto x86_l_222e;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8768ULL: goto x86_l_2240;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8830ULL: goto x86_l_227e;
	case 8842ULL: goto x86_l_228a;
	case 8854ULL: goto x86_l_2296;
	case 8866ULL: goto x86_l_22a2;
	case 8878ULL: goto x86_l_22ae;
	case 8887ULL: goto x86_l_22b7;
	case 8896ULL: goto x86_l_22c0;
	case 8905ULL: goto x86_l_22c9;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8939ULL: goto x86_l_22eb;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8949ULL: goto x86_l_22f5;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8964ULL: goto x86_l_2304;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8993ULL: goto x86_l_2321;
	case 8997ULL: goto x86_l_2325;
	case 8999ULL: goto x86_l_2327;
	case 9001ULL: goto x86_l_2329;
	case 9005ULL: goto x86_l_232d;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9021ULL: goto x86_l_233d;
	case 9025ULL: goto x86_l_2341;
	case 9031ULL: goto x86_l_2347;
	case 9039ULL: goto x86_l_234f;
	case 9044ULL: goto x86_l_2354;
	case 9053ULL: goto x86_l_235d;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c61:
	/* 0x1c61: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1c67:
	/* 0x1c67: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1c6c:
	/* 0x1c6c: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e5f;
	}
x86_l_1c72:
	/* 0x1c72: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1c77:
	/* 0x1c77: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c79:
	/* 0x1c79: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1c7f:
	/* 0x1c7f: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1c84:
	/* 0x1c84: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e5f;
	}
x86_l_1c8a:
	/* 0x1c8a: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1c8f:
	/* 0x1c8f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1c91:
	/* 0x1c91: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1c97:
	/* 0x1c97: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1c9c:
	/* 0x1c9c: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e5f;
	}
x86_l_1ca2:
	/* 0x1ca2: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1ca7:
	/* 0x1ca7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ca9:
	/* 0x1ca9: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1caf:
	/* 0x1caf: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1cb4:
	/* 0x1cb4: jne    1e5f <trace_ret_vfs_writev_tail+0x1e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e5f;
	}
x86_l_1cba:
	/* 0x1cba: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1cbd:
	/* 0x1cbd: je     1e55 <trace_ret_vfs_writev_tail+0x1e55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e55;
	}
x86_l_1cc3:
	/* 0x1cc3: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_1cc8:
	/* 0x1cc8: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1ccc:
	/* 0x1ccc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1cce:
	/* 0x1cce: jne    1bf0 <trace_ret_vfs_writev_tail+0x1bf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7152ULL;
	}
x86_l_1cd4:
	/* 0x1cd4: jmp    216d <trace_ret_vfs_writev_tail+0x216d> */
	goto x86_l_216d;
x86_l_1cd9:
	/* 0x1cd9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cde:
	/* 0x1cde: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce8:
	/* 0x1ce8: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ced:
	/* 0x1ced: je     1b58 <trace_ret_vfs_writev_tail+0x1b58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7000ULL;
	}
x86_l_1cf3:
	/* 0x1cf3: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cf7:
	/* 0x1cf7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d01:
	/* 0x1d01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d06:
	/* 0x1d06: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0b:
	/* 0x1d0b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d14:
	/* 0x1d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d16:
	/* 0x1d16: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d1b:
	/* 0x1d1b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d20:
	/* 0x1d20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d25:
	/* 0x1d25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d34:
	/* 0x1d34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d36:
	/* 0x1d36: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3b:
	/* 0x1d3b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d40:
	/* 0x1d40: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d45:
	/* 0x1d45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d54:
	/* 0x1d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d56:
	/* 0x1d56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5b:
	/* 0x1d5b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d5f:
	/* 0x1d5f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d64:
	/* 0x1d64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d69:
	/* 0x1d69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d73:
	/* 0x1d73: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d78:
	/* 0x1d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7a:
	/* 0x1d7a: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d84:
	/* 0x1d84: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d88:
	/* 0x1d88: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d92:
	/* 0x1d92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d97:
	/* 0x1d97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d9c:
	/* 0x1d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9e:
	/* 0x1d9e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1da3:
	/* 0x1da3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1da6:
	/* 0x1da6: je     1f79 <trace_ret_vfs_writev_tail+0x1f79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f79;
	}
x86_l_1dac:
	/* 0x1dac: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db1:
	/* 0x1db1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1db4:
	/* 0x1db4: je     1f79 <trace_ret_vfs_writev_tail+0x1f79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f79;
	}
x86_l_1dba:
	/* 0x1dba: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1dbe:
	/* 0x1dbe: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc3:
	/* 0x1dc3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dd2:
	/* 0x1dd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd4:
	/* 0x1dd4: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1dd8:
	/* 0x1dd8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1dda:
	/* 0x1dda: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1de0:
	/* 0x1de0: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1de3:
	/* 0x1de3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1de5:
	/* 0x1de5: jae    2043 <trace_ret_vfs_writev_tail+0x2043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2043;
	}
x86_l_1deb:
	/* 0x1deb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df0:
	/* 0x1df0: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1df3:
	/* 0x1df3: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1df6:
	/* 0x1df6: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e00:
	/* 0x1e00: mov    BYTE PTR [r13+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1e06:
	/* 0x1e06: mov    BYTE PTR [r13+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1e0e:
	/* 0x1e0e: cmp    r14d,0x7000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28672ULL);
x86_l_1e15:
	/* 0x1e15: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e1d:
	/* 0x1e1d: jae    2175 <trace_ret_vfs_writev_tail+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2175;
	}
x86_l_1e23:
	/* 0x1e23: and    r14d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1e2a:
	/* 0x1e2a: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e2d:
	/* 0x1e2d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1e34:
	/* 0x1e34: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e36:
	/* 0x1e36: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e3b:
	/* 0x1e3b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e40:
	/* 0x1e40: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e43:
	/* 0x1e43: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e45:
	/* 0x1e45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e47:
	/* 0x1e47: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1e4a:
	/* 0x1e4a: jne    1729 <trace_ret_vfs_writev_tail+0x1729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5929ULL;
	}
x86_l_1e50:
	/* 0x1e50: jmp    2175 <trace_ret_vfs_writev_tail+0x2175> */
	goto x86_l_2175;
x86_l_1e55:
	/* 0x1e55: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_1e59:
	/* 0x1e59: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1e5f:
	/* 0x1e5f: mov    DWORD PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1e67:
	/* 0x1e67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_write_path_filter)));
x86_l_1e6e:
	/* 0x1e6e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e73:
	/* 0x1e73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e78:
	/* 0x1e78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7a:
	/* 0x1e7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e7d:
	/* 0x1e7d: je     39c3 <trace_ret_vfs_writev_tail+0x39c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14787ULL;
	}
x86_l_1e83:
	/* 0x1e83: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e86:
	/* 0x1e86: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1e88:
	/* 0x1e88: je     215a <trace_ret_vfs_writev_tail+0x215a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215a;
	}
x86_l_1e8e:
	/* 0x1e8e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e90:
	/* 0x1e90: cmp    dl,BYTE PTR [r14+rcx*1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e94:
	/* 0x1e94: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1e9a:
	/* 0x1e9a: movzx  edx,BYTE PTR [rax+rcx*1+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1e9f:
	/* 0x1e9f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ea1:
	/* 0x1ea1: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1ea7:
	/* 0x1ea7: cmp    dl,BYTE PTR [r14+rcx*1+0x1] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 1ULL);
x86_l_1eac:
	/* 0x1eac: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1eb2:
	/* 0x1eb2: movzx  edx,BYTE PTR [rax+rcx*1+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1eb7:
	/* 0x1eb7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1eb9:
	/* 0x1eb9: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1ebf:
	/* 0x1ebf: cmp    dl,BYTE PTR [r14+rcx*1+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 2ULL);
x86_l_1ec4:
	/* 0x1ec4: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1eca:
	/* 0x1eca: movzx  edx,BYTE PTR [rax+rcx*1+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1ecf:
	/* 0x1ecf: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ed1:
	/* 0x1ed1: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1ed7:
	/* 0x1ed7: cmp    dl,BYTE PTR [r14+rcx*1+0x3] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 3ULL);
x86_l_1edc:
	/* 0x1edc: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1ee2:
	/* 0x1ee2: movzx  edx,BYTE PTR [rax+rcx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1ee7:
	/* 0x1ee7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ee9:
	/* 0x1ee9: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1eef:
	/* 0x1eef: cmp    dl,BYTE PTR [r14+rcx*1+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 4ULL);
x86_l_1ef4:
	/* 0x1ef4: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1efa:
	/* 0x1efa: movzx  edx,BYTE PTR [rax+rcx*1+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1eff:
	/* 0x1eff: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f01:
	/* 0x1f01: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1f07:
	/* 0x1f07: cmp    dl,BYTE PTR [r14+rcx*1+0x5] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 5ULL);
x86_l_1f0c:
	/* 0x1f0c: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1f12:
	/* 0x1f12: movzx  edx,BYTE PTR [rax+rcx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1f17:
	/* 0x1f17: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f19:
	/* 0x1f19: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1f1f:
	/* 0x1f1f: cmp    dl,BYTE PTR [r14+rcx*1+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 6ULL);
x86_l_1f24:
	/* 0x1f24: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1f2a:
	/* 0x1f2a: movzx  edx,BYTE PTR [rax+rcx*1+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1f2f:
	/* 0x1f2f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f31:
	/* 0x1f31: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1f37:
	/* 0x1f37: cmp    dl,BYTE PTR [r14+rcx*1+0x7] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 7ULL);
x86_l_1f3c:
	/* 0x1f3c: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1f42:
	/* 0x1f42: movzx  edx,BYTE PTR [rax+rcx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1f47:
	/* 0x1f47: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f49:
	/* 0x1f49: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_1f4f:
	/* 0x1f4f: cmp    dl,BYTE PTR [r14+rcx*1+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 8ULL);
x86_l_1f54:
	/* 0x1f54: jne    2157 <trace_ret_vfs_writev_tail+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2157;
	}
x86_l_1f5a:
	/* 0x1f5a: cmp    ecx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 54ULL);
x86_l_1f5d:
	/* 0x1f5d: je     2151 <trace_ret_vfs_writev_tail+0x2151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2151;
	}
x86_l_1f63:
	/* 0x1f63: movzx  edx,BYTE PTR [rax+rcx*1+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 9ULL);
x86_l_1f68:
	/* 0x1f68: add    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 9ULL);
x86_l_1f6c:
	/* 0x1f6c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f6e:
	/* 0x1f6e: jne    1e90 <trace_ret_vfs_writev_tail+0x1e90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e90;
	}
x86_l_1f74:
	/* 0x1f74: jmp    216d <trace_ret_vfs_writev_tail+0x216d> */
	goto x86_l_216d;
x86_l_1f79:
	/* 0x1f79: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: jne    1b53 <trace_ret_vfs_writev_tail+0x1b53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6995ULL;
	}
x86_l_1f82:
	/* 0x1f82: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f87:
	/* 0x1f87: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_1f8c:
	/* 0x1f8c: je     1b53 <trace_ret_vfs_writev_tail+0x1b53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6995ULL;
	}
x86_l_1f92:
	/* 0x1f92: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f96:
	/* 0x1f96: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1faa:
	/* 0x1faa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fae:
	/* 0x1fae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb3:
	/* 0x1fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb5:
	/* 0x1fb5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fba:
	/* 0x1fba: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fce:
	/* 0x1fce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fd3:
	/* 0x1fd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd5:
	/* 0x1fd5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fda:
	/* 0x1fda: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fee:
	/* 0x1fee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ff3:
	/* 0x1ff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff5:
	/* 0x1ff5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ffa:
	/* 0x1ffa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ffe:
	/* 0x1ffe: jmp    2085 <trace_ret_vfs_writev_tail+0x2085> */
	goto x86_l_2085;
x86_l_2003:
	/* 0x2003: lea    rdi,[r12+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_200b:
	/* 0x200b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_200e:
	/* 0x200e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2012:
	/* 0x2012: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2017:
	/* 0x2017: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_201c:
	/* 0x201c: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2021:
	/* 0x2021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2023:
	/* 0x2023: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2026:
	/* 0x2026: jne    31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12711ULL;
	}
x86_l_202c:
	/* 0x202c: movzx  eax,WORD PTR [rbx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2030:
	/* 0x2030: mov    WORD PTR [rsp+0xb8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2038:
	/* 0x2038: mov    WORD PTR [r12+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_203e:
	/* 0x203e: jmp    c74 <trace_ret_vfs_writev_tail+0xc74> */
	return 3188ULL;
x86_l_2043:
	/* 0x2043: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2048:
	/* 0x2048: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_204e:
	/* 0x204e: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2051:
	/* 0x2051: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2053:
	/* 0x2053: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2058:
	/* 0x2058: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205a:
	/* 0x205a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_205d:
	/* 0x205d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2062:
	/* 0x2062: jl     1b58 <trace_ret_vfs_writev_tail+0x1b58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7000ULL;
	}
x86_l_2068:
	/* 0x2068: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_206c:
	/* 0x206c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2072:
	/* 0x2072: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2078:
	/* 0x2078: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_207b:
	/* 0x207b: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2080:
	/* 0x2080: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2085:
	/* 0x2085: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_208a:
	/* 0x208a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_208f:
	/* 0x208f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2094:
	/* 0x2094: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2099:
	/* 0x2099: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_209e:
	/* 0x209e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a0:
	/* 0x20a0: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20a5:
	/* 0x20a5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20aa:
	/* 0x20aa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_20ae:
	/* 0x20ae: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b3:
	/* 0x20b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20b8:
	/* 0x20b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20bd:
	/* 0x20bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c2:
	/* 0x20c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c4:
	/* 0x20c4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20c9:
	/* 0x20c9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20cc:
	/* 0x20cc: je     3337 <trace_ret_vfs_writev_tail+0x3337> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13111ULL;
	}
x86_l_20d2:
	/* 0x20d2: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20d7:
	/* 0x20d7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20da:
	/* 0x20da: je     3337 <trace_ret_vfs_writev_tail+0x3337> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13111ULL;
	}
x86_l_20e0:
	/* 0x20e0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20e4:
	/* 0x20e4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20e9:
	/* 0x20e9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_20ee:
	/* 0x20ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f3:
	/* 0x20f3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20f8:
	/* 0x20f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fa:
	/* 0x20fa: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20fe:
	/* 0x20fe: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2100:
	/* 0x2100: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2106:
	/* 0x2106: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2109:
	/* 0x2109: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_210b:
	/* 0x210b: jb     1deb <trace_ret_vfs_writev_tail+0x1deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1deb;
	}
x86_l_2111:
	/* 0x2111: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2116:
	/* 0x2116: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_211c:
	/* 0x211c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_211f:
	/* 0x211f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2121:
	/* 0x2121: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2126:
	/* 0x2126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2128:
	/* 0x2128: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_212b:
	/* 0x212b: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_2131:
	/* 0x2131: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2135:
	/* 0x2135: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_213b:
	/* 0x213b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2140:
	/* 0x2140: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2144:
	/* 0x2144: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2147:
	/* 0x2147: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_214c:
	/* 0x214c: jmp    33c1 <trace_ret_vfs_writev_tail+0x33c1> */
	return 13249ULL;
x86_l_2151:
	/* 0x2151: cmp    BYTE PTR [rax+0x3f],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_2155:
	/* 0x2155: je     216d <trace_ret_vfs_writev_tail+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216d;
	}
x86_l_2157:
	/* 0x2157: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_215a:
	/* 0x215a: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_215d:
	/* 0x215d: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2165:
	/* 0x2165: jne    31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12711ULL;
	}
x86_l_216b:
	/* 0x216b: jmp    2175 <trace_ret_vfs_writev_tail+0x2175> */
	goto x86_l_2175;
x86_l_216d:
	/* 0x216d: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2175:
	/* 0x2175: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_217e:
	/* 0x217e: mov    BYTE PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_2186:
	/* 0x2186: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_218d:
	/* 0x218d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2192:
	/* 0x2192: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2197:
	/* 0x2197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2199:
	/* 0x2199: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_219c:
	/* 0x219c: je     359f <trace_ret_vfs_writev_tail+0x359f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13727ULL;
	}
x86_l_21a2:
	/* 0x21a2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_21a5:
	/* 0x21a5: test   BYTE PTR [rax],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_21a8:
	/* 0x21a8: je     2354 <trace_ret_vfs_writev_tail+0x2354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2354;
	}
x86_l_21ae:
	/* 0x21ae: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21b2:
	/* 0x21b2: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21b7:
	/* 0x21b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21bc:
	/* 0x21bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21c1:
	/* 0x21c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21c6:
	/* 0x21c6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_21c9:
	/* 0x21c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cb:
	/* 0x21cb: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21d0:
	/* 0x21d0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d5:
	/* 0x21d5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_21da:
	/* 0x21da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21df:
	/* 0x21df: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21e4:
	/* 0x21e4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_21e9:
	/* 0x21e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21eb:
	/* 0x21eb: movzx  r15d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_21f1:
	/* 0x21f1: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f5:
	/* 0x21f5: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_21f7:
	/* 0x21f7: je     2325 <trace_ret_vfs_writev_tail+0x2325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2325;
	}
x86_l_21fd:
	/* 0x21fd: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2201:
	/* 0x2201: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2206:
	/* 0x2206: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_220b:
	/* 0x220b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2210:
	/* 0x2210: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2215:
	/* 0x2215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2217:
	/* 0x2217: movabs rax,0x6972775f65706970 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598266772934912368ULL);
x86_l_2221:
	/* 0x2221: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2226:
	/* 0x2226: mov    DWORD PTR [rsp+0x1f],0x657469 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 133150635113ULL);
x86_l_222e:
	/* 0x222e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2237:
	/* 0x2237: mov    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_223c:
	/* 0x223c: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2240:
	/* 0x2240: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2245:
	/* 0x2245: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_224a:
	/* 0x224a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_224f:
	/* 0x224f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2254:
	/* 0x2254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2256:
	/* 0x2256: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_225b:
	/* 0x225b: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_225f:
	/* 0x225f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2264:
	/* 0x2264: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2269:
	/* 0x2269: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_226e:
	/* 0x226e: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2273:
	/* 0x2273: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2277:
	/* 0x2277: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_227c:
	/* 0x227c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227e:
	/* 0x227e: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_228a:
	/* 0x228a: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_2296:
	/* 0x2296: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_22a2:
	/* 0x22a2: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_22ae:
	/* 0x22ae: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_22b7:
	/* 0x22b7: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_22c0:
	/* 0x22c0: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_22c9:
	/* 0x22c9: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_22d2:
	/* 0x22d2: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22d7:
	/* 0x22d7: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22dc:
	/* 0x22dc: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22e1:
	/* 0x22e1: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_22e6:
	/* 0x22e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_22eb:
	/* 0x22eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22ee:
	/* 0x22ee: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_22f3:
	/* 0x22f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f5:
	/* 0x22f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ksymbols_map)));
x86_l_22fc:
	/* 0x22fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2301:
	/* 0x2301: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2304:
	/* 0x2304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2306:
	/* 0x2306: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2309:
	/* 0x2309: je     2310 <trace_ret_vfs_writev_tail+0x2310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2310;
	}
x86_l_230b:
	/* 0x230b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230e:
	/* 0x230e: jmp    2312 <trace_ret_vfs_writev_tail+0x2312> */
	goto x86_l_2312;
x86_l_2310:
	/* 0x2310: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2312:
	/* 0x2312: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2315:
	/* 0x2315: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_231a:
	/* 0x231a: jne    2321 <trace_ret_vfs_writev_tail+0x2321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2321;
	}
x86_l_231c:
	/* 0x231c: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_231f:
	/* 0x231f: jne    2347 <trace_ret_vfs_writev_tail+0x2347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2347;
	}
x86_l_2321:
	/* 0x2321: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2325:
	/* 0x2325: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_2327:
	/* 0x2327: je     2335 <trace_ret_vfs_writev_tail+0x2335> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2335;
	}
x86_l_2329:
	/* 0x2329: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_232d:
	/* 0x232d: cmp    ecx,0x3fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16383ULL);
x86_l_2333:
	/* 0x2333: ja     2347 <trace_ret_vfs_writev_tail+0x2347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2347;
	}
x86_l_2335:
	/* 0x2335: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2337:
	/* 0x2337: je     24b2 <trace_ret_vfs_writev_tail+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9394ULL;
	}
x86_l_233d:
	/* 0x233d: test   r15w,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_16);
x86_l_2341:
	/* 0x2341: jns    24b2 <trace_ret_vfs_writev_tail+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9394ULL;
	}
x86_l_2347:
	/* 0x2347: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_234f:
	/* 0x234f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2354:
	/* 0x2354: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_235d:
	/* 0x235d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_type_filter)));
x86_l_2364:
	/* 0x2364: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2369:
	/* 0x2369: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 9070ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9075ULL: goto x86_l_2373;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	case 9088ULL: goto x86_l_2380;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9101ULL: goto x86_l_238d;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9207ULL: goto x86_l_23f7;
	case 9212ULL: goto x86_l_23fc;
	case 9215ULL: goto x86_l_23ff;
	case 9221ULL: goto x86_l_2405;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9256ULL: goto x86_l_2428;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9306ULL: goto x86_l_245a;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9330ULL: goto x86_l_2472;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9363ULL: goto x86_l_2493;
	case 9365ULL: goto x86_l_2495;
	case 9367ULL: goto x86_l_2497;
	case 9372ULL: goto x86_l_249c;
	case 9375ULL: goto x86_l_249f;
	case 9378ULL: goto x86_l_24a2;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9396ULL: goto x86_l_24b4;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9415ULL: goto x86_l_24c7;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9442ULL: goto x86_l_24e2;
	case 9448ULL: goto x86_l_24e8;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9472ULL: goto x86_l_2500;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9487ULL: goto x86_l_250f;
	case 9493ULL: goto x86_l_2515;
	case 9502ULL: goto x86_l_251e;
	case 9511ULL: goto x86_l_2527;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9529ULL: goto x86_l_2539;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9553ULL: goto x86_l_2551;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9572ULL: goto x86_l_2564;
	case 9581ULL: goto x86_l_256d;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9621ULL: goto x86_l_2595;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9644ULL: goto x86_l_25ac;
	case 9646ULL: goto x86_l_25ae;
	case 9650ULL: goto x86_l_25b2;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9690ULL: goto x86_l_25da;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9733ULL: goto x86_l_2605;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9763ULL: goto x86_l_2623;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9837ULL: goto x86_l_266d;
	case 9841ULL: goto x86_l_2671;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9868ULL: goto x86_l_268c;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9879ULL: goto x86_l_2697;
	case 9884ULL: goto x86_l_269c;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9939ULL: goto x86_l_26d3;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9947ULL: goto x86_l_26db;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9955ULL: goto x86_l_26e3;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9974ULL: goto x86_l_26f6;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10005ULL: goto x86_l_2715;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10031ULL: goto x86_l_272f;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10105ULL: goto x86_l_2779;
	case 10110ULL: goto x86_l_277e;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10129ULL: goto x86_l_2791;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10205ULL: goto x86_l_27dd;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10215ULL: goto x86_l_27e7;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10259ULL: goto x86_l_2813;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10288ULL: goto x86_l_2830;
	case 10291ULL: goto x86_l_2833;
	case 10296ULL: goto x86_l_2838;
	case 10298ULL: goto x86_l_283a;
	case 10301ULL: goto x86_l_283d;
	case 10307ULL: goto x86_l_2843;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10359ULL: goto x86_l_2877;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10375ULL: goto x86_l_2887;
	case 10384ULL: goto x86_l_2890;
	case 10387ULL: goto x86_l_2893;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10416ULL: goto x86_l_28b0;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10432ULL: goto x86_l_28c0;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10504ULL: goto x86_l_2908;
	case 10506ULL: goto x86_l_290a;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10556ULL: goto x86_l_293c;
	case 10561ULL: goto x86_l_2941;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10603ULL: goto x86_l_296b;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10619ULL: goto x86_l_297b;
	case 10625ULL: goto x86_l_2981;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10758ULL: goto x86_l_2a06;
	case 10761ULL: goto x86_l_2a09;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10777ULL: goto x86_l_2a19;
	case 10782ULL: goto x86_l_2a1e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_236e:
	/* 0x236e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2370:
	/* 0x2370: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2373:
	/* 0x2373: je     36c3 <trace_ret_vfs_writev_tail+0x36c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14019ULL;
	}
x86_l_2379:
	/* 0x2379: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_237c:
	/* 0x237c: test   BYTE PTR [rax+0x2],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934599ULL);
x86_l_2380:
	/* 0x2380: je     2515 <trace_ret_vfs_writev_tail+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2515;
	}
x86_l_2386:
	/* 0x2386: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_238b:
	/* 0x238b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238d:
	/* 0x238d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2390:
	/* 0x2390: je     24a4 <trace_ret_vfs_writev_tail+0x24a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a4;
	}
x86_l_2396:
	/* 0x2396: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2399:
	/* 0x2399: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_239d:
	/* 0x239d: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23a2:
	/* 0x23a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23a7:
	/* 0x23a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23ac:
	/* 0x23ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b1:
	/* 0x23b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b3:
	/* 0x23b3: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23b8:
	/* 0x23b8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_23bb:
	/* 0x23bb: je     24ab <trace_ret_vfs_writev_tail+0x24ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ab;
	}
x86_l_23c1:
	/* 0x23c1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c6:
	/* 0x23c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23cb:
	/* 0x23cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d0:
	/* 0x23d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d5:
	/* 0x23d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d7:
	/* 0x23d7: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23dc:
	/* 0x23dc: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23e1:
	/* 0x23e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23e6:
	/* 0x23e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23eb:
	/* 0x23eb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23f0:
	/* 0x23f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f5:
	/* 0x23f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f7:
	/* 0x23f7: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23fc:
	/* 0x23fc: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_23ff:
	/* 0x23ff: je     24da <trace_ret_vfs_writev_tail+0x24da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24da;
	}
x86_l_2405:
	/* 0x2405: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_240e:
	/* 0x240e: lea    rbp,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2413:
	/* 0x2413: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2418:
	/* 0x2418: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_241d:
	/* 0x241d: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2420:
	/* 0x2420: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2425:
	/* 0x2425: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2428:
	/* 0x2428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242a:
	/* 0x242a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_242c:
	/* 0x242c: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2431:
	/* 0x2431: cmp    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2436:
	/* 0x2436: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_2439:
	/* 0x2439: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2442:
	/* 0x2442: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2446:
	/* 0x2446: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_244b:
	/* 0x244b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2450:
	/* 0x2450: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2453:
	/* 0x2453: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2458:
	/* 0x2458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245a:
	/* 0x245a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_245c:
	/* 0x245c: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2461:
	/* 0x2461: cmp    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2466:
	/* 0x2466: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2469:
	/* 0x2469: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2472:
	/* 0x2472: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2476:
	/* 0x2476: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_247b:
	/* 0x247b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2480:
	/* 0x2480: lea    ebx,[rbx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_2483:
	/* 0x2483: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2486:
	/* 0x2486: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_248b:
	/* 0x248b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2490:
	/* 0x2490: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2493:
	/* 0x2493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2495:
	/* 0x2495: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2497:
	/* 0x2497: cmp    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_249c:
	/* 0x249c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_249f:
	/* 0x249f: lea    eax,[rbx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_24a2:
	/* 0x24a2: jmp    24df <trace_ret_vfs_writev_tail+0x24df> */
	goto x86_l_24df;
x86_l_24a4:
	/* 0x24a4: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_24a9:
	/* 0x24a9: jmp    24df <trace_ret_vfs_writev_tail+0x24df> */
	goto x86_l_24df;
x86_l_24ab:
	/* 0x24ab: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_24b0:
	/* 0x24b0: jmp    24df <trace_ret_vfs_writev_tail+0x24df> */
	goto x86_l_24df;
x86_l_24b2:
	/* 0x24b2: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_24b4:
	/* 0x24b4: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_24bc:
	/* 0x24bc: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c1:
	/* 0x24c1: jne    287e <trace_ret_vfs_writev_tail+0x287e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_287e;
	}
x86_l_24c7:
	/* 0x24c7: cmp    BYTE PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_24cf:
	/* 0x24cf: jne    2354 <trace_ret_vfs_writev_tail+0x2354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9044ULL;
	}
x86_l_24d5:
	/* 0x24d5: jmp    31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	return 12711ULL;
x86_l_24da:
	/* 0x24da: mov    eax,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967293ULL);
x86_l_24df:
	/* 0x24df: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e2:
	/* 0x24e2: test   ecx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_24e8:
	/* 0x24e8: je     24f1 <trace_ret_vfs_writev_tail+0x24f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f1;
	}
x86_l_24ea:
	/* 0x24ea: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_24ec:
	/* 0x24ec: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_24ef:
	/* 0x24ef: jne    2515 <trace_ret_vfs_writev_tail+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2515;
	}
x86_l_24f1:
	/* 0x24f1: test   ecx,0x20000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 131072ULL);
x86_l_24f7:
	/* 0x24f7: je     2500 <trace_ret_vfs_writev_tail+0x2500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2500;
	}
x86_l_24f9:
	/* 0x24f9: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_24fb:
	/* 0x24fb: and    edx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_24fe:
	/* 0x24fe: jne    2515 <trace_ret_vfs_writev_tail+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2515;
	}
x86_l_2500:
	/* 0x2500: test   ecx,0x40000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 262144ULL);
x86_l_2506:
	/* 0x2506: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_250c:
	/* 0x250c: and    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4ULL);
x86_l_250f:
	/* 0x250f: je     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12711ULL;
	}
x86_l_2515:
	/* 0x2515: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_251e:
	/* 0x251e: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2527:
	/* 0x2527: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2530:
	/* 0x2530: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2533:
	/* 0x2533: je     26c0 <trace_ret_vfs_writev_tail+0x26c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26c0;
	}
x86_l_2539:
	/* 0x2539: lea    r14,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_253d:
	/* 0x253d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2542:
	/* 0x2542: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2547:
	/* 0x2547: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_254c:
	/* 0x254c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2551:
	/* 0x2551: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2554:
	/* 0x2554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2556:
	/* 0x2556: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_255b:
	/* 0x255b: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2564:
	/* 0x2564: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_256d:
	/* 0x256d: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2571:
	/* 0x2571: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2576:
	/* 0x2576: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_257b:
	/* 0x257b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2580:
	/* 0x2580: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2585:
	/* 0x2585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2587:
	/* 0x2587: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_258c:
	/* 0x258c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2591:
	/* 0x2591: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2595:
	/* 0x2595: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_259a:
	/* 0x259a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_259f:
	/* 0x259f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25a4:
	/* 0x25a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25a9:
	/* 0x25a9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25ac:
	/* 0x25ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ae:
	/* 0x25ae: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25b2:
	/* 0x25b2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b7:
	/* 0x25b7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25bc:
	/* 0x25bc: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25c1:
	/* 0x25c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25c6:
	/* 0x25c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25cb:
	/* 0x25cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d0:
	/* 0x25d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d2:
	/* 0x25d2: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d7:
	/* 0x25d7: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_25da:
	/* 0x25da: js     2605 <trace_ret_vfs_writev_tail+0x2605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2605;
	}
x86_l_25dc:
	/* 0x25dc: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x25f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f7:
	/* 0x25f7: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_25fe:
	/* 0x25fe: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2603:
	/* 0x2603: jmp    2607 <trace_ret_vfs_writev_tail+0x2607> */
	goto x86_l_2607;
x86_l_2605:
	/* 0x2605: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2607:
	/* 0x2607: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_260c:
	/* 0x260c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2611:
	/* 0x2611: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2616:
	/* 0x2616: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_261b:
	/* 0x261b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2620:
	/* 0x2620: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2623:
	/* 0x2623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2625:
	/* 0x2625: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_262a:
	/* 0x262a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_262e:
	/* 0x262e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2633:
	/* 0x2633: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2638:
	/* 0x2638: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_263d:
	/* 0x263d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2642:
	/* 0x2642: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2646:
	/* 0x2646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_264b:
	/* 0x264b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264d:
	/* 0x264d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2652:
	/* 0x2652: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2657:
	/* 0x2657: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_265c:
	/* 0x265c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2661:
	/* 0x2661: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2666:
	/* 0x2666: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_266b:
	/* 0x266b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266d:
	/* 0x266d: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2671:
	/* 0x2671: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2675:
	/* 0x2675: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_267a:
	/* 0x267a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_267f:
	/* 0x267f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2684:
	/* 0x2684: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2689:
	/* 0x2689: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_268c:
	/* 0x268c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268e:
	/* 0x268e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2693:
	/* 0x2693: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2697:
	/* 0x2697: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_269c:
	/* 0x269c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26a1:
	/* 0x26a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a6:
	/* 0x26a6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ab:
	/* 0x26ab: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26af:
	/* 0x26af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26b4:
	/* 0x26b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b6:
	/* 0x26b6: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26bb:
	/* 0x26bb: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26c0:
	/* 0x26c0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_26c7:
	/* 0x26c7: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26cc:
	/* 0x26cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d1:
	/* 0x26d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d3:
	/* 0x26d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26d6:
	/* 0x26d6: je     26ee <trace_ret_vfs_writev_tail+0x26ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ee;
	}
x86_l_26d8:
	/* 0x26d8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_26db:
	/* 0x26db: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26df:
	/* 0x26df: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_26e1:
	/* 0x26e1: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_26e3:
	/* 0x26e3: je     2e5d <trace_ret_vfs_writev_tail+0x2e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11869ULL;
	}
x86_l_26e9:
	/* 0x26e9: jmp    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	return 11962ULL;
x86_l_26ee:
	/* 0x26ee: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_26f6:
	/* 0x26f6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_26fd:
	/* 0x26fd: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2702:
	/* 0x2702: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2707:
	/* 0x2707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2709:
	/* 0x2709: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_270c:
	/* 0x270c: je     2ec7 <trace_ret_vfs_writev_tail+0x2ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11975ULL;
	}
x86_l_2712:
	/* 0x2712: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2715:
	/* 0x2715: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2719:
	/* 0x2719: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_271e:
	/* 0x271e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2723:
	/* 0x2723: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2728:
	/* 0x2728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_272d:
	/* 0x272d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272f:
	/* 0x272f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2734:
	/* 0x2734: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2739:
	/* 0x2739: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_273e:
	/* 0x273e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2743:
	/* 0x2743: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2748:
	/* 0x2748: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_274d:
	/* 0x274d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2752:
	/* 0x2752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2754:
	/* 0x2754: test   BYTE PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215136ULL);
x86_l_2759:
	/* 0x2759: jne    285c <trace_ret_vfs_writev_tail+0x285c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_285c;
	}
x86_l_275f:
	/* 0x275f: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2763:
	/* 0x2763: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2768:
	/* 0x2768: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_276d:
	/* 0x276d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2772:
	/* 0x2772: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2777:
	/* 0x2777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2779:
	/* 0x2779: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277e:
	/* 0x277e: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_2782:
	/* 0x2782: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2787:
	/* 0x2787: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_278c:
	/* 0x278c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2791:
	/* 0x2791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2796:
	/* 0x2796: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_279b:
	/* 0x279b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27a0:
	/* 0x27a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a2:
	/* 0x27a2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27a7:
	/* 0x27a7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27ac:
	/* 0x27ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27b1:
	/* 0x27b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27b6:
	/* 0x27b6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_27b9:
	/* 0x27b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27bb:
	/* 0x27bb: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27c0:
	/* 0x27c0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27c5:
	/* 0x27c5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27c9:
	/* 0x27c9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ce:
	/* 0x27ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27d3:
	/* 0x27d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27d8:
	/* 0x27d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27dd:
	/* 0x27dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27df:
	/* 0x27df: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27e4:
	/* 0x27e4: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_27e7:
	/* 0x27e7: je     2968 <trace_ret_vfs_writev_tail+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2968;
	}
x86_l_27ed:
	/* 0x27ed: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27f2:
	/* 0x27f2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27f5:
	/* 0x27f5: je     2968 <trace_ret_vfs_writev_tail+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2968;
	}
x86_l_27fb:
	/* 0x27fb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27ff:
	/* 0x27ff: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2804:
	/* 0x2804: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2809:
	/* 0x2809: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_280e:
	/* 0x280e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2813:
	/* 0x2813: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2815:
	/* 0x2815: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2819:
	/* 0x2819: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_281e:
	/* 0x281e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2820:
	/* 0x2820: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2826:
	/* 0x2826: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2828:
	/* 0x2828: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_282a:
	/* 0x282a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2830:
	/* 0x2830: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2833:
	/* 0x2833: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2838:
	/* 0x2838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283a:
	/* 0x283a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_283d:
	/* 0x283d: jl     2ac8 <trace_ret_vfs_writev_tail+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10952ULL;
	}
x86_l_2843:
	/* 0x2843: mov    BYTE PTR [r14+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_284b:
	/* 0x284b: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2850:
	/* 0x2850: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2852:
	/* 0x2852: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2857:
	/* 0x2857: jmp    29f2 <trace_ret_vfs_writev_tail+0x29f2> */
	goto x86_l_29f2;
x86_l_285c:
	/* 0x285c: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2863:
	/* 0x2863: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2868:
	/* 0x2868: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_286d:
	/* 0x286d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2870:
	/* 0x2870: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2875:
	/* 0x2875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2877:
	/* 0x2877: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2879:
	/* 0x2879: jmp    2e30 <trace_ret_vfs_writev_tail+0x2e30> */
	return 11824ULL;
x86_l_287e:
	/* 0x287e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2887:
	/* 0x2887: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2890:
	/* 0x2890: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2893:
	/* 0x2893: je     2bcf <trace_ret_vfs_writev_tail+0x2bcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11215ULL;
	}
x86_l_2899:
	/* 0x2899: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_289e:
	/* 0x289e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28a3:
	/* 0x28a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28a8:
	/* 0x28a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ad:
	/* 0x28ad: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_28b0:
	/* 0x28b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b2:
	/* 0x28b2: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28b7:
	/* 0x28b7: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_28c0:
	/* 0x28c0: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_28c9:
	/* 0x28c9: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28cd:
	/* 0x28cd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28d2:
	/* 0x28d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28d7:
	/* 0x28d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28dc:
	/* 0x28dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28e1:
	/* 0x28e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e3:
	/* 0x28e3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28e8:
	/* 0x28e8: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28ed:
	/* 0x28ed: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_28f1:
	/* 0x28f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28f6:
	/* 0x28f6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28fb:
	/* 0x28fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2900:
	/* 0x2900: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2905:
	/* 0x2905: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2908:
	/* 0x2908: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290a:
	/* 0x290a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_290e:
	/* 0x290e: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2913:
	/* 0x2913: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2918:
	/* 0x2918: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_291d:
	/* 0x291d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2922:
	/* 0x2922: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2927:
	/* 0x2927: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_292c:
	/* 0x292c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292e:
	/* 0x292e: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2933:
	/* 0x2933: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2936:
	/* 0x2936: js     2b14 <trace_ret_vfs_writev_tail+0x2b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11028ULL;
	}
x86_l_293c:
	/* 0x293c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2941:
	/* 0x2941: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x2957: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_295e:
	/* 0x295e: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2963:
	/* 0x2963: jmp    2b16 <trace_ret_vfs_writev_tail+0x2b16> */
	return 11030ULL;
x86_l_2968:
	/* 0x2968: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_296b:
	/* 0x296b: jne    2ac8 <trace_ret_vfs_writev_tail+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10952ULL;
	}
x86_l_2971:
	/* 0x2971: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2976:
	/* 0x2976: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_297b:
	/* 0x297b: je     2ac8 <trace_ret_vfs_writev_tail+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10952ULL;
	}
x86_l_2981:
	/* 0x2981: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2985:
	/* 0x2985: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_298a:
	/* 0x298a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_298f:
	/* 0x298f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2994:
	/* 0x2994: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2999:
	/* 0x2999: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_299d:
	/* 0x299d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29a2:
	/* 0x29a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a4:
	/* 0x29a4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a9:
	/* 0x29a9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ae:
	/* 0x29ae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b3:
	/* 0x29b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b8:
	/* 0x29b8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29bd:
	/* 0x29bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c2:
	/* 0x29c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c4:
	/* 0x29c4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c9:
	/* 0x29c9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29ce:
	/* 0x29ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29d3:
	/* 0x29d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29d8:
	/* 0x29d8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29dd:
	/* 0x29dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e2:
	/* 0x29e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e4:
	/* 0x29e4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29e9:
	/* 0x29e9: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29ed:
	/* 0x29ed: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_29f2:
	/* 0x29f2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29f7:
	/* 0x29f7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29fc:
	/* 0x29fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a01:
	/* 0x2a01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a06:
	/* 0x2a06: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2a09:
	/* 0x2a09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0b:
	/* 0x2a0b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a10:
	/* 0x2a10: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a15:
	/* 0x2a15: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a19:
	/* 0x2a19: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 10787ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10804ULL: goto x86_l_2a34;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10817ULL: goto x86_l_2a41;
	case 10819ULL: goto x86_l_2a43;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10838ULL: goto x86_l_2a56;
	case 10843ULL: goto x86_l_2a5b;
	case 10845ULL: goto x86_l_2a5d;
	case 10849ULL: goto x86_l_2a61;
	case 10851ULL: goto x86_l_2a63;
	case 10857ULL: goto x86_l_2a69;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10883ULL: goto x86_l_2a83;
	case 10886ULL: goto x86_l_2a86;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10895ULL: goto x86_l_2a8f;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10903ULL: goto x86_l_2a97;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10916ULL: goto x86_l_2aa4;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10929ULL: goto x86_l_2ab1;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11136ULL: goto x86_l_2b80;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11160ULL: goto x86_l_2b98;
	case 11163ULL: goto x86_l_2b9b;
	case 11165ULL: goto x86_l_2b9d;
	case 11170ULL: goto x86_l_2ba2;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11224ULL: goto x86_l_2bd8;
	case 11233ULL: goto x86_l_2be1;
	case 11235ULL: goto x86_l_2be3;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11254ULL: goto x86_l_2bf6;
	case 11257ULL: goto x86_l_2bf9;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11272ULL: goto x86_l_2c08;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11294ULL: goto x86_l_2c1e;
	case 11303ULL: goto x86_l_2c27;
	case 11312ULL: goto x86_l_2c30;
	case 11321ULL: goto x86_l_2c39;
	case 11330ULL: goto x86_l_2c42;
	case 11339ULL: goto x86_l_2c4b;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11438ULL: goto x86_l_2cae;
	case 11446ULL: goto x86_l_2cb6;
	case 11453ULL: goto x86_l_2cbd;
	case 11455ULL: goto x86_l_2cbf;
	case 11460ULL: goto x86_l_2cc4;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11475ULL: goto x86_l_2cd3;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11572ULL: goto x86_l_2d34;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11645ULL: goto x86_l_2d7d;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11704ULL: goto x86_l_2db8;
	case 11710ULL: goto x86_l_2dbe;
	case 11715ULL: goto x86_l_2dc3;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11750ULL: goto x86_l_2de6;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11762ULL: goto x86_l_2df2;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11781ULL: goto x86_l_2e05;
	case 11786ULL: goto x86_l_2e0a;
	case 11791ULL: goto x86_l_2e0f;
	case 11799ULL: goto x86_l_2e17;
	case 11805ULL: goto x86_l_2e1d;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11824ULL: goto x86_l_2e30;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11840ULL: goto x86_l_2e40;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11855ULL: goto x86_l_2e4f;
	case 11857ULL: goto x86_l_2e51;
	case 11859ULL: goto x86_l_2e53;
	case 11863ULL: goto x86_l_2e57;
	case 11865ULL: goto x86_l_2e59;
	case 11867ULL: goto x86_l_2e5b;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11920ULL: goto x86_l_2e90;
	case 11922ULL: goto x86_l_2e92;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11931ULL: goto x86_l_2e9b;
	case 11933ULL: goto x86_l_2e9d;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11989ULL: goto x86_l_2ed5;
	case 12001ULL: goto x86_l_2ee1;
	case 12013ULL: goto x86_l_2eed;
	case 12025ULL: goto x86_l_2ef9;
	case 12034ULL: goto x86_l_2f02;
	case 12043ULL: goto x86_l_2f0b;
	case 12052ULL: goto x86_l_2f14;
	case 12061ULL: goto x86_l_2f1d;
	case 12065ULL: goto x86_l_2f21;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12105ULL: goto x86_l_2f49;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12125ULL: goto x86_l_2f5d;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12159ULL: goto x86_l_2f7f;
	case 12164ULL: goto x86_l_2f84;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12246ULL: goto x86_l_2fd6;
	case 12251ULL: goto x86_l_2fdb;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12329ULL: goto x86_l_3029;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12366ULL: goto x86_l_304e;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12404ULL: goto x86_l_3074;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12419ULL: goto x86_l_3083;
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12488ULL: goto x86_l_30c8;
	case 12493ULL: goto x86_l_30cd;
	case 12501ULL: goto x86_l_30d5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a23:
	/* 0x2a23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a28:
	/* 0x2a28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a2d:
	/* 0x2a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2f:
	/* 0x2a2f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a34:
	/* 0x2a34: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a37:
	/* 0x2a37: je     2aae <trace_ret_vfs_writev_tail+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aae;
	}
x86_l_2a39:
	/* 0x2a39: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a3e:
	/* 0x2a3e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a41:
	/* 0x2a41: je     2aae <trace_ret_vfs_writev_tail+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aae;
	}
x86_l_2a43:
	/* 0x2a43: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a47:
	/* 0x2a47: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a4c:
	/* 0x2a4c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a51:
	/* 0x2a51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a56:
	/* 0x2a56: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a5b:
	/* 0x2a5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5d:
	/* 0x2a5d: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a61:
	/* 0x2a61: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a63:
	/* 0x2a63: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a69:
	/* 0x2a69: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2a6b:
	/* 0x2a6b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a6d:
	/* 0x2a6d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a72:
	/* 0x2a72: jb     2e01 <trace_ret_vfs_writev_tail+0x2e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e01;
	}
x86_l_2a78:
	/* 0x2a78: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a7d:
	/* 0x2a7d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a83:
	/* 0x2a83: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a86:
	/* 0x2a86: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2a88:
	/* 0x2a88: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a8d:
	/* 0x2a8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8f:
	/* 0x2a8f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a92:
	/* 0x2a92: jl     2abc <trace_ret_vfs_writev_tail+0x2abc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2abc;
	}
x86_l_2a94:
	/* 0x2a94: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a97:
	/* 0x2a97: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2aa2:
	/* 0x2aa2: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2aa4:
	/* 0x2aa4: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2aa9:
	/* 0x2aa9: jmp    2d73 <trace_ret_vfs_writev_tail+0x2d73> */
	goto x86_l_2d73;
x86_l_2aae:
	/* 0x2aae: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ab1:
	/* 0x2ab1: je     2cf2 <trace_ret_vfs_writev_tail+0x2cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf2;
	}
x86_l_2ab7:
	/* 0x2ab7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abc:
	/* 0x2abc: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2ac2:
	/* 0x2ac2: jne    2e01 <trace_ret_vfs_writev_tail+0x2e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e01;
	}
x86_l_2ac8:
	/* 0x2ac8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2acd:
	/* 0x2acd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ad1:
	/* 0x2ad1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2adb:
	/* 0x2adb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ae5:
	/* 0x2ae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae7:
	/* 0x2ae7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aec:
	/* 0x2aec: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2af1:
	/* 0x2af1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2af6:
	/* 0x2af6: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2af9:
	/* 0x2af9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2afe:
	/* 0x2afe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b00:
	/* 0x2b00: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b02:
	/* 0x2b02: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b0f:
	/* 0x2b0f: jmp    2e30 <trace_ret_vfs_writev_tail+0x2e30> */
	goto x86_l_2e30;
x86_l_2b14:
	/* 0x2b14: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b16:
	/* 0x2b16: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b1b:
	/* 0x2b1b: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b20:
	/* 0x2b20: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b25:
	/* 0x2b25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b2a:
	/* 0x2b2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2b32:
	/* 0x2b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b34:
	/* 0x2b34: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b39:
	/* 0x2b39: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b3d:
	/* 0x2b3d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b42:
	/* 0x2b42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b47:
	/* 0x2b47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4c:
	/* 0x2b4c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b51:
	/* 0x2b51: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b55:
	/* 0x2b55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b5a:
	/* 0x2b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5c:
	/* 0x2b5c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b61:
	/* 0x2b61: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b66:
	/* 0x2b66: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b70:
	/* 0x2b70: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b75:
	/* 0x2b75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b7a:
	/* 0x2b7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7c:
	/* 0x2b7c: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b80:
	/* 0x2b80: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b84:
	/* 0x2b84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b89:
	/* 0x2b89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b93:
	/* 0x2b93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b98:
	/* 0x2b98: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2b9b:
	/* 0x2b9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9d:
	/* 0x2b9d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ba2:
	/* 0x2ba2: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ba6:
	/* 0x2ba6: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2bab:
	/* 0x2bab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bba:
	/* 0x2bba: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc3:
	/* 0x2bc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc5:
	/* 0x2bc5: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2bca:
	/* 0x2bca: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bcf:
	/* 0x2bcf: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2bd8:
	/* 0x2bd8: cmp    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2be1:
	/* 0x2be1: je     2c15 <trace_ret_vfs_writev_tail+0x2c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c15;
	}
x86_l_2be3:
	/* 0x2be3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2bea:
	/* 0x2bea: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bef:
	/* 0x2bef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf4:
	/* 0x2bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf6:
	/* 0x2bf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf9:
	/* 0x2bf9: je     24c7 <trace_ret_vfs_writev_tail+0x24c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9415ULL;
	}
x86_l_2bff:
	/* 0x2bff: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c02:
	/* 0x2c02: je     24c7 <trace_ret_vfs_writev_tail+0x24c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9415ULL;
	}
x86_l_2c08:
	/* 0x2c08: mov    BYTE PTR [rsp+0xc0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_2c10:
	/* 0x2c10: jmp    24c7 <trace_ret_vfs_writev_tail+0x24c7> */
	return 9415ULL;
x86_l_2c15:
	/* 0x2c15: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2c27:
	/* 0x2c27: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2c30:
	/* 0x2c30: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2c39:
	/* 0x2c39: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2c42:
	/* 0x2c42: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2c4b:
	/* 0x2c4b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c50:
	/* 0x2c50: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2c55:
	/* 0x2c55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c5a:
	/* 0x2c5a: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2c62:
	/* 0x2c62: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c67:
	/* 0x2c67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c69:
	/* 0x2c69: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c71:
	/* 0x2c71: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_2c74:
	/* 0x2c74: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_2c79:
	/* 0x2c79: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2c7c:
	/* 0x2c7c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c81:
	/* 0x2c81: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c86:
	/* 0x2c86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c90:
	/* 0x2c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c92:
	/* 0x2c92: cmp    BYTE PTR [rsp+0x60],0x7f */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860543ULL);
x86_l_2c97:
	/* 0x2c97: jne    2cda <trace_ret_vfs_writev_tail+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cda;
	}
x86_l_2c99:
	/* 0x2c99: cmp    BYTE PTR [rsp+0x61],0x45 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 416611827781ULL);
x86_l_2c9e:
	/* 0x2c9e: jne    2cda <trace_ret_vfs_writev_tail+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cda;
	}
x86_l_2ca0:
	/* 0x2ca0: cmp    BYTE PTR [rsp+0x62],0x4c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 420906795084ULL);
x86_l_2ca5:
	/* 0x2ca5: jne    2cda <trace_ret_vfs_writev_tail+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cda;
	}
x86_l_2ca7:
	/* 0x2ca7: cmp    BYTE PTR [rsp+0x63],0x46 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762374ULL);
x86_l_2cac:
	/* 0x2cac: jne    2cda <trace_ret_vfs_writev_tail+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cda;
	}
x86_l_2cae:
	/* 0x2cae: mov    BYTE PTR [rsp+0xc0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2cbd:
	/* 0x2cbd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cbf:
	/* 0x2cbf: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cc4:
	/* 0x2cc4: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd1:
	/* 0x2cd1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd3:
	/* 0x2cd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd5:
	/* 0x2cd5: jmp    24c7 <trace_ret_vfs_writev_tail+0x24c7> */
	return 9415ULL;
x86_l_2cda:
	/* 0x2cda: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&elf_files_map)));
x86_l_2ce1:
	/* 0x2ce1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ce6:
	/* 0x2ce6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ceb:
	/* 0x2ceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ced:
	/* 0x2ced: jmp    24c7 <trace_ret_vfs_writev_tail+0x24c7> */
	return 9415ULL;
x86_l_2cf2:
	/* 0x2cf2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf7:
	/* 0x2cf7: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d01:
	/* 0x2d01: je     2abc <trace_ret_vfs_writev_tail+0x2abc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2abc;
	}
x86_l_2d07:
	/* 0x2d07: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d0b:
	/* 0x2d0b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d10:
	/* 0x2d10: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d15:
	/* 0x2d15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1f:
	/* 0x2d1f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d23:
	/* 0x2d23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d28:
	/* 0x2d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2a:
	/* 0x2d2a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d2f:
	/* 0x2d2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d34:
	/* 0x2d34: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d39:
	/* 0x2d39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d43:
	/* 0x2d43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d48:
	/* 0x2d48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4a:
	/* 0x2d4a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d4f:
	/* 0x2d4f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d54:
	/* 0x2d54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d59:
	/* 0x2d59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d63:
	/* 0x2d63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d68:
	/* 0x2d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6a:
	/* 0x2d6a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6f:
	/* 0x2d6f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d73:
	/* 0x2d73: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d78:
	/* 0x2d78: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d7d:
	/* 0x2d7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d82:
	/* 0x2d82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d87:
	/* 0x2d87: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d8a:
	/* 0x2d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8c:
	/* 0x2d8c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d91:
	/* 0x2d91: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d96:
	/* 0x2d96: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d9a:
	/* 0x2d9a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2da4:
	/* 0x2da4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2da9:
	/* 0x2da9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dae:
	/* 0x2dae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db0:
	/* 0x2db0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2db5:
	/* 0x2db5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2db8:
	/* 0x2db8: je     31b8 <trace_ret_vfs_writev_tail+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_2dbe:
	/* 0x2dbe: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dc3:
	/* 0x2dc3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dc6:
	/* 0x2dc6: je     31b8 <trace_ret_vfs_writev_tail+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_2dcc:
	/* 0x2dcc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dd0:
	/* 0x2dd0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2dda:
	/* 0x2dda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2de4:
	/* 0x2de4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de6:
	/* 0x2de6: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2dea:
	/* 0x2dea: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dec:
	/* 0x2dec: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2df2:
	/* 0x2df2: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2df4:
	/* 0x2df4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2df6:
	/* 0x2df6: jae    323f <trace_ret_vfs_writev_tail+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12863ULL;
	}
x86_l_2dfc:
	/* 0x2dfc: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e01:
	/* 0x2e01: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e03:
	/* 0x2e03: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2e05:
	/* 0x2e05: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e0a:
	/* 0x2e0a: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2e0f:
	/* 0x2e0f: mov    BYTE PTR [r14+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_2e17:
	/* 0x2e17: cmp    ebx,0x7000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 28672ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e25:
	/* 0x2e25: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e2a:
	/* 0x2e2a: jae    2ec7 <trace_ret_vfs_writev_tail+0x2ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ec7;
	}
x86_l_2e30:
	/* 0x2e30: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e36:
	/* 0x2e36: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e39:
	/* 0x2e39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_2e40:
	/* 0x2e40: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e42:
	/* 0x2e42: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e47:
	/* 0x2e47: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e4c:
	/* 0x2e4c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e4f:
	/* 0x2e4f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e51:
	/* 0x2e51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e53:
	/* 0x2e53: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e57:
	/* 0x2e57: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_2e59:
	/* 0x2e59: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_2e5b:
	/* 0x2e5b: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e5d:
	/* 0x2e5d: movzx  eax,BYTE PTR [r14+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_2e62:
	/* 0x2e62: mov    cl,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 100ULL);
x86_l_2e64:
	/* 0x2e64: cmp    al,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 100ULL);
x86_l_2e66:
	/* 0x2e66: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e68:
	/* 0x2e68: movzx  eax,BYTE PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2e6d:
	/* 0x2e6d: mov    cl,0x65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 101ULL);
x86_l_2e6f:
	/* 0x2e6f: cmp    al,0x65 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 101ULL);
x86_l_2e71:
	/* 0x2e71: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e73:
	/* 0x2e73: movzx  eax,BYTE PTR [r14+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_2e78:
	/* 0x2e78: mov    cl,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 118ULL);
x86_l_2e7a:
	/* 0x2e7a: cmp    al,0x76 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 118ULL);
x86_l_2e7c:
	/* 0x2e7c: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e7e:
	/* 0x2e7e: movzx  eax,BYTE PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_2e83:
	/* 0x2e83: mov    cl,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 47ULL);
x86_l_2e85:
	/* 0x2e85: cmp    al,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 47ULL);
x86_l_2e87:
	/* 0x2e87: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e89:
	/* 0x2e89: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    cl,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 110ULL);
x86_l_2e90:
	/* 0x2e90: cmp    al,0x6e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 110ULL);
x86_l_2e92:
	/* 0x2e92: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e94:
	/* 0x2e94: movzx  eax,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e99:
	/* 0x2e99: mov    cl,0x75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 117ULL);
x86_l_2e9b:
	/* 0x2e9b: cmp    al,0x75 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 117ULL);
x86_l_2e9d:
	/* 0x2e9d: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2e9f:
	/* 0x2e9f: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    cl,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 108ULL);
x86_l_2ea6:
	/* 0x2ea6: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_2ea8:
	/* 0x2ea8: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2eaa:
	/* 0x2eaa: movzx  eax,BYTE PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2eaf:
	/* 0x2eaf: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_2eb1:
	/* 0x2eb1: jne    2eba <trace_ret_vfs_writev_tail+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eba;
	}
x86_l_2eb3:
	/* 0x2eb3: movzx  eax,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2eb8:
	/* 0x2eb8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eba:
	/* 0x2eba: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ebc:
	/* 0x2ebc: cmp    cl,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_2ebe:
	/* 0x2ebe: jne    2ec9 <trace_ret_vfs_writev_tail+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec9;
	}
x86_l_2ec0:
	/* 0x2ec0: mov    ebx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ec5:
	/* 0x2ec5: jmp    2ec9 <trace_ret_vfs_writev_tail+0x2ec9> */
	goto x86_l_2ec9;
x86_l_2ec7:
	/* 0x2ec7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ec9:
	/* 0x2ec9: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_2ee1:
	/* 0x2ee1: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2eed:
	/* 0x2eed: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2f02:
	/* 0x2f02: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2f14:
	/* 0x2f14: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2f1d:
	/* 0x2f1d: mov    r14,QWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f21:
	/* 0x2f21: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f26:
	/* 0x2f26: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f30:
	/* 0x2f30: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2f38:
	/* 0x2f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f3d:
	/* 0x2f3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3f:
	/* 0x2f3f: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f44:
	/* 0x2f44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f47:
	/* 0x2f47: je     2f51 <trace_ret_vfs_writev_tail+0x2f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f51;
	}
x86_l_2f49:
	/* 0x2f49: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f4c:
	/* 0x2f4c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f51:
	/* 0x2f51: mov    BYTE PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_2f56:
	/* 0x2f56: mov    DWORD PTR [rsp+0xc0],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2f5d:
	/* 0x2f5d: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2f61:
	/* 0x2f61: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f66:
	/* 0x2f66: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f6b:
	/* 0x2f6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f70:
	/* 0x2f70: lea    r14,[rsp+0x61] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2f75:
	/* 0x2f75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2f7d:
	/* 0x2f7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7f:
	/* 0x2f7f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f84:
	/* 0x2f84: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f88:
	/* 0x2f88: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f8d:
	/* 0x2f8d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f92:
	/* 0x2f92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f97:
	/* 0x2f97: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f9c:
	/* 0x2f9c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fa0:
	/* 0x2fa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa5:
	/* 0x2fa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa7:
	/* 0x2fa7: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fac:
	/* 0x2fac: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb1:
	/* 0x2fb1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2fb6:
	/* 0x2fb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fbb:
	/* 0x2fbb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fc5:
	/* 0x2fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc7:
	/* 0x2fc7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fd1:
	/* 0x2fd1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fd6:
	/* 0x2fd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fdb:
	/* 0x2fdb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2fde:
	/* 0x2fde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe0:
	/* 0x2fe0: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fe5:
	/* 0x2fe5: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fe9:
	/* 0x2fe9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fee:
	/* 0x2fee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ff3:
	/* 0x2ff3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ff8:
	/* 0x2ff8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ffd:
	/* 0x2ffd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3001:
	/* 0x3001: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3006:
	/* 0x3006: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3008:
	/* 0x3008: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_300d:
	/* 0x300d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3012:
	/* 0x3012: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3017:
	/* 0x3017: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_301c:
	/* 0x301c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3021:
	/* 0x3021: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3026:
	/* 0x3026: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3029:
	/* 0x3029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302b:
	/* 0x302b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3030:
	/* 0x3030: lea    rdi,[rsp+0xc6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_3038:
	/* 0x3038: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_303d:
	/* 0x303d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3042:
	/* 0x3042: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3047:
	/* 0x3047: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_304c:
	/* 0x304c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_304e:
	/* 0x304e: movzx  eax,WORD PTR [rsp+0xc6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 198ULL);
x86_l_3056:
	/* 0x3056: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_305b:
	/* 0x305b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3060:
	/* 0x3060: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3065:
	/* 0x3065: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_306a:
	/* 0x306a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_306d:
	/* 0x306d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3072:
	/* 0x3072: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3074:
	/* 0x3074: lea    rdi,[rsp+0x65] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 101ULL);
x86_l_3079:
	/* 0x3079: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_307e:
	/* 0x307e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3083:
	/* 0x3083: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3088:
	/* 0x3088: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_308d:
	/* 0x308d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_308f:
	/* 0x308f: lea    rdi,[rsp+0x6d] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 109ULL);
x86_l_3094:
	/* 0x3094: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0x30a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30aa:
	/* 0x30aa: lea    rdi,[rsp+0x71] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 113ULL);
x86_l_30af:
	/* 0x30af: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_30b7:
	/* 0x30b7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30bc:
	/* 0x30bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c1:
	/* 0x30c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30c6:
	/* 0x30c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c8:
	/* 0x30c8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30cd:
	/* 0x30cd: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_30d5:
	/* 0x30d5: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
	return 12509ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12509ULL: goto x86_l_30dd;
	case 12517ULL: goto x86_l_30e5;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12535ULL: goto x86_l_30f7;
	case 12537ULL: goto x86_l_30f9;
	case 12545ULL: goto x86_l_3101;
	case 12552ULL: goto x86_l_3108;
	case 12560ULL: goto x86_l_3110;
	case 12565ULL: goto x86_l_3115;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12583ULL: goto x86_l_3127;
	case 12588ULL: goto x86_l_312c;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12603ULL: goto x86_l_313b;
	case 12607ULL: goto x86_l_313f;
	case 12614ULL: goto x86_l_3146;
	case 12623ULL: goto x86_l_314f;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12635ULL: goto x86_l_315b;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12666ULL: goto x86_l_317a;
	case 12670ULL: goto x86_l_317e;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12684ULL: goto x86_l_318c;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12711ULL: goto x86_l_31a7;
	case 12713ULL: goto x86_l_31a9;
	case 12720ULL: goto x86_l_31b0;
	case 12722ULL: goto x86_l_31b2;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12731ULL: goto x86_l_31bb;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12753ULL: goto x86_l_31d1;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12808ULL: goto x86_l_3208;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12840ULL: goto x86_l_3228;
	case 12845ULL: goto x86_l_322d;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12861ULL: goto x86_l_323d;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12874ULL: goto x86_l_324a;
	case 12877ULL: goto x86_l_324d;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12886ULL: goto x86_l_3256;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12898ULL: goto x86_l_3262;
	case 12904ULL: goto x86_l_3268;
	case 12909ULL: goto x86_l_326d;
	case 12911ULL: goto x86_l_326f;
	case 12916ULL: goto x86_l_3274;
	case 12921ULL: goto x86_l_3279;
	case 12926ULL: goto x86_l_327e;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12939ULL: goto x86_l_328b;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12965ULL: goto x86_l_32a5;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12977ULL: goto x86_l_32b1;
	case 12982ULL: goto x86_l_32b6;
	case 12985ULL: goto x86_l_32b9;
	case 12991ULL: goto x86_l_32bf;
	case 12996ULL: goto x86_l_32c4;
	case 12999ULL: goto x86_l_32c7;
	case 13005ULL: goto x86_l_32cd;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13029ULL: goto x86_l_32e5;
	case 13031ULL: goto x86_l_32e7;
	case 13035ULL: goto x86_l_32eb;
	case 13037ULL: goto x86_l_32ed;
	case 13043ULL: goto x86_l_32f3;
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
	case 13088ULL: goto x86_l_3320;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13114ULL: goto x86_l_333a;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13136ULL: goto x86_l_3350;
	case 13140ULL: goto x86_l_3354;
	case 13145ULL: goto x86_l_3359;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13160ULL: goto x86_l_3368;
	case 13164ULL: goto x86_l_336c;
	case 13169ULL: goto x86_l_3371;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13201ULL: goto x86_l_3391;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13218ULL: goto x86_l_33a2;
	case 13223ULL: goto x86_l_33a7;
	case 13228ULL: goto x86_l_33ac;
	case 13233ULL: goto x86_l_33b1;
	case 13235ULL: goto x86_l_33b3;
	case 13240ULL: goto x86_l_33b8;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13286ULL: goto x86_l_33e6;
	case 13290ULL: goto x86_l_33ea;
	case 13295ULL: goto x86_l_33ef;
	case 13300ULL: goto x86_l_33f4;
	case 13305ULL: goto x86_l_33f9;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13317ULL: goto x86_l_3405;
	case 13320ULL: goto x86_l_3408;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13334ULL: goto x86_l_3416;
	case 13340ULL: goto x86_l_341c;
	case 13344ULL: goto x86_l_3420;
	case 13349ULL: goto x86_l_3425;
	case 13354ULL: goto x86_l_342a;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13366ULL: goto x86_l_3436;
	case 13370ULL: goto x86_l_343a;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13381ULL: goto x86_l_3445;
	case 13383ULL: goto x86_l_3447;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13399ULL: goto x86_l_3457;
	case 13402ULL: goto x86_l_345a;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13424ULL: goto x86_l_3470;
	case 13428ULL: goto x86_l_3474;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13452ULL: goto x86_l_348c;
	case 13457ULL: goto x86_l_3491;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13469ULL: goto x86_l_349d;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13523ULL: goto x86_l_34d3;
	case 13528ULL: goto x86_l_34d8;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13542ULL: goto x86_l_34e6;
	case 13547ULL: goto x86_l_34eb;
	case 13552ULL: goto x86_l_34f0;
	case 13555ULL: goto x86_l_34f3;
	case 13557ULL: goto x86_l_34f5;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13571ULL: goto x86_l_3503;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13593ULL: goto x86_l_3519;
	case 13598ULL: goto x86_l_351e;
	case 13601ULL: goto x86_l_3521;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13615ULL: goto x86_l_352f;
	case 13621ULL: goto x86_l_3535;
	case 13625ULL: goto x86_l_3539;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13640ULL: goto x86_l_3548;
	case 13645ULL: goto x86_l_354d;
	case 13647ULL: goto x86_l_354f;
	case 13651ULL: goto x86_l_3553;
	case 13653ULL: goto x86_l_3555;
	case 13659ULL: goto x86_l_355b;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13680ULL: goto x86_l_3570;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13692ULL: goto x86_l_357c;
	case 13695ULL: goto x86_l_357f;
	case 13701ULL: goto x86_l_3585;
	case 13704ULL: goto x86_l_3588;
	case 13710ULL: goto x86_l_358e;
	case 13715ULL: goto x86_l_3593;
	case 13717ULL: goto x86_l_3595;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13730ULL: goto x86_l_35a2;
	case 13736ULL: goto x86_l_35a8;
	case 13744ULL: goto x86_l_35b0;
	case 13751ULL: goto x86_l_35b7;
	case 13756ULL: goto x86_l_35bc;
	case 13761ULL: goto x86_l_35c1;
	case 13763ULL: goto x86_l_35c3;
	case 13766ULL: goto x86_l_35c6;
	case 13772ULL: goto x86_l_35cc;
	case 13775ULL: goto x86_l_35cf;
	case 13785ULL: goto x86_l_35d9;
	case 13788ULL: goto x86_l_35dc;
	case 13792ULL: goto x86_l_35e0;
	case 13800ULL: goto x86_l_35e8;
	case 13805ULL: goto x86_l_35ed;
	case 13807ULL: goto x86_l_35ef;
	case 13811ULL: goto x86_l_35f3;
	case 13819ULL: goto x86_l_35fb;
	case 13822ULL: goto x86_l_35fe;
	case 13826ULL: goto x86_l_3602;
	case 13833ULL: goto x86_l_3609;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13857ULL: goto x86_l_3621;
	case 13866ULL: goto x86_l_362a;
	case 13874ULL: goto x86_l_3632;
	case 13879ULL: goto x86_l_3637;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13901ULL: goto x86_l_364d;
	case 13903ULL: goto x86_l_364f;
	case 13906ULL: goto x86_l_3652;
	case 13912ULL: goto x86_l_3658;
	case 13915ULL: goto x86_l_365b;
	case 13919ULL: goto x86_l_365f;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13930ULL: goto x86_l_366a;
	case 13933ULL: goto x86_l_366d;
	case 13939ULL: goto x86_l_3673;
	case 13941ULL: goto x86_l_3675;
	case 13944ULL: goto x86_l_3678;
	case 13948ULL: goto x86_l_367c;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13989ULL: goto x86_l_36a5;
	case 13992ULL: goto x86_l_36a8;
	case 13994ULL: goto x86_l_36aa;
	case 14001ULL: goto x86_l_36b1;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14019ULL: goto x86_l_36c3;
	case 14022ULL: goto x86_l_36c6;
	case 14028ULL: goto x86_l_36cc;
	case 14036ULL: goto x86_l_36d4;
	case 14043ULL: goto x86_l_36db;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14055ULL: goto x86_l_36e7;
	case 14058ULL: goto x86_l_36ea;
	case 14064ULL: goto x86_l_36f0;
	case 14067ULL: goto x86_l_36f3;
	case 14077ULL: goto x86_l_36fd;
	case 14080ULL: goto x86_l_3700;
	case 14084ULL: goto x86_l_3704;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14099ULL: goto x86_l_3713;
	case 14103ULL: goto x86_l_3717;
	case 14111ULL: goto x86_l_371f;
	case 14114ULL: goto x86_l_3722;
	case 14118ULL: goto x86_l_3726;
	case 14125ULL: goto x86_l_372d;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14140ULL: goto x86_l_373c;
	case 14149ULL: goto x86_l_3745;
	case 14158ULL: goto x86_l_374e;
	case 14166ULL: goto x86_l_3756;
	case 14171ULL: goto x86_l_375b;
	case 14173ULL: goto x86_l_375d;
	case 14178ULL: goto x86_l_3762;
	case 14185ULL: goto x86_l_3769;
	case 14190ULL: goto x86_l_376e;
	case 14193ULL: goto x86_l_3771;
	case 14195ULL: goto x86_l_3773;
	case 14198ULL: goto x86_l_3776;
	case 14204ULL: goto x86_l_377c;
	case 14207ULL: goto x86_l_377f;
	case 14211ULL: goto x86_l_3783;
	case 14213ULL: goto x86_l_3785;
	case 14218ULL: goto x86_l_378a;
	case 14222ULL: goto x86_l_378e;
	case 14225ULL: goto x86_l_3791;
	case 14231ULL: goto x86_l_3797;
	case 14233ULL: goto x86_l_3799;
	case 14236ULL: goto x86_l_379c;
	case 14240ULL: goto x86_l_37a0;
	case 14247ULL: goto x86_l_37a7;
	case 14252ULL: goto x86_l_37ac;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14270ULL: goto x86_l_37be;
	case 14275ULL: goto x86_l_37c3;
	case 14281ULL: goto x86_l_37c9;
	case 14284ULL: goto x86_l_37cc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30dd:
	/* 0x30dd: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30e5:
	/* 0x30e5: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_30ed:
	/* 0x30ed: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_30f4:
	/* 0x30f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30f7:
	/* 0x30f7: je     3146 <trace_ret_vfs_writev_tail+0x3146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3146;
	}
x86_l_30f9:
	/* 0x30f9: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3101:
	/* 0x3101: mov    BYTE PTR [rsp+0x95],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 149ULL);
x86_l_3108:
	/* 0x3108: mov    BYTE PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_3110:
	/* 0x3110: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3115:
	/* 0x3115: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_311a:
	/* 0x311a: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_311f:
	/* 0x311f: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3127:
	/* 0x3127: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_312c:
	/* 0x312c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312e:
	/* 0x312e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3133:
	/* 0x3133: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_313b:
	/* 0x313b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_313f:
	/* 0x313f: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3146:
	/* 0x3146: movzx  eax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_314f:
	/* 0x314f: cmp    rax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31935ULL);
x86_l_3155:
	/* 0x3155: ja     31a7 <trace_ret_vfs_writev_tail+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31a7;
	}
x86_l_3157:
	/* 0x3157: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_315b:
	/* 0x315b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3162:
	/* 0x3162: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3167:
	/* 0x3167: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_316c:
	/* 0x316c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3171:
	/* 0x3171: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_317a:
	/* 0x317a: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_317e:
	/* 0x317e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3185:
	/* 0x3185: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_318a:
	/* 0x318a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318c:
	/* 0x318c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_3193:
	/* 0x3193: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3198:
	/* 0x3198: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_319d:
	/* 0x319d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_31a0:
	/* 0x31a0: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31a5:
	/* 0x31a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a7:
	/* 0x31a7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a9:
	/* 0x31a9: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_31b0:
	/* 0x31b0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_31b2:
	/* 0x31b2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_31b3:
	/* 0x31b3: jmp    6259 <.L.str.5+0x6249> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_31b8:
	/* 0x31b8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31bb:
	/* 0x31bb: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_31c1:
	/* 0x31c1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c6:
	/* 0x31c6: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_31cb:
	/* 0x31cb: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_31d1:
	/* 0x31d1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31d5:
	/* 0x31d5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31da:
	/* 0x31da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31df:
	/* 0x31df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31e4:
	/* 0x31e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e9:
	/* 0x31e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31ed:
	/* 0x31ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31f2:
	/* 0x31f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f4:
	/* 0x31f4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f9:
	/* 0x31f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fe:
	/* 0x31fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3203:
	/* 0x3203: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3208:
	/* 0x3208: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_320d:
	/* 0x320d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3212:
	/* 0x3212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3214:
	/* 0x3214: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3219:
	/* 0x3219: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_321e:
	/* 0x321e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3223:
	/* 0x3223: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3228:
	/* 0x3228: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_322d:
	/* 0x322d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3232:
	/* 0x3232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3234:
	/* 0x3234: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3239:
	/* 0x3239: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_323d:
	/* 0x323d: jmp    3274 <trace_ret_vfs_writev_tail+0x3274> */
	goto x86_l_3274;
x86_l_323f:
	/* 0x323f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3244:
	/* 0x3244: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_324a:
	/* 0x324a: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_324d:
	/* 0x324d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_324f:
	/* 0x324f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3254:
	/* 0x3254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3256:
	/* 0x3256: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3259:
	/* 0x3259: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_325f:
	/* 0x325f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3262:
	/* 0x3262: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3268:
	/* 0x3268: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_326d:
	/* 0x326d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_326f:
	/* 0x326f: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3274:
	/* 0x3274: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3279:
	/* 0x3279: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_327e:
	/* 0x327e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3283:
	/* 0x3283: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3288:
	/* 0x3288: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_328b:
	/* 0x328b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328d:
	/* 0x328d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3292:
	/* 0x3292: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3297:
	/* 0x3297: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_329b:
	/* 0x329b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32a0:
	/* 0x32a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32a5:
	/* 0x32a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32aa:
	/* 0x32aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32af:
	/* 0x32af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b1:
	/* 0x32b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32b6:
	/* 0x32b6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32b9:
	/* 0x32b9: je     3457 <trace_ret_vfs_writev_tail+0x3457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3457;
	}
x86_l_32bf:
	/* 0x32bf: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32c4:
	/* 0x32c4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32c7:
	/* 0x32c7: je     3457 <trace_ret_vfs_writev_tail+0x3457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3457;
	}
x86_l_32cd:
	/* 0x32cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32d1:
	/* 0x32d1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32d6:
	/* 0x32d6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32db:
	/* 0x32db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32e0:
	/* 0x32e0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32e5:
	/* 0x32e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e7:
	/* 0x32e7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_32eb:
	/* 0x32eb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_32ed:
	/* 0x32ed: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_32f3:
	/* 0x32f3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_32f5:
	/* 0x32f5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32f7:
	/* 0x32f7: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_32fd:
	/* 0x32fd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3302:
	/* 0x3302: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3308:
	/* 0x3308: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
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
	/* 0x3317: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_331d:
	/* 0x331d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3320:
	/* 0x3320: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3326:
	/* 0x3326: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_332b:
	/* 0x332b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_332d:
	/* 0x332d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3332:
	/* 0x3332: jmp    34dc <trace_ret_vfs_writev_tail+0x34dc> */
	goto x86_l_34dc;
x86_l_3337:
	/* 0x3337: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_333a:
	/* 0x333a: jne    1b53 <trace_ret_vfs_writev_tail+0x1b53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6995ULL;
	}
x86_l_3340:
	/* 0x3340: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3345:
	/* 0x3345: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_334a:
	/* 0x334a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_3350:
	/* 0x3350: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3354:
	/* 0x3354: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3359:
	/* 0x3359: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_335e:
	/* 0x335e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3363:
	/* 0x3363: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3368:
	/* 0x3368: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_336c:
	/* 0x336c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3371:
	/* 0x3371: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3373:
	/* 0x3373: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3378:
	/* 0x3378: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_337d:
	/* 0x337d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3382:
	/* 0x3382: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3387:
	/* 0x3387: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338c:
	/* 0x338c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3391:
	/* 0x3391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3393:
	/* 0x3393: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3398:
	/* 0x3398: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_339d:
	/* 0x339d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33a2:
	/* 0x33a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33a7:
	/* 0x33a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33ac:
	/* 0x33ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b1:
	/* 0x33b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b3:
	/* 0x33b3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33b8:
	/* 0x33b8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33bc:
	/* 0x33bc: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33c1:
	/* 0x33c1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33c6:
	/* 0x33c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33cb:
	/* 0x33cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33d0:
	/* 0x33d0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33d5:
	/* 0x33d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33da:
	/* 0x33da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dc:
	/* 0x33dc: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33e1:
	/* 0x33e1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33e6:
	/* 0x33e6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33ea:
	/* 0x33ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33ef:
	/* 0x33ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33f4:
	/* 0x33f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33f9:
	/* 0x33f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33fe:
	/* 0x33fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3400:
	/* 0x3400: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3405:
	/* 0x3405: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3408:
	/* 0x3408: je     37ec <trace_ret_vfs_writev_tail+0x37ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14316ULL;
	}
x86_l_340e:
	/* 0x340e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3413:
	/* 0x3413: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3416:
	/* 0x3416: je     37ec <trace_ret_vfs_writev_tail+0x37ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14316ULL;
	}
x86_l_341c:
	/* 0x341c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3420:
	/* 0x3420: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3425:
	/* 0x3425: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_342a:
	/* 0x342a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_342f:
	/* 0x342f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3434:
	/* 0x3434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3436:
	/* 0x3436: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_343a:
	/* 0x343a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_343c:
	/* 0x343c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3442:
	/* 0x3442: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3445:
	/* 0x3445: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3447:
	/* 0x3447: jae    3af3 <trace_ret_vfs_writev_tail+0x3af3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15091ULL;
	}
x86_l_344d:
	/* 0x344d: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3452:
	/* 0x3452: jmp    1deb <trace_ret_vfs_writev_tail+0x1deb> */
	return 7659ULL;
x86_l_3457:
	/* 0x3457: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_345a:
	/* 0x345a: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_3460:
	/* 0x3460: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3465:
	/* 0x3465: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_346a:
	/* 0x346a: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_3470:
	/* 0x3470: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3474:
	/* 0x3474: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3479:
	/* 0x3479: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_347e:
	/* 0x347e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3483:
	/* 0x3483: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3488:
	/* 0x3488: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_348c:
	/* 0x348c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3491:
	/* 0x3491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3493:
	/* 0x3493: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3498:
	/* 0x3498: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_349d:
	/* 0x349d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34a2:
	/* 0x34a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34a7:
	/* 0x34a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34ac:
	/* 0x34ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34b1:
	/* 0x34b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b3:
	/* 0x34b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34b8:
	/* 0x34b8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_34bd:
	/* 0x34bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34c2:
	/* 0x34c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34c7:
	/* 0x34c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34cc:
	/* 0x34cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34d1:
	/* 0x34d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d3:
	/* 0x34d3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d8:
	/* 0x34d8: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34dc:
	/* 0x34dc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34e1:
	/* 0x34e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34e6:
	/* 0x34e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34eb:
	/* 0x34eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f0:
	/* 0x34f0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_34f3:
	/* 0x34f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f5:
	/* 0x34f5: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34fa:
	/* 0x34fa: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34ff:
	/* 0x34ff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3503:
	/* 0x3503: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3508:
	/* 0x3508: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_350d:
	/* 0x350d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3512:
	/* 0x3512: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3517:
	/* 0x3517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3519:
	/* 0x3519: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_351e:
	/* 0x351e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3521:
	/* 0x3521: je     387b <trace_ret_vfs_writev_tail+0x387b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14459ULL;
	}
x86_l_3527:
	/* 0x3527: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_352c:
	/* 0x352c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_352f:
	/* 0x352f: je     387b <trace_ret_vfs_writev_tail+0x387b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14459ULL;
	}
x86_l_3535:
	/* 0x3535: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3539:
	/* 0x3539: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_353e:
	/* 0x353e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3543:
	/* 0x3543: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3548:
	/* 0x3548: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_354d:
	/* 0x354d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354f:
	/* 0x354f: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3553:
	/* 0x3553: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3555:
	/* 0x3555: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_355b:
	/* 0x355b: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_355d:
	/* 0x355d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_355f:
	/* 0x355f: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_3565:
	/* 0x3565: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_356a:
	/* 0x356a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3570:
	/* 0x3570: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3573:
	/* 0x3573: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3575:
	/* 0x3575: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_357a:
	/* 0x357a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_357c:
	/* 0x357c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_357f:
	/* 0x357f: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_3585:
	/* 0x3585: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3588:
	/* 0x3588: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_358e:
	/* 0x358e: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3593:
	/* 0x3593: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3595:
	/* 0x3595: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_359a:
	/* 0x359a: jmp    3900 <trace_ret_vfs_writev_tail+0x3900> */
	return 14592ULL;
x86_l_359f:
	/* 0x359f: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_35a2:
	/* 0x35a2: je     36b1 <trace_ret_vfs_writev_tail+0x36b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b1;
	}
x86_l_35a8:
	/* 0x35a8: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_35b0:
	/* 0x35b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_35b7:
	/* 0x35b7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35bc:
	/* 0x35bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35c1:
	/* 0x35c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c3:
	/* 0x35c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35c6:
	/* 0x35c6: je     36b1 <trace_ret_vfs_writev_tail+0x36b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b1;
	}
x86_l_35cc:
	/* 0x35cc: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_35cf:
	/* 0x35cf: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_35d9:
	/* 0x35d9: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35dc:
	/* 0x35dc: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e0:
	/* 0x35e0: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35e8:
	/* 0x35e8: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_35ed:
	/* 0x35ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ef:
	/* 0x35ef: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35f3:
	/* 0x35f3: mov    DWORD PTR [r14+0x1c],0x58 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084376ULL);
x86_l_35fb:
	/* 0x35fb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_35fe:
	/* 0x35fe: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3602:
	/* 0x3602: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_3609:
	/* 0x3609: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_360e:
	/* 0x360e: call   3613 <trace_ret_vfs_writev_tail+0x3613> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_3613:
	/* 0x3613: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_3618:
	/* 0x3618: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3621:
	/* 0x3621: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_362a:
	/* 0x362a: mov    DWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_3632:
	/* 0x3632: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3637:
	/* 0x3637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3639:
	/* 0x3639: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_363e:
	/* 0x363e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3645:
	/* 0x3645: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_364a:
	/* 0x364a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_364d:
	/* 0x364d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364f:
	/* 0x364f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3652:
	/* 0x3652: je     494b <trace_ret_vfs_writev_tail+0x494b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18763ULL;
	}
x86_l_3658:
	/* 0x3658: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_365b:
	/* 0x365b: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_365f:
	/* 0x365f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3661:
	/* 0x3661: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3666:
	/* 0x3666: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366a:
	/* 0x366a: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_366d:
	/* 0x366d: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_3673:
	/* 0x3673: jb     36b1 <trace_ret_vfs_writev_tail+0x36b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36b1;
	}
x86_l_3675:
	/* 0x3675: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3678:
	/* 0x3678: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_367c:
	/* 0x367c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_3683:
	/* 0x3683: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3688:
	/* 0x3688: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_368d:
	/* 0x368d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3692:
	/* 0x3692: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_369a:
	/* 0x369a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_369f:
	/* 0x369f: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_36a5:
	/* 0x36a5: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_36a8:
	/* 0x36a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36aa:
	/* 0x36aa: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b1:
	/* 0x36b1: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_36b9:
	/* 0x36b9: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_36be:
	/* 0x36be: jmp    234f <trace_ret_vfs_writev_tail+0x234f> */
	return 9039ULL;
x86_l_36c3:
	/* 0x36c3: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_36c6:
	/* 0x36c6: je     2515 <trace_ret_vfs_writev_tail+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9493ULL;
	}
x86_l_36cc:
	/* 0x36cc: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_36d4:
	/* 0x36d4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_36db:
	/* 0x36db: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36e0:
	/* 0x36e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36e5:
	/* 0x36e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36e7:
	/* 0x36e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36ea:
	/* 0x36ea: je     37d5 <trace_ret_vfs_writev_tail+0x37d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14293ULL;
	}
x86_l_36f0:
	/* 0x36f0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_36f3:
	/* 0x36f3: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_36fd:
	/* 0x36fd: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3700:
	/* 0x3700: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3704:
	/* 0x3704: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_370c:
	/* 0x370c: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3711:
	/* 0x3711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3713:
	/* 0x3713: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3717:
	/* 0x3717: mov    DWORD PTR [r14+0x1c],0x9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084443ULL);
x86_l_371f:
	/* 0x371f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3722:
	/* 0x3722: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3726:
	/* 0x3726: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_372d:
	/* 0x372d: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_3732:
	/* 0x3732: call   3737 <trace_ret_vfs_writev_tail+0x3737> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_3737:
	/* 0x3737: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_373c:
	/* 0x373c: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3745:
	/* 0x3745: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_374e:
	/* 0x374e: mov    DWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_3756:
	/* 0x3756: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_375b:
	/* 0x375b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375d:
	/* 0x375d: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3762:
	/* 0x3762: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3769:
	/* 0x3769: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_376e:
	/* 0x376e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3771:
	/* 0x3771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3773:
	/* 0x3773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3776:
	/* 0x3776: je     4981 <trace_ret_vfs_writev_tail+0x4981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18817ULL;
	}
x86_l_377c:
	/* 0x377c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_377f:
	/* 0x377f: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3783:
	/* 0x3783: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3785:
	/* 0x3785: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_378a:
	/* 0x378a: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_378e:
	/* 0x378e: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3791:
	/* 0x3791: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_3797:
	/* 0x3797: jb     37d5 <trace_ret_vfs_writev_tail+0x37d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14293ULL;
	}
x86_l_3799:
	/* 0x3799: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_379c:
	/* 0x379c: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37a0:
	/* 0x37a0: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_37a7:
	/* 0x37a7: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_37ac:
	/* 0x37ac: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_37b1:
	/* 0x37b1: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_37b6:
	/* 0x37b6: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_37be:
	/* 0x37be: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_37c3:
	/* 0x37c3: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_37c9:
	/* 0x37c9: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_37cc:
	/* 0x37cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 14286ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14286ULL: goto x86_l_37ce;
	case 14293ULL: goto x86_l_37d5;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14319ULL: goto x86_l_37ef;
	case 14325ULL: goto x86_l_37f5;
	case 14330ULL: goto x86_l_37fa;
	case 14335ULL: goto x86_l_37ff;
	case 14341ULL: goto x86_l_3805;
	case 14345ULL: goto x86_l_3809;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14376ULL: goto x86_l_3828;
	case 14381ULL: goto x86_l_382d;
	case 14386ULL: goto x86_l_3832;
	case 14391ULL: goto x86_l_3837;
	case 14396ULL: goto x86_l_383c;
	case 14401ULL: goto x86_l_3841;
	case 14406ULL: goto x86_l_3846;
	case 14408ULL: goto x86_l_3848;
	case 14413ULL: goto x86_l_384d;
	case 14418ULL: goto x86_l_3852;
	case 14423ULL: goto x86_l_3857;
	case 14428ULL: goto x86_l_385c;
	case 14433ULL: goto x86_l_3861;
	case 14438ULL: goto x86_l_3866;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14462ULL: goto x86_l_387e;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14484ULL: goto x86_l_3894;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14498ULL: goto x86_l_38a2;
	case 14503ULL: goto x86_l_38a7;
	case 14508ULL: goto x86_l_38ac;
	case 14512ULL: goto x86_l_38b0;
	case 14517ULL: goto x86_l_38b5;
	case 14519ULL: goto x86_l_38b7;
	case 14524ULL: goto x86_l_38bc;
	case 14529ULL: goto x86_l_38c1;
	case 14534ULL: goto x86_l_38c6;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14549ULL: goto x86_l_38d5;
	case 14551ULL: goto x86_l_38d7;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14566ULL: goto x86_l_38e6;
	case 14571ULL: goto x86_l_38eb;
	case 14576ULL: goto x86_l_38f0;
	case 14581ULL: goto x86_l_38f5;
	case 14583ULL: goto x86_l_38f7;
	case 14588ULL: goto x86_l_38fc;
	case 14592ULL: goto x86_l_3900;
	case 14597ULL: goto x86_l_3905;
	case 14602ULL: goto x86_l_390a;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14617ULL: goto x86_l_3919;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14631ULL: goto x86_l_3927;
	case 14636ULL: goto x86_l_392c;
	case 14641ULL: goto x86_l_3931;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14653ULL: goto x86_l_393d;
	case 14658ULL: goto x86_l_3942;
	case 14661ULL: goto x86_l_3945;
	case 14667ULL: goto x86_l_394b;
	case 14672ULL: goto x86_l_3950;
	case 14675ULL: goto x86_l_3953;
	case 14681ULL: goto x86_l_3959;
	case 14685ULL: goto x86_l_395d;
	case 14690ULL: goto x86_l_3962;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14707ULL: goto x86_l_3973;
	case 14711ULL: goto x86_l_3977;
	case 14713ULL: goto x86_l_3979;
	case 14719ULL: goto x86_l_397f;
	case 14721ULL: goto x86_l_3981;
	case 14723ULL: goto x86_l_3983;
	case 14729ULL: goto x86_l_3989;
	case 14734ULL: goto x86_l_398e;
	case 14740ULL: goto x86_l_3994;
	case 14743ULL: goto x86_l_3997;
	case 14745ULL: goto x86_l_3999;
	case 14750ULL: goto x86_l_399e;
	case 14752ULL: goto x86_l_39a0;
	case 14755ULL: goto x86_l_39a3;
	case 14761ULL: goto x86_l_39a9;
	case 14764ULL: goto x86_l_39ac;
	case 14770ULL: goto x86_l_39b2;
	case 14775ULL: goto x86_l_39b7;
	case 14777ULL: goto x86_l_39b9;
	case 14782ULL: goto x86_l_39be;
	case 14787ULL: goto x86_l_39c3;
	case 14795ULL: goto x86_l_39cb;
	case 14798ULL: goto x86_l_39ce;
	case 14804ULL: goto x86_l_39d4;
	case 14812ULL: goto x86_l_39dc;
	case 14819ULL: goto x86_l_39e3;
	case 14824ULL: goto x86_l_39e8;
	case 14829ULL: goto x86_l_39ed;
	case 14831ULL: goto x86_l_39ef;
	case 14834ULL: goto x86_l_39f2;
	case 14840ULL: goto x86_l_39f8;
	case 14843ULL: goto x86_l_39fb;
	case 14853ULL: goto x86_l_3a05;
	case 14856ULL: goto x86_l_3a08;
	case 14860ULL: goto x86_l_3a0c;
	case 14868ULL: goto x86_l_3a14;
	case 14873ULL: goto x86_l_3a19;
	case 14875ULL: goto x86_l_3a1b;
	case 14879ULL: goto x86_l_3a1f;
	case 14887ULL: goto x86_l_3a27;
	case 14890ULL: goto x86_l_3a2a;
	case 14894ULL: goto x86_l_3a2e;
	case 14901ULL: goto x86_l_3a35;
	case 14906ULL: goto x86_l_3a3a;
	case 14911ULL: goto x86_l_3a3f;
	case 14916ULL: goto x86_l_3a44;
	case 14925ULL: goto x86_l_3a4d;
	case 14934ULL: goto x86_l_3a56;
	case 14942ULL: goto x86_l_3a5e;
	case 14947ULL: goto x86_l_3a63;
	case 14949ULL: goto x86_l_3a65;
	case 14954ULL: goto x86_l_3a6a;
	case 14961ULL: goto x86_l_3a71;
	case 14966ULL: goto x86_l_3a76;
	case 14969ULL: goto x86_l_3a79;
	case 14971ULL: goto x86_l_3a7b;
	case 14974ULL: goto x86_l_3a7e;
	case 14980ULL: goto x86_l_3a84;
	case 14984ULL: goto x86_l_3a88;
	case 14986ULL: goto x86_l_3a8a;
	case 14991ULL: goto x86_l_3a8f;
	case 14995ULL: goto x86_l_3a93;
	case 14998ULL: goto x86_l_3a96;
	case 15001ULL: goto x86_l_3a99;
	case 15008ULL: goto x86_l_3aa0;
	case 15010ULL: goto x86_l_3aa2;
	case 15012ULL: goto x86_l_3aa4;
	case 15016ULL: goto x86_l_3aa8;
	case 15023ULL: goto x86_l_3aaf;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15038ULL: goto x86_l_3abe;
	case 15046ULL: goto x86_l_3ac6;
	case 15051ULL: goto x86_l_3acb;
	case 15057ULL: goto x86_l_3ad1;
	case 15060ULL: goto x86_l_3ad4;
	case 15062ULL: goto x86_l_3ad6;
	case 15068ULL: goto x86_l_3adc;
	case 15076ULL: goto x86_l_3ae4;
	case 15081ULL: goto x86_l_3ae9;
	case 15086ULL: goto x86_l_3aee;
	case 15091ULL: goto x86_l_3af3;
	case 15096ULL: goto x86_l_3af8;
	case 15102ULL: goto x86_l_3afe;
	case 15107ULL: goto x86_l_3b03;
	case 15109ULL: goto x86_l_3b05;
	case 15114ULL: goto x86_l_3b0a;
	case 15116ULL: goto x86_l_3b0c;
	case 15119ULL: goto x86_l_3b0f;
	case 15125ULL: goto x86_l_3b15;
	case 15129ULL: goto x86_l_3b19;
	case 15135ULL: goto x86_l_3b1f;
	case 15140ULL: goto x86_l_3b24;
	case 15144ULL: goto x86_l_3b28;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15157ULL: goto x86_l_3b35;
	case 15162ULL: goto x86_l_3b3a;
	case 15167ULL: goto x86_l_3b3f;
	case 15172ULL: goto x86_l_3b44;
	case 15177ULL: goto x86_l_3b49;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15189ULL: goto x86_l_3b55;
	case 15193ULL: goto x86_l_3b59;
	case 15198ULL: goto x86_l_3b5e;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15213ULL: goto x86_l_3b6d;
	case 15215ULL: goto x86_l_3b6f;
	case 15220ULL: goto x86_l_3b74;
	case 15223ULL: goto x86_l_3b77;
	case 15225ULL: goto x86_l_3b79;
	case 15230ULL: goto x86_l_3b7e;
	case 15233ULL: goto x86_l_3b81;
	case 15235ULL: goto x86_l_3b83;
	case 15239ULL: goto x86_l_3b87;
	case 15244ULL: goto x86_l_3b8c;
	case 15249ULL: goto x86_l_3b91;
	case 15254ULL: goto x86_l_3b96;
	case 15259ULL: goto x86_l_3b9b;
	case 15261ULL: goto x86_l_3b9d;
	case 15265ULL: goto x86_l_3ba1;
	case 15267ULL: goto x86_l_3ba3;
	case 15273ULL: goto x86_l_3ba9;
	case 15276ULL: goto x86_l_3bac;
	case 15278ULL: goto x86_l_3bae;
	case 15284ULL: goto x86_l_3bb4;
	case 15289ULL: goto x86_l_3bb9;
	case 15295ULL: goto x86_l_3bbf;
	case 15300ULL: goto x86_l_3bc4;
	case 15302ULL: goto x86_l_3bc6;
	case 15307ULL: goto x86_l_3bcb;
	case 15309ULL: goto x86_l_3bcd;
	case 15312ULL: goto x86_l_3bd0;
	case 15314ULL: goto x86_l_3bd2;
	case 15318ULL: goto x86_l_3bd6;
	case 15324ULL: goto x86_l_3bdc;
	case 15329ULL: goto x86_l_3be1;
	case 15333ULL: goto x86_l_3be5;
	case 15336ULL: goto x86_l_3be8;
	case 15341ULL: goto x86_l_3bed;
	case 15346ULL: goto x86_l_3bf2;
	case 15349ULL: goto x86_l_3bf5;
	case 15355ULL: goto x86_l_3bfb;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15368ULL: goto x86_l_3c08;
	case 15374ULL: goto x86_l_3c0e;
	case 15379ULL: goto x86_l_3c13;
	case 15384ULL: goto x86_l_3c18;
	case 15390ULL: goto x86_l_3c1e;
	case 15394ULL: goto x86_l_3c22;
	case 15399ULL: goto x86_l_3c27;
	case 15404ULL: goto x86_l_3c2c;
	case 15409ULL: goto x86_l_3c31;
	case 15414ULL: goto x86_l_3c36;
	case 15418ULL: goto x86_l_3c3a;
	case 15423ULL: goto x86_l_3c3f;
	case 15425ULL: goto x86_l_3c41;
	case 15430ULL: goto x86_l_3c46;
	case 15435ULL: goto x86_l_3c4b;
	case 15440ULL: goto x86_l_3c50;
	case 15445ULL: goto x86_l_3c55;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15457ULL: goto x86_l_3c61;
	case 15462ULL: goto x86_l_3c66;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15477ULL: goto x86_l_3c75;
	case 15482ULL: goto x86_l_3c7a;
	case 15487ULL: goto x86_l_3c7f;
	case 15489ULL: goto x86_l_3c81;
	case 15494ULL: goto x86_l_3c86;
	case 15498ULL: goto x86_l_3c8a;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15518ULL: goto x86_l_3c9e;
	case 15521ULL: goto x86_l_3ca1;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15533ULL: goto x86_l_3cad;
	case 15537ULL: goto x86_l_3cb1;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15552ULL: goto x86_l_3cc0;
	case 15557ULL: goto x86_l_3cc5;
	case 15559ULL: goto x86_l_3cc7;
	case 15564ULL: goto x86_l_3ccc;
	case 15567ULL: goto x86_l_3ccf;
	case 15573ULL: goto x86_l_3cd5;
	case 15578ULL: goto x86_l_3cda;
	case 15581ULL: goto x86_l_3cdd;
	case 15587ULL: goto x86_l_3ce3;
	case 15591ULL: goto x86_l_3ce7;
	case 15596ULL: goto x86_l_3cec;
	case 15601ULL: goto x86_l_3cf1;
	case 15606ULL: goto x86_l_3cf6;
	case 15611ULL: goto x86_l_3cfb;
	case 15613ULL: goto x86_l_3cfd;
	case 15617ULL: goto x86_l_3d01;
	case 15619ULL: goto x86_l_3d03;
	case 15625ULL: goto x86_l_3d09;
	case 15627ULL: goto x86_l_3d0b;
	case 15629ULL: goto x86_l_3d0d;
	case 15635ULL: goto x86_l_3d13;
	case 15640ULL: goto x86_l_3d18;
	case 15646ULL: goto x86_l_3d1e;
	case 15649ULL: goto x86_l_3d21;
	case 15651ULL: goto x86_l_3d23;
	case 15656ULL: goto x86_l_3d28;
	case 15658ULL: goto x86_l_3d2a;
	case 15661ULL: goto x86_l_3d2d;
	case 15667ULL: goto x86_l_3d33;
	case 15670ULL: goto x86_l_3d36;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15683ULL: goto x86_l_3d43;
	case 15688ULL: goto x86_l_3d48;
	case 15693ULL: goto x86_l_3d4d;
	case 15698ULL: goto x86_l_3d52;
	case 15703ULL: goto x86_l_3d57;
	case 15709ULL: goto x86_l_3d5d;
	case 15713ULL: goto x86_l_3d61;
	case 15718ULL: goto x86_l_3d66;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15737ULL: goto x86_l_3d79;
	case 15742ULL: goto x86_l_3d7e;
	case 15744ULL: goto x86_l_3d80;
	case 15749ULL: goto x86_l_3d85;
	case 15754ULL: goto x86_l_3d8a;
	case 15759ULL: goto x86_l_3d8f;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15776ULL: goto x86_l_3da0;
	case 15781ULL: goto x86_l_3da5;
	case 15786ULL: goto x86_l_3daa;
	case 15791ULL: goto x86_l_3daf;
	case 15796ULL: goto x86_l_3db4;
	case 15801ULL: goto x86_l_3db9;
	case 15806ULL: goto x86_l_3dbe;
	case 15808ULL: goto x86_l_3dc0;
	case 15813ULL: goto x86_l_3dc5;
	case 15817ULL: goto x86_l_3dc9;
	case 15822ULL: goto x86_l_3dce;
	case 15827ULL: goto x86_l_3dd3;
	case 15832ULL: goto x86_l_3dd8;
	case 15837ULL: goto x86_l_3ddd;
	case 15842ULL: goto x86_l_3de2;
	case 15847ULL: goto x86_l_3de7;
	case 15849ULL: goto x86_l_3de9;
	case 15854ULL: goto x86_l_3dee;
	case 15859ULL: goto x86_l_3df3;
	case 15863ULL: goto x86_l_3df7;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15878ULL: goto x86_l_3e06;
	case 15883ULL: goto x86_l_3e0b;
	case 15885ULL: goto x86_l_3e0d;
	case 15890ULL: goto x86_l_3e12;
	case 15893ULL: goto x86_l_3e15;
	case 15899ULL: goto x86_l_3e1b;
	case 15904ULL: goto x86_l_3e20;
	case 15907ULL: goto x86_l_3e23;
	case 15909ULL: goto x86_l_3e25;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15923ULL: goto x86_l_3e33;
	case 15928ULL: goto x86_l_3e38;
	case 15933ULL: goto x86_l_3e3d;
	case 15935ULL: goto x86_l_3e3f;
	case 15939ULL: goto x86_l_3e43;
	case 15941ULL: goto x86_l_3e45;
	case 15947ULL: goto x86_l_3e4b;
	case 15950ULL: goto x86_l_3e4e;
	case 15952ULL: goto x86_l_3e50;
	case 15958ULL: goto x86_l_3e56;
	case 15963ULL: goto x86_l_3e5b;
	case 15969ULL: goto x86_l_3e61;
	case 15974ULL: goto x86_l_3e66;
	case 15976ULL: goto x86_l_3e68;
	case 15981ULL: goto x86_l_3e6d;
	case 15983ULL: goto x86_l_3e6f;
	case 15986ULL: goto x86_l_3e72;
	case 15992ULL: goto x86_l_3e78;
	case 15996ULL: goto x86_l_3e7c;
	case 16002ULL: goto x86_l_3e82;
	case 16007ULL: goto x86_l_3e87;
	default: return 0xffffffffffffffffULL;
	}
x86_l_37ce:
	/* 0x37ce: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d5:
	/* 0x37d5: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_37dd:
	/* 0x37dd: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37e2:
	/* 0x37e2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37e7:
	/* 0x37e7: jmp    2515 <trace_ret_vfs_writev_tail+0x2515> */
	return 9493ULL;
x86_l_37ec:
	/* 0x37ec: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_37ef:
	/* 0x37ef: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bfb;
	}
x86_l_37f5:
	/* 0x37f5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37fa:
	/* 0x37fa: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_37ff:
	/* 0x37ff: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bfb;
	}
x86_l_3805:
	/* 0x3805: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3809:
	/* 0x3809: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_380e:
	/* 0x380e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3813:
	/* 0x3813: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3818:
	/* 0x3818: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_381d:
	/* 0x381d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3821:
	/* 0x3821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3826:
	/* 0x3826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3828:
	/* 0x3828: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_382d:
	/* 0x382d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3832:
	/* 0x3832: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3837:
	/* 0x3837: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_383c:
	/* 0x383c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3841:
	/* 0x3841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3846:
	/* 0x3846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3848:
	/* 0x3848: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_384d:
	/* 0x384d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3852:
	/* 0x3852: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3857:
	/* 0x3857: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_385c:
	/* 0x385c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3861:
	/* 0x3861: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3866:
	/* 0x3866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3868:
	/* 0x3868: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386d:
	/* 0x386d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3871:
	/* 0x3871: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3876:
	/* 0x3876: jmp    3b30 <trace_ret_vfs_writev_tail+0x3b30> */
	goto x86_l_3b30;
x86_l_387b:
	/* 0x387b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_387e:
	/* 0x387e: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_3884:
	/* 0x3884: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3889:
	/* 0x3889: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_388e:
	/* 0x388e: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_3894:
	/* 0x3894: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3898:
	/* 0x3898: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_389d:
	/* 0x389d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38a2:
	/* 0x38a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38a7:
	/* 0x38a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38ac:
	/* 0x38ac: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38b0:
	/* 0x38b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38b5:
	/* 0x38b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b7:
	/* 0x38b7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38bc:
	/* 0x38bc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38c1:
	/* 0x38c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38c6:
	/* 0x38c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38cb:
	/* 0x38cb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38d0:
	/* 0x38d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38d5:
	/* 0x38d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d7:
	/* 0x38d7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38dc:
	/* 0x38dc: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38e1:
	/* 0x38e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38e6:
	/* 0x38e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38eb:
	/* 0x38eb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38f0:
	/* 0x38f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38f5:
	/* 0x38f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f7:
	/* 0x38f7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38fc:
	/* 0x38fc: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3900:
	/* 0x3900: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3905:
	/* 0x3905: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_390a:
	/* 0x390a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_390f:
	/* 0x390f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3914:
	/* 0x3914: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3917:
	/* 0x3917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3919:
	/* 0x3919: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_391e:
	/* 0x391e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3923:
	/* 0x3923: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3927:
	/* 0x3927: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_392c:
	/* 0x392c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3931:
	/* 0x3931: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3936:
	/* 0x3936: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_393b:
	/* 0x393b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393d:
	/* 0x393d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3942:
	/* 0x3942: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3945:
	/* 0x3945: je     3c05 <trace_ret_vfs_writev_tail+0x3c05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c05;
	}
x86_l_394b:
	/* 0x394b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3950:
	/* 0x3950: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3953:
	/* 0x3953: je     3c05 <trace_ret_vfs_writev_tail+0x3c05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c05;
	}
x86_l_3959:
	/* 0x3959: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_395d:
	/* 0x395d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3962:
	/* 0x3962: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3967:
	/* 0x3967: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_396c:
	/* 0x396c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3971:
	/* 0x3971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3973:
	/* 0x3973: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3977:
	/* 0x3977: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3979:
	/* 0x3979: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_397f:
	/* 0x397f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3981:
	/* 0x3981: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3983:
	/* 0x3983: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_3989:
	/* 0x3989: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_398e:
	/* 0x398e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3994:
	/* 0x3994: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3997:
	/* 0x3997: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3999:
	/* 0x3999: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_399e:
	/* 0x399e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39a0:
	/* 0x39a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_39a3:
	/* 0x39a3: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_39a9:
	/* 0x39a9: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_39ac:
	/* 0x39ac: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_39b2:
	/* 0x39b2: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_39b7:
	/* 0x39b7: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39b9:
	/* 0x39b9: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39be:
	/* 0x39be: jmp    3c8a <trace_ret_vfs_writev_tail+0x3c8a> */
	goto x86_l_3c8a;
x86_l_39c3:
	/* 0x39c3: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_39cb:
	/* 0x39cb: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_39ce:
	/* 0x39ce: je     2175 <trace_ret_vfs_writev_tail+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8565ULL;
	}
x86_l_39d4:
	/* 0x39d4: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_39dc:
	/* 0x39dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_39e3:
	/* 0x39e3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39e8:
	/* 0x39e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39ed:
	/* 0x39ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ef:
	/* 0x39ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39f2:
	/* 0x39f2: je     3adc <trace_ret_vfs_writev_tail+0x3adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3adc;
	}
x86_l_39f8:
	/* 0x39f8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_39fb:
	/* 0x39fb: movabs rax,0x100000002 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967298ULL);
x86_l_3a05:
	/* 0x3a05: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a08:
	/* 0x3a08: lea    r13,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a14:
	/* 0x3a14: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3a19:
	/* 0x3a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a1b:
	/* 0x3a1b: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a1f:
	/* 0x3a1f: mov    DWORD PTR [r14+0x1c],0x37 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084343ULL);
x86_l_3a27:
	/* 0x3a27: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3a2a:
	/* 0x3a2a: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3a2e:
	/* 0x3a2e: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_3a35:
	/* 0x3a35: mov    edx,0x47 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_3a3a:
	/* 0x3a3a: call   3a3f <trace_ret_vfs_writev_tail+0x3a3f> */
	X86_SIM_L_EXEC_CALL_MEMCPY(71ULL);
x86_l_3a3f:
	/* 0x3a3f: mov    BYTE PTR [r14+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_3a44:
	/* 0x3a44: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3a4d:
	/* 0x3a4d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3a56:
	/* 0x3a56: mov    DWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_3a5e:
	/* 0x3a5e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3a63:
	/* 0x3a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a65:
	/* 0x3a65: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a6a:
	/* 0x3a6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_3a71:
	/* 0x3a71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a76:
	/* 0x3a76: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3a79:
	/* 0x3a79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7b:
	/* 0x3a7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a7e:
	/* 0x3a7e: je     47d0 <trace_ret_vfs_writev_tail+0x47d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18384ULL;
	}
x86_l_3a84:
	/* 0x3a84: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a88:
	/* 0x3a88: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3a8a:
	/* 0x3a8a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a8f:
	/* 0x3a8f: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a93:
	/* 0x3a93: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a96:
	/* 0x3a96: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3a99:
	/* 0x3a99: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_3aa0:
	/* 0x3aa0: jb     3adc <trace_ret_vfs_writev_tail+0x3adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3adc;
	}
x86_l_3aa2:
	/* 0x3aa2: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa4:
	/* 0x3aa4: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aa8:
	/* 0x3aa8: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&logs)));
x86_l_3aaf:
	/* 0x3aaf: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3ab4:
	/* 0x3ab4: mov    edx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 104ULL);
x86_l_3ab9:
	/* 0x3ab9: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3abe:
	/* 0x3abe: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3ac6:
	/* 0x3ac6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3acb:
	/* 0x3acb: mov    r8d,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 104ULL);
x86_l_3ad1:
	/* 0x3ad1: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3ad4:
	/* 0x3ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ad6:
	/* 0x3ad6: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3adc:
	/* 0x3adc: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3ae4:
	/* 0x3ae4: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aee:
	/* 0x3aee: jmp    2175 <trace_ret_vfs_writev_tail+0x2175> */
	return 8565ULL;
x86_l_3af3:
	/* 0x3af3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3af8:
	/* 0x3af8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3afe:
	/* 0x3afe: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_3b03:
	/* 0x3b03: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3b05:
	/* 0x3b05: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3b0a:
	/* 0x3b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b0c:
	/* 0x3b0c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3b0f:
	/* 0x3b0f: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3bfb;
	}
x86_l_3b15:
	/* 0x3b15: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3b19:
	/* 0x3b19: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3b1f:
	/* 0x3b1f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b24:
	/* 0x3b24: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3b28:
	/* 0x3b28: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3b2b:
	/* 0x3b2b: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b30:
	/* 0x3b30: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b35:
	/* 0x3b35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b3a:
	/* 0x3b3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b3f:
	/* 0x3b3f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b44:
	/* 0x3b44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b49:
	/* 0x3b49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4b:
	/* 0x3b4b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b50:
	/* 0x3b50: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b55:
	/* 0x3b55: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b59:
	/* 0x3b59: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b5e:
	/* 0x3b5e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b63:
	/* 0x3b63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b68:
	/* 0x3b68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b6d:
	/* 0x3b6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6f:
	/* 0x3b6f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b74:
	/* 0x3b74: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3b77:
	/* 0x3b77: je     3bf2 <trace_ret_vfs_writev_tail+0x3bf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bf2;
	}
x86_l_3b79:
	/* 0x3b79: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b7e:
	/* 0x3b7e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b81:
	/* 0x3b81: je     3bf2 <trace_ret_vfs_writev_tail+0x3bf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bf2;
	}
x86_l_3b83:
	/* 0x3b83: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b87:
	/* 0x3b87: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b8c:
	/* 0x3b8c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3b91:
	/* 0x3b91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b96:
	/* 0x3b96: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3b9b:
	/* 0x3b9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9d:
	/* 0x3b9d: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3ba1:
	/* 0x3ba1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ba3:
	/* 0x3ba3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ba9:
	/* 0x3ba9: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3bac:
	/* 0x3bac: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3bae:
	/* 0x3bae: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_3bb4:
	/* 0x3bb4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bb9:
	/* 0x3bb9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3bbf:
	/* 0x3bbf: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_3bc4:
	/* 0x3bc4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3bc6:
	/* 0x3bc6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3bcb:
	/* 0x3bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bcd:
	/* 0x3bcd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3bd0:
	/* 0x3bd0: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3bfb;
	}
x86_l_3bd2:
	/* 0x3bd2: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3bd6:
	/* 0x3bd6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3bdc:
	/* 0x3bdc: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3be1:
	/* 0x3be1: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3be5:
	/* 0x3be5: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3be8:
	/* 0x3be8: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bed:
	/* 0x3bed: jmp    3dce <trace_ret_vfs_writev_tail+0x3dce> */
	goto x86_l_3dce;
x86_l_3bf2:
	/* 0x3bf2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3bf5:
	/* 0x3bf5: je     3d4d <trace_ret_vfs_writev_tail+0x3d4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d4d;
	}
x86_l_3bfb:
	/* 0x3bfb: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3c00:
	/* 0x3c00: jmp    1b53 <trace_ret_vfs_writev_tail+0x1b53> */
	return 6995ULL;
x86_l_3c05:
	/* 0x3c05: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3c08:
	/* 0x3c08: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_3c0e:
	/* 0x3c0e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c13:
	/* 0x3c13: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3c18:
	/* 0x3c18: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_3c1e:
	/* 0x3c1e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c22:
	/* 0x3c22: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c27:
	/* 0x3c27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c2c:
	/* 0x3c2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c31:
	/* 0x3c31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c36:
	/* 0x3c36: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c3a:
	/* 0x3c3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c3f:
	/* 0x3c3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c41:
	/* 0x3c41: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c46:
	/* 0x3c46: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c4b:
	/* 0x3c4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c50:
	/* 0x3c50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c55:
	/* 0x3c55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5a:
	/* 0x3c5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5f:
	/* 0x3c5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c61:
	/* 0x3c61: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c66:
	/* 0x3c66: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3c6b:
	/* 0x3c6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c70:
	/* 0x3c70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c75:
	/* 0x3c75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c7a:
	/* 0x3c7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c7f:
	/* 0x3c7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c81:
	/* 0x3c81: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c86:
	/* 0x3c86: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c8a:
	/* 0x3c8a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c8f:
	/* 0x3c8f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c94:
	/* 0x3c94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c99:
	/* 0x3c99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c9e:
	/* 0x3c9e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3ca1:
	/* 0x3ca1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca3:
	/* 0x3ca3: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca8:
	/* 0x3ca8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cad:
	/* 0x3cad: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3cb1:
	/* 0x3cb1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cb6:
	/* 0x3cb6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cbb:
	/* 0x3cbb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cc0:
	/* 0x3cc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc5:
	/* 0x3cc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc7:
	/* 0x3cc7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ccc:
	/* 0x3ccc: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3ccf:
	/* 0x3ccf: je     3ff0 <trace_ret_vfs_writev_tail+0x3ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16368ULL;
	}
x86_l_3cd5:
	/* 0x3cd5: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cda:
	/* 0x3cda: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3cdd:
	/* 0x3cdd: je     3ff0 <trace_ret_vfs_writev_tail+0x3ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16368ULL;
	}
x86_l_3ce3:
	/* 0x3ce3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3ce7:
	/* 0x3ce7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cec:
	/* 0x3cec: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3cf1:
	/* 0x3cf1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cf6:
	/* 0x3cf6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3cfb:
	/* 0x3cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cfd:
	/* 0x3cfd: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3d01:
	/* 0x3d01: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d03:
	/* 0x3d03: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d09:
	/* 0x3d09: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3d0b:
	/* 0x3d0b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d0d:
	/* 0x3d0d: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_3d13:
	/* 0x3d13: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d18:
	/* 0x3d18: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3d1e:
	/* 0x3d1e: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d21:
	/* 0x3d21: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3d23:
	/* 0x3d23: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3d28:
	/* 0x3d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2a:
	/* 0x3d2a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d2d:
	/* 0x3d2d: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_3d33:
	/* 0x3d33: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d36:
	/* 0x3d36: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3d3c:
	/* 0x3d3c: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3d41:
	/* 0x3d41: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d43:
	/* 0x3d43: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d48:
	/* 0x3d48: jmp    4075 <trace_ret_vfs_writev_tail+0x4075> */
	return 16501ULL;
x86_l_3d4d:
	/* 0x3d4d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d52:
	/* 0x3d52: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3d57:
	/* 0x3d57: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bfb;
	}
x86_l_3d5d:
	/* 0x3d5d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d61:
	/* 0x3d61: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d66:
	/* 0x3d66: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d6b:
	/* 0x3d6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d70:
	/* 0x3d70: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d75:
	/* 0x3d75: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d79:
	/* 0x3d79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d7e:
	/* 0x3d7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d80:
	/* 0x3d80: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d85:
	/* 0x3d85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d8a:
	/* 0x3d8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d8f:
	/* 0x3d8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d94:
	/* 0x3d94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d99:
	/* 0x3d99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d9e:
	/* 0x3d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da0:
	/* 0x3da0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3da5:
	/* 0x3da5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3daa:
	/* 0x3daa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3daf:
	/* 0x3daf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3db4:
	/* 0x3db4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3db9:
	/* 0x3db9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dbe:
	/* 0x3dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc0:
	/* 0x3dc0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dc5:
	/* 0x3dc5: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3dc9:
	/* 0x3dc9: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3dce:
	/* 0x3dce: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dd3:
	/* 0x3dd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3dd8:
	/* 0x3dd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ddd:
	/* 0x3ddd: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3de2:
	/* 0x3de2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de7:
	/* 0x3de7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de9:
	/* 0x3de9: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dee:
	/* 0x3dee: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3df3:
	/* 0x3df3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3df7:
	/* 0x3df7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dfc:
	/* 0x3dfc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e01:
	/* 0x3e01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e06:
	/* 0x3e06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e0b:
	/* 0x3e0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e0d:
	/* 0x3e0d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e12:
	/* 0x3e12: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e15:
	/* 0x3e15: je     3e98 <trace_ret_vfs_writev_tail+0x3e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16024ULL;
	}
x86_l_3e1b:
	/* 0x3e1b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e20:
	/* 0x3e20: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3e23:
	/* 0x3e23: je     3e98 <trace_ret_vfs_writev_tail+0x3e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16024ULL;
	}
x86_l_3e25:
	/* 0x3e25: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e29:
	/* 0x3e29: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e2e:
	/* 0x3e2e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3e33:
	/* 0x3e33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e38:
	/* 0x3e38: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3e3d:
	/* 0x3e3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3f:
	/* 0x3e3f: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3e43:
	/* 0x3e43: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3e45:
	/* 0x3e45: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e4b:
	/* 0x3e4b: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3e4e:
	/* 0x3e4e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e50:
	/* 0x3e50: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_3e56:
	/* 0x3e56: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e5b:
	/* 0x3e5b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3e61:
	/* 0x3e61: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_3e66:
	/* 0x3e66: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3e68:
	/* 0x3e68: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3e6d:
	/* 0x3e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e6f:
	/* 0x3e6f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3e72:
	/* 0x3e72: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_3bfb;
	}
x86_l_3e78:
	/* 0x3e78: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3e7c:
	/* 0x3e7c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3e82:
	/* 0x3e82: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3e87:
	/* 0x3e87: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
	return 16011ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16011ULL: goto x86_l_3e8b;
	case 16014ULL: goto x86_l_3e8e;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16027ULL: goto x86_l_3e9b;
	case 16033ULL: goto x86_l_3ea1;
	case 16038ULL: goto x86_l_3ea6;
	case 16043ULL: goto x86_l_3eab;
	case 16049ULL: goto x86_l_3eb1;
	case 16053ULL: goto x86_l_3eb5;
	case 16058ULL: goto x86_l_3eba;
	case 16063ULL: goto x86_l_3ebf;
	case 16068ULL: goto x86_l_3ec4;
	case 16073ULL: goto x86_l_3ec9;
	case 16077ULL: goto x86_l_3ecd;
	case 16082ULL: goto x86_l_3ed2;
	case 16084ULL: goto x86_l_3ed4;
	case 16089ULL: goto x86_l_3ed9;
	case 16094ULL: goto x86_l_3ede;
	case 16099ULL: goto x86_l_3ee3;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16114ULL: goto x86_l_3ef2;
	case 16116ULL: goto x86_l_3ef4;
	case 16121ULL: goto x86_l_3ef9;
	case 16126ULL: goto x86_l_3efe;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16146ULL: goto x86_l_3f12;
	case 16148ULL: goto x86_l_3f14;
	case 16153ULL: goto x86_l_3f19;
	case 16157ULL: goto x86_l_3f1d;
	case 16162ULL: goto x86_l_3f22;
	case 16167ULL: goto x86_l_3f27;
	case 16172ULL: goto x86_l_3f2c;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16187ULL: goto x86_l_3f3b;
	case 16189ULL: goto x86_l_3f3d;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16203ULL: goto x86_l_3f4b;
	case 16208ULL: goto x86_l_3f50;
	case 16213ULL: goto x86_l_3f55;
	case 16218ULL: goto x86_l_3f5a;
	case 16223ULL: goto x86_l_3f5f;
	case 16225ULL: goto x86_l_3f61;
	case 16230ULL: goto x86_l_3f66;
	case 16233ULL: goto x86_l_3f69;
	case 16239ULL: goto x86_l_3f6f;
	case 16244ULL: goto x86_l_3f74;
	case 16247ULL: goto x86_l_3f77;
	case 16253ULL: goto x86_l_3f7d;
	case 16257ULL: goto x86_l_3f81;
	case 16262ULL: goto x86_l_3f86;
	case 16267ULL: goto x86_l_3f8b;
	case 16272ULL: goto x86_l_3f90;
	case 16277ULL: goto x86_l_3f95;
	case 16279ULL: goto x86_l_3f97;
	case 16283ULL: goto x86_l_3f9b;
	case 16285ULL: goto x86_l_3f9d;
	case 16291ULL: goto x86_l_3fa3;
	case 16294ULL: goto x86_l_3fa6;
	case 16296ULL: goto x86_l_3fa8;
	case 16302ULL: goto x86_l_3fae;
	case 16307ULL: goto x86_l_3fb3;
	case 16313ULL: goto x86_l_3fb9;
	case 16318ULL: goto x86_l_3fbe;
	case 16320ULL: goto x86_l_3fc0;
	case 16325ULL: goto x86_l_3fc5;
	case 16327ULL: goto x86_l_3fc7;
	case 16330ULL: goto x86_l_3fca;
	case 16336ULL: goto x86_l_3fd0;
	case 16340ULL: goto x86_l_3fd4;
	case 16346ULL: goto x86_l_3fda;
	case 16351ULL: goto x86_l_3fdf;
	case 16355ULL: goto x86_l_3fe3;
	case 16358ULL: goto x86_l_3fe6;
	case 16363ULL: goto x86_l_3feb;
	case 16368ULL: goto x86_l_3ff0;
	case 16371ULL: goto x86_l_3ff3;
	case 16377ULL: goto x86_l_3ff9;
	case 16382ULL: goto x86_l_3ffe;
	case 16387ULL: goto x86_l_4003;
	case 16393ULL: goto x86_l_4009;
	case 16397ULL: goto x86_l_400d;
	case 16402ULL: goto x86_l_4012;
	case 16407ULL: goto x86_l_4017;
	case 16412ULL: goto x86_l_401c;
	case 16417ULL: goto x86_l_4021;
	case 16421ULL: goto x86_l_4025;
	case 16426ULL: goto x86_l_402a;
	case 16428ULL: goto x86_l_402c;
	case 16433ULL: goto x86_l_4031;
	case 16438ULL: goto x86_l_4036;
	case 16443ULL: goto x86_l_403b;
	case 16448ULL: goto x86_l_4040;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16460ULL: goto x86_l_404c;
	case 16465ULL: goto x86_l_4051;
	case 16470ULL: goto x86_l_4056;
	case 16475ULL: goto x86_l_405b;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16490ULL: goto x86_l_406a;
	case 16492ULL: goto x86_l_406c;
	case 16497ULL: goto x86_l_4071;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16511ULL: goto x86_l_407f;
	case 16516ULL: goto x86_l_4084;
	case 16521ULL: goto x86_l_4089;
	case 16524ULL: goto x86_l_408c;
	case 16526ULL: goto x86_l_408e;
	case 16531ULL: goto x86_l_4093;
	case 16536ULL: goto x86_l_4098;
	case 16540ULL: goto x86_l_409c;
	case 16545ULL: goto x86_l_40a1;
	case 16550ULL: goto x86_l_40a6;
	case 16555ULL: goto x86_l_40ab;
	case 16560ULL: goto x86_l_40b0;
	case 16562ULL: goto x86_l_40b2;
	case 16567ULL: goto x86_l_40b7;
	case 16570ULL: goto x86_l_40ba;
	case 16576ULL: goto x86_l_40c0;
	case 16581ULL: goto x86_l_40c5;
	case 16584ULL: goto x86_l_40c8;
	case 16590ULL: goto x86_l_40ce;
	case 16594ULL: goto x86_l_40d2;
	case 16599ULL: goto x86_l_40d7;
	case 16604ULL: goto x86_l_40dc;
	case 16609ULL: goto x86_l_40e1;
	case 16614ULL: goto x86_l_40e6;
	case 16616ULL: goto x86_l_40e8;
	case 16620ULL: goto x86_l_40ec;
	case 16622ULL: goto x86_l_40ee;
	case 16628ULL: goto x86_l_40f4;
	case 16630ULL: goto x86_l_40f6;
	case 16632ULL: goto x86_l_40f8;
	case 16638ULL: goto x86_l_40fe;
	case 16643ULL: goto x86_l_4103;
	case 16649ULL: goto x86_l_4109;
	case 16652ULL: goto x86_l_410c;
	case 16654ULL: goto x86_l_410e;
	case 16659ULL: goto x86_l_4113;
	case 16661ULL: goto x86_l_4115;
	case 16664ULL: goto x86_l_4118;
	case 16670ULL: goto x86_l_411e;
	case 16673ULL: goto x86_l_4121;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16686ULL: goto x86_l_412e;
	case 16691ULL: goto x86_l_4133;
	case 16696ULL: goto x86_l_4138;
	case 16699ULL: goto x86_l_413b;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16715ULL: goto x86_l_414b;
	case 16721ULL: goto x86_l_4151;
	case 16725ULL: goto x86_l_4155;
	case 16730ULL: goto x86_l_415a;
	case 16735ULL: goto x86_l_415f;
	case 16740ULL: goto x86_l_4164;
	case 16745ULL: goto x86_l_4169;
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
	case 16798ULL: goto x86_l_419e;
	case 16803ULL: goto x86_l_41a3;
	case 16808ULL: goto x86_l_41a8;
	case 16813ULL: goto x86_l_41ad;
	case 16818ULL: goto x86_l_41b2;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16844ULL: goto x86_l_41cc;
	case 16849ULL: goto x86_l_41d1;
	case 16854ULL: goto x86_l_41d6;
	case 16859ULL: goto x86_l_41db;
	case 16861ULL: goto x86_l_41dd;
	case 16866ULL: goto x86_l_41e2;
	case 16871ULL: goto x86_l_41e7;
	case 16875ULL: goto x86_l_41eb;
	case 16880ULL: goto x86_l_41f0;
	case 16885ULL: goto x86_l_41f5;
	case 16890ULL: goto x86_l_41fa;
	case 16895ULL: goto x86_l_41ff;
	case 16897ULL: goto x86_l_4201;
	case 16902ULL: goto x86_l_4206;
	case 16905ULL: goto x86_l_4209;
	case 16911ULL: goto x86_l_420f;
	case 16916ULL: goto x86_l_4214;
	case 16919ULL: goto x86_l_4217;
	case 16925ULL: goto x86_l_421d;
	case 16929ULL: goto x86_l_4221;
	case 16934ULL: goto x86_l_4226;
	case 16939ULL: goto x86_l_422b;
	case 16944ULL: goto x86_l_4230;
	case 16949ULL: goto x86_l_4235;
	case 16951ULL: goto x86_l_4237;
	case 16955ULL: goto x86_l_423b;
	case 16957ULL: goto x86_l_423d;
	case 16963ULL: goto x86_l_4243;
	case 16966ULL: goto x86_l_4246;
	case 16968ULL: goto x86_l_4248;
	case 16974ULL: goto x86_l_424e;
	case 16979ULL: goto x86_l_4253;
	case 16985ULL: goto x86_l_4259;
	case 16990ULL: goto x86_l_425e;
	case 16992ULL: goto x86_l_4260;
	case 16997ULL: goto x86_l_4265;
	case 16999ULL: goto x86_l_4267;
	case 17002ULL: goto x86_l_426a;
	case 17008ULL: goto x86_l_4270;
	case 17012ULL: goto x86_l_4274;
	case 17018ULL: goto x86_l_427a;
	case 17023ULL: goto x86_l_427f;
	case 17027ULL: goto x86_l_4283;
	case 17030ULL: goto x86_l_4286;
	case 17035ULL: goto x86_l_428b;
	case 17040ULL: goto x86_l_4290;
	case 17043ULL: goto x86_l_4293;
	case 17049ULL: goto x86_l_4299;
	case 17054ULL: goto x86_l_429e;
	case 17059ULL: goto x86_l_42a3;
	case 17065ULL: goto x86_l_42a9;
	case 17069ULL: goto x86_l_42ad;
	case 17074ULL: goto x86_l_42b2;
	case 17079ULL: goto x86_l_42b7;
	case 17084ULL: goto x86_l_42bc;
	case 17089ULL: goto x86_l_42c1;
	case 17093ULL: goto x86_l_42c5;
	case 17098ULL: goto x86_l_42ca;
	case 17100ULL: goto x86_l_42cc;
	case 17105ULL: goto x86_l_42d1;
	case 17110ULL: goto x86_l_42d6;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17125ULL: goto x86_l_42e5;
	case 17130ULL: goto x86_l_42ea;
	case 17132ULL: goto x86_l_42ec;
	case 17137ULL: goto x86_l_42f1;
	case 17142ULL: goto x86_l_42f6;
	case 17147ULL: goto x86_l_42fb;
	case 17152ULL: goto x86_l_4300;
	case 17157ULL: goto x86_l_4305;
	case 17162ULL: goto x86_l_430a;
	case 17164ULL: goto x86_l_430c;
	case 17169ULL: goto x86_l_4311;
	case 17173ULL: goto x86_l_4315;
	case 17178ULL: goto x86_l_431a;
	case 17183ULL: goto x86_l_431f;
	case 17188ULL: goto x86_l_4324;
	case 17193ULL: goto x86_l_4329;
	case 17196ULL: goto x86_l_432c;
	case 17198ULL: goto x86_l_432e;
	case 17203ULL: goto x86_l_4333;
	case 17208ULL: goto x86_l_4338;
	case 17212ULL: goto x86_l_433c;
	case 17217ULL: goto x86_l_4341;
	case 17222ULL: goto x86_l_4346;
	case 17227ULL: goto x86_l_434b;
	case 17232ULL: goto x86_l_4350;
	case 17234ULL: goto x86_l_4352;
	case 17239ULL: goto x86_l_4357;
	case 17242ULL: goto x86_l_435a;
	case 17248ULL: goto x86_l_4360;
	case 17253ULL: goto x86_l_4365;
	case 17256ULL: goto x86_l_4368;
	case 17262ULL: goto x86_l_436e;
	case 17266ULL: goto x86_l_4372;
	case 17271ULL: goto x86_l_4377;
	case 17276ULL: goto x86_l_437c;
	case 17281ULL: goto x86_l_4381;
	case 17286ULL: goto x86_l_4386;
	case 17288ULL: goto x86_l_4388;
	case 17292ULL: goto x86_l_438c;
	case 17294ULL: goto x86_l_438e;
	case 17300ULL: goto x86_l_4394;
	case 17302ULL: goto x86_l_4396;
	case 17304ULL: goto x86_l_4398;
	case 17310ULL: goto x86_l_439e;
	case 17315ULL: goto x86_l_43a3;
	case 17321ULL: goto x86_l_43a9;
	case 17324ULL: goto x86_l_43ac;
	case 17326ULL: goto x86_l_43ae;
	case 17331ULL: goto x86_l_43b3;
	case 17333ULL: goto x86_l_43b5;
	case 17336ULL: goto x86_l_43b8;
	case 17342ULL: goto x86_l_43be;
	case 17345ULL: goto x86_l_43c1;
	case 17351ULL: goto x86_l_43c7;
	case 17356ULL: goto x86_l_43cc;
	case 17358ULL: goto x86_l_43ce;
	case 17363ULL: goto x86_l_43d3;
	case 17368ULL: goto x86_l_43d8;
	case 17371ULL: goto x86_l_43db;
	case 17377ULL: goto x86_l_43e1;
	case 17382ULL: goto x86_l_43e6;
	case 17387ULL: goto x86_l_43eb;
	case 17393ULL: goto x86_l_43f1;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17407ULL: goto x86_l_43ff;
	case 17412ULL: goto x86_l_4404;
	case 17417ULL: goto x86_l_4409;
	case 17421ULL: goto x86_l_440d;
	case 17426ULL: goto x86_l_4412;
	case 17428ULL: goto x86_l_4414;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17448ULL: goto x86_l_4428;
	case 17453ULL: goto x86_l_442d;
	case 17458ULL: goto x86_l_4432;
	case 17460ULL: goto x86_l_4434;
	case 17465ULL: goto x86_l_4439;
	case 17470ULL: goto x86_l_443e;
	case 17475ULL: goto x86_l_4443;
	case 17480ULL: goto x86_l_4448;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17492ULL: goto x86_l_4454;
	case 17497ULL: goto x86_l_4459;
	case 17501ULL: goto x86_l_445d;
	case 17506ULL: goto x86_l_4462;
	case 17511ULL: goto x86_l_4467;
	case 17516ULL: goto x86_l_446c;
	case 17521ULL: goto x86_l_4471;
	case 17526ULL: goto x86_l_4476;
	case 17531ULL: goto x86_l_447b;
	case 17533ULL: goto x86_l_447d;
	case 17538ULL: goto x86_l_4482;
	case 17543ULL: goto x86_l_4487;
	case 17547ULL: goto x86_l_448b;
	case 17552ULL: goto x86_l_4490;
	case 17557ULL: goto x86_l_4495;
	case 17562ULL: goto x86_l_449a;
	case 17567ULL: goto x86_l_449f;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17577ULL: goto x86_l_44a9;
	case 17583ULL: goto x86_l_44af;
	case 17588ULL: goto x86_l_44b4;
	case 17591ULL: goto x86_l_44b7;
	case 17597ULL: goto x86_l_44bd;
	case 17601ULL: goto x86_l_44c1;
	case 17606ULL: goto x86_l_44c6;
	case 17611ULL: goto x86_l_44cb;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17623ULL: goto x86_l_44d7;
	case 17627ULL: goto x86_l_44db;
	case 17629ULL: goto x86_l_44dd;
	case 17635ULL: goto x86_l_44e3;
	case 17638ULL: goto x86_l_44e6;
	case 17640ULL: goto x86_l_44e8;
	case 17646ULL: goto x86_l_44ee;
	case 17651ULL: goto x86_l_44f3;
	case 17657ULL: goto x86_l_44f9;
	case 17662ULL: goto x86_l_44fe;
	case 17664ULL: goto x86_l_4500;
	case 17669ULL: goto x86_l_4505;
	case 17671ULL: goto x86_l_4507;
	case 17674ULL: goto x86_l_450a;
	case 17680ULL: goto x86_l_4510;
	case 17684ULL: goto x86_l_4514;
	case 17690ULL: goto x86_l_451a;
	case 17695ULL: goto x86_l_451f;
	case 17699ULL: goto x86_l_4523;
	case 17702ULL: goto x86_l_4526;
	case 17707ULL: goto x86_l_452b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3e8b:
	/* 0x3e8b: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e8e:
	/* 0x3e8e: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e93:
	/* 0x3e93: jmp    3f22 <trace_ret_vfs_writev_tail+0x3f22> */
	goto x86_l_3f22;
x86_l_3e98:
	/* 0x3e98: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e9b:
	/* 0x3e9b: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_3ea1:
	/* 0x3ea1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea6:
	/* 0x3ea6: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_3eab:
	/* 0x3eab: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_3eb1:
	/* 0x3eb1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3eb5:
	/* 0x3eb5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3eba:
	/* 0x3eba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ebf:
	/* 0x3ebf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ec4:
	/* 0x3ec4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec9:
	/* 0x3ec9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ecd:
	/* 0x3ecd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ed2:
	/* 0x3ed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed4:
	/* 0x3ed4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed9:
	/* 0x3ed9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ede:
	/* 0x3ede: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ee3:
	/* 0x3ee3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eed:
	/* 0x3eed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef2:
	/* 0x3ef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef4:
	/* 0x3ef4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ef9:
	/* 0x3ef9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3efe:
	/* 0x3efe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f03:
	/* 0x3f03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f08:
	/* 0x3f08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f0d:
	/* 0x3f0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f12:
	/* 0x3f12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f14:
	/* 0x3f14: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f19:
	/* 0x3f19: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f1d:
	/* 0x3f1d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f22:
	/* 0x3f22: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f27:
	/* 0x3f27: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f2c:
	/* 0x3f2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f31:
	/* 0x3f31: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f36:
	/* 0x3f36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f3b:
	/* 0x3f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3d:
	/* 0x3f3d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f42:
	/* 0x3f42: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f47:
	/* 0x3f47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f4b:
	/* 0x3f4b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f50:
	/* 0x3f50: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f55:
	/* 0x3f55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f5a:
	/* 0x3f5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f5f:
	/* 0x3f5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f61:
	/* 0x3f61: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f66:
	/* 0x3f66: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3f69:
	/* 0x3f69: je     4138 <trace_ret_vfs_writev_tail+0x4138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4138;
	}
x86_l_3f6f:
	/* 0x3f6f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f74:
	/* 0x3f74: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3f77:
	/* 0x3f77: je     4138 <trace_ret_vfs_writev_tail+0x4138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4138;
	}
x86_l_3f7d:
	/* 0x3f7d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f81:
	/* 0x3f81: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f86:
	/* 0x3f86: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3f8b:
	/* 0x3f8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f90:
	/* 0x3f90: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f95:
	/* 0x3f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f97:
	/* 0x3f97: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3f9b:
	/* 0x3f9b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f9d:
	/* 0x3f9d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3fa3:
	/* 0x3fa3: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_3fa6:
	/* 0x3fa6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fa8:
	/* 0x3fa8: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_3fae:
	/* 0x3fae: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3fb3:
	/* 0x3fb3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3fb9:
	/* 0x3fb9: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_3fbe:
	/* 0x3fbe: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3fc0:
	/* 0x3fc0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3fc5:
	/* 0x3fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc7:
	/* 0x3fc7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3fca:
	/* 0x3fca: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_3fd0:
	/* 0x3fd0: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3fd4:
	/* 0x3fd4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3fda:
	/* 0x3fda: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3fdf:
	/* 0x3fdf: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3fe3:
	/* 0x3fe3: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fe6:
	/* 0x3fe6: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3feb:
	/* 0x3feb: jmp    41c2 <trace_ret_vfs_writev_tail+0x41c2> */
	goto x86_l_41c2;
x86_l_3ff0:
	/* 0x3ff0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3ff3:
	/* 0x3ff3: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_3ff9:
	/* 0x3ff9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ffe:
	/* 0x3ffe: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4003:
	/* 0x4003: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_4009:
	/* 0x4009: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_400d:
	/* 0x400d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4012:
	/* 0x4012: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4017:
	/* 0x4017: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_401c:
	/* 0x401c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4021:
	/* 0x4021: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4025:
	/* 0x4025: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_402a:
	/* 0x402a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402c:
	/* 0x402c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4031:
	/* 0x4031: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4036:
	/* 0x4036: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_403b:
	/* 0x403b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4040:
	/* 0x4040: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4045:
	/* 0x4045: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_404a:
	/* 0x404a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_404c:
	/* 0x404c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4051:
	/* 0x4051: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4056:
	/* 0x4056: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_405b:
	/* 0x405b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4060:
	/* 0x4060: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4065:
	/* 0x4065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_406a:
	/* 0x406a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406c:
	/* 0x406c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4071:
	/* 0x4071: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4075:
	/* 0x4075: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_407a:
	/* 0x407a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_407f:
	/* 0x407f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4084:
	/* 0x4084: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4089:
	/* 0x4089: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_408c:
	/* 0x408c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_408e:
	/* 0x408e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4093:
	/* 0x4093: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4098:
	/* 0x4098: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_409c:
	/* 0x409c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40a1:
	/* 0x40a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40a6:
	/* 0x40a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40ab:
	/* 0x40ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40b0:
	/* 0x40b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b2:
	/* 0x40b2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40b7:
	/* 0x40b7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_40ba:
	/* 0x40ba: je     4290 <trace_ret_vfs_writev_tail+0x4290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4290;
	}
x86_l_40c0:
	/* 0x40c0: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40c5:
	/* 0x40c5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_40c8:
	/* 0x40c8: je     4290 <trace_ret_vfs_writev_tail+0x4290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4290;
	}
x86_l_40ce:
	/* 0x40ce: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_40d2:
	/* 0x40d2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40d7:
	/* 0x40d7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_40dc:
	/* 0x40dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40e1:
	/* 0x40e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_40e6:
	/* 0x40e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e8:
	/* 0x40e8: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_40ec:
	/* 0x40ec: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_40ee:
	/* 0x40ee: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_40f4:
	/* 0x40f4: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_40f6:
	/* 0x40f6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40f8:
	/* 0x40f8: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_40fe:
	/* 0x40fe: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4103:
	/* 0x4103: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4109:
	/* 0x4109: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_410c:
	/* 0x410c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_410e:
	/* 0x410e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4113:
	/* 0x4113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4115:
	/* 0x4115: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4118:
	/* 0x4118: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_411e:
	/* 0x411e: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4121:
	/* 0x4121: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4127:
	/* 0x4127: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_412c:
	/* 0x412c: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_412e:
	/* 0x412e: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4133:
	/* 0x4133: jmp    4315 <trace_ret_vfs_writev_tail+0x4315> */
	goto x86_l_4315;
x86_l_4138:
	/* 0x4138: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_413b:
	/* 0x413b: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_4141:
	/* 0x4141: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4146:
	/* 0x4146: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_414b:
	/* 0x414b: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_4151:
	/* 0x4151: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4155:
	/* 0x4155: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_415a:
	/* 0x415a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_415f:
	/* 0x415f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4164:
	/* 0x4164: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4169:
	/* 0x4169: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
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
	/* 0x4179: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x4194: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4199:
	/* 0x4199: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_419e:
	/* 0x419e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41a3:
	/* 0x41a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41a8:
	/* 0x41a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ad:
	/* 0x41ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b2:
	/* 0x41b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b4:
	/* 0x41b4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b9:
	/* 0x41b9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_41bd:
	/* 0x41bd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41c2:
	/* 0x41c2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41c7:
	/* 0x41c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41cc:
	/* 0x41cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41d1:
	/* 0x41d1: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41d6:
	/* 0x41d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41db:
	/* 0x41db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41dd:
	/* 0x41dd: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41e2:
	/* 0x41e2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41e7:
	/* 0x41e7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_41eb:
	/* 0x41eb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41f0:
	/* 0x41f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41f5:
	/* 0x41f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41fa:
	/* 0x41fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41ff:
	/* 0x41ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4201:
	/* 0x4201: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4206:
	/* 0x4206: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4209:
	/* 0x4209: je     43d8 <trace_ret_vfs_writev_tail+0x43d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43d8;
	}
x86_l_420f:
	/* 0x420f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4214:
	/* 0x4214: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4217:
	/* 0x4217: je     43d8 <trace_ret_vfs_writev_tail+0x43d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43d8;
	}
x86_l_421d:
	/* 0x421d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4221:
	/* 0x4221: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4226:
	/* 0x4226: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_422b:
	/* 0x422b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4230:
	/* 0x4230: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4235:
	/* 0x4235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4237:
	/* 0x4237: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_423b:
	/* 0x423b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_423d:
	/* 0x423d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4243:
	/* 0x4243: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4246:
	/* 0x4246: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4248:
	/* 0x4248: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_424e:
	/* 0x424e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4253:
	/* 0x4253: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4259:
	/* 0x4259: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_425e:
	/* 0x425e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4260:
	/* 0x4260: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4265:
	/* 0x4265: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4267:
	/* 0x4267: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_426a:
	/* 0x426a: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_4270:
	/* 0x4270: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4274:
	/* 0x4274: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_427a:
	/* 0x427a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_427f:
	/* 0x427f: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4283:
	/* 0x4283: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4286:
	/* 0x4286: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_428b:
	/* 0x428b: jmp    4462 <trace_ret_vfs_writev_tail+0x4462> */
	goto x86_l_4462;
x86_l_4290:
	/* 0x4290: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4293:
	/* 0x4293: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_4299:
	/* 0x4299: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429e:
	/* 0x429e: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_42a3:
	/* 0x42a3: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_42a9:
	/* 0x42a9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42ad:
	/* 0x42ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_42b2:
	/* 0x42b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42b7:
	/* 0x42b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42bc:
	/* 0x42bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42c1:
	/* 0x42c1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42c5:
	/* 0x42c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ca:
	/* 0x42ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42cc:
	/* 0x42cc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42d1:
	/* 0x42d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42d6:
	/* 0x42d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42db:
	/* 0x42db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42e0:
	/* 0x42e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e5:
	/* 0x42e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ea:
	/* 0x42ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42ec:
	/* 0x42ec: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f1:
	/* 0x42f1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_42f6:
	/* 0x42f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42fb:
	/* 0x42fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4300:
	/* 0x4300: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4305:
	/* 0x4305: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_430a:
	/* 0x430a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_430c:
	/* 0x430c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4311:
	/* 0x4311: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4315:
	/* 0x4315: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_431a:
	/* 0x431a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_431f:
	/* 0x431f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4324:
	/* 0x4324: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4329:
	/* 0x4329: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_432c:
	/* 0x432c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_432e:
	/* 0x432e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4333:
	/* 0x4333: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4338:
	/* 0x4338: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_433c:
	/* 0x433c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4341:
	/* 0x4341: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4346:
	/* 0x4346: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_434b:
	/* 0x434b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4350:
	/* 0x4350: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4352:
	/* 0x4352: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4357:
	/* 0x4357: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_435a:
	/* 0x435a: je     4530 <trace_ret_vfs_writev_tail+0x4530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17712ULL;
	}
x86_l_4360:
	/* 0x4360: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4365:
	/* 0x4365: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4368:
	/* 0x4368: je     4530 <trace_ret_vfs_writev_tail+0x4530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17712ULL;
	}
x86_l_436e:
	/* 0x436e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4372:
	/* 0x4372: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4377:
	/* 0x4377: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_437c:
	/* 0x437c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4381:
	/* 0x4381: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4386:
	/* 0x4386: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4388:
	/* 0x4388: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_438c:
	/* 0x438c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_438e:
	/* 0x438e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4394:
	/* 0x4394: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4396:
	/* 0x4396: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4398:
	/* 0x4398: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_439e:
	/* 0x439e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43a3:
	/* 0x43a3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_43a9:
	/* 0x43a9: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43ac:
	/* 0x43ac: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_43ae:
	/* 0x43ae: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_43b3:
	/* 0x43b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b5:
	/* 0x43b5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43b8:
	/* 0x43b8: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_43be:
	/* 0x43be: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_43c1:
	/* 0x43c1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_43c7:
	/* 0x43c7: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_43cc:
	/* 0x43cc: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43ce:
	/* 0x43ce: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43d3:
	/* 0x43d3: jmp    45b5 <trace_ret_vfs_writev_tail+0x45b5> */
	return 17845ULL;
x86_l_43d8:
	/* 0x43d8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_43db:
	/* 0x43db: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_43e1:
	/* 0x43e1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e6:
	/* 0x43e6: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_43eb:
	/* 0x43eb: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_43f1:
	/* 0x43f1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_43f5:
	/* 0x43f5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43fa:
	/* 0x43fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43ff:
	/* 0x43ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4404:
	/* 0x4404: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4409:
	/* 0x4409: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_440d:
	/* 0x440d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4412:
	/* 0x4412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4414:
	/* 0x4414: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4419:
	/* 0x4419: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_441e:
	/* 0x441e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4423:
	/* 0x4423: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4428:
	/* 0x4428: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442d:
	/* 0x442d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4432:
	/* 0x4432: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4434:
	/* 0x4434: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4439:
	/* 0x4439: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_443e:
	/* 0x443e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4443:
	/* 0x4443: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4448:
	/* 0x4448: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444d:
	/* 0x444d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4452:
	/* 0x4452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4454:
	/* 0x4454: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4459:
	/* 0x4459: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_445d:
	/* 0x445d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4462:
	/* 0x4462: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4467:
	/* 0x4467: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_446c:
	/* 0x446c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4471:
	/* 0x4471: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4476:
	/* 0x4476: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_447b:
	/* 0x447b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_447d:
	/* 0x447d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4482:
	/* 0x4482: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4487:
	/* 0x4487: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_448b:
	/* 0x448b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4490:
	/* 0x4490: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4495:
	/* 0x4495: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_449a:
	/* 0x449a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_449f:
	/* 0x449f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a1:
	/* 0x44a1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44a6:
	/* 0x44a6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_44a9:
	/* 0x44a9: je     4678 <trace_ret_vfs_writev_tail+0x4678> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18040ULL;
	}
x86_l_44af:
	/* 0x44af: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44b4:
	/* 0x44b4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_44b7:
	/* 0x44b7: je     4678 <trace_ret_vfs_writev_tail+0x4678> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18040ULL;
	}
x86_l_44bd:
	/* 0x44bd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_44c1:
	/* 0x44c1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44c6:
	/* 0x44c6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_44cb:
	/* 0x44cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44d0:
	/* 0x44d0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44d5:
	/* 0x44d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d7:
	/* 0x44d7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_44db:
	/* 0x44db: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44dd:
	/* 0x44dd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44e3:
	/* 0x44e3: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_44e6:
	/* 0x44e6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44e8:
	/* 0x44e8: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_44ee:
	/* 0x44ee: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44f3:
	/* 0x44f3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_44f9:
	/* 0x44f9: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_44fe:
	/* 0x44fe: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4500:
	/* 0x4500: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4505:
	/* 0x4505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4507:
	/* 0x4507: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_450a:
	/* 0x450a: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_4510:
	/* 0x4510: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4514:
	/* 0x4514: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_451a:
	/* 0x451a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_451f:
	/* 0x451f: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4523:
	/* 0x4523: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4526:
	/* 0x4526: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_452b:
	/* 0x452b: jmp    4702 <trace_ret_vfs_writev_tail+0x4702> */
	return 18178ULL;
	return 17712ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17712ULL: goto x86_l_4530;
	case 17715ULL: goto x86_l_4533;
	case 17721ULL: goto x86_l_4539;
	case 17726ULL: goto x86_l_453e;
	case 17731ULL: goto x86_l_4543;
	case 17737ULL: goto x86_l_4549;
	case 17741ULL: goto x86_l_454d;
	case 17746ULL: goto x86_l_4552;
	case 17751ULL: goto x86_l_4557;
	case 17756ULL: goto x86_l_455c;
	case 17761ULL: goto x86_l_4561;
	case 17765ULL: goto x86_l_4565;
	case 17770ULL: goto x86_l_456a;
	case 17772ULL: goto x86_l_456c;
	case 17777ULL: goto x86_l_4571;
	case 17782ULL: goto x86_l_4576;
	case 17787ULL: goto x86_l_457b;
	case 17792ULL: goto x86_l_4580;
	case 17797ULL: goto x86_l_4585;
	case 17802ULL: goto x86_l_458a;
	case 17804ULL: goto x86_l_458c;
	case 17809ULL: goto x86_l_4591;
	case 17814ULL: goto x86_l_4596;
	case 17819ULL: goto x86_l_459b;
	case 17824ULL: goto x86_l_45a0;
	case 17829ULL: goto x86_l_45a5;
	case 17834ULL: goto x86_l_45aa;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17845ULL: goto x86_l_45b5;
	case 17850ULL: goto x86_l_45ba;
	case 17855ULL: goto x86_l_45bf;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17868ULL: goto x86_l_45cc;
	case 17870ULL: goto x86_l_45ce;
	case 17875ULL: goto x86_l_45d3;
	case 17880ULL: goto x86_l_45d8;
	case 17884ULL: goto x86_l_45dc;
	case 17889ULL: goto x86_l_45e1;
	case 17894ULL: goto x86_l_45e6;
	case 17899ULL: goto x86_l_45eb;
	case 17904ULL: goto x86_l_45f0;
	case 17906ULL: goto x86_l_45f2;
	case 17911ULL: goto x86_l_45f7;
	case 17914ULL: goto x86_l_45fa;
	case 17920ULL: goto x86_l_4600;
	case 17925ULL: goto x86_l_4605;
	case 17928ULL: goto x86_l_4608;
	case 17934ULL: goto x86_l_460e;
	case 17938ULL: goto x86_l_4612;
	case 17943ULL: goto x86_l_4617;
	case 17948ULL: goto x86_l_461c;
	case 17953ULL: goto x86_l_4621;
	case 17958ULL: goto x86_l_4626;
	case 17960ULL: goto x86_l_4628;
	case 17964ULL: goto x86_l_462c;
	case 17966ULL: goto x86_l_462e;
	case 17972ULL: goto x86_l_4634;
	case 17974ULL: goto x86_l_4636;
	case 17976ULL: goto x86_l_4638;
	case 17982ULL: goto x86_l_463e;
	case 17987ULL: goto x86_l_4643;
	case 17993ULL: goto x86_l_4649;
	case 17996ULL: goto x86_l_464c;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18005ULL: goto x86_l_4655;
	case 18008ULL: goto x86_l_4658;
	case 18014ULL: goto x86_l_465e;
	case 18017ULL: goto x86_l_4661;
	case 18023ULL: goto x86_l_4667;
	case 18028ULL: goto x86_l_466c;
	case 18030ULL: goto x86_l_466e;
	case 18035ULL: goto x86_l_4673;
	case 18040ULL: goto x86_l_4678;
	case 18043ULL: goto x86_l_467b;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18059ULL: goto x86_l_468b;
	case 18065ULL: goto x86_l_4691;
	case 18069ULL: goto x86_l_4695;
	case 18074ULL: goto x86_l_469a;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18093ULL: goto x86_l_46ad;
	case 18098ULL: goto x86_l_46b2;
	case 18100ULL: goto x86_l_46b4;
	case 18105ULL: goto x86_l_46b9;
	case 18110ULL: goto x86_l_46be;
	case 18115ULL: goto x86_l_46c3;
	case 18120ULL: goto x86_l_46c8;
	case 18125ULL: goto x86_l_46cd;
	case 18130ULL: goto x86_l_46d2;
	case 18132ULL: goto x86_l_46d4;
	case 18137ULL: goto x86_l_46d9;
	case 18142ULL: goto x86_l_46de;
	case 18147ULL: goto x86_l_46e3;
	case 18152ULL: goto x86_l_46e8;
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18164ULL: goto x86_l_46f4;
	case 18169ULL: goto x86_l_46f9;
	case 18173ULL: goto x86_l_46fd;
	case 18178ULL: goto x86_l_4702;
	case 18183ULL: goto x86_l_4707;
	case 18188ULL: goto x86_l_470c;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18205ULL: goto x86_l_471d;
	case 18210ULL: goto x86_l_4722;
	case 18215ULL: goto x86_l_4727;
	case 18219ULL: goto x86_l_472b;
	case 18224ULL: goto x86_l_4730;
	case 18229ULL: goto x86_l_4735;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18241ULL: goto x86_l_4741;
	case 18246ULL: goto x86_l_4746;
	case 18249ULL: goto x86_l_4749;
	case 18255ULL: goto x86_l_474f;
	case 18260ULL: goto x86_l_4754;
	case 18263ULL: goto x86_l_4757;
	case 18269ULL: goto x86_l_475d;
	case 18273ULL: goto x86_l_4761;
	case 18278ULL: goto x86_l_4766;
	case 18283ULL: goto x86_l_476b;
	case 18288ULL: goto x86_l_4770;
	case 18293ULL: goto x86_l_4775;
	case 18295ULL: goto x86_l_4777;
	case 18299ULL: goto x86_l_477b;
	case 18301ULL: goto x86_l_477d;
	case 18307ULL: goto x86_l_4783;
	case 18310ULL: goto x86_l_4786;
	case 18312ULL: goto x86_l_4788;
	case 18318ULL: goto x86_l_478e;
	case 18323ULL: goto x86_l_4793;
	case 18329ULL: goto x86_l_4799;
	case 18334ULL: goto x86_l_479e;
	case 18336ULL: goto x86_l_47a0;
	case 18341ULL: goto x86_l_47a5;
	case 18343ULL: goto x86_l_47a7;
	case 18346ULL: goto x86_l_47aa;
	case 18352ULL: goto x86_l_47b0;
	case 18356ULL: goto x86_l_47b4;
	case 18362ULL: goto x86_l_47ba;
	case 18367ULL: goto x86_l_47bf;
	case 18371ULL: goto x86_l_47c3;
	case 18374ULL: goto x86_l_47c6;
	case 18379ULL: goto x86_l_47cb;
	case 18384ULL: goto x86_l_47d0;
	case 18391ULL: goto x86_l_47d7;
	case 18394ULL: goto x86_l_47da;
	case 18399ULL: goto x86_l_47df;
	case 18402ULL: goto x86_l_47e2;
	case 18405ULL: goto x86_l_47e5;
	case 18407ULL: goto x86_l_47e7;
	case 18409ULL: goto x86_l_47e9;
	case 18414ULL: goto x86_l_47ee;
	case 18417ULL: goto x86_l_47f1;
	case 18424ULL: goto x86_l_47f8;
	case 18430ULL: goto x86_l_47fe;
	case 18435ULL: goto x86_l_4803;
	case 18438ULL: goto x86_l_4806;
	case 18444ULL: goto x86_l_480c;
	case 18449ULL: goto x86_l_4811;
	case 18454ULL: goto x86_l_4816;
	case 18460ULL: goto x86_l_481c;
	case 18464ULL: goto x86_l_4820;
	case 18469ULL: goto x86_l_4825;
	case 18474ULL: goto x86_l_482a;
	case 18479ULL: goto x86_l_482f;
	case 18484ULL: goto x86_l_4834;
	case 18488ULL: goto x86_l_4838;
	case 18493ULL: goto x86_l_483d;
	case 18495ULL: goto x86_l_483f;
	case 18500ULL: goto x86_l_4844;
	case 18505ULL: goto x86_l_4849;
	case 18510ULL: goto x86_l_484e;
	case 18515ULL: goto x86_l_4853;
	case 18520ULL: goto x86_l_4858;
	case 18525ULL: goto x86_l_485d;
	case 18527ULL: goto x86_l_485f;
	case 18532ULL: goto x86_l_4864;
	case 18537ULL: goto x86_l_4869;
	case 18542ULL: goto x86_l_486e;
	case 18547ULL: goto x86_l_4873;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18559ULL: goto x86_l_487f;
	case 18564ULL: goto x86_l_4884;
	case 18568ULL: goto x86_l_4888;
	case 18573ULL: goto x86_l_488d;
	case 18578ULL: goto x86_l_4892;
	case 18583ULL: goto x86_l_4897;
	case 18588ULL: goto x86_l_489c;
	case 18591ULL: goto x86_l_489f;
	case 18593ULL: goto x86_l_48a1;
	case 18598ULL: goto x86_l_48a6;
	case 18603ULL: goto x86_l_48ab;
	case 18607ULL: goto x86_l_48af;
	case 18612ULL: goto x86_l_48b4;
	case 18617ULL: goto x86_l_48b9;
	case 18622ULL: goto x86_l_48be;
	case 18627ULL: goto x86_l_48c3;
	case 18629ULL: goto x86_l_48c5;
	case 18634ULL: goto x86_l_48ca;
	case 18637ULL: goto x86_l_48cd;
	case 18643ULL: goto x86_l_48d3;
	case 18648ULL: goto x86_l_48d8;
	case 18651ULL: goto x86_l_48db;
	case 18657ULL: goto x86_l_48e1;
	case 18661ULL: goto x86_l_48e5;
	case 18666ULL: goto x86_l_48ea;
	case 18671ULL: goto x86_l_48ef;
	case 18676ULL: goto x86_l_48f4;
	case 18681ULL: goto x86_l_48f9;
	case 18683ULL: goto x86_l_48fb;
	case 18687ULL: goto x86_l_48ff;
	case 18689ULL: goto x86_l_4901;
	case 18695ULL: goto x86_l_4907;
	case 18697ULL: goto x86_l_4909;
	case 18699ULL: goto x86_l_490b;
	case 18705ULL: goto x86_l_4911;
	case 18710ULL: goto x86_l_4916;
	case 18716ULL: goto x86_l_491c;
	case 18719ULL: goto x86_l_491f;
	case 18721ULL: goto x86_l_4921;
	case 18726ULL: goto x86_l_4926;
	case 18728ULL: goto x86_l_4928;
	case 18731ULL: goto x86_l_492b;
	case 18737ULL: goto x86_l_4931;
	case 18740ULL: goto x86_l_4934;
	case 18746ULL: goto x86_l_493a;
	case 18751ULL: goto x86_l_493f;
	case 18753ULL: goto x86_l_4941;
	case 18758ULL: goto x86_l_4946;
	case 18763ULL: goto x86_l_494b;
	case 18770ULL: goto x86_l_4952;
	case 18772ULL: goto x86_l_4954;
	case 18777ULL: goto x86_l_4959;
	case 18782ULL: goto x86_l_495e;
	case 18785ULL: goto x86_l_4961;
	case 18788ULL: goto x86_l_4964;
	case 18790ULL: goto x86_l_4966;
	case 18792ULL: goto x86_l_4968;
	case 18797ULL: goto x86_l_496d;
	case 18800ULL: goto x86_l_4970;
	case 18806ULL: goto x86_l_4976;
	case 18812ULL: goto x86_l_497c;
	case 18817ULL: goto x86_l_4981;
	case 18824ULL: goto x86_l_4988;
	case 18826ULL: goto x86_l_498a;
	case 18831ULL: goto x86_l_498f;
	case 18836ULL: goto x86_l_4994;
	case 18839ULL: goto x86_l_4997;
	case 18842ULL: goto x86_l_499a;
	case 18844ULL: goto x86_l_499c;
	case 18846ULL: goto x86_l_499e;
	case 18851ULL: goto x86_l_49a3;
	case 18854ULL: goto x86_l_49a6;
	case 18860ULL: goto x86_l_49ac;
	case 18866ULL: goto x86_l_49b2;
	case 18871ULL: goto x86_l_49b7;
	case 18874ULL: goto x86_l_49ba;
	case 18880ULL: goto x86_l_49c0;
	case 18885ULL: goto x86_l_49c5;
	case 18890ULL: goto x86_l_49ca;
	case 18896ULL: goto x86_l_49d0;
	case 18900ULL: goto x86_l_49d4;
	case 18905ULL: goto x86_l_49d9;
	case 18910ULL: goto x86_l_49de;
	case 18915ULL: goto x86_l_49e3;
	case 18920ULL: goto x86_l_49e8;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18931ULL: goto x86_l_49f3;
	case 18936ULL: goto x86_l_49f8;
	case 18941ULL: goto x86_l_49fd;
	case 18946ULL: goto x86_l_4a02;
	case 18951ULL: goto x86_l_4a07;
	case 18956ULL: goto x86_l_4a0c;
	case 18961ULL: goto x86_l_4a11;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18973ULL: goto x86_l_4a1d;
	case 18978ULL: goto x86_l_4a22;
	case 18983ULL: goto x86_l_4a27;
	case 18988ULL: goto x86_l_4a2c;
	case 18993ULL: goto x86_l_4a31;
	case 18995ULL: goto x86_l_4a33;
	case 19000ULL: goto x86_l_4a38;
	case 19004ULL: goto x86_l_4a3c;
	case 19009ULL: goto x86_l_4a41;
	case 19014ULL: goto x86_l_4a46;
	case 19019ULL: goto x86_l_4a4b;
	case 19024ULL: goto x86_l_4a50;
	case 19029ULL: goto x86_l_4a55;
	case 19034ULL: goto x86_l_4a5a;
	case 19036ULL: goto x86_l_4a5c;
	case 19041ULL: goto x86_l_4a61;
	case 19046ULL: goto x86_l_4a66;
	case 19050ULL: goto x86_l_4a6a;
	case 19055ULL: goto x86_l_4a6f;
	case 19060ULL: goto x86_l_4a74;
	case 19065ULL: goto x86_l_4a79;
	case 19070ULL: goto x86_l_4a7e;
	case 19072ULL: goto x86_l_4a80;
	case 19077ULL: goto x86_l_4a85;
	case 19080ULL: goto x86_l_4a88;
	case 19086ULL: goto x86_l_4a8e;
	case 19091ULL: goto x86_l_4a93;
	case 19094ULL: goto x86_l_4a96;
	case 19100ULL: goto x86_l_4a9c;
	case 19104ULL: goto x86_l_4aa0;
	case 19109ULL: goto x86_l_4aa5;
	case 19114ULL: goto x86_l_4aaa;
	case 19119ULL: goto x86_l_4aaf;
	case 19124ULL: goto x86_l_4ab4;
	case 19126ULL: goto x86_l_4ab6;
	case 19130ULL: goto x86_l_4aba;
	case 19132ULL: goto x86_l_4abc;
	case 19138ULL: goto x86_l_4ac2;
	case 19141ULL: goto x86_l_4ac5;
	case 19143ULL: goto x86_l_4ac7;
	case 19149ULL: goto x86_l_4acd;
	case 19154ULL: goto x86_l_4ad2;
	case 19160ULL: goto x86_l_4ad8;
	case 19165ULL: goto x86_l_4add;
	case 19167ULL: goto x86_l_4adf;
	case 19172ULL: goto x86_l_4ae4;
	case 19174ULL: goto x86_l_4ae6;
	case 19177ULL: goto x86_l_4ae9;
	case 19183ULL: goto x86_l_4aef;
	case 19187ULL: goto x86_l_4af3;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19202ULL: goto x86_l_4b02;
	case 19205ULL: goto x86_l_4b05;
	case 19210ULL: goto x86_l_4b0a;
	case 19215ULL: goto x86_l_4b0f;
	case 19218ULL: goto x86_l_4b12;
	case 19224ULL: goto x86_l_4b18;
	case 19229ULL: goto x86_l_4b1d;
	case 19234ULL: goto x86_l_4b22;
	case 19240ULL: goto x86_l_4b28;
	case 19244ULL: goto x86_l_4b2c;
	case 19249ULL: goto x86_l_4b31;
	case 19254ULL: goto x86_l_4b36;
	case 19259ULL: goto x86_l_4b3b;
	case 19264ULL: goto x86_l_4b40;
	case 19268ULL: goto x86_l_4b44;
	case 19273ULL: goto x86_l_4b49;
	case 19275ULL: goto x86_l_4b4b;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19290ULL: goto x86_l_4b5a;
	case 19295ULL: goto x86_l_4b5f;
	case 19300ULL: goto x86_l_4b64;
	case 19305ULL: goto x86_l_4b69;
	case 19307ULL: goto x86_l_4b6b;
	case 19312ULL: goto x86_l_4b70;
	case 19317ULL: goto x86_l_4b75;
	case 19322ULL: goto x86_l_4b7a;
	case 19327ULL: goto x86_l_4b7f;
	case 19332ULL: goto x86_l_4b84;
	case 19337ULL: goto x86_l_4b89;
	case 19339ULL: goto x86_l_4b8b;
	case 19344ULL: goto x86_l_4b90;
	case 19348ULL: goto x86_l_4b94;
	case 19353ULL: goto x86_l_4b99;
	case 19358ULL: goto x86_l_4b9e;
	case 19363ULL: goto x86_l_4ba3;
	case 19368ULL: goto x86_l_4ba8;
	case 19371ULL: goto x86_l_4bab;
	case 19373ULL: goto x86_l_4bad;
	case 19378ULL: goto x86_l_4bb2;
	case 19383ULL: goto x86_l_4bb7;
	case 19387ULL: goto x86_l_4bbb;
	case 19392ULL: goto x86_l_4bc0;
	case 19397ULL: goto x86_l_4bc5;
	case 19402ULL: goto x86_l_4bca;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4530:
	/* 0x4530: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4533:
	/* 0x4533: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_4539:
	/* 0x4539: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_453e:
	/* 0x453e: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4543:
	/* 0x4543: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_4549:
	/* 0x4549: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_454d:
	/* 0x454d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4552:
	/* 0x4552: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4557:
	/* 0x4557: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_455c:
	/* 0x455c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4561:
	/* 0x4561: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4565:
	/* 0x4565: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_456a:
	/* 0x456a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456c:
	/* 0x456c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4571:
	/* 0x4571: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4576:
	/* 0x4576: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_457b:
	/* 0x457b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4580:
	/* 0x4580: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4585:
	/* 0x4585: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_458a:
	/* 0x458a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_458c:
	/* 0x458c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4591:
	/* 0x4591: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4596:
	/* 0x4596: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_459b:
	/* 0x459b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45a0:
	/* 0x45a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45a5:
	/* 0x45a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45aa:
	/* 0x45aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45ac:
	/* 0x45ac: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b1:
	/* 0x45b1: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45b5:
	/* 0x45b5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45ba:
	/* 0x45ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45bf:
	/* 0x45bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45c4:
	/* 0x45c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45c9:
	/* 0x45c9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_45cc:
	/* 0x45cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45ce:
	/* 0x45ce: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45d3:
	/* 0x45d3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45d8:
	/* 0x45d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_45dc:
	/* 0x45dc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45e1:
	/* 0x45e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45e6:
	/* 0x45e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45eb:
	/* 0x45eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45f0:
	/* 0x45f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f2:
	/* 0x45f2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45f7:
	/* 0x45f7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_45fa:
	/* 0x45fa: je     4803 <trace_ret_vfs_writev_tail+0x4803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4803;
	}
x86_l_4600:
	/* 0x4600: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4605:
	/* 0x4605: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4608:
	/* 0x4608: je     4803 <trace_ret_vfs_writev_tail+0x4803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4803;
	}
x86_l_460e:
	/* 0x460e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4612:
	/* 0x4612: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4617:
	/* 0x4617: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_461c:
	/* 0x461c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4621:
	/* 0x4621: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4626:
	/* 0x4626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4628:
	/* 0x4628: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_462c:
	/* 0x462c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_462e:
	/* 0x462e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4634:
	/* 0x4634: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4636:
	/* 0x4636: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4638:
	/* 0x4638: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_463e:
	/* 0x463e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4643:
	/* 0x4643: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4649:
	/* 0x4649: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_464c:
	/* 0x464c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_464e:
	/* 0x464e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4653:
	/* 0x4653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4655:
	/* 0x4655: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4658:
	/* 0x4658: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_465e:
	/* 0x465e: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4661:
	/* 0x4661: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4667:
	/* 0x4667: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_466c:
	/* 0x466c: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_466e:
	/* 0x466e: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4673:
	/* 0x4673: jmp    4888 <trace_ret_vfs_writev_tail+0x4888> */
	goto x86_l_4888;
x86_l_4678:
	/* 0x4678: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_467b:
	/* 0x467b: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_4681:
	/* 0x4681: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4686:
	/* 0x4686: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_468b:
	/* 0x468b: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_4691:
	/* 0x4691: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4695:
	/* 0x4695: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_469a:
	/* 0x469a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_469f:
	/* 0x469f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46a4:
	/* 0x46a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a9:
	/* 0x46a9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46ad:
	/* 0x46ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46b2:
	/* 0x46b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b4:
	/* 0x46b4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46b9:
	/* 0x46b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46be:
	/* 0x46be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46c3:
	/* 0x46c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46c8:
	/* 0x46c8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46cd:
	/* 0x46cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46d2:
	/* 0x46d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d4:
	/* 0x46d4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d9:
	/* 0x46d9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_46de:
	/* 0x46de: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46e3:
	/* 0x46e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46e8:
	/* 0x46e8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46ed:
	/* 0x46ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46f2:
	/* 0x46f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46f4:
	/* 0x46f4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46f9:
	/* 0x46f9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46fd:
	/* 0x46fd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4702:
	/* 0x4702: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4707:
	/* 0x4707: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_470c:
	/* 0x470c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4711:
	/* 0x4711: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4716:
	/* 0x4716: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_471b:
	/* 0x471b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471d:
	/* 0x471d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4722:
	/* 0x4722: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4727:
	/* 0x4727: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_472b:
	/* 0x472b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4730:
	/* 0x4730: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4735:
	/* 0x4735: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_473a:
	/* 0x473a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_473f:
	/* 0x473f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4741:
	/* 0x4741: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4746:
	/* 0x4746: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4749:
	/* 0x4749: je     49b7 <trace_ret_vfs_writev_tail+0x49b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49b7;
	}
x86_l_474f:
	/* 0x474f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4754:
	/* 0x4754: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4757:
	/* 0x4757: je     49b7 <trace_ret_vfs_writev_tail+0x49b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49b7;
	}
x86_l_475d:
	/* 0x475d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4761:
	/* 0x4761: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4766:
	/* 0x4766: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_476b:
	/* 0x476b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4770:
	/* 0x4770: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4775:
	/* 0x4775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4777:
	/* 0x4777: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_477b:
	/* 0x477b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_477d:
	/* 0x477d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4783:
	/* 0x4783: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4786:
	/* 0x4786: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4788:
	/* 0x4788: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_478e:
	/* 0x478e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4793:
	/* 0x4793: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4799:
	/* 0x4799: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_479e:
	/* 0x479e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_47a0:
	/* 0x47a0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_47a5:
	/* 0x47a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47a7:
	/* 0x47a7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_47aa:
	/* 0x47aa: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_47b0:
	/* 0x47b0: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_47b4:
	/* 0x47b4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_47ba:
	/* 0x47ba: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_47bf:
	/* 0x47bf: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_47c3:
	/* 0x47c3: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_47c6:
	/* 0x47c6: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_47cb:
	/* 0x47cb: jmp    4a41 <trace_ret_vfs_writev_tail+0x4a41> */
	goto x86_l_4a41;
x86_l_47d0:
	/* 0x47d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_47d7:
	/* 0x47d7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47da:
	/* 0x47da: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_47df:
	/* 0x47df: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_47e2:
	/* 0x47e2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_47e5:
	/* 0x47e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47e7:
	/* 0x47e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47e9:
	/* 0x47e9: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_47ee:
	/* 0x47ee: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_47f1:
	/* 0x47f1: cmp    rcx,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 2000000001ULL);
x86_l_47f8:
	/* 0x47f8: jae    3aa2 <trace_ret_vfs_writev_tail+0x3aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15010ULL;
	}
x86_l_47fe:
	/* 0x47fe: jmp    3adc <trace_ret_vfs_writev_tail+0x3adc> */
	return 15068ULL;
x86_l_4803:
	/* 0x4803: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4806:
	/* 0x4806: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_480c:
	/* 0x480c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4811:
	/* 0x4811: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4816:
	/* 0x4816: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_481c:
	/* 0x481c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4820:
	/* 0x4820: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4825:
	/* 0x4825: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_482a:
	/* 0x482a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_482f:
	/* 0x482f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4834:
	/* 0x4834: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4838:
	/* 0x4838: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_483d:
	/* 0x483d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483f:
	/* 0x483f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4844:
	/* 0x4844: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4849:
	/* 0x4849: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_484e:
	/* 0x484e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4853:
	/* 0x4853: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4858:
	/* 0x4858: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_485d:
	/* 0x485d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485f:
	/* 0x485f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4864:
	/* 0x4864: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4869:
	/* 0x4869: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_486e:
	/* 0x486e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4873:
	/* 0x4873: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4878:
	/* 0x4878: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_487d:
	/* 0x487d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_487f:
	/* 0x487f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4884:
	/* 0x4884: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4888:
	/* 0x4888: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_488d:
	/* 0x488d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4892:
	/* 0x4892: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4897:
	/* 0x4897: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_489c:
	/* 0x489c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_489f:
	/* 0x489f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48a1:
	/* 0x48a1: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48a6:
	/* 0x48a6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48ab:
	/* 0x48ab: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_48af:
	/* 0x48af: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48b4:
	/* 0x48b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48b9:
	/* 0x48b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48be:
	/* 0x48be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48c3:
	/* 0x48c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48c5:
	/* 0x48c5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48ca:
	/* 0x48ca: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_48cd:
	/* 0x48cd: je     4b0f <trace_ret_vfs_writev_tail+0x4b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b0f;
	}
x86_l_48d3:
	/* 0x48d3: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48d8:
	/* 0x48d8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_48db:
	/* 0x48db: je     4b0f <trace_ret_vfs_writev_tail+0x4b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b0f;
	}
x86_l_48e1:
	/* 0x48e1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48e5:
	/* 0x48e5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48ea:
	/* 0x48ea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_48ef:
	/* 0x48ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48f4:
	/* 0x48f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_48f9:
	/* 0x48f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48fb:
	/* 0x48fb: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_48ff:
	/* 0x48ff: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4901:
	/* 0x4901: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4907:
	/* 0x4907: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4909:
	/* 0x4909: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_490b:
	/* 0x490b: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_4911:
	/* 0x4911: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4916:
	/* 0x4916: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_491c:
	/* 0x491c: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_491f:
	/* 0x491f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4921:
	/* 0x4921: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4926:
	/* 0x4926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4928:
	/* 0x4928: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_492b:
	/* 0x492b: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_4931:
	/* 0x4931: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4934:
	/* 0x4934: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_493a:
	/* 0x493a: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_493f:
	/* 0x493f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4941:
	/* 0x4941: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4946:
	/* 0x4946: jmp    4b94 <trace_ret_vfs_writev_tail+0x4b94> */
	goto x86_l_4b94;
x86_l_494b:
	/* 0x494b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_4952:
	/* 0x4952: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4954:
	/* 0x4954: lea    rbp,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4959:
	/* 0x4959: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_495e:
	/* 0x495e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4961:
	/* 0x4961: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4964:
	/* 0x4964: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4966:
	/* 0x4966: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4968:
	/* 0x4968: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_496d:
	/* 0x496d: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4970:
	/* 0x4970: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_4976:
	/* 0x4976: jae    3675 <trace_ret_vfs_writev_tail+0x3675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13941ULL;
	}
x86_l_497c:
	/* 0x497c: jmp    36b1 <trace_ret_vfs_writev_tail+0x36b1> */
	return 14001ULL;
x86_l_4981:
	/* 0x4981: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&logs_count)));
x86_l_4988:
	/* 0x4988: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_498a:
	/* 0x498a: lea    rbp,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_498f:
	/* 0x498f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4994:
	/* 0x4994: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4997:
	/* 0x4997: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_499a:
	/* 0x499a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_499c:
	/* 0x499c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_499e:
	/* 0x499e: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_49a3:
	/* 0x49a3: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_49a6:
	/* 0x49a6: cmp    rax,0x77359401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2000000001ULL);
x86_l_49ac:
	/* 0x49ac: jae    3799 <trace_ret_vfs_writev_tail+0x3799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14233ULL;
	}
x86_l_49b2:
	/* 0x49b2: jmp    37d5 <trace_ret_vfs_writev_tail+0x37d5> */
	return 14293ULL;
x86_l_49b7:
	/* 0x49b7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_49ba:
	/* 0x49ba: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_49c0:
	/* 0x49c0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49c5:
	/* 0x49c5: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_49ca:
	/* 0x49ca: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_49d0:
	/* 0x49d0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49d4:
	/* 0x49d4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49d9:
	/* 0x49d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49de:
	/* 0x49de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49e3:
	/* 0x49e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e8:
	/* 0x49e8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49ec:
	/* 0x49ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49f1:
	/* 0x49f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f3:
	/* 0x49f3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f8:
	/* 0x49f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49fd:
	/* 0x49fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a02:
	/* 0x4a02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a07:
	/* 0x4a07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a0c:
	/* 0x4a0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a11:
	/* 0x4a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a13:
	/* 0x4a13: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a18:
	/* 0x4a18: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4a1d:
	/* 0x4a1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a22:
	/* 0x4a22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a27:
	/* 0x4a27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2c:
	/* 0x4a2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a31:
	/* 0x4a31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a33:
	/* 0x4a33: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a38:
	/* 0x4a38: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a3c:
	/* 0x4a3c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4a41:
	/* 0x4a41: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a46:
	/* 0x4a46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a4b:
	/* 0x4a4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a50:
	/* 0x4a50: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4a55:
	/* 0x4a55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a5a:
	/* 0x4a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5c:
	/* 0x4a5c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a61:
	/* 0x4a61: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a66:
	/* 0x4a66: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a6a:
	/* 0x4a6a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a6f:
	/* 0x4a6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a74:
	/* 0x4a74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a79:
	/* 0x4a79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a7e:
	/* 0x4a7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a80:
	/* 0x4a80: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a85:
	/* 0x4a85: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4a88:
	/* 0x4a88: je     4c57 <trace_ret_vfs_writev_tail+0x4c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19543ULL;
	}
x86_l_4a8e:
	/* 0x4a8e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a93:
	/* 0x4a93: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4a96:
	/* 0x4a96: je     4c57 <trace_ret_vfs_writev_tail+0x4c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19543ULL;
	}
x86_l_4a9c:
	/* 0x4a9c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4aa0:
	/* 0x4aa0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4aa5:
	/* 0x4aa5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4aaa:
	/* 0x4aaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4aaf:
	/* 0x4aaf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ab4:
	/* 0x4ab4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab6:
	/* 0x4ab6: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4aba:
	/* 0x4aba: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4abc:
	/* 0x4abc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ac2:
	/* 0x4ac2: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4ac5:
	/* 0x4ac5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ac7:
	/* 0x4ac7: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_4acd:
	/* 0x4acd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ad2:
	/* 0x4ad2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4ad8:
	/* 0x4ad8: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_4add:
	/* 0x4add: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4adf:
	/* 0x4adf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4ae4:
	/* 0x4ae4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae6:
	/* 0x4ae6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ae9:
	/* 0x4ae9: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_4aef:
	/* 0x4aef: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4af3:
	/* 0x4af3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4af9:
	/* 0x4af9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4afe:
	/* 0x4afe: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4b02:
	/* 0x4b02: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4b05:
	/* 0x4b05: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b0a:
	/* 0x4b0a: jmp    4ce1 <trace_ret_vfs_writev_tail+0x4ce1> */
	return 19681ULL;
x86_l_4b0f:
	/* 0x4b0f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4b12:
	/* 0x4b12: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_4b18:
	/* 0x4b18: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b1d:
	/* 0x4b1d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4b22:
	/* 0x4b22: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_4b28:
	/* 0x4b28: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b2c:
	/* 0x4b2c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b31:
	/* 0x4b31: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b36:
	/* 0x4b36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b3b:
	/* 0x4b3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b40:
	/* 0x4b40: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b44:
	/* 0x4b44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b49:
	/* 0x4b49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b4b:
	/* 0x4b4b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b50:
	/* 0x4b50: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b55:
	/* 0x4b55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b5a:
	/* 0x4b5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b5f:
	/* 0x4b5f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b64:
	/* 0x4b64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b69:
	/* 0x4b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6b:
	/* 0x4b6b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b70:
	/* 0x4b70: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b75:
	/* 0x4b75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b7a:
	/* 0x4b7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b7f:
	/* 0x4b7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b84:
	/* 0x4b84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b89:
	/* 0x4b89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b8b:
	/* 0x4b8b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b90:
	/* 0x4b90: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b94:
	/* 0x4b94: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b99:
	/* 0x4b99: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b9e:
	/* 0x4b9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ba3:
	/* 0x4ba3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ba8:
	/* 0x4ba8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4bab:
	/* 0x4bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bad:
	/* 0x4bad: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bb2:
	/* 0x4bb2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4bb7:
	/* 0x4bb7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4bbb:
	/* 0x4bbb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bc0:
	/* 0x4bc0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4bc5:
	/* 0x4bc5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bca:
	/* 0x4bca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 19407ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19407ULL: goto x86_l_4bcf;
	case 19409ULL: goto x86_l_4bd1;
	case 19414ULL: goto x86_l_4bd6;
	case 19417ULL: goto x86_l_4bd9;
	case 19423ULL: goto x86_l_4bdf;
	case 19428ULL: goto x86_l_4be4;
	case 19431ULL: goto x86_l_4be7;
	case 19437ULL: goto x86_l_4bed;
	case 19441ULL: goto x86_l_4bf1;
	case 19446ULL: goto x86_l_4bf6;
	case 19451ULL: goto x86_l_4bfb;
	case 19456ULL: goto x86_l_4c00;
	case 19461ULL: goto x86_l_4c05;
	case 19463ULL: goto x86_l_4c07;
	case 19467ULL: goto x86_l_4c0b;
	case 19469ULL: goto x86_l_4c0d;
	case 19475ULL: goto x86_l_4c13;
	case 19477ULL: goto x86_l_4c15;
	case 19479ULL: goto x86_l_4c17;
	case 19485ULL: goto x86_l_4c1d;
	case 19490ULL: goto x86_l_4c22;
	case 19496ULL: goto x86_l_4c28;
	case 19499ULL: goto x86_l_4c2b;
	case 19501ULL: goto x86_l_4c2d;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19511ULL: goto x86_l_4c37;
	case 19517ULL: goto x86_l_4c3d;
	case 19520ULL: goto x86_l_4c40;
	case 19526ULL: goto x86_l_4c46;
	case 19531ULL: goto x86_l_4c4b;
	case 19533ULL: goto x86_l_4c4d;
	case 19538ULL: goto x86_l_4c52;
	case 19543ULL: goto x86_l_4c57;
	case 19546ULL: goto x86_l_4c5a;
	case 19552ULL: goto x86_l_4c60;
	case 19557ULL: goto x86_l_4c65;
	case 19562ULL: goto x86_l_4c6a;
	case 19568ULL: goto x86_l_4c70;
	case 19572ULL: goto x86_l_4c74;
	case 19577ULL: goto x86_l_4c79;
	case 19582ULL: goto x86_l_4c7e;
	case 19587ULL: goto x86_l_4c83;
	case 19592ULL: goto x86_l_4c88;
	case 19596ULL: goto x86_l_4c8c;
	case 19601ULL: goto x86_l_4c91;
	case 19603ULL: goto x86_l_4c93;
	case 19608ULL: goto x86_l_4c98;
	case 19613ULL: goto x86_l_4c9d;
	case 19618ULL: goto x86_l_4ca2;
	case 19623ULL: goto x86_l_4ca7;
	case 19628ULL: goto x86_l_4cac;
	case 19633ULL: goto x86_l_4cb1;
	case 19635ULL: goto x86_l_4cb3;
	case 19640ULL: goto x86_l_4cb8;
	case 19645ULL: goto x86_l_4cbd;
	case 19650ULL: goto x86_l_4cc2;
	case 19655ULL: goto x86_l_4cc7;
	case 19660ULL: goto x86_l_4ccc;
	case 19665ULL: goto x86_l_4cd1;
	case 19667ULL: goto x86_l_4cd3;
	case 19672ULL: goto x86_l_4cd8;
	case 19676ULL: goto x86_l_4cdc;
	case 19681ULL: goto x86_l_4ce1;
	case 19686ULL: goto x86_l_4ce6;
	case 19691ULL: goto x86_l_4ceb;
	case 19696ULL: goto x86_l_4cf0;
	case 19701ULL: goto x86_l_4cf5;
	case 19706ULL: goto x86_l_4cfa;
	case 19708ULL: goto x86_l_4cfc;
	case 19713ULL: goto x86_l_4d01;
	case 19718ULL: goto x86_l_4d06;
	case 19722ULL: goto x86_l_4d0a;
	case 19727ULL: goto x86_l_4d0f;
	case 19732ULL: goto x86_l_4d14;
	case 19737ULL: goto x86_l_4d19;
	case 19742ULL: goto x86_l_4d1e;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19752ULL: goto x86_l_4d28;
	case 19758ULL: goto x86_l_4d2e;
	case 19763ULL: goto x86_l_4d33;
	case 19766ULL: goto x86_l_4d36;
	case 19772ULL: goto x86_l_4d3c;
	case 19776ULL: goto x86_l_4d40;
	case 19781ULL: goto x86_l_4d45;
	case 19786ULL: goto x86_l_4d4a;
	case 19791ULL: goto x86_l_4d4f;
	case 19796ULL: goto x86_l_4d54;
	case 19798ULL: goto x86_l_4d56;
	case 19802ULL: goto x86_l_4d5a;
	case 19804ULL: goto x86_l_4d5c;
	case 19810ULL: goto x86_l_4d62;
	case 19813ULL: goto x86_l_4d65;
	case 19815ULL: goto x86_l_4d67;
	case 19821ULL: goto x86_l_4d6d;
	case 19826ULL: goto x86_l_4d72;
	case 19832ULL: goto x86_l_4d78;
	case 19837ULL: goto x86_l_4d7d;
	case 19839ULL: goto x86_l_4d7f;
	case 19844ULL: goto x86_l_4d84;
	case 19846ULL: goto x86_l_4d86;
	case 19849ULL: goto x86_l_4d89;
	case 19855ULL: goto x86_l_4d8f;
	case 19859ULL: goto x86_l_4d93;
	case 19865ULL: goto x86_l_4d99;
	case 19870ULL: goto x86_l_4d9e;
	case 19874ULL: goto x86_l_4da2;
	case 19877ULL: goto x86_l_4da5;
	case 19882ULL: goto x86_l_4daa;
	case 19887ULL: goto x86_l_4daf;
	case 19890ULL: goto x86_l_4db2;
	case 19896ULL: goto x86_l_4db8;
	case 19901ULL: goto x86_l_4dbd;
	case 19906ULL: goto x86_l_4dc2;
	case 19912ULL: goto x86_l_4dc8;
	case 19916ULL: goto x86_l_4dcc;
	case 19921ULL: goto x86_l_4dd1;
	case 19926ULL: goto x86_l_4dd6;
	case 19931ULL: goto x86_l_4ddb;
	case 19936ULL: goto x86_l_4de0;
	case 19940ULL: goto x86_l_4de4;
	case 19945ULL: goto x86_l_4de9;
	case 19947ULL: goto x86_l_4deb;
	case 19952ULL: goto x86_l_4df0;
	case 19957ULL: goto x86_l_4df5;
	case 19962ULL: goto x86_l_4dfa;
	case 19967ULL: goto x86_l_4dff;
	case 19972ULL: goto x86_l_4e04;
	case 19977ULL: goto x86_l_4e09;
	case 19979ULL: goto x86_l_4e0b;
	case 19984ULL: goto x86_l_4e10;
	case 19989ULL: goto x86_l_4e15;
	case 19994ULL: goto x86_l_4e1a;
	case 19999ULL: goto x86_l_4e1f;
	case 20004ULL: goto x86_l_4e24;
	case 20009ULL: goto x86_l_4e29;
	case 20011ULL: goto x86_l_4e2b;
	case 20016ULL: goto x86_l_4e30;
	case 20020ULL: goto x86_l_4e34;
	case 20025ULL: goto x86_l_4e39;
	case 20030ULL: goto x86_l_4e3e;
	case 20035ULL: goto x86_l_4e43;
	case 20040ULL: goto x86_l_4e48;
	case 20043ULL: goto x86_l_4e4b;
	case 20045ULL: goto x86_l_4e4d;
	case 20050ULL: goto x86_l_4e52;
	case 20055ULL: goto x86_l_4e57;
	case 20059ULL: goto x86_l_4e5b;
	case 20064ULL: goto x86_l_4e60;
	case 20069ULL: goto x86_l_4e65;
	case 20074ULL: goto x86_l_4e6a;
	case 20079ULL: goto x86_l_4e6f;
	case 20081ULL: goto x86_l_4e71;
	case 20086ULL: goto x86_l_4e76;
	case 20089ULL: goto x86_l_4e79;
	case 20095ULL: goto x86_l_4e7f;
	case 20100ULL: goto x86_l_4e84;
	case 20103ULL: goto x86_l_4e87;
	case 20109ULL: goto x86_l_4e8d;
	case 20113ULL: goto x86_l_4e91;
	case 20118ULL: goto x86_l_4e96;
	case 20123ULL: goto x86_l_4e9b;
	case 20128ULL: goto x86_l_4ea0;
	case 20133ULL: goto x86_l_4ea5;
	case 20135ULL: goto x86_l_4ea7;
	case 20139ULL: goto x86_l_4eab;
	case 20141ULL: goto x86_l_4ead;
	case 20147ULL: goto x86_l_4eb3;
	case 20149ULL: goto x86_l_4eb5;
	case 20151ULL: goto x86_l_4eb7;
	case 20157ULL: goto x86_l_4ebd;
	case 20162ULL: goto x86_l_4ec2;
	case 20168ULL: goto x86_l_4ec8;
	case 20171ULL: goto x86_l_4ecb;
	case 20173ULL: goto x86_l_4ecd;
	case 20178ULL: goto x86_l_4ed2;
	case 20180ULL: goto x86_l_4ed4;
	case 20183ULL: goto x86_l_4ed7;
	case 20189ULL: goto x86_l_4edd;
	case 20192ULL: goto x86_l_4ee0;
	case 20198ULL: goto x86_l_4ee6;
	case 20203ULL: goto x86_l_4eeb;
	case 20205ULL: goto x86_l_4eed;
	case 20210ULL: goto x86_l_4ef2;
	case 20215ULL: goto x86_l_4ef7;
	case 20218ULL: goto x86_l_4efa;
	case 20224ULL: goto x86_l_4f00;
	case 20229ULL: goto x86_l_4f05;
	case 20234ULL: goto x86_l_4f0a;
	case 20240ULL: goto x86_l_4f10;
	case 20244ULL: goto x86_l_4f14;
	case 20249ULL: goto x86_l_4f19;
	case 20254ULL: goto x86_l_4f1e;
	case 20259ULL: goto x86_l_4f23;
	case 20264ULL: goto x86_l_4f28;
	case 20268ULL: goto x86_l_4f2c;
	case 20273ULL: goto x86_l_4f31;
	case 20275ULL: goto x86_l_4f33;
	case 20280ULL: goto x86_l_4f38;
	case 20285ULL: goto x86_l_4f3d;
	case 20290ULL: goto x86_l_4f42;
	case 20295ULL: goto x86_l_4f47;
	case 20300ULL: goto x86_l_4f4c;
	case 20305ULL: goto x86_l_4f51;
	case 20307ULL: goto x86_l_4f53;
	case 20312ULL: goto x86_l_4f58;
	case 20317ULL: goto x86_l_4f5d;
	case 20322ULL: goto x86_l_4f62;
	case 20327ULL: goto x86_l_4f67;
	case 20332ULL: goto x86_l_4f6c;
	case 20337ULL: goto x86_l_4f71;
	case 20339ULL: goto x86_l_4f73;
	case 20344ULL: goto x86_l_4f78;
	case 20348ULL: goto x86_l_4f7c;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20373ULL: goto x86_l_4f95;
	case 20378ULL: goto x86_l_4f9a;
	case 20380ULL: goto x86_l_4f9c;
	case 20385ULL: goto x86_l_4fa1;
	case 20390ULL: goto x86_l_4fa6;
	case 20394ULL: goto x86_l_4faa;
	case 20399ULL: goto x86_l_4faf;
	case 20404ULL: goto x86_l_4fb4;
	case 20409ULL: goto x86_l_4fb9;
	case 20414ULL: goto x86_l_4fbe;
	case 20416ULL: goto x86_l_4fc0;
	case 20421ULL: goto x86_l_4fc5;
	case 20424ULL: goto x86_l_4fc8;
	case 20430ULL: goto x86_l_4fce;
	case 20435ULL: goto x86_l_4fd3;
	case 20438ULL: goto x86_l_4fd6;
	case 20444ULL: goto x86_l_4fdc;
	case 20448ULL: goto x86_l_4fe0;
	case 20453ULL: goto x86_l_4fe5;
	case 20458ULL: goto x86_l_4fea;
	case 20463ULL: goto x86_l_4fef;
	case 20468ULL: goto x86_l_4ff4;
	case 20470ULL: goto x86_l_4ff6;
	case 20474ULL: goto x86_l_4ffa;
	case 20476ULL: goto x86_l_4ffc;
	case 20482ULL: goto x86_l_5002;
	case 20485ULL: goto x86_l_5005;
	case 20487ULL: goto x86_l_5007;
	case 20493ULL: goto x86_l_500d;
	case 20498ULL: goto x86_l_5012;
	case 20504ULL: goto x86_l_5018;
	case 20509ULL: goto x86_l_501d;
	case 20511ULL: goto x86_l_501f;
	case 20516ULL: goto x86_l_5024;
	case 20518ULL: goto x86_l_5026;
	case 20521ULL: goto x86_l_5029;
	case 20527ULL: goto x86_l_502f;
	case 20531ULL: goto x86_l_5033;
	case 20537ULL: goto x86_l_5039;
	case 20542ULL: goto x86_l_503e;
	case 20546ULL: goto x86_l_5042;
	case 20549ULL: goto x86_l_5045;
	case 20554ULL: goto x86_l_504a;
	case 20559ULL: goto x86_l_504f;
	case 20562ULL: goto x86_l_5052;
	case 20568ULL: goto x86_l_5058;
	case 20573ULL: goto x86_l_505d;
	case 20578ULL: goto x86_l_5062;
	case 20584ULL: goto x86_l_5068;
	case 20588ULL: goto x86_l_506c;
	case 20593ULL: goto x86_l_5071;
	case 20598ULL: goto x86_l_5076;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20612ULL: goto x86_l_5084;
	case 20617ULL: goto x86_l_5089;
	case 20619ULL: goto x86_l_508b;
	case 20624ULL: goto x86_l_5090;
	case 20629ULL: goto x86_l_5095;
	case 20634ULL: goto x86_l_509a;
	case 20639ULL: goto x86_l_509f;
	case 20644ULL: goto x86_l_50a4;
	case 20649ULL: goto x86_l_50a9;
	case 20651ULL: goto x86_l_50ab;
	case 20656ULL: goto x86_l_50b0;
	case 20661ULL: goto x86_l_50b5;
	case 20666ULL: goto x86_l_50ba;
	case 20671ULL: goto x86_l_50bf;
	case 20676ULL: goto x86_l_50c4;
	case 20681ULL: goto x86_l_50c9;
	case 20683ULL: goto x86_l_50cb;
	case 20688ULL: goto x86_l_50d0;
	case 20692ULL: goto x86_l_50d4;
	case 20697ULL: goto x86_l_50d9;
	case 20702ULL: goto x86_l_50de;
	case 20707ULL: goto x86_l_50e3;
	case 20712ULL: goto x86_l_50e8;
	case 20715ULL: goto x86_l_50eb;
	case 20717ULL: goto x86_l_50ed;
	case 20722ULL: goto x86_l_50f2;
	case 20727ULL: goto x86_l_50f7;
	case 20731ULL: goto x86_l_50fb;
	case 20736ULL: goto x86_l_5100;
	case 20741ULL: goto x86_l_5105;
	case 20746ULL: goto x86_l_510a;
	case 20751ULL: goto x86_l_510f;
	case 20753ULL: goto x86_l_5111;
	case 20758ULL: goto x86_l_5116;
	case 20761ULL: goto x86_l_5119;
	case 20767ULL: goto x86_l_511f;
	case 20772ULL: goto x86_l_5124;
	case 20775ULL: goto x86_l_5127;
	case 20781ULL: goto x86_l_512d;
	case 20785ULL: goto x86_l_5131;
	case 20790ULL: goto x86_l_5136;
	case 20795ULL: goto x86_l_513b;
	case 20800ULL: goto x86_l_5140;
	case 20805ULL: goto x86_l_5145;
	case 20807ULL: goto x86_l_5147;
	case 20811ULL: goto x86_l_514b;
	case 20813ULL: goto x86_l_514d;
	case 20819ULL: goto x86_l_5153;
	case 20821ULL: goto x86_l_5155;
	case 20823ULL: goto x86_l_5157;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20840ULL: goto x86_l_5168;
	case 20843ULL: goto x86_l_516b;
	case 20845ULL: goto x86_l_516d;
	case 20850ULL: goto x86_l_5172;
	case 20852ULL: goto x86_l_5174;
	case 20855ULL: goto x86_l_5177;
	case 20861ULL: goto x86_l_517d;
	case 20864ULL: goto x86_l_5180;
	case 20870ULL: goto x86_l_5186;
	case 20875ULL: goto x86_l_518b;
	case 20877ULL: goto x86_l_518d;
	case 20882ULL: goto x86_l_5192;
	case 20887ULL: goto x86_l_5197;
	case 20890ULL: goto x86_l_519a;
	case 20896ULL: goto x86_l_51a0;
	case 20901ULL: goto x86_l_51a5;
	case 20906ULL: goto x86_l_51aa;
	case 20912ULL: goto x86_l_51b0;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	case 20926ULL: goto x86_l_51be;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20940ULL: goto x86_l_51cc;
	case 20945ULL: goto x86_l_51d1;
	case 20947ULL: goto x86_l_51d3;
	case 20952ULL: goto x86_l_51d8;
	case 20957ULL: goto x86_l_51dd;
	case 20962ULL: goto x86_l_51e2;
	case 20967ULL: goto x86_l_51e7;
	case 20972ULL: goto x86_l_51ec;
	case 20977ULL: goto x86_l_51f1;
	case 20979ULL: goto x86_l_51f3;
	case 20984ULL: goto x86_l_51f8;
	case 20989ULL: goto x86_l_51fd;
	case 20994ULL: goto x86_l_5202;
	case 20999ULL: goto x86_l_5207;
	case 21004ULL: goto x86_l_520c;
	case 21009ULL: goto x86_l_5211;
	case 21011ULL: goto x86_l_5213;
	case 21016ULL: goto x86_l_5218;
	case 21020ULL: goto x86_l_521c;
	case 21025ULL: goto x86_l_5221;
	case 21030ULL: goto x86_l_5226;
	case 21035ULL: goto x86_l_522b;
	case 21040ULL: goto x86_l_5230;
	case 21045ULL: goto x86_l_5235;
	case 21050ULL: goto x86_l_523a;
	case 21052ULL: goto x86_l_523c;
	case 21057ULL: goto x86_l_5241;
	case 21062ULL: goto x86_l_5246;
	case 21066ULL: goto x86_l_524a;
	case 21071ULL: goto x86_l_524f;
	case 21076ULL: goto x86_l_5254;
	case 21081ULL: goto x86_l_5259;
	case 21086ULL: goto x86_l_525e;
	case 21088ULL: goto x86_l_5260;
	case 21093ULL: goto x86_l_5265;
	case 21096ULL: goto x86_l_5268;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4bcf:
	/* 0x4bcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd1:
	/* 0x4bd1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4bd6:
	/* 0x4bd6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4bd9:
	/* 0x4bd9: je     4daf <trace_ret_vfs_writev_tail+0x4daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4daf;
	}
x86_l_4bdf:
	/* 0x4bdf: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4be4:
	/* 0x4be4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4be7:
	/* 0x4be7: je     4daf <trace_ret_vfs_writev_tail+0x4daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4daf;
	}
x86_l_4bed:
	/* 0x4bed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4bf1:
	/* 0x4bf1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bf6:
	/* 0x4bf6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4bfb:
	/* 0x4bfb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c00:
	/* 0x4c00: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4c05:
	/* 0x4c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c07:
	/* 0x4c07: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4c0b:
	/* 0x4c0b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c0d:
	/* 0x4c0d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c13:
	/* 0x4c13: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4c15:
	/* 0x4c15: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c17:
	/* 0x4c17: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_4c1d:
	/* 0x4c1d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c22:
	/* 0x4c22: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4c28:
	/* 0x4c28: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c2b:
	/* 0x4c2b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4c2d:
	/* 0x4c2d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4c32:
	/* 0x4c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c34:
	/* 0x4c34: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c37:
	/* 0x4c37: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_4c3d:
	/* 0x4c3d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4c40:
	/* 0x4c40: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4c46:
	/* 0x4c46: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4c4b:
	/* 0x4c4b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c4d:
	/* 0x4c4d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4c52:
	/* 0x4c52: jmp    4e34 <trace_ret_vfs_writev_tail+0x4e34> */
	goto x86_l_4e34;
x86_l_4c57:
	/* 0x4c57: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4c5a:
	/* 0x4c5a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_4c60:
	/* 0x4c60: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c65:
	/* 0x4c65: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4c6a:
	/* 0x4c6a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_4c70:
	/* 0x4c70: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c74:
	/* 0x4c74: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4c79:
	/* 0x4c79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c7e:
	/* 0x4c7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c83:
	/* 0x4c83: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c88:
	/* 0x4c88: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c8c:
	/* 0x4c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c91:
	/* 0x4c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c93:
	/* 0x4c93: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c98:
	/* 0x4c98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9d:
	/* 0x4c9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ca2:
	/* 0x4ca2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ca7:
	/* 0x4ca7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cac:
	/* 0x4cac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb1:
	/* 0x4cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb3:
	/* 0x4cb3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cb8:
	/* 0x4cb8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4cbd:
	/* 0x4cbd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4cc2:
	/* 0x4cc2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cc7:
	/* 0x4cc7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ccc:
	/* 0x4ccc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cd1:
	/* 0x4cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd3:
	/* 0x4cd3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd8:
	/* 0x4cd8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4cdc:
	/* 0x4cdc: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4ce1:
	/* 0x4ce1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce6:
	/* 0x4ce6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ceb:
	/* 0x4ceb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4cf0:
	/* 0x4cf0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4cf5:
	/* 0x4cf5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cfa:
	/* 0x4cfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cfc:
	/* 0x4cfc: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d01:
	/* 0x4d01: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d06:
	/* 0x4d06: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d0a:
	/* 0x4d0a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d0f:
	/* 0x4d0f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d14:
	/* 0x4d14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d19:
	/* 0x4d19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d1e:
	/* 0x4d1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d20:
	/* 0x4d20: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d25:
	/* 0x4d25: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4d28:
	/* 0x4d28: je     4ef7 <trace_ret_vfs_writev_tail+0x4ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ef7;
	}
x86_l_4d2e:
	/* 0x4d2e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d33:
	/* 0x4d33: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4d36:
	/* 0x4d36: je     4ef7 <trace_ret_vfs_writev_tail+0x4ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ef7;
	}
x86_l_4d3c:
	/* 0x4d3c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d40:
	/* 0x4d40: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d45:
	/* 0x4d45: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4d4a:
	/* 0x4d4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d4f:
	/* 0x4d4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4d54:
	/* 0x4d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d56:
	/* 0x4d56: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4d5a:
	/* 0x4d5a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4d5c:
	/* 0x4d5c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d62:
	/* 0x4d62: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4d65:
	/* 0x4d65: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d67:
	/* 0x4d67: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_4d6d:
	/* 0x4d6d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d72:
	/* 0x4d72: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4d78:
	/* 0x4d78: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_4d7d:
	/* 0x4d7d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4d7f:
	/* 0x4d7f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4d84:
	/* 0x4d84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d86:
	/* 0x4d86: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d89:
	/* 0x4d89: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_4d8f:
	/* 0x4d8f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4d93:
	/* 0x4d93: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4d99:
	/* 0x4d99: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d9e:
	/* 0x4d9e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4da2:
	/* 0x4da2: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4da5:
	/* 0x4da5: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4daa:
	/* 0x4daa: jmp    4f81 <trace_ret_vfs_writev_tail+0x4f81> */
	goto x86_l_4f81;
x86_l_4daf:
	/* 0x4daf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4db2:
	/* 0x4db2: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_4db8:
	/* 0x4db8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dbd:
	/* 0x4dbd: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4dc2:
	/* 0x4dc2: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_4dc8:
	/* 0x4dc8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4dcc:
	/* 0x4dcc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4dd1:
	/* 0x4dd1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4dd6:
	/* 0x4dd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ddb:
	/* 0x4ddb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de0:
	/* 0x4de0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4de4:
	/* 0x4de4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4de9:
	/* 0x4de9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4deb:
	/* 0x4deb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4df0:
	/* 0x4df0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4df5:
	/* 0x4df5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4dfa:
	/* 0x4dfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4dff:
	/* 0x4dff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e04:
	/* 0x4e04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e09:
	/* 0x4e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e0b:
	/* 0x4e0b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e10:
	/* 0x4e10: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4e15:
	/* 0x4e15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e1a:
	/* 0x4e1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e1f:
	/* 0x4e1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e24:
	/* 0x4e24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e29:
	/* 0x4e29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2b:
	/* 0x4e2b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e30:
	/* 0x4e30: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e34:
	/* 0x4e34: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e39:
	/* 0x4e39: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e3e:
	/* 0x4e3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e43:
	/* 0x4e43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e48:
	/* 0x4e48: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4e4b:
	/* 0x4e4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4d:
	/* 0x4e4d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e52:
	/* 0x4e52: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4e57:
	/* 0x4e57: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e5b:
	/* 0x4e5b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e60:
	/* 0x4e60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e65:
	/* 0x4e65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e6a:
	/* 0x4e6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e6f:
	/* 0x4e6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e71:
	/* 0x4e71: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4e76:
	/* 0x4e76: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4e79:
	/* 0x4e79: je     504f <trace_ret_vfs_writev_tail+0x504f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_504f;
	}
x86_l_4e7f:
	/* 0x4e7f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e84:
	/* 0x4e84: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4e87:
	/* 0x4e87: je     504f <trace_ret_vfs_writev_tail+0x504f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_504f;
	}
x86_l_4e8d:
	/* 0x4e8d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e91:
	/* 0x4e91: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e96:
	/* 0x4e96: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4e9b:
	/* 0x4e9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ea0:
	/* 0x4ea0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ea5:
	/* 0x4ea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ea7:
	/* 0x4ea7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4eab:
	/* 0x4eab: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4ead:
	/* 0x4ead: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4eb3:
	/* 0x4eb3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4eb5:
	/* 0x4eb5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4eb7:
	/* 0x4eb7: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_4ebd:
	/* 0x4ebd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ec2:
	/* 0x4ec2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4ec8:
	/* 0x4ec8: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ecb:
	/* 0x4ecb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4ecd:
	/* 0x4ecd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4ed2:
	/* 0x4ed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ed4:
	/* 0x4ed4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ed7:
	/* 0x4ed7: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_4edd:
	/* 0x4edd: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ee0:
	/* 0x4ee0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4ee6:
	/* 0x4ee6: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4eeb:
	/* 0x4eeb: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4eed:
	/* 0x4eed: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ef2:
	/* 0x4ef2: jmp    50d4 <trace_ret_vfs_writev_tail+0x50d4> */
	goto x86_l_50d4;
x86_l_4ef7:
	/* 0x4ef7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4efa:
	/* 0x4efa: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_4f00:
	/* 0x4f00: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f05:
	/* 0x4f05: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_4f0a:
	/* 0x4f0a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_4f10:
	/* 0x4f10: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f14:
	/* 0x4f14: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f19:
	/* 0x4f19: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f1e:
	/* 0x4f1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f23:
	/* 0x4f23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f28:
	/* 0x4f28: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f2c:
	/* 0x4f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f31:
	/* 0x4f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f33:
	/* 0x4f33: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f38:
	/* 0x4f38: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f3d:
	/* 0x4f3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f42:
	/* 0x4f42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f47:
	/* 0x4f47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f4c:
	/* 0x4f4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f51:
	/* 0x4f51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f53:
	/* 0x4f53: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f58:
	/* 0x4f58: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4f5d:
	/* 0x4f5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f62:
	/* 0x4f62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f67:
	/* 0x4f67: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f6c:
	/* 0x4f6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f71:
	/* 0x4f71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f73:
	/* 0x4f73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f78:
	/* 0x4f78: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f7c:
	/* 0x4f7c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4f81:
	/* 0x4f81: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f86:
	/* 0x4f86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f8b:
	/* 0x4f8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f90:
	/* 0x4f90: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4f95:
	/* 0x4f95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f9a:
	/* 0x4f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f9c:
	/* 0x4f9c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fa1:
	/* 0x4fa1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4fa6:
	/* 0x4fa6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4faa:
	/* 0x4faa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4faf:
	/* 0x4faf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4fb4:
	/* 0x4fb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fb9:
	/* 0x4fb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fbe:
	/* 0x4fbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fc0:
	/* 0x4fc0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4fc5:
	/* 0x4fc5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4fc8:
	/* 0x4fc8: je     5197 <trace_ret_vfs_writev_tail+0x5197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5197;
	}
x86_l_4fce:
	/* 0x4fce: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fd3:
	/* 0x4fd3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4fd6:
	/* 0x4fd6: je     5197 <trace_ret_vfs_writev_tail+0x5197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5197;
	}
x86_l_4fdc:
	/* 0x4fdc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4fe0:
	/* 0x4fe0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fe5:
	/* 0x4fe5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4fea:
	/* 0x4fea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fef:
	/* 0x4fef: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ff4:
	/* 0x4ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff6:
	/* 0x4ff6: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4ffa:
	/* 0x4ffa: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4ffc:
	/* 0x4ffc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5002:
	/* 0x5002: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5005:
	/* 0x5005: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5007:
	/* 0x5007: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_500d:
	/* 0x500d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5012:
	/* 0x5012: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5018:
	/* 0x5018: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_501d:
	/* 0x501d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_501f:
	/* 0x501f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5024:
	/* 0x5024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5026:
	/* 0x5026: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5029:
	/* 0x5029: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_502f:
	/* 0x502f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5033:
	/* 0x5033: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5039:
	/* 0x5039: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_503e:
	/* 0x503e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5042:
	/* 0x5042: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5045:
	/* 0x5045: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_504a:
	/* 0x504a: jmp    5221 <trace_ret_vfs_writev_tail+0x5221> */
	goto x86_l_5221;
x86_l_504f:
	/* 0x504f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5052:
	/* 0x5052: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_5058:
	/* 0x5058: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_505d:
	/* 0x505d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5062:
	/* 0x5062: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_5068:
	/* 0x5068: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_506c:
	/* 0x506c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5071:
	/* 0x5071: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5076:
	/* 0x5076: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_507b:
	/* 0x507b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5080:
	/* 0x5080: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5084:
	/* 0x5084: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5089:
	/* 0x5089: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508b:
	/* 0x508b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5090:
	/* 0x5090: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5095:
	/* 0x5095: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_509a:
	/* 0x509a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_509f:
	/* 0x509f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50a4:
	/* 0x50a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50a9:
	/* 0x50a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50ab:
	/* 0x50ab: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50b0:
	/* 0x50b0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_50b5:
	/* 0x50b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50ba:
	/* 0x50ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50bf:
	/* 0x50bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50c4:
	/* 0x50c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50c9:
	/* 0x50c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50cb:
	/* 0x50cb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d0:
	/* 0x50d0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50d4:
	/* 0x50d4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50d9:
	/* 0x50d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50de:
	/* 0x50de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50e3:
	/* 0x50e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e8:
	/* 0x50e8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_50eb:
	/* 0x50eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50ed:
	/* 0x50ed: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50f2:
	/* 0x50f2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_50f7:
	/* 0x50f7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_50fb:
	/* 0x50fb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5100:
	/* 0x5100: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5105:
	/* 0x5105: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_510a:
	/* 0x510a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_510f:
	/* 0x510f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5111:
	/* 0x5111: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5116:
	/* 0x5116: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5119:
	/* 0x5119: je     52ef <trace_ret_vfs_writev_tail+0x52ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21231ULL;
	}
x86_l_511f:
	/* 0x511f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5124:
	/* 0x5124: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5127:
	/* 0x5127: je     52ef <trace_ret_vfs_writev_tail+0x52ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21231ULL;
	}
x86_l_512d:
	/* 0x512d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5131:
	/* 0x5131: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5136:
	/* 0x5136: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_513b:
	/* 0x513b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5140:
	/* 0x5140: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5145:
	/* 0x5145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5147:
	/* 0x5147: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_514b:
	/* 0x514b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_514d:
	/* 0x514d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5153:
	/* 0x5153: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5155:
	/* 0x5155: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5157:
	/* 0x5157: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_515d:
	/* 0x515d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5162:
	/* 0x5162: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5168:
	/* 0x5168: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_516b:
	/* 0x516b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_516d:
	/* 0x516d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5172:
	/* 0x5172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5174:
	/* 0x5174: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5177:
	/* 0x5177: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_517d:
	/* 0x517d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5180:
	/* 0x5180: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5186:
	/* 0x5186: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_518b:
	/* 0x518b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_518d:
	/* 0x518d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5192:
	/* 0x5192: jmp    5374 <trace_ret_vfs_writev_tail+0x5374> */
	return 21364ULL;
x86_l_5197:
	/* 0x5197: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_519a:
	/* 0x519a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_51a0:
	/* 0x51a0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a5:
	/* 0x51a5: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_51aa:
	/* 0x51aa: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_51b0:
	/* 0x51b0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51b4:
	/* 0x51b4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_51b9:
	/* 0x51b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51be:
	/* 0x51be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51c3:
	/* 0x51c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c8:
	/* 0x51c8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51cc:
	/* 0x51cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51d1:
	/* 0x51d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d3:
	/* 0x51d3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d8:
	/* 0x51d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51dd:
	/* 0x51dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51e2:
	/* 0x51e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51e7:
	/* 0x51e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51ec:
	/* 0x51ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51f1:
	/* 0x51f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51f3:
	/* 0x51f3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51f8:
	/* 0x51f8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_51fd:
	/* 0x51fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5202:
	/* 0x5202: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5207:
	/* 0x5207: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_520c:
	/* 0x520c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5211:
	/* 0x5211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5213:
	/* 0x5213: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5218:
	/* 0x5218: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_521c:
	/* 0x521c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5221:
	/* 0x5221: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5226:
	/* 0x5226: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_522b:
	/* 0x522b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5230:
	/* 0x5230: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5235:
	/* 0x5235: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_523a:
	/* 0x523a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_523c:
	/* 0x523c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5241:
	/* 0x5241: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5246:
	/* 0x5246: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_524a:
	/* 0x524a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_524f:
	/* 0x524f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5254:
	/* 0x5254: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5259:
	/* 0x5259: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525e:
	/* 0x525e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5260:
	/* 0x5260: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5265:
	/* 0x5265: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5268:
	/* 0x5268: je     5437 <trace_ret_vfs_writev_tail+0x5437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21559ULL;
	}
	return 21102ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21102ULL: goto x86_l_526e;
	case 21107ULL: goto x86_l_5273;
	case 21110ULL: goto x86_l_5276;
	case 21116ULL: goto x86_l_527c;
	case 21120ULL: goto x86_l_5280;
	case 21125ULL: goto x86_l_5285;
	case 21130ULL: goto x86_l_528a;
	case 21135ULL: goto x86_l_528f;
	case 21140ULL: goto x86_l_5294;
	case 21142ULL: goto x86_l_5296;
	case 21146ULL: goto x86_l_529a;
	case 21148ULL: goto x86_l_529c;
	case 21154ULL: goto x86_l_52a2;
	case 21157ULL: goto x86_l_52a5;
	case 21159ULL: goto x86_l_52a7;
	case 21165ULL: goto x86_l_52ad;
	case 21170ULL: goto x86_l_52b2;
	case 21176ULL: goto x86_l_52b8;
	case 21181ULL: goto x86_l_52bd;
	case 21183ULL: goto x86_l_52bf;
	case 21188ULL: goto x86_l_52c4;
	case 21190ULL: goto x86_l_52c6;
	case 21193ULL: goto x86_l_52c9;
	case 21199ULL: goto x86_l_52cf;
	case 21203ULL: goto x86_l_52d3;
	case 21209ULL: goto x86_l_52d9;
	case 21214ULL: goto x86_l_52de;
	case 21218ULL: goto x86_l_52e2;
	case 21221ULL: goto x86_l_52e5;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21234ULL: goto x86_l_52f2;
	case 21240ULL: goto x86_l_52f8;
	case 21245ULL: goto x86_l_52fd;
	case 21250ULL: goto x86_l_5302;
	case 21256ULL: goto x86_l_5308;
	case 21260ULL: goto x86_l_530c;
	case 21265ULL: goto x86_l_5311;
	case 21270ULL: goto x86_l_5316;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21284ULL: goto x86_l_5324;
	case 21289ULL: goto x86_l_5329;
	case 21291ULL: goto x86_l_532b;
	case 21296ULL: goto x86_l_5330;
	case 21301ULL: goto x86_l_5335;
	case 21306ULL: goto x86_l_533a;
	case 21311ULL: goto x86_l_533f;
	case 21316ULL: goto x86_l_5344;
	case 21321ULL: goto x86_l_5349;
	case 21323ULL: goto x86_l_534b;
	case 21328ULL: goto x86_l_5350;
	case 21333ULL: goto x86_l_5355;
	case 21338ULL: goto x86_l_535a;
	case 21343ULL: goto x86_l_535f;
	case 21348ULL: goto x86_l_5364;
	case 21353ULL: goto x86_l_5369;
	case 21355ULL: goto x86_l_536b;
	case 21360ULL: goto x86_l_5370;
	case 21364ULL: goto x86_l_5374;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21384ULL: goto x86_l_5388;
	case 21387ULL: goto x86_l_538b;
	case 21389ULL: goto x86_l_538d;
	case 21394ULL: goto x86_l_5392;
	case 21399ULL: goto x86_l_5397;
	case 21403ULL: goto x86_l_539b;
	case 21408ULL: goto x86_l_53a0;
	case 21413ULL: goto x86_l_53a5;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21425ULL: goto x86_l_53b1;
	case 21430ULL: goto x86_l_53b6;
	case 21433ULL: goto x86_l_53b9;
	case 21439ULL: goto x86_l_53bf;
	case 21444ULL: goto x86_l_53c4;
	case 21447ULL: goto x86_l_53c7;
	case 21453ULL: goto x86_l_53cd;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21467ULL: goto x86_l_53db;
	case 21472ULL: goto x86_l_53e0;
	case 21477ULL: goto x86_l_53e5;
	case 21479ULL: goto x86_l_53e7;
	case 21483ULL: goto x86_l_53eb;
	case 21485ULL: goto x86_l_53ed;
	case 21491ULL: goto x86_l_53f3;
	case 21493ULL: goto x86_l_53f5;
	case 21495ULL: goto x86_l_53f7;
	case 21501ULL: goto x86_l_53fd;
	case 21506ULL: goto x86_l_5402;
	case 21512ULL: goto x86_l_5408;
	case 21515ULL: goto x86_l_540b;
	case 21517ULL: goto x86_l_540d;
	case 21522ULL: goto x86_l_5412;
	case 21524ULL: goto x86_l_5414;
	case 21527ULL: goto x86_l_5417;
	case 21533ULL: goto x86_l_541d;
	case 21536ULL: goto x86_l_5420;
	case 21542ULL: goto x86_l_5426;
	case 21547ULL: goto x86_l_542b;
	case 21549ULL: goto x86_l_542d;
	case 21554ULL: goto x86_l_5432;
	case 21559ULL: goto x86_l_5437;
	case 21562ULL: goto x86_l_543a;
	case 21568ULL: goto x86_l_5440;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21584ULL: goto x86_l_5450;
	case 21588ULL: goto x86_l_5454;
	case 21593ULL: goto x86_l_5459;
	case 21598ULL: goto x86_l_545e;
	case 21603ULL: goto x86_l_5463;
	case 21608ULL: goto x86_l_5468;
	case 21612ULL: goto x86_l_546c;
	case 21617ULL: goto x86_l_5471;
	case 21619ULL: goto x86_l_5473;
	case 21624ULL: goto x86_l_5478;
	case 21629ULL: goto x86_l_547d;
	case 21634ULL: goto x86_l_5482;
	case 21639ULL: goto x86_l_5487;
	case 21644ULL: goto x86_l_548c;
	case 21649ULL: goto x86_l_5491;
	case 21651ULL: goto x86_l_5493;
	case 21656ULL: goto x86_l_5498;
	case 21661ULL: goto x86_l_549d;
	case 21666ULL: goto x86_l_54a2;
	case 21671ULL: goto x86_l_54a7;
	case 21676ULL: goto x86_l_54ac;
	case 21681ULL: goto x86_l_54b1;
	case 21683ULL: goto x86_l_54b3;
	case 21688ULL: goto x86_l_54b8;
	case 21692ULL: goto x86_l_54bc;
	case 21697ULL: goto x86_l_54c1;
	case 21702ULL: goto x86_l_54c6;
	case 21707ULL: goto x86_l_54cb;
	case 21712ULL: goto x86_l_54d0;
	case 21717ULL: goto x86_l_54d5;
	case 21722ULL: goto x86_l_54da;
	case 21724ULL: goto x86_l_54dc;
	case 21729ULL: goto x86_l_54e1;
	case 21734ULL: goto x86_l_54e6;
	case 21738ULL: goto x86_l_54ea;
	case 21743ULL: goto x86_l_54ef;
	case 21748ULL: goto x86_l_54f4;
	case 21753ULL: goto x86_l_54f9;
	case 21758ULL: goto x86_l_54fe;
	case 21760ULL: goto x86_l_5500;
	case 21765ULL: goto x86_l_5505;
	case 21768ULL: goto x86_l_5508;
	case 21774ULL: goto x86_l_550e;
	case 21779ULL: goto x86_l_5513;
	case 21782ULL: goto x86_l_5516;
	case 21788ULL: goto x86_l_551c;
	case 21792ULL: goto x86_l_5520;
	case 21797ULL: goto x86_l_5525;
	case 21802ULL: goto x86_l_552a;
	case 21807ULL: goto x86_l_552f;
	case 21812ULL: goto x86_l_5534;
	case 21814ULL: goto x86_l_5536;
	case 21818ULL: goto x86_l_553a;
	case 21820ULL: goto x86_l_553c;
	case 21826ULL: goto x86_l_5542;
	case 21829ULL: goto x86_l_5545;
	case 21831ULL: goto x86_l_5547;
	case 21837ULL: goto x86_l_554d;
	case 21842ULL: goto x86_l_5552;
	case 21848ULL: goto x86_l_5558;
	case 21853ULL: goto x86_l_555d;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21862ULL: goto x86_l_5566;
	case 21865ULL: goto x86_l_5569;
	case 21871ULL: goto x86_l_556f;
	case 21875ULL: goto x86_l_5573;
	case 21881ULL: goto x86_l_5579;
	case 21886ULL: goto x86_l_557e;
	case 21890ULL: goto x86_l_5582;
	case 21893ULL: goto x86_l_5585;
	case 21898ULL: goto x86_l_558a;
	case 21903ULL: goto x86_l_558f;
	case 21906ULL: goto x86_l_5592;
	case 21912ULL: goto x86_l_5598;
	case 21917ULL: goto x86_l_559d;
	case 21922ULL: goto x86_l_55a2;
	case 21928ULL: goto x86_l_55a8;
	case 21932ULL: goto x86_l_55ac;
	case 21937ULL: goto x86_l_55b1;
	case 21942ULL: goto x86_l_55b6;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21956ULL: goto x86_l_55c4;
	case 21961ULL: goto x86_l_55c9;
	case 21963ULL: goto x86_l_55cb;
	case 21968ULL: goto x86_l_55d0;
	case 21973ULL: goto x86_l_55d5;
	case 21978ULL: goto x86_l_55da;
	case 21983ULL: goto x86_l_55df;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21995ULL: goto x86_l_55eb;
	case 22000ULL: goto x86_l_55f0;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22015ULL: goto x86_l_55ff;
	case 22020ULL: goto x86_l_5604;
	case 22025ULL: goto x86_l_5609;
	case 22027ULL: goto x86_l_560b;
	case 22032ULL: goto x86_l_5610;
	case 22036ULL: goto x86_l_5614;
	case 22041ULL: goto x86_l_5619;
	case 22046ULL: goto x86_l_561e;
	case 22051ULL: goto x86_l_5623;
	case 22056ULL: goto x86_l_5628;
	case 22059ULL: goto x86_l_562b;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22075ULL: goto x86_l_563b;
	case 22080ULL: goto x86_l_5640;
	case 22085ULL: goto x86_l_5645;
	case 22090ULL: goto x86_l_564a;
	case 22095ULL: goto x86_l_564f;
	case 22097ULL: goto x86_l_5651;
	case 22102ULL: goto x86_l_5656;
	case 22105ULL: goto x86_l_5659;
	case 22111ULL: goto x86_l_565f;
	case 22116ULL: goto x86_l_5664;
	case 22119ULL: goto x86_l_5667;
	case 22125ULL: goto x86_l_566d;
	case 22129ULL: goto x86_l_5671;
	case 22134ULL: goto x86_l_5676;
	case 22139ULL: goto x86_l_567b;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22151ULL: goto x86_l_5687;
	case 22155ULL: goto x86_l_568b;
	case 22157ULL: goto x86_l_568d;
	case 22163ULL: goto x86_l_5693;
	case 22165ULL: goto x86_l_5695;
	case 22167ULL: goto x86_l_5697;
	case 22173ULL: goto x86_l_569d;
	case 22178ULL: goto x86_l_56a2;
	case 22184ULL: goto x86_l_56a8;
	case 22187ULL: goto x86_l_56ab;
	case 22189ULL: goto x86_l_56ad;
	case 22194ULL: goto x86_l_56b2;
	case 22196ULL: goto x86_l_56b4;
	case 22199ULL: goto x86_l_56b7;
	case 22205ULL: goto x86_l_56bd;
	case 22208ULL: goto x86_l_56c0;
	case 22214ULL: goto x86_l_56c6;
	case 22219ULL: goto x86_l_56cb;
	case 22221ULL: goto x86_l_56cd;
	case 22226ULL: goto x86_l_56d2;
	case 22231ULL: goto x86_l_56d7;
	case 22234ULL: goto x86_l_56da;
	case 22240ULL: goto x86_l_56e0;
	case 22245ULL: goto x86_l_56e5;
	case 22250ULL: goto x86_l_56ea;
	case 22256ULL: goto x86_l_56f0;
	case 22260ULL: goto x86_l_56f4;
	case 22265ULL: goto x86_l_56f9;
	case 22270ULL: goto x86_l_56fe;
	case 22275ULL: goto x86_l_5703;
	case 22280ULL: goto x86_l_5708;
	case 22284ULL: goto x86_l_570c;
	case 22289ULL: goto x86_l_5711;
	case 22291ULL: goto x86_l_5713;
	case 22296ULL: goto x86_l_5718;
	case 22301ULL: goto x86_l_571d;
	case 22306ULL: goto x86_l_5722;
	case 22311ULL: goto x86_l_5727;
	case 22316ULL: goto x86_l_572c;
	case 22321ULL: goto x86_l_5731;
	case 22323ULL: goto x86_l_5733;
	case 22328ULL: goto x86_l_5738;
	case 22333ULL: goto x86_l_573d;
	case 22338ULL: goto x86_l_5742;
	case 22343ULL: goto x86_l_5747;
	case 22348ULL: goto x86_l_574c;
	case 22353ULL: goto x86_l_5751;
	case 22355ULL: goto x86_l_5753;
	case 22360ULL: goto x86_l_5758;
	case 22364ULL: goto x86_l_575c;
	case 22369ULL: goto x86_l_5761;
	case 22374ULL: goto x86_l_5766;
	case 22379ULL: goto x86_l_576b;
	case 22384ULL: goto x86_l_5770;
	case 22389ULL: goto x86_l_5775;
	case 22394ULL: goto x86_l_577a;
	case 22396ULL: goto x86_l_577c;
	case 22401ULL: goto x86_l_5781;
	case 22406ULL: goto x86_l_5786;
	case 22410ULL: goto x86_l_578a;
	case 22415ULL: goto x86_l_578f;
	case 22420ULL: goto x86_l_5794;
	case 22425ULL: goto x86_l_5799;
	case 22430ULL: goto x86_l_579e;
	case 22432ULL: goto x86_l_57a0;
	case 22437ULL: goto x86_l_57a5;
	case 22440ULL: goto x86_l_57a8;
	case 22446ULL: goto x86_l_57ae;
	case 22451ULL: goto x86_l_57b3;
	case 22454ULL: goto x86_l_57b6;
	case 22460ULL: goto x86_l_57bc;
	case 22464ULL: goto x86_l_57c0;
	case 22469ULL: goto x86_l_57c5;
	case 22474ULL: goto x86_l_57ca;
	case 22479ULL: goto x86_l_57cf;
	case 22484ULL: goto x86_l_57d4;
	case 22486ULL: goto x86_l_57d6;
	case 22490ULL: goto x86_l_57da;
	case 22492ULL: goto x86_l_57dc;
	case 22498ULL: goto x86_l_57e2;
	case 22501ULL: goto x86_l_57e5;
	case 22503ULL: goto x86_l_57e7;
	case 22509ULL: goto x86_l_57ed;
	case 22514ULL: goto x86_l_57f2;
	case 22520ULL: goto x86_l_57f8;
	case 22525ULL: goto x86_l_57fd;
	case 22527ULL: goto x86_l_57ff;
	case 22532ULL: goto x86_l_5804;
	case 22534ULL: goto x86_l_5806;
	case 22537ULL: goto x86_l_5809;
	case 22543ULL: goto x86_l_580f;
	case 22547ULL: goto x86_l_5813;
	case 22553ULL: goto x86_l_5819;
	case 22558ULL: goto x86_l_581e;
	case 22562ULL: goto x86_l_5822;
	case 22565ULL: goto x86_l_5825;
	case 22570ULL: goto x86_l_582a;
	case 22575ULL: goto x86_l_582f;
	case 22578ULL: goto x86_l_5832;
	case 22584ULL: goto x86_l_5838;
	case 22589ULL: goto x86_l_583d;
	case 22594ULL: goto x86_l_5842;
	case 22600ULL: goto x86_l_5848;
	case 22604ULL: goto x86_l_584c;
	case 22609ULL: goto x86_l_5851;
	case 22614ULL: goto x86_l_5856;
	case 22619ULL: goto x86_l_585b;
	case 22624ULL: goto x86_l_5860;
	case 22628ULL: goto x86_l_5864;
	case 22633ULL: goto x86_l_5869;
	case 22635ULL: goto x86_l_586b;
	case 22640ULL: goto x86_l_5870;
	case 22645ULL: goto x86_l_5875;
	case 22650ULL: goto x86_l_587a;
	case 22655ULL: goto x86_l_587f;
	case 22660ULL: goto x86_l_5884;
	case 22665ULL: goto x86_l_5889;
	case 22667ULL: goto x86_l_588b;
	case 22672ULL: goto x86_l_5890;
	case 22677ULL: goto x86_l_5895;
	case 22682ULL: goto x86_l_589a;
	case 22687ULL: goto x86_l_589f;
	case 22692ULL: goto x86_l_58a4;
	case 22697ULL: goto x86_l_58a9;
	case 22699ULL: goto x86_l_58ab;
	case 22704ULL: goto x86_l_58b0;
	case 22708ULL: goto x86_l_58b4;
	case 22713ULL: goto x86_l_58b9;
	case 22718ULL: goto x86_l_58be;
	case 22723ULL: goto x86_l_58c3;
	case 22728ULL: goto x86_l_58c8;
	case 22731ULL: goto x86_l_58cb;
	case 22733ULL: goto x86_l_58cd;
	case 22738ULL: goto x86_l_58d2;
	case 22743ULL: goto x86_l_58d7;
	case 22747ULL: goto x86_l_58db;
	case 22752ULL: goto x86_l_58e0;
	case 22757ULL: goto x86_l_58e5;
	case 22762ULL: goto x86_l_58ea;
	case 22767ULL: goto x86_l_58ef;
	case 22769ULL: goto x86_l_58f1;
	case 22774ULL: goto x86_l_58f6;
	case 22777ULL: goto x86_l_58f9;
	case 22783ULL: goto x86_l_58ff;
	case 22788ULL: goto x86_l_5904;
	case 22791ULL: goto x86_l_5907;
	case 22797ULL: goto x86_l_590d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_526e:
	/* 0x526e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5273:
	/* 0x5273: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5276:
	/* 0x5276: je     5437 <trace_ret_vfs_writev_tail+0x5437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5437;
	}
x86_l_527c:
	/* 0x527c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5280:
	/* 0x5280: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5285:
	/* 0x5285: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_528a:
	/* 0x528a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_528f:
	/* 0x528f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5294:
	/* 0x5294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5296:
	/* 0x5296: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_529a:
	/* 0x529a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_529c:
	/* 0x529c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_52a2:
	/* 0x52a2: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_52a5:
	/* 0x52a5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_52a7:
	/* 0x52a7: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_52ad:
	/* 0x52ad: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52b2:
	/* 0x52b2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_52b8:
	/* 0x52b8: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_52bd:
	/* 0x52bd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_52bf:
	/* 0x52bf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_52c4:
	/* 0x52c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52c6:
	/* 0x52c6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_52c9:
	/* 0x52c9: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_52cf:
	/* 0x52cf: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_52d3:
	/* 0x52d3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_52d9:
	/* 0x52d9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_52de:
	/* 0x52de: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_52e2:
	/* 0x52e2: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_52e5:
	/* 0x52e5: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52ea:
	/* 0x52ea: jmp    54c1 <trace_ret_vfs_writev_tail+0x54c1> */
	goto x86_l_54c1;
x86_l_52ef:
	/* 0x52ef: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_52f2:
	/* 0x52f2: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_52f8:
	/* 0x52f8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52fd:
	/* 0x52fd: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5302:
	/* 0x5302: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_5308:
	/* 0x5308: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_530c:
	/* 0x530c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5311:
	/* 0x5311: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5316:
	/* 0x5316: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_531b:
	/* 0x531b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5320:
	/* 0x5320: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5324:
	/* 0x5324: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5329:
	/* 0x5329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_532b:
	/* 0x532b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5330:
	/* 0x5330: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5335:
	/* 0x5335: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_533a:
	/* 0x533a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_533f:
	/* 0x533f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5344:
	/* 0x5344: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5349:
	/* 0x5349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534b:
	/* 0x534b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5350:
	/* 0x5350: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5355:
	/* 0x5355: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_535a:
	/* 0x535a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_535f:
	/* 0x535f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5364:
	/* 0x5364: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5369:
	/* 0x5369: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_536b:
	/* 0x536b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5370:
	/* 0x5370: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5374:
	/* 0x5374: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5379:
	/* 0x5379: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_537e:
	/* 0x537e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5383:
	/* 0x5383: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5388:
	/* 0x5388: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_538b:
	/* 0x538b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_538d:
	/* 0x538d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5392:
	/* 0x5392: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5397:
	/* 0x5397: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_539b:
	/* 0x539b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53a0:
	/* 0x53a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53a5:
	/* 0x53a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53aa:
	/* 0x53aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53af:
	/* 0x53af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53b1:
	/* 0x53b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53b6:
	/* 0x53b6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_53b9:
	/* 0x53b9: je     558f <trace_ret_vfs_writev_tail+0x558f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_558f;
	}
x86_l_53bf:
	/* 0x53bf: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53c4:
	/* 0x53c4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_53c7:
	/* 0x53c7: je     558f <trace_ret_vfs_writev_tail+0x558f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_558f;
	}
x86_l_53cd:
	/* 0x53cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_53d1:
	/* 0x53d1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53d6:
	/* 0x53d6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_53db:
	/* 0x53db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53e0:
	/* 0x53e0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_53e5:
	/* 0x53e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53e7:
	/* 0x53e7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_53eb:
	/* 0x53eb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_53ed:
	/* 0x53ed: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_53f3:
	/* 0x53f3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_53f5:
	/* 0x53f5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_53f7:
	/* 0x53f7: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_53fd:
	/* 0x53fd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5402:
	/* 0x5402: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5408:
	/* 0x5408: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_540b:
	/* 0x540b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_540d:
	/* 0x540d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5412:
	/* 0x5412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5414:
	/* 0x5414: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5417:
	/* 0x5417: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_541d:
	/* 0x541d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5420:
	/* 0x5420: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5426:
	/* 0x5426: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_542b:
	/* 0x542b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_542d:
	/* 0x542d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5432:
	/* 0x5432: jmp    5614 <trace_ret_vfs_writev_tail+0x5614> */
	goto x86_l_5614;
x86_l_5437:
	/* 0x5437: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_543a:
	/* 0x543a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_5440:
	/* 0x5440: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5445:
	/* 0x5445: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_544a:
	/* 0x544a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_5450:
	/* 0x5450: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5454:
	/* 0x5454: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5459:
	/* 0x5459: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_545e:
	/* 0x545e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5463:
	/* 0x5463: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5468:
	/* 0x5468: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_546c:
	/* 0x546c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5471:
	/* 0x5471: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5473:
	/* 0x5473: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5478:
	/* 0x5478: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_547d:
	/* 0x547d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5482:
	/* 0x5482: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5487:
	/* 0x5487: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_548c:
	/* 0x548c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5491:
	/* 0x5491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5493:
	/* 0x5493: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5498:
	/* 0x5498: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_549d:
	/* 0x549d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54a2:
	/* 0x54a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54a7:
	/* 0x54a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54ac:
	/* 0x54ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54b1:
	/* 0x54b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54b3:
	/* 0x54b3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b8:
	/* 0x54b8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_54bc:
	/* 0x54bc: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_54c1:
	/* 0x54c1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54c6:
	/* 0x54c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54cb:
	/* 0x54cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54d0:
	/* 0x54d0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_54d5:
	/* 0x54d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54da:
	/* 0x54da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54dc:
	/* 0x54dc: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54e1:
	/* 0x54e1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_54e6:
	/* 0x54e6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54ea:
	/* 0x54ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54ef:
	/* 0x54ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54f4:
	/* 0x54f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54f9:
	/* 0x54f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54fe:
	/* 0x54fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5500:
	/* 0x5500: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5505:
	/* 0x5505: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5508:
	/* 0x5508: je     56d7 <trace_ret_vfs_writev_tail+0x56d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56d7;
	}
x86_l_550e:
	/* 0x550e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5513:
	/* 0x5513: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5516:
	/* 0x5516: je     56d7 <trace_ret_vfs_writev_tail+0x56d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56d7;
	}
x86_l_551c:
	/* 0x551c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5520:
	/* 0x5520: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5525:
	/* 0x5525: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_552a:
	/* 0x552a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_552f:
	/* 0x552f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5534:
	/* 0x5534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5536:
	/* 0x5536: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_553a:
	/* 0x553a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_553c:
	/* 0x553c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5542:
	/* 0x5542: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5545:
	/* 0x5545: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5547:
	/* 0x5547: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_554d:
	/* 0x554d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5552:
	/* 0x5552: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5558:
	/* 0x5558: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_555d:
	/* 0x555d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_555f:
	/* 0x555f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5564:
	/* 0x5564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5566:
	/* 0x5566: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5569:
	/* 0x5569: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_556f:
	/* 0x556f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5573:
	/* 0x5573: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5579:
	/* 0x5579: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_557e:
	/* 0x557e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5582:
	/* 0x5582: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5585:
	/* 0x5585: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_558a:
	/* 0x558a: jmp    5761 <trace_ret_vfs_writev_tail+0x5761> */
	goto x86_l_5761;
x86_l_558f:
	/* 0x558f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5592:
	/* 0x5592: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_5598:
	/* 0x5598: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_559d:
	/* 0x559d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_55a2:
	/* 0x55a2: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_55a8:
	/* 0x55a8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_55ac:
	/* 0x55ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55b1:
	/* 0x55b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55b6:
	/* 0x55b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55bb:
	/* 0x55bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55c0:
	/* 0x55c0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_55c4:
	/* 0x55c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55c9:
	/* 0x55c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55cb:
	/* 0x55cb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55d0:
	/* 0x55d0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55d5:
	/* 0x55d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55da:
	/* 0x55da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55df:
	/* 0x55df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55e4:
	/* 0x55e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55e9:
	/* 0x55e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55eb:
	/* 0x55eb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55f0:
	/* 0x55f0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_55f5:
	/* 0x55f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55fa:
	/* 0x55fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55ff:
	/* 0x55ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5604:
	/* 0x5604: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5609:
	/* 0x5609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560b:
	/* 0x560b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5610:
	/* 0x5610: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5614:
	/* 0x5614: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5619:
	/* 0x5619: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_561e:
	/* 0x561e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5623:
	/* 0x5623: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5628:
	/* 0x5628: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_562b:
	/* 0x562b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_562d:
	/* 0x562d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5632:
	/* 0x5632: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5637:
	/* 0x5637: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_563b:
	/* 0x563b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5640:
	/* 0x5640: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5645:
	/* 0x5645: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_564a:
	/* 0x564a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564f:
	/* 0x564f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5651:
	/* 0x5651: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5656:
	/* 0x5656: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5659:
	/* 0x5659: je     582f <trace_ret_vfs_writev_tail+0x582f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_582f;
	}
x86_l_565f:
	/* 0x565f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5664:
	/* 0x5664: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5667:
	/* 0x5667: je     582f <trace_ret_vfs_writev_tail+0x582f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_582f;
	}
x86_l_566d:
	/* 0x566d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5671:
	/* 0x5671: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5676:
	/* 0x5676: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_567b:
	/* 0x567b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5680:
	/* 0x5680: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5685:
	/* 0x5685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5687:
	/* 0x5687: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_568b:
	/* 0x568b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_568d:
	/* 0x568d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5693:
	/* 0x5693: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5695:
	/* 0x5695: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5697:
	/* 0x5697: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_569d:
	/* 0x569d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56a2:
	/* 0x56a2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_56a8:
	/* 0x56a8: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_56ab:
	/* 0x56ab: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_56ad:
	/* 0x56ad: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_56b2:
	/* 0x56b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56b4:
	/* 0x56b4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_56b7:
	/* 0x56b7: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_56bd:
	/* 0x56bd: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_56c0:
	/* 0x56c0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_56c6:
	/* 0x56c6: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_56cb:
	/* 0x56cb: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56cd:
	/* 0x56cd: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56d2:
	/* 0x56d2: jmp    58b4 <trace_ret_vfs_writev_tail+0x58b4> */
	goto x86_l_58b4;
x86_l_56d7:
	/* 0x56d7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_56da:
	/* 0x56da: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_56e0:
	/* 0x56e0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e5:
	/* 0x56e5: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_56ea:
	/* 0x56ea: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_56f0:
	/* 0x56f0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_56f4:
	/* 0x56f4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56f9:
	/* 0x56f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56fe:
	/* 0x56fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5703:
	/* 0x5703: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5708:
	/* 0x5708: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_570c:
	/* 0x570c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5711:
	/* 0x5711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5713:
	/* 0x5713: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5718:
	/* 0x5718: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_571d:
	/* 0x571d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5722:
	/* 0x5722: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5727:
	/* 0x5727: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_572c:
	/* 0x572c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5731:
	/* 0x5731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5733:
	/* 0x5733: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5738:
	/* 0x5738: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_573d:
	/* 0x573d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5742:
	/* 0x5742: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5747:
	/* 0x5747: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_574c:
	/* 0x574c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5751:
	/* 0x5751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5753:
	/* 0x5753: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5758:
	/* 0x5758: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_575c:
	/* 0x575c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5761:
	/* 0x5761: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5766:
	/* 0x5766: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_576b:
	/* 0x576b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5770:
	/* 0x5770: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5775:
	/* 0x5775: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_577a:
	/* 0x577a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_577c:
	/* 0x577c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5781:
	/* 0x5781: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5786:
	/* 0x5786: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_578a:
	/* 0x578a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_578f:
	/* 0x578f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5794:
	/* 0x5794: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5799:
	/* 0x5799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_579e:
	/* 0x579e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57a0:
	/* 0x57a0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57a5:
	/* 0x57a5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_57a8:
	/* 0x57a8: je     5977 <trace_ret_vfs_writev_tail+0x5977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22903ULL;
	}
x86_l_57ae:
	/* 0x57ae: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57b3:
	/* 0x57b3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_57b6:
	/* 0x57b6: je     5977 <trace_ret_vfs_writev_tail+0x5977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22903ULL;
	}
x86_l_57bc:
	/* 0x57bc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57c0:
	/* 0x57c0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57c5:
	/* 0x57c5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_57ca:
	/* 0x57ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57cf:
	/* 0x57cf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_57d4:
	/* 0x57d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d6:
	/* 0x57d6: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_57da:
	/* 0x57da: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_57dc:
	/* 0x57dc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_57e2:
	/* 0x57e2: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_57e5:
	/* 0x57e5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_57e7:
	/* 0x57e7: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_57ed:
	/* 0x57ed: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57f2:
	/* 0x57f2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_57f8:
	/* 0x57f8: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_57fd:
	/* 0x57fd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_57ff:
	/* 0x57ff: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5804:
	/* 0x5804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5806:
	/* 0x5806: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5809:
	/* 0x5809: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_580f:
	/* 0x580f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5813:
	/* 0x5813: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5819:
	/* 0x5819: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_581e:
	/* 0x581e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5822:
	/* 0x5822: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5825:
	/* 0x5825: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_582a:
	/* 0x582a: jmp    5a01 <trace_ret_vfs_writev_tail+0x5a01> */
	return 23041ULL;
x86_l_582f:
	/* 0x582f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5832:
	/* 0x5832: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_5838:
	/* 0x5838: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583d:
	/* 0x583d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5842:
	/* 0x5842: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_5848:
	/* 0x5848: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_584c:
	/* 0x584c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5851:
	/* 0x5851: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5856:
	/* 0x5856: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_585b:
	/* 0x585b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5860:
	/* 0x5860: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5864:
	/* 0x5864: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5869:
	/* 0x5869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586b:
	/* 0x586b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5870:
	/* 0x5870: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5875:
	/* 0x5875: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_587a:
	/* 0x587a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_587f:
	/* 0x587f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5884:
	/* 0x5884: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5889:
	/* 0x5889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_588b:
	/* 0x588b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5890:
	/* 0x5890: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5895:
	/* 0x5895: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_589a:
	/* 0x589a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_589f:
	/* 0x589f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58a4:
	/* 0x58a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a9:
	/* 0x58a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58ab:
	/* 0x58ab: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58b0:
	/* 0x58b0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_58b4:
	/* 0x58b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58b9:
	/* 0x58b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_58be:
	/* 0x58be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58c3:
	/* 0x58c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58c8:
	/* 0x58c8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_58cb:
	/* 0x58cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58cd:
	/* 0x58cd: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58d2:
	/* 0x58d2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_58d7:
	/* 0x58d7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_58db:
	/* 0x58db: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58e0:
	/* 0x58e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_58e5:
	/* 0x58e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58ea:
	/* 0x58ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58ef:
	/* 0x58ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f1:
	/* 0x58f1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_58f6:
	/* 0x58f6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_58f9:
	/* 0x58f9: je     5acf <trace_ret_vfs_writev_tail+0x5acf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23247ULL;
	}
x86_l_58ff:
	/* 0x58ff: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5904:
	/* 0x5904: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5907:
	/* 0x5907: je     5acf <trace_ret_vfs_writev_tail+0x5acf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23247ULL;
	}
x86_l_590d:
	/* 0x590d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
	return 22801ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22801ULL: goto x86_l_5911;
	case 22806ULL: goto x86_l_5916;
	case 22811ULL: goto x86_l_591b;
	case 22816ULL: goto x86_l_5920;
	case 22821ULL: goto x86_l_5925;
	case 22823ULL: goto x86_l_5927;
	case 22827ULL: goto x86_l_592b;
	case 22829ULL: goto x86_l_592d;
	case 22835ULL: goto x86_l_5933;
	case 22837ULL: goto x86_l_5935;
	case 22839ULL: goto x86_l_5937;
	case 22845ULL: goto x86_l_593d;
	case 22850ULL: goto x86_l_5942;
	case 22856ULL: goto x86_l_5948;
	case 22859ULL: goto x86_l_594b;
	case 22861ULL: goto x86_l_594d;
	case 22866ULL: goto x86_l_5952;
	case 22868ULL: goto x86_l_5954;
	case 22871ULL: goto x86_l_5957;
	case 22877ULL: goto x86_l_595d;
	case 22880ULL: goto x86_l_5960;
	case 22886ULL: goto x86_l_5966;
	case 22891ULL: goto x86_l_596b;
	case 22893ULL: goto x86_l_596d;
	case 22898ULL: goto x86_l_5972;
	case 22903ULL: goto x86_l_5977;
	case 22906ULL: goto x86_l_597a;
	case 22912ULL: goto x86_l_5980;
	case 22917ULL: goto x86_l_5985;
	case 22922ULL: goto x86_l_598a;
	case 22928ULL: goto x86_l_5990;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22942ULL: goto x86_l_599e;
	case 22947ULL: goto x86_l_59a3;
	case 22952ULL: goto x86_l_59a8;
	case 22956ULL: goto x86_l_59ac;
	case 22961ULL: goto x86_l_59b1;
	case 22963ULL: goto x86_l_59b3;
	case 22968ULL: goto x86_l_59b8;
	case 22973ULL: goto x86_l_59bd;
	case 22978ULL: goto x86_l_59c2;
	case 22983ULL: goto x86_l_59c7;
	case 22988ULL: goto x86_l_59cc;
	case 22993ULL: goto x86_l_59d1;
	case 22995ULL: goto x86_l_59d3;
	case 23000ULL: goto x86_l_59d8;
	case 23005ULL: goto x86_l_59dd;
	case 23010ULL: goto x86_l_59e2;
	case 23015ULL: goto x86_l_59e7;
	case 23020ULL: goto x86_l_59ec;
	case 23025ULL: goto x86_l_59f1;
	case 23027ULL: goto x86_l_59f3;
	case 23032ULL: goto x86_l_59f8;
	case 23036ULL: goto x86_l_59fc;
	case 23041ULL: goto x86_l_5a01;
	case 23046ULL: goto x86_l_5a06;
	case 23051ULL: goto x86_l_5a0b;
	case 23056ULL: goto x86_l_5a10;
	case 23061ULL: goto x86_l_5a15;
	case 23066ULL: goto x86_l_5a1a;
	case 23068ULL: goto x86_l_5a1c;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23082ULL: goto x86_l_5a2a;
	case 23087ULL: goto x86_l_5a2f;
	case 23092ULL: goto x86_l_5a34;
	case 23097ULL: goto x86_l_5a39;
	case 23102ULL: goto x86_l_5a3e;
	case 23104ULL: goto x86_l_5a40;
	case 23109ULL: goto x86_l_5a45;
	case 23112ULL: goto x86_l_5a48;
	case 23118ULL: goto x86_l_5a4e;
	case 23123ULL: goto x86_l_5a53;
	case 23126ULL: goto x86_l_5a56;
	case 23132ULL: goto x86_l_5a5c;
	case 23136ULL: goto x86_l_5a60;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23151ULL: goto x86_l_5a6f;
	case 23156ULL: goto x86_l_5a74;
	case 23158ULL: goto x86_l_5a76;
	case 23162ULL: goto x86_l_5a7a;
	case 23164ULL: goto x86_l_5a7c;
	case 23170ULL: goto x86_l_5a82;
	case 23173ULL: goto x86_l_5a85;
	case 23175ULL: goto x86_l_5a87;
	case 23181ULL: goto x86_l_5a8d;
	case 23186ULL: goto x86_l_5a92;
	case 23192ULL: goto x86_l_5a98;
	case 23197ULL: goto x86_l_5a9d;
	case 23199ULL: goto x86_l_5a9f;
	case 23204ULL: goto x86_l_5aa4;
	case 23206ULL: goto x86_l_5aa6;
	case 23209ULL: goto x86_l_5aa9;
	case 23215ULL: goto x86_l_5aaf;
	case 23219ULL: goto x86_l_5ab3;
	case 23225ULL: goto x86_l_5ab9;
	case 23230ULL: goto x86_l_5abe;
	case 23234ULL: goto x86_l_5ac2;
	case 23237ULL: goto x86_l_5ac5;
	case 23242ULL: goto x86_l_5aca;
	case 23247ULL: goto x86_l_5acf;
	case 23250ULL: goto x86_l_5ad2;
	case 23256ULL: goto x86_l_5ad8;
	case 23261ULL: goto x86_l_5add;
	case 23266ULL: goto x86_l_5ae2;
	case 23272ULL: goto x86_l_5ae8;
	case 23276ULL: goto x86_l_5aec;
	case 23281ULL: goto x86_l_5af1;
	case 23286ULL: goto x86_l_5af6;
	case 23291ULL: goto x86_l_5afb;
	case 23296ULL: goto x86_l_5b00;
	case 23300ULL: goto x86_l_5b04;
	case 23305ULL: goto x86_l_5b09;
	case 23307ULL: goto x86_l_5b0b;
	case 23312ULL: goto x86_l_5b10;
	case 23317ULL: goto x86_l_5b15;
	case 23322ULL: goto x86_l_5b1a;
	case 23327ULL: goto x86_l_5b1f;
	case 23332ULL: goto x86_l_5b24;
	case 23337ULL: goto x86_l_5b29;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23349ULL: goto x86_l_5b35;
	case 23354ULL: goto x86_l_5b3a;
	case 23359ULL: goto x86_l_5b3f;
	case 23364ULL: goto x86_l_5b44;
	case 23369ULL: goto x86_l_5b49;
	case 23371ULL: goto x86_l_5b4b;
	case 23376ULL: goto x86_l_5b50;
	case 23380ULL: goto x86_l_5b54;
	case 23385ULL: goto x86_l_5b59;
	case 23390ULL: goto x86_l_5b5e;
	case 23395ULL: goto x86_l_5b63;
	case 23400ULL: goto x86_l_5b68;
	case 23403ULL: goto x86_l_5b6b;
	case 23405ULL: goto x86_l_5b6d;
	case 23410ULL: goto x86_l_5b72;
	case 23415ULL: goto x86_l_5b77;
	case 23419ULL: goto x86_l_5b7b;
	case 23424ULL: goto x86_l_5b80;
	case 23429ULL: goto x86_l_5b85;
	case 23434ULL: goto x86_l_5b8a;
	case 23439ULL: goto x86_l_5b8f;
	case 23441ULL: goto x86_l_5b91;
	case 23446ULL: goto x86_l_5b96;
	case 23449ULL: goto x86_l_5b99;
	case 23455ULL: goto x86_l_5b9f;
	case 23460ULL: goto x86_l_5ba4;
	case 23463ULL: goto x86_l_5ba7;
	case 23469ULL: goto x86_l_5bad;
	case 23473ULL: goto x86_l_5bb1;
	case 23478ULL: goto x86_l_5bb6;
	case 23483ULL: goto x86_l_5bbb;
	case 23488ULL: goto x86_l_5bc0;
	case 23493ULL: goto x86_l_5bc5;
	case 23495ULL: goto x86_l_5bc7;
	case 23499ULL: goto x86_l_5bcb;
	case 23501ULL: goto x86_l_5bcd;
	case 23507ULL: goto x86_l_5bd3;
	case 23509ULL: goto x86_l_5bd5;
	case 23511ULL: goto x86_l_5bd7;
	case 23517ULL: goto x86_l_5bdd;
	case 23522ULL: goto x86_l_5be2;
	case 23528ULL: goto x86_l_5be8;
	case 23531ULL: goto x86_l_5beb;
	case 23533ULL: goto x86_l_5bed;
	case 23538ULL: goto x86_l_5bf2;
	case 23540ULL: goto x86_l_5bf4;
	case 23543ULL: goto x86_l_5bf7;
	case 23549ULL: goto x86_l_5bfd;
	case 23552ULL: goto x86_l_5c00;
	case 23558ULL: goto x86_l_5c06;
	case 23563ULL: goto x86_l_5c0b;
	case 23565ULL: goto x86_l_5c0d;
	case 23570ULL: goto x86_l_5c12;
	case 23575ULL: goto x86_l_5c17;
	case 23578ULL: goto x86_l_5c1a;
	case 23584ULL: goto x86_l_5c20;
	case 23589ULL: goto x86_l_5c25;
	case 23594ULL: goto x86_l_5c2a;
	case 23600ULL: goto x86_l_5c30;
	case 23604ULL: goto x86_l_5c34;
	case 23609ULL: goto x86_l_5c39;
	case 23614ULL: goto x86_l_5c3e;
	case 23619ULL: goto x86_l_5c43;
	case 23624ULL: goto x86_l_5c48;
	case 23628ULL: goto x86_l_5c4c;
	case 23633ULL: goto x86_l_5c51;
	case 23635ULL: goto x86_l_5c53;
	case 23640ULL: goto x86_l_5c58;
	case 23645ULL: goto x86_l_5c5d;
	case 23650ULL: goto x86_l_5c62;
	case 23655ULL: goto x86_l_5c67;
	case 23660ULL: goto x86_l_5c6c;
	case 23665ULL: goto x86_l_5c71;
	case 23667ULL: goto x86_l_5c73;
	case 23672ULL: goto x86_l_5c78;
	case 23677ULL: goto x86_l_5c7d;
	case 23682ULL: goto x86_l_5c82;
	case 23687ULL: goto x86_l_5c87;
	case 23692ULL: goto x86_l_5c8c;
	case 23697ULL: goto x86_l_5c91;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23708ULL: goto x86_l_5c9c;
	case 23713ULL: goto x86_l_5ca1;
	case 23718ULL: goto x86_l_5ca6;
	case 23723ULL: goto x86_l_5cab;
	case 23728ULL: goto x86_l_5cb0;
	case 23733ULL: goto x86_l_5cb5;
	case 23738ULL: goto x86_l_5cba;
	case 23740ULL: goto x86_l_5cbc;
	case 23745ULL: goto x86_l_5cc1;
	case 23750ULL: goto x86_l_5cc6;
	case 23754ULL: goto x86_l_5cca;
	case 23759ULL: goto x86_l_5ccf;
	case 23764ULL: goto x86_l_5cd4;
	case 23769ULL: goto x86_l_5cd9;
	case 23774ULL: goto x86_l_5cde;
	case 23776ULL: goto x86_l_5ce0;
	case 23781ULL: goto x86_l_5ce5;
	case 23784ULL: goto x86_l_5ce8;
	case 23790ULL: goto x86_l_5cee;
	case 23795ULL: goto x86_l_5cf3;
	case 23798ULL: goto x86_l_5cf6;
	case 23804ULL: goto x86_l_5cfc;
	case 23808ULL: goto x86_l_5d00;
	case 23813ULL: goto x86_l_5d05;
	case 23818ULL: goto x86_l_5d0a;
	case 23823ULL: goto x86_l_5d0f;
	case 23828ULL: goto x86_l_5d14;
	case 23830ULL: goto x86_l_5d16;
	case 23834ULL: goto x86_l_5d1a;
	case 23836ULL: goto x86_l_5d1c;
	case 23842ULL: goto x86_l_5d22;
	case 23845ULL: goto x86_l_5d25;
	case 23847ULL: goto x86_l_5d27;
	case 23853ULL: goto x86_l_5d2d;
	case 23858ULL: goto x86_l_5d32;
	case 23864ULL: goto x86_l_5d38;
	case 23869ULL: goto x86_l_5d3d;
	case 23871ULL: goto x86_l_5d3f;
	case 23876ULL: goto x86_l_5d44;
	case 23878ULL: goto x86_l_5d46;
	case 23881ULL: goto x86_l_5d49;
	case 23887ULL: goto x86_l_5d4f;
	case 23891ULL: goto x86_l_5d53;
	case 23897ULL: goto x86_l_5d59;
	case 23902ULL: goto x86_l_5d5e;
	case 23906ULL: goto x86_l_5d62;
	case 23909ULL: goto x86_l_5d65;
	case 23914ULL: goto x86_l_5d6a;
	case 23919ULL: goto x86_l_5d6f;
	case 23922ULL: goto x86_l_5d72;
	case 23928ULL: goto x86_l_5d78;
	case 23933ULL: goto x86_l_5d7d;
	case 23938ULL: goto x86_l_5d82;
	case 23944ULL: goto x86_l_5d88;
	case 23948ULL: goto x86_l_5d8c;
	case 23953ULL: goto x86_l_5d91;
	case 23958ULL: goto x86_l_5d96;
	case 23963ULL: goto x86_l_5d9b;
	case 23968ULL: goto x86_l_5da0;
	case 23972ULL: goto x86_l_5da4;
	case 23977ULL: goto x86_l_5da9;
	case 23979ULL: goto x86_l_5dab;
	case 23984ULL: goto x86_l_5db0;
	case 23989ULL: goto x86_l_5db5;
	case 23994ULL: goto x86_l_5dba;
	case 23999ULL: goto x86_l_5dbf;
	case 24004ULL: goto x86_l_5dc4;
	case 24009ULL: goto x86_l_5dc9;
	case 24011ULL: goto x86_l_5dcb;
	case 24016ULL: goto x86_l_5dd0;
	case 24021ULL: goto x86_l_5dd5;
	case 24026ULL: goto x86_l_5dda;
	case 24031ULL: goto x86_l_5ddf;
	case 24036ULL: goto x86_l_5de4;
	case 24041ULL: goto x86_l_5de9;
	case 24043ULL: goto x86_l_5deb;
	case 24048ULL: goto x86_l_5df0;
	case 24052ULL: goto x86_l_5df4;
	case 24057ULL: goto x86_l_5df9;
	case 24062ULL: goto x86_l_5dfe;
	case 24067ULL: goto x86_l_5e03;
	case 24072ULL: goto x86_l_5e08;
	case 24075ULL: goto x86_l_5e0b;
	case 24077ULL: goto x86_l_5e0d;
	case 24082ULL: goto x86_l_5e12;
	case 24087ULL: goto x86_l_5e17;
	case 24091ULL: goto x86_l_5e1b;
	case 24096ULL: goto x86_l_5e20;
	case 24101ULL: goto x86_l_5e25;
	case 24106ULL: goto x86_l_5e2a;
	case 24111ULL: goto x86_l_5e2f;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24121ULL: goto x86_l_5e39;
	case 24127ULL: goto x86_l_5e3f;
	case 24132ULL: goto x86_l_5e44;
	case 24135ULL: goto x86_l_5e47;
	case 24141ULL: goto x86_l_5e4d;
	case 24145ULL: goto x86_l_5e51;
	case 24150ULL: goto x86_l_5e56;
	case 24155ULL: goto x86_l_5e5b;
	case 24160ULL: goto x86_l_5e60;
	case 24165ULL: goto x86_l_5e65;
	case 24167ULL: goto x86_l_5e67;
	case 24171ULL: goto x86_l_5e6b;
	case 24173ULL: goto x86_l_5e6d;
	case 24179ULL: goto x86_l_5e73;
	case 24181ULL: goto x86_l_5e75;
	case 24183ULL: goto x86_l_5e77;
	case 24189ULL: goto x86_l_5e7d;
	case 24194ULL: goto x86_l_5e82;
	case 24200ULL: goto x86_l_5e88;
	case 24203ULL: goto x86_l_5e8b;
	case 24205ULL: goto x86_l_5e8d;
	case 24210ULL: goto x86_l_5e92;
	case 24212ULL: goto x86_l_5e94;
	case 24215ULL: goto x86_l_5e97;
	case 24221ULL: goto x86_l_5e9d;
	case 24224ULL: goto x86_l_5ea0;
	case 24230ULL: goto x86_l_5ea6;
	case 24235ULL: goto x86_l_5eab;
	case 24237ULL: goto x86_l_5ead;
	case 24242ULL: goto x86_l_5eb2;
	case 24247ULL: goto x86_l_5eb7;
	case 24250ULL: goto x86_l_5eba;
	case 24256ULL: goto x86_l_5ec0;
	case 24261ULL: goto x86_l_5ec5;
	case 24266ULL: goto x86_l_5eca;
	case 24272ULL: goto x86_l_5ed0;
	case 24276ULL: goto x86_l_5ed4;
	case 24281ULL: goto x86_l_5ed9;
	case 24286ULL: goto x86_l_5ede;
	case 24291ULL: goto x86_l_5ee3;
	case 24296ULL: goto x86_l_5ee8;
	case 24300ULL: goto x86_l_5eec;
	case 24305ULL: goto x86_l_5ef1;
	case 24307ULL: goto x86_l_5ef3;
	case 24312ULL: goto x86_l_5ef8;
	case 24317ULL: goto x86_l_5efd;
	case 24322ULL: goto x86_l_5f02;
	case 24327ULL: goto x86_l_5f07;
	case 24332ULL: goto x86_l_5f0c;
	case 24337ULL: goto x86_l_5f11;
	case 24339ULL: goto x86_l_5f13;
	case 24344ULL: goto x86_l_5f18;
	case 24349ULL: goto x86_l_5f1d;
	case 24354ULL: goto x86_l_5f22;
	case 24359ULL: goto x86_l_5f27;
	case 24364ULL: goto x86_l_5f2c;
	case 24369ULL: goto x86_l_5f31;
	case 24371ULL: goto x86_l_5f33;
	case 24376ULL: goto x86_l_5f38;
	case 24380ULL: goto x86_l_5f3c;
	case 24385ULL: goto x86_l_5f41;
	case 24390ULL: goto x86_l_5f46;
	case 24395ULL: goto x86_l_5f4b;
	case 24400ULL: goto x86_l_5f50;
	case 24405ULL: goto x86_l_5f55;
	case 24410ULL: goto x86_l_5f5a;
	case 24412ULL: goto x86_l_5f5c;
	case 24417ULL: goto x86_l_5f61;
	case 24422ULL: goto x86_l_5f66;
	case 24426ULL: goto x86_l_5f6a;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24446ULL: goto x86_l_5f7e;
	case 24448ULL: goto x86_l_5f80;
	case 24453ULL: goto x86_l_5f85;
	case 24456ULL: goto x86_l_5f88;
	case 24462ULL: goto x86_l_5f8e;
	case 24467ULL: goto x86_l_5f93;
	case 24470ULL: goto x86_l_5f96;
	case 24476ULL: goto x86_l_5f9c;
	case 24480ULL: goto x86_l_5fa0;
	case 24485ULL: goto x86_l_5fa5;
	case 24490ULL: goto x86_l_5faa;
	case 24495ULL: goto x86_l_5faf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5911:
	/* 0x5911: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5916:
	/* 0x5916: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_591b:
	/* 0x591b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5920:
	/* 0x5920: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5925:
	/* 0x5925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5927:
	/* 0x5927: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_592b:
	/* 0x592b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_592d:
	/* 0x592d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5933:
	/* 0x5933: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5935:
	/* 0x5935: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5937:
	/* 0x5937: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_593d:
	/* 0x593d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5942:
	/* 0x5942: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5948:
	/* 0x5948: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_594b:
	/* 0x594b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_594d:
	/* 0x594d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5952:
	/* 0x5952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5954:
	/* 0x5954: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5957:
	/* 0x5957: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_595d:
	/* 0x595d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5960:
	/* 0x5960: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5966:
	/* 0x5966: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_596b:
	/* 0x596b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_596d:
	/* 0x596d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5972:
	/* 0x5972: jmp    5b54 <trace_ret_vfs_writev_tail+0x5b54> */
	goto x86_l_5b54;
x86_l_5977:
	/* 0x5977: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_597a:
	/* 0x597a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_5980:
	/* 0x5980: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5985:
	/* 0x5985: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_598a:
	/* 0x598a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_5990:
	/* 0x5990: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5994:
	/* 0x5994: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5999:
	/* 0x5999: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_599e:
	/* 0x599e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59a3:
	/* 0x59a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a8:
	/* 0x59a8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59ac:
	/* 0x59ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59b1:
	/* 0x59b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59b3:
	/* 0x59b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b8:
	/* 0x59b8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59bd:
	/* 0x59bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59c2:
	/* 0x59c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59c7:
	/* 0x59c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59cc:
	/* 0x59cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59d1:
	/* 0x59d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59d3:
	/* 0x59d3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59d8:
	/* 0x59d8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_59dd:
	/* 0x59dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59e2:
	/* 0x59e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59e7:
	/* 0x59e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59ec:
	/* 0x59ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59f1:
	/* 0x59f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f3:
	/* 0x59f3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59f8:
	/* 0x59f8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_59fc:
	/* 0x59fc: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a01:
	/* 0x5a01: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a06:
	/* 0x5a06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a0b:
	/* 0x5a0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a10:
	/* 0x5a10: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a15:
	/* 0x5a15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a1a:
	/* 0x5a1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a1c:
	/* 0x5a1c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a21:
	/* 0x5a21: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a26:
	/* 0x5a26: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a2a:
	/* 0x5a2a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a2f:
	/* 0x5a2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a34:
	/* 0x5a34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a39:
	/* 0x5a39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a3e:
	/* 0x5a3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a40:
	/* 0x5a40: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a45:
	/* 0x5a45: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5a48:
	/* 0x5a48: je     5c17 <trace_ret_vfs_writev_tail+0x5c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c17;
	}
x86_l_5a4e:
	/* 0x5a4e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a53:
	/* 0x5a53: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5a56:
	/* 0x5a56: je     5c17 <trace_ret_vfs_writev_tail+0x5c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c17;
	}
x86_l_5a5c:
	/* 0x5a5c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a60:
	/* 0x5a60: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a65:
	/* 0x5a65: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5a6a:
	/* 0x5a6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a6f:
	/* 0x5a6f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5a74:
	/* 0x5a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a76:
	/* 0x5a76: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5a7a:
	/* 0x5a7a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5a7c:
	/* 0x5a7c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5a82:
	/* 0x5a82: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5a85:
	/* 0x5a85: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a87:
	/* 0x5a87: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_5a8d:
	/* 0x5a8d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a92:
	/* 0x5a92: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5a98:
	/* 0x5a98: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_5a9d:
	/* 0x5a9d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5a9f:
	/* 0x5a9f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5aa4:
	/* 0x5aa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa6:
	/* 0x5aa6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5aa9:
	/* 0x5aa9: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_5aaf:
	/* 0x5aaf: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ab3:
	/* 0x5ab3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ab9:
	/* 0x5ab9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5abe:
	/* 0x5abe: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ac2:
	/* 0x5ac2: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ac5:
	/* 0x5ac5: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5aca:
	/* 0x5aca: jmp    5ca1 <trace_ret_vfs_writev_tail+0x5ca1> */
	goto x86_l_5ca1;
x86_l_5acf:
	/* 0x5acf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5ad2:
	/* 0x5ad2: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_5ad8:
	/* 0x5ad8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5add:
	/* 0x5add: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5ae2:
	/* 0x5ae2: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_5ae8:
	/* 0x5ae8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5aec:
	/* 0x5aec: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5af1:
	/* 0x5af1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5af6:
	/* 0x5af6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5afb:
	/* 0x5afb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b00:
	/* 0x5b00: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b04:
	/* 0x5b04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b09:
	/* 0x5b09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0b:
	/* 0x5b0b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b10:
	/* 0x5b10: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b15:
	/* 0x5b15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b1a:
	/* 0x5b1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b1f:
	/* 0x5b1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b24:
	/* 0x5b24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b29:
	/* 0x5b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b2b:
	/* 0x5b2b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b30:
	/* 0x5b30: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b35:
	/* 0x5b35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b3a:
	/* 0x5b3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b3f:
	/* 0x5b3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b44:
	/* 0x5b44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b49:
	/* 0x5b49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b4b:
	/* 0x5b4b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b50:
	/* 0x5b50: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b54:
	/* 0x5b54: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b59:
	/* 0x5b59: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b5e:
	/* 0x5b5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b63:
	/* 0x5b63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b68:
	/* 0x5b68: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5b6b:
	/* 0x5b6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b6d:
	/* 0x5b6d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b72:
	/* 0x5b72: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b77:
	/* 0x5b77: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b7b:
	/* 0x5b7b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b80:
	/* 0x5b80: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b85:
	/* 0x5b85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b8a:
	/* 0x5b8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b8f:
	/* 0x5b8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b91:
	/* 0x5b91: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b96:
	/* 0x5b96: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5b99:
	/* 0x5b99: je     5d6f <trace_ret_vfs_writev_tail+0x5d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d6f;
	}
x86_l_5b9f:
	/* 0x5b9f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ba4:
	/* 0x5ba4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5ba7:
	/* 0x5ba7: je     5d6f <trace_ret_vfs_writev_tail+0x5d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d6f;
	}
x86_l_5bad:
	/* 0x5bad: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5bb1:
	/* 0x5bb1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bb6:
	/* 0x5bb6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5bbb:
	/* 0x5bbb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bc0:
	/* 0x5bc0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5bc5:
	/* 0x5bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc7:
	/* 0x5bc7: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5bcb:
	/* 0x5bcb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5bcd:
	/* 0x5bcd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5bd3:
	/* 0x5bd3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5bd5:
	/* 0x5bd5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5bd7:
	/* 0x5bd7: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_5bdd:
	/* 0x5bdd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5be2:
	/* 0x5be2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5be8:
	/* 0x5be8: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5beb:
	/* 0x5beb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5bed:
	/* 0x5bed: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5bf2:
	/* 0x5bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bf4:
	/* 0x5bf4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5bf7:
	/* 0x5bf7: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_5bfd:
	/* 0x5bfd: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5c00:
	/* 0x5c00: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5c06:
	/* 0x5c06: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5c0b:
	/* 0x5c0b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c0d:
	/* 0x5c0d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c12:
	/* 0x5c12: jmp    5df4 <trace_ret_vfs_writev_tail+0x5df4> */
	goto x86_l_5df4;
x86_l_5c17:
	/* 0x5c17: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5c1a:
	/* 0x5c1a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_5c20:
	/* 0x5c20: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c25:
	/* 0x5c25: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5c2a:
	/* 0x5c2a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_5c30:
	/* 0x5c30: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c34:
	/* 0x5c34: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c39:
	/* 0x5c39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c3e:
	/* 0x5c3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c43:
	/* 0x5c43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c48:
	/* 0x5c48: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c4c:
	/* 0x5c4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c51:
	/* 0x5c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c53:
	/* 0x5c53: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c58:
	/* 0x5c58: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c5d:
	/* 0x5c5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c62:
	/* 0x5c62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c67:
	/* 0x5c67: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c6c:
	/* 0x5c6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c71:
	/* 0x5c71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c73:
	/* 0x5c73: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c78:
	/* 0x5c78: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c7d:
	/* 0x5c7d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c82:
	/* 0x5c82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c87:
	/* 0x5c87: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8c:
	/* 0x5c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c91:
	/* 0x5c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c93:
	/* 0x5c93: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c98:
	/* 0x5c98: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c9c:
	/* 0x5c9c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ca1:
	/* 0x5ca1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ca6:
	/* 0x5ca6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cab:
	/* 0x5cab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cb0:
	/* 0x5cb0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5cb5:
	/* 0x5cb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cba:
	/* 0x5cba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cbc:
	/* 0x5cbc: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5cc1:
	/* 0x5cc1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5cc6:
	/* 0x5cc6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5cca:
	/* 0x5cca: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ccf:
	/* 0x5ccf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cd4:
	/* 0x5cd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cd9:
	/* 0x5cd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cde:
	/* 0x5cde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ce0:
	/* 0x5ce0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ce5:
	/* 0x5ce5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5ce8:
	/* 0x5ce8: je     5eb7 <trace_ret_vfs_writev_tail+0x5eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5eb7;
	}
x86_l_5cee:
	/* 0x5cee: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5cf3:
	/* 0x5cf3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5cf6:
	/* 0x5cf6: je     5eb7 <trace_ret_vfs_writev_tail+0x5eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5eb7;
	}
x86_l_5cfc:
	/* 0x5cfc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d00:
	/* 0x5d00: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d05:
	/* 0x5d05: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5d0a:
	/* 0x5d0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d0f:
	/* 0x5d0f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5d14:
	/* 0x5d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d16:
	/* 0x5d16: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5d1a:
	/* 0x5d1a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5d1c:
	/* 0x5d1c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d22:
	/* 0x5d22: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5d25:
	/* 0x5d25: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d27:
	/* 0x5d27: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_5d2d:
	/* 0x5d2d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d32:
	/* 0x5d32: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5d38:
	/* 0x5d38: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_5d3d:
	/* 0x5d3d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5d3f:
	/* 0x5d3f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5d44:
	/* 0x5d44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d46:
	/* 0x5d46: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5d49:
	/* 0x5d49: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_5d4f:
	/* 0x5d4f: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5d53:
	/* 0x5d53: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5d59:
	/* 0x5d59: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5d5e:
	/* 0x5d5e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5d62:
	/* 0x5d62: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d65:
	/* 0x5d65: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d6a:
	/* 0x5d6a: jmp    5f41 <trace_ret_vfs_writev_tail+0x5f41> */
	goto x86_l_5f41;
x86_l_5d6f:
	/* 0x5d6f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5d72:
	/* 0x5d72: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_5d78:
	/* 0x5d78: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d7d:
	/* 0x5d7d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5d82:
	/* 0x5d82: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_5d88:
	/* 0x5d88: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d8c:
	/* 0x5d8c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d91:
	/* 0x5d91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d96:
	/* 0x5d96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d9b:
	/* 0x5d9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da0:
	/* 0x5da0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5da4:
	/* 0x5da4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5da9:
	/* 0x5da9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dab:
	/* 0x5dab: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db0:
	/* 0x5db0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db5:
	/* 0x5db5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dba:
	/* 0x5dba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dbf:
	/* 0x5dbf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc4:
	/* 0x5dc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dc9:
	/* 0x5dc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dcb:
	/* 0x5dcb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd0:
	/* 0x5dd0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5dd5:
	/* 0x5dd5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dda:
	/* 0x5dda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ddf:
	/* 0x5ddf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de4:
	/* 0x5de4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5de9:
	/* 0x5de9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5deb:
	/* 0x5deb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df0:
	/* 0x5df0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5df4:
	/* 0x5df4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5df9:
	/* 0x5df9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5dfe:
	/* 0x5dfe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e03:
	/* 0x5e03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e08:
	/* 0x5e08: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5e0b:
	/* 0x5e0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e0d:
	/* 0x5e0d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e12:
	/* 0x5e12: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e17:
	/* 0x5e17: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e1b:
	/* 0x5e1b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e20:
	/* 0x5e20: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e25:
	/* 0x5e25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e2a:
	/* 0x5e2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e2f:
	/* 0x5e2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e31:
	/* 0x5e31: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e36:
	/* 0x5e36: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5e39:
	/* 0x5e39: je     600f <trace_ret_vfs_writev_tail+0x600f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24591ULL;
	}
x86_l_5e3f:
	/* 0x5e3f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e44:
	/* 0x5e44: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5e47:
	/* 0x5e47: je     600f <trace_ret_vfs_writev_tail+0x600f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24591ULL;
	}
x86_l_5e4d:
	/* 0x5e4d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e51:
	/* 0x5e51: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e56:
	/* 0x5e56: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5e5b:
	/* 0x5e5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e60:
	/* 0x5e60: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5e65:
	/* 0x5e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e67:
	/* 0x5e67: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5e6b:
	/* 0x5e6b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5e6d:
	/* 0x5e6d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e73:
	/* 0x5e73: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5e75:
	/* 0x5e75: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e77:
	/* 0x5e77: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_5e7d:
	/* 0x5e7d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e82:
	/* 0x5e82: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5e88:
	/* 0x5e88: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e8b:
	/* 0x5e8b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5e8d:
	/* 0x5e8d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5e92:
	/* 0x5e92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e94:
	/* 0x5e94: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e97:
	/* 0x5e97: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_5e9d:
	/* 0x5e9d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ea0:
	/* 0x5ea0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ea6:
	/* 0x5ea6: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5eab:
	/* 0x5eab: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ead:
	/* 0x5ead: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5eb2:
	/* 0x5eb2: jmp    6094 <trace_ret_vfs_writev_tail+0x6094> */
	return 24724ULL;
x86_l_5eb7:
	/* 0x5eb7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5eba:
	/* 0x5eba: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_5ec0:
	/* 0x5ec0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ec5:
	/* 0x5ec5: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5eca:
	/* 0x5eca: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_5ed0:
	/* 0x5ed0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ed4:
	/* 0x5ed4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ed9:
	/* 0x5ed9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ede:
	/* 0x5ede: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ee3:
	/* 0x5ee3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ee8:
	/* 0x5ee8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5eec:
	/* 0x5eec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ef1:
	/* 0x5ef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ef3:
	/* 0x5ef3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ef8:
	/* 0x5ef8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5efd:
	/* 0x5efd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f02:
	/* 0x5f02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f07:
	/* 0x5f07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0c:
	/* 0x5f0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f11:
	/* 0x5f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f13:
	/* 0x5f13: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f18:
	/* 0x5f18: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5f1d:
	/* 0x5f1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f22:
	/* 0x5f22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f27:
	/* 0x5f27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f2c:
	/* 0x5f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f31:
	/* 0x5f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f33:
	/* 0x5f33: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f38:
	/* 0x5f38: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f3c:
	/* 0x5f3c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5f41:
	/* 0x5f41: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f46:
	/* 0x5f46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f4b:
	/* 0x5f4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f50:
	/* 0x5f50: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5f55:
	/* 0x5f55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5a:
	/* 0x5f5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f5c:
	/* 0x5f5c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f61:
	/* 0x5f61: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5f66:
	/* 0x5f66: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f6a:
	/* 0x5f6a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f6f:
	/* 0x5f6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f74:
	/* 0x5f74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f79:
	/* 0x5f79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f7e:
	/* 0x5f7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f80:
	/* 0x5f80: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5f85:
	/* 0x5f85: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5f88:
	/* 0x5f88: je     6157 <trace_ret_vfs_writev_tail+0x6157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24919ULL;
	}
x86_l_5f8e:
	/* 0x5f8e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f93:
	/* 0x5f93: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5f96:
	/* 0x5f96: je     6157 <trace_ret_vfs_writev_tail+0x6157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24919ULL;
	}
x86_l_5f9c:
	/* 0x5f9c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5fa0:
	/* 0x5fa0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fa5:
	/* 0x5fa5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5faa:
	/* 0x5faa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5faf:
	/* 0x5faf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
	return 24500ULL;
}

static __noinline __u64 tracee_trace_ret_vfs_writev_tail_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24500ULL: goto x86_l_5fb4;
	case 24502ULL: goto x86_l_5fb6;
	case 24506ULL: goto x86_l_5fba;
	case 24508ULL: goto x86_l_5fbc;
	case 24514ULL: goto x86_l_5fc2;
	case 24517ULL: goto x86_l_5fc5;
	case 24519ULL: goto x86_l_5fc7;
	case 24525ULL: goto x86_l_5fcd;
	case 24530ULL: goto x86_l_5fd2;
	case 24536ULL: goto x86_l_5fd8;
	case 24541ULL: goto x86_l_5fdd;
	case 24543ULL: goto x86_l_5fdf;
	case 24548ULL: goto x86_l_5fe4;
	case 24550ULL: goto x86_l_5fe6;
	case 24553ULL: goto x86_l_5fe9;
	case 24559ULL: goto x86_l_5fef;
	case 24563ULL: goto x86_l_5ff3;
	case 24569ULL: goto x86_l_5ff9;
	case 24574ULL: goto x86_l_5ffe;
	case 24578ULL: goto x86_l_6002;
	case 24581ULL: goto x86_l_6005;
	case 24586ULL: goto x86_l_600a;
	case 24591ULL: goto x86_l_600f;
	case 24594ULL: goto x86_l_6012;
	case 24600ULL: goto x86_l_6018;
	case 24605ULL: goto x86_l_601d;
	case 24610ULL: goto x86_l_6022;
	case 24616ULL: goto x86_l_6028;
	case 24620ULL: goto x86_l_602c;
	case 24625ULL: goto x86_l_6031;
	case 24630ULL: goto x86_l_6036;
	case 24635ULL: goto x86_l_603b;
	case 24640ULL: goto x86_l_6040;
	case 24644ULL: goto x86_l_6044;
	case 24649ULL: goto x86_l_6049;
	case 24651ULL: goto x86_l_604b;
	case 24656ULL: goto x86_l_6050;
	case 24661ULL: goto x86_l_6055;
	case 24666ULL: goto x86_l_605a;
	case 24671ULL: goto x86_l_605f;
	case 24676ULL: goto x86_l_6064;
	case 24681ULL: goto x86_l_6069;
	case 24683ULL: goto x86_l_606b;
	case 24688ULL: goto x86_l_6070;
	case 24693ULL: goto x86_l_6075;
	case 24698ULL: goto x86_l_607a;
	case 24703ULL: goto x86_l_607f;
	case 24708ULL: goto x86_l_6084;
	case 24713ULL: goto x86_l_6089;
	case 24715ULL: goto x86_l_608b;
	case 24720ULL: goto x86_l_6090;
	case 24724ULL: goto x86_l_6094;
	case 24729ULL: goto x86_l_6099;
	case 24734ULL: goto x86_l_609e;
	case 24739ULL: goto x86_l_60a3;
	case 24744ULL: goto x86_l_60a8;
	case 24747ULL: goto x86_l_60ab;
	case 24749ULL: goto x86_l_60ad;
	case 24754ULL: goto x86_l_60b2;
	case 24759ULL: goto x86_l_60b7;
	case 24763ULL: goto x86_l_60bb;
	case 24768ULL: goto x86_l_60c0;
	case 24773ULL: goto x86_l_60c5;
	case 24778ULL: goto x86_l_60ca;
	case 24783ULL: goto x86_l_60cf;
	case 24785ULL: goto x86_l_60d1;
	case 24790ULL: goto x86_l_60d6;
	case 24793ULL: goto x86_l_60d9;
	case 24799ULL: goto x86_l_60df;
	case 24804ULL: goto x86_l_60e4;
	case 24807ULL: goto x86_l_60e7;
	case 24813ULL: goto x86_l_60ed;
	case 24817ULL: goto x86_l_60f1;
	case 24822ULL: goto x86_l_60f6;
	case 24827ULL: goto x86_l_60fb;
	case 24832ULL: goto x86_l_6100;
	case 24837ULL: goto x86_l_6105;
	case 24839ULL: goto x86_l_6107;
	case 24843ULL: goto x86_l_610b;
	case 24845ULL: goto x86_l_610d;
	case 24851ULL: goto x86_l_6113;
	case 24853ULL: goto x86_l_6115;
	case 24855ULL: goto x86_l_6117;
	case 24861ULL: goto x86_l_611d;
	case 24866ULL: goto x86_l_6122;
	case 24872ULL: goto x86_l_6128;
	case 24875ULL: goto x86_l_612b;
	case 24877ULL: goto x86_l_612d;
	case 24882ULL: goto x86_l_6132;
	case 24884ULL: goto x86_l_6134;
	case 24887ULL: goto x86_l_6137;
	case 24893ULL: goto x86_l_613d;
	case 24896ULL: goto x86_l_6140;
	case 24902ULL: goto x86_l_6146;
	case 24907ULL: goto x86_l_614b;
	case 24909ULL: goto x86_l_614d;
	case 24914ULL: goto x86_l_6152;
	case 24919ULL: goto x86_l_6157;
	case 24922ULL: goto x86_l_615a;
	case 24928ULL: goto x86_l_6160;
	case 24933ULL: goto x86_l_6165;
	case 24938ULL: goto x86_l_616a;
	case 24944ULL: goto x86_l_6170;
	case 24948ULL: goto x86_l_6174;
	case 24953ULL: goto x86_l_6179;
	case 24958ULL: goto x86_l_617e;
	case 24963ULL: goto x86_l_6183;
	case 24968ULL: goto x86_l_6188;
	case 24972ULL: goto x86_l_618c;
	case 24977ULL: goto x86_l_6191;
	case 24979ULL: goto x86_l_6193;
	case 24984ULL: goto x86_l_6198;
	case 24989ULL: goto x86_l_619d;
	case 24994ULL: goto x86_l_61a2;
	case 24999ULL: goto x86_l_61a7;
	case 25004ULL: goto x86_l_61ac;
	case 25009ULL: goto x86_l_61b1;
	case 25011ULL: goto x86_l_61b3;
	case 25016ULL: goto x86_l_61b8;
	case 25021ULL: goto x86_l_61bd;
	case 25026ULL: goto x86_l_61c2;
	case 25031ULL: goto x86_l_61c7;
	case 25036ULL: goto x86_l_61cc;
	case 25041ULL: goto x86_l_61d1;
	case 25043ULL: goto x86_l_61d3;
	case 25048ULL: goto x86_l_61d8;
	case 25051ULL: goto x86_l_61db;
	case 25057ULL: goto x86_l_61e1;
	case 25062ULL: goto x86_l_61e6;
	case 25067ULL: goto x86_l_61eb;
	case 25073ULL: goto x86_l_61f1;
	case 25077ULL: goto x86_l_61f5;
	case 25082ULL: goto x86_l_61fa;
	case 25087ULL: goto x86_l_61ff;
	case 25092ULL: goto x86_l_6204;
	case 25097ULL: goto x86_l_6209;
	case 25101ULL: goto x86_l_620d;
	case 25106ULL: goto x86_l_6212;
	case 25108ULL: goto x86_l_6214;
	case 25113ULL: goto x86_l_6219;
	case 25118ULL: goto x86_l_621e;
	case 25123ULL: goto x86_l_6223;
	case 25128ULL: goto x86_l_6228;
	case 25133ULL: goto x86_l_622d;
	case 25138ULL: goto x86_l_6232;
	case 25140ULL: goto x86_l_6234;
	case 25145ULL: goto x86_l_6239;
	case 25150ULL: goto x86_l_623e;
	case 25155ULL: goto x86_l_6243;
	case 25160ULL: goto x86_l_6248;
	case 25165ULL: goto x86_l_624d;
	case 25170ULL: goto x86_l_6252;
	case 25172ULL: goto x86_l_6254;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5fb4:
	/* 0x5fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fb6:
	/* 0x5fb6: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5fba:
	/* 0x5fba: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5fbc:
	/* 0x5fbc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5fc2:
	/* 0x5fc2: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_5fc5:
	/* 0x5fc5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fc7:
	/* 0x5fc7: jb     344d <trace_ret_vfs_writev_tail+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13389ULL;
	}
x86_l_5fcd:
	/* 0x5fcd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fd2:
	/* 0x5fd2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5fd8:
	/* 0x5fd8: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_5fdd:
	/* 0x5fdd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5fdf:
	/* 0x5fdf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5fe4:
	/* 0x5fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe6:
	/* 0x5fe6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5fe9:
	/* 0x5fe9: jl     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 15355ULL;
	}
x86_l_5fef:
	/* 0x5fef: lea    ecx,[r14-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ff3:
	/* 0x5ff3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ff9:
	/* 0x5ff9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5ffe:
	/* 0x5ffe: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6002:
	/* 0x6002: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6005:
	/* 0x6005: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_600a:
	/* 0x600a: jmp    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	return 15355ULL;
x86_l_600f:
	/* 0x600f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6012:
	/* 0x6012: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_6018:
	/* 0x6018: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_601d:
	/* 0x601d: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_6022:
	/* 0x6022: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_6028:
	/* 0x6028: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_602c:
	/* 0x602c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6031:
	/* 0x6031: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6036:
	/* 0x6036: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_603b:
	/* 0x603b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6040:
	/* 0x6040: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6044:
	/* 0x6044: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6049:
	/* 0x6049: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_604b:
	/* 0x604b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6050:
	/* 0x6050: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6055:
	/* 0x6055: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_605a:
	/* 0x605a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_605f:
	/* 0x605f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6064:
	/* 0x6064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6069:
	/* 0x6069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606b:
	/* 0x606b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6070:
	/* 0x6070: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6075:
	/* 0x6075: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_607a:
	/* 0x607a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_607f:
	/* 0x607f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6084:
	/* 0x6084: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6089:
	/* 0x6089: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_608b:
	/* 0x608b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6090:
	/* 0x6090: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6094:
	/* 0x6094: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6099:
	/* 0x6099: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_609e:
	/* 0x609e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60a3:
	/* 0x60a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60a8:
	/* 0x60a8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_60ab:
	/* 0x60ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60ad:
	/* 0x60ad: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60b2:
	/* 0x60b2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60b7:
	/* 0x60b7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_60bb:
	/* 0x60bb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60c0:
	/* 0x60c0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_60c5:
	/* 0x60c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60ca:
	/* 0x60ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60cf:
	/* 0x60cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60d1:
	/* 0x60d1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60d6:
	/* 0x60d6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_60d9:
	/* 0x60d9: je     61d8 <trace_ret_vfs_writev_tail+0x61d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d8;
	}
x86_l_60df:
	/* 0x60df: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60e4:
	/* 0x60e4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_60e7:
	/* 0x60e7: je     61d8 <trace_ret_vfs_writev_tail+0x61d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d8;
	}
x86_l_60ed:
	/* 0x60ed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_60f1:
	/* 0x60f1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60f6:
	/* 0x60f6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_60fb:
	/* 0x60fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6100:
	/* 0x6100: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6105:
	/* 0x6105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6107:
	/* 0x6107: mov    esi,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_610b:
	/* 0x610b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_610d:
	/* 0x610d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6113:
	/* 0x6113: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6115:
	/* 0x6115: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6117:
	/* 0x6117: jb     2dfc <trace_ret_vfs_writev_tail+0x2dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11772ULL;
	}
x86_l_611d:
	/* 0x611d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6122:
	/* 0x6122: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6128:
	/* 0x6128: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_612b:
	/* 0x612b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_612d:
	/* 0x612d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6132:
	/* 0x6132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6134:
	/* 0x6134: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6137:
	/* 0x6137: jl     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10935ULL;
	}
x86_l_613d:
	/* 0x613d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6140:
	/* 0x6140: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6146:
	/* 0x6146: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_614b:
	/* 0x614b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_614d:
	/* 0x614d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6152:
	/* 0x6152: jmp    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	return 10935ULL;
x86_l_6157:
	/* 0x6157: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_615a:
	/* 0x615a: jne    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15355ULL;
	}
x86_l_6160:
	/* 0x6160: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6165:
	/* 0x6165: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_616a:
	/* 0x616a: je     3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15355ULL;
	}
x86_l_6170:
	/* 0x6170: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6174:
	/* 0x6174: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6179:
	/* 0x6179: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_617e:
	/* 0x617e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6183:
	/* 0x6183: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6188:
	/* 0x6188: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_618c:
	/* 0x618c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6191:
	/* 0x6191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6193:
	/* 0x6193: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6198:
	/* 0x6198: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_619d:
	/* 0x619d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61a2:
	/* 0x61a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61a7:
	/* 0x61a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61ac:
	/* 0x61ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61b1:
	/* 0x61b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61b3:
	/* 0x61b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61b8:
	/* 0x61b8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_61bd:
	/* 0x61bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61c2:
	/* 0x61c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61c7:
	/* 0x61c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61cc:
	/* 0x61cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61d1:
	/* 0x61d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61d3:
	/* 0x61d3: jmp    3bfb <trace_ret_vfs_writev_tail+0x3bfb> */
	return 15355ULL;
x86_l_61d8:
	/* 0x61d8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_61db:
	/* 0x61db: jne    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10935ULL;
	}
x86_l_61e1:
	/* 0x61e1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61e6:
	/* 0x61e6: cmp    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_61eb:
	/* 0x61eb: je     2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10935ULL;
	}
x86_l_61f1:
	/* 0x61f1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61f5:
	/* 0x61f5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_61fa:
	/* 0x61fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61ff:
	/* 0x61ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6204:
	/* 0x6204: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6209:
	/* 0x6209: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_620d:
	/* 0x620d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6212:
	/* 0x6212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6214:
	/* 0x6214: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6219:
	/* 0x6219: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_621e:
	/* 0x621e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6223:
	/* 0x6223: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6228:
	/* 0x6228: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_622d:
	/* 0x622d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6232:
	/* 0x6232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6234:
	/* 0x6234: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6239:
	/* 0x6239: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_623e:
	/* 0x623e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6243:
	/* 0x6243: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6248:
	/* 0x6248: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_624d:
	/* 0x624d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6252:
	/* 0x6252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6254:
	/* 0x6254: jmp    2ab7 <trace_ret_vfs_writev_tail+0x2ab7> */
	return 10935ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_vfs_writev_tail_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22116U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2184ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2189ULL && __x86_pc <= 3898ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3901ULL && __x86_pc <= 5531ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5533ULL && __x86_pc <= 7263ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7265ULL && __x86_pc <= 9065ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9070ULL && __x86_pc <= 10782ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10787ULL && __x86_pc <= 12501ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12509ULL && __x86_pc <= 14284ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14286ULL && __x86_pc <= 16007ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16011ULL && __x86_pc <= 17707ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17712ULL && __x86_pc <= 19402ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19407ULL && __x86_pc <= 21096ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21102ULL && __x86_pc <= 22797ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22801ULL && __x86_pc <= 24495ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 24500ULL && __x86_pc <= 25172ULL)
			__x86_pc = tracee_trace_ret_vfs_writev_tail_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

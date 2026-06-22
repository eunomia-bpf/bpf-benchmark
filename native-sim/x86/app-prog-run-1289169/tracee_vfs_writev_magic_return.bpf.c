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
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 30ULL: goto x86_l_1e;
	case 32ULL: goto x86_l_20;
	case 35ULL: goto x86_l_23;
	case 43ULL: goto x86_l_2b;
	case 48ULL: goto x86_l_30;
	case 55ULL: goto x86_l_37;
	case 63ULL: goto x86_l_3f;
	case 65ULL: goto x86_l_41;
	case 68ULL: goto x86_l_44;
	case 74ULL: goto x86_l_4a;
	case 77ULL: goto x86_l_4d;
	case 82ULL: goto x86_l_52;
	case 86ULL: goto x86_l_56;
	case 94ULL: goto x86_l_5e;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 105ULL: goto x86_l_69;
	case 107ULL: goto x86_l_6b;
	case 110ULL: goto x86_l_6e;
	case 118ULL: goto x86_l_76;
	case 123ULL: goto x86_l_7b;
	case 130ULL: goto x86_l_82;
	case 138ULL: goto x86_l_8a;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 157ULL: goto x86_l_9d;
	case 160ULL: goto x86_l_a0;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 184ULL: goto x86_l_b8;
	case 195ULL: goto x86_l_c3;
	case 200ULL: goto x86_l_c8;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 254ULL: goto x86_l_fe;
	case 258ULL: goto x86_l_102;
	case 263ULL: goto x86_l_107;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 279ULL: goto x86_l_117;
	case 281ULL: goto x86_l_119;
	case 289ULL: goto x86_l_121;
	case 291ULL: goto x86_l_123;
	case 295ULL: goto x86_l_127;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 323ULL: goto x86_l_143;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 338ULL: goto x86_l_152;
	case 343ULL: goto x86_l_157;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 366ULL: goto x86_l_16e;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 396ULL: goto x86_l_18c;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 413ULL: goto x86_l_19d;
	case 423ULL: goto x86_l_1a7;
	case 431ULL: goto x86_l_1af;
	case 442ULL: goto x86_l_1ba;
	case 453ULL: goto x86_l_1c5;
	case 464ULL: goto x86_l_1d0;
	case 475ULL: goto x86_l_1db;
	case 486ULL: goto x86_l_1e6;
	case 497ULL: goto x86_l_1f1;
	case 508ULL: goto x86_l_1fc;
	case 519ULL: goto x86_l_207;
	case 526ULL: goto x86_l_20e;
	case 534ULL: goto x86_l_216;
	case 542ULL: goto x86_l_21e;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 566ULL: goto x86_l_236;
	case 574ULL: goto x86_l_23e;
	case 582ULL: goto x86_l_246;
	case 590ULL: goto x86_l_24e;
	case 598ULL: goto x86_l_256;
	case 606ULL: goto x86_l_25e;
	case 614ULL: goto x86_l_266;
	case 622ULL: goto x86_l_26e;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 637ULL: goto x86_l_27d;
	case 641ULL: goto x86_l_281;
	case 645ULL: goto x86_l_285;
	case 649ULL: goto x86_l_289;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 674ULL: goto x86_l_2a2;
	case 679ULL: goto x86_l_2a7;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 691ULL: goto x86_l_2b3;
	case 696ULL: goto x86_l_2b8;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 724ULL: goto x86_l_2d4;
	case 726ULL: goto x86_l_2d6;
	case 730ULL: goto x86_l_2da;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 749ULL: goto x86_l_2ed;
	case 757ULL: goto x86_l_2f5;
	case 759ULL: goto x86_l_2f7;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 798ULL: goto x86_l_31e;
	case 802ULL: goto x86_l_322;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 825ULL: goto x86_l_339;
	case 833ULL: goto x86_l_341;
	case 835ULL: goto x86_l_343;
	case 838ULL: goto x86_l_346;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
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
	case 1185ULL: goto x86_l_4a1;
	case 1193ULL: goto x86_l_4a9;
	case 1201ULL: goto x86_l_4b1;
	case 1209ULL: goto x86_l_4b9;
	case 1217ULL: goto x86_l_4c1;
	case 1225ULL: goto x86_l_4c9;
	case 1233ULL: goto x86_l_4d1;
	case 1241ULL: goto x86_l_4d9;
	case 1249ULL: goto x86_l_4e1;
	case 1257ULL: goto x86_l_4e9;
	case 1265ULL: goto x86_l_4f1;
	case 1273ULL: goto x86_l_4f9;
	case 1281ULL: goto x86_l_501;
	case 1289ULL: goto x86_l_509;
	case 1297ULL: goto x86_l_511;
	case 1305ULL: goto x86_l_519;
	case 1312ULL: goto x86_l_520;
	case 1318ULL: goto x86_l_526;
	case 1325ULL: goto x86_l_52d;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1341ULL: goto x86_l_53d;
	case 1344ULL: goto x86_l_540;
	case 1347ULL: goto x86_l_543;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1365ULL: goto x86_l_555;
	case 1368ULL: goto x86_l_558;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1384ULL: goto x86_l_568;
	case 1391ULL: goto x86_l_56f;
	case 1395ULL: goto x86_l_573;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1418ULL: goto x86_l_58a;
	case 1426ULL: goto x86_l_592;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
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
	case 1688ULL: goto x86_l_698;
	case 1695ULL: goto x86_l_69f;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1735ULL: goto x86_l_6c7;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1751ULL: goto x86_l_6d7;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1778ULL: goto x86_l_6f2;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1815ULL: goto x86_l_717;
	case 1823ULL: goto x86_l_71f;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1855ULL: goto x86_l_73f;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1872ULL: goto x86_l_750;
	case 1877ULL: goto x86_l_755;
	case 1879ULL: goto x86_l_757;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1897ULL: goto x86_l_769;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1955ULL: goto x86_l_7a3;
	case 1962ULL: goto x86_l_7aa;
	case 1966ULL: goto x86_l_7ae;
	case 1970ULL: goto x86_l_7b2;
	case 1974ULL: goto x86_l_7b6;
	case 1979ULL: goto x86_l_7bb;
	case 1987ULL: goto x86_l_7c3;
	case 1992ULL: goto x86_l_7c8;
	case 1994ULL: goto x86_l_7ca;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2025ULL: goto x86_l_7e9;
	case 2027ULL: goto x86_l_7eb;
	case 2035ULL: goto x86_l_7f3;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2059ULL: goto x86_l_80b;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2080ULL: goto x86_l_820;
	case 2085ULL: goto x86_l_825;
	case 2088ULL: goto x86_l_828;
	case 2090ULL: goto x86_l_82a;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2129ULL: goto x86_l_851;
	case 2136ULL: goto x86_l_858;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2160ULL: goto x86_l_870;
	case 2162ULL: goto x86_l_872;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2200ULL: goto x86_l_898;
	case 2204ULL: goto x86_l_89c;
	case 2208ULL: goto x86_l_8a0;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2272ULL: goto x86_l_8e0;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2297ULL: goto x86_l_8f9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 328ULL);
x86_l_a:
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: movabs rbx,0x2d700000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3122441224192ULL);
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
	/* 0x23: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2b:
	/* 0x2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30:
	/* 0x30: mov    rdi,QWORD PTR [rip+0x3217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_37:
	/* 0x37: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3f:
	/* 0x3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41:
	/* 0x41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44:
	/* 0x44: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_4a:
	/* 0x4a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52:
	/* 0x52: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_5e:
	/* 0x5e: mov    r15,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62:
	/* 0x62: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_67:
	/* 0x67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69:
	/* 0x69: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6b:
	/* 0x6b: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_76:
	/* 0x76: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_7b:
	/* 0x7b: mov    rdi,QWORD PTR [rip+0x3217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_82:
	/* 0x82: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_96:
	/* 0x96: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_9b:
	/* 0x9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d:
	/* 0x9d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a4:
	/* 0xa4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a9:
	/* 0xa9: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b1:
	/* 0xb1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b6:
	/* 0xb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8:
	/* 0xb8: test   DWORD PTR [rsp+0xb0],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755916341248ULL);
x86_l_c3:
	/* 0xc3: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_c8:
	/* 0xc8: jne    14a <vfs_writev_magic_return+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a;
	}
x86_l_ce:
	/* 0xce: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_d3:
	/* 0xd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5:
	/* 0xd5: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_da:
	/* 0xda: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_dd:
	/* 0xdd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_df:
	/* 0xdf: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e3:
	/* 0xe3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e8:
	/* 0xe8: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f0:
	/* 0xf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f5:
	/* 0xf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7:
	/* 0xf7: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fe:
	/* 0xfe: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_102:
	/* 0x102: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107:
	/* 0x107: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10f:
	/* 0x10f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_114:
	/* 0x114: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_117:
	/* 0x117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119:
	/* 0x119: test   BYTE PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_121:
	/* 0x121: jne    129 <vfs_writev_magic_return+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_129;
	}
x86_l_123:
	/* 0x123: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127:
	/* 0x127: jmp    14a <vfs_writev_magic_return+0x14a> */
	goto x86_l_14a;
x86_l_129:
	/* 0x129: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e:
	/* 0x12e: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_135:
	/* 0x135: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a:
	/* 0x13a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c:
	/* 0x13c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: je     145 <vfs_writev_magic_return+0x145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145;
	}
x86_l_141:
	/* 0x141: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143:
	/* 0x143: jmp    14a <vfs_writev_magic_return+0x14a> */
	goto x86_l_14a;
x86_l_145:
	/* 0x145: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_14a:
	/* 0x14a: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_152:
	/* 0x152: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_157:
	/* 0x157: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_15e:
	/* 0x15e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_163:
	/* 0x163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165:
	/* 0x165: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_168:
	/* 0x168: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_16e:
	/* 0x16e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_171:
	/* 0x171: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_176:
	/* 0x176: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_17d:
	/* 0x17d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_182:
	/* 0x182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_18c:
	/* 0x18c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f:
	/* 0x18f: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_195:
	/* 0x195: mov    QWORD PTR [rsp+0x120],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_19d:
	/* 0x19d: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_1a7:
	/* 0x1a7: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1af:
	/* 0x1af: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1c5:
	/* 0x1c5: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1d0:
	/* 0x1d0: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1db:
	/* 0x1db: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1e6:
	/* 0x1e6: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1f1:
	/* 0x1f1: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1fc:
	/* 0x1fc: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_207:
	/* 0x207: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_216:
	/* 0x216: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21e:
	/* 0x21e: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_226:
	/* 0x226: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_22e:
	/* 0x22e: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_236:
	/* 0x236: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_246:
	/* 0x246: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_24e:
	/* 0x24e: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_256:
	/* 0x256: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_266:
	/* 0x266: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_26e:
	/* 0x26e: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_276:
	/* 0x276: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_27b:
	/* 0x27b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d:
	/* 0x27d: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_281:
	/* 0x281: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_285:
	/* 0x285: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_289:
	/* 0x289: mov    DWORD PTR [r14+0x70],0x2d7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337879ULL);
x86_l_291:
	/* 0x291: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_296:
	/* 0x296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298:
	/* 0x298: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b:
	/* 0x29b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2a0:
	/* 0x2a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2:
	/* 0x2a2: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2a7:
	/* 0x2a7: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2ab:
	/* 0x2ab: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2af:
	/* 0x2af: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3:
	/* 0x2b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b8:
	/* 0x2b8: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2bf:
	/* 0x2bf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c4:
	/* 0x2c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6:
	/* 0x2c6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2c9:
	/* 0x2c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: mov    r15,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2d4:
	/* 0x2d4: je     31a <vfs_writev_magic_return+0x31a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a;
	}
x86_l_2d6:
	/* 0x2d6: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2da:
	/* 0x2da: mov    DWORD PTR [rsp+0x10c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_2e1:
	/* 0x2e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e6:
	/* 0x2e6: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2ed:
	/* 0x2ed: lea    rsi,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_2f5:
	/* 0x2f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7:
	/* 0x2f7: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2fa:
	/* 0x2fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fd:
	/* 0x2fd: je     563 <vfs_writev_magic_return+0x563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_563;
	}
x86_l_303:
	/* 0x303: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_308:
	/* 0x308: jne    b94 <vfs_writev_magic_return+0xb94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2964ULL;
	}
x86_l_30e:
	/* 0x30e: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_313:
	/* 0x313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315:
	/* 0x315: jmp    c33 <vfs_writev_magic_return+0xc33> */
	return 3123ULL;
x86_l_31a:
	/* 0x31a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_322:
	/* 0x322: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_32d:
	/* 0x32d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_332:
	/* 0x332: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_339:
	/* 0x339: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_341:
	/* 0x341: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_343:
	/* 0x343: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_346:
	/* 0x346: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_34c:
	/* 0x34c: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_350:
	/* 0x350: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_357:
	/* 0x357: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_362:
	/* 0x362: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_36d:
	/* 0x36d: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_378:
	/* 0x378: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3d0:
	/* 0x3d0: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_480:
	/* 0x480: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_4a1:
	/* 0x4a1: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4a9:
	/* 0x4a9: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4b1:
	/* 0x4b1: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4b9:
	/* 0x4b9: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4c1:
	/* 0x4c1: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4c9:
	/* 0x4c9: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4d1:
	/* 0x4d1: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4d9:
	/* 0x4d9: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4e1:
	/* 0x4e1: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4e9:
	/* 0x4e9: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4f1:
	/* 0x4f1: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4f9:
	/* 0x4f9: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_501:
	/* 0x501: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_509:
	/* 0x509: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_511:
	/* 0x511: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_519:
	/* 0x519: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_520:
	/* 0x520: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_526:
	/* 0x526: mov    rbx,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_52d:
	/* 0x52d: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_535:
	/* 0x535: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_53a:
	/* 0x53a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_53d:
	/* 0x53d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_540:
	/* 0x540: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_543:
	/* 0x543: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_548:
	/* 0x548: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_54d:
	/* 0x54d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_550:
	/* 0x550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552:
	/* 0x552: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_555:
	/* 0x555: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_558:
	/* 0x558: jne    2d6 <vfs_writev_magic_return+0x2d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d6;
	}
x86_l_55e:
	/* 0x55e: jmp    2a09 <vfs_writev_magic_return+0x2a09> */
	return 10761ULL;
x86_l_563:
	/* 0x563: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_568:
	/* 0x568: mov    eax,DWORD PTR [rsp+0x10c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_56f:
	/* 0x56f: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_573:
	/* 0x573: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_57e:
	/* 0x57e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_583:
	/* 0x583: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_58a:
	/* 0x58a: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_592:
	/* 0x592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_594:
	/* 0x594: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_597:
	/* 0x597: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_5a5:
	/* 0x5a5: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a9:
	/* 0x5a9: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_5bb:
	/* 0x5bb: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5d1:
	/* 0x5d1: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_608:
	/* 0x608: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_613:
	/* 0x613: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_61b:
	/* 0x61b: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_63b:
	/* 0x63b: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_643:
	/* 0x643: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_64b:
	/* 0x64b: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_653:
	/* 0x653: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_65b:
	/* 0x65b: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_663:
	/* 0x663: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_66b:
	/* 0x66b: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_673:
	/* 0x673: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_67b:
	/* 0x67b: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_683:
	/* 0x683: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_68b:
	/* 0x68b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_698:
	/* 0x698: mov    rbx,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_69f:
	/* 0x69f: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6a7:
	/* 0x6a7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6ac:
	/* 0x6ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6af:
	/* 0x6af: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b5:
	/* 0x6b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ba:
	/* 0x6ba: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6bf:
	/* 0x6bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c4:
	/* 0x6c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c7:
	/* 0x6c7: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_6cd:
	/* 0x6cd: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_6d0:
	/* 0x6d0: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_6d7:
	/* 0x6d7: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6db:
	/* 0x6db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e0:
	/* 0x6e0: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x6f2: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6fa:
	/* 0x6fa: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ff:
	/* 0x6ff: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_703:
	/* 0x703: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_708:
	/* 0x708: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_710:
	/* 0x710: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_715:
	/* 0x715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_717:
	/* 0x717: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_71f:
	/* 0x71f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_723:
	/* 0x723: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_728:
	/* 0x728: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_730:
	/* 0x730: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_73f:
	/* 0x73f: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_743:
	/* 0x743: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_748:
	/* 0x748: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_750:
	/* 0x750: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_755:
	/* 0x755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_757:
	/* 0x757: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_75e:
	/* 0x75e: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_761:
	/* 0x761: mov    QWORD PTR [rsp+0x130],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_769:
	/* 0x769: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76d:
	/* 0x76d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_772:
	/* 0x772: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_77a:
	/* 0x77a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77f:
	/* 0x77f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_782:
	/* 0x782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_784:
	/* 0x784: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_78c:
	/* 0x78c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_791:
	/* 0x791: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_799:
	/* 0x799: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_79e:
	/* 0x79e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7a1:
	/* 0x7a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a3:
	/* 0x7a3: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7aa:
	/* 0x7aa: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7ae:
	/* 0x7ae: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7b2:
	/* 0x7b2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7b6:
	/* 0x7b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7bb:
	/* 0x7bb: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7c3:
	/* 0x7c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c8:
	/* 0x7c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ca:
	/* 0x7ca: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7d1:
	/* 0x7d1: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d9:
	/* 0x7d9: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7e1:
	/* 0x7e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e6:
	/* 0x7e6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7e9:
	/* 0x7e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7eb:
	/* 0x7eb: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7f3:
	/* 0x7f3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7f7:
	/* 0x7f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7fc:
	/* 0x7fc: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_804:
	/* 0x804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_809:
	/* 0x809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80b:
	/* 0x80b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_813:
	/* 0x813: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_818:
	/* 0x818: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_820:
	/* 0x820: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_825:
	/* 0x825: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_828:
	/* 0x828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82a:
	/* 0x82a: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_831:
	/* 0x831: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_835:
	/* 0x835: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_839:
	/* 0x839: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_83d:
	/* 0x83d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_842:
	/* 0x842: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_84a:
	/* 0x84a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_84f:
	/* 0x84f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_851:
	/* 0x851: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_858:
	/* 0x858: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_85b:
	/* 0x85b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_860:
	/* 0x860: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_868:
	/* 0x868: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_86d:
	/* 0x86d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_870:
	/* 0x870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_872:
	/* 0x872: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_87a:
	/* 0x87a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87f:
	/* 0x87f: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_887:
	/* 0x887: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_88c:
	/* 0x88c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_898:
	/* 0x898: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_89c:
	/* 0x89c: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8a0:
	/* 0x8a0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8a4:
	/* 0x8a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a9:
	/* 0x8a9: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8b1:
	/* 0x8b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b6:
	/* 0x8b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b8:
	/* 0x8b8: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8c0:
	/* 0x8c0: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8c4:
	/* 0x8c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8c9:
	/* 0x8c9: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8d1:
	/* 0x8d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: mov    r12d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8e0:
	/* 0x8e0: mov    QWORD PTR [rsp+0xa8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8e8:
	/* 0x8e8: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ec:
	/* 0x8ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f1:
	/* 0x8f1: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8f9:
	/* 0x8f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 2302ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2302ULL: goto x86_l_8fe;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2345ULL: goto x86_l_929;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2377ULL: goto x86_l_949;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2432ULL: goto x86_l_980;
	case 2437ULL: goto x86_l_985;
	case 2440ULL: goto x86_l_988;
	case 2442ULL: goto x86_l_98a;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2480ULL: goto x86_l_9b0;
	case 2484ULL: goto x86_l_9b4;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2512ULL: goto x86_l_9d0;
	case 2519ULL: goto x86_l_9d7;
	case 2522ULL: goto x86_l_9da;
	case 2526ULL: goto x86_l_9de;
	case 2534ULL: goto x86_l_9e6;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2572ULL: goto x86_l_a0c;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2621ULL: goto x86_l_a3d;
	case 2625ULL: goto x86_l_a41;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2635ULL: goto x86_l_a4b;
	case 2638ULL: goto x86_l_a4e;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2662ULL: goto x86_l_a66;
	case 2670ULL: goto x86_l_a6e;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2683ULL: goto x86_l_a7b;
	case 2688ULL: goto x86_l_a80;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2711ULL: goto x86_l_a97;
	case 2715ULL: goto x86_l_a9b;
	case 2723ULL: goto x86_l_aa3;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2740ULL: goto x86_l_ab4;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2790ULL: goto x86_l_ae6;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2800ULL: goto x86_l_af0;
	case 2808ULL: goto x86_l_af8;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2849ULL: goto x86_l_b21;
	case 2851ULL: goto x86_l_b23;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2872ULL: goto x86_l_b38;
	case 2877ULL: goto x86_l_b3d;
	case 2879ULL: goto x86_l_b3f;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2910ULL: goto x86_l_b5e;
	case 2913ULL: goto x86_l_b61;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2940ULL: goto x86_l_b7c;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3031ULL: goto x86_l_bd7;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3046ULL: goto x86_l_be6;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3074ULL: goto x86_l_c02;
	case 3082ULL: goto x86_l_c0a;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3111ULL: goto x86_l_c27;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3123ULL: goto x86_l_c33;
	case 3127ULL: goto x86_l_c37;
	case 3131ULL: goto x86_l_c3b;
	case 3135ULL: goto x86_l_c3f;
	case 3140ULL: goto x86_l_c44;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3157ULL: goto x86_l_c55;
	case 3159ULL: goto x86_l_c57;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3176ULL: goto x86_l_c68;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3208ULL: goto x86_l_c88;
	case 3219ULL: goto x86_l_c93;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3239ULL: goto x86_l_ca7;
	case 3247ULL: goto x86_l_caf;
	case 3249ULL: goto x86_l_cb1;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3272ULL: goto x86_l_cc8;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3281ULL: goto x86_l_cd1;
	case 3288ULL: goto x86_l_cd8;
	case 3291ULL: goto x86_l_cdb;
	case 3298ULL: goto x86_l_ce2;
	case 3302ULL: goto x86_l_ce6;
	case 3306ULL: goto x86_l_cea;
	case 3313ULL: goto x86_l_cf1;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3342ULL: goto x86_l_d0e;
	case 3346ULL: goto x86_l_d12;
	case 3353ULL: goto x86_l_d19;
	case 3357ULL: goto x86_l_d1d;
	case 3364ULL: goto x86_l_d24;
	case 3371ULL: goto x86_l_d2b;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3385ULL: goto x86_l_d39;
	case 3393ULL: goto x86_l_d41;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3409ULL: goto x86_l_d51;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3436ULL: goto x86_l_d6c;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3448ULL: goto x86_l_d78;
	case 3451ULL: goto x86_l_d7b;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3478ULL: goto x86_l_d96;
	case 3481ULL: goto x86_l_d99;
	case 3483ULL: goto x86_l_d9b;
	case 3485ULL: goto x86_l_d9d;
	case 3493ULL: goto x86_l_da5;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3578ULL: goto x86_l_dfa;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3597ULL: goto x86_l_e0d;
	case 3600ULL: goto x86_l_e10;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3615ULL: goto x86_l_e1f;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3628ULL: goto x86_l_e2c;
	case 3634ULL: goto x86_l_e32;
	case 3641ULL: goto x86_l_e39;
	case 3649ULL: goto x86_l_e41;
	case 3656ULL: goto x86_l_e48;
	case 3664ULL: goto x86_l_e50;
	case 3671ULL: goto x86_l_e57;
	case 3679ULL: goto x86_l_e5f;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3699ULL: goto x86_l_e73;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3716ULL: goto x86_l_e84;
	case 3724ULL: goto x86_l_e8c;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3769ULL: goto x86_l_eb9;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3781ULL: goto x86_l_ec5;
	case 3789ULL: goto x86_l_ecd;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3816ULL: goto x86_l_ee8;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3831ULL: goto x86_l_ef7;
	case 3839ULL: goto x86_l_eff;
	case 3846ULL: goto x86_l_f06;
	case 3849ULL: goto x86_l_f09;
	case 3851ULL: goto x86_l_f0b;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3885ULL: goto x86_l_f2d;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3894ULL: goto x86_l_f36;
	case 3901ULL: goto x86_l_f3d;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3952ULL: goto x86_l_f70;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3971ULL: goto x86_l_f83;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3980ULL: goto x86_l_f8c;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3987ULL: goto x86_l_f93;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4004ULL: goto x86_l_fa4;
	case 4007ULL: goto x86_l_fa7;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4039ULL: goto x86_l_fc7;
	case 4046ULL: goto x86_l_fce;
	case 4054ULL: goto x86_l_fd6;
	case 4061ULL: goto x86_l_fdd;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4101ULL: goto x86_l_1005;
	case 4103ULL: goto x86_l_1007;
	case 4107ULL: goto x86_l_100b;
	case 4115ULL: goto x86_l_1013;
	case 4122ULL: goto x86_l_101a;
	case 4125ULL: goto x86_l_101d;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_8fe:
	/* 0x8fe: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_901:
	/* 0x901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_903:
	/* 0x903: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_90b:
	/* 0x90b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_910:
	/* 0x910: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_918:
	/* 0x918: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_91d:
	/* 0x91d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_920:
	/* 0x920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_922:
	/* 0x922: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_929:
	/* 0x929: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_92d:
	/* 0x92d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_931:
	/* 0x931: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_935:
	/* 0x935: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93a:
	/* 0x93a: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_942:
	/* 0x942: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_947:
	/* 0x947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_949:
	/* 0x949: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_951:
	/* 0x951: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_955:
	/* 0x955: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_95a:
	/* 0x95a: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_962:
	/* 0x962: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_967:
	/* 0x967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_969:
	/* 0x969: cmp    r12d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 176ULL);
x86_l_971:
	/* 0x971: jne    9da <vfs_writev_magic_return+0x9da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9da;
	}
x86_l_973:
	/* 0x973: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_978:
	/* 0x978: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_980:
	/* 0x980: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_985:
	/* 0x985: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_988:
	/* 0x988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98a:
	/* 0x98a: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_992:
	/* 0x992: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_997:
	/* 0x997: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_99f:
	/* 0x99f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9a4:
	/* 0x9a4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9a7:
	/* 0x9a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9b0:
	/* 0x9b0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_9b4:
	/* 0x9b4: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b8:
	/* 0x9b8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9bc:
	/* 0x9bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c1:
	/* 0x9c1: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9c9:
	/* 0x9c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9ce:
	/* 0x9ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d0:
	/* 0x9d0: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9d7:
	/* 0x9d7: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9da:
	/* 0x9da: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9de:
	/* 0x9de: mov    rbx,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_9e6:
	/* 0x9e6: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9ed:
	/* 0x9ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f2:
	/* 0x9f2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9fa:
	/* 0x9fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ff:
	/* 0x9ff: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a02:
	/* 0xa02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a04:
	/* 0xa04: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a0c:
	/* 0xa0c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a10:
	/* 0xa10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a15:
	/* 0xa15: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a1d:
	/* 0xa1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a22:
	/* 0xa22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a24:
	/* 0xa24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a29:
	/* 0xa29: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a31:
	/* 0xa31: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a36:
	/* 0xa36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a3b:
	/* 0xa3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3d:
	/* 0xa3d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a41:
	/* 0xa41: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a44:
	/* 0xa44: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a49:
	/* 0xa49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4b:
	/* 0xa4b: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a4e:
	/* 0xa4e: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a52:
	/* 0xa52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a57:
	/* 0xa57: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a5f:
	/* 0xa5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a64:
	/* 0xa64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a66:
	/* 0xa66: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a6e:
	/* 0xa6e: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a72:
	/* 0xa72: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a77:
	/* 0xa77: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a7b:
	/* 0xa7b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a80:
	/* 0xa80: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a88:
	/* 0xa88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a8d:
	/* 0xa8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8f:
	/* 0xa8f: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a97:
	/* 0xa97: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a9b:
	/* 0xa9b: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_aa3:
	/* 0xaa3: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_aa7:
	/* 0xaa7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aac:
	/* 0xaac: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ab4:
	/* 0xab4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab9:
	/* 0xab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abb:
	/* 0xabb: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ac3:
	/* 0xac3: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ac7:
	/* 0xac7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_acc:
	/* 0xacc: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ad4:
	/* 0xad4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ad9:
	/* 0xad9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ade:
	/* 0xade: test   BYTE PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_ae6:
	/* 0xae6: je     aec <vfs_writev_magic_return+0xaec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aec;
	}
x86_l_ae8:
	/* 0xae8: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_aec:
	/* 0xaec: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_af0:
	/* 0xaf0: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_af8:
	/* 0xaf8: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_b00:
	/* 0xb00: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_b05:
	/* 0xb05: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b0a:
	/* 0xb0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0c:
	/* 0xb0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b11:
	/* 0xb11: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b19:
	/* 0xb19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b1e:
	/* 0xb1e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b21:
	/* 0xb21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b23:
	/* 0xb23: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b2b:
	/* 0xb2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b30:
	/* 0xb30: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b38:
	/* 0xb38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b3d:
	/* 0xb3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3f:
	/* 0xb3f: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b47:
	/* 0xb47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b4c:
	/* 0xb4c: lea    rbx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b54:
	/* 0xb54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b57:
	/* 0xb57: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b5c:
	/* 0xb5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5e:
	/* 0xb5e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_b61:
	/* 0xb61: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b6a:
	/* 0xb6a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: mov    r12,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_b7c:
	/* 0xb7c: mov    r15,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_b84:
	/* 0xb84: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b89:
	/* 0xb89: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b8e:
	/* 0xb8e: je     30e <vfs_writev_magic_return+0x30e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 782ULL;
	}
x86_l_b94:
	/* 0xb94: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b99:
	/* 0xb99: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_ba0:
	/* 0xba0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba5:
	/* 0xba5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_baa:
	/* 0xbaa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_baf:
	/* 0xbaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb1:
	/* 0xbb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bb6:
	/* 0xbb6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bbb:
	/* 0xbbb: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bc3:
	/* 0xbc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc8:
	/* 0xbc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bca:
	/* 0xbca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bcf:
	/* 0xbcf: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bd7:
	/* 0xbd7: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bdf:
	/* 0xbdf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be4:
	/* 0xbe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be6:
	/* 0xbe6: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bee:
	/* 0xbee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bf3:
	/* 0xbf3: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bfb:
	/* 0xbfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c00:
	/* 0xc00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c02:
	/* 0xc02: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c0a:
	/* 0xc0a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_c0d:
	/* 0xc0d: je     c31 <vfs_writev_magic_return+0xc31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c31;
	}
x86_l_c0f:
	/* 0xc0f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c18:
	/* 0xc18: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c20:
	/* 0xc20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c25:
	/* 0xc25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c27:
	/* 0xc27: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c2f:
	/* 0xc2f: jmp    c33 <vfs_writev_magic_return+0xc33> */
	goto x86_l_c33;
x86_l_c31:
	/* 0xc31: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c33:
	/* 0xc33: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c37:
	/* 0xc37: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3b:
	/* 0xc3b: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c3f:
	/* 0xc3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c44:
	/* 0xc44: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c4b:
	/* 0xc4b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c50:
	/* 0xc50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c52:
	/* 0xc52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c55:
	/* 0xc55: je     c6d <vfs_writev_magic_return+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c6d;
	}
x86_l_c57:
	/* 0xc57: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c5a:
	/* 0xc5a: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c60:
	/* 0xc60: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c63:
	/* 0xc63: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c66:
	/* 0xc66: jne    c6d <vfs_writev_magic_return+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c6d;
	}
x86_l_c68:
	/* 0xc68: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c6d:
	/* 0xc6d: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c72:
	/* 0xc72: cmp    ax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c77:
	/* 0xc77: jne    29db <vfs_writev_magic_return+0x29db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10715ULL;
	}
x86_l_c7d:
	/* 0xc7d: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c88:
	/* 0xc88: mov    DWORD PTR [rsp+0xb0],0x2d7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244823ULL);
x86_l_c93:
	/* 0xc93: mov    WORD PTR [rsp+0x80],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c9b:
	/* 0xc9b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ca0:
	/* 0xca0: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_ca7:
	/* 0xca7: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_caf:
	/* 0xcaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb1:
	/* 0xcb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb4:
	/* 0xcb4: je     d24 <vfs_writev_magic_return+0xd24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d24;
	}
x86_l_cb6:
	/* 0xcb6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cbb:
	/* 0xcbb: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cc3:
	/* 0xcc3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_cc6:
	/* 0xcc6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cc8:
	/* 0xcc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: je     d24 <vfs_writev_magic_return+0xd24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d24;
	}
x86_l_ccd:
	/* 0xccd: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd1:
	/* 0xcd1: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_cd8:
	/* 0xcd8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_ce2:
	/* 0xce2: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce6:
	/* 0xce6: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cea:
	/* 0xcea: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_cf1:
	/* 0xcf1: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_cf8:
	/* 0xcf8: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cfc:
	/* 0xcfc: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_d03:
	/* 0xd03: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d07:
	/* 0xd07: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_d0e:
	/* 0xd0e: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d12:
	/* 0xd12: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_d19:
	/* 0xd19: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d1d:
	/* 0xd1d: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_d24:
	/* 0xd24: mov    rdx,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_d2b:
	/* 0xd2b: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d32:
	/* 0xd32: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d35:
	/* 0xd35: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_d39:
	/* 0xd39: mov    QWORD PTR [rsp+0x130],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_d41:
	/* 0xd41: jne    d5c <vfs_writev_magic_return+0xd5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d5c;
	}
x86_l_d43:
	/* 0xd43: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d45:
	/* 0xd45: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d47:
	/* 0xd47: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_d4a:
	/* 0xd4a: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d51:
	/* 0xd51: jne    15a8 <vfs_writev_magic_return+0x15a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5544ULL;
	}
x86_l_d57:
	/* 0xd57: jmp    2a0b <vfs_writev_magic_return+0x2a0b> */
	return 10763ULL;
x86_l_d5c:
	/* 0xd5c: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d63:
	/* 0xd63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d66:
	/* 0xd66: je     f36 <vfs_writev_magic_return+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f36;
	}
x86_l_d6c:
	/* 0xd6c: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d73:
	/* 0xd73: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d76:
	/* 0xd76: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d78:
	/* 0xd78: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d7b:
	/* 0xd7b: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_d7f:
	/* 0xd7f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d82:
	/* 0xd82: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d85:
	/* 0xd85: xor    rbp,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d8c:
	/* 0xd8c: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d8f:
	/* 0xd8f: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d96:
	/* 0xd96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d99:
	/* 0xd99: je     dc2 <vfs_writev_magic_return+0xdc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc2;
	}
x86_l_d9b:
	/* 0xd9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d9d:
	/* 0xd9d: mov    rdx,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_da5:
	/* 0xda5: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_dac:
	/* 0xdac: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_daf:
	/* 0xdaf: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_db2:
	/* 0xdb2: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_db5:
	/* 0xdb5: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_dbc:
	/* 0xdbc: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dbf:
	/* 0xdbf: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dc2:
	/* 0xdc2: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_dc9:
	/* 0xdc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dcc:
	/* 0xdcc: je     de8 <vfs_writev_magic_return+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de8;
	}
x86_l_dce:
	/* 0xdce: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_dd2:
	/* 0xdd2: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dd5:
	/* 0xdd5: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_dd8:
	/* 0xdd8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ddb:
	/* 0xddb: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_de2:
	/* 0xde2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_de5:
	/* 0xde5: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_de8:
	/* 0xde8: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_def:
	/* 0xdef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_dfa:
	/* 0xdfa: je     e13 <vfs_writev_magic_return+0xe13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e13;
	}
x86_l_dfc:
	/* 0xdfc: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dff:
	/* 0xdff: movsx  rcx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e03:
	/* 0xe03: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e06:
	/* 0xe06: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_e0d:
	/* 0xe0d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e10:
	/* 0xe10: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e13:
	/* 0xe13: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_e18:
	/* 0xe18: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_e1f:
	/* 0xe1f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_e22:
	/* 0xe22: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e27:
	/* 0xe27: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2c:
	/* 0xe2c: je     fa7 <vfs_writev_magic_return+0xfa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa7;
	}
x86_l_e32:
	/* 0xe32: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e39:
	/* 0xe39: mov    QWORD PTR [rsp+0x140],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_e41:
	/* 0xe41: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e50:
	/* 0xe50: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e57:
	/* 0xe57: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_e5f:
	/* 0xe5f: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e67:
	/* 0xe67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e6c:
	/* 0xe6c: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e73:
	/* 0xe73: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e7b:
	/* 0xe7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7d:
	/* 0xe7d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e80:
	/* 0xe80: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e84:
	/* 0xe84: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e8c:
	/* 0xe8c: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e93:
	/* 0xe93: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_e96:
	/* 0xe96: je     ebb <vfs_writev_magic_return+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebb;
	}
x86_l_e98:
	/* 0xe98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e9d:
	/* 0xe9d: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ea5:
	/* 0xea5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_ea8:
	/* 0xea8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eaa:
	/* 0xeaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ead:
	/* 0xead: je     ebb <vfs_writev_magic_return+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebb;
	}
x86_l_eaf:
	/* 0xeaf: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb2:
	/* 0xeb2: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb6:
	/* 0xeb6: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eb9:
	/* 0xeb9: jmp    ebd <vfs_writev_magic_return+0xebd> */
	goto x86_l_ebd;
x86_l_ebb:
	/* 0xebb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ebd:
	/* 0xebd: mov    rdx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_ec5:
	/* 0xec5: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ecd:
	/* 0xecd: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ed5:
	/* 0xed5: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_ed8:
	/* 0xed8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_edb:
	/* 0xedb: jb     ef3 <vfs_writev_magic_return+0xef3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ef3;
	}
x86_l_edd:
	/* 0xedd: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ee1:
	/* 0xee1: je     ee8 <vfs_writev_magic_return+0xee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee8;
	}
x86_l_ee3:
	/* 0xee3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ee6:
	/* 0xee6: jbe    ef3 <vfs_writev_magic_return+0xef3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ef3;
	}
x86_l_ee8:
	/* 0xee8: and    r13,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 320ULL);
x86_l_ef0:
	/* 0xef0: or     rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_ef3:
	/* 0xef3: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ef7:
	/* 0xef7: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_eff:
	/* 0xeff: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f06:
	/* 0xf06: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f09:
	/* 0xf09: je     f52 <vfs_writev_magic_return+0xf52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f52;
	}
x86_l_f0b:
	/* 0xf0b: mov    QWORD PTR [rsp+0xa8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f13:
	/* 0xf13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f18:
	/* 0xf18: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f20:
	/* 0xf20: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f23:
	/* 0xf23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f25:
	/* 0xf25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f28:
	/* 0xf28: je     f66 <vfs_writev_magic_return+0xf66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f66;
	}
x86_l_f2a:
	/* 0xf2a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2d:
	/* 0xf2d: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f31:
	/* 0xf31: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f34:
	/* 0xf34: jmp    f68 <vfs_writev_magic_return+0xf68> */
	goto x86_l_f68;
x86_l_f36:
	/* 0xf36: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f3d:
	/* 0xf3d: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_f44:
	/* 0xf44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f47:
	/* 0xf47: jne    d9b <vfs_writev_magic_return+0xd9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d9b;
	}
x86_l_f4d:
	/* 0xf4d: jmp    dc2 <vfs_writev_magic_return+0xdc2> */
	goto x86_l_dc2;
x86_l_f52:
	/* 0xf52: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f54:
	/* 0xf54: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f57:
	/* 0xf57: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f5f:
	/* 0xf5f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: jae    f88 <vfs_writev_magic_return+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f88;
	}
x86_l_f64:
	/* 0xf64: jmp    f9e <vfs_writev_magic_return+0xf9e> */
	goto x86_l_f9e;
x86_l_f66:
	/* 0xf66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f68:
	/* 0xf68: mov    rdx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_f70:
	/* 0xf70: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f78:
	/* 0xf78: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f7b:
	/* 0xf7b: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f83:
	/* 0xf83: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: jb     f9e <vfs_writev_magic_return+0xf9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f9e;
	}
x86_l_f88:
	/* 0xf88: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f8c:
	/* 0xf8c: je     f93 <vfs_writev_magic_return+0xf93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f93;
	}
x86_l_f8e:
	/* 0xf8e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f91:
	/* 0xf91: jbe    f9e <vfs_writev_magic_return+0xf9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f9e;
	}
x86_l_f93:
	/* 0xf93: and    r13,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 320ULL);
x86_l_f9b:
	/* 0xf9b: or     rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_f9e:
	/* 0xf9e: or     rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_fa1:
	/* 0xfa1: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_fa4:
	/* 0xfa4: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_fa7:
	/* 0xfa7: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_faf:
	/* 0xfaf: je     105f <vfs_writev_magic_return+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4191ULL;
	}
x86_l_fb5:
	/* 0xfb5: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fba:
	/* 0xfba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbc:
	/* 0xfbc: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc0:
	/* 0xfc0: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_fc7:
	/* 0xfc7: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_fce:
	/* 0xfce: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_fd6:
	/* 0xfd6: mov    r13,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_fdd:
	/* 0xfdd: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_fe4:
	/* 0xfe4: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_fe9:
	/* 0xfe9: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ff1:
	/* 0xff1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff6:
	/* 0xff6: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_ffd:
	/* 0xffd: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1005:
	/* 0x1005: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1007:
	/* 0x1007: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_100b:
	/* 0x100b: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1013:
	/* 0x1013: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_101a:
	/* 0x101a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_101d:
	/* 0x101d: je     1042 <vfs_writev_magic_return+0x1042> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4162ULL;
	}
x86_l_101f:
	/* 0x101f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1024:
	/* 0x1024: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_102c:
	/* 0x102c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
	return 4145ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4150ULL: goto x86_l_1036;
	case 4153ULL: goto x86_l_1039;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4175ULL: goto x86_l_104f;
	case 4178ULL: goto x86_l_1052;
	case 4181ULL: goto x86_l_1055;
	case 4183ULL: goto x86_l_1057;
	case 4189ULL: goto x86_l_105d;
	case 4191ULL: goto x86_l_105f;
	case 4197ULL: goto x86_l_1065;
	case 4205ULL: goto x86_l_106d;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4216ULL: goto x86_l_1078;
	case 4222ULL: goto x86_l_107e;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4237ULL: goto x86_l_108d;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4246ULL: goto x86_l_1096;
	case 4254ULL: goto x86_l_109e;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4300ULL: goto x86_l_10cc;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4349ULL: goto x86_l_10fd;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4364ULL: goto x86_l_110c;
	case 4371ULL: goto x86_l_1113;
	case 4374ULL: goto x86_l_1116;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4395ULL: goto x86_l_112b;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4417ULL: goto x86_l_1141;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4439ULL: goto x86_l_1157;
	case 4443ULL: goto x86_l_115b;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4470ULL: goto x86_l_1176;
	case 4476ULL: goto x86_l_117c;
	case 4483ULL: goto x86_l_1183;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4507ULL: goto x86_l_119b;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4536ULL: goto x86_l_11b8;
	case 4538ULL: goto x86_l_11ba;
	case 4545ULL: goto x86_l_11c1;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4577ULL: goto x86_l_11e1;
	case 4585ULL: goto x86_l_11e9;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4602ULL: goto x86_l_11fa;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4616ULL: goto x86_l_1208;
	case 4620ULL: goto x86_l_120c;
	case 4627ULL: goto x86_l_1213;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4658ULL: goto x86_l_1232;
	case 4666ULL: goto x86_l_123a;
	case 4668ULL: goto x86_l_123c;
	case 4675ULL: goto x86_l_1243;
	case 4678ULL: goto x86_l_1246;
	case 4680ULL: goto x86_l_1248;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4699ULL: goto x86_l_125b;
	case 4702ULL: goto x86_l_125e;
	case 4706ULL: goto x86_l_1262;
	case 4709ULL: goto x86_l_1265;
	case 4711ULL: goto x86_l_1267;
	case 4713ULL: goto x86_l_1269;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4733ULL: goto x86_l_127d;
	case 4739ULL: goto x86_l_1283;
	case 4744ULL: goto x86_l_1288;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4771ULL: goto x86_l_12a3;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4820ULL: goto x86_l_12d4;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4859ULL: goto x86_l_12fb;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4890ULL: goto x86_l_131a;
	case 4898ULL: goto x86_l_1322;
	case 4900ULL: goto x86_l_1324;
	case 4907ULL: goto x86_l_132b;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4917ULL: goto x86_l_1335;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4925ULL: goto x86_l_133d;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4940ULL: goto x86_l_134c;
	case 4942ULL: goto x86_l_134e;
	case 4944ULL: goto x86_l_1350;
	case 4947ULL: goto x86_l_1353;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4962ULL: goto x86_l_1362;
	case 4970ULL: goto x86_l_136a;
	case 4976ULL: goto x86_l_1370;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4988ULL: goto x86_l_137c;
	case 4993ULL: goto x86_l_1381;
	case 4995ULL: goto x86_l_1383;
	case 5002ULL: goto x86_l_138a;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5033ULL: goto x86_l_13a9;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5055ULL: goto x86_l_13bf;
	case 5060ULL: goto x86_l_13c4;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5068ULL: goto x86_l_13cc;
	case 5071ULL: goto x86_l_13cf;
	case 5073ULL: goto x86_l_13d1;
	case 5076ULL: goto x86_l_13d4;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5087ULL: goto x86_l_13df;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5096ULL: goto x86_l_13e8;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5117ULL: goto x86_l_13fd;
	case 5121ULL: goto x86_l_1401;
	case 5128ULL: goto x86_l_1408;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5163ULL: goto x86_l_142b;
	case 5170ULL: goto x86_l_1432;
	case 5173ULL: goto x86_l_1435;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5205ULL: goto x86_l_1455;
	case 5208ULL: goto x86_l_1458;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5224ULL: goto x86_l_1468;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5267ULL: goto x86_l_1493;
	case 5275ULL: goto x86_l_149b;
	case 5277ULL: goto x86_l_149d;
	case 5284ULL: goto x86_l_14a4;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5301ULL: goto x86_l_14b5;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5315ULL: goto x86_l_14c3;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5341ULL: goto x86_l_14dd;
	case 5344ULL: goto x86_l_14e0;
	case 5350ULL: goto x86_l_14e6;
	case 5357ULL: goto x86_l_14ed;
	case 5360ULL: goto x86_l_14f0;
	case 5369ULL: goto x86_l_14f9;
	case 5374ULL: goto x86_l_14fe;
	case 5381ULL: goto x86_l_1505;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5398ULL: goto x86_l_1516;
	case 5401ULL: goto x86_l_1519;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5415ULL: goto x86_l_1527;
	case 5420ULL: goto x86_l_152c;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
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
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5514ULL: goto x86_l_158a;
	case 5521ULL: goto x86_l_1591;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5538ULL: goto x86_l_15a2;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5556ULL: goto x86_l_15b4;
	case 5558ULL: goto x86_l_15b6;
	case 5564ULL: goto x86_l_15bc;
	case 5576ULL: goto x86_l_15c8;
	case 5588ULL: goto x86_l_15d4;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5661ULL: goto x86_l_161d;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5685ULL: goto x86_l_1635;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5762ULL: goto x86_l_1682;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5807ULL: goto x86_l_16af;
	case 5815ULL: goto x86_l_16b7;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5837ULL: goto x86_l_16cd;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1031:
	/* 0x1031: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1034:
	/* 0x1034: je     1042 <vfs_writev_magic_return+0x1042> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1042;
	}
x86_l_1036:
	/* 0x1036: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1039:
	/* 0x1039: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103d:
	/* 0x103d: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1040:
	/* 0x1040: jmp    1044 <vfs_writev_magic_return+0x1044> */
	goto x86_l_1044;
x86_l_1042:
	/* 0x1042: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1044:
	/* 0x1044: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1047:
	/* 0x1047: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_104f:
	/* 0x104f: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1052:
	/* 0x1052: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1055:
	/* 0x1055: jae    1074 <vfs_writev_magic_return+0x1074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1074;
	}
x86_l_1057:
	/* 0x1057: movzx  r13d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_105d:
	/* 0x105d: jmp    1090 <vfs_writev_magic_return+0x1090> */
	goto x86_l_1090;
x86_l_105f:
	/* 0x105f: movzx  r13d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1065:
	/* 0x1065: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_106d:
	/* 0x106d: jne    10a4 <vfs_writev_magic_return+0x10a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10a4;
	}
x86_l_106f:
	/* 0x106f: jmp    116e <vfs_writev_magic_return+0x116e> */
	goto x86_l_116e;
x86_l_1074:
	/* 0x1074: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1078:
	/* 0x1078: movzx  r13d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_107e:
	/* 0x107e: je     1085 <vfs_writev_magic_return+0x1085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1085;
	}
x86_l_1080:
	/* 0x1080: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1083:
	/* 0x1083: jbe    1090 <vfs_writev_magic_return+0x1090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1090;
	}
x86_l_1085:
	/* 0x1085: and    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_108d:
	/* 0x108d: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1090:
	/* 0x1090: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1093:
	/* 0x1093: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1096:
	/* 0x1096: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_109e:
	/* 0x109e: je     116e <vfs_writev_magic_return+0x116e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116e;
	}
x86_l_10a4:
	/* 0x10a4: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_10a9:
	/* 0x10a9: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_10b0:
	/* 0x10b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b5:
	/* 0x10b5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10bd:
	/* 0x10bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10cc:
	/* 0x10cc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10d0:
	/* 0x10d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d5:
	/* 0x10d5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10dd:
	/* 0x10dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10e2:
	/* 0x10e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e4:
	/* 0x10e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10e9:
	/* 0x10e9: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10f1:
	/* 0x10f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10f6:
	/* 0x10f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10fb:
	/* 0x10fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fd:
	/* 0x10fd: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1101:
	/* 0x1101: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1105:
	/* 0x1105: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_110c:
	/* 0x110c: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1113:
	/* 0x1113: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1116:
	/* 0x1116: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_111f:
	/* 0x111f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1124:
	/* 0x1124: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_112b:
	/* 0x112b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1133:
	/* 0x1133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1135:
	/* 0x1135: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_113c:
	/* 0x113c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_113f:
	/* 0x113f: je     1160 <vfs_writev_magic_return+0x1160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1160;
	}
x86_l_1141:
	/* 0x1141: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1145:
	/* 0x1145: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_114a:
	/* 0x114a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_114d:
	/* 0x114d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_114f:
	/* 0x114f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1152:
	/* 0x1152: je     1160 <vfs_writev_magic_return+0x1160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1160;
	}
x86_l_1154:
	/* 0x1154: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1157:
	/* 0x1157: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_115b:
	/* 0x115b: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_115e:
	/* 0x115e: jmp    1162 <vfs_writev_magic_return+0x1162> */
	goto x86_l_1162;
x86_l_1160:
	/* 0x1160: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1162:
	/* 0x1162: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1165:
	/* 0x1165: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1168:
	/* 0x1168: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_116b:
	/* 0x116b: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_116e:
	/* 0x116e: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1176:
	/* 0x1176: je     1275 <vfs_writev_magic_return+0x1275> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1275;
	}
x86_l_117c:
	/* 0x117c: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1183:
	/* 0x1183: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1187:
	/* 0x1187: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_118c:
	/* 0x118c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1194:
	/* 0x1194: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1199:
	/* 0x1199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119b:
	/* 0x119b: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11a3:
	/* 0x11a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11a8:
	/* 0x11a8: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11b0:
	/* 0x11b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11b5:
	/* 0x11b5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11b8:
	/* 0x11b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ba:
	/* 0x11ba: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11c1:
	/* 0x11c1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_11c5:
	/* 0x11c5: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_11c9:
	/* 0x11c9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11cd:
	/* 0x11cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11d2:
	/* 0x11d2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11da:
	/* 0x11da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11df:
	/* 0x11df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e1:
	/* 0x11e1: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11e9:
	/* 0x11e9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_11ed:
	/* 0x11ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11f2:
	/* 0x11f2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11fa:
	/* 0x11fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11ff:
	/* 0x11ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1201:
	/* 0x1201: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1208:
	/* 0x1208: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_120c:
	/* 0x120c: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1213:
	/* 0x1213: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_121a:
	/* 0x121a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_121d:
	/* 0x121d: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1226:
	/* 0x1226: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122b:
	/* 0x122b: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1232:
	/* 0x1232: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_123a:
	/* 0x123a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123c:
	/* 0x123c: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1243:
	/* 0x1243: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1246:
	/* 0x1246: je     1267 <vfs_writev_magic_return+0x1267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1267;
	}
x86_l_1248:
	/* 0x1248: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_124c:
	/* 0x124c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1251:
	/* 0x1251: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1256:
	/* 0x1256: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1259:
	/* 0x1259: je     1267 <vfs_writev_magic_return+0x1267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1267;
	}
x86_l_125b:
	/* 0x125b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125e:
	/* 0x125e: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1262:
	/* 0x1262: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1265:
	/* 0x1265: jmp    1269 <vfs_writev_magic_return+0x1269> */
	goto x86_l_1269;
x86_l_1267:
	/* 0x1267: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1269:
	/* 0x1269: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_126c:
	/* 0x126c: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_126f:
	/* 0x126f: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1272:
	/* 0x1272: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1275:
	/* 0x1275: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_127d:
	/* 0x127d: je     1362 <vfs_writev_magic_return+0x1362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1362;
	}
x86_l_1283:
	/* 0x1283: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1288:
	/* 0x1288: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_128f:
	/* 0x128f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1294:
	/* 0x1294: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_129c:
	/* 0x129c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a1:
	/* 0x12a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a3:
	/* 0x12a3: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12ab:
	/* 0x12ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12b0:
	/* 0x12b0: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12b8:
	/* 0x12b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12bd:
	/* 0x12bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12bf:
	/* 0x12bf: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12c7:
	/* 0x12c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12cc:
	/* 0x12cc: lea    r12,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12d4:
	/* 0x12d4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12d7:
	/* 0x12d7: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_12dc:
	/* 0x12dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12de:
	/* 0x12de: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_12e2:
	/* 0x12e2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_12e7:
	/* 0x12e7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_12ea:
	/* 0x12ea: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12ef:
	/* 0x12ef: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12f2:
	/* 0x12f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f4:
	/* 0x12f4: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_12fb:
	/* 0x12fb: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1302:
	/* 0x1302: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1305:
	/* 0x1305: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_130e:
	/* 0x130e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1313:
	/* 0x1313: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_131a:
	/* 0x131a: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1322:
	/* 0x1322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1324:
	/* 0x1324: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_132b:
	/* 0x132b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_132e:
	/* 0x132e: je     134e <vfs_writev_magic_return+0x134e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_134e;
	}
x86_l_1330:
	/* 0x1330: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1335:
	/* 0x1335: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_133b:
	/* 0x133b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_133d:
	/* 0x133d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1340:
	/* 0x1340: je     134e <vfs_writev_magic_return+0x134e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_134e;
	}
x86_l_1342:
	/* 0x1342: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1345:
	/* 0x1345: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1349:
	/* 0x1349: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_134c:
	/* 0x134c: jmp    1350 <vfs_writev_magic_return+0x1350> */
	goto x86_l_1350;
x86_l_134e:
	/* 0x134e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1350:
	/* 0x1350: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1353:
	/* 0x1353: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1356:
	/* 0x1356: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1359:
	/* 0x1359: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_135c:
	/* 0x135c: movzx  r13d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1362:
	/* 0x1362: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_136a:
	/* 0x136a: je     13f1 <vfs_writev_magic_return+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f1;
	}
x86_l_1370:
	/* 0x1370: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1374:
	/* 0x1374: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1379:
	/* 0x1379: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_137c:
	/* 0x137c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1381:
	/* 0x1381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1383:
	/* 0x1383: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_138a:
	/* 0x138a: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1391:
	/* 0x1391: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1394:
	/* 0x1394: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_139d:
	/* 0x139d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a2:
	/* 0x13a2: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_13a9:
	/* 0x13a9: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13b1:
	/* 0x13b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b3:
	/* 0x13b3: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13ba:
	/* 0x13ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13bd:
	/* 0x13bd: je     13dd <vfs_writev_magic_return+0x13dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13dd;
	}
x86_l_13bf:
	/* 0x13bf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13c4:
	/* 0x13c4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13c7:
	/* 0x13c7: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_13ca:
	/* 0x13ca: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13cc:
	/* 0x13cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13cf:
	/* 0x13cf: je     13dd <vfs_writev_magic_return+0x13dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13dd;
	}
x86_l_13d1:
	/* 0x13d1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d4:
	/* 0x13d4: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d8:
	/* 0x13d8: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13db:
	/* 0x13db: jmp    13df <vfs_writev_magic_return+0x13df> */
	goto x86_l_13df;
x86_l_13dd:
	/* 0x13dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13df:
	/* 0x13df: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13e2:
	/* 0x13e2: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13e5:
	/* 0x13e5: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13e8:
	/* 0x13e8: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13eb:
	/* 0x13eb: movzx  r13d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_13f1:
	/* 0x13f1: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_13f8:
	/* 0x13f8: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: je     1468 <vfs_writev_magic_return+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1468;
	}
x86_l_13fd:
	/* 0x13fd: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1401:
	/* 0x1401: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1408:
	/* 0x1408: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_140f:
	/* 0x140f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1412:
	/* 0x1412: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1418:
	/* 0x1418: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141d:
	/* 0x141d: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1424:
	/* 0x1424: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1429:
	/* 0x1429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142b:
	/* 0x142b: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1432:
	/* 0x1432: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1435:
	/* 0x1435: je     145a <vfs_writev_magic_return+0x145a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145a;
	}
x86_l_1437:
	/* 0x1437: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_143c:
	/* 0x143c: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1444:
	/* 0x1444: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1447:
	/* 0x1447: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1449:
	/* 0x1449: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_144c:
	/* 0x144c: je     145a <vfs_writev_magic_return+0x145a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145a;
	}
x86_l_144e:
	/* 0x144e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1451:
	/* 0x1451: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1455:
	/* 0x1455: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1458:
	/* 0x1458: jmp    145c <vfs_writev_magic_return+0x145c> */
	goto x86_l_145c;
x86_l_145a:
	/* 0x145a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145c:
	/* 0x145c: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_145f:
	/* 0x145f: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1462:
	/* 0x1462: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1465:
	/* 0x1465: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1468:
	/* 0x1468: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_146f:
	/* 0x146f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: je     14d6 <vfs_writev_magic_return+0x14d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d6;
	}
x86_l_1474:
	/* 0x1474: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_147b:
	/* 0x147b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_147e:
	/* 0x147e: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1487:
	/* 0x1487: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_148c:
	/* 0x148c: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1493:
	/* 0x1493: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_149b:
	/* 0x149b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149d:
	/* 0x149d: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14a4:
	/* 0x14a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a7:
	/* 0x14a7: je     14c8 <vfs_writev_magic_return+0x14c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14c8;
	}
x86_l_14a9:
	/* 0x14a9: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14ad:
	/* 0x14ad: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14b2:
	/* 0x14b2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14b5:
	/* 0x14b5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14b7:
	/* 0x14b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ba:
	/* 0x14ba: je     14c8 <vfs_writev_magic_return+0x14c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14c8;
	}
x86_l_14bc:
	/* 0x14bc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14bf:
	/* 0x14bf: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c3:
	/* 0x14c3: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14c6:
	/* 0x14c6: jmp    14ca <vfs_writev_magic_return+0x14ca> */
	goto x86_l_14ca;
x86_l_14c8:
	/* 0x14c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ca:
	/* 0x14ca: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14cd:
	/* 0x14cd: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_14d0:
	/* 0x14d0: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d3:
	/* 0x14d3: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_14d6:
	/* 0x14d6: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_14dd:
	/* 0x14dd: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_14e0:
	/* 0x14e0: je     1568 <vfs_writev_magic_return+0x1568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1568;
	}
x86_l_14e6:
	/* 0x14e6: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_14ed:
	/* 0x14ed: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14f0:
	/* 0x14f0: mov    WORD PTR [rsp+0xb0],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14f9:
	/* 0x14f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14fe:
	/* 0x14fe: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1505:
	/* 0x1505: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_150d:
	/* 0x150d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150f:
	/* 0x150f: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1516:
	/* 0x1516: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1519:
	/* 0x1519: je     155a <vfs_writev_magic_return+0x155a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155a;
	}
x86_l_151b:
	/* 0x151b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1523:
	/* 0x1523: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1527:
	/* 0x1527: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_152c:
	/* 0x152c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_152f:
	/* 0x152f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1531:
	/* 0x1531: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1534:
	/* 0x1534: jne    154e <vfs_writev_magic_return+0x154e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_154e;
	}
x86_l_1536:
	/* 0x1536: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_153b:
	/* 0x153b: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_153f:
	/* 0x153f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1544:
	/* 0x1544: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1547:
	/* 0x1547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1549:
	/* 0x1549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154c:
	/* 0x154c: je     155a <vfs_writev_magic_return+0x155a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155a;
	}
x86_l_154e:
	/* 0x154e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1551:
	/* 0x1551: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1555:
	/* 0x1555: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1558:
	/* 0x1558: jmp    155c <vfs_writev_magic_return+0x155c> */
	goto x86_l_155c;
x86_l_155a:
	/* 0x155a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155c:
	/* 0x155c: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_155f:
	/* 0x155f: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1562:
	/* 0x1562: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1565:
	/* 0x1565: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1568:
	/* 0x1568: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_156f:
	/* 0x156f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1572:
	/* 0x1572: mov    r12,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_157a:
	/* 0x157a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157f:
	/* 0x157f: je     1588 <vfs_writev_magic_return+0x1588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1588;
	}
x86_l_1581:
	/* 0x1581: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1585:
	/* 0x1585: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1588:
	/* 0x1588: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158a:
	/* 0x158a: and    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1591:
	/* 0x1591: mov    rdx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1598:
	/* 0x1598: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_159b:
	/* 0x159b: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15a2:
	/* 0x15a2: je     2a0b <vfs_writev_magic_return+0x2a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10763ULL;
	}
x86_l_15a8:
	/* 0x15a8: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15ad:
	/* 0x15ad: mov    DWORD PTR [rsp+0x10c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_15b4:
	/* 0x15b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15b6:
	/* 0x15b6: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_15bc:
	/* 0x15bc: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_15c8:
	/* 0x15c8: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_15d4:
	/* 0x15d4: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_15e0:
	/* 0x15e0: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15e5:
	/* 0x15e5: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_15e8:
	/* 0x15e8: je     1759 <vfs_writev_magic_return+0x1759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5977ULL;
	}
x86_l_15ee:
	/* 0x15ee: lea    rbx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15f2:
	/* 0x15f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15f7:
	/* 0x15f7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15fc:
	/* 0x15fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1601:
	/* 0x1601: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1604:
	/* 0x1604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1606:
	/* 0x1606: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_160f:
	/* 0x160f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1614:
	/* 0x1614: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_161d:
	/* 0x161d: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1621:
	/* 0x1621: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1626:
	/* 0x1626: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_162e:
	/* 0x162e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1633:
	/* 0x1633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1635:
	/* 0x1635: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_163d:
	/* 0x163d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1642:
	/* 0x1642: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1646:
	/* 0x1646: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_164b:
	/* 0x164b: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1653:
	/* 0x1653: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1658:
	/* 0x1658: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_165b:
	/* 0x165b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165d:
	/* 0x165d: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1664:
	/* 0x1664: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1669:
	/* 0x1669: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_166e:
	/* 0x166e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1676:
	/* 0x1676: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167b:
	/* 0x167b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1680:
	/* 0x1680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1682:
	/* 0x1682: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_168a:
	/* 0x168a: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_168d:
	/* 0x168d: js     16b9 <vfs_writev_magic_return+0x16b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16b9;
	}
x86_l_168f:
	/* 0x168f: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1694:
	/* 0x1694: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1699:
	/* 0x1699: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16a1:
	/* 0x16a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a6:
	/* 0x16a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a8:
	/* 0x16a8: imul   rax,r15,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_R15, X86_WIDTH_64, 1000000000ULL);
x86_l_16af:
	/* 0x16af: add    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_16b7:
	/* 0x16b7: jmp    16bb <vfs_writev_magic_return+0x16bb> */
	goto x86_l_16bb;
x86_l_16b9:
	/* 0x16b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16bb:
	/* 0x16bb: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_16c3:
	/* 0x16c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16c8:
	/* 0x16c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16cd:
	/* 0x16cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d2:
	/* 0x16d2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d7:
	/* 0x16d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16dc:
	/* 0x16dc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e1:
	/* 0x16e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	return 5861ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5861ULL: goto x86_l_16e5;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5905ULL: goto x86_l_1711;
	case 5912ULL: goto x86_l_1718;
	case 5917ULL: goto x86_l_171d;
	case 5925ULL: goto x86_l_1725;
	case 5930ULL: goto x86_l_172a;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5977ULL: goto x86_l_1759;
	case 5982ULL: goto x86_l_175e;
	case 5989ULL: goto x86_l_1765;
	case 5997ULL: goto x86_l_176d;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6047ULL: goto x86_l_179f;
	case 6050ULL: goto x86_l_17a2;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6120ULL: goto x86_l_17e8;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6192ULL: goto x86_l_1830;
	case 6197ULL: goto x86_l_1835;
	case 6200ULL: goto x86_l_1838;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6215ULL: goto x86_l_1847;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6253ULL: goto x86_l_186d;
	case 6258ULL: goto x86_l_1872;
	case 6261ULL: goto x86_l_1875;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6288ULL: goto x86_l_1890;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6305ULL: goto x86_l_18a1;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6315ULL: goto x86_l_18ab;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6345ULL: goto x86_l_18c9;
	case 6350ULL: goto x86_l_18ce;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6417ULL: goto x86_l_1911;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6434ULL: goto x86_l_1922;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6491ULL: goto x86_l_195b;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6530ULL: goto x86_l_1982;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6545ULL: goto x86_l_1991;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6566ULL: goto x86_l_19a6;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6626ULL: goto x86_l_19e2;
	case 6631ULL: goto x86_l_19e7;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6681ULL: goto x86_l_1a19;
	case 6687ULL: goto x86_l_1a1f;
	case 6693ULL: goto x86_l_1a25;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6719ULL: goto x86_l_1a3f;
	case 6721ULL: goto x86_l_1a41;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6746ULL: goto x86_l_1a5a;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6818ULL: goto x86_l_1aa2;
	case 6826ULL: goto x86_l_1aaa;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6851ULL: goto x86_l_1ac3;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6870ULL: goto x86_l_1ad6;
	case 6874ULL: goto x86_l_1ada;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6960ULL: goto x86_l_1b30;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6996ULL: goto x86_l_1b54;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7021ULL: goto x86_l_1b6d;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7052ULL: goto x86_l_1b8c;
	case 7054ULL: goto x86_l_1b8e;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7067ULL: goto x86_l_1b9b;
	case 7069ULL: goto x86_l_1b9d;
	case 7075ULL: goto x86_l_1ba3;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7098ULL: goto x86_l_1bba;
	case 7106ULL: goto x86_l_1bc2;
	case 7112ULL: goto x86_l_1bc8;
	case 7118ULL: goto x86_l_1bce;
	case 7121ULL: goto x86_l_1bd1;
	case 7129ULL: goto x86_l_1bd9;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7167ULL: goto x86_l_1bff;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7207ULL: goto x86_l_1c27;
	case 7211ULL: goto x86_l_1c2b;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7239ULL: goto x86_l_1c47;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	case 7254ULL: goto x86_l_1c56;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7283ULL: goto x86_l_1c73;
	case 7291ULL: goto x86_l_1c7b;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7309ULL: goto x86_l_1c8d;
	case 7321ULL: goto x86_l_1c99;
	case 7333ULL: goto x86_l_1ca5;
	case 7345ULL: goto x86_l_1cb1;
	case 7357ULL: goto x86_l_1cbd;
	case 7365ULL: goto x86_l_1cc5;
	case 7371ULL: goto x86_l_1ccb;
	case 7377ULL: goto x86_l_1cd1;
	case 7385ULL: goto x86_l_1cd9;
	case 7394ULL: goto x86_l_1ce2;
	case 7402ULL: goto x86_l_1cea;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7417ULL: goto x86_l_1cf9;
	case 7422ULL: goto x86_l_1cfe;
	case 7430ULL: goto x86_l_1d06;
	case 7434ULL: goto x86_l_1d0a;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7452ULL: goto x86_l_1d1c;
	case 7460ULL: goto x86_l_1d24;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7477ULL: goto x86_l_1d35;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7496ULL: goto x86_l_1d48;
	case 7503ULL: goto x86_l_1d4f;
	case 7512ULL: goto x86_l_1d58;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7591ULL: goto x86_l_1da7;
	case 7595ULL: goto x86_l_1dab;
	case 7603ULL: goto x86_l_1db3;
	case 7610ULL: goto x86_l_1dba;
	case 7612ULL: goto x86_l_1dbc;
	case 7621ULL: goto x86_l_1dc5;
	case 7625ULL: goto x86_l_1dc9;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7662ULL: goto x86_l_1dee;
	case 7664ULL: goto x86_l_1df0;
	case 7672ULL: goto x86_l_1df8;
	case 7676ULL: goto x86_l_1dfc;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7692ULL: goto x86_l_1e0c;
	case 7700ULL: goto x86_l_1e14;
	case 7702ULL: goto x86_l_1e16;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16e5:
	/* 0x16e5: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16ed:
	/* 0x16ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f2:
	/* 0x16f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f4:
	/* 0x16f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16f9:
	/* 0x16f9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1701:
	/* 0x1701: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1706:
	/* 0x1706: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_170b:
	/* 0x170b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170d:
	/* 0x170d: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1711:
	/* 0x1711: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1718:
	/* 0x1718: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_171d:
	/* 0x171d: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1725:
	/* 0x1725: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_172a:
	/* 0x172a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_172d:
	/* 0x172d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172f:
	/* 0x172f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1734:
	/* 0x1734: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_173c:
	/* 0x173c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1740:
	/* 0x1740: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1745:
	/* 0x1745: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_174a:
	/* 0x174a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174c:
	/* 0x174c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1751:
	/* 0x1751: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1759:
	/* 0x1759: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_175e:
	/* 0x175e: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1765:
	/* 0x1765: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_176d:
	/* 0x176d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176f:
	/* 0x176f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1772:
	/* 0x1772: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1775:
	/* 0x1775: jne    1bd1 <vfs_writev_magic_return+0x1bd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bd1;
	}
x86_l_177b:
	/* 0x177b: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1783:
	/* 0x1783: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1788:
	/* 0x1788: mov    rdi,QWORD PTR [rip+0x3213] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_178f:
	/* 0x178f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1794:
	/* 0x1794: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1796:
	/* 0x1796: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1799:
	/* 0x1799: je     1bce <vfs_writev_magic_return+0x1bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bce;
	}
x86_l_179f:
	/* 0x179f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_17a2:
	/* 0x17a2: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a6:
	/* 0x17a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17ab:
	/* 0x17ab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17b0:
	/* 0x17b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b5:
	/* 0x17b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b7:
	/* 0x17b7: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17bc:
	/* 0x17bc: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17c4:
	/* 0x17c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17c9:
	/* 0x17c9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17d1:
	/* 0x17d1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17d6:
	/* 0x17d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17db:
	/* 0x17db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17dd:
	/* 0x17dd: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_17e2:
	/* 0x17e2: jne    18e7 <vfs_writev_magic_return+0x18e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18e7;
	}
x86_l_17e8:
	/* 0x17e8: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ec:
	/* 0x17ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17f1:
	/* 0x17f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17f6:
	/* 0x17f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17fb:
	/* 0x17fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fd:
	/* 0x17fd: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1802:
	/* 0x1802: lea    rax,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_1806:
	/* 0x1806: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180b:
	/* 0x180b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1810:
	/* 0x1810: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1815:
	/* 0x1815: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_181a:
	/* 0x181a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_181f:
	/* 0x181f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1821:
	/* 0x1821: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1826:
	/* 0x1826: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_182b:
	/* 0x182b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1830:
	/* 0x1830: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1835:
	/* 0x1835: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1838:
	/* 0x1838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183a:
	/* 0x183a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_183f:
	/* 0x183f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1847:
	/* 0x1847: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_184b:
	/* 0x184b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1850:
	/* 0x1850: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1855:
	/* 0x1855: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_185a:
	/* 0x185a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185c:
	/* 0x185c: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1864:
	/* 0x1864: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1867:
	/* 0x1867: je     18f8 <vfs_writev_magic_return+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_186d:
	/* 0x186d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1872:
	/* 0x1872: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1875:
	/* 0x1875: je     18f8 <vfs_writev_magic_return+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_187b:
	/* 0x187b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_187f:
	/* 0x187f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1884:
	/* 0x1884: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1889:
	/* 0x1889: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_188e:
	/* 0x188e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1890:
	/* 0x1890: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1894:
	/* 0x1894: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1899:
	/* 0x1899: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_189b:
	/* 0x189b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18a1:
	/* 0x18a1: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_18a3:
	/* 0x18a3: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_18a5:
	/* 0x18a5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_18ab:
	/* 0x18ab: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18ae:
	/* 0x18ae: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_18b3:
	/* 0x18b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b5:
	/* 0x18b5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18b8:
	/* 0x18b8: jl     1a5a <vfs_writev_magic_return+0x1a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1a5a;
	}
x86_l_18be:
	/* 0x18be: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_18c1:
	/* 0x18c1: mov    BYTE PTR [r13+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_18c9:
	/* 0x18c9: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_18ce:
	/* 0x18ce: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_18d0:
	/* 0x18d0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d5:
	/* 0x18d5: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18dd:
	/* 0x18dd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18e2:
	/* 0x18e2: jmp    1970 <vfs_writev_magic_return+0x1970> */
	goto x86_l_1970;
x86_l_18e7:
	/* 0x18e7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_18ec:
	/* 0x18ec: lea    rdx,[rip+0x320f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 12815ULL);
x86_l_18f3:
	/* 0x18f3: jmp    1a81 <vfs_writev_magic_return+0x1a81> */
	goto x86_l_1a81;
x86_l_18f8:
	/* 0x18f8: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_18fb:
	/* 0x18fb: jne    1a5a <vfs_writev_magic_return+0x1a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a5a;
	}
x86_l_1901:
	/* 0x1901: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1906:
	/* 0x1906: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_190b:
	/* 0x190b: je     1a5a <vfs_writev_magic_return+0x1a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5a;
	}
x86_l_1911:
	/* 0x1911: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1914:
	/* 0x1914: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1919:
	/* 0x1919: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_191e:
	/* 0x191e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1922:
	/* 0x1922: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_192a:
	/* 0x192a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_192f:
	/* 0x192f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1931:
	/* 0x1931: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1936:
	/* 0x1936: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_193b:
	/* 0x193b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1940:
	/* 0x1940: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1945:
	/* 0x1945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1947:
	/* 0x1947: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_194c:
	/* 0x194c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1951:
	/* 0x1951: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1956:
	/* 0x1956: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195b:
	/* 0x195b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195d:
	/* 0x195d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1962:
	/* 0x1962: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1966:
	/* 0x1966: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_196b:
	/* 0x196b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1970:
	/* 0x1970: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1975:
	/* 0x1975: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_197a:
	/* 0x197a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197f:
	/* 0x197f: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1982:
	/* 0x1982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1984:
	/* 0x1984: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1989:
	/* 0x1989: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1991:
	/* 0x1991: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1995:
	/* 0x1995: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_199a:
	/* 0x199a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_199f:
	/* 0x199f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a4:
	/* 0x19a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a6:
	/* 0x19a6: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19ae:
	/* 0x19ae: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19b1:
	/* 0x19b1: je     1a3c <vfs_writev_magic_return+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3c;
	}
x86_l_19b7:
	/* 0x19b7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19bc:
	/* 0x19bc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19bf:
	/* 0x19bf: je     1a3c <vfs_writev_magic_return+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3c;
	}
x86_l_19c1:
	/* 0x19c1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19ca:
	/* 0x19ca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19cf:
	/* 0x19cf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19da:
	/* 0x19da: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_19dc:
	/* 0x19dc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e2:
	/* 0x19e2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e7:
	/* 0x19e7: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_19e9:
	/* 0x19e9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19eb:
	/* 0x19eb: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_19ee:
	/* 0x19ee: jb     1ba6 <vfs_writev_magic_return+0x1ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_19f4:
	/* 0x19f4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19f9:
	/* 0x19f9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19ff:
	/* 0x19ff: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a02:
	/* 0x1a02: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a07:
	/* 0x1a07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a09:
	/* 0x1a09: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a0c:
	/* 0x1a0c: jl     1a44 <vfs_writev_magic_return+0x1a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1a44;
	}
x86_l_1a0e:
	/* 0x1a0e: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1a11:
	/* 0x1a11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a16:
	/* 0x1a16: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a19:
	/* 0x1a19: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1a25:
	/* 0x1a25: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a27:
	/* 0x1a27: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a34:
	/* 0x1a34: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a37:
	/* 0x1a37: jmp    1b1e <vfs_writev_magic_return+0x1b1e> */
	goto x86_l_1b1e;
x86_l_1a3c:
	/* 0x1a3c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a3f:
	/* 0x1a3f: je     1ab6 <vfs_writev_magic_return+0x1ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ab6;
	}
x86_l_1a41:
	/* 0x1a41: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1a44:
	/* 0x1a44: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a49:
	/* 0x1a49: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a4e:
	/* 0x1a4e: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_1a54:
	/* 0x1a54: jne    1bab <vfs_writev_magic_return+0x1bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bab;
	}
x86_l_1a5a:
	/* 0x1a5a: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a62:
	/* 0x1a62: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a66:
	/* 0x1a66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a6b:
	/* 0x1a6b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a70:
	/* 0x1a70: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a75:
	/* 0x1a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a77:
	/* 0x1a77: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a81:
	/* 0x1a81: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a84:
	/* 0x1a84: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8d:
	/* 0x1a8d: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1a93:
	/* 0x1a93: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a96:
	/* 0x1a96: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    rdi,QWORD PTR [rip+0x320f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&io_file_path_cache_map)));
x86_l_1aa2:
	/* 0x1aa2: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1aad:
	/* 0x1aad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aaf:
	/* 0x1aaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab1:
	/* 0x1ab1: jmp    1bd1 <vfs_writev_magic_return+0x1bd1> */
	goto x86_l_1bd1;
x86_l_1ab6:
	/* 0x1ab6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1abb:
	/* 0x1abb: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1ac3:
	/* 0x1ac3: je     1a44 <vfs_writev_magic_return+0x1a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a44;
	}
x86_l_1ac9:
	/* 0x1ac9: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1acc:
	/* 0x1acc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad1:
	/* 0x1ad1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad6:
	/* 0x1ad6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ada:
	/* 0x1ada: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae7:
	/* 0x1ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae9:
	/* 0x1ae9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aee:
	/* 0x1aee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af3:
	/* 0x1af3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af8:
	/* 0x1af8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1afd:
	/* 0x1afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aff:
	/* 0x1aff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b04:
	/* 0x1b04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b09:
	/* 0x1b09: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b13:
	/* 0x1b13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b15:
	/* 0x1b15: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1a:
	/* 0x1b1a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b23:
	/* 0x1b23: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b28:
	/* 0x1b28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1b30:
	/* 0x1b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b32:
	/* 0x1b32: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b37:
	/* 0x1b37: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b3f:
	/* 0x1b3f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b43:
	/* 0x1b43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b48:
	/* 0x1b48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b52:
	/* 0x1b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b54:
	/* 0x1b54: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b5c:
	/* 0x1b5c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b5f:
	/* 0x1b5f: je     2791 <vfs_writev_magic_return+0x2791> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10129ULL;
	}
x86_l_1b65:
	/* 0x1b65: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6a:
	/* 0x1b6a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b6d:
	/* 0x1b6d: je     2791 <vfs_writev_magic_return+0x2791> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10129ULL;
	}
x86_l_1b73:
	/* 0x1b73: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b77:
	/* 0x1b77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b7c:
	/* 0x1b7c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b81:
	/* 0x1b81: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b86:
	/* 0x1b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b88:
	/* 0x1b88: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b8c:
	/* 0x1b8c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b8e:
	/* 0x1b8e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b94:
	/* 0x1b94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b99:
	/* 0x1b99: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1b9b:
	/* 0x1b9b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b9d:
	/* 0x1b9d: jae    28c3 <vfs_writev_magic_return+0x28c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10435ULL;
	}
x86_l_1ba3:
	/* 0x1ba3: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1ba6:
	/* 0x1ba6: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bab:
	/* 0x1bab: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1bad:
	/* 0x1bad: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1baf:
	/* 0x1baf: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    BYTE PTR [r13+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1bba:
	/* 0x1bba: mov    BYTE PTR [r13+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1bc2:
	/* 0x1bc2: cmp    edx,0x6fff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28671ULL);
x86_l_1bc8:
	/* 0x1bc8: jbe    1a8d <vfs_writev_magic_return+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a8d;
	}
x86_l_1bce:
	/* 0x1bce: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd1:
	/* 0x1bd1: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bd9:
	/* 0x1bd9: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be2:
	/* 0x1be2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be7:
	/* 0x1be7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bec:
	/* 0x1bec: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1bef:
	/* 0x1bef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf1:
	/* 0x1bf1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bfb:
	/* 0x1bfb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1bff:
	/* 0x1bff: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c07:
	/* 0x1c07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c0c:
	/* 0x1c0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0e:
	/* 0x1c0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c13:
	/* 0x1c13: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c1b:
	/* 0x1c1b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c20:
	/* 0x1c20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c25:
	/* 0x1c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c27:
	/* 0x1c27: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    DWORD PTR [rsp+0xf0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1c32:
	/* 0x1c32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c37:
	/* 0x1c37: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c44:
	/* 0x1c44: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1c47:
	/* 0x1c47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c49:
	/* 0x1c49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c56:
	/* 0x1c56: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c5a:
	/* 0x1c5a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c64:
	/* 0x1c64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c66:
	/* 0x1c66: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1c73:
	/* 0x1c73: mov    r15d,DWORD PTR [rsp+0x10c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1c7b:
	/* 0x1c7b: cmp    r15d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    ebx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32ULL);
x86_l_1c84:
	/* 0x1c84: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1c89:
	/* 0x1c89: cmovb  ebp,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R15, X86_WIDTH_32, X86_CC_B);
x86_l_1c8d:
	/* 0x1c8d: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1c99:
	/* 0x1c99: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1ca5:
	/* 0x1ca5: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1cb1:
	/* 0x1cb1: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1cbd:
	/* 0x1cbd: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cc5:
	/* 0x1cc5: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1ccb:
	/* 0x1ccb: ja     1d4f <vfs_writev_magic_return+0x1d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4f;
	}
x86_l_1cd1:
	/* 0x1cd1: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1ce2:
	/* 0x1ce2: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cea:
	/* 0x1cea: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1cf2:
	/* 0x1cf2: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1cf7:
	/* 0x1cf7: ja     1d4f <vfs_writev_magic_return+0x1d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4f;
	}
x86_l_1cf9:
	/* 0x1cf9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1cfe:
	/* 0x1cfe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d06:
	/* 0x1d06: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d0a:
	/* 0x1d0a: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1d11:
	/* 0x1d11: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d16:
	/* 0x1d16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d18:
	/* 0x1d18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d1a:
	/* 0x1d1a: jle    1d4f <vfs_writev_magic_return+0x1d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1d4f;
	}
x86_l_1d1c:
	/* 0x1d1c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d24:
	/* 0x1d24: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1d2b:
	/* 0x1d2b: ja     1d4f <vfs_writev_magic_return+0x1d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4f;
	}
x86_l_1d2d:
	/* 0x1d2d: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1d35:
	/* 0x1d35: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d3d:
	/* 0x1d3d: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1d40:
	/* 0x1d40: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d48:
	/* 0x1d48: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1d58:
	/* 0x1d58: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1d61:
	/* 0x1d61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d66:
	/* 0x1d66: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d70:
	/* 0x1d70: mov    rdx,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1d78:
	/* 0x1d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7a:
	/* 0x1d7a: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1d82:
	/* 0x1d82: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1d85:
	/* 0x1d85: cmovb  ebx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1d88:
	/* 0x1d88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d92:
	/* 0x1d92: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_1d9c:
	/* 0x1d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9e:
	/* 0x1d9e: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1da1:
	/* 0x1da1: je     1e32 <vfs_writev_magic_return+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7730ULL;
	}
x86_l_1da7:
	/* 0x1da7: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dab:
	/* 0x1dab: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1db3:
	/* 0x1db3: cmp    rbx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 27899ULL);
x86_l_1dba:
	/* 0x1dba: ja     1e32 <vfs_writev_magic_return+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7730ULL;
	}
x86_l_1dbc:
	/* 0x1dbc: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1dc5:
	/* 0x1dc5: lea    rdi,[r14+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1dc9:
	/* 0x1dc9: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd5:
	/* 0x1dd5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dda:
	/* 0x1dda: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ddf:
	/* 0x1ddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de1:
	/* 0x1de1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1de4:
	/* 0x1de4: jne    1e32 <vfs_writev_magic_return+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7730ULL;
	}
x86_l_1de6:
	/* 0x1de6: cmp    DWORD PTR [rsp+0x30],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158434304ULL);
x86_l_1dee:
	/* 0x1dee: jb     1df8 <vfs_writev_magic_return+0x1df8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1df8;
	}
x86_l_1df0:
	/* 0x1df0: mov    DWORD PTR [rsp+0x30],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158434303ULL);
x86_l_1df8:
	/* 0x1df8: lea    rdi,[r14+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1dfc:
	/* 0x1dfc: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e03:
	/* 0x1e03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e08:
	/* 0x1e08: mov    esi,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e0c:
	/* 0x1e0c: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e14:
	/* 0x1e14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e16:
	/* 0x1e16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7705ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7705ULL: goto x86_l_1e19;
	case 7707ULL: goto x86_l_1e1b;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7723ULL: goto x86_l_1e2b;
	case 7730ULL: goto x86_l_1e32;
	case 7738ULL: goto x86_l_1e3a;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7764ULL: goto x86_l_1e54;
	case 7772ULL: goto x86_l_1e5c;
	case 7776ULL: goto x86_l_1e60;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7793ULL: goto x86_l_1e71;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7811ULL: goto x86_l_1e83;
	case 7818ULL: goto x86_l_1e8a;
	case 7826ULL: goto x86_l_1e92;
	case 7833ULL: goto x86_l_1e99;
	case 7835ULL: goto x86_l_1e9b;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7852ULL: goto x86_l_1eac;
	case 7860ULL: goto x86_l_1eb4;
	case 7864ULL: goto x86_l_1eb8;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7881ULL: goto x86_l_1ec9;
	case 7883ULL: goto x86_l_1ecb;
	case 7886ULL: goto x86_l_1ece;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7899ULL: goto x86_l_1edb;
	case 7906ULL: goto x86_l_1ee2;
	case 7914ULL: goto x86_l_1eea;
	case 7922ULL: goto x86_l_1ef2;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7940ULL: goto x86_l_1f04;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7984ULL: goto x86_l_1f30;
	case 7987ULL: goto x86_l_1f33;
	case 7995ULL: goto x86_l_1f3b;
	case 8002ULL: goto x86_l_1f42;
	case 8009ULL: goto x86_l_1f49;
	case 8016ULL: goto x86_l_1f50;
	case 8023ULL: goto x86_l_1f57;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8053ULL: goto x86_l_1f75;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8098ULL: goto x86_l_1fa2;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8124ULL: goto x86_l_1fbc;
	case 8130ULL: goto x86_l_1fc2;
	case 8138ULL: goto x86_l_1fca;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8171ULL: goto x86_l_1feb;
	case 8175ULL: goto x86_l_1fef;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8190ULL: goto x86_l_1ffe;
	case 8192ULL: goto x86_l_2000;
	case 8194ULL: goto x86_l_2002;
	case 8200ULL: goto x86_l_2008;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8224ULL: goto x86_l_2020;
	case 8228ULL: goto x86_l_2024;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8251ULL: goto x86_l_203b;
	case 8258ULL: goto x86_l_2042;
	case 8261ULL: goto x86_l_2045;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8280ULL: goto x86_l_2058;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8292ULL: goto x86_l_2064;
	case 8296ULL: goto x86_l_2068;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8307ULL: goto x86_l_2073;
	case 8309ULL: goto x86_l_2075;
	case 8317ULL: goto x86_l_207d;
	case 8323ULL: goto x86_l_2083;
	case 8330ULL: goto x86_l_208a;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8358ULL: goto x86_l_20a6;
	case 8360ULL: goto x86_l_20a8;
	case 8363ULL: goto x86_l_20ab;
	case 8369ULL: goto x86_l_20b1;
	case 8377ULL: goto x86_l_20b9;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8418ULL: goto x86_l_20e2;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8453ULL: goto x86_l_2105;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8467ULL: goto x86_l_2113;
	case 8470ULL: goto x86_l_2116;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8494ULL: goto x86_l_212e;
	case 8498ULL: goto x86_l_2132;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8520ULL: goto x86_l_2148;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8537ULL: goto x86_l_2159;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8589ULL: goto x86_l_218d;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8621ULL: goto x86_l_21ad;
	case 8624ULL: goto x86_l_21b0;
	case 8628ULL: goto x86_l_21b4;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8650ULL: goto x86_l_21ca;
	case 8658ULL: goto x86_l_21d2;
	case 8666ULL: goto x86_l_21da;
	case 8674ULL: goto x86_l_21e2;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8706ULL: goto x86_l_2202;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8712ULL: goto x86_l_2208;
	case 8714ULL: goto x86_l_220a;
	case 8721ULL: goto x86_l_2211;
	case 8728ULL: goto x86_l_2218;
	case 8731ULL: goto x86_l_221b;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8760ULL: goto x86_l_2238;
	case 8764ULL: goto x86_l_223c;
	case 8767ULL: goto x86_l_223f;
	case 8773ULL: goto x86_l_2245;
	case 8777ULL: goto x86_l_2249;
	case 8783ULL: goto x86_l_224f;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8841ULL: goto x86_l_2289;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8959ULL: goto x86_l_22ff;
	case 8964ULL: goto x86_l_2304;
	case 8969ULL: goto x86_l_2309;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8980ULL: goto x86_l_2314;
	case 8984ULL: goto x86_l_2318;
	case 8988ULL: goto x86_l_231c;
	case 8993ULL: goto x86_l_2321;
	case 8998ULL: goto x86_l_2326;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9033ULL: goto x86_l_2349;
	case 9037ULL: goto x86_l_234d;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9059ULL: goto x86_l_2363;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9143ULL: goto x86_l_23b7;
	case 9145ULL: goto x86_l_23b9;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9157ULL: goto x86_l_23c5;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9290ULL: goto x86_l_244a;
	case 9295ULL: goto x86_l_244f;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9317ULL: goto x86_l_2465;
	case 9319ULL: goto x86_l_2467;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9342ULL: goto x86_l_247e;
	case 9344ULL: goto x86_l_2480;
	case 9348ULL: goto x86_l_2484;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9382ULL: goto x86_l_24a6;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1e19:
	/* 0x1e19: jne    1e32 <vfs_writev_magic_return+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e32;
	}
x86_l_1e1b:
	/* 0x1e1b: add    rbx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_1e1f:
	/* 0x1e1f: add    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1e23:
	/* 0x1e23: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e2b:
	/* 0x1e2b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e32:
	/* 0x1e32: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e3a:
	/* 0x1e3a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1e41:
	/* 0x1e41: ja     1e8a <vfs_writev_magic_return+0x1e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e8a;
	}
x86_l_1e43:
	/* 0x1e43: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1e4c:
	/* 0x1e4c: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1e52:
	/* 0x1e52: ja     1e8a <vfs_writev_magic_return+0x1e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e8a;
	}
x86_l_1e54:
	/* 0x1e54: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1e5c:
	/* 0x1e5c: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e60:
	/* 0x1e60: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e67:
	/* 0x1e67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e6c:
	/* 0x1e6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e71:
	/* 0x1e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e73:
	/* 0x1e73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e76:
	/* 0x1e76: js     1e8a <vfs_writev_magic_return+0x1e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e8a;
	}
x86_l_1e78:
	/* 0x1e78: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1e7b:
	/* 0x1e7b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e83:
	/* 0x1e83: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e8a:
	/* 0x1e8a: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e92:
	/* 0x1e92: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1e99:
	/* 0x1e99: ja     1ee2 <vfs_writev_magic_return+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee2;
	}
x86_l_1e9b:
	/* 0x1e9b: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1ea4:
	/* 0x1ea4: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1eaa:
	/* 0x1eaa: ja     1ee2 <vfs_writev_magic_return+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee2;
	}
x86_l_1eac:
	/* 0x1eac: lea    rdx,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1eb4:
	/* 0x1eb4: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1eb8:
	/* 0x1eb8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec4:
	/* 0x1ec4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec9:
	/* 0x1ec9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecb:
	/* 0x1ecb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ece:
	/* 0x1ece: js     1ee2 <vfs_writev_magic_return+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ee2;
	}
x86_l_1ed0:
	/* 0x1ed0: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1edb:
	/* 0x1edb: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    QWORD PTR [rsp+0x128],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1eea:
	/* 0x1eea: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ef2:
	/* 0x1ef2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1ef9:
	/* 0x1ef9: ja     1f42 <vfs_writev_magic_return+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f42;
	}
x86_l_1efb:
	/* 0x1efb: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1f04:
	/* 0x1f04: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1f0a:
	/* 0x1f0a: ja     1f42 <vfs_writev_magic_return+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f42;
	}
x86_l_1f0c:
	/* 0x1f0c: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f10:
	/* 0x1f10: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1f17:
	/* 0x1f17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1c:
	/* 0x1f1c: lea    rdx,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1f24:
	/* 0x1f24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f29:
	/* 0x1f29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2b:
	/* 0x1f2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2e:
	/* 0x1f2e: js     1f42 <vfs_writev_magic_return+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f42;
	}
x86_l_1f30:
	/* 0x1f30: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1f33:
	/* 0x1f33: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f3b:
	/* 0x1f3b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1f42:
	/* 0x1f42: lea    r12,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1f49:
	/* 0x1f49: mov    r13,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1f50:
	/* 0x1f50: mov    r15,QWORD PTR [r14+0x7df8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1f57:
	/* 0x1f57: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1f5a:
	/* 0x1f5a: je     2070 <vfs_writev_magic_return+0x2070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2070;
	}
x86_l_1f60:
	/* 0x1f60: or     r13,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 32240ULL);
x86_l_1f67:
	/* 0x1f67: mov    ebp,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f6b:
	/* 0x1f6b: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1f70:
	/* 0x1f70: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f75:
	/* 0x1f75: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f82:
	/* 0x1f82: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_bufs)));
x86_l_1f89:
	/* 0x1f89: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f8e:
	/* 0x1f8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f90:
	/* 0x1f90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f93:
	/* 0x1f93: je     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228f;
	}
x86_l_1f99:
	/* 0x1f99: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1f9c:
	/* 0x1f9c: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fa0:
	/* 0x1fa0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa2:
	/* 0x1fa2: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1faa:
	/* 0x1faa: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fac:
	/* 0x1fac: call   51bc <vfs_writev_magic_return+0x51bc> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_1fb1:
	/* 0x1fb1: movzx  eax,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fb6:
	/* 0x1fb6: cmp    rax,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31995ULL);
x86_l_1fbc:
	/* 0x1fbc: ja     2291 <vfs_writev_magic_return+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2291;
	}
x86_l_1fc2:
	/* 0x1fc2: mov    esi,DWORD PTR [rax+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1fca:
	/* 0x1fca: cmp    esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1fd0:
	/* 0x1fd0: ja     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_228f;
	}
x86_l_1fd6:
	/* 0x1fd6: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1fd9:
	/* 0x1fd9: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1fdc:
	/* 0x1fdc: lea    ecx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fdf:
	/* 0x1fdf: cmp    ecx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1fe5:
	/* 0x1fe5: ja     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_228f;
	}
x86_l_1feb:
	/* 0x1feb: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fef:
	/* 0x1fef: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ffe:
	/* 0x1ffe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2000:
	/* 0x2000: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2002:
	/* 0x2002: je     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228f;
	}
x86_l_2008:
	/* 0x2008: mov    rbp,QWORD PTR [r14+0x7e10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_200f:
	/* 0x200f: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_2014:
	/* 0x2014: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2019:
	/* 0x2019: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_2020:
	/* 0x2020: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2024:
	/* 0x2024: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2028:
	/* 0x2028: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_202d:
	/* 0x202d: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_exact_version)));
x86_l_2034:
	/* 0x2034: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2039:
	/* 0x2039: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_203b:
	/* 0x203b: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2042:
	/* 0x2042: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2045:
	/* 0x2045: je     2204 <vfs_writev_magic_return+0x2204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2204;
	}
x86_l_204b:
	/* 0x204b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2050:
	/* 0x2050: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2056:
	/* 0x2056: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2058:
	/* 0x2058: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_205b:
	/* 0x205b: je     2208 <vfs_writev_magic_return+0x2208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2208;
	}
x86_l_2061:
	/* 0x2061: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2064:
	/* 0x2064: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2068:
	/* 0x2068: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_206b:
	/* 0x206b: jmp    2211 <vfs_writev_magic_return+0x2211> */
	goto x86_l_2211;
x86_l_2070:
	/* 0x2070: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2073:
	/* 0x2073: jne    2083 <vfs_writev_magic_return+0x2083> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2083;
	}
x86_l_2075:
	/* 0x2075: cmp    QWORD PTR [r14+0x7df0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138469745623040ULL);
x86_l_207d:
	/* 0x207d: je     21b9 <vfs_writev_magic_return+0x21b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b9;
	}
x86_l_2083:
	/* 0x2083: lea    rbx,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_208a:
	/* 0x208a: mov    r15,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2091:
	/* 0x2091: or     r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_2094:
	/* 0x2094: mov    ebp,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2098:
	/* 0x2098: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_209d:
	/* 0x209d: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20a2:
	/* 0x20a2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a4:
	/* 0x20a4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a6:
	/* 0x20a6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a8:
	/* 0x20a8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_20ab:
	/* 0x20ab: je     2245 <vfs_writev_magic_return+0x2245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2245;
	}
x86_l_20b1:
	/* 0x20b1: mov    QWORD PTR [rsp+0x110],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_20b9:
	/* 0x20b9: mov    QWORD PTR [rsp+0x120],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_20c1:
	/* 0x20c1: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_20c4:
	/* 0x20c4: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20cc:
	/* 0x20cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20d1:
	/* 0x20d1: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_20d8:
	/* 0x20d8: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20dd:
	/* 0x20dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20df:
	/* 0x20df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20e2:
	/* 0x20e2: je     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228f;
	}
x86_l_20e8:
	/* 0x20e8: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20ed:
	/* 0x20ed: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_20f4:
	/* 0x20f4: ja     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_228f;
	}
x86_l_20fa:
	/* 0x20fa: lea    edx,[rcx+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_20fd:
	/* 0x20fd: mov    ecx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2105:
	/* 0x2105: cmp    ecx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_210b:
	/* 0x210b: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2110:
	/* 0x2110: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2113:
	/* 0x2113: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2116:
	/* 0x2116: lea    edx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2119:
	/* 0x2119: cmp    edx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_211f:
	/* 0x211f: ja     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_228f;
	}
x86_l_2125:
	/* 0x2125: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212a:
	/* 0x212a: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_212e:
	/* 0x212e: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2132:
	/* 0x2132: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2139:
	/* 0x2139: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_213e:
	/* 0x213e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2140:
	/* 0x2140: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2142:
	/* 0x2142: je     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228f;
	}
x86_l_2148:
	/* 0x2148: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_214b:
	/* 0x214b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2150:
	/* 0x2150: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2152:
	/* 0x2152: mov    rax,QWORD PTR [r14+0x7e00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_2159:
	/* 0x2159: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2161:
	/* 0x2161: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_2166:
	/* 0x2166: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_216b:
	/* 0x216b: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_2172:
	/* 0x2172: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2176:
	/* 0x2176: mov    DWORD PTR [rsp+0x34],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_217a:
	/* 0x217a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_217f:
	/* 0x217f: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_prefix_version)));
x86_l_2186:
	/* 0x2186: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_218b:
	/* 0x218b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218d:
	/* 0x218d: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2194:
	/* 0x2194: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2197:
	/* 0x2197: je     21c5 <vfs_writev_magic_return+0x21c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c5;
	}
x86_l_2199:
	/* 0x2199: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_219e:
	/* 0x219e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_21a1:
	/* 0x21a1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21a6:
	/* 0x21a6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21a8:
	/* 0x21a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ab:
	/* 0x21ab: je     21c5 <vfs_writev_magic_return+0x21c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c5;
	}
x86_l_21ad:
	/* 0x21ad: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b0:
	/* 0x21b0: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b4:
	/* 0x21b4: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_21b7:
	/* 0x21b7: jmp    21c7 <vfs_writev_magic_return+0x21c7> */
	goto x86_l_21c7;
x86_l_21b9:
	/* 0x21b9: mov    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32496ULL);
x86_l_21c0:
	/* 0x21c0: jmp    2291 <vfs_writev_magic_return+0x2291> */
	goto x86_l_2291;
x86_l_21c5:
	/* 0x21c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c7:
	/* 0x21c7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21ca:
	/* 0x21ca: mov    rsi,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_21d2:
	/* 0x21d2: mov    rdi,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_21da:
	/* 0x21da: mov    r8,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21e2:
	/* 0x21e2: and    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_21e5:
	/* 0x21e5: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_21e8:
	/* 0x21e8: andn   rax,r8,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_21ed:
	/* 0x21ed: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_21f0:
	/* 0x21f0: andn   rax,rbp,r8 */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_21f5:
	/* 0x21f5: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_21f8:
	/* 0x21f8: and    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_21fb:
	/* 0x21fb: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_21fe:
	/* 0x21fe: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2202:
	/* 0x2202: jmp    2245 <vfs_writev_magic_return+0x2245> */
	goto x86_l_2245;
x86_l_2204:
	/* 0x2204: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2206:
	/* 0x2206: jmp    2211 <vfs_writev_magic_return+0x2211> */
	goto x86_l_2211;
x86_l_2208:
	/* 0x2208: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_220a:
	/* 0x220a: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2211:
	/* 0x2211: lea    rbx,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2218:
	/* 0x2218: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_221b:
	/* 0x221b: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_221e:
	/* 0x221e: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2221:
	/* 0x2221: andn   rsi,rbp,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RSI, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_2226:
	/* 0x2226: andn   rdi,rdx,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RDI, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_222b:
	/* 0x222b: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_222e:
	/* 0x222e: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2231:
	/* 0x2231: mov    r13,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2238:
	/* 0x2238: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_223c:
	/* 0x223c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_223f:
	/* 0x223f: jne    20b1 <vfs_writev_magic_return+0x20b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20b1;
	}
x86_l_2245:
	/* 0x2245: cmp    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2249:
	/* 0x2249: je     28a6 <vfs_writev_magic_return+0x28a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10406ULL;
	}
x86_l_224f:
	/* 0x224f: mov    QWORD PTR [rsp+0x110],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2257:
	/* 0x2257: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_225a:
	/* 0x225a: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_225d:
	/* 0x225d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2265:
	/* 0x2265: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_226a:
	/* 0x226a: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_2271:
	/* 0x2271: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2276:
	/* 0x2276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2278:
	/* 0x2278: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_227b:
	/* 0x227b: je     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228f;
	}
x86_l_227d:
	/* 0x227d: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2282:
	/* 0x2282: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_2289:
	/* 0x2289: jbe    2701 <vfs_writev_magic_return+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9985ULL;
	}
x86_l_228f:
	/* 0x228f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2291:
	/* 0x2291: and    QWORD PTR [r14+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_2298:
	/* 0x2298: je     2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10761ULL;
	}
x86_l_229e:
	/* 0x229e: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_22a5:
	/* 0x22a5: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a9:
	/* 0x22a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22ae:
	/* 0x22ae: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b3:
	/* 0x22b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b8:
	/* 0x22b8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_22bb:
	/* 0x22bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bd:
	/* 0x22bd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22c2:
	/* 0x22c2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22c7:
	/* 0x22c7: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22cb:
	/* 0x22cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22d0:
	/* 0x22d0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22d5:
	/* 0x22d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22da:
	/* 0x22da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22dc:
	/* 0x22dc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e1:
	/* 0x22e1: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_22e5:
	/* 0x22e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22ea:
	/* 0x22ea: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22ef:
	/* 0x22ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f4:
	/* 0x22f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f6:
	/* 0x22f6: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22fb:
	/* 0x22fb: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22ff:
	/* 0x22ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2304:
	/* 0x2304: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2309:
	/* 0x2309: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_230e:
	/* 0x230e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2310:
	/* 0x2310: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2314:
	/* 0x2314: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2318:
	/* 0x2318: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231c:
	/* 0x231c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2321:
	/* 0x2321: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2326:
	/* 0x2326: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232b:
	/* 0x232b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_232e:
	/* 0x232e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2330:
	/* 0x2330: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2335:
	/* 0x2335: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_233a:
	/* 0x233a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_233f:
	/* 0x233f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2344:
	/* 0x2344: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2347:
	/* 0x2347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2349:
	/* 0x2349: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_234d:
	/* 0x234d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2351:
	/* 0x2351: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2355:
	/* 0x2355: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2359:
	/* 0x2359: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_235e:
	/* 0x235e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2363:
	/* 0x2363: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2368:
	/* 0x2368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236a:
	/* 0x236a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236e:
	/* 0x236e: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2372:
	/* 0x2372: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2377:
	/* 0x2377: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_237c:
	/* 0x237c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2381:
	/* 0x2381: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2384:
	/* 0x2384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2386:
	/* 0x2386: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_238b:
	/* 0x238b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_238f:
	/* 0x238f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2394:
	/* 0x2394: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2399:
	/* 0x2399: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_239e:
	/* 0x239e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a0:
	/* 0x23a0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23a5:
	/* 0x23a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23aa:
	/* 0x23aa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23af:
	/* 0x23af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23b4:
	/* 0x23b4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23b7:
	/* 0x23b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b9:
	/* 0x23b9: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23bd:
	/* 0x23bd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_23c1:
	/* 0x23c1: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_23c5:
	/* 0x23c5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23c9:
	/* 0x23c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23ce:
	/* 0x23ce: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23d3:
	/* 0x23d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23d8:
	/* 0x23d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23da:
	/* 0x23da: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23de:
	/* 0x23de: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23e2:
	/* 0x23e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23e7:
	/* 0x23e7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23ec:
	/* 0x23ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f1:
	/* 0x23f1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23f4:
	/* 0x23f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f6:
	/* 0x23f6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23fb:
	/* 0x23fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2400:
	/* 0x2400: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2405:
	/* 0x2405: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_240a:
	/* 0x240a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_240d:
	/* 0x240d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240f:
	/* 0x240f: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2413:
	/* 0x2413: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2417:
	/* 0x2417: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_241b:
	/* 0x241b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_241f:
	/* 0x241f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2424:
	/* 0x2424: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2429:
	/* 0x2429: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_242e:
	/* 0x242e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2430:
	/* 0x2430: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2435:
	/* 0x2435: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2439:
	/* 0x2439: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_243e:
	/* 0x243e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2443:
	/* 0x2443: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2448:
	/* 0x2448: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244a:
	/* 0x244a: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_244f:
	/* 0x244f: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2453:
	/* 0x2453: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2458:
	/* 0x2458: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_245d:
	/* 0x245d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2462:
	/* 0x2462: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2465:
	/* 0x2465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2467:
	/* 0x2467: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_246c:
	/* 0x246c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2471:
	/* 0x2471: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2476:
	/* 0x2476: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_247b:
	/* 0x247b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_247e:
	/* 0x247e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2480:
	/* 0x2480: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2484:
	/* 0x2484: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2488:
	/* 0x2488: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_248c:
	/* 0x248c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2490:
	/* 0x2490: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2495:
	/* 0x2495: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_249a:
	/* 0x249a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_249f:
	/* 0x249f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a1:
	/* 0x24a1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24a6:
	/* 0x24a6: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_24aa:
	/* 0x24aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24af:
	/* 0x24af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b4:
	/* 0x24b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24b9:
	/* 0x24b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bb:
	/* 0x24bb: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_24c0:
	/* 0x24c0: jne    2518 <vfs_writev_magic_return+0x2518> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9496ULL;
	}
x86_l_24c2:
	/* 0x24c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24c7:
	/* 0x24c7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24cc:
	/* 0x24cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24d1:
	/* 0x24d1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24d4:
	/* 0x24d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d6:
	/* 0x24d6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24db:
	/* 0x24db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24e0:
	/* 0x24e0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24e5:
	/* 0x24e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 9450ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9459ULL: goto x86_l_24f3;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9500ULL: goto x86_l_251c;
	case 9504ULL: goto x86_l_2520;
	case 9511ULL: goto x86_l_2527;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9598ULL: goto x86_l_257e;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9663ULL: goto x86_l_25bf;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9716ULL: goto x86_l_25f4;
	case 9721ULL: goto x86_l_25f9;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9732ULL: goto x86_l_2604;
	case 9740ULL: goto x86_l_260c;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9778ULL: goto x86_l_2632;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9827ULL: goto x86_l_2663;
	case 9830ULL: goto x86_l_2666;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9872ULL: goto x86_l_2690;
	case 9880ULL: goto x86_l_2698;
	case 9884ULL: goto x86_l_269c;
	case 9892ULL: goto x86_l_26a4;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9914ULL: goto x86_l_26ba;
	case 9916ULL: goto x86_l_26bc;
	case 9918ULL: goto x86_l_26be;
	case 9920ULL: goto x86_l_26c0;
	case 9924ULL: goto x86_l_26c4;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9945ULL: goto x86_l_26d9;
	case 9951ULL: goto x86_l_26df;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9988ULL: goto x86_l_2704;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10004ULL: goto x86_l_2714;
	case 10006ULL: goto x86_l_2716;
	case 10012ULL: goto x86_l_271c;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10026ULL: goto x86_l_272a;
	case 10032ULL: goto x86_l_2730;
	case 10034ULL: goto x86_l_2732;
	case 10036ULL: goto x86_l_2734;
	case 10038ULL: goto x86_l_2736;
	case 10044ULL: goto x86_l_273c;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10056ULL: goto x86_l_2748;
	case 10062ULL: goto x86_l_274e;
	case 10064ULL: goto x86_l_2750;
	case 10070ULL: goto x86_l_2756;
	case 10076ULL: goto x86_l_275c;
	case 10079ULL: goto x86_l_275f;
	case 10081ULL: goto x86_l_2761;
	case 10083ULL: goto x86_l_2763;
	case 10085ULL: goto x86_l_2765;
	case 10087ULL: goto x86_l_2767;
	case 10089ULL: goto x86_l_2769;
	case 10095ULL: goto x86_l_276f;
	case 10101ULL: goto x86_l_2775;
	case 10103ULL: goto x86_l_2777;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10120ULL: goto x86_l_2788;
	case 10122ULL: goto x86_l_278a;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10129ULL: goto x86_l_2791;
	case 10132ULL: goto x86_l_2794;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10151ULL: goto x86_l_27a7;
	case 10157ULL: goto x86_l_27ad;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10174ULL: goto x86_l_27be;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10231ULL: goto x86_l_27f7;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10242ULL: goto x86_l_2802;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10270ULL: goto x86_l_281e;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10294ULL: goto x86_l_2836;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10325ULL: goto x86_l_2855;
	case 10328ULL: goto x86_l_2858;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10350ULL: goto x86_l_286e;
	case 10353ULL: goto x86_l_2871;
	case 10357ULL: goto x86_l_2875;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10364ULL: goto x86_l_287c;
	case 10367ULL: goto x86_l_287f;
	case 10370ULL: goto x86_l_2882;
	case 10378ULL: goto x86_l_288a;
	case 10381ULL: goto x86_l_288d;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10392ULL: goto x86_l_2898;
	case 10397ULL: goto x86_l_289d;
	case 10400ULL: goto x86_l_28a0;
	case 10403ULL: goto x86_l_28a3;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10427ULL: goto x86_l_28bb;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10479ULL: goto x86_l_28ef;
	case 10485ULL: goto x86_l_28f5;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10506ULL: goto x86_l_290a;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10524ULL: goto x86_l_291c;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10542ULL: goto x86_l_292e;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10561ULL: goto x86_l_2941;
	case 10563ULL: goto x86_l_2943;
	case 10571ULL: goto x86_l_294b;
	case 10574ULL: goto x86_l_294e;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10615ULL: goto x86_l_2977;
	case 10619ULL: goto x86_l_297b;
	case 10621ULL: goto x86_l_297d;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10634ULL: goto x86_l_298a;
	case 10636ULL: goto x86_l_298c;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10663ULL: goto x86_l_29a7;
	case 10666ULL: goto x86_l_29aa;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10694ULL: goto x86_l_29c6;
	case 10699ULL: goto x86_l_29cb;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10722ULL: goto x86_l_29e2;
	case 10725ULL: goto x86_l_29e5;
	case 10729ULL: goto x86_l_29e9;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10744ULL: goto x86_l_29f8;
	case 10746ULL: goto x86_l_29fa;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10763ULL: goto x86_l_2a0b;
	case 10770ULL: goto x86_l_2a12;
	case 10772ULL: goto x86_l_2a14;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10803ULL: goto x86_l_2a33;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10817ULL: goto x86_l_2a41;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10885ULL: goto x86_l_2a85;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10900ULL: goto x86_l_2a94;
	case 10905ULL: goto x86_l_2a99;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10920ULL: goto x86_l_2aa8;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10941ULL: goto x86_l_2abd;
	case 10949ULL: goto x86_l_2ac5;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10968ULL: goto x86_l_2ad8;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10985ULL: goto x86_l_2ae9;
	case 10989ULL: goto x86_l_2aed;
	case 10991ULL: goto x86_l_2aef;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11004ULL: goto x86_l_2afc;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11031ULL: goto x86_l_2b17;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11067ULL: goto x86_l_2b3b;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	default: return 0xffffffffffffffffULL;
	}
x86_l_24ea:
	/* 0x24ea: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24ed:
	/* 0x24ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ef:
	/* 0x24ef: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24f3:
	/* 0x24f3: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_24f7:
	/* 0x24f7: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_24fb:
	/* 0x24fb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24ff:
	/* 0x24ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2504:
	/* 0x2504: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2509:
	/* 0x2509: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_250e:
	/* 0x250e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2510:
	/* 0x2510: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2514:
	/* 0x2514: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2518:
	/* 0x2518: lea    r12,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251c:
	/* 0x251c: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2520:
	/* 0x2520: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2527:
	/* 0x2527: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_252c:
	/* 0x252c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2531:
	/* 0x2531: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2536:
	/* 0x2536: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2539:
	/* 0x2539: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253b:
	/* 0x253b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2540:
	/* 0x2540: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2544:
	/* 0x2544: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2549:
	/* 0x2549: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_254e:
	/* 0x254e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2553:
	/* 0x2553: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2555:
	/* 0x2555: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_255a:
	/* 0x255a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_255f:
	/* 0x255f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2564:
	/* 0x2564: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2569:
	/* 0x2569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256b:
	/* 0x256b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_256f:
	/* 0x256f: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2573:
	/* 0x2573: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2578:
	/* 0x2578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257a:
	/* 0x257a: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_257e:
	/* 0x257e: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2582:
	/* 0x2582: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2587:
	/* 0x2587: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_258c:
	/* 0x258c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2591:
	/* 0x2591: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2593:
	/* 0x2593: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2598:
	/* 0x2598: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259c:
	/* 0x259c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25a1:
	/* 0x25a1: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_25a5:
	/* 0x25a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25aa:
	/* 0x25aa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25af:
	/* 0x25af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25b4:
	/* 0x25b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b6:
	/* 0x25b6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25bb:
	/* 0x25bb: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25bf:
	/* 0x25bf: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_25c3:
	/* 0x25c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25c8:
	/* 0x25c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25cd:
	/* 0x25cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d2:
	/* 0x25d2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_25d5:
	/* 0x25d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d7:
	/* 0x25d7: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25dc:
	/* 0x25dc: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25e0:
	/* 0x25e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25e5:
	/* 0x25e5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ea:
	/* 0x25ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25ef:
	/* 0x25ef: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_25f2:
	/* 0x25f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f4:
	/* 0x25f4: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_25f9:
	/* 0x25f9: je     2600 <vfs_writev_magic_return+0x2600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2600;
	}
x86_l_25fb:
	/* 0x25fb: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2600:
	/* 0x2600: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2604:
	/* 0x2604: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_260c:
	/* 0x260c: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2614:
	/* 0x2614: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2619:
	/* 0x2619: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_261e:
	/* 0x261e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2620:
	/* 0x2620: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2625:
	/* 0x2625: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262a:
	/* 0x262a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_262f:
	/* 0x262f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2632:
	/* 0x2632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2634:
	/* 0x2634: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2639:
	/* 0x2639: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_263e:
	/* 0x263e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2643:
	/* 0x2643: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2648:
	/* 0x2648: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264a:
	/* 0x264a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_264f:
	/* 0x264f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2654:
	/* 0x2654: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2659:
	/* 0x2659: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_265c:
	/* 0x265c: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2661:
	/* 0x2661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2663:
	/* 0x2663: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2666:
	/* 0x2666: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_266a:
	/* 0x266a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_266f:
	/* 0x266f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2674:
	/* 0x2674: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2677:
	/* 0x2677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2679:
	/* 0x2679: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_267e:
	/* 0x267e: mov    rdi,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2686:
	/* 0x2686: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_268b:
	/* 0x268b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_268e:
	/* 0x268e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2690:
	/* 0x2690: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2698:
	/* 0x2698: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_269c:
	/* 0x269c: mov    rbx,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_26a4:
	/* 0x26a4: je     26c4 <vfs_writev_magic_return+0x26c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26c4;
	}
x86_l_26a6:
	/* 0x26a6: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_26ab:
	/* 0x26ab: mov    rsi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_26b2:
	/* 0x26b2: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_26b7:
	/* 0x26b7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26ba:
	/* 0x26ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26bc:
	/* 0x26bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26be:
	/* 0x26be: js     26c4 <vfs_writev_magic_return+0x26c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26c4;
	}
x86_l_26c0:
	/* 0x26c0: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26c4:
	/* 0x26c4: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26cc:
	/* 0x26cc: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_26d1:
	/* 0x26d1: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_26d6:
	/* 0x26d6: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_26d9:
	/* 0x26d9: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_26df:
	/* 0x26df: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26e3:
	/* 0x26e3: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_26e8:
	/* 0x26e8: mov    rsi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_26ef:
	/* 0x26ef: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26f4:
	/* 0x26f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26f7:
	/* 0x26f7: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_26fa:
	/* 0x26fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fc:
	/* 0x26fc: jmp    2a0b <vfs_writev_magic_return+0x2a0b> */
	goto x86_l_2a0b;
x86_l_2701:
	/* 0x2701: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_2704:
	/* 0x2704: mov    edx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_270c:
	/* 0x270c: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2712:
	/* 0x2712: jbe    2732 <vfs_writev_magic_return+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2732;
	}
x86_l_2714:
	/* 0x2714: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2716:
	/* 0x2716: add    ecx,0xffffff05 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967045ULL);
x86_l_271c:
	/* 0x271c: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_271f:
	/* 0x271f: mov    edx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 255ULL);
x86_l_2724:
	/* 0x2724: cmp    ecx,0x7c00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31744ULL);
x86_l_272a:
	/* 0x272a: ja     228f <vfs_writev_magic_return+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8847ULL;
	}
x86_l_2730:
	/* 0x2730: jmp    275f <vfs_writev_magic_return+0x275f> */
	goto x86_l_275f;
x86_l_2732:
	/* 0x2732: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2734:
	/* 0x2734: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2736:
	/* 0x2736: je     2291 <vfs_writev_magic_return+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8849ULL;
	}
x86_l_273c:
	/* 0x273c: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_273f:
	/* 0x273f: add    esi,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2742:
	/* 0x2742: cmp    esi,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 32000ULL);
x86_l_2748:
	/* 0x2748: ja     2291 <vfs_writev_magic_return+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8849ULL;
	}
x86_l_274e:
	/* 0x274e: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2750:
	/* 0x2750: and    edx,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 255ULL);
x86_l_2756:
	/* 0x2756: je     2807 <vfs_writev_magic_return+0x2807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2807;
	}
x86_l_275c:
	/* 0x275c: add    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_275f:
	/* 0x275f: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2761:
	/* 0x2761: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2763:
	/* 0x2763: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2765:
	/* 0x2765: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2767:
	/* 0x2767: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2769:
	/* 0x2769: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_276f:
	/* 0x276f: ja     2291 <vfs_writev_magic_return+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8849ULL;
	}
x86_l_2775:
	/* 0x2775: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2777:
	/* 0x2777: movzx  edi,BYTE PTR [r14+rdi*1+0x89] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 0, X86_WIDTH_8), 137ULL);
x86_l_2780:
	/* 0x2780: mov    BYTE PTR [rax+rdx*1+0x4],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_2785:
	/* 0x2785: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2788:
	/* 0x2788: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_278a:
	/* 0x278a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_278d:
	/* 0x278d: jne    2769 <vfs_writev_magic_return+0x2769> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2769;
	}
x86_l_278f:
	/* 0x278f: jmp    2809 <vfs_writev_magic_return+0x2809> */
	goto x86_l_2809;
x86_l_2791:
	/* 0x2791: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2794:
	/* 0x2794: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_279a:
	/* 0x279a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_279f:
	/* 0x279f: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_27a4:
	/* 0x27a4: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_27a7:
	/* 0x27a7: je     1a44 <vfs_writev_magic_return+0x1a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6724ULL;
	}
x86_l_27ad:
	/* 0x27ad: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_27b0:
	/* 0x27b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27b5:
	/* 0x27b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ba:
	/* 0x27ba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27be:
	/* 0x27be: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_27c6:
	/* 0x27c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27cb:
	/* 0x27cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cd:
	/* 0x27cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27d2:
	/* 0x27d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d7:
	/* 0x27d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27dc:
	/* 0x27dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e1:
	/* 0x27e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e3:
	/* 0x27e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e8:
	/* 0x27e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ed:
	/* 0x27ed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27f2:
	/* 0x27f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27f7:
	/* 0x27f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f9:
	/* 0x27f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27fe:
	/* 0x27fe: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2802:
	/* 0x2802: jmp    290d <vfs_writev_magic_return+0x290d> */
	goto x86_l_290d;
x86_l_2807:
	/* 0x2807: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2809:
	/* 0x2809: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_280b:
	/* 0x280b: mov    BYTE PTR [rax+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_2810:
	/* 0x2810: lea    ecx,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_2817:
	/* 0x2817: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_281c:
	/* 0x281c: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_281e:
	/* 0x281e: mov    rbp,QWORD PTR [r14+0x7e08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_2825:
	/* 0x2825: movzx  eax,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_282a:
	/* 0x282a: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_282f:
	/* 0x282f: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_2836:
	/* 0x2836: mov    DWORD PTR [rsp+0x34],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_283b:
	/* 0x283b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2840:
	/* 0x2840: mov    rdi,QWORD PTR [rip+0x320b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_suffix_version)));
x86_l_2847:
	/* 0x2847: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_284c:
	/* 0x284c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284e:
	/* 0x284e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2855:
	/* 0x2855: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2858:
	/* 0x2858: je     287a <vfs_writev_magic_return+0x287a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287a;
	}
x86_l_285a:
	/* 0x285a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_285f:
	/* 0x285f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2862:
	/* 0x2862: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2867:
	/* 0x2867: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2869:
	/* 0x2869: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_286c:
	/* 0x286c: je     287a <vfs_writev_magic_return+0x287a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287a;
	}
x86_l_286e:
	/* 0x286e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2871:
	/* 0x2871: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2875:
	/* 0x2875: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2878:
	/* 0x2878: jmp    287c <vfs_writev_magic_return+0x287c> */
	goto x86_l_287c;
x86_l_287a:
	/* 0x287a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_287c:
	/* 0x287c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_287f:
	/* 0x287f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2882:
	/* 0x2882: mov    rdi,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_288a:
	/* 0x288a: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_288d:
	/* 0x288d: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2890:
	/* 0x2890: andn   rax,rbp,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_2895:
	/* 0x2895: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2898:
	/* 0x2898: andn   rax,r12,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_289d:
	/* 0x289d: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28a0:
	/* 0x28a0: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_28a3:
	/* 0x28a3: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_28a6:
	/* 0x28a6: andn   rax,rdi,rdx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_28ab:
	/* 0x28ab: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28ae:
	/* 0x28ae: or     r15,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_28b1:
	/* 0x28b1: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28b4:
	/* 0x28b4: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_28bb:
	/* 0x28bb: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_28be:
	/* 0x28be: jmp    2291 <vfs_writev_magic_return+0x2291> */
	return 8849ULL;
x86_l_28c3:
	/* 0x28c3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28c8:
	/* 0x28c8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28ce:
	/* 0x28ce: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28d1:
	/* 0x28d1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_28d6:
	/* 0x28d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d8:
	/* 0x28d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28db:
	/* 0x28db: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_28de:
	/* 0x28de: jl     1a44 <vfs_writev_magic_return+0x1a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6724ULL;
	}
x86_l_28e4:
	/* 0x28e4: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_28e7:
	/* 0x28e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ec:
	/* 0x28ec: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_28ef:
	/* 0x28ef: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_28f5:
	/* 0x28f5: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_28fb:
	/* 0x28fb: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28fd:
	/* 0x28fd: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2902:
	/* 0x2902: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_290a:
	/* 0x290a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_290d:
	/* 0x290d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2912:
	/* 0x2912: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2917:
	/* 0x2917: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291c:
	/* 0x291c: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_291f:
	/* 0x291f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2921:
	/* 0x2921: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2926:
	/* 0x2926: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_292e:
	/* 0x292e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2932:
	/* 0x2932: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2937:
	/* 0x2937: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_293c:
	/* 0x293c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2941:
	/* 0x2941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2943:
	/* 0x2943: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_294b:
	/* 0x294b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_294e:
	/* 0x294e: je     2a1a <vfs_writev_magic_return+0x2a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1a;
	}
x86_l_2954:
	/* 0x2954: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2959:
	/* 0x2959: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_295c:
	/* 0x295c: je     2a1a <vfs_writev_magic_return+0x2a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1a;
	}
x86_l_2962:
	/* 0x2962: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2966:
	/* 0x2966: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_296b:
	/* 0x296b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2970:
	/* 0x2970: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2975:
	/* 0x2975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2977:
	/* 0x2977: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_297b:
	/* 0x297b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_297d:
	/* 0x297d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2983:
	/* 0x2983: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2988:
	/* 0x2988: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_298a:
	/* 0x298a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_298c:
	/* 0x298c: jb     1ba3 <vfs_writev_magic_return+0x1ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7075ULL;
	}
x86_l_2992:
	/* 0x2992: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2997:
	/* 0x2997: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_299d:
	/* 0x299d: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29a0:
	/* 0x29a0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_29a5:
	/* 0x29a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a7:
	/* 0x29a7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29aa:
	/* 0x29aa: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_29b0:
	/* 0x29b0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b5:
	/* 0x29b5: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_29b8:
	/* 0x29b8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_29be:
	/* 0x29be: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_29c4:
	/* 0x29c4: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29c6:
	/* 0x29c6: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29cb:
	/* 0x29cb: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_29d3:
	/* 0x29d3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_29d6:
	/* 0x29d6: jmp    2a85 <vfs_writev_magic_return+0x2a85> */
	goto x86_l_2a85;
x86_l_29db:
	/* 0x29db: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_29e2:
	/* 0x29e2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29e5:
	/* 0x29e5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29e9:
	/* 0x29e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ee:
	/* 0x29ee: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_29f3:
	/* 0x29f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f5:
	/* 0x29f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29f8:
	/* 0x29f8: jne    2a09 <vfs_writev_magic_return+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a09;
	}
x86_l_29fa:
	/* 0x29fa: movzx  eax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_29ff:
	/* 0x29ff: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2a04:
	/* 0x2a04: jmp    c7d <vfs_writev_magic_return+0xc7d> */
	return 3197ULL;
x86_l_2a09:
	/* 0x2a09: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a0b:
	/* 0x2a0b: add    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 328ULL);
x86_l_2a12:
	/* 0x2a12: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2a14:
	/* 0x2a14: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2a15:
	/* 0x2a15: jmp    3da8 <vfs_writev_magic_return+0x3da8> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2a1a:
	/* 0x2a1a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a1d:
	/* 0x2a1d: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_2a23:
	/* 0x2a23: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a28:
	/* 0x2a28: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2a2d:
	/* 0x2a2d: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_2a33:
	/* 0x2a33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a38:
	/* 0x2a38: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3d:
	/* 0x2a3d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a41:
	/* 0x2a41: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a49:
	/* 0x2a49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a4e:
	/* 0x2a4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a50:
	/* 0x2a50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5a:
	/* 0x2a5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a64:
	/* 0x2a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a66:
	/* 0x2a66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a70:
	/* 0x2a70: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a75:
	/* 0x2a75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a7a:
	/* 0x2a7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7c:
	/* 0x2a7c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a81:
	/* 0x2a81: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a85:
	/* 0x2a85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a8a:
	/* 0x2a8a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8f:
	/* 0x2a8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a94:
	/* 0x2a94: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a99:
	/* 0x2a99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9b:
	/* 0x2a9b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2aa0:
	/* 0x2aa0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2aa8:
	/* 0x2aa8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2aac:
	/* 0x2aac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab1:
	/* 0x2ab1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2abb:
	/* 0x2abb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abd:
	/* 0x2abd: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ac5:
	/* 0x2ac5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ac8:
	/* 0x2ac8: je     2b14 <vfs_writev_magic_return+0x2b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b14;
	}
x86_l_2aca:
	/* 0x2aca: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2acf:
	/* 0x2acf: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ad2:
	/* 0x2ad2: je     2b14 <vfs_writev_magic_return+0x2b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b14;
	}
x86_l_2ad4:
	/* 0x2ad4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2add:
	/* 0x2add: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ae7:
	/* 0x2ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae9:
	/* 0x2ae9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2aed:
	/* 0x2aed: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2aef:
	/* 0x2aef: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2af5:
	/* 0x2af5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2afa:
	/* 0x2afa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2afc:
	/* 0x2afc: jae    2b86 <vfs_writev_magic_return+0x2b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11142ULL;
	}
x86_l_2b02:
	/* 0x2b02: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0f:
	/* 0x2b0f: jmp    1bab <vfs_writev_magic_return+0x1bab> */
	return 7083ULL;
x86_l_2b14:
	/* 0x2b14: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b17:
	/* 0x2b17: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_2b1d:
	/* 0x2b1d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b22:
	/* 0x2b22: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2b27:
	/* 0x2b27: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_2b2d:
	/* 0x2b2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b32:
	/* 0x2b32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b37:
	/* 0x2b37: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b3b:
	/* 0x2b3b: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b43:
	/* 0x2b43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b48:
	/* 0x2b48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4a:
	/* 0x2b4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b54:
	/* 0x2b54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 11097ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11124ULL: goto x86_l_2b74;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11153ULL: goto x86_l_2b91;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11166ULL: goto x86_l_2b9e;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11180ULL: goto x86_l_2bac;
	case 11186ULL: goto x86_l_2bb2;
	case 11192ULL: goto x86_l_2bb8;
	case 11194ULL: goto x86_l_2bba;
	case 11199ULL: goto x86_l_2bbf;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11242ULL: goto x86_l_2bea;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11263ULL: goto x86_l_2bff;
	case 11271ULL: goto x86_l_2c07;
	case 11274ULL: goto x86_l_2c0a;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11284ULL: goto x86_l_2c14;
	case 11286ULL: goto x86_l_2c16;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11305ULL: goto x86_l_2c29;
	case 11307ULL: goto x86_l_2c2b;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11319ULL: goto x86_l_2c37;
	case 11324ULL: goto x86_l_2c3c;
	case 11326ULL: goto x86_l_2c3e;
	case 11332ULL: goto x86_l_2c44;
	case 11337ULL: goto x86_l_2c49;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11353ULL: goto x86_l_2c59;
	case 11356ULL: goto x86_l_2c5c;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11370ULL: goto x86_l_2c6a;
	case 11376ULL: goto x86_l_2c70;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11438ULL: goto x86_l_2cae;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11531ULL: goto x86_l_2d0b;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11546ULL: goto x86_l_2d1a;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11565ULL: goto x86_l_2d2d;
	case 11567ULL: goto x86_l_2d2f;
	case 11575ULL: goto x86_l_2d37;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11588ULL: goto x86_l_2d44;
	case 11590ULL: goto x86_l_2d46;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11611ULL: goto x86_l_2d5b;
	case 11615ULL: goto x86_l_2d5f;
	case 11617ULL: goto x86_l_2d61;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11630ULL: goto x86_l_2d6e;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11674ULL: goto x86_l_2d9a;
	case 11680ULL: goto x86_l_2da0;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11701ULL: goto x86_l_2db5;
	case 11703ULL: goto x86_l_2db7;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11742ULL: goto x86_l_2dde;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11810ULL: goto x86_l_2e22;
	case 11815ULL: goto x86_l_2e27;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11837ULL: goto x86_l_2e3d;
	case 11842ULL: goto x86_l_2e42;
	case 11850ULL: goto x86_l_2e4a;
	case 11854ULL: goto x86_l_2e4e;
	case 11859ULL: goto x86_l_2e53;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11871ULL: goto x86_l_2e5f;
	case 11879ULL: goto x86_l_2e67;
	case 11882ULL: goto x86_l_2e6a;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11894ULL: goto x86_l_2e76;
	case 11898ULL: goto x86_l_2e7a;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11915ULL: goto x86_l_2e8b;
	case 11919ULL: goto x86_l_2e8f;
	case 11921ULL: goto x86_l_2e91;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11934ULL: goto x86_l_2e9e;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11951ULL: goto x86_l_2eaf;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11961ULL: goto x86_l_2eb9;
	case 11964ULL: goto x86_l_2ebc;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11978ULL: goto x86_l_2eca;
	case 11984ULL: goto x86_l_2ed0;
	case 11990ULL: goto x86_l_2ed6;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 12005ULL: goto x86_l_2ee5;
	case 12007ULL: goto x86_l_2ee7;
	case 12010ULL: goto x86_l_2eea;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12026ULL: goto x86_l_2efa;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12046ULL: goto x86_l_2f0e;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12154ULL: goto x86_l_2f7a;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12196ULL: goto x86_l_2fa4;
	case 12198ULL: goto x86_l_2fa6;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12217ULL: goto x86_l_2fb9;
	case 12219ULL: goto x86_l_2fbb;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12238ULL: goto x86_l_2fce;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12265ULL: goto x86_l_2fe9;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12294ULL: goto x86_l_3006;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12314ULL: goto x86_l_301a;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12350ULL: goto x86_l_303e;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12407ULL: goto x86_l_3077;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12418ULL: goto x86_l_3082;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12433ULL: goto x86_l_3091;
	case 12438ULL: goto x86_l_3096;
	case 12443ULL: goto x86_l_309b;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12458ULL: goto x86_l_30aa;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12479ULL: goto x86_l_30bf;
	case 12487ULL: goto x86_l_30c7;
	case 12490ULL: goto x86_l_30ca;
	case 12492ULL: goto x86_l_30cc;
	case 12497ULL: goto x86_l_30d1;
	case 12500ULL: goto x86_l_30d4;
	case 12502ULL: goto x86_l_30d6;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12527ULL: goto x86_l_30ef;
	case 12529ULL: goto x86_l_30f1;
	case 12535ULL: goto x86_l_30f7;
	case 12540ULL: goto x86_l_30fc;
	case 12542ULL: goto x86_l_30fe;
	case 12548ULL: goto x86_l_3104;
	case 12553ULL: goto x86_l_3109;
	case 12559ULL: goto x86_l_310f;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12569ULL: goto x86_l_3119;
	case 12572ULL: goto x86_l_311c;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12613ULL: goto x86_l_3145;
	case 12615ULL: goto x86_l_3147;
	case 12618ULL: goto x86_l_314a;
	case 12624ULL: goto x86_l_3150;
	case 12629ULL: goto x86_l_3155;
	case 12634ULL: goto x86_l_315a;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12654ULL: goto x86_l_316e;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12669ULL: goto x86_l_317d;
	case 12674ULL: goto x86_l_3182;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12762ULL: goto x86_l_31da;
	case 12766ULL: goto x86_l_31de;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12783ULL: goto x86_l_31ef;
	case 12791ULL: goto x86_l_31f7;
	case 12794ULL: goto x86_l_31fa;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b59:
	/* 0x2b59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b5e:
	/* 0x2b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b60:
	/* 0x2b60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b65:
	/* 0x2b65: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6a:
	/* 0x2b6a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b74:
	/* 0x2b74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b76:
	/* 0x2b76: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b7b:
	/* 0x2b7b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b84:
	/* 0x2b84: jmp    2bc7 <vfs_writev_magic_return+0x2bc7> */
	goto x86_l_2bc7;
x86_l_2b86:
	/* 0x2b86: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b8b:
	/* 0x2b8b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b91:
	/* 0x2b91: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b94:
	/* 0x2b94: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b99:
	/* 0x2b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9b:
	/* 0x2b9b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b9e:
	/* 0x2b9e: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_2ba4:
	/* 0x2ba4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba9:
	/* 0x2ba9: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2bac:
	/* 0x2bac: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2bb8:
	/* 0x2bb8: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bba:
	/* 0x2bba: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bbf:
	/* 0x2bbf: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bcc:
	/* 0x2bcc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bdb:
	/* 0x2bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdd:
	/* 0x2bdd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2be2:
	/* 0x2be2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2bea:
	/* 0x2bea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bee:
	/* 0x2bee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf3:
	/* 0x2bf3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bf8:
	/* 0x2bf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bfd:
	/* 0x2bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bff:
	/* 0x2bff: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c07:
	/* 0x2c07: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c0a:
	/* 0x2c0a: je     2c87 <vfs_writev_magic_return+0x2c87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c87;
	}
x86_l_2c0c:
	/* 0x2c0c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c11:
	/* 0x2c11: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c14:
	/* 0x2c14: je     2c87 <vfs_writev_magic_return+0x2c87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c87;
	}
x86_l_2c16:
	/* 0x2c16: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c1f:
	/* 0x2c1f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c24:
	/* 0x2c24: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c29:
	/* 0x2c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2b:
	/* 0x2c2b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2c2f:
	/* 0x2c2f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c31:
	/* 0x2c31: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c37:
	/* 0x2c37: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3c:
	/* 0x2c3c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c3e:
	/* 0x2c3e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_2c44:
	/* 0x2c44: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c49:
	/* 0x2c49: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c4f:
	/* 0x2c4f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c52:
	/* 0x2c52: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c57:
	/* 0x2c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c59:
	/* 0x2c59: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c5c:
	/* 0x2c5c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_2c62:
	/* 0x2c62: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c67:
	/* 0x2c67: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c6a:
	/* 0x2c6a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c70:
	/* 0x2c70: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c76:
	/* 0x2c76: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c78:
	/* 0x2c78: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c85:
	/* 0x2c85: jmp    2cf7 <vfs_writev_magic_return+0x2cf7> */
	goto x86_l_2cf7;
x86_l_2c87:
	/* 0x2c87: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c8a:
	/* 0x2c8a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_2c90:
	/* 0x2c90: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c95:
	/* 0x2c95: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2c9a:
	/* 0x2c9a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_2ca0:
	/* 0x2ca0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2caa:
	/* 0x2caa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cae:
	/* 0x2cae: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cbb:
	/* 0x2cbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbd:
	/* 0x2cbd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc7:
	/* 0x2cc7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cd1:
	/* 0x2cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd3:
	/* 0x2cd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cdd:
	/* 0x2cdd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ce2:
	/* 0x2ce2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ce7:
	/* 0x2ce7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce9:
	/* 0x2ce9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cee:
	/* 0x2cee: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cf2:
	/* 0x2cf2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cfc:
	/* 0x2cfc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d01:
	/* 0x2d01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d06:
	/* 0x2d06: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d0b:
	/* 0x2d0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0d:
	/* 0x2d0d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d12:
	/* 0x2d12: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d1a:
	/* 0x2d1a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d1e:
	/* 0x2d1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d23:
	/* 0x2d23: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d28:
	/* 0x2d28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2d:
	/* 0x2d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2f:
	/* 0x2d2f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d37:
	/* 0x2d37: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d3a:
	/* 0x2d3a: je     2db7 <vfs_writev_magic_return+0x2db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db7;
	}
x86_l_2d3c:
	/* 0x2d3c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d41:
	/* 0x2d41: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d44:
	/* 0x2d44: je     2db7 <vfs_writev_magic_return+0x2db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db7;
	}
x86_l_2d46:
	/* 0x2d46: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d4a:
	/* 0x2d4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d4f:
	/* 0x2d4f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d54:
	/* 0x2d54: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d59:
	/* 0x2d59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5b:
	/* 0x2d5b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2d5f:
	/* 0x2d5f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d61:
	/* 0x2d61: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d67:
	/* 0x2d67: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6c:
	/* 0x2d6c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d6e:
	/* 0x2d6e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_2d74:
	/* 0x2d74: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d79:
	/* 0x2d79: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d7f:
	/* 0x2d7f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d82:
	/* 0x2d82: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d87:
	/* 0x2d87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d89:
	/* 0x2d89: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d8c:
	/* 0x2d8c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_2d92:
	/* 0x2d92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d97:
	/* 0x2d97: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d9a:
	/* 0x2d9a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2da0:
	/* 0x2da0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2da6:
	/* 0x2da6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2da8:
	/* 0x2da8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dad:
	/* 0x2dad: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2db5:
	/* 0x2db5: jmp    2e27 <vfs_writev_magic_return+0x2e27> */
	goto x86_l_2e27;
x86_l_2db7:
	/* 0x2db7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dba:
	/* 0x2dba: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_2dc0:
	/* 0x2dc0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc5:
	/* 0x2dc5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2dca:
	/* 0x2dca: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_2dd0:
	/* 0x2dd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dda:
	/* 0x2dda: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2dde:
	/* 0x2dde: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2de6:
	/* 0x2de6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2deb:
	/* 0x2deb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ded:
	/* 0x2ded: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2df2:
	/* 0x2df2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df7:
	/* 0x2df7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e01:
	/* 0x2e01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e03:
	/* 0x2e03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e08:
	/* 0x2e08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e0d:
	/* 0x2e0d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e12:
	/* 0x2e12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e17:
	/* 0x2e17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e19:
	/* 0x2e19: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e1e:
	/* 0x2e1e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e22:
	/* 0x2e22: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e27:
	/* 0x2e27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e2c:
	/* 0x2e2c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e31:
	/* 0x2e31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e36:
	/* 0x2e36: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e3b:
	/* 0x2e3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e3d:
	/* 0x2e3d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e42:
	/* 0x2e42: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e4a:
	/* 0x2e4a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e4e:
	/* 0x2e4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e53:
	/* 0x2e53: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e58:
	/* 0x2e58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e5d:
	/* 0x2e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5f:
	/* 0x2e5f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e67:
	/* 0x2e67: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e6a:
	/* 0x2e6a: je     2ee7 <vfs_writev_magic_return+0x2ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee7;
	}
x86_l_2e6c:
	/* 0x2e6c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e71:
	/* 0x2e71: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e74:
	/* 0x2e74: je     2ee7 <vfs_writev_magic_return+0x2ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee7;
	}
x86_l_2e76:
	/* 0x2e76: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e7a:
	/* 0x2e7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e7f:
	/* 0x2e7f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e84:
	/* 0x2e84: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e89:
	/* 0x2e89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8b:
	/* 0x2e8b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2e8f:
	/* 0x2e8f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e91:
	/* 0x2e91: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e97:
	/* 0x2e97: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9c:
	/* 0x2e9c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e9e:
	/* 0x2e9e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_2ea4:
	/* 0x2ea4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ea9:
	/* 0x2ea9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2eaf:
	/* 0x2eaf: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2eb2:
	/* 0x2eb2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2eb7:
	/* 0x2eb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb9:
	/* 0x2eb9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ebc:
	/* 0x2ebc: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_2ec2:
	/* 0x2ec2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ec7:
	/* 0x2ec7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2eca:
	/* 0x2eca: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ed6:
	/* 0x2ed6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ed8:
	/* 0x2ed8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2edd:
	/* 0x2edd: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ee5:
	/* 0x2ee5: jmp    2f57 <vfs_writev_magic_return+0x2f57> */
	goto x86_l_2f57;
x86_l_2ee7:
	/* 0x2ee7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2eea:
	/* 0x2eea: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_2ef0:
	/* 0x2ef0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef5:
	/* 0x2ef5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2efa:
	/* 0x2efa: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_2f00:
	/* 0x2f00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f05:
	/* 0x2f05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f0a:
	/* 0x2f0a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f0e:
	/* 0x2f0e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1b:
	/* 0x2f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1d:
	/* 0x2f1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f22:
	/* 0x2f22: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f27:
	/* 0x2f27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f2c:
	/* 0x2f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f31:
	/* 0x2f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f33:
	/* 0x2f33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f38:
	/* 0x2f38: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3d:
	/* 0x2f3d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f42:
	/* 0x2f42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f47:
	/* 0x2f47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f49:
	/* 0x2f49: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4e:
	/* 0x2f4e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f52:
	/* 0x2f52: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f57:
	/* 0x2f57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f5c:
	/* 0x2f5c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f61:
	/* 0x2f61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f66:
	/* 0x2f66: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f6b:
	/* 0x2f6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f6d:
	/* 0x2f6d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f72:
	/* 0x2f72: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f7a:
	/* 0x2f7a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f83:
	/* 0x2f83: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f88:
	/* 0x2f88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8d:
	/* 0x2f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8f:
	/* 0x2f8f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f97:
	/* 0x2f97: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f9a:
	/* 0x2f9a: je     3017 <vfs_writev_magic_return+0x3017> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3017;
	}
x86_l_2f9c:
	/* 0x2f9c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fa1:
	/* 0x2fa1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2fa4:
	/* 0x2fa4: je     3017 <vfs_writev_magic_return+0x3017> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3017;
	}
x86_l_2fa6:
	/* 0x2fa6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2faa:
	/* 0x2faa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2faf:
	/* 0x2faf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fb4:
	/* 0x2fb4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2fb9:
	/* 0x2fb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbb:
	/* 0x2fbb: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2fbf:
	/* 0x2fbf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fc1:
	/* 0x2fc1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fc7:
	/* 0x2fc7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fcc:
	/* 0x2fcc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fce:
	/* 0x2fce: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_2fd4:
	/* 0x2fd4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fd9:
	/* 0x2fd9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2fdf:
	/* 0x2fdf: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fe2:
	/* 0x2fe2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2fe7:
	/* 0x2fe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe9:
	/* 0x2fe9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fec:
	/* 0x2fec: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_2ff2:
	/* 0x2ff2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff7:
	/* 0x2ff7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2ffa:
	/* 0x2ffa: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3000:
	/* 0x3000: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3006:
	/* 0x3006: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3008:
	/* 0x3008: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300d:
	/* 0x300d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3015:
	/* 0x3015: jmp    3087 <vfs_writev_magic_return+0x3087> */
	goto x86_l_3087;
x86_l_3017:
	/* 0x3017: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_301a:
	/* 0x301a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3020:
	/* 0x3020: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3025:
	/* 0x3025: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_302a:
	/* 0x302a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3030:
	/* 0x3030: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3035:
	/* 0x3035: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303a:
	/* 0x303a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_303e:
	/* 0x303e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3046:
	/* 0x3046: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_304b:
	/* 0x304b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_304d:
	/* 0x304d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3052:
	/* 0x3052: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3057:
	/* 0x3057: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_305c:
	/* 0x305c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3061:
	/* 0x3061: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3063:
	/* 0x3063: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3068:
	/* 0x3068: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306d:
	/* 0x306d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3072:
	/* 0x3072: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3077:
	/* 0x3077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3079:
	/* 0x3079: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_307e:
	/* 0x307e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3082:
	/* 0x3082: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3087:
	/* 0x3087: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_308c:
	/* 0x308c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3091:
	/* 0x3091: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3096:
	/* 0x3096: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_309b:
	/* 0x309b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309d:
	/* 0x309d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30a2:
	/* 0x30a2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30aa:
	/* 0x30aa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30ae:
	/* 0x30ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30b3:
	/* 0x30b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30b8:
	/* 0x30b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30bd:
	/* 0x30bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30bf:
	/* 0x30bf: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30c7:
	/* 0x30c7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_30ca:
	/* 0x30ca: je     3147 <vfs_writev_magic_return+0x3147> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3147;
	}
x86_l_30cc:
	/* 0x30cc: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30d1:
	/* 0x30d1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30d4:
	/* 0x30d4: je     3147 <vfs_writev_magic_return+0x3147> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3147;
	}
x86_l_30d6:
	/* 0x30d6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30da:
	/* 0x30da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30df:
	/* 0x30df: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30e4:
	/* 0x30e4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30e9:
	/* 0x30e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30eb:
	/* 0x30eb: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_30ef:
	/* 0x30ef: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30f1:
	/* 0x30f1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30f7:
	/* 0x30f7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fc:
	/* 0x30fc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30fe:
	/* 0x30fe: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3104:
	/* 0x3104: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3109:
	/* 0x3109: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_310f:
	/* 0x310f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3112:
	/* 0x3112: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3117:
	/* 0x3117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3119:
	/* 0x3119: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_311c:
	/* 0x311c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3122:
	/* 0x3122: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3127:
	/* 0x3127: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_312a:
	/* 0x312a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3130:
	/* 0x3130: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3136:
	/* 0x3136: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3138:
	/* 0x3138: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_313d:
	/* 0x313d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3145:
	/* 0x3145: jmp    31b7 <vfs_writev_magic_return+0x31b7> */
	goto x86_l_31b7;
x86_l_3147:
	/* 0x3147: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_314a:
	/* 0x314a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3150:
	/* 0x3150: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3155:
	/* 0x3155: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_315a:
	/* 0x315a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3160:
	/* 0x3160: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3165:
	/* 0x3165: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316a:
	/* 0x316a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_316e:
	/* 0x316e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3176:
	/* 0x3176: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_317b:
	/* 0x317b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317d:
	/* 0x317d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3182:
	/* 0x3182: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3187:
	/* 0x3187: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_318c:
	/* 0x318c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3191:
	/* 0x3191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3193:
	/* 0x3193: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3198:
	/* 0x3198: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_319d:
	/* 0x319d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31a2:
	/* 0x31a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31a7:
	/* 0x31a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a9:
	/* 0x31a9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ae:
	/* 0x31ae: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31b2:
	/* 0x31b2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31b7:
	/* 0x31b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31bc:
	/* 0x31bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31c1:
	/* 0x31c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c6:
	/* 0x31c6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31cb:
	/* 0x31cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cd:
	/* 0x31cd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31d2:
	/* 0x31d2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31da:
	/* 0x31da: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31de:
	/* 0x31de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31e3:
	/* 0x31e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31e8:
	/* 0x31e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ed:
	/* 0x31ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ef:
	/* 0x31ef: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31f7:
	/* 0x31f7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31fa:
	/* 0x31fa: je     3277 <vfs_writev_magic_return+0x3277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12919ULL;
	}
x86_l_31fc:
	/* 0x31fc: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3201:
	/* 0x3201: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3204:
	/* 0x3204: je     3277 <vfs_writev_magic_return+0x3277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12919ULL;
	}
x86_l_3206:
	/* 0x3206: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
	return 12810ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12810ULL: goto x86_l_320a;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12831ULL: goto x86_l_321f;
	case 12833ULL: goto x86_l_3221;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12846ULL: goto x86_l_322e;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12876ULL: goto x86_l_324c;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12890ULL: goto x86_l_325a;
	case 12896ULL: goto x86_l_3260;
	case 12902ULL: goto x86_l_3266;
	case 12904ULL: goto x86_l_3268;
	case 12909ULL: goto x86_l_326d;
	case 12917ULL: goto x86_l_3275;
	case 12919ULL: goto x86_l_3277;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12954ULL: goto x86_l_329a;
	case 12958ULL: goto x86_l_329e;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13015ULL: goto x86_l_32d7;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13066ULL: goto x86_l_330a;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13095ULL: goto x86_l_3327;
	case 13098ULL: goto x86_l_332a;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13108ULL: goto x86_l_3334;
	case 13110ULL: goto x86_l_3336;
	case 13114ULL: goto x86_l_333a;
	case 13119ULL: goto x86_l_333f;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13131ULL: goto x86_l_334b;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13150ULL: goto x86_l_335e;
	case 13156ULL: goto x86_l_3364;
	case 13161ULL: goto x86_l_3369;
	case 13167ULL: goto x86_l_336f;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13180ULL: goto x86_l_337c;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13194ULL: goto x86_l_338a;
	case 13200ULL: goto x86_l_3390;
	case 13206ULL: goto x86_l_3396;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13221ULL: goto x86_l_33a5;
	case 13223ULL: goto x86_l_33a7;
	case 13226ULL: goto x86_l_33aa;
	case 13232ULL: goto x86_l_33b0;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13258ULL: goto x86_l_33ca;
	case 13262ULL: goto x86_l_33ce;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13297ULL: goto x86_l_33f1;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13319ULL: goto x86_l_3407;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13370ULL: goto x86_l_343a;
	case 13374ULL: goto x86_l_343e;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13389ULL: goto x86_l_344d;
	case 13391ULL: goto x86_l_344f;
	case 13399ULL: goto x86_l_3457;
	case 13402ULL: goto x86_l_345a;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13412ULL: goto x86_l_3464;
	case 13414ULL: goto x86_l_3466;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13433ULL: goto x86_l_3479;
	case 13435ULL: goto x86_l_347b;
	case 13439ULL: goto x86_l_347f;
	case 13441ULL: goto x86_l_3481;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13454ULL: goto x86_l_348e;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13481ULL: goto x86_l_34a9;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13498ULL: goto x86_l_34ba;
	case 13504ULL: goto x86_l_34c0;
	case 13510ULL: goto x86_l_34c6;
	case 13512ULL: goto x86_l_34c8;
	case 13517ULL: goto x86_l_34cd;
	case 13525ULL: goto x86_l_34d5;
	case 13527ULL: goto x86_l_34d7;
	case 13530ULL: goto x86_l_34da;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13546ULL: goto x86_l_34ea;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13562ULL: goto x86_l_34fa;
	case 13566ULL: goto x86_l_34fe;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13581ULL: goto x86_l_350d;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13603ULL: goto x86_l_3523;
	case 13608ULL: goto x86_l_3528;
	case 13613ULL: goto x86_l_352d;
	case 13618ULL: goto x86_l_3532;
	case 13623ULL: goto x86_l_3537;
	case 13625ULL: goto x86_l_3539;
	case 13630ULL: goto x86_l_353e;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13649ULL: goto x86_l_3551;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13661ULL: goto x86_l_355d;
	case 13666ULL: goto x86_l_3562;
	case 13674ULL: goto x86_l_356a;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13688ULL: goto x86_l_3578;
	case 13693ULL: goto x86_l_357d;
	case 13695ULL: goto x86_l_357f;
	case 13703ULL: goto x86_l_3587;
	case 13706ULL: goto x86_l_358a;
	case 13708ULL: goto x86_l_358c;
	case 13713ULL: goto x86_l_3591;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13739ULL: goto x86_l_35ab;
	case 13743ULL: goto x86_l_35af;
	case 13745ULL: goto x86_l_35b1;
	case 13751ULL: goto x86_l_35b7;
	case 13756ULL: goto x86_l_35bc;
	case 13758ULL: goto x86_l_35be;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13775ULL: goto x86_l_35cf;
	case 13778ULL: goto x86_l_35d2;
	case 13783ULL: goto x86_l_35d7;
	case 13785ULL: goto x86_l_35d9;
	case 13788ULL: goto x86_l_35dc;
	case 13794ULL: goto x86_l_35e2;
	case 13799ULL: goto x86_l_35e7;
	case 13802ULL: goto x86_l_35ea;
	case 13808ULL: goto x86_l_35f0;
	case 13814ULL: goto x86_l_35f6;
	case 13816ULL: goto x86_l_35f8;
	case 13821ULL: goto x86_l_35fd;
	case 13829ULL: goto x86_l_3605;
	case 13831ULL: goto x86_l_3607;
	case 13834ULL: goto x86_l_360a;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13856ULL: goto x86_l_3620;
	case 13861ULL: goto x86_l_3625;
	case 13866ULL: goto x86_l_362a;
	case 13870ULL: goto x86_l_362e;
	case 13878ULL: goto x86_l_3636;
	case 13883ULL: goto x86_l_363b;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13905ULL: goto x86_l_3651;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13917ULL: goto x86_l_365d;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13929ULL: goto x86_l_3669;
	case 13934ULL: goto x86_l_366e;
	case 13938ULL: goto x86_l_3672;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13953ULL: goto x86_l_3681;
	case 13958ULL: goto x86_l_3686;
	case 13963ULL: goto x86_l_368b;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13978ULL: goto x86_l_369a;
	case 13982ULL: goto x86_l_369e;
	case 13987ULL: goto x86_l_36a3;
	case 13992ULL: goto x86_l_36a8;
	case 13997ULL: goto x86_l_36ad;
	case 13999ULL: goto x86_l_36af;
	case 14007ULL: goto x86_l_36b7;
	case 14010ULL: goto x86_l_36ba;
	case 14012ULL: goto x86_l_36bc;
	case 14017ULL: goto x86_l_36c1;
	case 14020ULL: goto x86_l_36c4;
	case 14022ULL: goto x86_l_36c6;
	case 14026ULL: goto x86_l_36ca;
	case 14031ULL: goto x86_l_36cf;
	case 14036ULL: goto x86_l_36d4;
	case 14041ULL: goto x86_l_36d9;
	case 14043ULL: goto x86_l_36db;
	case 14047ULL: goto x86_l_36df;
	case 14049ULL: goto x86_l_36e1;
	case 14055ULL: goto x86_l_36e7;
	case 14060ULL: goto x86_l_36ec;
	case 14062ULL: goto x86_l_36ee;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14079ULL: goto x86_l_36ff;
	case 14082ULL: goto x86_l_3702;
	case 14087ULL: goto x86_l_3707;
	case 14089ULL: goto x86_l_3709;
	case 14092ULL: goto x86_l_370c;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14106ULL: goto x86_l_371a;
	case 14112ULL: goto x86_l_3720;
	case 14118ULL: goto x86_l_3726;
	case 14120ULL: goto x86_l_3728;
	case 14125ULL: goto x86_l_372d;
	case 14133ULL: goto x86_l_3735;
	case 14135ULL: goto x86_l_3737;
	case 14138ULL: goto x86_l_373a;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14160ULL: goto x86_l_3750;
	case 14165ULL: goto x86_l_3755;
	case 14170ULL: goto x86_l_375a;
	case 14174ULL: goto x86_l_375e;
	case 14182ULL: goto x86_l_3766;
	case 14187ULL: goto x86_l_376b;
	case 14189ULL: goto x86_l_376d;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14204ULL: goto x86_l_377c;
	case 14209ULL: goto x86_l_3781;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14231ULL: goto x86_l_3797;
	case 14233ULL: goto x86_l_3799;
	case 14238ULL: goto x86_l_379e;
	case 14242ULL: goto x86_l_37a2;
	case 14247ULL: goto x86_l_37a7;
	case 14252ULL: goto x86_l_37ac;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14269ULL: goto x86_l_37bd;
	case 14274ULL: goto x86_l_37c2;
	case 14282ULL: goto x86_l_37ca;
	case 14286ULL: goto x86_l_37ce;
	case 14291ULL: goto x86_l_37d3;
	case 14296ULL: goto x86_l_37d8;
	case 14301ULL: goto x86_l_37dd;
	case 14303ULL: goto x86_l_37df;
	case 14311ULL: goto x86_l_37e7;
	case 14314ULL: goto x86_l_37ea;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14324ULL: goto x86_l_37f4;
	case 14326ULL: goto x86_l_37f6;
	case 14330ULL: goto x86_l_37fa;
	case 14335ULL: goto x86_l_37ff;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14347ULL: goto x86_l_380b;
	case 14351ULL: goto x86_l_380f;
	case 14353ULL: goto x86_l_3811;
	case 14359ULL: goto x86_l_3817;
	case 14364ULL: goto x86_l_381c;
	case 14366ULL: goto x86_l_381e;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14383ULL: goto x86_l_382f;
	case 14386ULL: goto x86_l_3832;
	case 14391ULL: goto x86_l_3837;
	case 14393ULL: goto x86_l_3839;
	case 14396ULL: goto x86_l_383c;
	case 14402ULL: goto x86_l_3842;
	case 14407ULL: goto x86_l_3847;
	case 14410ULL: goto x86_l_384a;
	case 14416ULL: goto x86_l_3850;
	case 14422ULL: goto x86_l_3856;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14437ULL: goto x86_l_3865;
	case 14439ULL: goto x86_l_3867;
	case 14442ULL: goto x86_l_386a;
	case 14448ULL: goto x86_l_3870;
	case 14453ULL: goto x86_l_3875;
	case 14458ULL: goto x86_l_387a;
	case 14464ULL: goto x86_l_3880;
	case 14469ULL: goto x86_l_3885;
	case 14474ULL: goto x86_l_388a;
	case 14478ULL: goto x86_l_388e;
	case 14486ULL: goto x86_l_3896;
	case 14491ULL: goto x86_l_389b;
	case 14493ULL: goto x86_l_389d;
	case 14498ULL: goto x86_l_38a2;
	case 14503ULL: goto x86_l_38a7;
	case 14508ULL: goto x86_l_38ac;
	case 14513ULL: goto x86_l_38b1;
	case 14515ULL: goto x86_l_38b3;
	case 14520ULL: goto x86_l_38b8;
	case 14525ULL: goto x86_l_38bd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_320a:
	/* 0x320a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_320f:
	/* 0x320f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3214:
	/* 0x3214: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3219:
	/* 0x3219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321b:
	/* 0x321b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_321f:
	/* 0x321f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3221:
	/* 0x3221: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3227:
	/* 0x3227: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_322c:
	/* 0x322c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_322e:
	/* 0x322e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3234:
	/* 0x3234: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3239:
	/* 0x3239: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_323f:
	/* 0x323f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3242:
	/* 0x3242: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3247:
	/* 0x3247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3249:
	/* 0x3249: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_324c:
	/* 0x324c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3252:
	/* 0x3252: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3257:
	/* 0x3257: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_325a:
	/* 0x325a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3260:
	/* 0x3260: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3266:
	/* 0x3266: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3268:
	/* 0x3268: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_326d:
	/* 0x326d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3275:
	/* 0x3275: jmp    32e7 <vfs_writev_magic_return+0x32e7> */
	goto x86_l_32e7;
x86_l_3277:
	/* 0x3277: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_327a:
	/* 0x327a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3280:
	/* 0x3280: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3285:
	/* 0x3285: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_328a:
	/* 0x328a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3290:
	/* 0x3290: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3295:
	/* 0x3295: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329a:
	/* 0x329a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_329e:
	/* 0x329e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_32a6:
	/* 0x32a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ab:
	/* 0x32ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ad:
	/* 0x32ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32b2:
	/* 0x32b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32b7:
	/* 0x32b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32bc:
	/* 0x32bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c1:
	/* 0x32c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c3:
	/* 0x32c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32c8:
	/* 0x32c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32cd:
	/* 0x32cd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32d2:
	/* 0x32d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32d7:
	/* 0x32d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d9:
	/* 0x32d9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32de:
	/* 0x32de: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32e2:
	/* 0x32e2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32e7:
	/* 0x32e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32ec:
	/* 0x32ec: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32f1:
	/* 0x32f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f6:
	/* 0x32f6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32fb:
	/* 0x32fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fd:
	/* 0x32fd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3302:
	/* 0x3302: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_330a:
	/* 0x330a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_330e:
	/* 0x330e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3313:
	/* 0x3313: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3318:
	/* 0x3318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_331d:
	/* 0x331d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331f:
	/* 0x331f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3327:
	/* 0x3327: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_332a:
	/* 0x332a: je     33a7 <vfs_writev_magic_return+0x33a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a7;
	}
x86_l_332c:
	/* 0x332c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3331:
	/* 0x3331: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3334:
	/* 0x3334: je     33a7 <vfs_writev_magic_return+0x33a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a7;
	}
x86_l_3336:
	/* 0x3336: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_333a:
	/* 0x333a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_333f:
	/* 0x333f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3344:
	/* 0x3344: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3349:
	/* 0x3349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334b:
	/* 0x334b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_334f:
	/* 0x334f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3351:
	/* 0x3351: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3357:
	/* 0x3357: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_335c:
	/* 0x335c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_335e:
	/* 0x335e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3364:
	/* 0x3364: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3369:
	/* 0x3369: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_336f:
	/* 0x336f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3372:
	/* 0x3372: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3377:
	/* 0x3377: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3379:
	/* 0x3379: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_337c:
	/* 0x337c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3382:
	/* 0x3382: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3387:
	/* 0x3387: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_338a:
	/* 0x338a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3390:
	/* 0x3390: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3396:
	/* 0x3396: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3398:
	/* 0x3398: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_339d:
	/* 0x339d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_33a5:
	/* 0x33a5: jmp    3417 <vfs_writev_magic_return+0x3417> */
	goto x86_l_3417;
x86_l_33a7:
	/* 0x33a7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33aa:
	/* 0x33aa: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_33b0:
	/* 0x33b0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b5:
	/* 0x33b5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_33ba:
	/* 0x33ba: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_33c0:
	/* 0x33c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33c5:
	/* 0x33c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ca:
	/* 0x33ca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33ce:
	/* 0x33ce: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_33d6:
	/* 0x33d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33db:
	/* 0x33db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dd:
	/* 0x33dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33e2:
	/* 0x33e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e7:
	/* 0x33e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ec:
	/* 0x33ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f1:
	/* 0x33f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f3:
	/* 0x33f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33f8:
	/* 0x33f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33fd:
	/* 0x33fd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3402:
	/* 0x3402: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3407:
	/* 0x3407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3409:
	/* 0x3409: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_340e:
	/* 0x340e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3412:
	/* 0x3412: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3417:
	/* 0x3417: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_341c:
	/* 0x341c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3421:
	/* 0x3421: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3426:
	/* 0x3426: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_342b:
	/* 0x342b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342d:
	/* 0x342d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3432:
	/* 0x3432: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_343a:
	/* 0x343a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_343e:
	/* 0x343e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3443:
	/* 0x3443: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3448:
	/* 0x3448: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_344d:
	/* 0x344d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344f:
	/* 0x344f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3457:
	/* 0x3457: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_345a:
	/* 0x345a: je     34d7 <vfs_writev_magic_return+0x34d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d7;
	}
x86_l_345c:
	/* 0x345c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3461:
	/* 0x3461: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3464:
	/* 0x3464: je     34d7 <vfs_writev_magic_return+0x34d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d7;
	}
x86_l_3466:
	/* 0x3466: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_346a:
	/* 0x346a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_346f:
	/* 0x346f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3474:
	/* 0x3474: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3479:
	/* 0x3479: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347b:
	/* 0x347b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_347f:
	/* 0x347f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3481:
	/* 0x3481: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3487:
	/* 0x3487: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_348c:
	/* 0x348c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_348e:
	/* 0x348e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3494:
	/* 0x3494: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3499:
	/* 0x3499: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_349f:
	/* 0x349f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34a2:
	/* 0x34a2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_34a7:
	/* 0x34a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a9:
	/* 0x34a9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34ac:
	/* 0x34ac: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_34b2:
	/* 0x34b2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34b7:
	/* 0x34b7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_34ba:
	/* 0x34ba: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34c0:
	/* 0x34c0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34c6:
	/* 0x34c6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34c8:
	/* 0x34c8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34cd:
	/* 0x34cd: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_34d5:
	/* 0x34d5: jmp    3547 <vfs_writev_magic_return+0x3547> */
	goto x86_l_3547;
x86_l_34d7:
	/* 0x34d7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_34da:
	/* 0x34da: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_34e0:
	/* 0x34e0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e5:
	/* 0x34e5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_34ea:
	/* 0x34ea: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_34f0:
	/* 0x34f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34f5:
	/* 0x34f5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34fa:
	/* 0x34fa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34fe:
	/* 0x34fe: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3506:
	/* 0x3506: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_350b:
	/* 0x350b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350d:
	/* 0x350d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3512:
	/* 0x3512: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3517:
	/* 0x3517: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_351c:
	/* 0x351c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3521:
	/* 0x3521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3523:
	/* 0x3523: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3528:
	/* 0x3528: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352d:
	/* 0x352d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3532:
	/* 0x3532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3537:
	/* 0x3537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3539:
	/* 0x3539: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353e:
	/* 0x353e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3542:
	/* 0x3542: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3547:
	/* 0x3547: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_354c:
	/* 0x354c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3551:
	/* 0x3551: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3556:
	/* 0x3556: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_355b:
	/* 0x355b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355d:
	/* 0x355d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3562:
	/* 0x3562: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_356a:
	/* 0x356a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_356e:
	/* 0x356e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3573:
	/* 0x3573: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3578:
	/* 0x3578: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_357d:
	/* 0x357d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_357f:
	/* 0x357f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3587:
	/* 0x3587: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_358a:
	/* 0x358a: je     3607 <vfs_writev_magic_return+0x3607> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3607;
	}
x86_l_358c:
	/* 0x358c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3591:
	/* 0x3591: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3594:
	/* 0x3594: je     3607 <vfs_writev_magic_return+0x3607> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3607;
	}
x86_l_3596:
	/* 0x3596: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_359a:
	/* 0x359a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_359f:
	/* 0x359f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35a4:
	/* 0x35a4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_35a9:
	/* 0x35a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ab:
	/* 0x35ab: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_35af:
	/* 0x35af: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35b1:
	/* 0x35b1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35b7:
	/* 0x35b7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35bc:
	/* 0x35bc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35be:
	/* 0x35be: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_35c4:
	/* 0x35c4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35c9:
	/* 0x35c9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_35cf:
	/* 0x35cf: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35d2:
	/* 0x35d2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_35d7:
	/* 0x35d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d9:
	/* 0x35d9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35dc:
	/* 0x35dc: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_35e2:
	/* 0x35e2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35e7:
	/* 0x35e7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_35ea:
	/* 0x35ea: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_35f0:
	/* 0x35f0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_35f6:
	/* 0x35f6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35f8:
	/* 0x35f8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35fd:
	/* 0x35fd: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3605:
	/* 0x3605: jmp    3677 <vfs_writev_magic_return+0x3677> */
	goto x86_l_3677;
x86_l_3607:
	/* 0x3607: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_360a:
	/* 0x360a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3610:
	/* 0x3610: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3615:
	/* 0x3615: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_361a:
	/* 0x361a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3620:
	/* 0x3620: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3625:
	/* 0x3625: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_362a:
	/* 0x362a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_362e:
	/* 0x362e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3636:
	/* 0x3636: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_363b:
	/* 0x363b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363d:
	/* 0x363d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3642:
	/* 0x3642: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3647:
	/* 0x3647: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_364c:
	/* 0x364c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3651:
	/* 0x3651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3653:
	/* 0x3653: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3658:
	/* 0x3658: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_365d:
	/* 0x365d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3662:
	/* 0x3662: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3667:
	/* 0x3667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3669:
	/* 0x3669: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366e:
	/* 0x366e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3672:
	/* 0x3672: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3677:
	/* 0x3677: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_367c:
	/* 0x367c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3681:
	/* 0x3681: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3686:
	/* 0x3686: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_368b:
	/* 0x368b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368d:
	/* 0x368d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3692:
	/* 0x3692: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_369a:
	/* 0x369a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_369e:
	/* 0x369e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36a3:
	/* 0x36a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36a8:
	/* 0x36a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36ad:
	/* 0x36ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36af:
	/* 0x36af: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_36b7:
	/* 0x36b7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_36ba:
	/* 0x36ba: je     3737 <vfs_writev_magic_return+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3737;
	}
x86_l_36bc:
	/* 0x36bc: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36c1:
	/* 0x36c1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_36c4:
	/* 0x36c4: je     3737 <vfs_writev_magic_return+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3737;
	}
x86_l_36c6:
	/* 0x36c6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36ca:
	/* 0x36ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36cf:
	/* 0x36cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36d4:
	/* 0x36d4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_36d9:
	/* 0x36d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36db:
	/* 0x36db: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_36df:
	/* 0x36df: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_36e1:
	/* 0x36e1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_36e7:
	/* 0x36e7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36ec:
	/* 0x36ec: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36ee:
	/* 0x36ee: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_36f4:
	/* 0x36f4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36f9:
	/* 0x36f9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_36ff:
	/* 0x36ff: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3702:
	/* 0x3702: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3707:
	/* 0x3707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3709:
	/* 0x3709: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_370c:
	/* 0x370c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3712:
	/* 0x3712: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3717:
	/* 0x3717: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_371a:
	/* 0x371a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3720:
	/* 0x3720: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3726:
	/* 0x3726: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3728:
	/* 0x3728: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_372d:
	/* 0x372d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3735:
	/* 0x3735: jmp    37a7 <vfs_writev_magic_return+0x37a7> */
	goto x86_l_37a7;
x86_l_3737:
	/* 0x3737: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_373a:
	/* 0x373a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3740:
	/* 0x3740: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3745:
	/* 0x3745: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_374a:
	/* 0x374a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3750:
	/* 0x3750: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3755:
	/* 0x3755: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375a:
	/* 0x375a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_375e:
	/* 0x375e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3766:
	/* 0x3766: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_376b:
	/* 0x376b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376d:
	/* 0x376d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3772:
	/* 0x3772: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3777:
	/* 0x3777: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_377c:
	/* 0x377c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3781:
	/* 0x3781: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3783:
	/* 0x3783: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3788:
	/* 0x3788: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_378d:
	/* 0x378d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3792:
	/* 0x3792: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3797:
	/* 0x3797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3799:
	/* 0x3799: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_379e:
	/* 0x379e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37a2:
	/* 0x37a2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37a7:
	/* 0x37a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ac:
	/* 0x37ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37b1:
	/* 0x37b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b6:
	/* 0x37b6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37bb:
	/* 0x37bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37bd:
	/* 0x37bd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37c2:
	/* 0x37c2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_37ca:
	/* 0x37ca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37ce:
	/* 0x37ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37d3:
	/* 0x37d3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37d8:
	/* 0x37d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37dd:
	/* 0x37dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37df:
	/* 0x37df: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_37e7:
	/* 0x37e7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_37ea:
	/* 0x37ea: je     3867 <vfs_writev_magic_return+0x3867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3867;
	}
x86_l_37ec:
	/* 0x37ec: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37f1:
	/* 0x37f1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_37f4:
	/* 0x37f4: je     3867 <vfs_writev_magic_return+0x3867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3867;
	}
x86_l_37f6:
	/* 0x37f6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37fa:
	/* 0x37fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ff:
	/* 0x37ff: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3804:
	/* 0x3804: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3809:
	/* 0x3809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380b:
	/* 0x380b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_380f:
	/* 0x380f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3811:
	/* 0x3811: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3817:
	/* 0x3817: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_381c:
	/* 0x381c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_381e:
	/* 0x381e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3824:
	/* 0x3824: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3829:
	/* 0x3829: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_382f:
	/* 0x382f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3832:
	/* 0x3832: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3837:
	/* 0x3837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3839:
	/* 0x3839: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_383c:
	/* 0x383c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3842:
	/* 0x3842: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3847:
	/* 0x3847: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_384a:
	/* 0x384a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3850:
	/* 0x3850: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3856:
	/* 0x3856: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3858:
	/* 0x3858: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_385d:
	/* 0x385d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3865:
	/* 0x3865: jmp    38d7 <vfs_writev_magic_return+0x38d7> */
	return 14551ULL;
x86_l_3867:
	/* 0x3867: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_386a:
	/* 0x386a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3870:
	/* 0x3870: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3875:
	/* 0x3875: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_387a:
	/* 0x387a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3880:
	/* 0x3880: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3885:
	/* 0x3885: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388a:
	/* 0x388a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_388e:
	/* 0x388e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3896:
	/* 0x3896: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389b:
	/* 0x389b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389d:
	/* 0x389d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38a2:
	/* 0x38a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38a7:
	/* 0x38a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ac:
	/* 0x38ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38b1:
	/* 0x38b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b3:
	/* 0x38b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38b8:
	/* 0x38b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38bd:
	/* 0x38bd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 14530ULL;
}

static __noinline __u64 tracee_vfs_writev_magic_return_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14530ULL: goto x86_l_38c2;
	case 14535ULL: goto x86_l_38c7;
	case 14537ULL: goto x86_l_38c9;
	case 14542ULL: goto x86_l_38ce;
	case 14546ULL: goto x86_l_38d2;
	case 14551ULL: goto x86_l_38d7;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14566ULL: goto x86_l_38e6;
	case 14571ULL: goto x86_l_38eb;
	case 14573ULL: goto x86_l_38ed;
	case 14578ULL: goto x86_l_38f2;
	case 14586ULL: goto x86_l_38fa;
	case 14590ULL: goto x86_l_38fe;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14607ULL: goto x86_l_390f;
	case 14615ULL: goto x86_l_3917;
	case 14618ULL: goto x86_l_391a;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14628ULL: goto x86_l_3924;
	case 14630ULL: goto x86_l_3926;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14644ULL: goto x86_l_3934;
	case 14649ULL: goto x86_l_3939;
	case 14651ULL: goto x86_l_393b;
	case 14655ULL: goto x86_l_393f;
	case 14657ULL: goto x86_l_3941;
	case 14663ULL: goto x86_l_3947;
	case 14668ULL: goto x86_l_394c;
	case 14670ULL: goto x86_l_394e;
	case 14676ULL: goto x86_l_3954;
	case 14681ULL: goto x86_l_3959;
	case 14687ULL: goto x86_l_395f;
	case 14690ULL: goto x86_l_3962;
	case 14695ULL: goto x86_l_3967;
	case 14697ULL: goto x86_l_3969;
	case 14700ULL: goto x86_l_396c;
	case 14706ULL: goto x86_l_3972;
	case 14711ULL: goto x86_l_3977;
	case 14714ULL: goto x86_l_397a;
	case 14720ULL: goto x86_l_3980;
	case 14726ULL: goto x86_l_3986;
	case 14728ULL: goto x86_l_3988;
	case 14733ULL: goto x86_l_398d;
	case 14741ULL: goto x86_l_3995;
	case 14743ULL: goto x86_l_3997;
	case 14746ULL: goto x86_l_399a;
	case 14752ULL: goto x86_l_39a0;
	case 14757ULL: goto x86_l_39a5;
	case 14762ULL: goto x86_l_39aa;
	case 14768ULL: goto x86_l_39b0;
	case 14773ULL: goto x86_l_39b5;
	case 14778ULL: goto x86_l_39ba;
	case 14782ULL: goto x86_l_39be;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14797ULL: goto x86_l_39cd;
	case 14802ULL: goto x86_l_39d2;
	case 14807ULL: goto x86_l_39d7;
	case 14812ULL: goto x86_l_39dc;
	case 14817ULL: goto x86_l_39e1;
	case 14819ULL: goto x86_l_39e3;
	case 14824ULL: goto x86_l_39e8;
	case 14829ULL: goto x86_l_39ed;
	case 14834ULL: goto x86_l_39f2;
	case 14839ULL: goto x86_l_39f7;
	case 14841ULL: goto x86_l_39f9;
	case 14846ULL: goto x86_l_39fe;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14865ULL: goto x86_l_3a11;
	case 14870ULL: goto x86_l_3a16;
	case 14875ULL: goto x86_l_3a1b;
	case 14877ULL: goto x86_l_3a1d;
	case 14882ULL: goto x86_l_3a22;
	case 14890ULL: goto x86_l_3a2a;
	case 14894ULL: goto x86_l_3a2e;
	case 14899ULL: goto x86_l_3a33;
	case 14904ULL: goto x86_l_3a38;
	case 14909ULL: goto x86_l_3a3d;
	case 14911ULL: goto x86_l_3a3f;
	case 14919ULL: goto x86_l_3a47;
	case 14922ULL: goto x86_l_3a4a;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14932ULL: goto x86_l_3a54;
	case 14934ULL: goto x86_l_3a56;
	case 14938ULL: goto x86_l_3a5a;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14953ULL: goto x86_l_3a69;
	case 14955ULL: goto x86_l_3a6b;
	case 14959ULL: goto x86_l_3a6f;
	case 14961ULL: goto x86_l_3a71;
	case 14967ULL: goto x86_l_3a77;
	case 14972ULL: goto x86_l_3a7c;
	case 14974ULL: goto x86_l_3a7e;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14991ULL: goto x86_l_3a8f;
	case 14994ULL: goto x86_l_3a92;
	case 14999ULL: goto x86_l_3a97;
	case 15001ULL: goto x86_l_3a99;
	case 15004ULL: goto x86_l_3a9c;
	case 15010ULL: goto x86_l_3aa2;
	case 15015ULL: goto x86_l_3aa7;
	case 15018ULL: goto x86_l_3aaa;
	case 15024ULL: goto x86_l_3ab0;
	case 15030ULL: goto x86_l_3ab6;
	case 15032ULL: goto x86_l_3ab8;
	case 15037ULL: goto x86_l_3abd;
	case 15045ULL: goto x86_l_3ac5;
	case 15047ULL: goto x86_l_3ac7;
	case 15050ULL: goto x86_l_3aca;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15066ULL: goto x86_l_3ada;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15082ULL: goto x86_l_3aea;
	case 15086ULL: goto x86_l_3aee;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15101ULL: goto x86_l_3afd;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15116ULL: goto x86_l_3b0c;
	case 15121ULL: goto x86_l_3b11;
	case 15123ULL: goto x86_l_3b13;
	case 15128ULL: goto x86_l_3b18;
	case 15133ULL: goto x86_l_3b1d;
	case 15138ULL: goto x86_l_3b22;
	case 15143ULL: goto x86_l_3b27;
	case 15145ULL: goto x86_l_3b29;
	case 15150ULL: goto x86_l_3b2e;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15164ULL: goto x86_l_3b3c;
	case 15169ULL: goto x86_l_3b41;
	case 15174ULL: goto x86_l_3b46;
	case 15179ULL: goto x86_l_3b4b;
	case 15181ULL: goto x86_l_3b4d;
	case 15186ULL: goto x86_l_3b52;
	case 15194ULL: goto x86_l_3b5a;
	case 15198ULL: goto x86_l_3b5e;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15213ULL: goto x86_l_3b6d;
	case 15215ULL: goto x86_l_3b6f;
	case 15223ULL: goto x86_l_3b77;
	case 15226ULL: goto x86_l_3b7a;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15236ULL: goto x86_l_3b84;
	case 15238ULL: goto x86_l_3b86;
	case 15242ULL: goto x86_l_3b8a;
	case 15247ULL: goto x86_l_3b8f;
	case 15252ULL: goto x86_l_3b94;
	case 15257ULL: goto x86_l_3b99;
	case 15259ULL: goto x86_l_3b9b;
	case 15263ULL: goto x86_l_3b9f;
	case 15265ULL: goto x86_l_3ba1;
	case 15271ULL: goto x86_l_3ba7;
	case 15276ULL: goto x86_l_3bac;
	case 15278ULL: goto x86_l_3bae;
	case 15284ULL: goto x86_l_3bb4;
	case 15289ULL: goto x86_l_3bb9;
	case 15295ULL: goto x86_l_3bbf;
	case 15298ULL: goto x86_l_3bc2;
	case 15303ULL: goto x86_l_3bc7;
	case 15305ULL: goto x86_l_3bc9;
	case 15308ULL: goto x86_l_3bcc;
	case 15314ULL: goto x86_l_3bd2;
	case 15319ULL: goto x86_l_3bd7;
	case 15322ULL: goto x86_l_3bda;
	case 15328ULL: goto x86_l_3be0;
	case 15334ULL: goto x86_l_3be6;
	case 15336ULL: goto x86_l_3be8;
	case 15341ULL: goto x86_l_3bed;
	case 15349ULL: goto x86_l_3bf5;
	case 15351ULL: goto x86_l_3bf7;
	case 15354ULL: goto x86_l_3bfa;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15370ULL: goto x86_l_3c0a;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15390ULL: goto x86_l_3c1e;
	case 15398ULL: goto x86_l_3c26;
	case 15403ULL: goto x86_l_3c2b;
	case 15405ULL: goto x86_l_3c2d;
	case 15410ULL: goto x86_l_3c32;
	case 15415ULL: goto x86_l_3c37;
	case 15420ULL: goto x86_l_3c3c;
	case 15425ULL: goto x86_l_3c41;
	case 15427ULL: goto x86_l_3c43;
	case 15432ULL: goto x86_l_3c48;
	case 15437ULL: goto x86_l_3c4d;
	case 15442ULL: goto x86_l_3c52;
	case 15447ULL: goto x86_l_3c57;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15458ULL: goto x86_l_3c62;
	case 15463ULL: goto x86_l_3c67;
	case 15468ULL: goto x86_l_3c6c;
	case 15473ULL: goto x86_l_3c71;
	case 15478ULL: goto x86_l_3c76;
	case 15483ULL: goto x86_l_3c7b;
	case 15485ULL: goto x86_l_3c7d;
	case 15490ULL: goto x86_l_3c82;
	case 15498ULL: goto x86_l_3c8a;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15512ULL: goto x86_l_3c98;
	case 15517ULL: goto x86_l_3c9d;
	case 15519ULL: goto x86_l_3c9f;
	case 15527ULL: goto x86_l_3ca7;
	case 15530ULL: goto x86_l_3caa;
	case 15536ULL: goto x86_l_3cb0;
	case 15541ULL: goto x86_l_3cb5;
	case 15544ULL: goto x86_l_3cb8;
	case 15550ULL: goto x86_l_3cbe;
	case 15554ULL: goto x86_l_3cc2;
	case 15559ULL: goto x86_l_3cc7;
	case 15564ULL: goto x86_l_3ccc;
	case 15569ULL: goto x86_l_3cd1;
	case 15571ULL: goto x86_l_3cd3;
	case 15575ULL: goto x86_l_3cd7;
	case 15577ULL: goto x86_l_3cd9;
	case 15583ULL: goto x86_l_3cdf;
	case 15588ULL: goto x86_l_3ce4;
	case 15590ULL: goto x86_l_3ce6;
	case 15596ULL: goto x86_l_3cec;
	case 15601ULL: goto x86_l_3cf1;
	case 15607ULL: goto x86_l_3cf7;
	case 15610ULL: goto x86_l_3cfa;
	case 15615ULL: goto x86_l_3cff;
	case 15617ULL: goto x86_l_3d01;
	case 15620ULL: goto x86_l_3d04;
	case 15626ULL: goto x86_l_3d0a;
	case 15631ULL: goto x86_l_3d0f;
	case 15634ULL: goto x86_l_3d12;
	case 15640ULL: goto x86_l_3d18;
	case 15646ULL: goto x86_l_3d1e;
	case 15648ULL: goto x86_l_3d20;
	case 15656ULL: goto x86_l_3d28;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15670ULL: goto x86_l_3d36;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15684ULL: goto x86_l_3d44;
	case 15690ULL: goto x86_l_3d4a;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15706ULL: goto x86_l_3d5a;
	case 15711ULL: goto x86_l_3d5f;
	case 15716ULL: goto x86_l_3d64;
	case 15720ULL: goto x86_l_3d68;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15735ULL: goto x86_l_3d77;
	case 15740ULL: goto x86_l_3d7c;
	case 15745ULL: goto x86_l_3d81;
	case 15750ULL: goto x86_l_3d86;
	case 15755ULL: goto x86_l_3d8b;
	case 15757ULL: goto x86_l_3d8d;
	case 15762ULL: goto x86_l_3d92;
	case 15767ULL: goto x86_l_3d97;
	case 15772ULL: goto x86_l_3d9c;
	case 15777ULL: goto x86_l_3da1;
	case 15779ULL: goto x86_l_3da3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_38c2:
	/* 0x38c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38c7:
	/* 0x38c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38c9:
	/* 0x38c9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ce:
	/* 0x38ce: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_38d2:
	/* 0x38d2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38d7:
	/* 0x38d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38dc:
	/* 0x38dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38e1:
	/* 0x38e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e6:
	/* 0x38e6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38eb:
	/* 0x38eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ed:
	/* 0x38ed: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38f2:
	/* 0x38f2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_38fa:
	/* 0x38fa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38fe:
	/* 0x38fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3903:
	/* 0x3903: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3908:
	/* 0x3908: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_390d:
	/* 0x390d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_390f:
	/* 0x390f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3917:
	/* 0x3917: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_391a:
	/* 0x391a: je     3997 <vfs_writev_magic_return+0x3997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3997;
	}
x86_l_391c:
	/* 0x391c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3921:
	/* 0x3921: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3924:
	/* 0x3924: je     3997 <vfs_writev_magic_return+0x3997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3997;
	}
x86_l_3926:
	/* 0x3926: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_392a:
	/* 0x392a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_392f:
	/* 0x392f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3934:
	/* 0x3934: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3939:
	/* 0x3939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393b:
	/* 0x393b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_393f:
	/* 0x393f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3941:
	/* 0x3941: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3947:
	/* 0x3947: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_394c:
	/* 0x394c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_394e:
	/* 0x394e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3954:
	/* 0x3954: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3959:
	/* 0x3959: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_395f:
	/* 0x395f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3962:
	/* 0x3962: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3967:
	/* 0x3967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3969:
	/* 0x3969: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_396c:
	/* 0x396c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3972:
	/* 0x3972: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3977:
	/* 0x3977: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_397a:
	/* 0x397a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3980:
	/* 0x3980: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3986:
	/* 0x3986: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3988:
	/* 0x3988: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_398d:
	/* 0x398d: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3995:
	/* 0x3995: jmp    3a07 <vfs_writev_magic_return+0x3a07> */
	goto x86_l_3a07;
x86_l_3997:
	/* 0x3997: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_399a:
	/* 0x399a: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_39a0:
	/* 0x39a0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39a5:
	/* 0x39a5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_39aa:
	/* 0x39aa: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_39b0:
	/* 0x39b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39b5:
	/* 0x39b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ba:
	/* 0x39ba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_39be:
	/* 0x39be: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_39c6:
	/* 0x39c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39cb:
	/* 0x39cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39cd:
	/* 0x39cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39d2:
	/* 0x39d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39d7:
	/* 0x39d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39dc:
	/* 0x39dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39e1:
	/* 0x39e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39e3:
	/* 0x39e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39e8:
	/* 0x39e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ed:
	/* 0x39ed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39f2:
	/* 0x39f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39f7:
	/* 0x39f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f9:
	/* 0x39f9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39fe:
	/* 0x39fe: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3a02:
	/* 0x3a02: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a07:
	/* 0x3a07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a0c:
	/* 0x3a0c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a11:
	/* 0x3a11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a16:
	/* 0x3a16: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a1b:
	/* 0x3a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a1d:
	/* 0x3a1d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a22:
	/* 0x3a22: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a2a:
	/* 0x3a2a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a2e:
	/* 0x3a2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a33:
	/* 0x3a33: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a38:
	/* 0x3a38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a3d:
	/* 0x3a3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a3f:
	/* 0x3a3f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a47:
	/* 0x3a47: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3a4a:
	/* 0x3a4a: je     3ac7 <vfs_writev_magic_return+0x3ac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac7;
	}
x86_l_3a4c:
	/* 0x3a4c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a51:
	/* 0x3a51: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3a54:
	/* 0x3a54: je     3ac7 <vfs_writev_magic_return+0x3ac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac7;
	}
x86_l_3a56:
	/* 0x3a56: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3a5a:
	/* 0x3a5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a5f:
	/* 0x3a5f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a64:
	/* 0x3a64: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3a69:
	/* 0x3a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6b:
	/* 0x3a6b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3a6f:
	/* 0x3a6f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3a71:
	/* 0x3a71: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a77:
	/* 0x3a77: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a7c:
	/* 0x3a7c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a7e:
	/* 0x3a7e: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3a84:
	/* 0x3a84: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a89:
	/* 0x3a89: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3a8f:
	/* 0x3a8f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a92:
	/* 0x3a92: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3a97:
	/* 0x3a97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a99:
	/* 0x3a99: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a9c:
	/* 0x3a9c: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3aa2:
	/* 0x3aa2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aa7:
	/* 0x3aa7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3aaa:
	/* 0x3aaa: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3ab0:
	/* 0x3ab0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ab6:
	/* 0x3ab6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ab8:
	/* 0x3ab8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3abd:
	/* 0x3abd: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3ac5:
	/* 0x3ac5: jmp    3b37 <vfs_writev_magic_return+0x3b37> */
	goto x86_l_3b37;
x86_l_3ac7:
	/* 0x3ac7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3aca:
	/* 0x3aca: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3ad0:
	/* 0x3ad0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ad5:
	/* 0x3ad5: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3ada:
	/* 0x3ada: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3ae0:
	/* 0x3ae0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ae5:
	/* 0x3ae5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aea:
	/* 0x3aea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3aee:
	/* 0x3aee: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3af6:
	/* 0x3af6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3afb:
	/* 0x3afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3afd:
	/* 0x3afd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b02:
	/* 0x3b02: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b07:
	/* 0x3b07: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b0c:
	/* 0x3b0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b11:
	/* 0x3b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b13:
	/* 0x3b13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b18:
	/* 0x3b18: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b1d:
	/* 0x3b1d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b22:
	/* 0x3b22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b27:
	/* 0x3b27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b29:
	/* 0x3b29: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b2e:
	/* 0x3b2e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b32:
	/* 0x3b32: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b37:
	/* 0x3b37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b3c:
	/* 0x3b3c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b41:
	/* 0x3b41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b46:
	/* 0x3b46: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b4b:
	/* 0x3b4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4d:
	/* 0x3b4d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b52:
	/* 0x3b52: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b5a:
	/* 0x3b5a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b5e:
	/* 0x3b5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b63:
	/* 0x3b63: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b68:
	/* 0x3b68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b6d:
	/* 0x3b6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6f:
	/* 0x3b6f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b77:
	/* 0x3b77: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3b7a:
	/* 0x3b7a: je     3bf7 <vfs_writev_magic_return+0x3bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bf7;
	}
x86_l_3b7c:
	/* 0x3b7c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b81:
	/* 0x3b81: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b84:
	/* 0x3b84: je     3bf7 <vfs_writev_magic_return+0x3bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bf7;
	}
x86_l_3b86:
	/* 0x3b86: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b8a:
	/* 0x3b8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b8f:
	/* 0x3b8f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b94:
	/* 0x3b94: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3b99:
	/* 0x3b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9b:
	/* 0x3b9b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3b9f:
	/* 0x3b9f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ba1:
	/* 0x3ba1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ba7:
	/* 0x3ba7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bac:
	/* 0x3bac: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3bae:
	/* 0x3bae: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3bb4:
	/* 0x3bb4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3bb9:
	/* 0x3bb9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3bbf:
	/* 0x3bbf: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3bc2:
	/* 0x3bc2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3bc7:
	/* 0x3bc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc9:
	/* 0x3bc9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3bcc:
	/* 0x3bcc: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3bd2:
	/* 0x3bd2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bd7:
	/* 0x3bd7: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3bda:
	/* 0x3bda: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3be0:
	/* 0x3be0: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3be6:
	/* 0x3be6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3be8:
	/* 0x3be8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bed:
	/* 0x3bed: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3bf5:
	/* 0x3bf5: jmp    3c67 <vfs_writev_magic_return+0x3c67> */
	goto x86_l_3c67;
x86_l_3bf7:
	/* 0x3bf7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3bfa:
	/* 0x3bfa: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3c00:
	/* 0x3c00: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c05:
	/* 0x3c05: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3c0a:
	/* 0x3c0a: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3c10:
	/* 0x3c10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c15:
	/* 0x3c15: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c1a:
	/* 0x3c1a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c1e:
	/* 0x3c1e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3c26:
	/* 0x3c26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c2b:
	/* 0x3c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c2d:
	/* 0x3c2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c32:
	/* 0x3c32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c37:
	/* 0x3c37: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c3c:
	/* 0x3c3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c41:
	/* 0x3c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c43:
	/* 0x3c43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c48:
	/* 0x3c48: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c4d:
	/* 0x3c4d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c52:
	/* 0x3c52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c57:
	/* 0x3c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c59:
	/* 0x3c59: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c5e:
	/* 0x3c5e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3c62:
	/* 0x3c62: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c67:
	/* 0x3c67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c6c:
	/* 0x3c6c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c71:
	/* 0x3c71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c76:
	/* 0x3c76: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c7b:
	/* 0x3c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c7d:
	/* 0x3c7d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c82:
	/* 0x3c82: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3c8a:
	/* 0x3c8a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c8e:
	/* 0x3c8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c93:
	/* 0x3c93: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c98:
	/* 0x3c98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c9d:
	/* 0x3c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9f:
	/* 0x3c9f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3ca7:
	/* 0x3ca7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3caa:
	/* 0x3caa: je     3d41 <vfs_writev_magic_return+0x3d41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d41;
	}
x86_l_3cb0:
	/* 0x3cb0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cb5:
	/* 0x3cb5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3cb8:
	/* 0x3cb8: je     3d41 <vfs_writev_magic_return+0x3d41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d41;
	}
x86_l_3cbe:
	/* 0x3cbe: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3cc2:
	/* 0x3cc2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cc7:
	/* 0x3cc7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ccc:
	/* 0x3ccc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3cd1:
	/* 0x3cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd3:
	/* 0x3cd3: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3cd7:
	/* 0x3cd7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3cd9:
	/* 0x3cd9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3cdf:
	/* 0x3cdf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ce4:
	/* 0x3ce4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ce6:
	/* 0x3ce6: jb     2b02 <vfs_writev_magic_return+0x2b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11010ULL;
	}
x86_l_3cec:
	/* 0x3cec: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3cf1:
	/* 0x3cf1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3cf7:
	/* 0x3cf7: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3cfa:
	/* 0x3cfa: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3cff:
	/* 0x3cff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d01:
	/* 0x3d01: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d04:
	/* 0x3d04: jl     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6721ULL;
	}
x86_l_3d0a:
	/* 0x3d0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0f:
	/* 0x3d0f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d12:
	/* 0x3d12: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3d18:
	/* 0x3d18: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3d1e:
	/* 0x3d1e: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d20:
	/* 0x3d20: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3d28:
	/* 0x3d28: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_3d2b:
	/* 0x3d2b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d30:
	/* 0x3d30: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_3d36:
	/* 0x3d36: je     1a5a <vfs_writev_magic_return+0x1a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6746ULL;
	}
x86_l_3d3c:
	/* 0x3d3c: jmp    1bab <vfs_writev_magic_return+0x1bab> */
	return 7083ULL;
x86_l_3d41:
	/* 0x3d41: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3d44:
	/* 0x3d44: jne    1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6721ULL;
	}
x86_l_3d4a:
	/* 0x3d4a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4f:
	/* 0x3d4f: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3d54:
	/* 0x3d54: je     1a41 <vfs_writev_magic_return+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_3d5a:
	/* 0x3d5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d5f:
	/* 0x3d5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d64:
	/* 0x3d64: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d68:
	/* 0x3d68: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3d70:
	/* 0x3d70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d75:
	/* 0x3d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d77:
	/* 0x3d77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d7c:
	/* 0x3d7c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d81:
	/* 0x3d81: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d86:
	/* 0x3d86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d8b:
	/* 0x3d8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d8d:
	/* 0x3d8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d92:
	/* 0x3d92: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d97:
	/* 0x3d97: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d9c:
	/* 0x3d9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3da1:
	/* 0x3da1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da3:
	/* 0x3da3: jmp    1a41 <vfs_writev_magic_return+0x1a41> */
	return 6721ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 13400U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2297ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2302ULL && __x86_pc <= 4143ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 4145ULL && __x86_pc <= 5857ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5861ULL && __x86_pc <= 7702ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7705ULL && __x86_pc <= 9445ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9450ULL && __x86_pc <= 11092ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11097ULL && __x86_pc <= 12806ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12810ULL && __x86_pc <= 14525ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14530ULL && __x86_pc <= 15779ULL)
			__x86_pc = tracee_vfs_writev_magic_return_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

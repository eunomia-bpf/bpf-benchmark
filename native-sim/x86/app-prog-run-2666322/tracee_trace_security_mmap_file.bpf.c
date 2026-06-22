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

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_0(
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
	case 89ULL: goto x86_l_59;
	case 91ULL: goto x86_l_5b;
	case 94ULL: goto x86_l_5e;
	case 96ULL: goto x86_l_60;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 127ULL: goto x86_l_7f;
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 145ULL: goto x86_l_91;
	case 150ULL: goto x86_l_96;
	case 152ULL: goto x86_l_98;
	case 155ULL: goto x86_l_9b;
	case 157ULL: goto x86_l_9d;
	case 159ULL: goto x86_l_9f;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 173ULL: goto x86_l_ad;
	case 178ULL: goto x86_l_b2;
	case 185ULL: goto x86_l_b9;
	case 188ULL: goto x86_l_bc;
	case 190ULL: goto x86_l_be;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 207ULL: goto x86_l_cf;
	case 214ULL: goto x86_l_d6;
	case 217ULL: goto x86_l_d9;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 241ULL: goto x86_l_f1;
	case 249ULL: goto x86_l_f9;
	case 260ULL: goto x86_l_104;
	case 271ULL: goto x86_l_10f;
	case 282ULL: goto x86_l_11a;
	case 293ULL: goto x86_l_125;
	case 304ULL: goto x86_l_130;
	case 315ULL: goto x86_l_13b;
	case 326ULL: goto x86_l_146;
	case 337ULL: goto x86_l_151;
	case 344ULL: goto x86_l_158;
	case 352ULL: goto x86_l_160;
	case 360ULL: goto x86_l_168;
	case 368ULL: goto x86_l_170;
	case 376ULL: goto x86_l_178;
	case 384ULL: goto x86_l_180;
	case 392ULL: goto x86_l_188;
	case 400ULL: goto x86_l_190;
	case 408ULL: goto x86_l_198;
	case 416ULL: goto x86_l_1a0;
	case 424ULL: goto x86_l_1a8;
	case 432ULL: goto x86_l_1b0;
	case 440ULL: goto x86_l_1b8;
	case 448ULL: goto x86_l_1c0;
	case 453ULL: goto x86_l_1c5;
	case 455ULL: goto x86_l_1c7;
	case 459ULL: goto x86_l_1cb;
	case 463ULL: goto x86_l_1cf;
	case 467ULL: goto x86_l_1d3;
	case 475ULL: goto x86_l_1db;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 501ULL: goto x86_l_1f5;
	case 505ULL: goto x86_l_1f9;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 524ULL: goto x86_l_20c;
	case 532ULL: goto x86_l_214;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 542ULL: goto x86_l_21e;
	case 544ULL: goto x86_l_220;
	case 548ULL: goto x86_l_224;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 567ULL: goto x86_l_237;
	case 575ULL: goto x86_l_23f;
	case 577ULL: goto x86_l_241;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 600ULL: goto x86_l_258;
	case 605ULL: goto x86_l_25d;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 619ULL: goto x86_l_26b;
	case 623ULL: goto x86_l_26f;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 653ULL: goto x86_l_28d;
	case 659ULL: goto x86_l_293;
	case 663ULL: goto x86_l_297;
	case 667ULL: goto x86_l_29b;
	case 678ULL: goto x86_l_2a6;
	case 689ULL: goto x86_l_2b1;
	case 700ULL: goto x86_l_2bc;
	case 711ULL: goto x86_l_2c7;
	case 722ULL: goto x86_l_2d2;
	case 733ULL: goto x86_l_2dd;
	case 744ULL: goto x86_l_2e8;
	case 755ULL: goto x86_l_2f3;
	case 766ULL: goto x86_l_2fe;
	case 777ULL: goto x86_l_309;
	case 788ULL: goto x86_l_314;
	case 799ULL: goto x86_l_31f;
	case 810ULL: goto x86_l_32a;
	case 821ULL: goto x86_l_335;
	case 832ULL: goto x86_l_340;
	case 843ULL: goto x86_l_34b;
	case 854ULL: goto x86_l_356;
	case 865ULL: goto x86_l_361;
	case 876ULL: goto x86_l_36c;
	case 887ULL: goto x86_l_377;
	case 898ULL: goto x86_l_382;
	case 909ULL: goto x86_l_38d;
	case 920ULL: goto x86_l_398;
	case 931ULL: goto x86_l_3a3;
	case 942ULL: goto x86_l_3ae;
	case 953ULL: goto x86_l_3b9;
	case 964ULL: goto x86_l_3c4;
	case 975ULL: goto x86_l_3cf;
	case 986ULL: goto x86_l_3da;
	case 997ULL: goto x86_l_3e5;
	case 1005ULL: goto x86_l_3ed;
	case 1013ULL: goto x86_l_3f5;
	case 1021ULL: goto x86_l_3fd;
	case 1029ULL: goto x86_l_405;
	case 1037ULL: goto x86_l_40d;
	case 1045ULL: goto x86_l_415;
	case 1053ULL: goto x86_l_41d;
	case 1061ULL: goto x86_l_425;
	case 1069ULL: goto x86_l_42d;
	case 1077ULL: goto x86_l_435;
	case 1085ULL: goto x86_l_43d;
	case 1093ULL: goto x86_l_445;
	case 1101ULL: goto x86_l_44d;
	case 1109ULL: goto x86_l_455;
	case 1117ULL: goto x86_l_45d;
	case 1124ULL: goto x86_l_464;
	case 1130ULL: goto x86_l_46a;
	case 1137ULL: goto x86_l_471;
	case 1142ULL: goto x86_l_476;
	case 1147ULL: goto x86_l_47b;
	case 1150ULL: goto x86_l_47e;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1169ULL: goto x86_l_491;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1179ULL: goto x86_l_49b;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1197ULL: goto x86_l_4ad;
	case 1201ULL: goto x86_l_4b1;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1245ULL: goto x86_l_4dd;
	case 1253ULL: goto x86_l_4e5;
	case 1257ULL: goto x86_l_4e9;
	case 1261ULL: goto x86_l_4ed;
	case 1272ULL: goto x86_l_4f8;
	case 1283ULL: goto x86_l_503;
	case 1294ULL: goto x86_l_50e;
	case 1305ULL: goto x86_l_519;
	case 1316ULL: goto x86_l_524;
	case 1327ULL: goto x86_l_52f;
	case 1338ULL: goto x86_l_53a;
	case 1349ULL: goto x86_l_545;
	case 1360ULL: goto x86_l_550;
	case 1368ULL: goto x86_l_558;
	case 1376ULL: goto x86_l_560;
	case 1384ULL: goto x86_l_568;
	case 1392ULL: goto x86_l_570;
	case 1400ULL: goto x86_l_578;
	case 1408ULL: goto x86_l_580;
	case 1416ULL: goto x86_l_588;
	case 1424ULL: goto x86_l_590;
	case 1432ULL: goto x86_l_598;
	case 1440ULL: goto x86_l_5a0;
	case 1448ULL: goto x86_l_5a8;
	case 1456ULL: goto x86_l_5b0;
	case 1464ULL: goto x86_l_5b8;
	case 1472ULL: goto x86_l_5c0;
	case 1480ULL: goto x86_l_5c8;
	case 1487ULL: goto x86_l_5cf;
	case 1493ULL: goto x86_l_5d5;
	case 1500ULL: goto x86_l_5dc;
	case 1505ULL: goto x86_l_5e1;
	case 1510ULL: goto x86_l_5e6;
	case 1513ULL: goto x86_l_5e9;
	case 1516ULL: goto x86_l_5ec;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1546ULL: goto x86_l_60a;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1576ULL: goto x86_l_628;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1591ULL: goto x86_l_637;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1664ULL: goto x86_l_680;
	case 1668ULL: goto x86_l_684;
	case 1671ULL: goto x86_l_687;
	case 1679ULL: goto x86_l_68f;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1701ULL: goto x86_l_6a5;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1726ULL: goto x86_l_6be;
	case 1728ULL: goto x86_l_6c0;
	case 1732ULL: goto x86_l_6c4;
	case 1736ULL: goto x86_l_6c8;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1761ULL: goto x86_l_6e1;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1928ULL: goto x86_l_788;
	case 1932ULL: goto x86_l_78c;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2041ULL: goto x86_l_7f9;
	case 2045ULL: goto x86_l_7fd;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
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
	/* 0x2a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f:
	/* 0x2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34:
	/* 0x34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36:
	/* 0x36: test   DWORD PTR [rsp+0x20],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137441050624ULL);
x86_l_3e:
	/* 0x3e: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_43:
	/* 0x43: jne    a6 <trace_security_mmap_file+0xa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a6;
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
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     60 <trace_security_mmap_file+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60;
	}
x86_l_5b:
	/* 0x5b: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5e:
	/* 0x5e: jmp    60 <trace_security_mmap_file+0x60> */
	goto x86_l_60;
x86_l_60:
	/* 0x60: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64:
	/* 0x64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69:
	/* 0x69: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e:
	/* 0x6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_73:
	/* 0x73: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_76:
	/* 0x76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78:
	/* 0x78: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_7d:
	/* 0x7d: jne    85 <trace_security_mmap_file+0x85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85;
	}
x86_l_7f:
	/* 0x7f: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83:
	/* 0x83: jmp    a6 <trace_security_mmap_file+0xa6> */
	goto x86_l_a6;
x86_l_85:
	/* 0x85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_91:
	/* 0x91: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96:
	/* 0x96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98:
	/* 0x98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: je     a1 <trace_security_mmap_file+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a1;
	}
x86_l_9d:
	/* 0x9d: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f:
	/* 0x9f: jmp    a6 <trace_security_mmap_file+0xa6> */
	goto x86_l_a6;
x86_l_a1:
	/* 0xa1: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_a6:
	/* 0xa6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad:
	/* 0xad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b2:
	/* 0xb2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_b9:
	/* 0xb9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bc:
	/* 0xbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be:
	/* 0xbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_c7:
	/* 0xc7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cf:
	/* 0xcf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_d6:
	/* 0xd6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d9:
	/* 0xd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db:
	/* 0xdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_e4:
	/* 0xe4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_f1:
	/* 0xf1: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_104:
	/* 0x104: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_10f:
	/* 0x10f: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_11a:
	/* 0x11a: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_125:
	/* 0x125: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_130:
	/* 0x130: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_13b:
	/* 0x13b: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_146:
	/* 0x146: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_151:
	/* 0x151: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_158:
	/* 0x158: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_160:
	/* 0x160: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_168:
	/* 0x168: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_178:
	/* 0x178: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_190:
	/* 0x190: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1a0:
	/* 0x1a0: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1b8:
	/* 0x1b8: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1c0:
	/* 0x1c0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c5:
	/* 0x1c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7:
	/* 0x1c7: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cb:
	/* 0x1cb: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1cf:
	/* 0x1cf: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d3:
	/* 0x1d3: mov    DWORD PTR [r14+0x70],0x2f9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337913ULL);
x86_l_1db:
	/* 0x1db: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1e0:
	/* 0x1e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1f1:
	/* 0x1f1: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1f5:
	/* 0x1f5: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f9:
	/* 0x1f9: mov    DWORD PTR [rsp+0xc8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_200:
	/* 0x200: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_205:
	/* 0x205: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_20c:
	/* 0x20c: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_214:
	/* 0x214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216:
	/* 0x216: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21b:
	/* 0x21b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21e:
	/* 0x21e: je     264 <trace_security_mmap_file+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264;
	}
x86_l_220:
	/* 0x220: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_224:
	/* 0x224: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_22b:
	/* 0x22b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230:
	/* 0x230: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_237:
	/* 0x237: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23f:
	/* 0x23f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241:
	/* 0x241: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_244:
	/* 0x244: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_247:
	/* 0x247: je     4a6 <trace_security_mmap_file+0x4a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a6;
	}
x86_l_24d:
	/* 0x24d: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_252:
	/* 0x252: jne    a1a <trace_security_mmap_file+0xa1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2586ULL;
	}
x86_l_258:
	/* 0x258: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_25d:
	/* 0x25d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f:
	/* 0x25f: jmp    aa1 <trace_security_mmap_file+0xaa1> */
	return 2721ULL;
x86_l_264:
	/* 0x264: mov    eax,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_26b:
	/* 0x26b: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f:
	/* 0x26f: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_277:
	/* 0x277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c:
	/* 0x27c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_283:
	/* 0x283: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_288:
	/* 0x288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a:
	/* 0x28a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d:
	/* 0x28d: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_293:
	/* 0x293: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_297:
	/* 0x297: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29b:
	/* 0x29b: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2a6:
	/* 0x2a6: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2b1:
	/* 0x2b1: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2bc:
	/* 0x2bc: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2c7:
	/* 0x2c7: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2d2:
	/* 0x2d2: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2e8:
	/* 0x2e8: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_2fe:
	/* 0x2fe: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_309:
	/* 0x309: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_314:
	/* 0x314: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_31f:
	/* 0x31f: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_32a:
	/* 0x32a: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_335:
	/* 0x335: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_340:
	/* 0x340: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_34b:
	/* 0x34b: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_356:
	/* 0x356: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_361:
	/* 0x361: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_36c:
	/* 0x36c: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_377:
	/* 0x377: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_382:
	/* 0x382: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_38d:
	/* 0x38d: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_398:
	/* 0x398: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3a3:
	/* 0x3a3: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3ae:
	/* 0x3ae: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3b9:
	/* 0x3b9: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3c4:
	/* 0x3c4: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3cf:
	/* 0x3cf: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3da:
	/* 0x3da: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3e5:
	/* 0x3e5: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3ed:
	/* 0x3ed: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3fd:
	/* 0x3fd: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_405:
	/* 0x405: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_40d:
	/* 0x40d: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_415:
	/* 0x415: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_425:
	/* 0x425: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_42d:
	/* 0x42d: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_435:
	/* 0x435: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_455:
	/* 0x455: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_45d:
	/* 0x45d: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_464:
	/* 0x464: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_46a:
	/* 0x46a: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_471:
	/* 0x471: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_476:
	/* 0x476: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_47b:
	/* 0x47b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_481:
	/* 0x481: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_484:
	/* 0x484: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_489:
	/* 0x489: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48e:
	/* 0x48e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_491:
	/* 0x491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_498:
	/* 0x498: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49b:
	/* 0x49b: jne    220 <trace_security_mmap_file+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_220;
	}
x86_l_4a1:
	/* 0x4a1: jmp    3a67 <trace_security_mmap_file+0x3a67> */
	return 14951ULL;
x86_l_4a6:
	/* 0x4a6: mov    eax,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4ad:
	/* 0x4ad: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b1:
	/* 0x4b1: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4b9:
	/* 0x4b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4be:
	/* 0x4be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4c5:
	/* 0x4c5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ca:
	/* 0x4ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cc:
	/* 0x4cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4cf:
	/* 0x4cf: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_4d5:
	/* 0x4d5: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rsp+0xd8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4e5:
	/* 0x4e5: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e9:
	/* 0x4e9: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_4f8:
	/* 0x4f8: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_50e:
	/* 0x50e: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_519:
	/* 0x519: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_524:
	/* 0x524: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_52f:
	/* 0x52f: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_53a:
	/* 0x53a: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_545:
	/* 0x545: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_550:
	/* 0x550: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_558:
	/* 0x558: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_560:
	/* 0x560: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_568:
	/* 0x568: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_580:
	/* 0x580: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_588:
	/* 0x588: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5a0:
	/* 0x5a0: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5c0:
	/* 0x5c0: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cf:
	/* 0x5cf: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5d5:
	/* 0x5d5: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5dc:
	/* 0x5dc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e1:
	/* 0x5e1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5e6:
	/* 0x5e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ec:
	/* 0x5ec: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5ef:
	/* 0x5ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f4:
	/* 0x5f4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f9:
	/* 0x5f9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5fc:
	/* 0x5fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe:
	/* 0x5fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_601:
	/* 0x601: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_607:
	/* 0x607: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_60a:
	/* 0x60a: mov    r12,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_611:
	/* 0x611: lea    r13,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_616:
	/* 0x616: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61b:
	/* 0x61b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_620:
	/* 0x620: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_625:
	/* 0x625: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_628:
	/* 0x628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62a:
	/* 0x62a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62f:
	/* 0x62f: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_637:
	/* 0x637: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63b:
	/* 0x63b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_640:
	/* 0x640: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_645:
	/* 0x645: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64a:
	/* 0x64a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64c:
	/* 0x64c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_651:
	/* 0x651: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_655:
	/* 0x655: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65a:
	/* 0x65a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65f:
	/* 0x65f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_664:
	/* 0x664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666:
	/* 0x666: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66b:
	/* 0x66b: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_66f:
	/* 0x66f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_674:
	/* 0x674: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_679:
	/* 0x679: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_67e:
	/* 0x67e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_680:
	/* 0x680: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_684:
	/* 0x684: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_687:
	/* 0x687: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_68f:
	/* 0x68f: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_693:
	/* 0x693: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_698:
	/* 0x698: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69d:
	/* 0x69d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a2:
	/* 0x6a2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6a5:
	/* 0x6a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a7:
	/* 0x6a7: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ac:
	/* 0x6ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b1:
	/* 0x6b1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b6:
	/* 0x6b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6bb:
	/* 0x6bb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6be:
	/* 0x6be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c0:
	/* 0x6c0: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c4:
	/* 0x6c4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6c8:
	/* 0x6c8: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6cc:
	/* 0x6cc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6d0:
	/* 0x6d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d5:
	/* 0x6d5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6da:
	/* 0x6da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6df:
	/* 0x6df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e1:
	/* 0x6e1: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e5:
	/* 0x6e5: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ed:
	/* 0x6ed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f2:
	/* 0x6f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f7:
	/* 0x6f7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6fa:
	/* 0x6fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fc:
	/* 0x6fc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_701:
	/* 0x701: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_705:
	/* 0x705: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70a:
	/* 0x70a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_70f:
	/* 0x70f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_714:
	/* 0x714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_716:
	/* 0x716: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71b:
	/* 0x71b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_720:
	/* 0x720: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_725:
	/* 0x725: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_72a:
	/* 0x72a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_72d:
	/* 0x72d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72f:
	/* 0x72f: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_733:
	/* 0x733: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_737:
	/* 0x737: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_73b:
	/* 0x73b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_73f:
	/* 0x73f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_744:
	/* 0x744: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_749:
	/* 0x749: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_74e:
	/* 0x74e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_750:
	/* 0x750: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_754:
	/* 0x754: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_757:
	/* 0x757: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75c:
	/* 0x75c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_761:
	/* 0x761: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_766:
	/* 0x766: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_770:
	/* 0x770: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_775:
	/* 0x775: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77a:
	/* 0x77a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77f:
	/* 0x77f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_782:
	/* 0x782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_784:
	/* 0x784: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_788:
	/* 0x788: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_78c:
	/* 0x78c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_790:
	/* 0x790: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_794:
	/* 0x794: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_799:
	/* 0x799: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_79e:
	/* 0x79e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a3:
	/* 0x7a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a5:
	/* 0x7a5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7aa:
	/* 0x7aa: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7ae:
	/* 0x7ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b3:
	/* 0x7b3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b8:
	/* 0x7b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7bd:
	/* 0x7bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bf:
	/* 0x7bf: mov    r13d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c4:
	/* 0x7c4: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c8:
	/* 0x7c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7cd:
	/* 0x7cd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7d2:
	/* 0x7d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e1:
	/* 0x7e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e6:
	/* 0x7e6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7eb:
	/* 0x7eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f0:
	/* 0x7f0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7f3:
	/* 0x7f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f5:
	/* 0x7f5: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f9:
	/* 0x7f9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7fd:
	/* 0x7fd: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_801:
	/* 0x801: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_805:
	/* 0x805: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80a:
	/* 0x80a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_80f:
	/* 0x80f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_814:
	/* 0x814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_816:
	/* 0x816: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_81b:
	/* 0x81b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_81f:
	/* 0x81f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_824:
	/* 0x824: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_829:
	/* 0x829: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82e:
	/* 0x82e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_830:
	/* 0x830: cmp    r13d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_835:
	/* 0x835: jne    88c <trace_security_mmap_file+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2188ULL;
	}
x86_l_837:
	/* 0x837: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_83c:
	/* 0x83c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_841:
	/* 0x841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_846:
	/* 0x846: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_849:
	/* 0x849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84b:
	/* 0x84b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_850:
	/* 0x850: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2133ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2146ULL: goto x86_l_862;
	case 2148ULL: goto x86_l_864;
	case 2152ULL: goto x86_l_868;
	case 2156ULL: goto x86_l_86c;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2181ULL: goto x86_l_885;
	case 2185ULL: goto x86_l_889;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2203ULL: goto x86_l_89b;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2318ULL: goto x86_l_90e;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2329ULL: goto x86_l_919;
	case 2337ULL: goto x86_l_921;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2390ULL: goto x86_l_956;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2420ULL: goto x86_l_974;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2449ULL: goto x86_l_991;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2557ULL: goto x86_l_9fd;
	case 2559ULL: goto x86_l_9ff;
	case 2567ULL: goto x86_l_a07;
	case 2575ULL: goto x86_l_a0f;
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
	case 2730ULL: goto x86_l_aaa;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2756ULL: goto x86_l_ac4;
	case 2758ULL: goto x86_l_ac6;
	case 2761ULL: goto x86_l_ac9;
	case 2769ULL: goto x86_l_ad1;
	case 2772ULL: goto x86_l_ad4;
	case 2775ULL: goto x86_l_ad7;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2798ULL: goto x86_l_aee;
	case 2809ULL: goto x86_l_af9;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2841ULL: goto x86_l_b19;
	case 2844ULL: goto x86_l_b1c;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2859ULL: goto x86_l_b2b;
	case 2861ULL: goto x86_l_b2d;
	case 2864ULL: goto x86_l_b30;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2877ULL: goto x86_l_b3d;
	case 2880ULL: goto x86_l_b40;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2895ULL: goto x86_l_b4f;
	case 2902ULL: goto x86_l_b56;
	case 2909ULL: goto x86_l_b5d;
	case 2913ULL: goto x86_l_b61;
	case 2920ULL: goto x86_l_b68;
	case 2924ULL: goto x86_l_b6c;
	case 2931ULL: goto x86_l_b73;
	case 2935ULL: goto x86_l_b77;
	case 2942ULL: goto x86_l_b7e;
	case 2946ULL: goto x86_l_b82;
	case 2953ULL: goto x86_l_b89;
	case 2960ULL: goto x86_l_b90;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2974ULL: goto x86_l_b9e;
	case 2980ULL: goto x86_l_ba4;
	case 2984ULL: goto x86_l_ba8;
	case 2992ULL: goto x86_l_bb0;
	case 3000ULL: goto x86_l_bb8;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3050ULL: goto x86_l_bea;
	case 3055ULL: goto x86_l_bef;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3117ULL: goto x86_l_c2d;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3162ULL: goto x86_l_c5a;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3185ULL: goto x86_l_c71;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3238ULL: goto x86_l_ca6;
	case 3240ULL: goto x86_l_ca8;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3271ULL: goto x86_l_cc7;
	case 3276ULL: goto x86_l_ccc;
	case 3279ULL: goto x86_l_ccf;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3310ULL: goto x86_l_cee;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3339ULL: goto x86_l_d0b;
	case 3343ULL: goto x86_l_d0f;
	case 3351ULL: goto x86_l_d17;
	case 3354ULL: goto x86_l_d1a;
	case 3362ULL: goto x86_l_d22;
	case 3364ULL: goto x86_l_d24;
	case 3372ULL: goto x86_l_d2c;
	case 3380ULL: goto x86_l_d34;
	case 3388ULL: goto x86_l_d3c;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3405ULL: goto x86_l_d4d;
	case 3408ULL: goto x86_l_d50;
	case 3414ULL: goto x86_l_d56;
	case 3423ULL: goto x86_l_d5f;
	case 3426ULL: goto x86_l_d62;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3436ULL: goto x86_l_d6c;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3449ULL: goto x86_l_d79;
	case 3452ULL: goto x86_l_d7c;
	case 3459ULL: goto x86_l_d83;
	case 3462ULL: goto x86_l_d86;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3474ULL: goto x86_l_d92;
	case 3481ULL: goto x86_l_d99;
	case 3484ULL: goto x86_l_d9c;
	case 3487ULL: goto x86_l_d9f;
	case 3490ULL: goto x86_l_da2;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3535ULL: goto x86_l_dcf;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3565ULL: goto x86_l_ded;
	case 3568ULL: goto x86_l_df0;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	case 3581ULL: goto x86_l_dfd;
	case 3586ULL: goto x86_l_e02;
	case 3593ULL: goto x86_l_e09;
	case 3596ULL: goto x86_l_e0c;
	case 3604ULL: goto x86_l_e14;
	case 3610ULL: goto x86_l_e1a;
	case 3617ULL: goto x86_l_e21;
	case 3625ULL: goto x86_l_e29;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3692ULL: goto x86_l_e6c;
	case 3695ULL: goto x86_l_e6f;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3793ULL: goto x86_l_ed1;
	case 3796ULL: goto x86_l_ed4;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3818ULL: goto x86_l_eea;
	case 3821ULL: goto x86_l_eed;
	case 3823ULL: goto x86_l_eef;
	case 3826ULL: goto x86_l_ef2;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3835ULL: goto x86_l_efb;
	case 3842ULL: goto x86_l_f02;
	default: return 0xffffffffffffffffULL;
	}
x86_l_855:
	/* 0x855: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_85a:
	/* 0x85a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_85f:
	/* 0x85f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_862:
	/* 0x862: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_864:
	/* 0x864: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_868:
	/* 0x868: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_86c:
	/* 0x86c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_870:
	/* 0x870: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_874:
	/* 0x874: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_879:
	/* 0x879: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87e:
	/* 0x87e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_883:
	/* 0x883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_885:
	/* 0x885: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_889:
	/* 0x889: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88c:
	/* 0x88c: mov    DWORD PTR [rbx+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_890:
	/* 0x890: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_893:
	/* 0x893: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_89b:
	/* 0x89b: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8a2:
	/* 0x8a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a7:
	/* 0x8a7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ac:
	/* 0x8ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b1:
	/* 0x8b1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8b4:
	/* 0x8b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b6:
	/* 0x8b6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8bb:
	/* 0x8bb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8bf:
	/* 0x8bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8c4:
	/* 0x8c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c9:
	/* 0x8c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ce:
	/* 0x8ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d0:
	/* 0x8d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d5:
	/* 0x8d5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8da:
	/* 0x8da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8df:
	/* 0x8df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8e4:
	/* 0x8e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e6:
	/* 0x8e6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ea:
	/* 0x8ea: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8fb:
	/* 0x8fb: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8ff:
	/* 0x8ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_904:
	/* 0x904: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_909:
	/* 0x909: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_90e:
	/* 0x90e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_910:
	/* 0x910: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_915:
	/* 0x915: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_919:
	/* 0x919: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_921:
	/* 0x921: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_925:
	/* 0x925: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92a:
	/* 0x92a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_92f:
	/* 0x92f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_934:
	/* 0x934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_936:
	/* 0x936: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93b:
	/* 0x93b: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_940:
	/* 0x940: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_944:
	/* 0x944: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_949:
	/* 0x949: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94e:
	/* 0x94e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_953:
	/* 0x953: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_956:
	/* 0x956: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_958:
	/* 0x958: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_95d:
	/* 0x95d: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_962:
	/* 0x962: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_967:
	/* 0x967: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_96c:
	/* 0x96c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_971:
	/* 0x971: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_974:
	/* 0x974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_976:
	/* 0x976: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_97b:
	/* 0x97b: je     983 <trace_security_mmap_file+0x983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_983;
	}
x86_l_97d:
	/* 0x97d: or     BYTE PTR [r12+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_983:
	/* 0x983: lea    rdi,[r12+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_988:
	/* 0x988: mov    QWORD PTR [r12+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_991:
	/* 0x991: mov    QWORD PTR [r12+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_99a:
	/* 0x99a: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_99f:
	/* 0x99f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9a4:
	/* 0x9a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a6:
	/* 0x9a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ab:
	/* 0x9ab: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9b0:
	/* 0x9b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9b5:
	/* 0x9b5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9b8:
	/* 0x9b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ba:
	/* 0x9ba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c4:
	/* 0x9c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c9:
	/* 0x9c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ce:
	/* 0x9ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d0:
	/* 0x9d0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d5:
	/* 0x9d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9da:
	/* 0x9da: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9df:
	/* 0x9df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9e7:
	/* 0x9e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e9:
	/* 0x9e9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9ec:
	/* 0x9ec: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9f0:
	/* 0x9f0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9f5:
	/* 0x9f5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9fa:
	/* 0x9fa: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9fd:
	/* 0x9fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ff:
	/* 0x9ff: mov    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_a07:
	/* 0xa07: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a0f:
	/* 0xa0f: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a14:
	/* 0xa14: je     258 <trace_security_mmap_file+0x258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 600ULL;
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
	/* 0xa2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0xa3c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a41:
	/* 0xa41: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0xa52: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a57:
	/* 0xa57: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5c:
	/* 0xa5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a61:
	/* 0xa61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a63:
	/* 0xa63: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a68:
	/* 0xa68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a6d:
	/* 0xa6d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a72:
	/* 0xa72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a77:
	/* 0xa77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a79:
	/* 0xa79: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7e:
	/* 0xa7e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a81:
	/* 0xa81: je     a9f <trace_security_mmap_file+0xa9f> */
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
	/* 0xa8c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a91:
	/* 0xa91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a96:
	/* 0xa96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a98:
	/* 0xa98: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a9d:
	/* 0xa9d: jmp    aa1 <trace_security_mmap_file+0xaa1> */
	goto x86_l_aa1;
x86_l_a9f:
	/* 0xa9f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa1:
	/* 0xaa1: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aaa:
	/* 0xaaa: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aae:
	/* 0xaae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab3:
	/* 0xab3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_aba:
	/* 0xaba: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_abf:
	/* 0xabf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac1:
	/* 0xac1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac4:
	/* 0xac4: je     ade <trace_security_mmap_file+0xade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ade;
	}
x86_l_ac6:
	/* 0xac6: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ac9:
	/* 0xac9: mov    BYTE PTR [r12+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ad1:
	/* 0xad1: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_ad4:
	/* 0xad4: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ad7:
	/* 0xad7: jne    ade <trace_security_mmap_file+0xade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ade;
	}
x86_l_ad9:
	/* 0xad9: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_ade:
	/* 0xade: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ae3:
	/* 0xae3: cmp    ax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ae8:
	/* 0xae8: jne    3a39 <trace_security_mmap_file+0x3a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14905ULL;
	}
x86_l_aee:
	/* 0xaee: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_af9:
	/* 0xaf9: mov    DWORD PTR [rsp+0x20],0x2f9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438954233ULL);
x86_l_b01:
	/* 0xb01: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b06:
	/* 0xb06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b0b:
	/* 0xb0b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b12:
	/* 0xb12: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b17:
	/* 0xb17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b19:
	/* 0xb19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1c:
	/* 0xb1c: je     b89 <trace_security_mmap_file+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b1e:
	/* 0xb1e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b23:
	/* 0xb23: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b28:
	/* 0xb28: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b2b:
	/* 0xb2b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b2d:
	/* 0xb2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b30:
	/* 0xb30: je     b89 <trace_security_mmap_file+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b32:
	/* 0xb32: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b36:
	/* 0xb36: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b3d:
	/* 0xb3d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b40:
	/* 0xb40: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b47:
	/* 0xb47: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4b:
	/* 0xb4b: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b4f:
	/* 0xb4f: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b56:
	/* 0xb56: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b5d:
	/* 0xb5d: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b61:
	/* 0xb61: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b68:
	/* 0xb68: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6c:
	/* 0xb6c: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b73:
	/* 0xb73: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b77:
	/* 0xb77: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b7e:
	/* 0xb7e: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b82:
	/* 0xb82: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b89:
	/* 0xb89: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b90:
	/* 0xb90: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b97:
	/* 0xb97: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b9b:
	/* 0xb9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9e:
	/* 0xb9e: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_ba4:
	/* 0xba4: lea    rcx,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ba8:
	/* 0xba8: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bb0:
	/* 0xbb0: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bb8:
	/* 0xbb8: lea    rbx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bbc:
	/* 0xbbc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc1:
	/* 0xbc1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bc6:
	/* 0xbc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bcb:
	/* 0xbcb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_bce:
	/* 0xbce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd0:
	/* 0xbd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bd5:
	/* 0xbd5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bda:
	/* 0xbda: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bde:
	/* 0xbde: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be3:
	/* 0xbe3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be8:
	/* 0xbe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bea:
	/* 0xbea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bef:
	/* 0xbef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf4:
	/* 0xbf4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bf9:
	/* 0xbf9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bfe:
	/* 0xbfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c00:
	/* 0xc00: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c04:
	/* 0xc04: mov    DWORD PTR [rsp+0xd4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_c0b:
	/* 0xc0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c10:
	/* 0xc10: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c15:
	/* 0xc15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1a:
	/* 0xc1a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c24:
	/* 0xc24: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c29:
	/* 0xc29: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c2d:
	/* 0xc2d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c32:
	/* 0xc32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c37:
	/* 0xc37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c39:
	/* 0xc39: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c3e:
	/* 0xc3e: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c46:
	/* 0xc46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c4b:
	/* 0xc4b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c50:
	/* 0xc50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c55:
	/* 0xc55: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_c58:
	/* 0xc58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5a:
	/* 0xc5a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_c63:
	/* 0xc63: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c68:
	/* 0xc68: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_c71:
	/* 0xc71: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c75:
	/* 0xc75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c7a:
	/* 0xc7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7f:
	/* 0xc7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c84:
	/* 0xc84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c86:
	/* 0xc86: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8b:
	/* 0xc8b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c90:
	/* 0xc90: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c94:
	/* 0xc94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c99:
	/* 0xc99: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9e:
	/* 0xc9e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ca3:
	/* 0xca3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ca6:
	/* 0xca6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca8:
	/* 0xca8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cac:
	/* 0xcac: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb1:
	/* 0xcb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb6:
	/* 0xcb6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cbb:
	/* 0xcbb: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc0:
	/* 0xcc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cc5:
	/* 0xcc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc7:
	/* 0xcc7: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccc:
	/* 0xccc: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_ccf:
	/* 0xccf: js     cf5 <trace_security_mmap_file+0xcf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_cf5;
	}
x86_l_cd1:
	/* 0xcd1: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cd6:
	/* 0xcd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cdb:
	/* 0xcdb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce0:
	/* 0xce0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce5:
	/* 0xce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce7:
	/* 0xce7: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_cee:
	/* 0xcee: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_cf3:
	/* 0xcf3: jmp    cf7 <trace_security_mmap_file+0xcf7> */
	goto x86_l_cf7;
x86_l_cf5:
	/* 0xcf5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf7:
	/* 0xcf7: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_cff:
	/* 0xcff: mov    rax,QWORD PTR [r13+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d03:
	/* 0xd03: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_d0b:
	/* 0xd0b: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d0f:
	/* 0xd0f: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_d17:
	/* 0xd17: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1a:
	/* 0xd1a: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d22:
	/* 0xd22: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d24:
	/* 0xd24: mov    QWORD PTR [rsp+0xd8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d2c:
	/* 0xd2c: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d34:
	/* 0xd34: mov    QWORD PTR [rsp+0xb8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d3c:
	/* 0xd3c: jne    d46 <trace_security_mmap_file+0xd46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d46;
	}
x86_l_d3e:
	/* 0xd3e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d41:
	/* 0xd41: jmp    14d4 <trace_security_mmap_file+0x14d4> */
	return 5332ULL;
x86_l_d46:
	/* 0xd46: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d4d:
	/* 0xd4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d50:
	/* 0xd50: je     efb <trace_security_mmap_file+0xefb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_efb;
	}
x86_l_d56:
	/* 0xd56: movzx  ecx,BYTE PTR [r12+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d5f:
	/* 0xd5f: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d62:
	/* 0xd62: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d65:
	/* 0xd65: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d68:
	/* 0xd68: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_d6c:
	/* 0xd6c: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d6f:
	/* 0xd6f: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d72:
	/* 0xd72: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d79:
	/* 0xd79: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d7c:
	/* 0xd7c: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d83:
	/* 0xd83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d86:
	/* 0xd86: je     daf <trace_security_mmap_file+0xdaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_daf;
	}
x86_l_d88:
	/* 0xd88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8a:
	/* 0xd8a: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d92:
	/* 0xd92: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d99:
	/* 0xd99: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d9c:
	/* 0xd9c: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d9f:
	/* 0xd9f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_da2:
	/* 0xda2: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_da9:
	/* 0xda9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dac:
	/* 0xdac: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_daf:
	/* 0xdaf: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_db6:
	/* 0xdb6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: je     dd5 <trace_security_mmap_file+0xdd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd5;
	}
x86_l_dbb:
	/* 0xdbb: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_dbf:
	/* 0xdbf: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dc2:
	/* 0xdc2: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_dc5:
	/* 0xdc5: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_dc8:
	/* 0xdc8: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_dcf:
	/* 0xdcf: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dd2:
	/* 0xdd2: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dd5:
	/* 0xdd5: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_ddc:
	/* 0xddc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ddf:
	/* 0xddf: je     dfd <trace_security_mmap_file+0xdfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dfd;
	}
x86_l_de1:
	/* 0xde1: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_de4:
	/* 0xde4: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_de9:
	/* 0xde9: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ded:
	/* 0xded: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_df0:
	/* 0xdf0: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_df7:
	/* 0xdf7: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dfa:
	/* 0xdfa: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dfd:
	/* 0xdfd: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_e02:
	/* 0xe02: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_e09:
	/* 0xe09: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_e0c:
	/* 0xe0c: mov    WORD PTR [rsp+0x88],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e14:
	/* 0xe14: je     f60 <trace_security_mmap_file+0xf60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3936ULL;
	}
x86_l_e1a:
	/* 0xe1a: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e21:
	/* 0xe21: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e29:
	/* 0xe29: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e30:
	/* 0xe30: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e35:
	/* 0xe35: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e3c:
	/* 0xe3c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e41:
	/* 0xe41: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e46:
	/* 0xe46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e4b:
	/* 0xe4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e52:
	/* 0xe52: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e57:
	/* 0xe57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e59:
	/* 0xe59: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e5c:
	/* 0xe5c: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e60:
	/* 0xe60: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e65:
	/* 0xe65: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e6c:
	/* 0xe6c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: je     e91 <trace_security_mmap_file+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e91;
	}
x86_l_e71:
	/* 0xe71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e76:
	/* 0xe76: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e7b:
	/* 0xe7b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e7e:
	/* 0xe7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e80:
	/* 0xe80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e83:
	/* 0xe83: je     e91 <trace_security_mmap_file+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e91;
	}
x86_l_e85:
	/* 0xe85: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e88:
	/* 0xe88: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8c:
	/* 0xe8c: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e8f:
	/* 0xe8f: jmp    e94 <trace_security_mmap_file+0xe94> */
	goto x86_l_e94;
x86_l_e91:
	/* 0xe91: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e94:
	/* 0xe94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e99:
	/* 0xe99: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e9e:
	/* 0xe9e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea3:
	/* 0xea3: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_ea6:
	/* 0xea6: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ea9:
	/* 0xea9: jb     ec1 <trace_security_mmap_file+0xec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec1;
	}
x86_l_eab:
	/* 0xeab: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eaf:
	/* 0xeaf: je     eb6 <trace_security_mmap_file+0xeb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb6;
	}
x86_l_eb1:
	/* 0xeb1: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_eb4:
	/* 0xeb4: jbe    ec1 <trace_security_mmap_file+0xec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ec1;
	}
x86_l_eb6:
	/* 0xeb6: and    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_ebe:
	/* 0xebe: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec1:
	/* 0xec1: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ec5:
	/* 0xec5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eca:
	/* 0xeca: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ed1:
	/* 0xed1: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_ed4:
	/* 0xed4: je     f17 <trace_security_mmap_file+0xf17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3863ULL;
	}
x86_l_ed6:
	/* 0xed6: mov    QWORD PTR [rsp+0x70],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_edb:
	/* 0xedb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ee0:
	/* 0xee0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee5:
	/* 0xee5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eea:
	/* 0xeea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eed:
	/* 0xeed: je     f28 <trace_security_mmap_file+0xf28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3880ULL;
	}
x86_l_eef:
	/* 0xeef: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef2:
	/* 0xef2: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef6:
	/* 0xef6: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ef9:
	/* 0xef9: jmp    f2a <trace_security_mmap_file+0xf2a> */
	return 3882ULL;
x86_l_efb:
	/* 0xefb: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f02:
	/* 0xf02: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
	return 3849ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3849ULL: goto x86_l_f09;
	case 3852ULL: goto x86_l_f0c;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3865ULL: goto x86_l_f19;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3876ULL: goto x86_l_f24;
	case 3878ULL: goto x86_l_f26;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3887ULL: goto x86_l_f2f;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3905ULL: goto x86_l_f41;
	case 3909ULL: goto x86_l_f45;
	case 3911ULL: goto x86_l_f47;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3944ULL: goto x86_l_f68;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3957ULL: goto x86_l_f75;
	case 3961ULL: goto x86_l_f79;
	case 3968ULL: goto x86_l_f80;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3987ULL: goto x86_l_f93;
	case 3994ULL: goto x86_l_f9a;
	case 4002ULL: goto x86_l_fa2;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4060ULL: goto x86_l_fdc;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4077ULL: goto x86_l_fed;
	case 4079ULL: goto x86_l_fef;
	case 4081ULL: goto x86_l_ff1;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4097ULL: goto x86_l_1001;
	case 4105ULL: goto x86_l_1009;
	case 4107ULL: goto x86_l_100b;
	case 4115ULL: goto x86_l_1013;
	case 4123ULL: goto x86_l_101b;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4142ULL: goto x86_l_102e;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4149ULL: goto x86_l_1035;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4171ULL: goto x86_l_104b;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4258ULL: goto x86_l_10a2;
	case 4262ULL: goto x86_l_10a6;
	case 4269ULL: goto x86_l_10ad;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4310ULL: goto x86_l_10d6;
	case 4313ULL: goto x86_l_10d9;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4327ULL: goto x86_l_10e7;
	case 4329ULL: goto x86_l_10e9;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4341ULL: goto x86_l_10f5;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4354ULL: goto x86_l_1102;
	case 4357ULL: goto x86_l_1105;
	case 4360ULL: goto x86_l_1108;
	case 4368ULL: goto x86_l_1110;
	case 4374ULL: goto x86_l_1116;
	case 4381ULL: goto x86_l_111d;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4395ULL: goto x86_l_112b;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4412ULL: goto x86_l_113c;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4427ULL: goto x86_l_114b;
	case 4431ULL: goto x86_l_114f;
	case 4435ULL: goto x86_l_1153;
	case 4439ULL: goto x86_l_1157;
	case 4443ULL: goto x86_l_115b;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4490ULL: goto x86_l_118a;
	case 4494ULL: goto x86_l_118e;
	case 4501ULL: goto x86_l_1195;
	case 4508ULL: goto x86_l_119c;
	case 4511ULL: goto x86_l_119f;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4535ULL: goto x86_l_11b7;
	case 4542ULL: goto x86_l_11be;
	case 4545ULL: goto x86_l_11c1;
	case 4547ULL: goto x86_l_11c3;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4559ULL: goto x86_l_11cf;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4566ULL: goto x86_l_11d6;
	case 4569ULL: goto x86_l_11d9;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4592ULL: goto x86_l_11f0;
	case 4600ULL: goto x86_l_11f8;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4711ULL: goto x86_l_1267;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4757ULL: goto x86_l_1295;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4768ULL: goto x86_l_12a0;
	case 4770ULL: goto x86_l_12a2;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4778ULL: goto x86_l_12aa;
	case 4782ULL: goto x86_l_12ae;
	case 4785ULL: goto x86_l_12b1;
	case 4787ULL: goto x86_l_12b3;
	case 4789ULL: goto x86_l_12b5;
	case 4792ULL: goto x86_l_12b8;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4801ULL: goto x86_l_12c1;
	case 4809ULL: goto x86_l_12c9;
	case 4817ULL: goto x86_l_12d1;
	case 4823ULL: goto x86_l_12d7;
	case 4827ULL: goto x86_l_12db;
	case 4832ULL: goto x86_l_12e0;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4842ULL: goto x86_l_12ea;
	case 4849ULL: goto x86_l_12f1;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4883ULL: goto x86_l_1313;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4895ULL: goto x86_l_131f;
	case 4900ULL: goto x86_l_1324;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4911ULL: goto x86_l_132f;
	case 4913ULL: goto x86_l_1331;
	case 4916ULL: goto x86_l_1334;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4925ULL: goto x86_l_133d;
	case 4927ULL: goto x86_l_133f;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4939ULL: goto x86_l_134b;
	case 4947ULL: goto x86_l_1353;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4959ULL: goto x86_l_135f;
	case 4963ULL: goto x86_l_1363;
	case 4967ULL: goto x86_l_1367;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5026ULL: goto x86_l_13a2;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5036ULL: goto x86_l_13ac;
	case 5040ULL: goto x86_l_13b0;
	case 5043ULL: goto x86_l_13b3;
	case 5045ULL: goto x86_l_13b5;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	case 5071ULL: goto x86_l_13cf;
	case 5078ULL: goto x86_l_13d6;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5173ULL: goto x86_l_1435;
	case 5176ULL: goto x86_l_1438;
	case 5178ULL: goto x86_l_143a;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5219ULL: goto x86_l_1463;
	case 5222ULL: goto x86_l_1466;
	case 5224ULL: goto x86_l_1468;
	case 5227ULL: goto x86_l_146b;
	case 5232ULL: goto x86_l_1470;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5246ULL: goto x86_l_147e;
	case 5249ULL: goto x86_l_1481;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5268ULL: goto x86_l_1494;
	case 5270ULL: goto x86_l_1496;
	case 5273ULL: goto x86_l_1499;
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5292ULL: goto x86_l_14ac;
	case 5295ULL: goto x86_l_14af;
	case 5298ULL: goto x86_l_14b2;
	case 5301ULL: goto x86_l_14b5;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5332ULL: goto x86_l_14d4;
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5350ULL: goto x86_l_14e6;
	case 5358ULL: goto x86_l_14ee;
	case 5364ULL: goto x86_l_14f4;
	case 5372ULL: goto x86_l_14fc;
	case 5380ULL: goto x86_l_1504;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5397ULL: goto x86_l_1515;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5424ULL: goto x86_l_1530;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f09:
	/* 0xf09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0c:
	/* 0xf0c: jne    d88 <trace_security_mmap_file+0xd88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3464ULL;
	}
x86_l_f12:
	/* 0xf12: jmp    daf <trace_security_mmap_file+0xdaf> */
	return 3503ULL;
x86_l_f17:
	/* 0xf17: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f19:
	/* 0xf19: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f1c:
	/* 0xf1c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f21:
	/* 0xf21: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f24:
	/* 0xf24: jae    f41 <trace_security_mmap_file+0xf41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f41;
	}
x86_l_f26:
	/* 0xf26: jmp    f57 <trace_security_mmap_file+0xf57> */
	goto x86_l_f57;
x86_l_f28:
	/* 0xf28: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2a:
	/* 0xf2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f2f:
	/* 0xf2f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f34:
	/* 0xf34: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f37:
	/* 0xf37: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3c:
	/* 0xf3c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: jb     f57 <trace_security_mmap_file+0xf57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f57;
	}
x86_l_f41:
	/* 0xf41: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f45:
	/* 0xf45: je     f4c <trace_security_mmap_file+0xf4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f4c;
	}
x86_l_f47:
	/* 0xf47: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f4a:
	/* 0xf4a: jbe    f57 <trace_security_mmap_file+0xf57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f57;
	}
x86_l_f4c:
	/* 0xf4c: and    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_f54:
	/* 0xf54: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_f57:
	/* 0xf57: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_f5a:
	/* 0xf5a: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f5d:
	/* 0xf5d: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f60:
	/* 0xf60: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f68:
	/* 0xf68: je     100b <trace_security_mmap_file+0x100b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100b;
	}
x86_l_f6e:
	/* 0xf6e: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f73:
	/* 0xf73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f75:
	/* 0xf75: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f79:
	/* 0xf79: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_f80:
	/* 0xf80: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f87:
	/* 0xf87: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f8c:
	/* 0xf8c: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f93:
	/* 0xf93: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f9a:
	/* 0xf9a: movzx  eax,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_fa2:
	/* 0xfa2: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fa7:
	/* 0xfa7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fac:
	/* 0xfac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_fb3:
	/* 0xfb3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb8:
	/* 0xfb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fba:
	/* 0xfba: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fbe:
	/* 0xfbe: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc3:
	/* 0xfc3: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fca:
	/* 0xfca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fcd:
	/* 0xfcd: je     fef <trace_security_mmap_file+0xfef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fef;
	}
x86_l_fcf:
	/* 0xfcf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fd4:
	/* 0xfd4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd9:
	/* 0xfd9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fdc:
	/* 0xfdc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fde:
	/* 0xfde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe1:
	/* 0xfe1: je     fef <trace_security_mmap_file+0xfef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fef;
	}
x86_l_fe3:
	/* 0xfe3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe6:
	/* 0xfe6: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fea:
	/* 0xfea: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fed:
	/* 0xfed: jmp    ff1 <trace_security_mmap_file+0xff1> */
	goto x86_l_ff1;
x86_l_fef:
	/* 0xfef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ff1:
	/* 0xff1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ff4:
	/* 0xff4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ff9:
	/* 0xff9: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_ffc:
	/* 0xffc: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fff:
	/* 0xfff: jae    1022 <trace_security_mmap_file+0x1022> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1022;
	}
x86_l_1001:
	/* 0x1001: movzx  ebp,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_1009:
	/* 0x1009: jmp    103d <trace_security_mmap_file+0x103d> */
	goto x86_l_103d;
x86_l_100b:
	/* 0x100b: movzx  ebp,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_1013:
	/* 0x1013: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_101b:
	/* 0x101b: jne    1051 <trace_security_mmap_file+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1051;
	}
x86_l_101d:
	/* 0x101d: jmp    1108 <trace_security_mmap_file+0x1108> */
	goto x86_l_1108;
x86_l_1022:
	/* 0x1022: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1026:
	/* 0x1026: movzx  ebp,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_102e:
	/* 0x102e: je     1035 <trace_security_mmap_file+0x1035> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1035;
	}
x86_l_1030:
	/* 0x1030: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: jbe    103d <trace_security_mmap_file+0x103d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_103d;
	}
x86_l_1035:
	/* 0x1035: and    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_103a:
	/* 0x103a: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_103d:
	/* 0x103d: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1040:
	/* 0x1040: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1043:
	/* 0x1043: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_104b:
	/* 0x104b: je     1108 <trace_security_mmap_file+0x1108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1108;
	}
x86_l_1051:
	/* 0x1051: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1056:
	/* 0x1056: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_105d:
	/* 0x105d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1062:
	/* 0x1062: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1067:
	/* 0x1067: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_106c:
	/* 0x106c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106e:
	/* 0x106e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1073:
	/* 0x1073: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1077:
	/* 0x1077: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107c:
	/* 0x107c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1081:
	/* 0x1081: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1086:
	/* 0x1086: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1088:
	/* 0x1088: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_108d:
	/* 0x108d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1092:
	/* 0x1092: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1097:
	/* 0x1097: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_109c:
	/* 0x109c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109e:
	/* 0x109e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a2:
	/* 0x10a2: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10a6:
	/* 0x10a6: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_10ad:
	/* 0x10ad: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_10b4:
	/* 0x10b4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10b7:
	/* 0x10b7: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10bc:
	/* 0x10bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c1:
	/* 0x10c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_10c8:
	/* 0x10c8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10cd:
	/* 0x10cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cf:
	/* 0x10cf: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10d6:
	/* 0x10d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d9:
	/* 0x10d9: je     10fa <trace_security_mmap_file+0x10fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10fa;
	}
x86_l_10db:
	/* 0x10db: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10df:
	/* 0x10df: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10e4:
	/* 0x10e4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10e7:
	/* 0x10e7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10e9:
	/* 0x10e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: je     10fa <trace_security_mmap_file+0x10fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10fa;
	}
x86_l_10ee:
	/* 0x10ee: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f5:
	/* 0x10f5: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10f8:
	/* 0x10f8: jmp    10fc <trace_security_mmap_file+0x10fc> */
	goto x86_l_10fc;
x86_l_10fa:
	/* 0x10fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10fc:
	/* 0x10fc: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10ff:
	/* 0x10ff: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1102:
	/* 0x1102: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1105:
	/* 0x1105: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1108:
	/* 0x1108: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1110:
	/* 0x1110: je     11f0 <trace_security_mmap_file+0x11f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f0;
	}
x86_l_1116:
	/* 0x1116: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_111d:
	/* 0x111d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1121:
	/* 0x1121: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1126:
	/* 0x1126: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_112b:
	/* 0x112b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1130:
	/* 0x1130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1132:
	/* 0x1132: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1137:
	/* 0x1137: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_113c:
	/* 0x113c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1141:
	/* 0x1141: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1146:
	/* 0x1146: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1149:
	/* 0x1149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114b:
	/* 0x114b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_114f:
	/* 0x114f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1153:
	/* 0x1153: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1157:
	/* 0x1157: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_115b:
	/* 0x115b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1160:
	/* 0x1160: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1165:
	/* 0x1165: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116a:
	/* 0x116a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116c:
	/* 0x116c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1171:
	/* 0x1171: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1175:
	/* 0x1175: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_117a:
	/* 0x117a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_117f:
	/* 0x117f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1184:
	/* 0x1184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1186:
	/* 0x1186: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118a:
	/* 0x118a: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_118e:
	/* 0x118e: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1195:
	/* 0x1195: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_119c:
	/* 0x119c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_119f:
	/* 0x119f: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a4:
	/* 0x11a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a9:
	/* 0x11a9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_11b0:
	/* 0x11b0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b5:
	/* 0x11b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b7:
	/* 0x11b7: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11be:
	/* 0x11be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c1:
	/* 0x11c1: je     11e2 <trace_security_mmap_file+0x11e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e2;
	}
x86_l_11c3:
	/* 0x11c3: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11c7:
	/* 0x11c7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11cc:
	/* 0x11cc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11cf:
	/* 0x11cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11d1:
	/* 0x11d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d4:
	/* 0x11d4: je     11e2 <trace_security_mmap_file+0x11e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e2;
	}
x86_l_11d6:
	/* 0x11d6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d9:
	/* 0x11d9: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11dd:
	/* 0x11dd: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e0:
	/* 0x11e0: jmp    11e4 <trace_security_mmap_file+0x11e4> */
	goto x86_l_11e4;
x86_l_11e2:
	/* 0x11e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e4:
	/* 0x11e4: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11e7:
	/* 0x11e7: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_11ea:
	/* 0x11ea: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ed:
	/* 0x11ed: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11f0:
	/* 0x11f0: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11f8:
	/* 0x11f8: je     12c9 <trace_security_mmap_file+0x12c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c9;
	}
x86_l_11fe:
	/* 0x11fe: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1203:
	/* 0x1203: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_120a:
	/* 0x120a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_120f:
	/* 0x120f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1214:
	/* 0x1214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1219:
	/* 0x1219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121b:
	/* 0x121b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1220:
	/* 0x1220: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1225:
	/* 0x1225: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122a:
	/* 0x122a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_122f:
	/* 0x122f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1231:
	/* 0x1231: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1236:
	/* 0x1236: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_123b:
	/* 0x123b: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1240:
	/* 0x1240: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1243:
	/* 0x1243: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1248:
	/* 0x1248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124a:
	/* 0x124a: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_124e:
	/* 0x124e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1253:
	/* 0x1253: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1256:
	/* 0x1256: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_125b:
	/* 0x125b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_125e:
	/* 0x125e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1260:
	/* 0x1260: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1267:
	/* 0x1267: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_126e:
	/* 0x126e: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1271:
	/* 0x1271: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1276:
	/* 0x1276: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127b:
	/* 0x127b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1282:
	/* 0x1282: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1287:
	/* 0x1287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1289:
	/* 0x1289: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1290:
	/* 0x1290: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: je     12b3 <trace_security_mmap_file+0x12b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b3;
	}
x86_l_1295:
	/* 0x1295: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_129a:
	/* 0x129a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_129d:
	/* 0x129d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_12a0:
	/* 0x12a0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12a2:
	/* 0x12a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a5:
	/* 0x12a5: je     12b3 <trace_security_mmap_file+0x12b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b3;
	}
x86_l_12a7:
	/* 0x12a7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12aa:
	/* 0x12aa: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ae:
	/* 0x12ae: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12b1:
	/* 0x12b1: jmp    12b5 <trace_security_mmap_file+0x12b5> */
	goto x86_l_12b5;
x86_l_12b3:
	/* 0x12b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b5:
	/* 0x12b5: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12b8:
	/* 0x12b8: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12bb:
	/* 0x12bb: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12be:
	/* 0x12be: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_12c1:
	/* 0x12c1: movzx  ebp,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_12c9:
	/* 0x12c9: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12d1:
	/* 0x12d1: je     1353 <trace_security_mmap_file+0x1353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1353;
	}
x86_l_12d7:
	/* 0x12d7: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12db:
	/* 0x12db: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12e0:
	/* 0x12e0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12e3:
	/* 0x12e3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12e8:
	/* 0x12e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ea:
	/* 0x12ea: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12f1:
	/* 0x12f1: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12f8:
	/* 0x12f8: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12fb:
	/* 0x12fb: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1300:
	/* 0x1300: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1305:
	/* 0x1305: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_130c:
	/* 0x130c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1311:
	/* 0x1311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1313:
	/* 0x1313: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_131a:
	/* 0x131a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_131d:
	/* 0x131d: je     133d <trace_security_mmap_file+0x133d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133d;
	}
x86_l_131f:
	/* 0x131f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1324:
	/* 0x1324: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1327:
	/* 0x1327: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_132a:
	/* 0x132a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_132c:
	/* 0x132c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_132f:
	/* 0x132f: je     133d <trace_security_mmap_file+0x133d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133d;
	}
x86_l_1331:
	/* 0x1331: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1334:
	/* 0x1334: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1338:
	/* 0x1338: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_133b:
	/* 0x133b: jmp    133f <trace_security_mmap_file+0x133f> */
	goto x86_l_133f;
x86_l_133d:
	/* 0x133d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133f:
	/* 0x133f: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1342:
	/* 0x1342: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1345:
	/* 0x1345: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1348:
	/* 0x1348: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_134b:
	/* 0x134b: movzx  ebp,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_1353:
	/* 0x1353: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_135a:
	/* 0x135a: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_135d:
	/* 0x135d: je     13c3 <trace_security_mmap_file+0x13c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13c3;
	}
x86_l_135f:
	/* 0x135f: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1363:
	/* 0x1363: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1367:
	/* 0x1367: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_136e:
	/* 0x136e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1371:
	/* 0x1371: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1376:
	/* 0x1376: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137b:
	/* 0x137b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1382:
	/* 0x1382: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1390:
	/* 0x1390: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1393:
	/* 0x1393: je     13b5 <trace_security_mmap_file+0x13b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b5;
	}
x86_l_1395:
	/* 0x1395: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_139a:
	/* 0x139a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_139f:
	/* 0x139f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13a2:
	/* 0x13a2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13a4:
	/* 0x13a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13a7:
	/* 0x13a7: je     13b5 <trace_security_mmap_file+0x13b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b5;
	}
x86_l_13a9:
	/* 0x13a9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ac:
	/* 0x13ac: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b0:
	/* 0x13b0: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13b3:
	/* 0x13b3: jmp    13b7 <trace_security_mmap_file+0x13b7> */
	goto x86_l_13b7;
x86_l_13b5:
	/* 0x13b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b7:
	/* 0x13b7: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ba:
	/* 0x13ba: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_13bd:
	/* 0x13bd: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13c0:
	/* 0x13c0: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13c3:
	/* 0x13c3: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13ca:
	/* 0x13ca: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13cd:
	/* 0x13cd: je     142e <trace_security_mmap_file+0x142e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_142e;
	}
x86_l_13cf:
	/* 0x13cf: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13d6:
	/* 0x13d6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d9:
	/* 0x13d9: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13de:
	/* 0x13de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e3:
	/* 0x13e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13ea:
	/* 0x13ea: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13ef:
	/* 0x13ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f1:
	/* 0x13f1: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13f8:
	/* 0x13f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: je     1420 <trace_security_mmap_file+0x1420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1420;
	}
x86_l_13fd:
	/* 0x13fd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1402:
	/* 0x1402: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1405:
	/* 0x1405: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_140d:
	/* 0x140d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_140f:
	/* 0x140f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1412:
	/* 0x1412: je     1420 <trace_security_mmap_file+0x1420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1420;
	}
x86_l_1414:
	/* 0x1414: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1417:
	/* 0x1417: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_141b:
	/* 0x141b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_141e:
	/* 0x141e: jmp    1422 <trace_security_mmap_file+0x1422> */
	goto x86_l_1422;
x86_l_1420:
	/* 0x1420: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1422:
	/* 0x1422: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1425:
	/* 0x1425: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1428:
	/* 0x1428: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_142b:
	/* 0x142b: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_142e:
	/* 0x142e: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1435:
	/* 0x1435: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1438:
	/* 0x1438: je     14b5 <trace_security_mmap_file+0x14b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b5;
	}
x86_l_143a:
	/* 0x143a: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1441:
	/* 0x1441: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1444:
	/* 0x1444: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1449:
	/* 0x1449: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144e:
	/* 0x144e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1455:
	/* 0x1455: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_145a:
	/* 0x145a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145c:
	/* 0x145c: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1463:
	/* 0x1463: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1466:
	/* 0x1466: je     14a7 <trace_security_mmap_file+0x14a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a7;
	}
x86_l_1468:
	/* 0x1468: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_146b:
	/* 0x146b: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1470:
	/* 0x1470: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1474:
	/* 0x1474: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1479:
	/* 0x1479: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_147c:
	/* 0x147c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147e:
	/* 0x147e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1481:
	/* 0x1481: jne    149b <trace_security_mmap_file+0x149b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_149b;
	}
x86_l_1483:
	/* 0x1483: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1488:
	/* 0x1488: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_148c:
	/* 0x148c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1491:
	/* 0x1491: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1494:
	/* 0x1494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1496:
	/* 0x1496: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1499:
	/* 0x1499: je     14a7 <trace_security_mmap_file+0x14a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a7;
	}
x86_l_149b:
	/* 0x149b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149e:
	/* 0x149e: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a2:
	/* 0x14a2: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14a5:
	/* 0x14a5: jmp    14a9 <trace_security_mmap_file+0x14a9> */
	goto x86_l_14a9;
x86_l_14a7:
	/* 0x14a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a9:
	/* 0x14a9: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_14ac:
	/* 0x14ac: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_14af:
	/* 0x14af: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14b2:
	/* 0x14b2: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_14b5:
	/* 0x14b5: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14bc:
	/* 0x14bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14bf:
	/* 0x14bf: je     14cd <trace_security_mmap_file+0x14cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cd;
	}
x86_l_14c1:
	/* 0x14c1: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14c6:
	/* 0x14c6: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14ca:
	/* 0x14ca: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14cd:
	/* 0x14cd: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14d4:
	/* 0x14d4: lea    rax,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_14db:
	/* 0x14db: lea    rbx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14df:
	/* 0x14df: and    QWORD PTR [r14+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_14e6:
	/* 0x14e6: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14ee:
	/* 0x14ee: je     167e <trace_security_mmap_file+0x167e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5758ULL;
	}
x86_l_14f4:
	/* 0x14f4: test   BYTE PTR [rsp+0xe8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 996432412676ULL);
x86_l_14fc:
	/* 0x14fc: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1504:
	/* 0x1504: je     1677 <trace_security_mmap_file+0x1677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5751ULL;
	}
x86_l_150a:
	/* 0x150a: cmp    DWORD PTR [r14+0x74],0x9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206345ULL);
x86_l_150f:
	/* 0x150f: jne    1677 <trace_security_mmap_file+0x1677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5751ULL;
	}
x86_l_1515:
	/* 0x1515: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_151d:
	/* 0x151d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1522:
	/* 0x1522: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_1529:
	/* 0x1529: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_152e:
	/* 0x152e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1530:
	/* 0x1530: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 5427ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5427ULL: goto x86_l_1533;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5452ULL: goto x86_l_154c;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5516ULL: goto x86_l_158c;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5636ULL: goto x86_l_1604;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	case 5650ULL: goto x86_l_1612;
	case 5654ULL: goto x86_l_1616;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5671ULL: goto x86_l_1627;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5690ULL: goto x86_l_163a;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5732ULL: goto x86_l_1664;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5760ULL: goto x86_l_1680;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5800ULL: goto x86_l_16a8;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5821ULL: goto x86_l_16bd;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5835ULL: goto x86_l_16cb;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5891ULL: goto x86_l_1703;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5974ULL: goto x86_l_1756;
	case 5976ULL: goto x86_l_1758;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 5997ULL: goto x86_l_176d;
	case 6001ULL: goto x86_l_1771;
	case 6003ULL: goto x86_l_1773;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6014ULL: goto x86_l_177e;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6106ULL: goto x86_l_17da;
	case 6113ULL: goto x86_l_17e1;
	case 6116ULL: goto x86_l_17e4;
	case 6124ULL: goto x86_l_17ec;
	case 6130ULL: goto x86_l_17f2;
	case 6132ULL: goto x86_l_17f4;
	case 6141ULL: goto x86_l_17fd;
	case 6149ULL: goto x86_l_1805;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6177ULL: goto x86_l_1821;
	case 6181ULL: goto x86_l_1825;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6202ULL: goto x86_l_183a;
	case 6210ULL: goto x86_l_1842;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6227ULL: goto x86_l_1853;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6246ULL: goto x86_l_1866;
	case 6253ULL: goto x86_l_186d;
	case 6261ULL: goto x86_l_1875;
	case 6268ULL: goto x86_l_187c;
	case 6270ULL: goto x86_l_187e;
	case 6279ULL: goto x86_l_1887;
	case 6285ULL: goto x86_l_188d;
	case 6287ULL: goto x86_l_188f;
	case 6295ULL: goto x86_l_1897;
	case 6299ULL: goto x86_l_189b;
	case 6303ULL: goto x86_l_189f;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6327ULL: goto x86_l_18b7;
	case 6330ULL: goto x86_l_18ba;
	case 6338ULL: goto x86_l_18c2;
	case 6345ULL: goto x86_l_18c9;
	case 6353ULL: goto x86_l_18d1;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6371ULL: goto x86_l_18e3;
	case 6377ULL: goto x86_l_18e9;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6410ULL: goto x86_l_190a;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6418ULL: goto x86_l_1912;
	case 6426ULL: goto x86_l_191a;
	case 6433ULL: goto x86_l_1921;
	case 6441ULL: goto x86_l_1929;
	case 6448ULL: goto x86_l_1930;
	case 6450ULL: goto x86_l_1932;
	case 6459ULL: goto x86_l_193b;
	case 6465ULL: goto x86_l_1941;
	case 6467ULL: goto x86_l_1943;
	case 6471ULL: goto x86_l_1947;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6498ULL: goto x86_l_1962;
	case 6501ULL: goto x86_l_1965;
	case 6503ULL: goto x86_l_1967;
	case 6506ULL: goto x86_l_196a;
	case 6514ULL: goto x86_l_1972;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	case 6534ULL: goto x86_l_1986;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6564ULL: goto x86_l_19a4;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6594ULL: goto x86_l_19c2;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6607ULL: goto x86_l_19cf;
	case 6614ULL: goto x86_l_19d6;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6729ULL: goto x86_l_1a49;
	case 6733ULL: goto x86_l_1a4d;
	case 6737ULL: goto x86_l_1a51;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6784ULL: goto x86_l_1a80;
	case 6786ULL: goto x86_l_1a82;
	case 6790ULL: goto x86_l_1a86;
	case 6794ULL: goto x86_l_1a8a;
	case 6798ULL: goto x86_l_1a8e;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6823ULL: goto x86_l_1aa7;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6845ULL: goto x86_l_1abd;
	case 6847ULL: goto x86_l_1abf;
	case 6852ULL: goto x86_l_1ac4;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6906ULL: goto x86_l_1afa;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6931ULL: goto x86_l_1b13;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6982ULL: goto x86_l_1b46;
	case 6984ULL: goto x86_l_1b48;
	case 6988ULL: goto x86_l_1b4c;
	case 6992ULL: goto x86_l_1b50;
	case 6996ULL: goto x86_l_1b54;
	case 7000ULL: goto x86_l_1b58;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7043ULL: goto x86_l_1b83;
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7109ULL: goto x86_l_1bc5;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7156ULL: goto x86_l_1bf4;
	case 7160ULL: goto x86_l_1bf8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1533:
	/* 0x1533: mov    QWORD PTR [rsp+0x98],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_153b:
	/* 0x153b: je     168d <trace_security_mmap_file+0x168d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168d;
	}
x86_l_1541:
	/* 0x1541: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1544:
	/* 0x1544: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_154c:
	/* 0x154c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1550:
	/* 0x1550: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1555:
	/* 0x1555: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_155a:
	/* 0x155a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_155f:
	/* 0x155f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1561:
	/* 0x1561: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1566:
	/* 0x1566: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_156b:
	/* 0x156b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1570:
	/* 0x1570: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1575:
	/* 0x1575: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157a:
	/* 0x157a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_157f:
	/* 0x157f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1581:
	/* 0x1581: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_1586:
	/* 0x1586: jne    1694 <trace_security_mmap_file+0x1694> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1694;
	}
x86_l_158c:
	/* 0x158c: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1590:
	/* 0x1590: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1595:
	/* 0x1595: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_159a:
	/* 0x159a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_159f:
	/* 0x159f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a1:
	/* 0x15a1: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a6:
	/* 0x15a6: lea    rax,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_15aa:
	/* 0x15aa: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ae:
	/* 0x15ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15b3:
	/* 0x15b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b7:
	/* 0x15b7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15bc:
	/* 0x15bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c1:
	/* 0x15c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c3:
	/* 0x15c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15c8:
	/* 0x15c8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15cd:
	/* 0x15cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15d2:
	/* 0x15d2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_15d5:
	/* 0x15d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d7:
	/* 0x15d7: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15dc:
	/* 0x15dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e1:
	/* 0x15e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15ea:
	/* 0x15ea: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15ef:
	/* 0x15ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15f4:
	/* 0x15f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f6:
	/* 0x15f6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15fb:
	/* 0x15fb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: je     16a5 <trace_security_mmap_file+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16a5;
	}
x86_l_1604:
	/* 0x1604: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1609:
	/* 0x1609: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: je     16a5 <trace_security_mmap_file+0x16a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16a5;
	}
x86_l_1612:
	/* 0x1612: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1616:
	/* 0x1616: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_161b:
	/* 0x161b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1620:
	/* 0x1620: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1625:
	/* 0x1625: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1627:
	/* 0x1627: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_162b:
	/* 0x162b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1630:
	/* 0x1630: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1632:
	/* 0x1632: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1638:
	/* 0x1638: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_163a:
	/* 0x163a: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_163c:
	/* 0x163c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1642:
	/* 0x1642: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1645:
	/* 0x1645: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_164a:
	/* 0x164a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164c:
	/* 0x164c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_164f:
	/* 0x164f: jl     17a9 <trace_security_mmap_file+0x17a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_17a9;
	}
x86_l_1655:
	/* 0x1655: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165d:
	/* 0x165d: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_1664:
	/* 0x1664: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_166a:
	/* 0x166a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_166d:
	/* 0x166d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1672:
	/* 0x1672: jmp    1711 <trace_security_mmap_file+0x1711> */
	goto x86_l_1711;
x86_l_1677:
	/* 0x1677: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1679:
	/* 0x1679: jmp    1e44 <trace_security_mmap_file+0x1e44> */
	return 7748ULL;
x86_l_167e:
	/* 0x167e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1680:
	/* 0x1680: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1688:
	/* 0x1688: jmp    1e44 <trace_security_mmap_file+0x1e44> */
	return 7748ULL;
x86_l_168d:
	/* 0x168d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168f:
	/* 0x168f: jmp    17e4 <trace_security_mmap_file+0x17e4> */
	goto x86_l_17e4;
x86_l_1694:
	/* 0x1694: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1699:
	/* 0x1699: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_16a0:
	/* 0x16a0: jmp    17cd <trace_security_mmap_file+0x17cd> */
	goto x86_l_17cd;
x86_l_16a5:
	/* 0x16a5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16a8:
	/* 0x16a8: jne    17a9 <trace_security_mmap_file+0x17a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17a9;
	}
x86_l_16ae:
	/* 0x16ae: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b2:
	/* 0x16b2: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_16b7:
	/* 0x16b7: je     17a9 <trace_security_mmap_file+0x17a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a9;
	}
x86_l_16bd:
	/* 0x16bd: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c2:
	/* 0x16c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16c7:
	/* 0x16c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16cb:
	/* 0x16cb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16cf:
	/* 0x16cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d4:
	/* 0x16d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d9:
	/* 0x16d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16db:
	/* 0x16db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16e0:
	/* 0x16e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e4:
	/* 0x16e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16e7:
	/* 0x16e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ec:
	/* 0x16ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ee:
	/* 0x16ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16f3:
	/* 0x16f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f7:
	/* 0x16f7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16fc:
	/* 0x16fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1701:
	/* 0x1701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1703:
	/* 0x1703: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1707:
	/* 0x1707: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_170b:
	/* 0x170b: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_1711:
	/* 0x1711: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1716:
	/* 0x1716: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_171b:
	/* 0x171b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1720:
	/* 0x1720: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1725:
	/* 0x1725: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_172a:
	/* 0x172a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172f:
	/* 0x172f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1733:
	/* 0x1733: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1738:
	/* 0x1738: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173d:
	/* 0x173d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1742:
	/* 0x1742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1744:
	/* 0x1744: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1749:
	/* 0x1749: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_174c:
	/* 0x174c: je     178e <trace_security_mmap_file+0x178e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_178e;
	}
x86_l_174e:
	/* 0x174e: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1753:
	/* 0x1753: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1756:
	/* 0x1756: je     178e <trace_security_mmap_file+0x178e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_178e;
	}
x86_l_1758:
	/* 0x1758: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_175c:
	/* 0x175c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1761:
	/* 0x1761: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1766:
	/* 0x1766: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_176b:
	/* 0x176b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176d:
	/* 0x176d: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1771:
	/* 0x1771: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1773:
	/* 0x1773: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1779:
	/* 0x1779: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_177c:
	/* 0x177c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_177e:
	/* 0x177e: jae    2f70 <trace_security_mmap_file+0x2f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12144ULL;
	}
x86_l_1784:
	/* 0x1784: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1789:
	/* 0x1789: jmp    29b3 <trace_security_mmap_file+0x29b3> */
	return 10675ULL;
x86_l_178e:
	/* 0x178e: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1791:
	/* 0x1791: je     2fac <trace_security_mmap_file+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12204ULL;
	}
x86_l_1797:
	/* 0x1797: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_179c:
	/* 0x179c: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_17a3:
	/* 0x17a3: jne    29b3 <trace_security_mmap_file+0x29b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10675ULL;
	}
x86_l_17a9:
	/* 0x17a9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ae:
	/* 0x17ae: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17b2:
	/* 0x17b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17b7:
	/* 0x17b7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17bc:
	/* 0x17bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17c1:
	/* 0x17c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c3:
	/* 0x17c3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17c8:
	/* 0x17c8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_17cd:
	/* 0x17cd: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_17d0:
	/* 0x17d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17d5:
	/* 0x17d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d7:
	/* 0x17d7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17da:
	/* 0x17da: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_17e1:
	/* 0x17e1: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17e4:
	/* 0x17e4: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17ec:
	/* 0x17ec: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_17f2:
	/* 0x17f2: ja     186d <trace_security_mmap_file+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_186d;
	}
x86_l_17f4:
	/* 0x17f4: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_17fd:
	/* 0x17fd: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1805:
	/* 0x1805: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_180d:
	/* 0x180d: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1812:
	/* 0x1812: ja     186d <trace_security_mmap_file+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_186d;
	}
x86_l_1814:
	/* 0x1814: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1819:
	/* 0x1819: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1821:
	/* 0x1821: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1825:
	/* 0x1825: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_182c:
	/* 0x182c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1831:
	/* 0x1831: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1834:
	/* 0x1834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1836:
	/* 0x1836: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1838:
	/* 0x1838: jle    186d <trace_security_mmap_file+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_186d;
	}
x86_l_183a:
	/* 0x183a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1842:
	/* 0x1842: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1849:
	/* 0x1849: ja     186d <trace_security_mmap_file+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_186d;
	}
x86_l_184b:
	/* 0x184b: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1853:
	/* 0x1853: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_185b:
	/* 0x185b: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_185e:
	/* 0x185e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1866:
	/* 0x1866: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_186d:
	/* 0x186d: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1875:
	/* 0x1875: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_187c:
	/* 0x187c: ja     18c9 <trace_security_mmap_file+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c9;
	}
x86_l_187e:
	/* 0x187e: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1887:
	/* 0x1887: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_188d:
	/* 0x188d: ja     18c9 <trace_security_mmap_file+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c9;
	}
x86_l_188f:
	/* 0x188f: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1897:
	/* 0x1897: lea    rdx,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_189b:
	/* 0x189b: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_189f:
	/* 0x189f: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_18a6:
	/* 0x18a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ab:
	/* 0x18ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b0:
	/* 0x18b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b2:
	/* 0x18b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b5:
	/* 0x18b5: js     18c9 <trace_security_mmap_file+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18c9;
	}
x86_l_18b7:
	/* 0x18b7: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_18ba:
	/* 0x18ba: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_18c2:
	/* 0x18c2: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_18c9:
	/* 0x18c9: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18d1:
	/* 0x18d1: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_18d8:
	/* 0x18d8: ja     1921 <trace_security_mmap_file+0x1921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1921;
	}
x86_l_18da:
	/* 0x18da: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_18e3:
	/* 0x18e3: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_18e9:
	/* 0x18e9: ja     1921 <trace_security_mmap_file+0x1921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1921;
	}
x86_l_18eb:
	/* 0x18eb: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18ef:
	/* 0x18ef: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_18f6:
	/* 0x18f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18fb:
	/* 0x18fb: lea    rdx,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1903:
	/* 0x1903: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1908:
	/* 0x1908: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190a:
	/* 0x190a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_190d:
	/* 0x190d: js     1921 <trace_security_mmap_file+0x1921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1921;
	}
x86_l_190f:
	/* 0x190f: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1912:
	/* 0x1912: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_191a:
	/* 0x191a: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1921:
	/* 0x1921: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1929:
	/* 0x1929: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1930:
	/* 0x1930: ja     1979 <trace_security_mmap_file+0x1979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1979;
	}
x86_l_1932:
	/* 0x1932: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_193b:
	/* 0x193b: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1941:
	/* 0x1941: ja     1979 <trace_security_mmap_file+0x1979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1979;
	}
x86_l_1943:
	/* 0x1943: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1947:
	/* 0x1947: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_194e:
	/* 0x194e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1953:
	/* 0x1953: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_195b:
	/* 0x195b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1960:
	/* 0x1960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1962:
	/* 0x1962: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1965:
	/* 0x1965: js     1979 <trace_security_mmap_file+0x1979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1979;
	}
x86_l_1967:
	/* 0x1967: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_196a:
	/* 0x196a: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1972:
	/* 0x1972: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1979:
	/* 0x1979: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197e:
	/* 0x197e: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1986:
	/* 0x1986: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_198d:
	/* 0x198d: ja     19d6 <trace_security_mmap_file+0x19d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19d6;
	}
x86_l_198f:
	/* 0x198f: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1998:
	/* 0x1998: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_199e:
	/* 0x199e: ja     19d6 <trace_security_mmap_file+0x19d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19d6;
	}
x86_l_19a0:
	/* 0x19a0: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19a4:
	/* 0x19a4: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_19ab:
	/* 0x19ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b0:
	/* 0x19b0: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_19b8:
	/* 0x19b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19bd:
	/* 0x19bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bf:
	/* 0x19bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c2:
	/* 0x19c2: js     19d6 <trace_security_mmap_file+0x19d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19d6;
	}
x86_l_19c4:
	/* 0x19c4: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_19c7:
	/* 0x19c7: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19cf:
	/* 0x19cf: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_19d6:
	/* 0x19d6: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_19dd:
	/* 0x19dd: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19e1:
	/* 0x19e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19e6:
	/* 0x19e6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19eb:
	/* 0x19eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f0:
	/* 0x19f0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19f3:
	/* 0x19f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f5:
	/* 0x19f5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19fa:
	/* 0x19fa: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19ff:
	/* 0x19ff: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a03:
	/* 0x1a03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a08:
	/* 0x1a08: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a12:
	/* 0x1a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a14:
	/* 0x1a14: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a19:
	/* 0x1a19: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a22:
	/* 0x1a22: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a27:
	/* 0x1a27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a2c:
	/* 0x1a2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2e:
	/* 0x1a2e: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a33:
	/* 0x1a33: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a38:
	/* 0x1a38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a3d:
	/* 0x1a3d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a42:
	/* 0x1a42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a47:
	/* 0x1a47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a49:
	/* 0x1a49: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a51:
	/* 0x1a51: lea    r13,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a55:
	/* 0x1a55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a5a:
	/* 0x1a5a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a64:
	/* 0x1a64: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a67:
	/* 0x1a67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a69:
	/* 0x1a69: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a73:
	/* 0x1a73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a78:
	/* 0x1a78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a80:
	/* 0x1a80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a82:
	/* 0x1a82: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a86:
	/* 0x1a86: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a8a:
	/* 0x1a8a: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1a8e:
	/* 0x1a8e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a92:
	/* 0x1a92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a97:
	/* 0x1a97: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa1:
	/* 0x1aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa3:
	/* 0x1aa3: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1aab:
	/* 0x1aab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab0:
	/* 0x1ab0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aba:
	/* 0x1aba: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1abd:
	/* 0x1abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abf:
	/* 0x1abf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ac4:
	/* 0x1ac4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1acd:
	/* 0x1acd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad7:
	/* 0x1ad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad9:
	/* 0x1ad9: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ade:
	/* 0x1ade: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae3:
	/* 0x1ae3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aed:
	/* 0x1aed: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1af0:
	/* 0x1af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af2:
	/* 0x1af2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1af6:
	/* 0x1af6: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1afa:
	/* 0x1afa: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1afe:
	/* 0x1afe: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b02:
	/* 0x1b02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b07:
	/* 0x1b07: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b11:
	/* 0x1b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b13:
	/* 0x1b13: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b17:
	/* 0x1b17: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b20:
	/* 0x1b20: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b25:
	/* 0x1b25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b2d:
	/* 0x1b2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2f:
	/* 0x1b2f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b34:
	/* 0x1b34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b39:
	/* 0x1b39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b43:
	/* 0x1b43: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b46:
	/* 0x1b46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b48:
	/* 0x1b48: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b4c:
	/* 0x1b4c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b50:
	/* 0x1b50: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b54:
	/* 0x1b54: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b58:
	/* 0x1b58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b5d:
	/* 0x1b5d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b62:
	/* 0x1b62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b67:
	/* 0x1b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b69:
	/* 0x1b69: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b6e:
	/* 0x1b6e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b72:
	/* 0x1b72: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b77:
	/* 0x1b77: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b81:
	/* 0x1b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b83:
	/* 0x1b83: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b87:
	/* 0x1b87: lea    r15,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b91:
	/* 0x1b91: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b96:
	/* 0x1b96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b9e:
	/* 0x1b9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba0:
	/* 0x1ba0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1baa:
	/* 0x1baa: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1baf:
	/* 0x1baf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bb7:
	/* 0x1bb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb9:
	/* 0x1bb9: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bbd:
	/* 0x1bbd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1bc1:
	/* 0x1bc1: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1bc5:
	/* 0x1bc5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bce:
	/* 0x1bce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd8:
	/* 0x1bd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bda:
	/* 0x1bda: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bdf:
	/* 0x1bdf: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1be3:
	/* 0x1be3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be8:
	/* 0x1be8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bed:
	/* 0x1bed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf2:
	/* 0x1bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf4:
	/* 0x1bf4: cmp    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_1bf8:
	/* 0x1bf8: jne    1c50 <trace_security_mmap_file+0x1c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7248ULL;
	}
	return 7162ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7205ULL: goto x86_l_1c25;
	case 7207ULL: goto x86_l_1c27;
	case 7211ULL: goto x86_l_1c2b;
	case 7215ULL: goto x86_l_1c2f;
	case 7219ULL: goto x86_l_1c33;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7248ULL: goto x86_l_1c50;
	case 7252ULL: goto x86_l_1c54;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7277ULL: goto x86_l_1c6d;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7325ULL: goto x86_l_1c9d;
	case 7327ULL: goto x86_l_1c9f;
	case 7331ULL: goto x86_l_1ca3;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7346ULL: goto x86_l_1cb2;
	case 7350ULL: goto x86_l_1cb6;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7480ULL: goto x86_l_1d38;
	case 7488ULL: goto x86_l_1d40;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7594ULL: goto x86_l_1daa;
	case 7599ULL: goto x86_l_1daf;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7620ULL: goto x86_l_1dc4;
	case 7623ULL: goto x86_l_1dc7;
	case 7625ULL: goto x86_l_1dc9;
	case 7633ULL: goto x86_l_1dd1;
	case 7639ULL: goto x86_l_1dd7;
	case 7647ULL: goto x86_l_1ddf;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7680ULL: goto x86_l_1e00;
	case 7684ULL: goto x86_l_1e04;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7705ULL: goto x86_l_1e19;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7740ULL: goto x86_l_1e3c;
	case 7748ULL: goto x86_l_1e44;
	case 7756ULL: goto x86_l_1e4c;
	case 7766ULL: goto x86_l_1e56;
	case 7774ULL: goto x86_l_1e5e;
	case 7782ULL: goto x86_l_1e66;
	case 7790ULL: goto x86_l_1e6e;
	case 7798ULL: goto x86_l_1e76;
	case 7806ULL: goto x86_l_1e7e;
	case 7814ULL: goto x86_l_1e86;
	case 7822ULL: goto x86_l_1e8e;
	case 7830ULL: goto x86_l_1e96;
	case 7837ULL: goto x86_l_1e9d;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7861ULL: goto x86_l_1eb5;
	case 7866ULL: goto x86_l_1eba;
	case 7871ULL: goto x86_l_1ebf;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7912ULL: goto x86_l_1ee8;
	case 7918ULL: goto x86_l_1eee;
	case 7922ULL: goto x86_l_1ef2;
	case 7929ULL: goto x86_l_1ef9;
	case 7932ULL: goto x86_l_1efc;
	case 7939ULL: goto x86_l_1f03;
	case 7946ULL: goto x86_l_1f0a;
	case 7950ULL: goto x86_l_1f0e;
	case 7957ULL: goto x86_l_1f15;
	case 7961ULL: goto x86_l_1f19;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7979ULL: goto x86_l_1f2b;
	case 7983ULL: goto x86_l_1f2f;
	case 7990ULL: goto x86_l_1f36;
	case 7994ULL: goto x86_l_1f3a;
	case 7998ULL: goto x86_l_1f3e;
	case 8005ULL: goto x86_l_1f45;
	case 8012ULL: goto x86_l_1f4c;
	case 8016ULL: goto x86_l_1f50;
	case 8020ULL: goto x86_l_1f54;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8043ULL: goto x86_l_1f6b;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8061ULL: goto x86_l_1f7d;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8078ULL: goto x86_l_1f8e;
	case 8085ULL: goto x86_l_1f95;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8098ULL: goto x86_l_1fa2;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8121ULL: goto x86_l_1fb9;
	case 8124ULL: goto x86_l_1fbc;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8136ULL: goto x86_l_1fc8;
	case 8143ULL: goto x86_l_1fcf;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8152ULL: goto x86_l_1fd8;
	case 8159ULL: goto x86_l_1fdf;
	case 8162ULL: goto x86_l_1fe2;
	case 8165ULL: goto x86_l_1fe5;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8187ULL: goto x86_l_1ffb;
	case 8190ULL: goto x86_l_1ffe;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8215ULL: goto x86_l_2017;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8274ULL: goto x86_l_2052;
	case 8281ULL: goto x86_l_2059;
	case 8289ULL: goto x86_l_2061;
	case 8296ULL: goto x86_l_2068;
	case 8304ULL: goto x86_l_2070;
	case 8311ULL: goto x86_l_2077;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8336ULL: goto x86_l_2090;
	case 8341ULL: goto x86_l_2095;
	case 8343ULL: goto x86_l_2097;
	case 8346ULL: goto x86_l_209a;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8387ULL: goto x86_l_20c3;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8401ULL: goto x86_l_20d1;
	case 8409ULL: goto x86_l_20d9;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8430ULL: goto x86_l_20ee;
	case 8434ULL: goto x86_l_20f2;
	case 8436ULL: goto x86_l_20f4;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8449ULL: goto x86_l_2101;
	case 8452ULL: goto x86_l_2104;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8468ULL: goto x86_l_2114;
	case 8471ULL: goto x86_l_2117;
	case 8473ULL: goto x86_l_2119;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8504ULL: goto x86_l_2138;
	case 8508ULL: goto x86_l_213c;
	case 8511ULL: goto x86_l_213f;
	case 8513ULL: goto x86_l_2141;
	case 8520ULL: goto x86_l_2148;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8547ULL: goto x86_l_2163;
	case 8555ULL: goto x86_l_216b;
	case 8563ULL: goto x86_l_2173;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8576ULL: goto x86_l_2180;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8595ULL: goto x86_l_2193;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8637ULL: goto x86_l_21bd;
	case 8644ULL: goto x86_l_21c4;
	case 8651ULL: goto x86_l_21cb;
	case 8659ULL: goto x86_l_21d3;
	case 8666ULL: goto x86_l_21da;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8702ULL: goto x86_l_21fe;
	case 8706ULL: goto x86_l_2202;
	case 8711ULL: goto x86_l_2207;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8741ULL: goto x86_l_2225;
	case 8743ULL: goto x86_l_2227;
	case 8746ULL: goto x86_l_222a;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8784ULL: goto x86_l_2250;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8804ULL: goto x86_l_2264;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8827ULL: goto x86_l_227b;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bfa:
	/* 0x1bfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bff:
	/* 0x1bff: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c04:
	/* 0x1c04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c09:
	/* 0x1c09: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c0c:
	/* 0x1c0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0e:
	/* 0x1c0e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c13:
	/* 0x1c13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c18:
	/* 0x1c18: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c22:
	/* 0x1c22: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c25:
	/* 0x1c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c27:
	/* 0x1c27: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c2b:
	/* 0x1c2b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1c2f:
	/* 0x1c2f: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c33:
	/* 0x1c33: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c37:
	/* 0x1c37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c3c:
	/* 0x1c3c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c41:
	/* 0x1c41: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c46:
	/* 0x1c46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c48:
	/* 0x1c48: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c50:
	/* 0x1c50: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c54:
	/* 0x1c54: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c60:
	/* 0x1c60: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c65:
	/* 0x1c65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c6a:
	/* 0x1c6a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c6d:
	/* 0x1c6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6f:
	/* 0x1c6f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c74:
	/* 0x1c74: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c78:
	/* 0x1c78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c7d:
	/* 0x1c7d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c82:
	/* 0x1c82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c87:
	/* 0x1c87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c89:
	/* 0x1c89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c93:
	/* 0x1c93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c98:
	/* 0x1c98: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c9d:
	/* 0x1c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9f:
	/* 0x1c9f: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca3:
	/* 0x1ca3: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1cac:
	/* 0x1cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cae:
	/* 0x1cae: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb2:
	/* 0x1cb2: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cb6:
	/* 0x1cb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cbb:
	/* 0x1cbb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cc5:
	/* 0x1cc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc7:
	/* 0x1cc7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cd5:
	/* 0x1cd5: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cde:
	/* 0x1cde: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce8:
	/* 0x1ce8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cea:
	/* 0x1cea: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cef:
	/* 0x1cef: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cf3:
	/* 0x1cf3: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cfc:
	/* 0x1cfc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d01:
	/* 0x1d01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d06:
	/* 0x1d06: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d10:
	/* 0x1d10: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d14:
	/* 0x1d14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d19:
	/* 0x1d19: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d1e:
	/* 0x1d1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d23:
	/* 0x1d23: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d26:
	/* 0x1d26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d28:
	/* 0x1d28: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_1d2d:
	/* 0x1d2d: je     1d34 <trace_security_mmap_file+0x1d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d34;
	}
x86_l_1d2f:
	/* 0x1d2f: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1d34:
	/* 0x1d34: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1d38:
	/* 0x1d38: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1d40:
	/* 0x1d40: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1d48:
	/* 0x1d48: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d52:
	/* 0x1d52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d54:
	/* 0x1d54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d59:
	/* 0x1d59: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d72:
	/* 0x1d72: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d77:
	/* 0x1d77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d7c:
	/* 0x1d7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7e:
	/* 0x1d7e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d83:
	/* 0x1d83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d88:
	/* 0x1d88: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d90:
	/* 0x1d90: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1d95:
	/* 0x1d95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d97:
	/* 0x1d97: lea    rdi,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1da0:
	/* 0x1da0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1da5:
	/* 0x1da5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1da8:
	/* 0x1da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1daa:
	/* 0x1daa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1daf:
	/* 0x1daf: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1db7:
	/* 0x1db7: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1dc7:
	/* 0x1dc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc9:
	/* 0x1dc9: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dd1:
	/* 0x1dd1: test   BYTE PTR [r12+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de4:
	/* 0x1de4: je     1e04 <trace_security_mmap_file+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e04;
	}
x86_l_1de6:
	/* 0x1de6: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1deb:
	/* 0x1deb: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1df2:
	/* 0x1df2: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1df7:
	/* 0x1df7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1dfa:
	/* 0x1dfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfc:
	/* 0x1dfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dfe:
	/* 0x1dfe: js     1e04 <trace_security_mmap_file+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e04;
	}
x86_l_1e00:
	/* 0x1e00: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1e04:
	/* 0x1e04: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e0c:
	/* 0x1e0c: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1e11:
	/* 0x1e11: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1e16:
	/* 0x1e16: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1e19:
	/* 0x1e19: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1e1f:
	/* 0x1e1f: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e23:
	/* 0x1e23: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e28:
	/* 0x1e28: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1e2f:
	/* 0x1e2f: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e34:
	/* 0x1e34: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1e37:
	/* 0x1e37: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1e3a:
	/* 0x1e3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3c:
	/* 0x1e3c: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e44:
	/* 0x1e44: mov    DWORD PTR [r14+0x70],0x2eb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337899ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_1e56:
	/* 0x1e56: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1e5e:
	/* 0x1e5e: mov    QWORD PTR [rax+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_1e66:
	/* 0x1e66: mov    QWORD PTR [rax+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    QWORD PTR [rax+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_1e76:
	/* 0x1e76: mov    QWORD PTR [rax+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    QWORD PTR [rax+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_1e86:
	/* 0x1e86: mov    QWORD PTR [rax+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_1e8e:
	/* 0x1e8e: mov    QWORD PTR [rax+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_1e96:
	/* 0x1e96: mov    QWORD PTR [rax],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    QWORD PTR [r14+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_1ea8:
	/* 0x1ea8: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1ead:
	/* 0x1ead: mov    DWORD PTR [rsp+0x20],0x2eb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438954219ULL);
x86_l_1eb5:
	/* 0x1eb5: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eba:
	/* 0x1eba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_1ec6:
	/* 0x1ec6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ecb:
	/* 0x1ecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecd:
	/* 0x1ecd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed0:
	/* 0x1ed0: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_1ed6:
	/* 0x1ed6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1edb:
	/* 0x1edb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee0:
	/* 0x1ee0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ee3:
	/* 0x1ee3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ee5:
	/* 0x1ee5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee8:
	/* 0x1ee8: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_1eee:
	/* 0x1eee: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef2:
	/* 0x1ef2: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1efc:
	/* 0x1efc: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_1f03:
	/* 0x1f03: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f0a:
	/* 0x1f0a: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    QWORD PTR [r14+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_1f15:
	/* 0x1f15: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f19:
	/* 0x1f19: mov    QWORD PTR [r14+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1f20:
	/* 0x1f20: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f24:
	/* 0x1f24: mov    QWORD PTR [r14+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    QWORD PTR [r14+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1f36:
	/* 0x1f36: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3a:
	/* 0x1f3a: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f3e:
	/* 0x1f3e: mov    QWORD PTR [r14+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1f45:
	/* 0x1f45: mov    QWORD PTR [r14+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f50:
	/* 0x1f50: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1f54:
	/* 0x1f54: mov    QWORD PTR [rsp+0x98],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f5c:
	/* 0x1f5c: jne    1f76 <trace_security_mmap_file+0x1f76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f76;
	}
x86_l_1f5e:
	/* 0x1f5e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f61:
	/* 0x1f61: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f64:
	/* 0x1f64: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f6b:
	/* 0x1f6b: jne    274f <trace_security_mmap_file+0x274f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10063ULL;
	}
x86_l_1f71:
	/* 0x1f71: jmp    3a67 <trace_security_mmap_file+0x3a67> */
	return 14951ULL;
x86_l_1f76:
	/* 0x1f76: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_1f7d:
	/* 0x1f7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f80:
	/* 0x1f80: je     2141 <trace_security_mmap_file+0x2141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2141;
	}
x86_l_1f86:
	/* 0x1f86: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1f8e:
	/* 0x1f8e: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_1f95:
	/* 0x1f95: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1f98:
	/* 0x1f98: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9b:
	/* 0x1f9b: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1f9e:
	/* 0x1f9e: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_1fa2:
	/* 0x1fa2: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1fa5:
	/* 0x1fa5: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1fa8:
	/* 0x1fa8: xor    r13,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_1faf:
	/* 0x1faf: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1fb2:
	/* 0x1fb2: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1fb9:
	/* 0x1fb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fbc:
	/* 0x1fbc: je     1fe5 <trace_security_mmap_file+0x1fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fe5;
	}
x86_l_1fbe:
	/* 0x1fbe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc0:
	/* 0x1fc0: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1fcf:
	/* 0x1fcf: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1fd2:
	/* 0x1fd2: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1fd5:
	/* 0x1fd5: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1fd8:
	/* 0x1fd8: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1fdf:
	/* 0x1fdf: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1fe2:
	/* 0x1fe2: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1fe5:
	/* 0x1fe5: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_1fec:
	/* 0x1fec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fef:
	/* 0x1fef: je     200b <trace_security_mmap_file+0x200b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200b;
	}
x86_l_1ff1:
	/* 0x1ff1: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1ff5:
	/* 0x1ff5: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ff8:
	/* 0x1ff8: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1ffb:
	/* 0x1ffb: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1ffe:
	/* 0x1ffe: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_2005:
	/* 0x2005: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2008:
	/* 0x2008: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_200b:
	/* 0x200b: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2012:
	/* 0x2012: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2015:
	/* 0x2015: je     2033 <trace_security_mmap_file+0x2033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2033;
	}
x86_l_2017:
	/* 0x2017: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_201a:
	/* 0x201a: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_201f:
	/* 0x201f: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2023:
	/* 0x2023: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2026:
	/* 0x2026: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_202d:
	/* 0x202d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2030:
	/* 0x2030: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2033:
	/* 0x2033: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2038:
	/* 0x2038: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_203f:
	/* 0x203f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2042:
	/* 0x2042: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2047:
	/* 0x2047: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_204c:
	/* 0x204c: je     21a4 <trace_security_mmap_file+0x21a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a4;
	}
x86_l_2052:
	/* 0x2052: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_2059:
	/* 0x2059: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2061:
	/* 0x2061: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_2068:
	/* 0x2068: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2070:
	/* 0x2070: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_2077:
	/* 0x2077: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_207f:
	/* 0x207f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2084:
	/* 0x2084: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2089:
	/* 0x2089: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_2090:
	/* 0x2090: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2095:
	/* 0x2095: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2097:
	/* 0x2097: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_209a:
	/* 0x209a: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_209e:
	/* 0x209e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a3:
	/* 0x20a3: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_20aa:
	/* 0x20aa: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_20ad:
	/* 0x20ad: je     20cf <trace_security_mmap_file+0x20cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cf;
	}
x86_l_20af:
	/* 0x20af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b4:
	/* 0x20b4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20b9:
	/* 0x20b9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20bc:
	/* 0x20bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20be:
	/* 0x20be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20c1:
	/* 0x20c1: je     20cf <trace_security_mmap_file+0x20cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cf;
	}
x86_l_20c3:
	/* 0x20c3: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c6:
	/* 0x20c6: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ca:
	/* 0x20ca: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_20cd:
	/* 0x20cd: jmp    20d1 <trace_security_mmap_file+0x20d1> */
	goto x86_l_20d1;
x86_l_20cf:
	/* 0x20cf: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d1:
	/* 0x20d1: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_20d9:
	/* 0x20d9: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_20e1:
	/* 0x20e1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20e6:
	/* 0x20e6: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_20e9:
	/* 0x20e9: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_20ec:
	/* 0x20ec: jb     2104 <trace_security_mmap_file+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2104;
	}
x86_l_20ee:
	/* 0x20ee: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_20f2:
	/* 0x20f2: je     20f9 <trace_security_mmap_file+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f9;
	}
x86_l_20f4:
	/* 0x20f4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_20f7:
	/* 0x20f7: jbe    2104 <trace_security_mmap_file+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2104;
	}
x86_l_20f9:
	/* 0x20f9: and    rbp,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 224ULL);
x86_l_2101:
	/* 0x2101: or     rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2104:
	/* 0x2104: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2108:
	/* 0x2108: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_210d:
	/* 0x210d: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2114:
	/* 0x2114: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2117:
	/* 0x2117: je     215d <trace_security_mmap_file+0x215d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215d;
	}
x86_l_2119:
	/* 0x2119: mov    QWORD PTR [rsp+0x90],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2121:
	/* 0x2121: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2126:
	/* 0x2126: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_212b:
	/* 0x212b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_212e:
	/* 0x212e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2130:
	/* 0x2130: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2133:
	/* 0x2133: je     2161 <trace_security_mmap_file+0x2161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2161;
	}
x86_l_2135:
	/* 0x2135: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2138:
	/* 0x2138: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213c:
	/* 0x213c: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_213f:
	/* 0x213f: jmp    2163 <trace_security_mmap_file+0x2163> */
	goto x86_l_2163;
x86_l_2141:
	/* 0x2141: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2148:
	/* 0x2148: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_214f:
	/* 0x214f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2152:
	/* 0x2152: jne    1fbe <trace_security_mmap_file+0x1fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fbe;
	}
x86_l_2158:
	/* 0x2158: jmp    1fe5 <trace_security_mmap_file+0x1fe5> */
	goto x86_l_1fe5;
x86_l_215d:
	/* 0x215d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_215f:
	/* 0x215f: jmp    2173 <trace_security_mmap_file+0x2173> */
	goto x86_l_2173;
x86_l_2161:
	/* 0x2161: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2163:
	/* 0x2163: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_216b:
	/* 0x216b: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2173:
	/* 0x2173: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2176:
	/* 0x2176: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_217b:
	/* 0x217b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_217e:
	/* 0x217e: jb     2196 <trace_security_mmap_file+0x2196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2196;
	}
x86_l_2180:
	/* 0x2180: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2184:
	/* 0x2184: je     218b <trace_security_mmap_file+0x218b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_218b;
	}
x86_l_2186:
	/* 0x2186: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2189:
	/* 0x2189: jbe    2196 <trace_security_mmap_file+0x2196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2196;
	}
x86_l_218b:
	/* 0x218b: and    rbp,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 224ULL);
x86_l_2193:
	/* 0x2193: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2196:
	/* 0x2196: or     rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_2199:
	/* 0x2199: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_219c:
	/* 0x219c: and    r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_219f:
	/* 0x219f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21a4:
	/* 0x21a4: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_21ac:
	/* 0x21ac: je     226d <trace_security_mmap_file+0x226d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226d;
	}
x86_l_21b2:
	/* 0x21b2: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_21b7:
	/* 0x21b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b9:
	/* 0x21b9: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21bd:
	/* 0x21bd: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_21c4:
	/* 0x21c4: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_21cb:
	/* 0x21cb: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_21d3:
	/* 0x21d3: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_21da:
	/* 0x21da: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_21e1:
	/* 0x21e1: movzx  eax,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_21e6:
	/* 0x21e6: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21eb:
	/* 0x21eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21f0:
	/* 0x21f0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_21f7:
	/* 0x21f7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21fc:
	/* 0x21fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21fe:
	/* 0x21fe: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2202:
	/* 0x2202: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2207:
	/* 0x2207: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_220e:
	/* 0x220e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2211:
	/* 0x2211: je     2233 <trace_security_mmap_file+0x2233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2233;
	}
x86_l_2213:
	/* 0x2213: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2218:
	/* 0x2218: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_221d:
	/* 0x221d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2220:
	/* 0x2220: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2222:
	/* 0x2222: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2225:
	/* 0x2225: je     2233 <trace_security_mmap_file+0x2233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2233;
	}
x86_l_2227:
	/* 0x2227: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222a:
	/* 0x222a: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222e:
	/* 0x222e: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2231:
	/* 0x2231: jmp    2235 <trace_security_mmap_file+0x2235> */
	goto x86_l_2235;
x86_l_2233:
	/* 0x2233: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2235:
	/* 0x2235: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2238:
	/* 0x2238: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_223d:
	/* 0x223d: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2240:
	/* 0x2240: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2243:
	/* 0x2243: jae    224c <trace_security_mmap_file+0x224c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_224c;
	}
x86_l_2245:
	/* 0x2245: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224a:
	/* 0x224a: jmp    2267 <trace_security_mmap_file+0x2267> */
	goto x86_l_2267;
x86_l_224c:
	/* 0x224c: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2250:
	/* 0x2250: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2255:
	/* 0x2255: je     225c <trace_security_mmap_file+0x225c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_225c;
	}
x86_l_2257:
	/* 0x2257: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_225a:
	/* 0x225a: jbe    2267 <trace_security_mmap_file+0x2267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2267;
	}
x86_l_225c:
	/* 0x225c: and    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_2264:
	/* 0x2264: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2267:
	/* 0x2267: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_226a:
	/* 0x226a: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_226d:
	/* 0x226d: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_2273:
	/* 0x2273: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_227b:
	/* 0x227b: je     233f <trace_security_mmap_file+0x233f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9023ULL;
	}
x86_l_2281:
	/* 0x2281: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2286:
	/* 0x2286: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_228d:
	/* 0x228d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2292:
	/* 0x2292: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2297:
	/* 0x2297: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229c:
	/* 0x229c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229e:
	/* 0x229e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22a3:
	/* 0x22a3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22a7:
	/* 0x22a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22ac:
	/* 0x22ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b1:
	/* 0x22b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b6:
	/* 0x22b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b8:
	/* 0x22b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22bd:
	/* 0x22bd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22c2:
	/* 0x22c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 8903ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8910ULL: goto x86_l_22ce;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8925ULL: goto x86_l_22dd;
	case 8932ULL: goto x86_l_22e4;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8994ULL: goto x86_l_2322;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9005ULL: goto x86_l_232d;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9017ULL: goto x86_l_2339;
	case 9023ULL: goto x86_l_233f;
	case 9031ULL: goto x86_l_2347;
	case 9037ULL: goto x86_l_234d;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9102ULL: goto x86_l_238e;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9157ULL: goto x86_l_23c5;
	case 9164ULL: goto x86_l_23cc;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9211ULL: goto x86_l_23fb;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9223ULL: goto x86_l_2407;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9253ULL: goto x86_l_2425;
	case 9256ULL: goto x86_l_2428;
	case 9262ULL: goto x86_l_242e;
	case 9270ULL: goto x86_l_2436;
	case 9276ULL: goto x86_l_243c;
	case 9281ULL: goto x86_l_2441;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9355ULL: goto x86_l_248b;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9372ULL: goto x86_l_249c;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9384ULL: goto x86_l_24a8;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9418ULL: goto x86_l_24ca;
	case 9425ULL: goto x86_l_24d1;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9446ULL: goto x86_l_24e6;
	case 9448ULL: goto x86_l_24e8;
	case 9451ULL: goto x86_l_24eb;
	case 9455ULL: goto x86_l_24ef;
	case 9458ULL: goto x86_l_24f2;
	case 9460ULL: goto x86_l_24f4;
	case 9462ULL: goto x86_l_24f6;
	case 9465ULL: goto x86_l_24f9;
	case 9468ULL: goto x86_l_24fc;
	case 9471ULL: goto x86_l_24ff;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9485ULL: goto x86_l_250d;
	case 9493ULL: goto x86_l_2515;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9511ULL: goto x86_l_2527;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9535ULL: goto x86_l_253f;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9562ULL: goto x86_l_255a;
	case 9569ULL: goto x86_l_2561;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9582ULL: goto x86_l_256e;
	case 9585ULL: goto x86_l_2571;
	case 9587ULL: goto x86_l_2573;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9595ULL: goto x86_l_257b;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9606ULL: goto x86_l_2586;
	case 9609ULL: goto x86_l_2589;
	case 9612ULL: goto x86_l_258c;
	case 9615ULL: goto x86_l_258f;
	case 9618ULL: goto x86_l_2592;
	case 9623ULL: goto x86_l_2597;
	case 9629ULL: goto x86_l_259d;
	case 9636ULL: goto x86_l_25a4;
	case 9639ULL: goto x86_l_25a7;
	case 9641ULL: goto x86_l_25a9;
	case 9645ULL: goto x86_l_25ad;
	case 9649ULL: goto x86_l_25b1;
	case 9656ULL: goto x86_l_25b8;
	case 9659ULL: goto x86_l_25bb;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9691ULL: goto x86_l_25db;
	case 9694ULL: goto x86_l_25de;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9709ULL: goto x86_l_25ed;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9723ULL: goto x86_l_25fb;
	case 9726ULL: goto x86_l_25fe;
	case 9728ULL: goto x86_l_2600;
	case 9730ULL: goto x86_l_2602;
	case 9733ULL: goto x86_l_2605;
	case 9736ULL: goto x86_l_2608;
	case 9739ULL: goto x86_l_260b;
	case 9742ULL: goto x86_l_260e;
	case 9748ULL: goto x86_l_2614;
	case 9755ULL: goto x86_l_261b;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9767ULL: goto x86_l_2627;
	case 9770ULL: goto x86_l_262a;
	case 9776ULL: goto x86_l_2630;
	case 9781ULL: goto x86_l_2635;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9795ULL: goto x86_l_2643;
	case 9802ULL: goto x86_l_264a;
	case 9805ULL: goto x86_l_264d;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9815ULL: goto x86_l_2657;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9833ULL: goto x86_l_2669;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9853ULL: goto x86_l_267d;
	case 9856ULL: goto x86_l_2680;
	case 9862ULL: goto x86_l_2686;
	case 9869ULL: goto x86_l_268d;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9881ULL: goto x86_l_2699;
	case 9888ULL: goto x86_l_26a0;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9915ULL: goto x86_l_26bb;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9973ULL: goto x86_l_26f5;
	case 9976ULL: goto x86_l_26f8;
	case 9978ULL: goto x86_l_26fa;
	case 9981ULL: goto x86_l_26fd;
	case 9985ULL: goto x86_l_2701;
	case 9988ULL: goto x86_l_2704;
	case 9990ULL: goto x86_l_2706;
	case 9992ULL: goto x86_l_2708;
	case 9995ULL: goto x86_l_270b;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10030ULL: goto x86_l_272e;
	case 10033ULL: goto x86_l_2731;
	case 10040ULL: goto x86_l_2738;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10057ULL: goto x86_l_2749;
	case 10063ULL: goto x86_l_274f;
	case 10066ULL: goto x86_l_2752;
	case 10072ULL: goto x86_l_2758;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10108ULL: goto x86_l_277c;
	case 10111ULL: goto x86_l_277f;
	case 10119ULL: goto x86_l_2787;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10172ULL: goto x86_l_27bc;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10213ULL: goto x86_l_27e5;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10226ULL: goto x86_l_27f2;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10243ULL: goto x86_l_2803;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10317ULL: goto x86_l_284d;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10338ULL: goto x86_l_2862;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10349ULL: goto x86_l_286d;
	case 10355ULL: goto x86_l_2873;
	case 10357ULL: goto x86_l_2875;
	case 10359ULL: goto x86_l_2877;
	case 10365ULL: goto x86_l_287d;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10387ULL: goto x86_l_2893;
	case 10392ULL: goto x86_l_2898;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10451ULL: goto x86_l_28d3;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10480ULL: goto x86_l_28f0;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22c7:
	/* 0x22c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22cc:
	/* 0x22cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ce:
	/* 0x22ce: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d2:
	/* 0x22d2: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_22d6:
	/* 0x22d6: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_22dd:
	/* 0x22dd: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_22e4:
	/* 0x22e4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22e7:
	/* 0x22e7: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22ed:
	/* 0x22ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22f2:
	/* 0x22f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_22f9:
	/* 0x22f9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22fe:
	/* 0x22fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2300:
	/* 0x2300: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2307:
	/* 0x2307: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_230a:
	/* 0x230a: je     232b <trace_security_mmap_file+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232b;
	}
x86_l_230c:
	/* 0x230c: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2310:
	/* 0x2310: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2315:
	/* 0x2315: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2318:
	/* 0x2318: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_231a:
	/* 0x231a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_231d:
	/* 0x231d: je     232b <trace_security_mmap_file+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232b;
	}
x86_l_231f:
	/* 0x231f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2322:
	/* 0x2322: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2326:
	/* 0x2326: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2329:
	/* 0x2329: jmp    232d <trace_security_mmap_file+0x232d> */
	goto x86_l_232d;
x86_l_232b:
	/* 0x232b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_232d:
	/* 0x232d: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2330:
	/* 0x2330: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2333:
	/* 0x2333: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2336:
	/* 0x2336: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2339:
	/* 0x2339: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_233f:
	/* 0x233f: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_2347:
	/* 0x2347: je     242e <trace_security_mmap_file+0x242e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242e;
	}
x86_l_234d:
	/* 0x234d: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2354:
	/* 0x2354: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2358:
	/* 0x2358: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_235d:
	/* 0x235d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2362:
	/* 0x2362: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2367:
	/* 0x2367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2369:
	/* 0x2369: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_236e:
	/* 0x236e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2373:
	/* 0x2373: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2378:
	/* 0x2378: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_237d:
	/* 0x237d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2380:
	/* 0x2380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2382:
	/* 0x2382: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2386:
	/* 0x2386: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_238a:
	/* 0x238a: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_238e:
	/* 0x238e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2392:
	/* 0x2392: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2397:
	/* 0x2397: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_239c:
	/* 0x239c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a1:
	/* 0x23a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a3:
	/* 0x23a3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23a8:
	/* 0x23a8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_23ac:
	/* 0x23ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23b1:
	/* 0x23b1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23b6:
	/* 0x23b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23bb:
	/* 0x23bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bd:
	/* 0x23bd: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23c1:
	/* 0x23c1: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23c5:
	/* 0x23c5: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_23cc:
	/* 0x23cc: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_23d3:
	/* 0x23d3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23d6:
	/* 0x23d6: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23dc:
	/* 0x23dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23e1:
	/* 0x23e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_23e8:
	/* 0x23e8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23ed:
	/* 0x23ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ef:
	/* 0x23ef: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23f6:
	/* 0x23f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23f9:
	/* 0x23f9: je     241a <trace_security_mmap_file+0x241a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_241a;
	}
x86_l_23fb:
	/* 0x23fb: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23ff:
	/* 0x23ff: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2404:
	/* 0x2404: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2407:
	/* 0x2407: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2409:
	/* 0x2409: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_240c:
	/* 0x240c: je     241a <trace_security_mmap_file+0x241a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_241a;
	}
x86_l_240e:
	/* 0x240e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2411:
	/* 0x2411: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2415:
	/* 0x2415: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2418:
	/* 0x2418: jmp    241c <trace_security_mmap_file+0x241c> */
	goto x86_l_241c;
x86_l_241a:
	/* 0x241a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_241c:
	/* 0x241c: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_241f:
	/* 0x241f: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2422:
	/* 0x2422: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2425:
	/* 0x2425: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2428:
	/* 0x2428: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_242e:
	/* 0x242e: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_2436:
	/* 0x2436: je     250d <trace_security_mmap_file+0x250d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_243c:
	/* 0x243c: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2441:
	/* 0x2441: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2448:
	/* 0x2448: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_244d:
	/* 0x244d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2452:
	/* 0x2452: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2457:
	/* 0x2457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2459:
	/* 0x2459: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_245e:
	/* 0x245e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2463:
	/* 0x2463: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2468:
	/* 0x2468: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_246d:
	/* 0x246d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246f:
	/* 0x246f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2474:
	/* 0x2474: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2479:
	/* 0x2479: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_247c:
	/* 0x247c: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2481:
	/* 0x2481: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2484:
	/* 0x2484: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2489:
	/* 0x2489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248b:
	/* 0x248b: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_248f:
	/* 0x248f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2494:
	/* 0x2494: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2497:
	/* 0x2497: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_249c:
	/* 0x249c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_249f:
	/* 0x249f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a1:
	/* 0x24a1: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_24a8:
	/* 0x24a8: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_24af:
	/* 0x24af: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24b2:
	/* 0x24b2: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24b7:
	/* 0x24b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24bc:
	/* 0x24bc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_24c3:
	/* 0x24c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24c8:
	/* 0x24c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ca:
	/* 0x24ca: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_24d1:
	/* 0x24d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24d4:
	/* 0x24d4: je     24f4 <trace_security_mmap_file+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f4;
	}
x86_l_24d6:
	/* 0x24d6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24db:
	/* 0x24db: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_24de:
	/* 0x24de: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_24e1:
	/* 0x24e1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_24e3:
	/* 0x24e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24e6:
	/* 0x24e6: je     24f4 <trace_security_mmap_file+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f4;
	}
x86_l_24e8:
	/* 0x24e8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24eb:
	/* 0x24eb: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ef:
	/* 0x24ef: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24f2:
	/* 0x24f2: jmp    24f6 <trace_security_mmap_file+0x24f6> */
	goto x86_l_24f6;
x86_l_24f4:
	/* 0x24f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f6:
	/* 0x24f6: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24f9:
	/* 0x24f9: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_24fc:
	/* 0x24fc: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24ff:
	/* 0x24ff: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2502:
	/* 0x2502: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2507:
	/* 0x2507: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_250d:
	/* 0x250d: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_2515:
	/* 0x2515: je     259d <trace_security_mmap_file+0x259d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259d;
	}
x86_l_251b:
	/* 0x251b: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_251f:
	/* 0x251f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2524:
	/* 0x2524: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2527:
	/* 0x2527: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_252c:
	/* 0x252c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252e:
	/* 0x252e: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_2535:
	/* 0x2535: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2538:
	/* 0x2538: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_253f:
	/* 0x253f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2542:
	/* 0x2542: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2547:
	/* 0x2547: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_254c:
	/* 0x254c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_2553:
	/* 0x2553: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2558:
	/* 0x2558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255a:
	/* 0x255a: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2561:
	/* 0x2561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2564:
	/* 0x2564: je     2584 <trace_security_mmap_file+0x2584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2584;
	}
x86_l_2566:
	/* 0x2566: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_256b:
	/* 0x256b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_256e:
	/* 0x256e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2571:
	/* 0x2571: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2573:
	/* 0x2573: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2576:
	/* 0x2576: je     2584 <trace_security_mmap_file+0x2584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2584;
	}
x86_l_2578:
	/* 0x2578: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_257b:
	/* 0x257b: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_257f:
	/* 0x257f: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2582:
	/* 0x2582: jmp    2586 <trace_security_mmap_file+0x2586> */
	goto x86_l_2586;
x86_l_2584:
	/* 0x2584: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2586:
	/* 0x2586: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2589:
	/* 0x2589: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_258c:
	/* 0x258c: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_258f:
	/* 0x258f: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2592:
	/* 0x2592: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2597:
	/* 0x2597: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_259d:
	/* 0x259d: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_25a4:
	/* 0x25a4: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_25a7:
	/* 0x25a7: je     2614 <trace_security_mmap_file+0x2614> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2614;
	}
x86_l_25a9:
	/* 0x25a9: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ad:
	/* 0x25ad: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b1:
	/* 0x25b1: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_25b8:
	/* 0x25b8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25bb:
	/* 0x25bb: mov    WORD PTR [rsp+0x10],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c1:
	/* 0x25c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25c6:
	/* 0x25c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_25cd:
	/* 0x25cd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d2:
	/* 0x25d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d4:
	/* 0x25d4: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_25db:
	/* 0x25db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25de:
	/* 0x25de: je     2600 <trace_security_mmap_file+0x2600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2600;
	}
x86_l_25e0:
	/* 0x25e0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_25e5:
	/* 0x25e5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25ea:
	/* 0x25ea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_25ed:
	/* 0x25ed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_25ef:
	/* 0x25ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25f2:
	/* 0x25f2: je     2600 <trace_security_mmap_file+0x2600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2600;
	}
x86_l_25f4:
	/* 0x25f4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f7:
	/* 0x25f7: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fb:
	/* 0x25fb: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25fe:
	/* 0x25fe: jmp    2602 <trace_security_mmap_file+0x2602> */
	goto x86_l_2602;
x86_l_2600:
	/* 0x2600: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2602:
	/* 0x2602: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2605:
	/* 0x2605: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_2608:
	/* 0x2608: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_260b:
	/* 0x260b: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_260e:
	/* 0x260e: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_2614:
	/* 0x2614: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_261b:
	/* 0x261b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_261e:
	/* 0x261e: je     2686 <trace_security_mmap_file+0x2686> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2686;
	}
x86_l_2620:
	/* 0x2620: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_2627:
	/* 0x2627: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_262a:
	/* 0x262a: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2630:
	/* 0x2630: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2635:
	/* 0x2635: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_263c:
	/* 0x263c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2641:
	/* 0x2641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2643:
	/* 0x2643: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_264a:
	/* 0x264a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_264d:
	/* 0x264d: je     2672 <trace_security_mmap_file+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2672;
	}
x86_l_264f:
	/* 0x264f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2654:
	/* 0x2654: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2657:
	/* 0x2657: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_265f:
	/* 0x265f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2661:
	/* 0x2661: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2664:
	/* 0x2664: je     2672 <trace_security_mmap_file+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2672;
	}
x86_l_2666:
	/* 0x2666: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2669:
	/* 0x2669: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266d:
	/* 0x266d: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2670:
	/* 0x2670: jmp    2674 <trace_security_mmap_file+0x2674> */
	goto x86_l_2674;
x86_l_2672:
	/* 0x2672: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2674:
	/* 0x2674: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2677:
	/* 0x2677: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_267a:
	/* 0x267a: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_267d:
	/* 0x267d: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2680:
	/* 0x2680: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_2686:
	/* 0x2686: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_268d:
	/* 0x268d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2690:
	/* 0x2690: je     2719 <trace_security_mmap_file+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2719;
	}
x86_l_2696:
	/* 0x2696: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2699:
	/* 0x2699: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_26a0:
	/* 0x26a0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_26a3:
	/* 0x26a3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26a8:
	/* 0x26a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26ad:
	/* 0x26ad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_26b4:
	/* 0x26b4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26b9:
	/* 0x26b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26bb:
	/* 0x26bb: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_26c2:
	/* 0x26c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26c5:
	/* 0x26c5: je     2706 <trace_security_mmap_file+0x2706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2706;
	}
x86_l_26c7:
	/* 0x26c7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_26ca:
	/* 0x26ca: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26cf:
	/* 0x26cf: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_26d3:
	/* 0x26d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d8:
	/* 0x26d8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26db:
	/* 0x26db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26dd:
	/* 0x26dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e0:
	/* 0x26e0: jne    26fa <trace_security_mmap_file+0x26fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26fa;
	}
x86_l_26e2:
	/* 0x26e2: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26e7:
	/* 0x26e7: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26eb:
	/* 0x26eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26f0:
	/* 0x26f0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26f3:
	/* 0x26f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f5:
	/* 0x26f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26f8:
	/* 0x26f8: je     2706 <trace_security_mmap_file+0x2706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2706;
	}
x86_l_26fa:
	/* 0x26fa: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26fd:
	/* 0x26fd: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2701:
	/* 0x2701: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2704:
	/* 0x2704: jmp    2708 <trace_security_mmap_file+0x2708> */
	goto x86_l_2708;
x86_l_2706:
	/* 0x2706: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2708:
	/* 0x2708: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_270b:
	/* 0x270b: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_270e:
	/* 0x270e: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2711:
	/* 0x2711: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2714:
	/* 0x2714: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2719:
	/* 0x2719: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2720:
	/* 0x2720: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2723:
	/* 0x2723: je     2731 <trace_security_mmap_file+0x2731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2731;
	}
x86_l_2725:
	/* 0x2725: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_272a:
	/* 0x272a: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_272e:
	/* 0x272e: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2731:
	/* 0x2731: and    r13,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2738:
	/* 0x2738: mov    rcx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_273f:
	/* 0x273f: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2742:
	/* 0x2742: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2749:
	/* 0x2749: je     3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14951ULL;
	}
x86_l_274f:
	/* 0x274f: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2752:
	/* 0x2752: jne    2a25 <trace_security_mmap_file+0x2a25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10789ULL;
	}
x86_l_2758:
	/* 0x2758: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2760:
	/* 0x2760: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2765:
	/* 0x2765: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_276c:
	/* 0x276c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2771:
	/* 0x2771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2773:
	/* 0x2773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2776:
	/* 0x2776: je     28b2 <trace_security_mmap_file+0x28b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b2;
	}
x86_l_277c:
	/* 0x277c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_277f:
	/* 0x277f: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2787:
	/* 0x2787: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278b:
	/* 0x278b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2790:
	/* 0x2790: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2795:
	/* 0x2795: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279a:
	/* 0x279a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279c:
	/* 0x279c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27a1:
	/* 0x27a1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a6:
	/* 0x27a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27ab:
	/* 0x27ab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b0:
	/* 0x27b0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27b5:
	/* 0x27b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27ba:
	/* 0x27ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27bc:
	/* 0x27bc: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_27c1:
	/* 0x27c1: jne    28b9 <trace_security_mmap_file+0x28b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28b9;
	}
x86_l_27c7:
	/* 0x27c7: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27cb:
	/* 0x27cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27d0:
	/* 0x27d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27d5:
	/* 0x27d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27da:
	/* 0x27da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27dc:
	/* 0x27dc: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27e1:
	/* 0x27e1: lea    rax,[r13-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_27e5:
	/* 0x27e5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e9:
	/* 0x27e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27ee:
	/* 0x27ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f2:
	/* 0x27f2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27f7:
	/* 0x27f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27fc:
	/* 0x27fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27fe:
	/* 0x27fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2803:
	/* 0x2803: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2808:
	/* 0x2808: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_280d:
	/* 0x280d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2810:
	/* 0x2810: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2812:
	/* 0x2812: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2817:
	/* 0x2817: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_281c:
	/* 0x281c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2820:
	/* 0x2820: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2825:
	/* 0x2825: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_282a:
	/* 0x282a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282f:
	/* 0x282f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2831:
	/* 0x2831: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2836:
	/* 0x2836: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2839:
	/* 0x2839: je     28ca <trace_security_mmap_file+0x28ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ca;
	}
x86_l_283f:
	/* 0x283f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2844:
	/* 0x2844: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2847:
	/* 0x2847: je     28ca <trace_security_mmap_file+0x28ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ca;
	}
x86_l_284d:
	/* 0x284d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2851:
	/* 0x2851: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2856:
	/* 0x2856: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_285b:
	/* 0x285b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2860:
	/* 0x2860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2862:
	/* 0x2862: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2866:
	/* 0x2866: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_286b:
	/* 0x286b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_286d:
	/* 0x286d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2873:
	/* 0x2873: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2875:
	/* 0x2875: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2877:
	/* 0x2877: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_287d:
	/* 0x287d: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2880:
	/* 0x2880: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2885:
	/* 0x2885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2887:
	/* 0x2887: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_288a:
	/* 0x288a: jl     29ea <trace_security_mmap_file+0x29ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10730ULL;
	}
x86_l_2890:
	/* 0x2890: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2893:
	/* 0x2893: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2898:
	/* 0x2898: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_289f:
	/* 0x289f: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_28a5:
	/* 0x28a5: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28a8:
	/* 0x28a8: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ad:
	/* 0x28ad: jmp    2936 <trace_security_mmap_file+0x2936> */
	return 10550ULL;
x86_l_28b2:
	/* 0x28b2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b4:
	/* 0x28b4: jmp    2a25 <trace_security_mmap_file+0x2a25> */
	return 10789ULL;
x86_l_28b9:
	/* 0x28b9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_28be:
	/* 0x28be: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_28c5:
	/* 0x28c5: jmp    2a0e <trace_security_mmap_file+0x2a0e> */
	return 10766ULL;
x86_l_28ca:
	/* 0x28ca: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28cd:
	/* 0x28cd: jne    29ea <trace_security_mmap_file+0x29ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10730ULL;
	}
x86_l_28d3:
	/* 0x28d3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d7:
	/* 0x28d7: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_28dc:
	/* 0x28dc: je     29ea <trace_security_mmap_file+0x29ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10730ULL;
	}
x86_l_28e2:
	/* 0x28e2: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e7:
	/* 0x28e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28ec:
	/* 0x28ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f0:
	/* 0x28f0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28f4:
	/* 0x28f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f9:
	/* 0x28f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 10494ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10536ULL: goto x86_l_2928;
	case 10540ULL: goto x86_l_292c;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10568ULL: goto x86_l_2948;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10609ULL: goto x86_l_2971;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10621ULL: goto x86_l_297d;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10642ULL: goto x86_l_2992;
	case 10646ULL: goto x86_l_2996;
	case 10648ULL: goto x86_l_2998;
	case 10654ULL: goto x86_l_299e;
	case 10657ULL: goto x86_l_29a1;
	case 10659ULL: goto x86_l_29a3;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10678ULL: goto x86_l_29b6;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10706ULL: goto x86_l_29d2;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10724ULL: goto x86_l_29e4;
	case 10730ULL: goto x86_l_29ea;
	case 10735ULL: goto x86_l_29ef;
	case 10739ULL: goto x86_l_29f3;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10786ULL: goto x86_l_2a22;
	case 10789ULL: goto x86_l_2a25;
	case 10797ULL: goto x86_l_2a2d;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10814ULL: goto x86_l_2a3e;
	case 10822ULL: goto x86_l_2a46;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10850ULL: goto x86_l_2a62;
	case 10854ULL: goto x86_l_2a66;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10869ULL: goto x86_l_2a75;
	case 10871ULL: goto x86_l_2a77;
	case 10873ULL: goto x86_l_2a79;
	case 10875ULL: goto x86_l_2a7b;
	case 10883ULL: goto x86_l_2a83;
	case 10890ULL: goto x86_l_2a8a;
	case 10892ULL: goto x86_l_2a8c;
	case 10900ULL: goto x86_l_2a94;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10919ULL: goto x86_l_2aa7;
	case 10926ULL: goto x86_l_2aae;
	case 10934ULL: goto x86_l_2ab6;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10952ULL: goto x86_l_2ac8;
	case 10958ULL: goto x86_l_2ace;
	case 10960ULL: goto x86_l_2ad0;
	case 10968ULL: goto x86_l_2ad8;
	case 10972ULL: goto x86_l_2adc;
	case 10976ULL: goto x86_l_2ae0;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 10998ULL: goto x86_l_2af6;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11011ULL: goto x86_l_2b03;
	case 11018ULL: goto x86_l_2b0a;
	case 11026ULL: goto x86_l_2b12;
	case 11033ULL: goto x86_l_2b19;
	case 11035ULL: goto x86_l_2b1b;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11052ULL: goto x86_l_2b2c;
	case 11056ULL: goto x86_l_2b30;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11076ULL: goto x86_l_2b44;
	case 11081ULL: goto x86_l_2b49;
	case 11083ULL: goto x86_l_2b4b;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11099ULL: goto x86_l_2b5b;
	case 11106ULL: goto x86_l_2b62;
	case 11114ULL: goto x86_l_2b6a;
	case 11121ULL: goto x86_l_2b71;
	case 11123ULL: goto x86_l_2b73;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11171ULL: goto x86_l_2ba3;
	case 11174ULL: goto x86_l_2ba6;
	case 11176ULL: goto x86_l_2ba8;
	case 11179ULL: goto x86_l_2bab;
	case 11187ULL: goto x86_l_2bb3;
	case 11194ULL: goto x86_l_2bba;
	case 11202ULL: goto x86_l_2bc2;
	case 11209ULL: goto x86_l_2bc9;
	case 11211ULL: goto x86_l_2bcb;
	case 11220ULL: goto x86_l_2bd4;
	case 11226ULL: goto x86_l_2bda;
	case 11228ULL: goto x86_l_2bdc;
	case 11232ULL: goto x86_l_2be0;
	case 11239ULL: goto x86_l_2be7;
	case 11244ULL: goto x86_l_2bec;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11264ULL: goto x86_l_2c00;
	case 11267ULL: goto x86_l_2c03;
	case 11275ULL: goto x86_l_2c0b;
	case 11282ULL: goto x86_l_2c12;
	case 11290ULL: goto x86_l_2c1a;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11308ULL: goto x86_l_2c2c;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11320ULL: goto x86_l_2c38;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11350ULL: goto x86_l_2c56;
	case 11352ULL: goto x86_l_2c58;
	case 11355ULL: goto x86_l_2c5b;
	case 11363ULL: goto x86_l_2c63;
	case 11370ULL: goto x86_l_2c6a;
	case 11378ULL: goto x86_l_2c72;
	case 11385ULL: goto x86_l_2c79;
	case 11387ULL: goto x86_l_2c7b;
	case 11396ULL: goto x86_l_2c84;
	case 11402ULL: goto x86_l_2c8a;
	case 11404ULL: goto x86_l_2c8c;
	case 11408ULL: goto x86_l_2c90;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11435ULL: goto x86_l_2cab;
	case 11438ULL: goto x86_l_2cae;
	case 11440ULL: goto x86_l_2cb0;
	case 11443ULL: goto x86_l_2cb3;
	case 11451ULL: goto x86_l_2cbb;
	case 11458ULL: goto x86_l_2cc2;
	case 11465ULL: goto x86_l_2cc9;
	case 11472ULL: goto x86_l_2cd0;
	case 11475ULL: goto x86_l_2cd3;
	case 11481ULL: goto x86_l_2cd9;
	case 11488ULL: goto x86_l_2ce0;
	case 11492ULL: goto x86_l_2ce4;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11509ULL: goto x86_l_2cf5;
	case 11514ULL: goto x86_l_2cfa;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11537ULL: goto x86_l_2d11;
	case 11540ULL: goto x86_l_2d14;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11551ULL: goto x86_l_2d1f;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11566ULL: goto x86_l_2d2e;
	case 11569ULL: goto x86_l_2d31;
	case 11575ULL: goto x86_l_2d37;
	case 11581ULL: goto x86_l_2d3d;
	case 11589ULL: goto x86_l_2d45;
	case 11595ULL: goto x86_l_2d4b;
	case 11601ULL: goto x86_l_2d51;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11610ULL: goto x86_l_2d5a;
	case 11616ULL: goto x86_l_2d60;
	case 11622ULL: goto x86_l_2d66;
	case 11626ULL: goto x86_l_2d6a;
	case 11633ULL: goto x86_l_2d71;
	case 11638ULL: goto x86_l_2d76;
	case 11641ULL: goto x86_l_2d79;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11651ULL: goto x86_l_2d83;
	case 11658ULL: goto x86_l_2d8a;
	case 11665ULL: goto x86_l_2d91;
	case 11673ULL: goto x86_l_2d99;
	case 11679ULL: goto x86_l_2d9f;
	case 11686ULL: goto x86_l_2da6;
	case 11690ULL: goto x86_l_2daa;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11713ULL: goto x86_l_2dc1;
	case 11720ULL: goto x86_l_2dc8;
	case 11723ULL: goto x86_l_2dcb;
	case 11729ULL: goto x86_l_2dd1;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11740ULL: goto x86_l_2ddc;
	case 11742ULL: goto x86_l_2dde;
	case 11745ULL: goto x86_l_2de1;
	case 11751ULL: goto x86_l_2de7;
	case 11754ULL: goto x86_l_2dea;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11779ULL: goto x86_l_2e03;
	case 11785ULL: goto x86_l_2e09;
	case 11792ULL: goto x86_l_2e10;
	case 11799ULL: goto x86_l_2e17;
	case 11802ULL: goto x86_l_2e1a;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11813ULL: goto x86_l_2e25;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11821ULL: goto x86_l_2e2d;
	case 11827ULL: goto x86_l_2e33;
	case 11829ULL: goto x86_l_2e35;
	case 11837ULL: goto x86_l_2e3d;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11875ULL: goto x86_l_2e63;
	case 11878ULL: goto x86_l_2e66;
	case 11884ULL: goto x86_l_2e6c;
	case 11892ULL: goto x86_l_2e74;
	case 11895ULL: goto x86_l_2e77;
	case 11902ULL: goto x86_l_2e7e;
	case 11908ULL: goto x86_l_2e84;
	case 11911ULL: goto x86_l_2e87;
	case 11919ULL: goto x86_l_2e8f;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11933ULL: goto x86_l_2e9d;
	case 11936ULL: goto x86_l_2ea0;
	case 11939ULL: goto x86_l_2ea3;
	case 11945ULL: goto x86_l_2ea9;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11978ULL: goto x86_l_2eca;
	case 11980ULL: goto x86_l_2ecc;
	case 11986ULL: goto x86_l_2ed2;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11996ULL: goto x86_l_2edc;
	case 11998ULL: goto x86_l_2ede;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12022ULL: goto x86_l_2ef6;
	case 12026ULL: goto x86_l_2efa;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12056ULL: goto x86_l_2f18;
	case 12059ULL: goto x86_l_2f1b;
	case 12065ULL: goto x86_l_2f21;
	case 12070ULL: goto x86_l_2f26;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12083ULL: goto x86_l_2f33;
	case 12089ULL: goto x86_l_2f39;
	case 12092ULL: goto x86_l_2f3c;
	case 12096ULL: goto x86_l_2f40;
	case 12099ULL: goto x86_l_2f43;
	case 12104ULL: goto x86_l_2f48;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12119ULL: goto x86_l_2f57;
	case 12122ULL: goto x86_l_2f5a;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12170ULL: goto x86_l_2f8a;
	case 12173ULL: goto x86_l_2f8d;
	case 12179ULL: goto x86_l_2f93;
	case 12183ULL: goto x86_l_2f97;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12208ULL: goto x86_l_2fb0;
	case 12213ULL: goto x86_l_2fb5;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12228ULL: goto x86_l_2fc4;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12253ULL: goto x86_l_2fdd;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12284ULL: goto x86_l_2ffc;
	case 12288ULL: goto x86_l_3000;
	case 12292ULL: goto x86_l_3004;
	case 12297ULL: goto x86_l_3009;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12310ULL: goto x86_l_3016;
	case 12312ULL: goto x86_l_3018;
	default: return 0xffffffffffffffffULL;
	}
x86_l_28fe:
	/* 0x28fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2900:
	/* 0x2900: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2905:
	/* 0x2905: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2909:
	/* 0x2909: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_290c:
	/* 0x290c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2911:
	/* 0x2911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2913:
	/* 0x2913: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2918:
	/* 0x2918: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_291c:
	/* 0x291c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2921:
	/* 0x2921: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2926:
	/* 0x2926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2928:
	/* 0x2928: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292c:
	/* 0x292c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2930:
	/* 0x2930: mov    r15d,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_2936:
	/* 0x2936: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_293b:
	/* 0x293b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2940:
	/* 0x2940: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2945:
	/* 0x2945: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2948:
	/* 0x2948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294a:
	/* 0x294a: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_294f:
	/* 0x294f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2954:
	/* 0x2954: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2958:
	/* 0x2958: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_295d:
	/* 0x295d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2962:
	/* 0x2962: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2967:
	/* 0x2967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2969:
	/* 0x2969: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_296e:
	/* 0x296e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2971:
	/* 0x2971: je     29cf <trace_security_mmap_file+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cf;
	}
x86_l_2973:
	/* 0x2973: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2978:
	/* 0x2978: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_297b:
	/* 0x297b: je     29cf <trace_security_mmap_file+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cf;
	}
x86_l_297d:
	/* 0x297d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2981:
	/* 0x2981: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2986:
	/* 0x2986: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_298b:
	/* 0x298b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2990:
	/* 0x2990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2992:
	/* 0x2992: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2996:
	/* 0x2996: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2998:
	/* 0x2998: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_299e:
	/* 0x299e: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_29a1:
	/* 0x29a1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29a3:
	/* 0x29a3: jae    3104 <trace_security_mmap_file+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12548ULL;
	}
x86_l_29a9:
	/* 0x29a9: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ae:
	/* 0x29ae: jmp    2f54 <trace_security_mmap_file+0x2f54> */
	goto x86_l_2f54;
x86_l_29b3:
	/* 0x29b3: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_29b6:
	/* 0x29b6: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_29b9:
	/* 0x29b9: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_29be:
	/* 0x29be: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_29c3:
	/* 0x29c3: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_29ca:
	/* 0x29ca: jmp    17da <trace_security_mmap_file+0x17da> */
	return 6106ULL;
x86_l_29cf:
	/* 0x29cf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29d2:
	/* 0x29d2: je     325f <trace_security_mmap_file+0x325f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12895ULL;
	}
x86_l_29d8:
	/* 0x29d8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29dd:
	/* 0x29dd: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_29e4:
	/* 0x29e4: jne    2f54 <trace_security_mmap_file+0x2f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f54;
	}
x86_l_29ea:
	/* 0x29ea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ef:
	/* 0x29ef: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29f3:
	/* 0x29f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29f8:
	/* 0x29f8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fd:
	/* 0x29fd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a02:
	/* 0x2a02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a04:
	/* 0x2a04: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a09:
	/* 0x2a09: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2a11:
	/* 0x2a11: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a16:
	/* 0x2a16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a18:
	/* 0x2a18: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a1b:
	/* 0x2a1b: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a22:
	/* 0x2a22: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a25:
	/* 0x2a25: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a2d:
	/* 0x2a2d: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_2a33:
	/* 0x2a33: ja     2aae <trace_security_mmap_file+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aae;
	}
x86_l_2a35:
	/* 0x2a35: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_2a3e:
	/* 0x2a3e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a46:
	/* 0x2a46: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_2a4e:
	/* 0x2a4e: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_2a53:
	/* 0x2a53: ja     2aae <trace_security_mmap_file+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aae;
	}
x86_l_2a55:
	/* 0x2a55: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a5a:
	/* 0x2a5a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a62:
	/* 0x2a62: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2a66:
	/* 0x2a66: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a72:
	/* 0x2a72: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2a75:
	/* 0x2a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a77:
	/* 0x2a77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a79:
	/* 0x2a79: jle    2aae <trace_security_mmap_file+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2aae;
	}
x86_l_2a7b:
	/* 0x2a7b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a83:
	/* 0x2a83: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_2a8a:
	/* 0x2a8a: ja     2aae <trace_security_mmap_file+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aae;
	}
x86_l_2a8c:
	/* 0x2a8c: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2a94:
	/* 0x2a94: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a9c:
	/* 0x2a9c: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2aa7:
	/* 0x2aa7: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2aae:
	/* 0x2aae: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ab6:
	/* 0x2ab6: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2abd:
	/* 0x2abd: ja     2b0a <trace_security_mmap_file+0x2b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b0a;
	}
x86_l_2abf:
	/* 0x2abf: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_2ac8:
	/* 0x2ac8: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2ace:
	/* 0x2ace: ja     2b0a <trace_security_mmap_file+0x2b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b0a;
	}
x86_l_2ad0:
	/* 0x2ad0: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ad8:
	/* 0x2ad8: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2adc:
	/* 0x2adc: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2ae0:
	/* 0x2ae0: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aec:
	/* 0x2aec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2af1:
	/* 0x2af1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af3:
	/* 0x2af3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2af6:
	/* 0x2af6: js     2b0a <trace_security_mmap_file+0x2b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b0a;
	}
x86_l_2af8:
	/* 0x2af8: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2afb:
	/* 0x2afb: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b03:
	/* 0x2b03: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2b0a:
	/* 0x2b0a: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b12:
	/* 0x2b12: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2b19:
	/* 0x2b19: ja     2b62 <trace_security_mmap_file+0x2b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b62;
	}
x86_l_2b1b:
	/* 0x2b1b: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_2b24:
	/* 0x2b24: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2b2a:
	/* 0x2b2a: ja     2b62 <trace_security_mmap_file+0x2b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b62;
	}
x86_l_2b2c:
	/* 0x2b2c: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b30:
	/* 0x2b30: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2b37:
	/* 0x2b37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b3c:
	/* 0x2b3c: lea    rdx,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2b44:
	/* 0x2b44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b49:
	/* 0x2b49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4b:
	/* 0x2b4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b4e:
	/* 0x2b4e: js     2b62 <trace_security_mmap_file+0x2b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b62;
	}
x86_l_2b50:
	/* 0x2b50: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2b53:
	/* 0x2b53: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b5b:
	/* 0x2b5b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2b62:
	/* 0x2b62: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b6a:
	/* 0x2b6a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2b71:
	/* 0x2b71: ja     2bba <trace_security_mmap_file+0x2bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2bba;
	}
x86_l_2b73:
	/* 0x2b73: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_2b7c:
	/* 0x2b7c: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2b82:
	/* 0x2b82: ja     2bba <trace_security_mmap_file+0x2bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2bba;
	}
x86_l_2b84:
	/* 0x2b84: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b88:
	/* 0x2b88: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b94:
	/* 0x2b94: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2b9c:
	/* 0x2b9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba1:
	/* 0x2ba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba3:
	/* 0x2ba3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba6:
	/* 0x2ba6: js     2bba <trace_security_mmap_file+0x2bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2bba;
	}
x86_l_2ba8:
	/* 0x2ba8: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2bab:
	/* 0x2bab: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2bb3:
	/* 0x2bb3: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2bba:
	/* 0x2bba: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bc2:
	/* 0x2bc2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2bc9:
	/* 0x2bc9: ja     2c12 <trace_security_mmap_file+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c12;
	}
x86_l_2bcb:
	/* 0x2bcb: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_2bd4:
	/* 0x2bd4: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2bda:
	/* 0x2bda: ja     2c12 <trace_security_mmap_file+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c12;
	}
x86_l_2bdc:
	/* 0x2bdc: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2be0:
	/* 0x2be0: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2be7:
	/* 0x2be7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bec:
	/* 0x2bec: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf9:
	/* 0x2bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfb:
	/* 0x2bfb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bfe:
	/* 0x2bfe: js     2c12 <trace_security_mmap_file+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c12;
	}
x86_l_2c00:
	/* 0x2c00: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2c03:
	/* 0x2c03: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c0b:
	/* 0x2c0b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2c12:
	/* 0x2c12: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c1a:
	/* 0x2c1a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2c21:
	/* 0x2c21: ja     2c6a <trace_security_mmap_file+0x2c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c6a;
	}
x86_l_2c23:
	/* 0x2c23: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_2c2c:
	/* 0x2c2c: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2c32:
	/* 0x2c32: ja     2c6a <trace_security_mmap_file+0x2c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c6a;
	}
x86_l_2c34:
	/* 0x2c34: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c38:
	/* 0x2c38: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c44:
	/* 0x2c44: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c51:
	/* 0x2c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c53:
	/* 0x2c53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c56:
	/* 0x2c56: js     2c6a <trace_security_mmap_file+0x2c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c6a;
	}
x86_l_2c58:
	/* 0x2c58: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2c5b:
	/* 0x2c5b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c63:
	/* 0x2c63: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2c6a:
	/* 0x2c6a: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c72:
	/* 0x2c72: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2c79:
	/* 0x2c79: ja     2cc2 <trace_security_mmap_file+0x2cc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cc2;
	}
x86_l_2c7b:
	/* 0x2c7b: mov    BYTE PTR [r14+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_2c84:
	/* 0x2c84: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2c8a:
	/* 0x2c8a: ja     2cc2 <trace_security_mmap_file+0x2cc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cc2;
	}
x86_l_2c8c:
	/* 0x2c8c: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c90:
	/* 0x2c90: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2c97:
	/* 0x2c97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c9c:
	/* 0x2c9c: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca9:
	/* 0x2ca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cab:
	/* 0x2cab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cae:
	/* 0x2cae: js     2cc2 <trace_security_mmap_file+0x2cc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cc2;
	}
x86_l_2cb0:
	/* 0x2cb0: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_2cb3:
	/* 0x2cb3: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cbb:
	/* 0x2cbb: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    rbp,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2cc9:
	/* 0x2cc9: mov    rbx,QWORD PTR [r14+0x7df8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_2cd0:
	/* 0x2cd0: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2cd3:
	/* 0x2cd3: je     2df6 <trace_security_mmap_file+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df6;
	}
x86_l_2cd9:
	/* 0x2cd9: or     rbp,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 32240ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    eax,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ce8:
	/* 0x2ce8: movzx  r12d,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2ced:
	/* 0x2ced: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2cf5:
	/* 0x2cf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cfa:
	/* 0x2cfa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_bufs)));
x86_l_2d01:
	/* 0x2d01: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d06:
	/* 0x2d06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d08:
	/* 0x2d08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0b:
	/* 0x2d0b: je     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13325ULL;
	}
x86_l_2d11:
	/* 0x2d11: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2d14:
	/* 0x2d14: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d17:
	/* 0x2d17: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d1f:
	/* 0x2d1f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d21:
	/* 0x2d21: call   2d26 <trace_security_mmap_file+0x2d26> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_2d26:
	/* 0x2d26: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d2e:
	/* 0x2d2e: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d31:
	/* 0x2d31: cmp    rax,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31995ULL);
x86_l_2d37:
	/* 0x2d37: ja     3410 <trace_security_mmap_file+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13328ULL;
	}
x86_l_2d3d:
	/* 0x2d3d: mov    esi,DWORD PTR [rax+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2d45:
	/* 0x2d45: cmp    esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2d4b:
	/* 0x2d4b: ja     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13325ULL;
	}
x86_l_2d51:
	/* 0x2d51: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2d54:
	/* 0x2d54: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d57:
	/* 0x2d57: lea    ecx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d5a:
	/* 0x2d5a: cmp    ecx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2d60:
	/* 0x2d60: ja     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13325ULL;
	}
x86_l_2d66:
	/* 0x2d66: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d6a:
	/* 0x2d6a: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d71:
	/* 0x2d71: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d76:
	/* 0x2d76: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d79:
	/* 0x2d79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7b:
	/* 0x2d7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d7d:
	/* 0x2d7d: je     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13325ULL;
	}
x86_l_2d83:
	/* 0x2d83: lea    r13,[r14+0x7de8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    rax,QWORD PTR [r14+0x7e10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_2d91:
	/* 0x2d91: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d99:
	/* 0x2d99: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2da6:
	/* 0x2da6: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2daa:
	/* 0x2daa: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dae:
	/* 0x2dae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db3:
	/* 0x2db3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_exact_version)));
x86_l_2dba:
	/* 0x2dba: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dbf:
	/* 0x2dbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc1:
	/* 0x2dc1: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2dc8:
	/* 0x2dc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dcb:
	/* 0x2dcb: je     30fd <trace_security_mmap_file+0x30fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12541ULL;
	}
x86_l_2dd1:
	/* 0x2dd1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2dd6:
	/* 0x2dd6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2dd9:
	/* 0x2dd9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ddc:
	/* 0x2ddc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2dde:
	/* 0x2dde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2de1:
	/* 0x2de1: je     3371 <trace_security_mmap_file+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_2de7:
	/* 0x2de7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dea:
	/* 0x2dea: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dee:
	/* 0x2dee: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2df1:
	/* 0x2df1: jmp    337a <trace_security_mmap_file+0x337a> */
	return 13178ULL;
x86_l_2df6:
	/* 0x2df6: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2df9:
	/* 0x2df9: jne    2e09 <trace_security_mmap_file+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e09;
	}
x86_l_2dfb:
	/* 0x2dfb: cmp    QWORD PTR [r14+0x7df0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138469745623040ULL);
x86_l_2e03:
	/* 0x2e03: je     2f48 <trace_security_mmap_file+0x2f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f48;
	}
x86_l_2e09:
	/* 0x2e09: lea    r13,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2e10:
	/* 0x2e10: mov    r15,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2e17:
	/* 0x2e17: or     r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2e1a:
	/* 0x2e1a: mov    ebx,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e1e:
	/* 0x2e1e: movzx  ecx,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2e23:
	/* 0x2e23: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e25:
	/* 0x2e25: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e28:
	/* 0x2e28: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e2a:
	/* 0x2e2a: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2e2d:
	/* 0x2e2d: je     33bb <trace_security_mmap_file+0x33bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13243ULL;
	}
x86_l_2e33:
	/* 0x2e33: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_2e35:
	/* 0x2e35: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e3d:
	/* 0x2e3d: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e45:
	/* 0x2e45: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2e48:
	/* 0x2e48: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2e50:
	/* 0x2e50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e55:
	/* 0x2e55: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_2e5c:
	/* 0x2e5c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e61:
	/* 0x2e61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e63:
	/* 0x2e63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e66:
	/* 0x2e66: je     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13325ULL;
	}
x86_l_2e6c:
	/* 0x2e6c: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2e74:
	/* 0x2e74: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e77:
	/* 0x2e77: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_2e7e:
	/* 0x2e7e: ja     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13325ULL;
	}
x86_l_2e84:
	/* 0x2e84: lea    edx,[rcx+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e87:
	/* 0x2e87: mov    ecx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2e8f:
	/* 0x2e8f: cmp    ecx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2e95:
	/* 0x2e95: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2e9a:
	/* 0x2e9a: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2e9d:
	/* 0x2e9d: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2ea0:
	/* 0x2ea0: lea    edx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ea3:
	/* 0x2ea3: cmp    edx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_2ea9:
	/* 0x2ea9: ja     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13325ULL;
	}
x86_l_2eaf:
	/* 0x2eaf: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2eb4:
	/* 0x2eb4: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2eb8:
	/* 0x2eb8: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ebc:
	/* 0x2ebc: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ec8:
	/* 0x2ec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eca:
	/* 0x2eca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ecc:
	/* 0x2ecc: je     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13325ULL;
	}
x86_l_2ed2:
	/* 0x2ed2: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2eda:
	/* 0x2eda: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2edc:
	/* 0x2edc: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2ede:
	/* 0x2ede: mov    rbx,QWORD PTR [r14+0x7e00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eea:
	/* 0x2eea: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eef:
	/* 0x2eef: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2efa:
	/* 0x2efa: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2efe:
	/* 0x2efe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f03:
	/* 0x2f03: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_prefix_version)));
x86_l_2f0a:
	/* 0x2f0a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f0f:
	/* 0x2f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f11:
	/* 0x2f11: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2f18:
	/* 0x2f18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f1b:
	/* 0x2f1b: je     30be <trace_security_mmap_file+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12478ULL;
	}
x86_l_2f21:
	/* 0x2f21: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f26:
	/* 0x2f26: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f29:
	/* 0x2f29: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f2e:
	/* 0x2f2e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f30:
	/* 0x2f30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f33:
	/* 0x2f33: je     30be <trace_security_mmap_file+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12478ULL;
	}
x86_l_2f39:
	/* 0x2f39: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f40:
	/* 0x2f40: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2f43:
	/* 0x2f43: jmp    30c0 <trace_security_mmap_file+0x30c0> */
	return 12480ULL;
x86_l_2f48:
	/* 0x2f48: mov    r13,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32496ULL);
x86_l_2f4f:
	/* 0x2f4f: jmp    3410 <trace_security_mmap_file+0x3410> */
	return 13328ULL;
x86_l_2f54:
	/* 0x2f54: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2f57:
	/* 0x2f57: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_2f5a:
	/* 0x2f5a: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2f64:
	/* 0x2f64: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_2f6b:
	/* 0x2f6b: jmp    2a1b <trace_security_mmap_file+0x2a1b> */
	goto x86_l_2a1b;
x86_l_2f70:
	/* 0x2f70: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f75:
	/* 0x2f75: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f80:
	/* 0x2f80: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f83:
	/* 0x2f83: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f88:
	/* 0x2f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8a:
	/* 0x2f8a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f8d:
	/* 0x2f8d: jl     179c <trace_security_mmap_file+0x179c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6044ULL;
	}
x86_l_2f93:
	/* 0x2f93: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f97:
	/* 0x2f97: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2fa2:
	/* 0x2fa2: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fa5:
	/* 0x2fa5: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2faa:
	/* 0x2faa: jmp    3004 <trace_security_mmap_file+0x3004> */
	goto x86_l_3004;
x86_l_2fac:
	/* 0x2fac: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb0:
	/* 0x2fb0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2fb5:
	/* 0x2fb5: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_2fbb:
	/* 0x2fbb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc4:
	/* 0x2fc4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fc8:
	/* 0x2fc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fcd:
	/* 0x2fcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd2:
	/* 0x2fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd4:
	/* 0x2fd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fd9:
	/* 0x2fd9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fdd:
	/* 0x2fdd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fe0:
	/* 0x2fe0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fe5:
	/* 0x2fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe7:
	/* 0x2fe7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fec:
	/* 0x2fec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff0:
	/* 0x2ff0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ffa:
	/* 0x2ffa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ffc:
	/* 0x2ffc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3000:
	/* 0x3000: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3004:
	/* 0x3004: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3009:
	/* 0x3009: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_300e:
	/* 0x300e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3013:
	/* 0x3013: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3016:
	/* 0x3016: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3018:
	/* 0x3018: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 12317ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12343ULL: goto x86_l_3037;
	case 12348ULL: goto x86_l_303c;
	case 12351ULL: goto x86_l_303f;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12365ULL: goto x86_l_304d;
	case 12371ULL: goto x86_l_3053;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12392ULL: goto x86_l_3068;
	case 12396ULL: goto x86_l_306c;
	case 12398ULL: goto x86_l_306e;
	case 12404ULL: goto x86_l_3074;
	case 12407ULL: goto x86_l_3077;
	case 12409ULL: goto x86_l_3079;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12441ULL: goto x86_l_3099;
	case 12444ULL: goto x86_l_309c;
	case 12450ULL: goto x86_l_30a2;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12483ULL: goto x86_l_30c3;
	case 12491ULL: goto x86_l_30cb;
	case 12494ULL: goto x86_l_30ce;
	case 12497ULL: goto x86_l_30d1;
	case 12502ULL: goto x86_l_30d6;
	case 12510ULL: goto x86_l_30de;
	case 12513ULL: goto x86_l_30e1;
	case 12518ULL: goto x86_l_30e6;
	case 12521ULL: goto x86_l_30e9;
	case 12524ULL: goto x86_l_30ec;
	case 12527ULL: goto x86_l_30ef;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12553ULL: goto x86_l_3109;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12567ULL: goto x86_l_3117;
	case 12572ULL: goto x86_l_311c;
	case 12574ULL: goto x86_l_311e;
	case 12577ULL: goto x86_l_3121;
	case 12583ULL: goto x86_l_3127;
	case 12587ULL: goto x86_l_312b;
	case 12593ULL: goto x86_l_3131;
	case 12598ULL: goto x86_l_3136;
	case 12601ULL: goto x86_l_3139;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12614ULL: goto x86_l_3146;
	case 12620ULL: goto x86_l_314c;
	case 12624ULL: goto x86_l_3150;
	case 12629ULL: goto x86_l_3155;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12644ULL: goto x86_l_3164;
	case 12648ULL: goto x86_l_3168;
	case 12653ULL: goto x86_l_316d;
	case 12658ULL: goto x86_l_3172;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12669ULL: goto x86_l_317d;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12688ULL: goto x86_l_3190;
	case 12693ULL: goto x86_l_3195;
	case 12698ULL: goto x86_l_319a;
	case 12700ULL: goto x86_l_319c;
	case 12704ULL: goto x86_l_31a0;
	case 12708ULL: goto x86_l_31a4;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12726ULL: goto x86_l_31b6;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12767ULL: goto x86_l_31df;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12781ULL: goto x86_l_31ed;
	case 12787ULL: goto x86_l_31f3;
	case 12791ULL: goto x86_l_31f7;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12808ULL: goto x86_l_3208;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12820ULL: goto x86_l_3214;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12831ULL: goto x86_l_321f;
	case 12836ULL: goto x86_l_3224;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12854ULL: goto x86_l_3236;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12867ULL: goto x86_l_3243;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12882ULL: goto x86_l_3252;
	case 12885ULL: goto x86_l_3255;
	case 12890ULL: goto x86_l_325a;
	case 12895ULL: goto x86_l_325f;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12919ULL: goto x86_l_3277;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12944ULL: goto x86_l_3290;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12954ULL: goto x86_l_329a;
	case 12959ULL: goto x86_l_329f;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12975ULL: goto x86_l_32af;
	case 12979ULL: goto x86_l_32b3;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13001ULL: goto x86_l_32c9;
	case 13003ULL: goto x86_l_32cb;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13056ULL: goto x86_l_3300;
	case 13062ULL: goto x86_l_3306;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13083ULL: goto x86_l_331b;
	case 13087ULL: goto x86_l_331f;
	case 13089ULL: goto x86_l_3321;
	case 13095ULL: goto x86_l_3327;
	case 13098ULL: goto x86_l_332a;
	case 13100ULL: goto x86_l_332c;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13132ULL: goto x86_l_334c;
	case 13135ULL: goto x86_l_334f;
	case 13141ULL: goto x86_l_3355;
	case 13145ULL: goto x86_l_3359;
	case 13151ULL: goto x86_l_335f;
	case 13156ULL: goto x86_l_3364;
	case 13159ULL: goto x86_l_3367;
	case 13164ULL: goto x86_l_336c;
	case 13169ULL: goto x86_l_3371;
	case 13171ULL: goto x86_l_3373;
	case 13178ULL: goto x86_l_337a;
	case 13181ULL: goto x86_l_337d;
	case 13189ULL: goto x86_l_3385;
	case 13196ULL: goto x86_l_338c;
	case 13199ULL: goto x86_l_338f;
	case 13202ULL: goto x86_l_3392;
	case 13205ULL: goto x86_l_3395;
	case 13210ULL: goto x86_l_339a;
	case 13215ULL: goto x86_l_339f;
	case 13218ULL: goto x86_l_33a2;
	case 13221ULL: goto x86_l_33a5;
	case 13224ULL: goto x86_l_33a8;
	case 13228ULL: goto x86_l_33ac;
	case 13231ULL: goto x86_l_33af;
	case 13234ULL: goto x86_l_33b2;
	case 13237ULL: goto x86_l_33b5;
	case 13243ULL: goto x86_l_33bb;
	case 13248ULL: goto x86_l_33c0;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13296ULL: goto x86_l_33f0;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13309ULL: goto x86_l_33fd;
	case 13312ULL: goto x86_l_3400;
	case 13319ULL: goto x86_l_3407;
	case 13325ULL: goto x86_l_340d;
	case 13328ULL: goto x86_l_3410;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13346ULL: goto x86_l_3422;
	case 13353ULL: goto x86_l_3429;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13375ULL: goto x86_l_343f;
	case 13377ULL: goto x86_l_3441;
	case 13382ULL: goto x86_l_3446;
	case 13387ULL: goto x86_l_344b;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13406ULL: goto x86_l_345e;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13432ULL: goto x86_l_3478;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13449ULL: goto x86_l_3489;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13465ULL: goto x86_l_3499;
	case 13469ULL: goto x86_l_349d;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13491ULL: goto x86_l_34b3;
	case 13493ULL: goto x86_l_34b5;
	case 13498ULL: goto x86_l_34ba;
	case 13503ULL: goto x86_l_34bf;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	case 13516ULL: goto x86_l_34cc;
	case 13518ULL: goto x86_l_34ce;
	case 13522ULL: goto x86_l_34d2;
	case 13526ULL: goto x86_l_34d6;
	case 13530ULL: goto x86_l_34da;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13551ULL: goto x86_l_34ef;
	case 13555ULL: goto x86_l_34f3;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13574ULL: goto x86_l_3506;
	case 13577ULL: goto x86_l_3509;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13588ULL: goto x86_l_3514;
	case 13593ULL: goto x86_l_3519;
	case 13598ULL: goto x86_l_351e;
	case 13603ULL: goto x86_l_3523;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13625ULL: goto x86_l_3539;
	case 13628ULL: goto x86_l_353c;
	case 13630ULL: goto x86_l_353e;
	case 13634ULL: goto x86_l_3542;
	case 13638ULL: goto x86_l_3546;
	case 13642ULL: goto x86_l_354a;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13667ULL: goto x86_l_3563;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13689ULL: goto x86_l_3579;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13706ULL: goto x86_l_358a;
	case 13711ULL: goto x86_l_358f;
	case 13714ULL: goto x86_l_3592;
	case 13716ULL: goto x86_l_3594;
	case 13720ULL: goto x86_l_3598;
	case 13724ULL: goto x86_l_359c;
	case 13728ULL: goto x86_l_35a0;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13758ULL: goto x86_l_35be;
	case 13763ULL: goto x86_l_35c3;
	case 13768ULL: goto x86_l_35c8;
	case 13773ULL: goto x86_l_35cd;
	case 13775ULL: goto x86_l_35cf;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13799ULL: goto x86_l_35e7;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13827ULL: goto x86_l_3603;
	case 13829ULL: goto x86_l_3605;
	case 13833ULL: goto x86_l_3609;
	case 13837ULL: goto x86_l_360d;
	case 13841ULL: goto x86_l_3611;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13860ULL: goto x86_l_3624;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13871ULL: goto x86_l_362f;
	case 13876ULL: goto x86_l_3634;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13892ULL: goto x86_l_3644;
	case 13894ULL: goto x86_l_3646;
	case 13899ULL: goto x86_l_364b;
	case 13904ULL: goto x86_l_3650;
	case 13909ULL: goto x86_l_3655;
	case 13912ULL: goto x86_l_3658;
	case 13914ULL: goto x86_l_365a;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13929ULL: goto x86_l_3669;
	case 13934ULL: goto x86_l_366e;
	case 13937ULL: goto x86_l_3671;
	case 13939ULL: goto x86_l_3673;
	case 13943ULL: goto x86_l_3677;
	case 13947ULL: goto x86_l_367b;
	case 13951ULL: goto x86_l_367f;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	default: return 0xffffffffffffffffULL;
	}
x86_l_301d:
	/* 0x301d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3022:
	/* 0x3022: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3026:
	/* 0x3026: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_302b:
	/* 0x302b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3030:
	/* 0x3030: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3035:
	/* 0x3035: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3037:
	/* 0x3037: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303c:
	/* 0x303c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_303f:
	/* 0x303f: je     3143 <trace_security_mmap_file+0x3143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3143;
	}
x86_l_3045:
	/* 0x3045: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_304a:
	/* 0x304a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_304d:
	/* 0x304d: je     3143 <trace_security_mmap_file+0x3143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3143;
	}
x86_l_3053:
	/* 0x3053: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3057:
	/* 0x3057: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_305c:
	/* 0x305c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3061:
	/* 0x3061: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3066:
	/* 0x3066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3068:
	/* 0x3068: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_306c:
	/* 0x306c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_306e:
	/* 0x306e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3074:
	/* 0x3074: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3077:
	/* 0x3077: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3079:
	/* 0x3079: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_307f:
	/* 0x307f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3084:
	/* 0x3084: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_308a:
	/* 0x308a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_308f:
	/* 0x308f: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3092:
	/* 0x3092: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3097:
	/* 0x3097: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3099:
	/* 0x3099: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_309c:
	/* 0x309c: jl     179c <trace_security_mmap_file+0x179c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6044ULL;
	}
x86_l_30a2:
	/* 0x30a2: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_30a6:
	/* 0x30a6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_30ac:
	/* 0x30ac: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_30b1:
	/* 0x30b1: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30b4:
	/* 0x30b4: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30b9:
	/* 0x30b9: jmp    31a4 <trace_security_mmap_file+0x31a4> */
	goto x86_l_31a4;
x86_l_30be:
	/* 0x30be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30c0:
	/* 0x30c0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_30c3:
	/* 0x30c3: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30cb:
	/* 0x30cb: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_30ce:
	/* 0x30ce: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_30d1:
	/* 0x30d1: andn   rax,rbx,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_30d6:
	/* 0x30d6: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_30de:
	/* 0x30de: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_30e1:
	/* 0x30e1: andn   rax,rbp,rbx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_30e6:
	/* 0x30e6: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_30e9:
	/* 0x30e9: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_30ec:
	/* 0x30ec: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_30ef:
	/* 0x30ef: mov    ebx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_30f3:
	/* 0x30f3: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_30f8:
	/* 0x30f8: jmp    33bb <trace_security_mmap_file+0x33bb> */
	goto x86_l_33bb;
x86_l_30fd:
	/* 0x30fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30ff:
	/* 0x30ff: jmp    337a <trace_security_mmap_file+0x337a> */
	goto x86_l_337a;
x86_l_3104:
	/* 0x3104: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3109:
	/* 0x3109: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_310f:
	/* 0x310f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3114:
	/* 0x3114: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3117:
	/* 0x3117: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_311c:
	/* 0x311c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311e:
	/* 0x311e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3121:
	/* 0x3121: jl     29dd <trace_security_mmap_file+0x29dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10717ULL;
	}
x86_l_3127:
	/* 0x3127: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_312b:
	/* 0x312b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3131:
	/* 0x3131: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3136:
	/* 0x3136: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3139:
	/* 0x3139: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_313e:
	/* 0x313e: jmp    32b7 <trace_security_mmap_file+0x32b7> */
	goto x86_l_32b7;
x86_l_3143:
	/* 0x3143: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3146:
	/* 0x3146: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_314c:
	/* 0x314c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3150:
	/* 0x3150: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3155:
	/* 0x3155: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_315b:
	/* 0x315b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3160:
	/* 0x3160: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3164:
	/* 0x3164: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3168:
	/* 0x3168: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316d:
	/* 0x316d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3172:
	/* 0x3172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3174:
	/* 0x3174: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3179:
	/* 0x3179: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317d:
	/* 0x317d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3180:
	/* 0x3180: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3185:
	/* 0x3185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3187:
	/* 0x3187: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_318c:
	/* 0x318c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3190:
	/* 0x3190: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3195:
	/* 0x3195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_319a:
	/* 0x319a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319c:
	/* 0x319c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31a0:
	/* 0x31a0: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31a4:
	/* 0x31a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a9:
	/* 0x31a9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31ae:
	/* 0x31ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b3:
	/* 0x31b3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_31b6:
	/* 0x31b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b8:
	/* 0x31b8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31bd:
	/* 0x31bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c2:
	/* 0x31c2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31c6:
	/* 0x31c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31cb:
	/* 0x31cb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d0:
	/* 0x31d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d5:
	/* 0x31d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d7:
	/* 0x31d7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31dc:
	/* 0x31dc: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31df:
	/* 0x31df: je     3b3b <trace_security_mmap_file+0x3b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15163ULL;
	}
x86_l_31e5:
	/* 0x31e5: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31ea:
	/* 0x31ea: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31ed:
	/* 0x31ed: je     3b3b <trace_security_mmap_file+0x3b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15163ULL;
	}
x86_l_31f3:
	/* 0x31f3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31f7:
	/* 0x31f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31fc:
	/* 0x31fc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3201:
	/* 0x3201: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3206:
	/* 0x3206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3208:
	/* 0x3208: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_320c:
	/* 0x320c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_320e:
	/* 0x320e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3214:
	/* 0x3214: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3217:
	/* 0x3217: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3219:
	/* 0x3219: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_321f:
	/* 0x321f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3224:
	/* 0x3224: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_322a:
	/* 0x322a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_322f:
	/* 0x322f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3234:
	/* 0x3234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3236:
	/* 0x3236: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3239:
	/* 0x3239: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_323f:
	/* 0x323f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3243:
	/* 0x3243: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3249:
	/* 0x3249: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_324e:
	/* 0x324e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3252:
	/* 0x3252: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3255:
	/* 0x3255: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325a:
	/* 0x325a: jmp    3b9c <trace_security_mmap_file+0x3b9c> */
	return 15260ULL;
x86_l_325f:
	/* 0x325f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3263:
	/* 0x3263: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3268:
	/* 0x3268: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_326e:
	/* 0x326e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3273:
	/* 0x3273: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3277:
	/* 0x3277: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_327b:
	/* 0x327b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3280:
	/* 0x3280: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3285:
	/* 0x3285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3287:
	/* 0x3287: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_328c:
	/* 0x328c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3290:
	/* 0x3290: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3293:
	/* 0x3293: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3298:
	/* 0x3298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329a:
	/* 0x329a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_329f:
	/* 0x329f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a3:
	/* 0x32a3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32a8:
	/* 0x32a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ad:
	/* 0x32ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32af:
	/* 0x32af: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b3:
	/* 0x32b3: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32b7:
	/* 0x32b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32bc:
	/* 0x32bc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32c1:
	/* 0x32c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c6:
	/* 0x32c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32c9:
	/* 0x32c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cb:
	/* 0x32cb: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32d0:
	/* 0x32d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d5:
	/* 0x32d5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32d9:
	/* 0x32d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32de:
	/* 0x32de: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32e3:
	/* 0x32e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e8:
	/* 0x32e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ea:
	/* 0x32ea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ef:
	/* 0x32ef: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32f2:
	/* 0x32f2: je     391d <trace_security_mmap_file+0x391d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14621ULL;
	}
x86_l_32f8:
	/* 0x32f8: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32fd:
	/* 0x32fd: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3300:
	/* 0x3300: je     391d <trace_security_mmap_file+0x391d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14621ULL;
	}
x86_l_3306:
	/* 0x3306: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_330a:
	/* 0x330a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_330f:
	/* 0x330f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3314:
	/* 0x3314: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3319:
	/* 0x3319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331b:
	/* 0x331b: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_331f:
	/* 0x331f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3321:
	/* 0x3321: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3327:
	/* 0x3327: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_332a:
	/* 0x332a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_332c:
	/* 0x332c: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_3332:
	/* 0x3332: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3337:
	/* 0x3337: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_333d:
	/* 0x333d: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3342:
	/* 0x3342: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3345:
	/* 0x3345: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_334a:
	/* 0x334a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334c:
	/* 0x334c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_334f:
	/* 0x334f: jl     29dd <trace_security_mmap_file+0x29dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10717ULL;
	}
x86_l_3355:
	/* 0x3355: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3359:
	/* 0x3359: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_335f:
	/* 0x335f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3364:
	/* 0x3364: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3367:
	/* 0x3367: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_336c:
	/* 0x336c: jmp    397e <trace_security_mmap_file+0x397e> */
	return 14718ULL;
x86_l_3371:
	/* 0x3371: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3373:
	/* 0x3373: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_337a:
	/* 0x337a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_337d:
	/* 0x337d: mov    r8,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3385:
	/* 0x3385: lea    r13,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_338c:
	/* 0x338c: or     rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_338f:
	/* 0x338f: and    rdx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_3392:
	/* 0x3392: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3395:
	/* 0x3395: andn   rax,r8,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_339a:
	/* 0x339a: andn   rsi,rdx,r8 */
	X86_SIM_L_EXEC_ANDN(X86_RSI, X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_339f:
	/* 0x339f: and    rdx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_33a2:
	/* 0x33a2: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_33a5:
	/* 0x33a5: mov    rbp,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a8:
	/* 0x33a8: mov    ebx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_33ac:
	/* 0x33ac: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_33af:
	/* 0x33af: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_33b2:
	/* 0x33b2: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_33b5:
	/* 0x33b5: jne    2e33 <trace_security_mmap_file+0x2e33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11827ULL;
	}
x86_l_33bb:
	/* 0x33bb: cmp    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c0:
	/* 0x33c0: je     3b1e <trace_security_mmap_file+0x3b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15134ULL;
	}
x86_l_33c6:
	/* 0x33c6: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_33c8:
	/* 0x33c8: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_33d0:
	/* 0x33d0: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_33d5:
	/* 0x33d5: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_33dd:
	/* 0x33dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33e2:
	/* 0x33e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_33e9:
	/* 0x33e9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33ee:
	/* 0x33ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f0:
	/* 0x33f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f3:
	/* 0x33f3: je     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_340d;
	}
x86_l_33f5:
	/* 0x33f5: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_33fd:
	/* 0x33fd: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3400:
	/* 0x3400: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_3407:
	/* 0x3407: jbe    3886 <trace_security_mmap_file+0x3886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 14470ULL;
	}
x86_l_340d:
	/* 0x340d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3410:
	/* 0x3410: and    QWORD PTR [r14+0x80],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_3417:
	/* 0x3417: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_341c:
	/* 0x341c: je     3a69 <trace_security_mmap_file+0x3a69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14953ULL;
	}
x86_l_3422:
	/* 0x3422: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_3429:
	/* 0x3429: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_342d:
	/* 0x342d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3432:
	/* 0x3432: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3437:
	/* 0x3437: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_343c:
	/* 0x343c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_343f:
	/* 0x343f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3441:
	/* 0x3441: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3446:
	/* 0x3446: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_344b:
	/* 0x344b: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_344f:
	/* 0x344f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3454:
	/* 0x3454: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3459:
	/* 0x3459: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_345e:
	/* 0x345e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3460:
	/* 0x3460: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3465:
	/* 0x3465: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3469:
	/* 0x3469: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_346e:
	/* 0x346e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3473:
	/* 0x3473: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3478:
	/* 0x3478: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347a:
	/* 0x347a: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_347f:
	/* 0x347f: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3484:
	/* 0x3484: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3489:
	/* 0x3489: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_348e:
	/* 0x348e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3493:
	/* 0x3493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3495:
	/* 0x3495: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3499:
	/* 0x3499: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_349d:
	/* 0x349d: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a1:
	/* 0x34a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34a6:
	/* 0x34a6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ab:
	/* 0x34ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34b0:
	/* 0x34b0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_34b3:
	/* 0x34b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b5:
	/* 0x34b5: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ba:
	/* 0x34ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34bf:
	/* 0x34bf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34c4:
	/* 0x34c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34c9:
	/* 0x34c9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_34cc:
	/* 0x34cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ce:
	/* 0x34ce: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34d2:
	/* 0x34d2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_34d6:
	/* 0x34d6: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_34da:
	/* 0x34da: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34de:
	/* 0x34de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34e3:
	/* 0x34e3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34e8:
	/* 0x34e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34ed:
	/* 0x34ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ef:
	/* 0x34ef: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34f3:
	/* 0x34f3: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_34f7:
	/* 0x34f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34fc:
	/* 0x34fc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3501:
	/* 0x3501: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3506:
	/* 0x3506: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3509:
	/* 0x3509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350b:
	/* 0x350b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3510:
	/* 0x3510: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3514:
	/* 0x3514: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3519:
	/* 0x3519: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_351e:
	/* 0x351e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3523:
	/* 0x3523: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3525:
	/* 0x3525: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_352a:
	/* 0x352a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_352f:
	/* 0x352f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3534:
	/* 0x3534: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3539:
	/* 0x3539: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_353c:
	/* 0x353c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353e:
	/* 0x353e: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3542:
	/* 0x3542: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3546:
	/* 0x3546: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_354a:
	/* 0x354a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_354e:
	/* 0x354e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3553:
	/* 0x3553: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3558:
	/* 0x3558: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_355d:
	/* 0x355d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355f:
	/* 0x355f: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3563:
	/* 0x3563: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3567:
	/* 0x3567: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_356c:
	/* 0x356c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3571:
	/* 0x3571: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3576:
	/* 0x3576: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3579:
	/* 0x3579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_357b:
	/* 0x357b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3580:
	/* 0x3580: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3585:
	/* 0x3585: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_358a:
	/* 0x358a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_358f:
	/* 0x358f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3592:
	/* 0x3592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3594:
	/* 0x3594: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3598:
	/* 0x3598: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_359c:
	/* 0x359c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_35a0:
	/* 0x35a0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35a4:
	/* 0x35a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35a9:
	/* 0x35a9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35ae:
	/* 0x35ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35b3:
	/* 0x35b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b5:
	/* 0x35b5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35ba:
	/* 0x35ba: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_35be:
	/* 0x35be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35c3:
	/* 0x35c3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35c8:
	/* 0x35c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35cd:
	/* 0x35cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35cf:
	/* 0x35cf: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35d3:
	/* 0x35d3: lea    r15,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d8:
	/* 0x35d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35dd:
	/* 0x35dd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35e2:
	/* 0x35e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35e7:
	/* 0x35e7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35ea:
	/* 0x35ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ec:
	/* 0x35ec: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35f1:
	/* 0x35f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35f6:
	/* 0x35f6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35fb:
	/* 0x35fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3600:
	/* 0x3600: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3603:
	/* 0x3603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3605:
	/* 0x3605: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3609:
	/* 0x3609: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_360d:
	/* 0x360d: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3611:
	/* 0x3611: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3615:
	/* 0x3615: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_361a:
	/* 0x361a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_361f:
	/* 0x361f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3624:
	/* 0x3624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3626:
	/* 0x3626: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_362b:
	/* 0x362b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_362f:
	/* 0x362f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3634:
	/* 0x3634: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3639:
	/* 0x3639: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_363e:
	/* 0x363e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3640:
	/* 0x3640: cmp    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_3644:
	/* 0x3644: jne    369c <trace_security_mmap_file+0x369c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13980ULL;
	}
x86_l_3646:
	/* 0x3646: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_364b:
	/* 0x364b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3650:
	/* 0x3650: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3655:
	/* 0x3655: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3658:
	/* 0x3658: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365a:
	/* 0x365a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_365f:
	/* 0x365f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3664:
	/* 0x3664: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3669:
	/* 0x3669: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_366e:
	/* 0x366e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3671:
	/* 0x3671: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3673:
	/* 0x3673: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3677:
	/* 0x3677: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_367b:
	/* 0x367b: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_367f:
	/* 0x367f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3683:
	/* 0x3683: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3688:
	/* 0x3688: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 13965ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13976ULL: goto x86_l_3698;
	case 13980ULL: goto x86_l_369c;
	case 13984ULL: goto x86_l_36a0;
	case 13991ULL: goto x86_l_36a7;
	case 13996ULL: goto x86_l_36ac;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14009ULL: goto x86_l_36b9;
	case 14011ULL: goto x86_l_36bb;
	case 14016ULL: goto x86_l_36c0;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14035ULL: goto x86_l_36d3;
	case 14037ULL: goto x86_l_36d5;
	case 14042ULL: goto x86_l_36da;
	case 14047ULL: goto x86_l_36df;
	case 14052ULL: goto x86_l_36e4;
	case 14057ULL: goto x86_l_36e9;
	case 14059ULL: goto x86_l_36eb;
	case 14063ULL: goto x86_l_36ef;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14074ULL: goto x86_l_36fa;
	case 14078ULL: goto x86_l_36fe;
	case 14082ULL: goto x86_l_3702;
	case 14087ULL: goto x86_l_3707;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14099ULL: goto x86_l_3713;
	case 14104ULL: goto x86_l_3718;
	case 14108ULL: goto x86_l_371c;
	case 14113ULL: goto x86_l_3721;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14127ULL: goto x86_l_372f;
	case 14132ULL: goto x86_l_3734;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14143ULL: goto x86_l_373f;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14157ULL: goto x86_l_374d;
	case 14162ULL: goto x86_l_3752;
	case 14165ULL: goto x86_l_3755;
	case 14167ULL: goto x86_l_3757;
	case 14172ULL: goto x86_l_375c;
	case 14176ULL: goto x86_l_3760;
	case 14181ULL: goto x86_l_3765;
	case 14186ULL: goto x86_l_376a;
	case 14191ULL: goto x86_l_376f;
	case 14194ULL: goto x86_l_3772;
	case 14196ULL: goto x86_l_3774;
	case 14201ULL: goto x86_l_3779;
	case 14209ULL: goto x86_l_3781;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14220ULL: goto x86_l_378c;
	case 14228ULL: goto x86_l_3794;
	case 14236ULL: goto x86_l_379c;
	case 14241ULL: goto x86_l_37a1;
	case 14246ULL: goto x86_l_37a6;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14258ULL: goto x86_l_37b2;
	case 14263ULL: goto x86_l_37b7;
	case 14266ULL: goto x86_l_37ba;
	case 14268ULL: goto x86_l_37bc;
	case 14273ULL: goto x86_l_37c1;
	case 14278ULL: goto x86_l_37c6;
	case 14283ULL: goto x86_l_37cb;
	case 14288ULL: goto x86_l_37d0;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14308ULL: goto x86_l_37e4;
	case 14313ULL: goto x86_l_37e9;
	case 14315ULL: goto x86_l_37eb;
	case 14318ULL: goto x86_l_37ee;
	case 14322ULL: goto x86_l_37f2;
	case 14327ULL: goto x86_l_37f7;
	case 14332ULL: goto x86_l_37fc;
	case 14335ULL: goto x86_l_37ff;
	case 14337ULL: goto x86_l_3801;
	case 14342ULL: goto x86_l_3806;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14363ULL: goto x86_l_381b;
	case 14365ULL: goto x86_l_381d;
	case 14373ULL: goto x86_l_3825;
	case 14377ULL: goto x86_l_3829;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14391ULL: goto x86_l_3837;
	case 14396ULL: goto x86_l_383c;
	case 14399ULL: goto x86_l_383f;
	case 14401ULL: goto x86_l_3841;
	case 14403ULL: goto x86_l_3843;
	case 14405ULL: goto x86_l_3845;
	case 14409ULL: goto x86_l_3849;
	case 14417ULL: goto x86_l_3851;
	case 14422ULL: goto x86_l_3856;
	case 14427ULL: goto x86_l_385b;
	case 14430ULL: goto x86_l_385e;
	case 14436ULL: goto x86_l_3864;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14460ULL: goto x86_l_387c;
	case 14463ULL: goto x86_l_387f;
	case 14465ULL: goto x86_l_3881;
	case 14470ULL: goto x86_l_3886;
	case 14478ULL: goto x86_l_388e;
	case 14484ULL: goto x86_l_3894;
	case 14486ULL: goto x86_l_3896;
	case 14488ULL: goto x86_l_3898;
	case 14494ULL: goto x86_l_389e;
	case 14497ULL: goto x86_l_38a1;
	case 14502ULL: goto x86_l_38a6;
	case 14508ULL: goto x86_l_38ac;
	case 14514ULL: goto x86_l_38b2;
	case 14516ULL: goto x86_l_38b4;
	case 14519ULL: goto x86_l_38b7;
	case 14521ULL: goto x86_l_38b9;
	case 14527ULL: goto x86_l_38bf;
	case 14530ULL: goto x86_l_38c2;
	case 14533ULL: goto x86_l_38c5;
	case 14539ULL: goto x86_l_38cb;
	case 14545ULL: goto x86_l_38d1;
	case 14547ULL: goto x86_l_38d3;
	case 14553ULL: goto x86_l_38d9;
	case 14559ULL: goto x86_l_38df;
	case 14562ULL: goto x86_l_38e2;
	case 14564ULL: goto x86_l_38e4;
	case 14566ULL: goto x86_l_38e6;
	case 14568ULL: goto x86_l_38e8;
	case 14571ULL: goto x86_l_38eb;
	case 14573ULL: goto x86_l_38ed;
	case 14579ULL: goto x86_l_38f3;
	case 14585ULL: goto x86_l_38f9;
	case 14587ULL: goto x86_l_38fb;
	case 14596ULL: goto x86_l_3904;
	case 14601ULL: goto x86_l_3909;
	case 14604ULL: goto x86_l_390c;
	case 14606ULL: goto x86_l_390e;
	case 14609ULL: goto x86_l_3911;
	case 14611ULL: goto x86_l_3913;
	case 14614ULL: goto x86_l_3916;
	case 14616ULL: goto x86_l_3918;
	case 14621ULL: goto x86_l_391d;
	case 14624ULL: goto x86_l_3920;
	case 14630ULL: goto x86_l_3926;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14645ULL: goto x86_l_3935;
	case 14650ULL: goto x86_l_393a;
	case 14654ULL: goto x86_l_393e;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14668ULL: goto x86_l_394c;
	case 14670ULL: goto x86_l_394e;
	case 14675ULL: goto x86_l_3953;
	case 14679ULL: goto x86_l_3957;
	case 14682ULL: goto x86_l_395a;
	case 14687ULL: goto x86_l_395f;
	case 14689ULL: goto x86_l_3961;
	case 14694ULL: goto x86_l_3966;
	case 14698ULL: goto x86_l_396a;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14710ULL: goto x86_l_3976;
	case 14714ULL: goto x86_l_397a;
	case 14718ULL: goto x86_l_397e;
	case 14723ULL: goto x86_l_3983;
	case 14728ULL: goto x86_l_3988;
	case 14733ULL: goto x86_l_398d;
	case 14736ULL: goto x86_l_3990;
	case 14738ULL: goto x86_l_3992;
	case 14743ULL: goto x86_l_3997;
	case 14748ULL: goto x86_l_399c;
	case 14752ULL: goto x86_l_39a0;
	case 14757ULL: goto x86_l_39a5;
	case 14762ULL: goto x86_l_39aa;
	case 14767ULL: goto x86_l_39af;
	case 14769ULL: goto x86_l_39b1;
	case 14774ULL: goto x86_l_39b6;
	case 14777ULL: goto x86_l_39b9;
	case 14783ULL: goto x86_l_39bf;
	case 14788ULL: goto x86_l_39c4;
	case 14791ULL: goto x86_l_39c7;
	case 14797ULL: goto x86_l_39cd;
	case 14801ULL: goto x86_l_39d1;
	case 14806ULL: goto x86_l_39d6;
	case 14811ULL: goto x86_l_39db;
	case 14816ULL: goto x86_l_39e0;
	case 14818ULL: goto x86_l_39e2;
	case 14822ULL: goto x86_l_39e6;
	case 14824ULL: goto x86_l_39e8;
	case 14830ULL: goto x86_l_39ee;
	case 14833ULL: goto x86_l_39f1;
	case 14835ULL: goto x86_l_39f3;
	case 14841ULL: goto x86_l_39f9;
	case 14846ULL: goto x86_l_39fe;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14864ULL: goto x86_l_3a10;
	case 14867ULL: goto x86_l_3a13;
	case 14873ULL: goto x86_l_3a19;
	case 14877ULL: goto x86_l_3a1d;
	case 14883ULL: goto x86_l_3a23;
	case 14888ULL: goto x86_l_3a28;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14905ULL: goto x86_l_3a39;
	case 14912ULL: goto x86_l_3a40;
	case 14915ULL: goto x86_l_3a43;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14931ULL: goto x86_l_3a53;
	case 14934ULL: goto x86_l_3a56;
	case 14936ULL: goto x86_l_3a58;
	case 14941ULL: goto x86_l_3a5d;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14953ULL: goto x86_l_3a69;
	case 14960ULL: goto x86_l_3a70;
	case 14962ULL: goto x86_l_3a72;
	case 14963ULL: goto x86_l_3a73;
	case 14968ULL: goto x86_l_3a78;
	case 14971ULL: goto x86_l_3a7b;
	case 14973ULL: goto x86_l_3a7d;
	case 14975ULL: goto x86_l_3a7f;
	case 14977ULL: goto x86_l_3a81;
	case 14982ULL: goto x86_l_3a86;
	case 14989ULL: goto x86_l_3a8d;
	case 14997ULL: goto x86_l_3a95;
	case 14999ULL: goto x86_l_3a97;
	case 15006ULL: goto x86_l_3a9e;
	case 15011ULL: goto x86_l_3aa3;
	case 15018ULL: goto x86_l_3aaa;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15034ULL: goto x86_l_3aba;
	case 15039ULL: goto x86_l_3abf;
	case 15041ULL: goto x86_l_3ac1;
	case 15048ULL: goto x86_l_3ac8;
	case 15051ULL: goto x86_l_3acb;
	case 15053ULL: goto x86_l_3acd;
	case 15058ULL: goto x86_l_3ad2;
	case 15061ULL: goto x86_l_3ad5;
	case 15069ULL: goto x86_l_3add;
	case 15071ULL: goto x86_l_3adf;
	case 15074ULL: goto x86_l_3ae2;
	case 15076ULL: goto x86_l_3ae4;
	case 15079ULL: goto x86_l_3ae7;
	case 15083ULL: goto x86_l_3aeb;
	case 15086ULL: goto x86_l_3aee;
	case 15088ULL: goto x86_l_3af0;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15103ULL: goto x86_l_3aff;
	case 15106ULL: goto x86_l_3b02;
	case 15109ULL: goto x86_l_3b05;
	case 15114ULL: goto x86_l_3b0a;
	case 15117ULL: goto x86_l_3b0d;
	case 15122ULL: goto x86_l_3b12;
	case 15125ULL: goto x86_l_3b15;
	case 15128ULL: goto x86_l_3b18;
	case 15131ULL: goto x86_l_3b1b;
	case 15134ULL: goto x86_l_3b1e;
	case 15139ULL: goto x86_l_3b23;
	case 15142ULL: goto x86_l_3b26;
	case 15145ULL: goto x86_l_3b29;
	case 15148ULL: goto x86_l_3b2c;
	case 15155ULL: goto x86_l_3b33;
	case 15158ULL: goto x86_l_3b36;
	case 15163ULL: goto x86_l_3b3b;
	case 15166ULL: goto x86_l_3b3e;
	case 15172ULL: goto x86_l_3b44;
	case 15176ULL: goto x86_l_3b48;
	case 15181ULL: goto x86_l_3b4d;
	case 15187ULL: goto x86_l_3b53;
	case 15192ULL: goto x86_l_3b58;
	case 15196ULL: goto x86_l_3b5c;
	case 15200ULL: goto x86_l_3b60;
	case 15205ULL: goto x86_l_3b65;
	case 15210ULL: goto x86_l_3b6a;
	case 15212ULL: goto x86_l_3b6c;
	case 15217ULL: goto x86_l_3b71;
	case 15221ULL: goto x86_l_3b75;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15231ULL: goto x86_l_3b7f;
	case 15236ULL: goto x86_l_3b84;
	case 15240ULL: goto x86_l_3b88;
	case 15245ULL: goto x86_l_3b8d;
	case 15250ULL: goto x86_l_3b92;
	case 15252ULL: goto x86_l_3b94;
	case 15256ULL: goto x86_l_3b98;
	case 15260ULL: goto x86_l_3b9c;
	case 15265ULL: goto x86_l_3ba1;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15278ULL: goto x86_l_3bae;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15290ULL: goto x86_l_3bba;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15304ULL: goto x86_l_3bc8;
	case 15309ULL: goto x86_l_3bcd;
	case 15311ULL: goto x86_l_3bcf;
	case 15316ULL: goto x86_l_3bd4;
	case 15319ULL: goto x86_l_3bd7;
	case 15325ULL: goto x86_l_3bdd;
	case 15330ULL: goto x86_l_3be2;
	case 15333ULL: goto x86_l_3be5;
	case 15339ULL: goto x86_l_3beb;
	case 15343ULL: goto x86_l_3bef;
	case 15348ULL: goto x86_l_3bf4;
	case 15353ULL: goto x86_l_3bf9;
	case 15358ULL: goto x86_l_3bfe;
	case 15360ULL: goto x86_l_3c00;
	case 15364ULL: goto x86_l_3c04;
	case 15366ULL: goto x86_l_3c06;
	case 15372ULL: goto x86_l_3c0c;
	case 15375ULL: goto x86_l_3c0f;
	case 15377ULL: goto x86_l_3c11;
	case 15383ULL: goto x86_l_3c17;
	case 15388ULL: goto x86_l_3c1c;
	case 15394ULL: goto x86_l_3c22;
	case 15399ULL: goto x86_l_3c27;
	case 15404ULL: goto x86_l_3c2c;
	case 15406ULL: goto x86_l_3c2e;
	case 15409ULL: goto x86_l_3c31;
	case 15415ULL: goto x86_l_3c37;
	case 15419ULL: goto x86_l_3c3b;
	case 15425ULL: goto x86_l_3c41;
	case 15430ULL: goto x86_l_3c46;
	case 15434ULL: goto x86_l_3c4a;
	case 15437ULL: goto x86_l_3c4d;
	case 15442ULL: goto x86_l_3c52;
	case 15447ULL: goto x86_l_3c57;
	case 15450ULL: goto x86_l_3c5a;
	case 15456ULL: goto x86_l_3c60;
	case 15460ULL: goto x86_l_3c64;
	case 15465ULL: goto x86_l_3c69;
	case 15471ULL: goto x86_l_3c6f;
	case 15476ULL: goto x86_l_3c74;
	case 15480ULL: goto x86_l_3c78;
	case 15484ULL: goto x86_l_3c7c;
	case 15489ULL: goto x86_l_3c81;
	case 15494ULL: goto x86_l_3c86;
	case 15496ULL: goto x86_l_3c88;
	case 15501ULL: goto x86_l_3c8d;
	case 15505ULL: goto x86_l_3c91;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15515ULL: goto x86_l_3c9b;
	case 15520ULL: goto x86_l_3ca0;
	case 15524ULL: goto x86_l_3ca4;
	case 15529ULL: goto x86_l_3ca9;
	case 15534ULL: goto x86_l_3cae;
	case 15536ULL: goto x86_l_3cb0;
	case 15540ULL: goto x86_l_3cb4;
	case 15544ULL: goto x86_l_3cb8;
	case 15549ULL: goto x86_l_3cbd;
	case 15554ULL: goto x86_l_3cc2;
	case 15559ULL: goto x86_l_3cc7;
	case 15562ULL: goto x86_l_3cca;
	case 15564ULL: goto x86_l_3ccc;
	case 15569ULL: goto x86_l_3cd1;
	case 15574ULL: goto x86_l_3cd6;
	case 15578ULL: goto x86_l_3cda;
	case 15583ULL: goto x86_l_3cdf;
	case 15588ULL: goto x86_l_3ce4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_368d:
	/* 0x368d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3692:
	/* 0x3692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3694:
	/* 0x3694: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3698:
	/* 0x3698: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_369c:
	/* 0x369c: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36a0:
	/* 0x36a0: lea    rbp,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_36a7:
	/* 0x36a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36ac:
	/* 0x36ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36b1:
	/* 0x36b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36b6:
	/* 0x36b6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_36b9:
	/* 0x36b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36bb:
	/* 0x36bb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36c0:
	/* 0x36c0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36c4:
	/* 0x36c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36c9:
	/* 0x36c9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36ce:
	/* 0x36ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36d3:
	/* 0x36d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d5:
	/* 0x36d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36da:
	/* 0x36da: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36df:
	/* 0x36df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36e4:
	/* 0x36e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36e9:
	/* 0x36e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36eb:
	/* 0x36eb: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ef:
	/* 0x36ef: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_36f3:
	/* 0x36f3: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_36f8:
	/* 0x36f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36fa:
	/* 0x36fa: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36fe:
	/* 0x36fe: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3702:
	/* 0x3702: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3707:
	/* 0x3707: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_370c:
	/* 0x370c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3711:
	/* 0x3711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3713:
	/* 0x3713: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3718:
	/* 0x3718: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_371c:
	/* 0x371c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3721:
	/* 0x3721: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3725:
	/* 0x3725: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_372a:
	/* 0x372a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_372f:
	/* 0x372f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3734:
	/* 0x3734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3736:
	/* 0x3736: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_373b:
	/* 0x373b: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_373f:
	/* 0x373f: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3743:
	/* 0x3743: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3748:
	/* 0x3748: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_374d:
	/* 0x374d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3752:
	/* 0x3752: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3755:
	/* 0x3755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3757:
	/* 0x3757: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_375c:
	/* 0x375c: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3760:
	/* 0x3760: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3765:
	/* 0x3765: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_376a:
	/* 0x376a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_376f:
	/* 0x376f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3772:
	/* 0x3772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3774:
	/* 0x3774: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_3779:
	/* 0x3779: mov    r15,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3781:
	/* 0x3781: je     3788 <trace_security_mmap_file+0x3788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3788;
	}
x86_l_3783:
	/* 0x3783: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_3788:
	/* 0x3788: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_378c:
	/* 0x378c: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_3794:
	/* 0x3794: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_379c:
	/* 0x379c: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_37a1:
	/* 0x37a1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_37a6:
	/* 0x37a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37a8:
	/* 0x37a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ad:
	/* 0x37ad: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37b2:
	/* 0x37b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b7:
	/* 0x37b7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_37ba:
	/* 0x37ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37bc:
	/* 0x37bc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37c1:
	/* 0x37c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37c6:
	/* 0x37c6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37cb:
	/* 0x37cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d0:
	/* 0x37d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d2:
	/* 0x37d2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37d7:
	/* 0x37d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37dc:
	/* 0x37dc: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37e1:
	/* 0x37e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_37e4:
	/* 0x37e4: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_37e9:
	/* 0x37e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37eb:
	/* 0x37eb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_37ee:
	/* 0x37ee: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_37f2:
	/* 0x37f2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_37f7:
	/* 0x37f7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_37fc:
	/* 0x37fc: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_37ff:
	/* 0x37ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3801:
	/* 0x3801: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3806:
	/* 0x3806: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_380e:
	/* 0x380e: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_3813:
	/* 0x3813: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_381b:
	/* 0x381b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_381d:
	/* 0x381d: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3825:
	/* 0x3825: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_3829:
	/* 0x3829: je     3849 <trace_security_mmap_file+0x3849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3849;
	}
x86_l_382b:
	/* 0x382b: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_3830:
	/* 0x3830: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_3837:
	/* 0x3837: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_383c:
	/* 0x383c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_383f:
	/* 0x383f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3841:
	/* 0x3841: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3843:
	/* 0x3843: js     3849 <trace_security_mmap_file+0x3849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3849;
	}
x86_l_3845:
	/* 0x3845: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3849:
	/* 0x3849: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3851:
	/* 0x3851: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_3856:
	/* 0x3856: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_385b:
	/* 0x385b: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_385e:
	/* 0x385e: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_3864:
	/* 0x3864: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3868:
	/* 0x3868: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_386d:
	/* 0x386d: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_3874:
	/* 0x3874: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3879:
	/* 0x3879: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_387c:
	/* 0x387c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_387f:
	/* 0x387f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3881:
	/* 0x3881: jmp    3a69 <trace_security_mmap_file+0x3a69> */
	goto x86_l_3a69;
x86_l_3886:
	/* 0x3886: mov    edx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_388e:
	/* 0x388e: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_3894:
	/* 0x3894: jbe    38b4 <trace_security_mmap_file+0x38b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_38b4;
	}
x86_l_3896:
	/* 0x3896: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3898:
	/* 0x3898: add    ecx,0xffffff05 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967045ULL);
x86_l_389e:
	/* 0x389e: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_38a1:
	/* 0x38a1: mov    edx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 255ULL);
x86_l_38a6:
	/* 0x38a6: cmp    ecx,0x7c00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31744ULL);
x86_l_38ac:
	/* 0x38ac: ja     340d <trace_security_mmap_file+0x340d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13325ULL;
	}
x86_l_38b2:
	/* 0x38b2: jmp    38e2 <trace_security_mmap_file+0x38e2> */
	goto x86_l_38e2;
x86_l_38b4:
	/* 0x38b4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38b7:
	/* 0x38b7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_38b9:
	/* 0x38b9: je     3410 <trace_security_mmap_file+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13328ULL;
	}
x86_l_38bf:
	/* 0x38bf: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38c2:
	/* 0x38c2: add    esi,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_38c5:
	/* 0x38c5: cmp    esi,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 32000ULL);
x86_l_38cb:
	/* 0x38cb: ja     3410 <trace_security_mmap_file+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13328ULL;
	}
x86_l_38d1:
	/* 0x38d1: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_38d3:
	/* 0x38d3: and    edx,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 255ULL);
x86_l_38d9:
	/* 0x38d9: je     3a78 <trace_security_mmap_file+0x3a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a78;
	}
x86_l_38df:
	/* 0x38df: add    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_38e2:
	/* 0x38e2: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_38e4:
	/* 0x38e4: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38e6:
	/* 0x38e6: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_38e8:
	/* 0x38e8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38eb:
	/* 0x38eb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38ed:
	/* 0x38ed: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_38f3:
	/* 0x38f3: ja     3410 <trace_security_mmap_file+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13328ULL;
	}
x86_l_38f9:
	/* 0x38f9: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_38fb:
	/* 0x38fb: movzx  edi,BYTE PTR [r14+rdi*1+0x89] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 0, X86_WIDTH_8), 137ULL);
x86_l_3904:
	/* 0x3904: mov    BYTE PTR [rax+rdx*1+0x4],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_3909:
	/* 0x3909: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_390c:
	/* 0x390c: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_390e:
	/* 0x390e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3911:
	/* 0x3911: jne    38ed <trace_security_mmap_file+0x38ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ed;
	}
x86_l_3913:
	/* 0x3913: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_3916:
	/* 0x3916: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_3918:
	/* 0x3918: jmp    3a7f <trace_security_mmap_file+0x3a7f> */
	goto x86_l_3a7f;
x86_l_391d:
	/* 0x391d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3920:
	/* 0x3920: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_3926:
	/* 0x3926: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_392a:
	/* 0x392a: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_392f:
	/* 0x392f: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_3935:
	/* 0x3935: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_393a:
	/* 0x393a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393e:
	/* 0x393e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3942:
	/* 0x3942: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3947:
	/* 0x3947: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_394c:
	/* 0x394c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_394e:
	/* 0x394e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3953:
	/* 0x3953: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3957:
	/* 0x3957: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_395a:
	/* 0x395a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_395f:
	/* 0x395f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3961:
	/* 0x3961: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3966:
	/* 0x3966: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_396a:
	/* 0x396a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_396f:
	/* 0x396f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3974:
	/* 0x3974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3976:
	/* 0x3976: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397a:
	/* 0x397a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_397e:
	/* 0x397e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3983:
	/* 0x3983: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3988:
	/* 0x3988: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_398d:
	/* 0x398d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3990:
	/* 0x3990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3992:
	/* 0x3992: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3997:
	/* 0x3997: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_399c:
	/* 0x399c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_39a0:
	/* 0x39a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39a5:
	/* 0x39a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39aa:
	/* 0x39aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39af:
	/* 0x39af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b1:
	/* 0x39b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b6:
	/* 0x39b6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_39b9:
	/* 0x39b9: je     3c57 <trace_security_mmap_file+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_39bf:
	/* 0x39bf: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39c4:
	/* 0x39c4: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_39c7:
	/* 0x39c7: je     3c57 <trace_security_mmap_file+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_39cd:
	/* 0x39cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_39d1:
	/* 0x39d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39d6:
	/* 0x39d6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39db:
	/* 0x39db: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39e0:
	/* 0x39e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39e2:
	/* 0x39e2: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_39e6:
	/* 0x39e6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_39e8:
	/* 0x39e8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_39ee:
	/* 0x39ee: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_39f1:
	/* 0x39f1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39f3:
	/* 0x39f3: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_39f9:
	/* 0x39f9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39fe:
	/* 0x39fe: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3a04:
	/* 0x3a04: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a09:
	/* 0x3a09: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3a0e:
	/* 0x3a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a10:
	/* 0x3a10: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a13:
	/* 0x3a13: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_3a19:
	/* 0x3a19: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3a1d:
	/* 0x3a1d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3a23:
	/* 0x3a23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a28:
	/* 0x3a28: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3a2c:
	/* 0x3a2c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a2f:
	/* 0x3a2f: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a34:
	/* 0x3a34: jmp    3cb8 <trace_security_mmap_file+0x3cb8> */
	goto x86_l_3cb8;
x86_l_3a39:
	/* 0x3a39: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_3a40:
	/* 0x3a40: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3a43:
	/* 0x3a43: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3a47:
	/* 0x3a47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a4c:
	/* 0x3a4c: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_3a51:
	/* 0x3a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a53:
	/* 0x3a53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a56:
	/* 0x3a56: jne    3a67 <trace_security_mmap_file+0x3a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a67;
	}
x86_l_3a58:
	/* 0x3a58: movzx  eax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3a5d:
	/* 0x3a5d: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_3a62:
	/* 0x3a62: jmp    aee <trace_security_mmap_file+0xaee> */
	return 2798ULL;
x86_l_3a67:
	/* 0x3a67: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a69:
	/* 0x3a69: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_3a70:
	/* 0x3a70: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3a72:
	/* 0x3a72: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3a73:
	/* 0x3a73: jmp    5f79 <trace_security_mmap_file+0x5f79> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3a78:
	/* 0x3a78: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_3a7b:
	/* 0x3a7b: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_3a7d:
	/* 0x3a7d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a7f:
	/* 0x3a7f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3a81:
	/* 0x3a81: mov    BYTE PTR [rax+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_3a86:
	/* 0x3a86: lea    ecx,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_3a8d:
	/* 0x3a8d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3a95:
	/* 0x3a95: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a97:
	/* 0x3a97: mov    rbx,QWORD PTR [r14+0x7e08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_3a9e:
	/* 0x3a9e: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_3aaa:
	/* 0x3aaa: mov    DWORD PTR [rsp+0x24],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3aae:
	/* 0x3aae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ab3:
	/* 0x3ab3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_suffix_version)));
x86_l_3aba:
	/* 0x3aba: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3abf:
	/* 0x3abf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac1:
	/* 0x3ac1: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3ac8:
	/* 0x3ac8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3acb:
	/* 0x3acb: je     3af0 <trace_security_mmap_file+0x3af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af0;
	}
x86_l_3acd:
	/* 0x3acd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ad2:
	/* 0x3ad2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3ad5:
	/* 0x3ad5: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3add:
	/* 0x3add: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3adf:
	/* 0x3adf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ae2:
	/* 0x3ae2: je     3af0 <trace_security_mmap_file+0x3af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af0;
	}
x86_l_3ae4:
	/* 0x3ae4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ae7:
	/* 0x3ae7: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aeb:
	/* 0x3aeb: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3aee:
	/* 0x3aee: jmp    3af2 <trace_security_mmap_file+0x3af2> */
	goto x86_l_3af2;
x86_l_3af0:
	/* 0x3af0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3af2:
	/* 0x3af2: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3af7:
	/* 0x3af7: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3aff:
	/* 0x3aff: and    r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3b02:
	/* 0x3b02: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b05:
	/* 0x3b05: andn   rax,rbx,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_3b0a:
	/* 0x3b0a: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b0d:
	/* 0x3b0d: andn   rax,r12,rbx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_3b12:
	/* 0x3b12: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b15:
	/* 0x3b15: and    r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3b18:
	/* 0x3b18: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b1b:
	/* 0x3b1b: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_3b1e:
	/* 0x3b1e: andn   rax,rsi,rdx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3b23:
	/* 0x3b23: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3b26:
	/* 0x3b26: or     r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b29:
	/* 0x3b29: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b2c:
	/* 0x3b2c: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_3b33:
	/* 0x3b33: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_3b36:
	/* 0x3b36: jmp    3410 <trace_security_mmap_file+0x3410> */
	return 13328ULL;
x86_l_3b3b:
	/* 0x3b3b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3b3e:
	/* 0x3b3e: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_3b44:
	/* 0x3b44: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b48:
	/* 0x3b48: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3b4d:
	/* 0x3b4d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_3b53:
	/* 0x3b53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b58:
	/* 0x3b58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b5c:
	/* 0x3b5c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b60:
	/* 0x3b60: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b65:
	/* 0x3b65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b6a:
	/* 0x3b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6c:
	/* 0x3b6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b71:
	/* 0x3b71: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b75:
	/* 0x3b75: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b78:
	/* 0x3b78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b7d:
	/* 0x3b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b7f:
	/* 0x3b7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b84:
	/* 0x3b84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b88:
	/* 0x3b88: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b8d:
	/* 0x3b8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b92:
	/* 0x3b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b94:
	/* 0x3b94: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b98:
	/* 0x3b98: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b9c:
	/* 0x3b9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ba1:
	/* 0x3ba1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ba6:
	/* 0x3ba6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bab:
	/* 0x3bab: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3bae:
	/* 0x3bae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bb0:
	/* 0x3bb0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bb5:
	/* 0x3bb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bba:
	/* 0x3bba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3bbe:
	/* 0x3bbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bc3:
	/* 0x3bc3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bc8:
	/* 0x3bc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bcd:
	/* 0x3bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bcf:
	/* 0x3bcf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd4:
	/* 0x3bd4: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3bd7:
	/* 0x3bd7: je     3d73 <trace_security_mmap_file+0x3d73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15731ULL;
	}
x86_l_3bdd:
	/* 0x3bdd: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3be2:
	/* 0x3be2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3be5:
	/* 0x3be5: je     3d73 <trace_security_mmap_file+0x3d73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15731ULL;
	}
x86_l_3beb:
	/* 0x3beb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3bef:
	/* 0x3bef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bf4:
	/* 0x3bf4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bf9:
	/* 0x3bf9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3bfe:
	/* 0x3bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c00:
	/* 0x3c00: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3c04:
	/* 0x3c04: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3c06:
	/* 0x3c06: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c0c:
	/* 0x3c0c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3c0f:
	/* 0x3c0f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c11:
	/* 0x3c11: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_3c17:
	/* 0x3c17: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c1c:
	/* 0x3c1c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3c22:
	/* 0x3c22: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c27:
	/* 0x3c27: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3c2c:
	/* 0x3c2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c2e:
	/* 0x3c2e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c31:
	/* 0x3c31: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_3c37:
	/* 0x3c37: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3c3b:
	/* 0x3c3b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3c41:
	/* 0x3c41: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c46:
	/* 0x3c46: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3c4a:
	/* 0x3c4a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c4d:
	/* 0x3c4d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c52:
	/* 0x3c52: jmp    3dd4 <trace_security_mmap_file+0x3dd4> */
	return 15828ULL;
x86_l_3c57:
	/* 0x3c57: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3c5a:
	/* 0x3c5a: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_3c60:
	/* 0x3c60: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c64:
	/* 0x3c64: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3c69:
	/* 0x3c69: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_3c6f:
	/* 0x3c6f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c74:
	/* 0x3c74: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c78:
	/* 0x3c78: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c7c:
	/* 0x3c7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c81:
	/* 0x3c81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c86:
	/* 0x3c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c88:
	/* 0x3c88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c8d:
	/* 0x3c8d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c91:
	/* 0x3c91: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c94:
	/* 0x3c94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c99:
	/* 0x3c99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9b:
	/* 0x3c9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ca0:
	/* 0x3ca0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ca4:
	/* 0x3ca4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cae:
	/* 0x3cae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb0:
	/* 0x3cb0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cb4:
	/* 0x3cb4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3cb8:
	/* 0x3cb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cbd:
	/* 0x3cbd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cc2:
	/* 0x3cc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc7:
	/* 0x3cc7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3cca:
	/* 0x3cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ccc:
	/* 0x3ccc: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cd1:
	/* 0x3cd1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd6:
	/* 0x3cd6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3cda:
	/* 0x3cda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cdf:
	/* 0x3cdf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ce4:
	/* 0x3ce4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 15593ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15593ULL: goto x86_l_3ce9;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15603ULL: goto x86_l_3cf3;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15617ULL: goto x86_l_3d01;
	case 15623ULL: goto x86_l_3d07;
	case 15627ULL: goto x86_l_3d0b;
	case 15632ULL: goto x86_l_3d10;
	case 15637ULL: goto x86_l_3d15;
	case 15642ULL: goto x86_l_3d1a;
	case 15644ULL: goto x86_l_3d1c;
	case 15648ULL: goto x86_l_3d20;
	case 15650ULL: goto x86_l_3d22;
	case 15656ULL: goto x86_l_3d28;
	case 15659ULL: goto x86_l_3d2b;
	case 15661ULL: goto x86_l_3d2d;
	case 15667ULL: goto x86_l_3d33;
	case 15672ULL: goto x86_l_3d38;
	case 15678ULL: goto x86_l_3d3e;
	case 15683ULL: goto x86_l_3d43;
	case 15688ULL: goto x86_l_3d48;
	case 15690ULL: goto x86_l_3d4a;
	case 15693ULL: goto x86_l_3d4d;
	case 15699ULL: goto x86_l_3d53;
	case 15703ULL: goto x86_l_3d57;
	case 15709ULL: goto x86_l_3d5d;
	case 15714ULL: goto x86_l_3d62;
	case 15718ULL: goto x86_l_3d66;
	case 15721ULL: goto x86_l_3d69;
	case 15726ULL: goto x86_l_3d6e;
	case 15731ULL: goto x86_l_3d73;
	case 15734ULL: goto x86_l_3d76;
	case 15740ULL: goto x86_l_3d7c;
	case 15744ULL: goto x86_l_3d80;
	case 15749ULL: goto x86_l_3d85;
	case 15755ULL: goto x86_l_3d8b;
	case 15760ULL: goto x86_l_3d90;
	case 15764ULL: goto x86_l_3d94;
	case 15768ULL: goto x86_l_3d98;
	case 15773ULL: goto x86_l_3d9d;
	case 15778ULL: goto x86_l_3da2;
	case 15780ULL: goto x86_l_3da4;
	case 15785ULL: goto x86_l_3da9;
	case 15789ULL: goto x86_l_3dad;
	case 15792ULL: goto x86_l_3db0;
	case 15797ULL: goto x86_l_3db5;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15808ULL: goto x86_l_3dc0;
	case 15813ULL: goto x86_l_3dc5;
	case 15818ULL: goto x86_l_3dca;
	case 15820ULL: goto x86_l_3dcc;
	case 15824ULL: goto x86_l_3dd0;
	case 15828ULL: goto x86_l_3dd4;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15843ULL: goto x86_l_3de3;
	case 15846ULL: goto x86_l_3de6;
	case 15848ULL: goto x86_l_3de8;
	case 15853ULL: goto x86_l_3ded;
	case 15858ULL: goto x86_l_3df2;
	case 15862ULL: goto x86_l_3df6;
	case 15867ULL: goto x86_l_3dfb;
	case 15872ULL: goto x86_l_3e00;
	case 15877ULL: goto x86_l_3e05;
	case 15879ULL: goto x86_l_3e07;
	case 15884ULL: goto x86_l_3e0c;
	case 15887ULL: goto x86_l_3e0f;
	case 15893ULL: goto x86_l_3e15;
	case 15898ULL: goto x86_l_3e1a;
	case 15901ULL: goto x86_l_3e1d;
	case 15907ULL: goto x86_l_3e23;
	case 15911ULL: goto x86_l_3e27;
	case 15916ULL: goto x86_l_3e2c;
	case 15921ULL: goto x86_l_3e31;
	case 15926ULL: goto x86_l_3e36;
	case 15928ULL: goto x86_l_3e38;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15940ULL: goto x86_l_3e44;
	case 15943ULL: goto x86_l_3e47;
	case 15945ULL: goto x86_l_3e49;
	case 15951ULL: goto x86_l_3e4f;
	case 15956ULL: goto x86_l_3e54;
	case 15962ULL: goto x86_l_3e5a;
	case 15967ULL: goto x86_l_3e5f;
	case 15972ULL: goto x86_l_3e64;
	case 15974ULL: goto x86_l_3e66;
	case 15977ULL: goto x86_l_3e69;
	case 15983ULL: goto x86_l_3e6f;
	case 15987ULL: goto x86_l_3e73;
	case 15993ULL: goto x86_l_3e79;
	case 15998ULL: goto x86_l_3e7e;
	case 16002ULL: goto x86_l_3e82;
	case 16005ULL: goto x86_l_3e85;
	case 16010ULL: goto x86_l_3e8a;
	case 16015ULL: goto x86_l_3e8f;
	case 16018ULL: goto x86_l_3e92;
	case 16024ULL: goto x86_l_3e98;
	case 16028ULL: goto x86_l_3e9c;
	case 16033ULL: goto x86_l_3ea1;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16048ULL: goto x86_l_3eb0;
	case 16052ULL: goto x86_l_3eb4;
	case 16057ULL: goto x86_l_3eb9;
	case 16062ULL: goto x86_l_3ebe;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16073ULL: goto x86_l_3ec9;
	case 16076ULL: goto x86_l_3ecc;
	case 16081ULL: goto x86_l_3ed1;
	case 16083ULL: goto x86_l_3ed3;
	case 16088ULL: goto x86_l_3ed8;
	case 16092ULL: goto x86_l_3edc;
	case 16097ULL: goto x86_l_3ee1;
	case 16102ULL: goto x86_l_3ee6;
	case 16104ULL: goto x86_l_3ee8;
	case 16108ULL: goto x86_l_3eec;
	case 16112ULL: goto x86_l_3ef0;
	case 16117ULL: goto x86_l_3ef5;
	case 16122ULL: goto x86_l_3efa;
	case 16127ULL: goto x86_l_3eff;
	case 16130ULL: goto x86_l_3f02;
	case 16132ULL: goto x86_l_3f04;
	case 16137ULL: goto x86_l_3f09;
	case 16142ULL: goto x86_l_3f0e;
	case 16146ULL: goto x86_l_3f12;
	case 16151ULL: goto x86_l_3f17;
	case 16156ULL: goto x86_l_3f1c;
	case 16161ULL: goto x86_l_3f21;
	case 16163ULL: goto x86_l_3f23;
	case 16168ULL: goto x86_l_3f28;
	case 16171ULL: goto x86_l_3f2b;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16185ULL: goto x86_l_3f39;
	case 16191ULL: goto x86_l_3f3f;
	case 16195ULL: goto x86_l_3f43;
	case 16200ULL: goto x86_l_3f48;
	case 16205ULL: goto x86_l_3f4d;
	case 16210ULL: goto x86_l_3f52;
	case 16212ULL: goto x86_l_3f54;
	case 16216ULL: goto x86_l_3f58;
	case 16218ULL: goto x86_l_3f5a;
	case 16224ULL: goto x86_l_3f60;
	case 16227ULL: goto x86_l_3f63;
	case 16229ULL: goto x86_l_3f65;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16246ULL: goto x86_l_3f76;
	case 16251ULL: goto x86_l_3f7b;
	case 16256ULL: goto x86_l_3f80;
	case 16258ULL: goto x86_l_3f82;
	case 16261ULL: goto x86_l_3f85;
	case 16267ULL: goto x86_l_3f8b;
	case 16271ULL: goto x86_l_3f8f;
	case 16277ULL: goto x86_l_3f95;
	case 16282ULL: goto x86_l_3f9a;
	case 16286ULL: goto x86_l_3f9e;
	case 16289ULL: goto x86_l_3fa1;
	case 16294ULL: goto x86_l_3fa6;
	case 16299ULL: goto x86_l_3fab;
	case 16302ULL: goto x86_l_3fae;
	case 16308ULL: goto x86_l_3fb4;
	case 16312ULL: goto x86_l_3fb8;
	case 16317ULL: goto x86_l_3fbd;
	case 16323ULL: goto x86_l_3fc3;
	case 16328ULL: goto x86_l_3fc8;
	case 16332ULL: goto x86_l_3fcc;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16346ULL: goto x86_l_3fda;
	case 16348ULL: goto x86_l_3fdc;
	case 16353ULL: goto x86_l_3fe1;
	case 16357ULL: goto x86_l_3fe5;
	case 16360ULL: goto x86_l_3fe8;
	case 16365ULL: goto x86_l_3fed;
	case 16367ULL: goto x86_l_3fef;
	case 16372ULL: goto x86_l_3ff4;
	case 16376ULL: goto x86_l_3ff8;
	case 16381ULL: goto x86_l_3ffd;
	case 16386ULL: goto x86_l_4002;
	case 16388ULL: goto x86_l_4004;
	case 16392ULL: goto x86_l_4008;
	case 16396ULL: goto x86_l_400c;
	case 16401ULL: goto x86_l_4011;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	case 16414ULL: goto x86_l_401e;
	case 16416ULL: goto x86_l_4020;
	case 16421ULL: goto x86_l_4025;
	case 16426ULL: goto x86_l_402a;
	case 16430ULL: goto x86_l_402e;
	case 16435ULL: goto x86_l_4033;
	case 16440ULL: goto x86_l_4038;
	case 16445ULL: goto x86_l_403d;
	case 16447ULL: goto x86_l_403f;
	case 16452ULL: goto x86_l_4044;
	case 16455ULL: goto x86_l_4047;
	case 16461ULL: goto x86_l_404d;
	case 16466ULL: goto x86_l_4052;
	case 16469ULL: goto x86_l_4055;
	case 16475ULL: goto x86_l_405b;
	case 16479ULL: goto x86_l_405f;
	case 16484ULL: goto x86_l_4064;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16496ULL: goto x86_l_4070;
	case 16500ULL: goto x86_l_4074;
	case 16502ULL: goto x86_l_4076;
	case 16508ULL: goto x86_l_407c;
	case 16511ULL: goto x86_l_407f;
	case 16513ULL: goto x86_l_4081;
	case 16519ULL: goto x86_l_4087;
	case 16524ULL: goto x86_l_408c;
	case 16530ULL: goto x86_l_4092;
	case 16535ULL: goto x86_l_4097;
	case 16540ULL: goto x86_l_409c;
	case 16542ULL: goto x86_l_409e;
	case 16545ULL: goto x86_l_40a1;
	case 16551ULL: goto x86_l_40a7;
	case 16555ULL: goto x86_l_40ab;
	case 16561ULL: goto x86_l_40b1;
	case 16566ULL: goto x86_l_40b6;
	case 16570ULL: goto x86_l_40ba;
	case 16573ULL: goto x86_l_40bd;
	case 16578ULL: goto x86_l_40c2;
	case 16583ULL: goto x86_l_40c7;
	case 16586ULL: goto x86_l_40ca;
	case 16592ULL: goto x86_l_40d0;
	case 16596ULL: goto x86_l_40d4;
	case 16601ULL: goto x86_l_40d9;
	case 16607ULL: goto x86_l_40df;
	case 16612ULL: goto x86_l_40e4;
	case 16616ULL: goto x86_l_40e8;
	case 16620ULL: goto x86_l_40ec;
	case 16625ULL: goto x86_l_40f1;
	case 16630ULL: goto x86_l_40f6;
	case 16632ULL: goto x86_l_40f8;
	case 16637ULL: goto x86_l_40fd;
	case 16641ULL: goto x86_l_4101;
	case 16644ULL: goto x86_l_4104;
	case 16649ULL: goto x86_l_4109;
	case 16651ULL: goto x86_l_410b;
	case 16656ULL: goto x86_l_4110;
	case 16660ULL: goto x86_l_4114;
	case 16665ULL: goto x86_l_4119;
	case 16670ULL: goto x86_l_411e;
	case 16672ULL: goto x86_l_4120;
	case 16676ULL: goto x86_l_4124;
	case 16680ULL: goto x86_l_4128;
	case 16685ULL: goto x86_l_412d;
	case 16690ULL: goto x86_l_4132;
	case 16695ULL: goto x86_l_4137;
	case 16698ULL: goto x86_l_413a;
	case 16700ULL: goto x86_l_413c;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16714ULL: goto x86_l_414a;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16729ULL: goto x86_l_4159;
	case 16731ULL: goto x86_l_415b;
	case 16736ULL: goto x86_l_4160;
	case 16739ULL: goto x86_l_4163;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16753ULL: goto x86_l_4171;
	case 16759ULL: goto x86_l_4177;
	case 16763ULL: goto x86_l_417b;
	case 16768ULL: goto x86_l_4180;
	case 16773ULL: goto x86_l_4185;
	case 16778ULL: goto x86_l_418a;
	case 16780ULL: goto x86_l_418c;
	case 16784ULL: goto x86_l_4190;
	case 16786ULL: goto x86_l_4192;
	case 16792ULL: goto x86_l_4198;
	case 16795ULL: goto x86_l_419b;
	case 16797ULL: goto x86_l_419d;
	case 16803ULL: goto x86_l_41a3;
	case 16808ULL: goto x86_l_41a8;
	case 16814ULL: goto x86_l_41ae;
	case 16819ULL: goto x86_l_41b3;
	case 16824ULL: goto x86_l_41b8;
	case 16826ULL: goto x86_l_41ba;
	case 16829ULL: goto x86_l_41bd;
	case 16835ULL: goto x86_l_41c3;
	case 16839ULL: goto x86_l_41c7;
	case 16845ULL: goto x86_l_41cd;
	case 16850ULL: goto x86_l_41d2;
	case 16854ULL: goto x86_l_41d6;
	case 16857ULL: goto x86_l_41d9;
	case 16862ULL: goto x86_l_41de;
	case 16867ULL: goto x86_l_41e3;
	case 16870ULL: goto x86_l_41e6;
	case 16876ULL: goto x86_l_41ec;
	case 16880ULL: goto x86_l_41f0;
	case 16885ULL: goto x86_l_41f5;
	case 16891ULL: goto x86_l_41fb;
	case 16896ULL: goto x86_l_4200;
	case 16900ULL: goto x86_l_4204;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16914ULL: goto x86_l_4212;
	case 16916ULL: goto x86_l_4214;
	case 16921ULL: goto x86_l_4219;
	case 16925ULL: goto x86_l_421d;
	case 16928ULL: goto x86_l_4220;
	case 16933ULL: goto x86_l_4225;
	case 16935ULL: goto x86_l_4227;
	case 16940ULL: goto x86_l_422c;
	case 16944ULL: goto x86_l_4230;
	case 16949ULL: goto x86_l_4235;
	case 16954ULL: goto x86_l_423a;
	case 16956ULL: goto x86_l_423c;
	case 16960ULL: goto x86_l_4240;
	case 16964ULL: goto x86_l_4244;
	case 16969ULL: goto x86_l_4249;
	case 16974ULL: goto x86_l_424e;
	case 16979ULL: goto x86_l_4253;
	case 16982ULL: goto x86_l_4256;
	case 16984ULL: goto x86_l_4258;
	case 16989ULL: goto x86_l_425d;
	case 16994ULL: goto x86_l_4262;
	case 16998ULL: goto x86_l_4266;
	case 17003ULL: goto x86_l_426b;
	case 17008ULL: goto x86_l_4270;
	case 17013ULL: goto x86_l_4275;
	case 17015ULL: goto x86_l_4277;
	case 17020ULL: goto x86_l_427c;
	case 17023ULL: goto x86_l_427f;
	case 17029ULL: goto x86_l_4285;
	case 17034ULL: goto x86_l_428a;
	case 17037ULL: goto x86_l_428d;
	case 17043ULL: goto x86_l_4293;
	case 17047ULL: goto x86_l_4297;
	case 17052ULL: goto x86_l_429c;
	case 17057ULL: goto x86_l_42a1;
	case 17062ULL: goto x86_l_42a6;
	case 17064ULL: goto x86_l_42a8;
	case 17068ULL: goto x86_l_42ac;
	case 17070ULL: goto x86_l_42ae;
	case 17076ULL: goto x86_l_42b4;
	case 17079ULL: goto x86_l_42b7;
	case 17081ULL: goto x86_l_42b9;
	case 17087ULL: goto x86_l_42bf;
	case 17092ULL: goto x86_l_42c4;
	case 17098ULL: goto x86_l_42ca;
	case 17103ULL: goto x86_l_42cf;
	case 17108ULL: goto x86_l_42d4;
	case 17110ULL: goto x86_l_42d6;
	case 17113ULL: goto x86_l_42d9;
	case 17119ULL: goto x86_l_42df;
	case 17123ULL: goto x86_l_42e3;
	case 17129ULL: goto x86_l_42e9;
	case 17134ULL: goto x86_l_42ee;
	case 17138ULL: goto x86_l_42f2;
	case 17141ULL: goto x86_l_42f5;
	case 17146ULL: goto x86_l_42fa;
	case 17151ULL: goto x86_l_42ff;
	case 17154ULL: goto x86_l_4302;
	case 17160ULL: goto x86_l_4308;
	case 17164ULL: goto x86_l_430c;
	case 17169ULL: goto x86_l_4311;
	case 17175ULL: goto x86_l_4317;
	case 17180ULL: goto x86_l_431c;
	case 17184ULL: goto x86_l_4320;
	case 17188ULL: goto x86_l_4324;
	case 17193ULL: goto x86_l_4329;
	case 17198ULL: goto x86_l_432e;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17209ULL: goto x86_l_4339;
	case 17212ULL: goto x86_l_433c;
	case 17217ULL: goto x86_l_4341;
	case 17219ULL: goto x86_l_4343;
	case 17224ULL: goto x86_l_4348;
	case 17228ULL: goto x86_l_434c;
	case 17233ULL: goto x86_l_4351;
	case 17238ULL: goto x86_l_4356;
	case 17240ULL: goto x86_l_4358;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3ce9:
	/* 0x3ce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ceb:
	/* 0x3ceb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf0:
	/* 0x3cf0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3cf3:
	/* 0x3cf3: je     3e8f <trace_security_mmap_file+0x3e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8f;
	}
x86_l_3cf9:
	/* 0x3cf9: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cfe:
	/* 0x3cfe: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3d01:
	/* 0x3d01: je     3e8f <trace_security_mmap_file+0x3e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8f;
	}
x86_l_3d07:
	/* 0x3d07: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d0b:
	/* 0x3d0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d10:
	/* 0x3d10: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d15:
	/* 0x3d15: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3d1a:
	/* 0x3d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1c:
	/* 0x3d1c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d20:
	/* 0x3d20: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d22:
	/* 0x3d22: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d28:
	/* 0x3d28: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3d2b:
	/* 0x3d2b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d2d:
	/* 0x3d2d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_3d33:
	/* 0x3d33: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d38:
	/* 0x3d38: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3d3e:
	/* 0x3d3e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d43:
	/* 0x3d43: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3d48:
	/* 0x3d48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d4a:
	/* 0x3d4a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d4d:
	/* 0x3d4d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_3d53:
	/* 0x3d53: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d57:
	/* 0x3d57: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3d5d:
	/* 0x3d5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d62:
	/* 0x3d62: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3d66:
	/* 0x3d66: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d69:
	/* 0x3d69: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d6e:
	/* 0x3d6e: jmp    3ef0 <trace_security_mmap_file+0x3ef0> */
	goto x86_l_3ef0;
x86_l_3d73:
	/* 0x3d73: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3d76:
	/* 0x3d76: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_3d7c:
	/* 0x3d7c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d80:
	/* 0x3d80: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3d85:
	/* 0x3d85: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_3d8b:
	/* 0x3d8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d90:
	/* 0x3d90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d94:
	/* 0x3d94: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d98:
	/* 0x3d98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d9d:
	/* 0x3d9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3da2:
	/* 0x3da2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da4:
	/* 0x3da4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3da9:
	/* 0x3da9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dad:
	/* 0x3dad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3db0:
	/* 0x3db0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3db5:
	/* 0x3db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db7:
	/* 0x3db7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dbc:
	/* 0x3dbc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dc0:
	/* 0x3dc0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dc5:
	/* 0x3dc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dca:
	/* 0x3dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dcc:
	/* 0x3dcc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd0:
	/* 0x3dd0: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3dd4:
	/* 0x3dd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dd9:
	/* 0x3dd9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3dde:
	/* 0x3dde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de3:
	/* 0x3de3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3de6:
	/* 0x3de6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de8:
	/* 0x3de8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ded:
	/* 0x3ded: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3df2:
	/* 0x3df2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3df6:
	/* 0x3df6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dfb:
	/* 0x3dfb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e00:
	/* 0x3e00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e05:
	/* 0x3e05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e07:
	/* 0x3e07: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e0c:
	/* 0x3e0c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3e0f:
	/* 0x3e0f: je     3fab <trace_security_mmap_file+0x3fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fab;
	}
x86_l_3e15:
	/* 0x3e15: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e1a:
	/* 0x3e1a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e1d:
	/* 0x3e1d: je     3fab <trace_security_mmap_file+0x3fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fab;
	}
x86_l_3e23:
	/* 0x3e23: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3e27:
	/* 0x3e27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e2c:
	/* 0x3e2c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e31:
	/* 0x3e31: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3e36:
	/* 0x3e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e38:
	/* 0x3e38: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e3c:
	/* 0x3e3c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3e3e:
	/* 0x3e3e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e44:
	/* 0x3e44: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3e47:
	/* 0x3e47: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e49:
	/* 0x3e49: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_3e4f:
	/* 0x3e4f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e54:
	/* 0x3e54: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3e5a:
	/* 0x3e5a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3e5f:
	/* 0x3e5f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3e64:
	/* 0x3e64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e66:
	/* 0x3e66: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3e69:
	/* 0x3e69: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_3e6f:
	/* 0x3e6f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3e73:
	/* 0x3e73: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3e79:
	/* 0x3e79: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e7e:
	/* 0x3e7e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3e82:
	/* 0x3e82: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3e85:
	/* 0x3e85: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e8a:
	/* 0x3e8a: jmp    400c <trace_security_mmap_file+0x400c> */
	goto x86_l_400c;
x86_l_3e8f:
	/* 0x3e8f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3e92:
	/* 0x3e92: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_3e98:
	/* 0x3e98: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e9c:
	/* 0x3e9c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3ea1:
	/* 0x3ea1: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_3ea7:
	/* 0x3ea7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3eac:
	/* 0x3eac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eb0:
	/* 0x3eb0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3eb4:
	/* 0x3eb4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb9:
	/* 0x3eb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ebe:
	/* 0x3ebe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec0:
	/* 0x3ec0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ec5:
	/* 0x3ec5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ec9:
	/* 0x3ec9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ecc:
	/* 0x3ecc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ed1:
	/* 0x3ed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed3:
	/* 0x3ed3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ed8:
	/* 0x3ed8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3edc:
	/* 0x3edc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ee1:
	/* 0x3ee1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ee6:
	/* 0x3ee6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee8:
	/* 0x3ee8: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eec:
	/* 0x3eec: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3ef0:
	/* 0x3ef0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ef5:
	/* 0x3ef5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3efa:
	/* 0x3efa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eff:
	/* 0x3eff: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3f02:
	/* 0x3f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f04:
	/* 0x3f04: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f09:
	/* 0x3f09: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f0e:
	/* 0x3f0e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f12:
	/* 0x3f12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f17:
	/* 0x3f17: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f1c:
	/* 0x3f1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f21:
	/* 0x3f21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f23:
	/* 0x3f23: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f28:
	/* 0x3f28: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3f2b:
	/* 0x3f2b: je     40c7 <trace_security_mmap_file+0x40c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c7;
	}
x86_l_3f31:
	/* 0x3f31: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f36:
	/* 0x3f36: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3f39:
	/* 0x3f39: je     40c7 <trace_security_mmap_file+0x40c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c7;
	}
x86_l_3f3f:
	/* 0x3f3f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f43:
	/* 0x3f43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f48:
	/* 0x3f48: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f4d:
	/* 0x3f4d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f52:
	/* 0x3f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f54:
	/* 0x3f54: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3f58:
	/* 0x3f58: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f5a:
	/* 0x3f5a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f60:
	/* 0x3f60: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_3f63:
	/* 0x3f63: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f65:
	/* 0x3f65: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_3f6b:
	/* 0x3f6b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f70:
	/* 0x3f70: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3f76:
	/* 0x3f76: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3f7b:
	/* 0x3f7b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3f80:
	/* 0x3f80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f82:
	/* 0x3f82: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3f85:
	/* 0x3f85: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_3f8b:
	/* 0x3f8b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3f8f:
	/* 0x3f8f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3f95:
	/* 0x3f95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f9a:
	/* 0x3f9a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3f9e:
	/* 0x3f9e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3fa1:
	/* 0x3fa1: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fa6:
	/* 0x3fa6: jmp    4128 <trace_security_mmap_file+0x4128> */
	goto x86_l_4128;
x86_l_3fab:
	/* 0x3fab: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3fae:
	/* 0x3fae: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_3fb4:
	/* 0x3fb4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb8:
	/* 0x3fb8: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3fbd:
	/* 0x3fbd: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_3fc3:
	/* 0x3fc3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fc8:
	/* 0x3fc8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fcc:
	/* 0x3fcc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fd0:
	/* 0x3fd0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fd5:
	/* 0x3fd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fda:
	/* 0x3fda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fdc:
	/* 0x3fdc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fe1:
	/* 0x3fe1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe5:
	/* 0x3fe5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fe8:
	/* 0x3fe8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fed:
	/* 0x3fed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fef:
	/* 0x3fef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ff4:
	/* 0x3ff4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff8:
	/* 0x3ff8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ffd:
	/* 0x3ffd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4002:
	/* 0x4002: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4004:
	/* 0x4004: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4008:
	/* 0x4008: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_400c:
	/* 0x400c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4011:
	/* 0x4011: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4016:
	/* 0x4016: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_401b:
	/* 0x401b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_401e:
	/* 0x401e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4020:
	/* 0x4020: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4025:
	/* 0x4025: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_402a:
	/* 0x402a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_402e:
	/* 0x402e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4033:
	/* 0x4033: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4038:
	/* 0x4038: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_403d:
	/* 0x403d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403f:
	/* 0x403f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4044:
	/* 0x4044: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4047:
	/* 0x4047: je     41e3 <trace_security_mmap_file+0x41e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e3;
	}
x86_l_404d:
	/* 0x404d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4052:
	/* 0x4052: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4055:
	/* 0x4055: je     41e3 <trace_security_mmap_file+0x41e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e3;
	}
x86_l_405b:
	/* 0x405b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_405f:
	/* 0x405f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4064:
	/* 0x4064: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4069:
	/* 0x4069: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_406e:
	/* 0x406e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4070:
	/* 0x4070: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4074:
	/* 0x4074: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4076:
	/* 0x4076: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_407c:
	/* 0x407c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_407f:
	/* 0x407f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4081:
	/* 0x4081: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_4087:
	/* 0x4087: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_408c:
	/* 0x408c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4092:
	/* 0x4092: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4097:
	/* 0x4097: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_409c:
	/* 0x409c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409e:
	/* 0x409e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_40a1:
	/* 0x40a1: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_40a7:
	/* 0x40a7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_40ab:
	/* 0x40ab: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_40b1:
	/* 0x40b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40b6:
	/* 0x40b6: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_40ba:
	/* 0x40ba: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40bd:
	/* 0x40bd: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40c2:
	/* 0x40c2: jmp    4244 <trace_security_mmap_file+0x4244> */
	goto x86_l_4244;
x86_l_40c7:
	/* 0x40c7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_40ca:
	/* 0x40ca: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_40d0:
	/* 0x40d0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40d4:
	/* 0x40d4: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_40d9:
	/* 0x40d9: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_40df:
	/* 0x40df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40e4:
	/* 0x40e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e8:
	/* 0x40e8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_40ec:
	/* 0x40ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40f1:
	/* 0x40f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40f6:
	/* 0x40f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40f8:
	/* 0x40f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40fd:
	/* 0x40fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4101:
	/* 0x4101: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4104:
	/* 0x4104: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4109:
	/* 0x4109: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410b:
	/* 0x410b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4110:
	/* 0x4110: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4114:
	/* 0x4114: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4119:
	/* 0x4119: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_411e:
	/* 0x411e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4120:
	/* 0x4120: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4124:
	/* 0x4124: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4128:
	/* 0x4128: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_412d:
	/* 0x412d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4132:
	/* 0x4132: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4137:
	/* 0x4137: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_413a:
	/* 0x413a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_413c:
	/* 0x413c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4141:
	/* 0x4141: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4146:
	/* 0x4146: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_414a:
	/* 0x414a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_414f:
	/* 0x414f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4154:
	/* 0x4154: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4159:
	/* 0x4159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_415b:
	/* 0x415b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4160:
	/* 0x4160: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4163:
	/* 0x4163: je     42ff <trace_security_mmap_file+0x42ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42ff;
	}
x86_l_4169:
	/* 0x4169: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_416e:
	/* 0x416e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4171:
	/* 0x4171: je     42ff <trace_security_mmap_file+0x42ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42ff;
	}
x86_l_4177:
	/* 0x4177: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_417b:
	/* 0x417b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4180:
	/* 0x4180: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4185:
	/* 0x4185: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_418a:
	/* 0x418a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418c:
	/* 0x418c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4190:
	/* 0x4190: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4192:
	/* 0x4192: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4198:
	/* 0x4198: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_419b:
	/* 0x419b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_419d:
	/* 0x419d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_41a3:
	/* 0x41a3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_41a8:
	/* 0x41a8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_41ae:
	/* 0x41ae: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41b3:
	/* 0x41b3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_41b8:
	/* 0x41b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ba:
	/* 0x41ba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_41bd:
	/* 0x41bd: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_41c3:
	/* 0x41c3: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_41c7:
	/* 0x41c7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_41cd:
	/* 0x41cd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41d2:
	/* 0x41d2: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_41d6:
	/* 0x41d6: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_41d9:
	/* 0x41d9: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41de:
	/* 0x41de: jmp    4360 <trace_security_mmap_file+0x4360> */
	return 17248ULL;
x86_l_41e3:
	/* 0x41e3: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_41e6:
	/* 0x41e6: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_41ec:
	/* 0x41ec: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41f0:
	/* 0x41f0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_41f5:
	/* 0x41f5: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_41fb:
	/* 0x41fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4200:
	/* 0x4200: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4204:
	/* 0x4204: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4208:
	/* 0x4208: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_420d:
	/* 0x420d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4212:
	/* 0x4212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4214:
	/* 0x4214: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4219:
	/* 0x4219: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_421d:
	/* 0x421d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4220:
	/* 0x4220: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4225:
	/* 0x4225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4227:
	/* 0x4227: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_422c:
	/* 0x422c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4230:
	/* 0x4230: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4235:
	/* 0x4235: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_423a:
	/* 0x423a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_423c:
	/* 0x423c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4240:
	/* 0x4240: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4244:
	/* 0x4244: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4249:
	/* 0x4249: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_424e:
	/* 0x424e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4253:
	/* 0x4253: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4256:
	/* 0x4256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4258:
	/* 0x4258: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_425d:
	/* 0x425d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4262:
	/* 0x4262: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4266:
	/* 0x4266: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_426b:
	/* 0x426b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4270:
	/* 0x4270: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4275:
	/* 0x4275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4277:
	/* 0x4277: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_427c:
	/* 0x427c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_427f:
	/* 0x427f: je     441b <trace_security_mmap_file+0x441b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17435ULL;
	}
x86_l_4285:
	/* 0x4285: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_428a:
	/* 0x428a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_428d:
	/* 0x428d: je     441b <trace_security_mmap_file+0x441b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17435ULL;
	}
x86_l_4293:
	/* 0x4293: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4297:
	/* 0x4297: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_429c:
	/* 0x429c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42a1:
	/* 0x42a1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_42a6:
	/* 0x42a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a8:
	/* 0x42a8: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_42ac:
	/* 0x42ac: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_42ae:
	/* 0x42ae: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_42b4:
	/* 0x42b4: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_42b7:
	/* 0x42b7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_42b9:
	/* 0x42b9: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_42bf:
	/* 0x42bf: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_42c4:
	/* 0x42c4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_42ca:
	/* 0x42ca: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42cf:
	/* 0x42cf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_42d4:
	/* 0x42d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d6:
	/* 0x42d6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_42d9:
	/* 0x42d9: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_42df:
	/* 0x42df: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_42e3:
	/* 0x42e3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_42e9:
	/* 0x42e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42ee:
	/* 0x42ee: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_42f2:
	/* 0x42f2: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_42f5:
	/* 0x42f5: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42fa:
	/* 0x42fa: jmp    447c <trace_security_mmap_file+0x447c> */
	return 17532ULL;
x86_l_42ff:
	/* 0x42ff: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4302:
	/* 0x4302: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_4308:
	/* 0x4308: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_430c:
	/* 0x430c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4311:
	/* 0x4311: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_4317:
	/* 0x4317: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_431c:
	/* 0x431c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4320:
	/* 0x4320: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4324:
	/* 0x4324: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4329:
	/* 0x4329: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_432e:
	/* 0x432e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4330:
	/* 0x4330: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4335:
	/* 0x4335: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4339:
	/* 0x4339: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_433c:
	/* 0x433c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4341:
	/* 0x4341: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4343:
	/* 0x4343: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4348:
	/* 0x4348: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_434c:
	/* 0x434c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4351:
	/* 0x4351: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4356:
	/* 0x4356: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4358:
	/* 0x4358: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 17244ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17244ULL: goto x86_l_435c;
	case 17248ULL: goto x86_l_4360;
	case 17253ULL: goto x86_l_4365;
	case 17258ULL: goto x86_l_436a;
	case 17263ULL: goto x86_l_436f;
	case 17266ULL: goto x86_l_4372;
	case 17268ULL: goto x86_l_4374;
	case 17273ULL: goto x86_l_4379;
	case 17278ULL: goto x86_l_437e;
	case 17282ULL: goto x86_l_4382;
	case 17287ULL: goto x86_l_4387;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17307ULL: goto x86_l_439b;
	case 17313ULL: goto x86_l_43a1;
	case 17318ULL: goto x86_l_43a6;
	case 17321ULL: goto x86_l_43a9;
	case 17327ULL: goto x86_l_43af;
	case 17331ULL: goto x86_l_43b3;
	case 17336ULL: goto x86_l_43b8;
	case 17341ULL: goto x86_l_43bd;
	case 17346ULL: goto x86_l_43c2;
	case 17348ULL: goto x86_l_43c4;
	case 17352ULL: goto x86_l_43c8;
	case 17354ULL: goto x86_l_43ca;
	case 17360ULL: goto x86_l_43d0;
	case 17363ULL: goto x86_l_43d3;
	case 17365ULL: goto x86_l_43d5;
	case 17371ULL: goto x86_l_43db;
	case 17376ULL: goto x86_l_43e0;
	case 17382ULL: goto x86_l_43e6;
	case 17387ULL: goto x86_l_43eb;
	case 17392ULL: goto x86_l_43f0;
	case 17394ULL: goto x86_l_43f2;
	case 17397ULL: goto x86_l_43f5;
	case 17403ULL: goto x86_l_43fb;
	case 17407ULL: goto x86_l_43ff;
	case 17413ULL: goto x86_l_4405;
	case 17418ULL: goto x86_l_440a;
	case 17422ULL: goto x86_l_440e;
	case 17425ULL: goto x86_l_4411;
	case 17430ULL: goto x86_l_4416;
	case 17435ULL: goto x86_l_441b;
	case 17438ULL: goto x86_l_441e;
	case 17444ULL: goto x86_l_4424;
	case 17448ULL: goto x86_l_4428;
	case 17453ULL: goto x86_l_442d;
	case 17459ULL: goto x86_l_4433;
	case 17464ULL: goto x86_l_4438;
	case 17468ULL: goto x86_l_443c;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17484ULL: goto x86_l_444c;
	case 17489ULL: goto x86_l_4451;
	case 17493ULL: goto x86_l_4455;
	case 17496ULL: goto x86_l_4458;
	case 17501ULL: goto x86_l_445d;
	case 17503ULL: goto x86_l_445f;
	case 17508ULL: goto x86_l_4464;
	case 17512ULL: goto x86_l_4468;
	case 17517ULL: goto x86_l_446d;
	case 17522ULL: goto x86_l_4472;
	case 17524ULL: goto x86_l_4474;
	case 17528ULL: goto x86_l_4478;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17542ULL: goto x86_l_4486;
	case 17547ULL: goto x86_l_448b;
	case 17550ULL: goto x86_l_448e;
	case 17552ULL: goto x86_l_4490;
	case 17557ULL: goto x86_l_4495;
	case 17562ULL: goto x86_l_449a;
	case 17566ULL: goto x86_l_449e;
	case 17571ULL: goto x86_l_44a3;
	case 17576ULL: goto x86_l_44a8;
	case 17581ULL: goto x86_l_44ad;
	case 17583ULL: goto x86_l_44af;
	case 17588ULL: goto x86_l_44b4;
	case 17591ULL: goto x86_l_44b7;
	case 17597ULL: goto x86_l_44bd;
	case 17602ULL: goto x86_l_44c2;
	case 17605ULL: goto x86_l_44c5;
	case 17611ULL: goto x86_l_44cb;
	case 17615ULL: goto x86_l_44cf;
	case 17620ULL: goto x86_l_44d4;
	case 17625ULL: goto x86_l_44d9;
	case 17630ULL: goto x86_l_44de;
	case 17632ULL: goto x86_l_44e0;
	case 17636ULL: goto x86_l_44e4;
	case 17638ULL: goto x86_l_44e6;
	case 17644ULL: goto x86_l_44ec;
	case 17647ULL: goto x86_l_44ef;
	case 17649ULL: goto x86_l_44f1;
	case 17655ULL: goto x86_l_44f7;
	case 17660ULL: goto x86_l_44fc;
	case 17666ULL: goto x86_l_4502;
	case 17671ULL: goto x86_l_4507;
	case 17676ULL: goto x86_l_450c;
	case 17678ULL: goto x86_l_450e;
	case 17681ULL: goto x86_l_4511;
	case 17687ULL: goto x86_l_4517;
	case 17691ULL: goto x86_l_451b;
	case 17697ULL: goto x86_l_4521;
	case 17702ULL: goto x86_l_4526;
	case 17706ULL: goto x86_l_452a;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17719ULL: goto x86_l_4537;
	case 17722ULL: goto x86_l_453a;
	case 17728ULL: goto x86_l_4540;
	case 17732ULL: goto x86_l_4544;
	case 17737ULL: goto x86_l_4549;
	case 17743ULL: goto x86_l_454f;
	case 17748ULL: goto x86_l_4554;
	case 17752ULL: goto x86_l_4558;
	case 17756ULL: goto x86_l_455c;
	case 17761ULL: goto x86_l_4561;
	case 17766ULL: goto x86_l_4566;
	case 17768ULL: goto x86_l_4568;
	case 17773ULL: goto x86_l_456d;
	case 17777ULL: goto x86_l_4571;
	case 17780ULL: goto x86_l_4574;
	case 17785ULL: goto x86_l_4579;
	case 17787ULL: goto x86_l_457b;
	case 17792ULL: goto x86_l_4580;
	case 17796ULL: goto x86_l_4584;
	case 17801ULL: goto x86_l_4589;
	case 17806ULL: goto x86_l_458e;
	case 17808ULL: goto x86_l_4590;
	case 17812ULL: goto x86_l_4594;
	case 17816ULL: goto x86_l_4598;
	case 17821ULL: goto x86_l_459d;
	case 17826ULL: goto x86_l_45a2;
	case 17831ULL: goto x86_l_45a7;
	case 17834ULL: goto x86_l_45aa;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17846ULL: goto x86_l_45b6;
	case 17850ULL: goto x86_l_45ba;
	case 17855ULL: goto x86_l_45bf;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17867ULL: goto x86_l_45cb;
	case 17872ULL: goto x86_l_45d0;
	case 17875ULL: goto x86_l_45d3;
	case 17881ULL: goto x86_l_45d9;
	case 17886ULL: goto x86_l_45de;
	case 17889ULL: goto x86_l_45e1;
	case 17895ULL: goto x86_l_45e7;
	case 17899ULL: goto x86_l_45eb;
	case 17904ULL: goto x86_l_45f0;
	case 17909ULL: goto x86_l_45f5;
	case 17914ULL: goto x86_l_45fa;
	case 17916ULL: goto x86_l_45fc;
	case 17920ULL: goto x86_l_4600;
	case 17922ULL: goto x86_l_4602;
	case 17928ULL: goto x86_l_4608;
	case 17931ULL: goto x86_l_460b;
	case 17933ULL: goto x86_l_460d;
	case 17939ULL: goto x86_l_4613;
	case 17944ULL: goto x86_l_4618;
	case 17950ULL: goto x86_l_461e;
	case 17955ULL: goto x86_l_4623;
	case 17960ULL: goto x86_l_4628;
	case 17962ULL: goto x86_l_462a;
	case 17965ULL: goto x86_l_462d;
	case 17971ULL: goto x86_l_4633;
	case 17975ULL: goto x86_l_4637;
	case 17981ULL: goto x86_l_463d;
	case 17986ULL: goto x86_l_4642;
	case 17990ULL: goto x86_l_4646;
	case 17993ULL: goto x86_l_4649;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18006ULL: goto x86_l_4656;
	case 18012ULL: goto x86_l_465c;
	case 18016ULL: goto x86_l_4660;
	case 18021ULL: goto x86_l_4665;
	case 18027ULL: goto x86_l_466b;
	case 18032ULL: goto x86_l_4670;
	case 18036ULL: goto x86_l_4674;
	case 18040ULL: goto x86_l_4678;
	case 18045ULL: goto x86_l_467d;
	case 18050ULL: goto x86_l_4682;
	case 18052ULL: goto x86_l_4684;
	case 18057ULL: goto x86_l_4689;
	case 18061ULL: goto x86_l_468d;
	case 18064ULL: goto x86_l_4690;
	case 18069ULL: goto x86_l_4695;
	case 18071ULL: goto x86_l_4697;
	case 18076ULL: goto x86_l_469c;
	case 18080ULL: goto x86_l_46a0;
	case 18085ULL: goto x86_l_46a5;
	case 18090ULL: goto x86_l_46aa;
	case 18092ULL: goto x86_l_46ac;
	case 18096ULL: goto x86_l_46b0;
	case 18100ULL: goto x86_l_46b4;
	case 18105ULL: goto x86_l_46b9;
	case 18110ULL: goto x86_l_46be;
	case 18115ULL: goto x86_l_46c3;
	case 18118ULL: goto x86_l_46c6;
	case 18120ULL: goto x86_l_46c8;
	case 18125ULL: goto x86_l_46cd;
	case 18130ULL: goto x86_l_46d2;
	case 18134ULL: goto x86_l_46d6;
	case 18139ULL: goto x86_l_46db;
	case 18144ULL: goto x86_l_46e0;
	case 18149ULL: goto x86_l_46e5;
	case 18151ULL: goto x86_l_46e7;
	case 18156ULL: goto x86_l_46ec;
	case 18159ULL: goto x86_l_46ef;
	case 18165ULL: goto x86_l_46f5;
	case 18170ULL: goto x86_l_46fa;
	case 18173ULL: goto x86_l_46fd;
	case 18179ULL: goto x86_l_4703;
	case 18183ULL: goto x86_l_4707;
	case 18188ULL: goto x86_l_470c;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18200ULL: goto x86_l_4718;
	case 18204ULL: goto x86_l_471c;
	case 18206ULL: goto x86_l_471e;
	case 18212ULL: goto x86_l_4724;
	case 18215ULL: goto x86_l_4727;
	case 18217ULL: goto x86_l_4729;
	case 18223ULL: goto x86_l_472f;
	case 18228ULL: goto x86_l_4734;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18244ULL: goto x86_l_4744;
	case 18246ULL: goto x86_l_4746;
	case 18249ULL: goto x86_l_4749;
	case 18255ULL: goto x86_l_474f;
	case 18259ULL: goto x86_l_4753;
	case 18265ULL: goto x86_l_4759;
	case 18270ULL: goto x86_l_475e;
	case 18274ULL: goto x86_l_4762;
	case 18277ULL: goto x86_l_4765;
	case 18282ULL: goto x86_l_476a;
	case 18287ULL: goto x86_l_476f;
	case 18290ULL: goto x86_l_4772;
	case 18296ULL: goto x86_l_4778;
	case 18300ULL: goto x86_l_477c;
	case 18305ULL: goto x86_l_4781;
	case 18311ULL: goto x86_l_4787;
	case 18316ULL: goto x86_l_478c;
	case 18320ULL: goto x86_l_4790;
	case 18324ULL: goto x86_l_4794;
	case 18329ULL: goto x86_l_4799;
	case 18334ULL: goto x86_l_479e;
	case 18336ULL: goto x86_l_47a0;
	case 18341ULL: goto x86_l_47a5;
	case 18345ULL: goto x86_l_47a9;
	case 18348ULL: goto x86_l_47ac;
	case 18353ULL: goto x86_l_47b1;
	case 18355ULL: goto x86_l_47b3;
	case 18360ULL: goto x86_l_47b8;
	case 18364ULL: goto x86_l_47bc;
	case 18369ULL: goto x86_l_47c1;
	case 18374ULL: goto x86_l_47c6;
	case 18376ULL: goto x86_l_47c8;
	case 18380ULL: goto x86_l_47cc;
	case 18384ULL: goto x86_l_47d0;
	case 18389ULL: goto x86_l_47d5;
	case 18394ULL: goto x86_l_47da;
	case 18399ULL: goto x86_l_47df;
	case 18402ULL: goto x86_l_47e2;
	case 18404ULL: goto x86_l_47e4;
	case 18409ULL: goto x86_l_47e9;
	case 18414ULL: goto x86_l_47ee;
	case 18418ULL: goto x86_l_47f2;
	case 18423ULL: goto x86_l_47f7;
	case 18428ULL: goto x86_l_47fc;
	case 18433ULL: goto x86_l_4801;
	case 18435ULL: goto x86_l_4803;
	case 18440ULL: goto x86_l_4808;
	case 18443ULL: goto x86_l_480b;
	case 18449ULL: goto x86_l_4811;
	case 18454ULL: goto x86_l_4816;
	case 18457ULL: goto x86_l_4819;
	case 18463ULL: goto x86_l_481f;
	case 18467ULL: goto x86_l_4823;
	case 18472ULL: goto x86_l_4828;
	case 18477ULL: goto x86_l_482d;
	case 18482ULL: goto x86_l_4832;
	case 18484ULL: goto x86_l_4834;
	case 18488ULL: goto x86_l_4838;
	case 18490ULL: goto x86_l_483a;
	case 18496ULL: goto x86_l_4840;
	case 18499ULL: goto x86_l_4843;
	case 18501ULL: goto x86_l_4845;
	case 18507ULL: goto x86_l_484b;
	case 18512ULL: goto x86_l_4850;
	case 18518ULL: goto x86_l_4856;
	case 18523ULL: goto x86_l_485b;
	case 18528ULL: goto x86_l_4860;
	case 18530ULL: goto x86_l_4862;
	case 18533ULL: goto x86_l_4865;
	case 18539ULL: goto x86_l_486b;
	case 18543ULL: goto x86_l_486f;
	case 18549ULL: goto x86_l_4875;
	case 18554ULL: goto x86_l_487a;
	case 18558ULL: goto x86_l_487e;
	case 18561ULL: goto x86_l_4881;
	case 18566ULL: goto x86_l_4886;
	case 18571ULL: goto x86_l_488b;
	case 18574ULL: goto x86_l_488e;
	case 18580ULL: goto x86_l_4894;
	case 18584ULL: goto x86_l_4898;
	case 18589ULL: goto x86_l_489d;
	case 18595ULL: goto x86_l_48a3;
	case 18600ULL: goto x86_l_48a8;
	case 18604ULL: goto x86_l_48ac;
	case 18608ULL: goto x86_l_48b0;
	case 18613ULL: goto x86_l_48b5;
	case 18618ULL: goto x86_l_48ba;
	case 18620ULL: goto x86_l_48bc;
	case 18625ULL: goto x86_l_48c1;
	case 18629ULL: goto x86_l_48c5;
	case 18632ULL: goto x86_l_48c8;
	case 18637ULL: goto x86_l_48cd;
	case 18639ULL: goto x86_l_48cf;
	case 18644ULL: goto x86_l_48d4;
	case 18648ULL: goto x86_l_48d8;
	case 18653ULL: goto x86_l_48dd;
	case 18658ULL: goto x86_l_48e2;
	case 18660ULL: goto x86_l_48e4;
	case 18664ULL: goto x86_l_48e8;
	case 18668ULL: goto x86_l_48ec;
	case 18673ULL: goto x86_l_48f1;
	case 18678ULL: goto x86_l_48f6;
	case 18683ULL: goto x86_l_48fb;
	case 18686ULL: goto x86_l_48fe;
	case 18688ULL: goto x86_l_4900;
	case 18693ULL: goto x86_l_4905;
	case 18698ULL: goto x86_l_490a;
	case 18702ULL: goto x86_l_490e;
	case 18707ULL: goto x86_l_4913;
	case 18712ULL: goto x86_l_4918;
	case 18717ULL: goto x86_l_491d;
	case 18719ULL: goto x86_l_491f;
	case 18724ULL: goto x86_l_4924;
	case 18727ULL: goto x86_l_4927;
	case 18733ULL: goto x86_l_492d;
	case 18738ULL: goto x86_l_4932;
	case 18741ULL: goto x86_l_4935;
	case 18747ULL: goto x86_l_493b;
	case 18751ULL: goto x86_l_493f;
	case 18756ULL: goto x86_l_4944;
	case 18761ULL: goto x86_l_4949;
	case 18766ULL: goto x86_l_494e;
	case 18768ULL: goto x86_l_4950;
	case 18772ULL: goto x86_l_4954;
	case 18774ULL: goto x86_l_4956;
	case 18780ULL: goto x86_l_495c;
	case 18783ULL: goto x86_l_495f;
	case 18785ULL: goto x86_l_4961;
	case 18791ULL: goto x86_l_4967;
	case 18796ULL: goto x86_l_496c;
	case 18802ULL: goto x86_l_4972;
	case 18807ULL: goto x86_l_4977;
	case 18812ULL: goto x86_l_497c;
	case 18814ULL: goto x86_l_497e;
	case 18817ULL: goto x86_l_4981;
	case 18823ULL: goto x86_l_4987;
	case 18827ULL: goto x86_l_498b;
	case 18833ULL: goto x86_l_4991;
	case 18838ULL: goto x86_l_4996;
	case 18842ULL: goto x86_l_499a;
	case 18845ULL: goto x86_l_499d;
	case 18850ULL: goto x86_l_49a2;
	case 18855ULL: goto x86_l_49a7;
	case 18858ULL: goto x86_l_49aa;
	case 18864ULL: goto x86_l_49b0;
	case 18868ULL: goto x86_l_49b4;
	case 18873ULL: goto x86_l_49b9;
	case 18879ULL: goto x86_l_49bf;
	case 18884ULL: goto x86_l_49c4;
	case 18888ULL: goto x86_l_49c8;
	case 18892ULL: goto x86_l_49cc;
	case 18897ULL: goto x86_l_49d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_435c:
	/* 0x435c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4360:
	/* 0x4360: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4365:
	/* 0x4365: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_436a:
	/* 0x436a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_436f:
	/* 0x436f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4372:
	/* 0x4372: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4374:
	/* 0x4374: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4379:
	/* 0x4379: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_437e:
	/* 0x437e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4382:
	/* 0x4382: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4387:
	/* 0x4387: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_438c:
	/* 0x438c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4391:
	/* 0x4391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4393:
	/* 0x4393: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4398:
	/* 0x4398: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_439b:
	/* 0x439b: je     4537 <trace_security_mmap_file+0x4537> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4537;
	}
x86_l_43a1:
	/* 0x43a1: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43a6:
	/* 0x43a6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_43a9:
	/* 0x43a9: je     4537 <trace_security_mmap_file+0x4537> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4537;
	}
x86_l_43af:
	/* 0x43af: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_43b3:
	/* 0x43b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43b8:
	/* 0x43b8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43bd:
	/* 0x43bd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_43c2:
	/* 0x43c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43c4:
	/* 0x43c4: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_43c8:
	/* 0x43c8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_43ca:
	/* 0x43ca: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_43d0:
	/* 0x43d0: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_43d3:
	/* 0x43d3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43d5:
	/* 0x43d5: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_43db:
	/* 0x43db: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43e0:
	/* 0x43e0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_43e6:
	/* 0x43e6: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43eb:
	/* 0x43eb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_43f0:
	/* 0x43f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43f2:
	/* 0x43f2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43f5:
	/* 0x43f5: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_43fb:
	/* 0x43fb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_43ff:
	/* 0x43ff: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4405:
	/* 0x4405: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_440a:
	/* 0x440a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_440e:
	/* 0x440e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4411:
	/* 0x4411: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4416:
	/* 0x4416: jmp    4598 <trace_security_mmap_file+0x4598> */
	goto x86_l_4598;
x86_l_441b:
	/* 0x441b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_441e:
	/* 0x441e: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_4424:
	/* 0x4424: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4428:
	/* 0x4428: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_442d:
	/* 0x442d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_4433:
	/* 0x4433: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4438:
	/* 0x4438: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_443c:
	/* 0x443c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4440:
	/* 0x4440: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4445:
	/* 0x4445: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_444a:
	/* 0x444a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444c:
	/* 0x444c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4451:
	/* 0x4451: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4455:
	/* 0x4455: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x4468: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_446d:
	/* 0x446d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4472:
	/* 0x4472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4474:
	/* 0x4474: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4478:
	/* 0x4478: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_447c:
	/* 0x447c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4481:
	/* 0x4481: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4486:
	/* 0x4486: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_448b:
	/* 0x448b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_448e:
	/* 0x448e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4490:
	/* 0x4490: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4495:
	/* 0x4495: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449a:
	/* 0x449a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_449e:
	/* 0x449e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44a3:
	/* 0x44a3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44a8:
	/* 0x44a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ad:
	/* 0x44ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44af:
	/* 0x44af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44b4:
	/* 0x44b4: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_44b7:
	/* 0x44b7: je     4653 <trace_security_mmap_file+0x4653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4653;
	}
x86_l_44bd:
	/* 0x44bd: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44c2:
	/* 0x44c2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_44c5:
	/* 0x44c5: je     4653 <trace_security_mmap_file+0x4653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4653;
	}
x86_l_44cb:
	/* 0x44cb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_44cf:
	/* 0x44cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44d4:
	/* 0x44d4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44d9:
	/* 0x44d9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44de:
	/* 0x44de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44e0:
	/* 0x44e0: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_44e4:
	/* 0x44e4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44e6:
	/* 0x44e6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44ec:
	/* 0x44ec: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_44ef:
	/* 0x44ef: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44f1:
	/* 0x44f1: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_44f7:
	/* 0x44f7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_44fc:
	/* 0x44fc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4502:
	/* 0x4502: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4507:
	/* 0x4507: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_450c:
	/* 0x450c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450e:
	/* 0x450e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4511:
	/* 0x4511: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_4517:
	/* 0x4517: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_451b:
	/* 0x451b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4521:
	/* 0x4521: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4526:
	/* 0x4526: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_452a:
	/* 0x452a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_452d:
	/* 0x452d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4532:
	/* 0x4532: jmp    46b4 <trace_security_mmap_file+0x46b4> */
	goto x86_l_46b4;
x86_l_4537:
	/* 0x4537: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_453a:
	/* 0x453a: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_4540:
	/* 0x4540: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4544:
	/* 0x4544: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4549:
	/* 0x4549: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_454f:
	/* 0x454f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4554:
	/* 0x4554: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4558:
	/* 0x4558: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_455c:
	/* 0x455c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4561:
	/* 0x4561: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4566:
	/* 0x4566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4568:
	/* 0x4568: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_456d:
	/* 0x456d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4571:
	/* 0x4571: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4574:
	/* 0x4574: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4579:
	/* 0x4579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457b:
	/* 0x457b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4580:
	/* 0x4580: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4584:
	/* 0x4584: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4589:
	/* 0x4589: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_458e:
	/* 0x458e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4590:
	/* 0x4590: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4594:
	/* 0x4594: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4598:
	/* 0x4598: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_459d:
	/* 0x459d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45a2:
	/* 0x45a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45a7:
	/* 0x45a7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_45aa:
	/* 0x45aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45ac:
	/* 0x45ac: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45b1:
	/* 0x45b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45b6:
	/* 0x45b6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_45ba:
	/* 0x45ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45bf:
	/* 0x45bf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45c4:
	/* 0x45c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45c9:
	/* 0x45c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45cb:
	/* 0x45cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45d0:
	/* 0x45d0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_45d3:
	/* 0x45d3: je     476f <trace_security_mmap_file+0x476f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_476f;
	}
x86_l_45d9:
	/* 0x45d9: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45de:
	/* 0x45de: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_45e1:
	/* 0x45e1: je     476f <trace_security_mmap_file+0x476f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_476f;
	}
x86_l_45e7:
	/* 0x45e7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_45eb:
	/* 0x45eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45f0:
	/* 0x45f0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45f5:
	/* 0x45f5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_45fa:
	/* 0x45fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45fc:
	/* 0x45fc: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4600:
	/* 0x4600: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4602:
	/* 0x4602: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4608:
	/* 0x4608: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_460b:
	/* 0x460b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_460d:
	/* 0x460d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_4613:
	/* 0x4613: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4618:
	/* 0x4618: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_461e:
	/* 0x461e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4623:
	/* 0x4623: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4628:
	/* 0x4628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_462a:
	/* 0x462a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_462d:
	/* 0x462d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_4633:
	/* 0x4633: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4637:
	/* 0x4637: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_463d:
	/* 0x463d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4642:
	/* 0x4642: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4646:
	/* 0x4646: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4649:
	/* 0x4649: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_464e:
	/* 0x464e: jmp    47d0 <trace_security_mmap_file+0x47d0> */
	goto x86_l_47d0;
x86_l_4653:
	/* 0x4653: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4656:
	/* 0x4656: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_465c:
	/* 0x465c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4660:
	/* 0x4660: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4665:
	/* 0x4665: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_466b:
	/* 0x466b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4670:
	/* 0x4670: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4674:
	/* 0x4674: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4678:
	/* 0x4678: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_467d:
	/* 0x467d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4682:
	/* 0x4682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4684:
	/* 0x4684: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4689:
	/* 0x4689: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468d:
	/* 0x468d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4690:
	/* 0x4690: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4695:
	/* 0x4695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4697:
	/* 0x4697: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_469c:
	/* 0x469c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a0:
	/* 0x46a0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46a5:
	/* 0x46a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46aa:
	/* 0x46aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ac:
	/* 0x46ac: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b0:
	/* 0x46b0: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46b4:
	/* 0x46b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46b9:
	/* 0x46b9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46be:
	/* 0x46be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46c3:
	/* 0x46c3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_46c6:
	/* 0x46c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c8:
	/* 0x46c8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46cd:
	/* 0x46cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46d2:
	/* 0x46d2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_46d6:
	/* 0x46d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46db:
	/* 0x46db: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46e0:
	/* 0x46e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46e5:
	/* 0x46e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e7:
	/* 0x46e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ec:
	/* 0x46ec: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46ef:
	/* 0x46ef: je     488b <trace_security_mmap_file+0x488b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_488b;
	}
x86_l_46f5:
	/* 0x46f5: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46fa:
	/* 0x46fa: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_46fd:
	/* 0x46fd: je     488b <trace_security_mmap_file+0x488b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_488b;
	}
x86_l_4703:
	/* 0x4703: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4707:
	/* 0x4707: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_470c:
	/* 0x470c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4711:
	/* 0x4711: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4716:
	/* 0x4716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4718:
	/* 0x4718: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_471c:
	/* 0x471c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_471e:
	/* 0x471e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4724:
	/* 0x4724: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4727:
	/* 0x4727: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4729:
	/* 0x4729: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_472f:
	/* 0x472f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4734:
	/* 0x4734: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_473a:
	/* 0x473a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_473f:
	/* 0x473f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4744:
	/* 0x4744: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4746:
	/* 0x4746: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4749:
	/* 0x4749: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_474f:
	/* 0x474f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4753:
	/* 0x4753: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4759:
	/* 0x4759: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_475e:
	/* 0x475e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4762:
	/* 0x4762: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4765:
	/* 0x4765: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_476a:
	/* 0x476a: jmp    48ec <trace_security_mmap_file+0x48ec> */
	goto x86_l_48ec;
x86_l_476f:
	/* 0x476f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4772:
	/* 0x4772: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_4778:
	/* 0x4778: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_477c:
	/* 0x477c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4781:
	/* 0x4781: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_4787:
	/* 0x4787: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_478c:
	/* 0x478c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4790:
	/* 0x4790: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4794:
	/* 0x4794: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4799:
	/* 0x4799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_479e:
	/* 0x479e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47a0:
	/* 0x47a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47a5:
	/* 0x47a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a9:
	/* 0x47a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47ac:
	/* 0x47ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47b1:
	/* 0x47b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b3:
	/* 0x47b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47b8:
	/* 0x47b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47bc:
	/* 0x47bc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47c1:
	/* 0x47c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47c6:
	/* 0x47c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c8:
	/* 0x47c8: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47cc:
	/* 0x47cc: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_47d0:
	/* 0x47d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47d5:
	/* 0x47d5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47da:
	/* 0x47da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47df:
	/* 0x47df: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_47e2:
	/* 0x47e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47e4:
	/* 0x47e4: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47e9:
	/* 0x47e9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47ee:
	/* 0x47ee: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_47f2:
	/* 0x47f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47f7:
	/* 0x47f7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47fc:
	/* 0x47fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4801:
	/* 0x4801: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4803:
	/* 0x4803: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4808:
	/* 0x4808: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_480b:
	/* 0x480b: je     49a7 <trace_security_mmap_file+0x49a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49a7;
	}
x86_l_4811:
	/* 0x4811: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4816:
	/* 0x4816: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4819:
	/* 0x4819: je     49a7 <trace_security_mmap_file+0x49a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49a7;
	}
x86_l_481f:
	/* 0x481f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4823:
	/* 0x4823: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4828:
	/* 0x4828: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_482d:
	/* 0x482d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4832:
	/* 0x4832: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4834:
	/* 0x4834: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4838:
	/* 0x4838: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_483a:
	/* 0x483a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4840:
	/* 0x4840: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4843:
	/* 0x4843: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4845:
	/* 0x4845: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_484b:
	/* 0x484b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4850:
	/* 0x4850: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4856:
	/* 0x4856: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_485b:
	/* 0x485b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4860:
	/* 0x4860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4862:
	/* 0x4862: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4865:
	/* 0x4865: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_486b:
	/* 0x486b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_486f:
	/* 0x486f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4875:
	/* 0x4875: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487a:
	/* 0x487a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_487e:
	/* 0x487e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4881:
	/* 0x4881: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4886:
	/* 0x4886: jmp    4a08 <trace_security_mmap_file+0x4a08> */
	return 18952ULL;
x86_l_488b:
	/* 0x488b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_488e:
	/* 0x488e: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_4894:
	/* 0x4894: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4898:
	/* 0x4898: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_489d:
	/* 0x489d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_48a3:
	/* 0x48a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48a8:
	/* 0x48a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ac:
	/* 0x48ac: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_48b0:
	/* 0x48b0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48b5:
	/* 0x48b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48ba:
	/* 0x48ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48bc:
	/* 0x48bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48c1:
	/* 0x48c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48c5:
	/* 0x48c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48c8:
	/* 0x48c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48cd:
	/* 0x48cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48cf:
	/* 0x48cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48d4:
	/* 0x48d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48d8:
	/* 0x48d8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48dd:
	/* 0x48dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e2:
	/* 0x48e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e4:
	/* 0x48e4: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48e8:
	/* 0x48e8: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48ec:
	/* 0x48ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48f1:
	/* 0x48f1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48f6:
	/* 0x48f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48fb:
	/* 0x48fb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_48fe:
	/* 0x48fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4900:
	/* 0x4900: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4905:
	/* 0x4905: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_490a:
	/* 0x490a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_490e:
	/* 0x490e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4913:
	/* 0x4913: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4918:
	/* 0x4918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_491d:
	/* 0x491d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491f:
	/* 0x491f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4924:
	/* 0x4924: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4927:
	/* 0x4927: je     4ac3 <trace_security_mmap_file+0x4ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19139ULL;
	}
x86_l_492d:
	/* 0x492d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4932:
	/* 0x4932: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4935:
	/* 0x4935: je     4ac3 <trace_security_mmap_file+0x4ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19139ULL;
	}
x86_l_493b:
	/* 0x493b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_493f:
	/* 0x493f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4944:
	/* 0x4944: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4949:
	/* 0x4949: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_494e:
	/* 0x494e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4950:
	/* 0x4950: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4954:
	/* 0x4954: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4956:
	/* 0x4956: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_495c:
	/* 0x495c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_495f:
	/* 0x495f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4961:
	/* 0x4961: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_4967:
	/* 0x4967: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_496c:
	/* 0x496c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4972:
	/* 0x4972: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4977:
	/* 0x4977: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_497c:
	/* 0x497c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497e:
	/* 0x497e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4981:
	/* 0x4981: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_4987:
	/* 0x4987: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_498b:
	/* 0x498b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4991:
	/* 0x4991: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4996:
	/* 0x4996: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_499a:
	/* 0x499a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_499d:
	/* 0x499d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49a2:
	/* 0x49a2: jmp    4b24 <trace_security_mmap_file+0x4b24> */
	return 19236ULL;
x86_l_49a7:
	/* 0x49a7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_49aa:
	/* 0x49aa: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_49b0:
	/* 0x49b0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b4:
	/* 0x49b4: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_49b9:
	/* 0x49b9: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_49bf:
	/* 0x49bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49c4:
	/* 0x49c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49c8:
	/* 0x49c8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49cc:
	/* 0x49cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49d1:
	/* 0x49d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 18902ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18902ULL: goto x86_l_49d6;
	case 18904ULL: goto x86_l_49d8;
	case 18909ULL: goto x86_l_49dd;
	case 18913ULL: goto x86_l_49e1;
	case 18916ULL: goto x86_l_49e4;
	case 18921ULL: goto x86_l_49e9;
	case 18923ULL: goto x86_l_49eb;
	case 18928ULL: goto x86_l_49f0;
	case 18932ULL: goto x86_l_49f4;
	case 18937ULL: goto x86_l_49f9;
	case 18942ULL: goto x86_l_49fe;
	case 18944ULL: goto x86_l_4a00;
	case 18948ULL: goto x86_l_4a04;
	case 18952ULL: goto x86_l_4a08;
	case 18957ULL: goto x86_l_4a0d;
	case 18962ULL: goto x86_l_4a12;
	case 18967ULL: goto x86_l_4a17;
	case 18970ULL: goto x86_l_4a1a;
	case 18972ULL: goto x86_l_4a1c;
	case 18977ULL: goto x86_l_4a21;
	case 18982ULL: goto x86_l_4a26;
	case 18986ULL: goto x86_l_4a2a;
	case 18991ULL: goto x86_l_4a2f;
	case 18996ULL: goto x86_l_4a34;
	case 19001ULL: goto x86_l_4a39;
	case 19003ULL: goto x86_l_4a3b;
	case 19008ULL: goto x86_l_4a40;
	case 19011ULL: goto x86_l_4a43;
	case 19017ULL: goto x86_l_4a49;
	case 19022ULL: goto x86_l_4a4e;
	case 19025ULL: goto x86_l_4a51;
	case 19031ULL: goto x86_l_4a57;
	case 19035ULL: goto x86_l_4a5b;
	case 19040ULL: goto x86_l_4a60;
	case 19045ULL: goto x86_l_4a65;
	case 19050ULL: goto x86_l_4a6a;
	case 19052ULL: goto x86_l_4a6c;
	case 19056ULL: goto x86_l_4a70;
	case 19058ULL: goto x86_l_4a72;
	case 19064ULL: goto x86_l_4a78;
	case 19067ULL: goto x86_l_4a7b;
	case 19069ULL: goto x86_l_4a7d;
	case 19075ULL: goto x86_l_4a83;
	case 19080ULL: goto x86_l_4a88;
	case 19086ULL: goto x86_l_4a8e;
	case 19091ULL: goto x86_l_4a93;
	case 19096ULL: goto x86_l_4a98;
	case 19098ULL: goto x86_l_4a9a;
	case 19101ULL: goto x86_l_4a9d;
	case 19107ULL: goto x86_l_4aa3;
	case 19111ULL: goto x86_l_4aa7;
	case 19117ULL: goto x86_l_4aad;
	case 19122ULL: goto x86_l_4ab2;
	case 19126ULL: goto x86_l_4ab6;
	case 19129ULL: goto x86_l_4ab9;
	case 19134ULL: goto x86_l_4abe;
	case 19139ULL: goto x86_l_4ac3;
	case 19142ULL: goto x86_l_4ac6;
	case 19148ULL: goto x86_l_4acc;
	case 19152ULL: goto x86_l_4ad0;
	case 19157ULL: goto x86_l_4ad5;
	case 19163ULL: goto x86_l_4adb;
	case 19168ULL: goto x86_l_4ae0;
	case 19172ULL: goto x86_l_4ae4;
	case 19176ULL: goto x86_l_4ae8;
	case 19181ULL: goto x86_l_4aed;
	case 19186ULL: goto x86_l_4af2;
	case 19188ULL: goto x86_l_4af4;
	case 19193ULL: goto x86_l_4af9;
	case 19197ULL: goto x86_l_4afd;
	case 19200ULL: goto x86_l_4b00;
	case 19205ULL: goto x86_l_4b05;
	case 19207ULL: goto x86_l_4b07;
	case 19212ULL: goto x86_l_4b0c;
	case 19216ULL: goto x86_l_4b10;
	case 19221ULL: goto x86_l_4b15;
	case 19226ULL: goto x86_l_4b1a;
	case 19228ULL: goto x86_l_4b1c;
	case 19232ULL: goto x86_l_4b20;
	case 19236ULL: goto x86_l_4b24;
	case 19241ULL: goto x86_l_4b29;
	case 19246ULL: goto x86_l_4b2e;
	case 19251ULL: goto x86_l_4b33;
	case 19254ULL: goto x86_l_4b36;
	case 19256ULL: goto x86_l_4b38;
	case 19261ULL: goto x86_l_4b3d;
	case 19266ULL: goto x86_l_4b42;
	case 19270ULL: goto x86_l_4b46;
	case 19275ULL: goto x86_l_4b4b;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19287ULL: goto x86_l_4b57;
	case 19292ULL: goto x86_l_4b5c;
	case 19295ULL: goto x86_l_4b5f;
	case 19301ULL: goto x86_l_4b65;
	case 19306ULL: goto x86_l_4b6a;
	case 19309ULL: goto x86_l_4b6d;
	case 19315ULL: goto x86_l_4b73;
	case 19319ULL: goto x86_l_4b77;
	case 19324ULL: goto x86_l_4b7c;
	case 19329ULL: goto x86_l_4b81;
	case 19334ULL: goto x86_l_4b86;
	case 19336ULL: goto x86_l_4b88;
	case 19340ULL: goto x86_l_4b8c;
	case 19342ULL: goto x86_l_4b8e;
	case 19348ULL: goto x86_l_4b94;
	case 19351ULL: goto x86_l_4b97;
	case 19353ULL: goto x86_l_4b99;
	case 19359ULL: goto x86_l_4b9f;
	case 19364ULL: goto x86_l_4ba4;
	case 19370ULL: goto x86_l_4baa;
	case 19375ULL: goto x86_l_4baf;
	case 19380ULL: goto x86_l_4bb4;
	case 19382ULL: goto x86_l_4bb6;
	case 19385ULL: goto x86_l_4bb9;
	case 19391ULL: goto x86_l_4bbf;
	case 19395ULL: goto x86_l_4bc3;
	case 19401ULL: goto x86_l_4bc9;
	case 19406ULL: goto x86_l_4bce;
	case 19410ULL: goto x86_l_4bd2;
	case 19413ULL: goto x86_l_4bd5;
	case 19418ULL: goto x86_l_4bda;
	case 19423ULL: goto x86_l_4bdf;
	case 19426ULL: goto x86_l_4be2;
	case 19432ULL: goto x86_l_4be8;
	case 19436ULL: goto x86_l_4bec;
	case 19441ULL: goto x86_l_4bf1;
	case 19447ULL: goto x86_l_4bf7;
	case 19452ULL: goto x86_l_4bfc;
	case 19456ULL: goto x86_l_4c00;
	case 19460ULL: goto x86_l_4c04;
	case 19465ULL: goto x86_l_4c09;
	case 19470ULL: goto x86_l_4c0e;
	case 19472ULL: goto x86_l_4c10;
	case 19477ULL: goto x86_l_4c15;
	case 19481ULL: goto x86_l_4c19;
	case 19484ULL: goto x86_l_4c1c;
	case 19489ULL: goto x86_l_4c21;
	case 19491ULL: goto x86_l_4c23;
	case 19496ULL: goto x86_l_4c28;
	case 19500ULL: goto x86_l_4c2c;
	case 19505ULL: goto x86_l_4c31;
	case 19510ULL: goto x86_l_4c36;
	case 19512ULL: goto x86_l_4c38;
	case 19516ULL: goto x86_l_4c3c;
	case 19520ULL: goto x86_l_4c40;
	case 19525ULL: goto x86_l_4c45;
	case 19530ULL: goto x86_l_4c4a;
	case 19535ULL: goto x86_l_4c4f;
	case 19538ULL: goto x86_l_4c52;
	case 19540ULL: goto x86_l_4c54;
	case 19545ULL: goto x86_l_4c59;
	case 19550ULL: goto x86_l_4c5e;
	case 19554ULL: goto x86_l_4c62;
	case 19559ULL: goto x86_l_4c67;
	case 19564ULL: goto x86_l_4c6c;
	case 19569ULL: goto x86_l_4c71;
	case 19571ULL: goto x86_l_4c73;
	case 19576ULL: goto x86_l_4c78;
	case 19579ULL: goto x86_l_4c7b;
	case 19585ULL: goto x86_l_4c81;
	case 19590ULL: goto x86_l_4c86;
	case 19593ULL: goto x86_l_4c89;
	case 19599ULL: goto x86_l_4c8f;
	case 19603ULL: goto x86_l_4c93;
	case 19608ULL: goto x86_l_4c98;
	case 19613ULL: goto x86_l_4c9d;
	case 19618ULL: goto x86_l_4ca2;
	case 19620ULL: goto x86_l_4ca4;
	case 19624ULL: goto x86_l_4ca8;
	case 19626ULL: goto x86_l_4caa;
	case 19632ULL: goto x86_l_4cb0;
	case 19635ULL: goto x86_l_4cb3;
	case 19637ULL: goto x86_l_4cb5;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19654ULL: goto x86_l_4cc6;
	case 19659ULL: goto x86_l_4ccb;
	case 19664ULL: goto x86_l_4cd0;
	case 19666ULL: goto x86_l_4cd2;
	case 19669ULL: goto x86_l_4cd5;
	case 19675ULL: goto x86_l_4cdb;
	case 19679ULL: goto x86_l_4cdf;
	case 19685ULL: goto x86_l_4ce5;
	case 19690ULL: goto x86_l_4cea;
	case 19694ULL: goto x86_l_4cee;
	case 19697ULL: goto x86_l_4cf1;
	case 19702ULL: goto x86_l_4cf6;
	case 19707ULL: goto x86_l_4cfb;
	case 19710ULL: goto x86_l_4cfe;
	case 19716ULL: goto x86_l_4d04;
	case 19720ULL: goto x86_l_4d08;
	case 19725ULL: goto x86_l_4d0d;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19740ULL: goto x86_l_4d1c;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19754ULL: goto x86_l_4d2a;
	case 19756ULL: goto x86_l_4d2c;
	case 19761ULL: goto x86_l_4d31;
	case 19765ULL: goto x86_l_4d35;
	case 19768ULL: goto x86_l_4d38;
	case 19773ULL: goto x86_l_4d3d;
	case 19775ULL: goto x86_l_4d3f;
	case 19780ULL: goto x86_l_4d44;
	case 19784ULL: goto x86_l_4d48;
	case 19789ULL: goto x86_l_4d4d;
	case 19794ULL: goto x86_l_4d52;
	case 19796ULL: goto x86_l_4d54;
	case 19800ULL: goto x86_l_4d58;
	case 19804ULL: goto x86_l_4d5c;
	case 19809ULL: goto x86_l_4d61;
	case 19814ULL: goto x86_l_4d66;
	case 19819ULL: goto x86_l_4d6b;
	case 19822ULL: goto x86_l_4d6e;
	case 19824ULL: goto x86_l_4d70;
	case 19829ULL: goto x86_l_4d75;
	case 19834ULL: goto x86_l_4d7a;
	case 19838ULL: goto x86_l_4d7e;
	case 19843ULL: goto x86_l_4d83;
	case 19848ULL: goto x86_l_4d88;
	case 19853ULL: goto x86_l_4d8d;
	case 19855ULL: goto x86_l_4d8f;
	case 19860ULL: goto x86_l_4d94;
	case 19863ULL: goto x86_l_4d97;
	case 19869ULL: goto x86_l_4d9d;
	case 19874ULL: goto x86_l_4da2;
	case 19877ULL: goto x86_l_4da5;
	case 19883ULL: goto x86_l_4dab;
	case 19887ULL: goto x86_l_4daf;
	case 19892ULL: goto x86_l_4db4;
	case 19897ULL: goto x86_l_4db9;
	case 19902ULL: goto x86_l_4dbe;
	case 19904ULL: goto x86_l_4dc0;
	case 19908ULL: goto x86_l_4dc4;
	case 19910ULL: goto x86_l_4dc6;
	case 19916ULL: goto x86_l_4dcc;
	case 19919ULL: goto x86_l_4dcf;
	case 19921ULL: goto x86_l_4dd1;
	case 19927ULL: goto x86_l_4dd7;
	case 19932ULL: goto x86_l_4ddc;
	case 19938ULL: goto x86_l_4de2;
	case 19943ULL: goto x86_l_4de7;
	case 19948ULL: goto x86_l_4dec;
	case 19950ULL: goto x86_l_4dee;
	case 19953ULL: goto x86_l_4df1;
	case 19959ULL: goto x86_l_4df7;
	case 19963ULL: goto x86_l_4dfb;
	case 19969ULL: goto x86_l_4e01;
	case 19974ULL: goto x86_l_4e06;
	case 19978ULL: goto x86_l_4e0a;
	case 19981ULL: goto x86_l_4e0d;
	case 19986ULL: goto x86_l_4e12;
	case 19991ULL: goto x86_l_4e17;
	case 19994ULL: goto x86_l_4e1a;
	case 20000ULL: goto x86_l_4e20;
	case 20004ULL: goto x86_l_4e24;
	case 20009ULL: goto x86_l_4e29;
	case 20015ULL: goto x86_l_4e2f;
	case 20020ULL: goto x86_l_4e34;
	case 20024ULL: goto x86_l_4e38;
	case 20028ULL: goto x86_l_4e3c;
	case 20033ULL: goto x86_l_4e41;
	case 20038ULL: goto x86_l_4e46;
	case 20040ULL: goto x86_l_4e48;
	case 20045ULL: goto x86_l_4e4d;
	case 20049ULL: goto x86_l_4e51;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20059ULL: goto x86_l_4e5b;
	case 20064ULL: goto x86_l_4e60;
	case 20068ULL: goto x86_l_4e64;
	case 20073ULL: goto x86_l_4e69;
	case 20078ULL: goto x86_l_4e6e;
	case 20080ULL: goto x86_l_4e70;
	case 20084ULL: goto x86_l_4e74;
	case 20088ULL: goto x86_l_4e78;
	case 20093ULL: goto x86_l_4e7d;
	case 20098ULL: goto x86_l_4e82;
	case 20103ULL: goto x86_l_4e87;
	case 20106ULL: goto x86_l_4e8a;
	case 20108ULL: goto x86_l_4e8c;
	case 20113ULL: goto x86_l_4e91;
	case 20118ULL: goto x86_l_4e96;
	case 20122ULL: goto x86_l_4e9a;
	case 20127ULL: goto x86_l_4e9f;
	case 20132ULL: goto x86_l_4ea4;
	case 20137ULL: goto x86_l_4ea9;
	case 20139ULL: goto x86_l_4eab;
	case 20144ULL: goto x86_l_4eb0;
	case 20147ULL: goto x86_l_4eb3;
	case 20153ULL: goto x86_l_4eb9;
	case 20158ULL: goto x86_l_4ebe;
	case 20161ULL: goto x86_l_4ec1;
	case 20167ULL: goto x86_l_4ec7;
	case 20171ULL: goto x86_l_4ecb;
	case 20176ULL: goto x86_l_4ed0;
	case 20181ULL: goto x86_l_4ed5;
	case 20186ULL: goto x86_l_4eda;
	case 20188ULL: goto x86_l_4edc;
	case 20192ULL: goto x86_l_4ee0;
	case 20194ULL: goto x86_l_4ee2;
	case 20200ULL: goto x86_l_4ee8;
	case 20203ULL: goto x86_l_4eeb;
	case 20205ULL: goto x86_l_4eed;
	case 20211ULL: goto x86_l_4ef3;
	case 20216ULL: goto x86_l_4ef8;
	case 20222ULL: goto x86_l_4efe;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20234ULL: goto x86_l_4f0a;
	case 20237ULL: goto x86_l_4f0d;
	case 20243ULL: goto x86_l_4f13;
	case 20247ULL: goto x86_l_4f17;
	case 20253ULL: goto x86_l_4f1d;
	case 20258ULL: goto x86_l_4f22;
	case 20262ULL: goto x86_l_4f26;
	case 20265ULL: goto x86_l_4f29;
	case 20270ULL: goto x86_l_4f2e;
	case 20275ULL: goto x86_l_4f33;
	case 20278ULL: goto x86_l_4f36;
	case 20284ULL: goto x86_l_4f3c;
	case 20288ULL: goto x86_l_4f40;
	case 20293ULL: goto x86_l_4f45;
	case 20299ULL: goto x86_l_4f4b;
	case 20304ULL: goto x86_l_4f50;
	case 20308ULL: goto x86_l_4f54;
	case 20312ULL: goto x86_l_4f58;
	case 20317ULL: goto x86_l_4f5d;
	case 20322ULL: goto x86_l_4f62;
	case 20324ULL: goto x86_l_4f64;
	case 20329ULL: goto x86_l_4f69;
	case 20333ULL: goto x86_l_4f6d;
	case 20336ULL: goto x86_l_4f70;
	case 20341ULL: goto x86_l_4f75;
	case 20343ULL: goto x86_l_4f77;
	case 20348ULL: goto x86_l_4f7c;
	case 20352ULL: goto x86_l_4f80;
	case 20357ULL: goto x86_l_4f85;
	case 20362ULL: goto x86_l_4f8a;
	case 20364ULL: goto x86_l_4f8c;
	case 20368ULL: goto x86_l_4f90;
	case 20372ULL: goto x86_l_4f94;
	case 20377ULL: goto x86_l_4f99;
	case 20382ULL: goto x86_l_4f9e;
	case 20387ULL: goto x86_l_4fa3;
	case 20390ULL: goto x86_l_4fa6;
	case 20392ULL: goto x86_l_4fa8;
	case 20397ULL: goto x86_l_4fad;
	case 20402ULL: goto x86_l_4fb2;
	case 20406ULL: goto x86_l_4fb6;
	case 20411ULL: goto x86_l_4fbb;
	case 20416ULL: goto x86_l_4fc0;
	case 20421ULL: goto x86_l_4fc5;
	case 20423ULL: goto x86_l_4fc7;
	case 20428ULL: goto x86_l_4fcc;
	case 20431ULL: goto x86_l_4fcf;
	case 20437ULL: goto x86_l_4fd5;
	case 20442ULL: goto x86_l_4fda;
	case 20445ULL: goto x86_l_4fdd;
	case 20451ULL: goto x86_l_4fe3;
	case 20455ULL: goto x86_l_4fe7;
	case 20460ULL: goto x86_l_4fec;
	case 20465ULL: goto x86_l_4ff1;
	case 20470ULL: goto x86_l_4ff6;
	case 20472ULL: goto x86_l_4ff8;
	case 20476ULL: goto x86_l_4ffc;
	case 20478ULL: goto x86_l_4ffe;
	case 20484ULL: goto x86_l_5004;
	case 20487ULL: goto x86_l_5007;
	case 20489ULL: goto x86_l_5009;
	case 20495ULL: goto x86_l_500f;
	case 20500ULL: goto x86_l_5014;
	case 20506ULL: goto x86_l_501a;
	case 20511ULL: goto x86_l_501f;
	case 20516ULL: goto x86_l_5024;
	case 20518ULL: goto x86_l_5026;
	case 20521ULL: goto x86_l_5029;
	case 20527ULL: goto x86_l_502f;
	case 20531ULL: goto x86_l_5033;
	case 20537ULL: goto x86_l_5039;
	case 20542ULL: goto x86_l_503e;
	case 20546ULL: goto x86_l_5042;
	default: return 0xffffffffffffffffULL;
	}
x86_l_49d6:
	/* 0x49d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d8:
	/* 0x49d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49dd:
	/* 0x49dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e1:
	/* 0x49e1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49e4:
	/* 0x49e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49e9:
	/* 0x49e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49eb:
	/* 0x49eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49f0:
	/* 0x49f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f4:
	/* 0x49f4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_49f9:
	/* 0x49f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49fe:
	/* 0x49fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a00:
	/* 0x4a00: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a04:
	/* 0x4a04: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a08:
	/* 0x4a08: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a0d:
	/* 0x4a0d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a12:
	/* 0x4a12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a17:
	/* 0x4a17: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4a1a:
	/* 0x4a1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1c:
	/* 0x4a1c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a21:
	/* 0x4a21: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a26:
	/* 0x4a26: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a2a:
	/* 0x4a2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a2f:
	/* 0x4a2f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a34:
	/* 0x4a34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a39:
	/* 0x4a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a3b:
	/* 0x4a3b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a40:
	/* 0x4a40: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4a43:
	/* 0x4a43: je     4bdf <trace_security_mmap_file+0x4bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bdf;
	}
x86_l_4a49:
	/* 0x4a49: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a4e:
	/* 0x4a4e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4a51:
	/* 0x4a51: je     4bdf <trace_security_mmap_file+0x4bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bdf;
	}
x86_l_4a57:
	/* 0x4a57: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a5b:
	/* 0x4a5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a60:
	/* 0x4a60: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a65:
	/* 0x4a65: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4a6a:
	/* 0x4a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a6c:
	/* 0x4a6c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4a70:
	/* 0x4a70: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a72:
	/* 0x4a72: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a78:
	/* 0x4a78: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4a7b:
	/* 0x4a7b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4a7d:
	/* 0x4a7d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_4a83:
	/* 0x4a83: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a88:
	/* 0x4a88: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4a8e:
	/* 0x4a8e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a93:
	/* 0x4a93: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4a98:
	/* 0x4a98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9a:
	/* 0x4a9a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a9d:
	/* 0x4a9d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_4aa3:
	/* 0x4aa3: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4aa7:
	/* 0x4aa7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4aad:
	/* 0x4aad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ab2:
	/* 0x4ab2: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4ab6:
	/* 0x4ab6: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ab9:
	/* 0x4ab9: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4abe:
	/* 0x4abe: jmp    4c40 <trace_security_mmap_file+0x4c40> */
	goto x86_l_4c40;
x86_l_4ac3:
	/* 0x4ac3: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4ac6:
	/* 0x4ac6: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_4acc:
	/* 0x4acc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad0:
	/* 0x4ad0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4ad5:
	/* 0x4ad5: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_4adb:
	/* 0x4adb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ae0:
	/* 0x4ae0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae4:
	/* 0x4ae4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ae8:
	/* 0x4ae8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4aed:
	/* 0x4aed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4af2:
	/* 0x4af2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4af4:
	/* 0x4af4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4af9:
	/* 0x4af9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4afd:
	/* 0x4afd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b00:
	/* 0x4b00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b05:
	/* 0x4b05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b07:
	/* 0x4b07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b0c:
	/* 0x4b0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b10:
	/* 0x4b10: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b15:
	/* 0x4b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1a:
	/* 0x4b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1c:
	/* 0x4b1c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b20:
	/* 0x4b20: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b24:
	/* 0x4b24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b29:
	/* 0x4b29: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b2e:
	/* 0x4b2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b33:
	/* 0x4b33: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4b36:
	/* 0x4b36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b38:
	/* 0x4b38: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b3d:
	/* 0x4b3d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b42:
	/* 0x4b42: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b46:
	/* 0x4b46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b4b:
	/* 0x4b4b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b50:
	/* 0x4b50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b55:
	/* 0x4b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b57:
	/* 0x4b57: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b5c:
	/* 0x4b5c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4b5f:
	/* 0x4b5f: je     4cfb <trace_security_mmap_file+0x4cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cfb;
	}
x86_l_4b65:
	/* 0x4b65: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b6a:
	/* 0x4b6a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4b6d:
	/* 0x4b6d: je     4cfb <trace_security_mmap_file+0x4cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cfb;
	}
x86_l_4b73:
	/* 0x4b73: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b77:
	/* 0x4b77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b7c:
	/* 0x4b7c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b81:
	/* 0x4b81: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4b86:
	/* 0x4b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b88:
	/* 0x4b88: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4b8c:
	/* 0x4b8c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4b8e:
	/* 0x4b8e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4b94:
	/* 0x4b94: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4b97:
	/* 0x4b97: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4b99:
	/* 0x4b99: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_4b9f:
	/* 0x4b9f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ba4:
	/* 0x4ba4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4baa:
	/* 0x4baa: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4baf:
	/* 0x4baf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4bb4:
	/* 0x4bb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb6:
	/* 0x4bb6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bb9:
	/* 0x4bb9: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_4bbf:
	/* 0x4bbf: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4bc3:
	/* 0x4bc3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4bc9:
	/* 0x4bc9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bce:
	/* 0x4bce: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4bd2:
	/* 0x4bd2: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4bd5:
	/* 0x4bd5: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bda:
	/* 0x4bda: jmp    4d5c <trace_security_mmap_file+0x4d5c> */
	goto x86_l_4d5c;
x86_l_4bdf:
	/* 0x4bdf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4be2:
	/* 0x4be2: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_4be8:
	/* 0x4be8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bec:
	/* 0x4bec: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4bf1:
	/* 0x4bf1: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_4bf7:
	/* 0x4bf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bfc:
	/* 0x4bfc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c00:
	/* 0x4c00: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c04:
	/* 0x4c04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c09:
	/* 0x4c09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c0e:
	/* 0x4c0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c10:
	/* 0x4c10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c15:
	/* 0x4c15: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c19:
	/* 0x4c19: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c1c:
	/* 0x4c1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c21:
	/* 0x4c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c23:
	/* 0x4c23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c28:
	/* 0x4c28: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c2c:
	/* 0x4c2c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c31:
	/* 0x4c31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c36:
	/* 0x4c36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c38:
	/* 0x4c38: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c3c:
	/* 0x4c3c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c40:
	/* 0x4c40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c45:
	/* 0x4c45: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c4a:
	/* 0x4c4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c4f:
	/* 0x4c4f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4c52:
	/* 0x4c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c54:
	/* 0x4c54: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c59:
	/* 0x4c59: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c5e:
	/* 0x4c5e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c62:
	/* 0x4c62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c67:
	/* 0x4c67: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c6c:
	/* 0x4c6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c71:
	/* 0x4c71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c73:
	/* 0x4c73: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c78:
	/* 0x4c78: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4c7b:
	/* 0x4c7b: je     4e17 <trace_security_mmap_file+0x4e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e17;
	}
x86_l_4c81:
	/* 0x4c81: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c86:
	/* 0x4c86: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4c89:
	/* 0x4c89: je     4e17 <trace_security_mmap_file+0x4e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e17;
	}
x86_l_4c8f:
	/* 0x4c8f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c93:
	/* 0x4c93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c98:
	/* 0x4c98: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c9d:
	/* 0x4c9d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ca2:
	/* 0x4ca2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca4:
	/* 0x4ca4: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4ca8:
	/* 0x4ca8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4caa:
	/* 0x4caa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4cb0:
	/* 0x4cb0: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4cb3:
	/* 0x4cb3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4cb5:
	/* 0x4cb5: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_4cbb:
	/* 0x4cbb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cc0:
	/* 0x4cc0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4cc6:
	/* 0x4cc6: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ccb:
	/* 0x4ccb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4cd0:
	/* 0x4cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd2:
	/* 0x4cd2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4cd5:
	/* 0x4cd5: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_4cdb:
	/* 0x4cdb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4cdf:
	/* 0x4cdf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4ce5:
	/* 0x4ce5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cea:
	/* 0x4cea: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4cee:
	/* 0x4cee: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4cf1:
	/* 0x4cf1: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cf6:
	/* 0x4cf6: jmp    4e78 <trace_security_mmap_file+0x4e78> */
	goto x86_l_4e78;
x86_l_4cfb:
	/* 0x4cfb: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4cfe:
	/* 0x4cfe: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_4d04:
	/* 0x4d04: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d08:
	/* 0x4d08: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4d0d:
	/* 0x4d0d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_4d13:
	/* 0x4d13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d18:
	/* 0x4d18: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d1c:
	/* 0x4d1c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d20:
	/* 0x4d20: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d25:
	/* 0x4d25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d2a:
	/* 0x4d2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d2c:
	/* 0x4d2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d31:
	/* 0x4d31: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d35:
	/* 0x4d35: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d38:
	/* 0x4d38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d3d:
	/* 0x4d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d3f:
	/* 0x4d3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d44:
	/* 0x4d44: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d48:
	/* 0x4d48: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d4d:
	/* 0x4d4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d52:
	/* 0x4d52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d54:
	/* 0x4d54: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d58:
	/* 0x4d58: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d5c:
	/* 0x4d5c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d61:
	/* 0x4d61: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d66:
	/* 0x4d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d6b:
	/* 0x4d6b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4d6e:
	/* 0x4d6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d70:
	/* 0x4d70: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d75:
	/* 0x4d75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d7a:
	/* 0x4d7a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d7e:
	/* 0x4d7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d83:
	/* 0x4d83: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d88:
	/* 0x4d88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d8d:
	/* 0x4d8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d8f:
	/* 0x4d8f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d94:
	/* 0x4d94: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4d97:
	/* 0x4d97: je     4f33 <trace_security_mmap_file+0x4f33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f33;
	}
x86_l_4d9d:
	/* 0x4d9d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4da2:
	/* 0x4da2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4da5:
	/* 0x4da5: je     4f33 <trace_security_mmap_file+0x4f33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f33;
	}
x86_l_4dab:
	/* 0x4dab: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4daf:
	/* 0x4daf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4db4:
	/* 0x4db4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4db9:
	/* 0x4db9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4dbe:
	/* 0x4dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc0:
	/* 0x4dc0: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4dc4:
	/* 0x4dc4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4dc6:
	/* 0x4dc6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4dcf:
	/* 0x4dcf: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4dd1:
	/* 0x4dd1: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_4dd7:
	/* 0x4dd7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ddc:
	/* 0x4ddc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4de2:
	/* 0x4de2: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4de7:
	/* 0x4de7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4dec:
	/* 0x4dec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dee:
	/* 0x4dee: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4df1:
	/* 0x4df1: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_4df7:
	/* 0x4df7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4dfb:
	/* 0x4dfb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4e01:
	/* 0x4e01: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e06:
	/* 0x4e06: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4e0a:
	/* 0x4e0a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e0d:
	/* 0x4e0d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e12:
	/* 0x4e12: jmp    4f94 <trace_security_mmap_file+0x4f94> */
	goto x86_l_4f94;
x86_l_4e17:
	/* 0x4e17: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4e1a:
	/* 0x4e1a: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_4e20:
	/* 0x4e20: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e24:
	/* 0x4e24: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4e29:
	/* 0x4e29: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_4e2f:
	/* 0x4e2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e34:
	/* 0x4e34: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e38:
	/* 0x4e38: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e3c:
	/* 0x4e3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e41:
	/* 0x4e41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e46:
	/* 0x4e46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e48:
	/* 0x4e48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e4d:
	/* 0x4e4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e51:
	/* 0x4e51: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e54:
	/* 0x4e54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e59:
	/* 0x4e59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e5b:
	/* 0x4e5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e60:
	/* 0x4e60: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e64:
	/* 0x4e64: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e69:
	/* 0x4e69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e6e:
	/* 0x4e6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e70:
	/* 0x4e70: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e74:
	/* 0x4e74: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e78:
	/* 0x4e78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e7d:
	/* 0x4e7d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e82:
	/* 0x4e82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e87:
	/* 0x4e87: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4e8a:
	/* 0x4e8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8c:
	/* 0x4e8c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e91:
	/* 0x4e91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e96:
	/* 0x4e96: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4e9a:
	/* 0x4e9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e9f:
	/* 0x4e9f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ea4:
	/* 0x4ea4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ea9:
	/* 0x4ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eab:
	/* 0x4eab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4eb0:
	/* 0x4eb0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4eb3:
	/* 0x4eb3: je     504f <trace_security_mmap_file+0x504f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20559ULL;
	}
x86_l_4eb9:
	/* 0x4eb9: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ebe:
	/* 0x4ebe: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4ec1:
	/* 0x4ec1: je     504f <trace_security_mmap_file+0x504f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20559ULL;
	}
x86_l_4ec7:
	/* 0x4ec7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4ecb:
	/* 0x4ecb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ed0:
	/* 0x4ed0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ed5:
	/* 0x4ed5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4eda:
	/* 0x4eda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4edc:
	/* 0x4edc: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4ee0:
	/* 0x4ee0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4ee2:
	/* 0x4ee2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ee8:
	/* 0x4ee8: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_4eeb:
	/* 0x4eeb: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4eed:
	/* 0x4eed: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_4ef3:
	/* 0x4ef3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ef8:
	/* 0x4ef8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4efe:
	/* 0x4efe: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f03:
	/* 0x4f03: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4f08:
	/* 0x4f08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0a:
	/* 0x4f0a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4f0d:
	/* 0x4f0d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_4f13:
	/* 0x4f13: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4f17:
	/* 0x4f17: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4f1d:
	/* 0x4f1d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f22:
	/* 0x4f22: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4f26:
	/* 0x4f26: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4f29:
	/* 0x4f29: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f2e:
	/* 0x4f2e: jmp    50b0 <trace_security_mmap_file+0x50b0> */
	return 20656ULL;
x86_l_4f33:
	/* 0x4f33: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4f36:
	/* 0x4f36: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_4f3c:
	/* 0x4f3c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f40:
	/* 0x4f40: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4f45:
	/* 0x4f45: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_4f4b:
	/* 0x4f4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f50:
	/* 0x4f50: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f54:
	/* 0x4f54: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f58:
	/* 0x4f58: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f5d:
	/* 0x4f5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f62:
	/* 0x4f62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f64:
	/* 0x4f64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f69:
	/* 0x4f69: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f6d:
	/* 0x4f6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f70:
	/* 0x4f70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f75:
	/* 0x4f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f77:
	/* 0x4f77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f7c:
	/* 0x4f7c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f80:
	/* 0x4f80: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f85:
	/* 0x4f85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f8a:
	/* 0x4f8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8c:
	/* 0x4f8c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f90:
	/* 0x4f90: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f94:
	/* 0x4f94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f99:
	/* 0x4f99: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f9e:
	/* 0x4f9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fa3:
	/* 0x4fa3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4fa6:
	/* 0x4fa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa8:
	/* 0x4fa8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fad:
	/* 0x4fad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fb2:
	/* 0x4fb2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4fb6:
	/* 0x4fb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fbb:
	/* 0x4fbb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fc0:
	/* 0x4fc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fc5:
	/* 0x4fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fc7:
	/* 0x4fc7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fcc:
	/* 0x4fcc: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4fcf:
	/* 0x4fcf: je     516b <trace_security_mmap_file+0x516b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20843ULL;
	}
x86_l_4fd5:
	/* 0x4fd5: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fda:
	/* 0x4fda: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4fdd:
	/* 0x4fdd: je     516b <trace_security_mmap_file+0x516b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20843ULL;
	}
x86_l_4fe3:
	/* 0x4fe3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4fe7:
	/* 0x4fe7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fec:
	/* 0x4fec: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ff1:
	/* 0x4ff1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4ff6:
	/* 0x4ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff8:
	/* 0x4ff8: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4ffc:
	/* 0x4ffc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4ffe:
	/* 0x4ffe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5004:
	/* 0x5004: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5007:
	/* 0x5007: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5009:
	/* 0x5009: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_500f:
	/* 0x500f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5014:
	/* 0x5014: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_501a:
	/* 0x501a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
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
	/* 0x5029: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_502f:
	/* 0x502f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5033:
	/* 0x5033: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5039:
	/* 0x5039: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_503e:
	/* 0x503e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5042:
	/* 0x5042: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
	return 20549ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20549ULL: goto x86_l_5045;
	case 20554ULL: goto x86_l_504a;
	case 20559ULL: goto x86_l_504f;
	case 20562ULL: goto x86_l_5052;
	case 20568ULL: goto x86_l_5058;
	case 20572ULL: goto x86_l_505c;
	case 20577ULL: goto x86_l_5061;
	case 20583ULL: goto x86_l_5067;
	case 20588ULL: goto x86_l_506c;
	case 20592ULL: goto x86_l_5070;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20608ULL: goto x86_l_5080;
	case 20613ULL: goto x86_l_5085;
	case 20617ULL: goto x86_l_5089;
	case 20620ULL: goto x86_l_508c;
	case 20625ULL: goto x86_l_5091;
	case 20627ULL: goto x86_l_5093;
	case 20632ULL: goto x86_l_5098;
	case 20636ULL: goto x86_l_509c;
	case 20641ULL: goto x86_l_50a1;
	case 20646ULL: goto x86_l_50a6;
	case 20648ULL: goto x86_l_50a8;
	case 20652ULL: goto x86_l_50ac;
	case 20656ULL: goto x86_l_50b0;
	case 20661ULL: goto x86_l_50b5;
	case 20666ULL: goto x86_l_50ba;
	case 20671ULL: goto x86_l_50bf;
	case 20674ULL: goto x86_l_50c2;
	case 20676ULL: goto x86_l_50c4;
	case 20681ULL: goto x86_l_50c9;
	case 20686ULL: goto x86_l_50ce;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20705ULL: goto x86_l_50e1;
	case 20707ULL: goto x86_l_50e3;
	case 20712ULL: goto x86_l_50e8;
	case 20715ULL: goto x86_l_50eb;
	case 20721ULL: goto x86_l_50f1;
	case 20726ULL: goto x86_l_50f6;
	case 20729ULL: goto x86_l_50f9;
	case 20735ULL: goto x86_l_50ff;
	case 20739ULL: goto x86_l_5103;
	case 20744ULL: goto x86_l_5108;
	case 20749ULL: goto x86_l_510d;
	case 20754ULL: goto x86_l_5112;
	case 20756ULL: goto x86_l_5114;
	case 20760ULL: goto x86_l_5118;
	case 20762ULL: goto x86_l_511a;
	case 20768ULL: goto x86_l_5120;
	case 20771ULL: goto x86_l_5123;
	case 20773ULL: goto x86_l_5125;
	case 20779ULL: goto x86_l_512b;
	case 20784ULL: goto x86_l_5130;
	case 20790ULL: goto x86_l_5136;
	case 20795ULL: goto x86_l_513b;
	case 20800ULL: goto x86_l_5140;
	case 20802ULL: goto x86_l_5142;
	case 20805ULL: goto x86_l_5145;
	case 20811ULL: goto x86_l_514b;
	case 20815ULL: goto x86_l_514f;
	case 20821ULL: goto x86_l_5155;
	case 20826ULL: goto x86_l_515a;
	case 20830ULL: goto x86_l_515e;
	case 20833ULL: goto x86_l_5161;
	case 20838ULL: goto x86_l_5166;
	case 20843ULL: goto x86_l_516b;
	case 20846ULL: goto x86_l_516e;
	case 20852ULL: goto x86_l_5174;
	case 20856ULL: goto x86_l_5178;
	case 20861ULL: goto x86_l_517d;
	case 20867ULL: goto x86_l_5183;
	case 20872ULL: goto x86_l_5188;
	case 20876ULL: goto x86_l_518c;
	case 20880ULL: goto x86_l_5190;
	case 20885ULL: goto x86_l_5195;
	case 20890ULL: goto x86_l_519a;
	case 20892ULL: goto x86_l_519c;
	case 20897ULL: goto x86_l_51a1;
	case 20901ULL: goto x86_l_51a5;
	case 20904ULL: goto x86_l_51a8;
	case 20909ULL: goto x86_l_51ad;
	case 20911ULL: goto x86_l_51af;
	case 20916ULL: goto x86_l_51b4;
	case 20920ULL: goto x86_l_51b8;
	case 20925ULL: goto x86_l_51bd;
	case 20930ULL: goto x86_l_51c2;
	case 20932ULL: goto x86_l_51c4;
	case 20936ULL: goto x86_l_51c8;
	case 20940ULL: goto x86_l_51cc;
	case 20945ULL: goto x86_l_51d1;
	case 20950ULL: goto x86_l_51d6;
	case 20955ULL: goto x86_l_51db;
	case 20958ULL: goto x86_l_51de;
	case 20960ULL: goto x86_l_51e0;
	case 20965ULL: goto x86_l_51e5;
	case 20970ULL: goto x86_l_51ea;
	case 20974ULL: goto x86_l_51ee;
	case 20979ULL: goto x86_l_51f3;
	case 20984ULL: goto x86_l_51f8;
	case 20989ULL: goto x86_l_51fd;
	case 20991ULL: goto x86_l_51ff;
	case 20996ULL: goto x86_l_5204;
	case 20999ULL: goto x86_l_5207;
	case 21005ULL: goto x86_l_520d;
	case 21010ULL: goto x86_l_5212;
	case 21013ULL: goto x86_l_5215;
	case 21019ULL: goto x86_l_521b;
	case 21023ULL: goto x86_l_521f;
	case 21028ULL: goto x86_l_5224;
	case 21033ULL: goto x86_l_5229;
	case 21038ULL: goto x86_l_522e;
	case 21040ULL: goto x86_l_5230;
	case 21044ULL: goto x86_l_5234;
	case 21046ULL: goto x86_l_5236;
	case 21052ULL: goto x86_l_523c;
	case 21055ULL: goto x86_l_523f;
	case 21057ULL: goto x86_l_5241;
	case 21063ULL: goto x86_l_5247;
	case 21068ULL: goto x86_l_524c;
	case 21074ULL: goto x86_l_5252;
	case 21079ULL: goto x86_l_5257;
	case 21084ULL: goto x86_l_525c;
	case 21086ULL: goto x86_l_525e;
	case 21089ULL: goto x86_l_5261;
	case 21095ULL: goto x86_l_5267;
	case 21099ULL: goto x86_l_526b;
	case 21105ULL: goto x86_l_5271;
	case 21110ULL: goto x86_l_5276;
	case 21114ULL: goto x86_l_527a;
	case 21117ULL: goto x86_l_527d;
	case 21122ULL: goto x86_l_5282;
	case 21127ULL: goto x86_l_5287;
	case 21130ULL: goto x86_l_528a;
	case 21136ULL: goto x86_l_5290;
	case 21140ULL: goto x86_l_5294;
	case 21145ULL: goto x86_l_5299;
	case 21151ULL: goto x86_l_529f;
	case 21156ULL: goto x86_l_52a4;
	case 21160ULL: goto x86_l_52a8;
	case 21164ULL: goto x86_l_52ac;
	case 21169ULL: goto x86_l_52b1;
	case 21174ULL: goto x86_l_52b6;
	case 21176ULL: goto x86_l_52b8;
	case 21181ULL: goto x86_l_52bd;
	case 21185ULL: goto x86_l_52c1;
	case 21188ULL: goto x86_l_52c4;
	case 21193ULL: goto x86_l_52c9;
	case 21195ULL: goto x86_l_52cb;
	case 21200ULL: goto x86_l_52d0;
	case 21204ULL: goto x86_l_52d4;
	case 21209ULL: goto x86_l_52d9;
	case 21214ULL: goto x86_l_52de;
	case 21216ULL: goto x86_l_52e0;
	case 21220ULL: goto x86_l_52e4;
	case 21224ULL: goto x86_l_52e8;
	case 21229ULL: goto x86_l_52ed;
	case 21234ULL: goto x86_l_52f2;
	case 21239ULL: goto x86_l_52f7;
	case 21242ULL: goto x86_l_52fa;
	case 21244ULL: goto x86_l_52fc;
	case 21249ULL: goto x86_l_5301;
	case 21254ULL: goto x86_l_5306;
	case 21258ULL: goto x86_l_530a;
	case 21263ULL: goto x86_l_530f;
	case 21268ULL: goto x86_l_5314;
	case 21273ULL: goto x86_l_5319;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21283ULL: goto x86_l_5323;
	case 21289ULL: goto x86_l_5329;
	case 21294ULL: goto x86_l_532e;
	case 21297ULL: goto x86_l_5331;
	case 21303ULL: goto x86_l_5337;
	case 21307ULL: goto x86_l_533b;
	case 21312ULL: goto x86_l_5340;
	case 21317ULL: goto x86_l_5345;
	case 21322ULL: goto x86_l_534a;
	case 21324ULL: goto x86_l_534c;
	case 21328ULL: goto x86_l_5350;
	case 21330ULL: goto x86_l_5352;
	case 21336ULL: goto x86_l_5358;
	case 21339ULL: goto x86_l_535b;
	case 21341ULL: goto x86_l_535d;
	case 21347ULL: goto x86_l_5363;
	case 21352ULL: goto x86_l_5368;
	case 21358ULL: goto x86_l_536e;
	case 21363ULL: goto x86_l_5373;
	case 21368ULL: goto x86_l_5378;
	case 21370ULL: goto x86_l_537a;
	case 21373ULL: goto x86_l_537d;
	case 21379ULL: goto x86_l_5383;
	case 21383ULL: goto x86_l_5387;
	case 21389ULL: goto x86_l_538d;
	case 21394ULL: goto x86_l_5392;
	case 21398ULL: goto x86_l_5396;
	case 21401ULL: goto x86_l_5399;
	case 21406ULL: goto x86_l_539e;
	case 21411ULL: goto x86_l_53a3;
	case 21414ULL: goto x86_l_53a6;
	case 21420ULL: goto x86_l_53ac;
	case 21424ULL: goto x86_l_53b0;
	case 21429ULL: goto x86_l_53b5;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21444ULL: goto x86_l_53c4;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21458ULL: goto x86_l_53d2;
	case 21460ULL: goto x86_l_53d4;
	case 21465ULL: goto x86_l_53d9;
	case 21469ULL: goto x86_l_53dd;
	case 21472ULL: goto x86_l_53e0;
	case 21477ULL: goto x86_l_53e5;
	case 21479ULL: goto x86_l_53e7;
	case 21484ULL: goto x86_l_53ec;
	case 21488ULL: goto x86_l_53f0;
	case 21493ULL: goto x86_l_53f5;
	case 21498ULL: goto x86_l_53fa;
	case 21500ULL: goto x86_l_53fc;
	case 21504ULL: goto x86_l_5400;
	case 21508ULL: goto x86_l_5404;
	case 21513ULL: goto x86_l_5409;
	case 21518ULL: goto x86_l_540e;
	case 21523ULL: goto x86_l_5413;
	case 21526ULL: goto x86_l_5416;
	case 21528ULL: goto x86_l_5418;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21542ULL: goto x86_l_5426;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21557ULL: goto x86_l_5435;
	case 21559ULL: goto x86_l_5437;
	case 21564ULL: goto x86_l_543c;
	case 21567ULL: goto x86_l_543f;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21581ULL: goto x86_l_544d;
	case 21587ULL: goto x86_l_5453;
	case 21591ULL: goto x86_l_5457;
	case 21596ULL: goto x86_l_545c;
	case 21601ULL: goto x86_l_5461;
	case 21606ULL: goto x86_l_5466;
	case 21608ULL: goto x86_l_5468;
	case 21612ULL: goto x86_l_546c;
	case 21614ULL: goto x86_l_546e;
	case 21620ULL: goto x86_l_5474;
	case 21623ULL: goto x86_l_5477;
	case 21625ULL: goto x86_l_5479;
	case 21631ULL: goto x86_l_547f;
	case 21636ULL: goto x86_l_5484;
	case 21642ULL: goto x86_l_548a;
	case 21647ULL: goto x86_l_548f;
	case 21652ULL: goto x86_l_5494;
	case 21654ULL: goto x86_l_5496;
	case 21657ULL: goto x86_l_5499;
	case 21663ULL: goto x86_l_549f;
	case 21667ULL: goto x86_l_54a3;
	case 21673ULL: goto x86_l_54a9;
	case 21678ULL: goto x86_l_54ae;
	case 21682ULL: goto x86_l_54b2;
	case 21685ULL: goto x86_l_54b5;
	case 21690ULL: goto x86_l_54ba;
	case 21695ULL: goto x86_l_54bf;
	case 21698ULL: goto x86_l_54c2;
	case 21704ULL: goto x86_l_54c8;
	case 21708ULL: goto x86_l_54cc;
	case 21713ULL: goto x86_l_54d1;
	case 21719ULL: goto x86_l_54d7;
	case 21724ULL: goto x86_l_54dc;
	case 21728ULL: goto x86_l_54e0;
	case 21732ULL: goto x86_l_54e4;
	case 21737ULL: goto x86_l_54e9;
	case 21742ULL: goto x86_l_54ee;
	case 21744ULL: goto x86_l_54f0;
	case 21749ULL: goto x86_l_54f5;
	case 21753ULL: goto x86_l_54f9;
	case 21756ULL: goto x86_l_54fc;
	case 21761ULL: goto x86_l_5501;
	case 21763ULL: goto x86_l_5503;
	case 21768ULL: goto x86_l_5508;
	case 21772ULL: goto x86_l_550c;
	case 21777ULL: goto x86_l_5511;
	case 21782ULL: goto x86_l_5516;
	case 21784ULL: goto x86_l_5518;
	case 21788ULL: goto x86_l_551c;
	case 21792ULL: goto x86_l_5520;
	case 21797ULL: goto x86_l_5525;
	case 21802ULL: goto x86_l_552a;
	case 21807ULL: goto x86_l_552f;
	case 21810ULL: goto x86_l_5532;
	case 21812ULL: goto x86_l_5534;
	case 21817ULL: goto x86_l_5539;
	case 21822ULL: goto x86_l_553e;
	case 21826ULL: goto x86_l_5542;
	case 21831ULL: goto x86_l_5547;
	case 21836ULL: goto x86_l_554c;
	case 21841ULL: goto x86_l_5551;
	case 21843ULL: goto x86_l_5553;
	case 21848ULL: goto x86_l_5558;
	case 21851ULL: goto x86_l_555b;
	case 21857ULL: goto x86_l_5561;
	case 21862ULL: goto x86_l_5566;
	case 21865ULL: goto x86_l_5569;
	case 21871ULL: goto x86_l_556f;
	case 21875ULL: goto x86_l_5573;
	case 21880ULL: goto x86_l_5578;
	case 21885ULL: goto x86_l_557d;
	case 21890ULL: goto x86_l_5582;
	case 21892ULL: goto x86_l_5584;
	case 21896ULL: goto x86_l_5588;
	case 21898ULL: goto x86_l_558a;
	case 21904ULL: goto x86_l_5590;
	case 21907ULL: goto x86_l_5593;
	case 21909ULL: goto x86_l_5595;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21926ULL: goto x86_l_55a6;
	case 21931ULL: goto x86_l_55ab;
	case 21936ULL: goto x86_l_55b0;
	case 21938ULL: goto x86_l_55b2;
	case 21941ULL: goto x86_l_55b5;
	case 21947ULL: goto x86_l_55bb;
	case 21951ULL: goto x86_l_55bf;
	case 21957ULL: goto x86_l_55c5;
	case 21962ULL: goto x86_l_55ca;
	case 21966ULL: goto x86_l_55ce;
	case 21969ULL: goto x86_l_55d1;
	case 21974ULL: goto x86_l_55d6;
	case 21979ULL: goto x86_l_55db;
	case 21982ULL: goto x86_l_55de;
	case 21988ULL: goto x86_l_55e4;
	case 21992ULL: goto x86_l_55e8;
	case 21997ULL: goto x86_l_55ed;
	case 22003ULL: goto x86_l_55f3;
	case 22008ULL: goto x86_l_55f8;
	case 22012ULL: goto x86_l_55fc;
	case 22016ULL: goto x86_l_5600;
	case 22021ULL: goto x86_l_5605;
	case 22026ULL: goto x86_l_560a;
	case 22028ULL: goto x86_l_560c;
	case 22033ULL: goto x86_l_5611;
	case 22037ULL: goto x86_l_5615;
	case 22040ULL: goto x86_l_5618;
	case 22045ULL: goto x86_l_561d;
	case 22047ULL: goto x86_l_561f;
	case 22052ULL: goto x86_l_5624;
	case 22056ULL: goto x86_l_5628;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22068ULL: goto x86_l_5634;
	case 22072ULL: goto x86_l_5638;
	case 22076ULL: goto x86_l_563c;
	case 22081ULL: goto x86_l_5641;
	case 22086ULL: goto x86_l_5646;
	case 22091ULL: goto x86_l_564b;
	case 22094ULL: goto x86_l_564e;
	case 22096ULL: goto x86_l_5650;
	case 22101ULL: goto x86_l_5655;
	case 22106ULL: goto x86_l_565a;
	case 22110ULL: goto x86_l_565e;
	case 22115ULL: goto x86_l_5663;
	case 22120ULL: goto x86_l_5668;
	case 22125ULL: goto x86_l_566d;
	case 22127ULL: goto x86_l_566f;
	case 22132ULL: goto x86_l_5674;
	case 22135ULL: goto x86_l_5677;
	case 22141ULL: goto x86_l_567d;
	case 22146ULL: goto x86_l_5682;
	case 22149ULL: goto x86_l_5685;
	case 22155ULL: goto x86_l_568b;
	case 22159ULL: goto x86_l_568f;
	case 22164ULL: goto x86_l_5694;
	case 22169ULL: goto x86_l_5699;
	case 22174ULL: goto x86_l_569e;
	case 22176ULL: goto x86_l_56a0;
	case 22180ULL: goto x86_l_56a4;
	case 22182ULL: goto x86_l_56a6;
	case 22188ULL: goto x86_l_56ac;
	case 22191ULL: goto x86_l_56af;
	case 22193ULL: goto x86_l_56b1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5045:
	/* 0x5045: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_504a:
	/* 0x504a: jmp    51cc <trace_security_mmap_file+0x51cc> */
	goto x86_l_51cc;
x86_l_504f:
	/* 0x504f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5052:
	/* 0x5052: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5058:
	/* 0x5058: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_505c:
	/* 0x505c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5061:
	/* 0x5061: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_5067:
	/* 0x5067: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_506c:
	/* 0x506c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5070:
	/* 0x5070: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5074:
	/* 0x5074: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5079:
	/* 0x5079: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_507e:
	/* 0x507e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5080:
	/* 0x5080: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5085:
	/* 0x5085: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5089:
	/* 0x5089: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_508c:
	/* 0x508c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5091:
	/* 0x5091: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5093:
	/* 0x5093: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5098:
	/* 0x5098: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_509c:
	/* 0x509c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50a1:
	/* 0x50a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50a6:
	/* 0x50a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50a8:
	/* 0x50a8: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50ac:
	/* 0x50ac: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50b0:
	/* 0x50b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50b5:
	/* 0x50b5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50ba:
	/* 0x50ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50bf:
	/* 0x50bf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_50c2:
	/* 0x50c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c4:
	/* 0x50c4: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50c9:
	/* 0x50c9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50ce:
	/* 0x50ce: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_50d2:
	/* 0x50d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50d7:
	/* 0x50d7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50dc:
	/* 0x50dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e1:
	/* 0x50e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e3:
	/* 0x50e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50e8:
	/* 0x50e8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_50eb:
	/* 0x50eb: je     5287 <trace_security_mmap_file+0x5287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5287;
	}
x86_l_50f1:
	/* 0x50f1: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50f6:
	/* 0x50f6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_50f9:
	/* 0x50f9: je     5287 <trace_security_mmap_file+0x5287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5287;
	}
x86_l_50ff:
	/* 0x50ff: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5103:
	/* 0x5103: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5108:
	/* 0x5108: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_510d:
	/* 0x510d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5112:
	/* 0x5112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5114:
	/* 0x5114: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5118:
	/* 0x5118: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_511a:
	/* 0x511a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5120:
	/* 0x5120: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5123:
	/* 0x5123: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5125:
	/* 0x5125: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_512b:
	/* 0x512b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5130:
	/* 0x5130: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5136:
	/* 0x5136: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_513b:
	/* 0x513b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5140:
	/* 0x5140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5142:
	/* 0x5142: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5145:
	/* 0x5145: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_514b:
	/* 0x514b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_514f:
	/* 0x514f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5155:
	/* 0x5155: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_515a:
	/* 0x515a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_515e:
	/* 0x515e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5161:
	/* 0x5161: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5166:
	/* 0x5166: jmp    52e8 <trace_security_mmap_file+0x52e8> */
	goto x86_l_52e8;
x86_l_516b:
	/* 0x516b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_516e:
	/* 0x516e: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_5174:
	/* 0x5174: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5178:
	/* 0x5178: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_517d:
	/* 0x517d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_5183:
	/* 0x5183: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5188:
	/* 0x5188: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_518c:
	/* 0x518c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5190:
	/* 0x5190: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5195:
	/* 0x5195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_519a:
	/* 0x519a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519c:
	/* 0x519c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51a1:
	/* 0x51a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a5:
	/* 0x51a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51a8:
	/* 0x51a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51ad:
	/* 0x51ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51af:
	/* 0x51af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51b4:
	/* 0x51b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b8:
	/* 0x51b8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51bd:
	/* 0x51bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c2:
	/* 0x51c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c4:
	/* 0x51c4: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51c8:
	/* 0x51c8: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51cc:
	/* 0x51cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51d1:
	/* 0x51d1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51d6:
	/* 0x51d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51db:
	/* 0x51db: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_51de:
	/* 0x51de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51e0:
	/* 0x51e0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51e5:
	/* 0x51e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51ea:
	/* 0x51ea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51ee:
	/* 0x51ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51f3:
	/* 0x51f3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51f8:
	/* 0x51f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51fd:
	/* 0x51fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ff:
	/* 0x51ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5204:
	/* 0x5204: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5207:
	/* 0x5207: je     53a3 <trace_security_mmap_file+0x53a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53a3;
	}
x86_l_520d:
	/* 0x520d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5212:
	/* 0x5212: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5215:
	/* 0x5215: je     53a3 <trace_security_mmap_file+0x53a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53a3;
	}
x86_l_521b:
	/* 0x521b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_521f:
	/* 0x521f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5224:
	/* 0x5224: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5229:
	/* 0x5229: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_522e:
	/* 0x522e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5230:
	/* 0x5230: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5234:
	/* 0x5234: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5236:
	/* 0x5236: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_523c:
	/* 0x523c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_523f:
	/* 0x523f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5241:
	/* 0x5241: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_5247:
	/* 0x5247: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_524c:
	/* 0x524c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5252:
	/* 0x5252: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5257:
	/* 0x5257: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_525c:
	/* 0x525c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_525e:
	/* 0x525e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5261:
	/* 0x5261: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_5267:
	/* 0x5267: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_526b:
	/* 0x526b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5271:
	/* 0x5271: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5276:
	/* 0x5276: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_527a:
	/* 0x527a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_527d:
	/* 0x527d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5282:
	/* 0x5282: jmp    5404 <trace_security_mmap_file+0x5404> */
	goto x86_l_5404;
x86_l_5287:
	/* 0x5287: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_528a:
	/* 0x528a: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5290:
	/* 0x5290: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5294:
	/* 0x5294: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5299:
	/* 0x5299: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_529f:
	/* 0x529f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52a4:
	/* 0x52a4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a8:
	/* 0x52a8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52ac:
	/* 0x52ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52b1:
	/* 0x52b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52b6:
	/* 0x52b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b8:
	/* 0x52b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52bd:
	/* 0x52bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c1:
	/* 0x52c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52c4:
	/* 0x52c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52c9:
	/* 0x52c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52cb:
	/* 0x52cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52d0:
	/* 0x52d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52d4:
	/* 0x52d4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52d9:
	/* 0x52d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52de:
	/* 0x52de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e0:
	/* 0x52e0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52e4:
	/* 0x52e4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52e8:
	/* 0x52e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52ed:
	/* 0x52ed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52f2:
	/* 0x52f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f7:
	/* 0x52f7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_52fa:
	/* 0x52fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52fc:
	/* 0x52fc: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5301:
	/* 0x5301: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5306:
	/* 0x5306: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_530a:
	/* 0x530a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_530f:
	/* 0x530f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5314:
	/* 0x5314: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5319:
	/* 0x5319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_531b:
	/* 0x531b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5320:
	/* 0x5320: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5323:
	/* 0x5323: je     54bf <trace_security_mmap_file+0x54bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54bf;
	}
x86_l_5329:
	/* 0x5329: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_532e:
	/* 0x532e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5331:
	/* 0x5331: je     54bf <trace_security_mmap_file+0x54bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54bf;
	}
x86_l_5337:
	/* 0x5337: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_533b:
	/* 0x533b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5340:
	/* 0x5340: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5345:
	/* 0x5345: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_534a:
	/* 0x534a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534c:
	/* 0x534c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5350:
	/* 0x5350: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5352:
	/* 0x5352: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5358:
	/* 0x5358: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_535b:
	/* 0x535b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_535d:
	/* 0x535d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_5363:
	/* 0x5363: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5368:
	/* 0x5368: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_536e:
	/* 0x536e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5373:
	/* 0x5373: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5378:
	/* 0x5378: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_537a:
	/* 0x537a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_537d:
	/* 0x537d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_5383:
	/* 0x5383: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5387:
	/* 0x5387: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_538d:
	/* 0x538d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5392:
	/* 0x5392: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5396:
	/* 0x5396: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5399:
	/* 0x5399: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_539e:
	/* 0x539e: jmp    5520 <trace_security_mmap_file+0x5520> */
	goto x86_l_5520;
x86_l_53a3:
	/* 0x53a3: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_53a6:
	/* 0x53a6: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_53ac:
	/* 0x53ac: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53b0:
	/* 0x53b0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_53b5:
	/* 0x53b5: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_53bb:
	/* 0x53bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53c0:
	/* 0x53c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53c4:
	/* 0x53c4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_53c8:
	/* 0x53c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53cd:
	/* 0x53cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53d2:
	/* 0x53d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d4:
	/* 0x53d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53d9:
	/* 0x53d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53dd:
	/* 0x53dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_53e0:
	/* 0x53e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53e5:
	/* 0x53e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53e7:
	/* 0x53e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53ec:
	/* 0x53ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53f0:
	/* 0x53f0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53f5:
	/* 0x53f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53fa:
	/* 0x53fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53fc:
	/* 0x53fc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5400:
	/* 0x5400: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5404:
	/* 0x5404: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5409:
	/* 0x5409: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_540e:
	/* 0x540e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5413:
	/* 0x5413: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5416:
	/* 0x5416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5418:
	/* 0x5418: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_541d:
	/* 0x541d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5422:
	/* 0x5422: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5426:
	/* 0x5426: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_542b:
	/* 0x542b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5430:
	/* 0x5430: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5435:
	/* 0x5435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5437:
	/* 0x5437: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_543c:
	/* 0x543c: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_543f:
	/* 0x543f: je     55db <trace_security_mmap_file+0x55db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55db;
	}
x86_l_5445:
	/* 0x5445: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_544a:
	/* 0x544a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_544d:
	/* 0x544d: je     55db <trace_security_mmap_file+0x55db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55db;
	}
x86_l_5453:
	/* 0x5453: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5457:
	/* 0x5457: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_545c:
	/* 0x545c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5461:
	/* 0x5461: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5466:
	/* 0x5466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5468:
	/* 0x5468: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_546c:
	/* 0x546c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_546e:
	/* 0x546e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5474:
	/* 0x5474: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5477:
	/* 0x5477: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5479:
	/* 0x5479: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_547f:
	/* 0x547f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5484:
	/* 0x5484: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_548a:
	/* 0x548a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_548f:
	/* 0x548f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5494:
	/* 0x5494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5496:
	/* 0x5496: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5499:
	/* 0x5499: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_549f:
	/* 0x549f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_54a3:
	/* 0x54a3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_54a9:
	/* 0x54a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54ae:
	/* 0x54ae: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_54b2:
	/* 0x54b2: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_54b5:
	/* 0x54b5: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ba:
	/* 0x54ba: jmp    563c <trace_security_mmap_file+0x563c> */
	goto x86_l_563c;
x86_l_54bf:
	/* 0x54bf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_54c2:
	/* 0x54c2: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_54c8:
	/* 0x54c8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54cc:
	/* 0x54cc: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_54d1:
	/* 0x54d1: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_54d7:
	/* 0x54d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54dc:
	/* 0x54dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54e0:
	/* 0x54e0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54e4:
	/* 0x54e4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54e9:
	/* 0x54e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54ee:
	/* 0x54ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54f0:
	/* 0x54f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54f5:
	/* 0x54f5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f9:
	/* 0x54f9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54fc:
	/* 0x54fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5501:
	/* 0x5501: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5503:
	/* 0x5503: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5508:
	/* 0x5508: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_550c:
	/* 0x550c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5511:
	/* 0x5511: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5516:
	/* 0x5516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5518:
	/* 0x5518: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_551c:
	/* 0x551c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5520:
	/* 0x5520: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5525:
	/* 0x5525: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_552a:
	/* 0x552a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_552f:
	/* 0x552f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5532:
	/* 0x5532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5534:
	/* 0x5534: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5539:
	/* 0x5539: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_553e:
	/* 0x553e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5542:
	/* 0x5542: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5547:
	/* 0x5547: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_554c:
	/* 0x554c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5551:
	/* 0x5551: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5553:
	/* 0x5553: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5558:
	/* 0x5558: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_555b:
	/* 0x555b: je     56f7 <trace_security_mmap_file+0x56f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22263ULL;
	}
x86_l_5561:
	/* 0x5561: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5566:
	/* 0x5566: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5569:
	/* 0x5569: je     56f7 <trace_security_mmap_file+0x56f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22263ULL;
	}
x86_l_556f:
	/* 0x556f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5573:
	/* 0x5573: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5578:
	/* 0x5578: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_557d:
	/* 0x557d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5582:
	/* 0x5582: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5584:
	/* 0x5584: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5588:
	/* 0x5588: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_558a:
	/* 0x558a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5590:
	/* 0x5590: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5593:
	/* 0x5593: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5595:
	/* 0x5595: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_559b:
	/* 0x559b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_55a0:
	/* 0x55a0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_55a6:
	/* 0x55a6: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_55ab:
	/* 0x55ab: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_55b0:
	/* 0x55b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b2:
	/* 0x55b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_55b5:
	/* 0x55b5: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_55bb:
	/* 0x55bb: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_55bf:
	/* 0x55bf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_55c5:
	/* 0x55c5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ca:
	/* 0x55ca: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_55ce:
	/* 0x55ce: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_55d1:
	/* 0x55d1: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55d6:
	/* 0x55d6: jmp    5758 <trace_security_mmap_file+0x5758> */
	return 22360ULL;
x86_l_55db:
	/* 0x55db: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_55de:
	/* 0x55de: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_55e4:
	/* 0x55e4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55e8:
	/* 0x55e8: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_55ed:
	/* 0x55ed: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_55f3:
	/* 0x55f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55f8:
	/* 0x55f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55fc:
	/* 0x55fc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5600:
	/* 0x5600: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5605:
	/* 0x5605: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_560a:
	/* 0x560a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560c:
	/* 0x560c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5611:
	/* 0x5611: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5615:
	/* 0x5615: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5618:
	/* 0x5618: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_561d:
	/* 0x561d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561f:
	/* 0x561f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5624:
	/* 0x5624: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5628:
	/* 0x5628: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_562d:
	/* 0x562d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5632:
	/* 0x5632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5634:
	/* 0x5634: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5638:
	/* 0x5638: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_563c:
	/* 0x563c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5641:
	/* 0x5641: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5646:
	/* 0x5646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564b:
	/* 0x564b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_564e:
	/* 0x564e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5650:
	/* 0x5650: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5655:
	/* 0x5655: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_565a:
	/* 0x565a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_565e:
	/* 0x565e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5663:
	/* 0x5663: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5668:
	/* 0x5668: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_566d:
	/* 0x566d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_566f:
	/* 0x566f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5674:
	/* 0x5674: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5677:
	/* 0x5677: je     5813 <trace_security_mmap_file+0x5813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22547ULL;
	}
x86_l_567d:
	/* 0x567d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5682:
	/* 0x5682: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5685:
	/* 0x5685: je     5813 <trace_security_mmap_file+0x5813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22547ULL;
	}
x86_l_568b:
	/* 0x568b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_568f:
	/* 0x568f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5694:
	/* 0x5694: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5699:
	/* 0x5699: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_569e:
	/* 0x569e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56a0:
	/* 0x56a0: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_56a4:
	/* 0x56a4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_56a6:
	/* 0x56a6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_56ac:
	/* 0x56ac: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_56af:
	/* 0x56af: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56b1:
	/* 0x56b1: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
	return 22199ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22199ULL: goto x86_l_56b7;
	case 22204ULL: goto x86_l_56bc;
	case 22210ULL: goto x86_l_56c2;
	case 22215ULL: goto x86_l_56c7;
	case 22220ULL: goto x86_l_56cc;
	case 22222ULL: goto x86_l_56ce;
	case 22225ULL: goto x86_l_56d1;
	case 22231ULL: goto x86_l_56d7;
	case 22235ULL: goto x86_l_56db;
	case 22241ULL: goto x86_l_56e1;
	case 22246ULL: goto x86_l_56e6;
	case 22250ULL: goto x86_l_56ea;
	case 22253ULL: goto x86_l_56ed;
	case 22258ULL: goto x86_l_56f2;
	case 22263ULL: goto x86_l_56f7;
	case 22266ULL: goto x86_l_56fa;
	case 22272ULL: goto x86_l_5700;
	case 22276ULL: goto x86_l_5704;
	case 22281ULL: goto x86_l_5709;
	case 22287ULL: goto x86_l_570f;
	case 22292ULL: goto x86_l_5714;
	case 22296ULL: goto x86_l_5718;
	case 22300ULL: goto x86_l_571c;
	case 22305ULL: goto x86_l_5721;
	case 22310ULL: goto x86_l_5726;
	case 22312ULL: goto x86_l_5728;
	case 22317ULL: goto x86_l_572d;
	case 22321ULL: goto x86_l_5731;
	case 22324ULL: goto x86_l_5734;
	case 22329ULL: goto x86_l_5739;
	case 22331ULL: goto x86_l_573b;
	case 22336ULL: goto x86_l_5740;
	case 22340ULL: goto x86_l_5744;
	case 22345ULL: goto x86_l_5749;
	case 22350ULL: goto x86_l_574e;
	case 22352ULL: goto x86_l_5750;
	case 22356ULL: goto x86_l_5754;
	case 22360ULL: goto x86_l_5758;
	case 22365ULL: goto x86_l_575d;
	case 22370ULL: goto x86_l_5762;
	case 22375ULL: goto x86_l_5767;
	case 22378ULL: goto x86_l_576a;
	case 22380ULL: goto x86_l_576c;
	case 22385ULL: goto x86_l_5771;
	case 22390ULL: goto x86_l_5776;
	case 22394ULL: goto x86_l_577a;
	case 22399ULL: goto x86_l_577f;
	case 22404ULL: goto x86_l_5784;
	case 22409ULL: goto x86_l_5789;
	case 22411ULL: goto x86_l_578b;
	case 22416ULL: goto x86_l_5790;
	case 22419ULL: goto x86_l_5793;
	case 22425ULL: goto x86_l_5799;
	case 22430ULL: goto x86_l_579e;
	case 22433ULL: goto x86_l_57a1;
	case 22439ULL: goto x86_l_57a7;
	case 22443ULL: goto x86_l_57ab;
	case 22448ULL: goto x86_l_57b0;
	case 22453ULL: goto x86_l_57b5;
	case 22458ULL: goto x86_l_57ba;
	case 22460ULL: goto x86_l_57bc;
	case 22464ULL: goto x86_l_57c0;
	case 22466ULL: goto x86_l_57c2;
	case 22472ULL: goto x86_l_57c8;
	case 22475ULL: goto x86_l_57cb;
	case 22477ULL: goto x86_l_57cd;
	case 22483ULL: goto x86_l_57d3;
	case 22488ULL: goto x86_l_57d8;
	case 22494ULL: goto x86_l_57de;
	case 22499ULL: goto x86_l_57e3;
	case 22504ULL: goto x86_l_57e8;
	case 22506ULL: goto x86_l_57ea;
	case 22509ULL: goto x86_l_57ed;
	case 22515ULL: goto x86_l_57f3;
	case 22519ULL: goto x86_l_57f7;
	case 22525ULL: goto x86_l_57fd;
	case 22530ULL: goto x86_l_5802;
	case 22534ULL: goto x86_l_5806;
	case 22537ULL: goto x86_l_5809;
	case 22542ULL: goto x86_l_580e;
	case 22547ULL: goto x86_l_5813;
	case 22550ULL: goto x86_l_5816;
	case 22556ULL: goto x86_l_581c;
	case 22560ULL: goto x86_l_5820;
	case 22565ULL: goto x86_l_5825;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22580ULL: goto x86_l_5834;
	case 22584ULL: goto x86_l_5838;
	case 22589ULL: goto x86_l_583d;
	case 22594ULL: goto x86_l_5842;
	case 22596ULL: goto x86_l_5844;
	case 22601ULL: goto x86_l_5849;
	case 22605ULL: goto x86_l_584d;
	case 22608ULL: goto x86_l_5850;
	case 22613ULL: goto x86_l_5855;
	case 22615ULL: goto x86_l_5857;
	case 22620ULL: goto x86_l_585c;
	case 22624ULL: goto x86_l_5860;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22636ULL: goto x86_l_586c;
	case 22640ULL: goto x86_l_5870;
	case 22644ULL: goto x86_l_5874;
	case 22649ULL: goto x86_l_5879;
	case 22654ULL: goto x86_l_587e;
	case 22659ULL: goto x86_l_5883;
	case 22662ULL: goto x86_l_5886;
	case 22664ULL: goto x86_l_5888;
	case 22669ULL: goto x86_l_588d;
	case 22674ULL: goto x86_l_5892;
	case 22678ULL: goto x86_l_5896;
	case 22683ULL: goto x86_l_589b;
	case 22688ULL: goto x86_l_58a0;
	case 22693ULL: goto x86_l_58a5;
	case 22695ULL: goto x86_l_58a7;
	case 22700ULL: goto x86_l_58ac;
	case 22703ULL: goto x86_l_58af;
	case 22709ULL: goto x86_l_58b5;
	case 22714ULL: goto x86_l_58ba;
	case 22717ULL: goto x86_l_58bd;
	case 22723ULL: goto x86_l_58c3;
	case 22727ULL: goto x86_l_58c7;
	case 22732ULL: goto x86_l_58cc;
	case 22737ULL: goto x86_l_58d1;
	case 22742ULL: goto x86_l_58d6;
	case 22744ULL: goto x86_l_58d8;
	case 22748ULL: goto x86_l_58dc;
	case 22750ULL: goto x86_l_58de;
	case 22756ULL: goto x86_l_58e4;
	case 22759ULL: goto x86_l_58e7;
	case 22761ULL: goto x86_l_58e9;
	case 22767ULL: goto x86_l_58ef;
	case 22772ULL: goto x86_l_58f4;
	case 22778ULL: goto x86_l_58fa;
	case 22783ULL: goto x86_l_58ff;
	case 22788ULL: goto x86_l_5904;
	case 22790ULL: goto x86_l_5906;
	case 22793ULL: goto x86_l_5909;
	case 22799ULL: goto x86_l_590f;
	case 22803ULL: goto x86_l_5913;
	case 22809ULL: goto x86_l_5919;
	case 22814ULL: goto x86_l_591e;
	case 22818ULL: goto x86_l_5922;
	case 22821ULL: goto x86_l_5925;
	case 22826ULL: goto x86_l_592a;
	case 22831ULL: goto x86_l_592f;
	case 22834ULL: goto x86_l_5932;
	case 22840ULL: goto x86_l_5938;
	case 22844ULL: goto x86_l_593c;
	case 22849ULL: goto x86_l_5941;
	case 22855ULL: goto x86_l_5947;
	case 22860ULL: goto x86_l_594c;
	case 22864ULL: goto x86_l_5950;
	case 22868ULL: goto x86_l_5954;
	case 22873ULL: goto x86_l_5959;
	case 22878ULL: goto x86_l_595e;
	case 22880ULL: goto x86_l_5960;
	case 22885ULL: goto x86_l_5965;
	case 22889ULL: goto x86_l_5969;
	case 22892ULL: goto x86_l_596c;
	case 22897ULL: goto x86_l_5971;
	case 22899ULL: goto x86_l_5973;
	case 22904ULL: goto x86_l_5978;
	case 22908ULL: goto x86_l_597c;
	case 22913ULL: goto x86_l_5981;
	case 22918ULL: goto x86_l_5986;
	case 22920ULL: goto x86_l_5988;
	case 22924ULL: goto x86_l_598c;
	case 22928ULL: goto x86_l_5990;
	case 22933ULL: goto x86_l_5995;
	case 22938ULL: goto x86_l_599a;
	case 22943ULL: goto x86_l_599f;
	case 22946ULL: goto x86_l_59a2;
	case 22948ULL: goto x86_l_59a4;
	case 22953ULL: goto x86_l_59a9;
	case 22958ULL: goto x86_l_59ae;
	case 22962ULL: goto x86_l_59b2;
	case 22967ULL: goto x86_l_59b7;
	case 22972ULL: goto x86_l_59bc;
	case 22977ULL: goto x86_l_59c1;
	case 22979ULL: goto x86_l_59c3;
	case 22984ULL: goto x86_l_59c8;
	case 22987ULL: goto x86_l_59cb;
	case 22993ULL: goto x86_l_59d1;
	case 22998ULL: goto x86_l_59d6;
	case 23001ULL: goto x86_l_59d9;
	case 23007ULL: goto x86_l_59df;
	case 23011ULL: goto x86_l_59e3;
	case 23016ULL: goto x86_l_59e8;
	case 23021ULL: goto x86_l_59ed;
	case 23026ULL: goto x86_l_59f2;
	case 23028ULL: goto x86_l_59f4;
	case 23032ULL: goto x86_l_59f8;
	case 23034ULL: goto x86_l_59fa;
	case 23040ULL: goto x86_l_5a00;
	case 23043ULL: goto x86_l_5a03;
	case 23045ULL: goto x86_l_5a05;
	case 23051ULL: goto x86_l_5a0b;
	case 23056ULL: goto x86_l_5a10;
	case 23062ULL: goto x86_l_5a16;
	case 23067ULL: goto x86_l_5a1b;
	case 23072ULL: goto x86_l_5a20;
	case 23074ULL: goto x86_l_5a22;
	case 23077ULL: goto x86_l_5a25;
	case 23083ULL: goto x86_l_5a2b;
	case 23087ULL: goto x86_l_5a2f;
	case 23093ULL: goto x86_l_5a35;
	case 23098ULL: goto x86_l_5a3a;
	case 23102ULL: goto x86_l_5a3e;
	case 23105ULL: goto x86_l_5a41;
	case 23110ULL: goto x86_l_5a46;
	case 23115ULL: goto x86_l_5a4b;
	case 23118ULL: goto x86_l_5a4e;
	case 23124ULL: goto x86_l_5a54;
	case 23128ULL: goto x86_l_5a58;
	case 23133ULL: goto x86_l_5a5d;
	case 23139ULL: goto x86_l_5a63;
	case 23144ULL: goto x86_l_5a68;
	case 23148ULL: goto x86_l_5a6c;
	case 23152ULL: goto x86_l_5a70;
	case 23157ULL: goto x86_l_5a75;
	case 23162ULL: goto x86_l_5a7a;
	case 23164ULL: goto x86_l_5a7c;
	case 23169ULL: goto x86_l_5a81;
	case 23173ULL: goto x86_l_5a85;
	case 23176ULL: goto x86_l_5a88;
	case 23181ULL: goto x86_l_5a8d;
	case 23183ULL: goto x86_l_5a8f;
	case 23188ULL: goto x86_l_5a94;
	case 23192ULL: goto x86_l_5a98;
	case 23197ULL: goto x86_l_5a9d;
	case 23202ULL: goto x86_l_5aa2;
	case 23204ULL: goto x86_l_5aa4;
	case 23208ULL: goto x86_l_5aa8;
	case 23212ULL: goto x86_l_5aac;
	case 23217ULL: goto x86_l_5ab1;
	case 23222ULL: goto x86_l_5ab6;
	case 23227ULL: goto x86_l_5abb;
	case 23230ULL: goto x86_l_5abe;
	case 23232ULL: goto x86_l_5ac0;
	case 23237ULL: goto x86_l_5ac5;
	case 23242ULL: goto x86_l_5aca;
	case 23246ULL: goto x86_l_5ace;
	case 23251ULL: goto x86_l_5ad3;
	case 23256ULL: goto x86_l_5ad8;
	case 23261ULL: goto x86_l_5add;
	case 23263ULL: goto x86_l_5adf;
	case 23268ULL: goto x86_l_5ae4;
	case 23271ULL: goto x86_l_5ae7;
	case 23277ULL: goto x86_l_5aed;
	case 23282ULL: goto x86_l_5af2;
	case 23285ULL: goto x86_l_5af5;
	case 23291ULL: goto x86_l_5afb;
	case 23295ULL: goto x86_l_5aff;
	case 23300ULL: goto x86_l_5b04;
	case 23305ULL: goto x86_l_5b09;
	case 23310ULL: goto x86_l_5b0e;
	case 23312ULL: goto x86_l_5b10;
	case 23316ULL: goto x86_l_5b14;
	case 23318ULL: goto x86_l_5b16;
	case 23324ULL: goto x86_l_5b1c;
	case 23327ULL: goto x86_l_5b1f;
	case 23329ULL: goto x86_l_5b21;
	case 23335ULL: goto x86_l_5b27;
	case 23340ULL: goto x86_l_5b2c;
	case 23346ULL: goto x86_l_5b32;
	case 23351ULL: goto x86_l_5b37;
	case 23356ULL: goto x86_l_5b3c;
	case 23358ULL: goto x86_l_5b3e;
	case 23361ULL: goto x86_l_5b41;
	case 23367ULL: goto x86_l_5b47;
	case 23371ULL: goto x86_l_5b4b;
	case 23377ULL: goto x86_l_5b51;
	case 23382ULL: goto x86_l_5b56;
	case 23386ULL: goto x86_l_5b5a;
	case 23389ULL: goto x86_l_5b5d;
	case 23394ULL: goto x86_l_5b62;
	case 23399ULL: goto x86_l_5b67;
	case 23402ULL: goto x86_l_5b6a;
	case 23408ULL: goto x86_l_5b70;
	case 23412ULL: goto x86_l_5b74;
	case 23417ULL: goto x86_l_5b79;
	case 23423ULL: goto x86_l_5b7f;
	case 23428ULL: goto x86_l_5b84;
	case 23432ULL: goto x86_l_5b88;
	case 23436ULL: goto x86_l_5b8c;
	case 23441ULL: goto x86_l_5b91;
	case 23446ULL: goto x86_l_5b96;
	case 23448ULL: goto x86_l_5b98;
	case 23453ULL: goto x86_l_5b9d;
	case 23457ULL: goto x86_l_5ba1;
	case 23460ULL: goto x86_l_5ba4;
	case 23465ULL: goto x86_l_5ba9;
	case 23467ULL: goto x86_l_5bab;
	case 23472ULL: goto x86_l_5bb0;
	case 23476ULL: goto x86_l_5bb4;
	case 23481ULL: goto x86_l_5bb9;
	case 23486ULL: goto x86_l_5bbe;
	case 23488ULL: goto x86_l_5bc0;
	case 23492ULL: goto x86_l_5bc4;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23506ULL: goto x86_l_5bd2;
	case 23511ULL: goto x86_l_5bd7;
	case 23514ULL: goto x86_l_5bda;
	case 23516ULL: goto x86_l_5bdc;
	case 23521ULL: goto x86_l_5be1;
	case 23526ULL: goto x86_l_5be6;
	case 23530ULL: goto x86_l_5bea;
	case 23535ULL: goto x86_l_5bef;
	case 23540ULL: goto x86_l_5bf4;
	case 23545ULL: goto x86_l_5bf9;
	case 23547ULL: goto x86_l_5bfb;
	case 23552ULL: goto x86_l_5c00;
	case 23555ULL: goto x86_l_5c03;
	case 23561ULL: goto x86_l_5c09;
	case 23566ULL: goto x86_l_5c0e;
	case 23569ULL: goto x86_l_5c11;
	case 23575ULL: goto x86_l_5c17;
	case 23579ULL: goto x86_l_5c1b;
	case 23584ULL: goto x86_l_5c20;
	case 23589ULL: goto x86_l_5c25;
	case 23594ULL: goto x86_l_5c2a;
	case 23596ULL: goto x86_l_5c2c;
	case 23600ULL: goto x86_l_5c30;
	case 23602ULL: goto x86_l_5c32;
	case 23608ULL: goto x86_l_5c38;
	case 23611ULL: goto x86_l_5c3b;
	case 23613ULL: goto x86_l_5c3d;
	case 23619ULL: goto x86_l_5c43;
	case 23624ULL: goto x86_l_5c48;
	case 23630ULL: goto x86_l_5c4e;
	case 23635ULL: goto x86_l_5c53;
	case 23640ULL: goto x86_l_5c58;
	case 23642ULL: goto x86_l_5c5a;
	case 23645ULL: goto x86_l_5c5d;
	case 23651ULL: goto x86_l_5c63;
	case 23655ULL: goto x86_l_5c67;
	case 23661ULL: goto x86_l_5c6d;
	case 23666ULL: goto x86_l_5c72;
	case 23670ULL: goto x86_l_5c76;
	case 23673ULL: goto x86_l_5c79;
	case 23678ULL: goto x86_l_5c7e;
	case 23683ULL: goto x86_l_5c83;
	case 23686ULL: goto x86_l_5c86;
	case 23692ULL: goto x86_l_5c8c;
	case 23696ULL: goto x86_l_5c90;
	case 23701ULL: goto x86_l_5c95;
	case 23707ULL: goto x86_l_5c9b;
	case 23712ULL: goto x86_l_5ca0;
	case 23716ULL: goto x86_l_5ca4;
	case 23720ULL: goto x86_l_5ca8;
	case 23725ULL: goto x86_l_5cad;
	case 23730ULL: goto x86_l_5cb2;
	case 23732ULL: goto x86_l_5cb4;
	case 23737ULL: goto x86_l_5cb9;
	case 23741ULL: goto x86_l_5cbd;
	case 23744ULL: goto x86_l_5cc0;
	case 23749ULL: goto x86_l_5cc5;
	case 23751ULL: goto x86_l_5cc7;
	case 23756ULL: goto x86_l_5ccc;
	case 23760ULL: goto x86_l_5cd0;
	case 23765ULL: goto x86_l_5cd5;
	case 23770ULL: goto x86_l_5cda;
	case 23772ULL: goto x86_l_5cdc;
	case 23776ULL: goto x86_l_5ce0;
	case 23780ULL: goto x86_l_5ce4;
	case 23785ULL: goto x86_l_5ce9;
	case 23790ULL: goto x86_l_5cee;
	case 23795ULL: goto x86_l_5cf3;
	case 23798ULL: goto x86_l_5cf6;
	case 23800ULL: goto x86_l_5cf8;
	case 23805ULL: goto x86_l_5cfd;
	case 23810ULL: goto x86_l_5d02;
	case 23814ULL: goto x86_l_5d06;
	case 23819ULL: goto x86_l_5d0b;
	case 23824ULL: goto x86_l_5d10;
	case 23829ULL: goto x86_l_5d15;
	case 23831ULL: goto x86_l_5d17;
	case 23836ULL: goto x86_l_5d1c;
	case 23839ULL: goto x86_l_5d1f;
	case 23845ULL: goto x86_l_5d25;
	case 23850ULL: goto x86_l_5d2a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56b7:
	/* 0x56b7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56bc:
	/* 0x56bc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_56c2:
	/* 0x56c2: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56c7:
	/* 0x56c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_56cc:
	/* 0x56cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ce:
	/* 0x56ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_56d1:
	/* 0x56d1: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_56d7:
	/* 0x56d7: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_56db:
	/* 0x56db: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_56e1:
	/* 0x56e1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e6:
	/* 0x56e6: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_56ea:
	/* 0x56ea: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56ed:
	/* 0x56ed: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56f2:
	/* 0x56f2: jmp    5874 <trace_security_mmap_file+0x5874> */
	goto x86_l_5874;
x86_l_56f7:
	/* 0x56f7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_56fa:
	/* 0x56fa: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5700:
	/* 0x5700: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5704:
	/* 0x5704: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5709:
	/* 0x5709: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_570f:
	/* 0x570f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5714:
	/* 0x5714: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5718:
	/* 0x5718: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_571c:
	/* 0x571c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5721:
	/* 0x5721: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5726:
	/* 0x5726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5728:
	/* 0x5728: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_572d:
	/* 0x572d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5731:
	/* 0x5731: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5734:
	/* 0x5734: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5739:
	/* 0x5739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573b:
	/* 0x573b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5740:
	/* 0x5740: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5744:
	/* 0x5744: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5749:
	/* 0x5749: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574e:
	/* 0x574e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5750:
	/* 0x5750: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5754:
	/* 0x5754: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5758:
	/* 0x5758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_575d:
	/* 0x575d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5762:
	/* 0x5762: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5767:
	/* 0x5767: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_576a:
	/* 0x576a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_576c:
	/* 0x576c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5771:
	/* 0x5771: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5776:
	/* 0x5776: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_577a:
	/* 0x577a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_577f:
	/* 0x577f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5784:
	/* 0x5784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5789:
	/* 0x5789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_578b:
	/* 0x578b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5790:
	/* 0x5790: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5793:
	/* 0x5793: je     592f <trace_security_mmap_file+0x592f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_592f;
	}
x86_l_5799:
	/* 0x5799: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_579e:
	/* 0x579e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_57a1:
	/* 0x57a1: je     592f <trace_security_mmap_file+0x592f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_592f;
	}
x86_l_57a7:
	/* 0x57a7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57ab:
	/* 0x57ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57b0:
	/* 0x57b0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57b5:
	/* 0x57b5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_57ba:
	/* 0x57ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57bc:
	/* 0x57bc: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_57c0:
	/* 0x57c0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_57c2:
	/* 0x57c2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_57c8:
	/* 0x57c8: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_57cb:
	/* 0x57cb: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_57cd:
	/* 0x57cd: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_57d3:
	/* 0x57d3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57d8:
	/* 0x57d8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_57de:
	/* 0x57de: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57e3:
	/* 0x57e3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_57e8:
	/* 0x57e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57ea:
	/* 0x57ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_57ed:
	/* 0x57ed: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_57f3:
	/* 0x57f3: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_57f7:
	/* 0x57f7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_57fd:
	/* 0x57fd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5802:
	/* 0x5802: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5806:
	/* 0x5806: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5809:
	/* 0x5809: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_580e:
	/* 0x580e: jmp    5990 <trace_security_mmap_file+0x5990> */
	goto x86_l_5990;
x86_l_5813:
	/* 0x5813: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5816:
	/* 0x5816: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_581c:
	/* 0x581c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5820:
	/* 0x5820: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5825:
	/* 0x5825: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_582b:
	/* 0x582b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5830:
	/* 0x5830: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5834:
	/* 0x5834: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5838:
	/* 0x5838: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_583d:
	/* 0x583d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5842:
	/* 0x5842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5844:
	/* 0x5844: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5849:
	/* 0x5849: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_584d:
	/* 0x584d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5850:
	/* 0x5850: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5855:
	/* 0x5855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5857:
	/* 0x5857: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_585c:
	/* 0x585c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5860:
	/* 0x5860: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5865:
	/* 0x5865: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_586a:
	/* 0x586a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586c:
	/* 0x586c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5870:
	/* 0x5870: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5874:
	/* 0x5874: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5879:
	/* 0x5879: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_587e:
	/* 0x587e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5883:
	/* 0x5883: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5886:
	/* 0x5886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5888:
	/* 0x5888: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_588d:
	/* 0x588d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5892:
	/* 0x5892: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5896:
	/* 0x5896: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_589b:
	/* 0x589b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58a0:
	/* 0x58a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a5:
	/* 0x58a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a7:
	/* 0x58a7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58ac:
	/* 0x58ac: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_58af:
	/* 0x58af: je     5a4b <trace_security_mmap_file+0x5a4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a4b;
	}
x86_l_58b5:
	/* 0x58b5: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58ba:
	/* 0x58ba: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_58bd:
	/* 0x58bd: je     5a4b <trace_security_mmap_file+0x5a4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a4b;
	}
x86_l_58c3:
	/* 0x58c3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_58c7:
	/* 0x58c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58cc:
	/* 0x58cc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58d1:
	/* 0x58d1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_58d6:
	/* 0x58d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58d8:
	/* 0x58d8: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_58dc:
	/* 0x58dc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_58de:
	/* 0x58de: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58e4:
	/* 0x58e4: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_58e7:
	/* 0x58e7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_58e9:
	/* 0x58e9: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_58ef:
	/* 0x58ef: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_58f4:
	/* 0x58f4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_58fa:
	/* 0x58fa: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58ff:
	/* 0x58ff: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5904:
	/* 0x5904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5906:
	/* 0x5906: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5909:
	/* 0x5909: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_590f:
	/* 0x590f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5913:
	/* 0x5913: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5919:
	/* 0x5919: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591e:
	/* 0x591e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5922:
	/* 0x5922: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5925:
	/* 0x5925: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_592a:
	/* 0x592a: jmp    5aac <trace_security_mmap_file+0x5aac> */
	goto x86_l_5aac;
x86_l_592f:
	/* 0x592f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5932:
	/* 0x5932: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5938:
	/* 0x5938: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_593c:
	/* 0x593c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5941:
	/* 0x5941: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_5947:
	/* 0x5947: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_594c:
	/* 0x594c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5950:
	/* 0x5950: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5954:
	/* 0x5954: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5959:
	/* 0x5959: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_595e:
	/* 0x595e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5960:
	/* 0x5960: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5965:
	/* 0x5965: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5969:
	/* 0x5969: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_596c:
	/* 0x596c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5971:
	/* 0x5971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5973:
	/* 0x5973: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5978:
	/* 0x5978: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_597c:
	/* 0x597c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5981:
	/* 0x5981: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5986:
	/* 0x5986: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5988:
	/* 0x5988: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_598c:
	/* 0x598c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5990:
	/* 0x5990: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5995:
	/* 0x5995: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_599a:
	/* 0x599a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_599f:
	/* 0x599f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_59a2:
	/* 0x59a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59a4:
	/* 0x59a4: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59a9:
	/* 0x59a9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59ae:
	/* 0x59ae: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59b2:
	/* 0x59b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59b7:
	/* 0x59b7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59bc:
	/* 0x59bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59c1:
	/* 0x59c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59c3:
	/* 0x59c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59c8:
	/* 0x59c8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_59cb:
	/* 0x59cb: je     5b67 <trace_security_mmap_file+0x5b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b67;
	}
x86_l_59d1:
	/* 0x59d1: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59d6:
	/* 0x59d6: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_59d9:
	/* 0x59d9: je     5b67 <trace_security_mmap_file+0x5b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b67;
	}
x86_l_59df:
	/* 0x59df: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_59e3:
	/* 0x59e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59e8:
	/* 0x59e8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59ed:
	/* 0x59ed: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_59f2:
	/* 0x59f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f4:
	/* 0x59f4: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_59f8:
	/* 0x59f8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_59fa:
	/* 0x59fa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5a00:
	/* 0x5a00: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5a03:
	/* 0x5a03: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a05:
	/* 0x5a05: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_5a0b:
	/* 0x5a0b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a10:
	/* 0x5a10: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5a16:
	/* 0x5a16: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a1b:
	/* 0x5a1b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5a20:
	/* 0x5a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a22:
	/* 0x5a22: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a25:
	/* 0x5a25: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_5a2b:
	/* 0x5a2b: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5a2f:
	/* 0x5a2f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5a35:
	/* 0x5a35: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a3a:
	/* 0x5a3a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5a3e:
	/* 0x5a3e: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a41:
	/* 0x5a41: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a46:
	/* 0x5a46: jmp    5bc8 <trace_security_mmap_file+0x5bc8> */
	goto x86_l_5bc8;
x86_l_5a4b:
	/* 0x5a4b: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a4e:
	/* 0x5a4e: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_5a54:
	/* 0x5a54: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a58:
	/* 0x5a58: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5a5d:
	/* 0x5a5d: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_5a63:
	/* 0x5a63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a68:
	/* 0x5a68: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a6c:
	/* 0x5a6c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a70:
	/* 0x5a70: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a75:
	/* 0x5a75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a7a:
	/* 0x5a7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a7c:
	/* 0x5a7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a81:
	/* 0x5a81: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a85:
	/* 0x5a85: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a88:
	/* 0x5a88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a8d:
	/* 0x5a8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a8f:
	/* 0x5a8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a94:
	/* 0x5a94: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a98:
	/* 0x5a98: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a9d:
	/* 0x5a9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5aa2:
	/* 0x5aa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa4:
	/* 0x5aa4: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aa8:
	/* 0x5aa8: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5aac:
	/* 0x5aac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ab1:
	/* 0x5ab1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ab6:
	/* 0x5ab6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5abb:
	/* 0x5abb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5abe:
	/* 0x5abe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac0:
	/* 0x5ac0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ac5:
	/* 0x5ac5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5aca:
	/* 0x5aca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ace:
	/* 0x5ace: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ad3:
	/* 0x5ad3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ad8:
	/* 0x5ad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5add:
	/* 0x5add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5adf:
	/* 0x5adf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ae4:
	/* 0x5ae4: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5ae7:
	/* 0x5ae7: je     5c83 <trace_security_mmap_file+0x5c83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c83;
	}
x86_l_5aed:
	/* 0x5aed: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5af2:
	/* 0x5af2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5af5:
	/* 0x5af5: je     5c83 <trace_security_mmap_file+0x5c83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c83;
	}
x86_l_5afb:
	/* 0x5afb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5aff:
	/* 0x5aff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b04:
	/* 0x5b04: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b09:
	/* 0x5b09: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5b0e:
	/* 0x5b0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b10:
	/* 0x5b10: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5b14:
	/* 0x5b14: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5b16:
	/* 0x5b16: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b1c:
	/* 0x5b1c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5b1f:
	/* 0x5b1f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b21:
	/* 0x5b21: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_5b27:
	/* 0x5b27: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5b2c:
	/* 0x5b2c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5b32:
	/* 0x5b32: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b37:
	/* 0x5b37: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5b3c:
	/* 0x5b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b3e:
	/* 0x5b3e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b41:
	/* 0x5b41: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_5b47:
	/* 0x5b47: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5b4b:
	/* 0x5b4b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5b51:
	/* 0x5b51: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b56:
	/* 0x5b56: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5b5a:
	/* 0x5b5a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b5d:
	/* 0x5b5d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b62:
	/* 0x5b62: jmp    5ce4 <trace_security_mmap_file+0x5ce4> */
	goto x86_l_5ce4;
x86_l_5b67:
	/* 0x5b67: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5b6a:
	/* 0x5b6a: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5b70:
	/* 0x5b70: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b74:
	/* 0x5b74: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5b79:
	/* 0x5b79: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_5b7f:
	/* 0x5b7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b84:
	/* 0x5b84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b88:
	/* 0x5b88: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b8c:
	/* 0x5b8c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b91:
	/* 0x5b91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b96:
	/* 0x5b96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b98:
	/* 0x5b98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b9d:
	/* 0x5b9d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ba1:
	/* 0x5ba1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5ba4:
	/* 0x5ba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ba9:
	/* 0x5ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bab:
	/* 0x5bab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bb0:
	/* 0x5bb0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bb4:
	/* 0x5bb4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bb9:
	/* 0x5bb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bbe:
	/* 0x5bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc0:
	/* 0x5bc0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bc4:
	/* 0x5bc4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5bc8:
	/* 0x5bc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bcd:
	/* 0x5bcd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bd2:
	/* 0x5bd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bd7:
	/* 0x5bd7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5bda:
	/* 0x5bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bdc:
	/* 0x5bdc: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5be1:
	/* 0x5be1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5be6:
	/* 0x5be6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5bea:
	/* 0x5bea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bef:
	/* 0x5bef: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bf4:
	/* 0x5bf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bf9:
	/* 0x5bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bfb:
	/* 0x5bfb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c00:
	/* 0x5c00: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5c03:
	/* 0x5c03: je     5da0 <trace_security_mmap_file+0x5da0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23968ULL;
	}
x86_l_5c09:
	/* 0x5c09: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c0e:
	/* 0x5c0e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5c11:
	/* 0x5c11: je     5da0 <trace_security_mmap_file+0x5da0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23968ULL;
	}
x86_l_5c17:
	/* 0x5c17: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c1b:
	/* 0x5c1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c20:
	/* 0x5c20: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c25:
	/* 0x5c25: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5c2a:
	/* 0x5c2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2c:
	/* 0x5c2c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5c30:
	/* 0x5c30: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5c32:
	/* 0x5c32: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c38:
	/* 0x5c38: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5c3b:
	/* 0x5c3b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c3d:
	/* 0x5c3d: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_5c43:
	/* 0x5c43: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c48:
	/* 0x5c48: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5c4e:
	/* 0x5c4e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c53:
	/* 0x5c53: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5c58:
	/* 0x5c58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c5a:
	/* 0x5c5a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c5d:
	/* 0x5c5d: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_5c63:
	/* 0x5c63: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5c67:
	/* 0x5c67: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5c6d:
	/* 0x5c6d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c72:
	/* 0x5c72: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5c76:
	/* 0x5c76: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c79:
	/* 0x5c79: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c7e:
	/* 0x5c7e: jmp    5e01 <trace_security_mmap_file+0x5e01> */
	return 24065ULL;
x86_l_5c83:
	/* 0x5c83: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5c86:
	/* 0x5c86: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_5c8c:
	/* 0x5c8c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c90:
	/* 0x5c90: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5c95:
	/* 0x5c95: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_5c9b:
	/* 0x5c9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ca0:
	/* 0x5ca0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ca4:
	/* 0x5ca4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ca8:
	/* 0x5ca8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cad:
	/* 0x5cad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cb2:
	/* 0x5cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb4:
	/* 0x5cb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cb9:
	/* 0x5cb9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cbd:
	/* 0x5cbd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5cc0:
	/* 0x5cc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cc5:
	/* 0x5cc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc7:
	/* 0x5cc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ccc:
	/* 0x5ccc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cd0:
	/* 0x5cd0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5cd5:
	/* 0x5cd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cda:
	/* 0x5cda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cdc:
	/* 0x5cdc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ce0:
	/* 0x5ce0: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ce4:
	/* 0x5ce4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ce9:
	/* 0x5ce9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cee:
	/* 0x5cee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cf3:
	/* 0x5cf3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5cf6:
	/* 0x5cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf8:
	/* 0x5cf8: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cfd:
	/* 0x5cfd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d02:
	/* 0x5d02: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d06:
	/* 0x5d06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d0b:
	/* 0x5d0b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d10:
	/* 0x5d10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d15:
	/* 0x5d15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d17:
	/* 0x5d17: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d1c:
	/* 0x5d1c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5d1f:
	/* 0x5d1f: je     5ebd <trace_security_mmap_file+0x5ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24253ULL;
	}
x86_l_5d25:
	/* 0x5d25: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d2a:
	/* 0x5d2a: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
	return 23853ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23853ULL: goto x86_l_5d2d;
	case 23859ULL: goto x86_l_5d33;
	case 23863ULL: goto x86_l_5d37;
	case 23868ULL: goto x86_l_5d3c;
	case 23873ULL: goto x86_l_5d41;
	case 23878ULL: goto x86_l_5d46;
	case 23880ULL: goto x86_l_5d48;
	case 23884ULL: goto x86_l_5d4c;
	case 23886ULL: goto x86_l_5d4e;
	case 23892ULL: goto x86_l_5d54;
	case 23895ULL: goto x86_l_5d57;
	case 23897ULL: goto x86_l_5d59;
	case 23903ULL: goto x86_l_5d5f;
	case 23908ULL: goto x86_l_5d64;
	case 23914ULL: goto x86_l_5d6a;
	case 23919ULL: goto x86_l_5d6f;
	case 23924ULL: goto x86_l_5d74;
	case 23926ULL: goto x86_l_5d76;
	case 23929ULL: goto x86_l_5d79;
	case 23935ULL: goto x86_l_5d7f;
	case 23939ULL: goto x86_l_5d83;
	case 23945ULL: goto x86_l_5d89;
	case 23950ULL: goto x86_l_5d8e;
	case 23955ULL: goto x86_l_5d93;
	case 23958ULL: goto x86_l_5d96;
	case 23963ULL: goto x86_l_5d9b;
	case 23968ULL: goto x86_l_5da0;
	case 23971ULL: goto x86_l_5da3;
	case 23977ULL: goto x86_l_5da9;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23992ULL: goto x86_l_5db8;
	case 23997ULL: goto x86_l_5dbd;
	case 24001ULL: goto x86_l_5dc1;
	case 24005ULL: goto x86_l_5dc5;
	case 24010ULL: goto x86_l_5dca;
	case 24015ULL: goto x86_l_5dcf;
	case 24017ULL: goto x86_l_5dd1;
	case 24022ULL: goto x86_l_5dd6;
	case 24026ULL: goto x86_l_5dda;
	case 24029ULL: goto x86_l_5ddd;
	case 24034ULL: goto x86_l_5de2;
	case 24036ULL: goto x86_l_5de4;
	case 24041ULL: goto x86_l_5de9;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24057ULL: goto x86_l_5df9;
	case 24061ULL: goto x86_l_5dfd;
	case 24065ULL: goto x86_l_5e01;
	case 24070ULL: goto x86_l_5e06;
	case 24075ULL: goto x86_l_5e0b;
	case 24080ULL: goto x86_l_5e10;
	case 24083ULL: goto x86_l_5e13;
	case 24085ULL: goto x86_l_5e15;
	case 24090ULL: goto x86_l_5e1a;
	case 24095ULL: goto x86_l_5e1f;
	case 24099ULL: goto x86_l_5e23;
	case 24104ULL: goto x86_l_5e28;
	case 24109ULL: goto x86_l_5e2d;
	case 24114ULL: goto x86_l_5e32;
	case 24116ULL: goto x86_l_5e34;
	case 24121ULL: goto x86_l_5e39;
	case 24124ULL: goto x86_l_5e3c;
	case 24130ULL: goto x86_l_5e42;
	case 24135ULL: goto x86_l_5e47;
	case 24138ULL: goto x86_l_5e4a;
	case 24144ULL: goto x86_l_5e50;
	case 24148ULL: goto x86_l_5e54;
	case 24153ULL: goto x86_l_5e59;
	case 24158ULL: goto x86_l_5e5e;
	case 24163ULL: goto x86_l_5e63;
	case 24165ULL: goto x86_l_5e65;
	case 24169ULL: goto x86_l_5e69;
	case 24171ULL: goto x86_l_5e6b;
	case 24177ULL: goto x86_l_5e71;
	case 24180ULL: goto x86_l_5e74;
	case 24182ULL: goto x86_l_5e76;
	case 24188ULL: goto x86_l_5e7c;
	case 24193ULL: goto x86_l_5e81;
	case 24199ULL: goto x86_l_5e87;
	case 24204ULL: goto x86_l_5e8c;
	case 24209ULL: goto x86_l_5e91;
	case 24211ULL: goto x86_l_5e93;
	case 24214ULL: goto x86_l_5e96;
	case 24220ULL: goto x86_l_5e9c;
	case 24224ULL: goto x86_l_5ea0;
	case 24230ULL: goto x86_l_5ea6;
	case 24235ULL: goto x86_l_5eab;
	case 24240ULL: goto x86_l_5eb0;
	case 24243ULL: goto x86_l_5eb3;
	case 24248ULL: goto x86_l_5eb8;
	case 24253ULL: goto x86_l_5ebd;
	case 24256ULL: goto x86_l_5ec0;
	case 24262ULL: goto x86_l_5ec6;
	case 24266ULL: goto x86_l_5eca;
	case 24271ULL: goto x86_l_5ecf;
	case 24277ULL: goto x86_l_5ed5;
	case 24282ULL: goto x86_l_5eda;
	case 24286ULL: goto x86_l_5ede;
	case 24290ULL: goto x86_l_5ee2;
	case 24295ULL: goto x86_l_5ee7;
	case 24300ULL: goto x86_l_5eec;
	case 24302ULL: goto x86_l_5eee;
	case 24307ULL: goto x86_l_5ef3;
	case 24311ULL: goto x86_l_5ef7;
	case 24314ULL: goto x86_l_5efa;
	case 24319ULL: goto x86_l_5eff;
	case 24321ULL: goto x86_l_5f01;
	case 24326ULL: goto x86_l_5f06;
	case 24330ULL: goto x86_l_5f0a;
	case 24335ULL: goto x86_l_5f0f;
	case 24340ULL: goto x86_l_5f14;
	case 24342ULL: goto x86_l_5f16;
	case 24347ULL: goto x86_l_5f1b;
	case 24350ULL: goto x86_l_5f1e;
	case 24356ULL: goto x86_l_5f24;
	case 24360ULL: goto x86_l_5f28;
	case 24365ULL: goto x86_l_5f2d;
	case 24371ULL: goto x86_l_5f33;
	case 24376ULL: goto x86_l_5f38;
	case 24380ULL: goto x86_l_5f3c;
	case 24384ULL: goto x86_l_5f40;
	case 24389ULL: goto x86_l_5f45;
	case 24394ULL: goto x86_l_5f4a;
	case 24396ULL: goto x86_l_5f4c;
	case 24401ULL: goto x86_l_5f51;
	case 24405ULL: goto x86_l_5f55;
	case 24408ULL: goto x86_l_5f58;
	case 24413ULL: goto x86_l_5f5d;
	case 24415ULL: goto x86_l_5f5f;
	case 24420ULL: goto x86_l_5f64;
	case 24424ULL: goto x86_l_5f68;
	case 24429ULL: goto x86_l_5f6d;
	case 24434ULL: goto x86_l_5f72;
	case 24436ULL: goto x86_l_5f74;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5d2d:
	/* 0x5d2d: je     5ebd <trace_security_mmap_file+0x5ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ebd;
	}
x86_l_5d33:
	/* 0x5d33: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d37:
	/* 0x5d37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d3c:
	/* 0x5d3c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d41:
	/* 0x5d41: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5d46:
	/* 0x5d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d48:
	/* 0x5d48: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5d4c:
	/* 0x5d4c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5d4e:
	/* 0x5d4e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d54:
	/* 0x5d54: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5d57:
	/* 0x5d57: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d59:
	/* 0x5d59: jb     1784 <trace_security_mmap_file+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6020ULL;
	}
x86_l_5d5f:
	/* 0x5d5f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d64:
	/* 0x5d64: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5d6a:
	/* 0x5d6a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d6f:
	/* 0x5d6f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5d74:
	/* 0x5d74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d76:
	/* 0x5d76: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5d79:
	/* 0x5d79: jl     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6039ULL;
	}
x86_l_5d7f:
	/* 0x5d7f: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5d83:
	/* 0x5d83: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5d89:
	/* 0x5d89: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8e:
	/* 0x5d8e: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5d93:
	/* 0x5d93: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d96:
	/* 0x5d96: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d9b:
	/* 0x5d9b: jmp    179c <trace_security_mmap_file+0x179c> */
	return 6044ULL;
x86_l_5da0:
	/* 0x5da0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5da3:
	/* 0x5da3: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5da9:
	/* 0x5da9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dad:
	/* 0x5dad: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5db2:
	/* 0x5db2: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_5db8:
	/* 0x5db8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dbd:
	/* 0x5dbd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dc1:
	/* 0x5dc1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5dc5:
	/* 0x5dc5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dca:
	/* 0x5dca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dcf:
	/* 0x5dcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dd1:
	/* 0x5dd1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dd6:
	/* 0x5dd6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dda:
	/* 0x5dda: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5ddd:
	/* 0x5ddd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5de2:
	/* 0x5de2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de4:
	/* 0x5de4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5de9:
	/* 0x5de9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ded:
	/* 0x5ded: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5df2:
	/* 0x5df2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5df7:
	/* 0x5df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df9:
	/* 0x5df9: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dfd:
	/* 0x5dfd: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e01:
	/* 0x5e01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e06:
	/* 0x5e06: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e0b:
	/* 0x5e0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e10:
	/* 0x5e10: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5e13:
	/* 0x5e13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e15:
	/* 0x5e15: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e1a:
	/* 0x5e1a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e1f:
	/* 0x5e1f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e23:
	/* 0x5e23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e28:
	/* 0x5e28: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e2d:
	/* 0x5e2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e32:
	/* 0x5e32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e34:
	/* 0x5e34: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e39:
	/* 0x5e39: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5e3c:
	/* 0x5e3c: je     5f1b <trace_security_mmap_file+0x5f1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f1b;
	}
x86_l_5e42:
	/* 0x5e42: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e47:
	/* 0x5e47: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5e4a:
	/* 0x5e4a: je     5f1b <trace_security_mmap_file+0x5f1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f1b;
	}
x86_l_5e50:
	/* 0x5e50: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e54:
	/* 0x5e54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e59:
	/* 0x5e59: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e5e:
	/* 0x5e5e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5e63:
	/* 0x5e63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e65:
	/* 0x5e65: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5e69:
	/* 0x5e69: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5e6b:
	/* 0x5e6b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e71:
	/* 0x5e71: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_5e74:
	/* 0x5e74: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e76:
	/* 0x5e76: jb     29a9 <trace_security_mmap_file+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10665ULL;
	}
x86_l_5e7c:
	/* 0x5e7c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e81:
	/* 0x5e81: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5e87:
	/* 0x5e87: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e8c:
	/* 0x5e8c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5e91:
	/* 0x5e91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e93:
	/* 0x5e93: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e96:
	/* 0x5e96: jl     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10712ULL;
	}
x86_l_5e9c:
	/* 0x5e9c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ea0:
	/* 0x5ea0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ea6:
	/* 0x5ea6: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eab:
	/* 0x5eab: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5eb0:
	/* 0x5eb0: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5eb3:
	/* 0x5eb3: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5eb8:
	/* 0x5eb8: jmp    29dd <trace_security_mmap_file+0x29dd> */
	return 10717ULL;
x86_l_5ebd:
	/* 0x5ebd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5ec0:
	/* 0x5ec0: jne    1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6039ULL;
	}
x86_l_5ec6:
	/* 0x5ec6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eca:
	/* 0x5eca: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5ecf:
	/* 0x5ecf: je     1797 <trace_security_mmap_file+0x1797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6039ULL;
	}
x86_l_5ed5:
	/* 0x5ed5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5eda:
	/* 0x5eda: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ede:
	/* 0x5ede: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ee2:
	/* 0x5ee2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ee7:
	/* 0x5ee7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eec:
	/* 0x5eec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eee:
	/* 0x5eee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ef3:
	/* 0x5ef3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ef7:
	/* 0x5ef7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5efa:
	/* 0x5efa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eff:
	/* 0x5eff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f01:
	/* 0x5f01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f06:
	/* 0x5f06: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f0a:
	/* 0x5f0a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f0f:
	/* 0x5f0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f14:
	/* 0x5f14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f16:
	/* 0x5f16: jmp    1797 <trace_security_mmap_file+0x1797> */
	return 6039ULL;
x86_l_5f1b:
	/* 0x5f1b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5f1e:
	/* 0x5f1e: jne    29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10712ULL;
	}
x86_l_5f24:
	/* 0x5f24: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f28:
	/* 0x5f28: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5f2d:
	/* 0x5f2d: je     29d8 <trace_security_mmap_file+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10712ULL;
	}
x86_l_5f33:
	/* 0x5f33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f38:
	/* 0x5f38: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f3c:
	/* 0x5f3c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f40:
	/* 0x5f40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f45:
	/* 0x5f45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f4a:
	/* 0x5f4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f4c:
	/* 0x5f4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f51:
	/* 0x5f51: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f55:
	/* 0x5f55: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f58:
	/* 0x5f58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5d:
	/* 0x5f5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f5f:
	/* 0x5f5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f64:
	/* 0x5f64: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f68:
	/* 0x5f68: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f6d:
	/* 0x5f6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f72:
	/* 0x5f72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f74:
	/* 0x5f74: jmp    29d8 <trace_security_mmap_file+0x29d8> */
	return 10712ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_security_mmap_file_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22048U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2128ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2133ULL && __x86_pc <= 3842ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3849ULL && __x86_pc <= 5424ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5427ULL && __x86_pc <= 7160ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7162ULL && __x86_pc <= 8898ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8903ULL && __x86_pc <= 10489ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10494ULL && __x86_pc <= 12312ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12317ULL && __x86_pc <= 13960ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13965ULL && __x86_pc <= 15588ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15593ULL && __x86_pc <= 17240ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17244ULL && __x86_pc <= 18897ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 18902ULL && __x86_pc <= 20546ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20549ULL && __x86_pc <= 22193ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22199ULL && __x86_pc <= 23850ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 23853ULL && __x86_pc <= 24436ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

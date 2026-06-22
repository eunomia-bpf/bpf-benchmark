extern char args_map;
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

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_0(
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
	case 25ULL: goto x86_l_19;
	case 35ULL: goto x86_l_23;
	case 40ULL: goto x86_l_28;
	case 42ULL: goto x86_l_2a;
	case 44ULL: goto x86_l_2c;
	case 47ULL: goto x86_l_2f;
	case 51ULL: goto x86_l_33;
	case 58ULL: goto x86_l_3a;
	case 61ULL: goto x86_l_3d;
	case 66ULL: goto x86_l_42;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 77ULL: goto x86_l_4d;
	case 80ULL: goto x86_l_50;
	case 88ULL: goto x86_l_58;
	case 93ULL: goto x86_l_5d;
	case 95ULL: goto x86_l_5f;
	case 97ULL: goto x86_l_61;
	case 100ULL: goto x86_l_64;
	case 104ULL: goto x86_l_68;
	case 111ULL: goto x86_l_6f;
	case 114ULL: goto x86_l_72;
	case 119ULL: goto x86_l_77;
	case 121ULL: goto x86_l_79;
	case 133ULL: goto x86_l_85;
	case 145ULL: goto x86_l_91;
	case 157ULL: goto x86_l_9d;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 234ULL: goto x86_l_ea;
	case 237ULL: goto x86_l_ed;
	case 242ULL: goto x86_l_f2;
	case 244ULL: goto x86_l_f4;
	case 247ULL: goto x86_l_f7;
	case 249ULL: goto x86_l_f9;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 258ULL: goto x86_l_102;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 279ULL: goto x86_l_117;
	case 281ULL: goto x86_l_119;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 291ULL: goto x86_l_123;
	case 293ULL: goto x86_l_125;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 312ULL: goto x86_l_138;
	case 315ULL: goto x86_l_13b;
	case 317ULL: goto x86_l_13d;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 337ULL: goto x86_l_151;
	case 345ULL: goto x86_l_159;
	case 353ULL: goto x86_l_161;
	case 360ULL: goto x86_l_168;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 375ULL: goto x86_l_177;
	case 383ULL: goto x86_l_17f;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 402ULL: goto x86_l_192;
	case 410ULL: goto x86_l_19a;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 434ULL: goto x86_l_1b2;
	case 445ULL: goto x86_l_1bd;
	case 454ULL: goto x86_l_1c6;
	case 466ULL: goto x86_l_1d2;
	case 478ULL: goto x86_l_1de;
	case 490ULL: goto x86_l_1ea;
	case 502ULL: goto x86_l_1f6;
	case 514ULL: goto x86_l_202;
	case 526ULL: goto x86_l_20e;
	case 538ULL: goto x86_l_21a;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 567ULL: goto x86_l_237;
	case 576ULL: goto x86_l_240;
	case 585ULL: goto x86_l_249;
	case 594ULL: goto x86_l_252;
	case 603ULL: goto x86_l_25b;
	case 612ULL: goto x86_l_264;
	case 621ULL: goto x86_l_26d;
	case 630ULL: goto x86_l_276;
	case 639ULL: goto x86_l_27f;
	case 648ULL: goto x86_l_288;
	case 657ULL: goto x86_l_291;
	case 666ULL: goto x86_l_29a;
	case 675ULL: goto x86_l_2a3;
	case 680ULL: goto x86_l_2a8;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 691ULL: goto x86_l_2b3;
	case 696ULL: goto x86_l_2b8;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 721ULL: goto x86_l_2d1;
	case 723ULL: goto x86_l_2d3;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 739ULL: goto x86_l_2e3;
	case 746ULL: goto x86_l_2ea;
	case 753ULL: goto x86_l_2f1;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 768ULL: goto x86_l_300;
	case 776ULL: goto x86_l_308;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 786ULL: goto x86_l_312;
	case 793ULL: goto x86_l_319;
	case 800ULL: goto x86_l_320;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 815ULL: goto x86_l_32f;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 832ULL: goto x86_l_340;
	case 840ULL: goto x86_l_348;
	case 845ULL: goto x86_l_34d;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 866ULL: goto x86_l_362;
	case 871ULL: goto x86_l_367;
	case 878ULL: goto x86_l_36e;
	case 882ULL: goto x86_l_372;
	case 890ULL: goto x86_l_37a;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 909ULL: goto x86_l_38d;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 921ULL: goto x86_l_399;
	case 925ULL: goto x86_l_39d;
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
	case 1192ULL: goto x86_l_4a8;
	case 1203ULL: goto x86_l_4b3;
	case 1214ULL: goto x86_l_4be;
	case 1225ULL: goto x86_l_4c9;
	case 1236ULL: goto x86_l_4d4;
	case 1247ULL: goto x86_l_4df;
	case 1258ULL: goto x86_l_4ea;
	case 1266ULL: goto x86_l_4f2;
	case 1274ULL: goto x86_l_4fa;
	case 1282ULL: goto x86_l_502;
	case 1290ULL: goto x86_l_50a;
	case 1298ULL: goto x86_l_512;
	case 1306ULL: goto x86_l_51a;
	case 1314ULL: goto x86_l_522;
	case 1322ULL: goto x86_l_52a;
	case 1330ULL: goto x86_l_532;
	case 1338ULL: goto x86_l_53a;
	case 1346ULL: goto x86_l_542;
	case 1354ULL: goto x86_l_54a;
	case 1362ULL: goto x86_l_552;
	case 1370ULL: goto x86_l_55a;
	case 1378ULL: goto x86_l_562;
	case 1385ULL: goto x86_l_569;
	case 1392ULL: goto x86_l_570;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1405ULL: goto x86_l_57d;
	case 1408ULL: goto x86_l_580;
	case 1410ULL: goto x86_l_582;
	case 1415ULL: goto x86_l_587;
	case 1420ULL: goto x86_l_58c;
	case 1423ULL: goto x86_l_58f;
	case 1425ULL: goto x86_l_591;
	case 1433ULL: goto x86_l_599;
	case 1436ULL: goto x86_l_59c;
	case 1442ULL: goto x86_l_5a2;
	case 1447ULL: goto x86_l_5a7;
	case 1454ULL: goto x86_l_5ae;
	case 1458ULL: goto x86_l_5b2;
	case 1466ULL: goto x86_l_5ba;
	case 1473ULL: goto x86_l_5c1;
	case 1478ULL: goto x86_l_5c6;
	case 1483ULL: goto x86_l_5cb;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1494ULL: goto x86_l_5d6;
	case 1500ULL: goto x86_l_5dc;
	case 1503ULL: goto x86_l_5df;
	case 1507ULL: goto x86_l_5e3;
	case 1510ULL: goto x86_l_5e6;
	case 1521ULL: goto x86_l_5f1;
	case 1532ULL: goto x86_l_5fc;
	case 1543ULL: goto x86_l_607;
	case 1554ULL: goto x86_l_612;
	case 1565ULL: goto x86_l_61d;
	case 1576ULL: goto x86_l_628;
	case 1587ULL: goto x86_l_633;
	case 1598ULL: goto x86_l_63e;
	case 1609ULL: goto x86_l_649;
	case 1617ULL: goto x86_l_651;
	case 1625ULL: goto x86_l_659;
	case 1633ULL: goto x86_l_661;
	case 1641ULL: goto x86_l_669;
	case 1649ULL: goto x86_l_671;
	case 1657ULL: goto x86_l_679;
	case 1665ULL: goto x86_l_681;
	case 1673ULL: goto x86_l_689;
	case 1681ULL: goto x86_l_691;
	case 1689ULL: goto x86_l_699;
	case 1697ULL: goto x86_l_6a1;
	case 1705ULL: goto x86_l_6a9;
	case 1713ULL: goto x86_l_6b1;
	case 1721ULL: goto x86_l_6b9;
	case 1729ULL: goto x86_l_6c1;
	case 1736ULL: goto x86_l_6c8;
	case 1743ULL: goto x86_l_6cf;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1759ULL: goto x86_l_6df;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1784ULL: goto x86_l_6f8;
	case 1787ULL: goto x86_l_6fb;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1829ULL: goto x86_l_725;
	case 1831ULL: goto x86_l_727;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1864ULL: goto x86_l_748;
	case 1868ULL: goto x86_l_74c;
	case 1872ULL: goto x86_l_750;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1896ULL: goto x86_l_768;
	case 1900ULL: goto x86_l_76c;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1963ULL: goto x86_l_7ab;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1986ULL: goto x86_l_7c2;
	case 1989ULL: goto x86_l_7c5;
	case 1993ULL: goto x86_l_7c9;
	case 1997ULL: goto x86_l_7cd;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2028ULL: goto x86_l_7ec;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2049ULL: goto x86_l_801;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2083ULL: goto x86_l_823;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2113ULL: goto x86_l_841;
	case 2117ULL: goto x86_l_845;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
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
	/* 0xa: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19:
	/* 0x19: movabs rbx,0x2fa00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3272765079552ULL);
x86_l_23:
	/* 0x23: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28:
	/* 0x28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a:
	/* 0x2a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c:
	/* 0x2c: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2f:
	/* 0x2f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33:
	/* 0x33: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_3a:
	/* 0x3a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42:
	/* 0x42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44:
	/* 0x44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47:
	/* 0x47: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_4d:
	/* 0x4d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58:
	/* 0x58: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5d:
	/* 0x5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f:
	/* 0x5f: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_61:
	/* 0x61: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68:
	/* 0x68: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_6f:
	/* 0x6f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_72:
	/* 0x72: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_77:
	/* 0x77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_85:
	/* 0x85: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_a9:
	/* 0xa9: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_ae:
	/* 0xae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0:
	/* 0xb0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_b8:
	/* 0xb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba:
	/* 0xba: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c1:
	/* 0xc1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c9:
	/* 0xc9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce:
	/* 0xce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d3:
	/* 0xd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5:
	/* 0xd5: test   DWORD PTR [rsp],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2097152ULL);
x86_l_dc:
	/* 0xdc: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_e1:
	/* 0xe1: jne    146 <trace_ret_do_init_module+0x146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_146;
	}
x86_l_e3:
	/* 0xe3: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_e8:
	/* 0xe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea:
	/* 0xea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_f2:
	/* 0xf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4:
	/* 0xf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: je     fe <trace_ret_do_init_module+0xfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe;
	}
x86_l_f9:
	/* 0xf9: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_fc:
	/* 0xfc: jmp    fe <trace_ret_do_init_module+0xfe> */
	goto x86_l_fe;
x86_l_fe:
	/* 0xfe: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_102:
	/* 0x102: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_105:
	/* 0x105: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10a:
	/* 0x10a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f:
	/* 0x10f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_114:
	/* 0x114: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_117:
	/* 0x117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119:
	/* 0x119: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_11d:
	/* 0x11d: jne    125 <trace_ret_do_init_module+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_125;
	}
x86_l_11f:
	/* 0x11f: mov    ebp,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_123:
	/* 0x123: jmp    146 <trace_ret_do_init_module+0x146> */
	goto x86_l_146;
x86_l_125:
	/* 0x125: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_12c:
	/* 0x12c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_131:
	/* 0x131: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_136:
	/* 0x136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138:
	/* 0x138: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: je     141 <trace_ret_do_init_module+0x141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_141;
	}
x86_l_13d:
	/* 0x13d: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f:
	/* 0x13f: jmp    146 <trace_ret_do_init_module+0x146> */
	goto x86_l_146;
x86_l_141:
	/* 0x141: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_146:
	/* 0x146: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_151:
	/* 0x151: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_161:
	/* 0x161: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_168:
	/* 0x168: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_170:
	/* 0x170: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_175:
	/* 0x175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177:
	/* 0x177: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17f:
	/* 0x17f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_182:
	/* 0x182: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_188:
	/* 0x188: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_192:
	/* 0x192: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_19a:
	/* 0x19a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f:
	/* 0x19f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a9:
	/* 0x1a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_1b2:
	/* 0x1b2: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_1bd:
	/* 0x1bd: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_1d2:
	/* 0x1d2: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1de:
	/* 0x1de: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1ea:
	/* 0x1ea: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_202:
	/* 0x202: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_226:
	/* 0x226: mov    QWORD PTR [r12+0x7dd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_22e:
	/* 0x22e: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_237:
	/* 0x237: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_240:
	/* 0x240: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_249:
	/* 0x249: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_252:
	/* 0x252: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_25b:
	/* 0x25b: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_264:
	/* 0x264: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_26d:
	/* 0x26d: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_276:
	/* 0x276: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_27f:
	/* 0x27f: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_288:
	/* 0x288: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_291:
	/* 0x291: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_29a:
	/* 0x29a: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2a3:
	/* 0x2a3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2a8:
	/* 0x2a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa:
	/* 0x2aa: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2af:
	/* 0x2af: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2b3:
	/* 0x2b3: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b8:
	/* 0x2b8: mov    DWORD PTR [r12+0x70],0x310 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337936ULL);
x86_l_2c1:
	/* 0x2c1: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2c6:
	/* 0x2c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8:
	/* 0x2c8: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc:
	/* 0x2cc: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2d1:
	/* 0x2d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3:
	/* 0x2d3: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2d9:
	/* 0x2d9: mov    DWORD PTR [r12+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2de:
	/* 0x2de: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e3:
	/* 0x2e3: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ea:
	/* 0x2ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2f1:
	/* 0x2f1: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f9:
	/* 0x2f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fe:
	/* 0x2fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300:
	/* 0x300: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_308:
	/* 0x308: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30b:
	/* 0x30b: je     367 <trace_ret_do_init_module+0x367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367;
	}
x86_l_30d:
	/* 0x30d: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_312:
	/* 0x312: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_319:
	/* 0x319: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_320:
	/* 0x320: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_328:
	/* 0x328: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32d:
	/* 0x32d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f:
	/* 0x32f: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_337:
	/* 0x337: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: je     5a7 <trace_ret_do_init_module+0x5a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a7;
	}
x86_l_340:
	/* 0x340: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_348:
	/* 0x348: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_34d:
	/* 0x34d: jne    b4a <trace_ret_do_init_module+0xb4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2890ULL;
	}
x86_l_353:
	/* 0x353: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_358:
	/* 0x358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a:
	/* 0x35a: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_362:
	/* 0x362: jmp    bf3 <trace_ret_do_init_module+0xbf3> */
	return 3059ULL;
x86_l_367:
	/* 0x367: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_36e:
	/* 0x36e: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_372:
	/* 0x372: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_37a:
	/* 0x37a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_381:
	/* 0x381: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_386:
	/* 0x386: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38b:
	/* 0x38b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d:
	/* 0x38d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_390:
	/* 0x390: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_396:
	/* 0x396: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_399:
	/* 0x399: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_39d:
	/* 0x39d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_3c1:
	/* 0x3c1: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_3cc:
	/* 0x3cc: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_3e2:
	/* 0x3e2: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_3ed:
	/* 0x3ed: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_3f8:
	/* 0x3f8: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_403:
	/* 0x403: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_40e:
	/* 0x40e: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_419:
	/* 0x419: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_42f:
	/* 0x42f: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_43a:
	/* 0x43a: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_450:
	/* 0x450: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_471:
	/* 0x471: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_492:
	/* 0x492: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_4a8:
	/* 0x4a8: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_4be:
	/* 0x4be: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_4c9:
	/* 0x4c9: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_4d4:
	/* 0x4d4: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_4df:
	/* 0x4df: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_4ea:
	/* 0x4ea: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4f2:
	/* 0x4f2: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4fa:
	/* 0x4fa: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_50a:
	/* 0x50a: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_512:
	/* 0x512: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_51a:
	/* 0x51a: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_522:
	/* 0x522: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_532:
	/* 0x532: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_53a:
	/* 0x53a: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_542:
	/* 0x542: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_54a:
	/* 0x54a: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_55a:
	/* 0x55a: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_562:
	/* 0x562: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_569:
	/* 0x569: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_570:
	/* 0x570: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_573:
	/* 0x573: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_578:
	/* 0x578: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_57d:
	/* 0x57d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_580:
	/* 0x580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_582:
	/* 0x582: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_587:
	/* 0x587: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58c:
	/* 0x58c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_58f:
	/* 0x58f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_591:
	/* 0x591: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_599:
	/* 0x599: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: jne    30d <trace_ret_do_init_module+0x30d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30d;
	}
x86_l_5a2:
	/* 0x5a2: jmp    2561 <trace_ret_do_init_module+0x2561> */
	return 9569ULL;
x86_l_5a7:
	/* 0x5a7: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_5ae:
	/* 0x5ae: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5b2:
	/* 0x5b2: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5ba:
	/* 0x5ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_5c1:
	/* 0x5c1: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5c6:
	/* 0x5c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cb:
	/* 0x5cb: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_5d1:
	/* 0x5d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3:
	/* 0x5d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d6:
	/* 0x5d6: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_5dc:
	/* 0x5dc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5df:
	/* 0x5df: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5e3:
	/* 0x5e3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_5f1:
	/* 0x5f1: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_5fc:
	/* 0x5fc: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_607:
	/* 0x607: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_61d:
	/* 0x61d: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_628:
	/* 0x628: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_63e:
	/* 0x63e: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_649:
	/* 0x649: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_651:
	/* 0x651: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_659:
	/* 0x659: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_661:
	/* 0x661: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_669:
	/* 0x669: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_671:
	/* 0x671: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_679:
	/* 0x679: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_681:
	/* 0x681: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_689:
	/* 0x689: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_691:
	/* 0x691: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_699:
	/* 0x699: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_6a1:
	/* 0x6a1: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6b1:
	/* 0x6b1: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6b9:
	/* 0x6b9: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6c1:
	/* 0x6c1: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c8:
	/* 0x6c8: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_6cf:
	/* 0x6cf: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6d7:
	/* 0x6d7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6dc:
	/* 0x6dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e1:
	/* 0x6e1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e6:
	/* 0x6e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6eb:
	/* 0x6eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6f8:
	/* 0x6f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_701:
	/* 0x701: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_704:
	/* 0x704: mov    rbx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_70c:
	/* 0x70c: lea    r13,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_710:
	/* 0x710: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x722: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_725:
	/* 0x725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_727:
	/* 0x727: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72b:
	/* 0x72b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_730:
	/* 0x730: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_734:
	/* 0x734: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_737:
	/* 0x737: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_73c:
	/* 0x73c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_741:
	/* 0x741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_746:
	/* 0x746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_748:
	/* 0x748: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_74c:
	/* 0x74c: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_750:
	/* 0x750: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_764:
	/* 0x764: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_768:
	/* 0x768: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_76c:
	/* 0x76c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_76f:
	/* 0x76f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_774:
	/* 0x774: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_779:
	/* 0x779: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77e:
	/* 0x77e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_780:
	/* 0x780: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_783:
	/* 0x783: mov    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_787:
	/* 0x787: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78c:
	/* 0x78c: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_790:
	/* 0x790: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_793:
	/* 0x793: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_798:
	/* 0x798: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_79d:
	/* 0x79d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a2:
	/* 0x7a2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ab:
	/* 0x7ab: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7ae:
	/* 0x7ae: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b8:
	/* 0x7b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7bd:
	/* 0x7bd: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7c0:
	/* 0x7c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c2:
	/* 0x7c2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c5:
	/* 0x7c5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7c9:
	/* 0x7c9: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7cd:
	/* 0x7cd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7d1:
	/* 0x7d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7d4:
	/* 0x7d4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7d9:
	/* 0x7d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7de:
	/* 0x7de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7e3:
	/* 0x7e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e5:
	/* 0x7e5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e8:
	/* 0x7e8: mov    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7ec:
	/* 0x7ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7ef:
	/* 0x7ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f4:
	/* 0x7f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f9:
	/* 0x7f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fe:
	/* 0x7fe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_801:
	/* 0x801: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_803:
	/* 0x803: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_807:
	/* 0x807: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_80b:
	/* 0x80b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x81f: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_823:
	/* 0x823: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_826:
	/* 0x826: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_82b:
	/* 0x82b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_830:
	/* 0x830: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_835:
	/* 0x835: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_838:
	/* 0x838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83a:
	/* 0x83a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83d:
	/* 0x83d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_841:
	/* 0x841: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_845:
	/* 0x845: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_849:
	/* 0x849: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_84c:
	/* 0x84c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_851:
	/* 0x851: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_856:
	/* 0x856: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_85b:
	/* 0x85b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85d:
	/* 0x85d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_860:
	/* 0x860: mov    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_864:
	/* 0x864: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_867:
	/* 0x867: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_86c:
	/* 0x86c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_871:
	/* 0x871: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_876:
	/* 0x876: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_879:
	/* 0x879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87b:
	/* 0x87b: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87f:
	/* 0x87f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_882:
	/* 0x882: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_887:
	/* 0x887: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_88c:
	/* 0x88c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_891:
	/* 0x891: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
	return 2196ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2196ULL: goto x86_l_894;
	case 2198ULL: goto x86_l_896;
	case 2201ULL: goto x86_l_899;
	case 2205ULL: goto x86_l_89d;
	case 2209ULL: goto x86_l_8a1;
	case 2213ULL: goto x86_l_8a5;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2233ULL: goto x86_l_8b9;
	case 2237ULL: goto x86_l_8bd;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2259ULL: goto x86_l_8d3;
	case 2261ULL: goto x86_l_8d5;
	case 2265ULL: goto x86_l_8d9;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2292ULL: goto x86_l_8f4;
	case 2296ULL: goto x86_l_8f8;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2319ULL: goto x86_l_90f;
	case 2322ULL: goto x86_l_912;
	case 2326ULL: goto x86_l_916;
	case 2330ULL: goto x86_l_91a;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2354ULL: goto x86_l_932;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2365ULL: goto x86_l_93d;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2386ULL: goto x86_l_952;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2409ULL: goto x86_l_969;
	case 2411ULL: goto x86_l_96b;
	case 2415ULL: goto x86_l_96f;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2453ULL: goto x86_l_995;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2517ULL: goto x86_l_9d5;
	case 2519ULL: goto x86_l_9d7;
	case 2523ULL: goto x86_l_9db;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2545ULL: goto x86_l_9f1;
	case 2547ULL: goto x86_l_9f3;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2566ULL: goto x86_l_a06;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2581ULL: goto x86_l_a15;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2592ULL: goto x86_l_a20;
	case 2596ULL: goto x86_l_a24;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2624ULL: goto x86_l_a40;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2636ULL: goto x86_l_a4c;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2654ULL: goto x86_l_a5e;
	case 2656ULL: goto x86_l_a60;
	case 2660ULL: goto x86_l_a64;
	case 2664ULL: goto x86_l_a68;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2741ULL: goto x86_l_ab5;
	case 2745ULL: goto x86_l_ab9;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2783ULL: goto x86_l_adf;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2793ULL: goto x86_l_ae9;
	case 2797ULL: goto x86_l_aed;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2817ULL: goto x86_l_b01;
	case 2821ULL: goto x86_l_b05;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2844ULL: goto x86_l_b1c;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2869ULL: goto x86_l_b35;
	case 2871ULL: goto x86_l_b37;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2890ULL: goto x86_l_b4a;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2994ULL: goto x86_l_bb2;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3018ULL: goto x86_l_bca;
	case 3022ULL: goto x86_l_bce;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3031ULL: goto x86_l_bd7;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3057ULL: goto x86_l_bf1;
	case 3059ULL: goto x86_l_bf3;
	case 3063ULL: goto x86_l_bf7;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3079ULL: goto x86_l_c07;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3125ULL: goto x86_l_c35;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3140ULL: goto x86_l_c44;
	case 3151ULL: goto x86_l_c4f;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3170ULL: goto x86_l_c62;
	case 3175ULL: goto x86_l_c67;
	case 3180ULL: goto x86_l_c6c;
	case 3182ULL: goto x86_l_c6e;
	case 3185ULL: goto x86_l_c71;
	case 3187ULL: goto x86_l_c73;
	case 3190ULL: goto x86_l_c76;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3205ULL: goto x86_l_c85;
	case 3209ULL: goto x86_l_c89;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3226ULL: goto x86_l_c9a;
	case 3230ULL: goto x86_l_c9e;
	case 3234ULL: goto x86_l_ca2;
	case 3241ULL: goto x86_l_ca9;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3259ULL: goto x86_l_cbb;
	case 3263ULL: goto x86_l_cbf;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3281ULL: goto x86_l_cd1;
	case 3285ULL: goto x86_l_cd5;
	case 3292ULL: goto x86_l_cdc;
	case 3299ULL: goto x86_l_ce3;
	case 3306ULL: goto x86_l_cea;
	case 3314ULL: goto x86_l_cf2;
	case 3322ULL: goto x86_l_cfa;
	case 3324ULL: goto x86_l_cfc;
	case 3328ULL: goto x86_l_d00;
	case 3336ULL: goto x86_l_d08;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3347ULL: goto x86_l_d13;
	case 3349ULL: goto x86_l_d15;
	case 3356ULL: goto x86_l_d1c;
	case 3364ULL: goto x86_l_d24;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3399ULL: goto x86_l_d47;
	case 3406ULL: goto x86_l_d4e;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3446ULL: goto x86_l_d76;
	case 3454ULL: goto x86_l_d7e;
	case 3456ULL: goto x86_l_d80;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3472ULL: goto x86_l_d90;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3497ULL: goto x86_l_da9;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3510ULL: goto x86_l_db6;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3523ULL: goto x86_l_dc3;
	case 3531ULL: goto x86_l_dcb;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3558ULL: goto x86_l_de6;
	case 3561ULL: goto x86_l_de9;
	case 3568ULL: goto x86_l_df0;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3586ULL: goto x86_l_e02;
	case 3589ULL: goto x86_l_e05;
	case 3595ULL: goto x86_l_e0b;
	case 3601ULL: goto x86_l_e11;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3620ULL: goto x86_l_e24;
	case 3625ULL: goto x86_l_e29;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3642ULL: goto x86_l_e3a;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3666ULL: goto x86_l_e52;
	case 3670ULL: goto x86_l_e56;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3690ULL: goto x86_l_e6a;
	case 3693ULL: goto x86_l_e6d;
	case 3695ULL: goto x86_l_e6f;
	case 3698ULL: goto x86_l_e72;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3725ULL: goto x86_l_e8d;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3741ULL: goto x86_l_e9d;
	case 3743ULL: goto x86_l_e9f;
	case 3746ULL: goto x86_l_ea2;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3760ULL: goto x86_l_eb0;
	case 3764ULL: goto x86_l_eb4;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3806ULL: goto x86_l_ede;
	default: return 0xffffffffffffffffULL;
	}
x86_l_894:
	/* 0x894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_896:
	/* 0x896: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_899:
	/* 0x899: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_89d:
	/* 0x89d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8a1:
	/* 0x8a1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8a5:
	/* 0x8a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8a8:
	/* 0x8a8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8ad:
	/* 0x8ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b2:
	/* 0x8b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b7:
	/* 0x8b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b9:
	/* 0x8b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bd:
	/* 0x8bd: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8c1:
	/* 0x8c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x8d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d5:
	/* 0x8d5: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d9:
	/* 0x8d9: lea    rbx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8dd:
	/* 0x8dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8e0:
	/* 0x8e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8e5:
	/* 0x8e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ea:
	/* 0x8ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ef:
	/* 0x8ef: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8f2:
	/* 0x8f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f4:
	/* 0x8f4: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f8:
	/* 0x8f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8fb:
	/* 0x8fb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_900:
	/* 0x900: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_905:
	/* 0x905: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_90a:
	/* 0x90a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_90d:
	/* 0x90d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90f:
	/* 0x90f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_912:
	/* 0x912: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_916:
	/* 0x916: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_91a:
	/* 0x91a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_91e:
	/* 0x91e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_921:
	/* 0x921: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_926:
	/* 0x926: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92b:
	/* 0x92b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_930:
	/* 0x930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_932:
	/* 0x932: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_936:
	/* 0x936: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_93a:
	/* 0x93a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_93d:
	/* 0x93d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_942:
	/* 0x942: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_947:
	/* 0x947: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_94c:
	/* 0x94c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94e:
	/* 0x94e: cmp    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_952:
	/* 0x952: jne    9b0 <trace_ret_do_init_module+0x9b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b0;
	}
x86_l_954:
	/* 0x954: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_957:
	/* 0x957: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_95c:
	/* 0x95c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_961:
	/* 0x961: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_966:
	/* 0x966: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_969:
	/* 0x969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96b:
	/* 0x96b: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96f:
	/* 0x96f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_972:
	/* 0x972: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_977:
	/* 0x977: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_97c:
	/* 0x97c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_981:
	/* 0x981: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_984:
	/* 0x984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_986:
	/* 0x986: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_989:
	/* 0x989: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_98d:
	/* 0x98d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_991:
	/* 0x991: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_995:
	/* 0x995: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_998:
	/* 0x998: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_99d:
	/* 0x99d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a2:
	/* 0x9a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9a7:
	/* 0x9a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ac:
	/* 0x9ac: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b0:
	/* 0x9b0: mov    DWORD PTR [r15+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b4:
	/* 0x9b4: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9b9:
	/* 0x9b9: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9c0:
	/* 0x9c0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9cd:
	/* 0x9cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d2:
	/* 0x9d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9d5:
	/* 0x9d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d7:
	/* 0x9d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9db:
	/* 0x9db: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9df:
	/* 0x9df: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e7:
	/* 0x9e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ec:
	/* 0x9ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f1:
	/* 0x9f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f3:
	/* 0x9f3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f7:
	/* 0x9f7: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9fc:
	/* 0x9fc: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a01:
	/* 0xa01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a06:
	/* 0xa06: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0a:
	/* 0xa0a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a15:
	/* 0xa15: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a19:
	/* 0xa19: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a1e:
	/* 0xa1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a20:
	/* 0xa20: mov    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a24:
	/* 0xa24: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a28:
	/* 0xa28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a2b:
	/* 0xa2b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a35:
	/* 0xa35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3a:
	/* 0xa3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3c:
	/* 0xa3c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a40:
	/* 0xa40: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a43:
	/* 0xa43: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a48:
	/* 0xa48: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a4c:
	/* 0xa4c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a4f:
	/* 0xa4f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a54:
	/* 0xa54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a59:
	/* 0xa59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a5e:
	/* 0xa5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a60:
	/* 0xa60: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [r15+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a68:
	/* 0xa68: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a6c:
	/* 0xa6c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a6f:
	/* 0xa6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a74:
	/* 0xa74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a79:
	/* 0xa79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a7e:
	/* 0xa7e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a81:
	/* 0xa81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a83:
	/* 0xa83: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a87:
	/* 0xa87: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a8b:
	/* 0xa8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a8e:
	/* 0xa8e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a93:
	/* 0xa93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a98:
	/* 0xa98: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a9d:
	/* 0xa9d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_aa0:
	/* 0xaa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa2:
	/* 0xaa2: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_aa6:
	/* 0xaa6: je     aad <trace_ret_do_init_module+0xaad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aad;
	}
x86_l_aa8:
	/* 0xaa8: or     BYTE PTR [r15+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_aad:
	/* 0xaad: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_ab5:
	/* 0xab5: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ab9:
	/* 0xab9: mov    QWORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_ac1:
	/* 0xac1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ac6:
	/* 0xac6: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_acb:
	/* 0xacb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ad0:
	/* 0xad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad2:
	/* 0xad2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ad5:
	/* 0xad5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ada:
	/* 0xada: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_adf:
	/* 0xadf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae4:
	/* 0xae4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ae7:
	/* 0xae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae9:
	/* 0xae9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aed:
	/* 0xaed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_af0:
	/* 0xaf0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af5:
	/* 0xaf5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afa:
	/* 0xafa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aff:
	/* 0xaff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b01:
	/* 0xb01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b05:
	/* 0xb05: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_b08:
	/* 0xb08: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_b0d:
	/* 0xb0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b12:
	/* 0xb12: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b15:
	/* 0xb15: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b1a:
	/* 0xb1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1c:
	/* 0xb1c: add    r15,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b20:
	/* 0xb20: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_b2d:
	/* 0xb2d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b32:
	/* 0xb32: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b35:
	/* 0xb35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b37:
	/* 0xb37: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b3f:
	/* 0xb3f: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b44:
	/* 0xb44: je     353 <trace_ret_do_init_module+0x353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 851ULL;
	}
x86_l_b4a:
	/* 0xb4a: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_b52:
	/* 0xb52: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b57:
	/* 0xb57: add    rdx,QWORD PTR [rbx+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b5e:
	/* 0xb5e: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b63:
	/* 0xb63: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b68:
	/* 0xb68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6d:
	/* 0xb6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b79:
	/* 0xb79: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b7e:
	/* 0xb7e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b83:
	/* 0xb83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b88:
	/* 0xb88: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b8d:
	/* 0xb8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b92:
	/* 0xb92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b94:
	/* 0xb94: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b99:
	/* 0xb99: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b9c:
	/* 0xb9c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba1:
	/* 0xba1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba6:
	/* 0xba6: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bab:
	/* 0xbab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb0:
	/* 0xbb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb2:
	/* 0xbb2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb6:
	/* 0xbb6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bb9:
	/* 0xbb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bbe:
	/* 0xbbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc3:
	/* 0xbc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc8:
	/* 0xbc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bca:
	/* 0xbca: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bce:
	/* 0xbce: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bd1:
	/* 0xbd1: je     bf1 <trace_ret_do_init_module+0xbf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf1;
	}
x86_l_bd3:
	/* 0xbd3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bd7:
	/* 0xbd7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0xbeb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bef:
	/* 0xbef: jmp    bf3 <trace_ret_do_init_module+0xbf3> */
	goto x86_l_bf3;
x86_l_bf1:
	/* 0xbf1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf3:
	/* 0xbf3: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf7:
	/* 0xbf7: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bff:
	/* 0xbff: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c03:
	/* 0xc03: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c07:
	/* 0xc07: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c0e:
	/* 0xc0e: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c18:
	/* 0xc18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1a:
	/* 0xc1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1d:
	/* 0xc1d: je     c35 <trace_ret_do_init_module+0xc35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c35;
	}
x86_l_c1f:
	/* 0xc1f: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c22:
	/* 0xc22: mov    BYTE PTR [r15+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c29:
	/* 0xc29: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c2c:
	/* 0xc2c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c2f:
	/* 0xc2f: jne    c35 <trace_ret_do_init_module+0xc35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c35;
	}
x86_l_c31:
	/* 0xc31: or     BYTE PTR [rbx+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c35:
	/* 0xc35: movzx  eax,WORD PTR [rbx+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c39:
	/* 0xc39: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c3e:
	/* 0xc3e: jne    2532 <trace_ret_do_init_module+0x2532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9522ULL;
	}
x86_l_c44:
	/* 0xc44: mov    QWORD PTR [rbx+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c4f:
	/* 0xc4f: mov    DWORD PTR [rsp],0x310 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_c56:
	/* 0xc56: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c5b:
	/* 0xc5b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c62:
	/* 0xc62: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c67:
	/* 0xc67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c6c:
	/* 0xc6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6e:
	/* 0xc6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c71:
	/* 0xc71: je     cdc <trace_ret_do_init_module+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cdc;
	}
x86_l_c73:
	/* 0xc73: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c76:
	/* 0xc76: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c79:
	/* 0xc79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c7e:
	/* 0xc7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c80:
	/* 0xc80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: je     cdc <trace_ret_do_init_module+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cdc;
	}
x86_l_c85:
	/* 0xc85: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c89:
	/* 0xc89: mov    QWORD PTR [rbx+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c90:
	/* 0xc90: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c93:
	/* 0xc93: mov    QWORD PTR [rbx+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c9a:
	/* 0xc9a: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9e:
	/* 0xc9e: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rbx+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_ca9:
	/* 0xca9: mov    QWORD PTR [rbx+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_cb0:
	/* 0xcb0: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb4:
	/* 0xcb4: mov    QWORD PTR [rbx+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_cbb:
	/* 0xcbb: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cbf:
	/* 0xcbf: mov    QWORD PTR [rbx+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_cc6:
	/* 0xcc6: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [rbx+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_cd1:
	/* 0xcd1: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cd5:
	/* 0xcd5: mov    QWORD PTR [rbx+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_cdc:
	/* 0xcdc: mov    rax,QWORD PTR [rbx+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_ce3:
	/* 0xce3: mov    QWORD PTR [rbx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cea:
	/* 0xcea: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_cf2:
	/* 0xcf2: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_cfa:
	/* 0xcfa: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfc:
	/* 0xcfc: lea    rcx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d00:
	/* 0xd00: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d08:
	/* 0xd08: cmp    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_d0c:
	/* 0xd0c: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d11:
	/* 0xd11: jne    d2f <trace_ret_do_init_module+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d2f;
	}
x86_l_d13:
	/* 0xd13: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d15:
	/* 0xd15: and    QWORD PTR [r15+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_d1c:
	/* 0xd1c: mov    rbx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_d24:
	/* 0xd24: jne    14c8 <trace_ret_do_init_module+0x14c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5320ULL;
	}
x86_l_d2a:
	/* 0xd2a: jmp    14e2 <trace_ret_do_init_module+0x14e2> */
	return 5346ULL;
x86_l_d2f:
	/* 0xd2f: mov    rax,QWORD PTR [r15+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d36:
	/* 0xd36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d39:
	/* 0xd39: je     ee3 <trace_ret_do_init_module+0xee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3811ULL;
	}
x86_l_d3f:
	/* 0xd3f: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d47:
	/* 0xd47: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d4e:
	/* 0xd4e: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d51:
	/* 0xd51: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d53:
	/* 0xd53: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d56:
	/* 0xd56: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_d5a:
	/* 0xd5a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d5d:
	/* 0xd5d: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d60:
	/* 0xd60: xor    rbp,QWORD PTR [r15+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d67:
	/* 0xd67: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d6a:
	/* 0xd6a: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d71:
	/* 0xd71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d74:
	/* 0xd74: je     d9d <trace_ret_do_init_module+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9d;
	}
x86_l_d76:
	/* 0xd76: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d7e:
	/* 0xd7e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d80:
	/* 0xd80: cmp    BYTE PTR [rcx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d87:
	/* 0xd87: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_d8a:
	/* 0xd8a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d8d:
	/* 0xd8d: neg    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d90:
	/* 0xd90: xor    rdx,QWORD PTR [r15+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d97:
	/* 0xd97: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d9a:
	/* 0xd9a: and    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d9d:
	/* 0xd9d: mov    rax,QWORD PTR [r15+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_da4:
	/* 0xda4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da7:
	/* 0xda7: je     dc3 <trace_ret_do_init_module+0xdc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc3;
	}
x86_l_da9:
	/* 0xda9: mov    ecx,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_dad:
	/* 0xdad: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_db0:
	/* 0xdb0: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_db3:
	/* 0xdb3: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_db6:
	/* 0xdb6: xor    rcx,QWORD PTR [r15+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_dbd:
	/* 0xdbd: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dc0:
	/* 0xdc0: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dc3:
	/* 0xdc3: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_dcb:
	/* 0xdcb: mov    rax,QWORD PTR [r15+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_dd2:
	/* 0xdd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd5:
	/* 0xdd5: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ddd:
	/* 0xddd: je     df6 <trace_ret_do_init_module+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df6;
	}
x86_l_ddf:
	/* 0xddf: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_de2:
	/* 0xde2: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_de6:
	/* 0xde6: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_de9:
	/* 0xde9: xor    rcx,QWORD PTR [r15+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_df0:
	/* 0xdf0: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_df3:
	/* 0xdf3: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_df6:
	/* 0xdf6: movzx  r13d,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_dfb:
	/* 0xdfb: mov    rbx,QWORD PTR [r15+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_e02:
	/* 0xe02: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e05:
	/* 0xe05: mov    WORD PTR [rsp+0x50],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e0b:
	/* 0xe0b: je     f49 <trace_ret_do_init_module+0xf49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3913ULL;
	}
x86_l_e11:
	/* 0xe11: mov    rax,QWORD PTR [r15+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e18:
	/* 0xe18: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e1d:
	/* 0xe1d: mov    rax,QWORD PTR [r15+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e24:
	/* 0xe24: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e29:
	/* 0xe29: mov    rax,QWORD PTR [r15+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e30:
	/* 0xe30: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e35:
	/* 0xe35: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3a:
	/* 0xe3a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e41:
	/* 0xe41: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e44:
	/* 0xe44: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e49:
	/* 0xe49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4b:
	/* 0xe4b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e52:
	/* 0xe52: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e56:
	/* 0xe56: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e5d:
	/* 0xe5d: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_e60:
	/* 0xe60: je     e80 <trace_ret_do_init_module+0xe80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e80;
	}
x86_l_e62:
	/* 0xe62: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e65:
	/* 0xe65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e6a:
	/* 0xe6a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e6d:
	/* 0xe6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6f:
	/* 0xe6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e72:
	/* 0xe72: je     e80 <trace_ret_do_init_module+0xe80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e80;
	}
x86_l_e74:
	/* 0xe74: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e77:
	/* 0xe77: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7b:
	/* 0xe7b: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e7e:
	/* 0xe7e: jmp    e83 <trace_ret_do_init_module+0xe83> */
	goto x86_l_e83;
x86_l_e80:
	/* 0xe80: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e83:
	/* 0xe83: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e88:
	/* 0xe88: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e8d:
	/* 0xe8d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e91:
	/* 0xe91: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e94:
	/* 0xe94: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e97:
	/* 0xe97: jb     eac <trace_ret_do_init_module+0xeac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_eac;
	}
x86_l_e99:
	/* 0xe99: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e9d:
	/* 0xe9d: je     ea4 <trace_ret_do_init_module+0xea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea4;
	}
x86_l_e9f:
	/* 0xe9f: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ea2:
	/* 0xea2: jbe    eac <trace_ret_do_init_module+0xeac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_eac;
	}
x86_l_ea4:
	/* 0xea4: and    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_ea9:
	/* 0xea9: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_eac:
	/* 0xeac: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eb0:
	/* 0xeb0: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb4:
	/* 0xeb4: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ebb:
	/* 0xebb: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: je     eff <trace_ret_do_init_module+0xeff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3839ULL;
	}
x86_l_ec0:
	/* 0xec0: mov    QWORD PTR [rsp+0x60],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ec5:
	/* 0xec5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ec8:
	/* 0xec8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ecd:
	/* 0xecd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ed0:
	/* 0xed0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed2:
	/* 0xed2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed5:
	/* 0xed5: je     f0f <trace_ret_do_init_module+0xf0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3855ULL;
	}
x86_l_ed7:
	/* 0xed7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eda:
	/* 0xeda: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ede:
	/* 0xede: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
	return 3809ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3818ULL: goto x86_l_eea;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3844ULL: goto x86_l_f04;
	case 3848ULL: goto x86_l_f08;
	case 3851ULL: goto x86_l_f0b;
	case 3853ULL: goto x86_l_f0d;
	case 3855ULL: goto x86_l_f0f;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3879ULL: goto x86_l_f27;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3913ULL: goto x86_l_f49;
	case 3921ULL: goto x86_l_f51;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3934ULL: goto x86_l_f5e;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3960ULL: goto x86_l_f78;
	case 3967ULL: goto x86_l_f7f;
	case 3974ULL: goto x86_l_f86;
	case 3978ULL: goto x86_l_f8a;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4006ULL: goto x86_l_fa6;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4033ULL: goto x86_l_fc1;
	case 4036ULL: goto x86_l_fc4;
	case 4040ULL: goto x86_l_fc8;
	case 4043ULL: goto x86_l_fcb;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4050ULL: goto x86_l_fd2;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4060ULL: goto x86_l_fdc;
	case 4062ULL: goto x86_l_fde;
	case 4068ULL: goto x86_l_fe4;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4080ULL: goto x86_l_ff0;
	case 4082ULL: goto x86_l_ff2;
	case 4085ULL: goto x86_l_ff5;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4098ULL: goto x86_l_1002;
	case 4101ULL: goto x86_l_1005;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4173ULL: goto x86_l_104d;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4213ULL: goto x86_l_1075;
	case 4220ULL: goto x86_l_107c;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4239ULL: goto x86_l_108f;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4259ULL: goto x86_l_10a3;
	case 4262ULL: goto x86_l_10a6;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4278ULL: goto x86_l_10b6;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4293ULL: goto x86_l_10c5;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4300ULL: goto x86_l_10cc;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4323ULL: goto x86_l_10e3;
	case 4330ULL: goto x86_l_10ea;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4379ULL: goto x86_l_111b;
	case 4381ULL: goto x86_l_111d;
	case 4384ULL: goto x86_l_1120;
	case 4388ULL: goto x86_l_1124;
	case 4392ULL: goto x86_l_1128;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4414ULL: goto x86_l_113e;
	case 4416ULL: goto x86_l_1140;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4444ULL: goto x86_l_115c;
	case 4447ULL: goto x86_l_115f;
	case 4451ULL: goto x86_l_1163;
	case 4458ULL: goto x86_l_116a;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4477ULL: goto x86_l_117d;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4490ULL: goto x86_l_118a;
	case 4497ULL: goto x86_l_1191;
	case 4500ULL: goto x86_l_1194;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4509ULL: goto x86_l_119d;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4519ULL: goto x86_l_11a7;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4533ULL: goto x86_l_11b5;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4621ULL: goto x86_l_120d;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4671ULL: goto x86_l_123f;
	case 4678ULL: goto x86_l_1246;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4708ULL: goto x86_l_1264;
	case 4710ULL: goto x86_l_1266;
	case 4717ULL: goto x86_l_126d;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4735ULL: goto x86_l_127f;
	case 4738ULL: goto x86_l_1282;
	case 4740ULL: goto x86_l_1284;
	case 4743ULL: goto x86_l_1287;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4752ULL: goto x86_l_1290;
	case 4754ULL: goto x86_l_1292;
	case 4757ULL: goto x86_l_1295;
	case 4760ULL: goto x86_l_1298;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4780ULL: goto x86_l_12ac;
	case 4786ULL: goto x86_l_12b2;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4810ULL: goto x86_l_12ca;
	case 4817ULL: goto x86_l_12d1;
	case 4824ULL: goto x86_l_12d8;
	case 4829ULL: goto x86_l_12dd;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4874ULL: goto x86_l_130a;
	case 4877ULL: goto x86_l_130d;
	case 4879ULL: goto x86_l_130f;
	case 4882ULL: goto x86_l_1312;
	case 4886ULL: goto x86_l_1316;
	case 4889ULL: goto x86_l_1319;
	case 4891ULL: goto x86_l_131b;
	case 4893ULL: goto x86_l_131d;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4902ULL: goto x86_l_1326;
	case 4905ULL: goto x86_l_1329;
	case 4911ULL: goto x86_l_132f;
	case 4918ULL: goto x86_l_1336;
	case 4921ULL: goto x86_l_1339;
	case 4923ULL: goto x86_l_133b;
	case 4927ULL: goto x86_l_133f;
	case 4930ULL: goto x86_l_1342;
	case 4937ULL: goto x86_l_1349;
	case 4943ULL: goto x86_l_134f;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4965ULL: goto x86_l_1365;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4993ULL: goto x86_l_1381;
	case 4995ULL: goto x86_l_1383;
	case 4998ULL: goto x86_l_1386;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5021ULL: goto x86_l_139d;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5060ULL: goto x86_l_13c4;
	case 5063ULL: goto x86_l_13c7;
	case 5065ULL: goto x86_l_13c9;
	case 5072ULL: goto x86_l_13d0;
	case 5075ULL: goto x86_l_13d3;
	case 5077ULL: goto x86_l_13d5;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5120ULL: goto x86_l_1400;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5142ULL: goto x86_l_1416;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5174ULL: goto x86_l_1436;
	case 5181ULL: goto x86_l_143d;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5197ULL: goto x86_l_144d;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5216ULL: goto x86_l_1460;
	case 5224ULL: goto x86_l_1468;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5250ULL: goto x86_l_1482;
	case 5253ULL: goto x86_l_1485;
	case 5255ULL: goto x86_l_1487;
	case 5257ULL: goto x86_l_1489;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5269ULL: goto x86_l_1495;
	case 5277ULL: goto x86_l_149d;
	case 5284ULL: goto x86_l_14a4;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5310ULL: goto x86_l_14be;
	case 5318ULL: goto x86_l_14c6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ee1:
	/* 0xee1: jmp    f11 <trace_ret_do_init_module+0xf11> */
	goto x86_l_f11;
x86_l_ee3:
	/* 0xee3: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eea:
	/* 0xeea: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ef1:
	/* 0xef1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef4:
	/* 0xef4: jne    d76 <trace_ret_do_init_module+0xd76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3446ULL;
	}
x86_l_efa:
	/* 0xefa: jmp    d9d <trace_ret_do_init_module+0xd9d> */
	return 3485ULL;
x86_l_eff:
	/* 0xeff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f01:
	/* 0xf01: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f04:
	/* 0xf04: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f08:
	/* 0xf08: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f0b:
	/* 0xf0b: jae    f27 <trace_ret_do_init_module+0xf27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f27;
	}
x86_l_f0d:
	/* 0xf0d: jmp    f3a <trace_ret_do_init_module+0xf3a> */
	goto x86_l_f3a;
x86_l_f0f:
	/* 0xf0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f11:
	/* 0xf11: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f16:
	/* 0xf16: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f1b:
	/* 0xf1b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f1e:
	/* 0xf1e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f22:
	/* 0xf22: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: jb     f3a <trace_ret_do_init_module+0xf3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f3a;
	}
x86_l_f27:
	/* 0xf27: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f2b:
	/* 0xf2b: je     f32 <trace_ret_do_init_module+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f32;
	}
x86_l_f2d:
	/* 0xf2d: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f30:
	/* 0xf30: jbe    f3a <trace_ret_do_init_module+0xf3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f3a;
	}
x86_l_f32:
	/* 0xf32: and    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_f37:
	/* 0xf37: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_f3a:
	/* 0xf3a: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f3d:
	/* 0xf3d: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f40:
	/* 0xf40: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f43:
	/* 0xf43: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_f49:
	/* 0xf49: cmp    QWORD PTR [r15+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f51:
	/* 0xf51: je     1005 <trace_ret_do_init_module+0x1005> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1005;
	}
x86_l_f57:
	/* 0xf57: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f5c:
	/* 0xf5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5e:
	/* 0xf5e: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f62:
	/* 0xf62: mov    rbx,QWORD PTR [r15+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_f69:
	/* 0xf69: mov    rax,QWORD PTR [r15+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f70:
	/* 0xf70: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f75:
	/* 0xf75: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_f78:
	/* 0xf78: mov    r13,QWORD PTR [r15+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f7f:
	/* 0xf7f: mov    r12,QWORD PTR [r15+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f86:
	/* 0xf86: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8a:
	/* 0xf8a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f91:
	/* 0xf91: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f94:
	/* 0xf94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f99:
	/* 0xf99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9b:
	/* 0xf9b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f9e:
	/* 0xf9e: mov    eax,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fa2:
	/* 0xfa2: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa6:
	/* 0xfa6: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fad:
	/* 0xfad: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: je     fcd <trace_ret_do_init_module+0xfcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fcd;
	}
x86_l_fb2:
	/* 0xfb2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fb5:
	/* 0xfb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fba:
	/* 0xfba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbc:
	/* 0xfbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: je     fcd <trace_ret_do_init_module+0xfcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fcd;
	}
x86_l_fc1:
	/* 0xfc1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc4:
	/* 0xfc4: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc8:
	/* 0xfc8: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fcb:
	/* 0xfcb: jmp    fcf <trace_ret_do_init_module+0xfcf> */
	goto x86_l_fcf;
x86_l_fcd:
	/* 0xfcd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fcf:
	/* 0xfcf: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fd2:
	/* 0xfd2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd6:
	/* 0xfd6: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_fd9:
	/* 0xfd9: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_fdc:
	/* 0xfdc: jae    fe6 <trace_ret_do_init_module+0xfe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_fe6;
	}
x86_l_fde:
	/* 0xfde: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_fe4:
	/* 0xfe4: jmp    fff <trace_ret_do_init_module+0xfff> */
	goto x86_l_fff;
x86_l_fe6:
	/* 0xfe6: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fea:
	/* 0xfea: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_ff0:
	/* 0xff0: je     ff7 <trace_ret_do_init_module+0xff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ff7;
	}
x86_l_ff2:
	/* 0xff2: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_ff5:
	/* 0xff5: jbe    fff <trace_ret_do_init_module+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fff;
	}
x86_l_ff7:
	/* 0xff7: and    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 96ULL);
x86_l_ffc:
	/* 0xffc: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_fff:
	/* 0xfff: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1002:
	/* 0x1002: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1005:
	/* 0x1005: cmp    QWORD PTR [r15+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_100d:
	/* 0x100d: je     10d5 <trace_ret_do_init_module+0x10d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d5;
	}
x86_l_1013:
	/* 0x1013: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1018:
	/* 0x1018: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_101f:
	/* 0x101f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1022:
	/* 0x1022: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1027:
	/* 0x1027: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_102c:
	/* 0x102c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1031:
	/* 0x1031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1033:
	/* 0x1033: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1037:
	/* 0x1037: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_103b:
	/* 0x103b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_103e:
	/* 0x103e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1043:
	/* 0x1043: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1048:
	/* 0x1048: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_104d:
	/* 0x104d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104f:
	/* 0x104f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1053:
	/* 0x1053: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1058:
	/* 0x1058: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_105d:
	/* 0x105d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1062:
	/* 0x1062: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1066:
	/* 0x1066: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_106b:
	/* 0x106b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106d:
	/* 0x106d: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1071:
	/* 0x1071: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1075:
	/* 0x1075: mov    rbx,QWORD PTR [r15+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_107c:
	/* 0x107c: mov    r14,QWORD PTR [r15+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1083:
	/* 0x1083: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1088:
	/* 0x1088: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_108f:
	/* 0x108f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1092:
	/* 0x1092: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1097:
	/* 0x1097: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_109a:
	/* 0x109a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109c:
	/* 0x109c: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10a3:
	/* 0x10a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a6:
	/* 0x10a6: je     10c7 <trace_ret_do_init_module+0x10c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c7;
	}
x86_l_10a8:
	/* 0x10a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ab:
	/* 0x10ab: lea    rsi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10af:
	/* 0x10af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b4:
	/* 0x10b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b6:
	/* 0x10b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b9:
	/* 0x10b9: je     10c7 <trace_ret_do_init_module+0x10c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c7;
	}
x86_l_10bb:
	/* 0x10bb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10be:
	/* 0x10be: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c2:
	/* 0x10c2: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10c5:
	/* 0x10c5: jmp    10c9 <trace_ret_do_init_module+0x10c9> */
	goto x86_l_10c9;
x86_l_10c7:
	/* 0x10c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c9:
	/* 0x10c9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10cc:
	/* 0x10cc: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_10cf:
	/* 0x10cf: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10d2:
	/* 0x10d2: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_10d5:
	/* 0x10d5: cmp    QWORD PTR [r15+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_10dd:
	/* 0x10dd: je     11c3 <trace_ret_do_init_module+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11c3;
	}
x86_l_10e3:
	/* 0x10e3: mov    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_10ea:
	/* 0x10ea: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10ee:
	/* 0x10ee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10f6:
	/* 0x10f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10fb:
	/* 0x10fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1100:
	/* 0x1100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1102:
	/* 0x1102: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1106:
	/* 0x1106: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1109:
	/* 0x1109: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_110e:
	/* 0x110e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1113:
	/* 0x1113: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1118:
	/* 0x1118: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_111b:
	/* 0x111b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111d:
	/* 0x111d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1120:
	/* 0x1120: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1124:
	/* 0x1124: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1128:
	/* 0x1128: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_112c:
	/* 0x112c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1134:
	/* 0x1134: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1139:
	/* 0x1139: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_113e:
	/* 0x113e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1140:
	/* 0x1140: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1144:
	/* 0x1144: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1148:
	/* 0x1148: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_114b:
	/* 0x114b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1150:
	/* 0x1150: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1155:
	/* 0x1155: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_115a:
	/* 0x115a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115c:
	/* 0x115c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115f:
	/* 0x115f: mov    DWORD PTR [r15+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1163:
	/* 0x1163: mov    rbx,QWORD PTR [r15+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_116a:
	/* 0x116a: mov    r14,QWORD PTR [r15+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1171:
	/* 0x1171: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1176:
	/* 0x1176: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_117d:
	/* 0x117d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1180:
	/* 0x1180: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1185:
	/* 0x1185: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1188:
	/* 0x1188: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118a:
	/* 0x118a: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1191:
	/* 0x1191: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1194:
	/* 0x1194: je     11b5 <trace_ret_do_init_module+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b5;
	}
x86_l_1196:
	/* 0x1196: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1199:
	/* 0x1199: lea    rsi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_119d:
	/* 0x119d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a2:
	/* 0x11a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a4:
	/* 0x11a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a7:
	/* 0x11a7: je     11b5 <trace_ret_do_init_module+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b5;
	}
x86_l_11a9:
	/* 0x11a9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ac:
	/* 0x11ac: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b0:
	/* 0x11b0: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11b3:
	/* 0x11b3: jmp    11b7 <trace_ret_do_init_module+0x11b7> */
	goto x86_l_11b7;
x86_l_11b5:
	/* 0x11b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b7:
	/* 0x11b7: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ba:
	/* 0x11ba: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_11bd:
	/* 0x11bd: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11c0:
	/* 0x11c0: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_11c3:
	/* 0x11c3: cmp    QWORD PTR [r15+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11cb:
	/* 0x11cb: je     12a4 <trace_ret_do_init_module+0x12a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a4;
	}
x86_l_11d1:
	/* 0x11d1: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11d6:
	/* 0x11d6: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_11dd:
	/* 0x11dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11e0:
	/* 0x11e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11e5:
	/* 0x11e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ea:
	/* 0x11ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11ef:
	/* 0x11ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f1:
	/* 0x11f1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f5:
	/* 0x11f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11f8:
	/* 0x11f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11fd:
	/* 0x11fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1202:
	/* 0x1202: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1207:
	/* 0x1207: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1209:
	/* 0x1209: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120d:
	/* 0x120d: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_1210:
	/* 0x1210: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1215:
	/* 0x1215: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_121a:
	/* 0x121a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_121d:
	/* 0x121d: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1222:
	/* 0x1222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1224:
	/* 0x1224: lea    rbx,[r15+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1228:
	/* 0x1228: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_122d:
	/* 0x122d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1232:
	/* 0x1232: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1235:
	/* 0x1235: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_123a:
	/* 0x123a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_123d:
	/* 0x123d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123f:
	/* 0x123f: mov    r14,QWORD PTR [r15+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1246:
	/* 0x1246: mov    r12,QWORD PTR [r15+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_124d:
	/* 0x124d: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1252:
	/* 0x1252: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1259:
	/* 0x1259: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_125c:
	/* 0x125c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1261:
	/* 0x1261: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1264:
	/* 0x1264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1266:
	/* 0x1266: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_126d:
	/* 0x126d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1270:
	/* 0x1270: je     1290 <trace_ret_do_init_module+0x1290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1290;
	}
x86_l_1272:
	/* 0x1272: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1275:
	/* 0x1275: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127a:
	/* 0x127a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_127d:
	/* 0x127d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127f:
	/* 0x127f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1282:
	/* 0x1282: je     1290 <trace_ret_do_init_module+0x1290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1290;
	}
x86_l_1284:
	/* 0x1284: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1287:
	/* 0x1287: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128b:
	/* 0x128b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_128e:
	/* 0x128e: jmp    1292 <trace_ret_do_init_module+0x1292> */
	goto x86_l_1292;
x86_l_1290:
	/* 0x1290: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1292:
	/* 0x1292: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1295:
	/* 0x1295: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1298:
	/* 0x1298: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_129b:
	/* 0x129b: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_129e:
	/* 0x129e: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_12a4:
	/* 0x12a4: cmp    QWORD PTR [r15+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12ac:
	/* 0x12ac: je     132f <trace_ret_do_init_module+0x132f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132f;
	}
x86_l_12b2:
	/* 0x12b2: lea    rbx,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12b6:
	/* 0x12b6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12bb:
	/* 0x12bb: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12c0:
	/* 0x12c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c3:
	/* 0x12c3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12c8:
	/* 0x12c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ca:
	/* 0x12ca: mov    r14,QWORD PTR [r15+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12d1:
	/* 0x12d1: mov    r12,QWORD PTR [r15+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12d8:
	/* 0x12d8: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12dd:
	/* 0x12dd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12e4:
	/* 0x12e4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ec:
	/* 0x12ec: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12ef:
	/* 0x12ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f1:
	/* 0x12f1: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12f8:
	/* 0x12f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: je     131b <trace_ret_do_init_module+0x131b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131b;
	}
x86_l_12fd:
	/* 0x12fd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1305:
	/* 0x1305: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1308:
	/* 0x1308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130a:
	/* 0x130a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_130d:
	/* 0x130d: je     131b <trace_ret_do_init_module+0x131b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131b;
	}
x86_l_130f:
	/* 0x130f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1312:
	/* 0x1312: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1316:
	/* 0x1316: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1319:
	/* 0x1319: jmp    131d <trace_ret_do_init_module+0x131d> */
	goto x86_l_131d;
x86_l_131b:
	/* 0x131b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131d:
	/* 0x131d: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1320:
	/* 0x1320: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1323:
	/* 0x1323: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1326:
	/* 0x1326: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1329:
	/* 0x1329: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_132f:
	/* 0x132f: mov    rbx,QWORD PTR [r15+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1336:
	/* 0x1336: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1339:
	/* 0x1339: je     139d <trace_ret_do_init_module+0x139d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139d;
	}
x86_l_133b:
	/* 0x133b: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_133f:
	/* 0x133f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1342:
	/* 0x1342: mov    r14,QWORD PTR [r15+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1349:
	/* 0x1349: mov    WORD PTR [rsp+0x48],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_134f:
	/* 0x134f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1356:
	/* 0x1356: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_135b:
	/* 0x135b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1360:
	/* 0x1360: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1363:
	/* 0x1363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1365:
	/* 0x1365: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_136c:
	/* 0x136c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_136f:
	/* 0x136f: je     138f <trace_ret_do_init_module+0x138f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_138f;
	}
x86_l_1371:
	/* 0x1371: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1377:
	/* 0x1377: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137c:
	/* 0x137c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137e:
	/* 0x137e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1381:
	/* 0x1381: je     138f <trace_ret_do_init_module+0x138f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_138f;
	}
x86_l_1383:
	/* 0x1383: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1386:
	/* 0x1386: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138a:
	/* 0x138a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_138d:
	/* 0x138d: jmp    1391 <trace_ret_do_init_module+0x1391> */
	goto x86_l_1391;
x86_l_138f:
	/* 0x138f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1391:
	/* 0x1391: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1394:
	/* 0x1394: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1397:
	/* 0x1397: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_139a:
	/* 0x139a: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_139d:
	/* 0x139d: mov    rbx,QWORD PTR [r15+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_13a4:
	/* 0x13a4: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13a7:
	/* 0x13a7: je     1406 <trace_ret_do_init_module+0x1406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1406;
	}
x86_l_13a9:
	/* 0x13a9: mov    r14,QWORD PTR [r15+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13b0:
	/* 0x13b0: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b5:
	/* 0x13b5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13bc:
	/* 0x13bc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13bf:
	/* 0x13bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c4:
	/* 0x13c4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13c7:
	/* 0x13c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c9:
	/* 0x13c9: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13d0:
	/* 0x13d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d3:
	/* 0x13d3: je     13f8 <trace_ret_do_init_module+0x13f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f8;
	}
x86_l_13d5:
	/* 0x13d5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13d8:
	/* 0x13d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13dd:
	/* 0x13dd: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_13e5:
	/* 0x13e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e7:
	/* 0x13e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: je     13f8 <trace_ret_do_init_module+0x13f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f8;
	}
x86_l_13ec:
	/* 0x13ec: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ef:
	/* 0x13ef: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f3:
	/* 0x13f3: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13f6:
	/* 0x13f6: jmp    13fa <trace_ret_do_init_module+0x13fa> */
	goto x86_l_13fa;
x86_l_13f8:
	/* 0x13f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13fa:
	/* 0x13fa: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13fd:
	/* 0x13fd: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1400:
	/* 0x1400: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1403:
	/* 0x1403: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1406:
	/* 0x1406: mov    r14,QWORD PTR [r15+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_140d:
	/* 0x140d: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: je     1495 <trace_ret_do_init_module+0x1495> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1495;
	}
x86_l_1416:
	/* 0x1416: mov    r12,QWORD PTR [r15+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_141d:
	/* 0x141d: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1422:
	/* 0x1422: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1429:
	/* 0x1429: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_142c:
	/* 0x142c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1431:
	/* 0x1431: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1434:
	/* 0x1434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1436:
	/* 0x1436: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_143d:
	/* 0x143d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1440:
	/* 0x1440: je     1487 <trace_ret_do_init_module+0x1487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1487;
	}
x86_l_1442:
	/* 0x1442: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1445:
	/* 0x1445: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_144d:
	/* 0x144d: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1451:
	/* 0x1451: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1456:
	/* 0x1456: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145e:
	/* 0x145e: jne    147b <trace_ret_do_init_module+0x147b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_147b;
	}
x86_l_1460:
	/* 0x1460: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1468:
	/* 0x1468: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_146c:
	/* 0x146c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1471:
	/* 0x1471: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1474:
	/* 0x1474: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1476:
	/* 0x1476: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1479:
	/* 0x1479: je     1487 <trace_ret_do_init_module+0x1487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1487;
	}
x86_l_147b:
	/* 0x147b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147e:
	/* 0x147e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1482:
	/* 0x1482: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1485:
	/* 0x1485: jmp    1489 <trace_ret_do_init_module+0x1489> */
	goto x86_l_1489;
x86_l_1487:
	/* 0x1487: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1489:
	/* 0x1489: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_148c:
	/* 0x148c: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_148f:
	/* 0x148f: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1492:
	/* 0x1492: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1495:
	/* 0x1495: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_149d:
	/* 0x149d: mov    rax,QWORD PTR [r15+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_14a4:
	/* 0x14a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a7:
	/* 0x14a7: je     14b0 <trace_ret_do_init_module+0x14b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b0;
	}
x86_l_14a9:
	/* 0x14a9: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14ad:
	/* 0x14ad: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14b0:
	/* 0x14b0: and    rbp,QWORD PTR [r15+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14b7:
	/* 0x14b7: and    QWORD PTR [r15+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_14be:
	/* 0x14be: mov    rbx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_14c6:
	/* 0x14c6: je     14e2 <trace_ret_do_init_module+0x14e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5346ULL;
	}
	return 5320ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5320ULL: goto x86_l_14c8;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5338ULL: goto x86_l_14da;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5378ULL: goto x86_l_1502;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5402ULL: goto x86_l_151a;
	case 5410ULL: goto x86_l_1522;
	case 5420ULL: goto x86_l_152c;
	case 5428ULL: goto x86_l_1534;
	case 5439ULL: goto x86_l_153f;
	case 5450ULL: goto x86_l_154a;
	case 5461ULL: goto x86_l_1555;
	case 5472ULL: goto x86_l_1560;
	case 5483ULL: goto x86_l_156b;
	case 5494ULL: goto x86_l_1576;
	case 5505ULL: goto x86_l_1581;
	case 5516ULL: goto x86_l_158c;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5575ULL: goto x86_l_15c7;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5594ULL: goto x86_l_15da;
	case 5598ULL: goto x86_l_15de;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5615ULL: goto x86_l_15ef;
	case 5622ULL: goto x86_l_15f6;
	case 5626ULL: goto x86_l_15fa;
	case 5633ULL: goto x86_l_1601;
	case 5637ULL: goto x86_l_1605;
	case 5644ULL: goto x86_l_160c;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5674ULL: goto x86_l_162a;
	case 5681ULL: goto x86_l_1631;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5714ULL: goto x86_l_1652;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5721ULL: goto x86_l_1659;
	case 5728ULL: goto x86_l_1660;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5746ULL: goto x86_l_1672;
	case 5749ULL: goto x86_l_1675;
	case 5755ULL: goto x86_l_167b;
	case 5763ULL: goto x86_l_1683;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5818ULL: goto x86_l_16ba;
	case 5820ULL: goto x86_l_16bc;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5833ULL: goto x86_l_16c9;
	case 5836ULL: goto x86_l_16cc;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5849ULL: goto x86_l_16d9;
	case 5856ULL: goto x86_l_16e0;
	case 5859ULL: goto x86_l_16e3;
	case 5861ULL: goto x86_l_16e5;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5871ULL: goto x86_l_16ef;
	case 5874ULL: goto x86_l_16f2;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5887ULL: goto x86_l_16ff;
	case 5895ULL: goto x86_l_1707;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5919ULL: goto x86_l_171f;
	case 5922ULL: goto x86_l_1722;
	case 5929ULL: goto x86_l_1729;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5968ULL: goto x86_l_1750;
	case 5976ULL: goto x86_l_1758;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6004ULL: goto x86_l_1774;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6021ULL: goto x86_l_1785;
	case 6024ULL: goto x86_l_1788;
	case 6028ULL: goto x86_l_178c;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6057ULL: goto x86_l_17a9;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6072ULL: goto x86_l_17b8;
	case 6074ULL: goto x86_l_17ba;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6118ULL: goto x86_l_17e6;
	case 6121ULL: goto x86_l_17e9;
	case 6125ULL: goto x86_l_17ed;
	case 6129ULL: goto x86_l_17f1;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6164ULL: goto x86_l_1814;
	case 6167ULL: goto x86_l_1817;
	case 6171ULL: goto x86_l_181b;
	case 6174ULL: goto x86_l_181e;
	case 6176ULL: goto x86_l_1820;
	case 6183ULL: goto x86_l_1827;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6230ULL: goto x86_l_1856;
	case 6232ULL: goto x86_l_1858;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6243ULL: goto x86_l_1863;
	case 6251ULL: goto x86_l_186b;
	case 6254ULL: goto x86_l_186e;
	case 6257ULL: goto x86_l_1871;
	case 6260ULL: goto x86_l_1874;
	case 6263ULL: goto x86_l_1877;
	case 6271ULL: goto x86_l_187f;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6284ULL: goto x86_l_188c;
	case 6288ULL: goto x86_l_1890;
	case 6295ULL: goto x86_l_1897;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6314ULL: goto x86_l_18aa;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6330ULL: goto x86_l_18ba;
	case 6337ULL: goto x86_l_18c1;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6347ULL: goto x86_l_18cb;
	case 6350ULL: goto x86_l_18ce;
	case 6354ULL: goto x86_l_18d2;
	case 6358ULL: goto x86_l_18d6;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6378ULL: goto x86_l_18ea;
	case 6380ULL: goto x86_l_18ec;
	case 6383ULL: goto x86_l_18ef;
	case 6385ULL: goto x86_l_18f1;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6397ULL: goto x86_l_18fd;
	case 6399ULL: goto x86_l_18ff;
	case 6402ULL: goto x86_l_1902;
	case 6406ULL: goto x86_l_1906;
	case 6409ULL: goto x86_l_1909;
	case 6412ULL: goto x86_l_190c;
	case 6414ULL: goto x86_l_190e;
	case 6420ULL: goto x86_l_1914;
	case 6422ULL: goto x86_l_1916;
	case 6428ULL: goto x86_l_191c;
	case 6430ULL: goto x86_l_191e;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6442ULL: goto x86_l_192a;
	case 6445ULL: goto x86_l_192d;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6565ULL: goto x86_l_19a5;
	case 6569ULL: goto x86_l_19a9;
	case 6573ULL: goto x86_l_19ad;
	case 6580ULL: goto x86_l_19b4;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6599ULL: goto x86_l_19c7;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6638ULL: goto x86_l_19ee;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6655ULL: goto x86_l_19ff;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6669ULL: goto x86_l_1a0d;
	case 6677ULL: goto x86_l_1a15;
	case 6683ULL: goto x86_l_1a1b;
	case 6690ULL: goto x86_l_1a22;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6748ULL: goto x86_l_1a5c;
	case 6752ULL: goto x86_l_1a60;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6774ULL: goto x86_l_1a76;
	case 6776ULL: goto x86_l_1a78;
	case 6780ULL: goto x86_l_1a7c;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6811ULL: goto x86_l_1a9b;
	case 6818ULL: goto x86_l_1aa2;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6845ULL: goto x86_l_1abd;
	case 6848ULL: goto x86_l_1ac0;
	case 6850ULL: goto x86_l_1ac2;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6862ULL: goto x86_l_1ace;
	case 6865ULL: goto x86_l_1ad1;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6876ULL: goto x86_l_1adc;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6901ULL: goto x86_l_1af5;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6915ULL: goto x86_l_1b03;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6953ULL: goto x86_l_1b29;
	case 6957ULL: goto x86_l_1b2d;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14c8:
	/* 0x14c8: mov    DWORD PTR [rsp],0x40000000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1073741824ULL);
x86_l_14cf:
	/* 0x14cf: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14da:
	/* 0x14da: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14dd:
	/* 0x14dd: call   0 <trace_ret_do_init_module> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5346ULL);
	__x86_sim_call_depth++;
	return 9593ULL;
x86_l_14e2:
	/* 0x14e2: lea    rdx,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14e6:
	/* 0x14e6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14e9:
	/* 0x14e9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14ee:
	/* 0x14ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14f3:
	/* 0x14f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f8:
	/* 0x14f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fa:
	/* 0x14fa: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fe:
	/* 0x14fe: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1502:
	/* 0x1502: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1505:
	/* 0x1505: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_150a:
	/* 0x150a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_150f:
	/* 0x150f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1514:
	/* 0x1514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1516:
	/* 0x1516: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151a:
	/* 0x151a: mov    DWORD PTR [r15+0x70],0x2fa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337914ULL);
x86_l_1522:
	/* 0x1522: mov    WORD PTR [r15+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_152c:
	/* 0x152c: mov    BYTE PTR [r15+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1534:
	/* 0x1534: mov    QWORD PTR [r15+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_153f:
	/* 0x153f: mov    QWORD PTR [r15+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_154a:
	/* 0x154a: mov    QWORD PTR [r15+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1555:
	/* 0x1555: mov    QWORD PTR [r15+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1560:
	/* 0x1560: mov    QWORD PTR [r15+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_156b:
	/* 0x156b: mov    QWORD PTR [r15+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1576:
	/* 0x1576: mov    QWORD PTR [r15+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1581:
	/* 0x1581: mov    QWORD PTR [r15+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_158c:
	/* 0x158c: mov    QWORD PTR [r15+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_1597:
	/* 0x1597: movzx  eax,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_159c:
	/* 0x159c: mov    DWORD PTR [rsp],0x2fa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 762ULL);
x86_l_15a3:
	/* 0x15a3: mov    WORD PTR [rsp+0x48],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15a8:
	/* 0x15a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_15af:
	/* 0x15af: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15b4:
	/* 0x15b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b9:
	/* 0x15b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bb:
	/* 0x15bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15be:
	/* 0x15be: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_15c4:
	/* 0x15c4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15c7:
	/* 0x15c7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_15ca:
	/* 0x15ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15cf:
	/* 0x15cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d1:
	/* 0x15d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d4:
	/* 0x15d4: je     2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9569ULL;
	}
x86_l_15da:
	/* 0x15da: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15de:
	/* 0x15de: mov    QWORD PTR [r15+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_15e5:
	/* 0x15e5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e8:
	/* 0x15e8: mov    QWORD PTR [r15+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_15ef:
	/* 0x15ef: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15f6:
	/* 0x15f6: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15fa:
	/* 0x15fa: mov    QWORD PTR [r15+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_1601:
	/* 0x1601: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1605:
	/* 0x1605: mov    QWORD PTR [r15+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_160c:
	/* 0x160c: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1610:
	/* 0x1610: mov    QWORD PTR [r15+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1617:
	/* 0x1617: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_161b:
	/* 0x161b: mov    QWORD PTR [r15+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1622:
	/* 0x1622: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1626:
	/* 0x1626: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162a:
	/* 0x162a: mov    QWORD PTR [r15+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1631:
	/* 0x1631: mov    QWORD PTR [r15+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1638:
	/* 0x1638: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_163d:
	/* 0x163d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163f:
	/* 0x163f: cmp    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1643:
	/* 0x1643: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_164b:
	/* 0x164b: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1650:
	/* 0x1650: jne    166b <trace_ret_do_init_module+0x166b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_166b;
	}
x86_l_1652:
	/* 0x1652: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1654:
	/* 0x1654: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1656:
	/* 0x1656: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1659:
	/* 0x1659: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1660:
	/* 0x1660: jne    1dff <trace_ret_do_init_module+0x1dff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7679ULL;
	}
x86_l_1666:
	/* 0x1666: jmp    2563 <trace_ret_do_init_module+0x2563> */
	return 9571ULL;
x86_l_166b:
	/* 0x166b: mov    rax,QWORD PTR [r15+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_1672:
	/* 0x1672: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1675:
	/* 0x1675: je     1820 <trace_ret_do_init_module+0x1820> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1820;
	}
x86_l_167b:
	/* 0x167b: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1683:
	/* 0x1683: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_168a:
	/* 0x168a: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_168d:
	/* 0x168d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168f:
	/* 0x168f: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1692:
	/* 0x1692: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1696:
	/* 0x1696: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1699:
	/* 0x1699: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_169c:
	/* 0x169c: xor    rbp,QWORD PTR [r15+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_16a3:
	/* 0x16a3: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16a6:
	/* 0x16a6: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_16ad:
	/* 0x16ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b0:
	/* 0x16b0: je     16d9 <trace_ret_do_init_module+0x16d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d9;
	}
x86_l_16b2:
	/* 0x16b2: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16ba:
	/* 0x16ba: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16bc:
	/* 0x16bc: cmp    BYTE PTR [rcx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_16c3:
	/* 0x16c3: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_16c6:
	/* 0x16c6: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16c9:
	/* 0x16c9: neg    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_16cc:
	/* 0x16cc: xor    rdx,QWORD PTR [r15+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_16d3:
	/* 0x16d3: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16d6:
	/* 0x16d6: and    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_16d9:
	/* 0x16d9: mov    rax,QWORD PTR [r15+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_16e0:
	/* 0x16e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e3:
	/* 0x16e3: je     16ff <trace_ret_do_init_module+0x16ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ff;
	}
x86_l_16e5:
	/* 0x16e5: mov    ecx,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_16e9:
	/* 0x16e9: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16ec:
	/* 0x16ec: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_16ef:
	/* 0x16ef: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_16f2:
	/* 0x16f2: xor    rcx,QWORD PTR [r15+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_16f9:
	/* 0x16f9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16fc:
	/* 0x16fc: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_16ff:
	/* 0x16ff: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1707:
	/* 0x1707: mov    rax,QWORD PTR [r15+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_170e:
	/* 0x170e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1711:
	/* 0x1711: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1716:
	/* 0x1716: je     172f <trace_ret_do_init_module+0x172f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172f;
	}
x86_l_1718:
	/* 0x1718: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_171b:
	/* 0x171b: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_171f:
	/* 0x171f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1722:
	/* 0x1722: xor    rcx,QWORD PTR [r15+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1729:
	/* 0x1729: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_172c:
	/* 0x172c: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_172f:
	/* 0x172f: movzx  eax,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1734:
	/* 0x1734: mov    r13,QWORD PTR [r15+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_173b:
	/* 0x173b: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_173e:
	/* 0x173e: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1743:
	/* 0x1743: je     1877 <trace_ret_do_init_module+0x1877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1877;
	}
x86_l_1749:
	/* 0x1749: mov    rcx,QWORD PTR [r15+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1750:
	/* 0x1750: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1758:
	/* 0x1758: mov    rcx,QWORD PTR [r15+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_175f:
	/* 0x175f: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1764:
	/* 0x1764: mov    rcx,QWORD PTR [r15+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_176b:
	/* 0x176b: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1770:
	/* 0x1770: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1774:
	/* 0x1774: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_177b:
	/* 0x177b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_177e:
	/* 0x177e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1783:
	/* 0x1783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1785:
	/* 0x1785: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1788:
	/* 0x1788: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_178c:
	/* 0x178c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1790:
	/* 0x1790: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1797:
	/* 0x1797: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_179a:
	/* 0x179a: je     17ba <trace_ret_do_init_module+0x17ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ba;
	}
x86_l_179c:
	/* 0x179c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_179f:
	/* 0x179f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a4:
	/* 0x17a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17a7:
	/* 0x17a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a9:
	/* 0x17a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ac:
	/* 0x17ac: je     17ba <trace_ret_do_init_module+0x17ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ba;
	}
x86_l_17ae:
	/* 0x17ae: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b1:
	/* 0x17b1: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b5:
	/* 0x17b5: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17b8:
	/* 0x17b8: jmp    17bd <trace_ret_do_init_module+0x17bd> */
	goto x86_l_17bd;
x86_l_17ba:
	/* 0x17ba: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17bd:
	/* 0x17bd: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17c2:
	/* 0x17c2: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17c7:
	/* 0x17c7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17cb:
	/* 0x17cb: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_17ce:
	/* 0x17ce: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_17d1:
	/* 0x17d1: jb     17e9 <trace_ret_do_init_module+0x17e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17e9;
	}
x86_l_17d3:
	/* 0x17d3: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17d7:
	/* 0x17d7: je     17de <trace_ret_do_init_module+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17de;
	}
x86_l_17d9:
	/* 0x17d9: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_17dc:
	/* 0x17dc: jbe    17e9 <trace_ret_do_init_module+0x17e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17e9;
	}
x86_l_17de:
	/* 0x17de: and    r14,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 208ULL);
x86_l_17e6:
	/* 0x17e6: or     r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_17e9:
	/* 0x17e9: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17ed:
	/* 0x17ed: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f1:
	/* 0x17f1: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17f8:
	/* 0x17f8: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_17fb:
	/* 0x17fb: je     183c <trace_ret_do_init_module+0x183c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183c;
	}
x86_l_17fd:
	/* 0x17fd: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1802:
	/* 0x1802: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1805:
	/* 0x1805: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_180a:
	/* 0x180a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_180d:
	/* 0x180d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180f:
	/* 0x180f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1812:
	/* 0x1812: je     1840 <trace_ret_do_init_module+0x1840> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1840;
	}
x86_l_1814:
	/* 0x1814: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1817:
	/* 0x1817: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_181b:
	/* 0x181b: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_181e:
	/* 0x181e: jmp    1842 <trace_ret_do_init_module+0x1842> */
	goto x86_l_1842;
x86_l_1820:
	/* 0x1820: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1827:
	/* 0x1827: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_182e:
	/* 0x182e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1831:
	/* 0x1831: jne    16b2 <trace_ret_do_init_module+0x16b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16b2;
	}
x86_l_1837:
	/* 0x1837: jmp    16d9 <trace_ret_do_init_module+0x16d9> */
	goto x86_l_16d9;
x86_l_183c:
	/* 0x183c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183e:
	/* 0x183e: jmp    184c <trace_ret_do_init_module+0x184c> */
	goto x86_l_184c;
x86_l_1840:
	/* 0x1840: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1842:
	/* 0x1842: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1847:
	/* 0x1847: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_184c:
	/* 0x184c: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_184f:
	/* 0x184f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1853:
	/* 0x1853: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1856:
	/* 0x1856: jb     186e <trace_ret_do_init_module+0x186e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_186e;
	}
x86_l_1858:
	/* 0x1858: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_185c:
	/* 0x185c: je     1863 <trace_ret_do_init_module+0x1863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1863;
	}
x86_l_185e:
	/* 0x185e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1861:
	/* 0x1861: jbe    186e <trace_ret_do_init_module+0x186e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_186e;
	}
x86_l_1863:
	/* 0x1863: and    r14,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 208ULL);
x86_l_186b:
	/* 0x186b: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_186e:
	/* 0x186e: or     r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_1871:
	/* 0x1871: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1874:
	/* 0x1874: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1877:
	/* 0x1877: cmp    QWORD PTR [r15+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_187f:
	/* 0x187f: je     1916 <trace_ret_do_init_module+0x1916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1916;
	}
x86_l_1885:
	/* 0x1885: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_188a:
	/* 0x188a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188c:
	/* 0x188c: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1890:
	/* 0x1890: mov    rbx,QWORD PTR [r15+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1897:
	/* 0x1897: mov    rax,QWORD PTR [r15+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_189e:
	/* 0x189e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18a3:
	/* 0x18a3: mov    r13,QWORD PTR [r15+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_18aa:
	/* 0x18aa: mov    r12,QWORD PTR [r15+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_18b1:
	/* 0x18b1: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_18b6:
	/* 0x18b6: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_18c1:
	/* 0x18c1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18c4:
	/* 0x18c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c9:
	/* 0x18c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cb:
	/* 0x18cb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_18ce:
	/* 0x18ce: mov    eax,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18d2:
	/* 0x18d2: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d6:
	/* 0x18d6: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_18dd:
	/* 0x18dd: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_18e0:
	/* 0x18e0: je     18fd <trace_ret_do_init_module+0x18fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18fd;
	}
x86_l_18e2:
	/* 0x18e2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18e5:
	/* 0x18e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18ea:
	/* 0x18ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ec:
	/* 0x18ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18ef:
	/* 0x18ef: je     18fd <trace_ret_do_init_module+0x18fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18fd;
	}
x86_l_18f1:
	/* 0x18f1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f4:
	/* 0x18f4: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f8:
	/* 0x18f8: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18fb:
	/* 0x18fb: jmp    18ff <trace_ret_do_init_module+0x18ff> */
	goto x86_l_18ff;
x86_l_18fd:
	/* 0x18fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ff:
	/* 0x18ff: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1902:
	/* 0x1902: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1906:
	/* 0x1906: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1909:
	/* 0x1909: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_190c:
	/* 0x190c: jae    191e <trace_ret_do_init_module+0x191e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_191e;
	}
x86_l_190e:
	/* 0x190e: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1914:
	/* 0x1914: jmp    1937 <trace_ret_do_init_module+0x1937> */
	goto x86_l_1937;
x86_l_1916:
	/* 0x1916: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_191c:
	/* 0x191c: jmp    193d <trace_ret_do_init_module+0x193d> */
	goto x86_l_193d;
x86_l_191e:
	/* 0x191e: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1922:
	/* 0x1922: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1928:
	/* 0x1928: je     192f <trace_ret_do_init_module+0x192f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192f;
	}
x86_l_192a:
	/* 0x192a: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_192d:
	/* 0x192d: jbe    1937 <trace_ret_do_init_module+0x1937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1937;
	}
x86_l_192f:
	/* 0x192f: and    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 88ULL);
x86_l_1934:
	/* 0x1934: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1937:
	/* 0x1937: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_193a:
	/* 0x193a: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_193d:
	/* 0x193d: cmp    QWORD PTR [r15+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1945:
	/* 0x1945: je     1a0d <trace_ret_do_init_module+0x1a0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a0d;
	}
x86_l_194b:
	/* 0x194b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1950:
	/* 0x1950: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1957:
	/* 0x1957: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_195a:
	/* 0x195a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_195f:
	/* 0x195f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1964:
	/* 0x1964: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1969:
	/* 0x1969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196b:
	/* 0x196b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196f:
	/* 0x196f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1973:
	/* 0x1973: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1976:
	/* 0x1976: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_197b:
	/* 0x197b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1980:
	/* 0x1980: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1985:
	/* 0x1985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1987:
	/* 0x1987: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198b:
	/* 0x198b: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1990:
	/* 0x1990: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1995:
	/* 0x1995: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_199a:
	/* 0x199a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_199e:
	/* 0x199e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a3:
	/* 0x19a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a5:
	/* 0x19a5: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19a9:
	/* 0x19a9: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19ad:
	/* 0x19ad: mov    rbx,QWORD PTR [r15+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_19b4:
	/* 0x19b4: mov    r14,QWORD PTR [r15+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_19bb:
	/* 0x19bb: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c0:
	/* 0x19c0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_19c7:
	/* 0x19c7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_19ca:
	/* 0x19ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19cf:
	/* 0x19cf: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19d2:
	/* 0x19d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d4:
	/* 0x19d4: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_19db:
	/* 0x19db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19de:
	/* 0x19de: je     19ff <trace_ret_do_init_module+0x19ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ff;
	}
x86_l_19e0:
	/* 0x19e0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19e3:
	/* 0x19e3: lea    rsi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19e7:
	/* 0x19e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ec:
	/* 0x19ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ee:
	/* 0x19ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19f1:
	/* 0x19f1: je     19ff <trace_ret_do_init_module+0x19ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ff;
	}
x86_l_19f3:
	/* 0x19f3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f6:
	/* 0x19f6: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fa:
	/* 0x19fa: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19fd:
	/* 0x19fd: jmp    1a01 <trace_ret_do_init_module+0x1a01> */
	goto x86_l_1a01;
x86_l_19ff:
	/* 0x19ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a01:
	/* 0x1a01: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a04:
	/* 0x1a04: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a07:
	/* 0x1a07: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a0a:
	/* 0x1a0a: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a0d:
	/* 0x1a0d: cmp    QWORD PTR [r15+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1a15:
	/* 0x1a15: je     1afb <trace_ret_do_init_module+0x1afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1afb;
	}
x86_l_1a1b:
	/* 0x1a1b: mov    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1a22:
	/* 0x1a22: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a29:
	/* 0x1a29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a33:
	/* 0x1a33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a38:
	/* 0x1a38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3a:
	/* 0x1a3a: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a41:
	/* 0x1a41: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a46:
	/* 0x1a46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a50:
	/* 0x1a50: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a53:
	/* 0x1a53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a55:
	/* 0x1a55: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a58:
	/* 0x1a58: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a5c:
	/* 0x1a5c: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a60:
	/* 0x1a60: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a64:
	/* 0x1a64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a67:
	/* 0x1a67: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a71:
	/* 0x1a71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a76:
	/* 0x1a76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a78:
	/* 0x1a78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7c:
	/* 0x1a7c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1a80:
	/* 0x1a80: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a83:
	/* 0x1a83: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a88:
	/* 0x1a88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a92:
	/* 0x1a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a94:
	/* 0x1a94: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a97:
	/* 0x1a97: mov    DWORD PTR [r15+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    rbx,QWORD PTR [r15+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    r14,QWORD PTR [r15+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aae:
	/* 0x1aae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1ab5:
	/* 0x1ab5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ab8:
	/* 0x1ab8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1abd:
	/* 0x1abd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ac0:
	/* 0x1ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac2:
	/* 0x1ac2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ac9:
	/* 0x1ac9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1acc:
	/* 0x1acc: je     1aed <trace_ret_do_init_module+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aed;
	}
x86_l_1ace:
	/* 0x1ace: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad1:
	/* 0x1ad1: lea    rsi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ada:
	/* 0x1ada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adc:
	/* 0x1adc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1adf:
	/* 0x1adf: je     1aed <trace_ret_do_init_module+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aed;
	}
x86_l_1ae1:
	/* 0x1ae1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae8:
	/* 0x1ae8: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1aeb:
	/* 0x1aeb: jmp    1aef <trace_ret_do_init_module+0x1aef> */
	goto x86_l_1aef;
x86_l_1aed:
	/* 0x1aed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aef:
	/* 0x1aef: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1af2:
	/* 0x1af2: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1af5:
	/* 0x1af5: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1af8:
	/* 0x1af8: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1afb:
	/* 0x1afb: cmp    QWORD PTR [r15+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1b03:
	/* 0x1b03: je     1bda <trace_ret_do_init_module+0x1bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7130ULL;
	}
x86_l_1b09:
	/* 0x1b09: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1b0e:
	/* 0x1b0e: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1b15:
	/* 0x1b15: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b18:
	/* 0x1b18: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b22:
	/* 0x1b22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b27:
	/* 0x1b27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b29:
	/* 0x1b29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b30:
	/* 0x1b30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b35:
	/* 0x1b35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b3f:
	/* 0x1b3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b41:
	/* 0x1b41: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b45:
	/* 0x1b45: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
	return 6989ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7038ULL: goto x86_l_1b7e;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7054ULL: goto x86_l_1b8e;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7074ULL: goto x86_l_1ba2;
	case 7081ULL: goto x86_l_1ba9;
	case 7084ULL: goto x86_l_1bac;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7097ULL: goto x86_l_1bb9;
	case 7099ULL: goto x86_l_1bbb;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7116ULL: goto x86_l_1bcc;
	case 7118ULL: goto x86_l_1bce;
	case 7121ULL: goto x86_l_1bd1;
	case 7124ULL: goto x86_l_1bd4;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7138ULL: goto x86_l_1be2;
	case 7144ULL: goto x86_l_1be8;
	case 7150ULL: goto x86_l_1bee;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7164ULL: goto x86_l_1bfc;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7174ULL: goto x86_l_1c06;
	case 7181ULL: goto x86_l_1c0d;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7238ULL: goto x86_l_1c46;
	case 7241ULL: goto x86_l_1c49;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7269ULL: goto x86_l_1c65;
	case 7275ULL: goto x86_l_1c6b;
	case 7282ULL: goto x86_l_1c72;
	case 7285ULL: goto x86_l_1c75;
	case 7287ULL: goto x86_l_1c77;
	case 7291ULL: goto x86_l_1c7b;
	case 7294ULL: goto x86_l_1c7e;
	case 7301ULL: goto x86_l_1c85;
	case 7307ULL: goto x86_l_1c8b;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7336ULL: goto x86_l_1ca8;
	case 7339ULL: goto x86_l_1cab;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7379ULL: goto x86_l_1cd3;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	case 7392ULL: goto x86_l_1ce0;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7429ULL: goto x86_l_1d05;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7471ULL: goto x86_l_1d2f;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7490ULL: goto x86_l_1d42;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7502ULL: goto x86_l_1d4e;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7521ULL: goto x86_l_1d61;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7607ULL: goto x86_l_1db7;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7623ULL: goto x86_l_1dc7;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7640ULL: goto x86_l_1dd8;
	case 7644ULL: goto x86_l_1ddc;
	case 7647ULL: goto x86_l_1ddf;
	case 7649ULL: goto x86_l_1de1;
	case 7656ULL: goto x86_l_1de8;
	case 7663ULL: goto x86_l_1def;
	case 7666ULL: goto x86_l_1df2;
	case 7673ULL: goto x86_l_1df9;
	case 7679ULL: goto x86_l_1dff;
	case 7687ULL: goto x86_l_1e07;
	case 7693ULL: goto x86_l_1e0d;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7712ULL: goto x86_l_1e20;
	case 7721ULL: goto x86_l_1e29;
	case 7729ULL: goto x86_l_1e31;
	case 7737ULL: goto x86_l_1e39;
	case 7744ULL: goto x86_l_1e40;
	case 7750ULL: goto x86_l_1e46;
	case 7758ULL: goto x86_l_1e4e;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7790ULL: goto x86_l_1e6e;
	case 7794ULL: goto x86_l_1e72;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7808ULL: goto x86_l_1e80;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7820ULL: goto x86_l_1e8c;
	case 7827ULL: goto x86_l_1e93;
	case 7829ULL: goto x86_l_1e95;
	case 7837ULL: goto x86_l_1e9d;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7856ULL: goto x86_l_1eb0;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7875ULL: goto x86_l_1ec3;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7898ULL: goto x86_l_1eda;
	case 7906ULL: goto x86_l_1ee2;
	case 7914ULL: goto x86_l_1eea;
	case 7921ULL: goto x86_l_1ef1;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7951ULL: goto x86_l_1f0f;
	case 7955ULL: goto x86_l_1f13;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7972ULL: goto x86_l_1f24;
	case 7974ULL: goto x86_l_1f26;
	case 7976ULL: goto x86_l_1f28;
	case 7984ULL: goto x86_l_1f30;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 8001ULL: goto x86_l_1f41;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8020ULL: goto x86_l_1f54;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8031ULL: goto x86_l_1f5f;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8053ULL: goto x86_l_1f75;
	case 8062ULL: goto x86_l_1f7e;
	case 8070ULL: goto x86_l_1f86;
	case 8078ULL: goto x86_l_1f8e;
	case 8084ULL: goto x86_l_1f94;
	case 8086ULL: goto x86_l_1f96;
	case 8090ULL: goto x86_l_1f9a;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8115ULL: goto x86_l_1fb3;
	case 8119ULL: goto x86_l_1fb7;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8134ULL: goto x86_l_1fc6;
	case 8136ULL: goto x86_l_1fc8;
	case 8138ULL: goto x86_l_1fca;
	case 8140ULL: goto x86_l_1fcc;
	case 8148ULL: goto x86_l_1fd4;
	case 8155ULL: goto x86_l_1fdb;
	case 8157ULL: goto x86_l_1fdd;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8176ULL: goto x86_l_1ff0;
	case 8184ULL: goto x86_l_1ff8;
	case 8191ULL: goto x86_l_1fff;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8214ULL: goto x86_l_2016;
	case 8221ULL: goto x86_l_201d;
	case 8223ULL: goto x86_l_201f;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
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
	case 8281ULL: goto x86_l_2059;
	case 8289ULL: goto x86_l_2061;
	case 8296ULL: goto x86_l_2068;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8342ULL: goto x86_l_2096;
	case 8346ULL: goto x86_l_209a;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8370ULL: goto x86_l_20b2;
	case 8374ULL: goto x86_l_20b6;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8394ULL: goto x86_l_20ca;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8421ULL: goto x86_l_20e5;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8434ULL: goto x86_l_20f2;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8461ULL: goto x86_l_210d;
	case 8464ULL: goto x86_l_2110;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8482ULL: goto x86_l_2122;
	case 8484ULL: goto x86_l_2124;
	case 8487ULL: goto x86_l_2127;
	case 8491ULL: goto x86_l_212b;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8502ULL: goto x86_l_2136;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8519ULL: goto x86_l_2147;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8547ULL: goto x86_l_2163;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8581ULL: goto x86_l_2185;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8615ULL: goto x86_l_21a7;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8646ULL: goto x86_l_21c6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b4d:
	/* 0x1b4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b52:
	/* 0x1b52: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b55:
	/* 0x1b55: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1b5a:
	/* 0x1b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5c:
	/* 0x1b5c: lea    rbx,[r15+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1b60:
	/* 0x1b60: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b65:
	/* 0x1b65: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b6d:
	/* 0x1b6d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b72:
	/* 0x1b72: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b75:
	/* 0x1b75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b77:
	/* 0x1b77: mov    r14,QWORD PTR [r15+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    r12,QWORD PTR [r15+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1b85:
	/* 0x1b85: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1b95:
	/* 0x1b95: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1b98:
	/* 0x1b98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b9d:
	/* 0x1b9d: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ba0:
	/* 0x1ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba2:
	/* 0x1ba2: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ba9:
	/* 0x1ba9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bac:
	/* 0x1bac: je     1bcc <trace_ret_do_init_module+0x1bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcc;
	}
x86_l_1bae:
	/* 0x1bae: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1bb1:
	/* 0x1bb1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1bb9:
	/* 0x1bb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbb:
	/* 0x1bbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bbe:
	/* 0x1bbe: je     1bcc <trace_ret_do_init_module+0x1bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcc;
	}
x86_l_1bc0:
	/* 0x1bc0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc7:
	/* 0x1bc7: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1bca:
	/* 0x1bca: jmp    1bce <trace_ret_do_init_module+0x1bce> */
	goto x86_l_1bce;
x86_l_1bcc:
	/* 0x1bcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bce:
	/* 0x1bce: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bd1:
	/* 0x1bd1: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1bd4:
	/* 0x1bd4: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bd7:
	/* 0x1bd7: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1bda:
	/* 0x1bda: cmp    QWORD PTR [r15+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1be2:
	/* 0x1be2: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1be8:
	/* 0x1be8: je     1c6b <trace_ret_do_init_module+0x1c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c6b;
	}
x86_l_1bee:
	/* 0x1bee: lea    rbx,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1bfc:
	/* 0x1bfc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bff:
	/* 0x1bff: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c04:
	/* 0x1c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c06:
	/* 0x1c06: mov    r14,QWORD PTR [r15+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    r12,QWORD PTR [r15+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1c14:
	/* 0x1c14: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c19:
	/* 0x1c19: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1c20:
	/* 0x1c20: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c23:
	/* 0x1c23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c28:
	/* 0x1c28: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c2b:
	/* 0x1c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2d:
	/* 0x1c2d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c34:
	/* 0x1c34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c37:
	/* 0x1c37: je     1c57 <trace_ret_do_init_module+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c57;
	}
x86_l_1c39:
	/* 0x1c39: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c3c:
	/* 0x1c3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c41:
	/* 0x1c41: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c44:
	/* 0x1c44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c46:
	/* 0x1c46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c49:
	/* 0x1c49: je     1c57 <trace_ret_do_init_module+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c57;
	}
x86_l_1c4b:
	/* 0x1c4b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c52:
	/* 0x1c52: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c55:
	/* 0x1c55: jmp    1c59 <trace_ret_do_init_module+0x1c59> */
	goto x86_l_1c59;
x86_l_1c57:
	/* 0x1c57: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c59:
	/* 0x1c59: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c5c:
	/* 0x1c5c: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c5f:
	/* 0x1c5f: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c62:
	/* 0x1c62: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c65:
	/* 0x1c65: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    rbx,QWORD PTR [r15+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1c72:
	/* 0x1c72: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1c75:
	/* 0x1c75: je     1cd9 <trace_ret_do_init_module+0x1cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd9;
	}
x86_l_1c77:
	/* 0x1c77: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    r14,QWORD PTR [r15+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1c85:
	/* 0x1c85: mov    WORD PTR [rsp+0x48],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1c92:
	/* 0x1c92: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c97:
	/* 0x1c97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c9c:
	/* 0x1c9c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c9f:
	/* 0x1c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca1:
	/* 0x1ca1: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ca8:
	/* 0x1ca8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cab:
	/* 0x1cab: je     1ccb <trace_ret_do_init_module+0x1ccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ccb;
	}
x86_l_1cad:
	/* 0x1cad: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cb0:
	/* 0x1cb0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1cb3:
	/* 0x1cb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb8:
	/* 0x1cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cba:
	/* 0x1cba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cbd:
	/* 0x1cbd: je     1ccb <trace_ret_do_init_module+0x1ccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ccb;
	}
x86_l_1cbf:
	/* 0x1cbf: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc6:
	/* 0x1cc6: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1cc9:
	/* 0x1cc9: jmp    1ccd <trace_ret_do_init_module+0x1ccd> */
	goto x86_l_1ccd;
x86_l_1ccb:
	/* 0x1ccb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ccd:
	/* 0x1ccd: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cd0:
	/* 0x1cd0: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cd3:
	/* 0x1cd3: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cd6:
	/* 0x1cd6: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cd9:
	/* 0x1cd9: mov    rbx,QWORD PTR [r15+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1ce0:
	/* 0x1ce0: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1ce3:
	/* 0x1ce3: je     1d42 <trace_ret_do_init_module+0x1d42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d42;
	}
x86_l_1ce5:
	/* 0x1ce5: mov    r14,QWORD PTR [r15+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1cec:
	/* 0x1cec: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf1:
	/* 0x1cf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1cf8:
	/* 0x1cf8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1cfb:
	/* 0x1cfb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d00:
	/* 0x1d00: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d03:
	/* 0x1d03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d05:
	/* 0x1d05: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d0c:
	/* 0x1d0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d0f:
	/* 0x1d0f: je     1d34 <trace_ret_do_init_module+0x1d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d34;
	}
x86_l_1d11:
	/* 0x1d11: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d14:
	/* 0x1d14: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d19:
	/* 0x1d19: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d21:
	/* 0x1d21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d23:
	/* 0x1d23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d26:
	/* 0x1d26: je     1d34 <trace_ret_do_init_module+0x1d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d34;
	}
x86_l_1d28:
	/* 0x1d28: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2f:
	/* 0x1d2f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d32:
	/* 0x1d32: jmp    1d36 <trace_ret_do_init_module+0x1d36> */
	goto x86_l_1d36;
x86_l_1d34:
	/* 0x1d34: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d36:
	/* 0x1d36: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d39:
	/* 0x1d39: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d3c:
	/* 0x1d3c: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d3f:
	/* 0x1d3f: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d42:
	/* 0x1d42: mov    r14,QWORD PTR [r15+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1d49:
	/* 0x1d49: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1d4c:
	/* 0x1d4c: je     1dc7 <trace_ret_do_init_module+0x1dc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc7;
	}
x86_l_1d4e:
	/* 0x1d4e: mov    r12,QWORD PTR [r15+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1d55:
	/* 0x1d55: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1d61:
	/* 0x1d61: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1d64:
	/* 0x1d64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d69:
	/* 0x1d69: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d6c:
	/* 0x1d6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6e:
	/* 0x1d6e: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d75:
	/* 0x1d75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d78:
	/* 0x1d78: je     1db9 <trace_ret_do_init_module+0x1db9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db9;
	}
x86_l_1d7a:
	/* 0x1d7a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d7d:
	/* 0x1d7d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d82:
	/* 0x1d82: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d86:
	/* 0x1d86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d8e:
	/* 0x1d8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d90:
	/* 0x1d90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d93:
	/* 0x1d93: jne    1dad <trace_ret_do_init_module+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dad;
	}
x86_l_1d95:
	/* 0x1d95: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d9a:
	/* 0x1d9a: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1da3:
	/* 0x1da3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1da6:
	/* 0x1da6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da8:
	/* 0x1da8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: je     1db9 <trace_ret_do_init_module+0x1db9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db9;
	}
x86_l_1dad:
	/* 0x1dad: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db0:
	/* 0x1db0: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db4:
	/* 0x1db4: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1db7:
	/* 0x1db7: jmp    1dbb <trace_ret_do_init_module+0x1dbb> */
	goto x86_l_1dbb;
x86_l_1db9:
	/* 0x1db9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dbb:
	/* 0x1dbb: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1dbe:
	/* 0x1dbe: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1dc1:
	/* 0x1dc1: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1dc4:
	/* 0x1dc4: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1dc7:
	/* 0x1dc7: mov    rax,QWORD PTR [r15+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1dce:
	/* 0x1dce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd1:
	/* 0x1dd1: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dd6:
	/* 0x1dd6: je     1ddf <trace_ret_do_init_module+0x1ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ddf;
	}
x86_l_1dd8:
	/* 0x1dd8: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1ddc:
	/* 0x1ddc: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ddf:
	/* 0x1ddf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de1:
	/* 0x1de1: and    rbp,QWORD PTR [r15+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1de8:
	/* 0x1de8: mov    rcx,QWORD PTR [r15+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1def:
	/* 0x1def: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1df2:
	/* 0x1df2: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1df9:
	/* 0x1df9: je     2563 <trace_ret_do_init_module+0x2563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9571ULL;
	}
x86_l_1dff:
	/* 0x1dff: movzx  eax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e07:
	/* 0x1e07: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e15:
	/* 0x1e15: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e1a:
	/* 0x1e1a: ja     1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fff;
	}
x86_l_1e20:
	/* 0x1e20: mov    BYTE PTR [r15+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1e29:
	/* 0x1e29: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e31:
	/* 0x1e31: mov    WORD PTR [r15+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1e39:
	/* 0x1e39: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1e40:
	/* 0x1e40: ja     1ec3 <trace_ret_do_init_module+0x1ec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ec3;
	}
x86_l_1e46:
	/* 0x1e46: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1e4e:
	/* 0x1e4e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e52:
	/* 0x1e52: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e55:
	/* 0x1e55: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e61:
	/* 0x1e61: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e66:
	/* 0x1e66: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e6e:
	/* 0x1e6e: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1e72:
	/* 0x1e72: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e79:
	/* 0x1e79: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e7e:
	/* 0x1e7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e80:
	/* 0x1e80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e82:
	/* 0x1e82: jle    1ebb <trace_ret_do_init_module+0x1ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ebb;
	}
x86_l_1e84:
	/* 0x1e84: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e8c:
	/* 0x1e8c: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1e93:
	/* 0x1e93: ja     1ec3 <trace_ret_do_init_module+0x1ec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ec3;
	}
x86_l_1e95:
	/* 0x1e95: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1e9d:
	/* 0x1e9d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ea5:
	/* 0x1ea5: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1eb0:
	/* 0x1eb0: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1eb9:
	/* 0x1eb9: jmp    1ec3 <trace_ret_do_init_module+0x1ec3> */
	goto x86_l_1ec3;
x86_l_1ebb:
	/* 0x1ebb: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ec3:
	/* 0x1ec3: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ec6:
	/* 0x1ec6: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1ecb:
	/* 0x1ecb: ja     1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fff;
	}
x86_l_1ed1:
	/* 0x1ed1: mov    BYTE PTR [r15+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_1eda:
	/* 0x1eda: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    WORD PTR [r15+0x7d8e],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_1eea:
	/* 0x1eea: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1ef1:
	/* 0x1ef1: ja     1f67 <trace_ret_do_init_module+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f67;
	}
x86_l_1ef3:
	/* 0x1ef3: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ef6:
	/* 0x1ef6: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1efd:
	/* 0x1efd: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1f02:
	/* 0x1f02: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f07:
	/* 0x1f07: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f0f:
	/* 0x1f0f: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1f13:
	/* 0x1f13: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1f22:
	/* 0x1f22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f24:
	/* 0x1f24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f26:
	/* 0x1f26: jle    1f5f <trace_ret_do_init_module+0x1f5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f5f;
	}
x86_l_1f28:
	/* 0x1f28: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f30:
	/* 0x1f30: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1f37:
	/* 0x1f37: ja     1f67 <trace_ret_do_init_module+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f67;
	}
x86_l_1f39:
	/* 0x1f39: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1f41:
	/* 0x1f41: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f49:
	/* 0x1f49: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f54:
	/* 0x1f54: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f5d:
	/* 0x1f5d: jmp    1f67 <trace_ret_do_init_module+0x1f67> */
	goto x86_l_1f67;
x86_l_1f5f:
	/* 0x1f5f: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f67:
	/* 0x1f67: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f6a:
	/* 0x1f6a: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1f6f:
	/* 0x1f6f: ja     1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fff;
	}
x86_l_1f75:
	/* 0x1f75: mov    BYTE PTR [r15+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_1f7e:
	/* 0x1f7e: movzx  eax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f86:
	/* 0x1f86: mov    WORD PTR [r15+0x7d90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32144ULL);
x86_l_1f8e:
	/* 0x1f8e: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1f94:
	/* 0x1f94: ja     1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fff;
	}
x86_l_1f96:
	/* 0x1f96: lea    rcx,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1f9a:
	/* 0x1f9a: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fab:
	/* 0x1fab: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fb3:
	/* 0x1fb3: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1fb7:
	/* 0x1fb7: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fc3:
	/* 0x1fc3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1fc6:
	/* 0x1fc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc8:
	/* 0x1fc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fca:
	/* 0x1fca: jle    1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fff;
	}
x86_l_1fcc:
	/* 0x1fcc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fd4:
	/* 0x1fd4: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1fdb:
	/* 0x1fdb: ja     1fff <trace_ret_do_init_module+0x1fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fff;
	}
x86_l_1fdd:
	/* 0x1fdd: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1fe5:
	/* 0x1fe5: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1fed:
	/* 0x1fed: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ff8:
	/* 0x1ff8: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1fff:
	/* 0x1fff: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2007:
	/* 0x2007: mov    eax,DWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_200a:
	/* 0x200a: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_200e:
	/* 0x200e: movzx  ebx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2016:
	/* 0x2016: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_201d:
	/* 0x201d: ja     2068 <trace_ret_do_init_module+0x2068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2068;
	}
x86_l_201f:
	/* 0x201f: mov    BYTE PTR [r15+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_2028:
	/* 0x2028: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_202e:
	/* 0x202e: ja     2068 <trace_ret_do_init_module+0x2068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2068;
	}
x86_l_2030:
	/* 0x2030: lea    rdi,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2034:
	/* 0x2034: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_203b:
	/* 0x203b: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
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
	/* 0x2054: js     2068 <trace_ret_do_init_module+0x2068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2068;
	}
x86_l_2056:
	/* 0x2056: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2059:
	/* 0x2059: mov    WORD PTR [r15+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2061:
	/* 0x2061: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2068:
	/* 0x2068: mov    rbx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_206f:
	/* 0x206f: lea    r13,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2073:
	/* 0x2073: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2076:
	/* 0x2076: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_207b:
	/* 0x207b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2080:
	/* 0x2080: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2085:
	/* 0x2085: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2088:
	/* 0x2088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208a:
	/* 0x208a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208e:
	/* 0x208e: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2096:
	/* 0x2096: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_209a:
	/* 0x209a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_209d:
	/* 0x209d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20a2:
	/* 0x20a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a7:
	/* 0x20a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ac:
	/* 0x20ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ae:
	/* 0x20ae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b2:
	/* 0x20b2: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_20b6:
	/* 0x20b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20b9:
	/* 0x20b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20be:
	/* 0x20be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20c3:
	/* 0x20c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c8:
	/* 0x20c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ca:
	/* 0x20ca: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ce:
	/* 0x20ce: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20d3:
	/* 0x20d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20d6:
	/* 0x20d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20db:
	/* 0x20db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20e0:
	/* 0x20e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20e5:
	/* 0x20e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e7:
	/* 0x20e7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ea:
	/* 0x20ea: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_20ee:
	/* 0x20ee: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f2:
	/* 0x20f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20f5:
	/* 0x20f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20fa:
	/* 0x20fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ff:
	/* 0x20ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2104:
	/* 0x2104: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2107:
	/* 0x2107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2109:
	/* 0x2109: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_210d:
	/* 0x210d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2110:
	/* 0x2110: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2115:
	/* 0x2115: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_211a:
	/* 0x211a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_211f:
	/* 0x211f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2122:
	/* 0x2122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2124:
	/* 0x2124: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2127:
	/* 0x2127: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_212b:
	/* 0x212b: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_212f:
	/* 0x212f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2133:
	/* 0x2133: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2136:
	/* 0x2136: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_213b:
	/* 0x213b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2140:
	/* 0x2140: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2145:
	/* 0x2145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2147:
	/* 0x2147: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214a:
	/* 0x214a: mov    DWORD PTR [r15+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_214e:
	/* 0x214e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2156:
	/* 0x2156: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215b:
	/* 0x215b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2160:
	/* 0x2160: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2163:
	/* 0x2163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2165:
	/* 0x2165: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2169:
	/* 0x2169: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_216d:
	/* 0x216d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2170:
	/* 0x2170: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2175:
	/* 0x2175: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_217a:
	/* 0x217a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_217f:
	/* 0x217f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2181:
	/* 0x2181: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2185:
	/* 0x2185: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2188:
	/* 0x2188: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_218d:
	/* 0x218d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2192:
	/* 0x2192: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2197:
	/* 0x2197: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_219a:
	/* 0x219a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219c:
	/* 0x219c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_219f:
	/* 0x219f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_21a3:
	/* 0x21a3: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21a7:
	/* 0x21a7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21ab:
	/* 0x21ab: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21ae:
	/* 0x21ae: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21b3:
	/* 0x21b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21b8:
	/* 0x21b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21bd:
	/* 0x21bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21bf:
	/* 0x21bf: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c2:
	/* 0x21c2: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21c6:
	/* 0x21c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 8649ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8703ULL: goto x86_l_21ff;
	case 8707ULL: goto x86_l_2203;
	case 8711ULL: goto x86_l_2207;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8731ULL: goto x86_l_221b;
	case 8735ULL: goto x86_l_221f;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8759ULL: goto x86_l_2237;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8817ULL: goto x86_l_2271;
	case 8820ULL: goto x86_l_2274;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8832ULL: goto x86_l_2280;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8852ULL: goto x86_l_2294;
	case 8856ULL: goto x86_l_2298;
	case 8860ULL: goto x86_l_229c;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8883ULL: goto x86_l_22b3;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8906ULL: goto x86_l_22ca;
	case 8908ULL: goto x86_l_22cc;
	case 8912ULL: goto x86_l_22d0;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8938ULL: goto x86_l_22ea;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8950ULL: goto x86_l_22f6;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8970ULL: goto x86_l_230a;
	case 8973ULL: goto x86_l_230d;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9015ULL: goto x86_l_2337;
	case 9019ULL: goto x86_l_233b;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9069ULL: goto x86_l_236d;
	case 9073ULL: goto x86_l_2371;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9084ULL: goto x86_l_237c;
	case 9088ULL: goto x86_l_2380;
	case 9092ULL: goto x86_l_2384;
	case 9095ULL: goto x86_l_2387;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9112ULL: goto x86_l_2398;
	case 9116ULL: goto x86_l_239c;
	case 9120ULL: goto x86_l_23a0;
	case 9128ULL: goto x86_l_23a8;
	case 9132ULL: goto x86_l_23ac;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9156ULL: goto x86_l_23c4;
	case 9160ULL: goto x86_l_23c8;
	case 9164ULL: goto x86_l_23cc;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9191ULL: goto x86_l_23e7;
	case 9195ULL: goto x86_l_23eb;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9237ULL: goto x86_l_2415;
	case 9241ULL: goto x86_l_2419;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9338ULL: goto x86_l_247a;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9365ULL: goto x86_l_2495;
	case 9367ULL: goto x86_l_2497;
	case 9375ULL: goto x86_l_249f;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9412ULL: goto x86_l_24c4;
	case 9420ULL: goto x86_l_24cc;
	case 9424ULL: goto x86_l_24d0;
	case 9426ULL: goto x86_l_24d2;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9451ULL: goto x86_l_24eb;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9460ULL: goto x86_l_24f4;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9480ULL: goto x86_l_2508;
	case 9486ULL: goto x86_l_250e;
	case 9490ULL: goto x86_l_2512;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9515ULL: goto x86_l_252b;
	case 9518ULL: goto x86_l_252e;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9529ULL: goto x86_l_2539;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9571ULL: goto x86_l_2563;
	case 9578ULL: goto x86_l_256a;
	case 9579ULL: goto x86_l_256b;
	case 9581ULL: goto x86_l_256d;
	case 9583ULL: goto x86_l_256f;
	case 9585ULL: goto x86_l_2571;
	case 9587ULL: goto x86_l_2573;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9598ULL: goto x86_l_257e;
	case 9600ULL: goto x86_l_2580;
	case 9602ULL: goto x86_l_2582;
	case 9603ULL: goto x86_l_2583;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9617ULL: goto x86_l_2591;
	case 9626ULL: goto x86_l_259a;
	case 9633ULL: goto x86_l_25a1;
	case 9644ULL: goto x86_l_25ac;
	case 9655ULL: goto x86_l_25b7;
	case 9666ULL: goto x86_l_25c2;
	case 9677ULL: goto x86_l_25cd;
	case 9688ULL: goto x86_l_25d8;
	case 9699ULL: goto x86_l_25e3;
	case 9710ULL: goto x86_l_25ee;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9729ULL: goto x86_l_2601;
	case 9733ULL: goto x86_l_2605;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9761ULL: goto x86_l_2621;
	case 9769ULL: goto x86_l_2629;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9787ULL: goto x86_l_263b;
	case 9793ULL: goto x86_l_2641;
	case 9795ULL: goto x86_l_2643;
	case 9803ULL: goto x86_l_264b;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9816ULL: goto x86_l_2658;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9836ULL: goto x86_l_266c;
	case 9844ULL: goto x86_l_2674;
	case 9851ULL: goto x86_l_267b;
	case 9855ULL: goto x86_l_267f;
	case 9862ULL: goto x86_l_2686;
	case 9870ULL: goto x86_l_268e;
	case 9877ULL: goto x86_l_2695;
	case 9883ULL: goto x86_l_269b;
	case 9892ULL: goto x86_l_26a4;
	case 9900ULL: goto x86_l_26ac;
	case 9903ULL: goto x86_l_26af;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9923ULL: goto x86_l_26c3;
	case 9926ULL: goto x86_l_26c6;
	case 9928ULL: goto x86_l_26c8;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9942ULL: goto x86_l_26d6;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9983ULL: goto x86_l_26ff;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 10000ULL: goto x86_l_2710;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10020ULL: goto x86_l_2724;
	case 10027ULL: goto x86_l_272b;
	case 10029ULL: goto x86_l_272d;
	case 10038ULL: goto x86_l_2736;
	case 10045ULL: goto x86_l_273d;
	case 10047ULL: goto x86_l_273f;
	case 10051ULL: goto x86_l_2743;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10076ULL: goto x86_l_275c;
	case 10078ULL: goto x86_l_275e;
	case 10081ULL: goto x86_l_2761;
	case 10083ULL: goto x86_l_2763;
	case 10087ULL: goto x86_l_2767;
	case 10096ULL: goto x86_l_2770;
	case 10104ULL: goto x86_l_2778;
	case 10108ULL: goto x86_l_277c;
	case 10115ULL: goto x86_l_2783;
	case 10123ULL: goto x86_l_278b;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10141ULL: goto x86_l_279d;
	case 10145ULL: goto x86_l_27a1;
	case 10152ULL: goto x86_l_27a8;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10172ULL: goto x86_l_27bc;
	case 10175ULL: goto x86_l_27bf;
	case 10177ULL: goto x86_l_27c1;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10203ULL: goto x86_l_27db;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10220ULL: goto x86_l_27ec;
	case 10223ULL: goto x86_l_27ef;
	case 10225ULL: goto x86_l_27f1;
	case 10228ULL: goto x86_l_27f4;
	case 10230ULL: goto x86_l_27f6;
	case 10234ULL: goto x86_l_27fa;
	case 10238ULL: goto x86_l_27fe;
	case 10246ULL: goto x86_l_2806;
	case 10253ULL: goto x86_l_280d;
	case 10257ULL: goto x86_l_2811;
	case 10264ULL: goto x86_l_2818;
	case 10268ULL: goto x86_l_281c;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10289ULL: goto x86_l_2831;
	case 10291ULL: goto x86_l_2833;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21c9:
	/* 0x21c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21ce:
	/* 0x21ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21d3:
	/* 0x21d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d8:
	/* 0x21d8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_21db:
	/* 0x21db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21dd:
	/* 0x21dd: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e1:
	/* 0x21e1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21e4:
	/* 0x21e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21e9:
	/* 0x21e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21ee:
	/* 0x21ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21f3:
	/* 0x21f3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_21f6:
	/* 0x21f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f8:
	/* 0x21f8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21fb:
	/* 0x21fb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_21ff:
	/* 0x21ff: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2203:
	/* 0x2203: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2207:
	/* 0x2207: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x2219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221b:
	/* 0x221b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_221f:
	/* 0x221f: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2223:
	/* 0x2223: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2226:
	/* 0x2226: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_222b:
	/* 0x222b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2230:
	/* 0x2230: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2235:
	/* 0x2235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2237:
	/* 0x2237: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223a:
	/* 0x223a: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_223f:
	/* 0x223f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2242:
	/* 0x2242: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2247:
	/* 0x2247: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_224c:
	/* 0x224c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2251:
	/* 0x2251: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2254:
	/* 0x2254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2256:
	/* 0x2256: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225a:
	/* 0x225a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_225d:
	/* 0x225d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2262:
	/* 0x2262: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2267:
	/* 0x2267: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_226c:
	/* 0x226c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2271:
	/* 0x2271: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2274:
	/* 0x2274: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2278:
	/* 0x2278: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_227c:
	/* 0x227c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2280:
	/* 0x2280: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2283:
	/* 0x2283: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2288:
	/* 0x2288: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_228d:
	/* 0x228d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2292:
	/* 0x2292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2294:
	/* 0x2294: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2298:
	/* 0x2298: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_229c:
	/* 0x229c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_229f:
	/* 0x229f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22a4:
	/* 0x22a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22a9:
	/* 0x22a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22ae:
	/* 0x22ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b0:
	/* 0x22b0: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_22b3:
	/* 0x22b3: jne    2311 <trace_ret_do_init_module+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2311;
	}
x86_l_22b5:
	/* 0x22b5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22b8:
	/* 0x22b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22bd:
	/* 0x22bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c2:
	/* 0x22c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c7:
	/* 0x22c7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_22ca:
	/* 0x22ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22cc:
	/* 0x22cc: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d0:
	/* 0x22d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22d3:
	/* 0x22d3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22d8:
	/* 0x22d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22dd:
	/* 0x22dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22e2:
	/* 0x22e2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_22e5:
	/* 0x22e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e7:
	/* 0x22e7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ea:
	/* 0x22ea: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_22ee:
	/* 0x22ee: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_22f2:
	/* 0x22f2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22f6:
	/* 0x22f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22f9:
	/* 0x22f9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22fe:
	/* 0x22fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2303:
	/* 0x2303: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2308:
	/* 0x2308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230a:
	/* 0x230a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230d:
	/* 0x230d: mov    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2311:
	/* 0x2311: mov    DWORD PTR [r15+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2315:
	/* 0x2315: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_231c:
	/* 0x231c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_231f:
	/* 0x231f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2324:
	/* 0x2324: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2329:
	/* 0x2329: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232e:
	/* 0x232e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2331:
	/* 0x2331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2333:
	/* 0x2333: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2337:
	/* 0x2337: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_233b:
	/* 0x233b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_233e:
	/* 0x233e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2343:
	/* 0x2343: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2348:
	/* 0x2348: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_234d:
	/* 0x234d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234f:
	/* 0x234f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2353:
	/* 0x2353: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2358:
	/* 0x2358: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_235d:
	/* 0x235d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2362:
	/* 0x2362: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2366:
	/* 0x2366: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_236b:
	/* 0x236b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236d:
	/* 0x236d: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2371:
	/* 0x2371: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2375:
	/* 0x2375: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_237a:
	/* 0x237a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237c:
	/* 0x237c: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2380:
	/* 0x2380: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2384:
	/* 0x2384: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2387:
	/* 0x2387: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_238c:
	/* 0x238c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2391:
	/* 0x2391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2396:
	/* 0x2396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2398:
	/* 0x2398: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239c:
	/* 0x239c: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a0:
	/* 0x23a0: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23a8:
	/* 0x23a8: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_23ac:
	/* 0x23ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23af:
	/* 0x23af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23b4:
	/* 0x23b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x23c4: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23c8:
	/* 0x23c8: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_23cc:
	/* 0x23cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23cf:
	/* 0x23cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23d4:
	/* 0x23d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d9:
	/* 0x23d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23de:
	/* 0x23de: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23e1:
	/* 0x23e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e3:
	/* 0x23e3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e7:
	/* 0x23e7: mov    QWORD PTR [r15+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23eb:
	/* 0x23eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23ee:
	/* 0x23ee: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23f3:
	/* 0x23f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f8:
	/* 0x23f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23fd:
	/* 0x23fd: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2400:
	/* 0x2400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2402:
	/* 0x2402: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2406:
	/* 0x2406: je     240d <trace_ret_do_init_module+0x240d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240d;
	}
x86_l_2408:
	/* 0x2408: or     BYTE PTR [r15+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_240d:
	/* 0x240d: mov    QWORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2415:
	/* 0x2415: lea    rdi,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2419:
	/* 0x2419: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2421:
	/* 0x2421: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2426:
	/* 0x2426: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_242b:
	/* 0x242b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2430:
	/* 0x2430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2432:
	/* 0x2432: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2435:
	/* 0x2435: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_243a:
	/* 0x243a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_243f:
	/* 0x243f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2444:
	/* 0x2444: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2447:
	/* 0x2447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2449:
	/* 0x2449: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244d:
	/* 0x244d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2450:
	/* 0x2450: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2455:
	/* 0x2455: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_245a:
	/* 0x245a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245f:
	/* 0x245f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2461:
	/* 0x2461: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2465:
	/* 0x2465: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_2468:
	/* 0x2468: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_246d:
	/* 0x246d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2472:
	/* 0x2472: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2475:
	/* 0x2475: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_247a:
	/* 0x247a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247c:
	/* 0x247c: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2480:
	/* 0x2480: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_248a:
	/* 0x248a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_248d:
	/* 0x248d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2492:
	/* 0x2492: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2495:
	/* 0x2495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2497:
	/* 0x2497: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_249f:
	/* 0x249f: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24a7:
	/* 0x24a7: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ab:
	/* 0x24ab: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_24b0:
	/* 0x24b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24b5:
	/* 0x24b5: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_24ba:
	/* 0x24ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bc:
	/* 0x24bc: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24c4:
	/* 0x24c4: mov    r14,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24cc:
	/* 0x24cc: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_24d0:
	/* 0x24d0: je     24f4 <trace_ret_do_init_module+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f4;
	}
x86_l_24d2:
	/* 0x24d2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_24d9:
	/* 0x24d9: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_24de:
	/* 0x24de: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_24e3:
	/* 0x24e3: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_24e8:
	/* 0x24e8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_24eb:
	/* 0x24eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ed:
	/* 0x24ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ef:
	/* 0x24ef: js     24f4 <trace_ret_do_init_module+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24f4;
	}
x86_l_24f1:
	/* 0x24f1: mov    DWORD PTR [rbx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_24f4:
	/* 0x24f4: movzx  eax,WORD PTR [rbx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24fb:
	/* 0x24fb: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2500:
	/* 0x2500: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2505:
	/* 0x2505: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2508:
	/* 0x2508: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_250e:
	/* 0x250e: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2512:
	/* 0x2512: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2519:
	/* 0x2519: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_251e:
	/* 0x251e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2523:
	/* 0x2523: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2528:
	/* 0x2528: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_252b:
	/* 0x252b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_252e:
	/* 0x252e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2530:
	/* 0x2530: jmp    2563 <trace_ret_do_init_module+0x2563> */
	goto x86_l_2563;
x86_l_2532:
	/* 0x2532: lea    rdi,[rbx+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2539:
	/* 0x2539: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253d:
	/* 0x253d: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2542:
	/* 0x2542: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2547:
	/* 0x2547: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_254c:
	/* 0x254c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254e:
	/* 0x254e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2551:
	/* 0x2551: jne    2561 <trace_ret_do_init_module+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2561;
	}
x86_l_2553:
	/* 0x2553: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2558:
	/* 0x2558: mov    WORD PTR [rbx+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_255c:
	/* 0x255c: jmp    c44 <trace_ret_do_init_module+0xc44> */
	return 3140ULL;
x86_l_2561:
	/* 0x2561: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2563:
	/* 0x2563: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_256a:
	/* 0x256a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_256b:
	/* 0x256b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_256d:
	/* 0x256d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_256f:
	/* 0x256f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2571:
	/* 0x2571: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2573:
	/* 0x2573: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: jmp    2cec <lkm_seeker_send_to_userspace+0x773> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2579:
	/* 0x2579: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_257a:
	/* 0x257a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_257c:
	/* 0x257c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_257e:
	/* 0x257e: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2580:
	/* 0x2580: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2582:
	/* 0x2582: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2583:
	/* 0x2583: sub    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 104ULL);
x86_l_2587:
	/* 0x2587: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_258a:
	/* 0x258a: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_258d:
	/* 0x258d: mov    rax,QWORD PTR [rdx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2591:
	/* 0x2591: mov    WORD PTR [rax+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_259a:
	/* 0x259a: mov    BYTE PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_25a1:
	/* 0x25a1: mov    QWORD PTR [rax+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_25ac:
	/* 0x25ac: mov    QWORD PTR [rax+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_25b7:
	/* 0x25b7: mov    QWORD PTR [rax+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_25c2:
	/* 0x25c2: mov    QWORD PTR [rax+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_25cd:
	/* 0x25cd: mov    QWORD PTR [rax+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_25d8:
	/* 0x25d8: mov    QWORD PTR [rax+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_25e3:
	/* 0x25e3: mov    QWORD PTR [rax+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_25ee:
	/* 0x25ee: mov    QWORD PTR [rax+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_25f9:
	/* 0x25f9: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25fe:
	/* 0x25fe: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_2601:
	/* 0x2601: lea    rdx,[rdi+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2605:
	/* 0x2605: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2608:
	/* 0x2608: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_260d:
	/* 0x260d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2612:
	/* 0x2612: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2617:
	/* 0x2617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2619:
	/* 0x2619: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261d:
	/* 0x261d: mov    r13,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2621:
	/* 0x2621: movzx  ebp,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2629:
	/* 0x2629: cmp    rbp,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 31999ULL);
x86_l_2630:
	/* 0x2630: ja     267b <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_267b;
	}
x86_l_2632:
	/* 0x2632: mov    BYTE PTR [r13+rbp*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 588410519552ULL);
x86_l_263b:
	/* 0x263b: cmp    ebp,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 31991ULL);
x86_l_2641:
	/* 0x2641: ja     267b <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_267b;
	}
x86_l_2643:
	/* 0x2643: lea    rdi,[r13*1+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_264b:
	/* 0x264b: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_264e:
	/* 0x264e: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2653:
	/* 0x2653: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2658:
	/* 0x2658: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_265d:
	/* 0x265d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2662:
	/* 0x2662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2664:
	/* 0x2664: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2667:
	/* 0x2667: js     267b <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_267b;
	}
x86_l_2669:
	/* 0x2669: add    ebp,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_266c:
	/* 0x266c: mov    WORD PTR [r13+0x7d8a],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2674:
	/* 0x2674: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_267b:
	/* 0x267b: mov    r13,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_267f:
	/* 0x267f: mov    DWORD PTR [rsp],0x38 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2686:
	/* 0x2686: movzx  ebp,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_268e:
	/* 0x268e: cmp    rbp,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 27899ULL);
x86_l_2695:
	/* 0x2695: ja     2717 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2717;
	}
x86_l_269b:
	/* 0x269b: mov    BYTE PTR [r13+rbp*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 588410519553ULL);
x86_l_26a4:
	/* 0x26a4: lea    rdi,[rbp*1+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_26ac:
	/* 0x26ac: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26af:
	/* 0x26af: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_26b2:
	/* 0x26b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_26b7:
	/* 0x26b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26bc:
	/* 0x26bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26c1:
	/* 0x26c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c3:
	/* 0x26c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26c6:
	/* 0x26c6: jne    2717 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2717;
	}
x86_l_26c8:
	/* 0x26c8: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26cc:
	/* 0x26cc: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26cf:
	/* 0x26cf: cmp    eax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_26d4:
	/* 0x26d4: jb     26e2 <lkm_seeker_send_to_userspace+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26e2;
	}
x86_l_26d6:
	/* 0x26d6: mov    DWORD PTR [rsp],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4095ULL);
x86_l_26dd:
	/* 0x26dd: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_26e2:
	/* 0x26e2: lea    rdi,[rbp*1+0x8e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 142ULL);
x86_l_26ea:
	/* 0x26ea: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26ed:
	/* 0x26ed: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_26ef:
	/* 0x26ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26f4:
	/* 0x26f4: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f7:
	/* 0x26f7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26fa:
	/* 0x26fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fc:
	/* 0x26fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26ff:
	/* 0x26ff: jne    2717 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2717;
	}
x86_l_2701:
	/* 0x2701: add    rbp,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2705:
	/* 0x2705: add    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2708:
	/* 0x2708: mov    WORD PTR [r13+0x7d8a],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2710:
	/* 0x2710: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2717:
	/* 0x2717: mov    r12,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_271b:
	/* 0x271b: movzx  r13d,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2724:
	/* 0x2724: cmp    r13,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31999ULL);
x86_l_272b:
	/* 0x272b: ja     2778 <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2778;
	}
x86_l_272d:
	/* 0x272d: mov    BYTE PTR [r12+r13*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R13, 0), 588410519554ULL);
x86_l_2736:
	/* 0x2736: cmp    r13d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31995ULL);
x86_l_273d:
	/* 0x273d: ja     2778 <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2778;
	}
x86_l_273f:
	/* 0x273f: lea    rdi,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2743:
	/* 0x2743: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_274a:
	/* 0x274a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_274f:
	/* 0x274f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2754:
	/* 0x2754: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2759:
	/* 0x2759: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_275c:
	/* 0x275c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275e:
	/* 0x275e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2761:
	/* 0x2761: js     2778 <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2778;
	}
x86_l_2763:
	/* 0x2763: add    r13d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2767:
	/* 0x2767: mov    WORD PTR [r12+0x7d8a],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2770:
	/* 0x2770: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2778:
	/* 0x2778: mov    r15,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277c:
	/* 0x277c: mov    DWORD PTR [rsp],0x19 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_2783:
	/* 0x2783: movzx  r12d,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_278b:
	/* 0x278b: cmp    r12,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 27899ULL);
x86_l_2792:
	/* 0x2792: ja     280d <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_280d;
	}
x86_l_2794:
	/* 0x2794: mov    BYTE PTR [r15+r12*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R12, 0), 588410519555ULL);
x86_l_279d:
	/* 0x279d: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_27a1:
	/* 0x27a1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_27a8:
	/* 0x27a8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_27ab:
	/* 0x27ab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_27b0:
	/* 0x27b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27b5:
	/* 0x27b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27ba:
	/* 0x27ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27bc:
	/* 0x27bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27bf:
	/* 0x27bf: jne    280d <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_280d;
	}
x86_l_27c1:
	/* 0x27c1: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c4:
	/* 0x27c4: cmp    eax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_27c9:
	/* 0x27c9: jb     27d7 <lkm_seeker_send_to_userspace+0x25e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_27d7;
	}
x86_l_27cb:
	/* 0x27cb: mov    DWORD PTR [rsp],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4095ULL);
x86_l_27d2:
	/* 0x27d2: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_27d7:
	/* 0x27d7: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_27db:
	/* 0x27db: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_27e2:
	/* 0x27e2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_27e4:
	/* 0x27e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27e9:
	/* 0x27e9: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ec:
	/* 0x27ec: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_27ef:
	/* 0x27ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f1:
	/* 0x27f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27f4:
	/* 0x27f4: jne    280d <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_280d;
	}
x86_l_27f6:
	/* 0x27f6: add    r12,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_27fa:
	/* 0x27fa: add    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27fe:
	/* 0x27fe: mov    WORD PTR [r15+0x7d8a],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2806:
	/* 0x2806: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_280d:
	/* 0x280d: mov    r14,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2811:
	/* 0x2811: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2818:
	/* 0x2818: lea    rbp,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_281c:
	/* 0x281c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_281f:
	/* 0x281f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2824:
	/* 0x2824: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2829:
	/* 0x2829: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282e:
	/* 0x282e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2831:
	/* 0x2831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2833:
	/* 0x2833: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2837:
	/* 0x2837: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_283c:
	/* 0x283c: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2840:
	/* 0x2840: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2843:
	/* 0x2843: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2848:
	/* 0x2848: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_284d:
	/* 0x284d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 10322ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10322ULL: goto x86_l_2852;
	case 10324ULL: goto x86_l_2854;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	case 10356ULL: goto x86_l_2874;
	case 10360ULL: goto x86_l_2878;
	case 10363ULL: goto x86_l_287b;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10387ULL: goto x86_l_2893;
	case 10392ULL: goto x86_l_2898;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10419ULL: goto x86_l_28b3;
	case 10423ULL: goto x86_l_28b7;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10453ULL: goto x86_l_28d5;
	case 10457ULL: goto x86_l_28d9;
	case 10461ULL: goto x86_l_28dd;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10481ULL: goto x86_l_28f1;
	case 10484ULL: goto x86_l_28f4;
	case 10488ULL: goto x86_l_28f8;
	case 10491ULL: goto x86_l_28fb;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10509ULL: goto x86_l_290d;
	case 10511ULL: goto x86_l_290f;
	case 10515ULL: goto x86_l_2913;
	case 10519ULL: goto x86_l_2917;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10539ULL: goto x86_l_292b;
	case 10543ULL: goto x86_l_292f;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10573ULL: goto x86_l_294d;
	case 10577ULL: goto x86_l_2951;
	case 10581ULL: goto x86_l_2955;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10604ULL: goto x86_l_296c;
	case 10608ULL: goto x86_l_2970;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10635ULL: goto x86_l_298b;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10658ULL: goto x86_l_29a2;
	case 10661ULL: goto x86_l_29a5;
	case 10665ULL: goto x86_l_29a9;
	case 10669ULL: goto x86_l_29ad;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10693ULL: goto x86_l_29c5;
	case 10697ULL: goto x86_l_29c9;
	case 10701ULL: goto x86_l_29cd;
	case 10704ULL: goto x86_l_29d0;
	case 10709ULL: goto x86_l_29d5;
	case 10714ULL: goto x86_l_29da;
	case 10719ULL: goto x86_l_29df;
	case 10721ULL: goto x86_l_29e1;
	case 10724ULL: goto x86_l_29e4;
	case 10728ULL: goto x86_l_29e8;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10755ULL: goto x86_l_2a03;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10776ULL: goto x86_l_2a18;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10789ULL: goto x86_l_2a25;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10801ULL: goto x86_l_2a31;
	case 10806ULL: goto x86_l_2a36;
	case 10811ULL: goto x86_l_2a3b;
	case 10813ULL: goto x86_l_2a3d;
	case 10817ULL: goto x86_l_2a41;
	case 10821ULL: goto x86_l_2a45;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10841ULL: goto x86_l_2a59;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10869ULL: goto x86_l_2a75;
	case 10873ULL: goto x86_l_2a79;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10903ULL: goto x86_l_2a97;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10931ULL: goto x86_l_2ab3;
	case 10934ULL: goto x86_l_2ab6;
	case 10938ULL: goto x86_l_2aba;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10975ULL: goto x86_l_2adf;
	case 10977ULL: goto x86_l_2ae1;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11035ULL: goto x86_l_2b1b;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11050ULL: goto x86_l_2b2a;
	case 11054ULL: goto x86_l_2b2e;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11066ULL: goto x86_l_2b3a;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11078ULL: goto x86_l_2b46;
	case 11082ULL: goto x86_l_2b4a;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11115ULL: goto x86_l_2b6b;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11127ULL: goto x86_l_2b77;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11148ULL: goto x86_l_2b8c;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11158ULL: goto x86_l_2b96;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11200ULL: goto x86_l_2bc0;
	case 11204ULL: goto x86_l_2bc4;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11256ULL: goto x86_l_2bf8;
	case 11259ULL: goto x86_l_2bfb;
	case 11264ULL: goto x86_l_2c00;
	case 11269ULL: goto x86_l_2c05;
	case 11274ULL: goto x86_l_2c0a;
	case 11276ULL: goto x86_l_2c0c;
	case 11280ULL: goto x86_l_2c10;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11296ULL: goto x86_l_2c20;
	case 11301ULL: goto x86_l_2c25;
	case 11303ULL: goto x86_l_2c27;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11334ULL: goto x86_l_2c46;
	case 11338ULL: goto x86_l_2c4a;
	case 11342ULL: goto x86_l_2c4e;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11378ULL: goto x86_l_2c72;
	case 11380ULL: goto x86_l_2c74;
	case 11384ULL: goto x86_l_2c78;
	case 11386ULL: goto x86_l_2c7a;
	case 11390ULL: goto x86_l_2c7e;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11411ULL: goto x86_l_2c93;
	case 11413ULL: goto x86_l_2c95;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11424ULL: goto x86_l_2ca0;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11444ULL: goto x86_l_2cb4;
	case 11450ULL: goto x86_l_2cba;
	case 11454ULL: goto x86_l_2cbe;
	case 11458ULL: goto x86_l_2cc2;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11479ULL: goto x86_l_2cd7;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11489ULL: goto x86_l_2ce1;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11499ULL: goto x86_l_2ceb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2852:
	/* 0x2852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2854:
	/* 0x2854: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2858:
	/* 0x2858: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_285c:
	/* 0x285c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_285f:
	/* 0x285f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2864:
	/* 0x2864: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2869:
	/* 0x2869: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_286e:
	/* 0x286e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2870:
	/* 0x2870: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2874:
	/* 0x2874: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2878:
	/* 0x2878: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_287b:
	/* 0x287b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2880:
	/* 0x2880: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2885:
	/* 0x2885: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_288a:
	/* 0x288a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288c:
	/* 0x288c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_288f:
	/* 0x288f: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2893:
	/* 0x2893: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2898:
	/* 0x2898: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289c:
	/* 0x289c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_289f:
	/* 0x289f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28a4:
	/* 0x28a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28a9:
	/* 0x28a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ae:
	/* 0x28ae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28b1:
	/* 0x28b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b3:
	/* 0x28b3: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b7:
	/* 0x28b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28ba:
	/* 0x28ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28c4:
	/* 0x28c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28c9:
	/* 0x28c9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28cc:
	/* 0x28cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ce:
	/* 0x28ce: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d1:
	/* 0x28d1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_28d5:
	/* 0x28d5: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28d9:
	/* 0x28d9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28dd:
	/* 0x28dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28e0:
	/* 0x28e0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28e5:
	/* 0x28e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28ea:
	/* 0x28ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28ef:
	/* 0x28ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f1:
	/* 0x28f1: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f4:
	/* 0x28f4: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28f8:
	/* 0x28f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28fb:
	/* 0x28fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2900:
	/* 0x2900: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2905:
	/* 0x2905: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_290a:
	/* 0x290a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_290d:
	/* 0x290d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290f:
	/* 0x290f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2913:
	/* 0x2913: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2917:
	/* 0x2917: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_291a:
	/* 0x291a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_291f:
	/* 0x291f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2924:
	/* 0x2924: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2929:
	/* 0x2929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292b:
	/* 0x292b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292f:
	/* 0x292f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2932:
	/* 0x2932: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2937:
	/* 0x2937: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_293c:
	/* 0x293c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2941:
	/* 0x2941: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2944:
	/* 0x2944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2946:
	/* 0x2946: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2949:
	/* 0x2949: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_294d:
	/* 0x294d: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2951:
	/* 0x2951: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2955:
	/* 0x2955: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2958:
	/* 0x2958: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_295d:
	/* 0x295d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2962:
	/* 0x2962: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2967:
	/* 0x2967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2969:
	/* 0x2969: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296c:
	/* 0x296c: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2970:
	/* 0x2970: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2973:
	/* 0x2973: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2978:
	/* 0x2978: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_297d:
	/* 0x297d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2982:
	/* 0x2982: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2985:
	/* 0x2985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2987:
	/* 0x2987: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298b:
	/* 0x298b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_298e:
	/* 0x298e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2993:
	/* 0x2993: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2998:
	/* 0x2998: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_299d:
	/* 0x299d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29a0:
	/* 0x29a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a2:
	/* 0x29a2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a5:
	/* 0x29a5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_29a9:
	/* 0x29a9: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29ad:
	/* 0x29ad: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29b1:
	/* 0x29b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29b4:
	/* 0x29b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29b9:
	/* 0x29b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29be:
	/* 0x29be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c3:
	/* 0x29c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c5:
	/* 0x29c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c9:
	/* 0x29c9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_29cd:
	/* 0x29cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29d0:
	/* 0x29d0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29d5:
	/* 0x29d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29da:
	/* 0x29da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29df:
	/* 0x29df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e1:
	/* 0x29e1: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e4:
	/* 0x29e4: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29e8:
	/* 0x29e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29eb:
	/* 0x29eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29f0:
	/* 0x29f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29f5:
	/* 0x29f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29fa:
	/* 0x29fa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29fd:
	/* 0x29fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ff:
	/* 0x29ff: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a03:
	/* 0x2a03: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a06:
	/* 0x2a06: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a0b:
	/* 0x2a0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a10:
	/* 0x2a10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a15:
	/* 0x2a15: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a18:
	/* 0x2a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1a:
	/* 0x2a1a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1d:
	/* 0x2a1d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a21:
	/* 0x2a21: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a25:
	/* 0x2a25: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a29:
	/* 0x2a29: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a2c:
	/* 0x2a2c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a31:
	/* 0x2a31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a36:
	/* 0x2a36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a3b:
	/* 0x2a3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3d:
	/* 0x2a3d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a41:
	/* 0x2a41: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2a45:
	/* 0x2a45: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a48:
	/* 0x2a48: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a4d:
	/* 0x2a4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a52:
	/* 0x2a52: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a57:
	/* 0x2a57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a59:
	/* 0x2a59: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_2a5c:
	/* 0x2a5c: jne    2aba <lkm_seeker_send_to_userspace+0x541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aba;
	}
x86_l_2a5e:
	/* 0x2a5e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a61:
	/* 0x2a61: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a66:
	/* 0x2a66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a70:
	/* 0x2a70: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a73:
	/* 0x2a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a75:
	/* 0x2a75: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a79:
	/* 0x2a79: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a7c:
	/* 0x2a7c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a81:
	/* 0x2a81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a86:
	/* 0x2a86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a8e:
	/* 0x2a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a90:
	/* 0x2a90: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a93:
	/* 0x2a93: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a97:
	/* 0x2a97: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a9b:
	/* 0x2a9b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aa2:
	/* 0x2aa2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2aa7:
	/* 0x2aa7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aac:
	/* 0x2aac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ab1:
	/* 0x2ab1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab3:
	/* 0x2ab3: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aba:
	/* 0x2aba: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2abe:
	/* 0x2abe: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ac3:
	/* 0x2ac3: lea    rbp,[r15+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2aca:
	/* 0x2aca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2acd:
	/* 0x2acd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ad2:
	/* 0x2ad2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2adc:
	/* 0x2adc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2adf:
	/* 0x2adf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae1:
	/* 0x2ae1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae5:
	/* 0x2ae5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ae9:
	/* 0x2ae9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aec:
	/* 0x2aec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2af1:
	/* 0x2af1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af6:
	/* 0x2af6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afb:
	/* 0x2afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afd:
	/* 0x2afd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b01:
	/* 0x2b01: lea    rdi,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b06:
	/* 0x2b06: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b10:
	/* 0x2b10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b14:
	/* 0x2b14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b19:
	/* 0x2b19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1b:
	/* 0x2b1b: mov    eax,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2b23:
	/* 0x2b23: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2b28:
	/* 0x2b28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2a:
	/* 0x2b2a: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b2e:
	/* 0x2b2e: lea    rdx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b32:
	/* 0x2b32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b35:
	/* 0x2b35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3f:
	/* 0x2b3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b44:
	/* 0x2b44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b46:
	/* 0x2b46: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b53:
	/* 0x2b53: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2b57:
	/* 0x2b57: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b5a:
	/* 0x2b5a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b64:
	/* 0x2b64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b69:
	/* 0x2b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6b:
	/* 0x2b6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b73:
	/* 0x2b73: add    r13,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2b77:
	/* 0x2b77: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b7a:
	/* 0x2b7a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b84:
	/* 0x2b84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b89:
	/* 0x2b89: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b8c:
	/* 0x2b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8e:
	/* 0x2b8e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b92:
	/* 0x2b92: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b96:
	/* 0x2b96: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b99:
	/* 0x2b99: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b9e:
	/* 0x2b9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ba8:
	/* 0x2ba8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2bab:
	/* 0x2bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bad:
	/* 0x2bad: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2bb1:
	/* 0x2bb1: je     2bb8 <lkm_seeker_send_to_userspace+0x63f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bb8;
	}
x86_l_2bb3:
	/* 0x2bb3: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2bb8:
	/* 0x2bb8: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2bc0:
	/* 0x2bc0: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bdb:
	/* 0x2bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdd:
	/* 0x2bdd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2be0:
	/* 0x2be0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2be5:
	/* 0x2be5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bea:
	/* 0x2bea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bef:
	/* 0x2bef: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2bf2:
	/* 0x2bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf8:
	/* 0x2bf8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bfb:
	/* 0x2bfb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c00:
	/* 0x2c00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c05:
	/* 0x2c05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c0a:
	/* 0x2c0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0c:
	/* 0x2c0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c10:
	/* 0x2c10: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_2c13:
	/* 0x2c13: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2c18:
	/* 0x2c18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2c20:
	/* 0x2c20: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2c25:
	/* 0x2c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c27:
	/* 0x2c27: add    r14,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2c2b:
	/* 0x2c2b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2c30:
	/* 0x2c30: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c35:
	/* 0x2c35: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2c38:
	/* 0x2c38: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c3d:
	/* 0x2c3d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c40:
	/* 0x2c40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c42:
	/* 0x2c42: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c46:
	/* 0x2c46: mov    rdx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4a:
	/* 0x2c4a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2c53:
	/* 0x2c53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c58:
	/* 0x2c58: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    rdx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c60:
	/* 0x2c60: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c64:
	/* 0x2c64: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2c69:
	/* 0x2c69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6b:
	/* 0x2c6b: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6e:
	/* 0x2c6e: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2c72:
	/* 0x2c72: jne    2c7a <lkm_seeker_send_to_userspace+0x701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c7a;
	}
x86_l_2c74:
	/* 0x2c74: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c78:
	/* 0x2c78: jmp    2ca0 <lkm_seeker_send_to_userspace+0x727> */
	goto x86_l_2ca0;
x86_l_2c7a:
	/* 0x2c7a: mov    rcx,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    rsi,QWORD PTR [rip+0x36c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2c85:
	/* 0x2c85: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c93:
	/* 0x2c93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c95:
	/* 0x2c95: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c99:
	/* 0x2c99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c9b:
	/* 0x2c9b: js     2ca0 <lkm_seeker_send_to_userspace+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ca0;
	}
x86_l_2c9d:
	/* 0x2c9d: mov    DWORD PTR [rcx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ca0:
	/* 0x2ca0: movzx  eax,WORD PTR [rcx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ca7:
	/* 0x2ca7: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2cac:
	/* 0x2cac: mov    edx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_2cb1:
	/* 0x2cb1: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2cb4:
	/* 0x2cb4: add    edx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2cba:
	/* 0x2cba: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cbe:
	/* 0x2cbe: movzx  r8d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2cc2:
	/* 0x2cc2: mov    rsi,QWORD PTR [rip+0x36c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2cc9:
	/* 0x2cc9: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2cce:
	/* 0x2cce: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cdb:
	/* 0x2cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdd:
	/* 0x2cdd: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_2ce1:
	/* 0x2ce1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2ce2:
	/* 0x2ce2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2ce4:
	/* 0x2ce4: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2ce6:
	/* 0x2ce6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2ce8:
	/* 0x2ce8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2cea:
	/* 0x2cea: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2ceb:
	/* 0x2ceb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_do_init_module_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10424U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2193ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2196ULL && __x86_pc <= 3806ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3809ULL && __x86_pc <= 5318ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5320ULL && __x86_pc <= 6984ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6989ULL && __x86_pc <= 8646ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8649ULL && __x86_pc <= 10317ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10322ULL && __x86_pc <= 11499ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
